/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_message.c: Sends a (PRIVMSG|NOTICE) message to a user or channel.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "common.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "channel.h"
#include "channel_mode.h"
#include "irc_string.h"
#include "hash.h"
#include "packet.h"

struct entity
{
  void *ptr;
  int type;
  int flags;
};

static int build_target_list(int p_or_n, const char *command,
                             struct Client *client_p,
                             struct Client *source_p,
                             char *nicks_channels, char *text);

static int flood_attack_client(int p_or_n, struct Client *source_p,
                               struct Client *target_p);
static int flood_attack_channel(int p_or_n, struct Client *source_p,
                                struct Channel *chptr, char *chname);
static struct Client* find_userhost (char *, char *, int *);

#define ENTITY_NONE    0
#define ENTITY_CHANNEL 1
#define ENTITY_CHANOPS_ON_CHANNEL 2
#define ENTITY_CLIENT  3

static struct entity targets[512];
static int ntargets = 0;

static int duplicate_ptr(void *);

static void m_message(int, const char *, struct Client *,
                      struct Client *, int, char **);

static void m_privmsg(struct Client *, struct Client *, int, char **);
static void m_notice(struct Client *, struct Client *, int, char **);

static void msg_channel(int p_or_n, const char *command,
                        struct Client *client_p,
                        struct Client *source_p,
                        struct Channel *chptr, char *text);

static void msg_channel_flags(int p_or_n, const char *command,
                              struct Client *client_p,
                              struct Client *source_p,
                              struct Channel *chptr, int flags, char *text);

static void msg_client(int p_or_n, const char *command,
                       struct Client *source_p, struct Client *target_p,
                       char *text);

static void handle_special(int p_or_n, const char *command,
			   struct Client *client_p,
			   struct Client *source_p, char *nick, char *text);

struct Message privmsg_msgtab = {
  "PRIVMSG", 0, 0, 1, 0, MFLG_SLOW | MFLG_UNREG, 0L,
  {m_unregistered, m_privmsg, m_privmsg, m_ignore, m_privmsg, m_ignore}
};

struct Message notice_msgtab = {
  "NOTICE", 0, 0, 1, 0, MFLG_SLOW, 0L,
  {m_unregistered, m_notice, m_notice, m_ignore, m_notice, m_ignore}
};

void
_modinit(void)
{
  mod_add_cmd(&privmsg_msgtab);
  mod_add_cmd(&notice_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&privmsg_msgtab);
  mod_del_cmd(&notice_msgtab);
}

const char *_version = "$Revision$";

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

#define PRIVMSG 0
#define NOTICE  1

static void
m_privmsg(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  /* servers have no reason to send privmsgs, yet sometimes there is cause
   * for a notice.. (for example remote kline replies) --fl_
   */
  if (!IsClient(source_p))
    return;

  m_message(PRIVMSG, "PRIVMSG", client_p, source_p, parc, parv);
}

static void
m_notice(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  m_message(NOTICE, "NOTICE", client_p, source_p, parc, parv);
}

/*
 * inputs	- flag privmsg or notice
 * 		- pointer to command "PRIVMSG" or "NOTICE"
 *		- pointer to client_p
 *		- pointer to source_p
 *		- pointer to channel
 */
static void
m_message(int p_or_n, const char *command, struct Client *client_p,
          struct Client *source_p, int parc, char *parv[])
{
  int i;

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

  if (build_target_list(p_or_n, command, client_p, source_p, parv[1],
                        parv[2]) < 0)
    return;

  for (i = 0; i < ntargets; i++)
  {
    switch (targets[i].type)
    {
      case ENTITY_CHANNEL:
        msg_channel(p_or_n, command, client_p, source_p,
                    (struct Channel *)targets[i].ptr, parv[2]);
        break;

      case ENTITY_CHANOPS_ON_CHANNEL:
        msg_channel_flags(p_or_n, command, client_p, source_p,
                          (struct Channel *)targets[i].ptr,
                          targets[i].flags, parv[2]);
        break;

      case ENTITY_CLIENT:
        msg_client(p_or_n, command, source_p,
                   (struct Client *)targets[i].ptr, parv[2]);
        break;
    }
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
  int type;
  char *p = NULL, *nick, *target_list;
  struct Channel *chptr = NULL;
  struct Client *target_p = NULL;

  target_list = nicks_channels;

  ntargets = 0;

  for (nick = strtoken(&p, target_list, ","); nick;
       nick = strtoken(&p, NULL, ","))
  {
    char *with_prefix;
    /*
     * channels are privmsg'd a lot more than other clients, moved up
     * here plain old channel msg?
     */

    if (IsChanPrefix(*nick))
    {
      /* ignore send of local channel to a server (should not happen) */
      if (*nick == '&' && IsServer(client_p))
        continue;

      if ((chptr = hash_find_channel(nick)) != NULL)
      {
        if (!duplicate_ptr(chptr))
        {
          if (ntargets >= ConfigFileEntry.max_targets)
          {
            sendto_one(source_p, form_str(ERR_TOOMANYTARGETS),
                       ID_or_name(&me, client_p),
                       ID_or_name(source_p, client_p), nick,
		       ConfigFileEntry.max_targets);
            return (1);
          }
          targets[ntargets].ptr = (void *)chptr;
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

    /* look for a privmsg to another client */
    if ((target_p = find_person(client_p, nick)) != NULL)
    {
      if (!duplicate_ptr(target_p))
      {
        if (ntargets >= ConfigFileEntry.max_targets)
	  {
	    sendto_one(source_p, form_str(ERR_TOOMANYTARGETS),
                       ID_or_name(&me, client_p),
                       ID_or_name(source_p, client_p), nick,
		       ConfigFileEntry.max_targets);
	    return (1);
	  }
        targets[ntargets].ptr = (void *)target_p;
        targets[ntargets].type = ENTITY_CLIENT;
        targets[ntargets++].flags = 0;
      }
      continue;
    }
    
    /* @#channel or +#channel message ? */

    type = 0;
    with_prefix = nick;
    /*  allow %+@ if someone wants to do that */
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
      nick++;
    }

    if (type != 0)
    {
      /* suggested by Mortiis */
      if (*nick == '\0')      /* if its a '\0' dump it, there is no recipient */
      {
        sendto_one(source_p, form_str(ERR_NORECIPIENT),
                   ID_or_name(&me, client_p),
                   ID_or_name(source_p, client_p), command);
        continue;
      }

      /* At this point, nick+1 should be a channel name i.e. #foo or &foo
       * if the channel is found, fine, if not report an error
       */

      if ((chptr = hash_find_channel(nick)) != NULL)
      {
        if (!has_member_flags(find_channel_link(source_p, chptr),
                              CHFL_CHANOP|CHFL_HALFOP|CHFL_VOICE))
        {
          sendto_one(source_p, form_str(ERR_CHANOPRIVSNEEDED),
                     ID_or_name(&me, client_p),
                     ID_or_name(source_p, client_p), with_prefix);
          return(-1);
        }

        if (!duplicate_ptr(chptr))
        {
          if (ntargets >= ConfigFileEntry.max_targets)
          {
	    sendto_one(source_p, form_str(ERR_TOOMANYTARGETS),
                       ID_or_name(&me, client_p),
                       ID_or_name(source_p, client_p), nick,
		       ConfigFileEntry.max_targets);
            return(1);
          }
          targets[ntargets].ptr = (void *)chptr;
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

    if ((*nick == '$') || strchr(nick, '@') != NULL)
    {
      handle_special(p_or_n, command, client_p, source_p, nick, text);
    }
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

  return(1);
}

/* duplicate_ptr()
 *
 * inputs	- pointer to check
 *		- pointer to table of entities
 *		- number of valid entities so far
 * output	- YES if duplicate pointer in table, NO if not.
 *		  note, this does the canonize using pointers
 * side effects	- NONE
 */
static int
duplicate_ptr(void *ptr)
{
  int i;

  for (i = 0; i < ntargets; i++)
  {
    if (targets[i].ptr == ptr)
      return(1);
  }

  return(0);
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
  int result;

  if (MyClient(source_p))
  {
    /* idle time shouldnt be reset by notices --fl */
    if (p_or_n != NOTICE)
      source_p->localClient->last = CurrentTime;
  }

  /* chanops and voiced can flood their own channel with impunity */
  if ((result = can_send(chptr, source_p, NULL)))
  {
    if (result == CAN_SEND_OPV ||
        !flood_attack_channel(p_or_n, source_p, chptr, chptr->chname))
    {
      sendto_channel_butone(client_p, source_p, chptr, command, ":%s", text);
    }
  }
  else
  {
    if (p_or_n != NOTICE)
      sendto_one(source_p, form_str(ERR_CANNOTSENDTOCHAN),
                 ID_or_name(&me, client_p),
                 ID_or_name(source_p, client_p), chptr->chname);
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
  int type;
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

  if (MyClient(source_p))
  {
    /* idletime shouldnt be reset by notice --fl */
    if (p_or_n != NOTICE)
      source_p->localClient->last = CurrentTime;

    sendto_channel_local_butone(source_p, type, chptr, ":%s!%s@%s %s %c%s :%s",
                                source_p->name, source_p->username,
                                source_p->host, command, c, chptr->chname, text);
  }
  else
  {
    /*
     * another good catch, lee.  we never would echo to remote clients anyway,
     * so use slightly less intensive sendto_channel_local()
     */
    sendto_channel_local(type, YES, chptr, ":%s!%s@%s %s %c%s :%s",
                         source_p->name, source_p->username,
                         source_p->host, command, c, chptr->chname, text);
  }

  if (chptr->chname[0] != '#')
    return;

  sendto_channel_remote(source_p, client_p, type, CAP_CHW, CAP_TS6, chptr,
                ":%s %s %c%s :%s", source_p->name, command, c, chptr->chname, text);
  sendto_channel_remote(source_p, client_p, type, CAP_CHW|CAP_TS6, NOCAPS, chptr,
                ":%s %s %c%s :%s", ID(source_p), command, c, chptr->chname, text);
  /* non CAP_CHW servers? */
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
  if (MyClient(source_p))
  {
    /*
     * reset idle time for message only if its not to self 
     * and its not a notice
     * NOTE: Normally we really should reset their idletime
     * if the are messaging themselves, but we have to go
     * this way in order to prevent them to trick out
     * idle-klines.
     */
    if ((p_or_n != NOTICE) && (source_p != target_p))
      source_p->localClient->last = CurrentTime;
  }

  if (MyConnect(source_p) && (p_or_n != NOTICE) && target_p->away)
    sendto_one(source_p, form_str(RPL_AWAY), me.name,
               source_p->name, target_p->name, target_p->away);

  if (MyClient(target_p))
  {
    if (!IsServer(source_p) && IsSetCallerId(target_p))
    {
      /* Here is the anti-flood bot/spambot code -db */
      if (source_p == target_p || accept_message(source_p, target_p) ||
         (IsOper(source_p) && (ConfigFileEntry.opers_bypass_callerid == 1)))
      {
        sendto_one(target_p, ":%s!%s@%s %s %s :%s",
                   source_p->name, source_p->username,
                   source_p->host, command, target_p->name, text);
      }
      else
      {
        /* check for accept, flag recipient incoming message */
        if (p_or_n != NOTICE)
	  sendto_one(source_p, form_str(RPL_TARGUMODEG),
		     ID_or_name(&me, source_p->from),
		     ID_or_name(source_p, source_p->from), target_p->name);

        if ((target_p->localClient->last_caller_id_time +
             ConfigFileEntry.caller_id_wait) < CurrentTime)
        {
          if (p_or_n != NOTICE)
	    sendto_one(source_p, form_str(RPL_TARGNOTIFY),
		       ID_or_name(&me, source_p->from),
		       ID_or_name(source_p, source_p->from), target_p->name);

          sendto_one(target_p, form_str(RPL_UMODEGMSG),
                     me.name, target_p->name,
                     get_client_name(source_p, HIDE_IP));

          target_p->localClient->last_caller_id_time = CurrentTime;

        }
        /* Only so opers can watch for floods */
        flood_attack_client(p_or_n, source_p, target_p);
      }
    }
    else
    {
      /* If the client is remote, we dont perform a special check for
       * flooding.. as we wouldnt block their message anyway.. this means
       * we dont give warnings.. we then check if theyre opered 
       * (to avoid flood warnings), lastly if theyre our client
       * and flooding    -- fl */
      if (!MyClient(source_p) || IsOper(source_p) ||
          (MyClient(source_p) &&
           !flood_attack_client(p_or_n, source_p, target_p)))
        sendto_anywhere(target_p, source_p, "%s %s :%s",
                        command, target_p->name, text);
    }
  }
  else
    /* The target is a remote user.. same things apply  -- fl */
  if (!MyClient(source_p) || IsOper(source_p) ||
        (MyClient(source_p)
           && !flood_attack_client(p_or_n, source_p, target_p)))
    sendto_anywhere(target_p, source_p, "%s %s :%s", command, target_p->name,
                    text);
}

/* flood_attack_client()
 *
 * inputs       - flag 0 if PRIVMSG 1 if NOTICE. RFC
 *                say NOTICE must not auto reply
 *              - pointer to source Client 
 *		- pointer to target Client
 * output	- 1 if target is under flood attack
 * side effects	- check for flood attack on target target_p
 */
static int
flood_attack_client(int p_or_n, struct Client *source_p,
                    struct Client *target_p)
{
  int delta;

  if (GlobalSetOptions.floodcount && MyConnect(target_p)
      && IsClient(source_p) && !IsConfCanFlood(source_p))
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
        ClearMsgFloodNoticed(target_p);
      }
    }

    if ((target_p->localClient->received_number_of_privmsgs >=
         GlobalSetOptions.floodcount) || IsMsgFloodNoticed(target_p))
    {
      if (!IsMsgFloodNoticed(target_p))
      {
        sendto_realops_flags(UMODE_BOTS, L_ALL,
                             "Possible Flooder %s on %s target: %s",
                             get_client_name(source_p, HIDE_IP),
                             source_p->servptr->name, target_p->name);
        SetMsgFloodNoticed(target_p);
        /* add a bit of penalty */
        target_p->localClient->received_number_of_privmsgs += 2;
      }

      if (MyClient(source_p) && (p_or_n != NOTICE))
        sendto_one(source_p,
                   ":%s NOTICE %s :*** Message to %s throttled due to flooding",
                   me.name, source_p->name, target_p->name);
      return(1);
    }
    else
      target_p->localClient->received_number_of_privmsgs++;
  }

  return(0);
}

/* flood_attack_channel()
 *
 * inputs       - flag 0 if PRIVMSG 1 if NOTICE. RFC
 *                says NOTICE must not auto reply
 *              - pointer to source Client 
 *		- pointer to target channel
 * output	- 1 if target is under flood attack
 * side effects	- check for flood attack on target chptr
 */
static int
flood_attack_channel(int p_or_n, struct Client *source_p,
                     struct Channel *chptr, char *chname)
{
  int delta;

  if (GlobalSetOptions.floodcount && !IsConfCanFlood(source_p))
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

    if ((chptr->received_number_of_privmsgs >= GlobalSetOptions.floodcount)
        || IsSetFloodNoticed(chptr))
    {
      if (!IsSetFloodNoticed(chptr))
      {
        sendto_realops_flags(UMODE_BOTS, L_ALL,
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
                   me.name, source_p->name, chname);
      return(1);
    }
    else
      chptr->received_number_of_privmsgs++;
  }

  return(0);
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
  if ((server = strchr(nick, '@')) != NULL)
  {
    count = 0;

    if ((host = strchr(nick, '%')) && !IsOper(source_p))
    {
      sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
                 ID_or_name(&me, client_p),
                 ID_or_name(source_p, client_p));
      return;
    }

    if ((target_p = find_server(server + 1)) != NULL)
    {
      if (!IsMe(target_p))
      {
	/*
	 * Not destined for a user on me :-(
	 */
	sendto_one(target_p, ":%s %s %s :%s",
                   ID_or_name(source_p, target_p->from),
		   command, nick, text);
	if ((p_or_n != NOTICE) && MyClient(source_p))
	  source_p->localClient->last = CurrentTime;
	return;
      }

      *server = '\0';

      if (host != NULL)
	*host++ = '\0';

      /* Check if someones msg'ing opers@our.server */
      if (strcmp(nick, "opers") == 0)
      {
	if (!IsOper(source_p))
	  sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
                     ID_or_name(&me, client_p),
                     ID_or_name(source_p, client_p));
	else
	  sendto_realops_flags(UMODE_ALL, L_ALL, "To opers: From: %s: %s",
			       source_p->name, text);
	return;
      }

      /*
       * Look for users which match the destination host
       * (no host == wildcard) and if one and one only is
       * found connected to me, deliver message!
       */
      target_p = find_userhost(nick, host, &count);

      if (target_p != NULL)
      {
	if (server != NULL)
	  *server = '@';
	if (host != NULL)
	  *--host = '%';

	if (count == 1)
	{
	  sendto_one(target_p, ":%s!%s@%s %s %s :%s",
		     source_p->name, source_p->username, source_p->host,
                     command, nick, text);
	  if ((p_or_n != NOTICE) && MyClient(source_p))
	    source_p->localClient->last = CurrentTime;
	}
	else
	  sendto_one(source_p, form_str(ERR_TOOMANYTARGETS),
                     ID_or_name(&me, client_p),
                     ID_or_name(source_p, client_p), nick,
		     ConfigFileEntry.max_targets);
      }
    }
    else if (server && *(server+1) && (target_p == NULL))
	sendto_one(source_p, form_str(ERR_NOSUCHSERVER),
                   ID_or_name(&me, client_p),
                   ID_or_name(source_p, client_p), server+1);
    else if (server && (target_p == NULL))
	sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                   ID_or_name(&me, client_p),
                   ID_or_name(source_p, client_p), nick);
    return;
  }

  if (!IsOper(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               ID_or_name(&me, client_p),
               ID_or_name(source_p, client_p));
    return;
  }

  /*
   * the following two cases allow masks in NOTICEs
   * (for OPERs only)
   *
   * Armin, 8Jun90 (gruner@informatik.tu-muenchen.de)
   */
  if (*nick == '$')
  {
    if ((*(nick+1) == '$' || *(nick+1) == '#'))
      nick++;
    else if(MyOper(source_p))
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
      source_p->localClient->last = CurrentTime;

    return;
  }
}

/*
 * find_userhost - find a user@host (server or user).
 * inputs       - user name to look for
 *              - host name to look for
 *		- pointer to count of number of matches found
 * outputs	- pointer to client if found
 *		- count is updated
 * side effects	- none
 *
 */
static struct Client *
find_userhost(char *user, char *host, int *count)
{
  struct Client *c2ptr;
  struct Client *res = NULL;
  dlink_node *lc2ptr;

  *count = 0;

  if (collapse(user) != NULL)
  {
    DLINK_FOREACH(lc2ptr, local_client_list.head)
    {
      c2ptr = lc2ptr->data;

      if (!IsClient(c2ptr)) /* something other than a client */
        continue;

      if ((!host || match(host, c2ptr->host)) &&
          irccmp(user, c2ptr->username) == 0)
      {
        (*count)++;
        res = c2ptr;
      }
    }
  }

  return(res);
}
