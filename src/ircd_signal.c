/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file ircd_signal.c
 * @brief Implements signal handling for the IRC daemon.
 *
 * This file contains functions for setting up and managing signal handlers
 * for the IRC daemon. It includes handlers for various signals and ensures
 * proper reaping of zombie processes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

#include "io_signal.h"
#include "ircd.h"
#include "ircd_exit.h"
#include "ircd_signal.h"

/**
 * @var dorehash
 * @brief Flag indicating if the server configuration should be re-read.
 *
 * This global variable is set to true when the server receives the SIGHUP signal,
 * indicating that the server configuration should be re-read.
 */
volatile sig_atomic_t dorehash;

/**
 * @var doremotd
 * @brief Flag indicating if the MOTD file should be re-read.
 *
 * This global variable is set to true when the server receives the SIGUSR1 signal,
 * indicating that the Message of the Day (MOTD) file should be re-read.
 */
volatile sig_atomic_t doremotd;

/**
 * @brief Unified signal handler for the IRC daemon.
 *
 * This function handles various signals by delegating to specific handlers
 * based on the signal number.
 *
 * @param sig Signal number.
 */
static void
_ircd_signal_handler(int sig)
{
  switch (sig)
  {
    case SIGTERM:
      ircd_exit(IRCD_EXIT_TERMINATE, "received signal SIGTERM");
      break;
    case SIGINT:
      ircd_exit(server_state.foreground ? IRCD_EXIT_TERMINATE : IRCD_EXIT_RESTART, "received signal SIGINT");
      break;
    case SIGHUP:
      dorehash = 1;
      break;
    case SIGUSR1:
      doremotd = 1;
      break;
    case SIGCHLD:
    {
      int saved_errno = errno;  /* Save errno to restore it later. */
      int status;

      /* Reap all zombie child processes. */
      while (waitpid(-1, &status, WNOHANG) > 0)
        ;
      errno = saved_errno;  /* Restore errno. */
      break;
    }
    default:
      break;
  }
}

/**
 * @brief Initializes signal handlers for the IRC daemon.
 *
 * This function sets up signal handlers for various signals using the
 * io_signal_register API. It also ignores certain signals that do not need
 * to be handled.
 */
void
ircd_signal_init(void)
{
  const io_signal_t signals[] =
  {
    { SIGTERM, _ircd_signal_handler },
    { SIGHUP, _ircd_signal_handler },
    { SIGUSR1, _ircd_signal_handler },
    { SIGCHLD, _ircd_signal_handler },
    { SIGINT, _ircd_signal_handler }
  };

  const int ignore_signals[] =
  {
    SIGPIPE,
    SIGALRM,
#ifdef SIGXFSZ
    SIGXFSZ,
#endif
#ifdef SIGWINCH
    SIGWINCH,
#endif
#ifdef SIGTRAP
    SIGTRAP,
#endif
  };

  if (io_signal_register(signals, IO_ARRAY_LENGTH(signals)) == -1)
  {
    fprintf(stderr, "Failed to set up signal handlers\n");
    exit(EXIT_FAILURE);
  }

  if (io_signal_ignore(ignore_signals, IO_ARRAY_LENGTH(ignore_signals)) == -1)
  {
    fprintf(stderr, "Failed to ignore signals\n");
    exit(EXIT_FAILURE);
  }
}
