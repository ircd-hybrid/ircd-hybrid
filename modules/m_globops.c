/*
 * SPDX-FileCopyrightText: 2011-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_globops.c
 * \brief Includes required functions for processing the GLOBOPS command.
 */

#include "module.h"

#include "client.h"
#include "conf_oper.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

static void
_globops_send(struct Client *source, const char *message)
{
  sendto_servers(source, 0, 0, ":%s GLOBOPS :%s", source->id, message);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_GLOBAL, "from %s: %s",
                 source->name, message);
}

/*! \brief GLOBOPS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = message text
 */
static void
mo_globops(struct Client *source, size_t parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_GLOBOPS))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "globops");
    return;
  }

  const char *const message = parv[1];
  _globops_send(source, message);
}

/*! \brief GLOBOPS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = message text
 */
static void
ms_globops(struct Client *source, size_t parc, char *parv[])
{
  const char *const message = parv[1];
  _globops_send(source, message);
}

static struct Command command_table =
{
  .name = "GLOBOPS",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_globops, .args_min = 2 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_globops, .args_min = 2 }
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
