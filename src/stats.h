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
 * @file stats.h
 * @brief Defines the interface for the stats API.
 *
 * This header file contains the definitions and function prototypes for the stats API,
 * which allows for dynamic registration, unregistration, and management of stats handlers.
 */

#ifndef INCLUDED_stats_h
#define INCLUDED_stats_h

#include "client.h"

/**
 * @def STATS_HANDLER_INIT
 * @brief Macro to simplify the initialization of StatsHandler entries.
 *
 * This macro is used to create entries for arrays of StatsHandler structures,
 * providing a more readable and consistent initialization process. By default,
 * the handler is enabled.
 *
 * @param l The character representing the stats command.
 * @param h The function to handle the stats command.
 * @param r The required user modes to access this stats command.
 */
#define STATS_HANDLER_INIT(l, h, r) { .letter = l, .handler = h, .required_modes = r, .enabled = true }

/**
 * @enum stats_result
 * @brief Error codes for the stats API functions.
 *
 * This enumeration defines error codes for the stats API functions, indicating the result of
 * registration and unregistration operations.
 */
enum stats_result
{
  STATS_SUCCESS = 0,  /**< Indicates a successful operation. */
  STATS_ALREADY_REGISTERED,  /**< Indicates that the stats handler for the given character is already registered. */
  STATS_NOT_FOUND,  /**< Indicates that the stats handler for the given character was not found. */
};

/**
 * @typedef stats_handler_func
 * @brief Type definition for stats handler functions.
 *
 * This typedef defines the function signature for stats handler functions.
 */
typedef void (*stats_handler_func)(struct Client *, int, char *[]);

/**
 * @struct StatsHandler
 * @brief Structure for holding stats handler information.
 *
 * This structure contains the letter representing the stats command, the function pointer to the stats handler,
 * and the required user modes for accessing the stats command.
 */
struct StatsHandler
{
  unsigned char letter;  /**< The character representing the stats command. */
  stats_handler_func handler;  /**< The function to handle the stats command. */
  unsigned int required_modes;  /**< The required user modes to access this stats command. */
  bool enabled;  /**< Indicates if the handler is enabled. */
};

extern enum stats_result stats_register(unsigned char, stats_handler_func, unsigned int);
extern void stats_register_array(const struct StatsHandler *, size_t);
extern enum stats_result stats_unregister(unsigned char);
extern void stats_unregister_array(const struct StatsHandler *, size_t);
extern struct StatsHandler *stats_find(unsigned char);
extern enum stats_result stats_set_enabled(unsigned char);
extern enum stats_result stats_set_disabled(unsigned char);
extern enum stats_result stats_set_required_modes(unsigned char, unsigned int);
extern bool stats_allowed(const struct StatsHandler *, unsigned int);
#endif  /* INCLUDED_stats_h */
