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
#include "list.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_serv.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"
#include "conf_class.h"


static void report_this_status(struct Client *, struct Client *, int);

/*
 * do_etrace()
 */
static void
do_etrace(struct Client *source_p, int parc, char *parv[])
{
  const char *tname = NULL;
  struct Client *target_p = NULL;
  int wilds = 0;
  int do_all = 0;
  int full_etrace = 0;
  dlink_node *ptr;

  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                       "ETRACE requested by %s (%s@%s) [%s]",
                       source_p->name, source_p->username,
                       source_p->host, source_p->servptr->name);

  if (parc > 1)
  {
    if (irccmp(parv[1], "-full") == 0)
    {
      ++parv;
      --parc;
      full_etrace = 1;
    }
  }

  if (parc > 1)
  {
    tname = parv[1];

    if (tname != NULL)
      wilds = has_wildcards(tname);
    else
      tname = "*";
  }
  else
  {
    do_all = 1;
    tname = "*";
  }

  if (HasUMode(source_p, UMODE_CCONN_FULL))
    full_etrace = 1;

  if (!wilds && !do_all)
  {
    target_p = hash_find_client(tname);

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
      if (!match(tname, target_p->name))
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
  do_etrace(source_p, parc, parv);
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

  name = get_client_name(target_p, HIDE_IP);
  class_name = get_client_class(&target_p->localClient->confs);

  set_time();

  if (target_p->status == STAT_CLIENT)
  {
    if (full_etrace)
    {
      if (ConfigFileEntry.hide_spoof_ips)
	sendto_one(source_p, form_str(RPL_ETRACE_FULL),
		   me.name,
		   source_p->name,
		   HasUMode(target_p, UMODE_OPER) ? "Oper" : "User",
		   class_name,
		   target_p->name,
		   target_p->username,
		   target_p->host,
		   IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost,
		   IsIPSpoof(target_p) ? "<hidden>" : target_p->localClient->client_host,
		   IsIPSpoof(target_p) ? "<hidden>" : target_p->localClient->client_server,
		   target_p->info);
      else
        sendto_one(source_p, form_str(RPL_ETRACE_FULL),
		   me.name,
		   source_p->name, 
		   HasUMode(target_p, UMODE_OPER) ? "Oper" : "User", 
		   class_name,
		   target_p->name,
		   target_p->username,
		   target_p->host,
		   target_p->sockhost,
		   target_p->localClient->client_host,
		   target_p->localClient->client_server,
		   target_p->info);
    }
    else
    {
      if (ConfigFileEntry.hide_spoof_ips)
	sendto_one(source_p, form_str(RPL_ETRACE),
		   me.name,
		   source_p->name,
		   HasUMode(target_p, UMODE_OPER) ? "Oper" : "User",
		   class_name,
		   target_p->name,
		   target_p->username,
		   target_p->host,
		   IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost,
		   target_p->info);
      else
	sendto_one(source_p, form_str(RPL_ETRACE),
		   me.name,
		   source_p->name, 
		   HasUMode(target_p, UMODE_OPER) ? "Oper" : "User", 
		   class_name,
		   target_p->name,
		   target_p->username,
		   target_p->host,
		   target_p->sockhost,
		   target_p->info);
    }
  }
}

static struct Message etrace_msgtab = {
  "ETRACE", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_etrace, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&etrace_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&etrace_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
