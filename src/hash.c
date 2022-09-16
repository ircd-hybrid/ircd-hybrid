/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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

/*! \file hash.c
 * \brief Hash table management.
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


/* The actual hash tables, They MUST be of the same HASHSIZE, variable
 * size tables could be supported but the rehash routine should also
 * rebuild the transformation maps, I kept the tables of equal size
 * so that I can use one hash function.
 */
static struct Client *idTable[HASHSIZE];
static struct Client *clientTable[HASHSIZE];
static struct Channel *channelTable[HASHSIZE];


/*
 * New hash function based on the Fowler/Noll/Vo (FNV) algorithm from
 * http://www.isthe.com/chongo/tech/comp/fnv/
 *
 * Here, we use the FNV-1 method, which gives slightly better results
 * than FNV-1a.   -Michael
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

/************************** Externally visible functions ********************/

/* Optimization note: in these functions I supposed that the CSE optimization
 * (Common Subexpression Elimination) does its work decently, this means that
 * I avoided introducing new variables to do the work myself and I did let
 * the optimizer play with more free registers, actual tests proved this
 * solution to be faster than doing things like tmp2=tmp->hnext... and then
 * use tmp2 myself which would have given less freedom to the optimizer.
 */

/* hash_add_client()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - Adds a client's name in the proper hash linked
 *                list, can't fail, client must have a non-null
 *                name or expect a coredump, the name is infact
 *                taken from client->name
 */
void
hash_add_client(struct Client *client)
{
  const unsigned int hashv = strhash(client->name);

  client->hnext = clientTable[hashv];
  clientTable[hashv] = client;
}

/* hash_add_channel()
 *
 * inputs       - pointer to channel
 * output       - NONE
 * side effects - Adds a channel's name in the proper hash linked
 *                list, can't fail. channel must have a non-null name
 *                or expect a coredump. As before the name is taken
 *                from channel->name, we do hash its entire lenght
 *                since this proved to be statistically faster
 */
void
hash_add_channel(struct Channel *channel)
{
  const unsigned int hashv = strhash(channel->name);

  channel->hnextch = channelTable[hashv];
  channelTable[hashv] = channel;
}

void
hash_add_id(struct Client *client)
{
  const unsigned int hashv = strhash(client->id);

  client->idhnext = idTable[hashv];
  idTable[hashv] = client;
}

/* hash_del_id()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - Removes an ID from the hash linked list
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

/* hash_del_client()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - Removes a Client's name from the hash linked list
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

/* hash_del_channel()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - Removes the channel's name from the corresponding
 *                hash linked list
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

/* hash_find_client()
 *
 * inputs       - pointer to name
 * output       - NONE
 * side effects - New semantics: finds a client whose name is 'name'
 *                if can't find one returns NULL. If it finds one moves
 *                it to the top of the list and returns it.
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

/* hash_find_channel()
 *
 * inputs       - pointer to name
 * output       - NONE
 * side effects - New semantics: finds a channel whose name is 'name',
 *                if can't find one returns NULL, if can find it moves
 *                it to the top of the list and returns it.
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

/* hash_get_bucket(int type, unsigned int hashv)
 *
 * inputs       - hash value (must be between 0 and HASHSIZE - 1)
 * output       - NONE
 * returns      - pointer to first channel in channelTable[hashv]
 *                if that exists;
 *                NULL if there is no channel in that place;
 *                NULL if hashv is an invalid number.
 * side effects - NONE
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

/*
 * Safe list code.
 *
 * The idea is really quite simple. As the link lists pointed to in
 * each "bucket" of the channel hash table are traversed atomically
 * there is no locking needed. Overall, yes, inconsistent reported
 * state can still happen, but normally this isn't a big deal.
 * I don't like sticking the code into hash.c but oh well. Moreover,
 * if a hash isn't used in future, oops.
 *
 * - Dianora
 */

/* exceeding_sendq()
 *
 * inputs       - pointer to client to check
 * output	- 1 if client is in danger of blowing its sendq
 *		  0 if it is not.
 * side effects -
 *
 * Sendq limit is fairly conservative at 1/2 (In original anyway)
 */
static bool
exceeding_sendq(const struct Client *to)
{
  if (dbuf_length(&to->connection->buf_sendq) > (class_get_sendq(&to->connection->confs) / 2))
    return true;
  else
    return false;
}

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

/* list_allow_channel()
 *
 * inputs       - channel name
 *              - pointer to a list task
 * output       - 1 if the channel is to be displayed
 *                0 otherwise
 * side effects -
 */
static bool
list_allow_channel(const char *name, const struct ListTask *lt)
{
  dlink_node *node;

  DLINK_FOREACH(node, lt->show_mask.head)
    if (match(node->data, name) != 0)
      return false;

  DLINK_FOREACH(node, lt->hide_mask.head)
    if (match(node->data, name) == 0)
      return false;

  return true;
}

/* list_one_channel()
 *
 * inputs       - client pointer to return result to
 *              - pointer to channel to list
 *              - pointer to ListTask structure
 * output	- none
 * side effects -
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

/* safe_list_channels()
 *
 * inputs	- pointer to client requesting list
 * output	- 0/1
 * side effects	- safely list all channels to client
 *
 * Walk the channel buckets, ensure all pointers in a bucket are
 * traversed before blocking on a sendq. This means, no locking is needed.
 *
 * - Dianora
 */
void
safe_list_channels(struct Client *client, bool only_unmasked_channels)
{
  struct ListTask *const lt = client->connection->list_task;
  struct Channel *channel;

  if (only_unmasked_channels == false)
  {
    for (unsigned int i = lt->hash_index; i < HASHSIZE; ++i)
    {
      if (exceeding_sendq(client) == true)
      {
        lt->hash_index = i;
        return;  /* Still more to do */
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
