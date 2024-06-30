/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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
#include "module.h"


enum whois_show_type
{
  WHOIS_SHOW_NORMAL,  /**< Can see just normal; no restrictions apply */
  WHOIS_SHOW_NONPUB,  /**< Channel is either +s, or +p */
  WHOIS_SHOW_HIDDEN,  /**< Client is +p */
  WHOIS_SHOW_NO,  /**< May not see this channel */
};

static enum whois_show_type
whois_show_channel(struct Channel *channel, struct Client *source, struct Client *target)
{
  if (PubChannel(channel) && !HasUMode(target, UMODE_HIDECHANS))
    return WHOIS_SHOW_NORMAL;

  if (source == target || member_find_link(source, channel))
    return WHOIS_SHOW_NORMAL;

  if (HasUMode(source, UMODE_OPER))
  {
    if (!PubChannel(channel))
      return WHOIS_SHOW_NONPUB;
    /* HasUMode(target, UMODE_HIDECHANS) == true */
    return WHOIS_SHOW_HIDDEN;
  }

  return WHOIS_SHOW_NO;
}

/* whois_person()
 *
 * inputs	- source client to report to
 *		- target client to report on
 * output	- NONE
 * side effects	- 
 */
static void
whois_person(struct Client *source, struct Client *target)
{
  char buf[IRCD_BUFSIZE];
  list_node_t *node;
  const struct ServicesTag *svstag = NULL;

  sendto_one_numeric(source, &me, RPL_WHOISUSER,
                     target->name, target->username, target->host, target->info);

  if (list_length(&target->channel))
  {
    char *bufptr = buf;

    /* :me.name 319 source->name target->name :~@#chan1 +#chan2 #chan3 ...\r\n */
    /* 1       23456            7            89                           0 1  */
    size_t len = strlen(target->name) + 11;

    if (MyConnect(source))
      len += strlen(me.name) + strlen(source->name);
    else
      len += IO_MAX(strlen(me.name), strlen(me.id)) + IO_MAX(strlen(source->name), strlen(source->id));

    LIST_FOREACH(node, target->channel.head)
    {
      const struct ChannelMember *member = node->data;
      enum whois_show_type show = whois_show_channel(member->channel, source, target);

      if (show != WHOIS_SHOW_NO)
      {
        if ((bufptr - buf) + member->channel->name_len + 1 + (show != WHOIS_SHOW_NORMAL) + member_get_prefix_len(member, true) + len > sizeof(buf))
        {
          sendto_one_numeric(source, &me, RPL_WHOISCHANNELS, target->name, buf);
          bufptr = buf;
        }

        const char *channel_prefix = "";
        if (show == WHOIS_SHOW_NONPUB)
          channel_prefix = "?";
        else if (show == WHOIS_SHOW_HIDDEN)
          channel_prefix = "!";

        bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != buf ? " %s%s%s" : "%s%s%s",
                           channel_prefix, member_get_prefix(member, true), member->channel->name);
      }
    }

    if (bufptr != buf)
      sendto_one_numeric(source, &me, RPL_WHOISCHANNELS, target->name, buf);
  }

  if ((ConfigServerHide.hide_servers || IsHidden(target->servptr)) &&
      !(HasUMode(source, UMODE_OPER) || source == target))
    sendto_one_numeric(source, &me, RPL_WHOISSERVER,
                       target->name, ConfigServerHide.hidden_name, ConfigServerInfo.network_description);
  else
    sendto_one_numeric(source, &me, RPL_WHOISSERVER,
                       target->name, target->servptr->name, target->servptr->info);

  if (HasUMode(target, UMODE_REGISTERED))
    sendto_one_numeric(source, &me, RPL_WHOISREGNICK, target->name);

  if (strcmp(target->account, "*"))
    sendto_one_numeric(source, &me, RPL_WHOISACCOUNT, target->name, target->account, "is");

  if (target->away[0])
    sendto_one_numeric(source, &me, RPL_AWAY, target->name, target->away);

  if (HasUMode(target, UMODE_CALLERID | UMODE_SOFTCALLERID))
  {
    bool callerid = HasUMode(target, UMODE_CALLERID) != 0;

    sendto_one_numeric(source, &me, RPL_TARGUMODEG, target->name,
                       callerid ? "+g" : "+G",
                       callerid ? "server side ignore" :
                                  "server side ignore with the exception of common channels");
  }

  if (HasUMode(target, UMODE_OPER) || HasFlag(target, FLAGS_SERVICE))
  {
    if (!HasUMode(target, UMODE_HIDDEN) || HasUMode(source, UMODE_OPER))
    {
      if (target->svstags.head)
        svstag = target->svstags.head->data;

      if (svstag == NULL || svstag->numeric != RPL_WHOISOPERATOR)
      {
        const char *text;
        if (HasFlag(target, FLAGS_SERVICE))
          text = "is a Network Service";
        else if (HasUMode(target, UMODE_ADMIN))
          text = "is a Server Administrator";
        else  /* HasUMode(target, UMODE_OPER) == true */
          text = "is an IRC Operator";
        sendto_one_numeric(source, &me, RPL_WHOISOPERATOR, target->name, text);
      }
    }
  }

  LIST_FOREACH(node, target->svstags.head)
  {
    svstag = node->data;

    if (svstag->numeric == RPL_WHOISOPERATOR)
      if (HasUMode(target, UMODE_HIDDEN) && !HasUMode(source, UMODE_OPER))
        continue;

    if (svstag->umodes == 0 || HasUMode(source, svstag->umodes))
      sendto_one_numeric(source, &me, svstag->numeric | SND_EXPLICIT, "%s :%s",
                         target->name, svstag->tag);
  }

  if (HasUMode(target, UMODE_BOT))
    sendto_one_numeric(source, &me, RPL_WHOISBOT, target->name);

  if (HasUMode(target, UMODE_WEBIRC))
    sendto_one_numeric(source, &me, RPL_WHOISTEXT, target->name,
                       "User connected using a webirc gateway");

  if (HasUMode(source, UMODE_OPER) || source == target)
    sendto_one_numeric(source, &me, RPL_WHOISMODES,
                       target->name, user_get_mode_str(target->umodes));

  if (HasUMode(source, UMODE_OPER) || source == target)
    sendto_one_numeric(source, &me, RPL_WHOISACTUALLY,
                       target->name, target->username, target->realhost, target->sockhost);

  if (HasUMode(target, UMODE_SECURE))
  {
    snprintf(buf, sizeof(buf), target->tls_cipher ?
             "is using a secure connection [%s]" :
             "is using a secure connection", target->tls_cipher);
    sendto_one_numeric(source, &me, RPL_WHOISSECURE, target->name, buf);
  }

  if (!EmptyString(target->tls_certfp))
    if (HasUMode(source, UMODE_OPER) || source == target)
      sendto_one_numeric(source, &me, RPL_WHOISCERTFP, target->name, target->tls_certfp);

  if (MyConnect(target))
    if (!HasUMode(target, UMODE_HIDEIDLE) || HasUMode(source, UMODE_OPER) || source == target)
      sendto_one_numeric(source, &me, RPL_WHOISIDLE,
                         target->name, client_get_idle_time(source, target), target->connection->created_real);

  if (HasUMode(target, UMODE_SPY) && source != target)
    sendto_one_notice(target, &me, ":*** Notice -- %s (%s@%s) [%s] is doing a /whois on you",
                      source->name, source->username, source->host, source->servptr->name);
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
do_whois(struct Client *source, const char *name)
{
  struct Client *target = hash_find_client(name);

  if (target && IsClient(target))
    whois_person(source, target);
  else
    sendto_one_numeric(source, &me, ERR_NOSUCHNICK, name);

  sendto_one_numeric(source, &me, RPL_ENDOFWHOIS, name);
}

/*! \brief WHOIS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
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
m_whois(struct Client *source, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  if (!EmptyString(parv[2]))
  {
    /* seeing as this is going across servers, we should limit it */
    if ((last_used + ConfigGeneral.pace_wait_simple) > event_base->time.sec_monotonic)
    {
      sendto_one_numeric(source, &me, RPL_LOAD2HI, "WHOIS");
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

    if (server_hunt(source, ":%s WHOIS %s :%s", 1, parv)->ret != HUNTED_ISME)
      return;

    parv[1] = parv[2];
  }

  do_whois(source, parv[1]);
}

/*! \brief WHOIS command handler
 *
 * \param source Pointer to allocated Client struct from which the message
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
mo_whois(struct Client *source, int parc, char *parv[])
{
  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  if (!EmptyString(parv[2]))
  {
    if (server_hunt(source, ":%s WHOIS %s :%s", 1, parv)->ret != HUNTED_ISME)
      return;

    parv[1] = parv[2];
  }

  do_whois(source, parv[1]);
}

static struct Command whois_msgtab =
{
  .name = "WHOIS",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_whois },
  .handlers[SERVER_HANDLER] = { .handler = mo_whois },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_whois }
};

static void
init_handler(void)
{
  command_add(&whois_msgtab);
}

static void
exit_handler(void)
{
  command_del(&whois_msgtab);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
