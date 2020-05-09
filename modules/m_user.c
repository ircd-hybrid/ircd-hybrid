/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2020 ircd-hybrid development team
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
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "user.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "listener.h"


/* do_user()
 *
 * inputs       -
 * output       - NONE
 * side effects -
 */
static void
do_user(struct Client *source_p,
        const char *username,
        const char *realname)
{
  assert(IsUnknown(source_p));

  source_p->connection->registration &= ~REG_NEED_USER;

  strlcpy(source_p->info, realname, sizeof(source_p->info));

  if (!HasFlag(source_p, FLAGS_GOTID))
    strlcpy(source_p->username, username, sizeof(source_p->username));

  if (source_p->connection->registration == 0)
    register_local_user(source_p);
}

/*! \brief USER command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
mr_user(struct Client *source_p, int parc, char *parv[])
{
  const char *const username = parv[1];
  const char *const realname = parv[4];

  if (source_p->connection->listener->flags & LISTENER_SERVER)
  {
    exit_client(source_p, "Use a different port");
    return;
  }

  char *p = strchr(username, '@');
  if (p)
    *p = '\0';

  do_user(source_p, username, realname);
}

static struct Message user_msgtab =
{
  .cmd = "USER",
  .handlers[UNREGISTERED_HANDLER] = { .handler = mr_user, .args_min = 5 },
  .handlers[CLIENT_HANDLER] = { .handler = m_registered },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_registered }
};

static void
module_init(void)
{
  mod_add_cmd(&user_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&user_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
