/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2003-2026 ircd-hybrid development team
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

/*! \file m_xline.c
 * \brief Includes required functions for processing the XLINE command.
 */

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "misc.h"
#include "module.h"

#include "aline.h"
#include "client.h"
#include "client_format.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_gecos.h"
#include "conf_shared.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"

static void
xline_check(const struct GecosItem *gecos)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, local_client_list.head)
  {
    struct Client *const client = node->data;
    if (client_is_dead(client))
      continue;

    if (match(gecos->mask, client->info) == 0)
      conf_ban_apply(client, CONF_BAN_TYPE_XLINE, gecos->reason);
  }
}

static void
_xline_report_added(struct Client *source, const struct GecosItem *gecos, uintmax_t duration_minutes)
{
  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  if (duration_minutes)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Temporary X-line added by %s for [%s] (%ju min) [%s]",
                   source_name, gecos->mask, duration_minutes, gecos->reason);
    log_write(LOG_TYPE_XLINE,
              "Temporary X-line added by %s for [%s] (%ju min) [%s]",
              source_name, gecos->mask, duration_minutes, gecos->reason);
    return;
  }

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "X-line added by %s for [%s] [%s]",
                 source_name, gecos->mask, gecos->reason);
  log_write(LOG_TYPE_XLINE, "X-line added by %s for [%s] [%s]",
            source_name, gecos->mask, gecos->reason);
}

static void
xline_handle(struct Client *source, const struct aline_ctx *aline)
{
  if (!client_is_service(source) && !aline_valid_mask_simple(aline->mask))
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me,
                        ":Please include at least %u non-wildcard characters with the X-line",
                        ConfigGeneral.min_nonwildcard_simple);
    return;
  }

  struct GecosItem *gecos = gecos_find(aline->mask, match);
  if (gecos)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":[%s] already X-lined by [%s] - %s",
                        aline->mask, gecos->mask, gecos->reason);
    return;
  }

  char reason[IRCD_BUFSIZE];
  if (aline->duration)
    snprintf(reason, sizeof(reason), "Temporary X-line %ju min. - %.*s (%s)",
             aline->duration / 60, REASONLEN, aline->reason, date_iso8601(0));
  else
    snprintf(reason, sizeof(reason), "%.*s (%s)",
             REASONLEN, aline->reason, date_iso8601(0));

  gecos = gecos_make();
  gecos->mask = io_strdup(aline->mask);
  gecos->reason = io_strdup(reason);
  gecos->created_at = io_time_get(IO_TIME_REALTIME_SEC);
  gecos->in_database = true;

  if (aline->duration)
  {
    gecos->expires_at = gecos->created_at + aline->duration;
    const uintmax_t duration_minutes = aline->duration / 60;

    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Added temporary X-line [%s] (%ju min)",
                        gecos->mask, duration_minutes);

    _xline_report_added(source, gecos, duration_minutes);
  }
  else
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Added X-line [%s]",
                        gecos->mask);

    _xline_report_added(source, gecos, 0);
  }

  xline_check(gecos);
}

static void
mo_xline(struct Client *source, int parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_XLINE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "xline");
    return;
  }

  struct aline_ctx aline = { .add = true, .simple_mask = true };
  if (!aline_parse("XLINE", source, parc, parv, &aline))
    return;

  if (aline.server)
  {
    sendto_match_servs(source, aline.server, CAPAB_CLUSTER, "XLINE %s %s %ju :%s",
                       aline.server, aline.mask, aline.duration, aline.reason);

    /* Allow ON to apply local xline as well if it matches */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source, "XLINE", CAPAB_CLUSTER, CLUSTER_XLINE, "%s %ju :%s",
                       aline.mask, aline.duration, aline.reason);

  xline_handle(source, &aline);
}

/*! \brief XLINE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server mask
 *      - parv[2] = gecos
 *      - parv[3] = duration in seconds
 *      - parv[4] = reason
 */
static void
ms_xline(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline =
  {
    .add = true,
    .simple_mask = true,
    .mask = parv[2],
    .reason = parv[4],
    .server = parv[1],
    .duration = strtoumax(parv[3], NULL, 10)
  };

  sendto_match_servs(source, aline.server, CAPAB_CLUSTER, "XLINE %s %s %ju :%s",
                     aline.server, aline.mask, aline.duration, aline.reason);

  if (match(aline.server, me.name))
    return;

  if (client_is_service(source) ||
      shared_find(SHARED_XLINE, source->uplink->name, source->username, source->host))
    xline_handle(source, &aline);
}

static struct Command command_table =
{
  .name = "XLINE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_xline, .args_min = 5 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_xline, .args_min = 2 }
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
