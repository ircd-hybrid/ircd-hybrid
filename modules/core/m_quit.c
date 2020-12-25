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

/*! \file m_quit.c
 * \brief Includes required functions for processing the QUIT command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"


/*! \brief QUIT command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = quit message
 */
static void
m_quit(struct Client *source_p, int parc, char *parv[])
{
  char reason[KICKLEN + 1] = "Quit: ";

  if (!EmptyString(parv[1]) && (HasUMode(source_p, UMODE_OPER) ||
      (source_p->connection->created_monotonic + ConfigGeneral.anti_spam_exit_message_time)
      < event_base->time.sec_monotonic))
    strlcpy(reason + 6, parv[1], sizeof(reason) - 6);

  exit_client(source_p, reason);
}

/*! \brief QUIT command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = quit message
 */
static void
ms_quit(struct Client *source_p, int parc, char *parv[])
{
  char reason[KICKLEN + 1] = "";  /* Essential that buf[0] = '\0' */

  if (!EmptyString(parv[1]))
    strlcpy(reason, parv[1], sizeof(reason));

  exit_client(source_p, reason);
}

static struct Message quit_msgtab =
{
  .cmd = "QUIT",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_quit },
  .handlers[CLIENT_HANDLER] = { .handler = m_quit },
  .handlers[SERVER_HANDLER] = { .handler = ms_quit },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_quit }
};

static void
module_init(void)
{
  mod_add_cmd(&quit_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&quit_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
  .is_core = true
};
