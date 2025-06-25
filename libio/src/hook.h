/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (C) 2003 Piotr Nizynski, Advanced IRC Services Project Tea
 *  Copyright (c) 2005-2025 ircd-hybrid development team
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
 * @file hook.h
 * @brief Implements a flexible event hooking interface for modular event handling.
 *
 * This file implements a flexible event hooking interface, enabling functions to register as
 * callbacks for specific events and execute in a chain upon occurrence of the events.
 */

#ifndef INCLUDED_hook_h
#define INCLUDED_hook_h
#include "list.h"

/**
 * @enum hook_priority_t
 * @brief Enum for specifying the position for inserting hooks in a hook chain.
 *
 * This enum provides fine-grained options for specifying where a new hook should be
 * inserted in a hook chain relative to existing hooks, with higher priorities
 * reserved for system/core components.
 */
typedef enum
{
  HOOK_PRIORITY_SYSTEM_CRITICAL,  /**< Reserved for system/core critical hooks. */
  HOOK_PRIORITY_SYSTEM_HIGH,  /**< Reserved for system/core high priority hooks. */
  HOOK_PRIORITY_SYSTEM,  /**< Reserved for system/core hooks. */
  HOOK_PRIORITY_HIGH,  /**< High priority user hooks. */
  HOOK_PRIORITY_ABOVE_NORMAL,  /**< Above normal priority user hooks. */
  HOOK_PRIORITY_NORMAL,  /**< Normal priority user hooks. */
  HOOK_PRIORITY_BELOW_NORMAL, /**< Below normal priority user hooks. */
  HOOK_PRIORITY_LOW,  /**< Low priority user hooks. */
  HOOK_PRIORITY_LOWEST,  /**< Lowest priority user hooks. */
  HOOK_PRIORITY_DEFAULT,  /**< Default priority user hooks (end of chain). */
} hook_priority_t;

/**
 * @enum hook_flow_t
 * @brief Enum for controlling the flow of hook execution.
 *
 * This enum defines the possible flow control signals that can be returned by a hook function.
 * Each signal dictates how the dispatcher should behave after executing the current hook in the chain.
 */
typedef enum
{
  HOOK_FLOW_CONTINUE,  /**< Continue execution to the next hook in the chain. */
  HOOK_FLOW_RESTART,  /**< Restart the hook execution from the beginning of the chain. */
  HOOK_FLOW_RETRY,  /**< Retry the current hook without advancing to the next one. */
  HOOK_FLOW_STOP,  /**< Stop execution of the hook chain immediately. */
} hook_flow_t;

/**
 * @typedef hook_function_t
 * @brief Function pointer type for hook functions.
 *
 * A hook function receives a pointer to data and returns a hook_flow_t,
 * which directs the hook chain execution.
 *
 * @param data Pointer to data passed to the hook.
 * @return hook_flow_t Flow control signal.
 */
typedef hook_flow_t (*hook_function_t)(void *);

/**
 * @struct HookContainer
 * @brief Represents a container for hooks.
 *
 * The HookContainer structure holds information about a specific hook,
 * including its name and the chain of hook functions.
 */
struct HookContainer
{
  list_node_t node;  /**< Doubly-linked list node for container management. */
  char *name;  /**< Name used to identify the callback. */
  list_t chain;  /**< Doubly-linked list to store hook functions. */
};

extern struct HookContainer *hook_container_register(const char *);
extern hook_flow_t hook_dispatch(struct HookContainer *, void *);
extern struct HookContainer *hook_container_find(const char *);
extern list_node_t *hook_install(struct HookContainer *, hook_function_t, hook_priority_t);
extern void hook_uninstall(struct HookContainer *, hook_function_t);
extern void hook_container_unregister(const char *);
#endif  /* INCLUDED_hook_h */
