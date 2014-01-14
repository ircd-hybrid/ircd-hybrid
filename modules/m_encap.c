/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2003-2014 ircd-hybrid development team
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

/*! \file m_encap.c
 * \brief Includes required functions for processing the ENCAP command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "parse.h"
#include "s_serv.h"
#include "send.h"
#include "modules.h"
#include "irc_string.h"


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
#ifdef NOT_USED_YET
  int paramcount, mpara = 0;
#endif
  struct Message *mptr = NULL;
  MessageHandler handler = 0;

  for (i = 1; i < (unsigned int)parc - 1; i++)
  {
    len = strlen(parv[i]) + 1;

    if ((cur_len + len) >= sizeof(buffer))
      return;

    snprintf(ptr, sizeof(buffer) - cur_len, "%s ", parv[i]);
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
    snprintf(ptr, sizeof(buffer) - cur_len, "%s", parv[2]);
  else
    snprintf(ptr, sizeof(buffer) - cur_len, ":%s", parv[parc - 1]);

  if ((cur_len + len) >= sizeof(buffer))
    buffer[sizeof(buffer) - 1] = '\0';

  sendto_match_servs(source_p, parv[1], CAP_ENCAP,
                     "ENCAP %s", buffer);

  if (match(parv[1], me.name))
    return;

  if ((mptr = find_command(parv[2])) == NULL)
    return;

#ifdef NOT_USED_YET
  paramcount = mptr->parameters;
  mpara      = mptr->maxpara;
#endif
  mptr->bytes += strlen(buffer);

  /*
   * Yes this is an ugly hack, but it is quicker than copying the
   * entire array again.
   *
   * Note: this hack wouldn't be needed if parv[0] were set to the
   * command name, rather than being derived from the prefix, as
   * it should have been from the beginning.
   */
  ptr = parv[0];
  parv += 2;
  parc -= 2;
  parv[0] = ptr;

  if ((handler = mptr->handlers[ENCAP_HANDLER]))
    (*handler)(client_p, source_p, parc, parv);
}

static struct Message encap_msgtab =
{
  "ENCAP", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_ignore, m_ignore, ms_encap, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&encap_msgtab);
  add_capability("ENCAP", CAP_ENCAP, 1);
}

static void
module_exit(void)
{
  mod_del_cmd(&encap_msgtab);
  delete_capability("ENCAP");
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
