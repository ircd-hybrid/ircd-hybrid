/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
#include "hash.h"
#include "server.h"
#include "parse.h"
#include "modules.h"
#include "conf_db.h"
#include "memory.h"


/* static int remove_tkline_match(const char *host, const char *user)
 * Input: A hostname, a username to unkline.
 * Output: returns YES on success, NO if no tkline removed.
 * Side effects: Any matching tklines are removed.
 */
static int
remove_kline_match(const char *host, const char *user)
{
  struct irc_ssaddr iphost, *piphost;
  struct MaskItem *conf;
  int t = 0;
  int aftype = 0;

  if ((t = parse_netmask(host, &iphost, NULL)) != HM_HOST)
  {
#ifdef IPV6
    if (t == HM_IPV6)
      aftype = AF_INET6;
    else
#endif
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

/*! \brief UNKLINE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = user\@host mask to UNKLINE
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

  if (parse_aline("UNKLINE", source_p, parc, parv, 0, &user,
                  &host, NULL, &target_server, NULL) < 0)
    return 0;

  if (target_server != NULL)
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

  if (remove_kline_match(host, user))
  {
    sendto_one_notice(source_p, &me, ":K-Line for [%s@%s] is removed",
                      user, host);
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has removed the K-Line for: [%s@%s]",
                         get_oper_name(source_p), user, host);
    ilog(LOG_TYPE_KLINE, "%s removed K-Line for [%s@%s]",
         get_oper_name(source_p), user, host);
  }
  else
    sendto_one_notice(source_p, &me, ":No K-Line for [%s@%s] found", 
	              user, host);
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
 *      - parv[2] = user mask to UNKLINE
 *      - parv[3] = host mask to UNKLINE
 */
static int
me_unkline(struct Client *source_p, int parc, char *parv[])
{
  const char *kuser, *khost;

  if (parc != 4)
    return 0;

  kuser = parv[2];
  khost = parv[3];

  if (!IsClient(source_p) || match(parv[1], me.name))
    return 0;

  if (HasFlag(source_p, FLAGS_SERVICE) ||
      find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_UNKLINE))
  {
    if (remove_kline_match(khost, kuser))
    {
      sendto_one_notice(source_p, &me, ":K-Line for [%s@%s] is removed",
                        kuser, khost);
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s has removed the K-Line for: [%s@%s]",
                           get_oper_name(source_p), kuser, khost);
      ilog(LOG_TYPE_KLINE, "%s removed K-Line for [%s@%s]",
           get_oper_name(source_p), kuser, khost);
    }
    else
      sendto_one_notice(source_p, &me, ":No K-Line for [%s@%s] found",
                        kuser, khost);
  }

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
 *      - parv[2] = user mask to UNKLINE
 *      - parv[3] = host mask to UNKLINE
 */
static int
ms_unkline(struct Client *source_p, int parc, char *parv[])
{
  if (parc != 4)
    return 0;

  sendto_match_servs(source_p, parv[1], CAP_UNKLN,
                     "UNKLINE %s %s %s",
                     parv[1], parv[2], parv[3]);

  return me_unkline(source_p, parc, parv);
}

static struct Message unkline_msgtab =
{
  "UNKLINE", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_unkline, me_unkline, mo_unkline, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&unkline_msgtab);
  add_capability("UNKLN", CAP_UNKLN, 1);
}

static void
module_exit(void)
{
  mod_del_cmd(&unkline_msgtab);
  delete_capability("UNKLN");
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
