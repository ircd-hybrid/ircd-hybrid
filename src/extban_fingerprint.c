/*
 * SPDX-FileCopyrightText: 2015-2016 plexus development team
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_fingerprint.c
 * \brief Implements TLS certificate fingerprint based extended channel bans.
 */

#include "io_string.h"

#include "channel_mode.h"
#include "client.h"
#include "extban.h"

static enum extban_match
extban_fingerprint_matches(struct Client *client, struct Channel *channel, struct Ban *ban)
{
  if (!string_is_empty(client->tls_certfp))
    if (match(ban->host, client->tls_certfp) == 0)
      return EXTBAN_MATCH;

  return EXTBAN_NO_MATCH;
}

struct Extban extban_fingerprint =
{
  .character = 'z',
  .type = EXTBAN_MATCHING,
  .types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX,
  .matches = extban_fingerprint_matches
};
