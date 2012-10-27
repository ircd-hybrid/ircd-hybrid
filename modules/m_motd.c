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
#include "client.h"
#include "tools.h"
#include "motd.h"
#include "ircd.h"
#include "send.h"
#include "numeric.h"
#include "handlers.h"
#include "hook.h"
#include "msg.h"
#include "s_serv.h"     /* hunt_server */
#include "parse.h"
#include "modules.h"
#include "s_conf.h"

static void mr_motd(struct Client *, struct Client *, int, char **);
static void m_motd(struct Client*, struct Client*, int, char**);
static void mo_motd(struct Client*, struct Client*, int, char**);

/*
 * note regarding mo_motd being used twice:
 * this is not a kludge.  any rate limiting, shide, or whatever
 * other access restrictions should be done by the source's server.
 * for security's sake, still check that the source is an oper
 * for 'oper only' information in the mo_ function(s).
 */
struct Message motd_msgtab = {
  "MOTD", 0, 0, 0, 1, MFLG_SLOW, 0,
  {mr_motd, m_motd, mo_motd, m_ignore, mo_motd, m_ignore}
};

#ifndef STATIC_MODULES
const char *_version = "$Revision$";
static struct Callback *motd_cb;

static void *
do_motd(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);

  send_message_file(source_p, &ConfigFileEntry.motd);
  return NULL;
}

void
_modinit(void)
{
  motd_cb = register_callback("doing_motd", do_motd);
  mod_add_cmd(&motd_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&motd_msgtab);
  uninstall_hook(motd_cb, do_motd);
}
#endif

/* mr_motd()
 *
 * parv[0] = sender prefix
 */
static void
mr_motd(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  /* allow unregistered clients to see the motd, but exit them */
  send_message_file(source_p, &ConfigFileEntry.motd);
  exit_client(source_p, source_p, "Client Exit after MOTD");
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
    sendto_one(source_p, form_str(RPL_LOAD2HI), me.name, source_p->name);
    return;
  }
  else
    last_used = CurrentTime;

  /* This is safe enough to use during non hidden server mode */
  if (!ConfigFileEntry.disable_remote && !ConfigServerHide.hide_servers)
  {
    if (hunt_server(client_p, source_p, ":%s MOTD :%s", 1,parc,parv)!=HUNTED_ISME)
      return;
  }

#ifdef STATIC_MODULES
  send_message_file(source_p, &ConfigFileEntry.motd);
#else
  execute_callback(motd_cb, source_p, parc, parv);
#endif
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

  if (hunt_server(client_p, source_p, ":%s MOTD :%s",1,parc,parv)!=HUNTED_ISME)
    return;

#ifdef STATIC_MODULES
  send_message_file(source_p, &ConfigFileEntry.motd);
#else
  execute_callback(motd_cb, source_p, parc, parv);
#endif
}
