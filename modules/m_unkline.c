/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_shared.h"
#include "address.h"
#include "numeric.h"
#include "log.h"
#include "send.h"
#include "server_capab.h"
#include "parse.h"
#include "module.h"
#include "memory.h"
#include "aline.h"


/* static int remove_tkline_match(const char *host, const char *user)
 * Input: A hostname, a username to unkline.
 * Output: returns YES on success, NO if no tkline removed.
 * Side effects: Any matching tklines are removed.
 */
static void
kline_remove(struct Client *source, const struct aline_ctx *aline)
{
  struct io_addr iphost, *piphost;
  struct MaskItem *conf;

  if (parse_netmask(aline->host, &iphost, NULL) != HM_HOST)
    piphost = &iphost;
  else
    piphost = NULL;

  if ((conf = find_conf_by_address(aline->host, piphost, CONF_KLINE, aline->user, NULL, 0)) == NULL)
  {
    if (IsClient(source))
      sendto_one_notice(source, &me, ":No K-Line for [%s@%s] found", aline->user, aline->host);
    return;
  }

  if (!IsConfDatabase(conf))
  {
    if (IsClient(source))
      sendto_one_notice(source, &me, ":The K-Line for [%s@%s] is in the configuration file and must be removed by hand",
                        conf->user, conf->host);
    return;
  }

  if (IsClient(source))
    sendto_one_notice(source, &me, ":K-Line for [%s@%s] is removed",
                      conf->user, conf->host);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "%s has removed the K-Line for: [%s@%s]",
                 get_oper_name(source), conf->user, conf->host);
  log_write(LOG_TYPE_KLINE, "%s removed K-Line for [%s@%s]",
            get_oper_name(source), conf->user, conf->host);

  delete_one_address_conf(aline->host, conf);
}

/*! \brief UNKLINE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
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
static void
mo_unkline(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline = { .add = false, .simple_mask = false };

  if (!HasOFlag(source, OPER_FLAG_UNKLINE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "unkline");
    return;
  }

  if (aline_parse("UNKLINE", source, parc, parv, &aline) == false)
    return;

  if (aline.server)
  {
     sendto_match_servs(source, aline.server, CAPAB_UNKLN, "UNKLINE %s %s %s",
                        aline.server, aline.user, aline.host);

    /* Allow ON to apply local unkline as well if it matches */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source, "UNKLINE", CAPAB_UNKLN, CLUSTER_UNKLINE, "%s %s",
                       aline.user, aline.host);

  kline_remove(source, &aline);
}

/*! \brief UNKLINE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server mask
 *      - parv[2] = user mask
 *      - parv[3] = host mask
 */
static void
ms_unkline(struct Client *source, int parc, char *parv[])
{
  struct aline_ctx aline =
  {
    .add = false,
    .simple_mask = false,
    .user = parv[2],
    .host = parv[3],
    .server = parv[1]
  };

  sendto_match_servs(source, aline.server, CAPAB_UNKLN, "UNKLINE %s %s %s",
                     aline.server, aline.user, aline.host);

  if (match(aline.server, me.name))
    return;

  if (HasFlag(source, FLAGS_SERVICE) ||
      shared_find(SHARED_UNKLINE, source->servptr->name, source->username, source->host))
    kline_remove(source, &aline);
}

static struct Command command_table =
{
  .name = "UNKLINE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_unkline, .args_min = 4 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_unkline, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
  capab_add("UNKLN", CAPAB_UNKLN, true);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  capab_del("UNKLN");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
