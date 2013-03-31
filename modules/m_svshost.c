/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 2013 by the Hybrid Development Team.
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

/*! \file m_svshost.c
 * \brief Includes required functions for processing the SVSHOST command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "channel_mode.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"
#include "s_user.h"
#include "conf.h"
#include "userhost.h"


/*! \brief SVSHOST command handler (called by services)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = sender prefix
 *      - parv[1] = nickname
 *      - parv[2] = TS
 *      - parv[3] = hostname
 */
static void
ms_svshost(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;
  time_t ts = 0;

  if (!HasFlag(source_p, FLAGS_SERVICE))
    return;

  if ((target_p = find_person(client_p, parv[1])) == NULL)
    return;

  if ((ts = atol(parv[2])) && (ts != target_p->tsinfo))
    return;

  if (!valid_hostname(parv[3]))
    return;

  if (IsUserHostIp(target_p))
    delete_user_host(target_p->username, target_p->host, !MyConnect(target_p));

  strlcpy(target_p->host, parv[3], sizeof(target_p->host));
  SetIPSpoof(target_p);

  add_user_host(target_p->username, target_p->host, !MyConnect(target_p));
  SetUserHost(target_p);

  if (MyClient(target_p))
    clear_ban_cache_client(target_p);

  sendto_server(client_p, CAP_TS6, NOCAPS,
                ":%s SVSHOST %s %lu %s", ID(source_p),
                ID(target_p), (unsigned long)target_p->tsinfo, parv[3]);
  sendto_server(client_p, NOCAPS, CAP_TS6,
                ":%s SVSHOST %s %lu %s", source_p->name,
                target_p->name, (unsigned long)target_p->tsinfo, parv[3]);
}

static struct Message svshost_msgtab = {
  "SVSHOST", 0, 0, 4, MAXPARA, MFLG_SLOW, 0,
  {m_ignore, m_ignore, ms_svshost, m_ignore, m_ignore, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&svshost_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&svshost_msgtab);
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
