/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*
 * @file misc.c
 * @brief Miscellaneous functions for IRCd.
 */

#include "stdinc.h"
#include "misc.h"
#include "irc_string.h"
#include "ircd.h"

/**
 * @brief Formats a given time value into a human-readable string using the strftime format.
 *
 * This function formats the provided time value into a string representing the date
 * using the "%A %B %-e %Y -- %T %z" strftime format. It caches the result to avoid
 * repetitive strftime() calls with the same time value.
 *
 * @param lclock Time value to format (default is the current server time).
 * @return Formatted date string.
 */
const char *
date(uintmax_t lclock)
{
  static char buf[80];
  static uintmax_t lclock_last;

  if (lclock == 0)
    lclock = event_base->time.sec_real;

  if (lclock_last != lclock)
  {
    lclock_last = lclock;  /* Cache value to avoid repetitive strftime() calls. */
    strftime(buf, sizeof(buf), "%A %B %-e %Y -- %T %z", localtime((time_t *)&lclock));
  }

  return buf;
}

/**
 * @brief Formats a given time value into ISO 8601 date and time string.
 *
 * This function formats the provided time value into a string representing the date
 * using the "%FT%T%z" strftime format (ISO 8601). It caches the result to avoid
 * repetitive strftime() calls with the same time value.
 *
 * @param lclock Time value to format (default is the current server time).
 * @return Formatted ISO 8601 date and time string.
 */
const char *
date_iso8601(uintmax_t lclock)
{
  static char buf[MAX_DATE_STRING];
  static uintmax_t lclock_last;

  if (lclock == 0)
    lclock = event_base->time.sec_real;

  if (lclock_last != lclock)
  {
    lclock_last = lclock;  /* Cache value to avoid repetitive strftime() calls. */
    strftime(buf, sizeof(buf), "%FT%T%z", localtime((time_t *)&lclock));
  }

  return buf;
}

/**
 * @brief Formats the current date and time in ISO 8601 format with microseconds.
 *
 * This function generates a string representing the current date and time
 * in the ISO 8601 format (YYYY-MM-DDTHH:MM:SS.microsecondsZ). The result is
 * stored in a static buffer, and the pointer to this buffer is returned.
 *
 * @param unused Unused parameter. This parameter is not used in the function.
 * @return A pointer to the formatted date and time string.
 */
const char *
date_iso8601_usec(uintmax_t unused)
{
  static char buf[MAX_DATE_STRING];
  struct timeval tv;

  gettimeofday(&tv, NULL);
  uintmax_t current_time = tv.tv_sec;

  const struct tm *time_info = localtime((time_t *)&current_time);
  size_t len = strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%S", time_info);

  /* Append microseconds. */
  len += snprintf(buf + len, sizeof(buf) - len, ".%06ld", tv.tv_usec);
    
  /* Append UTC offset. */
  strftime(buf + len, sizeof(buf) - len, "%z", time_info);

  return buf;
}

/**
 * @brief Formats a given time value into a string using the ctime format.
 *
 * This function formats the provided time value into a string using the ctime format,
 * without the trailing newline. It caches the result to avoid repetitive strftime() calls
 * with the same time value.
 *
 * @param lclock Time value to format (default is the current server time).
 * @return Formatted ctime string without newline.
 */
const char *
date_ctime(uintmax_t lclock)
{
  static char buf[MAX_DATE_STRING];
  static uintmax_t lclock_last;

  if (lclock == 0)
    lclock = event_base->time.sec_real;

  if (lclock_last != lclock)
  {
    lclock_last = lclock;  /* Cache value to avoid repetitive strftime() calls. */
    strftime(buf, sizeof(buf), "%a %b %-e %T %Y", localtime((time_t *)&lclock));
  }

  return buf;
}

/**
 * @brief Converts a duration in seconds into a human-readable string.
 *
 * This function takes a duration in seconds and formats it into a string representing
 * days, hours, minutes, and seconds (e.g., "3 days, 23:59:59").
 *
 * @param duration Duration in seconds.
 * @return Formatted duration string.
 */
const char *
time_dissect(uintmax_t duration)
{
  static char buf[32];  /* 32 = sizeof("9999999999999999 days, 23:59:59") */
  unsigned int days = 0, hours = 0, minutes = 0, seconds = 0;

  while (duration >= 60 * 60 * 24)
  {
    duration -= 60 * 60 * 24;
    ++days;
  }

  while (duration >= 60 * 60)
  {
    duration -= 60 * 60;
    ++hours;
  }

  while (duration >= 60)
  {
    duration -= 60;
    ++minutes;
  }

  seconds = duration;

  snprintf(buf, sizeof(buf), "%u day%s, %02u:%02u:%02u",
           days, days == 1 ? "" : "s", hours, minutes, seconds);
  return buf;
}

/**
 * @brief Converts binary data to a hexadecimal string.
 *
 * This function takes binary data and converts it into a hexadecimal string.
 *
 * @param bin Binary data to convert.
 * @param hex Output buffer for the hexadecimal string.
 * @param length Length of the binary data.
 */
void
binary_to_hex(const unsigned char *bin, char *hex, unsigned int length)
{
  static const char trans[] = "0123456789ABCDEF";

  for (const unsigned char *const end = bin + length; bin < end; ++bin)
  {
    *hex++ = trans[*bin >>  4];
    *hex++ = trans[*bin & 0xf];
  }

  *hex = '\0';
}
