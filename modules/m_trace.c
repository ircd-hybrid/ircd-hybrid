/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_trace.c: Traces a path to a client/server.
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

static void m_trace(struct Client *, struct Client *, int, char **);
static void ms_trace(struct Client*, struct Client*, int, char**);
static void mo_trace(struct Client*, struct Client*, int, char**);
static void do_actual_trace(struct Client *, int, char **);

struct Message trace_msgtab = {
  "TRACE", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_trace, ms_trace, m_ignore, mo_trace, m_ignore}
};

#ifndef STATIC_MODULES
const char *_version = "$Revision$";
static struct Callback *trace_cb;

static void *
va_actual_trace(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);

  do_actual_trace(source_p, parc, parv);
  return NULL;
}

void
_modinit(void)
{
  trace_cb = register_callback("doing_trace", va_actual_trace);
  mod_add_cmd(&trace_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&trace_msgtab);
  uninstall_hook(trace_cb, va_actual_trace);
}
#endif

static int report_this_status(struct Client *source_p, struct Client *target_p,
			      int dow, int link_u_p, int link_u_s);

/*
 * m_trace()
 *
 *	parv[0] = sender prefix
 *	parv[1] = target client/server to trace
 */
static void
m_trace(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  const char *tname;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;

  sendto_one(source_p, form_str(RPL_ENDOFTRACE),
             me.name, source_p->name, tname);
}


/* mo_trace()
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void
mo_trace(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  dlink_node *ptr;
  const char *tname;
  const char *from, *to;

  if (parc > 2)
    if (hunt_server(client_p, source_p, ":%s TRACE %s :%s", 2, parc, parv))
      return;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;

  if (!MyConnect(source_p) && IsCapable(source_p->from, CAP_TS6) && HasID(source_p))
  {
    from = me.id;
    to = source_p->id;
  }
  else
  {
    from = me.name;
    to = source_p->name;
  }

  switch (hunt_server(client_p, source_p, ":%s TRACE :%s", 1, parc, parv))
  {
    case HUNTED_PASS: /* note: gets here only if parv[1] exists */
    {
      struct Client *ac2ptr = NULL;

      if ((ac2ptr = find_client(tname)) == NULL)
      {
        DLINK_FOREACH(ptr, global_client_list.head)
        {
          ac2ptr = ptr->data;

          if (match(tname, ac2ptr->name) || match(ac2ptr->name, tname))
            break;
          else
            ac2ptr = NULL;
        }
     }

     if (ac2ptr != NULL)
        sendto_one(source_p, form_str(RPL_TRACELINK), from, to,
                   ircd_version, tname, ac2ptr->from->name);
      else
        sendto_one(source_p, form_str(RPL_TRACELINK), from, to,
                   ircd_version, tname, "ac2ptr_is_NULL!!");
      return;
    }
    case HUNTED_ISME:
#ifdef STATIC_MODULES
      do_actual_trace(source_p, parc, parv);
#else
      execute_callback(trace_cb, source_p, parc, parv);
#endif
      break;
    default:
      return;
  }
}

static void
do_actual_trace(struct Client *source_p, int parc, char **parv)
{
  struct Client *target_p = NULL;
  struct ConfItem *conf;
  struct ClassItem *cltmp;
  int doall = 0;
  int cnt = 0, wilds, dow;
  dlink_node *ptr;
  const char *from, *to, *tname;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;

  if (!MyConnect(source_p) && IsCapable(source_p->from, CAP_TS6) && HasID(source_p))
  {
    from = me.id;
    to = source_p->id;
  }
  else
  {
    from = me.name;
    to = source_p->name;
  }

  if (match(tname, me.name))
    doall = TRUE;
  else if (!MyClient(source_p) && !strcmp(tname, me.id))
  {
    doall = TRUE;
    tname = me.name;
  }

  wilds = !parv[1] || strchr(tname, '*') || strchr(tname, '?');
  dow = wilds || doall;

  set_time();
  if (!IsOper(source_p) || !dow) /* non-oper traces must be full nicks */
                              /* lets also do this for opers tracing nicks */
  {
    const char *name;
    const char *class_name;
    char ipaddr[HOSTIPLEN];

    target_p = find_client(tname);
      
    if (target_p && IsClient(target_p)) 
    {
      name = get_client_name(target_p, HIDE_IP);
      /* should we not use sockhost here? - stu */
      irc_getnameinfo((struct sockaddr*)&target_p->localClient->ip,
		      target_p->localClient->ip.ss_len, ipaddr, HOSTIPLEN, NULL, 0,
		      NI_NUMERICHOST);

      class_name = get_client_class(target_p);

      if (IsOper(target_p))
      {
        sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                   from, to, class_name, name, 
                   IsIPSpoof(target_p) ? "255.255.255.255" : ipaddr,
                   CurrentTime - target_p->lasttime,
                   CurrentTime - target_p->localClient->last);
      }
      else
      {
        sendto_one(source_p,form_str(RPL_TRACEUSER),
                   from, to, class_name, name, 
		   IsIPSpoof(target_p) ? "255.255.255.255" : ipaddr,
                   CurrentTime - target_p->lasttime,
                   CurrentTime - target_p->localClient->last);
      }
    }
      
    sendto_one(source_p, form_str(RPL_ENDOFTRACE),
               from, to, tname);
    return;
  }

  /* report all direct connections */
  DLINK_FOREACH(ptr, local_client_list.head)
  {
    target_p = ptr->data;

    if (IsInvisible(target_p) && dow &&
	!(MyConnect(source_p) && IsOper(source_p)) &&
	!IsOper(target_p) && (target_p != source_p))
      continue;
    if (!doall && wilds && !match(tname, target_p->name))
      continue;
    if (!dow && irccmp(tname, target_p->name))
      continue;

    cnt = report_this_status(source_p, target_p, dow, 0, 0);
  }

  DLINK_FOREACH(ptr, serv_list.head)
  {
    target_p = ptr->data;

    if (!doall && wilds && !match(tname, target_p->name))
      continue;
    if (!dow && irccmp(tname, target_p->name))
      continue;

    cnt = report_this_status(source_p, target_p, dow,
      target_p->serv->dep_users, target_p->serv->dep_servers);
  }

  /* This section is to report the unknowns */
  DLINK_FOREACH(ptr, unknown_list.head)
  {
    target_p = ptr->data;

    if (!doall && wilds && !match(tname, target_p->name))
      continue;
    if (!dow && irccmp(tname, target_p->name))
      continue;

    cnt = report_this_status(source_p, target_p, dow, 0, 0);
  }

  DLINK_FOREACH(ptr, class_items.head)
  {
    conf = ptr->data;
    cltmp = (struct ClassItem *)map_to_conf(conf);
    if (CurrUserCount(cltmp) > 0)
      sendto_one(source_p, form_str(RPL_TRACECLASS),
		 from, to, conf->name, CurrUserCount(cltmp));
  }

  sendto_one(source_p, form_str(RPL_ENDOFTRACE), from, to, tname);
}


/*
** ms_trace
**      parv[0] = sender prefix
**      parv[1] = servername
*/
static void
ms_trace(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (hunt_server(client_p, source_p, ":%s TRACE %s :%s", 2, parc, parv))
    return;

  if (IsOper(source_p))
    mo_trace(client_p, source_p, parc, parv);
}

/* report_this_status()
 *
 * inputs	- pointer to client to report to
 * 		- pointer to client to report about
 * output	- counter of number of hits
 * side effects - NONE
 */
static int
report_this_status(struct Client *source_p, struct Client *target_p,
                   int dow, int link_u_p, int link_s_p)
{
  const char *name;
  const char *class_name;
  const char *from, *to;
  char ip[HOSTIPLEN];
  int cnt = 0;

  if (!MyConnect(source_p) && IsCapable(source_p->from, CAP_TS6) && HasID(source_p))
  {
    from = me.id;
    to = source_p->id;
  }
  else
  {
    from = me.name;
    to = source_p->name;
  }

  /* Should this be sockhost? - stu */
  irc_getnameinfo((struct sockaddr*)&target_p->localClient->ip, 
        target_p->localClient->ip.ss_len, ip, HOSTIPLEN, NULL, 0, 
        NI_NUMERICHOST);
  name = get_client_name(target_p, HIDE_IP);
  class_name = get_client_class(target_p);

  set_time();

  switch(target_p->status)
  {
    case STAT_CONNECTING:
      sendto_one(source_p, form_str(RPL_TRACECONNECTING),
                 from, to, class_name, 
		 IsOperAdmin(source_p) ? name : target_p->name);
		   
      cnt++;
      break;
    case STAT_HANDSHAKE:
      sendto_one(source_p, form_str(RPL_TRACEHANDSHAKE),
                 from, to, class_name, 
                 IsOperAdmin(source_p) ? name : target_p->name);
		   
      cnt++;
      break;
    case STAT_ME:
      break;
    case STAT_UNKNOWN:
      /* added time -Taner */
      sendto_one(source_p, form_str(RPL_TRACEUNKNOWN),
		 from, to, class_name, name, ip,
		 target_p->firsttime ? CurrentTime - target_p->firsttime : -1);
      cnt++;
      break;
    case STAT_CLIENT:
      /* Only opers see users if there is a wildcard
       * but anyone can see all the opers.
       */
      if ((IsOper(source_p) &&
	   (MyClient(source_p) || !(dow && IsInvisible(target_p))))
	  || !dow || IsOper(target_p))
	{
          if (IsAdmin(target_p) && !ConfigFileEntry.hide_spoof_ips)
	    sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                       from, to, class_name, name,
                       IsOperAdmin(source_p) ? ip : "255.255.255.255",
                       CurrentTime - target_p->lasttime,
                       CurrentTime - target_p->localClient->last);
		       
	  else if (IsOper(target_p))
          {
	    if (ConfigFileEntry.hide_spoof_ips)
	      sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
		         from, to, class_name, name, 
		         IsIPSpoof(target_p) ? "255.255.255.255" : ip,
		         CurrentTime - target_p->lasttime,
		         CurrentTime - target_p->localClient->last);
	    else
              sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                         from, to, class_name, name,
                         MyOper(source_p) ? ip :
                         (IsIPSpoof(target_p) ? "255.255.255.255" : ip),
                         CurrentTime - target_p->lasttime,
                         CurrentTime - target_p->localClient->last);
	  }		       
	  else
          {
	    const char *format_str=NULL;
	    if (IsOper(source_p) && IsCaptured(target_p))
	      format_str = form_str(RPL_TRACECAPTURED);
	    else
	      format_str = form_str(RPL_TRACEUSER);

            if (ConfigFileEntry.hide_spoof_ips)
	      sendto_one(source_p, format_str,
		         from, to, class_name, name,
                         IsIPSpoof(target_p) ? "255.255.255.255" : ip,
		         CurrentTime - target_p->lasttime,
		         CurrentTime - target_p->localClient->last);
	    else
              sendto_one(source_p, format_str,
                         from, to, class_name, name,
                         MyOper(source_p) ? ip :
                         (IsIPSpoof(target_p) ? "255.255.255.255" : ip),
                         CurrentTime - target_p->lasttime,
                         CurrentTime - target_p->localClient->last);
	  }
	  cnt++;
	}
      break;
    case STAT_SERVER:
      if(!IsOperAdmin(source_p))
        name = get_client_name(target_p, MASK_IP);

      sendto_one(source_p, form_str(RPL_TRACESERVER),
		 from, to, class_name, link_s_p,
		 link_u_p, name, *(target_p->serv->by) ?
		 target_p->serv->by : "*", "*",
		 me.name, CurrentTime - target_p->lasttime);
      cnt++;
      break;
      
    default: /* ...we actually shouldn't come here... --msa */
      sendto_one(source_p, form_str(RPL_TRACENEWTYPE),
		 from, to, name);
      cnt++;
      break;
  }

  return cnt;
}
