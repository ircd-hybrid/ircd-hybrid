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

static void mo_testline(struct Client *, struct Client *, int, char *[]);
static void mo_testgecos(struct Client *, struct Client *, int, char *[]);

struct Message testline_msgtab = {
  "TESTLINE", 0, 0, 0, 0, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_testline, m_ignore }
};

struct Message testgecos_msgtab = {
  "TESTGECOS", 0, 0, 0, 0, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_testgecos, m_ignore }
};
 
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
  /* IRCD_BUFSIZE to allow things like *u*s*e*r*n*a*m*e* etc. */
  char given_name[IRCD_BUFSIZE];
  char given_host[IRCD_BUFSIZE];
  char parv1_copy[IRCD_BUFSIZE];
  struct ConfItem *conf;
  struct AccessItem *aconf;
  struct irc_ssaddr ip;
  int host_mask;
  int t;
  int matches = 0;
  char userhost[HOSTLEN + USERLEN + 2];
  struct split_nuh_item nuh;

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, ":%s NOTICE %s :usage: user@host|ip [password]",
               me.name, source_p->name);
    return;
  }

  if (IsChanPrefix(*parv[1]))    /* Might be channel resv */
  {
    const struct ResvChannel *chptr = NULL;

    if ((chptr = match_find_resv(parv[1])))
    {
      sendto_one(source_p, form_str(RPL_TESTLINE),
                 me.name, source_p->name, 'Q', 0, chptr->name, 
                 chptr->reason ? chptr->reason : "No reason", "");
      return;
    }
  }

  strlcpy(parv1_copy, parv[1], sizeof(parv1_copy));

  nuh.nuhmask  = parv[1];
  nuh.nickptr  = NULL;
  nuh.userptr  = given_name;
  nuh.hostptr  = given_host;

  nuh.nicksize = 0;
  nuh.usersize = sizeof(given_name);
  nuh.hostsize = sizeof(given_host);

  split_nuh(&nuh);

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
      ++matches;
      if (aconf->status & CONF_EXEMPTDLINE)
        sendto_one(source_p,
                   ":%s NOTICE %s :Exempt D-line host [%s] reason [%s]",
                   me.name, source_p->name, aconf->host, aconf->reason);
      else
        sendto_one(source_p, form_str(RPL_TESTLINE),
                   me.name, source_p->name,
                   IsConfTemporary(aconf) ? 'd' : 'D',
                   IsConfTemporary(aconf) ? ((aconf->hold - CurrentTime) / 60)
                   : 0L,
                   aconf->host, aconf->reason, aconf->oper_reason);
    }
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
    snprintf(userhost, sizeof(userhost), "%s@%s", aconf->user, aconf->host);

    if (aconf->status & CONF_CLIENT)
    {
      sendto_one(source_p, form_str(RPL_TESTLINE),
                 me.name, source_p->name, 'I', 0L, userhost,
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
                 userhost, aconf->reason? aconf->reason : "No reason",
                 aconf->oper_reason ? aconf->oper_reason : "");
      ++matches;
    }
  }

  conf = find_matching_name_conf(NRESV_TYPE, given_name, NULL, NULL, 0);

  if (conf != NULL)
  {
    const struct MatchItem *mconf = map_to_conf(conf);

    sendto_one(source_p, form_str(RPL_TESTLINE),
               me.name, source_p->name, 'Q', 0L,
               conf->name, 
               mconf->reason ? mconf->reason : "No reason",
               mconf->oper_reason ? mconf->oper_reason : "");
    ++matches;
  }

  if (matches == 0)
    sendto_one(source_p, form_str(RPL_NOTESTLINE),
               me.name, source_p->name, parv1_copy);
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

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, ":%s NOTICE %s :usage: gecos",
               me.name, source_p->name);
    return;
  }

  if ((conf = find_matching_name_conf(XLINE_TYPE, parv[1], NULL, NULL, 0)))
  {
    const struct MatchItem *xconf = map_to_conf(conf);
    sendto_one(source_p, form_str(RPL_TESTLINE),
               me.name, source_p->name, 'X', 0L,
               conf->name, xconf->reason ? xconf->reason : "X-lined",
               xconf->oper_reason ? xconf->oper_reason : "");
  }
  else
    sendto_one(source_p, form_str(RPL_NOTESTLINE),
               me.name, source_p->name, parv[1]);
}
