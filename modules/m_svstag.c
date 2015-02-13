/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015-2015 ircd-hybrid development team
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

/*! \file m_svstag.c
 * \brief Includes required functions for processing the SVSTAG command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "channel_mode.h"
#include "parse.h"
#include "memory.h"
#include "modules.h"
#include "irc_string.h"
#include "user.h"
#include "conf.h"


/*! \brief SVSTAG command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = TS
 *      - parv[3] = [-][raw]
 *      - parv[4] = required user mode(s) to see the tag
 *      - parv[5] = tag line
 */
static int
ms_svstag(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  time_t ts = 0;

  if (!HasFlag(source_p, FLAGS_SERVICE) && !IsServer(source_p))
    return 0;

  if ((target_p = find_person(source_p, parv[1])) == NULL)
    return 0;

  if ((ts = atol(parv[2])) && ts != target_p->tsinfo)
    return 0;

  if (!strncmp(parv[3], "-", 1))
  {
    /* XXX: possibly allow to remove certain tags by numeric */
    client_clear_svstags(target_p);
    sendto_server(source_p, 0, 0, ":%s SVSTAG %s %lu %s",
                  source_p->id,
                  target_p->id, (unsigned long)target_p->tsinfo, parv[3]);
    return 0;
  }

  if (parc < 6 || EmptyString(parv[5]))
    return 0;

  client_attach_svstag(target_p, strtoul(parv[3], NULL, 10),
                       parv[4], parv[5]);

  sendto_server(source_p, 0, 0, ":%s SVSTAG %s %lu %s %s :%s",
                source_p->id,
                target_p->id, (unsigned long)target_p->tsinfo,
                parv[3], parv[4], parv[5]);
  return 0;
}

static struct Message svstag_msgtab =
{
  "SVSTAG", NULL, 0, 0, 4, MAXPARA, MFLG_SLOW, 0,
  { m_ignore, m_ignore, ms_svstag, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&svstag_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&svstag_msgtab);
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
