/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_pass.c: Used to send a password for a server or client{} block.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#include "stdinc.h"
#include "client.h"      /* client struct */
#include "irc_string.h" 
#include "send.h"        /* sendto_one */
#include "numeric.h"     /* ERR_xxx */
#include "ircd.h"        /* me */
#include "parse.h"
#include "modules.h"
#include "s_serv.h"
#include "s_user.h"


/*
 * m_pass() - Added Sat, 4 March 1989
 *
 *
 * mr_pass - PASS message handler
 *      parv[0] = sender prefix
 *      parv[1] = password
 *      parv[2] = optional extra version information
 */
static void
mr_pass(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  char *password = parv[1];

  assert(client_p == source_p);

  if (EmptyString(password))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS), me.name,
               source_p->name[0] ? source_p->name : "*", "PASS");
    return;
  }

  MyFree(source_p->localClient->passwd);
  if (strlen(password) > PASSWDLEN)
    password[PASSWDLEN] = '\0';
  DupString(source_p->localClient->passwd, password);

  if (parc > 2)
  {
    /* It looks to me as if orabidoo wanted to have more
     * than one set of option strings possible here...
     * i.e. ":AABBTS" as long as TS was the last two chars
     * however, as we are now using CAPAB, I think we can
     * safely assume if there is a ":TS" then its a TS server
     * -Dianora
     */
    if (!irccmp(parv[2], "TS") && source_p->tsinfo == 0)
      source_p->tsinfo = TS_DOESTS;
  }

  /* only do this stuff if we are doing ts6 */
  if (parc > 4)
  {
    if (atoi(parv[3]) >= 6 && valid_sid(parv[4]))
    {
      strlcpy(source_p->id, parv[4], sizeof(source_p->id));
      SetCapable(source_p, CAP_TS6);
    }
  }
}

static struct Message pass_msgtab = {
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

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
