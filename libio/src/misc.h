/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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

extern const char *date(uintmax_t);
extern const char *date_iso8601(uintmax_t);
extern const char *date_iso8601_usec(uintmax_t);
extern const char *date_ctime(uintmax_t);
extern const char *time_format_duration(uintmax_t);
#endif  /* INCLUDED_misc_h */
