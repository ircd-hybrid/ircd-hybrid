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
#include "s_serv.h"
#include "parse.h"
#include "modules.h"


/*
 * mo_locops - LOCOPS message handler
 * (write to *all* local opers currently online)
 *      parv[0] = command
 *      parv[1] = message text
 */
static int
mo_locops(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  const char *message = parv[1];

  if (!HasOFlag(source_p, OPER_FLAG_LOCOPS))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "locops");
    return 0;
  }

  if (EmptyString(message))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "LOCOPS");
    return 0;
  }

  sendto_realops_flags(UMODE_LOCOPS, L_ALL, SEND_LOCOPS, "from: %s: %s",
                       source_p->name, message);
  cluster_a_line(source_p, "LOCOPS", 0, SHARED_LOCOPS, message);
  return 0;
}

static int
ms_locops(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  if (parc != 3 || EmptyString(parv[2]))
    return 0;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER, "LOCOPS %s :%s",
                     parv[1], parv[2]);

  if (!IsClient(source_p) || match(parv[1], me.name))
    return 0;

  if (find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              "*", "*", SHARED_LOCOPS))
    sendto_realops_flags(UMODE_LOCOPS, L_ALL, SEND_LOCOPS, "from: %s: %s",
                         source_p->name, parv[2]);
  return 0;
}

static struct Message locops_msgtab =
{
  "LOCOPS", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_locops, m_ignore, mo_locops, m_ignore }
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
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
