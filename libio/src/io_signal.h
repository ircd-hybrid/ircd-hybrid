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
 * @file io_signal.h
 * @brief Provides an interface for setting up, unregistering, and ignoring signal handlers.
 *
 * This file contains functions for registering, unregistering, and ignoring signal handlers.
 * It also provides functionality to unblock signals.
 */

#ifndef INCLUDED_io_signal_h
#define INCLUDED_io_signal_h

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
