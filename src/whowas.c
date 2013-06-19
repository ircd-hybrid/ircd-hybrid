/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  whowas.c: WHOWAS user cache.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "whowas.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"


static struct Whowas WHOWAS[NICKNAMEHISTORYLENGTH];
dlink_list WHOWASHASH[HASHSIZE];


void
whowas_init(void)
{
  unsigned int idx;

  for (idx = 0; idx < NICKNAMEHISTORYLENGTH; ++idx)
    WHOWAS[idx].hashv = -1;
}

void
add_history(struct Client *client_p, const int online)
{
  static unsigned int whowas_next = 0;
  struct Whowas *who = &WHOWAS[whowas_next];

  assert(client_p && client_p->servptr);

  if (++whowas_next == NICKNAMEHISTORYLENGTH)
    whowas_next = 0;

  if (who->hashv != -1)
  {
    if (who->online)
      dlinkDelete(&who->cnode, &who->online->whowas);

    dlinkDelete(&who->tnode, &WHOWASHASH[who->hashv]);
  }

  who->hashv = strhash(client_p->name);
  who->logoff = CurrentTime;

  strlcpy(who->name, client_p->name, sizeof(who->name));
  strlcpy(who->username, client_p->username, sizeof(who->username));
  strlcpy(who->hostname, client_p->host, sizeof(who->hostname));
  strlcpy(who->realname, client_p->info, sizeof(who->realname));
  strlcpy(who->servername, client_p->servptr->name, sizeof(who->servername));

  if (online)
  {
    who->online = client_p;
    dlinkAdd(who, &who->cnode, &client_p->whowas);
  }
  else
    who->online = NULL;

  dlinkAdd(who, &who->tnode, &WHOWASHASH[who->hashv]);
}

void
off_history(struct Client *client_p)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, client_p->whowas.head)
  {
    struct Whowas *temp = ptr->data;

    temp->online = NULL;
    dlinkDelete(&temp->cnode, &client_p->whowas);
  }
}

struct Client *
get_history(const char *nick, time_t timelimit)
{
  dlink_node *ptr = NULL;

  timelimit = CurrentTime - timelimit;

  DLINK_FOREACH(ptr, WHOWASHASH[strhash(nick)].head)
  {
    struct Whowas *temp = ptr->data;

    if (temp->logoff < timelimit)
      continue;
    if (irccmp(nick, temp->name))
      continue;
    return temp->online;
  }

  return NULL;
}

void
whowas_count_memory(unsigned int *const count, uint64_t *const bytes)
{
  const struct Whowas *tmp = &WHOWAS[0];
  unsigned int i = 0;

  for (; i < NICKNAMEHISTORYLENGTH; ++i, ++tmp)
  {
    if (tmp->hashv != -1)
    {
      (*count)++;
      (*bytes) += sizeof(struct Whowas);
    }
  }
}
