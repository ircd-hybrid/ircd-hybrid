/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_userhost.c: Shows a user's host.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_conf.h"


static void m_userhost(struct Client *, struct Client *, int, char *[]);

struct Message userhost_msgtab = {
  "USERHOST", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_userhost, m_userhost, m_ignore, m_userhost, m_ignore}
};

void
_modinit(void)
{
  mod_add_cmd(&userhost_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&userhost_msgtab);
}

const char *_version = "$Revision$";

/*
 * m_userhost added by Darren Reed 13/8/91 to aid clients and reduce
 * the need for complicated requests like WHOIS. It returns user/host
 * information only (no spurious AWAY labels or channels).
 */
static void
m_userhost(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p;
  char buf[IRCD_BUFSIZE];
  char response[NICKLEN*2+USERLEN+HOSTLEN+30];
  char *t;
  int i;               /* loop counter */
  int cur_len;
  int rl;

  cur_len = ircsprintf(buf,form_str(RPL_USERHOST),me.name, parv[0], "");
  t = buf + cur_len;

  for (i = 0; i < 5; i++)
  {
    if (parv[i + 1] == NULL)
      break;

    if ((target_p = find_person(client_p, parv[i+1])) != NULL)
    {
      /*
       * Show real IP for USERHOST on yourself.
       * This is needed for things like mIRC, which do a server-based
       * lookup (USERHOST) to figure out what the clients' local IP
       * is.  Useful for things like NAT, and dynamic dial-up users.
       */
      if (MyClient(target_p) && (target_p == source_p))
      {
        rl = ircsprintf(response, "%s%s=%c%s@%s ",
                        target_p->name,
                        IsOper(target_p) ? "*" : "",
                        (target_p->away) ? '-' : '+',
                        target_p->username,
                        target_p->sockhost);
      }
      else
      {
        rl = ircsprintf(response, "%s%s=%c%s@%s ",
                        target_p->name,
                        IsOper(target_p) ? "*" : "",
                        (target_p->away) ? '-' : '+',
                        target_p->username,
                        target_p->host);
      }

      if ((rl + cur_len) < (IRCD_BUFSIZE - 10))
      {
        ircsprintf(t, "%s", response);
        t += rl;
        cur_len += rl;
      }
      else
        break;
    }
  }

  sendto_one(source_p, "%s", buf);
}
