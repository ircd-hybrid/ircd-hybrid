/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_restart.c: Exits and re-runs ircd.
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
#include "handlers.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "restart.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"

static void mo_restart(struct Client *, struct Client *, int, char *[]);

struct Message restart_msgtab = {
  "RESTART", 0, 0, 0, 0, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_restart, m_ignore }
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&restart_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&restart_msgtab);
}

const char *_version = "$Revision$";
#endif

/*
 * mo_restart
 *
 */
static void
mo_restart(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  char buf[IRCD_BUFSIZE]; 

  if (!IsOperDie(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "restart");
    return;
  }

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, ":%s NOTICE %s :Need server name /restart %s",
               me.name, source_p->name, me.name);
    return;
  }

  if (irccmp(parv[1], me.name))
  {
    sendto_one(source_p, ":%s NOTICE %s :Mismatch on /restart %s",
               me.name, source_p->name, me.name);
    return;
  }

  ircsprintf(buf, "received RESTART command from %s",
             get_oper_name(source_p));
  server_die(buf, YES);
}
