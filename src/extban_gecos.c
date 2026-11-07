/*
 * SPDX-FileCopyrightText: 2015-2016 plexus development team
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_gecos.c
 * \brief Implements gecos (real name) based extended channel bans.
 */

#include <stddef.h>

#include "io_string.h"
#include "list.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "extban.h"

static enum extban_match
extban_gecos_matches(struct Client *client, struct Channel *channel, struct Ban *ban)
{
  if (match(ban->host, client->info) == 0)
    return EXTBAN_MATCH;

  return EXTBAN_NO_MATCH;
}

struct Extban extban_gecos =
{
  .character = 'r',
  .type = EXTBAN_MATCHING,
  .types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX,
  .matches = extban_gecos_matches
};
