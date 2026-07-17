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
 * \return A struct ChannelInvite pointer or NULL
 */
struct ChannelInvite *
channel_invite_find(struct Channel *channel, struct Client *client)
{
  list_t *const list = list_get_shorter(&client->connection->channel_invite_list, &channel->invite_list);

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, list->head)
  {
    struct ChannelInvite *const invite = node->data;
    if (ConfigChannel.invite_expire_time &&
        ConfigChannel.invite_expire_time + invite->when < io_time_get(IO_TIME_MONOTONIC_SEC))
      channel_invite_remove(invite);
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
channel_invite_add(struct Channel *channel, struct Client *client)
{
  struct ChannelInvite *invite = channel_invite_find(channel, client);
  if (invite)
    channel_invite_remove(invite);

  invite = io_calloc(sizeof(*invite));
  invite->client = client;
  invite->channel = channel;
  invite->when = io_time_get(IO_TIME_MONOTONIC_SEC);

  /* Delete last link in chain if the list is max length */
  while (list_length(&client->connection->channel_invite_list) &&
         list_length(&client->connection->channel_invite_list) >= ConfigChannel.max_invites)
    channel_invite_remove(list_peek_tail(&client->connection->channel_invite_list));

  /* Add client to channel invite list */
  list_add(invite, &invite->channel_node, &channel->invite_list);

  /* Add channel to the end of the client invite list */
  list_add(invite, &invite->client_node, &client->connection->channel_invite_list);
}

/*! \brief Delete Invite block from channel invite list
 *         and client invite list
 * \param invite Pointer to Invite struct
 */
void
channel_invite_remove(struct ChannelInvite *invite)
{
  list_remove(&invite->client_node, &invite->client->connection->channel_invite_list);
  list_remove(&invite->channel_node, &invite->channel->invite_list);
  io_free(invite);
}

/*! \brief Removes and frees all Invite blocks from a list
 * \param list Pointer to a list_t
 */
void
channel_invite_remove_all(list_t *list)
{
  while (list->head)
    channel_invite_remove(list->head->data);
}

bool
channel_invite_consume(struct Channel *channel, struct Client *client)
{
  assert(channel);
  assert(client_is_local_user(client));

  struct ChannelInvite *const invite = channel_invite_find(channel, client);
  if (invite == NULL)
    return false;

  channel_invite_remove(invite);
  return true;
}
