/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

/*! \file m_away.c
 * \brief Includes required functions for processing the AWAY command.
 */

#include "stdinc.h"
#include "memory.h"
#include "module.h"
#include "io_string.h"
#include "io_time.h"
#include "cap.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "conf.h"


/*!
 *
 * \param source Pointer to client to set (un)away
 * \param message  Away message; can be NULL
 */
static void
do_away(struct Client *source, const char *message)
{
  assert(IsClient(source));

  if (string_is_empty(message))
  {
    /* Marking as not away */
    if (source->away_message)
    {
      io_free(source->away_message);
      source->away_message = NULL;

      /* We now send this only if they were away before --is */
      sendto_servers(source, 0, 0, ":%s AWAY", source->id);
      sendto_common_channels_local(source, true, CAP_AWAY_NOTIFY, 0, ":%s!%s@%s AWAY",
                                   source->name, source->username, source->host);
    }

    if (client_is_local(source))
      sendto_one_numeric(source, &me, RPL_UNAWAY);
    return;
  }

  if (client_is_local(source))
  {
    if ((source->connection->away.last_attempt + ConfigGeneral.away_time) < io_time_get(IO_TIME_MONOTONIC_SEC))
      source->connection->away.count = 0;

    if (source->connection->away.count > ConfigGeneral.away_count)
    {
      sendto_one_numeric(source, &me, ERR_TOOMANYAWAY);
      return;
    }

    source->connection->away.last_attempt = io_time_get(IO_TIME_MONOTONIC_SEC);
    source->connection->away.count++;
    sendto_one_numeric(source, &me, RPL_NOWAWAY);

    if (source->away_message && strncmp(source->away_message, message, ConfigGeneral.max_away_length) == 0)
      return;
  }

  io_free(source->away_message);
  source->away_message = io_strndup(message, ConfigGeneral.max_away_length);

  sendto_servers(source, 0, 0, ":%s AWAY :%s",
                 source->id, source->away_message);
  sendto_common_channels_local(source, true, CAP_AWAY_NOTIFY, 0, ":%s!%s@%s AWAY :%s",
                               source->name, source->username, source->host, source->away_message);
}

/*! \brief AWAY command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = away message
 */
static void
m_away(struct Client *source, int parc, char *parv[])
{
  const char *const message = parv[1];

  do_away(source, message);
}

static struct Command command_table =
{
  .name = "AWAY",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_away },
  .handlers[SERVER_HANDLER] = { .handler = m_away },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_away }
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
