/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file m_locops.c
 * \brief Includes required functions for processing the LOCOPS command.
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_shared.h"
#include "server_capab.h"
#include "parse.h"
#include "modules.h"


/*! \brief LOCOPS command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = message text
 */
static void
mo_locops(struct Client *source_p, int parc, char *parv[])
{
  const char *const message = parv[1];

  if (!HasOFlag(source_p, OPER_FLAG_LOCOPS))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "locops");
    return;
  }

  sendto_realops_flags(UMODE_LOCOPS, L_ALL, SEND_LOCOPS, "from %s: %s",
                       source_p->name, message);
  cluster_distribute(source_p, "LOCOPS", 0, CLUSTER_LOCOPS, message);
}

/*! \brief LOCOPS command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
ms_locops(struct Client *source_p, int parc, char *parv[])
{
  const char *const targets = parv[1];
  const char *const message = parv[2];

  sendto_match_servs(source_p, targets, CAPAB_CLUSTER, "LOCOPS %s :%s",
                     targets, message);

  if (match(targets, me.name))
    return;

  if (shared_find(SHARED_LOCOPS, source_p->servptr->name, "*", "*"))
    sendto_realops_flags(UMODE_LOCOPS, L_ALL, SEND_LOCOPS, "from %s: %s",
                         source_p->name, message);
}

static struct Message locops_msgtab =
{
  .cmd = "LOCOPS",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_locops, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_locops, .args_min = 2 }
};

static void
module_init(void)
{
  mod_add_cmd(&locops_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&locops_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
