/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file channel_invite.c
 * \brief Channel invitation related functions
 */

#include <stddef.h>

#include "io_time.h"
#include "list.h"
#include "memory.h"

#include "channel.h"
#include "channel_invite.h"
#include "client.h"
#include "conf.h"

/*! \brief Checks whether a client is invited to a certain channel. While walking the
 *         shortest invitation list, expired invitations are vaccumed automatically.
 * \param channel Pointer to channel block
 * \param client  Pointer to client
 * \return A struct Invite pointer or NULL
 */
struct Invite *
invite_find(struct Channel *channel, struct Client *client)
{
  list_t *const list = list_get_shorter(&client->connection->invite_list, &channel->invites);

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, list->head)
  {
    struct Invite *const invite = node->data;
    if (ConfigChannel.invite_expire_time &&
        ConfigChannel.invite_expire_time + invite->when < io_time_get(IO_TIME_MONOTONIC_SEC))
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

  invite = io_calloc(sizeof(*invite));
  invite->client = client;
  invite->channel = channel;
  invite->when = io_time_get(IO_TIME_MONOTONIC_SEC);

  /* Delete last link in chain if the list is max length */
  while (list_length(&client->connection->invite_list) &&
         list_length(&client->connection->invite_list) >= ConfigChannel.max_invites)
    invite_del(list_peek_tail(&client->connection->invite_list));

  /* Add client to channel invite list */
  list_add(invite, &invite->chan_node, &channel->invites);

  /* Add channel to the end of the client invite list */
  list_add(invite, &invite->user_node, &client->connection->invite_list);
}

/*! \brief Delete Invite block from channel invite list
 *         and client invite list
 * \param invite Pointer to Invite struct
 */
void
invite_del(struct Invite *invite)
{
  list_remove(&invite->user_node, &invite->client->connection->invite_list);
  list_remove(&invite->chan_node, &invite->channel->invites);
  io_free(invite);
}

/*! \brief Removes and frees all Invite blocks from a list
 * \param list Pointer to a list_t
 */
void
invite_clear_list(list_t *list)
{
  while (list->head)
    invite_del(list->head->data);
}
