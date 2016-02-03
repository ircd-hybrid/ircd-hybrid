/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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

/*! \file conf_cluster.c
 * \brief Implements cluster {} block configuration management.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "memory.h"
#include "conf_cluster.h"
#include "server.h"
#include "send.h"


static dlink_list cluster_list;


const dlink_list *
cluster_get_list(void)
{
  return &cluster_list;
}

void
cluster_clear(void)
{
  while (cluster_list.head)
  {
    struct ClusterItem *cluster = cluster_list.head->data;

    dlinkDelete(&cluster->node, &cluster_list);
    xfree(cluster->server);
    xfree(cluster);
  }
}

struct ClusterItem *
cluster_make(void)
{
  struct ClusterItem *cluster = xcalloc(sizeof(*cluster));
  dlinkAdd(cluster, &cluster->node, &cluster_list);

  return cluster;
}

void
cluster_distribute(void *source_p, const char *command, unsigned int capab,
                   unsigned int type, const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE] = "";
  dlink_node *node;

  va_start(args, pattern);
  vsnprintf(buffer, sizeof(buffer), pattern, args);
  va_end(args);

  DLINK_FOREACH(node, cluster_list.head)
  {
    const struct ClusterItem *cluster = node->data;

    if (cluster->type & type)
      sendto_match_servs(source_p, cluster->server, CAPAB_CLUSTER | capab,
                         "%s %s %s", command, cluster->server, buffer);
  }
}
