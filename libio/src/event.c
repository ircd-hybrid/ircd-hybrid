/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2026 ircd-hybrid development team
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

/*! \file event.c
 * \brief Timer based event execution
 */

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include "event.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"
#include "rng_mt.h"

#define EVENT_HEAP_INVALID_INDEX SIZE_MAX
#define EVENT_HEAP_MIN_CAPACITY 8

struct event_instance
{
  list_node_t node;
  char *name;
  event_handler_fn handler;
  uintmax_t interval_ms;
  bool oneshot;
  void *data;
  event_cleanup_fn cleanup_handler;
  uintmax_t next_fire_time_ms;
  uint8_t priority;
  size_t heap_index;
  struct event_manager_instance *manager;
  bool destroy_pending;
  bool auto_reschedule_suppressed;
};

struct event_manager_instance
{
  list_t event_list;
  struct event_instance **heap_array;
  size_t heap_size;
  size_t heap_capacity;
  bool is_running;
  event_handle_t dispatching_event;
};

static uintmax_t
_event_now_ms(void)
{
  return io_time_get_monotonic_ms_total();
}

static bool
_event_heap_precedes(const struct event_instance *a, const struct event_instance *b)
{
  if (a->next_fire_time_ms < b->next_fire_time_ms)
    return true;
  if (a->next_fire_time_ms > b->next_fire_time_ms)
    return false;
  return a->priority > b->priority;
}

static void
_event_heap_swap(event_manager_t manager, const size_t i, const size_t j)
{
  assert(manager);
  assert(i < manager->heap_size);
  assert(j < manager->heap_size);
  assert(manager->heap_array[i]);
  assert(manager->heap_array[j]);

  struct event_instance *const event_i = manager->heap_array[i];
  struct event_instance *const event_j = manager->heap_array[j];
  manager->heap_array[i] = event_j;
  manager->heap_array[j] = event_i;

  event_i->heap_index = j;
  event_j->heap_index = i;
}

static void
_event_heap_sift_up(event_manager_t manager, size_t idx)
{
  assert(idx < manager->heap_size);

  while (idx > 0)
  {
    size_t parent_idx = (idx - 1) / 2;
    if (_event_heap_precedes(manager->heap_array[idx], manager->heap_array[parent_idx]))
    {
      _event_heap_swap(manager, idx, parent_idx);
      idx = parent_idx;
    }
    else
      break;
  }
}

static void
_event_heap_sift_down(event_manager_t manager, size_t idx)
{
  assert(idx < manager->heap_size);

  while (true)
  {
    size_t left_child_idx = 2 * idx + 1;
    size_t right_child_idx = 2 * idx + 2;
    size_t preferred_idx = idx;

    assert(manager->heap_array[idx] || manager->heap_size == 0);

    if (left_child_idx < manager->heap_size &&
        _event_heap_precedes(manager->heap_array[left_child_idx], manager->heap_array[preferred_idx]))
      preferred_idx = left_child_idx;

    if (right_child_idx < manager->heap_size &&
        _event_heap_precedes(manager->heap_array[right_child_idx], manager->heap_array[preferred_idx]))
      preferred_idx = right_child_idx;

    if (preferred_idx != idx)
    {
      _event_heap_swap(manager, idx, preferred_idx);
      idx = preferred_idx;
    }
    else
      break;
  }
}

static void
_event_heap_resize(event_manager_t manager, size_t new_capacity)
{
  assert(manager);
  assert(new_capacity >= manager->heap_size);

  manager->heap_array = io_realloc(manager->heap_array, new_capacity * sizeof(*manager->heap_array));
  manager->heap_capacity = new_capacity;
}

static void
_event_heap_ensure_capacity(event_manager_t manager)
{
  assert(manager);

  if (manager->heap_size < manager->heap_capacity)
    return;

  const size_t new_capacity =
    (manager->heap_capacity == 0) ? EVENT_HEAP_MIN_CAPACITY : manager->heap_capacity * 2;
  _event_heap_resize(manager, new_capacity);
}

static void
_event_heap_insert(event_manager_t manager, event_handle_t event)
{
  assert(manager);
  assert(event);
  assert(event->manager == manager);
  assert(!event_is_scheduled(event));

  _event_heap_ensure_capacity(manager);

  manager->heap_array[manager->heap_size] = event;
  event->heap_index = manager->heap_size;
  manager->heap_size++;

  _event_heap_sift_up(manager, event->heap_index);

  assert(event_is_scheduled(event));
}

static event_status_t
_event_heap_remove(event_manager_t manager, event_handle_t event)
{
  if (event->manager != manager)
    return EVENT_ERR_INVALID_ARG;

  assert(event_is_scheduled(event));

  const size_t original_heap_size = manager->heap_size;
  const size_t idx_to_remove = event->heap_index;
  const size_t last_idx = manager->heap_size - 1;

  if (idx_to_remove < last_idx)
    _event_heap_swap(manager, idx_to_remove, last_idx);

  manager->heap_size--;
  manager->heap_array[manager->heap_size] = NULL;

  if (manager->heap_size > 0 && idx_to_remove < manager->heap_size)
  {
    const size_t parent_idx = (idx_to_remove - 1) / 2;
    if (idx_to_remove > 0 && _event_heap_precedes(manager->heap_array[idx_to_remove], manager->heap_array[parent_idx]))
      _event_heap_sift_up(manager, idx_to_remove);
    else
      _event_heap_sift_down(manager, idx_to_remove);
  }

  event->heap_index = EVENT_HEAP_INVALID_INDEX;

  assert(manager->heap_size == original_heap_size - 1);
  return EVENT_SUCCESS;
}

static void
_event_snapshot_capture(event_snapshot_t *snapshot, event_handle_t event, uintmax_t current_time_ms)
{
  assert(snapshot);
  assert(event);
  assert(event->manager);

  const bool scheduled = event_is_scheduled(event);

  snapshot->name = io_strdup(event->name ? event->name : "[unnamed]");
  snapshot->interval_ms = event->interval_ms;
  snapshot->priority = event->priority;
  snapshot->oneshot = event->oneshot;
  snapshot->scheduled = scheduled;

  if (scheduled)
  {
    snapshot->next_fire_time_ms = event->next_fire_time_ms;

    if (event->next_fire_time_ms <= current_time_ms)
      snapshot->time_until_fire_ms = 0;
    else
      snapshot->time_until_fire_ms = event->next_fire_time_ms - current_time_ms;
  }
  else
  {
    snapshot->next_fire_time_ms = EVENT_TIME_NEVER;
    snapshot->time_until_fire_ms = EVENT_TIME_NEVER;
  }
}

static void
_event_snapshot_destroy(event_snapshot_t *snapshot)
{
  assert(snapshot);

  io_free(snapshot->name);
  snapshot->name = NULL;
}

static event_status_t
_event_schedule_absolute(event_handle_t event, uintmax_t absolute_time_ms)
{
  assert(event);
  assert(event->manager);
  assert(event->handler);

  if (event->destroy_pending)
    return EVENT_ERR_INVALID_ARG;

  event->next_fire_time_ms = absolute_time_ms;

  if (event->manager->dispatching_event == event)
    event->auto_reschedule_suppressed = true;

  if (event_is_scheduled(event))
  {
    event_status_t status = _event_heap_remove(event->manager, event);
    if (status != EVENT_SUCCESS)
      return status;
  }

  _event_heap_insert(event->manager, event);
  return EVENT_SUCCESS;
}

event_manager_t
event_manager_create(const event_manager_config_t *config)
{
  size_t initial_heap_capacity = EVENT_HEAP_MIN_CAPACITY;

  if (config && config->initial_heap_capacity)
    initial_heap_capacity = config->initial_heap_capacity;

  event_manager_t manager = io_calloc(sizeof(*manager));
  _event_heap_resize(manager, initial_heap_capacity);

  assert(manager->heap_array || initial_heap_capacity == 0);
  assert(manager->heap_capacity == initial_heap_capacity);
  assert(manager->heap_size == 0);

  return manager;
}

event_status_t
event_manager_destroy(event_manager_t manager)
{
  if (manager == NULL)
    return EVENT_ERR_INVALID_ARG;

  if (manager->is_running)
    return EVENT_ERR_BUSY;

  assert(manager->heap_array || manager->heap_size == 0);
  assert(manager->dispatching_event == NULL);

  event_handle_t event;
  while ((event = list_peek_head(&manager->event_list)))
  {
    assert(event);
    assert(event->manager == manager);

    event_status_t status = event_destroy(event);
    if (status != EVENT_SUCCESS)
      return status;
  }

  assert(manager->heap_size == 0);
  assert(list_is_empty(&manager->event_list));

  io_free(manager->heap_array);
  manager->heap_array = NULL;
  io_free(manager);

  return EVENT_SUCCESS;
}

uintmax_t
event_manager_get_next_fire_time(event_manager_t manager)
{
  if (manager == NULL || manager->heap_size == 0)
    return EVENT_TIME_NEVER;

  return manager->heap_array[0]->next_fire_time_ms;
}

size_t
event_manager_get_scheduled_count(event_manager_t manager)
{
  return manager ? manager->heap_size : 0;
}

event_status_t
event_manager_for_each_snapshot(event_manager_t manager, event_snapshot_callback_fn callback, void *user_data)
{
  if (manager == NULL || callback == NULL)
    return EVENT_ERR_INVALID_ARG;

  const size_t count = list_length(&manager->event_list);
  if (count == 0)
    return EVENT_SUCCESS;

  event_snapshot_t *snapshots = io_calloc(count * sizeof(*snapshots));
  const uintmax_t current_time_ms = _event_now_ms();

  size_t i = 0;
  list_node_t *node;
  LIST_FOREACH(node, manager->event_list.head)
  {
    event_handle_t event = node->data;
    assert(event);
    assert(event->manager == manager);
    assert(i < count);

    _event_snapshot_capture(&snapshots[i], event, current_time_ms);
    ++i;
  }

  assert(i == count);

  for (i = 0; i < count; ++i)
    callback(&snapshots[i], user_data);

  for (i = 0; i < count; ++i)
    _event_snapshot_destroy(&snapshots[i]);
  io_free(snapshots);

  return EVENT_SUCCESS;
}

event_handle_t
event_create(event_manager_t manager, const char *name, event_handler_fn handler, uintmax_t interval_ms,
             bool oneshot, void *data, event_cleanup_fn cleanup_handler)
{
  if (manager == NULL || handler == NULL || interval_ms == 0)
    return NULL;

  event_handle_t event = io_calloc(sizeof(*event));
  event->manager = manager;
  event->name = name ? io_strdup(name) : NULL;
  event->handler = handler;
  event->interval_ms = interval_ms;
  event->oneshot = oneshot;
  event->data = data;
  event->cleanup_handler = cleanup_handler;
  event->heap_index = EVENT_HEAP_INVALID_INDEX;

  list_add(event, &event->node, &manager->event_list);
  return event;
}

static void
_event_cleanup_data(event_handle_t event)
{
  assert(event);

  if (event->cleanup_handler)
    event->cleanup_handler(event->data);
}

static void
_event_destroy_finalize(event_handle_t event)
{
  assert(event);
  assert(event->manager);
  assert(event->destroy_pending);
  assert(event->heap_index == EVENT_HEAP_INVALID_INDEX);
  assert(event->manager->dispatching_event != event);

  _event_cleanup_data(event);

  list_remove(&event->node, &event->manager->event_list);
  event->manager = NULL;

  io_free(event->name);
  event->name = NULL;
  io_free(event);
}

event_status_t
event_destroy(event_handle_t event)
{
  if (event == NULL || event->manager == NULL)
    return EVENT_ERR_INVALID_ARG;

  if (event->destroy_pending)
    return EVENT_SUCCESS;

  event_status_t status = event_unschedule(event);
  if (status != EVENT_SUCCESS)
    return status;

  event->destroy_pending = true;

  if (event->manager->dispatching_event == event)
  {
    event->auto_reschedule_suppressed = true;
    return EVENT_SUCCESS;
  }

  _event_destroy_finalize(event);
  return EVENT_SUCCESS;
}

event_status_t
event_unschedule(event_handle_t event)
{
  if (event == NULL || event->manager == NULL || event->destroy_pending)
    return EVENT_ERR_INVALID_ARG;

  if (event->manager->dispatching_event == event)
    event->auto_reschedule_suppressed = true;

  if (!event_is_scheduled(event))
    return EVENT_SUCCESS;

  return _event_heap_remove(event->manager, event);
}

event_status_t
event_schedule(event_handle_t event)
{
  if (event == NULL || event->manager == NULL || event->handler == NULL || event->destroy_pending)
    return EVENT_ERR_INVALID_ARG;

  const uintmax_t current_time_ms = _event_now_ms();
  const uintmax_t absolute_time_ms = current_time_ms + event->interval_ms;

  return _event_schedule_absolute(event, absolute_time_ms);
}

event_status_t
event_schedule_at(event_handle_t event, uintmax_t absolute_time_ms)
{
  if (event == NULL || event->manager == NULL || event->handler == NULL || event->destroy_pending)
    return EVENT_ERR_INVALID_ARG;

  return _event_schedule_absolute(event, absolute_time_ms);
}

event_status_t
event_schedule_jittered(event_handle_t event)
{
  if (event == NULL || event->manager == NULL || event->handler == NULL || event->destroy_pending)
    return EVENT_ERR_INVALID_ARG;

  uintmax_t delay_ms = event->interval_ms;

  if (event->interval_ms >= 3000)
  {
    const uintmax_t jitter_ms = event->interval_ms / 3;
    const uintmax_t random_range_ms = 2 * jitter_ms;

    delay_ms = event->interval_ms + (genrand_int32() % (random_range_ms + 1)) - jitter_ms;
    if (delay_ms == 0)
      delay_ms = 1;
  }

  const uintmax_t current_time_ms = _event_now_ms();
  const uintmax_t absolute_time_ms = current_time_ms + delay_ms;

  return _event_schedule_absolute(event, absolute_time_ms);
}

event_status_t
event_reset(event_handle_t event)
{
  if (event == NULL || event->manager == NULL || event->handler == NULL || event->destroy_pending)
    return EVENT_ERR_INVALID_ARG;

  return event_reschedule(event, event->interval_ms);
}

event_status_t
event_reschedule(event_handle_t event, uintmax_t new_delay_ms)
{
  if (event == NULL || event->manager == NULL || event->handler == NULL || event->destroy_pending || new_delay_ms == 0)
    return EVENT_ERR_INVALID_ARG;

  const uintmax_t current_time_ms = _event_now_ms();
  const uintmax_t new_absolute_fire_time_ms = current_time_ms + new_delay_ms;

  return _event_schedule_absolute(event, new_absolute_fire_time_ms);
}

uintmax_t
event_get_next_fire_time(event_handle_t event)
{
  return event_is_scheduled(event) ? event->next_fire_time_ms : EVENT_TIME_NEVER;
}

uintmax_t
event_get_time_until_fire(event_handle_t event)
{
  if (!event_is_scheduled(event))
    return EVENT_TIME_NEVER;

  const uintmax_t current_time_ms = _event_now_ms();
  const uintmax_t next_fire_time_ms = event->next_fire_time_ms;

  if (next_fire_time_ms <= current_time_ms)
    return 0;

  return next_fire_time_ms - current_time_ms;
}

bool
event_is_scheduled(event_handle_t event)
{
  if (event == NULL || event->manager == NULL)
    return false;

  return event->heap_index != EVENT_HEAP_INVALID_INDEX &&
         event->heap_index < event->manager->heap_size && event->manager->heap_array[event->heap_index] == event;
}

bool
event_is_oneshot(event_handle_t event)
{
  return event ? event->oneshot : false;
}

event_manager_t
event_get_manager(event_handle_t event)
{
  return event ? event->manager : NULL;
}

const char *
event_get_name(event_handle_t event)
{
  if (event == NULL)
    return "[invalid]";

  return event->name ? event->name : "[unnamed]";
}

event_status_t
event_set_name(event_handle_t event, const char *new_name)
{
  if (event == NULL || event->manager == NULL || event->destroy_pending)
    return EVENT_ERR_INVALID_ARG;

  char *const copy = new_name ? io_strdup(new_name) : NULL;

  io_free(event->name);
  event->name = copy;

  return EVENT_SUCCESS;
}

uint8_t
event_get_priority(event_handle_t event)
{
  return event ? event->priority : 0;
}

event_status_t
event_set_priority(event_handle_t event, uint8_t new_priority)
{
  if (event == NULL || event->manager == NULL || event->destroy_pending)
    return EVENT_ERR_INVALID_ARG;

  if (event->priority == new_priority)
    return EVENT_SUCCESS;

  event->priority = new_priority;

  if (event_is_scheduled(event))
    return event_schedule_at(event, event->next_fire_time_ms);

  return EVENT_SUCCESS;
}

uintmax_t
event_get_interval_ms(event_handle_t event)
{
  return event ? event->interval_ms : 0;
}

event_status_t
event_set_interval_ms(event_handle_t event, uintmax_t new_interval_ms)
{
  if (event == NULL || event->manager == NULL || event->destroy_pending || new_interval_ms == 0)
    return EVENT_ERR_INVALID_ARG;

  event->interval_ms = new_interval_ms;
  return EVENT_SUCCESS;
}

void *
event_get_data(event_handle_t event)
{
  return event ? event->data : NULL;
}

event_status_t
event_manager_run(event_manager_t manager)
{
  if (manager == NULL)
    return EVENT_ERR_INVALID_ARG;

  if (manager->is_running)
    return EVENT_ERR_BUSY;

  assert(manager->heap_array || manager->heap_size == 0);
  assert(manager->dispatching_event == NULL);

  manager->is_running = true;

  while (manager->heap_size > 0)
  {
    struct event_instance *const event = manager->heap_array[0];
    assert(event);
    assert(event->manager == manager);
    assert(event->handler);
    assert(event->interval_ms > 0);
    assert(event->heap_index == 0);
    assert(event_is_scheduled(event));
    assert(event->destroy_pending == false);
    assert(event->auto_reschedule_suppressed == false);

    const uintmax_t current_time_ms = _event_now_ms();
    if (event->next_fire_time_ms > current_time_ms)
      break;

    event_status_t status = _event_heap_remove(manager, event);
    assert(status == EVENT_SUCCESS);
    assert(event->heap_index == EVENT_HEAP_INVALID_INDEX);

    manager->dispatching_event = event;
    event->handler(event->data);
    manager->dispatching_event = NULL;

    if (event->destroy_pending)
    {
      _event_destroy_finalize(event);
      continue;
    }

    if (event->oneshot == false &&
        event->auto_reschedule_suppressed == false && !event_is_scheduled(event))
    {
      event->next_fire_time_ms = current_time_ms + event->interval_ms;
      _event_heap_insert(manager, event);
      assert(event_is_scheduled(event));
    }

    event->auto_reschedule_suppressed = false;
  }

  manager->is_running = false;

  assert(manager->dispatching_event == NULL);
  assert(manager->heap_size <= manager->heap_capacity);
  return EVENT_SUCCESS;
}
