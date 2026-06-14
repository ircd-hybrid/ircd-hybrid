/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2014-2026 ircd-hybrid development team
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

#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#include "io_string.h"
#include "memory.h"

#include "client.h"
#include "client_id.h"
#include "client_find.h"
#include "conf_pseudo.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

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

static struct Client *
_pseudo_find_target_server(const char *name)
{
  if (client_id_is_valid_sid(name))
    return client_find_server_by_sid(name);

  return client_find_server_by_name(name);
}

static struct Client *
_pseudo_find_target(const struct PseudoItem *pseudo)
{
  struct Client *const target = client_find_user_by_name(pseudo->nick);
  if (target == NULL)
    return NULL;

  const struct Client *const server = _pseudo_find_target_server(pseudo->server);
  if (server == NULL)
    return NULL;

  if (client_is_me(server))
    return NULL;

  if (target->uplink != server)
    return NULL;

  return target;
}

static const char *
_pseudo_format_message(const struct PseudoItem *pseudo, const char *message, char *buffer, size_t buffer_size)
{
  if (pseudo->prepend == NULL)
    return message;

  snprintf(buffer, buffer_size, "%s%s", pseudo->prepend, message);
  return buffer;
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
_pseudo_message_handler(struct Client *source, int parc, char *parv[])
{
  const struct PseudoItem *const pseudo = (const struct PseudoItem *)parv[1];  /* XXX */

  const char *const message = parv[parc - 1];
  if (parc < 3 || string_is_empty(message))
  {
    sendto_one_numeric(source, &me, ERR_NOTEXTTOSEND);
    return;
  }

  struct Client *const target = _pseudo_find_target(pseudo);
  if (target == NULL)
  {
    sendto_one_numeric(source, &me, ERR_SERVICESDOWN, pseudo->name);
    return;
  }

  char message_buffer[IRCD_BUFSIZE];
  const char *const dispatch_message =
    _pseudo_format_message(pseudo, message, message_buffer, sizeof(message_buffer));

  sendto_one_command(target, source, "PRIVMSG", ":%s", dispatch_message);
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

  struct PseudoItem *const pseudo = io_calloc(sizeof(*pseudo));
  pseudo->name = io_strdup(name);
  pseudo->nick = io_strdup(nick);
  pseudo->server = io_strdup(server);
  pseudo->command = io_strdup(command);
  pseudo->prepend = !string_is_empty(prepend) ? io_strdup(prepend) : NULL;
  pseudo->command_struct = (struct Command) {
    .name = pseudo->command,
    .extra = pseudo,
    .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
    .handlers[CLIENT_HANDLER] = { .handler = _pseudo_message_handler, .args_max = 2 },
    .handlers[SERVER_HANDLER] = { .handler = m_ignore },
    .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
    .handlers[OPER_HANDLER] = { .handler = _pseudo_message_handler, .args_max = 2 }
  };

  list_add_tail(pseudo, &pseudo->node, &pseudo_list);

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
  list_node_t *node;

  while ((node = list_pop_head(&pseudo_list)))
  {
    struct PseudoItem *const pseudo = node->data;
    assert(pseudo);
    assert(command_find(pseudo->command_struct.name));

    command_del(&pseudo->command_struct);

    io_free(pseudo->name);
    io_free(pseudo->nick);
    io_free(pseudo->server);
    io_free(pseudo->prepend);
    io_free(pseudo->command);
    io_free(pseudo);
  }
}
