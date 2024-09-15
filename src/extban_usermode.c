/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2019-2024 ircd-hybrid development team
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

/*! \file extban_usermode.c
 * \brief Implements usermode based extended channel bans.
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
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
        break;
      case '-':
        action = USER_MODE_ACTION_DEL;
        break;
      default:
      {
        const struct UserMode *mode = user_mode_find(*m);
        if (mode)
        {
          switch (action)
          {
            case USER_MODE_ACTION_ADD:
              modes_add |= mode->mode_bit;
              break;
            case USER_MODE_ACTION_DEL:
              modes_del |= mode->mode_bit;
              break;
          }
        }
      }
    }
  }


  if ((client->umodes & modes_add) == modes_add &&
      (client->umodes & modes_del) == 0)
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
