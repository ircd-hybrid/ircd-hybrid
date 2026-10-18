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

extern void ircd_signal_init(void);
extern void ircd_signal_process(void);
#endif  /* INCLUDED_ircd_signal_h */
