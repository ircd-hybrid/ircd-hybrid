/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file ircd_exit.c
 * @brief Functions to facilitate the restart and termination of the IRC server.
 */

#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "io_pidfile.h"
#include "io_poll.h"
#include "io_socket.h"
#include "io_string.h"
#include "log.h"
#include "resolver.h"

#include "client.h"
#include "conf_db.h"
#include "defaults.h"
#include "ircd.h"
#include "ircd_exit.h"
#include "ircd_module.h"
#include "listener.h"
#include "send.h"

/**
 * @brief Initiates server termination or restart with a formatted message.
 *
 * This function is responsible for initiating the termination or restart of the IRC server
 * with a formatted message indicating the reason.
 *
 * @param action The termination or restart action, including the exit status.
 * @param format A format string indicating the reason for server termination or restart.
 * @param ... Additional arguments to be formatted into the message.
 */
void
ircd_exit_fmt(ircd_exit_action_t action, const char *format, ...)
{
  char buf[IRCD_BUFSIZE];
  va_list args;

  va_start(args, format);
  vsnprintf(buf, sizeof(buf), format, args);
  va_end(args);

  ircd_exit(action, buf);
}

/**
 * @brief Initiates server termination or restart.
 *
 * This function is responsible for initiating the termination or restart of the IRC server.
 * It broadcasts server termination or restart messages, saves databases, closes file descriptors,
 * unlinks the PID file, and then either restarts the server or exits based on the 'action'
 * parameter. In the case of a restart, it attempts to execute the server binary with the original
 * command line arguments.
 *
 * @param action The termination or restart action, including the exit status.
 * @param message A message indicating the reason for server termination or restart.
 */
void
ircd_exit(ircd_exit_action_t action, const char *message)
{
  static bool was_here = false;

  if (was_here)
    abort();
  was_here = true;

  char buf[IRCD_BUFSIZE];
  if (string_is_empty(message))
    snprintf(buf, sizeof(buf), "Server is %s",
             action == IRCD_EXIT_RESTART ? "restarting" : "terminating");
  else
    snprintf(buf, sizeof(buf), "Server is %s: %s",
             action == IRCD_EXIT_RESTART ? "restarting" : "terminating", message);

  sendto_clients(0, SEND_RECIPIENT_CLIENT, SEND_TYPE_NOTICE, "%s", buf);

  sendto_servers(NULL, 0, 0, ":%s ERROR :%s", me.id, buf);

  log_write(LOG_TYPE_IRCD, "%s", buf);

  conf_db_save_all(NULL);

  ircd_module_shutdown();

  client_close_local_connections();
  listener_close_all();
  resolver_shutdown();

  io_pidfile_remove(pidFileName);
  io_pidfile_close();

  /* Live sockets retain their poller and are closed by the process exit or exec. */
  if (io_socket_context_destroy(ircd_socket_context) == 0)
    io_poll_destroy(ircd_poller);
  else
    log_write(LOG_TYPE_IRCD, "Failed to destroy socket context: %s", strerror(errno));

  if (action == IRCD_EXIT_RESTART)
  {
    execv(SPATH, myargv);
    log_write(LOG_TYPE_IRCD, "Failed to execute %s: %s", SPATH, strerror(errno));
  }

  exit(action == IRCD_EXIT_TERMINATE ? EXIT_SUCCESS : EXIT_FAILURE);
}
