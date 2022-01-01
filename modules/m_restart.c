/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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
static void
mo_restart(struct Client *source_p, int parc, char *parv[])
{
  const char *const name = parv[1];

  if (!HasOFlag(source_p, OPER_FLAG_RESTART))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "restart");
    return;
  }

  if (irccmp(name, me.name))
  {
    sendto_one_notice(source_p, &me, ":Mismatch on /restart %s", me.name);
    return;
  }

  char buf[IRCD_BUFSIZE];
  snprintf(buf, sizeof(buf), "received RESTART command from %s",
           client_get_name(source_p, HIDE_IP));
  server_die(buf, true);
}

static struct Message restart_msgtab =
{
  .cmd = "RESTART",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_restart, .args_min = 2 }
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
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
