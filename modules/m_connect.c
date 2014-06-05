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

/*! \file m_connect.c
 * \brief Includes required functions for processing the CONNECT command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "conf.h"
#include "log.h"
#include "server.h"
#include "send.h"
#include "parse.h"
#include "hash.h"
#include "modules.h"


/*! \brief CONNECT command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server
 *      - parv[2] = port number
 *      - parv[3] = nickname/servername
 */
static int
mo_connect(struct Client *source_p, int parc, char *parv[])
{
  int port;
  int tmpport;
  struct MaskItem *conf = NULL;
  const struct Client *target_p = NULL;

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "CONNECT");
    return 0;
  }

  if (parc > 3)
  {
    if (!HasOFlag(source_p, OPER_FLAG_CONNECT_REMOTE))
    {
      sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "connect:remote");
      return 0;
    }

    if (hunt_server(source_p, ":%s CONNECT %s %s :%s", 3,
                    parc, parv) != HUNTED_ISME)
      return 0;
  }
  else if (!HasOFlag(source_p, OPER_FLAG_CONNECT))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "connect");
    return 0;
  }

  if ((target_p = hash_find_server(parv[1])))
  {
    sendto_one_notice(source_p, &me, ":Connect: Server %s already exists from %s.",
                      parv[1], target_p->from->name);
    return 0;
  }

  /*
   * Try to find the name, then host, if both fail notify ops and bail
   */
  if (!(conf = find_matching_name_conf(CONF_SERVER, parv[1], NULL, NULL, 0)))
  {
    if (!(conf = find_matching_name_conf(CONF_SERVER,  NULL, NULL, parv[1], 0)))
    {
      sendto_one_notice(source_p, &me, ":Connect: Host %s not listed in ircd.conf", parv[1]);
      return 0;
    }
  }

  /*
   * Get port number from user, if given. If not specified,
   * use the default form configuration structure. If missing
   * from there, then use the precompiled default.
   */
  tmpport = port = conf->port;

  if (parc > 2 && !EmptyString(parv[2]))
  {
    if ((port = atoi(parv[2])) <= 0)
    {
      sendto_one_notice(source_p, &me, ":Connect: Illegal port number");
      return 0;
    }
  }
  else if (port <= 0 && (port = PORTNUM) <= 0)
  {
    sendto_one_notice(source_p, &me, ":Connect: missing port number");
    return 0;
  }

  if (find_servconn_in_progress(conf->name))
  {
    sendto_one_notice(source_p, &me, ":Connect: a connection to %s "
                      "is already in progress.", conf->name);
    return 0;
  }

  /*
   * Notify all operators about remote connect requests
   */
  ilog(LOG_TYPE_IRCD, "CONNECT From %s : %s %s",
       source_p->name, parv[1], parv[2] ? parv[2] : "");

  conf->port = port;

  /*
   * At this point we should be calling connect_server with a valid
   * connect{} block and a valid port in the connect{} block
   */
  if (serv_connect(conf, source_p))
  {
    if (!ConfigServerHide.hide_server_ips && HasUMode(source_p, UMODE_ADMIN))
      sendto_one_notice(source_p, &me, ":*** Connecting to %s[%s].%d",
                        conf->host, conf->name, conf->port);
    else
      sendto_one_notice(source_p, &me, ":*** Connecting to %s.%d",
                        conf->name, conf->port);
  }
  else
    sendto_one_notice(source_p, &me, ":*** Couldn't connect to %s.%d",
                      conf->name, conf->port);

  /*
   * Client is either connecting with all the data it needs or has been
   * destroyed
   */
  conf->port = tmpport;
  return 0;
}

/*! \brief CONNECT command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server
 *      - parv[2] = port number
 *      - parv[3] = nickname/servername
 */
static int
ms_connect(struct Client *source_p, int parc, char *parv[])
{
  int port;
  int tmpport;
  struct MaskItem *conf = NULL;
  const struct Client *target_p = NULL;

  if (hunt_server(source_p, ":%s CONNECT %s %s :%s",
                  3, parc, parv) != HUNTED_ISME)
    return 0;

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "CONNECT");
    return 0;
  }

  if ((target_p = hash_find_server(parv[1])))
  {
    sendto_one_notice(source_p, &me, ":Connect: Server %s already exists from %s.",
                      parv[1], target_p->from->name);
    return 0;
  }

  /*
   * Try to find the name, then host, if both fail notify ops and bail
   */
  if (!(conf = find_matching_name_conf(CONF_SERVER, parv[1], NULL, NULL, 0)))
  {
    if (!(conf = find_matching_name_conf(CONF_SERVER,  NULL, NULL, parv[1], 0)))
    {
      sendto_one_notice(source_p, &me, ":Connect: Host %s not listed in ircd.conf", parv[1]);
      return 0;
    }
  }

  /*
   * Get port number from user, if given. If not specified,
   * use the default form configuration structure. If missing
   * from there, then use the precompiled default.
   */
  tmpport = port = conf->port;

  if (parc > 2 && !EmptyString(parv[2]))
  {
    port = atoi(parv[2]);

    /*
     * If someone sends port 0, and we have a config port.. use it
     */
    if (port == 0 && conf->port)
      port = conf->port;
    else if (port <= 0)
    {
      sendto_one_notice(source_p, &me, ":Connect: Illegal port number");
      return 0;
    }
  }
  else if (port <= 0 && (port = PORTNUM) <= 0)
  {
    sendto_one_notice(source_p, &me, ":Connect: missing port number");
    return 0;
  }

  if (find_servconn_in_progress(conf->name))
  {
    sendto_one_notice(source_p, &me, ":Connect: a connection to %s "
                      "is already in progress.", conf->name);
    return 0;
  }

  /*
   * Notify all operators about remote connect requests
   */
  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_GLOBAL, "from %s: Remote CONNECT %s %d from %s",
                       me.name, parv[1], port, source_p->name);
  sendto_server(NULL, NOCAPS, NOCAPS,
                ":%s GLOBOPS :Remote CONNECT %s %d from %s",
                me.id, parv[1], port, source_p->name);

  ilog(LOG_TYPE_IRCD, "CONNECT From %s : %s %d",
       source_p->name, parv[1], port);

  conf->port = port;

  /*
   * At this point we should be calling connect_server with a valid
   * connect{} block and a valid port in the connect{} block
   */
  if (serv_connect(conf, source_p))
    sendto_one_notice(source_p, &me, ":*** Connecting to %s.%d",
                      conf->name, conf->port);
  else
    sendto_one_notice(source_p, &me, ":*** Couldn't connect to %s.%d",
                      conf->name, conf->port);
  /*
   * Client is either connecting with all the data it needs or has been
   * destroyed
   */
  conf->port = tmpport;
  return 0;
}

static struct Message connect_msgtab =
{
  "CONNECT", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_connect, m_ignore, mo_connect, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&connect_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&connect_msgtab);
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
