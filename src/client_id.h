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
 * @file client_id.h
 * @brief Functions for SID/UID generation and validation.
 *
 * This file contains declarations for functions related to Server ID (SID)
 * and User ID (UID) generation and validation. These functions are
 * essential for managing unique identifiers within the IRC daemon.
 */

#ifndef INCLUDED_client_id_h
#define INCLUDED_client_id_h
#include <stdbool.h>

struct Client;

enum
{
  CLIENT_ID_SID_LENGTH = 3,
  CLIENT_ID_UID_SUFFIX_LENGTH = 6,
  CLIENT_ID_UID_LENGTH = CLIENT_ID_SID_LENGTH + CLIENT_ID_UID_SUFFIX_LENGTH,
};

extern bool client_id_allocate_uid(struct Client *);
extern bool client_id_has_valid_sid(const struct Client *);
extern bool client_id_has_valid_uid(const struct Client *);
extern bool client_id_init_generator(const struct Client *);
extern bool client_id_is_valid_sid(const char *);
extern bool client_id_is_valid_uid(const char *);
extern bool client_id_set_next_uid(struct Client *);
extern bool client_id_set_server_sid(struct Client *, const char *, const char *, const char *, bool *);
#endif  /* INCLUDED_client_id_h */

