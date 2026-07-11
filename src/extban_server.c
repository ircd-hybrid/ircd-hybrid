/*
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_server.c
 * \brief Implements server name based extended channel bans.
 */

#include "io_string.h"
#include "list.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "extban.h"

static enum extban_match
extban_server_matches(struct Client *client, struct Channel *channel, struct Ban *ban)
{
  if (match(ban->host, me.name) == 0)
    return EXTBAN_MATCH;

  return EXTBAN_NO_MATCH;
}

struct Extban extban_server =
{
  .character = 's',
  .type = EXTBAN_MATCHING,
  .types = CHFL_BAN | CHFL_INVEX,
  .matches = extban_server_matches
};
