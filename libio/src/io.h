/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_io_h
#define INCLUDED_io_h
#include <limits.h>
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#if defined PATH_MAX
# define IO_PATH_MAX PATH_MAX
#elif defined MAXPATHLEN
# define IO_PATH_MAX MAXPATHLEN
#else
# define IO_PATH_MAX 4096
#endif

#if 0 && __GNUC__
#define IO_AFP(a,b) __attribute__((format (printf, a, b)))
#else
#define IO_AFP(a,b)
#endif

#endif  /* INCLUDED_io_h */
