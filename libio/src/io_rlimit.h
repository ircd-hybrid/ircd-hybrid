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
 * @file io_rlimit.h
 * @brief Provides an interface for managing resource limits, specifically core file size and the number of open files.
 *
 * This file contains function declarations for setting and retrieving resource limits to control
 * the maximum core file size and the maximum number of open files for the process.
 */

#ifndef INCLUDED_io_rlimit_h
#define INCLUDED_io_rlimit_h

extern void io_rlimit_set_max_core(void);
extern void io_rlimit_set_max_nofile(void);
extern size_t io_rlimit_get_cur_nofile(void);
#endif  /* INCLUDED_io_rlimit_h */
