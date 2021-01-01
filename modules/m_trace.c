/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2021 ircd-hybrid development team
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

/*! \file m_trace.c
 * \brief Includes required functions for processing the TRACE command.
 * \version $Id$
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
#include "modules.h"
#include "conf.h"
#include "conf_class.h"
#include "patchlevel.h"


static void
trace_get_dependent(unsigned int *const server,
                    unsigned int *const client, const struct Client *target_p)
{
  dlink_node *node;

  (*server)++;
  (*client) += dlink_list_length(&target_p->serv->client_list);

  DLINK_FOREACH(node, target_p->serv->server_list.head)
    trace_get_dependent(server, client, node->data);
}

/* report_this_status()
 *
 * inputs       - pointer to client to report to
 *              - pointer to client to report about
 * output       - counter of number of hits
 * side effects - NONE
 */
static void
report_this_status(struct Client *source_p, const struct Client *target_p)
{
  const char *name;
  const char *class_name;

  name = client_get_name(target_p, HIDE_IP);
  class_name = get_client_class(&target_p->connection->confs);

  switch (target_p->status)
  {
    case STAT_CONNECTING:
      sendto_one_numeric(source_p, &me, RPL_TRACECONNECTING, class_name,
                         HasUMode(source_p, UMODE_ADMIN) ? name : target_p->name);
      break;
    case STAT_HANDSHAKE:
      sendto_one_numeric(source_p, &me, RPL_TRACEHANDSHAKE, class_name,
                         HasUMode(source_p, UMODE_ADMIN) ? name : target_p->name);
      break;
    case STAT_ME:
      break;
    case STAT_UNKNOWN:
      sendto_one_numeric(source_p, &me, RPL_TRACEUNKNOWN, class_name,
                         name, target_p->sockhost,
                         event_base->time.sec_monotonic - target_p->connection->created_monotonic);
      break;
    case STAT_CLIENT:
      if (HasUMode(target_p, UMODE_OPER))
        sendto_one_numeric(source_p, &me, RPL_TRACEOPERATOR, class_name, name,
                           target_p->sockhost,
                           event_base->time.sec_monotonic - target_p->connection->last_data,
                           client_get_idle_time(source_p, target_p));
      else
        sendto_one_numeric(source_p, &me, RPL_TRACEUSER, class_name, name,
                           target_p->sockhost,
                           event_base->time.sec_monotonic - target_p->connection->last_data,
                           client_get_idle_time(source_p, target_p));
      break;
    case STAT_SERVER:
    {
      unsigned int clients = 0;
      unsigned int servers = 0;

      trace_get_dependent(&servers, &clients, target_p);

      if (!HasUMode(source_p, UMODE_ADMIN))
        name = client_get_name(target_p, MASK_IP);

      sendto_one_numeric(source_p, &me, RPL_TRACESERVER, class_name, servers,
                         clients, name, *(target_p->serv->by) ?
                         target_p->serv->by : "*", "*",
                         me.name, event_base->time.sec_monotonic - target_p->connection->last_data);
      break;
    }

    default: /* ...we actually shouldn't come here... --msa */
      sendto_one_numeric(source_p, &me, RPL_TRACENEWTYPE, name);
      break;
  }
}

static void
do_trace(struct Client *source_p, const char *name)
{
  bool doall = false;
  const dlink_node *node;
  const dlink_list *tab[] = { &local_client_list,
                              &local_server_list, &unknown_list, NULL };

  assert(HasUMode(source_p, UMODE_OPER));

  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                       "TRACE requested by %s (%s@%s) [%s]",
                       source_p->name, source_p->username,
                       source_p->host, source_p->servptr->name);

  if (EmptyString(name))
    doall = true;
  else if (match(name, me.name) == 0)
    doall = true;
  else if (!MyClient(source_p) && strcmp(name, me.id) == 0)
    doall = true;

  for (const dlink_list **list = tab; *list; ++list)
  {
    DLINK_FOREACH(node, (*list)->head)
    {
      const struct Client *target_p = node->data;

      if (doall == true || match(name, target_p->name) == 0)
        report_this_status(source_p, target_p);
    }
  }

  if (doall == true)
  {
    DLINK_FOREACH(node, class_get_list()->head)
    {
      const struct ClassItem *class = node->data;

      if (class->ref_count)
        sendto_one_numeric(source_p, &me, RPL_TRACECLASS, class->name, class->ref_count);
    }
  }

  sendto_one_numeric(source_p, &me, RPL_TRACEEND, me.name);
}

/*! \brief TRACE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
m_trace(struct Client *source_p, int parc, char *parv[])
{
  sendto_one_numeric(source_p, &me, RPL_TRACEEND, me.name);
}

/*! \brief TRACE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
mo_trace(struct Client *source_p, int parc, char *parv[])
{
  if (parc > 2)
    if (server_hunt(source_p, ":%s TRACE %s :%s", 2, parv)->ret != HUNTED_ISME)
      return;

  const struct server_hunt *hunt = server_hunt(source_p, ":%s TRACE :%s", 1, parv);
  switch (hunt->ret)
  {
    case HUNTED_PASS:
      sendto_one_numeric(source_p, &me, RPL_TRACELINK,
                         PATCHLEVEL, hunt->target_p->name, hunt->target_p->from->name);
      break;
    case HUNTED_ISME:
      do_trace(source_p, parv[1]);
      break;
    default:
      break;
  }
}

static struct Message trace_msgtab =
{
  .cmd = "TRACE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_trace },
  .handlers[SERVER_HANDLER] = { .handler = mo_trace },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_trace }
};

static void
module_init(void)
{
  mod_add_cmd(&trace_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&trace_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
