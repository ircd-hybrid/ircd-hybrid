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

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "numeric.h"
#include "send.h"
#include "memory.h"
#include "command.h"


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
command_tree_add_element(struct CommandTree *tree, struct Command *command, const char *const name)
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
command_tree_del_element(struct CommandTree *tree, const char *const name)
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
