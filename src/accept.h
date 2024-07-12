/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2024 ircd-hybrid development team
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

#ifndef INCLUDED_accept_h
#define INCLUDED_accept_h

struct AcceptItem
{
  list_node_t node;
  char *nick;
  char *user;
  char *host;
};

extern void accept_add(const char *, const char *, const char *, list_t *);
extern void accept_del(struct AcceptItem *, list_t *);
extern void accept_clear_list(list_t *);
extern bool accept_message(struct Client *, struct Client *);
extern struct AcceptItem *accept_find(const char *, const char *, const char *, list_t *, int (*)(const char *, const char *));
#endif  /* INCLUDED_accept_h */
