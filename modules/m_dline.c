/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 */

/*! \file m_dline.c
 * \brief Includes required functions for processing the DLINE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "conf.h"
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
#include "log.h"
#include "misc.h"
#include "send.h"
#include "hash.h"
#include "server.h"
#include "parse.h"
#include "modules.h"
#include "conf_db.h"
#include "memory.h"


/* apply_tdline()
 *
 * inputs	-
 * output	- NONE
 * side effects	- tkline as given is placed
 */
static void
apply_dline(struct Client *source_p, struct MaskItem *conf,
            time_t tkline_time)
{
  if (tkline_time)
  {
    conf->until = CurrentTime + tkline_time;
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s added temporary %d min. D-Line for [%s] [%s]",
                         get_oper_name(source_p), tkline_time/60,
                         conf->host, conf->reason);
    sendto_one_notice(source_p, &me, ":Added temporary %d min. D-Line [%s]",
                      tkline_time/60, conf->host);
    ilog(LOG_TYPE_DLINE, "%s added temporary %d min. D-Line for [%s] [%s]",
         get_oper_name(source_p), tkline_time/60, conf->host, conf->reason);
  }
  else
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s added D-Line for [%s] [%s]",
                         get_oper_name(source_p), conf->host, conf->reason);
    sendto_one_notice(source_p, &me, ":Added D-Line [%s]", conf->host);
    ilog(LOG_TYPE_DLINE, "%s added D-Line for [%s] [%s]",
         get_oper_name(source_p), conf->host, conf->reason);

  }

  SetConfDatabase(conf);
  conf->setat = CurrentTime;
  add_conf_by_address(CONF_DLINE, conf);
  rehashed_klines = 1;
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
static int
mo_dline(struct Client *source_p, int parc, char *parv[])
{
  char def_reason[] = CONF_NOREASON;
  char *dlhost = NULL, *reason = NULL;
  char *target_server = NULL;
  const char *creason;
  const struct Client *target_p = NULL;
  struct irc_ssaddr daddr;
  struct MaskItem *conf=NULL;
  time_t tkline_time=0;
  int bits = 0, aftype = 0, t = 0;
  const char *current_date = NULL;
  char hostip[HOSTIPLEN + 1];
  char buffer[IRCD_BUFSIZE];

  if (!HasOFlag(source_p, OPER_FLAG_DLINE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "dline");
    return 0;
  }

  if (parse_aline("DLINE", source_p,  parc, parv, AWILD, &dlhost,
                  NULL, &tkline_time, &target_server, &reason) < 0)
    return 0;

  if (target_server)
  {
    sendto_match_servs(source_p, target_server, CAP_DLN, "DLINE %s %lu %s :%s",
                       target_server, (unsigned long)tkline_time,
                       dlhost, reason);

    /* Allow ON to apply local kline as well if it matches */
    if (match(target_server, me.name))
      return 0;
  }
  else
    cluster_a_line(source_p, "DLINE", CAP_DLN, SHARED_DLINE,
                   "%d %s :%s", tkline_time, dlhost, reason);

  if ((t = parse_netmask(dlhost, NULL, &bits)) == HM_HOST)
  {
    if ((target_p = find_chasing(source_p, dlhost)) == NULL)
      return 0;  /* find_chasing sends ERR_NOSUCHNICK */

    if (!MyConnect(target_p))
    {
      sendto_one_notice(source_p, &me, ":Cannot DLINE nick on another server");
      return 0;
    }

    if (IsExemptKline(target_p))
    {
      sendto_one_notice(source_p, &me, ":%s is E-lined",
                        target_p->name);
      return 0;
    }

    getnameinfo((struct sockaddr *)&target_p->localClient->ip,
                target_p->localClient->ip.ss_len, hostip,
                sizeof(hostip), NULL, 0, NI_NUMERICHOST);
    dlhost = hostip;
    t = parse_netmask(dlhost, NULL, &bits);
    assert(t == HM_IPV4 || t == HM_IPV6);
  }

  if (bits < 8)
  {
    sendto_one_notice(source_p, &me, ":For safety, bitmasks less than 8 require conf access.");
    return 0;
  }

#ifdef IPV6
  if (t == HM_IPV6)
    aftype = AF_INET6;
  else
#endif
    aftype = AF_INET;

  parse_netmask(dlhost, &daddr, NULL);

  if ((conf = find_dline_conf(&daddr, aftype)))
  {
    creason = conf->reason ? conf->reason : def_reason;

    if (IsConfExemptKline(conf))
      sendto_one_notice(source_p, &me, ":[%s] is (E)d-lined by [%s] - %s",
                        dlhost, conf->host, creason);
    else
      sendto_one_notice(source_p, &me, ":[%s] already D-lined by [%s] - %s",
                        dlhost, conf->host, creason);
    return 0;
  }

  current_date = smalldate(0);

  if (!valid_comment(source_p, reason, 1))
    return 0;

  conf = conf_make(CONF_DLINE);
  conf->host = xstrdup(dlhost);

  if (tkline_time)
    snprintf(buffer, sizeof(buffer), "Temporary D-line %d min. - %s (%s)",
             (int)(tkline_time/60), reason, current_date);
  else
    snprintf(buffer, sizeof(buffer), "%s (%s)", reason, current_date);

  conf->reason = xstrdup(buffer);
  apply_dline(source_p, conf, tkline_time);
  rehashed_klines = 1;
  return 0;
}

static int
ms_dline(struct Client *source_p, int parc, char *parv[])
{
  char def_reason[] = CONF_NOREASON;
  char *dlhost, *reason;
  const char *creason;
  const struct Client *target_p = NULL;
  struct irc_ssaddr daddr;
  struct MaskItem *conf=NULL;
  time_t tkline_time=0;
  int bits = 0, aftype = 0, t = 0;
  const char *current_date = NULL;
  char hostip[HOSTIPLEN + 1];
  char buffer[IRCD_BUFSIZE];

  if (parc != 5 || EmptyString(parv[4]))
    return 0;

  /* parv[0]  parv[1]        parv[2]      parv[3]  parv[4] */
  /* oper     target_server  tkline_time  host     reason  */
  sendto_match_servs(source_p, parv[1], CAP_DLN,
                     "DLINE %s %s %s :%s",
                     parv[1], parv[2], parv[3], parv[4]);

  if (match(parv[1], me.name))
    return 0;

  tkline_time = valid_tkline(parv[2], TK_SECONDS);
  dlhost = parv[3];
  reason = parv[4];

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_DLINE))
  {
    if (!IsClient(source_p))
      return 0;

    if ((t = parse_netmask(dlhost, NULL, &bits)) == HM_HOST)
    {
      if ((target_p = find_chasing(source_p, dlhost)) == NULL)
        return 0;  /* find_chasing sends ERR_NOSUCHNICK */

      if (!MyConnect(target_p))
      {
        sendto_one_notice(source_p, &me, ":Cannot DLINE nick on another server");
        return 0;
      }

      if (IsExemptKline(target_p))
      {
        sendto_one_notice(source_p, &me, ":%s is E-lined", target_p->name);
        return 0;
      }

      getnameinfo((struct sockaddr *)&target_p->localClient->ip,
                  target_p->localClient->ip.ss_len, hostip,
                  sizeof(hostip), NULL, 0, NI_NUMERICHOST);
      dlhost = hostip;
      t = parse_netmask(dlhost, NULL, &bits);
      assert(t == HM_IPV4 || t == HM_IPV6);
    }

    if (bits < 8)
    {
      sendto_one_notice(source_p, &me, ":For safety, bitmasks less than 8 require conf access.");
      return 0;
    }

#ifdef IPV6
    if (t == HM_IPV6)
      aftype= AF_INET6;
    else
#endif
      aftype = AF_INET;

    parse_netmask(dlhost, &daddr, NULL);

    if ((conf = find_dline_conf(&daddr, aftype)))
    {
      creason = conf->reason ? conf->reason : def_reason;
      if (IsConfExemptKline(conf))
        sendto_one_notice(source_p, &me, ":[%s] is (E)d-lined by [%s] - %s",
                          dlhost, conf->host, creason);
      else
        sendto_one_notice(source_p, &me, ":[%s] already D-lined by [%s] - %s",
                          dlhost, conf->host, creason);
      return 0;
    }

    current_date = smalldate(0);

    if (!valid_comment(source_p, reason, 1))
      return 0;

    conf = conf_make(CONF_DLINE);
    conf->host = xstrdup(dlhost);

    if (tkline_time)
      snprintf(buffer, sizeof(buffer), "Temporary D-line %d min. - %s (%s)",
               (int)(tkline_time/60), reason, current_date);
    else
      snprintf(buffer, sizeof(buffer), "%s (%s)", reason, current_date);

    conf->reason = xstrdup(buffer);
    apply_dline(source_p, conf, tkline_time);
    rehashed_klines = 1;
  }

  return 0;
}

static struct Message dline_msgtab =
{
  "DLINE", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_dline, m_ignore, mo_dline, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&dline_msgtab);
  add_capability("DLN", CAP_DLN, 1);
}

static void
module_exit(void)
{
  mod_del_cmd(&dline_msgtab);
  delete_capability("DLN");
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
