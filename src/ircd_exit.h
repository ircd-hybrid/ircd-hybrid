/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file ircd_exit.h
 * @brief Header file for server restart and termination functionality.
 */

#ifndef INCLUDED_ircd_exit_h
#define INCLUDED_ircd_exit_h

#include "io.h"

/**
 * @enum ircd_exit_action_t
 * @brief Actions for server exit.
 *
 * This enum defines the actions for the IRC server exit, either terminating or restarting.
 */
typedef enum
{
  IRCD_EXIT_TERMINATE,  /**< Terminate the server. */
  IRCD_EXIT_RESTART,  /**< Restart the server. */
} ircd_exit_action_t;

extern void ircd_exit(ircd_exit_action_t, const char *);
extern void ircd_exit_fmt(ircd_exit_action_t, const char *, ...) IO_AFP(2,3);
#endif  /* INCLUDED_ircd_exit_h */
