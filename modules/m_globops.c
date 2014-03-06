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
#include "s_serv.h"
#include "parse.h"
#include "modules.h"


/*
 * mo_globops - GLOBOPS message handler
 * (write to *all* local opers currently online)
 *      parv[0] = command
 *      parv[1] = message text
 */
static int
mo_globops(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
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

  sendto_server(NULL, CAP_TS6, NOCAPS, ":%s GLOBOPS :%s",
                ID(source_p), message);
  sendto_server(NULL, NOCAPS, CAP_TS6, ":%s GLOBOPS :%s",
                source_p->name, message);

  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_GLOBAL, "from: %s: %s",
                       source_p->name, message);
  return 0;
}

static int
ms_globops(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  if (EmptyString(parv[1]))
    return 0;

  sendto_server(client_p, CAP_TS6, NOCAPS, ":%s GLOBOPS :%s",
                ID(source_p), parv[1]);
  sendto_server(client_p, NOCAPS, CAP_TS6, ":%s GLOBOPS :%s",
                source_p->name, parv[1]);

  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_GLOBAL, "from: %s: %s",
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
