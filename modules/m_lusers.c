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

/*! \file m_lusers.c
 * \brief Includes required functions for processing the LUSERS command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "server.h"
#include "user.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "module.h"


/*! \brief LUSERS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = ignored
 *      - parv[2] = nickname/servername
 */
static void
m_lusers(struct Client *source, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait_simple) > io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    sendto_one_numeric(source, &me, RPL_LOAD2HI, "LUSERS");
    return;
  }

  last_used = io_time_get(IO_TIME_MONOTONIC_SEC);

  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_hunt(source, ":%s LUSERS %s :%s", 2, parv)->ret != HUNTED_ISME)
      return;

  show_lusers(source);
}

/*! \brief LUSERS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = ignored
 *      - parv[2] = nickname/servername
 */
static void
ms_lusers(struct Client *source, int parc, char *parv[])
{
  if (server_hunt(source, ":%s LUSERS %s :%s", 2, parv)->ret != HUNTED_ISME)
    return;

  show_lusers(source);
}

static struct Command command_table =
{
  .name = "LUSERS",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_lusers },
  .handlers[SERVER_HANDLER] = { .handler = ms_lusers },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = ms_lusers }
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
