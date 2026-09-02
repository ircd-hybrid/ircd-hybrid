/*
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_svstag.c
 * \brief Includes required functions for processing the SVSTAG command.
 */

#include <stddef.h>
#include <string.h>

#include "io_string.h"
#include "module.h"

#include "client.h"
#include "client_find.h"
#include "client_svstag.h"
#include "parse.h"
#include "send.h"

/*! \brief SVSTAG command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 */
static void
ms_svstag(struct Client *source, size_t parc, char *parv[])
{
  if (!client_is_service(source) && !client_is_server(source))
    return;

  if (strcmp(parv[3], "313") || strcmp(parv[4], "+"))
    return;

  struct Client *const target = client_find_user(source, parv[1]);
  if (target == NULL)
    return;

  if (!svstag_attach(&target->svstag_list, parv[5]))
    return;

  sendto_servers(source, 0, 0, ":%s SVSTAG %s 0 %u + :%s",
                 source->id, target->id, RPL_WHOISOPERATOR, parv[5]);
}

static struct Command command_table =
{
  .name = "SVSTAG",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_svstag, .args_min = 6 },
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
