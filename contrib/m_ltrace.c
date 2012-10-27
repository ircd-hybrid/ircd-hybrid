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
#include "list.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_serv.h"
#include "conf.h"
#include "send.h"
#include "parse.h"
#include "modules.h"

static void do_ltrace(struct Client *, int, char *[]);
static void report_this_status(struct Client *, struct Client *, int);


static void
trace_get_dependent(int *const server,
                    int *const client, const struct Client *target_p)
{
  const dlink_node *ptr = NULL;

  (*server)++;
  (*client) += dlink_list_length(&target_p->serv->client_list);

  DLINK_FOREACH(ptr, target_p->serv->server_list.head)
    trace_get_dependent(server, client, ptr->data);
}

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
  const char *tname = NULL;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;
  sendto_one(source_p, form_str(RPL_ENDOFTRACE),
             me.name, source_p->name, tname);
}

/*
 * do_ltrace
 */
static void
do_ltrace(struct Client *source_p, int parc, char *parv[])
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

      if ((ac2ptr = hash_find_client(tname)) == NULL)
        DLINK_FOREACH(ptr, global_client_list.head)
        {
          ac2ptr = ptr->data;

          if (match(tname, ac2ptr->name))
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

  sendto_realops_flags(UMODE_SPY, L_ALL,
                       "LTRACE requested by %s (%s@%s) [%s]",
                       source_p->name, source_p->username,
                       source_p->host, source_p->servptr->name);

  doall = (parv[1] && (parc > 1)) ? match(tname, me.name) : 1;
  wilds = !parv[1] || strchr(tname, '*') || strchr(tname, '?');
  dow = wilds || doall;
  
  /* lusers cant issue ltrace.. */
  if (!dow)
  {
    const char* name;
    const char* class_name;

    target_p = hash_find_client(tname);

    if (target_p && IsClient(target_p)) 
    {
      name = get_client_name(target_p, HIDE_IP);
      class_name = get_client_class(target_p);

      if (HasUMode(target_p, UMODE_OPER))
      {
        if (ConfigFileEntry.hide_spoof_ips)
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, source_p->name, class_name, name, 
                     (IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost),
                     CurrentTime - target_p->localClient->lasttime,
                     CurrentTime - target_p->localClient->last_privmsg);
        else
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, source_p->name, class_name, name,
                     (IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost),
                     CurrentTime - target_p->localClient->lasttime,
                     CurrentTime - target_p->localClient->last_privmsg);
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

    if (!HasUMode(target_p, UMODE_OPER))
      continue;

    if (!doall && wilds && !match(tname, target_p->name))
      continue;

    if (!dow && irccmp(tname, target_p->name))
      continue;

    report_this_status(source_p, target_p, dow);
  }

  /* report all servers */
  DLINK_FOREACH(ptr, serv_list.head)
  {
    target_p = ptr->data;

    if (!doall && wilds && !match(tname, target_p->name))
      continue;
    if (!dow && irccmp(tname, target_p->name))
      continue;

    report_this_status(source_p, target_p, dow);
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
  if (!HasUMode(source_p, UMODE_OPER))
  {
    sendto_one(source_p, form_str(RPL_ENDOFTRACE), me.name, parv[0],
               parc > 1 ? parv[1] : me.name);
    return;
  }

  if (parc > 2)
    if (hunt_server(client_p, source_p, ":%s LTRACE %s :%s", 2, parc, parv))
      return;

  do_ltrace(source_p, parc, parv);
}

/*
 * report_this_status
 *
 * inputs	- pointer to client to report to
 * 		- pointer to client to report about
 * output	- counter of number of hits
 * side effects - NONE
 */
static void
report_this_status(struct Client *source_p, struct Client *target_p,
                   int dow)
{
  const char *name = NULL;
  const char *class_name = NULL;

  name = get_client_name(target_p, HIDE_IP);
  class_name = get_client_class(target_p);

  switch (target_p->status)
  {
    case STAT_CONNECTING:
      sendto_one(source_p, form_str(RPL_TRACECONNECTING), me.name,
                 source_p->name, class_name, 
                 HasUMode(source_p, UMODE_ADMIN) ? name : target_p->name);
      break;

    case STAT_HANDSHAKE:
      sendto_one(source_p, form_str(RPL_TRACEHANDSHAKE), me.name,
                 source_p->name, class_name, 
                 HasUMode(source_p, UMODE_ADMIN) ? name : target_p->name);
      break;

    case STAT_CLIENT:
      if (HasUMode(target_p, UMODE_ADMIN))
      {
        if (ConfigFileEntry.hide_spoof_ips)
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, source_p->name, class_name, name,
                     (IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost),
                     CurrentTime - target_p->localClient->lasttime,
                     CurrentTime - target_p->localClient->last_privmsg);
        else
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, source_p->name, class_name, name,
                     HasUMode(source_p, UMODE_ADMIN) ? target_p->sockhost :
                     (IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost),
                     CurrentTime - target_p->localClient->lasttime,
                     CurrentTime - target_p->localClient->last_privmsg);
      }
      else if (HasUMode(target_p, UMODE_OPER))
      {
        if (ConfigFileEntry.hide_spoof_ips)
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, source_p->name, class_name, name,
                     (IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost),
                     CurrentTime - target_p->localClient->lasttime,
                     CurrentTime - target_p->localClient->last_privmsg);
        else
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, source_p->name, class_name, name, 
                     (IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost),
                     CurrentTime - target_p->localClient->lasttime,
                     CurrentTime - target_p->localClient->last_privmsg);
      }
      break;

    case STAT_SERVER:
    {
      int clients = 0;
      int servers = 0;

      trace_get_dependent(&servers, &clients, target_p);

      if (!HasUMode(source_p, UMODE_ADMIN))
        name = get_client_name(target_p, MASK_IP);

      sendto_one(source_p, form_str(RPL_TRACESERVER),
                 me.name, source_p->name, class_name, servers,
                 clients, name, *(target_p->serv->by) ?
                 target_p->serv->by : "*", "*",
                 me.name, CurrentTime - target_p->localClient->lasttime);
      break;
    }

    case STAT_ME:
    case STAT_UNKNOWN:
      break;

    default: /* ...we actually shouldn't come here... --msa */
      sendto_one(source_p, form_str(RPL_TRACENEWTYPE), me.name,
                 source_p->name, name);
      break;
  }
}

static struct Message ltrace_msgtab = {
  "LTRACE", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_ltrace, mo_ltrace, m_ignore, mo_ltrace, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&ltrace_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&ltrace_msgtab);
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
