/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file m_whois.c
 * \brief Includes required functions for processing the WHOIS command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "client_svstag.h"
#include "hash.h"
#include "channel.h"
#include "channel_mode.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "misc.h"
#include "server.h"
#include "user.h"
#include "send.h"
#include "irc_string.h"
#include "parse.h"
#include "modules.h"


enum whois_show_type
{
  WHOIS_SHOW_NORMAL,  /**< Can see just normal; no restrictions apply */
  WHOIS_SHOW_NONPUB,  /**< Channel is either +s, or +p */
  WHOIS_SHOW_HIDDEN,  /**< Client is +p */
  WHOIS_SHOW_NO,  /**< May not see this channel */
};

static enum whois_show_type
whois_show_channel(struct Channel *channel,
                   struct Client *source_p,
                   struct Client *target_p)
{
  if (PubChannel(channel) && !HasUMode(target_p, UMODE_HIDECHANS))
    return WHOIS_SHOW_NORMAL;

  if (source_p == target_p || member_find_link(source_p, channel))
    return WHOIS_SHOW_NORMAL;

  if (HasUMode(source_p, UMODE_OPER))
  {
    if (!PubChannel(channel))
      return WHOIS_SHOW_NONPUB;
    /* HasUMode(target_p, UMODE_HIDECHANS) == true */
    return WHOIS_SHOW_HIDDEN;
  }

  return WHOIS_SHOW_NO;
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
  dlink_node *node;
  const struct ServicesTag *svstag = NULL;

  sendto_one_numeric(source_p, &me, RPL_WHOISUSER, target_p->name,
                     target_p->username, target_p->host,
                     target_p->info);

  if (dlink_list_length(&target_p->channel))
  {
    char buf[IRCD_BUFSIZE];
    char *bufptr = buf;

    /* :me.name 319 source_p->name target_p->name :~@#chan1 +#chan2 #chan3 ...\r\n */
    /* 1       23456              7              89                           0 1  */
    size_t len = strlen(target_p->name) + 11;

    if (MyConnect(source_p))
      len += strlen(me.name) + strlen(source_p->name);
    else
      len += IRCD_MAX(strlen(me.name), strlen(me.id)) + IRCD_MAX(strlen(source_p->name), strlen(source_p->id));

    DLINK_FOREACH(node, target_p->channel.head)
    {
      const struct ChannelMember *member = node->data;
      enum whois_show_type show = whois_show_channel(member->channel, source_p, target_p);

      if (show != WHOIS_SHOW_NO)
      {
        if ((bufptr - buf) + member->channel->name_len + 1 + (show != WHOIS_SHOW_NORMAL) + member_get_prefix_len(member, true) + len > sizeof(buf))
        {
          *(bufptr - 1) = '\0';
          sendto_one_numeric(source_p, &me, RPL_WHOISCHANNELS, target_p->name, buf);
          bufptr = buf;
        }

        const char *channel_prefix = "";
        if (show == WHOIS_SHOW_NONPUB)
          channel_prefix = "?";
        else if (show == WHOIS_SHOW_HIDDEN)
          channel_prefix = "!";

        bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), "%s%s%s ",
                           channel_prefix, member_get_prefix(member, true), member->channel->name);
      }
    }

    if (bufptr != buf)
    {
      *(bufptr - 1) = '\0';
      sendto_one_numeric(source_p, &me, RPL_WHOISCHANNELS, target_p->name, buf);
    }
  }

  if ((ConfigServerHide.hide_servers || IsHidden(target_p->servptr)) &&
      !(HasUMode(source_p, UMODE_OPER) || source_p == target_p))
    sendto_one_numeric(source_p, &me, RPL_WHOISSERVER, target_p->name,
                       ConfigServerHide.hidden_name,
                       ConfigServerInfo.network_description);
  else
    sendto_one_numeric(source_p, &me, RPL_WHOISSERVER, target_p->name,
                       target_p->servptr->name, target_p->servptr->info);

  if (HasUMode(target_p, UMODE_REGISTERED))
    sendto_one_numeric(source_p, &me, RPL_WHOISREGNICK, target_p->name);

  if (strcmp(target_p->account, "*"))
    sendto_one_numeric(source_p, &me, RPL_WHOISACCOUNT, target_p->name,
                       target_p->account, "is");

  if (target_p->away[0])
    sendto_one_numeric(source_p, &me, RPL_AWAY, target_p->name,
                       target_p->away);

  if (HasUMode(target_p, UMODE_CALLERID | UMODE_SOFTCALLERID))
  {
    bool callerid = HasUMode(target_p, UMODE_CALLERID) != 0;

    sendto_one_numeric(source_p, &me, RPL_TARGUMODEG, target_p->name,
                       callerid ? "+g" : "+G",
                       callerid ? "server side ignore" :
                                  "server side ignore with the exception of common channels");
  }

  if (HasUMode(target_p, UMODE_OPER) || HasFlag(target_p, FLAGS_SERVICE))
  {
    if (!HasUMode(target_p, UMODE_HIDDEN) || HasUMode(source_p, UMODE_OPER))
    {
      if (target_p->svstags.head)
        svstag = target_p->svstags.head->data;

      if (svstag == NULL || svstag->numeric != RPL_WHOISOPERATOR)
      {
        const char *text;
        if (HasFlag(target_p, FLAGS_SERVICE))
          text = "is a Network Service";
        else if (HasUMode(target_p, UMODE_ADMIN))
          text = "is a Server Administrator";
        else  /* HasUMode(target_p, UMODE_OPER) == true */
          text = "is an IRC Operator";
        sendto_one_numeric(source_p, &me, RPL_WHOISOPERATOR, target_p->name, text);
      }
    }
  }

  DLINK_FOREACH(node, target_p->svstags.head)
  {
    svstag = node->data;

    if (svstag->numeric == RPL_WHOISOPERATOR)
      if (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER))
        continue;

    if (svstag->umodes == 0 || HasUMode(source_p, svstag->umodes))
      sendto_one_numeric(source_p, &me, svstag->numeric | SND_EXPLICIT, "%s :%s",
                         target_p->name, svstag->tag);
  }

  if (HasUMode(target_p, UMODE_BOT))
    sendto_one_numeric(source_p, &me, RPL_WHOISBOT, target_p->name);

  if (HasUMode(target_p, UMODE_WEBIRC))
    sendto_one_numeric(source_p, &me, RPL_WHOISTEXT, target_p->name,
                       "User connected using a webirc gateway");

  if (HasUMode(source_p, UMODE_OPER) || source_p == target_p)
  {
    char buf[UMODE_MAX_STR];
    char *m = buf;

    *m++ = '+';
    for (const struct user_modes *tab = umode_tab; tab->c; ++tab)
      if (HasUMode(target_p, tab->flag))
        *m++ = tab->c;
    *m = '\0';

    sendto_one_numeric(source_p, &me, RPL_WHOISMODES, target_p->name, buf);
  }

  if (HasUMode(source_p, UMODE_OPER) || source_p == target_p)
    sendto_one_numeric(source_p, &me, RPL_WHOISACTUALLY, target_p->name,
                       target_p->username, target_p->realhost,
                       target_p->sockhost);

  if (HasUMode(target_p, UMODE_SECURE))
    sendto_one_numeric(source_p, &me, RPL_WHOISSECURE, target_p->name);

  if (!EmptyString(target_p->tls_certfp))
    if (HasUMode(source_p, UMODE_OPER) || source_p == target_p)
      sendto_one_numeric(source_p, &me, RPL_WHOISCERTFP, target_p->name, target_p->tls_certfp);

  if (MyConnect(target_p))
    if (!HasUMode(target_p, UMODE_HIDEIDLE) || HasUMode(source_p, UMODE_OPER) ||
        source_p == target_p)
      sendto_one_numeric(source_p, &me, RPL_WHOISIDLE, target_p->name,
                         client_get_idle_time(source_p, target_p),
                         target_p->connection->created_real);

  if (HasUMode(target_p, UMODE_SPY) && source_p != target_p)
    sendto_one_notice(target_p, &me, ":*** Notice -- %s (%s@%s) [%s] is doing a /whois on you",
                      source_p->name, source_p->username, source_p->host, source_p->servptr->name);
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
do_whois(struct Client *source_p, const char *name)
{
  struct Client *target_p;

  if ((target_p = hash_find_client(name)) && IsClient(target_p))
    whois_person(source_p, target_p);
  else
    sendto_one_numeric(source_p, &me, ERR_NOSUCHNICK, name);

  sendto_one_numeric(source_p, &me, RPL_ENDOFWHOIS, name);
}

/*! \brief WHOIS command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 *      - parv[2] = nickname
 */
static void
m_whois(struct Client *source_p, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  if (!EmptyString(parv[2]))
  {
    /* seeing as this is going across servers, we should limit it */
    if ((last_used + ConfigGeneral.pace_wait_simple) > event_base->time.sec_monotonic)
    {
      sendto_one_numeric(source_p, &me, RPL_LOAD2HI, "WHOIS");
      return;
    }

    last_used = event_base->time.sec_monotonic;

    /*
     * if we have serverhide enabled, they can either ask the clients
     * server, or our server.. I don't see why they would need to ask
     * anything else for info about the client.. --fl_
     */
    if (ConfigServerHide.disable_remote_commands)
      parv[1] = parv[2];

    if (server_hunt(source_p, ":%s WHOIS %s :%s", 1, parv)->ret != HUNTED_ISME)
      return;

    parv[1] = parv[2];
  }

  do_whois(source_p, parv[1]);
}

/*! \brief WHOIS command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 *      - parv[2] = nickname
 */
static void
mo_whois(struct Client *source_p, int parc, char *parv[])
{
  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  if (!EmptyString(parv[2]))
  {
    if (server_hunt(source_p, ":%s WHOIS %s :%s", 1, parv)->ret != HUNTED_ISME)
      return;

    parv[1] = parv[2];
  }

  do_whois(source_p, parv[1]);
}

static struct Message whois_msgtab =
{
  .cmd = "WHOIS",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_whois },
  .handlers[SERVER_HANDLER] = { .handler = mo_whois },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_whois }
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

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
