/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
extern bool client_id_extract_sid_from_uid(const char *, char[CLIENT_ID_SID_LENGTH + 1]);
extern bool client_id_has_valid_sid(const struct Client *);
extern bool client_id_has_valid_uid(const struct Client *);
extern bool client_id_init_generator(const struct Client *);
extern bool client_id_init_local_server_sid(struct Client *, const char *, const char *, const char *, bool *);
extern bool client_id_is_valid_sid(const char *);
extern bool client_id_is_valid_uid(const char *);
#endif  /* INCLUDED_client_id_h */

