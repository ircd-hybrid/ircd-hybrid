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
struct Invite
{
  list_node_t user_node;  /**< link to client->connection->invited */
  list_node_t chan_node;  /**< link to channel->invites */
  struct Channel *channel;  /**< Channel pointer */
  struct Client *client;  /**< Client pointer */
  uintmax_t when;  /**< Time the invite has been created; monotonic time */
};

extern void invite_add(struct Channel *, struct Client *);
extern void invite_del(struct Invite *);
extern void invite_clear_list(list_t *);
extern struct Invite *invite_find(struct Channel *, struct Client *);
#endif  /* INCLUDED_channel_invite_h */
