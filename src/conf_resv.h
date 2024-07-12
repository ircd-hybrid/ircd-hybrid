/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2024 ircd-hybrid development team
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

/*! \file conf_resv.h
 * \brief A header for the RESV functions.
 */

#ifndef INCLUDED_conf_resv_h
#define INCLUDED_conf_resv_h

struct ResvItem
{
  list_node_t node;
  list_t *list;
  list_t exempt_list;
  char *mask;
  char *reason;
  uintmax_t expire;
  uintmax_t setat;
  bool in_database;
};

struct ResvExemptItem
{
  list_node_t node;
  char *name;
  char *user;
  char *host;
  struct io_addr addr;
  int bits;
  int type;
};

extern void resv_delete(struct ResvItem *, bool);
extern void resv_clear(void);
extern void resv_expire(void);
extern bool resv_exempt_find(const struct Client *, const struct ResvItem *);
extern struct ResvItem *resv_make(const char *, const char *, const list_t *);
extern struct ResvItem *resv_find(const char *, int (*)(const char *, const char *));
extern const list_t *resv_chan_get_list(void);
extern const list_t *resv_nick_get_list(void);
#endif  /* INCLUDED_conf_resv_h */
