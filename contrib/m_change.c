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

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "conf.h"
#include "log.h"
#include "s_serv.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "s_user.h"
#include "hash.h"
#include "userhost.h"
#include "channel_mode.h"


static void
mo_chgident(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  struct Client *target_p = NULL;

  if (MyClient(source_p) && !HasUMode(source_p, UMODE_ADMIN))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "CHGIDENT");
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
    target_p = hash_find_client(parv[1]);

    if (target_p == NULL || !IsClient(target_p))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                 me.name, source_p->name, parv[1]);
      return;
    }
  }

  if (strlen(parv[2]) > USERLEN || !*parv[2] || !valid_username(parv[2]))
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid username",
               me.name, source_p->name);
    return;
  }

  if (IsUserHostIp(target_p))
    delete_user_host(target_p->username, target_p->host, !MyConnect(target_p));

  strlcpy(target_p->username, parv[2], sizeof(target_p->username));

  add_user_host(target_p->username, target_p->host, !MyConnect(target_p));
  SetUserHost(target_p);

  if (MyClient(source_p))
  {
    sendto_server(client_p, NOCAPS, NOCAPS, ":%s ENCAP * CHGIDENT %s %s",
                  source_p->name, target_p->name, parv[2]);
    sendto_one(source_p, ":%s NOTICE %s :%s changed to %s@%s",
               me.name, source_p->name, target_p->name, target_p->username,
               target_p->host);
  }

  if (MyClient(target_p))
  {
    if (IsClient(source_p))
      sendto_one(target_p, ":%s NOTICE %s :You are now %s@%s",
                 me.name, target_p->name, target_p->username, target_p->host);

    clear_ban_cache_client(target_p);
  }
}

static void
mo_chghost(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  if (MyClient(source_p) && !HasUMode(source_p, UMODE_ADMIN))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "CHGHOST");
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
    target_p = hash_find_client(parv[1]);

    if (target_p == NULL || !IsClient(target_p))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                 me.name, source_p->name, parv[1]);
      return;
    }
  }

  if (strlen(parv[2]) > HOSTLEN || !*parv[2] || !valid_hostname(parv[2]))
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid hostname",
               me.name, source_p->name);
    return;
  }

  if (IsUserHostIp(target_p))
    delete_user_host(target_p->username, target_p->host, !MyConnect(target_p));

  strlcpy(target_p->host, parv[2], sizeof(target_p->host));
  SetIPSpoof(target_p);

  add_user_host(target_p->username, target_p->host, !MyConnect(target_p));
  SetUserHost(target_p);

  if (MyClient(source_p))
  {
    sendto_server(client_p, NOCAPS, NOCAPS, ":%s ENCAP * CHGHOST %s %s",
                  source_p->name, target_p->name, parv[2]);
    sendto_one(source_p, ":%s NOTICE %s :%s changed to %s@%s",
               me.name, source_p->name, target_p->name, target_p->username,
               target_p->host);
  }

  if (MyClient(target_p))
  {
    if (IsClient(source_p))
      sendto_one(target_p, ":%s NOTICE %s :You are now %s@%s",
                 me.name, target_p->name, target_p->username, target_p->host);
    clear_ban_cache_client(target_p);
  }
}

static void
mo_chgname(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  struct Client *target_p = NULL;

  if (MyClient(source_p) && !HasUMode(source_p, UMODE_ADMIN))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "CHGNAME");
    return;
  }

  if (EmptyString(parv[2]))
  {
    parv[2] = parv[1];
    target_p = source_p;
  }
  else if ((target_p = hash_find_client(parv[1])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHNICK),
               me.name, source_p->name, parv[1]);
    return;
  }

  if (strlen(parv[2]) > REALLEN || !*parv[2])
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid realname",
               me.name, source_p->name);
    return;
  }

  if (parc > 3 && MyClient(source_p))
    sendto_one(source_p, ":%s NOTICE %s :Warning -- too many parameters "
               "for CHGNAME. You are probably missing a : before the new "
               "IRC name.", me.name, source_p->name);

  strlcpy(target_p->info, parv[2], sizeof(target_p->info));

  if (MyClient(source_p))
  {
    sendto_server(client_p, NOCAPS, NOCAPS, ":%s ENCAP * CHGNAME %s :%s",
                  source_p->name, target_p->name, parv[2]);
    sendto_one(source_p, ":%s NOTICE %s :%s realname changed to [%s]",
               me.name, source_p->name, target_p->name, target_p->info);
  }

  if (MyClient(target_p) && IsClient(source_p))
    sendto_one(target_p, ":%s NOTICE %s :Your realname is now [%s]",
               me.name, target_p->name, target_p->info);
}

static struct Message chgident_msgtab = {
  "CHGIDENT", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, mo_chgident, mo_chgident, mo_chgident, m_ignore}
};

static struct Message chghost_msgtab = {
  "CHGHOST", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, mo_chghost, mo_chghost, mo_chghost, m_ignore}
};

static struct Message chgname_msgtab = {
  "CHGNAME", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, mo_chgname, mo_chgname, mo_chgname, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&chgident_msgtab);
  mod_add_cmd(&chghost_msgtab);
  mod_add_cmd(&chgname_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&chgname_msgtab);
  mod_del_cmd(&chghost_msgtab);
  mod_del_cmd(&chgident_msgtab);
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
