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

/*! \file server_capab.h
 * \brief A header for the server CAPAB functions.
 */

#ifndef INCLUDED_server_capab_h
#define INCLUDED_server_capab_h

/** Server capability flags */
enum
{
  CAPAB_EOB     = 1 <<  0,  /**< Can do EOB message */
  CAPAB_KLN     = 1 <<  1,  /**< Can do KLINE message */
  CAPAB_KNOCK   = 1 <<  2,  /**< Supports KNOCK */
  CAPAB_UNKLN   = 1 <<  3,  /**< Can do UNKLINE message */
  CAPAB_CLUSTER = 1 <<  4,  /**< Supports server clustering */
  CAPAB_ENCAP   = 1 <<  5,  /**< Supports ENCAP message */
  CAPAB_TBURST  = 1 <<  6,  /**< Supports TBURST */
  CAPAB_DLN     = 1 <<  7,  /**< Can do DLINE message */
  CAPAB_UNDLN   = 1 <<  8,  /**< Can do UNDLINE message */
  CAPAB_RHOST   = 1 <<  9,  /**< Can do extended realhost UID messages */
  CAPAB_QOP     = 1 << 10,  /**< Server supports the owner (~) channel prefix mode */
  CAPAB_AOP     = 1 << 11,  /**< Server supports the admin (&) channel prefix mode */
  CAPAB_HOP     = 1 << 12,  /**< Server supports the half-op (%) channel prefix mode */
  CAPAB_RESYNC  = 1 << 13,  /**< Can do RESYNC message */
  CAPAB_MLOCK   = 1 << 14,  /**< Supports mode locking (MLOCK) */
};

/*
 * Capability macros.
 */
#define IsCapable(x, cap)   ((x)->connection->capab &   (cap))
#define SetCapable(x, cap)  ((x)->connection->capab |=  (cap))
#define ClearCap(x, cap)    ((x)->connection->capab &= ~(cap))

/** Capability structure. Describes a single server capability. */
struct Capability
{
  dlink_node node;  /**< List node; linked into capab_list */
  char *name;  /**< Name of capability */
  unsigned int cap;  /**< Mask value */
  bool active;  /**< Capability is active on this server and advertized to others */
};

extern void capab_init(void);
extern void capab_add(const char *, unsigned int, bool);
extern void capab_del(const char *);
extern unsigned int capab_find(const char *);
extern const char *capab_get(const void *, bool);
#endif  /* INCLUDED_server_capab_h */
