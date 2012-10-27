/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_rxline.c: xlines a user with regular expression support.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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
#include "parse.h"
#include "modules.h"
#include "resv.h"

static void mo_rxline(struct Client *, struct Client *, int, char *[]);
static void ms_rxline(struct Client *, struct Client *, int, char *[]);
static void mo_unrxline(struct Client *, struct Client *, int, char *[]);
static void ms_unrxline(struct Client *, struct Client *, int, char *[]);

static int valid_xline(struct Client *, char *, char *, int);
static void write_rxline(struct Client *, const char *, char *, time_t);
static void remove_xline(struct Client *, char *);
static int remove_txline(const char *);

struct Message rxline_msgtab = {
  "RXLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_rxline, m_ignore, mo_rxline, m_ignore }
};

struct Message unrxline_msgtab = {
  "UNRXLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_unrxline, m_ignore, mo_unrxline, m_ignore }
};

void
_modinit(void)
{
  mod_add_cmd(&rxline_msgtab);
  mod_add_cmd(&unrxline_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&rxline_msgtab);
  mod_del_cmd(&unrxline_msgtab);
}

const char *_version = "$Revision$";

static int
already_placed_rxline(struct Client *source_p, const char *gecos)
{
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, rxconf_items.head)
  {
    struct ConfItem *aptr = ptr->data;
    const struct MatchItem *match_item = map_to_conf(aptr);

    if (!strcmp(gecos, aptr->name))
    {
      sendto_one(source_p, ":%s NOTICE %s :[%s] already RX-Lined by [%s] - %s",
                 me.name, source_p->name, gecos,
                 aptr->name, match_item->reason);
      return 1;
    }
  }

  return 0;
}

/* mo_rxline()
 *
 * inputs	- pointer to server
 *		- pointer to client
 *		- parameter count
 *		- parameter list
 * output	-
 * side effects - regular expression x line is added
 *
 */
static void
mo_rxline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char *reason = NULL;
  char *gecos = NULL;
  char *target_server = NULL;
  time_t tkline_time = 0;

  if (!IsOperX(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "rxline");
    return;
  }

  if (parse_aline("RXLINE", source_p, parc, parv, AWILD, &gecos, 
                  NULL, &tkline_time, NULL, &reason) < 0)
    return;

  if (target_server != NULL)
  {
    sendto_match_servs(source_p, target_server, CAP_CLUSTER,
                       "RXLINE %s %s %d :%s",
                       target_server, gecos, (int)tkline_time, reason);

    /* Allow ON to apply local rxline as well if it matches */
    if (!match(target_server, me.name))
      return;
  }

#if 0
  cluster_a_line(source_p, "RXLINE", CAP_KLN, SHARED_XLINE,
		 "%s 0 :%s", gecos, reason);
#endif

  if (!valid_xline(source_p, gecos, reason, 0))
    return;

  if (!already_placed_rxline(source_p, gecos))
    write_rxline(source_p, gecos, reason, tkline_time);
}

/* ms_rxline()
 *
 * inputs       - oper, target server, rxline, {type}, reason
 *                deprecate {type} reserve for temp xlines later? XXX
 *
 * outputs      - none
 * side effects - propagates rxline, applies it if we are a target
 */
static void
ms_rxline(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  int t_sec = 0;

  if (parc != 5 || EmptyString(parv[4]))
    return;

  if (!IsClient(source_p))
    return;

  if (!valid_xline(source_p, parv[2], parv[4], 0))
    return;

  t_sec = atoi(parv[3]);
  /* XXX kludge! */
  if (t_sec < 3)
    t_sec = 0;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER,
                     "RXLINE %s %s %s :%s",
                     parv[1], parv[2], parv[3], parv[4]);

  if (!match(parv[1], me.name))
    return;

  if (find_matching_name_conf(ULINE_TYPE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_XLINE))
    if (!already_placed_rxline(source_p, parv[2]))
      write_rxline(source_p, parv[2], parv[4], t_sec);
}

static void
mo_unrxline(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  char *gecos = NULL;
  char *target_server = NULL;

  if (!IsOperX(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "unrxline");
    return;
  }

  if (parse_aline("UNRXLINE", source_p, parc, parv, 0, &gecos,
                  NULL, NULL, &target_server, NULL) < 0)
    return;

  if (target_server != NULL)
  {

    sendto_match_servs(source_p, target_server, CAP_CLUSTER,
                       "UNRXLINE %s %s", target_server, gecos);

    /* Allow ON to apply local unrxline as well if it matches */
    if (!match(target_server, me.name))
      return;
  }

#if 0
  cluster_a_line(source_p, "UNRXLINE", CAP_CLUSTER, SHARED_UNXLINE,
		 "%s", gecos);
#endif

  remove_xline(source_p, gecos);
}

/* ms_unrxline()
 *
 * inputs       - oper, target server, gecos
 * outputs      - none
 * side effects - propagates unrxline, applies it if we are a target
 */
static void
ms_unrxline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  if (parc != 3 || EmptyString(parv[2]))
    return;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER,
                     "UNRXLINE %s %s",
                     parv[1], parv[2]);

  if (!IsClient(source_p) || !match(parv[1], me.name))
    return;

  if (find_matching_name_conf(ULINE_TYPE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_UNXLINE))
    remove_xline(source_p, parv[2]);
}

/* valid_xline()
 *
 * inputs	- client to complain to, gecos, reason, whether to complain
 * outputs	- 1 for valid, else 0
 * side effects	- complains to client, when warn != 0
 */
static int
valid_xline(struct Client *source_p, char *gecos, char *reason, int warn)
{
  if (EmptyString(reason))
  {
    if (warn)
      sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
                 me.name, source_p->name, "RXLINE");
    return 0;
  }

  if (strchr(gecos, '"'))
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid character '\"'",
               me.name, source_p->name);
    return 0;
  }

  if (!valid_wild_card_simple(gecos))
  {
    if (warn)
      sendto_one(source_p, ":%s NOTICE %s :Please include at least %d non-wildcard characters with the rxline",
                 me.name, source_p->name, ConfigFileEntry.min_nonwildcard_simple);

    return 0;
  }

  return 1;
}

/* write_rxline()
 *
 * inputs	- client taking credit for rxline
 * outputs	- none
 * side effects	- when successful, adds an rxline to the conf
 */
static void
write_rxline(struct Client *source_p, const char *gecos, char *reason,
             time_t tkline_time)
{
  struct ConfItem *conf = NULL;
  struct MatchItem *match_item = NULL;
  const char *current_date = NULL;
  time_t cur_time = 0;
  void *exp_gecos = NULL;
  const char *errptr = NULL;

  if (!(exp_gecos = ircd_pcre_compile(gecos, &errptr)))
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
           "Failed to add regular expression based X-Line: %s", errptr);
    return;
  }

  conf = make_conf_item(RXLINE_TYPE);
  conf->regexpname = exp_gecos;

  match_item = map_to_conf(conf);

  DupString(conf->name, gecos);
  DupString(match_item->reason, reason);
  DupString(match_item->oper_reason, "");	/* XXX */

  cur_time = CurrentTime;
  current_date = smalldate(cur_time);

  if (tkline_time)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s added temporary %d min. RX-Line for [%s] [%s]",
                         get_oper_name(source_p), (int)tkline_time/60,
                         conf->name, match_item->reason);
    sendto_one(source_p, ":%s NOTICE %s :Added temporary %d min. RX-Line [%s]",
               MyConnect(source_p) ? me.name : ID_or_name(&me, source_p->from),
               source_p->name, (int)tkline_time/60, conf->name);
    ilog(L_TRACE, "%s added temporary %d min. RX-Line for [%s] [%s]",
         source_p->name, (int)tkline_time/60,
         conf->name, match_item->reason);
    match_item->hold = CurrentTime + tkline_time;
    add_temp_line(conf);
  }
  else
    write_conf_line(source_p, conf, current_date, cur_time);
  rehashed_klines = 1;
}

static void
remove_xline(struct Client *source_p, char *gecos)
{
  /* XXX use common temporary un function later */
  if (remove_txline(gecos))
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Un-rxlined [%s] from temporary RX-Lines",
               me.name, source_p->name, gecos);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the temporary RX-Line for: [%s]",
                         get_oper_name(source_p), gecos);
    ilog(L_NOTICE, "%s removed temporary RX-Line for [%s]",
         source_p->name, gecos);
    return;
  }

  if (remove_conf_line(RXLINE_TYPE, source_p, gecos, NULL) > 0)
  {
    sendto_one(source_p, ":%s NOTICE %s :RX-Line for [%s] is removed",
               me.name, source_p->name, gecos);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the RX-Line for: [%s]",
                         get_oper_name(source_p), gecos);
    ilog(L_NOTICE, "%s removed RX-Line for [%s]",
         get_oper_name(source_p), gecos);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :No RX-Line for %s",
               me.name, source_p->name, gecos);
}

/* static int remove_tkline_match(const char *host, const char *user)
 *
 * Inputs:	gecos
 * Output:	returns YES on success, NO if no tkline removed.
 * Side effects: Any matching tklines are removed.
 */
static int
remove_txline(const char *const gecos)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, temporary_rxlines.head)
  {
    struct ConfItem *conf = ptr->data;

    if (!strcmp(gecos, conf->name))
    {
      dlinkDelete(ptr, &temporary_rxlines);
      free_dlink_node(ptr);
      delete_conf_item(conf);
      return 1;
    }
  }

  return 0;
}
