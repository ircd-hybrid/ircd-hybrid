/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "s_user.h"
#include "conf.h"
#include "userhost.h"


static void
mo_hash(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  int i;
  int max_chain = 0;
  int buckets   = 0;
  int count     = 0;
  struct Client *cl;
  struct Client *icl;
  struct Channel *ch;
  struct UserHost *ush;
  struct MaskItem *rch;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((cl = hash_get_bucket(HASH_TYPE_CLIENT, i)) != NULL)
    {
      int len = 0;

      ++buckets;
      for (; cl != NULL; cl = cl->hnext)
        ++len;
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :Client: entries: %d buckets: %d "
             "max chain: %d", me.name, source_p->name, count, buckets,
             max_chain);

  count     = 0;
  buckets   = 0;
  max_chain = 0;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((ch = hash_get_bucket(HASH_TYPE_CHANNEL, i)) != NULL)
    {
      int len = 0;

      ++buckets;
      for (; ch != NULL; ch = ch->hnextch)
        ++len;
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :Channel: entries: %d buckets: %d "
             "max chain: %d", me.name, source_p->name, count, buckets,
             max_chain);

  count     = 0;
  buckets   = 0;
  max_chain = 0;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((rch = hash_get_bucket(HASH_TYPE_RESERVED, i)) != NULL)
    {
      int len = 0;

      ++buckets;
      for (; rch != NULL; rch = rch->hnext)
        ++len;
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :Resv: entries: %d buckets: %d "
             "max chain: %d", me.name, source_p->name, count, buckets,
             max_chain);

  count     = 0;
  buckets   = 0;
  max_chain = 0;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((icl = hash_get_bucket(HASH_TYPE_ID, i)) != NULL)
    {
      int len = 0;

      ++buckets;
      for (; icl != NULL; icl = icl->idhnext)
        ++len;
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :Id: entries: %d buckets: %d "
             "max chain: %d", me.name, source_p->name, count, buckets,
             max_chain);

  count     = 0;
  buckets   = 0;
  max_chain = 0;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((ush = hash_get_bucket(HASH_TYPE_USERHOST, i)) != NULL)
    {
      int len = 0;

      ++buckets;
      for (; ush != NULL; ush = ush->next)
        ++len;
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :UserHost: entries: %d buckets: %d "
             "max chain: %d", me.name, source_p->name, count, buckets,
             max_chain);
}

static struct Message hash_msgtab = {
 "HASH", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_hash, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&hash_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&hash_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
