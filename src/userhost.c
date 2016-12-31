/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2003-2017 ircd-hybrid development team
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


void
userhost_init(void)
{
  userhost_pool = mp_pool_new(sizeof(struct UserHost), MP_CHUNK_SIZE_USERHOST);
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
userhost_count(const char *host, unsigned int *global_p, unsigned int *local_p)
{
  struct UserHost *userhost;

  if ((userhost = hash_find_userhost(host)) == NULL)
    return;

  if (global_p)
    *global_p = userhost->gcount;
  if (local_p)
    *local_p  = userhost->lcount;
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
  struct UserHost *userhost;

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
userhost_add(const char *host, int global)
{
  struct UserHost *userhost;

  if ((userhost = userhost_find_or_add(host)) == NULL)
    return;

  userhost->gcount++;

  if (!global)
    userhost->lcount++;
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
userhost_del(const char *host, int global)
{
  struct UserHost *userhost;

  if ((userhost = hash_find_userhost(host)) == NULL)
    return;

  if (userhost->gcount > 0)
    userhost->gcount--;

  if (!global)
    if (userhost->lcount > 0)
      userhost->lcount--;

  if (userhost->gcount == 0 && userhost->lcount == 0)
  {
    hash_del_userhost(userhost);
    mp_pool_release(userhost);
  }
}
