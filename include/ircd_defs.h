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

/*! \file ircd_defs.h
 * \brief A header for ircd global definitions.
 *
 * This header file defines various global constants and structures used
 * throughout the ircd. It includes size definitions for record entries,
 * adhering to IRC and RFC standards. Modification of the defined constants
 * is discouraged without careful consideration, as they are fundamental
 * to the functioning of the ircd.
 */

#ifndef INCLUDED_ircd_defs_h
#define INCLUDED_ircd_defs_h
#include "stdinc.h"

/**
 * \defgroup ircd_constants IRCd Constants
 * @{
 */

#define IRCD_BUFSIZE    512  /**< Maximum size of IRC message buffer. WARNING: *DON'T* CHANGE THIS!!!! */
#define HOSTLEN         63  /**< Length of hostname. Updated to comply with RFC 1123. */
#define NICKLEN         30  /**< Maximum size of a nickname that the server will handle. Do not change; configurable in ircd.conf. */
#define USERLEN         10  /**< Maximum size of a username. */
#define ACCOUNTLEN      NICKLEN  /**< Maximum size of an account name, equal to NICKLEN. */
#define PORTNAMELEN     6  /**< Length of port name, e.g., ":31337". */
#define HOSTIPLEN       45  /**< Maximum length of a string representation of an IP address. */

#define PASSWDLEN       128  /**< Maximum length of a password. */
#define IDLEN           12  /**< Maximum length of an identifier. Do not change; not the actual generated length. */
#define REALLEN         50  /**< Maximum size of a real name (GECOS). */
#define CHANNELLEN      50  /**< Maximum size of a channel name. */
#define TOPICLEN        300  /**< Maximum size of a channel topic. Do not change; configurable in ircd.conf. */
#define REASONLEN       260  /**< Maximum size of a kick or ban reason. */
#define KICKLEN         180  /**< Maximum size of a kick message. */
#define AWAYLEN         180  /**< Maximum size of an away message. */
#define KEYLEN          23  /**< Maximum size of a channel key. */

#define MAX_DATE_STRING 32  /**< Maximum string length for a date string. */
#define LOWEST_SAFE_FD  3  /**< Lowest safe file descriptor number; skipping stdin, stdout, and stderr. */

/** @} */

/**
 * @struct irc_ssaddr
 * @brief Structure to handle sockaddr_storage with compatibility for different implementations.
 *
 * This structure provides a consistent interface for sockaddr_storage with compatibility
 * for different implementations that may or may not include the ss_len member.
 */
struct irc_ssaddr
{
  struct sockaddr_storage ss;  /**< Underlying sockaddr_storage structure. */
  unsigned char ss_len;  /**< Length of the sockaddr_storage. */
};
#endif /* INCLUDED_ircd_defs_h */
