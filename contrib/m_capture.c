/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_capture.c: Makes a designated client captive
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
#include "list.h"
#include "common.h"  
#include "handlers.h"
#include "client.h"
#include "hash.h"
#include "channel.h"
#include "channel_mode.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "hook.h"

static void mo_capture(struct Client *, struct Client *, int, char *[]);
static void mo_uncapture(struct Client *, struct Client *, int, char *[]);

struct Message capture_msgtab = {
  "CAPTURE", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_ignore, mo_capture, mo_capture, mo_capture, m_ignore}
};

struct Message uncapture_msgtab = {
  "UNCAPTURE", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_ignore, mo_uncapture, mo_uncapture, mo_uncapture, m_ignore}
};

void
_modinit(void)
{
  mod_add_cmd(&capture_msgtab);
  mod_add_cmd(&uncapture_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&capture_msgtab);
  mod_del_cmd(&uncapture_msgtab);
}

const char *_version = "$Revision$";

/* mo_capture
 *      parv[0] = sender prefix
 *      parv[1] = nickname masklist
 */
static void
mo_capture(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;
  char *nick = NULL, *user = NULL, *host = NULL;
  char *p = NULL;
  dlink_node *ptr = NULL;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NONICKNAMEGIVEN),
               me.name, source_p->name);
    return;
  }

  if (MyClient(source_p) && !IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "CAPTURE");
    return;
  }

  if ((p = strchr(parv[1], '@')) == NULL)
  {
    if ((target_p = find_client(parv[1])) != NULL && IsClient(target_p))
    {
      if (MyConnect(target_p) && source_p != target_p)
      {
        if (IsOper(target_p))
        {
          sendto_one(source_p, form_str(ERR_NOPRIVS),
                     me.name, source_p->name, "CAPTURE");
          return;
        }

        if (!IsCaptured(target_p))
        {
          sendto_realops_flags(UMODE_ALL, L_ALL, "Captured %s (%s@%s)",
                               target_p->name, target_p->username,
                               target_p->host);
          SetCaptured(target_p);
        }

        sendto_one(source_p, form_str(RPL_ISCAPTURED),
                   me.name, source_p->name, target_p->name);
      }
      else if (IsCapable(target_p->from, CAP_ENCAP))
        sendto_one(target_p, ":%s ENCAP %s CAPTURE %s",
                   source_p->name, target_p->from->name, target_p->name);
    }
    else
      sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                 me.name, source_p->name, parv[1]);
  }
  else
  {
    unsigned int matches = 0;

    /* p != NULL so user @ host given */
    nick = parv[1];
    *p++ = '\0';
    host = p;

    if ((p = strchr(nick, '!')) != NULL)
    {
      *p++ = '\0';
      user = p;
    }
    else
    {
      user = nick;
      nick = "*";
    }

    if (!valid_wild_card(source_p, YES, 3, nick, user, host))
      return;

    if (IsClient(client_p))
      sendto_server(client_p, NULL, CAP_ENCAP, 0,
                    ":%s ENCAP * CAPTURE %s!%s@%s",
                    source_p->name, nick, user, host);

    DLINK_FOREACH(ptr, local_client_list.head)
    {
      target_p = ptr->data;

      if ((source_p == target_p) || IsOper(target_p) || IsCaptured(target_p))
        continue;

      if (match(nick, target_p->name) &&
          match(host, target_p->host) && match(user, target_p->username))
      {
        SetCaptured(target_p);
        ++matches;
      }
    }

    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Bulk captured %s!%s@%s, %u local match(es)",
                         nick, user, host, matches);
  }
}

/* mo_uncapture
 *      parv[0] = sender prefix
 *      parv[1] = nickname masklist
 */
static void
mo_uncapture(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  struct Client *target_p = NULL;
  char *nick = NULL, *user = NULL, *host = NULL, *p = NULL;
  dlink_node *ptr = NULL;

  if (MyClient(source_p) && !IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "CAPTURE");
    return;
  }

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NONICKNAMEGIVEN),
               me.name, source_p->name);
    return;
  }

  if ((p = strchr(parv[1], '@')) == NULL)
  {      
    if ((target_p = find_client(parv[1])) != NULL && IsClient(target_p))
    {
      if (MyConnect(target_p))
      {
        if (IsCaptured(target_p))
        {
          ClearCaptured(target_p);

          sendto_realops_flags(UMODE_ALL, L_ALL, "Uncaptured %s (%s@%s)",
                               target_p->name, target_p->username,
                               target_p->host);
        }

        sendto_one(source_p, form_str(RPL_ISUNCAPTURED),
                   me.name, source_p->name, target_p->name);
      }
      else if (IsCapable(target_p->from, CAP_ENCAP))
        sendto_one(target_p, ":%s ENCAP %s UNCAPTURE %s",
                   source_p->name, target_p->from->name, target_p->name);
    }
    else
      sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                 me.name, source_p->name, parv[1]);
  }
  else
  {
    unsigned int matches = 0;

    /* p != NULL so user @ host given */
    nick = parv[1];
    *p++ = '\0';
    host = p;

    if ((p = strchr(nick, '!')) != NULL)
    {
      *p++ = '\0';
      user = p;
    }
    else
    {
      user = nick;
      nick = "*";
    }

    if (IsClient(client_p))
      sendto_server(client_p, NULL, CAP_ENCAP, 0,
                    ":%s ENCAP * UNCAPTURE %s!%s@%s",
                    source_p->name, nick, user, host);

    DLINK_FOREACH(ptr, local_client_list.head)
    {
      target_p = ptr->data;

      if (!IsCaptured(target_p))
        continue;

      if (match(nick, target_p->name) &&
          match(host, target_p->host) && match(user, target_p->username))
      {
        ClearCaptured(target_p);
        ++matches;
      }
    }

    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Bulk uncaptured %s!%s@%s, %u local match(es)",
                         nick, user, host, matches);
  }
}
