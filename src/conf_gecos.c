/*
 * SPDX-FileCopyrightText: 1998-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"

#include "conf_gecos.h"

enum conf_gecos_lookup_mode
{
  CONF_GECOS_LOOKUP_MATCH,
  CONF_GECOS_LOOKUP_EXACT,
  CONF_GECOS_LOOKUP_ACTIVE_EXACT
};

static list_t conf_gecos_items;

#ifndef NDEBUG
static bool conf_gecos_expire_callback_active;
#endif

static void
_conf_gecos_assert_mutation_allowed(void)
{
#ifndef NDEBUG
  assert(!conf_gecos_expire_callback_active);
#endif
}

static bool
_conf_gecos_is_expired(const struct conf_gecos *gecos, uintmax_t now)
{
  return gecos->expires_at != 0 && gecos->expires_at <= now;
}

static bool
_conf_gecos_spec_is_valid(const struct conf_gecos_spec *spec)
{
  if (spec == NULL || string_is_empty(spec->mask) || spec->reason == NULL ||
      (spec->origin != CONF_GECOS_ORIGIN_CONFIG && spec->origin != CONF_GECOS_ORIGIN_DATABASE))
    return false;

  return spec->expires_at == 0 || spec->expires_at > spec->created_at;
}

static struct conf_gecos *
_conf_gecos_lookup(const char *name, enum conf_gecos_lookup_mode mode)
{
  /* An empty real name is a valid value for wildcard matching. */
  if (name == NULL)
    return NULL;

  const bool exact = mode != CONF_GECOS_LOOKUP_MATCH;
  const bool active = mode != CONF_GECOS_LOOKUP_EXACT;
  const uintmax_t now = active ? io_time_get(IO_TIME_REALTIME_SEC) : 0;

  list_node_t *node;
  LIST_FOREACH(node, conf_gecos_items.head)
  {
    struct conf_gecos *const gecos = node->data;
    if (active && _conf_gecos_is_expired(gecos, now))
      continue;

    if ((exact ? io_strcasecmp(gecos->mask, name) : match(gecos->mask, name)) == 0)
      return gecos;
  }

  return NULL;
}

static void
_conf_gecos_destroy(struct conf_gecos *gecos)
{
  list_remove(&gecos->node, &conf_gecos_items);
  io_free(gecos->mask);
  io_free(gecos->reason);
  io_free(gecos);
}

const list_t *
conf_gecos_get_list(void)
{
  return &conf_gecos_items;
}

const struct conf_gecos *
conf_gecos_add(const struct conf_gecos_spec *spec)
{
  _conf_gecos_assert_mutation_allowed();

  if (!_conf_gecos_spec_is_valid(spec))
    return NULL;

  struct conf_gecos *const gecos = io_calloc(sizeof(*gecos));
  gecos->mask = io_strdup(spec->mask);
  gecos->reason = io_strdup(spec->reason);
  gecos->created_at = spec->created_at;
  gecos->expires_at = spec->expires_at;
  gecos->origin = spec->origin;
  list_add_tail(gecos, &gecos->node, &conf_gecos_items);

  return gecos;
}

const struct conf_gecos *
conf_gecos_find(const char *name)
{
  return _conf_gecos_lookup(name, CONF_GECOS_LOOKUP_MATCH);
}

const struct conf_gecos *
conf_gecos_find_exact(const char *mask)
{
  return _conf_gecos_lookup(mask, CONF_GECOS_LOOKUP_EXACT);
}

const struct conf_gecos *
conf_gecos_find_active_exact(const char *mask)
{
  return _conf_gecos_lookup(mask, CONF_GECOS_LOOKUP_ACTIVE_EXACT);
}

bool
conf_gecos_remove_active_exact(const char *mask)
{
  _conf_gecos_assert_mutation_allowed();

  struct conf_gecos *const gecos = _conf_gecos_lookup(mask, CONF_GECOS_LOOKUP_ACTIVE_EXACT);
  if (gecos == NULL)
    return false;

  _conf_gecos_destroy(gecos);
  return true;
}

void
conf_gecos_clear_configuration(void)
{
  _conf_gecos_assert_mutation_allowed();

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, conf_gecos_items.head)
  {
    struct conf_gecos *const gecos = node->data;
    if (gecos->origin == CONF_GECOS_ORIGIN_CONFIG)
      _conf_gecos_destroy(gecos);
  }
}

void
conf_gecos_expire(uintmax_t now, conf_gecos_expire_callback_fn callback, void *callback_ctx)
{
  _conf_gecos_assert_mutation_allowed();

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, conf_gecos_items.head)
  {
    struct conf_gecos *const gecos = node->data;
    if (!_conf_gecos_is_expired(gecos, now))
      continue;

    if (callback)
    {
#ifndef NDEBUG
      assert(!conf_gecos_expire_callback_active);
      conf_gecos_expire_callback_active = true;
#endif
      callback(gecos, callback_ctx);
#ifndef NDEBUG
      assert(conf_gecos_expire_callback_active);
      conf_gecos_expire_callback_active = false;
#endif
    }

    _conf_gecos_destroy(gecos);
  }
}
