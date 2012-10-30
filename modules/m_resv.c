/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_resv.c: Reserves(jupes) a nickname or channel.
 *
 *  Copyright (C) 2001-2002 Hybrid Development Team
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
#include "client.h"
#include "channel.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"
#include "log.h"
#include "resv.h"
#include "hash.h"


static void parse_resv(struct Client *, char *, int, char *);
static void remove_resv(struct Client *, const char *);


/* mo_resv()
 *   parv[0] = sender prefix
 *   parv[1] = channel/nick to forbid
 */
static void
mo_resv(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  char *resv = NULL;
  char *reason = NULL;
  char *target_server = NULL;
  time_t tkline_time = 0;

  /* RESV #channel ON irc.server.com :abuse
   * RESV kiddie ON irc.server.com :abuse
   */
  if (parse_aline("RESV", source_p, parc, parv,
		  AWILD, &resv, NULL, &tkline_time, &target_server, &reason) < 0)
    return;

  if (target_server != NULL)
  {
    /* if a given expire time is given, ENCAP it */
    if (tkline_time != 0)
      sendto_match_servs(source_p, target_server, CAP_ENCAP,
			 "ENCAP %s RESV %d %s 0 :%s",
			 target_server, (int)tkline_time, resv, reason);
    else
      sendto_match_servs(source_p, target_server, CAP_CLUSTER,
			 "RESV %s %s :%s",
			 target_server, resv, reason);
    /* Allow ON to apply local resv as well if it matches */
    if (!match(target_server, me.name))
      return;
  }
  else
  {
    /* RESV #channel :abuse
     * RESV kiddie :abuse
     */
    if (tkline_time != 0)
      cluster_a_line(source_p, "ENCAP", CAP_ENCAP, SHARED_RESV,
		     "RESV %d %s 0 : %s", (int)tkline_time, resv, reason);
    else
      cluster_a_line(source_p, "RESV", CAP_KLN, SHARED_RESV,
		     "%s : %s", resv, reason);
  }

  parse_resv(source_p, resv, (int)tkline_time, reason);
}

/* me_resv()
 *
 * inputs	- server
 *		- client (oper)
 *		- parc number of arguments
 *		- parv list of arguments
 * via parv[]
 * parv[0] = client name applying resv
 * parv[1] = tkline_time
 * parv[2] = name
 * parv[3] = 0
 * parv[4] = reason
 * parc should be 5
 *
 * outputs	- NONE
 * side effects -
 */
static void
me_resv(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if (parc != 5 || !IsClient(source_p))
    return;

  parse_resv(source_p, parv[2], atoi(parv[1]), parv[4]);
}

/* ms_resv()
 *   parv[0] = sender prefix
 *   parv[1] = target server
 *   parv[2] = channel/nick to resv
 *   parv[3] = reason
 */
static void
ms_resv(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if ((parc != 4) || EmptyString(parv[3]))
    return;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER,
                     "RESV %s %s :%s",
                     parv[1], parv[2], parv[3]);

  if (!IsClient(source_p) || !match(parv[1], me.name))
    return;

  if (HasFlag(source_p, FLAGS_SERVICE) || find_matching_name_conf(ULINE_TYPE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_RESV))
    parse_resv(source_p, parv[2], 0, parv[3]);
}

/* mo_unresv()
 *   parv[0] = sender prefix
 *   parv[1] = channel/nick to unforbid
 */
static void
mo_unresv(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  char *resv = NULL;
  char *reason = NULL;
  char *target_server = NULL;

  /* UNRESV #channel ON irc.server.com */
  /* UNRESV kiddie ON irc.server.com */
  if (parse_aline("UNRESV", source_p, parc, parv,
		  0, &resv, NULL, NULL, &target_server, &reason) < 0)
    return;

  if (target_server != NULL)
  {
    sendto_match_servs(source_p, target_server, CAP_CLUSTER,
                       "UNRESV %s %s",
                       target_server, resv);

    /* Allow ON to apply local unresv as well if it matches */
    if (!match(target_server, me.name))
      return;
  }
  else 
    cluster_a_line(source_p, "UNRESV", CAP_KLN, SHARED_UNRESV, resv);

  remove_resv(source_p, resv);
}

/* ms_unresv()
 *     parv[0] = sender prefix
 *     parv[1] = target server
 *     parv[2] = resv to remove
 */
static void
ms_unresv(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  if ((parc != 3) || EmptyString(parv[2]))
    return;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER,
                     "UNRESV %s %s",
                     parv[1], parv[2]);

  if (!IsClient(source_p) || !match(parv[1], me.name))
    return;

  if (HasFlag(source_p, FLAGS_SERVICE) || find_matching_name_conf(ULINE_TYPE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_UNRESV))
    remove_resv(source_p, parv[2]);
}

/* parse_resv()
 *
 * inputs	- source_p, NULL supported
 *		- thing to resv
 *		- time_t if tkline
 *		- reason
 * outputs	- none
 * side effects	- parse resv, create if valid
 */
static void
parse_resv(struct Client *source_p, char *name, int tkline_time, char *reason)
{
  struct ConfItem *conf = NULL;

  if (IsChanPrefix(*name))
  {
    struct ResvChannel *resv_p;

    if ((conf = create_channel_resv(name, reason, 0)) == NULL)
    {
      sendto_one(source_p,
	   ":%s NOTICE %s :A RESV has already been placed on channel: %s",
                   me.name, source_p->name, name);
      return;
    }

    resv_p = map_to_conf(conf);

    if (tkline_time != 0)
    {
      sendto_one(source_p,
		 ":%s NOTICE %s :A %d minute %s RESV has been placed on channel: %s",
                 me.name, source_p->name,
		 tkline_time/60,
                 (MyClient(source_p) ? "local" : "remote"), name);
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "%s has placed a %d minute %s RESV on channel: %s [%s]",
			   get_oper_name(source_p),
			   tkline_time/60,
			   (MyClient(source_p) ? "local" : "remote"),
			   resv_p->name, resv_p->reason);
      ilog(LOG_TYPE_IRCD, "%s added temporary %d min. RESV for [%s] [%s]",
	   source_p->name, (int)tkline_time/60,
	   conf->name, resv_p->reason);
      resv_p->hold = CurrentTime + tkline_time;
      add_temp_line(conf);
    }
    else
    {
      sendto_one(source_p,
		 ":%s NOTICE %s :A %s RESV has been placed on channel %s",
                 me.name, source_p->name,
                 (MyClient(source_p) ? "local" : "remote"), name);
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "%s has placed a %s RESV on channel %s : [%s]",
			   get_oper_name(source_p),
			   (MyClient(source_p) ? "local" : "remote"),
			   resv_p->name, resv_p->reason);
      write_conf_line(source_p, conf, NULL /* not used */, 0 /* not used */);
    }
  }
  else
  {
    struct MatchItem *resv_p = NULL;

    if (!valid_wild_card_simple(name))
    {
      sendto_one(source_p, ":%s NOTICE %s :Please include at least %d non-wildcard characters with the resv",
                 me.name, source_p->name, ConfigFileEntry.min_nonwildcard_simple);
      return;
    }

    if (!HasUMode(source_p, UMODE_ADMIN) && strpbrk(name, "*?#"))
    {
      sendto_one(source_p, ":%s NOTICE %s :You must be an admin to perform a "
                 "wildcard RESV", me.name, source_p->name);
      return;
    }

    if ((conf = create_nick_resv(name, reason, 0)) == NULL)
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :A RESV has already been placed on nick %s",
                 me.name, source_p->name, name);
      return;
    }

    resv_p = map_to_conf(conf);

    if (tkline_time != 0)
    {
      sendto_one(source_p,
		 ":%s NOTICE %s :A %d minute %s RESV has been placed on nick %s : [%s]",
                 me.name, source_p->name,
		 tkline_time/60,
                 (MyClient(source_p) ? "local" : "remote"),
                 conf->name, resv_p->reason);
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "%s has placed a %d minute %s RESV on nick %s : [%s]",
			   get_oper_name(source_p),
			   tkline_time/60,
			   (MyClient(source_p) ? "local" : "remote"),
			   conf->name, resv_p->reason);
      ilog(LOG_TYPE_IRCD, "%s added temporary %d min. RESV for [%s] [%s]",
	   source_p->name, (int)tkline_time/60,
	   conf->name, resv_p->reason);
      resv_p->hold = CurrentTime + tkline_time;
      add_temp_line(conf);
    }
    else
    {
      sendto_one(source_p,
		 ":%s NOTICE %s :A %s RESV has been placed on nick %s : [%s]",
                 me.name, source_p->name,
                 (MyClient(source_p) ? "local" : "remote"),
                 conf->name, resv_p->reason);
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "%s has placed a %s RESV on nick %s : [%s]",
			   get_oper_name(source_p),
			   (MyClient(source_p) ? "local" : "remote"),
			   conf->name, resv_p->reason);
      write_conf_line(source_p, conf, NULL /* not used */, 0 /* not used */);
    }
  }
}

static void
remove_resv(struct Client *source_p, const char *name)
{
  struct ConfItem *conf = NULL;

  if (IsChanPrefix(*name))
  {
    struct ResvChannel *resv_p;

    if (resv_channel_list.head == NULL ||
        !(resv_p = hash_find_resv(name)))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :A RESV does not exist for channel: %s",
                 me.name, source_p->name, name);
      return;
    }

    if (resv_p->conf)
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :The RESV for channel: %s is in ircd.conf and must be removed by hand.",
                 me.name, source_p->name, name);
      return;
    }

    delete_channel_resv(resv_p);
    remove_conf_line(CRESV_TYPE, source_p, name, NULL);

    sendto_one(source_p,
               ":%s NOTICE %s :The RESV has been removed on channel: %s",
               me.name, source_p->name, name);
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has removed the RESV for channel: %s",
                         get_oper_name(source_p), name);
  }
  else
  {
    struct MatchItem *resv_p = NULL;

    if ((conf = find_exact_name_conf(NRESV_TYPE, NULL, name, NULL, NULL)) == NULL)
    {
      sendto_one(source_p, ":%s NOTICE %s :A RESV does not exist for nick: %s",
                 me.name, source_p->name, name);
      return;
    }

    resv_p = map_to_conf(conf);

    if (resv_p->action)
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :The RESV for nick: %s is in ircd.conf and must be removed by hand.",
                 me.name, source_p->name, name);
      return;
    }

    delete_conf_item(conf);
    remove_conf_line(NRESV_TYPE, source_p, name, NULL);

    sendto_one(source_p, ":%s NOTICE %s :The RESV has been removed on nick: %s",
               me.name, source_p->name, name);
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has removed the RESV for nick: %s",
                         get_oper_name(source_p), name);
  }
}

static struct Message resv_msgtab = {
  "RESV", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_ignore, m_not_oper, ms_resv, me_resv, mo_resv, m_ignore }
};

static struct Message unresv_msgtab = {
  "UNRESV", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_ignore, m_not_oper, ms_unresv, m_ignore, mo_unresv, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&resv_msgtab);
  mod_add_cmd(&unresv_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&resv_msgtab);
  mod_del_cmd(&unresv_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
