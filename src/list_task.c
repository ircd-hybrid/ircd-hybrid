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

#include <stddef.h>

#include "event.h"
#include "io_string.h"
#include "list.h"
#include "memory.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "list_task.h"
#include "numeric.h"
#include "send.h"

static list_t list_task_queue;
static event_handle_t list_task_timer;

static inline bool
_list_task_is_congested(const struct ListTask *lt)
{
  const unsigned int max_sendq = client_get_max_sendq(lt->client);
  return dbuf_length(&lt->client->connection->buf_sendq) > (max_sendq / 2);
}

static void
_list_task_dequeue(struct ListTask *lt)
{
  if (lt->is_queued == false)
    return;

  list_remove(&lt->node, &list_task_queue);
  lt->is_queued = false;
}

static void
_list_task_clear_masks(list_t *list)
{
  while (list->head)
  {
    list_node_t *node = list->head;
    list_remove(node, list);
    io_free(node->data);
    list_free_node(node);
  }
}

struct ListTask *
list_task_create(struct Client *client)
{
  struct ListTask *lt = io_calloc(sizeof(*lt));
  lt->client = client;
  lt->users_max = UINT_MAX;
  lt->created_max = UINT_MAX;
  lt->topicts_max = UINT_MAX;
  lt->exact_match = true;
  client->connection->list_task = lt;

  return lt;
}

void
list_task_destroy(struct ListTask *lt)
{
  if (lt == NULL)
    return;

  _list_task_dequeue(lt);

  _list_task_clear_masks(&lt->include_masks);
  _list_task_clear_masks(&lt->exclude_masks);

  io_free(lt->topic);
  lt->topic = NULL;

  lt->client->connection->list_task = NULL;
  io_free(lt);
}

static bool
_list_task_eval_channel(const struct ListTask *lt, const struct Channel *channel)
{
  const struct Client *const client = lt->client;
  if (channel_is_secret(channel) && !(client_is_admin(client) || member_find_link(client, channel)))
    return false;

  const unsigned int user_count = list_length(&channel->members);
  if (user_count < lt->users_min || user_count > lt->users_max)
    return false;

  if (channel->creation_time)
  {
    const unsigned int ctime = (unsigned int)channel->creation_time;
    if (ctime < lt->created_min || ctime > lt->created_max)
      return false;
  }

  const unsigned int ttime = channel->topic_time ? (unsigned int)channel->topic_time : UINT_MAX;
  if (ttime < lt->topicts_min || ttime > lt->topicts_max)
    return false;

  if (!list_is_empty(&lt->include_masks) && list_find_cmp(&lt->include_masks, channel->name, match) == NULL)
    return false;

  if (!list_is_empty(&lt->exclude_masks) && list_find_cmp(&lt->exclude_masks, channel->name, match) != NULL)
    return false;

  if (lt->topic && (string_is_empty(channel->topic) || match(lt->topic, channel->topic)))
    return false;

  return true;
}

static void
_list_task_send_channel(const struct ListTask *lt, const struct Channel *channel)
{
  char mode_buf[MODEBUFLEN];
  snprintf(mode_buf, sizeof(mode_buf), channel->topic ? "[%s] " : "[%s]",
           channel_modes(channel, lt->client, false));

  sendto_one_numeric(lt->client, &me, RPL_LIST, channel->name,
                     list_length(&channel->members), mode_buf, string_or_empty(channel->topic));
}

static void
_list_task_execute_exact(struct ListTask *lt)
{
  list_node_t *node;
  LIST_FOREACH(node, lt->include_masks.head)
  {
    struct Channel *channel = hash_find_channel(node->data);
    if (channel && _list_task_eval_channel(lt, channel))
      _list_task_send_channel(lt, channel);
  }

  struct Client *const client = lt->client;
  list_task_destroy(lt);
  sendto_one_numeric(client, &me, RPL_LISTEND);
}

static void
_list_task_execute_global(struct ListTask *lt)
{
  for (unsigned int i = lt->hash_index; i < HASHSIZE; ++i)
  {
    /* Backpressure check. Yield control if the send queue is filling up. */
    if (_list_task_is_congested(lt))
    {
      lt->hash_index = i;
      return;  /* Yield back to event loop. */
    }

    for (struct Channel *channel = hash_get_bucket(HASH_TYPE_CHANNEL, i); channel; channel = channel->hnextch)
    {
      if (_list_task_eval_channel(lt, channel))
        _list_task_send_channel(lt, channel);
    }
  }

  struct Client *const client = lt->client;
  list_task_destroy(lt);
  sendto_one_numeric(client, &me, RPL_LISTEND);
}

static void
_list_task_pump(void *unused)
{
  if (list_is_empty(&list_task_queue))
    return;

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, list_task_queue.head)
  {
    struct ListTask *const lt = node->data;
    _list_task_execute_global(lt);
  }
}

void
list_task_start(struct ListTask *lt)
{
  /* If the query is an exact match (e.g. /LIST #a,#b), run it instantly. */
  if (lt->exact_match && !list_is_empty(&lt->include_masks))
  {
    _list_task_execute_exact(lt);
    return;
  }

  if (list_task_timer == NULL)
  {
    list_task_timer =
      event_create(ircd_event_manager, "_list_task_pump", _list_task_pump, 125, false, NULL, NULL);
    event_set_priority(list_task_timer, 2);
    event_schedule(list_task_timer);
  }

  list_add(lt, &lt->node, &list_task_queue);
  lt->is_queued = true;

  _list_task_execute_global(lt);
}
