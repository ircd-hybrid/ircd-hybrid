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

/*! \file m_hash.c
 * \brief Includes required functions for processing the HASH command.
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
#include "channel.h"


static void
do_hash(struct Client *source_p, unsigned int type)
{
  unsigned int max_chain = 0;
  unsigned int buckets   = 0;
  unsigned int count     = 0;

  assert(type == HASH_TYPE_CLIENT || type == HASH_TYPE_ID || type == HASH_TYPE_CHANNEL);

  for (unsigned int i = 0; i < HASHSIZE; ++i)
  {
    const void *ptr = hash_get_bucket(type, i);
    if (ptr)
    {
      unsigned int len = 0;
      ++buckets;

      while (ptr)
      {
        if (type == HASH_TYPE_CLIENT)
          ptr = ((const struct Client *)ptr)->hnext;
        else if (type == HASH_TYPE_ID)
          ptr = ((const struct Client *)ptr)->idhnext;
        else /* type == HASH_TYPE_CHANNEL */
          ptr = ((const struct Channel *)ptr)->hnextch;

        if (++len > max_chain)
          max_chain = len;
        count += len;
      }
    }
  }

  static const char *const strtype[] =
  {
    [HASH_TYPE_CLIENT] = "Client",
    [HASH_TYPE_ID] = "Id",
    [HASH_TYPE_CHANNEL] = "Channel",
  };

  sendto_one_notice(source_p, &me, ":%s: entries: %u buckets: %u max chain: %u",
                    strtype[type], count, buckets, max_chain);
}

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
static void
mo_hash(struct Client *source_p, int parc, char *parv[])
{
  do_hash(source_p, HASH_TYPE_CLIENT);
  do_hash(source_p, HASH_TYPE_ID);
  do_hash(source_p, HASH_TYPE_CHANNEL);
}

static struct Message hash_msgtab =
{
  .cmd = "HASH",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_hash }
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
  .modinit = module_init,
  .modexit = module_exit,
};
