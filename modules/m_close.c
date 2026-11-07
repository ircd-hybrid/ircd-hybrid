/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_close.c
 * \brief Includes required functions for processing the CLOSE command.
 */

#include <assert.h>
#include <stddef.h>

#include "list.h"
#include "module.h"

#include "client.h"
#include "client_format.h"
#include "conf_oper.h"
#include "ircd.h"
#include "ircd_module.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

/*! \brief CLOSE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
mo_close(struct Client *source, size_t parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_CLOSE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "close");
    return;
  }

  const unsigned int closed_count = list_length(&unknown_list);

  struct Client *target;
  while ((target = list_peek_head(&unknown_list)))
  {
    /* An oper (source) can never be in the unknown_list. */
    assert(source != target);

    client_format_name_buffer_t target_name_buffer;
    sendto_one_numeric(source, &me, RPL_CLOSING,
                       client_format_name(target, CLIENT_FORMAT_NAME_ADMIN, &target_name_buffer), target->state);
    client_exit(target, "Oper Closing");
  }

  sendto_one_numeric(source, &me, RPL_CLOSEEND, closed_count);
}

static struct Command command_table =
{
  .name = "CLOSE",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_close }
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
  .name = "m_close",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
