/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
 *  Copyright (c) 1997-1999 Andrea "Nemesi" Cocito
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

/*! \file m_who.c
 * \brief Includes required functions for processing the WHO command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "channel.h"
#include "channel_mode.h"
#include "hash.h"
#include "ircd.h"
#include "isupport.h"
#include "numeric.h"
#include "server.h"
#include "send.h"
#include "irc_string.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"
#include "hostmask.h"


/** Maximum number of lines to send in response to a /WHO. */
enum { WHO_MAX_REPLIES = 500 };

enum
{
  WHOSELECT_OPER  = 1 << 0,  /**< Flag for /WHO: Show IRC operators. */
  WHOSELECT_EXTRA = 1 << 1,  /**< Flag for /WHO: Pull rank to see users. */
  WHOSELECT_DELAY = 1 << 2,  /**< Flag for /WHO: Show join-delayed users. */
};

enum
{
  WHO_FIELD_QTO = 1 <<  0,  /**< Display query token. */
  WHO_FIELD_CHA = 1 <<  1,  /**< Show common channel name. */
  WHO_FIELD_UID = 1 <<  2,  /**< Show username. */
  WHO_FIELD_NIP = 1 <<  3,  /**< Show IP address. */
  WHO_FIELD_HOS = 1 <<  4,  /**< Show hostname. */
  WHO_FIELD_SER = 1 <<  5,  /**< Show server. */
  WHO_FIELD_NIC = 1 <<  6,  /**< Show nickname. */
  WHO_FIELD_FLA = 1 <<  7,  /**< Show flags (away, oper, chanop, etc). */
  WHO_FIELD_DIS = 1 <<  8,  /**< Show hop count (distance). */
  WHO_FIELD_REN = 1 <<  9,  /**< Show realname (info). */
  WHO_FIELD_IDL = 1 << 10,  /**< Show idle time. */
  WHO_FIELD_ACC = 1 << 11,  /**< Show account name. */
  WHO_FIELD_OPL = 1 << 12,  /**< Show oplevel. */
  /** Default fields for /WHO */
  WHO_FIELD_DEF = WHO_FIELD_NIC | WHO_FIELD_UID | WHO_FIELD_HOS | WHO_FIELD_SER,
};

struct WhoQuery
{
  unsigned int bitsel;  /**< User mode matching flags */
  unsigned int matchsel;  /**< Field matching flags */
  unsigned int fields;  /**< Fields to be shown in the output */
  unsigned int maxmatches;  /**< Maximum number of replies to be sent */
  const char *token;  /**< User-defined query token */
};


/*! \brief Send a WHO reply to a client who asked.
 * \param source_p Pointer to client requesting who.
 * \param target_p Client who is shown to \a source_p.
 * \param member ChannelMember pointer of a shared channel that provides visibility.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 */
static void
who_send(struct Client *source_p, const struct Client *target_p,
         struct ChannelMember *member, struct WhoQuery *who)
{
  char buf[IRCD_BUFSIZE];
  char *p = buf;

  /*
   * NOTE: with current fields list and sizes this _cannot_ overrun,
   * and also the message finally sent shouldn't ever be truncated.
   */
  buf[1] = '\0';

  /* If we don't have a channel and we need one... try to find it. */
  if (member == NULL)
  {
    if (who->fields == 0 || (who->fields & (WHO_FIELD_CHA | WHO_FIELD_FLA)))
    {
      dlink_node *node;
      DLINK_FOREACH(node, target_p->channel.head)
      {
        member = node->data;

        if (PubChannel(member->channel))
          break;
        member = NULL;
      }
    }
  }

  /*
   * Place the fields in the buffer and send it. Note that who->fields == 0
   * means "default query".
   */

  if ((who->fields & WHO_FIELD_QTO))  /* Query token */
  {
    if (EmptyString(who->token))
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", "0");
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", who->token);
  }

  if (who->fields == 0 || (who->fields & WHO_FIELD_CHA))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", member ? member->channel->name : "*");

  if (who->fields == 0 || (who->fields & WHO_FIELD_UID))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", target_p->username);

  if ((who->fields & WHO_FIELD_NIP))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", target_p->sockhost);

  if (who->fields == 0 || (who->fields & WHO_FIELD_HOS))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", target_p->host);

  if (who->fields == 0 || (who->fields & WHO_FIELD_SER))
  {
    if (!HasUMode(source_p, UMODE_OPER) &&
        (ConfigServerHide.hide_servers || IsHidden(target_p->servptr)))
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", ConfigServerHide.hidden_name);
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", target_p->servptr->name);
  }

  if (who->fields == 0 || (who->fields & WHO_FIELD_NIC))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", target_p->name);

  if (who->fields == 0 || (who->fields & WHO_FIELD_FLA))
  {
    char status[10];  /* sizeof("GBr*~&@%+") + 1 */

    if (HasUMode(source_p, UMODE_OPER))
      snprintf(status, sizeof(status), "%c%s%s%s%s", target_p->away[0] ? 'G' : 'H',
               HasUMode(target_p, UMODE_BOT) ? "B" : "",
               HasUMode(target_p, UMODE_REGISTERED) ? "r" : "",
               HasUMode(target_p, UMODE_OPER) ? "*" : "",
               member ? member_get_prefix(member, who->fields || !!HasCap(source_p, CAP_MULTI_PREFIX)) : "");

    else
      snprintf(status, sizeof(status), "%c%s%s%s%s", target_p->away[0] ? 'G' : 'H',
               HasUMode(target_p, UMODE_BOT) ? "B" : "",
               HasUMode(target_p, UMODE_REGISTERED) ? "r" : "",
               HasUMode(target_p, UMODE_OPER) &&
               !HasUMode(target_p, UMODE_HIDDEN) ? "*" : "",
               member ? member_get_prefix(member, who->fields || !!HasCap(source_p, CAP_MULTI_PREFIX)) : "");
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", status);
  }

  if (who->fields == 0 || (who->fields & WHO_FIELD_DIS))
  {
    if (!HasUMode(source_p, UMODE_OPER) &&
        (ConfigServerHide.hide_servers || IsHidden(target_p->servptr)))
      p += snprintf(p, sizeof(buf) - (p - buf), " %s%u", who->fields == 0 ? ":" : "", 0);
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %s%u", who->fields == 0 ? ":" : "", target_p->hopcount);
  }

  if ((who->fields & WHO_FIELD_IDL))
  {
    if (MyClient(target_p) &&
        (HasUMode(source_p, UMODE_OPER) || target_p == source_p))
      p += snprintf(p, sizeof(buf) - (p - buf), " %u", client_get_idle_time(source_p, target_p));
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %u", 0);
  }

  if ((who->fields & WHO_FIELD_ACC))
  {
    if (strcmp(target_p->account, "*"))
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", target_p->account);
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", "0");
  }

  if ((who->fields & WHO_FIELD_OPL))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", "n/a");

  if (who->fields == 0 || (who->fields & WHO_FIELD_REN))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s%s", who->fields ? ":" : "", target_p->info);
                                     /* Place colon here for special reply ^ */

  p = buf + 1;  /* The first char will always be an useless blank. */
  sendto_one_numeric(source_p, &me, who->fields ? RPL_WHOSPCRPL : RPL_WHOREPLY, p);
}

/*!
 * \param source_p Pointer to client requesting who.
 * \param target_p Pointer to client to do who on.
 * \param mask Mask to match.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 * \return true if mask matches, false otherwise.
 */
static bool
who_matches(struct Client *source_p, struct Client *target_p, const char *mask, struct WhoQuery *who)
{
  if ((who->bitsel & WHOSELECT_OPER))
    if (!HasUMode(target_p, UMODE_OPER) ||
        (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER)))
      return false;

  if (mask == NULL)
    return true;

  if ((who->matchsel & WHO_FIELD_NIC) && match(mask, target_p->name) == 0)
    return true;

  if ((who->matchsel & WHO_FIELD_UID) && match(mask, target_p->username) == 0)
    return true;

  if ((who->matchsel & WHO_FIELD_HOS))
  {
    if (match(mask, target_p->host) == 0)
      return true;
    else if (HasUMode(source_p, UMODE_OPER) && match(mask, target_p->realhost) == 0)
      return true;
  }

  if ((who->matchsel & WHO_FIELD_REN) && match(mask, target_p->info) == 0)
    return true;

  if ((who->matchsel & WHO_FIELD_ACC) && match(mask, target_p->account) == 0)
    return true;

  if ((who->matchsel & WHO_FIELD_NIP) && HasUMode(source_p, UMODE_OPER))
  {
    struct irc_ssaddr addr;
    int bits = 0;
    const int ret = parse_netmask(mask, &addr, &bits);

    if (ret == HM_IPV4 || ret == HM_IPV6)
      if (address_compare(&target_p->ip, &addr, false, false, bits) == true)
        return true;

    if (match(mask, target_p->sockhost) == 0)
      return true;
  }

  if ((who->matchsel & WHO_FIELD_SER))
    if (HasUMode(source_p, UMODE_OPER) ||
        (ConfigServerHide.hide_servers == 0 && !IsHidden(target_p->servptr)))
      if (match(mask, target_p->servptr->name) == 0)
        return true;

  return false;
}

/*! \brief Lists matching clients on specified channel. Marks matched clients.
 * \param source_p Pointer to client requesting who.
 * \param channel Pointer to channel member chain.
 * \param mask Mask to match.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 */
static void
who_on_common_channel(struct Client *source_p, struct Channel *channel, const char *mask,
                      struct WhoQuery *who)
{
  dlink_node *node;

  DLINK_FOREACH(node, channel->members.head)
  {
    struct ChannelMember *member = node->data;
    struct Client *target_p = member->client;

    if (!HasUMode(target_p, UMODE_INVISIBLE) || HasFlag(target_p, FLAGS_MARK))
      continue;

    AddFlag(target_p, FLAGS_MARK);

    if (who->maxmatches)
    {
      if (who_matches(source_p, target_p, mask, who) == true)
      {
        who_send(source_p, target_p, member, who);
        --who->maxmatches;
      }
    }
  }
}

/*! \brief Does a global scan of all clients looking for match.
 * \param source_p Pointer to client requesting who.
 * \param mask Mask to match.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 */
static void
who_global(struct Client *source_p, const char *mask, struct WhoQuery *who)
{
  dlink_node *node;
  static uintmax_t last_used = 0;

  if (!HasUMode(source_p, UMODE_OPER))
  {
    if ((last_used + ConfigGeneral.pace_wait) > event_base->time.sec_monotonic)
    {
      sendto_one_numeric(source_p, &me, RPL_LOAD2HI, "WHO");
      return;
    }

    last_used = event_base->time.sec_monotonic;
  }

  /* First, list all matching invisible clients on common channels */
  DLINK_FOREACH(node, source_p->channel.head)
  {
    struct ChannelMember *member = node->data;
    who_on_common_channel(source_p, member->channel, mask, who);
  }

  /* Second, list all matching visible clients */
  DLINK_FOREACH(node, global_client_list.head)
  {
    struct Client *target_p = node->data;

    assert(IsClient(target_p));

    if (HasUMode(target_p, UMODE_INVISIBLE))
    {
      DelFlag(target_p, FLAGS_MARK);
      continue;
    }

    if (who->maxmatches)
    {
      if (who_matches(source_p, target_p, mask, who) == true)
      {
        who_send(source_p, target_p, NULL, who);
        --who->maxmatches;
      }
    }
  }
}

/*! \brief Does a WHO on given channel.
 * \param source_p Pointer to client requesting who.
 * \param channel Pointer to channel to do who on.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 */
static void
who_on_channel(struct Client *source_p, struct Channel *channel, struct WhoQuery *who)
{
  bool is_member = false;

  if (HasUMode(source_p, UMODE_ADMIN) || member_find_link(source_p, channel))
    is_member = true;
  else if (SecretChannel(channel))
    return;

  dlink_node *node;
  DLINK_FOREACH(node, channel->members.head)
  {
    struct ChannelMember *member = node->data;
    struct Client *target_p = member->client;

    if (is_member == true || !HasUMode(target_p, UMODE_INVISIBLE))
    {
      if ((who->bitsel & WHOSELECT_OPER))
        if (!HasUMode(target_p, UMODE_OPER) ||
            (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER)))
          continue;

      who_send(source_p, target_p, member, who);
    }
  }
}

/*! \brief WHO command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = mask
 *      - parv[2] = additional selection flag, only 'o' for now.
 *                  and %flags to specify what fields to output
 *                  plus a ,querytype if the t flag is specified
 *                  so the final thing will be like o%tnchu,777
 */
static void
m_who(struct Client *source_p, int parc, char *parv[])
{
  char *mask = parv[1];
  char *options = parv[2];
  char *token = NULL;
  struct WhoQuery w = { .maxmatches = WHO_MAX_REPLIES }, *who = &w;

  if (!EmptyString(options))
  {
    char ch;
    char *p = options;

    while (((ch = *(p++))) && (ch != '%') && (ch != ','))
    {
      switch (ch)
      {
        case 'o':
        case 'O':
          who->bitsel |= WHOSELECT_OPER;
          break;
        case 'n':
        case 'N':
          who->matchsel |= WHO_FIELD_NIC;
          break;
        case 'u':
        case 'U':
          who->matchsel |= WHO_FIELD_UID;
          break;
        case 'h':
        case 'H':
          who->matchsel |= WHO_FIELD_HOS;
          break;
        case 'i':
        case 'I':
          who->matchsel |= WHO_FIELD_NIP;
          break;
        case 's':
        case 'S':
          who->matchsel |= WHO_FIELD_SER;
          break;
        case 'r':
        case 'R':
          who->matchsel |= WHO_FIELD_REN;
          break;
        case 'a':
        case 'A':
          who->matchsel |= WHO_FIELD_ACC;
          break;
      }
    }

    if (ch == '%')
    {
      while ((ch = *p++) && (ch != ','))
      {
        switch (ch)
        {
          case 'c':
          case 'C':
            who->fields |= WHO_FIELD_CHA;
            break;
          case 'd':
          case 'D':
            who->fields |= WHO_FIELD_DIS;
            break;
          case 'f':
          case 'F':
            who->fields |= WHO_FIELD_FLA;
            break;
          case 'h':
          case 'H':
            who->fields |= WHO_FIELD_HOS;
            break;
          case 'i':
          case 'I':
            who->fields |= WHO_FIELD_NIP;
            break;
          case 'l':
          case 'L':
            who->fields |= WHO_FIELD_IDL;
            break;
          case 'n':
          case 'N':
            who->fields |= WHO_FIELD_NIC;
            break;
          case 'r':
          case 'R':
            who->fields |= WHO_FIELD_REN;
            break;
          case 's':
          case 'S':
            who->fields |= WHO_FIELD_SER;
            break;
          case 't':
          case 'T':
            who->fields |= WHO_FIELD_QTO;
            break;
          case 'u':
          case 'U':
            who->fields |= WHO_FIELD_UID;
            break;
          case 'a':
          case 'A':
            who->fields |= WHO_FIELD_ACC;
            break;
          case 'o':
          case 'O':
            who->fields |= WHO_FIELD_OPL;
            break;
        }
      }
    }

    if (ch)
      token = p;

    if (token && (who->fields & WHO_FIELD_QTO))
    {
      p = token;
      if (!((*p > '9') || (*p < '0')))
        p++;
      if (!((*p > '9') || (*p < '0')))
        p++;
      if (!((*p > '9') || (*p < '0')))
        p++;
      *p = '\0';
    }
    else
      token = NULL;

    who->token = token;
  }

  if (who->matchsel == 0)
    who->matchsel = WHO_FIELD_DEF;

  /* '/who #some_channel' */
  if (IsChanPrefix(*mask))
  {
    /* List all users on a given channel */
    struct Channel *channel = hash_find_channel(mask);
    if (channel)
      who_on_channel(source_p, channel, who);

    sendto_one_numeric(source_p, &me, RPL_ENDOFWHO, mask);
    return;
  }

  collapse(mask);
  if (strcmp(mask, "0") == 0 ||
      strcmp(mask, "*") == 0)
    mask = NULL;

  who_global(source_p, mask, who);

  if (who->maxmatches == 0)
    sendto_one_numeric(source_p, &me, ERR_WHOLIMEXCEED, WHO_MAX_REPLIES, "WHO");
  sendto_one_numeric(source_p, &me, RPL_ENDOFWHO, EmptyString(mask) ? "*" : mask);
}

static struct Message who_msgtab =
{
  .cmd = "WHO",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_who, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_who, .args_min = 2 }
};

static void
module_init(void)
{
  mod_add_cmd(&who_msgtab);
  isupport_add("WHOX", NULL, -1);
}

static void
module_exit(void)
{
  mod_del_cmd(&who_msgtab);
  isupport_delete("WHOX");
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
