/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2020-2024 ircd-hybrid development team
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

/*! \file m_metadata.c
 * \brief Includes required functions for processing the METADATA command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "parse.h"
#include "memory.h"
#include "module.h"
#include "irc_string.h"


/*! \brief METADATA command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
ms_metadata(struct Client *source, int parc, char *parv[])
{
  if (!HasFlag(source, FLAGS_SERVICE) && !IsServer(source))
    return;

  if (irccmp(parv[1], "client") == 0)
  {
    struct Client *target = find_person(source, parv[2]);
    if (target == NULL)
      return;

    if (irccmp(parv[3], "cipher") == 0)
    {
      io_free(target->tls_cipher);
      if (!EmptyString(parv[4]))
        target->tls_cipher = io_strdup(parv[4]);
      else
        target->tls_cipher = NULL;
    }

    if (irccmp(parv[3], "certfp") == 0)
    {
      io_free(target->tls_certfp);
      if (!EmptyString(parv[4]))
        target->tls_certfp = io_strdup(parv[4]);
      else
        target->tls_certfp = NULL;
    }
  }

  if (parc == 4)
    sendto_servers(source, 0, 0, ":%s METADATA %s %s %s",
                   source->id, parv[1], parv[2], parv[3]);
  else  /* parc == 5 */
    sendto_servers(source, 0, 0, ":%s METADATA %s %s %s :%s",
                   source->id, parv[1], parv[2], parv[3], parv[4]);
}

static struct Command command_table =
{
  .name = "METADATA",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_metadata, .args_min = 4 },
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
