/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file ipcache.h
 * \brief Routines to count connections from particular IP addresses.
 */

#ifndef INCLUDED_ipcache_h
#define INCLUDED_ipcache_h
#include <stdbool.h>
#include <stdint.h>

#include "list.h"
#include "patricia.h"

struct ip_entry
{
  list_node_t node;  /**< List node; linked into ipcache_list */
  patricia_tree_t *trie_pointer;  /**< Pointer to 'patricia_tree_t' item */
  unsigned int count_local;  /**< Number of local users using this IP */
  unsigned int count_remote;  /**< Number of remote users using this IP */
  unsigned int connection_count;  /**< Number of connections from this IP in the last throttle_time duration */
  uintmax_t last_attempt;  /**< The last time someone connected from this IP; monotonic time */
};

extern void ipcache_record_remove(const void *, bool);
extern void ipcache_get_stats(uint32_t *const, size_t *const);
extern void ipcache_init(void);
extern struct ip_entry *ipcache_record_find_or_add(const void *);
#endif  /* INCLUDED_ipcache_h */
