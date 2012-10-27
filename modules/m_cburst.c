/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_cburst.c: Bursts a channel to a lazy-link from the hub.
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
#include "s_serv.h"       /* captab, send_channel_burst */
#include "s_user.h"
#include "send.h"
#include "msg.h"
#include "handlers.h"
#include "parse.h"
#include "modules.h"


static void ms_cburst(struct Client*, struct Client*, int, char**);

struct Message cburst_msgtab = {
  "CBURST", 0, 0, 1, 0, MFLG_SLOW | MFLG_UNREG, 0L,
  {m_unregistered, m_ignore, ms_cburst, m_ignore, m_ignore, m_ignore}
};
#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&cburst_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&cburst_msgtab);
}

const char *_version = "$Revision$";
#endif

/*
** m_cburst
**      parv[0] = sender prefix
**      parv[1] = channel
**      parv[2] = nick if present (!nick indicates cjoin)
**      parv[3] = channel key (EVENTUALLY)
*/
/*
 * This function will "burst" the given channel onto
 * the given LL capable server.
 */

static void 
ms_cburst(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  char *name;
  char *nick;
  const char *key;
  struct Channel *chptr;

  if (parc < 2 || *parv[1] == '\0' )
     return;

  name = parv[1];

  if (parc > 2)
    nick = parv[2];
  else
    nick = NULL;

  if (parc > 3)
    key = parv[3];
  else
    key = "";

#ifdef DEBUGLL
  sendto_realops_flags(UMODE_ALL, L_ALL, "CBURST called by %s for %s %s %s",
                       client_p->name, name, nick ? nick : "", key ? key : "");
#endif
  if ((chptr = hash_find_channel(name)) == NULL)
  {
    if ((!nick) || (nick && *nick != '!'))
    {
      if (!check_channel_name(name, 0))
      {
        sendto_realops_flags(UMODE_DEBUG, L_ALL,
                             "*** Too long or invalid channel name from %s: %s",
                             client_p->name, name);
        return;
      }

      chptr = make_channel(name);
      chptr->channelts = (time_t)(-1); /* highest possible TS so its always
					* over-ruled
                                        */
    }
    else if(nick && *nick=='!')
    {
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, nick+1, name);
      return;
    }
  }

  if (IsCapable(client_p,CAP_LL))
  {
    burst_channel(client_p,chptr);

    if (nick)
      sendto_one(client_p, ":%s LLJOIN %s %s %s",
                 me.name, name, nick, key);
  }
  else
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "*** CBURST request received from non LL capable server! [%s]",
                         client_p->name);
    }
}
