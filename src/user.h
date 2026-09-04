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

struct Client;

extern void show_lusers(struct Client *);
extern void user_set_hostmask(struct Client *, const char *, bool);
extern void user_register_local(struct Client *);
extern void user_register_remote(struct Client *);
extern bool valid_hostname(const char *);
extern bool valid_username(const char *, bool);
extern bool nickname_is_valid(const char *, bool);
#endif  /* INCLUDED_user_h */
