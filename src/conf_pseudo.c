/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 */

/*! \file conf_pseudo.c
 * \brief Handles with pseudo commands/service aliases.
 * \version $Id: conf_pseudo.c 4299 2014-07-20 13:51:28Z michael $
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
  struct Message *msg;
  char name[NICKLEN + 1];
  char nick[NICKLEN + 1];
  char serv[HOSTLEN + 1];
  char prep[IRCD_BUFSIZE];
  char cmmd[IRCD_BUFSIZE];
};

static dlink_list pseudo_cmd_list;

static int
m_pseudo(struct Client *source_p, int parc, char *parv[])
{
  char buffer[IRCD_BUFSIZE] = "";
  struct pseudo_cmd *pseudo = NULL;
  struct Client *target_p = NULL;
  struct Client *server_p = NULL;
  const char *msg = parv[parc - 1];

  if (parc < 3 || EmptyString(msg))
  {
    sendto_one_numeric(source_p, &me, ERR_NOTEXTTOSEND);
    return 0;
  }

  pseudo = (struct pseudo_cmd *)parv[1];

  if (pseudo->prep[0])
  {
    snprintf(buffer, sizeof(buffer), "%s%s", pseudo->prep, msg);
    msg = buffer;
  }

  target_p = find_person(source_p, pseudo->nick);
  server_p = hash_find_server(pseudo->serv);

  if (target_p && server_p && (target_p->servptr == server_p))
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
                const char *cmmd)
{
  struct Message *msg = NULL;
  struct pseudo_cmd *pseudo = NULL;

  if (find_command(cmmd))
    return;

  pseudo = MyCalloc(sizeof(struct pseudo_cmd));
  strlcpy(pseudo->name, name, sizeof(pseudo->name));
  strlcpy(pseudo->nick, nick, sizeof(pseudo->nick));
  strlcpy(pseudo->serv, serv, sizeof(pseudo->serv));
  strlcpy(pseudo->prep, prep, sizeof(pseudo->prep));
  strlcpy(pseudo->cmmd, cmmd, sizeof(pseudo->cmmd));
  dlinkAdd(pseudo, &pseudo->node, &pseudo_cmd_list);

  msg = MyCalloc(sizeof(struct Message));
  msg->cmd = pseudo->cmmd;
  msg->args_max = 2;
  msg->flags = MFLG_EXTRA|MFLG_SLOW;
  msg->extra = pseudo;
  msg->handlers[UNREGISTERED_HANDLER] = m_unregistered;
  msg->handlers[CLIENT_HANDLER] = m_pseudo;
  msg->handlers[SERVER_HANDLER] = m_ignore;
  msg->handlers[ENCAP_HANDLER] = m_ignore;
  msg->handlers[OPER_HANDLER] = m_pseudo;
  msg->handlers[DUMMY_HANDLER] = m_ignore;

  mod_add_cmd(msg);
  pseudo->msg = msg;
}

void
pseudo_clear(void)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, pseudo_cmd_list.head)
  {
    struct pseudo_cmd *pseudo = ptr->data;
    assert(find_command(pseudo->cmmd));

    mod_del_cmd(pseudo->msg);
    dlinkDelete(&pseudo->node, &pseudo_cmd_list);
    MyFree(pseudo->msg);
    MyFree(pseudo);
  }
}
