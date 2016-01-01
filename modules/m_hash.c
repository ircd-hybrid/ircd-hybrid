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

/*! \file m_hash.c
 * \brief Includes required functions for processing the HASH command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "userhost.h"


/*! \brief HASH command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static int
mo_hash(struct Client *source_p, int parc, char *parv[])
{
  unsigned int i = 0;
  unsigned int max_chain = 0;
  unsigned int buckets   = 0;
  unsigned int count     = 0;
  const struct Client *cl = NULL;
  const struct Client *icl = NULL;
  const struct Channel *ch = NULL;
  const struct UserHost *ush = NULL;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((cl = hash_get_bucket(HASH_TYPE_CLIENT, i)))
    {
      unsigned int len = 0;

      ++buckets;
      for (; cl; cl = cl->hnext)
        ++len;
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one_notice(source_p, &me, ":Client: entries: %u buckets: %u "
                    "max chain: %u", count, buckets, max_chain);

  count     = 0;
  buckets   = 0;
  max_chain = 0;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((ch = hash_get_bucket(HASH_TYPE_CHANNEL, i)))
    {
      unsigned int len = 0;

      ++buckets;
      for (; ch; ch = ch->hnextch)
        ++len;
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one_notice(source_p, &me, ":Channel: entries: %u buckets: %u "
                    "max chain: %u", count, buckets, max_chain);

  count     = 0;
  buckets   = 0;
  max_chain = 0;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((icl = hash_get_bucket(HASH_TYPE_ID, i)))
    {
      unsigned int len = 0;

      ++buckets;
      for (; icl; icl = icl->idhnext)
        ++len;
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one_notice(source_p, &me, ":Id: entries: %u buckets: %u "
                    "max chain: %u", count, buckets, max_chain);

  count     = 0;
  buckets   = 0;
  max_chain = 0;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((ush = hash_get_bucket(HASH_TYPE_USERHOST, i)))
    {
      unsigned int len = 0;

      ++buckets;
      for (; ush; ush = ush->next)
        ++len;
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one_notice(source_p, &me, ":UserHost: entries: %u buckets: %u "
                    "max chain: %u", count, buckets, max_chain);
  return 0;
}

static struct Message hash_msgtab =
{
  .cmd = "HASH",
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = m_ignore,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_hash
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

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
