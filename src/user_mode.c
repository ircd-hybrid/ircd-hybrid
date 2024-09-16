/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2024-2024 ircd-hybrid development team
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


#include "stdinc.h"
#include "irc_string.h"
#include "memory.h"
#include "client.h"
#include "send.h"
#include "user_mode.h"

#define USER_MODE_CAPACITY 52

static struct UserMode *user_mode_table[USER_MODE_CAPACITY];
char user_mode_string[USER_MODE_CAPACITY + 1];

static uint64_t
user_mode_char_to_bit(char mode_char)
{
  if (mode_char >= 'a' && mode_char <= 'z')
    return 1ULL << (mode_char - 'a');
  if (mode_char >= 'A' && mode_char <= 'Z')
    return 1ULL << (mode_char - 'A' + 26);

  return 0;
}

static int
user_mode_char_to_index(char mode_char)
{
  if (mode_char >= 'a' && mode_char <= 'z')
    return mode_char - 'a';
  if (mode_char >= 'A' && mode_char <= 'Z')
    return mode_char - 'A' + 26;

  return -1;
}

static void
user_mode_add_char(char mode_char)
{
  size_t len = strlen(user_mode_string);
  if (len >= USER_MODE_CAPACITY)
    return;

  /* Insert the character in alphabetical order. */
  size_t i;
  for (i = 0; i < len; ++i)
    if (user_mode_string[i] > mode_char)
      break;  /* Found the insertion point. */

  /* Shift the rest of the string to the right to make space. */
  memmove(&user_mode_string[i + 1], &user_mode_string[i], len - i + 1);
  user_mode_string[i] = mode_char;  /* Insert the mode character. */
}

static void
user_mode_remove_char(char mode_char)
{
  char *const pos = strchr(user_mode_string, mode_char);
  if (pos)
    /* Move the rest of the string left to overwrite the character. */
    memmove(pos, pos + 1, strlen(pos));
}

struct UserMode *
user_mode_find(char mode_char)
{
  int index = user_mode_char_to_index(mode_char);
  if (index < 0)
    return NULL;

  return user_mode_table[index];
}

user_mode_result_t
user_mode_register(struct UserMode *mode)
{
  int index = user_mode_char_to_index(mode->mode_char);
  if (index < 0)
    return USER_MODE_RESULT_INVALID_CHAR;

  if (user_mode_table[index])
    return USER_MODE_RESULT_MODE_ALREADY_EXISTS;

  mode->mode_bit = user_mode_char_to_bit(mode->mode_char);
  if (mode->mode_bit == 0)
    return USER_MODE_RESULT_INVALID_CHAR;

  if (mode->mode_flag)
    *(mode->mode_flag) = mode->mode_bit;

  user_mode_add_char(mode->mode_char);

  struct UserMode *mode_new = io_calloc(sizeof(*mode_new));
  *mode_new = *mode;
  user_mode_table[index] = mode_new;

  return USER_MODE_SUCCESS;
}

user_mode_result_t
user_mode_unregister(struct UserMode *mode)
{
  int index = user_mode_char_to_index(mode->mode_char);
  if (index < 0)
    return USER_MODE_RESULT_INVALID_CHAR;

  if (user_mode_table[index] == NULL)
    return USER_MODE_RESULT_MODE_NOT_FOUND;

  if (mode->mode_flag)
    *(mode->mode_flag) = 0;

  user_mode_remove_char(mode->mode_char);

  io_free(user_mode_table[index]);
  user_mode_table[index] = NULL;

  return USER_MODE_SUCCESS;
}

uint64_t
user_mode_get_oper_only(void)
{
  uint64_t mode_flags = 0;

  for (unsigned int i = 0; i < USER_MODE_CAPACITY; ++i)
  {
    const struct UserMode *mode = user_mode_table[i];
    if (mode && (mode->policy & USER_MODE_POLICY_OPER_ONLY))
      mode_flags |= mode->mode_bit;
  }

  return mode_flags;
}

uint64_t
user_mode_string_to_flags(const char *mode_string)
{
  uint64_t mode_flags = 0;

  if (EmptyString(mode_string))
    return 0;

  if (*mode_string == '+')
    ++mode_string;

  for (const char *m = mode_string; *m; ++m)
  {
    int index = user_mode_char_to_index(*m);
    if (index >= 0)
    {
      const struct UserMode *mode = user_mode_table[index];
      if (mode)
      {
        if (!(mode->policy & (USER_MODE_POLICY_INTERNAL_ONLY |
                              USER_MODE_POLICY_SERVICE_ONLY |
                              USER_MODE_POLICY_MANUAL_ONLY)))
          mode_flags |= mode->mode_bit;
      }
    }
  }

  return mode_flags;
}

static bool
user_mode_check_policy(const struct UserMode *mode, const struct Client *client, user_mode_source_t source, user_mode_action_t action)
{
  if (mode->policy & USER_MODE_POLICY_INTERNAL_ONLY)
    return false;

  if (action == USER_MODE_ACTION_ADD)
    if ((mode->policy & USER_MODE_POLICY_OPER_ONLY) && source != USER_MODE_SOURCE_SVSMODE)
      if (MyConnect(client) && user_mode_has_flag(client, UMODE_OPER) == false)
        return false;

  if ((mode->policy & USER_MODE_POLICY_SERVICE_ONLY) && source != USER_MODE_SOURCE_SVSMODE)
    return false;

  return true;
}

user_mode_result_t
user_mode_change(struct Client *client, char mode_char, user_mode_source_t source, user_mode_action_t action)
{
  struct UserMode *mode = user_mode_find(mode_char);
  if (mode == NULL)
    return USER_MODE_RESULT_MODE_NOT_FOUND;

  if (user_mode_check_policy(mode, client, source, action) == false)
    return USER_MODE_RESULT_POLICY_VIOLATION;

  switch (action)
  {
    case USER_MODE_ACTION_ADD:
      if (mode->set_callback && mode->set_callback(client, source) == false)
        return USER_MODE_RESULT_CALLBACK_FAILED;

      user_mode_set_flag(client, mode->mode_bit);
      break;
    case USER_MODE_ACTION_DEL:
      if (mode->unset_callback && mode->unset_callback(client, source) == false)
        return USER_MODE_RESULT_CALLBACK_FAILED;

      user_mode_unset_flag(client, mode->mode_bit);
      break;
    default:
      abort();  /* Invalid action, abort the program. */
  }

  return USER_MODE_SUCCESS;
}

user_mode_result_t
user_mode_set(struct Client *client, char mode_char, user_mode_source_t source)
{
  struct UserMode *mode = user_mode_find(mode_char);
  if (mode == NULL)
    return USER_MODE_RESULT_MODE_NOT_FOUND;

  if (user_mode_check_policy(mode, client, source, USER_MODE_ACTION_ADD) == false)
    return USER_MODE_RESULT_POLICY_VIOLATION;

  if (mode->set_callback && mode->set_callback(client, source) == false)
    return USER_MODE_RESULT_CALLBACK_FAILED;

  user_mode_set_flag(client, mode->mode_bit);
  return USER_MODE_SUCCESS;
}

user_mode_result_t
user_mode_unset(struct Client *client, char mode_char, user_mode_source_t source)
{
  struct UserMode *mode = user_mode_find(mode_char);
  if (mode == NULL)
    return USER_MODE_RESULT_MODE_NOT_FOUND;

  if (user_mode_check_policy(mode, client, source, USER_MODE_ACTION_DEL) == false)
    return USER_MODE_RESULT_POLICY_VIOLATION;

  if (mode->unset_callback && mode->unset_callback(client, source) == false)
    return USER_MODE_RESULT_CALLBACK_FAILED;

  user_mode_unset_flag(client, mode->mode_bit);
  return USER_MODE_SUCCESS;
}

bool
user_mode_has(const struct Client *client, char mode_char)
{
  uint64_t mode_bit = user_mode_char_to_bit(mode_char);
  return (client->umodes & mode_bit) != 0;
}

bool
user_mode_set_flag(struct Client *client, uint64_t mode_flag)
{
  if (mode_flag == 0)
    return false;

  client->umodes |= mode_flag;
  return true;
}

bool
user_mode_set_flag_exec(struct Client *client, uint64_t mode_flag, user_mode_source_t source)
{
  bool success = true;

  if (mode_flag == 0)
    return false;

  for (unsigned int i = 0; i < USER_MODE_CAPACITY; ++i)
  {
    const uint64_t mode_bit = 1ULL << i;
    if (mode_flag & mode_bit)
    {
      const struct UserMode *mode = user_mode_table[i];
      if (mode == NULL)
        continue;

      if (mode->set_callback && mode->set_callback(client, source) == false)
      {
        success = false;
        continue;
      }

      client->umodes |= mode->mode_bit;
    }
  }

  return success;
}

bool
user_mode_unset_flag_exec(struct Client *client, uint64_t mode_flag, user_mode_source_t source)
{
  bool success = true;

  if (mode_flag == 0)
    return false;

  for (unsigned int i = 0; i < USER_MODE_CAPACITY; ++i)
  {
    const uint64_t mode_bit = 1ULL << i;
    if (mode_flag & mode_bit)
    {
      const struct UserMode *mode = user_mode_table[i];
      if (mode == NULL)
        continue;

      if (mode->unset_callback && mode->unset_callback(client, source) == false)
      {
        success = false;
        continue;
      }

      client->umodes &= ~mode->mode_bit;
    }
  }

  return success;
}

bool
user_mode_unset_flag(struct Client *client, uint64_t mode_flag)
{
  if (mode_flag == 0)
    return false;

  client->umodes &= ~mode_flag;
  return true;
}

bool
user_mode_has_flag(const struct Client *client, uint64_t mode_flag)
{
  return (client->umodes & mode_flag) != 0;
}

bool
user_mode_set_mode(struct Client *client, const struct UserMode *mode)
{
  if (mode == NULL || mode->mode_bit == 0)
    return false;

  client->umodes |= mode->mode_bit;
  return true;
}

bool
user_mode_set_mode_exec(struct Client *client, const struct UserMode *mode, user_mode_source_t source)
{
  if (mode == NULL || mode->mode_bit == 0)
    return false;

  if (mode->set_callback && mode->set_callback(client, source) == false)
    return false;

  client->umodes |= mode->mode_bit;
  return true;
}

bool
user_mode_unset_mode(struct Client *client, const struct UserMode *mode)
{
  if (mode == NULL || mode->mode_bit == 0)
    return false;

  client->umodes &= ~mode->mode_bit;
  return true;
}

bool
user_mode_unset_mode_exec(struct Client *client, const struct UserMode *mode, user_mode_source_t source)
{
  if (mode == NULL || mode->mode_bit == 0)
    return false;

  if (mode->unset_callback && mode->unset_callback(client, source) == false)
    return false;

  client->umodes &= ~mode->mode_bit;
  return true;
}

bool
user_mode_has_mode(const struct Client *client, const struct UserMode *mode)
{
  if (mode == NULL)
    return false;

  return (client->umodes & mode->mode_bit) != 0;
}

static uint64_t
user_mode_purge_invalid(struct Client *client)
{
  for (unsigned int i = 0; i < USER_MODE_CAPACITY; ++i)
  {
    const uint64_t mode_bit = 1ULL << i;
    if (user_mode_has_flag(client, mode_bit))
      if (user_mode_table[i] == NULL)
        user_mode_unset_flag(client, mode_bit);
  }

  return client->umodes;
}

void
user_mode_send_invalid(void)
{
  list_node_t *node;

  LIST_FOREACH(node, local_client_list.head)
  {
    struct Client *client = node->data;
    const uint64_t mode_flags_old = client->umodes;
    if (mode_flags_old != user_mode_purge_invalid(client))
      user_mode_send(client, mode_flags_old, USER_MODE_SEND_CLIENT | USER_MODE_SEND_SERVER);
  }
}

void
user_mode_send(struct Client *client, uint64_t mode_flags_old, user_mode_send_t send)
{
  /*
   * If the client's current user modes match the old modes, indicating no change,
   * simply return without further processing.
   */
  const uint64_t changed_modes = client->umodes ^ mode_flags_old;
  if (changed_modes == 0)
    return;

  char buf_add[USER_MODE_CAPACITY + 2];  /* +2 for the '+' and the '\0'. */
  char buf_del[USER_MODE_CAPACITY + 2];  /* +2 for the '-' and the '\0'. */
  char *bufptr_add = buf_add;
  char *bufptr_del = buf_del;

  for (unsigned int i = 0; i < USER_MODE_CAPACITY; ++i)
  {
    const uint64_t mode_bit = 1ULL << i;
    if (changed_modes & mode_bit)
    {
      const char mode_char = (i < 26) ? ('a' + i) : ('A' + (i - 26));

      if (user_mode_has_flag(client, mode_bit))
      {
        if (bufptr_add == buf_add)
          *bufptr_add++ = '+';
        *bufptr_add++ = mode_char;
      }
      else if (mode_flags_old & mode_bit)
      {
        if (bufptr_del == buf_del)
          *bufptr_del++ = '-';
        *bufptr_del++ = mode_char;
      }
    }
  }

  *bufptr_add = '\0';
  *bufptr_del = '\0';

  assert(buf_add[0] != '\0' || buf_del[0] != '\0');

  if (send & USER_MODE_SEND_CLIENT)
    sendto_one(client, ":%s!%s@%s MODE %s :%s%s",
               client->name, client->username, client->host, client->name, buf_add, buf_del);
  if (send & USER_MODE_SEND_SERVER)
    sendto_servers(client, 0, 0, ":%s MODE %s :%s%s",
                   client->id, client->id, buf_add, buf_del);
}

const char *
user_mode_to_str(uint64_t mode_flags)
{
  static char buf[USER_MODE_CAPACITY + 2];  /* +2 for the '+' and the '\0'. */
  char *bufptr = buf;

  *bufptr++ = '+';

  for (unsigned int i = 0; i < USER_MODE_CAPACITY; ++i)
  {
    const uint64_t mode_bit = 1ULL << i;
    if (mode_flags & mode_bit)
      *bufptr++ = (i < 26) ? ('a' + i) : ('A' + (i - 26));
  }

  *bufptr = '\0';
  return buf;
}
