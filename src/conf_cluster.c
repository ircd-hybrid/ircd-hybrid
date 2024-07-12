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
 * @file conf_cluster.c
 * @brief Implements cluster block configuration management.
 */

#include "stdinc.h"
#include "ircd_defs.h"
#include "list.h"
#include "memory.h"
#include "conf_cluster.h"
#include "server_capab.h"
#include "send.h"

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
  while (cluster_list.head)
  {
    struct ClusterItem *cluster = cluster_list.head->data;
    list_remove(&cluster->node, &cluster_list);
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
  struct ClusterItem *cluster = io_calloc(sizeof(*cluster));
  list_add(cluster, &cluster->node, &cluster_list);

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
cluster_distribute(const void *client, const char *command, unsigned int capab,
                   unsigned int type, const char *pattern, ...)
{
  char buf[IRCD_BUFSIZE];

  va_list args;
  va_start(args, pattern);
  vsnprintf(buf, sizeof(buf), pattern, args);
  va_end(args);

  list_node_t *node;
  LIST_FOREACH(node, cluster_list.head)
  {
    const struct ClusterItem *cluster = node->data;
    if (cluster->type & type)
      sendto_match_servs(client, cluster->server, CAPAB_CLUSTER | capab, "%s %s %s",
                         command, cluster->server, buf);
  }
}
