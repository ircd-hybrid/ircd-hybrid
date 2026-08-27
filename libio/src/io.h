/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_io_h
#define INCLUDED_io_h
#include <limits.h>

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
