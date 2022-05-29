/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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
#include "server.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "channel.h"
#include "channel_mode.h"
#include "irc_string.h"
#include "hash.h"
#include "packet.h"
#include "misc.h"


enum
{
  ENTITY_NONE,
  ENTITY_CHANNEL,
  ENTITY_CLIENT
};

static const char *const command[] =
{
  [false] = "PRIVMSG",
  [true] = "NOTICE"
};

static struct
{
  void *ptr;
  unsigned int type;
  unsigned int rank;
} targets[IRCD_BUFSIZE];

static unsigned int ntargets;


/* duplicate_ptr()
 *
 * inputs       - pointer to check
 *              - pointer to table of entities
 *              - number of valid entities so far
 * output       - YES if duplicate pointer in table, NO if not.
 *                note, this does the canonize using pointers
 * side effects - NONE
 */
static bool
duplicate_ptr(const void *const ptr)
{
  for (unsigned int i = 0; i < ntargets; ++i)
    if (targets[i].ptr == ptr)
      return true;

  return false;
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
static bool
flood_attack_client(bool notice, struct Client *source_p, struct Client *target_p)
{
  assert(MyClient(target_p));
  assert(IsClient(source_p));

  if (!(GlobalSetOptions.floodcount && GlobalSetOptions.floodtime))
    return false;

  if (HasUMode(source_p, UMODE_OPER))
    return false;

  if (HasFlag(source_p, FLAGS_SERVICE | FLAGS_CANFLOOD))
    return false;

  if (target_p->connection->first_received_message_time + GlobalSetOptions.floodtime < event_base->time.sec_monotonic)
  {
    if (target_p->connection->received_number_of_privmsgs)
      target_p->connection->received_number_of_privmsgs = 0;
    else
      DelFlag(target_p, FLAGS_FLOOD_NOTICED);

    target_p->connection->first_received_message_time = event_base->time.sec_monotonic;
  }

  if (target_p->connection->received_number_of_privmsgs >= GlobalSetOptions.floodcount)
  {
    if (!HasFlag(target_p, FLAGS_FLOOD_NOTICED))
    {
      sendto_realops_flags(UMODE_FLOOD, L_ALL, SEND_NOTICE, "Possible Flooder %s on %s target: %s",
                           client_get_name(source_p, HIDE_IP),
                           source_p->servptr->name, target_p->name);
      AddFlag(target_p, FLAGS_FLOOD_NOTICED);
    }

    if (notice == false)
      sendto_one_notice(source_p, &me, ":*** Message to %s throttled due to flooding",
                        target_p->name);
    return true;
  }

  ++target_p->connection->received_number_of_privmsgs;
  return false;
}

/* flood_attack_channel()
 *
 * inputs       - flag 0 if PRIVMSG 1 if NOTICE. RFC
 *                says NOTICE must not auto reply
 *              - pointer to source Client
 *              - pointer to target channel
 * output       - 1 if target is under flood attack
 * side effects - check for flood attack on target channel
 */
static bool
flood_attack_channel(bool notice, struct Client *source_p, struct Channel *channel)
{
  if (!(GlobalSetOptions.floodcount && GlobalSetOptions.floodtime))
    return false;

  if (HasUMode(source_p, UMODE_OPER))
    return false;

  if (HasFlag(source_p, FLAGS_SERVICE | FLAGS_CANFLOOD))
    return false;

  if (channel->first_received_message_time + GlobalSetOptions.floodtime < event_base->time.sec_monotonic)
  {
    if (channel->received_number_of_privmsgs)
      channel->received_number_of_privmsgs = 0;
    else
      ClearFloodNoticed(channel);

    channel->first_received_message_time = event_base->time.sec_monotonic;
  }

  if (channel->received_number_of_privmsgs >= GlobalSetOptions.floodcount)
  {
    if (!IsSetFloodNoticed(channel))
    {
      sendto_realops_flags(UMODE_FLOOD, L_ALL, SEND_NOTICE, "Possible Flooder %s on %s target: %s",
                           client_get_name(source_p, HIDE_IP),
                           source_p->servptr->name, channel->name);
      SetFloodNoticed(channel);
    }

    if (MyClient(source_p))
    {
      if (notice == false)
        sendto_one_notice(source_p, &me, ":*** Message to %s throttled due to flooding",
                          channel->name);
      return true;
    }
  }

  ++channel->received_number_of_privmsgs;
  return false;
}

/* msg_channel_flags()
 *
 * inputs	- flag 0 if PRIVMSG 1 if NOTICE. RFC
 *		  say NOTICE must not auto reply
 *		- pointer to source_p
 *		- pointer to channel
 *		- flags
 *		- pointer to text to send
 * output	- NONE
 * side effects	- message given channel either chanop or voice
 */
static void
msg_channel(bool notice, struct Client *source_p, struct Channel *channel,
            unsigned int rank, const char *text)
{
  const char *prefix, *error = NULL;

  switch (rank)
  {
    case CHACCESS_VOICE:
      prefix = "+";
      break;
    case CHACCESS_HALFOP:
      prefix = "%";
      break;
    case CHACCESS_CHANOP:
      prefix = "@";
      break;
    case CHACCESS_CHANADMIN:
      prefix = "&";
      break;
    case CHACCESS_CHANOWNER:
      prefix = "~";
      break;
    default:
      prefix = "";
  }

  /* Chanops and voiced can flood their own channel with impunity */
  int ret = can_send(channel, source_p, NULL, text, notice, &error);
  if (ret != CAN_SEND_NO)
  {
    if (ret == CAN_SEND_OPV || flood_attack_channel(notice, source_p, channel) == false)
      sendto_channel_butone(source_p, source_p, channel, rank, "%s %s%s :%s",
                            command[notice], prefix, channel->name, text);
  }
  else if (notice == false)
    sendto_one_numeric(source_p, &me, ERR_CANNOTSENDTOCHAN, channel->name, error);
}

/* msg_client()
 *
 * inputs	- flag 0 if PRIVMSG 1 if NOTICE. RFC
 *		  say NOTICE must not auto reply
 * 		- pointer to source_p source (struct Client *)
 *		- pointer to target_p target (struct Client *)
 *		- pointer to text
 * output	- NONE
 * side effects	- message given channel either chanop or voice
 */
static void
msg_client(bool notice, struct Client *source_p, struct Client *target_p,
           const char *text)
{
  if (MyClient(source_p))
  {
    if (target_p->away[0] && notice == false)
      sendto_one_numeric(source_p, &me, RPL_AWAY, target_p->name, target_p->away);

    if (HasUMode(target_p, UMODE_REGONLY) && target_p != source_p)
    {
      if (!HasUMode(source_p, UMODE_REGISTERED | UMODE_OPER))
      {
        if (notice == false)
          sendto_one_numeric(source_p, &me, ERR_NONONREG, target_p->name);
        return;
      }
    }
  }

  if (MyClient(target_p) && IsClient(source_p))
  {
    if (HasUMode(target_p, UMODE_CALLERID | UMODE_SOFTCALLERID) &&
        accept_message(source_p, target_p) == false)
    {
      bool callerid = HasUMode(target_p, UMODE_CALLERID) != 0;

      /* check for accept, flag recipient incoming message */
      if (notice == false)
        sendto_one_numeric(source_p, &me, RPL_TARGUMODEG,
                           target_p->name,
                           callerid ? "+g" : "+G",
                           callerid ? "server side ignore" :
                                      "server side ignore with the exception of common channels");

      if ((target_p->connection->last_caller_id_time +
           ConfigGeneral.caller_id_wait) < event_base->time.sec_monotonic)
      {
        if (notice == false)
          sendto_one_numeric(source_p, &me, RPL_TARGNOTIFY, target_p->name);

        sendto_one_numeric(target_p, &me, RPL_UMODEGMSG,
                           source_p->name, source_p->username, source_p->host,
                           callerid ? "+g" : "+G");
        target_p->connection->last_caller_id_time = event_base->time.sec_monotonic;
      }

      /* Only so opers can watch for floods */
      flood_attack_client(notice, source_p, target_p);
      return;
    }

    if (flood_attack_client(notice, source_p, target_p) == true)
      return;
  }

  sendto_anywhere(target_p, source_p, command[notice], ":%s", text);
}

/* handle_special()
 *
 * inputs	- client pointer
 *		- nick stuff to grok for opers
 *		- text to send if grok
 * output	- none
 * side effects	- old style nick@server is handled here for non opers
 *		  all the traditional oper type messages are also parsed here.
 *		  i.e. "/msg #some.host."
 *		  However, syntax has been changed.
 *		  previous syntax "/msg #some.host.mask"
 *		  now becomes     "/msg $#some.host.mask"
 *		  previous syntax of: "/msg $some.server.mask" remains
 *		  This disambiguates the syntax.
 */
static void
handle_special(bool notice, struct Client *source_p,
               const char *nick, const char *text)
{
  /*
   * nick@server addressed?
   */
  const char *server = strchr(nick, '@');
  if (server)
  {
    struct Client *target_p = hash_find_server(server + 1);
    if (target_p == NULL)
    {
      sendto_one_numeric(source_p, &me, ERR_NOSUCHSERVER, server + 1);
      return;
    }

    if (!IsMe(target_p))
    {
      sendto_one(target_p, ":%s %s %s :%s", source_p->id, command[notice], nick, text);
      return;
    }

    sendto_one_numeric(source_p, &me, ERR_NOSUCHNICK, nick);
    return;
  }

  if (!HasUMode(source_p, UMODE_OPER))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVILEGES);
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
    if (*(nick + 1) == '$' || *(nick + 1) == '#')
      ++nick;
    else if (MyClient(source_p))
    {
      sendto_one_notice(source_p, &me, ":The command %s %s is no longer supported, please use $%s",
                        command[notice], nick, nick);
      return;
    }

    const char *s = strrchr(nick, '.');
    if (s == NULL)
    {
      sendto_one_numeric(source_p, &me, ERR_NOTOPLEVEL, nick);
      return;
    }

    while (*++s)
      if (*s == '.' || *s == '*' || *s == '?')
        break;

    if (*s == '*' || *s == '?')
    {
      sendto_one_numeric(source_p, &me, ERR_WILDTOPLEVEL, nick);
      return;
    }

    sendto_match_butone(IsServer(source_p->from) ? source_p->from : NULL, source_p,
                        nick + 1, (*nick == '#') ? MATCH_HOST : MATCH_SERVER,
                        "%s $%s :%s", command[notice], nick, text);
  }
}

/* build_target_list()
 *
 * inputs	- pointer to given source (oper/client etc.)
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
static void
build_target_list(bool notice, struct Client *source_p, char *list, const char *text)
{
  char *p = NULL;
  void *target = NULL;

  ntargets = 0;

  for (const char *name = strtok_r(list, ",", &p); name;
                   name = strtok_r(NULL, ",", &p))
  {
    /*
     * Channels are privmsg'd a lot more than other clients, moved up
     * here plain old channel msg?
     */
    if (IsChanPrefix(*name))
    {
      if ((target = hash_find_channel(name)))
      {
        if (duplicate_ptr(target) == false)
        {
          if (ntargets >= ConfigGeneral.max_targets)
          {
            sendto_one_numeric(source_p, &me, ERR_TOOMANYTARGETS,
                               name, ConfigGeneral.max_targets);
            return;
          }

          targets[ntargets].ptr = target;
          targets[ntargets].type = ENTITY_CHANNEL;
          targets[ntargets++].rank = 0;
        }
      }
      else if (notice == false)
        sendto_one_numeric(source_p, &me, ERR_NOSUCHNICK, name);

      continue;
    }

    /* Look for a PRIVMSG/NOTICE to another client */
    if ((target = find_person(source_p, name)))
    {
      if (duplicate_ptr(target) == false)
      {
        if (ntargets >= ConfigGeneral.max_targets)
        {
          sendto_one_numeric(source_p, &me, ERR_TOOMANYTARGETS,
                             name, ConfigGeneral.max_targets);
          return;
        }

        targets[ntargets].ptr = target;
        targets[ntargets].type = ENTITY_CLIENT;
        targets[ntargets++].rank = 0;
      }

      continue;
    }

    /* @#channel or +#channel message ? */
    unsigned int rank = CHACCESS_REMOTE;
    const char *with_prefix = name;

    /* Allow %+@ if someone wants to do that */
    while (true)
    {
      if (*name == '~')
        rank = IRCD_MIN(rank, CHACCESS_CHANOWNER);
      else if (*name == '&')
        rank = IRCD_MIN(rank, CHACCESS_CHANADMIN);
      else if (*name == '@')
        rank = IRCD_MIN(rank, CHACCESS_CHANOP);
      else if (*name == '%')
        rank = IRCD_MIN(rank, CHACCESS_HALFOP);
      else if (*name == '+')
        rank = IRCD_MIN(rank, CHACCESS_VOICE);
      else
        break;
      ++name;
    }

    if (rank != CHACCESS_REMOTE)
    {
      if (EmptyString(name))  /* If it's a '\0' dump it, there is no recipient */
      {
        sendto_one_numeric(source_p, &me, ERR_NORECIPIENT, command[notice]);
        continue;
      }

      /*
       * At this point, name should be a channel name i.e. #foo. If the channel
       * is found, fine, if not report an error.
       */
      if ((target = hash_find_channel(name)))
      {
        if (IsClient(source_p) && !HasFlag(source_p, FLAGS_SERVICE))
        {
          if (member_highest_rank(member_find_link(source_p, target)) < CHACCESS_VOICE)
          {
            sendto_one_numeric(source_p, &me, ERR_CHANOPRIVSNEEDED, with_prefix);
            continue;
          }
        }

        if (duplicate_ptr(target) == false)
        {
          if (ntargets >= ConfigGeneral.max_targets)
          {
            sendto_one_numeric(source_p, &me, ERR_TOOMANYTARGETS,
                               name, ConfigGeneral.max_targets);
            return;
          }

          targets[ntargets].ptr = target;
          targets[ntargets].type = ENTITY_CHANNEL;
          targets[ntargets++].rank = rank;
        }
      }
      else if (notice == false)
        sendto_one_numeric(source_p, &me, ERR_NOSUCHNICK, name);

      continue;
    }

    if (*name == '$' || strchr(name, '@'))
      handle_special(notice, source_p, name, text);
    else if (notice == false)
    {
      if (!IsDigit(*name) || MyClient(source_p))
        sendto_one_numeric(source_p, &me, ERR_NOSUCHNICK, name);
    }
  }
}

/*
 * inputs       - flag privmsg or notice
 *              - pointer to source_p
 *              - pointer to channel
 */
static void
m_message(bool notice, struct Client *source_p, int parc, char *parv[])
{
  if (EmptyString(parv[1]))
  {
    if (notice == false)
      sendto_one_numeric(source_p, &me, ERR_NORECIPIENT, command[notice]);
    return;
  }

  if (EmptyString(parv[2]))
  {
    if (notice == false)
      sendto_one_numeric(source_p, &me, ERR_NOTEXTTOSEND);
    return;
  }

  build_target_list(notice, source_p, parv[1], parv[2]);

  for (unsigned int i = 0; i < ntargets; ++i)
  {
    switch (targets[i].type)
    {
      case ENTITY_CLIENT:
        msg_client(notice, source_p, targets[i].ptr, parv[2]);
        break;

      case ENTITY_CHANNEL:
        msg_channel(notice, source_p, targets[i].ptr, targets[i].rank, parv[2]);
        break;
    }
  }
}

static void
m_privmsg(struct Client *source_p, int parc, char *parv[])
{
  /*
   * Servers have no reason to send privmsgs, yet sometimes there is cause
   * for a notice.. (for example remote kline replies) --fl_
   */
  if (!IsClient(source_p))
    return;

  if (MyConnect(source_p))
    source_p->connection->last_privmsg = event_base->time.sec_monotonic;

  m_message(false, source_p, parc, parv);
}

static void
m_notice(struct Client *source_p, int parc, char *parv[])
{
  m_message(true, source_p, parc, parv);
}

static struct Message privmsg_msgtab =
{
  .cmd = "PRIVMSG",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_privmsg, .end_grace_period = true },
  .handlers[SERVER_HANDLER] = { .handler = m_privmsg },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_privmsg, .end_grace_period = true }
};

static struct Message notice_msgtab =
{
  .cmd = "NOTICE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_notice },
  .handlers[SERVER_HANDLER] = { .handler = m_notice },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_notice }
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
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
  .is_core = true
};
