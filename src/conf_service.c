/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2012-2016 ircd-hybrid development team
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

/*! \file conf_service.c
 * \brief Implements service {} block configuration management.
 * \version $Id: conf_service.c 7240 2016-02-03 16:40:25Z michael $
 */

#include "stdinc.h"
#include "list.h"
#include "irc_string.h"
#include "memory.h"
#include "conf_service.h"


static dlink_list service_list;


const dlink_list *
service_get_list(void)
{
  return &service_list;
}

void
service_clear(void)
{
  while (service_list.head)
  {
    struct ServiceItem *service = service_list.head->data;

    dlinkDelete(&service->node, &service_list);
    xfree(service->name);
    xfree(service);
  }
}

struct ServiceItem *
service_make(void)
{
  struct ServiceItem *service = xcalloc(sizeof(*service));
  dlinkAdd(service, &service->node, &service_list);

  return service;
}

const struct ServiceItem *
service_find(const char *name)
{
  dlink_node *node;

  DLINK_FOREACH(node, service_list.head)
  {
    const struct ServiceItem *service = node->data;

    if (!irccmp(service->name, name))
      return service;
  }

  return NULL;
}
