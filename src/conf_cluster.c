/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file conf_cluster.c
 * @brief Implements cluster block configuration management.
 */

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#include "list.h"
#include "memory.h"

#include "conf_cluster.h"
#include "ircd_defs.h"
#include "send.h"
#include "server_capab.h"

static list_t cluster_list;  /**< List to manage cluster items. */

/**
 * @brief Retrieves the list of cluster items.
 *
 * This function returns a pointer to the list of cluster items.
 *
 * @return Pointer to the list of cluster items.
 */
const list_t *
cluster_get_list(void)
{
  return &cluster_list;
}

/**
 * @brief Clears the list of cluster items.
 *
 * This function removes all cluster items from the list and frees their memory.
 */
void
cluster_clear(void)
{
  list_node_t *node;

  while ((node = list_pop_head(&cluster_list)))
  {
    struct ClusterItem *const cluster = node->data;
    assert(cluster);

    io_free(cluster->server);
    io_free(cluster);
  }
}

/**
 * @brief Creates a new cluster item and adds it to the list.
 *
 * This function allocates memory for a new cluster item, adds it to the cluster list,
 * and returns a pointer to the created cluster item.
 *
 * @return Pointer to the newly created cluster item.
 */
struct ClusterItem *
cluster_make(void)
{
  struct ClusterItem *const cluster = io_calloc(sizeof(*cluster));
  list_add_tail(cluster, &cluster->node, &cluster_list);

  return cluster;
}

/**
 * @brief Distributes a command to servers in the cluster.
 *
 * This function sends a command to servers in the cluster based on the specified type
 * and pattern. It formats the command and its arguments and sends it to matching servers.
 *
 * @param client Sender client.
 * @param command IRC command to be distributed.
 * @param capab Capabilities for the command.
 * @param type Type of the command.
 * @param pattern Format string for the command arguments.
 * @param ... Additional arguments for the command.
 */
void
cluster_distribute(const void *client, const char *command, uint32_t capab, uint32_t type,
                   const char *pattern, ...)
{
  char buf[IRCD_BUFSIZE];
  va_list args;

  va_start(args, pattern);
  vsnprintf(buf, sizeof(buf), pattern, args);
  va_end(args);

  list_node_t *node;
  LIST_FOREACH(node, cluster_list.head)
  {
    const struct ClusterItem *const cluster = node->data;
    if (cluster->type & type)
      sendto_match_servs(client, cluster->server, CAPAB_CLUSTER | capab, "%s %s %s",
                         command, cluster->server, buf);
  }
}
