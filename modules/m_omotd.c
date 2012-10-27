/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_omotd.c: Shows the operator message of the day.
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
#include "hook.h"
#include "msg.h"
#include "s_serv.h"     /* hunt_server */
#include "parse.h"
#include "modules.h"
#include "s_conf.h"

static void m_omotd(struct Client *, struct Client *, int, char *[]);

struct Message omotd_msgtab = {
  "OMOTD", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, m_omotd, m_ignore}
};

void
_modinit(void)
{
  mod_add_cmd(&omotd_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&omotd_msgtab);
}

const char *_version = "$Revision$";

/* m_omotd()
 *
 *      parv[0] = sender prefix
 */
static void
m_omotd(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  send_message_file(source_p, &ConfigFileEntry.opermotd);
}
