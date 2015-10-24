/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "server.h"
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
static int
mo_locops(struct Client *source_p, int parc, char *parv[])
{
  const char *const message = parv[1];

  if (!HasOFlag(source_p, OPER_FLAG_LOCOPS))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "locops");
    return 0;
  }

  if (EmptyString(message))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "LOCOPS");
    return 0;
  }

  sendto_realops_flags(UMODE_LOCOPS, L_ALL, SEND_LOCOPS, "from %s: %s",
                       source_p->name, message);
  cluster_a_line(source_p, "LOCOPS", 0, SHARED_LOCOPS, message);
  return 0;
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
static int
ms_locops(struct Client *source_p, int parc, char *parv[])
{
  const char *const targets = parv[1];
  const char *const message = parv[2];

  if (parc != 3 || EmptyString(message))
    return 0;

  sendto_match_servs(source_p, targets, CAPAB_CLUSTER, "LOCOPS %s :%s",
                     targets, message);

  if (match(targets, me.name))
    return 0;

  if (find_matching_name_conf(CONF_SHARED, source_p->servptr->name,
                              "*", "*", SHARED_LOCOPS))
    sendto_realops_flags(UMODE_LOCOPS, L_ALL, SEND_LOCOPS, "from %s: %s",
                         source_p->name, message);
  return 0;
}

static struct Message locops_msgtab =
{
  .cmd = "LOCOPS",
  .args_min = 2,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = ms_locops,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_locops
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
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
