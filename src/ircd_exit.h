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
 * @file ircd_exit.h
 * @brief Header file for server restart and termination functionality.
 */

#ifndef INCLUDED_ircd_exit_h
#define INCLUDED_ircd_exit_h

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
extern void ircd_exit_fmt(ircd_exit_action_t, const char *, ...);
#endif  /* INCLUDED_ircd_exit_h */
