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

/*! \file event.h
 * \brief Timer based event execution
 */

#ifndef INCLUDED_event_h
#define INCLUDED_event_h
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct event_manager_instance;
typedef struct event_manager_instance *event_manager_t;

struct event_instance;
typedef struct event_instance *event_handle_t;

typedef void (*event_handler_fn)(void *);
typedef void (*event_cleanup_fn)(void *);

typedef enum
{
  EVENT_SUCCESS = 0,
  EVENT_ERR_INVALID_ARG,
  EVENT_ERR_NOT_FOUND,
} event_status_t;

typedef struct
{
  size_t initial_capacity;
} event_manager_config_t;

extern void event_manager_destroy(event_manager_t);
extern void event_manager_for_each_scheduled(event_manager_t, void (*callback)(event_handle_t, void *), void *);
extern void event_run(event_manager_t);
extern bool event_is_oneshot(event_handle_t);
extern bool event_is_scheduled(event_handle_t);
extern uint8_t event_get_priority(event_handle_t);
extern size_t event_manager_get_active_count(event_manager_t);
extern uintmax_t event_get_interval_ms(event_handle_t);
extern uintmax_t event_get_next_fire_time(event_handle_t);
extern uintmax_t event_get_time_until_fire(event_handle_t);
extern uintmax_t event_manager_get_next_fire_time(event_manager_t);
extern event_handle_t event_create(event_manager_t, const char *, event_handler_fn, uintmax_t, bool, void *, event_cleanup_fn);
extern event_manager_t event_get_manager(event_handle_t);
extern event_manager_t event_manager_create(event_manager_config_t *);
extern event_status_t event_destroy(event_handle_t);
extern event_status_t event_reschedule(event_handle_t, uintmax_t);
extern event_status_t event_reset(event_handle_t);
extern event_status_t event_schedule(event_handle_t);
extern event_status_t event_schedule_at(event_handle_t, uintmax_t);
extern event_status_t event_schedule_fuzzed(event_handle_t);
extern event_status_t event_set_interval_ms(event_handle_t, uintmax_t);
extern event_status_t event_set_name(event_handle_t event, const char *);
extern event_status_t event_set_priority(event_handle_t, uint8_t);
extern event_status_t event_unschedule(event_handle_t);
extern void *event_get_data(event_handle_t);
extern const char *event_get_name(event_handle_t);
#endif  /* INCLUDED_event_h */
