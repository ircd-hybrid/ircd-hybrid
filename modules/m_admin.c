/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*! \file m_admin.c
 * \brief Includes required functions for processing the ADMIN command.
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "server.h"
#include "send.h"
#include "parse.h"
#include "module.h"


/*! \brief Sends administrative information about this server.
 *
 * \param source Pointer to client to report to
 */
static void
do_admin(struct Client *source)
{
  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE, "ADMIN requested by %s (%s@%s) [%s]",
                       source->name, source->username, source->host, source->servptr->name);

  sendto_one_numeric(source, &me, RPL_ADMINME, me.name);

  if (!EmptyString(ConfigAdminInfo.name))
    sendto_one_numeric(source, &me, RPL_ADMINLOC1, ConfigAdminInfo.name);
  if (!EmptyString(ConfigAdminInfo.description))
    sendto_one_numeric(source, &me, RPL_ADMINLOC2, ConfigAdminInfo.description);
  if (!EmptyString(ConfigAdminInfo.email))
    sendto_one_numeric(source, &me, RPL_ADMINEMAIL, ConfigAdminInfo.email);
}

/*! \brief ADMIN command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 */
static void
m_admin(struct Client *source, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait_simple) > event_base->time.sec_monotonic)
  {
    sendto_one_numeric(source, &me, RPL_LOAD2HI, "ADMIN");
    return;
  }

  last_used = event_base->time.sec_monotonic;

  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_hunt(source, ":%s ADMIN :%s", 1, parv)->ret != HUNTED_ISME)
      return;

  do_admin(source);
}

/*! \brief ADMIN command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 */
static void
ms_admin(struct Client *source, int parc, char *parv[])
{
  if (server_hunt(source, ":%s ADMIN :%s", 1, parv)->ret != HUNTED_ISME)
    return;

  do_admin(source);
}

static struct Command command_table =
{
  .name = "ADMIN",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_admin },
  .handlers[SERVER_HANDLER] = { .handler = ms_admin },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = ms_admin }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
