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

/*! \file client.h
 * \brief Header including structures, macros and prototypes for client handling
 * \version $Id$
 */


#ifndef INCLUDED_client_h
#define INCLUDED_client_h

#include "list.h"
#include "fdlist.h"
#include "config.h"
#include "ircd_defs.h"
#include "dbuf.h"
#include "channel.h"
#include "auth.h"

struct MaskItem;

/*
 * status macros.
 */
enum
{
  STAT_CONNECTING = 0x00000001U,
  STAT_HANDSHAKE  = 0x00000002U,
  STAT_ME         = 0x00000004U,
  STAT_UNKNOWN    = 0x00000008U,
  STAT_SERVER     = 0x00000010U,
  STAT_CLIENT     = 0x00000020U
};

enum
{
  REG_NEED_USER = 0x00000001U,  /**< User must send USER command */
  REG_NEED_NICK = 0x00000002U,  /**< User must send NICK command */
  REG_NEED_CAP  = 0x00000004U,  /**< In middle of CAP negotiations */
  REG_INIT      = REG_NEED_USER | REG_NEED_NICK
};

#define ID_or_name(x,client_p)  ((IsServer(client_p->from) && (x)->id[0]) ? (x)->id : (x)->name)

#define IsRegistered(x)         ((x)->status  > STAT_UNKNOWN)
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
                                 (x)->handler = HasUMode(x, UMODE_OPER) ? \
                                 OPER_HANDLER : CLIENT_HANDLER; }

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
  CAP_MULTI_PREFIX  = 0x00000001U,
  CAP_AWAY_NOTIFY   = 0x00000002U,
  CAP_UHNAMES       = 0x00000004U,
  CAP_EXTENDED_JOIN = 0x00000008U
};

#define HasCap(x, y) ((x)->connection->cap_active & (y))


/* housekeeping flags */
enum
{
  FLAGS_PINGSENT      = 0x00000001U,  /**< Unreplied ping sent */
  FLAGS_DEADSOCKET    = 0x00000002U,  /**< Local socket is dead--Exiting soon */
  FLAGS_KILLED        = 0x00000004U,  /**< Prevents "QUIT" from being sent for this */
  FLAGS_CLOSING       = 0x00000008U,  /**< Set when closing to suppress errors */
  FLAGS_GOTID         = 0x00000010U,  /**< Successful ident lookup achieved */
  FLAGS_SENDQEX       = 0x00000020U,  /**< Sendq exceeded */
  FLAGS_IPHASH        = 0x00000040U,  /**< Iphashed this client */
  FLAGS_MARK          = 0x00000080U,  /**< Marked client */
  FLAGS_CANFLOOD      = 0x00000100U,  /**< Client has the ability to flood */
  FLAGS_EXEMPTKLINE   = 0x00000200U,  /**< Client is exempt from k-lines */
  FLAGS_NOLIMIT       = 0x00000400U,  /**< Client is exempt from limits */
  FLAGS_PING_COOKIE   = 0x00000800U,  /**< PING Cookie */
  FLAGS_FLOODDONE     = 0x00001000U,  /**< Flood grace period has been ended. */
  FLAGS_EOB           = 0x00002000U,  /**< Server has sent us an EOB */
  FLAGS_HIDDEN        = 0x00004000U,  /**< A hidden server. Not shown in /links */
  FLAGS_BLOCKED       = 0x00008000U,  /**< Must wait for COMM_SELECT_WRITE */
  FLAGS_USERHOST      = 0x00010000U,  /**< Client is in userhost hash */
  FLAGS_BURSTED       = 0x00020000U,  /**< User was already bursted */
  FLAGS_EXEMPTRESV    = 0x00040000U,  /**< Client is exempt from RESV */
  FLAGS_GOTUSER       = 0x00080000U,  /**< If we received a USER command */
  FLAGS_FINISHED_AUTH = 0x00100000U,  /**< Client has been released from auth */
  FLAGS_FLOOD_NOTICED = 0x00200000U,  /**< Notice to opers about this flooder has been sent */
  FLAGS_SERVICE       = 0x00400000U,  /**< Client/server is a network service */
  FLAGS_SSL           = 0x00800000U,  /**< User is connected via TLS/SSL */
  FLAGS_SQUIT         = 0x01000000U,
  FLAGS_EXEMPTXLINE   = 0x02000000U   /**< Client is exempt from x-lines */
};

#define HasFlag(x, y) ((x)->flags &   (y))
#define AddFlag(x, y) ((x)->flags |=  (y))
#define DelFlag(x, y) ((x)->flags &= ~(y))


/* umodes, settable flags */
enum
{
  UMODE_SERVNOTICE   = 0x00000001U,  /**< Server notices such as kill */
  UMODE_CCONN        = 0x00000002U,  /**< Can see client connection notices */
  UMODE_REJ          = 0x00000004U,  /**< Bot Rejections */
  UMODE_SKILL        = 0x00000008U,  /**< Server Killed */
  UMODE_FULL         = 0x00000010U,  /**< Full messages */
  UMODE_SPY          = 0x00000020U,  /**< See STATS / LINKS */
  UMODE_DEBUG        = 0x00000040U,  /**< 'debugging' info */
  UMODE_NCHANGE      = 0x00000080U,  /**< Nick change notice */
  UMODE_WALLOP       = 0x00000100U,  /**< Send wallops to them */
  UMODE_INVISIBLE    = 0x00000200U,  /**< Makes user invisible */
  UMODE_BOTS         = 0x00000400U,  /**< Shows bots */
  UMODE_EXTERNAL     = 0x00000800U,  /**< Show servers introduced and splitting */
  UMODE_CALLERID     = 0x00001000U,  /**< Block unless caller id's */
  UMODE_SOFTCALLERID = 0x00002000U,  /**< Block unless on common channel */
  UMODE_UNAUTH       = 0x00004000U,  /**< Show unauth connects here */
  UMODE_LOCOPS       = 0x00008000U,  /**< Can see LOCOPS messages */
  UMODE_DEAF         = 0x00010000U,  /**< Don't receive channel messages */
  UMODE_REGISTERED   = 0x00020000U,  /**< User has identified for that nick. */
  UMODE_REGONLY      = 0x00040000U,  /**< Only registered nicks may PM */
  UMODE_HIDDEN       = 0x00080000U,  /**< IRC operator status is hidden */
  UMODE_OPER         = 0x00100000U,  /**< IRC operator */
  UMODE_ADMIN        = 0x00200000U,  /**< Admin on server */
  UMODE_FARCONNECT   = 0x00400000U,  /**< Can see remote client connects/exits */
  UMODE_HIDDENHOST   = 0x00800000U,  /**< User's host is hidden */
  UMODE_SSL          = 0x01000000U,  /**< User is connected via TLS/SSL */
  UMODE_WEBIRC       = 0x02000000U,  /**< User connected via a webirc gateway */
  UMODE_HIDEIDLE     = 0x04000000U,  /**< Hides idle and signon time in WHOIS */
  UMODE_HIDECHANS    = 0x08000000U   /**< Hides channel list in WHOIS */
};

#define HasUMode(x, y) ((x)->umodes &   (y))
#define AddUMode(x, y) ((x)->umodes |=  (y))
#define DelUMode(x, y) ((x)->umodes &= ~(y))


/* oper priv flags */
enum
{
 OPER_FLAG_KILL_REMOTE    = 0x00000001U,  /**< Oper can KILL remote users */
 OPER_FLAG_KILL           = 0x00000002U,  /**< Oper can KILL local users */
 OPER_FLAG_UNKLINE        = 0x00000004U,  /**< Oper can use UNKLINE command */
 OPER_FLAG_KLINE          = 0x00000008U,  /**< Oper can use KLINE command */
 OPER_FLAG_XLINE          = 0x00000010U,  /**< Oper can use XLINE command */
 OPER_FLAG_DIE            = 0x00000020U,  /**< Oper can use DIE command */
 OPER_FLAG_REHASH         = 0x00000040U,  /**< Oper can use REHASH command */
 OPER_FLAG_ADMIN          = 0x00000080U,  /**< Oper can set user mode +a */
 OPER_FLAG_REMOTEBAN      = 0x00000100U,  /**< Oper can set remote bans */
 OPER_FLAG_GLOBOPS        = 0x00000200U,  /**< Oper can use GLOBOPS command */
 OPER_FLAG_MODULE         = 0x00000400U,  /**< Oper can use MODULE command */
 OPER_FLAG_RESTART        = 0x00000800U,  /**< Oper can use RESTART command */
 OPER_FLAG_DLINE          = 0x00001000U,  /**< Oper can use DLINE command */
 OPER_FLAG_UNDLINE        = 0x00002000U,  /**< Oper can use UNDLINE command */
 OPER_FLAG_SET            = 0x00004000U,  /**< Oper can use SET command */
 OPER_FLAG_SQUIT          = 0x00008000U,  /**< Oper can do local SQUIT */
 OPER_FLAG_SQUIT_REMOTE   = 0x00010000U,  /**< Oper can do remote SQUIT */
 OPER_FLAG_CONNECT        = 0x00020000U,  /**< Oper can do local CONNECT */
 OPER_FLAG_CONNECT_REMOTE = 0x00040000U,  /**< Oper can do remote CONNECT */
 OPER_FLAG_WALLOPS        = 0x00080000U,  /**< Oper can use WALLOPS command */
 OPER_FLAG_LOCOPS         = 0x00100000U,  /**< Oper can use LOCOPS command */
 OPER_FLAG_UNXLINE        = 0x00200000U,  /**< Oper can use UNXLINE command */
 OPER_FLAG_OPME           = 0x00400000U   /**< Oper can use OPME command */
};

#define HasOFlag(x, y) (MyConnect(x) ? (x)->connection->operflags & (y) : 0)
#define AddOFlag(x, y) ((x)->connection->operflags |=  (y))
#define DelOFlag(x, y) ((x)->connection->operflags &= ~(y))
#define ClrOFlag(x)    ((x)->connection->operflags = 0)



/* flags macros. */
#define IsAuthFinished(x)       ((x)->flags & FLAGS_FINISHED_AUTH)
#define IsDead(x)               ((x)->flags & FLAGS_DEADSOCKET)
#define SetDead(x)              ((x)->flags |= FLAGS_DEADSOCKET)
#define IsClosing(x)            ((x)->flags & FLAGS_CLOSING)
#define SetClosing(x)           ((x)->flags |= FLAGS_CLOSING)
#define IsDefunct(x)            ((x)->flags & (FLAGS_DEADSOCKET|FLAGS_CLOSING|FLAGS_KILLED))

/* oper flags */
#define MyOper(x)               (MyConnect(x) && HasUMode(x, UMODE_OPER))

#define SetOper(x)              {(x)->umodes |= UMODE_OPER; \
                                 if (!IsServer((x))) (x)->handler = OPER_HANDLER;}

#define ClearOper(x)            {(x)->umodes &= ~(UMODE_OPER|UMODE_ADMIN); \
                                 if (!HasUMode(x, UMODE_OPER) && !IsServer((x))) \
                                  (x)->handler = CLIENT_HANDLER; }

#define IsFloodDone(x)          ((x)->flags &  FLAGS_FLOODDONE)
#define IsHidden(x)             ((x)->flags &  FLAGS_HIDDEN)


/*! \brief addr_mask_type enumeration */
enum addr_mask_type
{
  HIDE_IP, /**< IP is hidden. Resolved hostname is shown instead */
  SHOW_IP, /**< IP is shown. No parts of it are hidden or masked */
  MASK_IP  /**< IP is masked. 255.255.255.255 is shown instead */
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
  dlink_list server_list; /**< Servers on this server */
  dlink_list client_list; /**< Clients on this server */
  char by[NICKLEN + 1];   /**< Who activated this connection */
};

/*! \brief ListTask structure */
struct ListTask
{
  dlink_list show_mask; /**< Channels to show */
  dlink_list hide_mask; /**< Channels to hide */

  unsigned int hash_index; /**< The hash bucket we are currently in */
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

  uint64_t serial;     /**< Used to enforce 1 send per nick */

  time_t       lasttime;   /**< ...should be only LOCAL clients? --msa */
  time_t       firsttime;  /**< Time client was created */
  time_t       since;      /**< Last time we parsed something */
  time_t       last_join_time;   /**< When this client last joined a channel */
  time_t       last_leave_time;  /**< When this client last left a channel */
  int          join_leave_count; /**< Count of JOIN/LEAVE in less than
                                         MIN_JOIN_LEAVE_TIME seconds */
  int          oper_warn_count_down; /**< Warn opers of this possible
                                          spambot every time this gets to 0 */
  time_t       last_caller_id_time;
  time_t       first_received_message_time;
  time_t       last_privmsg;  /**< Last time we got a PRIVMSG */

  int          received_number_of_privmsgs;

  struct ListTask  *list_task;

  struct dbuf_queue buf_sendq;
  struct dbuf_queue buf_recvq;

  struct
  {
    unsigned int messages;      /**< Statistics: protocol messages sent/received */
    uint64_t bytes;             /**< Statistics: total bytes sent/received */
  } recv, send;

  struct
  {
    unsigned int count;  /**< How many AWAY/INVITE/KNOCK/NICK requests client has sent */
    time_t last_attempt;  /**< Last time the AWAY/INVITE/KNOCK/NICK request was issued */
  } away, invite, knock, nick;

  struct AuthRequest auth;
  struct Listener *listener;   /**< Listener accepted from */
  dlink_list        acceptlist; /**< Clients I'll allow to talk to me */
  dlink_list        watches;   /**< Chain of Watch pointer blocks */
  dlink_list        confs;     /**< Configuration record associated */
  dlink_list        invited;   /**< Chain of invite pointer blocks */
  struct irc_ssaddr ip;
  int               aftype;    /**< Makes life easier for DNS res in IPV6 */
  int               country_id; /**< ID corresponding to a ISO 3166 country code */

  fde_t             fd;

  /* Anti-flood stuff. We track how many messages were parsed and how
   * many we were allowed in the current second, and apply a simple
   * decay to avoid flooding.
   *   -- adrian
   */
  int allow_read;       /**< How many we're allowed to read in this second */
  int sent_parsed;      /**< How many messages we've parsed in this second */

  char *password;  /**< Password supplied by the client/server */
  char *challenge_response;  /**< Expected CHALLENGE response from client */
  char *challenge_operator;  /**< Operator to become if they supply the response */
};

/*! \brief Client structure */
struct Client
{
  dlink_node node;
  dlink_node lnode;             /**< Used for Server->servers/users */

  struct Connection *connection;
  struct Client    *hnext;      /**< For client hash table lookups by name */
  struct Client    *idhnext;    /**< For SID hash table lookups by sid */
  struct Server    *serv;       /**< ...defined, if this is a server */
  struct Client    *servptr;    /**< Points to server this Client is on */
  struct Client    *from;       /**< == self, if Local Client, *NEVER* NULL! */

  time_t            tsinfo;     /**< TS on the nick, SVINFO on server */

  unsigned int      flags;      /**< Client flags */
  unsigned int      umodes;     /**< Opers, normal users subset */
  unsigned int      hopcount;   /**< Number of servers to this 0 = local */
  unsigned int      status;     /**< Client type */
  unsigned int      handler;    /**< Handler index */

  dlink_list        whowas;
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
   * client->host contains the resolved name or ip address
   * as a string for the user, it may be fiddled with for oper spoofing etc.
   * once it's changed the *real* address goes away. This should be
   * considered a read-only field after the client has registered.
   */
  char              host[HOSTLEN + 1];     /* client's hostname */

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
  char             *certfp;
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
extern void client_attach_svstag(struct Client *, unsigned int, const char *, const char *const);
extern void client_clear_svstags(struct Client *);
extern void del_accept(struct split_nuh_item *, struct Client *);
extern void del_all_accepts(struct Client *);
extern void exit_client(struct Client *, const char *);
extern void conf_try_ban(struct Client *, struct MaskItem *);
extern void check_conf_klines(void);
extern void client_init(void);
extern void dead_link_on_write(struct Client *, int);
extern void dead_link_on_read(struct Client *, int);
extern void exit_aborted_clients(void);
extern void free_exited_clients(void);
extern struct Client *make_client(struct Client *);
extern struct Client *find_chasing(struct Client *, const char *);
extern struct Client *find_person(const struct Client *const, const char *);
extern const char *get_client_name(const struct Client *, enum addr_mask_type);

#endif /* INCLUDED_client_h */
