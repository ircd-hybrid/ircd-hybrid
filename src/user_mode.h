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

#ifndef INCLUDED_user_mode_h
#define INCLUDED_user_mode_h

struct Client;

typedef enum
{
  USER_MODE_SOURCE_REGULAR,
  USER_MODE_SOURCE_SVSMODE,
} user_mode_source_t;

typedef enum
{
  USER_MODE_ADD,
  USER_MODE_DEL,
} user_mode_action_t;

typedef enum
{
  USER_MODE_POLICY_INTERNAL_ONLY = 1 << 0,
  USER_MODE_POLICY_OPER_ONLY     = 1 << 1,
  USER_MODE_POLICY_MANUAL_ONLY   = 1 << 2,
  USER_MODE_POLICY_SERVICE_ONLY  = 1 << 3,
} user_mode_policy_t;

typedef bool (*user_mode_callback_t)(struct Client *, user_mode_source_t);

struct UserMode
{
  char mode_char;
  uint64_t mode_bit;
  uint64_t *mode_flag;
  user_mode_policy_t policy;
  user_mode_callback_t set_callback;
  user_mode_callback_t unset_callback;
};

extern char user_mode_string[];

extern void user_mode_send(struct Client *, uint64_t, bool, bool);
extern void user_mode_send_invalid(void);
extern bool user_mode_has(const struct Client *, char);
extern bool user_mode_has_flag(const struct Client *, uint64_t);
extern bool user_mode_set_flag(struct Client *, uint64_t);
extern bool user_mode_unset_flag(struct Client *, uint64_t);
extern int user_mode_change(struct Client *, char, user_mode_source_t, user_mode_action_t);
extern int user_mode_register(struct UserMode *);
extern int user_mode_set(struct Client *, char, user_mode_source_t);
extern int user_mode_unregister(struct UserMode *);
extern int user_mode_unset(struct Client *, char, user_mode_source_t);
extern uint64_t user_mode_get_oper_only(void);
extern uint64_t user_mode_string_to_flags(const char *);
extern struct UserMode *user_mode_find(char);
extern const char *user_mode_to_str(uint64_t);
#endif  /* INCLUDED_user_mode_h */
