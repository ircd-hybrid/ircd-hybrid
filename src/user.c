/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 */

/*! \file s_user.c
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
#include "irc_string.h"
#include "ircd.h"
#include "listener.h"
#include "motd.h"
#include "numeric.h"
#include "conf.h"
#include "log.h"
#include "server.h"
#include "send.h"
#include "supported.h"
#include "memory.h"
#include "packet.h"
#include "rng_mt.h"
#include "userhost.h"
#include "misc.h"
#include "parse.h"
#include "watch.h"

static char umode_buffer[IRCD_BUFSIZE];
static const char *uid_get(void);

/* Used for building up the isupport string,
 * used with init_isupport, add_isupport, delete_isupport
 */
struct Isupport
{
  dlink_node node;
  char *name;
  char *options;
  int number;
};

static dlink_list support_list;
static dlink_list support_list_lines;

/* memory is cheap. map 0-255 to equivalent mode */
const unsigned int user_modes[256] =
{
  /* 0x00 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x0F */
  /* 0x10 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x1F */
  /* 0x20 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x2F */
  /* 0x30 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x3F */
  0,                  /* @ */
  0,                  /* A */
  0,                  /* B */
  0,                  /* C */
  UMODE_DEAF,         /* D */
  0,                  /* E */
  UMODE_FARCONNECT,   /* F */
  UMODE_SOFTCALLERID, /* G */
  UMODE_HIDDEN,       /* H */
  0,                  /* I */
  0,                  /* J */
  0,                  /* K */
  0,                  /* L */
  0,                  /* M */
  0,                  /* N */
  0,                  /* O */
  0,                  /* P */
  0,                  /* Q */
  UMODE_REGONLY,      /* R */
  UMODE_SSL,          /* S */
  0,                  /* T */
  0,                  /* U */
  0,                  /* V */
  UMODE_WEBIRC,       /* W */
  0,                  /* X */
  0,                  /* Y */
  0,                  /* Z 0x5A */
  0, 0, 0, 0, 0,      /* 0x5F   */
  0,                  /* 0x60   */
  UMODE_ADMIN,        /* a */
  UMODE_BOTS,         /* b */
  UMODE_CCONN,        /* c */
  UMODE_DEBUG,        /* d */
  UMODE_EXTERNAL,     /* e */
  UMODE_FULL,         /* f */
  UMODE_CALLERID,     /* g */
  0,                  /* h */
  UMODE_INVISIBLE,    /* i */
  UMODE_REJ,          /* j */
  UMODE_SKILL,        /* k */
  UMODE_LOCOPS,       /* l */
  0,                  /* m */
  UMODE_NCHANGE,      /* n */
  UMODE_OPER,         /* o */
  0,                  /* p */
  UMODE_HIDEIDLE,     /* q */
  UMODE_REGISTERED,   /* r */
  UMODE_SERVNOTICE,   /* s */
  0,                  /* t */
  UMODE_UNAUTH,       /* u */
  0,                  /* v */
  UMODE_WALLOP,       /* w */
  UMODE_HIDDENHOST,   /* x */
  UMODE_SPY,          /* y */
  UMODE_OPERWALL,     /* z      0x7A */
  0,0,0,0,0,          /* 0x7B - 0x7F */

  /* 0x80 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x8F */
  /* 0x90 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x9F */
  /* 0xA0 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0xAF */
  /* 0xB0 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0xBF */
  /* 0xC0 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0xCF */
  /* 0xD0 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0xDF */
  /* 0xE0 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0xEF */
  /* 0xF0 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0  /* 0xFF */
};

void
assemble_umode_buffer(void)
{
  unsigned int idx = 0;
  char *umode_buffer_ptr = umode_buffer;

  for (; idx < (sizeof(user_modes) / sizeof(user_modes[0])); ++idx)
    if (user_modes[idx])
      *umode_buffer_ptr++ = idx;

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
    sendto_one_numeric(source_p, &me, RPL_LUSERCLIENT, (Count.total-Count.invisi),
                       Count.invisi, dlink_list_length(&global_serv_list));
  else
    sendto_one_numeric(source_p, &me, RPL_LUSERCLIENT,
                       (Count.total - Count.invisi), Count.invisi, 1);

  if (Count.oper)
    sendto_one_numeric(source_p, &me, RPL_LUSEROP, Count.oper);

  if (dlink_list_length(&unknown_list))
    sendto_one_numeric(source_p, &me, RPL_LUSERUNKNOWN, dlink_list_length(&unknown_list));

  if (dlink_list_length(&global_channel_list))
    sendto_one_numeric(source_p, &me, RPL_LUSERCHANNELS, dlink_list_length(&global_channel_list));

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

/* show_isupport()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects	- display to client what we support (for them)
 */
void
show_isupport(struct Client *source_p)
{
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, support_list_lines.head)
    sendto_one_numeric(source_p, &me, RPL_ISUPPORT, ptr->data);
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

  /* If this user is in the exception class, Set it "E lined" */
  if (IsConfExemptKline(conf))
  {
    SetExemptKline(source_p);
    sendto_one_notice(source_p, &me, ":*** You are exempt from K/D/G lines. Congrats.");
  }

  /*
   * The else here is to make sure that G line exempt users
   * do not get noticed twice.
   */
  else if (IsConfExemptGline(conf))
  {
    SetExemptGline(source_p);
    sendto_one_notice(source_p, &me, ":*** You are exempt from G lines. Congrats.");
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
  dlink_node *ptr = NULL;
  char ubuf[IRCD_BUFSIZE] = "";

  if (MyClient(source_p))
    send_umode(source_p, source_p, 0, SEND_UMODES, ubuf);
  else
    send_umode(NULL, source_p, 0, SEND_UMODES, ubuf);

  watch_check_hash(source_p, RPL_LOGON);

  if (ubuf[0] == '\0')
  {
    ubuf[0] = '+';
    ubuf[1] = '\0';
  }

  DLINK_FOREACH(ptr, serv_list.head)
  {
    struct Client *server = ptr->data;

    if (server == source_p->from)
      continue;

    if (IsCapable(server, CAP_SVS))
      sendto_one(server, ":%s UID %s %d %lu %s %s %s %s %s %s :%s",
                 source_p->servptr->id,
                 source_p->name, source_p->hopcount+1,
                 (unsigned long)source_p->tsinfo,
                 ubuf, source_p->username, source_p->host,
                 (MyClient(source_p) && IsIPSpoof(source_p)) ?
                 "0" : source_p->sockhost, source_p->id,
                 source_p->svid,
                 source_p->info);
    else
      sendto_one(server, ":%s UID %s %d %lu %s %s %s %s %s :%s",
                 source_p->servptr->id,
                 source_p->name, source_p->hopcount+1,
                 (unsigned long)source_p->tsinfo,
                 ubuf, source_p->username, source_p->host,
                 (MyClient(source_p) && IsIPSpoof(source_p)) ?
                 "0" : source_p->sockhost, source_p->id, source_p->info);

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
                      ssl_get_cipher(source_p->localClient->fd.ssl));
  }
#endif

  sendto_one_numeric(source_p, &me, RPL_WELCOME, ServerInfo.network_name,
                     source_p->name);
  sendto_one_numeric(source_p, &me, RPL_YOURHOST,
                     get_listener_name(source_p->localClient->listener), ircd_version);
  sendto_one_numeric(source_p, &me, RPL_CREATED, built_date);
  sendto_one_numeric(source_p, &me, RPL_MYINFO, me.name, ircd_version, umode_buffer);
  show_isupport(source_p);

  if (source_p->id[0])
    sendto_one_numeric(source_p, &me, RPL_YOURID, source_p->id);

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
  const char *reason = NULL;

  if ((conf = find_matching_name_conf(CONF_XLINE, source_p->info, NULL, NULL, 0)))
  {
    ++conf->count;

    if (conf->reason)
      reason = conf->reason;
    else
      reason = CONF_NOREASON;

    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "X-line Rejecting [%s] [%s], user %s [%s]",
                         source_p->info, reason,
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
  assert(!source_p->localClient->registration);

  ClearCap(source_p, CAP_TS6);

  if (ConfigFileEntry.ping_cookie)
  {
    if (!IsPingSent(source_p) && !source_p->localClient->random_ping)
    {
      do
        source_p->localClient->random_ping = genrand_int32();
      while (!source_p->localClient->random_ping);

      sendto_one(source_p, "PING :%u",
                 source_p->localClient->random_ping);
      SetPingSent(source_p);
      return;
    }

    if (!HasPingCookie(source_p))
      return;
  }

  source_p->localClient->last_privmsg = CurrentTime;
  /* Straight up the maximum rate of flooding... */
  source_p->localClient->allow_read = MAX_FLOOD_BURST;

  if (!check_client(source_p))
    return;

  if (!valid_hostname(source_p->host))
  {
    sendto_one_notice(source_p, &me, ":*** Notice -- You have an illegal "
                      "character in your hostname");
    strlcpy(source_p->host, source_p->sockhost,
            sizeof(source_p->host));
  }

  conf = source_p->localClient->confs.head->data;

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
      if (*p != '[')
        source_p->username[i++] = *p;

    source_p->username[i] = '\0';
  }

  /* Password check */
  if (!EmptyString(conf->passwd))
  {
    const char *pass = source_p->localClient->passwd;

    if (!match_conf_password(pass, conf))
    {
      ++ServerStats.is_ref;

      sendto_one_numeric(source_p, &me, ERR_PASSWDMISMATCH);
      exit_client(source_p, "Bad Password");
      return;
    }
  }

  /*
   * Don't free source_p->localClient->passwd here - it can be required
   * by masked /stats I if there are auth{} blocks with need_password = no;
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
  if ((Count.local >= ServerInfo.max_clients + MAX_BUFFER) ||
      (Count.local >= ServerInfo.max_clients && !IsExemptLimits(source_p)))
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
                       ConfigFileEntry.hide_spoof_ips && IsIPSpoof(source_p) ?
                       "255.255.255.255" : source_p->sockhost,
                       get_client_class(&source_p->localClient->confs),
                       source_p->info, source_p->id);

  if (ConfigFileEntry.invisible_on_connect)
  {
    AddUMode(source_p, UMODE_INVISIBLE);
    ++Count.invisi;
  }

  if (++Count.local > Count.max_loc)
  {
    Count.max_loc = Count.local;

    if (!(Count.max_loc % 10))
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "New Max Local Clients: %d",
                           Count.max_loc);
  }

  if (++Count.total > Count.max_tot)
    Count.max_tot = Count.total;
  ++Count.totalrestartcount;

  assert(source_p->servptr == &me);
  SetClient(source_p);
  dlinkAdd(source_p, &source_p->lnode, &source_p->servptr->serv->client_list);

  source_p->localClient->allow_read = MAX_FLOOD_BURST;

  assert(dlinkFind(&unknown_list, source_p));

  dlink_move_node(&source_p->localClient->lclient_node,
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
register_remote_user(struct Client *source_p, const char *username,
                     const char *host, const char *server)
{
  struct Client *target_p = NULL;

  assert(source_p->username != username);

  strlcpy(source_p->host, host, sizeof(source_p->host));
  strlcpy(source_p->username, username, sizeof(source_p->username));

  /*
   * Coming from another server, take the servers word for it
   */
  source_p->servptr = hash_find_server(server);

  /*
   * Super GhostDetect:
   * If we can't find the server the user is supposed to be on,
   * then simply blow the user away.        -Taner
   */
  if (source_p->servptr == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "No server %s for user %s[%s@%s] from %s",
                         server, source_p->name, source_p->username,
                         source_p->host, source_p->from->name);
    sendto_one(source_p->from,
               ":%s KILL %s :%s (Ghosted, server %s doesn't exist)",
               me.id, source_p->id, me.name, server);

    AddFlag(source_p, FLAGS_KILLED);
    exit_client(source_p, "Ghosted Client");
    return;
  }

  if ((target_p = source_p->servptr) && target_p->from != source_p->from)
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "Bad User [%s] :%s USER %s@%s %s, != %s[%s]",
                         source_p->from->name, source_p->name, source_p->username,
                         source_p->host, source_p->servptr->name,
                         target_p->name, target_p->from->name);
    sendto_one(source_p->from,
               ":%s KILL %s :%s (NICK from wrong direction (%s != %s))",
               me.id, source_p->id, me.name, source_p->servptr->name,
               target_p->from->name);

    AddFlag(source_p, FLAGS_KILLED);
    exit_client(source_p, "USER server wrong direction");
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
  add_user_host(source_p->username, source_p->host, 1);
  SetUserHost(source_p);

  if (HasFlag(source_p->servptr, FLAGS_EOB))
    sendto_realops_flags(UMODE_FARCONNECT, L_ALL, SEND_NOTICE,
                         "Client connecting at %s: %s (%s@%s) [%s] <%s>",
                         source_p->servptr->name,
                         source_p->name, source_p->username, source_p->host,
                         source_p->info, source_p->id);

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
  int dots      = 0;
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
      if ((*p == '.') && ConfigFileEntry.dots_in_ident)
      {
        if (++dots > ConfigFileEntry.dots_in_ident)
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

  return  p - username <= USERLEN;;
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

  assert(nickname && *nickname);

  /*
   * Nicks can't start with a digit or - or be 0 length.
   */
  if (*p == '-' || (IsDigit(*p) && local) || *p == '\0')
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
           unsigned int old, unsigned int sendmask, char *umode_buf)
{
  char *m = umode_buf;
  int what = 0;

  /*
   * Build a string in umode_buf to represent the change in the user's
   * mode between the new (source_p->umodes) and 'old'.
   */
  for (unsigned int i = 0; i < 128; ++i)
  {
    unsigned int flag = user_modes[i];

    if (!flag)
      continue;

    if (MyClient(source_p) && !(flag & sendmask))
      continue;

    if ((flag & old) && !HasUMode(source_p, flag))
    {
      if (what == MODE_DEL)
        *m++ = (char)i;
      else
      {
        what = MODE_DEL;
        *m++ = '-';
        *m++ = (char)i;
      }
    }
    else if (!(flag & old) && HasUMode(source_p, flag))
    {
      if (what == MODE_ADD)
        *m++ = (char)i;
      else
      {
        what = MODE_ADD;
        *m++ = '+';
        *m++ = (char)i;
      }
    }
  }

  *m = '\0';

  if (*umode_buf && client_p)
    sendto_one(client_p, ":%s!%s@%s MODE %s :%s",
               source_p->name, source_p->username,
               source_p->host, source_p->name, umode_buf);
}

/* send_umode_out()
 *
 * inputs	-
 * output	- NONE
 * side effects - Only send ubuf out to servers that know about this client
 */
void
send_umode_out(struct Client *client_p, struct Client *source_p,
               unsigned int old)
{
  char buf[IRCD_BUFSIZE] = "";

  send_umode(NULL, source_p, old, SEND_UMODES, buf);

  if (buf[0])
    sendto_server(source_p, NOCAPS, NOCAPS, ":%s MODE %s :%s",
                  source_p->id, source_p->id, buf);

  if (client_p && MyClient(client_p))
    send_umode(client_p, source_p, old, 0xffffffff, buf);
}

void
user_set_hostmask(struct Client *target_p, const char *hostname, const int what)
{
  dlink_node *ptr = NULL;

  if (!strcmp(target_p->host, hostname))
    return;

  switch (what)
  {
    case MODE_ADD:
      AddUMode(target_p, UMODE_HIDDENHOST);
      AddFlag(target_p, FLAGS_IP_SPOOFING);
      break;
    case MODE_DEL:
      DelUMode(target_p, UMODE_HIDDENHOST);

      if (!HasFlag(target_p, FLAGS_AUTH_SPOOF))
        DelFlag(target_p, FLAGS_IP_SPOOFING);
      break;
    default: return;
  }

  if (ConfigFileEntry.cycle_on_host_change)
    sendto_common_channels_local(target_p, 0, 0, ":%s!%s@%s QUIT :Changing hostname",
                                 target_p->name, target_p->username, target_p->host);

  if (IsUserHostIp(target_p))
    delete_user_host(target_p->username, target_p->host, !MyConnect(target_p));

  strlcpy(target_p->host, hostname, sizeof(target_p->host));

  add_user_host(target_p->username, target_p->host, !MyConnect(target_p));
  SetUserHost(target_p);

  if (MyClient(target_p))
  {
    sendto_one_numeric(target_p, &me, RPL_NEWHOSTIS, target_p->host);
    clear_ban_cache_client(target_p);
  }

  if (!ConfigFileEntry.cycle_on_host_change)
    return;

  DLINK_FOREACH(ptr, target_p->channel.head)
  {
    char modebuf[4], nickbuf[NICKLEN * 3 + 3] = "";
    char *p = modebuf;
    int len = 0;
    const struct Membership *ms = ptr->data;

    if (has_member_flags(ms, CHFL_CHANOP))
    {
      *p++ = 'o';
      len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", target_p->name);
    }

    if (has_member_flags(ms, CHFL_HALFOP))
    {
      *p++ = 'h';
      len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", target_p->name);
    }

    if (has_member_flags(ms, CHFL_VOICE))
    {
      *p++ = 'v';
      len += snprintf(nickbuf + len, sizeof(nickbuf) - len, len ? " %s" : "%s", target_p->name);
    }

    *p = '\0';

    sendto_channel_local_butone(target_p, 0, 0, ms->chptr, ":%s!%s@%s JOIN :%s",
                                target_p->name, target_p->username, target_p->host,
                                ms->chptr->chname);
    if (nickbuf[0])
      sendto_channel_local_butone(target_p, 0, 0, ms->chptr, ":%s MODE %s +%s %s",
                                  target_p->servptr->name, ms->chptr->chname,
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
oper_up(struct Client *source_p)
{
  const unsigned int old = source_p->umodes;
  const struct MaskItem *conf = source_p->localClient->confs.head->data;

  assert(source_p->localClient->confs.head);

  ++Count.oper;
  SetOper(source_p);

  if (conf->modes)
    AddUMode(source_p, conf->modes);
  else if (ConfigFileEntry.oper_umodes)
    AddUMode(source_p, ConfigFileEntry.oper_umodes);

  if (!(old & UMODE_INVISIBLE) && HasUMode(source_p, UMODE_INVISIBLE))
    ++Count.invisi;
  if ((old & UMODE_INVISIBLE) && !HasUMode(source_p, UMODE_INVISIBLE))
    --Count.invisi;

  assert(dlinkFind(&oper_list, source_p) == NULL);
  dlinkAdd(source_p, make_dlink_node(), &oper_list);

  AddOFlag(source_p, conf->port);

  if (HasOFlag(source_p, OPER_FLAG_ADMIN))
    AddUMode(source_p, UMODE_ADMIN);

  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE, "%s is now an operator",
                       get_oper_name(source_p));
  send_umode_out(source_p, source_p, old);
  sendto_one_numeric(source_p, &me, RPL_YOUREOPER);
}

static char new_uid[TOTALSIDUID + 1];  /* Allow for \0 */

int
valid_sid(const char *sid)
{
  if (strlen(sid) == IRC_MAXSID)
    if (IsDigit(*sid))
      if (IsAlNum(*(sid + 1)) && IsAlNum(*(sid + 2)))
        return 1;

  return 0;
}

/*
 * init_uid()
 *
 * inputs	- NONE
 * output	- NONE
 * side effects	- new_uid is filled in with server id portion (sid)
 *		  (first 3 bytes) or defaulted to 'A'.
 *	          Rest is filled in with 'A'
 */
void
init_uid(void)
{
  memset(new_uid, 0, sizeof(new_uid));

  if (!EmptyString(ServerInfo.sid))
    strlcpy(new_uid, ServerInfo.sid, sizeof(new_uid));

  for (unsigned int i = 0; i < IRC_MAXSID; ++i)
    if (new_uid[i] == '\0')
      new_uid[i] = 'A';

  /* NOTE: if IRC_MAXUID != 6, this will have to be rewritten */
  memcpy(new_uid + IRC_MAXSID, "AAAAA@", IRC_MAXUID);
}

/*
 * add_one_to_uid
 *
 * inputs	- index number into new_uid
 * output	- NONE
 * side effects	- new_uid is incremented by one
 *		  note this is a recursive function
 */
static void
add_one_to_uid(int i)
{
  if (i != IRC_MAXSID)  /* Not reached server SID portion yet? */
  {
    if (new_uid[i] == 'Z')
      new_uid[i] = '0';
    else if (new_uid[i] == '9')
    {
      new_uid[i] = 'A';
      add_one_to_uid(i-1);
    }
    else
      ++new_uid[i];
  }
  else
  {
    /* NOTE: if IRC_MAXUID != 6, this will have to be rewritten */
    if (new_uid[i] == 'Z')
      memcpy(new_uid + IRC_MAXSID, "AAAAAA", IRC_MAXUID);
    else
      ++new_uid[i];
  }
}

/*
 * uid_get
 *
 * inputs       - struct Client *
 * output       - new UID is returned to caller
 * side effects - new_uid is incremented by one.
 */
static const char *
uid_get(void)
{
  add_one_to_uid(TOTALSIDUID - 1);  /* Index from 0 */
  return new_uid;
}

/*
 * init_isupport()
 *
 * input	- NONE
 * output	- NONE
 * side effects	- Must be called before isupport is enabled
 */
void
init_isupport(void)
{
  add_isupport("CALLERID", NULL, -1);
  add_isupport("CASEMAPPING", CASEMAP, -1);
  add_isupport("DEAF", "D", -1);
  add_isupport("KICKLEN", NULL, KICKLEN);
  add_isupport("MODES", NULL, MAXMODEPARAMS);
#ifdef HALFOPS
  add_isupport("PREFIX", "(ohv)@%+", -1);
  add_isupport("STATUSMSG", "@%+", -1);
#else
  add_isupport("PREFIX", "(ov)@+", -1);
  add_isupport("STATUSMSG", "@+", -1);
#endif
  add_isupport("EXCEPTS", "e", -1);
  add_isupport("INVEX", "I", -1);
}

/*
 * add_isupport()
 *
 * input	- name of supported function
 *		- options if any
 *		- number if any
 * output	- NONE
 * side effects	- Each supported item must call this when activated
 */
void
add_isupport(const char *name, const char *options, int n)
{
  dlink_node *ptr;
  struct Isupport *support;

  DLINK_FOREACH(ptr, support_list.head)
  {
    support = ptr->data;
    if (irccmp(support->name, name) == 0)
    {
      MyFree(support->name);
      MyFree(support->options);
      break;
    }
  }

  if (ptr == NULL)
  {
    support = MyCalloc(sizeof(*support));
    dlinkAddTail(support, &support->node, &support_list);
  }

  support->name = xstrdup(name);
  if (options)
    support->options = xstrdup(options);
  support->number = n;

  rebuild_isupport_message_line();
}

/*
 * delete_isupport()
 *
 * input	- name of supported function
 * output	- NONE
 * side effects	- Each supported item must call this when deactivated
 */
void
delete_isupport(const char *name)
{
  dlink_node *ptr;
  struct Isupport *support;

  DLINK_FOREACH(ptr, support_list.head)
  {
    support = ptr->data;
    if (irccmp(support->name, name) == 0)
    {
      dlinkDelete(ptr, &support_list);
      MyFree(support->name);
      MyFree(support->options);
      MyFree(support);
      break;
    }
  }

  rebuild_isupport_message_line();
}

/*
 * rebuild_isupport_message_line
 *
 * input	- NONE
 * output	- NONE
 * side effects	- Destroy the isupport MessageFile lines, and rebuild.
 */
void
rebuild_isupport_message_line(void)
{
  char isupportbuffer[IRCD_BUFSIZE];
  char *p = isupportbuffer;
  dlink_node *ptr = NULL, *ptr_next = NULL;
  int n = 0;
  int tokens = 0;
  size_t len = 0;
  size_t reserve = strlen(me.name) + HOSTLEN + strlen(numeric_form(RPL_ISUPPORT));

  DLINK_FOREACH_SAFE(ptr, ptr_next, support_list_lines.head)
  {
    dlinkDelete(ptr, &support_list_lines);
    MyFree(ptr->data);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH(ptr, support_list.head)
  {
    struct Isupport *support = ptr->data;

    p += (n = sprintf(p, "%s", support->name));
    len += n;

    if (support->options)
    {
      p += (n = sprintf(p, "=%s", support->options));
      len += n;
    }

    if (support->number > 0)
    {
      p += (n = sprintf(p, "=%d", support->number));
      len += n;
    }

    *p++ = ' ';
    len++;
    *p = '\0';

    if (++tokens == (MAXPARA-2) || len >= (sizeof(isupportbuffer)-reserve))
    { /* arbritrary for now */
      if (*--p == ' ')
        *p = '\0';

      dlinkAddTail(xstrdup(isupportbuffer), make_dlink_node(), &support_list_lines);
      p = isupportbuffer;
      len = 0;
      n = tokens = 0;
    }
  }

  if (len)
  {
    if (*--p == ' ')
      *p = '\0';
    dlinkAddTail(xstrdup(isupportbuffer), make_dlink_node(), &support_list_lines);
  }
}
