/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file client_find.c
 * \brief Client lookup helpers for named and ID-addressed entities.
 */

#include <stddef.h>

#include "io_string.h"

#include "client.h"
#include "client_find.h"
#include "client_id.h"
#include "conf.h"
#include "hash.h"
#include "whowas.h"

static bool
_client_find_source_can_lookup_ids(const struct Client *source)
{
  return client_is_server(source->nexthop) || client_is_me(source->nexthop);
}

struct Client *
client_find_user_by_name(const char *name)
{
  if (string_is_empty(name))
    return NULL;

  struct Client *const client = hash_find_client(name);
  if (client && client_is_user(client))
    return client;

  return NULL;
}

struct Client *
client_find_user_by_uid(const char *uid)
{
  if (string_is_empty(uid))
    return NULL;

  struct Client *const client = hash_find_id(uid);
  if (client && client_is_user(client))
    return client;

  return NULL;
}

struct Client *
client_find_server_by_name(const char *name)
{
  if (string_is_empty(name))
    return NULL;

  struct Client *const client = hash_find_client(name);
  if (client && (client_is_server(client) || client_is_me(client)))
    return client;

  return NULL;
}

struct Client *
client_find_server_by_sid(const char *sid)
{
  if (string_is_empty(sid))
    return NULL;

  struct Client *const client = hash_find_id(sid);
  if (client && (client_is_server(client) || client_is_me(client)))
    return client;

  return NULL;
}

struct Client *
client_find_entity_by_name(const char *name)
{
  if (string_is_empty(name))
    return NULL;

  return hash_find_client(name);
}

struct Client *
client_find_entity_by_id(const char *id)
{
  if (string_is_empty(id))
    return NULL;

  return hash_find_id(id);
}

struct Client *
client_find_user(const struct Client *source, const char *token)
{
  if (string_is_empty(token))
    return NULL;

  if (_client_find_source_can_lookup_ids(source) && client_id_is_valid_uid(token))
    return client_find_user_by_uid(token);

  return client_find_user_by_name(token);
}

struct Client *
client_find_user_with_history(const struct Client *source, const char *token, bool *from_history)
{
  if (from_history)
    *from_history = false;

  if (string_is_empty(token))
    return NULL;

  struct Client *client = client_find_user(source, token);
  if (client)
    return client;

  client = whowas_get_history(token, ConfigGeneral.kill_chase_time_limit);
  if (client && from_history)
    *from_history = true;

  return client;
}

struct Client *
client_find_server(const struct Client *source, const char *token)
{
  if (string_is_empty(token))
    return NULL;

  if (_client_find_source_can_lookup_ids(source) && client_id_is_valid_sid(token))
    return client_find_server_by_sid(token);

  return client_find_server_by_name(token);
}

struct Client *
client_find_entity(const struct Client *source, const char *token)
{
  if (string_is_empty(token))
    return NULL;

  if (_client_find_source_can_lookup_ids(source))
  {
    if (client_id_is_valid_uid(token) ||
        client_id_is_valid_sid(token))
      return client_find_entity_by_id(token);
  }

  return client_find_entity_by_name(token);
}
