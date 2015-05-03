/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
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
#include "server.h"


/*! \brief PING command handler
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
m_ping(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  const char *destination = NULL;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NOORIGIN);
    return 0;
  }

  destination = parv[2];  /* Will get NULL or pointer (parc >= 2!!) */

  if (ConfigServerHide.disable_remote_commands && !HasUMode(source_p, UMODE_OPER))
  {
    sendto_one(source_p, ":%s PONG %s :%s", me.name,
               (destination) ? destination : me.name, parv[1]);
    return 0;
  }

  if (!EmptyString(destination) && irccmp(destination, me.name))
  {
    if ((target_p = hash_find_server(destination)))
      sendto_one(target_p, ":%s PING %s :%s",
                 ID_or_name(source_p, target_p), source_p->name,
                 ID_or_name(target_p, target_p));
    else
      sendto_one_numeric(source_p, &me, ERR_NOSUCHSERVER, destination);
  }
  else
    sendto_one(source_p, ":%s PONG %s :%s", me.name,
               (destination) ? destination : me.name, parv[1]);
  return 0;
}

/*! \brief PING command handler
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
ms_ping(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  const char *destination = NULL;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NOORIGIN);
    return 0;
  }

  destination = parv[2];  /* Will get NULL or pointer (parc >= 2!!) */

  if (!EmptyString(destination) && irccmp(destination, me.name) && irccmp(destination, me.id))
  {
    if ((target_p = hash_find_server(destination)))
    {
      if (target_p->from != source_p->from)
        sendto_one(target_p, ":%s PING %s :%s",
                   ID_or_name(source_p, target_p), source_p->name,
                   ID_or_name(target_p, target_p));
    }
    else if (!IsDigit(*destination))
      sendto_one_numeric(source_p, &me, ERR_NOSUCHSERVER, destination);
  }
  else
    sendto_one(source_p, ":%s PONG %s :%s", ID_or_name(&me, source_p),
               (destination) ? destination : me.name, ID_or_name(source_p, source_p));
  return 0;
}

static struct Message ping_msgtab =
{
  .cmd = "PING",
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_ping,
  .handlers[SERVER_HANDLER] = ms_ping,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = m_ping
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

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
