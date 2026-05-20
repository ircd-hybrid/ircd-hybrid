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
