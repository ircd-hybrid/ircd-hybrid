/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2014-2021 ircd-hybrid development team
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

/*! \file conf_pseudo.h
 * \brief Handles with pseudo commands/service aliases.
 * \version $Id$
 */

#ifndef INCLUDED_conf_pseudo_h
#define INCLUDED_conf_pseudo_h

struct PseudoItem
{
  dlink_node node;
  struct Message msg;
  char *name;
  char *nick;
  char *serv;
  char *prepend;
  char *command;
};

extern const dlink_list *pseudo_get_list(void);
extern void pseudo_register(const char *, const char *, const char *, const char *, const char *);
extern void pseudo_clear(void);
#endif  /* INCLUDED_conf_pseudo_h */
