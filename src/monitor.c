/*
 * SPDX-FileCopyrightText: 1997 Jukka Santala (Donwulff)
 * SPDX-FileCopyrightText: 2005-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file monitor.c
 * \brief File including functions for MONITOR support
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "io_string.h"
#include "list.h"
#include "memory.h"

#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "monitor.h"
#include "numeric.h"
#include "send.h"

static list_t monitor_hash[HASHSIZE];

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

/*! \brief Looks up the monitor table for a given name
 * \param name Nick name to look up
 */
static struct Monitor *
_monitor_find(const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, monitor_hash[hash_string(name)].head)
  {
    struct Monitor *const monitor = node->data;
    if (io_strcasecmp(monitor->name, name) == 0)
      return monitor;
  }

  return NULL;
}

/*! \brief Unlinks a Monitor struct from its associated hash table
 *         and frees memory.
 * \param monitor Name to remove
 */
static void
_monitor_destroy(struct Monitor *monitor)
{
  assert(monitor->monitored_by.head == NULL);
  assert(list_find(&monitor_hash[hash_string(monitor->name)], monitor));

  list_remove(&monitor->node, &monitor_hash[hash_string(monitor->name)]);
  io_free(monitor->name);
  io_free(monitor);
}

/*! \brief Notifies all clients that have client's name on
 *         their monitor list.
 * \param client Pointer to Client struct
 */
void
monitor_notify_signon(const struct Client *client)
{
  assert(client_is_user(client));

  struct Monitor *const monitor = _monitor_find(client->name);
  if (monitor == NULL)
    return;  /* This name isn't on monitor */

  char buf[NICKLEN + USERLEN + HOSTLEN + 3];  /* +3 for !, @, \0 */
  snprintf(buf, sizeof(buf), "%s!%s@%s", client->name, client->username, client->host);

  /* Send notifies out to everybody on the list in header */
  list_node_t *node;
  LIST_FOREACH(node, monitor->monitored_by.head)
    sendto_one_numeric(node->data, &me, RPL_MONONLINE, buf);
}

/*! \brief Notifies all clients that have client's name on
 *         their monitor list.
 * \param client Pointer to Client struct
 */
void
monitor_notify_signoff(const struct Client *client)
{
  assert(client_is_user(client));

  struct Monitor *const monitor = _monitor_find(client->name);
  if (monitor == NULL)
    return;  /* This name isn't on monitor */

  /* Send notifies out to everybody on the list in header */
  list_node_t *node;
  LIST_FOREACH(node, monitor->monitored_by.head)
    sendto_one_numeric(node->data, &me, RPL_MONOFFLINE, client->name);
}

/*! \brief Adds a monitor entry to client's monitor list if it doesn't exist
 * \param name   Nick name to add
 * \param client Pointer to Client struct
 * \return false if the target is already being monitored, true otherwise
 */
bool
monitor_subscribe(struct Client *client, const char *name)
{
  assert(client_is_local(client));

  struct Monitor *monitor = _monitor_find(name);
  if (monitor == NULL)
  {
    /* First subscriber for this name: create the monitor bucket entry. */
    monitor = io_calloc(sizeof(*monitor));
    monitor->name = io_strdup(name);
    list_add(monitor, &monitor->node, &monitor_hash[hash_string(monitor->name)]);
  }
  else if (list_find(&monitor->monitored_by, client))
    return false;  /* Already subscribed. */

  /* Link both directions: monitor -> client and client -> monitor. */
  list_add(client, list_make_node(), &monitor->monitored_by);
  list_add(monitor, list_make_node(), &client->connection->monitor_list);
  return true;
}

/*! \brief Removes a single entry from client's monitor list
 * \param name   Name to remove
 * \param client Pointer to Client struct
 */
void
monitor_unsubscribe(struct Client *client, const char *name)
{
  assert(client_is_local(client));

  struct Monitor *const monitor = _monitor_find(name);
  if (monitor == NULL)
    return;  /* No header found for that name, i.e. it is not being monitored. */

  list_node_t *node = list_find_remove(&monitor->monitored_by, client);
  if (node == NULL)
    return;  /* This name is not being monitored by this client. */
  list_free_node(node);

  node = list_find_remove(&client->connection->monitor_list, monitor);
  assert(node);
  if (node == NULL)
    return;
  list_free_node(node);

  /* Remove the monitor header if nobody is subscribed anymore. */
  if (list_is_empty(&monitor->monitored_by))
    _monitor_destroy(monitor);
}

/*! \brief Removes all entries from client's monitor list
 *         and deletes headers that are no longer being monitored.
 * \param client Pointer to Client struct
 */
void
monitor_clear_list(struct Client *client)
{
  assert(client_is_local(client));

  list_node_t *monitor_node;
  while ((monitor_node = list_pop_head(&client->connection->monitor_list)))
  {
    struct Monitor *const monitor = monitor_node->data;
    assert(monitor);

    list_free_node(monitor_node);

    list_node_t *const subscriber_node = list_find_remove(&monitor->monitored_by, client);
    assert(subscriber_node);

    if (subscriber_node)
      list_free_node(subscriber_node);

    /* If this leaves a header without notifies, remove it. */
    if (list_is_empty(&monitor->monitored_by))
      _monitor_destroy(monitor);
  }

  assert(list_is_empty(&client->connection->monitor_list));
}

/*! \brief Counts up memory used by monitor list headers
 */
void
monitor_count_memory(uint32_t *const count, size_t *const bytes)
{
  *count = *bytes = 0;

  for (size_t i = 0; i < HASHSIZE; ++i)
  {
    (*count) += list_length(&monitor_hash[i]);

    list_node_t *node;
    LIST_FOREACH(node, monitor_hash[i].head)
    {
      const struct Monitor *const monitor = node->data;
      (*bytes) += strlen(monitor->name) + 1;  /* +1 for '\0' */
    }
  }

  (*bytes) += *count * sizeof(struct Monitor);
}
