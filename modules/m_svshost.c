/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2016-2016 ircd-hybrid development team
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

/*! \file m_svshost.c
 * \brief Includes required functions for processing the SVSHOST command.
 * \version $Id: m_svshost.c 7329 2016-02-18 21:07:50Z michael $
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "channel_mode.h"
#include "parse.h"
#include "modules.h"
#include "user.h"


/*! \brief SVSHOST command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = TS
 *      - parv[3] = +|-
 *      - parv[4] = host name
 */
static int
ms_svshost(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  int what = MODE_ADD;

  if (!HasFlag(source_p, FLAGS_SERVICE))
    return 0;

  if ((target_p = find_person(source_p, parv[1])) == NULL)
    return 0;

  uintmax_t ts = strtoumax(parv[2], NULL, 10);
  if (ts && (ts != target_p->tsinfo))
    return 0;

  switch (*parv[3])
  {
    case '+':
      what = MODE_ADD;
      break;
    case '-':
      what = MODE_DEL;
      break;
    default: return 0;
  }

  if (valid_hostname(parv[4]))
    user_set_hostmask(target_p, parv[4], what);

  sendto_server(source_p, 0, 0, ":%s SVSHOST %s %ju %s %s",
                source_p->id,
                target_p->id, target_p->tsinfo, parv[3], parv[4]);
  return 0;
}

static struct Message svshost_msgtab =
{
  .cmd = "SVSHOST",
  .args_min = 5,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_ignore,
  .handlers[CLIENT_HANDLER] = m_ignore,
  .handlers[SERVER_HANDLER] = ms_svshost,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = m_ignore
};

static void
module_init(void)
{
  mod_add_cmd(&svshost_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&svshost_msgtab);
}

struct module module_entry =
{
  .version = "$Revision: 7329 $",
  .modinit = module_init,
  .modexit = module_exit,
};
