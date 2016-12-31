/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2017 ircd-hybrid development team
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

/*! \file m_error.c
 * \brief Includes required functions for processing the ERROR command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "modules.h"
#include "log.h"
#include "parse.h"
#include "irc_string.h"


/*! \brief ERROR command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = error message
 */
static int
mr_error(struct Client *source_p, int parc, char *parv[])
{
  const char *message = (parc > 1 && !EmptyString(parv[1])) ? parv[1] : "<>";

  assert(MyConnect(source_p));

  if (!IsHandshake(source_p) && !IsConnecting(source_p))
    return 0;

  ilog(LOG_TYPE_IRCD, "Received ERROR message from %s: %s",
       source_p->name, message);

  sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                       "ERROR :from %s -- %s",
                       get_client_name(source_p, HIDE_IP), message);
  sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                       "ERROR :from %s -- %s",
                       get_client_name(source_p, MASK_IP), message);
  return 0;
}

/*! \brief ERROR command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = error message
 */
static int
ms_error(struct Client *source_p, int parc, char *parv[])
{
  const char *message = (parc > 1 && !EmptyString(parv[1])) ? parv[1] : "<>";

  ilog(LOG_TYPE_IRCD, "Received ERROR message from %s: %s",
       source_p->name, message);

  if (MyConnect(source_p))
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "ERROR :from %s -- %s",
                         get_client_name(source_p->from, MASK_IP), message);
  else
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "ERROR :from %s via %s -- %s",
                         source_p->name,
                         get_client_name(source_p->from, MASK_IP), message);
  return 0;
}

static struct Message error_msgtab =
{
  .cmd = "ERROR",
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = mr_error,
  .handlers[CLIENT_HANDLER] = m_ignore,
  .handlers[SERVER_HANDLER] = ms_error,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = m_ignore
};

static void
module_init(void)
{
  mod_add_cmd(&error_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&error_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
