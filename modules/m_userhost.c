/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*! \file m_userhost.c
 * \brief Includes required functions for processing the USERHOST command.
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "irc_string.h"
#include "parse.h"
#include "modules.h"


/** See 5.7 Userhost message in RFC1459 */
enum { RFC1459_MAX_USERHOST_LIST = 5 };


/*! \brief USERHOST command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = space-separated list of up to 5 nicknames
 */
static void
m_userhost(struct Client *source_p, int parc, char *parv[])
{
  char response[NICKLEN + USERLEN + HOSTLEN + 5]; /* +5 for "*=+@\0" */
  char buf[IRCD_BUFSIZE] = "";  /* Essential that buf[0] = '\0' */
  char *bufptr = buf, *p = NULL;
  size_t masklen, i = 0;

  /* :me.name 302 source_p->name :n1*=+u1@h1 n2=-u2@h2 ...\r\n */
  /* 1       23456              78                        9 10 */
  size_t len = strlen(me.name) + strlen(source_p->name) + 10;

  for (const char *name = strtok_r(parv[1], " ", &p); name && i++ < RFC1459_MAX_USERHOST_LIST;
                   name = strtok_r(NULL,    " ", &p))
  {
    const struct Client *target_p = find_person(source_p, name);
    if (target_p == NULL)
      continue;

    /*
     * Show real IP address for USERHOST on yourself.
     * This is needed for things like mIRC, which do a server-based
     * lookup (USERHOST) to figure out what the clients' local IP
     * is. Useful for things like NAT, and dynamic dial-up users.
     */
    if (target_p == source_p)
      masklen = snprintf(response, sizeof(response), "%s%s=%c%s@%s",
                         target_p->name,
                         HasUMode(target_p, UMODE_OPER) ? "*" : "",
                         (target_p->away[0]) ? '-' : '+',
                         target_p->username,
                         target_p->sockhost);
    else
      masklen = snprintf(response, sizeof(response), "%s%s=%c%s@%s",
                         target_p->name, (HasUMode(target_p, UMODE_OPER) &&
                                          (!HasUMode(target_p, UMODE_HIDDEN) ||
                                            HasUMode(source_p, UMODE_OPER))) ? "*" : "",
                         (target_p->away[0]) ? '-' : '+',
                         target_p->username,
                         target_p->host);

    if ((bufptr - buf) + masklen + len + 1 /* +1 for space */ > sizeof(buf))
      break;

    bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != buf ? " %s" : "%s", response);
  }

  sendto_one_numeric(source_p, &me, RPL_USERHOST, buf);
}

static struct Message userhost_msgtab =
{
  .cmd = "USERHOST",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_userhost, .args_min = 2, .args_max = 1 },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_userhost, .args_min = 2, .args_max = 1 }
};

static void
module_init(void)
{
  mod_add_cmd(&userhost_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&userhost_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
