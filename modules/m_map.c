/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2026 ircd-hybrid development team
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

/*! \file m_map.c
 * \brief Includes required functions for processing the MAP command.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "io_time.h"
#include "misc.h"
#include "module.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "links_cache.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "user_mode.h"

enum { MAP_LINE_PREFIX_WIDTH = 50 };
enum { MAP_PROMPT_BUFFER_SIZE = 64 };

static void _map_format_line(char *buffer, size_t buffer_size, const char *server_name, const char *server_id, size_t indent_len, unsigned int user_count, unsigned int total_users);
static void _map_send_flat(struct Client *client);
static void _map_send_live(struct Client *client, const struct Client *current_server, char *prompt_buffer, size_t prompt_length);
static bool _map_should_hide_server(const struct Client *server, const struct Client *client);
static double _map_get_user_percentage(unsigned int count, unsigned int total);

static double
_map_get_user_percentage(unsigned int count, unsigned int total)
{
  if (total == 0)
    return 0.0;

  return 100.0 * (double)count / (double)total;
}

static void
_map_format_line(char *buffer, size_t buffer_size, const char *server_name, const char *server_id,
                 size_t indent_len, unsigned int user_count, unsigned int total_users)
{
  size_t bufpos = snprintf(buffer, buffer_size, "%s", server_name);
  if (server_id)
    bufpos += snprintf(buffer + bufpos, buffer_size - bufpos, "[%s]", server_id);

  int required_dashes = MAP_LINE_PREFIX_WIDTH - bufpos - indent_len;
  if (required_dashes > 0)
  {
    if (bufpos < buffer_size - 1)
      buffer[bufpos++] = ' ';

    const size_t drawable_dashes = IO_MIN((size_t)required_dashes, buffer_size - bufpos - 1);
    memset(buffer + bufpos, '-', drawable_dashes);
    bufpos += drawable_dashes;
  }

  snprintf(buffer + bufpos, buffer_size - bufpos, " | Users: %5u (%1.2f%%)",
           user_count, _map_get_user_percentage(user_count, total_users));
}

static bool
_map_should_hide_server(const struct Client *server, const struct Client *client)
{
  if (client_is_oper(client))
    return false;

  if (client_is_hidden(server))
    return true;

  if (client_is_service(server) && ConfigServerHide.hide_services)
    return true;

  return false;
}

static void
_map_send_flat(struct Client *client)
{
  const list_t *const cache = links_cache_get();
  const links_cache_metadata_t *metadata = links_cache_get_metadata();
  const unsigned int remote_server_count = list_length(cache);
  unsigned int processed_server_count = 0;
  unsigned int snapshot_global_users;

  if (metadata->generated_at_unix > 0)
    snapshot_global_users = metadata->network_users_total;
  else
    snapshot_global_users = list_length(&global_client_list);

  char line_buffer[IRCD_BUFSIZE];
  _map_format_line(line_buffer, sizeof(line_buffer),
                   me.name, NULL, 0, list_length(&local_client_list), snapshot_global_users);
  sendto_one_numeric(client, &me, RPL_MAP, "", line_buffer);

  list_node_t *node;
  LIST_FOREACH(node, cache->head)
  {
    const links_cache_entry_t *const entry = node->data;
    ++processed_server_count;

    _map_format_line(line_buffer, sizeof(line_buffer),
                     entry->name, NULL, 2, entry->user_count, snapshot_global_users);

    const char *const prefix = (processed_server_count == remote_server_count) ? "`-": "|-";
    sendto_one_numeric(client, &me, RPL_MAP, prefix, line_buffer);
  }
}

static void
_map_send_live(struct Client *client, const struct Client *current_server, char *prompt_buffer, size_t prompt_length)
{
  assert(prompt_length < MAP_PROMPT_BUFFER_SIZE);
  char *const p = prompt_buffer + prompt_length;
  *p = '\0';

  if (prompt_length > 60)
    sendto_one_numeric(client, &me, RPL_MAPMORE, prompt_buffer, current_server->name);
  else
  {
    char line_buffer[IRCD_BUFSIZE];
    const char *const server_id = client_is_oper(client) ? current_server->id : NULL;
    const unsigned int server_users = list_length(&current_server->server->child_user_list);
    const unsigned int global_users = list_length(&global_client_list);

    _map_format_line(line_buffer, sizeof(line_buffer),
                     current_server->name, server_id, prompt_length, server_users, global_users);
    sendto_one_numeric(client, &me, RPL_MAP, prompt_buffer, line_buffer);
  }

  if (prompt_length)
  {
    *(p - 1) = ' ';
    if (*(p - 2) == '`')
      *(p - 2) = ' ';
  }

  if (prompt_length > 60)
    return;

  strcpy(p, "|-");

  unsigned int visible_server_count = 0;
  list_node_t *node;
  LIST_FOREACH(node, current_server->server->child_server_list.head)
  {
    const struct Client *const server = node->data;
    if (!_map_should_hide_server(server, client))
      ++visible_server_count;
  }

  LIST_FOREACH(node, current_server->server->child_server_list.head)
  {
    const struct Client *const server = node->data;
    if (_map_should_hide_server(server, client))
      continue;

    if (--visible_server_count == 0)
      *p = '`';

    _map_send_live(client, server, prompt_buffer, prompt_length + 2);
  }

  if (prompt_length)
    *(p - 1) = '-';
}

static void
_map_process_request(struct Client *source)
{
  sendto_clients(UMODE_SPY, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "MAP requested by %s (%s@%s) [%s]",
                 source->name, source->username, source->host, source->uplink->name);

  if (ConfigServerHide.flatten_links && !client_is_oper(source))
    _map_send_flat(source);
  else
    _map_send_live(source, &me, (char[MAP_PROMPT_BUFFER_SIZE]){ 0 }, 0);

  sendto_one_numeric(source, &me, RPL_MAPEND);
}

/*! \brief MAP command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
m_map(struct Client *source, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);
  if ((last_used + ConfigGeneral.pace_wait) > now)
  {
    sendto_one_numeric(source, &me, RPL_LOAD2HI, "MAP");
    return;
  }

  last_used = now;

  _map_process_request(source);
}

/*! \brief MAP command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
mo_map(struct Client *source, int parc, char *parv[])
{
  _map_process_request(source);
}

static struct Command command_table =
{
  .name = "MAP",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_map },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_map }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
