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

#include "ircd_defs.h"
#include "config.h"
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
  bool autoconn;  /**< Flag indicating if autoconn is enabled for all servers. */
  unsigned int maxclients;  /**< Maximum allowed client connections. */
  unsigned int floodcount;  /**< Number of messages allowed in 'floodtime' seconds. */
  unsigned int floodtime;  /**< Time threshold for flood control. */
  unsigned int joinfloodtime;  /**< Time threshold for join flood control. */
  unsigned int joinfloodcount;  /**< Number of join messages allowed in 'joinfloodtime' seconds. */
  unsigned int spam_num;  /**< Number of spam messages allowed. */
  unsigned int spam_time;  /**< Time threshold for spam control. */
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
  uintmax_t is_cbs;  /**< Bytes sent to clients. */
  uintmax_t is_cbr;  /**< Bytes received from clients. */
  uintmax_t is_sbs;  /**< Bytes sent to servers. */
  uintmax_t is_sbr;  /**< Bytes received from servers. */
  uintmax_t is_cti;  /**< Time spent connected by clients. */
  uintmax_t is_sti;  /**< Time spent connected by servers. */
  unsigned int is_cl;  /**< Number of client connections. */
  unsigned int is_sv;  /**< Number of server connections. */
  unsigned int is_ni;  /**< Connections with unidentified sources. */
  unsigned int is_ac;  /**< Number of accepted connections. */
  unsigned int is_ref;  /**< Number of refused connections. */
  unsigned int is_unco;  /**< Number of unknown commands received. */
  unsigned int is_wrdi;  /**< Number of commands going in the wrong direction. */
  unsigned int is_unpf;  /**< Number of messages with unknown prefixes. */
  unsigned int is_empt;  /**< Number of empty messages received. */
  unsigned int is_num;  /**< Number of numeric messages received. */
  unsigned int is_kill;  /**< Number of kills generated on collisions. */
  unsigned int is_asuc;  /**< Number of successful authentication requests. */
  unsigned int is_abad;  /**< Number of unsuccessful authentication requests. */
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
  uintmax_t totalrestartcount;  /**< Total clients connected since server startup. */
  unsigned int oper;  /**< Current IRC operators. */
  unsigned int invisi;  /**< Current invisible clients (users with user mode +i). */
  unsigned int max_loc;  /**< Peak local client count. */
  unsigned int max_tot;  /**< Peak global client count. */
  unsigned int max_loc_con; /**< Peak local connections (clients + server). */
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
  bool foreground; /**< Flag indicating whether the server should run in the foreground. */
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

/**
 * @extern bool dorehash
 * @brief External flag indicating whether to reload ircd configuration files.
 *
 * This flag is set to true when the ircd receives a SIGHUP signal,
 * indicating the need to reload the configuration files.
 * The ircd will perform a rehash to apply the updated configurations.
 */
extern bool dorehash;

/**
 * @extern bool doremotd
 * @brief External flag indicating whether to reload the Message of the Day (MOTD) files.
 *
 * This flag is set to true when the ircd receives a SIGUSR1 signal,
 * indicating the need to reload the MOTD files.
 * The ircd will refresh and display the updated Message of the Day to users.
 */
extern bool doremotd;


extern struct Counter Count;
extern struct ServerStatistics ServerStats;
extern struct SetOptions GlobalSetOptions;
extern struct ServerState_t server_state;
extern struct event event_write_links_file;
#endif  /* INCLUDED_ircd_h */
