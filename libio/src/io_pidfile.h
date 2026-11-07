/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
#include <sys/types.h>

extern void io_pidfile_close(void);
extern int io_pidfile_create(const char *);
extern int io_pidfile_read(const char *, pid_t *);
extern int io_pidfile_remove(const char *);
#endif  /* INCLUDED_pidfile_h */
