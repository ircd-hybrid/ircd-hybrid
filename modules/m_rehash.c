/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
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
  const char *const option = parv[1];

  if (!HasOFlag(source_p, OPER_FLAG_REHASH))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "rehash");
    return 0;
  }

  if (!EmptyString(option))
  {
    if (!irccmp(option, "DNS"))
    {
      sendto_one_numeric(source_p, &me, RPL_REHASHING, "DNS");
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                           "%s is rehashing DNS",
                           get_oper_name(source_p));
      restart_resolver();
      found = 1;
    }
    else if (!irccmp(option, "MOTD"))
    {
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                           "%s is forcing re-reading of MOTD files",
                           get_oper_name(source_p));
      motd_recache();
      found = 1;
    }

    if (found)
      ilog(LOG_TYPE_IRCD, "REHASH %s From %s",
           option, get_oper_name(source_p));
    else
      sendto_one_notice(source_p, &me, ":%s is not a valid option. "
                        "Choose from DNS, MOTD", option);
  }
  else
  {
    sendto_one_numeric(source_p, &me, RPL_REHASHING, ConfigGeneral.configfile);
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s is rehashing configuration file(s)",
                         get_oper_name(source_p));
    ilog(LOG_TYPE_IRCD, "REHASH From %s",
         get_oper_name(source_p));
    conf_rehash(0);
  }

  return 0;
}

static struct Message rehash_msgtab =
{
  .cmd = "REHASH",
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_not_oper,
  .handlers[SERVER_HANDLER] = m_ignore,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_rehash
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
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
