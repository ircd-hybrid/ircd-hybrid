/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_undline.c
 * \brief Includes required functions for processing the UNDLINE command.
 */

#include <stdbool.h>
#include <stddef.h>

#include "address.h"
#include "io_string.h"
#include "log.h"
#include "module.h"

#include "aline.h"
#include "client.h"
#include "client_format.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_shared.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"

static void
_undline_report_removed(struct Client *source, const struct MaskItem *conf)
{
  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "D-line removed by %s for [%s]",
                 source_name, conf->host);
  log_write(LOG_TYPE_DLINE, "D-line removed by %s for [%s]",
            source_name, conf->host);
}

static void
_undline_remove(struct Client *source, const struct aline_ctx *aline)
{
  struct io_addr parsed_addr;
  struct io_addr *parsed_addr_ptr = NULL;

  if (address_parse_netmask(aline->host, &parsed_addr, NULL) != HM_HOST)
    parsed_addr_ptr = &parsed_addr;

  struct MaskItem *const conf =
    find_conf_by_address(NULL, parsed_addr_ptr, CONF_DLINE, NULL, NULL, 0);
  if (conf == NULL)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":No D-line for [%s] found",
                        aline->host);
    return;
  }

  if (!IsConfDatabase(conf))
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me,
                        ":D-line for [%s] is in the configuration file and must be removed by hand",
                        conf->host);
    return;
  }

  if (client_is_user(source))
    sendto_one_notice(source, &me, ":Removed D-line [%s]",
                      conf->host);

  _undline_report_removed(source, conf);

  delete_one_address_conf(aline->host, conf);
}

/*! \brief UNDLINE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = IP address
 *      - parv[2] = "ON"
 *      - parv[3] = target server
 */
static void
mo_undline(struct Client *source, int parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_UNDLINE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "undline");
    return;
  }

  struct aline_ctx aline = { .add = false, .simple_mask = false };
  if (!aline_parse("UNDLINE", source, parc, parv, &aline))
    return;

  if (aline.server)
  {
    sendto_match_servs(source, aline.server, CAPAB_UNDLN, "UNDLINE %s %s",
                       aline.server, aline.host);

    /* Allow ON to apply local undline as well if it matches */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source, "UNDLINE", CAPAB_UNDLN, CLUSTER_UNDLINE, "%s",
                       aline.host);

  _undline_remove(source, &aline);
}

/*! \brief UNDLINE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server mask
 *      - parv[2] = IP address
 */
static void
ms_undline(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline =
  {
    .add = false,
    .simple_mask = false,
    .host = parv[2],
    .server = parv[1]
  };

  sendto_match_servs(source, aline.server, CAPAB_UNDLN, "UNDLINE %s %s",
                     aline.server, aline.host);

  if (match(aline.server, me.name))
    return;

  if (client_is_service(source) ||
      shared_find(SHARED_UNDLINE, source->uplink->name, source->username, source->host))
    _undline_remove(source, &aline);
}

static struct Command command_table =
{
  .name = "UNDLINE",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_undline, .args_min = 3 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_undline, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
  capab_add("UNDLN", CAPAB_UNDLN, true);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  capab_del("UNDLN");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
