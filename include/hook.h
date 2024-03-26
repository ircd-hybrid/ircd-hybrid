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
 * @file hook.h
 * @brief Implements a flexible event hooking interface for modular event handling.
 *
 * This file implements a flexible event hooking interface, enabling functions to register as
 * callbacks for specific events and execute in a chain upon occurrence of the events.
 */

#ifndef INCLUDED_hook_h
#define INCLUDED_hook_h

/**
 * @typedef HCFUNC
 * @brief Typedef for function pointers used as hook callbacks.
 * @param va_list Argument list passed to the hook function.
 * @return void * Return value of the hook function.
 */
typedef void *HCFUNC(va_list);

/**
 * @struct HookContainer
 * @brief Represents a container for hooks.
 *
 * The HookContainer structure holds information about a specific hook,
 * including its name, the chain of hook functions, and usage statistics.
 */
struct HookContainer
{
  dlink_node node;  /**< Doubly-linked list node for container management. */
  char *name;  /**< Name used to identify the callback. */
  dlink_list chain;  /**< Doubly-linked list to store hook functions. */
  unsigned int called;  /**< Number of times the hook has been called. */
  uintmax_t last;  /**< Timestamp of the last time the hook was called. */
};

extern struct HookContainer *hook_container_register(const char *, HCFUNC *);
extern void *hook_run_chain(struct HookContainer *, ...);
extern struct HookContainer *hook_container_find(const char *);
extern dlink_node *hook_install(struct HookContainer *, HCFUNC *);
extern void hook_uninstall(struct HookContainer *, HCFUNC *);
extern void *hook_advance_to_next(dlink_node *, ...);
#endif  /* INCLUDED_hook_h */
