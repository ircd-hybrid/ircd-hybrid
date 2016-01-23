/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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

/*! \file m_connect.c
 * \brief Includes required functions for processing the CONNECT command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
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
  struct MaskItem *conf = NULL;
  const struct Client *target_p = NULL;
  const char *const name = parv[1];

  if (EmptyString(name))
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

    if (hunt_server(source_p, ":%s CONNECT %s %s :%s", 3, parc, parv) != HUNTED_ISME)
      return 0;
  }
  else if (!HasOFlag(source_p, OPER_FLAG_CONNECT))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "connect");
    return 0;
  }

  /*
   * Try to find the name, then host, if both fail notify ops and bail
   */
  if (!(conf = find_matching_name_conf(CONF_SERVER, name, NULL, NULL, 0)) &&
      !(conf = find_matching_name_conf(CONF_SERVER, NULL, NULL, name, 0)))
  {
    sendto_one_notice(source_p, &me, ":Connect: Host %s not listed in configuration file", name);
    return 0;
  }

  if ((target_p = hash_find_server(conf->name)))
  {
    sendto_one_notice(source_p, &me, ":Connect: Server %s already exists from %s",
                      target_p->name, target_p->from->name);
    return 0;
  }

  /*
   * Get port number from user, if given. If not specified,
   * use the default from configuration structure.
   */
  int port = 0;

  if (parc > 2 && !EmptyString(parv[2]))
    port = atoi(parv[2]);
  if (port == 0)
    port = conf->port;
  if (port <= 0)
  {
    sendto_one_notice(source_p, &me, ":Connect: Illegal port number");
    return 0;
  }

  if (find_servconn_in_progress(conf->name))
  {
    sendto_one_notice(source_p, &me, ":Connect: a connection to %s is already in progress",
                      conf->name);
    return 0;
  }

  ilog(LOG_TYPE_IRCD, "CONNECT %s %d from %s",
       name, port, get_oper_name(source_p));

  const int tmpport = conf->port;
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
  struct MaskItem *conf = NULL;
  const struct Client *target_p = NULL;
  const char *const name = parv[1];

  if (parc < 4 || EmptyString(parv[3]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "CONNECT");
    return 0;
  }

  if (hunt_server(source_p, ":%s CONNECT %s %s :%s", 3, parc, parv) != HUNTED_ISME)
    return 0;

  /*
   * Try to find the name, then host, if both fail notify ops and bail
   */
  if (!(conf = find_matching_name_conf(CONF_SERVER, name, NULL, NULL, 0)) &&
      !(conf = find_matching_name_conf(CONF_SERVER, NULL, NULL, name, 0)))
  {
    sendto_one_notice(source_p, &me, ":Connect: Host %s not listed in configuration file", name);
    return 0;
  }

  if ((target_p = hash_find_server(conf->name)))
  {
    sendto_one_notice(source_p, &me, ":Connect: Server %s already exists from %s",
                      target_p->name, target_p->from->name);
    return 0;
  }

  /*
   * Get port number from user, if given. If not specified,
   * use the default from configuration structure.
   */
  int port = atoi(parv[2]);

  if (port == 0)
    port = conf->port;
  if (port <= 0)
  {
    sendto_one_notice(source_p, &me, ":Connect: Illegal port number");
    return 0;
  }

  if (find_servconn_in_progress(conf->name))
  {
    sendto_one_notice(source_p, &me, ":Connect: a connection to %s is already in progress",
                      conf->name);
    return 0;
  }

  /*
   * Notify all operators about remote connect requests
   */
  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_GLOBAL, "from %s: Remote CONNECT %s %d from %s",
                       me.name, name, port, get_oper_name(source_p));
  sendto_server(NULL, 0, 0, ":%s GLOBOPS :Remote CONNECT %s %d from %s",
                me.id, name, port, get_oper_name(source_p));

  ilog(LOG_TYPE_IRCD, "Remote CONNECT %s %d from %s",
       name, port, get_oper_name(source_p));

  const int tmpport = conf->port;
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
  .cmd = "CONNECT",
  .args_min = 2,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = ms_connect,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_connect
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
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
