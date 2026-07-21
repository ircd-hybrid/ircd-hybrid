/*
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_usermode.c
 * \brief Implements usermode based extended channel bans.
 */

#include <stddef.h>
#include <stdint.h>

#include "channel_mode.h"
#include "client.h"
#include "extban.h"
#include "user_mode.h"

static enum extban_match
extban_usermode_matches(struct Client *client, struct Channel *channel, struct Ban *ban)
{
  user_mode_action_t action = USER_MODE_ACTION_ADD;
  uint64_t modes_del = 0, modes_add = 0;

  for (const char *m = ban->host; *m; ++m)
  {
    switch (*m)
    {
      case '+':
        action = USER_MODE_ACTION_ADD;
        continue;
      case '-':
        action = USER_MODE_ACTION_DEL;
        continue;
      default:
      {
        const struct UserMode *mode = user_mode_find(*m);
        if (mode == NULL)
          continue;

        if (action == USER_MODE_ACTION_ADD)
          modes_add |= mode->mode_bit;
        else
          modes_del |= mode->mode_bit;
      }
    }
  }


  if ((client->user_mode_flags & modes_add) == modes_add &&
      (client->user_mode_flags & modes_del) == 0)
    return EXTBAN_MATCH;

  return EXTBAN_NO_MATCH;
}

struct Extban extban_usermode =
{
  .character = 'u',
  .type = EXTBAN_MATCHING,
  .types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX,
  .matches = extban_usermode_matches
};
