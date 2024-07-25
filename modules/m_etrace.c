/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2004-2024 ircd-hybrid development team
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

/*! \file m_etrace.c
 * \brief Includes required functions for processing the ETRACE command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "server.h"
#include "send.h"
#include "parse.h"
#include "module.h"
#include "conf.h"


/* report_this_status()
 *
 * inputs       - pointer to client to report to
 *              - pointer to client to report about
 *              - flag full etrace or not
 * output       - NONE
 * side effects - NONE
 */
static void
trace_send_status(struct Client *source, const struct Client *target)
{
  if (target->status != STAT_CLIENT)
    return;

  sendto_one_numeric(source, &me, RPL_ETRACE,
                     HasUMode(target, UMODE_OPER) ? "Oper" : "User",
                     class_get_name(&target->connection->confs),
                     target->name, target->username, target->host, target->sockhost, target->info);
}

/*
 * do_etrace()
 */
static void
do_etrace(struct Client *source, const char *name)
{
  sendto_clients(UMODE_SPY, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "ETRACE requested by %s (%s@%s) [%s]",
                 source->name, source->username, source->host, source->servptr->name);

  bool doall = false;
  if (EmptyString(name))
    doall = true;
  else if (match(name, me.name) == 0)
    doall = true;
  else if (!MyClient(source) && strcmp(name, me.id) == 0)
    doall = true;

  list_node_t *node;
  LIST_FOREACH(node, local_client_list.head)
  {
    const struct Client *target = node->data;

    if (doall || match(name, target->name) == 0)
      trace_send_status(source, target);
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
mo_etrace(struct Client *source, int parc, char *parv[])
{
  if (parc > 2)
    if (server_route_command(source, ":%s ETRACE %s :%s", 2, parv)->result != SERVER_ROUTE_ISME)
      return;

  const server_route_t *route = server_route_command(source, ":%s ETRACE :%s", 1, parv);
  switch (route->result)
  {
    case SERVER_ROUTE_PASS:
      sendto_one_numeric(source, &me, RPL_TRACELINK,
                         IRCD_VERSION, route->target->name, route->target->from->name);
      break;
    case SERVER_ROUTE_ISME:
      do_etrace(source, parv[1]);
      break;
    default:
      break;
  }
}

static struct Command command_table =
{
  .name = "ETRACE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = mo_etrace },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_etrace }
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
