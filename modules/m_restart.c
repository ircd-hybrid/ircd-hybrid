/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_restart.c
 * \brief Includes required functions for processing the RESTART command.
 */

#include <stdbool.h>
#include <stddef.h>

#include "io_string.h"
#include "module.h"

#include "client.h"
#include "client_format.h"
#include "ircd.h"
#include "ircd_module.h"
#include "ircd_exit.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

/*! \brief RESTART command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = server name
 */
static void
mo_restart(struct Client *source, size_t parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_RESTART))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "restart");
    return;
  }

  const char *const name = parv[1];
  if (io_strcasecmp(name, me.name))
  {
    sendto_one_notice(source, &me, ":Mismatch on /restart %s", me.name);
    return;
  }

  client_format_name_buffer_t source_name_buffer;
  ircd_exit_fmt(IRCD_EXIT_RESTART, "received RESTART command from %s",
                client_format_name(source, CLIENT_FORMAT_NAME_PUBLIC, &source_name_buffer));
}

static struct Command command_table =
{
  .name = "RESTART",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_restart, .args_min = 2 }
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  return ircd_module_register_commands(&command_table, 1, error_message, error_message_size);
}

static void
exit_handler(void *context)
{
  command_del(&command_table);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "m_restart",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
