/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_io_h
#define INCLUDED_io_h
#include <limits.h>

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

#ifdef PATH_MAX
# define IO_PATH_MAX PATH_MAX
#else
# define IO_PATH_MAX 4096
#endif

#if defined(__GNUC__) || defined(__clang__)
# define IO_AFP(a, b) __attribute__((format(printf, a, b)))
#else
# define IO_AFP(a, b)
#endif
#endif  /* INCLUDED_io_h */
