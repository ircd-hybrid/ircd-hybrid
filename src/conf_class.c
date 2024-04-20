/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

#include "stdinc.h"
#include "defaults.h"
#include "list.h"
#include "conf.h"
#include "irc_string.h"
#include "memory.h"
#include "patricia.h"


struct ClassItem *class_default;

static list_t class_list;


const list_t *
class_get_list(void)
{
  return &class_list;
}

struct ClassItem *
class_make(void)
{
  struct ClassItem *class = xcalloc(sizeof(*class));

  class->active = true;
  class->con_freq = DEFAULT_CONNECTFREQUENCY;
  class->ping_freq = DEFAULT_PINGFREQUENCY;
  class->max_sendq = DEFAULT_SENDQ;
  class->max_recvq = DEFAULT_RECVQ;
  class->ip_tree_v6 = patricia_new(128);
  class->ip_tree_v4 = patricia_new( 32);

  list_add(class, &class->node, &class_list);

  return class;
}

void
class_free(struct ClassItem *const class)
{
  assert(class != class_default);
  assert(class->active == false);
  assert(class->ref_count == 0);

  if (class->ip_tree_v6)
    patricia_destroy(class->ip_tree_v6, NULL);
  if (class->ip_tree_v4)
    patricia_destroy(class->ip_tree_v4, NULL);

  list_remove(&class->node, &class_list);
  xfree(class->name);
  xfree(class);
}

void
class_init(void)
{
  class_default = class_make();
  class_default->name = xstrdup("default");
}

const struct ClassItem *
class_get_ptr(const list_t *const list)
{
  const list_node_t *const node = list->head;

  if (node)
  {
    const struct MaskItem *const conf = node->data;

    assert(conf->class);
    assert(conf->type & (CONF_OPER | CONF_CLIENT | CONF_SERVER));

    return conf->class;
  }

  return class_default;
}

const char *
class_get_name(const list_t *const list)
{
  return class_get_ptr(list)->name;
}

unsigned int
class_get_ping_freq(const list_t *const list)
{
  return class_get_ptr(list)->ping_freq;
}

unsigned int
class_get_sendq(const list_t *const list)
{
  return class_get_ptr(list)->max_sendq;
}

unsigned int
class_get_recvq(const list_t *const list)
{
  return class_get_ptr(list)->max_recvq;
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
    struct ClassItem *class = node->data;

    if (irccmp(class->name, name) == 0)
    {
      if (active && class->active == false)
        return NULL;

      return class;
    }
  }

  return NULL;
}

/*
 * We don't delete the class table, rather mark all entries for deletion.
 * The table is cleaned up by delete_marked_classes. - avalon
 */
void
class_mark_for_deletion(void)
{
  list_node_t *node;

  LIST_FOREACH_PREV(node, class_list.tail->prev)
  {
    struct ClassItem *class = node->data;
    class->active = false;
  }
}

void
class_delete_marked(void)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, class_list.head)
  {
    struct ClassItem *class = node->data;

    if (class->active == false && class->ref_count == 0)
      class_free(class);
  }
}

static void *
class_ip_limit_trie(struct ClassItem *class, void *addr)
{
  if (((struct sockaddr *)addr)->sa_family == AF_INET6)
    return class->ip_tree_v6;
  else
    return class->ip_tree_v4;
}

bool
class_ip_limit_add(struct ClassItem *class, void *addr, bool over_rule)
{
  int bitlen;

  if (((struct sockaddr *)addr)->sa_family == AF_INET6)
    bitlen = class->cidr_bitlen_ipv6;
  else
    bitlen = class->cidr_bitlen_ipv4;

  if (class->number_per_cidr == 0 || bitlen == 0)
    return false;

  patricia_node_t *pnode = patricia_make_and_lookup_addr(class_ip_limit_trie(class, addr), addr, bitlen);
  if (((uintptr_t)pnode->data) >= class->number_per_cidr)
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
class_ip_limit_remove(struct ClassItem *class, void *addr)
{
  int bitlen;

  if (((struct sockaddr *)addr)->sa_family == AF_INET6)
    bitlen = class->cidr_bitlen_ipv6;
  else
    bitlen = class->cidr_bitlen_ipv4;

  if (class->number_per_cidr == 0 || bitlen == 0)
    return false;

  patricia_node_t *pnode = patricia_try_search_best_addr(class_ip_limit_trie(class, addr), addr, 0);
  if (pnode == NULL)
    return false;

  PATRICIA_DATA_SET(pnode, (((uintptr_t)pnode->data) - 1));

  if (((uintptr_t)pnode->data) == 0)
  {
    patricia_remove(class_ip_limit_trie(class, addr), pnode);
    return true;
  }

  return false;
}

void
class_ip_limit_rebuild(struct ClassItem *class)
{
  patricia_clear(class->ip_tree_v6, NULL);
  patricia_clear(class->ip_tree_v4, NULL);

  list_node_t *node;
  LIST_FOREACH(node, local_client_list.head)
  {
    struct Client *client = node->data;
    struct MaskItem *conf = client->connection->confs.tail->data;

    if (conf->type == CONF_CLIENT)
      if (conf->class == class)
        class_ip_limit_add(class, &client->addr, true);
  }
}
