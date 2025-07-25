/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2025 ircd-hybrid development team
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
#include <string.h>

#include "io_time.h"
#include "memory.h"
#include "rng_mt.h"
#include "event.h"

#define EVENT_HEAP_INVALID_IDX (SIZE_MAX - 1)
#define EVENT_HEAP_MIN_CAPACITY 8

struct event_instance
{
  char *name;
  event_handler_fn handler;
  uintmax_t interval_ms;
  bool oneshot;
  void *data;
  event_cleanup_fn cleanup_handler;
  uintmax_t next_fire_time_ms;
  uint8_t priority;
  size_t heap_idx;
  struct event_manager_instance *manager;
  bool fired_and_cleaned;
};

struct event_manager_instance
{
  struct event_instance **heap_array;
  size_t heap_size;
  size_t heap_capacity;
};

static bool
_event_is_higher_priority_or_earlier(const struct event_instance *a, const struct event_instance *b)
{
  if (a->next_fire_time_ms < b->next_fire_time_ms)
    return true;
  if (a->next_fire_time_ms > b->next_fire_time_ms)
    return false;
  return a->priority > b->priority;
}

static void
_event_heap_swap(event_manager_t mgr, const size_t i, const size_t j)
{
  assert(i < mgr->heap_size);
  assert(j < mgr->heap_size);
  assert(mgr->heap_array[i]);
  assert(mgr->heap_array[j]);

  struct event_instance *const ev_i = mgr->heap_array[i];
  struct event_instance *const ev_j = mgr->heap_array[j];

  mgr->heap_array[i] = ev_j;
  mgr->heap_array[j] = ev_i;

  ev_i->heap_idx = j;
  ev_j->heap_idx = i;
}


static void
_event_heap_heapify_up(event_manager_t mgr, size_t idx)
{
  assert(idx < mgr->heap_size);

  while (idx > 0)
  {
    size_t parent_idx = (idx - 1) / 2;

    if (_event_is_higher_priority_or_earlier(mgr->heap_array[idx], mgr->heap_array[parent_idx]))
    {
      _event_heap_swap(mgr, idx, parent_idx);
      idx = parent_idx;
    }
    else
      break;
  }
}

static void
_event_heap_heapify_down(event_manager_t mgr, size_t idx)
{
  assert(idx < mgr->heap_size);

  while (true)
  {
    size_t left_child_idx = 2 * idx + 1;
    size_t right_child_idx = 2 * idx + 2;
    size_t preferred_idx = idx;

    assert(mgr->heap_array[idx] || mgr->heap_size == 0);

    if (left_child_idx < mgr->heap_size &&
        _event_is_higher_priority_or_earlier(mgr->heap_array[left_child_idx], mgr->heap_array[preferred_idx]))
      preferred_idx = left_child_idx;

    if (right_child_idx < mgr->heap_size &&
        _event_is_higher_priority_or_earlier(mgr->heap_array[right_child_idx], mgr->heap_array[preferred_idx]))
      preferred_idx = right_child_idx;

    if (preferred_idx != idx)
    {
      _event_heap_swap(mgr, idx, preferred_idx);
      idx = preferred_idx;
    }
    else
      break;
  }
}

static void
_event_heap_resize(event_manager_t mgr, size_t new_capacity)
{
  assert(new_capacity >= mgr->heap_size);

  struct event_instance **new_array = io_calloc(new_capacity * sizeof(*new_array));

  if (mgr->heap_array && mgr->heap_size > 0)
    memcpy(new_array, mgr->heap_array, mgr->heap_size * sizeof(*new_array));

  io_free(mgr->heap_array);
  mgr->heap_array = new_array;
  mgr->heap_capacity = new_capacity;
}

static event_status_t
_event_add_to_heap(event_manager_t mgr, event_handle_t event)
{
  assert(event->manager == mgr);
  assert(event->heap_idx == EVENT_HEAP_INVALID_IDX || event->heap_idx >= mgr->heap_size || mgr->heap_array[event->heap_idx] != event);
  assert(!event_is_scheduled(event));

  if (mgr->heap_size == mgr->heap_capacity)
  {
    size_t new_capacity = (mgr->heap_capacity == 0) ? EVENT_HEAP_MIN_CAPACITY : mgr->heap_capacity * 2;
    _event_heap_resize(mgr, new_capacity);
  }

  mgr->heap_array[mgr->heap_size] = event;
  event->heap_idx = mgr->heap_size;
  mgr->heap_size++;

  _event_heap_heapify_up(mgr, event->heap_idx);

  assert(event->heap_idx < mgr->heap_size);
  assert(mgr->heap_array[event->heap_idx] == event);
  assert(event_is_scheduled(event));

  return EVENT_SUCCESS;
}

static event_status_t
_event_remove_from_heap(event_manager_t mgr, event_handle_t event)
{
  if (event->manager != mgr)
    return EVENT_ERR_INVALID_ARG;

  assert(event_is_scheduled(event));

  if (!event_is_scheduled(event))
    return EVENT_ERR_NOT_FOUND;

  const size_t original_heap_size = mgr->heap_size;

  const size_t idx_to_remove = event->heap_idx;
  if (idx_to_remove == mgr->heap_size - 1)
  {
    mgr->heap_size--;
    mgr->heap_array[mgr->heap_size] = NULL;
  }
  else
  {
    _event_heap_swap(mgr, idx_to_remove, mgr->heap_size - 1);
    mgr->heap_size--;
    mgr->heap_array[mgr->heap_size] = NULL;

    if (mgr->heap_size > 0 && idx_to_remove < mgr->heap_size)
    {
      _event_heap_heapify_down(mgr, idx_to_remove);
      _event_heap_heapify_up(mgr, idx_to_remove);
    }
  }

  event->heap_idx = EVENT_HEAP_INVALID_IDX;

  assert(mgr->heap_size == original_heap_size - 1);
  return EVENT_SUCCESS;
}

static event_status_t
_event_schedule_at_internal(event_handle_t event, uintmax_t absolute_time_ms)
{
  assert(event);
  assert(event->manager);
  assert(event->handler);

  event->next_fire_time_ms = absolute_time_ms;

  if (event_is_scheduled(event))
    _event_remove_from_heap(event->manager, event);

  return _event_add_to_heap(event->manager, event);
}

event_manager_t
event_manager_create(event_manager_config_t *config)
{
  size_t initial_capacity = EVENT_HEAP_MIN_CAPACITY;

  if (config && config->initial_capacity)
    initial_capacity = config->initial_capacity;

  event_manager_t mgr = io_calloc(sizeof(*mgr));
  _event_heap_resize(mgr, initial_capacity);

  assert(mgr->heap_array || initial_capacity == 0);
  assert(mgr->heap_capacity == initial_capacity);
  assert(mgr->heap_size == 0);

  return mgr;
}

void
event_manager_destroy(event_manager_t mgr)
{
  assert(mgr->heap_array || mgr->heap_size == 0);
  while (mgr->heap_size > 0)
  {
    event_handle_t event_to_destroy = mgr->heap_array[0];
    event_destroy(event_to_destroy);
  }

  io_free(mgr->heap_array);
  mgr->heap_array = NULL;
  io_free(mgr);
}

uintmax_t
event_manager_get_next_fire_time(event_manager_t mgr)
{
  if (mgr->heap_size == 0)
    return UINTMAX_MAX;

  return mgr->heap_array[0]->next_fire_time_ms;
}

size_t
event_manager_get_active_count(event_manager_t mgr)
{
  return mgr->heap_size;
}

void
event_manager_for_each_scheduled(event_manager_t mgr, void (*callback)(event_handle_t event, void *user_data), void *user_data)
{
  if (mgr->heap_size == 0)
    return;

  const size_t count = mgr->heap_size;
  event_handle_t *handles = io_calloc(count * sizeof(event_handle_t));
  memcpy(handles, mgr->heap_array, count * sizeof(event_handle_t));

  for (size_t i = 0; i < count; ++i)
    callback(handles[i], user_data);

  io_free(handles);
}

event_handle_t
event_create(event_manager_t mgr, const char *name, event_handler_fn handler, uintmax_t interval_ms, bool oneshot, void *data, event_cleanup_fn cleanup_handler)
{
  if (mgr == NULL || handler == NULL || interval_ms == 0)
    return NULL;

  event_handle_t event = io_calloc(sizeof(*event));
  event->manager = mgr;
  event->name = name ? io_strdup(name) : NULL;
  event->handler = handler;
  event->interval_ms = interval_ms;
  event->oneshot = oneshot;
  event->data = data;
  event->cleanup_handler = cleanup_handler;
  event->heap_idx = EVENT_HEAP_INVALID_IDX;

  return event;
}

event_status_t
event_destroy(event_handle_t event)
{
  event_status_t status = EVENT_SUCCESS;

  if (event_is_scheduled(event))
    status = event_unschedule(event);

  if (event->cleanup_handler && event->fired_and_cleaned == false)
    event->cleanup_handler(event->data);

  io_free(event->name);
  event->name = NULL;
  io_free(event);

  return status;
}

event_status_t
event_unschedule(event_handle_t event)
{
  if (event->manager == NULL)
    return EVENT_ERR_INVALID_ARG;

  event_status_t status = _event_remove_from_heap(event->manager, event);
  assert(event->heap_idx == EVENT_HEAP_INVALID_IDX || status != EVENT_SUCCESS);

  return status;
}

event_status_t
event_schedule(event_handle_t event)
{
  if (event->manager == NULL)
    return EVENT_ERR_INVALID_ARG;
  if (event->handler == NULL)
    return EVENT_ERR_INVALID_ARG;

  const uintmax_t current_time = io_time_get_monotonic_ms_total();
  const uintmax_t absolute_time_ms = current_time + event->interval_ms;

  return _event_schedule_at_internal(event, absolute_time_ms);
}

event_status_t
event_schedule_at(event_handle_t event, uintmax_t absolute_time_ms)
{
  if (event->manager == NULL)
    return EVENT_ERR_INVALID_ARG;
  if (event->handler == NULL)
    return EVENT_ERR_INVALID_ARG;

  return _event_schedule_at_internal(event, absolute_time_ms);;
}

event_status_t
event_schedule_fuzzed(event_handle_t event)
{
  if (event->manager == NULL)
    return EVENT_ERR_INVALID_ARG;
  if (event->handler == NULL)
    return EVENT_ERR_INVALID_ARG;

  uintmax_t fuzzed_delay = event->interval_ms;

  if (event->interval_ms >= 3000)
  {
    const uintmax_t fuzz_offset = event->interval_ms / 3;
    const uintmax_t max_random_add = 2 * fuzz_offset;

    fuzzed_delay = event->interval_ms + (genrand_int32() % (max_random_add + 1)) - fuzz_offset;
    if (fuzzed_delay == 0)
      fuzzed_delay = 1;
  }

  const uintmax_t current_time = io_time_get_monotonic_ms_total();
  const uintmax_t absolute_time_ms = current_time + fuzzed_delay;

  return _event_schedule_at_internal(event, absolute_time_ms);
}

uintmax_t
event_get_next_fire_time(event_handle_t event)
{
  return event_is_scheduled(event) ? event->next_fire_time_ms : UINTMAX_MAX;
}

uintmax_t
event_get_time_until_fire(event_handle_t event)
{
  if (!event_is_scheduled(event))
    return UINTMAX_MAX;

  const uintmax_t current_time = io_time_get_monotonic_ms_total();
  const uintmax_t next_fire_time = event->next_fire_time_ms;

  if (next_fire_time <= current_time)
    return 0;

  return next_fire_time - current_time;
}

bool
event_is_scheduled(event_handle_t event)
{
  if (event->manager == NULL)
    return false;

  return event->heap_idx != EVENT_HEAP_INVALID_IDX &&
         event->heap_idx < event->manager->heap_size && event->manager->heap_array[event->heap_idx] == event;
}

bool
event_is_oneshot(event_handle_t event)
{
  return event->oneshot;
}

event_manager_t
event_get_manager(event_handle_t event)
{
  return event->manager;
}

const char *
event_get_name(event_handle_t event)
{
  return event->name ? event->name : "[unnamed]";
}

event_status_t
event_set_name(event_handle_t event, const char *new_name)
{
  io_free(event->name);

  if (new_name)
    event->name = io_strdup(new_name);
  else
    event->name = NULL;

  return EVENT_SUCCESS;
}

uint8_t
event_get_priority(event_handle_t event)
{
  return event->priority;
}

event_status_t
event_set_priority(event_handle_t event, uint8_t new_priority)
{
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
  return event->interval_ms;
}

event_status_t
event_set_interval_ms(event_handle_t event, uintmax_t new_interval_ms)
{
  if (new_interval_ms == 0)
    return EVENT_ERR_INVALID_ARG;

  event->interval_ms = new_interval_ms;

  if (event_is_scheduled(event))
    return event_schedule(event);

  return EVENT_SUCCESS;
}

void *
event_get_data(event_handle_t event)
{
  return event->data;
}

event_status_t
event_set_data(event_handle_t event, void *new_data)
{
  if (event->cleanup_handler && event->data && (event->data != new_data) && event->fired_and_cleaned == false)
    event->cleanup_handler(event->data);

  event->fired_and_cleaned = false;
  event->data = new_data;
  return EVENT_SUCCESS;
}

event_status_t
event_set_handler(event_handle_t event, event_handler_fn new_handler)
{
  if (new_handler == NULL)
    return EVENT_ERR_INVALID_ARG;

  event->handler = new_handler;
  return EVENT_SUCCESS;
}

event_status_t
event_set_oneshot(event_handle_t event, bool oneshot)
{
  event->oneshot = oneshot;
  return EVENT_SUCCESS;
}

event_status_t
event_set_cleanup_handler(event_handle_t event, event_cleanup_fn new_cleanup_handler)
{
  event->cleanup_handler = new_cleanup_handler;
  return EVENT_SUCCESS;
}

event_status_t
event_trigger_now(event_handle_t event)
{
  if (event->manager == NULL)
    return EVENT_ERR_INVALID_ARG;
  if (event->handler == NULL)
    return EVENT_ERR_INVALID_ARG;

  if (event_is_scheduled(event))
    _event_remove_from_heap(event->manager, event);

  event->handler(event->data);

  if (event->oneshot == false)
    return event_schedule(event);
  else
  {

    if (event->cleanup_handler && event->fired_and_cleaned == false)
    {
      event->cleanup_handler(event->data);
      event->fired_and_cleaned = true;
    }

    return EVENT_SUCCESS;
  }
}

void
event_run(event_manager_t mgr)
{
  assert(mgr->heap_array || mgr->heap_size == 0);
  uintmax_t current_time = io_time_get_monotonic_ms_total();

  while (mgr->heap_size > 0)
  {
    assert(mgr->heap_array[0]);
    struct event_instance *event = mgr->heap_array[0];
    assert(event->manager == mgr);

    if (event->next_fire_time_ms > current_time)
      break;

    assert(event->manager == mgr);
    assert(event->heap_idx == 0);

    _event_remove_from_heap(mgr, event);
    assert(event->heap_idx == EVENT_HEAP_INVALID_IDX);

    event->handler(event->data);

    if (event->oneshot == false)
    {
      event->next_fire_time_ms = current_time + event->interval_ms;
      _event_add_to_heap(mgr, event);
    }
    else
    {
      if (event->cleanup_handler && event->fired_and_cleaned == false)
      {
        event->cleanup_handler(event->data);
        event->fired_and_cleaned = true;
      }
    }
  }

  assert(mgr->heap_size <= mgr->heap_capacity);
}
