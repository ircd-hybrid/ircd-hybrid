/*
 * SPDX-FileCopyrightText: 2001-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "address.h"
#include "io.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"

#include "channel.h"
#include "client.h"
#include "conf_resv.h"
#include "ircd_defs.h"
#include "nuh.h"

enum conf_resv_lookup_mode
{
  CONF_RESV_LOOKUP_MATCH,
  CONF_RESV_LOOKUP_EXACT,
  CONF_RESV_LOOKUP_ACTIVE_EXACT
};

static list_t conf_resv_channels;
static list_t conf_resv_nicks;

#ifndef NDEBUG
static bool conf_resv_expire_callback_active;
#endif

static void
_conf_resv_assert_mutation_allowed(void)
{
#ifndef NDEBUG
  assert(!conf_resv_expire_callback_active);
#endif
}

static list_t *
_conf_resv_list(const char *name)
{
  assert(!string_is_empty(name));
  return channel_is_valid_prefix_char(*name) ? &conf_resv_channels : &conf_resv_nicks;
}

static bool
_conf_resv_is_expired(const struct conf_resv *resv, uintmax_t now)
{
  return resv->expires_at != 0 && resv->expires_at <= now;
}

static bool
_conf_resv_spec_is_valid(const struct conf_resv_spec *spec)
{
  if (spec == NULL || string_is_empty(spec->mask) || spec->reason == NULL ||
      (spec->origin != CONF_RESV_ORIGIN_CONFIG && spec->origin != CONF_RESV_ORIGIN_DATABASE) ||
      (spec->expires_at != 0 && spec->expires_at <= spec->created_at))
    return false;

  if (spec->exemptions)
  {
    const list_node_t *node;
    LIST_FOREACH(node, spec->exemptions->head)
      if (node->data == NULL)
        return false;
  }

  return true;
}

static void
_conf_resv_add_exemptions(struct conf_resv *resv, const list_t *exemptions)
{
  if (exemptions == NULL)
    return;

  const list_node_t *node;
  LIST_FOREACH(node, exemptions->head)
  {
    char *const mask = io_strdup(node->data);
    char nick[NICKLEN + 1];
    char user[USERLEN + 1];
    char host[HOSTLEN + 1];
    struct nuh_split nuh =
    {
      .nuhmask = mask,
      .nickptr = nick,
      .userptr = user,
      .hostptr = host,
      .nicksize = sizeof(nick),
      .usersize = sizeof(user),
      .hostsize = sizeof(host)
    };

    nuh_split(&nuh);
    io_free(mask);

    struct conf_resv_exempt *const exempt = io_calloc(sizeof(*exempt));
    exempt->nick = io_strdup(nick);
    exempt->user = io_strdup(user);
    exempt->host = io_strdup(host);
    address_parse_prefix(exempt->host, &exempt->address, &exempt->prefix_length);
    list_add_tail(exempt, &exempt->node, &resv->exemptions);
  }
}

static struct conf_resv *
_conf_resv_lookup(const char *name, enum conf_resv_lookup_mode mode)
{
  if (string_is_empty(name))
    return NULL;

  const bool exact = mode != CONF_RESV_LOOKUP_MATCH;
  const bool active = mode != CONF_RESV_LOOKUP_EXACT;
  const uintmax_t now = active ? io_time_get(IO_TIME_REALTIME_SEC) : 0;

  const list_node_t *node;
  LIST_FOREACH(node, _conf_resv_list(name)->head)
  {
    struct conf_resv *const resv = node->data;
    if (active && _conf_resv_is_expired(resv, now))
      continue;

    if ((exact ? io_strcasecmp(resv->mask, name) : match(resv->mask, name)) == 0)
      return resv;
  }

  return NULL;
}

static void
_conf_resv_destroy(struct conf_resv *resv)
{
  list_node_t *node;

  while ((node = list_pop_head(&resv->exemptions)))
  {
    struct conf_resv_exempt *const exempt = node->data;
    io_free(exempt->nick);
    io_free(exempt->user);
    io_free(exempt->host);
    io_free(exempt);
  }

  list_remove(&resv->node, _conf_resv_list(resv->mask));
  io_free(resv->mask);
  io_free(resv->reason);
  io_free(resv);
}

const list_t *
conf_resv_channel_get_list(void)
{
  return &conf_resv_channels;
}

const list_t *
conf_resv_nick_get_list(void)
{
  return &conf_resv_nicks;
}

const struct conf_resv *
conf_resv_add(const struct conf_resv_spec *spec)
{
  _conf_resv_assert_mutation_allowed();

  if (!_conf_resv_spec_is_valid(spec))
    return NULL;

  struct conf_resv *const resv = io_calloc(sizeof(*resv));
  resv->mask = io_strdup(spec->mask);
  resv->reason = io_strndup(spec->reason, REASONLEN);
  resv->created_at = spec->created_at;
  resv->expires_at = spec->expires_at;
  resv->origin = spec->origin;
  _conf_resv_add_exemptions(resv, spec->exemptions);
  list_add_tail(resv, &resv->node, _conf_resv_list(resv->mask));

  return resv;
}

const struct conf_resv *
conf_resv_find(const char *name)
{
  return _conf_resv_lookup(name, CONF_RESV_LOOKUP_MATCH);
}

const struct conf_resv *
conf_resv_find_exact(const char *mask)
{
  return _conf_resv_lookup(mask, CONF_RESV_LOOKUP_EXACT);
}

const struct conf_resv *
conf_resv_find_active_exact(const char *mask)
{
  return _conf_resv_lookup(mask, CONF_RESV_LOOKUP_ACTIVE_EXACT);
}

bool
conf_resv_remove_active_exact(const char *mask)
{
  _conf_resv_assert_mutation_allowed();

  struct conf_resv *const resv = _conf_resv_lookup(mask, CONF_RESV_LOOKUP_ACTIVE_EXACT);
  if (resv == NULL)
    return false;

  _conf_resv_destroy(resv);
  return true;
}

bool
conf_resv_exempts_client(const struct conf_resv *resv, const struct Client *client)
{
  assert(resv);
  assert(client);

  const list_node_t *node;
  LIST_FOREACH(node, resv->exemptions.head)
  {
    const struct conf_resv_exempt *const exempt = node->data;
    if (match(exempt->nick, client->name) || match(exempt->user, client->username))
      continue;

    if (address_is_ipv4(&exempt->address) || address_is_ipv6(&exempt->address))
    {
      if (address_match_prefix(&client->addr, &exempt->address, exempt->prefix_length))
        return true;
    }
    else if (match(exempt->host, client->realhost) == 0 ||
             match(exempt->host, client->sockhost) == 0 || match(exempt->host, client->host) == 0)
      return true;
  }

  return false;
}

void
conf_resv_clear_configuration(void)
{
  _conf_resv_assert_mutation_allowed();

  list_t *const lists[] = { &conf_resv_channels, &conf_resv_nicks };
  for (size_t i = 0; i < IO_ARRAY_LENGTH(lists); ++i)
  {
    list_node_t *node, *node_next;
    LIST_FOREACH_SAFE(node, node_next, lists[i]->head)
    {
      struct conf_resv *const resv = node->data;
      if (resv->origin == CONF_RESV_ORIGIN_CONFIG)
        _conf_resv_destroy(resv);
    }
  }
}

void
conf_resv_expire(uintmax_t now, conf_resv_expire_callback_fn callback, void *callback_ctx)
{
  _conf_resv_assert_mutation_allowed();

  list_t *const lists[] = { &conf_resv_channels, &conf_resv_nicks };
  for (size_t i = 0; i < IO_ARRAY_LENGTH(lists); ++i)
  {
    list_node_t *node, *node_next;
    LIST_FOREACH_SAFE(node, node_next, lists[i]->head)
    {
      struct conf_resv *const resv = node->data;
      if (!_conf_resv_is_expired(resv, now))
        continue;

      if (callback)
      {
#ifndef NDEBUG
        assert(!conf_resv_expire_callback_active);
        conf_resv_expire_callback_active = true;
#endif
        callback(resv, callback_ctx);
#ifndef NDEBUG
        assert(conf_resv_expire_callback_active);
        conf_resv_expire_callback_active = false;
#endif
      }

      _conf_resv_destroy(resv);
    }
  }
}
