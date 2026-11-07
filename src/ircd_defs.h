/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file ircd_defs.h
 * @brief A header for ircd global definitions.
 *
 * This header file defines various global constants and structures used
 * throughout the ircd. It includes size definitions for record entries,
 * adhering to IRC and RFC standards. Modification of the defined constants
 * is discouraged without careful consideration, as they are fundamental
 * to the functioning of the ircd.
 */

#ifndef INCLUDED_ircd_defs_h
#define INCLUDED_ircd_defs_h

/**
 * @defgroup ircd_constants IRCd Constants
 * @{
 */

#define IRCD_BUFSIZE    512  /**< Maximum size of IRC message buffer. WARNING: *DON'T* CHANGE THIS!!!! */
#define HOSTLEN         63  /**< Length of hostname. Updated to comply with RFC 1123. */
#define NICKLEN         30  /**< Maximum size of a nickname that the server will handle. Do not change; configurable in ircd.conf. */
#define USERLEN         10  /**< Maximum size of a username. */
#define ACCOUNTLEN      NICKLEN  /**< Maximum size of an account name, equal to NICKLEN. */
#define HOSTIPLEN       45  /**< Maximum length of a string representation of an IP address. */

#define PASSWDLEN       128  /**< Maximum length of a password. */
#define IDLEN           9  /**< Maximum length of a unique identifier (UID). Do not change. */
#define REALLEN         50  /**< Maximum size of a real name (GECOS). */
#define CHANNELLEN      50  /**< Maximum size of a channel name. */
#define TOPICLEN        300  /**< Maximum size of a channel topic. Do not change; configurable in ircd.conf. */
#define REASONLEN       260  /**< Maximum size of a kick or ban reason. */
#define KICKLEN         180  /**< Maximum size of a kick message. */
#define AWAYLEN         180  /**< Maximum size of an away message. */
#define KEYLEN          23  /**< Maximum size of a channel key. */

/** @} */
#endif /* INCLUDED_ircd_defs_h */
