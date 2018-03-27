/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2018 ircd-hybrid development team
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

/*! \file conf_shared.h
 * \brief Implements shared {} block configuration management.
 * \version $Id$
 */

#ifndef INCLUDED_conf_shared_h
#define INCLUDED_conf_shared_h

enum
{
  SHARED_KLINE   = 1 << 0,
  SHARED_UNKLINE = 1 << 1,
  SHARED_XLINE   = 1 << 2,
  SHARED_UNXLINE = 1 << 3,
  SHARED_RESV    = 1 << 4,
  SHARED_UNRESV  = 1 << 5,
  SHARED_LOCOPS  = 1 << 6,
  SHARED_DLINE   = 1 << 7,
  SHARED_UNDLINE = 1 << 8,
  SHARED_REHASH  = 1 << 9,
  SHARED_ALL     = UINT_MAX
};

struct SharedItem
{
  dlink_node node;
  char *server;
  char *user;
  char *host;
  unsigned int type;
};

extern const dlink_list *shared_get_list(void);
extern void shared_clear(void);
extern struct SharedItem *shared_make(void);
extern const struct SharedItem *shared_find(unsigned int, const char *, const char *, const char *);
#endif
