/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "misc.h"
#include "module.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "client_find.h"
#include "client_svstag.h"
#include "conf.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "user_mode.h"

/**
 * @enum whois_channel_visibility_t
 * @brief Enum for representing the visibility level of a channel in a WHOIS query.
 *
 * This enum defines the different levels of visibility for a channel when a WHOIS query is made.
 * Each value indicates the level of access the querying user has to the channel's information,
 * depending on their relationship to the channel and their user modes.
 */
typedef enum
{
  WHOIS_CHANNEL_VISIBILITY_FULL,  /**< Full visibility; no restrictions apply. Channel appears as "#channel". */
  WHOIS_CHANNEL_VISIBILITY_LIMITED,  /**< Channel is private (+p) or secret (+s). Channel appears as "?#channel". */
  WHOIS_CHANNEL_VISIBILITY_HIDDEN,  /**< Channel is hidden by the target's user mode (+p). Channel appears as "!#channel". */
  WHOIS_CHANNEL_VISIBILITY_NONE,  /**< Channel is not visible to the querying user. */
} whois_channel_visibility_t;

/**
 * @brief Determines the visibility level of a channel in a WHOIS query.
 *
 * This function evaluates the visibility level of a specified channel for a WHOIS query
 * based on the relationship between the source client, target client, and the channel's
 * properties. It returns a value indicating the level of access the querying user has
 * to the channel's information.
 *
 * @param channel A pointer to the Channel structure representing a channel in which the target client is a member.
 * @param source A pointer to the Client structure representing the querying user.
 * @param target A pointer to the Client structure representing the user being queried.
 * @return A whois_channel_visibility_t value indicating the visibility level of the channel.
*/
static whois_channel_visibility_t
_whois_get_channel_visibility(const struct Channel *channel, const struct Client *source, const struct Client *target)
{
  if (channel_is_public(channel) && !user_mode_has_flag(target, UMODE_HIDECHANS))
    return WHOIS_CHANNEL_VISIBILITY_FULL;

  if (source == target || channel_member_find(source, channel))
    return WHOIS_CHANNEL_VISIBILITY_FULL;

  if (client_is_oper(source))
  {
    if (!channel_is_public(channel))
      return WHOIS_CHANNEL_VISIBILITY_LIMITED;
    /* user_mode_has_flag(target, UMODE_HIDECHANS) == true */
    return WHOIS_CHANNEL_VISIBILITY_HIDDEN;
  }

  return WHOIS_CHANNEL_VISIBILITY_NONE;
}

static const char *
_whois_get_channel_visibility_prefix(whois_channel_visibility_t vis)
{
  switch (vis)
  {
    case WHOIS_CHANNEL_VISIBILITY_LIMITED:
      return "?";
    case WHOIS_CHANNEL_VISIBILITY_HIDDEN:
      return "!";
    case WHOIS_CHANNEL_VISIBILITY_FULL:
    case WHOIS_CHANNEL_VISIBILITY_NONE:
    default:
      return "";
  }
}

static void
_whois_send_user_numeric(struct Client *source, const struct Client *target)
{
  sendto_one_numeric(source, &me, RPL_WHOISUSER,
                     target->name, target->username, target->host, target->info);
}

static void
_whois_send_host_numeric(struct Client *source, const struct Client *target)
{
  if (client_is_oper(source) || source == target)
    sendto_one_numeric(source, &me, RPL_WHOISACTUALLY,
                       target->name, target->username, target->realhost, target->sockhost);
}

static void
_whois_send_channels_numeric(struct Client *source, const struct Client *target)
{
  if (list_is_empty(&target->channel_list))
    return;

  /* :me.name 319 source->name target->name :~@#chan1 +#chan2 #chan3 ...\r\n */
  /* 1       23456            7            89                           0 1  */
  size_t len = strlen(target->name) + 11;
  if (client_is_local(source))
    len += strlen(me.name) + strlen(source->name);
  else
    len += IO_MAX(strlen(me.name), strlen(me.id)) + IO_MAX(strlen(source->name), strlen(source->id));

  char buf[IRCD_BUFSIZE];
  char *bufptr = buf;

  list_node_t *node;
  LIST_FOREACH(node, target->channel_list.head)
  {
    const struct ChannelMember *const member = node->data;
    whois_channel_visibility_t vis = _whois_get_channel_visibility(member->channel, source, target);

    if (vis == WHOIS_CHANNEL_VISIBILITY_NONE)
      continue;

    if ((bufptr - buf) + member->channel->name_len + 1 + (vis != WHOIS_CHANNEL_VISIBILITY_FULL) + channel_member_get_prefix_length(member, true) + len > sizeof(buf))
    {
      sendto_one_numeric(source, &me, RPL_WHOISCHANNELS, target->name, buf);
      bufptr = buf;
    }

    const char *const channel_prefix = _whois_get_channel_visibility_prefix(vis);
    bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != buf ? " %s%s%s" : "%s%s%s",
                       channel_prefix, channel_member_get_prefix(member, true), member->channel->name);
  }

  if (bufptr != buf)
    sendto_one_numeric(source, &me, RPL_WHOISCHANNELS, target->name, buf);
}

static void
_whois_send_server_numeric(struct Client *source, const struct Client *target)
{
  if ((ConfigServerHide.hide_servers || client_is_hidden(target->uplink)) &&
      !(client_is_oper(source) || source == target))
    sendto_one_numeric(source, &me, RPL_WHOISSERVER,
                       target->name, ConfigServerHide.hidden_name, ConfigServerInfo.network_description);
  else
    sendto_one_numeric(source, &me, RPL_WHOISSERVER,
                       target->name, target->uplink->name, target->uplink->info);
}

static void
_whois_send_away_numeric(struct Client *source, const struct Client *target)
{
  if (target->away_message)
    sendto_one_numeric(source, &me, RPL_AWAY, target->name, target->away_message);
}

static void
_whois_send_operator_numeric(struct Client *source, const struct Client *target)
{
  if (client_is_oper(target) || client_is_service(target))
  {
    if (!user_mode_has_flag(target, UMODE_HIDDEN) || client_is_oper(source))
    {
      const struct ServicesTag *const svstag = list_peek_head(&target->svstag_list);
      if (svstag == NULL || svstag->numeric != RPL_WHOISOPERATOR)
      {
        const char *text;
        if (client_is_service(target))
          text = "is a Network Service";
        else if (client_is_admin(target))
          text = "is a Server Administrator";
        else  /* client_is_oper(target) == true */
          text = "is an IRC Operator";
        sendto_one_numeric(source, &me, RPL_WHOISOPERATOR, target->name, text);
      }
    }
  }

  list_node_t *node;
  LIST_FOREACH(node, target->svstag_list.head)
  {
    const struct ServicesTag *const svstag = node->data;
    if (svstag->numeric == RPL_WHOISOPERATOR)
      if (user_mode_has_flag(target, UMODE_HIDDEN) && !client_is_oper(source))
        continue;

    if (svstag->umodes == 0 || user_mode_has_flag(source, svstag->umodes))
      sendto_one_numeric(source, &me, svstag->numeric | SND_EXPLICIT, "%s :%s",
                         target->name, svstag->tag);
  }
}

static void
_whois_send_modes_numeric(struct Client *source, const struct Client *target)
{
  if (client_is_oper(source) || source == target)
    sendto_one_numeric(source, &me, RPL_WHOISMODES,
                       target->name, user_mode_to_str(target->umodes));
}

static void
_whois_send_idle_numeric(struct Client *source, const struct Client *target)
{
  if (client_is_local(target))
    if (!user_mode_has_flag(target, UMODE_HIDEIDLE) || client_is_oper(source) || source == target)
      sendto_one_numeric(source, &me, RPL_WHOISIDLE,
                         target->name, client_get_idle_time(source, target), target->connection->created_real);
}

static void
_whois_send_target_reply(struct Client *source, struct Client *target)
{
  _whois_send_user_numeric(source, target);

  _whois_send_host_numeric(source, target);

  _whois_send_channels_numeric(source, target);

  _whois_send_server_numeric(source, target);

  _whois_send_away_numeric(source, target);

  _whois_send_operator_numeric(source, target);

  _whois_send_modes_numeric(source, target);

  hook_dispatch(ircd_hook_whois_send, &(ircd_hook_whois_send_ctx){ .source = source, .target = target });

  _whois_send_idle_numeric(source, target);
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
_whois_process_request(struct Client *source, const char *name)
{
  struct Client *const target = client_find_user(source, name);
  if (target)
    _whois_send_target_reply(source, target);
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
  if (string_is_empty(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  if (!string_is_empty(parv[2]))
  {
    static uintmax_t last_used = 0;
    /* seeing as this is going across servers, we should limit it */
    if ((last_used + ConfigGeneral.pace_wait_simple) > io_time_get(IO_TIME_MONOTONIC_SEC))
    {
      sendto_one_numeric(source, &me, RPL_LOAD2HI, "WHOIS");
      return;
    }

    last_used = io_time_get(IO_TIME_MONOTONIC_SEC);

    /*
     * if we have serverhide enabled, they can either ask the clients
     * server, or our server.. I don't see why they would need to ask
     * anything else for info about the client.. --fl_
     */
    if (ConfigServerHide.disable_remote_commands)
      parv[1] = parv[2];

    if (server_route_command(source, ":%s WHOIS %s :%s", 1, parv)->result != SERVER_ROUTE_ISME)
      return;

    parv[1] = parv[2];
  }

  _whois_process_request(source, parv[1]);
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
  if (string_is_empty(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  if (!string_is_empty(parv[2]))
  {
    if (server_route_command(source, ":%s WHOIS %s :%s", 1, parv)->result != SERVER_ROUTE_ISME)
      return;

    parv[1] = parv[2];
  }

  _whois_process_request(source, parv[1]);
}

static struct Command command_table =
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
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
