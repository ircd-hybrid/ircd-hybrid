/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file ipcache.h
 * \brief Routines to count connections from particular IP addresses.
 */

#ifndef INCLUDED_ipcache_h
#define INCLUDED_ipcache_h

struct ip_entry
{
  list_node_t node;  /**< List node; linked into ipcache_list */
  void *trie_pointer;  /**< Pointer to 'patricia_tree_t' item */
  unsigned int count_local;  /**< Number of local users using this IP */
  unsigned int count_remote;  /**< Number of remote users using this IP */
  unsigned int connection_count;  /**< Number of connections from this IP in the last throttle_time duration */
  uintmax_t last_attempt;  /**< The last time someone connected from this IP; monotonic time */
};

extern struct ip_entry *ipcache_record_find_or_add(void *);
extern void ipcache_record_remove(void *, bool);
extern void ipcache_get_stats(unsigned int *const, size_t *const);
extern void ipcache_init(void);
#endif  /* INCLUDED_ipcache_h */
