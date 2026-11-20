/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file user.h
 * \brief A header for the user functions.
 */

#ifndef INCLUDED_user_h
#define INCLUDED_user_h

#include <stdbool.h>
#include <stdint.h>

struct Client;

typedef enum
{
  USER_NICK_CHANGE_ORIGIN_NICK,
  USER_NICK_CHANGE_ORIGIN_SVSNICK
} user_nick_change_origin_t;


extern void show_lusers(struct Client *);
extern void user_change_nick(struct Client *, const char *, uintmax_t, user_nick_change_origin_t);
extern void user_register_local(struct Client *);
extern void user_register_remote(struct Client *);
extern void user_set_hostmask(struct Client *, const char *, bool);
extern bool user_account_is_valid(const char *);
extern bool user_set_account(struct Client *, const char *);
extern bool hostname_is_valid(const char *);
extern bool username_is_valid(const char *, bool);
extern bool nickname_is_valid(const char *, bool);
#endif  /* INCLUDED_user_h */
