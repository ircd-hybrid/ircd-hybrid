/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file client_find.h
 * \brief Client lookup helpers for named and ID-addressed entities.
 */

#ifndef INCLUDED_client_find_h
#define INCLUDED_client_find_h
#include <stdbool.h>

struct Client;

extern struct Client *client_find_entity(const struct Client *, const char *);
extern struct Client *client_find_entity_by_id(const char *);
extern struct Client *client_find_entity_by_name(const char *);
extern struct Client *client_find_server(const struct Client *, const char *);
extern struct Client *client_find_server_by_name(const char *);
extern struct Client *client_find_server_by_sid(const char *);
extern struct Client *client_find_user(const struct Client *, const char *);
extern struct Client *client_find_user_by_name(const char *);
extern struct Client *client_find_user_by_uid(const char *);
extern struct Client *client_find_user_with_history(const struct Client *, const char *, bool *);
#endif  /* INCLUDED_client_find_h */
