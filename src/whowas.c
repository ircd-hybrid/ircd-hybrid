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
#include "whowas.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "numeric.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"
#include "s_conf.h"
#include "memory.h"

/* internally defined function */
static void add_whowas_to_clist(struct Whowas **, struct Whowas *);
static void del_whowas_from_clist(struct Whowas **, struct Whowas *);
static void add_whowas_to_list(struct Whowas **, struct Whowas *);
static void del_whowas_from_list(struct Whowas **, struct Whowas *);

struct Whowas WHOWAS[NICKNAMEHISTORYLENGTH];
struct Whowas *WHOWASHASH[HASHSIZE];

static unsigned int whowas_next = 0;

void
add_history(struct Client *client_p, int online)
{
  struct Whowas *who = &WHOWAS[whowas_next];

  assert(client_p != NULL);

  if (client_p == NULL)
    return;

  /* XXX when is this possible? Looks like it could happen
   * (with a half registered client.)
   * and what is the correct action here? - Dianora
   */
  if (client_p->servptr == NULL)
    return;

  if (who->hashv != -1)
  {
    if (who->online)
      del_whowas_from_clist(&(who->online->whowas),who);
    del_whowas_from_list(&WHOWASHASH[who->hashv], who);
  }

  who->hashv  = strhash(client_p->name);
  who->logoff = CurrentTime;

  /* NOTE: strcpy ok here, the sizes in the client struct MUST
   * match the sizes in the whowas struct
   */
  strlcpy(who->name, client_p->name, sizeof(who->name));
  strcpy(who->username, client_p->username);
  strcpy(who->hostname, client_p->host);
  strcpy(who->realname, client_p->info);

  strlcpy(who->servername, client_p->servptr->name, sizeof(who->servername));

  if (online)
  {
    who->online = client_p;
    add_whowas_to_clist(&(client_p->whowas), who);
  }
  else
    who->online = NULL;

  add_whowas_to_list(&WHOWASHASH[who->hashv], who);
  whowas_next++;

  if (whowas_next == NICKNAMEHISTORYLENGTH)
    whowas_next = 0;
}

void
off_history(struct Client *client_p)
{
  struct Whowas *temp, *next;

  for (temp = client_p->whowas; temp; temp=next)
  {
    next = temp->cnext;
    temp->online = NULL;
    del_whowas_from_clist(&(client_p->whowas), temp);
  }
}

struct Client *
get_history(const char *nick, time_t timelimit)
{
  struct Whowas *temp;

  timelimit = CurrentTime - timelimit;
  temp = WHOWASHASH[strhash(nick)];

  for (; temp; temp = temp->next)
  {
    if (irccmp(nick, temp->name))
      continue;
    if (temp->logoff < timelimit)
      continue;
    return(temp->online);
  }

  return(NULL);
}

void
count_whowas_memory(int *wwu, unsigned long *wwum)
{
  struct Whowas *tmp;
  int i;
  int u = 0;
  unsigned long um = 0;

  /* count the number of used whowas structs in 'u'   */
  /* count up the memory used of whowas structs in um */
  for (i = 0, tmp = &WHOWAS[0]; i < NICKNAMEHISTORYLENGTH; i++, tmp++)
  {
    if (tmp->hashv != -1)
    {
      u++;
      um += sizeof(struct Whowas);
    }
  }

  *wwu = u;
  *wwum = um;
}

void
init_whowas(void)
{
  int i;

  for (i = 0; i < NICKNAMEHISTORYLENGTH; i++)
  {
    memset(&WHOWAS[i], 0, sizeof(struct Whowas));
    WHOWAS[i].hashv = -1;
  }

  for (i = 0; i < HASHSIZE; ++i)
    WHOWASHASH[i] = NULL;        
}

static void
add_whowas_to_clist(struct Whowas **bucket, struct Whowas *whowas)
{
  whowas->cprev = NULL;

  if ((whowas->cnext = *bucket) != NULL)
    whowas->cnext->cprev = whowas;
  *bucket = whowas;
}
 
static void
del_whowas_from_clist(struct Whowas **bucket, struct Whowas *whowas)
{
  if (whowas->cprev)
    whowas->cprev->cnext = whowas->cnext;
  else
    *bucket = whowas->cnext;
  if (whowas->cnext)
    whowas->cnext->cprev = whowas->cprev;
}

static void
add_whowas_to_list(struct Whowas **bucket, struct Whowas *whowas)
{
  whowas->prev = NULL;

  if ((whowas->next = *bucket) != NULL)
    whowas->next->prev = whowas;
  *bucket = whowas;
}
 
static void
del_whowas_from_list(struct Whowas **bucket, struct Whowas *whowas)
{
  if (whowas->prev)
    whowas->prev->next = whowas->next;
  else
    *bucket = whowas->next;
  if (whowas->next)
    whowas->next->prev = whowas->prev;
}
