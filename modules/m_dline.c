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

/*! \file m_dline.c
 * \brief Includes required functions for processing the DLINE command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_shared.h"
#include "ircd.h"
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
dline_check(const struct AddressRec *arec)
{
  list_t *tab[] = { &local_client_list, &unknown_list, NULL };

  for (list_t **list = tab; *list; ++list)
  {
    list_node_t *node, *node_next;

    LIST_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      struct Client *client = node->data;

      if (IsDead(client))
        continue;

      switch (arec->masktype)
      {
        case HM_IPV6:
        case HM_IPV4:
          if (address_compare(&client->addr, &arec->Mask.ipa.addr, false, false, arec->Mask.ipa.bits))
            conf_try_ban(client, CLIENT_BAN_DLINE, arec->conf->reason);
          break;
        default:
          assert(0);
      }
    }
  }
}

/* dline_add()
 *
 * inputs	-
 * output	- NONE
 * side effects	- dline as given is placed
 */
static void
dline_handle(struct Client *source, const struct aline_ctx *aline)
{
  char buf[IRCD_BUFSIZE];
  struct io_addr addr;
  int bits = 0;
  unsigned int min_cidr = 0;

  switch (parse_netmask(aline->host, &addr, &bits))
  {
    case HM_IPV4:
      min_cidr = ConfigGeneral.dline_min_cidr;
      break;
    case HM_IPV6:
      min_cidr = ConfigGeneral.dline_min_cidr6;
      break;
    default:  /* HM_HOST */
      if (IsClient(source))
        sendto_one_notice(source, &me, ":Invalid D-Line");
      return;
  }

  if (min_cidr > 0 && !HasFlag(source, FLAGS_SERVICE) && (unsigned int)bits < min_cidr)
  {
    if (IsClient(source))
      sendto_one_notice(source, &me, ":For safety, bitmasks less than %u require conf access.", min_cidr);
    return;
  }

  struct MaskItem *conf;
  if ((conf = find_conf_by_address(NULL, &addr, CONF_DLINE, NULL, NULL, 1)))
  {
    if (IsClient(source))
      sendto_one_notice(source, &me, ":[%s] already D-lined by [%s] - %s",
                        aline->host, conf->host, conf->reason);
    return;
  }

  if (aline->duration)
    snprintf(buf, sizeof(buf), "Temporary D-line %ju min. - %.*s (%s)",
             aline->duration / 60, REASONLEN, aline->reason, date_iso8601(0));
  else
    snprintf(buf, sizeof(buf), "%.*s (%s)", REASONLEN, aline->reason, date_iso8601(0));

  conf = conf_make(CONF_DLINE);
  conf->host = io_strdup(aline->host);
  conf->reason = io_strdup(buf);
  conf->setat = event_base->time.sec_real;
  SetConfDatabase(conf);

  if (aline->duration)
  {
    conf->until = event_base->time.sec_real + aline->duration;

    if (IsClient(source))
      sendto_one_notice(source, &me, ":Added temporary %ju min. D-Line [%s]",
                        aline->duration / 60, conf->host);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s added temporary %ju min. D-Line for [%s] [%s]",
                         get_oper_name(source), aline->duration / 60, conf->host, conf->reason);
    log_write(LOG_TYPE_DLINE, "%s added temporary %ju min. D-Line for [%s] [%s]",
              get_oper_name(source), aline->duration / 60, conf->host, conf->reason);
  }
  else
  {
    if (IsClient(source))
      sendto_one_notice(source, &me, ":Added D-Line [%s]", conf->host);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "%s added D-Line for [%s] [%s]",
                         get_oper_name(source), conf->host, conf->reason);
    log_write(LOG_TYPE_DLINE, "%s added D-Line for [%s] [%s]",
              get_oper_name(source), conf->host, conf->reason);
  }

  dline_check(add_conf_by_address(CONF_DLINE, conf));
}

/* mo_dline()
 *
 * inputs	- pointer to server
 *		- pointer to client
 *		- parameter count
 *		- parameter list
 * output	-
 * side effects - D line is added
 *
 */
static void
mo_dline(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline = { .add = true, .simple_mask = false };

  if (!HasOFlag(source, OPER_FLAG_DLINE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "dline");
    return;
  }

  if (aline_parse("DLINE", source, parc, parv, &aline) == false)
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
ms_dline(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline =
  {
    .add = true,
    .simple_mask = false,
    .host = parv[3],
    .reason = parv[4],
    .server = parv[1],
    .duration = strtoumax(parv[2], NULL, 10)
  };

  sendto_match_servs(source, aline.server, CAPAB_DLN, "DLINE %s %ju %s :%s",
                     aline.server, aline.duration, aline.host, aline.reason);

  if (match(aline.server, me.name))
    return;

  if (HasFlag(source, FLAGS_SERVICE) ||
      shared_find(SHARED_DLINE, source->servptr->name, source->username, source->host))
    dline_handle(source, &aline);
}

static struct Command dline_msgtab =
{
  .name = "DLINE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_dline, .args_min = 5 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_dline, .args_min = 2 }
};

static void
module_init(void)
{
  command_add(&dline_msgtab);
  capab_add("DLN", CAPAB_DLN, true);
}

static void
module_exit(void)
{
  command_del(&dline_msgtab);
  capab_del("DLN");
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
