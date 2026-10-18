/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_pass.c
 * \brief Includes required functions for processing the PASS command.
 */

#include <assert.h>
#include <stddef.h>

#include "io_string.h"
#include "memory.h"
#include "module.h"

#include "ircd_module.h"
#include "client.h"
#include "parse.h"

/*! \brief PASS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = password
 */
static void
mr_pass(struct Client *source, size_t parc, char *parv[])
{
  const char *const password = parv[1];
  assert(client_is_local(source));

  if (source->connection->password == NULL)
    source->connection->password = io_strndup(password, PASSWDLEN);
}

static struct Command command_table =
{
  .name = "PASS",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = mr_pass, .args_min = 2 },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_already_registered },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_reject_already_registered }
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
  .name = "m_pass",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
