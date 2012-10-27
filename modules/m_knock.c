/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_knock.c: Requests to be invited to a channel.
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
#include "tools.h"
#include "handlers.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "s_conf.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_serv.h"
#include "s_user.h"
#include "common.h"

static void m_knock(struct Client*, struct Client*, int, char**);
static void ms_knock(struct Client *, struct Client *, int, char**);
static void me_knock(struct Client *, struct Client *, int, char**);

static void parse_knock_local(struct Client *, struct Client *,
                              int, char **, char *);
static void parse_knock_remote(struct Client *, struct Client *,
                                      int, char **, int);

static void send_knock(struct Client *, struct Client *,
                       struct Channel *, char *, char *, int, int);

struct Message knock_msgtab = {
  "KNOCK", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_knock, ms_knock, me_knock, m_knock, m_ignore}
};

struct Message knockll_msgtab = {
  "KNOCKLL", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_ignore, m_knock, m_ignore, m_ignore, m_ignore}
};

#ifndef STATIC_MODULES

void
_modinit(void)
{
  mod_add_cmd(&knock_msgtab);
  mod_add_cmd(&knockll_msgtab);
  add_capability("KNOCK", CAP_KNOCK, 1);
  add_isupport("KNOCK", NULL, -1);
}

void
_moddeinit(void)
{
  mod_del_cmd(&knock_msgtab);
  mod_del_cmd(&knockll_msgtab);
  delete_capability("KNOCK");
  delete_isupport("KNOCK");
}

const char *_version = "$Revision$";
#endif

/* m_knock
 *    parv[0] = sender prefix
 *    parv[1] = channel
 *
 *  The KNOCK command has the following syntax:
 *   :<sender> KNOCK <channel>
 *
 *  If a user is not banned from the channel they can use the KNOCK
 *  command to have the server NOTICE the channel operators notifying
 *  they would like to join.  Helpful if the channel is invite-only, the
 *  key is forgotten, or the channel is full (INVITE can bypass each one
 *  of these conditions.  Concept by Dianora <db@db.net> and written by
 *  <anonymous>
 *
 *  This function is also used for LL servers forwarding knock requests they
 *  dont know about, for us to answer.
 */
static void
m_knock(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  char *sockhost = NULL;

  if ((ConfigChannel.use_knock == 0) && MyClient(source_p))
  {
    sendto_one(source_p, form_str(ERR_KNOCKDISABLED),
               me.name, source_p->name);
    return;
  }

  /* a remote KNOCKLL request, check we're capable of handling it.. */
  if (!MyConnect(source_p))
  {
    if (!ServerInfo.hub || !IsCapable(client_p, CAP_LL) || parc < 3)
      return;
    else
    {
      /* set sockhost to parv[2] here to save messing in parse_knock_local() */
      sockhost = parv[2];

      if(parc > 3)
      {
        parv[2] = parv[3];
        parv[3] = NULL;
      }
      else
        parv[2] = NULL;

      parc--;
    }
  }
    
  if (IsClient(source_p))
    parse_knock_local(client_p, source_p, parc, parv, sockhost);
}

/* 
 * ms_knock()
 *	parv[0] = sender prefix
 *	parv[1] = channel
 */
 
static void
ms_knock(struct Client *client_p, struct Client *source_p,
	 int parc, char *parv[])
{
  if (IsClient(source_p))
    parse_knock_remote(client_p, source_p, parc, parv, 1);
}

/* 
 * me_knock()
 *	parv[0] = sender prefix
 *	parv[1] = channel
 */
 
static void
me_knock(struct Client *client_p, struct Client *source_p,
	 int parc, char *parv[])
{
  if (IsClient(source_p))
    parse_knock_remote(client_p, source_p, parc, parv, 0);
}

/* parse_knock_local()
 *
 * input        - pointer to physical struct client_p
 *              - pointer to source struct source_p
 *              - number of args
 *              - pointer to array of args
 *		- clients sockhost
 * output       -
 * side effects - sets name to name of base channel
 *                or sends failure message to source_p
 */
static void
parse_knock_local(struct Client *client_p, struct Client *source_p,
                              int parc, char *parv[], char *sockhost)
{
  /* We will cut at the first comma reached, however we will not *
   * process anything afterwards.                                */

  struct Channel *chptr;
  char *p, *name, *key;

  name = parv[1];
  key = (parc > 2) ? parv[2] : NULL;

  if ((p = strchr(name, ',')) != NULL)
    *p = '\0';

  if (*name == '\0')
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "KNOCK");
    return;
  }

  if (!IsChanPrefix(*name))
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, source_p->name, name);
    return;
  }

  if ((chptr = hash_find_channel(name)) == NULL)
  {
    if (!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
    {
      sendto_one(uplink, ":%s KNOCKLL %s %s %s",
                 ID_or_name(source_p, uplink), parv[1],
		 IsIPSpoof(source_p) ? "255.255.255.255" :
		 source_p->sockhost,
		 (parc > 2) ? parv[2] : "");
    }
    else
    {
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, source_p->name, name);
    }

    return;
  }

  /* Normal channel, just be sure they aren't on it */
  if (IsMember(source_p, chptr))
  {
    sendto_one(source_p, form_str(ERR_KNOCKONCHAN),
               me.name, source_p->name, name);
    return;
  }

  if (!((chptr->mode.mode & MODE_INVITEONLY) || (*chptr->mode.key) ||
        (chptr->mode.limit && dlink_list_length(&chptr->members) >=
         chptr->mode.limit)))
  {
    sendto_one(source_p, form_str(ERR_CHANOPEN),
               me.name, source_p->name, name);
    return;
  }

  /* don't allow a knock if the user is banned, or the channel is secret */
  if ((chptr->mode.mode & MODE_PRIVATE) || is_banned(chptr, source_p))
  {
    sendto_one(source_p, form_str(ERR_CANNOTSENDTOCHAN),
               me.name, source_p->name, name);
    return;
  }

  /* flood protection:
   * allow one knock per user per knock_delay
   * allow one knock per channel per knock_delay_channel
   *
   * we only limit local requests..
   */
  if (MyClient(source_p) &&
     (source_p->localClient->last_knock + ConfigChannel.knock_delay) >
      CurrentTime)
  {
    sendto_one(source_p, form_str(ERR_TOOMANYKNOCK),
               me.name, source_p->name, parv[1], "user");
    return;
  }
  else if (chptr->last_knock +
           ConfigChannel.knock_delay_channel > CurrentTime)
  {
    sendto_one(source_p, form_str(ERR_TOOMANYKNOCK),
               me.name, source_p->name, parv[1], "channel");
    return;
  }

  /* pass on the knock */
  send_knock(client_p, source_p, chptr, name, key,
             MyClient(source_p) ? 0 : 1, 1);
}

/* parse_knock_remote()
 *
 * input	- pointer to client
 *		- pointer to source
 *		- number of args
 *		- pointer to array of args
 * output	- none
 * side effects - knock is checked for validity, if valid send_knock() is
 * 		  called
 */
static void
parse_knock_remote(struct Client *client_p, struct Client *source_p,
		   int parc, char *parv[], int prop)
{
  struct Channel *chptr;
  char *p, *name, *key;

  name = parv[1];
  key = parv[2];

  if ((p = strchr(name, ',')) != NULL)
    *p = '\0';

  if (!IsChanPrefix(*name) || (chptr = hash_find_channel(name)) == NULL)
    return;

  if (IsMember(source_p, chptr))
    return;
  
  if (!((chptr->mode.mode & MODE_INVITEONLY) || (*chptr->mode.key) ||
        (chptr->mode.limit && dlink_list_length(&chptr->members) >=
         chptr->mode.limit)))
    return;

  if (chptr)
    send_knock(client_p, source_p, chptr, name, key, 0, prop);
}

/* send_knock()
 *
 * input        - pointer to physical struct client_p
 *              - pointer to source struct source_p
 *              - pointer to channel struct chptr
 *              - pointer to base channel name
 * output       -
 * side effects - knock is sent locally (if enabled) and propagated
 */
static void
send_knock(struct Client *client_p, struct Client *source_p,
	   struct Channel *chptr, char *name, char *key, int llclient,
	   int prop)
{
  chptr->last_knock = CurrentTime;

  if (MyClient(source_p))
  {
    source_p->localClient->last_knock = CurrentTime;

    sendto_one(source_p, form_str(RPL_KNOCKDLVR),
               me.name, source_p->name, name);
  }
  else if (llclient == 1)
    sendto_one(source_p, form_str(RPL_KNOCKDLVR),
               me.name, source_p->name, name);

  if (IsClient(source_p))
  {
    if (ConfigChannel.use_knock)
      sendto_channel_local(CHFL_CHANOP, NO,
		     chptr, form_str(RPL_KNOCK),
			     me.name, name, name,
			     source_p->name, source_p->username,
			     source_p->host);

    if (prop)
    {
      sendto_server(client_p, source_p, chptr, CAP_KNOCK|CAP_TS6, NOCAPS, LL_ICLIENT,
                    ":%s KNOCK %s %s",
                    ID(source_p), name, key != NULL ? key : "");
      sendto_server(client_p, source_p, chptr, CAP_KNOCK, CAP_TS6, LL_ICLIENT,
                    ":%s KNOCK %s %s",
		    source_p->name, name, key != NULL ? key : "");
    }
  }
}

