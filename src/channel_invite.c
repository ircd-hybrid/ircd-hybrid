/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file channel_invite.c
 * \brief Channel invitation related functions
 */

#include <assert.h>
#include <stddef.h>

#include "io_time.h"
#include "list.h"
#include "memory.h"

#include "channel.h"
#include "channel_invite.h"
#include "client.h"
#include "conf.h"

static bool
_channel_invite_is_expired(const struct ChannelInvite *invite, uintmax_t now)
{
  return ConfigChannel.invite_expire_time && now >= invite->when &&
         now - invite->when > ConfigChannel.invite_expire_time;
}

static struct ChannelInvite *
_channel_invite_find(const struct Channel *channel, const struct Client *client, uintmax_t now)
{
  const list_t *const client_list = &client->connection->channel_invite_list;
  const list_t *const channel_list = &channel->invite_list;
  const list_t *const list = list_length(client_list) <= list_length(channel_list) ? client_list : channel_list;

  const list_node_t *node;
  LIST_FOREACH(node, list->head)
  {
    struct ChannelInvite *const invite = node->data;
    if (invite->channel == channel && invite->client == client && !_channel_invite_is_expired(invite, now))
      return invite;
  }

  return NULL;
}

static void
_channel_invite_remove(struct ChannelInvite *invite)
{
  list_remove(&invite->client_node, &invite->client->connection->channel_invite_list);
  list_remove(&invite->channel_node, &invite->channel->invite_list);
  io_free(invite);
}

const struct ChannelInvite *
channel_invite_find(const struct Channel *channel, const struct Client *client)
{
  assert(channel);
  assert(client_is_local_user(client));
  return _channel_invite_find(channel, client, io_time_get(IO_TIME_MONOTONIC_SEC));
}

bool
channel_invite_consume(struct Channel *channel, struct Client *client)
{
  assert(channel);
  assert(client_is_local_user(client));

  struct ChannelInvite *const invite = _channel_invite_find(channel, client, io_time_get(IO_TIME_MONOTONIC_SEC));
  if (invite == NULL)
    return false;

  _channel_invite_remove(invite);
  return true;
}

void
channel_invite_expire_client(struct Client *client, uintmax_t now)
{
  assert(client_is_local_user(client));

  if (ConfigChannel.invite_expire_time == 0)
    return;

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, client->connection->channel_invite_list.head)
  {
    struct ChannelInvite *const invite = node->data;
    if (_channel_invite_is_expired(invite, now))
      _channel_invite_remove(invite);
  }
}

void
channel_invite_add(struct Channel *channel, struct Client *client)
{
  assert(channel);
  assert(client_is_local_user(client));

  const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);
  channel_invite_expire_client(client, now);

  struct ChannelInvite *const existing = _channel_invite_find(channel, client, now);
  if (existing)
    _channel_invite_remove(existing);

  /* Evict the oldest invitations before adding the newest one. */
  list_t *const client_list = &client->connection->channel_invite_list;
  while (!list_is_empty(client_list) && list_length(client_list) >= ConfigChannel.max_invites)
    _channel_invite_remove(list_peek_tail(client_list));

  struct ChannelInvite *const invite = io_calloc(sizeof(*invite));
  invite->client = client;
  invite->channel = channel;
  invite->when = now;

  list_add(invite, &invite->channel_node, &channel->invite_list);
  list_add(invite, &invite->client_node, &client->connection->channel_invite_list);
}

static void
_channel_invite_clear_list(list_t *list)
{
  while (list->head)
    _channel_invite_remove(list->head->data);
}

void
channel_invite_clear_client(struct Client *client)
{
  assert(client_is_local_user(client));
  _channel_invite_clear_list(&client->connection->channel_invite_list);
}

void
channel_invite_clear_channel(struct Channel *channel)
{
  assert(channel);
  _channel_invite_clear_list(&channel->invite_list);
}
