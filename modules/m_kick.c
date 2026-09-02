/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_kick.c
 * \brief Includes required functions for processing the KICK command.
 */

#include <assert.h>
#include <stddef.h>

#include "io_string.h"
#include "module.h"

#include "channel.h"
#include "channel_member.h"
#include "channel_mode.h"
#include "client.h"
#include "client_find.h"
#include "conf.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

static const char *
_kick_get_reason(const struct Client *source, const char *reason)
{
  if (!string_is_empty(reason))
    return reason;

  if (client_is_user(source))
    return source->name;

  return client_get_visible_server_name(source);
}

static void
_kick_notify_channel_members(struct Client *source, const struct Channel *channel,
                             const struct Client *target, const char *reason)
{
  if (client_is_user(source))
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s!%s@%s KICK %s %s :%.*s",
                         source->name, source->username, source->host,
                         channel->name, target->name, ConfigChannel.max_kick_length, reason);
  else
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s KICK %s %s :%.*s",
                         client_get_visible_server_name(source),
                         channel->name, target->name, ConfigChannel.max_kick_length, reason);
}

static void
_kick_commit(struct Client *source, struct Channel *channel,
             struct Client *target, struct ChannelMember *member_target, const char *reason)
{
  sendto_servers(source, 0, 0, ":%s KICK %s %s :%.*s",
                 source->id, channel->name, target->id, ConfigChannel.max_kick_length, reason);

  _kick_notify_channel_members(source, channel, target, reason);

  channel_member_remove(member_target);
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
m_kick(struct Client *source, size_t parc, char *parv[])
{
  const char *const channel_name = parv[1];

  struct Channel *const channel = channel_find(channel_name);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, channel_name);
    return;
  }

  struct ChannelMember *const member_source = channel_member_find(channel, source);
  if (member_source == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOTONCHANNEL, channel->name);
    return;
  }

  if (channel_member_get_highest_rank(member_source) < CHACCESS_HALFOP)
  {
    sendto_one_numeric(source, &me, ERR_CHANOPRIVSNEEDED, channel->name);
    return;
  }

  const char *const target_name = parv[2];
  struct Client *const target = client_find_user_with_history(source, target_name, NULL);
  if (target == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHNICK, target_name);
    return;
  }

  struct ChannelMember *const member_target = channel_member_find(channel, target);
  if (member_target == NULL)
  {
    sendto_one_numeric(source, &me, ERR_USERNOTINCHANNEL, target->name, channel->name);
    return;
  }

  if (channel_member_get_highest_rank(member_source) <
      channel_member_get_highest_rank(member_target))
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
ms_kick(struct Client *source, size_t parc, char *parv[])
{
  struct Channel *const channel = channel_find(parv[1]);
  if (channel == NULL)
    return;

  struct Client *const target = client_find_user(source, parv[2]);
  if (target == NULL)
    return;

  struct ChannelMember *const member_target = channel_member_find(channel, target);
  if (member_target == NULL)
    return;

  const char *const reason = _kick_get_reason(source, parv[3]);
  _kick_commit(source, channel, target, member_target, reason);
}

static struct Command command_table =
{
  .name = "KICK",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_kick, .args_min = 3, .end_grace_period = true },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_kick, .args_min = 3 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_kick, .args_min = 3, .end_grace_period = true }
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
