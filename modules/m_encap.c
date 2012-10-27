/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_encap.c: encapsulated command propagation and parsing
 *
 *  Copyright (C) 2003 by the past and present ircd coders, and others.
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
#include "msg.h"
#include "parse.h"
#include "sprintf_irc.h"
#include "s_serv.h"
#include "send.h"
#include "modules.h"
#include "irc_string.h"

static void ms_encap(struct Client *, struct Client *, int, char *[]);

struct Message encap_msgtab = {
  "ENCAP", 0, 0, 3, 0, MFLG_SLOW, 0,
  {m_ignore, m_ignore, ms_encap, m_ignore, m_ignore, m_ignore}
};

void
_modinit(void)
{
  mod_add_cmd(&encap_msgtab);
  add_capability("ENCAP", CAP_ENCAP, 1);
}

void
_moddeinit(void)
{
  mod_del_cmd(&encap_msgtab);
  delete_capability("ENCAP");
}
const char *_version = "$Revision$";

/*
 * ms_encap()
 *
 * inputs	- destination server, subcommand, parameters
 * output	- none
 * side effects	- propagates subcommand to locally connected servers
 */
static void
ms_encap(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char buffer[IRCD_BUFSIZE], *ptr = buffer;
  unsigned int cur_len = 0, len, i;
  int paramcount, mpara = 0;
  struct Message *mptr = NULL;
  MessageHandler handler = 0;

  for (i = 1; i < (unsigned int)parc - 1; i++)
  {
    len = strlen(parv[i]) + 1;

    if ((cur_len + len) >= sizeof(buffer))
      return;

    ircsprintf(ptr, "%s ", parv[i]);
    cur_len += len;
    ptr += len;
  }

  len = strlen(parv[i]);

  /*
   * if the final parameter crosses our buffer size, should we bail, 
   * like the rest, or should we truncate?  ratbox seems to think truncate,
   * so i'll do that for now until i can talk to lee.  -bill
   */

  if (parc == 3)
    ircsprintf(ptr, "%s", parv[2]);
  else
    ircsprintf(ptr, ":%s", parv[parc-1]);

  if ((cur_len + len) >= sizeof(buffer))
    buffer[sizeof(buffer)-1] = '\0';

  sendto_match_servs(source_p, parv[1], CAP_ENCAP,
                     "ENCAP %s", buffer);

  if (!match(parv[1], me.name))
    return;

  if ((mptr = find_command(parv[2])) == NULL)
    return;

  paramcount = mptr->parameters;
  mpara      = mptr->maxpara;

  mptr->bytes += strlen(buffer);

  /*
   * yes this is an ugly hack, but it is quicker than copying the entire array again
   * note: this hack wouldnt be needed if parv[0] were set to the command name, rather
   * than being derived from the prefix, as it should have been from the beginning.
   */
  ptr = parv[0];
  parv += 2;
  parc -= 2;
  parv[0] = ptr;

  if ((handler = mptr->handlers[ENCAP_HANDLER]) == NULL)
    return;

  (*handler)(client_p, source_p, parc, parv);
}
