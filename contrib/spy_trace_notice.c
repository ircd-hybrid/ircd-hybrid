/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  spy_trace_notice.c: Sends a notice when someone uses TRACE or LTRACE
 *
 *  Copyright (C) 2002 Hybrid Development Team
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

static struct Callback *trace_cb = NULL, *ltrace_cb = NULL;
static struct Callback *ctrace_cb = NULL, *etrace_cb = NULL;
static dlink_node *prev_trace, *prev_ltrace;
static dlink_node *prev_ctrace, *prev_etrace;

static void *show_trace(va_list);
static void *show_ltrace(va_list);
static void *show_ctrace(va_list);
static void *show_etrace(va_list);

void
_modinit(void)
{
  if ((trace_cb = find_callback("doing_trace")))
    prev_trace = install_hook(trace_cb, show_trace);

  if ((ltrace_cb = find_callback("doing_ltrace")))
    prev_ltrace = install_hook(ltrace_cb, show_ltrace);

  if ((ctrace_cb = find_callback("doing_ctrace")))
    prev_ctrace = install_hook(ctrace_cb, show_ctrace);

  if ((etrace_cb = find_callback("doing_etrace")))
    prev_etrace = install_hook(etrace_cb, show_etrace);
}

void
_moddeinit(void)
{
  if (trace_cb)
    uninstall_hook(trace_cb, show_trace);

  if (ltrace_cb)
    uninstall_hook(ltrace_cb, show_ltrace);

  if (ctrace_cb)
    uninstall_hook(ctrace_cb, show_ctrace);
}

const char *_version = "$Revision$";

static void *
show_trace(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);

  if (IsClient(source_p))
    sendto_realops_flags(UMODE_SPY, L_ALL,
                         "trace requested by %s (%s@%s) [%s]",
                         source_p->name, source_p->username,
                         source_p->host, source_p->servptr->name);

  return pass_callback(prev_trace, source_p, parc, parv);
}

static void *
show_ltrace(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);

  if (IsClient(source_p))
    sendto_realops_flags(UMODE_SPY, L_ALL,
                         "ltrace requested by %s (%s@%s) [%s]",
                         source_p->name, source_p->username,
                         source_p->host, source_p->servptr->name);

  return pass_callback(prev_ltrace, source_p, parc, parv);
}

static void *
show_ctrace(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);

  if (IsClient(source_p))
    sendto_realops_flags(UMODE_SPY, L_ALL,
                         "ctrace requested by %s (%s@%s) [%s]",
                         source_p->name, source_p->username,
                         source_p->host, source_p->servptr->name);

  return pass_callback(prev_ctrace, source_p, parc, parv);
}

static void *
show_etrace(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);

  if (IsClient(source_p))
    sendto_realops_flags(UMODE_SPY, L_ALL,
                         "etrace requested by %s (%s@%s) [%s]",
                         source_p->name, source_p->username,
                         source_p->host, source_p->servptr->name);

  return pass_callback(prev_etrace, source_p, parc, parv);
}
#endif
