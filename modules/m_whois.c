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
  char buf[IRCD_BUFSIZE] = { '\0' };
  const dlink_node *lp = NULL;
  char *t = NULL;
  int cur_len = 0;
  int show_ip = 0;
  int mlen = 0;
  int tlen = 0;
  int reply_to_send = 0;

  sendto_one(source_p, form_str(RPL_WHOISUSER), me.name,
             source_p->name, target_p->name,
             target_p->username, target_p->host, target_p->info);

  cur_len = mlen = snprintf(buf, sizeof(buf), form_str(RPL_WHOISCHANNELS),
                            me.name, source_p->name, target_p->name, "");
  t = buf + mlen;

  DLINK_FOREACH(lp, target_p->channel.head)
  {
    const struct Membership *ms = lp->data;

    if (ShowChannel(source_p, ms->chptr))
    {
      if ((cur_len + 3 + strlen(ms->chptr->chname) + 1) > (IRCD_BUFSIZE - 2))
      {
	*(t - 1) = '\0';
	sendto_one(source_p, "%s", buf);
	cur_len = mlen;
	t = buf + mlen;
      }

      tlen = sprintf(t, "%s%s ", get_member_status(ms, 1), ms->chptr->chname);
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
               target_p->servptr->name, target_p->servptr->info);
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

  if (target_p->sockhost[0] && strcmp(target_p->sockhost, "0"))
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

  if (MyConnect(target_p))
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

/* do_whois()
 *
 * inputs       - pointer to /whois source
 *              - number of parameters
 *              - pointer to parameters array
 * output       - pointer to void
 * side effects - Does whois
 */
static void
do_whois(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  char *nick = parv[1];
  char *p = NULL;

  if ((p = strchr(nick, ',')) != NULL)
    *p = '\0';
  if (*nick == '\0')
    return;

  if ((target_p = hash_find_client(nick)) && IsClient(target_p))
    whois_person(source_p, target_p);
  else if (!IsDigit(*nick))
    sendto_one(source_p, form_str(ERR_NOSUCHNICK),
               me.name, source_p->name, nick);

  sendto_one(source_p, form_str(RPL_ENDOFWHOIS),
             me.name, source_p->name, nick);
}

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

    /*
     * if we have serverhide enabled, they can either ask the clients
     * server, or our server.. I dont see why they would need to ask
     * anything else for info about the client.. --fl_
     */
    if (ConfigServerHide.disable_remote_commands)
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
