/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2019-2020 ircd-hybrid development team
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

/*! \file extban_join.c
 * \brief Implements join restriction extended channel bans.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "irc_string.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "extban.h"
#include "numeric.h"


int
extban_join_can_join(struct Channel *channel, struct Client *client,
                     struct ChannelMember *member)
{
  assert(member == NULL);

  /* Search for matching joinban */
  if (find_bmask(client, channel, &channel->banlist, &extban_join) == true)
    /* Clients who match +e j: override +b j: */
    if (find_bmask(client, channel, &channel->exceptlist, &extban_join) == false)
      return ERR_BANNEDFROMCHAN;

  return 0;
}

struct Extban extban_join =
{
  .character = 'j',
  .type = EXTBAN_ACTING,
  .types = CHFL_BAN | CHFL_EXCEPTION
};
