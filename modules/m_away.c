/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_away.c: Sets/removes away status on a user.
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
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_conf.h"
#include "s_serv.h"
#include "packet.h"
#include "s_user.h"

static void m_away(struct Client *, struct Client *, int, char *[]);
static void mo_away(struct Client *, struct Client *, int, char *[]);
static void ms_away(struct Client *, struct Client *, int, char *[]);

struct Message away_msgtab = {
  "AWAY", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_away, ms_away, m_ignore, mo_away, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&away_msgtab);
  add_isupport("AWAYLEN", NULL, AWAYLEN);
}

void
_moddeinit(void)
{
  mod_del_cmd(&away_msgtab);
  delete_isupport("AWAYLEN");
}

const char *_version = "$Revision$";
#endif

/***********************************************************************
 * m_away() - Added 14 Dec 1988 by jto. 
 *            Not currently really working, I don't like this
 *            call at all...
 *
 *            ...trying to make it work. I don't like it either,
 *            but perhaps it's worth the load it causes to net.
 *            This requires flooding of the whole net like NICK,
 *            USER, MODE, etc messages...  --msa
 ***********************************************************************/

/*
 * m_away
 *  parv[0] = sender prefix
 *  parv[1] = away message
 */
static void
m_away(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  char *cur_away_msg = source_p->away;
  char *new_away_msg = NULL;
  size_t nbytes = 0;

  if (!IsFloodDone(source_p))
    flood_endgrace(source_p);

  if (parc < 2 || EmptyString(parv[1]))
  {
    /* Marking as not away */
    if (cur_away_msg)
    {
      /* we now send this only if they were away before --is */
      sendto_server(client_p, source_p, NULL, CAP_TS6, NOCAPS,
                    NOFLAGS, ":%s AWAY", ID(source_p));
      sendto_server(client_p, source_p, NULL, NOCAPS, CAP_TS6,
                    NOFLAGS, ":%s AWAY", source_p->name);

      MyFree(cur_away_msg);
      source_p->away = NULL;
    }

    sendto_one(source_p, form_str(RPL_UNAWAY),
               me.name, source_p->name);
    return;
  }

  /* Marking as away */
  if ((CurrentTime - source_p->localClient->last_away) < ConfigFileEntry.pace_wait)
  {
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }

  source_p->localClient->last_away = CurrentTime;
  new_away_msg = parv[1];

  nbytes = strlen(new_away_msg);
  if (nbytes > (size_t)AWAYLEN) {
    new_away_msg[AWAYLEN] = '\0';
    nbytes = AWAYLEN;
  }

  /* we now send this only if they
   * weren't away already --is */
  if (!cur_away_msg)
  {
    sendto_server(client_p, source_p, NULL, CAP_TS6, NOCAPS,
                  NOFLAGS, ":%s AWAY :%s", ID(source_p), new_away_msg);
    sendto_server(client_p, source_p, NULL, NOCAPS, CAP_TS6,
                  NOFLAGS, ":%s AWAY :%s", source_p->name, new_away_msg);
  }
  else
    MyFree(cur_away_msg);

  cur_away_msg = MyMalloc(nbytes + 1);
  strcpy(cur_away_msg, new_away_msg);
  source_p->away = cur_away_msg;

  sendto_one(source_p, form_str(RPL_NOWAWAY), me.name, source_p->name);
}

static void
mo_away(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  char *cur_away_msg = source_p->away;
  char *new_away_msg = NULL;
  size_t nbytes = 0;

  if (!IsFloodDone(source_p))
    flood_endgrace(source_p);

  if (parc < 2 || EmptyString(parv[1]))
  {
    /* Marking as not away */
    if (cur_away_msg)
    {
      /* we now send this only if they were away before --is */
      sendto_server(client_p, source_p, NULL, CAP_TS6, NOCAPS,
                    NOFLAGS, ":%s AWAY", ID(source_p));
      sendto_server(client_p, source_p, NULL, NOCAPS, CAP_TS6,
                    NOFLAGS, ":%s AWAY", source_p->name);

      MyFree(cur_away_msg);
      source_p->away = NULL;
    }

    sendto_one(source_p, form_str(RPL_UNAWAY),
               me.name, source_p->name);
    return;
  }

  new_away_msg = parv[1];

  nbytes = strlen(new_away_msg);
  if (nbytes > (size_t)AWAYLEN) {
    new_away_msg[AWAYLEN] = '\0';
    nbytes = AWAYLEN;
  }

  /* we now send this only if they
   * weren't away already --is */
  if (!cur_away_msg)
  {
    sendto_server(client_p, source_p, NULL, CAP_TS6, NOCAPS,
                  NOFLAGS, ":%s AWAY :%s", ID(source_p), new_away_msg);
    sendto_server(client_p, source_p, NULL, NOCAPS, CAP_TS6,
                  NOFLAGS, ":%s AWAY :%s", source_p->name, new_away_msg);
  }
  else
    MyFree(cur_away_msg);

  cur_away_msg = MyMalloc(nbytes + 1);
  strcpy(cur_away_msg, new_away_msg);
  source_p->away = cur_away_msg;

  sendto_one(source_p, form_str(RPL_NOWAWAY), me.name, source_p->name);
}

static void
ms_away(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  char *cur_away_msg = NULL;
  char *new_away_msg = NULL;
  size_t nbytes = 0;

  if (!IsClient(source_p))
    return;

  cur_away_msg = source_p->away;

  if (parc < 2 || EmptyString(parv[1]))
  {
    /* Marking as not away */
    if (cur_away_msg)
    {
      /* we now send this only if they were away before --is */
      sendto_server(client_p, source_p, NULL, CAP_TS6, NOCAPS,
                    NOFLAGS, ":%s AWAY", ID(source_p));
      sendto_server(client_p, source_p, NULL, NOCAPS, CAP_TS6,
                    NOFLAGS, ":%s AWAY", source_p->name);

      MyFree(cur_away_msg);
      source_p->away = NULL;
    }

    return;
  }

  new_away_msg = parv[1];

  nbytes = strlen(new_away_msg);
  if (nbytes > (size_t)AWAYLEN) {
    new_away_msg[AWAYLEN] = '\0';
    nbytes = AWAYLEN;
  }

  /* we now send this only if they
   * weren't away already --is */
  if (!cur_away_msg)
  {
    sendto_server(client_p, source_p, NULL, CAP_TS6, NOCAPS,
                  NOFLAGS, ":%s AWAY :%s", ID(source_p), new_away_msg);
    sendto_server(client_p, source_p, NULL, NOCAPS, CAP_TS6,
                  NOFLAGS, ":%s AWAY :%s", source_p->name, new_away_msg);
  }
  else
    MyFree(cur_away_msg);

  cur_away_msg = MyMalloc(nbytes + 1);
  strcpy(cur_away_msg, new_away_msg);
  source_p->away = cur_away_msg;
}
