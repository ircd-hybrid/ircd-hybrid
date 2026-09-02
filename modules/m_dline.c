/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_dline.c
 * \brief Includes required functions for processing the DLINE command.
 */

#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "address.h"
#include "io_parse.h"
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
#include "conf_oper.h"
#include "conf_shared.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"

static void
dline_check(const struct AddressRec *arec)
{
  list_t *tab[] = { &local_client_list, &unknown_list, NULL };

  for (list_t **list = tab; *list; ++list)
  {
    list_node_t *node, *node_next;
    LIST_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      struct Client *const client = node->data;
      if (client_is_dead(client))
        continue;

      switch (arec->masktype)
      {
        case HM_IPV6:
        case HM_IPV4:
          if (address_match(&client->addr, &arec->Mask.ipa.addr, false, false, arec->Mask.ipa.bits))
            conf_ban_apply(client, CONF_BAN_TYPE_DLINE, arec->conf->reason);
          break;
        default:
          assert(0);
      }
    }
  }
}

static void
_dline_report_added(struct Client *source, const struct MaskItem *conf, uintmax_t duration_minutes)
{
  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  if (duration_minutes)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Temporary D-line added by %s for [%s] (%ju min) [%s]",
                   source_name, conf->host, duration_minutes, conf->reason);
    log_write(LOG_TYPE_DLINE,
              "Temporary D-line added by %s for [%s] (%ju min) [%s]",
              source_name, conf->host, duration_minutes, conf->reason);
    return;
  }

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "D-line added by %s for [%s] [%s]",
                 source_name, conf->host, conf->reason);
  log_write(LOG_TYPE_DLINE, "D-line added by %s for [%s] [%s]",
            source_name, conf->host, conf->reason);
}

static void
dline_handle(struct Client *source, const struct aline_ctx *aline)
{
  struct io_addr parsed_addr;
  int cidr_bits = 0;
  unsigned int minimum_cidr_bits = 0;

  switch (address_parse_netmask(aline->host, &parsed_addr, &cidr_bits))
  {
    case HM_IPV4:
      minimum_cidr_bits = ConfigGeneral.dline_min_cidr;
      break;

    case HM_IPV6:
      minimum_cidr_bits = ConfigGeneral.dline_min_cidr6;
      break;

    default:
      if (client_is_user(source))
        sendto_one_notice(source, &me, ":Invalid D-line");
      return;
  }

  if (minimum_cidr_bits > 0 && !client_is_service(source) && (unsigned int)cidr_bits < minimum_cidr_bits)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me,
                        ":For safety, bitmasks less than %u require conf access.",
                        minimum_cidr_bits);
    return;
  }

  struct MaskItem *conf = find_conf_by_address(NULL, &parsed_addr, CONF_DLINE, NULL, NULL, 1);
  if (conf)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":[%s] already D-lined by [%s] - %s",
                        aline->host, conf->host, conf->reason);
    return;
  }

  char reason[IRCD_BUFSIZE];
  if (aline->duration)
    snprintf(reason, sizeof(reason), "Temporary D-line %ju min. - %.*s (%s)",
             aline->duration / 60, REASONLEN, aline->reason, date_iso8601(0));
  else
    snprintf(reason, sizeof(reason), "%.*s (%s)",
             REASONLEN, aline->reason, date_iso8601(0));

  conf = conf_make(CONF_DLINE);
  conf->host = io_strdup(aline->host);
  conf->reason = io_strdup(reason);
  conf->setat = io_time_get(IO_TIME_REALTIME_SEC);
  SetConfDatabase(conf);

  if (aline->duration)
  {
    conf->until = conf->setat + aline->duration;
    const uintmax_t duration_minutes = aline->duration / 60;

    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Added temporary D-line [%s] (%ju min)",
                        conf->host, duration_minutes);

    _dline_report_added(source, conf, duration_minutes);
  }
  else
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Added D-line [%s]",
                        conf->host);

    _dline_report_added(source, conf, 0);
  }

  dline_check(add_conf_by_address(CONF_DLINE, conf));
}

static void
mo_dline(struct Client *source, size_t parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_DLINE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "dline");
    return;
  }

  struct aline_ctx aline = { .add = true, .simple_mask = false };
  if (!aline_parse("DLINE", source, parc, parv, &aline))
    return;

  if (aline.server)
  {
    sendto_match_servs(source, aline.server, CAPAB_DLN, "DLINE %s %ju %s :%s",
                       aline.server, aline.duration, aline.host, aline.reason);

    /* Allow ON to apply local dline as well if it matches */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source, "DLINE", CAPAB_DLN, CLUSTER_DLINE, "%ju %s :%s",
                       aline.duration, aline.host, aline.reason);

  dline_handle(source, &aline);
}

/*! \brief DLINE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server mask
 *      - parv[2] = duration in seconds
 *      - parv[3] = IP address
 *      - parv[4] = reason
 */
static void
ms_dline(struct Client *source, size_t parc, char *parv[])
{
  uintmax_t duration;
  if (io_parse_uintmax(parv[2], &duration) != IO_PARSE_OK)
    return;

  struct aline_ctx aline =
  {
    .add = true,
    .simple_mask = false,
    .host = parv[3],
    .reason = parv[4],
    .server = parv[1],
    .duration = duration
  };

  sendto_match_servs(source, aline.server, CAPAB_DLN, "DLINE %s %ju %s :%s",
                     aline.server, aline.duration, aline.host, aline.reason);

  if (match(aline.server, me.name))
    return;

  if (client_is_service(source) ||
      shared_find(SHARED_DLINE, source->uplink->name, source->username, source->host))
    dline_handle(source, &aline);
}

static struct Command command_table =
{
  .name = "DLINE",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_dline, .args_min = 5 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_dline, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
  capab_add("DLN", CAPAB_DLN, true);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  capab_del("DLN");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
