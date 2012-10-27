/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  spy_whois_notice.c: Sends a notice when someone uses WHOIS.
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
#include "hash.h"
#include "hook.h"
#include "client.h"
#include "ircd.h"
#include "send.h"

static struct Callback *whois_cb = NULL;
static dlink_node *prev_hook;

static void *show_notice(va_list);

void
_modinit(void)
{
  if ((whois_cb = find_callback("doing_whois")))
    prev_hook = install_hook(whois_cb, show_notice);
}

void
_moddeinit(void)
{
  if (whois_cb)
    uninstall_hook(whois_cb, show_notice);
}

const char *_version = "$Revision$";

/* show_notice
 *
 * inputs	- source_p, parc, parv
 * output	- inherited
 * side effects	- show a whois notice source_p does a /whois on client_p
 */
void *
show_notice(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);
  struct Client *target_p;

  target_p = parv[1] ? find_client(parv[1]) : NULL;

  if (target_p != NULL && target_p != source_p)
    if (MyClient(target_p) && IsOper(target_p) &&
        (target_p->umodes & UMODE_SPY))
    {
      sendto_one(target_p, ":%s NOTICE %s :*** Notice -- %s (%s@%s) is doing "
                 "a whois on you", me.name, target_p->name, source_p->name,
		 source_p->username, source_p->host);
    }

  return pass_callback(prev_hook, source_p, parc, parv);
}
#endif
