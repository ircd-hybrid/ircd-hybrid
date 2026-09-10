/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file ipcache.c
 * \brief Routines to count connections from particular IP addresses.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/socket.h>

#include "event.h"
#include "io_time.h"
#include "memory.h"

#include "conf.h"
#include "ipcache.h"
#include "ircd.h"

static list_t ipcache_list;
static patricia_tree_t *ipcache_trie_v6;
static patricia_tree_t *ipcache_trie_v4;

static patricia_tree_t *
_ipcache_trie_for_addr(const struct io_addr *addr)
{
  switch (address_get_family(addr))
  {
    case AF_INET:
      return ipcache_trie_v4;
    case AF_INET6:
      return ipcache_trie_v6;
    default:
      return NULL;
  }
}

struct ip_entry *
ipcache_record_find_or_add(const struct io_addr *addr)
{
  patricia_tree_t *const trie = _ipcache_trie_for_addr(addr);
  if (trie == NULL)
    return NULL;

  patricia_node_t *const pnode = patricia_make_and_lookup_addr(trie, addr, 0);
  if (pnode == NULL)
    return NULL;

  struct ip_entry *entry = patricia_node_get_data(pnode);
  if (entry)
    return entry;

  entry = io_calloc(sizeof(*entry));
  entry->trie_pointer = trie;

  list_add(pnode, &entry->node, &ipcache_list);
  patricia_node_set_data(pnode, entry);

  return entry;
}

static void
_ipcache_record_delete(patricia_node_t *pnode)
{
  assert(pnode);

  struct ip_entry *const entry = patricia_node_get_data(pnode);
  assert(entry);

  if (entry->count_local || entry->count_remote ||
      (io_time_get(IO_TIME_MONOTONIC_SEC) - entry->last_attempt) < ConfigGeneral.throttle_time)
    return;

  patricia_remove(entry->trie_pointer, pnode);

  list_remove(&entry->node, &ipcache_list);
  io_free(entry);
}

static void
_ipcache_remove_expired_records(void *unused)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, ipcache_list.head)
    _ipcache_record_delete(node->data);
}

void
ipcache_record_remove(const struct io_addr *addr, bool local)
{
  patricia_tree_t *const trie = _ipcache_trie_for_addr(addr);
  if (trie == NULL)
    return;

  patricia_node_t *const pnode = patricia_try_search_exact_addr(trie, addr, 0);
  if (pnode == NULL)
    return;

  struct ip_entry *const entry = patricia_node_get_data(pnode);
  assert(entry);
  assert(entry->count_local > 0 || entry->count_remote > 0);

  if (local)
  {
    assert(entry->count_local > 0);
    --entry->count_local;
  }
  else
  {
    assert(entry->count_remote > 0);
    --entry->count_remote;
  }

  _ipcache_record_delete(pnode);
}

void
ipcache_get_stats(uint32_t *const number_ips_stored, size_t *const mem_ips_stored)
{
  /* TBD: inaccurate for now as it does only count the amount of memory for struct ip_entry items */
  (*number_ips_stored) = list_length(&ipcache_list);
  (*mem_ips_stored) = list_length(&ipcache_list) * sizeof(struct ip_entry);
}

void
ipcache_init(void)
{
  ipcache_trie_v6 = patricia_create(AF_INET6);
  ipcache_trie_v4 = patricia_create(AF_INET);

  event_handle_t event_expire_ipcache =
    event_create(ircd_event_manager, "_ipcache_remove_expired_records", _ipcache_remove_expired_records, 123000, false, NULL, NULL);
  event_schedule(event_expire_ipcache);
}
