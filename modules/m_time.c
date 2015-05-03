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

/*! \file m_time.c
 * \brief Includes required functions for processing the TIME command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "misc.h"
#include "conf.h"
#include "server.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"


/*! \brief TIME command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 */
static int
m_time(struct Client *source_p, int parc, char *parv[])
{
  /* This is not rate limited, so end the grace period */
  if (!IsFloodDone(source_p))
    flood_endgrace(source_p);

  /* This is safe enough to use during non hidden server mode */
  if (!ConfigServerHide.disable_remote_commands)
    if (hunt_server(source_p, ":%s TIME :%s", 1, parc, parv) != HUNTED_ISME)
      return 0;

  sendto_one_numeric(source_p, &me, RPL_TIME, me.name, date(0));
  return 0;
}

/*! \brief TIME command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 */
static int
ms_time(struct Client *source_p, int parc, char *parv[])
{
  if (hunt_server(source_p, ":%s TIME :%s", 1, parc, parv) != HUNTED_ISME)
    return 0;

  sendto_one_numeric(source_p, &me, RPL_TIME, me.name, date(0));
  return 0;
}

static struct Message time_msgtab =
{
  .cmd = "TIME",
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_time,
  .handlers[SERVER_HANDLER] = ms_time,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = ms_time
};

static void
module_init(void)
{
  mod_add_cmd(&time_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&time_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
