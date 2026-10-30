/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file stats.c
 * @brief Implements dynamic registration and unregistration of stats handlers.
 *
 * This file contains the implementation of an API for dynamically registering and unregistering
 * stats handlers. The API allows modules to register their own stats handlers upon loading and
 * unregister them upon unloading.
 */

#include <assert.h>

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
 * @param handler Non-NULL function to handle the stats command.
 * @param required_modes Borrowed required-mode flags, or NULL for no requirement.
 * @return STATS_SUCCESS, STATS_INVALID_ARGUMENT, or STATS_ALREADY_REGISTERED.
 *         Failure leaves existing registrations unchanged.
 */
stats_result_t
stats_register(unsigned char letter, stats_handler_func handler, uint64_t *required_modes)
{
  if (handler == NULL)
    return STATS_INVALID_ARGUMENT;

  if (stats_handlers[letter])
    return STATS_ALREADY_REGISTERED;

  struct StatsHandler *const new = io_calloc(sizeof(*new));
  new->letter = letter;
  new->handler = handler;
  new->required_modes = required_modes;
  new->enabled = true;
  stats_handlers[letter] = new;

  return STATS_SUCCESS;
}

/**
 * @brief Registers an array of stats handlers.
 *
 * If registration fails, all handlers added by this call are unregistered
 * in reverse order. Previously registered handlers remain unchanged.
 *
 * @param handlers The array of StatsHandler structures, or NULL when elements is zero.
 * @param elements The number of elements in the handlers array.
 * @param failed_index Optional output for the first failing index, or elements on success.
 * @return STATS_SUCCESS if all handlers were registered, otherwise the first registration error.
 */
stats_result_t
stats_register_array(const struct StatsHandler *handlers, size_t elements, size_t *failed_index)
{
  assert(handlers || elements == 0);

  if (failed_index)
    *failed_index = elements;

  for (size_t i = 0; i < elements; ++i)
  {
    const struct StatsHandler *const handler = &handlers[i];
    const stats_result_t result = stats_register(handler->letter, handler->handler, handler->required_modes);
    if (result != STATS_SUCCESS)
    {
      if (failed_index)
        *failed_index = i;

      while (i)
        stats_unregister(handlers[--i].letter);

      return result;
    }
  }

  return STATS_SUCCESS;
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
stats_result_t
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
 * @param elements The number of elements in the handlers array.
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
struct StatsHandler *
stats_find(unsigned char letter)
{
  return stats_handlers[letter];
}

/**
 * @brief Enables a stats handler.
 *
 * This function sets the enabled field of the specified stats handler to true.
 *
 * @param letter The character representing the stats command.
 * @return STATS_SUCCESS on success, or STATS_NOT_FOUND if the handler was not found.
 */
stats_result_t
stats_set_enabled(unsigned char letter)
{
  struct StatsHandler *const handler = stats_find(letter);
  if (handler == NULL)
    return STATS_NOT_FOUND;

  handler->enabled = true;
  return STATS_SUCCESS;
}

/**
 * @brief Disables a stats handler.
 *
 * This function sets the enabled field of the specified stats handler to false.
 *
 * @param letter The character representing the stats command.
 * @return STATS_SUCCESS on success, or STATS_NOT_FOUND if the handler was not found.
 */
stats_result_t
stats_set_disabled(unsigned char letter)
{
  struct StatsHandler *const handler = stats_find(letter);
  if (handler == NULL)
    return STATS_NOT_FOUND;

  handler->enabled = false;
  return STATS_SUCCESS;
}

/**
 * @brief Sets the required user modes for a stats handler.
 *
 * This function updates the required user modes for the specified stats handler.
 *
 * @param letter The character representing the stats command.
 * @param required_modes The user modes required to access this stats command.
 * @return STATS_SUCCESS on success, or STATS_NOT_FOUND if the handler was not found.
 */
stats_result_t
stats_set_required_modes(unsigned char letter, uint64_t *required_modes)
{
  struct StatsHandler *const handler = stats_find(letter);
  if (handler == NULL)
    return STATS_NOT_FOUND;

  handler->required_modes = required_modes;
  return STATS_SUCCESS;
}

/**
 * @brief Checks if the user has the required user modes and if the handler is enabled.
 *
 * This function checks if the user has the necessary user modes to execute a
 * stats handler and if the handler is enabled. It returns true if the user has
 * the required user modes and the handler is enabled, or if no specific user modes are required.
 *
 * @param handler The stats handler containing the required user modes and enabled state.
 * @param modes The user modes the user currently has
 * @return True if the user has the required user modes and the handler is enabled, false otherwise.
 */
bool
stats_allowed(const struct StatsHandler *handler, uint64_t modes)
{
  if (handler->enabled == false)
    return false;
  return handler->required_modes == NULL || (modes & *handler->required_modes);
}
