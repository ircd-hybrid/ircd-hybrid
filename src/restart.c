/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
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
restart(const char *mesg)
{
  static int was_here = 0; /* redundant due to restarting flag below */

  if (was_here++)
    abort();

  server_die(mesg, 1);
}

void
server_die(const char *mesg, int rboot)
{
  char buffer[IRCD_BUFSIZE] = "";
  dlink_node *ptr = NULL;
  static int was_here = 0;

  if (rboot && was_here++)
    abort();

  if (EmptyString(mesg))
    snprintf(buffer, sizeof(buffer), "Server %s",
             rboot ? "Restarting" : "Terminating");
  else
    snprintf(buffer, sizeof(buffer), "Server %s: %s",
             rboot ? "Restarting" : "Terminating", mesg);

  DLINK_FOREACH(ptr, local_client_list.head)
    sendto_one_notice(ptr->data, &me, ":%s", buffer);

  sendto_server(NULL, NOCAPS, NOCAPS, ":%s ERROR :%s", ID(&me), buffer);

  ilog(LOG_TYPE_IRCD, "%s", buffer);

  save_all_databases(NULL);

  send_queued_all();
  close_fds(NULL);

  unlink(pidFileName);

  if (rboot)
  {
    execv(SPATH, myargv);
    exit(1);
  }
  else
    exit(0);
}
