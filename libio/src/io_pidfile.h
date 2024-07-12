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
 * @file io_pidfile.h
 * @brief Provides an interface for handling PID files, including reading, writing, and locking.
 *
 * This file contains functions for creating, locking, and managing PID files to ensure that
 * only one instance of a process is running at a time.
 */

#ifndef INCLUDED_pidfile_h
#define INCLUDED_pidfile_h

#include <unistd.h>

extern void io_pidfile_close(void);
extern int io_pidfile_create(const char *);
extern int io_pidfile_read(const char *, pid_t *);
extern int io_pidfile_remove(const char *);
#endif  /* INCLUDED_pidfile_h */
