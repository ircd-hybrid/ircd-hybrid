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


/*! \brief DIE command handler
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
mo_die(struct Client *source_p, int parc, char *parv[])
{
  char buf[IRCD_BUFSIZE] = "";
  const char *const name = parv[1];

  if (!HasOFlag(source_p, OPER_FLAG_DIE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "die");
    return 0;
  }

  if (EmptyString(name))
  {
    sendto_one_notice(source_p, &me, ":Need server name /die %s", me.name);
    return 0;
  }

  if (irccmp(name, me.name))
  {
    sendto_one_notice(source_p, &me, ":Mismatch on /die %s", me.name);
    return 0;
  }

  snprintf(buf, sizeof(buf), "received DIE command from %s",
           get_client_name(source_p, HIDE_IP));
  server_die(buf, SERVER_SHUTDOWN);
  return 0;
}

static struct Message die_msgtab =
{
  .cmd = "DIE",
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = m_ignore,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_die
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
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
