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

/*! \file conf_class.c
 * \brief Configuration managment for class{} blocks
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "ircd.h"
#include "conf.h"
#include "hostmask.h"
#include "irc_string.h"
#include "memory.h"
#include "patricia.h"


struct ClassItem *class_default;

static dlink_list class_list;


const dlink_list *
class_get_list(void)
{
  return &class_list;
}

struct ClassItem *
class_make(void)
{
  struct ClassItem *class = xcalloc(sizeof(*class));

  class->active    = 1;
  class->con_freq  = DEFAULT_CONNECTFREQUENCY;
  class->ping_freq = DEFAULT_PINGFREQUENCY;
  class->max_total = MAXIMUM_LINKS_DEFAULT;
  class->max_sendq = DEFAULT_SENDQ;
  class->max_recvq = DEFAULT_RECVQ;
  class->ip_tree   = patricia_new(PATRICIA_MAXBITS);

  dlinkAdd(class, &class->node, &class_list);

  return class;
}

void
class_free(struct ClassItem *const class)
{
  assert(class != class_default);
  assert(class->active    == 0);
  assert(class->ref_count == 0);

  if (class->ip_tree)
    patricia_destroy(class->ip_tree, NULL);

  dlinkDelete(&class->node, &class_list);
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
class_get_ptr(const dlink_list *const list)
{
  const dlink_node *const node = list->head;

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
get_client_class(const dlink_list *const list)
{
  return class_get_ptr(list)->name;
}

unsigned int
get_client_ping(const dlink_list *const list)
{
  return class_get_ptr(list)->ping_freq;
}

unsigned int
get_sendq(const dlink_list *const list)
{
  return class_get_ptr(list)->max_sendq;
}

unsigned int
get_recvq(const dlink_list *const list)
{
  return class_get_ptr(list)->max_recvq;
}

/*
 * inputs       - Integer (Number of class)
 * output       - Pointer to ClassItem struct. Non-NULL expected
 * side effects - NONE
 */
struct ClassItem *
class_find(const char *name, int active)
{
  dlink_node *node;

  DLINK_FOREACH(node, class_list.head)
  {
    struct ClassItem *class = node->data;

    if (irccmp(class->name, name) == 0)
      return active && class->active == 0 ? NULL : class;
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
  dlink_node *node;

  DLINK_FOREACH_PREV(node, class_list.tail->prev)
    ((struct ClassItem *)node->data)->active = 0;
}

void
class_delete_marked(void)
{
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, class_list.head)
  {
    struct ClassItem *class = node->data;

    if (class->active == 0 && class->ref_count == 0)
      class_free(class);
  }
}

int
class_ip_limit_add(struct ClassItem *class, void *addr, int over_rule)
{
  int bitlen;

  if (((struct sockaddr *)addr)->sa_family == AF_INET6)
    bitlen = class->cidr_bitlen_ipv6;
  else
    bitlen = class->cidr_bitlen_ipv4;

  if (class->number_per_cidr == 0 || bitlen == 0)
    return 0;

  patricia_node_t *pnode = patricia_make_and_lookup_addr(class->ip_tree, addr, bitlen);
  if (((uintptr_t)pnode->data) >= class->number_per_cidr && over_rule == 0)
    return 1;

  PATRICIA_DATA_SET(pnode, (((uintptr_t)pnode->data) + 1));
  return 0;
}

int
class_ip_limit_remove(struct ClassItem *class, void *addr)
{
  int bitlen;

  if (((struct sockaddr *)addr)->sa_family == AF_INET6)
    bitlen = class->cidr_bitlen_ipv6;
  else
    bitlen = class->cidr_bitlen_ipv4;

  if (class->number_per_cidr == 0 || bitlen == 0)
    return 0;

  patricia_node_t *pnode = patricia_try_search_best_addr(class->ip_tree, addr, 0);
  if (pnode == NULL)
    return 0;

  PATRICIA_DATA_SET(pnode, (((uintptr_t)pnode->data) - 1));

  if (((uintptr_t)pnode->data) == 0)
  {
    patricia_remove(class->ip_tree, pnode);
    return 1;
  }

  return 0;
}

void
class_ip_limit_rebuild(struct ClassItem *class)
{
  dlink_node *node;

  patricia_clear(class->ip_tree, NULL);

  DLINK_FOREACH(node, local_client_list.head)
  {
    struct Client *client_p = node->data;
    struct MaskItem *conf = client_p->connection->confs.tail->data;

    if (conf->type == CONF_CLIENT)
      if (conf->class == class)
        class_ip_limit_add(class, &client_p->ip, 1);
  }
}
