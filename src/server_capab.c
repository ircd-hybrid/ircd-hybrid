/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file server_capab.c
 * @brief Implementation of Server CAPAB related functions.
 *
 * This file provides functions for managing server capabilities in an IRC server.
 * Server capabilities represent features or behaviors that a server supports,
 * and these capabilities can be dynamically added or removed during runtime.
 */

#include <stdio.h>

#include "io_string.h"
#include "memory.h"

#include "client.h"
#include "ircd_defs.h"
#include "server_capab.h"

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
capab_add(const char *name, uint32_t flag, bool active)
{
  struct Capability *const cap = io_calloc(sizeof(*cap));
  cap->name = io_strdup(name);
  cap->flag = flag;
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
    struct Capability *const cap = node->data;
    if (io_strcasecmp(cap->name, name) == 0)
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
uint32_t
capab_find(const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, capab_list.head)
  {
    const struct Capability *const cap = node->data;
    if (io_strcasecmp(cap->name, name) == 0)
      return cap->flag;
  }

  return 0;
}

/**
 * @brief Generate a string representation of server capabilities.
 *
 * This function generates a static, space-separated string of capability names.
 * If a non-NULL client pointer is passed, the function filters the capabilities to only
 * include those supported by that client (using its capability bitmask). If the client pointer
 * is NULL, then all capabilities in the global list are included (subject to the 'active' flag).
 *
 * @param client Pointer to a Client structure (can be NULL).
 * @param active Boolean indicating whether only active capabilities should be included.
 * @return Pointer to a static string representing the server capabilities.
 */
const char *
capab_get(const struct Client *client, bool active)
{
  static char buf[IRCD_BUFSIZE];
  char *bufptr = buf;

  *bufptr = '\0';  /* Clear the static buffer. */

  list_node_t *node;
  LIST_FOREACH(node, capab_list.head)
  {
    const struct Capability *const cap = node->data;
    if (active && cap->active == false)
      continue;

    if (client && !capab_has_flag(client, cap->flag))
      continue;

    bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != buf ? " %s" : "%s", cap->name);
  }

  return buf;
}
