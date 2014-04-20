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

/*! \file m_whowas.c
 * \brief Includes required functions for processing the WHOWAS command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "whowas.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "numeric.h"
#include "s_misc.h"
#include "s_serv.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"


static void
do_whowas(struct Client *source_p, const int parc, char *parv[])
{
  int cur = 0;
  int max = -1;
  const dlink_node *ptr = NULL;

  if (parc > 2 && !EmptyString(parv[2]))
    if ((max = atoi(parv[2])) > 20 && !MyConnect(source_p))
      max = 20;

  DLINK_FOREACH(ptr, WHOWASHASH[strhash(parv[1])].head)
  {
    const struct Whowas *temp = ptr->data;

    if (!irccmp(parv[1], temp->name))
    {
      sendto_one_numeric(source_p, &me, RPL_WHOWASUSER, temp->name,
                         temp->username, temp->hostname,
                         temp->realname);

      if ((temp->shide || ConfigServerHide.hide_servers) && !HasUMode(source_p, UMODE_OPER))
        sendto_one_numeric(source_p, &me, RPL_WHOISSERVER, temp->name,
                           ServerInfo.network_name, myctime(temp->logoff));
      else
        sendto_one_numeric(source_p, &me, RPL_WHOISSERVER, temp->name,
                           temp->servername, myctime(temp->logoff));
      ++cur;
    }

    if (max > 0 && cur >= max)
      break;
  }

  if (!cur)
    sendto_one_numeric(source_p, &me, ERR_WASNOSUCHNICK, parv[1]);

  sendto_one_numeric(source_p, &me, RPL_ENDOFWHOWAS, parv[1]);
}

/*! \brief WHOWAS command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = count
 *      - parv[3] = nickname/servername
 */
static int
m_whowas(struct Client *source_p, int parc, char *parv[])
{
  static time_t last_used = 0;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NONICKNAMEGIVEN);
    return 0;
  }

  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI);
    return 0;
  }

  last_used = CurrentTime;

  if (parc > 3 && !ConfigServerHide.disable_remote_commands)
    if (hunt_server(source_p, ":%s WHOWAS %s %s :%s", 3,
                    parc, parv) != HUNTED_ISME)
      return 0;

  do_whowas(source_p, parc, parv);
  return 0;
}

/*! \brief WHOWAS command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = count
 *      - parv[3] = nickname/servername
 */
static int
ms_whowas(struct Client *source_p, int parc, char *parv[])
{
  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NONICKNAMEGIVEN);
    return 0;
  }

  if (parc > 3)
    if (hunt_server(source_p, ":%s WHOWAS %s %s :%s", 3,
                    parc, parv) != HUNTED_ISME)
      return 0;

  do_whowas(source_p, parc, parv);
  return 0;
}

static struct Message whowas_msgtab =
{
  "WHOWAS", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_whowas, ms_whowas, m_ignore, ms_whowas, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&whowas_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&whowas_msgtab);
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
