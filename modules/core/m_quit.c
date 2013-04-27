/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_quit.c: Makes a user quit from IRC.
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
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "s_serv.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"


/*
** m_quit
**      parv[0] = sender prefix
**      parv[1] = comment
*/
static void
m_quit(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  char reason[KICKLEN + 1] = "Quit: ";

  if (!EmptyString(parv[1]) && (HasUMode(source_p, UMODE_OPER) ||
      (source_p->localClient->firsttime + ConfigFileEntry.anti_spam_exit_message_time)
      < CurrentTime))
    strlcpy(reason + 6, parv[1], sizeof(reason) - 6);

  exit_client(source_p, source_p, reason);
}

/*
** ms_quit
**      parv[0] = sender prefix
**      parv[1] = comment
*/
static void
ms_quit(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  char reason[KICKLEN + 1] = { '\0' };

  if (!EmptyString(parv[1]))
    strlcpy(reason, parv[1], sizeof(reason));
  else
    strlcpy(reason, client_p->name, sizeof(reason));

  exit_client(source_p, source_p, reason);
}

static struct Message quit_msgtab = {
  "QUIT", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  {m_quit, m_quit, ms_quit, m_ignore, m_quit, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&quit_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&quit_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
