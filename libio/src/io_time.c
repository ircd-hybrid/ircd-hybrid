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
 * @file io_time.c
 * @brief Implements the functions for retrieving real-time and monotonic time values.
 *
 * This file contains the implementation of functions that retrieve real-time and
 * monotonic time values, perform sanity checks, and handle errors.
 */

#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "io_time.h"

/**
 * @var previous_realtime
 * @brief Stores the previous real-time clock value.
 *
 * This variable maintains the previous real-time clock value to perform sanity checks
 * and ensure time progression. It helps detect anomalies such as time running backwards.
 */
static struct timespec previous_realtime;

/**
 * @var previous_monotonic
 * @brief Stores the previous monotonic clock value.
 *
 * This variable maintains the previous monotonic clock value to perform sanity checks
 * and ensure time progression. It helps detect anomalies such as time running backwards.
 */
static struct timespec previous_monotonic;

/**
 * @var current_time_data
 * @brief Stores the current real-time and monotonic time values.
 *
 * This variable maintains the current real-time and monotonic time values, updated by
 * the io_time_set function. It provides the latest time values to the io_time_get function.
 */
static io_time current_time_data;

/**
 * @var initialized
 * @brief Indicates whether the time values have been initialized.
 *
 * This boolean variable indicates whether the time values have been initialized
 * and are ready for use. Initialization is necessary to perform sanity checks.
 */
static bool initialized;

/**
 * @var io_time_error_callback
 * @brief Callback for error events.
 *
 * This function pointer stores the callback function that will be called when an error occurs.
 * The callback can be used to perform additional actions or logging when an error is encountered.
 */
static void (*io_time_error_callback)(enum io_time_error_code, const char *);

/**
 * @var io_time_last_error
 * @brief Buffer for storing the last error message.
 *
 * This buffer stores the last error message encountered during time provider operations.
 * It provides detailed information about the most recent error for debugging and logging purposes.
 */
static char io_time_last_error[IO_TIME_ERROR_BUFFER_SIZE];

/**
 * @var io_time_error_strings
 * @brief Array of error message strings corresponding to io_time_error_code values.
 *
 * This array stores human-readable error messages for each error code defined in io_time_error_code.
 * It is used to format detailed error messages for debugging and logging purposes.
 */
static const char *const io_time_error_strings[IO_TIME_ERR_COUNT] =
{
  [IO_TIME_OK] = "Operation completed successfully",
  [IO_TIME_ERR_INIT] = "Failed to initialize the time provider API",
  [IO_TIME_ERR_GET_REAL] = "Failed to get real-time",
  [IO_TIME_ERR_GET_MONO] = "Failed to get monotonic time",
  [IO_TIME_ERR_GET_MONO_RAW] = "Failed to get monotonic raw time",
  [IO_TIME_ERR_NEGATIVE] = "Clock failure: negative time value",
  [IO_TIME_ERR_NSEC_RANGE] = "Clock failure: nanoseconds out of range",
  [IO_TIME_ERR_BACKWARDS] = "Clock failure: time moved backwards. Current: %ld s, %ld ns. Previous: %ld s, %ld ns. Delta: %ld s, %ld ns.",
  [IO_TIME_ERR_LARGE_JUMP] = "Clock failure: large time jump. Current: %ld s, %ld ns. Previous: %ld s, %ld ns. Delta: %ld s, %ld ns."
};

/**
 * @brief Sets the error callback function.
 *
 * This function sets the callback function to be called when an error occurs.
 *
 * @param callback The error callback function to set.
 */
void
io_time_set_error_callback(void (*callback)(enum io_time_error_code, const char *))
{
  io_time_error_callback = callback;
}

/**
 * @brief Sets the last error message for time provider operations.
 *
 * This function sets the last error message using a formatted string. It is used internally
 * to provide detailed error messages for time provider operations that encounter issues.
 *
 * @param code Error code indicating the type of error.
 * @param current The current time value causing the error.
 * @param previous The previous time value causing the error.
 */
static void
io_time_set_error(enum io_time_error_code code, const struct timespec *current, const struct timespec *previous)
{
  long delta_sec = current->tv_sec - previous->tv_sec;
  long delta_nsec = current->tv_nsec - previous->tv_nsec;

  if (delta_nsec < 0)
  {
    delta_sec -= 1;
    delta_nsec += 1000000000;
  }

  snprintf(io_time_last_error, sizeof(io_time_last_error), io_time_error_strings[code],
           current->tv_sec, current->tv_nsec, previous->tv_sec, previous->tv_nsec, delta_sec, delta_nsec);
}

/**
 * @brief Retrieves the last error message.
 *
 * This function returns the last error message set during time provider operations. It can be used
 * to obtain detailed information about the most recent error that occurred.
 *
 * @return Pointer to the last error message.
 */
const char *
io_time_get_error(void)
{
  return io_time_last_error;
}

/**
 * @brief Initializes the time provider API.
 *
 * This function initializes the time provider API by calling io_time_set to retrieve the current
 * time data. If the initialization fails, it calls the error callback with an appropriate error code
 * and message.
 *
 * @return int Returns 0 on successful initialization, -1 on failure.
 */
int
io_time_init(void)
{
  if (initialized)
    return 0;

  const io_time *const iotime = io_time_set();
  if (iotime == NULL)
  {
    if (io_time_error_callback)
      io_time_error_callback(IO_TIME_ERR_INIT, io_time_get_error());

    return -1;
  }

  initialized = true;
  return 0;
}

/**
 * @brief Retrieves the current time for a specified clock.
 *
 * This function wraps the clock_gettime function and retrieves the current time for the
 * specified clock. If the clock_gettime call fails, it returns the appropriate error code.
 *
 * @param clock_id The clock ID for which to retrieve the time.
 * @param ts Pointer to a timespec structure to store the retrieved time.
 * @return enum io_time_error_code Returns an appropriate error code.
 */
static enum io_time_error_code
io_internal_gettime(clockid_t clock_id, struct timespec *ts)
{
  if (clock_gettime(clock_id, ts))
  {
    switch (clock_id)
    {
      case CLOCK_REALTIME:
        return IO_TIME_ERR_GET_REAL;
      case CLOCK_MONOTONIC:
        return IO_TIME_ERR_GET_MONO;
      case CLOCK_MONOTONIC_RAW:
        return IO_TIME_ERR_GET_MONO_RAW;
      default:
        abort();  /* Invalid clock_id, abort the program. */
    }
  }

  return IO_TIME_OK;
}

/**
 * @brief Performs sanity checks on the retrieved time values.
 *
 * This function checks the validity of the retrieved time values, ensuring they are
 * positive, within the valid range, and progressing forward. If any check fails, it
 * returns an appropriate error code.
 *
 * @param new_time Pointer to the new timespec structure.
 * @param old_time Pointer to the old timespec structure.
 * @return enum io_time_error_code Returns an appropriate error code.
 */
static enum io_time_error_code
io_time_sanity_check(const struct timespec *new_time, const struct timespec *old_time)
{
  /* Check for positive time values in new_time. */
  if (new_time->tv_sec < 0 || new_time->tv_nsec < 0)
    return IO_TIME_ERR_NEGATIVE;  /* Invalid negative time value. */

  /* Ensure nanoseconds in new_time are within valid range. */
  if (new_time->tv_nsec >= 1000000000)
    return IO_TIME_ERR_NSEC_RANGE;  /* Nanoseconds out of range. */

  /* Check for time running backwards. */
  if (new_time->tv_sec < old_time->tv_sec)
    return IO_TIME_ERR_BACKWARDS;  /* Time running backwards. */
  if (new_time->tv_sec == old_time->tv_sec && new_time->tv_nsec < old_time->tv_nsec)
    return IO_TIME_ERR_BACKWARDS;  /* Time running backwards. */

  /* Check for reasonable progression. */
  if (new_time->tv_sec - old_time->tv_sec > 3600)
    return IO_TIME_ERR_LARGE_JUMP;  /* Unreasonably large time jump. */

  return IO_TIME_OK;
}

/**
 * @brief Updates and retrieves the current time values.
 *
 * This function updates the real-time and monotonic time values by calling internal functions
 * to retrieve the time from the system. It also performs sanity checks to ensure the retrieved
 * values are valid. If the values pass the sanity checks, they are stored in a static structure
 * and returned to the caller. If any error occurs, the error callback is invoked.
 *
 * @return const io_time* Pointer to the io_time structure containing the updated time values.
 *                        Returns NULL on failure.
 */
const io_time *
io_time_set(void)
{
  struct timespec current_realtime, current_monotonic;

  enum io_time_error_code ret = io_internal_gettime(CLOCK_REALTIME, &current_realtime);
  if (ret != IO_TIME_OK)
  {
    io_time_set_error(ret, &current_realtime, &previous_realtime);

    if (io_time_error_callback)
      io_time_error_callback(ret, io_time_get_error());
    return NULL;
  }

#ifdef CLOCK_MONOTONIC_RAW
  ret = io_internal_gettime(CLOCK_MONOTONIC_RAW, &current_monotonic);
  if (ret != IO_TIME_OK)
  {
    ret = io_internal_gettime(CLOCK_MONOTONIC, &current_monotonic);
    if (ret != IO_TIME_OK)
    {
      io_time_set_error(ret, &current_monotonic, &previous_monotonic);

      if (io_time_error_callback)
        io_time_error_callback(ret, io_time_get_error());
      return NULL;
    }
  }
#else
  ret = io_internal_gettime(CLOCK_MONOTONIC, &current_monotonic);
  if (ret != IO_TIME_OK)
  {
    io_time_set_error(ret, &current_monotonic, &previous_monotonic);

    if (io_time_error_callback)
      io_time_error_callback(ret, io_time_get_error());
    return NULL;
  }
#endif

  ret = io_time_sanity_check(&current_realtime, &previous_realtime);
  if (ret != IO_TIME_OK)
  {
    io_time_set_error(ret, &current_realtime, &previous_realtime);

    if (io_time_error_callback)
      io_time_error_callback(ret, io_time_get_error());
    return NULL;
  }

  ret = io_time_sanity_check(&current_monotonic, &previous_monotonic);
  if (ret != IO_TIME_OK)
  {
    io_time_set_error(ret, &current_monotonic, &previous_monotonic);

    if (io_time_error_callback)
      io_time_error_callback(ret, io_time_get_error());
    return NULL;
  }

  /* Update previous time data. */
  previous_realtime = current_realtime;
  previous_monotonic = current_monotonic;

  /* Update the public io_time structure. */
  current_time_data.sec_real = current_realtime.tv_sec;
  current_time_data.nsec_real = current_realtime.tv_nsec;
  current_time_data.sec_monotonic = current_monotonic.tv_sec;
  current_time_data.nsec_monotonic = current_monotonic.tv_nsec;

  return &current_time_data;
}

/**
 * @brief Retrieves a specific part of the current time values.
 *
 * This function retrieves a specific part of the current time values (seconds or nanoseconds,
 * real-time or monotonic) as specified by the io_time_type enumeration.
 *
 * @param type The type of time value to retrieve, specified as an io_time_type enumeration.
 * @return uintmax_t The requested time value. Aborts if an invalid type is specified.
 */
uintmax_t
io_time_get(io_time_type type)
{
  switch (type)
  {
    case IO_TIME_REALTIME_SEC:
      return current_time_data.sec_real;
    case IO_TIME_REALTIME_NSEC:
      return current_time_data.nsec_real;
    case IO_TIME_MONOTONIC_SEC:
      return current_time_data.sec_monotonic;
    case IO_TIME_MONOTONIC_NSEC:
      return current_time_data.nsec_monotonic;
    default:
      abort();  /* Invalid type, abort the program. */
  }
}
