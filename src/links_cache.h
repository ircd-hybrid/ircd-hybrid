/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_links_cache_h
#define INCLUDED_links_cache_h

#include <stdint.h>
#include "list.h"

typedef struct
{
  uintmax_t generated_at_unix;
  uint32_t network_users_total;
} links_cache_metadata_t;

typedef struct
{
  char *name;
  char *uplink_name;
  char *description;
  uint32_t user_count;
  list_node_t node;
} links_cache_entry_t;

extern void links_cache_init(void);
extern void links_cache_set_timer(uintmax_t);
extern const list_t *links_cache_get(void);
extern const links_cache_metadata_t *links_cache_get_metadata(void);
#endif  /* INCLUDED_links_cache_h */
