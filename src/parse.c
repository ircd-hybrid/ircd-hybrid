/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file parse.c
 * \brief The message parser.
 */

#include "stdinc.h"
#include "client.h"
#include "parse.h"
#include "channel.h"
#include "hash.h"
#include "id.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "log.h"
#include "send.h"
#include "conf.h"
#include "memory.h"
#include "user.h"
#include "server.h"
#include "packet.h"


/*
 * (based on orabidoo's parser code)
 *
 * This has always just been a trie. Look at volume III of Knuth ACP
 *
 *
 * ok, you start out with an array of pointers, each one corresponds
 * to a letter at the current position in the command being examined.
 *
 * so roughly you have this for matching 'trie' or 'tie'
 *
 * 't' points -> [CommandTree *] 'r' -> [CommandTree *] -> 'i'
 *   -> [CommandTree *] -> [CommandTree *] -> 'e' and matches
 *
 *                               'i' -> [CommandTree *] -> 'e' and matches
 *
 * BUGS (Limitations!)
 *
 * I designed this trie to parse ircd commands. Hence it currently
 * casefolds. This is trivial to fix by increasing MAXPTRLEN.
 * This trie also "folds" '{' etc. down. This means, the input to this
 * trie must be alpha tokens only. This again, is a limitation that
 * can be overcome by increasing MAXPTRLEN to include upper/lower case
 * at the expense of more memory. At the extreme end, you could make
 * MAXPTRLEN 128.
 *
 * This is also not a patricia trie. On short ircd tokens, this is
 * not likely going to matter.
 *
 * Diane Bruce (Dianora), June 6 2003
 */

/*
 * Must be a power of 2, and larger than 26 [a-z]|[A-Z]. It's used to allocate
 * the set of pointers at each node of the tree.
 * There are MAXPTRLEN pointers at each node. Obviously, there have to be more
 * pointers than ASCII letters. 32 is a nice number since there is then no need
 * to shift 'A'/'a' to base 0 index, at the expense of a few never used
 * pointers.
 * For a small parser like this, this is a good compromise and does
 * make it somewhat faster. - Dianora
 */
enum { MAXPTRLEN = 32 };


static struct CommandTree
{
  int links; /* Count of all pointers (including command) at this node
              * used as reference count for deletion of _this_ node.
              */
  struct Command *command;
  struct CommandTree *pointers[MAXPTRLEN];
} command_tree;


/* remove_unknown()
 *
 * inputs       -
 * output       -
 * side effects -
 */
static void
parse_remove_unknown(struct Client *client, const char *lsender, char *lbuffer)
{
  /*
   * Do kill if it came from a server because it means there is a ghost
   * user on the other server which needs to be removed. -avalon
   * Tell opers about this. -Taner
   */
  /*
   * '[0-9]something'  is an ID      (KILL/SQUIT depending on its length)
   * 'nodots'          is a nickname (KILL)
   * 'no.dot.at.start' is a server   (SQUIT)
   */
  if ((IsDigit(*lsender) && strlen(lsender) <= IRC_MAXSID) || strchr(lsender, '.'))
  {
    log_write(LOG_TYPE_DEBUG, "Unknown prefix (%s) from %s, Squitting %s",
         lbuffer, client_get_name(client, SHOW_IP), lsender);
    sendto_one(client, ":%s SQUIT %s :(Unknown prefix (%s) from %s)",
               me.id, lsender, lbuffer, client->name);
  }
  else
    sendto_one(client, ":%s KILL %s :%s (Unknown Client)",
               me.id, lsender, me.name);
}

/*
 *
 *      parc    number of arguments ('sender' counted as one!)
 *      parv[0] pointer to 'sender' (may point to empty string) (not used)
 *      parv[1]..parv[parc-1]
 *              pointers to additional parameters, this is a NULL
 *              terminated list (parv[parc] == NULL).
 *
 * *WARNING*
 *      Numerics are mostly error reports. If there is something
 *      wrong with the message, just *DROP* it! Don't even think of
 *      sending back a neat error message -- big danger of creating
 *      a ping pong error message...
 *
 * Rewritten by Nemesi, Jan 1999, to support numeric nicks in parv[1]
 *
 * Called when we get a numeric message from a remote _server_ and we are
 * supposed to forward it somewhere. Note that we always ignore numerics sent
 * to 'me' and simply drop the message if we can't handle with this properly:
 * the savvy approach is NEVER generate an error in response to an... error :)
 */
static void
parse_handle_numeric(unsigned int numeric, struct Client *source, int parc, char *parv[])
{
  /*
   * Avoid trash, we need it to come from a server and have a target
   */
  if (parc < 2 || !IsServer(source))
    return;

  /*
   * Remap low number numerics, not that I understand WHY.. --Nemesi
   */
  /*
   * Numerics below 100 talk about the current 'connection', you're not
   * connected to a remote server so it doesn't make sense to send them
   * remotely - but the information they contain may be useful, so we
   * remap them up. Weird, but true.  -- Isomer
   */
  if (numeric < 100)
    numeric += 100;

  /*
   * Who should receive this message ? Will we do something with it ?
   * Note that we use findUser functions, so the target can't be neither
   * a server, nor a channel (?) nor a list of targets (?) .. u2.10
   * should never generate numeric replies to non-users anyway
   * Ahem... it can be a channel actually, csc bots use it :\ --Nem
   */
  if (IsChanPrefix(*parv[1]))
  {
    struct Channel *channel = hash_find_channel(parv[1]);
    if (channel == NULL)
      return;

    sendto_channel_butone(source, source, channel, 0, "%u %s %s",
                          numeric, channel->name, parv[2]);
  }
  else
  {
    struct Client *target = find_person(source, parv[1]);
    if (target == NULL || target->from == source->from)
      return;

    /* Fake it for server hiding, if it's our client */
    if ((ConfigServerHide.hide_servers || IsHidden(source)) && MyConnect(target) &&
        !HasUMode(target, UMODE_OPER))
      sendto_one_numeric(target, &me, numeric | SND_EXPLICIT, "%s", parv[2]);
    else
      sendto_one_numeric(target, source, numeric | SND_EXPLICIT, "%s", parv[2]);
  }
}

/* handle_command()
 *
 * inputs       - pointer to message block
 *              - pointer to client
 *              - pointer to client message is from
 *              - count of number of args
 *              - pointer to argv[] array
 * output       - -1 if error from server
 * side effects -
 */
static void
parse_handle_command(struct Command *command, struct Client *source,
                     unsigned int i, char *para[])
{
  const struct CommandHandler *const handler = &command->handlers[source->from->handler];

  if (IsServer(source->from))
    ++command->rcount;
  ++command->count;

  if (handler->end_grace_period && MyClient(source))
    flood_endgrace(source);

  /* Check right amount of parameters is passed... --is */
  if (handler->args_min &&
      ((i < handler->args_min) ||
       (handler->empty_last_arg != true && EmptyString(para[handler->args_min - 1]))))
    sendto_one_numeric(source, &me, ERR_NEEDMOREPARAMS, command->name);
  else
    handler->handler(source, i, para);
}

/*
 * parse a buffer.
 *
 * NOTE: parse() should not be called recusively by any other functions!
 */
void
parse(struct Client *client, char *buffer, char *buffer_end)
{
  struct Client *from = client;
  struct Command *command = NULL;
  char *para[MAXPARA + 2];  /* <command> + <parameters> + NULL */
  char *ch = buffer;
  char *s = NULL;
  unsigned int numeric = 0;
  unsigned int parc = 0;
  unsigned int paramcount;

  assert(!IsDead(client));
  assert(client->connection);
  assert(client->connection->fd);
  assert(client->connection->fd->flags.open);
  assert((buffer_end - buffer) < IRCD_BUFSIZE);

  /* Skip leading spaces. */
  while (*ch == ' ')
    ++ch;

  if (*ch == ':')
  {
    /*
     * Copy the prefix to 'sender' assuming it terminates
     * with SPACE (or NULL, which is an error, though).
     */
    const char *const sender = ++ch;

    if ((s = strchr(ch, ' ')))
    {
      *s = '\0';
      ch = ++s;
    }

    if (*sender && IsServer(client))
    {
      if ((from = hash_find_id(sender)) == NULL)
        from = hash_find_client(sender);

      /*
       * Hmm! If the client corresponding to the prefix is not found--what is
       * the correct action??? Now, I will ignore the message (old IRC just
       * let it through as if the prefix just wasn't there...) --msa
       */
      if (from == NULL)
      {
        ++ServerStats.is_unpf;
        parse_remove_unknown(client, sender, buffer);
        return;
      }

      if (from->from != client)
      {
        ++ServerStats.is_wrdi;
        log_write(LOG_TYPE_DEBUG, "Fake direction: dropped message from %s[%s] via %s",
             from->name, from->from->name, client_get_name(client, SHOW_IP));
        return;
      }
    }

    while (*ch == ' ')
      ++ch;
  }

  if (*ch == '\0')
  {
    ++ServerStats.is_empt;
    return;
  }

  /*
   * Extract the command code from the packet. Point s to the end
   * of the command code and calculate the length using pointer
   * arithmetic. Note: only need length for numerics and *all*
   * numerics must have parameters and thus a space after the command
   * code. -avalon
   */

  /* EOB is 3 characters long but is not a numeric */
  if (*(ch + 3) == ' ' &&  /* Ok, let's see if it's a possible numeric */
      IsDigit(*ch) && IsDigit(*(ch + 1)) && IsDigit(*(ch + 2)))
  {
    numeric = (*ch - '0') * 100 + (*(ch + 1) - '0') * 10 + (*(ch + 2) - '0');
    paramcount = 2;  /* Destination, and the rest of it */
    ++ServerStats.is_num;
    s = ch + 3;  /* I know this is ' ' from above if */
    *s++ = '\0';  /* Blow away the ' ', and point s to next part */
  }
  else
  {
    if ((s = strchr(ch, ' ')))
      *s++ = '\0';

    if ((command = command_find(ch)) == NULL)
    {
      /*
       * Note: Give error message *only* to recognized
       * persons. It's a nightmare situation to have
       * two programs sending "Unknown command"'s or
       * equivalent to each other at full blast....
       * If it has got to person state, it at least
       * seems to be well behaving. Perhaps this message
       * should never be generated, though...  --msa
       */
      if (IsClient(from))
        sendto_one_numeric(from, &me, ERR_UNKNOWNCOMMAND, ch);

      ++ServerStats.is_unco;
      return;
    }

    paramcount = command->handlers[from->from->handler].args_max;

    size_t length = buffer_end - ((s) ? s : ch);
    command->bytes += length;
  }

  memset(para, 0, sizeof(para));
  para[parc] = ch;

  if (command && command->extra)
  {
    /*
     * XXX: This will have to go away after the command handler rewrite
     */
    para[++parc] = command->extra;
  }

  /*
   * Must the following loop really be so devious? On surface it
   * splits the message to parameters from blank spaces. But, if
   * paramcount has been reached, the rest of the message goes into
   * this last parameter (about same effect as ":" has...) --msa
   */

  /* Note initially true: s == NULL || *(s - 1) == '\0' !! */
  if (s)
  {
    if (paramcount == 0 || paramcount > MAXPARA)
      paramcount = MAXPARA;

    while (true)
    {
       while (*s == ' ')
         *s++ = '\0';

       if (*s == '\0')
         break;

       if (*s == ':')
       {
         /* The rest is single parameter--can include blanks also. */
         para[++parc] = s + (numeric == 0);  /* Keep the colon if it's a numeric */
         break;
       }

       para[++parc] = s;

       if (parc >= paramcount)
         break;

       while (*s && *s != ' ')
         ++s;
    }
  }

  para[++parc] = NULL;

  if (command)
    parse_handle_command(command, from, parc, para);
  else
    parse_handle_numeric(numeric, from, parc, para);
}

/* add_msg_element()
 *
 * inputs	- pointer to CommandTree
 *		- pointer to Message to add for given command
 *		- pointer to current portion of command being added
 * output	- NONE
 * side effects	- recursively build the Message Tree ;-)
 */
/*
 * How this works.
 *
 * The code first checks to see if its reached the end of the command
 * If so, that struct CommandTree has a msg pointer updated and the links
 * count incremented, since a msg pointer is a reference.
 * Then the code descends recursively, building the trie.
 * If a pointer index inside the struct CommandTree is NULL a new
 * child struct CommandTree has to be allocated.
 * The links (reference count) is incremented as they are created
 * in the parent.
 */
static void
command_tree_add_element(struct CommandTree *tree, struct Command *command, const char *name)
{
  if (*name == '\0')
  {
    tree->command = command;
    tree->links++;  /* Have msg pointer, so up ref count */
  }
  else
  {
    /*
     * *name & (MAXPTRLEN-1)
     * convert the char pointed to at *name from ASCII to an integer
     * between 0 and MAXPTRLEN.
     * Thus 'A' -> 0x1 'B' -> 0x2 'c' -> 0x3 etc.
     */
    struct CommandTree *current = tree->pointers[*name & (MAXPTRLEN - 1)];
    if (current == NULL)
    {
      current = xcalloc(sizeof(*current));
      tree->pointers[*name & (MAXPTRLEN - 1)] = current;

      tree->links++;  /* Have new pointer, so up ref count */
    }

    command_tree_add_element(current, command, name + 1);
  }
}

/* del_msg_element()
 *
 * inputs	- Pointer to CommandTree to delete from
 *		- pointer to command name to delete
 * output	- NONE
 * side effects	- recursively deletes a token from the Message Tree ;-)
 */
/*
 * How this works.
 *
 * Well, first off, the code recursively descends into the trie
 * until it finds the terminating letter of the command being removed.
 * Once it has done that, it marks the msg pointer as NULL then
 * reduces the reference count on that allocated struct CommandTree
 * since a command counts as a reference.
 *
 * Then it pops up the recurse stack. As it comes back up the recurse
 * The code checks to see if the child now has no pointers or msg
 * i.e. the links count has gone to zero. If it's no longer used, the
 * child struct CommandTree can be deleted. The parent reference
 * to this child is then removed and the parents link count goes down.
 * Thus, we continue to go back up removing all unused CommandTree(s)
 */
static void
command_tree_del_element(struct CommandTree *tree, const char *name)
{
  /*
   * In case this is called for a nonexistent command
   * check that there is a command pointer here, else links-- goes -ve
   * -db
   */
  if (*name== '\0' && tree->command)
  {
    tree->command = NULL;
    tree->links--;
  }
  else
  {
    struct CommandTree *current = tree->pointers[*name & (MAXPTRLEN - 1)];
    if (current)
    {
      command_tree_del_element(current, name + 1);

      if (current->links == 0)
      {
        tree->pointers[*name & (MAXPTRLEN - 1)] = NULL;
        tree->links--;
        xfree(current);
      }
    }
  }
}

/* command_tree_parse()
 *
 * inputs	- Pointer to command to find
 *		- Pointer to CommandTree root
 * output	- Find given command returning Message * if found NULL if not
 * side effects	- none
 */
static struct Command *
command_tree_parse(const char *name)
{
  struct CommandTree *tree = &command_tree;

  assert(!EmptyString(name));

  while (IsAlpha(*name) && (tree = tree->pointers[*name & (MAXPTRLEN - 1)]))
    if (*++name == '\0')
      return tree->command;

  return NULL;
}

/* command_add()
 *
 * inputs	- pointer to struct Command
 * output	- none
 * side effects - load this one command name
 */
void
command_add(struct Command *command)
{
  assert(command);
  assert(command->name);

  /* Command already added? */
  if (command_tree_parse(command->name) == NULL)
    command_tree_add_element(&command_tree, command, command->name);
}

/* command_del()
 *
 * inputs	- pointer to struct Command
 * output	- none
 * side effects - unload this one command name
 */
void
command_del(struct Command *command)
{
  assert(command);
  assert(command->name);

  if (command_tree_parse(command->name))
    command_tree_del_element(&command_tree, command->name);
}

/* find_command()
 *
 * inputs	- command name
 * output	- pointer to struct Command
 * side effects - none
 */
struct Command *
command_find(const char *name)
{
  return command_tree_parse(name);
}

/* report_messages()
 *
 * inputs	- pointer to client to report to
 * output	- NONE
 * side effects	- client is shown list of commands
 */
void
command_report(struct Client *source)
{
  const struct CommandTree *const tree = &command_tree;
  const struct CommandTree *stack[MAXPTRLEN * MAXPTRLEN];
  unsigned int top = 0;

  /* Initialize stack with the root node. */
  stack[top++] = tree;

  while (top > 0)
  {
    /* Pop the top of the stack. */
    const struct CommandTree *current = stack[--top];

    if (current->command)
      sendto_one_numeric(source, &me, RPL_STATSCOMMANDS,
                         current->command->name,
                         current->command->count,
                         current->command->bytes,
                         current->command->rcount,
                         current->command->ecount);

    /* Push non-null pointers onto the stack in descending order. */
    for (int i = MAXPTRLEN - 1; i >= 0; --i)
    {
      const struct CommandTree *ptr = current->pointers[i];
      if (ptr)
        stack[top++] = ptr;
    }
  }
}

/* m_not_oper()
 * inputs	-
 * output	-
 * side effects	- just returns a nastyogram to given user
 */
void
m_not_oper(struct Client *source, int parc, char *parv[])
{
  sendto_one_numeric(source, &me, ERR_NOPRIVILEGES);
}

void
m_unregistered(struct Client *source, int parc, char *parv[])
{
  sendto_one_numeric(source, &me, ERR_NOTREGISTERED);
}

void
m_registered(struct Client *source, int parc, char *parv[])
{
  sendto_one_numeric(source, &me, ERR_ALREADYREGISTRED);
}

void
m_ignore(struct Client *source, int parc, char *parv[])
{
  return;
}
