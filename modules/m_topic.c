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

/*! \file m_topic.c
 * \brief Includes required functions for processing the TOPIC command.
 */

#include <stddef.h>
#include <stdio.h>

#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "module.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

static void
_topic_format_setter_info(const struct Client *source, char *buf, size_t buflen)
{
  if (client_is_user(source))
  {
    snprintf(buf, buflen, "%s!%s@%s",
             source->name, source->username, source->host);
    return;
  }

  strlcpy(buf, client_get_visible_server_name(source), buflen);
}

static void
_topic_notify_channel_members(struct Client *source, const struct Channel *channel)
{
  if (client_is_user(source))
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s!%s@%s TOPIC %s :%s",
                         source->name, source->username, source->host, channel->name, string_or_empty(channel->topic));
  else
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s TOPIC %s :%s",
                         client_get_visible_server_name(source), channel->name, string_or_empty(channel->topic));
}

static void
_topic_commit(struct Client *source, struct Channel *channel, const char *topic)
{
  char topic_info[NICKLEN + USERLEN + HOSTLEN + 3];  /* +3 for !, @, \0 */
  _topic_format_setter_info(source, topic_info, sizeof(topic_info));

  channel_set_topic(channel, topic, topic_info, io_time_get(IO_TIME_REALTIME_SEC), client_is_local_user(source));

  sendto_servers(source, 0, 0, ":%s TOPIC %s :%s",
                 source->id, channel->name, string_or_empty(channel->topic));
  _topic_notify_channel_members(source, channel);
}

static void
_topic_send_current(struct Client *source, const struct Channel *channel)
{
  if (string_is_empty(channel->topic))
  {
    sendto_one_numeric(source, &me, RPL_NOTOPIC, channel->name);
    return;
  }

  sendto_one_numeric(source, &me, RPL_TOPIC,
                     channel->name, channel->topic);
  sendto_one_numeric(source, &me, RPL_TOPICWHOTIME,
                     channel->name, channel->topic_info, channel->topic_time);
}

/*! \brief TOPIC command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 *      - parv[2] = topic text, if setting topic (can be an empty string)
 */
static void
m_topic(struct Client *source, int parc, char *parv[])
{
  const char *const channel_name = parv[1];

  struct Channel *const channel = channel_find(channel_name);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, channel_name);
    return;
  }

  /* Setting topic */
  if (parc > 2)
  {
    const struct ChannelMember *const member = channel_member_find(source, channel);
    if (member == NULL)
    {
      sendto_one_numeric(source, &me, ERR_NOTONCHANNEL, channel->name);
      return;
    }

    if (channel_has_mode(channel, MODE_TOPICLIMIT) && channel_member_get_highest_rank(member) < CHACCESS_HALFOP)
    {
      sendto_one_numeric(source, &me, ERR_CHANOPRIVSNEEDED, channel->name);
      return;
    }

    _topic_commit(source, channel, parv[2]);
    return;
  }

  /* Only asking for topic */
  if (channel_is_secret(channel) && channel_member_find(source, channel) == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOTONCHANNEL, channel->name);
    return;
  }

  _topic_send_current(source, channel);
}

/*! \brief TOPIC command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 *      - parv[2] = topic text (can be an empty string)
 */
static void
ms_topic(struct Client *source, int parc, char *parv[])
{
  struct Channel *const channel = channel_find(parv[1]);
  if (channel == NULL)
    return;

  _topic_commit(source, channel, parv[2]);
}

static struct Command command_table =
{
  .name = "TOPIC",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_topic, .args_min = 2, .end_grace_period = true },
  .handlers[SERVER_HANDLER] = { .handler = ms_topic, .args_min = 3, .empty_last_arg = true },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_topic, .args_min = 2, .end_grace_period = true }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
