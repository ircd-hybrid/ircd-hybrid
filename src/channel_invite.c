/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2020 ircd-hybrid development team
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

/*! \file channel_invite.c
 * \brief Channel invitation related functions
 * \version $Id: channel_invite.c 9249 2020-02-01 13:35:32Z michael $
 */

#include "stdinc.h"
#include "memory.h"
#include "list.h"
#include "event.h"
#include "channel.h"
#include "channel_invite.h"
#include "conf.h"


struct Invite *
invite_find(struct Channel *channel, struct Client *client)
{
  dlink_node *node, *node_next;
  dlink_list *list;

  /* Take the shortest of the two lists */
  if (dlink_list_length(&client->connection->invited) < dlink_list_length(&channel->invites))
    list = &client->connection->invited;
  else
    list = &channel->invites;

  DLINK_FOREACH_SAFE(node, node_next, list->head)
  {
    struct Invite *invite = node->data;

    if (ConfigChannel.invite_expire_time &&
        ConfigChannel.invite_expire_time + invite->when < event_base->time.sec_monotonic)
      invite_del(invite);
    else if (invite->channel == channel && invite->client == client)
      return invite;
  }

  return NULL;
}

/*! \brief Adds client to invite list
 * \param channel Pointer to channel block
 * \param client  Pointer to client to add invite to
 */
void
invite_add(struct Channel *channel, struct Client *client)
{
  struct Invite *invite = invite_find(channel, client);
  if (invite)
    invite_del(invite);

  invite = xcalloc(sizeof(*invite));
  invite->client = client;
  invite->channel = channel;
  invite->when = event_base->time.sec_monotonic;

  /* Delete last link in chain if the list is max length */
  while (dlink_list_length(&client->connection->invited) &&
         dlink_list_length(&client->connection->invited) >= ConfigChannel.max_invites)
    invite_del(client->connection->invited.tail->data);

  /* Add client to channel invite list */
  dlinkAdd(invite, &invite->chan_node, &channel->invites);

  /* Add channel to the end of the client invite list */
  dlinkAdd(invite, &invite->user_node, &client->connection->invited);
}

/*! \brief Delete Invite block from channel invite list
 *         and client invite list
 * \param invite Pointer to Invite struct
 */
void
invite_del(struct Invite *invite)
{
  dlinkDelete(&invite->user_node, &invite->client->connection->invited);
  dlinkDelete(&invite->chan_node, &invite->channel->invites);

  /* Release memory pointed to by 'invite' */
  xfree(invite);
}

/*! \brief Removes and frees all Invite blocks from a list
 * \param list Pointer to a dlink_list
 */
void
invite_clear_list(dlink_list *list)
{
  while (list->head)
    invite_del(list->head->data);
}
