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

/*! \file m_kick.c
 * \brief Includes required functions for processing the KICK command.
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "conf.h"
#include "io_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "module.h"
#include "parse.h"
#include "hash.h"

static const char *
_kick_get_reason(const struct Client *source, const char *reason)
{
  return string_default(reason, source->name);
}

static void
_kick_send_local(struct Client *source, const struct Channel *channel,
                 const struct Client *target, const char *reason)
{
  if (IsClient(source))
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s!%s@%s KICK %s %s :%.*s",
                         source->name, source->username, source->host,
                         channel->name, target->name, ConfigChannel.max_kick_length, reason);
  else
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s KICK %s %s :%.*s",
                         client_is_hidden(source) || ConfigServerHide.hide_servers ? me.name : source->name,
                         channel->name, target->name, ConfigChannel.max_kick_length, reason);
}

static void
_kick_commit(struct Client *source, struct Channel *channel,
             struct Client *target, struct ChannelMember *member_target, const char *reason)
{
  sendto_servers(source, 0, 0, ":%s KICK %s %s :%.*s",
                 source->id, channel->name, target->id, ConfigChannel.max_kick_length, reason);

  _kick_send_local(source, channel, target, reason);

  channel_remove_member(member_target);
}


/*! \brief KICK command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 *      - parv[2] = client to kick
 *      - parv[3] = reason
 */
static void
m_kick(struct Client *source, int parc, char *parv[])
{
  struct Channel *channel = hash_find_channel(parv[1]);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, parv[1]);
    return;
  }

  struct ChannelMember *member_source = member_find_link(source, channel);
  if (member_source == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOTONCHANNEL, channel->name);
    return;
  }

  if (member_highest_rank(member_source) < CHACCESS_HALFOP)
  {
    sendto_one_numeric(source, &me, ERR_CHANOPRIVSNEEDED, channel->name);
    return;
  }

  struct Client *target = find_chasing(source, parv[2]);
  if (target == NULL)
    return;  /* find_chasing sends ERR_NOSUCHNICK */

  struct ChannelMember *member_target = member_find_link(target, channel);
  if (member_target == NULL)
  {
    sendto_one_numeric(source, &me, ERR_USERNOTINCHANNEL, target->name, channel->name);
    return;
  }

  if (member_highest_rank(member_source) < member_highest_rank(member_target))
  {
    sendto_one_numeric(source, &me, ERR_CHANOPRIVSNEEDED, channel->name);
    return;
  }

  if (channel_has_mode(channel, MODE_NOKICK))
  {
    sendto_one_numeric(source, &me, ERR_CANNOTKICK, channel->name, target->name);
    return;
  }

  const char *const reason = _kick_get_reason(source, parv[3]);
  _kick_commit(source, channel, target, member_target, reason);
}

/*! \brief KICK command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 *      - parv[2] = client to kick
 *      - parv[3] = reason
 */
static void
ms_kick(struct Client *source, int parc, char *parv[])
{
  struct Channel *channel = hash_find_channel(parv[1]);
  if (channel == NULL)
    return;

  struct Client *target = find_person(source, parv[2]);
  if (target == NULL)
    return;

  struct ChannelMember *member_target = member_find_link(target, channel);
  if (member_target == NULL)
    return;

  const char *const reason = _kick_get_reason(source, parv[3]);
  _kick_commit(source, channel, target, member_target, reason);
}

static struct Command command_table =
{
  .name = "KICK",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_kick, .args_min = 3, .end_grace_period = true },
  .handlers[SERVER_HANDLER] = { .handler = ms_kick, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_kick, .args_min = 3, .end_grace_period = true }
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
  .core = true
};
