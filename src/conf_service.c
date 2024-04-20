/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2012-2024 ircd-hybrid development team
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
 * @file conf_service.c
 * @brief Implementation of service {} block configuration management.
 */

#include "stdinc.h"
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
  while (service_list.head)
  {
    struct ServiceItem *service = service_list.head->data;

    list_remove(&service->node, &service_list);
    xfree(service->name);
    xfree(service);
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
  struct ServiceItem *service = xcalloc(sizeof(*service));
  list_add(service, &service->node, &service_list);

  return service;
}

/**
 * @brief Find a service configuration by name.
 *
 * This function searches the service_list for a service configuration with
 * the specified name. It uses the provided compare function pointer to
 * perform the string comparison.
 *
 * @param name The name of the service to find.
 * @param compare A function pointer for comparing two strings.
 *
 * @return A pointer to the found ServiceItem, or NULL if not found.
 */
const struct ServiceItem *
service_find(const char *name, int (*compare)(const char *, const char *))
{
  list_node_t *node;

  LIST_FOREACH(node, service_list.head)
  {
    const struct ServiceItem *service = node->data;

    if (compare(service->name, name) == 0)
      return service;
  }

  return NULL;
}
