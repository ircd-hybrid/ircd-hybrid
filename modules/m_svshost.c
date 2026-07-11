/*
 * SPDX-FileCopyrightText: 2016-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_svshost.c
 * \brief Includes required functions for processing the SVSHOST command.
 */

#include <stdbool.h>
#include <stddef.h>

#include "module.h"

#include "client.h"
#include "client_find.h"
#include "parse.h"
#include "send.h"
#include "user.h"

/*! \brief SVSHOST command handler
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
 *      - parv[3] = host name
 */
static void
ms_svshost(struct Client *source, int parc, char *parv[])
{
  if (!client_is_service(source) && !client_is_server(source))
    return;

  const char *const target_name = parv[1];
  struct Client *const target = client_find_user(source, target_name);
  if (target == NULL)
    return;

  const char *const new_host = parv[3];
  if (!valid_hostname(new_host))
    return;

  user_set_hostmask(target, new_host, false);
  sendto_servers(source, 0, 0, ":%s SVSHOST %s 0 %s",
                 source->id, target->id, new_host);
}

static struct Command command_table =
{
  .name = "SVSHOST",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_svshost, .args_min = 4 },
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
