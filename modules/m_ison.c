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
#include "handlers.h"
#include "client.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_conf.h" /* ConfigFileEntry */
#include "s_serv.h" /* uplink/IsCapable */

static void do_ison(struct Client *, struct Client *, struct Client *, int, char *[]);
static void m_ison(struct Client *, struct Client *, int, char *[]);
static void ms_ison(struct Client *, struct Client *, int, char *[]);

struct Message ison_msgtab = {
  "ISON", 0, 0, 1, 1, MFLG_SLOW, 0,
  {m_unregistered, m_ison, ms_ison, m_ignore, m_ison, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&ison_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&ison_msgtab);
}
const char *_version = "$Revision$";
#endif



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
  struct Client *up = NULL;

  if (!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
    up = uplink;

  do_ison(client_p, up, source_p, parc, parv);
}

/*
 * ms_ison added by David Taylor 04/01/2000 to handle relayed ISON requests.
 * It's slightly less bandwidth efficient than a normal ISON, but it's
 * only ever going to get relayed over one link...
 * Plus, we'll only ever relay each nick once in it's lifetime, if it
 * exists...
 * ISON :nicklist
 */
static void
ms_ison(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if (ServerInfo.hub && IsCapable(client_p, CAP_LL))
    do_ison(client_p, NULL, source_p, parc, parv);
}

static void
do_ison(struct Client *client_p, struct Client *up, struct Client *source_p,
        int parc, char *parv[])
{
  struct Client *target_p = NULL;
  char *nick;
  char *p;
  char *current_insert_point, *current_insert_point2;
  char buf[IRCD_BUFSIZE];
  char buf2[IRCD_BUFSIZE];
  int len;
  int i;
  int done = 0;
  int relay_to_hub = 0;

  current_insert_point2 = buf2;
  *buf2 = '\0';

  len = ircsprintf(buf, form_str(RPL_ISON), me.name, parv[0]);
  current_insert_point = buf + len;

  /* rfc1459 is ambigious about how to handle ISON
   * this should handle both interpretations.
   */
  for (i = 1; i < parc; i++)
  {
    for (nick = strtoken(&p, parv[i], " "); nick;
         nick = strtoken(&p, NULL, " "))
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

      if (up)
      {
        /* Build up a single list, for use if we relay.. */
        len = strlen(nick);

        if ((current_insert_point2 + len + 5) < (buf2 + sizeof(buf2)))
        {
          memcpy(current_insert_point2, nick, len);
          current_insert_point2 += len;
          *current_insert_point2++ = ' ';
        }

        if (target_p == NULL)
        {
          /*
           * XXX Ick. we need to ask our hub if nick is online.
           * it's probably safest to relay the whole command,
           * unless we can answer it fully ourselves.
           * -davidt
           */
          relay_to_hub = 1;

          /* Also cache info about nick */
          sendto_one(up, ":%s NBURST %s", ID_or_name(&me, up), nick);
        }
      }
    }

    if (done)
      break;
  }

  /*  current_insert_point--;
   *  Do NOT take out the trailing space, it breaks ircII
   *  --Rodder */

  *current_insert_point  = '\0';
  *current_insert_point2 = '\0'; 
  
  if (relay_to_hub)
    sendto_one(up, ":%s ISON :%s", ID_or_name(source_p, up), buf2);
  else
    sendto_one(source_p, "%s", buf);
}
