/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_trace.c
 * \brief Includes required functions for processing the TRACE command.
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
#include "client_format.h"
#include "conf_class.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"

static void
_trace_count_server_dependents(const struct Client *target,
                               uint32_t *const server_count, uint32_t *const user_count)
{
  (*server_count)++;
  (*user_count) += list_length(&target->server->child_user_list);

  list_node_t *node;
  LIST_FOREACH(node, target->server->child_server_list.head)
    _trace_count_server_dependents(node->data, server_count, user_count);
}

static void
_trace_send_target_status(struct Client *source, const struct Client *target)
{
  const char *const class_name = client_get_class_name(target);

  client_format_name_buffer_t target_name_buffer;
  const char *const target_name =
    client_format_name(target, CLIENT_FORMAT_NAME_PUBLIC, &target_name_buffer);

  switch (target->state)
  {
    case CLIENT_STATE_CONNECTING:
      sendto_one_numeric(source, &me, RPL_TRACECONNECTING,
                         class_name, client_is_admin(source) ? target_name : target->name);
      break;
    case CLIENT_STATE_HANDSHAKE:
      sendto_one_numeric(source, &me, RPL_TRACEHANDSHAKE,
                         class_name, client_is_admin(source) ? target_name : target->name);
      break;
    case CLIENT_STATE_ME:
      /* `&me` is not reported as a regular TRACE target here. */
      break;
    case CLIENT_STATE_UNKNOWN:
      sendto_one_numeric(source, &me, RPL_TRACEUNKNOWN,
                         class_name, target_name, target->sockhost, client_get_session_duration(target));
      break;
    case CLIENT_STATE_USER:
      if (client_is_oper(target))
        sendto_one_numeric(source, &me, RPL_TRACEOPERATOR,
                           class_name, target_name, target->sockhost, client_get_socket_idle_duration(target),
                           client_get_idle_time(source, target));
      else
        sendto_one_numeric(source, &me, RPL_TRACEUSER,
                           class_name, target_name, target->sockhost, client_get_socket_idle_duration(target),
                           client_get_idle_time(source, target));
      break;
    case CLIENT_STATE_SERVER:
    {
      uint32_t server_count = 0;
      uint32_t user_count = 0;
      _trace_count_server_dependents(target, &server_count, &user_count);

      client_format_name_buffer_t masked_target_name_buffer;
      const char *const visible_target_name =
        client_is_admin(source) ?
          target_name : client_format_name(target, CLIENT_FORMAT_NAME_OPER, &masked_target_name_buffer);

      sendto_one_numeric(source, &me, RPL_TRACESERVER,
                         class_name, server_count, user_count, visible_target_name,
                         target->server->initiator_name ? target->server->initiator_name : "*", "*",
                         me.name, client_get_socket_idle_duration(target));
      break;
    }

    default:
      assert(!"unexpected client state in TRACE");
      sendto_one_numeric(source, &me, RPL_TRACENEWTYPE, target_name);
      break;
  }
}

static void
_trace_process_request(struct Client *source, const char *name)
{
  assert(client_is_oper(source));

  hook_dispatch(ircd_hook_spy_request, &(ircd_hook_spy_request_ctx){
    .source = source,
    .command = "TRACE"
  });

  bool doall = false;
  if (string_is_empty(name))
    doall = true;
  else if (match(name, me.name) == 0)
    doall = true;
  else if (!client_is_local(source) && strcmp(name, me.id) == 0)
    doall = true;

  const list_node_t *node;
  const list_t *tab[] = { &local_client_list,
                          &local_server_list, &unknown_list, NULL };
  for (const list_t **list = tab; *list; ++list)
  {
    LIST_FOREACH(node, (*list)->head)
    {
      const struct Client *const target = node->data;
      if (doall || match(name, target->name) == 0)
        _trace_send_target_status(source, target);
    }
  }

  if (doall)
  {
    LIST_FOREACH(node, class_get_list()->head)
    {
      const struct ClassItem *const klass = node->data;
      if (klass->ref_count)
        sendto_one_numeric(source, &me, RPL_TRACECLASS, klass->name, klass->ref_count);
    }
  }

  sendto_one_numeric(source, &me, RPL_TRACEEND, me.name);
}

/*! \brief TRACE command handler
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
m_trace(struct Client *source, size_t parc, char *parv[])
{
  sendto_one_numeric(source, &me, RPL_TRACEEND, me.name);
}

/*! \brief TRACE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nick or server name to trace
 *      - parv[2] = nick or server name to forward the trace to
 */
static void
mo_trace(struct Client *source, size_t parc, char *parv[])
{
  if (parc > 2)
    if (server_route_command(source, ":%s TRACE %s :%s", 2, parv)->result != SERVER_ROUTE_ISME)
      return;

  const server_route_t *route = server_route_command(source, ":%s TRACE :%s", 1, parv);
  switch (route->result)
  {
    case SERVER_ROUTE_PASS:
      sendto_one_numeric(source, &me, RPL_TRACELINK,
                         IRCD_VERSION, route->target->name, route->target->nexthop->name);
      break;
    case SERVER_ROUTE_ISME:
      _trace_process_request(source, parv[1]);
      break;
    default:
      break;
  }
}

static struct Command command_table =
{
  .name = "TRACE",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_trace },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = mo_trace },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_trace }
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
