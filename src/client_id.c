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
 * @file client_id.c
 * @brief Contains functions pertaining to SID/UID generation and validation.
 */

#include "io_string.h"

#include "stdinc.h"
#include "client.h"
#include "client_id.h"


struct ClientIdGenerator
{
  char next_uid[CLIENT_ID_UID_LENGTH + 1];
  bool initialized;
  bool exhausted;
};

static struct ClientIdGenerator client_id_generator;

static bool
_client_id_is_valid_char(const char ch)
{
  return IsUpper(ch) || IsDigit(ch);
}

static bool
_client_id_is_valid(const char *id, size_t length)
{
  assert(!string_is_empty(id));

  if (strlen(id) != length)
    return false;

  if (!IsDigit(id[0]))
    return false;

  for (size_t i = 1; i < length; ++i)
    if (!_client_id_is_valid_char(id[i]))
      return false;

  return true;
}

bool
client_id_is_valid_sid(const char *sid)
{
  return _client_id_is_valid(sid, CLIENT_ID_SID_LENGTH);
}

bool
client_id_is_valid_uid(const char *uid)
{
  return _client_id_is_valid(uid, CLIENT_ID_UID_LENGTH);
}

bool
client_id_has_valid_sid(const struct Client *client)
{
  assert(client);

  if (string_is_empty(client->id))
    return false;
  return client_id_is_valid_sid(client->id);
}

bool
client_id_has_valid_uid(const struct Client *client)
{
  assert(client);

  if (string_is_empty(client->id))
    return false;
  return client_id_is_valid_uid(client->id);
}

static void
_client_id_generate_sid(const char *server_name, const char *server_description, char sid[CLIENT_ID_SID_LENGTH + 1])
{
  assert(!string_is_empty(server_name));
  assert(!string_is_empty(server_description));
  assert(sid);

  uint32_t hash = 0;

  for (const char *p = server_name; *p; ++p)
    hash = 5 * hash + (unsigned char)*p;
  for (const char *p = server_description; *p; ++p)
    hash = 5 * hash + (unsigned char)*p;

  snprintf(sid, CLIENT_ID_SID_LENGTH + 1, "%03u", hash % 1000U);
  assert(client_id_is_valid_sid(sid));
}

bool
client_id_set_server_sid(struct Client *client, const char *configured_sid, const char *server_name,
                         const char *server_description, bool *generated)
{
  assert(client);
  assert(sizeof(client->id) >= CLIENT_ID_SID_LENGTH + 1);

  if (generated)
    *generated = false;

  /* A configured SID takes precedence. */
  if (!string_is_empty(configured_sid))
  {
    if (!client_id_is_valid_sid(configured_sid))
      return false;

    strlcpy(client->id, configured_sid, sizeof(client->id));
    return true;
  }

  _client_id_generate_sid(server_name, server_description, client->id);

  if (generated)
    *generated = true;

  return true;
}

static bool
_client_id_generator_init(struct ClientIdGenerator *generator, const char *sid)
{
  assert(generator);
  assert(!string_is_empty(sid));

  if (!client_id_is_valid_sid(sid))
    return false;

  memcpy(generator->next_uid, sid, CLIENT_ID_SID_LENGTH);

  for (size_t i = CLIENT_ID_SID_LENGTH; i < CLIENT_ID_UID_LENGTH; ++i)
    generator->next_uid[i] = 'A';

  generator->next_uid[CLIENT_ID_UID_LENGTH] = '\0';
  generator->initialized = true;
  generator->exhausted = false;
  return true;
}

bool
client_id_init_generator(const struct Client *server)
{
  assert(server);

  if (!client_id_has_valid_sid(server))
    return false;

  return _client_id_generator_init(&client_id_generator, server->id);
}

static bool
_client_id_generator_advance(char uid[CLIENT_ID_UID_LENGTH + 1])
{
  assert(uid);

  /*
   * Suffix order is:
   *   A-Z, 0-9
   *
   * A carry occurs only when a digit rolls over from '9' back to 'A'.
   * If we carry past the leftmost suffix character, the generator is
   * exhausted and no further UIDs are available.
   */
  for (size_t i = CLIENT_ID_UID_LENGTH; i-- > CLIENT_ID_SID_LENGTH; )
  {
    if (uid[i] >= 'A' && uid[i] < 'Z')
    {
      ++uid[i];
      return true;
    }

    if (uid[i] == 'Z')
    {
      uid[i] = '0';
      return true;
    }

    if (uid[i] >= '0' && uid[i] < '9')
    {
      ++uid[i];
      return true;
    }

    if (uid[i] == '9')
    {
      uid[i] = 'A';
      continue;
    }

    return false;
  }

  return false;
}

static bool
_client_id_generator_next(struct ClientIdGenerator *generator, char uid[CLIENT_ID_UID_LENGTH + 1])
{
  assert(generator);
  assert(uid);

  if (generator->initialized == false || generator->exhausted)
    return false;

  memcpy(uid, generator->next_uid, CLIENT_ID_UID_LENGTH + 1);

  if (!_client_id_generator_advance(generator->next_uid))
    generator->exhausted = true;

  return true;
}

bool
client_id_set_next_uid(struct Client *client)
{
  assert(client);
  assert(sizeof(client->id) >= CLIENT_ID_UID_LENGTH + 1);
  return _client_id_generator_next(&client_id_generator, client->id);
}
