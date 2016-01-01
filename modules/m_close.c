/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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
 * \version $Id$
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
static int
mo_close(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node = NULL, *node_next = NULL;
  unsigned int closed = dlink_list_length(&unknown_list);

  if (!HasOFlag(source_p, OPER_FLAG_CLOSE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "close");
    return 0;
  }

  DLINK_FOREACH_SAFE(node, node_next, unknown_list.head)
  {
    struct Client *target_p = node->data;

    sendto_one_numeric(source_p, &me, RPL_CLOSING,
                       get_client_name(target_p, SHOW_IP),
                       target_p->status);

    /*
     * Exit here is safe, because it is guaranteed not to be source_p
     * because it is unregistered and source_p is an oper.
     */
    exit_client(target_p, "Oper Closing");
  }

  sendto_one_numeric(source_p, &me, RPL_CLOSEEND, closed);
  return 0;
}

static struct Message close_msgtab =
{
  .cmd = "CLOSE",
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = m_ignore,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_close
};

static void
module_init(void)
{
  mod_add_cmd(&close_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&close_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
