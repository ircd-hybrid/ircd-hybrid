/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2003-2016 ircd-hybrid development team
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

/*! \file userhost.h
 * \brief A header for global user limits.
 * \version $Id$
 */

#ifndef INCLUDED_userhost_h
#define INCLUDED_userhost_h

struct UserHost
{
  struct UserHost *next;
  char host[HOSTIPLEN + 1];
  unsigned int gcount;  /* Global user count on this addr */
  unsigned int lcount;  /* Local user count on this addr */
};

extern void userhost_init(void);
extern void userhost_count(const char *, unsigned int *, unsigned int *);
extern void userhost_add(const char *, int);
extern void userhost_del(const char *, int);
#endif  /* INCLUDED_userhost_h */
