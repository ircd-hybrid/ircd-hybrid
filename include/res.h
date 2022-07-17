/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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

/*! \file res.h
 * \brief ircd resolver functions
 * \version $Id$
 */

#ifndef INCLUDED_res_h
#define INCLUDED_res_h

typedef void (*dns_callback_fnc)(void *, const struct irc_ssaddr *, const char *, size_t);

extern void resolver_init(void);
extern void restart_resolver(void);
extern void delete_resolver_queries(const void *);
extern void gethost_byname_type(dns_callback_fnc , void *, const char *, int);
extern void gethost_byaddr(dns_callback_fnc, void *, const struct irc_ssaddr *);
#endif  /* INCLUDED_res_h */
