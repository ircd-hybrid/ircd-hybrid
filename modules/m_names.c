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

/*! \file m_names.c
 * \brief Includes required functions for processing the NAMES command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/*
** m_names
**      parv[0] = command
**      parv[1] = channel
*/
static int
m_names(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  char *s = NULL;
  char *para = parc > 1 ? parv[1] : NULL;

  if (!EmptyString(para))
  {
    if ((s = strchr(para, ',')))
      *s = '\0';

    if (*para == '\0')
      return 0;

    if ((chptr = hash_find_channel(para)))
      channel_member_names(source_p, chptr, 1);
    else
      sendto_one_numeric(source_p, &me, RPL_ENDOFNAMES, para);
  }
  else
    sendto_one_numeric(source_p, &me, RPL_ENDOFNAMES, "*");

  return 0;
}

static struct Message names_msgtab =
{
  "NAMES", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_names, m_ignore, m_ignore, m_names, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&names_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&names_msgtab);
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
