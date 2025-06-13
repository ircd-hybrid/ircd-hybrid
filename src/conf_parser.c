/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 29 "conf_parser.y"


#include "stdinc.h"
#include "defaults.h"
#include "io_string.h"
#include "ircd.h"
#include "list.h"
#include "client.h"
#include "command.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_cluster.h"
#include "conf_connect.h"
#include "conf_gecos.h"
#include "conf_oper.h"
#include "conf_pseudo.h"
#include "conf_resv.h"
#include "conf_service.h"
#include "conf_shared.h"
#include "id.h"
#include "ircd_defs.h"
#include "log.h"
#include "memory.h"
#include "module.h"
#include "nuh.h"
#include "server.h"
#include "address.h"
#include "listener.h"
#include "user.h"
#include "motd.h"
#include "cloak.h"
#include "flatten_links.h"

int yylex(void);

static struct
{
  struct
  {
    list_t list;
  } mask,
    leaf,
    hub;

  struct
  {
    char buf[IRCD_BUFSIZE];
  } name,
    nick,
    user,
    host,
    addr,
    bind,
    file,
    ciph,
    cert,
    rpass,
    spass,
    whois,
    modes,
    class,
    target,
    prepend,
    command;

  struct
  {
    unsigned int value;
  } flags,
    size,
    type,
    port,
    timeout,
    aftype,
    attributes,
    ping_freq,
    max_perip_local,
    max_perip_global,
    con_freq,
    min_idle,
    max_idle,
    max_total,
    max_sendq,
    max_recvq,
    max_channels,
    cidr_bitlen_ipv4,
    cidr_bitlen_ipv6,
    number_per_cidr;
} block_state;

static void
reset_block_state(void)
{
  list_node_t *node, *node_next;
  list_t *tab[] = { &block_state.mask.list,
                        &block_state.leaf.list, &block_state.hub.list, NULL };

  for (list_t **list = tab; *list; ++list)
  {
    LIST_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      io_free(node->data);
      list_remove(node, *list);
      list_free_node(node);
    }
  }

  memset(&block_state, 0, sizeof(block_state));
}


#line 183 "conf_parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_CONF_PARSER_H_INCLUDED
# define YY_YY_CONF_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ACCEPT_PASSWORD = 258,         /* ACCEPT_PASSWORD  */
    ADMIN = 259,                   /* ADMIN  */
    AFTYPE = 260,                  /* AFTYPE  */
    ANTI_NICK_FLOOD = 261,         /* ANTI_NICK_FLOOD  */
    ANTI_SPAM_EXIT_MESSAGE_TIME = 262, /* ANTI_SPAM_EXIT_MESSAGE_TIME  */
    AUTOCONN = 263,                /* AUTOCONN  */
    AWAY_COUNT = 264,              /* AWAY_COUNT  */
    AWAY_TIME = 265,               /* AWAY_TIME  */
    BYTES = 266,                   /* BYTES  */
    KBYTES = 267,                  /* KBYTES  */
    MBYTES = 268,                  /* MBYTES  */
    CALLER_ID_WAIT = 269,          /* CALLER_ID_WAIT  */
    CAN_FLOOD = 270,               /* CAN_FLOOD  */
    CHANNEL = 271,                 /* CHANNEL  */
    CIDR_BITLEN_IPV4 = 272,        /* CIDR_BITLEN_IPV4  */
    CIDR_BITLEN_IPV6 = 273,        /* CIDR_BITLEN_IPV6  */
    CLASS = 274,                   /* CLASS  */
    CLIENT = 275,                  /* CLIENT  */
    CLOAK_ENABLED = 276,           /* CLOAK_ENABLED  */
    CLOAK_CIDR_LEN_IPV4 = 277,     /* CLOAK_CIDR_LEN_IPV4  */
    CLOAK_CIDR_LEN_IPV6 = 278,     /* CLOAK_CIDR_LEN_IPV6  */
    CLOAK_NUM_BITS = 279,          /* CLOAK_NUM_BITS  */
    CLOAK_SECRET = 280,            /* CLOAK_SECRET  */
    CLOAK_SUFFIX = 281,            /* CLOAK_SUFFIX  */
    CLOSE = 282,                   /* CLOSE  */
    CONNECT = 283,                 /* CONNECT  */
    CONNECTFREQ = 284,             /* CONNECTFREQ  */
    CORE = 285,                    /* CORE  */
    CYCLE_ON_HOST_CHANGE = 286,    /* CYCLE_ON_HOST_CHANGE  */
    DEFAULT_FLOODCOUNT = 287,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 288,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 289, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 290, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 291,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 292,                   /* DEFER  */
    DENY = 293,                    /* DENY  */
    DESCRIPTION = 294,             /* DESCRIPTION  */
    DIE = 295,                     /* DIE  */
    DISABLE_AUTH = 296,            /* DISABLE_AUTH  */
    DISABLE_DNS = 297,             /* DISABLE_DNS  */
    DISABLE_FAKE_CHANNELS = 298,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 299, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 300,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 301,         /* DLINE_MIN_CIDR6  */
    EMAIL = 302,                   /* EMAIL  */
    ENABLE_ADMIN = 303,            /* ENABLE_ADMIN  */
    ENABLE_EXTBANS = 304,          /* ENABLE_EXTBANS  */
    ENABLE_OWNER = 305,            /* ENABLE_OWNER  */
    ENCRYPTED = 306,               /* ENCRYPTED  */
    EXCEED_LIMIT = 307,            /* EXCEED_LIMIT  */
    EXEMPT = 308,                  /* EXEMPT  */
    FAILED_OPER_NOTICE = 309,      /* FAILED_OPER_NOTICE  */
    FLATTEN_LINKS = 310,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 311,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 312,      /* FLATTEN_LINKS_FILE  */
    GECOS = 313,                   /* GECOS  */
    GENERAL = 314,                 /* GENERAL  */
    HIDDEN = 315,                  /* HIDDEN  */
    HIDDEN_NAME = 316,             /* HIDDEN_NAME  */
    HIDE_CHANS = 317,              /* HIDE_CHANS  */
    HIDE_IDLE = 318,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 319,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVER_IPS = 320,         /* HIDE_SERVER_IPS  */
    HIDE_SERVERS = 321,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 322,           /* HIDE_SERVICES  */
    HOST = 323,                    /* HOST  */
    HUB = 324,                     /* HUB  */
    HUB_MASK = 325,                /* HUB_MASK  */
    IDENT_TIMEOUT = 326,           /* IDENT_TIMEOUT  */
    INVISIBLE_ON_CONNECT = 327,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 328,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 329,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 330,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 331,      /* INVITE_EXPIRE_TIME  */
    IP = 332,                      /* IP  */
    IRCD_AUTH = 333,               /* IRCD_AUTH  */
    IRCD_FLAGS = 334,              /* IRCD_FLAGS  */
    IRCD_SID = 335,                /* IRCD_SID  */
    JOIN = 336,                    /* JOIN  */
    KILL = 337,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 338,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 339,                   /* KLINE  */
    KLINE_EXEMPT = 340,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 341,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 342,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 343,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 344,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 345,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 346,               /* LEAF_MASK  */
    LISTEN = 347,                  /* LISTEN  */
    LOADMODULE = 348,              /* LOADMODULE  */
    MASK = 349,                    /* MASK  */
    MASS = 350,                    /* MASS  */
    MAX_ACCEPT = 351,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 352,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 353,                /* MAX_BANS  */
    MAX_BANS_LARGE = 354,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 355,            /* MAX_CHANNELS  */
    MAX_IDLE = 356,                /* MAX_IDLE  */
    MAX_INVITES = 357,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 358,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 359,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 360,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 361,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 362,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 363,              /* MAX_NUMBER  */
    MAX_TARGETS = 364,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 365,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 366,                 /* MESSAGE  */
    MIN_IDLE = 367,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 368,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 369,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 370,                  /* MODULE  */
    MODULE_BASE_PATH = 371,        /* MODULE_BASE_PATH  */
    MOTD = 372,                    /* MOTD  */
    MOTD_FILE = 373,               /* MOTD_FILE  */
    NAME = 374,                    /* NAME  */
    NEED_IDENT = 375,              /* NEED_IDENT  */
    NEED_PASSWORD = 376,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 377,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 378,            /* NETWORK_NAME  */
    NICK = 379,                    /* NICK  */
    NO_OPER_FLOOD = 380,           /* NO_OPER_FLOOD  */
    NO_TILDE = 381,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 382,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 383,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 384,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 385,             /* OPER_UMODES  */
    OPERATOR = 386,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 387,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 388,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 389,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 390,                /* PASSWORD  */
    PATH = 391,                    /* PATH  */
    PING_COOKIE = 392,             /* PING_COOKIE  */
    PING_TIME = 393,               /* PING_TIME  */
    PORT = 394,                    /* PORT  */
    RANDOM_IDLE = 395,             /* RANDOM_IDLE  */
    REASON = 396,                  /* REASON  */
    REDIRPORT = 397,               /* REDIRPORT  */
    REDIRSERV = 398,               /* REDIRSERV  */
    REHASH = 399,                  /* REHASH  */
    REMOTE = 400,                  /* REMOTE  */
    REMOTEBAN = 401,               /* REMOTEBAN  */
    RESIDENT = 402,                /* RESIDENT  */
    RESV = 403,                    /* RESV  */
    RESV_EXEMPT = 404,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 405,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 406,                 /* SECONDS  */
    MINUTES = 407,                 /* MINUTES  */
    HOURS = 408,                   /* HOURS  */
    DAYS = 409,                    /* DAYS  */
    WEEKS = 410,                   /* WEEKS  */
    MONTHS = 411,                  /* MONTHS  */
    YEARS = 412,                   /* YEARS  */
    SEND_PASSWORD = 413,           /* SEND_PASSWORD  */
    SENDQ = 414,                   /* SENDQ  */
    SERVERHIDE = 415,              /* SERVERHIDE  */
    SERVERINFO = 416,              /* SERVERINFO  */
    SHORT_MOTD = 417,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 418,       /* SPECIALS_IN_IDENT  */
    SPOOF = 419,                   /* SPOOF  */
    SQUIT = 420,                   /* SQUIT  */
    STATS_E_DISABLED = 421,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 422,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 423,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 424,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 425,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 426,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 427,       /* STATS_U_OPER_ONLY  */
    T_ALL = 428,                   /* T_ALL  */
    T_BIND = 429,                  /* T_BIND  */
    T_COMMAND = 430,               /* T_COMMAND  */
    T_CLUSTER = 431,               /* T_CLUSTER  */
    T_DEBUG = 432,                 /* T_DEBUG  */
    T_DLINE = 433,                 /* T_DLINE  */
    T_FILE = 434,                  /* T_FILE  */
    T_GLOBOPS = 435,               /* T_GLOBOPS  */
    T_IPV4 = 436,                  /* T_IPV4  */
    T_IPV6 = 437,                  /* T_IPV6  */
    T_LOCOPS = 438,                /* T_LOCOPS  */
    T_LOG = 439,                   /* T_LOG  */
    T_OPME = 440,                  /* T_OPME  */
    T_PREPEND = 441,               /* T_PREPEND  */
    T_PSEUDO = 442,                /* T_PSEUDO  */
    T_RECVQ = 443,                 /* T_RECVQ  */
    T_RESTART = 444,               /* T_RESTART  */
    T_SERVER = 445,                /* T_SERVER  */
    T_SERVICE = 446,               /* T_SERVICE  */
    T_SET = 447,                   /* T_SET  */
    T_SHARED = 448,                /* T_SHARED  */
    T_SIZE = 449,                  /* T_SIZE  */
    T_TARGET = 450,                /* T_TARGET  */
    T_TLS = 451,                   /* T_TLS  */
    T_UMODES = 452,                /* T_UMODES  */
    T_UNDLINE = 453,               /* T_UNDLINE  */
    T_UNLIMITED = 454,             /* T_UNLIMITED  */
    T_UNRESV = 455,                /* T_UNRESV  */
    T_UNXLINE = 456,               /* T_UNXLINE  */
    T_WEBIRC = 457,                /* T_WEBIRC  */
    TBOOL = 458,                   /* TBOOL  */
    THROTTLE_COUNT = 459,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 460,           /* THROTTLE_TIME  */
    TIMEOUT = 461,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 462,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 463, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 464,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 465,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 466, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 467,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 468, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 469,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 470,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 471,           /* TS_WARN_DELTA  */
    TWODOTS = 472,                 /* TWODOTS  */
    TYPE = 473,                    /* TYPE  */
    UNKLINE = 474,                 /* UNKLINE  */
    USE_LOGGING = 475,             /* USE_LOGGING  */
    USER = 476,                    /* USER  */
    VHOST = 477,                   /* VHOST  */
    VHOST6 = 478,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 479,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 480,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 481,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 482,                   /* XLINE  */
    XLINE_EXEMPT = 483,            /* XLINE_EXEMPT  */
    QSTRING = 484,                 /* QSTRING  */
    NUMBER = 485                   /* NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ACCEPT_PASSWORD 258
#define ADMIN 259
#define AFTYPE 260
#define ANTI_NICK_FLOOD 261
#define ANTI_SPAM_EXIT_MESSAGE_TIME 262
#define AUTOCONN 263
#define AWAY_COUNT 264
#define AWAY_TIME 265
#define BYTES 266
#define KBYTES 267
#define MBYTES 268
#define CALLER_ID_WAIT 269
#define CAN_FLOOD 270
#define CHANNEL 271
#define CIDR_BITLEN_IPV4 272
#define CIDR_BITLEN_IPV6 273
#define CLASS 274
#define CLIENT 275
#define CLOAK_ENABLED 276
#define CLOAK_CIDR_LEN_IPV4 277
#define CLOAK_CIDR_LEN_IPV6 278
#define CLOAK_NUM_BITS 279
#define CLOAK_SECRET 280
#define CLOAK_SUFFIX 281
#define CLOSE 282
#define CONNECT 283
#define CONNECTFREQ 284
#define CORE 285
#define CYCLE_ON_HOST_CHANGE 286
#define DEFAULT_FLOODCOUNT 287
#define DEFAULT_FLOODTIME 288
#define DEFAULT_JOIN_FLOOD_COUNT 289
#define DEFAULT_JOIN_FLOOD_TIME 290
#define DEFAULT_MAX_CLIENTS 291
#define DEFER 292
#define DENY 293
#define DESCRIPTION 294
#define DIE 295
#define DISABLE_AUTH 296
#define DISABLE_DNS 297
#define DISABLE_FAKE_CHANNELS 298
#define DISABLE_REMOTE_COMMANDS 299
#define DLINE_MIN_CIDR 300
#define DLINE_MIN_CIDR6 301
#define EMAIL 302
#define ENABLE_ADMIN 303
#define ENABLE_EXTBANS 304
#define ENABLE_OWNER 305
#define ENCRYPTED 306
#define EXCEED_LIMIT 307
#define EXEMPT 308
#define FAILED_OPER_NOTICE 309
#define FLATTEN_LINKS 310
#define FLATTEN_LINKS_DELAY 311
#define FLATTEN_LINKS_FILE 312
#define GECOS 313
#define GENERAL 314
#define HIDDEN 315
#define HIDDEN_NAME 316
#define HIDE_CHANS 317
#define HIDE_IDLE 318
#define HIDE_IDLE_FROM_OPERS 319
#define HIDE_SERVER_IPS 320
#define HIDE_SERVERS 321
#define HIDE_SERVICES 322
#define HOST 323
#define HUB 324
#define HUB_MASK 325
#define IDENT_TIMEOUT 326
#define INVISIBLE_ON_CONNECT 327
#define INVITE_CLIENT_COUNT 328
#define INVITE_CLIENT_TIME 329
#define INVITE_DELAY_CHANNEL 330
#define INVITE_EXPIRE_TIME 331
#define IP 332
#define IRCD_AUTH 333
#define IRCD_FLAGS 334
#define IRCD_SID 335
#define JOIN 336
#define KILL 337
#define KILL_CHASE_TIME_LIMIT 338
#define KLINE 339
#define KLINE_EXEMPT 340
#define KLINE_MIN_CIDR 341
#define KLINE_MIN_CIDR6 342
#define KNOCK_CLIENT_COUNT 343
#define KNOCK_CLIENT_TIME 344
#define KNOCK_DELAY_CHANNEL 345
#define LEAF_MASK 346
#define LISTEN 347
#define LOADMODULE 348
#define MASK 349
#define MASS 350
#define MAX_ACCEPT 351
#define MAX_AWAY_LENGTH 352
#define MAX_BANS 353
#define MAX_BANS_LARGE 354
#define MAX_CHANNELS 355
#define MAX_IDLE 356
#define MAX_INVITES 357
#define MAX_KICK_LENGTH 358
#define MAX_MONITOR 359
#define MAX_NICK_CHANGES 360
#define MAX_NICK_LENGTH 361
#define MAX_NICK_TIME 362
#define MAX_NUMBER 363
#define MAX_TARGETS 364
#define MAX_TOPIC_LENGTH 365
#define MESSAGE 366
#define MIN_IDLE 367
#define MIN_NONWILDCARD 368
#define MIN_NONWILDCARD_SIMPLE 369
#define MODULE 370
#define MODULE_BASE_PATH 371
#define MOTD 372
#define MOTD_FILE 373
#define NAME 374
#define NEED_IDENT 375
#define NEED_PASSWORD 376
#define NETWORK_DESCRIPTION 377
#define NETWORK_NAME 378
#define NICK 379
#define NO_OPER_FLOOD 380
#define NO_TILDE 381
#define NUMBER_PER_CIDR 382
#define NUMBER_PER_IP_GLOBAL 383
#define NUMBER_PER_IP_LOCAL 384
#define OPER_UMODES 385
#define OPERATOR 386
#define OPERS_BYPASS_CALLERID 387
#define PACE_WAIT 388
#define PACE_WAIT_SIMPLE 389
#define PASSWORD 390
#define PATH 391
#define PING_COOKIE 392
#define PING_TIME 393
#define PORT 394
#define RANDOM_IDLE 395
#define REASON 396
#define REDIRPORT 397
#define REDIRSERV 398
#define REHASH 399
#define REMOTE 400
#define REMOTEBAN 401
#define RESIDENT 402
#define RESV 403
#define RESV_EXEMPT 404
#define RSA_PRIVATE_KEY_FILE 405
#define SECONDS 406
#define MINUTES 407
#define HOURS 408
#define DAYS 409
#define WEEKS 410
#define MONTHS 411
#define YEARS 412
#define SEND_PASSWORD 413
#define SENDQ 414
#define SERVERHIDE 415
#define SERVERINFO 416
#define SHORT_MOTD 417
#define SPECIALS_IN_IDENT 418
#define SPOOF 419
#define SQUIT 420
#define STATS_E_DISABLED 421
#define STATS_I_OPER_ONLY 422
#define STATS_K_OPER_ONLY 423
#define STATS_M_OPER_ONLY 424
#define STATS_O_OPER_ONLY 425
#define STATS_P_OPER_ONLY 426
#define STATS_U_OPER_ONLY 427
#define T_ALL 428
#define T_BIND 429
#define T_COMMAND 430
#define T_CLUSTER 431
#define T_DEBUG 432
#define T_DLINE 433
#define T_FILE 434
#define T_GLOBOPS 435
#define T_IPV4 436
#define T_IPV6 437
#define T_LOCOPS 438
#define T_LOG 439
#define T_OPME 440
#define T_PREPEND 441
#define T_PSEUDO 442
#define T_RECVQ 443
#define T_RESTART 444
#define T_SERVER 445
#define T_SERVICE 446
#define T_SET 447
#define T_SHARED 448
#define T_SIZE 449
#define T_TARGET 450
#define T_TLS 451
#define T_UMODES 452
#define T_UNDLINE 453
#define T_UNLIMITED 454
#define T_UNRESV 455
#define T_UNXLINE 456
#define T_WEBIRC 457
#define TBOOL 458
#define THROTTLE_COUNT 459
#define THROTTLE_TIME 460
#define TIMEOUT 461
#define TLS_CERTIFICATE_FILE 462
#define TLS_CERTIFICATE_FINGERPRINT 463
#define TLS_CIPHER_LIST 464
#define TLS_CIPHER_SUITES 465
#define TLS_CONNECTION_REQUIRED 466
#define TLS_DH_PARAM_FILE 467
#define TLS_MESSAGE_DIGEST_ALGORITHM 468
#define TLS_SUPPORTED_GROUPS 469
#define TS_MAX_DELTA 470
#define TS_WARN_DELTA 471
#define TWODOTS 472
#define TYPE 473
#define UNKLINE 474
#define USE_LOGGING 475
#define USER 476
#define VHOST 477
#define VHOST6 478
#define WARN_NO_CONNECT_BLOCK 479
#define WHOIS 480
#define WHOWAS_HISTORY_LENGTH 481
#define XLINE 482
#define XLINE_EXEMPT 483
#define QSTRING 484
#define NUMBER 485

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 141 "conf_parser.y"

  int number;
  char *string;

#line 701 "conf_parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ACCEPT_PASSWORD = 3,            /* ACCEPT_PASSWORD  */
  YYSYMBOL_ADMIN = 4,                      /* ADMIN  */
  YYSYMBOL_AFTYPE = 5,                     /* AFTYPE  */
  YYSYMBOL_ANTI_NICK_FLOOD = 6,            /* ANTI_NICK_FLOOD  */
  YYSYMBOL_ANTI_SPAM_EXIT_MESSAGE_TIME = 7, /* ANTI_SPAM_EXIT_MESSAGE_TIME  */
  YYSYMBOL_AUTOCONN = 8,                   /* AUTOCONN  */
  YYSYMBOL_AWAY_COUNT = 9,                 /* AWAY_COUNT  */
  YYSYMBOL_AWAY_TIME = 10,                 /* AWAY_TIME  */
  YYSYMBOL_BYTES = 11,                     /* BYTES  */
  YYSYMBOL_KBYTES = 12,                    /* KBYTES  */
  YYSYMBOL_MBYTES = 13,                    /* MBYTES  */
  YYSYMBOL_CALLER_ID_WAIT = 14,            /* CALLER_ID_WAIT  */
  YYSYMBOL_CAN_FLOOD = 15,                 /* CAN_FLOOD  */
  YYSYMBOL_CHANNEL = 16,                   /* CHANNEL  */
  YYSYMBOL_CIDR_BITLEN_IPV4 = 17,          /* CIDR_BITLEN_IPV4  */
  YYSYMBOL_CIDR_BITLEN_IPV6 = 18,          /* CIDR_BITLEN_IPV6  */
  YYSYMBOL_CLASS = 19,                     /* CLASS  */
  YYSYMBOL_CLIENT = 20,                    /* CLIENT  */
  YYSYMBOL_CLOAK_ENABLED = 21,             /* CLOAK_ENABLED  */
  YYSYMBOL_CLOAK_CIDR_LEN_IPV4 = 22,       /* CLOAK_CIDR_LEN_IPV4  */
  YYSYMBOL_CLOAK_CIDR_LEN_IPV6 = 23,       /* CLOAK_CIDR_LEN_IPV6  */
  YYSYMBOL_CLOAK_NUM_BITS = 24,            /* CLOAK_NUM_BITS  */
  YYSYMBOL_CLOAK_SECRET = 25,              /* CLOAK_SECRET  */
  YYSYMBOL_CLOAK_SUFFIX = 26,              /* CLOAK_SUFFIX  */
  YYSYMBOL_CLOSE = 27,                     /* CLOSE  */
  YYSYMBOL_CONNECT = 28,                   /* CONNECT  */
  YYSYMBOL_CONNECTFREQ = 29,               /* CONNECTFREQ  */
  YYSYMBOL_CORE = 30,                      /* CORE  */
  YYSYMBOL_CYCLE_ON_HOST_CHANGE = 31,      /* CYCLE_ON_HOST_CHANGE  */
  YYSYMBOL_DEFAULT_FLOODCOUNT = 32,        /* DEFAULT_FLOODCOUNT  */
  YYSYMBOL_DEFAULT_FLOODTIME = 33,         /* DEFAULT_FLOODTIME  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_COUNT = 34,  /* DEFAULT_JOIN_FLOOD_COUNT  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_TIME = 35,   /* DEFAULT_JOIN_FLOOD_TIME  */
  YYSYMBOL_DEFAULT_MAX_CLIENTS = 36,       /* DEFAULT_MAX_CLIENTS  */
  YYSYMBOL_DEFER = 37,                     /* DEFER  */
  YYSYMBOL_DENY = 38,                      /* DENY  */
  YYSYMBOL_DESCRIPTION = 39,               /* DESCRIPTION  */
  YYSYMBOL_DIE = 40,                       /* DIE  */
  YYSYMBOL_DISABLE_AUTH = 41,              /* DISABLE_AUTH  */
  YYSYMBOL_DISABLE_DNS = 42,               /* DISABLE_DNS  */
  YYSYMBOL_DISABLE_FAKE_CHANNELS = 43,     /* DISABLE_FAKE_CHANNELS  */
  YYSYMBOL_DISABLE_REMOTE_COMMANDS = 44,   /* DISABLE_REMOTE_COMMANDS  */
  YYSYMBOL_DLINE_MIN_CIDR = 45,            /* DLINE_MIN_CIDR  */
  YYSYMBOL_DLINE_MIN_CIDR6 = 46,           /* DLINE_MIN_CIDR6  */
  YYSYMBOL_EMAIL = 47,                     /* EMAIL  */
  YYSYMBOL_ENABLE_ADMIN = 48,              /* ENABLE_ADMIN  */
  YYSYMBOL_ENABLE_EXTBANS = 49,            /* ENABLE_EXTBANS  */
  YYSYMBOL_ENABLE_OWNER = 50,              /* ENABLE_OWNER  */
  YYSYMBOL_ENCRYPTED = 51,                 /* ENCRYPTED  */
  YYSYMBOL_EXCEED_LIMIT = 52,              /* EXCEED_LIMIT  */
  YYSYMBOL_EXEMPT = 53,                    /* EXEMPT  */
  YYSYMBOL_FAILED_OPER_NOTICE = 54,        /* FAILED_OPER_NOTICE  */
  YYSYMBOL_FLATTEN_LINKS = 55,             /* FLATTEN_LINKS  */
  YYSYMBOL_FLATTEN_LINKS_DELAY = 56,       /* FLATTEN_LINKS_DELAY  */
  YYSYMBOL_FLATTEN_LINKS_FILE = 57,        /* FLATTEN_LINKS_FILE  */
  YYSYMBOL_GECOS = 58,                     /* GECOS  */
  YYSYMBOL_GENERAL = 59,                   /* GENERAL  */
  YYSYMBOL_HIDDEN = 60,                    /* HIDDEN  */
  YYSYMBOL_HIDDEN_NAME = 61,               /* HIDDEN_NAME  */
  YYSYMBOL_HIDE_CHANS = 62,                /* HIDE_CHANS  */
  YYSYMBOL_HIDE_IDLE = 63,                 /* HIDE_IDLE  */
  YYSYMBOL_HIDE_IDLE_FROM_OPERS = 64,      /* HIDE_IDLE_FROM_OPERS  */
  YYSYMBOL_HIDE_SERVER_IPS = 65,           /* HIDE_SERVER_IPS  */
  YYSYMBOL_HIDE_SERVERS = 66,              /* HIDE_SERVERS  */
  YYSYMBOL_HIDE_SERVICES = 67,             /* HIDE_SERVICES  */
  YYSYMBOL_HOST = 68,                      /* HOST  */
  YYSYMBOL_HUB = 69,                       /* HUB  */
  YYSYMBOL_HUB_MASK = 70,                  /* HUB_MASK  */
  YYSYMBOL_IDENT_TIMEOUT = 71,             /* IDENT_TIMEOUT  */
  YYSYMBOL_INVISIBLE_ON_CONNECT = 72,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 73,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 74,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 75,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 76,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 77,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 78,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 79,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 80,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 81,                      /* JOIN  */
  YYSYMBOL_KILL = 82,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 83,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 84,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 85,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 86,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 87,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 88,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 89,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 90,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 91,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 92,                    /* LISTEN  */
  YYSYMBOL_LOADMODULE = 93,                /* LOADMODULE  */
  YYSYMBOL_MASK = 94,                      /* MASK  */
  YYSYMBOL_MASS = 95,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 96,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_AWAY_LENGTH = 97,           /* MAX_AWAY_LENGTH  */
  YYSYMBOL_MAX_BANS = 98,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 99,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 100,             /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 101,                 /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 102,              /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 103,          /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 104,              /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 105,         /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 106,          /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 107,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 108,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 109,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 110,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 111,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 112,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 113,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 114,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 115,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 116,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 117,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 118,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 119,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 120,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 121,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 122,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 123,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 124,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 125,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 126,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 127,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 128,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 129,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_UMODES = 130,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 131,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 132,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 133,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 134,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 135,                 /* PASSWORD  */
  YYSYMBOL_PATH = 136,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 137,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 138,                /* PING_TIME  */
  YYSYMBOL_PORT = 139,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 140,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 141,                   /* REASON  */
  YYSYMBOL_REDIRPORT = 142,                /* REDIRPORT  */
  YYSYMBOL_REDIRSERV = 143,                /* REDIRSERV  */
  YYSYMBOL_REHASH = 144,                   /* REHASH  */
  YYSYMBOL_REMOTE = 145,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 146,                /* REMOTEBAN  */
  YYSYMBOL_RESIDENT = 147,                 /* RESIDENT  */
  YYSYMBOL_RESV = 148,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 149,              /* RESV_EXEMPT  */
  YYSYMBOL_RSA_PRIVATE_KEY_FILE = 150,     /* RSA_PRIVATE_KEY_FILE  */
  YYSYMBOL_SECONDS = 151,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 152,                  /* MINUTES  */
  YYSYMBOL_HOURS = 153,                    /* HOURS  */
  YYSYMBOL_DAYS = 154,                     /* DAYS  */
  YYSYMBOL_WEEKS = 155,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 156,                   /* MONTHS  */
  YYSYMBOL_YEARS = 157,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 158,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 159,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 160,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 161,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 162,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 163,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 164,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 165,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 166,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_I_OPER_ONLY = 167,        /* STATS_I_OPER_ONLY  */
  YYSYMBOL_STATS_K_OPER_ONLY = 168,        /* STATS_K_OPER_ONLY  */
  YYSYMBOL_STATS_M_OPER_ONLY = 169,        /* STATS_M_OPER_ONLY  */
  YYSYMBOL_STATS_O_OPER_ONLY = 170,        /* STATS_O_OPER_ONLY  */
  YYSYMBOL_STATS_P_OPER_ONLY = 171,        /* STATS_P_OPER_ONLY  */
  YYSYMBOL_STATS_U_OPER_ONLY = 172,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 173,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 174,                   /* T_BIND  */
  YYSYMBOL_T_COMMAND = 175,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 176,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 177,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 178,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 179,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 180,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 181,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 182,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 183,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 184,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 185,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 186,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 187,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 188,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 189,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 190,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 191,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 192,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 193,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 194,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 195,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 196,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 197,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 198,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 199,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 200,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 201,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 202,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 203,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 204,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 205,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 206,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 207,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 208, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 209,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 210,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 211,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 212,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 213, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 214,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 215,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 216,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 217,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 218,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 219,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 220,              /* USE_LOGGING  */
  YYSYMBOL_USER = 221,                     /* USER  */
  YYSYMBOL_VHOST = 222,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 223,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 224,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 225,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 226,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 227,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 228,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 229,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 230,                   /* NUMBER  */
  YYSYMBOL_231_ = 231,                     /* ';'  */
  YYSYMBOL_232_ = 232,                     /* '}'  */
  YYSYMBOL_233_ = 233,                     /* '='  */
  YYSYMBOL_234_ = 234,                     /* ':'  */
  YYSYMBOL_235_ = 235,                     /* ','  */
  YYSYMBOL_236_ = 236,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 237,                 /* $accept  */
  YYSYMBOL_conf = 238,                     /* conf  */
  YYSYMBOL_conf_item = 239,                /* conf_item  */
  YYSYMBOL_timespec_ = 240,                /* timespec_  */
  YYSYMBOL_timespec = 241,                 /* timespec  */
  YYSYMBOL_sizespec_ = 242,                /* sizespec_  */
  YYSYMBOL_sizespec = 243,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 244,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 245,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 246,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 247,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 248,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 249,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 250,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 251,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 252, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 253, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 254, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 255, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 256, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 257, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 258, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 259,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 260,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 261,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 262,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 263, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 264, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 265, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 266, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_motd_file = 267,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 268,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 269,              /* admin_entry  */
  YYSYMBOL_admin_items = 270,              /* admin_items  */
  YYSYMBOL_admin_item = 271,               /* admin_item  */
  YYSYMBOL_admin_name = 272,               /* admin_name  */
  YYSYMBOL_admin_email = 273,              /* admin_email  */
  YYSYMBOL_admin_description = 274,        /* admin_description  */
  YYSYMBOL_motd_entry = 275,               /* motd_entry  */
  YYSYMBOL_276_1 = 276,                    /* $@1  */
  YYSYMBOL_motd_items = 277,               /* motd_items  */
  YYSYMBOL_motd_item = 278,                /* motd_item  */
  YYSYMBOL_motd_mask = 279,                /* motd_mask  */
  YYSYMBOL_motd_file = 280,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 281,             /* pseudo_entry  */
  YYSYMBOL_282_2 = 282,                    /* $@2  */
  YYSYMBOL_pseudo_items = 283,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 284,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 285,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 286,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 287,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 288,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 289,            /* logging_entry  */
  YYSYMBOL_logging_items = 290,            /* logging_items  */
  YYSYMBOL_logging_item = 291,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 292,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 293,       /* logging_file_entry  */
  YYSYMBOL_294_3 = 294,                    /* $@3  */
  YYSYMBOL_logging_file_items = 295,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 296,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 297,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 298,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 299,        /* logging_file_type  */
  YYSYMBOL_300_4 = 300,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 301,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 302,               /* oper_entry  */
  YYSYMBOL_303_5 = 303,                    /* $@5  */
  YYSYMBOL_oper_items = 304,               /* oper_items  */
  YYSYMBOL_oper_item = 305,                /* oper_item  */
  YYSYMBOL_oper_name = 306,                /* oper_name  */
  YYSYMBOL_oper_user = 307,                /* oper_user  */
  YYSYMBOL_oper_password = 308,            /* oper_password  */
  YYSYMBOL_oper_whois = 309,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 310,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 311, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 312, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 313,               /* oper_class  */
  YYSYMBOL_oper_umodes = 314,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 315,               /* oper_flags  */
  YYSYMBOL_316_6 = 316,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 317,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 318,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 319,              /* class_entry  */
  YYSYMBOL_320_7 = 320,                    /* $@7  */
  YYSYMBOL_class_items = 321,              /* class_items  */
  YYSYMBOL_class_item = 322,               /* class_item  */
  YYSYMBOL_class_name = 323,               /* class_name  */
  YYSYMBOL_class_ping_time = 324,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 325, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 326, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 327,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 328,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 329,         /* class_max_number  */
  YYSYMBOL_class_sendq = 330,              /* class_sendq  */
  YYSYMBOL_class_recvq = 331,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 332,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 333,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 334,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 335,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 336,           /* class_max_idle  */
  YYSYMBOL_class_flags = 337,              /* class_flags  */
  YYSYMBOL_338_8 = 338,                    /* $@8  */
  YYSYMBOL_class_flags_items = 339,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 340,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 341,             /* listen_entry  */
  YYSYMBOL_342_9 = 342,                    /* $@9  */
  YYSYMBOL_listen_flags = 343,             /* listen_flags  */
  YYSYMBOL_344_10 = 344,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 345,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 346,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 347,             /* listen_items  */
  YYSYMBOL_listen_item = 348,              /* listen_item  */
  YYSYMBOL_listen_port = 349,              /* listen_port  */
  YYSYMBOL_350_11 = 350,                   /* $@11  */
  YYSYMBOL_port_items = 351,               /* port_items  */
  YYSYMBOL_port_item = 352,                /* port_item  */
  YYSYMBOL_listen_address = 353,           /* listen_address  */
  YYSYMBOL_listen_host = 354,              /* listen_host  */
  YYSYMBOL_auth_entry = 355,               /* auth_entry  */
  YYSYMBOL_356_12 = 356,                   /* $@12  */
  YYSYMBOL_auth_items = 357,               /* auth_items  */
  YYSYMBOL_auth_item = 358,                /* auth_item  */
  YYSYMBOL_auth_user = 359,                /* auth_user  */
  YYSYMBOL_auth_passwd = 360,              /* auth_passwd  */
  YYSYMBOL_auth_class = 361,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 362,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 363,               /* auth_flags  */
  YYSYMBOL_364_13 = 364,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 365,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 366,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 367,               /* auth_spoof  */
  YYSYMBOL_auth_redir_serv = 368,          /* auth_redir_serv  */
  YYSYMBOL_auth_redir_port = 369,          /* auth_redir_port  */
  YYSYMBOL_resv_entry = 370,               /* resv_entry  */
  YYSYMBOL_371_14 = 371,                   /* $@14  */
  YYSYMBOL_resv_items = 372,               /* resv_items  */
  YYSYMBOL_resv_item = 373,                /* resv_item  */
  YYSYMBOL_resv_mask = 374,                /* resv_mask  */
  YYSYMBOL_resv_reason = 375,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 376,              /* resv_exempt  */
  YYSYMBOL_service_entry = 377,            /* service_entry  */
  YYSYMBOL_service_items = 378,            /* service_items  */
  YYSYMBOL_service_item = 379,             /* service_item  */
  YYSYMBOL_service_name = 380,             /* service_name  */
  YYSYMBOL_shared_entry = 381,             /* shared_entry  */
  YYSYMBOL_382_15 = 382,                   /* $@15  */
  YYSYMBOL_shared_items = 383,             /* shared_items  */
  YYSYMBOL_shared_item = 384,              /* shared_item  */
  YYSYMBOL_shared_name = 385,              /* shared_name  */
  YYSYMBOL_shared_user = 386,              /* shared_user  */
  YYSYMBOL_shared_type = 387,              /* shared_type  */
  YYSYMBOL_388_16 = 388,                   /* $@16  */
  YYSYMBOL_shared_types = 389,             /* shared_types  */
  YYSYMBOL_shared_type_item = 390,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 391,            /* cluster_entry  */
  YYSYMBOL_392_17 = 392,                   /* $@17  */
  YYSYMBOL_cluster_items = 393,            /* cluster_items  */
  YYSYMBOL_cluster_item = 394,             /* cluster_item  */
  YYSYMBOL_cluster_name = 395,             /* cluster_name  */
  YYSYMBOL_cluster_type = 396,             /* cluster_type  */
  YYSYMBOL_397_18 = 397,                   /* $@18  */
  YYSYMBOL_cluster_types = 398,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 399,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 400,            /* connect_entry  */
  YYSYMBOL_401_19 = 401,                   /* $@19  */
  YYSYMBOL_connect_items = 402,            /* connect_items  */
  YYSYMBOL_connect_item = 403,             /* connect_item  */
  YYSYMBOL_connect_name = 404,             /* connect_name  */
  YYSYMBOL_connect_host = 405,             /* connect_host  */
  YYSYMBOL_connect_timeout = 406,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 407,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 408,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 409,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 410, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 411,             /* connect_port  */
  YYSYMBOL_connect_aftype = 412,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 413,            /* connect_flags  */
  YYSYMBOL_414_20 = 414,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 415,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 416,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 417,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 418,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 419,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 420,            /* connect_class  */
  YYSYMBOL_connect_tls_cipher_list = 421,  /* connect_tls_cipher_list  */
  YYSYMBOL_kill_entry = 422,               /* kill_entry  */
  YYSYMBOL_423_21 = 423,                   /* $@21  */
  YYSYMBOL_kill_items = 424,               /* kill_items  */
  YYSYMBOL_kill_item = 425,                /* kill_item  */
  YYSYMBOL_kill_user = 426,                /* kill_user  */
  YYSYMBOL_kill_reason = 427,              /* kill_reason  */
  YYSYMBOL_deny_entry = 428,               /* deny_entry  */
  YYSYMBOL_429_22 = 429,                   /* $@22  */
  YYSYMBOL_deny_items = 430,               /* deny_items  */
  YYSYMBOL_deny_item = 431,                /* deny_item  */
  YYSYMBOL_deny_ip = 432,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 433,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 434,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 435,             /* exempt_items  */
  YYSYMBOL_exempt_item = 436,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 437,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 438,              /* gecos_entry  */
  YYSYMBOL_439_23 = 439,                   /* $@23  */
  YYSYMBOL_gecos_items = 440,              /* gecos_items  */
  YYSYMBOL_gecos_item = 441,               /* gecos_item  */
  YYSYMBOL_gecos_name = 442,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 443,             /* gecos_reason  */
  YYSYMBOL_general_entry = 444,            /* general_entry  */
  YYSYMBOL_general_items = 445,            /* general_items  */
  YYSYMBOL_general_item = 446,             /* general_item  */
  YYSYMBOL_general_away_count = 447,       /* general_away_count  */
  YYSYMBOL_general_away_time = 448,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 449,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 450, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 451, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 452,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 453,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 454,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 455,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 456, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 457, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 458,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 459,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 460, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 461,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 462,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 463, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 464,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 465,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 466, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 467, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 468, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 469, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 470, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 471, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 472, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 473, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 474, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 475,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 476,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 477, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 478, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 479,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 480,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 481, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 482,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 483,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_auth = 484,     /* general_disable_auth  */
  YYSYMBOL_general_disable_dns = 485,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 486,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 487,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 488,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 489,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 490, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 491, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 492, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 493,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 494, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 495, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 496,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 497,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 498,     /* general_cloak_suffix  */
  YYSYMBOL_general_ident_timeout = 499,    /* general_ident_timeout  */
  YYSYMBOL_channel_entry = 500,            /* channel_entry  */
  YYSYMBOL_channel_items = 501,            /* channel_items  */
  YYSYMBOL_channel_item = 502,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 503,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 504,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 505,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 506, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 507, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 508, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 509, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 510, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 511, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 512, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 513, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 514,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 515,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 516,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 517,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 518,  /* channel_max_kick_length  */
  YYSYMBOL_channel_default_join_flood_count = 519, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 520, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 521,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 522,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 523,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 524, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 525, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 526, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 527, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 528,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 529, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 530,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 531,        /* serverhide_hidden  */
  YYSYMBOL_serverhide_hide_server_ips = 532 /* serverhide_hide_server_ips  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  296
/* YYNRULES -- Number of rules.  */
#define YYNRULES  615
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1291

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   485


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   235,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   234,   231,
       2,   233,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   236,     2,   232,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   373,   373,   374,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   405,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   416,
     416,   417,   418,   419,   420,   427,   437,   444,   446,   448,
     448,   450,   454,   464,   466,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   487,   496,   505,   514,   523,   532,
     541,   550,   565,   580,   590,   604,   613,   636,   659,   667,
     676,   686,   688,   688,   689,   690,   691,   692,   694,   703,
     712,   726,   725,   743,   743,   744,   744,   744,   746,   752,
     763,   762,   781,   781,   782,   782,   782,   782,   782,   784,
     790,   796,   802,   825,   826,   826,   828,   828,   829,   831,
     838,   838,   851,   852,   854,   854,   855,   855,   857,   865,
     868,   874,   873,   879,   883,   887,   891,   895,   899,   903,
     907,   918,   917,   979,   979,   980,   981,   982,   983,   984,
     985,   986,   987,   988,   989,   990,   992,   998,  1004,  1010,
    1016,  1027,  1033,  1044,  1050,  1057,  1056,  1062,  1062,  1063,
    1067,  1071,  1075,  1079,  1083,  1087,  1091,  1095,  1099,  1103,
    1107,  1111,  1115,  1119,  1123,  1127,  1131,  1135,  1139,  1143,
    1147,  1151,  1155,  1159,  1163,  1167,  1171,  1175,  1186,  1185,
    1241,  1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,
    1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1259,  1265,
    1271,  1277,  1283,  1289,  1295,  1301,  1307,  1314,  1320,  1326,
    1332,  1341,  1351,  1350,  1356,  1356,  1357,  1361,  1372,  1371,
    1378,  1377,  1382,  1382,  1383,  1387,  1391,  1395,  1399,  1405,
    1405,  1406,  1406,  1406,  1406,  1406,  1408,  1408,  1410,  1410,
    1412,  1425,  1442,  1448,  1459,  1458,  1506,  1506,  1507,  1508,
    1509,  1510,  1511,  1512,  1513,  1514,  1515,  1517,  1523,  1529,
    1535,  1547,  1546,  1552,  1552,  1553,  1557,  1561,  1565,  1569,
    1573,  1577,  1581,  1585,  1591,  1605,  1614,  1628,  1627,  1642,
    1642,  1643,  1643,  1643,  1643,  1645,  1651,  1657,  1667,  1669,
    1669,  1670,  1670,  1672,  1689,  1688,  1711,  1711,  1712,  1712,
    1712,  1712,  1714,  1720,  1740,  1739,  1745,  1745,  1746,  1750,
    1754,  1758,  1762,  1766,  1770,  1774,  1778,  1782,  1793,  1792,
    1811,  1811,  1812,  1812,  1812,  1814,  1821,  1820,  1826,  1826,
    1827,  1831,  1835,  1839,  1843,  1847,  1851,  1855,  1859,  1863,
    1874,  1873,  1931,  1931,  1932,  1933,  1934,  1935,  1936,  1937,
    1938,  1939,  1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,
    1949,  1955,  1961,  1967,  1973,  1986,  1999,  2005,  2011,  2015,
    2022,  2021,  2026,  2026,  2027,  2031,  2037,  2048,  2054,  2060,
    2066,  2082,  2081,  2105,  2105,  2106,  2106,  2106,  2108,  2128,
    2139,  2138,  2163,  2163,  2164,  2164,  2164,  2166,  2172,  2182,
    2184,  2184,  2185,  2185,  2187,  2205,  2204,  2225,  2225,  2226,
    2226,  2226,  2228,  2234,  2244,  2246,  2246,  2247,  2248,  2249,
    2250,  2251,  2252,  2253,  2254,  2255,  2256,  2257,  2258,  2259,
    2260,  2261,  2262,  2263,  2264,  2265,  2266,  2267,  2268,  2269,
    2270,  2271,  2272,  2273,  2274,  2275,  2276,  2277,  2278,  2279,
    2280,  2281,  2282,  2283,  2284,  2285,  2286,  2287,  2288,  2289,
    2290,  2291,  2292,  2293,  2294,  2295,  2296,  2297,  2298,  2299,
    2300,  2303,  2308,  2313,  2318,  2323,  2328,  2333,  2338,  2343,
    2348,  2353,  2358,  2363,  2368,  2373,  2378,  2386,  2391,  2396,
    2401,  2406,  2411,  2416,  2421,  2426,  2431,  2436,  2441,  2446,
    2451,  2456,  2461,  2466,  2471,  2476,  2481,  2486,  2491,  2496,
    2501,  2506,  2511,  2520,  2525,  2530,  2535,  2540,  2557,  2565,
    2573,  2581,  2591,  2601,  2612,  2614,  2614,  2615,  2616,  2617,
    2618,  2619,  2620,  2621,  2622,  2623,  2624,  2625,  2626,  2627,
    2628,  2629,  2630,  2631,  2632,  2633,  2635,  2640,  2646,  2652,
    2657,  2662,  2667,  2672,  2677,  2682,  2687,  2692,  2697,  2702,
    2707,  2712,  2735,  2740,  2749,  2751,  2751,  2752,  2753,  2754,
    2755,  2756,  2757,  2758,  2759,  2760,  2761,  2763,  2769,  2780,
    2789,  2795,  2801,  2807,  2816,  2822
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ACCEPT_PASSWORD",
  "ADMIN", "AFTYPE", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME",
  "AUTOCONN", "AWAY_COUNT", "AWAY_TIME", "BYTES", "KBYTES", "MBYTES",
  "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL", "CIDR_BITLEN_IPV4",
  "CIDR_BITLEN_IPV6", "CLASS", "CLIENT", "CLOAK_ENABLED",
  "CLOAK_CIDR_LEN_IPV4", "CLOAK_CIDR_LEN_IPV6", "CLOAK_NUM_BITS",
  "CLOAK_SECRET", "CLOAK_SUFFIX", "CLOSE", "CONNECT", "CONNECTFREQ",
  "CORE", "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_FLOODTIME", "DEFAULT_JOIN_FLOOD_COUNT",
  "DEFAULT_JOIN_FLOOD_TIME", "DEFAULT_MAX_CLIENTS", "DEFER", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_DNS",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR",
  "DLINE_MIN_CIDR6", "EMAIL", "ENABLE_ADMIN", "ENABLE_EXTBANS",
  "ENABLE_OWNER", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "FLATTEN_LINKS_DELAY",
  "FLATTEN_LINKS_FILE", "GECOS", "GENERAL", "HIDDEN", "HIDDEN_NAME",
  "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK",
  "IDENT_TIMEOUT", "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT",
  "INVITE_CLIENT_TIME", "INVITE_DELAY_CHANNEL", "INVITE_EXPIRE_TIME", "IP",
  "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID", "JOIN", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_MIN_CIDR",
  "KLINE_MIN_CIDR6", "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME",
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LISTEN", "LOADMODULE", "MASK",
  "MASS", "MAX_ACCEPT", "MAX_AWAY_LENGTH", "MAX_BANS", "MAX_BANS_LARGE",
  "MAX_CHANNELS", "MAX_IDLE", "MAX_INVITES", "MAX_KICK_LENGTH",
  "MAX_MONITOR", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME",
  "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MESSAGE", "MIN_IDLE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE",
  "MODULE_BASE_PATH", "MOTD", "MOTD_FILE", "NAME", "NEED_IDENT",
  "NEED_PASSWORD", "NETWORK_DESCRIPTION", "NETWORK_NAME", "NICK",
  "NO_OPER_FLOOD", "NO_TILDE", "NUMBER_PER_CIDR", "NUMBER_PER_IP_GLOBAL",
  "NUMBER_PER_IP_LOCAL", "OPER_UMODES", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD",
  "PATH", "PING_COOKIE", "PING_TIME", "PORT", "RANDOM_IDLE", "REASON",
  "REDIRPORT", "REDIRSERV", "REHASH", "REMOTE", "REMOTEBAN", "RESIDENT",
  "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ",
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPECIALS_IN_IDENT", "SPOOF",
  "SQUIT", "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_M_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY",
  "STATS_U_OPER_ONLY", "T_ALL", "T_BIND", "T_COMMAND", "T_CLUSTER",
  "T_DEBUG", "T_DLINE", "T_FILE", "T_GLOBOPS", "T_IPV4", "T_IPV6",
  "T_LOCOPS", "T_LOG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ",
  "T_RESTART", "T_SERVER", "T_SERVICE", "T_SET", "T_SHARED", "T_SIZE",
  "T_TARGET", "T_TLS", "T_UMODES", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV",
  "T_UNXLINE", "T_WEBIRC", "TBOOL", "THROTTLE_COUNT", "THROTTLE_TIME",
  "TIMEOUT", "TLS_CERTIFICATE_FILE", "TLS_CERTIFICATE_FINGERPRINT",
  "TLS_CIPHER_LIST", "TLS_CIPHER_SUITES", "TLS_CONNECTION_REQUIRED",
  "TLS_DH_PARAM_FILE", "TLS_MESSAGE_DIGEST_ALGORITHM",
  "TLS_SUPPORTED_GROUPS", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "TYPE", "UNKLINE", "USE_LOGGING", "USER", "VHOST", "VHOST6",
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "WHOWAS_HISTORY_LENGTH", "XLINE",
  "XLINE_EXEMPT", "QSTRING", "NUMBER", "';'", "'}'", "'='", "':'", "','",
  "'{'", "$accept", "conf", "conf_item", "timespec_", "timespec",
  "sizespec_", "sizespec", "module_base_path_entry", "loadmodule_entry",
  "module_attributes", "module_attributes_items", "module_attributes_item",
  "serverinfo_entry", "serverinfo_items", "serverinfo_item",
  "serverinfo_tls_certificate_file", "serverinfo_rsa_private_key_file",
  "serverinfo_tls_dh_param_file", "serverinfo_tls_cipher_list",
  "serverinfo_tls_cipher_suites",
  "serverinfo_tls_message_digest_algorithm",
  "serverinfo_tls_supported_groups", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_description", "serverinfo_default_max_clients",
  "serverinfo_max_nick_length", "serverinfo_max_topic_length",
  "serverinfo_motd_file", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "motd_entry", "$@1", "motd_items", "motd_item", "motd_mask", "motd_file",
  "pseudo_entry", "$@2", "pseudo_items", "pseudo_item", "pseudo_command",
  "pseudo_name", "pseudo_prepend", "pseudo_target", "logging_entry",
  "logging_items", "logging_item", "logging_use_logging",
  "logging_file_entry", "$@3", "logging_file_items", "logging_file_item",
  "logging_file_name", "logging_file_size", "logging_file_type", "$@4",
  "logging_file_type_item", "oper_entry", "$@5", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_whois",
  "oper_encrypted", "oper_tls_certificate_fingerprint",
  "oper_tls_connection_required", "oper_class", "oper_umodes",
  "oper_flags", "$@6", "oper_flags_items", "oper_flags_item",
  "class_entry", "$@7", "class_items", "class_item", "class_name",
  "class_ping_time", "class_number_per_ip_local",
  "class_number_per_ip_global", "class_connectfreq", "class_max_channels",
  "class_max_number", "class_sendq", "class_recvq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "class_min_idle", "class_max_idle",
  "class_flags", "$@8", "class_flags_items", "class_flags_item",
  "listen_entry", "$@9", "listen_flags", "$@10", "listen_flags_items",
  "listen_flags_item", "listen_items", "listen_item", "listen_port",
  "$@11", "port_items", "port_item", "listen_address", "listen_host",
  "auth_entry", "$@12", "auth_items", "auth_item", "auth_user",
  "auth_passwd", "auth_class", "auth_encrypted", "auth_flags", "$@13",
  "auth_flags_items", "auth_flags_item", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@14", "resv_items", "resv_item",
  "resv_mask", "resv_reason", "resv_exempt", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@15",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@16", "shared_types", "shared_type_item",
  "cluster_entry", "$@17", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@18", "cluster_types", "cluster_type_item",
  "connect_entry", "$@19", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_timeout", "connect_bind",
  "connect_send_password", "connect_accept_password",
  "connect_tls_certificate_fingerprint", "connect_port", "connect_aftype",
  "connect_flags", "$@20", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_tls_cipher_list", "kill_entry", "$@21",
  "kill_items", "kill_item", "kill_user", "kill_reason", "deny_entry",
  "$@22", "deny_items", "deny_item", "deny_ip", "deny_reason",
  "exempt_entry", "exempt_items", "exempt_item", "exempt_ip",
  "gecos_entry", "$@23", "gecos_items", "gecos_item", "gecos_name",
  "gecos_reason", "general_entry", "general_items", "general_item",
  "general_away_count", "general_away_time", "general_max_monitor",
  "general_whowas_history_length", "general_cycle_on_host_change",
  "general_dline_min_cidr", "general_dline_min_cidr6",
  "general_kline_min_cidr", "general_kline_min_cidr6",
  "general_kill_chase_time_limit", "general_failed_oper_notice",
  "general_anti_nick_flood", "general_max_nick_time",
  "general_max_nick_changes", "general_max_accept",
  "general_max_away_length", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_invisible_on_connect", "general_warn_no_connect_block",
  "general_stats_e_disabled", "general_stats_m_oper_only",
  "general_stats_o_oper_only", "general_stats_P_oper_only",
  "general_stats_u_oper_only", "general_stats_k_oper_only",
  "general_stats_i_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_specials_in_ident",
  "general_max_targets", "general_ping_cookie", "general_disable_auth",
  "general_disable_dns", "general_throttle_count", "general_throttle_time",
  "general_oper_umodes", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_default_floodtime", "general_cloak_enabled",
  "general_cloak_cidr_len_ipv4", "general_cloak_cidr_len_ipv6",
  "general_cloak_num_bits", "general_cloak_secret", "general_cloak_suffix",
  "general_ident_timeout", "channel_entry", "channel_items",
  "channel_item", "channel_enable_extbans", "channel_enable_owner",
  "channel_enable_admin", "channel_disable_fake_channels",
  "channel_invite_client_count", "channel_invite_client_time",
  "channel_invite_delay_channel", "channel_invite_expire_time",
  "channel_knock_client_count", "channel_knock_client_time",
  "channel_knock_delay_channel", "channel_max_channels",
  "channel_max_invites", "channel_max_bans", "channel_max_bans_large",
  "channel_max_kick_length", "channel_default_join_flood_count",
  "channel_default_join_flood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_flatten_links_delay", "serverhide_flatten_links_file",
  "serverhide_disable_remote_commands", "serverhide_hide_servers",
  "serverhide_hide_services", "serverhide_hidden_name",
  "serverhide_hidden", "serverhide_hide_server_ips", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-1066)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-131)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1066,   693, -1066,  -197,  -187,  -185, -1066, -1066, -1066,  -174,
   -1066,  -168, -1066, -1066, -1066,  -153,  -154, -1066, -1066, -1066,
    -152,  -146, -1066,  -135, -1066,  -133, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066,   334,   833,  -132,  -130,  -120,    23,  -105,
     414,   -81,   -67,   -57,   -54,   -41,   -45,   -40,   -30,   625,
     451,    -9,    10,    -8,    19,    -7,     8,    42,    50,    57,
      16, -1066, -1066, -1066, -1066, -1066,    69,    75,    78,    82,
      90,    94,   100,   103,   105,   107,   108,   109,   114,   115,
     118,   119,   120,   122,   197, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066,   654,   638,     6, -1066,   123,    74,
   -1066, -1066,    22, -1066,   124,   131,   134,   135,   139,   142,
     144,   145,   146,   147,   150,   152,   153,   156,   157,   158,
     159,   160,   165,   166,   170,   172,   174,   183,   184,   185,
     186,   193,   194,   201,   209,   211,   215,   217,   218,   224,
     225,   228,   229,   231,   234,   236,   237,   238,   239,   242,
     243,   244,   246,   247,   255,   256,   258,    88, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066,   331,     5,   364,   137,    13,   261,   180,   403,
      32, -1066,   260,   263,   265,   269,   273,   280,   281,   282,
     283,     4, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066,   277,   284,   291,   292,   297,   299,   300,   301,
     302,   304,   307,   308,   310,   312,   320,   321,   322,   323,
     199, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,    71,
     278,   327,    87, -1066, -1066, -1066,    62,    24, -1066,   330,
      37, -1066, -1066,    46, -1066,    96,   102,   141,   311, -1066,
     200,   264,   361,   362,   363,   365,   337,   264,   264,   264,
     341,   264,   264,   342,   345,   348,   349,   366,   367, -1066,
     368,   372,   374,   376, -1066,   377,   379,   380,   382,   383,
     384,   387,   388,   389,   390,   392,    49, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066,   396,   398,   399,   401,   402,   409,   411,
   -1066,   412,   415,   416,   417,   418,   419,   420,   421,   275,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066,   423,   426,    45,
   -1066, -1066, -1066,   407,   431, -1066, -1066,   434,   440,    17,
   -1066, -1066, -1066,   391,   264,   444,   264,   264,   394,   445,
     446,   447,   449,   450,   481,   458,   264,   492,   493,   468,
     469,   498,   264,   500,   264,   474,   480,   483,   485,   486,
     488,   264,   489,   494,   495,   523,   499,   524,   264,   264,
     527,   529,   504,   532,   533,   534,   535,   536,   537,   539,
     513,   264,   264,   264,   542,   517,   519, -1066,   528,   515,
     520, -1066,   525,   530,   531,   541,   543,     2, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,   545,   546,
      31, -1066, -1066, -1066,   538,   547,   551, -1066,   554, -1066,
     126, -1066, -1066, -1066, -1066, -1066, -1066,   360, -1066, -1066,
   -1066,   557,   556,   558,    30, -1066, -1066, -1066,   559,   560,
     561, -1066,   562,   564,   565,   566,   567,   568,   569,   163,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066,   572,   571,   573,   574,    21, -1066, -1066, -1066, -1066,
     602,   608,   264,   585,   612,   587,   614,   615,   616,   590,
   -1066, -1066,   540,   593,   620,   596,   597,   598,   600,   601,
     603,   606,   607,   610,   611,   619,   622,   623,   627,   595,
   -1066,   618,   604, -1066,    98, -1066, -1066, -1066, -1066,   628,
     626, -1066,   629,   631,   630,   633,   641,   642,    29, -1066,
   -1066, -1066, -1066, -1066,   635,   640, -1066,   647,   652, -1066,
     655,    92, -1066, -1066, -1066, -1066,   658,   659,   661, -1066,
     662,  -112,   663,   664,   665,   666,   667,   669,   670,   671,
     673,   674,   679,   680,   681,   682,   683,   684,   685, -1066,
   -1066,   687,   688,   264,   686,   690,   264,   694,   264,   696,
     697,   698,   699,   264,   700,   700,   695, -1066, -1066,   705,
    -145,   708,   656,   709,   710,   707,   712,   713,   714,   716,
     717,   264,   718,   719,   720, -1066,   721,   723,   722, -1066,
     724, -1066,   725,   727,   726, -1066,   728,   729,   730,   731,
     732,   733,   734,   735,   736,   737,   738,   739,   740,   741,
     742,   743,   744,   745,   746,   747,   748,   749,   750,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   761,
     762,   763,   764,   765,   766,   767,   768,   769,   770,   771,
     772,   773,   774,   775,   776,   777,   778,   779,   780, -1066,
   -1066,   783,   810,   781,   786,   787,   789,   790,   791,   785,
   -1066,   792,   793,   794, -1066, -1066,   795,   797,   796,   798,
     799, -1066,   137, -1066,   802,   803,   804, -1066, -1066,   805,
     820,   800,   807,   808,   809,   811,   824,   812,   813,   814,
   -1066, -1066,   815,   817,   818,   819, -1066,   821,   822,   823,
     825,   826,   827,   828,   829,   830, -1066,   831,   832,   834,
     835,   836,   837,   838,   839,   840,   841,   842,   843,   844,
     845,   846,   847,   848, -1066, -1066,   851,   806,   850, -1066,
     852, -1066,   182, -1066,   853,   855,   856,   857,   858, -1066,
     859, -1066, -1066,   862,   816,   863,   864, -1066, -1066, -1066,
   -1066, -1066,   264,   264,   264,   264,   264,   264,   264, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,   865,   866,
     867,   -60,   868,   869,   870,   871,   872,   873,   874,   875,
     876,     3,   877,   878, -1066,   879,   880,   881,   882,   883,
     884,   885,    11,   886,   887,   888,   889,   890,   891,   892,
     893, -1066,   894,   895, -1066, -1066,   896,   897, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066,   898,   899,   276,   900,   901,   902,   903,   904,
   -1066,   905,   906, -1066,   907,   908,   309,   430,   526, -1066,
   -1066, -1066,   909,   910, -1066,   911,   912,   522,   913,   914,
     915,   916,   917,   918,   919, -1066,   920,   921,   922, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066,   923,   660, -1066, -1066,
     924,   854,   860, -1066,   169, -1066, -1066, -1066, -1066,   925,
     926,   927,   928, -1066, -1066,   929,   672,   930, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066,  -179, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066,   700,   700,   700, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,  -177, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066,  -158, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,  -149,
   -1066,   932,   798,   933, -1066, -1066, -1066, -1066, -1066, -1066,
     715, -1066,   931,   934, -1066,   935, -1066,   936,   937, -1066,
   -1066,   938, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066,  -144, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066,  -139, -1066, -1066,   944,
    -173,   861,   943, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,   -19,
   -1066, -1066, -1066,   -60, -1066, -1066, -1066, -1066,    11, -1066,
     276, -1066,   309, -1066, -1066, -1066,  1018,   617,  1021,   677,
     940,  1022,  1030, -1066,   522, -1066,   660,   945,   946,   947,
     381, -1066, -1066,   672, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,   948, -1066,
   -1066
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   208,   370,   420,     0,
     435,     0,   274,   411,   248,     0,     0,   101,   151,   307,
       0,     0,   348,     0,   110,     0,   324,     3,     4,     5,
      13,     6,    25,    26,     7,     8,    10,    11,    12,    15,
      16,    17,    18,    19,    20,    21,    22,    24,    23,     9,
      14,    27,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    96,    95,   575,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   556,   572,   573,   574,   571,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   557,
     558,   568,   569,   570,     0,     0,     0,   433,     0,     0,
     431,   432,     0,   500,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   446,   447,
     448,   491,   454,   492,   486,   487,   488,   489,   458,   449,
     450,   451,   452,   453,   473,   455,   456,   457,   459,   460,
     490,   464,   465,   466,   467,   463,   462,   468,   475,   476,
     469,   470,   471,   461,   472,   483,   484,   485,   481,   482,
     474,   479,   480,   477,   478,   493,   494,   495,   496,   497,
     498,   499,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   606,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   596,   597,   598,   599,   600,   601,   602,   604,
     603,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    69,    67,    65,    70,    71,    72,    66,    56,
      68,    58,    59,    60,    61,    62,    63,    64,    57,     0,
       0,     0,     0,   125,   126,   127,     0,     0,   322,     0,
       0,   320,   321,     0,    97,     0,     0,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   555,
       0,     0,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   211,   212,   215,
     217,   218,   219,   220,   221,   222,   223,   213,   214,   216,
     224,   225,   226,     0,     0,     0,     0,     0,     0,     0,
     400,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     373,   374,   375,   376,   377,   378,   379,   380,   382,   381,
     384,   388,   385,   386,   387,   383,   426,     0,     0,     0,
     423,   424,   425,     0,     0,   430,   441,     0,     0,     0,
     438,   439,   440,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   445,     0,     0,
       0,   291,     0,     0,     0,     0,     0,     0,   277,   278,
     279,   280,   285,   281,   282,   283,   284,   417,     0,     0,
       0,   414,   415,   416,     0,     0,     0,   250,     0,   262,
       0,   260,   261,   263,   264,    52,    51,    48,    50,    46,
      45,     0,     0,     0,     0,   104,   105,   106,     0,     0,
       0,   175,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   155,   156,   157,   158,   161,   162,   163,   160,   159,
     164,     0,     0,     0,     0,     0,   310,   311,   312,   313,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     595,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,   356,     0,   351,   352,   353,   128,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,   113,
     114,   116,   115,   117,     0,     0,   319,     0,     0,   334,
       0,     0,   327,   328,   329,   330,     0,     0,     0,    91,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   554,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   210,   389,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   372,     0,     0,     0,   422,
       0,   429,     0,     0,     0,   437,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   444,
     286,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,     0,     0,   413,   265,     0,     0,     0,     0,
       0,   259,     0,   107,     0,     0,     0,   103,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   314,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   594,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,   354,     0,     0,     0,   350,
       0,   123,     0,   118,     0,     0,     0,     0,     0,   112,
       0,   318,   331,     0,     0,     0,     0,   326,   100,    99,
      98,   592,    29,    29,    29,    29,    29,    29,    29,    31,
      30,   593,   579,   578,   576,   577,   580,   581,   582,   583,
     584,   585,   586,   589,   590,   587,   588,   591,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,     0,     0,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   371,     0,     0,   421,   434,     0,     0,   436,   512,
     517,   501,   502,   530,   547,   548,   549,   550,   551,   552,
     505,   545,   546,   538,   539,   506,   507,   511,   553,   520,
     510,   508,   509,   515,   516,   503,   514,   513,   536,   543,
     544,   534,   542,   531,   529,   532,   537,   533,   535,   522,
     528,   527,   523,   524,   525,   526,   540,   541,   519,   518,
     521,   504,     0,     0,     0,     0,     0,     0,     0,     0,
     275,     0,     0,   412,     0,     0,     0,   270,   266,   269,
     249,    49,     0,     0,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,     0,     0,   308,
     610,   607,   608,   609,   614,   613,   615,   611,   612,    86,
      83,    90,    82,    87,    88,    89,    81,    85,    84,    75,
      74,    77,    78,    76,    79,    80,     0,     0,   349,   129,
       0,     0,     0,   141,     0,   133,   134,   136,   135,     0,
       0,     0,     0,   111,   323,     0,     0,     0,   325,    32,
      33,    34,    35,    36,    37,    38,   237,   238,   232,   247,
     246,     0,   245,   233,   241,   234,   240,   228,   239,   231,
     230,   229,    39,    39,    39,    41,    40,   235,   236,   395,
     398,   399,   409,   406,   391,   407,   404,   405,     0,   403,
     408,   390,   397,   394,   393,   392,   396,   410,   427,   428,
     442,   443,   289,   290,   299,   295,   296,   298,   303,   300,
     301,   302,   297,     0,   294,   288,   306,   305,   304,   287,
     419,   418,   273,   272,   257,   258,   255,   256,   254,     0,
     253,     0,     0,     0,   108,   109,   173,   170,   195,   206,
     182,   191,     0,   180,   185,     0,   200,     0,   194,   198,
     204,   184,   187,   196,   197,   201,   192,   199,   188,   205,
     190,   186,   189,     0,   178,   166,   168,   174,   171,   172,
     167,   169,   317,   315,   316,   355,   360,   366,   369,   362,
     368,   363,   367,   365,   361,   364,     0,   359,   137,     0,
       0,     0,     0,   132,   120,   119,   121,   122,   332,   338,
     344,   347,   340,   346,   341,   345,   343,   339,   342,     0,
     337,   333,   243,     0,    42,    43,    44,   401,     0,   292,
       0,   251,     0,   271,   268,   267,     0,     0,     0,     0,
       0,     0,     0,   176,     0,   357,     0,     0,     0,     0,
       0,   131,   335,     0,   244,   402,   293,   252,   181,   203,
     179,   207,   202,   193,   183,   177,   358,   138,   140,   139,
     149,   148,   144,   146,   150,   147,   143,   145,     0,   336,
     142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1066, -1066, -1066,  -275,  -329, -1065,  -674, -1066, -1066, -1066,
   -1066,   -22, -1066, -1066,   477, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066,   963, -1066, -1066, -1066, -1066, -1066,
   -1066,   369, -1066, -1066, -1066, -1066, -1066,   325, -1066, -1066,
   -1066, -1066, -1066, -1066,   456, -1066, -1066, -1066, -1066,   -96,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,   502, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066,  -206, -1066, -1066, -1066,   689, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066,  -169, -1066, -1066, -1066, -1066, -1066,   -62,
   -1066,   668, -1066, -1066, -1066,    33, -1066, -1066, -1066, -1066,
   -1066,   692, -1066, -1066, -1066, -1066, -1066, -1066, -1066,   -59,
   -1066, -1066, -1066, -1066, -1066, -1066,   621, -1066, -1066, -1066,
   -1066, -1066,   939, -1066, -1066, -1066, -1066,   552, -1066, -1066,
   -1066, -1066, -1066,   -79, -1066, -1066, -1066,   578, -1066, -1066,
   -1066, -1066,   -69, -1066, -1066, -1066,   801, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,   -48,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,   691, -1066,
   -1066, -1066, -1066, -1066,   784, -1066, -1066, -1066, -1066,  1062,
   -1066, -1066, -1066, -1066,   782, -1066, -1066, -1066, -1066,  1005,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066,  1089, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066,   941, -1066, -1066, -1066,
   -1066, -1066, -1066, -1066, -1066, -1066
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   869,   870,  1095,  1096,    28,    29,   246,
     527,   528,    30,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    31,    80,    81,    82,    83,    84,    32,    66,
     534,   535,   536,   537,    33,    73,   618,   619,   620,   621,
     622,   623,    34,   312,   313,   314,   315,   316,  1054,  1055,
    1056,  1057,  1058,  1211,  1288,    35,    67,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   791,
    1183,  1184,    36,    55,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   664,  1081,  1082,    37,    63,   519,   778,  1149,  1150,
     520,   521,   522,  1153,   998,   999,   523,   524,    38,    61,
     497,   498,   499,   500,   501,   502,   503,   763,  1133,  1134,
     504,   505,   506,    39,    68,   565,   566,   567,   568,   569,
      40,   320,   321,   322,    41,    75,   631,   632,   633,   634,
     635,   854,  1229,  1230,    42,    71,   604,   605,   606,   607,
     837,  1206,  1207,    43,    56,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   685,  1108,  1109,
     411,   412,   413,   414,   415,    44,    62,   510,   511,   512,
     513,    45,    57,   419,   420,   421,   422,    46,   129,   130,
     131,    47,    59,   429,   430,   431,   432,    48,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    49,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,    50,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     902,   903,   642,   488,  1079,   251,   507,   416,   648,   649,
     650,   310,   652,   653,  1092,  1093,  1094,    76,   426,  1106,
     318,   489,   561,   426,   127,   613,  1258,  1234,  1235,  1236,
     613,   531,   507,   561,    51,    52,   906,   907,   318,   862,
     863,   864,   865,   866,   867,   868,   416,   627,   252,    53,
     350,    54,  1232,   490,  1237,    77,  1233,   901,  1238,   253,
     254,   255,    58,    78,   256,   257,   351,   352,    60,   258,
     259,   260,   601,  1239,   562,   127,    64,  1240,   353,    65,
    1080,   491,  1241,   417,    69,   562,  1242,  1253,   310,   133,
      70,  1254,  1255,   627,   134,   135,  1256,   136,   137,   601,
     128,    72,   138,    74,   124,   707,   125,   709,   710,   139,
     140,   141,   142,   143,   144,   563,   126,   719,   641,   145,
     146,   147,   417,   725,   532,   727,   563,   514,   354,   148,
     149,   132,   734,   150,   151,    79,   427,   492,   319,   741,
     742,   427,   152,   614,   493,   494,   508,   418,   614,   355,
     356,   128,   754,   755,   756,   242,   319,   357,   428,   153,
     154,   358,   564,   428,   538,   628,   495,   525,   359,   243,
    1050,   155,   508,   564,   156,   157,   360,   361,   362,   244,
     245,   531,   539,  1050,   158,   159,   418,   363,   247,  -130,
     602,   248,   160,   161,   515,   162,   249,   163,    85,   615,
     272,   164,   165,   516,   615,   517,   250,  1107,   364,   533,
     616,   628,  1262,   166,   540,   616,  1263,   602,   167,   617,
     168,   169,   170,   496,   617,   171,   509,   309,   317,   323,
     311,    86,    87,   901,   769,   273,   579,   365,   274,   324,
      88,   612,   541,   809,   529,    89,    90,    91,   328,   704,
     172,   173,   509,   805,   174,   175,   176,   177,   178,   179,
     180,   848,   786,   773,   629,   518,  -130,   630,   275,   625,
      92,    93,    94,    95,   532,   325,   383,   698,   384,   276,
     385,   676,   542,   326,   526,    96,    97,    98,  1051,   603,
     327,  1124,   181,   182,   386,    99,   100,   101,   543,   102,
     103,  1051,   330,   183,   184,   277,   424,   311,   331,   278,
     629,   332,   185,   630,   186,   333,   603,   279,   280,   610,
     486,   281,   282,   334,   856,   636,   387,   335,  1125,  1144,
     838,   637,   488,   336,   890,    76,   337,   893,   338,   895,
     339,   340,   341,   388,   900,   389,  1145,   342,   343,   283,
     489,   344,   345,   346,   390,   347,   423,   433,   780,   533,
     544,  1126,   918,  1052,   434,   514,   391,   435,   436,  1146,
     638,   545,   437,    77,   546,   438,  1052,   439,   440,   441,
     442,    78,   490,   443,   547,   444,   445,  1053,   548,   446,
     447,   448,   449,   450,   392,   799,  1127,  1128,   451,   452,
    1053,  1212,  1129,   453,   538,   454,   284,   455,   285,   286,
     491,   287,   288,   289,   393,   133,   456,   457,   458,   459,
     134,   135,   539,   136,   137,  1130,   460,   461,   138,   348,
     640,   599,   515,   394,   462,   139,   140,   141,   142,   143,
     144,   516,   463,   517,   464,   145,   146,   147,   465,   395,
     466,   467,   272,    79,   540,   148,   149,   468,   469,   150,
     151,   470,   471,  1280,   472,  1281,   492,   473,   152,   474,
     475,   476,   477,   493,   494,   478,   479,   480,  1131,   481,
     482,   396,   541,   397,   398,   153,   154,   273,   483,   484,
     274,   485,   530,   570,   641,   495,   571,   155,   572,  1147,
     156,   157,   573,   518,  1132,  1148,   574,   694,   581,   608,
     158,   159,  1282,   575,   576,   577,   578,   582,   160,   161,
     275,   162,   542,   163,   583,   584,  1158,   164,   165,  1283,
     585,   276,   586,   587,   588,   589,  1259,   590,   543,   166,
     591,   592,   639,   593,   167,   594,   168,   169,   170,  1159,
    1160,   171,   496,   595,   596,   597,   598,   277,  1284,  1285,
     609,   278,  1161,   624,   643,   644,   645,   647,   646,   279,
     280,   651,   654,   281,   282,   655,   172,   173,   656,   657,
     174,   175,   176,   177,   178,   179,   180,  1069,  1070,  1071,
    1072,  1073,  1074,  1075,   706,   782,   658,   711,   659,   660,
     544,   283,  1286,  1162,  1163,   661,  1164,   662,  1287,   663,
     665,   545,   666,   667,   546,   668,   669,   670,   181,   182,
     671,   672,   673,   674,   547,   675,   251,   678,   548,   183,
     184,   679,   680,  1165,   681,   682,   700,  1166,   185,   383,
     186,   384,   683,   385,   684,   686,  1167,  1151,   687,   688,
     689,   690,   691,   692,   693,   350,   696,   386,   284,   697,
     285,   286,   701,   287,   288,   289,  1168,   702,  1169,   252,
    1170,   351,   352,   703,   708,   712,   713,   714,   715,   716,
     253,   254,   255,   353,   717,   256,   257,  1171,   718,   387,
     258,   259,   260,     2,     3,   720,   721,     4,   722,   723,
    1172,   724,  1173,   726,   728,  1174,   388,  1175,   389,     5,
     729,  1176,     6,   730,  1177,   731,   732,   390,   733,   735,
    1178,     7,  1179,  1180,   736,   737,   738,   740,   739,   391,
     743,     8,   744,   354,   745,   746,   747,   748,   749,   750,
     751,  1181,   752,   753,  1196,   757,     9,   758,   761,  1182,
     759,    10,    11,   762,   355,   356,  1219,   392,   764,   760,
    1001,  1152,   357,   765,   766,  1269,   358,   600,   611,   775,
     817,    12,  1271,   359,   767,    13,   768,   393,   771,   772,
     776,   360,   361,   362,   777,    14,    15,   779,   783,   784,
     788,   785,   363,   789,   790,   792,   394,   793,   794,   795,
     796,   797,   798,   801,   802,   807,   803,   804,  1197,    16,
      17,   808,   395,   364,   810,   811,   812,   813,   814,   815,
    1220,   816,   818,   819,    18,   820,   834,   821,   822,   823,
     824,   840,   825,  1198,    85,   826,   827,   836,  1199,   828,
     829,    19,   365,  1200,   396,  1221,   397,   398,   830,   835,
    1222,   831,   832,    20,    21,  1223,   833,   841,  1201,   909,
    1202,  1203,   843,   844,   850,   842,   845,    86,    87,    22,
    1224,   851,  1225,  1226,   846,   847,    88,    23,   852,  1204,
      24,    89,    90,    91,    25,   853,    26,  1205,   855,   858,
     859,  1227,   860,   861,   871,   872,   873,   874,   875,  1228,
     876,   877,   878,   787,   879,   880,    92,    93,    94,    95,
     881,   882,   883,   884,   885,   886,   887,   888,   889,   891,
     892,    96,    97,    98,   894,   896,   904,   897,   898,   899,
     901,    99,   100,   101,   905,   102,   103,   908,   910,   911,
     912,   913,   914,   849,   915,   916,   917,   919,   920,  1246,
     922,   921,   923,   924,   926,   925,   927,   928,  1213,   929,
     930,   931,   932,   933,   934,   935,   936,   937,   938,   939,
     940,   941,   942,   943,   944,   945,   946,   947,   948,   949,
     950,   951,   952,   953,   954,   955,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   967,   968,   969,
     970,   971,   972,   973,   974,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   985,   990,   986,   987,   988,
     989,   991,   992,  1006,   994,   993,   995,  1012,   997,   996,
    1000,  1002,  1003,  1007,  1005,  1004,  1008,  1009,  1010,  1047,
    1011,  1013,  1014,   329,  1016,  1015,  1017,  1018,  1275,  1066,
    1019,   800,  1020,  1021,  1022,   677,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1264,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,
    1046,  1048,  1059,  1049,  1060,  1061,  1062,  1209,  1272,  1063,
    1064,  1065,  1067,  1210,  1260,  1068,  1076,  1077,  1078,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1097,  1098,
    1099,  1100,  1101,  1102,  1103,  1104,  1105,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1154,  1155,  1156,  1157,  1185,  1186,  1187,  1188,  1189,  1190,
    1191,  1192,  1193,  1194,  1195,  1208,  1214,  1215,  1216,  1217,
    1218,  1231,  1243,  1268,  1245,  1247,  1270,  1273,  1248,  1249,
    1250,  1251,  1252,  1257,  1261,  1274,  1277,  1278,  1279,  1290,
    1267,  1266,   839,   857,  1289,  1244,   806,  1276,   781,   770,
    1265,   425,   487,   349,     0,     0,     0,     0,     0,     0,
     695,   774,   580,   699,     0,     0,     0,     0,     0,     0,
       0,   705,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   626
};

static const yytype_int16 yycheck[] =
{
     674,   675,   331,     1,    64,     1,     1,     1,   337,   338,
     339,     1,   341,   342,    11,    12,    13,     1,     1,     8,
       1,    19,     1,     1,     1,     1,   199,  1092,  1093,  1094,
       1,     1,     1,     1,   231,   232,   181,   182,     1,   151,
     152,   153,   154,   155,   156,   157,     1,     1,    44,   236,
       1,   236,   231,    51,   231,    39,   235,   230,   235,    55,
      56,    57,   236,    47,    60,    61,    17,    18,   236,    65,
      66,    67,     1,   231,    53,     1,   229,   235,    29,   233,
     140,    79,   231,    77,   236,    53,   235,   231,     1,     1,
     236,   235,   231,     1,     6,     7,   235,     9,    10,     1,
      77,   236,    14,   236,   236,   434,   236,   436,   437,    21,
      22,    23,    24,    25,    26,    94,   236,   446,   230,    31,
      32,    33,    77,   452,    94,   454,    94,     1,    79,    41,
      42,   236,   461,    45,    46,   119,   119,   135,   119,   468,
     469,   119,    54,   119,   142,   143,   141,   141,   119,   100,
     101,    77,   481,   482,   483,   236,   119,   108,   141,    71,
      72,   112,   141,   141,     1,   119,   164,    30,   119,   236,
       1,    83,   141,   141,    86,    87,   127,   128,   129,   236,
     234,     1,    19,     1,    96,    97,   141,   138,   229,   179,
     119,   236,   104,   105,    68,   107,   236,   109,     1,   175,
       1,   113,   114,    77,   175,    79,   236,   196,   159,   179,
     186,   119,   231,   125,    51,   186,   235,   119,   130,   195,
     132,   133,   134,   221,   195,   137,   221,   236,   236,   236,
     220,    34,    35,   230,   232,    36,   232,   188,    39,   231,
      43,   179,    79,   572,   231,    48,    49,    50,   232,   232,
     162,   163,   221,   232,   166,   167,   168,   169,   170,   171,
     172,   232,   232,   232,   218,   139,   179,   221,    69,   232,
      73,    74,    75,    76,    94,   233,     1,   232,     3,    80,
       5,   232,   119,   233,   147,    88,    89,    90,   119,   218,
     233,    15,   204,   205,    19,    98,    99,   100,   135,   102,
     103,   119,   233,   215,   216,   106,   232,   220,   233,   110,
     218,   233,   224,   221,   226,   233,   218,   118,   119,   232,
     232,   122,   123,   233,   232,   229,    51,   233,    52,    20,
     232,   229,     1,   233,   663,     1,   233,   666,   233,   668,
     233,   233,   233,    68,   673,    70,    37,   233,   233,   150,
      19,   233,   233,   233,    79,   233,   233,   233,   232,   179,
     197,    85,   691,   194,   233,     1,    91,   233,   233,    60,
     229,   208,   233,    39,   211,   233,   194,   233,   233,   233,
     233,    47,    51,   233,   221,   233,   233,   218,   225,   233,
     233,   233,   233,   233,   119,   232,   120,   121,   233,   233,
     218,   232,   126,   233,     1,   233,   207,   233,   209,   210,
      79,   212,   213,   214,   139,     1,   233,   233,   233,   233,
       6,     7,    19,     9,    10,   149,   233,   233,    14,   232,
     230,   232,    68,   158,   233,    21,    22,    23,    24,    25,
      26,    77,   233,    79,   233,    31,    32,    33,   233,   174,
     233,   233,     1,   119,    51,    41,    42,   233,   233,    45,
      46,   233,   233,    82,   233,    84,   135,   233,    54,   233,
     233,   233,   233,   142,   143,   233,   233,   233,   202,   233,
     233,   206,    79,   208,   209,    71,    72,    36,   233,   233,
      39,   233,   231,   233,   230,   164,   233,    83,   233,   190,
      86,    87,   233,   139,   228,   196,   233,   232,   231,   231,
      96,    97,   131,   233,   233,   233,   233,   233,   104,   105,
      69,   107,   119,   109,   233,   233,     4,   113,   114,   148,
     233,    80,   233,   233,   233,   233,  1210,   233,   135,   125,
     233,   233,   231,   233,   130,   233,   132,   133,   134,    27,
      28,   137,   221,   233,   233,   233,   233,   106,   177,   178,
     233,   110,    40,   233,   203,   203,   203,   230,   203,   118,
     119,   230,   230,   122,   123,   230,   162,   163,   230,   230,
     166,   167,   168,   169,   170,   171,   172,   862,   863,   864,
     865,   866,   867,   868,   203,   235,   230,   203,   231,   231,
     197,   150,   221,    81,    82,   233,    84,   233,   227,   233,
     233,   208,   233,   233,   211,   233,   233,   233,   204,   205,
     233,   233,   233,   233,   221,   233,     1,   231,   225,   215,
     216,   233,   233,   111,   233,   233,   229,   115,   224,     1,
     226,     3,   233,     5,   233,   233,   124,   217,   233,   233,
     233,   233,   233,   233,   233,     1,   233,    19,   207,   233,
     209,   210,   231,   212,   213,   214,   144,   233,   146,    44,
     148,    17,    18,   233,   230,   230,   230,   230,   229,   229,
      55,    56,    57,    29,   203,    60,    61,   165,   230,    51,
      65,    66,    67,     0,     1,   203,   203,     4,   230,   230,
     178,   203,   180,   203,   230,   183,    68,   185,    70,    16,
     230,   189,    19,   230,   192,   230,   230,    79,   230,   230,
     198,    28,   200,   201,   230,   230,   203,   203,   229,    91,
     203,    38,   203,    79,   230,   203,   203,   203,   203,   203,
     203,   219,   203,   230,    84,   203,    53,   230,   233,   227,
     231,    58,    59,   233,   100,   101,    84,   119,   233,   231,
     782,   235,   108,   233,   233,   148,   112,   290,   312,   231,
     230,    78,    95,   119,   233,    82,   233,   139,   233,   233,
     233,   127,   128,   129,   233,    92,    93,   233,   231,   233,
     231,   233,   138,   233,   233,   233,   158,   233,   233,   233,
     233,   233,   233,   231,   233,   203,   233,   233,   148,   116,
     117,   203,   174,   159,   229,   203,   229,   203,   203,   203,
     148,   231,   229,   203,   131,   229,   231,   230,   230,   229,
     229,   203,   229,   173,     1,   229,   229,   233,   178,   229,
     229,   148,   188,   183,   206,   173,   208,   209,   229,   231,
     178,   229,   229,   160,   161,   183,   229,   231,   198,   203,
     200,   201,   231,   233,   229,   236,   233,    34,    35,   176,
     198,   231,   200,   201,   233,   233,    43,   184,   231,   219,
     187,    48,    49,    50,   191,   233,   193,   227,   233,   231,
     231,   219,   231,   231,   231,   231,   231,   231,   231,   227,
     231,   231,   231,   534,   231,   231,    73,    74,    75,    76,
     231,   231,   231,   231,   231,   231,   231,   230,   230,   233,
     230,    88,    89,    90,   230,   229,   231,   230,   230,   230,
     230,    98,    99,   100,   229,   102,   103,   229,   229,   229,
     233,   229,   229,   618,   230,   229,   229,   229,   229,   234,
     229,   231,   229,   231,   229,   231,   229,   231,  1054,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   229,   203,   233,   229,   231,   230,   229,   229,
     229,   229,   229,   203,   229,   231,   229,   203,   230,   233,
     231,   229,   229,   233,   229,   231,   229,   229,   229,   233,
     229,   229,   229,    80,   229,   231,   229,   229,  1254,   233,
     231,   549,   231,   231,   231,   366,   231,   231,   231,   231,
     231,   231,   231,   231,  1233,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     229,   231,   229,   231,   229,   229,   229,   233,   148,   231,
     231,   229,   229,   233,   233,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   230,   145,   231,   234,   145,   145,   234,   234,
     234,   234,   234,   229,   231,   145,   231,   231,   231,   231,
    1242,  1240,   604,   631,  1263,  1152,   565,  1256,   520,   497,
    1238,   129,   187,   104,    -1,    -1,    -1,    -1,    -1,    -1,
     399,   510,   261,   419,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   320
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   238,     0,     1,     4,    16,    19,    28,    38,    53,
      58,    59,    78,    82,    92,    93,   116,   117,   131,   148,
     160,   161,   176,   184,   187,   191,   193,   239,   244,   245,
     249,   269,   275,   281,   289,   302,   319,   341,   355,   370,
     377,   381,   391,   400,   422,   428,   434,   438,   444,   500,
     521,   231,   232,   236,   236,   320,   401,   429,   236,   439,
     236,   356,   423,   342,   229,   233,   276,   303,   371,   236,
     236,   392,   236,   282,   236,   382,     1,    39,    47,   119,
     270,   271,   272,   273,   274,     1,    34,    35,    43,    48,
      49,    50,    73,    74,    75,    76,    88,    89,    90,    98,
      99,   100,   102,   103,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   236,   236,   236,     1,    77,   435,
     436,   437,   236,     1,     6,     7,     9,    10,    14,    21,
      22,    23,    24,    25,    26,    31,    32,    33,    41,    42,
      45,    46,    54,    71,    72,    83,    86,    87,    96,    97,
     104,   105,   107,   109,   113,   114,   125,   130,   132,   133,
     134,   137,   162,   163,   166,   167,   168,   169,   170,   171,
     172,   204,   205,   215,   216,   224,   226,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   236,   236,   236,   234,   246,   229,   236,   236,
     236,     1,    44,    55,    56,    57,    60,    61,    65,    66,
      67,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,     1,    36,    39,    69,    80,   106,   110,   118,
     119,   122,   123,   150,   207,   209,   210,   212,   213,   214,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   236,
       1,   220,   290,   291,   292,   293,   294,   236,     1,   119,
     378,   379,   380,   236,   231,   233,   233,   233,   232,   271,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   232,   502,
       1,    17,    18,    29,    79,   100,   101,   108,   112,   119,
     127,   128,   129,   138,   159,   188,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,     1,     3,     5,    19,    51,    68,    70,
      79,    91,   119,   139,   158,   174,   206,   208,   209,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   417,   418,   419,   420,   421,     1,    77,   141,   430,
     431,   432,   433,   233,   232,   436,     1,   119,   141,   440,
     441,   442,   443,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   232,   446,     1,    19,
      51,    79,   135,   142,   143,   164,   221,   357,   358,   359,
     360,   361,   362,   363,   367,   368,   369,     1,   141,   221,
     424,   425,   426,   427,     1,    68,    77,    79,   139,   343,
     347,   348,   349,   353,   354,    30,   147,   247,   248,   231,
     231,     1,    94,   179,   277,   278,   279,   280,     1,    19,
      51,    79,   119,   135,   197,   208,   211,   221,   225,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,     1,    53,    94,   141,   372,   373,   374,   375,   376,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   232,
     523,   231,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   232,
     251,     1,   119,   218,   393,   394,   395,   396,   231,   233,
     232,   291,   179,     1,   119,   175,   186,   195,   283,   284,
     285,   286,   287,   288,   233,   232,   379,     1,   119,   218,
     221,   383,   384,   385,   386,   387,   229,   229,   229,   231,
     230,   230,   241,   203,   203,   203,   203,   230,   241,   241,
     241,   230,   241,   241,   230,   230,   230,   230,   230,   231,
     231,   233,   233,   233,   338,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   232,   322,   231,   233,
     233,   233,   233,   233,   233,   414,   233,   233,   233,   233,
     233,   233,   233,   233,   232,   403,   233,   233,   232,   431,
     229,   231,   233,   233,   232,   441,   203,   241,   230,   241,
     241,   203,   230,   230,   230,   229,   229,   203,   230,   241,
     203,   203,   230,   230,   203,   241,   203,   241,   230,   230,
     230,   230,   230,   230,   241,   230,   230,   230,   203,   229,
     203,   241,   241,   203,   203,   230,   203,   203,   203,   203,
     203,   203,   203,   230,   241,   241,   241,   203,   230,   231,
     231,   233,   233,   364,   233,   233,   233,   233,   233,   232,
     358,   233,   233,   232,   425,   231,   233,   233,   344,   233,
     232,   348,   235,   231,   233,   233,   232,   278,   231,   233,
     233,   316,   233,   233,   233,   233,   233,   233,   233,   232,
     305,   231,   233,   233,   233,   232,   373,   203,   203,   241,
     229,   203,   229,   203,   203,   203,   231,   230,   229,   203,
     229,   230,   230,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   231,   231,   233,   397,   232,   394,
     203,   231,   236,   231,   233,   233,   233,   233,   232,   284,
     229,   231,   231,   233,   388,   233,   232,   384,   231,   231,
     231,   231,   151,   152,   153,   154,   155,   156,   157,   240,
     241,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   230,   230,
     241,   233,   230,   241,   230,   241,   229,   230,   230,   230,
     241,   230,   243,   243,   231,   229,   181,   182,   229,   203,
     229,   229,   233,   229,   229,   230,   229,   229,   241,   229,
     229,   231,   229,   229,   231,   231,   229,   229,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   229,   203,   233,   229,   230,   229,   229,   229,
     231,   229,   229,   231,   229,   229,   233,   230,   351,   352,
     231,   248,   229,   229,   231,   229,   203,   233,   229,   229,
     229,   229,   203,   229,   229,   231,   229,   229,   229,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   229,   233,   231,   231,
       1,   119,   194,   218,   295,   296,   297,   298,   299,   229,
     229,   229,   229,   231,   231,   229,   233,   229,   231,   240,
     240,   240,   240,   240,   240,   240,   231,   231,   231,    64,
     140,   339,   340,   231,   231,   231,   231,   231,   231,   231,
     231,   231,    11,    12,    13,   242,   243,   231,   231,   231,
     231,   231,   231,   231,   231,   231,     8,   196,   415,   416,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,    15,    52,    85,   120,   121,   126,
     149,   202,   228,   365,   366,   231,   231,   231,   231,   231,
     231,   231,   231,   231,    20,    37,    60,   190,   196,   345,
     346,   217,   235,   350,   231,   231,   231,   231,     4,    27,
      28,    40,    81,    82,    84,   111,   115,   124,   144,   146,
     148,   165,   178,   180,   183,   185,   189,   192,   198,   200,
     201,   219,   227,   317,   318,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,    84,   148,   173,   178,
     183,   198,   200,   201,   219,   227,   398,   399,   231,   233,
     233,   300,   232,   296,   231,   231,   231,   231,   231,    84,
     148,   173,   178,   183,   198,   200,   201,   219,   227,   389,
     390,   231,   231,   235,   242,   242,   242,   231,   235,   231,
     235,   231,   235,   230,   352,   231,   234,   234,   234,   234,
     234,   234,   234,   231,   235,   231,   235,   229,   199,   243,
     233,   231,   231,   235,   340,   416,   366,   346,   145,   148,
     145,    95,   148,   145,   145,   318,   399,   231,   231,   231,
      82,    84,   131,   148,   177,   178,   221,   227,   301,   390,
     231
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   237,   238,   238,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   240,
     240,   241,   241,   241,   241,   241,   241,   241,   241,   242,
     242,   243,   243,   243,   243,   244,   245,   246,   246,   247,
     247,   248,   248,   249,   250,   250,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   270,   271,   271,   271,   271,   272,   273,
     274,   276,   275,   277,   277,   278,   278,   278,   279,   280,
     282,   281,   283,   283,   284,   284,   284,   284,   284,   285,
     286,   287,   288,   289,   290,   290,   291,   291,   291,   292,
     294,   293,   295,   295,   296,   296,   296,   296,   297,   298,
     298,   300,   299,   301,   301,   301,   301,   301,   301,   301,
     301,   303,   302,   304,   304,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   316,   315,   317,   317,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   320,   319,
     321,   321,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   338,   337,   339,   339,   340,   340,   342,   341,
     344,   343,   345,   345,   346,   346,   346,   346,   346,   347,
     347,   348,   348,   348,   348,   348,   350,   349,   351,   351,
     352,   352,   353,   354,   356,   355,   357,   357,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   359,   360,   361,
     362,   364,   363,   365,   365,   366,   366,   366,   366,   366,
     366,   366,   366,   366,   367,   368,   369,   371,   370,   372,
     372,   373,   373,   373,   373,   374,   375,   376,   377,   378,
     378,   379,   379,   380,   382,   381,   383,   383,   384,   384,
     384,   384,   385,   386,   388,   387,   389,   389,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   392,   391,
     393,   393,   394,   394,   394,   395,   397,   396,   398,   398,
     399,   399,   399,   399,   399,   399,   399,   399,   399,   399,
     401,   400,   402,   402,   403,   403,   403,   403,   403,   403,
     403,   403,   403,   403,   403,   403,   403,   403,   403,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   412,
     414,   413,   415,   415,   416,   416,   417,   418,   419,   420,
     421,   423,   422,   424,   424,   425,   425,   425,   426,   427,
     429,   428,   430,   430,   431,   431,   431,   432,   433,   434,
     435,   435,   436,   436,   437,   439,   438,   440,   440,   441,
     441,   441,   442,   443,   444,   445,   445,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   501,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   522,   523,   523,   523,
     523,   523,   523,   523,   523,   523,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     0,
       1,     2,     3,     3,     3,     4,     4,     0,     2,     3,
       1,     1,     1,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     2,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     5,     2,     1,     1,     1,     2,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     3,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     0,     6,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     2,     0,     5,     3,     1,
       1,     3,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     5,     2,
       1,     1,     1,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     2,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     4,     4,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 29: /* timespec_: %empty  */
#line 405 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3517 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 406 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3523 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 407 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3529 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 408 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3535 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 409 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3541 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 410 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3547 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 411 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3553 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 412 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3559 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 413 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3565 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 416 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3571 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 417 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3577 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 418 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3583 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 419 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3589 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 420 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3595 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 428 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3604 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 438 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3613 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 444 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3621 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 451 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3630 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 455 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3639 "conf_parser.c"
    break;

  case 74: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 488 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3651 "conf_parser.c"
    break;

  case 75: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 497 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = io_strdup(yylval.string);
  }
}
#line 3663 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 506 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = io_strdup(yylval.string);
  }
}
#line 3675 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 515 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = io_strdup(yylval.string);
  }
}
#line 3687 "conf_parser.c"
    break;

  case 78: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 524 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = io_strdup(yylval.string);
  }
}
#line 3699 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 533 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = io_strdup(yylval.string);
  }
}
#line 3711 "conf_parser.c"
    break;

  case 80: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 542 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = io_strdup(yylval.string);
  }
}
#line 3723 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 551 "conf_parser.y"
{
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && ConfigServerInfo.name == NULL)
  {
    if (server_valid_name(yylval.string))
      ConfigServerInfo.name = io_strdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3741 "conf_parser.c"
    break;

  case 82: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 566 "conf_parser.y"
{
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && ConfigServerInfo.sid == NULL)
  {
    if (valid_sid(yylval.string))
      ConfigServerInfo.sid = io_strdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3759 "conf_parser.c"
    break;

  case 83: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 581 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3772 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 591 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    char *p = strchr(yylval.string, ' ');

    if (p)
      *p = '\0';

    io_free(ConfigServerInfo.network_name);
    ConfigServerInfo.network_name = io_strdup(yylval.string);
  }
}
#line 3789 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 605 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3801 "conf_parser.c"
    break;

  case 86: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 614 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 1)
  {
    conf_error_report("default_max_clients too low, setting to 1");
    ConfigServerInfo.default_max_clients = 1;
  }
  else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "default_max_clients too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);

    ConfigServerInfo.default_max_clients = MAXCLIENTS_MAX;
  }
  else
    ConfigServerInfo.default_max_clients = (yyvsp[-1].number);
}
#line 3827 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 637 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 9)
  {
    conf_error_report("max_nick_length too low, setting to 9");
    ConfigServerInfo.max_nick_length = 9;
  }
  else if ((yyvsp[-1].number) > NICKLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
    conf_error_report(buf);

    ConfigServerInfo.max_nick_length = NICKLEN;
  }
  else
    ConfigServerInfo.max_nick_length = (yyvsp[-1].number);
}
#line 3853 "conf_parser.c"
    break;

  case 88: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 660 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigServerInfo.max_topic_length = TOPICLEN;
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3864 "conf_parser.c"
    break;

  case 89: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 668 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3876 "conf_parser.c"
    break;

  case 90: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 677 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3885 "conf_parser.c"
    break;

  case 98: /* admin_name: NAME '=' QSTRING ';'  */
#line 695 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3897 "conf_parser.c"
    break;

  case 99: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 704 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3909 "conf_parser.c"
    break;

  case 100: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 713 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3921 "conf_parser.c"
    break;

  case 101: /* $@1: %empty  */
#line 726 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3930 "conf_parser.c"
    break;

  case 102: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 730 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3947 "conf_parser.c"
    break;

  case 108: /* motd_mask: MASK '=' QSTRING ';'  */
#line 747 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3956 "conf_parser.c"
    break;

  case 109: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 753 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3965 "conf_parser.c"
    break;

  case 110: /* $@2: %empty  */
#line 763 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3974 "conf_parser.c"
    break;

  case 111: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 767 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.command.buf[0] ||
      !block_state.name.buf[0] ||
      !block_state.nick.buf[0] ||
      !block_state.host.buf[0])
    break;

  pseudo_register(block_state.name.buf, block_state.nick.buf, block_state.host.buf,
                  block_state.prepend.buf, block_state.command.buf);
}
#line 3992 "conf_parser.c"
    break;

  case 119: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 785 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 4001 "conf_parser.c"
    break;

  case 120: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 791 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4010 "conf_parser.c"
    break;

  case 121: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 797 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 4019 "conf_parser.c"
    break;

  case 122: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 803 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct nuh_split nuh =
    {
      .nuhmask = yylval.string,
      .nickptr = NULL,
      .userptr = block_state.nick.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.nick.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    nuh_split(&nuh);
  }
}
#line 4041 "conf_parser.c"
    break;

  case 129: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 832 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 4050 "conf_parser.c"
    break;

  case 130: /* $@3: %empty  */
#line 838 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4059 "conf_parser.c"
    break;

  case 131: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 842 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 4072 "conf_parser.c"
    break;

  case 138: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 858 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 4083 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 866 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 4091 "conf_parser.c"
    break;

  case 140: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 869 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 4099 "conf_parser.c"
    break;

  case 141: /* $@4: %empty  */
#line 874 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 4108 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: USER  */
#line 880 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4117 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: OPERATOR  */
#line 884 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4126 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: XLINE  */
#line 888 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4135 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: RESV  */
#line 892 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4144 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: T_DLINE  */
#line 896 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4153 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KLINE  */
#line 900 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4162 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: KILL  */
#line 904 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4171 "conf_parser.c"
    break;

  case 150: /* logging_file_type_item: T_DEBUG  */
#line 908 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4180 "conf_parser.c"
    break;

  case 151: /* $@5: %empty  */
#line 918 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4192 "conf_parser.c"
    break;

  case 152: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 925 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  if (!block_state.rpass.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
  {
    char *s = node->data;

    if (string_is_empty(s))
      continue;

    struct nuh_split nuh =
    {
      .nuhmask = s,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    nuh_split(&nuh);

    struct OperItem *const oper = oper_create();
    oper->name = io_strdup(block_state.name.buf);
    oper->user = io_strdup(block_state.user.buf);
    oper->host = io_strdup(block_state.host.buf);

    if (block_state.cert.buf[0])
      oper->tls_cert_fingerprint = io_strdup(block_state.cert.buf);
    if (block_state.rpass.buf[0])
      oper->password = io_strdup(block_state.rpass.buf);
    if (block_state.whois.buf[0])
      oper->whois_text = io_strdup(block_state.whois.buf);
    if (block_state.modes.buf[0])
      oper->modes = io_strdup(block_state.modes.buf);

    oper->flags = block_state.flags.value;
    oper->oper_privs = block_state.port.value;
    oper->htype = address_parse_netmask(oper->host, &oper->addr, &oper->bits);

    oper_assign_class(oper, block_state.class.buf);
  }
}
#line 4250 "conf_parser.c"
    break;

  case 166: /* oper_name: NAME '=' QSTRING ';'  */
#line 993 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4259 "conf_parser.c"
    break;

  case 167: /* oper_user: USER '=' QSTRING ';'  */
#line 999 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4268 "conf_parser.c"
    break;

  case 168: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1005 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4277 "conf_parser.c"
    break;

  case 169: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1011 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4286 "conf_parser.c"
    break;

  case 170: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1017 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4300 "conf_parser.c"
    break;

  case 171: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1028 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4309 "conf_parser.c"
    break;

  case 172: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1034 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4323 "conf_parser.c"
    break;

  case 173: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4332 "conf_parser.c"
    break;

  case 174: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1051 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4341 "conf_parser.c"
    break;

  case 175: /* $@6: %empty  */
#line 1057 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4350 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: KILL ':' REMOTE  */
#line 1064 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4359 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: KILL  */
#line 1068 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4368 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1072 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4377 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: CONNECT  */
#line 1076 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4386 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1080 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4395 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: SQUIT  */
#line 1084 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4404 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: KLINE  */
#line 1088 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4413 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: UNKLINE  */
#line 1092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4422 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_DLINE  */
#line 1096 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4431 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: T_UNDLINE  */
#line 1100 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4440 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: XLINE  */
#line 1104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4449 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: T_UNXLINE  */
#line 1108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4458 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: DIE  */
#line 1112 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4467 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: T_RESTART  */
#line 1116 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4476 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1120 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4485 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: REHASH  */
#line 1124 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4494 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: ADMIN  */
#line 1128 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4503 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_GLOBOPS  */
#line 1132 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4512 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: T_LOCOPS  */
#line 1136 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4521 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: REMOTEBAN  */
#line 1140 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4530 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: T_SET  */
#line 1144 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4539 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: MODULE  */
#line 1148 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4548 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: T_OPME  */
#line 1152 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4557 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: NICK ':' RESV  */
#line 1156 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4566 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: JOIN ':' RESV  */
#line 1160 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4575 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: RESV  */
#line 1164 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4584 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: T_UNRESV  */
#line 1168 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4593 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: CLOSE  */
#line 1172 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4602 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1176 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4611 "conf_parser.c"
    break;

  case 208: /* $@7: %empty  */
#line 1186 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4627 "conf_parser.c"
    break;

  case 209: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1197 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.class.buf[0])
    break;

  struct ClassItem *class = class_find(block_state.class.buf, false);
  if (class == NULL)
    class = class_make();

  class->active = true;
  io_free(class->name);
  class->name = io_strdup(block_state.class.buf);
  class->ping_freq = block_state.ping_freq.value;
  class->max_perip_local = block_state.max_perip_local.value;
  class->max_perip_global = block_state.max_perip_global.value;
  class->con_freq = block_state.con_freq.value;
  class->max_total = block_state.max_total.value;
  class->max_sendq = block_state.max_sendq.value;
  class->max_recvq = block_state.max_recvq.value;
  class->max_channels = block_state.max_channels.value;

  if (block_state.min_idle.value > block_state.max_idle.value)
  {
    block_state.min_idle.value = 0;
    block_state.max_idle.value = 0;
    block_state.flags.value &= ~CLASS_FLAGS_FAKE_IDLE;
  }

  class->flags = block_state.flags.value;
  class->min_idle = block_state.min_idle.value;
  class->max_idle = block_state.max_idle.value;

  bool diff = (class->cidr_bitlen_ipv4 != block_state.cidr_bitlen_ipv4.value ||
               class->cidr_bitlen_ipv6 != block_state.cidr_bitlen_ipv6.value);
  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;

  if (diff)
    class_ip_limit_rebuild(class);
}
#line 4675 "conf_parser.c"
    break;

  case 228: /* class_name: NAME '=' QSTRING ';'  */
#line 1260 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4684 "conf_parser.c"
    break;

  case 229: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1266 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4693 "conf_parser.c"
    break;

  case 230: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1272 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4702 "conf_parser.c"
    break;

  case 231: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1278 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4711 "conf_parser.c"
    break;

  case 232: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1284 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4720 "conf_parser.c"
    break;

  case 233: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1290 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4729 "conf_parser.c"
    break;

  case 234: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1296 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4738 "conf_parser.c"
    break;

  case 235: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1302 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4747 "conf_parser.c"
    break;

  case 236: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1308 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4757 "conf_parser.c"
    break;

  case 237: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1315 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4766 "conf_parser.c"
    break;

  case 238: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1321 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4775 "conf_parser.c"
    break;

  case 239: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1327 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4784 "conf_parser.c"
    break;

  case 240: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1333 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4796 "conf_parser.c"
    break;

  case 241: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1342 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4808 "conf_parser.c"
    break;

  case 242: /* $@8: %empty  */
#line 1351 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4817 "conf_parser.c"
    break;

  case 246: /* class_flags_item: RANDOM_IDLE  */
#line 1358 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4826 "conf_parser.c"
    break;

  case 247: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1362 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4835 "conf_parser.c"
    break;

  case 248: /* $@9: %empty  */
#line 1372 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4844 "conf_parser.c"
    break;

  case 250: /* $@10: %empty  */
#line 1378 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4852 "conf_parser.c"
    break;

  case 254: /* listen_flags_item: T_TLS  */
#line 1384 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4861 "conf_parser.c"
    break;

  case 255: /* listen_flags_item: HIDDEN  */
#line 1388 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4870 "conf_parser.c"
    break;

  case 256: /* listen_flags_item: T_SERVER  */
#line 1392 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4879 "conf_parser.c"
    break;

  case 257: /* listen_flags_item: CLIENT  */
#line 1396 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4888 "conf_parser.c"
    break;

  case 258: /* listen_flags_item: DEFER  */
#line 1400 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4897 "conf_parser.c"
    break;

  case 266: /* $@11: %empty  */
#line 1408 "conf_parser.y"
                                 { reset_block_state(); }
#line 4903 "conf_parser.c"
    break;

  case 270: /* port_item: NUMBER  */
#line 1413 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_TLS
    if (block_state.flags.value & LISTENER_TLS)
    {
      conf_error_report("TLS not available - port closed");
      break;
    }
#endif
    listener_add((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4921 "conf_parser.c"
    break;

  case 271: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1426 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_TLS
    if (block_state.flags.value & LISTENER_TLS)
    {
      conf_error_report("TLS not available - port closed");
      break;
    }
#endif

    for (int i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      listener_add(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4941 "conf_parser.c"
    break;

  case 272: /* listen_address: IP '=' QSTRING ';'  */
#line 1443 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4950 "conf_parser.c"
    break;

  case 273: /* listen_host: HOST '=' QSTRING ';'  */
#line 1449 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4959 "conf_parser.c"
    break;

  case 274: /* $@12: %empty  */
#line 1459 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4968 "conf_parser.c"
    break;

  case 275: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1463 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
  {
    char *s = node->data;

    if (string_is_empty(s))
      continue;

    struct nuh_split nuh =
    {
      .nuhmask = s,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    nuh_split(&nuh);

    struct MaskItem *conf = conf_make(CONF_CLIENT);
    conf->user = io_strdup(block_state.user.buf);
    conf->host = io_strdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = io_strdup(block_state.rpass.buf);
    if (block_state.name.buf[0])
      conf->name = io_strdup(block_state.name.buf);

    conf->flags = block_state.flags.value;
    conf->port = block_state.port.value;

    conf_assign_class(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
#line 5015 "conf_parser.c"
    break;

  case 287: /* auth_user: USER '=' QSTRING ';'  */
#line 1518 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5024 "conf_parser.c"
    break;

  case 288: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1524 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5033 "conf_parser.c"
    break;

  case 289: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1530 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5042 "conf_parser.c"
    break;

  case 290: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1536 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5056 "conf_parser.c"
    break;

  case 291: /* $@13: %empty  */
#line 1547 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 5065 "conf_parser.c"
    break;

  case 295: /* auth_flags_item: EXCEED_LIMIT  */
#line 1554 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 5074 "conf_parser.c"
    break;

  case 296: /* auth_flags_item: KLINE_EXEMPT  */
#line 1558 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 5083 "conf_parser.c"
    break;

  case 297: /* auth_flags_item: XLINE_EXEMPT  */
#line 1562 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 5092 "conf_parser.c"
    break;

  case 298: /* auth_flags_item: NEED_IDENT  */
#line 1566 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 5101 "conf_parser.c"
    break;

  case 299: /* auth_flags_item: CAN_FLOOD  */
#line 1570 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 5110 "conf_parser.c"
    break;

  case 300: /* auth_flags_item: NO_TILDE  */
#line 1574 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 5119 "conf_parser.c"
    break;

  case 301: /* auth_flags_item: RESV_EXEMPT  */
#line 1578 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 5128 "conf_parser.c"
    break;

  case 302: /* auth_flags_item: T_WEBIRC  */
#line 1582 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 5137 "conf_parser.c"
    break;

  case 303: /* auth_flags_item: NEED_PASSWORD  */
#line 1586 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 5146 "conf_parser.c"
    break;

  case 304: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1592 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_hostname(yylval.string))
  {
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
    block_state.flags.value |= CONF_FLAGS_SPOOF_IP;
  }
  else
    log_write(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 5163 "conf_parser.c"
    break;

  case 305: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1606 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 5175 "conf_parser.c"
    break;

  case 306: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1615 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 5187 "conf_parser.c"
    break;

  case 307: /* $@14: %empty  */
#line 1628 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5199 "conf_parser.c"
    break;

  case 308: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1635 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5210 "conf_parser.c"
    break;

  case 315: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1646 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5219 "conf_parser.c"
    break;

  case 316: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1652 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5228 "conf_parser.c"
    break;

  case 317: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5237 "conf_parser.c"
    break;

  case 323: /* service_name: NAME '=' QSTRING ';'  */
#line 1673 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5252 "conf_parser.c"
    break;

  case 324: /* $@15: %empty  */
#line 1689 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5268 "conf_parser.c"
    break;

  case 325: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1700 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5283 "conf_parser.c"
    break;

  case 332: /* shared_name: NAME '=' QSTRING ';'  */
#line 1715 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5292 "conf_parser.c"
    break;

  case 333: /* shared_user: USER '=' QSTRING ';'  */
#line 1721 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct nuh_split nuh =
    {
      .nuhmask = yylval.string,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    nuh_split(&nuh);
  }
}
#line 5314 "conf_parser.c"
    break;

  case 334: /* $@16: %empty  */
#line 1740 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5323 "conf_parser.c"
    break;

  case 338: /* shared_type_item: KLINE  */
#line 1747 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5332 "conf_parser.c"
    break;

  case 339: /* shared_type_item: UNKLINE  */
#line 1751 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5341 "conf_parser.c"
    break;

  case 340: /* shared_type_item: T_DLINE  */
#line 1755 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5350 "conf_parser.c"
    break;

  case 341: /* shared_type_item: T_UNDLINE  */
#line 1759 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5359 "conf_parser.c"
    break;

  case 342: /* shared_type_item: XLINE  */
#line 1763 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5368 "conf_parser.c"
    break;

  case 343: /* shared_type_item: T_UNXLINE  */
#line 1767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5377 "conf_parser.c"
    break;

  case 344: /* shared_type_item: RESV  */
#line 1771 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5386 "conf_parser.c"
    break;

  case 345: /* shared_type_item: T_UNRESV  */
#line 1775 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5395 "conf_parser.c"
    break;

  case 346: /* shared_type_item: T_LOCOPS  */
#line 1779 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5404 "conf_parser.c"
    break;

  case 347: /* shared_type_item: T_ALL  */
#line 1783 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5413 "conf_parser.c"
    break;

  case 348: /* $@17: %empty  */
#line 1793 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5427 "conf_parser.c"
    break;

  case 349: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1802 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5440 "conf_parser.c"
    break;

  case 355: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1815 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5449 "conf_parser.c"
    break;

  case 356: /* $@18: %empty  */
#line 1821 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5458 "conf_parser.c"
    break;

  case 360: /* cluster_type_item: KLINE  */
#line 1828 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5467 "conf_parser.c"
    break;

  case 361: /* cluster_type_item: UNKLINE  */
#line 1832 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5476 "conf_parser.c"
    break;

  case 362: /* cluster_type_item: T_DLINE  */
#line 1836 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5485 "conf_parser.c"
    break;

  case 363: /* cluster_type_item: T_UNDLINE  */
#line 1840 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5494 "conf_parser.c"
    break;

  case 364: /* cluster_type_item: XLINE  */
#line 1844 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5503 "conf_parser.c"
    break;

  case 365: /* cluster_type_item: T_UNXLINE  */
#line 1848 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5512 "conf_parser.c"
    break;

  case 366: /* cluster_type_item: RESV  */
#line 1852 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5521 "conf_parser.c"
    break;

  case 367: /* cluster_type_item: T_UNRESV  */
#line 1856 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5530 "conf_parser.c"
    break;

  case 368: /* cluster_type_item: T_LOCOPS  */
#line 1860 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5539 "conf_parser.c"
    break;

  case 369: /* cluster_type_item: T_ALL  */
#line 1864 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5548 "conf_parser.c"
    break;

  case 370: /* $@19: %empty  */
#line 1874 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5563 "conf_parser.c"
    break;

  case 371: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1884 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0] ||
      !block_state.host.buf[0])
    break;

  if (!block_state.rpass.buf[0] ||
      !block_state.spass.buf[0])
    break;

  if (server_valid_name(block_state.name.buf) == false)
    break;

  if (has_wildcards(block_state.name.buf) ||
      has_wildcards(block_state.host.buf))
    break;

  struct ConnectItem *connect = connect_create();
  connect->name = io_strdup(block_state.name.buf);
  connect->host = io_strdup(block_state.host.buf);
  connect->accept_password = io_strdup(block_state.rpass.buf);
  connect->send_password = io_strdup(block_state.spass.buf);

  connect->port = block_state.port.value;
  connect->timeout = block_state.timeout.value;
  connect->address_family = block_state.aftype.value;
  connect->flags = block_state.flags.value;

  if (block_state.cert.buf[0])
    connect->tls_cert_fingerprint = io_strdup(block_state.cert.buf);

  if (block_state.ciph.buf[0])
    connect->cipher_list = io_strdup(block_state.ciph.buf);

  list_move_list(&block_state.hub.list, &connect->hub_masks);
  list_move_list(&block_state.leaf.list, &connect->leaf_masks);

  if (block_state.bind.buf[0])
    if (address_from_string(block_state.bind.buf, &connect->bind_addr) == false)
      conf_error_report("Invalid IP address for bind address");

  connect_assign_class(connect, block_state.class.buf);
  connect_dns_lookup(connect);
}
#line 5614 "conf_parser.c"
    break;

  case 390: /* connect_name: NAME '=' QSTRING ';'  */
#line 1950 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5623 "conf_parser.c"
    break;

  case 391: /* connect_host: HOST '=' QSTRING ';'  */
#line 1956 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5632 "conf_parser.c"
    break;

  case 392: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1962 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5641 "conf_parser.c"
    break;

  case 393: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1968 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5650 "conf_parser.c"
    break;

  case 394: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1974 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (*yylval.string == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr(yylval.string, ' '))
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.spass.buf, yylval.string, sizeof(block_state.spass.buf));
}
#line 5666 "conf_parser.c"
    break;

  case 395: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1987 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (*yylval.string == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr(yylval.string, ' '))
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5682 "conf_parser.c"
    break;

  case 396: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2000 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5691 "conf_parser.c"
    break;

  case 397: /* connect_port: PORT '=' NUMBER ';'  */
#line 2006 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5700 "conf_parser.c"
    break;

  case 398: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2012 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5709 "conf_parser.c"
    break;

  case 399: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2016 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5718 "conf_parser.c"
    break;

  case 400: /* $@20: %empty  */
#line 2022 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5726 "conf_parser.c"
    break;

  case 404: /* connect_flags_item: AUTOCONN  */
#line 2028 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5735 "conf_parser.c"
    break;

  case 405: /* connect_flags_item: T_TLS  */
#line 2032 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5744 "conf_parser.c"
    break;

  case 406: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2038 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5758 "conf_parser.c"
    break;

  case 407: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5767 "conf_parser.c"
    break;

  case 408: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2055 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5776 "conf_parser.c"
    break;

  case 409: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5785 "conf_parser.c"
    break;

  case 410: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2067 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5799 "conf_parser.c"
    break;

  case 411: /* $@21: %empty  */
#line 2082 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5808 "conf_parser.c"
    break;

  case 412: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2086 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.user.buf[0] ||
      !block_state.host.buf[0])
    break;

  struct MaskItem *conf = conf_make(CONF_KLINE);
  conf->user = io_strdup(block_state.user.buf);
  conf->host = io_strdup(block_state.host.buf);

  if (block_state.rpass.buf[0])
    conf->reason = io_strdup(block_state.rpass.buf);
  else
    conf->reason = io_strdup(CONF_NOREASON);
  add_conf_by_address(CONF_KLINE, conf);
}
#line 5831 "conf_parser.c"
    break;

  case 418: /* kill_user: USER '=' QSTRING ';'  */
#line 2109 "conf_parser.y"
{

  if (conf_parser_ctx.pass == 2)
  {
    struct nuh_split nuh =
    {
      .nuhmask = yylval.string,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    nuh_split(&nuh);
  }
}
#line 5854 "conf_parser.c"
    break;

  case 419: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2129 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5863 "conf_parser.c"
    break;

  case 420: /* $@22: %empty  */
#line 2139 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5872 "conf_parser.c"
    break;

  case 421: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2143 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  if (address_parse_netmask(block_state.addr.buf, NULL, NULL) != HM_HOST)
  {
    struct MaskItem *conf = conf_make(CONF_DLINE);
    conf->host = io_strdup(block_state.addr.buf);

    if (block_state.rpass.buf[0])
      conf->reason = io_strdup(block_state.rpass.buf);
    else
      conf->reason = io_strdup(CONF_NOREASON);
    add_conf_by_address(CONF_DLINE, conf);
  }
}
#line 5896 "conf_parser.c"
    break;

  case 427: /* deny_ip: IP '=' QSTRING ';'  */
#line 2167 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5905 "conf_parser.c"
    break;

  case 428: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2173 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5914 "conf_parser.c"
    break;

  case 434: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2188 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (*yylval.string && address_parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      struct MaskItem *conf = conf_make(CONF_EXEMPT);
      conf->host = io_strdup(yylval.string);

      add_conf_by_address(CONF_EXEMPT, conf);
    }
  }
}
#line 5931 "conf_parser.c"
    break;

  case 435: /* $@23: %empty  */
#line 2205 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5940 "conf_parser.c"
    break;

  case 436: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2209 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  struct GecosItem *gecos = gecos_make();
  gecos->mask = io_strdup(block_state.name.buf);

  if (block_state.rpass.buf[0])
    gecos->reason = io_strdup(block_state.rpass.buf);
  else
    gecos->reason = io_strdup(CONF_NOREASON);
}
#line 5960 "conf_parser.c"
    break;

  case 442: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2229 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5969 "conf_parser.c"
    break;

  case 443: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2235 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5978 "conf_parser.c"
    break;

  case 501: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2304 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5986 "conf_parser.c"
    break;

  case 502: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2309 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5994 "conf_parser.c"
    break;

  case 503: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2314 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 6002 "conf_parser.c"
    break;

  case 504: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2319 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 6010 "conf_parser.c"
    break;

  case 505: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2324 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 6018 "conf_parser.c"
    break;

  case 506: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2329 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 6026 "conf_parser.c"
    break;

  case 507: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2334 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 6034 "conf_parser.c"
    break;

  case 508: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2339 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6042 "conf_parser.c"
    break;

  case 509: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2344 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6050 "conf_parser.c"
    break;

  case 510: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2349 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6058 "conf_parser.c"
    break;

  case 511: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2354 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 6066 "conf_parser.c"
    break;

  case 512: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2359 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 6074 "conf_parser.c"
    break;

  case 513: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2364 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6082 "conf_parser.c"
    break;

  case 514: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2369 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6090 "conf_parser.c"
    break;

  case 515: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2374 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6098 "conf_parser.c"
    break;

  case 516: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2379 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 6109 "conf_parser.c"
    break;

  case 517: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2387 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6117 "conf_parser.c"
    break;

  case 518: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2392 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6125 "conf_parser.c"
    break;

  case 519: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2397 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6133 "conf_parser.c"
    break;

  case 520: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2402 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6141 "conf_parser.c"
    break;

  case 521: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2407 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6149 "conf_parser.c"
    break;

  case 522: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2412 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6157 "conf_parser.c"
    break;

  case 523: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2417 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 6165 "conf_parser.c"
    break;

  case 524: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2422 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 6173 "conf_parser.c"
    break;

  case 525: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2427 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 6181 "conf_parser.c"
    break;

  case 526: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2432 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6189 "conf_parser.c"
    break;

  case 527: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2437 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 6197 "conf_parser.c"
    break;

  case 528: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2442 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 6205 "conf_parser.c"
    break;

  case 529: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2447 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6213 "conf_parser.c"
    break;

  case 530: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2452 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6221 "conf_parser.c"
    break;

  case 531: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2457 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6229 "conf_parser.c"
    break;

  case 532: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2462 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6237 "conf_parser.c"
    break;

  case 533: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2467 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6245 "conf_parser.c"
    break;

  case 534: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2472 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6253 "conf_parser.c"
    break;

  case 535: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2477 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6261 "conf_parser.c"
    break;

  case 536: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2482 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6269 "conf_parser.c"
    break;

  case 537: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2487 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6277 "conf_parser.c"
    break;

  case 538: /* general_disable_auth: DISABLE_AUTH '=' TBOOL ';'  */
#line 2492 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6285 "conf_parser.c"
    break;

  case 539: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2497 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6293 "conf_parser.c"
    break;

  case 540: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2502 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6301 "conf_parser.c"
    break;

  case 541: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2507 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6309 "conf_parser.c"
    break;

  case 542: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2512 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6321 "conf_parser.c"
    break;

  case 543: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2521 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6329 "conf_parser.c"
    break;

  case 544: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2526 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6337 "conf_parser.c"
    break;

  case 545: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2531 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6345 "conf_parser.c"
    break;

  case 546: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2536 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6353 "conf_parser.c"
    break;

  case 547: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2541 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
  {
    ConfigGeneral.cloak_enabled = true;
    cloak_set_enabled();
  }
  else
  {
    ConfigGeneral.cloak_enabled = false;
    cloak_set_disabled();
  }
}
#line 6373 "conf_parser.c"
    break;

  case 548: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2558 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6384 "conf_parser.c"
    break;

  case 549: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2566 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6395 "conf_parser.c"
    break;

  case 550: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2574 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6406 "conf_parser.c"
    break;

  case 551: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2582 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6419 "conf_parser.c"
    break;

  case 552: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2592 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6432 "conf_parser.c"
    break;

  case 553: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2602 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6443 "conf_parser.c"
    break;

  case 576: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2636 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6451 "conf_parser.c"
    break;

  case 577: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2641 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6460 "conf_parser.c"
    break;

  case 578: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2647 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6469 "conf_parser.c"
    break;

  case 579: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2653 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6477 "conf_parser.c"
    break;

  case 580: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2658 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6485 "conf_parser.c"
    break;

  case 581: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2663 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6493 "conf_parser.c"
    break;

  case 582: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2668 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6501 "conf_parser.c"
    break;

  case 583: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2673 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6509 "conf_parser.c"
    break;

  case 584: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2678 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6517 "conf_parser.c"
    break;

  case 585: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2683 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6525 "conf_parser.c"
    break;

  case 586: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2688 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6533 "conf_parser.c"
    break;

  case 587: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2693 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6541 "conf_parser.c"
    break;

  case 588: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2698 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6549 "conf_parser.c"
    break;

  case 589: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2703 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6557 "conf_parser.c"
    break;

  case 590: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2708 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6565 "conf_parser.c"
    break;

  case 591: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2713 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 1)
  {
    conf_error_report("max_kick_length too low, setting to 9");
    ConfigChannel.max_kick_length = KICKLEN;
  }
  else if ((yyvsp[-1].number) > KICKLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_kick_length too high, setting to %d", KICKLEN);
    conf_error_report(buf);

    ConfigChannel.max_kick_length = KICKLEN;
  }
  else
    ConfigChannel.max_kick_length = (yyvsp[-1].number);
}
#line 6591 "conf_parser.c"
    break;

  case 592: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2736 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6599 "conf_parser.c"
    break;

  case 593: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2741 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6607 "conf_parser.c"
    break;

  case 607: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2764 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6616 "conf_parser.c"
    break;

  case 608: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2770 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    flatten_links_handle_event_state(interval_seconds);
  }
}
#line 6630 "conf_parser.c"
    break;

  case 609: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2781 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6642 "conf_parser.c"
    break;

  case 610: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2790 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6651 "conf_parser.c"
    break;

  case 611: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2796 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6660 "conf_parser.c"
    break;

  case 612: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2802 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6669 "conf_parser.c"
    break;

  case 613: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2808 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6681 "conf_parser.c"
    break;

  case 614: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2817 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6690 "conf_parser.c"
    break;

  case 615: /* serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'  */
#line 2823 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6699 "conf_parser.c"
    break;


#line 6703 "conf_parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

