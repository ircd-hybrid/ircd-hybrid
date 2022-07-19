/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2019-2022 ircd-hybrid development team
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

/*! \file extban_operclass.c
 * \brief Implements oper class based extended channel bans.
 */

#include "stdinc.h"
#include "list.h"
#include "irc_string.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "conf_class.h"
#include "extban.h"


static enum extban_match
extban_operclass_matches(struct Client *client, struct Channel *channel, struct Ban *ban)
{
  if (MyConnect(client) && HasUMode(client, UMODE_OPER))
    if (match(ban->host, class_get_name(&client->connection->confs)) == 0)
      return EXTBAN_MATCH;

  return EXTBAN_NO_MATCH;
}

struct Extban extban_operclass =
{
  .character = 'o',
  .type = EXTBAN_MATCHING,
  .types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX,
  .matches = extban_operclass_matches
};
