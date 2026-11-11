/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>

#include "list.h"
#include "memory.h"

#include "channel.h"
#include "channel_member.h"
#include "channel_mode.h"
#include "client.h"

enum channel_member_status_format
{
  MEMBER_STATUS_FORMAT_HIGHEST_PREFIX,
  MEMBER_STATUS_FORMAT_ALL_PREFIXES,
  MEMBER_STATUS_FORMAT_MODE_LETTERS
};

struct ChannelMember *
channel_member_add(struct Channel *channel, struct Client *client, uint32_t flags)
{
  struct ChannelMember *const member = io_calloc(sizeof(*member));
  member->client = client;
  member->channel = channel;
  member->flags = flags;
  list_add(member, &member->channel_node, &channel->member_list);

  if (client_is_local(client))
    list_add(member, &member->local_channel_node, &channel->local_member_list);

  list_add(member, &member->client_node, &client->channel_member_list);
  return member;
}

void
channel_member_remove(struct ChannelMember *member)
{
  struct Client *const client = member->client;
  struct Channel *const channel = member->channel;

  list_remove(&member->channel_node, &channel->member_list);

  if (client_is_local(client))
    list_remove(&member->local_channel_node, &channel->local_member_list);

  list_remove(&member->client_node, &client->channel_member_list);

  io_free(member);

  if (channel_is_empty(channel))
    channel_destroy(channel);
}

void
channel_member_remove_list(list_t *list)
{
  struct ChannelMember *member;

  while ((member = list_peek_head(list)))
    channel_member_remove(member);
}

int
channel_member_prefix_to_rank(char prefix)
{
  for (const struct chan_mode *status_mode = cflag_tab; status_mode->letter; ++status_mode)
    if (status_mode->prefix == prefix)
      return status_mode->rank;
  return CHACCESS_PEON;
}

char
channel_member_rank_to_prefix(int rank)
{
  for (const struct chan_mode *status_mode = cflag_tab; status_mode->letter; ++status_mode)
    if (status_mode->rank == rank)
      return status_mode->prefix;

  return '\0';
}

uint32_t
channel_member_prefix_to_flag(char prefix)
{
  for (const struct chan_mode *status_mode = cflag_tab; status_mode->letter; ++status_mode)
    if (status_mode->prefix == prefix)
      return status_mode->flag;
  return 0;
}

static bool
_channel_member_format_statuses(const struct ChannelMember *member, enum channel_member_status_format format,
                                char *buffer, size_t capacity)
{
  assert(member);
  assert(buffer || capacity == 0);

  if (capacity == 0)
    return false;

  size_t length = 0;
  buffer[0] = '\0';

  for (const struct chan_mode *status_mode = cflag_tab; status_mode->letter; ++status_mode)
  {
    if (channel_member_has_flags(member, status_mode->flag))
    {
      if (length == capacity - 1)
      {
        buffer[0] = '\0';
        return false;
      }

      buffer[length++] = format == MEMBER_STATUS_FORMAT_MODE_LETTERS ? status_mode->letter : status_mode->prefix;

      if (format == MEMBER_STATUS_FORMAT_HIGHEST_PREFIX)
        break;
    }
  }

  buffer[length] = '\0';
  return true;
}

bool
channel_member_format_prefix(const struct ChannelMember *member, bool multi_prefix, char *buffer, size_t capacity)
{
  const enum channel_member_status_format format =
    multi_prefix ? MEMBER_STATUS_FORMAT_ALL_PREFIXES : MEMBER_STATUS_FORMAT_HIGHEST_PREFIX;
  return _channel_member_format_statuses(member, format, buffer, capacity);
}

bool
channel_member_format_status_modes(const struct ChannelMember *member, char *buffer, size_t capacity)
{
  return _channel_member_format_statuses(member, MEMBER_STATUS_FORMAT_MODE_LETTERS, buffer, capacity);
}

int
channel_member_get_highest_rank(const struct ChannelMember *member)
{
  if (member == NULL)
    return CHACCESS_NOTONCHAN;

  int highest_rank = CHACCESS_PEON;

  for (const struct chan_mode *status_mode = cflag_tab; status_mode->letter; ++status_mode)
    if (status_mode->rank > highest_rank && channel_member_has_flags(member, status_mode->flag))
      highest_rank = status_mode->rank;

  return highest_rank;
}

struct ChannelMember *
channel_member_find(const struct Channel *channel, const struct Client *client)
{
  if (!client_is_user(client))
    return NULL;

  const list_t *channel_list = &channel->member_list;
  if (client_is_local(client))
    channel_list = &channel->local_member_list;

  if (list_length(channel_list) < list_length(&client->channel_member_list))
  {
    list_node_t *node;
    LIST_FOREACH(node, channel_list->head)
    {
      struct ChannelMember *const member = node->data;
      if (member->client == client)
        return member;
    }
  }
  else
  {
    list_node_t *node;
    LIST_FOREACH(node, client->channel_member_list.head)
    {
      struct ChannelMember *const member = node->data;
      if (member->channel == channel)
        return member;
    }
  }

  return NULL;
}
