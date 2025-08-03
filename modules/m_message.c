/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2025 ircd-hybrid development team
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

#include "hook.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "misc.h"
#include "module.h"
#include "stdinc.h"
#include "accept.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "conf.h"
#include "conf_oper.h"
#include "hash.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "user_mode.h"

static const char *const command[] =
{
  [false] = "PRIVMSG",
  [true] = "NOTICE"
};

typedef enum
{
  TARGET_ENTITY_NONE,
  TARGET_ENTITY_CHANNEL,
  TARGET_ENTITY_CLIENT,
} target_entity_t;

struct Target
{
  void *ptr;
  target_entity_t type;
  unsigned int rank;
};

static struct Target target_list[IRCD_BUFSIZE / 2];
static unsigned int target_count;


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
target_is_duplicate(const void *const ptr)
{
  for (unsigned int i = 0; i < target_count; ++i)
    if (target_list[i].ptr == ptr)
      return true;

  return false;
}

static bool
target_check_limit_exceeded(struct Client *source, const char *name)
{
  if (target_count >= ConfigGeneral.max_targets)
  {
    sendto_one_numeric(source, &me, ERR_TOOMANYTARGETS, name, ConfigGeneral.max_targets);
    return true;
  }

  return false;
}

static void
target_add_to_list(void *target_ptr, int target_type, unsigned int access_rank)
{
  if (target_count >= IO_ARRAY_LENGTH(target_list))
    return;

  target_list[target_count++] =
    (struct Target){ .ptr = target_ptr, .type = target_type, .rank = access_rank };
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

  if (user_mode_has_flag(source, UMODE_OPER))
    return false;

  if (HasFlag(source, FLAGS_SERVICE | FLAGS_CANFLOOD))
    return false;

  if (target->connection->first_received_message_time + GlobalSetOptions.floodtime < io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    if (target->connection->received_number_of_privmsgs)
      target->connection->received_number_of_privmsgs = 0;
    else
      DelFlag(target, FLAGS_FLOOD_NOTICED);

    target->connection->first_received_message_time = io_time_get(IO_TIME_MONOTONIC_SEC);
  }

  if (target->connection->received_number_of_privmsgs >= GlobalSetOptions.floodcount)
  {
    if (!HasFlag(target, FLAGS_FLOOD_NOTICED))
    {
      sendto_clients(UMODE_FLOOD, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Possible Flooder %s on %s target: %s",
                     client_get_name(source, HIDE_IP), source->uplink->name, target->name);
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

  if (user_mode_has_flag(source, UMODE_OPER))
    return false;

  if (HasFlag(source, FLAGS_SERVICE | FLAGS_CANFLOOD))
    return false;

  if (channel->first_received_message_time + GlobalSetOptions.floodtime < io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    if (channel->received_number_of_privmsgs)
      channel->received_number_of_privmsgs = 0;
    else
      channel->sent_message_flood_notice = false;

    channel->first_received_message_time = io_time_get(IO_TIME_MONOTONIC_SEC);
  }

  if (channel->received_number_of_privmsgs >= GlobalSetOptions.floodcount)
  {
    if (channel->sent_message_flood_notice == false)
    {
      sendto_clients(UMODE_FLOOD, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Possible Flooder %s on %s target: %s",
                     client_get_name(source, HIDE_IP), source->uplink->name, channel->name);
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
  channel_send_perm_t perm = channel_send_qualifies(channel, source, NULL, rank, text, notice, &error);
  if (perm == CHANNEL_SEND_PERM_FORBIDDEN)
  {
    if (notice == false)
      sendto_one_numeric(source, &me, ERR_CANNOTSENDTOCHAN, channel->name, error);
    return;
  }

  if (perm == CHANNEL_SEND_PERM_ELEVATED || flood_attack_channel(notice, source, channel) == false)
  {
    const char *const prefix = channel_rank_to_prefix(rank);
    sendto_channel_butone(source, source, channel, rank, "%s %s%s :%s",
                          command[notice], prefix, channel->name, text);
  }
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
  ircd_hook_msg_client_ctx ctx = { .notice = notice, .source = source, .target = target, .text = text };

  if (MyClient(source))
  {
    if (target->away && notice == false)
      sendto_one_numeric(source, &me, RPL_AWAY, target->name, target->away);

    if (hook_dispatch(ircd_hook_msg_client_source_local, &ctx) == HOOK_FLOW_STOP)
      return;
  }

  if (MyClient(target) && IsClient(source))
  {
    if (flood_attack_client(notice, source, target))
      return;

    if (hook_dispatch(ircd_hook_msg_client_target_local, &ctx) == HOOK_FLOW_STOP)
      return;
  }

  sendto_one_anywhere(target, source, command[notice], ":%s", text);
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
target_handle_masked(struct Client *source, const char *nick, const char *text, bool notice)
{
  if (user_mode_has_flag(source, UMODE_OPER) == false)
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
                      (*nick == '#') ? SEND_MATCH_HOST : SEND_MATCH_SERVER, "%s $%s :%s", command[notice], nick, text);
}

static void
target_handle_directed(struct Client *source, const char *nick, const char *text, bool notice)
{
  const char *server = strchr(nick, '@');
  if (server == NULL)
    return;

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
}

static void
target_handle_channel(struct Client *source, void *target, unsigned int access_rank)
{
  if (target_is_duplicate(target) == false)
    target_add_to_list(target, TARGET_ENTITY_CHANNEL, access_rank);
}

static void
target_handle_client(struct Client *source, void *target)
{
  if (target_is_duplicate(target) == false)
    target_add_to_list(target, TARGET_ENTITY_CLIENT, 0);
}

static void
target_process(struct Client *source, const char *name, const char *text, bool notice)
{
  unsigned int access_rank = 0;

  for (; *name; ++name)
  {
    unsigned int prefix_rank = channel_prefix_to_rank(*name);
    if (prefix_rank == CHACCESS_PEON)
      break;
    if (access_rank == 0 || prefix_rank < access_rank)
      access_rank = prefix_rank;
  }

  if (string_is_empty(name))
  {
    sendto_one_numeric(source, &me, ERR_NORECIPIENT, command[notice]);
    return;
  }

  void *target;
  if (IsChanPrefix(*name))
  {
    target = hash_find_channel(name);
    if (target)
    {
      target_handle_channel(source, target, access_rank);
      return;
    }
  }
  else if ((target = find_person(source, name)))
  {
    target_handle_client(source, target);
    return;
  }
  else if (*name == '$')
  {
    target_handle_masked(source, name, text, notice);
    return;
  }
  else if (strchr(name, '@'))
  {
    target_handle_directed(source, name, text, notice);
    return;
  }

  if (notice == false && (!IsDigit(*name) || MyClient(source)))
    sendto_one_numeric(source, &me, ERR_NOSUCHNICK, name);
}

static void
target_process_list(struct Client *source, char *list, const char *text, bool notice)
{
  char *p = NULL;

  target_count = 0;

  for (const char *name = strtok_r(list, ",", &p); name;
                   name = strtok_r(NULL, ",", &p))
  {
    if (target_check_limit_exceeded(source, name))
      break;
    target_process(source, name, text, notice);
  }
}

/*
 * inputs       - flag privmsg or notice
 *              - pointer to source
 *              - pointer to channel
 */
static void
m_message(struct Client *source, int parc, char *parv[], bool notice)
{
  if (string_is_empty(parv[1]))
  {
    if (notice == false)
      sendto_one_numeric(source, &me, ERR_NORECIPIENT, command[notice]);
    return;
  }

  if (string_is_empty(parv[2]))
  {
    if (notice == false)
      sendto_one_numeric(source, &me, ERR_NOTEXTTOSEND);
    return;
  }

  target_process_list(source, parv[1], parv[2], notice);

  for (unsigned int i = 0; i < target_count; ++i)
  {
    struct Target *target = &target_list[i];
    switch (target->type)
    {
      case TARGET_ENTITY_CLIENT:
        msg_client(notice, source, target->ptr, parv[2]);
        break;
      case TARGET_ENTITY_CHANNEL:
        msg_channel(notice, source, target->ptr, target->rank, parv[2]);
        break;
      default:
        abort();  /* Invalid entity, abort the program. */
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
    source->connection->last_privmsg = io_time_get(IO_TIME_MONOTONIC_SEC);

  m_message(source, parc, parv, false);
}

static void
m_notice(struct Client *source, int parc, char *parv[])
{
  m_message(source, parc, parv, true);
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
