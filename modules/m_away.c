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

/*! \file m_away.c
 * \brief Includes required functions for processing the AWAY command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"
#include "s_serv.h"
#include "packet.h"
#include "s_user.h"


/*
 * m_away
 *  parv[0] = command
 *  parv[1] = away message
 */
static int
m_away(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  if (!IsFloodDone(source_p))
    flood_endgrace(source_p);

  if (parc < 2 || EmptyString(parv[1]))
  {
    /* Marking as not away */
    if (source_p->away[0])
    {
      source_p->away[0] = '\0';
      /* we now send this only if they were away before --is */
      sendto_server(client_p, CAP_TS6, NOCAPS,
                    ":%s AWAY", ID(source_p));
      sendto_server(client_p, NOCAPS, CAP_TS6,
                    ":%s AWAY", source_p->name);
      sendto_common_channels_local(source_p, 1, CAP_AWAY_NOTIFY,
                                   ":%s!%s@%s AWAY",
                                   source_p->name, source_p->username,
                                   source_p->host);
    }

    sendto_one(source_p, form_str(RPL_UNAWAY),
               me.name, source_p->name);
    return 0;
  }

  if ((CurrentTime - source_p->localClient->last_away) < ConfigFileEntry.pace_wait)
  {
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return 0;
  }

  source_p->localClient->last_away = CurrentTime;
  sendto_one(source_p, form_str(RPL_NOWAWAY), me.name, source_p->name);

  if (!strncmp(source_p->away, parv[1], sizeof(source_p->away) - 1))
    return 0;

  strlcpy(source_p->away, parv[1], sizeof(source_p->away));

  sendto_common_channels_local(source_p, 1, CAP_AWAY_NOTIFY,
                               ":%s!%s@%s AWAY :%s",
                               source_p->name, source_p->username,
                               source_p->host, source_p->away);
  sendto_server(client_p, CAP_TS6, NOCAPS,
                ":%s AWAY :%s", ID(source_p), source_p->away);
  sendto_server(client_p, NOCAPS, CAP_TS6,
                ":%s AWAY :%s", source_p->name, source_p->away);
  return 0;
}

static int
ms_away(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if (parc < 2 || EmptyString(parv[1]))
  {
    /* Marking as not away */
    if (source_p->away[0])
    {
      source_p->away[0] = '\0';
      /* we now send this only if they were away before --is */
      sendto_server(client_p, CAP_TS6, NOCAPS,
                    ":%s AWAY", ID(source_p));
      sendto_server(client_p, NOCAPS, CAP_TS6,
                    ":%s AWAY", source_p->name);
      sendto_common_channels_local(source_p, 1, CAP_AWAY_NOTIFY,
                                   ":%s!%s@%s AWAY",
                                   source_p->name, source_p->username,
                                   source_p->host);
    }

    return 0;
  }

  if (!strncmp(source_p->away, parv[1], sizeof(source_p->away) - 1))
    return 0;

  strlcpy(source_p->away, parv[1], sizeof(source_p->away));

  sendto_common_channels_local(source_p, 1, CAP_AWAY_NOTIFY,
                               ":%s!%s@%s AWAY :%s",
                               source_p->name, source_p->username,
                               source_p->host, source_p->away);
  sendto_server(client_p, CAP_TS6, NOCAPS,
                ":%s AWAY :%s", ID(source_p), source_p->away);
  sendto_server(client_p, NOCAPS, CAP_TS6,
                ":%s AWAY :%s", source_p->name, source_p->away);
  return 0;
}

static struct Message away_msgtab =
{
  "AWAY", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_away, ms_away, m_ignore, m_away, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&away_msgtab);
  add_isupport("AWAYLEN", NULL, AWAYLEN);
}

static void
module_exit(void)
{
  mod_del_cmd(&away_msgtab);
  delete_isupport("AWAYLEN");
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
