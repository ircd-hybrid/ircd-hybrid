/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2024 ircd-hybrid development team
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

/*! \file m_eob.c
 * \brief Includes required functions for processing the EOB command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "parse.h"
#include "module.h"
#include "server.h"


/*! \brief EOB command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
ms_eob(struct Client *source, int parc, char *parv[])
{
  assert(IsServer(source));

  if (MyConnect(source))
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                         "End of burst from %s (%ju seconds)", source->name,
                         (io_time_get(IO_TIME_MONOTONIC_SEC) - source->connection->created_monotonic));

  AddFlag(source, FLAGS_EOB);
  sendto_servers(source, 0, 0, ":%s EOB", source->id);
}

static struct Command command_table =
{
  .name = "EOB",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered  },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_eob },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
