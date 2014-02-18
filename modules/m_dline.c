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
 * \brief Includes required functions for processing the DLINE/UNDLINE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "client.h"
#include "irc_string.h"
#include "conf.h"
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "log.h"
#include "s_misc.h"
#include "send.h"
#include "hash.h"
#include "s_serv.h"
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
    sendto_one(source_p, ":%s NOTICE %s :Added temporary %d min. D-Line [%s]",
               MyConnect(source_p) ? me.name : ID_or_name(&me, source_p),
               source_p->name, tkline_time/60, conf->host);
    ilog(LOG_TYPE_DLINE, "%s added temporary %d min. D-Line for [%s] [%s]",
         get_oper_name(source_p), tkline_time/60, conf->host, conf->reason);
  }
  else
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s added D-Line for [%s] [%s]",
                         get_oper_name(source_p), conf->host, conf->reason);
    sendto_one(source_p, ":%s NOTICE %s :Added D-Line [%s]",
               MyConnect(source_p) ? me.name : ID_or_name(&me, source_p),
               source_p->name, conf->host);
    ilog(LOG_TYPE_DLINE, "%s added D-Line for [%s] [%s]",
         get_oper_name(source_p), conf->host, conf->reason);

  }

  SetConfDatabase(conf);
  conf->setat = CurrentTime;
  add_conf_by_address(CONF_DLINE, conf);
  rehashed_klines = 1;
}

/* static int remove_tdline_match(const char *host, const char *user)
 * Input: An ip to undline.
 * Output: returns YES on success, NO if no tdline removed.
 * Side effects: Any matching tdlines are removed.
 */
static int
remove_dline_match(const char *host)
{
  struct irc_ssaddr iphost, *piphost;
  struct MaskItem *conf;
  int t = 0;
  int aftype = 0;

  if ((t = parse_netmask(host, &iphost, NULL)) != HM_HOST)
  {
#ifdef IPV6
    if (t == HM_IPV6)
      aftype = AF_INET6;
    else
#endif
      aftype = AF_INET;
    piphost = &iphost;
  }
  else
    piphost = NULL;

  if ((conf = find_conf_by_address(host, piphost, CONF_DLINE, aftype, NULL, NULL, 0)))
  {
    if (IsConfDatabase(conf))
    {
      delete_one_address_conf(host, conf);
      return 1;
    }
  }

  return 0;
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
mo_dline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
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
  time_t cur_time;
  char hostip[HOSTIPLEN + 1];
  char buffer[IRCD_BUFSIZE];

  if (!HasOFlag(source_p, OPER_FLAG_DLINE))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS), me.name,
               source_p->name, "dline");
    return 0;
  }

  if (parse_aline("DLINE", source_p,  parc, parv, AWILD, &dlhost,
                  NULL, &tkline_time, &target_server, &reason) < 0)
    return 0;

  if (target_server != NULL)
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
    if ((target_p = find_chasing(source_p, dlhost, NULL)) == NULL)
      return 0;

    if (!MyConnect(target_p))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :Can't DLINE nick on another server",
                 me.name, source_p->name);
      return 0;
    }

    if (IsExemptKline(target_p))
    {
      sendto_one(source_p, ":%s NOTICE %s :%s is E-lined",
                 me.name, source_p->name, target_p->name);
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
    sendto_one(source_p,
               ":%s NOTICE %s :For safety, bitmasks less than 8 require conf access.",
               me.name, source_p->name);
    return 0;
  }

#ifdef IPV6
  if (t == HM_IPV6)
    aftype = AF_INET6;
  else
#endif
    aftype = AF_INET;

  parse_netmask(dlhost, &daddr, NULL);

  if ((conf = find_dline_conf(&daddr, aftype)) != NULL)
  {
    creason = conf->reason ? conf->reason : def_reason;

    if (IsConfExemptKline(conf))
      sendto_one(source_p, ":%s NOTICE %s :[%s] is (E)d-lined by [%s] - %s",
                 me.name, source_p->name, dlhost, conf->host, creason);
    else
      sendto_one(source_p, ":%s NOTICE %s :[%s] already D-lined by [%s] - %s",
                 me.name, source_p->name, dlhost, conf->host, creason);
    return 0;
  }

  cur_time = CurrentTime;
  current_date = smalldate(cur_time);

  if (!valid_comment(source_p, reason, 1))
    return 0;

  conf = conf_make(CONF_DLINE);
  conf->host = xstrdup(dlhost);

  if (tkline_time != 0)
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
ms_dline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
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
  time_t cur_time;
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
      if ((target_p = find_chasing(source_p, dlhost, NULL)) == NULL)
        return 0;

      if (!MyConnect(target_p))
      {
        sendto_one(source_p,
                   ":%s NOTICE %s :Can't DLINE nick on another server",
                   me.name, source_p->name);
        return 0;
      }

      if (IsExemptKline(target_p))
      {
        sendto_one(source_p,
                   ":%s NOTICE %s :%s is E-lined", me.name,
                   source_p->name, target_p->name);
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
      sendto_one(source_p,
                 ":%s NOTICE %s :For safety, bitmasks less than 8 require conf access.",
                 me.name, source_p->name);
      return 0;
    }

#ifdef IPV6
    if (t == HM_IPV6)
      aftype= AF_INET6;
    else
#endif
      aftype = AF_INET;

    parse_netmask(dlhost, &daddr, NULL);

    if ((conf = find_dline_conf(&daddr, aftype)) != NULL)
    {
      creason = conf->reason ? conf->reason : def_reason;
      if (IsConfExemptKline(conf))
        sendto_one(source_p,
                   ":%s NOTICE %s :[%s] is (E)d-lined by [%s] - %s",
                   me.name, source_p->name, dlhost, conf->host, creason);
      else
        sendto_one(source_p,
                   ":%s NOTICE %s :[%s] already D-lined by [%s] - %s",
                   me.name, source_p->name, dlhost, conf->host, creason);
      return 0;
    }

    cur_time = CurrentTime;
    current_date = smalldate(cur_time);

    if (!valid_comment(source_p, reason, 1))
      return 0;

    conf = conf_make(CONF_DLINE);
    conf->host = xstrdup(dlhost);

    if (tkline_time != 0)
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

/*
** m_undline
** added May 28th 2000 by Toby Verrall <toot@melnet.co.uk>
** based totally on m_unkline
** added to hybrid-7 7/11/2000 --is
**
**      parv[0] = sender nick
**      parv[1] = dline to remove
*/
static int
mo_undline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  char *addr = NULL, *user = NULL;
  char *target_server = NULL;

  if (!HasOFlag(source_p, OPER_FLAG_UNDLINE))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS), me.name,
               source_p->name, "undline");
    return 0;
  }

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "UNDLINE");
    return 0;
  }

  if (parse_aline("UNDLINE", source_p, parc, parv, 0, &user,
                  &addr, NULL, &target_server, NULL) < 0)
    return 0;

  if (target_server != NULL)
  {
    sendto_match_servs(source_p, target_server, CAP_UNDLN,
                       "UNDLINE %s %s", target_server, addr);

    /* Allow ON to apply local unkline as well if it matches */
    if (match(target_server, me.name))
      return 0;
  }
  else
    cluster_a_line(source_p, "UNDLINE", CAP_UNDLN, SHARED_UNDLINE,
                   "%s", addr);

  if (remove_dline_match(addr))
  {
    sendto_one(source_p, ":%s NOTICE %s :D-Line for [%s] is removed",
               me.name, source_p->name, addr);
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has removed the D-Line for: [%s]",
                         get_oper_name(source_p), addr);
    ilog(LOG_TYPE_DLINE, "%s removed D-Line for [%s]",
         get_oper_name(source_p), addr);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :No D-Line for [%s] found",
               me.name, source_p->name, addr);
  return 0;
}

static int
ms_undline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  const char *addr = parv[1];

  if (parc != 3 || EmptyString(parv[2]))
    return 0;

  sendto_match_servs(source_p, parv[1], CAP_UNDLN,
                     "UNDLINE %s %s",
                     parv[1], parv[2]);

  if (!IsClient(source_p) || match(parv[1], me.name))
    return 0;

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_UNDLINE))
  {
    if (remove_dline_match(addr))
    {
      sendto_one(source_p, ":%s NOTICE %s :D-Line for [%s] is removed",
                 me.name, source_p->name, addr);
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s has removed the D-Line for: [%s]",
                           get_oper_name(source_p), addr);
      ilog(LOG_TYPE_DLINE, "%s removed D-Line for [%s]",
           get_oper_name(source_p), addr);
    }
    else
      sendto_one(source_p, ":%s NOTICE %s :No D-Line for [%s] found",
                 me.name, source_p->name, addr);
  }

  return 0;
}

static struct Message dline_msgtab =
{
  "DLINE", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_dline, m_ignore, mo_dline, m_ignore }
};

static struct Message undline_msgtab =
{
  "UNDLINE", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_undline, m_ignore, mo_undline, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&dline_msgtab);
  mod_add_cmd(&undline_msgtab);
  add_capability("DLN", CAP_DLN, 1);
  add_capability("UNDLN", CAP_UNDLN, 1);
}

static void
module_exit(void)
{
  mod_del_cmd(&dline_msgtab);
  mod_del_cmd(&undline_msgtab);
  delete_capability("UNDLN");
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
