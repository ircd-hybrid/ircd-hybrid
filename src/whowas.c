/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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

/*! \file whowas.c
 * \brief WHOWAS user cache.
 * \version $Id$
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
  for (unsigned int i = 0; i < NICKNAMEHISTORYLENGTH; ++i)
    WHOWAS[i].hashv = -1;
}

void
whowas_add_history(struct Client *client_p, const int online)
{
  static unsigned int whowas_next = 0;
  struct Whowas *const whowas = &WHOWAS[whowas_next];

  assert(IsClient(client_p));

  if (++whowas_next == NICKNAMEHISTORYLENGTH)
    whowas_next = 0;

  if (whowas->hashv != -1)
  {
    if (whowas->online)
      dlinkDelete(&whowas->cnode, &whowas->online->whowas);

    dlinkDelete(&whowas->tnode, &WHOWASHASH[whowas->hashv]);
  }

  whowas->hashv = strhash(client_p->name);
  whowas->shide = IsHidden(client_p->servptr) != 0;
  whowas->logoff = CurrentTime;

  strlcpy(whowas->account, client_p->account, sizeof(whowas->account));
  strlcpy(whowas->name, client_p->name, sizeof(whowas->name));
  strlcpy(whowas->username, client_p->username, sizeof(whowas->username));
  strlcpy(whowas->hostname, client_p->host, sizeof(whowas->hostname));
  strlcpy(whowas->sockhost, client_p->sockhost, sizeof(whowas->sockhost));
  strlcpy(whowas->realname, client_p->info, sizeof(whowas->realname));
  strlcpy(whowas->servername, client_p->servptr->name, sizeof(whowas->servername));

  if (online)
  {
    whowas->online = client_p;
    dlinkAdd(whowas, &whowas->cnode, &client_p->whowas);
  }
  else
    whowas->online = NULL;

  dlinkAdd(whowas, &whowas->tnode, &WHOWASHASH[whowas->hashv]);
}

void
whowas_off_history(struct Client *client_p)
{
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, client_p->whowas.head)
  {
    struct Whowas *whowas = node->data;

    whowas->online = NULL;
    dlinkDelete(&whowas->cnode, &client_p->whowas);
  }
}

struct Client *
whowas_get_history(const char *nick, time_t timelimit)
{
  dlink_node *node = NULL;

  timelimit = CurrentTime - timelimit;

  DLINK_FOREACH(node, WHOWASHASH[strhash(nick)].head)
  {
    struct Whowas *whowas = node->data;

    if (whowas->logoff < timelimit)
      continue;
    if (irccmp(nick, whowas->name))
      continue;
    return whowas->online;
  }

  return NULL;
}

void
whowas_count_memory(unsigned int *const count, size_t *const bytes)
{
  const struct Whowas *whowas = &WHOWAS[0];

  for (unsigned int i = 0; i < NICKNAMEHISTORYLENGTH; ++i, ++whowas)
  {
    if (whowas->hashv != -1)
    {
      (*count)++;
      (*bytes) += sizeof(struct Whowas);
    }
  }
}
