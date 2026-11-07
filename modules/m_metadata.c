/*
 * SPDX-FileCopyrightText: 2020-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_metadata.c
 * \brief Includes required functions for processing the METADATA command.
 */

#include <stddef.h>

#include "io_string.h"
#include "memory.h"
#include "module.h"

#include "ircd_module.h"
#include "client.h"
#include "client_find.h"
#include "parse.h"
#include "send.h"

/*! \brief METADATA command handler
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
ms_metadata(struct Client *source, size_t parc, char *parv[])
{
  if (!client_is_service(source) && !client_is_server(source))
    return;

  if (io_strcasecmp(parv[1], "client") == 0)
  {
    struct Client *const target = client_find_user(source, parv[2]);
    if (target == NULL)
      return;

    if (io_strcasecmp(parv[3], "cipher") == 0)
    {
      io_free(target->tls_cipher);
      if (!string_is_empty(parv[4]))
        target->tls_cipher = io_strdup(parv[4]);
      else
        target->tls_cipher = NULL;
    }

    if (io_strcasecmp(parv[3], "certfp") == 0)
    {
      io_free(target->tls_certfp);
      if (!string_is_empty(parv[4]))
        target->tls_certfp = io_strdup(parv[4]);
      else
        target->tls_certfp = NULL;
    }
  }

  if (parc == 4)
    sendto_servers(source, 0, 0, ":%s METADATA %s %s %s",
                   source->id, parv[1], parv[2], parv[3]);
  else  /* parc == 5 */
    sendto_servers(source, 0, 0, ":%s METADATA %s %s %s :%s",
                   source->id, parv[1], parv[2], parv[3], parv[4]);
}

static struct Command command_table =
{
  .name = "METADATA",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_metadata, .args_min = 4 },
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
  .name = "m_metadata",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
