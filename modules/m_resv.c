/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2018 ircd-hybrid development team
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
#include "server_capab.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_resv.h"
#include "conf_shared.h"
#include "log.h"


/* parse_resv()
 *
 * inputs	- source_p
 *		- thing to resv
 *		- !0 if temporary
 *		- reason
 * outputs	- none
 * side effects	- parse resv, create if valid
 */
static void
resv_handle(struct Client *source_p, struct aline_ctx *aline)
{
  if (!HasFlag(source_p, FLAGS_SERVICE))
  {
    if (!HasUMode(source_p, UMODE_ADMIN) && has_wildcards(aline->mask))
    {
      if (IsClient(source_p))
        sendto_one_notice(source_p, &me, ":You must be an admin to perform a wildcard RESV");

      return;
    }

    if (valid_wild_card_simple(aline->mask + !!IsChanPrefix(*aline->mask)) == false)
    {
      if (IsClient(source_p))
        sendto_one_notice(source_p, &me, ":Please include at least %u non-wildcard characters with the RESV",
                          ConfigGeneral.min_nonwildcard_simple);

      return;
    }
  }

  struct ResvItem *resv;
  if ((resv = resv_make(aline->mask, aline->reason, NULL)) == NULL)
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":A RESV has already been placed on: %s", aline->mask);

    return;
  }

  resv->setat = CurrentTime;
  resv->in_database = true;

  if (aline->duration)
  {
    resv->expire = CurrentTime + aline->duration;

    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":Added temporary %ju min. RESV [%s]",
                        aline->duration / 60, resv->mask);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s added temporary %ju min. RESV for [%s] [%s]",
                         get_oper_name(source_p), aline->duration / 60,
                         resv->mask, resv->reason);
    ilog(LOG_TYPE_RESV, "%s added temporary %ju min. RESV for [%s] [%s]",
         get_oper_name(source_p), aline->duration / 60, resv->mask, resv->reason);
  }
  else
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":Added RESV [%s] [%s]",
                        resv->mask, resv->reason);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s added RESV for [%s] [%s]",
                         get_oper_name(source_p), resv->mask,
                         resv->reason);
    ilog(LOG_TYPE_RESV, "%s added RESV for [%s] [%s]",
         get_oper_name(source_p), resv->mask, resv->reason);
  }
}

/* mo_resv()
 *   parv[0] = command
 *   parv[1] = channel/nick to forbid
 */
static int
mo_resv(struct Client *source_p, int parc, char *parv[])
{
  struct aline_ctx aline = { .add = true, .simple_mask = true };

  if (!HasOFlag(source_p, OPER_FLAG_RESV))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "resv");
    return 0;
  }

  if (parse_aline("RESV", source_p, parc, parv, &aline) == false)
    return 0;

  if (aline.server)
  {
    sendto_match_servs(source_p, aline.server, CAPAB_CLUSTER, "RESV %s %ju %s :%s",
                       aline.server, aline.duration, aline.mask, aline.reason);

    /* Allow ON to apply local resv as well if it matches */
    if (match(aline.server, me.name))
      return 0;
  }
  else
    cluster_distribute(source_p, "RESV", CAPAB_KLN, CLUSTER_RESV, "%ju %s :%s",
                       aline.duration, aline.mask, aline.reason);

  resv_handle(source_p, &aline);
  return 0;
}

/*! \brief RESV command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server mask
 *      - parv[2] = duration in seconds
 *      - parv[3] = name mask
 *      - parv[4] = reason
 */
static int
ms_resv(struct Client *source_p, int parc, char *parv[])
{
  struct aline_ctx aline =
  {
    .add = true,
    .simple_mask = true,
    .mask = parv[2],
    .reason = parv[4],
    .server = parv[1],
    .duration = strtoumax(parv[2], NULL, 10)
  };
  if (parc != 5 || EmptyString(parv[parc - 1]))
    return 0;

  sendto_match_servs(source_p, aline.server, CAPAB_CLUSTER, "RESV %s %ju %s :%s",
                     aline.server, aline.duration, aline.mask, aline.reason);

  if (match(aline.server, me.name))
    return 0;

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      shared_find(SHARED_RESV, source_p->servptr->name,
                  source_p->username, source_p->host))
    resv_handle(source_p, &aline);
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
  .handlers[ENCAP_HANDLER] = m_ignore,
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
