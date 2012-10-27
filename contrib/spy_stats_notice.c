/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  spy_stats_notice.c: Sends a notice when someone uses STATS.
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
#ifndef STATIC_MODULES
#include "tools.h"
#include "modules.h"
#include "hook.h"
#include "client.h"
#include "ircd.h"
#include "send.h"

static struct Callback *stats_cb = NULL;
static dlink_node *prev_hook;

static void *show_stats(va_list);

void
_modinit(void)
{
  if ((stats_cb = find_callback("doing_stats")))
    prev_hook = install_hook(stats_cb, show_stats);
}

void
_moddeinit(void)
{
  if (stats_cb)
    uninstall_hook(stats_cb, show_stats);
}

const char *_version = "$Revision$";

/* show a stats request */
static void *
show_stats(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);
  char statchar;

  if (parc < 2)
    return NULL;  /* shouldn't happen */

  statchar = parv[1][0];
  if (statchar == 'L' || statchar == 'l')
  {
    if (parc > 2 && *parv[2])
      sendto_realops_flags(UMODE_SPY, L_ALL,
                           "STATS %c requested by %s (%s@%s) [%s] on %s",
			   statchar, source_p->name, source_p->username,
			   source_p->host, source_p->servptr->name, parv[2]);
    else
      sendto_realops_flags(UMODE_SPY, L_ALL,
                           "STATS %c requested by %s (%s@%s) [%s]",
                           statchar, source_p->name, source_p->username,
			   source_p->host, source_p->servptr->name);
  }
  else if (statchar != 'p')
    sendto_realops_flags(UMODE_SPY, L_ALL,
                         "STATS %c requested by %s (%s@%s) [%s]",
                         statchar, source_p->name, source_p->username,
                         source_p->host, source_p->servptr->name);

  return pass_callback(prev_hook, source_p, parc, parv);
}
#endif
