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

/*! \file user.c
 * \brief User related functions.
 */

#include "stdinc.h"
#include "io_time.h"
#include "defaults.h"
#include "list.h"
#include "user.h"
#include "cap.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "cloak.h"
#include "hash.h"
#include "id.h"
#include "irc_string.h"
#include "ircd.h"
#include "listener.h"
#include "motd.h"
#include "numeric.h"
#include "conf.h"
#include "conf_gecos.h"
#include "log.h"
#include "server.h"
#include "send.h"
#include "memory.h"
#include "rng_mt.h"
#include "misc.h"
#include "parse.h"
#include "monitor.h"
#include "isupport.h"
#include "tls.h"

static char umode_buffer[UMODE_MAX_STR];

const struct user_modes *umode_map[256];
const struct user_modes  umode_tab[] =
{
  { 'B', UMODE_BOT          },
  { 'D', UMODE_DEAF         },
  { 'F', UMODE_FARCONNECT   },
  { 'G', UMODE_SOFTCALLERID },
  { 'H', UMODE_HIDDEN       },
  { 'X', UMODE_EXPIRATION   },
  { 'R', UMODE_REGONLY      },
  { 'S', UMODE_SECURE       },
  { 'W', UMODE_WEBIRC       },
  { 'Z', UMODE_SECUREONLY   },
  { 'a', UMODE_ADMIN        },
  { 'c', UMODE_CCONN        },
  { 'e', UMODE_EXTERNAL     },
  { 'f', UMODE_FLOOD        },
  { 'g', UMODE_CALLERID     },
  { 'i', UMODE_INVISIBLE    },
  { 'j', UMODE_REJ          },
  { 'k', UMODE_SKILL        },
  { 'l', UMODE_LOCOPS       },
  { 'n', UMODE_NCHANGE      },
  { 'o', UMODE_OPER         },
  { 'p', UMODE_HIDECHANS    },
  { 'q', UMODE_HIDEIDLE     },
  { 'r', UMODE_REGISTERED   },
  { 's', UMODE_SERVNOTICE   },
  { 'w', UMODE_WALLOP       },
  { 'x', UMODE_CLOAK        },
  { 'y', UMODE_SPY          },
  { 'z', UMODE_SECURE       },
  { '\0', 0 }
};

void
user_modes_init(void)
{
  char *umode_buffer_ptr = umode_buffer;

  for (const struct user_modes *tab = umode_tab; tab->c; ++tab)
  {
    umode_map[tab->c] = tab;
    *umode_buffer_ptr++ = tab->c;
  }

  *umode_buffer_ptr = '\0';
}

/* show_lusers()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - display to client user counts etc.
 */
void
show_lusers(struct Client *client)
{
  if (ConfigServerHide.hide_servers == 0 || HasUMode(client, UMODE_OPER))
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

  if (ConfigServerHide.hide_servers == 0 || HasUMode(client, UMODE_OPER))
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

/* report_and_set_user_flags()
 *
 * inputs       - pointer to client
 *              - pointer to conf for this user
 * output       - NONE
 * side effects - Report to user any special flags
 *                they are getting, and set them.
 */
static void
report_and_set_user_flags(struct Client *client, const struct MaskItem *conf)
{
  /* If this user is being spoofed, tell them so */
  if (IsConfDoSpoofIp(conf))
    sendto_one_notice(client, &me, ":*** Spoofing your IP");

  /* If this user is in the exception class, set it "E lined" */
  if (IsConfExemptKline(conf))
  {
    AddFlag(client, FLAGS_EXEMPTKLINE);
    sendto_one_notice(client, &me, ":*** You are exempt from K/D lines");
  }

  if (IsConfExemptXline(conf))
  {
    AddFlag(client, FLAGS_EXEMPTXLINE);
    sendto_one_notice(client, &me, ":*** You are exempt from X lines");
  }

  if (IsConfExemptResv(conf))
  {
    AddFlag(client, FLAGS_EXEMPTRESV);
    sendto_one_notice(client, &me, ":*** You are exempt from resvs");
  }

  /* If this user is exempt from user limits set it "F lined" */
  if (IsConfExemptLimits(conf))
  {
    AddFlag(client, FLAGS_NOLIMIT);
    sendto_one_notice(client, &me, ":*** You are exempt from user limits");
  }

  if (IsConfCanFlood(conf))
  {
    AddFlag(client, FLAGS_CANFLOOD);
    sendto_one_notice(client, &me, ":*** You are exempt from flood protection");
  }
}

/* introduce_client()
 *
 * inputs       - client
 * output       - NONE
 * side effects - This common function introduces a client to the rest
 *                of the net, either from a local client connect or
 *                from a remote connect.
 */
static void
user_introduce(struct Client *client)
{
  monitor_signon(client);

  sendto_servers(client, 0, 0, ":%s UID %s %u %ju %s %s %s %s %s %s %s :%s",
                 client->servptr->id, client->name, client->hopcount + 1,
                 client->tsinfo, user_get_mode_str(client->umodes),
                 client->username, client->host, client->realhost,
                 client->sockhost, client->id, client->account, client->info);

  if (!EmptyString(client->tls_certfp))
    sendto_servers(client, 0, 0, ":%s CERTFP %s", client->id, client->tls_certfp);

  if (!EmptyString(client->tls_cipher))
    sendto_servers(client, 0, 0, ":%s METADATA client %s cipher :%s",
                   client->servptr->id, client->id, client->tls_cipher);
}

/* user_welcome()
 *
 * inputs       - client pointer to client to welcome
 * output       - NONE
 * side effects -
 */
static void
user_welcome(struct Client *client)
{
#ifdef AX_BUILD_DATE
  static const char built_date[] = AX_BUILD_DATE;
#else
  static const char built_date[] = __DATE__ " at " __TIME__;
#endif

  if (HasFlag(client, FLAGS_TLS))
  {
    AddUMode(client, UMODE_SECURE);

    client->tls_cipher = io_strdup(tls_get_cipher(&client->connection->fd->tls));
    sendto_one_notice(client, &me, ":*** Connected securely via %s",
                      client->tls_cipher);

    if (!EmptyString(client->tls_certfp))
      sendto_one_notice(client, &me, ":*** Your client certificate fingerprint is %s",
                        client->tls_certfp);
  }

  sendto_one_numeric(client, &me, RPL_WELCOME, ConfigServerInfo.network_name,
                     client->name, client->username, client->realhost);
  sendto_one_numeric(client, &me, RPL_YOURHOST,
                     listener_get_name(client->connection->listener), IRCD_VERSION);
  sendto_one_numeric(client, &me, RPL_CREATED, built_date);
  sendto_one_numeric(client, &me, RPL_MYINFO, me.name, IRCD_VERSION, umode_buffer,
                     cmode_rpl04[0], cmode_rpl04[1]);

  isupport_show(client);
  show_lusers(client);
  motd_signon(client);
}

/*! \brief This function is called when both NICK and USER messages
 *      have been accepted for the client, in whatever order. Only
 *      after this, is the UID message propagated.
 * \param client Pointer to given client to introduce
 */
void
user_register_local(struct Client *client)
{
  assert(client == client->from);
  assert(client->connection->registration == 0);
  assert(MyConnect(client));
  assert(IsUnknown(client));
  assert(list_find(&unknown_list, client));

  if (ConfigGeneral.ping_cookie)
  {
    if (!HasFlag(client, FLAGS_PINGSENT) && client->connection->random_ping == 0)
    {
      do
        client->connection->random_ping = genrand_int32();
      while (client->connection->random_ping == 0);

      sendto_one(client, "PING :%u", client->connection->random_ping);
      AddFlag(client, FLAGS_PINGSENT);
      return;
    }

    if (!HasFlag(client, FLAGS_PING_COOKIE))
      return;
  }

  if (conf_check_client(client) == false)
    return;

  const struct MaskItem *const conf = client->connection->confs.head->data;
  if (IsNeedIdentd(conf) && !HasFlag(client, FLAGS_GOTID))
  {
    sendto_one_notice(client, &me, ":*** Notice -- You need to install identd to use this server");
    client_exit(client, "Install identd");
    ++ServerStats.is_ref;
    return;
  }

  if (valid_username(client->username, true) == false)
  {
    sendto_clients(UMODE_REJ, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Invalid username: %s (%s@%s)",
                   client->name, client->username, client->host);
    client_exit_fmt(client, "Invalid username [%s]", client->username);
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
  if (list_length(&local_client_list) >= max_clients)
  {
    sendto_clients(UMODE_REJ, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Too many clients, rejecting %s[%s].",
                   client->name, client->host);
    client_exit(client, "Sorry, server is full - try later");
    ++ServerStats.is_ref;
    return;
  }

  if (!IsConfExemptXline(conf))
  {
    const struct GecosItem *gecos = gecos_find(client->info, match);
    if (gecos)
    {
      sendto_clients(UMODE_REJ, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "X-line Rejecting [%s] [%s], user %s [%s]",
                     client->info, gecos->reason, client_get_name(client, HIDE_IP), client->sockhost);
      client_exit(client, "Bad user info");
      ++ServerStats.is_ref;
      return;
    }
  }

  /* Password check */
  if (!EmptyString(conf->passwd))
  {
    if (match_conf_password(client->connection->password, conf) == false)
    {
      sendto_one_numeric(client, &me, ERR_PASSWDMISMATCH);
      client_exit(client, "Bad Password");
      ++ServerStats.is_ref;
      return;
    }
  }

  io_free(client->connection->password);
  client->connection->password = NULL;

  const char *id;
  while (hash_find_id((id = uid_get())))
    ;

  strlcpy(client->id, id, sizeof(client->id));
  hash_add_id(client);

  sendto_clients(UMODE_CCONN, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Client connecting: %s (%s@%s) [%s] {%s} [%s] <%s>",
                 client->name, client->username, client->realhost, client->sockhost,
                 class_get_name(&client->connection->confs), client->info, client->id);

  if (ConfigGeneral.invisible_on_connect)
  {
    AddUMode(client, UMODE_INVISIBLE);
    ++Count.invisi;
  }

  SetClient(client);

  client->servptr = &me;
  client->connection->last_privmsg = io_time_get(IO_TIME_MONOTONIC_SEC);

  list_add(client, &client->lnode, &client->servptr->serv->client_list);
  list_add(client, &client->node, &global_client_list);
  list_move_node(&client->connection->node, &unknown_list, &local_client_list);

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

  /*
   * Report if user has &^>= etc. and set flags as needed in client
   */
  report_and_set_user_flags(client, conf);

  user_welcome(client);

  if (!HasFlag(client, FLAGS_SPOOF))
  {
    const char *const cloak = cloak_compute(&client->addr);
    if (cloak)
    {
      user_set_hostmask(client, cloak, false);
      AddUMode(client, UMODE_CLOAK);
    }
  }

  send_umode(client, 0, true, false);
  user_introduce(client);
}

/* register_remote_user()
 *
 * inputs       - client remote or directly connected client
 *              - username to register as
 *              - host name to register as
 *              - server name
 * output	- NONE
 * side effects	- This function is called when a remote client
 *		  is introduced by a server.
 */
void
user_register_remote(struct Client *client)
{
  assert(client->servptr->from == client->from);

  /*
   * If the nick has been introduced by a services server,
   * make it a service as well.
   */
  if (HasFlag(client->servptr, FLAGS_SERVICE))
    AddFlag(client, FLAGS_SERVICE);

  SetClient(client);
  list_add(client, &client->lnode, &client->servptr->serv->client_list);
  list_add(client, &client->node, &global_client_list);

  if (list_length(&global_client_list) > Count.max_tot)
    Count.max_tot = list_length(&global_client_list);

  if (HasFlag(client->servptr, FLAGS_EOB))
    sendto_clients(UMODE_FARCONNECT, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Client connecting at %s: %s (%s@%s) [%s] [%s] <%s>",
                   client->servptr->name, client->name, client->username, client->realhost,
                   client->sockhost, client->info, client->id);

  user_introduce(client);
}

/* valid_hostname()
 *
 * Inputs       - pointer to hostname
 * Output       - 1 if valid, 0 if not
 * Side effects - check hostname for validity
 *
 * NOTE: this doesn't allow a hostname to begin with a dot and
 * will not allow more dots than chars.
 */
bool
valid_hostname(const char *hostname)
{
  const char *p = hostname;

  assert(p);

  if (EmptyString(p) || *p == '.' || *p == ':')
    return false;

  for (; *p; ++p)
    if (!IsHostChar(*p))
      return false;

  return p - hostname <= HOSTLEN;
}

/* valid_username()
 *
 * Inputs       - pointer to user
 * Output       - 1 if valid, 0 if not
 * Side effects - check username for validity
 *
 * Absolutely always reject any '*' '!' '?' '@' in an user name
 * reject any odd control characters names.
 * Allow '.' in username to allow for "first.last"
 * style of username
 */
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

/* clean_nick_name()
 *
 * input        - nickname
 *              - whether it's a local nick (1) or remote (0)
 * output       - none
 * side effects - walks through the nickname, returning 0 if erroneous
 */
bool
valid_nickname(const char *nickname, bool local)
{
  const char *p = nickname;

  assert(p);

  /*
   * Nicks can't start with a digit or - or be 0 length.
   */
  if (EmptyString(p) || *p == '-' || (IsDigit(*p) && local))
    return false;

  for (; *p; ++p)
    if (!IsNickChar(*p))
      return false;

  return p - nickname <= NICKLEN;
}

/*! \brief Builds a mode change string to buffer pointed by \a buf
 * \param client  Pointer to client
 * \param send    Whether to send a MODE message to client
 * \param old     Old user mode to compare against when building new mode buffer
 */
void
send_umode(struct Client *client, unsigned int old, bool send_client, bool send_server)
{
  /*
   * If the client's current user modes match the old modes, indicating no change,
   * simply return without further processing.
   */
  if (client->umodes == old)
    return;

  char buf[UMODE_MAX_STR];
  char *m = buf;
  int what = MODE_NONE;

  /*
   * Construct a string in the 'buf' array to represent the modifications in the user's mode
   * between the current modes (client->umodes) and the provided 'old' modes.
   */
  for (const struct user_modes *tab = umode_tab; tab->c; ++tab)
  {
    if ((tab->flag & old) && !HasUMode(client, tab->flag))
    {
      if (what == MODE_DEL)
        *m++ = tab->c;
      else
      {
        what = MODE_DEL;
        *m++ = '-';
        *m++ = tab->c;
      }
    }
    else if (!(tab->flag & old) && HasUMode(client, tab->flag))
    {
      if (what == MODE_ADD)
        *m++ = tab->c;
      else
      {
        what = MODE_ADD;
        *m++ = '+';
        *m++ = tab->c;
      }
    }
  }

  *m = '\0';
  assert(buf[0] != '\0');

  if (send_client)
    sendto_one(client, ":%s!%s@%s MODE %s :%s",
               client->name, client->username, client->host, client->name, buf);
  if (send_server)
    sendto_servers(client, 0, 0, ":%s MODE %s :%s",
                   client->id, client->id, buf);
}

const char *
user_get_mode_str(unsigned int modes)
{
  static char buf[UMODE_MAX_STR];
  char *m = buf;

  *m++ = '+';
  for (const struct user_modes *tab = umode_tab; tab->c; ++tab)
    if (modes &tab->flag)
      *m++ = tab->c;
  *m = '\0';

  return buf;
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
                               client->name, client->username,
                               client->host, client->username, hostname);

  strlcpy(client->host, hostname, sizeof(client->host));

  if (svshost)
    sendto_servers(client, 0, 0, ":%s SVSHOST %s %ju %s",
                   client->servptr->id, client->id, client->tsinfo, client->host);

  if (MyConnect(client))
  {
    sendto_one_numeric(client, &me, RPL_VISIBLEHOST, client->host);
    clear_ban_cache_list(&client->channel);
  }

  if (ConfigGeneral.cycle_on_host_change == 0)
    return;

  list_node_t *node;
  LIST_FOREACH(node, client->channel.head)
  {
    char nickbuf[CMEMBER_STATUS_FLAGS_LEN * NICKLEN + CMEMBER_STATUS_FLAGS_LEN] = "";
    char modebuf[CMEMBER_STATUS_FLAGS_LEN + 1];
    char *p = modebuf;
    int len = 0;
    const struct ChannelMember *member = node->data;

    for (const struct chan_mode *tab = cflag_tab; tab->letter; ++tab)
    {
      if (member_has_flags(member, tab->flag))
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
                           client->servptr->name, member->channel->name, modebuf, nickbuf);
  }

  if (client->away[0])
    sendto_common_channels_local(client, false, CAP_AWAY_NOTIFY, CAP_CHGHOST, ":%s!%s@%s AWAY :%s",
                                 client->name, client->username, client->host, client->away);
}
