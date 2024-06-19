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

/*! \file m_wallops.c
 * \brief Includes required functions for processing the WALLOPS command.
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "module.h"


/*! \brief WALLOPS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = message text
 */
static void
mo_wallops(struct Client *source, int parc, char *parv[])
{
  const char *const message = parv[1];

  if (!HasOFlag(source, OPER_FLAG_WALLOPS))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "wallops");
    return;
  }

  sendto_wallops_flags(UMODE_WALLOP, source, "%s", message);
  sendto_server(source, 0, 0, ":%s WALLOPS :%s", source->id, message);
}

/*! \brief WALLOPS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = message text
 */
static void
ms_wallops(struct Client *source, int parc, char *parv[])
{
  const char *const message = parv[1];

  sendto_wallops_flags(UMODE_WALLOP, source, "%s", message);
  sendto_server(source, 0, 0, ":%s WALLOPS :%s", source->id, message);
}

static struct Command wallops_msgtab =
{
  .name = "WALLOPS",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_wallops, .args_min = 2 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_wallops, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&wallops_msgtab);
}

static void
exit_handler(void)
{
  command_del(&wallops_msgtab);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
