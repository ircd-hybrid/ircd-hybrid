/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  spy_info_notice.c: Sends a notice when someone uses INFO.
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

static struct Callback *info_cb = NULL;
static dlink_node *prev_hook;

static void *show_info(va_list args);

void
_modinit(void)
{
  if ((info_cb = find_callback("doing_info")))
    prev_hook = install_hook(info_cb, show_info);
}

void
_moddeinit(void)
{
  if (info_cb)
    uninstall_hook(info_cb, show_info);
}

const char *_version = "$Revision$";

static void *
show_info(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);

  if (IsClient(source_p))
    sendto_realops_flags(UMODE_SPY, L_ALL,
                         "info requested by %s (%s@%s) [%s]",
                         source_p->name, source_p->username,
                         source_p->host, source_p->servptr->name);

  return pass_callback(prev_hook, source_p, parc, parv);
}
#endif
