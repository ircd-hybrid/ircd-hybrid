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

/*! \file m_resync.c
 * \brief Includes required functions for processing the RESYNC command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "server.h"
#include "server_capab.h"
#include "hash.h"
#include "channel.h"


/*! \brief RESYNC command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 */
static void
ms_resync(struct Client *source_p, int parc, char *parv[])
{
  assert(MyConnect(source_p));
  assert(IsServer(source_p));

  if (!MyConnect(source_p) || !IsServer(source_p))
    return;

  struct Channel *channel = hash_find_channel(parv[1]);
  if (channel == NULL)
    return;

  channel_send_modes(source_p, channel);
}

static struct Message resync_msgtab =
{
  .cmd = "RESYNC",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered  },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_resync },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&resync_msgtab);
  capab_add("RESYNC", CAPAB_RESYNC, true);
}

static void
module_exit(void)
{
  mod_del_cmd(&resync_msgtab);
  capab_del("RESYNC");
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
