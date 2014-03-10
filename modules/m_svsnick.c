/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999 Bahamut development team.
 *  Copyright (c) 2011-2014 ircd-hybrid development team
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

/*! \file m_svsnick.c
 * \brief Includes required functions for processing the SVSNICK command.
 * \version $Id$
 */


#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "channel_mode.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"
#include "s_user.h"
#include "hash.h"
#include "watch.h"
#include "whowas.h"


/*! \brief SVSNICK command handler (called by services)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = old nickname
 *      - parv[2] = new nickname
 *      - parv[3] = timestamp
 */
static int
ms_svsnick(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL, *exists_p = NULL;

  if (!HasFlag(source_p, FLAGS_SERVICE) || !valid_nickname(parv[2], 1))
    return 0;

  if (hunt_server(client_p, source_p, ":%s SVSNICK %s %s :%s",
                  1, parc, parv) != HUNTED_ISME)
    return 0;

  if ((target_p = find_person(client_p, parv[1])) == NULL)
    return 0;

  assert(MyClient(target_p));

  if ((exists_p = hash_find_client(parv[2])))
  {
    if (IsUnknown(exists_p))
      exit_client(exists_p, &me, "SVSNICK Override");
    else
    {
      exit_client(target_p, &me, "SVSNICK Collide");
      return 0;
    }
  }

  target_p->tsinfo = atoi(parv[3]);
  clear_ban_cache_client(target_p);
  watch_check_hash(target_p, RPL_LOGOFF);

  if (HasUMode(target_p, UMODE_REGISTERED))
  {
    unsigned int oldmodes = target_p->umodes;
    char modebuf[IRCD_BUFSIZE] = { '\0' };

    DelUMode(target_p, UMODE_REGISTERED);
    send_umode(target_p, target_p, oldmodes, 0xffffffff, modebuf);
  }

  sendto_common_channels_local(target_p, 1, 0, ":%s!%s@%s NICK :%s",
                               target_p->name, target_p->username,
                               target_p->host, parv[2]);

  whowas_add_history(target_p, 1);

  sendto_server(NULL, NOCAPS, NOCAPS, ":%s NICK %s :%lu",
                ID(target_p), parv[2], (unsigned long)target_p->tsinfo);
  hash_del_client(target_p);
  strlcpy(target_p->name, parv[2], sizeof(target_p->name));
  hash_add_client(target_p);

  watch_check_hash(target_p, RPL_LOGON);

  fd_note(&target_p->localClient->fd, "Nick: %s", parv[2]);
  return 0;
}

static struct Message svsnick_msgtab =
{
  "SVSNICK", 0, 0, 4, MAXPARA, MFLG_SLOW, 0,
  {m_ignore, m_ignore, ms_svsnick, m_ignore, m_ignore, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&svsnick_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&svsnick_msgtab);
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
