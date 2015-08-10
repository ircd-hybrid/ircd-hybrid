/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2015 ircd-hybrid development team
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
parse_resv(struct Client *source_p, const char *name, int tkline_time, const char *reason)
{
  const char *type = "channel";
  struct MaskItem *conf = NULL;

  if (!IsChanPrefix(*name))
    type = "nick";

  if (!HasFlag(source_p, FLAGS_SERVICE) && !HasUMode(source_p, UMODE_ADMIN) && has_wildcards(name))
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":You must be an admin to perform a wildcard RESV");

    return;
  }

  if (!valid_wild_card_simple(name + !!IsChanPrefix(*name)))
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":Please include at least %u non-wildcard characters with the resv",
                        ConfigGeneral.min_nonwildcard_simple);

    return;
  }

  if ((conf = create_resv(name, reason, NULL)) == NULL)
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":A RESV has already been placed on %s: %s", type, name);

    return;
  }

  conf->setat = CurrentTime;
  SetConfDatabase(conf);

  if (tkline_time)
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":A %d minute RESV has been placed on %s: %s",
                        tkline_time/60, type, name);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s has placed a %d minute RESV on %s: %s [%s]",
                         get_oper_name(source_p),
                         tkline_time/60, type,
                         conf->name, conf->reason);
    ilog(LOG_TYPE_RESV, "%s added temporary %d min. RESV for [%s] [%s]",
         get_oper_name(source_p), (int)tkline_time/60,
         conf->name, conf->reason);
    conf->until = CurrentTime + tkline_time;
  }
  else
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":A RESV has been placed on %s: %s",
                        type, name);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s has placed a RESV on %s: %s [%s]",
                         get_oper_name(source_p), type,
                         conf->name, conf->reason);
    ilog(LOG_TYPE_RESV, "%s added RESV for [%s] [%s]",
         get_oper_name(source_p), conf->name, conf->reason);
  }
}

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

  if (!parse_aline("RESV", source_p, parc, parv, 0, &resv, NULL,
                   &tkline_time, &target_server, &reason))
    return 0;

  if (target_server)
  {
    /* if a given expire time is given, ENCAP it */
    if (tkline_time)
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
    if (tkline_time)
      cluster_a_line(source_p, "ENCAP", CAP_ENCAP, SHARED_RESV,
                     "RESV %d %s 0 :%s", (int)tkline_time, resv, reason);
    else
      cluster_a_line(source_p, "RESV", CAP_KLN, SHARED_RESV,
                     "%s :%s", resv, reason);
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
  if (parc != 5 || EmptyString(parv[4]))
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
  if (parc != 4 || EmptyString(parv[3]))
    return 0;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER, "RESV %s %s :%s",
                     parv[1], parv[2], parv[3]);

  if (match(parv[1], me.name))
    return 0;

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_RESV))
    parse_resv(source_p, parv[2], 0, parv[3]);
  return 0;
}

static struct Message resv_msgtab =
{
  .cmd = "RESV",
  .args_min = 3,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = ms_resv,
  .handlers[ENCAP_HANDLER] = me_resv,
  .handlers[OPER_HANDLER] = mo_resv
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
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
