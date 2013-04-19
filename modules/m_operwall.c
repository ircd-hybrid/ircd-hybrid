/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_operwall.c: Sends a message to all IRCOps.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "send.h"
#include "s_user.h"
#include "parse.h"
#include "modules.h"
#include "s_serv.h"


/*
 * mo_operwall - OPERWALL message handler
 *  (write to *all* local opers currently online)
 *      parv[0] = sender prefix
 *      parv[1] = message text
 */
static void
mo_operwall(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  const char *message = parv[1];

  if (!HasOFlag(source_p, OPER_FLAG_OPERWALL))
  {
    sendto_one(source_p, ERR_NOPRIVS,
               me.name, source_p->name, "operwall");
    return;
  }

  if (EmptyString(message))
  {
    sendto_one(source_p, ERR_NEEDMOREPARAMS,
               me.name, source_p->name, "OPERWALL");
    return;
  }

  sendto_server(NULL, CAP_TS6, NOCAPS,
                ":%s OPERWALL :%s", ID(source_p), message);
  sendto_server(NULL, NOCAPS, CAP_TS6,
                ":%s OPERWALL :%s", source_p->name, message);
  sendto_wallops_flags(UMODE_OPERWALL, source_p, "OPERWALL - %s", message);
}

/*
 * ms_operwall - OPERWALL message handler
 *  (write to *all* local opers currently online)
 *      parv[0] = sender prefix
 *      parv[1] = message text
 */
static void
ms_operwall(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  const char *message = parv[1];

  if (EmptyString(message))
    return;

  sendto_server(client_p, CAP_TS6, NOCAPS, ":%s OPERWALL :%s",
                ID(source_p), message);
  sendto_server(client_p, NOCAPS, CAP_TS6, ":%s OPERWALL :%s",
                source_p->name, message);
  sendto_wallops_flags(UMODE_OPERWALL, source_p, "OPERWALL - %s", message);
}

/*
 * me_operwall - OPERWALL message handler
 *  (write to *all* local opers currently online)
 *      parv[0] = sender prefix
 *      parv[1] = message text
 *
 * Lets ms_encap handle propagation.
 */
static void
me_operwall(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  const char *message = parv[1];

  if (EmptyString(message))
    return;

  sendto_wallops_flags(UMODE_OPERWALL, source_p, "OPERWALL - %s", message);
}

static struct Message operwall_msgtab = {
  "OPERWALL", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, ms_operwall, me_operwall, mo_operwall, m_ignore}
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

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
