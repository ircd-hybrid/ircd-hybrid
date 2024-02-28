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
 * @file restart.c
 * @brief Functions to facilitate the restart and termination of the IRC server.
 */

#include "stdinc.h"
#include "list.h"
#include "restart.h"
#include "fdlist.h"
#include "ircd.h"
#include "irc_string.h"
#include "send.h"
#include "log.h"
#include "client.h"
#include "conf_db.h"

/**
 * @brief Initiates server termination or restart.
 *
 * This function is responsible for initiating the termination or restart of the IRC server.
 * It broadcasts server termination or restart messages, saves databases, closes file descriptors,
 * unlinks the PID file, and then either restarts the server or exits based on the 'restart' parameter.
 * In the case of a restart, it attempts to execute the server binary with the original command line arguments.
 *
 * @param message A message indicating the reason for server termination or restart.
 * @param restart A boolean flag indicating whether to restart the server (true) or terminate it (false).
 */
void
server_die(const char *message, bool restart)
{
  char buf[IRCD_BUFSIZE];

  if (restart)
  {
    static bool was_here = false;
    if (was_here)
      abort();

    was_here = true;
  }

  if (EmptyString(message))
    snprintf(buf, sizeof(buf), "Server %s",
             restart ? "Restarting" : "Terminating");
  else
    snprintf(buf, sizeof(buf), "Server %s: %s",
             restart ? "Restarting" : "Terminating", message);

  dlink_node *node;
  DLINK_FOREACH(node, local_client_list.head)
    sendto_one_notice(node->data, &me, ":%s", buf);

  sendto_server(NULL, 0, 0, ":%s ERROR :%s", me.id, buf);

  ilog(LOG_TYPE_IRCD, "%s", buf);

  save_all_databases(NULL);

  close_fds();

  unlink(pidFileName);

  if (restart)
  {
    execv(SPATH, myargv);
    exit(EXIT_FAILURE);
  }
  else
    exit(EXIT_SUCCESS);
}
