/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
