/*
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_channel.c
 * \brief Implements channel name based extended channel bans.
 */

#include <stdbool.h>
#include <stddef.h>

#include "module.h"

#include "channel.h"
#include "channel_member.h"
#include "channel_mode.h"
#include "client.h"
#include "extban.h"
#include "ircd_module.h"

static bool
_extban_channel_matches(const struct Client *client, const struct Channel *channel, const struct Ban *ban)
{
  const char *channel_name = ban->extban_parameter;

  const int required_rank = channel_member_prefix_to_rank(*channel_name);
  if (required_rank != CHACCESS_PEON)
    ++channel_name;

  const struct Channel *const referenced_channel = channel_find(channel_name);
  if (referenced_channel == NULL)
    return false;

  /*
   * If the channel in question is either +s, or +p, only allow a match against
   * the source channel to prevent channel probing.
   */
  if (!channel_is_public(referenced_channel) && referenced_channel != channel)
    return false;

  const struct ChannelMember *const member = channel_member_find(referenced_channel, client);
  return member && required_rank <= channel_member_get_highest_rank(member);
}

static const struct Extban extban_channel =
{
  .letter = 'c',
  .kind = EXTBAN_KIND_MATCHING,
  .list_types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX,
  .matches = _extban_channel_matches
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  return ircd_module_register_extban(&extban_channel, error_message, error_message_size);
}

static void
exit_handler(void *context)
{
  extban_unregister(&extban_channel);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "extban_channel",
  .flags = MODULE_FLAG_NO_REMOVE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
