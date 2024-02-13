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
 * @file hash.c
 * @brief Hash table management.
 *
 * This file contains functions and structures related to hash table management.
 * The hash tables are used to efficiently store and retrieve information about
 * clients, channels, and IDs.
 */

#include "stdinc.h"
#include "list.h"
#include "conf.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "id.h"
#include "rng_mt.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "memory.h"
#include "dbuf.h"

/**
 * @var static struct Client *idTable[HASHSIZE]
 * @brief Hash table storing pointers to clients based on their IDs.
 *
 * @var static struct Client *clientTable[HASHSIZE]
 * @brief Hash table storing pointers to clients based on their names.
 *
 * @var static struct Channel *channelTable[HASHSIZE]
 * @brief Hash table storing pointers to channels based on their names.
 *
 * These hash tables are used for efficient retrieval of clients and channels
 * based on either their unique identifiers (IDs) or names. The tables have a
 * fixed size specified by HASHSIZE, and it is crucial that all hash tables
 * (idTable, clientTable, and channelTable) have the same size. While variable
 * size tables could be supported theoretically, it would require additional
 * complexity in the rehashing routine to rebuild the transformation maps.
 * Keeping all tables of equal size ensures that only one hash function needs
 * to be used, simplifying the implementation.
 */
static struct Client *idTable[HASHSIZE];
static struct Client *clientTable[HASHSIZE];
static struct Channel *channelTable[HASHSIZE];

/**
 * @brief Generate a hash value for the given string using the FNV-1 algorithm with a random XOR key to mitigate hash table degeneration attacks.
 *
 * This function employs the Fowler/Noll/Vo (FNV) algorithm, specifically the FNV-1
 * method, to produce a hash value for the provided string. FNV-1 is chosen for its
 * slightly superior results compared to FNV-1a in this context. The algorithm iterates
 * over each character of the input string, incorporating it into the hash calculation.
 * To counteract possible hash table degeneration attacks, a random XOR key is introduced.
 * Hash table degeneration attacks aim to exploit weaknesses in hash functions by causing
 * many keys to hash to the same values, leading to poor performance. The random XOR key
 * adds an element of unpredictability, making it harder for attackers to manipulate input
 * in a way that causes clustering in the hash table and degrades its efficiency.
 *
 * @param name A pointer to the null-terminated string for which the hash is generated.
 * @return The calculated hash value for the input string.
 */
unsigned int
strhash(const char *name)
{
  static unsigned int hashf_xor_key = 0;
  const unsigned char *p = (const unsigned char *)name;
  unsigned int hval = FNV1_32_INIT;

  if (EmptyString(p))
    return 0;

  if (hashf_xor_key == 0)
    do
      hashf_xor_key = genrand_int32() % 256;  /* better than nothing --adx */
    while (hashf_xor_key == 0);

  for (; *p; ++p)
  {
    hval += (hval << 1) + (hval << 4) +
            (hval << 7) + (hval << 8) + (hval << 24);
    hval ^= (ToLower(*p) ^ hashf_xor_key);
  }

  return (hval >> FNV1_32_BITS) ^ (hval & ((1 << FNV1_32_BITS) - 1));
}

/**
 * @brief Add a client to the client hash table.
 *
 * This function adds a client to the client hash table based on its name.
 *
 * @param client A pointer to the client to be added.
 */
void
hash_add_client(struct Client *client)
{
  const unsigned int hashv = strhash(client->name);

  client->hnext = clientTable[hashv];
  clientTable[hashv] = client;
}

/**
 * @brief Add a channel to the channel hash table.
 *
 * This function adds a channel to the channel hash table based on its name.
 *
 * @param channel A pointer to the channel to be added.
 */
void
hash_add_channel(struct Channel *channel)
{
  const unsigned int hashv = strhash(channel->name);

  channel->hnextch = channelTable[hashv];
  channelTable[hashv] = channel;
}

/**
 * @brief Add a client to the ID hash table.
 *
 * This function adds a client to the ID hash table based on its ID.
 *
 * @param client A pointer to the client to be added.
 */
void
hash_add_id(struct Client *client)
{
  const unsigned int hashv = strhash(client->id);

  client->idhnext = idTable[hashv];
  idTable[hashv] = client;
}

/**
 * @brief Remove a client from the ID hash table.
 *
 * This function removes a client from the ID hash table.
 *
 * @param client A pointer to the client to be removed.
 */
void
hash_del_id(struct Client *client)
{
  const unsigned int hashv = strhash(client->id);
  struct Client *tmp = idTable[hashv];

  if (tmp)
  {
    if (tmp == client)
    {
      idTable[hashv] = client->idhnext;
      client->idhnext = client;
    }
    else
    {
      while (tmp->idhnext != client)
        if ((tmp = tmp->idhnext) == NULL)
          return;

      tmp->idhnext = tmp->idhnext->idhnext;
      client->idhnext = client;
    }
  }
}

/**
 * @brief Remove a client from the client hash table.
 *
 * This function removes a client from the client hash table.
 *
 * @param client A pointer to the client to be removed.
 */
void
hash_del_client(struct Client *client)
{
  const unsigned int hashv = strhash(client->name);
  struct Client *tmp = clientTable[hashv];

  if (tmp)
  {
    if (tmp == client)
    {
      clientTable[hashv] = client->hnext;
      client->hnext = client;
    }
    else
    {
      while (tmp->hnext != client)
        if ((tmp = tmp->hnext) == NULL)
          return;

      tmp->hnext = tmp->hnext->hnext;
      client->hnext = client;
    }
  }
}

/**
 * @brief Remove a channel from the channel hash table.
 *
 * This function removes a channel from the channel hash table.
 *
 * @param channel A pointer to the channel to be removed.
 */
void
hash_del_channel(struct Channel *channel)
{
  const unsigned int hashv = strhash(channel->name);
  struct Channel *tmp = channelTable[hashv];

  if (tmp)
  {
    if (tmp == channel)
    {
      channelTable[hashv] = channel->hnextch;
      channel->hnextch = channel;
    }
    else
    {
      while (tmp->hnextch != channel)
        if ((tmp = tmp->hnextch) == NULL)
          return;

      tmp->hnextch = tmp->hnextch->hnextch;
      channel->hnextch = channel;
    }
  }
}

/**
 * @brief Find a client based on its name in the client hash table.
 *
 * This function searches for a client in the client hash table based on its name.
 * If found, it moves the client to the top of the list and returns it.
 * This reordering of the list optimizes subsequent lookups for the same name.
 *
 * @param name The name of the client to find.
 * @return A pointer to the found client, or NULL if not found.
 */
struct Client *
hash_find_client(const char *name)
{
  const unsigned int hashv = strhash(name);
  struct Client *client;

  if ((client = clientTable[hashv]))
  {
    if (irccmp(name, client->name))
    {
      struct Client *prev;

      while (prev = client, (client = client->hnext))
      {
        if (irccmp(name, client->name) == 0)
        {
          prev->hnext = client->hnext;
          client->hnext = clientTable[hashv];
          clientTable[hashv] = client;
          break;
        }
      }
    }
  }

  return client;
}

/**
 * @brief Find a client based on its ID in the ID hash table.
 *
 * This function searches for a client in the ID hash table based on its ID.
 * If found, it moves the client to the top of the list and returns it.
 * This reordering of the list optimizes subsequent lookups for the same ID.
 *
 * @param name The ID of the client to find.
 * @return A pointer to the found client, or NULL if not found.
 */
struct Client *
hash_find_id(const char *name)
{
  const unsigned int hashv = strhash(name);
  struct Client *client;

  if ((client = idTable[hashv]))
  {
    if (strcmp(name, client->id))
    {
      struct Client *prev;

      while (prev = client, (client = client->idhnext))
      {
        if (strcmp(name, client->id) == 0)
        {
          prev->idhnext = client->idhnext;
          client->idhnext = idTable[hashv];
          idTable[hashv] = client;
          break;
        }
      }
    }
  }

  return client;
}

/**
 * @brief Find a server based on its name in the server hash table.
 *
 * This function searches for a server in the server hash table based on its name.
 * If found, it moves the server to the top of the list and returns it.
 * This reordering of the list optimizes subsequent lookups for the same name.
 *
 * @param name The name of the server to find.
 * @return A pointer to the found server, or NULL if not found.
 */
struct Client *
hash_find_server(const char *name)
{
  const unsigned int hashv = strhash(name);
  struct Client *client;

  if (IsDigit(*name) && strlen(name) == IRC_MAXSID)
    return hash_find_id(name);

  if ((client = clientTable[hashv]))
  {
    if ((!IsServer(client) && !IsMe(client)) ||
        irccmp(name, client->name))
    {
      struct Client *prev;

      while (prev = client, (client = client->hnext))
      {
        if ((IsServer(client) || IsMe(client)) &&
            irccmp(name, client->name) == 0)
        {
          prev->hnext = client->hnext;
          client->hnext = clientTable[hashv];
          clientTable[hashv] = client;
          break;
        }
      }
    }
  }

  return client;
}

/**
 * @brief Find a channel based on its name in the channel hash table.
 *
 * This function searches for a channel in the channel hash table based on its name.
 * If found, it moves the channel to the top of the list and returns it.
 * This reordering of the list optimizes subsequent lookups for the same name.
 *
 * @param name The name of the channel to find.
 * @return A pointer to the found channel, or NULL if not found.
 */
struct Channel *
hash_find_channel(const char *name)
{
  const unsigned int hashv = strhash(name);
  struct Channel *channel;

  if ((channel = channelTable[hashv]))
  {
    if (irccmp(name, channel->name))
    {
      struct Channel *prev;

      while (prev = channel, (channel = channel->hnextch))
      {
        if (irccmp(name, channel->name) == 0)
        {
          prev->hnextch = channel->hnextch;
          channel->hnextch = channelTable[hashv];
          channelTable[hashv] = channel;
          break;
        }
      }
    }
  }

  return channel;
}

/**
 * @brief Get the first entry in a specific hash bucket.
 *
 * This function retrieves the first entry in a specific hash bucket based on the hash type.
 *
 * @param type The type of hash (HASH_TYPE_ID, HASH_TYPE_CHANNEL, HASH_TYPE_CLIENT).
 * @param hashv The hash value indicating the bucket.
 * @return A pointer to the first entry in the specified hash bucket.
 */
void *
hash_get_bucket(int type, unsigned int hashv)
{
  assert(hashv < HASHSIZE);

  if (hashv >= HASHSIZE)
    return NULL;

  switch (type)
  {
    case HASH_TYPE_ID:
      return idTable[hashv];
      break;
    case HASH_TYPE_CHANNEL:
      return channelTable[hashv];
      break;
    case HASH_TYPE_CLIENT:
      return clientTable[hashv];
      break;
    default:
      assert(0);
  }

  return NULL;
}

/**
 * @brief Check if the send queue of a client is close to its limit.
 *
 * This function determines whether the send queue of a client is close to its limit,
 * providing a conservative estimate to avoid excessive queue growth. The calculation
 * considers the client's send queue length in comparison to half of its configured
 * maximum send queue size.
 *
 * @param to A pointer to the client to check.
 * @return true if the client is in danger of exhausting its send queue, false otherwise.
 */
static bool
exceeding_sendq(const struct Client *to)
{
  if (dbuf_length(&to->connection->buf_sendq) > (class_get_sendq(&to->connection->confs) / 2))
    return true;
  else
    return false;
}

/**
 * @brief Frees resources associated with a ListTask for a given client.
 *
 * This function is responsible for freeing the memory allocated for the ListTask
 * associated with the specified client. The ListTask contains information about
 * channel listing preferences for the client, including show and hide masks.
 * Additionally, it removes the client from the global list of clients with active
 * list tasks.
 *
 * @param client Pointer to the client for which the ListTask resources are to be freed.
 */
void
free_list_task(struct Client *client)
{
  struct ListTask *const lt = client->connection->list_task;
  dlink_node *node, *node_next;

  dlinkDelete(&lt->node, &listing_client_list);

  DLINK_FOREACH_SAFE(node, node_next, lt->show_mask.head)
  {
    xfree(node->data);
    dlinkDelete(node, &lt->show_mask);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, lt->hide_mask.head)
  {
    xfree(node->data);
    dlinkDelete(node, &lt->hide_mask);
    free_dlink_node(node);
  }

  xfree(lt);
  client->connection->list_task = NULL;
}

/**
 * @brief Allow listing a channel based on show/hide masks.
 *
 * This function determines whether a channel is allowed to be listed based on show/hide masks.
 *
 * @param name The name of the channel to check.
 * @param lt A pointer to the ListTask structure.
 * @return true if the channel is allowed, false otherwise.
 */
static bool
list_allow_channel(const char *name, const struct ListTask *lt)
{
  dlink_node *node;

  DLINK_FOREACH(node, lt->show_mask.head)
    if (match(node->data, name) != 0)
      return false;

  if (dlinkFindCmp(&lt->hide_mask, name, match))
    return false;

  return true;
}

/**
 * @brief Lists information about a single channel to a client.
 *
 * This function lists information about a single channel to the specified client,
 * based on the client's list task preferences. It checks various criteria such as
 * the number of users in the channel, creation time, topic, and mode to determine
 * whether the channel should be listed to the client.
 *
 * @param client Pointer to the client to which channel information is to be sent.
 * @param channel Pointer to the channel for which information is to be listed.
 */
static void
list_one_channel(struct Client *client, struct Channel *channel)
{
  const struct ListTask *const lt = client->connection->list_task;
  char buf[MODEBUFLEN];

  if (HasCMode(channel, MODE_SECRET) &&
      !(HasUMode(client, UMODE_ADMIN) || member_find_link(client, channel)))
    return;

  if (dlink_list_length(&channel->members) < lt->users_min ||
      dlink_list_length(&channel->members) > lt->users_max ||
      (channel->creation_time != 0 &&
       ((unsigned int)channel->creation_time < lt->created_min ||
        (unsigned int)channel->creation_time > lt->created_max)) ||
      (unsigned int)channel->topic_time < lt->topicts_min ||
      (channel->topic_time ? (unsigned int)channel->topic_time : UINT_MAX) >
      lt->topicts_max)
    return;

  if (lt->topic[0] && match(lt->topic, channel->topic))
    return;

  if (list_allow_channel(channel->name, lt) == false)
    return;

  if (channel->topic[0])
    snprintf(buf, sizeof(buf), "[%s] ",
             channel_modes(channel, client, false));
  else
    snprintf(buf, sizeof(buf), "[%s]",
             channel_modes(channel, client, false));

  sendto_one_numeric(client, &me, RPL_LIST, channel->name,
                     dlink_list_length(&channel->members),
                     buf, channel->topic);
}

/**
 * @brief Safely lists channels to the client without risking sendq limits.
 *
 * This function safely lists channels to the specified client without risking sendq limits.
 * It traverses the channel hash table buckets atomically to ensure safe traversal of linked lists.
 * If the only_unmasked_channels flag is set, it only lists channels that are not masked by the client's
 * ListTask structure. The function also takes into account various conditions, such as channel user count,
 * creation time, topic time, and other criteria specified in the ListTask structure.
 *
 * @param client Pointer to the client requesting the list.
 * @param only_unmasked_channels Flag to list only unmasked channels.
 *
 * @note The function follows a simple idea where link lists in each "bucket" of the channel hash table are
 *       traversed atomically, eliminating the need for locking. While inconsistent reported state may still
 *       happen, it is generally not a significant issue.
 */
void
safe_list_channels(struct Client *client, bool only_unmasked_channels)
{
  struct ListTask *const lt = client->connection->list_task;
  struct Channel *channel;

  /* If only_unmasked_channels is false, list all channels. */
  if (only_unmasked_channels == false)
  {
    for (unsigned int i = lt->hash_index; i < HASHSIZE; ++i)
    {
      /* Check if the client is in danger of exceeding its sendq. */
      if (exceeding_sendq(client) == true)
      {
        lt->hash_index = i;
        return;  /* Still more channels to list. */
      }

      for (channel = channelTable[i]; channel; channel = channel->hnextch)
        list_one_channel(client, channel);
    }
  }
  else
  {
    dlink_node *node;

    DLINK_FOREACH(node, lt->show_mask.head)
      if ((channel = hash_find_channel(node->data)))
        list_one_channel(client, channel);
  }

  free_list_task(client);
  sendto_one_numeric(client, &me, RPL_LISTEND);
}
