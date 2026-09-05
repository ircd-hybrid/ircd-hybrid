/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-FileCopyrightText: 1997-1999 Andrea "Nemesi" Cocito
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_who.c
 * \brief Includes required functions for processing the WHO command.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "address.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "module.h"

#include "cap.h"
#include "channel.h"
#include "channel_member.h"
#include "channel_mode.h"
#include "client.h"
#include "client_find.h"
#include "conf.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "isupport.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "user_mode.h"

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

  /** Fields included in a traditional RPL_WHOREPLY response. */
  WHO_FIELD_CLASSIC_REPLY =
    WHO_FIELD_CHA |
    WHO_FIELD_UID |
    WHO_FIELD_HOS |
    WHO_FIELD_SER |
    WHO_FIELD_NIC |
    WHO_FIELD_FLA |
    WHO_FIELD_DIS |
    WHO_FIELD_REN,
};

struct WhoQuery
{
  unsigned int bitsel;  /**< User mode matching flags */
  unsigned int matchsel;  /**< Field matching flags */
  unsigned int fields;  /**< Fields to be shown in the output */
  unsigned int maxmatches;  /**< Maximum number of replies to be sent */
  bool whox;  /**< Whether the request uses the WHOX response format. */
  const char *token;  /**< User-defined query token */
};

static bool
_who_reply_includes(const struct WhoQuery *who, unsigned int fields)
{
  const unsigned int reply_fields =
    who->whox ? who->fields : WHO_FIELD_CLASSIC_REPLY;

  return (reply_fields & fields) != 0;
}

/*! \brief Send a WHO reply to a client who asked.
 * \param source Pointer to client requesting who.
 * \param target Client who is shown to \a source.
 * \param member ChannelMember pointer of a shared channel that provides visibility.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 */
static void
_who_send(struct Client *source, const struct Client *target,
          const struct ChannelMember *member, const struct WhoQuery *who)
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
    if (_who_reply_includes(who, WHO_FIELD_CHA | WHO_FIELD_FLA))
    {
      list_node_t *node;
      LIST_FOREACH(node, target->channel_member_list.head)
      {
        member = node->data;

        if (channel_is_public(member->channel) || source == target || channel_member_find(member->channel, source))
          break;
        member = NULL;
      }
    }
  }

  if (_who_reply_includes(who, WHO_FIELD_QTO))  /* Query token */
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", string_or_default(who->token, "0"));

  if (_who_reply_includes(who, WHO_FIELD_CHA))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", member ? member->channel->name : "*");

  if (_who_reply_includes(who, WHO_FIELD_UID))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", target->username);

  if (_who_reply_includes(who, WHO_FIELD_NIP))
  {
    if (client_is_oper(source) || source == target)
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", target->sockhost);
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", "255.255.255.255");
  }

  if (_who_reply_includes(who, WHO_FIELD_HOS))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", target->host);

  if (_who_reply_includes(who, WHO_FIELD_SER))
  {
    if (!client_is_oper(source) &&
        (ConfigServerHide.hide_servers || client_is_hidden(target->uplink)))
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", ConfigServerHide.hidden_name);
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", target->uplink->name);
  }

  if (_who_reply_includes(who, WHO_FIELD_NIC))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", target->name);

  if (_who_reply_includes(who, WHO_FIELD_FLA))
  {
    char status[32] = { [0] = target->away_message ? 'G' : 'H' };

    ircd_hook_who_send_ctx ctx = { .source = source, .target = target };
    hook_dispatch(ircd_hook_who_send, &ctx);

    if (ctx.modes_len)
    {
      ctx.modes[ctx.modes_len] = '\0';
      strlcat(status, ctx.modes, sizeof(status));
    }

    if (member)
    {
      const char *const prefix =
        channel_member_get_prefix(member, who->whox || client_has_cap(source, CAP_MULTI_PREFIX));
      if (!string_is_empty(prefix))
        strlcat(status, prefix, sizeof(status));
    }

    p += snprintf(p, sizeof(buf) - (p - buf), " %s", status);
  }

  if (_who_reply_includes(who, WHO_FIELD_DIS))
  {
    if (!client_is_oper(source) &&
        (ConfigServerHide.hide_servers || client_is_hidden(target->uplink)))
      p += snprintf(p, sizeof(buf) - (p - buf), " %s%u", who->whox ? "" : ":", 0);
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %s%u", who->whox ? "" : ":", target->hopcount);
  }

  if (_who_reply_includes(who, WHO_FIELD_IDL))
  {
    if (client_is_local(target) && (client_is_oper(source) || target == source))
      p += snprintf(p, sizeof(buf) - (p - buf), " %u", client_get_idle_time(source, target));
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %u", 0);
  }

  if (_who_reply_includes(who, WHO_FIELD_ACC))
  {
    if (client_has_account(target))
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", target->account);
    else
      p += snprintf(p, sizeof(buf) - (p - buf), " %s", "0");
  }

  if (_who_reply_includes(who, WHO_FIELD_OPL))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s", "n/a");

  if (_who_reply_includes(who, WHO_FIELD_REN))
    p += snprintf(p, sizeof(buf) - (p - buf), " %s%s", who->whox ? ":" : "", target->info);
                              /* Place colon here for special reply ^ */

  sendto_one_numeric(source, &me, who->whox ? RPL_WHOSPCRPL : RPL_WHOREPLY, buf + 1);
}

static bool
_who_matches_oper_selection(const struct Client *source, const struct Client *target, const struct WhoQuery *who)
{
  if ((who->bitsel & WHOSELECT_OPER) == 0)
    return true;

  if (!client_is_oper(target))
    return false;

  if (user_mode_has_flag(target, UMODE_HIDDEN) && !client_is_oper(source))
    return false;

  return true;
}

/*!
 * \param source Pointer to client requesting who.
 * \param target Pointer to client to do who on.
 * \param mask Mask to match.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 * \return true if mask matches, false otherwise.
 */
static bool
_who_matches(struct Client *source, const struct Client *target,
             const char *mask, const struct WhoQuery *who)
{
  if (!_who_matches_oper_selection(source, target, who))
    return false;

  if (mask == NULL)
    return true;

  if ((who->matchsel & WHO_FIELD_NIC) && match(mask, target->name) == 0)
    return true;

  if ((who->matchsel & WHO_FIELD_UID) && match(mask, target->username) == 0)
    return true;

  if ((who->matchsel & WHO_FIELD_HOS))
  {
    if (match(mask, target->host) == 0)
      return true;
    if (client_is_oper(source) && match(mask, target->realhost) == 0)
      return true;
  }

  if ((who->matchsel & WHO_FIELD_REN) && match(mask, target->info) == 0)
    return true;

  if ((who->matchsel & WHO_FIELD_ACC) && client_has_account(target) && match(mask, target->account) == 0)
    return true;

  if ((who->matchsel & WHO_FIELD_NIP) && client_is_oper(source))
  {
    struct io_addr addr;
    int bits = 0;
    const int ret = address_parse_netmask(mask, &addr, &bits);

    if (ret == HM_IPV4 || ret == HM_IPV6)
      if (address_match(&target->addr, &addr, false, false, bits))
        return true;

    if (match(mask, target->sockhost) == 0)
      return true;
  }

  if ((who->matchsel & WHO_FIELD_SER))
    if (client_is_oper(source) || (ConfigServerHide.hide_servers == 0 && !client_is_hidden(target->uplink)))
      if (match(mask, target->uplink->name) == 0)
        return true;

  return false;
}

/*! \brief Lists matching clients on specified channel. Marks matched clients.
 * \param source Pointer to client requesting who.
 * \param channel Pointer to channel member chain.
 * \param mask Mask to match.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 */
static void
_who_on_common_channel(struct Client *source, struct Channel *channel,
                       const char *mask, struct WhoQuery *who)
{
  list_node_t *node;

  LIST_FOREACH(node, channel->member_list.head)
  {
    struct ChannelMember *const member = node->data;
    struct Client *const target = member->client;

    if (!user_mode_has_flag(target, UMODE_INVISIBLE) || client_has_flag(target, FLAGS_MARK))
      continue;

    client_set_flag(target, FLAGS_MARK);

    if (who->maxmatches)
    {
      if (_who_matches(source, target, mask, who))
      {
        _who_send(source, target, member, who);
        --who->maxmatches;
      }
    }
  }
}

/*! \brief Does a global scan of all clients looking for match.
 * \param source Pointer to client requesting who.
 * \param mask Mask to match.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 */
static void
_who_global(struct Client *source, const char *mask, struct WhoQuery *who)
{
  if (!client_is_oper(source))
  {
    static uintmax_t last_used = 0;
    if ((last_used + ConfigGeneral.pace_wait) > io_time_get(IO_TIME_MONOTONIC_SEC))
    {
      sendto_one_numeric(source, &me, RPL_LOAD2HI, "WHO");
      return;
    }

    last_used = io_time_get(IO_TIME_MONOTONIC_SEC);
  }

  /* First, list all matching invisible clients on common channels */
  list_node_t *node;
  LIST_FOREACH(node, source->channel_member_list.head)
  {
    struct ChannelMember *const member = node->data;
    _who_on_common_channel(source, member->channel, mask, who);
  }

  /* Second, list all matching visible clients */
  LIST_FOREACH(node, global_client_list.head)
  {
    struct Client *const target = node->data;
    assert(client_is_user(target));

    if (user_mode_has_flag(target, UMODE_INVISIBLE))
    {
      client_unset_flag(target, FLAGS_MARK);
      continue;
    }

    if (who->maxmatches)
    {
      if (_who_matches(source, target, mask, who))
      {
        _who_send(source, target, NULL, who);
        --who->maxmatches;
      }
    }
  }
}

/*! \brief Does a WHO on given channel.
 * \param source Pointer to client requesting who.
 * \param channel Pointer to channel to do who on.
 * \param who Pointer to struct WhoQuery item that defines the options for this query.
 */
static void
_who_on_channel(struct Client *source, struct Channel *channel, const struct WhoQuery *who)
{
  bool is_member = false;

  if (client_is_admin(source) || channel_member_find(channel, source))
    is_member = true;
  else if (channel_is_secret(channel))
    return;

  list_node_t *node;
  LIST_FOREACH(node, channel->member_list.head)
  {
    struct ChannelMember *const member = node->data;
    struct Client *const target = member->client;

    if (is_member || !user_mode_has_flag(target, UMODE_INVISIBLE))
    {
      if (!_who_matches_oper_selection(source, target, who))
        continue;

      _who_send(source, target, member, who);
    }
  }
}

static void
_who_dispatch_oper_spy_request(struct Client *source, const struct WhoQuery *who)
{
  if ((who->bitsel & WHOSELECT_OPER) == 0)
    return;

  hook_dispatch(ircd_hook_spy_request, &(ircd_hook_spy_request_ctx){
    .source = source,
    .command = "WHO",
    .selector = 'o'
  });
}

static void
_who_parse_selector(struct WhoQuery *who, char selector)
{
  switch (selector)
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
    default:
      break;
  }
}

static void
_who_parse_reply_field(struct WhoQuery *who, char field)
{
  switch (field)
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
    default:
      break;
  }
}

static const char *
_who_parse_query_token(const struct WhoQuery *who, char *token)
{
  if (token == NULL || (who->fields & WHO_FIELD_QTO) == 0)
    return NULL;

  char *p = token;
  unsigned int digits = 0;

  while (digits < 3 && *p >= '0' && *p <= '9')
  {
    ++p;
    ++digits;
  }

  *p = '\0';

  return digits > 0 ? token : NULL;
}

static void
_who_parse_options(struct WhoQuery *who, char *options)
{
  if (string_is_empty(options))
    return;

  char ch = '\0';
  char *p = options;

  while ((ch = *p++))
  {
    if (ch == '%' || ch == ',')
      break;

    _who_parse_selector(who, ch);
  }

  if (ch == '%')
  {
    who->whox = true;

    while ((ch = *p++))
    {
      if (ch == ',')
        break;

      _who_parse_reply_field(who, ch);
    }
  }

  if (ch == ',')
    who->token = _who_parse_query_token(who, p);
}

static bool
_who_handle_channel_query(struct Client *source, const char *mask, const struct WhoQuery *who)
{
  if (!channel_is_valid_prefix_char(*mask))
    return false;

  struct Channel *const channel = channel_find(mask);
  if (channel)
    _who_on_channel(source, channel, who);

  sendto_one_numeric(source, &me, RPL_ENDOFWHO, mask);
  return true;
}

static bool
_who_handle_nick_query(struct Client *source, const char *mask, const struct WhoQuery *who)
{
  if (who->matchsel && (who->matchsel & WHO_FIELD_NIC) == 0)
    return false;

  const struct Client *const target = client_find_user_by_name(mask);
  if (target == NULL)
    return false;

  if (_who_matches_oper_selection(source, target, who))
    _who_send(source, target, NULL, who);

  sendto_one_numeric(source, &me, RPL_ENDOFWHO, mask);
  return true;
}

/*! \brief WHO command handler
 *
 * \param source Pointer to allocated Client struct from which the message
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
m_who(struct Client *source, size_t parc, char *parv[])
{
  char *mask = parv[1];
  struct WhoQuery who = { .maxmatches = WHO_MAX_REPLIES };

  _who_parse_options(&who, parv[2]);

  _who_dispatch_oper_spy_request(source, &who);

 /* '/who #some_channel' */
  if (_who_handle_channel_query(source, mask, &who))
    return;

  /* '/who nick' */
  if (_who_handle_nick_query(source, mask, &who))
    return;

  collapse(mask);
  if (strcmp(mask, "0") == 0 ||
      strcmp(mask, "*") == 0)
    mask = NULL;

  if (who.matchsel == 0)
    who.matchsel = WHO_FIELD_DEF;

  _who_global(source, mask, &who);

  if (who.maxmatches == 0)
    sendto_one_numeric(source, &me, ERR_WHOLIMEXCEED, WHO_MAX_REPLIES, "WHO");
  sendto_one_numeric(source, &me, RPL_ENDOFWHO, string_or_default(mask, "*"));
}

static struct Command command_table =
{
  .name = "WHO",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_who, .args_min = 2 },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_who, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
  isupport_add("WHOX", NULL);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  isupport_delete("WHOX");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
