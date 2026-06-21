/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

/*! \file m_motd.c
 * \brief Includes required functions for processing the MOTD command.
 */

#include <stddef.h>
#include <stdint.h>

#include "io_time.h"
#include "module.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "motd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"

/*! \brief Sends the "message of the day" and notifies irc-operators
 *         about the MOTD request
 *
 * \param source Pointer to client to report to
 */
static void
_motd_process_request(struct Client *source)
{
  hook_dispatch(ircd_hook_spy_request, &(ircd_hook_spy_request_ctx){
    .source = source,
    .command = "MOTD"
  });

  motd_send(source);
}

/*! \brief MOTD command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 */
static void
m_motd(struct Client *source, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait) > io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    sendto_one_numeric(source, &me, RPL_LOAD2HI, "MOTD");
    return;
  }

  last_used = io_time_get(IO_TIME_MONOTONIC_SEC);

  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_route_command(source, ":%s MOTD :%s", 1, parv)->result != SERVER_ROUTE_ISME)
      return;

  _motd_process_request(source);
}

/*! \brief MOTD command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 */
static void
ms_motd(struct Client *source, int parc, char *parv[])
{
  if (server_route_command(source, ":%s MOTD :%s", 1, parv)->result != SERVER_ROUTE_ISME)
    return;

  _motd_process_request(source);
}

static struct Command command_table =
{
  .name = "MOTD",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_motd },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_motd },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = ms_motd }
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
