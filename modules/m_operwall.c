/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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

/*! \file m_operwall.c
 * \brief Includes required functions for processing the OPERWALL command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "server.h"


/*! \brief OPERWALL command handler
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
mo_operwall(struct Client *source_p, int parc, char *parv[])
{
  const char *message = parv[1];

  if (!HasOFlag(source_p, OPER_FLAG_OPERWALL))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "operwall");
    return 0;
  }

  if (EmptyString(message))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "OPERWALL");
    return 0;
  }

  sendto_server(source_p, NOCAPS, NOCAPS, ":%s OPERWALL :%s",
                source_p->id, message);
  sendto_wallops_flags(UMODE_OPERWALL, source_p, "OPERWALL - %s", message);
  return 0;
}

/*! \brief OPERWALL command handler
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
ms_operwall(struct Client *source_p, int parc, char *parv[])
{
  const char *message = parv[1];

  if (EmptyString(message))
    return 0;

  sendto_server(source_p, NOCAPS, NOCAPS, ":%s OPERWALL :%s",
                source_p->id, message);
  sendto_wallops_flags(UMODE_OPERWALL, source_p, "OPERWALL - %s", message);
  return 0;
}

static struct Message operwall_msgtab =
{
  "OPERWALL", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_operwall, m_ignore, mo_operwall, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&operwall_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&operwall_msgtab);
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
