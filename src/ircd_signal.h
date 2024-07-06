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
 * @file ircd_signal.h
 * @brief Header file for IRC daemon signal handling.
 */

#ifndef INCLUDED_ircd_signal_h
#define INCLUDED_ircd_signal_h

/**
 * @var dorehash
 * @brief Flag indicating if the server configuration should be re-read.
 *
 * This global variable is set to true when the server receives the SIGHUP signal,
 * indicating that the server configuration should be re-read.
 */
extern volatile sig_atomic_t dorehash;

/**
 * @var doremotd
 * @brief Flag indicating if the MOTD file should be re-read.
 *
 * This global variable is set to true when the server receives the SIGUSR1 signal,
 * indicating that the Message of the Day (MOTD) file should be re-read.
 */
extern volatile sig_atomic_t doremotd;

extern void ircd_signal_init(void);
#endif  /* INCLUDED_ircd_signal_h */
