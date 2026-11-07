/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file address_index.c
 * @brief Indexed matching of IPv4 and IPv6 network prefixes.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

#include "address.h"
#include "memory.h"
#include "patricia.h"

#include "address_index.h"

struct address_index
{
  patricia_tree_t *ipv4;
  patricia_tree_t *ipv6;
  size_t count;
#ifndef NDEBUG
  size_t iteration_depth;
#endif
};

struct address_index_group
{
  struct address_index *index;
  patricia_node_t *node;
  struct address_index_entry *entries;
};

struct address_index_entry
{
  struct address_index_entry *next;
  struct address_index_entry **previous_link;

  struct address_index_group *group;
  void *data;
};

struct address_index_match_context
{
  const struct address_index *index;
  address_index_foreach_fn callback;
  void *callback_ctx;
};

static void
_address_index_assert_not_iterating(const struct address_index *index)
{
  assert(index);

#ifndef NDEBUG
  assert(index->iteration_depth == 0);
#else
  (void)index;
#endif
}

static patricia_tree_t *
_address_index_tree(struct address_index *index, int family)
{
  assert(index);

  switch (family)
  {
    case AF_INET:
      return index->ipv4;
    case AF_INET6:
      return index->ipv6;
    default:
      return NULL;
  }
}

static patricia_tree_t *
_address_index_group_tree(const struct address_index_group *group)
{
  assert(group);
  assert(group->index);
  assert(group->node);

  const patricia_prefix_t *const prefix = patricia_node_get_prefix(group->node);
  assert(prefix);

  patricia_tree_t *const tree = _address_index_tree(group->index, prefix->family);
  assert(tree);
  return tree;
}

static void
_address_index_entry_link(struct address_index_group *group, struct address_index_entry *entry)
{
  assert(group);
  assert(group->index);
  assert(group->node);
  assert(entry);
  assert(entry->group == group);
  assert(entry->next == NULL);
  assert(entry->previous_link == NULL);

  if (group->entries)
  {
    assert(group->entries->group == group);
    assert(group->entries->previous_link == &group->entries);
  }

  entry->next = group->entries;
  entry->previous_link = &group->entries;

  if (entry->next)
    entry->next->previous_link = &entry->next;

  group->entries = entry;
}

static void
_address_index_entry_unlink(struct address_index_entry *entry)
{
  assert(entry);
  assert(entry->group);
  assert(entry->previous_link);
  assert(*entry->previous_link == entry);

  if (entry->next)
  {
    assert(entry->next != entry);
    assert(entry->next->group == entry->group);
    assert(entry->next->previous_link == &entry->next);
  }

  struct address_index_entry *const next = entry->next;
  struct address_index_entry **const previous_link = entry->previous_link;

  *previous_link = next;
  if (next)
    next->previous_link = previous_link;

#ifndef NDEBUG
  entry->next = NULL;
  entry->previous_link = NULL;
#endif
}

static struct address_index_group *
_address_index_group_create(struct address_index *index, patricia_node_t *node)
{
  assert(index);
  assert(node);
  assert(patricia_node_get_data(node) == NULL);

  struct address_index_group *const group = io_calloc(sizeof(*group));
  group->index = index;
  group->node = node;

  patricia_node_set_data(node, group);
  return group;
}

static void
_address_index_group_destroy(void *data)
{
  struct address_index_group *const group = data;

  assert(group);
  assert(group->index);
  assert(group->node);
  assert(group->entries);
  assert(patricia_node_get_data(group->node) == group);

  while (group->entries)
  {
    struct address_index_entry *const entry = group->entries;
    assert(entry->group == group);
    assert(entry->previous_link == &group->entries);
    assert(group->index->count > 0);

    _address_index_entry_unlink(entry);
    --group->index->count;
    io_free(entry);
  }

  io_free(group);
}

static bool
_address_index_foreach_group(const patricia_prefix_t *prefix, void *data, void *context)
{
  assert(prefix);
  assert(data);
  assert(context);

  const struct address_index_match_context *const match_context = context;
  const struct address_index_group *const group = data;

  assert(match_context->index);
  assert(match_context->callback);
  assert(group->index == match_context->index);
  assert(group->node);
  assert(group->entries);
  assert(patricia_node_get_data(group->node) == group);
  assert(patricia_node_get_prefix(group->node) == prefix);

  for (const struct address_index_entry *entry = group->entries; entry; entry = entry->next)
  {
    assert(entry->group == group);
    assert(entry->previous_link);
    assert(*entry->previous_link == entry);

    if (!match_context->callback(entry, match_context->callback_ctx))
      return false;
  }

  return true;
}

address_index_t *
address_index_create(void)
{
  struct address_index *const index = io_calloc(sizeof(*index));
  index->ipv4 = patricia_create(AF_INET);
  index->ipv6 = patricia_create(AF_INET6);

  assert(index->ipv4);
  assert(index->ipv6);
  return index;
}

void
address_index_destroy(address_index_t *index)
{
  if (index == NULL)
    return;

  _address_index_assert_not_iterating(index);

  patricia_destroy(index->ipv4, _address_index_group_destroy);
  patricia_destroy(index->ipv6, _address_index_group_destroy);

  assert(index->count == 0);

  io_free(index);
}

address_index_entry_t *
address_index_add(address_index_t *index, const struct io_addr *addr, unsigned int prefix_length, void *data)
{
  assert(index);
  assert(addr);

  _address_index_assert_not_iterating(index);

  patricia_tree_t *const tree = _address_index_tree(index, address_get_family(addr));
  if (tree == NULL)
    return NULL;

  if (index->count == SIZE_MAX)
    return NULL;

  patricia_node_t *const node = patricia_make_and_lookup_addr(tree, addr, prefix_length);
  if (node == NULL)
    return NULL;

  struct address_index_group *group = patricia_node_get_data(node);
  if (group == NULL)
    group = _address_index_group_create(index, node);
  else
  {
    assert(group->index == index);
    assert(group->node == node);
    assert(group->entries);
  }

  struct address_index_entry *const entry = io_calloc(sizeof(*entry));
  entry->group = group;
  entry->data = data;

  _address_index_entry_link(group, entry);
  ++index->count;
  return entry;
}

void *
address_index_remove(address_index_entry_t *entry)
{
  assert(entry);
  assert(entry->group);

  struct address_index_group *const group = entry->group;
  struct address_index *const index = group->index;
  assert(index);
  assert(group->node);
  assert(group->entries);
  assert(patricia_node_get_data(group->node) == group);

  _address_index_assert_not_iterating(index);
  assert(index->count > 0);

  void *const data = entry->data;

  _address_index_entry_unlink(entry);
  --index->count;
  io_free(entry);

  if (group->entries == NULL)
  {
    patricia_tree_t *const tree = _address_index_group_tree(group);
    void *const group_data = patricia_remove(tree, group->node);
    assert(group_data == group);

    io_free(group);
  }

  return data;
}

bool
address_index_foreach_match(address_index_t *index, const struct io_addr *addr,
                            address_index_foreach_fn callback, void *callback_ctx)
{
  assert(index);
  assert(addr);
  assert(callback);

  const patricia_tree_t *const tree = _address_index_tree(index, address_get_family(addr));
  if (tree == NULL)
    return true;

#ifndef NDEBUG
  assert(index->iteration_depth < SIZE_MAX);
  ++index->iteration_depth;
#endif

  struct address_index_match_context context =
  {
    .index = index,
    .callback = callback,
    .callback_ctx = callback_ctx
  };

  const bool completed =
    patricia_foreach_match_addr(tree, addr, _address_index_foreach_group, &context);

#ifndef NDEBUG
  assert(index->iteration_depth > 0);
  --index->iteration_depth;
#endif

  return completed;
}

void
address_index_entry_get_prefix(const address_index_entry_t *entry,
                               struct io_addr *addr_out, unsigned int *prefix_length_out)
{
  assert(entry);
  assert(entry->group);
  assert(addr_out);
  assert(prefix_length_out);

  const struct address_index_group *const group = entry->group;
  assert(group->index);
  assert(group->node);
  assert(group->entries);
  assert(patricia_node_get_data(group->node) == group);

  const patricia_prefix_t *const prefix = patricia_node_get_prefix(group->node);
  assert(prefix);

  bool success;

  switch (prefix->family)
  {
    case AF_INET:
      success = address_from_bytes(addr_out, AF_INET, &prefix->addr.ipv4, sizeof(prefix->addr.ipv4));
      break;
    case AF_INET6:
      success = address_from_bytes(addr_out, AF_INET6, &prefix->addr.ipv6, sizeof(prefix->addr.ipv6));
      break;
    default:
      assert(false);
      return;
  }

  assert(success);
  if (!success)
    return;

  *prefix_length_out = prefix->bitlen;
}

void *
address_index_entry_get_data(const address_index_entry_t *entry)
{
  assert(entry);
  return entry->data;
}

size_t
address_index_count(const address_index_t *index)
{
  assert(index);
  return index->count;
}
