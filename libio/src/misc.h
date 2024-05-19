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

/**
 * @file misc.h
 * @brief Header file for miscellaneous functions.
 */

#ifndef INCLUDED_misc_h
#define INCLUDED_misc_h

#include <stdint.h>

/**
 * @def IO_MAX
 * @brief Macro for maximum of two values.
 * @param a First value.
 * @param b Second value.
 * @return The greater of the two values.
 */
#define IO_MAX(a, b)  ((a) > (b) ? (a) : (b))

/**
 * @def IO_MIN
 * @brief Macro for minimum of two values.
 * @param a First value.
 * @param b Second value.
 * @return The smaller of the two values.
 */
#define IO_MIN(a, b)  ((a) < (b) ? (a) : (b))

/**
 * @def IO_ARRAY_LENGTH
 * @brief Macro to determine the number of elements in an array.
 * @param x Array whose number of elements is to be determined.
 * @return The number of elements in the array.
 */
#define IO_ARRAY_LENGTH(x) ((sizeof(x)) / sizeof(x[0]))

/**
 * @def _1MEG
 * @brief Represents 1 Mebibyte (MiB).
 *
 * This macro defines the size equivalent to 1 MiB, where 1 MiB equals 1024 Kibibytes (KiB).
 */
#define _1MEG     (1024.0f)

/**
 * @def _1GIG
 * @brief Represents 1 Gibibyte (GiB).
 *
 * This macro defines the size equivalent to 1 GiB, where 1 GiB equals 1024 Mebibytes (MiB).
 */
#define _1GIG     (1024.0f * 1024.0f)

/**
 * @def _1TER
 * @brief Represents 1 Tebibyte (TiB).
 *
 * This macro defines the size equivalent to 1 TiB, where 1 TiB equals 1024 Gibibytes (GiB).
 */
#define _1TER     (1024.0f * 1024.0f * 1024.0f)

/**
 * @def _GMKs
 * @brief Returns a string representing the appropriate size unit for a given size.
 * @param x Size value.
 * @return String representation of the size unit (Kibibytes, Mebibytes, Gibibytes, or Tebibytes).
 */
#define _GMKs(x)  (((x) > _1TER) ? "Tebibytes" : (((x) > _1GIG) ? "Gibibytes" :\
                  (((x) > _1MEG) ? "Mebibytes" : "Kibibytes")))

/**
 * @def _GMKv
 * @brief Returns the size value converted to the appropriate unit.
 * @param x Size value.
 * @return Size value converted to Kibibytes, Mebibytes, Gibibytes, or left unchanged.
 */
#define _GMKv(x)  (((x) > _1TER) ? (float)((x)/_1TER) : (((x) > _1GIG) ? \
                   (float)((x)/_1GIG) : (((x) > _1MEG) ? (float)((x)/_1MEG) : \
                   (float)(x))))

extern const char *date(uintmax_t);
extern const char *date_iso8601(uintmax_t);
extern const char *date_iso8601_usec(uintmax_t);
extern const char *date_ctime(uintmax_t);
extern const char *time_format_duration(uintmax_t);
extern void binary_to_hex(const unsigned char *, char *, unsigned int);
#endif  /* INCLUDED_misc_h */
