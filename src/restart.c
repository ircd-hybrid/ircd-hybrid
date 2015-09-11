/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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

/*! \file restart.c
 * \brief Functions to allow the ircd to restart.
 * \version $Id$
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
#include "memory.h"
#include "conf_db.h"


void
server_die(const char *message, int action)
{
  char buffer[IRCD_BUFSIZE] = "";
  dlink_node *node = NULL;
  static int was_here = 0;

  if (action == SERVER_RESTART && was_here++)
    abort();

  if (EmptyString(message))
    snprintf(buffer, sizeof(buffer), "Server %s",
             action == SERVER_RESTART ? "Restarting" : "Terminating");
  else
    snprintf(buffer, sizeof(buffer), "Server %s: %s",
             action == SERVER_RESTART ? "Restarting" : "Terminating", message);

  DLINK_FOREACH(node, local_client_list.head)
    sendto_one_notice(node->data, &me, ":%s", buffer);

  sendto_server(NULL, 0, 0, ":%s ERROR :%s", me.id, buffer);

  ilog(LOG_TYPE_IRCD, "%s", buffer);

  save_all_databases(NULL);

  send_queued_all();
  close_fds(NULL);

  unlink(pidFileName);

  if (action == SERVER_RESTART)
  {
    execv(SPATH, myargv);
    exit(EXIT_FAILURE);
  }
  else
    exit(EXIT_SUCCESS);
}
