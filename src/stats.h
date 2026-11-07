/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
#include <stdbool.h>
#include <stddef.h>

struct Client;

/**
 * @def STATS_HANDLER_INIT
 * @brief Macro to simplify the initialization of StatsHandler entries.
 *
 * This macro is used to create entries for arrays of StatsHandler structures,
 * providing a more readable and consistent initialization process. New
 * registrations are enabled independently of the immutable definition.
 *
 * @param l The character representing the stats command.
 * @param h The function to handle the stats command.
 * @param a The access class required to use this stats command.
 */
#define STATS_HANDLER_INIT(l, h, a) \
  { .letter = l, .handler = h, .access = a }

/** Access classes for stats handlers. Zero is not a valid access class. */
typedef enum
{
  STATS_ACCESS_PUBLIC = 1,
  STATS_ACCESS_OPER,
  STATS_ACCESS_ADMIN
} stats_access_t;

/**
 * @enum stats_result_t
 * @brief Error codes for the stats API functions.
 *
 * This enumeration defines error codes for the stats API functions, indicating the result of
 * registration and unregistration operations.
 */
typedef enum
{
  STATS_SUCCESS = 0,  /**< Indicates a successful operation. */
  STATS_ALREADY_REGISTERED,  /**< Indicates that the stats handler for the given character is already registered. */
  STATS_NOT_FOUND,  /**< Indicates that the stats handler for the given character was not found. */
  STATS_INVALID_ARGUMENT,  /**< Indicates that a required argument is invalid. */
} stats_result_t;

/**
 * @typedef stats_handler_fn
 * @brief Type definition for stats handler functions.
 *
 * This typedef defines the function signature for stats handler functions.
 */
typedef void (*stats_handler_fn)(struct Client *, size_t, char *[]);

/**
 * @struct StatsHandler
 * @brief Structure for holding stats handler information.
 *
 * Definitions are borrowed by the registry and must remain valid and unchanged
 * until unregistered. Activation state is maintained separately by the registry.
 */
struct StatsHandler
{
  unsigned char letter;  /**< The character representing the stats command. */
  stats_handler_fn handler;  /**< The function to handle the stats command. */
  stats_access_t access;  /**< The access class required to use this stats command. */
};

extern void stats_unregister_array(const struct StatsHandler *, size_t);
extern bool stats_allowed(const struct StatsHandler *, const struct Client *);
extern stats_result_t stats_register(const struct StatsHandler *);
extern stats_result_t stats_register_array(const struct StatsHandler *, size_t, size_t *);
extern stats_result_t stats_unregister(const struct StatsHandler *);
extern stats_result_t stats_set_enabled(unsigned char);
extern stats_result_t stats_set_disabled(unsigned char);
extern const struct StatsHandler *stats_find(unsigned char);
#endif  /* INCLUDED_stats_h */
