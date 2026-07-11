/*
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_operclass.c
 * \brief Implements oper class based extended channel bans.
 */

#include "io_string.h"
#include "list.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "conf_class.h"
#include "extban.h"
#include "user_mode.h"

static enum extban_match
extban_operclass_matches(struct Client *client, struct Channel *channel, struct Ban *ban)
{
  if (client_is_local(client) && client_is_oper(client))
  {
    const char *class_name = client_get_class_name(client);
    if (match(ban->host, class_name) == 0)
      return EXTBAN_MATCH;
  }

  return EXTBAN_NO_MATCH;
}

struct Extban extban_operclass =
{
  .character = 'o',
  .type = EXTBAN_MATCHING,
  .types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX,
  .matches = extban_operclass_matches
};
