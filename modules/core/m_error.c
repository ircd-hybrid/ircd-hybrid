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
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "modules.h"
#include "log.h"
#include "parse.h"
#include "irc_string.h"


/*
 * Note: At least at protocol level ERROR has only one parameter.
 * --msa
 *
 *      parv[0] = sender prefix
 *      parv[*] = parameters
 */
static void
m_error(struct Client *client_p, struct Client *source_p, 
        int parc, char *parv[])
{
  const char *para = (parc > 1 && !EmptyString(parv[1])) ? parv[1] : "<>";

  assert(source_p == client_p);

  if (!IsHandshake(source_p) && !IsConnecting(source_p))
    return;

  ilog(LOG_TYPE_IRCD, "Received ERROR message from %s: %s",
       source_p->name, para);

  if (client_p == source_p)
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "ERROR :from %s -- %s",
                         get_client_name(client_p, HIDE_IP), para);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "ERROR :from %s -- %s",
                         get_client_name(client_p, MASK_IP), para);
  }
  else
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "ERROR :from %s via %s -- %s",
                         source_p->name, get_client_name(client_p, HIDE_IP), para);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "ERROR :from %s via %s -- %s",
                         source_p->name, get_client_name(client_p, MASK_IP), para);
  }
}

static void
ms_error(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  const char *para = (parc > 1 && !EmptyString(parv[1])) ? parv[1] : "<>";

  ilog(LOG_TYPE_IRCD, "Received ERROR message from %s: %s",
       source_p->name, para);

  if (client_p == source_p)
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "ERROR :from %s -- %s",
                         get_client_name(client_p, MASK_IP), para);
  else
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "ERROR :from %s via %s -- %s",
                         source_p->name,
                         get_client_name(client_p, MASK_IP), para);
}

static struct Message error_msgtab = {
 "ERROR", 0, 0, 1, MAXPARA, MFLG_SLOW, 0,
  { m_error, m_ignore, ms_error, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&error_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&error_msgtab);
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
