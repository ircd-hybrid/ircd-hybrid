/*
 * SPDX-FileCopyrightText: 1998-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file conf_gecos.c
 * \brief Implements gecos {} block configuration management.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "io_time.h"
#include "list.h"
#include "memory.h"

#include "conf_gecos.h"

static list_t gecos_list;

#ifndef NDEBUG
static bool gecos_expire_callback_active;
#endif

static void
_gecos_assert_mutation_allowed(void)
{
#ifndef NDEBUG
  assert(!gecos_expire_callback_active);
#endif
}

static bool
_gecos_is_expired(const struct GecosItem *gecos, uintmax_t now)
{
  assert(gecos);
  return gecos->expires_at != 0 && gecos->expires_at <= now;
}

const list_t *
gecos_get_list(void)
{
  return &gecos_list;
}

void
gecos_clear(void)
{
  _gecos_assert_mutation_allowed();

  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, gecos_list.head)
  {
    struct GecosItem *const gecos = node->data;
    if (gecos->in_database == false)
      gecos_delete(gecos);
  }
}

void
gecos_delete(struct GecosItem *gecos)
{
  assert(gecos);
  _gecos_assert_mutation_allowed();

  list_remove(&gecos->node, &gecos_list);
  io_free(gecos->mask);
  io_free(gecos->reason);
  io_free(gecos);
}

struct GecosItem *
gecos_make(void)
{
  _gecos_assert_mutation_allowed();

  struct GecosItem *const gecos = io_calloc(sizeof(*gecos));
  list_add_tail(gecos, &gecos->node, &gecos_list);

  return gecos;
}

struct GecosItem *
gecos_find(const char *name, int (*compare)(const char *, const char *))
{
  const uintmax_t now = io_time_get(IO_TIME_REALTIME_SEC);

  list_node_t *node;
  LIST_FOREACH(node, gecos_list.head)
  {
    struct GecosItem *const gecos = node->data;
    if (!_gecos_is_expired(gecos, now) && compare(gecos->mask, name) == 0)
      return gecos;
  }

  return NULL;
}

void
gecos_expire(uintmax_t now, gecos_expire_callback_fn callback, void *callback_ctx)
{
  _gecos_assert_mutation_allowed();

  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, gecos_list.head)
  {
    struct GecosItem *const gecos = node->data;
    if (!_gecos_is_expired(gecos, now))
      continue;

    if (callback)
    {
#ifndef NDEBUG
      assert(!gecos_expire_callback_active);
      gecos_expire_callback_active = true;
#endif

      callback(gecos, callback_ctx);

#ifndef NDEBUG
      assert(gecos_expire_callback_active);
      gecos_expire_callback_active = false;
#endif
    }

    gecos_delete(gecos);
  }
}
