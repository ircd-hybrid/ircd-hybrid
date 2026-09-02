/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_time.c
 * \brief Includes required functions for processing the TIME command.
 */

#include <stddef.h>

#include "misc.h"
#include "module.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"

/*! \brief TIME command handler
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
m_time(struct Client *source, size_t parc, char *parv[])
{
  /* This is safe enough to use during non hidden server mode */
  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_route_command(source, ":%s TIME :%s", 1, parv)->result != SERVER_ROUTE_ISME)
      return;

  sendto_one_numeric(source, &me, RPL_TIME, me.name, date(0));
}

/*! \brief TIME command handler
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
ms_time(struct Client *source, size_t parc, char *parv[])
{
  if (server_route_command(source, ":%s TIME :%s", 1, parv)->result != SERVER_ROUTE_ISME)
    return;

  sendto_one_numeric(source, &me, RPL_TIME, me.name, date(0));
}

static struct Command command_table =
{
  .name = "TIME",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_time },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_time },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = ms_time }
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
