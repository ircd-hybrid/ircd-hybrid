/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997 Jukka Santala (Donwulff)
 *  Copyright (c) 2005-2020 ircd-hybrid development team
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

/*! \file monitor.c
 * \brief File including functions for MONITOR support
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "memory.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "monitor.h"


static dlink_list monitor_hash[HASHSIZE];


/*
 * Rough figure of the datastructures for monitor:
 *
 * MONITOR HASH       client1
 *   |                  |- nick1
 * nick1-|- client1     |- nick2
 *   |   |- client2               client3
 *   |   |- client3   client2       |- nick1
 *   |                  |- nick1
 * nick2-|- client2     |- nick2
 *       |- client1
 */

/*! \brief Counts up memory used by monitor list headers
 */
void
monitor_count_memory(unsigned int *const count, size_t *const bytes)
{
  for (unsigned int i = 0; i < HASHSIZE; ++i)
  {
    dlink_node *node;
    (*count) += dlink_list_length(&monitor_hash[i]);

    DLINK_FOREACH(node, monitor_hash[i].head)
    {
      const struct Monitor *const monitor = node->data;
      (*bytes) += strlen(monitor->name) + 1;  /* +1 for '\0' */
    }
  }

  (*bytes) += *count * sizeof(struct Monitor);
}

/*! \brief Looks up the monitor table for a given name
 * \param name Nick name to look up
 */
static struct Monitor *
monitor_find_hash(const char *name)
{
  dlink_node *node;

  DLINK_FOREACH(node, monitor_hash[strhash(name)].head)
  {
    struct Monitor *monitor = node->data;

    if (irccmp(monitor->name, name) == 0)
      return monitor;
  }

  return NULL;
}

/*! \brief Notifies all clients that have client's name on
 *         their monitor list.
 * \param client Pointer to Client struct
 */
void
monitor_signon(const struct Client *client)
{
  char buf[NICKLEN + USERLEN + HOSTLEN + 3];  /* +3 for !, @, \0 */
  dlink_node *node;

  assert(IsClient(client));

  struct Monitor *monitor = monitor_find_hash(client->name);
  if (monitor == NULL)
    return;  /* This name isn't on monitor */

  snprintf(buf, sizeof(buf), "%s!%s@%s", client->name,
           client->username, client->host);

  /* Send notifies out to everybody on the list in header */
  DLINK_FOREACH(node, monitor->monitored_by.head)
    sendto_one_numeric(node->data, &me, RPL_MONONLINE, buf);
}

/*! \brief Notifies all clients that have client's name on
 *         their monitor list.
 * \param client Pointer to Client struct
 */
void
monitor_signoff(const struct Client *client)
{
  dlink_node *node;

  assert(IsClient(client));

  struct Monitor *monitor = monitor_find_hash(client->name);
  if (monitor == NULL)
    return;  /* This name isn't on monitor */

  /* Send notifies out to everybody on the list in header */
  DLINK_FOREACH(node, monitor->monitored_by.head)
    sendto_one_numeric(node->data, &me, RPL_MONOFFLINE, client->name);
}

/*! \brief Unlinks a Monitor struct from its associated hash table
 *         and frees memory.
 * \param monitor Name to remove
 */
static void
monitor_free(struct Monitor *monitor)
{
  assert(monitor->monitored_by.head == NULL);
  assert(dlinkFind(&monitor_hash[monitor->hash_value], monitor));

  dlinkDelete(&monitor->node, &monitor_hash[monitor->hash_value]);

  xfree(monitor->name);
  xfree(monitor);
}

/*! \brief Adds a monitor entry to client's monitor list if it doesn't exist
 * \param name   Nick name to add
 * \param client Pointer to Client struct
 * \return false if the target is already being monitored, true otherwise
 */
bool
monitor_add_to_hash_table(const char *name, struct Client *client)
{
  dlink_node *node = NULL;

  /* If found NULL (no header for this name), make one... */
  struct Monitor *monitor = monitor_find_hash(name);
  if (monitor == NULL)
  {
    monitor = xcalloc(sizeof(*monitor));
    monitor->name = xstrdup(name);
    monitor->hash_value = strhash(monitor->name);

    dlinkAdd(monitor, &monitor->node, &monitor_hash[monitor->hash_value]);
  }
  else
  {
    /* Is this client already on the monitor-list? */
    node = dlinkFind(&monitor->monitored_by, client);
  }

  if (node == NULL)
  {
    /* No it isn't, so add it in the bucket and client adding it */
    dlinkAdd(client, make_dlink_node(), &monitor->monitored_by);
    dlinkAdd(monitor, make_dlink_node(), &client->connection->monitors);
    return true;
  }

  return false;
}

/*! \brief Removes a single entry from client's monitor list
 * \param name   Name to remove
 * \param client Pointer to Client struct
 */
void
monitor_del_from_hash_table(const char *name, struct Client *client)
{
  struct Monitor *monitor = monitor_find_hash(name);
  if (monitor == NULL)
    return;  /* No header found for that name. i.e. it's not being monitored */

  dlink_node *node = dlinkFindDelete(&monitor->monitored_by, client);
  if (node == NULL)
    return;  /* This name isn't being monitored by client */

  free_dlink_node(node);

  node = dlinkFindDelete(&client->connection->monitors, monitor);
  if (node)
    free_dlink_node(node);

  /* In case this header is now empty of notices, remove it */
  if (monitor->monitored_by.head == NULL)
    monitor_free(monitor);
}

/*! \brief Removes all entries from client's monitor list
 *         and deletes headers that are no longer being monitored.
 * \param client Pointer to Client struct
 */
void
monitor_clear_list(struct Client *client)
{
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, client->connection->monitors.head)
  {
    struct Monitor *monitor = node->data;

    assert(dlinkFind(&monitor->monitored_by, client));

    dlink_node *temp = dlinkFindDelete(&monitor->monitored_by, client);
    if (temp)
      free_dlink_node(temp);

    /* If this leaves a header without notifies, remove it. */
    if (monitor->monitored_by.head == NULL)
      monitor_free(monitor);

    dlinkDelete(node, &client->connection->monitors);
    free_dlink_node(node);
  }

  assert(client->connection->monitors.head == NULL);
  assert(client->connection->monitors.tail == NULL);
}
