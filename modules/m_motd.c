/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_motd.c: Shows the current message of the day.
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
#include "motd.h"
#include "ircd.h"
#include "send.h"
#include "numeric.h"
#include "handlers.h"
#include "msg.h"
#include "s_serv.h"     /* hunt_server */
#include "parse.h"
#include "modules.h"
#include "s_conf.h"

static void m_motd(struct Client *, struct Client *, int, char *[]);
static void mo_motd(struct Client *, struct Client *, int, char *[]);

/*
 * note regarding mo_motd being used twice:
 * this is not a kludge.  any rate limiting, shide, or whatever
 * other access restrictions should be done by the source's server.
 * for security's sake, still check that the source is an oper
 * for 'oper only' information in the mo_ function(s).
 */
struct Message motd_msgtab = {
  "MOTD", 0, 0, 0, 1, MFLG_SLOW, 0,
  { m_unregistered, m_motd, mo_motd, m_ignore, mo_motd, m_ignore }
};

const char *_version = "$Revision$";

static void
do_motd(struct Client *source_p)
{
  sendto_realops_flags(UMODE_SPY, L_ALL,
                       "MOTD requested by %s (%s@%s) [%s]",
                       source_p->name, source_p->username,
                       source_p->host, source_p->servptr->name);
  send_message_file(source_p, &ConfigFileEntry.motd);
}

void
_modinit(void)
{
  mod_add_cmd(&motd_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&motd_msgtab);
}

/*
** m_motd
**      parv[0] = sender prefix
**      parv[1] = servername
*/
static void
m_motd(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    /* safe enough to give this on a local connect only */
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }

  last_used = CurrentTime;

  /* This is safe enough to use during non hidden server mode */
  if (!ConfigFileEntry.disable_remote && !ConfigServerHide.hide_servers)
    if (hunt_server(client_p, source_p, ":%s MOTD :%s", 1,
                    parc, parv) != HUNTED_ISME)
      return;

  do_motd(source_p);
}

/*
** mo_motd
**      parv[0] = sender prefix
**      parv[1] = servername
*/
static void
mo_motd(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if (!IsClient(source_p))
    return;

  if (hunt_server(client_p, source_p, ":%s MOTD :%s", 1,
                  parc, parv) != HUNTED_ISME)
    return;

  do_motd(source_p);
}
