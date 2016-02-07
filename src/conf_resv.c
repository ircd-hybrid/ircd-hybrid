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
#include "ircd.h"
#include "irc_string.h"
#include "ircd_defs.h"
#include "misc.h"
#include "conf.h"
#include "conf_resv.h"
#include "hostmask.h"


static dlink_list resv_chan_list;
static dlink_list resv_nick_list;


const dlink_list *
resv_chan_get_list(void)
{
  return &resv_chan_list;
}

const dlink_list *
resv_nick_get_list(void)
{
  return &resv_nick_list;
}

void
resv_delete(struct ResvItem *resv)
{
  while (resv->exempt_list.head)
  {
    struct ResvExemptItem *exempt = resv->exempt_list.head->data;

    dlinkDelete(&exempt->node, &resv->exempt_list);
    xfree(exempt->name);
    xfree(exempt->user);
    xfree(exempt->host);
    xfree(exempt);
  }

  dlinkDelete(&resv->node, resv->list);
  xfree(resv->mask);
  xfree(resv->reason);
  xfree(resv);
}

/* create_resv()
 *
 * inputs	- name of nick to create resv for
 *		- reason for resv
 *		- 1 if from ircd.conf, 0 if from elsewhere
 * output	- pointer to struct ResvNick
 * side effects	-
 */
struct ResvItem *
resv_make(const char *mask, const char *reason, const dlink_list *elist)
{
  dlink_list *list;

  if (resv_find(mask, irccmp))
    return NULL;

  if (IsChanPrefix(*mask))
    list = &resv_chan_list;
  else
    list = &resv_nick_list;

  struct ResvItem *resv = xcalloc(sizeof(*resv));
  resv->list = list;
  resv->mask = xstrdup(mask);
  resv->reason = xstrndup(reason, IRCD_MIN(strlen(reason), REASONLEN));
  dlinkAdd(resv, &resv->node, resv->list);

  if (elist)
  {
    dlink_node *node;

    DLINK_FOREACH(node, elist->head)
    {
      char nick[NICKLEN + 1];
      char user[USERLEN + 1];
      char host[HOSTLEN + 1];
      struct split_nuh_item nuh;
      char *s = node->data;

      if (strlen(s) == 2 && IsAlpha(*(s + 1) && IsAlpha(*(s + 2))))
      {
#ifdef HAVE_LIBGEOIP
        struct ResvExemptItem *exempt = xcalloc(sizeof(*exempt));
        exempt->name = xstrdup(s);
        exempt->country_id = GeoIP_id_by_code(s);
        dlinkAdd(exempt, &exempt->node, &resv->exempt_list);
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

        struct ResvExemptItem *exempt = xcalloc(sizeof(*exempt));
        exempt->name = xstrdup(nick);
        exempt->user = xstrdup(user);
        exempt->host = xstrdup(host);
        exempt->type = parse_netmask(host, &exempt->addr, &exempt->bits);
        dlinkAdd(exempt, &exempt->node, &resv->exempt_list);
      }
    }
  }

  return resv;
}

struct ResvItem *
resv_find(const char *name, int (*compare)(const char *, const char *))
{
  dlink_node *node = NULL;
  dlink_list *list = NULL;

  if (IsChanPrefix(*name))
    list = &resv_chan_list;
  else
    list = &resv_nick_list;

  DLINK_FOREACH(node, list->head)
  {
    struct ResvItem *resv = node->data;

    if (!compare(resv->mask, name))
      return resv;
  }

  return NULL;
}

int
resv_exempt_find(const struct Client *client_p, const struct ResvItem *resv)
{
  const dlink_node *node = NULL;

  DLINK_FOREACH(node, resv->exempt_list.head)
  {
    const struct ResvExemptItem *exempt = node->data;

    if (exempt->country_id)
    {
      if (exempt->country_id == client_p->connection->country_id)
        return 1;
    }
    else if (!match(exempt->name, client_p->name) && !match(exempt->user, client_p->username))
    {
      switch (exempt->type)
      {
        case HM_HOST:
          if (!match(exempt->host, client_p->host) || !match(exempt->host, client_p->sockhost))
            return 1;
          break;
        case HM_IPV4:
          if (client_p->connection->aftype == AF_INET)
            if (match_ipv4(&client_p->connection->ip, &exempt->addr, exempt->bits))
              return 1;
          break;
        case HM_IPV6:
          if (client_p->connection->aftype == AF_INET6)
            if (match_ipv6(&client_p->connection->ip, &exempt->addr, exempt->bits))
              return 1;
          break;
        default:
          assert(0);
      }
    }
  }

  return 0;
}

void
resv_clear(void)
{
  dlink_list *tab[] = { &resv_chan_list, &resv_nick_list, NULL };

  for (dlink_list **list = tab; *list; ++list)
  {
    dlink_node *node = NULL, *node_next = NULL;

    DLINK_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      struct ResvItem *resv = node->data;

      if (!resv->in_database)
        resv_delete(resv);
    }
  }
}

void
resv_expire(void)
{
  dlink_list *tab[] = { &resv_chan_list, &resv_nick_list, NULL };

  for (dlink_list **list = tab; *list; ++list)
  {
    dlink_node *node = NULL, *node_next = NULL;

    DLINK_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      struct ResvItem *resv = node->data;

      if (!resv->expire || resv->expire > CurrentTime)
        continue;

      if (ConfigGeneral.tkline_expire_notices)
        sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "Temporary RESV for [%s] expired",
                             resv->mask);
      resv_delete(resv);
    }
  }
}
