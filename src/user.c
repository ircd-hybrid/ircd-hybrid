/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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
show_lusers(struct Client *source_p)
{
  if (!ConfigServerHide.hide_servers || HasUMode(source_p, UMODE_OPER))
    sendto_one_numeric(source_p, &me, RPL_LUSERCLIENT, (Count.total - Count.invisi),
                       Count.invisi, dlink_list_length(&global_server_list));
  else
    sendto_one_numeric(source_p, &me, RPL_LUSERCLIENT, (Count.total - Count.invisi),
                       Count.invisi, 1);

  if (Count.oper)
    sendto_one_numeric(source_p, &me, RPL_LUSEROP, Count.oper);

  if (dlink_list_length(&unknown_list))
    sendto_one_numeric(source_p, &me, RPL_LUSERUNKNOWN, dlink_list_length(&unknown_list));

  if (dlink_list_length(&channel_list))
    sendto_one_numeric(source_p, &me, RPL_LUSERCHANNELS, dlink_list_length(&channel_list));

  if (!ConfigServerHide.hide_servers || HasUMode(source_p, UMODE_OPER))
  {
    sendto_one_numeric(source_p, &me, RPL_LUSERME, Count.local, Count.myserver);
    sendto_one_numeric(source_p, &me, RPL_LOCALUSERS, Count.local, Count.max_loc);
  }
  else
  {
    sendto_one_numeric(source_p, &me, RPL_LUSERME, Count.total, 0);
    sendto_one_numeric(source_p, &me, RPL_LOCALUSERS, Count.total, Count.max_tot);
  }

  sendto_one_numeric(source_p, &me, RPL_GLOBALUSERS, Count.total, Count.max_tot);

  if (!ConfigServerHide.hide_servers || HasUMode(source_p, UMODE_OPER))
    sendto_one_numeric(source_p, &me, RPL_STATSCONN, Count.max_loc_con,
                       Count.max_loc_cli, Count.totalrestartcount);

  if (Count.local > Count.max_loc_cli)
    Count.max_loc_cli = Count.local;

  if ((Count.local + Count.myserver) > Count.max_loc_con)
    Count.max_loc_con = Count.local + Count.myserver;
}

/* report_and_set_user_flags()
 *
 * inputs       - pointer to source_p
 *              - pointer to conf for this user
 * output       - NONE
 * side effects - Report to user any special flags
 *                they are getting, and set them.
 */
static void
report_and_set_user_flags(struct Client *source_p, const struct MaskItem *conf)
{
  /* If this user is being spoofed, tell them so */
  if (IsConfDoSpoofIp(conf))
    sendto_one_notice(source_p, &me, ":*** Spoofing your IP. Congrats.");

  /* If this user is in the exception class, set it "E lined" */
  if (IsConfExemptKline(conf))
  {
    SetExemptKline(source_p);
    sendto_one_notice(source_p, &me, ":*** You are exempt from K/D lines. Congrats.");
  }

  if (IsConfExemptXline(conf))
  {
    SetExemptXline(source_p);
    sendto_one_notice(source_p, &me, ":*** You are exempt from X lines. Congrats.");
  }

  if (IsConfExemptResv(conf))
  {
    SetExemptResv(source_p);
    sendto_one_notice(source_p, &me, ":*** You are exempt from resvs. Congrats.");
  }

  /* If this user is exempt from user limits set it "F lined" */
  if (IsConfExemptLimits(conf))
  {
    SetExemptLimits(source_p);
    sendto_one_notice(source_p, &me, ":*** You are exempt from user limits. Congrats.");
  }

  if (IsConfCanFlood(conf))
  {
    SetCanFlood(source_p);
    sendto_one_notice(source_p, &me, ":*** You are exempt from flood "
                      "protection, aren't you fearsome.");
  }
}

/* introduce_client()
 *
 * inputs       - source_p
 * output       - NONE
 * side effects - This common function introduces a client to the rest
 *                of the net, either from a local client connect or
 *                from a remote connect.
 */
static void
introduce_client(struct Client *source_p)
{
  dlink_node *node = NULL;
  char ubuf[IRCD_BUFSIZE] = "";

  if (MyClient(source_p))
    send_umode(source_p, source_p, 0, ubuf);
  else
    send_umode(NULL, source_p, 0, ubuf);

  watch_check_hash(source_p, RPL_LOGON);

  if (ubuf[0] == '\0')
  {
    ubuf[0] = '+';
    ubuf[1] = '\0';
  }

  DLINK_FOREACH(node, local_server_list.head)
  {
    struct Client *server = node->data;

    if (server == source_p->from)
      continue;

    if (IsCapable(server, CAP_SVS))
      sendto_one(server, ":%s UID %s %u %lu %s %s %s %s %s %s :%s",
                 source_p->servptr->id,
                 source_p->name, source_p->hopcount+1,
                 (unsigned long)source_p->tsinfo,
                 ubuf, source_p->username, source_p->host,
                 source_p->sockhost, source_p->id,
                 source_p->account,
                 source_p->info);
    else
      sendto_one(server, ":%s UID %s %u %lu %s %s %s %s %s :%s",
                 source_p->servptr->id,
                 source_p->name, source_p->hopcount+1,
                 (unsigned long)source_p->tsinfo,
                 ubuf, source_p->username, source_p->host,
                 source_p->sockhost, source_p->id, source_p->info);

    if (!EmptyString(source_p->certfp))
      sendto_one(server, ":%s CERTFP %s", source_p->id, source_p->certfp);
  }
}

/* user_welcome()
 *
 * inputs       - client pointer to client to welcome
 * output       - NONE
 * side effects -
 */
static void
user_welcome(struct Client *source_p)
{
#if defined(__TIME__) && defined(__DATE__)
  static const char built_date[] = __DATE__ " at " __TIME__;
#else
  static const char built_date[] = "unknown";
#endif

#ifdef HAVE_LIBCRYPTO
  if (HasFlag(source_p, FLAGS_SSL))
  {
    AddUMode(source_p, UMODE_SSL);
    sendto_one_notice(source_p, &me, ":*** Connected securely via %s",
                      ssl_get_cipher(source_p->connection->fd.ssl));
  }
#endif

  sendto_one_numeric(source_p, &me, RPL_WELCOME, ConfigServerInfo.network_name,
                     source_p->name);
  sendto_one_numeric(source_p, &me, RPL_YOURHOST,
                     get_listener_name(source_p->connection->listener), ircd_version);
  sendto_one_numeric(source_p, &me, RPL_CREATED, built_date);
  sendto_one_numeric(source_p, &me, RPL_MYINFO, me.name, ircd_version, umode_buffer);

  isupport_show(source_p);
  show_lusers(source_p);
  motd_signon(source_p);
}

/* check_xline()
 *
 * inputs       - pointer to client to test
 * outupt       - 1 if exiting 0 if ok
 * side effects -
 */
static int
check_xline(struct Client *source_p)
{
  struct MaskItem *conf = NULL;

  if (IsExemptXline(source_p))
    return 0;

  if ((conf = find_matching_name_conf(CONF_XLINE, source_p->info, NULL, NULL, 0)))
  {
    ++conf->count;
    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "X-line Rejecting [%s] [%s], user %s [%s]",
                         source_p->info, conf->reason,
                         get_client_name(source_p, HIDE_IP),
                         source_p->sockhost);

    ++ServerStats.is_ref;
    exit_client(source_p, "Bad user info");
    return 1;
  }

  return 0;
}

/*! \brief This function is called when both NICK and USER messages
 *      have been accepted for the client, in whatever order. Only
 *      after this, is the UID message propagated.
 * \param source_p Pointer to given client to introduce
 */
void
register_local_user(struct Client *source_p)
{
  const char *id = NULL;
  const struct MaskItem *conf = NULL;

  assert(source_p == source_p->from);
  assert(MyConnect(source_p));
  assert(IsUnknown(source_p));
  assert(!source_p->connection->registration);

  if (ConfigGeneral.ping_cookie)
  {
    if (!IsPingSent(source_p) && !source_p->connection->random_ping)
    {
      do
        source_p->connection->random_ping = genrand_int32();
      while (!source_p->connection->random_ping);

      sendto_one(source_p, "PING :%u", source_p->connection->random_ping);
      SetPingSent(source_p);
      return;
    }

    if (!HasPingCookie(source_p))
      return;
  }

  source_p->connection->last_privmsg = CurrentTime;
  /* Straight up the maximum rate of flooding... */
  source_p->connection->allow_read = MAX_FLOOD_BURST;

  if (!check_client(source_p))
    return;

  if (!valid_hostname(source_p->host))
  {
    sendto_one_notice(source_p, &me, ":*** Notice -- You have an illegal "
                      "character in your hostname");
    strlcpy(source_p->host, source_p->sockhost, sizeof(source_p->host));
  }

  conf = source_p->connection->confs.head->data;

  if (!IsGotId(source_p))
  {
    char username[USERLEN + 1] = "";
    const char *p = username;
    unsigned int i = 0;

    if (IsNeedIdentd(conf))
    {
      ++ServerStats.is_ref;
      sendto_one_notice(source_p, &me, ":*** Notice -- You need to install "
                        "identd to use this server");
      exit_client(source_p, "Install identd");
      return;
    }

    strlcpy(username, source_p->username, sizeof(username));

    if (!IsNoTilde(conf))
      source_p->username[i++] = '~';

    for (; *p && i < USERLEN; ++p)
      source_p->username[i++] = *p;

    source_p->username[i] = '\0';
  }

  /* Password check */
  if (!EmptyString(conf->passwd))
  {
    if (!match_conf_password(source_p->connection->password, conf))
    {
      ++ServerStats.is_ref;

      sendto_one_numeric(source_p, &me, ERR_PASSWDMISMATCH);
      exit_client(source_p, "Bad Password");
      return;
    }
  }

  /*
   * Don't free source_p->connection->password here - it can be required
   * by masked /stats I if there are auth {} blocks with need_password = no;
   * --adx
   */

  /*
   * Report if user has &^>= etc. and set flags as needed in source_p
   */
  report_and_set_user_flags(source_p, conf);

  if (IsDead(source_p))
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
      (Count.local >= GlobalSetOptions.maxclients && !IsExemptLimits(source_p)))
  {
    sendto_realops_flags(UMODE_FULL, L_ALL, SEND_NOTICE,
                         "Too many clients, rejecting %s[%s].",
                         source_p->name, source_p->host);
    ++ServerStats.is_ref;
    exit_client(source_p, "Sorry, server is full - try later");
    return;
  }

  if (!valid_username(source_p->username, 1))
  {
    char buf[IRCD_BUFSIZE] = "";

    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "Invalid username: %s (%s@%s)",
                         source_p->name, source_p->username, source_p->host);
    ++ServerStats.is_ref;
    snprintf(buf, sizeof(buf), "Invalid username [%s]", source_p->username);
    exit_client(source_p, buf);
    return;
  }

  if (check_xline(source_p))
    return;

  while (hash_find_id((id = uid_get())))
    ;

  strlcpy(source_p->id, id, sizeof(source_p->id));
  hash_add_id(source_p);

  sendto_realops_flags(UMODE_CCONN, L_ALL, SEND_NOTICE,
                       "Client connecting: %s (%s@%s) [%s] {%s} [%s] <%s>",
                       source_p->name, source_p->username, source_p->host,
                       source_p->sockhost,
                       get_client_class(&source_p->connection->confs),
                       source_p->info, source_p->id);

  if (ConfigGeneral.invisible_on_connect)
  {
    AddUMode(source_p, UMODE_INVISIBLE);
    ++Count.invisi;
  }

  if (++Count.local > Count.max_loc)
  {
    Count.max_loc = Count.local;

    if (!(Count.max_loc % 10))
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "New maximum local client connections: %u",
                           Count.max_loc);
  }

  if (++Count.total > Count.max_tot)
    Count.max_tot = Count.total;
  ++Count.totalrestartcount;

  assert(source_p->servptr == &me);
  SetClient(source_p);
  dlinkAdd(source_p, &source_p->lnode, &source_p->servptr->serv->client_list);
  dlinkAdd(source_p, &source_p->node, &global_client_list);

  assert(dlinkFind(&unknown_list, source_p));

  dlink_move_node(&source_p->connection->lclient_node,
                  &unknown_list, &local_client_list);

  user_welcome(source_p);
  add_user_host(source_p->username, source_p->host, 0);
  SetUserHost(source_p);

  introduce_client(source_p);
}

/* register_remote_user()
 *
 * inputs       - source_p remote or directly connected client
 *              - username to register as
 *              - host name to register as
 *              - server name
 * output	- NONE
 * side effects	- This function is called when a remote client
 *		  is introduced by a server.
 */
void
register_remote_user(struct Client *source_p)
{
  const struct Client *target_p = NULL;

  if ((target_p = source_p->servptr) && target_p->from != source_p->from)
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "Bad User [%s] :%s USER %s@%s %s, != %s[%s]",
                         source_p->from->name, source_p->name, source_p->username,
                         source_p->host, source_p->servptr->name,
                         target_p->name, target_p->from->name);
    sendto_one(source_p->from,
               ":%s KILL %s :%s (UID from wrong direction (%s != %s))",
               me.id, source_p->id, me.name, source_p->servptr->name,
               target_p->from->name);

    AddFlag(source_p, FLAGS_KILLED);
    exit_client(source_p, "UID server wrong direction");
    return;
  }

  /*
   * If the nick has been introduced by a services server,
   * make it a service as well.
   */
  if (HasFlag(source_p->servptr, FLAGS_SERVICE))
    AddFlag(source_p, FLAGS_SERVICE);

  if (++Count.total > Count.max_tot)
    Count.max_tot = Count.total;

  SetClient(source_p);
  dlinkAdd(source_p, &source_p->lnode, &source_p->servptr->serv->client_list);
  dlinkAdd(source_p, &source_p->node, &global_client_list);
  add_user_host(source_p->username, source_p->host, 1);
  SetUserHost(source_p);

  if (HasFlag(source_p->servptr, FLAGS_EOB))
    sendto_realops_flags(UMODE_FARCONNECT, L_ALL, SEND_NOTICE,
                         "Client connecting at %s: %s (%s@%s) [%s] [%s] <%s>",
                         source_p->servptr->name,
                         source_p->name, source_p->username, source_p->host,
                         source_p->sockhost, source_p->info, source_p->id);

  introduce_client(source_p);
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
  unsigned int dots = 0;
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

/* send_umode()
 * send the MODE string for user (user) to connection client_p
 * -avalon
 *
 * inputs	- client_p
 *		- source_p
 *		- int old
 *		- sendmask mask of modes to send
 * 		- suplied umode_buf
 * output	- NONE
 */
void
send_umode(struct Client *client_p, struct Client *source_p,
           unsigned int old, char *umode_buf)
{
  char *m = umode_buf;
  int what = 0;

  /*
   * Build a string in umode_buf to represent the change in the user's
   * mode between the new (source_p->umodes) and 'old'.
   */
  for (const struct user_modes *tab = umode_tab; tab->c; ++tab)
  {
    if ((tab->flag & old) && !HasUMode(source_p, tab->flag))
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
    else if (!(tab->flag & old) && HasUMode(source_p, tab->flag))
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

  if (*umode_buf && client_p)
    sendto_one(client_p, ":%s!%s@%s MODE %s :%s",
               client_p->name, client_p->username,
               client_p->host, client_p->name, umode_buf);
}

/* send_umode_out()
 *
 * inputs	-
 * output	- NONE
 * side effects - Only send ubuf out to servers that know about this client
 */
void
send_umode_out(struct Client *source_p, unsigned int old)
{
  char buf[IRCD_BUFSIZE] = "";

  send_umode(MyClient(source_p) ? source_p : NULL, source_p, old, buf);

  if (buf[0])
    sendto_server(source_p, 0, 0, ":%s MODE %s :%s",
                  source_p->id, source_p->id, buf);
}

void
user_set_hostmask(struct Client *target_p, const char *hostname, const int what)
{
  dlink_node *node = NULL;

  if (!strcmp(target_p->host, hostname))
    return;

  switch (what)
  {
    case MODE_ADD:
      AddUMode(target_p, UMODE_HIDDENHOST);
      break;
    case MODE_DEL:
      DelUMode(target_p, UMODE_HIDDENHOST);
      break;
    default: return;
  }

  if (ConfigGeneral.cycle_on_host_change)
    sendto_common_channels_local(target_p, 0, 0, ":%s!%s@%s QUIT :Changing hostname",
                                 target_p->name, target_p->username, target_p->host);

  if (IsUserHostIp(target_p))
    delete_user_host(target_p->username, target_p->host, !MyConnect(target_p));

  strlcpy(target_p->host, hostname, sizeof(target_p->host));

  add_user_host(target_p->username, target_p->host, !MyConnect(target_p));
  SetUserHost(target_p);

  if (MyClient(target_p))
  {
    sendto_one_numeric(target_p, &me, RPL_VISIBLEHOST, target_p->host);
    clear_ban_cache_client(target_p);
  }

  if (!ConfigGeneral.cycle_on_host_change)
    return;

  DLINK_FOREACH(node, target_p->channel.head)
  {
    char modebuf[4], nickbuf[NICKLEN * 3 + 3] = "";
    char *p = modebuf;
    int len = 0;
    const struct Membership *member = node->data;

    if (has_member_flags(member, CHFL_CHANOP))
    {
      *p++ = 'o';
      len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", target_p->name);
    }

    if (has_member_flags(member, CHFL_HALFOP))
    {
      *p++ = 'h';
      len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", target_p->name);
    }

    if (has_member_flags(member, CHFL_VOICE))
    {
      *p++ = 'v';
      len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", target_p->name);
    }

    *p = '\0';


    sendto_channel_local_butone(target_p, CAP_EXTENDED_JOIN, 0, member->chptr, ":%s!%s@%s JOIN %s %s :%s",
                                target_p->name, target_p->username,
                                target_p->host, member->chptr->name,
                                (!IsDigit(target_p->account[0]) && target_p->account[0] != '*') ? target_p->account : "*",
                                target_p->info);
    sendto_channel_local_butone(target_p, 0, CAP_EXTENDED_JOIN, member->chptr, ":%s!%s@%s JOIN :%s",
                                target_p->name, target_p->username,
                                target_p->host, member->chptr->name);

    if (nickbuf[0])
      sendto_channel_local_butone(target_p, 0, 0, member->chptr, ":%s MODE %s +%s %s",
                                  target_p->servptr->name, member->chptr->name,
                                  modebuf, nickbuf);

  }

  if (target_p->away[0])
    sendto_common_channels_local(target_p, 0, CAP_AWAY_NOTIFY,
                                 ":%s!%s@%s AWAY :%s",
                                 target_p->name, target_p->username,
                                 target_p->host, target_p->away);
}

/*! \brief Blindly opers up given source_p, using conf info.
 *         All checks on passwords have already been done.
 * \param source_p Pointer to given client to oper
 */
void
user_oper_up(struct Client *source_p)
{
  const unsigned int old = source_p->umodes;
  const struct MaskItem *const conf = source_p->connection->confs.head->data;

  assert(source_p->connection->confs.head);

  ++Count.oper;
  SetOper(source_p);

  if (conf->modes)
    AddUMode(source_p, conf->modes);
  else if (ConfigGeneral.oper_umodes)
    AddUMode(source_p, ConfigGeneral.oper_umodes);

  if (!(old & UMODE_INVISIBLE) && HasUMode(source_p, UMODE_INVISIBLE))
    ++Count.invisi;
  if ((old & UMODE_INVISIBLE) && !HasUMode(source_p, UMODE_INVISIBLE))
    --Count.invisi;

  assert(dlinkFind(&oper_list, source_p) == NULL);
  dlinkAdd(source_p, make_dlink_node(), &oper_list);

  AddOFlag(source_p, conf->port);

  if (HasOFlag(source_p, OPER_FLAG_ADMIN))
    AddUMode(source_p, UMODE_ADMIN);

  if (!EmptyString(conf->whois))
  {
    client_attach_svstag(source_p, RPL_WHOISOPERATOR, "+", conf->whois);
    sendto_server(source_p, 0, 0, ":%s SVSTAG %s %lu %u + :%s",
                  me.id, source_p->id, (unsigned long)source_p->tsinfo,
                  RPL_WHOISOPERATOR, conf->whois);
  }

  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE, "%s is now an operator",
                       get_oper_name(source_p));
  sendto_server(NULL, 0, 0, ":%s GLOBOPS :%s is now an operator",
                me.id, get_oper_name(source_p));
  send_umode_out(source_p, old);
  sendto_one_numeric(source_p, &me, RPL_YOUREOPER);
}
