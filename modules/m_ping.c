/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_ping.c: Requests that a PONG message be sent back.
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
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "irc_string.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "hash.h"
#include "s_conf.h"
#include "s_serv.h"

static void m_ping(struct Client *, struct Client *, int, char *[]);
static void ms_ping(struct Client *, struct Client *, int, char *[]);

struct Message ping_msgtab = {
  "PING", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_ping, ms_ping, m_ignore, m_ping, m_ping}
};

void
_modinit(void)
{
  mod_add_cmd(&ping_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&ping_msgtab);
}

const char *_version = "$Revision$";

/*
** m_ping
**      parv[0] = sender prefix
**      parv[1] = origin
**      parv[2] = destination
*/
static void
m_ping(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  struct Client *target_p;
  char  *origin, *destination;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOORIGIN), me.name, parv[0]);
    return;
  }

  origin = parv[1];
  destination = parv[2]; /* Will get NULL or pointer (parc >= 2!!) */

  if (ConfigFileEntry.disable_remote && !IsOper(source_p))
  {
    sendto_one(source_p,":%s PONG %s :%s", me.name,
              (destination) ? destination : me.name, origin);
    return;
  }

  if (!EmptyString(destination) && irccmp(destination, me.name) != 0)
  {
    /* We're sending it across servers.. origin == client_p->name --fl_ */
    origin = client_p->name;

    if ((target_p = find_server(destination)) != NULL)
    {
      sendto_one(target_p,":%s PING %s :%s", parv[0],
                 origin, destination);
    }
    else
    {
      sendto_one(source_p, form_str(ERR_NOSUCHSERVER),
                 me.name, parv[0], destination);
      return;
    }
  }
  else
    sendto_one(source_p,":%s PONG %s :%s", me.name,
               (destination) ? destination : me.name, origin);
}

static void
ms_ping(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Client *target_p;
  const char *origin, *destination;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOORIGIN), me.name, parv[0]);
    return;
  }

  origin = source_p->name;
  destination = parv[2]; /* Will get NULL or pointer (parc >= 2!!) */

  if (!EmptyString(destination) && irccmp(destination, me.name) != 0 && irccmp(destination, me.id) != 0)
  {
    if ((target_p = find_server(destination)))
      sendto_one(target_p,":%s PING %s :%s", parv[0],
		 origin, destination);
    else
    {
      sendto_one(source_p, form_str(ERR_NOSUCHSERVER),
                 ID_or_name(&me, client_p), parv[0], destination);
      return;
    }
  }
  else
    sendto_one(source_p,":%s PONG %s :%s",
               ID_or_name(&me, client_p), (destination) ? destination : me.name, origin);
}
