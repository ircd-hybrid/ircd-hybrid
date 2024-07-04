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
static bool initialized = false;

/**
 * @brief Retrieves the current time for a specified clock.
 *
 * This function wraps the clock_gettime function and retrieves the current time for the
 * specified clock. If the clock_gettime call fails, the program exits with an error.
 *
 * @param clock_id The clock ID for which to retrieve the time.
 * @param ts       Pointer to a timespec structure to store the retrieved time.
 * @return int     Returns 0 on success. Exits with failure on error.
 */
static int
io_internal_gettime(clockid_t clock_id, struct timespec *ts)
{
  if (clock_gettime(clock_id, ts))
    exit(EXIT_FAILURE);  /* Exit on failure. */

  return 0;
}

/**
 * @brief Performs sanity checks on the retrieved time values.
 *
 * This function checks the validity of the retrieved time values, ensuring they are
 * positive, within the valid range, and progressing forward. If any check fails, it
 * returns an error code.
 *
 * @param new_time Pointer to the new timespec structure.
 * @param old_time Pointer to the old timespec structure.
 * @return int     Returns 0 on success, -1 on failure.
 */
static int
io_time_sanity_check(const struct timespec *new_time, const struct timespec *old_time)
{
  /* Check for positive time values in new_time. */
  if (new_time->tv_sec < 0 || new_time->tv_nsec < 0)
    return -1;  /* Invalid negative time value. */

  /* Ensure nanoseconds in new_time are within valid range. */
  if (new_time->tv_nsec >= 1000000000)
    return -1;  /* Nanoseconds out of range. */

  /* Check for time running backwards or not progressing. */
  if (new_time->tv_sec < old_time->tv_sec)
    return -1;  /* Time running backwards. */
  if (new_time->tv_sec == old_time->tv_sec && new_time->tv_nsec < old_time->tv_nsec)
    return -1;  /* Time running backwards. */

  /* Check for reasonable progression. */
  if (new_time->tv_sec - old_time->tv_sec > 3600)
    return -1;  /* Unreasonably large time jump. */

  return 0;
}

/**
 * @brief Updates and retrieves the current time values.
 *
 * This function updates the real-time and monotonic time values by calling internal functions
 * to retrieve the time from the system. It also performs sanity checks to ensure the retrieved
 * values are valid. If the values pass the sanity checks, they are stored in a static structure
 * and returned to the caller.
 *
 * @return const io_time* Pointer to the io_time structure containing the updated time values.
 *                        Returns NULL on failure.
 */
const io_time *
io_time_set(void)
{
  struct timespec current_realtime, current_monotonic;

  /* Get real-time clock. */
  if (io_internal_gettime(CLOCK_REALTIME, &current_realtime))
    return NULL;

  /* Get monotonic clock, use CLOCK_MONOTONIC_RAW if available. */
#ifdef CLOCK_MONOTONIC_RAW
  if (io_internal_gettime(CLOCK_MONOTONIC_RAW, &current_monotonic))
    if (io_internal_gettime(CLOCK_MONOTONIC, &current_monotonic))
      return NULL;
#else
  if (io_internal_gettime(CLOCK_MONOTONIC, &current_monotonic))
    return NULL;
#endif

  /* Perform sanity checks if the time values have been initialized before. */
  if (initialized)
  {
    /* Check both real-time and monotonic clocks for time going backwards or unreasonable jumps. */
    if (io_time_sanity_check(&current_realtime, &previous_realtime) ||
        io_time_sanity_check(&current_monotonic, &previous_monotonic))
      exit(EXIT_FAILURE);  /* Exit if sanity check fails. */
  }

  /* Update previous time data. */
  previous_realtime = current_realtime;
  previous_monotonic = current_monotonic;
  initialized = true;

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
