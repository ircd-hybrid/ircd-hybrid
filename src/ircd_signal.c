/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd_signal.c: responsible for ircd's signal handling
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "ircd_signal.h"
#include "ircd.h"         /* dorehash */
#include "restart.h"      /* server_die */
#include "memory.h"
#include "s_bsd.h"

/*
 * sigterm_handler - exit the server
 */
static void 
sigterm_handler(int sig)  
{
  server_die("received signal SIGTERM", 0);
}

/* 
 * sighup_handler - reread the server configuration
 */
static void 
sighup_handler(int sig)
{
  dorehash = 1;
}

/*
 * sigusr1_handler - reread the motd file
 */
static void
sigusr1_handler(int sig)
{
  doremotd = 1;
}

/*
 * 
 * inputs	- nothing
 * output	- nothing
 * side effects - Reaps zombies periodically
 * -AndroSyn
 */
static void
sigchld_handler(int sig)
{
  int status, errno_save = errno;

  while (waitpid(-1, &status, WNOHANG) > 0)
    ;
  errno = errno_save;
}

/*
 * sigint_handler - restart the server
 */
static void 
sigint_handler(int sig)
{
  server_die("SIGINT received", !server_state.foreground);
}

/*
 * setup_signals - initialize signal handlers for server
 */
void 
setup_signals(void)
{
  struct sigaction act;

  act.sa_flags = 0;
  act.sa_handler = SIG_IGN;

  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask, SIGPIPE);
  sigaddset(&act.sa_mask, SIGALRM);
  sigaction(SIGALRM, &act, 0);
#ifdef SIGTRAP
  sigaddset(&act.sa_mask, SIGTRAP);
#endif
#ifdef SIGXFSZ
  sigaddset(&act.sa_mask, SIGXFSZ);
  sigaction(SIGXFSZ, &act, 0);
#endif

#ifdef SIGWINCH
  sigaddset(&act.sa_mask, SIGWINCH);
  sigaction(SIGWINCH, &act, 0);
#endif
  sigaction(SIGPIPE, &act, 0);
#ifdef SIGTRAP
  sigaction(SIGTRAP, &act, 0);
#endif

  act.sa_handler = sighup_handler;
  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask, SIGHUP);
  sigaction(SIGHUP, &act, 0);

  act.sa_handler = sigint_handler;
  sigaddset(&act.sa_mask, SIGINT);
  sigaction(SIGINT, &act, 0);

  act.sa_handler = sigterm_handler;
  sigaddset(&act.sa_mask, SIGTERM);
  sigaction(SIGTERM, &act, 0);

  act.sa_handler = sigusr1_handler;
  sigaddset(&act.sa_mask, SIGUSR1);
  sigaction(SIGUSR1, &act, 0);

  act.sa_handler = sigchld_handler;
  sigaddset(&act.sa_mask, SIGCHLD);
  sigaction(SIGCHLD, &act, 0);
}
