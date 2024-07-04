/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2024-2024 ircd-hybrid development team
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
 * @file io_time.h
 * @brief Provides an interface for retrieving real-time and monotonic time values.
 *
 * This file contains the declarations for functions that retrieve real-time and
 * monotonic time values, along with structures and enumerations used by these
 * functions. The API ensures accurate timekeeping by performing sanity checks
 * to detect and handle anomalies.
 */

#ifndef INCLUDED_io_time_h
#define INCLUDED_io_time_h

#include <stdint.h>
#include <stdbool.h>

/**
 * @struct io_time
 * @brief Structure holding real-time and monotonic time values.
 *
 * This structure stores both real-time and monotonic time values in seconds and nanoseconds.
 * It is updated by the io_time_set function and accessed by the io_time_get function.
 */
typedef struct
{
  uintmax_t sec_real;  /**< Seconds part of the real-time clock. */
  uintmax_t nsec_real;  /**< Nanoseconds part of the real-time clock. */
  uintmax_t sec_monotonic;  /**< Seconds part of the monotonic clock. */
  uintmax_t nsec_monotonic;  /**< Nanoseconds part of the monotonic clock. */
} io_time;

/**
 * @enum io_time_type
 * @brief Enumeration for specifying the type of time value to retrieve.
 *
 * This enumeration defines constants for selecting which part of the time data
 * to retrieve (seconds or nanoseconds, real-time or monotonic). These values
 * are used as parameters in the io_time_get function to specify the required
 * time component.
 */
typedef enum
{
  IO_TIME_REALTIME_SEC,  /**< Real-time clock, seconds part. */
  IO_TIME_REALTIME_NSEC,  /**< Real-time clock, nanoseconds part. */
  IO_TIME_MONOTONIC_SEC,  /**< Monotonic clock, seconds part. */
  IO_TIME_MONOTONIC_NSEC,  /**< Monotonic clock, nanoseconds part. */
} io_time_type;

extern const io_time *io_time_set(void);
extern uintmax_t io_time_get(io_time_type);
#endif  /* INCLUDED_io_time_h */

