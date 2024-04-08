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
#include "list.h"
#include "memory.h"
#include "whowas.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "conf.h"

static list_t whowas_list;  /*!< Linked list of struct Whowas pointers. */
static list_t whowas_hash[HASHSIZE];  /*!< Array of linked lists for Whowas entry retrieval based on hash values. */

/**
 * @brief Retrieves a slot of the whowas_hash based on the provided hash value.
 *
 * @param hash_value The hash value used to locate the slot.
 * @return A pointer to the list_t associated with the specified hash value.
 */
const list_t *
whowas_get_hash(unsigned int hash_value)
{
  if (hash_value >= HASHSIZE)
    return NULL;

  return &whowas_hash[hash_value];
}

/**
 * @brief Unlinks a Whowas struct from its associated lists.
 * @param whowas Pointer to the Whowas struct to be unlinked.
 * @return Pointer to the unlinked Whowas struct.
 */
static struct Whowas *
whowas_unlink(struct Whowas *whowas)
{
  if (whowas->client)
    list_delete(&whowas->client_list_node, &whowas->client->whowas_list);

  list_delete(&whowas->hash_node, &whowas_hash[whowas->hash_value]);
  list_delete(&whowas->list_node, &whowas_list);

  return whowas;
}

/**
 * @brief Unlinks a Whowas struct from its associated lists and frees memory.
 * @param whowas Pointer to the Whowas struct to be unlinked and freed.
 */
static void
whowas_free(struct Whowas *whowas)
{
  whowas_unlink(whowas);
  xfree(whowas);
}

/**
 * @brief Retrieves a Whowas struct for further use.
 *
 * Allocates a new Whowas struct or returns the oldest entry from whowas_list
 * if it exceeds the configured history length.
 *
 * @return A pointer to the allocated or reused Whowas struct.
 */
static struct Whowas *
whowas_make(void)
{
  struct Whowas *whowas;

  if (list_length(&whowas_list) &&
      list_length(&whowas_list) >= ConfigGeneral.whowas_history_length)
    whowas = whowas_unlink(whowas_list.tail->data);  /* Re-use oldest item */
  else
    whowas = xcalloc(sizeof(*whowas));

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
  struct Whowas *whowas = whowas_make();

  assert(IsClient(client));

  whowas->hash_value = hash_string(client->name);
  whowas->logoff = event_base->time.sec_real;
  whowas->server_hidden = IsHidden(client->servptr) != 0;

  strlcpy(whowas->account, client->account, sizeof(whowas->account));
  strlcpy(whowas->name, client->name, sizeof(whowas->name));
  strlcpy(whowas->username, client->username, sizeof(whowas->username));
  strlcpy(whowas->hostname, client->host, sizeof(whowas->hostname));
  strlcpy(whowas->realhost, client->realhost, sizeof(whowas->realhost));
  strlcpy(whowas->sockhost, client->sockhost, sizeof(whowas->sockhost));
  strlcpy(whowas->realname, client->info, sizeof(whowas->realname));
  strlcpy(whowas->servername, client->servptr->name, sizeof(whowas->servername));

  if (online)
  {
    whowas->client = client;
    list_add(whowas, &whowas->client_list_node, &client->whowas_list);
  }
  else
    whowas->client = NULL;

  list_add(whowas, &whowas->hash_node, &whowas_hash[whowas->hash_value]);
  list_add(whowas, &whowas->list_node, &whowas_list);
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
    list_delete(&whowas->client_list_node, &client->whowas_list);
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
  timelimit = event_base->time.sec_real - timelimit;

  list_node_t *node;
  LIST_FOREACH(node, whowas_hash[hash_string(name)].head)
  {
    struct Whowas *whowas = node->data;

    if (whowas->logoff < timelimit)
      continue;
    if (irccmp(name, whowas->name))
      continue;
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
  (*count) = list_length(&whowas_list);
  (*bytes) = list_length(&whowas_list) * sizeof(struct Whowas);
}
