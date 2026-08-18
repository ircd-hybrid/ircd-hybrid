/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_kline.c
 * \brief Includes required functions for processing the KLINE command.
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
#include "misc.h"
#include "memory.h"
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
kline_check(const struct AddressRec *arec)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, local_client_list.head)
  {
    struct Client *const client = node->data;
    if (client_is_dead(client))
      continue;

    if (match(arec->username, client->username))
      continue;

    switch (arec->masktype)
    {
      case HM_HOST:
        if (match(arec->Mask.hostname, client->realhost) == 0 ||
            match(arec->Mask.hostname, client->sockhost) == 0 || match(arec->Mask.hostname, client->host) == 0)
          conf_ban_apply(client, CONF_BAN_TYPE_KLINE, arec->conf->reason);
        break;
      case HM_IPV6:
      case HM_IPV4:
        if (address_match(&client->addr, &arec->Mask.ipa.addr, false, false, arec->Mask.ipa.bits))
          conf_ban_apply(client, CONF_BAN_TYPE_KLINE, arec->conf->reason);
        break;
      default:
        assert(0);
    }
  }
}

static void
_kline_report_added(struct Client *source, const struct MaskItem *conf, uintmax_t duration_minutes)
{
  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  if (duration_minutes)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Temporary K-line added by %s for [%s@%s] (%ju min) [%s]",
                   source_name, conf->user, conf->host, duration_minutes, conf->reason);
    log_write(LOG_TYPE_KLINE,
              "Temporary K-line added by %s for [%s@%s] (%ju min) [%s]",
              source_name, conf->user, conf->host, duration_minutes, conf->reason);
    return;
  }

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "K-line added by %s for [%s@%s] [%s]",
                 source_name, conf->user, conf->host, conf->reason);
  log_write(LOG_TYPE_KLINE, "K-line added by %s for [%s@%s] [%s]",
            source_name, conf->user, conf->host, conf->reason);
}

static void
kline_handle(struct Client *source, const struct aline_ctx *aline)
{
  if (!client_is_service(source) && !aline_valid_mask(2, aline->user, aline->host))
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me,
                        ":Please include at least %u non-wildcard characters with the mask",
                        ConfigGeneral.min_nonwildcard);
    return;
  }

  struct io_addr parsed_addr;
  int cidr_bits = 0;
  unsigned int minimum_cidr_bits = 0;
  struct io_addr *parsed_addr_ptr = NULL;
  switch (address_parse_netmask(aline->host, &parsed_addr, &cidr_bits))
  {
    case HM_IPV4:
      minimum_cidr_bits = ConfigGeneral.kline_min_cidr;
      parsed_addr_ptr = &parsed_addr;
      break;
    case HM_IPV6:
      minimum_cidr_bits = ConfigGeneral.kline_min_cidr6;
      parsed_addr_ptr = &parsed_addr;
      break;
    default:  /* HM_HOST */
      break;
  }

  if (minimum_cidr_bits > 0 && !client_is_service(source) && (unsigned int)cidr_bits < minimum_cidr_bits)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":For safety, bitmasks less than %u require conf access.",
                        minimum_cidr_bits);
    return;
  }

  struct MaskItem *conf;
  if ((conf = find_conf_by_address(aline->host, parsed_addr_ptr, CONF_KLINE, aline->user, NULL, 0)))
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":[%s@%s] already K-Lined by [%s@%s] - %s",
                        aline->user, aline->host, conf->user, conf->host, conf->reason);
    return;
  }

  char reason[IRCD_BUFSIZE];
  if (aline->duration)
    snprintf(reason, sizeof(reason), "Temporary K-line %ju min. - %.*s (%s)",
             aline->duration / 60, REASONLEN, aline->reason, date_iso8601(0));
  else
    snprintf(reason, sizeof(reason), "%.*s (%s)", REASONLEN, aline->reason, date_iso8601(0));

  conf = conf_make(CONF_KLINE);
  conf->user = io_strdup(aline->user);
  conf->host = io_strdup(aline->host);
  conf->setat = io_time_get(IO_TIME_REALTIME_SEC);
  conf->reason = io_strdup(reason);
  SetConfDatabase(conf);

  if (aline->duration)
  {
    conf->until = conf->setat + aline->duration;
    const uintmax_t duration_minutes = aline->duration / 60;

    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Added temporary %ju min. K-Line [%s@%s]",
                        duration_minutes, conf->user, conf->host);

    _kline_report_added(source, conf, duration_minutes);
  }
  else
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Added K-Line [%s@%s]",
                        conf->user, conf->host);

    _kline_report_added(source, conf, 0);
  }

  kline_check(add_conf_by_address(CONF_KLINE, conf));
}

static void
mo_kline(struct Client *source, int parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_KLINE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "kline");
    return;
  }

  struct aline_ctx aline = { .add = true, .simple_mask = false };
  if (!aline_parse("KLINE", source, parc, parv, &aline))
    return;

  if (aline.server)
  {
    sendto_match_servs(source, aline.server, CAPAB_KLN, "KLINE %s %ju %s %s :%s",
                       aline.server, aline.duration, aline.user, aline.host, aline.reason);

    /* Allow ON to apply local kline as well if it matches */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source, "KLINE", CAPAB_KLN, CLUSTER_KLINE, "%ju %s %s :%s",
                       aline.duration, aline.user, aline.host, aline.reason);

  kline_handle(source, &aline);
}

/*! \brief KLINE command handler
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
 *      - parv[3] = user mask
 *      - parv[4] = host mask
 *      - parv[5] = reason
 */
static void
ms_kline(struct Client *source, int parc, char *parv[])
{
  uintmax_t duration;
  if (io_parse_uintmax(parv[2], &duration) != IO_PARSE_OK)
    return;

  struct aline_ctx aline =
  {
    .add = true,
    .simple_mask = false,
    .user = parv[3],
    .host = parv[4],
    .reason = parv[5],
    .server = parv[1],
    .duration = duration
  };

  sendto_match_servs(source, aline.server, CAPAB_KLN, "KLINE %s %ju %s %s :%s",
                     aline.server, aline.duration, aline.user, aline.host, aline.reason);

  if (match(aline.server, me.name))
    return;

  if (client_is_service(source) ||
      shared_find(SHARED_KLINE, source->uplink->name, source->username, source->host))
    kline_handle(source, &aline);
}

static struct Command command_table =
{
  .name = "KLINE",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_kline, .args_min = 6 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_kline, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
  capab_add("KLN", CAPAB_KLN, true);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  capab_del("KLN");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
