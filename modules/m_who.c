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
#include "numeric.h"
#include "server.h"
#include "send.h"
#include "irc_string.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"
#include "hostmask.h"


enum { WHO_MAX_REPLIES = 500 };


/* do_who()
 *
 * inputs       - pointer to client requesting who
 *              - pointer to client to do who on
 *              - The reported name
 *              - channel flags
 * output       - NONE
 * side effects - do a who on given person
 */
static void
do_who(struct Client *source_p, const struct Client *target_p,
       const char *name, const char *op_flags)
{
  char status[8];  /* sizeof("GBr*@%+") + 1 */

  if (HasUMode(source_p, UMODE_OPER))
    snprintf(status, sizeof(status), "%c%s%s%s%s", target_p->away[0] ? 'G' : 'H',
             HasUMode(target_p, UMODE_BOT) ? "B" : "",
             HasUMode(target_p, UMODE_REGISTERED) ? "r" : "",
             HasUMode(target_p, UMODE_OPER) ? "*" : "", op_flags);
  else
    snprintf(status, sizeof(status), "%c%s%s%s%s", target_p->away[0] ? 'G' : 'H',
             HasUMode(target_p, UMODE_BOT) ? "B" : "",
             HasUMode(target_p, UMODE_REGISTERED) ? "r" : "",
             HasUMode(target_p, UMODE_OPER) &&
             !HasUMode(target_p, UMODE_HIDDEN) ? "*" : "", op_flags);

  if (ConfigServerHide.hide_servers || IsHidden(target_p->servptr))
    sendto_one_numeric(source_p, &me, RPL_WHOREPLY,
               (name) ? (name) : "*",
               target_p->username, target_p->host,
               HasUMode(source_p, UMODE_OPER) ? target_p->servptr->name : "*",
               target_p->name, status,
               HasUMode(source_p, UMODE_OPER) ? target_p->hopcount : 0, target_p->info);
  else
    sendto_one_numeric(source_p, &me, RPL_WHOREPLY,
               (name) ? (name) : "*", target_p->username,
               target_p->host, target_p->servptr->name, target_p->name,
               status, target_p->hopcount, target_p->info);
}

/*!
 * \param source_p Pointer to client requesting who
 * \param target_p Pointer to client to do who on
 * \param mask Mask to match
 * \return true if mask matches, false otherwise
 */
static bool
who_matches(struct Client *source_p, struct Client *target_p, const char *mask)
{
  if (mask == NULL)
    return true;

  if (match(mask, target_p->name) == 0)
    return true;

  if (match(mask, target_p->username) == 0)
    return true;

  if (match(mask, target_p->host) == 0)
    return true;

  if (match(mask, target_p->info) == 0)
    return true;

  if (HasUMode(source_p, UMODE_OPER))
  {
    int bits = 0;
    struct irc_ssaddr addr;

    switch (parse_netmask(mask, &addr, &bits))
    {
      case HM_IPV6:
      case HM_IPV4:
        if (address_compare(&target_p->ip, &addr, false, false, bits) == true)
          return true;
    }

    if (match(mask, target_p->sockhost) == 0)
      return true;
    if (match(mask, target_p->realhost) == 0)
      return true;
  }

  if (HasUMode(source_p, UMODE_OPER) ||
      (ConfigServerHide.hide_servers == 0 && !IsHidden(target_p->servptr)))
    if (match(mask, target_p->servptr->name) == 0)
      return true;

  return false;
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
who_common_channel(struct Client *source_p, struct Channel *channel, const char *mask,
                   bool server_oper, unsigned int *maxmatches)
{
  dlink_node *node;

  DLINK_FOREACH(node, channel->members.head)
  {
    struct Client *target_p = ((struct ChannelMember *)node->data)->client;

    if (!HasUMode(target_p, UMODE_INVISIBLE) || HasFlag(target_p, FLAGS_MARK))
      continue;

    if (server_oper == true)
      if (!HasUMode(target_p, UMODE_OPER) ||
          (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER)))
        continue;

    AddFlag(target_p, FLAGS_MARK);

    if (who_matches(source_p, target_p, mask) == true)
    {
      do_who(source_p, target_p, NULL, "");

      if (*maxmatches)
      {
        if (--(*maxmatches) == 0)
        {
          sendto_one_numeric(source_p, &me, ERR_WHOLIMEXCEED, WHO_MAX_REPLIES, "WHO");
          return;
        }
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
who_global(struct Client *source_p, const char *mask, bool server_oper)
{
  dlink_node *node;
  unsigned int maxmatches = WHO_MAX_REPLIES;
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
    struct Channel *channel = ((struct ChannelMember *)node->data)->channel;
    who_common_channel(source_p, channel, mask, server_oper, &maxmatches);
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

    if (server_oper == true)
      if (!HasUMode(target_p, UMODE_OPER) ||
          (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER)))
        continue;

    if (who_matches(source_p, target_p, mask) == true)
    {
      do_who(source_p, target_p, NULL, "");

      if (maxmatches)
      {
        if (--maxmatches == 0)
        {
          sendto_one_numeric(source_p, &me, ERR_WHOLIMEXCEED, WHO_MAX_REPLIES, "WHO");
          return;
        }
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
do_who_on_channel(struct Client *source_p, struct Channel *channel,
                  bool is_member, bool server_oper)
{
  dlink_node *node;

  DLINK_FOREACH(node, channel->members.head)
  {
    struct ChannelMember *member = node->data;
    struct Client *target_p = member->client;

    if (is_member == true || !HasUMode(target_p, UMODE_INVISIBLE))
    {
      if (server_oper == true)
        if (!HasUMode(target_p, UMODE_OPER) ||
            (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER)))
          continue;
      do_who(source_p, target_p, channel->name, member_get_prefix(member, !!HasCap(source_p, CAP_MULTI_PREFIX)));
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
 *      - parv[1] = nickname/channelname
 *      - parv[2] = additional selection flag, only 'o' for now
 */
static void
m_who(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node;
  struct Client *target_p = NULL;
  struct Channel *channel = NULL;
  char *const mask = parv[1];
  const bool server_oper = parv[2] && *parv[2] == 'o';  /* Show OPERS only */

  /* See if mask is there, collapse it or return if not there */
  if (EmptyString(mask))
  {
    who_global(source_p, NULL, server_oper);
    sendto_one_numeric(source_p, &me, RPL_ENDOFWHO, "*");
    return;
  }

  /* Mask isn't NULL at this point. repeat after me... -db */
  collapse(mask);

  /* '/who #some_channel' */
  if (IsChanPrefix(*mask))
  {
    /* List all users on a given channel */
    if ((channel = hash_find_channel(mask)))
    {
      if (HasUMode(source_p, UMODE_ADMIN) || member_find_link(source_p, channel))
        do_who_on_channel(source_p, channel, true, server_oper);
      else if (!SecretChannel(channel))
        do_who_on_channel(source_p, channel, false, server_oper);
    }

    sendto_one_numeric(source_p, &me, RPL_ENDOFWHO, mask);
    return;
  }

  /* '/who nick' */
  if ((target_p = find_person(source_p, mask)) &&
      (server_oper == false || HasUMode(target_p, UMODE_OPER)))
  {
    DLINK_FOREACH(node, target_p->channel.head)
    {
      channel = ((struct ChannelMember *)node->data)->channel;
      if (PubChannel(channel) || member_find_link(source_p, channel))
        break;
    }

    if (node)
      do_who(source_p, target_p, channel->name,
             member_get_prefix(node->data, !!HasCap(source_p, CAP_MULTI_PREFIX)));
    else
      do_who(source_p, target_p, NULL, "");

    sendto_one_numeric(source_p, &me, RPL_ENDOFWHO, mask);
    return;
  }

  /* '/who *' */
  if (strcmp(mask, "*") == 0)
  {
    if ((node = source_p->channel.head))
    {
      channel = ((struct ChannelMember *)node->data)->channel;
      do_who_on_channel(source_p, channel, true, server_oper);
    }

    sendto_one_numeric(source_p, &me, RPL_ENDOFWHO, "*");
    return;
  }

  /* '/who 0' */
  if (strcmp(mask, "0") == 0)
    who_global(source_p, NULL, server_oper);
  else
    who_global(source_p, mask, server_oper);

  /* Wasn't a nick, wasn't a channel, wasn't a '*' so ... */
  sendto_one_numeric(source_p, &me, RPL_ENDOFWHO, mask);
}

static struct Message who_msgtab =
{
  .cmd = "WHO",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_who },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_who }
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

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
