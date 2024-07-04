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
#include "event.h"
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
 * @brief Registers a new callback with a hook container.
 *
 * @param name Name used to identify the callback (can be NULL for anonymous callbacks).
 * @param func Initial function attached to the chain (can be NULL to create an empty chain).
 * @return struct HookContainer* Pointer to the registered HookContainer structure.
 *
 * This function registers a new callback with a hook container. If a container with the given
 * name already exists, the function adds the provided function to its chain. If the name is NULL,
 * an anonymous container is created.
 *
 * @note Once a callback is registered, it should remain in memory for the duration of the program's
 *       execution. This is necessary because there may be modules or components that rely on the
 *       existence of the callback, even if no functions are currently attached to it. By dynamically
 *       allocating the HookContainer structure within this function, we ensure that it remains
 *       accessible and valid throughout the program's lifetime, preventing potential crashes or
 *       undefined behavior caused by premature deallocation.
 */
struct HookContainer *
hook_container_register(const char *name, HCFUNC *func)
{
  struct HookContainer *container;

  if (name)
  {
    container = hook_container_find(name);
    if (container)
    {
      if (func)
        list_add_tail(func, io_calloc(sizeof(list_node_t)), &container->chain);
      return container;
    }
  }

  container = io_calloc(sizeof(*container));
  if (func)
    list_add(func, io_calloc(sizeof(list_node_t)), &container->chain);

  if (name)
  {
    container->name = io_strdup(name);
    list_add(container, &container->node, &hook_container_list);
  }

  return container;
}

/**
 * @brief Executes the hook chain associated with a hook container.
 *
 * This function executes the hook chain associated with the given container.
 * It increments usage statistics and passes control to the hook functions in
 * the chain. The return value of the last executed hook function is returned.
 *
 * @param container Pointer to the HookContainer structure.
 * @param ... Variable arguments passed to the hook functions.
 * @return void* Return value of the last executed hook function.
 */
void *
hook_run_chain(struct HookContainer *container, ...)
{
  container->called++;
  container->last = io_time_get(IO_TIME_MONOTONIC_SEC);

  /* Check if the hook chain is empty. */
  if (list_is_empty(&container->chain))
    return NULL;  /* No hooks to execute. */

  va_list args;
  va_start(args, container);
  void *res = ((HCFUNC *)container->chain.head->data)(args);
  va_end(args);

  return res;
}

/**
 * @brief Passes control to the next hook in the chain.
 *
 * This function is called by a hook function to pass code flow further in
 * the hook chain. It finds the next hook in the chain after the current one
 * and calls it with the provided arguments.
 *
 * @param this_hook Pointer to the list_node_t of the current hook function.
 * @param ... Original or modified arguments to be passed to the next hook.
 * @return void* Return value of the next hook function.
 */
void *
hook_advance_to_next(list_node_t *this_hook, ...)
{
  /* Check if the next hook exists. */
  if (this_hook->next == NULL)
    return NULL;  /* Reached the last hook in the chain. */

  va_list args;
  va_start(args, this_hook);
  void *res = ((HCFUNC *)this_hook->next->data)(args);
  va_end(args);

  return res;
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
 * The new hook is added at the specified position in the chain, allowing
 * for flexible control over the hook's placement.
 *
 * @param container Pointer to the HookContainer structure.
 * @param hook Address of the hook function.
 * @param position Position to insert the hook in the chain.
 * @return list_node_t* Pointer to the list_node_t of the installed hook.
 */
list_node_t *
hook_install(struct HookContainer *container, HCFUNC *hook, enum hook_insert position)
{
  list_node_t *node = io_calloc(sizeof(*node));
  unsigned int length = list_length(&container->chain);
  unsigned int insert_position = 0;

  switch (position)
  {
    case HOOK_INSERT_SYSTEM_CRITICAL:
      insert_position = 0;
      break;
    case HOOK_INSERT_SYSTEM_HIGH:
      insert_position = (length >= 1) ? 1 : length;
      break;
    case HOOK_INSERT_SYSTEM:
      insert_position = (length >= 2) ? 2 : length;
      break;
    case HOOK_INSERT_HIGH:
      insert_position = length / 10;
      break;
    case HOOK_INSERT_ABOVE_NORMAL:
      insert_position = length / 5;
      break;
    case HOOK_INSERT_NORMAL:
      insert_position = length / 2;
      break;
    case HOOK_INSERT_BELOW_NORMAL:
      insert_position = 3 * length / 4;
      break;
    case HOOK_INSERT_LOW:
      insert_position = 9 * length / 10;
      break;
    case HOOK_INSERT_LOWEST:
      insert_position = (length > 0) ? length - 1 : 0;
      break;
    case HOOK_INSERT_DEFAULT:
    default:
      insert_position = length;
      break;
  }

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
hook_uninstall(struct HookContainer *container, HCFUNC *hook)
{
  list_node_t *node = list_find_remove(&container->chain, hook);
  if (node)
    list_free_node(node);
}
