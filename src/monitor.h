/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997 Jukka Santala (Donwulff)
 *  Copyright (c) 2005-2024 ircd-hybrid development team
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

/*! \file monitor.h
 * \brief Header including structures and prototypes for MONITOR support
 */

#ifndef INCLUDED_monitor_h
#define INCLUDED_monitor_h

/** Monitor structure */
struct Monitor
{
  list_node_t node;  /**< List node; linked into monitor_hash */
  list_t monitored_by;  /**< List of clients that have this entry on their monitor list */
  char *name;  /**< Name of the client to monitor */
  unsigned int hash_value;  /**< Cached hash value derived from Monitor::name */
};

extern void monitor_signon(const struct Client *);
extern void monitor_signoff(const struct Client *);
extern void monitor_del_from_hash_table(const char *, struct Client *);
extern void monitor_clear_list(struct Client *);
extern void monitor_count_memory(unsigned int *const, size_t *const);
extern bool monitor_add_to_hash_table(const char *, struct Client *);
#endif  /* INCLUDED_monitor_h */
