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
 * @def IO_TIME_ERROR_BUFFER_SIZE
 * @brief Buffer size for storing error messages.
 *
 * This constant defines the size of the buffer used for storing error messages
 * encountered during time provider operations. It ensures that error messages are properly
 * bounded and do not overflow.
 */
#define IO_TIME_ERROR_BUFFER_SIZE 256

/**
 * @enum io_time_error_code
 * @brief Enum for representing error codes for time provider operations.
 *
 * This enum lists possible error codes returned by time provider operations such as initialization,
 * retrieving time, and sanity checks. Each code provides a specific reason for a failure or success state.
 */
enum io_time_error_code
{
  IO_TIME_OK = 0,  /**< Operation completed successfully. */
  IO_TIME_ERR_INIT,  /**< Initialization failed. */
  IO_TIME_ERR_GET_REAL,  /**< Failed to get real-time. */
  IO_TIME_ERR_GET_MONO,  /**< Failed to get monotonic time. */
  IO_TIME_ERR_GET_MONO_RAW,  /**< Failed to get monotonic raw time. */
  IO_TIME_ERR_NEGATIVE,  /**< Clock failure: negative time value. */
  IO_TIME_ERR_NSEC_RANGE,  /**< Clock failure: nanoseconds out of range. */
  IO_TIME_ERR_BACKWARDS,  /**< Clock failure: time running backwards. */
  IO_TIME_ERR_LARGE_JUMP,  /**< Clock failure: large time jump. */
  IO_TIME_ERR_COUNT  /**< Number of error codes defined. */
};

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

extern void io_time_set_error_callback(void (*)(enum io_time_error_code, const char *));
extern const char *io_time_get_error(void);
extern int io_time_init(void);
extern const io_time *io_time_set(void);
extern uintmax_t io_time_get(io_time_type);
#endif  /* INCLUDED_io_time_h */

