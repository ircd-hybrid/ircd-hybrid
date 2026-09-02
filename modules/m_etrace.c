/*
 * SPDX-FileCopyrightText: 2004-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_etrace.c
 * \brief Includes required functions for processing the ETRACE command.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "module.h"

#include "client.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"

static void
_etrace_send_user_status(struct Client *source, const struct Client *target)
{
  if (!client_is_user(target))
    return;

  const char *const class_name = client_get_class_name(target);
  sendto_one_numeric(source, &me, RPL_ETRACE,
                     client_is_oper(target) ? "Oper" : "User", class_name,
                     target->name, target->username, target->host, target->sockhost, target->info);
}

static void
_etrace_process_request(struct Client *source, const char *name)
{
  hook_dispatch(ircd_hook_spy_request, &(ircd_hook_spy_request_ctx){
    .source = source,
    .command = "ETRACE"
  });

  bool doall = false;
  if (string_is_empty(name))
    doall = true;
  else if (match(name, me.name) == 0)
    doall = true;
  else if (!client_is_local(source) && strcmp(name, me.id) == 0)
    doall = true;

  list_node_t *node;
  LIST_FOREACH(node, local_client_list.head)
  {
    const struct Client *const target = node->data;
    if (doall || match(name, target->name) == 0)
      _etrace_send_user_status(source, target);
  }

  sendto_one_numeric(source, &me, RPL_ETRACEEND, me.name);
}

/*! \brief ETRACE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nick name to trace
 *      - parv[2] = nick or server name to forward the etrace to
 */
static void
mo_etrace(struct Client *source, size_t parc, char *parv[])
{
  if (parc > 2)
    if (server_route_command(source, ":%s ETRACE %s :%s", 2, parv)->result != SERVER_ROUTE_ISME)
      return;

  const server_route_t *route = server_route_command(source, ":%s ETRACE :%s", 1, parv);
  switch (route->result)
  {
    case SERVER_ROUTE_PASS:
      sendto_one_numeric(source, &me, RPL_TRACELINK,
                         IRCD_VERSION, route->target->name, route->target->nexthop->name);
      break;
    case SERVER_ROUTE_ISME:
      _etrace_process_request(source, parv[1]);
      break;
    default:
      break;
  }
}

static struct Command command_table =
{
  .name = "ETRACE",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = mo_etrace },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_etrace }
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
