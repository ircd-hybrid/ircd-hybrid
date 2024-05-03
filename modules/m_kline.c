/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*! \file m_kline.c
 * \brief Includes required functions for processing the KLINE command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_shared.h"
#include "address.h"
#include "numeric.h"
#include "log.h"
#include "misc.h"
#include "send.h"
#include "server_capab.h"
#include "parse.h"
#include "modules.h"
#include "memory.h"
#include "aline.h"


static void
kline_check(const struct AddressRec *arec)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, local_client_list.head)
  {
    struct Client *client = node->data;

    if (IsDead(client))
      continue;

    if (match(arec->username, client->username))
      continue;

    switch (arec->masktype)
    {
      case HM_HOST:
        if (match(arec->Mask.hostname, client->realhost) == 0 ||
            match(arec->Mask.hostname, client->sockhost) == 0 || match(arec->Mask.hostname, client->host) == 0)
          conf_try_ban(client, CLIENT_BAN_KLINE, arec->conf->reason);
        break;
      case HM_IPV6:
      case HM_IPV4:
        if (address_compare(&client->addr, &arec->Mask.ipa.addr, false, false, arec->Mask.ipa.bits))
          conf_try_ban(client, CLIENT_BAN_KLINE, arec->conf->reason);
        break;
      default:
        assert(0);
    }
  }
}

/* apply_tkline()
 *
 * inputs       -
 * output       - NONE
 * side effects - tkline as given is placed
 */
static void
kline_handle(struct Client *source, const struct aline_ctx *aline)
{
  char buf[IRCD_BUFSIZE];
  int bits = 0;
  unsigned int min_cidr = 0;
  struct io_addr iphost, *piphost = NULL;

  if (!HasFlag(source, FLAGS_SERVICE) && valid_wild_card(2, aline->user, aline->host) == false)
  {
    if (IsClient(source))
      sendto_one_notice(source, &me,
                        ":Please include at least %u non-wildcard characters with the mask",
                        ConfigGeneral.min_nonwildcard);
    return;
  }

  switch (parse_netmask(aline->host, &iphost, &bits))
  {
    case HM_IPV4:
      min_cidr = ConfigGeneral.kline_min_cidr;
      piphost = &iphost;
      break;
    case HM_IPV6:
      min_cidr = ConfigGeneral.kline_min_cidr6;
      piphost = &iphost;
      break;
    default:  /* HM_HOST */
      break;
  }

  if (min_cidr > 0 && !HasFlag(source, FLAGS_SERVICE) && (unsigned int)bits < min_cidr)
  {
    if (IsClient(source))
      sendto_one_notice(source, &me, ":For safety, bitmasks less than %u require conf access.", min_cidr);
    return;
  }

  struct MaskItem *conf;
  if ((conf = find_conf_by_address(aline->host, piphost, CONF_KLINE, aline->user, NULL, 0)))
  {
    if (IsClient(source))
      sendto_one_notice(source, &me, ":[%s@%s] already K-Lined by [%s@%s] - %s",
                        aline->user, aline->host, conf->user, conf->host, conf->reason);
    return;
  }

  if (aline->duration)
    snprintf(buf, sizeof(buf), "Temporary K-line %ju min. - %.*s (%s)",
             aline->duration / 60, REASONLEN, aline->reason, date_iso8601(0));
  else
    snprintf(buf, sizeof(buf), "%.*s (%s)", REASONLEN, aline->reason, date_iso8601(0));

  conf = conf_make(CONF_KLINE);
  conf->user = xstrdup(aline->user);
  conf->host = xstrdup(aline->host);
  conf->setat = event_base->time.sec_real;
  conf->reason = xstrdup(buf);
  SetConfDatabase(conf);

  if (aline->duration)
  {
    conf->until = event_base->time.sec_real + aline->duration;

    if (IsClient(source))
      sendto_one_notice(source, &me, ":Added temporary %ju min. K-Line [%s@%s]",
                        aline->duration / 60, conf->user, conf->host);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s added temporary %ju min. K-Line for [%s@%s] [%s]",
                         get_oper_name(source), aline->duration / 60, conf->user, conf->host, conf->reason);
    log_write(LOG_TYPE_KLINE, "%s added temporary %ju min. K-Line for [%s@%s] [%s]",
              get_oper_name(source), aline->duration / 60, conf->user, conf->host, conf->reason);
  }
  else
  {
    if (IsClient(source))
      sendto_one_notice(source, &me, ":Added K-Line [%s@%s]",
                        conf->user, conf->host);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "%s added K-Line for [%s@%s] [%s]",
                         get_oper_name(source), conf->user, conf->host, conf->reason);
    log_write(LOG_TYPE_KLINE, "%s added K-Line for [%s@%s] [%s]",
              get_oper_name(source), conf->user, conf->host, conf->reason);
  }

  kline_check(add_conf_by_address(CONF_KLINE, conf));
}

/* mo_kline()
 *
 * inputs	- pointer to server
 *		- pointer to client
 *		- parameter count
 *		- parameter list
 * output	-
 * side effects - k line is added
 */
static void
mo_kline(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline = { .add = true, .simple_mask = false };

  if (!HasOFlag(source, OPER_FLAG_KLINE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "kline");
    return;
  }

  if (parse_aline("KLINE", source, parc, parv, &aline) == false)
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
  struct aline_ctx aline =
  {
    .add = true,
    .simple_mask = false,
    .user = parv[3],
    .host = parv[4],
    .reason = parv[5],
    .server = parv[1],
    .duration = strtoumax(parv[2], NULL, 10)
  };

  sendto_match_servs(source, aline.server, CAPAB_KLN, "KLINE %s %ju %s %s :%s",
                     aline.server, aline.duration, aline.user, aline.host, aline.reason);

  if (match(aline.server, me.name))
    return;

  if (HasFlag(source, FLAGS_SERVICE) ||
      shared_find(SHARED_KLINE, source->servptr->name, source->username, source->host))
    kline_handle(source, &aline);
}

static struct Command kline_msgtab =
{
  .name = "KLINE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_kline, .args_min = 6 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_kline, .args_min = 2 }
};

static void
module_init(void)
{
  command_add(&kline_msgtab);
  capab_add("KLN", CAPAB_KLN, true);
}

static void
module_exit(void)
{
  command_del(&kline_msgtab);
  capab_del("KLN");
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
