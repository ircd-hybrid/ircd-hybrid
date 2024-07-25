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

/*! \file m_error.c
 * \brief Includes required functions for processing the ERROR command.
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "module.h"
#include "log.h"
#include "parse.h"
#include "irc_string.h"


/*! \brief ERROR command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = error message
 */
static void
mr_error(struct Client *source, int parc, char *parv[])
{
  assert(MyConnect(source));

  if (!IsHandshake(source) && !IsConnecting(source))
    return;

  const char *message = "<>";
  if (!EmptyString(parv[1]))
    message = parv[1];

  log_write(LOG_TYPE_IRCD, "Received ERROR message from %s: %s",
            client_get_name(source, SHOW_IP), message);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE, "ERROR :from %s -- %s",
                 client_get_name(source, HIDE_IP), message);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE, "ERROR :from %s -- %s",
                 client_get_name(source, MASK_IP), message);
}

/*! \brief ERROR command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = error message
 */
static void
ms_error(struct Client *source, int parc, char *parv[])
{
  const char *message = "<>";
  if (!EmptyString(parv[1]))
    message = parv[1];

  log_write(LOG_TYPE_IRCD, "Received ERROR message from %s: %s",
            client_get_name(source, SHOW_IP), message);

  if (MyConnect(source))
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "ERROR :from %s -- %s",
                   client_get_name(source->from, MASK_IP), message);
  else
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "ERROR :from %s via %s -- %s",
                   source->name, client_get_name(source->from, MASK_IP), message);
}

static struct Command command_table =
{
  .name = "ERROR",
  .handlers[UNREGISTERED_HANDLER] = { .handler = mr_error },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_error },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
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
  .core = true
};
