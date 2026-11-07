/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_channel_member_h
#define INCLUDED_channel_member_h
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "list.h"

struct Channel;
struct Client;

struct ChannelMember
{
  list_node_t local_channel_node;  /**< link to channel->local_member_list */
  list_node_t channel_node;  /**< link to channel->member_list */
  list_node_t client_node;  /**< link to client->channel_member_list */
  struct Channel *channel;  /**< Channel pointer */
  struct Client *client;  /**< Client pointer */
  uint32_t flags;  /**< user/channel flags, e.g. CHFL_CHANOP */
};

extern void channel_member_remove(struct ChannelMember *);
extern void channel_member_remove_list(list_t *);
extern int channel_member_get_highest_rank(const struct ChannelMember *);
extern int channel_member_prefix_to_rank(char);
extern uint32_t channel_member_prefix_to_flag(char);
extern size_t channel_member_get_prefix_length(const struct ChannelMember *, bool);
extern struct ChannelMember *channel_member_add(struct Channel *, struct Client *, uint32_t);
extern struct ChannelMember *channel_member_find(const struct Channel *, const struct Client *);
extern const char *channel_member_get_prefix(const struct ChannelMember *, bool);
extern const char *channel_member_rank_to_prefix(int);

static inline bool
channel_member_has_flags(const struct ChannelMember *member, uint32_t flags)
{
  return (member->flags & flags) != 0;
}

static inline void
channel_member_set_flags(struct ChannelMember *member, uint32_t flags)
{
  member->flags |= flags;
}

static inline void
channel_member_unset_flags(struct ChannelMember *member, uint32_t flags)
{
  member->flags &= ~flags;
}
#endif  /* INCLUDED_channel_member_h */
