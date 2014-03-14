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

/*! \file m_ping.c
 * \brief Includes required functions for processing the PING command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "irc_string.h"
#include "parse.h"
#include "modules.h"
#include "hash.h"
#include "conf.h"
#include "s_serv.h"


/*
** m_ping
**      parv[0] = command
**      parv[1] = origin
**      parv[2] = destination
*/
static int
m_ping(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p;
  char *origin, *destination;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NOORIGIN);
    return 0;
  }

  origin = parv[1];
  destination = parv[2];  /* Will get NULL or pointer (parc >= 2!!) */

  if (ConfigServerHide.disable_remote_commands && !HasUMode(source_p, UMODE_OPER))
  {
    sendto_one(source_p, ":%s PONG %s :%s", me.name,
              (destination) ? destination : me.name, origin);
    return 0;
  }

  if (!EmptyString(destination) && irccmp(destination, me.name) != 0)
  {
    /* We're sending it across servers.. origin == source_p->name --fl_ */
    origin = source_p->name;

    if ((target_p = hash_find_server(destination)))
      sendto_one(target_p, ":%s PING %s :%s", source_p->name,
                 origin, destination);
    else
      sendto_one_numeric(source_p, &me, ERR_NOSUCHSERVER, destination);
  }
  else
    sendto_one(source_p, ":%s PONG %s :%s", me.name,
               (destination) ? destination : me.name, origin);
  return 0;
}

static int
ms_ping(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p;
  const char *origin, *destination;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NOORIGIN);
    return 0;
  }

  origin = source_p->name;
  destination = parv[2];  /* Will get NULL or pointer (parc >= 2!!) */

  if (!EmptyString(destination) && irccmp(destination, me.name) != 0 && irccmp(destination, me.id) != 0)
  {
    if ((target_p = hash_find_server(destination)))
      sendto_one(target_p, ":%s PING %s :%s", source_p->name,
                 origin, destination);
    else
      sendto_one_numeric(source_p, &me, ERR_NOSUCHSERVER, destination);
  }
  else
    sendto_one(source_p, ":%s PONG %s :%s", ID_or_name(&me, source_p),
               (destination) ? destination : me.name, origin);
  return 0;
}

static struct Message ping_msgtab =
{
  "PING", 0, 0, 1, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_ping, ms_ping, m_ignore, m_ping, m_ping }
};

static void
module_init(void)
{
  mod_add_cmd(&ping_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&ping_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
