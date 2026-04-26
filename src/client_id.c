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

#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "io_string.h"

#include "client.h"
#include "client_id.h"
#include "hash.h"

_Static_assert(CLIENT_ID_SID_LENGTH == 3, "CLIENT_ID_SID_LENGTH must be 3");
_Static_assert(CLIENT_ID_UID_LENGTH == 9, "CLIENT_ID_UID_LENGTH must be 9");
_Static_assert(CLIENT_ID_UID_LENGTH == CLIENT_ID_SID_LENGTH + CLIENT_ID_UID_SUFFIX_LENGTH,
               "CLIENT_ID_UID_LENGTH must equal SID length plus UID suffix length");
_Static_assert(sizeof(((struct Client *)0)->id) >= CLIENT_ID_UID_LENGTH + 1,
               "struct Client.id is too small for a full UID plus terminator");

struct ClientIdGenerator
{
  char next_uid[CLIENT_ID_UID_LENGTH + 1];
  bool initialized;
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

  /* Per TS6 specification, the first character must always be a digit. */
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

static uint32_t
_client_id_hash_djb2_update(uint32_t hash, const char *str)
{
  assert(!string_is_empty(str));

  for (const unsigned char *p = (const unsigned char *)str; *p; ++p)
    hash = ((hash << 5) + hash) + *p;  /* hash * 33 + byte */

  return hash;
}

static uint32_t
_client_id_hash_djb2_update_byte(uint32_t hash, unsigned char byte)
{
  return ((hash << 5) + hash) + byte;  /* hash * 33 + byte */
}

static void
_client_id_generate_sid(const char *server_name, const char *server_description, char sid[CLIENT_ID_SID_LENGTH + 1])
{
  static const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  assert(!string_is_empty(server_name));
  assert(!string_is_empty(server_description));
  assert(sid);

  uint32_t hash = 5381U;
  hash = _client_id_hash_djb2_update(hash, server_name);

  /*
   * Hash an explicit separator so the pair
   *   ("ab", "c")
   * does not collide with
   *   ("a", "bc").
   */
  hash = _client_id_hash_djb2_update_byte(hash, 0);
  hash = _client_id_hash_djb2_update(hash, server_description);

  /*
   * The valid SID space is:
   *   [0-9][A-Z0-9][A-Z0-9]
   *
   * This gives 10 * 36 * 36 distinct values.
   */
  uint32_t value = hash % (10U * 36U * 36U);
  sid[0] = '0' + (value / (36U * 36U));
  value %= (36U * 36U);
  sid[1] = alphabet[value / 36U];
  sid[2] = alphabet[value % 36U];
  sid[3] = '\0';

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

static void
_client_id_generator_advance(struct ClientIdGenerator *generator)
{
  assert(generator);
  assert(generator->initialized);

  /*
   * Suffix order is:
   *   A-Z, 0-9
   *
   * Advance from right to left. A carry occurs only when a suffix character
   * rolls over from '9' back to 'A'. If every suffix character is already
   * '9', the generator wraps from "<SID>999999" back to "<SID>AAAAAA".
   */
  for (size_t i = CLIENT_ID_UID_LENGTH; i-- > CLIENT_ID_SID_LENGTH; )
  {
    char *const ch = &generator->next_uid[i];
    if (*ch >= 'A' && *ch < 'Z')
    {
      ++*ch;
      return;
    }

    if (*ch == 'Z')
    {
      *ch = '0';
      return;
    }

    if (*ch >= '0' && *ch < '9')
    {
      ++*ch;
      return;
    }

    if (*ch == '9')
    {
      *ch = 'A';
      continue;
    }

    assert(!"invalid local UID generator state");
  }
}

static bool
_client_id_generator_next(struct ClientIdGenerator *generator, char uid[CLIENT_ID_UID_LENGTH + 1])
{
  assert(generator);
  assert(uid);

  if (generator->initialized == false)
    return false;

  /* Return the current UID, then advance the generator state. */
  memcpy(uid, generator->next_uid, CLIENT_ID_UID_LENGTH + 1);
  _client_id_generator_advance(generator);
  return true;
}

bool
client_id_allocate_uid(struct Client *client)
{
  assert(client);

  char uid[CLIENT_ID_UID_LENGTH + 1];
  char first_colliding_uid[CLIENT_ID_UID_LENGTH + 1] = "";

  for (;;)
  {
    if (!_client_id_generator_next(&client_id_generator, uid))
      return false;

    /* Verify the generated UID is not currently in use by an active client. */
    if (hash_find_id(uid) == NULL)
    {
      memcpy(client->id, uid, CLIENT_ID_UID_LENGTH + 1);
      return true;
    }

    /*
     * The local UID generator wraps. If we collide with the same UID again,
     * we have completed a full pass through the namespace without finding a
     * free slot.
     */
    if (first_colliding_uid[0] == '\0')
      memcpy(first_colliding_uid, uid, sizeof(first_colliding_uid));
    else if (strcmp(uid, first_colliding_uid) == 0)
      return false;
  }
}
