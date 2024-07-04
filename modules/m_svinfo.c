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

/*! \file m_svinfo.c
 * \brief Includes required functions for processing the SVINFO command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "server.h"
#include "conf.h"
#include "log.h"
#include "parse.h"
#include "module.h"


/*! \brief SVINFO command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = TS_CURRENT for the server
 *      - parv[2] = TS_MINIMUM for the server
 *      - parv[3] = unused
 *      - parv[4] = server's idea of UTC time
 */
static void
ms_svinfo(struct Client *source, int parc, char *parv[])
{
  if (!IsServer(source) || !MyConnect(source))
    return;

  if (TS_CURRENT < atoi(parv[2]) || atoi(parv[1]) < TS_MINIMUM)
  {
    /*
     * A server with the wrong TS version connected; since we're
     * TS_ONLY we can't fall back to the non-TS protocol so
     * we drop the link  -orabidoo
     */
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
              "Link %s dropped, wrong TS protocol version (%s,%s)",
              client_get_name(source, SHOW_IP), parv[1], parv[2]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
              "Link %s dropped, wrong TS protocol version (%s,%s)",
              client_get_name(source, MASK_IP), parv[1], parv[2]);
    log_write(LOG_TYPE_IRCD,
              "Link %s dropped, wrong TS protocol version (%s,%s)",
              client_get_name(source, SHOW_IP), parv[1], parv[2]);

    exit_client(source, "Incompatible TS version");
    return;
  }

  /*
   * Since we're here, might as well set event_base->time.sec_real while we're at it
   */
  io_time_set();

  const uintmax_t remote_ts = strtoumax(parv[4], NULL, 10);
  const uintmax_t local_ts = io_time_get(IO_TIME_REALTIME_SEC);
  const intmax_t delta_ts = imaxabs(remote_ts - local_ts);

  if (delta_ts > ConfigGeneral.ts_max_delta)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
              "Link %s dropped, excessive TS delta (my TS=%ju, their TS=%ju, delta=%ji)",
              client_get_name(source, SHOW_IP), local_ts, remote_ts, delta_ts);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
              "Link %s dropped, excessive TS delta (my TS=%ju, their TS=%ju, delta=%ji)",
              client_get_name(source, MASK_IP), local_ts, remote_ts, delta_ts);
    log_write(LOG_TYPE_IRCD,
              "Link %s dropped, excessive TS delta (my TS=%ju, their TS=%ju, delta=%ji)",
              client_get_name(source, SHOW_IP), local_ts, remote_ts, delta_ts);

    exit_client(source, "Excessive TS delta");
    return;
  }

  if (delta_ts > ConfigGeneral.ts_warn_delta)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
              "Link %s notable TS delta (my TS=%ju, their TS=%ju, delta=%ji)",
              client_get_name(source, SHOW_IP), local_ts, remote_ts, delta_ts);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
              "Link %s notable TS delta (my TS=%ju, their TS=%ju, delta=%ji)",
              client_get_name(source, MASK_IP), local_ts, remote_ts, delta_ts);
  }
}

static struct Command command_table =
{
  .name = "SVINFO",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_svinfo, .args_min = 5 },
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
