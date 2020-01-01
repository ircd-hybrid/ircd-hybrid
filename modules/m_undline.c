/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2020 ircd-hybrid development team
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

/*! \file m_undline.c
 * \brief Includes required functions for processing the UNDLINE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_shared.h"
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
#include "log.h"
#include "misc.h"
#include "send.h"
#include "server_capab.h"
#include "parse.h"
#include "modules.h"
#include "memory.h"


/* static int remove_tdline_match(const char *host, const char *user)
 * Input: An ip to undline.
 * Output: returns YES on success, NO if no tdline removed.
 * Side effects: Any matching tdlines are removed.
 */
static void
dline_remove(struct Client *source_p, const struct aline_ctx *aline)
{
  struct irc_ssaddr iphost, *piphost;
  struct MaskItem *conf;

  if (parse_netmask(aline->host, &iphost, NULL) != HM_HOST)
    piphost = &iphost;
  else
    piphost = NULL;

  if ((conf = find_conf_by_address(NULL, piphost, CONF_DLINE, NULL, NULL, 0)) == NULL)
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":No D-Line for [%s] found", aline->host);

    return;
  }

  if (!IsConfDatabase(conf))
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":The D-Line for [%s] is in the configuration file and must be removed by hand",
                        conf->host);
    return;
  }

  if (IsClient(source_p))
    sendto_one_notice(source_p, &me, ":D-Line for [%s] is removed",
                      conf->host);

  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                       "%s has removed the D-Line for: [%s]",
                       get_oper_name(source_p), conf->host);
  ilog(LOG_TYPE_DLINE, "%s removed D-Line for [%s]",
       get_oper_name(source_p), conf->host);

  delete_one_address_conf(aline->host, conf);
}

/*! \brief UNDLINE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = IP address
 *      - parv[2] = "ON"
 *      - parv[3] = target server
 */
static void
mo_undline(struct Client *source_p, int parc, char *parv[])
{
  struct aline_ctx aline = { .add = false, .simple_mask = false };

  if (!HasOFlag(source_p, OPER_FLAG_UNDLINE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "undline");
    return;
  }

  if (parc < 2 || EmptyString(parv[parc - 1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "UNDLINE");
    return;
  }

  if (parse_aline("UNDLINE", source_p, parc, parv, &aline) == false)
    return;

  if (aline.server)
  {
    sendto_match_servs(source_p, aline.server, CAPAB_UNDLN, "UNDLINE %s %s",
                       aline.server, aline.host);

    /* Allow ON to apply local undline as well if it matches */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source_p, "UNDLINE", CAPAB_UNDLN, CLUSTER_UNDLINE, "%s", aline.host);

  dline_remove(source_p, &aline);
}

/*! \brief UNDLINE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server mask
 *      - parv[2] = IP address
 */
static void
ms_undline(struct Client *source_p, int parc, char *parv[])
{
  struct aline_ctx aline =
  {
    .add = false,
    .simple_mask = false,
    .host = parv[2],
    .server = parv[1]
  };

  if (parc != 3 || EmptyString(parv[parc - 1]))
    return;

  sendto_match_servs(source_p, aline.server, CAPAB_UNDLN, "UNDLINE %s %s",
                     aline.server, aline.host);

  if (match(aline.server, me.name))
    return;

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      shared_find(SHARED_UNDLINE, source_p->servptr->name,
                  source_p->username, source_p->host))
    dline_remove(source_p, &aline);
}

static struct Message undline_msgtab =
{
  .cmd = "UNDLINE",
  .args_min = 2,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = ms_undline,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_undline
};

static void
module_init(void)
{
  mod_add_cmd(&undline_msgtab);
  capab_add("UNDLN", CAPAB_UNDLN);
}

static void
module_exit(void)
{
  mod_del_cmd(&undline_msgtab);
  capab_del("UNDLN");
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
