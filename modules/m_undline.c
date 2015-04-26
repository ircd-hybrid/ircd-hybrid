/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
#include "log.h"
#include "misc.h"
#include "send.h"
#include "server.h"
#include "parse.h"
#include "modules.h"
#include "conf_db.h"
#include "memory.h"


/* static int remove_tdline_match(const char *host, const char *user)
 * Input: An ip to undline.
 * Output: returns YES on success, NO if no tdline removed.
 * Side effects: Any matching tdlines are removed.
 */
static int
dline_remove(const char *host)
{
  struct irc_ssaddr iphost, *piphost;
  struct MaskItem *conf;
  int t = 0;
  int aftype = 0;

  if ((t = parse_netmask(host, &iphost, NULL)) != HM_HOST)
  {
    if (t == HM_IPV6)
      aftype = AF_INET6;
    else
      aftype = AF_INET;

    piphost = &iphost;
  }
  else
    piphost = NULL;

  if ((conf = find_conf_by_address(host, piphost, CONF_DLINE, aftype, NULL, NULL, 0)))
  {
    if (IsConfDatabase(conf))
    {
      delete_one_address_conf(host, conf);
      return 1;
    }
  }

  return 0;
}

static void
dline_remove_and_notify(struct Client *source_p, const char *host)
{
  if (dline_remove(host))
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":D-Line for [%s] is removed", host);

    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has removed the D-Line for: [%s]",
                         get_oper_name(source_p), host);
    ilog(LOG_TYPE_DLINE, "%s removed D-Line for [%s]",
         get_oper_name(source_p), host);
  }
  else if (IsClient(source_p))
    sendto_one_notice(source_p, &me, ":No D-Line for [%s] found", host);
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
static int
mo_undline(struct Client *source_p, int parc, char *parv[])
{
  char *addr = NULL;
  char *target_server = NULL;

  if (!HasOFlag(source_p, OPER_FLAG_UNDLINE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "undline");
    return 0;
  }

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "UNDLINE");
    return 0;
  }

  if (!parse_aline("UNDLINE", source_p, parc, parv, 0, &addr,
                   NULL, NULL, &target_server, NULL))
    return 0;

  if (target_server)
  {
    sendto_match_servs(source_p, target_server, CAP_UNDLN,
                       "UNDLINE %s %s", target_server, addr);

    /* Allow ON to apply local undline as well if it matches */
    if (match(target_server, me.name))
      return 0;
  }
  else
    cluster_a_line(source_p, "UNDLINE", CAP_UNDLN, SHARED_UNDLINE, "%s", addr);

  dline_remove_and_notify(source_p, addr);
  return 0;
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
 *      - parv[1] = target server
 *      - parv[2] = IP address
 */
static int
ms_undline(struct Client *source_p, int parc, char *parv[])
{
  const char *addr = parv[2];

  if (parc != 3 || EmptyString(parv[2]))
    return 0;

  sendto_match_servs(source_p, parv[1], CAP_UNDLN, "UNDLINE %s %s",
                     parv[1], parv[2]);

  if (match(parv[1], me.name))
    return 0;

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_UNDLINE))
    dline_remove_and_notify(source_p, addr);

  return 0;
}

static struct Message undline_msgtab =
{
  "UNDLINE", NULL, 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_undline, m_ignore, mo_undline, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&undline_msgtab);
  add_capability("UNDLN", CAP_UNDLN);
}

static void
module_exit(void)
{
  mod_del_cmd(&undline_msgtab);
  delete_capability("UNDLN");
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
