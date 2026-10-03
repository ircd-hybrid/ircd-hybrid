/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file conf_deny.c
 * @brief D-line configuration and indexed lookup implementation.
 *
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "address.h"
#include "address_index.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"

#include "conf_deny.h"

enum conf_deny_lookup_mode
{
  CONF_DENY_LOOKUP_COVERING,
  CONF_DENY_LOOKUP_EXACT
};

struct conf_deny_registry
{
  list_t items;
  address_index_t *index;

#ifndef NDEBUG
  bool expire_callback_active;
#endif
};

struct conf_deny_find_context
{
  const struct conf_deny *match;
  uintmax_t now;
};

struct conf_deny_prefix_lookup_context
{
  struct conf_deny *match;
  unsigned int prefix_length;
  uintmax_t now;
  enum conf_deny_lookup_mode mode;
};

static struct conf_deny_registry conf_deny_registry;

static bool
_conf_deny_is_initialized(void)
{
  return conf_deny_registry.index != NULL;
}

static void
_conf_deny_assert_initialized(void)
{
  const bool initialized = _conf_deny_is_initialized();
  assert(initialized);

  assert((conf_deny_registry.items.head == NULL) ==
         (conf_deny_registry.items.tail == NULL));

#ifndef NDEBUG
  const size_t item_count = list_length(&conf_deny_registry.items);

  assert((conf_deny_registry.items.head == NULL) == (item_count == 0));
  assert(item_count == address_index_count(conf_deny_registry.index));
#endif
}

static void
_conf_deny_assert_mutation_allowed(void)
{
  _conf_deny_assert_initialized();

#ifndef NDEBUG
  assert(!conf_deny_registry.expire_callback_active);
#endif
}

static bool
_conf_deny_is_expired(const struct conf_deny *deny, uintmax_t now)
{
  assert(deny);

  return deny->expires_at != 0 && deny->expires_at <= now;
}

static bool
_conf_deny_is_active(const struct conf_deny *deny, uintmax_t now)
{
  return !_conf_deny_is_expired(deny, now);
}

static bool
_conf_deny_parse_prefix(const char *prefix, struct io_addr *network, unsigned int *prefix_length)
{
  assert(!string_is_empty(prefix));
  assert(network);
  assert(prefix_length);

  if (!address_parse_prefix(prefix, network, prefix_length))
    return false;

  const bool masked = address_mask(network, *prefix_length);
  assert(masked);
  return masked;
}

static bool
_conf_deny_origin_is_valid(enum conf_deny_origin origin)
{
  return origin == CONF_DENY_ORIGIN_CONFIG || origin == CONF_DENY_ORIGIN_DATABASE;
}

static bool
_conf_deny_spec_is_valid(const struct conf_deny_spec *spec)
{
  if (spec == NULL || string_is_empty(spec->prefix) || spec->reason == NULL ||
      !_conf_deny_origin_is_valid(spec->origin))
    return false;

  if (spec->expires_at != 0 && spec->expires_at <= spec->created_at)
    return false;

  return true;
}

static bool
_conf_deny_find_callback(const address_index_entry_t *entry, void *callback_ctx)
{
  assert(entry);
  assert(callback_ctx);

  struct conf_deny_find_context *const context = callback_ctx;
  const struct conf_deny *const deny = address_index_entry_get_data(entry);

  assert(deny);
  assert(deny->index_entry == entry);

  if (!_conf_deny_is_active(deny, context->now))
    return true;

  context->match = deny;
  return false;
}

static bool
_conf_deny_prefix_lookup_callback(const address_index_entry_t *entry, void *callback_ctx)
{
  assert(entry);
  assert(callback_ctx);

  struct conf_deny_prefix_lookup_context *const context = callback_ctx;
  struct conf_deny *const deny = address_index_entry_get_data(entry);

  assert(deny);
  assert(deny->index_entry == entry);

  if (context->mode == CONF_DENY_LOOKUP_COVERING &&
      !_conf_deny_is_active(deny, context->now))
    return true;

  struct io_addr entry_network;
  unsigned int entry_prefix_length;
  address_index_entry_get_prefix(entry, &entry_network, &entry_prefix_length);

  switch (context->mode)
  {
    case CONF_DENY_LOOKUP_COVERING:
      if (entry_prefix_length > context->prefix_length)
        return true;
      break;
    case CONF_DENY_LOOKUP_EXACT:
      if (entry_prefix_length != context->prefix_length)
        return true;
      break;
    default:
      assert(false);
      return false;
  }

  context->match = deny;
  return false;
}

static struct conf_deny *
_conf_deny_find_prefix(const struct io_addr *network, unsigned int prefix_length,
                       enum conf_deny_lookup_mode mode)
{
  assert(network);

  struct conf_deny_prefix_lookup_context context =
  {
    .prefix_length = prefix_length,
    .now = mode == CONF_DENY_LOOKUP_COVERING ? io_time_get(IO_TIME_REALTIME_SEC) : 0,
    .mode = mode
  };

  const bool completed =
    address_index_foreach_match(conf_deny_registry.index, network,
                                _conf_deny_prefix_lookup_callback, &context);
  assert(completed == (context.match == NULL));

  return context.match;
}

static void
_conf_deny_destroy(struct conf_deny *deny)
{
  assert(deny);
  _conf_deny_assert_initialized();
  assert(deny->node.data == deny);
  assert(deny->reason);
  assert(_conf_deny_origin_is_valid(deny->origin));
  assert(deny->index_entry);

  void *const data = address_index_remove(deny->index_entry);
  assert(data == deny);

  list_remove(&deny->node, &conf_deny_registry.items);

  io_free(deny->reason);
  io_free(deny);

  _conf_deny_assert_initialized();
}

void
conf_deny_init(void)
{
  assert(conf_deny_registry.index == NULL);
  assert(conf_deny_registry.items.head == NULL);
  assert(conf_deny_registry.items.tail == NULL);

#ifndef NDEBUG
  assert(!conf_deny_registry.expire_callback_active);
#endif

  conf_deny_registry.index = address_index_create();

  assert(conf_deny_registry.index);
  _conf_deny_assert_initialized();
}

struct conf_deny *
conf_deny_add(const struct conf_deny_spec *spec)
{
  _conf_deny_assert_mutation_allowed();

  if (!_conf_deny_spec_is_valid(spec))
    return NULL;

  struct io_addr network;
  unsigned int prefix_length;
  if (!_conf_deny_parse_prefix(spec->prefix, &network, &prefix_length))
    return NULL;

  struct conf_deny *const deny = io_calloc(sizeof(*deny));
  deny->reason = io_strdup(spec->reason);
  deny->created_at = spec->created_at;
  deny->expires_at = spec->expires_at;
  deny->origin = spec->origin;
  deny->index_entry = address_index_add(conf_deny_registry.index, &network, prefix_length, deny);

  if (deny->index_entry == NULL)
  {
    io_free(deny->reason);
    io_free(deny);
    return NULL;
  }

  list_add_tail(deny, &deny->node, &conf_deny_registry.items);

  _conf_deny_assert_initialized();
  return deny;
}

void
conf_deny_delete(struct conf_deny *deny)
{
  assert(deny);
  _conf_deny_assert_mutation_allowed();
  _conf_deny_destroy(deny);
}

bool
conf_deny_format_prefix(const struct conf_deny *deny, char *buffer, size_t buffer_size)
{
  _conf_deny_assert_initialized();
  assert(deny);
  assert(buffer);
  assert(buffer_size > 0);

  if (deny == NULL || buffer == NULL || buffer_size == 0)
    return false;

  assert(deny->index_entry);

  struct io_addr network;
  unsigned int prefix_length;
  address_index_entry_get_prefix(deny->index_entry, &network, &prefix_length);

  return address_prefix_to_string(&network, prefix_length, buffer, buffer_size);
}

const struct conf_deny *
conf_deny_find(const struct io_addr *address)
{
  _conf_deny_assert_initialized();
  assert(address);

  if (address == NULL)
    return NULL;

  struct conf_deny_find_context context =
  {
    .now = io_time_get(IO_TIME_REALTIME_SEC)
  };

  const bool completed =
    address_index_foreach_match(conf_deny_registry.index, address,
                                _conf_deny_find_callback, &context);
  assert(completed == (context.match == NULL));

  return context.match;
}

bool
conf_deny_matches(const struct conf_deny *deny, const struct io_addr *address)
{
  _conf_deny_assert_initialized();
  assert(deny);
  assert(address);

  if (deny == NULL || address == NULL)
    return false;

  const uintmax_t now = io_time_get(IO_TIME_REALTIME_SEC);
  if (!_conf_deny_is_active(deny, now))
    return false;

  assert(deny->index_entry);

  struct io_addr network;
  unsigned int prefix_length;
  address_index_entry_get_prefix(deny->index_entry, &network, &prefix_length);

  return address_match_prefix(address, &network, prefix_length);
}

const struct conf_deny *
conf_deny_find_covering(const char *prefix)
{
  _conf_deny_assert_initialized();
  assert(!string_is_empty(prefix));

  if (string_is_empty(prefix))
    return NULL;

  struct io_addr network;
  unsigned int prefix_length;
  if (!_conf_deny_parse_prefix(prefix, &network, &prefix_length))
    return NULL;

  return _conf_deny_find_prefix(&network, prefix_length, CONF_DENY_LOOKUP_COVERING);
}

struct conf_deny *
conf_deny_find_exact(const char *prefix)
{
  _conf_deny_assert_initialized();
  assert(!string_is_empty(prefix));

  if (string_is_empty(prefix))
    return NULL;

  struct io_addr network;
  unsigned int prefix_length;
  if (!_conf_deny_parse_prefix(prefix, &network, &prefix_length))
    return NULL;

  return _conf_deny_find_prefix(&network, prefix_length, CONF_DENY_LOOKUP_EXACT);
}

const list_t *
conf_deny_get_list(void)
{
  _conf_deny_assert_initialized();
  return &conf_deny_registry.items;
}

void
conf_deny_expire(uintmax_t now, conf_deny_expire_callback_fn callback, void *callback_ctx)
{
  _conf_deny_assert_mutation_allowed();

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, conf_deny_registry.items.head)
  {
    struct conf_deny *const deny = node->data;
    assert(deny);
    assert(&deny->node == node);

    if (!_conf_deny_is_expired(deny, now))
      continue;

    if (callback)
    {
#ifndef NDEBUG
      assert(!conf_deny_registry.expire_callback_active);
      conf_deny_registry.expire_callback_active = true;
#endif

      callback(deny, callback_ctx);

#ifndef NDEBUG
      assert(conf_deny_registry.expire_callback_active);
      conf_deny_registry.expire_callback_active = false;
#endif
    }

    _conf_deny_destroy(deny);
  }
}

void
conf_deny_clear_configuration(void)
{
  _conf_deny_assert_mutation_allowed();

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, conf_deny_registry.items.head)
  {
    struct conf_deny *const deny = node->data;
    assert(deny);
    assert(&deny->node == node);

    assert(_conf_deny_origin_is_valid(deny->origin));

    if (deny->origin == CONF_DENY_ORIGIN_CONFIG)
      _conf_deny_destroy(deny);
  }
}

