/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_user.c: User related functions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "s_user.h"
#include "s_misc.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "fdlist.h"
#include "hash.h"
#include "irc_string.h"
#include "s_bsd.h"
#include "ircd.h"
#include "listener.h"
#include "motd.h"
#include "numeric.h"
#include "conf.h"
#include "log.h"
#include "s_serv.h"
#include "send.h"
#include "supported.h"
#include "whowas.h"
#include "memory.h"
#include "packet.h"
#include "rng_mt.h"
#include "userhost.h"
#include "hook.h"
#include "s_misc.h"
#include "parse.h"
#include "watch.h"


struct Callback *entering_umode_cb = NULL;
struct Callback *umode_cb = NULL;

static char umode_buffer[IRCD_BUFSIZE];

static void user_welcome(struct Client *);
static void report_and_set_user_flags(struct Client *, const struct MaskItem *);
static int check_xline(struct Client *);
static void introduce_client(struct Client *);
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

static dlink_list support_list = { NULL, NULL, 0 };
MessageFile *isupportFile;

/* memory is cheap. map 0-255 to equivalent mode */
unsigned int user_modes[256] =
{
  /* 0x00 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x0F */
  /* 0x10 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x1F */
  /* 0x20 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x2F */
  /* 0x30 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* 0x3F */
  0,                  /* @ */
  0,                  /* A */
  0,                  /* B */
  UMODE_CCONN_FULL,   /* C */
  UMODE_DEAF,         /* D */
  0,                  /* E */
  0,                  /* F */
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
  0,                  /* S */
  0,                  /* T */
  0,                  /* U */
  0,                  /* V */
  0,                  /* W */
  0,                  /* X */
  0,                  /* Y */
  0,                  /* Z 0x5A */
  0, 0, 0, 0, 0,      /* 0x5F   */ 
  0,                  /* 0x60   */
  UMODE_ADMIN,        /* a */
  UMODE_BOTS,         /* b */
  UMODE_CCONN,        /* c */
  UMODE_DEBUG,        /* d */
  0,                  /* e */
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
  0,                  /* q */
  UMODE_REGISTERED,   /* r */
  UMODE_SERVNOTICE,   /* s */
  0,                  /* t */
  UMODE_UNAUTH,       /* u */
  0,                  /* v */
  UMODE_WALLOP,       /* w */
  UMODE_EXTERNAL,     /* x */
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
  const char *from, *to;

  if (!MyConnect(source_p) && IsCapable(source_p->from, CAP_TS6) && HasID(source_p))
  {
    from = me.id;
    to = source_p->id;
  }
  else
  {
    from = me.name;
    to = source_p->name;
  }

  if (!ConfigServerHide.hide_servers || HasUMode(source_p, UMODE_OPER))
    sendto_one(source_p, form_str(RPL_LUSERCLIENT),
               from, to, (Count.total-Count.invisi),
               Count.invisi, dlink_list_length(&global_serv_list));
  else
    sendto_one(source_p, form_str(RPL_LUSERCLIENT), from, to,
               (Count.total-Count.invisi), Count.invisi, 1);

  if (Count.oper > 0)
    sendto_one(source_p, form_str(RPL_LUSEROP),
               from, to, Count.oper);

  if (dlink_list_length(&unknown_list) > 0)
    sendto_one(source_p, form_str(RPL_LUSERUNKNOWN),
               from, to, dlink_list_length(&unknown_list));

  if (dlink_list_length(&global_channel_list) > 0)
    sendto_one(source_p, form_str(RPL_LUSERCHANNELS),
               from, to, dlink_list_length(&global_channel_list));

  if (!ConfigServerHide.hide_servers || HasUMode(source_p, UMODE_OPER))
  {
    sendto_one(source_p, form_str(RPL_LUSERME),
               from, to, Count.local, Count.myserver);
    sendto_one(source_p, form_str(RPL_LOCALUSERS),
               from, to, Count.local, Count.max_loc,
               Count.local, Count.max_loc);
  }
  else
  {
    sendto_one(source_p, form_str(RPL_LUSERME),
               from, to, Count.total, 0);
    sendto_one(source_p, form_str(RPL_LOCALUSERS), 
               from, to, Count.total, Count.max_tot,
               Count.total, Count.max_tot);
  }

  sendto_one(source_p, form_str(RPL_GLOBALUSERS),
             from, to, Count.total, Count.max_tot,
             Count.total, Count.max_tot);

  if (!ConfigServerHide.hide_servers || HasUMode(source_p, UMODE_OPER))
    sendto_one(source_p, form_str(RPL_STATSCONN), from, to,
               Count.max_loc_con, Count.max_loc_cli, Count.totalrestartcount);

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
  send_message_file(source_p, isupportFile);
}

/*
** register_local_user
**      This function is called when both NICK and USER messages
**      have been accepted for the client, in whatever order. Only
**      after this, is the USER message propagated.
**
**      NICK's must be propagated at once when received, although
**      it would be better to delay them too until full info is
**      available. Doing it is not so simple though, would have
**      to implement the following:
**
**      (actually it has been implemented already for a while) -orabidoo
**
**      1) user telnets in and gives only "NICK foobar" and waits
**      2) another user far away logs in normally with the nick
**         "foobar" (quite legal, as this server didn't propagate
**         it).
**      3) now this server gets nick "foobar" from outside, but
**         has alread the same defined locally. Current server
**         would just issue "KILL foobar" to clean out dups. But,
**         this is not fair. It should actually request another
**         nick from local user or kill him/her...
*/
void
register_local_user(struct Client *source_p)
{
  const char *id = NULL;
  const struct MaskItem *conf = NULL;

  assert(source_p != NULL);
  assert(source_p == source_p->from);
  assert(MyConnect(source_p));
  assert(!source_p->localClient->registration);

  ClearCap(source_p, CAP_TS6);

  if (ConfigFileEntry.ping_cookie)
  {
    if (!IsPingSent(source_p) && source_p->localClient->random_ping == 0)
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

  if (valid_hostname(source_p->host) == 0)
  {
    sendto_one(source_p, ":%s NOTICE %s :*** Notice -- You have an illegal "
               "character in your hostname", me.name, source_p->name);
    strlcpy(source_p->host, source_p->sockhost,
            sizeof(source_p->host));
  }

  conf = source_p->localClient->confs.head->data;

  if (!IsGotId(source_p))
  {
    char username[USERLEN + 1];
    const char *p = username;
    unsigned int i = 0;

    if (IsNeedIdentd(conf))
    {
      ++ServerStats.is_ref;
      sendto_one(source_p, ":%s NOTICE %s :*** Notice -- You need to install "
                 "identd to use this server", me.name, source_p->name);
      exit_client(source_p, &me, "Install identd");
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

  /* password check */
  if (!EmptyString(conf->passwd))
  {
    const char *pass = source_p->localClient->passwd;

    if (!match_conf_password(pass, conf))
    {
      ++ServerStats.is_ref;
      sendto_one(source_p, form_str(ERR_PASSWDMISMATCH),
                 me.name, source_p->name);
      exit_client(source_p, &me, "Bad Password");
      return;
    }
  }

  /* don't free source_p->localClient->passwd here - it can be required
   * by masked /stats I if there are auth{} blocks with need_password = no;
   * --adx
   */

  /* report if user has &^>= etc. and set flags as needed in source_p */
  report_and_set_user_flags(source_p, conf);

  if (IsDead(source_p))
    return;

  /* Limit clients -
   * We want to be able to have servers and F-line clients
   * connect, so save room for "buffer" connections.
   * Smaller servers may want to decrease this, and it should
   * probably be just a percentage of the MAXCLIENTS...
   *   -Taner
   */
  /* Except "F:" clients */
  if ((Count.local >= ServerInfo.max_clients + MAX_BUFFER) ||
      (Count.local >= ServerInfo.max_clients && !IsExemptLimits(source_p)))
  {
    sendto_realops_flags(UMODE_FULL, L_ALL, SEND_NOTICE,
                         "Too many clients, rejecting %s[%s].",
                         source_p->name, source_p->host);
    ++ServerStats.is_ref;
    exit_client(source_p, &me, "Sorry, server is full - try later");
    return;
  }

  /* valid user name check */
  if (valid_username(source_p->username) == 0)
  {
    char tmpstr2[IRCD_BUFSIZE];

    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "Invalid username: %s (%s@%s)",
                         source_p->name, source_p->username, source_p->host);
    ++ServerStats.is_ref;
    snprintf(tmpstr2, sizeof(tmpstr2), "Invalid username [%s]",
             source_p->username);
    exit_client(source_p, &me, tmpstr2);
    return;
  }

  if (check_xline(source_p))
    return;

  while (hash_find_id((id = uid_get())) != NULL)
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

  sendto_realops_flags(UMODE_CCONN_FULL, L_ALL, SEND_NOTICE,
                       "CLICONN %s %s %s %s %s %s %s 0 %s",
                       source_p->name, source_p->username, source_p->host,
                       ConfigFileEntry.hide_spoof_ips && IsIPSpoof(source_p) ?
                       "255.255.255.255" : source_p->sockhost,
		       get_client_class(&source_p->localClient->confs),
		       ConfigFileEntry.hide_spoof_ips && IsIPSpoof(source_p) ?
                           "<hidden>" : source_p->localClient->client_host,
		       ConfigFileEntry.hide_spoof_ips && IsIPSpoof(source_p) ?
                           "<hidden>" : source_p->localClient->client_server,
                       source_p->info);


  if (ConfigFileEntry.invisible_on_connect)
  {
    AddUMode(source_p, UMODE_INVISIBLE);
    ++Count.invisi;
  }

  if ((++Count.local) > Count.max_loc)
  {
    Count.max_loc = Count.local;

    if (!(Count.max_loc % 10))
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "New Max Local Clients: %d",
                           Count.max_loc);
  }

  /* Increment our total user count here */
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
 *              - realname (gecos)
 * output	- NONE
 * side effects	- This function is called when a remote client
 *		  is introduced by a server.
 */
void
register_remote_user(struct Client *source_p,
                     const char *username, const char *host, const char *server,
                     const char *realname)
{
  struct Client *target_p = NULL;

  assert(source_p != NULL);
  assert(source_p->username != username);

  strlcpy(source_p->host, host, sizeof(source_p->host)); 
  strlcpy(source_p->username, username, sizeof(source_p->username));

  /*
   * coming from another server, take the servers word for it
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
    kill_client(source_p->from, source_p, "%s (Server doesn't exist)", me.name);

    AddFlag(source_p, FLAGS_KILLED);
    exit_client(source_p, &me, "Ghosted Client");
    return;
  }

  if ((target_p = source_p->servptr) && target_p->from != source_p->from)
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "Bad User [%s] :%s USER %s@%s %s, != %s[%s]",
                         source_p->from->name, source_p->name, source_p->username,
                         source_p->host, source_p->servptr->name,
                         target_p->name, target_p->from->name);
    kill_client(source_p->from, source_p,
                "%s (NICK from wrong direction (%s != %s))",
                me.name, source_p->servptr->name, target_p->from->name);
    AddFlag(source_p, FLAGS_KILLED);
    exit_client(source_p, &me, "USER server wrong direction");
    return;
  }

  /*
   * If the nick has been introduced by a services server,
   * make it a service as well.
   */
  if (HasFlag(source_p->servptr, FLAGS_SERVICE))
    AddFlag(source_p, FLAGS_SERVICE);

  /* Increment our total user count here */
  if (++Count.total > Count.max_tot)
    Count.max_tot = Count.total;

  SetClient(source_p);
  dlinkAdd(source_p, &source_p->lnode, &source_p->servptr->serv->client_list);
  add_user_host(source_p->username, source_p->host, 1);
  SetUserHost(source_p);

  introduce_client(source_p);
}

/* introduce_client()
 *
 * inputs	- source_p
 * output	- NONE
 * side effects - This common function introduces a client to the rest
 *		  of the net, either from a local client connect or
 *		  from a remote connect.
 */
static void
introduce_client(struct Client *source_p)
{
  dlink_node *server_node = NULL;
  static char ubuf[12];

  if (MyClient(source_p))
    send_umode(source_p, source_p, 0, SEND_UMODES, ubuf);
  else
    send_umode(NULL, source_p, 0, SEND_UMODES, ubuf);

  watch_check_hash(source_p, RPL_LOGON);

  if (*ubuf == '\0')
  {
    ubuf[0] = '+';
    ubuf[1] = '\0';
  }

  DLINK_FOREACH(server_node, serv_list.head)
  {
    struct Client *server = server_node->data;

    if (server == source_p->from)
        continue;

    if (IsCapable(server, CAP_SVS))
    {
      if (IsCapable(server, CAP_TS6) && HasID(source_p))
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
        sendto_one(server, "NICK %s %d %lu %s %s %s %s %s :%s",
                   source_p->name, source_p->hopcount+1,
                   (unsigned long)source_p->tsinfo,
                   ubuf, source_p->username, source_p->host,
                   source_p->servptr->name, source_p->svid,
                   source_p->info);

    }
    else
    {
      if (IsCapable(server, CAP_TS6) && HasID(source_p))
        sendto_one(server, ":%s UID %s %d %lu %s %s %s %s %s :%s",
                   source_p->servptr->id,
                   source_p->name, source_p->hopcount+1,
                   (unsigned long)source_p->tsinfo,
                   ubuf, source_p->username, source_p->host,
                   (MyClient(source_p) && IsIPSpoof(source_p)) ?
                   "0" : source_p->sockhost, source_p->id, source_p->info);
      else
        sendto_one(server, "NICK %s %d %lu %s %s %s %s :%s",
                   source_p->name, source_p->hopcount+1,
                   (unsigned long)source_p->tsinfo,
                   ubuf, source_p->username, source_p->host,
                   source_p->servptr->name, source_p->info);
    }
  }
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

  assert(p != NULL);

  if (*p == '.' || *p == ':')
    return 0;

  for (; *p; ++p)
    if (!IsHostChar(*p))
      return 0;

  return 1;
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
valid_username(const char *username)
{
  int dots      = 0;
  const char *p = username;

  assert(p != NULL);

  if (*p == '~')
    ++p;

  /* reject usernames that don't start with an alphanum
   * i.e. reject jokers who have '-@somehost' or '.@somehost'
   * or "-hi-@somehost", "h-----@somehost" would still be accepted.
   */
  if (!IsAlNum(*p))
    return 0;

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

  return 1;
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

  /* nicks can't start with a digit or - or be 0 length */
  /* This closer duplicates behaviour of hybrid-6 */
  if (*p == '-' || (IsDigit(*p) && local) || *p == '\0')
    return 0;

  for (; *p; ++p)
    if (!IsNickChar(*p))
      return 0;

  return p - nickname <= NICKLEN;
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
  {
    sendto_one(source_p,
               ":%s NOTICE %s :*** Spoofing your IP. congrats.",
               me.name, source_p->name);
  }

  /* If this user is in the exception class, Set it "E lined" */
  if (IsConfExemptKline(conf))
  {
    SetExemptKline(source_p);
    sendto_one(source_p,
               ":%s NOTICE %s :*** You are exempt from K/D/G lines. congrats.",
               me.name, source_p->name);
  }

  /* The else here is to make sure that G line exempt users
   * do not get noticed twice.
   */
  else if (IsConfExemptGline(conf))
  {
    SetExemptGline(source_p);
    sendto_one(source_p, ":%s NOTICE %s :*** You are exempt from G lines.",
               me.name, source_p->name);
  }

  if (IsConfExemptResv(conf))
  {
    SetExemptResv(source_p);
    sendto_one(source_p, ":%s NOTICE %s :*** You are exempt from resvs.",
               me.name, source_p->name);
  }

  /* If this user is exempt from user limits set it "F lined" */
  if (IsConfExemptLimits(conf))
  {
    SetExemptLimits(source_p);
    sendto_one(source_p,
               ":%s NOTICE %s :*** You are exempt from user limits. congrats.",
               me.name,source_p->name);
  }

  if (IsConfCanFlood(conf))
  {
    SetCanFlood(source_p);
    sendto_one(source_p, ":%s NOTICE %s :*** You are exempt from flood "
               "protection, aren't you fearsome.",
               me.name, source_p->name);
  }
}

/* change_simple_umode()
 *
 * this callback can be hooked to allow special handling of
 * certain usermodes
 */
static void *
change_simple_umode(va_list args)
{
  struct Client *client_p;
  struct Client *source_p;
  int what;
  unsigned int flag;

  client_p = va_arg(args, struct Client *);
  source_p = va_arg(args, struct Client *);
  what = va_arg(args, int);
  flag = va_arg(args, unsigned int);

  if (what == MODE_ADD)
    AddUMode(source_p, flag);
  else
    DelUMode(source_p, flag);

  return NULL;
}

/* set_user_mode()
 *
 * added 15/10/91 By Darren Reed.
 * parv[0] - sender
 * parv[1] - username to change mode for
 * parv[2] - modes to change
 */
void
set_user_mode(struct Client *client_p, struct Client *source_p,
              int parc, char *parv[])
{
  unsigned int flag, setflags;
  char **p, *m, buf[IRCD_BUFSIZE];
  struct Client *target_p;
  int what = MODE_ADD, badflag = 0, i;

  assert(!(parc < 2));

  if ((target_p = find_person(client_p, parv[1])) == NULL)
  {
    if (MyConnect(source_p))
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, source_p->name, parv[1]);
    return;
  }

  if (IsServer(source_p))
  {
     sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                          "*** Mode for User %s from %s",
                          parv[1], source_p->name);
     return;
  }

  if (source_p != target_p)
  {
     sendto_one(source_p, form_str(ERR_USERSDONTMATCH),
                me.name, source_p->name);
     return;
  }

  if (parc < 3)
  {
    m = buf;
    *m++ = '+';

    for (i = 0; i < 128; i++)
      if (HasUMode(source_p, user_modes[i]))
        *m++ = (char)i;
    *m = '\0';

    sendto_one(source_p, form_str(RPL_UMODEIS),
               me.name, source_p->name, buf);
    return;
  }

  execute_callback(entering_umode_cb, client_p, source_p);

  /* find flags already set for user */
  setflags = source_p->umodes;

  /* parse mode change string(s) */
  for (p = &parv[2]; p && *p; p++)
  {
    for (m = *p; *m; m++)
    {
      switch (*m)
      {
        case '+':
          what = MODE_ADD;
          break;
        case '-':
          what = MODE_DEL;
          break;
        case 'o':
          if (what == MODE_ADD)
          {
            if (IsServer(client_p) && !HasUMode(source_p, UMODE_OPER))
            {
              ++Count.oper;
              SetOper(source_p);
            }
          }
          else
          {
            /* Only decrement the oper counts if an oper to begin with
             * found by Pat Szuta, Perly , perly@xnet.com 
             */
            if (!HasUMode(source_p, UMODE_OPER))
              break;

            ClearOper(source_p);
            Count.oper--;

            if (MyConnect(source_p))
            {
              dlink_node *dm;

              detach_conf(source_p, CONF_OPER);
              ClrOFlag(source_p);
              DelUMode(source_p, ConfigFileEntry.oper_only_umodes);

              if ((dm = dlinkFindDelete(&oper_list, source_p)) != NULL)
                free_dlink_node(dm);
            }
          }

          break;

        /* we may not get these,
         * but they shouldnt be in default
         */
        case 'r':
        case ' ' :
        case '\n':
        case '\r':
        case '\t':
          break;

        default:
          if ((flag = user_modes[(unsigned char)*m]))
          {
            if (MyConnect(source_p) && !HasUMode(source_p, UMODE_OPER) &&
                (ConfigFileEntry.oper_only_umodes & flag))
            {
              badflag = 1;
            }
            else
              execute_callback(umode_cb, client_p, source_p, what, flag);
          }
          else
          {
            if (MyConnect(source_p))
              badflag = 1;
          }

          break;
      }
    }
  }

  if (badflag)
    sendto_one(source_p, form_str(ERR_UMODEUNKNOWNFLAG),
               me.name, source_p->name);

  if (HasUMode(source_p, UMODE_NCHANGE) && !HasOFlag(source_p, OPER_FLAG_N))
  {
    sendto_one(source_p, ":%s NOTICE %s :*** You have no nchange flag;",
               me.name, source_p->name);
    DelUMode(source_p, UMODE_NCHANGE);
  }

  if (MyConnect(source_p) && HasUMode(source_p, UMODE_ADMIN) &&
      !HasOFlag(source_p, OPER_FLAG_ADMIN))
  {
    sendto_one(source_p, ":%s NOTICE %s :*** You have no admin flag;",
               me.name, source_p->name);
    DelUMode(source_p, UMODE_ADMIN);
  }

  if (!(setflags & UMODE_INVISIBLE) && HasUMode(source_p, UMODE_INVISIBLE))
    ++Count.invisi;
  if ((setflags & UMODE_INVISIBLE) && !HasUMode(source_p, UMODE_INVISIBLE))
    --Count.invisi;

  /*
   * compare new flags with old flags and send string which
   * will cause servers to update correctly.
   */
  send_umode_out(client_p, source_p, setflags);
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
  unsigned int i;
  unsigned int flag;

  /*
   * build a string in umode_buf to represent the change in the user's
   * mode between the new (source_p->umodes) and 'old'.
   */
  for (i = 0; i < 128; i++)
  {
    flag = user_modes[i];
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
  char buf[IRCD_BUFSIZE] = { '\0' };
  dlink_node *ptr = NULL;

  send_umode(NULL, source_p, old, SEND_UMODES, buf);

  if (buf[0])
  {
    DLINK_FOREACH(ptr, serv_list.head)
    {
      struct Client *target_p = ptr->data;

      if ((target_p != client_p) && (target_p != source_p))
        sendto_one(target_p, ":%s MODE %s :%s",
                   ID_or_name(source_p, target_p),
                   ID_or_name(source_p, target_p), buf);
    }
  }

  if (client_p && MyClient(client_p))
    send_umode(client_p, source_p, old, 0xffffffff, buf);
}

/* user_welcome()
 *
 * inputs	- client pointer to client to welcome
 * output	- NONE
 * side effects	-
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
  if (source_p->localClient->fd.ssl != NULL)
    sendto_one(source_p, ":%s NOTICE %s :*** Connected securely via %s",
               me.name, source_p->name,
               ssl_get_cipher(source_p->localClient->fd.ssl));
#endif

  sendto_one(source_p, form_str(RPL_WELCOME), me.name, source_p->name, 
             ServerInfo.network_name, source_p->name);
  sendto_one(source_p, form_str(RPL_YOURHOST), me.name, source_p->name,
             get_listener_name(source_p->localClient->listener), ircd_version);
  sendto_one(source_p, form_str(RPL_CREATED),
             me.name, source_p->name, built_date);
  sendto_one(source_p, form_str(RPL_MYINFO),
             me.name, source_p->name, me.name, ircd_version, umode_buffer);
  show_isupport(source_p);

  if (source_p->id[0] != '\0')
    sendto_one(source_p, form_str(RPL_YOURID), me.name,
               source_p->name, source_p->id);

  show_lusers(source_p);

  if (ConfigFileEntry.short_motd)
  {
    sendto_one(source_p, ":%s NOTICE %s :*** Notice -- motd was last changed at %s",
               me.name, source_p->name, ConfigFileEntry.motd.lastChangedDate);
    sendto_one(source_p,
               ":%s NOTICE %s :*** Notice -- Please read the motd if you haven't "
               "read it", me.name, source_p->name);
    sendto_one(source_p, form_str(RPL_MOTDSTART),
               me.name, source_p->name, me.name);
    sendto_one(source_p, form_str(RPL_MOTD),
               me.name, source_p->name,
               "*** This is the short motd ***");
    sendto_one(source_p, form_str(RPL_ENDOFMOTD),
               me.name, source_p->name);
  }
  else  
    send_message_file(source_p, &ConfigFileEntry.motd);
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

  if ((conf = find_matching_name_conf(CONF_XLINE, source_p->info, NULL, NULL, 0)) ||
      (conf = find_matching_name_conf(CONF_RXLINE, source_p->info, NULL, NULL, 0)))
  {
    ++conf->count;

    if (conf->reason != NULL)
      reason = conf->reason;
    else
      reason = "No Reason";

    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "X-line Rejecting [%s] [%s], user %s [%s]",
                         source_p->info, reason,
                         get_client_name(source_p, HIDE_IP),
                         source_p->sockhost);

    ++ServerStats.is_ref;
    exit_client(source_p, &me, "Bad user info");
    return 1;
  }

  return 0;
}

/* oper_up()
 *
 * inputs	- pointer to given client to oper
 * output	- NONE
 * side effects	- Blindly opers up given source_p, using conf info
 *                all checks on passwords have already been done.
 *                This could also be used by rsa oper routines. 
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
  if (!HasOFlag(source_p, OPER_FLAG_N))
    DelUMode(source_p, UMODE_NCHANGE);

  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE, "%s is now an operator",
                       get_oper_name(source_p));
  send_umode_out(source_p, source_p, old);
  sendto_one(source_p, form_str(RPL_YOUREOPER), me.name, source_p->name);
}

static char new_uid[TOTALSIDUID + 1];     /* allow for \0 */

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
  int i;

  memset(new_uid, 0, sizeof(new_uid));

  if (!EmptyString(ServerInfo.sid))
    strlcpy(new_uid, ServerInfo.sid, sizeof(new_uid));

  for (i = 0; i < IRC_MAXSID; ++i)
    if (new_uid[i] == '\0') 
      new_uid[i] = 'A';

  /* NOTE: if IRC_MAXUID != 6, this will have to be rewritten */
  /* Yes nenolod, I have known it was off by one ever since I wrote it
   * But *JUST* for you, though, it really doesn't look as *pretty*
   * -Dianora
   */
  memcpy(new_uid + IRC_MAXSID, "AAAAA@", IRC_MAXUID);

  entering_umode_cb = register_callback("entering_umode", NULL);
  umode_cb = register_callback("changing_umode", change_simple_umode);
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
  if (i != IRC_MAXSID)    /* Not reached server SID portion yet? */
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
  add_one_to_uid(TOTALSIDUID - 1);    /* index from 0 */
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
  isupportFile = init_MessageLine();

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
    support = MyMalloc(sizeof(*support));
    dlinkAddTail(support, &support->node, &support_list);
  }

  support->name = xstrdup(name);
  if (options != NULL)
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
  dlink_node *ptr = NULL;
  int n = 0;
  int tokens = 0;
  size_t len = 0;
  size_t reserve = strlen(me.name) + HOSTLEN + strlen(form_str(RPL_ISUPPORT));

  destroy_MessageLine(isupportFile);

  DLINK_FOREACH(ptr, support_list.head)
  {
    struct Isupport *support = ptr->data;

    p += (n = sprintf(p, "%s", support->name));
    len += n;

    if (support->options != NULL)
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

      addto_MessageLine(isupportFile, isupportbuffer);
      p = isupportbuffer;
      len = 0;
      n = tokens = 0;
    }
  }

  if (len != 0)
  {
    if (*--p == ' ')
      *p = '\0';
    addto_MessageLine(isupportFile, isupportbuffer);
  }
}
