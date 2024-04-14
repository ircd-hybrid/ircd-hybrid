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

#ifndef INCLUDED_io_h
#define INCLUDED_io_h

#include <limits.h>

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
