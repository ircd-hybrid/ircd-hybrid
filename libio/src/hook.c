/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (C) 2003 Piotr Nizynski, Advanced IRC Services Project Tea
 *  Copyright (c) 2005-2024 ircd-hybrid development team
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
 * @file hook.c
 * @brief Implements a generic event hooking interface for modular event handling.
 *
 * This file contains the implementation of a flexible and extensible event hooking interface,
 * allowing functions to be registered as callbacks for specific events and executed in a chain
 * when the events occur.
 */

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>

#include "io_time.h"
#include "list.h"
#include "memory.h"
#include "hook.h"

/**
 * @var hook_container_list
 * @brief Doubly linked list holding all hook containers.
 *
 * This global variable maintains a doubly linked list of all hook containers.
 * Each element in the list is a HookContainer structure representing a specific
 * hook container. Hook containers are used to store callbacks (hook functions)
 * and manage their execution when triggered by events.
 */
static list_t hook_container_list;

/**
 * @brief Retrieves the list of hook containers.
 *
 * This function returns a pointer to the list of hook containers.
 *
 * @return Pointer to the list of hook containers.
 */
const list_t *
hook_container_get_list(void)
{
  return &hook_container_list;
}

/**
 * @brief Registers a new HookContainer by name.
 *
 * This function registers a new HookContainer identified by the provided name. If a container with the
 * given name already exists, the function returns a pointer to that container without modifying it. If no
 * such container exists, a new HookContainer is created, initialized, and added to the global list of containers.
 *
 * @param name Name used to identify the HookContainer. The name cannot be NULL.
 * @return struct HookContainer* Pointer to the registered HookContainer structure, or NULL if the name is invalid.
 */
struct HookContainer *
hook_container_register(const char *name)
{
  if (name == NULL)
    return NULL;

  struct HookContainer *container = hook_container_find(name);
  if (container)
    return container;

  container = io_calloc(sizeof(*container));
  container->name = io_strdup(name);
  list_add(container, &container->node, &hook_container_list);

  return container;
}

/**
 * @brief Unregisters and frees a HookContainer by name, along with any registered callbacks.
 *
 * This function removes a HookContainer from the global hook container list by its name.
 * All callbacks registered in the container's chain are also removed.
 *
 * @param name The name of the HookContainer to unregister. Must be non-NULL.
 */
void
hook_container_unregister(const char *name)
{
  if (name == NULL)
    return;

  struct HookContainer *container = hook_container_find(name);
  if (container == NULL)
    return;

  while (container->chain.head)
  {
    list_node_t *node = container->chain.head;
    list_remove(node, &container->chain);
    list_free_node(node);
  }

  list_remove(&container->node, &hook_container_list);
  io_free(container->name);
  io_free(container);
}

/**
 * @brief Dispatches the execution of the hook chain associated with a hook container.
 *
 * This function iterates over and executes each hook in the chain associated with the
 * specified HookContainer. The dispatcher processes the flow control signals returned
 * by each hook, allowing the chain to continue or stop based on the hooks' outcomes.
 * The function increments the usage statistics for the container, including the count of
 * how many times the chain has been executed.
 *
 * @param container Pointer to the HookContainer structure.
 * @param ... Variable arguments passed to the hook functions.
 * @return hook_flow_t The flow control signal indicating how the hook chain execution was concluded.
 */
hook_flow_t
hook_dispatch(struct HookContainer *container, void *data)
{
  container->called++;
  container->last = io_time_get(IO_TIME_MONOTONIC_SEC);

  list_node_t *node = container->chain.head;
  while (node)
  {
    HCFUNC hook_func = node->data;
    hook_flow_t flow = hook_func(data);

    switch (flow)
    {
      case HOOK_FLOW_CONTINUE:
        node = node->next;
        break;
      case HOOK_FLOW_RESTART:
        node = container->chain.head;
        break;
      case HOOK_FLOW_RETRY:
        break;
      case HOOK_FLOW_STOP:
      default:
        return HOOK_FLOW_STOP;
    }
  }

  return HOOK_FLOW_CONTINUE;
}

/**
 * @brief Finds a named hook container.
 *
 * This function searches the list of hook containers for a container with
 * the specified name and returns a pointer to it if found.
 *
 * @param name Name of the hook container to find.
 * @return struct HookContainer* Pointer to the found HookContainer structure, or NULL if not found.
 */
struct HookContainer *
hook_container_find(const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, hook_container_list.head)
  {
    struct HookContainer *container = node->data;
    if (strcasecmp(container->name, name) == 0)
      return container;
  }

  return NULL;
}

/**
 * @brief Installs a new hook into a hook container.
 *
 * This function installs a new hook into the specified hook container.
 * The new hook is added at the specified priority in the chain, allowing
 * for flexible control over the hook's placement based on the priority.
 *
 * @param container Pointer to the HookContainer structure.
 * @param hook Address of the hook function.
 * @param priority Priority level to insert the hook in the chain.
 * @return list_node_t* Pointer to the list_node_t of the installed hook.
 */
list_node_t *
hook_install(struct HookContainer *container, HCFUNC hook, hook_priority_t priority)
{
  unsigned int length = list_length(&container->chain);
  unsigned int insert_position = 0;

  /* Determine the insert position based on the priority level. */
  switch (priority)
  {
    case HOOK_PRIORITY_SYSTEM_CRITICAL:
      insert_position = 0;
      break;
    case HOOK_PRIORITY_SYSTEM_HIGH:
      insert_position = (length >= 1) ? 1 : length;
      break;
    case HOOK_PRIORITY_SYSTEM:
      insert_position = (length >= 2) ? 2 : length;
      break;
    case HOOK_PRIORITY_HIGH:
      insert_position = length / 10;
      break;
    case HOOK_PRIORITY_ABOVE_NORMAL:
      insert_position = length / 5;
      break;
    case HOOK_PRIORITY_NORMAL:
      insert_position = length / 2;
      break;
    case HOOK_PRIORITY_BELOW_NORMAL:
      insert_position = 3 * length / 4;
      break;
    case HOOK_PRIORITY_LOW:
      insert_position = 9 * length / 10;
      break;
    case HOOK_PRIORITY_LOWEST:
      insert_position = (length > 0) ? length - 1 : 0;
      break;
    case HOOK_PRIORITY_DEFAULT:
    default:
      insert_position = length;
      break;
  }

  list_node_t *node = io_calloc(sizeof(*node));
  list_add_at(hook, insert_position, node, &container->chain);

  return node;
}

/**
 * @brief Removes a specific hook from a hook container.
 *
 * This function removes the specified hook function from the chain associated
 * with the given hook container. The memory allocated for the hook node is freed.
 *
 * @param container Pointer to the HookContainer structure.
 * @param hook Address of the hook function to uninstall.
 */
void
hook_uninstall(struct HookContainer *container, HCFUNC hook)
{
  list_node_t *node = list_find_remove(&container->chain, hook);
  if (node)
    list_free_node(node);
}
