/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_change.c: Allows changing user/host/real of connected clients.
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

/* List of ircd includes from ../include/ */
#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "common.h"     /* FALSE bleah */
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_user.h"
#include "hash.h"

static void mo_chgident(struct Client *, struct Client *, int, char *[]);
static void mo_chghost(struct Client *, struct Client *, int, char *[]);
static void mo_chgname(struct Client *, struct Client *, int, char *[]);

struct Message chgident_msgtab = {
  "CHGIDENT", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, mo_chgident, mo_chgident, mo_chgident, m_ignore}
};

struct Message chghost_msgtab = {
  "CHGHOST", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, mo_chghost, mo_chghost, mo_chghost, m_ignore}
};

struct Message chgname_msgtab = {
  "CHGNAME", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, mo_chgname, mo_chgname, mo_chgname, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&chgident_msgtab);
  mod_add_cmd(&chghost_msgtab);
  mod_add_cmd(&chgname_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&chgname_msgtab);
  mod_del_cmd(&chghost_msgtab);
  mod_del_cmd(&chgident_msgtab);
}

const char *_version = "$Revision$";
#endif

static void
mo_chgident(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  struct Client *target_p = NULL;

  if (MyClient(source_p) && !IsOperAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, parv[0], "CHGIDENT");
    return;
  }

  if (EmptyString(parv[2]))
  {
    parv[2] = parv[1];

    target_p = source_p;
    if (!IsClient(target_p))
      return;
  }
  else {
    target_p = find_client(parv[1]);

    if (target_p == NULL || !IsClient(target_p))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHNICK), me.name, parv[0], parv[1]);
      return;
    }
  }

  if (strlen(parv[2]) > USERLEN || !*parv[2] || !valid_username(parv[2]))
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid username", me.name, parv[0]);
    return;
  }

  strcpy(target_p->username, parv[2]);
  
  if (MyClient(source_p))
  {
    sendto_server(client_p, source_p, NULL, NOCAPS, NOCAPS, LL_ICLIENT,
                  ":%s ENCAP * CHGIDENT %s %s",
                  parv[0], target_p->name, parv[2]);
    sendto_one(source_p, ":%s NOTICE %s :%s changed to %s@%s",
               me.name, parv[0], target_p->name, target_p->username,
               target_p->host);
  }

  if (MyConnect(target_p) && IsClient(source_p))
    sendto_one(target_p, ":%s NOTICE %s :You are now %s@%s",
               me.name, target_p->name, target_p->username, target_p->host);
}

static void
mo_chghost(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  if (MyClient(source_p) && !IsOperAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, parv[0], "CHGHOST");
    return;
  }

  if (EmptyString(parv[2]))
  {
    parv[2] = parv[1];

    target_p = source_p;
    if (!IsClient(target_p))
      return;
  }
  else {
    target_p = find_client(parv[1]);
    if (target_p == NULL || !IsClient(target_p))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHNICK), me.name, parv[0], parv[1]);
      return;
    }
  }

  if (strlen(parv[2]) > HOSTLEN || !*parv[2] || !valid_hostname(parv[2]))
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid hostname", me.name, parv[0]);
    return;
  }

  strcpy(target_p->host, parv[2]);
  SetIPSpoof(target_p);
 
  if (MyClient(source_p))
  {
    sendto_server(client_p, source_p, NULL, NOCAPS, NOCAPS, LL_ICLIENT,
                  ":%s ENCAP * CHGHOST %s %s",
                  parv[0], target_p->name, parv[2]);
    sendto_one(source_p, ":%s NOTICE %s :%s changed to %s@%s",
               me.name, parv[0], target_p->name, target_p->username,
               target_p->host);
  }

  if (MyConnect(target_p) && IsClient(source_p))
    sendto_one(target_p, ":%s NOTICE %s :You are now %s@%s",
               me.name, target_p->name, target_p->username, target_p->host);
}

static void
mo_chgname(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  struct Client *target_p = NULL;

  if (MyClient(source_p) && !IsOperAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, parv[0], "CHGNAME");
    return;
  }

  if (EmptyString(parv[2]))
  {
    parv[2] = parv[1];
    target_p = source_p;
  }
  else if ((target_p = find_client(parv[1])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHNICK), me.name, parv[0], parv[1]);
    return;
  }

  if (strlen(parv[2]) > REALLEN || !*parv[2])
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid realname", me.name, parv[0]);
    return;
  }

  if (parc > 3 && MyClient(source_p))
    sendto_one(source_p, ":%s NOTICE %s :Warning -- too many parameters "
               "for CHGNAME. You are probably missing a : before the new "
               "IRC name.", me.name, parv[0]);

  strcpy(target_p->info, parv[2]);
  
  if (MyClient(source_p))
  {
    sendto_server(client_p, source_p, NULL, NOCAPS, NOCAPS, LL_ICLIENT,
                  ":%s ENCAP * CHGNAME %s :%s",
                  parv[0], target_p->name, parv[2]);
    sendto_one(source_p, ":%s NOTICE %s :%s realname changed to [%s]",
               me.name, parv[0], target_p->name, target_p->info);
  }

  if (MyClient(target_p) && IsClient(source_p))
    sendto_one(target_p, ":%s NOTICE %s :Your realname is now [%s]",
               me.name, target_p->name, target_p->info);
}
