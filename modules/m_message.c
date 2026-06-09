/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hook.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "misc.h"
#include "module.h"

#include "accept.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "client_find.h"
#include "client_format.h"
#include "conf.h"
#include "conf_oper.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

static const char *const command[] =
{
  [false] = "PRIVMSG",
  [true] = "NOTICE"
};

typedef struct
{
  const char *mask;
} target_mask_ctx_t;

static bool
target_filter_host(const struct Client *client, void *context)
{
  const target_mask_ctx_t *ctx = context;
  const char *const mask = ctx->mask;
  struct io_addr addr;
  int bits = 0;

  const int result = address_parse_netmask(mask, &addr, &bits);
  if (result == HM_IPV4 || result == HM_IPV6)
    return address_match(&client->addr, &addr, false, false, bits);

  return match(mask, client->realhost) == 0;
}

static bool
target_filter_server(const struct Client *client, void *context)
{
  const target_mask_ctx_t *const ctx = context;
  return match(ctx->mask, client->uplink->name) == 0;
}

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

static bool
flood_attack_client(bool notice, struct Client *source, struct Client *target)
{
  assert(client_is_local_user(target));
  assert(client_is_user(source));

  if (!(GlobalSetOptions.floodcount && GlobalSetOptions.floodtime))
    return false;

  if (client_is_oper(source))
    return false;

  if (client_has_flag(source, FLAGS_SERVICE | FLAGS_CANFLOOD))
    return false;

  const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);
  if (now - target->connection->first_received_message_time > GlobalSetOptions.floodtime)
  {
    if (target->connection->received_privmsg_count)
      target->connection->received_privmsg_count = 0;
    else
      client_unset_flag(target, FLAGS_FLOOD_NOTICED);

    target->connection->first_received_message_time = now;
  }

  if (target->connection->received_privmsg_count >= GlobalSetOptions.floodcount)
  {
    if (!client_has_flag(target, FLAGS_FLOOD_NOTICED))
    {
      client_format_name_buffer_t source_name_buffer;
      sendto_clients(UMODE_FLOOD, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Possible Flooder %s on %s target: %s",
                     client_format_name(source, CLIENT_FORMAT_NAME_PUBLIC, &source_name_buffer),
                     source->uplink->name, target->name);
      client_set_flag(target, FLAGS_FLOOD_NOTICED);
    }

    if (notice == false)
      sendto_one_notice(source, &me, ":*** Message to %s throttled due to flooding", target->name);
    return true;
  }

  ++target->connection->received_privmsg_count;
  return false;
}

static bool
flood_attack_channel(bool notice, struct Client *source, struct Channel *channel)
{
  if (!(GlobalSetOptions.floodcount && GlobalSetOptions.floodtime))
    return false;

  if (client_is_oper(source))
    return false;

  if (client_has_flag(source, FLAGS_SERVICE | FLAGS_CANFLOOD))
    return false;

  const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);
  if (now - channel->first_received_message_time > GlobalSetOptions.floodtime)
  {
    if (channel->received_privmsg_count)
      channel->received_privmsg_count = 0;
    else
      channel->sent_message_flood_notice = false;

    channel->first_received_message_time = now;
  }

  if (channel->received_privmsg_count >= GlobalSetOptions.floodcount)
  {
    if (channel->sent_message_flood_notice == false)
    {
      client_format_name_buffer_t source_name_buffer;
      sendto_clients(UMODE_FLOOD, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Possible Flooder %s on %s target: %s",
                     client_format_name(source, CLIENT_FORMAT_NAME_PUBLIC, &source_name_buffer),
                     source->uplink->name, channel->name);
      channel->sent_message_flood_notice = true;
    }

    if (client_is_local_user(source))
    {
      if (notice == false)
        sendto_one_notice(source, &me, ":*** Message to %s throttled due to flooding", channel->name);
      return true;
    }
  }

  ++channel->received_privmsg_count;
  return false;
}

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

  if (perm == CHANNEL_SEND_PERM_ELEVATED || !flood_attack_channel(notice, source, channel))
  {
    const char *const prefix = channel_member_rank_to_prefix(rank);
    sendto_channel_butone(source, source, channel, rank, "%s %s%s :%s",
                          command[notice], prefix, channel->name, text);
  }
}

static void
msg_client(bool notice, struct Client *source, struct Client *target, const char *text)
{
  ircd_hook_msg_client_ctx ctx = { .notice = notice, .source = source, .target = target, .text = text };

  if (client_is_local_user(source))
  {
    if (target->away_message && notice == false)
      sendto_one_numeric(source, &me, RPL_AWAY, target->name, target->away_message);

    if (hook_dispatch(ircd_hook_msg_client_source_local, &ctx) == HOOK_FLOW_STOP)
      return;
  }

  if (client_is_local_user(target) && client_is_user(source))
  {
    if (flood_attack_client(notice, source, target))
      return;

    if (hook_dispatch(ircd_hook_msg_client_target_local, &ctx) == HOOK_FLOW_STOP)
      return;
  }

  sendto_one_command(target, source, command[notice], ":%s", text);
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
  if (!client_is_oper(source))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVILEGES);
    return;
  }

  if (client_is_local_user(source) && !client_has_oper_flag(source, OPER_FLAG_MESSAGE_MASS))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "message:mass");
    return;
  }

  send_filter_fn filter_to_use = NULL;
  const char *mask = NULL;

  if (*(nick + 1) == '#')  /* $#host.mask */
  {
    filter_to_use = target_filter_host;
    mask = nick + 2;
  }
  else if (*(nick + 1) == '$')  /* $$server.mask */
  {
    filter_to_use = target_filter_server;
    mask = nick + 2;
  }
  else  /* Deprecated $server.mask */
  {
    if (client_is_local_user(source))
      sendto_one_notice(source, &me, ":Invalid syntax for mass-message target '%s'. Use $$<servermask> for servers or $#<hostmask> for hosts.",
                        nick);
    /* Silently ignore for remote opers. */
    return;
  }

  const struct Client *const exclude_uplink = client_is_server(source->nexthop) ? source->nexthop : NULL;
  target_mask_ctx_t ctx = { .mask = mask };

  sendto_filtered_butone(exclude_uplink, source, filter_to_use, &ctx, "%s %s :%s", command[notice], nick, text);
}

static void
target_handle_directed(struct Client *source, const char *nick, const char *text, bool notice)
{
  const char *const server = strchr(nick, '@');
  if (server == NULL)
    return;

  struct Client *const target = client_find_server(source, server + 1);
  if (target == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHSERVER, server + 1);
    return;
  }

  if (!client_is_me(target))
  {
    sendto_one(target, ":%s %s %s :%s", source->id, command[notice], nick, text);
    return;
  }

  sendto_one_numeric(source, &me, ERR_NOSUCHNICK, nick);
}

static void
target_handle_channel(struct Client *source, void *target, unsigned int access_rank)
{
  if (!target_is_duplicate(target))
    target_add_to_list(target, TARGET_ENTITY_CHANNEL, access_rank);
}

static void
target_handle_client(struct Client *source, void *target)
{
  if (!target_is_duplicate(target))
    target_add_to_list(target, TARGET_ENTITY_CLIENT, 0);
}

static void
target_process(struct Client *source, const char *name, const char *text, bool notice)
{
  unsigned int access_rank = 0;

  for (; *name; ++name)
  {
    unsigned int prefix_rank = channel_member_prefix_to_rank(*name);
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
    target = channel_find(name);
    if (target)
    {
      target_handle_channel(source, target, access_rank);
      return;
    }
  }
  else if ((target = client_find_user(source, name)))
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

  if (notice == false && client_is_local_user(source))
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
    struct Target *const target = &target_list[i];
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
  if (!client_is_user(source))
    return;

  if (client_is_local(source))
    source->connection->last_privmsg_time = io_time_get(IO_TIME_MONOTONIC_SEC);

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
