/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_lusers.c: Sends user statistics.
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
#include "numeric.h"
#include "s_serv.h"    /* hunt_server */
#include "s_user.h"    /* show_lusers */
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"


/* m_lusers - LUSERS message handler
 * parv[0] = sender
 * parv[1] = host/server mask.
 * parv[2] = server to query
 * 
 * 199970918 JRL hacked to ignore parv[1] completely and require parc > 3
 * to cause a force
 *
 * 2003 hacked parv[1] back in, by request of efnet admins/opers -Dianora
 */
static void
m_lusers(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait_simple) > CurrentTime)
  {
    /* safe enough to give this on a local connect only */
    sendto_one(source_p, RPL_LOAD2HI, me.name, source_p->name);
    return;
  }

  last_used = CurrentTime;

  if (parc > 2 && !ConfigFileEntry.disable_remote)
    if (hunt_server(client_p, source_p, ":%s LUSERS %s :%s", 2,
                    parc, parv) != HUNTED_ISME)
      return;

  show_lusers(source_p);
}

/* ms_lusers - LUSERS message handler for servers and opers
 * parv[0] = sender
 * parv[1] = host/server mask.
 * parv[2] = server to query
 */
static void
ms_lusers(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  if (parc > 2)
    if (hunt_server(client_p, source_p, ":%s LUSERS %s :%s", 2,
                    parc, parv) != HUNTED_ISME)
        return;

  if (IsClient(source_p))
    show_lusers(source_p);
}

static struct Message lusers_msgtab = {
  "LUSERS", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_lusers, ms_lusers, m_ignore, ms_lusers, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&lusers_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&lusers_msgtab);
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
