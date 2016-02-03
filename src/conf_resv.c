/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2016 ircd-hybrid development team
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

/*! \file conf_resv.c
 * \brief Functions to reserve(jupe) a nick/channel.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "send.h"
#include "client.h"
#include "memory.h"
#include "irc_string.h"
#include "ircd_defs.h"
#include "misc.h"
#include "conf.h"
#include "conf_resv.h"
#include "hostmask.h"


/* create_resv()
 *
 * inputs	- name of nick to create resv for
 *		- reason for resv
 *		- 1 if from ircd.conf, 0 if from elsewhere
 * output	- pointer to struct ResvNick
 * side effects	-
 */
struct MaskItem *
create_resv(const char *name, const char *reason, const dlink_list *list)
{
  dlink_node *node = NULL;
  struct MaskItem *conf = NULL;
  enum maskitem_type type;

  if (name == NULL || reason == NULL)
    return NULL;

  if (IsChanPrefix(*name))
    type = CONF_CRESV;
  else
    type = CONF_NRESV;

  if (find_exact_name_conf(type, NULL, name, NULL, NULL))
    return NULL;

  conf = conf_make(type);
  conf->name = xstrdup(name);
  conf->reason = xstrndup(reason, IRCD_MIN(strlen(reason), REASONLEN));

  if (list)
  {
    DLINK_FOREACH(node, list->head)
    {
      char nick[NICKLEN + 1];
      char user[USERLEN + 1];
      char host[HOSTLEN + 1];
      struct split_nuh_item nuh;
      struct exempt *exptr = NULL;
      char *s = node->data;

      if (strlen(s) == 2 && IsAlpha(*(s + 1) && IsAlpha(*(s + 2))))
      {
#ifdef HAVE_LIBGEOIP
        exptr = xcalloc(sizeof(*exptr));
        exptr->name = xstrdup(s);
        exptr->country_id = GeoIP_id_by_code(s);
        dlinkAdd(exptr, &exptr->node, &conf->exempt_list);
#endif
      }
      else
      {
        nuh.nuhmask  = s;
        nuh.nickptr  = nick;
        nuh.userptr  = user;
        nuh.hostptr  = host;

        nuh.nicksize = sizeof(nick);
        nuh.usersize = sizeof(user);
        nuh.hostsize = sizeof(host);

        split_nuh(&nuh);

        exptr = xcalloc(sizeof(*exptr));
        exptr->name = xstrdup(nick);
        exptr->user = xstrdup(user);
        exptr->host = xstrdup(host);
        exptr->type = parse_netmask(host, &exptr->addr, &exptr->bits);
        dlinkAdd(exptr, &exptr->node, &conf->exempt_list);
      }
    }
  }

  return conf;
}

int
resv_find_exempt(const struct Client *client_p, const struct MaskItem *conf)
{
  const dlink_node *node = NULL;

  DLINK_FOREACH(node, conf->exempt_list.head)
  {
    const struct exempt *exptr = node->data;

    if (exptr->country_id)
    {
      if (exptr->country_id == client_p->connection->country_id)
        return 1;
    }
    else if (!match(exptr->name, client_p->name) && !match(exptr->user, client_p->username))
    {
      switch (exptr->type)
      {
        case HM_HOST:
          if (!match(exptr->host, client_p->host) || !match(exptr->host, client_p->sockhost))
            return 1;
          break;
        case HM_IPV4:
          if (client_p->connection->aftype == AF_INET)
            if (match_ipv4(&client_p->connection->ip, &exptr->addr, exptr->bits))
              return 1;
          break;
        case HM_IPV6:
          if (client_p->connection->aftype == AF_INET6)
            if (match_ipv6(&client_p->connection->ip, &exptr->addr, exptr->bits))
              return 1;
          break;
        default:
          assert(0);
      }
    }
  }

  return 0;
}

/* match_find_resv()
 *
 * inputs       - pointer to name
 * output       - pointer to a struct ResvChannel
 * side effects - Finds a reserved channel whose name matches 'name',
 *                if can't find one returns NULL.
 */
struct MaskItem *
match_find_resv(const char *name)
{
  dlink_node *node = NULL;

  if (EmptyString(name))
    return NULL;

  DLINK_FOREACH(node, cresv_items.head)
  {
    struct MaskItem *conf = node->data;

    if (!match(conf->name, name))
      return conf;
  }

  return NULL;
}
