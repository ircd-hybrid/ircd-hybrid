/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 1997 Jukka Santala (Donwulff)
 *  Copyright (C) 2005 by the Hybrid Development Team.
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 */

/*! \file watch.c
 * \brief File including functions for WATCH support
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "s_user.h"
#include "s_misc.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "s_serv.h"
#include "send.h"
#include "supported.h"
#include "whowas.h"
#include "memory.h"
#include "mempool.h"
#include "packet.h"
#include "watch.h"


static dlink_list watchTable[HASHSIZE];

static mp_pool_t *watch_pool = NULL;

/*! \brief Initializes the watch table
 */
void
watch_init(void)
{
  watch_pool = mp_pool_new(sizeof(struct Watch), MP_CHUNK_SIZE_WATCH);
}

/*
 * Rough figure of the datastructures for watch:
 *
 * NOTIFY HASH          client_p1
 *   |                    |- nick1
 * nick1-|- client_p1     |- nick2
 *   |   |- client_p2                client_p3
 *   |   |- client_p3   client_p2      |- nick1
 *   |                    |- nick1
 * nick2-|- client_p2     |- nick2
 *       |- client_p1
 */

/*! \brief Counts up memory used by watch list headers
 */
void
watch_count_memory(unsigned int *const count, uint64_t *const memory)
{
  unsigned int idx;

  for (idx = 0; idx < HASHSIZE; ++idx)
    *count += dlink_list_length(&watchTable[idx]);

  *memory = *count * sizeof(struct Watch);
}

/*! \brief Notifies all clients that have client_p's nick name on
 *         their watch list.
 * \param client_p pointer to Client struct
 * \param reply numeric to send. Either RPL_LOGON or RPL_LOGOFF
 */
void
watch_check_hash(struct Client *client_p, int reply)
{
  struct Watch *anptr = NULL;
  dlink_node *ptr = NULL;
  assert(IsClient(client_p));
  if ((anptr = watch_find_hash(client_p->name)) == NULL)
    return;    /* This nick isn't on watch */

  /* Update the time of last change to item */
  anptr->lasttime = CurrentTime;

  /* Send notifies out to everybody on the list in header */
  DLINK_FOREACH(ptr, anptr->watched_by.head)
  {
    struct Client *target_p = ptr->data;

    sendto_one(target_p, form_str(reply),
               me.name, target_p->name, client_p->name,
               client_p->username, client_p->host,
               anptr->lasttime, client_p->info);
  }
}

/*! \brief Looks up the watch table for a given nick
 * \param name nick name to look up
 */
struct Watch *
watch_find_hash(const char *name)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, watchTable[strhash(name)].head)
  {
    struct Watch *anptr = ptr->data;

    if (!irccmp(anptr->nick, name))
      return anptr;
  }

  return NULL;
}

/*! \brief Adds a watch entry to client_p's watch list
 * \param nick     nick name to add
 * \param client_p Pointer to Client struct
 */
void
watch_add_to_hash_table(const char *nick, struct Client *client_p)
{
  struct Watch *anptr = NULL;
  dlink_node *ptr = NULL;

  /* If found NULL (no header for this nick), make one... */
  if ((anptr = watch_find_hash(nick)) == NULL)
  {
    anptr = mp_pool_get(watch_pool);
    memset(anptr, 0, sizeof(*anptr));
    anptr->lasttime = CurrentTime;
    strlcpy(anptr->nick, nick, sizeof(anptr->nick));

    dlinkAdd(anptr, &anptr->node, &watchTable[strhash(nick)]);
  }
  else
  {
    /* Is this client already on the watch-list? */
    ptr = dlinkFind(&anptr->watched_by, client_p);
  }

  if (ptr == NULL)
  {
    /* No it isn't, so add it in the bucket and client addint it */
    dlinkAdd(client_p, make_dlink_node(), &anptr->watched_by);
    dlinkAdd(anptr, make_dlink_node(), &client_p->localClient->watches);
  }
}

/*! \brief Removes a single entry from client_p's watch list
 * \param nick     nick name to remove
 * \param client_p Pointer to Client struct
 */
void
watch_del_from_hash_table(const char *nick, struct Client *client_p)
{
  struct Watch *anptr = NULL;
  dlink_node *ptr = NULL;

  if ((anptr = watch_find_hash(nick)) == NULL)
    return;    /* No header found for that nick. i.e. it's not being watched */

  if ((ptr = dlinkFind(&anptr->watched_by, client_p)) == NULL)
    return;    /* This nick isn't being watched by client_p */

  dlinkDelete(ptr, &anptr->watched_by);
  free_dlink_node(ptr);

  if ((ptr = dlinkFindDelete(&client_p->localClient->watches, anptr)))
    free_dlink_node(ptr);

  /* In case this header is now empty of notices, remove it */
  if (anptr->watched_by.head == NULL)
  {
    assert(dlinkFind(&watchTable[strhash(nick)], anptr) != NULL);
    dlinkDelete(&anptr->node, &watchTable[strhash(nick)]);
    mp_pool_release(anptr);
  }
}

/*! \brief Removes all entries from client_p's watch list
 *         and deletes headers that are no longer being watched.
 * \param client_p Pointer to Client struct
 */
void
watch_del_watch_list(struct Client *client_p)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;
  dlink_node *tmp = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, client_p->localClient->watches.head)
  {
    struct Watch *anptr = ptr->data;

    assert(anptr);

    assert(dlinkFind(&anptr->watched_by, client_p) != NULL);
    if ((tmp = dlinkFindDelete(&anptr->watched_by, client_p)))
      free_dlink_node(tmp);

    /* If this leaves a header without notifies, remove it. */
    if (anptr->watched_by.head == NULL)
    {
      assert(dlinkFind(&watchTable[strhash(anptr->nick)], anptr) != NULL);
      dlinkDelete(&anptr->node, &watchTable[strhash(anptr->nick)]);

      mp_pool_release(anptr);
    }

    dlinkDelete(ptr, &client_p->localClient->watches);
    free_dlink_node(ptr);
  }

  assert(client_p->localClient->watches.head == NULL);
  assert(client_p->localClient->watches.tail == NULL);
}
