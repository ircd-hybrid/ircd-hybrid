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
 *      - parv[2] = optional extra version information
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

  MyFree(source_p->localClient->passwd);
  source_p->localClient->passwd = xstrndup(parv[1], IRCD_MIN(strlen(parv[1]), PASSWDLEN));

  if (parc > 2)
  {
    /*
     * It looks to me as if orabidoo wanted to have more
     * than one set of option strings possible here...
     * i.e. ":AABBTS" as long as TS was the last two chars
     * however, as we are now using CAPAB, I think we can
     * safely assume if there is a ":TS" then it's a TS server
     * -Dianora
     */
    if (!irccmp(parv[2], "TS") && source_p->tsinfo == 0)
      source_p->tsinfo = TS_DOESTS;
  }

  /* Only do this stuff if we are doing ts6 */
  if (parc > 4)
  {
    if (atoi(parv[3]) >= 6 && valid_sid(parv[4]))
    {
      strlcpy(source_p->id, parv[4], sizeof(source_p->id));
      SetCapable(source_p, CAP_TS6);
    }
  }

  return 0;
}

static struct Message pass_msgtab =
{
  "PASS", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
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
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
