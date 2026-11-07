/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
#include "ircd_module.h"
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
m_names(struct Client *source, size_t parc, char *parv[])
{
  const char *const channel_name = parv[1];
  if (string_is_empty(channel_name))
  {
    sendto_one_numeric(source, &me, RPL_ENDOFNAMES, "*");
    return;
  }

  struct Channel *const channel = channel_find(channel_name);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, RPL_ENDOFNAMES, channel_name);
    return;
  }

  channel_send_namereply(source, channel);
}

static struct Command command_table =
{
  .name = "NAMES",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_names },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_names }
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
  .name = "m_names",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
