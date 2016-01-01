/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2003-2016 ircd-hybrid development team
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

/*! \file userhost.c
 * \brief Global user limits.
 * \version $Id$
 */

#include "list.h"
#include "hash.h"
#include "client.h"
#include "userhost.h"
#include "mempool.h"
#include "irc_string.h"


static mp_pool_t *userhost_pool;
static mp_pool_t *namehost_pool;


void
userhost_init(void)
{
  userhost_pool = mp_pool_new(sizeof(struct UserHost), MP_CHUNK_SIZE_USERHOST);
  namehost_pool = mp_pool_new(sizeof(struct NameHost), MP_CHUNK_SIZE_NAMEHOST);
}

/* userhost_count()
 *
 * inputs       - user name
 *              - hostname
 *              - int flag 1 if global, 0 if local
 *              - pointer to where global count should go
 *              - pointer to where local count should go
 *              - pointer to where identd count should go (local clients only)
 * output       - none
 * side effects -
 */
void
userhost_count(const char *user, const char *host, unsigned int *global_p,
               unsigned int *local_p, unsigned int *icount_p)
{
  dlink_node *node = NULL;
  struct UserHost *found_userhost;

  if ((found_userhost = hash_find_userhost(host)) == NULL)
    return;

  DLINK_FOREACH(node, found_userhost->list.head)
  {
    struct NameHost *nameh = node->data;

    if (!irccmp(user, nameh->name))
    {
      if (global_p)
        *global_p = nameh->gcount;
      if (local_p)
        *local_p  = nameh->lcount;
      if (icount_p)
        *icount_p = nameh->icount;

      return;
    }
  }
}

/* userhost_find_or_add()
 *
 * inputs       - host name
 * output       - none
 * side effects - find UserHost * for given host name
 */
static struct UserHost *
userhost_find_or_add(const char *host)
{
  struct UserHost *userhost = NULL;

  if ((userhost = hash_find_userhost(host)))
    return userhost;

  userhost = mp_pool_get(userhost_pool);

  strlcpy(userhost->host, host, sizeof(userhost->host));
  hash_add_userhost(userhost);

  return userhost;
}

/* userhost_add()
 *
 * inputs       - user name
 *              - hostname
 *              - int flag 1 if global, 0 if local
 * output       - none
 * side effects - add given user@host to hash tables
 */
void
userhost_add(const char *user, const char *host, int global)
{
  dlink_node *node = NULL;
  struct UserHost *found_userhost;
  struct NameHost *nameh;
  unsigned int hasident = 1;

  if (*user == '~')
  {
    hasident = 0;
    ++user;
  }

  if ((found_userhost = userhost_find_or_add(host)) == NULL)
    return;

  DLINK_FOREACH(node, found_userhost->list.head)
  {
    nameh = node->data;

    if (!irccmp(user, nameh->name))
    {
      nameh->gcount++;

      if (!global)
      {
        if (hasident)
          nameh->icount++;
        nameh->lcount++;
      }

      return;
    }
  }

  nameh = mp_pool_get(namehost_pool);
  nameh->gcount = 1;
  strlcpy(nameh->name, user, sizeof(nameh->name));

  if (!global)
  {
    if (hasident)
      nameh->icount = 1;

    nameh->lcount = 1;
  }

  dlinkAdd(nameh, &nameh->node, &found_userhost->list);
}

/* userhost_del()
 *
 * inputs       - user name
 *              - hostname
 *              - int flag 1 if global, 0 if local
 * output       - none
 * side effects - delete given user@host to hash tables
 */
void
userhost_del(const char *user, const char *host, int global)
{
  dlink_node *node = NULL;
  struct UserHost *found_userhost = NULL;
  unsigned int hasident = 1;

  if (*user == '~')
  {
    hasident = 0;
    ++user;
  }

  if ((found_userhost = hash_find_userhost(host)) == NULL)
    return;

  DLINK_FOREACH(node, found_userhost->list.head)
  {
    struct NameHost *nameh = node->data;

    if (!irccmp(user, nameh->name))
    {
      if (nameh->gcount > 0)
        nameh->gcount--;

      if (!global)
      {
        if (nameh->lcount > 0)
          nameh->lcount--;

        if (hasident && nameh->icount > 0)
          nameh->icount--;
      }

      if (nameh->gcount == 0 && nameh->lcount == 0)
      {
        dlinkDelete(&nameh->node, &found_userhost->list);
        mp_pool_release(nameh);
      }

      if (dlink_list_length(&found_userhost->list) == 0)
      {
        hash_del_userhost(found_userhost);
        mp_pool_release(found_userhost);
      }

      return;
    }
  }
}
