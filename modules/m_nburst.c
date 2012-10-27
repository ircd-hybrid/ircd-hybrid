/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_nburst.c: Requests that a nick be burst to a lazylink.
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
#include "tools.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"
#include "msg.h"
#include "handlers.h"
#include "parse.h"
#include "modules.h"
#include "s_conf.h"


static void ms_nburst(struct Client*, struct Client*, int, char**);

struct Message nburst_msgtab = {
  "NBURST", 0, 0, 1, 0, MFLG_SLOW | MFLG_UNREG, 0L,
  {m_unregistered, m_ignore, ms_nburst, m_ignore, m_ignore, m_ignore}
};
#ifndef STATIC_MODULES

void
_modinit(void)
{
  mod_add_cmd(&nburst_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&nburst_msgtab);
}

const char *_version = "$Revision$";
#endif
/*
** m_nburst
**      parv[0] = sender prefix
**      parv[1] = nickname to burst
**      parv[2] = new nick (optional)
**      parv[3] = old nick (optional)
*/
/*
 * This function will "burst" the given channel onto
 * the given LL capable server.
 */

static void
ms_nburst(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  char *nick;
  char *nick_new = NULL;
  char *nick_old = NULL;
  struct Client *target_p;
  char status;

  if (parc < 2 || *parv[1] == '\0')
     return;

  nick = parv[1];

  if (parc > 2)
    nick_new = parv[2];

  if (parc > 3)
    nick_old = parv[3];

  if (!ServerInfo.hub && IsCapable(client_p, CAP_LL))
    return;
#ifdef DEBUGLL
  sendto_realops_flags(UMODE_ALL, L_ALL, "NBURST called by %s for %s %s %s",
    client_p->name,
    nick,
    nick_new ? nick_new : "",
    nick_old ? nick_old : "" );
#endif

  status = 'N';
  if ((target_p = find_client(nick)) != NULL)
  {
    /* nick exists.  burst nick back to leaf */
    status = 'Y';
    client_burst_if_needed(client_p, target_p);
  }

  /* Send back LLNICK, if wanted */
  if (parc > 2)
    sendto_one(client_p, ":%s LLNICK %c %s %s", me.name, status, nick_new,
               (nick_old ? nick_old : ""));
}
