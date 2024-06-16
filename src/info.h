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
 * @file info.h
 * @brief Implements dynamic registration, unregistration, and updating of info entries.
 *
 * This file contains the implementation of an API for dynamically registering and unregistering
 * info entries. The API supports various output types including string, unsigned integer,
 * signed integer, boolean, float, double, and char.
 * This implementation is used for showing the configuration in /INFO requests.
 */

#ifndef INCLUDED_info_h
#define INCLUDED_info_h

#include "list.h"

/**
 * @def INFO_ENTRY_INIT
 * @brief Macro to simplify the initialization of InfoEntry entries.
 *
 * This macro is used to create entries for arrays of InfoEntry structures,
 * providing a more readable and consistent initialization process.
 *
 * @param n The name of the info entry.
 * @param ot The output type of the info entry.
 * @param o The pointer to the value of the info entry.
 * @param d The description of the info entry.
 */
#define INFO_ENTRY_INIT(n, ot, o, d) { .name = n, .output_type = ot, .option = o, .description = d }

/**
 * @enum info_output_type_t
 * @brief Specifies the output format for info entries.
 *
 * This enumeration defines the various output formats available for info entries.
 * Each type determines how the value of an info entrywill be formatted and
 * displayed in response to /INFO requests.
 */
typedef enum
{
  INFO_OUTPUT_STRING = 1,  /**< Output the value by dereferencing a string pointer (char **). */
  INFO_OUTPUT_STRING_LITERAL,  /**< Output the value as a string literal (char *). */
  INFO_OUTPUT_INT,  /**< Output the value as an integer. */
  INFO_OUTPUT_UNSIGNED_INT,  /**< Output the value as an unsigned integer. */
  INFO_OUTPUT_BOOLEAN,  /**< Output as "YES" or "NO". */
  INFO_OUTPUT_FLOAT,  /**< Output the value as a floating-point number. */
  INFO_OUTPUT_DOUBLE,  /**< Output the value as a double-precision floating-point number. */
  INFO_OUTPUT_CHAR,  /**< Output the value as a single character. */
} info_output_type_t;

/**
 * @enum info_result_t
 * @brief Error codes for the info API functions.
 *
 * This enumeration defines error codes for the info API functions, indicating the result of
 * registration and unregistration operations.
 */
typedef enum
{
  INFO_SUCCESS = 0,  /**< Indicates a successful operation. */
  INFO_ALREADY_REGISTERED,  /**< Indicates that the info entry for the given name is already registered. */
  INFO_NOT_FOUND,  /**< Indicates that the info entry for the given name was not found. */
} info_result_t;

/**
 * @struct InfoEntry
 * @brief Structure representing an info entry.
 *
 * This structure represents an info entry, containing the name, output type,
 * pointer to the value, description, and a list node for the doubly-linked list.
 */
struct InfoEntry
{
  list_node_t node;  /**< List node for the doubly-linked list. */
  const char *name;  /**< Displayed variable name. */
  info_output_type_t output_type;  /**< Type of output. */
  const void *option;  /**< Pointer to the value. */
  const char *description;  /**< Description of the variable. */
};

extern info_result_t info_register(const char *, info_output_type_t, const void *, const char *);
extern info_result_t info_unregister(const char *);
extern void info_register_array(const struct InfoEntry *, size_t);
extern void info_unregister_array(const struct InfoEntry *, size_t);
extern struct InfoEntry *info_find(const char *);
extern void info_send(struct Client *);
#endif  /* INCLUDED_info_h */
