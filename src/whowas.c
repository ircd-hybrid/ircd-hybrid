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
 * @file whowas.c
 * @brief Implementation of the WHOWAS user cache.
 *
 * This file contains the implementation of a data structure and functions used for
 * storing historical information about IRC users.
 */

#include "stdinc.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"
#include "irc_string.h"
#include "client.h"
#include "hash.h"
#include "conf.h"
#include "whowas.h"

static list_t whowas_list;  /*!< Linked list of struct Whowas pointers. */
static list_t whowas_hash[HASHSIZE];  /*!< Array of linked lists for Whowas entry retrieval based on hash values. */

/**
 * @brief Finds a WhowasGroup entry for the given nickname.
 *
 * @param name The nickname string.
 * @return A pointer to the WhowasGroup struct if found, or NULL if not found.
 */
struct WhowasGroup *
whowas_group_find(const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, whowas_hash[hash_string(name)].head)
  {
    struct WhowasGroup *group = node->data;
    if (irccmp(group->name, name) == 0)
      return group;
  }

  return NULL;
}

/**
 * @brief Creates a new WhowasGroup entry for the given nickname.
 *
 * @param name The nickname string.
 * @return A pointer to the newly created WhowasGroup struct.
 */
static struct WhowasGroup *
whowas_group_make(const char *name)
{
  struct WhowasGroup *group = io_calloc(sizeof(*group));
  group->name = io_strdup(name);
  group->hash_value = hash_string(name);
  list_add(group, &group->hash_node, &whowas_hash[group->hash_value]);

  return group;
}

/**
 * @brief Frees a WhowasGroup entry if its list is empty.
 *
 * @param group Pointer to the WhowasGroup struct to be freed.
 */
static void
whowas_group_free(struct WhowasGroup *group)
{
  if (list_is_empty(&group->whowas_records) == false)
    return;

  list_remove(&group->hash_node, &whowas_hash[group->hash_value]);
  io_free(group->name);
  io_free(group);
}

/**
 * @brief Unlinks a Whowas struct from its associated lists and frees memory.
 * @param whowas Pointer to the Whowas struct to be unlinked and freed.
 */
static void
whowas_free(struct Whowas *whowas)
{
  if (whowas->client)
    list_remove(&whowas->client_list_node, &whowas->client->whowas_list);

  list_remove(&whowas->whowas_list_node, &whowas_list);
  list_remove(&whowas->group_list_node, &whowas->group->whowas_records);

  whowas_group_free(whowas->group);

  io_free(whowas->name);
  io_free(whowas->username);
  io_free(whowas->hostname);
  io_free(whowas->realhost);
  io_free(whowas->sockhost);
  io_free(whowas->realname);
  io_free(whowas->account);
  io_free(whowas->servername);
  io_free(whowas);
}

/**
 * @brief Retrieves a Whowas struct for further use.
 *
 * Allocates a new Whowas struct and frees the oldest entry from whowas_list
 * if it exceeds the configured history length.
 *
 * @return A pointer to the allocated Whowas struct.
 */
static struct Whowas *
whowas_make(void)
{
  if (list_length(&whowas_list) &&
      list_length(&whowas_list) >= ConfigGeneral.whowas_history_length)
    whowas_free(whowas_list.tail->data);  /* Free oldest item. */

  struct Whowas *whowas = io_calloc(sizeof(*whowas));
  return whowas;
}

/**
 * @brief Trims the Whowas history to the configured maximum length.
 *
 * Removes Whowas entries from the end of the Whowas history list until
 * the total number of entries is within the specified maximum limit
 * (ConfigGeneral.whowas_history_length). This function is called to
 * maintain the size of the Whowas history within acceptable bounds.
 */
void
whowas_trim(void)
{
  while (list_length(&whowas_list) &&
         list_length(&whowas_list) >= ConfigGeneral.whowas_history_length)
    whowas_free(whowas_list.tail->data);
}

/**
 * @brief Adds a Whowas struct to the whowas list and the nickname-specific list.
 *
 * @param whowas Pointer to the Whowas struct to be added.
 * @param client Pointer to the Client struct.
 * @param online Boolean indicating whether the client is online.
 */
static void
whowas_add(struct Whowas *whowas, struct Client *client, bool online)
{
  whowas->group = whowas_group_find(whowas->name);
  if (whowas->group == NULL)
    whowas->group = whowas_group_make(whowas->name);

  if (online)
  {
    whowas->client = client;
    list_add(whowas, &whowas->client_list_node, &client->whowas_list);
  }
  else
    whowas->client = NULL;

  list_add(whowas, &whowas->whowas_list_node, &whowas_list);
  list_add(whowas, &whowas->group_list_node, &whowas->group->whowas_records);
}

/**
 * @brief Adds the current client's name to the history.
 *
 * This function is usually called before changing to a new name (nick).
 * The client must be a fully registered user.
 *
 * @param client A pointer to the Client struct to add to the Whowas history.
 * @param online A boolean indicating whether it's a nick change (true) or client exit (false).
 */
void
whowas_add_history(struct Client *client, bool online)
{
  assert(IsClient(client));

  struct Whowas *whowas = whowas_make();
  whowas->logoff = io_time_get(IO_TIME_REALTIME_SEC);
  whowas->server_hidden = IsHidden(client->servptr) != 0;
  whowas->name = io_strdup(client->name);
  whowas->username = io_strdup(client->username);
  whowas->hostname = io_strdup(client->host);
  whowas->realhost = io_strdup(client->realhost);
  whowas->sockhost = io_strdup(client->sockhost);
  whowas->realname = io_strdup(client->info);
  whowas->account = io_strdup(client->account);
  whowas->servername = io_strdup(client->servptr->name);

  whowas_add(whowas, client, online);
}

/**
 * @brief Clears the Whowas history entries associated with a specific client.
 *
 * Removes all Whowas entries linked to the specified client from the Whowas history.
 * This function is typically called when a client structure is about to be released,
 * ensuring that the Whowas history no longer references the client after its termination.
 *
 * @param client Pointer to the Client struct for which Whowas history entries should be cleared.
 */
void
whowas_off_history(struct Client *client)
{
  while (client->whowas_list.head)
  {
    struct Whowas *whowas = client->whowas_list.head->data;
    whowas->client = NULL;
    list_remove(&whowas->client_list_node, &client->whowas_list);
  }
}

/**
 * @brief Retrieves the most recent client associated with a given nickname within a specified time limit.
 *
 * Searches the Whowas history to find a client that was using the provided nickname within the given time limit.
 * If a matching entry is found, it returns a pointer to the associated Client struct; otherwise, it returns NULL.
 *
 * @param name      The name of the nickname to search for.
 * @param timelimit The maximum age for a client since log-off.
 * @return A pointer to the Client struct representing the most recent user of the specified nickname within the time limit, or NULL if not found.
 */
struct Client *
whowas_get_history(const char *name, uintmax_t timelimit)
{
  struct WhowasGroup *group = whowas_group_find(name);
  if (group == NULL)
    return NULL;

  timelimit = io_time_get(IO_TIME_REALTIME_SEC) - timelimit;

  list_node_t *node;
  LIST_FOREACH(node, group->whowas_records.head)
  {
    struct Whowas *whowas = node->data;
    if (whowas->logoff >= timelimit)
      return whowas->client;
  }

  return NULL;
}

/**
 * @brief Counts the allocated structures stored in whowas_list for debugging purposes.
 *
 * @param count A pointer to an unsigned integer to store the count of allocated structures.
 * @param bytes A pointer to a size_t to store the total memory occupied by the structures.
 */
void
whowas_count_memory(unsigned int *const count, size_t *const bytes)
{
  *count = list_length(&whowas_list);
  *bytes = list_length(&whowas_list) * sizeof(struct Whowas);

  list_node_t *node;
  LIST_FOREACH(node, whowas_list.head)
  {
    const struct Whowas *const whowas = node->data;
    *bytes += strlen(whowas->account) + 1;
    *bytes += strlen(whowas->name) + 1;
    *bytes += strlen(whowas->username) + 1;
    *bytes += strlen(whowas->hostname) + 1;
    *bytes += strlen(whowas->realhost) + 1;
    *bytes += strlen(whowas->sockhost) + 1;
    *bytes += strlen(whowas->realname) + 1;
    *bytes += strlen(whowas->servername) + 1;
  }
}
