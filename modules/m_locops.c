/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_locops.c
 * \brief Includes required functions for processing the LOCOPS command.
 */

#include "module.h"

#include "io_string.h"

#include "client.h"
#include "conf_cluster.h"
#include "conf_oper.h"
#include "conf_shared.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"

/*! \brief LOCOPS command handler
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
mo_locops(struct Client *source, int parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_LOCOPS))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "locops");
    return;
  }

  const char *const message = parv[1];
  sendto_clients(UMODE_LOCOPS, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_LOCOPS, "from %s: %s",
                 source->name, message);
  cluster_distribute(source, "LOCOPS", 0, CLUSTER_LOCOPS, "%s", message);
}

/*! \brief LOCOPS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server
 *      - parv[2] = message text
 */
static void
ms_locops(struct Client *source, int parc, char *parv[])
{
  const char *const targets = parv[1];
  const char *const message = parv[2];

  sendto_match_servs(source, targets, CAPAB_CLUSTER, "LOCOPS %s :%s",
                     targets, message);

  if (match(targets, me.name))
    return;

  if (shared_find(SHARED_LOCOPS, source->uplink->name, "*", "*"))
    sendto_clients(UMODE_LOCOPS, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_LOCOPS, "from %s: %s",
                   source->name, message);
}

static struct Command command_table =
{
  .name = "LOCOPS",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_locops, .args_min = 3 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_locops, .args_min = 2 }
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
