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

/*! \file m_rehash.c
 * \brief Includes required functions for processing the REHASH command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "res.h"
#include "conf.h"
#include "log.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "motd.h"


/*! \brief REHASH command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = additional option
 */
static int
mo_rehash(struct Client *source_p, int parc, char *parv[])
{
  int found = 0;

  if (!HasOFlag(source_p, OPER_FLAG_REHASH))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "rehash");
    return 0;
  }

  if (!EmptyString(parv[1]))
  {
    if (!irccmp(parv[1], "DNS"))
    {
      sendto_one_numeric(source_p, &me, RPL_REHASHING, "DNS");
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s is rehashing DNS",
                           get_oper_name(source_p));
      restart_resolver();
      found = 1;
    }
    else if (!irccmp(parv[1], "MOTD"))
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s is forcing re-reading of MOTD files",
                           get_oper_name(source_p));
      motd_recache();
      found = 1;
    }

    if (found)
      ilog(LOG_TYPE_IRCD, "REHASH %s From %s",
           parv[1], get_oper_name(source_p));
    else
      sendto_one_notice(source_p, &me, ":%s is not a valid option. "
                        "Choose from DNS, MOTD", parv[1]);
  }
  else
  {
    sendto_one_numeric(source_p, &me, RPL_REHASHING, ConfigFileEntry.configfile);
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s is rehashing configuration file(s)",
                         get_oper_name(source_p));
    ilog(LOG_TYPE_IRCD, "REHASH From %s",
         get_oper_name(source_p));
    rehash(0);
  }

  return 0;
}

static struct Message rehash_msgtab =
{
  "REHASH", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_rehash, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&rehash_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&rehash_msgtab);
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
