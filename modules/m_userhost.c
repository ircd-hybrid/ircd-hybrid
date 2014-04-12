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

/*! \file m_userhost.c
 * \brief Includes required functions for processing the USERHOST command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "irc_string.h"
#include "parse.h"
#include "modules.h"


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
static int
m_userhost(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p;
  char buf[IRCD_BUFSIZE];
  char response[NICKLEN*2+USERLEN+HOSTLEN+30];
  char *t = NULL, *p = NULL, *nick = NULL;
  int i = 0;
  int cur_len;
  int rl;

  cur_len = snprintf(buf, sizeof(buf), numeric_form(RPL_USERHOST), me.name, source_p->name, "");
  t = buf + cur_len;

  for (nick = strtoken(&p, parv[1], " "); nick && i++ < 5;
       nick = strtoken(&p,    NULL, " "))
  {
    if ((target_p = find_person(source_p, nick)))
    {
      /*
       * Show real IP for USERHOST on yourself.
       * This is needed for things like mIRC, which do a server-based
       * lookup (USERHOST) to figure out what the clients' local IP
       * is. Useful for things like NAT, and dynamic dial-up users.
       */
      if (MyClient(target_p) && (target_p == source_p))
      {
        rl = sprintf(response, "%s%s=%c%s@%s ",
                     target_p->name,
                     HasUMode(target_p, UMODE_OPER) ? "*" : "",
                     (target_p->away[0]) ? '-' : '+',
                     target_p->username,
                     target_p->sockhost);
      }
      else
      {
        rl = sprintf(response, "%s%s=%c%s@%s ",
                     target_p->name, (HasUMode(target_p, UMODE_OPER) &&
                                      (!HasUMode(target_p, UMODE_HIDDEN) ||
                                        HasUMode(source_p, UMODE_OPER))) ? "*" : "",
                     (target_p->away[0]) ? '-' : '+',
                     target_p->username,
                     target_p->host);
      }

      if ((rl + cur_len) < (IRCD_BUFSIZE - 10))
      {
        sprintf(t, "%s", response);
        t += rl;
        cur_len += rl;
      }
      else
        break;
    }
  }

  sendto_one(source_p, "%s", buf);
  return 0;
}

static struct Message userhost_msgtab =
{
  "USERHOST", 0, 0, 2, 1, MFLG_SLOW, 0,
  { m_unregistered, m_userhost, m_userhost, m_ignore, m_userhost, m_ignore }
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
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
