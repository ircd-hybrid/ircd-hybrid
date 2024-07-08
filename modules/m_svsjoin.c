/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2014-2024 ircd-hybrid development team
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

/*! \file m_svsjoin.c
 * \brief Includes required functions for processing the SVSJOIN command.
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "send.h"
#include "parse.h"
#include "module.h"


/*! \brief SVSJOIN command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = channel
 *      - parv[3] = channel password (key)
 */
static void
ms_svsjoin(struct Client *source, int parc, char *parv[])
{
  if (!HasFlag(source, FLAGS_SERVICE) && !IsServer(source))
    return;

  struct Client *target = find_person(source, parv[1]);
  if (target == NULL)
    return;

  if (MyConnect(target))
  {
    channel_join_list(target, parv[2], parv[3]);
    return;
  }

  if (target->from == source->from)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                         "Received wrong-direction SVSJOIN for %s (behind %s) from %s",
                         target->name, source->from->name, client_get_name(source, HIDE_IP));
    return;
  }

  if (EmptyString(parv[3]))
    sendto_one(target, ":%s SVSJOIN %s %s",
               source->id, target->id, parv[2]);
  else
    sendto_one(target, ":%s SVSJOIN %s %s %s",
               source->id, target->id, parv[2], parv[3]);
}

static struct Command command_table =
{
  .name = "SVSJOIN",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_svsjoin, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
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
