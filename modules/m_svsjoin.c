/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2014-2014 ircd-hybrid development team
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

/*! \file m_svsjoin.c
 * \brief Includes required functions for processing the SVSJOIN command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "server.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"
#include "resv.h"


/*! \brief SVSJOIN command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = channel
 *      - parv[3] = channel password (key)
 */
static int
ms_svsjoin(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;

  if (!HasFlag(source_p, FLAGS_SERVICE))
    return 0;

  if (EmptyString(parv[2]))
    return 0;

  if ((target_p = find_person(source_p, parv[1])) == NULL)
    return 0;

  if (MyConnect(target_p))
  {
    channel_do_join(target_p, parv[2], parv[3]);
    return 0;
  }

  if (target_p->from == source_p->from)
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "Received wrong-direction SVSJOIN "
                         "for %s (behind %s) from %s",
                         target_p->name, source_p->from->name,
                         get_client_name(source_p, HIDE_IP));
    return 0;
  }

  if (parc == 3)
    sendto_one(target_p, ":%s SVSJOIN %s %s", source_p->id,
               target_p->id, parv[2]);
  else
    sendto_one(target_p, ":%s SVSJOIN %s %s %s", source_p->id,
               target_p->id, parv[2], parv[3]);
  return 0;
}

static struct Message svsjoin_msgtab =
{
  "SVSJOIN", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_ignore, ms_svsjoin, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&svsjoin_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&svsjoin_msgtab);
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
