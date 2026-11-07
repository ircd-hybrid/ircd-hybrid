/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file client_id.c
 * @brief Contains functions pertaining to SID/UID generation and validation.
 */

#include <assert.h>
#include <string.h>

#include "io_string.h"

#include "client.h"
#include "client_id.h"
#include "client_find.h"

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
_client_id_is_valid_char(unsigned char ch)
{
  return io_ascii_is_upper(ch) || io_ascii_is_digit(ch);
}

static bool
_client_id_is_valid(const char *id, size_t length)
{
  assert(length == CLIENT_ID_SID_LENGTH || length == CLIENT_ID_UID_LENGTH);

  if (id == NULL)
    return false;

  /* Per TS6 specification, the first character must always be a digit. */
  if (!io_ascii_is_digit(id[0]))
    return false;

  for (size_t i = 1; i < length; ++i)
    if (!_client_id_is_valid_char(id[i]))
      return false;

  return id[length] == '\0';
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
  return client_id_is_valid_sid(client->id);
}

bool
client_id_has_valid_uid(const struct Client *client)
{
  assert(client);
  return client_id_is_valid_uid(client->id);
}

bool
client_id_extract_sid_from_uid(const char *uid, char sid[CLIENT_ID_SID_LENGTH + 1])
{
  assert(sid);

  if (!client_id_is_valid_uid(uid))
    return false;

  memcpy(sid, uid, CLIENT_ID_SID_LENGTH);
  sid[CLIENT_ID_SID_LENGTH] = '\0';

  return true;
}

bool
client_id_set_local_sid(struct Client *client, const char *sid)
{
  if (client == NULL || !string_is_empty(client->id))
    return false;

  if (!client_id_is_valid_sid(sid))
    return false;

  memcpy(client->id, sid, CLIENT_ID_SID_LENGTH + 1);
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
  assert(client_id_generator.initialized == false);

  if (!client_id_has_valid_sid(server))
    return false;

  return _client_id_generator_init(&client_id_generator, server->id);
}

static bool
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
      return true;
    }

    if (*ch == 'Z')
    {
      *ch = '0';
      return true;
    }

    if (*ch >= '0' && *ch < '9')
    {
      ++*ch;
      return true;
    }

    if (*ch == '9')
    {
      *ch = 'A';
      continue;
    }

    assert(!"invalid local UID generator state");
    return false;
  }

  return true;
}

static bool
_client_id_generator_next(struct ClientIdGenerator *generator, char uid[CLIENT_ID_UID_LENGTH + 1])
{
  assert(generator);
  assert(uid);

  if (generator->initialized == false)
    return false;

  assert(client_id_is_valid_uid(generator->next_uid));

  /* Return the current UID, then advance the generator state. */
  memcpy(uid, generator->next_uid, CLIENT_ID_UID_LENGTH + 1);
  return _client_id_generator_advance(generator);
}

bool
client_id_allocate_uid(struct Client *client)
{
  assert(client);
  assert(string_is_empty(client->id));

  char uid[CLIENT_ID_UID_LENGTH + 1];
  char first_colliding_uid[CLIENT_ID_UID_LENGTH + 1] = "";

  for (;;)
  {
    if (!_client_id_generator_next(&client_id_generator, uid))
      return false;

    /* Verify the generated UID is not currently in use by an active client. */
    if (client_find_entity_by_id(uid) == NULL)
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
