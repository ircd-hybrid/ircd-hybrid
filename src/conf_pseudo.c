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
#include "numeric.h"
#include "send.h"
#include "memory.h"
#include "conf_pseudo.h"

static list_t pseudo_list;  /**< List to manage pseudo items. */

/**
 * @brief Retrieves the list of pseudo items.
 *
 * This function returns a pointer to the list of pseudo items.
 *
 * @return Pointer to the list of pseudo items.
 */
const list_t *
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
 * @param source Source client sending the pseudo message.
 * @param parc Number of parameters in the message.
 * @param parv Array of parameters in the message.
 */
static void
pseudo_message_handler(struct Client *source, int parc, char *parv[])
{
  char buf[IRCD_BUFSIZE];
  const struct PseudoItem *const pseudo = (const struct PseudoItem *)parv[1];
  const char *msg = parv[parc - 1];

  if (parc < 3 || EmptyString(msg))
  {
    sendto_one_numeric(source, &me, ERR_NOTEXTTOSEND);
    return;
  }

  if (pseudo->prepend)
  {
    snprintf(buf, sizeof(buf), "%s%s", pseudo->prepend, msg);
    msg = buf;
  }

  struct Client *target = find_person(source, pseudo->nick);
  if (target)
  {
    const struct Client *server = hash_find_server(pseudo->server);
    if (server == NULL || target->servptr != server || IsMe(server))
      target = NULL;
  }

  if (target)
    sendto_one(target, ":%s PRIVMSG %s :%s", source->id, target->id, msg);
  else
    sendto_one_numeric(source, &me, ERR_SERVICESDOWN, pseudo->name);
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
pseudo_register(const char *name, const char *nick, const char *server, const char *prepend, const char *command)
{
  if (command_find(command))
    return;

  struct PseudoItem *pseudo = io_calloc(sizeof(*pseudo));
  pseudo->name = io_strdup(name);
  pseudo->nick = io_strdup(nick);
  pseudo->server = io_strdup(server);
  pseudo->command = io_strdup(command);
  if (!EmptyString(prepend))
    pseudo->prepend = io_strdup(prepend);

  pseudo->command_struct = (struct Command) {
    .name = pseudo->command,
    .extra = pseudo,
    .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
    .handlers[CLIENT_HANDLER] = { .handler = pseudo_message_handler, .args_max = 2 },
    .handlers[SERVER_HANDLER] = { .handler = m_ignore },
    .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
    .handlers[OPER_HANDLER] = { .handler = pseudo_message_handler, .args_max = 2 }
  };

  list_add(pseudo, &pseudo->node, &pseudo_list);

  command_add(&pseudo->command_struct);
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
    assert(command_find(pseudo->command_struct.name));

    command_del(&pseudo->command_struct);
    list_remove(&pseudo->node, &pseudo_list);

    io_free(pseudo->name);
    io_free(pseudo->nick);
    io_free(pseudo->server);
    io_free(pseudo->prepend);
    io_free(pseudo->command);
    io_free(pseudo);
  }
}
