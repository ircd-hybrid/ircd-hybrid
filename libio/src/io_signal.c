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
 * @file io_signal.c
 * @brief Implements functions for setting up, unregistering, and ignoring signal handlers.
 *
 * This file contains the implementation of functions for registering, unregistering, and ignoring
 * signal handlers using sigaction and unblocking the specified signals.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include "io_signal.h"

/**
 * @brief Registers signal handlers and unblocks the specified signals.
 *
 * This function registers handlers for the given signals using sigaction
 * and unblocks them to ensure they can be delivered to the process.
 *
 * @param signals Array of signal-handler pairs.
 * @param elements The number of signal-handler pairs in the array.
 * @return int Returns 0 on success, -1 on failure.
 */
int
io_signal_register(const io_signal_t *signals, size_t elements)
{
  sigset_t set;
  sigemptyset(&set);

  for (size_t i = 0; i < elements; ++i)
  {
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = signals[i].handler;
    sigemptyset(&act.sa_mask);

    if (sigaction(signals[i].signum, &act, NULL))
    {
      fprintf(stderr, "Failed to set handler for signal %d: %s\n", signals[i].signum, strerror(errno));
      return -1;
    }

    sigaddset(&set, signals[i].signum);
  }

  if (sigprocmask(SIG_UNBLOCK, &set, NULL))
  {
    fprintf(stderr, "Failed to unblock signals: %s\n", strerror(errno));
    return -1;
  }

  return 0;
}

/**
 * @brief Unregisters signal handlers and resets to default actions.
 *
 * This function unregisters handlers for the given signals, resetting them to their
 * default actions, and unblocks the specified signals to ensure they can be delivered
 * to the process.
 *
 * @param signals Array of signal numbers to unregister.
 * @param elements The number of signals in the array.
 * @return int Returns 0 on success, -1 on failure.
 */
int
io_signal_unregister(const int *signals, size_t elements)
{
  sigset_t set;
  sigemptyset(&set);

  for (size_t i = 0; i < elements; ++i)
  {
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = SIG_DFL;
    sigemptyset(&act.sa_mask);

    if (sigaction(signals[i], &act, NULL))
    {
      fprintf(stderr, "Failed to unregister handler for signal %d: %s\n", signals[i], strerror(errno));
      return -1;
    }

    sigaddset(&set, signals[i]);
  }

  if (sigprocmask(SIG_UNBLOCK, &set, NULL))
  {
    fprintf(stderr, "Failed to unblock signals: %s\n", strerror(errno));
    return -1;
  }

  return 0;
}

/**
 * @brief Ignores the specified signals.
 *
 * This function sets the handlers for the given signals to SIG_IGN, effectively
 * ignoring them, and unblocks the specified signals to ensure they can be delivered
 * to the process.
 *
 * @param signals Array of signal numbers to ignore.
 * @param elements The number of signals in the array.
 * @return int Returns 0 on success, -1 on failure.
 */
int
io_signal_ignore(const int *signals, size_t elements)
{
  sigset_t set;
  sigemptyset(&set);

  for (size_t i = 0; i < elements; ++i)
  {
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = SIG_IGN;
    sigemptyset(&act.sa_mask);

    if (sigaction(signals[i], &act, NULL))
    {
      fprintf(stderr, "Failed to ignore signal %d: %s\n", signals[i], strerror(errno));
      return -1;
    }

    sigaddset(&set, signals[i]);
  }

  if (sigprocmask(SIG_UNBLOCK, &set, NULL))
  {
    fprintf(stderr, "Failed to unblock signals: %s\n", strerror(errno));
    return -1;
  }

  return 0;
}
