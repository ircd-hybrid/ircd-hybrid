/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2003-2014 ircd-hybrid development team
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

/*! \file m_xline.c
 * \brief Includes required functions for processing the XLINE/UNXLINE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "conf.h"
#include "numeric.h"
#include "log.h"
#include "send.h"
#include "s_serv.h"
#include "parse.h"
#include "modules.h"
#include "conf_db.h"
#include "memory.h"


static void
check_xline(struct MaskItem *conf)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, local_client_list.head)
  {
    struct Client *client_p = ptr->data;

    if (IsDead(client_p))
      continue;

    if (!match(conf->name, client_p->info))
      conf_try_ban(client_p, conf);
  }
}

/* static int remove_tkline_match(const char *host, const char *user)
 *
 * Inputs:      gecos
 * Output:      returns YES on success, NO if no tkline removed.
 * Side effects: Any matching tklines are removed.
 */
static int
remove_xline_match(const char *gecos)
{
  dlink_node *ptr = NULL, *next_ptr = NULL;

  DLINK_FOREACH_SAFE(ptr, next_ptr, xconf_items.head)
  {
    struct MaskItem *conf = ptr->data;

    if (!IsConfDatabase(conf))
      continue;

    if (!irccmp(gecos, conf->name))
    {
      conf_free(conf);
      return 1;
    }
  }

  return 0;
}

static void
remove_xline(struct Client *source_p, const char *gecos)
{
  if (remove_xline_match(gecos))
  {
    sendto_one(source_p,
               ":%s NOTICE %s :X-Line for [%s] is removed",
               me.name, source_p->name, gecos);
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has removed the X-Line for: [%s]",
                         get_oper_name(source_p), gecos);
    ilog(LOG_TYPE_XLINE, "%s removed X-Line for [%s]",
         get_oper_name(source_p), gecos);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :No X-Line for %s",
               me.name, source_p->name, gecos);
}

/* valid_xline()
 *
 * inputs       - client to complain to, gecos, reason, whether to complain
 * outputs      - 1 for valid, else 0
 * side effects - complains to client, when warn != 0
 */
static int
valid_xline(struct Client *source_p, const char *gecos, const char *reason)
{
  if (EmptyString(reason))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "XLINE");
    return 0;
  }

  if (!valid_wild_card_simple(gecos))
  {
    sendto_one(source_p, ":%s NOTICE %s :Please include at least %d non-wildcard characters with the xline",
               me.name, source_p->name, ConfigFileEntry.min_nonwildcard_simple);
    return 0;
  }

  return 1;
}

/* write_xline()
 *
 * inputs       - client taking credit for xline, gecos, reason, xline type
 * outputs      - none
 * side effects - when successful, adds an xline to the conf
 */
static void
write_xline(struct Client *source_p, char *gecos, char *reason,
            time_t tkline_time)
{
  struct MaskItem *conf = conf_make(CONF_XLINE);

  collapse(gecos);
  conf->name = xstrdup(gecos);
  conf->reason = xstrdup(reason);
  conf->setat = CurrentTime;

  SetConfDatabase(conf);

  if (tkline_time != 0)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s added temporary %d min. X-Line for [%s] [%s]",
                         get_oper_name(source_p), (int)tkline_time/60,
                         conf->name, conf->reason);
    sendto_one(source_p, ":%s NOTICE %s :Added temporary %d min. X-Line [%s]",
               MyConnect(source_p) ? me.name : ID_or_name(&me, source_p),
               source_p->name, (int)tkline_time/60, conf->name);
    ilog(LOG_TYPE_XLINE, "%s added temporary %d min. X-Line for [%s] [%s]",
         source_p->name, (int)tkline_time/60, conf->name, conf->reason);
    conf->until = CurrentTime + tkline_time;
  }
  else
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s added X-Line for [%s] [%s]",
                         get_oper_name(source_p), conf->name,
                         conf->reason);
    sendto_one(source_p,
               ":%s NOTICE %s :Added X-Line [%s] [%s]",
               MyConnect(source_p) ? me.name : ID_or_name(&me, source_p),
               source_p->name, conf->name, conf->reason);
    ilog(LOG_TYPE_XLINE, "%s added X-Line for [%s] [%s]",
         get_oper_name(source_p), conf->name, conf->reason);
  }

  check_xline(conf);
}

static void
relay_xline(struct Client *source_p, char *parv[])
{
  struct MaskItem *conf = NULL;
  int t_sec;

  t_sec = atoi(parv[3]);

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER,
                     "XLINE %s %s %s :%s",
                     parv[1], parv[2], parv[3], parv[4]);

  if (match(parv[1], me.name))
    return;

  if (HasFlag(source_p, FLAGS_SERVICE) || find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_XLINE))
  {
    if ((conf = find_matching_name_conf(CONF_XLINE, parv[2], NULL, NULL, 0)))
    {
      sendto_one(source_p, ":%s NOTICE %s :[%s] already X-Lined by [%s] - %s",
                 ID_or_name(&me, source_p),
                 ID_or_name(source_p, source_p),
                 parv[2], conf->name, conf->reason);
      return;
    }

    write_xline(source_p, parv[2], parv[4], t_sec);
  }
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
static int
mo_xline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char *reason = NULL;
  char *gecos = NULL;
  struct MaskItem *conf = NULL;
  char *target_server = NULL;
  time_t tkline_time = 0;

  if (!HasOFlag(source_p, OPER_FLAG_XLINE))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS), me.name,
               source_p->name, "xline");
    return 0;
  }

  /*
   * XLINE <gecos> <time> ON <mask> :<reason>
   * XLINE <gecos> ON <mask> :<reason>
   */
  if (parse_aline("XLINE", source_p, parc, parv, 0, &gecos, NULL,
                  &tkline_time, &target_server, &reason) < 0)
    return 0;

  if (target_server != NULL)
  {
    /* if a given expire time is given, ENCAP it */
    if (tkline_time != 0)
      sendto_match_servs(source_p, target_server, CAP_ENCAP,
                         "ENCAP %s XLINE %d %s 0 :%s",
                         target_server, (int)tkline_time, gecos, reason);
    else
      sendto_match_servs(source_p, target_server, CAP_CLUSTER,
                         "XLINE %s %s %d :%s",
                         target_server, gecos, (int)tkline_time, reason);

    /* Allow ON to apply local xline as well if it matches */
    if (match(target_server, me.name))
      return 0;
  }
  else
  {
    if (tkline_time != 0)
      cluster_a_line(source_p, "ENCAP", CAP_ENCAP, SHARED_XLINE,
                     "XLINE %d %s 0 :%s", (int)tkline_time, gecos, reason);
    else
      cluster_a_line(source_p, "XLINE", CAP_KLN, SHARED_XLINE,
                     "%s 0 :%s", gecos, reason);
  }

  if (!valid_xline(source_p, gecos, reason))
    return 0;

  if ((conf = find_matching_name_conf(CONF_XLINE, gecos, NULL, NULL, 0)))
  {
    sendto_one(source_p, ":%s NOTICE %s :[%s] already X-Lined by [%s] - %s",
               me.name, source_p->name, gecos,
               conf->name, conf->reason);
    return 0;
  }

  write_xline(source_p, gecos, reason, tkline_time);
  return 0;
}

/* ms_xline()
 *
 * inputs	- oper, target server, xline, {type}, reason
 *
 * outputs	- none
 * side effects	- propagates xline, applies it if we are a target
 */
static int
ms_xline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (parc != 5 || EmptyString(parv[4]))
    return 0;

  if (!IsClient(source_p))
    return 0;

  if (!valid_xline(source_p, parv[2], parv[4]))
    return 0;

  relay_xline(source_p, parv);
  return 0;
}

/* me_xline()
 *
 * inputs	- server
 *		- client (oper)
 *		- parc number of arguments
 *		- parv list of arguments
 * via parv[]
 * parv[1] = target server
 * parv[2] = xline
 * parv[3] = time
 * parv[4] = reason
 *
 * outputs	- none
 * side effects	-
 */
static int
me_xline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (!IsClient(source_p) || parc != 5)
    return 0;

  relay_xline(source_p, parv);
  return 0;
}

/* mo_unxline()
 *
 * inputs	- pointer to server
 *		- pointer to client
 *		- parameter count
 *		- parameter list
 * output	-
 * side effects - removes a xline
 */
static int
mo_unxline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  char *gecos = NULL;
  char *target_server = NULL;

  if (!HasOFlag(source_p, OPER_FLAG_UNXLINE))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS), me.name,
               source_p->name, "unxline");
    return 0;
  }

  /* UNXLINE bill ON irc.server.com */
  if (parse_aline("UNXLINE", source_p, parc, parv, 0, &gecos,
                  NULL, NULL, &target_server, NULL) < 0)
    return 0;

  if (target_server != NULL)
  {
    sendto_match_servs(source_p, target_server, CAP_CLUSTER,
                       "UNXLINE %s %s", target_server, gecos);

    /* Allow ON to apply local unxline as well if it matches */
    if (match(target_server, me.name))
      return 0;
  }
  else
    cluster_a_line(source_p, "UNXLINE", CAP_CLUSTER, SHARED_UNXLINE,
                   "%s", gecos);

  remove_xline(source_p, gecos);
  return 0;
}

/* ms_unxline()
 *
 * inputs	- oper, target server, gecos
 * outputs	- none
 * side effects	- propagates unxline, applies it if we are a target
 */
static int
ms_unxline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  if (parc != 3)
    return 0;

  if (!IsClient(source_p) || EmptyString(parv[2]))
    return 0;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER,
                     "UNXLINE %s %s", parv[1], parv[2]);

  if (match(parv[1], me.name))
    return 0;

  if (HasFlag(source_p, FLAGS_SERVICE) || find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_UNXLINE))
    remove_xline(source_p, parv[2]);
  return 0;
}

static struct Message xline_msgtab =
{
  "XLINE", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_xline, me_xline, mo_xline, m_ignore }
};

static struct Message unxline_msgtab =
{
  "UNXLINE", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_unxline, m_ignore, mo_unxline, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&xline_msgtab);
  mod_add_cmd(&unxline_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&xline_msgtab);
  mod_del_cmd(&unxline_msgtab);
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
