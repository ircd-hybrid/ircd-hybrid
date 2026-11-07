/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file stats.c
 * @brief Registration, activation, and access control for STATS handlers.
 */

#include <assert.h>
#include <limits.h>

#include "client.h"
#include "stats.h"

/** One slot for each possible unsigned-character selector. */
#define STATS_HANDLER_CAPACITY (UCHAR_MAX + 1U)

struct stats_registration
{
  const struct StatsHandler *handler;
  bool enabled;
};

static struct stats_registration stats_registrations[STATS_HANDLER_CAPACITY];

/**
 * @brief Registers a borrowed handler definition.
 *
 * The definition must remain valid and unchanged until unregistered. New
 * registrations are enabled. Failure leaves existing registrations unchanged.
 *
 * @param handler Non-NULL definition with a callback and a valid access class.
 * @return STATS_SUCCESS, STATS_INVALID_ARGUMENT, or STATS_ALREADY_REGISTERED.
 */
stats_result_t
stats_register(const struct StatsHandler *handler)
{
  if (handler == NULL || handler->handler == NULL)
    return STATS_INVALID_ARGUMENT;

  switch (handler->access)
  {
    case STATS_ACCESS_PUBLIC:
    case STATS_ACCESS_OPER:
    case STATS_ACCESS_ADMIN:
      break;
    default:
      return STATS_INVALID_ARGUMENT;
  }

  struct stats_registration *const registration = &stats_registrations[handler->letter];
  if (registration->handler)
    return STATS_ALREADY_REGISTERED;

  *registration = (struct stats_registration){ .handler = handler, .enabled = true };
  return STATS_SUCCESS;
}

/**
 * @brief Registers an array of borrowed handler definitions.
 *
 * The array must remain valid and unchanged until unregistered. If registration
 * fails, definitions added by this call are unregistered in reverse order.
 * Previously registered definitions and their activation states remain unchanged.
 *
 * @param handlers The array of definitions, or NULL when elements is zero.
 * @param elements The number of elements in the array.
 * @param failed_index Optional output for the first failing index, or elements on success.
 * @return STATS_SUCCESS, otherwise the first registration error.
 */
stats_result_t
stats_register_array(const struct StatsHandler *handlers, size_t elements, size_t *failed_index)
{
  assert(handlers || elements == 0);

  if (failed_index)
    *failed_index = elements;

  for (size_t i = 0; i < elements; ++i)
  {
    const stats_result_t result = stats_register(&handlers[i]);
    if (result != STATS_SUCCESS)
    {
      if (failed_index)
        *failed_index = i;

      while (i)
        stats_unregister(&handlers[--i]);

      return result;
    }
  }

  return STATS_SUCCESS;
}

/**
 * @brief Unregisters the exact definition originally registered.
 *
 * A different definition with the same selector leaves the registration and its
 * activation state unchanged. The registry never frees the borrowed definition.
 *
 * @param handler The definition originally passed to stats_register().
 * @return STATS_SUCCESS, STATS_NOT_FOUND, or STATS_INVALID_ARGUMENT for NULL.
 */
stats_result_t
stats_unregister(const struct StatsHandler *handler)
{
  if (handler == NULL)
    return STATS_INVALID_ARGUMENT;

  struct stats_registration *const registration = &stats_registrations[handler->letter];
  if (registration->handler != handler)
    return STATS_NOT_FOUND;

  *registration = (struct stats_registration){ 0 };
  return STATS_SUCCESS;
}

/**
 * @brief Unregisters definitions belonging to the supplied array.
 *
 * Registrations belonging to other definitions remain unchanged.
 *
 * @param handlers The original array, or NULL when elements is zero.
 * @param elements The number of elements in the array.
 */
void
stats_unregister_array(const struct StatsHandler *handlers, size_t elements)
{
  assert(handlers || elements == 0);

  for (size_t i = 0; i < elements; ++i)
    stats_unregister(&handlers[i]);
}

/**
 * @brief Finds a registered definition, including disabled registrations.
 * @return The borrowed definition, valid until unregistered, or NULL.
 */
const struct StatsHandler *
stats_find(unsigned char letter)
{
  return stats_registrations[letter].handler;
}

/**
 * @brief Enables the current registration for a selector.
 * @return STATS_SUCCESS or STATS_NOT_FOUND.
 */
stats_result_t
stats_set_enabled(unsigned char letter)
{
  struct stats_registration *const registration = &stats_registrations[letter];
  if (registration->handler == NULL)
    return STATS_NOT_FOUND;

  registration->enabled = true;
  return STATS_SUCCESS;
}

/**
 * @brief Disables the current registration without removing its definition.
 * @return STATS_SUCCESS or STATS_NOT_FOUND.
 */
stats_result_t
stats_set_disabled(unsigned char letter)
{
  struct stats_registration *const registration = &stats_registrations[letter];
  if (registration->handler == NULL)
    return STATS_NOT_FOUND;

  registration->enabled = false;
  return STATS_SUCCESS;
}

/**
 * @brief Checks registration, activation, and the client's access class.
 *
 * A NULL argument, an unregistered or disabled definition, or an unknown access
 * class denies access. Oper and admin status are evaluated through the Client API.
 */
bool
stats_allowed(const struct StatsHandler *handler, const struct Client *client)
{
  if (handler == NULL || client == NULL)
    return false;

  const struct stats_registration *const registration = &stats_registrations[handler->letter];
  if (registration->handler != handler || !registration->enabled)
    return false;

  switch (handler->access)
  {
    case STATS_ACCESS_PUBLIC:
      return true;
    case STATS_ACCESS_OPER:
      return client_is_oper(client);
    case STATS_ACCESS_ADMIN:
      return client_is_admin(client);
  }

  return false;
}
