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

/*! \file m_unxline.c
 * \brief Includes required functions for processing the UNXLINE command.
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
#include "conf_gecos.h"
#include "conf_shared.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"

static void
_unxline_report_removed(struct Client *source, const struct GecosItem *gecos)
{
  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "X-line removed by %s for [%s]",
                 source_name, gecos->mask);
  log_write(LOG_TYPE_XLINE, "X-line removed by %s for [%s]",
            source_name, gecos->mask);
}

static void
_unxline_remove(struct Client *source, const struct aline_ctx *aline)
{
  struct GecosItem *const gecos = gecos_find(aline->mask, io_strcasecmp);
  if (gecos == NULL)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":No X-line for [%s] found",
                        aline->mask);
    return;
  }

  if (gecos->in_database == false)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me,
                        ":X-line for [%s] is in the configuration file and must be removed by hand",
                        gecos->mask);
    return;
  }

  if (client_is_user(source))
    sendto_one_notice(source, &me, ":Removed X-line [%s]",
                      gecos->mask);

  _unxline_report_removed(source, gecos);

  gecos_delete(gecos, false);
}

/*! \brief UNXLINE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = gecos
 *      - parv[2] = "ON"
 *      - parv[3] = target server
 */
static void
mo_unxline(struct Client *source, int parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_UNXLINE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "unxline");
    return;
  }

  struct aline_ctx aline = { .add = false, .simple_mask = true };
  if (!aline_parse("UNXLINE", source, parc, parv, &aline))
    return;

  if (aline.server)
  {
    sendto_match_servs(source, aline.server, CAPAB_CLUSTER, "UNXLINE %s %s",
                       aline.server, aline.mask);

    /* Allow ON to apply local unxline as well if it matches */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source, "UNXLINE", CAPAB_CLUSTER, CLUSTER_UNXLINE, "%s",
                       aline.mask);

  _unxline_remove(source, &aline);
}

/*! \brief UNXLINE command handler
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
 */
static void
ms_unxline(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline =
  {
    .add = false,
    .simple_mask = true,
    .mask = parv[2],
    .server = parv[1]
  };

  sendto_match_servs(source, aline.server, CAPAB_CLUSTER, "UNXLINE %s %s",
                     aline.server, aline.mask);

  if (match(aline.server, me.name))
    return;

  if (client_is_service(source) ||
      shared_find(SHARED_UNXLINE, source->uplink->name, source->username, source->host))
    _unxline_remove(source, &aline);
}

static struct Command command_table =
{
  .name = "UNXLINE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_unxline, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_unxline, .args_min = 2 }
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
