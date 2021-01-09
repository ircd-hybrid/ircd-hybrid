/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2021 ircd-hybrid development team
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
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "user.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
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
#include "packet.h"
#include "rng_mt.h"
#include "misc.h"
#include "parse.h"
#include "monitor.h"
#include "isupport.h"
#include "tls.h"
#include "patchlevel.h"

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
  { 'a', UMODE_ADMIN        },
  { 'c', UMODE_CCONN        },
  { 'd', UMODE_DEBUG        },
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
  { 'y', UMODE_SPY          },
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
    sendto_one_numeric(client, &me, RPL_LUSERCLIENT, (dlink_list_length(&global_client_list) - Count.invisi),
                       Count.invisi, dlink_list_length(&global_server_list));
  else
    sendto_one_numeric(client, &me, RPL_LUSERCLIENT, (dlink_list_length(&global_client_list) - Count.invisi),
                       Count.invisi, 1);

  if (Count.oper)
    sendto_one_numeric(client, &me, RPL_LUSEROP, Count.oper);

  if (dlink_list_length(&unknown_list))
    sendto_one_numeric(client, &me, RPL_LUSERUNKNOWN, dlink_list_length(&unknown_list));

  if (dlink_list_length(channel_get_list()))
    sendto_one_numeric(client, &me, RPL_LUSERCHANNELS, dlink_list_length(channel_get_list()));

  if (ConfigServerHide.hide_servers == 0 || HasUMode(client, UMODE_OPER))
  {
    sendto_one_numeric(client, &me, RPL_LUSERME, dlink_list_length(&local_client_list), dlink_list_length(&local_server_list));
    sendto_one_numeric(client, &me, RPL_LOCALUSERS, dlink_list_length(&local_client_list), Count.max_loc);
    sendto_one_numeric(client, &me, RPL_GLOBALUSERS, dlink_list_length(&global_client_list), Count.max_tot);
    sendto_one_numeric(client, &me, RPL_STATSCONN, Count.max_loc_con, Count.max_loc, Count.totalrestartcount);
  }
  else
  {
    sendto_one_numeric(client, &me, RPL_LUSERME, dlink_list_length(&global_client_list), 0);
    sendto_one_numeric(client, &me, RPL_LOCALUSERS, dlink_list_length(&global_client_list), Count.max_tot);
    sendto_one_numeric(client, &me, RPL_GLOBALUSERS, dlink_list_length(&global_client_list), Count.max_tot);
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
introduce_client(struct Client *client)
{
  char buf[UMODE_MAX_STR] = "";

  send_umode(client, MyConnect(client), 0, buf);
  monitor_signon(client);

  if (buf[0] == '\0')
  {
    buf[0] = '+';
    buf[1] = '\0';
  }

  sendto_server(client, 0, 0, ":%s UID %s %u %ju %s %s %s %s %s %s %s :%s",
                client->servptr->id, client->name, client->hopcount + 1,
                client->tsinfo, buf, client->username, client->host,
                client->realhost, client->sockhost, client->id,
                client->account, client->info);

  if (!EmptyString(client->tls_certfp))
    sendto_server(client, 0, 0, ":%s CERTFP %s", client->id, client->tls_certfp);
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
  static const char built_date[] = __DATE__ " at " __TIME__;

  if (HasFlag(client, FLAGS_TLS))
  {
    AddUMode(client, UMODE_SECURE);

    client->tls_cipher = xstrdup(tls_get_cipher(&client->connection->fd->tls));
    sendto_one_notice(client, &me, ":*** Connected securely via %s",
                      client->tls_cipher);
  }

  sendto_one_numeric(client, &me, RPL_WELCOME, ConfigServerInfo.network_name,
                     client->name, client->username, client->realhost);
  sendto_one_numeric(client, &me, RPL_YOURHOST,
                     listener_get_name(client->connection->listener), PATCHLEVEL);
  sendto_one_numeric(client, &me, RPL_CREATED, built_date);
  sendto_one_numeric(client, &me, RPL_MYINFO, me.name, PATCHLEVEL, umode_buffer);

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
register_local_user(struct Client *client)
{
  const struct MaskItem *conf = NULL;

  assert(client == client->from);
  assert(client->connection->registration == 0);
  assert(MyConnect(client));
  assert(IsUnknown(client));

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

  conf = client->connection->confs.head->data;

  if (!HasFlag(client, FLAGS_GOTID))
  {
    char username[USERLEN + 1];
    unsigned int i = 0;

    if (IsNeedIdentd(conf))
    {
      ++ServerStats.is_ref;
      sendto_one_notice(client, &me, ":*** Notice -- You need to install "
                        "identd to use this server");
      exit_client(client, "Install identd");
      return;
    }

    strlcpy(username, client->username, sizeof(username));

    if (!IsNoTilde(conf))
      client->username[i++] = '~';

    for (const char *p = username; *p && i < USERLEN; ++p)
      client->username[i++] = *p;

    client->username[i] = '\0';
  }

  /* Password check */
  if (!EmptyString(conf->passwd))
  {
    if (match_conf_password(client->connection->password, conf) == false)
    {
      ++ServerStats.is_ref;

      sendto_one_numeric(client, &me, ERR_PASSWDMISMATCH);
      exit_client(client, "Bad Password");
      return;
    }
  }

  xfree(client->connection->password);
  client->connection->password = NULL;

  /*
   * Report if user has &^>= etc. and set flags as needed in client
   */
  report_and_set_user_flags(client, conf);

  if (IsDead(client))
    return;

  /*
   * Limit clients -
   * We want to be able to have servers and F-line clients
   * connect, so save room for "buffer" connections.
   * Smaller servers may want to decrease this, and it should
   * probably be just a percentage of the MAXCLIENTS...
   *   -Taner
   */
  if ((dlink_list_length(&local_client_list) >= GlobalSetOptions.maxclients + MAX_BUFFER) ||
      (dlink_list_length(&local_client_list) >= GlobalSetOptions.maxclients && !HasFlag(client, FLAGS_NOLIMIT)))
  {
    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "Too many clients, rejecting %s[%s].",
                         client->name, client->host);
    ++ServerStats.is_ref;
    exit_client(client, "Sorry, server is full - try later");
    return;
  }

  if (valid_username(client->username, true) == false)
  {
    char buf[sizeof("Invalid username []") + sizeof(client->username)];

    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "Invalid username: %s (%s@%s)",
                         client->name, client->username, client->host);
    ++ServerStats.is_ref;
    snprintf(buf, sizeof(buf), "Invalid username [%s]", client->username);
    exit_client(client, buf);
    return;
  }

  if (!HasFlag(client, FLAGS_EXEMPTXLINE))
  {
    const struct GecosItem *gecos = gecos_find(client->info, match);
    if (gecos)
    {
      sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                           "X-line Rejecting [%s] [%s], user %s [%s]",
                           client->info, gecos->reason,
                           client_get_name(client, HIDE_IP),
                           client->sockhost);
      ++ServerStats.is_ref;
      exit_client(client, "Bad user info");
      return;
    }
  }

  const char *id;
  while (hash_find_id((id = uid_get())))
    ;

  strlcpy(client->id, id, sizeof(client->id));
  hash_add_id(client);

  sendto_realops_flags(UMODE_CCONN, L_ALL, SEND_NOTICE,
                       "Client connecting: %s (%s@%s) [%s] {%s} [%s] <%s>",
                       client->name, client->username, client->realhost,
                       client->sockhost,
                       get_client_class(&client->connection->confs),
                       client->info, client->id);

  if (ConfigGeneral.invisible_on_connect)
  {
    AddUMode(client, UMODE_INVISIBLE);
    ++Count.invisi;
  }

  SetClient(client);

  client->servptr = &me;
  client->connection->last_privmsg = event_base->time.sec_monotonic;

  dlinkAdd(client, &client->lnode, &client->servptr->serv->client_list);
  dlinkAdd(client, &client->node, &global_client_list);

  assert(dlinkFind(&unknown_list, client));

  dlink_move_node(&client->connection->lclient_node,
                  &unknown_list, &local_client_list);

  if (dlink_list_length(&local_client_list) > Count.max_loc)
  {
    Count.max_loc = dlink_list_length(&local_client_list);

    if (!(Count.max_loc % 10))
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                           "New maximum local client connections: %u",
                           Count.max_loc);
  }

  if ((dlink_list_length(&local_client_list) +
       dlink_list_length(&local_server_list)) > Count.max_loc_con)
    Count.max_loc_con = dlink_list_length(&local_client_list) +
                        dlink_list_length(&local_server_list);

  if (dlink_list_length(&global_client_list) > Count.max_tot)
    Count.max_tot = dlink_list_length(&global_client_list);
  ++Count.totalrestartcount;

  user_welcome(client);

  introduce_client(client);
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
register_remote_user(struct Client *client)
{
  assert(client->servptr->from == client->from);

  /*
   * If the nick has been introduced by a services server,
   * make it a service as well.
   */
  if (HasFlag(client->servptr, FLAGS_SERVICE))
    AddFlag(client, FLAGS_SERVICE);

  SetClient(client);
  dlinkAdd(client, &client->lnode, &client->servptr->serv->client_list);
  dlinkAdd(client, &client->node, &global_client_list);

  if (dlink_list_length(&global_client_list) > Count.max_tot)
    Count.max_tot = dlink_list_length(&global_client_list);

  if (HasFlag(client->servptr, FLAGS_EOB))
    sendto_realops_flags(UMODE_FARCONNECT, L_ALL, SEND_NOTICE,
                         "Client connecting at %s: %s (%s@%s) [%s] [%s] <%s>",
                         client->servptr->name,
                         client->name, client->username, client->realhost,
                         client->sockhost, client->info, client->id);

  introduce_client(client);
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
    unsigned int dots = 0;

    while (*p)
    {
      if (*p == '.' && ConfigGeneral.dots_in_ident)
      {
        if (++dots > ConfigGeneral.dots_in_ident)
          return false;
        if (!IsUser2Char(*(p + 1)))
          return false;
      }
      else if (!IsUser2Char(*p))
        return false;
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
 * \param client   Pointer to client
 * \param dispatch Whether to send a MODE message to client
 * \param old      Old user mode to compare against when building new mode buffer
 * \param buf      Pointer to buffer to build string in
 */
void
send_umode(struct Client *client, bool dispatch, unsigned int old, char *buf)
{
  char *m = buf;
  int what = 0;

  /*
   * Build a string in umode_buf to represent the change in the user's
   * mode between the new (client->umodes) and 'old'.
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

  if (dispatch == true && *buf)
    sendto_one(client, ":%s!%s@%s MODE %s :%s",
               client->name, client->username,
               client->host, client->name, buf);
}

/* send_umode_out()
 *
 * inputs	-
 * output	- NONE
 * side effects - Only send ubuf out to servers that know about this client
 */
void
send_umode_out(struct Client *client, unsigned int old)
{
  char buf[UMODE_MAX_STR] = "";

  send_umode(client, MyConnect(client), old, buf);

  if (buf[0])
    sendto_server(client, 0, 0, ":%s MODE %s :%s",
                  client->id, client->id, buf);
}

void
user_set_hostmask(struct Client *client, const char *hostname)
{
  dlink_node *node;

  if (strcmp(client->host, hostname) == 0)
    return;

  if (ConfigGeneral.cycle_on_host_change)
    sendto_common_channels_local(client, false, 0, CAP_CHGHOST, ":%s!%s@%s QUIT :Changing hostname",
                                 client->name, client->username, client->host);

  sendto_common_channels_local(client, true, CAP_CHGHOST, 0, ":%s!%s@%s CHGHOST %s %s",
                               client->name, client->username,
                               client->host, client->username, hostname);

  strlcpy(client->host, hostname, sizeof(client->host));

  if (MyConnect(client))
  {
    sendto_one_numeric(client, &me, RPL_VISIBLEHOST, client->host);
    clear_ban_cache_list(&client->channel);
  }

  if (ConfigGeneral.cycle_on_host_change == 0)
    return;

  DLINK_FOREACH(node, client->channel.head)
  {
    char modebuf[CMEMBER_STATUS_FLAGS_LEN + 1];
    char nickbuf[CMEMBER_STATUS_FLAGS_LEN * NICKLEN + CMEMBER_STATUS_FLAGS_LEN] = "";
    char *p = modebuf;
    int len = 0;
    const struct ChannelMember *member = node->data;

    if (member_has_flags(member, CHFL_CHANOP) == true)
    {
      *p++ = 'o';
      len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", client->name);
    }

    if (member_has_flags(member, CHFL_HALFOP) == true)
    {
      *p++ = 'h';
      len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", client->name);
    }

    if (member_has_flags(member, CHFL_VOICE) == true)
    {
      *p++ = 'v';
      len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", client->name);
    }

    *p = '\0';

    sendto_channel_local(client, member->channel, 0, CAP_EXTENDED_JOIN, CAP_CHGHOST, ":%s!%s@%s JOIN %s %s :%s",
                         client->name, client->username,
                         client->host, member->channel->name,
                         client->account, client->info);
    sendto_channel_local(client, member->channel, 0, 0, CAP_EXTENDED_JOIN | CAP_CHGHOST, ":%s!%s@%s JOIN :%s",
                         client->name, client->username,
                         client->host, member->channel->name);

    if (nickbuf[0])
      sendto_channel_local(client, member->channel, 0, 0, CAP_CHGHOST, ":%s MODE %s +%s %s",
                           client->servptr->name, member->channel->name,
                           modebuf, nickbuf);
  }

  if (client->away[0])
    sendto_common_channels_local(client, false, CAP_AWAY_NOTIFY, CAP_CHGHOST,
                                 ":%s!%s@%s AWAY :%s",
                                 client->name, client->username,
                                 client->host, client->away);
}
