/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_ltrace.c: Traces a path to a client/server.
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
#include "handlers.h"
#include "tools.h"
#include "hook.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_serv.h"
#include "s_conf.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "irc_getnameinfo.h"

static void do_ltrace(struct Client *, int, char **);
static void m_ltrace(struct Client *, struct Client *, int, char **);
static void mo_ltrace(struct Client *, struct Client *, int, char **);

struct Message ltrace_msgtab = {
  "LTRACE", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_ltrace, mo_ltrace, m_ignore, mo_ltrace, m_ignore}
};

#ifndef STATIC_MODULES
const char *_version = "$Revision$";
static struct Callback *ltrace_cb;

static void *
va_ltrace(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);

  do_ltrace(source_p, parc, parv);
  return NULL;
}

void
_modinit(void)
{
  ltrace_cb = register_callback("doing_ltrace", va_ltrace);
  mod_add_cmd(&ltrace_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&ltrace_msgtab);
  uninstall_hook(ltrace_cb, va_ltrace);
}
#endif

static int report_this_status(struct Client *source_p, struct Client *target_p,int dow,
                              int link_u_p, int link_u_s);

/*
 * m_ltrace()
 *
 *	parv[0] = sender prefix
 *	parv[1] = target client/server to trace
 */
static void
m_ltrace(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char *tname;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;
  sendto_one(source_p, form_str(RPL_ENDOFTRACE),
             me.name, parv[0], tname);
}

/*
 * do_ltrace
 */
static void
do_ltrace(struct Client *source_p, int parc, char **parv)
{
  struct Client *target_p = NULL;
  int   doall;
  int   wilds, dow;
  dlink_node *ptr;
  char *looking_for = parv[0];
  char *tname = parc > 1 ? parv[1] : me.name;

  switch (hunt_server(source_p->from, source_p, ":%s LTRACE :%s", 1,parc,parv))
  {
    case HUNTED_PASS: /* note: gets here only if parv[1] exists */
    {
      struct Client *ac2ptr = NULL;

      if ((ac2ptr = find_client(tname)) == NULL)
        DLINK_FOREACH(ptr, global_client_list.head)
        {
          ac2ptr = ptr->data;

          if (match(tname, ac2ptr->name) || match(ac2ptr->name, tname))
            break;
          else
            ac2ptr = NULL;
        }

      if (ac2ptr != NULL)
        sendto_one(source_p, form_str(RPL_TRACELINK), me.name, looking_for,
                   ircd_version, tname, ac2ptr->from->name);
      else
        sendto_one(source_p, form_str(RPL_TRACELINK), me.name, looking_for,
                   ircd_version, tname, "ac2ptr_is_NULL!!");
      return;
    }
    case HUNTED_ISME:
      break;
    default:
      return;
  }

  doall = (parv[1] && (parc > 1)) ? match(tname, me.name): TRUE;
  wilds = !parv[1] || strchr(tname, '*') || strchr(tname, '?');
  dow = wilds || doall;
  
  /* lusers cant issue ltrace.. */
  if (!dow)
  {
    const char* name;
    const char* class_name;
    char ipaddr[HOSTIPLEN];

    target_p = find_client(tname);

    if (target_p && IsClient(target_p)) 
    {
      name = get_client_name(target_p, HIDE_IP);
      /* Should this be sockhost? - stu */
      irc_getnameinfo((struct sockaddr*)&target_p->localClient->ip,
                  target_p->localClient->ip.ss_len, ipaddr,
                  HOSTIPLEN, NULL, 0, NI_NUMERICHOST);
      class_name = get_client_class(target_p);

      if (IsOper(target_p))
      {
        if (ConfigFileEntry.hide_spoof_ips)
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, source_p->name, class_name, name, 
                     (IsIPSpoof(target_p) ? "255.255.255.255" : ipaddr),
                     CurrentTime - target_p->lasttime,
                     CurrentTime - target_p->localClient->last);
        else
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, source_p->name, class_name, name,
                     (IsIPSpoof(target_p) ? "255.255.255.255" : ipaddr),
                     CurrentTime - target_p->lasttime,
                     CurrentTime - target_p->localClient->last);
      }
    }

    sendto_one(source_p, form_str(RPL_ENDOFTRACE),
               me.name, source_p->name, tname);
    return;
  }

  /* report all opers */
  DLINK_FOREACH(ptr, local_client_list.head)
  {
    target_p = ptr->data;

    if (!IsOper(target_p))
      continue;

    if (!doall && wilds && !match(tname, target_p->name))
      continue;

    if (!dow && irccmp(tname, target_p->name))
      continue;

    report_this_status(source_p, target_p, dow, 0, 0);
  }

  /* report all servers */
  DLINK_FOREACH(ptr, serv_list.head)
  {
    target_p = ptr->data;

    if (!doall && wilds && !match(tname, target_p->name))
      continue;
    if (!dow && irccmp(tname, target_p->name))
      continue;

    report_this_status(source_p, target_p, dow, target_p->serv->dep_users,
                       target_p->serv->dep_servers);
  }

  sendto_one(source_p, form_str(RPL_ENDOFTRACE), me.name, parv[0], tname);
}

/*
 * mo_ltrace
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void
mo_ltrace(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  if (!IsOper(source_p))
  {
    sendto_one(source_p, form_str(RPL_ENDOFTRACE), me.name, parv[0],
               parc > 1 ? parv[1] : me.name);
    return;
  }

  if (parc > 2)
    if (hunt_server(client_p, source_p, ":%s LTRACE %s :%s", 2, parc, parv))
      return;

#ifdef STATIC_MODULES
  do_ltrace(source_p, parc, parv);
#else
  execute_callback(ltrace_cb, source_p, parc, parv);
#endif
}

/*
 * report_this_status
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
  const char *name = NULL;
  const char *class_name = NULL;
  char ip[HOSTIPLEN];

  /* Should this be sockhost? - stu */
  irc_getnameinfo((struct sockaddr *)&target_p->localClient->ip,
              target_p->localClient->ip.ss_len, ip,
              HOSTIPLEN, NULL, 0, NI_NUMERICHOST);

  name = get_client_name(target_p, HIDE_IP);
  class_name = get_client_class(target_p);

  switch (target_p->status)
  {
    case STAT_CONNECTING:
      sendto_one(source_p, form_str(RPL_TRACECONNECTING), me.name,
                 source_p->name, class_name, 
                 IsAdmin(source_p) ? name : target_p->name);
      break;

    case STAT_HANDSHAKE:
      sendto_one(source_p, form_str(RPL_TRACEHANDSHAKE), me.name,
                 source_p->name, class_name, 
                 IsAdmin(source_p) ? name : target_p->name);
      break;

    case STAT_CLIENT:
      if (IsAdmin(target_p))
      {
        if (ConfigFileEntry.hide_spoof_ips)
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, source_p->name, class_name, name,
                     (IsIPSpoof(target_p) ? "255.255.255.255" : ip),
                     CurrentTime - target_p->lasttime,
                     CurrentTime - target_p->localClient->last);
        else
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, source_p->name, class_name, name,
                     IsAdmin(source_p) ? ip :
                     (IsIPSpoof(target_p) ? "255.255.255.255" : ip),
                     CurrentTime - target_p->lasttime,
                     CurrentTime - target_p->localClient->last);
      }
      else if (IsOper(target_p))
      {
        if (ConfigFileEntry.hide_spoof_ips)
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, source_p->name, class_name, name,
                     (IsIPSpoof(target_p) ? "255.255.255.255" : ip),
                     CurrentTime - target_p->lasttime,
                     CurrentTime - target_p->localClient->last);
        else
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, source_p->name, class_name, name, 
                     (IsIPSpoof(target_p) ? "255.255.255.255" : ip),
                     CurrentTime - target_p->lasttime,
                     CurrentTime - target_p->localClient->last);
      }
      break;

    case STAT_SERVER:
      if(!IsAdmin(source_p))
        name = get_client_name(target_p, MASK_IP);

      sendto_one(source_p, form_str(RPL_TRACESERVER),
                 me.name, source_p->name, class_name, link_s_p,
                 link_u_p, name, *(target_p->serv->by) ?
                 target_p->serv->by : "*", "*",
                 me.name, CurrentTime - target_p->lasttime);
      break;

    case STAT_ME:
    case STAT_UNKNOWN:
      break;

    default: /* ...we actually shouldn't come here... --msa */
      sendto_one(source_p, form_str(RPL_TRACENEWTYPE), me.name,
                 source_p->name, name);
      break;
  }

  return 0;
}
