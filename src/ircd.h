/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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
 * @file ircd.h
 * @brief Header file for ircd startup routines and server configurations.
 *
 * This header file contains declarations and definitions related to ircd startup routines,
 * server configurations, and various server statistics.
 *
 * @see ircd.c
 */

#ifndef INCLUDED_ircd_h
#define INCLUDED_ircd_h
#include <stdbool.h>
#include <stdint.h>

#include "config.h"  /**< Autotools-generated PACKAGE_NAME & PACKAGE_VERSION. */
#include "event.h"

/**
 * @def IRCD_VERSION
 * @brief Macro representing the ircd version derived from autoconf.
 *
 * This macro holds the version information of the ircd in the format "PACKAGE_NAME-PACKAGE_VERSION",
 * where PACKAGE_NAME and PACKAGE_VERSION are derived from the autoconf configuration process.
 * For example, "ircd-hybrid-8.2.44".
 */
#define IRCD_VERSION PACKAGE_NAME "-" PACKAGE_VERSION

/**
 * @struct SetOptions
 * @brief Structure for server configuration options.
 *
 * This structure holds various options related to server configuration,
 * which can be modified using the SET IRC command.
 */
struct SetOptions
{
  uint32_t autoconnect;  /**< Flag indicating if autoconnect is enabled for all servers. */ /* XXX bool -> m_set.c */
  uint32_t maxclients;  /**< Maximum allowed client connections. */
  uint32_t floodcount;  /**< Number of messages allowed in 'floodtime' seconds. */
  uint32_t floodtime;  /**< Time threshold for flood control. */
  uint32_t joinfloodtime;  /**< Time threshold for join flood control. */
  uint32_t joinfloodcount;  /**< Number of join messages allowed in 'joinfloodtime' seconds. */
  uint32_t spam_num;  /**< Number of spam messages allowed. */
  uint32_t spam_time;  /**< Time threshold for spam control. */
};

/**
 * @struct ServerStatistics
 * @brief Structure for server communication and connection statistics.
 *
 * This structure holds statistics related to server communication and connections.
 * These metrics provide insights into data transmission, connection durations,
 * and various activities between clients and servers.
 */
struct ServerStatistics
{
  uint64_t is_cbs;  /**< Bytes sent to clients. */
  uint64_t is_cbr;  /**< Bytes received from clients. */
  uint64_t is_sbs;  /**< Bytes sent to servers. */
  uint64_t is_sbr;  /**< Bytes received from servers. */
  uint64_t is_cti;  /**< Time spent connected by clients. */
  uint64_t is_sti;  /**< Time spent connected by servers. */
  uint64_t is_cl;  /**< Number of client connections. */
  uint64_t is_sv;  /**< Number of server connections. */
  uint64_t is_ni;  /**< Connections with unidentified sources. */
  uint64_t is_ac;  /**< Number of accepted connections. */
  uint64_t is_ref;  /**< Number of refused connections. */
  uint64_t is_unco;  /**< Number of unknown commands received. */
  uint64_t is_wrdi;  /**< Number of commands going in the wrong direction. */
  uint64_t is_unpf;  /**< Number of messages with unknown prefixes. */
  uint64_t is_empt;  /**< Number of empty messages received. */
  uint64_t is_num;  /**< Number of numeric messages received. */
  uint64_t is_kill;  /**< Number of kills generated on collisions. */
  uint64_t is_asuc;  /**< Number of successful authentication requests. */
  uint64_t is_abad;  /**< Number of unsuccessful authentication requests. */
};

/**
 * @struct Counter
 * @brief Structure holding various server activity counters.
 *
 * This structure tracks various server activity metrics, including total client connections,
 * IRC operator count, invisible clients (users with user mode +i), and peak client counts.
 */
struct Counter
{
  uint64_t totalrestartcount;  /**< Total clients connected since server startup. */
  uint32_t oper;  /**< Current IRC operators. */
  uint32_t invisi;  /**< Current invisible clients (users with user mode +i). */
  uint32_t max_loc;  /**< Peak local client count. */
  uint32_t max_tot;  /**< Peak global client count. */
  uint32_t max_loc_con;  /**< Peak local connections (clients + server). */
};

/**
 * @struct ServerState_t
 * @brief Structure representing the server's foreground state.
 *
 * This structure holds a flag indicating whether the server should run in the foreground.
 * The flag is set based on the command line parameter '-foreground' when launching the ircd process.
 */
struct ServerState_t
{
  bool foreground;  /**< Flag indicating whether the server should run in the foreground. */
};

/**
 * @extern char **myargv
 * @brief External variable representing the command line arguments.
 *
 * This variable holds the command line arguments passed to the ircd.
 */
extern char **myargv;

/**
 * @extern const char *logFileName
 * @brief External variable representing the log file name.
 *
 * This variable holds the name of the log file used by the ircd.
 */
extern const char *logFileName;

/**
 * @extern const char *pidFileName
 * @brief External variable representing the PID file name.
 *
 * This variable holds the name of the PID file used by the ircd.
 */
extern const char *pidFileName;

extern struct Counter Count;
extern struct ServerStatistics ServerStats;
extern struct SetOptions GlobalSetOptions;
extern struct ServerState_t server_state;
extern event_manager_t ircd_event_manager;
#endif  /* INCLUDED_ircd_h */
