/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2022 ircd-hybrid development team
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

/*! \file m_unresv.c
 * \brief Includes required functions for processing the UNRESV command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_resv.h"
#include "conf_shared.h"
#include "numeric.h"
#include "log.h"
#include "send.h"
#include "server_capab.h"
#include "parse.h"
#include "modules.h"
#include "memory.h"


static void
resv_remove(struct Client *source_p, const struct aline_ctx *aline)
{
  struct ResvItem *resv = resv_find(aline->mask, irccmp);
  if (resv == NULL)
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":No RESV for %s", aline->mask);

    return;
  }

  if (resv->in_database == false)
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":The RESV for %s is in the configuration file and must be removed by hand",
                        resv->mask);
    return;
  }

  if (IsClient(source_p))
    sendto_one_notice(source_p, &me, ":RESV for [%s] is removed", resv->mask);

  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                       "%s has removed the RESV for: [%s]",
                       get_oper_name(source_p), resv->mask);
  ilog(LOG_TYPE_RESV, "%s removed RESV for [%s]",
       get_oper_name(source_p), resv->mask);

  resv_delete(resv, false);
}

/*! \brief UNRESV command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel/nick
 *      - parv[2] = "ON"
 *      - parv[3] = target server
 */
static void
mo_unresv(struct Client *source_p, int parc, char *parv[])
{
  struct aline_ctx aline = { .add = false, .simple_mask = true };

  if (!HasOFlag(source_p, OPER_FLAG_UNRESV))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "unresv");
    return;
  }

  if (parse_aline("UNRESV", source_p, parc, parv, &aline) == false)
    return;

  if (aline.server)
  {
    sendto_match_servs(source_p, aline.server, CAPAB_CLUSTER, "UNRESV %s %s",
                       aline.server, aline.mask);

    /* Allow ON to apply local unresv as well if it matches */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source_p, "UNRESV", CAPAB_KLN, CLUSTER_UNRESV, aline.mask);

  resv_remove(source_p, &aline);
}

/*! \brief UNRESV command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server mask
 *      - parv[2] = name mask
 */
static void
ms_unresv(struct Client *source_p, int parc, char *parv[])
{
  struct aline_ctx aline =
  {
    .add = false,
    .simple_mask = true,
    .mask = parv[2],
    .server = parv[1]
  };

  sendto_match_servs(source_p, aline.server, CAPAB_CLUSTER, "UNRESV %s %s",
                     aline.server, aline.mask);

  if (match(aline.server, me.name))
    return;

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      shared_find(SHARED_UNRESV, source_p->servptr->name,
                  source_p->username, source_p->host))
    resv_remove(source_p, &aline);
}

static struct Message unresv_msgtab =
{
  .cmd = "UNRESV",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_unresv, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_unresv, .args_min = 2 }
};

static void
module_init(void)
{
  mod_add_cmd(&unresv_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&unresv_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
