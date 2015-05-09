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

/*! \file m_unkline.c
 * \brief Includes required functions for processing the UNKLINE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "conf.h"
#include "hostmask.h"
#include "numeric.h"
#include "log.h"
#include "misc.h"
#include "send.h"
#include "server.h"
#include "parse.h"
#include "modules.h"
#include "memory.h"


/* static int remove_tkline_match(const char *host, const char *user)
 * Input: A hostname, a username to unkline.
 * Output: returns YES on success, NO if no tkline removed.
 * Side effects: Any matching tklines are removed.
 */
static int
kline_remove(const char *user, const char *host)
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

  if ((conf = find_conf_by_address(host, piphost, CONF_KLINE, aftype, user, NULL, 0)))
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
kline_remove_and_notify(struct Client *source_p, const char *user, const char *host)
{
  if (kline_remove(user, host))
  {
    if (IsClient(source_p))
      sendto_one_notice(source_p, &me, ":K-Line for [%s@%s] is removed", user, host);

    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has removed the K-Line for: [%s@%s]",
                         get_oper_name(source_p), user, host);
    ilog(LOG_TYPE_KLINE, "%s removed K-Line for [%s@%s]",
         get_oper_name(source_p), user, host);
  }
  else if (IsClient(source_p))
    sendto_one_notice(source_p, &me, ":No K-Line for [%s@%s] found", user, host);
}

/*! \brief UNKLINE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = user\@host mask
 *      - parv[2] = "ON"
 *      - parv[3] = target server
 */
static int
mo_unkline(struct Client *source_p, int parc, char *parv[])
{
  char *target_server = NULL;
  char *user, *host;

  if (!HasOFlag(source_p, OPER_FLAG_UNKLINE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "unkline");
    return 0;
  }

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "UNKLINE");
    return 0;
  }

  if (!parse_aline("UNKLINE", source_p, parc, parv, 0, &user,
                   &host, NULL, &target_server, NULL))
    return 0;

  if (target_server)
  {
     sendto_match_servs(source_p, target_server, CAP_UNKLN,
                        "UNKLINE %s %s %s",
                        target_server, user, host);

    /* Allow ON to apply local unkline as well if it matches */
    if (match(target_server, me.name))
      return 0;
  }
  else
    cluster_a_line(source_p, "UNKLINE", CAP_UNKLN, SHARED_UNKLINE,
                   "%s %s", user, host);

  kline_remove_and_notify(source_p, user, host);
  return 0;
}

/*! \brief UNKLINE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server
 *      - parv[2] = user mask
 *      - parv[3] = host mask
 */
static int
ms_unkline(struct Client *source_p, int parc, char *parv[])
{
  const char *user, *host;

  if (parc != 4 || EmptyString(parv[3]))
    return 0;

  sendto_match_servs(source_p, parv[1], CAP_UNKLN, "UNKLINE %s %s %s",
                     parv[1], parv[2], parv[3]);

  user = parv[2];
  host = parv[3];

  if (match(parv[1], me.name))
    return 0;

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_UNKLINE))
    kline_remove_and_notify(source_p, user, host);

  return 0;
}

static struct Message unkline_msgtab =
{
  .cmd = "UNKLINE",
  .args_min = 2,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = ms_unkline,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_unkline
};

static void
module_init(void)
{
  mod_add_cmd(&unkline_msgtab);
  add_capability("UNKLN", CAP_UNKLN);
}

static void
module_exit(void)
{
  mod_del_cmd(&unkline_msgtab);
  delete_capability("UNKLN");
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
