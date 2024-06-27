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
#line 27 "conf_parser.y"


#include "stdinc.h"
#include "defaults.h"
#include "ircd.h"
#include "list.h"
#include "command.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_cluster.h"
#include "conf_gecos.h"
#include "conf_pseudo.h"
#include "conf_resv.h"
#include "conf_service.h"
#include "conf_shared.h"
#include "event.h"
#include "id.h"
#include "log.h"
#include "irc_string.h"
#include "memory.h"
#include "module.h"
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
    class,
    target,
    prepend,
    command;

  struct
  {
    unsigned int value;
  } flags,
    modes,
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


#line 179 "conf_parser.c"

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
    BOT = 266,                     /* BOT  */
    BYTES = 267,                   /* BYTES  */
    KBYTES = 268,                  /* KBYTES  */
    MBYTES = 269,                  /* MBYTES  */
    CALLER_ID_WAIT = 270,          /* CALLER_ID_WAIT  */
    CAN_FLOOD = 271,               /* CAN_FLOOD  */
    CHANNEL = 272,                 /* CHANNEL  */
    CIDR_BITLEN_IPV4 = 273,        /* CIDR_BITLEN_IPV4  */
    CIDR_BITLEN_IPV6 = 274,        /* CIDR_BITLEN_IPV6  */
    CLASS = 275,                   /* CLASS  */
    CLIENT = 276,                  /* CLIENT  */
    CLOAK_ENABLED = 277,           /* CLOAK_ENABLED  */
    CLOAK_CIDR_LEN_IPV4 = 278,     /* CLOAK_CIDR_LEN_IPV4  */
    CLOAK_CIDR_LEN_IPV6 = 279,     /* CLOAK_CIDR_LEN_IPV6  */
    CLOAK_NUM_BITS = 280,          /* CLOAK_NUM_BITS  */
    CLOAK_SECRET = 281,            /* CLOAK_SECRET  */
    CLOAK_SUFFIX = 282,            /* CLOAK_SUFFIX  */
    CLOSE = 283,                   /* CLOSE  */
    CONNECT = 284,                 /* CONNECT  */
    CONNECTFREQ = 285,             /* CONNECTFREQ  */
    CORE = 286,                    /* CORE  */
    CYCLE_ON_HOST_CHANGE = 287,    /* CYCLE_ON_HOST_CHANGE  */
    DEFAULT_FLOODCOUNT = 288,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 289,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 290, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 291, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 292,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 293,                   /* DEFER  */
    DENY = 294,                    /* DENY  */
    DESCRIPTION = 295,             /* DESCRIPTION  */
    DIE = 296,                     /* DIE  */
    DISABLE_AUTH = 297,            /* DISABLE_AUTH  */
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
    EXPIRATION = 309,              /* EXPIRATION  */
    FAILED_OPER_NOTICE = 310,      /* FAILED_OPER_NOTICE  */
    FLATTEN_LINKS = 311,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 312,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 313,      /* FLATTEN_LINKS_FILE  */
    GECOS = 314,                   /* GECOS  */
    GENERAL = 315,                 /* GENERAL  */
    HIDDEN = 316,                  /* HIDDEN  */
    HIDDEN_NAME = 317,             /* HIDDEN_NAME  */
    HIDE_CHANS = 318,              /* HIDE_CHANS  */
    HIDE_IDLE = 319,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 320,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVER_IPS = 321,         /* HIDE_SERVER_IPS  */
    HIDE_SERVERS = 322,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 323,           /* HIDE_SERVICES  */
    HOST = 324,                    /* HOST  */
    HUB = 325,                     /* HUB  */
    HUB_MASK = 326,                /* HUB_MASK  */
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
    MAX_BANS = 352,                /* MAX_BANS  */
    MAX_BANS_LARGE = 353,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 354,            /* MAX_CHANNELS  */
    MAX_IDLE = 355,                /* MAX_IDLE  */
    MAX_INVITES = 356,             /* MAX_INVITES  */
    MAX_MONITOR = 357,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 358,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 359,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 360,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 361,              /* MAX_NUMBER  */
    MAX_TARGETS = 362,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 363,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 364,                 /* MESSAGE  */
    MIN_IDLE = 365,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 366,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 367,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 368,                  /* MODULE  */
    MODULE_BASE_PATH = 369,        /* MODULE_BASE_PATH  */
    MOTD = 370,                    /* MOTD  */
    NAME = 371,                    /* NAME  */
    NEED_IDENT = 372,              /* NEED_IDENT  */
    NEED_PASSWORD = 373,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 374,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 375,            /* NETWORK_NAME  */
    NICK = 376,                    /* NICK  */
    NO_OPER_FLOOD = 377,           /* NO_OPER_FLOOD  */
    NO_TILDE = 378,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 379,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 380,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 381,     /* NUMBER_PER_IP_LOCAL  */
    OPER_ONLY_UMODES = 382,        /* OPER_ONLY_UMODES  */
    OPER_UMODES = 383,             /* OPER_UMODES  */
    OPERATOR = 384,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 385,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 386,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 387,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 388,                /* PASSWORD  */
    PATH = 389,                    /* PATH  */
    PING_COOKIE = 390,             /* PING_COOKIE  */
    PING_TIME = 391,               /* PING_TIME  */
    PORT = 392,                    /* PORT  */
    RANDOM_IDLE = 393,             /* RANDOM_IDLE  */
    REASON = 394,                  /* REASON  */
    REDIRPORT = 395,               /* REDIRPORT  */
    REDIRSERV = 396,               /* REDIRSERV  */
    REHASH = 397,                  /* REHASH  */
    REMOTE = 398,                  /* REMOTE  */
    REMOTEBAN = 399,               /* REMOTEBAN  */
    RESIDENT = 400,                /* RESIDENT  */
    RESV = 401,                    /* RESV  */
    RESV_EXEMPT = 402,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 403,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 404,                 /* SECONDS  */
    MINUTES = 405,                 /* MINUTES  */
    HOURS = 406,                   /* HOURS  */
    DAYS = 407,                    /* DAYS  */
    WEEKS = 408,                   /* WEEKS  */
    MONTHS = 409,                  /* MONTHS  */
    YEARS = 410,                   /* YEARS  */
    SEND_PASSWORD = 411,           /* SEND_PASSWORD  */
    SENDQ = 412,                   /* SENDQ  */
    SERVERHIDE = 413,              /* SERVERHIDE  */
    SERVERINFO = 414,              /* SERVERINFO  */
    SHORT_MOTD = 415,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 416,       /* SPECIALS_IN_IDENT  */
    SPOOF = 417,                   /* SPOOF  */
    SQUIT = 418,                   /* SQUIT  */
    STATS_E_DISABLED = 419,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 420,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 421,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 422,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 423,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 424,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 425,       /* STATS_U_OPER_ONLY  */
    T_ALL = 426,                   /* T_ALL  */
    T_BIND = 427,                  /* T_BIND  */
    T_CALLERID = 428,              /* T_CALLERID  */
    T_CCONN = 429,                 /* T_CCONN  */
    T_COMMAND = 430,               /* T_COMMAND  */
    T_CLUSTER = 431,               /* T_CLUSTER  */
    T_DEAF = 432,                  /* T_DEAF  */
    T_DEBUG = 433,                 /* T_DEBUG  */
    T_DLINE = 434,                 /* T_DLINE  */
    T_EXTERNAL = 435,              /* T_EXTERNAL  */
    T_FARCONNECT = 436,            /* T_FARCONNECT  */
    T_FILE = 437,                  /* T_FILE  */
    T_FLOOD = 438,                 /* T_FLOOD  */
    T_GLOBOPS = 439,               /* T_GLOBOPS  */
    T_INVISIBLE = 440,             /* T_INVISIBLE  */
    T_IPV4 = 441,                  /* T_IPV4  */
    T_IPV6 = 442,                  /* T_IPV6  */
    T_LOCOPS = 443,                /* T_LOCOPS  */
    T_LOG = 444,                   /* T_LOG  */
    T_NCHANGE = 445,               /* T_NCHANGE  */
    T_NONONREG = 446,              /* T_NONONREG  */
    T_OPME = 447,                  /* T_OPME  */
    T_PREPEND = 448,               /* T_PREPEND  */
    T_PSEUDO = 449,                /* T_PSEUDO  */
    T_RECVQ = 450,                 /* T_RECVQ  */
    T_REJ = 451,                   /* T_REJ  */
    T_RESTART = 452,               /* T_RESTART  */
    T_SECUREONLY = 453,            /* T_SECUREONLY  */
    T_SERVER = 454,                /* T_SERVER  */
    T_SERVICE = 455,               /* T_SERVICE  */
    T_SERVNOTICE = 456,            /* T_SERVNOTICE  */
    T_SET = 457,                   /* T_SET  */
    T_SHARED = 458,                /* T_SHARED  */
    T_SIZE = 459,                  /* T_SIZE  */
    T_SKILL = 460,                 /* T_SKILL  */
    T_SOFTCALLERID = 461,          /* T_SOFTCALLERID  */
    T_SPY = 462,                   /* T_SPY  */
    T_TARGET = 463,                /* T_TARGET  */
    T_TLS = 464,                   /* T_TLS  */
    T_UMODES = 465,                /* T_UMODES  */
    T_UNDLINE = 466,               /* T_UNDLINE  */
    T_UNLIMITED = 467,             /* T_UNLIMITED  */
    T_UNRESV = 468,                /* T_UNRESV  */
    T_UNXLINE = 469,               /* T_UNXLINE  */
    T_WALLOP = 470,                /* T_WALLOP  */
    T_WALLOPS = 471,               /* T_WALLOPS  */
    T_WEBIRC = 472,                /* T_WEBIRC  */
    TBOOL = 473,                   /* TBOOL  */
    THROTTLE_COUNT = 474,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 475,           /* THROTTLE_TIME  */
    TIMEOUT = 476,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 477,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 478, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 479,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 480,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 481, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 482,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 483, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 484,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 485,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 486,           /* TS_WARN_DELTA  */
    TWODOTS = 487,                 /* TWODOTS  */
    TYPE = 488,                    /* TYPE  */
    UNKLINE = 489,                 /* UNKLINE  */
    USE_LOGGING = 490,             /* USE_LOGGING  */
    USER = 491,                    /* USER  */
    VHOST = 492,                   /* VHOST  */
    VHOST6 = 493,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 494,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 495,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 496,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 497,                   /* XLINE  */
    XLINE_EXEMPT = 498,            /* XLINE_EXEMPT  */
    QSTRING = 499,                 /* QSTRING  */
    NUMBER = 500                   /* NUMBER  */
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
#define BOT 266
#define BYTES 267
#define KBYTES 268
#define MBYTES 269
#define CALLER_ID_WAIT 270
#define CAN_FLOOD 271
#define CHANNEL 272
#define CIDR_BITLEN_IPV4 273
#define CIDR_BITLEN_IPV6 274
#define CLASS 275
#define CLIENT 276
#define CLOAK_ENABLED 277
#define CLOAK_CIDR_LEN_IPV4 278
#define CLOAK_CIDR_LEN_IPV6 279
#define CLOAK_NUM_BITS 280
#define CLOAK_SECRET 281
#define CLOAK_SUFFIX 282
#define CLOSE 283
#define CONNECT 284
#define CONNECTFREQ 285
#define CORE 286
#define CYCLE_ON_HOST_CHANGE 287
#define DEFAULT_FLOODCOUNT 288
#define DEFAULT_FLOODTIME 289
#define DEFAULT_JOIN_FLOOD_COUNT 290
#define DEFAULT_JOIN_FLOOD_TIME 291
#define DEFAULT_MAX_CLIENTS 292
#define DEFER 293
#define DENY 294
#define DESCRIPTION 295
#define DIE 296
#define DISABLE_AUTH 297
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
#define EXPIRATION 309
#define FAILED_OPER_NOTICE 310
#define FLATTEN_LINKS 311
#define FLATTEN_LINKS_DELAY 312
#define FLATTEN_LINKS_FILE 313
#define GECOS 314
#define GENERAL 315
#define HIDDEN 316
#define HIDDEN_NAME 317
#define HIDE_CHANS 318
#define HIDE_IDLE 319
#define HIDE_IDLE_FROM_OPERS 320
#define HIDE_SERVER_IPS 321
#define HIDE_SERVERS 322
#define HIDE_SERVICES 323
#define HOST 324
#define HUB 325
#define HUB_MASK 326
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
#define MAX_BANS 352
#define MAX_BANS_LARGE 353
#define MAX_CHANNELS 354
#define MAX_IDLE 355
#define MAX_INVITES 356
#define MAX_MONITOR 357
#define MAX_NICK_CHANGES 358
#define MAX_NICK_LENGTH 359
#define MAX_NICK_TIME 360
#define MAX_NUMBER 361
#define MAX_TARGETS 362
#define MAX_TOPIC_LENGTH 363
#define MESSAGE 364
#define MIN_IDLE 365
#define MIN_NONWILDCARD 366
#define MIN_NONWILDCARD_SIMPLE 367
#define MODULE 368
#define MODULE_BASE_PATH 369
#define MOTD 370
#define NAME 371
#define NEED_IDENT 372
#define NEED_PASSWORD 373
#define NETWORK_DESCRIPTION 374
#define NETWORK_NAME 375
#define NICK 376
#define NO_OPER_FLOOD 377
#define NO_TILDE 378
#define NUMBER_PER_CIDR 379
#define NUMBER_PER_IP_GLOBAL 380
#define NUMBER_PER_IP_LOCAL 381
#define OPER_ONLY_UMODES 382
#define OPER_UMODES 383
#define OPERATOR 384
#define OPERS_BYPASS_CALLERID 385
#define PACE_WAIT 386
#define PACE_WAIT_SIMPLE 387
#define PASSWORD 388
#define PATH 389
#define PING_COOKIE 390
#define PING_TIME 391
#define PORT 392
#define RANDOM_IDLE 393
#define REASON 394
#define REDIRPORT 395
#define REDIRSERV 396
#define REHASH 397
#define REMOTE 398
#define REMOTEBAN 399
#define RESIDENT 400
#define RESV 401
#define RESV_EXEMPT 402
#define RSA_PRIVATE_KEY_FILE 403
#define SECONDS 404
#define MINUTES 405
#define HOURS 406
#define DAYS 407
#define WEEKS 408
#define MONTHS 409
#define YEARS 410
#define SEND_PASSWORD 411
#define SENDQ 412
#define SERVERHIDE 413
#define SERVERINFO 414
#define SHORT_MOTD 415
#define SPECIALS_IN_IDENT 416
#define SPOOF 417
#define SQUIT 418
#define STATS_E_DISABLED 419
#define STATS_I_OPER_ONLY 420
#define STATS_K_OPER_ONLY 421
#define STATS_M_OPER_ONLY 422
#define STATS_O_OPER_ONLY 423
#define STATS_P_OPER_ONLY 424
#define STATS_U_OPER_ONLY 425
#define T_ALL 426
#define T_BIND 427
#define T_CALLERID 428
#define T_CCONN 429
#define T_COMMAND 430
#define T_CLUSTER 431
#define T_DEAF 432
#define T_DEBUG 433
#define T_DLINE 434
#define T_EXTERNAL 435
#define T_FARCONNECT 436
#define T_FILE 437
#define T_FLOOD 438
#define T_GLOBOPS 439
#define T_INVISIBLE 440
#define T_IPV4 441
#define T_IPV6 442
#define T_LOCOPS 443
#define T_LOG 444
#define T_NCHANGE 445
#define T_NONONREG 446
#define T_OPME 447
#define T_PREPEND 448
#define T_PSEUDO 449
#define T_RECVQ 450
#define T_REJ 451
#define T_RESTART 452
#define T_SECUREONLY 453
#define T_SERVER 454
#define T_SERVICE 455
#define T_SERVNOTICE 456
#define T_SET 457
#define T_SHARED 458
#define T_SIZE 459
#define T_SKILL 460
#define T_SOFTCALLERID 461
#define T_SPY 462
#define T_TARGET 463
#define T_TLS 464
#define T_UMODES 465
#define T_UNDLINE 466
#define T_UNLIMITED 467
#define T_UNRESV 468
#define T_UNXLINE 469
#define T_WALLOP 470
#define T_WALLOPS 471
#define T_WEBIRC 472
#define TBOOL 473
#define THROTTLE_COUNT 474
#define THROTTLE_TIME 475
#define TIMEOUT 476
#define TLS_CERTIFICATE_FILE 477
#define TLS_CERTIFICATE_FINGERPRINT 478
#define TLS_CIPHER_LIST 479
#define TLS_CIPHER_SUITES 480
#define TLS_CONNECTION_REQUIRED 481
#define TLS_DH_PARAM_FILE 482
#define TLS_MESSAGE_DIGEST_ALGORITHM 483
#define TLS_SUPPORTED_GROUPS 484
#define TS_MAX_DELTA 485
#define TS_WARN_DELTA 486
#define TWODOTS 487
#define TYPE 488
#define UNKLINE 489
#define USE_LOGGING 490
#define USER 491
#define VHOST 492
#define VHOST6 493
#define WARN_NO_CONNECT_BLOCK 494
#define WHOIS 495
#define WHOWAS_HISTORY_LENGTH 496
#define XLINE 497
#define XLINE_EXEMPT 498
#define QSTRING 499
#define NUMBER 500

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 135 "conf_parser.y"

  int number;
  char *string;

#line 727 "conf_parser.c"

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
  YYSYMBOL_BOT = 11,                       /* BOT  */
  YYSYMBOL_BYTES = 12,                     /* BYTES  */
  YYSYMBOL_KBYTES = 13,                    /* KBYTES  */
  YYSYMBOL_MBYTES = 14,                    /* MBYTES  */
  YYSYMBOL_CALLER_ID_WAIT = 15,            /* CALLER_ID_WAIT  */
  YYSYMBOL_CAN_FLOOD = 16,                 /* CAN_FLOOD  */
  YYSYMBOL_CHANNEL = 17,                   /* CHANNEL  */
  YYSYMBOL_CIDR_BITLEN_IPV4 = 18,          /* CIDR_BITLEN_IPV4  */
  YYSYMBOL_CIDR_BITLEN_IPV6 = 19,          /* CIDR_BITLEN_IPV6  */
  YYSYMBOL_CLASS = 20,                     /* CLASS  */
  YYSYMBOL_CLIENT = 21,                    /* CLIENT  */
  YYSYMBOL_CLOAK_ENABLED = 22,             /* CLOAK_ENABLED  */
  YYSYMBOL_CLOAK_CIDR_LEN_IPV4 = 23,       /* CLOAK_CIDR_LEN_IPV4  */
  YYSYMBOL_CLOAK_CIDR_LEN_IPV6 = 24,       /* CLOAK_CIDR_LEN_IPV6  */
  YYSYMBOL_CLOAK_NUM_BITS = 25,            /* CLOAK_NUM_BITS  */
  YYSYMBOL_CLOAK_SECRET = 26,              /* CLOAK_SECRET  */
  YYSYMBOL_CLOAK_SUFFIX = 27,              /* CLOAK_SUFFIX  */
  YYSYMBOL_CLOSE = 28,                     /* CLOSE  */
  YYSYMBOL_CONNECT = 29,                   /* CONNECT  */
  YYSYMBOL_CONNECTFREQ = 30,               /* CONNECTFREQ  */
  YYSYMBOL_CORE = 31,                      /* CORE  */
  YYSYMBOL_CYCLE_ON_HOST_CHANGE = 32,      /* CYCLE_ON_HOST_CHANGE  */
  YYSYMBOL_DEFAULT_FLOODCOUNT = 33,        /* DEFAULT_FLOODCOUNT  */
  YYSYMBOL_DEFAULT_FLOODTIME = 34,         /* DEFAULT_FLOODTIME  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_COUNT = 35,  /* DEFAULT_JOIN_FLOOD_COUNT  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_TIME = 36,   /* DEFAULT_JOIN_FLOOD_TIME  */
  YYSYMBOL_DEFAULT_MAX_CLIENTS = 37,       /* DEFAULT_MAX_CLIENTS  */
  YYSYMBOL_DEFER = 38,                     /* DEFER  */
  YYSYMBOL_DENY = 39,                      /* DENY  */
  YYSYMBOL_DESCRIPTION = 40,               /* DESCRIPTION  */
  YYSYMBOL_DIE = 41,                       /* DIE  */
  YYSYMBOL_DISABLE_AUTH = 42,              /* DISABLE_AUTH  */
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
  YYSYMBOL_EXPIRATION = 54,                /* EXPIRATION  */
  YYSYMBOL_FAILED_OPER_NOTICE = 55,        /* FAILED_OPER_NOTICE  */
  YYSYMBOL_FLATTEN_LINKS = 56,             /* FLATTEN_LINKS  */
  YYSYMBOL_FLATTEN_LINKS_DELAY = 57,       /* FLATTEN_LINKS_DELAY  */
  YYSYMBOL_FLATTEN_LINKS_FILE = 58,        /* FLATTEN_LINKS_FILE  */
  YYSYMBOL_GECOS = 59,                     /* GECOS  */
  YYSYMBOL_GENERAL = 60,                   /* GENERAL  */
  YYSYMBOL_HIDDEN = 61,                    /* HIDDEN  */
  YYSYMBOL_HIDDEN_NAME = 62,               /* HIDDEN_NAME  */
  YYSYMBOL_HIDE_CHANS = 63,                /* HIDE_CHANS  */
  YYSYMBOL_HIDE_IDLE = 64,                 /* HIDE_IDLE  */
  YYSYMBOL_HIDE_IDLE_FROM_OPERS = 65,      /* HIDE_IDLE_FROM_OPERS  */
  YYSYMBOL_HIDE_SERVER_IPS = 66,           /* HIDE_SERVER_IPS  */
  YYSYMBOL_HIDE_SERVERS = 67,              /* HIDE_SERVERS  */
  YYSYMBOL_HIDE_SERVICES = 68,             /* HIDE_SERVICES  */
  YYSYMBOL_HOST = 69,                      /* HOST  */
  YYSYMBOL_HUB = 70,                       /* HUB  */
  YYSYMBOL_HUB_MASK = 71,                  /* HUB_MASK  */
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
  YYSYMBOL_MAX_BANS = 97,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 98,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 99,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 100,                 /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 101,              /* MAX_INVITES  */
  YYSYMBOL_MAX_MONITOR = 102,              /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 103,         /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 104,          /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 105,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 106,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 107,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 108,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 109,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 110,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 111,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 112,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 113,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 114,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 115,                     /* MOTD  */
  YYSYMBOL_NAME = 116,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 117,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 118,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 119,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 120,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 121,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 122,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 123,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 124,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 125,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 126,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_ONLY_UMODES = 127,         /* OPER_ONLY_UMODES  */
  YYSYMBOL_OPER_UMODES = 128,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 129,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 130,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 131,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 132,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 133,                 /* PASSWORD  */
  YYSYMBOL_PATH = 134,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 135,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 136,                /* PING_TIME  */
  YYSYMBOL_PORT = 137,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 138,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 139,                   /* REASON  */
  YYSYMBOL_REDIRPORT = 140,                /* REDIRPORT  */
  YYSYMBOL_REDIRSERV = 141,                /* REDIRSERV  */
  YYSYMBOL_REHASH = 142,                   /* REHASH  */
  YYSYMBOL_REMOTE = 143,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 144,                /* REMOTEBAN  */
  YYSYMBOL_RESIDENT = 145,                 /* RESIDENT  */
  YYSYMBOL_RESV = 146,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 147,              /* RESV_EXEMPT  */
  YYSYMBOL_RSA_PRIVATE_KEY_FILE = 148,     /* RSA_PRIVATE_KEY_FILE  */
  YYSYMBOL_SECONDS = 149,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 150,                  /* MINUTES  */
  YYSYMBOL_HOURS = 151,                    /* HOURS  */
  YYSYMBOL_DAYS = 152,                     /* DAYS  */
  YYSYMBOL_WEEKS = 153,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 154,                   /* MONTHS  */
  YYSYMBOL_YEARS = 155,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 156,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 157,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 158,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 159,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 160,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 161,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 162,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 163,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 164,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_I_OPER_ONLY = 165,        /* STATS_I_OPER_ONLY  */
  YYSYMBOL_STATS_K_OPER_ONLY = 166,        /* STATS_K_OPER_ONLY  */
  YYSYMBOL_STATS_M_OPER_ONLY = 167,        /* STATS_M_OPER_ONLY  */
  YYSYMBOL_STATS_O_OPER_ONLY = 168,        /* STATS_O_OPER_ONLY  */
  YYSYMBOL_STATS_P_OPER_ONLY = 169,        /* STATS_P_OPER_ONLY  */
  YYSYMBOL_STATS_U_OPER_ONLY = 170,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 171,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 172,                   /* T_BIND  */
  YYSYMBOL_T_CALLERID = 173,               /* T_CALLERID  */
  YYSYMBOL_T_CCONN = 174,                  /* T_CCONN  */
  YYSYMBOL_T_COMMAND = 175,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 176,                /* T_CLUSTER  */
  YYSYMBOL_T_DEAF = 177,                   /* T_DEAF  */
  YYSYMBOL_T_DEBUG = 178,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 179,                  /* T_DLINE  */
  YYSYMBOL_T_EXTERNAL = 180,               /* T_EXTERNAL  */
  YYSYMBOL_T_FARCONNECT = 181,             /* T_FARCONNECT  */
  YYSYMBOL_T_FILE = 182,                   /* T_FILE  */
  YYSYMBOL_T_FLOOD = 183,                  /* T_FLOOD  */
  YYSYMBOL_T_GLOBOPS = 184,                /* T_GLOBOPS  */
  YYSYMBOL_T_INVISIBLE = 185,              /* T_INVISIBLE  */
  YYSYMBOL_T_IPV4 = 186,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 187,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 188,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 189,                    /* T_LOG  */
  YYSYMBOL_T_NCHANGE = 190,                /* T_NCHANGE  */
  YYSYMBOL_T_NONONREG = 191,               /* T_NONONREG  */
  YYSYMBOL_T_OPME = 192,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 193,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 194,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 195,                  /* T_RECVQ  */
  YYSYMBOL_T_REJ = 196,                    /* T_REJ  */
  YYSYMBOL_T_RESTART = 197,                /* T_RESTART  */
  YYSYMBOL_T_SECUREONLY = 198,             /* T_SECUREONLY  */
  YYSYMBOL_T_SERVER = 199,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 200,                /* T_SERVICE  */
  YYSYMBOL_T_SERVNOTICE = 201,             /* T_SERVNOTICE  */
  YYSYMBOL_T_SET = 202,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 203,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 204,                   /* T_SIZE  */
  YYSYMBOL_T_SKILL = 205,                  /* T_SKILL  */
  YYSYMBOL_T_SOFTCALLERID = 206,           /* T_SOFTCALLERID  */
  YYSYMBOL_T_SPY = 207,                    /* T_SPY  */
  YYSYMBOL_T_TARGET = 208,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 209,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 210,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 211,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 212,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 213,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 214,                /* T_UNXLINE  */
  YYSYMBOL_T_WALLOP = 215,                 /* T_WALLOP  */
  YYSYMBOL_T_WALLOPS = 216,                /* T_WALLOPS  */
  YYSYMBOL_T_WEBIRC = 217,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 218,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 219,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 220,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 221,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 222,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 223, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 224,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 225,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 226,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 227,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 228, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 229,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 230,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 231,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 232,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 233,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 234,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 235,              /* USE_LOGGING  */
  YYSYMBOL_USER = 236,                     /* USER  */
  YYSYMBOL_VHOST = 237,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 238,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 239,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 240,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 241,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 242,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 243,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 244,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 245,                   /* NUMBER  */
  YYSYMBOL_246_ = 246,                     /* ';'  */
  YYSYMBOL_247_ = 247,                     /* '}'  */
  YYSYMBOL_248_ = 248,                     /* '='  */
  YYSYMBOL_249_ = 249,                     /* ':'  */
  YYSYMBOL_250_ = 250,                     /* ','  */
  YYSYMBOL_251_ = 251,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 252,                 /* $accept  */
  YYSYMBOL_conf = 253,                     /* conf  */
  YYSYMBOL_conf_item = 254,                /* conf_item  */
  YYSYMBOL_timespec_ = 255,                /* timespec_  */
  YYSYMBOL_timespec = 256,                 /* timespec  */
  YYSYMBOL_sizespec_ = 257,                /* sizespec_  */
  YYSYMBOL_sizespec = 258,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 259,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 260,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 261,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 262,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 263,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 264,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 265,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 266,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 267, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 268, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 269, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 270, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 271, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 272, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 273, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 274,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 275,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 276,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 277,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 278, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 279, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 280, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 281, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_hub = 282,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 283,              /* admin_entry  */
  YYSYMBOL_admin_items = 284,              /* admin_items  */
  YYSYMBOL_admin_item = 285,               /* admin_item  */
  YYSYMBOL_admin_name = 286,               /* admin_name  */
  YYSYMBOL_admin_email = 287,              /* admin_email  */
  YYSYMBOL_admin_description = 288,        /* admin_description  */
  YYSYMBOL_motd_entry = 289,               /* motd_entry  */
  YYSYMBOL_290_1 = 290,                    /* $@1  */
  YYSYMBOL_motd_items = 291,               /* motd_items  */
  YYSYMBOL_motd_item = 292,                /* motd_item  */
  YYSYMBOL_motd_mask = 293,                /* motd_mask  */
  YYSYMBOL_motd_file = 294,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 295,             /* pseudo_entry  */
  YYSYMBOL_296_2 = 296,                    /* $@2  */
  YYSYMBOL_pseudo_items = 297,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 298,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 299,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 300,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 301,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 302,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 303,            /* logging_entry  */
  YYSYMBOL_logging_items = 304,            /* logging_items  */
  YYSYMBOL_logging_item = 305,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 306,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 307,       /* logging_file_entry  */
  YYSYMBOL_308_3 = 308,                    /* $@3  */
  YYSYMBOL_logging_file_items = 309,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 310,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 311,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 312,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 313,        /* logging_file_type  */
  YYSYMBOL_314_4 = 314,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 315,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 316,               /* oper_entry  */
  YYSYMBOL_317_5 = 317,                    /* $@5  */
  YYSYMBOL_oper_items = 318,               /* oper_items  */
  YYSYMBOL_oper_item = 319,                /* oper_item  */
  YYSYMBOL_oper_name = 320,                /* oper_name  */
  YYSYMBOL_oper_user = 321,                /* oper_user  */
  YYSYMBOL_oper_password = 322,            /* oper_password  */
  YYSYMBOL_oper_whois = 323,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 324,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 325, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 326, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 327,               /* oper_class  */
  YYSYMBOL_oper_umodes = 328,              /* oper_umodes  */
  YYSYMBOL_329_6 = 329,                    /* $@6  */
  YYSYMBOL_oper_umodes_items = 330,        /* oper_umodes_items  */
  YYSYMBOL_oper_umodes_item = 331,         /* oper_umodes_item  */
  YYSYMBOL_oper_flags = 332,               /* oper_flags  */
  YYSYMBOL_333_7 = 333,                    /* $@7  */
  YYSYMBOL_oper_flags_items = 334,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 335,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 336,              /* class_entry  */
  YYSYMBOL_337_8 = 337,                    /* $@8  */
  YYSYMBOL_class_items = 338,              /* class_items  */
  YYSYMBOL_class_item = 339,               /* class_item  */
  YYSYMBOL_class_name = 340,               /* class_name  */
  YYSYMBOL_class_ping_time = 341,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 342, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 343, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 344,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 345,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 346,         /* class_max_number  */
  YYSYMBOL_class_sendq = 347,              /* class_sendq  */
  YYSYMBOL_class_recvq = 348,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 349,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 350,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 351,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 352,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 353,           /* class_max_idle  */
  YYSYMBOL_class_flags = 354,              /* class_flags  */
  YYSYMBOL_355_9 = 355,                    /* $@9  */
  YYSYMBOL_class_flags_items = 356,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 357,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 358,             /* listen_entry  */
  YYSYMBOL_359_10 = 359,                   /* $@10  */
  YYSYMBOL_listen_flags = 360,             /* listen_flags  */
  YYSYMBOL_361_11 = 361,                   /* $@11  */
  YYSYMBOL_listen_flags_items = 362,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 363,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 364,             /* listen_items  */
  YYSYMBOL_listen_item = 365,              /* listen_item  */
  YYSYMBOL_listen_port = 366,              /* listen_port  */
  YYSYMBOL_367_12 = 367,                   /* $@12  */
  YYSYMBOL_port_items = 368,               /* port_items  */
  YYSYMBOL_port_item = 369,                /* port_item  */
  YYSYMBOL_listen_address = 370,           /* listen_address  */
  YYSYMBOL_listen_host = 371,              /* listen_host  */
  YYSYMBOL_auth_entry = 372,               /* auth_entry  */
  YYSYMBOL_373_13 = 373,                   /* $@13  */
  YYSYMBOL_auth_items = 374,               /* auth_items  */
  YYSYMBOL_auth_item = 375,                /* auth_item  */
  YYSYMBOL_auth_user = 376,                /* auth_user  */
  YYSYMBOL_auth_passwd = 377,              /* auth_passwd  */
  YYSYMBOL_auth_class = 378,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 379,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 380,               /* auth_flags  */
  YYSYMBOL_381_14 = 381,                   /* $@14  */
  YYSYMBOL_auth_flags_items = 382,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 383,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 384,               /* auth_spoof  */
  YYSYMBOL_auth_redir_serv = 385,          /* auth_redir_serv  */
  YYSYMBOL_auth_redir_port = 386,          /* auth_redir_port  */
  YYSYMBOL_resv_entry = 387,               /* resv_entry  */
  YYSYMBOL_388_15 = 388,                   /* $@15  */
  YYSYMBOL_resv_items = 389,               /* resv_items  */
  YYSYMBOL_resv_item = 390,                /* resv_item  */
  YYSYMBOL_resv_mask = 391,                /* resv_mask  */
  YYSYMBOL_resv_reason = 392,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 393,              /* resv_exempt  */
  YYSYMBOL_service_entry = 394,            /* service_entry  */
  YYSYMBOL_service_items = 395,            /* service_items  */
  YYSYMBOL_service_item = 396,             /* service_item  */
  YYSYMBOL_service_name = 397,             /* service_name  */
  YYSYMBOL_shared_entry = 398,             /* shared_entry  */
  YYSYMBOL_399_16 = 399,                   /* $@16  */
  YYSYMBOL_shared_items = 400,             /* shared_items  */
  YYSYMBOL_shared_item = 401,              /* shared_item  */
  YYSYMBOL_shared_name = 402,              /* shared_name  */
  YYSYMBOL_shared_user = 403,              /* shared_user  */
  YYSYMBOL_shared_type = 404,              /* shared_type  */
  YYSYMBOL_405_17 = 405,                   /* $@17  */
  YYSYMBOL_shared_types = 406,             /* shared_types  */
  YYSYMBOL_shared_type_item = 407,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 408,            /* cluster_entry  */
  YYSYMBOL_409_18 = 409,                   /* $@18  */
  YYSYMBOL_cluster_items = 410,            /* cluster_items  */
  YYSYMBOL_cluster_item = 411,             /* cluster_item  */
  YYSYMBOL_cluster_name = 412,             /* cluster_name  */
  YYSYMBOL_cluster_type = 413,             /* cluster_type  */
  YYSYMBOL_414_19 = 414,                   /* $@19  */
  YYSYMBOL_cluster_types = 415,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 416,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 417,            /* connect_entry  */
  YYSYMBOL_418_20 = 418,                   /* $@20  */
  YYSYMBOL_connect_items = 419,            /* connect_items  */
  YYSYMBOL_connect_item = 420,             /* connect_item  */
  YYSYMBOL_connect_name = 421,             /* connect_name  */
  YYSYMBOL_connect_host = 422,             /* connect_host  */
  YYSYMBOL_connect_timeout = 423,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 424,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 425,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 426,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 427, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 428,             /* connect_port  */
  YYSYMBOL_connect_aftype = 429,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 430,            /* connect_flags  */
  YYSYMBOL_431_21 = 431,                   /* $@21  */
  YYSYMBOL_connect_flags_items = 432,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 433,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 434,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 435,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 436,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 437,            /* connect_class  */
  YYSYMBOL_connect_tls_cipher_list = 438,  /* connect_tls_cipher_list  */
  YYSYMBOL_kill_entry = 439,               /* kill_entry  */
  YYSYMBOL_440_22 = 440,                   /* $@22  */
  YYSYMBOL_kill_items = 441,               /* kill_items  */
  YYSYMBOL_kill_item = 442,                /* kill_item  */
  YYSYMBOL_kill_user = 443,                /* kill_user  */
  YYSYMBOL_kill_reason = 444,              /* kill_reason  */
  YYSYMBOL_deny_entry = 445,               /* deny_entry  */
  YYSYMBOL_446_23 = 446,                   /* $@23  */
  YYSYMBOL_deny_items = 447,               /* deny_items  */
  YYSYMBOL_deny_item = 448,                /* deny_item  */
  YYSYMBOL_deny_ip = 449,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 450,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 451,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 452,             /* exempt_items  */
  YYSYMBOL_exempt_item = 453,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 454,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 455,              /* gecos_entry  */
  YYSYMBOL_456_24 = 456,                   /* $@24  */
  YYSYMBOL_gecos_items = 457,              /* gecos_items  */
  YYSYMBOL_gecos_item = 458,               /* gecos_item  */
  YYSYMBOL_gecos_name = 459,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 460,             /* gecos_reason  */
  YYSYMBOL_general_entry = 461,            /* general_entry  */
  YYSYMBOL_general_items = 462,            /* general_items  */
  YYSYMBOL_general_item = 463,             /* general_item  */
  YYSYMBOL_general_away_count = 464,       /* general_away_count  */
  YYSYMBOL_general_away_time = 465,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 466,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 467, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 468, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 469,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 470,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 471,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 472,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 473, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 474, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 475,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 476,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 477, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 478,       /* general_max_accept  */
  YYSYMBOL_general_anti_spam_exit_message_time = 479, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 480,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 481,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 482, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 483, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 484, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 485, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 486, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 487, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 488, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 489, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 490, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 491,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 492,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 493, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 494, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 495,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 496,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 497, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 498,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 499,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_auth = 500,     /* general_disable_auth  */
  YYSYMBOL_general_throttle_count = 501,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 502,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 503,      /* general_oper_umodes  */
  YYSYMBOL_504_25 = 504,                   /* $@25  */
  YYSYMBOL_umode_oitems = 505,             /* umode_oitems  */
  YYSYMBOL_umode_oitem = 506,              /* umode_oitem  */
  YYSYMBOL_general_oper_only_umodes = 507, /* general_oper_only_umodes  */
  YYSYMBOL_508_26 = 508,                   /* $@26  */
  YYSYMBOL_umode_items = 509,              /* umode_items  */
  YYSYMBOL_umode_item = 510,               /* umode_item  */
  YYSYMBOL_general_min_nonwildcard = 511,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 512, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 513, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 514, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 515,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 516, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 517, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 518,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 519,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 520,     /* general_cloak_suffix  */
  YYSYMBOL_channel_entry = 521,            /* channel_entry  */
  YYSYMBOL_channel_items = 522,            /* channel_items  */
  YYSYMBOL_channel_item = 523,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 524,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 525,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 526,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 527, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 528, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 529, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 530, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 531, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 532, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 533, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 534, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 535,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 536,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 537,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 538,   /* channel_max_bans_large  */
  YYSYMBOL_channel_default_join_flood_count = 539, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 540, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 541,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 542,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 543,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 544, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 545, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 546, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 547, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 548,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 549, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 550,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 551,        /* serverhide_hidden  */
  YYSYMBOL_serverhide_hide_server_ips = 552 /* serverhide_hide_server_ips  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   1395

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  252
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  301
/* YYNRULES -- Number of rules.  */
#define YYNRULES  683
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1350

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   500


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
       2,     2,     2,     2,   250,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   249,   246,
       2,   248,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   251,     2,   247,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   382,   382,   383,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   414,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   425,
     425,   426,   427,   428,   429,   436,   446,   453,   455,   457,
     457,   459,   463,   473,   475,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   495,   504,   513,   522,   531,   540,   549,
     558,   573,   588,   598,   612,   621,   644,   667,   690,   700,
     702,   702,   703,   704,   705,   706,   708,   717,   726,   740,
     739,   757,   757,   758,   758,   758,   760,   766,   777,   776,
     795,   795,   796,   796,   796,   796,   796,   798,   804,   810,
     816,   839,   840,   840,   842,   842,   843,   845,   852,   852,
     865,   866,   868,   868,   869,   869,   871,   879,   882,   888,
     887,   893,   897,   901,   905,   909,   913,   917,   921,   932,
     931,   995,   995,   996,   997,   998,   999,  1000,  1001,  1002,
    1003,  1004,  1005,  1006,  1008,  1014,  1020,  1026,  1032,  1043,
    1049,  1060,  1067,  1066,  1072,  1072,  1073,  1077,  1081,  1085,
    1089,  1093,  1097,  1101,  1105,  1109,  1113,  1117,  1121,  1125,
    1129,  1133,  1137,  1141,  1145,  1149,  1153,  1157,  1164,  1163,
    1169,  1169,  1170,  1174,  1178,  1182,  1186,  1190,  1194,  1198,
    1202,  1206,  1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,
    1242,  1246,  1250,  1254,  1258,  1262,  1266,  1270,  1274,  1278,
    1282,  1286,  1297,  1296,  1352,  1352,  1353,  1354,  1355,  1356,
    1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,  1366,
    1367,  1368,  1370,  1376,  1382,  1388,  1394,  1400,  1406,  1412,
    1418,  1425,  1431,  1437,  1443,  1452,  1462,  1461,  1467,  1467,
    1468,  1472,  1483,  1482,  1489,  1488,  1493,  1493,  1494,  1498,
    1502,  1506,  1510,  1516,  1516,  1517,  1517,  1517,  1517,  1517,
    1519,  1519,  1521,  1521,  1523,  1536,  1553,  1559,  1570,  1569,
    1617,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,  1625,
    1626,  1628,  1634,  1640,  1646,  1658,  1657,  1663,  1663,  1664,
    1668,  1672,  1676,  1680,  1684,  1688,  1692,  1696,  1702,  1716,
    1725,  1739,  1738,  1753,  1753,  1754,  1754,  1754,  1754,  1756,
    1762,  1768,  1778,  1780,  1780,  1781,  1781,  1783,  1800,  1799,
    1822,  1822,  1823,  1823,  1823,  1823,  1825,  1831,  1851,  1850,
    1856,  1856,  1857,  1861,  1865,  1869,  1873,  1877,  1881,  1885,
    1889,  1893,  1904,  1903,  1922,  1922,  1923,  1923,  1923,  1925,
    1932,  1931,  1937,  1937,  1938,  1942,  1946,  1950,  1954,  1958,
    1962,  1966,  1970,  1974,  1985,  1984,  2062,  2062,  2063,  2064,
    2065,  2066,  2067,  2068,  2069,  2070,  2071,  2072,  2073,  2074,
    2075,  2076,  2077,  2078,  2080,  2086,  2092,  2098,  2104,  2117,
    2130,  2136,  2142,  2146,  2153,  2152,  2157,  2157,  2158,  2162,
    2168,  2179,  2185,  2191,  2197,  2213,  2212,  2236,  2236,  2237,
    2237,  2237,  2239,  2259,  2270,  2269,  2294,  2294,  2295,  2295,
    2295,  2297,  2303,  2313,  2315,  2315,  2316,  2316,  2318,  2336,
    2335,  2356,  2356,  2357,  2357,  2357,  2359,  2365,  2375,  2377,
    2377,  2378,  2379,  2380,  2381,  2382,  2383,  2384,  2385,  2386,
    2387,  2388,  2389,  2390,  2391,  2392,  2393,  2394,  2395,  2396,
    2397,  2398,  2399,  2400,  2401,  2402,  2403,  2404,  2405,  2406,
    2407,  2408,  2409,  2410,  2411,  2412,  2413,  2414,  2415,  2416,
    2417,  2418,  2419,  2420,  2421,  2422,  2423,  2424,  2425,  2426,
    2427,  2428,  2429,  2432,  2437,  2442,  2447,  2452,  2457,  2462,
    2467,  2472,  2477,  2482,  2487,  2492,  2497,  2502,  2507,  2512,
    2517,  2522,  2527,  2532,  2537,  2542,  2547,  2552,  2557,  2562,
    2567,  2572,  2577,  2582,  2587,  2592,  2597,  2602,  2607,  2612,
    2617,  2622,  2628,  2627,  2632,  2632,  2633,  2636,  2639,  2642,
    2645,  2648,  2651,  2654,  2657,  2660,  2663,  2666,  2669,  2672,
    2675,  2678,  2681,  2684,  2687,  2690,  2693,  2696,  2702,  2701,
    2706,  2706,  2707,  2710,  2713,  2716,  2719,  2722,  2725,  2728,
    2731,  2734,  2737,  2740,  2743,  2746,  2749,  2752,  2755,  2758,
    2761,  2764,  2767,  2770,  2775,  2780,  2785,  2790,  2795,  2812,
    2820,  2828,  2836,  2846,  2859,  2861,  2861,  2862,  2863,  2864,
    2865,  2866,  2867,  2868,  2869,  2870,  2871,  2872,  2873,  2874,
    2875,  2876,  2877,  2878,  2879,  2881,  2886,  2892,  2898,  2903,
    2908,  2913,  2918,  2923,  2928,  2933,  2938,  2943,  2948,  2953,
    2958,  2963,  2972,  2974,  2974,  2975,  2976,  2977,  2978,  2979,
    2980,  2981,  2982,  2983,  2984,  2986,  2992,  3008,  3017,  3023,
    3029,  3035,  3044,  3050
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ACCEPT_PASSWORD",
  "ADMIN", "AFTYPE", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME",
  "AUTOCONN", "AWAY_COUNT", "AWAY_TIME", "BOT", "BYTES", "KBYTES",
  "MBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL", "CIDR_BITLEN_IPV4",
  "CIDR_BITLEN_IPV6", "CLASS", "CLIENT", "CLOAK_ENABLED",
  "CLOAK_CIDR_LEN_IPV4", "CLOAK_CIDR_LEN_IPV6", "CLOAK_NUM_BITS",
  "CLOAK_SECRET", "CLOAK_SUFFIX", "CLOSE", "CONNECT", "CONNECTFREQ",
  "CORE", "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_FLOODTIME", "DEFAULT_JOIN_FLOOD_COUNT",
  "DEFAULT_JOIN_FLOOD_TIME", "DEFAULT_MAX_CLIENTS", "DEFER", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6", "EMAIL",
  "ENABLE_ADMIN", "ENABLE_EXTBANS", "ENABLE_OWNER", "ENCRYPTED",
  "EXCEED_LIMIT", "EXEMPT", "EXPIRATION", "FAILED_OPER_NOTICE",
  "FLATTEN_LINKS", "FLATTEN_LINKS_DELAY", "FLATTEN_LINKS_FILE", "GECOS",
  "GENERAL", "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
  "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS", "HIDE_SERVERS",
  "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK", "INVISIBLE_ON_CONNECT",
  "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME", "INVITE_DELAY_CHANNEL",
  "INVITE_EXPIRE_TIME", "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID",
  "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6", "KNOCK_CLIENT_COUNT",
  "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LISTEN",
  "LOADMODULE", "MASK", "MASS", "MAX_ACCEPT", "MAX_BANS", "MAX_BANS_LARGE",
  "MAX_CHANNELS", "MAX_IDLE", "MAX_INVITES", "MAX_MONITOR",
  "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MESSAGE", "MIN_IDLE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE",
  "MODULE_BASE_PATH", "MOTD", "NAME", "NEED_IDENT", "NEED_PASSWORD",
  "NETWORK_DESCRIPTION", "NETWORK_NAME", "NICK", "NO_OPER_FLOOD",
  "NO_TILDE", "NUMBER_PER_CIDR", "NUMBER_PER_IP_GLOBAL",
  "NUMBER_PER_IP_LOCAL", "OPER_ONLY_UMODES", "OPER_UMODES", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD",
  "PATH", "PING_COOKIE", "PING_TIME", "PORT", "RANDOM_IDLE", "REASON",
  "REDIRPORT", "REDIRSERV", "REHASH", "REMOTE", "REMOTEBAN", "RESIDENT",
  "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ",
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPECIALS_IN_IDENT", "SPOOF",
  "SQUIT", "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_M_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY",
  "STATS_U_OPER_ONLY", "T_ALL", "T_BIND", "T_CALLERID", "T_CCONN",
  "T_COMMAND", "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FARCONNECT", "T_FILE", "T_FLOOD", "T_GLOBOPS", "T_INVISIBLE",
  "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_NCHANGE", "T_NONONREG",
  "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ", "T_REJ", "T_RESTART",
  "T_SECUREONLY", "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET",
  "T_SHARED", "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_TARGET",
  "T_TLS", "T_UMODES", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE",
  "T_WALLOP", "T_WALLOPS", "T_WEBIRC", "TBOOL", "THROTTLE_COUNT",
  "THROTTLE_TIME", "TIMEOUT", "TLS_CERTIFICATE_FILE",
  "TLS_CERTIFICATE_FINGERPRINT", "TLS_CIPHER_LIST", "TLS_CIPHER_SUITES",
  "TLS_CONNECTION_REQUIRED", "TLS_DH_PARAM_FILE",
  "TLS_MESSAGE_DIGEST_ALGORITHM", "TLS_SUPPORTED_GROUPS", "TS_MAX_DELTA",
  "TS_WARN_DELTA", "TWODOTS", "TYPE", "UNKLINE", "USE_LOGGING", "USER",
  "VHOST", "VHOST6", "WARN_NO_CONNECT_BLOCK", "WHOIS",
  "WHOWAS_HISTORY_LENGTH", "XLINE", "XLINE_EXEMPT", "QSTRING", "NUMBER",
  "';'", "'}'", "'='", "':'", "','", "'{'", "$accept", "conf", "conf_item",
  "timespec_", "timespec", "sizespec_", "sizespec",
  "module_base_path_entry", "loadmodule_entry", "module_attributes",
  "module_attributes_items", "module_attributes_item", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_tls_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_tls_dh_param_file",
  "serverinfo_tls_cipher_list", "serverinfo_tls_cipher_suites",
  "serverinfo_tls_message_digest_algorithm",
  "serverinfo_tls_supported_groups", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_description", "serverinfo_default_max_clients",
  "serverinfo_max_nick_length", "serverinfo_max_topic_length",
  "serverinfo_hub", "admin_entry", "admin_items", "admin_item",
  "admin_name", "admin_email", "admin_description", "motd_entry", "$@1",
  "motd_items", "motd_item", "motd_mask", "motd_file", "pseudo_entry",
  "$@2", "pseudo_items", "pseudo_item", "pseudo_command", "pseudo_name",
  "pseudo_prepend", "pseudo_target", "logging_entry", "logging_items",
  "logging_item", "logging_use_logging", "logging_file_entry", "$@3",
  "logging_file_items", "logging_file_item", "logging_file_name",
  "logging_file_size", "logging_file_type", "$@4",
  "logging_file_type_item", "oper_entry", "$@5", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_whois",
  "oper_encrypted", "oper_tls_certificate_fingerprint",
  "oper_tls_connection_required", "oper_class", "oper_umodes", "$@6",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@7",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@8",
  "class_items", "class_item", "class_name", "class_ping_time",
  "class_number_per_ip_local", "class_number_per_ip_global",
  "class_connectfreq", "class_max_channels", "class_max_number",
  "class_sendq", "class_recvq", "class_cidr_bitlen_ipv4",
  "class_cidr_bitlen_ipv6", "class_number_per_cidr", "class_min_idle",
  "class_max_idle", "class_flags", "$@9", "class_flags_items",
  "class_flags_item", "listen_entry", "$@10", "listen_flags", "$@11",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "$@12", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "$@13", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_class", "auth_encrypted", "auth_flags",
  "$@14", "auth_flags_items", "auth_flags_item", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "resv_entry", "$@15", "resv_items",
  "resv_item", "resv_mask", "resv_reason", "resv_exempt", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@16",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@17", "shared_types", "shared_type_item",
  "cluster_entry", "$@18", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@19", "cluster_types", "cluster_type_item",
  "connect_entry", "$@20", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_timeout", "connect_bind",
  "connect_send_password", "connect_accept_password",
  "connect_tls_certificate_fingerprint", "connect_port", "connect_aftype",
  "connect_flags", "$@21", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_tls_cipher_list", "kill_entry", "$@22",
  "kill_items", "kill_item", "kill_user", "kill_reason", "deny_entry",
  "$@23", "deny_items", "deny_item", "deny_ip", "deny_reason",
  "exempt_entry", "exempt_items", "exempt_item", "exempt_ip",
  "gecos_entry", "$@24", "gecos_items", "gecos_item", "gecos_name",
  "gecos_reason", "general_entry", "general_items", "general_item",
  "general_away_count", "general_away_time", "general_max_monitor",
  "general_whowas_history_length", "general_cycle_on_host_change",
  "general_dline_min_cidr", "general_dline_min_cidr6",
  "general_kline_min_cidr", "general_kline_min_cidr6",
  "general_kill_chase_time_limit", "general_failed_oper_notice",
  "general_anti_nick_flood", "general_max_nick_time",
  "general_max_nick_changes", "general_max_accept",
  "general_anti_spam_exit_message_time", "general_ts_warn_delta",
  "general_ts_max_delta", "general_invisible_on_connect",
  "general_warn_no_connect_block", "general_stats_e_disabled",
  "general_stats_m_oper_only", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_u_oper_only",
  "general_stats_k_oper_only", "general_stats_i_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_opers_bypass_callerid", "general_pace_wait_simple",
  "general_short_motd", "general_no_oper_flood",
  "general_specials_in_ident", "general_max_targets",
  "general_ping_cookie", "general_disable_auth", "general_throttle_count",
  "general_throttle_time", "general_oper_umodes", "$@25", "umode_oitems",
  "umode_oitem", "general_oper_only_umodes", "$@26", "umode_items",
  "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_default_floodtime", "general_cloak_enabled",
  "general_cloak_cidr_len_ipv4", "general_cloak_cidr_len_ipv6",
  "general_cloak_num_bits", "general_cloak_secret", "general_cloak_suffix",
  "channel_entry", "channel_items", "channel_item",
  "channel_enable_extbans", "channel_enable_owner", "channel_enable_admin",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_invite_delay_channel",
  "channel_invite_expire_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_channels", "channel_max_invites", "channel_max_bans",
  "channel_max_bans_large", "channel_default_join_flood_count",
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

#define YYPACT_NINF (-778)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-129)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -778,   854,  -778,  -146,  -245,  -240,  -778,  -778,  -778,  -203,
    -778,  -201,  -778,  -778,  -778,  -185,  -219,  -778,  -778,  -778,
    -183,  -180,  -778,  -175,  -778,  -163,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,    22,   961,  -157,  -134,  -124,    20,  -117,
     441,  -112,   -88,   -86,  -206,  -129,   -81,   -78,   -75,   755,
     520,   -74,    64,   -71,    16,   -58,   -52,   -51,   -33,   -32,
      14,  -778,  -778,  -778,  -778,  -778,   -13,   -10,    -9,    -1,
      53,    60,    63,    67,    72,    77,    78,    80,    87,    88,
      97,    98,   101,   155,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,   709,   618,    32,  -778,   102,    21,  -778,  -778,
      94,  -778,   107,   111,   115,   117,   119,   124,   125,   126,
     128,   134,   135,   136,   137,   138,   140,   141,   144,   145,
     146,   147,   148,   149,   152,   153,   156,   157,   159,   161,
     162,   164,  -778,  -778,   180,   182,   183,   184,   185,   187,
     189,   191,   193,   195,   196,   197,   198,   205,   209,   210,
     211,   214,   221,    57,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,   357,     6,   292,   -12,
     -37,    61,    31,   355,    73,  -778,   222,   224,   228,   229,
     232,   233,   234,   236,   241,   213,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,    66,   243,   244,   245,
     247,   251,   252,   255,   256,   259,   262,   263,   266,   267,
     268,   269,   270,    38,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,    86,   106,   272,    59,  -778,  -778,  -778,   279,   173,
    -778,   274,    45,  -778,  -778,    85,  -778,   118,   235,   282,
     260,  -778,   278,   284,   294,   312,   313,   318,   293,   284,
     284,   284,   295,   284,   284,   296,   297,   302,   304,   305,
    -778,   308,   291,   307,   310,  -778,   311,   314,   316,   319,
     322,   326,   329,   331,   332,   334,   335,   254,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,   320,   336,   339,   341,   348,   349,
     364,  -778,   366,   367,   368,   370,   372,   374,   381,   382,
     231,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,   383,   385,
      43,  -778,  -778,  -778,   306,   358,  -778,  -778,   386,   387,
      56,  -778,  -778,  -778,   338,   284,   396,   284,   284,   425,
     399,   400,   402,   409,   410,   437,   412,   284,   440,   414,
     418,   446,   447,   284,   421,   428,   429,   430,   431,   284,
     432,   433,   436,   466,   438,   442,   467,   284,   284,   473,
     475,   449,   477,   480,   481,   482,   485,   490,   493,   468,
     284,   284,   284,   494,   469,   470,  -778,   476,   471,   483,
    -778,   484,   487,   488,   489,   492,   258,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,   495,   503,    69,
    -778,  -778,  -778,   478,   505,   510,  -778,   515,  -778,    44,
    -778,  -778,  -778,  -778,  -778,  -778,   479,  -778,  -778,  -778,
     518,   519,   522,    17,  -778,  -778,  -778,   526,   527,   529,
    -778,   532,   533,  -778,   534,   535,   537,   539,   104,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
     545,   544,   548,   550,     2,  -778,  -778,  -778,  -778,   512,
     523,   284,   556,   583,   558,   587,   592,   596,   572,  -778,
    -778,   521,   576,   606,   582,   584,   585,   593,   594,   599,
     600,   602,   603,   605,   607,   608,   609,   581,  -778,   586,
     580,  -778,    84,  -778,  -778,  -778,  -778,   613,   590,  -778,
     472,   604,   611,   612,   614,   615,     3,  -778,  -778,  -778,
    -778,  -778,   617,   610,  -778,   619,   616,  -778,   620,    50,
    -778,  -778,  -778,  -778,   621,   626,   629,  -778,   632,   264,
     634,   636,   639,   642,   643,   644,   645,   649,   650,   652,
     653,   654,   659,   660,   662,   663,  -778,  -778,   595,   667,
     284,   670,   674,   284,   676,   284,   671,   677,   680,   682,
     284,   684,   684,   691,  -778,  -778,   686,   -39,   694,   722,
     698,   701,   703,   710,   711,   708,   712,   713,   284,   715,
     716,   717,  -778,   720,   721,   724,  -778,   725,  -778,   723,
     728,   727,  -778,   730,   733,   734,   735,   736,   738,   739,
     740,   741,   742,   744,   745,   746,   747,   748,   749,   753,
     756,   757,   759,   761,   762,   768,   769,   770,   771,   772,
     773,   774,   775,   588,   696,   776,   777,   778,   779,   780,
     781,   782,   783,   785,   786,   787,   792,   793,   794,   795,
     796,   798,   799,   800,  -778,  -778,   803,   834,   718,   809,
     729,   811,   812,   817,   818,  -778,   819,   821,   820,  -778,
    -778,   823,   824,   822,   826,   827,  -778,   -12,  -778,   825,
     828,   829,  -778,  -778,   830,   858,   831,   833,   836,   835,
     837,   860,   838,   840,   839,  -778,  -778,   842,   843,   844,
     845,  -778,   846,   847,   848,   849,   850,   851,   852,   853,
     855,  -778,   856,   857,   859,   861,   862,   863,   864,   865,
     866,   867,   868,   869,   870,   871,   872,   873,  -778,  -778,
     876,   841,   875,  -778,   877,  -778,    15,  -778,   878,   880,
     881,   882,   883,  -778,   884,  -778,  -778,   887,   879,   888,
     889,  -778,  -778,  -778,  -778,  -778,   284,   284,   284,   284,
     284,   284,   284,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,   890,   891,   892,   -45,   893,   894,   895,   896,   897,
     898,   899,   900,   901,    13,   902,   903,  -778,   904,   905,
     906,   907,   908,   909,   910,    -3,   911,   912,   913,   914,
     915,   916,   917,   918,  -778,   919,   920,  -778,  -778,   921,
     922,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -222,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -216,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,   923,
     924,   509,   925,   926,   927,   928,   929,  -778,   930,   931,
    -778,   932,   933,   114,   625,   751,  -778,  -778,  -778,   934,
     935,  -778,   936,   937,   504,   938,   939,   743,   940,   941,
     942,   943,  -778,   944,   945,   946,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,   947,   491,  -778,  -778,   948,   885,   886,  -778,
      91,  -778,  -778,  -778,  -778,   949,   950,   951,   952,  -778,
    -778,   953,   764,   954,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -215,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,   684,   684,
     684,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -210,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,   588,
    -778,   696,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -209,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -208,
    -778,   956,   826,   957,  -778,  -778,  -778,  -778,  -778,  -778,
     955,  -778,   958,   959,  -778,   960,  -778,   962,   963,  -778,
    -778,   964,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -197,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -194,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -173,  -778,  -778,   966,  -198,   967,   968,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -136,  -778,  -778,  -778,   -45,  -778,  -778,
    -778,  -778,    -3,  -778,  -778,  -778,   509,  -778,   114,  -778,
    -778,  -778,   578,   815,   985,   995,  1056,  1062,  1063,  -778,
     504,  -778,   743,  -778,   491,   970,   971,   972,   356,  -778,
    -778,   764,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,   973,  -778,  -778
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   232,   394,   444,     0,
     459,     0,   298,   435,   272,     0,     0,    99,   149,   331,
       0,     0,   372,     0,   108,     0,   348,     3,     4,     5,
      13,     6,    25,    26,     7,     8,    10,    11,    12,    15,
      16,    17,    18,    19,    20,    21,    22,    24,    23,     9,
      14,    27,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    94,    93,   644,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   626,   641,   642,   643,   640,   629,
     630,   631,   632,   633,   634,   635,   636,   637,   627,   628,
     638,   639,     0,     0,     0,   457,     0,     0,   455,   456,
       0,   522,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   588,   562,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   470,   471,   472,   514,   478,   515,
     509,   510,   511,   512,   482,   473,   474,   475,   476,   477,
     479,   480,   481,   483,   484,   513,   488,   489,   490,   491,
     487,   486,   492,   499,   500,   493,   494,   495,   485,   497,
     507,   508,   505,   506,   498,   496,   503,   504,   501,   502,
     516,   517,   518,   519,   520,   521,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   674,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   664,   665,   666,   667,
     668,   669,   670,   672,   671,   673,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    68,    66,    64,    69,    70,
      71,    65,    56,    67,    58,    59,    60,    61,    62,    63,
      57,     0,     0,     0,     0,   123,   124,   125,     0,     0,
     346,     0,     0,   344,   345,     0,    95,     0,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     625,     0,     0,     0,     0,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   236,
     239,   241,   242,   243,   244,   245,   246,   247,   237,   238,
     240,   248,   249,   250,     0,     0,     0,     0,     0,     0,
       0,   424,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   397,   398,   399,   400,   401,   402,   403,   404,   406,
     405,   408,   412,   409,   410,   411,   407,   450,     0,     0,
       0,   447,   448,   449,     0,     0,   454,   465,     0,     0,
       0,   462,   463,   464,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   469,     0,     0,     0,
     315,     0,     0,     0,     0,     0,     0,   301,   302,   303,
     304,   309,   305,   306,   307,   308,   441,     0,     0,     0,
     438,   439,   440,     0,     0,     0,   274,     0,   286,     0,
     284,   285,   287,   288,    52,    51,    48,    50,    46,    45,
       0,     0,     0,     0,   102,   103,   104,     0,     0,     0,
     198,     0,     0,   172,     0,     0,     0,     0,     0,   152,
     153,   154,   155,   156,   159,   160,   161,   158,   157,   162,
       0,     0,     0,     0,     0,   334,   335,   336,   337,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   663,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,   380,     0,   375,   376,   377,   126,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     0,   111,   112,   114,
     113,   115,     0,     0,   343,     0,     0,   358,     0,     0,
     351,   352,   353,   354,     0,     0,     0,    89,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   624,   251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,   413,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   396,     0,     0,     0,   446,     0,   453,     0,
       0,     0,   461,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   468,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   300,     0,     0,     0,   437,
     289,     0,     0,     0,     0,     0,   283,     0,   105,     0,
       0,     0,   101,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,   338,     0,     0,     0,
       0,   333,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   662,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,   378,
       0,     0,     0,   374,     0,   121,     0,   116,     0,     0,
       0,     0,     0,   110,     0,   342,   355,     0,     0,     0,
       0,   350,    98,    97,    96,   660,    29,    29,    29,    29,
      29,    29,    29,    31,    30,   661,   648,   647,   645,   646,
     649,   650,   651,   652,   653,   654,   655,   658,   659,   656,
     657,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   395,     0,     0,   445,   458,     0,
       0,   460,   534,   538,   523,   524,   551,   618,   619,   620,
     621,   622,   623,   527,   616,   617,   559,   528,   529,   533,
     541,   532,   530,   531,   537,   525,   536,   535,   557,   614,
     615,   555,   592,   612,   597,   598,   599,   608,   593,   594,
     603,   611,   595,   605,   609,   600,   610,   601,   613,   604,
     596,   607,   602,   606,     0,   591,   566,   586,   570,   571,
     572,   582,   567,   568,   577,   585,   569,   579,   583,   574,
     584,   575,   587,   578,   573,   581,   576,   580,     0,   565,
     552,   550,   553,   558,   554,   556,   543,   549,   548,   544,
     545,   546,   547,   560,   561,   540,   539,   542,   526,     0,
       0,     0,     0,     0,     0,     0,     0,   299,     0,     0,
     436,     0,     0,     0,   294,   290,   293,   273,    49,     0,
       0,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,     0,     0,     0,   332,   678,   675,   676,
     677,   682,   681,   683,   679,   680,    85,    82,    88,    81,
      86,    87,    80,    84,    83,    74,    73,    76,    77,    75,
      78,    79,     0,     0,   373,   127,     0,     0,     0,   139,
       0,   131,   132,   134,   133,     0,     0,     0,     0,   109,
     347,     0,     0,     0,   349,    32,    33,    34,    35,    36,
      37,    38,   261,   262,   256,   271,   270,     0,   269,   257,
     265,   258,   264,   252,   263,   255,   254,   253,    39,    39,
      39,    41,    40,   259,   260,   419,   422,   423,   433,   430,
     415,   431,   428,   429,     0,   427,   432,   414,   421,   418,
     417,   416,   420,   434,   451,   452,   466,   467,   589,     0,
     563,     0,   313,   314,   323,   319,   320,   322,   327,   324,
     325,   326,   321,     0,   318,   312,   330,   329,   328,   311,
     443,   442,   297,   296,   281,   282,   279,   280,   278,     0,
     277,     0,     0,     0,   106,   107,   171,   168,   218,   230,
     205,   214,     0,   203,   208,     0,   224,     0,   217,   222,
     228,   207,   210,   219,   221,   225,   215,   223,   211,   229,
     213,   220,   209,   212,     0,   201,   164,   166,   176,   196,
     180,   181,   182,   192,   177,   178,   187,   195,   179,   189,
     193,   184,   194,   185,   197,   188,   183,   191,   186,   190,
       0,   175,   169,   170,   165,   167,   341,   339,   340,   379,
     384,   390,   393,   386,   392,   387,   391,   389,   385,   388,
       0,   383,   135,     0,     0,     0,     0,   130,   118,   117,
     119,   120,   356,   362,   368,   371,   364,   370,   365,   369,
     367,   363,   366,     0,   361,   357,   267,     0,    42,    43,
      44,   425,     0,   590,   564,   316,     0,   275,     0,   295,
     292,   291,     0,     0,     0,     0,     0,     0,     0,   199,
       0,   173,     0,   381,     0,     0,     0,     0,     0,   129,
     359,     0,   268,   426,   317,   276,   204,   227,   202,   231,
     226,   216,   206,   200,   174,   382,   136,   138,   137,   147,
     146,   142,   144,   148,   145,   141,   143,     0,   360,   140
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -778,  -778,  -778,  -425,  -321,  -777,  -661,  -778,  -778,  -778,
    -778,   333,  -778,  -778,   706,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  1024,  -778,  -778,  -778,  -778,  -778,  -778,
     697,  -778,  -778,  -778,  -778,  -778,   500,  -778,  -778,  -778,
    -778,  -778,  -778,   965,  -778,  -778,  -778,  -778,   142,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,   683,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,   -89,
    -778,  -778,  -778,   -85,  -778,  -778,  -778,   874,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,   -63,  -778,  -778,  -778,  -778,
    -778,   -72,  -778,   719,  -778,  -778,  -778,    47,  -778,  -778,
    -778,  -778,  -778,   750,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,   -69,  -778,  -778,  -778,  -778,  -778,  -778,   678,  -778,
    -778,  -778,  -778,  -778,   969,  -778,  -778,  -778,  -778,   622,
    -778,  -778,  -778,  -778,  -778,   -91,  -778,  -778,  -778,   641,
    -778,  -778,  -778,  -778,   -80,  -778,  -778,  -778,   974,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,   -57,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
     752,  -778,  -778,  -778,  -778,  -778,   832,  -778,  -778,  -778,
    -778,  1110,  -778,  -778,  -778,  -778,   975,  -778,  -778,  -778,
    -778,  1055,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,    89,  -778,  -778,  -778,    90,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  1140,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,   989,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   853,   854,  1121,  1122,    28,    29,   240,
     516,   517,    30,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,    31,    80,    81,    82,    83,    84,    32,    66,   523,
     524,   525,   526,    33,    73,   606,   607,   608,   609,   610,
     611,    34,   304,   305,   306,   307,   308,  1080,  1081,  1082,
    1083,  1084,  1265,  1347,    35,    67,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   779,  1240,  1241,
     549,   776,  1214,  1215,    36,    55,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   651,  1107,  1108,    37,    63,   508,   763,
    1179,  1180,   509,   510,   511,  1183,  1025,  1026,   512,   513,
      38,    61,   486,   487,   488,   489,   490,   491,   492,   748,
    1163,  1164,   493,   494,   495,    39,    68,   554,   555,   556,
     557,   558,    40,   312,   313,   314,    41,    75,   619,   620,
     621,   622,   623,   838,  1283,  1284,    42,    71,   592,   593,
     594,   595,   821,  1260,  1261,    43,    56,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   672,
    1134,  1135,   402,   403,   404,   405,   406,    44,    62,   499,
     500,   501,   502,    45,    57,   410,   411,   412,   413,    46,
     127,   128,   129,    47,    59,   420,   421,   422,   423,    48,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   455,   988,   989,   225,   454,   964,   965,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    49,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    50,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     885,   886,   630,   550,   601,  1132,    53,   496,   636,   637,
     638,    54,   640,   641,  1316,    76,  1076,   310,   520,   514,
    1105,   125,   125,    76,  1148,  1118,  1119,  1120,  1149,    65,
    1150,  1286,   520,   407,  1151,  1287,  1291,  1295,  1297,   266,
    1292,  1296,  1298,   239,   407,   503,   310,   884,    58,  1309,
      60,   615,  1311,  1310,    77,   551,  1312,   417,   131,    64,
     302,    78,    77,   132,   133,   302,   134,   135,    69,    78,
     496,    70,   136,  1313,   550,   267,    72,  1314,   268,   137,
     138,   139,   140,   141,   142,   589,   615,   589,    74,   143,
     144,   145,  1076,  1106,   122,   417,   552,   126,   126,   146,
      51,    52,   147,   148,   694,   527,   696,   697,   269,   408,
    1320,   521,   149,   504,  1321,   241,   706,   123,   270,   602,
     408,   505,   712,   506,   528,   521,   551,   124,   718,   150,
      79,  1077,   311,   515,   130,  1174,   726,   727,    79,   236,
     151,   553,   271,   152,   153,   497,   272,   889,   890,   739,
     740,   741,  1175,   154,   273,   529,    85,   274,   275,   155,
     156,   311,   157,   237,   158,   238,   616,   552,   159,   160,
     242,   409,   418,   243,   601,  1176,   244,   301,   603,   161,
     309,   507,   409,   530,   162,   163,   276,   164,   165,   166,
      86,    87,   167,   315,   316,   419,   604,   317,    88,   522,
     590,   616,   590,    89,    90,    91,  1133,  1077,   497,   518,
     418,   605,   553,   522,   245,   318,   319,   168,   169,  1078,
     531,   170,   171,   172,   173,   174,   175,   176,    92,    93,
      94,    95,   374,   419,   375,   322,   376,   532,   323,   324,
     794,  -128,   498,    96,    97,    98,  -128,   325,  1079,   790,
     832,   377,    99,   100,   101,   341,   102,   246,   884,   477,
     277,   320,   278,   279,   771,   280,   281,   282,   415,   247,
     248,   249,   342,   343,   250,   251,   177,   178,   478,   252,
     253,   254,   378,   617,   344,   587,   618,   179,   180,   602,
     685,   765,   613,   503,   303,  1078,   181,   840,   182,   303,
     379,   326,   380,   691,   475,   498,   598,   519,   327,   479,
     381,   328,   570,  1177,   533,   329,   758,   591,   617,   591,
     330,   618,   382,  1178,  1079,   331,   332,   534,   333,   873,
     535,   822,   876,   345,   878,   334,   335,   480,  1266,   883,
     536,  1288,  1289,  1290,   537,   336,   337,   383,   603,   338,
     414,   784,   596,   346,   347,   424,   527,   901,   477,   425,
     348,   504,   624,   426,   349,   427,   604,   428,   384,   505,
     350,   506,   429,   430,   431,   528,   432,   478,   351,   352,
     353,   605,   433,   434,   435,   436,   437,   385,   438,   439,
     354,   481,   440,   441,   442,   443,   444,   445,   482,   483,
     446,   447,   339,   386,   448,   449,   529,   450,   479,   451,
     452,   355,   453,   846,   847,   848,   849,   850,   851,   852,
     484,  1095,  1096,  1097,  1098,  1099,  1100,  1101,   456,   507,
     457,   458,   459,   460,   530,   461,   480,   462,  1339,   463,
    1340,   464,   131,   465,   466,   467,   468,   132,   133,   356,
     134,   135,   387,   469,   388,   389,   136,   470,   471,   472,
     568,   600,   473,   137,   138,   139,   140,   141,   142,   474,
     559,   531,   560,   143,   144,   145,   561,   562,   681,   625,
     563,   564,   565,   146,   566,  1341,   147,   148,   532,   567,
     481,   571,   572,   573,   485,   574,   149,   482,   483,   575,
     576,   663,  1342,   577,   578,   754,   627,   579,  1188,   629,
     580,   581,   631,   150,   582,   583,   584,   585,   586,   484,
     597,   266,   612,   628,   151,  1154,   626,   152,   153,   629,
     632,   633,  1189,  1190,  1343,  1344,   634,   154,   635,   648,
     639,   642,   643,   155,   156,  1191,   157,   644,   158,   645,
     687,   646,   159,   160,   647,   649,   693,   267,   650,   652,
     268,  1155,   653,   161,   654,   533,   665,   655,   162,   163,
     656,   164,   165,   166,   657,  1250,   167,   658,   534,   659,
     660,   535,   661,   662,   666,  1192,  1193,   667,  1194,   668,
     269,   536,  1345,   485,  1156,   537,   669,   670,  1346,   942,
     270,   168,   169,  1317,   688,   170,   171,   172,   173,   174,
     175,   176,   671,  1195,   673,   674,   675,  1196,   676,   374,
     677,   375,   678,   376,   271,  1197,  1157,  1158,   272,   679,
     680,   683,  1159,   684,   689,   690,   273,  1251,   377,   274,
     275,   695,   943,   698,   699,   700,  1198,   701,  1199,   944,
    1200,   945,   946,   702,   703,   704,  1160,   705,   707,   708,
     177,   178,  1252,   709,   710,   711,   713,  1201,   276,   378,
    1253,   179,   180,   714,   715,   716,   717,   719,   720,  1254,
     181,   721,   182,  1202,   722,   725,   723,   379,  1203,   380,
     724,   728,  1204,   729,   730,   731,  1205,   381,   732,   733,
     734,  1206,  1255,   735,  1256,  1257,  1207,   966,   736,   382,
     341,   737,   742,   738,   743,  1208,   744,  1209,  1210,   746,
    1211,  1326,   745,   826,   760,  1258,  1161,   342,   343,   767,
     792,   747,   749,  1259,   383,   750,   751,   752,  1212,   344,
     753,   793,   277,   756,   278,   279,  1213,   280,   281,   282,
     967,   757,  1162,   761,  1218,   384,   245,   968,   762,   969,
     970,   947,   948,   764,   768,   949,   802,   769,   950,   951,
     770,   952,   773,   953,   385,   774,   954,   775,   955,   956,
     777,   778,   780,   781,   957,   782,   958,   783,   345,   959,
     386,   786,   787,   960,   961,   962,   788,  1219,   789,   246,
     795,   796,   797,   963,  1220,   798,  1221,  1222,   346,   347,
     799,   247,   248,   249,   800,   348,   250,   251,   801,   349,
     803,   252,   253,   254,   804,   350,   805,   818,   820,   806,
     807,   824,   819,   351,   352,   353,   825,   808,   809,   387,
     871,   388,   389,   810,   811,   354,   812,   813,  1273,   814,
     827,   815,   816,   817,     2,     3,   835,  1181,     4,   828,
     829,   834,   830,   831,   837,   836,   355,   842,   839,   971,
     972,     5,   843,   973,     6,   844,   974,   975,   845,   976,
     855,   977,   856,     7,   978,   857,   979,   980,   858,   859,
     860,   861,   981,     8,   982,   862,   863,   983,   864,   865,
     866,   984,   985,   986,   356,   867,   868,     9,   869,   870,
    1274,   987,   872,    10,    11,   879,  1223,  1224,   874,   875,
    1225,   877,   880,  1226,  1227,   881,  1228,   882,  1229,   884,
     888,  1230,    12,  1231,  1232,  1275,    13,   887,   891,  1233,
     892,  1234,   893,  1276,  1235,   894,    14,    15,  1236,  1237,
    1238,   895,  1277,   898,   896,   897,   899,   900,  1239,   902,
     903,  1327,    85,   904,   905,   906,  1011,   909,    16,    17,
     907,   908,   910,   911,  1013,  1278,   912,  1279,  1280,   913,
     914,   915,   916,    18,   917,   918,   919,   920,   921,   588,
     922,   923,   924,   925,   926,   927,    86,    87,  1281,   928,
      19,  1182,   929,   930,    88,   931,  1282,   932,   933,    89,
      90,    91,    20,    21,   934,   935,   936,   937,   938,   939,
     940,   941,   990,   991,   992,   993,   994,   995,   996,   997,
      22,   998,   999,  1000,    92,    93,    94,    95,  1001,  1002,
    1003,  1004,  1005,    23,  1006,  1007,  1008,  1009,    24,    96,
      97,    98,  1010,  1012,    25,  1014,  1015,    26,    99,   100,
     101,  1016,   102,  1018,  1017,  1019,  1020,  1021,  1022,  1029,
    1023,  1024,  1030,  1027,  1032,  1031,  1033,  1035,  1039,  1034,
    1036,  1038,  1040,  1037,  1041,  1042,  1043,  1044,  1045,  1073,
    1329,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1028,  1055,  1056,  1057,   321,  1058,   833,  1059,  1060,  1061,
    1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,  1074,  1085,  1075,  1086,  1087,  1088,  1092,  1328,  1089,
    1090,  1091,  1093,  1263,  1264,  1094,  1102,  1103,  1104,  1109,
    1110,  1111,  1112,  1113,  1114,  1115,  1116,  1117,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,  1131,  1136,  1137,  1138,
    1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,  1152,
    1153,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
    1184,  1185,  1186,  1187,  1216,  1217,  1242,  1243,  1244,  1245,
    1246,  1247,  1248,  1249,  1262,  1268,  1269,  1270,  1271,  1272,
    1285,  1299,  1330,  1301,  1302,  1331,  1332,  1303,  1304,  1305,
    1315,  1306,  1307,  1308,  1319,  1318,  1336,  1337,  1338,  1349,
     772,   785,  1267,  1334,  1322,  1333,  1325,  1324,   766,  1300,
    1348,   664,   791,   823,  1335,  1323,   755,   416,   476,  1293,
    1294,   841,   686,   340,   569,     0,     0,     0,     0,     0,
       0,   759,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   614,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   682,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   692
};

static const yytype_int16 yycheck[] =
{
     661,   662,   323,     1,     1,     8,   251,     1,   329,   330,
     331,   251,   333,   334,   212,     1,     1,     1,     1,    31,
      65,     1,     1,     1,   246,    12,    13,    14,   250,   248,
     246,   246,     1,     1,   250,   250,   246,   246,   246,     1,
     250,   250,   250,   249,     1,     1,     1,   245,   251,   246,
     251,     1,   246,   250,    40,    53,   250,     1,     1,   244,
       1,    47,    40,     6,     7,     1,     9,    10,   251,    47,
       1,   251,    15,   246,     1,    37,   251,   250,    40,    22,
      23,    24,    25,    26,    27,     1,     1,     1,   251,    32,
      33,    34,     1,   138,   251,     1,    94,    77,    77,    42,
     246,   247,    45,    46,   425,     1,   427,   428,    70,    77,
     246,    94,    55,    69,   250,   244,   437,   251,    80,   116,
      77,    77,   443,    79,    20,    94,    53,   251,   449,    72,
     116,   116,   116,   145,   251,    21,   457,   458,   116,   251,
      83,   139,   104,    86,    87,   139,   108,   186,   187,   470,
     471,   472,    38,    96,   116,    51,     1,   119,   120,   102,
     103,   116,   105,   251,   107,   251,   116,    94,   111,   112,
     251,   139,   116,   251,     1,    61,   251,   251,   175,   122,
     251,   137,   139,    79,   127,   128,   148,   130,   131,   132,
      35,    36,   135,   251,   246,   139,   193,   248,    43,   182,
     116,   116,   116,    48,    49,    50,   209,   116,   139,   246,
     116,   208,   139,   182,     1,   248,   248,   160,   161,   204,
     116,   164,   165,   166,   167,   168,   169,   170,    73,    74,
      75,    76,     1,   139,     3,   248,     5,   133,   248,   248,
     561,   182,   236,    88,    89,    90,   182,   248,   233,   247,
     247,    20,    97,    98,    99,     1,   101,    44,   245,     1,
     222,   247,   224,   225,   247,   227,   228,   229,   247,    56,
      57,    58,    18,    19,    61,    62,   219,   220,    20,    66,
      67,    68,    51,   233,    30,   247,   236,   230,   231,   116,
     247,   247,   247,     1,   235,   204,   239,   247,   241,   235,
      69,   248,    71,   247,   247,   236,   247,   246,   248,    51,
      79,   248,   246,   199,   210,   248,   247,   233,   233,   233,
     248,   236,    91,   209,   233,   248,   248,   223,   248,   650,
     226,   247,   653,    79,   655,   248,   248,    79,   247,   660,
     236,  1118,  1119,  1120,   240,   248,   248,   116,   175,   248,
     248,   247,   246,    99,   100,   248,     1,   678,     1,   248,
     106,    69,   244,   248,   110,   248,   193,   248,   137,    77,
     116,    79,   248,   248,   248,    20,   248,    20,   124,   125,
     126,   208,   248,   248,   248,   248,   248,   156,   248,   248,
     136,   133,   248,   248,   248,   248,   248,   248,   140,   141,
     248,   248,   247,   172,   248,   248,    51,   248,    51,   248,
     248,   157,   248,   149,   150,   151,   152,   153,   154,   155,
     162,   846,   847,   848,   849,   850,   851,   852,   248,   137,
     248,   248,   248,   248,    79,   248,    79,   248,    82,   248,
      84,   248,     1,   248,   248,   248,   248,     6,     7,   195,
       9,    10,   221,   248,   223,   224,    15,   248,   248,   248,
     247,   182,   248,    22,    23,    24,    25,    26,    27,   248,
     248,   116,   248,    32,    33,    34,   248,   248,   247,   244,
     248,   248,   248,    42,   248,   129,    45,    46,   133,   248,
     133,   248,   248,   248,   236,   248,    55,   140,   141,   248,
     248,   247,   146,   248,   248,   247,   246,   248,     4,   245,
     248,   248,   218,    72,   248,   248,   248,   248,   248,   162,
     248,     1,   248,   245,    83,    16,   244,    86,    87,   245,
     218,   218,    28,    29,   178,   179,   218,    96,   245,   248,
     245,   245,   245,   102,   103,    41,   105,   245,   107,   245,
     244,   246,   111,   112,   246,   248,   218,    37,   248,   248,
      40,    52,   248,   122,   248,   210,   246,   248,   127,   128,
     248,   130,   131,   132,   248,    84,   135,   248,   223,   248,
     248,   226,   248,   248,   248,    81,    82,   248,    84,   248,
      70,   236,   236,   236,    85,   240,   248,   248,   242,    11,
      80,   160,   161,  1264,   246,   164,   165,   166,   167,   168,
     169,   170,   248,   109,   248,   248,   248,   113,   248,     1,
     248,     3,   248,     5,   104,   121,   117,   118,   108,   248,
     248,   248,   123,   248,   248,   248,   116,   146,    20,   119,
     120,   245,    54,   218,   245,   245,   142,   245,   144,    61,
     146,    63,    64,   244,   244,   218,   147,   245,   218,   245,
     219,   220,   171,   245,   218,   218,   245,   163,   148,    51,
     179,   230,   231,   245,   245,   245,   245,   245,   245,   188,
     239,   245,   241,   179,   218,   218,   248,    69,   184,    71,
     248,   218,   188,   218,   245,   218,   192,    79,   218,   218,
     218,   197,   211,   218,   213,   214,   202,    11,   218,    91,
       1,   218,   218,   245,   245,   211,   246,   213,   214,   248,
     216,   143,   246,   251,   246,   234,   217,    18,    19,   250,
     218,   248,   248,   242,   116,   248,   248,   248,   234,    30,
     248,   218,   222,   248,   224,   225,   242,   227,   228,   229,
      54,   248,   243,   248,    11,   137,     1,    61,   248,    63,
      64,   173,   174,   248,   246,   177,   245,   248,   180,   181,
     248,   183,   246,   185,   156,   248,   188,   248,   190,   191,
     248,   248,   248,   248,   196,   248,   198,   248,    79,   201,
     172,   246,   248,   205,   206,   207,   248,    54,   248,    44,
     244,   218,   244,   215,    61,   218,    63,    64,    99,   100,
     218,    56,    57,    58,   218,   106,    61,    62,   246,   110,
     244,    66,    67,    68,   218,   116,   244,   246,   248,   245,
     245,   218,   246,   124,   125,   126,   246,   244,   244,   221,
     245,   223,   224,   244,   244,   136,   244,   244,    84,   244,
     246,   244,   244,   244,     0,     1,   246,   232,     4,   248,
     248,   244,   248,   248,   248,   246,   157,   246,   248,   173,
     174,    17,   246,   177,    20,   246,   180,   181,   246,   183,
     246,   185,   246,    29,   188,   246,   190,   191,   246,   246,
     246,   246,   196,    39,   198,   246,   246,   201,   246,   246,
     246,   205,   206,   207,   195,   246,   246,    53,   246,   246,
     146,   215,   245,    59,    60,   244,   173,   174,   248,   245,
     177,   245,   245,   180,   181,   245,   183,   245,   185,   245,
     244,   188,    78,   190,   191,   171,    82,   246,   244,   196,
     218,   198,   244,   179,   201,   244,    92,    93,   205,   206,
     207,   248,   188,   245,   244,   244,   244,   244,   215,   244,
     244,   146,     1,   246,   244,   244,   248,   244,   114,   115,
     246,   246,   244,   246,   245,   211,   246,   213,   214,   246,
     246,   246,   246,   129,   246,   246,   246,   246,   246,   283,
     246,   246,   246,   246,   246,   246,    35,    36,   234,   246,
     146,   250,   246,   246,    43,   246,   242,   246,   246,    48,
      49,    50,   158,   159,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     176,   246,   246,   246,    73,    74,    75,    76,   246,   246,
     246,   246,   246,   189,   246,   246,   246,   244,   194,    88,
      89,    90,   218,   244,   200,   244,   244,   203,    97,    98,
      99,   244,   101,   244,   246,   244,   246,   244,   244,   244,
     248,   245,   244,   246,   244,   246,   218,   244,   218,   248,
     244,   244,   244,   248,   244,   246,   244,   244,   244,   248,
      95,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     767,   246,   246,   246,    80,   246,   606,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     244,   246,   244,   246,   244,   244,   244,   248,   143,   246,
     246,   244,   244,   248,   248,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   245,   146,   246,   249,   143,   143,   249,   249,   249,
     244,   249,   249,   249,   246,   248,   246,   246,   246,   246,
     523,   538,  1080,  1312,  1287,  1310,  1298,  1296,   509,  1182,
    1321,   357,   554,   592,  1314,  1292,   486,   127,   183,  1149,
    1151,   619,   410,   103,   255,    -1,    -1,    -1,    -1,    -1,
      -1,   499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   420
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   253,     0,     1,     4,    17,    20,    29,    39,    53,
      59,    60,    78,    82,    92,    93,   114,   115,   129,   146,
     158,   159,   176,   189,   194,   200,   203,   254,   259,   260,
     264,   283,   289,   295,   303,   316,   336,   358,   372,   387,
     394,   398,   408,   417,   439,   445,   451,   455,   461,   521,
     541,   246,   247,   251,   251,   337,   418,   446,   251,   456,
     251,   373,   440,   359,   244,   248,   290,   317,   388,   251,
     251,   409,   251,   296,   251,   399,     1,    40,    47,   116,
     284,   285,   286,   287,   288,     1,    35,    36,    43,    48,
      49,    50,    73,    74,    75,    76,    88,    89,    90,    97,
      98,    99,   101,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   251,   251,   251,     1,    77,   452,   453,   454,
     251,     1,     6,     7,     9,    10,    15,    22,    23,    24,
      25,    26,    27,    32,    33,    34,    42,    45,    46,    55,
      72,    83,    86,    87,    96,   102,   103,   105,   107,   111,
     112,   122,   127,   128,   130,   131,   132,   135,   160,   161,
     164,   165,   166,   167,   168,   169,   170,   219,   220,   230,
     231,   239,   241,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   507,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   251,   251,   251,   249,
     261,   244,   251,   251,   251,     1,    44,    56,    57,    58,
      61,    62,    66,    67,    68,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,     1,    37,    40,    70,
      80,   104,   108,   116,   119,   120,   148,   222,   224,   225,
     227,   228,   229,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   251,     1,   235,   304,   305,   306,   307,   308,   251,
       1,   116,   395,   396,   397,   251,   246,   248,   248,   248,
     247,   285,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   247,
     523,     1,    18,    19,    30,    79,    99,   100,   106,   110,
     116,   124,   125,   126,   136,   157,   195,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     1,     3,     5,    20,    51,    69,
      71,    79,    91,   116,   137,   156,   172,   221,   223,   224,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   434,   435,   436,   437,   438,     1,    77,   139,
     447,   448,   449,   450,   248,   247,   453,     1,   116,   139,
     457,   458,   459,   460,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   508,   504,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   247,   463,     1,    20,    51,
      79,   133,   140,   141,   162,   236,   374,   375,   376,   377,
     378,   379,   380,   384,   385,   386,     1,   139,   236,   441,
     442,   443,   444,     1,    69,    77,    79,   137,   360,   364,
     365,   366,   370,   371,    31,   145,   262,   263,   246,   246,
       1,    94,   182,   291,   292,   293,   294,     1,    20,    51,
      79,   116,   133,   210,   223,   226,   236,   240,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   332,
       1,    53,    94,   139,   389,   390,   391,   392,   393,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   247,   543,
     246,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   247,   266,     1,
     116,   233,   410,   411,   412,   413,   246,   248,   247,   305,
     182,     1,   116,   175,   193,   208,   297,   298,   299,   300,
     301,   302,   248,   247,   396,     1,   116,   233,   236,   400,
     401,   402,   403,   404,   244,   244,   244,   246,   245,   245,
     256,   218,   218,   218,   218,   245,   256,   256,   256,   245,
     256,   256,   245,   245,   245,   245,   246,   246,   248,   248,
     248,   355,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   247,   339,   246,   248,   248,   248,   248,
     248,   248,   431,   248,   248,   248,   248,   248,   248,   248,
     248,   247,   420,   248,   248,   247,   448,   244,   246,   248,
     248,   247,   458,   218,   256,   245,   256,   256,   218,   245,
     245,   245,   244,   244,   218,   245,   256,   218,   245,   245,
     218,   218,   256,   245,   245,   245,   245,   245,   256,   245,
     245,   245,   218,   248,   248,   218,   256,   256,   218,   218,
     245,   218,   218,   218,   218,   218,   218,   218,   245,   256,
     256,   256,   218,   245,   246,   246,   248,   248,   381,   248,
     248,   248,   248,   248,   247,   375,   248,   248,   247,   442,
     246,   248,   248,   361,   248,   247,   365,   250,   246,   248,
     248,   247,   292,   246,   248,   248,   333,   248,   248,   329,
     248,   248,   248,   248,   247,   319,   246,   248,   248,   248,
     247,   390,   218,   218,   256,   244,   218,   244,   218,   218,
     218,   246,   245,   244,   218,   244,   245,   245,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   246,   246,
     248,   414,   247,   411,   218,   246,   251,   246,   248,   248,
     248,   248,   247,   298,   244,   246,   246,   248,   405,   248,
     247,   401,   246,   246,   246,   246,   149,   150,   151,   152,
     153,   154,   155,   255,   256,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   245,   245,   256,   248,   245,   256,   245,   256,   244,
     245,   245,   245,   256,   245,   258,   258,   246,   244,   186,
     187,   244,   218,   244,   244,   248,   244,   244,   245,   244,
     244,   256,   244,   244,   246,   244,   244,   246,   246,   244,
     244,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,    11,    54,    61,    63,    64,   173,   174,   177,
     180,   181,   183,   185,   188,   190,   191,   196,   198,   201,
     205,   206,   207,   215,   509,   510,    11,    54,    61,    63,
      64,   173,   174,   177,   180,   181,   183,   185,   188,   190,
     191,   196,   198,   201,   205,   206,   207,   215,   505,   506,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   244,
     218,   248,   244,   245,   244,   244,   244,   246,   244,   244,
     246,   244,   244,   248,   245,   368,   369,   246,   263,   244,
     244,   246,   244,   218,   248,   244,   244,   248,   244,   218,
     244,   244,   246,   244,   244,   244,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   244,   248,   246,   246,     1,   116,   204,   233,
     309,   310,   311,   312,   313,   244,   244,   244,   244,   246,
     246,   244,   248,   244,   246,   255,   255,   255,   255,   255,
     255,   255,   246,   246,   246,    65,   138,   356,   357,   246,
     246,   246,   246,   246,   246,   246,   246,   246,    12,    13,
      14,   257,   258,   246,   246,   246,   246,   246,   246,   246,
     246,   246,     8,   209,   432,   433,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   250,
     246,   250,   246,   246,    16,    52,    85,   117,   118,   123,
     147,   217,   243,   382,   383,   246,   246,   246,   246,   246,
     246,   246,   246,   246,    21,    38,    61,   199,   209,   362,
     363,   232,   250,   367,   246,   246,   246,   246,     4,    28,
      29,    41,    81,    82,    84,   109,   113,   121,   142,   144,
     146,   163,   179,   184,   188,   192,   197,   202,   211,   213,
     214,   216,   234,   242,   334,   335,   246,   246,    11,    54,
      61,    63,    64,   173,   174,   177,   180,   181,   183,   185,
     188,   190,   191,   196,   198,   201,   205,   206,   207,   215,
     330,   331,   246,   246,   246,   246,   246,   246,   246,   246,
      84,   146,   171,   179,   188,   211,   213,   214,   234,   242,
     415,   416,   246,   248,   248,   314,   247,   310,   246,   246,
     246,   246,   246,    84,   146,   171,   179,   188,   211,   213,
     214,   234,   242,   406,   407,   246,   246,   250,   257,   257,
     257,   246,   250,   510,   506,   246,   250,   246,   250,   245,
     369,   246,   249,   249,   249,   249,   249,   249,   249,   246,
     250,   246,   250,   246,   250,   244,   212,   258,   248,   246,
     246,   250,   357,   433,   383,   363,   143,   146,   143,    95,
     146,   143,   143,   335,   331,   416,   246,   246,   246,    82,
      84,   129,   146,   178,   179,   236,   242,   315,   407,   246
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   252,   253,   253,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   255,
     255,   256,   256,   256,   256,   256,   256,   256,   256,   257,
     257,   258,   258,   258,   258,   259,   260,   261,   261,   262,
     262,   263,   263,   264,   265,   265,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   284,   285,   285,   285,   285,   286,   287,   288,   290,
     289,   291,   291,   292,   292,   292,   293,   294,   296,   295,
     297,   297,   298,   298,   298,   298,   298,   299,   300,   301,
     302,   303,   304,   304,   305,   305,   305,   306,   308,   307,
     309,   309,   310,   310,   310,   310,   311,   312,   312,   314,
     313,   315,   315,   315,   315,   315,   315,   315,   315,   317,
     316,   318,   318,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   329,   328,   330,   330,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   333,   332,
     334,   334,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   337,   336,   338,   338,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   355,   354,   356,   356,
     357,   357,   359,   358,   361,   360,   362,   362,   363,   363,
     363,   363,   363,   364,   364,   365,   365,   365,   365,   365,
     367,   366,   368,   368,   369,   369,   370,   371,   373,   372,
     374,   374,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   376,   377,   378,   379,   381,   380,   382,   382,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   384,   385,
     386,   388,   387,   389,   389,   390,   390,   390,   390,   391,
     392,   393,   394,   395,   395,   396,   396,   397,   399,   398,
     400,   400,   401,   401,   401,   401,   402,   403,   405,   404,
     406,   406,   407,   407,   407,   407,   407,   407,   407,   407,
     407,   407,   409,   408,   410,   410,   411,   411,   411,   412,
     414,   413,   415,   415,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   418,   417,   419,   419,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   429,   431,   430,   432,   432,   433,   433,
     434,   435,   436,   437,   438,   440,   439,   441,   441,   442,
     442,   442,   443,   444,   446,   445,   447,   447,   448,   448,
     448,   449,   450,   451,   452,   452,   453,   453,   454,   456,
     455,   457,   457,   458,   458,   458,   459,   460,   461,   462,
     462,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   504,   503,   505,   505,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   508,   507,
     509,   509,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   522,   523,   523,   523,
     523,   523,   523,   523,   523,   523,   523,   523,   523,   523,
     523,   523,   523,   523,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   542,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552
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
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     2,     4,     4,     4,     0,
       6,     2,     1,     1,     1,     2,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     2,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     4,     0,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     3,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     0,     6,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       0,     5,     3,     1,     1,     3,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     2,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       4,     4,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4
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
#line 414 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3363 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 415 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3369 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 416 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3375 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 417 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3381 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 418 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3387 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 419 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3393 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 420 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3399 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 421 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3405 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 422 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3411 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 425 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3417 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 426 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3423 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 427 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3429 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 428 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3435 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 429 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3441 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 437 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3450 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 447 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3459 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 453 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3467 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 460 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3476 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 464 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3485 "conf_parser.c"
    break;

  case 73: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 496 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3497 "conf_parser.c"
    break;

  case 74: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 505 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = io_strdup(yylval.string);
  }
}
#line 3509 "conf_parser.c"
    break;

  case 75: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 514 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = io_strdup(yylval.string);
  }
}
#line 3521 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 523 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = io_strdup(yylval.string);
  }
}
#line 3533 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 532 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = io_strdup(yylval.string);
  }
}
#line 3545 "conf_parser.c"
    break;

  case 78: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 541 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = io_strdup(yylval.string);
  }
}
#line 3557 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 550 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = io_strdup(yylval.string);
  }
}
#line 3569 "conf_parser.c"
    break;

  case 80: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 559 "conf_parser.y"
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
#line 3587 "conf_parser.c"
    break;

  case 81: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 574 "conf_parser.y"
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
#line 3605 "conf_parser.c"
    break;

  case 82: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 589 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3618 "conf_parser.c"
    break;

  case 83: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 599 "conf_parser.y"
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
#line 3635 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 613 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3647 "conf_parser.c"
    break;

  case 85: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 622 "conf_parser.y"
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
#line 3673 "conf_parser.c"
    break;

  case 86: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 645 "conf_parser.y"
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
#line 3699 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 668 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 80)
  {
    conf_error_report("max_topic_length too low, setting to 80");
    ConfigServerInfo.max_topic_length = 80;
  }
  else if ((yyvsp[-1].number) > TOPICLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
    conf_error_report(buf);

    ConfigServerInfo.max_topic_length = TOPICLEN;
  }
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3725 "conf_parser.c"
    break;

  case 88: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 691 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3734 "conf_parser.c"
    break;

  case 96: /* admin_name: NAME '=' QSTRING ';'  */
#line 709 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3746 "conf_parser.c"
    break;

  case 97: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 718 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3758 "conf_parser.c"
    break;

  case 98: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 727 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3770 "conf_parser.c"
    break;

  case 99: /* $@1: %empty  */
#line 740 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3779 "conf_parser.c"
    break;

  case 100: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 744 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3796 "conf_parser.c"
    break;

  case 106: /* motd_mask: MASK '=' QSTRING ';'  */
#line 761 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3805 "conf_parser.c"
    break;

  case 107: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3814 "conf_parser.c"
    break;

  case 108: /* $@2: %empty  */
#line 777 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3823 "conf_parser.c"
    break;

  case 109: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 781 "conf_parser.y"
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
#line 3841 "conf_parser.c"
    break;

  case 117: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 799 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3850 "conf_parser.c"
    break;

  case 118: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 805 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3859 "conf_parser.c"
    break;

  case 119: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 811 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3868 "conf_parser.c"
    break;

  case 120: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 817 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh =
    {
      .nuhmask = yylval.string,
      .nickptr = NULL,
      .userptr = block_state.nick.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.nick.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    split_nuh(&nuh);
  }
}
#line 3890 "conf_parser.c"
    break;

  case 127: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 846 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3899 "conf_parser.c"
    break;

  case 128: /* $@3: %empty  */
#line 852 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3908 "conf_parser.c"
    break;

  case 129: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 856 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3921 "conf_parser.c"
    break;

  case 136: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 872 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3932 "conf_parser.c"
    break;

  case 137: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 880 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3940 "conf_parser.c"
    break;

  case 138: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 883 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3948 "conf_parser.c"
    break;

  case 139: /* $@4: %empty  */
#line 888 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3957 "conf_parser.c"
    break;

  case 141: /* logging_file_type_item: USER  */
#line 894 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3966 "conf_parser.c"
    break;

  case 142: /* logging_file_type_item: OPERATOR  */
#line 898 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3975 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: XLINE  */
#line 902 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3984 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: RESV  */
#line 906 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3993 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: T_DLINE  */
#line 910 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4002 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: KLINE  */
#line 914 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4011 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: KILL  */
#line 918 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4020 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: T_DEBUG  */
#line 922 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4029 "conf_parser.c"
    break;

  case 149: /* $@5: %empty  */
#line 932 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 4041 "conf_parser.c"
    break;

  case 150: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 939 "conf_parser.y"
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

    if (EmptyString(s))
      continue;

    struct split_nuh_item nuh =
    {
      .nuhmask = s,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    split_nuh(&nuh);

    struct MaskItem *conf = conf_make(CONF_OPER);
    conf->addr = io_calloc(sizeof(*conf->addr));
    conf->name = io_strdup(block_state.name.buf);
    conf->user = io_strdup(block_state.user.buf);
    conf->host = io_strdup(block_state.host.buf);

    if (block_state.cert.buf[0])
      conf->certfp = io_strdup(block_state.cert.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = io_strdup(block_state.rpass.buf);

    if (block_state.whois.buf[0])
      conf->whois = io_strdup(block_state.whois.buf);

    conf->flags = block_state.flags.value;
    conf->modes = block_state.modes.value;
    conf->port  = block_state.port.value;
    conf->htype = parse_netmask(conf->host, conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);
  }
}
#line 4101 "conf_parser.c"
    break;

  case 164: /* oper_name: NAME '=' QSTRING ';'  */
#line 1009 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4110 "conf_parser.c"
    break;

  case 165: /* oper_user: USER '=' QSTRING ';'  */
#line 1015 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4119 "conf_parser.c"
    break;

  case 166: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1021 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4128 "conf_parser.c"
    break;

  case 167: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1027 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4137 "conf_parser.c"
    break;

  case 168: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1033 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 4151 "conf_parser.c"
    break;

  case 169: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1044 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4160 "conf_parser.c"
    break;

  case 170: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1050 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 4174 "conf_parser.c"
    break;

  case 171: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4183 "conf_parser.c"
    break;

  case 172: /* $@6: %empty  */
#line 1067 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 4192 "conf_parser.c"
    break;

  case 176: /* oper_umodes_item: BOT  */
#line 1074 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOT;
}
#line 4201 "conf_parser.c"
    break;

  case 177: /* oper_umodes_item: T_CCONN  */
#line 1078 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 4210 "conf_parser.c"
    break;

  case 178: /* oper_umodes_item: T_DEAF  */
#line 1082 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 4219 "conf_parser.c"
    break;

  case 179: /* oper_umodes_item: T_FLOOD  */
#line 1086 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FLOOD;
}
#line 4228 "conf_parser.c"
    break;

  case 180: /* oper_umodes_item: HIDDEN  */
#line 1090 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 4237 "conf_parser.c"
    break;

  case 181: /* oper_umodes_item: HIDE_CHANS  */
#line 1094 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 4246 "conf_parser.c"
    break;

  case 182: /* oper_umodes_item: HIDE_IDLE  */
#line 1098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 4255 "conf_parser.c"
    break;

  case 183: /* oper_umodes_item: T_SKILL  */
#line 1102 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 4264 "conf_parser.c"
    break;

  case 184: /* oper_umodes_item: T_NCHANGE  */
#line 1106 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 4273 "conf_parser.c"
    break;

  case 185: /* oper_umodes_item: T_REJ  */
#line 1110 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 4282 "conf_parser.c"
    break;

  case 186: /* oper_umodes_item: T_SPY  */
#line 1114 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4291 "conf_parser.c"
    break;

  case 187: /* oper_umodes_item: T_EXTERNAL  */
#line 1118 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4300 "conf_parser.c"
    break;

  case 188: /* oper_umodes_item: T_SERVNOTICE  */
#line 1122 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4309 "conf_parser.c"
    break;

  case 189: /* oper_umodes_item: T_INVISIBLE  */
#line 1126 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4318 "conf_parser.c"
    break;

  case 190: /* oper_umodes_item: T_WALLOP  */
#line 1130 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4327 "conf_parser.c"
    break;

  case 191: /* oper_umodes_item: T_SOFTCALLERID  */
#line 1134 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4336 "conf_parser.c"
    break;

  case 192: /* oper_umodes_item: T_CALLERID  */
#line 1138 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4345 "conf_parser.c"
    break;

  case 193: /* oper_umodes_item: T_LOCOPS  */
#line 1142 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4354 "conf_parser.c"
    break;

  case 194: /* oper_umodes_item: T_NONONREG  */
#line 1146 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4363 "conf_parser.c"
    break;

  case 195: /* oper_umodes_item: T_FARCONNECT  */
#line 1150 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4372 "conf_parser.c"
    break;

  case 196: /* oper_umodes_item: EXPIRATION  */
#line 1154 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 4381 "conf_parser.c"
    break;

  case 197: /* oper_umodes_item: T_SECUREONLY  */
#line 1158 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SECUREONLY;
}
#line 4390 "conf_parser.c"
    break;

  case 198: /* $@7: %empty  */
#line 1164 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4399 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: KILL ':' REMOTE  */
#line 1171 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4408 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: KILL  */
#line 1175 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4417 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1179 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4426 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: CONNECT  */
#line 1183 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4435 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1187 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4444 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: SQUIT  */
#line 1191 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4453 "conf_parser.c"
    break;

  case 208: /* oper_flags_item: KLINE  */
#line 1195 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4462 "conf_parser.c"
    break;

  case 209: /* oper_flags_item: UNKLINE  */
#line 1199 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4471 "conf_parser.c"
    break;

  case 210: /* oper_flags_item: T_DLINE  */
#line 1203 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4480 "conf_parser.c"
    break;

  case 211: /* oper_flags_item: T_UNDLINE  */
#line 1207 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4489 "conf_parser.c"
    break;

  case 212: /* oper_flags_item: XLINE  */
#line 1211 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4498 "conf_parser.c"
    break;

  case 213: /* oper_flags_item: T_UNXLINE  */
#line 1215 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4507 "conf_parser.c"
    break;

  case 214: /* oper_flags_item: DIE  */
#line 1219 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4516 "conf_parser.c"
    break;

  case 215: /* oper_flags_item: T_RESTART  */
#line 1223 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4525 "conf_parser.c"
    break;

  case 216: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1227 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4534 "conf_parser.c"
    break;

  case 217: /* oper_flags_item: REHASH  */
#line 1231 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4543 "conf_parser.c"
    break;

  case 218: /* oper_flags_item: ADMIN  */
#line 1235 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4552 "conf_parser.c"
    break;

  case 219: /* oper_flags_item: T_GLOBOPS  */
#line 1239 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4561 "conf_parser.c"
    break;

  case 220: /* oper_flags_item: T_WALLOPS  */
#line 1243 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4570 "conf_parser.c"
    break;

  case 221: /* oper_flags_item: T_LOCOPS  */
#line 1247 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4579 "conf_parser.c"
    break;

  case 222: /* oper_flags_item: REMOTEBAN  */
#line 1251 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4588 "conf_parser.c"
    break;

  case 223: /* oper_flags_item: T_SET  */
#line 1255 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4597 "conf_parser.c"
    break;

  case 224: /* oper_flags_item: MODULE  */
#line 1259 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4606 "conf_parser.c"
    break;

  case 225: /* oper_flags_item: T_OPME  */
#line 1263 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4615 "conf_parser.c"
    break;

  case 226: /* oper_flags_item: NICK ':' RESV  */
#line 1267 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4624 "conf_parser.c"
    break;

  case 227: /* oper_flags_item: JOIN ':' RESV  */
#line 1271 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4633 "conf_parser.c"
    break;

  case 228: /* oper_flags_item: RESV  */
#line 1275 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4642 "conf_parser.c"
    break;

  case 229: /* oper_flags_item: T_UNRESV  */
#line 1279 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4651 "conf_parser.c"
    break;

  case 230: /* oper_flags_item: CLOSE  */
#line 1283 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4660 "conf_parser.c"
    break;

  case 231: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1287 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4669 "conf_parser.c"
    break;

  case 232: /* $@8: %empty  */
#line 1297 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4685 "conf_parser.c"
    break;

  case 233: /* class_entry: CLASS $@8 '{' class_items '}' ';'  */
#line 1308 "conf_parser.y"
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
#line 4733 "conf_parser.c"
    break;

  case 252: /* class_name: NAME '=' QSTRING ';'  */
#line 1371 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4742 "conf_parser.c"
    break;

  case 253: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1377 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4751 "conf_parser.c"
    break;

  case 254: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1383 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4760 "conf_parser.c"
    break;

  case 255: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1389 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4769 "conf_parser.c"
    break;

  case 256: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1395 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4778 "conf_parser.c"
    break;

  case 257: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1401 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4787 "conf_parser.c"
    break;

  case 258: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1407 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4796 "conf_parser.c"
    break;

  case 259: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1413 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4805 "conf_parser.c"
    break;

  case 260: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1419 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4815 "conf_parser.c"
    break;

  case 261: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1426 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4824 "conf_parser.c"
    break;

  case 262: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1432 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4833 "conf_parser.c"
    break;

  case 263: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1438 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4842 "conf_parser.c"
    break;

  case 264: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1444 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4854 "conf_parser.c"
    break;

  case 265: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1453 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4866 "conf_parser.c"
    break;

  case 266: /* $@9: %empty  */
#line 1462 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4875 "conf_parser.c"
    break;

  case 270: /* class_flags_item: RANDOM_IDLE  */
#line 1469 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4884 "conf_parser.c"
    break;

  case 271: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1473 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4893 "conf_parser.c"
    break;

  case 272: /* $@10: %empty  */
#line 1483 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4902 "conf_parser.c"
    break;

  case 274: /* $@11: %empty  */
#line 1489 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4910 "conf_parser.c"
    break;

  case 278: /* listen_flags_item: T_TLS  */
#line 1495 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4919 "conf_parser.c"
    break;

  case 279: /* listen_flags_item: HIDDEN  */
#line 1499 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4928 "conf_parser.c"
    break;

  case 280: /* listen_flags_item: T_SERVER  */
#line 1503 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4937 "conf_parser.c"
    break;

  case 281: /* listen_flags_item: CLIENT  */
#line 1507 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4946 "conf_parser.c"
    break;

  case 282: /* listen_flags_item: DEFER  */
#line 1511 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4955 "conf_parser.c"
    break;

  case 290: /* $@12: %empty  */
#line 1519 "conf_parser.y"
                                 { reset_block_state(); }
#line 4961 "conf_parser.c"
    break;

  case 294: /* port_item: NUMBER  */
#line 1524 "conf_parser.y"
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
#line 4979 "conf_parser.c"
    break;

  case 295: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1537 "conf_parser.y"
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
#line 4999 "conf_parser.c"
    break;

  case 296: /* listen_address: IP '=' QSTRING ';'  */
#line 1554 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5008 "conf_parser.c"
    break;

  case 297: /* listen_host: HOST '=' QSTRING ';'  */
#line 1560 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5017 "conf_parser.c"
    break;

  case 298: /* $@13: %empty  */
#line 1570 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5026 "conf_parser.c"
    break;

  case 299: /* auth_entry: IRCD_AUTH $@13 '{' auth_items '}' ';'  */
#line 1574 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
  {
    char *s = node->data;

    if (EmptyString(s))
      continue;

    struct split_nuh_item nuh =
    {
      .nuhmask = s,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    split_nuh(&nuh);

    struct MaskItem *conf = conf_make(CONF_CLIENT);
    conf->user = io_strdup(block_state.user.buf);
    conf->host = io_strdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = io_strdup(block_state.rpass.buf);
    if (block_state.name.buf[0])
      conf->name = io_strdup(block_state.name.buf);

    conf->flags = block_state.flags.value;
    conf->port = block_state.port.value;

    conf_add_class_to_conf(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
#line 5073 "conf_parser.c"
    break;

  case 311: /* auth_user: USER '=' QSTRING ';'  */
#line 1629 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5082 "conf_parser.c"
    break;

  case 312: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1635 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5091 "conf_parser.c"
    break;

  case 313: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1641 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5100 "conf_parser.c"
    break;

  case 314: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1647 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5114 "conf_parser.c"
    break;

  case 315: /* $@14: %empty  */
#line 1658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 5123 "conf_parser.c"
    break;

  case 319: /* auth_flags_item: EXCEED_LIMIT  */
#line 1665 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 5132 "conf_parser.c"
    break;

  case 320: /* auth_flags_item: KLINE_EXEMPT  */
#line 1669 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 5141 "conf_parser.c"
    break;

  case 321: /* auth_flags_item: XLINE_EXEMPT  */
#line 1673 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 5150 "conf_parser.c"
    break;

  case 322: /* auth_flags_item: NEED_IDENT  */
#line 1677 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 5159 "conf_parser.c"
    break;

  case 323: /* auth_flags_item: CAN_FLOOD  */
#line 1681 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 5168 "conf_parser.c"
    break;

  case 324: /* auth_flags_item: NO_TILDE  */
#line 1685 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 5177 "conf_parser.c"
    break;

  case 325: /* auth_flags_item: RESV_EXEMPT  */
#line 1689 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 5186 "conf_parser.c"
    break;

  case 326: /* auth_flags_item: T_WEBIRC  */
#line 1693 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 5195 "conf_parser.c"
    break;

  case 327: /* auth_flags_item: NEED_PASSWORD  */
#line 1697 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 5204 "conf_parser.c"
    break;

  case 328: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1703 "conf_parser.y"
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
#line 5221 "conf_parser.c"
    break;

  case 329: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1717 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 5233 "conf_parser.c"
    break;

  case 330: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1726 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 5245 "conf_parser.c"
    break;

  case 331: /* $@15: %empty  */
#line 1739 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5257 "conf_parser.c"
    break;

  case 332: /* resv_entry: RESV $@15 '{' resv_items '}' ';'  */
#line 1746 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5268 "conf_parser.c"
    break;

  case 339: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1757 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5277 "conf_parser.c"
    break;

  case 340: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1763 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5286 "conf_parser.c"
    break;

  case 341: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1769 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5295 "conf_parser.c"
    break;

  case 347: /* service_name: NAME '=' QSTRING ';'  */
#line 1784 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5310 "conf_parser.c"
    break;

  case 348: /* $@16: %empty  */
#line 1800 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5326 "conf_parser.c"
    break;

  case 349: /* shared_entry: T_SHARED $@16 '{' shared_items '}' ';'  */
#line 1811 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5341 "conf_parser.c"
    break;

  case 356: /* shared_name: NAME '=' QSTRING ';'  */
#line 1826 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5350 "conf_parser.c"
    break;

  case 357: /* shared_user: USER '=' QSTRING ';'  */
#line 1832 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh =
    {
      .nuhmask = yylval.string,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    split_nuh(&nuh);
  }
}
#line 5372 "conf_parser.c"
    break;

  case 358: /* $@17: %empty  */
#line 1851 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5381 "conf_parser.c"
    break;

  case 362: /* shared_type_item: KLINE  */
#line 1858 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5390 "conf_parser.c"
    break;

  case 363: /* shared_type_item: UNKLINE  */
#line 1862 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5399 "conf_parser.c"
    break;

  case 364: /* shared_type_item: T_DLINE  */
#line 1866 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5408 "conf_parser.c"
    break;

  case 365: /* shared_type_item: T_UNDLINE  */
#line 1870 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5417 "conf_parser.c"
    break;

  case 366: /* shared_type_item: XLINE  */
#line 1874 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5426 "conf_parser.c"
    break;

  case 367: /* shared_type_item: T_UNXLINE  */
#line 1878 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5435 "conf_parser.c"
    break;

  case 368: /* shared_type_item: RESV  */
#line 1882 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5444 "conf_parser.c"
    break;

  case 369: /* shared_type_item: T_UNRESV  */
#line 1886 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5453 "conf_parser.c"
    break;

  case 370: /* shared_type_item: T_LOCOPS  */
#line 1890 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5462 "conf_parser.c"
    break;

  case 371: /* shared_type_item: T_ALL  */
#line 1894 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5471 "conf_parser.c"
    break;

  case 372: /* $@18: %empty  */
#line 1904 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5485 "conf_parser.c"
    break;

  case 373: /* cluster_entry: T_CLUSTER $@18 '{' cluster_items '}' ';'  */
#line 1913 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5498 "conf_parser.c"
    break;

  case 379: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1926 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5507 "conf_parser.c"
    break;

  case 380: /* $@19: %empty  */
#line 1932 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5516 "conf_parser.c"
    break;

  case 384: /* cluster_type_item: KLINE  */
#line 1939 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5525 "conf_parser.c"
    break;

  case 385: /* cluster_type_item: UNKLINE  */
#line 1943 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5534 "conf_parser.c"
    break;

  case 386: /* cluster_type_item: T_DLINE  */
#line 1947 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5543 "conf_parser.c"
    break;

  case 387: /* cluster_type_item: T_UNDLINE  */
#line 1951 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5552 "conf_parser.c"
    break;

  case 388: /* cluster_type_item: XLINE  */
#line 1955 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5561 "conf_parser.c"
    break;

  case 389: /* cluster_type_item: T_UNXLINE  */
#line 1959 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5570 "conf_parser.c"
    break;

  case 390: /* cluster_type_item: RESV  */
#line 1963 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5579 "conf_parser.c"
    break;

  case 391: /* cluster_type_item: T_UNRESV  */
#line 1967 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5588 "conf_parser.c"
    break;

  case 392: /* cluster_type_item: T_LOCOPS  */
#line 1971 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5597 "conf_parser.c"
    break;

  case 393: /* cluster_type_item: T_ALL  */
#line 1975 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5606 "conf_parser.c"
    break;

  case 394: /* $@20: %empty  */
#line 1985 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5621 "conf_parser.c"
    break;

  case 395: /* connect_entry: CONNECT $@20 '{' connect_items '}' ';'  */
#line 1995 "conf_parser.y"
{
  struct addrinfo hints, *res;

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

  struct MaskItem *conf = conf_make(CONF_SERVER);
  conf->addr = io_calloc(sizeof(*conf->addr));
  conf->port = block_state.port.value;
  conf->timeout = block_state.timeout.value;
  conf->flags = block_state.flags.value;
  conf->aftype = block_state.aftype.value;
  conf->host = io_strdup(block_state.host.buf);
  conf->name = io_strdup(block_state.name.buf);
  conf->passwd = io_strdup(block_state.rpass.buf);
  conf->spasswd = io_strdup(block_state.spass.buf);

  if (block_state.cert.buf[0])
    conf->certfp = io_strdup(block_state.cert.buf);

  if (block_state.ciph.buf[0])
    conf->cipher_list = io_strdup(block_state.ciph.buf);

  list_move_list(&block_state.leaf.list, &conf->leaf_list);
  list_move_list(&block_state.hub.list, &conf->hub_list);

  if (block_state.bind.buf[0])
  {
    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(block_state.bind.buf, NULL, &hints, &res))
      log_write(LOG_TYPE_IRCD, "Invalid netmask for server bind(%s)", block_state.bind.buf);
    else
    {
      assert(res);

      conf->bind = io_calloc(sizeof(*conf->bind));

      memcpy(conf->bind, res->ai_addr, res->ai_addrlen);
      conf->bind->ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  conf_dns_lookup(conf);
}
#line 5692 "conf_parser.c"
    break;

  case 414: /* connect_name: NAME '=' QSTRING ';'  */
#line 2081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5701 "conf_parser.c"
    break;

  case 415: /* connect_host: HOST '=' QSTRING ';'  */
#line 2087 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5710 "conf_parser.c"
    break;

  case 416: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 2093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5719 "conf_parser.c"
    break;

  case 417: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 2099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5728 "conf_parser.c"
    break;

  case 418: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2105 "conf_parser.y"
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
#line 5744 "conf_parser.c"
    break;

  case 419: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2118 "conf_parser.y"
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
#line 5760 "conf_parser.c"
    break;

  case 420: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2131 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5769 "conf_parser.c"
    break;

  case 421: /* connect_port: PORT '=' NUMBER ';'  */
#line 2137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5778 "conf_parser.c"
    break;

  case 422: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2143 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5787 "conf_parser.c"
    break;

  case 423: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2147 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5796 "conf_parser.c"
    break;

  case 424: /* $@21: %empty  */
#line 2153 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5804 "conf_parser.c"
    break;

  case 428: /* connect_flags_item: AUTOCONN  */
#line 2159 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5813 "conf_parser.c"
    break;

  case 429: /* connect_flags_item: T_TLS  */
#line 2163 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5822 "conf_parser.c"
    break;

  case 430: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2169 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5836 "conf_parser.c"
    break;

  case 431: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2180 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5845 "conf_parser.c"
    break;

  case 432: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2186 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5854 "conf_parser.c"
    break;

  case 433: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2192 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5863 "conf_parser.c"
    break;

  case 434: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2198 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5877 "conf_parser.c"
    break;

  case 435: /* $@22: %empty  */
#line 2213 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5886 "conf_parser.c"
    break;

  case 436: /* kill_entry: KILL $@22 '{' kill_items '}' ';'  */
#line 2217 "conf_parser.y"
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
#line 5909 "conf_parser.c"
    break;

  case 442: /* kill_user: USER '=' QSTRING ';'  */
#line 2240 "conf_parser.y"
{

  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh =
    {
      .nuhmask = yylval.string,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    split_nuh(&nuh);
  }
}
#line 5932 "conf_parser.c"
    break;

  case 443: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2260 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5941 "conf_parser.c"
    break;

  case 444: /* $@23: %empty  */
#line 2270 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5950 "conf_parser.c"
    break;

  case 445: /* deny_entry: DENY $@23 '{' deny_items '}' ';'  */
#line 2274 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  if (parse_netmask(block_state.addr.buf, NULL, NULL) != HM_HOST)
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
#line 5974 "conf_parser.c"
    break;

  case 451: /* deny_ip: IP '=' QSTRING ';'  */
#line 2298 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5983 "conf_parser.c"
    break;

  case 452: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2304 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5992 "conf_parser.c"
    break;

  case 458: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2319 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (*yylval.string && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      struct MaskItem *conf = conf_make(CONF_EXEMPT);
      conf->host = io_strdup(yylval.string);

      add_conf_by_address(CONF_EXEMPT, conf);
    }
  }
}
#line 6009 "conf_parser.c"
    break;

  case 459: /* $@24: %empty  */
#line 2336 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 6018 "conf_parser.c"
    break;

  case 460: /* gecos_entry: GECOS $@24 '{' gecos_items '}' ';'  */
#line 2340 "conf_parser.y"
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
#line 6038 "conf_parser.c"
    break;

  case 466: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2360 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 6047 "conf_parser.c"
    break;

  case 467: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2366 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 6056 "conf_parser.c"
    break;

  case 523: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2433 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 6064 "conf_parser.c"
    break;

  case 524: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2438 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 6072 "conf_parser.c"
    break;

  case 525: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2443 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 6080 "conf_parser.c"
    break;

  case 526: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2448 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 6088 "conf_parser.c"
    break;

  case 527: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2453 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 6096 "conf_parser.c"
    break;

  case 528: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2458 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 6104 "conf_parser.c"
    break;

  case 529: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2463 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 6112 "conf_parser.c"
    break;

  case 530: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2468 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6120 "conf_parser.c"
    break;

  case 531: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2473 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6128 "conf_parser.c"
    break;

  case 532: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2478 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6136 "conf_parser.c"
    break;

  case 533: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2483 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 6144 "conf_parser.c"
    break;

  case 534: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2488 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 6152 "conf_parser.c"
    break;

  case 535: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2493 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6160 "conf_parser.c"
    break;

  case 536: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2498 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6168 "conf_parser.c"
    break;

  case 537: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2503 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6176 "conf_parser.c"
    break;

  case 538: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2508 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6184 "conf_parser.c"
    break;

  case 539: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2513 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6192 "conf_parser.c"
    break;

  case 540: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2518 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6200 "conf_parser.c"
    break;

  case 541: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2523 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6208 "conf_parser.c"
    break;

  case 542: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2528 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6216 "conf_parser.c"
    break;

  case 543: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2533 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6224 "conf_parser.c"
    break;

  case 544: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2538 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 6232 "conf_parser.c"
    break;

  case 545: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2543 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 6240 "conf_parser.c"
    break;

  case 546: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2548 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 6248 "conf_parser.c"
    break;

  case 547: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2553 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6256 "conf_parser.c"
    break;

  case 548: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2558 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 6264 "conf_parser.c"
    break;

  case 549: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2563 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 6272 "conf_parser.c"
    break;

  case 550: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2568 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6280 "conf_parser.c"
    break;

  case 551: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2573 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6288 "conf_parser.c"
    break;

  case 552: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2578 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6296 "conf_parser.c"
    break;

  case 553: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2583 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6304 "conf_parser.c"
    break;

  case 554: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2588 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6312 "conf_parser.c"
    break;

  case 555: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2593 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6320 "conf_parser.c"
    break;

  case 556: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2598 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6328 "conf_parser.c"
    break;

  case 557: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2603 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6336 "conf_parser.c"
    break;

  case 558: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2608 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6344 "conf_parser.c"
    break;

  case 559: /* general_disable_auth: DISABLE_AUTH '=' TBOOL ';'  */
#line 2613 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6352 "conf_parser.c"
    break;

  case 560: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2618 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6360 "conf_parser.c"
    break;

  case 561: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2623 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6368 "conf_parser.c"
    break;

  case 562: /* $@25: %empty  */
#line 2628 "conf_parser.y"
{
  ConfigGeneral.oper_umodes = 0;
}
#line 6376 "conf_parser.c"
    break;

  case 566: /* umode_oitem: BOT  */
#line 2634 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_BOT;
}
#line 6384 "conf_parser.c"
    break;

  case 567: /* umode_oitem: T_CCONN  */
#line 2637 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6392 "conf_parser.c"
    break;

  case 568: /* umode_oitem: T_DEAF  */
#line 2640 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6400 "conf_parser.c"
    break;

  case 569: /* umode_oitem: T_FLOOD  */
#line 2643 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FLOOD;
}
#line 6408 "conf_parser.c"
    break;

  case 570: /* umode_oitem: HIDDEN  */
#line 2646 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6416 "conf_parser.c"
    break;

  case 571: /* umode_oitem: HIDE_CHANS  */
#line 2649 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6424 "conf_parser.c"
    break;

  case 572: /* umode_oitem: HIDE_IDLE  */
#line 2652 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6432 "conf_parser.c"
    break;

  case 573: /* umode_oitem: T_SKILL  */
#line 2655 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6440 "conf_parser.c"
    break;

  case 574: /* umode_oitem: T_NCHANGE  */
#line 2658 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6448 "conf_parser.c"
    break;

  case 575: /* umode_oitem: T_REJ  */
#line 2661 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6456 "conf_parser.c"
    break;

  case 576: /* umode_oitem: T_SPY  */
#line 2664 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6464 "conf_parser.c"
    break;

  case 577: /* umode_oitem: T_EXTERNAL  */
#line 2667 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6472 "conf_parser.c"
    break;

  case 578: /* umode_oitem: T_SERVNOTICE  */
#line 2670 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6480 "conf_parser.c"
    break;

  case 579: /* umode_oitem: T_INVISIBLE  */
#line 2673 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6488 "conf_parser.c"
    break;

  case 580: /* umode_oitem: T_WALLOP  */
#line 2676 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6496 "conf_parser.c"
    break;

  case 581: /* umode_oitem: T_SOFTCALLERID  */
#line 2679 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6504 "conf_parser.c"
    break;

  case 582: /* umode_oitem: T_CALLERID  */
#line 2682 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6512 "conf_parser.c"
    break;

  case 583: /* umode_oitem: T_LOCOPS  */
#line 2685 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6520 "conf_parser.c"
    break;

  case 584: /* umode_oitem: T_NONONREG  */
#line 2688 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6528 "conf_parser.c"
    break;

  case 585: /* umode_oitem: T_FARCONNECT  */
#line 2691 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6536 "conf_parser.c"
    break;

  case 586: /* umode_oitem: EXPIRATION  */
#line 2694 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6544 "conf_parser.c"
    break;

  case 587: /* umode_oitem: T_SECUREONLY  */
#line 2697 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SECUREONLY;
}
#line 6552 "conf_parser.c"
    break;

  case 588: /* $@26: %empty  */
#line 2702 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6560 "conf_parser.c"
    break;

  case 592: /* umode_item: BOT  */
#line 2708 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_BOT;
}
#line 6568 "conf_parser.c"
    break;

  case 593: /* umode_item: T_CCONN  */
#line 2711 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6576 "conf_parser.c"
    break;

  case 594: /* umode_item: T_DEAF  */
#line 2714 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6584 "conf_parser.c"
    break;

  case 595: /* umode_item: T_FLOOD  */
#line 2717 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FLOOD;
}
#line 6592 "conf_parser.c"
    break;

  case 596: /* umode_item: T_SKILL  */
#line 2720 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6600 "conf_parser.c"
    break;

  case 597: /* umode_item: HIDDEN  */
#line 2723 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6608 "conf_parser.c"
    break;

  case 598: /* umode_item: HIDE_CHANS  */
#line 2726 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDECHANS;
}
#line 6616 "conf_parser.c"
    break;

  case 599: /* umode_item: HIDE_IDLE  */
#line 2729 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDEIDLE;
}
#line 6624 "conf_parser.c"
    break;

  case 600: /* umode_item: T_NCHANGE  */
#line 2732 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6632 "conf_parser.c"
    break;

  case 601: /* umode_item: T_REJ  */
#line 2735 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6640 "conf_parser.c"
    break;

  case 602: /* umode_item: T_SPY  */
#line 2738 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6648 "conf_parser.c"
    break;

  case 603: /* umode_item: T_EXTERNAL  */
#line 2741 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6656 "conf_parser.c"
    break;

  case 604: /* umode_item: T_SERVNOTICE  */
#line 2744 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6664 "conf_parser.c"
    break;

  case 605: /* umode_item: T_INVISIBLE  */
#line 2747 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6672 "conf_parser.c"
    break;

  case 606: /* umode_item: T_WALLOP  */
#line 2750 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6680 "conf_parser.c"
    break;

  case 607: /* umode_item: T_SOFTCALLERID  */
#line 2753 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6688 "conf_parser.c"
    break;

  case 608: /* umode_item: T_CALLERID  */
#line 2756 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6696 "conf_parser.c"
    break;

  case 609: /* umode_item: T_LOCOPS  */
#line 2759 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6704 "conf_parser.c"
    break;

  case 610: /* umode_item: T_NONONREG  */
#line 2762 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6712 "conf_parser.c"
    break;

  case 611: /* umode_item: T_FARCONNECT  */
#line 2765 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6720 "conf_parser.c"
    break;

  case 612: /* umode_item: EXPIRATION  */
#line 2768 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6728 "conf_parser.c"
    break;

  case 613: /* umode_item: T_SECUREONLY  */
#line 2771 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SECUREONLY;
}
#line 6736 "conf_parser.c"
    break;

  case 614: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2776 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6744 "conf_parser.c"
    break;

  case 615: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2781 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6752 "conf_parser.c"
    break;

  case 616: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2786 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6760 "conf_parser.c"
    break;

  case 617: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2791 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6768 "conf_parser.c"
    break;

  case 618: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2796 "conf_parser.y"
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
#line 6788 "conf_parser.c"
    break;

  case 619: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2813 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6799 "conf_parser.c"
    break;

  case 620: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2821 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6810 "conf_parser.c"
    break;

  case 621: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2829 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6821 "conf_parser.c"
    break;

  case 622: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2837 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6834 "conf_parser.c"
    break;

  case 623: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2847 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6847 "conf_parser.c"
    break;

  case 645: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2882 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6855 "conf_parser.c"
    break;

  case 646: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2887 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6864 "conf_parser.c"
    break;

  case 647: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2893 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6873 "conf_parser.c"
    break;

  case 648: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2899 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6881 "conf_parser.c"
    break;

  case 649: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2904 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6889 "conf_parser.c"
    break;

  case 650: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2909 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6897 "conf_parser.c"
    break;

  case 651: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2914 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6905 "conf_parser.c"
    break;

  case 652: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2919 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6913 "conf_parser.c"
    break;

  case 653: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2924 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6921 "conf_parser.c"
    break;

  case 654: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2929 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6929 "conf_parser.c"
    break;

  case 655: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2934 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6937 "conf_parser.c"
    break;

  case 656: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2939 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6945 "conf_parser.c"
    break;

  case 657: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2944 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6953 "conf_parser.c"
    break;

  case 658: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2949 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6961 "conf_parser.c"
    break;

  case 659: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2954 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6969 "conf_parser.c"
    break;

  case 660: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2959 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6977 "conf_parser.c"
    break;

  case 661: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2964 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6985 "conf_parser.c"
    break;

  case 675: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2987 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6994 "conf_parser.c"
    break;

  case 676: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2993 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].number) > 0)
    {
      event_flatten_links_write_file.when = (yyvsp[-1].number);
      event_add(&event_flatten_links_write_file, NULL);
    }
    else
     event_delete(&event_flatten_links_write_file);

    ConfigServerHide.flatten_links_delay = (yyvsp[-1].number);
  }
}
#line 7013 "conf_parser.c"
    break;

  case 677: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 3009 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 7025 "conf_parser.c"
    break;

  case 678: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 3018 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 7034 "conf_parser.c"
    break;

  case 679: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 3024 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 7043 "conf_parser.c"
    break;

  case 680: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 3030 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 7052 "conf_parser.c"
    break;

  case 681: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 3036 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 7064 "conf_parser.c"
    break;

  case 682: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 3045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 7073 "conf_parser.c"
    break;

  case 683: /* serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'  */
#line 3051 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 7082 "conf_parser.c"
    break;


#line 7086 "conf_parser.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

