/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_whois.c: Shows who a user is.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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
#include "channel.h"
#include "channel_mode.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "s_misc.h"
#include "s_serv.h"
#include "send.h"
#include "irc_string.h"
#include "parse.h"
#include "modules.h"


static void do_whois(struct Client *, int, char *[]);
static int single_whois(struct Client *, struct Client *);
static void whois_person(struct Client *, struct Client *);
static int global_whois(struct Client *, const char *);


/*
** m_whois
**      parv[0] = sender prefix
**      parv[1] = nickname masklist
*/
static void
m_whois(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  static time_t last_used = 0;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NONICKNAMEGIVEN),
               me.name, source_p->name);
    return;
  }

  if (parc > 2 && !EmptyString(parv[2]))
  {
    /* seeing as this is going across servers, we should limit it */
    if ((last_used + ConfigFileEntry.pace_wait_simple) > CurrentTime)
    {
      sendto_one(source_p, form_str(RPL_LOAD2HI),
                 me.name, source_p->name);
      return;
    }

    last_used = CurrentTime;

    /* if we have serverhide enabled, they can either ask the clients
     * server, or our server.. I dont see why they would need to ask
     * anything else for info about the client.. --fl_
     */
    if (ConfigFileEntry.disable_remote)
      parv[1] = parv[2];

    if (hunt_server(client_p, source_p, ":%s WHOIS %s :%s", 1,
                    parc, parv) != HUNTED_ISME)
      return;

    parv[1] = parv[2];
  }

  do_whois(source_p, parc, parv);
}

/*
** mo_whois
**      parv[0] = sender prefix
**      parv[1] = nickname masklist
*/
static void
mo_whois(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NONICKNAMEGIVEN),
               me.name, source_p->name);
    return;
  }

  if (parc > 2 && !EmptyString(parv[2]))
  {
    if (hunt_server(client_p, source_p, ":%s WHOIS %s :%s", 1,
                    parc, parv) != HUNTED_ISME)
      return;

    parv[1] = parv[2];
  }

  do_whois(source_p, parc, parv);
}

/* do_whois()
 *
 * inputs	- pointer to /whois source
 *              - number of parameters
 *              - pointer to parameters array
 * output	- pointer to void
 * side effects - Does whois
 */
static void
do_whois(struct Client *source_p, int parc, char *parv[])
{
  static time_t last_used = 0;
  struct Client *target_p;
  char *nick;
  char *p = NULL;
  int found = 0;

  nick = parv[1];
  while (*nick == ',')
    nick++;
  if ((p = strchr(nick,',')) != NULL)
    *p = '\0';

  if (*nick == '\0')
    return;

  collapse(nick);

  if (strpbrk(nick, "?#*") == NULL)
  {
    if ((target_p = hash_find_client(nick)) != NULL)
    {
      if (IsClient(target_p))
      {
        whois_person(source_p, target_p);
        found = 1;
      }
    }
  }
  else /* wilds is true */
  {
    if (!HasUMode(source_p, UMODE_OPER))
    {
      if ((last_used + ConfigFileEntry.pace_wait_simple) > CurrentTime)
      {
        sendto_one(source_p, form_str(RPL_LOAD2HI),
                   me.name, source_p->name);
        return;
      }
      else
        last_used = CurrentTime;
  }

    /* Oh-oh wilds is true so have to do it the hard expensive way */
    if (MyClient(source_p))
      found = global_whois(source_p, nick);
  }

  if (!found)
  {
    if (!IsDigit(*nick))
      sendto_one(source_p, form_str(ERR_NOSUCHNICK),
		 me.name, source_p->name, nick);
  }

  sendto_one(source_p, form_str(RPL_ENDOFWHOIS),
             me.name, source_p->name, parv[1]);
}

/* global_whois()
 *
 * Inputs	- source_p client to report to
 *		- target_p client to report on
 * Output	- if found return 1
 * Side Effects	- do a single whois on given client
 * 		  writing results to source_p
 */
static int
global_whois(struct Client *source_p, const char *nick)
{
  dlink_node *ptr;
  struct Client *target_p;
  int found = 0;

  DLINK_FOREACH(ptr, global_client_list.head)
  {
    target_p = ptr->data;

    if (!IsClient(target_p))
      continue;

    if (match(nick, target_p->name))
      continue;

    assert(target_p->servptr != NULL);

    /* 'Rules' established for sending a WHOIS reply:
     *
     *
     * - if wildcards are being used dont send a reply if
     *   the querier isnt any common channels and the
     *   client in question is invisible and wildcards are
     *   in use (allow exact matches only);
     *
     * - only send replies about common or public channels
     *   the target user(s) are on;
     */

    found |= single_whois(source_p, target_p);
  }

  return found;
}

/* single_whois()
 *
 * Inputs	- source_p client to report to
 *		- target_p client to report on
 * Output	- if found return 1
 * Side Effects	- do a single whois on given client
 * 		  writing results to source_p
 */
static int
single_whois(struct Client *source_p, struct Client *target_p)
{
  dlink_node *ptr = NULL;

  if (!HasUMode(target_p, UMODE_INVISIBLE) || target_p == source_p)
  {
    /* always show user if they are visible (no +i) */
    whois_person(source_p, target_p);
    return 1;
  }

  /* target_p is +i. Check if it is on any common channels with source_p */
  DLINK_FOREACH(ptr, target_p->channel.head)
  {
    struct Channel *chptr = ((struct Membership *) ptr->data)->chptr;

    if (IsMember(source_p, chptr))
    {
      whois_person(source_p, target_p);
      return 1;
    }
  }

  return 0;
}

/* whois_person()
 *
 * inputs	- source_p client to report to
 *		- target_p client to report on
 * output	- NONE
 * side effects	- 
 */
static void
whois_person(struct Client *source_p, struct Client *target_p)
{
  char buf[IRCD_BUFSIZE];
  dlink_node *lp;
  struct Client *server_p;
  struct Channel *chptr;
  struct Membership *ms;
  int cur_len = 0;
  int mlen;
  char *t = NULL;
  int tlen;
  int reply_to_send = 0;
  int show_ip = 0;

  server_p = target_p->servptr;

  sendto_one(source_p, form_str(RPL_WHOISUSER),
             me.name, source_p->name, target_p->name,
             target_p->username, target_p->host, target_p->info);

  cur_len = mlen = snprintf(buf, sizeof(buf), form_str(RPL_WHOISCHANNELS),
                            me.name, source_p->name, target_p->name, "");
  t = buf + mlen;

  DLINK_FOREACH(lp, target_p->channel.head)
  {
    ms = lp->data;
    chptr = ms->chptr;

    if (ShowChannel(source_p, chptr))
    {
      if ((cur_len + 3 + strlen(chptr->chname) + 1) > (IRCD_BUFSIZE - 2))
      {
	*(t - 1) = '\0';
	sendto_one(source_p, "%s", buf);
	cur_len = mlen;
	t = buf + mlen;
      }

      tlen = sprintf(t, "%s%s ", get_member_status(ms, 1), chptr->chname);
      t += tlen;
      cur_len += tlen;
      reply_to_send = 1;
    }
  }

  if (reply_to_send)
  {
    *(t - 1) = '\0';
    sendto_one(source_p, "%s", buf);
  }

  if (HasUMode(source_p, UMODE_OPER) || !ConfigServerHide.hide_servers || target_p == source_p)
    sendto_one(source_p, form_str(RPL_WHOISSERVER),
               me.name, source_p->name, target_p->name,
               server_p->name, server_p->info);
  else
    sendto_one(source_p, form_str(RPL_WHOISSERVER),
	       me.name, source_p->name, target_p->name,
               ConfigServerHide.hidden_name,
	       ServerInfo.network_desc);

  if (HasUMode(target_p, UMODE_REGISTERED))
    sendto_one(source_p, form_str(RPL_WHOISREGNICK),
               me.name, source_p->name, target_p->name);

  if (target_p->away[0])
    sendto_one(source_p, form_str(RPL_AWAY),
               me.name, source_p->name, target_p->name,
               target_p->away);

  if (HasUMode(target_p, UMODE_CALLERID) && !HasUMode(target_p, UMODE_SOFTCALLERID))
    sendto_one(source_p, form_str(RPL_TARGUMODEG),
               me.name, source_p->name, target_p->name);

  if (HasUMode(target_p, UMODE_OPER))
    if (!HasUMode(target_p, UMODE_HIDDEN) || HasUMode(source_p, UMODE_OPER))
      sendto_one(source_p, form_str(HasUMode(target_p, UMODE_ADMIN) ? RPL_WHOISADMIN :
                 RPL_WHOISOPERATOR),
                 me.name, source_p->name, target_p->name);

  if (strcmp(target_p->sockhost, "0"))
  {
    if (HasUMode(source_p, UMODE_ADMIN) || source_p == target_p)
      show_ip = 1;
    else if (IsIPSpoof(target_p))
      show_ip = (HasUMode(source_p, UMODE_OPER) && !ConfigFileEntry.hide_spoof_ips);
    else
      show_ip = 1;

    sendto_one(source_p, form_str(RPL_WHOISACTUALLY),
               me.name, source_p->name, target_p->name,
               show_ip ? target_p->sockhost : "255.255.255.255");
  }

  if (MyConnect(target_p)) /* Can't do any of this if not local! db */
  {
#ifdef HAVE_LIBCRYPTO
    if (target_p->localClient->fd.ssl)
      sendto_one(source_p, form_str(RPL_WHOISSECURE),
                 me.name, source_p->name, target_p->name);
#endif
    sendto_one(source_p, form_str(RPL_WHOISIDLE),
               me.name, source_p->name, target_p->name,
               idle_time_get(source_p, target_p),
               target_p->localClient->firsttime);

    if (HasUMode(target_p, UMODE_OPER) && target_p != source_p)
      if (HasUMode(target_p, UMODE_SPY))
        sendto_one(target_p, ":%s NOTICE %s :*** Notice -- %s (%s@%s) [%s] is doing "
                   "a whois on you", me.name, target_p->name, source_p->name,
                   source_p->username, source_p->host, source_p->servptr->name);
  }
}

static struct Message whois_msgtab = {
  "WHOIS", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_whois, mo_whois, m_ignore, mo_whois, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&whois_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&whois_msgtab);
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
