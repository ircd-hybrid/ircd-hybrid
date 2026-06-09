/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

/**
 * @file client_format.h
 * @brief Client display formatting helpers.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "io_string.h"

#include "client.h"
#include "client_format.h"

static const char client_format_masked_host_component[] = "<masked>";

static const char *
_client_format_get_entity_name(const struct Client *client)
{
  assert(client);

  if (!string_is_empty(client->name))
    return client->name;

  return "*";
}

static const char *
_client_format_get_host_component(const struct Client *client, client_format_name_t format)
{
  assert(client);

  switch (format)
  {
    case CLIENT_FORMAT_NAME_PUBLIC:
      return client->host;
    case CLIENT_FORMAT_NAME_OPER:
      return client_format_masked_host_component;
    case CLIENT_FORMAT_NAME_ADMIN:
    case CLIENT_FORMAT_NAME_LOG:
      return client->sockhost;
  }

  assert(!"invalid client name format");
  return client->host;
}

static bool
_client_format_uses_user_host(const struct Client *client)
{
  assert(client);
  return client_is_user(client) || client_is_unknown(client);
}

static bool
_client_format_should_omit_host(const struct Client *client, const char *entity_name, const char *host_component)
{
  assert(client);
  assert(entity_name);
  assert(host_component);

  if (_client_format_uses_user_host(client))
    return false;

  if (string_is_empty(host_component))
    return true;

  return io_strcasecmp(entity_name, host_component) == 0;
}

const char *
client_format_name(const struct Client *client, client_format_name_t format, client_format_name_buffer_t *buffer)
{
  assert(client);
  assert(buffer);

  const char *const entity_name = _client_format_get_entity_name(client);

  if (client_is_me(client) || !client_is_local(client))
  {
    strlcpy(buffer->value, entity_name, sizeof(buffer->value));
    return buffer->value;
  }

  const char *const host_component = _client_format_get_host_component(client, format);

  if (_client_format_uses_user_host(client))
    snprintf(buffer->value, sizeof(buffer->value), "%s[%s@%s]",
             entity_name, client->username, host_component);
  else if (_client_format_should_omit_host(client, entity_name, host_component))
    strlcpy(buffer->value, entity_name, sizeof(buffer->value));
  else
    snprintf(buffer->value, sizeof(buffer->value), "%s[%s]",
             entity_name, host_component);

  return buffer->value;
}

static const char *
_client_format_get_oper_source(const struct Client *client)
{
  assert(client);
  assert(client_is_user(client));

  if (client_is_local(client) && !string_is_empty(client->connection->oper_name))
    return client->connection->oper_name;

  assert(client->uplink);
  return _client_format_get_entity_name(client->uplink);
}

const char *
client_format_oper_name(const struct Client *client, client_format_oper_name_buffer_t *buffer)
{
  assert(client);
  assert(buffer);

  const char *const entity_name = _client_format_get_entity_name(client);

  if (client_is_server(client) || client_is_me(client))
  {
    strlcpy(buffer->value, entity_name, sizeof(buffer->value));
    return buffer->value;
  }

  assert(client_is_user(client));
  assert(client_is_oper(client));
  assert(!string_is_empty(client->username));
  assert(!string_is_empty(client->host));

  const char *const oper_source = _client_format_get_oper_source(client);
  snprintf(buffer->value, sizeof(buffer->value), "%s[%s@%s]{%s}",
           entity_name, client->username, client->host, oper_source);

  return buffer->value;
}
