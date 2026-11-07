/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file client_format.h
 * @brief Client display formatting helpers.
 */

#ifndef INCLUDED_client_format_h
#define INCLUDED_client_format_h

#include "ircd_defs.h"

struct Client;

typedef enum client_format_name
{
  CLIENT_FORMAT_NAME_PUBLIC,
  CLIENT_FORMAT_NAME_OPER,
  CLIENT_FORMAT_NAME_ADMIN,
  CLIENT_FORMAT_NAME_LOG,
} client_format_name_t;

enum
{
  CLIENT_FORMAT_NAME_HOST_COMPONENT_LENGTH = HOSTLEN > HOSTIPLEN ? HOSTLEN : HOSTIPLEN,
  CLIENT_FORMAT_NAME_BUFFER_LENGTH = HOSTLEN + USERLEN + CLIENT_FORMAT_NAME_HOST_COMPONENT_LENGTH + 4,
  CLIENT_FORMAT_OPER_NAME_BUFFER_LENGTH = IRCD_BUFSIZE
};

typedef struct client_format_name_buffer
{
  char value[CLIENT_FORMAT_NAME_BUFFER_LENGTH];
} client_format_name_buffer_t;

typedef struct client_format_oper_name_buffer
{
  char value[CLIENT_FORMAT_OPER_NAME_BUFFER_LENGTH];
} client_format_oper_name_buffer_t;

extern const char *client_format_name(const struct Client *, client_format_name_t, client_format_name_buffer_t *);
extern const char *client_format_oper_name(const struct Client *, client_format_oper_name_buffer_t *);
#endif  /* INCLUDED_client_format_h */
