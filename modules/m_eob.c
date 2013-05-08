/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_eob.c: Signifies the end of a server burst.
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
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "s_serv.h"


/*
 * ms_eob - EOB command handler
 *      parv[0] = sender prefix   
 *      parv[1] = servername   
 */
static void
ms_eob(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  assert(IsServer(source_p));
  assert(client_p == source_p);

  AddFlag(source_p, FLAGS_EOB);

  sendto_server(client_p, CAP_TS6, NOCAPS,
                ":%s EOB", ID(source_p));
  sendto_server(client_p, NOCAPS, CAP_TS6,
                ":%s EOB", source_p->name);
}

static struct Message eob_msgtab = {
  "EOB", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_ignore, ms_eob, m_ignore, m_ignore, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&eob_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&eob_msgtab);
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
