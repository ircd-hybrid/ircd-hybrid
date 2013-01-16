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
#include "ircd_defs.h"
#include "motd.h"               /* MessageFile */
#include "client.h"
#include "hook.h"
#include "conf_class.h"


#define CONF_NOREASON "<No reason supplied>"

struct conf_parser_context
{
  unsigned int boot;
  unsigned int pass;
  FILE *conf_file;
};

extern struct conf_parser_context conf_parser_ctx;

enum maskitem_type
{
  CONF_RESERVED = 1 <<  0, /* XXX */
  CONF_CLIENT   = 1 <<  1,
  CONF_SERVER   = 1 <<  2,
  CONF_KLINE    = 1 <<  3,
  CONF_DLINE    = 1 <<  4,
  CONF_EXEMPT   = 1 <<  5,
  CONF_CLUSTER  = 1 <<  6,
  CONF_RKLINE   = 1 <<  7,
  CONF_RXLINE   = 1 <<  8,
  CONF_XLINE    = 1 <<  9,
  CONF_ULINE    = 1 << 10,
  CONF_GLINE    = 1 << 11,
  CONF_CRESV    = 1 << 12,
  CONF_NRESV    = 1 << 13,
  CONF_SERVICE  = 1 << 14,
  CONF_OPER     = 1 << 15,
  CONF_HUB      = 1 << 16, /* XXX There are no separate hub/leaf configs anymore. This is just for /stats h */
  CONF_CLASS    = 1 << 17  /* XXX Same here; just for /stats Y|y */
};

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

struct MaskItem
{
  struct MaskItem   *hnext;
  dlink_node         node;
  dlink_list         leaf_list;
  dlink_list         hub_list;
  enum maskitem_type type;
  unsigned int       dns_failed;
  unsigned int       dns_pending;
  unsigned int       flags;
  unsigned int       modes;
  unsigned int       port;
  unsigned int       count;
  unsigned int       aftype;
  unsigned int       active;
  unsigned int       htype;
  unsigned int       ref_count;  /* Number of *LOCAL* clients using this */
  int                bits;
  time_t             until;     /* Hold action until this time (calendar time) */
  time_t             setat;
  struct irc_ssaddr  bind;  /* ip to bind to for outgoing connect */
  struct irc_ssaddr  addr;  /* ip to connect to */
  struct ClassItem  *class;  /* Class of connection */
  char              *name;
  char              *user;     /* user part of user@host */
  char              *host;     /* host part of user@host */
  char              *passwd;
  char              *spasswd;  /* Password to send. */
  char              *reason;
  char              *cipher_list;
  void              *rsa_public_key;
  void              *regexuser;
  void              *regexhost;
};

struct CidrItem
{
  dlink_node node;
  struct irc_ssaddr mask;
  unsigned int number_on_this_cidr;
};


#define IsConfOperator(x)	((x)->type == CONF_OPER)
#define IsConfKill(x)		((x)->type == CONF_KLINE)
#define IsConfClient(x)		((x)->type == CONF_CLIENT)
#define IsConfGline(x)          ((x)->type == CONF_GLINE)

/* MaskItem->flags */
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
#define CONF_FLAGS_ALLOW_AUTO_CONN      0x00002000
#define CONF_FLAGS_ENCRYPTED            0x00004000
#define CONF_FLAGS_IN_DATABASE          0x00008000
#define CONF_FLAGS_EXEMPTRESV           0x00010000
#define CONF_FLAGS_SSL                  0x00020000
#define CONF_FLAGS_WEBIRC               0x00040000

/* Macros for struct MaskItem */
#define IsConfWebIRC(x)         ((x)->flags & CONF_FLAGS_WEBIRC)
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
#define IsConfRedir(x)          ((x)->flags & CONF_FLAGS_REDIR)
#define IsConfSSL(x)      ((x)->flags & CONF_FLAGS_SSL)
#define SetConfSSL(x)     ((x)->flags |= CONF_FLAGS_SSL)
#define ClearConfSSL(x)   ((x)->flags &= ~CONF_FLAGS_SSL)
#define IsConfDatabase(x)      ((x)->flags & CONF_FLAGS_IN_DATABASE)
#define SetConfDatabase(x)     ((x)->flags |= CONF_FLAGS_IN_DATABASE)


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
  const char *glinefile;
  const char *xlinefile;
  const char *dlinefile;
  const char *resvfile;

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
  char *rsa_private_key_file;
  void *rsa_private_key;
  void *server_ctx;
  void *client_ctx;
  int hub;
  struct irc_ssaddr ip;
  struct irc_ssaddr ip6;
  unsigned int max_clients;
  unsigned int max_nick_length;
  unsigned int max_topic_length;
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

extern dlink_list server_items;
extern dlink_list cluster_items;
extern dlink_list xconf_items;
extern dlink_list rxconf_items;
extern dlink_list rkconf_items;
extern dlink_list service_items;
extern struct logging_entry ConfigLoggingEntry;
extern struct config_file_entry ConfigFileEntry;/* defined in ircd.c*/
extern struct config_channel_entry ConfigChannel;/* defined in channel.c*/
extern struct config_server_hide ConfigServerHide; /* defined in s_conf.c */
extern struct server_info ServerInfo;       /* defined in ircd.c */
extern struct admin_info AdminInfo;        /* defined in ircd.c */
extern int valid_wild_card(struct Client *, int, int, ...);
/* End GLOBAL section */




extern void init_ip_hash_table(void);
extern void count_ip_hash(unsigned int *, uint64_t *);
extern void remove_one_ip(struct irc_ssaddr *);
extern struct MaskItem *conf_make(enum maskitem_type);
extern void read_conf_files(int);
extern int attach_conf(struct Client *, struct MaskItem *);
extern int attach_connect_block(struct Client *, const char *, const char *);
extern int check_client(struct Client *);


extern void detach_conf(struct Client *, enum maskitem_type);
extern struct MaskItem *find_conf_name(dlink_list *, const char *, enum maskitem_type);
extern struct MaskItem *find_kill(struct Client *);
extern struct MaskItem *find_gline(struct Client *);
extern int conf_connect_allowed(struct irc_ssaddr *, int);
extern char *oper_privs_as_string(const unsigned int);
extern void split_nuh(struct split_nuh_item *);
extern struct MaskItem *find_matching_name_conf(enum maskitem_type, const char *,
                                                const char *, const char *, unsigned int);
extern struct MaskItem *find_exact_name_conf(enum maskitem_type, const struct Client *, const char *,
                                             const char *, const char *);
extern void conf_free(struct MaskItem *);
extern void report_confitem_types(struct Client *, enum maskitem_type);
extern void yyerror(const char *);
extern void conf_error_report(const char *);
extern void cleanup_tklines(void *);
extern int rehash(int);
extern void lookup_confhost(struct MaskItem *);
extern void conf_add_class_to_conf(struct MaskItem *, const char *);

extern const char *get_oper_name(const struct Client *);

/* XXX should the parse_aline stuff go into another file ?? */
#define AWILD 0x1		/* check wild cards */
extern int parse_aline(const char *, struct Client *, int, char **,
		       int, char **, char **, time_t *, char **, char **);
extern int valid_comment(struct Client *, char *, int);


#define TK_SECONDS 0
#define TK_MINUTES 1
extern time_t valid_tkline(const char *, int);
extern int match_conf_password(const char *, const struct MaskItem *);

#define NOT_AUTHORIZED    (-1)
#define I_LINE_FULL       (-2)
#define TOO_MANY          (-3)
#define BANNED_CLIENT     (-4)
#define TOO_FAST          (-5)

#define CLEANUP_TKLINES_TIME 60

extern void cluster_a_line(struct Client *,
			   const char *, int, int, const char *,...);
#endif /* INCLUDED_s_conf_h */
