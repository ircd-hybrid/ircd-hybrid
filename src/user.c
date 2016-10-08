/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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
#include "userhost.h"
#include "misc.h"
#include "parse.h"
#include "watch.h"
#include "isupport.h"
#include "tls.h"

static char umode_buffer[IRCD_BUFSIZE];

const struct user_modes *umode_map[256];
const struct user_modes  umode_tab[] =
{
  { 'D', UMODE_DEAF         },
  { 'F', UMODE_FARCONNECT   },
  { 'G', UMODE_SOFTCALLERID },
  { 'H', UMODE_HIDDEN       },
  { 'R', UMODE_REGONLY      },
  { 'S', UMODE_SSL          },
  { 'W', UMODE_WEBIRC       },
  { 'a', UMODE_ADMIN        },
  { 'b', UMODE_BOTS         },
  { 'c', UMODE_CCONN        },
  { 'd', UMODE_DEBUG        },
  { 'e', UMODE_EXTERNAL     },
  { 'f', UMODE_FULL         },
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
  { 'u', UMODE_UNAUTH       },
  { 'w', UMODE_WALLOP       },
  { 'x', UMODE_HIDDENHOST   },
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
show_lusers(struct Client *client_p)
{
  if (!ConfigServerHide.hide_servers || HasUMode(client_p, UMODE_OPER))
    sendto_one_numeric(client_p, &me, RPL_LUSERCLIENT, (Count.total - Count.invisi),
                       Count.invisi, dlink_list_length(&global_server_list));
  else
    sendto_one_numeric(client_p, &me, RPL_LUSERCLIENT, (Count.total - Count.invisi),
                       Count.invisi, 1);

  if (Count.oper)
    sendto_one_numeric(client_p, &me, RPL_LUSEROP, Count.oper);

  if (dlink_list_length(&unknown_list))
    sendto_one_numeric(client_p, &me, RPL_LUSERUNKNOWN, dlink_list_length(&unknown_list));

  if (dlink_list_length(&channel_list))
    sendto_one_numeric(client_p, &me, RPL_LUSERCHANNELS, dlink_list_length(&channel_list));

  if (!ConfigServerHide.hide_servers || HasUMode(client_p, UMODE_OPER))
  {
    sendto_one_numeric(client_p, &me, RPL_LUSERME, Count.local, Count.myserver);
    sendto_one_numeric(client_p, &me, RPL_LOCALUSERS, Count.local, Count.max_loc);
  }
  else
  {
    sendto_one_numeric(client_p, &me, RPL_LUSERME, Count.total, 0);
    sendto_one_numeric(client_p, &me, RPL_LOCALUSERS, Count.total, Count.max_tot);
  }

  sendto_one_numeric(client_p, &me, RPL_GLOBALUSERS, Count.total, Count.max_tot);

  if (!ConfigServerHide.hide_servers || HasUMode(client_p, UMODE_OPER))
    sendto_one_numeric(client_p, &me, RPL_STATSCONN, Count.max_loc_con,
                       Count.max_loc_cli, Count.totalrestartcount);

  if (Count.local > Count.max_loc_cli)
    Count.max_loc_cli = Count.local;

  if ((Count.local + Count.myserver) > Count.max_loc_con)
    Count.max_loc_con = Count.local + Count.myserver;
}

/* report_and_set_user_flags()
 *
 * inputs       - pointer to client_p
 *              - pointer to conf for this user
 * output       - NONE
 * side effects - Report to user any special flags
 *                they are getting, and set them.
 */
static void
report_and_set_user_flags(struct Client *client_p, const struct MaskItem *conf)
{
  /* If this user is being spoofed, tell them so */
  if (IsConfDoSpoofIp(conf))
    sendto_one_notice(client_p, &me, ":*** Spoofing your IP");

  /* If this user is in the exception class, set it "E lined" */
  if (IsConfExemptKline(conf))
  {
    AddFlag(client_p, FLAGS_EXEMPTKLINE);
    sendto_one_notice(client_p, &me, ":*** You are exempt from K/D lines");
  }

  if (IsConfExemptXline(conf))
  {
    AddFlag(client_p, FLAGS_EXEMPTXLINE);
    sendto_one_notice(client_p, &me, ":*** You are exempt from X lines");
  }

  if (IsConfExemptResv(conf))
  {
    AddFlag(client_p, FLAGS_EXEMPTRESV);
    sendto_one_notice(client_p, &me, ":*** You are exempt from resvs");
  }

  /* If this user is exempt from user limits set it "F lined" */
  if (IsConfExemptLimits(conf))
  {
    AddFlag(client_p, FLAGS_NOLIMIT);
    sendto_one_notice(client_p, &me, ":*** You are exempt from user limits");
  }

  if (IsConfCanFlood(conf))
  {
    AddFlag(client_p, FLAGS_CANFLOOD);
    sendto_one_notice(client_p, &me, ":*** You are exempt from flood protection");
  }
}

/* introduce_client()
 *
 * inputs       - client_p
 * output       - NONE
 * side effects - This common function introduces a client to the rest
 *                of the net, either from a local client connect or
 *                from a remote connect.
 */
static void
introduce_client(struct Client *client_p)
{
  dlink_node *node = NULL;
  char ubuf[IRCD_BUFSIZE] = "";

  send_umode(client_p, MyConnect(client_p), 0, ubuf);
  watch_check_hash(client_p, RPL_LOGON);

  if (ubuf[0] == '\0')
  {
    ubuf[0] = '+';
    ubuf[1] = '\0';
  }

  DLINK_FOREACH(node, local_server_list.head)
  {
    struct Client *server_p = node->data;

    if (server_p == client_p->from)
      continue;

    sendto_one(server_p, ":%s UID %s %u %ju %s %s %s %s %s %s :%s",
               client_p->servptr->id,
               client_p->name, client_p->hopcount+1,
               client_p->tsinfo,
               ubuf, client_p->username, client_p->host,
               client_p->sockhost, client_p->id,
               client_p->account,
               client_p->info);

    if (!EmptyString(client_p->certfp))
      sendto_one(server_p, ":%s CERTFP %s", client_p->id, client_p->certfp);
  }
}

/* user_welcome()
 *
 * inputs       - client pointer to client to welcome
 * output       - NONE
 * side effects -
 */
static void
user_welcome(struct Client *client_p)
{
  static const char built_date[] = __DATE__ " at " __TIME__;

  if (HasFlag(client_p, FLAGS_SSL))
  {
    AddUMode(client_p, UMODE_SSL);
    sendto_one_notice(client_p, &me, ":*** Connected securely via %s",
                      tls_get_cipher(&client_p->connection->fd.ssl));
  }

  sendto_one_numeric(client_p, &me, RPL_WELCOME, ConfigServerInfo.network_name,
                     client_p->name);
  sendto_one_numeric(client_p, &me, RPL_YOURHOST,
                     listener_get_name(client_p->connection->listener), ircd_version);
  sendto_one_numeric(client_p, &me, RPL_CREATED, built_date);
  sendto_one_numeric(client_p, &me, RPL_MYINFO, me.name, ircd_version, umode_buffer);

  isupport_show(client_p);
  show_lusers(client_p);
  motd_signon(client_p);
}

/* check_xline()
 *
 * inputs       - pointer to client to test
 * outupt       - 1 if exiting 0 if ok
 * side effects -
 */
static int
check_xline(struct Client *client_p)
{
  const struct GecosItem *gecos = NULL;

  if (HasFlag(client_p, FLAGS_EXEMPTXLINE))
    return 0;

  if ((gecos = gecos_find(client_p->info, match)))
  {
    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "X-line Rejecting [%s] [%s], user %s [%s]",
                         client_p->info, gecos->reason,
                         get_client_name(client_p, HIDE_IP),
                         client_p->sockhost);

    ++ServerStats.is_ref;
    exit_client(client_p, "Bad user info");
    return 1;
  }

  return 0;
}

/*! \brief This function is called when both NICK and USER messages
 *      have been accepted for the client, in whatever order. Only
 *      after this, is the UID message propagated.
 * \param client_p Pointer to given client to introduce
 */
void
register_local_user(struct Client *client_p)
{
  const struct MaskItem *conf = NULL;

  assert(client_p == client_p->from);
  assert(MyConnect(client_p));
  assert(IsUnknown(client_p));
  assert(!client_p->connection->registration);

  if (ConfigGeneral.ping_cookie)
  {
    if (!HasFlag(client_p, FLAGS_PINGSENT) && !client_p->connection->random_ping)
    {
      do
        client_p->connection->random_ping = genrand_int32();
      while (!client_p->connection->random_ping);

      sendto_one(client_p, "PING :%u", client_p->connection->random_ping);
      AddFlag(client_p, FLAGS_PINGSENT);
      return;
    }

    if (!HasFlag(client_p, FLAGS_PING_COOKIE))
      return;
  }

  client_p->connection->last_privmsg = CurrentTime;
  /* Straight up the maximum rate of flooding... */
  client_p->connection->allow_read = MAX_FLOOD_BURST;

  if (!check_client(client_p))
    return;

  if (!valid_hostname(client_p->host))
  {
    sendto_one_notice(client_p, &me, ":*** Notice -- You have an illegal "
                      "character in your hostname");
    strlcpy(client_p->host, client_p->sockhost, sizeof(client_p->host));
  }

  conf = client_p->connection->confs.head->data;

  if (!HasFlag(client_p, FLAGS_GOTID))
  {
    char username[USERLEN + 1] = "";
    unsigned int i = 0;

    if (IsNeedIdentd(conf))
    {
      ++ServerStats.is_ref;
      sendto_one_notice(client_p, &me, ":*** Notice -- You need to install "
                        "identd to use this server");
      exit_client(client_p, "Install identd");
      return;
    }

    strlcpy(username, client_p->username, sizeof(username));

    if (!IsNoTilde(conf))
      client_p->username[i++] = '~';

    for (const char *p = username; *p && i < USERLEN; ++p)
      client_p->username[i++] = *p;

    client_p->username[i] = '\0';
  }

  /* Password check */
  if (!EmptyString(conf->passwd))
  {
    if (!match_conf_password(client_p->connection->password, conf))
    {
      ++ServerStats.is_ref;

      sendto_one_numeric(client_p, &me, ERR_PASSWDMISMATCH);
      exit_client(client_p, "Bad Password");
      return;
    }
  }

  /*
   * Don't free client_p->connection->password here - it can be required
   * by masked /stats I if there are auth {} blocks with need_password = no;
   * --adx
   */

  /*
   * Report if user has &^>= etc. and set flags as needed in client_p
   */
  report_and_set_user_flags(client_p, conf);

  if (IsDead(client_p))
    return;

  /*
   * Limit clients -
   * We want to be able to have servers and F-line clients
   * connect, so save room for "buffer" connections.
   * Smaller servers may want to decrease this, and it should
   * probably be just a percentage of the MAXCLIENTS...
   *   -Taner
   */
  if ((Count.local >= GlobalSetOptions.maxclients + MAX_BUFFER) ||
      (Count.local >= GlobalSetOptions.maxclients && !HasFlag(client_p, FLAGS_NOLIMIT)))
  {
    sendto_realops_flags(UMODE_FULL, L_ALL, SEND_NOTICE,
                         "Too many clients, rejecting %s[%s].",
                         client_p->name, client_p->host);
    ++ServerStats.is_ref;
    exit_client(client_p, "Sorry, server is full - try later");
    return;
  }

  if (!valid_username(client_p->username, 1))
  {
    char buf[IRCD_BUFSIZE] = "";

    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "Invalid username: %s (%s@%s)",
                         client_p->name, client_p->username, client_p->host);
    ++ServerStats.is_ref;
    snprintf(buf, sizeof(buf), "Invalid username [%s]", client_p->username);
    exit_client(client_p, buf);
    return;
  }

  if (check_xline(client_p))
    return;

  const char *id;
  while (hash_find_id((id = uid_get())))
    ;

  strlcpy(client_p->id, id, sizeof(client_p->id));
  hash_add_id(client_p);

  sendto_realops_flags(UMODE_CCONN, L_ALL, SEND_NOTICE,
                       "Client connecting: %s (%s@%s) [%s] {%s} [%s] <%s>",
                       client_p->name, client_p->username, client_p->host,
                       client_p->sockhost,
                       get_client_class(&client_p->connection->confs),
                       client_p->info, client_p->id);

  if (ConfigGeneral.invisible_on_connect)
  {
    AddUMode(client_p, UMODE_INVISIBLE);
    ++Count.invisi;
  }

  if (++Count.local > Count.max_loc)
  {
    Count.max_loc = Count.local;

    if (!(Count.max_loc % 10))
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                           "New maximum local client connections: %u",
                           Count.max_loc);
  }

  if (++Count.total > Count.max_tot)
    Count.max_tot = Count.total;
  ++Count.totalrestartcount;

  assert(client_p->servptr == &me);
  SetClient(client_p);
  dlinkAdd(client_p, &client_p->lnode, &client_p->servptr->serv->client_list);
  dlinkAdd(client_p, &client_p->node, &global_client_list);

  assert(dlinkFind(&unknown_list, client_p));

  dlink_move_node(&client_p->connection->lclient_node,
                  &unknown_list, &local_client_list);

  user_welcome(client_p);
  userhost_add(client_p->sockhost, 0);
  AddFlag(client_p, FLAGS_USERHOST);

  introduce_client(client_p);
}

/* register_remote_user()
 *
 * inputs       - client_p remote or directly connected client
 *              - username to register as
 *              - host name to register as
 *              - server name
 * output	- NONE
 * side effects	- This function is called when a remote client
 *		  is introduced by a server.
 */
void
register_remote_user(struct Client *client_p)
{
  assert(client_p->servptr->from == client_p->from);

  /*
   * If the nick has been introduced by a services server,
   * make it a service as well.
   */
  if (HasFlag(client_p->servptr, FLAGS_SERVICE))
    AddFlag(client_p, FLAGS_SERVICE);

  if (++Count.total > Count.max_tot)
    Count.max_tot = Count.total;

  SetClient(client_p);
  dlinkAdd(client_p, &client_p->lnode, &client_p->servptr->serv->client_list);
  dlinkAdd(client_p, &client_p->node, &global_client_list);
  userhost_add(client_p->sockhost, 1);
  AddFlag(client_p, FLAGS_USERHOST);

  if (HasFlag(client_p->servptr, FLAGS_EOB))
    sendto_realops_flags(UMODE_FARCONNECT, L_ALL, SEND_NOTICE,
                         "Client connecting at %s: %s (%s@%s) [%s] [%s] <%s>",
                         client_p->servptr->name,
                         client_p->name, client_p->username, client_p->host,
                         client_p->sockhost, client_p->info, client_p->id);

  introduce_client(client_p);
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
int
valid_hostname(const char *hostname)
{
  const char *p = hostname;

  assert(p);

  if (EmptyString(p) || *p == '.' || *p == ':')
    return 0;

  for (; *p; ++p)
    if (!IsHostChar(*p))
      return 0;

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
int
valid_username(const char *username, const int local)
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
    return 0;

  if (local)
  {
    unsigned int dots = 0;

    while (*++p)
    {
      if (*p == '.' && ConfigGeneral.dots_in_ident)
      {
        if (++dots > ConfigGeneral.dots_in_ident)
          return 0;
        if (!IsUserChar(*(p + 1)))
          return 0;
      }
      else if (!IsUserChar(*p))
        return 0;
    }
  }
  else
  {
    while (*++p)
      if (!IsUserChar(*p))
        return 0;
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
int
valid_nickname(const char *nickname, const int local)
{
  const char *p = nickname;

  assert(p);

  /*
   * Nicks can't start with a digit or - or be 0 length.
   */
  if (EmptyString(p) || *p == '-' || (IsDigit(*p) && local))
    return 0;

  for (; *p; ++p)
    if (!IsNickChar(*p))
      return 0;

  return p - nickname <= NICKLEN;
}

/*! \brief Builds a mode change string to buffer pointed by \a buf
 * \param client_p  Pointer to client
 * \param dispatch  Whether to send a MODE message to client_p
 * \param old       Old user mode to compare against when building new mode buffer
 * \param buf       Pointer to buffer to build string in
 */
void
send_umode(struct Client *client_p, unsigned int dispatch,
           unsigned int old, char *buf)
{
  char *m = buf;
  int what = 0;

  /*
   * Build a string in umode_buf to represent the change in the user's
   * mode between the new (client_p->umodes) and 'old'.
   */
  for (const struct user_modes *tab = umode_tab; tab->c; ++tab)
  {
    if ((tab->flag & old) && !HasUMode(client_p, tab->flag))
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
    else if (!(tab->flag & old) && HasUMode(client_p, tab->flag))
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

  if (dispatch && *buf)
    sendto_one(client_p, ":%s!%s@%s MODE %s :%s",
               client_p->name, client_p->username,
               client_p->host, client_p->name, buf);
}

/* send_umode_out()
 *
 * inputs	-
 * output	- NONE
 * side effects - Only send ubuf out to servers that know about this client
 */
void
send_umode_out(struct Client *client_p, unsigned int old)
{
  char buf[IRCD_BUFSIZE] = "";

  send_umode(client_p, MyConnect(client_p), old, buf);

  if (buf[0])
    sendto_server(client_p, 0, 0, ":%s MODE %s :%s",
                  client_p->id, client_p->id, buf);
}

void
user_set_hostmask(struct Client *client_p, const char *hostname, const int what)
{
  dlink_node *node = NULL;

  if (!strcmp(client_p->host, hostname))
    return;

  switch (what)
  {
    case MODE_ADD:
      AddUMode(client_p, UMODE_HIDDENHOST);
      break;
    case MODE_DEL:
      DelUMode(client_p, UMODE_HIDDENHOST);
      break;
    default: return;
  }

  if (ConfigGeneral.cycle_on_host_change)
    sendto_common_channels_local(client_p, 0, 0, CAP_CHGHOST, ":%s!%s@%s QUIT :Changing hostname",
                                 client_p->name, client_p->username, client_p->host);

  sendto_common_channels_local(client_p, 0, CAP_CHGHOST, 0, ":%s!%s@%s CHGHOST %s %s",
                               client_p->name, client_p->username,
                               client_p->host, client_p->username, hostname);

  strlcpy(client_p->host, hostname, sizeof(client_p->host));

  if (MyConnect(client_p))
  {
    sendto_one_numeric(client_p, &me, RPL_VISIBLEHOST, client_p->host);
    clear_ban_cache_list(&client_p->channel);
  }

  if (!ConfigGeneral.cycle_on_host_change)
    return;

  DLINK_FOREACH(node, client_p->channel.head)
  {
    char modebuf[CMEMBER_STATUS_FLAGS_LEN + 1];
    char nickbuf[CMEMBER_STATUS_FLAGS_LEN * NICKLEN + CMEMBER_STATUS_FLAGS_LEN] = "";
    char *p = modebuf;
    int len = 0;
    const struct Membership *member = node->data;

    if (has_member_flags(member, CHFL_CHANOP))
    {
      *p++ = 'o';
      len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", client_p->name);
    }

    if (has_member_flags(member, CHFL_HALFOP))
    {
      *p++ = 'h';
      len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", client_p->name);
    }

    if (has_member_flags(member, CHFL_VOICE))
    {
      *p++ = 'v';
      len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", client_p->name);
    }

    *p = '\0';

    sendto_channel_local(client_p, member->chptr, 0, CAP_EXTENDED_JOIN, CAP_CHGHOST, ":%s!%s@%s JOIN %s %s :%s",
                         client_p->name, client_p->username,
                         client_p->host, member->chptr->name,
                         client_p->account, client_p->info);
    sendto_channel_local(client_p, member->chptr, 0, 0, CAP_EXTENDED_JOIN | CAP_CHGHOST, ":%s!%s@%s JOIN :%s",
                         client_p->name, client_p->username,
                         client_p->host, member->chptr->name);

    if (nickbuf[0])
      sendto_channel_local(client_p, member->chptr, 0, 0, CAP_CHGHOST, ":%s MODE %s +%s %s",
                           client_p->servptr->name, member->chptr->name,
                           modebuf, nickbuf);
  }

  if (client_p->away[0])
    sendto_common_channels_local(client_p, 0, CAP_AWAY_NOTIFY, CAP_CHGHOST,
                                 ":%s!%s@%s AWAY :%s",
                                 client_p->name, client_p->username,
                                 client_p->host, client_p->away);
}
