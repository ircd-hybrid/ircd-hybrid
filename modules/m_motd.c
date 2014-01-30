/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 */

/*! \file m_motd.c
 * \brief Includes required functions for processing the MOTD command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "motd.h"
#include "ircd.h"
#include "send.h"
#include "numeric.h"
#include "s_serv.h"     /* hunt_server */
#include "parse.h"
#include "modules.h"
#include "conf.h"


static void
do_motd(struct Client *source_p)
{
  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                       "MOTD requested by %s (%s@%s) [%s]",
                       source_p->name, source_p->username,
                       source_p->host, source_p->servptr->name);
  motd_send(source_p);
}

/*
** m_motd
**      parv[0] = sender prefix
**      parv[1] = servername
*/
static int
m_motd(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    /* safe enough to give this on a local connect only */
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return 0;
  }

  last_used = CurrentTime;

  /* This is safe enough to use during non hidden server mode */
  if (!ConfigServerHide.disable_remote_commands && !ConfigServerHide.hide_servers)
    if (hunt_server(client_p, source_p, ":%s MOTD :%s", 1,
                    parc, parv) != HUNTED_ISME)
      return 0;

  do_motd(source_p);
  return 0;
}

/*
 * note regarding mo_motd being used twice:
 * this is not a kludge.  any rate limiting, shide, or whatever
 * other access restrictions should be done by the source's server.
 * for security's sake, still check that the source is an oper
 * for 'oper only' information in the mo_ function(s).
 */

/*
** mo_motd
**      parv[0] = sender prefix
**      parv[1] = servername
*/
static int
mo_motd(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if (hunt_server(client_p, source_p, ":%s MOTD :%s", 1,
                  parc, parv) != HUNTED_ISME)
    return 0;

  do_motd(source_p);
  return 0;
}

static struct Message motd_msgtab =
{
  "MOTD", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_motd, mo_motd, m_ignore, mo_motd, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&motd_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&motd_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
