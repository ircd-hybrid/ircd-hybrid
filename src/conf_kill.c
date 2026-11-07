/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file conf_kill.c
 * @brief K-line configuration and indexed lookup implementation.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "address.h"
#include "address_index.h"
#include "hostmask_index.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"

#include "conf_kill.h"

enum conf_kill_lookup_mode
{
  CONF_KILL_LOOKUP_COVERING,
  CONF_KILL_LOOKUP_EXACT
};

struct conf_kill_registry
{
  list_t items;
  address_index_t *address_index;
  hostmask_index_t *hostmask_index;

#ifndef NDEBUG
  bool expire_callback_active;
#endif
};

struct conf_kill_find_context
{
  const char *username;
  const struct conf_kill *match;
  uintmax_t now;
};

struct conf_kill_address_lookup_context
{
  const char *user;
  struct conf_kill *match;
  unsigned int prefix_length;
  uintmax_t now;
  enum conf_kill_lookup_mode mode;
};

static struct conf_kill_registry conf_kill_registry;

static bool
_conf_kill_is_initialized(void)
{
  assert((conf_kill_registry.address_index == NULL) ==
         (conf_kill_registry.hostmask_index == NULL));

  return conf_kill_registry.address_index != NULL;
}

static void
_conf_kill_assert_initialized(void)
{
  const bool initialized = _conf_kill_is_initialized();
  assert(initialized);

  assert((conf_kill_registry.items.head == NULL) ==
         (conf_kill_registry.items.tail == NULL));

#ifndef NDEBUG
  const size_t item_count = list_length(&conf_kill_registry.items);

  assert((conf_kill_registry.items.head == NULL) == (item_count == 0));
  assert(item_count ==
         address_index_count(conf_kill_registry.address_index) +
         hostmask_index_count(conf_kill_registry.hostmask_index));
#endif
}

static void
_conf_kill_assert_mutation_allowed(void)
{
  _conf_kill_assert_initialized();

#ifndef NDEBUG
  assert(!conf_kill_registry.expire_callback_active);
#endif
}

static bool
_conf_kill_is_expired(const struct conf_kill *kill, uintmax_t now)
{
  assert(kill);

  return kill->expires_at != 0 && kill->expires_at <= now;
}

static bool
_conf_kill_is_active(const struct conf_kill *kill, uintmax_t now)
{
  return !_conf_kill_is_expired(kill, now);
}

static bool
_conf_kill_matches_username(const struct conf_kill *kill, const char *username)
{
  assert(kill);
  assert(!string_is_empty(kill->user));
  assert(!string_is_empty(username));

  return match(kill->user, username) == 0;
}

static bool
_conf_kill_parse_address_selector(const char *host, struct io_addr *network, unsigned int *prefix_length)
{
  assert(!string_is_empty(host));
  assert(network);
  assert(prefix_length);

  if (!address_parse_prefix(host, network, prefix_length))
    return false;

  const bool masked = address_mask(network, *prefix_length);
  assert(masked);

  return masked;
}

static bool
_conf_kill_origin_is_valid(enum conf_kill_origin origin)
{
  return origin == CONF_KILL_ORIGIN_CONFIG || origin == CONF_KILL_ORIGIN_DATABASE;
}

static bool
_conf_kill_spec_is_valid(const struct conf_kill_spec *spec)
{
  if (spec == NULL || string_is_empty(spec->user) ||
      string_is_empty(spec->host) || spec->reason == NULL ||
      !_conf_kill_origin_is_valid(spec->origin))
    return false;

  if (spec->expires_at != 0 && spec->expires_at <= spec->created_at)
    return false;

  return true;
}

static bool
_conf_kill_index_add(struct conf_kill *kill, const char *host)
{
  assert(kill);
  assert(!string_is_empty(host));

  struct io_addr network;
  unsigned int prefix_length;

  if (_conf_kill_parse_address_selector(host, &network, &prefix_length))
  {
    kill->selector_type = CONF_KILL_SELECTOR_ADDRESS;
    kill->index_entry.address =
      address_index_add(conf_kill_registry.address_index, &network, prefix_length, kill);

    return kill->index_entry.address != NULL;
  }

  kill->selector_type = CONF_KILL_SELECTOR_HOSTMASK;
  kill->index_entry.hostmask = hostmask_index_add(conf_kill_registry.hostmask_index, host, kill);

  return kill->index_entry.hostmask != NULL;
}

static void
_conf_kill_index_remove(struct conf_kill *kill)
{
  assert(kill);

  void *data;

  switch (kill->selector_type)
  {
    case CONF_KILL_SELECTOR_ADDRESS:
      assert(kill->index_entry.address);
      data = address_index_remove(kill->index_entry.address);
      break;
    case CONF_KILL_SELECTOR_HOSTMASK:
      assert(kill->index_entry.hostmask);
      data = hostmask_index_remove(kill->index_entry.hostmask);
      break;
    default:
      assert(false);
      return;
  }

  assert(data == kill);
  (void)data;
}

static bool
_conf_kill_find_address_callback(const address_index_entry_t *entry, void *callback_ctx)
{
  assert(entry);
  assert(callback_ctx);

  struct conf_kill_find_context *const context = callback_ctx;
  const struct conf_kill *const kill = address_index_entry_get_data(entry);

  assert(kill);
  assert(kill->selector_type == CONF_KILL_SELECTOR_ADDRESS);
  assert(kill->index_entry.address == entry);

  if (!_conf_kill_is_active(kill, context->now) ||
      !_conf_kill_matches_username(kill, context->username))
    return true;

  context->match = kill;
  return false;
}

static bool
_conf_kill_find_hostmask_callback(const hostmask_index_entry_t *entry, void *callback_ctx)
{
  assert(entry);
  assert(callback_ctx);

  struct conf_kill_find_context *const context = callback_ctx;
  const struct conf_kill *const kill = hostmask_index_entry_get_data(entry);

  assert(kill);
  assert(kill->selector_type == CONF_KILL_SELECTOR_HOSTMASK);
  assert(kill->index_entry.hostmask == entry);

  if (!_conf_kill_is_active(kill, context->now) ||
      !_conf_kill_matches_username(kill, context->username))
    return true;

  context->match = kill;
  return false;
}

static bool
_conf_kill_address_lookup_callback(const address_index_entry_t *entry, void *callback_ctx)
{
  assert(entry);
  assert(callback_ctx);

  struct conf_kill_address_lookup_context *const context = callback_ctx;
  struct conf_kill *const kill = address_index_entry_get_data(entry);

  assert(kill);
  assert(kill->selector_type == CONF_KILL_SELECTOR_ADDRESS);
  assert(kill->index_entry.address == entry);

  if (context->mode == CONF_KILL_LOOKUP_COVERING &&
      !_conf_kill_is_active(kill, context->now))
    return true;

  if (io_strcasecmp(kill->user, context->user))
    return true;

  struct io_addr entry_network;
  unsigned int entry_prefix_length;
  address_index_entry_get_prefix(entry, &entry_network, &entry_prefix_length);

  switch (context->mode)
  {
    case CONF_KILL_LOOKUP_COVERING:
      if (entry_prefix_length > context->prefix_length)
        return true;
      break;
    case CONF_KILL_LOOKUP_EXACT:
      if (entry_prefix_length != context->prefix_length)
        return true;
      break;
    default:
      assert(false);
      return false;
  }

  context->match = kill;
  return false;
}

static struct conf_kill *
_conf_kill_find_address_selector(const char *user, const struct io_addr *network,
                                 unsigned int prefix_length, enum conf_kill_lookup_mode mode)
{
  assert(!string_is_empty(user));
  assert(network);

  struct conf_kill_address_lookup_context context =
  {
    .user = user,
    .prefix_length = prefix_length,
    .now = mode == CONF_KILL_LOOKUP_COVERING ? io_time_get(IO_TIME_REALTIME_SEC) : 0,
    .mode = mode
  };

  const bool completed =
    address_index_foreach_match(conf_kill_registry.address_index, network,
                                _conf_kill_address_lookup_callback, &context);
  assert(completed == (context.match == NULL));

  return context.match;
}

static struct conf_kill *
_conf_kill_find_hostmask_selector(const char *user, const char *host, enum conf_kill_lookup_mode mode)
{
  assert(!string_is_empty(user));
  assert(!string_is_empty(host));

  const uintmax_t now = mode == CONF_KILL_LOOKUP_COVERING ? io_time_get(IO_TIME_REALTIME_SEC) : 0;

  list_node_t *node;
  LIST_FOREACH(node, conf_kill_registry.items.head)
  {
    struct conf_kill *const kill = node->data;
    assert(kill);
    assert(&kill->node == node);

    if (kill->selector_type != CONF_KILL_SELECTOR_HOSTMASK)
      continue;

    if (mode == CONF_KILL_LOOKUP_COVERING && !_conf_kill_is_active(kill, now))
      continue;

    assert(kill->index_entry.hostmask);

    const char *const mask = hostmask_index_entry_get_mask(kill->index_entry.hostmask);
    assert(!string_is_empty(mask));

    if (io_strcasecmp(kill->user, user) || io_strcasecmp(mask, host))
      continue;

    return kill;
  }

  return NULL;
}

static void
_conf_kill_destroy(struct conf_kill *kill)
{
  assert(kill);
  _conf_kill_assert_initialized();
  assert(kill->node.data == kill);
  assert(!string_is_empty(kill->user));
  assert(kill->reason);
  assert(_conf_kill_origin_is_valid(kill->origin));

  _conf_kill_index_remove(kill);
  list_remove(&kill->node, &conf_kill_registry.items);

  io_free(kill->user);
  io_free(kill->reason);
  io_free(kill);

  _conf_kill_assert_initialized();
}

void
conf_kill_init(void)
{
  assert(conf_kill_registry.address_index == NULL);
  assert(conf_kill_registry.hostmask_index == NULL);
  assert(conf_kill_registry.items.head == NULL);
  assert(conf_kill_registry.items.tail == NULL);

#ifndef NDEBUG
  assert(!conf_kill_registry.expire_callback_active);
#endif

  conf_kill_registry.address_index = address_index_create();
  conf_kill_registry.hostmask_index = hostmask_index_create();

  assert(conf_kill_registry.address_index);
  assert(conf_kill_registry.hostmask_index);
  _conf_kill_assert_initialized();
}

struct conf_kill *
conf_kill_add(const struct conf_kill_spec *spec)
{
  _conf_kill_assert_mutation_allowed();

  if (!_conf_kill_spec_is_valid(spec))
    return NULL;

  struct conf_kill *const kill = io_calloc(sizeof(*kill));
  kill->user = io_strdup(spec->user);
  kill->reason = io_strdup(spec->reason);
  kill->created_at = spec->created_at;
  kill->expires_at = spec->expires_at;
  kill->origin = spec->origin;

  if (!_conf_kill_index_add(kill, spec->host))
    goto fail;

  list_add_tail(kill, &kill->node, &conf_kill_registry.items);

  _conf_kill_assert_initialized();
  return kill;

fail:
  io_free(kill->user);
  io_free(kill->reason);
  io_free(kill);
  return NULL;
}

void
conf_kill_delete(struct conf_kill *kill)
{
  assert(kill);
  _conf_kill_assert_mutation_allowed();
  _conf_kill_destroy(kill);
}

bool
conf_kill_format_host(const struct conf_kill *kill, char *buffer, size_t buffer_size)
{
  _conf_kill_assert_initialized();
  assert(kill);
  assert(buffer);
  assert(buffer_size > 0);

  if (kill == NULL || buffer == NULL || buffer_size == 0)
    return false;

  switch (kill->selector_type)
  {
    case CONF_KILL_SELECTOR_ADDRESS:
    {
      assert(kill->index_entry.address);

      struct io_addr network;
      unsigned int prefix_length;
      address_index_entry_get_prefix(kill->index_entry.address, &network, &prefix_length);

      return address_prefix_to_string(&network, prefix_length, buffer, buffer_size);
    }

    case CONF_KILL_SELECTOR_HOSTMASK:
    {
      assert(kill->index_entry.hostmask);

      const char *const mask = hostmask_index_entry_get_mask(kill->index_entry.hostmask);
      assert(!string_is_empty(mask));

      const size_t mask_length = strlen(mask);
      if (mask_length >= buffer_size)
        return false;

      memcpy(buffer, mask, mask_length + 1);
      return true;
    }
  }

  assert(false);
  return false;
}

const struct conf_kill *
conf_kill_find(const struct io_addr *address, const char *username, const char *hostname)
{
  _conf_kill_assert_initialized();
  assert(!string_is_empty(username));
  assert(address || !string_is_empty(hostname));

  if (string_is_empty(username) || (address == NULL && string_is_empty(hostname)))
    return NULL;

  struct conf_kill_find_context context =
  {
    .username = username,
    .now = io_time_get(IO_TIME_REALTIME_SEC)
  };

  if (address)
  {
    const bool completed =
      address_index_foreach_match(conf_kill_registry.address_index, address,
                                  _conf_kill_find_address_callback, &context);
    assert(completed == (context.match == NULL));

    if (context.match)
      return context.match;
  }

  if (!string_is_empty(hostname))
  {
    const bool completed =
      hostmask_index_foreach_match(conf_kill_registry.hostmask_index, hostname,
                                   _conf_kill_find_hostmask_callback, &context);
    assert(completed == (context.match == NULL));
  }

  return context.match;
}

bool
conf_kill_matches(const struct conf_kill *kill, const struct io_addr *address,
                  const char *username, const char *hostname)
{
  _conf_kill_assert_initialized();
  assert(kill);
  assert(!string_is_empty(username));
  assert(address || !string_is_empty(hostname));

  if (kill == NULL || string_is_empty(username) ||
      (address == NULL && string_is_empty(hostname)))
    return false;

  const uintmax_t now = io_time_get(IO_TIME_REALTIME_SEC);
  if (!_conf_kill_is_active(kill, now) || !_conf_kill_matches_username(kill, username))
    return false;

  switch (kill->selector_type)
  {
    case CONF_KILL_SELECTOR_ADDRESS:
    {
      if (address == NULL)
        return false;

      assert(kill->index_entry.address);

      struct io_addr network;
      unsigned int prefix_length;
      address_index_entry_get_prefix(kill->index_entry.address, &network, &prefix_length);

      return address_match_prefix(address, &network, prefix_length);
    }

    case CONF_KILL_SELECTOR_HOSTMASK:
    {
      if (string_is_empty(hostname))
        return false;

      assert(kill->index_entry.hostmask);

      const char *const mask = hostmask_index_entry_get_mask(kill->index_entry.hostmask);
      assert(!string_is_empty(mask));

      return match(mask, hostname) == 0;
    }
  }

  assert(false);
  return false;
}

const struct conf_kill *
conf_kill_find_covering(const char *user, const char *host)
{
  _conf_kill_assert_initialized();
  assert(!string_is_empty(user));
  assert(!string_is_empty(host));

  if (string_is_empty(user) || string_is_empty(host))
    return NULL;

  struct io_addr network;
  unsigned int prefix_length;

  if (_conf_kill_parse_address_selector(host, &network, &prefix_length))
    return _conf_kill_find_address_selector(user, &network, prefix_length, CONF_KILL_LOOKUP_COVERING);

  return _conf_kill_find_hostmask_selector(user, host, CONF_KILL_LOOKUP_COVERING);
}

struct conf_kill *
conf_kill_find_exact(const char *user, const char *host)
{
  _conf_kill_assert_initialized();
  assert(!string_is_empty(user));
  assert(!string_is_empty(host));

  if (string_is_empty(user) || string_is_empty(host))
    return NULL;

  struct io_addr network;
  unsigned int prefix_length;

  if (_conf_kill_parse_address_selector(host, &network, &prefix_length))
    return _conf_kill_find_address_selector(user, &network, prefix_length, CONF_KILL_LOOKUP_EXACT);

  return _conf_kill_find_hostmask_selector(user, host, CONF_KILL_LOOKUP_EXACT);
}

const list_t *
conf_kill_get_list(void)
{
  _conf_kill_assert_initialized();
  return &conf_kill_registry.items;
}

void
conf_kill_expire(uintmax_t now, conf_kill_expire_callback_fn callback, void *callback_ctx)
{
  _conf_kill_assert_mutation_allowed();

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, conf_kill_registry.items.head)
  {
    struct conf_kill *const kill = node->data;
    assert(kill);
    assert(&kill->node == node);

    if (!_conf_kill_is_expired(kill, now))
      continue;

    if (callback)
    {
#ifndef NDEBUG
      assert(!conf_kill_registry.expire_callback_active);
      conf_kill_registry.expire_callback_active = true;
#endif

      callback(kill, callback_ctx);

#ifndef NDEBUG
      assert(conf_kill_registry.expire_callback_active);
      conf_kill_registry.expire_callback_active = false;
#endif
    }

    _conf_kill_destroy(kill);
  }
}

void
conf_kill_clear_configuration(void)
{
  _conf_kill_assert_mutation_allowed();

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, conf_kill_registry.items.head)
  {
    struct conf_kill *const kill = node->data;
    assert(kill);
    assert(&kill->node == node);

    assert(_conf_kill_origin_is_valid(kill->origin));

    if (kill->origin == CONF_KILL_ORIGIN_CONFIG)
      _conf_kill_destroy(kill);
  }
}

