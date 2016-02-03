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

/*! \file conf_shared.h
 * \brief Implements shared {} block configuration management.
 * \version $Id$
 */

#ifndef INCLUDED_conf_shared_h
#define INCLUDED_conf_shared_h
#include "stdinc.h"

enum
{
  SHARED_KLINE   = 0x00000001U,
  SHARED_UNKLINE = 0x00000002U,
  SHARED_XLINE   = 0x00000004U,
  SHARED_UNXLINE = 0x00000008U,
  SHARED_RESV    = 0x00000010U,
  SHARED_UNRESV  = 0x00000020U,
  SHARED_LOCOPS  = 0x00000040U,
  SHARED_DLINE   = 0x00000080U,
  SHARED_UNDLINE = 0x00000100U,
  SHARED_REHASH  = 0x00000200U,
  SHARED_ALL     = 0xFFFFFFFFU
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
