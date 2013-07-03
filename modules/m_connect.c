/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_connect.c: Connects to a remote IRC server.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
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
#include "s_serv.h"
#include "send.h"
#include "parse.h"
#include "hash.h"
#include "modules.h"


/*
 * mo_connect - CONNECT command handler
 * 
 * Added by Jto 11 Feb 1989
 *
 * m_connect
 *      parv[0] = sender prefix
 *      parv[1] = servername
 *      parv[2] = port number
 *      parv[3] = remote server
 */
static void
mo_connect(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  int port;
  int tmpport;
  struct MaskItem *conf = NULL;
  const struct Client *target_p = NULL;

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "CONNECT");
    return;
  }

  if (parc > 3)
  {
    if (!HasOFlag(source_p, OPER_FLAG_CONNECT_REMOTE))
    {
      sendto_one(source_p, form_str(ERR_NOPRIVS),
                 me.name, source_p->name, "connect");
      return;
    }

    if (hunt_server(client_p, source_p, ":%s CONNECT %s %s :%s", 3,
                    parc, parv) != HUNTED_ISME)
      return;
  }
  else if (!HasOFlag(source_p, OPER_FLAG_CONNECT))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "connect");
    return;
  }

  if ((target_p = hash_find_server(parv[1])))
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Connect: Server %s already exists from %s.",
               me.name, source_p->name, parv[1], target_p->from->name);
    return;
  }

  /*
   * try to find the name, then host, if both fail notify ops and bail
   */
  if (!(conf = find_matching_name_conf(CONF_SERVER, parv[1], NULL, NULL, 0)))
  {
    if  (!(conf = find_matching_name_conf(CONF_SERVER,  NULL, NULL, parv[1], 0)))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :Connect: Host %s not listed in ircd.conf",
                 me.name, source_p->name, parv[1]);
      return;
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
      sendto_one(source_p, ":%s NOTICE %s :Connect: Illegal port number",
                 me.name, source_p->name);
      return;
    }
  }
  else if (port <= 0 && (port = PORTNUM) <= 0)
  {
    sendto_one(source_p, ":%s NOTICE %s :Connect: missing port number",
               me.name, source_p->name);
    return;
  }

  if (find_servconn_in_progress(conf->name))
  {
    sendto_one(source_p, ":%s NOTICE %s :Connect: a connection to %s "
               "is already in progress.", me.name, source_p->name, conf->name);
    return;
  }

  /*
   * Notify all operators about remote connect requests
   */
  ilog(LOG_TYPE_IRCD, "CONNECT From %s : %s %s", 
       source_p->name, parv[1], parv[2] ? parv[2] : "");

  conf->port = port;

  /*
   * at this point we should be calling connect_server with a valid
   * C:line and a valid port in the C:line
   */
  if (serv_connect(conf, source_p))
  {
    if (!ConfigServerHide.hide_server_ips && HasUMode(source_p, UMODE_ADMIN))
      sendto_one(source_p, ":%s NOTICE %s :*** Connecting to %s[%s].%d",
                 me.name, source_p->name, conf->host,
                 conf->name, conf->port);
    else
      sendto_one(source_p, ":%s NOTICE %s :*** Connecting to %s.%d",
                 me.name, source_p->name, conf->name, conf->port);
  }
  else
  {
    sendto_one(source_p, ":%s NOTICE %s :*** Couldn't connect to %s.%d",
               me.name, source_p->name, conf->name, conf->port);
  }

  /*
   * Client is either connecting with all the data it needs or has been
   * destroyed
   */
  conf->port = tmpport;
}

/*
 * ms_connect - CONNECT command handler
 * 
 * Added by Jto 11 Feb 1989
 *
 * m_connect
 *      parv[0] = sender prefix
 *      parv[1] = servername
 *      parv[2] = port number
 *      parv[3] = remote server
 */
static void
ms_connect(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  int port;
  int tmpport;
  struct MaskItem *conf = NULL;
  const struct Client *target_p = NULL;

  if (hunt_server(client_p, source_p, ":%s CONNECT %s %s :%s",
                  3, parc, parv) != HUNTED_ISME)
    return;

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "CONNECT");
    return;
  }

  if ((target_p = hash_find_server(parv[1])))
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Connect: Server %s already exists from %s.",
               me.name, source_p->name, parv[1], target_p->from->name);
    return;
  }

  /*
   * try to find the name, then host, if both fail notify ops and bail
   */
  if (!(conf = find_matching_name_conf(CONF_SERVER, parv[1], NULL, NULL, 0)))
  { 
    if  (!(conf = find_matching_name_conf(CONF_SERVER,  NULL, NULL, parv[1], 0)))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :Connect: Host %s not listed in ircd.conf",
                 me.name, source_p->name, parv[1]);
      return;
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
     * if someone sends port 0, and we have a config port.. use it
     */
    if (port == 0 && conf->port)
      port = conf->port;
    else if (port <= 0)
    {
      sendto_one(source_p, ":%s NOTICE %s :Connect: Illegal port number",
                 me.name, source_p->name);
      return;
    }
  }
  else if (port <= 0 && (port = PORTNUM) <= 0)
  {
    sendto_one(source_p, ":%s NOTICE %s :Connect: missing port number",
               me.name, source_p->name);
    return;
  }

  if (find_servconn_in_progress(conf->name))
  {
    sendto_one(source_p, ":%s NOTICE %s :Connect: a connection to %s "
               "is already in progress.", me.name, source_p->name, conf->name);
    return;
  }

  /*
   * Notify all operators about remote connect requests
   */
  sendto_wallops_flags(UMODE_WALLOP, &me, "Remote CONNECT %s %d from %s",
                       parv[1], port, source_p->name);
  sendto_server(NULL, NOCAPS, CAP_TS6,
                ":%s WALLOPS :Remote CONNECT %s %d from %s",
                me.name, parv[1], port, source_p->name);
  sendto_server(NULL, CAP_TS6, NOCAPS,
                ":%s WALLOPS :Remote CONNECT %s %d from %s",
                me.id, parv[1], port, source_p->name);

  ilog(LOG_TYPE_IRCD, "CONNECT From %s : %s %d", 
       source_p->name, parv[1], port);

  conf->port = port;

  /*
   * At this point we should be calling connect_server with a valid
   * C:line and a valid port in the C:line
   */
  if (serv_connect(conf, source_p))
    sendto_one(source_p, ":%s NOTICE %s :*** Connecting to %s.%d",
               me.name, source_p->name, conf->name, conf->port);
  else
    sendto_one(source_p, ":%s NOTICE %s :*** Couldn't connect to %s.%d",
               me.name, source_p->name, conf->name, conf->port);
  /*
   * Client is either connecting with all the data it needs or has been
   * destroyed
   */
  conf->port = tmpport;
}

static struct Message connect_msgtab = {
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

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
