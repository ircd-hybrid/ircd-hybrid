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
  for (const struct chan_mode *tab = cflag_tab; tab->prefix; ++tab)
    if (tab->prefix == prefix)
      return tab->rank;
  return CHACCESS_PEON;
}

const char *
channel_member_rank_to_prefix(int rank)
{
  for (const struct chan_mode *tab = cflag_tab; tab->prefix; ++tab)
  {
    if (tab->rank == rank)
    {
      static char prefix[2];
      prefix[0] = tab->prefix;
      prefix[1] = '\0';  /* Just for safety */

      return prefix;
    }
  }

  return "";
}

uint32_t
channel_member_prefix_to_flag(char prefix)
{
  for (const struct chan_mode *tab = cflag_tab; tab->prefix; ++tab)
    if (tab->prefix == prefix)
      return tab->flag;
  return 0;
}

const char *
channel_member_get_prefix(const struct ChannelMember *member, bool combine)
{
  static char buf[CMEMBER_STATUS_FLAGS_LEN + 1];  /* +1 for \0 */
  char *bufptr = buf;

  for (const struct chan_mode *tab = cflag_tab; tab->letter; ++tab)
  {
    if (channel_member_has_flags(member, tab->flag))
    {
      *bufptr++ = tab->prefix;

      if (!combine)
        break;
    }
  }

  *bufptr = '\0';
  return buf;
}

size_t
channel_member_get_prefix_length(const struct ChannelMember *member, bool combine)
{
  size_t len = 0;

  for (const struct chan_mode *tab = cflag_tab; tab->letter; ++tab)
  {
    if (channel_member_has_flags(member, tab->flag))
    {
      ++len;

      if (!combine)
        break;
    }
  }

  return len;
}

int
channel_member_get_highest_rank(const struct ChannelMember *member)
{
  if (member == NULL)
    return CHACCESS_NOTONCHAN;

  if (channel_member_has_flags(member, CHFL_CHANOWNER))
    return CHACCESS_OWNER;

  if (channel_member_has_flags(member, CHFL_CHANADMIN))
    return CHACCESS_ADMIN;

  if (channel_member_has_flags(member, CHFL_CHANOP))
    return CHACCESS_OP;

  if (channel_member_has_flags(member, CHFL_HALFOP))
    return CHACCESS_HALFOP;

  if (channel_member_has_flags(member, CHFL_VOICE))
    return CHACCESS_VOICE;

  return CHACCESS_PEON;
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
