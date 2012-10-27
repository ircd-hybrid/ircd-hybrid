/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd_parser.y: Parses the ircd configuration file.
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

%{

#define YY_NO_UNPUT
#include <sys/types.h>

#include "stdinc.h"
#include "dalloca.h"
#include "ircd.h"
#include "tools.h"
#include "list.h"
#include "s_conf.h"
#include "event.h"
#include "s_log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "pcre.h"
#include "irc_string.h"
#include "irc_getaddrinfo.h"
#include "sprintf_irc.h"
#include "memory.h"
#include "modules.h"
#include "s_serv.h" /* for CAP_LL / IsCapable */
#include "hostmask.h"
#include "send.h"
#include "listener.h"
#include "resv.h"
#include "numeric.h"
#include "s_user.h"

#ifdef HAVE_LIBCRYPTO
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#endif

static char *class_name = NULL;
static struct ConfItem *yy_conf = NULL;
static struct AccessItem *yy_aconf = NULL;
static struct MatchItem *yy_match_item = NULL;
static struct ClassItem *yy_class = NULL;
static char *yy_class_name = NULL;

static dlink_list col_conf_list  = { NULL, NULL, 0 };
static dlink_list hub_conf_list  = { NULL, NULL, 0 };
static dlink_list leaf_conf_list = { NULL, NULL, 0 };
static unsigned int listener_flags = 0;
static unsigned int regex_ban = 0;
static char userbuf[IRCD_BUFSIZE];
static char hostbuf[IRCD_BUFSIZE];
static char reasonbuf[REASONLEN + 1];
static char gecos_name[REALLEN * 4];

extern dlink_list gdeny_items; /* XXX */

static char *resv_reason = NULL;
static char *listener_address = NULL;
static int not_atom = 0;

struct CollectItem {
  dlink_node node;
  char *name;
  char *user;
  char *host;
  char *passwd;
  int  port;
  int  flags;
#ifdef HAVE_LIBCRYPTO
  char *rsa_public_key_file;
  RSA *rsa_public_key;
#endif
};

static void
free_collect_item(struct CollectItem *item)
{
  MyFree(item->name);
  MyFree(item->user);
  MyFree(item->host);
  MyFree(item->passwd);
#ifdef HAVE_LIBCRYPTO
  MyFree(item->rsa_public_key_file);
#endif
  MyFree(item);
}

static void
unhook_hub_leaf_confs(void)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct CollectItem *yy_hconf;
  struct CollectItem *yy_lconf;

  DLINK_FOREACH_SAFE(ptr, next_ptr, hub_conf_list.head)
  {
    yy_hconf = ptr->data;
    dlinkDelete(&yy_hconf->node, &hub_conf_list);
    free_collect_item(yy_hconf);
  }

  DLINK_FOREACH_SAFE(ptr, next_ptr, leaf_conf_list.head)
  {
    yy_lconf = ptr->data;
    dlinkDelete(&yy_lconf->node, &leaf_conf_list);
    free_collect_item(yy_lconf);
  }
}

%}

%union {
  int number;
  char *string;
}

%token  ACCEPT_PASSWORD
%token  ACTION
%token  ADMIN
%token  AFTYPE
%token	T_ALLOW
%token  ANTI_NICK_FLOOD
%token  ANTI_SPAM_EXIT_MESSAGE_TIME
%token  AUTOCONN
%token	T_BLOCK
%token  BURST_AWAY
%token  BURST_TOPICWHO
%token  BYTES KBYTES MBYTES GBYTES TBYTES
%token  CALLER_ID_WAIT
%token  CAN_FLOOD
%token  CAN_IDLE
%token  CHANNEL
%token	CIDR_BITLEN_IPV4
%token	CIDR_BITLEN_IPV6
%token  CIPHER_PREFERENCE
%token  CLASS
%token  COMPRESSED
%token  COMPRESSION_LEVEL
%token  CONNECT
%token  CONNECTFREQ
%token  CRYPTLINK
%token  DEFAULT_CIPHER_PREFERENCE
%token  DEFAULT_FLOODCOUNT
%token  DEFAULT_SPLIT_SERVER_COUNT
%token  DEFAULT_SPLIT_USER_COUNT
%token  DENY
%token  DESCRIPTION
%token  DIE
%token  DISABLE_AUTH
%token  DISABLE_HIDDEN
%token  DISABLE_LOCAL_CHANNELS
%token  DISABLE_REMOTE_COMMANDS
%token  DOT_IN_IP6_ADDR
%token  DOTS_IN_IDENT
%token	DURATION
%token  EGDPOOL_PATH
%token  EMAIL
%token	ENABLE
%token  ENCRYPTED
%token  EXCEED_LIMIT
%token  EXEMPT
%token  FAILED_OPER_NOTICE
%token  FAKENAME
%token  IRCD_FLAGS
%token  FLATTEN_LINKS
%token  FFAILED_OPERLOG
%token  FKILLLOG
%token  FKLINELOG
%token  FGLINELOG
%token  FIOERRLOG
%token  FOPERLOG
%token  FOPERSPYLOG
%token  FUSERLOG
%token  GECOS
%token  GENERAL
%token  GLINE
%token  GLINES
%token  GLINE_EXEMPT
%token  GLINE_LOG
%token  GLINE_TIME
%token  GLINE_MIN_CIDR
%token  GLINE_MIN_CIDR6
%token  GLOBAL_KILL
%token  IRCD_AUTH
%token  NEED_IDENT
%token  HAVENT_READ_CONF
%token  HIDDEN
%token  HIDDEN_ADMIN
%token	HIDDEN_NAME
%token  HIDDEN_OPER
%token  HIDE_SERVER_IPS
%token  HIDE_SERVERS
%token	HIDE_SPOOF_IPS
%token  HOST
%token  HUB
%token  HUB_MASK
%token  IDLETIME
%token  IGNORE_BOGUS_TS
%token  INVISIBLE_ON_CONNECT
%token  IP
%token  KILL
%token	KILL_CHASE_TIME_LIMIT
%token  KLINE
%token  KLINE_EXEMPT
%token  KLINE_REASON
%token  KLINE_WITH_REASON
%token  KNOCK_DELAY
%token  KNOCK_DELAY_CHANNEL
%token  LAZYLINK
%token  LEAF_MASK
%token  LINKS_DELAY
%token  LISTEN
%token  T_LOG
%token  LOGGING
%token  LOG_LEVEL
%token  MAX_ACCEPT
%token  MAX_BANS
%token  MAX_CHANS_PER_USER
%token  MAX_GLOBAL
%token  MAX_IDENT
%token  MAX_LOCAL
%token  MAX_NICK_CHANGES
%token  MAX_NICK_TIME
%token  MAX_NUMBER
%token  MAX_TARGETS
%token  MESSAGE_LOCALE
%token  MIN_NONWILDCARD
%token  MIN_NONWILDCARD_SIMPLE
%token  MODULE
%token  MODULES
%token  NAME
%token  NEED_PASSWORD
%token  NETWORK_DESC
%token  NETWORK_NAME
%token  NICK
%token  NICK_CHANGES
%token  NO_CREATE_ON_SPLIT
%token  NO_JOIN_ON_SPLIT
%token  NO_OPER_FLOOD
%token  NO_TILDE
%token  NOT
%token  NUMBER
%token  NUMBER_PER_IDENT
%token  NUMBER_PER_CIDR
%token  NUMBER_PER_IP
%token  NUMBER_PER_IP_GLOBAL
%token  OPERATOR
%token  OPERS_BYPASS_CALLERID
%token  OPER_LOG
%token  OPER_ONLY_UMODES
%token  OPER_PASS_RESV
%token  OPER_SPY_T
%token  OPER_UMODES
%token  JOIN_FLOOD_COUNT
%token  JOIN_FLOOD_TIME
%token  PACE_WAIT
%token  PACE_WAIT_SIMPLE
%token  PASSWORD
%token  PATH
%token  PING_COOKIE
%token  PING_TIME
%token  PING_WARNING
%token  PORT
%token  QSTRING
%token  QUIET_ON_BAN
%token  REASON
%token  REDIRPORT
%token  REDIRSERV
%token  REGEX_T
%token  REHASH
%token  TREJECT_HOLD_TIME
%token  REMOTE
%token  REMOTEBAN
%token  RESTRICT_CHANNELS
%token  RESTRICTED
%token  RSA_PRIVATE_KEY_FILE
%token  RSA_PUBLIC_KEY_FILE
%token  SSL_CERTIFICATE_FILE
%token  RESV
%token  RESV_EXEMPT
%token  SECONDS MINUTES HOURS DAYS WEEKS
%token  SENDQ
%token  SEND_PASSWORD
%token  SERVERHIDE
%token  SERVERINFO
%token  SERVLINK_PATH
%token  IRCD_SID
%token	TKLINE_EXPIRE_NOTICES
%token  T_SHARED
%token  T_CLUSTER
%token  TYPE
%token  SHORT_MOTD
%token  SILENT
%token  SPOOF
%token  SPOOF_NOTICE
%token  STATS_I_OPER_ONLY
%token  STATS_K_OPER_ONLY
%token  STATS_O_OPER_ONLY
%token  STATS_P_OPER_ONLY
%token  TBOOL
%token  TMASKED
%token  T_REJECT
%token  TS_MAX_DELTA
%token  TS_WARN_DELTA
%token  TWODOTS
%token  T_ALL
%token  T_BOTS
%token  T_SOFTCALLERID
%token  T_CALLERID
%token  T_CCONN
%token  T_CLIENT_FLOOD
%token  T_DEAF
%token  T_DEBUG
%token  T_DRONE
%token  T_EXTERNAL
%token  T_FULL
%token  T_INVISIBLE
%token  T_IPV4
%token  T_IPV6
%token  T_LOCOPS
%token  T_LOGPATH
%token  T_L_CRIT
%token  T_L_DEBUG
%token  T_L_ERROR
%token  T_L_INFO
%token  T_L_NOTICE
%token  T_L_TRACE
%token  T_L_WARN
%token  T_MAX_CLIENTS
%token  T_NCHANGE
%token  T_OPERWALL
%token  T_REJ
%token  T_SERVNOTICE
%token  T_SKILL
%token  T_SPY
%token  T_SSL
%token  T_UMODES
%token  T_UNAUTH
%token  T_UNRESV
%token  T_UNXLINE
%token  T_WALLOP
%token  THROTTLE_TIME
%token  TOPICBURST
%token  TRUE_NO_OPER_FLOOD
%token  TKLINE
%token  TXLINE
%token  TRESV
%token  UNKLINE
%token  USER
%token  USE_EGD
%token  USE_EXCEPT
%token  USE_INVEX
%token  USE_KNOCK
%token  USE_LOGGING
%token  USE_WHOIS_ACTUALLY
%token  VHOST
%token  VHOST6
%token  XLINE
%token  WARN
%token  WARN_NO_NLINE

%type <string> QSTRING
%type <number> NUMBER
%type <number> timespec
%type <number> timespec_
%type <number> sizespec
%type <number> sizespec_

%%
conf:   
        | conf conf_item
        ;

conf_item:        admin_entry
                | logging_entry
                | oper_entry
		| channel_entry
                | class_entry 
                | listen_entry
                | auth_entry
                | serverinfo_entry
		| serverhide_entry
                | resv_entry
                | shared_entry
		| cluster_entry
                | connect_entry
                | kill_entry
                | deny_entry
		| exempt_entry
		| general_entry
		| gline_entry
                | gecos_entry
                | modules_entry
                | error ';'
                | error '}'
        ;


timespec_: { $$ = 0; } | timespec;
timespec:	NUMBER timespec_
		{
			$$ = $1 + $2;
		}
		| NUMBER SECONDS timespec_
		{
			$$ = $1 + $3;
		}
		| NUMBER MINUTES timespec_
		{
			$$ = $1 * 60 + $3;
		}
		| NUMBER HOURS timespec_
		{
			$$ = $1 * 60 * 60 + $3;
		}
		| NUMBER DAYS timespec_
		{
			$$ = $1 * 60 * 60 * 24 + $3;
		}
		| NUMBER WEEKS timespec_
		{
			$$ = $1 * 60 * 60 * 24 * 7 + $3;
		}
		;

sizespec_:	{ $$ = 0; } | sizespec;
sizespec:	NUMBER sizespec_ { $$ = $1 + $2; }
		| NUMBER BYTES sizespec_ { $$ = $1 + $3; }
		| NUMBER KBYTES sizespec_ { $$ = $1 * 1024 + $3; }
		| NUMBER MBYTES sizespec_ { $$ = $1 * 1024 * 1024 + $3; }
		;


/***************************************************************************
 *  section modules
 ***************************************************************************/
modules_entry: MODULES
  '{' modules_items '}' ';';

modules_items:  modules_items modules_item | modules_item;
modules_item:   modules_module | modules_path | error ';' ;

modules_module: MODULE '=' QSTRING ';'
{
#ifndef STATIC_MODULES /* NOOP in the static case */
  if (ypass == 2)
  {
    char *m_bn;

    m_bn = basename(yylval.string);

    /* I suppose we should just ignore it if it is already loaded(since
     * otherwise we would flood the opers on rehash) -A1kmm.
     */
    add_conf_module(yylval.string);
  }
#endif
};

modules_path: PATH '=' QSTRING ';'
{
#ifndef STATIC_MODULES
  if (ypass == 2)
    mod_add_path(yylval.string);
#endif
};

/***************************************************************************
 *  section serverinfo
 ***************************************************************************/
serverinfo_entry: SERVERINFO
  '{' serverinfo_items '}' ';';

serverinfo_items:       serverinfo_items serverinfo_item |
                        serverinfo_item ;
serverinfo_item:        serverinfo_name | serverinfo_vhost |
                        serverinfo_hub | serverinfo_description |
                        serverinfo_network_name | serverinfo_network_desc |
                        serverinfo_max_clients | 
                        serverinfo_rsa_private_key_file | serverinfo_vhost6 |
                        serverinfo_sid | serverinfo_ssl_certificate_file |
			error ';' ;

serverinfo_ssl_certificate_file: SSL_CERTIFICATE_FILE '=' QSTRING ';'
{
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2 && ServerInfo.ctx) 
  {
    if (!ServerInfo.rsa_private_key_file)
    {
      yyerror("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_file(ServerInfo.ctx,
      yylval.string, SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.ctx,
      ServerInfo.rsa_private_key_file, SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.ctx))
    {
      yyerror("RSA private key does not match the SSL certificate public key!");
      break;
    }
  }
#endif
};

serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'
{
#ifdef HAVE_LIBCRYPTO
  if (ypass == 1)
  {
    BIO *file;

    if (ServerInfo.rsa_private_key)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;
    }

    if (ServerInfo.rsa_private_key_file)
    {
      MyFree(ServerInfo.rsa_private_key_file);
      ServerInfo.rsa_private_key_file = NULL;
    }

    DupString(ServerInfo.rsa_private_key_file, yylval.string);

    if ((file = BIO_new_file(yylval.string, "r")) == NULL)
    {
      yyerror("File open failed, ignoring");
      break;
    }

    ServerInfo.rsa_private_key = (RSA *)PEM_read_bio_RSAPrivateKey(file, NULL,
      0, NULL);

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);

    if (ServerInfo.rsa_private_key == NULL)
    {
      yyerror("Couldn't extract key, ignoring");
      break;
    }

    if (!RSA_check_key(ServerInfo.rsa_private_key))
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      yyerror("Invalid key, ignoring");
      break;
    }

    /* require 2048 bit (256 byte) key */
    if (RSA_size(ServerInfo.rsa_private_key) != 256)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      yyerror("Not a 2048 bit key, ignoring");
    }
  }
#endif
};

serverinfo_name: NAME '=' QSTRING ';' 
{
  /* this isn't rehashable */
  if (ypass == 2)
  {
    if (ServerInfo.name == NULL)
    {
      /* the ircd will exit() in main() if we dont set one */
      if (strlen(yylval.string) <= HOSTLEN)
        DupString(ServerInfo.name, yylval.string);
    }
  }
};

serverinfo_sid: IRCD_SID '=' QSTRING ';' 
{
  /* this isn't rehashable */
  if (ypass == 2 && !ServerInfo.sid)
  {
    if ((strlen(yylval.string) == IRC_MAXSID) && IsDigit(yylval.string[0])
	&& IsAlNum(yylval.string[1]) && IsAlNum(yylval.string[2]))
    {
      DupString(ServerInfo.sid, yylval.string);
    }
    else
    {
      ilog(L_ERROR, "Ignoring config file entry SID -- invalid SID. Aborting.");
      exit(0);
    }
  }
};

serverinfo_description: DESCRIPTION '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
};

serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'
{
  if (ypass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      p = '\0';

    MyFree(ServerInfo.network_name);
    DupString(ServerInfo.network_name, yylval.string);
  }
};

serverinfo_network_desc: NETWORK_DESC '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
};

serverinfo_vhost: VHOST '=' QSTRING ';'
{
  if (ypass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip.ss.ss_family = res->ai_family;
      ServerInfo.ip.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);

      ServerInfo.specific_ipv4_vhost = 1;
    }
  }
};

serverinfo_vhost6: VHOST6 '=' QSTRING ';'
{
#ifdef IPV6
  if (ypass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost6(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip6.ss.ss_family = res->ai_family;
      ServerInfo.ip6.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);

      ServerInfo.specific_ipv6_vhost = 1;
    }
  }
#endif
};

serverinfo_max_clients: T_MAX_CLIENTS '=' NUMBER ';'
{
  if (ypass == 2)
  {
    recalc_fdlimit(NULL);

    if ($3 < MAXCLIENTS_MIN)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
      yyerror(buf);
    }
    else if ($3 > MAXCLIENTS_MAX)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
      yyerror(buf);
    }
    else
      ServerInfo.max_clients = $3;
  }
};

serverinfo_hub: HUB '=' TBOOL ';' 
{
  if (ypass == 2)
  {
    if (yylval.number)
    {
      /* Don't become a hub if we have a lazylink active. */
      if (!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
      {
        sendto_realops_flags(UMODE_ALL, L_ALL,
                             "Ignoring config file line hub=yes; "
                             "due to active LazyLink (%s)", uplink->name);
      }
      else
      {
        ServerInfo.hub = 1;
        uplink = NULL;
        delete_capability("HUB");
        add_capability("HUB", CAP_HUB, 1);
      }
    }
    else if (ServerInfo.hub)
    {
      dlink_node *ptr = NULL;

      ServerInfo.hub = 0;
      delete_capability("HUB");

      /* Don't become a leaf if we have a lazylink active. */
      DLINK_FOREACH(ptr, serv_list.head)
      {
        const struct Client *acptr = ptr->data;
        if (MyConnect(acptr) && IsCapable(acptr, CAP_LL))
        {
          sendto_realops_flags(UMODE_ALL, L_ALL,
                               "Ignoring config file line hub=no; "
                               "due to active LazyLink (%s)",
                               acptr->name);
          add_capability("HUB", CAP_HUB, 1);
          ServerInfo.hub = 1;
          break;
        }
      }
    }
  }
};

/***************************************************************************
 * admin section
 ***************************************************************************/
admin_entry: ADMIN  '{' admin_items '}' ';' ;

admin_items: admin_items admin_item | admin_item;
admin_item:  admin_name | admin_description |
             admin_email | error ';' ;

admin_name: NAME '=' QSTRING ';' 
{
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
};

admin_email: EMAIL '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
};

admin_description: DESCRIPTION '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
};

/***************************************************************************
 *  section logging
 ***************************************************************************/
/* XXX */
logging_entry:          LOGGING  '{' logging_items '}' ';' ;

logging_items:          logging_items logging_item |
                        logging_item ;

logging_item:           logging_path | logging_oper_log |
			logging_log_level |
			logging_use_logging | logging_fuserlog |
			logging_foperlog | logging_fglinelog |
			logging_fklinelog | logging_killlog |
			logging_foperspylog | logging_ioerrlog |
			logging_ffailed_operlog |
			error ';' ;

logging_path:           T_LOGPATH '=' QSTRING ';' 
                        {
                        };

logging_oper_log:	OPER_LOG '=' QSTRING ';'
                        {
                        };

logging_fuserlog: FUSERLOG '=' QSTRING ';'
{
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
};

logging_ffailed_operlog: FFAILED_OPERLOG '=' QSTRING ';'
{
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
};

logging_foperlog: FOPERLOG '=' QSTRING ';'
{
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
};

logging_foperspylog: FOPERSPYLOG '=' QSTRING ';'
{
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
};

logging_fglinelog: FGLINELOG '=' QSTRING ';'
{
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
};

logging_fklinelog: FKLINELOG '=' QSTRING ';'
{
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
};

logging_ioerrlog: FIOERRLOG '=' QSTRING ';'
{
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
};

logging_killlog: FKILLLOG '=' QSTRING ';'
{
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
};

logging_log_level: LOG_LEVEL '=' T_L_CRIT ';'
{ 
  if (ypass == 2)
    set_log_level(L_CRIT);
} | LOG_LEVEL '=' T_L_ERROR ';'
{
  if (ypass == 2)
    set_log_level(L_ERROR);
} | LOG_LEVEL '=' T_L_WARN ';'
{
  if (ypass == 2)
    set_log_level(L_WARN);
} | LOG_LEVEL '=' T_L_NOTICE ';'
{
  if (ypass == 2)
    set_log_level(L_NOTICE);
} | LOG_LEVEL '=' T_L_TRACE ';'
{
  if (ypass == 2)
    set_log_level(L_TRACE);
} | LOG_LEVEL '=' T_L_INFO ';'
{
  if (ypass == 2)
    set_log_level(L_INFO);
} | LOG_LEVEL '=' T_L_DEBUG ';'
{
  if (ypass == 2)
    set_log_level(L_DEBUG);
};

logging_use_logging: USE_LOGGING '=' TBOOL ';'
{
  if (ypass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
};

/***************************************************************************
 * section oper
 ***************************************************************************/
oper_entry: OPERATOR 
{
  if (ypass == 2)
  {
    yy_conf = make_conf_item(OPER_TYPE);
    yy_aconf = map_to_conf(yy_conf);
    SetConfEncrypted(yy_aconf); /* Yes, the default is encrypted */
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
} oper_name_b '{' oper_items '}' ';'
{
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;
    dlink_node *ptr;
    dlink_node *next_ptr;

    conf_add_class_to_conf(yy_conf, class_name);

    /* Now, make sure there is a copy of the "base" given oper
     * block in each of the collected copies
     */

    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;
      yy_tmp = ptr->data;

      new_conf = make_conf_item(OPER_TYPE);
      new_aconf = (struct AccessItem *)map_to_conf(new_conf);

      new_aconf->flags = yy_aconf->flags;

      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      if (yy_tmp->user != NULL)
	DupString(new_aconf->user, yy_tmp->user);
      else
	DupString(new_aconf->user, "*");
      if (yy_tmp->host != NULL)
	DupString(new_aconf->host, yy_tmp->host);
      else
	DupString(new_aconf->host, "*");
      conf_add_class_to_conf(new_conf, class_name);
      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);

      new_aconf->port = yy_aconf->port;
#ifdef HAVE_LIBCRYPTO
      if (yy_aconf->rsa_public_key_file != NULL)
      {
        BIO *file;

        DupString(new_aconf->rsa_public_key_file,
		  yy_aconf->rsa_public_key_file);

        file = BIO_new_file(yy_aconf->rsa_public_key_file, "r");
        new_aconf->rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file, 
							   NULL, 0, NULL);
        BIO_set_close(file, BIO_CLOSE);
        BIO_free(file);
      }
#endif

#ifdef HAVE_LIBCRYPTO
      if (yy_tmp->name && (yy_tmp->passwd || yy_aconf->rsa_public_key)
	  && yy_tmp->host)
#else
      if (yy_tmp->name && yy_tmp->passwd && yy_tmp->host)
#endif
      {
        conf_add_class_to_conf(new_conf, class_name);
	if (yy_tmp->name != NULL)
	  DupString(new_conf->name, yy_tmp->name);
      }

      dlinkDelete(&yy_tmp->node, &col_conf_list);
      free_collect_item(yy_tmp);
    }

    yy_conf = NULL;
    yy_aconf = NULL;


    MyFree(class_name);
    class_name = NULL;
  }
}; 

oper_name_b: | oper_name_t;
oper_items:     oper_items oper_item | oper_item;
oper_item:      oper_name | oper_user | oper_password | oper_hidden_admin |
                oper_hidden_oper | oper_umodes |
		oper_class | oper_global_kill | oper_remote |
                oper_kline | oper_xline | oper_unkline |
		oper_gline | oper_nick_changes | oper_remoteban |
                oper_die | oper_rehash | oper_admin | oper_operwall |
		oper_encrypted | oper_rsa_public_key_file |
                oper_flags | error ';' ;

oper_name: NAME '=' QSTRING ';'
{
  if (ypass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
};

oper_name_t: QSTRING
{
  if (ypass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
};

oper_user: USER '=' QSTRING ';'
{
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    if (yy_aconf->user == NULL)
    {
      split_nuh(yylval.string, NULL, &yy_aconf->user, &yy_aconf->host);
    }
    else
    {
      yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
      split_nuh(yylval.string, NULL, &yy_tmp->user, &yy_tmp->host);
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
};

oper_password: PASSWORD '=' QSTRING ';'
{
  if (ypass == 2)
  {
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
};

oper_encrypted: ENCRYPTED '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
};

oper_rsa_public_key_file: RSA_PUBLIC_KEY_FILE '=' QSTRING ';'
{
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    BIO *file;

    if (yy_aconf->rsa_public_key != NULL)
    {
      RSA_free(yy_aconf->rsa_public_key);
      yy_aconf->rsa_public_key = NULL;
    }

    if (yy_aconf->rsa_public_key_file != NULL)
    {
      MyFree(yy_aconf->rsa_public_key_file);
      yy_aconf->rsa_public_key_file = NULL;
    }

    DupString(yy_aconf->rsa_public_key_file, yylval.string);
    file = BIO_new_file(yylval.string, "r");

    if (file == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- file doesn't exist");
      break;
    }

    yy_aconf->rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);

    if (yy_aconf->rsa_public_key == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");
      break;
    }

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);
  }
#endif /* HAVE_LIBCRYPTO */
};

oper_class: CLASS '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
};

oper_umodes: T_UMODES
{
  if (ypass == 2)
    yy_aconf->modes = 0;
} '='  oper_umodes_items ';' ;

oper_umodes_items: oper_umodes_items ',' oper_umodes_item | oper_umodes_item;
oper_umodes_item:  T_BOTS
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_BOTS;
} | T_CCONN
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CCONN;
} | T_DEAF
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEAF;
} | T_DEBUG
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
} | T_FULL
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_FULL;
} | T_SKILL
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SKILL;
} | T_NCHANGE
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
} | T_REJ
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_REJ;
} | T_UNAUTH
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
} | T_SPY
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SPY;
} | T_EXTERNAL
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
} | T_OPERWALL
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
} | T_SERVNOTICE
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
} | T_INVISIBLE
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
} | T_WALLOP
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
} | T_SOFTCALLERID
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
} | T_CALLERID
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
} | T_LOCOPS
{
  if (ypass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
};

oper_global_kill: GLOBAL_KILL '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
    else
      yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
  }
};

oper_remote: REMOTE '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REMOTE;
    else
      yy_aconf->port &= ~OPER_FLAG_REMOTE; 
  }
};

oper_remoteban: REMOTEBAN '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REMOTEBAN;
    else
      yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
  }
};

oper_kline: KLINE '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_K;
    else
      yy_aconf->port &= ~OPER_FLAG_K;
  }
};

oper_xline: XLINE '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_X;
    else
      yy_aconf->port &= ~OPER_FLAG_X;
  }
};

oper_unkline: UNKLINE '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_UNKLINE;
    else
      yy_aconf->port &= ~OPER_FLAG_UNKLINE; 
  }
};

oper_gline: GLINE '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_GLINE;
    else
      yy_aconf->port &= ~OPER_FLAG_GLINE;
  }
};

oper_nick_changes: NICK_CHANGES '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_N;
    else
      yy_aconf->port &= ~OPER_FLAG_N;
  }
};

oper_die: DIE '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_DIE;
    else
      yy_aconf->port &= ~OPER_FLAG_DIE;
  }
};

oper_rehash: REHASH '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REHASH;
    else
      yy_aconf->port &= ~OPER_FLAG_REHASH;
  }
};

oper_admin: ADMIN '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_ADMIN;
    else
      yy_aconf->port &= ~OPER_FLAG_ADMIN;
  }
};

oper_hidden_admin: HIDDEN_ADMIN '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
    else
      yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
  }
};

oper_hidden_oper: HIDDEN_OPER '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
    else
      yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
  }
};

oper_operwall: T_OPERWALL '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_OPERWALL;
    else
      yy_aconf->port &= ~OPER_FLAG_OPERWALL;
  }
};

oper_flags: IRCD_FLAGS
{
} '='  oper_flags_items ';';

oper_flags_items: oper_flags_items ',' oper_flags_item | oper_flags_item;
oper_flags_item: NOT { not_atom = 1; } oper_flags_item_atom
		| { not_atom = 0; } oper_flags_item_atom;

oper_flags_item_atom: GLOBAL_KILL
{
  if (ypass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
} | REMOTE
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
} | KLINE
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
} | UNKLINE
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
} | XLINE
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
} | GLINE
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
} | DIE
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
} | REHASH
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
} | ADMIN
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
} | HIDDEN_ADMIN
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
} | NICK_CHANGES
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
} | T_OPERWALL
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
} | OPER_SPY_T
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
} | HIDDEN_OPER
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
} | REMOTEBAN
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
} | ENCRYPTED
{
  if (ypass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
};


/***************************************************************************
 *  section class
 ***************************************************************************/
class_entry: CLASS
{
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = (struct ClassItem *)map_to_conf(yy_conf);
  }
} class_name_b '{' class_items '}' ';'
{
  if (ypass == 1)
  {
    struct ConfItem *cconf;
    struct ClassItem *class = NULL;

    if (yy_class_name == NULL)
    {
      delete_conf_item(yy_conf);
    }
    else
    {
      cconf = find_exact_name_conf(CLASS_TYPE, yy_class_name, NULL, NULL);

      if (cconf != NULL)		/* The class existed already */
      {
        rebuild_cidr_class(cconf, yy_class);
        class = (struct ClassItem *) map_to_conf(cconf);
        *class = *yy_class;
        delete_conf_item(yy_conf);

        MyFree(cconf->name);            /* Allows case change of class name */
        cconf->name = yy_class_name;
      }
      else	/* Brand new class */
      {
        MyFree(yy_conf->name);          /* just in case it was allocated */
        yy_conf->name = yy_class_name;
      }
    }
    yy_class_name = NULL;
  }
};

class_name_b: | class_name_t;

class_items:    class_items class_item | class_item;
class_item:     class_name |
		class_cidr_bitlen_ipv4 | class_cidr_bitlen_ipv6 |
                class_ping_time |
		class_ping_warning |
		class_number_per_cidr |
                class_number_per_ip |
                class_connectfreq |
                class_max_number |
		class_max_global |
		class_max_local |
		class_max_ident |
                class_sendq |
		error ';' ;

class_name: NAME '=' QSTRING ';' 
{
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
};

class_name_t: QSTRING
{
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
};

class_ping_time: PING_TIME '=' timespec ';'
{
  if (ypass == 1)
    PingFreq(yy_class) = $3;
};

class_ping_warning: PING_WARNING '=' timespec ';'
{
  if (ypass == 1)
    PingWarning(yy_class) = $3;
};

class_number_per_ip: NUMBER_PER_IP '=' NUMBER ';'
{
  if (ypass == 1)
    MaxPerIp(yy_class) = $3;
};

class_connectfreq: CONNECTFREQ '=' timespec ';'
{
  if (ypass == 1)
    ConFreq(yy_class) = $3;
};

class_max_number: MAX_NUMBER '=' NUMBER ';'
{
  if (ypass == 1)
    MaxTotal(yy_class) = $3;
};

class_max_global: MAX_GLOBAL '=' NUMBER ';'
{
  if (ypass == 1)
    MaxGlobal(yy_class) = $3;
};

class_max_local: MAX_LOCAL '=' NUMBER ';'
{
  if (ypass == 1)
    MaxLocal(yy_class) = $3;
};

class_max_ident: MAX_IDENT '=' NUMBER ';'
{
  if (ypass == 1)
    MaxIdent(yy_class) = $3;
};

class_sendq: SENDQ '=' sizespec ';'
{
  if (ypass == 1)
    MaxSendq(yy_class) = $3;
};

class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'
{
  if (ypass == 1)
    CidrBitlenIPV4(yy_class) = $3;
};

class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'
{
  if (ypass == 1)
    CidrBitlenIPV6(yy_class) = $3;
};

class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'
{
  if (ypass == 1)
    NumberPerCidr(yy_class) = $3;
};

/***************************************************************************
 *  section listen
 ***************************************************************************/
listen_entry: LISTEN
{
  if (ypass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
} '{' listen_items '}' ';'
{
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
};

listen_flags: IRCD_FLAGS
{
} '='  listen_flags_items ';';

listen_flags_items: listen_flags_items ',' listen_flags_item | listen_flags_item;
listen_flags_item: T_SSL
{
  if (ypass == 2)
    listener_flags |= LISTENER_SSL;
} | HIDDEN
{
  if (ypass == 2)
    listener_flags |= LISTENER_HIDDEN;
};

listen_items:   listen_items listen_item | listen_item;
listen_item:    listen_port | listen_flags | listen_address | listen_host | error ';' ;

listen_port: PORT '=' port_items ';' ;

port_items: port_items ',' port_item | port_item;

port_item: NUMBER
{
  if (ypass == 2)
  {
    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }
    add_listener($1, listener_address, listener_flags);
    listener_flags = 0;
  }
} | NUMBER TWODOTS NUMBER
{
  if (ypass == 2)
  {
    int i;

    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }

    for (i = $1; i <= $3; ++i)
      add_listener(i, listener_address, listener_flags);

    listener_flags = 0;
  }
};

listen_address: IP '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
};

listen_host: HOST '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
};

/***************************************************************************
 *  section auth
 ***************************************************************************/
auth_entry: IRCD_AUTH
{
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLIENT_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
} '{' auth_items '}' ';'
{
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    dlink_node *ptr = NULL, *next_ptr = NULL;

    if (yy_aconf->user && yy_aconf->host)
    {
      conf_add_class_to_conf(yy_conf, class_name);
      add_conf_by_address(CONF_CLIENT, yy_aconf);
    }
    else
      delete_conf_item(yy_conf);

    /* copy over settings from first struct */
    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;

      new_conf = make_conf_item(CLIENT_TYPE);
      new_aconf = map_to_conf(new_conf);

      yy_tmp = ptr->data;

      assert(yy_tmp->user && yy_tmp->host);

      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);
      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);

      new_aconf->flags = yy_aconf->flags;
      new_aconf->port  = yy_aconf->port;

      DupString(new_aconf->user, yy_tmp->user);
      collapse(new_aconf->user);

      DupString(new_aconf->host, yy_tmp->host);
      collapse(new_aconf->host);

      conf_add_class_to_conf(new_conf, class_name);
      add_conf_by_address(CONF_CLIENT, new_aconf);
      dlinkDelete(&yy_tmp->node, &col_conf_list);
      free_collect_item(yy_tmp);
    }

    MyFree(class_name);
    class_name = NULL;
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}; 

auth_items:     auth_items auth_item | auth_item;
auth_item:      auth_user | auth_passwd | auth_class | auth_flags |
                auth_kline_exempt | auth_need_ident |
                auth_exceed_limit | auth_no_tilde | auth_gline_exempt |
		auth_spoof | auth_spoof_notice |
                auth_redir_serv | auth_redir_port | auth_can_flood |
                auth_need_password | auth_encrypted | error ';' ;

auth_user: USER '=' QSTRING ';'
{
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    if (yy_aconf->user == NULL)
      split_nuh(yylval.string, NULL, &yy_aconf->user, &yy_aconf->host);
    else
    {
      yy_tmp = MyMalloc(sizeof(struct CollectItem));
      split_nuh(yylval.string, NULL, &yy_tmp->user, &yy_tmp->host);
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
};

/* XXX - IP/IPV6 tags don't exist anymore - put IP/IPV6 into user. */

auth_passwd: PASSWORD '=' QSTRING ';'
{
  if (ypass == 2)
  {
    /* be paranoid */
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
};

auth_spoof_notice: SPOOF_NOTICE '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
  }
};

auth_class: CLASS '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
};

auth_encrypted: ENCRYPTED '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
};

auth_flags: IRCD_FLAGS
{
} '='  auth_flags_items ';';

auth_flags_items: auth_flags_items ',' auth_flags_item | auth_flags_item;
auth_flags_item: NOT { not_atom = 1; } auth_flags_item_atom
		| { not_atom = 0; } auth_flags_item_atom;

auth_flags_item_atom: SPOOF_NOTICE
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

} | EXCEED_LIMIT
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
} | KLINE_EXEMPT
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
} | NEED_IDENT
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
} | CAN_FLOOD
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
} | CAN_IDLE
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
} | NO_TILDE
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
} | GLINE_EXEMPT
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
} | RESV_EXEMPT
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
} | NEED_PASSWORD
{
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
};

auth_kline_exempt: KLINE_EXEMPT '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
  }
};

auth_need_ident: NEED_IDENT '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
  }
};

auth_exceed_limit: EXCEED_LIMIT '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
  }
};

auth_can_flood: CAN_FLOOD '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
  }
};

auth_no_tilde: NO_TILDE '=' TBOOL ';' 
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
  }
};

auth_gline_exempt: GLINE_EXEMPT '=' TBOOL ';' 
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
  }
};

/* XXX - need check for illegal hostnames here */
auth_spoof: SPOOF '=' QSTRING ';' 
{
  if (ypass == 2)
  {
    MyFree(yy_conf->name);

    if (strlen(yylval.string) < HOSTLEN)
    {    
      DupString(yy_conf->name, yylval.string);
      yy_aconf->flags |= CONF_FLAGS_SPOOF_IP;
    }
    else
    {
      ilog(L_ERROR, "Spoofs must be less than %d..ignoring it", HOSTLEN);
      yy_conf->name = NULL;
    }
  }
};

auth_redir_serv: REDIRSERV '=' QSTRING ';'
{
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
};

auth_redir_port: REDIRPORT '=' NUMBER ';'
{
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = $3;
  }
};

auth_need_password: NEED_PASSWORD '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
  }
};


/***************************************************************************
 *  section resv
 ***************************************************************************/
resv_entry: RESV
{
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
} '{' resv_items '}' ';'
{
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
};

resv_items:	resv_items resv_item | resv_item;
resv_item:	resv_creason | resv_channel | resv_nick | error ';' ;

resv_creason: REASON '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
};

resv_channel: CHANNEL '=' QSTRING ';'
{
  if (ypass == 2)
  {
    if (IsChanPrefix(*yylval.string))
    {
      char def_reason[] = "No reason";

      create_channel_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
    }
  }
  /* ignore it for now.. but we really should make a warning if
   * its an erroneous name --fl_ */
};

resv_nick: NICK '=' QSTRING ';'
{
  if (ypass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
};

/***************************************************************************
 *  section shared, for sharing remote klines etc.
 ***************************************************************************/
shared_entry: T_SHARED
{
  if (ypass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
} '{' shared_items '}' ';'
{
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
};

shared_items: shared_items shared_item | shared_item;
shared_item:  shared_name | shared_user | shared_type | error ';' ;

shared_name: NAME '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
};

shared_user: USER '=' QSTRING ';'
{
  if (ypass == 2)
  {
    split_nuh(yylval.string, NULL, &yy_match_item->user, &yy_match_item->host);
  }
};

shared_type: TYPE
{
  if (ypass == 2)
    yy_match_item->action = 0;
} '=' shared_types ';' ;

shared_types: shared_types ',' shared_type_item | shared_type_item;
shared_type_item: KLINE
{
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
} | TKLINE
{
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
} | UNKLINE
{
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
} | XLINE
{
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
} | TXLINE
{
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
} | T_UNXLINE
{
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
} | RESV
{
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
} | TRESV
{
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
} | T_UNRESV
{
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
} | T_LOCOPS
{
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
} | T_ALL
{
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
};

/***************************************************************************
 *  section cluster
 ***************************************************************************/
cluster_entry: T_CLUSTER
{
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
} '{' cluster_items '}' ';'
{
  if (ypass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
};

cluster_items:	cluster_items cluster_item | cluster_item;
cluster_item:	cluster_name | cluster_type | error ';' ;

cluster_name: NAME '=' QSTRING ';'
{
  if (ypass == 2)
    DupString(yy_conf->name, yylval.string);
};

cluster_type: TYPE
{
  if (ypass == 2)
    yy_conf->flags = 0;
} '=' cluster_types ';' ;

cluster_types:	cluster_types ',' cluster_type_item | cluster_type_item;
cluster_type_item: KLINE
{
  if (ypass == 2)
    yy_conf->flags |= SHARED_KLINE;
} | TKLINE
{
  if (ypass == 2)
    yy_conf->flags |= SHARED_TKLINE;
} | UNKLINE
{
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
} | XLINE
{
  if (ypass == 2)
    yy_conf->flags |= SHARED_XLINE;
} | TXLINE
{
  if (ypass == 2)
    yy_conf->flags |= SHARED_TXLINE;
} | T_UNXLINE
{
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
} | RESV
{
  if (ypass == 2)
    yy_conf->flags |= SHARED_RESV;
} | TRESV
{
  if (ypass == 2)
    yy_conf->flags |= SHARED_TRESV;
} | T_UNRESV
{
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNRESV;
} | T_LOCOPS
{
  if (ypass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
} | T_ALL
{
  if (ypass == 2)
    yy_conf->flags = SHARED_ALL;
};

/***************************************************************************
 *  section connect
 ***************************************************************************/
connect_entry: CONNECT   
{
  if (ypass == 2)
  {
    yy_conf = make_conf_item(SERVER_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
    yy_aconf->passwd = NULL;
    /* defaults */
    yy_aconf->port = PORTNUM;

    if (ConfigFileEntry.burst_away)
      yy_aconf->flags = CONF_FLAGS_BURST_AWAY;
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
} connect_name_b '{' connect_items '}' ';'
{
  if (ypass == 2)
  {
    struct CollectItem *yy_hconf=NULL;
    struct CollectItem *yy_lconf=NULL;
    dlink_node *ptr;
    dlink_node *next_ptr;
#ifdef HAVE_LIBCRYPTO
    if (yy_aconf->host &&
	((yy_aconf->passwd && yy_aconf->spasswd) ||
	 (yy_aconf->rsa_public_key && IsConfCryptLink(yy_aconf))))
#else /* !HAVE_LIBCRYPTO */
      if (yy_aconf->host && !IsConfCryptLink(yy_aconf) && 
	  yy_aconf->passwd && yy_aconf->spasswd)
#endif /* !HAVE_LIBCRYPTO */
	{
	  if (conf_add_server(yy_conf, scount, class_name) >= 0)
	  {
	    ++scount;
	  }
	  else
	  {
	    delete_conf_item(yy_conf);
	    yy_conf = NULL;
	    yy_aconf = NULL;
	  }
	}
	else
	{
	  /* Even if yy_conf ->name is NULL
	   * should still unhook any hub/leaf confs still pending
	   */
	  unhook_hub_leaf_confs();

	  if (yy_conf->name != NULL)
	  {
#ifndef HAVE_LIBCRYPTO
	    if (IsConfCryptLink(yy_aconf))
	      yyerror("Ignoring connect block -- no OpenSSL support");
#else
	    if (IsConfCryptLink(yy_aconf) && !yy_aconf->rsa_public_key)
	      yyerror("Ignoring connect block -- missing key");
#endif
	    if (yy_aconf->host == NULL)
	      yyerror("Ignoring connect block -- missing host");
	    else if (!IsConfCryptLink(yy_aconf) && 
		    (!yy_aconf->passwd || !yy_aconf->spasswd))
              yyerror("Ignoring connect block -- missing password");
	  }


          /* XXX
           * This fixes a try_connections() core (caused by invalid class_ptr
           * pointers) reported by metalrock. That's an ugly fix, but there
           * is currently no better way. The entire config subsystem needs an
           * rewrite ASAP. make_conf_item() shouldn't really add things onto
           * a doubly linked list immediately without any sanity checks!  -Michael
           */
          delete_conf_item(yy_conf);

          yy_aconf = NULL;
	  yy_conf = NULL;
	}

      /*
       * yy_conf is still pointing at the server that is having
       * a connect block built for it. This means, y_aconf->name 
       * points to the actual irc name this server will be known as.
       * Now this new server has a set or even just one hub_mask (or leaf_mask)
       * given in the link list at yy_hconf. Fill in the HUB confs
       * from this link list now.
       */        
      DLINK_FOREACH_SAFE(ptr, next_ptr, hub_conf_list.head)
      {
	struct ConfItem *new_hub_conf;
	struct MatchItem *match_item;

	yy_hconf = ptr->data;

	/* yy_conf == NULL is a fatal error for this connect block! */
	if ((yy_conf != NULL) && (yy_conf->name != NULL))
	{
	  new_hub_conf = make_conf_item(HUB_TYPE);
	  match_item = (struct MatchItem *)map_to_conf(new_hub_conf);
	  DupString(new_hub_conf->name, yy_conf->name);
	  if (yy_hconf->user != NULL)
	    DupString(match_item->user, yy_hconf->user);
	  else
	    DupString(match_item->user, "*");
	  if (yy_hconf->host != NULL)
	    DupString(match_item->host, yy_hconf->host);
	  else
	    DupString(match_item->host, "*");
	}
	dlinkDelete(&yy_hconf->node, &hub_conf_list);
	free_collect_item(yy_hconf);
      }

      /* Ditto for the LEAF confs */

      DLINK_FOREACH_SAFE(ptr, next_ptr, leaf_conf_list.head)
      {
	struct ConfItem *new_leaf_conf;
	struct MatchItem *match_item;

	yy_lconf = ptr->data;

	if ((yy_conf != NULL) && (yy_conf->name != NULL))
	{
	  new_leaf_conf = make_conf_item(LEAF_TYPE);
	  match_item = (struct MatchItem *)map_to_conf(new_leaf_conf);
	  DupString(new_leaf_conf->name, yy_conf->name);
	  if (yy_lconf->user != NULL)
	    DupString(match_item->user, yy_lconf->user);
	  else
	    DupString(match_item->user, "*");
	  if (yy_lconf->host != NULL)
	    DupString(match_item->host, yy_lconf->host);
	  else
	    DupString(match_item->host, "*");
	}
	dlinkDelete(&yy_lconf->node, &leaf_conf_list);
	free_collect_item(yy_lconf);
      }
      MyFree(class_name);
      class_name = NULL;
      yy_conf = NULL;
      yy_aconf = NULL;
  }
};

connect_name_b: | connect_name_t;
connect_items:  connect_items connect_item | connect_item;
connect_item:   connect_name | connect_host | connect_vhost |
		connect_send_password | connect_accept_password |
		connect_aftype | connect_port |
 		connect_fakename | connect_flags | connect_hub_mask | 
		connect_leaf_mask | connect_class | connect_auto |
		connect_encrypted | connect_compressed | connect_cryptlink |
		connect_rsa_public_key_file | connect_cipher_preference |
                error ';' ;

connect_name: NAME '=' QSTRING ';'
{
  if (ypass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
};

connect_name_t: QSTRING
{
  if (ypass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
};

connect_host: HOST '=' QSTRING ';' 
{
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
};

connect_vhost: VHOST '=' QSTRING ';' 
{
  if (ypass == 2)
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&yy_aconf->my_ipnum, res->ai_addr, res->ai_addrlen);
      yy_aconf->my_ipnum.ss.ss_family = res->ai_family;
      yy_aconf->my_ipnum.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);
    }
  }
};
 
connect_send_password: SEND_PASSWORD '=' QSTRING ';'
{
  if (ypass == 2)
  {
    if ($3[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr($3, ' ') != NULL)
      yyerror("Server passwords cannot contain spaces");
    else {
      if (yy_aconf->spasswd != NULL)
        memset(yy_aconf->spasswd, 0, strlen(yy_aconf->spasswd));

      MyFree(yy_aconf->spasswd);
      DupString(yy_aconf->spasswd, yylval.string);
    }
  }
};

connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'
{
  if (ypass == 2)
  {
    if ($3[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr($3, ' ') != NULL)
      yyerror("Server passwords cannot contain spaces");
    else {
      if (yy_aconf->passwd != NULL)
        memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

      MyFree(yy_aconf->passwd);
      DupString(yy_aconf->passwd, yylval.string);
    }
  }
};

connect_port: PORT '=' NUMBER ';'
{
  if (ypass == 2)
    yy_aconf->port = $3;
};

connect_aftype: AFTYPE '=' T_IPV4 ';'
{
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
} | AFTYPE '=' T_IPV6 ';'
{
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
};

connect_fakename: FAKENAME '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
};

connect_flags: IRCD_FLAGS
{
} '='  connect_flags_items ';';

connect_flags_items: connect_flags_items ',' connect_flags_item | connect_flags_item;
connect_flags_item: NOT  { not_atom = 1; } connect_flags_item_atom
			|  { not_atom = 0; } connect_flags_item_atom;

connect_flags_item_atom: LAZYLINK
{
  if (ypass == 2)
  {
    if (not_atom)ClearConfLazyLink(yy_aconf);
    else SetConfLazyLink(yy_aconf);
  }
} | COMPRESSED
{
  if (ypass == 2)
#ifndef HAVE_LIBZ
    yyerror("Ignoring flags = compressed; -- no zlib support");
#else
 {
   if (not_atom)ClearConfCompressed(yy_aconf);
   else SetConfCompressed(yy_aconf);
 }
#endif
} | CRYPTLINK
{
  if (ypass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
} | AUTOCONN
{
  if (ypass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
} | BURST_AWAY
{
  if (ypass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
} | TOPICBURST
{
  if (ypass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
;

connect_rsa_public_key_file: RSA_PUBLIC_KEY_FILE '=' QSTRING ';'
{
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    BIO *file;

    if (yy_aconf->rsa_public_key != NULL)
    {
      RSA_free(yy_aconf->rsa_public_key);
      yy_aconf->rsa_public_key = NULL;
    }

    if (yy_aconf->rsa_public_key_file != NULL)
    {
      MyFree(yy_aconf->rsa_public_key_file);
      yy_aconf->rsa_public_key_file = NULL;
    }

    DupString(yy_aconf->rsa_public_key_file, yylval.string);

    if ((file = BIO_new_file(yylval.string, "r")) == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- file doesn't exist");
      break;
    }

    yy_aconf->rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);

    if (yy_aconf->rsa_public_key == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");
      break;
    }
      
    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);
  }
#endif /* HAVE_LIBCRYPTO */
};

connect_encrypted: ENCRYPTED '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ENCRYPTED;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ENCRYPTED;
  }
};

connect_cryptlink: CRYPTLINK '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_CRYPTLINK;
    else
      yy_aconf->flags &= ~CONF_FLAGS_CRYPTLINK;
  }
};

connect_compressed: COMPRESSED '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
#ifndef HAVE_LIBZ
      yyerror("Ignoring compressed=yes; -- no zlib support");
#else
      yy_aconf->flags |= CONF_FLAGS_COMPRESSED;
#endif
    else
      yy_aconf->flags &= ~CONF_FLAGS_COMPRESSED;
  }
};

connect_auto: AUTOCONN '=' TBOOL ';'
{
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ALLOW_AUTO_CONN;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ALLOW_AUTO_CONN;
  }
};

connect_hub_mask: HUB_MASK '=' QSTRING ';' 
{
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &hub_conf_list);
  }
};

connect_leaf_mask: LEAF_MASK '=' QSTRING ';' 
{
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &leaf_conf_list);
  }
};

connect_class: CLASS '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
};

connect_cipher_preference: CIPHER_PREFERENCE '=' QSTRING ';'
{
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    struct EncCapability *ecap;
    const char *cipher_name;
    int found = 0;

    yy_aconf->cipher_preference = NULL;
    cipher_name = yylval.string;

    for (ecap = CipherTable; ecap->name; ecap++)
    {
      if ((irccmp(ecap->name, cipher_name) == 0) &&
          (ecap->cap & CAP_ENC_MASK))
      {
        yy_aconf->cipher_preference = ecap;
        found = 1;
        break;
      }
    }

    if (!found)
      yyerror("Invalid cipher");
  }
#else
  if (ypass == 2)
    yyerror("Ignoring cipher_preference -- no OpenSSL support");
#endif
};

/***************************************************************************
 *  section kill
 ***************************************************************************/
kill_entry: KILL
{
  if (ypass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
} '{' kill_items '}' ';'
{
  if (ypass == 2)
  {
    if (userbuf[0] && hostbuf[0])
    {
      if (regex_ban)
      {
        pcre *exp_user = NULL;
        pcre *exp_host = NULL;
        const char *errptr = NULL;

        if (!(exp_user = ircd_pcre_compile(userbuf, &errptr)) ||
            !(exp_host = ircd_pcre_compile(hostbuf, &errptr)))
        {
          ilog(L_ERROR, "Failed to add regular expression based K-Line: %s", errptr);
          break;
        }

        yy_conf = make_conf_item(RKLINE_TYPE);
        yy_aconf->regexuser = exp_user;
        yy_aconf->regexhost = exp_host;

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
      }
      else
      {
        yy_conf = make_conf_item(KLINE_TYPE);
        yy_aconf = map_to_conf(yy_conf);

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
        add_conf_by_address(CONF_KILL, yy_aconf);
      }
    }
    else
      delete_conf_item(yy_conf);

    yy_conf = NULL;
    yy_aconf = NULL;
  }
}; 

kill_type: TYPE
{
} '='  kill_type_items ';';

kill_type_items: kill_type_items ',' kill_type_item | kill_type_item;
kill_type_item: REGEX_T
{
  if (ypass == 2)
    regex_ban = 1;
};

kill_items:     kill_items kill_item | kill_item;
kill_item:      kill_user | kill_reason | kill_type | error;

kill_user: USER '=' QSTRING ';'
{
  if (ypass == 2)
  {
    char *user = NULL, *host = NULL;

    split_nuh(yylval.string, NULL, &user, &host);

    strlcpy(userbuf, user, sizeof(userbuf));
    strlcpy(hostbuf, host, sizeof(hostbuf));

    MyFree(user);
    MyFree(host);
  }
};

kill_reason: REASON '=' QSTRING ';' 
{
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
};

/***************************************************************************
 *  section deny
 ***************************************************************************/
deny_entry: DENY 
{
  if (ypass == 2)
  {
    yy_conf = make_conf_item(DLINE_TYPE);
    yy_aconf = map_to_conf(yy_conf);
    /* default reason */
    DupString(yy_aconf->reason, "No reason");
  }
} '{' deny_items '}' ';'
{
  if (ypass == 2)
  {
    if (yy_aconf->host && parse_netmask(yy_aconf->host, NULL, NULL) != HM_HOST)
      add_conf_by_address(CONF_DLINE, yy_aconf);
    else
      delete_conf_item(yy_conf);
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}; 

deny_items:     deny_items deny_item | deny_item;
deny_item:      deny_ip | deny_reason | error;

deny_ip: IP '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
};

deny_reason: REASON '=' QSTRING ';' 
{
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
};

/***************************************************************************
 *  section exempt
 ***************************************************************************/
exempt_entry: EXEMPT '{' exempt_items '}' ';';

exempt_items:     exempt_items exempt_item | exempt_item;
exempt_item:      exempt_ip | error;

exempt_ip: IP '=' QSTRING ';'
{
  if (ypass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      yy_conf = make_conf_item(EXEMPTDLINE_TYPE);
      yy_aconf = map_to_conf(yy_conf);
      DupString(yy_aconf->host, yylval.string);

      add_conf_by_address(CONF_EXEMPTDLINE, yy_aconf);

      yy_conf = NULL;
      yy_aconf = NULL;
    }
  }
};

/***************************************************************************
 *  section gecos
 ***************************************************************************/
gecos_entry: GECOS
{
  if (ypass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
} '{' gecos_items '}' ';'
{
  if (ypass == 2)
  {
    if (gecos_name[0])
    {
      if (regex_ban)
      {
        pcre *exp_p = NULL;
        const char *errptr = NULL;

        if (!(exp_p = ircd_pcre_compile(gecos_name, &errptr)))
        {
          ilog(L_ERROR, "Failed to add regular expression based X-Line: %s", errptr);
          break;
        }

        yy_conf = make_conf_item(RXLINE_TYPE);
        yy_conf->regexpname = exp_p;
      }
      else
        yy_conf = make_conf_item(XLINE_TYPE);

      yy_match_item = map_to_conf(yy_conf);
      DupString(yy_conf->name, gecos_name);

      if (reasonbuf[0])
        DupString(yy_match_item->reason, reasonbuf);
      else
        DupString(yy_match_item->reason, "No reason");
    }
  }
};

gecos_flags: TYPE
{
} '='  gecos_flags_items ';';

gecos_flags_items: gecos_flags_items ',' gecos_flags_item | gecos_flags_item;
gecos_flags_item: REGEX_T
{
  if (ypass == 2)
    regex_ban = 1;
};

gecos_items: gecos_items gecos_item | gecos_item;
gecos_item:  gecos_name | gecos_reason | gecos_flags | error;

gecos_name: NAME '=' QSTRING ';' 
{
  if (ypass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
};

gecos_reason: REASON '=' QSTRING ';' 
{
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
};

/***************************************************************************
 *  section general
 ***************************************************************************/
general_entry: GENERAL
  '{' general_items '}' ';';

general_items:      general_items general_item | general_item;
general_item:       general_hide_spoof_ips | general_ignore_bogus_ts |
		    general_failed_oper_notice | general_anti_nick_flood |
		    general_max_nick_time | general_max_nick_changes |
		    general_max_accept | general_anti_spam_exit_message_time |
                    general_ts_warn_delta | general_ts_max_delta |
                    general_kill_chase_time_limit | general_kline_with_reason |
                    general_kline_reason | general_invisible_on_connect |
                    general_warn_no_nline | general_dots_in_ident |
                    general_stats_o_oper_only | general_stats_k_oper_only |
                    general_pace_wait | general_stats_i_oper_only |
                    general_pace_wait_simple | general_stats_P_oper_only |
                    general_short_motd | general_no_oper_flood |
                    general_true_no_oper_flood | general_oper_pass_resv |
                    general_idletime | general_message_locale |
                    general_oper_only_umodes | general_max_targets |
                    general_use_egd | general_egdpool_path |
                    general_oper_umodes | general_caller_id_wait |
                    general_opers_bypass_callerid | general_default_floodcount |
                    general_min_nonwildcard | general_min_nonwildcard_simple |
                    general_servlink_path | general_disable_remote_commands |
                    general_default_cipher_preference |
                    general_compression_level | general_client_flood |
                    general_throttle_time | general_havent_read_conf |
                    general_dot_in_ip6_addr | general_ping_cookie |
                    general_disable_auth | general_burst_away |
		    general_tkline_expire_notices | general_gline_min_cidr |
                    general_gline_min_cidr6 | general_use_whois_actually |
		    general_reject_hold_time |
		    error;



general_gline_min_cidr: GLINE_MIN_CIDR '=' NUMBER ';'
{
  ConfigFileEntry.gline_min_cidr = $3;
};

general_gline_min_cidr6: GLINE_MIN_CIDR6 '=' NUMBER ';'
{
  ConfigFileEntry.gline_min_cidr6 = $3;
};

general_burst_away: BURST_AWAY '=' TBOOL ';'
{
  ConfigFileEntry.burst_away = yylval.number;
};

general_use_whois_actually: USE_WHOIS_ACTUALLY '=' TBOOL ';'
{
  ConfigFileEntry.use_whois_actually = yylval.number;
};

general_reject_hold_time: TREJECT_HOLD_TIME '=' timespec ';'
{
  GlobalSetOptions.rejecttime = yylval.number;
};

general_tkline_expire_notices: TKLINE_EXPIRE_NOTICES '=' TBOOL ';'
{
  ConfigFileEntry.tkline_expire_notices = yylval.number;
};

general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' NUMBER ';'
{
  ConfigFileEntry.kill_chase_time_limit = $3;
};

general_hide_spoof_ips: HIDE_SPOOF_IPS '=' TBOOL ';'
{
  ConfigFileEntry.hide_spoof_ips = yylval.number;
};

general_ignore_bogus_ts: IGNORE_BOGUS_TS '=' TBOOL ';'
{
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
};

general_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'
{
  ConfigFileEntry.disable_remote = yylval.number;
};

general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'
{
  ConfigFileEntry.failed_oper_notice = yylval.number;
};

general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'
{
  ConfigFileEntry.anti_nick_flood = yylval.number;
};

general_max_nick_time: MAX_NICK_TIME '=' timespec ';'
{
  ConfigFileEntry.max_nick_time = $3; 
};

general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'
{
  ConfigFileEntry.max_nick_changes = $3;
};

general_max_accept: MAX_ACCEPT '=' NUMBER ';'
{
  ConfigFileEntry.max_accept = $3;
};

general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'
{
  ConfigFileEntry.anti_spam_exit_message_time = $3;
};

general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'
{
  ConfigFileEntry.ts_warn_delta = $3;
};

general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'
{
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = $3;
};

general_havent_read_conf: HAVENT_READ_CONF '=' NUMBER ';'
{
  if (($3 > 0) && ypass == 1)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
};

general_kline_with_reason: KLINE_WITH_REASON '=' TBOOL ';'
{
  ConfigFileEntry.kline_with_reason = yylval.number;
};

general_kline_reason: KLINE_REASON '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
};

general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'
{
  ConfigFileEntry.invisible_on_connect = yylval.number;
};

general_warn_no_nline: WARN_NO_NLINE '=' TBOOL ';'
{
  ConfigFileEntry.warn_no_nline = yylval.number;
};

general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'
{
  ConfigFileEntry.stats_o_oper_only = yylval.number;
};

general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'
{
  ConfigFileEntry.stats_P_oper_only = yylval.number;
};

general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'
{
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
} | STATS_K_OPER_ONLY '=' TMASKED ';'
{
  ConfigFileEntry.stats_k_oper_only = 1;
};

general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'
{
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
} | STATS_I_OPER_ONLY '=' TMASKED ';'
{
  ConfigFileEntry.stats_i_oper_only = 1;
};

general_pace_wait: PACE_WAIT '=' timespec ';'
{
  ConfigFileEntry.pace_wait = $3;
};

general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'
{
  ConfigFileEntry.caller_id_wait = $3;
};

general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'
{
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
};

general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'
{
  ConfigFileEntry.pace_wait_simple = $3;
};

general_short_motd: SHORT_MOTD '=' TBOOL ';'
{
  ConfigFileEntry.short_motd = yylval.number;
};
  
general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'
{
  ConfigFileEntry.no_oper_flood = yylval.number;
};

general_true_no_oper_flood: TRUE_NO_OPER_FLOOD '=' TBOOL ';'
{
  ConfigFileEntry.true_no_oper_flood = yylval.number;
};

general_oper_pass_resv: OPER_PASS_RESV '=' TBOOL ';'
{
  ConfigFileEntry.oper_pass_resv = yylval.number;
};

general_message_locale: MESSAGE_LOCALE '=' QSTRING ';'
{
  if (ypass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
};

general_idletime: IDLETIME '=' timespec ';'
{
  ConfigFileEntry.idletime = $3;
};

general_dots_in_ident: DOTS_IN_IDENT '=' NUMBER ';'
{
  ConfigFileEntry.dots_in_ident = $3;
};

general_max_targets: MAX_TARGETS '=' NUMBER ';'
{
  ConfigFileEntry.max_targets = $3;
};

general_servlink_path: SERVLINK_PATH '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
};

general_default_cipher_preference: DEFAULT_CIPHER_PREFERENCE '=' QSTRING ';'
{
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    struct EncCapability *ecap;
    const char *cipher_name;
    int found = 0;

    ConfigFileEntry.default_cipher_preference = NULL;
    cipher_name = yylval.string;

    for (ecap = CipherTable; ecap->name; ecap++)
    {
      if ((irccmp(ecap->name, cipher_name) == 0) &&
          (ecap->cap & CAP_ENC_MASK))
      {
        ConfigFileEntry.default_cipher_preference = ecap;
        found = 1;
        break;
      }
    }

    if (!found)
      yyerror("Invalid cipher");
  }
#else
  if (ypass == 2)
    yyerror("Ignoring default_cipher_preference -- no OpenSSL support");
#endif
};

general_compression_level: COMPRESSION_LEVEL '=' NUMBER ';'
{
  if (ypass == 2)
  {
    ConfigFileEntry.compression_level = $3;
#ifndef HAVE_LIBZ
    yyerror("Ignoring compression_level -- no zlib support");
#else
    if ((ConfigFileEntry.compression_level < 1) ||
        (ConfigFileEntry.compression_level > 9))
    {
      yyerror("Ignoring invalid compression_level, using default");
      ConfigFileEntry.compression_level = 0;
    }
#endif
  }
};

general_use_egd: USE_EGD '=' TBOOL ';'
{
  ConfigFileEntry.use_egd = yylval.number;
};

general_egdpool_path: EGDPOOL_PATH '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
};

general_ping_cookie: PING_COOKIE '=' TBOOL ';'
{
  ConfigFileEntry.ping_cookie = yylval.number;
};

general_disable_auth: DISABLE_AUTH '=' TBOOL ';'
{
  ConfigFileEntry.disable_auth = yylval.number;
};

general_throttle_time: THROTTLE_TIME '=' timespec ';'
{
  ConfigFileEntry.throttle_time = yylval.number;
};

general_oper_umodes: OPER_UMODES
{
  ConfigFileEntry.oper_umodes = 0;
} '='  umode_oitems ';' ;

umode_oitems:    umode_oitems ',' umode_oitem | umode_oitem;
umode_oitem:     T_BOTS
{
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
} | T_CCONN
{
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
} | T_DEAF
{
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
} | T_DEBUG
{
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
} | T_FULL
{
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
} | T_SKILL
{
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
} | T_NCHANGE
{
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
} | T_REJ
{
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
} | T_UNAUTH
{
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
} | T_SPY
{
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
} | T_EXTERNAL
{
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
} | T_OPERWALL
{
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
} | T_SERVNOTICE
{
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
} | T_INVISIBLE
{
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
} | T_WALLOP
{
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
} | T_SOFTCALLERID
{
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
} | T_CALLERID
{
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
} | T_LOCOPS
{
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
};

general_oper_only_umodes: OPER_ONLY_UMODES 
{
  ConfigFileEntry.oper_only_umodes = 0;
} '='  umode_items ';' ;

umode_items:	umode_items ',' umode_item | umode_item;
umode_item:	T_BOTS 
{
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
} | T_CCONN
{
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
} | T_DEAF
{
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
} | T_DEBUG
{
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
} | T_FULL
{ 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
} | T_SKILL
{
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
} | T_NCHANGE
{
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
} | T_REJ
{
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
} | T_UNAUTH
{
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
} | T_SPY
{
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
} | T_EXTERNAL
{
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
} | T_OPERWALL
{
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
} | T_SERVNOTICE
{
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
} | T_INVISIBLE
{
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
} | T_WALLOP
{
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
} | T_SOFTCALLERID
{
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
} | T_CALLERID
{
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
} | T_LOCOPS
{
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
};

general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'
{
  ConfigFileEntry.min_nonwildcard = $3;
};

general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'
{
  ConfigFileEntry.min_nonwildcard_simple = $3;
};

general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'
{
  ConfigFileEntry.default_floodcount = $3;
};

general_client_flood: T_CLIENT_FLOOD '=' sizespec ';'
{
  ConfigFileEntry.client_flood = $3;
};

general_dot_in_ip6_addr: DOT_IN_IP6_ADDR '=' TBOOL ';'
{
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
};

/*************************************************************************** 
 *  section glines
 ***************************************************************************/
gline_entry: GLINES
{
  if (ypass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
} '{' gline_items '}' ';'
{
  if (ypass == 2)
  {
    /*
     * since we re-allocate yy_conf/yy_aconf after the end of action=, at the
     * end we will have one extra, so we should free it.
     */
    if (yy_conf->name == NULL || yy_aconf->user == NULL)
    {
      delete_conf_item(yy_conf);
      yy_conf = NULL;
      yy_aconf = NULL;
    }
  }
};

gline_items:        gline_items gline_item | gline_item;
gline_item:         gline_enable | 
                    gline_duration |
		    gline_logging |
                    gline_user |
                    gline_server | 
                    gline_action |
                    error;

gline_enable: ENABLE '=' TBOOL ';'
{
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
};

gline_duration: DURATION '=' timespec ';'
{
  if (ypass == 2)
    ConfigFileEntry.gline_time = $3;
};

gline_logging: LOGGING
{
  if (ypass == 2)
    ConfigFileEntry.gline_logging = 0;
} '=' gline_logging_types ';';
gline_logging_types:	 gline_logging_types ',' gline_logging_type_item | gline_logging_type_item;
gline_logging_type_item: T_REJECT
{
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
} | T_BLOCK
{
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
};

gline_user: USER '=' QSTRING ';'
{
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp = NULL;

    if (yy_aconf->user == NULL)
    {
      split_nuh(yylval.string, NULL, &yy_aconf->user, &yy_aconf->host);
    }
    else
    {
      yy_tmp = MyMalloc(sizeof(struct CollectItem));
      split_nuh(yylval.string, NULL, &yy_tmp->user, &yy_tmp->host);
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
};

gline_server: NAME '=' QSTRING ';'
{
  if (ypass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
};

gline_action: ACTION
{
  if (ypass == 2)
    yy_aconf->flags = 0;
} '=' gdeny_types ';'
{
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    dlink_node *ptr, *next_ptr;

    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;

      yy_tmp = ptr->data;
      new_conf = make_conf_item(GDENY_TYPE);
      new_aconf = map_to_conf(new_conf);

      new_aconf->flags = yy_aconf->flags;

      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      else
        DupString(new_conf->name, "*");
      if (yy_aconf->user != NULL)
         DupString(new_aconf->user, yy_tmp->user);
      else   
        DupString(new_aconf->user, "*");
      if (yy_aconf->host != NULL)
        DupString(new_aconf->host, yy_tmp->host);
      else
        DupString(new_aconf->host, "*");

      dlinkDelete(&yy_tmp->node, &col_conf_list);
    }

    /*
     * In case someone has fed us with more than one action= after user/name
     * which would leak memory  -Michael
     */
    if (yy_conf->name == NULL || yy_aconf->user == NULL)
      delete_conf_item(yy_conf);

    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
};

gdeny_types: gdeny_types ',' gdeny_type_item | gdeny_type_item;
gdeny_type_item: T_REJECT
{
  if (ypass == 2)
    yy_aconf->flags |= GDENY_REJECT;
} | T_BLOCK
{
  if (ypass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
};

/***************************************************************************
 *  section channel
 ***************************************************************************/
channel_entry: CHANNEL
  '{' channel_items '}' ';';

channel_items:      channel_items channel_item | channel_item;
channel_item:       channel_disable_local_channels | channel_use_except |
                    channel_use_invex | channel_use_knock |
                    channel_max_bans | channel_knock_delay |
                    channel_knock_delay_channel | channel_max_chans_per_user |
                    channel_quiet_on_ban | channel_default_split_user_count |
                    channel_default_split_server_count |
                    channel_no_create_on_split | channel_restrict_channels |
                    channel_no_join_on_split | channel_burst_topicwho |
                    channel_jflood_count | channel_jflood_time |
                    error;

channel_restrict_channels: RESTRICT_CHANNELS '=' TBOOL ';'
{
  ConfigChannel.restrict_channels = yylval.number;
};

channel_disable_local_channels: DISABLE_LOCAL_CHANNELS '=' TBOOL ';'
{
  ConfigChannel.disable_local_channels = yylval.number;
};

channel_use_except: USE_EXCEPT '=' TBOOL ';'
{
  ConfigChannel.use_except = yylval.number;
};

channel_use_invex: USE_INVEX '=' TBOOL ';'
{
  ConfigChannel.use_invex = yylval.number;
};

channel_use_knock: USE_KNOCK '=' TBOOL ';'
{
  ConfigChannel.use_knock = yylval.number;
};

channel_knock_delay: KNOCK_DELAY '=' timespec ';'
{
  ConfigChannel.knock_delay = $3;
};

channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'
{
  ConfigChannel.knock_delay_channel = $3;
};

channel_max_chans_per_user: MAX_CHANS_PER_USER '=' NUMBER ';'
{
  ConfigChannel.max_chans_per_user = $3;
};

channel_quiet_on_ban: QUIET_ON_BAN '=' TBOOL ';'
{
  ConfigChannel.quiet_on_ban = yylval.number;
};

channel_max_bans: MAX_BANS '=' NUMBER ';'
{
  ConfigChannel.max_bans = $3;
};

channel_default_split_user_count: DEFAULT_SPLIT_USER_COUNT '=' NUMBER ';'
{
  ConfigChannel.default_split_user_count = $3;
};

channel_default_split_server_count: DEFAULT_SPLIT_SERVER_COUNT '=' NUMBER ';'
{
  ConfigChannel.default_split_server_count = $3;
};

channel_no_create_on_split: NO_CREATE_ON_SPLIT '=' TBOOL ';'
{
  ConfigChannel.no_create_on_split = yylval.number;
};

channel_no_join_on_split: NO_JOIN_ON_SPLIT '=' TBOOL ';'
{
  ConfigChannel.no_join_on_split = yylval.number;
};

channel_burst_topicwho: BURST_TOPICWHO '=' TBOOL ';'
{
  ConfigChannel.burst_topicwho = yylval.number;
};

channel_jflood_count: JOIN_FLOOD_COUNT '=' NUMBER ';'
{
  GlobalSetOptions.joinfloodcount = yylval.number;
};

channel_jflood_time: JOIN_FLOOD_TIME '=' timespec ';'
{
  GlobalSetOptions.joinfloodtime = yylval.number;
};

/***************************************************************************
 *  section serverhide
 ***************************************************************************/
serverhide_entry: SERVERHIDE
  '{' serverhide_items '}' ';';

serverhide_items:   serverhide_items serverhide_item | serverhide_item;
serverhide_item:    serverhide_flatten_links | serverhide_hide_servers |
		    serverhide_links_delay |
		    serverhide_disable_hidden |
		    serverhide_hidden | serverhide_hidden_name |
		    serverhide_hide_server_ips |
                    error;

serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'
{
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
};

serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'
{
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
};

serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'
{
  if (ypass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
};

serverhide_links_delay: LINKS_DELAY '=' timespec ';'
{
  if (ypass == 2)
  {
    if (($3 > 0) && ConfigServerHide.links_disabled == 1)
    {
      eventAddIsh("write_links_file", write_links_file, NULL, $3);
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = $3;
  }
};

serverhide_hidden: HIDDEN '=' TBOOL ';'
{
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
};

serverhide_disable_hidden: DISABLE_HIDDEN '=' TBOOL ';'
{
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
};

serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'
{
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
};
