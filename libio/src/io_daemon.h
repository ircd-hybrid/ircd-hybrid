/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_io_daemon_h
#define INCLUDED_io_daemon_h
#include <sys/types.h>

typedef enum
{
  IO_DAEMON_CHILD,
  IO_DAEMON_PARENT,
  IO_DAEMON_ERROR
} io_daemon_result_t;

extern io_daemon_result_t io_daemonize(pid_t *);
#endif  /* INCLUDED_io_daemon_h */
