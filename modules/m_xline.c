/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2003-2015 ircd-hybrid development team
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

/*! \file m_xline.c
 * \brief Includes required functions for processing the XLINE command.
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
#include "misc.h"
#include "send.h"
#include "server.h"
#include "parse.h"
#include "modules.h"
#include "memory.h"


static void
xline_check(struct MaskItem *conf)
{
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, local_client_list.head)
  {
    struct Client *client_p = node->data;

    if (IsDead(client_p))
      continue;

    if (!match(conf->name, client_p->info))
      conf_try_ban(client_p, conf);
  }
}

/* valid_xline()
 *
 * inputs       - client to complain to, gecos, reason, whether to complain
 * outputs      - 1 for valid, else 0
 * side effects - complains to client, when warn != 0
 */
static int
valid_xline(struct Client *source_p, const char *gecos)
{
  if (!valid_wild_card_simple(gecos))
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":Please include at least %u non-wildcard characters with the xline",
                        ConfigGeneral.min_nonwildcard_simple);
    return 0;
  }

  return 1;
}

/* xline_add()
 *
 * inputs       - client taking credit for xline, gecos, reason, xline type
 * outputs      - none
 * side effects - when successful, adds an xline to the conf
 */
static void
xline_add(struct Client *source_p, const char *gecos, const char *reason,
          time_t txline_time)
{
  char buf[IRCD_BUFSIZE];
  struct MaskItem *conf;

  if (txline_time)
    snprintf(buf, sizeof(buf), "Temporary X-line %d min. - %.*s (%s)",
             (int)(txline_time/60), REASONLEN, reason, date_iso8601(0));
  else
    snprintf(buf, sizeof(buf), "%.*s (%s)", REASONLEN, reason, date_iso8601(0));

  conf = conf_make(CONF_XLINE);
  conf->name = xstrdup(gecos);
  conf->reason = xstrdup(buf);
  conf->setat = CurrentTime;
  SetConfDatabase(conf);

  if (txline_time)
  {
    conf->until = CurrentTime + txline_time;

    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":Added temporary %d min. X-Line [%s]",
                        (int)txline_time/60, conf->name);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s added temporary %d min. X-Line for [%s] [%s]",
                         get_oper_name(source_p), (int)txline_time/60,
                         conf->name, conf->reason);
    ilog(LOG_TYPE_XLINE, "%s added temporary %d min. X-Line for [%s] [%s]",
         get_oper_name(source_p), (int)txline_time/60, conf->name, conf->reason);
  }
  else
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":Added X-Line [%s] [%s]",
                        conf->name, conf->reason);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s added X-Line for [%s] [%s]",
                         get_oper_name(source_p), conf->name,
                         conf->reason);
    ilog(LOG_TYPE_XLINE, "%s added X-Line for [%s] [%s]",
         get_oper_name(source_p), conf->name, conf->reason);
  }

  xline_check(conf);
}

static void
relay_xline(struct Client *source_p, char *parv[])
{
  struct MaskItem *conf = NULL;

  if (HasFlag(source_p, FLAGS_SERVICE) || find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_XLINE))
  {
    if ((conf = find_matching_name_conf(CONF_XLINE, parv[2], NULL, NULL, 0)))
    {
      if (IsClient(source_p))
        sendto_one_notice(source_p, &me, ":[%s] already X-Lined by [%s] - %s",
                          parv[2], conf->name, conf->reason);
      return;
    }

    xline_add(source_p, parv[2], parv[4], atoi(parv[3]));
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
mo_xline(struct Client *source_p, int parc, char *parv[])
{
  char *reason = NULL;
  char *gecos = NULL;
  struct MaskItem *conf = NULL;
  char *target_server = NULL;
  time_t txline_time = 0;

  if (!HasOFlag(source_p, OPER_FLAG_XLINE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "xline");
    return 0;
  }

  if (!parse_aline("XLINE", source_p, parc, parv, 0, &gecos, NULL,
                   &txline_time, &target_server, &reason))
    return 0;

  if (target_server)
  {
    sendto_match_servs(source_p, target_server, CAPAB_CLUSTER, "XLINE %s %s %d :%s",
                       target_server, gecos, (int)txline_time, reason);

    /* Allow ON to apply local xline as well if it matches */
    if (match(target_server, me.name))
      return 0;
  }
  else
    cluster_a_line(source_p, "XLINE", CAPAB_CLUSTER, SHARED_XLINE, "%s %d :%s",
                   gecos, txline_time, reason);

  if (!valid_xline(source_p, gecos))
    return 0;

  if ((conf = find_matching_name_conf(CONF_XLINE, gecos, NULL, NULL, 0)))
  {
    sendto_one_notice(source_p, &me, ":[%s] already X-Lined by [%s] - %s",
                      gecos, conf->name, conf->reason);
    return 0;
  }

  xline_add(source_p, gecos, reason, txline_time);
  return 0;
}

/*! \brief XLINE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server
 *      - parv[2] = gecos
 *      - parv[3] = time
 *      - parv[4] = reason
 */
static int
ms_xline(struct Client *source_p, int parc, char *parv[])
{
  if (parc != 5 || EmptyString(parv[4]))
    return 0;

  sendto_match_servs(source_p, parv[1], CAPAB_CLUSTER, "XLINE %s %s %s :%s",
                     parv[1], parv[2], parv[3], parv[4]);

  if (match(parv[1], me.name))
    return 0;

  if (!valid_xline(source_p, parv[2]))
    return 0;

  relay_xline(source_p, parv);
  return 0;
}

/* XXX: TBR */
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
me_xline(struct Client *source_p, int parc, char *parv[])
{
  if (parc != 5 || EmptyString(parv[4]))
    return 0;

  if (!valid_xline(source_p, parv[2]))
    return 0;

  relay_xline(source_p, parv);
  return 0;
}

static struct Message xline_msgtab =
{
  .cmd = "XLINE",
  .args_min = 2,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = ms_xline,
  .handlers[ENCAP_HANDLER] = me_xline,
  .handlers[OPER_HANDLER] = mo_xline
};

static void
module_init(void)
{
  mod_add_cmd(&xline_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&xline_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
