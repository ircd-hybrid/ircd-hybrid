/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_who.c: Shows who is on a channel.
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
#include "channel.h"
#include "channel_mode.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"

static void who_global(struct Client *, char *, int);
static void do_who(struct Client *, struct Client *,
                   const char *, const char *);
static void do_who_on_channel(struct Client *, struct Channel *,
                              const char *, int, int);

/*
** m_who
**      parv[0] = sender prefix
**      parv[1] = nickname mask list
**      parv[2] = additional selection flag, only 'o' for now.
*/
static void
m_who(struct Client *client_p, struct Client *source_p,
      int parc, char *parv[])
{
  struct Client *target_p;
  char *mask = parv[1];
  dlink_node *lp;
  int server_oper = parc > 2 ? (*parv[2] == 'o') : 0; /* Show OPERS only */
  struct Channel *chptr;

  /* See if mask is there, collapse it or return if not there */
  if (EmptyString(mask))
  {
    who_global(source_p, mask, server_oper);
    sendto_one(source_p, form_str(RPL_ENDOFWHO),
               me.name, source_p->name, "*");
    return;
  }

  /* mask isn't NULL at this point. repeat after me... -db */
  collapse(mask);

  /* '/who *' */
  if (!strcmp(mask, "*"))
  {
    if ((lp = source_p->channel.head) != NULL)
    {
      struct Channel *mychannel = ((struct Membership *)lp->data)->chptr;
      do_who_on_channel(source_p, mychannel, mychannel->chname, 1,
                        server_oper);
    }

    sendto_one(source_p, form_str(RPL_ENDOFWHO),
               me.name, source_p->name, "*");
    return;
  }

  /* '/who #some_channel' */
  if (IsChanPrefix(*mask))
  {
    /* List all users on a given channel */
    if ((chptr = hash_find_channel(mask)) != NULL)
    {
      if (IsMember(source_p, chptr))
        do_who_on_channel(source_p, chptr, chptr->chname, 1, server_oper);
      else if (!SecretChannel(chptr))
        do_who_on_channel(source_p, chptr, chptr->chname, 0, server_oper);
    }

    sendto_one(source_p, form_str(RPL_ENDOFWHO),
               me.name, source_p->name, mask);
    return;
  }

  /* '/who nick' */
  if (((target_p = hash_find_client(mask)) != NULL) &&
      IsClient(target_p) && (!server_oper || HasUMode(target_p, UMODE_OPER)))
  {
    DLINK_FOREACH(lp, target_p->channel.head)
    {
      chptr = ((struct Membership *) lp->data)->chptr;
      if (PubChannel(chptr) || IsMember(source_p, chptr))
        break;
    }

    if (lp != NULL)
      do_who(source_p, target_p, chptr->chname,
             get_member_status(lp->data, !!HasCap(source_p, CAP_MULTI_PREFIX)));
    else
      do_who(source_p, target_p, NULL, "");

    sendto_one(source_p, form_str(RPL_ENDOFWHO),
               me.name, source_p->name, mask);
    return;
  }

  /* '/who 0' */
  if (!strcmp(mask, "0"))
    who_global(source_p, NULL, server_oper);
  else
    who_global(source_p, mask, server_oper);

  /* Wasn't a nick, wasn't a channel, wasn't a '*' so ... */
  sendto_one(source_p, form_str(RPL_ENDOFWHO),
             me.name, source_p->name, mask);
}

/* who_common_channel
 * inputs	- pointer to client requesting who
 * 		- pointer to channel member chain.
 *		- char * mask to match
 *		- int if oper on a server or not
 *		- pointer to int maxmatches
 * output	- NONE
 * side effects - lists matching clients on specified channel,
 * 		  marks matched clients.
 *
 */
static void
who_common_channel(struct Client *source_p, struct Channel *chptr,
                   char *mask, int server_oper, int *maxmatches)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    struct Client *target_p = ((struct Membership *)ptr->data)->client_p;

    if (!HasUMode(target_p, UMODE_INVISIBLE) || HasFlag(target_p, FLAGS_MARK))
      continue;

    if (server_oper)
      if (!HasUMode(target_p, UMODE_OPER) ||
          (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER)))
        continue;

    AddFlag(target_p, FLAGS_MARK);

    assert(target_p->servptr != NULL);

    if ((mask == NULL) ||
      match(mask, target_p->name) || match(mask, target_p->username) ||
      match(mask, target_p->host) || 
      ((!ConfigServerHide.hide_servers || HasUMode(source_p, UMODE_OPER)) &&
       match(mask, target_p->servptr->name)) ||
      match(mask, target_p->info))
    {
      do_who(source_p, target_p, NULL, "");

      if (*maxmatches > 0)
      {
        if (--(*maxmatches) == 0)
          return;
      }
    }
  }
}

/* who_global()
 *
 * inputs	- pointer to client requesting who
 *		- char * mask to match
 *		- int if oper on a server or not
 * output	- NONE
 * side effects - do a global scan of all clients looking for match
 *		  this is slightly expensive on EFnet ...
 */
static void
who_global(struct Client *source_p, char *mask, int server_oper)
{
  struct Channel *chptr;
  struct Client *target_p;
  dlink_node *lp;
  dlink_node *lp_next;
  dlink_node *gcptr;
  dlink_node *gcptr_next;
  int maxmatches = 500;
  static time_t last_used = 0;

  if (!HasUMode(source_p, UMODE_OPER))
  {
    if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
    {
      /* safe enough to give this on a local connect only */
      sendto_one(source_p, form_str(RPL_LOAD2HI), me.name, source_p->name);
      return;
    }

    last_used = CurrentTime;
  }

  /* first, list all matching invisible clients on common channels */
  DLINK_FOREACH_SAFE(lp, lp_next, source_p->channel.head)
  {
    chptr = ((struct Membership *)lp->data)->chptr;
    who_common_channel(source_p, chptr, mask, server_oper, &maxmatches);
  }

  /* second, list all matching visible clients */
  DLINK_FOREACH_SAFE(gcptr, gcptr_next, global_client_list.head)
  {
    target_p = gcptr->data;

    if (!IsClient(target_p))
      continue;

    if (HasUMode(target_p, UMODE_INVISIBLE))
    {
      DelFlag(target_p, FLAGS_MARK);
      continue;
    }

    if (server_oper)
      if (!HasUMode(target_p, UMODE_OPER) ||
          (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER)))
        continue;

    assert(target_p->servptr != NULL);

    if (!mask ||
        match(mask, target_p->name) || match(mask, target_p->username) ||
        match(mask, target_p->host) || match(mask, target_p->servptr->name) ||
        match(mask, target_p->info))
    {
      do_who(source_p, target_p, NULL, "");

      if (maxmatches > 0)
      {
        if (--maxmatches == 0)
          return;
      }
    }
  }
}

/* do_who_on_channel()
 *
 * inputs	- pointer to client requesting who
 *		- pointer to channel to do who on
 *		- The "real name" of this channel
 *		- int if source_p is a server oper or not
 *		- int if client is member or not
 *		- int server_op flag
 * output	- NONE
 * side effects - do a who on given channel
 */
static void
do_who_on_channel(struct Client *source_p, struct Channel *chptr,
                  const char *chname, int member, int server_oper)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;
  struct Client *target_p;
  struct Membership *ms;

  DLINK_FOREACH_SAFE(ptr, ptr_next, chptr->members.head)
  {
    ms = ptr->data;
    target_p = ms->client_p;

    if (member || !HasUMode(target_p, UMODE_INVISIBLE))
    {
      if (server_oper)
        if (!HasUMode(target_p, UMODE_OPER) ||
            (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER)))
          continue;
      do_who(source_p, target_p, chname, get_member_status(ms, !!HasCap(source_p, CAP_MULTI_PREFIX)));
    }
  }
}

/* do_who()
 *
 * inputs	- pointer to client requesting who
 *		- pointer to client to do who on
 *		- The reported name
 *		- channel flags
 * output	- NONE
 * side effects - do a who on given person
 */
static void
do_who(struct Client *source_p, struct Client *target_p,
       const char *chname, const char *op_flags)
{
  char status[7]; /* G*@%+\0 */

  if (HasUMode(source_p, UMODE_OPER))
    snprintf(status, sizeof(status), "%c%s%s", target_p->away[0] ? 'G' : 'H',
             HasUMode(target_p, UMODE_OPER) ? "*" : "", op_flags);
  else
    snprintf(status, sizeof(status), "%c%s%s", target_p->away[0] ? 'G' : 'H',
             HasUMode(target_p, UMODE_OPER) &&
             !HasUMode(target_p, UMODE_HIDDEN) ? "*" : "", op_flags);

  if (ConfigServerHide.hide_servers)
  {
    sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
	       (chname) ? (chname) : "*",
               target_p->username, target_p->host,
	       HasUMode(source_p, UMODE_OPER) ? target_p->servptr->name : "*",
	       target_p->name, status, 0, target_p->info);
  }
  else
  {
    sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
	       (chname) ? (chname) : "*", target_p->username,
	       target_p->host, target_p->servptr->name, target_p->name,
	       status, target_p->hopcount, target_p->info);
  }
}

static struct Message who_msgtab = {
  "WHO", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_who, m_ignore, m_ignore, m_who, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&who_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&who_msgtab);
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
