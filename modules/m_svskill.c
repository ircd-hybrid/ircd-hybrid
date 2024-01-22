/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999 Bahamut development team.
 *  Copyright (c) 2013-2024 ircd-hybrid development team
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

/*! \file m_svskill.c
 * \brief Includes required functions for processing the SVSKILL command.
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"
#include "conf.h"


/*! \brief SVSKILL command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = timestamp
 *      - parv[3] = kill message
 */
static void
ms_svskill(struct Client *source_p, int parc, char *parv[])
{
  const char *comment = parv[3];  /* Either defined or NULL */

  if (!HasFlag(source_p, FLAGS_SERVICE))
    return;

  if (EmptyString(comment))
    comment = CONF_NOREASON;

  struct Client *target_p = find_person(source_p, parv[1]);
  if (target_p == NULL)
    return;

  uintmax_t ts = strtoumax(parv[2], NULL, 10);
  if (ts && (ts != target_p->tsinfo))
    return;

  if (MyConnect(target_p))
  {
    char reason[REASONLEN + 1] = "SVSKilled: ";
    strlcpy(reason + 11, comment, sizeof(reason) - 11);

    exit_client(target_p, reason);
    return;
  }

  if (target_p->from == source_p->from)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Received wrong-direction SVSKILL "
                         "for %s (behind %s) from %s",
                         target_p->name, source_p->from->name,
                         client_get_name(source_p, HIDE_IP));
    return;
  }

  sendto_one(target_p, ":%s SVSKILL %s %ju :%s", source_p->id,
             target_p->id, ts, comment);
}

static struct Message svskill_msgtab =
{
  .cmd = "SVSKILL",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_svskill, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&svskill_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&svskill_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
