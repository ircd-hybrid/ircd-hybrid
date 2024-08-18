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
static struct Cap **cap_array;
static size_t cap_array_size;
static bool cap_array_stale;

const list_t *
cap_get_list(void)
{
  return &cap_list;
}

static int
cap_compare(const void *const a_, const void *const b_)
{
  const struct Cap *const a = *(const struct Cap *const *)a_;
  const struct Cap *const b = *(const struct Cap *const *)b_;
  return strcmp(a->name, b->name);
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
  cap_array_stale = true;
}

void
cap_unregister(const char *name)
{
  struct Cap *cap = cap_find(name);
  if (cap == NULL)
    return;

  list_remove(&cap->node, &cap_list);

  /* Temporarily disable the warning for casting away const qualifiers. */
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wcast-qual"
  /* Freeing memory allocated for const char pointers. */
  io_free((void *)cap->name);
  io_free((void *)cap->value);
  /* Re-enable the discarded qualifiers warning. */
  #pragma GCC diagnostic pop
  io_free(cap);

  cap_array_stale = true;
}

static void
cap_array_update(void)
{
  cap_array_stale = false;

  io_free(cap_array);
  cap_array = NULL;

  if (list_is_empty(&cap_list))
    return;

  cap_array = (struct Cap **)list_to_array(&cap_list);
  cap_array_size = list_length(&cap_list);

  qsort(cap_array, cap_array_size, sizeof(struct Cap *), cap_compare);
}

struct Cap *
cap_find(const char *name)
{
  if (cap_array_stale)
    cap_array_update();

  if (cap_array_size == 0)
    return NULL;

  const struct Cap key = { .name = name };
  const struct Cap *key_ptr = &key;
  struct Cap **cap = bsearch(&key_ptr, cap_array, cap_array_size, sizeof(struct Cap *), cap_compare);

  return cap ? *cap : NULL;
}
