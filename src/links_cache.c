/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <jansson.h>  /**< Jansson JSON library. */

#include "event.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "memory.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "links_cache.h"

static const char *const LINKS_CACHE_KEY_METADATA = "metadata";
static const char *const LINKS_CACHE_KEY_SERVERS = "servers";
static const char *const LINKS_CACHE_KEY_GENERATED_AT = "generated_at_unix";
static const char *const LINKS_CACHE_KEY_NETWORK_USERS = "network_users_total";
static const char *const LINKS_CACHE_KEY_NAME = "name";
static const char *const LINKS_CACHE_KEY_UPLINK_NAME = "uplink_name";
static const char *const LINKS_CACHE_KEY_DESCRIPTION = "description";
static const char *const LINKS_CACHE_KEY_USER_COUNT = "user_count";


static event_handle_t update_timer;
static list_t cache_buffer_A;
static list_t cache_buffer_B;
static list_t *live_cache_ptr = &cache_buffer_A;
static links_cache_metadata_t cache_metadata;

static void _links_cache_update(void *unused);
static void _links_cache_write_file(void);
static void _links_cache_read_file(void);
static void _links_cache_clear_buffer(list_t *buffer);

static void
_links_cache_free_entry(void *data)
{
  if (data == NULL)
    return;

  links_cache_entry_t *entry = data;
  io_free(entry->name);
  entry->name = NULL;
  io_free(entry->uplink_name);
  entry->uplink_name = NULL;
  io_free(entry->description);
  entry->description = NULL;
  io_free(entry);
}

void
links_cache_set_timer(uintmax_t new_interval_seconds)
{
  assert(live_cache_ptr == &cache_buffer_A || live_cache_ptr == &cache_buffer_B);

  const uintmax_t interval_ms = new_interval_seconds * 1000ULL;
  if (interval_ms > 0)
  {
    if (update_timer == NULL)
      update_timer = event_create(ircd_event_manager, "links_cache_update", _links_cache_update, interval_ms, false, NULL, NULL);
    else
      event_set_interval_ms(update_timer, interval_ms);

    if (list_is_empty(live_cache_ptr))
      _links_cache_update(NULL);

    event_schedule(update_timer);
  }
  else if (update_timer)
  {
    if (event_is_scheduled(update_timer))
      event_unschedule(update_timer);

    _links_cache_clear_buffer(&cache_buffer_A);
    _links_cache_clear_buffer(&cache_buffer_B);

    memset(&cache_metadata, 0, sizeof(cache_metadata));
  }
}

void
links_cache_init(void)
{
  static bool initialized = false;
  if (initialized)
    return;
  initialized = true;

  _links_cache_read_file();
}

const list_t *
links_cache_get(void)
{
  assert(live_cache_ptr);
  return live_cache_ptr;
}

const links_cache_metadata_t *
links_cache_get_metadata(void)
{
  return &cache_metadata;
}

static void
_links_cache_clear_buffer(list_t *buffer)
{
  assert(buffer);

  list_node_t *node;
  while ((node = list_pop_head(buffer)))
  {
    links_cache_entry_t *const entry = node->data;
    assert(entry);

    _links_cache_free_entry(entry);
  }
}

static void
_links_cache_update(void *unused)
{
  assert(live_cache_ptr == &cache_buffer_A || live_cache_ptr == &cache_buffer_B);

  list_t *const inactive_buffer = (live_cache_ptr == &cache_buffer_A) ? &cache_buffer_B : &cache_buffer_A;
  assert(list_is_empty(inactive_buffer));

  list_node_t *node;
  LIST_FOREACH(node, global_server_list.head)
  {
    const struct Client *const server = node->data;
    if (client_is_hidden(server) || client_is_me(server))
      continue;
    if (client_is_service(server) && ConfigServerHide.hide_services)
      continue;

    links_cache_entry_t *const entry = io_calloc(sizeof(*entry));
    entry->name = io_strdup(server->name);
    entry->uplink_name = io_strdup(me.name);
    entry->description = io_strdup(server->info);
    entry->user_count = list_length(&server->server->child_user_list);

    list_add_tail(entry, &entry->node, inactive_buffer);
  }

  cache_metadata.generated_at_unix = io_time_get(IO_TIME_REALTIME_SEC);
  cache_metadata.network_users_total = list_length(&global_client_list);

  live_cache_ptr = inactive_buffer;

  list_t *const stale_buffer = (live_cache_ptr == &cache_buffer_A) ? &cache_buffer_B : &cache_buffer_A;
  _links_cache_clear_buffer(stale_buffer);

  _links_cache_write_file();
}

static void
_links_cache_write_file(void)
{
  if (string_is_empty(ConfigServerHide.flatten_links_file))
    return;

  json_t *root = json_object();
  json_t *metadata = json_object();
  json_object_set_new(metadata, LINKS_CACHE_KEY_GENERATED_AT, json_integer(cache_metadata.generated_at_unix));
  json_object_set_new(metadata, LINKS_CACHE_KEY_NETWORK_USERS, json_integer(cache_metadata.network_users_total));
  json_object_set_new(root, LINKS_CACHE_KEY_METADATA, metadata);

  json_t *servers_array = json_array();
  json_object_set_new(root, LINKS_CACHE_KEY_SERVERS, servers_array);

  list_node_t *node;
  LIST_FOREACH(node, (*live_cache_ptr).head)
  {
    const links_cache_entry_t *const entry = node->data;
    json_error_t error;
    json_t *json_entry = json_pack_ex(&error, 0, "{s:s, s:s, s:s, s:i}",
                                      LINKS_CACHE_KEY_NAME, entry->name,
                                      LINKS_CACHE_KEY_UPLINK_NAME, entry->uplink_name,
                                      LINKS_CACHE_KEY_DESCRIPTION, entry->description,
                                      LINKS_CACHE_KEY_USER_COUNT, entry->user_count);
    if (json_entry == NULL)
    {
      log_write(LOG_TYPE_IRCD, "Error packing links_cache entry: line %d: %s", error.line, error.text);
      continue;
    }

    json_array_append_new(servers_array, json_entry);
  }

  if (json_dump_file(root, ConfigServerHide.flatten_links_file, JSON_INDENT(4)))
    log_write(LOG_TYPE_IRCD, "Error writing links_cache JSON data to '%s'", ConfigServerHide.flatten_links_file);

  json_decref(root);
}

static void
_links_cache_read_file(void)
{
  if (string_is_empty(ConfigServerHide.flatten_links_file))
    return;

  json_error_t error;
  json_t *root = json_load_file(ConfigServerHide.flatten_links_file, 0, &error);
  if (root == NULL)
  {
    if (errno != ENOENT)
      log_write(LOG_TYPE_IRCD, "Could not load links_cache file '%s': %s (line %d)",
                ConfigServerHide.flatten_links_file, error.text, error.line);
    return;
  }

  json_t *metadata = json_object_get(root, LINKS_CACHE_KEY_METADATA);
  if (json_is_object(metadata))
    json_unpack_ex(metadata, &error, 0, "{s:I, s:i}",
                   LINKS_CACHE_KEY_GENERATED_AT, &cache_metadata.generated_at_unix,
                   LINKS_CACHE_KEY_NETWORK_USERS, &cache_metadata.network_users_total);

  json_t *servers_array = json_object_get(root, LINKS_CACHE_KEY_SERVERS);
  if (json_is_array(servers_array) == 0)
  {
    log_write(LOG_TYPE_IRCD, "Error in '%s': '%s' is not a JSON array.",
              ConfigServerHide.flatten_links_file, LINKS_CACHE_KEY_SERVERS);
    json_decref(root);
    return;
  }

  size_t index;
  json_t *json_entry;
  json_array_foreach(servers_array, index, json_entry)
  {
    const char *name, *uplink_name, *description;
    int user_count;

    if (json_unpack_ex(json_entry, &error, 0, "{s:s, s:s, s:s, s:i}",
                       LINKS_CACHE_KEY_NAME, &name,
                       LINKS_CACHE_KEY_UPLINK_NAME, &uplink_name,
                       LINKS_CACHE_KEY_DESCRIPTION, &description,
                       LINKS_CACHE_KEY_USER_COUNT, &user_count))
    {
      log_write(LOG_TYPE_IRCD, "Error unpacking links_cache entry at index %zu: %s", index, error.text);
      continue;
    }

    links_cache_entry_t *const entry = io_calloc(sizeof(*entry));
    entry->name = io_strdup(name);
    entry->uplink_name = io_strdup(uplink_name);
    entry->description = io_strdup(description);
    entry->user_count = user_count;

    list_add_tail(entry, &entry->node, live_cache_ptr);
  }

  json_decref(root);
}
