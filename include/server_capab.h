/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2020 ircd-hybrid development team
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

/*! \file server_capab.h
 * \brief A header for the server CAPAB functions.
 * \version $Id$
 */

#ifndef INCLUDED_server_capab_h
#define INCLUDED_server_capab_h

/** Server capability flags */
enum
{
  CAPAB_QS      = 1 <<  0,  /**< Can handle quit storm removal */
  CAPAB_EOB     = 1 <<  1,  /**< Can do EOB message */
  CAPAB_KLN     = 1 <<  2,  /**< Can do KLINE message */
  CAPAB_KNOCK   = 1 <<  3,  /**< Supports KNOCK */
  CAPAB_UNKLN   = 1 <<  4,  /**< Can do UNKLINE message */
  CAPAB_CLUSTER = 1 <<  5,  /**< Supports server clustering */
  CAPAB_ENCAP   = 1 <<  6,  /**< Supports ENCAP message */
  CAPAB_TBURST  = 1 <<  7,  /**< Supports TBURST */
  CAPAB_DLN     = 1 <<  8,  /**< Can do DLINE message */
  CAPAB_UNDLN   = 1 <<  9,  /**< Can do UNDLINE message */
  CAPAB_RHOST   = 1 << 10   /**< Can do extended realhost UID messages */
};

/*
 * Capability macros.
 */
#define IsCapable(x, cap)   ((x)->connection->caps &   (cap))
#define SetCapable(x, cap)  ((x)->connection->caps |=  (cap))
#define ClearCap(x, cap)    ((x)->connection->caps &= ~(cap))

/* Capabilities */
struct Capability
{
  dlink_node node;  /**< List node; linked into capab_list */
  char *name;  /**< Name of capability */
  unsigned int cap;  /**< Mask value */
};

extern void capab_init(void);
extern void capab_add(const char *, unsigned int);
extern void capab_del(const char *);
extern unsigned int capab_find(const char *);
extern const char *capab_get(const void *);
#endif  /* INCLUDED_server_capab_h */
