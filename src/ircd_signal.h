/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file ircd_signal.h
 * @brief Header file for IRC daemon signal handling.
 */

#ifndef INCLUDED_ircd_signal_h
#define INCLUDED_ircd_signal_h
#include <signal.h>

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
