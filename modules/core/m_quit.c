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
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_conf.h"

static void m_quit(struct Client *, struct Client *, int, char *[]);
static void ms_quit(struct Client *, struct Client *, int, char *[]);

struct Message quit_msgtab = {
  "QUIT", 0, 0, 0, 0, MFLG_SLOW | MFLG_UNREG, 0,
  {m_quit, m_quit, ms_quit, m_ignore, m_quit, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&quit_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&quit_msgtab);
}

const char *_version = "$Revision$";
#endif

/*
** m_quit
**      parv[0] = sender prefix
**      parv[1] = comment
*/
static void
m_quit(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  char *comment = (parc > 1 && parv[1]) ? parv[1] : client_p->name;
  char reason[KICKLEN + 1] = "Quit: ";

  if (comment[0] && (IsOper(source_p) ||
      (source_p->firsttime + ConfigFileEntry.anti_spam_exit_message_time)
      < CurrentTime))
    strlcpy(reason+6, comment, sizeof(reason)-6);
  else
    strlcpy(reason, "Client Quit", sizeof(reason));

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
  char *comment = (parc > 1 && parv[1]) ? parv[1] : client_p->name;

  if (strlen(comment) > (size_t)KICKLEN)
    comment[KICKLEN] = '\0';

  exit_client(source_p, source_p, comment);
}
