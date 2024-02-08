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
 * @file ircd_signal.c
 * @brief Responsible for handling signals in the IRC daemon.
 *
 * This file contains functions for handling various signals that the IRC daemon may receive.
 */

#include "stdinc.h"
#include "ircd_signal.h"
#include "ircd.h"
#include "restart.h"

/**
 * @brief Handles the SIGTERM signal, causing the server to exit gracefully.
 *
 * This function is the signal handler for the SIGTERM signal. When the
 * server receives the SIGTERM signal, it calls this function, prompting
 * the server to exit gracefully.
 *
 * @param sig Signal number (SIGTERM).
 */
static void
sigterm_handler(int sig)
{
  server_die("received signal SIGTERM", false);
}

/**
 * @brief Handles the SIGHUP signal, triggering a reread of the server configuration.
 *
 * This function is the signal handler for the SIGHUP signal. When the
 * server receives the SIGHUP signal, it sets the global flag `dorehash`
 * to true, prompting a reread of the server configuration.
 *
 * @param sig Signal number (SIGHUP).
 */
static void
sighup_handler(int sig)
{
  dorehash = true;
}

/**
 * @brief Handles the SIGUSR1 signal, triggering a reread of the MOTD file.
 *
 * This function is the signal handler for the SIGUSR1 signal. When the
 * server receives the SIGUSR1 signal, it sets the global flag `doremotd`
 * to true, prompting a reread of the Message of the Day (MOTD) file.
 *
 * @param sig Signal number (SIGUSR1).
 */
static void
sigusr1_handler(int sig)
{
  doremotd = true;
}

/**
 * @brief Reaps zombie processes periodically as a side effect.
 *
 * This function is the signal handler for the SIGCHLD signal. When the
 * server receives the SIGCHLD signal, it reaps zombie processes
 * periodically to prevent them from lingering in the system.
 *
 * @param sig Signal number (SIGCHLD).
 */
static void
sigchld_handler(int sig)
{
  int status, errno_save = errno;

  while (waitpid(-1, &status, WNOHANG) > 0)
    ;
  errno = errno_save;
}

/**
 * @brief Handles the SIGINT signal, restarting the server if running in the background.
 *
 * This function is the signal handler for the SIGINT signal. When the
 * server receives the SIGINT signal, it calls `server_die` to exit gracefully.
 * If the server is running in the background, it restarts the server.
 *
 * @param sig Signal number (SIGINT).
 */
static void
sigint_handler(int sig)
{
  server_die("received signal SIGINT", server_state.foreground ? false : true);
}

/**
 * @brief Initializes signal handlers for the server.
 *
 * This function sets up the signal handlers for various signals, including
 * SIGXFSZ, SIGWINCH, SIGTRAP, SIGPIPE, SIGALRM, SIGHUP, SIGINT, SIGTERM,
 * SIGUSR1, and SIGCHLD. It also specifies the corresponding signal handlers
 * for each signal.
 */
void
setup_signals(void)
{
  struct sigaction act;

  act.sa_flags = 0;
  act.sa_handler = SIG_IGN;

  sigemptyset(&act.sa_mask);
#ifdef SIGXFSZ
  sigaddset(&act.sa_mask, SIGXFSZ);
#endif
#ifdef SIGWINCH
  sigaddset(&act.sa_mask, SIGWINCH);
#endif
#ifdef SIGTRAP
  sigaddset(&act.sa_mask, SIGTRAP);
#endif
  sigaddset(&act.sa_mask, SIGPIPE);
  sigaddset(&act.sa_mask, SIGALRM);
  sigaddset(&act.sa_mask, SIGHUP);
  sigaddset(&act.sa_mask, SIGINT);
  sigaddset(&act.sa_mask, SIGTERM);
  sigaddset(&act.sa_mask, SIGUSR1);
  sigaddset(&act.sa_mask, SIGCHLD);

#ifdef SIGXFSZ
  sigaction(SIGXFSZ, &act, NULL);
#endif
#ifdef SIGWINCH
  sigaction(SIGWINCH, &act, NULL);
#endif
#ifdef SIGTRAP
  sigaction(SIGTRAP, &act, NULL);
#endif
  sigaction(SIGPIPE, &act, NULL);
  sigaction(SIGALRM, &act, NULL);

  act.sa_handler = sighup_handler;
  sigaction(SIGHUP, &act, NULL);

  act.sa_handler = sigint_handler;
  sigaction(SIGINT, &act, NULL);

  act.sa_handler = sigterm_handler;
  sigaction(SIGTERM, &act, NULL);

  act.sa_handler = sigusr1_handler;
  sigaction(SIGUSR1, &act, NULL);

  act.sa_handler = sigchld_handler;
  sigaction(SIGCHLD, &act, NULL);

  sigprocmask(SIG_UNBLOCK, &act.sa_mask, NULL);
}
