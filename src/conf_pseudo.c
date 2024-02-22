/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2014-2024 ircd-hybrid development team
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

/**
 * @file conf_pseudo.c
 * @brief Manages pseudo commands and service aliases in the IRC daemon.
 *
 * This file contains functions and structures responsible for handling pseudo
 * commands and service aliases within the IRC daemon.
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

static dlink_list pseudo_list;  /**< List to manage pseudo items. */

/**
 * @brief Retrieves the list of pseudo items.
 *
 * This function returns a pointer to the list of pseudo items.
 *
 * @return Pointer to the list of pseudo items.
 */
const dlink_list *
pseudo_get_list(void)
{
  return &pseudo_list;
}

/**
 * @brief Handles incoming pseudo messages and forwards them accordingly.
 *
 * This function processes incoming pseudo messages and forwards them to the
 * appropriate target based on the pseudo configuration.
 *
 * @param source_p Source client sending the pseudo message.
 * @param parc Number of parameters in the message.
 * @param parv Array of parameters in the message.
 */
static void
pseudo_message_handler(struct Client *source_p, int parc, char *parv[])
{
  char buf[IRCD_BUFSIZE];
  const struct PseudoItem *const pseudo = (const struct PseudoItem *)parv[1];
  struct Client *target_p = NULL;
  struct Client *server_p = NULL;
  const char *msg = parv[parc - 1];

  if (parc < 3 || EmptyString(msg))
  {
    sendto_one_numeric(source_p, &me, ERR_NOTEXTTOSEND);
    return;
  }

  if (pseudo->prepend)
  {
    snprintf(buf, sizeof(buf), "%s%s", pseudo->prepend, msg);
    msg = buf;
  }

  target_p = find_person(source_p, pseudo->nick);
  server_p = hash_find_server(pseudo->server);

  if (target_p && server_p && (target_p->servptr == server_p) && !IsMe(server_p))
    sendto_one(target_p, ":%s PRIVMSG %s :%s", source_p->id, target_p->id, msg);
  else
    sendto_one_numeric(source_p, &me, ERR_SERVICESDOWN, pseudo->name);
}

/**
 * @brief Registers a new pseudo command or service alias.
 *
 * This function registers a new pseudo command or service alias with the IRC daemon.
 *
 * @param name Service name used for error messages.
 * @param nick Nickname associated with the pseudo command.
 * @param server Target server for the pseudo command.
 * @param prepend Optional text to be prepended to the user's message.
 * @param command Actual command or alias being registered.
 */
void
pseudo_register(const char *name, const char *nick, const char *server,
                const char *prepend,
                const char *command)
{
  if (find_command(command))
    return;

  struct PseudoItem *pseudo = xcalloc(sizeof(*pseudo));
  pseudo->name = xstrdup(name);
  pseudo->nick = xstrdup(nick);
  pseudo->server = xstrdup(server);
  pseudo->command = xstrdup(command);
  if (!EmptyString(prepend))
    pseudo->prepend = xstrdup(prepend);

  pseudo->msg = (struct Message) {
    .cmd = pseudo->command,
    .extra = pseudo,
    .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
    .handlers[CLIENT_HANDLER] = { .handler = pseudo_message_handler, .args_max = 2 },
    .handlers[SERVER_HANDLER] = { .handler = m_ignore },
    .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
    .handlers[OPER_HANDLER] = { .handler = pseudo_message_handler, .args_max = 2 }
  };

  dlinkAdd(pseudo, &pseudo->node, &pseudo_list);

  mod_add_cmd(&pseudo->msg);
}

/**
 * @brief Clears the list of pseudo commands and service aliases.
 *
 * This function removes all registered pseudo commands and service aliases from
 * the list and frees their memory.
 */
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
    xfree(pseudo->server);
    xfree(pseudo->prepend);
    xfree(pseudo->command);
    xfree(pseudo);
  }
}
