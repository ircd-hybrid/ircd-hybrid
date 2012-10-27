/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_squit.c: Makes a server quit.
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
#include "common.h"      /* FALSE bleah */
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"


static void ms_squit(struct Client *, struct Client *, int, char *[]);
static void mo_squit(struct Client *, struct Client *, int, char *[]);

struct Message squit_msgtab = {
  "SQUIT", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, ms_squit, m_ignore, mo_squit, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&squit_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&squit_msgtab);
}

const char *_version = "$Revision$";
#endif

/* mo_squit - SQUIT message handler
 *  parv[0] = sender prefix
 *  parv[1] = server name
 *  parv[2] = comment
 */
static void
mo_squit(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct Client *p;
  dlink_node *ptr;
  char *comment;
  const char *server;
  char def_reason[] = "No reason";

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "SQUIT");
    return;
  }

  server = parv[1];

  /* The following allows wild cards in SQUIT. Only
   * useful when the command is issued by an oper.
   */
  DLINK_FOREACH(ptr, global_serv_list.head)
  {
    p = ptr->data;

    if (IsServer(p) || IsMe(p))
    {
      if (match(server, p->name))
      {
        target_p = p;
        break;
      }
    }
  }

  if ((target_p == NULL) || IsMe(target_p))
  {
    sendto_one(source_p, form_str(ERR_NOSUCHSERVER),
               me.name, source_p->name, server);
    return;
  }

  if (!MyConnect(target_p) && !IsOperRemote(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  comment = (parc > 2 && parv[2]) ? parv[2] : def_reason;

  if (strlen(comment) > (size_t)REASONLEN)
    comment[REASONLEN] = '\0';

  if (MyConnect(target_p))
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, "Received SQUIT %s from %s (%s)",
                         target_p->name, get_client_name(source_p, HIDE_IP), comment);
    ilog(L_NOTICE, "Received SQUIT %s from %s (%s)",
         target_p->name, get_client_name(source_p, HIDE_IP), comment);
  }

  exit_client(target_p, source_p, comment);
}

/** NOTE: I removed wildcard lookups here, because a wildcarded
 **       SQUIT should/can never happen in ms_squit. -Michael
 **/

/* ms_squit - SQUIT message handler
 *  parv[0] = sender prefix
 *  parv[1] = server name
 *  parv[2] = comment
 */
static void
ms_squit(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct Client *target_p = NULL;
  char *comment;
  const char *server;
  char def_reason[] = "No reason";

  if (parc < 2 || EmptyString(parv[1]))
    return;

  server = parv[1];

  if ((target_p = find_server(server)) == NULL)
    return;

  if (!IsServer(target_p) || IsMe(target_p))
    return;

  comment = (parc > 2 && parv[2]) ? parv[2] : def_reason;

  if (strlen(comment) > (size_t)REASONLEN)
    comment[REASONLEN] = '\0';

  if (MyConnect(target_p))
  {
    sendto_wallops_flags(UMODE_WALLOP, &me, "Remote SQUIT %s from %s (%s)",
                         target_p->name, source_p->name, comment);
    sendto_server(NULL, NULL, NULL, CAP_TS6, NOCAPS, NOFLAGS,
                  ":%s WALLOPS :Remote SQUIT %s from %s (%s)",
                  me.id, target_p->name, source_p->name, comment);
    sendto_server(NULL, NULL, NULL, NOCAPS, CAP_TS6, NOFLAGS,
                  ":%s WALLOPS :Remote SQUIT %s from %s (%s)",
                  me.name, target_p->name, source_p->name, comment);
    ilog(L_TRACE, "SQUIT From %s : %s (%s)", parv[0],
         target_p->name, comment);

   }

   exit_client(target_p, source_p, comment);
}

