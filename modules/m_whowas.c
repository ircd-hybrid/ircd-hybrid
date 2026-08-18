/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_whowas.c
 * \brief Includes required functions for processing the WHOWAS command.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "io_parse.h"
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

static unsigned int
_whowas_parse_max_results(const char *text)
{
  if (string_is_empty(text))
    return 0;

  const bool negative = *text == '-';
  const char *const magnitude = negative ? text + 1 : text;

  unsigned int value;
  const io_parse_status_t status = io_parse_uint(magnitude, &value);

  if (status == IO_PARSE_RANGE)
    return negative ? 0 : UINT_MAX;

  if (status != IO_PARSE_OK || negative)
    return 0;

  return value;
}

static void
_whowas_process_request(struct Client *source, const char *name, const char *limit_str)
{
  unsigned int max_results = _whowas_parse_max_results(limit_str);
  if (!client_is_local(source) &&
      (max_results == 0 || max_results > WHOWAS_MAX_REPLIES))
    max_results = WHOWAS_MAX_REPLIES;

  const unsigned int records_found =
    whowas_query(name, max_results, _whowas_send_record_cb, source);
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
