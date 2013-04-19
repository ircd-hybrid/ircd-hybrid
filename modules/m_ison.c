/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_ison.c: Provides a single line answer of whether a user is online.
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
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


static void
do_ison(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Client *target_p = NULL;
  char *nick;
  char *p = NULL;
  char *current_insert_point = NULL;
  char buf[IRCD_BUFSIZE];
  int len;
  int i;
  int done = 0;

  len = snprintf(buf, sizeof(buf), RPL_ISON, me.name, source_p->name);
  current_insert_point = buf + len;

  /*
   * rfc1459 is ambigious about how to handle ISON
   * this should handle both interpretations.
   */
  for (i = 1; i < parc; i++)
  {
    for (nick = strtoken(&p, parv[i], " "); nick;
         nick = strtoken(&p,    NULL, " "))
    {
      if ((target_p = find_person(client_p, nick)))
      {
        len = strlen(target_p->name);

        if ((current_insert_point + (len + 5)) < (buf + sizeof(buf)))
        {
          memcpy(current_insert_point, target_p->name, len);
          current_insert_point += len;
          *current_insert_point++ = ' ';
        }
        else
        {
          done = 1;
          break;
        }
      }
    }

    if (done)
      break;
  }

  /*
   *  current_insert_point--;
   *  Do NOT take out the trailing space, it breaks ircII
   *  --Rodder
   */
  *current_insert_point  = '\0';

  sendto_one(source_p, "%s", buf);
}

/*
 * m_ison added by Darren Reed 13/8/91 to act as an efficent user indicator
 * with respect to cpu/bandwidth used. Implemented for NOTIFY feature in
 * clients. Designed to reduce number of whois requests. Can process
 * nicknames in batches as long as the maximum buffer length.
 *
 * format:
 * ISON :nicklist
 */
static void
m_ison(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  do_ison(client_p, source_p, parc, parv);
}

static struct Message ison_msgtab = {
  "ISON", 0, 0, 2, 1, MFLG_SLOW, 0,
  {m_unregistered, m_ison, m_ignore, m_ignore, m_ison, m_ignore}
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

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
