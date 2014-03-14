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

/*! \file m_version.c
 * \brief Includes required functions for processing the VERSION command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/* Option string. */
static const char serveropts[] =
{
  'T',
  'S',
#ifdef TS_CURRENT
  '0' + TS_CURRENT,
#endif
/* ONLY do TS */
/* ALWAYS do TS_WARNINGS */
  'o',
  'w',
  '\0'
};

/*
 * m_version - VERSION command handler
 *      parv[0] = command
 *      parv[1] = remote server
 */
static int
m_version(struct Client *source_p, int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait_simple) > CurrentTime)
  {
    /* safe enough to give this on a local connect only */
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI);
    return 0;
  }

  last_used = CurrentTime;

  if (!ConfigServerHide.disable_remote_commands)
    if (hunt_server(source_p, ":%s VERSION :%s",
                    1, parc, parv) != HUNTED_ISME)
      return 0;

  sendto_one_numeric(source_p, &me, RPL_VERSION, ircd_version, serno,
                     me.name, serveropts);
  show_isupport(source_p);
  return 0;
}

/*
 * mo_version - VERSION command handler
 *      parv[0] = command
 *      parv[1] = remote server
 */
static int
mo_version(struct Client *source_p, int parc, char *parv[])
{
  if (hunt_server(source_p, ":%s VERSION :%s",
                  1, parc, parv) != HUNTED_ISME)
    return 0;


  sendto_one_numeric(source_p, &me, RPL_VERSION, ircd_version, serno,
                     me.name, serveropts);
  show_isupport(source_p);
  return 0;
}

/*
 * ms_version - VERSION command handler
 *      parv[0] = command
 *      parv[1] = remote server
 */
static int
ms_version(struct Client *source_p, int parc, char *parv[])
{
  if (hunt_server(source_p, ":%s VERSION :%s",
                  1, parc, parv) != HUNTED_ISME)
    return 0;

  sendto_one_numeric(source_p, &me, RPL_VERSION, ircd_version, serno,
                     me.name, serveropts);
  show_isupport(source_p);
  return 0;
}

static struct Message version_msgtab =
{
  "VERSION", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_version, ms_version, m_ignore, mo_version, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&version_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&version_msgtab);
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
