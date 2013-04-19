/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_close.c: Closes all unregistered connections.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/*
 * mo_close - CLOSE message handler
 *  - added by Darren Reed Jul 13 1992.
 */
static void
mo_close(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  dlink_node *ptr = NULL, *ptr_next = NULL;
  unsigned int closed = dlink_list_length(&unknown_list);


  DLINK_FOREACH_SAFE(ptr, ptr_next, unknown_list.head)
  {
    struct Client *target_p = ptr->data;

    sendto_one(source_p, RPL_CLOSING, me.name, source_p->name,
               get_client_name(target_p, SHOW_IP), target_p->status);

    /*
     * exit here is safe, because it is guaranteed not to be source_p
     * because it is unregistered and source_p is an oper.
     */
    exit_client(target_p, target_p, "Oper Closing");
  }

  sendto_one(source_p, RPL_CLOSEEND,
             me.name, source_p->name, closed);
}

static struct Message close_msgtab = {
  "CLOSE", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_close, m_ignore }
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

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
