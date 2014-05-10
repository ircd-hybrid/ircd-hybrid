/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
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
  struct ClassItem *class = MyCalloc(sizeof(*class));

  class->active    = 1;
  class->con_freq  = DEFAULT_CONNECTFREQUENCY;
  class->ping_freq = DEFAULT_PINGFREQUENCY;
  class->max_total = MAXIMUM_LINKS_DEFAULT;
  class->max_sendq = DEFAULT_SENDQ;
  class->max_recvq = DEFAULT_RECVQ;

  dlinkAdd(class, &class->node, &class_list);

  return class;
}

void
class_free(struct ClassItem *class)
{
  assert(class);
  assert(class->active    == 0);
  assert(class->ref_count == 0);

  dlinkDelete(&class->node, &class_list);
  MyFree(class->name);
  MyFree(class);
}

void
class_init(void)
{
  (class_default = class_make())->name = xstrdup("default");
}

struct ClassItem *
get_class_ptr(const dlink_list *const list)
{
  const dlink_node *ptr = NULL;

  if ((ptr = list->head))
  {
    const struct MaskItem *conf = ptr->data;

    assert(conf->class);
    assert(conf->type & (CONF_OPER | CONF_CLIENT | CONF_SERVER));

    return conf->class;
  }

  return class_default;
}

const char *
get_client_class(const dlink_list *const list)
{
  const dlink_node *ptr = NULL;

  if ((ptr = list->head))
  {
    const struct MaskItem *conf = ptr->data;

    assert(conf->class);
    assert(conf->type & (CONF_OPER | CONF_CLIENT | CONF_SERVER));

    return conf->class->name;
  }

  return class_default->name;
}

unsigned int
get_client_ping(const dlink_list *const list)
{
  const dlink_node *ptr = NULL;

  if ((ptr = list->head))
  {
    const struct MaskItem *conf = ptr->data;

    assert(conf->class);
    assert(conf->type & (CONF_OPER | CONF_CLIENT | CONF_SERVER));

    return conf->class->ping_freq;
  }

  return class_default->ping_freq;
}

unsigned int
get_sendq(const dlink_list *const list)
{
  const dlink_node *ptr = NULL;

  if ((ptr = list->head))
  {
    const struct MaskItem *conf = ptr->data;

    assert(conf->class);
    assert(conf->type & (CONF_OPER | CONF_CLIENT | CONF_SERVER));

    return conf->class->max_sendq;
  }

  return class_default->max_sendq;
}

unsigned int
get_recvq(const dlink_list *const list)
{
  const dlink_node *ptr = NULL;

  if ((ptr = list->head))
  {
    const struct MaskItem *conf = ptr->data;

    assert(conf->class);
    assert(conf->type & (CONF_OPER | CONF_CLIENT | CONF_SERVER));

    return conf->class->max_recvq;
  }

  return class_default->max_recvq;
}

/*
 * inputs       - Integer (Number of class)
 * output       - Pointer to ClassItem struct. Non-NULL expected
 * side effects - NONE
 */
struct ClassItem *
class_find(const char *name, int active)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, class_list.head)
  {
    struct ClassItem *class = ptr->data;

    if (!irccmp(class->name, name))
      return active && !class->active ? NULL : class;
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
  dlink_node *ptr = NULL;

  DLINK_FOREACH_PREV(ptr, class_list.tail->prev)
    ((struct ClassItem *)ptr->data)->active = 0;
}

void
class_delete_marked(void)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, class_list.head)
  {
    struct ClassItem *class = ptr->data;

    if (!class->active && !class->ref_count)
    {
      destroy_cidr_class(class);
      class_free(class);
    }
  }
}

/*
 * cidr_limit_reached
 *
 * inputs	- int flag allowing over_rule of limits
 *		- pointer to the ip to be added
 *		- pointer to the class
 * output	- non zero if limit reached
 *		  0 if limit not reached
 * side effects	-
 */
int
cidr_limit_reached(int over_rule, struct irc_ssaddr *ip, struct ClassItem *class)
{
  dlink_node *ptr = NULL;
  struct CidrItem *cidr = NULL;

  if (class->number_per_cidr == 0)
    return 0;

  if (ip->ss.ss_family == AF_INET)
  {
    if (class->cidr_bitlen_ipv4 == 0)
      return 0;

    DLINK_FOREACH(ptr, class->list_ipv4.head)
    {
      cidr = ptr->data;

      if (match_ipv4(ip, &cidr->mask, class->cidr_bitlen_ipv4))
      {
        if (!over_rule && (cidr->number_on_this_cidr >= class->number_per_cidr))
          return -1;

        cidr->number_on_this_cidr++;
        return 0;
      }
    }

    cidr = MyCalloc(sizeof(struct CidrItem));
    cidr->number_on_this_cidr = 1;
    cidr->mask = *ip;
    mask_addr(&cidr->mask, class->cidr_bitlen_ipv4);
    dlinkAdd(cidr, &cidr->node, &class->list_ipv4);
  }
#ifdef IPV6
  else if (class->cidr_bitlen_ipv6 > 0)
  {
    DLINK_FOREACH(ptr, class->list_ipv6.head)
    {
      cidr = ptr->data;

      if (match_ipv6(ip, &cidr->mask, class->cidr_bitlen_ipv6))
      {
        if (!over_rule && (cidr->number_on_this_cidr >= class->number_per_cidr))
          return -1;

        cidr->number_on_this_cidr++;
        return 0;
      }
    }

    cidr = MyCalloc(sizeof(struct CidrItem));
    cidr->number_on_this_cidr = 1;
    cidr->mask = *ip;
    mask_addr(&cidr->mask, class->cidr_bitlen_ipv6);
    dlinkAdd(cidr, &cidr->node, &class->list_ipv6);
  }
#endif
  return 0;
}

/*
 * remove_from_cidr_check
 *
 * inputs	- pointer to the ip to be removed
 *		- pointer to the class
 * output	- NONE
 * side effects	-
 */
void
remove_from_cidr_check(struct irc_ssaddr *ip, struct ClassItem *aclass)
{
  dlink_node *ptr = NULL;
  dlink_node *next_ptr = NULL;
  struct CidrItem *cidr;

  if (aclass->number_per_cidr == 0)
    return;

  if (ip->ss.ss_family == AF_INET)
  {
    if (aclass->cidr_bitlen_ipv4 == 0)
      return;

    DLINK_FOREACH_SAFE(ptr, next_ptr, aclass->list_ipv4.head)
    {
      cidr = ptr->data;

      if (match_ipv4(ip, &cidr->mask, aclass->cidr_bitlen_ipv4))
      {
        cidr->number_on_this_cidr--;

        if (cidr->number_on_this_cidr == 0)
        {
          dlinkDelete(ptr, &aclass->list_ipv4);
          MyFree(cidr);
          return;
        }
      }
    }
  }
#ifdef IPV6
  else if (aclass->cidr_bitlen_ipv6 > 0)
  {
    DLINK_FOREACH_SAFE(ptr, next_ptr, aclass->list_ipv6.head)
    {
      cidr = ptr->data;

      if (match_ipv6(ip, &cidr->mask, aclass->cidr_bitlen_ipv6))
      {
        cidr->number_on_this_cidr--;

        if (cidr->number_on_this_cidr == 0)
        {
          dlinkDelete(ptr, &aclass->list_ipv6);
          MyFree(cidr);
          return;
        }
      }
    }
  }
#endif
}

void
rebuild_cidr_list(struct ClassItem *class)
{
  dlink_node *ptr = NULL;

  destroy_cidr_class(class);

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    struct Client *client_p = ptr->data;
    struct MaskItem *conf = client_p->localClient->confs.tail->data;

    if (conf && (conf->type == CONF_CLIENT))
      if (conf->class == class)
        cidr_limit_reached(1, &client_p->localClient->ip, class);
  }
}

/*
 * destroy_cidr_list
 *
 * inputs	- pointer to class dlink list of cidr blocks
 * output	- none
 * side effects	- completely destroys the class link list of cidr blocks
 */
static void
destroy_cidr_list(dlink_list *list)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, list->head)
  {
    dlinkDelete(ptr, list);
    MyFree(ptr->data);
  }
}

/*
 * destroy_cidr_class
 *
 * inputs	- pointer to class
 * output	- none
 * side effects	- completely destroys the class link list of cidr blocks
 */
void
destroy_cidr_class(struct ClassItem *class)
{
  destroy_cidr_list(&class->list_ipv4);
  destroy_cidr_list(&class->list_ipv6);
}
