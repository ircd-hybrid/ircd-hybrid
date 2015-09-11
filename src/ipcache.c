/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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
#include "mempool.h"
#include "conf.h"
#include "ircd.h"


static dlink_list ip_hash_table[IP_HASH_SIZE];
static mp_pool_t *ip_entry_pool;


/* ipcache_hash_address()
 *
 * input        - pointer to an irc_inaddr
 * output       - integer value used as index into hash table
 * side effects - hopefully, none
 */
static uint32_t
ipcache_hash_address(const struct irc_ssaddr *addr)
{
  if (addr->ss.ss_family == AF_INET)
  {
    const struct sockaddr_in *const v4 = (const struct sockaddr_in *)addr;
    uint32_t hash = 0, ip = ntohl(v4->sin_addr.s_addr);

    hash = ((ip >> 12) + ip) & (IP_HASH_SIZE - 1);
    return hash;
  }
  else
  {
    const struct sockaddr_in6 *const v6 = (const struct sockaddr_in6 *)addr;
    uint32_t hash = 0, *const ip = (uint32_t *)&v6->sin6_addr.s6_addr;

    hash  = ip[0] ^ ip[3];
    hash ^= hash >> 16;
    hash ^= hash >> 8;
    hash  = hash & (IP_HASH_SIZE - 1);
    return hash;
  }
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
ipcache_find_or_add_address(struct irc_ssaddr *addr)
{
  dlink_node *node = NULL;
  struct ip_entry *iptr = NULL;
  const uint32_t hash_index = ipcache_hash_address(addr);
  struct sockaddr_in *v4 = (struct sockaddr_in *)addr, *ptr_v4;
  struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)addr, *ptr_v6;

  DLINK_FOREACH(node, ip_hash_table[hash_index].head)
  {
    iptr = node->data;

    if (iptr->ip.ss.ss_family != addr->ss.ss_family)
      continue;

    if (addr->ss.ss_family == AF_INET6)
    {
      ptr_v6 = (struct sockaddr_in6 *)&iptr->ip;
      if (!memcmp(&v6->sin6_addr, &ptr_v6->sin6_addr, sizeof(struct in6_addr)))
        return iptr;  /* Found entry already in hash, return it. */
    }
    else
    {
      ptr_v4 = (struct sockaddr_in *)&iptr->ip;
      if (!memcmp(&v4->sin_addr, &ptr_v4->sin_addr, sizeof(struct in_addr)))
        return iptr;  /* Found entry already in hash, return it. */
    }
  }

  iptr = mp_pool_get(ip_entry_pool);
  memcpy(&iptr->ip, addr, sizeof(struct irc_ssaddr));

  dlinkAdd(iptr, &iptr->node, &ip_hash_table[hash_index]);

  return iptr;
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
ipcache_remove_address(struct irc_ssaddr *addr)
{
  dlink_node *node = NULL;
  const uint32_t hash_index = ipcache_hash_address(addr);
  struct sockaddr_in *v4 = (struct sockaddr_in *)addr, *ptr_v4;
  struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)addr, *ptr_v6;

  DLINK_FOREACH(node, ip_hash_table[hash_index].head)
  {
    struct ip_entry *iptr = node->data;

    if (iptr->ip.ss.ss_family != addr->ss.ss_family)
      continue;

    if (addr->ss.ss_family == AF_INET6)
    {
      ptr_v6 = (struct sockaddr_in6 *)&iptr->ip;
      if (memcmp(&v6->sin6_addr, &ptr_v6->sin6_addr, sizeof(struct in6_addr)))
        continue;
    }
    else
    {
      ptr_v4 = (struct sockaddr_in *)&iptr->ip;
      if (memcmp(&v4->sin_addr, &ptr_v4->sin_addr, sizeof(struct in_addr)))
        continue;
    }

    assert(iptr->count > 0);

    if (--iptr->count == 0 &&
        (CurrentTime - iptr->last_attempt) >= ConfigGeneral.throttle_time)
    {
      dlinkDelete(&iptr->node, &ip_hash_table[hash_index]);
      mp_pool_release(iptr);
      return;
    }
  }
}

/* ipcache_remove_expired_entries()
 *
 * input        - NONE
 * output       - NONE
 * side effects - free up all ip entries with no connections
 */
static void
ipcache_remove_expired_entries(void *unused)
{
  dlink_node *node = NULL, *node_next = NULL;

  for (unsigned int i = 0; i < IP_HASH_SIZE; ++i)
  {
    DLINK_FOREACH_SAFE(node, node_next, ip_hash_table[i].head)
    {
      struct ip_entry *iptr = node->data;

      if (iptr->count == 0 &&
          (CurrentTime - iptr->last_attempt) >= ConfigGeneral.throttle_time)
      {
        dlinkDelete(&iptr->node, &ip_hash_table[i]);
        mp_pool_release(iptr);
      }
    }
  }
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
ipcache_get_stats(unsigned int *const number_ips_stored, uint64_t *const mem_ips_stored)
{
  for (unsigned int i = 0; i < IP_HASH_SIZE; ++i)
    *number_ips_stored += dlink_list_length(&ip_hash_table[i]);
  *mem_ips_stored = *number_ips_stored * sizeof(struct ip_entry);
}

void
ipcache_init(void)
{
  static struct event event_expire_ipcache =
  {
    .name = "ipcache_remove_expired_entries",
    .handler = ipcache_remove_expired_entries,
    .when = 123
  };

  event_add(&event_expire_ipcache, NULL);
  ip_entry_pool = mp_pool_new(sizeof(struct ip_entry), MP_CHUNK_SIZE_IP_ENTRY);
}
