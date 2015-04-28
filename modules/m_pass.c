/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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

/*! \file m_pass.c
 * \brief Includes required functions for processing the PASS command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "send.h"
#include "numeric.h"
#include "ircd.h"
#include "parse.h"
#include "modules.h"
#include "server.h"
#include "user.h"
#include "misc.h"
#include "memory.h"


/*! \brief PASS command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = password
 *      - parv[2] = unused
 *      - parv[3] = TS protocol version
 *      - parv[4] = server ID (SID)
 */
static int
mr_pass(struct Client *source_p, int parc, char *parv[])
{
  assert(MyConnect(source_p));

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "PASS");
    return 0;
  }

  MyFree(source_p->connection->password);
  source_p->connection->password = xstrndup(parv[1], IRCD_MIN(strlen(parv[1]), PASSWDLEN));

  /* Only do this stuff if we are doing ts6 */
  if (parc > 4)
    if (atoi(parv[3]) >= 6 && valid_sid(parv[4]))
      strlcpy(source_p->id, parv[4], sizeof(source_p->id));

  return 0;
}

static struct Message pass_msgtab =
{
  "PASS", NULL, 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { mr_pass, m_registered, m_ignore, m_ignore, m_registered, mr_pass }
};

static void
module_init(void)
{
  mod_add_cmd(&pass_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&pass_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
