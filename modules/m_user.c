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

/*! \file m_user.c
 * \brief Includes required functions for processing the USER command.
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "user.h"
#include "send.h"
#include "parse.h"
#include "module.h"
#include "listener.h"


/*! \brief USER command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = username (login name, account)
 *      - parv[2] = client host name (ignored)
 *      - parv[3] = server host name (ignored)
 *      - parv[4] = user's real name info
 */
static void
mr_user(struct Client *source, int parc, char *parv[])
{
  const char *const username = parv[1];
  const char *const realname = parv[4];

  assert(IsUnknown(source));

  if (listener_has_flag(source->connection->listener, LISTENER_SERVER))
  {
    client_exit(source, "Use a different port");
    return;
  }

  if (!HasFlag(source, FLAGS_GOTID))
  {
    char *p = strchr(username, '@');
    if (p)
      *p = '\0';

    strlcpy(source->username, username, sizeof(source->username));
  }

  strlcpy(source->info, realname, sizeof(source->info));
  source->connection->registration &= ~REG_NEED_USER;

  if (source->connection->registration == 0)
    user_register_local(source);
}

static struct Command command_table =
{
  .name = "USER",
  .handlers[UNREGISTERED_HANDLER] = { .handler = mr_user, .args_min = 5 },
  .handlers[CLIENT_HANDLER] = { .handler = m_registered },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_registered }
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
