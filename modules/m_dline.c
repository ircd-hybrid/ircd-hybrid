/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_dline.c: Bans a user.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_misc.h"
#include "send.h"
#include "hash.h"
#include "handlers.h"
#include "s_serv.h"
#include "msg.h"
#include "s_gline.h"
#include "parse.h"
#include "modules.h"
#include "irc_getnameinfo.h"


static void mo_dline(struct Client *, struct Client *, int, char *[]);
static void mo_undline(struct Client *, struct Client *, int, char *[]);

static int remove_tdline_match(const char *);

struct Message dline_msgtab = {
  "DLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   {m_unregistered, m_not_oper, rfc1459_command_send_error, m_ignore, mo_dline, m_ignore}
};

struct Message undline_msgtab = {
  "UNDLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   {m_unregistered, m_not_oper, rfc1459_command_send_error, m_ignore, mo_undline, m_ignore}
};

void
_modinit(void)
{
  mod_add_cmd(&dline_msgtab);
  mod_add_cmd(&undline_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&dline_msgtab);
  mod_del_cmd(&undline_msgtab);
}

const char *_version = "$Revision$";

static char buffer[IRCD_BUFSIZE];


/* apply_tdline()
 *
 * inputs	-
 * output	- NONE
 * side effects	- tkline as given is placed
 */
static void
apply_tdline(struct Client *source_p, struct ConfItem *conf,
	     const char *current_date, int tkline_time)
{
  struct AccessItem *aconf;

  aconf = map_to_conf(conf);
  aconf->hold = CurrentTime + tkline_time;

  add_temp_line(conf);
  sendto_realops_flags(UMODE_ALL, L_ALL,
		       "%s added temporary %d min. D-Line for [%s] [%s]",
		       get_oper_name(source_p), tkline_time/60,
		       aconf->host, aconf->reason);

  sendto_one(source_p, ":%s NOTICE %s :Added temporary %d min. D-Line [%s]",
	     MyConnect(source_p) ? me.name : ID_or_name(&me, source_p->from),
             source_p->name, tkline_time/60, aconf->host);
  ilog(L_TRACE, "%s added temporary %d min. D-Line for [%s] [%s]",
       source_p->name, tkline_time/60, aconf->host, aconf->reason);
  log_oper_action(LOG_TEMP_DLINE_TYPE, source_p, "[%s@%s] [%s]\n",
		  aconf->user, aconf->host, aconf->reason);
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
static void
mo_dline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char def_reason[] = "No reason";
  char *dlhost, *oper_reason, *reason;
  const char *creason;
  const struct Client *target_p = NULL;
  struct irc_ssaddr daddr;
  struct ConfItem *conf=NULL;
  struct AccessItem *aconf=NULL;
  time_t tkline_time=0;
  int bits, t;
  const char *current_date = NULL;
  time_t cur_time;
  char hostip[HOSTIPLEN];

  if (!IsOperK(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "kline");
    return;
  }

  if (parse_aline("DLINE", source_p,  parc, parv, AWILD, &dlhost,
                  NULL, &tkline_time, NULL, &reason) < 0)
    return;

  if ((t = parse_netmask(dlhost, NULL, &bits)) == HM_HOST)
  {
    if ((target_p = find_chasing(client_p, source_p, dlhost, NULL)) == NULL)
      return;

    if (!MyConnect(target_p))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :Can't DLINE nick on another server",
                 me.name, source_p->name);
      return;
    }

    if (IsExemptKline(target_p))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :%s is E-lined", me.name,
                 source_p->name, target_p->name);
      return;
    }

    irc_getnameinfo((struct sockaddr *)&target_p->localClient->ip,
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
    return;
  }

#ifdef IPV6
  if (t == HM_IPV6)
    t = AF_INET6;
  else
#endif
    t = AF_INET;

  parse_netmask(dlhost, &daddr, NULL);

  if ((aconf = find_dline_conf(&daddr, t)) != NULL)
  {
    creason = aconf->reason ? aconf->reason : def_reason;
    if (IsConfExemptKline(aconf))
      sendto_one(source_p,
		 ":%s NOTICE %s :[%s] is (E)d-lined by [%s] - %s",
		 me.name, source_p->name, dlhost, aconf->host, creason);
    else
      sendto_one(source_p,
		 ":%s NOTICE %s :[%s] already D-lined by [%s] - %s",
		 me.name, source_p->name, dlhost, aconf->host, creason);
    return;
  }

  cur_time = CurrentTime;
  current_date = smalldate(cur_time);

  /* Look for an oper reason */
  if ((oper_reason = strchr(reason, '|')) != NULL)
    *oper_reason++ = '\0';

  if (!valid_comment(source_p, reason, YES))
    return;

  conf = make_conf_item(DLINE_TYPE);
  aconf = map_to_conf(conf);
  DupString(aconf->host, dlhost);

  if (tkline_time != 0)
  {
    ircsprintf(buffer, "Temporary D-line %d min. - %s (%s)",
	       (int)(tkline_time/60), reason, current_date);
    DupString(aconf->reason, buffer);
    if (oper_reason != NULL)
      DupString(aconf->oper_reason, oper_reason);
    apply_tdline(source_p, conf, current_date, tkline_time);
  }
  else
  {
    ircsprintf(buffer, "%s (%s)", reason, current_date);
    DupString(aconf->reason, buffer);
    if (oper_reason != NULL)
      DupString(aconf->oper_reason, oper_reason);
    add_conf_by_address(CONF_DLINE, aconf);
    write_conf_line(source_p, conf, current_date, cur_time);
  }

  rehashed_klines = 1;
}

/* static int remove_tdline_match(const char *host, const char *user)
 * Input: An ip to undline.
 * Output: returns YES on success, NO if no tdline removed.
 * Side effects: Any matching tdlines are removed.
 */
static int
remove_tdline_match(const char *cidr)
{
  struct AccessItem *td_conf;
  dlink_node *td_node;
  struct irc_ssaddr addr, caddr;
  int nm_t, cnm_t, bits, cbits;
  nm_t = parse_netmask(cidr, &addr, &bits);

  DLINK_FOREACH(td_node, temporary_dlines.head)
  {
    td_conf = map_to_conf(td_node->data);
    cnm_t   = parse_netmask(td_conf->host, &caddr, &cbits);

    if (cnm_t != nm_t)
      continue;

    if((nm_t==HM_HOST && !irccmp(td_conf->host, cidr)) ||
       (nm_t==HM_IPV4 && bits==cbits && match_ipv4(&addr, &caddr, bits))
#ifdef IPV6
       || (nm_t==HM_IPV6 && bits==cbits && match_ipv6(&addr, &caddr, bits))
#endif
      )
    {
      dlinkDelete(td_node, &temporary_dlines);
      delete_one_address_conf(td_conf->host, td_conf);
      return 1;
    }
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
static void
mo_undline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  const char *cidr = NULL;

  if (!IsOperUnkline(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "undline");
    return;
  }

  cidr = parv[1];

  if (remove_tdline_match(cidr))
  {
    sendto_one(source_p,
              ":%s NOTICE %s :Un-Dlined [%s] from temporary D-Lines",
              me.name, source_p->name, cidr);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the temporary D-Line for: [%s]",
                         get_oper_name(source_p), cidr);
    ilog(L_NOTICE, "%s removed temporary D-Line for [%s]", source_p->name, cidr);
    return;
  }

  if (remove_conf_line(DLINE_TYPE, source_p, cidr, NULL) > 0)
  {
    sendto_one(source_p, ":%s NOTICE %s :D-Line for [%s] is removed",
               me.name, source_p->name, cidr);
    sendto_realops_flags(UMODE_ALL, L_ALL,
			 "%s has removed the D-Line for: [%s]",
			 get_oper_name(source_p), cidr);
    ilog(L_NOTICE, "%s removed D-Line for [%s]",
         get_oper_name(source_p), cidr);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :No D-Line for [%s] found",
               me.name, source_p->name, cidr);
}
