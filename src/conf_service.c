/*
 * SPDX-FileCopyrightText: 2012-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file conf_service.c
 * @brief Implementation of service {} block configuration management.
 */

#include <assert.h>

#include "io_string.h"
#include "list.h"
#include "memory.h"

#include "conf_service.h"

/**
 * @brief List to hold configurations for service {} blocks.
 *
 * This static variable represents a doubly-linked list that stores
 * configurations for service {} blocks in the ircd-hybrid daemon. Each
 * node in the list corresponds to a specific service configuration.
 */
static list_t service_list;

/**
 * @brief Get the list of service configurations.
 *
 * This function returns a constant pointer to the list of service
 * configurations. It allows external components to access the list without
 * modifying it.
 *
 * @return A pointer to the list of service configurations.
 */
const list_t *
service_get_list(void)
{
  return &service_list;
}

/**
 * @brief Clear all service configurations.
 *
 * This function iterates over the service_list and removes all service
 * configurations from the list. It also frees the associated memory to
 * prevent memory leaks.
 */
void
service_clear(void)
{
  list_node_t *node;

  while ((node = list_pop_head(&service_list)))
  {
    struct ServiceItem *const service = node->data;
    assert(service);

    io_free(service->name);
    io_free(service);
  }
}

/**
 * @brief Create a new service configuration item.
 *
 * This function allocates memory for a new ServiceItem structure, adds it to
 * the service_list, and returns a pointer to the newly created ServiceItem.
 *
 * @return A pointer to the newly created ServiceItem.
 */
struct ServiceItem *
service_make(void)
{
  struct ServiceItem *const service = io_calloc(sizeof(*service));
  list_add_tail(service, &service->node, &service_list);

  return service;
}

/**
 * @brief Find a service configuration by name.
 *
 * This function searches the service_list for a service configuration with
 * the specified name.
 *
 * @param name The name of the service to find.
 *
 * @return A pointer to the found ServiceItem, or NULL if not found.
 */
const struct ServiceItem *
service_find(const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, service_list.head)
  {
    const struct ServiceItem *const service = node->data;
    if (io_strcasecmp(service->name, name) == 0)
      return service;
  }

  return NULL;
}
