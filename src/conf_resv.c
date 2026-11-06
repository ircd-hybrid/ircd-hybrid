/*
 * SPDX-FileCopyrightText: 2001-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file conf_resv.c
 * \brief Functions to reserve(jupe) a nick/channel.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "address.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"

#include "channel.h"
#include "client.h"
#include "conf_resv.h"
#include "ircd_defs.h"
#include "nuh.h"

static list_t resv_chan_list;
static list_t resv_nick_list;

#ifndef NDEBUG
static bool resv_expire_callback_active;
#endif

static void
_resv_assert_mutation_allowed(void)
{
#ifndef NDEBUG
  assert(!resv_expire_callback_active);
#endif
}

static bool
_resv_is_expired(const struct ResvItem *resv, uintmax_t now)
{
  assert(resv);
  return resv->expires_at != 0 && resv->expires_at <= now;
}

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
resv_delete(struct ResvItem *resv)
{
  assert(resv);
  _resv_assert_mutation_allowed();

  list_node_t *node;
  while ((node = list_pop_head(&resv->exempt_list)))
  {
    struct ResvExemptItem *const exempt = node->data;
    assert(exempt);

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

struct ResvItem *
resv_make(const char *mask, const char *reason, const list_t *elist)
{
  _resv_assert_mutation_allowed();

  list_t *const list = channel_is_valid_prefix_char(*mask) ? &resv_chan_list : &resv_nick_list;
  struct ResvItem *const resv = io_calloc(sizeof(*resv));
  resv->list = list;
  resv->mask = io_strdup(mask);
  resv->reason = io_strndup(reason, REASONLEN);
  list_add_tail(resv, &resv->node, resv->list);

  if (elist)
  {
    list_node_t *node;
    LIST_FOREACH(node, elist->head)
    {
      char *const s = node->data;
      char nick[NICKLEN + 1];
      char user[USERLEN + 1];
      char host[HOSTLEN + 1];
      struct nuh_split nuh =
      {
        .nuhmask = s,
        .nickptr = nick,
        .userptr = user,
        .hostptr = host,
        .nicksize = sizeof(nick),
        .usersize = sizeof(user),
        .hostsize = sizeof(host)
      };

      nuh_split(&nuh);

      struct ResvExemptItem *const exempt = io_calloc(sizeof(*exempt));
      exempt->name = io_strdup(nick);
      exempt->user = io_strdup(user);
      exempt->host = io_strdup(host);
      address_parse_prefix(exempt->host, &exempt->addr, &exempt->bits);

      list_add_tail(exempt, &exempt->node, &resv->exempt_list);
    }
  }

  return resv;
}

struct ResvItem *
resv_find(const char *name, int (*compare)(const char *, const char *))
{
  const uintmax_t now = io_time_get(IO_TIME_REALTIME_SEC);
  list_t *const list = channel_is_valid_prefix_char(*name) ? &resv_chan_list : &resv_nick_list;

  list_node_t *node;
  LIST_FOREACH(node, list->head)
  {
    struct ResvItem *const resv = node->data;
    if (!_resv_is_expired(resv, now) && compare(resv->mask, name) == 0)
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
    const struct ResvExemptItem *const exempt = node->data;
    if (match(exempt->name, client->name) || match(exempt->user, client->username))
      continue;

    if (address_is_ipv4(&exempt->addr) ||
        address_is_ipv6(&exempt->addr))
    {
      if (address_match_prefix(&client->addr, &exempt->addr, exempt->bits))
        return true;
    }
    else if (match(exempt->host, client->realhost) == 0 ||
             match(exempt->host, client->sockhost) == 0 || match(exempt->host, client->host) == 0)
      return true;
  }

  return false;
}

void
resv_clear(void)
{
  _resv_assert_mutation_allowed();

  list_t *tab[] = { &resv_chan_list, &resv_nick_list, NULL };

  for (list_t **list = tab; *list; ++list)
  {
    list_node_t *node, *node_next;

    LIST_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      struct ResvItem *const resv = node->data;
      if (resv->in_database == false)
        resv_delete(resv);
    }
  }
}

void
resv_expire(uintmax_t now, resv_expire_callback_fn callback, void *callback_ctx)
{
  _resv_assert_mutation_allowed();

  list_t *tab[] = { &resv_chan_list, &resv_nick_list, NULL };

  for (list_t **list = tab; *list; ++list)
  {
    list_node_t *node, *node_next;

    LIST_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      struct ResvItem *const resv = node->data;
      if (!_resv_is_expired(resv, now))
        continue;

      if (callback)
      {
#ifndef NDEBUG
        assert(!resv_expire_callback_active);
        resv_expire_callback_active = true;
#endif

        callback(resv, callback_ctx);

#ifndef NDEBUG
        assert(resv_expire_callback_active);
        resv_expire_callback_active = false;
#endif
      }

      resv_delete(resv);
    }
  }
}
