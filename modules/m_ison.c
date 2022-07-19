/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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

/*! \file m_ison.c
 * \brief Includes required functions for processing the ISON command.
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/*! \brief ISON command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = space-separated list of nicknames
 */
static void
m_ison(struct Client *source_p, int parc, char *parv[])
{
  char buf[IRCD_BUFSIZE] = "";  /* Essential that buf[0] = '\0' */
  char *bufptr = buf, *p = NULL;

  /* :me.name 303 source_p->name :nick1 nick2 ...      \r\n */
  /* 1       23456              78                     9 10 */
  size_t len = strlen(me.name) + strlen(source_p->name) + 10;


  for (const char *name = strtok_r(parv[1], " ", &p); name;
                   name = strtok_r(NULL,    " ", &p))
  {
    const struct Client *target_p = find_person(source_p, name);
    if (target_p == NULL)
      continue;

    if ((bufptr - buf) + strlen(target_p->name) + len + 1 /* +1 for space */ > sizeof(buf))
      break;

    bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), "%s ", target_p->name);
  }

  if (bufptr != buf)
    *(bufptr - 1) = '\0';  /* Get rid of trailing space on buffer */

  sendto_one_numeric(source_p, &me, RPL_ISON, buf);
}

static struct Message ison_msgtab =
{
  .cmd = "ISON",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ison, .args_min = 2, .args_max = 1 },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ison, .args_min = 2, .args_max = 1 }
};

static void
module_init(void)
{
  mod_add_cmd(&ison_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&ison_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
