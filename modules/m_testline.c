/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_testline.c: Tests a hostmask to see what will happen to it.
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
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "ircd_defs.h"
#include "ircd.h"
#include "restart.h"
#include "s_conf.h"
#include "send.h"
#include "msg.h"
#include "hostmask.h"
#include "numeric.h"
#include "parse.h"
#include "resv.h"
#include "hash.h"
#include "modules.h"

static void mo_testline(struct Client*, struct Client*, int, char**);
static void mo_testgecos(struct Client*, struct Client*, int, char**);

struct Message testline_msgtab = {
  "TESTLINE", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_testline, m_ignore}
};

struct Message testgecos_msgtab = {
  "TESTGECOS", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_testgecos, m_ignore}
};
 
#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&testline_msgtab);
  mod_add_cmd(&testgecos_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&testline_msgtab);
  mod_del_cmd(&testgecos_msgtab);
}
 
const char *_version = "$Revision$";
#endif

/* mo_testline()
 *
 * inputs       - pointer to physical connection request is coming from
 *              - pointer to source connection request is coming from
 *              - parc arg count
 *              - parv actual arguments   
 *   
 * output       - NONE
 * side effects - command to test I/K lines on server
 *   
 * i.e. /quote testline user@host,ip [password]
 *
 */
static void
mo_testline(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  char *orig_parv1;
  char *given_name;
  char *given_host = NULL;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  struct irc_ssaddr ip;
  int host_mask;
  int t;
  int matches = 0;
  char userhost[HOSTLEN + USERLEN + 2];

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, ":%s NOTICE %s :usage: user@host|ip [password]",
               me.name, source_p->name);
    return;
  }

  given_name = parv[1];

  if (IsChanPrefix(*given_name))	/* Might be channel resv */
  {
    struct ResvChannel *chptr;
    
    chptr = match_find_resv(given_name);
    if (chptr != NULL)
    {
      sendto_one(source_p,
		 form_str(RPL_TESTLINE),
		 me.name, source_p->name,
		 'Q', 0, chptr->name, 
		 chptr->reason ? chptr->reason : "No reason", "" );
      return;
    }
  }

  DupString(orig_parv1,parv[1]);
  split_nuh(given_name, NULL, &given_name, &given_host);

  t = parse_netmask(given_host, &ip, &host_mask);

  if (t != HM_HOST)
  {
    aconf = find_dline_conf(&ip, 
#ifdef IPV6 
			    (t == HM_IPV6) ? AF_INET6 : AF_INET
#else
			    AF_INET
#endif
			    );
    if (aconf != NULL)
    {
      conf = unmap_conf_item(aconf);

      if (aconf->status & CONF_EXEMPTDLINE)
      {
	sendto_one(source_p,
		   ":%s NOTICE %s :Exempt D-line host [%s] reason [%s]",
		   me.name, source_p->name, aconf->host, aconf->reason);
	++matches;
      }
      else
      {
	sendto_one(source_p,
		   form_str(RPL_TESTLINE),
		   me.name, source_p->name,
		   IsConfTemporary(aconf) ? 'd' : 'D',
		   IsConfTemporary(aconf) ? ((aconf->hold - CurrentTime) / 60)
		   : 0L,
		   aconf->host, aconf->reason, aconf->oper_reason);
	++matches;
      }
    }
  }

  aconf = find_kline_conf(given_host, given_name, &ip, t);
  if ((aconf != NULL) && (aconf->status & CONF_KILL))
  {
    snprintf(userhost, sizeof(userhost), "%s@%s", aconf->user, aconf->host);
    sendto_one(source_p, form_str(RPL_TESTLINE),
	       me.name, source_p->name,
	       IsConfTemporary(aconf) ? 'k' : 'K',
	       IsConfTemporary(aconf) ? ((aconf->hold - CurrentTime) / 60)
	       : 0L,
	       userhost, 
	       aconf->passwd ? aconf->passwd : "No reason",
	       aconf->oper_reason ? aconf->oper_reason : "");
    ++matches;
  }


  if (t != HM_HOST)
    aconf = find_address_conf(given_host, given_name, &ip, 
#ifdef IPV6
                              (t == HM_IPV6) ? AF_INET6 : AF_INET,
#else
                              AF_INET,
#endif
                              parv[2]);
  else
    aconf = find_address_conf(given_host, given_name, NULL, 0, parv[2]);
                 
  if (aconf != NULL)
  {
    conf = unmap_conf_item(aconf);

    snprintf(userhost, sizeof(userhost), "%s@%s", aconf->user, aconf->host);

    if (aconf->status & CONF_CLIENT)
    {
      sendto_one(source_p, form_str(RPL_TESTLINE),
		 me.name, source_p->name,
		 'I', 0L, userhost,
		 aconf->class_ptr ? aconf->class_ptr->name : "<default>", "");
      ++matches;
    }
    else if (aconf->status & CONF_KILL)
    {
      sendto_one(source_p, form_str(RPL_TESTLINE),
		 me.name, source_p->name,
		 IsConfTemporary(aconf) ? 'k' : 'K',
		 IsConfTemporary(aconf) ? ((aconf->hold - CurrentTime) / 60)
		 : 0L,
		 userhost, aconf->passwd ? aconf->passwd : "No reason",
		 aconf->oper_reason ? aconf->oper_reason : "");
      ++matches;
    }
  }

  conf = find_matching_name_conf(NRESV_TYPE, given_name, NULL, NULL, 0);

  if (conf != NULL)
  {
    struct MatchItem *mconf;
    mconf = (struct MatchItem *)map_to_conf(conf);

    sendto_one(source_p, form_str(RPL_TESTLINE),
	       me.name, source_p->name,
	       'Q', 0L,
	       conf->name, 
	       mconf->reason ? mconf->reason : "No reason",
	       mconf->oper_reason ? mconf->oper_reason : "");
    ++matches;
  }

  if (matches == 0)
    sendto_one(source_p, form_str(RPL_NOTESTLINE),
	       me.name, source_p->name, orig_parv1);

  MyFree(given_host);
  MyFree(given_name);
  MyFree(orig_parv1);
}

/* mo_testgecos()
 *
 * inputs       - pointer to physical connection request is coming from
 *              - pointer to source connection request is coming from
 *              - parc arg count
 *              - parv actual arguments   
 *   
 * output       - always 0
 * side effects - command to test X lines on server
 *   
 * i.e. /quote testgecos gecos
 *
 */
static void
mo_testgecos(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  struct ConfItem *conf = NULL;
  struct MatchItem *xconf = NULL;
  const char *gecos_name = NULL;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, ":%s NOTICE %s :usage: gecos",
               me.name, source_p->name);
    return;
  }

  gecos_name = parv[1];

  if ((conf = find_matching_name_conf(XLINE_TYPE, gecos_name, NULL, NULL, 0))
      != NULL)
  {
    xconf = (struct MatchItem *)map_to_conf(conf);
    sendto_one(source_p, form_str(RPL_TESTLINE),
	       me.name, source_p->name, 'X', 0L,
	       conf->name, xconf->reason ? xconf->reason : "X-lined",
	       xconf->oper_reason ? xconf->oper_reason : "");
  }
  else
    sendto_one(source_p, form_str(RPL_NOTESTLINE),
	       me.name, source_p->name, parv[1]);
}
