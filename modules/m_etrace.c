/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_etrace.c: Traces a path to a client/server.
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
#include "handlers.h"
#include "tools.h"
#include "hook.h"
#include "client.h"
#include "hash.h"
#include "common.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_conf.h"
#include "irc_getnameinfo.h"

#define FORM_STR_RPL_ETRACE	 ":%s 709 %s %s %s %s %s %s %s :%s"
#define FORM_STR_RPL_ETRACE_FULL ":%s 708 %s %s %s %s %s %s %s %s %s :%s"

static void do_etrace(struct Client *, int, char **);
static void mo_etrace(struct Client *, struct Client *, int, char *[]);

struct Message etrace_msgtab = {
  "ETRACE", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_etrace, m_ignore}
};

#ifndef STATIC_MODULES
const char *_version = "$Revision$";
static struct Callback *etrace_cb;

static void *
va_etrace(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);

  do_etrace(source_p, parc, parv);
  return NULL;
}

void
_modinit(void)
{
  etrace_cb = register_callback("doing_etrace", va_etrace);
  mod_add_cmd(&etrace_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&etrace_msgtab);
  uninstall_hook(etrace_cb, va_etrace);
}
#endif

static void report_this_status(struct Client *, struct Client *, int);

/*
 * do_etrace()
 */
static void
do_etrace(struct Client *source_p, int parc, char **parv)
{
  const char *tname = NULL;
  struct Client *target_p = NULL;
  int wilds = 0;
  int do_all = 0;
  int full_etrace = 0;
  dlink_node *ptr;

  if (parc > 1)
  {
    if (irccmp(parv[1], "-full") == 0)
    {
      parv++;
      parc--;
      full_etrace = 1;
    }
  }

  if (parc > 1)
  {
    tname = parv[1];

    if (tname != NULL)
      wilds = strchr(tname, '*') || strchr(tname, '?');
    else
      tname = "*";
  }
  else
  {
    do_all = 1;
    tname = "*";
  }

  if (IsFull(source_p))
    full_etrace = 1;

  if (!wilds && !do_all)
  {
    target_p = find_client(tname);

    if (target_p && MyClient(target_p))
      report_this_status(source_p, target_p, full_etrace);
      
    sendto_one(source_p, form_str(RPL_ENDOFTRACE), me.name, 
	       source_p->name, tname);
    return;
  }

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    target_p = ptr->data;

    if (wilds)
    {
      if (match(tname, target_p->name) || match(target_p->name, tname))
	report_this_status(source_p, target_p, full_etrace);
    }
    else
      report_this_status(source_p, target_p, full_etrace);
  }

  sendto_one(source_p, form_str(RPL_ENDOFTRACE), me.name,
	     source_p->name, tname);
}

/* mo_etrace()
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void
mo_etrace(struct Client *client_p, struct Client *source_p,
	  int parc, char *parv[])
{
#ifdef STATIC_MODULES
  do_etrace(source_p, parc, parv);
#else
  execute_callback(etrace_cb, source_p, parc, parv);
#endif
}

/* report_this_status()
 *
 * inputs	- pointer to client to report to
 * 		- pointer to client to report about
 *		- flag full etrace or not
 * output	- NONE
 * side effects - NONE
 */
static void
report_this_status(struct Client *source_p, struct Client *target_p,
		   int full_etrace)
{
  const char *name;
  const char *class_name;
  char ip[HOSTIPLEN];

  /* Should this be sockhost? - stu */
  irc_getnameinfo((struct sockaddr*)&target_p->localClient->ip, 
        target_p->localClient->ip.ss_len, ip, HOSTIPLEN, NULL, 0, 
        NI_NUMERICHOST);

  name = get_client_name(target_p, HIDE_IP);
  class_name = get_client_class(target_p);

  set_time();

  if (target_p->status == STAT_CLIENT)
  {
    if (full_etrace)
    {
      if (ConfigFileEntry.hide_spoof_ips)
	sendto_one(source_p, FORM_STR_RPL_ETRACE_FULL,
		   me.name,
		   source_p->name,
		   IsOper(target_p) ? "Oper" : "User",
		   class_name,
		   target_p->name,
		   target_p->username,
		   target_p->host,
		   IsIPSpoof(target_p) ? "255.255.255.255" : ip,
		   IsIPSpoof(target_p) ? "<hidden>" : target_p->client_host,
		   IsIPSpoof(target_p) ? "<hidden>" : target_p->client_server,
		   target_p->info);
      else
        sendto_one(source_p, FORM_STR_RPL_ETRACE_FULL,
		   me.name,
		   source_p->name, 
		   IsOper(target_p) ? "Oper" : "User", 
		   class_name,
		   target_p->name,
		   target_p->username,
		   target_p->host,
		   ip,
		   target_p->client_host,
		   target_p->client_server,
		   target_p->info);
    }
    else
    {
      if (ConfigFileEntry.hide_spoof_ips)
	sendto_one(source_p, FORM_STR_RPL_ETRACE,
		   me.name,
		   source_p->name,
		   IsOper(target_p) ? "Oper" : "User",
		   class_name,
		   target_p->name,
		   target_p->username,
		   target_p->host,
		   IsIPSpoof(target_p) ? "255.255.255.255" : ip,
		   target_p->info);
      else
	sendto_one(source_p, FORM_STR_RPL_ETRACE,
		   me.name,
		   source_p->name, 
		   IsOper(target_p) ? "Oper" : "User", 
		   class_name,
		   target_p->name,
		   target_p->username,
		   target_p->host,
		   ip,
		   target_p->info);
    }
  }
}
