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

/*! \file m_version.c
 * \brief Includes required functions for processing the VERSION command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "server.h"
#include "user.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "isupport.h"
#include "patchlevel.h"


/* Option string. */
static const char serveropts[] =
{
  'T',
  'S',
#ifdef TS_CURRENT
  '0' + TS_CURRENT,
#endif
/* ONLY do TS */
/* ALWAYS do TS_WARNINGS */
  'o',
  'w',
  '\0'
};

/*! \brief VERSION command handler
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
static void
m_version(struct Client *source_p, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait_simple) > event_base->time.sec_monotonic)
  {
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI, "VERSION");
    return;
  }

  last_used = event_base->time.sec_monotonic;

  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_hunt(source_p, ":%s VERSION :%s", 1, parv)->ret != HUNTED_ISME)
      return;

  sendto_one_numeric(source_p, &me, RPL_VERSION, PATCHLEVEL, me.name, serveropts);
  isupport_show(source_p);
}

/*! \brief VERSION command handler
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
static void
ms_version(struct Client *source_p, int parc, char *parv[])
{
  if (server_hunt(source_p, ":%s VERSION :%s", 1, parv)->ret != HUNTED_ISME)
    return;

  sendto_one_numeric(source_p, &me, RPL_VERSION, PATCHLEVEL, me.name, serveropts);
  isupport_show(source_p);
}

static struct Message version_msgtab =
{
  .cmd = "VERSION",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_version },
  .handlers[SERVER_HANDLER] = { .handler = ms_version },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = ms_version }
};

static void
module_init(void)
{
  mod_add_cmd(&version_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&version_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
