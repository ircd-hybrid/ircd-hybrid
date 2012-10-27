/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_die.c: Kills off this server.
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
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_log.h"
#include "s_conf.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "restart.h"


static void mo_die(struct Client *, struct Client *, int, char *[]);

struct Message die_msgtab = {
  "DIE", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_die, m_ignore}
};

void
_modinit(void)
{
  mod_add_cmd(&die_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&die_msgtab);
}

const char *_version = "$Revision$";

/*
 * mo_die - DIE command handler
 */
static void
mo_die(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  char buf[IRCD_BUFSIZE];

  if (!IsOperDie(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "die");
    return;
  }

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, ":%s NOTICE %s :Need server name /die %s",
               me.name, source_p->name, me.name);
    return;
  }

  if (irccmp(parv[1], me.name))
  {
    sendto_one(source_p, ":%s NOTICE %s :Mismatch on /die %s",
               me.name, source_p->name, me.name);
    return;
  }

  snprintf(buf, sizeof(buf), "received DIE command from %s",
           get_oper_name(source_p));
  server_die(buf, 0);
}
