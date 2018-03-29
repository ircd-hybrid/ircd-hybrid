/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2018 ircd-hybrid development team
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

/*! \file client.h
 * \brief Header including structures, macros and prototypes for client handling
 * \version $Id$
 */


#ifndef INCLUDED_client_h
#define INCLUDED_client_h

#include "list.h"
#include "fdlist.h"
#include "ircd_defs.h"
#include "dbuf.h"
#include "channel.h"
#include "auth.h"


/*
 * status macros.
 */
enum
{
  STAT_CONNECTING = 1,
  STAT_HANDSHAKE,
  STAT_ME,
  STAT_UNKNOWN,
  STAT_SERVER,
  STAT_CLIENT
};

enum
{
  REG_NEED_USER = 1 << 0,  /**< User must send USER command */
  REG_NEED_NICK = 1 << 1,  /**< User must send NICK command */
  REG_NEED_CAP  = 1 << 2,  /**< In middle of CAP negotiations */
  REG_INIT      = REG_NEED_USER | REG_NEED_NICK
};

#define ID_or_name(x,client_p)  ((IsServer(client_p->from) && (x)->id[0]) ? (x)->id : (x)->name)

#define IsConnecting(x)         ((x)->status == STAT_CONNECTING)
#define IsHandshake(x)          ((x)->status == STAT_HANDSHAKE)
#define IsMe(x)                 ((x)->status == STAT_ME)
#define IsUnknown(x)            ((x)->status == STAT_UNKNOWN)
#define IsServer(x)             ((x)->status == STAT_SERVER)
#define IsClient(x)             ((x)->status == STAT_CLIENT)

#define SetConnecting(x)        {(x)->status = STAT_CONNECTING; \
                                 (x)->handler = UNREGISTERED_HANDLER; }

#define SetHandshake(x)         {(x)->status = STAT_HANDSHAKE; \
                                 (x)->handler = UNREGISTERED_HANDLER; }

#define SetMe(x)                {(x)->status = STAT_ME; \
                                 (x)->handler = UNREGISTERED_HANDLER; }

#define SetUnknown(x)           {(x)->status = STAT_UNKNOWN; \
                                 (x)->handler = UNREGISTERED_HANDLER; }

#define SetServer(x)            {(x)->status = STAT_SERVER; \
                                 (x)->handler = SERVER_HANDLER; }

#define SetClient(x)            {(x)->status = STAT_CLIENT; \
                                 (x)->handler = CLIENT_HANDLER; }

#define MyConnect(x)            ((x)->connection != NULL)
#define MyClient(x)             (MyConnect(x) && IsClient(x))

/*
 * ts stuff
 */
enum
{
  TS_CURRENT = 6,  /**< Current TS protocol version */
  TS_MIN     = 6   /**< Minimum supported TS protocol version */
};

enum
{
  CAP_MULTI_PREFIX   = 1 << 0,  /**< ircv3.1 multi-prefix client capability */
  CAP_AWAY_NOTIFY    = 1 << 1,  /**< ircv3.1 away-notify client capability */
  CAP_UHNAMES        = 1 << 2,  /**< ircv3.2 userhost-in-names client capability */
  CAP_EXTENDED_JOIN  = 1 << 3,  /**< ircv3.1 extended-join client capability */
  CAP_ACCOUNT_NOTIFY = 1 << 4,  /**< ircv3.1 account-notify client capability */
  CAP_INVITE_NOTIFY  = 1 << 5,  /**< ircv3.2 invite-notify client capability */
  CAP_CHGHOST        = 1 << 6   /**< ircv3.2 chghost client capability */
};

#define HasCap(x, y) ((x)->connection->cap_active & (y))


/* housekeeping flags */
enum
{
  FLAGS_PINGSENT      = 1 <<  0,  /**< Unreplied ping sent */
  FLAGS_DEADSOCKET    = 1 <<  1,  /**< Local socket is dead--Exiting soon */
  FLAGS_KILLED        = 1 <<  2,  /**< Prevents "QUIT" from being sent for this */
  FLAGS_CLOSING       = 1 <<  3,  /**< Set when closing to suppress errors */
  FLAGS_GOTID         = 1 <<  4,  /**< Successful ident lookup achieved */
  FLAGS_SENDQEX       = 1 <<  5,  /**< Sendq exceeded */
  FLAGS_IPHASH        = 1 <<  6,  /**< Iphashed this client */
  FLAGS_MARK          = 1 <<  7,  /**< Marked client */
  FLAGS_CANFLOOD      = 1 <<  8,  /**< Client has the ability to flood */
  FLAGS_EXEMPTKLINE   = 1 <<  9,  /**< Client is exempt from k-lines */
  FLAGS_NOLIMIT       = 1 << 10,  /**< Client is exempt from limits */
  FLAGS_PING_COOKIE   = 1 << 11,  /**< PING Cookie */
  FLAGS_FLOODDONE     = 1 << 12,  /**< Flood grace period has been ended. */
  FLAGS_EOB           = 1 << 13,  /**< Server has sent us an EOB */
  FLAGS_HIDDEN        = 1 << 14,  /**< A hidden server. Not shown in /links */
  FLAGS_BLOCKED       = 1 << 15,  /**< Must wait for COMM_SELECT_WRITE */
  FLAGS_USERHOST      = 1 << 16,  /**< Client is in userhost hash */
  FLAGS_EXEMPTRESV    = 1 << 17,  /**< Client is exempt from RESV */
  FLAGS_GOTUSER       = 1 << 18,  /**< If we received a USER command */
  FLAGS_FINISHED_AUTH = 1 << 19,  /**< Client has been released from auth */
  FLAGS_FLOOD_NOTICED = 1 << 20,  /**< Notice to opers about this flooder has been sent */
  FLAGS_SERVICE       = 1 << 21,  /**< Client/server is a network service */
  FLAGS_SSL           = 1 << 22,  /**< User is connected via TLS/SSL */
  FLAGS_SQUIT         = 1 << 23,
  FLAGS_EXEMPTXLINE   = 1 << 24   /**< Client is exempt from x-lines */
};

#define HasFlag(x, y) ((x)->flags &   (y))
#define AddFlag(x, y) ((x)->flags |=  (y))
#define DelFlag(x, y) ((x)->flags &= ~(y))


/* umodes, settable flags */
enum
{
  UMODE_SERVNOTICE   = 1 <<  0,  /**< Server notices such as kill */
  UMODE_CCONN        = 1 <<  1,  /**< Can see client connection notices */
  UMODE_REJ          = 1 <<  2,  /**< Bot Rejections */
  UMODE_SKILL        = 1 <<  3,  /**< Server Killed */
  UMODE_FULL         = 1 <<  4,  /**< Full messages */
  UMODE_SPY          = 1 <<  5,  /**< See STATS / LINKS */
  UMODE_DEBUG        = 1 <<  6,  /**< 'debugging' info */
  UMODE_NCHANGE      = 1 <<  7,  /**< Nick change notice */
  UMODE_WALLOP       = 1 <<  8,  /**< Send wallops to them */
  UMODE_INVISIBLE    = 1 <<  9,  /**< Makes user invisible */
  UMODE_BOTS         = 1 << 10,  /**< Shows bots */
  UMODE_EXTERNAL     = 1 << 11,  /**< Show servers introduced and splitting */
  UMODE_CALLERID     = 1 << 12,  /**< Block unless caller id's */
  UMODE_SOFTCALLERID = 1 << 13,  /**< Block unless on common channel */
  UMODE_UNAUTH       = 1 << 14,  /**< Show unauth connects here */
  UMODE_LOCOPS       = 1 << 15,  /**< Can see LOCOPS messages */
  UMODE_DEAF         = 1 << 16,  /**< Don't receive channel messages */
  UMODE_REGISTERED   = 1 << 17,  /**< User has identified for that nick. */
  UMODE_REGONLY      = 1 << 18,  /**< Only registered nicks may PM */
  UMODE_HIDDEN       = 1 << 19,  /**< IRC operator status is hidden */
  UMODE_OPER         = 1 << 20,  /**< IRC operator */
  UMODE_ADMIN        = 1 << 21,  /**< Admin on server */
  UMODE_FARCONNECT   = 1 << 22,  /**< Can see remote client connects/exits */
  UMODE_SSL          = 1 << 23,  /**< User is connected via TLS/SSL */
  UMODE_WEBIRC       = 1 << 24,  /**< User connected via a webirc gateway */
  UMODE_HIDEIDLE     = 1 << 25,  /**< Hides idle and signon time in WHOIS */
  UMODE_HIDECHANS    = 1 << 26   /**< Hides channel list in WHOIS */
};

#define HasUMode(x, y) ((x)->umodes &   (y))
#define AddUMode(x, y) ((x)->umodes |=  (y))
#define DelUMode(x, y) ((x)->umodes &= ~(y))


/** irc-operator privilege flags */
enum
{
  OPER_FLAG_ADMIN          = 1 <<  0,  /**< Oper can set user mode +a */
  OPER_FLAG_CLOSE          = 1 <<  1,  /**< Oper can use CLOSE command */
  OPER_FLAG_CONNECT        = 1 <<  2,  /**< Oper can do local CONNECT */
  OPER_FLAG_CONNECT_REMOTE = 1 <<  3,  /**< Oper can do remote CONNECT */
  OPER_FLAG_DIE            = 1 <<  4,  /**< Oper can use DIE command */
  OPER_FLAG_DLINE          = 1 <<  5,  /**< Oper can use DLINE command */
  OPER_FLAG_GLOBOPS        = 1 <<  6,  /**< Oper can use GLOBOPS command */
  OPER_FLAG_JOIN_RESV      = 1 <<  7,  /**< Oper can use JOIN on resv {} channels */
  OPER_FLAG_KILL           = 1 <<  8,  /**< Oper can KILL local users */
  OPER_FLAG_KILL_REMOTE    = 1 <<  9,  /**< Oper can KILL remote users */
  OPER_FLAG_KLINE          = 1 << 10,  /**< Oper can use KLINE command */
  OPER_FLAG_LOCOPS         = 1 << 11,  /**< Oper can use LOCOPS command */
  OPER_FLAG_MODULE         = 1 << 12,  /**< Oper can use MODULE command */
  OPER_FLAG_NICK_RESV      = 1 << 13,  /**< Oper can use NICK on resv {} nicks */
  OPER_FLAG_OPME           = 1 << 14,  /**< Oper can use OPME command */
  OPER_FLAG_REHASH         = 1 << 15,  /**< Oper can use REHASH command */
  OPER_FLAG_REHASH_REMOTE  = 1 << 16,  /**< Oper can do remote REHASH command */
  OPER_FLAG_REMOTEBAN      = 1 << 17,  /**< Oper can set remote bans */
  OPER_FLAG_RESTART        = 1 << 18,  /**< Oper can use RESTART command */
  OPER_FLAG_RESV           = 1 << 19,  /**< Oper can use RESV command */
  OPER_FLAG_SET            = 1 << 20,  /**< Oper can use SET command */
  OPER_FLAG_SQUIT          = 1 << 21,  /**< Oper can do local SQUIT */
  OPER_FLAG_SQUIT_REMOTE   = 1 << 22,  /**< Oper can do remote SQUIT */
  OPER_FLAG_UNDLINE        = 1 << 23,  /**< Oper can use UNDLINE command */
  OPER_FLAG_UNKLINE        = 1 << 24,  /**< Oper can use UNKLINE command */
  OPER_FLAG_UNRESV         = 1 << 25,  /**< Oper can use UNRESV command */
  OPER_FLAG_UNXLINE        = 1 << 26,  /**< Oper can use UNXLINE command */
  OPER_FLAG_WALLOPS        = 1 << 27,  /**< Oper can use WALLOPS command */
  OPER_FLAG_XLINE          = 1 << 28   /**< Oper can use XLINE command */
};

#define HasOFlag(x, y) ((x)->connection->operflags &   (y))
#define AddOFlag(x, y) ((x)->connection->operflags |=  (y))
#define DelOFlag(x, y) ((x)->connection->operflags &= ~(y))
#define ClrOFlag(x)    ((x)->connection->operflags = 0)



/* flags macros. */
#define IsDead(x)               ((x)->flags & FLAGS_DEADSOCKET)
#define SetDead(x)              ((x)->flags |= FLAGS_DEADSOCKET)
#define IsDefunct(x)            ((x)->flags & (FLAGS_DEADSOCKET|FLAGS_CLOSING|FLAGS_KILLED))

/* oper flags */
#define SetOper(x)              {(x)->umodes |= UMODE_OPER; \
                                 if (MyClient((x))) (x)->handler = OPER_HANDLER;}

#define ClearOper(x)            {(x)->umodes &= ~(UMODE_OPER|UMODE_ADMIN); \
                                 if (MyClient((x))) \
                                  (x)->handler = CLIENT_HANDLER; }

#define IsFloodDone(x)          ((x)->flags &  FLAGS_FLOODDONE)
#define IsHidden(x)             ((x)->flags &  FLAGS_HIDDEN)


/*! \brief server ban types */
enum
{
  CLIENT_BAN_KLINE,
  CLIENT_BAN_DLINE,
  CLIENT_BAN_XLINE
};

/*! \brief addr_mask_type enumeration */
enum addr_mask_type
{
  HIDE_IP,  /**< IP is hidden. Resolved hostname is shown instead */
  SHOW_IP,  /**< IP is shown. No parts of it are hidden or masked */
  MASK_IP   /**< IP is masked. 255.255.255.255 is shown instead */
};

struct ServicesTag
{
  dlink_node node;
  char *tag;
  unsigned int numeric;
  unsigned int umodes;
};

/*! \brief Server structure */
struct Server
{
  dlink_list server_list;  /**< Servers on this server */
  dlink_list client_list;  /**< Clients on this server */
  char by[NICKLEN + 1];    /**< Who activated this connection */
};

/*! \brief ListTask structure */
struct ListTask
{
  dlink_node node;  /**< Embedded list node used to link into listing_client_list */
  dlink_list show_mask;  /**< Channels to show */
  dlink_list hide_mask;  /**< Channels to hide */

  unsigned int hash_index;  /**< The hash bucket we are currently in */
  unsigned int users_min;
  unsigned int users_max;
  unsigned int created_min;
  unsigned int created_max;
  unsigned int topicts_min;
  unsigned int topicts_max;
  char topic[TOPICLEN + 1];
};

/*! \brief Connection structure
 *
 * Allocated only for local clients, that are directly connected
 * to \b this server with a socket.
 */
struct Connection
{
  dlink_node   lclient_node;

  unsigned int registration;
  unsigned int cap_client;  /**< Client capabilities (from us) */
  unsigned int cap_active;  /**< Active capabilities (to us) */
  unsigned int       caps;  /**< Capabilities bit-field */

  unsigned int operflags;     /**< IRC Operator privilege flags */
  unsigned int random_ping; /**< Holding a 32bit value used for PING cookies */

  uintmax_t serial;     /**< Used to enforce 1 send per nick */

  uintmax_t    lasttime;   /**< Last time data read from socket */
  uintmax_t    firsttime;  /**< Time client was created */
  uintmax_t    since;      /**< Last time we parsed something */
  uintmax_t    last_join_time;   /**< When this client last joined a channel */
  uintmax_t    last_leave_time;  /**< When this client last left a channel */
  int          join_leave_count; /**< Count of JOIN/LEAVE in less than
                                         MIN_JOIN_LEAVE_TIME seconds */
  int          oper_warn_count_down; /**< Warn opers of this possible
                                          spambot every time this gets to 0 */
  uintmax_t    last_caller_id_time;
  uintmax_t    first_received_message_time;
  uintmax_t    last_privmsg;  /**< Last time we got a PRIVMSG */

  unsigned int received_number_of_privmsgs;

  struct ListTask  *list_task;

  struct dbuf_queue buf_sendq;
  struct dbuf_queue buf_recvq;

  struct
  {
    unsigned int messages;      /**< Statistics: protocol messages sent/received */
    uintmax_t bytes;             /**< Statistics: total bytes sent/received */
  } recv, send;

  struct
  {
    unsigned int count;  /**< How many AWAY/INVITE/KNOCK/NICK requests client has sent */
    uintmax_t last_attempt;  /**< Last time the AWAY/INVITE/KNOCK/NICK request was issued */
  } away, invite, knock, nick;

  struct AuthRequest *auth;
  struct Listener *listener;   /**< Listener accepted from */
  dlink_list        acceptlist; /**< Clients I'll allow to talk to me */
  dlink_list        watches;   /**< Chain of Watch pointer blocks */
  dlink_list        confs;     /**< Configuration record associated */
  dlink_list        invited;   /**< Chain of invite pointer blocks */
  struct irc_ssaddr ip;
  int               aftype;    /**< Makes life easier for DNS res in IPV6 */

  fde_t            *fd;

  /* Anti-flood stuff. We track how many messages were parsed and how
   * many we were allowed in the current second, and apply a simple
   * decay to avoid flooding.
   *   -- adrian
   */
  int allow_read;       /**< How many we're allowed to read in this second */
  int sent_parsed;      /**< How many messages we've parsed in this second */

  char *password;  /**< Password supplied by the client/server */
};

/*! \brief Client structure */
struct Client
{
  dlink_node node;
  dlink_node lnode;             /**< Used for Server->servers/users */

  struct Connection *connection;  /**< Connection structure associated with this client */
  struct Client    *hnext;      /**< For client hash table lookups by name */
  struct Client    *idhnext;    /**< For SID hash table lookups by sid */
  struct Server    *serv;       /**< ...defined, if this is a server */
  struct Client    *servptr;    /**< Points to server this Client is on */
  struct Client    *from;       /**< == self, if Local Client, *NEVER* NULL! */

  uintmax_t         tsinfo;     /**< TS on the nick, SVINFO on server */

  unsigned int      flags;      /**< Client flags */
  unsigned int      umodes;     /**< User modes this client has set */
  unsigned int      hopcount;   /**< Number of servers to this 0 = local */
  unsigned int      status;     /**< Client type */
  unsigned int      handler;    /**< Handler index */

  dlink_list        whowas_list;
  dlink_list        channel;   /**< Chain of channel pointer blocks */
  dlink_list        svstags;   /**< List of ServicesTag items */

  char away[AWAYLEN + 1]; /**< Client's AWAY message. Can be set/unset via AWAY command */
  char name[HOSTLEN + 1]; /**< Unique name for a client nick or host */
  char id[IDLEN + 1];       /**< Client ID, unique ID per client */
  char account[ACCOUNTLEN + 1]; /**< Services account */

  /*
   * client->username is the username from ident or the USER message,
   * If the client is idented the USER message is ignored, otherwise
   * the username part of the USER message is put here prefixed with a
   * tilde depending on the auth{} block. Once a client has registered,
   * this field should be considered read-only.
   */
  char              username[USERLEN + 1]; /* client's username */

  /*
   * client->host contains the resolved name or ip address as a string
   * for the user, it may be fiddled with for oper spoofing etc.
   * once it's changed the *real* address goes away.
   */
  char              host[HOSTLEN + 1];     /* client's hostname */

  /*
   * client->realhost contains the resolved name or ip address as a string
   * for the user. Once a client has registered, this field should be
   * considered read-only.
   */
  char              realhost[HOSTLEN + 1];     /* client's real hostname */


  /*
   * client->info for unix clients will normally contain the info from the
   * gcos field in /etc/passwd but anything can go here.
   */
  char              info[REALLEN + 1]; /* Free form additional client info */

  /*
   * client->sockhost contains the ip address gotten from the socket as a
   * string, this field should be considered read-only once the connection
   * has been made. (set in s_bsd.c only)
   */
  char              sockhost[HOSTIPLEN + 1]; /* This is the host name from the
                                                socket ip address as string */
  char             *certfp;  /**< SSL certificate fingerprint */
};


extern struct Client me;
extern dlink_list listing_client_list;
extern dlink_list global_client_list;
extern dlink_list global_server_list;   /* global servers on the network              */
extern dlink_list local_client_list;  /* local clients only ON this server          */
extern dlink_list local_server_list;  /* local servers to this server ONLY          */
extern dlink_list unknown_list;       /* unknown clients ON this server only        */
extern dlink_list oper_list;          /* our opers, duplicated in local_client_list */

extern int accept_message(struct Client *, struct Client *);
extern unsigned int client_get_idle_time(const struct Client *, const struct Client *);
extern struct split_nuh_item *find_accept(const char *, const char *,
                                          const char *, struct Client *,
                                          int (*)(const char *, const char *));
extern void client_detach_svstag(dlink_list *, unsigned int);
extern void client_attach_svstag(dlink_list *, unsigned int, const char *, const char *);
extern void client_clear_svstags(dlink_list *);
extern void del_accept(struct split_nuh_item *, struct Client *);
extern void del_all_accepts(struct Client *);
extern void exit_client(struct Client *, const char *);
extern void conf_try_ban(struct Client *, int, const char *);
extern void check_conf_klines(void);
extern void client_init(void);
extern void dead_link_on_write(struct Client *, int);
extern void dead_link_on_read(struct Client *, int);
extern void exit_aborted_clients(void);
extern void free_exited_clients(void);
extern struct Client *client_make(struct Client *);
extern struct Client *find_chasing(struct Client *, const char *);
extern struct Client *find_person(const struct Client *, const char *);
extern const char *client_get_name(const struct Client *, enum addr_mask_type);
#endif  /* INCLUDED_client_h */
