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

/*! \file m_names.c
 * \brief Includes required functions for processing the NAMES command.
 */

#include <stddef.h>

#include "io_string.h"
#include "module.h"

#include "channel.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

/*! \brief NAMES command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 */
static void
m_names(struct Client *source, int parc, char *parv[])
{
  const char *const name = parv[1];
  if (string_is_empty(name))
  {
    sendto_one_numeric(source, &me, RPL_ENDOFNAMES, "*");
    return;
  }

  struct Channel *const channel = channel_find(name);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, RPL_ENDOFNAMES, name);
    return;
  }

  channel_send_namereply(source, channel);
}

static struct Command command_table =
{
  .name = "NAMES",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = m_unregistered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_names },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = m_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = m_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_names }
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
