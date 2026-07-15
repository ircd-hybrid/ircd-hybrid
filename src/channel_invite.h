/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file channel_invite.h
 * \brief Channel invitation related functions
 */

#ifndef INCLUDED_channel_invite_h
#define INCLUDED_channel_invite_h
#include <stdint.h>

#include "list.h"

/** Invite structure */
struct ChannelInvite
{
  list_node_t client_node;  /**< link to client->connection->channel_invite_list */
  list_node_t channel_node;  /**< link to channel->invite_list */
  struct Channel *channel;  /**< Channel pointer */
  struct Client *client;  /**< Client pointer */
  uintmax_t when;  /**< Time the invite has been created; monotonic time */
};

extern void channel_invite_add(struct Channel *, struct Client *);
extern void channel_invite_remove(struct ChannelInvite *);
extern void channel_invite_remove_all(list_t *);
extern struct ChannelInvite *channel_invite_find(struct Channel *, struct Client *);
#endif  /* INCLUDED_channel_invite_h */
