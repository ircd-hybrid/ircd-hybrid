/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2011-2014 ircd-hybrid development team
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
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
  const char *message = parv[1];

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

  sendto_server(source_p, NOCAPS, NOCAPS, ":%s GLOBOPS :%s",
                source_p->id, message);
  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_GLOBAL, "from %s: %s",
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
  if (EmptyString(parv[1]))
    return 0;

  sendto_server(source_p, NOCAPS, NOCAPS, ":%s GLOBOPS :%s",
                source_p->id, parv[1]);
  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_GLOBAL, "from %s: %s",
                       source_p->name, parv[1]);
  return 0;
}

static struct Message globops_msgtab =
{
  "GLOBOPS", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_globops, m_ignore, mo_globops, m_ignore }
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
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
