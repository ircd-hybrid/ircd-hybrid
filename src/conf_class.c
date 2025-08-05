/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2025 ircd-hybrid development team
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

/*! \file conf_class.c
 * \brief Configuration managment for class{} blocks
 */

#include <assert.h>

#include "io_string.h"
#include "list.h"
#include "memory.h"
#include "patricia.h"

#include "client.h"
#include "conf.h"
#include "conf_class.h"
#include "defaults.h"

static list_t class_list;

struct ClassItem *class_default;

const list_t *
class_get_list(void)
{
  return &class_list;
}

struct ClassItem *
class_make(void)
{
  struct ClassItem *klass = io_calloc(sizeof(*klass));
  klass->active = true;
  klass->con_freq = DEFAULT_CONNECTFREQUENCY;
  klass->ping_freq = DEFAULT_PINGFREQUENCY;
  klass->max_sendq = DEFAULT_SENDQ;
  klass->max_recvq = DEFAULT_RECVQ;
  klass->ip_tree_v6 = patricia_new(128);
  klass->ip_tree_v4 = patricia_new( 32);
  list_add(klass, &klass->node, &class_list);

  return klass;
}

void
class_free(struct ClassItem *const klass)
{
  assert(klass != class_default);
  assert(klass->active == false);
  assert(klass->ref_count == 0);

  if (klass->ip_tree_v6)
    patricia_destroy(klass->ip_tree_v6, NULL);
  if (klass->ip_tree_v4)
    patricia_destroy(klass->ip_tree_v4, NULL);

  list_remove(&klass->node, &class_list);
  io_free(klass->name);
  io_free(klass);
}

void
class_init(void)
{
  class_default = class_make();
  class_default->name = io_strdup("default");
}

/*
 * inputs       - Integer (Number of class)
 * output       - Pointer to ClassItem struct. Non-NULL expected
 * side effects - NONE
 */
struct ClassItem *
class_find(const char *name, bool active)
{
  list_node_t *node;

  LIST_FOREACH(node, class_list.head)
  {
    struct ClassItem *klass = node->data;
    if (irccmp(klass->name, name) == 0)
    {
      if (active && klass->active == false)
        return NULL;

      return klass;
    }
  }

  return NULL;
}

/*
 * We don't delete the class table, rather mark all entries for deletion.
 * The table is cleaned up by delete_marked_classes. - avalon
 */
void
class_mark_all_inactive(void)
{
  list_node_t *node;

  LIST_FOREACH_PREV(node, class_list.tail->prev)
  {
    struct ClassItem *klass = node->data;
    klass->active = false;
  }
}

void
class_free_inactive(void)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, class_list.head)
  {
    struct ClassItem *klass = node->data;
    if (klass->active == false && klass->ref_count == 0)
      class_free(klass);
  }
}

static patricia_tree_t *
class_ip_limit_trie(struct ClassItem *klass, const void *addr)
{
  if (((const struct sockaddr *)addr)->sa_family == AF_INET6)
    return klass->ip_tree_v6;

  return klass->ip_tree_v4;
}

bool
class_ip_limit_add(struct ClassItem *klass, const void *addr, bool over_rule)
{
  int bitlen;

  if (((const struct sockaddr *)addr)->sa_family == AF_INET6)
    bitlen = klass->cidr_bitlen_ipv6;
  else
    bitlen = klass->cidr_bitlen_ipv4;

  if (klass->number_per_cidr == 0 || bitlen == 0)
    return false;

  patricia_node_t *pnode = patricia_make_and_lookup_addr(class_ip_limit_trie(klass, addr), addr, bitlen);
  if (((uintptr_t)pnode->data) >= klass->number_per_cidr)
  {
    if (over_rule)
      /*
       * In case of overruling, we continue with the client registration process
       * which means we expect a class_ip_limit_remove() call when detaching the
       * configuration record upon client exit, therefore pnode->data has to be
       * increased.
       */
      PATRICIA_DATA_SET(pnode, (((uintptr_t)pnode->data) + 1));

    return true;
  }

  PATRICIA_DATA_SET(pnode, (((uintptr_t)pnode->data) + 1));
  return false;
}

bool
class_ip_limit_remove(struct ClassItem *klass, const void *addr)
{
  int bitlen;

  if (((const struct sockaddr *)addr)->sa_family == AF_INET6)
    bitlen = klass->cidr_bitlen_ipv6;
  else
    bitlen = klass->cidr_bitlen_ipv4;

  if (klass->number_per_cidr == 0 || bitlen == 0)
    return false;

  patricia_node_t *pnode = patricia_try_search_best_addr(class_ip_limit_trie(klass, addr), addr, 0);
  if (pnode == NULL)
    return false;

  PATRICIA_DATA_SET(pnode, (((uintptr_t)pnode->data) - 1));

  if (((uintptr_t)pnode->data) == 0)
  {
    patricia_remove(class_ip_limit_trie(klass, addr), pnode);
    return true;
  }

  return false;
}

void
class_ip_limit_rebuild(struct ClassItem *klass)
{
  patricia_clear(klass->ip_tree_v6, NULL);
  patricia_clear(klass->ip_tree_v4, NULL);

  list_node_t *node;
  LIST_FOREACH(node, local_client_list.head)
  {
    const struct Client *client = node->data;
    if (client->connection->base_class == klass)
      class_ip_limit_add(klass, &client->addr, true);
  }
}

void
class_incref(struct ClassItem *klass)
{
  if (klass == NULL)
    return;
  klass->ref_count++;
}

void
class_decref(struct ClassItem *klass)
{
  if (klass == NULL)
    return;

  assert(klass->ref_count > 0);
  klass->ref_count--;

  if (klass->ref_count == 0 && klass->active == false)
    class_free(klass);
}
