/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_connect.c
 * \brief Includes required functions for processing the CONNECT command.
 */

#include <assert.h>
#include <stddef.h>

#include "io_string.h"
#include "log.h"
#include "module.h"

#include "client.h"
#include "client_format.h"
#include "client_find.h"
#include "conf_connect.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"

static void
_connect_report_request(const struct Client *source, const struct ConnectItem *connect)
{
  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);
  const char *const request_origin = client_is_local(source) ? "Local" : "Remote";

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_GLOBAL,
                 "from %s: %s CONNECT %s %u from %s",
                 me.name, request_origin, connect->name, connect->port, source_name);
  sendto_servers(NULL, 0, 0, ":%s GLOBOPS :%s CONNECT %s %u from %s",
                 me.id, request_origin, connect->name, connect->port, source_name);

  log_write(LOG_TYPE_IRCD, "%s CONNECT %s %u from %s",
            request_origin, connect->name, connect->port, source_name);
}

static void
_connect_process_request(struct Client *source, const char *name)
{
  assert(client_is_user(source));

  /*
   * Try to find the name. If it fails, notify and bail.
   */
  struct ConnectItem *const connect = connect_find(name, true);
  if (connect == NULL)
  {
    sendto_one_notice(source, &me, ":Connect: Server %s not found in configuration.", name);
    return;
  }

  const struct Client *const target = client_find_entity_by_name(connect->name);
  if (target)
  {
    if (client_is_server(target) || client_is_me(target))
      sendto_one_notice(source, &me, ":Connect: Server %s is already connected (via %s).",
                        target->name, target->nexthop->name);
    else if (client_is_connecting(target) || client_is_handshake(target))
      sendto_one_notice(source, &me, ":Connect: Connection to %s is already in progress.",
                        connect->name);
    return;
  }

  _connect_report_request(source, connect);

  /*
   * At this point we should be calling connect_server with a valid
   * connect{} block and a valid port in the connect{} block.
   */
  if (!server_connect(connect, source))
    sendto_one_notice(source, &me, ":*** Couldn't connect to %s.%u",
                      connect->name, connect->port);
  else if (client_is_local(source) && client_is_admin(source))
    sendto_one_notice(source, &me, ":*** Connecting to %s[%s].%u",
                      connect->name, connect->host, connect->port);
  else
    sendto_one_notice(source, &me, ":*** Connecting to %s.%u",
                      connect->name, connect->port);

  /*
   * Client is either connecting with all the data it needs or has been
   * destroyed.
   */
}

/*! \brief CONNECT command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server
 *      - parv[2] = unused/ignored
 *      - parv[3] = nickname/servername
 */
static void
mo_connect(struct Client *source, int parc, char *parv[])
{
  if (!string_is_empty(parv[3]))
  {
    if (!client_has_oper_flag(source, OPER_FLAG_CONNECT_REMOTE))
    {
      sendto_one_numeric(source, &me, ERR_NOPRIVS, "connect:remote");
      return;
    }

    if (server_route_command(source, ":%s CONNECT %s %s :%s", 3, parv)->result != SERVER_ROUTE_ISME)
      return;
  }

  if (!client_has_oper_flag(source, OPER_FLAG_CONNECT))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "connect");
    return;
  }

  const char *const name = parv[1];
  _connect_process_request(source, name);
}

/*! \brief CONNECT command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server
 *      - parv[2] = unused/ignored
 *      - parv[3] = nickname/servername
 */
static void
ms_connect(struct Client *source, int parc, char *parv[])
{
  if (server_route_command(source, ":%s CONNECT %s %s :%s", 3, parv)->result != SERVER_ROUTE_ISME)
    return;

  const char *const name = parv[1];
  _connect_process_request(source, name);
}

static struct Command command_table =
{
  .name = "CONNECT",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_connect, .args_min = 4 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_connect, .args_min = 2 }
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
