/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_lusers.c
 * \brief Includes required functions for processing the LUSERS command.
 */

#include <stddef.h>
#include <stdint.h>

#include "io_time.h"
#include "module.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "user.h"

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
m_lusers(struct Client *source, size_t parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait_simple) > io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    sendto_one_numeric(source, &me, RPL_LOAD2HI, "LUSERS");
    return;
  }

  last_used = io_time_get(IO_TIME_MONOTONIC_SEC);

  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_route_command(source, ":%s LUSERS %s :%s", 2, parv)->result != SERVER_ROUTE_ISME)
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
ms_lusers(struct Client *source, size_t parc, char *parv[])
{
  if (server_route_command(source, ":%s LUSERS %s :%s", 2, parv)->result != SERVER_ROUTE_ISME)
    return;

  show_lusers(source);
}

static struct Command command_table =
{
  .name = "LUSERS",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_lusers },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_lusers },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = ms_lusers }
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
