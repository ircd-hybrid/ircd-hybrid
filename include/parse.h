/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*! \file parse.h
 * \brief A header for the message parser.
 */

#ifndef INCLUDED_parse_h
#define INCLUDED_parse_h
#include "command.h"

struct Client;


/** Maximum parameters a command can have. See 2.3 Messages in RFC 1459. */
enum { MAXPARA = 15 };

extern void parse_message(struct Client *, char *, char *);

/* generic handlers */
extern void m_ignore(struct Client *, int, char *[]);
extern void m_not_oper(struct Client *, int, char *[]);
extern void m_registered(struct Client *, int, char *[]);
extern void m_unregistered(struct Client *, int, char *[]);
#endif  /* INCLUDED_parse_h */
