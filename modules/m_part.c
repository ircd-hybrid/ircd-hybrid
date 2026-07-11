/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_part.c
 * \brief Includes required functions for processing the PART command.
 */

#include <stdbool.h>
#include <stddef.h>

#include "module.h"

#include "channel.h"
#include "client.h"
#include "parse.h"

/*! \brief PART command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 *      - parv[2] = part message
 */
static void
m_part(struct Client *source, int parc, char *parv[])
{
  channel_part_list(source, parv[1], parv[2]);
}

static struct Command command_table =
{
  .name = "PART",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_part, .args_min = 2, .end_grace_period = true },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = m_part, .args_min = 2 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_part, .args_min = 2, .end_grace_period = true }
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
  .core = true
};
