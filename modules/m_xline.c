/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2003-2024 ircd-hybrid development team
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

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_gecos.h"
#include "conf_shared.h"
#include "numeric.h"
#include "log.h"
#include "misc.h"
#include "send.h"
#include "server_capab.h"
#include "parse.h"
#include "modules.h"
#include "memory.h"


static void
xline_check(const struct GecosItem *gecos)
{
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, local_client_list.head)
  {
    struct Client *client = node->data;

    if (IsDead(client))
      continue;

    if (match(gecos->mask, client->info) == 0)
      conf_try_ban(client, CLIENT_BAN_XLINE, gecos->reason);
  }
}

/* xline_handle()
 *
 * inputs       - client taking credit for xline, gecos, reason, xline type
 * outputs      - none
 * side effects - when successful, adds an xline to the conf
 */
static void
xline_handle(struct Client *source_p, const struct aline_ctx *aline)
{
  char buf[IRCD_BUFSIZE];

  if (!HasFlag(source_p, FLAGS_SERVICE))
  {
    if (valid_wild_card_simple(aline->mask) == false)
    {
      if (IsClient(source_p))
        sendto_one_notice(source_p, &me, ":Please include at least %u non-wildcard characters with the xline",
                          ConfigGeneral.min_nonwildcard_simple);
      return;
    }
  }

  struct GecosItem *gecos = gecos_find(aline->mask, match);
  if (gecos)
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":[%s] already X-Lined by [%s] - %s",
                        aline->mask, gecos->mask, gecos->reason);
    return;
  }

  if (aline->duration)
    snprintf(buf, sizeof(buf), "Temporary X-line %ju min. - %.*s (%s)",
             aline->duration / 60, REASONLEN, aline->reason, date_iso8601(0));
  else
    snprintf(buf, sizeof(buf), "%.*s (%s)", REASONLEN, aline->reason, date_iso8601(0));

  gecos = gecos_make();
  gecos->mask = xstrdup(aline->mask);
  gecos->reason = xstrdup(buf);
  gecos->setat = event_base->time.sec_real;
  gecos->in_database = true;

  if (aline->duration)
  {
    gecos->expire = event_base->time.sec_real + aline->duration;

    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":Added temporary %ju min. X-Line [%s]",
                        aline->duration / 60, gecos->mask);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s added temporary %ju min. X-Line for [%s] [%s]",
                         get_oper_name(source_p), aline->duration / 60,
                         gecos->mask, gecos->reason);
    log_write(LOG_TYPE_XLINE, "%s added temporary %ju min. X-Line for [%s] [%s]",
         get_oper_name(source_p), aline->duration / 60, gecos->mask, gecos->reason);
  }
  else
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":Added X-Line [%s] [%s]",
                        gecos->mask, gecos->reason);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s added X-Line for [%s] [%s]",
                         get_oper_name(source_p), gecos->mask,
                         gecos->reason);
    log_write(LOG_TYPE_XLINE, "%s added X-Line for [%s] [%s]",
         get_oper_name(source_p), gecos->mask, gecos->reason);
  }

  xline_check(gecos);
}

/* mo_xline()
 *
 * inputs	- pointer to server
 *		- pointer to client
 *		- parameter count
 *		- parameter list
 * output	-
 * side effects - x line is added
 *
 */
static void
mo_xline(struct Client *source_p, int parc, char *parv[])
{
  struct aline_ctx aline = { .add = true, .simple_mask = true };

  if (!HasOFlag(source_p, OPER_FLAG_XLINE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "xline");
    return;
  }

  if (parse_aline("XLINE", source_p, parc, parv, &aline) == false)
    return;

  if (aline.server)
  {
    sendto_match_servs(source_p, aline.server, CAPAB_CLUSTER, "XLINE %s %s %ju :%s",
                       aline.server, aline.mask, aline.duration, aline.reason);

    /* Allow ON to apply local xline as well if it matches */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source_p, "XLINE", CAPAB_CLUSTER, CLUSTER_XLINE, "%s %ju :%s",
                       aline.mask, aline.mask, aline.reason);

  xline_handle(source_p, &aline);
}

/*! \brief XLINE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
ms_xline(struct Client *source_p, int parc, char *parv[])
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

  sendto_match_servs(source_p, aline.server, CAPAB_CLUSTER, "XLINE %s %s %ju :%s",
                     aline.server, aline.mask, aline.duration, aline.reason);

  if (match(aline.server, me.name))
    return;

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      shared_find(SHARED_XLINE, source_p->servptr->name,
                  source_p->username, source_p->host))
    xline_handle(source_p, &aline);
}

static struct Message xline_msgtab =
{
  .cmd = "XLINE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_xline, .args_min = 5 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_xline, .args_min = 2 }
};

static void
module_init(void)
{
  mod_add_cmd(&xline_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&xline_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
