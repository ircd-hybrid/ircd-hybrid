/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2011-2016 ircd-hybrid development team
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

/*! \file m_globops.c
 * \brief Includes required functions for processing the GLOBOPS command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "send.h"
#include "server.h"
#include "parse.h"
#include "modules.h"


/*! \brief GLOBOPS command handler
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
mo_globops(struct Client *source_p, int parc, char *parv[])
{
  const char *const message = parv[1];

  if (!HasOFlag(source_p, OPER_FLAG_GLOBOPS))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "globops");
    return 0;
  }

  if (EmptyString(message))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "GLOBOPS");
    return 0;
  }

  sendto_server(source_p, 0, 0, ":%s GLOBOPS :%s",
                source_p->id, message);
  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_GLOBAL, "from %s: %s",
                       source_p->name, message);
  return 0;
}

/*! \brief GLOBOPS command handler
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
ms_globops(struct Client *source_p, int parc, char *parv[])
{
  const char *const message = parv[1];

  if (EmptyString(message))
    return 0;

  sendto_server(source_p, 0, 0, ":%s GLOBOPS :%s",
                source_p->id, message);
  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_GLOBAL, "from %s: %s",
                       source_p->name, message);
  return 0;
}

static struct Message globops_msgtab =
{
  .cmd = "GLOBOPS",
  .args_min = 2,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = ms_globops,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_globops
};

static void
module_init(void)
{
  mod_add_cmd(&globops_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&globops_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
