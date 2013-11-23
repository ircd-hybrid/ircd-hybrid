/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 1999 by the Bahamut Development Team.
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

/*! \file m_svskill.c
 * \brief Includes required functions for processing the SVSKILL command.
 * \version $Id: m_svskill.c 2511 2013-10-27 18:56:53Z michael $
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "s_serv.h"
#include "send.h"
#include "channel_mode.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"
#include "s_user.h"
#include "conf.h"


/*! \brief SVSKILL command handler (called by services)
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
 *      - parv[3] = kill message
 */
static void
ms_svskill(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  const char *comment = NULL;
  char reason[KICKLEN + 1] = "SVSKilled: ";
  time_t ts = 0;

  if (!HasFlag(source_p, FLAGS_SERVICE))
    return;

  if (EmptyString(parv[1]))
    return;

  if (parc > 3)
  {
    comment = parv[3] ? parv[3] : source_p->name;
    ts = atol(parv[2]);
  }
  else
    comment = (parc > 2 && parv[2]) ? parv[2] : source_p->name;

  if ((target_p = find_person(client_p, parv[1])) == NULL)
    return;

  if (ts && (ts != target_p->tsinfo))
    return;

  if (MyClient(target_p))
  {
    strlcpy(reason + 11, comment, sizeof(reason) - 11);
    exit_client(target_p, target_p, reason);
    return;
  }

  if (target_p->from == client_p)
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "Received wrong-direction SVSKILL "
                         "for %s (behind %s) from %s",
                         target_p->name, client_p->name,
                         get_client_name(source_p, HIDE_IP));
    return;
  }

  if (ts == 0)
    sendto_one(target_p, ":%s SVSKILL %s :%s",
               ID_or_name(source_p, target_p->from),
               ID_or_name(target_p, target_p->from), comment);
  else
    sendto_one(target_p, ":%s SVSKILL %s %lu :%s",
               ID_or_name(source_p, target_p->from),
               ID_or_name(target_p, target_p->from), ts, comment);
}

static struct Message svskill_msgtab = {
  "SVSKILL", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  {m_ignore, m_ignore, ms_svskill, m_ignore, m_ignore, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&svskill_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&svskill_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision: 2511 $",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
