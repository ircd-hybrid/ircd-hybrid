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

/*! \file m_message.c
 * \brief Includes required functions for processing the PRIVMSG/NOTICE command.
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
#include "module.h"
#include "channel.h"
#include "channel_mode.h"
#include "irc_string.h"
#include "hash.h"
#include "misc.h"
#include "accept.h"

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
 * side effects - check for flood attack on target target
 */
static bool
flood_attack_client(bool notice, struct Client *source, struct Client *target)
{
  assert(MyClient(target));
  assert(IsClient(source));

  if (!(GlobalSetOptions.floodcount && GlobalSetOptions.floodtime))
    return false;

  if (HasUMode(source, UMODE_OPER))
    return false;

  if (HasFlag(source, FLAGS_SERVICE | FLAGS_CANFLOOD))
    return false;

  if (target->connection->first_received_message_time + GlobalSetOptions.floodtime < event_base->time.sec_monotonic)
  {
    if (target->connection->received_number_of_privmsgs)
      target->connection->received_number_of_privmsgs = 0;
    else
      DelFlag(target, FLAGS_FLOOD_NOTICED);

    target->connection->first_received_message_time = event_base->time.sec_monotonic;
  }

  if (target->connection->received_number_of_privmsgs >= GlobalSetOptions.floodcount)
  {
    if (!HasFlag(target, FLAGS_FLOOD_NOTICED))
    {
      sendto_realops_flags(UMODE_FLOOD, L_ALL, SEND_NOTICE, "Possible Flooder %s on %s target: %s",
                           client_get_name(source, HIDE_IP), source->servptr->name, target->name);
      AddFlag(target, FLAGS_FLOOD_NOTICED);
    }

    if (notice == false)
      sendto_one_notice(source, &me, ":*** Message to %s throttled due to flooding", target->name);
    return true;
  }

  ++target->connection->received_number_of_privmsgs;
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
flood_attack_channel(bool notice, struct Client *source, struct Channel *channel)
{
  if (!(GlobalSetOptions.floodcount && GlobalSetOptions.floodtime))
    return false;

  if (HasUMode(source, UMODE_OPER))
    return false;

  if (HasFlag(source, FLAGS_SERVICE | FLAGS_CANFLOOD))
    return false;

  if (channel->first_received_message_time + GlobalSetOptions.floodtime < event_base->time.sec_monotonic)
  {
    if (channel->received_number_of_privmsgs)
      channel->received_number_of_privmsgs = 0;
    else
      channel->sent_message_flood_notice = false;

    channel->first_received_message_time = event_base->time.sec_monotonic;
  }

  if (channel->received_number_of_privmsgs >= GlobalSetOptions.floodcount)
  {
    if (channel->sent_message_flood_notice == false)
    {
      sendto_realops_flags(UMODE_FLOOD, L_ALL, SEND_NOTICE, "Possible Flooder %s on %s target: %s",
                           client_get_name(source, HIDE_IP), source->servptr->name, channel->name);
      channel->sent_message_flood_notice = true;
    }

    if (MyClient(source))
    {
      if (notice == false)
        sendto_one_notice(source, &me, ":*** Message to %s throttled due to flooding", channel->name);
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
 *		- pointer to source
 *		- pointer to channel
 *		- flags
 *		- pointer to text to send
 * output	- NONE
 * side effects	- message given channel either chanop or voice
 */
static void
msg_channel(bool notice, struct Client *source, struct Channel *channel,
            unsigned int rank, const char *text)
{
  const char *error = NULL;

  /* Chanops and voiced can flood their own channel with impunity */
  int ret = can_send(channel, source, NULL, text, notice, &error);
  if (ret != CAN_SEND_NO)
  {
    if (ret == CAN_SEND_OPV || flood_attack_channel(notice, source, channel) == false)
    {
      const char *const prefix = channel_rank_to_prefix(rank);
      sendto_channel_butone(source, source, channel, rank, "%s %s%s :%s",
                            command[notice], prefix, channel->name, text);
    }
  }
  else if (notice == false)
    sendto_one_numeric(source, &me, ERR_CANNOTSENDTOCHAN, channel->name, error);
}

/* msg_client()
 *
 * inputs	- flag 0 if PRIVMSG 1 if NOTICE. RFC
 *		  say NOTICE must not auto reply
 * 		- pointer to source source (struct Client *)
 *		- pointer to target target (struct Client *)
 *		- pointer to text
 * output	- NONE
 * side effects	- message given channel either chanop or voice
 */
static void
msg_client(bool notice, struct Client *source, struct Client *target, const char *text)
{
  if (MyClient(source))
  {
    if (target->away[0] && notice == false)
      sendto_one_numeric(source, &me, RPL_AWAY, target->name, target->away);

    if (HasUMode(target, UMODE_SECUREONLY) && !HasUMode(source, UMODE_SECURE))
    {
      if (notice == false)
        sendto_one_numeric(source, &me, ERR_CANNOTSENDTOUSER, target->name,
                           "You must be connected via TLS to message this user");
      return;
    }

    if (HasUMode(source, UMODE_SECUREONLY) && !HasUMode(target, UMODE_SECURE))
    {
      if (notice == false)
        sendto_one_numeric(source, &me, ERR_CANNOTSENDTOUSER, target->name,
                           "Recipient is not connected via TLS and you are +Z");
      return;
    }

    if (HasUMode(target, UMODE_REGONLY) && target != source)
    {
      if (!HasUMode(source, UMODE_REGISTERED | UMODE_OPER))
      {
        if (notice == false)
          sendto_one_numeric(source, &me, ERR_CANNOTSENDTOUSER, target->name,
                             "You must identify to a registered account to message this user");
        return;
      }
    }
  }

  if (MyClient(target) && IsClient(source))
  {
    if (HasUMode(target, UMODE_CALLERID | UMODE_SOFTCALLERID) &&
        accept_message(source, target) == false)
    {
      bool callerid = HasUMode(target, UMODE_CALLERID) != 0;

      /* check for accept, flag recipient incoming message */
      if (notice == false)
        sendto_one_numeric(source, &me, RPL_TARGUMODEG,
                           target->name,
                           callerid ? "+g" : "+G",
                           callerid ? "server side ignore" :
                                      "server side ignore with the exception of common channels");

      if ((target->connection->last_caller_id_time +
           ConfigGeneral.caller_id_wait) < event_base->time.sec_monotonic)
      {
        if (notice == false)
          sendto_one_numeric(source, &me, RPL_TARGNOTIFY, target->name);

        sendto_one_numeric(target, &me, RPL_UMODEGMSG,
                           source->name, source->username, source->host,
                           callerid ? "+g" : "+G");
        target->connection->last_caller_id_time = event_base->time.sec_monotonic;
      }

      /* Only so opers can watch for floods */
      flood_attack_client(notice, source, target);
      return;
    }

    if (flood_attack_client(notice, source, target))
      return;
  }

  sendto_anywhere(target, source, command[notice], ":%s", text);
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
handle_special(bool notice, struct Client *source, const char *nick, const char *text)
{
  /*
   * nick@server addressed?
   */
  const char *server = strchr(nick, '@');
  if (server)
  {
    struct Client *target = hash_find_server(server + 1);
    if (target == NULL)
    {
      sendto_one_numeric(source, &me, ERR_NOSUCHSERVER, server + 1);
      return;
    }

    if (!IsMe(target))
    {
      sendto_one(target, ":%s %s %s :%s", source->id, command[notice], nick, text);
      return;
    }

    sendto_one_numeric(source, &me, ERR_NOSUCHNICK, nick);
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
    if (!HasUMode(source, UMODE_OPER))
    {
      sendto_one_numeric(source, &me, ERR_NOPRIVILEGES);
      return;
    }

    if (MyClient(source) && !HasOFlag(source, OPER_FLAG_MESSAGE_MASS))
    {
      sendto_one_numeric(source, &me, ERR_NOPRIVS, "message:mass");
      return;
    }

    if (*(nick + 1) == '$' || *(nick + 1) == '#')
      ++nick;
    else if (MyClient(source))
    {
      sendto_one_notice(source, &me, ":The command %s %s is no longer supported, please use $%s",
                        command[notice], nick, nick);
      return;
    }

    sendto_match_butone(IsServer(source->from) ? source->from : NULL, source, nick + 1,
                        (*nick == '#'), "%s $%s :%s", command[notice], nick, text);
  }
}

/* build_target_list()
 *
 * inputs	- pointer to given source (oper/client etc.)
 *		- pointer to list of nicks/channels
 *		- pointer to table to place results
 *		- pointer to text (only used if source is an oper)
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
build_target_list(bool notice, struct Client *source, char *list, const char *text)
{
  ntargets = 0;

  char *p = NULL;
  for (const char *name = strtok_r(list, ",", &p); name;
                   name = strtok_r(NULL, ",", &p))
  {
    void *target;

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
            sendto_one_numeric(source, &me, ERR_TOOMANYTARGETS,
                               name, ConfigGeneral.max_targets);
            return;
          }

          targets[ntargets].ptr = target;
          targets[ntargets].type = ENTITY_CHANNEL;
          targets[ntargets++].rank = 0;
        }
      }
      else if (notice == false)
        sendto_one_numeric(source, &me, ERR_NOSUCHNICK, name);

      continue;
    }

    /* Look for a PRIVMSG/NOTICE to another client */
    if ((target = find_person(source, name)))
    {
      if (duplicate_ptr(target) == false)
      {
        if (ntargets >= ConfigGeneral.max_targets)
        {
          sendto_one_numeric(source, &me, ERR_TOOMANYTARGETS,
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
    unsigned int ret;
    while ((ret = channel_prefix_to_rank(*name)) != CHACCESS_PEON)
    {
      rank = IO_MIN(rank, ret);
      ++name;
    }

    if (rank != CHACCESS_REMOTE)
    {
      if (EmptyString(name))  /* If it's a '\0' dump it, there is no recipient */
      {
        sendto_one_numeric(source, &me, ERR_NORECIPIENT, command[notice]);
        continue;
      }

      /*
       * At this point, name should be a channel name i.e. #foo. If the channel
       * is found, fine, if not report an error.
       */
      if ((target = hash_find_channel(name)))
      {
        if (IsClient(source) && !HasFlag(source, FLAGS_SERVICE))
        {
          if (member_highest_rank(member_find_link(source, target)) < CHACCESS_VOICE)
          {
            sendto_one_numeric(source, &me, ERR_CHANOPRIVSNEEDED, with_prefix);
            continue;
          }
        }

        if (duplicate_ptr(target) == false)
        {
          if (ntargets >= ConfigGeneral.max_targets)
          {
            sendto_one_numeric(source, &me, ERR_TOOMANYTARGETS,
                               name, ConfigGeneral.max_targets);
            return;
          }

          targets[ntargets].ptr = target;
          targets[ntargets].type = ENTITY_CHANNEL;
          targets[ntargets++].rank = rank;
        }
      }
      else if (notice == false)
        sendto_one_numeric(source, &me, ERR_NOSUCHNICK, name);

      continue;
    }

    if (*name == '$' || strchr(name, '@'))
      handle_special(notice, source, name, text);
    else if (notice == false)
    {
      if (!IsDigit(*name) || MyClient(source))
        sendto_one_numeric(source, &me, ERR_NOSUCHNICK, name);
    }
  }
}

/*
 * inputs       - flag privmsg or notice
 *              - pointer to source
 *              - pointer to channel
 */
static void
m_message(bool notice, struct Client *source, int parc, char *parv[])
{
  if (EmptyString(parv[1]))
  {
    if (notice == false)
      sendto_one_numeric(source, &me, ERR_NORECIPIENT, command[notice]);
    return;
  }

  if (EmptyString(parv[2]))
  {
    if (notice == false)
      sendto_one_numeric(source, &me, ERR_NOTEXTTOSEND);
    return;
  }

  build_target_list(notice, source, parv[1], parv[2]);

  for (unsigned int i = 0; i < ntargets; ++i)
  {
    switch (targets[i].type)
    {
      case ENTITY_CLIENT:
        msg_client(notice, source, targets[i].ptr, parv[2]);
        break;

      case ENTITY_CHANNEL:
        msg_channel(notice, source, targets[i].ptr, targets[i].rank, parv[2]);
        break;
    }
  }
}

static void
m_privmsg(struct Client *source, int parc, char *parv[])
{
  /*
   * Servers have no reason to send privmsgs, yet sometimes there is cause
   * for a notice.. (for example remote kline replies) --fl_
   */
  if (!IsClient(source))
    return;

  if (MyConnect(source))
    source->connection->last_privmsg = event_base->time.sec_monotonic;

  m_message(false, source, parc, parv);
}

static void
m_notice(struct Client *source, int parc, char *parv[])
{
  m_message(true, source, parc, parv);
}

static struct Command command_table[] =
{
  [0] = {
    .name = "PRIVMSG",
    .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
    .handlers[CLIENT_HANDLER] = { .handler = m_privmsg, .end_grace_period = true },
    .handlers[SERVER_HANDLER] = { .handler = m_privmsg },
    .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
    .handlers[OPER_HANDLER] = { .handler = m_privmsg, .end_grace_period = true }
  },
  [1] = {
    .name = "NOTICE",
    .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
    .handlers[CLIENT_HANDLER] = { .handler = m_notice },
    .handlers[SERVER_HANDLER] = { .handler = m_notice },
    .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
    .handlers[OPER_HANDLER] = { .handler = m_notice }
  }
};

static void
init_handler(void)
{
  command_add_array(command_table, IO_ARRAY_LENGTH(command_table));
}

static void
exit_handler(void)
{
  command_del_array(command_table, IO_ARRAY_LENGTH(command_table));
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
  .core = true
};
