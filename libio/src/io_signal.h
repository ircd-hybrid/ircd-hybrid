/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file io_signal.h
 * @brief Provides an interface for setting up, unregistering, and ignoring signal handlers.
 *
 * This file contains functions for registering, unregistering, and ignoring signal handlers.
 * It also provides functionality to unblock signals.
 */

#ifndef INCLUDED_io_signal_h
#define INCLUDED_io_signal_h
#include <stddef.h>

/**
 * @brief Structure to define a signal and its handler.
 *
 * This structure holds a signal number and a corresponding handler function.
 * It is used to register signal handlers.
 */
typedef struct
{
  int signum;  /**< Signal number */
  void (*handler)(int);  /**< Handler function */
} io_signal_t;

extern int io_signal_register(const io_signal_t *, size_t);
extern int io_signal_unregister(const int *, size_t);
extern int io_signal_ignore(const int *, size_t);
#endif  /* INCLUDED_io_signal_h */
