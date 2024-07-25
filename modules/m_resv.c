/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2024 ircd-hybrid development team
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

/*! \file m_resv.c
 * \brief Includes required functions for processing the RESV command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "server_capab.h"
#include "send.h"
#include "parse.h"
#include "module.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_resv.h"
#include "conf_shared.h"
#include "log.h"
#include "aline.h"


/* parse_resv()
 *
 * inputs	- source
 *		- thing to resv
 *		- !0 if temporary
 *		- reason
 * outputs	- none
 * side effects	- parse resv, create if valid
 */
static void
resv_handle(struct Client *source, const struct aline_ctx *aline)
{
  if (!HasFlag(source, FLAGS_SERVICE))
  {
    if (aline_valid_mask_simple(aline->mask + !!IsChanPrefix(*aline->mask)) == false)
    {
      if (IsClient(source))
        sendto_one_notice(source, &me, ":Please include at least %u non-wildcard characters with the RESV",
                          ConfigGeneral.min_nonwildcard_simple);
      return;
    }
  }

  struct ResvItem *resv = resv_find(aline->mask, irccmp);
  if (resv)
  {
    if (IsClient(source))
      sendto_one_notice(source, &me, ":A RESV has already been placed on: %s", resv->mask);
    return;
  }

  resv = resv_make(aline->mask, aline->reason, NULL);
  resv->setat = io_time_get(IO_TIME_REALTIME_SEC);
  resv->in_database = true;

  if (aline->duration)
  {
    resv->expire = resv->setat + aline->duration;

    if (IsClient(source))
      sendto_one_notice(source, &me, ":Added temporary %ju min. RESV [%s]",
                        aline->duration / 60, resv->mask);

    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "%s added temporary %ju min. RESV for [%s] [%s]",
                   get_oper_name(source), aline->duration / 60, resv->mask, resv->reason);
    log_write(LOG_TYPE_RESV, "%s added temporary %ju min. RESV for [%s] [%s]",
              get_oper_name(source), aline->duration / 60, resv->mask, resv->reason);
  }
  else
  {
    if (IsClient(source))
      sendto_one_notice(source, &me, ":Added RESV [%s] [%s]",
                        resv->mask, resv->reason);

    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "%s added RESV for [%s] [%s]",
                   get_oper_name(source), resv->mask, resv->reason);
    log_write(LOG_TYPE_RESV, "%s added RESV for [%s] [%s]",
              get_oper_name(source), resv->mask, resv->reason);
  }
}

/* mo_resv()
 *   parv[0] = command
 *   parv[1] = channel/nick to forbid
 */
static void
mo_resv(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline = { .add = true, .simple_mask = true };

  if (!HasOFlag(source, OPER_FLAG_RESV))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "resv");
    return;
  }

  if (aline_parse("RESV", source, parc, parv, &aline) == false)
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
ms_resv(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline =
  {
    .add = true,
    .simple_mask = true,
    .mask = parv[3],
    .reason = parv[4],
    .server = parv[1],
    .duration = strtoumax(parv[2], NULL, 10)
  };

  sendto_match_servs(source, aline.server, CAPAB_CLUSTER, "RESV %s %ju %s :%s",
                     aline.server, aline.duration, aline.mask, aline.reason);

  if (match(aline.server, me.name))
    return;

  if (HasFlag(source, FLAGS_SERVICE) ||
      shared_find(SHARED_RESV, source->servptr->name, source->username, source->host))
    resv_handle(source, &aline);
}

static struct Command command_table =
{
  .name = "RESV",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_resv, .args_min = 5 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_resv, .args_min = 2 }
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
