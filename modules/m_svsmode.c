/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999 Bahamut development team.
 *  Copyright (c) 2011-2024 ircd-hybrid development team
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

/*! \file m_svsmode.c
 * \brief Includes required functions for processing the SVSMODE command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "client_svstag.h"
#include "ircd.h"
#include "send.h"
#include "channel.h"
#include "channel_mode.h"
#include "parse.h"
#include "module.h"
#include "user_mode.h"
#include "conf.h"


/*! \brief SVSMODE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = TS
 *      - parv[3] = modes to be added or removed
 */
static void
ms_svsmode(struct Client *source, int parc, char *parv[])
{
  const char *const modes = parv[3];

  if (!HasFlag(source, FLAGS_SERVICE) && !IsServer(source))
    return;

  struct Client *target = find_person(source, parv[1]);
  if (target == NULL)
    return;

  uintmax_t ts = strtoumax(parv[2], NULL, 10);
  if (ts && (ts != target->tsinfo))
    return;

  const uint64_t oldmodes = target->umodes;
  user_mode_action_t action = USER_MODE_ACTION_ADD;

  for (const char *m = modes; *m; ++m)
  {
    switch (*m)
    {
      case '+':
        action = USER_MODE_ACTION_ADD;
        break;
      case '-':
        action = USER_MODE_ACTION_DEL;
        break;
      default:
        user_mode_change(target, *m, USER_MODE_SOURCE_SVSMODE, action);
        break;
    }
  }

  sendto_servers(source, 0, 0, ":%s SVSMODE %s %ju %s",
                 source->id, target->id, target->tsinfo, modes);

  if (MyConnect(target))
    user_mode_send(target, oldmodes, true, false);
}

static struct Command command_table =
{
  .name = "SVSMODE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_svsmode, .args_min = 4 },
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
