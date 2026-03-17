/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

#ifndef INCLUDED_links_cache_h
#define INCLUDED_links_cache_h

#include <stdint.h>
#include "list.h"

typedef struct
{
  uintmax_t generated_at_unix;
  unsigned int network_users_total;
} links_cache_metadata_t;

typedef struct
{
  char *name;
  char *uplink_name;
  char *description;
  unsigned int user_count;
  list_node_t node;
} links_cache_entry_t;

extern void links_cache_init(void);
extern void links_cache_set_timer(uintmax_t);
extern const list_t *links_cache_get(void);
extern const links_cache_metadata_t *links_cache_get_metadata(void);
#endif  /* INCLUDED_links_cache_h */
