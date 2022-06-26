/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2022-2022 ircd-hybrid development team
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

/*! \file m_mlock.c
 * \brief Includes required functions for processing the MLOCK command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "server_capab.h"


/*! \brief MLOCK command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = timestamp
 *      - parv[2] = channel name
 *      - parv[3] = modes to be locked
 */
static void
ms_mlock(struct Client *source_p, int parc, char *parv[])
{
  assert(!MyClient(source_p));

  struct Channel *channel = hash_find_channel(parv[2]);
  if (channel == NULL)
    return;

  if (strtoumax(parv[1], NULL, 10) <= channel->creation_time)
    channel_set_mode_lock(source_p, channel, parv[3]);

  sendto_server(source_p, CAPAB_MLOCK, 0, ":%s MLOCK %ju %s :%s",
                source_p->id, channel->creation_time, channel->name,
                channel->mode_lock ? channel->mode_lock : "");
}

static struct Message mlock_msgtab =
{
  .cmd = "MLOCK",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_ignore },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_mlock, .args_min = 3, .empty_last_arg = true },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&mlock_msgtab);
  capab_add("MLOCK", CAPAB_MLOCK, true);
}

static void
module_exit(void)
{
  mod_del_cmd(&mlock_msgtab);
  capab_del("MLOCK");
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
  .is_core = true
};
