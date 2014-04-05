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

/*! \file m_restart.c
 * \brief Includes required functions for processing the RESTART command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "restart.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"


/*! \brief RESTART command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = server name
 */
static int
mo_restart(struct Client *source_p, int parc, char *parv[])
{
  char buf[IRCD_BUFSIZE];

  if (!HasOFlag(source_p, OPER_FLAG_RESTART))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "restart");
    return 0;
  }

  if (EmptyString(parv[1]))
  {
    sendto_one_notice(source_p, &me, ":Need server name /restart %s", me.name);
    return 0;
  }

  if (irccmp(parv[1], me.name))
  {
    sendto_one_notice(source_p, &me, ":Mismatch on /restart %s", me.name);
    return 0;
  }

  snprintf(buf, sizeof(buf), "received RESTART command from %s",
           get_oper_name(source_p));
  server_die(buf, 1);
  return 0;
}

static struct Message restart_msgtab =
{
  "RESTART", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_restart, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&restart_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&restart_msgtab);
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
