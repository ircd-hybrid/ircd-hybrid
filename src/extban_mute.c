/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015-2016 plexus development team
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

/*! \file extban_mute.c
 * \brief Implements message muting extended channel bans.
 * \version $Id: extban_mute.c 9223 2020-01-26 11:35:22Z michael $
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
extban_mute_can_send(struct Channel *channel, struct Client *client_p,
                     struct ChannelMember *member)
{
  if (!MyConnect(client_p))
    return CAN_SEND_NONOP;

  if (member)
  {
    if (member->flags & CHFL_BAN_SILENCED)
      return ERR_CANNOTSENDTOCHAN;

    if (member->flags & CHFL_MUTE_CHECKED)
      return CAN_SEND_NONOP;

    member->flags |= CHFL_MUTE_CHECKED;
  }

  /* Search for matching muteban */
  if (find_bmask(client_p, channel, &channel->banlist, &extban_mute) == true)
  {
    /* Clients who match +e m: override +b m: */
    if (find_bmask(client_p, channel, &channel->exceptlist, &extban_mute) == false)
    {
      if (member)
        member->flags |= CHFL_BAN_SILENCED;

      return ERR_CANNOTSENDTOCHAN;
    }
  }

  return CAN_SEND_NONOP;
}

struct Extban extban_mute =
{
  .character = 'm',
  .type = EXTBAN_ACTING,
  .types = CHFL_BAN | CHFL_EXCEPTION
};
