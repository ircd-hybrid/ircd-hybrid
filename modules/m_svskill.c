/*
 * SPDX-FileCopyrightText: 1999 Bahamut development team
 * SPDX-FileCopyrightText: 2013-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_svskill.c
 * \brief Includes required functions for processing the SVSKILL command.
 */

#include <stdbool.h>
#include <stddef.h>

#include "module.h"

#include "client.h"
#include "client_find.h"
#include "parse.h"
#include "send.h"

/*! \brief SVSKILL command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = ignored/unused
 *      - parv[3] = kill message
 */
static void
ms_svskill(struct Client *source, int parc, char *parv[])
{
  if (!client_is_service(source) && !client_is_server(source))
    return;

  struct Client *const target = client_find_user(source, parv[1]);
  if (target == NULL)
    return;

  const char *const reason = parv[3];
  if (client_is_local(target))
  {
    client_exit_fmt(target, "SVSKilled: %.*s", REASONLEN, reason);
    return;
  }

  if (target->nexthop == source->nexthop)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Received wrong-direction SVSKILL for %s (behind %s) from %s",
                   target->name, source->nexthop->name, source->name);
    return;
  }

  sendto_one_command(target, source, "SVSKILL", "0 :%s", reason);
}

static struct Command command_table =
{
  .name = "SVSKILL",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_svskill, .args_min = 4 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
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
