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

/*! \file m_pong.c
 * \brief Includes required functions for processing the PONG command.
 * \version $Id$
 */

#include "stdinc.h"
#include "ircd.h"
#include "user.h"
#include "client.h"
#include "hash.h"
#include "numeric.h"
#include "conf.h"
#include "send.h"
#include "irc_string.h"
#include "parse.h"
#include "modules.h"


/*! \brief PONG command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = origin
 *      - parv[2] = destination
 */
static int
ms_pong(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p;
  const char *origin, *destination;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NOORIGIN);
    return 0;
  }

  origin = parv[1];
  destination = parv[2];

  /* Now attempt to route the PONG, comstud pointed out routable PING
   * is used for SPING.  routable PING should also probably be left in
   *        -Dianora
   * That being the case, we will route, but only for registered clients (a
   * case can be made to allow them only from servers). -Shadowfax
   */
  if (!EmptyString(destination) && match(destination, me.name) &&
      irccmp(destination, me.id))
  {
    if ((target_p = hash_find_client(destination)) ||
        (target_p = hash_find_server(destination)))
      sendto_one(target_p, ":%s PONG %s %s",
                 source_p->name, origin, destination);
    else
      sendto_one_numeric(source_p, &me, ERR_NOSUCHSERVER, destination);
  }

  return 0;
}

/*! \brief PONG command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = origin/ping cookie
 */
static int
mr_pong(struct Client *source_p, int parc, char *parv[])
{
  assert(MyConnect(source_p));

  if (parc == 2 && !EmptyString(parv[1]))
  {
    if (ConfigFileEntry.ping_cookie && !source_p->localClient->registration)
    {
      unsigned int incoming_ping = strtoul(parv[1], NULL, 10);

      if (incoming_ping)
      {
        if (source_p->localClient->random_ping == incoming_ping)
        {
          SetPingCookie(source_p);
          register_local_user(source_p);
        }
        else
          sendto_one_numeric(source_p, &me, ERR_WRONGPONG,
                             source_p->localClient->random_ping);
      }
    }
  }
  else
    sendto_one_numeric(source_p, &me, ERR_NOORIGIN);

  return 0;
}

static struct Message pong_msgtab =
{
  "PONG", 0, 0, 1, MAXPARA, MFLG_SLOW, 0,
  { mr_pong, m_ignore, ms_pong, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&pong_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&pong_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
