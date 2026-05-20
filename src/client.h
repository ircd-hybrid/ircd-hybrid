/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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
 */

#ifndef INCLUDED_client_h
#define INCLUDED_client_h
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "address.h"
#include "dbuf.h"
#include "event.h"
#include "fdlist.h"
#include "io.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"

#include "command.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_connect.h"
#include "conf_oper.h"
#include "ircd_defs.h"
#include "list_task.h"
#include "lookup.h"
#include "user_mode.h"

/** Server ban types */
enum
{
  CLIENT_BAN_KLINE,
  CLIENT_BAN_DLINE,
  CLIENT_BAN_XLINE
};

/** addr_mask_type enumeration */
enum addr_mask_type
{
  HIDE_IP,  /**< IP is hidden. Resolved hostname is shown instead */
  SHOW_IP,  /**< IP is shown. No parts of it are hidden or masked */
  MASK_IP   /**< IP is masked. 255.255.255.255 is shown instead */
};

/** Client connection states */
enum client_state
{
  CLIENT_STATE_UNKNOWN = 1,
  CLIENT_STATE_CONNECTING,  /**< Connecting to another server */
  CLIENT_STATE_HANDSHAKE,  /**< PASS, CAPAB, and SERVER sent */
  CLIENT_STATE_SERVER,  /**< Fully registered server */
  CLIENT_STATE_CLIENT,  /**< Fully registered client */
  CLIENT_STATE_ME,  /**< This is &me */
};

/* XXX */
#define IsServer(x)             ((x)->state == CLIENT_STATE_SERVER)
#define IsClient(x)             ((x)->state == CLIENT_STATE_CLIENT)
#define MyClient(x)             (client_is_local(x) && IsClient(x))
/* XXX */

enum client_class_type
{
  CLIENT_CLASS_BASE,
  CLIENT_CLASS_OPER,
};

enum client_io_operation
{
  CLIENT_IO_OPERATION_READ,
  CLIENT_IO_OPERATION_WRITE,
};

enum client_io_failure
{
  CLIENT_IO_FAILURE_PEER_CLOSED,
  CLIENT_IO_FAILURE_ERROR,
};

enum
{
  REG_NEED_USER = 1 << 0,  /**< User must send USER command */
  REG_NEED_NICK = 1 << 1,  /**< User must send NICK command */
  REG_NEED_CAP  = 1 << 2,  /**< In middle of CAP negotiations */
  REG_INIT      = REG_NEED_USER | REG_NEED_NICK
};

/** Client flags */
enum
{
  FLAGS_DEADSOCKET      = 1 <<  0,  /**< Local socket is dead--Exiting soon */
  FLAGS_KILLED          = 1 <<  1,  /**< Prevents "QUIT" from being sent for this */
  FLAGS_CLOSING         = 1 <<  2,  /**< Set when closing to suppress errors */
  FLAGS_GOTID           = 1 <<  3,  /**< Successful ident lookup achieved */
  FLAGS_SENDQEX         = 1 <<  4,  /**< Sendq exceeded */
  FLAGS_IPHASH          = 1 <<  5,  /**< Iphashed this client */
  FLAGS_MARK            = 1 <<  6,  /**< Marked client */
  FLAGS_CANFLOOD        = 1 <<  7,  /**< Client has the ability to flood */
  FLAGS_EXEMPTKLINE     = 1 <<  8,  /**< Client is exempt from k-lines */
  FLAGS_NOLIMIT         = 1 <<  9,  /**< Client is exempt from limits */
  FLAGS_PING_COOKIE     = 1 << 10,  /**< PING Cookie */
  FLAGS_FLOODDONE       = 1 << 11,  /**< Flood grace period has been ended. */
  FLAGS_EOB             = 1 << 12,  /**< Server has sent us an EOB */
  FLAGS_HIDDEN          = 1 << 13,  /**< A hidden server. Not shown in /links */
  FLAGS_BLOCKED         = 1 << 14,  /**< Must wait for COMM_SELECT_WRITE */
  FLAGS_EXEMPTRESV      = 1 << 15,  /**< Client is exempt from RESV */
  FLAGS_GOTUSER         = 1 << 16,  /**< If we received a USER command */
  FLAGS_FLOOD_NOTICED   = 1 << 17,  /**< Notice to opers about this flooder has been sent */
  FLAGS_SERVICE         = 1 << 18,  /**< Client/server is a network service */
  FLAGS_TLS_HANDSHAKING = 1 << 19,  /**< The connection is actively negotiating a TLS handshake. */
  FLAGS_TLS_ACTIVE      = 1 << 20,  /**< The connection is secured with an active TLS session. */
  FLAGS_SQUIT           = 1 << 21,
  FLAGS_EXEMPTXLINE     = 1 << 22,  /**< Client is exempt from x-lines */
  FLAGS_CAP302          = 1 << 23,  /**< Client supports the IRCv3 CAP 302 extension */
  FLAGS_SPOOF           = 1 << 24,
  FLAGS_INTRODUCED      = 1 << 25,
};

/** Server structure */
struct Server
{
  list_t child_server_list;  /**< List of servers that are directly connected to this server. */
  list_t child_client_list;  /**< List of clients that are directly connected to this server. */
  char *initiator_name;  /**< The name of the oper who initiated an outbound link, or "AutoConn." */
  struct ConnectItem *conf;  /**< Pointer to the `connect {}` block that defines this server link. */
};

/** Connection structure
 * Allocated only for local clients, that are directly connected
 * to this server with a socket.
 */
struct Connection
{
  list_node_t node;
  uint32_t registration;
  uint32_t cap;  /**< Bitmask of client-announced CAP features. */
  uint32_t capab;  /**< Bitmask of server-announced CAPAB features. */
  uint32_t operflags;  /**< Bitmask of IRC Operator privilege flags. */
  uint32_t ping_cookie_token;  /**< The challenge token for "ping cookie" authentication, 0 if none pending. */
  uint32_t join_leave_count;  /**< Count of JOIN/LEAVE in less than MIN_JOIN_LEAVE_TIME seconds */
  uint32_t oper_warn_count_down;  /**< Warn opers of this possible spambot every time this gets to 0 */
  uint32_t received_number_of_privmsgs;
  uintmax_t last_broadcast_id;  /**< ID of the last broadcast this nexthop was part of; for send de-duplication. */
  uintmax_t last_receive_time;  /**< Monotonic time of the last successful data read from the socket. */
  uintmax_t ping_sent_time;  /**< Monotonic time the last PING was sent, or 0 if none is pending. */
  uintmax_t created_real;  /**< Time client was created; real time */
  uintmax_t created_monotonic;  /**< Time client was created; monotonic time */
  uintmax_t last_caller_id_time;  /**< Monotonic time */
  uintmax_t first_received_message_time;  /**< Monotonic time */
  uintmax_t last_privmsg_time;  /**< Last time we got a PRIVMSG; monotonic time */
  uintmax_t last_join_time;  /**< When this client last joined a channel; monotonic time */
  uintmax_t last_leave_time;  /**< When this client last left a channel; monotonic time */
  struct ListTask  *list_task;  /**< State for an in-progress /LIST command. */
  struct dbuf_queue buf_sendq;  /**< The queue of data waiting to be written to the socket. */
  struct dbuf_queue buf_recvq;  /**< The queue of data received from the socket, awaiting parsing. */

  struct
  {
    uint32_t messages;  /**< Statistics: protocol messages sent/received */
    uintmax_t bytes;  /**< Statistics: total bytes sent/received */
  } recv, send;

  struct
  {
    unsigned int count;  /**< How many AWAY/INVITE/KNOCK/NICK requests client has sent */
    uintmax_t last_attempt;  /**< Last time the AWAY/INVITE/KNOCK/NICK request was issued; monotonic time */
  } away, invite, knock, nick;

  struct ClassItem *base_class;  /**< The class assigned on initial connection. */
  struct ClassItem *oper_class;  /**< The class assigned on OPER. NULL if not an oper. */
  struct LookupRequest *lookup_request;  /**< State for the initial async DNS/ident lookup. */
  struct Listener *listener;  /**< The listener this connection was accepted from. */
  list_t accept_list;  /**< Clients I'll allow to talk to me */
  list_t monitor_list;  /**< Chain of Monitor pointer blocks */
  list_t invite_list;  /**< Chain of invite pointer blocks */

  fde_t *fd;  /**< Pointer to the file descriptor entry for the underlying socket. */

  int input_parse_debt;  /**< Decaying parse debt that limits queued input processing. */

  char *password;  /**< Password supplied by the client/server during handshake. */
  char *oper_name;  /**< The name of the oper block, if opered up. */
  char *scheduled_exit_reason;  /**< Exit reason retained while the client is queued for deferred exit. */
  event_handle_t activity_timeout_event;  /**< Event handle for the client's activity (idle/ping) timeout. */
  event_handle_t flood_recalc_event;  /**< Repeating event handle for the client's anti-flood timer. */
};

/** Client structure */
struct Client
{
  list_node_t global_node;  /**< Node for membership in global_client_list or global_server_list. */
  list_node_t uplink_node;  /**< Node for membership in an uplink's child_*_list. */

  struct Connection *connection;  /**< Connection structure associated with this client */
  struct Client *hnext;  /**< Next entry in the nickname/servername hash table bucket. */
  struct Client *idhnext;  /**< Next entry in the UID/SID hash table bucket. */
  struct Server *serv;  /**< If non-NULL, points to server-specific data. */
  struct Client *uplink;  /**< The server this entity is directly connected to. For local clients, this is &me. */
  struct Client *nexthop;   /**< The directly-connected server through which traffic for this entity flows. */

  uintmax_t tsinfo;  /**< Timestamp on this nick; real time */
  uint32_t hopcount;  /**< The number of server hops from here to the entity. */
  uint32_t flags;  /**< Client flags */
  uint64_t umodes;  /**< User modes this client has set */

  enum client_state state;  /**< The client's current state (e.g., CLIENT_STATE_CLIENT, CLIENT_STATE_SERVER). */
  unsigned int handler;  /**< The dispatch index for the command handler table based on client state. */

  list_t whowas_list;  /**< Historical records for this client's previous nicks. */
  list_t channel_list;  /**< List of channels this client is a member of. */
  list_t svstag_list;  /**< List of ServicesTag items */

  struct io_addr addr;  /**< The binary IP address of the remote end of the connection. */

  char *tls_certfp;  /**< The fingerprint of the client's TLS certificate, if provided. */
  char *tls_cipher;  /**< The negotiated TLS cipher suite for the connection. */
  char *away_message;  /**< The AWAY message set by this client, or NULL if not away. */

  char name[HOSTLEN + 1];  /**< The entity's nickname (for clients) or server name. */
  char id[IDLEN + 1];  /**< The entity's unique ID (UID for clients, SID for servers). */
  char account[ACCOUNTLEN + 1];  /**< The services account name this client is logged into; "*" if none. */

  /** client->username is the username from ident or the USER message,
   * If the client is idented the USER message is ignored, otherwise
   * the username part of the USER message is put here prefixed with a
   * tilde depending on the auth{} block. Once a client has registered,
   * this field should be considered read-only.
   */
  char username[USERLEN + 1];  /**< client's username */

  char host[HOSTLEN + 1];  /**< The publicly visible hostname, which may be cloaked or spoofed. */

  /** client->realhost contains the resolved name or ip address as a string
   * for the user. Once a client has registered, this field should be
   * considered read-only.
   */
  char realhost[HOSTLEN + 1];  /**< The forward-confirmed reverse DNS hostname of the connection. */


  /** client->info for unix clients will normally contain the info from the
   * gcos field in /etc/passwd but anything can go here.
   */
  char info[REALLEN + 1];  /**< Free form additional client info */

  /** client->sockhost contains the ip address gotten from the socket as a
   * string, this field should be considered read-only once the connection
   * has been made. (set in s_bsd.c only)
   */
  char sockhost[HOSTIPLEN + 1];  /**< This is the host name from the socket ip address as string */
};

extern struct Client me;
extern list_t global_client_list;
extern list_t global_server_list;  /* global servers on the network */
extern list_t local_client_list;  /* local clients only ON this server */
extern list_t local_server_list;  /* local servers to this server ONLY */
extern list_t unknown_list;  /* unknown clients ON this server only */
extern list_t oper_list;  /* our opers, duplicated in local_client_list */

extern uint64_t UMODE_BOT;
extern uint64_t UMODE_DEAF;
extern uint64_t UMODE_FARCONNECT;
extern uint64_t UMODE_SOFTCALLERID;
extern uint64_t UMODE_HIDDEN;
extern uint64_t UMODE_EXPIRATION;
extern uint64_t UMODE_REGONLY;
extern uint64_t UMODE_SECURE;
extern uint64_t UMODE_WEBIRC;
extern uint64_t UMODE_SECUREONLY;
extern uint64_t UMODE_ADMIN;
extern uint64_t UMODE_CCONN;
extern uint64_t UMODE_EXTERNAL;
extern uint64_t UMODE_FLOOD;
extern uint64_t UMODE_CALLERID;
extern uint64_t UMODE_INVISIBLE;
extern uint64_t UMODE_REJ;
extern uint64_t UMODE_SKILL;
extern uint64_t UMODE_LOCOPS;
extern uint64_t UMODE_NCHANGE;
extern uint64_t UMODE_OPER;
extern uint64_t UMODE_HIDECHANS;
extern uint64_t UMODE_HIDEIDLE;
extern uint64_t UMODE_REGISTERED;
extern uint64_t UMODE_SERVNOTICE;
extern uint64_t UMODE_CLOAK;
extern uint64_t UMODE_SPY;

extern void check_conf_klines(void);
extern void client_exit(struct Client *, const char *);
extern void client_exit_fmt(struct Client *, const char *, ...) IO_AFP(2,3);
extern void client_init(void);
extern void client_process_accepted_connection(fde_t *, struct Listener *, const struct io_addr *, const char *);
extern void client_reset_activity_timeout(struct Client *);
extern void client_schedule_exit(struct Client *, const char *);
extern void client_schedule_exit_fmt(struct Client *, const char *, ...) IO_AFP(2,3);
extern void client_schedule_exit_on_io_failure(struct Client *, enum client_io_operation, enum client_io_failure, int);
extern void client_set_class(struct Client *, struct ClassItem *, enum client_class_type);
extern void client_set_state(struct Client *, enum client_state);
extern void client_update_name(struct Client *, const char *);
extern void conf_try_ban(struct Client *, int, const char *);
extern void exit_aborted_clients(void);
extern void free_exited_clients(void);
extern unsigned int client_get_idle_time(const struct Client *, const struct Client *);
extern struct Client *client_create_local(void);
extern struct Client *client_create_remote(struct Client *);
extern const char *client_get_name(const struct Client *, enum addr_mask_type);
extern const char *client_get_oper_name(const struct Client *);
extern const char *client_get_visible_server_name(const struct Client *);

static inline bool
client_is_local(const struct Client *client)
{
  return client->connection != NULL;
}

static inline bool
client_has_cap(const struct Client *client, uint32_t cap_flag)
{
  return client_is_local(client) && ((client->connection->cap & cap_flag));
}

static inline bool
client_has_flag(const struct Client *client, uint32_t flag)
{
  return (client->flags & flag) != 0;
}

static inline void
client_set_flag(struct Client *client, uint32_t flags)
{
  client->flags |= flags;
}

static inline void
client_unset_flag(struct Client *client, uint32_t flags)
{
  client->flags &= ~flags;
}

static inline bool
client_has_oper_flag(const struct Client *client, uint32_t flag)
{
  return client_is_local(client) && ((client->connection->operflags & flag));
}

static inline void
client_set_oper_flag(struct Client *client, uint32_t flag)
{
  if (client_is_local(client))
    client->connection->operflags |= flag;
}

static inline void
client_unset_oper_flag(struct Client *client, uint32_t flag)
{
  if (client_is_local(client))
    client->connection->operflags &= ~flag;
}

static inline void
client_clear_oper_flags(struct Client *client)
{
  if (client_is_local(client))
    client->connection->operflags = 0;
}

static inline bool
client_has_account(const struct Client *client)
{
  return !string_is_empty(client->account) && strcmp(client->account, "*");
}

static inline bool
client_is_me(const struct Client *client)
{
  return client == &me;
}

static inline bool
client_is_connecting(const struct Client *client)
{
  return client->state == CLIENT_STATE_CONNECTING;
}

static inline bool
client_is_handshake(const struct Client *client)
{
  return client->state == CLIENT_STATE_HANDSHAKE;
}

static inline bool
client_is_unknown(const struct Client *client)
{
  return client->state == CLIENT_STATE_UNKNOWN;
}

static inline bool
client_is_oper(const struct Client *client)
{
  return user_mode_has_flag(client, UMODE_OPER);
}

static inline bool
client_is_admin(const struct Client *client)
{
  return user_mode_has_flag(client, UMODE_ADMIN);
}

static inline bool
client_is_dead(const struct Client *client)
{
  return client_has_flag(client, FLAGS_DEADSOCKET);
}

static inline void
client_set_dead(struct Client *client)
{
  client_set_flag(client, FLAGS_DEADSOCKET);
}

static inline bool
client_is_defunct(const struct Client *client)
{
  return client_has_flag(client, FLAGS_DEADSOCKET | FLAGS_CLOSING);
}

static inline bool
client_is_hidden(const struct Client *client)
{
  return client_has_flag(client, FLAGS_HIDDEN);
}

static inline bool
client_is_service(const struct Client *client)
{
  return client_has_flag(client, FLAGS_SERVICE);
}

static inline const char *
client_get_id_or_name(const struct Client *subject_client, const struct Client *context_client)
{
  if (IsServer(context_client->nexthop) && subject_client->id[0])
    return subject_client->id;

  return subject_client->name;
}

static inline const struct ClassItem *
client_get_active_class(const struct Client *client)
{
  assert(client_is_local(client));
  if (client->connection->oper_class)
    return client->connection->oper_class;
  if (client->connection->base_class)
    return client->connection->base_class;

  return class_default;
}

static inline unsigned int
client_get_max_sendq(const struct Client *client)
{
  assert(client_is_local(client));
  return class_get_max_sendq(client_get_active_class(client));
}

static inline unsigned int
client_get_max_recvq(const struct Client *client)
{
  assert(client_is_local(client));
  return class_get_max_recvq(client_get_active_class(client));
}

static inline unsigned int
client_get_ping_freq(const struct Client *client)
{
  assert(client_is_local(client));
  return class_get_ping_freq(client_get_active_class(client));
}

static inline unsigned int
client_get_max_channels(const struct Client *client)
{
  assert(client_is_local(client));
  const unsigned int class_limit = class_get_max_channels(client_get_active_class(client));
  return (class_limit > 0) ? class_limit : ConfigChannel.max_channels;
}

static inline uintmax_t
client_get_session_duration(const struct Client *client)
{
  assert(client_is_local(client));
  return io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->created_monotonic;
}

static inline uintmax_t
client_get_socket_idle_duration(const struct Client *client)
{
  assert(client_is_local(client));
  return io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->last_receive_time;
}

static inline uintmax_t
client_get_idle_duration(const struct Client *client)
{
  assert(client_is_local(client));
  return io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->last_privmsg_time;
}

static inline const char *
client_get_class_name(const struct Client *client)
{
  assert(client_is_local(client));
  return class_get_name(client_get_active_class(client));
}
#endif  /* INCLUDED_client_h */
