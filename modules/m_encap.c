/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2003-2022 ircd-hybrid development team
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

/*! \file m_encap.c
 * \brief Includes required functions for processing the ENCAP command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "parse.h"
#include "server_capab.h"
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
ms_encap(struct Client *source_p, int parc, char *parv[])
{
  char buf[IRCD_BUFSIZE];
  char *bufptr = buf;
  unsigned int cur_len = 0, len;

  for (unsigned int i = 1; i < (unsigned int)parc - 1; ++i)
  {
    len = strlen(parv[i]) + 1;  /* +1 for the space */

    /* Drop the whole command if this parameter would be truncated */
    if ((cur_len + len) >= sizeof(buf))
      return;

    snprintf(bufptr, sizeof(buf) - cur_len, "%s ", parv[i]);
    cur_len += len;
    bufptr += len;
  }

  /* If it's a command without parameters, don't prepend a ':' */
  if (parc == 3)
    snprintf(bufptr, sizeof(buf) - cur_len, "%s", parv[2]);
  else
    snprintf(bufptr, sizeof(buf) - cur_len, ":%s", parv[parc - 1]);

  sendto_match_servs(source_p, parv[1], CAPAB_ENCAP, "ENCAP %s", buf);

  if (match(parv[1], me.name))
    return;

  struct Message *message = find_command(parv[2]);
  if (message == NULL)
    return;

  const struct MessageHandler *const handler = &message->handlers[ENCAP_HANDLER];
  message->bytes += strlen(buf);
  message->ecount++;

  parv += 2;
  parc -= 2;

  if (handler->args_min &&
      (((unsigned int)parc < handler->args_min) ||
       (handler->empty_last_arg != true && EmptyString(parv[handler->args_min - 1]))))
    return;

  handler->handler(source_p, parc, parv);
}

static struct Message encap_msgtab =
{
  .cmd = "ENCAP",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_ignore },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_encap, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&encap_msgtab);
  capab_add("ENCAP", CAPAB_ENCAP, true);
}

static void
module_exit(void)
{
  mod_del_cmd(&encap_msgtab);
  capab_del("ENCAP");
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
