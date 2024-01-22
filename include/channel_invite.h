/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*! \file channel_invite.h
 * \brief Channel invitation related functions
 */

#ifndef INCLUDED_channel_invite_h
#define INCLUDED_channel_invite_h

/** Invite structure */
struct Invite
{
  dlink_node user_node;  /**< link to client->connection->invited */
  dlink_node chan_node;  /**< link to channel->invites */
  struct Channel *channel;  /**< Channel pointer */
  struct Client *client;  /**< Client pointer */
  uintmax_t when;  /**< Time the invite has been created; monotonic time */
};

extern struct Invite *invite_find(struct Channel *, struct Client *);
extern void invite_add(struct Channel *, struct Client *);
extern void invite_del(struct Invite *);
extern void invite_clear_list(dlink_list *);
#endif  /* INCLUDED_channel_invite_h */
