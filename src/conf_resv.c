/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2024 ircd-hybrid development team
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
 */

#include "stdinc.h"
#include "io_time.h"
#include "irc_string.h"
#include "list.h"
#include "send.h"
#include "client.h"
#include "memory.h"
#include "ircd.h"
#include "event.h"
#include "ircd_defs.h"
#include "misc.h"
#include "conf.h"
#include "conf_resv.h"
#include "address.h"

static list_t resv_chan_list;
static list_t resv_nick_list;

const list_t *
resv_chan_get_list(void)
{
  return &resv_chan_list;
}

const list_t *
resv_nick_get_list(void)
{
  return &resv_nick_list;
}

void
resv_delete(struct ResvItem *resv, bool expired)
{
  if (expired)
    sendto_realops_flags(UMODE_EXPIRATION, L_ALL, SEND_NOTICE, "Temporary RESV for [%s] expired",
                         resv->mask);

  while (resv->exempt_list.head)
  {
    struct ResvExemptItem *exempt = resv->exempt_list.head->data;

    list_remove(&exempt->node, &resv->exempt_list);
    io_free(exempt->name);
    io_free(exempt->user);
    io_free(exempt->host);
    io_free(exempt);
  }

  list_remove(&resv->node, resv->list);
  io_free(resv->mask);
  io_free(resv->reason);
  io_free(resv);
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
resv_make(const char *mask, const char *reason, const list_t *elist)
{
  list_t *list;

  if (IsChanPrefix(*mask))
    list = &resv_chan_list;
  else
    list = &resv_nick_list;

  struct ResvItem *resv = io_calloc(sizeof(*resv));
  resv->list = list;
  resv->mask = io_strdup(mask);
  resv->reason = io_strndup(reason, IO_MIN(strlen(reason), REASONLEN));
  list_add(resv, &resv->node, resv->list);

  if (elist)
  {
    list_node_t *node;

    LIST_FOREACH(node, elist->head)
    {
      char *s = node->data;
      char nick[NICKLEN + 1];
      char user[USERLEN + 1];
      char host[HOSTLEN + 1];
      struct split_nuh_item nuh =
      {
        .nuhmask = s,
        .nickptr = nick,
        .userptr = user,
        .hostptr = host,
        .nicksize = sizeof(nick),
        .usersize = sizeof(user),
        .hostsize = sizeof(host)
      };

      split_nuh(&nuh);

      struct ResvExemptItem *exempt = io_calloc(sizeof(*exempt));
      exempt->name = io_strdup(nick);
      exempt->user = io_strdup(user);
      exempt->host = io_strdup(host);
      exempt->type = parse_netmask(host, &exempt->addr, &exempt->bits);
      list_add(exempt, &exempt->node, &resv->exempt_list);
    }
  }

  return resv;
}

struct ResvItem *
resv_find(const char *name, int (*compare)(const char *, const char *))
{
  list_t *list;

  if (IsChanPrefix(*name))
    list = &resv_chan_list;
  else
    list = &resv_nick_list;

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, list->head)
  {
    struct ResvItem *resv = node->data;

    if (resv->expire &&
        (resv->expire <= io_time_get(IO_TIME_REALTIME_SEC)))
      resv_delete(resv, true);
    else if (compare(resv->mask, name) == 0)
      return resv;
  }

  return NULL;
}

bool
resv_exempt_find(const struct Client *client, const struct ResvItem *resv)
{
  list_node_t *node;

  LIST_FOREACH(node, resv->exempt_list.head)
  {
    const struct ResvExemptItem *exempt = node->data;

    if (match(exempt->name, client->name) == 0 && match(exempt->user, client->username) == 0)
    {
      switch (exempt->type)
      {
        case HM_HOST:
          if (match(exempt->host, client->realhost) == 0 ||
              match(exempt->host, client->sockhost) == 0 || match(exempt->host, client->host) == 0)
            return true;
          break;
        case HM_IPV6:
        case HM_IPV4:
          if (address_compare(&client->addr, &exempt->addr, false, false, exempt->bits))
            return true;
          break;
        default:
          assert(0);
      }
    }
  }

  return false;
}

void
resv_clear(void)
{
  list_t *tab[] = { &resv_chan_list, &resv_nick_list, NULL };

  for (list_t **list = tab; *list; ++list)
  {
    list_node_t *node, *node_next;

    LIST_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      struct ResvItem *resv = node->data;

      if (resv->in_database == false)
        resv_delete(resv, false);
    }
  }
}

void
resv_expire(void)
{
  list_t *tab[] = { &resv_chan_list, &resv_nick_list, NULL };

  for (list_t **list = tab; *list; ++list)
  {
    list_node_t *node, *node_next;

    LIST_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      struct ResvItem *resv = node->data;

      if (resv->expire &&
          (resv->expire <= io_time_get(IO_TIME_REALTIME_SEC)))
        resv_delete(resv, true);
    }
  }
}
