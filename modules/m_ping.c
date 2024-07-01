/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "irc_string.h"
#include "parse.h"
#include "module.h"
#include "hash.h"
#include "conf.h"


/*! \brief PING command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = origin
 *      - parv[2] = destination
 */
static void
m_ping(struct Client *source, int parc, char *parv[])
{
  struct Client *target = NULL;

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NOORIGIN);
    return;
  }

  const char *const destination = parv[2];  /* Will get NULL or pointer (parc >= 2!!) */
  if (ConfigServerHide.disable_remote_commands && !HasUMode(source, UMODE_OPER))
  {
    sendto_one(source, ":%s PONG %s :%s",
               me.name, (destination) ? destination : me.name, parv[1]);
    return;
  }

  if (EmptyString(destination) || ((target = hash_find_server(destination)) && IsMe(target)))
    sendto_one(source, ":%s PONG %s :%s", me.name, me.name, parv[1]);
  else if (target)
    sendto_one(target, ":%s PING %s :%s",
               ID_or_name(source, target), source->name, ID_or_name(target, target));
  else
    sendto_one_numeric(source, &me, ERR_NOSUCHSERVER, destination);
}

/*! \brief PING command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = origin
 *      - parv[2] = destination
 */
static void
ms_ping(struct Client *source, int parc, char *parv[])
{
  struct Client *target = NULL;

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NOORIGIN);
    return;
  }

  const char *const destination = parv[2];  /* Will get NULL or pointer (parc >= 2!!) */
  if (EmptyString(destination) || ((target = hash_find_server(destination)) && IsMe(target)))
    sendto_one(source, ":%s PONG %s :%s",
               ID_or_name(&me, source), me.name, ID_or_name(source, source));
  else if (target)
  {
    if (target->from != source->from)
      sendto_one(target, ":%s PING %s :%s",
                 ID_or_name(source, target), source->name, ID_or_name(target, target));
  }
  else if (!IsDigit(*destination))
    sendto_one_numeric(source, &me, ERR_NOSUCHSERVER, destination);
}

static struct Command command_table =
{
  .name = "PING",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ping },
  .handlers[SERVER_HANDLER] = { .handler = ms_ping },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ping }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
