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
#include <limits.h>
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

enum list_task_run_result
{
  LIST_TASK_RUN_DONE,
  LIST_TASK_RUN_PENDING,
};

static list_t list_task_queue;
static event_handle_t list_task_timer;

static void _list_task_pump(void *unused);

static inline bool
_list_task_is_congested(const struct ListTask *task)
{
  const unsigned int max_sendq = client_get_max_sendq(task->client);
  return dbuf_length(&task->client->connection->buf_sendq) > (max_sendq / 2);
}

static void
_list_task_dequeue(struct ListTask *task)
{
  if (task->is_queued == false)
    return;

  list_remove(&task->node, &list_task_queue);
  task->is_queued = false;
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
  struct ListTask *task = io_calloc(sizeof(*task));
  task->client = client;
  task->users_max = UINT_MAX;
  task->created_max = UINT_MAX;
  task->topicts_max = UINT_MAX;
  task->exact_match = true;
  client->connection->list_task = task;

  return task;
}

void
list_task_destroy(struct ListTask *task)
{
  if (task == NULL)
    return;

  _list_task_dequeue(task);

  _list_task_clear_masks(&task->include_masks);
  _list_task_clear_masks(&task->exclude_masks);

  io_free(task->topic);
  task->topic = NULL;

  task->client->connection->list_task = NULL;
  io_free(task);
}

static void
_list_task_finish(struct ListTask *task)
{
  struct Client *const client = task->client;

  list_task_destroy(task);
  sendto_one_numeric(client, &me, RPL_LISTEND);
}

static bool
_list_task_eval_channel(const struct ListTask *task, const struct Channel *channel)
{
  const struct Client *const client = task->client;
  if (channel_is_secret(channel) && !(client_is_admin(client) || member_find_link(client, channel)))
    return false;

  const unsigned int user_count = list_length(&channel->members);
  if (user_count < task->users_min || user_count > task->users_max)
    return false;

  if (channel->creation_time)
  {
    const unsigned int ctime = (unsigned int)channel->creation_time;
    if (ctime < task->created_min || ctime > task->created_max)
      return false;
  }

  const unsigned int ttime = channel->topic_time ? (unsigned int)channel->topic_time : UINT_MAX;
  if (ttime < task->topicts_min || ttime > task->topicts_max)
    return false;

  if (!list_is_empty(&task->include_masks) && list_find_cmp(&task->include_masks, channel->name, match) == NULL)
    return false;

  if (!list_is_empty(&task->exclude_masks) && list_find_cmp(&task->exclude_masks, channel->name, match) != NULL)
    return false;

  if (task->topic && (string_is_empty(channel->topic) || match(task->topic, channel->topic)))
    return false;

  return true;
}

static void
_list_task_send_channel(const struct ListTask *task, const struct Channel *channel)
{
  char mode_buf[MODEBUFLEN];
  snprintf(mode_buf, sizeof(mode_buf), channel->topic ? "[%s] " : "[%s]",
           channel_modes(channel, task->client, false));

  sendto_one_numeric(task->client, &me, RPL_LIST, channel->name,
                     list_length(&channel->members), mode_buf, string_or_empty(channel->topic));
}

static void
_list_task_execute_exact(struct ListTask *task)
{
  list_node_t *node;
  LIST_FOREACH(node, task->include_masks.head)
  {
    struct Channel *const channel = hash_find_channel(node->data);
    if (channel && _list_task_eval_channel(task, channel))
      _list_task_send_channel(task, channel);
  }

  _list_task_finish(task);
}

static enum list_task_run_result
_list_task_execute_global(struct ListTask *task)
{
  for (unsigned int i = task->hash_index; i < HASHSIZE; ++i)
  {
    /* Backpressure check. Yield control if the send queue is filling up. */
    if (_list_task_is_congested(task))
    {
      task->hash_index = i;
      return LIST_TASK_RUN_PENDING;  /* Yield back to event loop. */
    }

    for (struct Channel *channel = hash_get_bucket(HASH_TYPE_CHANNEL, i); channel; channel = channel->hnextch)
    {
      if (_list_task_eval_channel(task, channel))
        _list_task_send_channel(task, channel);
    }
  }

  _list_task_finish(task);
  return LIST_TASK_RUN_DONE;
}

static void
_list_task_timer_schedule(void)
{
  if (list_task_timer == NULL)
  {
    list_task_timer =
      event_create(ircd_event_manager, "_list_task_pump", _list_task_pump, 50, true, NULL, NULL);
    assert(list_task_timer);

    event_status_t status = event_set_priority(list_task_timer, 2);
    assert(status == EVENT_SUCCESS);
  }

  if (event_is_scheduled(list_task_timer))
    return;

  event_status_t status = event_schedule(list_task_timer);
  assert(status == EVENT_SUCCESS);
}

static void
_list_task_timer_schedule_if_needed(void)
{
  if (!list_is_empty(&list_task_queue))
    _list_task_timer_schedule();
}

static void
_list_task_pump(void *unused)
{
  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, list_task_queue.head)
  {
    struct ListTask *const task = node->data;
    _list_task_execute_global(task);
  }

  _list_task_timer_schedule_if_needed();
}

void
list_task_start(struct ListTask *task)
{
  assert(task);
  assert(task->client);
  assert(IsClient(task->client));
  assert(client_is_local(task->client));
  assert(task->is_queued == false);

  /* If the query is an exact match (e.g. /LIST #a,#b), run it instantly. */
  if (task->exact_match && !list_is_empty(&task->include_masks))
  {
    _list_task_execute_exact(task);
    return;
  }

  if (_list_task_execute_global(task) == LIST_TASK_RUN_PENDING)
  {
    list_add(task, &task->node, &list_task_queue);
    task->is_queued = true;
  }

  _list_task_timer_schedule_if_needed();
}
