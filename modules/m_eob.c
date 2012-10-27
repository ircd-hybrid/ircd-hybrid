/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_eob.c: Signifies the end of a server burst.
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
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"

static void ms_eob(struct Client*, struct Client*, int, char**);

struct Message eob_msgtab = {
  "EOB", 0, 0, 0, 0, MFLG_SLOW | MFLG_UNREG, 0, 
  {m_unregistered, m_ignore, ms_eob, m_ignore, m_ignore, m_ignore}
};
#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&eob_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&eob_msgtab);
}

const char *_version = "$Revision$";
#endif

/*
 * ms_eob - EOB command handler
 *      parv[0] = sender prefix   
 *      parv[1] = servername   
 */
static void
ms_eob(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
   sendto_realops_flags(UMODE_ALL, L_ALL, "End of burst from %s (%u seconds)",
                        source_p->name, 
			(unsigned int)(CurrentTime - source_p->firsttime));
   SetEob(client_p);
}
