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

/*! \file m_whowas.c
 * \brief Includes required functions for processing the WHOWAS command.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "io_string.h"
#include "io_time.h"
#include "misc.h"
#include "module.h"

#include "client.h"
#include "conf.h"
#include "conf_service.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "whowas.h"

/** Maximum number of lines to send in response to a /WHOWAS. Only applies to remote clients. */
enum { WHOWAS_MAX_REPLIES = 20 };

static bool
_whowas_should_hide_server(const struct Client *source, const struct Whowas *whowas)
{
  if (client_is_oper(source))
    return false;

  if (whowas->server_hidden || ConfigServerHide.hide_servers)
    return true;

  return ConfigServerHide.hide_services && service_find(whowas->servername);
}

static void
_whowas_send_record(struct Client *source, const struct Whowas *whowas)
{
  sendto_one_numeric(source, &me, RPL_WHOWASUSER,
                     whowas->name, whowas->username, whowas->hostname, whowas->realname);

  if (client_is_oper(source))
    sendto_one_numeric(source, &me, RPL_WHOISACTUALLY,
                       whowas->name, whowas->username, whowas->realhost, whowas->sockhost);

  if (strcmp(whowas->account, "*"))
    sendto_one_numeric(source, &me, RPL_WHOISACCOUNT,
                       whowas->name, whowas->account, "was");

  const char *const server_name =
    _whowas_should_hide_server(source, whowas) ? ConfigServerInfo.network_name : whowas->servername;
  sendto_one_numeric(source, &me, RPL_WHOISSERVER,
                     whowas->name, server_name, date_ctime(whowas->logoff));
}

static void
_whowas_send_record_cb(const struct Whowas *whowas, void *user_data)
{
  struct Client *const source = user_data;
  _whowas_send_record(source, whowas);
}

static void
_whowas_process_request(struct Client *source, const char *name, const char *limit_str)
{
  int reply_limit = -1;

  if (!string_is_empty(limit_str))
    reply_limit = atoi(limit_str);

  if (!client_is_local(source) && (reply_limit <= 0 || reply_limit > WHOWAS_MAX_REPLIES))
    reply_limit = WHOWAS_MAX_REPLIES;

  int records_found = whowas_query(name, reply_limit, _whowas_send_record_cb, source);
  if (records_found == 0)
    sendto_one_numeric(source, &me, ERR_WASNOSUCHNICK, name);

  sendto_one_numeric(source, &me, RPL_ENDOFWHOWAS, name);
}

/*! \brief WHOWAS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = count
 *      - parv[3] = nickname/servername
 */
static void
m_whowas(struct Client *source, int parc, char *parv[])
{
  if (string_is_empty(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  static uintmax_t last_used = 0;
  if ((last_used + ConfigGeneral.pace_wait) > io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    sendto_one_numeric(source, &me, RPL_LOAD2HI, "WHOWAS");
    return;
  }

  last_used = io_time_get(IO_TIME_MONOTONIC_SEC);

  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_route_command(source, ":%s WHOWAS %s %s :%s", 3, parv)->result != SERVER_ROUTE_ISME)
      return;

  _whowas_process_request(source, parv[1], parv[2]);
}

/*! \brief WHOWAS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = count
 *      - parv[3] = nickname/servername
 */
static void
ms_whowas(struct Client *source, int parc, char *parv[])
{
  if (string_is_empty(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  if (server_route_command(source, ":%s WHOWAS %s %s :%s", 3, parv)->result != SERVER_ROUTE_ISME)
    return;

  _whowas_process_request(source, parv[1], parv[2]);
}

static struct Command command_table =
{
  .name = "WHOWAS",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_whowas },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_whowas },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = ms_whowas }
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
