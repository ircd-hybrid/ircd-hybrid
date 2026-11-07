/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_tmode.c
 * \brief Includes required functions for processing the TMODE command.
 */

#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>

#include "io_parse.h"
#include "module.h"

#include "ircd_module.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "parse.h"

/*! \brief TMODE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = timestamp
 *      - parv[2] = channel name
 *      - parv[3] = modes to be added or removed
 */
static void
ms_tmode(struct Client *source, size_t parc, char *parv[])
{
  assert(!client_is_local_user(source));

  struct Channel *const channel = channel_find(parv[2]);
  if (channel == NULL)
    return;

  uintmax_t channel_timestamp;
  if (io_parse_uintmax(parv[1], &channel_timestamp) != IO_PARSE_OK)
    return;

  if (channel_timestamp > channel->creation_time)
    return;

  channel_mode_set(source, channel, parc - 3, parv + 3);
}

static struct Command command_table =
{
  .name = "TMODE",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_tmode, .args_min = 4 },
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
  .name = "m_tmode",
  .flags = MODULE_FLAG_NO_REMOVE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
