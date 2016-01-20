/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2016 ircd-hybrid development team
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


static void
resv_remove(struct Client *source_p, const char *name)
{
  unsigned int type = CONF_CRESV;
  struct MaskItem *conf = NULL;

  if (!IsChanPrefix(*name))
    type = CONF_NRESV;

  if ((conf = find_exact_name_conf(type, NULL, name, NULL, NULL)) == NULL)
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":No RESV for %s", name);

    return;
  }

  if (!IsConfDatabase(conf))
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":The RESV for %s is in ircd.conf and must be removed by hand",
                        name);
    return;
  }

  conf_free(conf);

  if (IsClient(source_p))
    sendto_one_notice(source_p, &me, ":RESV for [%s] is removed", name);

  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                       "%s has removed the RESV for: [%s]",
                       get_oper_name(source_p), name);
  ilog(LOG_TYPE_RESV, "%s removed RESV for [%s]",
       get_oper_name(source_p), name);
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
static int
mo_unresv(struct Client *source_p, int parc, char *parv[])
{
  char *resv = NULL;
  char *target_server = NULL;

  if (!HasOFlag(source_p, OPER_FLAG_UNRESV))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "unresv");
    return 0;
  }

  if (!parse_aline("UNRESV", source_p, parc, parv, 0, &resv, NULL,
                   NULL, &target_server, NULL))
    return 0;

  if (target_server)
  {
    sendto_match_servs(source_p, target_server, CAPAB_CLUSTER, "UNRESV %s %s",
                       target_server, resv);

    /* Allow ON to apply local unresv as well if it matches */
    if (match(target_server, me.name))
      return 0;
  }
  else
    cluster_a_line(source_p, "UNRESV", CAPAB_KLN, SHARED_UNRESV, resv);

  resv_remove(source_p, resv);
  return 0;
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
 *      - parv[1] = target server
 *      - parv[2] = channel/nick
 */
static int
ms_unresv(struct Client *source_p, int parc, char *parv[])
{
  if (parc != 3 || EmptyString(parv[2]))
    return 0;

  sendto_match_servs(source_p, parv[1], CAPAB_CLUSTER, "UNRESV %s %s",
                     parv[1], parv[2]);

  if (match(parv[1], me.name))
    return 0;

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      find_matching_name_conf(CONF_SHARED, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_UNRESV))
    resv_remove(source_p, parv[2]);

  return 0;
}

static struct Message unresv_msgtab =
{
  .cmd = "UNRESV",
  .args_min = 2,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = ms_unresv,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_unresv
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
