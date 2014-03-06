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

/*! \file m_die.c
 * \brief Includes required functions for processing the DIE command.
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
#include "restart.h"
#include "conf.h"


/*
 * mo_die - DIE command handler
 */
static int
mo_die(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  char buf[IRCD_BUFSIZE];

  if (!HasOFlag(source_p, OPER_FLAG_DIE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "die");
    return 0;
  }

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one_notice(source_p, &me, ":Need server name /die %s", me.name);
    return 0;
  }

  if (irccmp(parv[1], me.name))
  {
    sendto_one_notice(source_p, &me, ":Mismatch on /die %s", me.name);
    return 0;
  }

  snprintf(buf, sizeof(buf), "received DIE command from %s",
           get_oper_name(source_p));
  server_die(buf, 0);
  return 0;
}

static struct Message die_msgtab =
{
  "DIE", 0, 0, 1, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_die, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&die_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&die_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
