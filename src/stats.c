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
 * @file stats.c
 * @brief Implements dynamic registration and unregistration of stats handlers.
 *
 * This file contains the implementation of an API for dynamically registering and unregistering
 * stats handlers. The API allows modules to register their own stats handlers upon loading and
 * unregister them upon unloading.
 */

#include "stdinc.h"
#include "memory.h"
#include "stats.h"

/**
 * @def STATS_ARRAY_SIZE
 * @brief The size of the array used to store stats handlers.
 *
 * This constant defines the maximum number of stats handlers, allowing each possible ASCII character
 * to be used as a handler key.
 */
#define STATS_ARRAY_SIZE 256

/**
 * @var stats_handlers
 * @brief Array of stats handlers.
 *
 * This static array holds pointers to stats handlers for each possible ASCII character.
 * Each entry corresponds to a stats handler that can be dynamically registered and unregistered.
 */
static struct StatsHandler *stats_handlers[STATS_ARRAY_SIZE];

/**
 * @brief Registers a new stats handler.
 *
 * This function registers a new stats handler for the specified character. If a handler for the character
 * is already registered, it returns an error code.
 *
 * @param letter The character representing the stats command.
 * @param handler The function to handle the stats command.
 * @param required_modes The required user modes to access this stats command.
 * @return An error code indicating the result of the operation.
 */
enum stats_result
stats_register(unsigned char letter, stats_handler_func handler, unsigned int required_modes)
{
  if (stats_handlers[letter])
    return STATS_ALREADY_REGISTERED;

  struct StatsHandler *new = io_calloc(sizeof(*new));
  new->letter = letter;
  new->handler = handler;
  new->required_modes = required_modes;
  stats_handlers[letter] = new;

  return STATS_SUCCESS;
}

/**
 * @brief Registers an array of stats handlers.
 *
 * This function registers an entire array of stats handlers to the stats API.
 *
 * @param handlers The array of StatsHandler structures to be registered.
 * @param elements The number of elements in the handlers array.
 */
void
stats_register_array(const struct StatsHandler *handlers, size_t elements)
{
  for (size_t i = 0; i < elements; ++i)
  {
    const struct StatsHandler *const tmp = &handlers[i];
    stats_register(tmp->letter, tmp->handler, tmp->required_modes);
  }
}

/**
 * @brief Unregisters an existing stats handler.
 *
 * This function unregisters the stats handler for the specified character. If no handler is
 * found for the character, it returns an error code.
 *
 * @param letter The character representing the stats command.
 * @return An error code indicating the result of the operation.
 */
enum stats_result
stats_unregister(unsigned char letter)
{
  if (stats_handlers[letter] == NULL)
    return STATS_NOT_FOUND;

  io_free(stats_handlers[letter]);
  stats_handlers[letter] = NULL;

  return STATS_SUCCESS;
}

/**
 * @brief Unregisters an array of stats handlers.
 *
 * This function unregisters an entire array of stats handlers from the stats API.
 *
 * @param handlers The array of StatsHandler structures to be unregistered.
 * @param count The number of elements in the handlers array.
 */
void
stats_unregister_array(const struct StatsHandler *handlers, size_t elements)
{
  for (size_t i = 0; i < elements; ++i)
  {
    const struct StatsHandler *const tmp = &handlers[i];
    stats_unregister(tmp->letter);
  }
}

/**
 * @brief Finds a stats handler.
 *
 * This function looks up a stats handler for the specified character. If found, it returns a pointer
 * to the handler structure.
 *
 * @param letter The character representing the stats command.
 * @return A pointer to the StatsHandler structure or NULL if not found.
 */
const struct StatsHandler *
stats_find(unsigned char letter)
{
  return stats_handlers[letter];
}

/**
 * @brief Checks if the user has the required user modes for a stats handler.
 *
 * This function checks if the user has the necessary user modes to execute a
 * stats handler. It returns true if the user has the required user modes, or if no
 * specific user modes are required.
 *
 * @param handler The stats handler containing the required user modes.
 * @param modes The user modes the user currently has.
 * @return True if the user has the required user modes, false otherwise.
 */
bool
stats_mode_allowed(const struct StatsHandler *handler, unsigned int modes)
{
  return handler->required_modes == 0 || (modes & handler->required_modes) != 0;
}
