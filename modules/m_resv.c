/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2014 ircd-hybrid development team
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

/*! \file m_resv.c
 * \brief Includes required functions for processing the RESV command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "server.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"
#include "log.h"
#include "resv.h"
#include "hash.h"


static void parse_resv(struct Client *, char *, int, char *);


/* mo_resv()
 *   parv[0] = command
 *   parv[1] = channel/nick to forbid
 */
static int
mo_resv(struct Client *source_p, int parc, char *parv[])
{
  char *resv = NULL;
  char *reason = NULL;
  char *target_server = NULL;
  time_t tkline_time = 0;

  /* RESV #channel ON irc.server.com :abuse
   * RESV kiddie ON irc.server.com :abuse
   */
  if (parse_aline("RESV", source_p, parc, parv, AWILD, &resv, NULL,
                  &tkline_time, &target_server, &reason) < 0)
    return 0;

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
    if (match(target_server, me.name))
      return 0;
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
  return 0;
}

/* me_resv()
 *
 * inputs	- server
 *		- client (oper)
 *		- parc number of arguments
 *		- parv list of arguments
 * via parv[]
 * parv[0] = command
 * parv[1] = tkline_time
 * parv[2] = name
 * parv[3] = 0
 * parv[4] = reason
 * parc should be 5
 *
 * outputs	- NONE
 * side effects -
 */
static int
me_resv(struct Client *source_p, int parc, char *parv[])
{
  if (parc != 5 || !IsClient(source_p))
    return 0;

  parse_resv(source_p, parv[2], atoi(parv[1]), parv[4]);
  return 0;
}

/* ms_resv()
 *   parv[0] = command
 *   parv[1] = target server
 *   parv[2] = channel/nick to resv
 *   parv[3] = reason
 */
static int
ms_resv(struct Client *source_p, int parc, char *parv[])
{
  if ((parc != 4) || EmptyString(parv[3]))
    return 0;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER,
                     "RESV %s %s :%s",
                     parv[1], parv[2], parv[3]);

  if (!IsClient(source_p) || match(parv[1], me.name))
    return 0;

  if (HasFlag(source_p, FLAGS_SERVICE) || find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_RESV))
    parse_resv(source_p, parv[2], 0, parv[3]);
  return 0;
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
  if (IsChanPrefix(*name))
  {
    struct MaskItem *conf = NULL;

    if ((conf = create_resv(name, reason, NULL)) == NULL)
    {
      sendto_one_notice(source_p, &me, ":A RESV has already been placed on channel: %s",
                        name);
      return;
    }

    conf->setat = CurrentTime;
    SetConfDatabase(conf);

    if (tkline_time != 0)
    {
      sendto_one_notice(source_p, &me, ":A %d minute %s RESV has been placed on channel: %s",
                        tkline_time/60, (MyClient(source_p) ? "local" : "remote"), name);
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s has placed a %d minute %s RESV on channel: %s [%s]",
                           get_oper_name(source_p),
                           tkline_time/60,
                           (MyClient(source_p) ? "local" : "remote"),
                           conf->name, conf->reason);
      ilog(LOG_TYPE_RESV, "%s added temporary %d min. RESV for [%s] [%s]",
           source_p->name, (int)tkline_time/60,
           conf->name, conf->reason);
      conf->until = CurrentTime + tkline_time;
    }
    else
    {
      sendto_one_notice(source_p, &me, ":A %s RESV has been placed on channel %s",
                        (MyClient(source_p) ? "local" : "remote"), name);
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s has placed a %s RESV on channel %s : [%s]",
                           get_oper_name(source_p),
                           (MyClient(source_p) ? "local" : "remote"),
                           conf->name, conf->reason);
    }
  }
  else
  {
    struct MaskItem *conf = NULL;

    if (!valid_wild_card_simple(name))
    {
      sendto_one_notice(source_p, &me, ":Please include at least %d non-wildcard characters with the resv",
                        ConfigFileEntry.min_nonwildcard_simple);
      return;
    }

    if (!HasUMode(source_p, UMODE_ADMIN) && has_wildcards(name))
    {
      sendto_one_notice(source_p, &me, ":You must be an admin to perform a wildcard RESV");
      return;
    }

    if ((conf = create_resv(name, reason, NULL)) == NULL)
    {
      sendto_one_notice(source_p, &me, ":A RESV has already been placed on nick %s",
                        name);
      return;
    }

    conf->setat = CurrentTime;
    SetConfDatabase(conf);

    if (tkline_time != 0)
    {
      sendto_one_notice(source_p, &me, ":A %d minute %s RESV has been placed on nick %s : [%s]",
                        tkline_time/60, (MyClient(source_p) ? "local" : "remote"),
                        conf->name, conf->reason);
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s has placed a %d minute %s RESV on nick %s : [%s]",
                           get_oper_name(source_p), tkline_time/60,
                           (MyClient(source_p) ? "local" : "remote"),
                           conf->name, conf->reason);
      ilog(LOG_TYPE_RESV, "%s added temporary %d min. RESV for [%s] [%s]",
           source_p->name, (int)tkline_time/60, conf->name, conf->reason);
      conf->until = CurrentTime + tkline_time;
    }
    else
    {
      sendto_one_notice(source_p, &me, ":A %s RESV has been placed on nick %s : [%s]",
                        (MyClient(source_p) ? "local" : "remote"), conf->name, conf->reason);
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s has placed a %s RESV on nick %s : [%s]",
                           get_oper_name(source_p),
                           (MyClient(source_p) ? "local" : "remote"),
                           conf->name, conf->reason);
    }
  }
}

static struct Message resv_msgtab =
{
  "RESV", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_ignore, m_not_oper, ms_resv, me_resv, mo_resv, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&resv_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&resv_msgtab);
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
