/*
 * SPDX-FileCopyrightText: 2001-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_resv.c
 * \brief Includes required functions for processing the RESV command.
 */

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "io_parse.h"
#include "io_string.h"
#include "io_time.h"
#include "log.h"
#include "module.h"

#include "aline.h"
#include "channel.h"
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
_resv_report_added(struct Client *source, const struct ResvItem *resv, uintmax_t duration_minutes)
{
  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  if (duration_minutes)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Temporary RESV added by %s for [%s] (%ju min) [%s]",
                   source_name, resv->mask, duration_minutes, resv->reason);
    log_write(LOG_TYPE_RESV,
              "Temporary RESV added by %s for [%s] (%ju min) [%s]",
              source_name, resv->mask, duration_minutes, resv->reason);
    return;
  }

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "RESV added by %s for [%s] [%s]",
                 source_name, resv->mask, resv->reason);
  log_write(LOG_TYPE_RESV, "RESV added by %s for [%s] [%s]",
            source_name, resv->mask, resv->reason);
}

static void
resv_handle(struct Client *source, const struct aline_ctx *aline)
{
  if (!client_is_service(source) && !aline_valid_mask_simple(aline->mask + channel_is_valid_prefix_char(*aline->mask)))
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me,
                        ":Please include at least %u non-wildcard characters with the RESV",
                        ConfigGeneral.min_nonwildcard_simple);
    return;
  }

  struct ResvItem *resv = resv_find(aline->mask, io_strcasecmp);
  if (resv)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":A RESV has already been placed on [%s]",
                        resv->mask);
    return;
  }

  resv = resv_make(aline->mask, aline->reason, NULL);
  resv->created_at = io_time_get(IO_TIME_REALTIME_SEC);
  resv->in_database = true;

  if (aline->duration)
  {
    resv->expires_at = resv->created_at + aline->duration;
    const uintmax_t duration_minutes = aline->duration / 60;

    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Added temporary RESV [%s] (%ju min)",
                        resv->mask, duration_minutes);

    _resv_report_added(source, resv, duration_minutes);
  }
  else
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Added RESV [%s]",
                        resv->mask);

    _resv_report_added(source, resv, 0);
  }
}

/* mo_resv()
 *   parv[0] = command
 *   parv[1] = channel/nick to forbid
 */
static void
mo_resv(struct Client *source, size_t parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_RESV))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "resv");
    return;
  }

  struct aline_ctx aline = { .add = true, .simple_mask = true };
  if (!aline_parse("RESV", source, parc, parv, &aline))
    return;

  if (aline.server)
  {
    sendto_match_servs(source, aline.server, CAPAB_CLUSTER, "RESV %s %ju %s :%s",
                       aline.server, aline.duration, aline.mask, aline.reason);

    /* Allow ON to apply local resv as well if it matches */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source, "RESV", CAPAB_KLN, CLUSTER_RESV, "%ju %s :%s",
                       aline.duration, aline.mask, aline.reason);

  resv_handle(source, &aline);
}

/*! \brief RESV command handler
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
 *      - parv[3] = name mask
 *      - parv[4] = reason
 */
static void
ms_resv(struct Client *source, size_t parc, char *parv[])
{
  uintmax_t duration;
  if (io_parse_uintmax(parv[2], &duration) != IO_PARSE_OK)
    return;

  struct aline_ctx aline =
  {
    .add = true,
    .simple_mask = true,
    .mask = parv[3],
    .reason = parv[4],
    .server = parv[1],
    .duration = duration
  };

  sendto_match_servs(source, aline.server, CAPAB_CLUSTER, "RESV %s %ju %s :%s",
                     aline.server, aline.duration, aline.mask, aline.reason);

  if (match(aline.server, me.name))
    return;

  if (client_is_service(source) ||
      shared_find(SHARED_RESV, source->uplink->name, source->username, source->host))
    resv_handle(source, &aline);
}

static struct Command command_table =
{
  .name = "RESV",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_resv, .args_min = 5 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_resv, .args_min = 2 }
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
