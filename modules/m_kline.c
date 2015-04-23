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
#include "conf_db.h"
#include "memory.h"


static void
check_kline(struct AddressRec *arec)
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
m_kline_add_kline(struct Client *source_p, struct MaskItem *conf,
                  time_t tkline_time)
{
  if (tkline_time)
  {
    conf->until = CurrentTime + tkline_time;

    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":Added temporary %d min. K-Line [%s@%s]",
                        tkline_time/60, conf->user, conf->host);

    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
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

    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s added K-Line for [%s@%s] [%s]",
                         get_oper_name(source_p),
                         conf->user, conf->host, conf->reason);
    ilog(LOG_TYPE_KLINE, "%s added K-Line for [%s@%s] [%s]",
         get_oper_name(source_p), conf->user, conf->host, conf->reason);
  }

  conf->setat = CurrentTime;
  SetConfDatabase(conf);

  check_kline(add_conf_by_address(CONF_KLINE, conf));
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
already_placed_kline(struct Client *source_p, const char *luser, const char *lhost)
{
  struct irc_ssaddr iphost, *piphost;
  struct MaskItem *conf = NULL;
  int t = 0;
  int aftype = 0;

  if ((t = parse_netmask(lhost, &iphost, NULL)) != HM_HOST)
  {
    if (t == HM_IPV6)
      aftype = AF_INET6;
    else
      aftype = AF_INET;
    piphost = &iphost;
  }
  else
    piphost = NULL;

  if ((conf = find_conf_by_address(lhost, piphost, CONF_KLINE, aftype, luser, NULL, 0)))
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":[%s@%s] already K-Lined by [%s@%s] - %s",
                        luser, lhost, conf->user, conf->host, conf->reason);
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
  char buffer[IRCD_BUFSIZE];
  char *reason = NULL;
  char *user = NULL;
  char *host = NULL;
  char *target_server = NULL;
  struct MaskItem *conf;
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
    sendto_match_servs(source_p, target_server, CAP_KLN, "KLINE %s %lu %s %s :%s",
                       target_server, (unsigned long)tkline_time,
                       user, host, reason);

    /* Allow ON to apply local kline as well if it matches */
    if (match(target_server, me.name))
      return 0;
  }
  else
    cluster_a_line(source_p, "KLINE", CAP_KLN, SHARED_KLINE,
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

  conf = conf_make(CONF_KLINE);
  conf->host = xstrdup(host);
  conf->user = xstrdup(user);

  if (tkline_time)
    snprintf(buffer, sizeof(buffer), "Temporary K-line %d min. - %.*s (%s)",
             (int)(tkline_time/60), REASONLEN, reason, smalldate(0));
  else
    snprintf(buffer, sizeof(buffer), "%.*s (%s)", REASONLEN, reason, smalldate(0));

  conf->reason = xstrdup(buffer);
  m_kline_add_kline(source_p, conf, tkline_time);
  return 0;
}

/* me_kline - handle remote kline. no propagation */
static int
ms_kline(struct Client *source_p, int parc, char *parv[])
{
  char buffer[IRCD_BUFSIZE];
  struct MaskItem *conf = NULL;
  time_t tkline_time = 0;
  char *kuser, *khost, *kreason;
  int bits = 0;

  if (parc != 6 || EmptyString(parv[5]))
    return 0;

  /* parv[0]  parv[1]        parv[2]      parv[3]  parv[4]  parv[5] */
  /* command  target_server  tkline_time  user     host     reason */
  sendto_match_servs(source_p, parv[1], CAP_KLN, "KLINE %s %s %s %s :%s",
                     parv[1], parv[2], parv[3], parv[4], parv[5]);

  if (match(parv[1], me.name))
    return 0;

  tkline_time = valid_tkline(parv[2], TK_SECONDS);
  kuser = parv[3];
  khost = parv[4];
  kreason = parv[5];

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_KLINE))
  {
    if (!valid_wild_card(source_p, 2, kuser, khost))
      return 0;

    if (already_placed_kline(source_p, kuser, khost))
      return 0;

    switch (parse_netmask(khost, NULL, &bits))
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

    conf = conf_make(CONF_KLINE);
    conf->host = xstrdup(khost);
    conf->user = xstrdup(kuser);

    if (tkline_time)
      snprintf(buffer, sizeof(buffer), "Temporary K-line %u min. - %.*s (%s)",
               (unsigned int)(tkline_time/60), REASONLEN, kreason, smalldate(0));
    else
      snprintf(buffer, sizeof(buffer), "%.*s (%s)", REASONLEN, kreason, smalldate(0));

    conf->reason = xstrdup(buffer);
    m_kline_add_kline(source_p, conf, tkline_time);
  }

  return 0;
}

static struct Message kline_msgtab =
{
  "KLINE", NULL, 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_kline, m_ignore, mo_kline, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&kline_msgtab);
  add_capability("KLN", CAP_KLN);
}

static void
module_exit(void)
{
  mod_del_cmd(&kline_msgtab);
  delete_capability("KLN");
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
