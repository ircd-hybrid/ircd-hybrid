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

/*! \file m_close.c
 * \brief Includes required functions for processing the CLOSE command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/*! \brief CLOSE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
mo_close(struct Client *source_p, int parc, char *parv[])
{
  if (!HasOFlag(source_p, OPER_FLAG_CLOSE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "close");
    return;
  }

  const unsigned int closed = dlink_list_length(&unknown_list);
  while (unknown_list.head)
  {
    struct Client *target_p = unknown_list.head->data;

    sendto_one_numeric(source_p, &me, RPL_CLOSING,
                       client_get_name(target_p, SHOW_IP), target_p->status);

    /*
     * Exit here is safe, because it is guaranteed not to be source_p
     * because it is unregistered and source_p is an oper.
     */
    exit_client(target_p, "Oper Closing");
  }

  sendto_one_numeric(source_p, &me, RPL_CLOSEEND, closed);
}

static struct Command close_msgtab =
{
  .name = "CLOSE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_close }
};

static void
module_init(void)
{
  command_add(&close_msgtab);
}

static void
module_exit(void)
{
  command_del(&close_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
