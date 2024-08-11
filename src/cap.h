/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2024-2024 ircd-hybrid development team
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

#ifndef INCLUDED_cap_h
#define INCLUDED_cap_h
#include "list.h"

struct Cap
{
  char *name;
  char *value;
  unsigned int flag;
  size_t name_len;
  size_t value_len;
  list_node_t node;
};

extern void cap_register(unsigned int, const char *, const char *);
extern void cap_unregister(const char *);
extern struct Cap *cap_find(const char *);
extern const list_t *cap_get_list(void);
#endif  /* INCLUDED_cap_h */
