/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_error.c: Handles error messages from the other end.
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
#include "list.h"
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "msg.h"
#include "modules.h"
#include "s_log.h"


static void m_error(struct Client *, struct Client *, int, char *[]);
static void ms_error(struct Client *, struct Client *, int, char *[]);

struct Message error_msgtab = {
 "ERROR", 0, 0, 1, 0, MFLG_SLOW | MFLG_UNREG, 0,
  { m_error, m_ignore, ms_error, m_ignore, m_ignore, m_ignore }
};

void
_modinit(void)
{
  mod_add_cmd(&error_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&error_msgtab);
}

const char *_version = "$Revision$";

/*
 * Note: At least at protocol level ERROR has only one parameter.
 * --msa
 *
 *      parv[0] = sender prefix
 *      parv[*] = parameters
 */
void
m_error(struct Client *client_p, struct Client *source_p, 
        int parc, char *parv[])
{
  const char *para;

  para = (parc > 1 && *parv[1] != '\0') ? parv[1] : "<>";

  ilog(L_ERROR, "Received ERROR message from %s: %s",
       source_p->name, para);

  if (client_p == source_p)
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, "ERROR :from %s -- %s",
                         get_client_name(client_p, HIDE_IP), para);
    sendto_realops_flags(UMODE_ALL, L_OPER, "ERROR :from %s -- %s",
                         get_client_name(client_p, MASK_IP), para);
  }
  else
  {
    sendto_realops_flags(UMODE_ALL, L_OPER, "ERROR :from %s via %s -- %s",
                         source_p->name, get_client_name(client_p, MASK_IP), para);
    sendto_realops_flags(UMODE_ALL, L_ADMIN, "ERROR :from %s via %s -- %s",
                         source_p->name, get_client_name(client_p, HIDE_IP), para);
  }

  if (MyClient(source_p))
    exit_client(source_p, source_p, "ERROR");
}

void
ms_error(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  const char *para;

  para = (parc > 1 && *parv[1] != '\0') ? parv[1] : "<>";

  ilog(L_ERROR, "Received ERROR message from %s: %s",
       source_p->name, para);

  if (client_p == source_p)
    sendto_realops_flags(UMODE_ALL, L_ALL, "ERROR :from %s -- %s",
                         get_client_name(client_p, MASK_IP), para);
  else
    sendto_realops_flags(UMODE_ALL, L_ALL, "ERROR :from %s via %s -- %s",
                         source_p->name,
                         get_client_name(client_p, MASK_IP), para);
}
