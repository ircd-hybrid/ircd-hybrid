/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/**
 * @file server_capab.h
 * @brief Declarations for server capability functions and structures.
 *
 * This file provides declarations for functions and structures related to server capabilities.
 * Server capabilities represent features or functionalities that a server supports or implements.
 * These capabilities can be used to negotiate and advertise supported features between servers
 * in an Internet Relay Chat (IRC) network.
 */

#ifndef INCLUDED_server_capab_h
#define INCLUDED_server_capab_h

/**
 * @brief Server capability flags.
 *
 * Enumeration representing various server capabilities with corresponding bitmask values.
 */
enum
{
  CAPAB_EOB     = 1 <<  0,  /**< Indicates support for the End of Burst (EOB) message. */
  CAPAB_KLN     = 1 <<  1,  /**< Indicates support for the KLINE message. */
  CAPAB_KNOCK   = 1 <<  2,  /**< Indicates support for the KNOCK command. */
  CAPAB_UNKLN   = 1 <<  3,  /**< Indicates support for the UNKLINE message. */
  CAPAB_CLUSTER = 1 <<  4,  /**< Indicates support for server clustering. */
  CAPAB_ENCAP   = 1 <<  5,  /**< Indicates support for the ENCAP message. */
  CAPAB_TBURST  = 1 <<  6,  /**< Indicates support for TBURST. */
  CAPAB_DLN     = 1 <<  7,  /**< Indicates support for the DLINE message. */
  CAPAB_UNDLN   = 1 <<  8,  /**< Indicates support for the UNDLINE message. */
  CAPAB_RHOST   = 1 <<  9,  /**< Indicates support for extended realhost UID messages. */
  CAPAB_QOP     = 1 << 10,  /**< Indicates support for the owner (~) channel prefix mode (QOP). */
  CAPAB_AOP     = 1 << 11,  /**< Indicates support for the admin (&) channel prefix mode (AOP). */
  CAPAB_HOP     = 1 << 12,  /**< Indicates support for the half-op (%) channel prefix mode (HOP). */
  CAPAB_RESYNC  = 1 << 13,  /**< Indicates support for the RESYNC message. */
  CAPAB_MLOCK   = 1 << 14,  /**< Indicates support for mode locking (MLOCK). */
};

/**
 * @def IsCapable(x, cap)
 * @brief Check if a server is capable of a certain capability.
 * @param x Pointer to the client structure.
 * @param cap Capability flag to check.
 */
#define IsCapable(x, cap)   ((x)->connection->capab &   (cap))

/**
 * @def SetCapable(x, cap)
 * @brief Set a capability for a server.
 * @param x Pointer to the client structure.
 * @param cap Capability flag to set.
 */
#define SetCapable(x, cap)  ((x)->connection->capab |=  (cap))

/**
 * @def ClearCap(x, cap)
 * @brief Clear a capability for a server.
 * @param x Pointer to the client structure.
 * @param cap Capability flag to clear.
 */
#define ClearCap(x, cap)    ((x)->connection->capab &= ~(cap))

/**
 * @struct Capability
 * @brief Describes a single server capability.
 *
 * This structure represents a single server capability. It is used to store
 * information about a specific capability, including its name, bitmask value,
 * and whether it is currently active on the server and advertised to others.
 */
struct Capability
{
  dlink_node node;  /**< List node; linked into capab_list. */
  char *name;  /**< Name of the capability. */
  unsigned int cap;  /**< Bitmask value representing the capability. */
  bool active;  /**< Indicates whether the capability is currently active on this server and advertised to others. */
};

extern void capab_init(void);
extern void capab_add(const char *, unsigned int, bool);
extern void capab_del(const char *);
extern unsigned int capab_find(const char *);
extern const char *capab_get(const void *, bool);
#endif  /* INCLUDED_server_capab_h */
