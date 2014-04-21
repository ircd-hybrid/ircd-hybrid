/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2003-2014 ircd-hybrid development team
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

/*! \file m_unxline.c
 * \brief Includes required functions for processing the UNXLINE command.
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
#include "send.h"
#include "server.h"
#include "parse.h"
#include "modules.h"
#include "conf_db.h"
#include "memory.h"


/* static int remove_tkline_match(const char *host, const char *user)
 *
 * Inputs:      gecos
 * Output:      returns YES on success, NO if no tkline removed.
 * Side effects: Any matching tklines are removed.
 */
static int
remove_xline_match(const char *gecos)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, xconf_items.head)
  {
    struct MaskItem *conf = ptr->data;

    if (!IsConfDatabase(conf))
      continue;

    if (!irccmp(gecos, conf->name))
    {
      conf_free(conf);
      return 1;
    }
  }

  return 0;
}

static void
remove_xline(struct Client *source_p, const char *gecos)
{
  if (remove_xline_match(gecos))
  {
    sendto_one_notice(source_p, &me, ":X-Line for [%s] is removed", gecos);
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has removed the X-Line for: [%s]",
                         get_oper_name(source_p), gecos);
    ilog(LOG_TYPE_XLINE, "%s removed X-Line for [%s]",
         get_oper_name(source_p), gecos);
  }
  else
    sendto_one_notice(source_p, &me, ":No X-Line for %s", gecos);
}

/*! \brief UNXLINE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = gecos
 *      - parv[2] = "ON"
 *      - parv[3] = target server
 */
static int
mo_unxline(struct Client *source_p, int parc, char *parv[])
{
  char *gecos = NULL;
  char *target_server = NULL;

  if (!HasOFlag(source_p, OPER_FLAG_UNXLINE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "unxline");
    return 0;
  }

  /* UNXLINE bill ON irc.server.com */
  if (parse_aline("UNXLINE", source_p, parc, parv, 0, &gecos,
                  NULL, NULL, &target_server, NULL) < 0)
    return 0;

  if (target_server != NULL)
  {
    sendto_match_servs(source_p, target_server, CAP_CLUSTER,
                       "UNXLINE %s %s", target_server, gecos);

    /* Allow ON to apply local unxline as well if it matches */
    if (match(target_server, me.name))
      return 0;
  }
  else
    cluster_a_line(source_p, "UNXLINE", CAP_CLUSTER, SHARED_UNXLINE,
                   "%s", gecos);

  remove_xline(source_p, gecos);
  return 0;
}

/*! \brief UNXLINE command handler
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
 */
static int
ms_unxline(struct Client *source_p, int parc, char *parv[])
{
  if (parc != 3)
    return 0;

  if (!IsClient(source_p) || EmptyString(parv[2]))
    return 0;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER,
                     "UNXLINE %s %s", parv[1], parv[2]);

  if (match(parv[1], me.name))
    return 0;

  if (HasFlag(source_p, FLAGS_SERVICE) || find_matching_name_conf(CONF_ULINE, source_p->servptr->name,
                              source_p->username, source_p->host,
                              SHARED_UNXLINE))
    remove_xline(source_p, parv[2]);
  return 0;
}

static struct Message unxline_msgtab =
{
  "UNXLINE", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_unxline, m_ignore, mo_unxline, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&unxline_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&unxline_msgtab);
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
