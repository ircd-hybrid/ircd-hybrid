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

struct pseudo_cmd
{
  dlink_node node;
  struct Message msg;
  char *name;
  char *nick;
  char *serv;
  char *prep;
  char *command;
};

static dlink_list pseudo_cmd_list;

static int
m_pseudo(struct Client *source_p, int parc, char *parv[])
{
  char buffer[IRCD_BUFSIZE] = "";
  const struct pseudo_cmd *const pseudo = (const struct pseudo_cmd *)parv[1];
  struct Client *target_p = NULL;
  struct Client *server_p = NULL;
  const char *msg = parv[parc - 1];

  if (parc < 3 || EmptyString(msg))
  {
    sendto_one_numeric(source_p, &me, ERR_NOTEXTTOSEND);
    return 0;
  }

  if (!EmptyString(pseudo->prep))
  {
    snprintf(buffer, sizeof(buffer), "%s%s", pseudo->prep, msg);
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
pseudo_register(const char *name, const char *nick,
                const char *serv, const char *prep,
                const char *command)
{
  struct pseudo_cmd *cmd = NULL;

  if (find_command(command))
    return;

  cmd = xcalloc(sizeof(*cmd));
  cmd->name = xstrdup(name);
  cmd->nick = xstrdup(nick);
  cmd->serv = xstrdup(serv);
  cmd->prep = xstrdup(prep);
  cmd->command = xstrdup(command);

  cmd->msg.cmd = cmd->command;
  cmd->msg.args_max = 2;
  cmd->msg.flags = MFLG_EXTRA;
  cmd->msg.extra = cmd;
  cmd->msg.handlers[UNREGISTERED_HANDLER] = m_unregistered;
  cmd->msg.handlers[CLIENT_HANDLER] = m_pseudo;
  cmd->msg.handlers[SERVER_HANDLER] = m_ignore;
  cmd->msg.handlers[ENCAP_HANDLER] = m_ignore;
  cmd->msg.handlers[OPER_HANDLER] = m_pseudo;
  dlinkAdd(cmd, &cmd->node, &pseudo_cmd_list);

  mod_add_cmd(&cmd->msg);
}

void
pseudo_clear(void)
{
  while (pseudo_cmd_list.head)
  {
    struct pseudo_cmd *cmd = pseudo_cmd_list.head->data;
    assert(find_command(cmd->msg.cmd));

    mod_del_cmd(&cmd->msg);
    dlinkDelete(&cmd->node, &pseudo_cmd_list);

    xfree(cmd->name);
    xfree(cmd->nick);
    xfree(cmd->serv);
    xfree(cmd->prep);
    xfree(cmd->command);
    xfree(cmd);
  }
}
