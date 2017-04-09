/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2017 ircd-hybrid development team
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
  CAPAB_QS      = 0x00000001U,  /**< Can handle quit storm removal */
  CAPAB_EOB     = 0x00000002U,  /**< Can do EOB message */
  CAPAB_KLN     = 0x00000004U,  /**< Can do KLINE message */
  CAPAB_KNOCK   = 0x00000008U,  /**< Supports KNOCK */
  CAPAB_UNKLN   = 0x00000010U,  /**< Can do UNKLINE message */
  CAPAB_CLUSTER = 0x00000020U,  /**< Supports server clustering */
  CAPAB_ENCAP   = 0x00000040U,  /**< Supports ENCAP message */
  CAPAB_HOPS    = 0x00000080U,  /**< Supports HALFOPS */
  CAPAB_TBURST  = 0x00000100U,  /**< Supports TBURST */
  CAPAB_SVS     = 0x00000200U,  /**< Supports services */
  CAPAB_DLN     = 0x00000400U,  /**< Can do DLINE message */
  CAPAB_UNDLN   = 0x00000800U,  /**< Can do UNDLINE message */
  CAPAB_CHW     = 0x00001000U   /**< Can do channel wall @# */
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
  dlink_node node;
  char *name;  /**< Name of capability */
  unsigned int cap;  /**< Mask value */
};

extern void capab_init(void);
extern void capab_add(const char *, unsigned int);
extern void capab_del(const char *);
extern unsigned int capab_find(const char *);
extern const char *capab_get(const void *);
#endif  /* INCLUDED_server_capab_h */
