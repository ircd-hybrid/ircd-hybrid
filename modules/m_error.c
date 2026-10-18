/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_error.c
 * \brief Includes required functions for processing the ERROR command.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "io_string.h"
#include "log.h"
#include "module.h"

#include "client.h"
#include "client_format.h"
#include "ircd.h"
#include "ircd_module.h"
#include "parse.h"
#include "send.h"

/*! \brief ERROR command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = error message
 */
static void
mr_error(struct Client *source, size_t parc, char *parv[])
{
  assert(client_is_local(source));

  if (!client_is_handshake(source) && !client_is_connecting(source))
    return;

  const char *const message = string_or_default(parv[1], "<>");

  client_format_name_buffer_t log_name_buffer;
  client_format_name_buffer_t public_name_buffer;
  client_format_name_buffer_t oper_name_buffer;

  log_write(LOG_TYPE_IRCD, "Received ERROR message from %s: %s",
            client_format_name(source, CLIENT_FORMAT_NAME_LOG, &log_name_buffer), message);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE, "ERROR :from %s -- %s",
                 client_format_name(source, CLIENT_FORMAT_NAME_PUBLIC, &public_name_buffer), message);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE, "ERROR :from %s -- %s",
                 client_format_name(source, CLIENT_FORMAT_NAME_OPER, &oper_name_buffer), message);
}

/*! \brief ERROR command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = error message
 */
static void
ms_error(struct Client *source, size_t parc, char *parv[])
{
  const char *const message = string_or_default(parv[1], "<>");

  client_format_name_buffer_t log_name_buffer;
  client_format_name_buffer_t link_name_buffer;

  log_write(LOG_TYPE_IRCD, "Received ERROR message from %s: %s",
            client_format_name(source, CLIENT_FORMAT_NAME_LOG, &log_name_buffer), message);

  if (client_is_local(source))
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "ERROR :from %s -- %s",
                   client_format_name(source->nexthop, CLIENT_FORMAT_NAME_OPER, &link_name_buffer), message);
  else
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "ERROR :from %s via %s -- %s",
                   source->name, client_format_name(source->nexthop, CLIENT_FORMAT_NAME_OPER, &link_name_buffer), message);
}

static struct Command command_table =
{
  .name = "ERROR",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = mr_error },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_error },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
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
  .name = "m_error",
  .flags = MODULE_FLAG_NO_REMOVE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
