/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file parse.h
 * \brief A header for the message parser.
 */

#ifndef INCLUDED_parse_h
#define INCLUDED_parse_h
#include "client.h"

/** Maximum parameters a command can have. See 2.3 Messages in RFC 1459. */
enum { PARSE_MAX_PARAMETERS = 15 };

extern void parse_message(struct Client *, char *, const char *);
#endif  /* INCLUDED_parse_h */
