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
 * @file server_capab.c
 * @brief Implementation of Server CAPAB related functions.
 *
 * This file provides functions for managing server capabilities in an IRC server.
 * Server capabilities represent features or behaviors that a server supports,
 * and these capabilities can be dynamically added or removed during runtime.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd_defs.h"
#include "server_capab.h"
#include "memory.h"

/** @brief List of server capabilities supported by this IRC server. */
static list_t capab_list;

/**
 * @brief Initialize the server capabilities.
 *
 * This function initializes the server capabilities by adding essential capabilities
 * such as End of Burst (EOB), clustering, and extended realhost UID messages.
 */
void
capab_init(void)
{
  capab_add("EOB", CAPAB_EOB, true);
  capab_add("CLUSTER", CAPAB_CLUSTER, true);
  capab_add("RHOST", CAPAB_RHOST, true);
}

/**
 * @brief Add a capability to the list of supported capabilities.
 *
 * This function adds a new server capability to the list of supported capabilities.
 * The capability is specified by its name, associated integer flag, and an active state.
 * The active state indicates whether the capability is currently active on this server
 * and should be advertised to other servers.
 *
 * @param name String name of the capability.
 * @param flag Integer flag representing the capability.
 * @param active Boolean indicating whether the capability is initially active.
 */
void
capab_add(const char *name, unsigned int flag, bool active)
{
  struct Capability *cap = io_calloc(sizeof(*cap));
  cap->name = io_strdup(name);
  cap->cap = flag;
  cap->active = active;
  list_add(cap, &cap->node, &capab_list);
}

/**
 * @brief Delete a specified capability from the list of known capabilities.
 *
 * This function deletes a specified capability from the list of known capabilities.
 * The capability is identified by its name, and its memory is freed during deletion.
 *
 * @param name String name of the capability to be deleted.
 */
void
capab_del(const char *name)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, capab_list.head)
  {
    struct Capability *cap = node->data;

    if (irccmp(cap->name, name) == 0)
    {
      list_remove(node, &capab_list);
      io_free(cap->name);
      io_free(cap);
    }
  }
}

/**
 * @brief Find and retrieve the integer flag value associated with a given capability name.
 *
 * This function searches for a capability in the list based on its name and returns
 * the associated integer flag value. If the capability is not found, it returns 0.
 *
 * @param name String name of the capability to find.
 * @return Integer flag value of the capability; returns 0 if not found.
 */
unsigned int
capab_find(const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, capab_list.head)
  {
    const struct Capability *cap = node->data;
    if (irccmp(cap->name, name) == 0)
      return cap->cap;
  }

  return 0;
}

/**
 * @brief Show the current server capabilities.
 *
 * This function generates a static string representation of the current server capabilities.
 * The capabilities can be filtered based on a struct Client (ptr), and the active parameter
 * controls whether only active capabilities should be included in the output.
 *
 * @param ptr Pointer to a struct Client (can be NULL).
 * @param active Boolean indicating whether to display only active capabilities.
 * @return Pointer to a static string representing the server capabilities.
 */
const char *
capab_get(const void *ptr, bool active)
{
  static char buf[IRCD_BUFSIZE];
  char *bufptr = buf;

  *bufptr = '\0';  /* buf is static */

  list_node_t *node;
  LIST_FOREACH(node, capab_list.head)
  {
    const struct Capability *cap = node->data;
    if (active && cap->active == false)
      continue;
    if (ptr && !IsCapable(((const struct Client *)ptr), cap->cap))
      continue;

    bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != buf ? " %s" : "%s", cap->name);
  }

  return buf;
}
