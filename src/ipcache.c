/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2018 ircd-hybrid development team
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

/*! \file ipcache.c
 * \brief Routines to count connections from particular IP addresses.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "ipcache.h"
#include "event.h"
#include "memory.h"
#include "conf.h"
#include "ircd.h"
#include "patricia.h"


static dlink_list ipcache_list;
static patricia_tree_t *ipcache_trie_v6;
static patricia_tree_t *ipcache_trie_v4;


static void *
ipcache_get_trie(void *addr)
{
  if (((struct sockaddr *)addr)->sa_family == AF_INET6)
    return ipcache_trie_v6;
  else
    return ipcache_trie_v4;
}

/* ipcache_find_or_add_address()
 *
 * inputs       - pointer to struct irc_ssaddr
 * output       - pointer to a struct ip_entry
 * side effects -
 *
 * If the ip # was not found, a new struct ip_entry is created, and the ip
 * count set to 0.
 */
struct ip_entry *
ipcache_record_find_or_add(void *addr)
{
  patricia_tree_t *ptrie = ipcache_get_trie(addr);
  patricia_node_t *pnode = patricia_make_and_lookup_addr(ptrie, addr, 0);

  if (pnode->data)  /* Deliberate crash if 'pnode' is NULL */
    return pnode->data;  /* Already added to the trie */

  struct ip_entry *iptr = xcalloc(sizeof(*iptr));
  iptr->trie_pointer = ptrie;
  dlinkAdd(pnode, &iptr->node, &ipcache_list);

  PATRICIA_DATA_SET(pnode, iptr);

  return iptr;
}

static void
ipcache_record_delete(patricia_node_t *pnode)
{
  struct ip_entry *iptr = PATRICIA_DATA_GET(pnode, struct ip_entry);

  if (iptr->count_local == 0 && iptr->count_remote == 0 &&
      (CurrentTime - iptr->last_attempt) >= ConfigGeneral.throttle_time)
  {
    patricia_remove(iptr->trie_pointer, pnode);

    dlinkDelete(&iptr->node, &ipcache_list);
    xfree(iptr);
  }
}

/* ipcache_remove_addres()
 *
 * inputs        - unsigned long IP address value
 * output        - NONE
 * side effects  - The ip address given, is looked up in ip hash table
 *                 and number of ip#'s for that ip decremented.
 *                 If ip # count reaches 0 and has expired,
 *                 the struct ip_entry is returned to the ip_entry_heap
 */
void
ipcache_record_remove(void *addr, int local)
{
  patricia_node_t *pnode = patricia_try_search_exact_addr(ipcache_get_trie(addr), addr, 0);

  if (pnode == NULL)
    return;

  struct ip_entry *iptr = PATRICIA_DATA_GET(pnode, struct ip_entry);
  assert(iptr->count_local > 0 || iptr->count_remote > 0);

  if (local)
    --iptr->count_local;
  else
    --iptr->count_remote;

  ipcache_record_delete(pnode);
}

/* ipcache_remove_expired_entries()
 *
 * input        - NONE
 * output       - NONE
 * side effects - free up all ip entries with no connections
 */
static void
ipcache_remove_expired_records(void *unused)
{
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, ipcache_list.head)
    ipcache_record_delete(node->data);
}

/* ipcache_get_stats()
 *
 * inputs        - pointer to counter of number of ips hashed
 *               - pointer to memory used for ip hash
 * output        - returned via pointers input
 * side effects  - NONE
 *
 * number of hashed ip #'s is counted up, plus the amount of memory
 * used in the hash.
 */
void
ipcache_get_stats(unsigned int *const number_ips_stored, size_t *const mem_ips_stored)
{
  /* TBD: inaccurate for now as it does only count the amount of memory for struct ip_entry items */
  (*number_ips_stored) = dlink_list_length(&ipcache_list);
  (*mem_ips_stored) = dlink_list_length(&ipcache_list) * sizeof(struct ip_entry);
}

void
ipcache_init(void)
{
  static struct event event_expire_ipcache =
  {
    .name = "ipcache_remove_expired_records",
    .handler = ipcache_remove_expired_records,
    .when = 123
  };

  ipcache_trie_v6 = patricia_new(128);
  ipcache_trie_v4 = patricia_new( 32);

  event_add(&event_expire_ipcache, NULL);
}
