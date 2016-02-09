/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2014-2016 ircd-hybrid development team
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
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file conf_pseudo.c
 * \brief Handles with pseudo commands/service aliases.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "parse.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "memory.h"
#include "user.h"
#include "server.h"
#include "conf_pseudo.h"

struct PseudoItem
{
  dlink_node node;
  struct Message msg;
  char *name;
  char *nick;
  char *serv;
  char *prepend;
  char *command;
};

static dlink_list pseudo_list;

static int
m_pseudo(struct Client *source_p, int parc, char *parv[])
{
  char buffer[IRCD_BUFSIZE] = "";
  const struct PseudoItem *const pseudo = (const struct PseudoItem *)parv[1];
  struct Client *target_p = NULL;
  struct Client *server_p = NULL;
  const char *msg = parv[parc - 1];

  if (parc < 3 || EmptyString(msg))
  {
    sendto_one_numeric(source_p, &me, ERR_NOTEXTTOSEND);
    return 0;
  }

  if (!EmptyString(pseudo->prepend))
  {
    snprintf(buffer, sizeof(buffer), "%s%s", pseudo->prepend, msg);
    msg = buffer;
  }

  target_p = find_person(source_p, pseudo->nick);
  server_p = hash_find_server(pseudo->serv);

  if (target_p && server_p && (target_p->servptr == server_p) && !IsMe(server_p))
  {
    sendto_one(target_p, ":%s PRIVMSG %s :%s",
               source_p->id, target_p->id, msg);
    return 0;
  }

  sendto_one_numeric(source_p, &me, ERR_SERVICESDOWN, pseudo->name);
  return 0;
}

void
pseudo_register(const char *name, const char *nick, const char *serv, 
                const char *prepend,
                const char *command)
{
  if (find_command(command))
    return;

  struct PseudoItem *pseudo = xcalloc(sizeof(*pseudo));
  pseudo->name = xstrdup(name);
  pseudo->nick = xstrdup(nick);
  pseudo->serv = xstrdup(serv);
  pseudo->prepend = xstrdup(prepend);
  pseudo->command = xstrdup(command);

  pseudo->msg.cmd = pseudo->command;
  pseudo->msg.args_max = 2;
  pseudo->msg.flags = MFLG_EXTRA;
  pseudo->msg.extra = pseudo;
  pseudo->msg.handlers[UNREGISTERED_HANDLER] = m_unregistered;
  pseudo->msg.handlers[CLIENT_HANDLER] = m_pseudo;
  pseudo->msg.handlers[SERVER_HANDLER] = m_ignore;
  pseudo->msg.handlers[ENCAP_HANDLER] = m_ignore;
  pseudo->msg.handlers[OPER_HANDLER] = m_pseudo;
  dlinkAdd(pseudo, &pseudo->node, &pseudo_list);

  mod_add_cmd(&pseudo->msg);
}

void
pseudo_clear(void)
{
  while (pseudo_list.head)
  {
    struct PseudoItem *pseudo = pseudo_list.head->data;
    assert(find_command(pseudo->msg.cmd));

    mod_del_cmd(&pseudo->msg);
    dlinkDelete(&pseudo->node, &pseudo_list);

    xfree(pseudo->name);
    xfree(pseudo->nick);
    xfree(pseudo->serv);
    xfree(pseudo->prepend);
    xfree(pseudo->command);
    xfree(pseudo);
  }
}
