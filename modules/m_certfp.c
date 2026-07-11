/*
 * SPDX-FileCopyrightText: 2013-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_certfp.c
 * \brief Includes required functions for processing the CERTFP command.
 */

#include <stddef.h>

#include "memory.h"
#include "module.h"

#include "client.h"
#include "parse.h"
#include "send.h"

/*! \brief CERTFP command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = certificate fingerprint
 */
static void
ms_certfp(struct Client *source, int parc, char *parv[])
{
  if (!client_is_user(source))
    return;

  io_free(source->tls_certfp);
  source->tls_certfp = io_strdup(parv[1]);

  sendto_servers(source, 0, 0, ":%s CERTFP %s",
                 source->id, source->tls_certfp);
}

static struct Command command_table =
{
  .name = "CERTFP",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_certfp, .args_min = 2 },
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
