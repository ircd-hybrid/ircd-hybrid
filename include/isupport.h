/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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

/*! \file isupport.h
 * \brief Contains functions pertaining to RPL_ISUPPORT.
 * \version $Id$
 */

#ifndef INCLUDED_isupport_h
#define INCLUDED_isupport_h

extern void isupport_init(void);
extern void isupport_add(const char *, const char *, int);
extern void isupport_delete(const char *);
extern void isupport_rebuild(void);
extern void isupport_show(struct Client *);

#endif
