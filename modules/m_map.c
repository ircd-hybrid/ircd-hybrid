/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_map.c: Sends an Undernet compatible map to a user.
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
#include "modules.h"
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "ircd.h"
#include "irc_string.h"
#include "parse.h"
#include "s_user.h"



static void dump_map(struct Client *client,
                     struct Client *server,
                     unsigned int prompt_length)
{
  dlink_node *ptr = NULL;
  struct Client *target_p = NULL;
  static char prompt[64];
  char *p = prompt + prompt_length;
  int cnt = 0;

  *p = '\0';

  if (prompt_length > 60)
    sendto_one(client, form_str(RPL_MAPMORE), me.name,
               client->name, prompt, server->name);
  else
  {
    char buf[IRC_MAXSID + 3] = ""; /* +3 for [, ], \0 */

    if (HasUMode(client, UMODE_OPER) && server->id[0])
      snprintf(buf, sizeof(buf), "[%s]", server->id);

    sendto_one(client, form_str(RPL_MAP), me.name, client->name,
               prompt, server->name, buf,
               dlink_list_length(&server->serv->client_list),
               dlink_list_length(&server->serv->client_list) * 100 / Count.total);
  }

  if (prompt_length > 0)
  {
    *(p - 1) = ' ';

    if (*(p - 2) == '`')
      *(p - 2) = ' ';
  }

  if (prompt_length > 60)
    return;
  strcpy(p, "|-");

  DLINK_FOREACH(ptr, server->serv->server_list.head)
  {
    target_p = ptr->data;

    if (IsHidden(target_p) && !HasUMode(client, UMODE_OPER))
      continue;

    if (HasFlag(target_p, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (!HasUMode(client, UMODE_OPER))
        continue;

    ++cnt;
  }

  DLINK_FOREACH(ptr, server->serv->server_list.head)
  {
    target_p = ptr->data;

    if (IsHidden(target_p) && !HasUMode(client, UMODE_OPER))
      continue;

    if (HasFlag(target_p, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (!HasUMode(client, UMODE_OPER))
        continue;

    if (--cnt == 0)
      *p = '`';
    dump_map(client, target_p, prompt_length + 2);
  }

  if (prompt_length > 0)
    *(p - 1) = '-';
}

/* m_map()
 *      parv[0] = sender prefix
 */
static void
m_map(struct Client *client_p, struct Client *source_p,
      int parc, char *parv[])
{
  static time_t last_used = 0;

  if (ConfigServerHide.flatten_links)
  {
    m_not_oper(client_p, source_p, parc, parv);
    return;
  }

  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    /* safe enough to give this on a local connect only */
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }

  last_used = CurrentTime;

  dump_map(source_p, &me, 0);
  sendto_one(source_p, form_str(RPL_MAPEND), me.name, source_p->name);
}

/* mo_map()
 *      parv[0] = sender prefix
 */
static void
mo_map(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  dump_map(source_p, &me, 0);
  sendto_one(source_p, form_str(RPL_MAPEND), me.name, source_p->name);
}

static struct Message map_msgtab = {
  "MAP", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_map, m_ignore, m_ignore, mo_map, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&map_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&map_msgtab);
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
