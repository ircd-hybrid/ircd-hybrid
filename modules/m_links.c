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

/*! \file m_links.c
 * \brief Includes required functions for processing the LINKS command.
 */

#include <stddef.h>
#include <stdint.h>

#include "io_string.h"
#include "io_time.h"
#include "misc.h"
#include "module.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "links_cache.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "user_mode.h"

static void
_links_send_flat(struct Client *client)
{
  /* Print our own info first to mimic a standard /LINKS reply. */
  sendto_one_numeric(client, &me, RPL_LINKS, me.name, me.name, 0, me.info);

  const list_t *const cache = links_cache_get();
  list_node_t *node;
  LIST_FOREACH(node, cache->head)
  {
    const links_cache_entry_t *const entry = node->data;
    sendto_one_numeric(client, &me, RPL_LINKS,
                       entry->name, entry->uplink_name, 1, entry->description);
  }

  sendto_one_numeric(client, &me, RPL_ENDOFLINKS, "*");
}

static void
_links_send_live(struct Client *client, const char *mask)
{
  list_node_t *node;
  LIST_FOREACH(node, global_server_list.head)
  {
    const struct Client *const server = node->data;
    if (!client_is_oper(client))
    {
      if (client_is_hidden(server))
        continue;
      if (client_is_service(server) && ConfigServerHide.hide_services)
        continue;
    }

    if (!string_is_empty(mask) && match(mask, server->name))
      continue;

    sendto_one_numeric(client, &me, RPL_LINKS,
                       server->name, server->uplink->name, server->hopcount, server->info);
  }

  sendto_one_numeric(client, &me, RPL_ENDOFLINKS, string_default(mask, "*"));
}

/*! \brief Shows a list of linked servers and notifies irc-operators
 *         about the LINKS request
 *
 * \param source Pointer to client to report to
 */
static void
do_links(struct Client *source, char *parv[])
{
  sendto_clients(UMODE_SPY, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "LINKS requested by %s (%s@%s) [%s]",
                 source->name, source->username, source->host, source->uplink->name);

  if (ConfigServerHide.flatten_links && !client_is_oper(source))
  {
    _links_send_flat(source);
    return;
  }

  const char *mask = string_default(parv[2], parv[1]);
  _links_send_live(source, mask);
}

static void
mo_links(struct Client *source, int parc, char *parv[])
{
  do_links(source, parv);
}

/*! \brief LINKS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = servername mask
 * or
 *      - parv[0] = command
 *      - parv[1] = server to query
 *      - parv[2] = servername mask
 */
static void
m_links(struct Client *source, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait) > io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    sendto_one_numeric(source, &me, RPL_LOAD2HI, "LINKS");
    return;
  }

  last_used = io_time_get(IO_TIME_MONOTONIC_SEC);

  do_links(source, parv);
}

static struct Command command_table =
{
  .name = "LINKS",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_links },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_links }
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
