/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_gline.c: Votes towards globally banning a mask.
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
#include "tools.h"
#include "handlers.h"
#include "s_gline.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_misc.h"
#include "send.h"
#include "msg.h"
#include "fileio.h"
#include "s_serv.h"
#include "hash.h"
#include "parse.h"
#include "modules.h"
#include "list.h"
#include "s_log.h"

#define GLINE_NOT_PLACED     0
#ifdef GLINE_VOTING
#define GLINE_ALREADY_VOTED -1
#endif /* GLINE_VOTING */
#define GLINE_PLACED         1

extern dlink_list gdeny_items;

/* internal functions */
static void set_local_gline(const struct Client *,
                            const char *, const char *, const char *);

#ifdef GLINE_VOTING
static int check_majority_gline(const struct Client *,
				const char *, const char *, const char *);

static void add_new_majority_gline(const struct Client *,
                                   const char *, const char *, const char *);
#endif /* GLINE_VOTING */

static void do_sgline(struct Client *, struct Client *, int, char **, int);

static void me_gline(struct Client *, struct Client *, int, char **);
static void ms_gline(struct Client *, struct Client *, int, char **);
static void mo_gline(struct Client *, struct Client *, int, char **);
static void mo_ungline(struct Client *, struct Client *, int, char **);

/*
 * gline enforces 3 parameters to force operator to give a reason
 * a gline is not valid with "No reason"
 * -db
 */
struct Message gline_msgtab = {
  "GLINE", 0, 0, 3, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, ms_gline, me_gline, mo_gline, m_ignore}
};

struct Message ungline_msgtab = {
  "UNGLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_error, m_ignore, mo_ungline, m_ignore}
};
		
#ifndef STATIC_MODULES
void
_modinit(void)
{
    mod_add_cmd(&gline_msgtab);
    mod_add_cmd(&ungline_msgtab);
    add_capability("GLN", CAP_GLN, 1);
}

void
_moddeinit(void)
{
  mod_del_cmd(&gline_msgtab);
  mod_del_cmd(&ungline_msgtab);
  delete_capability("GLN");
}

const char *_version = "$Revision$";
#endif

/* mo_gline()
 *
 * inputs       - The usual for a m_ function
 * output       -
 * side effects -
 *
 * Place a G line if 3 opers agree on the identical user@host
 * 
 */
/* Allow this server to pass along GLINE if received and
 * GLINES is not defined.
 *
 */

static void
mo_gline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char *user = NULL;
  char *host = NULL;	     /* user and host of GLINE "victim" */
  char *reason = NULL;       /* reason for "victims" demise     */
  char *p;

  if (!ConfigFileEntry.glines)
  {
    sendto_one(source_p, ":%s NOTICE %s :GLINE disabled",
               me.name, source_p->name);
    return;
  }

  if (!IsOperGline(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "gline");
    return;
  }

  if (parse_aline("GLINE", source_p, parc, parv,
		  AWILD, &user, &host, NULL, NULL, &reason) < 0)
    return;

  if ((p = strchr(host, '/')) != NULL)
  {
    int bitlen = strtol(++p, NULL, 10);
    int min_bitlen = strchr(host, ':') ? ConfigFileEntry.gline_min_cidr6 :
                                         ConfigFileEntry.gline_min_cidr;
    if (bitlen < min_bitlen)
    {
      sendto_one(source_p, ":%s NOTICE %s :Cannot set G-Lines with CIDR length < %d",
                 me.name, source_p->name, min_bitlen);
      return;
    }
  }
  
#ifdef GLINE_VOTING
  /* If at least 3 opers agree this user should be G lined then do it */
  if (check_majority_gline(source_p, user, host, reason) ==
      GLINE_ALREADY_VOTED)
  {
    sendto_one(source_p,
               ":%s NOTICE %s :This server or oper has already voted",
               me.name, source_p->name);
    return;
  }

  /*
   * call these two functions first so the 'requesting' notice always comes
   * before the 'has triggered' notice.  -bill
   */
  sendto_realops_flags(UMODE_ALL, L_ALL,
                       "%s requesting G-Line for [%s@%s] [%s]",
                       get_oper_name(source_p),
                       user, host, reason);
  ilog(L_TRACE, "#gline for %s@%s [%s] requested by %s!%s@%s",
       user, host, reason, source_p->name, source_p->username,
       source_p->host);
#else
  set_local_gline(source_p, user, host, reason);
#endif /* GLINE_VOTING */
  
  /* 4 param version for hyb-7 servers */
  sendto_server(NULL, source_p, NULL, CAP_GLN|CAP_TS6, NOCAPS,
		LL_ICLIENT, ":%s GLINE %s %s :%s",
		ID(source_p), user, host, reason);
  sendto_server(NULL, source_p, NULL, CAP_GLN, CAP_TS6,
		LL_ICLIENT, ":%s GLINE %s %s :%s",
		source_p->name, user, host, reason);

  /* 8 param for hyb-6 */
  sendto_server(NULL, NULL, NULL, CAP_TS6, CAP_GLN, NOFLAGS,
		":%s GLINE %s %s %s %s %s %s :%s",
		ID(&me),
                ID(source_p), source_p->username,
		source_p->host, source_p->servptr->name, user, host,
		reason);
  sendto_server(NULL, NULL, NULL, NOCAPS, CAP_GLN|CAP_TS6, NOFLAGS,
		":%s GLINE %s %s %s %s %s %s :%s",
		me.name, source_p->name, source_p->username,
		source_p->host, source_p->servptr->name, user, host,
		reason);
}

/* ms_gline()
 * me_gline()
 * do_sgline()
 *
 * inputs       - The usual for a m_ function
 * output       -
 * side effects -
 *
 * Place a G line if 3 opers agree on the identical user@host
 * 
 * Allow this server to pass along GLINE if received and
 * GLINES is not defined.
 *
 * ENCAP'd GLINES are propagated by encap code.
 */

static void
ms_gline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  do_sgline(client_p, source_p, parc, parv, 1);
}

static void
me_gline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  do_sgline(client_p, source_p, parc, parv, 0);
}

static void
do_sgline(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[], int prop)
{
  const char *reason = NULL;      /* reason for "victims" demise       */
  char *user = NULL;
  char *host = NULL;              /* user and host of GLINE "victim"   */
  int var_offset, logged = 0;
  dlink_node *ptr;
  struct ConfItem *conf;
  struct AccessItem *aconf;

  /* hyb-7 style gline (post beta3) */
  if (parc == 4 && IsClient(source_p))
    var_offset = 0;
  /* or it's a hyb-6 style */
  else if (parc == 8 && IsServer(source_p))
  {
    var_offset = 4;

    /*
     * if we are dealing with an old style formatted gline,
     * the gline message is originating from the oper's server,
     * so we update source_p to point to the oper now, so that
     * logging works down the line.  -bill
     */
    if ((source_p = find_person(client_p, parv[1])) == NULL)
      return;

    if (irccmp(parv[2], source_p->username) != 0 ||
        irccmp(parv[3], source_p->host) != 0 ||
        irccmp(parv[4], source_p->servptr->name) != 0)
    {
      /*
       * at this point we know one of the parameters provided by
       * the h6 server was faulty.  bail out.
       */
      return;
    }
  }
  /* none of the above */
  else
    return;

  assert(source_p->servptr != NULL);

  user = parv[++var_offset];
  host = parv[++var_offset];
  reason = parv[++var_offset];

  var_offset = 0;

  DLINK_FOREACH(ptr, gdeny_items.head)
  {
    conf = ptr->data;
    aconf = (struct AccessItem *)map_to_conf(conf);

    if (match(conf->name, source_p->servptr->name) &&
        match(aconf->user, source_p->username) &&
        match(aconf->host, source_p->host))
    {
      var_offset = aconf->flags;
      break;
    }
  }

  if (prop && !(var_offset & GDENY_BLOCK))
  {
    sendto_server(client_p, source_p->servptr, NULL, CAP_GLN, NOCAPS, LL_ICLIENT,
                  ":%s GLINE %s %s :%s",
                  source_p->name, user, host, reason);
    /* hyb-6 version to the rest */
    sendto_server(client_p, NULL, NULL, NOCAPS, CAP_GLN, NOFLAGS,
                  ":%s GLINE %s %s %s %s %s %s :%s",
                  source_p->servptr->name,
                  source_p->name, source_p->username, source_p->host,
                  source_p->servptr->name,
                  user, host, reason);
  }
  else if (ConfigFileEntry.gline_logging & GDENY_BLOCK && ServerInfo.hub)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, "Blocked G-Line %s requested on [%s@%s] [%s]",
                         get_oper_name(source_p), user, host, reason);
    ilog(L_TRACE, "Blocked G-Line %s requested on [%s@%s] [%s]",
         get_oper_name(source_p), user, host, reason);
    logged = 1;
  }
    

  if (var_offset & GDENY_REJECT)
  {
    if (ConfigFileEntry.gline_logging & GDENY_REJECT && !logged)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, "Rejected G-Line %s requested on [%s@%s] [%s]",
                           get_oper_name(source_p), user, host, reason);
      ilog(L_TRACE, "Rejected G-Line %s requested on [%s@%s] [%s]",
           get_oper_name(source_p), user, host, reason);
    }
    return;
  }

  if (ConfigFileEntry.glines)
  {
    if (!valid_wild_card(source_p, YES, 2, user, host))
      return;

    if (IsClient(source_p))
    {
      const char *p = NULL;
      if ((p = strchr(host, '/')))
      {
        int bitlen = strtol(++p, NULL, 10);
        int min_bitlen = strchr(host, ':') ? ConfigFileEntry.gline_min_cidr6 :
                                             ConfigFileEntry.gline_min_cidr;

        if (bitlen < min_bitlen)
        {
          sendto_realops_flags(UMODE_ALL, L_ALL, "%s!%s@%s on %s is requesting "
                               "a GLINE with a CIDR mask < %d for [%s@%s] [%s]",
                               source_p->name, source_p->username, source_p->host,
                               source_p->servptr->name, min_bitlen, user, host, reason);
          return;
        }
      }
    }

#ifdef GLINE_VOTING
     /* If at least 3 opers agree this user should be G lined then do it */
     if (check_majority_gline(source_p, user, host, reason) ==
         GLINE_ALREADY_VOTED)
     {
       sendto_realops_flags(UMODE_ALL, L_ALL, "oper or server has already voted");
       return;
     }

     sendto_realops_flags(UMODE_ALL, L_ALL,
                          "%s requesting G-Line for [%s@%s] [%s]",
                          get_oper_name(source_p),
                          user, host, reason);
     ilog(L_TRACE, "#gline for %s@%s [%s] requested by %s",
          user, host, reason, get_oper_name(source_p));
#else 
     set_local_gline(source_p, user, host, reason);
#endif /* GLINE_VOTING */
  }
}

/* set_local_gline()
 *
 * inputs	- pointer to client struct of oper
 *		- pointer to victim user
 *		- pointer to victim host
 *		- pointer reason
 * output	- NONE
 * side effects	-
 */
static void
set_local_gline(const struct Client *source_p, const char *user,
                const char *host, const char *reason)
{
  char buffer[IRCD_BUFSIZE];
  struct ConfItem *conf;
  struct AccessItem *aconf;
  const char *current_date;
  time_t cur_time;

  set_time();
  cur_time = CurrentTime;

  current_date = smalldate(cur_time);
  conf = make_conf_item(GLINE_TYPE);
  aconf = (struct AccessItem *)map_to_conf(conf);

  ircsprintf(buffer, "%s (%s)", reason, current_date);
  DupString(aconf->reason, buffer);
  DupString(aconf->user, user);
  DupString(aconf->host, host);

  aconf->hold = CurrentTime + ConfigFileEntry.gline_time;
  add_temp_line(conf);

  sendto_realops_flags(UMODE_ALL, L_ALL,
                       "%s added G-Line for [%s@%s] [%s]",
                       get_oper_name(source_p),
                       aconf->user, aconf->host, aconf->reason);
  ilog(L_TRACE, "%s added G-Line for [%s@%s] [%s]",
       get_oper_name(source_p), aconf->user, aconf->host, aconf->reason);
  log_oper_action(LOG_GLINE_TYPE, source_p, "[%s@%s] [%s]\n",
		  aconf->user, aconf->host, aconf->reason);
  /* Now, activate gline against current online clients */
  rehashed_klines = 1;
}

#ifdef GLINE_VOTING
/* add_new_majority_gline()
 * 
 * inputs       - operator requesting gline
 * 		- username covered by the gline
 * 		- hostname covered by the gline
 * 		- reason for the gline
 * output       - NONE
 * side effects -
 * This function is called once a majority of opers
 * have agreed on a gline, and it can be placed. The
 * information about an operator being passed to us
 * happens to be the operator who pushed us over the
 * "majority" level needed. See check_majority_gline()
 * for more information.
 */
static void
add_new_majority_gline(const struct Client *source_p,
                       const char *user, const char *host, const char *reason)
{
  struct gline_pending *pending = MyMalloc(sizeof(struct gline_pending));

  strlcpy(pending->oper_nick1, source_p->name, sizeof(pending->oper_nick1));
  strlcpy(pending->oper_user1, source_p->username, sizeof(pending->oper_user1));
  strlcpy(pending->oper_host1, source_p->host, sizeof(pending->oper_host1));

  strlcpy(pending->oper_server1, source_p->servptr->name, sizeof(pending->oper_server1));

  strlcpy(pending->user, user, sizeof(pending->user));
  strlcpy(pending->host, host, sizeof(pending->host));
  strlcpy(pending->reason1, reason, sizeof(pending->reason1));

  pending->last_gline_time = CurrentTime;
  pending->time_request1   = CurrentTime;

  dlinkAdd(pending, &pending->node, &pending_glines);
}

/* check_majority_gline()
 *
 * inputs       - source, user, host, reason
 *
 * output       - one of three results
 *                
 * GLINE_ALREADY_VOTED	- returned if oper/server has already voted
 * GLINE_PLACED		- returned if this triggers a gline
 * GLINE_NOT_PLACED	- returned if not triggered
 *
 * Side effects -
 *      See if there is a majority agreement on a GLINE on the given user
 *      There must be at least 3 different opers agreeing on this GLINE
 *
 */
static int
check_majority_gline(const struct Client *source_p,
                     const char *user, const char *host, const char *reason)
{
  dlink_node *pending_node;
  struct gline_pending *gline_pending_ptr;

  /* if its already glined, why bother? :) -- fl_ */
  if (find_is_glined(host, user))
    return(GLINE_NOT_PLACED);

  /* special case condition where there are no pending glines */
  if (dlink_list_length(&pending_glines) == 0) /* first gline request placed */
  {
    add_new_majority_gline(source_p, user, host, reason);
    return(GLINE_NOT_PLACED);
  }

  DLINK_FOREACH(pending_node, pending_glines.head)
  {
    gline_pending_ptr = pending_node->data;

    if ((irccmp(gline_pending_ptr->user, user) == 0) &&
	(irccmp(gline_pending_ptr->host, host) == 0))
    {
      if (((irccmp(gline_pending_ptr->oper_user1, source_p->username) == 0) ||
           (irccmp(gline_pending_ptr->oper_host1, source_p->host) == 0)) ||
          (irccmp(gline_pending_ptr->oper_server1, source_p->servptr->name) == 0))
      {
	return(GLINE_ALREADY_VOTED);
      }

      if (gline_pending_ptr->oper_user2[0] != '\0')
      {
	/* if two other opers on two different servers have voted yes */

	if(((irccmp(gline_pending_ptr->oper_user2, source_p->username)==0) ||
	    (irccmp(gline_pending_ptr->oper_host2, source_p->host)==0)) ||
	   (irccmp(gline_pending_ptr->oper_server2, source_p->servptr->name)==0))
	{
	  return(GLINE_ALREADY_VOTED);
	}

	/* trigger the gline using the original reason --fl */
	set_local_gline(source_p, user, host, gline_pending_ptr->reason1);
	cleanup_glines(NULL);
	return(GLINE_PLACED);
      }
      else
      {
	strlcpy(gline_pending_ptr->oper_nick2, source_p->name,
	        sizeof(gline_pending_ptr->oper_nick2));
	strlcpy(gline_pending_ptr->oper_user2, source_p->username,
	        sizeof(gline_pending_ptr->oper_user2));
	strlcpy(gline_pending_ptr->oper_host2, source_p->host,
	        sizeof(gline_pending_ptr->oper_host2));
        strlcpy(gline_pending_ptr->reason2, reason,
                sizeof(gline_pending_ptr->reason2));
        strlcpy(gline_pending_ptr->oper_server2, source_p->servptr->name,
                sizeof(gline_pending_ptr->oper_server2));
	gline_pending_ptr->last_gline_time = CurrentTime;
	gline_pending_ptr->time_request2 = CurrentTime;
	return(GLINE_NOT_PLACED);
      }
    }
  }

  /* Didn't find this user@host gline in pending gline list
   * so add it.
   */
  add_new_majority_gline(source_p, user, host, reason);
  return(GLINE_NOT_PLACED);
}
#endif /* GLINE_VOTING */

static int
remove_gline_match(const char *user, const char *host)
{
  struct AccessItem *aconf;
  dlink_node *ptr = NULL;
  struct irc_ssaddr addr, caddr;
  int nm_t, cnm_t, bits, cbits;

  nm_t = parse_netmask(host, &addr, &bits);

  DLINK_FOREACH(ptr, temporary_glines.head)
  {
    aconf = map_to_conf(ptr->data);
    cnm_t = parse_netmask(aconf->host, &caddr, &cbits);

    if (cnm_t != nm_t || irccmp(user, aconf->user))
      continue;

    if ((nm_t == HM_HOST && !irccmp(aconf->host, host)) ||
        (nm_t == HM_IPV4 && bits == cbits && match_ipv4(&addr, &caddr, bits))
#ifdef IPV6
     || (nm_t == HM_IPV6 && bits == cbits && match_ipv6(&addr, &caddr, bits))
#endif
    )
    {
      dlinkDelete(ptr, &temporary_glines);
      delete_one_address_conf(aconf->host, aconf);
      return(1);
    }
  }

  return(0);
}

/*
** m_ungline
** added May 29th 2000 by Toby Verrall <toot@melnet.co.uk>
** added to hybrid-7 7/11/2000 --is
**
**      parv[0] = sender nick
**      parv[1] = gline to remove
*/
static void
mo_ungline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  char *user, *host;

  if (!ConfigFileEntry.glines)
  {
    sendto_one(source_p, ":%s NOTICE %s :UNGLINE disabled",
               me.name, source_p->name);
    return;
  }

  if (!IsOperUnkline(source_p) || !IsOperGline(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "gline");
    return;
  }

  if (parse_aline("UNGLINE", source_p, parc, parv,
		  0, &user, &host, NULL, NULL, NULL) < 0)
    return;

  if (remove_gline_match(user, host))
  {
    sendto_one(source_p, ":%s NOTICE %s :G-Line for [%s@%s] is removed",
               me.name, source_p->name, user, host);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the G-Line for: [%s@%s]",
                         get_oper_name(source_p), user, host);
    ilog(L_NOTICE, "%s removed G-Line for [%s@%s]",
         get_oper_name(source_p), user, host);
  }
  else
  {
    sendto_one(source_p, ":%s NOTICE %s :No G-Line for %s@%s",
               me.name, source_p->name, user, host);
  }
}
