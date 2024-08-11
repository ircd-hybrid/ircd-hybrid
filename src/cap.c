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

#include "stdinc.h"
#include "list.h"
#include "memory.h"
#include "cap.h"

static list_t cap_list;

const list_t *
cap_get_list(void)
{
  return &cap_list;
}

void
cap_register(unsigned int flag, const char *name, const char *value)
{
  if (cap_find(name))
    return;

  struct Cap *cap = io_calloc(sizeof(*cap));
  cap->flag = flag;
  cap->name = strdup(name);
  cap->name_len = strlen(name);

  if (value)
  {
    cap->value = strdup(value);
    cap->value_len = strlen(value);
  }

  list_add(cap, &cap->node, &cap_list);
}

void
cap_unregister(const char *name)
{
  struct Cap *cap = cap_find(name);
  if (cap == NULL)
    return;

  list_remove(&cap->node, &cap_list);
  io_free(cap->name);
  io_free(cap->value);
  io_free(cap);
}

struct Cap *
cap_find(const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, cap_list.head)
  {
    struct Cap *cap = node->data;
    if (strcmp(cap->name, name) == 0)
      return cap;
  }

  return NULL;
}
