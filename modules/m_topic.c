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

/*! \file m_topic.c
 * \brief Includes required functions for processing the TOPIC command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "conf.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "module.h"


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
  struct Channel *channel = hash_find_channel(parv[1]);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, parv[1]);
    return;
  }

  /* Setting topic */
  if (parc > 2)
  {
    const struct ChannelMember *member = member_find_link(source, channel);
    if (member == NULL)
    {
      sendto_one_numeric(source, &me, ERR_NOTONCHANNEL, channel->name);
      return;
    }

    if (HasCMode(channel, MODE_TOPICLIMIT) && member_highest_rank(member) < CHACCESS_HALFOP)
    {
      sendto_one_numeric(source, &me, ERR_CHANOPRIVSNEEDED, channel->name);
      return;
    }

    char topic_info[NICKLEN + USERLEN + HOSTLEN + 3];  /* +3 for !, @, \0 */
    snprintf(topic_info, sizeof(topic_info), "%s!%s@%s",
             source->name, source->username, source->host);
    channel_set_topic(channel, parv[2], topic_info, io_time_get(IO_TIME_REALTIME_SEC), true);

    sendto_server(source, 0, 0, ":%s TOPIC %s :%s",
                  source->id, channel->name, channel->topic);
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s!%s@%s TOPIC %s :%s",
                         source->name, source->username, source->host, channel->name, channel->topic);
  }
  else  /* Only asking for topic */
  {
    if (HasCMode(channel, MODE_SECRET) && member_find_link(source, channel) == NULL)
    {
      sendto_one_numeric(source, &me, ERR_NOTONCHANNEL, channel->name);
      return;
    }

    if (channel->topic[0] == '\0')
      sendto_one_numeric(source, &me, RPL_NOTOPIC, channel->name);
    else
    {
      sendto_one_numeric(source, &me, RPL_TOPIC,
                         channel->name, channel->topic);
      sendto_one_numeric(source, &me, RPL_TOPICWHOTIME,
                         channel->name, channel->topic_info, channel->topic_time);
    }
  }
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
  struct Channel *channel = hash_find_channel(parv[1]);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, parv[1]);
    return;
  }

  char topic_info[NICKLEN + USERLEN + HOSTLEN + 3];  /* +3 for !, @, \0 */
  if (IsClient(source))
    snprintf(topic_info, sizeof(topic_info), "%s!%s@%s",
             source->name, source->username, source->host);
  else if (IsHidden(source) || ConfigServerHide.hide_servers)
    strlcpy(topic_info, me.name, sizeof(topic_info));
  else
    strlcpy(topic_info, source->name, sizeof(topic_info));

  channel_set_topic(channel, parv[2], topic_info, io_time_get(IO_TIME_REALTIME_SEC), false);

  sendto_server(source, 0, 0, ":%s TOPIC %s :%s",
                source->id, channel->name, channel->topic);

  if (IsClient(source))
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s!%s@%s TOPIC %s :%s",
                         source->name, source->username, source->host, channel->name, channel->topic);
  else
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s TOPIC %s :%s",
                         (IsHidden(source) || ConfigServerHide.hide_servers) ? me.name : source->name,
                         channel->name, channel->topic);
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
