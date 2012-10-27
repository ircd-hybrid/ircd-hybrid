/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_post.c: Exits the user if unregistered, it is a web form.
 *
 *  Copyright (C) 2001-2002 Hybrid Development Team
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
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_conf.h"

static void mr_dumb_proxy(struct Client *, struct Client *, int, char *[]);

struct Message post_msgtab = {
  "POST", 0, 0, 0, 0, MFLG_SLOW | MFLG_UNREG, 0,
  {mr_dumb_proxy, m_ignore, m_ignore, m_ignore, m_ignore, m_ignore}
};

struct Message get_msgtab = {
  "GET", 0, 0, 0, 0, MFLG_SLOW | MFLG_UNREG, 0,
  {mr_dumb_proxy, m_ignore, m_ignore, m_ignore, m_ignore, m_ignore}
};

struct Message put_msgtab = {
  "PUT", 0, 0, 0, 0, MFLG_SLOW | MFLG_UNREG, 0,
  {mr_dumb_proxy, m_ignore, m_ignore, m_ignore, m_ignore, m_ignore}
};

void
_modinit(void)
{
  mod_add_cmd(&post_msgtab);
  mod_add_cmd(&get_msgtab);
  mod_add_cmd(&put_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&post_msgtab);
  mod_del_cmd(&get_msgtab);
  mod_del_cmd(&put_msgtab);
}

const char *_version = "$Revision$";

/*
** mr_dumb_proxy
**      parv[0] = sender prefix
**      parv[1] = comment
*/
static void
mr_dumb_proxy(struct Client *client_p, struct Client *source_p,
              int parc, char *parv[])
{
  sendto_realops_flags(UMODE_REJ, L_ALL,
                       "HTTP Proxy disconnected: [%s@%s]",
                       client_p->username, client_p->host);
  exit_client(source_p, source_p, "Client Exit");
}
