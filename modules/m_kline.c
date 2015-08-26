/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "conf.h"
#include "hostmask.h"
#include "numeric.h"
#include "log.h"
#include "misc.h"
#include "send.h"
#include "server.h"
#include "parse.h"
#include "modules.h"
#include "memory.h"


static void
kline_check(struct AddressRec *arec)
{
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, local_client_list.head)
  {
    struct Client *client_p = node->data;

    if (IsDead(client_p))
      continue;

    if (match(arec->username, client_p->username))
      continue;

    switch (arec->masktype)
    {
      case HM_IPV4:
        if (client_p->connection->aftype == AF_INET)
          if (match_ipv4(&client_p->connection->ip, &arec->Mask.ipa.addr, arec->Mask.ipa.bits))
            conf_try_ban(client_p, arec->conf);
        break;
      case HM_IPV6:
        if (client_p->connection->aftype == AF_INET6)
          if (match_ipv6(&client_p->connection->ip, &arec->Mask.ipa.addr, arec->Mask.ipa.bits))
            conf_try_ban(client_p, arec->conf);
        break;
      default:  /* HM_HOST */
        if (!match(arec->Mask.hostname, client_p->host) || !match(arec->Mask.hostname, client_p->sockhost))
          conf_try_ban(client_p, arec->conf);
        break;
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
kline_add(struct Client *source_p, const char *user, const char *host,
          const char *reason, time_t tkline_time)
{
  char buf[IRCD_BUFSIZE];
  struct MaskItem *conf;

  if (tkline_time)
    snprintf(buf, sizeof(buf), "Temporary K-line %d min. - %.*s (%s)",
             (int)(tkline_time/60), REASONLEN, reason, date_iso8601(0));
  else
    snprintf(buf, sizeof(buf), "%.*s (%s)", REASONLEN, reason, date_iso8601(0));

  conf = conf_make(CONF_KLINE);
  conf->host = xstrdup(host);
  conf->user = xstrdup(user);
  conf->setat = CurrentTime;
  conf->reason = xstrdup(buf);
  SetConfDatabase(conf);

  if (tkline_time)
  {
    conf->until = CurrentTime + tkline_time;

    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":Added temporary %d min. K-Line [%s@%s]",
                        tkline_time/60, conf->user, conf->host);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s added temporary %d min. K-Line for [%s@%s] [%s]",
                         get_oper_name(source_p), tkline_time/60,
                         conf->user, conf->host,
                         conf->reason);
    ilog(LOG_TYPE_KLINE, "%s added temporary %d min. K-Line for [%s@%s] [%s]",
         get_oper_name(source_p), tkline_time/60,
         conf->user, conf->host, conf->reason);
  }
  else
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":Added K-Line [%s@%s]",
                        conf->user, conf->host);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s added K-Line for [%s@%s] [%s]",
                         get_oper_name(source_p),
                         conf->user, conf->host, conf->reason);
    ilog(LOG_TYPE_KLINE, "%s added K-Line for [%s@%s] [%s]",
         get_oper_name(source_p), conf->user, conf->host, conf->reason);
  }

  kline_check(add_conf_by_address(CONF_KLINE, conf));
}

/* already_placed_kline()
 * inputs       - user to complain to, username & host to check for
 * outputs      - returns 1 on existing K-line, 0 if doesn't exist
 * side effects - notifies source_p if the K-line already exists
 */
/*
 * Note: This currently works if the new K-line is a special case of an
 *       existing K-line, but not the other way round. To do that we would
 *       have to walk the hash and check every existing K-line. -A1kmm.
 */
static int
already_placed_kline(struct Client *source_p, const char *user, const char *host)
{
  struct irc_ssaddr iphost, *piphost;
  struct MaskItem *conf = NULL;
  int t = 0;
  int aftype = 0;

  if ((t = parse_netmask(host, &iphost, NULL)) != HM_HOST)
  {
    if (t == HM_IPV6)
      aftype = AF_INET6;
    else
      aftype = AF_INET;

    piphost = &iphost;
  }
  else
    piphost = NULL;

  if ((conf = find_conf_by_address(host, piphost, CONF_KLINE, aftype, user, NULL, 0)))
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":[%s@%s] already K-Lined by [%s@%s] - %s",
                        user, host, conf->user, conf->host, conf->reason);
    return 1;
  }

  return 0;
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
static int
mo_kline(struct Client *source_p, int parc, char *parv[])
{
  char *reason = NULL;
  char *user = NULL;
  char *host = NULL;
  char *target_server = NULL;
  time_t tkline_time = 0;
  int bits = 0;

  if (!HasOFlag(source_p, OPER_FLAG_KLINE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "kline");
    return 0;
  }

  if (!parse_aline("KLINE", source_p, parc, parv, AWILD, &user, &host,
                   &tkline_time, &target_server, &reason))
    return 0;

  if (target_server)
  {
    sendto_match_servs(source_p, target_server, CAPAB_KLN, "KLINE %s %lu %s %s :%s",
                       target_server, (unsigned long)tkline_time,
                       user, host, reason);

    /* Allow ON to apply local kline as well if it matches */
    if (match(target_server, me.name))
      return 0;
  }
  else
    cluster_a_line(source_p, "KLINE", CAPAB_KLN, SHARED_KLINE,
                   "%d %s %s :%s", tkline_time, user, host, reason);

  if (already_placed_kline(source_p, user, host))
    return 0;

  switch (parse_netmask(host, NULL, &bits))
  {
    case HM_IPV4:
      if ((unsigned int)bits < ConfigGeneral.kline_min_cidr)
      {
        sendto_one_notice(source_p, &me, ":For safety, bitmasks less than %u require conf access.",
                          ConfigGeneral.kline_min_cidr);
        return 0;
      }

      break;
    case HM_IPV6:
      if ((unsigned int)bits < ConfigGeneral.kline_min_cidr6)
      {
        sendto_one_notice(source_p, &me, ":For safety, bitmasks less than %u require conf access.",
                          ConfigGeneral.kline_min_cidr6);
        return 0;
      }

      break;
    default:  /* HM_HOST */
      break;
  }

  kline_add(source_p, user, host, reason, tkline_time);
  return 0;
}

/* me_kline - handle remote kline. no propagation */
static int
ms_kline(struct Client *source_p, int parc, char *parv[])
{
  time_t tkline_time = 0;
  const char *user, *host, *reason;
  int bits = 0;

  if (parc != 6 || EmptyString(parv[5]))
    return 0;

  /* parv[0]  parv[1]        parv[2]      parv[3]  parv[4]  parv[5] */
  /* command  target_server  tkline_time  user     host     reason */
  sendto_match_servs(source_p, parv[1], CAPAB_KLN, "KLINE %s %s %s %s :%s",
                     parv[1], parv[2], parv[3], parv[4], parv[5]);

  if (match(parv[1], me.name))
    return 0;

  tkline_time = valid_tkline(parv[2], TK_SECONDS);
  user = parv[3];
  host = parv[4];
  reason = parv[5];

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_KLINE))
  {
    if (!valid_wild_card(source_p, 2, user, host))
      return 0;

    if (already_placed_kline(source_p, user, host))
      return 0;

    switch (parse_netmask(host, NULL, &bits))
    {
      case HM_IPV4:
        if ((unsigned int)bits < ConfigGeneral.kline_min_cidr)
        {
          if (IsClient(source_p))
            sendto_one_notice(source_p, &me, ":For safety, bitmasks less than %u require conf access.",
                              ConfigGeneral.kline_min_cidr);
          return 0;
        }

        break;
      case HM_IPV6:
        if ((unsigned int)bits < ConfigGeneral.kline_min_cidr6)
        {
          if (IsClient(source_p))
            sendto_one_notice(source_p, &me, ":For safety, bitmasks less than %u require conf access.",
                              ConfigGeneral.kline_min_cidr6);
          return 0;
        }

        break;
      default:  /* HM_HOST */
        break;
    }

    kline_add(source_p, user, host, reason, tkline_time);
  }

  return 0;
}

static struct Message kline_msgtab =
{
  .cmd = "KLINE",
  .args_min = 2,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = ms_kline,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_kline
};

static void
module_init(void)
{
  mod_add_cmd(&kline_msgtab);
  add_capability("KLN", CAPAB_KLN);
}

static void
module_exit(void)
{
  mod_del_cmd(&kline_msgtab);
  delete_capability("KLN");
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
