/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_version.c
 * \brief Includes required functions for processing the VERSION command.
 */

#include <stdint.h>

#include "io_time.h"
#include "module.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "isupport.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"

/* Option string. */
static const char serveropts[] =
{
  'T',
  'S',
  '0' + SERVER_TS_PROTOCOL_CURRENT,
  'o',
  'w',
  '\0'
};

static void
_version_process_request(struct Client *source)
{
  hook_dispatch(ircd_hook_spy_request, &(ircd_hook_spy_request_ctx){
    .source = source,
    .command = "VERSION"
  });

  sendto_one_numeric(source, &me, RPL_VERSION, IRCD_VERSION, me.name, serveropts);
  isupport_show(source);
}

/*! \brief VERSION command handler
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
m_version(struct Client *source, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait_simple) > io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    sendto_one_numeric(source, &me, RPL_LOAD2HI, "VERSION");
    return;
  }

  last_used = io_time_get(IO_TIME_MONOTONIC_SEC);

  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_route_command(source, ":%s VERSION :%s", 1, parv)->result != SERVER_ROUTE_ISME)
      return;

  _version_process_request(source);
}

/*! \brief VERSION command handler
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
ms_version(struct Client *source, int parc, char *parv[])
{
  if (server_route_command(source, ":%s VERSION :%s", 1, parv)->result != SERVER_ROUTE_ISME)
    return;

  _version_process_request(source);
}

static struct Command command_table =
{
  .name = "VERSION",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_version },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_version },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = ms_version }
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
