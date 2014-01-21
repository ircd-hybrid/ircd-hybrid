/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 */

/*! \file m_message.c
 * \brief Includes required functions for processing the PRIVMSG/NOTICE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "s_serv.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "channel.h"
#include "channel_mode.h"
#include "irc_string.h"
#include "hash.h"
#include "packet.h"


#define PRIVMSG 0
#define NOTICE  1

#define ENTITY_NONE    0
#define ENTITY_CHANNEL 1
#define ENTITY_CHANOPS_ON_CHANNEL 2
#define ENTITY_CLIENT  3

static struct entity
{
  void *ptr;
  int type;
  int flags;
} targets[IRCD_BUFSIZE];

static int ntargets = 0;


/*
** m_privmsg
**
** massive cleanup
** rev argv 6/91
**
**   Another massive cleanup Nov, 2000
** (I don't think there is a single line left from 6/91. Maybe.)
** m_privmsg and m_notice do basically the same thing.
** in the original 2.8.2 code base, they were the same function
** "m_message.c." When we did the great cleanup in conjuncton with bleep
** of ircu fame, we split m_privmsg.c and m_notice.c.
** I don't see the point of that now. Its harder to maintain, its
** easier to introduce bugs into one version and not the other etc.
** Really, the penalty of an extra function call isn't that big a deal folks.
** -db Nov 13, 2000
**
*/

/* duplicate_ptr()
 *
 * inputs       - pointer to check
 *              - pointer to table of entities
 *              - number of valid entities so far
 * output       - YES if duplicate pointer in table, NO if not.
 *                note, this does the canonize using pointers
 * side effects - NONE
 */
static int
duplicate_ptr(const void *ptr)
{
  int i = 0;

  for (; i < ntargets; ++i)
    if (targets[i].ptr == ptr)
      return 1;

  return 0;
}

/*
 * find_userhost - find a user@host (server or user).
 * inputs       - user name to look for
 *              - host name to look for
 *              - pointer to count of number of matches found
 * outputs      - pointer to client if found
 *              - count is updated
 * side effects - none
 *
 */
static struct Client *
find_userhost(char *user, char *host, int *count)
{
  struct Client *res = NULL;
  dlink_node *lc2ptr = NULL;

  *count = 0;

  if (collapse(user))
  {
    DLINK_FOREACH(lc2ptr, local_client_list.head)
    {
      struct Client *c2ptr = lc2ptr->data;

      if (!IsClient(c2ptr))
        continue;

      if ((!host || !match(host, c2ptr->host)) &&
          !irccmp(user, c2ptr->username))
      {
        (*count)++;
        res = c2ptr;
      }
    }
  }

  return res;
}

/* flood_attack_client()
 *
 * inputs       - flag 0 if PRIVMSG 1 if NOTICE. RFC
 *                say NOTICE must not auto reply
 *              - pointer to source Client
 *              - pointer to target Client
 * output       - 1 if target is under flood attack
 * side effects - check for flood attack on target target_p
 */
static int
flood_attack_client(int p_or_n, struct Client *source_p,
                    struct Client *target_p)
{
  int delta;

  if (GlobalSetOptions.floodcount && MyConnect(target_p) &&
      IsClient(source_p) && !IsCanFlood(source_p))
  {
    if ((target_p->localClient->first_received_message_time + 1)
        < CurrentTime)
    {
      delta =
        CurrentTime - target_p->localClient->first_received_message_time;
      target_p->localClient->received_number_of_privmsgs -= delta;
      target_p->localClient->first_received_message_time = CurrentTime;

      if (target_p->localClient->received_number_of_privmsgs <= 0)
      {
        target_p->localClient->received_number_of_privmsgs = 0;
        DelFlag(target_p, FLAGS_FLOOD_NOTICED);
      }
    }

    if ((target_p->localClient->received_number_of_privmsgs >=
         GlobalSetOptions.floodcount) || HasFlag(target_p, FLAGS_FLOOD_NOTICED))
    {
      if (!HasFlag(target_p, FLAGS_FLOOD_NOTICED))
      {
        sendto_realops_flags(UMODE_BOTS, L_ALL, SEND_NOTICE,
                             "Possible Flooder %s on %s target: %s",
                             get_client_name(source_p, HIDE_IP),
                             source_p->servptr->name, target_p->name);
        AddFlag(target_p, FLAGS_FLOOD_NOTICED);

        /* Add a bit of penalty */
        target_p->localClient->received_number_of_privmsgs += 2;
      }

      if (MyClient(source_p) && (p_or_n != NOTICE))
        sendto_one(source_p,
                   ":%s NOTICE %s :*** Message to %s throttled due to flooding",
                   me.name, source_p->name, target_p->name);
      return 1;
    }
    else
      target_p->localClient->received_number_of_privmsgs++;
  }

  return 0;
}

/* flood_attack_channel()
 *
 * inputs       - flag 0 if PRIVMSG 1 if NOTICE. RFC
 *                says NOTICE must not auto reply
 *              - pointer to source Client
 *              - pointer to target channel
 * output       - 1 if target is under flood attack
 * side effects - check for flood attack on target chptr
 */
static int
flood_attack_channel(int p_or_n, struct Client *source_p,
                     struct Channel *chptr)
{
  int delta;

  if (GlobalSetOptions.floodcount && !IsCanFlood(source_p))
  {
    if ((chptr->first_received_message_time + 1) < CurrentTime)
    {
      delta = CurrentTime - chptr->first_received_message_time;
      chptr->received_number_of_privmsgs -= delta;
      chptr->first_received_message_time = CurrentTime;

      if (chptr->received_number_of_privmsgs <= 0)
      {
        chptr->received_number_of_privmsgs = 0;
        ClearFloodNoticed(chptr);
      }
    }

    if ((chptr->received_number_of_privmsgs >= GlobalSetOptions.floodcount) ||
         IsSetFloodNoticed(chptr))
    {
      if (!IsSetFloodNoticed(chptr))
      {
        sendto_realops_flags(UMODE_BOTS, L_ALL, SEND_NOTICE,
                             "Possible Flooder %s on %s target: %s",
                             get_client_name(source_p, HIDE_IP),
                             source_p->servptr->name, chptr->chname);
        SetFloodNoticed(chptr);

        /* Add a bit of penalty */
        chptr->received_number_of_privmsgs += 2;
      }

      if (MyClient(source_p) && (p_or_n != NOTICE))
        sendto_one(source_p,
                   ":%s NOTICE %s :*** Message to %s throttled due to flooding",
                   me.name, source_p->name, chptr->chname);
      return 1;
    }
    else
      chptr->received_number_of_privmsgs++;
  }

  return 0;
}

/* msg_channel()
 *
 * inputs	- flag privmsg or notice
 * 		- pointer to command "PRIVMSG" or "NOTICE"
 *		- pointer to client_p
 *		- pointer to source_p
 *		- pointer to channel
 * output	- NONE
 * side effects	- message given channel
 */
static void
msg_channel(int p_or_n, const char *command, struct Client *client_p,
            struct Client *source_p, struct Channel *chptr, char *text)
{
  int result = 0;

  if (MyClient(source_p))
  {
    /* Idle time shouldnt be reset by notices --fl */
    if (p_or_n != NOTICE)
      source_p->localClient->last_privmsg = CurrentTime;
  }

  /* Chanops and voiced can flood their own channel with impunity */
  if ((result = can_send(chptr, source_p, NULL, text)) < 0)
  {
    if (result == CAN_SEND_OPV ||
        !flood_attack_channel(p_or_n, source_p, chptr))
      sendto_channel_butone(client_p, source_p, chptr, 0, "%s %s :%s",
                            command, chptr->chname, text);
  }
  else
  {
    if (p_or_n != NOTICE)
    {
      if (result == ERR_NOCTRLSONCHAN)
        sendto_one(source_p, form_str(ERR_NOCTRLSONCHAN),
                   ID_or_name(&me, client_p),
                   ID_or_name(source_p, client_p), chptr->chname, text);
      else if (result == ERR_NEEDREGGEDNICK)
        sendto_one(source_p, form_str(ERR_NEEDREGGEDNICK),
                   ID_or_name(&me, client_p),
                   ID_or_name(source_p, client_p), chptr->chname);
      else
        sendto_one(source_p, form_str(ERR_CANNOTSENDTOCHAN),
                   ID_or_name(&me, client_p),
                   ID_or_name(source_p, client_p), chptr->chname);
    }
  }
}

/* msg_channel_flags()
 *
 * inputs	- flag 0 if PRIVMSG 1 if NOTICE. RFC
 *		  say NOTICE must not auto reply
 *		- pointer to command, "PRIVMSG" or "NOTICE"
 *		- pointer to client_p
 *		- pointer to source_p
 *		- pointer to channel
 *		- flags
 *		- pointer to text to send
 * output	- NONE
 * side effects	- message given channel either chanop or voice
 */
static void
msg_channel_flags(int p_or_n, const char *command, struct Client *client_p,
                  struct Client *source_p, struct Channel *chptr,
                  int flags, char *text)
{
  unsigned int type;
  char c;

  if (flags & CHFL_VOICE)
  {
    type = CHFL_VOICE|CHFL_HALFOP|CHFL_CHANOP;
    c = '+';
  }
#ifdef HALFOPS
  else if (flags & CHFL_HALFOP)
  {
    type = CHFL_HALFOP|CHFL_CHANOP;
    c = '%';
   }
#endif
  else
  {
    type = CHFL_CHANOP;
    c = '@';
  }

  if (MyClient(source_p) && p_or_n != NOTICE)
    source_p->localClient->last_privmsg = CurrentTime;

  sendto_channel_butone(client_p, source_p, chptr, type, "%s %c%s :%s",
                        command, c, chptr->chname, text);
}

/* msg_client()
 *
 * inputs	- flag 0 if PRIVMSG 1 if NOTICE. RFC
 *		  say NOTICE must not auto reply
 *		- pointer to command, "PRIVMSG" or "NOTICE"
 * 		- pointer to source_p source (struct Client *)
 *		- pointer to target_p target (struct Client *)
 *		- pointer to text
 * output	- NONE
 * side effects	- message given channel either chanop or voice
 */
static void
msg_client(int p_or_n, const char *command, struct Client *source_p,
           struct Client *target_p, char *text)
{
  if (MyConnect(source_p))
  {
    /*
     * Reset idle time for message only if it's not a notice
     */
    if ((p_or_n != NOTICE))
      source_p->localClient->last_privmsg = CurrentTime;

    if ((p_or_n != NOTICE) && target_p->away[0])
      sendto_one(source_p, form_str(RPL_AWAY), me.name,
                 source_p->name, target_p->name, target_p->away);

    if (HasUMode(target_p, UMODE_REGONLY) && target_p != source_p)
    {
      if (!HasUMode(source_p, UMODE_REGISTERED|UMODE_OPER))
      {
        if (p_or_n != NOTICE)
          sendto_one(source_p, form_str(ERR_NONONREG), me.name, source_p->name,
                     target_p->name);
        return;
      }
    }
  }

  if (MyClient(target_p))
  {
    if (!IsServer(source_p) && HasUMode(target_p, UMODE_CALLERID|UMODE_SOFTCALLERID))
    {
      /* Here is the anti-flood bot/spambot code -db */
      if (accept_message(source_p, target_p) || HasFlag(source_p, FLAGS_SERVICE) ||
         (HasUMode(source_p, UMODE_OPER) && (ConfigFileEntry.opers_bypass_callerid == 1)))
      {
        sendto_one(target_p, ":%s!%s@%s %s %s :%s",
                   source_p->name, source_p->username,
                   source_p->host, command, target_p->name, text);
      }
      else
      {
        int callerid = !!HasUMode(target_p, UMODE_CALLERID);

        /* check for accept, flag recipient incoming message */
        if (p_or_n != NOTICE)
          sendto_one(source_p, form_str(RPL_TARGUMODEG),
                     ID_or_name(&me, source_p),
                     ID_or_name(source_p, source_p), target_p->name,
                     callerid ? "+g" : "+G",
                     callerid ? "server side ignore" :
                                "server side ignore with the exception of common channels");

        if ((target_p->localClient->last_caller_id_time +
             ConfigFileEntry.caller_id_wait) < CurrentTime)
        {
          if (p_or_n != NOTICE)
            sendto_one(source_p, form_str(RPL_TARGNOTIFY),
                       ID_or_name(&me, source_p),
                       ID_or_name(source_p, source_p), target_p->name);

          sendto_one(target_p, form_str(RPL_UMODEGMSG),
                     me.name, target_p->name,
                     get_client_name(source_p, HIDE_IP),
                     callerid ? "+g" : "+G");

          target_p->localClient->last_caller_id_time = CurrentTime;

        }

        /* Only so opers can watch for floods */
        flood_attack_client(p_or_n, source_p, target_p);
      }
    }
    else
    {
      /*
       * If the client is remote, we dont perform a special check for
       * flooding.. as we wouldnt block their message anyway.. this means
       * we dont give warnings.. we then check if theyre opered
       * (to avoid flood warnings), lastly if theyre our client
       * and flooding    -- fl
       */
      if (!MyClient(source_p) || HasUMode(source_p, UMODE_OPER) ||
          !flood_attack_client(p_or_n, source_p, target_p))
        sendto_anywhere(target_p, source_p, command, ":%s", text);
    }
  }
  else if (!MyClient(source_p) || HasUMode(source_p, UMODE_OPER) ||
           !flood_attack_client(p_or_n, source_p, target_p))
    sendto_anywhere(target_p, source_p, command, ":%s", text);
}

/* handle_special()
 *
 * inputs	- server pointer
 *		- client pointer
 *		- nick stuff to grok for opers
 *		- text to send if grok
 * output	- none
 * side effects	- old style username@server is handled here for non opers
 *		  opers are allowed username%hostname@server
 *		  all the traditional oper type messages are also parsed here.
 *		  i.e. "/msg #some.host."
 *		  However, syntax has been changed.
 *		  previous syntax "/msg #some.host.mask"
 *		  now becomes     "/msg $#some.host.mask"
 *		  previous syntax of: "/msg $some.server.mask" remains
 *		  This disambiguates the syntax.
 *
 * XXX		  N.B. dalnet changed it to nick@server as have other servers.
 *		  we will stick with tradition for now.
 *		- Dianora
 */
static void
handle_special(int p_or_n, const char *command, struct Client *client_p,
               struct Client *source_p, char *nick, char *text)
{
  struct Client *target_p;
  char *host;
  char *server;
  char *s;
  int count;

  /*
   * user[%host]@server addressed?
   */
  if ((server = strchr(nick, '@')))
  {
    count = 0;

    if ((host = strchr(nick, '%')) && !HasUMode(source_p, UMODE_OPER))
    {
      sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
                 ID_or_name(&me, client_p),
                 ID_or_name(source_p, client_p));
      return;
    }

    if ((target_p = hash_find_server(server + 1)))
    {
      if (!IsMe(target_p))
      {
        /*
         * Not destined for a user on me :-(
         */
        sendto_one(target_p, ":%s %s %s :%s",
                   ID_or_name(source_p, target_p),
                   command, nick, text);
        if ((p_or_n != NOTICE) && MyClient(source_p))
          source_p->localClient->last_privmsg = CurrentTime;

        return;
      }

      *server = '\0';

      if (host != NULL)
        *host++ = '\0';

      /*
       * Look for users which match the destination host
       * (no host == wildcard) and if one and one only is
       * found connected to me, deliver message!
       */
      if ((target_p = find_userhost(nick, host, &count)))
      {
        if (server != NULL)
          *server = '@';
        if (host != NULL)
          *--host = '%';

        if (count == 1)
        {
          sendto_one(target_p, ":%s!%s@%s %s %s :%s",
                     source_p->name, source_p->username,
                     source_p->host, command, nick, text);

          if ((p_or_n != NOTICE) && MyClient(source_p))
            source_p->localClient->last_privmsg = CurrentTime;
        }
        else
          sendto_one(source_p, form_str(ERR_TOOMANYTARGETS),
                     ID_or_name(&me, client_p),
                     ID_or_name(source_p, client_p), nick,
                     ConfigFileEntry.max_targets);
      }
    }
    else if (server && *(server + 1) && (target_p == NULL))
      sendto_one(source_p, form_str(ERR_NOSUCHSERVER),
                 ID_or_name(&me, client_p),
                 ID_or_name(source_p, client_p), server + 1);
    else if (server && (target_p == NULL))
      sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                 ID_or_name(&me, client_p),
                 ID_or_name(source_p, client_p), nick);
    return;
  }

  if (!HasUMode(source_p, UMODE_OPER))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               ID_or_name(&me, client_p),
               ID_or_name(source_p, client_p));
    return;
  }

  /*
   * The following two cases allow masks in NOTICEs
   * (for OPERs only)
   *
   * Armin, 8Jun90 (gruner@informatik.tu-muenchen.de)
   */
  if (*nick == '$')
  {
    if ((*(nick + 1) == '$' || *(nick + 1) == '#'))
      ++nick;
    else if (MyClient(source_p) && HasUMode(source_p, UMODE_OPER))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :The command %s %s is no longer supported, please use $%s",
                 me.name, source_p->name, command, nick, nick);
      return;
    }

    if ((s = strrchr(nick, '.')) == NULL)
    {
      sendto_one(source_p, form_str(ERR_NOTOPLEVEL),
                 me.name, source_p->name, nick);
      return;
    }

    while (*++s)
      if (*s == '.' || *s == '*' || *s == '?')
        break;

    if (*s == '*' || *s == '?')
    {
      sendto_one(source_p, form_str(ERR_WILDTOPLEVEL),
                 ID_or_name(&me, client_p),
                 ID_or_name(source_p, client_p), nick);
      return;
    }

    sendto_match_butone(IsServer(client_p) ? client_p : NULL, source_p,
                        nick + 1, (*nick == '#') ? MATCH_HOST : MATCH_SERVER,
                        "%s $%s :%s", command, nick, text);

    if ((p_or_n != NOTICE) && MyClient(source_p))
      source_p->localClient->last_privmsg = CurrentTime;
  }
}

/* build_target_list()
 *
 * inputs	- pointer to given client_p (server)
 *		- pointer to given source (oper/client etc.)
 *		- pointer to list of nicks/channels
 *		- pointer to table to place results
 *		- pointer to text (only used if source_p is an oper)
 * output	- number of valid entities
 * side effects	- target_table is modified to contain a list of
 *		  pointers to channels or clients
 *		  if source client is an oper
 *		  all the classic old bizzare oper privmsg tricks
 *		  are parsed and sent as is, if prefixed with $
 *		  to disambiguate.
 *
 */
static int
build_target_list(int p_or_n, const char *command, struct Client *client_p,
                  struct Client *source_p, char *nicks_channels, char *text)
{
  int type = 0;
  char *p = NULL, *nick = NULL;
  char *target_list = NULL;
  struct Channel *chptr = NULL;
  struct Client *target_p = NULL;

  target_list = nicks_channels;

  ntargets = 0;

  for (nick = strtoken(&p, target_list, ","); nick;
       nick = strtoken(&p, NULL, ","))
  {
    char *with_prefix;

    /*
     * Channels are privmsg'd a lot more than other clients, moved up
     * here plain old channel msg?
     */
    if (IsChanPrefix(*nick))
    {
      if ((chptr = hash_find_channel(nick)))
      {
        if (!duplicate_ptr(chptr))
        {
          if (ntargets >= ConfigFileEntry.max_targets)
          {
            sendto_one(source_p, form_str(ERR_TOOMANYTARGETS),
                       ID_or_name(&me, client_p),
                       ID_or_name(source_p, client_p), nick,
                       ConfigFileEntry.max_targets);
            return 1;
          }

          targets[ntargets].ptr = chptr;
          targets[ntargets++].type = ENTITY_CHANNEL;
        }
      }
      else
      {
        if (p_or_n != NOTICE)
          sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                     ID_or_name(&me, client_p),
                     ID_or_name(source_p, client_p), nick);
      }

      continue;
    }

    /* Look for a privmsg to another client */
    if ((target_p = find_person(client_p, nick)))
    {
      if (!duplicate_ptr(target_p))
      {
        if (ntargets >= ConfigFileEntry.max_targets)
        {
          sendto_one(source_p, form_str(ERR_TOOMANYTARGETS),
                     ID_or_name(&me, client_p),
                     ID_or_name(source_p, client_p), nick,
                     ConfigFileEntry.max_targets);
          return 1;
        }

        targets[ntargets].ptr = target_p;
        targets[ntargets].type = ENTITY_CLIENT;
        targets[ntargets++].flags = 0;
      }

      continue;
    }

    /* @#channel or +#channel message ? */
    type = 0;
    with_prefix = nick;

    /* Allow %+@ if someone wants to do that */
    for (; ;)
    {
      if (*nick == '@')
        type |= CHFL_CHANOP;
#ifdef HALFOPS
      else if (*nick == '%')
        type |= CHFL_CHANOP | CHFL_HALFOP;
#endif
      else if (*nick == '+')
        type |= CHFL_CHANOP | CHFL_HALFOP | CHFL_VOICE;
      else
        break;
      ++nick;
    }

    if (type != 0)
    {
      if (*nick == '\0')      /* if its a '\0' dump it, there is no recipient */
      {
        sendto_one(source_p, form_str(ERR_NORECIPIENT),
                   ID_or_name(&me, client_p),
                   ID_or_name(source_p, client_p), command);
        continue;
      }

      /*
       * At this point, nick+1 should be a channel name i.e. #foo or &foo
       * if the channel is found, fine, if not report an error
       */
      if ((chptr = hash_find_channel(nick)))
      {
        if (IsClient(source_p) && !HasFlag(source_p, FLAGS_SERVICE))
        {
          if (!has_member_flags(find_channel_link(source_p, chptr),
                                CHFL_CHANOP|CHFL_HALFOP|CHFL_VOICE))
          {
            sendto_one(source_p, form_str(ERR_CHANOPRIVSNEEDED),
                       ID_or_name(&me, client_p),
                       ID_or_name(source_p, client_p), with_prefix);
            return -1;
          }
        }

        if (!duplicate_ptr(chptr))
        {
          if (ntargets >= ConfigFileEntry.max_targets)
          {
            sendto_one(source_p, form_str(ERR_TOOMANYTARGETS),
                       ID_or_name(&me, client_p),
                       ID_or_name(source_p, client_p), nick,
                       ConfigFileEntry.max_targets);
            return 1;
          }

          targets[ntargets].ptr = chptr;
          targets[ntargets].type = ENTITY_CHANOPS_ON_CHANNEL;
          targets[ntargets++].flags = type;
        }
      }
      else
      {
        if (p_or_n != NOTICE)
          sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                     ID_or_name(&me, client_p),
                     ID_or_name(source_p, client_p), nick);
      }

      continue;
    }

    if (*nick == '$' || strchr(nick, '@'))
      handle_special(p_or_n, command, client_p, source_p, nick, text);
    else
    {
      if (p_or_n != NOTICE)
      {
        if (!IsDigit(*nick) || MyClient(source_p))
          sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                     ID_or_name(&me, client_p),
                     ID_or_name(source_p, client_p), nick);
      }
    }
    /* continue; */
  }

  return 1;
}

/*
 * inputs       - flag privmsg or notice
 *              - pointer to command "PRIVMSG" or "NOTICE"
 *              - pointer to client_p
 *              - pointer to source_p
 *              - pointer to channel
 */
static void
m_message(int p_or_n, const char *command, struct Client *client_p,
          struct Client *source_p, int parc, char *parv[])
{
  int i = 0;

  if (parc < 2 || EmptyString(parv[1]))
  {
    if (p_or_n != NOTICE)
      sendto_one(source_p, form_str(ERR_NORECIPIENT),
                 ID_or_name(&me, client_p),
                 ID_or_name(source_p, client_p), command);
    return;
  }

  if (parc < 3 || EmptyString(parv[2]))
  {
    if (p_or_n != NOTICE)
      sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
                 ID_or_name(&me, client_p),
                 ID_or_name(source_p, client_p));
    return;
  }

  /* Finish the flood grace period... */
  if (MyClient(source_p) && !IsFloodDone(source_p))
    flood_endgrace(source_p);

  if (build_target_list(p_or_n, command, client_p, source_p, parv[1], parv[2]) < 0)
    return;

  for (i = 0; i < ntargets; ++i)
  {
    switch (targets[i].type)
    {
      case ENTITY_CHANNEL:
        msg_channel(p_or_n, command, client_p, source_p, targets[i].ptr, parv[2]);
        break;

      case ENTITY_CHANOPS_ON_CHANNEL:
        msg_channel_flags(p_or_n, command, client_p, source_p,
                          targets[i].ptr, targets[i].flags, parv[2]);
        break;

      case ENTITY_CLIENT:
        msg_client(p_or_n, command, source_p, targets[i].ptr, parv[2]);
        break;
    }
  }
}

static int
m_privmsg(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  /*
   * Servers have no reason to send privmsgs, yet sometimes there is cause
   * for a notice.. (for example remote kline replies) --fl_
   */
  if (!IsClient(source_p))
    return 0;

  m_message(PRIVMSG, "PRIVMSG", client_p, source_p, parc, parv);
  return 0;
}

static int
m_notice(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  m_message(NOTICE, "NOTICE", client_p, source_p, parc, parv);
  return 0;
}

static struct Message privmsg_msgtab =
{
  "PRIVMSG", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_privmsg, m_privmsg, m_ignore, m_privmsg, m_ignore }
};

static struct Message notice_msgtab =
{
  "NOTICE", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_notice, m_notice, m_ignore, m_notice, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&privmsg_msgtab);
  mod_add_cmd(&notice_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&privmsg_msgtab);
  mod_del_cmd(&notice_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
