/*
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_channel.c
 * \brief Implements channel name based extended channel bans.
 */

#include <stddef.h>

#include "list.h"

#include "channel.h"
#include "channel_member.h"
#include "channel_mode.h"
#include "client.h"
#include "extban.h"

static enum extban_match
extban_channel_matches(struct Client *client, struct Channel *channel, struct Ban *ban)
{
  const char *name = ban->host;

  const int rank = channel_member_prefix_to_rank(*name);
  if (rank != CHACCESS_PEON)
    ++name;

  const struct Channel *const tmp = channel_find(name);
  if (tmp == NULL)
    return EXTBAN_NO_MATCH;

  /*
   * If the channel in question is either +s, or +p, only allow a match against
   * the source channel to prevent channel probing.
   */
  if (!channel_is_public(tmp) && tmp != channel)
    return EXTBAN_NO_MATCH;

  const struct ChannelMember *const member = channel_member_find(tmp, client);
  if (member)
  {
    if (rank > channel_member_get_highest_rank(member))
      return EXTBAN_NO_MATCH;
    return EXTBAN_MATCH;
  }

  return EXTBAN_NO_MATCH;
}

struct Extban extban_channel =
{
  .character = 'c',
  .type = EXTBAN_MATCHING,
  .types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX,
  .matches = extban_channel_matches
};
