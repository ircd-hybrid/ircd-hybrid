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

/*! \file m_away.c
 * \brief Includes required functions for processing the AWAY command.
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"
#include "server.h"
#include "user.h"
#include "isupport.h"


/*!
 *
 * \param source_p Pointer to client to set (un)away
 * \param message  Away message; can be NULL
 */
static void
do_away(struct Client *source_p, const char *message)
{
  assert(IsClient(source_p));

  if (EmptyString(message))
  {
    /* Marking as not away */
    if (source_p->away[0])
    {
      source_p->away[0] = '\0';

      /* We now send this only if they were away before --is */
      sendto_server(source_p, 0, 0, ":%s AWAY", source_p->id);
      sendto_common_channels_local(source_p, true, CAP_AWAY_NOTIFY, 0, ":%s!%s@%s AWAY",
                                   source_p->name, source_p->username, source_p->host);
    }

    if (MyConnect(source_p))
      sendto_one_numeric(source_p, &me, RPL_UNAWAY);
    return;
  }

  if (MyConnect(source_p))
  {
    if ((source_p->connection->away.last_attempt + ConfigGeneral.away_time) < event_base->time.sec_monotonic)
      source_p->connection->away.count = 0;

    if (source_p->connection->away.count > ConfigGeneral.away_count)
    {
      sendto_one_numeric(source_p, &me, ERR_TOOMANYAWAY);
      return;
    }

    source_p->connection->away.last_attempt = event_base->time.sec_monotonic;
    source_p->connection->away.count++;
    sendto_one_numeric(source_p, &me, RPL_NOWAWAY);

    if (strncmp(source_p->away, message, sizeof(source_p->away) - 1) == 0)
      return;
  }

  strlcpy(source_p->away, message, sizeof(source_p->away));
  sendto_common_channels_local(source_p, true, CAP_AWAY_NOTIFY, 0, ":%s!%s@%s AWAY :%s",
                               source_p->name, source_p->username,
                               source_p->host, source_p->away);
  sendto_server(source_p, 0, 0, ":%s AWAY :%s",
                source_p->id, source_p->away);
}

/*! \brief AWAY command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = away message
 */
static void
m_away(struct Client *source_p, int parc, char *parv[])
{
  const char *const message = parv[1];

  do_away(source_p, message);
}

static struct Message away_msgtab =
{
  .cmd = "AWAY",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_away },
  .handlers[SERVER_HANDLER] = { .handler = m_away },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_away }
};

static void
module_init(void)
{
  mod_add_cmd(&away_msgtab);
  isupport_add("AWAYLEN", NULL, AWAYLEN);
}

static void
module_exit(void)
{
  mod_del_cmd(&away_msgtab);
  isupport_delete("AWAYLEN");
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
