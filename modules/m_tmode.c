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

/*! \file m_tmode.c
 * \brief Includes required functions for processing the TMODE command.
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
#include "module.h"


/*! \brief TMODE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = timestamp
 *      - parv[2] = channel name
 *      - parv[3] = modes to be added or removed
 */
static void
ms_tmode(struct Client *source, int parc, char *parv[])
{
  assert(!MyClient(source));

  struct Channel *channel = hash_find_channel(parv[2]);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, parv[2]);
    return;
  }

  if (strtoumax(parv[1], NULL, 10) > channel->creation_time)
    return;

  channel_mode_set(source, channel, parc - 3, parv + 3);
}

static struct Command tmode_msgtab =
{
  .name = "TMODE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_ignore },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_tmode, .args_min = 4 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
init_handler(void)
{
  command_add(&tmode_msgtab);
}

static void
exit_handler(void)
{
  command_del(&tmode_msgtab);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
  .core = true
};
