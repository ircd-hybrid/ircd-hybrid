/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file user.c
 * \brief User related functions.
 */

#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "event.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "misc.h"
#include "rng_mt.h"
#include "tls.h"

#include "cap.h"
#include "channel.h"
#include "channel_member.h"
#include "channel_mode.h"
#include "client.h"
#include "client_format.h"
#include "client_id.h"
#include "client_input.h"
#include "cloak.h"
#include "conf.h"
#include "conf_gecos.h"
#include "defaults.h"
#include "hash.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "isupport.h"
#include "monitor.h"
#include "motd.h"
#include "numeric.h"
#include "packet.h"
#include "parse.h"
#include "send.h"
#include "user.h"
#include "user_mode.h"

void
show_lusers(struct Client *client)
{
  if (ConfigServerHide.hide_servers == 0 || client_is_oper(client))
    sendto_one_numeric(client, &me, RPL_LUSERCLIENT, (list_length(&global_client_list) - Count.invisi),
                       Count.invisi, list_length(&global_server_list));
  else
    sendto_one_numeric(client, &me, RPL_LUSERCLIENT, (list_length(&global_client_list) - Count.invisi),
                       Count.invisi, 1);

  if (Count.oper)
    sendto_one_numeric(client, &me, RPL_LUSEROP, Count.oper);

  if (list_length(&unknown_list))
    sendto_one_numeric(client, &me, RPL_LUSERUNKNOWN, list_length(&unknown_list));

  if (list_length(channel_get_list()))
    sendto_one_numeric(client, &me, RPL_LUSERCHANNELS, list_length(channel_get_list()));

  if (ConfigServerHide.hide_servers == 0 || client_is_oper(client))
  {
    sendto_one_numeric(client, &me, RPL_LUSERME, list_length(&local_client_list), list_length(&local_server_list));
    sendto_one_numeric(client, &me, RPL_LOCALUSERS, list_length(&local_client_list), Count.max_loc);
    sendto_one_numeric(client, &me, RPL_GLOBALUSERS, list_length(&global_client_list), Count.max_tot);
    sendto_one_numeric(client, &me, RPL_STATSCONN, Count.max_loc_con, Count.max_loc, Count.totalrestartcount);
  }
  else
  {
    sendto_one_numeric(client, &me, RPL_LUSERME, list_length(&global_client_list), 0);
    sendto_one_numeric(client, &me, RPL_LOCALUSERS, list_length(&global_client_list), Count.max_tot);
    sendto_one_numeric(client, &me, RPL_GLOBALUSERS, list_length(&global_client_list), Count.max_tot);
  }
}

static void
report_and_set_user_flags(struct Client *client, const struct MaskItem *conf)
{
  /* If this user is being spoofed, tell them so */
  if (IsConfDoSpoofIp(conf))
    sendto_one_notice(client, &me, ":*** Spoofing your IP");

  /* If this user is in the exception class, set it "E lined" */
  if (IsConfExemptKline(conf))
  {
    client_set_flag(client, FLAGS_EXEMPTKLINE);
    sendto_one_notice(client, &me, ":*** You are exempt from K/D lines");
  }

  if (IsConfExemptXline(conf))
  {
    client_set_flag(client, FLAGS_EXEMPTXLINE);
    sendto_one_notice(client, &me, ":*** You are exempt from X lines");
  }

  if (IsConfExemptResv(conf))
  {
    client_set_flag(client, FLAGS_EXEMPTRESV);
    sendto_one_notice(client, &me, ":*** You are exempt from resvs");
  }

  /* If this user is exempt from user limits set it "F lined" */
  if (IsConfExemptLimits(conf))
  {
    client_set_flag(client, FLAGS_NOLIMIT);
    sendto_one_notice(client, &me, ":*** You are exempt from user limits");
  }

  if (IsConfCanFlood(conf))
  {
    client_set_flag(client, FLAGS_CANFLOOD);
    sendto_one_notice(client, &me, ":*** You are exempt from flood protection");
  }
}

static void
user_introduce(struct Client *client)
{
  client_set_flag(client, FLAGS_INTRODUCED);

  sendto_servers(client, 0, 0, ":%s UID %s %u %ju %s %s %s %s %s %s %s :%s",
                 client->uplink->id, client->name, client->hopcount + 1,
                 client->nick_timestamp, user_mode_to_str(client->user_mode_flags),
                 client->username, client->host, client->realhost,
                 client->sockhost, client->id, client->account, client->info);

  if (!string_is_empty(client->tls_certfp))
    sendto_servers(client, 0, 0, ":%s CERTFP %s", client->id, client->tls_certfp);

  if (!string_is_empty(client->tls_cipher))
    sendto_servers(client, 0, 0, ":%s METADATA client %s cipher :%s",
                   client->uplink->id, client->id, client->tls_cipher);

  monitor_notify_signon(client);
}

static void
user_welcome(struct Client *client)
{
#ifdef AX_BUILD_DATE
  static const char built_date[] = AX_BUILD_DATE;
#else
  static const char built_date[] = __DATE__ " at " __TIME__;
#endif

  if (client_has_flag(client, FLAGS_TLS_ACTIVE))
  {
    user_mode_set_flag(client, UMODE_SECURE);

    client->tls_cipher = io_strdup(tls_get_cipher(&client->connection->fde->tls));
    sendto_one_notice(client, &me, ":*** Connected securely via %s",
                      client->tls_cipher);

    if (!string_is_empty(client->tls_certfp))
      sendto_one_notice(client, &me, ":*** Your client certificate fingerprint is %s",
                        client->tls_certfp);
  }

  sendto_one_numeric(client, &me, RPL_WELCOME,
                     ConfigServerInfo.network_name, client->name, client->username, client->realhost);
  sendto_one_numeric(client, &me, RPL_YOURHOST, me.name, IRCD_VERSION);
  sendto_one_numeric(client, &me, RPL_CREATED, built_date);
  sendto_one_numeric(client, &me, RPL_MYINFO,
                     me.name, IRCD_VERSION, user_mode_get_string(), cmode_rpl04[0], cmode_rpl04[1]);

  isupport_show(client);
  show_lusers(client);
  motd_signon(client);
}

static void
_user_register_report_rejection(struct Client *client, const char *reason_format, ...)
{
  char reason[IRCD_BUFSIZE];

  va_list args;
  va_start(args, reason_format);
  vsnprintf(reason, sizeof(reason), reason_format, args);
  va_end(args);

  client_format_name_buffer_t client_name_buffer;
  sendto_clients(UMODE_REJ, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Client registration rejected: %s (%s)",
                 client_format_name(client, CLIENT_FORMAT_NAME_PUBLIC, &client_name_buffer), reason);
}

static void
_user_register_reject_authorization(struct Client *client, enum conf_authorize_result result,
                                    const char *failure_reason)
{
  assert(result != CONF_AUTHORIZE_SUCCESS);

  if (string_is_empty(failure_reason))
    failure_reason = "unknown reason";

  if (result == CONF_AUTHORIZE_PASSWORD_MISMATCH)
    sendto_one_numeric(client, &me, ERR_PASSWDMISMATCH);

  _user_register_report_rejection(client, "authorization failed: %s",
                                  failure_reason);

  client_exit_fmt(client, "Connection rejected - %s", failure_reason);
  ++ServerStats.is_ref;
}

/*! \brief This function is called when both NICK and USER messages
 *      have been accepted for the client, in whatever order. Only
 *      after this, is the UID message propagated.
 * \param client Pointer to given client to introduce
 */
void
user_register_local(struct Client *client)
{
  assert(client == client->nexthop);
  assert(client->connection->registration_flags == 0);
  assert(client_is_local(client));
  assert(client_is_unknown(client));
  assert(list_find(&unknown_list, client));
  assert(list_find(&local_client_list, client) == NULL);

  if (ConfigGeneral.ping_cookie)
  {
    if (client->connection->ping_cookie_token == 0)
    {
      do
        client->connection->ping_cookie_token = genrand_int32();
      while (client->connection->ping_cookie_token == 0);

      sendto_one(client, "PING :%u", client->connection->ping_cookie_token);
      return;  /* Wait for the PONG reply. */
    }

    if (!client_has_flag(client, FLAGS_PING_COOKIE))
      return;
  }

  enum conf_authorize_result authorize_result = CONF_AUTHORIZE_SUCCESS;
  const char *authorize_failure_reason = NULL;
  const struct MaskItem *const conf =
    conf_authorize_client(client, &authorize_result, &authorize_failure_reason);
  if (conf == NULL)
  {
    _user_register_reject_authorization(client, authorize_result, authorize_failure_reason);
    return;
  }

  if (!valid_username(client->username, true))
  {
    _user_register_report_rejection(client, "invalid username: \"%s\"",
                                    client->username);

    client_exit(client, "Invalid username");
    ++ServerStats.is_ref;
    return;
  }

  /*
   * Limit clients -
   * We want to be able to have servers and F-line clients
   * connect, so save room for "buffer" connections.
   * Smaller servers may want to decrease this, and it should
   * probably be just a percentage of the MAXCLIENTS...
   *   -Taner
   */
  unsigned int max_clients = GlobalSetOptions.maxclients;
  if (IsConfExemptLimits(conf))
    max_clients += MAX_BUFFER;

  const unsigned int local_client_count = list_length(&local_client_list);
  if (local_client_count >= max_clients)
  {
    _user_register_report_rejection(client, "server is full: %u/%u local clients",
                                    local_client_count, max_clients);

    client_exit(client, "Server is full - try again later");
    ++ServerStats.is_ref;
    return;
  }

  if (!IsConfExemptXline(conf))
  {
    const struct GecosItem *const gecos = gecos_find(client->info, match);
    if (gecos)
    {
      _user_register_report_rejection(client,
                                      "X-line match: realname=\"%s\", reason=\"%s\", ip=\"%s\"",
                                      client->info, gecos->reason, client->sockhost);

      client_exit(client, "Bad user information");
      ++ServerStats.is_ref;
      return;
    }
  }

  if (!client_id_allocate_uid(client))
  {
    client_exit(client, "Local client ID generator exhausted");
    ++ServerStats.is_ref;
    return;
  }

  hash_add_id(client);

  hook_dispatch(ircd_hook_user_register_local, &(ircd_hook_user_register_ctx){ .client = client });

  client_set_state(client, CLIENT_STATE_USER);
  client_update_activity_timeout(client);

  client->connection->last_privmsg_time = io_time_get(IO_TIME_MONOTONIC_SEC);

  assert(client->connection->flood_recalc_event == NULL);
  client->connection->flood_recalc_event =
    event_create(ircd_event_manager, "client_input_flood_recalc", client_input_flood_recalc, 1000, false, client, NULL);
  event_set_priority(client->connection->flood_recalc_event, 2);
  event_schedule(client->connection->flood_recalc_event);

  list_add(client, &client->global_node, &global_client_list);
  list_add(client, &client->uplink_node, &client->uplink->server->child_user_list);
  list_move_node(&client->connection->node, &local_client_list, &unknown_list);

  if (list_length(&local_client_list) > Count.max_loc)
  {
    Count.max_loc = list_length(&local_client_list);

    if (!(Count.max_loc % 10))
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "New peak in local client connections: %u",
                     Count.max_loc);
  }

  if ((list_length(&local_client_list) + list_length(&local_server_list)) > Count.max_loc_con)
    Count.max_loc_con = list_length(&local_client_list) + list_length(&local_server_list);

  if (list_length(&global_client_list) > Count.max_tot)
    Count.max_tot = list_length(&global_client_list);
  ++Count.totalrestartcount;

  if (ConfigGeneral.invisible_on_connect)
    user_mode_set_flag_exec(client, UMODE_INVISIBLE, USER_MODE_SOURCE_REGULAR);

  /*
   * Report if user has &^>= etc. and set flags as needed in client
   */
  report_and_set_user_flags(client, conf);

  user_welcome(client);

  user_mode_set_flag_exec(client, UMODE_CLOAK, USER_MODE_SOURCE_REGULAR);

  user_mode_send(client, 0, USER_MODE_SEND_USER);

  user_introduce(client);
}

void
user_register_remote(struct Client *client)
{
  assert(client->uplink->nexthop == client->nexthop);

  /*
   * If the nick has been introduced by a services server,
   * make it a service as well.
   */
  if (client_is_service(client->uplink))
    client_set_flag(client, FLAGS_SERVICE);

  client_set_state(client, CLIENT_STATE_USER);

  list_add(client, &client->global_node, &global_client_list);
  list_add(client, &client->uplink_node, &client->uplink->server->child_user_list);

  if (list_length(&global_client_list) > Count.max_tot)
    Count.max_tot = list_length(&global_client_list);

  hook_dispatch(ircd_hook_user_register_remote, &(ircd_hook_user_register_ctx){ .client = client });

  user_introduce(client);
}

bool
valid_hostname(const char *hostname)
{
  const char *p = hostname;

  assert(p);

  if (string_is_empty(p) || *p == '.' || *p == ':')
    return false;

  for (; *p; ++p)
    if (!IsHostChar(*p))
      return false;

  return p - hostname <= HOSTLEN;
}

bool
valid_username(const char *username, bool local)
{
  const char *p = username;

  assert(p);

  if (*p == '~')
    ++p;

  /*
   * Reject usernames that don't start with an alphanum
   * i.e. reject jokers who have '-@somehost' or '.@somehost'
   * or "-hi-@somehost", "h-----@somehost" would still be accepted.
   */
  if (!IsAlNum(*p))
    return false;

  if (local)
  {
    unsigned int special = 0;

    while (*p)
    {
      if (*p == '-' || *p == '_' || *p == '.')
      {
        if (ConfigGeneral.specials_in_ident < ++special)
          return false;
      }
      else if (!IsUser2Char(*p))
        return false;

      ++p;
    }
  }
  else
  {
    while (*++p)
      if (!IsUserChar(*p))
        return false;
  }

  return p - username <= USERLEN;
}

bool
valid_nickname(const char *nickname, bool local)
{
  const char *p = nickname;

  assert(p);

  if (string_is_empty(p) || *p == '-' || (local && IsDigit(*p)))
    return false;

  for (; *p; ++p)
    if (!IsNickChar(*p))
      return false;

  return p - nickname <= NICKLEN;
}

void
user_set_hostmask(struct Client *client, const char *hostname, bool svshost)
{
  if (strcmp(client->host, hostname) == 0)
    return;

  if (ConfigGeneral.cycle_on_host_change)
    sendto_common_channels_local(client, false, 0, CAP_CHGHOST, ":%s!%s@%s QUIT :Changing hostname",
                                 client->name, client->username, client->host);

  sendto_common_channels_local(client, true, CAP_CHGHOST, 0, ":%s!%s@%s CHGHOST %s %s",
                               client->name, client->username, client->host, client->username, hostname);

  strlcpy(client->host, hostname, sizeof(client->host));

  if (svshost)
    sendto_servers(client, 0, 0, ":%s SVSHOST %s 0 %s",
                   client->uplink->id, client->id, client->host);

  if (client_is_local(client))
  {
    sendto_one_numeric(client, &me, RPL_VISIBLEHOST, client->host);
    clear_ban_cache_list(&client->channel_member_list);
  }

  if (ConfigGeneral.cycle_on_host_change == 0)
    return;

  list_node_t *node;
  LIST_FOREACH(node, client->channel_member_list.head)
  {
    char nickbuf[CMEMBER_STATUS_FLAGS_LEN * NICKLEN + CMEMBER_STATUS_FLAGS_LEN] = "";
    char modebuf[CMEMBER_STATUS_FLAGS_LEN + 1];
    char *p = modebuf;
    int len = 0;
    const struct ChannelMember *const member = node->data;

    for (const struct chan_mode *tab = cflag_tab; tab->letter; ++tab)
    {
      if (channel_member_has_flags(member, tab->flag))
      {
        *p++ = tab->letter;
        len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", client->name);
      }
    }

    *p = '\0';

    sendto_channel_local(client, member->channel, 0, CAP_EXTENDED_JOIN, CAP_CHGHOST, ":%s!%s@%s JOIN %s %s :%s",
                         client->name, client->username, client->host, member->channel->name,
                         client->account, client->info);
    sendto_channel_local(client, member->channel, 0, 0, CAP_EXTENDED_JOIN | CAP_CHGHOST, ":%s!%s@%s JOIN :%s",
                         client->name, client->username, client->host, member->channel->name);

    if (nickbuf[0])
      sendto_channel_local(client, member->channel, 0, 0, CAP_CHGHOST, ":%s MODE %s +%s %s",
                           client->uplink->name, member->channel->name, modebuf, nickbuf);
  }

  if (client->away_message)
    sendto_common_channels_local(client, false, CAP_AWAY_NOTIFY, CAP_CHGHOST, ":%s!%s@%s AWAY :%s",
                                 client->name, client->username, client->host, client->away_message);
}
