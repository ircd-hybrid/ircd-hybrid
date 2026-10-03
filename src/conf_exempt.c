/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file conf_exempt.c
 * @brief D-line address-exemption configuration and indexed lookup.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "address.h"
#include "address_index.h"
#include "io_string.h"
#include "list.h"
#include "memory.h"

#include "conf_exempt.h"

struct conf_exempt
{
  list_node_t node;
  address_index_entry_t *index_entry;
};

struct conf_exempt_registry
{
  list_t items;
  address_index_t *index;
};

struct conf_exempt_find_context
{
  const struct conf_exempt *match;
};

static struct conf_exempt_registry conf_exempt_registry;

static bool
_conf_exempt_is_initialized(void)
{
  return conf_exempt_registry.index != NULL;
}

static void
_conf_exempt_assert_initialized(void)
{
  const bool initialized = _conf_exempt_is_initialized();
  assert(initialized);

  assert((conf_exempt_registry.items.head == NULL) ==
         (conf_exempt_registry.items.tail == NULL));

#ifndef NDEBUG
  const size_t item_count = list_length(&conf_exempt_registry.items);

  assert((conf_exempt_registry.items.head == NULL) == (item_count == 0));
  assert(item_count == address_index_count(conf_exempt_registry.index));
#endif
}

static bool
_conf_exempt_parse_prefix(const char *prefix, struct io_addr *network, unsigned int *prefix_length)
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
_conf_exempt_find_callback(const address_index_entry_t *entry, void *callback_ctx)
{
  assert(entry);
  assert(callback_ctx);

  struct conf_exempt_find_context *const context = callback_ctx;
  const struct conf_exempt *const exempt = address_index_entry_get_data(entry);

  assert(exempt);
  assert(exempt->index_entry == entry);
  assert(context->match == NULL);

  context->match = exempt;
  return false;
}

static void
_conf_exempt_destroy(struct conf_exempt *exempt)
{
  assert(exempt);
  _conf_exempt_assert_initialized();
  assert(exempt->node.data == exempt);
  assert(exempt->index_entry);

  void *const data = address_index_remove(exempt->index_entry);
  assert(data == exempt);

  list_remove(&exempt->node, &conf_exempt_registry.items);
  io_free(exempt);

  _conf_exempt_assert_initialized();
}

void
conf_exempt_init(void)
{
  assert(!_conf_exempt_is_initialized());
  assert(conf_exempt_registry.items.head == NULL);
  assert(conf_exempt_registry.items.tail == NULL);

  conf_exempt_registry.index = address_index_create();

  assert(conf_exempt_registry.index);
  _conf_exempt_assert_initialized();
}

const struct conf_exempt *
conf_exempt_add(const char *prefix)
{
  _conf_exempt_assert_initialized();
  assert(!string_is_empty(prefix));

  if (string_is_empty(prefix))
    return NULL;

  struct io_addr network;
  unsigned int prefix_length;
  if (!_conf_exempt_parse_prefix(prefix, &network, &prefix_length))
    return NULL;

  struct conf_exempt *const exempt = io_calloc(sizeof(*exempt));
  exempt->index_entry = address_index_add(conf_exempt_registry.index, &network, prefix_length, exempt);

  if (exempt->index_entry == NULL)
  {
    io_free(exempt);
    return NULL;
  }

  list_add_tail(exempt, &exempt->node, &conf_exempt_registry.items);

  _conf_exempt_assert_initialized();
  return exempt;
}

bool
conf_exempt_format_prefix(const struct conf_exempt *exempt, char *buffer, size_t buffer_size)
{
  _conf_exempt_assert_initialized();
  assert(exempt);
  assert(buffer);
  assert(buffer_size > 0);

  if (exempt == NULL || buffer == NULL || buffer_size == 0)
    return false;

  assert(exempt->index_entry);

  struct io_addr network;
  unsigned int prefix_length;
  address_index_entry_get_prefix(exempt->index_entry, &network, &prefix_length);

  return address_prefix_to_string(&network, prefix_length, buffer, buffer_size);
}

const struct conf_exempt *
conf_exempt_find(const struct io_addr *address)
{
  _conf_exempt_assert_initialized();
  assert(address);

  if (address == NULL)
    return NULL;

  struct conf_exempt_find_context context = { 0 };

  const bool completed =
    address_index_foreach_match(conf_exempt_registry.index, address,
                                _conf_exempt_find_callback, &context);
  assert(completed == (context.match == NULL));

  return context.match;
}

const list_t *
conf_exempt_get_list(void)
{
  _conf_exempt_assert_initialized();
  return &conf_exempt_registry.items;
}

void
conf_exempt_clear(void)
{
  _conf_exempt_assert_initialized();

  while (conf_exempt_registry.items.head)
    _conf_exempt_destroy(conf_exempt_registry.items.head->data);

  _conf_exempt_assert_initialized();
}
