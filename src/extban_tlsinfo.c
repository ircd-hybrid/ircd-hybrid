/*
 * SPDX-FileCopyrightText: 2020-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_tlsinfo.c
 * \brief Implements TLS version/cipher based extended channel bans.
 */

#include "io_string.h"

#include "channel_mode.h"
#include "client.h"
#include "extban.h"

static enum extban_match
extban_tlsinfo_matches(struct Client *client, struct Channel *channel, struct Ban *ban)
{
  if (!string_is_empty(client->tls_cipher))
    if (match(ban->host, client->tls_cipher) == 0)
      return EXTBAN_MATCH;

  return EXTBAN_NO_MATCH;
}

struct Extban extban_tlsinfo =
{
  .character = 't',
  .type = EXTBAN_MATCHING,
  .types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX,
  .matches = extban_tlsinfo_matches
};
