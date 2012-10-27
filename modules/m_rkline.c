/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_kline.c: Bans a user.
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
#include "tools.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "pcre.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
#include "list.h"
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
#include "tools.h"

static void me_rkline(struct Client *, struct Client *, int, char *[]);
static void mo_rkline(struct Client *, struct Client *, int, char *[]);
static void ms_rkline(struct Client *, struct Client *, int, char *[]);

static void me_unrkline(struct Client *, struct Client *, int, char *[]);
static void mo_unrkline(struct Client *, struct Client *, int, char *[]);
static void ms_unrkline(struct Client *, struct Client *, int, char *[]);
/* Local function prototypes */
static int already_placed_rkline(struct Client *, const char *, const char *);
static void apply_rkline(struct Client *, struct ConfItem *, const char *, time_t);
static void apply_trkline(struct Client *, struct ConfItem *, int);

static char buffer[IRCD_BUFSIZE];
static int remove_trkline_match(const char *, const char *);

struct Message rkline_msgtab = {
  "RKLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   {m_unregistered, m_not_oper, ms_rkline, me_rkline, mo_rkline, m_ignore}
};

struct Message unrkline_msgtab = {
  "UNRKLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   {m_unregistered, m_not_oper, ms_unrkline, me_unrkline, mo_unrkline, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&rkline_msgtab);
  mod_add_cmd(&unrkline_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&rkline_msgtab);
  mod_del_cmd(&unrkline_msgtab);
}

const char *_version = "$Revision$";
#endif

/* mo_rkline()
 *
 * inputs	- pointer to server
 *		- pointer to client
 *		- parameter count
 *		- parameter list
 * output	-
 * side effects - rk line is added
 */
static void
mo_rkline(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  pcre *exp_user = NULL, *exp_host = NULL;
  const char *errptr = NULL;
  char *reason = NULL;
  char *oper_reason = NULL;
  char *user = NULL;
  char *host = NULL;
  const char *current_date = NULL;
  char *target_server = NULL;
  struct ConfItem *conf = NULL;
  struct AccessItem *aconf = NULL;
  time_t tkline_time = 0;
  time_t cur_time = 0;

  if (!IsAdmin(source_p) || !IsOperK(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "rkline");
    return;
  }

  if (parse_aline("RKLINE", source_p, parc, parv, NOUSERLOOKUP, &user,
                  &host, &tkline_time, &target_server, &reason) < 0)
    return;

  if (target_server != NULL)
  {
    if (HasID(source_p))
    {
      sendto_server(NULL, source_p, NULL, CAP_KLN|CAP_TS6, NOCAPS, LL_ICLIENT,
                    ":%s RKLINE %s %lu %s %s :%s",
                    source_p->id, target_server, (unsigned long)tkline_time,
                    user, host, reason);
      sendto_server(NULL, source_p, NULL, CAP_KLN, CAP_TS6, LL_ICLIENT,
                    ":%s RKLINE %s %lu %s %s :%s",
                    source_p->name, target_server, (unsigned long)tkline_time,
                    user, host, reason);
    }
    else
      sendto_server(NULL, source_p, NULL, CAP_KLN, NOCAPS, LL_ICLIENT,
                    ":%s RKLINE %s %lu %s %s :%s",
                    source_p->name, target_server, (unsigned long)tkline_time,
                    user, host, reason);

    /* Allow ON to apply local kline as well if it matches */
    if (!match(target_server, me.name))
      return;
  }
#if 0
  else
    cluster_a_line(source_p, "RKLINE", CAP_KLN, SHARED_KLINE,
		   "%d %s %s :%s", tkline_time, user, host, reason);
#endif

  if (already_placed_rkline(source_p, user, host))
    return;

  /* Look for an oper reason */
  if ((oper_reason = strchr(reason, '|')) != NULL)
    *oper_reason++ = '\0';

  if (!(exp_user = ircd_pcre_compile(user, &errptr)) ||
      !(exp_host = ircd_pcre_compile(host, &errptr)))
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
           "Failed to add regular expression based K-Line: %s", errptr);
    return;
  }

  cur_time = CurrentTime;
  current_date = smalldate(cur_time);
  conf = make_conf_item(RKLINE_TYPE);
  aconf = map_to_conf(conf);

  DupString(aconf->host, host);
  DupString(aconf->user, user);

  aconf->regexuser = exp_user;
  aconf->regexhost = exp_host;

  if (tkline_time != 0)
  {
    ircsprintf(buffer, "Temporary RK-line %d min. - %s (%s)",
               (int)(tkline_time/60), reason, current_date);
    DupString(aconf->reason, buffer);

    if (oper_reason != NULL)
      DupString(aconf->oper_reason, oper_reason);
    apply_trkline(source_p, conf, tkline_time);
  }
  else
  {
    ircsprintf(buffer, "%s (%s)", reason, current_date);
    DupString(aconf->reason, buffer);

    if (oper_reason != NULL)
      DupString(aconf->oper_reason, oper_reason);
    apply_rkline(source_p, conf, current_date, cur_time);
  }
}

/* me_rkline - handle remote rkline. no propagation */
static void
me_rkline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct ConfItem *conf = NULL;
  struct AccessItem *aconf = NULL;
  int tkline_time;
  const char *current_date = NULL;
  time_t cur_time;
  char *kuser, *khost, *kreason, *oper_reason;

  if (parc != 6 || EmptyString(parv[5]))
    return;

  if (!match(parv[1], me.name))
    return;

  tkline_time = valid_tkline(parv[2], TK_SECONDS);
  kuser = parv[3];
  khost = parv[4];
  kreason = parv[5];

  if ((oper_reason = strchr(kreason, '|')) != NULL)
    *oper_reason++ = '\0';

  cur_time = CurrentTime;
  current_date = smalldate(cur_time);

  if (find_matching_name_conf(ULINE_TYPE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_KLINE))
  {
    pcre *exp_user = NULL, *exp_host = NULL;
    const char *errptr = NULL;

    if (!IsClient(source_p) ||
        already_placed_rkline(source_p, kuser, khost))
      return;

    if (!(exp_user = ircd_pcre_compile(kuser, &errptr)) ||
        !(exp_host = ircd_pcre_compile(khost, &errptr)))
    {
      sendto_realops_flags(UMODE_ALL, L_ALL,
             "Failed to add regular expression based K-Line: %s", errptr);
      return;
    }

    conf = make_conf_item(RKLINE_TYPE);
    aconf = map_to_conf(conf);
    DupString(aconf->host, khost);
    DupString(aconf->user, kuser);

    aconf->regexuser = exp_user;
    aconf->regexhost = exp_host;

    if (tkline_time)
    {
      ircsprintf(buffer, "Temporary RK-line %d min. - %s (%s)",
                 (int)(tkline_time/60), kreason, current_date);
      DupString(aconf->reason, buffer);

      if (oper_reason != NULL)
        DupString(aconf->oper_reason, oper_reason);
      apply_trkline(source_p, conf, tkline_time);
    }
    else
    {
      ircsprintf(buffer, "%s (%s)", kreason, current_date);
      DupString(aconf->reason, buffer);

      if (oper_reason != NULL)
        DupString(aconf->oper_reason, oper_reason);
      apply_rkline(source_p, conf, current_date, cur_time);
    }
  }
}

static void
ms_rkline(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  if (parc != 6 || EmptyString(parv[5]))
    return;

  /* parv[0]  parv[1]        parv[2]      parv[3]  parv[4]  parv[5] */
  /* oper     target_server  tkline_time  user     host     reason */
  sendto_match_servs(source_p, parv[1], CAP_KLN,
                     "RKLINE %s %s %s %s :%s",
                     parv[1], parv[2], parv[3], parv[4], parv[5]);

  me_rkline(client_p, source_p, parc, parv);
}

/* apply_rkline()
 *
 * inputs	-
 * output	- NONE
 * side effects	- kline as given, is added to the hashtable
 *		  and conf file
 */
static void 
apply_rkline(struct Client *source_p, struct ConfItem *conf,
             const char *current_date, time_t cur_time)
{
  write_conf_line(source_p, conf, current_date, cur_time);
  /* Now, activate kline against current online clients */
  rehashed_klines = 1;
}

/* apply_trkline()
 *
 * inputs	-
 * output	- NONE
 * side effects	- tkline as given is placed
 */
static void
apply_trkline(struct Client *source_p, struct ConfItem *conf,
             int tkline_time)
{
  struct AccessItem *aconf = map_to_conf(conf);

  aconf->hold = CurrentTime + tkline_time;
  add_temp_line(conf);
  sendto_realops_flags(UMODE_ALL, L_ALL,
		       "%s added temporary %d min. RK-Line for [%s@%s] [%s]",
		       get_oper_name(source_p), tkline_time/60,
		       aconf->user, aconf->host,
		       aconf->reason);
  sendto_one(source_p, ":%s NOTICE %s :Added temporary %d min. RK-Line [%s@%s]",
             MyConnect(source_p) ? me.name : ID_or_name(&me, source_p->from),
             source_p->name, tkline_time/60, aconf->user, aconf->host);
  ilog(L_TRACE, "%s added temporary %d min. RK-Line for [%s@%s] [%s]",
       source_p->name, tkline_time/60,
       aconf->user, aconf->host, aconf->reason);
  rehashed_klines = 1;
}

/* already_placed_rkline()
 * inputs	- user to complain to, username & host to check for
 * outputs	- returns 1 on existing K-line, 0 if doesn't exist
 * side effects	- notifies source_p if the K-line already exists
 */
static int
already_placed_rkline(struct Client *source_p, const char *user, const char *host)
{
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, rkconf_items.head)
  {
    struct AccessItem *aptr = map_to_conf(ptr->data);

    if (!strcmp(user, aptr->user) &&
        !strcmp(aptr->host, host))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :[%s@%s] already RK-Lined by [%s@%s] - %s",
                 me.name, source_p->name, user, host, aptr->user,
                 aptr->host, aptr->reason ? aptr->reason : "No reason");
      return 1;
    }
  }

  return 0;
}

/*
 * mo_unrkline
 *      parv[0] = sender
 *      parv[1] = address to remove
 */
static void
mo_unrkline(struct Client *client_p,struct Client *source_p,
           int parc, char *parv[])
{
  char *target_server = NULL;
  char *user, *host;

  if (!IsAdmin(source_p) || !IsOperUnkline(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "unrkline");
    return;
  }

  if (parc < 2 || *parv[1] == '\0')
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "UNRKLINE");
    return;
  }

  if (parse_aline("UNRKLINE", source_p, parc, parv, NOUSERLOOKUP, &user,
                  &host, NULL, &target_server, NULL) < 0)
    return;

  if (target_server != NULL)
  {
    sendto_match_servs(source_p, target_server, CAP_UNKLN,
                       "UNRKLINE %s %s %s",
                       target_server, user, host);

    /* Allow ON to apply local unkline as well if it matches */
    if (!match(target_server, me.name))
      return;
  }
#if 0
  else
    cluster_a_line(source_p, "UNRKLINE", CAP_UNKLN, SHARED_UNKLINE,
                   "%s %s", user, host);
#endif

  if (remove_trkline_match(host, user))
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Un-klined [%s@%s] from temporary RK-Lines",
               me.name, source_p->name, user, host);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the temporary RK-Line for: [%s@%s]",
                         get_oper_name(source_p), user, host);
    ilog(L_NOTICE, "%s removed temporary RK-Line for [%s@%s]",
         source_p->name, user, host);
    return;
  }

  if (remove_conf_line(RKLINE_TYPE, source_p, user, host) > 0)
  {
    sendto_one(source_p, ":%s NOTICE %s :RK-Line for [%s@%s] is removed", 
               me.name, source_p->name, user,host);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the RK-Line for: [%s@%s]",
                         get_oper_name(source_p), user, host);
    ilog(L_NOTICE, "%s removed RK-Line for [%s@%s]",
         source_p->name, user, host);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :No RK-Line for [%s@%s] found", 
               me.name, source_p->name, user, host);
}

/* me_unrkline()
 *
 * inputs	- server
 *		- client
 *		- parc
 *		- parv
 * outputs	- none
 * side effects	- if server is authorized, rkline is removed
 *                does not propagate message
 */
static void
me_unrkline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  const char *user = NULL, *host = NULL;

  if (parc != 4 || EmptyString(parv[3]))
    return;

  user = parv[2];
  host = parv[3];

  if (!IsClient(source_p) || !match(parv[1], me.name))
    return;

  if (find_matching_name_conf(ULINE_TYPE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_UNKLINE))
  {
    if (remove_trkline_match(host, user))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :Un-klined [%s@%s] from temporary RK-Lines",
                 me.name, source_p->name, user, host);
      sendto_realops_flags(UMODE_ALL, L_ALL,  
                           "%s has removed the temporary RK-Line for: [%s@%s]",
                           get_oper_name(source_p), user, host);
      ilog(L_NOTICE, "%s removed temporary RK-Line for [%s@%s]",
           source_p->name, user, host);
      return;
    }

    if (remove_conf_line(RKLINE_TYPE, source_p, user, host) > 0)
    {
      sendto_one(source_p, ":%s NOTICE %s :RK-Line for [%s@%s] is removed",
                 me.name, source_p->name, user, host);
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "%s has removed the RK-Line for: [%s@%s]",
                           get_oper_name(source_p), user, host);

      ilog(L_NOTICE, "%s removed RK-Line for [%s@%s]",
           source_p->name, user, host);
    }
    else
      sendto_one(source_p, ":%s NOTICE %s :No RK-Line for [%s@%s] found",
                 me.name, source_p->name, user, host);
  }
}

/* ms_unrkline - propagates and handles a remote unrkline message */
static void
ms_unrkline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  if (parc != 4 || EmptyString(parv[3]))
    return;

  sendto_match_servs(source_p, parv[1], CAP_UNKLN,
                     "UNRKLINE %s %s %s",
                     parv[1], parv[2], parv[3]);

  me_unrkline(client_p, source_p, parc, parv);
}

/* static int remove_rtkline_match(const char *host, const char *user)
 * Input: A hostname, a username to unrkline.
 * Output: returns YES on success, NO if no trkline removed.
 * Side effects: Any matching trklines are removed.
 */
static int
remove_trkline_match(const char *const host,
                     const char *const user)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, temporary_rklines.head)
  {
    struct ConfItem *conf = ptr->data;
    struct AccessItem *aptr = map_to_conf(ptr->data);

    if (!strcmp(user, aptr->user) &&
        !strcmp(aptr->host, host))
    {
      dlinkDelete(ptr, &temporary_rklines);
      free_dlink_node(ptr);
      delete_conf_item(conf);
      return 1;
    }
  }

  return 0;
}
