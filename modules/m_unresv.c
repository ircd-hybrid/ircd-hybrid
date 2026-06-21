/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2026 ircd-hybrid development team
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

/*! \file m_unresv.c
 * \brief Includes required functions for processing the UNRESV command.
 */

#include <stdbool.h>
#include <stddef.h>

#include "io_string.h"
#include "log.h"
#include "module.h"

#include "aline.h"
#include "client.h"
#include "client_format.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_resv.h"
#include "conf_shared.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"

static void
_unresv_report_removed(struct Client *source, const struct ResvItem *resv)
{
  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "RESV removed by %s for [%s]",
                 source_name, resv->mask);
  log_write(LOG_TYPE_RESV, "RESV removed by %s for [%s]",
            source_name, resv->mask);
}

static void
_unresv_remove(struct Client *source, const struct aline_ctx *aline)
{
  struct ResvItem *const resv = resv_find(aline->mask, io_strcasecmp);
  if (resv == NULL)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":No RESV for [%s] found",
                        aline->mask);
    return;
  }

  if (resv->in_database == false)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me,
                        ":RESV for [%s] is in the configuration file and must be removed by hand",
                        resv->mask);
    return;
  }

  if (client_is_user(source))
    sendto_one_notice(source, &me, ":Removed RESV [%s]",
                      resv->mask);

  _unresv_report_removed(source, resv);

  resv_delete(resv, false);
}

/*! \brief UNRESV command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel/nick
 *      - parv[2] = "ON"
 *      - parv[3] = target server
 */
static void
mo_unresv(struct Client *source, int parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_UNRESV))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "unresv");
    return;
  }

  struct aline_ctx aline = { .add = false, .simple_mask = true };
  if (!aline_parse("UNRESV", source, parc, parv, &aline))
    return;

  if (aline.server)
  {
    sendto_match_servs(source, aline.server, CAPAB_CLUSTER, "UNRESV %s %s",
                       aline.server, aline.mask);

    /* Allow ON to apply local unresv as well if it matches */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source, "UNRESV", CAPAB_KLN, CLUSTER_UNRESV, "%s",
                       aline.mask);

  _unresv_remove(source, &aline);
}

/*! \brief UNRESV command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server mask
 *      - parv[2] = name mask
 */
static void
ms_unresv(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline =
  {
    .add = false,
    .simple_mask = true,
    .mask = parv[2],
    .server = parv[1]
  };

  sendto_match_servs(source, aline.server, CAPAB_CLUSTER, "UNRESV %s %s",
                     aline.server, aline.mask);

  if (match(aline.server, me.name))
    return;

  if (client_is_service(source) ||
      shared_find(SHARED_UNRESV, source->uplink->name, source->username, source->host))
    _unresv_remove(source, &aline);
}

static struct Command command_table =
{
  .name = "UNRESV",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = m_unregistered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_unresv, .args_min = 3 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = m_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_unresv, .args_min = 2 }
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
