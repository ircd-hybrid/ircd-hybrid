/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_users.c: Gives some basic user statistics.
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
#include "s_serv.h"
#include "conf.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/*
 * m_users
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void
m_users(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  static time_t last_used = 0;

  if (last_used + ConfigFileEntry.pace_wait_simple > CurrentTime)
  {
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }

  last_used = CurrentTime;

  if (!ConfigFileEntry.disable_remote)
    if (hunt_server(client_p, source_p, ":%s USERS :%s", 1,
                    parc, parv) != HUNTED_ISME)
      return;

  sendto_one(source_p, form_str(RPL_LOCALUSERS), me.name, source_p->name,
             ConfigServerHide.hide_servers ? Count.total : Count.local,
             ConfigServerHide.hide_servers ? Count.max_tot : Count.max_loc);
  sendto_one(source_p, form_str(RPL_GLOBALUSERS), me.name, source_p->name,
             Count.total, Count.max_tot);
}

/*
 * mo_users
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void
mo_users(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (hunt_server(client_p, source_p, ":%s USERS :%s", 1,
                  parc, parv) != HUNTED_ISME)
    return;

  if (!HasUMode(source_p, UMODE_OPER) && ConfigServerHide.hide_servers)
    sendto_one(source_p, form_str(RPL_LOCALUSERS), me.name, source_p->name,
               Count.total, Count.max_tot);
  else
    sendto_one(source_p, form_str(RPL_LOCALUSERS), me.name, source_p->name,
               Count.local, Count.max_loc);

  sendto_one(source_p, form_str(RPL_GLOBALUSERS), me.name, source_p->name,
             Count.total, Count.max_tot);
}

static struct Message users_msgtab = {
  "USERS", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_users, mo_users, m_ignore, mo_users, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&users_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&users_msgtab);
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
