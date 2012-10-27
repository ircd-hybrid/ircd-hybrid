/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  conf.h: A header for the configuration functions.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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

#ifndef INCLUDED_s_conf_h
#define INCLUDED_s_conf_h
#include "config.h"
#ifdef HAVE_LIBCRYPTO
#include <openssl/rsa.h>
#endif
#include "ircd_defs.h"
#include "motd.h"               /* MessageFile */
#include "client.h"
#include "hook.h"


struct Client;

extern struct Callback *client_check_cb;

struct conf_parser_context
{
  unsigned int boot;
  unsigned int pass;
  FILE *conf_file;
};

extern struct conf_parser_context conf_parser_ctx;

typedef enum
{  
  CONF_TYPE, 
  CLASS_TYPE,
  OPER_TYPE,
  CLIENT_TYPE,
  SERVER_TYPE,
  HUB_TYPE,
  LEAF_TYPE,
  KLINE_TYPE,
  DLINE_TYPE,
  EXEMPTDLINE_TYPE,
  CLUSTER_TYPE,
  RKLINE_TYPE,
  RXLINE_TYPE,
  XLINE_TYPE,    
  ULINE_TYPE,
  GLINE_TYPE,
  CRESV_TYPE,     
  NRESV_TYPE,
  SERVICE_TYPE
} ConfType;

struct split_nuh_item
{
  dlink_node node;

  char *nuhmask;
  char *nickptr;
  char *userptr;
  char *hostptr;

  size_t nicksize;
  size_t usersize;
  size_t hostsize;
};

struct ConfItem
{
  dlink_node node;      /* link into known ConfItems of this type */

  char *name;		/* Primary key */
  void *regexpname;
  unsigned int flags;
  ConfType type;
};

/*
 * MatchItem - used for XLINE and ULINE types
 */
struct MatchItem
{
  char *user;		/* Used for ULINE only */
  char *host;		/* Used for ULINE only */
  char *reason;
  char *oper_reason;
  int action;		/* used for uline */
  int count;		/* How many times this matchitem has been matched */
  int ref_count;	/* How many times is this matchitem in use */
  int illegal;		/* Should it be deleted when possible? */
  time_t           hold;     /* Hold action until this time (calendar time) */
};

struct AccessItem
{
  dlink_node node;
  unsigned int     dns_failed;
  unsigned int     dns_pending;
  unsigned int     status;   /* If CONF_ILLEGAL, delete when no clients */
  unsigned int     flags;
  unsigned int     modes;
  unsigned int     port;
  int              clients;  /* Number of *LOCAL* clients using this */
  int              bits;
  int              type;
  struct irc_ssaddr bind;  /* ip to bind to for outgoing connect */
  struct irc_ssaddr addr;  /* ip to connect to */
  char *           host;     /* host part of user@host */
  char *           passwd;
  char *           spasswd;  /* Password to send. */
  char *	   reason;
  char *	   oper_reason;
  char *           user;     /* user part of user@host */
  time_t           hold;     /* Hold action until this time (calendar time) */
  struct ConfItem *class_ptr;  /* Class of connection */
  int              aftype;
#ifdef HAVE_LIBCRYPTO
  /* certs */
  char *cipher_list;
  char *           rsa_public_key_file;
  RSA *            rsa_public_key;
#endif
  void *regexuser;
  void *regexhost;
  dlink_list leaf_list;
  dlink_list hub_list;
};

struct ClassItem
{
  dlink_list list_ipv4;         /* base of per cidr ipv4 client link list */
  dlink_list list_ipv6;         /* base of per cidr ipv6 client link list */
  unsigned int max_sendq;
  unsigned int max_recvq;
  int con_freq;
  int ping_freq;
  int ping_warning;
  int max_total;
  int max_local;
  int max_global;
  int max_ident;
  int max_perip;
  int curr_user_count;
  int cidr_bitlen_ipv4;
  int cidr_bitlen_ipv6;
  int number_per_cidr;
  int active;
};

struct CidrItem
{
  dlink_node node;
  struct irc_ssaddr mask;
  int number_on_this_cidr;
};


#define CONF_ILLEGAL            0x80000000
#define CONF_RESERVED           0x00000001
#define CONF_CLIENT             0x00000002
#define CONF_SERVER             0x00000004
#define CONF_OPERATOR           0x00000008
#define CONF_KLINE              0x00000010
#define CONF_CLASS              0x00000020
#define CONF_DLINE              0x00000040
#define CONF_XLINE              0x00000080
#define CONF_ULINE              0x00000100
#define CONF_EXEMPTDLINE        0x00000200
#define CONF_GLINE              0x00000400
#define CONF_SERVICE            0x00000800

#define CONF_SERVER_MASK       CONF_SERVER
#define CONF_CLIENT_MASK       (CONF_CLIENT | CONF_OPERATOR | CONF_SERVER_MASK)

/* XXX temporary hack */
#define CONF_CRESV	        0x80000001
#define CONF_NRESV	        0x80000002

#define IsConfIllegal(x)	((x)->status & CONF_ILLEGAL)
#define SetConfIllegal(x)	((x)->status |= CONF_ILLEGAL)
#define IsConfServer(x)		((x)->status == CONF_SERVER)
#define SetConfServer(x)	((x)->status = CONF_SERVER)
#define IsConfOperator(x)	((x)->status & CONF_OPERATOR)
#define IsConfKill(x)		((x)->status == CONF_KLINE)
#define IsConfClient(x)		((x)->status & CONF_CLIENT)
#define IsConfUline(x)		((x)->status & CONF_ULINE)
#define IsConfXline(x)		((x)->status & CONF_XLINE)
#define IsConfGline(x)          ((x)->status == CONF_GLINE)

/* AccessItem->flags */

/* Generic flags... */
/* access flags... */
#define CONF_FLAGS_DO_IDENTD            0x00000001
#define CONF_FLAGS_LIMIT_IP             0x00000002
#define CONF_FLAGS_NO_TILDE             0x00000004
#define CONF_FLAGS_NEED_IDENTD          0x00000008
#define CONF_FLAGS_NOMATCH_IP           0x00000010
#define CONF_FLAGS_EXEMPTKLINE          0x00000020
#define CONF_FLAGS_NOLIMIT              0x00000040
#define CONF_FLAGS_SPOOF_IP             0x00000080
#define CONF_FLAGS_SPOOF_NOTICE         0x00000100
#define CONF_FLAGS_REDIR                0x00000200
#define CONF_FLAGS_EXEMPTGLINE          0x00000400
#define CONF_FLAGS_CAN_FLOOD            0x00000800
#define CONF_FLAGS_NEED_PASSWORD        0x00001000
/* server flags */
#define CONF_FLAGS_ALLOW_AUTO_CONN      0x00002000
#define CONF_FLAGS_ENCRYPTED            0x00004000
#define CONF_FLAGS_TEMPORARY            0x00008000
#define CONF_FLAGS_EXEMPTRESV           0x00010000
#define CONF_FLAGS_SSL                  0x00020000

/* Macros for struct AccessItem */
#define IsLimitIp(x)            ((x)->flags & CONF_FLAGS_LIMIT_IP)
#define IsNoTilde(x)            ((x)->flags & CONF_FLAGS_NO_TILDE)
#define IsConfCanFlood(x)       ((x)->flags & CONF_FLAGS_CAN_FLOOD)
#define IsNeedPassword(x)       ((x)->flags & CONF_FLAGS_NEED_PASSWORD)
#define IsNeedIdentd(x)         ((x)->flags & CONF_FLAGS_NEED_IDENTD)
#define IsNoMatchIp(x)          ((x)->flags & CONF_FLAGS_NOMATCH_IP)
#define IsConfExemptKline(x)    ((x)->flags & CONF_FLAGS_EXEMPTKLINE)
#define IsConfExemptLimits(x)   ((x)->flags & CONF_FLAGS_NOLIMIT)
#define IsConfExemptGline(x)    ((x)->flags & CONF_FLAGS_EXEMPTGLINE)
#define IsConfExemptResv(x)     ((x)->flags & CONF_FLAGS_EXEMPTRESV)
#define IsConfDoIdentd(x)       ((x)->flags & CONF_FLAGS_DO_IDENTD)
#define IsConfDoSpoofIp(x)      ((x)->flags & CONF_FLAGS_SPOOF_IP)
#define IsConfSpoofNotice(x)    ((x)->flags & CONF_FLAGS_SPOOF_NOTICE)
#define IsConfEncrypted(x)      ((x)->flags & CONF_FLAGS_ENCRYPTED)
#define SetConfEncrypted(x)	((x)->flags |= CONF_FLAGS_ENCRYPTED)
#define ClearConfEncrypted(x)	((x)->flags &= ~CONF_FLAGS_ENCRYPTED)
#define IsConfAllowAutoConn(x)  ((x)->flags & CONF_FLAGS_ALLOW_AUTO_CONN)
#define SetConfAllowAutoConn(x)	((x)->flags |= CONF_FLAGS_ALLOW_AUTO_CONN)
#define ClearConfAllowAutoConn(x) ((x)->flags &= ~CONF_FLAGS_ALLOW_AUTO_CONN)
#define IsConfTemporary(x)      ((x)->flags & CONF_FLAGS_TEMPORARY)
#define SetConfTemporary(x)     ((x)->flags |= CONF_FLAGS_TEMPORARY)
#define IsConfRedir(x)          ((x)->flags & CONF_FLAGS_REDIR)
#define IsConfSSL(x)      ((x)->flags & CONF_FLAGS_SSL)
#define SetConfSSL(x)     ((x)->flags |= CONF_FLAGS_SSL)
#define ClearConfSSL(x)   ((x)->flags &= ~CONF_FLAGS_SSL)

/* shared/cluster server entry types 
 * These defines are used for both shared and cluster.
 */
#define SHARED_KLINE		0x0001
#define SHARED_UNKLINE		0x0002
#define SHARED_XLINE		0x0004
#define SHARED_UNXLINE		0x0008
#define SHARED_RESV		0x0010
#define SHARED_UNRESV		0x0020
#define SHARED_LOCOPS           0x0040
#define SHARED_DLINE            0x0080
#define SHARED_UNDLINE          0x0100
#define SHARED_ALL		(SHARED_KLINE | SHARED_UNKLINE |\
				 SHARED_XLINE | SHARED_UNXLINE |\
				 SHARED_RESV | SHARED_UNRESV |\
                                 SHARED_LOCOPS | SHARED_DLINE | SHARED_UNDLINE)

struct config_file_entry
{
  const char *dpath;          /* DPATH if set from command line */
  const char *configfile;
  const char *klinefile;
  const char *xlinefile;
  const char *dlinefile;
  const char *cresvfile;
  const char *nresvfile;

  char *egdpool_path;
  char *service_name;

  MessageFile motd;
  MessageFile linksfile;

  int gline_min_cidr;
  int gline_min_cidr6;
  int dots_in_ident;
  int failed_oper_notice;
  int anti_spam_exit_message_time;
  unsigned int max_accept;
  unsigned int max_watch;
  int max_nick_time;
  unsigned int max_nick_changes;
  int ts_max_delta;
  int ts_warn_delta;
  int anti_nick_flood;
  int warn_no_nline;
  int invisible_on_connect;
  int stats_e_disabled;
  int stats_o_oper_only;
  int stats_k_oper_only;
  int stats_i_oper_only;
  int stats_P_oper_only;
  int short_motd;
  int no_oper_flood;
  int true_no_oper_flood;
  int oper_pass_resv;
  int glines;
  int hide_spoof_ips;
  int tkline_expire_notices;
  int opers_bypass_callerid;
  int ignore_bogus_ts;
  int pace_wait;
  int pace_wait_simple;
  int gline_time;
  int gline_request_time;
  int oper_only_umodes;
  int oper_umodes;
  int max_targets;
  int caller_id_wait;
  int min_nonwildcard;
  int min_nonwildcard_simple;
  int kill_chase_time_limit;
  int default_floodcount;
  /* 0 == don't use throttle... */
  int throttle_time;
  int use_egd;
  int ping_cookie;
  int disable_auth;
  int disable_remote;
};

struct config_channel_entry
{
  int disable_fake_channels;
  int restrict_channels;
  int knock_delay;
  int knock_delay_channel;
  unsigned int max_bans;
  unsigned int max_chans_per_user;
  unsigned int max_chans_per_oper;
  int no_create_on_split;
  int no_join_on_split;
  int quiet_on_ban;
  int default_split_server_count;
  int default_split_user_count;
};

struct config_server_hide
{
  char *hidden_name;
  int flatten_links;
  int hide_servers;
  int links_delay;
  int links_disabled;
  int hidden;
  int hide_server_ips;
};

struct server_info
{
  char *sid;
  char *name;
  char *description;
  char *network_name;
  char *network_desc;
#ifdef HAVE_LIBCRYPTO
  char *rsa_private_key_file;
  RSA *rsa_private_key;
  SSL_CTX *server_ctx;
  SSL_CTX *client_ctx;
#endif
  int hub;
  struct irc_ssaddr ip;
  struct irc_ssaddr ip6;
  unsigned int max_clients;
  int specific_ipv4_vhost;
  int specific_ipv6_vhost;
  struct sockaddr_in dns_host;
  int can_use_v6;
};

struct admin_info
{
  char *name;
  char *description;
  char *email;
};

struct logging_entry
{
  unsigned int use_logging;
};

extern dlink_list class_items;
extern dlink_list server_items;
extern dlink_list cluster_items;
extern dlink_list hub_items;
extern dlink_list rxconf_items;
extern dlink_list rkconf_items;
extern dlink_list leaf_items;
extern dlink_list service_items;
extern dlink_list temporary_xlines;
extern struct logging_entry ConfigLoggingEntry;
extern struct config_file_entry ConfigFileEntry;/* defined in ircd.c*/
extern struct config_channel_entry ConfigChannel;/* defined in channel.c*/
extern struct config_server_hide ConfigServerHide; /* defined in s_conf.c */
extern struct server_info ServerInfo;       /* defined in ircd.c */
extern struct admin_info AdminInfo;        /* defined in ircd.c */
extern int valid_wild_card(struct Client *, int, int, ...);
/* End GLOBAL section */

extern unsigned int get_sendq(struct Client *);
extern unsigned int get_recvq(struct Client *);
extern const char *get_client_class(struct Client *);
extern int get_client_ping(struct Client *, int *);
extern void check_class(void);
extern void init_class(void);
extern struct ConfItem *find_class(const char *);
extern void init_ip_hash_table(void);
extern void count_ip_hash(unsigned int *, uint64_t *);
extern void remove_one_ip(struct irc_ssaddr *);
extern struct ConfItem *make_conf_item(ConfType type);
extern void free_access_item(struct AccessItem *);
extern void read_conf_files(int);
extern int attach_conf(struct Client *, struct ConfItem *);
extern int attach_connect_block(struct Client *, const char *, const char *);

extern int detach_conf(struct Client *, ConfType);

extern struct ConfItem *find_conf_name(dlink_list *, const char *, ConfType);
extern struct ConfItem *find_conf_exact(ConfType, const char *, const char *, const char *);
extern struct AccessItem *find_kill(struct Client *);
extern struct AccessItem *find_gline(struct Client *);
extern int conf_connect_allowed(struct irc_ssaddr *, int);
extern char *oper_privs_as_string(const unsigned int);
extern void split_nuh(struct split_nuh_item *);
extern struct ConfItem *find_matching_name_conf(ConfType, const char *,
                                                const char *, const char *, int);
extern struct ConfItem *find_exact_name_conf(ConfType, const struct Client *, const char *,
                                             const char *, const char *);
extern void delete_conf_item(struct ConfItem *);
extern void report_confitem_types(struct Client *, ConfType);
extern void yyerror(const char *);
extern void write_conf_line(struct Client *, struct ConfItem *,
                            const char *, time_t);
extern int remove_conf_line(ConfType, struct Client *, const char *,
                            const char *);
extern void add_temp_line(struct ConfItem *);
extern void cleanup_tklines(void *);
extern const char *get_conf_name(ConfType);
extern int rehash(int);
extern int conf_add_server(struct ConfItem *, const char *);
extern void conf_add_class_to_conf(struct ConfItem *, const char *);

/* XXX consider moving these into csvlib.h */
extern void parse_csv_file(FILE *, ConfType);
extern int find_and_delete_temporary(const char *, const char *, int);
extern const char *get_oper_name(const struct Client *);

extern void *map_to_conf(struct ConfItem *);
extern struct ConfItem *unmap_conf_item(void *);
/* XXX should the parse_aline stuff go into another file ?? */
#define AWILD 0x1		/* check wild cards */
extern int parse_aline(const char *, struct Client *, int, char **,
		       int, char **, char **, time_t *, char **, char **);
extern int valid_comment(struct Client *, char *, int);


#define TK_SECONDS 0
#define TK_MINUTES 1
extern time_t valid_tkline(const char *, int);
extern int match_conf_password(const char *, const struct AccessItem *);

#define NOT_AUTHORIZED    (-1)
#define I_LINE_FULL       (-2)
#define TOO_MANY          (-3)
#define BANNED_CLIENT     (-4)
#define TOO_FAST          (-5)

#define CLEANUP_TKLINES_TIME 60

extern void cluster_a_line(struct Client *,
			   const char *, int, int, const char *,...);
extern void rebuild_cidr_class(struct ConfItem *, struct ClassItem *);
#endif /* INCLUDED_s_conf_h */
