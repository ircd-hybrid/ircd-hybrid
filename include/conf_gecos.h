/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1998-2016 ircd-hybrid development team
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

/*! \file conf_gecos.h
 * \brief Implements gecos {} block configuration management.
 * \version $Id$
 */

#ifndef INCLUDED_conf_gecos_h
#define INCLUDED_conf_gecos_h

struct GecosItem
{
  dlink_node node;
  char *mask;
  char *reason;
  uintmax_t expire;
  uintmax_t setat;
  unsigned int in_database;
};

extern const dlink_list *gecos_get_list(void);
extern void gecos_delete(struct GecosItem *);
extern struct GecosItem *gecos_make(void);
extern struct GecosItem *gecos_find(const char *, int (*)(const char *, const char *));
extern void gecos_clear(void);
extern void gecos_expire(void);
#endif  /* INCLUDED_conf_gecos_h */
