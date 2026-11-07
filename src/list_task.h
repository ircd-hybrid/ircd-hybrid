/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_list_task_h
#define INCLUDED_list_task_h
#include <stdbool.h>
#include <stdint.h>

#include "list.h"

struct Client;

/**
 * @struct ListTask
 * @brief Holds the filtering criteria and execution state for a /LIST request.
 */
struct ListTask
{
  struct Client *client;  /**< Back-pointer to the client who owns this task. */
  list_node_t node;  /**< Node for membership in the global listing queue. */

  list_t include_masks;  /**< Channels to show, as exact names or wildcard masks. */
  list_t exclude_masks;  /**< Channels to hide, as exact names or wildcard masks. */

  char *topic;  /**< Topic wildcard string to match, or NULL if no topic filter is active. */
  uintmax_t creation_time_min;  /**< Minimum channel creation time, as real time seconds. */
  uintmax_t creation_time_max;  /**< Maximum channel creation time, as real time seconds. */
  uintmax_t topic_time_min;  /**< Minimum topic set time, as real time seconds. */
  uintmax_t topic_time_max;  /**< Maximum topic set time, as real time seconds. */

  unsigned int hash_index;  /**< Current hash bucket for background iteration. */
  unsigned int users_min;  /**< Minimum users required in the channel. */
  unsigned int users_max;  /**< Maximum users allowed in the channel. */

  bool has_creation_time_filter;  /**< True if C< or C> was specified. */
  bool has_topic_time_filter;  /**< True if T< or T> was specified. */
  bool exact_match;  /**< True if include masks contain only exact channel names. */
  bool is_queued;  /**< True if linked in the background LIST task queue. */
};

extern void list_task_destroy(struct ListTask *);
extern void list_task_start(struct ListTask *);
extern struct ListTask *list_task_create(struct Client *);
#endif  /* INCLUDED_list_task_h */
