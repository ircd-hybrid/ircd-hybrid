/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 */

/*! \file m_trace.c
 * \brief Includes required functions for processing the TRACE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "server.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"
#include "conf_class.h"


static void do_actual_trace(struct Client *, int, char *[]);
static void report_this_status(struct Client *, struct Client *, int);

static void
trace_get_dependent(unsigned int *const server,
                    unsigned int *const client, const struct Client *target_p)
{
  const dlink_node *ptr = NULL;

  (*server)++;
  (*client) += dlink_list_length(&target_p->serv->client_list);

  DLINK_FOREACH(ptr, target_p->serv->server_list.head)
    trace_get_dependent(server, client, ptr->data);
}

/*
 * m_trace()
 *
 *	parv[0] = command
 *	parv[1] = target client/server to trace
 */
static int
m_trace(struct Client *source_p, int parc, char *parv[])
{
  const char *tname = NULL;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;

  sendto_one_numeric(source_p, &me, RPL_ENDOFTRACE, tname);
  return 0;
}

/* mo_trace()
 *      parv[0] = command
 *      parv[1] = servername
 */
static int
mo_trace(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *ptr = NULL;
  const char *tname = NULL;

  if (parc > 2)
    if (hunt_server(source_p, ":%s TRACE %s :%s", 2, parc, parv) != HUNTED_ISME)
      return 0;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;

  switch (hunt_server(source_p, ":%s TRACE :%s", 1, parc, parv))
  {
    case HUNTED_PASS: /* note: gets here only if parv[1] exists */
    {
      struct Client *ac2ptr = NULL;

      if ((ac2ptr = hash_find_client(tname)) == NULL)
      {
        DLINK_FOREACH(ptr, global_client_list.head)
        {
          ac2ptr = ptr->data;

          if (!match(tname, ac2ptr->name))
            break;
          else
            ac2ptr = NULL;
        }
     }

      if (ac2ptr)
        sendto_one_numeric(source_p, &me, RPL_TRACELINK,
                           ircd_version, tname, ac2ptr->from->name);
      else
        sendto_one_numeric(source_p, &me, RPL_TRACELINK,
                           ircd_version, tname, "ac2ptr_is_NULL!!");
      return 0;
    }

    case HUNTED_ISME:
      do_actual_trace(source_p, parc, parv);
      break;
    default:
      return 0;
  }

  return 0;
}

/*
** ms_trace
**      parv[0] = command
**      parv[1] = servername
*/
static int
ms_trace(struct Client *source_p, int parc, char *parv[])
{
  if (hunt_server(source_p, ":%s TRACE %s :%s",
                  2, parc, parv) != HUNTED_ISME)
    return 0;

  if (HasUMode(source_p, UMODE_OPER))
    return mo_trace(source_p, parc, parv);
  return 0;
}

static void
do_actual_trace(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  int doall = 0;
  int wilds, dow;
  dlink_node *ptr;
  const char *tname;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;

  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                       "TRACE requested by %s (%s@%s) [%s]",
                       source_p->name, source_p->username,
                       source_p->host, source_p->servptr->name);

  if (!match(tname, me.name))
    doall = 1;
  else if (!MyClient(source_p) && !strcmp(tname, me.id))
  {
    doall = 1;
    tname = me.name;
  }

  wilds = !parv[1] || has_wildcards(tname);
  dow = wilds || doall;

  set_time();
  if (!HasUMode(source_p, UMODE_OPER) || !dow) /* non-oper traces must be full nicks */
                              /* lets also do this for opers tracing nicks */
  {
    const char *name;
    target_p = hash_find_client(tname);

    if (target_p && IsClient(target_p))
    {
      name = get_client_name(target_p, HIDE_IP);

      if (HasUMode(target_p, UMODE_OPER))
      {
        sendto_one_numeric(source_p, &me, RPL_TRACEOPERATOR,
                   get_client_class(&target_p->localClient->confs), name,
                   IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost,
                   CurrentTime - target_p->localClient->lasttime,
                   idle_time_get(source_p, target_p));
      }
      else
      {
        sendto_one_numeric(source_p, &me, RPL_TRACEUSER,
                   get_client_class(&target_p->localClient->confs), name,
                   IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost,
                   CurrentTime - target_p->localClient->lasttime,
                   idle_time_get(source_p, target_p));
      }
    }

    sendto_one_numeric(source_p, &me, RPL_ENDOFTRACE, tname);
    return;
  }

  /* report all direct connections */
  DLINK_FOREACH(ptr, local_client_list.head)
  {
    target_p = ptr->data;

    if (HasUMode(target_p, UMODE_INVISIBLE) && dow &&
        !(MyConnect(source_p) && HasUMode(source_p, UMODE_OPER)) &&
        !HasUMode(target_p, UMODE_OPER) && (target_p != source_p))
      continue;
    if (!doall && wilds && match(tname, target_p->name))
      continue;
    if (!dow && irccmp(tname, target_p->name))
      continue;

    report_this_status(source_p, target_p, dow);
  }

  DLINK_FOREACH(ptr, serv_list.head)
  {
    target_p = ptr->data;

    if (!doall && wilds && match(tname, target_p->name))
      continue;
    if (!dow && irccmp(tname, target_p->name))
      continue;

    report_this_status(source_p, target_p, dow);
  }

  /* This section is to report the unknowns */
  DLINK_FOREACH(ptr, unknown_list.head)
  {
    target_p = ptr->data;

    if (!doall && wilds && match(tname, target_p->name))
      continue;
    if (!dow && irccmp(tname, target_p->name))
      continue;

    report_this_status(source_p, target_p, dow);
  }

  DLINK_FOREACH(ptr, class_get_list()->head)
  {
    const struct ClassItem *class = ptr->data;

    if (class->ref_count > 0)
      sendto_one_numeric(source_p, &me, RPL_TRACECLASS, class->name, class->ref_count);
  }

  sendto_one_numeric(source_p, &me, RPL_ENDOFTRACE, tname);
}

/* report_this_status()
 *
 * inputs	- pointer to client to report to
 * 		- pointer to client to report about
 * output	- counter of number of hits
 * side effects - NONE
 */
static void
report_this_status(struct Client *source_p, struct Client *target_p, int dow)
{
  const char *name;
  const char *class_name;

  name = get_client_name(target_p, HIDE_IP);
  class_name = get_client_class(&target_p->localClient->confs);

  set_time();

  switch (target_p->status)
  {
    case STAT_CONNECTING:
      sendto_one_numeric(source_p, &me, RPL_TRACECONNECTING, class_name,
                 HasUMode(source_p, UMODE_ADMIN) ? name : target_p->name);
      break;
    case STAT_HANDSHAKE:
      sendto_one_numeric(source_p, &me, RPL_TRACEHANDSHAKE, class_name,
                 HasUMode(source_p, UMODE_ADMIN) ? name : target_p->name);
      break;
    case STAT_ME:
      break;
    case STAT_UNKNOWN:
      /* added time -Taner */
      sendto_one_numeric(source_p, &me, RPL_TRACEUNKNOWN, class_name,
                 name, target_p->sockhost,
                 CurrentTime - target_p->localClient->firsttime);
      break;
    case STAT_CLIENT:
      /*
       * Only opers see users if there is a wildcard
       * but anyone can see all the opers.
       */
      if ((HasUMode(source_p, UMODE_OPER) &&
           (MyClient(source_p) || !(dow && HasUMode(target_p, UMODE_INVISIBLE))))
          || !dow || HasUMode(target_p, UMODE_OPER))
        {
          if (HasUMode(target_p, UMODE_ADMIN) && !ConfigFileEntry.hide_spoof_ips)
            sendto_one_numeric(source_p, &me, RPL_TRACEOPERATOR, class_name, name,
                       HasUMode(source_p, UMODE_ADMIN) ? target_p->sockhost : "255.255.255.255",
                       CurrentTime - target_p->localClient->lasttime,
                       idle_time_get(source_p, target_p));

          else if (HasUMode(target_p, UMODE_OPER))
          {
            if (ConfigFileEntry.hide_spoof_ips)
              sendto_one_numeric(source_p, &me, RPL_TRACEOPERATOR, class_name, name,
                         IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost,
                         CurrentTime - target_p->localClient->lasttime,
                         idle_time_get(source_p, target_p));
            else
              sendto_one_numeric(source_p, &me, RPL_TRACEOPERATOR, class_name, name,
                         MyOper(source_p) ? target_p->sockhost :
                         (IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost),
                         CurrentTime - target_p->localClient->lasttime,
                         idle_time_get(source_p, target_p));
          }
          else
          {
            if (ConfigFileEntry.hide_spoof_ips)
              sendto_one_numeric(source_p, &me, RPL_TRACEUSER, class_name, name,
                         IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost,
                         CurrentTime - target_p->localClient->lasttime,
                         idle_time_get(source_p, target_p));
            else
              sendto_one_numeric(source_p, &me, RPL_TRACEUSER, class_name, name,
                         MyOper(source_p) ? target_p->sockhost :
                         (IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost),
                         CurrentTime - target_p->localClient->lasttime,
                         idle_time_get(source_p, target_p));
          }
        }
      break;
    case STAT_SERVER:
    {
      unsigned int clients = 0;
      unsigned int servers = 0;

      trace_get_dependent(&servers, &clients, target_p);

      if (!HasUMode(source_p, UMODE_ADMIN))
        name = get_client_name(target_p, MASK_IP);

      sendto_one_numeric(source_p, &me, RPL_TRACESERVER, class_name, servers,
                 clients, name, *(target_p->serv->by) ?
                 target_p->serv->by : "*", "*",
                 me.name, CurrentTime - target_p->localClient->lasttime);
      break;
    }

    default: /* ...we actually shouldn't come here... --msa */
      sendto_one_numeric(source_p, &me, RPL_TRACENEWTYPE, name);
      break;
  }
}

static struct Message trace_msgtab =
{
  "TRACE", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_trace, ms_trace, m_ignore, mo_trace, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&trace_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&trace_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
