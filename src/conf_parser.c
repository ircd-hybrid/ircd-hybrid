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
    MOTD_FILE = 371,               /* MOTD_FILE  */
    NAME = 372,                    /* NAME  */
    NEED_IDENT = 373,              /* NEED_IDENT  */
    NEED_PASSWORD = 374,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 375,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 376,            /* NETWORK_NAME  */
    NICK = 377,                    /* NICK  */
    NO_OPER_FLOOD = 378,           /* NO_OPER_FLOOD  */
    NO_TILDE = 379,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 380,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 381,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 382,     /* NUMBER_PER_IP_LOCAL  */
    OPER_ONLY_UMODES = 383,        /* OPER_ONLY_UMODES  */
    OPER_UMODES = 384,             /* OPER_UMODES  */
    OPERATOR = 385,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 386,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 387,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 388,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 389,                /* PASSWORD  */
    PATH = 390,                    /* PATH  */
    PING_COOKIE = 391,             /* PING_COOKIE  */
    PING_TIME = 392,               /* PING_TIME  */
    PORT = 393,                    /* PORT  */
    RANDOM_IDLE = 394,             /* RANDOM_IDLE  */
    REASON = 395,                  /* REASON  */
    REDIRPORT = 396,               /* REDIRPORT  */
    REDIRSERV = 397,               /* REDIRSERV  */
    REHASH = 398,                  /* REHASH  */
    REMOTE = 399,                  /* REMOTE  */
    REMOTEBAN = 400,               /* REMOTEBAN  */
    RESIDENT = 401,                /* RESIDENT  */
    RESV = 402,                    /* RESV  */
    RESV_EXEMPT = 403,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 404,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 405,                 /* SECONDS  */
    MINUTES = 406,                 /* MINUTES  */
    HOURS = 407,                   /* HOURS  */
    DAYS = 408,                    /* DAYS  */
    WEEKS = 409,                   /* WEEKS  */
    MONTHS = 410,                  /* MONTHS  */
    YEARS = 411,                   /* YEARS  */
    SEND_PASSWORD = 412,           /* SEND_PASSWORD  */
    SENDQ = 413,                   /* SENDQ  */
    SERVERHIDE = 414,              /* SERVERHIDE  */
    SERVERINFO = 415,              /* SERVERINFO  */
    SHORT_MOTD = 416,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 417,       /* SPECIALS_IN_IDENT  */
    SPOOF = 418,                   /* SPOOF  */
    SQUIT = 419,                   /* SQUIT  */
    STATS_E_DISABLED = 420,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 421,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 422,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 423,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 424,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 425,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 426,       /* STATS_U_OPER_ONLY  */
    T_ALL = 427,                   /* T_ALL  */
    T_BIND = 428,                  /* T_BIND  */
    T_CALLERID = 429,              /* T_CALLERID  */
    T_CCONN = 430,                 /* T_CCONN  */
    T_COMMAND = 431,               /* T_COMMAND  */
    T_CLUSTER = 432,               /* T_CLUSTER  */
    T_DEAF = 433,                  /* T_DEAF  */
    T_DEBUG = 434,                 /* T_DEBUG  */
    T_DLINE = 435,                 /* T_DLINE  */
    T_EXTERNAL = 436,              /* T_EXTERNAL  */
    T_FARCONNECT = 437,            /* T_FARCONNECT  */
    T_FILE = 438,                  /* T_FILE  */
    T_FLOOD = 439,                 /* T_FLOOD  */
    T_GLOBOPS = 440,               /* T_GLOBOPS  */
    T_INVISIBLE = 441,             /* T_INVISIBLE  */
    T_IPV4 = 442,                  /* T_IPV4  */
    T_IPV6 = 443,                  /* T_IPV6  */
    T_LOCOPS = 444,                /* T_LOCOPS  */
    T_LOG = 445,                   /* T_LOG  */
    T_NCHANGE = 446,               /* T_NCHANGE  */
    T_NONONREG = 447,              /* T_NONONREG  */
    T_OPME = 448,                  /* T_OPME  */
    T_PREPEND = 449,               /* T_PREPEND  */
    T_PSEUDO = 450,                /* T_PSEUDO  */
    T_RECVQ = 451,                 /* T_RECVQ  */
    T_REJ = 452,                   /* T_REJ  */
    T_RESTART = 453,               /* T_RESTART  */
    T_SECUREONLY = 454,            /* T_SECUREONLY  */
    T_SERVER = 455,                /* T_SERVER  */
    T_SERVICE = 456,               /* T_SERVICE  */
    T_SERVNOTICE = 457,            /* T_SERVNOTICE  */
    T_SET = 458,                   /* T_SET  */
    T_SHARED = 459,                /* T_SHARED  */
    T_SIZE = 460,                  /* T_SIZE  */
    T_SKILL = 461,                 /* T_SKILL  */
    T_SOFTCALLERID = 462,          /* T_SOFTCALLERID  */
    T_SPY = 463,                   /* T_SPY  */
    T_TARGET = 464,                /* T_TARGET  */
    T_TLS = 465,                   /* T_TLS  */
    T_UMODES = 466,                /* T_UMODES  */
    T_UNDLINE = 467,               /* T_UNDLINE  */
    T_UNLIMITED = 468,             /* T_UNLIMITED  */
    T_UNRESV = 469,                /* T_UNRESV  */
    T_UNXLINE = 470,               /* T_UNXLINE  */
    T_WALLOP = 471,                /* T_WALLOP  */
    T_WALLOPS = 472,               /* T_WALLOPS  */
    T_WEBIRC = 473,                /* T_WEBIRC  */
    TBOOL = 474,                   /* TBOOL  */
    THROTTLE_COUNT = 475,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 476,           /* THROTTLE_TIME  */
    TIMEOUT = 477,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 478,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 479, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 480,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 481,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 482, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 483,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 484, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 485,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 486,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 487,           /* TS_WARN_DELTA  */
    TWODOTS = 488,                 /* TWODOTS  */
    TYPE = 489,                    /* TYPE  */
    UNKLINE = 490,                 /* UNKLINE  */
    USE_LOGGING = 491,             /* USE_LOGGING  */
    USER = 492,                    /* USER  */
    VHOST = 493,                   /* VHOST  */
    VHOST6 = 494,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 495,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 496,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 497,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 498,                   /* XLINE  */
    XLINE_EXEMPT = 499,            /* XLINE_EXEMPT  */
    QSTRING = 500,                 /* QSTRING  */
    NUMBER = 501                   /* NUMBER  */
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
#define MOTD_FILE 371
#define NAME 372
#define NEED_IDENT 373
#define NEED_PASSWORD 374
#define NETWORK_DESCRIPTION 375
#define NETWORK_NAME 376
#define NICK 377
#define NO_OPER_FLOOD 378
#define NO_TILDE 379
#define NUMBER_PER_CIDR 380
#define NUMBER_PER_IP_GLOBAL 381
#define NUMBER_PER_IP_LOCAL 382
#define OPER_ONLY_UMODES 383
#define OPER_UMODES 384
#define OPERATOR 385
#define OPERS_BYPASS_CALLERID 386
#define PACE_WAIT 387
#define PACE_WAIT_SIMPLE 388
#define PASSWORD 389
#define PATH 390
#define PING_COOKIE 391
#define PING_TIME 392
#define PORT 393
#define RANDOM_IDLE 394
#define REASON 395
#define REDIRPORT 396
#define REDIRSERV 397
#define REHASH 398
#define REMOTE 399
#define REMOTEBAN 400
#define RESIDENT 401
#define RESV 402
#define RESV_EXEMPT 403
#define RSA_PRIVATE_KEY_FILE 404
#define SECONDS 405
#define MINUTES 406
#define HOURS 407
#define DAYS 408
#define WEEKS 409
#define MONTHS 410
#define YEARS 411
#define SEND_PASSWORD 412
#define SENDQ 413
#define SERVERHIDE 414
#define SERVERINFO 415
#define SHORT_MOTD 416
#define SPECIALS_IN_IDENT 417
#define SPOOF 418
#define SQUIT 419
#define STATS_E_DISABLED 420
#define STATS_I_OPER_ONLY 421
#define STATS_K_OPER_ONLY 422
#define STATS_M_OPER_ONLY 423
#define STATS_O_OPER_ONLY 424
#define STATS_P_OPER_ONLY 425
#define STATS_U_OPER_ONLY 426
#define T_ALL 427
#define T_BIND 428
#define T_CALLERID 429
#define T_CCONN 430
#define T_COMMAND 431
#define T_CLUSTER 432
#define T_DEAF 433
#define T_DEBUG 434
#define T_DLINE 435
#define T_EXTERNAL 436
#define T_FARCONNECT 437
#define T_FILE 438
#define T_FLOOD 439
#define T_GLOBOPS 440
#define T_INVISIBLE 441
#define T_IPV4 442
#define T_IPV6 443
#define T_LOCOPS 444
#define T_LOG 445
#define T_NCHANGE 446
#define T_NONONREG 447
#define T_OPME 448
#define T_PREPEND 449
#define T_PSEUDO 450
#define T_RECVQ 451
#define T_REJ 452
#define T_RESTART 453
#define T_SECUREONLY 454
#define T_SERVER 455
#define T_SERVICE 456
#define T_SERVNOTICE 457
#define T_SET 458
#define T_SHARED 459
#define T_SIZE 460
#define T_SKILL 461
#define T_SOFTCALLERID 462
#define T_SPY 463
#define T_TARGET 464
#define T_TLS 465
#define T_UMODES 466
#define T_UNDLINE 467
#define T_UNLIMITED 468
#define T_UNRESV 469
#define T_UNXLINE 470
#define T_WALLOP 471
#define T_WALLOPS 472
#define T_WEBIRC 473
#define TBOOL 474
#define THROTTLE_COUNT 475
#define THROTTLE_TIME 476
#define TIMEOUT 477
#define TLS_CERTIFICATE_FILE 478
#define TLS_CERTIFICATE_FINGERPRINT 479
#define TLS_CIPHER_LIST 480
#define TLS_CIPHER_SUITES 481
#define TLS_CONNECTION_REQUIRED 482
#define TLS_DH_PARAM_FILE 483
#define TLS_MESSAGE_DIGEST_ALGORITHM 484
#define TLS_SUPPORTED_GROUPS 485
#define TS_MAX_DELTA 486
#define TS_WARN_DELTA 487
#define TWODOTS 488
#define TYPE 489
#define UNKLINE 490
#define USE_LOGGING 491
#define USER 492
#define VHOST 493
#define VHOST6 494
#define WARN_NO_CONNECT_BLOCK 495
#define WHOIS 496
#define WHOWAS_HISTORY_LENGTH 497
#define XLINE 498
#define XLINE_EXEMPT 499
#define QSTRING 500
#define NUMBER 501

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 135 "conf_parser.y"

  int number;
  char *string;

#line 729 "conf_parser.c"

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
  YYSYMBOL_MOTD_FILE = 116,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 117,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 118,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 119,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 120,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 121,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 122,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 123,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 124,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 125,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 126,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 127,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_ONLY_UMODES = 128,         /* OPER_ONLY_UMODES  */
  YYSYMBOL_OPER_UMODES = 129,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 130,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 131,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 132,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 133,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 134,                 /* PASSWORD  */
  YYSYMBOL_PATH = 135,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 136,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 137,                /* PING_TIME  */
  YYSYMBOL_PORT = 138,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 139,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 140,                   /* REASON  */
  YYSYMBOL_REDIRPORT = 141,                /* REDIRPORT  */
  YYSYMBOL_REDIRSERV = 142,                /* REDIRSERV  */
  YYSYMBOL_REHASH = 143,                   /* REHASH  */
  YYSYMBOL_REMOTE = 144,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 145,                /* REMOTEBAN  */
  YYSYMBOL_RESIDENT = 146,                 /* RESIDENT  */
  YYSYMBOL_RESV = 147,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 148,              /* RESV_EXEMPT  */
  YYSYMBOL_RSA_PRIVATE_KEY_FILE = 149,     /* RSA_PRIVATE_KEY_FILE  */
  YYSYMBOL_SECONDS = 150,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 151,                  /* MINUTES  */
  YYSYMBOL_HOURS = 152,                    /* HOURS  */
  YYSYMBOL_DAYS = 153,                     /* DAYS  */
  YYSYMBOL_WEEKS = 154,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 155,                   /* MONTHS  */
  YYSYMBOL_YEARS = 156,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 157,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 158,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 159,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 160,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 161,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 162,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 163,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 164,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 165,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_I_OPER_ONLY = 166,        /* STATS_I_OPER_ONLY  */
  YYSYMBOL_STATS_K_OPER_ONLY = 167,        /* STATS_K_OPER_ONLY  */
  YYSYMBOL_STATS_M_OPER_ONLY = 168,        /* STATS_M_OPER_ONLY  */
  YYSYMBOL_STATS_O_OPER_ONLY = 169,        /* STATS_O_OPER_ONLY  */
  YYSYMBOL_STATS_P_OPER_ONLY = 170,        /* STATS_P_OPER_ONLY  */
  YYSYMBOL_STATS_U_OPER_ONLY = 171,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 172,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 173,                   /* T_BIND  */
  YYSYMBOL_T_CALLERID = 174,               /* T_CALLERID  */
  YYSYMBOL_T_CCONN = 175,                  /* T_CCONN  */
  YYSYMBOL_T_COMMAND = 176,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 177,                /* T_CLUSTER  */
  YYSYMBOL_T_DEAF = 178,                   /* T_DEAF  */
  YYSYMBOL_T_DEBUG = 179,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 180,                  /* T_DLINE  */
  YYSYMBOL_T_EXTERNAL = 181,               /* T_EXTERNAL  */
  YYSYMBOL_T_FARCONNECT = 182,             /* T_FARCONNECT  */
  YYSYMBOL_T_FILE = 183,                   /* T_FILE  */
  YYSYMBOL_T_FLOOD = 184,                  /* T_FLOOD  */
  YYSYMBOL_T_GLOBOPS = 185,                /* T_GLOBOPS  */
  YYSYMBOL_T_INVISIBLE = 186,              /* T_INVISIBLE  */
  YYSYMBOL_T_IPV4 = 187,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 188,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 189,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 190,                    /* T_LOG  */
  YYSYMBOL_T_NCHANGE = 191,                /* T_NCHANGE  */
  YYSYMBOL_T_NONONREG = 192,               /* T_NONONREG  */
  YYSYMBOL_T_OPME = 193,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 194,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 195,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 196,                  /* T_RECVQ  */
  YYSYMBOL_T_REJ = 197,                    /* T_REJ  */
  YYSYMBOL_T_RESTART = 198,                /* T_RESTART  */
  YYSYMBOL_T_SECUREONLY = 199,             /* T_SECUREONLY  */
  YYSYMBOL_T_SERVER = 200,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 201,                /* T_SERVICE  */
  YYSYMBOL_T_SERVNOTICE = 202,             /* T_SERVNOTICE  */
  YYSYMBOL_T_SET = 203,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 204,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 205,                   /* T_SIZE  */
  YYSYMBOL_T_SKILL = 206,                  /* T_SKILL  */
  YYSYMBOL_T_SOFTCALLERID = 207,           /* T_SOFTCALLERID  */
  YYSYMBOL_T_SPY = 208,                    /* T_SPY  */
  YYSYMBOL_T_TARGET = 209,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 210,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 211,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 212,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 213,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 214,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 215,                /* T_UNXLINE  */
  YYSYMBOL_T_WALLOP = 216,                 /* T_WALLOP  */
  YYSYMBOL_T_WALLOPS = 217,                /* T_WALLOPS  */
  YYSYMBOL_T_WEBIRC = 218,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 219,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 220,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 221,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 222,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 223,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 224, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 225,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 226,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 227,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 228,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 229, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 230,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 231,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 232,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 233,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 234,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 235,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 236,              /* USE_LOGGING  */
  YYSYMBOL_USER = 237,                     /* USER  */
  YYSYMBOL_VHOST = 238,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 239,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 240,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 241,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 242,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 243,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 244,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 245,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 246,                   /* NUMBER  */
  YYSYMBOL_247_ = 247,                     /* ';'  */
  YYSYMBOL_248_ = 248,                     /* '}'  */
  YYSYMBOL_249_ = 249,                     /* '='  */
  YYSYMBOL_250_ = 250,                     /* ':'  */
  YYSYMBOL_251_ = 251,                     /* ','  */
  YYSYMBOL_252_ = 252,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 253,                 /* $accept  */
  YYSYMBOL_conf = 254,                     /* conf  */
  YYSYMBOL_conf_item = 255,                /* conf_item  */
  YYSYMBOL_timespec_ = 256,                /* timespec_  */
  YYSYMBOL_timespec = 257,                 /* timespec  */
  YYSYMBOL_sizespec_ = 258,                /* sizespec_  */
  YYSYMBOL_sizespec = 259,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 260,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 261,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 262,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 263,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 264,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 265,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 266,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 267,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 268, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 269, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 270, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 271, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 272, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 273, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 274, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 275,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 276,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 277,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 278,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 279, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 280, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 281, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 282, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_motd_file = 283,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 284,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 285,              /* admin_entry  */
  YYSYMBOL_admin_items = 286,              /* admin_items  */
  YYSYMBOL_admin_item = 287,               /* admin_item  */
  YYSYMBOL_admin_name = 288,               /* admin_name  */
  YYSYMBOL_admin_email = 289,              /* admin_email  */
  YYSYMBOL_admin_description = 290,        /* admin_description  */
  YYSYMBOL_motd_entry = 291,               /* motd_entry  */
  YYSYMBOL_292_1 = 292,                    /* $@1  */
  YYSYMBOL_motd_items = 293,               /* motd_items  */
  YYSYMBOL_motd_item = 294,                /* motd_item  */
  YYSYMBOL_motd_mask = 295,                /* motd_mask  */
  YYSYMBOL_motd_file = 296,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 297,             /* pseudo_entry  */
  YYSYMBOL_298_2 = 298,                    /* $@2  */
  YYSYMBOL_pseudo_items = 299,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 300,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 301,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 302,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 303,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 304,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 305,            /* logging_entry  */
  YYSYMBOL_logging_items = 306,            /* logging_items  */
  YYSYMBOL_logging_item = 307,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 308,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 309,       /* logging_file_entry  */
  YYSYMBOL_310_3 = 310,                    /* $@3  */
  YYSYMBOL_logging_file_items = 311,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 312,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 313,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 314,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 315,        /* logging_file_type  */
  YYSYMBOL_316_4 = 316,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 317,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 318,               /* oper_entry  */
  YYSYMBOL_319_5 = 319,                    /* $@5  */
  YYSYMBOL_oper_items = 320,               /* oper_items  */
  YYSYMBOL_oper_item = 321,                /* oper_item  */
  YYSYMBOL_oper_name = 322,                /* oper_name  */
  YYSYMBOL_oper_user = 323,                /* oper_user  */
  YYSYMBOL_oper_password = 324,            /* oper_password  */
  YYSYMBOL_oper_whois = 325,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 326,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 327, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 328, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 329,               /* oper_class  */
  YYSYMBOL_oper_umodes = 330,              /* oper_umodes  */
  YYSYMBOL_331_6 = 331,                    /* $@6  */
  YYSYMBOL_oper_umodes_items = 332,        /* oper_umodes_items  */
  YYSYMBOL_oper_umodes_item = 333,         /* oper_umodes_item  */
  YYSYMBOL_oper_flags = 334,               /* oper_flags  */
  YYSYMBOL_335_7 = 335,                    /* $@7  */
  YYSYMBOL_oper_flags_items = 336,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 337,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 338,              /* class_entry  */
  YYSYMBOL_339_8 = 339,                    /* $@8  */
  YYSYMBOL_class_items = 340,              /* class_items  */
  YYSYMBOL_class_item = 341,               /* class_item  */
  YYSYMBOL_class_name = 342,               /* class_name  */
  YYSYMBOL_class_ping_time = 343,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 344, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 345, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 346,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 347,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 348,         /* class_max_number  */
  YYSYMBOL_class_sendq = 349,              /* class_sendq  */
  YYSYMBOL_class_recvq = 350,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 351,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 352,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 353,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 354,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 355,           /* class_max_idle  */
  YYSYMBOL_class_flags = 356,              /* class_flags  */
  YYSYMBOL_357_9 = 357,                    /* $@9  */
  YYSYMBOL_class_flags_items = 358,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 359,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 360,             /* listen_entry  */
  YYSYMBOL_361_10 = 361,                   /* $@10  */
  YYSYMBOL_listen_flags = 362,             /* listen_flags  */
  YYSYMBOL_363_11 = 363,                   /* $@11  */
  YYSYMBOL_listen_flags_items = 364,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 365,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 366,             /* listen_items  */
  YYSYMBOL_listen_item = 367,              /* listen_item  */
  YYSYMBOL_listen_port = 368,              /* listen_port  */
  YYSYMBOL_369_12 = 369,                   /* $@12  */
  YYSYMBOL_port_items = 370,               /* port_items  */
  YYSYMBOL_port_item = 371,                /* port_item  */
  YYSYMBOL_listen_address = 372,           /* listen_address  */
  YYSYMBOL_listen_host = 373,              /* listen_host  */
  YYSYMBOL_auth_entry = 374,               /* auth_entry  */
  YYSYMBOL_375_13 = 375,                   /* $@13  */
  YYSYMBOL_auth_items = 376,               /* auth_items  */
  YYSYMBOL_auth_item = 377,                /* auth_item  */
  YYSYMBOL_auth_user = 378,                /* auth_user  */
  YYSYMBOL_auth_passwd = 379,              /* auth_passwd  */
  YYSYMBOL_auth_class = 380,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 381,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 382,               /* auth_flags  */
  YYSYMBOL_383_14 = 383,                   /* $@14  */
  YYSYMBOL_auth_flags_items = 384,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 385,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 386,               /* auth_spoof  */
  YYSYMBOL_auth_redir_serv = 387,          /* auth_redir_serv  */
  YYSYMBOL_auth_redir_port = 388,          /* auth_redir_port  */
  YYSYMBOL_resv_entry = 389,               /* resv_entry  */
  YYSYMBOL_390_15 = 390,                   /* $@15  */
  YYSYMBOL_resv_items = 391,               /* resv_items  */
  YYSYMBOL_resv_item = 392,                /* resv_item  */
  YYSYMBOL_resv_mask = 393,                /* resv_mask  */
  YYSYMBOL_resv_reason = 394,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 395,              /* resv_exempt  */
  YYSYMBOL_service_entry = 396,            /* service_entry  */
  YYSYMBOL_service_items = 397,            /* service_items  */
  YYSYMBOL_service_item = 398,             /* service_item  */
  YYSYMBOL_service_name = 399,             /* service_name  */
  YYSYMBOL_shared_entry = 400,             /* shared_entry  */
  YYSYMBOL_401_16 = 401,                   /* $@16  */
  YYSYMBOL_shared_items = 402,             /* shared_items  */
  YYSYMBOL_shared_item = 403,              /* shared_item  */
  YYSYMBOL_shared_name = 404,              /* shared_name  */
  YYSYMBOL_shared_user = 405,              /* shared_user  */
  YYSYMBOL_shared_type = 406,              /* shared_type  */
  YYSYMBOL_407_17 = 407,                   /* $@17  */
  YYSYMBOL_shared_types = 408,             /* shared_types  */
  YYSYMBOL_shared_type_item = 409,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 410,            /* cluster_entry  */
  YYSYMBOL_411_18 = 411,                   /* $@18  */
  YYSYMBOL_cluster_items = 412,            /* cluster_items  */
  YYSYMBOL_cluster_item = 413,             /* cluster_item  */
  YYSYMBOL_cluster_name = 414,             /* cluster_name  */
  YYSYMBOL_cluster_type = 415,             /* cluster_type  */
  YYSYMBOL_416_19 = 416,                   /* $@19  */
  YYSYMBOL_cluster_types = 417,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 418,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 419,            /* connect_entry  */
  YYSYMBOL_420_20 = 420,                   /* $@20  */
  YYSYMBOL_connect_items = 421,            /* connect_items  */
  YYSYMBOL_connect_item = 422,             /* connect_item  */
  YYSYMBOL_connect_name = 423,             /* connect_name  */
  YYSYMBOL_connect_host = 424,             /* connect_host  */
  YYSYMBOL_connect_timeout = 425,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 426,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 427,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 428,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 429, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 430,             /* connect_port  */
  YYSYMBOL_connect_aftype = 431,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 432,            /* connect_flags  */
  YYSYMBOL_433_21 = 433,                   /* $@21  */
  YYSYMBOL_connect_flags_items = 434,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 435,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 436,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 437,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 438,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 439,            /* connect_class  */
  YYSYMBOL_connect_tls_cipher_list = 440,  /* connect_tls_cipher_list  */
  YYSYMBOL_kill_entry = 441,               /* kill_entry  */
  YYSYMBOL_442_22 = 442,                   /* $@22  */
  YYSYMBOL_kill_items = 443,               /* kill_items  */
  YYSYMBOL_kill_item = 444,                /* kill_item  */
  YYSYMBOL_kill_user = 445,                /* kill_user  */
  YYSYMBOL_kill_reason = 446,              /* kill_reason  */
  YYSYMBOL_deny_entry = 447,               /* deny_entry  */
  YYSYMBOL_448_23 = 448,                   /* $@23  */
  YYSYMBOL_deny_items = 449,               /* deny_items  */
  YYSYMBOL_deny_item = 450,                /* deny_item  */
  YYSYMBOL_deny_ip = 451,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 452,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 453,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 454,             /* exempt_items  */
  YYSYMBOL_exempt_item = 455,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 456,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 457,              /* gecos_entry  */
  YYSYMBOL_458_24 = 458,                   /* $@24  */
  YYSYMBOL_gecos_items = 459,              /* gecos_items  */
  YYSYMBOL_gecos_item = 460,               /* gecos_item  */
  YYSYMBOL_gecos_name = 461,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 462,             /* gecos_reason  */
  YYSYMBOL_general_entry = 463,            /* general_entry  */
  YYSYMBOL_general_items = 464,            /* general_items  */
  YYSYMBOL_general_item = 465,             /* general_item  */
  YYSYMBOL_general_away_count = 466,       /* general_away_count  */
  YYSYMBOL_general_away_time = 467,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 468,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 469, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 470, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 471,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 472,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 473,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 474,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 475, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 476, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 477,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 478,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 479, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 480,       /* general_max_accept  */
  YYSYMBOL_general_anti_spam_exit_message_time = 481, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 482,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 483,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 484, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 485, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 486, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 487, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 488, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 489, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 490, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 491, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 492, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 493,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 494,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 495, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 496, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 497,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 498,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 499, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 500,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 501,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_auth = 502,     /* general_disable_auth  */
  YYSYMBOL_general_throttle_count = 503,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 504,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 505,      /* general_oper_umodes  */
  YYSYMBOL_506_25 = 506,                   /* $@25  */
  YYSYMBOL_umode_oitems = 507,             /* umode_oitems  */
  YYSYMBOL_umode_oitem = 508,              /* umode_oitem  */
  YYSYMBOL_general_oper_only_umodes = 509, /* general_oper_only_umodes  */
  YYSYMBOL_510_26 = 510,                   /* $@26  */
  YYSYMBOL_umode_items = 511,              /* umode_items  */
  YYSYMBOL_umode_item = 512,               /* umode_item  */
  YYSYMBOL_general_min_nonwildcard = 513,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 514, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 515, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 516, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 517,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 518, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 519, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 520,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 521,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 522,     /* general_cloak_suffix  */
  YYSYMBOL_channel_entry = 523,            /* channel_entry  */
  YYSYMBOL_channel_items = 524,            /* channel_items  */
  YYSYMBOL_channel_item = 525,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 526,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 527,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 528,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 529, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 530, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 531, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 532, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 533, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 534, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 535, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 536, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 537,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 538,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 539,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 540,   /* channel_max_bans_large  */
  YYSYMBOL_channel_default_join_flood_count = 541, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 542, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 543,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 544,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 545,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 546, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 547, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 548, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 549, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 550,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 551, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 552,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 553,        /* serverhide_hidden  */
  YYSYMBOL_serverhide_hide_server_ips = 554 /* serverhide_hide_server_ips  */
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
#define YYLAST   1397

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  253
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  302
/* YYNRULES -- Number of rules.  */
#define YYNRULES  685
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1355

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   501


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
       2,     2,     2,     2,   251,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   250,   247,
       2,   249,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   252,     2,   248,     2,     2,     2,     2,
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
     245,   246
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   383,   383,   384,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   415,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   426,
     426,   427,   428,   429,   430,   437,   447,   454,   456,   458,
     458,   460,   464,   474,   476,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   497,   506,   515,   524,   533,   542,
     551,   560,   575,   590,   600,   614,   623,   646,   669,   692,
     701,   711,   713,   713,   714,   715,   716,   717,   719,   728,
     737,   751,   750,   768,   768,   769,   769,   769,   771,   777,
     788,   787,   806,   806,   807,   807,   807,   807,   807,   809,
     815,   821,   827,   850,   851,   851,   853,   853,   854,   856,
     863,   863,   876,   877,   879,   879,   880,   880,   882,   890,
     893,   899,   898,   904,   908,   912,   916,   920,   924,   928,
     932,   943,   942,  1006,  1006,  1007,  1008,  1009,  1010,  1011,
    1012,  1013,  1014,  1015,  1016,  1017,  1019,  1025,  1031,  1037,
    1043,  1054,  1060,  1071,  1078,  1077,  1083,  1083,  1084,  1088,
    1092,  1096,  1100,  1104,  1108,  1112,  1116,  1120,  1124,  1128,
    1132,  1136,  1140,  1144,  1148,  1152,  1156,  1160,  1164,  1168,
    1175,  1174,  1180,  1180,  1181,  1185,  1189,  1193,  1197,  1201,
    1205,  1209,  1213,  1217,  1221,  1225,  1229,  1233,  1237,  1241,
    1245,  1249,  1253,  1257,  1261,  1265,  1269,  1273,  1277,  1281,
    1285,  1289,  1293,  1297,  1308,  1307,  1363,  1363,  1364,  1365,
    1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,  1375,
    1376,  1377,  1378,  1379,  1381,  1387,  1393,  1399,  1405,  1411,
    1417,  1423,  1429,  1436,  1442,  1448,  1454,  1463,  1473,  1472,
    1478,  1478,  1479,  1483,  1494,  1493,  1500,  1499,  1504,  1504,
    1505,  1509,  1513,  1517,  1521,  1527,  1527,  1528,  1528,  1528,
    1528,  1528,  1530,  1530,  1532,  1532,  1534,  1547,  1564,  1570,
    1581,  1580,  1628,  1628,  1629,  1630,  1631,  1632,  1633,  1634,
    1635,  1636,  1637,  1639,  1645,  1651,  1657,  1669,  1668,  1674,
    1674,  1675,  1679,  1683,  1687,  1691,  1695,  1699,  1703,  1707,
    1713,  1727,  1736,  1750,  1749,  1764,  1764,  1765,  1765,  1765,
    1765,  1767,  1773,  1779,  1789,  1791,  1791,  1792,  1792,  1794,
    1811,  1810,  1833,  1833,  1834,  1834,  1834,  1834,  1836,  1842,
    1862,  1861,  1867,  1867,  1868,  1872,  1876,  1880,  1884,  1888,
    1892,  1896,  1900,  1904,  1915,  1914,  1933,  1933,  1934,  1934,
    1934,  1936,  1943,  1942,  1948,  1948,  1949,  1953,  1957,  1961,
    1965,  1969,  1973,  1977,  1981,  1985,  1996,  1995,  2073,  2073,
    2074,  2075,  2076,  2077,  2078,  2079,  2080,  2081,  2082,  2083,
    2084,  2085,  2086,  2087,  2088,  2089,  2091,  2097,  2103,  2109,
    2115,  2128,  2141,  2147,  2153,  2157,  2164,  2163,  2168,  2168,
    2169,  2173,  2179,  2190,  2196,  2202,  2208,  2224,  2223,  2247,
    2247,  2248,  2248,  2248,  2250,  2270,  2281,  2280,  2305,  2305,
    2306,  2306,  2306,  2308,  2314,  2324,  2326,  2326,  2327,  2327,
    2329,  2347,  2346,  2367,  2367,  2368,  2368,  2368,  2370,  2376,
    2386,  2388,  2388,  2389,  2390,  2391,  2392,  2393,  2394,  2395,
    2396,  2397,  2398,  2399,  2400,  2401,  2402,  2403,  2404,  2405,
    2406,  2407,  2408,  2409,  2410,  2411,  2412,  2413,  2414,  2415,
    2416,  2417,  2418,  2419,  2420,  2421,  2422,  2423,  2424,  2425,
    2426,  2427,  2428,  2429,  2430,  2431,  2432,  2433,  2434,  2435,
    2436,  2437,  2438,  2439,  2440,  2443,  2448,  2453,  2458,  2463,
    2468,  2473,  2478,  2483,  2488,  2493,  2498,  2503,  2508,  2513,
    2518,  2523,  2528,  2533,  2538,  2543,  2548,  2553,  2558,  2563,
    2568,  2573,  2578,  2583,  2588,  2593,  2598,  2603,  2608,  2613,
    2618,  2623,  2628,  2633,  2639,  2638,  2643,  2643,  2644,  2647,
    2650,  2653,  2656,  2659,  2662,  2665,  2668,  2671,  2674,  2677,
    2680,  2683,  2686,  2689,  2692,  2695,  2698,  2701,  2704,  2707,
    2713,  2712,  2717,  2717,  2718,  2721,  2724,  2727,  2730,  2733,
    2736,  2739,  2742,  2745,  2748,  2751,  2754,  2757,  2760,  2763,
    2766,  2769,  2772,  2775,  2778,  2781,  2786,  2791,  2796,  2801,
    2806,  2823,  2831,  2839,  2847,  2857,  2870,  2872,  2872,  2873,
    2874,  2875,  2876,  2877,  2878,  2879,  2880,  2881,  2882,  2883,
    2884,  2885,  2886,  2887,  2888,  2889,  2890,  2892,  2897,  2903,
    2909,  2914,  2919,  2924,  2929,  2934,  2939,  2944,  2949,  2954,
    2959,  2964,  2969,  2974,  2983,  2985,  2985,  2986,  2987,  2988,
    2989,  2990,  2991,  2992,  2993,  2994,  2995,  2997,  3003,  3019,
    3028,  3034,  3040,  3046,  3055,  3061
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
  "MODULE_BASE_PATH", "MOTD", "MOTD_FILE", "NAME", "NEED_IDENT",
  "NEED_PASSWORD", "NETWORK_DESCRIPTION", "NETWORK_NAME", "NICK",
  "NO_OPER_FLOOD", "NO_TILDE", "NUMBER_PER_CIDR", "NUMBER_PER_IP_GLOBAL",
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

#define YYPACT_NINF (-782)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-131)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -782,   848,  -782,  -171,  -246,  -225,  -782,  -782,  -782,  -207,
    -782,  -204,  -782,  -782,  -782,  -186,  -180,  -782,  -782,  -782,
    -181,  -166,  -782,  -165,  -782,  -151,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,    28,   966,  -142,  -128,  -117,    20,  -111,
     412,  -110,   -97,   -96,   -83,   -75,   -70,   -58,   -54,   838,
     551,   -52,    32,   -32,     6,   -16,    -9,    -8,    -6,     0,
      15,  -782,  -782,  -782,  -782,  -782,    27,    38,    66,    76,
      78,    83,    87,    90,    96,    98,    99,   102,   110,   114,
     115,   116,   117,   156,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,   854,   546,    37,  -782,   119,    19,  -782,  -782,
      55,  -782,   120,   121,   122,   124,   125,   126,   127,   131,
     133,   134,   135,   136,   137,   141,   143,   153,   154,   157,
     159,   162,   166,   167,   168,   174,   176,   180,   181,   184,
     191,   193,  -782,  -782,   200,   201,   202,   204,   206,   207,
     210,   211,   213,   216,   217,   219,   220,   225,   227,   229,
     233,   234,   237,    57,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,   330,    34,   310,   -20,
      45,   158,    24,   309,   108,  -782,   239,   240,   241,   247,
     248,   251,   252,   253,   258,   246,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,   257,   260,   261,   262,
     263,   264,   273,   276,   278,   279,   280,   281,   282,   283,
     285,   288,   290,   293,    93,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,    59,   306,   305,    25,  -782,  -782,  -782,
      89,   238,  -782,   307,    22,  -782,  -782,    64,  -782,    29,
      36,    39,   308,  -782,   311,   317,   266,   343,   345,   346,
     322,   317,   317,   317,   323,   317,   317,   326,   329,   338,
     339,   340,  -782,   342,   327,   344,   347,  -782,   349,   351,
     352,   353,   355,   357,   358,   359,   360,   362,   365,    21,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,   348,   367,   369,   370,
     374,   378,   380,  -782,   381,   386,   387,   389,   390,   393,
     404,   407,   255,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
     409,   411,    31,  -782,  -782,  -782,   395,   414,  -782,  -782,
     415,   424,    35,  -782,  -782,  -782,   373,   317,   428,   317,
     317,   375,   431,   435,   436,   438,   440,   467,   441,   317,
     469,   444,   447,   476,   478,   317,   450,   452,   453,   455,
     456,   317,   458,   459,   460,   488,   461,   462,   490,   317,
     317,   494,   495,   470,   502,   503,   506,   507,   509,   510,
     513,   491,   317,   317,   317,   515,   493,   489,  -782,   496,
     498,   500,  -782,   501,   504,   505,   511,   512,   215,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,   514,
     517,    43,  -782,  -782,  -782,   497,   518,   520,  -782,   523,
    -782,    16,  -782,  -782,  -782,  -782,  -782,  -782,   508,  -782,
    -782,  -782,   526,   529,   533,     4,  -782,  -782,  -782,   528,
     534,   535,  -782,   536,   537,  -782,   538,   539,   542,   543,
     183,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,   547,   553,   554,   556,    72,  -782,  -782,  -782,
    -782,   545,   576,   317,   555,   579,   563,   590,   591,   592,
     566,  -782,  -782,   499,   571,   599,   574,   578,   580,   575,
     582,   585,   588,   589,   596,   597,   602,   609,   612,   614,
     616,  -782,   617,   595,  -782,    17,  -782,  -782,  -782,  -782,
     618,   619,  -782,   622,   624,   620,   626,   627,   630,     2,
    -782,  -782,  -782,  -782,  -782,   635,   634,  -782,   636,   637,
    -782,   639,    48,  -782,  -782,  -782,  -782,   638,   642,   644,
    -782,   650,   245,   651,   655,   662,   663,   665,   667,   668,
     669,   670,   671,   672,   675,   676,   677,   680,   681,  -782,
    -782,   679,   683,   317,   682,   686,   317,   688,   317,   690,
     691,   692,   693,   317,   696,   696,   689,  -782,  -782,   699,
    -145,   702,   729,   704,   705,   703,   706,   710,   711,   713,
     714,   317,   716,   720,   709,  -782,   723,   724,   725,  -782,
     726,  -782,   730,   732,   735,  -782,   736,   737,   738,   739,
     740,   741,   742,   743,   745,   746,   747,   749,   750,   751,
     752,   753,   756,   757,   758,   759,   763,   764,   766,   770,
     771,   772,   773,   774,   775,   776,   549,   615,   777,   779,
     780,   781,   782,   783,   784,   785,   786,   787,   788,   789,
     790,   797,   798,   799,   800,   801,   804,  -782,  -782,   808,
     839,   721,   812,   813,   815,   816,   817,   819,  -782,   823,
     824,   825,  -782,  -782,   826,   828,   727,   829,   827,  -782,
     -20,  -782,   831,   832,   833,  -782,  -782,   834,   851,   835,
     836,   837,   840,   841,   859,   842,   843,   844,  -782,  -782,
     845,   847,   849,   846,  -782,   850,   852,   853,   855,   856,
     857,   858,   860,   861,  -782,   862,   863,   864,   865,   866,
     867,   868,   869,   870,   871,   872,   873,   874,   875,   876,
     877,   878,  -782,  -782,   881,   879,   880,  -782,   882,  -782,
     236,  -782,   885,   886,   887,   888,   889,  -782,   890,  -782,
    -782,   893,   891,   894,   895,  -782,  -782,  -782,  -782,  -782,
     317,   317,   317,   317,   317,   317,   317,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,   896,   897,   898,   -61,   899,
     900,   901,   902,   903,   904,   905,   906,   907,    40,   908,
     909,  -782,   910,   911,   912,   913,   914,   915,   916,    23,
     917,   918,   919,   920,   921,   922,   923,   924,  -782,   925,
     926,  -782,  -782,   927,   928,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -232,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -223,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,   929,   930,   243,   931,   932,   933,   934,
     935,  -782,   936,   937,  -782,   938,   939,   316,   259,   883,
    -782,  -782,  -782,   940,   941,  -782,   942,   943,   477,   944,
     945,   654,   946,   947,   948,   949,  -782,   950,   951,   952,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,   953,   678,  -782,
    -782,   954,   892,   955,  -782,   104,  -782,  -782,  -782,  -782,
     956,   958,   959,   960,  -782,  -782,   961,   731,   962,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -217,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,   696,   696,   696,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -210,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,   549,  -782,   615,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -201,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -190,  -782,   964,   829,   965,  -782,
    -782,  -782,  -782,  -782,  -782,   492,  -782,   963,   967,  -782,
     968,  -782,   969,   970,  -782,  -782,   971,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -177,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -159,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -136,  -782,  -782,   957,  -199,
     973,   976,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -134,  -782,
    -782,  -782,   -61,  -782,  -782,  -782,  -782,    23,  -782,  -782,
    -782,   243,  -782,   316,  -782,  -782,  -782,   608,   611,   991,
     988,  1064,  1070,  1071,  -782,   477,  -782,   654,  -782,   678,
     977,   978,   979,   391,  -782,  -782,   731,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,   980,  -782,  -782
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   234,   396,   446,     0,
     461,     0,   300,   437,   274,     0,     0,   101,   151,   333,
       0,     0,   374,     0,   110,     0,   350,     3,     4,     5,
      13,     6,    25,    26,     7,     8,    10,    11,    12,    15,
      16,    17,    18,    19,    20,    21,    22,    24,    23,     9,
      14,    27,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    96,    95,   646,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   628,   643,   644,   645,   642,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   629,   630,
     640,   641,     0,     0,     0,   459,     0,     0,   457,   458,
       0,   524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   590,   564,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   472,   473,   474,   516,   480,   517,
     511,   512,   513,   514,   484,   475,   476,   477,   478,   479,
     481,   482,   483,   485,   486,   515,   490,   491,   492,   493,
     489,   488,   494,   501,   502,   495,   496,   497,   487,   499,
     509,   510,   507,   508,   500,   498,   505,   506,   503,   504,
     518,   519,   520,   521,   522,   523,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   676,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   666,   667,   668,   669,
     670,   671,   672,   674,   673,   675,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    69,    67,    65,    70,
      71,    72,    66,    56,    68,    58,    59,    60,    61,    62,
      63,    64,    57,     0,     0,     0,     0,   125,   126,   127,
       0,     0,   348,     0,     0,   346,   347,     0,    97,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   627,     0,     0,     0,     0,   268,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   241,   243,   244,   245,   246,   247,   248,   249,
     239,   240,   242,   250,   251,   252,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   399,   400,   401,   402,   403,   404,   405,
     406,   408,   407,   410,   414,   411,   412,   413,   409,   452,
       0,     0,     0,   449,   450,   451,     0,     0,   456,   467,
       0,     0,     0,   464,   465,   466,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   471,     0,
       0,     0,   317,     0,     0,     0,     0,     0,     0,   303,
     304,   305,   306,   311,   307,   308,   309,   310,   443,     0,
       0,     0,   440,   441,   442,     0,     0,     0,   276,     0,
     288,     0,   286,   287,   289,   290,    52,    51,    48,    50,
      46,    45,     0,     0,     0,     0,   104,   105,   106,     0,
       0,     0,   200,     0,     0,   174,     0,     0,     0,     0,
       0,   154,   155,   156,   157,   158,   161,   162,   163,   160,
     159,   164,     0,     0,     0,     0,     0,   336,   337,   338,
     339,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   665,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,   382,     0,   377,   378,   379,   128,
       0,     0,   124,     0,     0,     0,     0,     0,     0,     0,
     113,   114,   116,   115,   117,     0,     0,   345,     0,     0,
     360,     0,     0,   353,   354,   355,   356,     0,     0,     0,
      91,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   626,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   415,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   398,     0,     0,     0,   448,
       0,   455,     0,     0,     0,   463,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   470,   312,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,     0,
       0,     0,   439,   291,     0,     0,     0,     0,     0,   285,
       0,   107,     0,     0,     0,   103,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   340,
       0,     0,     0,     0,   335,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   664,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,   380,     0,     0,     0,   376,     0,   123,
       0,   118,     0,     0,     0,     0,     0,   112,     0,   344,
     357,     0,     0,     0,     0,   352,   100,    99,    98,   662,
      29,    29,    29,    29,    29,    29,    29,    31,    30,   663,
     650,   649,   647,   648,   651,   652,   653,   654,   655,   656,
     657,   660,   661,   658,   659,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,     0,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   397,     0,
       0,   447,   460,     0,     0,   462,   536,   540,   525,   526,
     553,   620,   621,   622,   623,   624,   625,   529,   618,   619,
     561,   530,   531,   535,   543,   534,   532,   533,   539,   527,
     538,   537,   559,   616,   617,   557,   594,   614,   599,   600,
     601,   610,   595,   596,   605,   613,   597,   607,   611,   602,
     612,   603,   615,   606,   598,   609,   604,   608,     0,   593,
     568,   588,   572,   573,   574,   584,   569,   570,   579,   587,
     571,   581,   585,   576,   586,   577,   589,   580,   575,   583,
     578,   582,     0,   567,   554,   552,   555,   560,   556,   558,
     545,   551,   550,   546,   547,   548,   549,   562,   563,   542,
     541,   544,   528,     0,     0,     0,     0,     0,     0,     0,
       0,   301,     0,     0,   438,     0,     0,     0,   296,   292,
     295,   275,    49,     0,     0,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     0,     0,     0,
     334,   680,   677,   678,   679,   684,   683,   685,   681,   682,
      86,    83,    90,    82,    87,    88,    89,    81,    85,    84,
      75,    74,    77,    78,    76,    79,    80,     0,     0,   375,
     129,     0,     0,     0,   141,     0,   133,   134,   136,   135,
       0,     0,     0,     0,   111,   349,     0,     0,     0,   351,
      32,    33,    34,    35,    36,    37,    38,   263,   264,   258,
     273,   272,     0,   271,   259,   267,   260,   266,   254,   265,
     257,   256,   255,    39,    39,    39,    41,    40,   261,   262,
     421,   424,   425,   435,   432,   417,   433,   430,   431,     0,
     429,   434,   416,   423,   420,   419,   418,   422,   436,   453,
     454,   468,   469,   591,     0,   565,     0,   315,   316,   325,
     321,   322,   324,   329,   326,   327,   328,   323,     0,   320,
     314,   332,   331,   330,   313,   445,   444,   299,   298,   283,
     284,   281,   282,   280,     0,   279,     0,     0,     0,   108,
     109,   173,   170,   220,   232,   207,   216,     0,   205,   210,
       0,   226,     0,   219,   224,   230,   209,   212,   221,   223,
     227,   217,   225,   213,   231,   215,   222,   211,   214,     0,
     203,   166,   168,   178,   198,   182,   183,   184,   194,   179,
     180,   189,   197,   181,   191,   195,   186,   196,   187,   199,
     190,   185,   193,   188,   192,     0,   177,   171,   172,   167,
     169,   343,   341,   342,   381,   386,   392,   395,   388,   394,
     389,   393,   391,   387,   390,     0,   385,   137,     0,     0,
       0,     0,   132,   120,   119,   121,   122,   358,   364,   370,
     373,   366,   372,   367,   371,   369,   365,   368,     0,   363,
     359,   269,     0,    42,    43,    44,   427,     0,   592,   566,
     318,     0,   277,     0,   297,   294,   293,     0,     0,     0,
       0,     0,     0,     0,   201,     0,   175,     0,   383,     0,
       0,     0,     0,     0,   131,   361,     0,   270,   428,   319,
     278,   206,   229,   204,   233,   228,   218,   208,   202,   176,
     384,   138,   140,   139,   149,   148,   144,   146,   150,   147,
     143,   145,     0,   362,   142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -782,  -782,  -782,  -205,  -323,  -781,  -664,  -782,  -782,  -782,
    -782,   315,  -782,  -782,   811,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  1016,  -782,  -782,  -782,  -782,  -782,
    -782,   573,  -782,  -782,  -782,  -782,  -782,   607,  -782,  -782,
    -782,  -782,  -782,  -782,   795,  -782,  -782,  -782,  -782,   144,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,   694,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -211,  -782,  -782,  -782,   -87,  -782,  -782,  -782,   884,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,   -62,  -782,  -782,  -782,
    -782,  -782,   -72,  -782,   722,  -782,  -782,  -782,    49,  -782,
    -782,  -782,  -782,  -782,   744,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,   -66,  -782,  -782,  -782,  -782,  -782,  -782,   684,
    -782,  -782,  -782,  -782,  -782,   972,  -782,  -782,  -782,  -782,
     623,  -782,  -782,  -782,  -782,  -782,   -89,  -782,  -782,  -782,
     643,  -782,  -782,  -782,  -782,   -80,  -782,  -782,  -782,   974,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,   -56,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,   748,  -782,  -782,  -782,  -782,  -782,   830,  -782,  -782,
    -782,  -782,  1117,  -782,  -782,  -782,  -782,   975,  -782,  -782,
    -782,  -782,  1063,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,    91,  -782,  -782,  -782,    94,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  1147,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782,   996,  -782,  -782,  -782,  -782,  -782,  -782,  -782,
    -782,  -782
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   857,   858,  1126,  1127,    28,    29,   240,
     518,   519,    30,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,    31,    80,    81,    82,    83,    84,    32,    66,
     525,   526,   527,   528,    33,    73,   609,   610,   611,   612,
     613,   614,    34,   306,   307,   308,   309,   310,  1085,  1086,
    1087,  1088,  1089,  1270,  1352,    35,    67,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   782,  1245,
    1246,   551,   779,  1219,  1220,    36,    55,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   654,  1112,  1113,    37,    63,   510,
     766,  1184,  1185,   511,   512,   513,  1188,  1029,  1030,   514,
     515,    38,    61,   488,   489,   490,   491,   492,   493,   494,
     751,  1168,  1169,   495,   496,   497,    39,    68,   556,   557,
     558,   559,   560,    40,   314,   315,   316,    41,    75,   622,
     623,   624,   625,   626,   842,  1288,  1289,    42,    71,   595,
     596,   597,   598,   825,  1265,  1266,    43,    56,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     675,  1139,  1140,   404,   405,   406,   407,   408,    44,    62,
     501,   502,   503,   504,    45,    57,   412,   413,   414,   415,
      46,   127,   128,   129,    47,    59,   422,   423,   424,   425,
      48,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   457,   992,   993,   225,   456,   968,   969,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      49,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      50,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     889,   890,   633,   604,  1110,   522,    53,   312,   639,   640,
     641,   516,   643,   644,  1321,  1153,    76,   505,   592,  1154,
     125,   125,   343,   312,  1155,   522,   304,    54,  1156,    76,
    1291,  1137,   409,   304,  1292,   498,   419,  1296,   409,   344,
     345,  1297,   893,   894,   498,    58,  1300,   888,    60,   618,
    1301,   346,  1123,  1124,  1125,    77,   419,  1302,   131,    64,
     592,  1303,    78,   132,   133,   618,   134,   135,    77,    65,
    1314,    69,   136,   552,  1315,    78,    51,    52,  1111,   137,
     138,   139,   140,   141,   142,   506,    70,    72,  1316,   143,
     144,   145,  1317,   507,   266,   508,   126,   126,   523,   146,
     347,    74,   147,   148,   697,  1081,   699,   700,   410,   552,
     122,  1318,   149,  1325,   410,  1319,   709,  1326,   523,   605,
     348,   349,   715,   313,   123,   553,   517,   350,   721,   150,
     267,   351,    79,   268,   593,   124,   729,   730,   352,   313,
     151,   130,   236,   152,   153,    79,   353,   354,   355,   742,
     743,   744,   420,   154,   509,   237,   238,    85,   356,   155,
     156,   553,   157,   269,   158,   619,   554,   239,   159,   160,
     241,   411,   420,   270,   499,   421,   593,   411,   606,   357,
     161,   619,   242,   499,   529,   162,   163,   524,   164,   165,
     166,    86,    87,   167,   243,   421,   607,   271,   244,    88,
     303,   272,   554,   530,    89,    90,    91,   524,  -130,   273,
     274,   608,   555,   275,   276,  -130,   479,   358,   168,   169,
     311,  1082,   170,   171,   172,   173,   174,   175,   176,    92,
      93,    94,    95,  1138,   531,   480,   317,  1081,   318,   604,
     797,   319,   277,   320,    96,    97,    98,   245,   555,   321,
     836,   594,   774,    99,   100,   101,   376,   102,   377,  1159,
     378,   305,   532,   322,   768,   826,   481,   417,   305,   666,
     616,   500,   603,   601,   627,   379,   324,   177,   178,   688,
     500,   628,   620,   694,   629,   621,   888,   325,   179,   180,
     246,   761,   520,   594,   482,  1160,   844,   181,   620,   182,
     533,   621,   247,   248,   249,   477,   380,   250,   251,  1083,
     529,   505,   252,   253,   254,   326,   278,   534,   279,   280,
     793,   281,   282,   283,   381,   327,   382,   328,  1161,   530,
     877,   479,   329,   880,   383,   882,   330,  1179,  1084,   331,
     887,   590,  1293,  1294,  1295,   332,   384,   333,   334,   483,
     480,   335,  1271,  1082,  1180,   605,   484,   485,   905,   336,
     531,  1162,  1163,   337,   338,   339,   340,  1164,   416,   426,
     427,   428,   385,   429,   430,   431,   432,  1181,   486,   506,
     433,   481,   434,   435,   436,   437,   438,   507,   532,   508,
     439,  1165,   440,   386,   535,   850,   851,   852,   853,   854,
     855,   856,   441,   442,   341,   521,   443,   536,   444,   482,
     537,   445,   387,   131,   606,   446,   447,   448,   132,   133,
     538,   134,   135,   449,   539,   450,   533,   136,   388,   451,
     452,   787,   607,   453,   137,   138,   139,   140,   141,   142,
     454,  1083,   455,   534,   143,   144,   145,   608,   509,   458,
     459,   460,   487,   461,   146,   462,   463,   147,   148,   464,
     465,  1166,   466,   757,   483,   467,   468,   149,   469,   470,
    1084,   484,   485,  1344,   471,  1345,   472,   389,   473,   390,
     391,  1193,   474,   475,   150,   634,   476,  1167,   561,   562,
     563,   632,  1186,   486,   570,   151,   564,   565,   152,   153,
     566,   567,   568,   684,   572,  1194,  1195,   569,   154,   573,
     574,   575,   576,   577,   155,   156,  1182,   157,  1196,   158,
     535,  1346,   578,   159,   160,   579,  1183,   580,   581,   582,
     583,   584,   585,   536,   586,   161,   537,   587,  1347,   588,
     162,   163,   589,   164,   165,   166,   538,   376,   167,   377,
     539,   378,   266,   599,   600,   630,   615,   631,  1197,  1198,
     946,  1199,   635,   632,   636,   637,   379,   487,   638,   642,
    1348,  1349,   645,   168,   169,   646,   651,   170,   171,   172,
     173,   174,   175,   176,   647,   648,  1200,   649,   267,   650,
    1201,   268,   696,   652,   701,   668,   653,   380,   655,  1202,
     656,   657,   658,   947,   659,  1322,   660,   661,   662,   663,
     948,   664,   949,   950,   665,   381,   669,   382,   670,   671,
    1203,   269,  1204,   672,  1205,   383,   970,   673,  1350,   674,
     676,   270,   177,   178,  1351,   677,   678,   384,   679,   680,
     690,  1206,   681,   179,   180,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,   181,   682,   182,   271,   683,  1207,   686,   272,
     687,   691,  1208,   385,   692,  1223,  1209,   273,   274,   971,
    1210,   275,   276,   693,   698,  1211,   972,   702,   973,   974,
    1212,   703,   704,   705,   386,   706,   707,   708,   710,  1213,
     711,  1214,  1215,   712,  1216,   713,   716,   714,   717,   718,
     277,   719,   720,   387,   722,   723,   724,   725,  1224,   728,
     726,   727,  1217,   731,   732,  1225,   733,  1226,  1227,   388,
    1218,   734,   735,   951,   952,   736,   737,   953,   738,   739,
     954,   955,   740,   956,   745,   957,   747,   741,   958,   746,
     959,   960,  1307,   748,   763,   805,   961,   749,   962,   750,
     752,   963,  1331,   753,   754,   964,   965,   966,  1332,   770,
     755,   756,  1255,   759,   795,   967,   760,   764,   389,   765,
     390,   391,   767,   771,   278,   776,   279,   280,   772,   281,
     282,   283,   773,   777,   778,   780,   781,   783,   784,   975,
     976,   785,   786,   977,   789,   796,   978,   979,   799,   980,
     798,   981,   790,   791,   982,   792,   983,   984,   800,   801,
     802,   803,   985,   804,   986,  1278,   806,   987,   807,   808,
     811,   988,   989,   990,   809,  1256,   810,   812,  1228,  1229,
     813,   991,  1230,   814,   815,  1231,  1232,   828,  1233,   245,
    1234,   816,   817,  1235,   824,  1236,  1237,   818,     2,     3,
    1257,  1238,     4,  1239,   819,   343,  1240,   820,  1258,   821,
    1241,  1242,  1243,   822,   823,     5,   829,  1259,     6,   832,
    1244,   831,   344,   345,   830,   833,   834,     7,  1279,   835,
     838,   839,   246,   840,   346,   846,   841,     8,   843,   847,
    1260,   848,  1261,  1262,   247,   248,   249,   849,   859,   250,
     251,     9,   860,  1280,   252,   253,   254,    10,    11,   861,
     862,  1281,   863,  1263,   864,   865,   866,   867,   868,   869,
    1282,  1264,   870,   871,   872,   875,    12,   873,   874,   876,
      13,   878,   879,   347,   881,   883,   891,   884,   885,   886,
      14,    15,   888,  1283,   892,  1284,  1285,   895,   896,   897,
     898,   900,   899,   348,   349,   901,   908,   902,   903,   904,
     350,   906,    16,    17,   351,   907,  1286,    85,   909,   910,
    1015,   352,   911,   912,  1287,   913,  1027,   914,    18,   353,
     354,   355,   915,   916,   917,   918,   919,   920,   921,   922,
     923,   356,   924,   925,   926,    19,   927,   928,   929,   930,
     931,    86,    87,   932,   933,   934,   935,    20,    21,    88,
     936,   937,   357,   938,    89,    90,    91,   939,   940,   941,
     942,   943,   944,   945,   994,    22,   995,   996,   997,   998,
     999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,    23,    92,
      93,    94,    95,    24,  1007,  1008,  1009,  1010,  1011,    25,
     358,  1012,    26,  1013,    96,    97,    98,  1016,  1014,  1017,
    1018,  1019,  1020,    99,   100,   101,  1021,   102,  1022,  1023,
    1037,  1025,  1024,  1026,  1031,  1028,  1033,  1034,  1043,  1036,
    1035,  1039,  1040,  1334,  1038,  1032,  1042,  1044,  1045,  1041,
    1047,  1046,  1048,  1050,  1049,   591,   323,  1051,   775,  1052,
    1053,   602,  1054,  1055,  1056,  1057,  1339,  1058,  1059,  1060,
    1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070,
    1071,  1072,  1073,  1074,  1075,  1076,  1077,  1079,  1078,  1080,
    1090,  1091,  1092,  1093,  1187,  1333,  1094,  1095,  1096,  1098,
    1097,  1268,  1099,  1107,  1108,  1109,  1114,  1115,  1116,  1117,
    1118,  1119,  1120,  1121,  1122,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1141,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,  1150,  1151,  1152,  1157,  1158,  1170,  1171,
    1172,  1173,  1174,  1175,  1176,  1177,  1178,  1189,  1190,  1191,
    1192,  1221,  1222,  1247,  1248,  1249,  1250,  1251,  1252,  1253,
    1254,  1267,  1320,  1273,  1269,  1274,  1275,  1276,  1277,  1290,
    1304,  1335,  1306,  1308,  1336,  1337,   837,  1309,  1310,  1311,
    1312,  1313,  1323,  1324,  1341,  1342,  1343,  1354,  1338,  1272,
    1327,  1330,   758,   769,   788,  1329,  1305,  1353,   827,  1340,
     794,  1328,   689,   667,   418,   845,   478,  1299,  1298,   762,
     342,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   617,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   685,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   695
};

static const yytype_int16 yycheck[] =
{
     664,   665,   325,     1,    65,     1,   252,     1,   331,   332,
     333,    31,   335,   336,   213,   247,     1,     1,     1,   251,
       1,     1,     1,     1,   247,     1,     1,   252,   251,     1,
     247,     8,     1,     1,   251,     1,     1,   247,     1,    18,
      19,   251,   187,   188,     1,   252,   247,   246,   252,     1,
     251,    30,    12,    13,    14,    40,     1,   247,     1,   245,
       1,   251,    47,     6,     7,     1,     9,    10,    40,   249,
     247,   252,    15,     1,   251,    47,   247,   248,   139,    22,
      23,    24,    25,    26,    27,    69,   252,   252,   247,    32,
      33,    34,   251,    77,     1,    79,    77,    77,    94,    42,
      79,   252,    45,    46,   427,     1,   429,   430,    77,     1,
     252,   247,    55,   247,    77,   251,   439,   251,    94,   117,
      99,   100,   445,   117,   252,    53,   146,   106,   451,    72,
      37,   110,   117,    40,   117,   252,   459,   460,   117,   117,
      83,   252,   252,    86,    87,   117,   125,   126,   127,   472,
     473,   474,   117,    96,   138,   252,   252,     1,   137,   102,
     103,    53,   105,    70,   107,   117,    94,   250,   111,   112,
     245,   140,   117,    80,   140,   140,   117,   140,   176,   158,
     123,   117,   252,   140,     1,   128,   129,   183,   131,   132,
     133,    35,    36,   136,   252,   140,   194,   104,   252,    43,
     252,   108,    94,    20,    48,    49,    50,   183,   183,   116,
     117,   209,   140,   120,   121,   183,     1,   196,   161,   162,
     252,   117,   165,   166,   167,   168,   169,   170,   171,    73,
      74,    75,    76,   210,    51,    20,   252,     1,   247,     1,
     563,   249,   149,   249,    88,    89,    90,     1,   140,   249,
     248,   234,   248,    97,    98,    99,     1,   101,     3,    16,
       5,   236,    79,   248,   248,   248,    51,   248,   236,   248,
     248,   237,   183,   248,   245,    20,   249,   220,   221,   248,
     237,   245,   234,   248,   245,   237,   246,   249,   231,   232,
      44,   248,   247,   234,    79,    52,   248,   240,   234,   242,
     117,   237,    56,    57,    58,   248,    51,    61,    62,   205,
       1,     1,    66,    67,    68,   249,   223,   134,   225,   226,
     248,   228,   229,   230,    69,   249,    71,   249,    85,    20,
     653,     1,   249,   656,    79,   658,   249,    21,   234,   249,
     663,   248,  1123,  1124,  1125,   249,    91,   249,   249,   134,
      20,   249,   248,   117,    38,   117,   141,   142,   681,   249,
      51,   118,   119,   249,   249,   249,   249,   124,   249,   249,
     249,   249,   117,   249,   249,   249,   249,    61,   163,    69,
     249,    51,   249,   249,   249,   249,   249,    77,    79,    79,
     249,   148,   249,   138,   211,   150,   151,   152,   153,   154,
     155,   156,   249,   249,   248,   247,   249,   224,   249,    79,
     227,   249,   157,     1,   176,   249,   249,   249,     6,     7,
     237,     9,    10,   249,   241,   249,   117,    15,   173,   249,
     249,   248,   194,   249,    22,    23,    24,    25,    26,    27,
     249,   205,   249,   134,    32,    33,    34,   209,   138,   249,
     249,   249,   237,   249,    42,   249,   249,    45,    46,   249,
     249,   218,   249,   248,   134,   249,   249,    55,   249,   249,
     234,   141,   142,    82,   249,    84,   249,   222,   249,   224,
     225,     4,   249,   249,    72,   219,   249,   244,   249,   249,
     249,   246,   233,   163,   248,    83,   249,   249,    86,    87,
     249,   249,   249,   248,   247,    28,    29,   249,    96,   249,
     249,   249,   249,   249,   102,   103,   200,   105,    41,   107,
     211,   130,   249,   111,   112,   249,   210,   249,   249,   249,
     249,   249,   249,   224,   249,   123,   227,   249,   147,   249,
     128,   129,   249,   131,   132,   133,   237,     1,   136,     3,
     241,     5,     1,   247,   249,   247,   249,   246,    81,    82,
      11,    84,   219,   246,   219,   219,    20,   237,   246,   246,
     179,   180,   246,   161,   162,   246,   249,   165,   166,   167,
     168,   169,   170,   171,   246,   246,   109,   247,    37,   247,
     113,    40,   219,   249,   219,   247,   249,    51,   249,   122,
     249,   249,   249,    54,   249,  1269,   249,   249,   249,   249,
      61,   249,    63,    64,   249,    69,   249,    71,   249,   249,
     143,    70,   145,   249,   147,    79,    11,   249,   237,   249,
     249,    80,   220,   221,   243,   249,   249,    91,   249,   249,
     245,   164,   249,   231,   232,   850,   851,   852,   853,   854,
     855,   856,   240,   249,   242,   104,   249,   180,   249,   108,
     249,   247,   185,   117,   249,    11,   189,   116,   117,    54,
     193,   120,   121,   249,   246,   198,    61,   246,    63,    64,
     203,   246,   246,   245,   138,   245,   219,   246,   219,   212,
     246,   214,   215,   246,   217,   219,   246,   219,   246,   246,
     149,   246,   246,   157,   246,   246,   246,   219,    54,   219,
     249,   249,   235,   219,   219,    61,   246,    63,    64,   173,
     243,   219,   219,   174,   175,   219,   219,   178,   219,   219,
     181,   182,   219,   184,   219,   186,   247,   246,   189,   246,
     191,   192,   250,   247,   247,   246,   197,   249,   199,   249,
     249,   202,   144,   249,   249,   206,   207,   208,   147,   251,
     249,   249,    84,   249,   219,   216,   249,   249,   222,   249,
     224,   225,   249,   247,   223,   247,   225,   226,   249,   228,
     229,   230,   249,   249,   249,   249,   249,   249,   249,   174,
     175,   249,   249,   178,   247,   219,   181,   182,   219,   184,
     245,   186,   249,   249,   189,   249,   191,   192,   245,   219,
     219,   219,   197,   247,   199,    84,   245,   202,   219,   245,
     245,   206,   207,   208,   246,   147,   246,   245,   174,   175,
     245,   216,   178,   245,   245,   181,   182,   219,   184,     1,
     186,   245,   245,   189,   249,   191,   192,   245,     0,     1,
     172,   197,     4,   199,   245,     1,   202,   245,   180,   245,
     206,   207,   208,   247,   247,    17,   247,   189,    20,   249,
     216,   247,    18,    19,   252,   249,   249,    29,   147,   249,
     245,   247,    44,   247,    30,   247,   249,    39,   249,   247,
     212,   247,   214,   215,    56,    57,    58,   247,   247,    61,
      62,    53,   247,   172,    66,    67,    68,    59,    60,   247,
     247,   180,   247,   235,   247,   247,   247,   247,   247,   247,
     189,   243,   247,   247,   247,   246,    78,   247,   247,   246,
      82,   249,   246,    79,   246,   245,   247,   246,   246,   246,
      92,    93,   246,   212,   245,   214,   215,   245,   219,   245,
     245,   245,   249,    99,   100,   245,   247,   246,   245,   245,
     106,   245,   114,   115,   110,   245,   235,     1,   245,   245,
     249,   117,   247,   247,   243,   245,   249,   245,   130,   125,
     126,   127,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   137,   247,   247,   247,   147,   247,   247,   247,   247,
     247,    35,    36,   247,   247,   247,   247,   159,   160,    43,
     247,   247,   158,   247,    48,    49,    50,   247,   247,   247,
     247,   247,   247,   247,   247,   177,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   190,    73,
      74,    75,    76,   195,   247,   247,   247,   247,   247,   201,
     196,   247,   204,   245,    88,    89,    90,   245,   219,   246,
     245,   245,   245,    97,    98,    99,   247,   101,   245,   245,
     219,   245,   247,   245,   247,   246,   245,   245,   219,   245,
     247,   245,   245,    95,   249,   770,   245,   245,   245,   249,
     245,   247,   245,   247,   245,   284,    80,   247,   525,   247,
     247,   306,   247,   247,   247,   247,  1317,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   245,   247,   249,   247,
     245,   245,   245,   245,   251,   144,   247,   247,   245,   245,
     249,   249,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   245,   247,   249,   247,   247,   247,   247,   247,
     246,   147,   247,   250,   144,   144,   609,   250,   250,   250,
     250,   250,   249,   247,   247,   247,   247,   247,  1315,  1085,
    1292,  1303,   488,   511,   540,  1301,  1187,  1326,   595,  1319,
     556,  1297,   412,   359,   127,   622,   183,  1156,  1154,   501,
     103,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   422
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   254,     0,     1,     4,    17,    20,    29,    39,    53,
      59,    60,    78,    82,    92,    93,   114,   115,   130,   147,
     159,   160,   177,   190,   195,   201,   204,   255,   260,   261,
     265,   285,   291,   297,   305,   318,   338,   360,   374,   389,
     396,   400,   410,   419,   441,   447,   453,   457,   463,   523,
     543,   247,   248,   252,   252,   339,   420,   448,   252,   458,
     252,   375,   442,   361,   245,   249,   292,   319,   390,   252,
     252,   411,   252,   298,   252,   401,     1,    40,    47,   117,
     286,   287,   288,   289,   290,     1,    35,    36,    43,    48,
      49,    50,    73,    74,    75,    76,    88,    89,    90,    97,
      98,    99,   101,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   252,   252,   252,     1,    77,   454,   455,   456,
     252,     1,     6,     7,     9,    10,    15,    22,    23,    24,
      25,    26,    27,    32,    33,    34,    42,    45,    46,    55,
      72,    83,    86,    87,    96,   102,   103,   105,   107,   111,
     112,   123,   128,   129,   131,   132,   133,   136,   161,   162,
     165,   166,   167,   168,   169,   170,   171,   220,   221,   231,
     232,   240,   242,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   509,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   252,   252,   252,   250,
     262,   245,   252,   252,   252,     1,    44,    56,    57,    58,
      61,    62,    66,    67,    68,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,     1,    37,    40,    70,
      80,   104,   108,   116,   117,   120,   121,   149,   223,   225,
     226,   228,   229,   230,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   252,     1,   236,   306,   307,   308,   309,
     310,   252,     1,   117,   397,   398,   399,   252,   247,   249,
     249,   249,   248,   287,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   248,   525,     1,    18,    19,    30,    79,    99,   100,
     106,   110,   117,   125,   126,   127,   137,   158,   196,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     1,     3,     5,    20,
      51,    69,    71,    79,    91,   117,   138,   157,   173,   222,
     224,   225,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   436,   437,   438,   439,   440,     1,
      77,   140,   449,   450,   451,   452,   249,   248,   455,     1,
     117,   140,   459,   460,   461,   462,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   510,   506,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   248,   465,     1,
      20,    51,    79,   134,   141,   142,   163,   237,   376,   377,
     378,   379,   380,   381,   382,   386,   387,   388,     1,   140,
     237,   443,   444,   445,   446,     1,    69,    77,    79,   138,
     362,   366,   367,   368,   372,   373,    31,   146,   263,   264,
     247,   247,     1,    94,   183,   293,   294,   295,   296,     1,
      20,    51,    79,   117,   134,   211,   224,   227,   237,   241,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   334,     1,    53,    94,   140,   391,   392,   393,   394,
     395,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     248,   545,   247,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     248,   267,     1,   117,   234,   412,   413,   414,   415,   247,
     249,   248,   307,   183,     1,   117,   176,   194,   209,   299,
     300,   301,   302,   303,   304,   249,   248,   398,     1,   117,
     234,   237,   402,   403,   404,   405,   406,   245,   245,   245,
     247,   246,   246,   257,   219,   219,   219,   219,   246,   257,
     257,   257,   246,   257,   257,   246,   246,   246,   246,   247,
     247,   249,   249,   249,   357,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   248,   341,   247,   249,
     249,   249,   249,   249,   249,   433,   249,   249,   249,   249,
     249,   249,   249,   249,   248,   422,   249,   249,   248,   450,
     245,   247,   249,   249,   248,   460,   219,   257,   246,   257,
     257,   219,   246,   246,   246,   245,   245,   219,   246,   257,
     219,   246,   246,   219,   219,   257,   246,   246,   246,   246,
     246,   257,   246,   246,   246,   219,   249,   249,   219,   257,
     257,   219,   219,   246,   219,   219,   219,   219,   219,   219,
     219,   246,   257,   257,   257,   219,   246,   247,   247,   249,
     249,   383,   249,   249,   249,   249,   249,   248,   377,   249,
     249,   248,   444,   247,   249,   249,   363,   249,   248,   367,
     251,   247,   249,   249,   248,   294,   247,   249,   249,   335,
     249,   249,   331,   249,   249,   249,   249,   248,   321,   247,
     249,   249,   249,   248,   392,   219,   219,   257,   245,   219,
     245,   219,   219,   219,   247,   246,   245,   219,   245,   246,
     246,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   247,   247,   249,   416,   248,   413,   219,   247,
     252,   247,   249,   249,   249,   249,   248,   300,   245,   247,
     247,   249,   407,   249,   248,   403,   247,   247,   247,   247,
     150,   151,   152,   153,   154,   155,   156,   256,   257,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   246,   246,   257,   249,   246,
     257,   246,   257,   245,   246,   246,   246,   257,   246,   259,
     259,   247,   245,   187,   188,   245,   219,   245,   245,   249,
     245,   245,   246,   245,   245,   257,   245,   245,   247,   245,
     245,   247,   247,   245,   245,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,    11,    54,    61,    63,
      64,   174,   175,   178,   181,   182,   184,   186,   189,   191,
     192,   197,   199,   202,   206,   207,   208,   216,   511,   512,
      11,    54,    61,    63,    64,   174,   175,   178,   181,   182,
     184,   186,   189,   191,   192,   197,   199,   202,   206,   207,
     208,   216,   507,   508,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   245,   219,   249,   245,   246,   245,   245,
     245,   247,   245,   245,   247,   245,   245,   249,   246,   370,
     371,   247,   264,   245,   245,   247,   245,   219,   249,   245,
     245,   249,   245,   219,   245,   245,   247,   245,   245,   245,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   245,   249,   247,
     247,     1,   117,   205,   234,   311,   312,   313,   314,   315,
     245,   245,   245,   245,   247,   247,   245,   249,   245,   247,
     256,   256,   256,   256,   256,   256,   256,   247,   247,   247,
      65,   139,   358,   359,   247,   247,   247,   247,   247,   247,
     247,   247,   247,    12,    13,    14,   258,   259,   247,   247,
     247,   247,   247,   247,   247,   247,   247,     8,   210,   434,
     435,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   251,   247,   251,   247,   247,    16,
      52,    85,   118,   119,   124,   148,   218,   244,   384,   385,
     247,   247,   247,   247,   247,   247,   247,   247,   247,    21,
      38,    61,   200,   210,   364,   365,   233,   251,   369,   247,
     247,   247,   247,     4,    28,    29,    41,    81,    82,    84,
     109,   113,   122,   143,   145,   147,   164,   180,   185,   189,
     193,   198,   203,   212,   214,   215,   217,   235,   243,   336,
     337,   247,   247,    11,    54,    61,    63,    64,   174,   175,
     178,   181,   182,   184,   186,   189,   191,   192,   197,   199,
     202,   206,   207,   208,   216,   332,   333,   247,   247,   247,
     247,   247,   247,   247,   247,    84,   147,   172,   180,   189,
     212,   214,   215,   235,   243,   417,   418,   247,   249,   249,
     316,   248,   312,   247,   247,   247,   247,   247,    84,   147,
     172,   180,   189,   212,   214,   215,   235,   243,   408,   409,
     247,   247,   251,   258,   258,   258,   247,   251,   512,   508,
     247,   251,   247,   251,   246,   371,   247,   250,   250,   250,
     250,   250,   250,   250,   247,   251,   247,   251,   247,   251,
     245,   213,   259,   249,   247,   247,   251,   359,   435,   385,
     365,   144,   147,   144,    95,   147,   144,   144,   337,   333,
     418,   247,   247,   247,    82,    84,   130,   147,   179,   180,
     237,   243,   317,   409,   247
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   253,   254,   254,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   256,
     256,   257,   257,   257,   257,   257,   257,   257,   257,   258,
     258,   259,   259,   259,   259,   260,   261,   262,   262,   263,
     263,   264,   264,   265,   266,   266,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   286,   287,   287,   287,   287,   288,   289,
     290,   292,   291,   293,   293,   294,   294,   294,   295,   296,
     298,   297,   299,   299,   300,   300,   300,   300,   300,   301,
     302,   303,   304,   305,   306,   306,   307,   307,   307,   308,
     310,   309,   311,   311,   312,   312,   312,   312,   313,   314,
     314,   316,   315,   317,   317,   317,   317,   317,   317,   317,
     317,   319,   318,   320,   320,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   331,   330,   332,   332,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     335,   334,   336,   336,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   339,   338,   340,   340,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   357,   356,
     358,   358,   359,   359,   361,   360,   363,   362,   364,   364,
     365,   365,   365,   365,   365,   366,   366,   367,   367,   367,
     367,   367,   369,   368,   370,   370,   371,   371,   372,   373,
     375,   374,   376,   376,   377,   377,   377,   377,   377,   377,
     377,   377,   377,   378,   379,   380,   381,   383,   382,   384,
     384,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     386,   387,   388,   390,   389,   391,   391,   392,   392,   392,
     392,   393,   394,   395,   396,   397,   397,   398,   398,   399,
     401,   400,   402,   402,   403,   403,   403,   403,   404,   405,
     407,   406,   408,   408,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   411,   410,   412,   412,   413,   413,
     413,   414,   416,   415,   417,   417,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   420,   419,   421,   421,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   431,   433,   432,   434,   434,
     435,   435,   436,   437,   438,   439,   440,   442,   441,   443,
     443,   444,   444,   444,   445,   446,   448,   447,   449,   449,
     450,   450,   450,   451,   452,   453,   454,   454,   455,   455,
     456,   458,   457,   459,   459,   460,   460,   460,   461,   462,
     463,   464,   464,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   506,   505,   507,   507,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     510,   509,   511,   511,   512,   512,   512,   512,   512,   512,
     512,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     512,   512,   512,   512,   512,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   524,   525,
     525,   525,   525,   525,   525,   525,   525,   525,   525,   525,
     525,   525,   525,   525,   525,   525,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   544,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554
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
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     3,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     0,     6,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     0,     5,     3,     1,     1,     3,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     5,     2,     1,     1,     1,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       2,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     4,     4,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     2,     1,     1,     1,     1,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
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
#line 415 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3370 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 416 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3376 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 417 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3382 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 418 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3388 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 419 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3394 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 420 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3400 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 421 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3406 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 422 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3412 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 423 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3418 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 426 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3424 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 427 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3430 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 428 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3436 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 429 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3442 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 430 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3448 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 438 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3457 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 448 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3466 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 454 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3474 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 461 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3483 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 465 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3492 "conf_parser.c"
    break;

  case 74: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 498 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3504 "conf_parser.c"
    break;

  case 75: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 507 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = io_strdup(yylval.string);
  }
}
#line 3516 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 516 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = io_strdup(yylval.string);
  }
}
#line 3528 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 525 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = io_strdup(yylval.string);
  }
}
#line 3540 "conf_parser.c"
    break;

  case 78: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 534 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = io_strdup(yylval.string);
  }
}
#line 3552 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 543 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = io_strdup(yylval.string);
  }
}
#line 3564 "conf_parser.c"
    break;

  case 80: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 552 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = io_strdup(yylval.string);
  }
}
#line 3576 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 561 "conf_parser.y"
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
#line 3594 "conf_parser.c"
    break;

  case 82: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 576 "conf_parser.y"
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
#line 3612 "conf_parser.c"
    break;

  case 83: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 591 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3625 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 601 "conf_parser.y"
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
#line 3642 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 615 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3654 "conf_parser.c"
    break;

  case 86: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 624 "conf_parser.y"
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
#line 3680 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 647 "conf_parser.y"
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
#line 3706 "conf_parser.c"
    break;

  case 88: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 670 "conf_parser.y"
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
#line 3732 "conf_parser.c"
    break;

  case 89: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 693 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3744 "conf_parser.c"
    break;

  case 90: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 702 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3753 "conf_parser.c"
    break;

  case 98: /* admin_name: NAME '=' QSTRING ';'  */
#line 720 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3765 "conf_parser.c"
    break;

  case 99: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 729 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3777 "conf_parser.c"
    break;

  case 100: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 738 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3789 "conf_parser.c"
    break;

  case 101: /* $@1: %empty  */
#line 751 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3798 "conf_parser.c"
    break;

  case 102: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 755 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3815 "conf_parser.c"
    break;

  case 108: /* motd_mask: MASK '=' QSTRING ';'  */
#line 772 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3824 "conf_parser.c"
    break;

  case 109: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 778 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3833 "conf_parser.c"
    break;

  case 110: /* $@2: %empty  */
#line 788 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3842 "conf_parser.c"
    break;

  case 111: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 792 "conf_parser.y"
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
#line 3860 "conf_parser.c"
    break;

  case 119: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 810 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3869 "conf_parser.c"
    break;

  case 120: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 816 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3878 "conf_parser.c"
    break;

  case 121: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 822 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3887 "conf_parser.c"
    break;

  case 122: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 828 "conf_parser.y"
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
#line 3909 "conf_parser.c"
    break;

  case 129: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 857 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3918 "conf_parser.c"
    break;

  case 130: /* $@3: %empty  */
#line 863 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3927 "conf_parser.c"
    break;

  case 131: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 867 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3940 "conf_parser.c"
    break;

  case 138: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 883 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3951 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 891 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3959 "conf_parser.c"
    break;

  case 140: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 894 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3967 "conf_parser.c"
    break;

  case 141: /* $@4: %empty  */
#line 899 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3976 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: USER  */
#line 905 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3985 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: OPERATOR  */
#line 909 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3994 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: XLINE  */
#line 913 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4003 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: RESV  */
#line 917 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4012 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: T_DLINE  */
#line 921 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4021 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KLINE  */
#line 925 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4030 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: KILL  */
#line 929 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4039 "conf_parser.c"
    break;

  case 150: /* logging_file_type_item: T_DEBUG  */
#line 933 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4048 "conf_parser.c"
    break;

  case 151: /* $@5: %empty  */
#line 943 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 4060 "conf_parser.c"
    break;

  case 152: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 950 "conf_parser.y"
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
#line 4120 "conf_parser.c"
    break;

  case 166: /* oper_name: NAME '=' QSTRING ';'  */
#line 1020 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4129 "conf_parser.c"
    break;

  case 167: /* oper_user: USER '=' QSTRING ';'  */
#line 1026 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4138 "conf_parser.c"
    break;

  case 168: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1032 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4147 "conf_parser.c"
    break;

  case 169: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1038 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4156 "conf_parser.c"
    break;

  case 170: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1044 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 4170 "conf_parser.c"
    break;

  case 171: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1055 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4179 "conf_parser.c"
    break;

  case 172: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1061 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 4193 "conf_parser.c"
    break;

  case 173: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1072 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4202 "conf_parser.c"
    break;

  case 174: /* $@6: %empty  */
#line 1078 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 4211 "conf_parser.c"
    break;

  case 178: /* oper_umodes_item: BOT  */
#line 1085 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOT;
}
#line 4220 "conf_parser.c"
    break;

  case 179: /* oper_umodes_item: T_CCONN  */
#line 1089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 4229 "conf_parser.c"
    break;

  case 180: /* oper_umodes_item: T_DEAF  */
#line 1093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 4238 "conf_parser.c"
    break;

  case 181: /* oper_umodes_item: T_FLOOD  */
#line 1097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FLOOD;
}
#line 4247 "conf_parser.c"
    break;

  case 182: /* oper_umodes_item: HIDDEN  */
#line 1101 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 4256 "conf_parser.c"
    break;

  case 183: /* oper_umodes_item: HIDE_CHANS  */
#line 1105 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 4265 "conf_parser.c"
    break;

  case 184: /* oper_umodes_item: HIDE_IDLE  */
#line 1109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 4274 "conf_parser.c"
    break;

  case 185: /* oper_umodes_item: T_SKILL  */
#line 1113 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 4283 "conf_parser.c"
    break;

  case 186: /* oper_umodes_item: T_NCHANGE  */
#line 1117 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 4292 "conf_parser.c"
    break;

  case 187: /* oper_umodes_item: T_REJ  */
#line 1121 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 4301 "conf_parser.c"
    break;

  case 188: /* oper_umodes_item: T_SPY  */
#line 1125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4310 "conf_parser.c"
    break;

  case 189: /* oper_umodes_item: T_EXTERNAL  */
#line 1129 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4319 "conf_parser.c"
    break;

  case 190: /* oper_umodes_item: T_SERVNOTICE  */
#line 1133 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4328 "conf_parser.c"
    break;

  case 191: /* oper_umodes_item: T_INVISIBLE  */
#line 1137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4337 "conf_parser.c"
    break;

  case 192: /* oper_umodes_item: T_WALLOP  */
#line 1141 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4346 "conf_parser.c"
    break;

  case 193: /* oper_umodes_item: T_SOFTCALLERID  */
#line 1145 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4355 "conf_parser.c"
    break;

  case 194: /* oper_umodes_item: T_CALLERID  */
#line 1149 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4364 "conf_parser.c"
    break;

  case 195: /* oper_umodes_item: T_LOCOPS  */
#line 1153 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4373 "conf_parser.c"
    break;

  case 196: /* oper_umodes_item: T_NONONREG  */
#line 1157 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4382 "conf_parser.c"
    break;

  case 197: /* oper_umodes_item: T_FARCONNECT  */
#line 1161 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4391 "conf_parser.c"
    break;

  case 198: /* oper_umodes_item: EXPIRATION  */
#line 1165 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 4400 "conf_parser.c"
    break;

  case 199: /* oper_umodes_item: T_SECUREONLY  */
#line 1169 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SECUREONLY;
}
#line 4409 "conf_parser.c"
    break;

  case 200: /* $@7: %empty  */
#line 1175 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4418 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: KILL ':' REMOTE  */
#line 1182 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4427 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: KILL  */
#line 1186 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4436 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1190 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4445 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: CONNECT  */
#line 1194 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4454 "conf_parser.c"
    break;

  case 208: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1198 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4463 "conf_parser.c"
    break;

  case 209: /* oper_flags_item: SQUIT  */
#line 1202 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4472 "conf_parser.c"
    break;

  case 210: /* oper_flags_item: KLINE  */
#line 1206 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4481 "conf_parser.c"
    break;

  case 211: /* oper_flags_item: UNKLINE  */
#line 1210 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4490 "conf_parser.c"
    break;

  case 212: /* oper_flags_item: T_DLINE  */
#line 1214 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4499 "conf_parser.c"
    break;

  case 213: /* oper_flags_item: T_UNDLINE  */
#line 1218 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4508 "conf_parser.c"
    break;

  case 214: /* oper_flags_item: XLINE  */
#line 1222 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4517 "conf_parser.c"
    break;

  case 215: /* oper_flags_item: T_UNXLINE  */
#line 1226 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4526 "conf_parser.c"
    break;

  case 216: /* oper_flags_item: DIE  */
#line 1230 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4535 "conf_parser.c"
    break;

  case 217: /* oper_flags_item: T_RESTART  */
#line 1234 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4544 "conf_parser.c"
    break;

  case 218: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1238 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4553 "conf_parser.c"
    break;

  case 219: /* oper_flags_item: REHASH  */
#line 1242 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4562 "conf_parser.c"
    break;

  case 220: /* oper_flags_item: ADMIN  */
#line 1246 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4571 "conf_parser.c"
    break;

  case 221: /* oper_flags_item: T_GLOBOPS  */
#line 1250 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4580 "conf_parser.c"
    break;

  case 222: /* oper_flags_item: T_WALLOPS  */
#line 1254 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4589 "conf_parser.c"
    break;

  case 223: /* oper_flags_item: T_LOCOPS  */
#line 1258 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4598 "conf_parser.c"
    break;

  case 224: /* oper_flags_item: REMOTEBAN  */
#line 1262 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4607 "conf_parser.c"
    break;

  case 225: /* oper_flags_item: T_SET  */
#line 1266 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4616 "conf_parser.c"
    break;

  case 226: /* oper_flags_item: MODULE  */
#line 1270 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4625 "conf_parser.c"
    break;

  case 227: /* oper_flags_item: T_OPME  */
#line 1274 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4634 "conf_parser.c"
    break;

  case 228: /* oper_flags_item: NICK ':' RESV  */
#line 1278 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4643 "conf_parser.c"
    break;

  case 229: /* oper_flags_item: JOIN ':' RESV  */
#line 1282 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4652 "conf_parser.c"
    break;

  case 230: /* oper_flags_item: RESV  */
#line 1286 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4661 "conf_parser.c"
    break;

  case 231: /* oper_flags_item: T_UNRESV  */
#line 1290 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4670 "conf_parser.c"
    break;

  case 232: /* oper_flags_item: CLOSE  */
#line 1294 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4679 "conf_parser.c"
    break;

  case 233: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1298 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4688 "conf_parser.c"
    break;

  case 234: /* $@8: %empty  */
#line 1308 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4704 "conf_parser.c"
    break;

  case 235: /* class_entry: CLASS $@8 '{' class_items '}' ';'  */
#line 1319 "conf_parser.y"
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
#line 4752 "conf_parser.c"
    break;

  case 254: /* class_name: NAME '=' QSTRING ';'  */
#line 1382 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4761 "conf_parser.c"
    break;

  case 255: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1388 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4770 "conf_parser.c"
    break;

  case 256: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1394 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4779 "conf_parser.c"
    break;

  case 257: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1400 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4788 "conf_parser.c"
    break;

  case 258: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1406 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4797 "conf_parser.c"
    break;

  case 259: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1412 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4806 "conf_parser.c"
    break;

  case 260: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1418 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4815 "conf_parser.c"
    break;

  case 261: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1424 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4824 "conf_parser.c"
    break;

  case 262: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1430 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4834 "conf_parser.c"
    break;

  case 263: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1437 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4843 "conf_parser.c"
    break;

  case 264: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1443 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4852 "conf_parser.c"
    break;

  case 265: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1449 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4861 "conf_parser.c"
    break;

  case 266: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1455 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4873 "conf_parser.c"
    break;

  case 267: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1464 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4885 "conf_parser.c"
    break;

  case 268: /* $@9: %empty  */
#line 1473 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4894 "conf_parser.c"
    break;

  case 272: /* class_flags_item: RANDOM_IDLE  */
#line 1480 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4903 "conf_parser.c"
    break;

  case 273: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1484 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4912 "conf_parser.c"
    break;

  case 274: /* $@10: %empty  */
#line 1494 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4921 "conf_parser.c"
    break;

  case 276: /* $@11: %empty  */
#line 1500 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4929 "conf_parser.c"
    break;

  case 280: /* listen_flags_item: T_TLS  */
#line 1506 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4938 "conf_parser.c"
    break;

  case 281: /* listen_flags_item: HIDDEN  */
#line 1510 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4947 "conf_parser.c"
    break;

  case 282: /* listen_flags_item: T_SERVER  */
#line 1514 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4956 "conf_parser.c"
    break;

  case 283: /* listen_flags_item: CLIENT  */
#line 1518 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4965 "conf_parser.c"
    break;

  case 284: /* listen_flags_item: DEFER  */
#line 1522 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4974 "conf_parser.c"
    break;

  case 292: /* $@12: %empty  */
#line 1530 "conf_parser.y"
                                 { reset_block_state(); }
#line 4980 "conf_parser.c"
    break;

  case 296: /* port_item: NUMBER  */
#line 1535 "conf_parser.y"
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
#line 4998 "conf_parser.c"
    break;

  case 297: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1548 "conf_parser.y"
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
#line 5018 "conf_parser.c"
    break;

  case 298: /* listen_address: IP '=' QSTRING ';'  */
#line 1565 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5027 "conf_parser.c"
    break;

  case 299: /* listen_host: HOST '=' QSTRING ';'  */
#line 1571 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5036 "conf_parser.c"
    break;

  case 300: /* $@13: %empty  */
#line 1581 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5045 "conf_parser.c"
    break;

  case 301: /* auth_entry: IRCD_AUTH $@13 '{' auth_items '}' ';'  */
#line 1585 "conf_parser.y"
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
#line 5092 "conf_parser.c"
    break;

  case 313: /* auth_user: USER '=' QSTRING ';'  */
#line 1640 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5101 "conf_parser.c"
    break;

  case 314: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1646 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5110 "conf_parser.c"
    break;

  case 315: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1652 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5119 "conf_parser.c"
    break;

  case 316: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5133 "conf_parser.c"
    break;

  case 317: /* $@14: %empty  */
#line 1669 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 5142 "conf_parser.c"
    break;

  case 321: /* auth_flags_item: EXCEED_LIMIT  */
#line 1676 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 5151 "conf_parser.c"
    break;

  case 322: /* auth_flags_item: KLINE_EXEMPT  */
#line 1680 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 5160 "conf_parser.c"
    break;

  case 323: /* auth_flags_item: XLINE_EXEMPT  */
#line 1684 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 5169 "conf_parser.c"
    break;

  case 324: /* auth_flags_item: NEED_IDENT  */
#line 1688 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 5178 "conf_parser.c"
    break;

  case 325: /* auth_flags_item: CAN_FLOOD  */
#line 1692 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 5187 "conf_parser.c"
    break;

  case 326: /* auth_flags_item: NO_TILDE  */
#line 1696 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 5196 "conf_parser.c"
    break;

  case 327: /* auth_flags_item: RESV_EXEMPT  */
#line 1700 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 5205 "conf_parser.c"
    break;

  case 328: /* auth_flags_item: T_WEBIRC  */
#line 1704 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 5214 "conf_parser.c"
    break;

  case 329: /* auth_flags_item: NEED_PASSWORD  */
#line 1708 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 5223 "conf_parser.c"
    break;

  case 330: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1714 "conf_parser.y"
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
#line 5240 "conf_parser.c"
    break;

  case 331: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1728 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 5252 "conf_parser.c"
    break;

  case 332: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1737 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 5264 "conf_parser.c"
    break;

  case 333: /* $@15: %empty  */
#line 1750 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5276 "conf_parser.c"
    break;

  case 334: /* resv_entry: RESV $@15 '{' resv_items '}' ';'  */
#line 1757 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5287 "conf_parser.c"
    break;

  case 341: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1768 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5296 "conf_parser.c"
    break;

  case 342: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1774 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5305 "conf_parser.c"
    break;

  case 343: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1780 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5314 "conf_parser.c"
    break;

  case 349: /* service_name: NAME '=' QSTRING ';'  */
#line 1795 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5329 "conf_parser.c"
    break;

  case 350: /* $@16: %empty  */
#line 1811 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5345 "conf_parser.c"
    break;

  case 351: /* shared_entry: T_SHARED $@16 '{' shared_items '}' ';'  */
#line 1822 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5360 "conf_parser.c"
    break;

  case 358: /* shared_name: NAME '=' QSTRING ';'  */
#line 1837 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5369 "conf_parser.c"
    break;

  case 359: /* shared_user: USER '=' QSTRING ';'  */
#line 1843 "conf_parser.y"
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
#line 5391 "conf_parser.c"
    break;

  case 360: /* $@17: %empty  */
#line 1862 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5400 "conf_parser.c"
    break;

  case 364: /* shared_type_item: KLINE  */
#line 1869 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5409 "conf_parser.c"
    break;

  case 365: /* shared_type_item: UNKLINE  */
#line 1873 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5418 "conf_parser.c"
    break;

  case 366: /* shared_type_item: T_DLINE  */
#line 1877 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5427 "conf_parser.c"
    break;

  case 367: /* shared_type_item: T_UNDLINE  */
#line 1881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5436 "conf_parser.c"
    break;

  case 368: /* shared_type_item: XLINE  */
#line 1885 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5445 "conf_parser.c"
    break;

  case 369: /* shared_type_item: T_UNXLINE  */
#line 1889 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5454 "conf_parser.c"
    break;

  case 370: /* shared_type_item: RESV  */
#line 1893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5463 "conf_parser.c"
    break;

  case 371: /* shared_type_item: T_UNRESV  */
#line 1897 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5472 "conf_parser.c"
    break;

  case 372: /* shared_type_item: T_LOCOPS  */
#line 1901 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5481 "conf_parser.c"
    break;

  case 373: /* shared_type_item: T_ALL  */
#line 1905 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5490 "conf_parser.c"
    break;

  case 374: /* $@18: %empty  */
#line 1915 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5504 "conf_parser.c"
    break;

  case 375: /* cluster_entry: T_CLUSTER $@18 '{' cluster_items '}' ';'  */
#line 1924 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5517 "conf_parser.c"
    break;

  case 381: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1937 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5526 "conf_parser.c"
    break;

  case 382: /* $@19: %empty  */
#line 1943 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5535 "conf_parser.c"
    break;

  case 386: /* cluster_type_item: KLINE  */
#line 1950 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5544 "conf_parser.c"
    break;

  case 387: /* cluster_type_item: UNKLINE  */
#line 1954 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5553 "conf_parser.c"
    break;

  case 388: /* cluster_type_item: T_DLINE  */
#line 1958 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5562 "conf_parser.c"
    break;

  case 389: /* cluster_type_item: T_UNDLINE  */
#line 1962 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5571 "conf_parser.c"
    break;

  case 390: /* cluster_type_item: XLINE  */
#line 1966 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5580 "conf_parser.c"
    break;

  case 391: /* cluster_type_item: T_UNXLINE  */
#line 1970 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5589 "conf_parser.c"
    break;

  case 392: /* cluster_type_item: RESV  */
#line 1974 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5598 "conf_parser.c"
    break;

  case 393: /* cluster_type_item: T_UNRESV  */
#line 1978 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5607 "conf_parser.c"
    break;

  case 394: /* cluster_type_item: T_LOCOPS  */
#line 1982 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5616 "conf_parser.c"
    break;

  case 395: /* cluster_type_item: T_ALL  */
#line 1986 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5625 "conf_parser.c"
    break;

  case 396: /* $@20: %empty  */
#line 1996 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5640 "conf_parser.c"
    break;

  case 397: /* connect_entry: CONNECT $@20 '{' connect_items '}' ';'  */
#line 2006 "conf_parser.y"
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
#line 5711 "conf_parser.c"
    break;

  case 416: /* connect_name: NAME '=' QSTRING ';'  */
#line 2092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5720 "conf_parser.c"
    break;

  case 417: /* connect_host: HOST '=' QSTRING ';'  */
#line 2098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5729 "conf_parser.c"
    break;

  case 418: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 2104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5738 "conf_parser.c"
    break;

  case 419: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 2110 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5747 "conf_parser.c"
    break;

  case 420: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2116 "conf_parser.y"
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
#line 5763 "conf_parser.c"
    break;

  case 421: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2129 "conf_parser.y"
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
#line 5779 "conf_parser.c"
    break;

  case 422: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2142 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5788 "conf_parser.c"
    break;

  case 423: /* connect_port: PORT '=' NUMBER ';'  */
#line 2148 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5797 "conf_parser.c"
    break;

  case 424: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2154 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5806 "conf_parser.c"
    break;

  case 425: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2158 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5815 "conf_parser.c"
    break;

  case 426: /* $@21: %empty  */
#line 2164 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5823 "conf_parser.c"
    break;

  case 430: /* connect_flags_item: AUTOCONN  */
#line 2170 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5832 "conf_parser.c"
    break;

  case 431: /* connect_flags_item: T_TLS  */
#line 2174 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5841 "conf_parser.c"
    break;

  case 432: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2180 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5855 "conf_parser.c"
    break;

  case 433: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2191 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5864 "conf_parser.c"
    break;

  case 434: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2197 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5873 "conf_parser.c"
    break;

  case 435: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2203 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5882 "conf_parser.c"
    break;

  case 436: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2209 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5896 "conf_parser.c"
    break;

  case 437: /* $@22: %empty  */
#line 2224 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5905 "conf_parser.c"
    break;

  case 438: /* kill_entry: KILL $@22 '{' kill_items '}' ';'  */
#line 2228 "conf_parser.y"
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
#line 5928 "conf_parser.c"
    break;

  case 444: /* kill_user: USER '=' QSTRING ';'  */
#line 2251 "conf_parser.y"
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
#line 5951 "conf_parser.c"
    break;

  case 445: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2271 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5960 "conf_parser.c"
    break;

  case 446: /* $@23: %empty  */
#line 2281 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5969 "conf_parser.c"
    break;

  case 447: /* deny_entry: DENY $@23 '{' deny_items '}' ';'  */
#line 2285 "conf_parser.y"
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
#line 5993 "conf_parser.c"
    break;

  case 453: /* deny_ip: IP '=' QSTRING ';'  */
#line 2309 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 6002 "conf_parser.c"
    break;

  case 454: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2315 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 6011 "conf_parser.c"
    break;

  case 460: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2330 "conf_parser.y"
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
#line 6028 "conf_parser.c"
    break;

  case 461: /* $@24: %empty  */
#line 2347 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 6037 "conf_parser.c"
    break;

  case 462: /* gecos_entry: GECOS $@24 '{' gecos_items '}' ';'  */
#line 2351 "conf_parser.y"
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
#line 6057 "conf_parser.c"
    break;

  case 468: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2371 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 6066 "conf_parser.c"
    break;

  case 469: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2377 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 6075 "conf_parser.c"
    break;

  case 525: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2444 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 6083 "conf_parser.c"
    break;

  case 526: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2449 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 6091 "conf_parser.c"
    break;

  case 527: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2454 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 6099 "conf_parser.c"
    break;

  case 528: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2459 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 6107 "conf_parser.c"
    break;

  case 529: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2464 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 6115 "conf_parser.c"
    break;

  case 530: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2469 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 6123 "conf_parser.c"
    break;

  case 531: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2474 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 6131 "conf_parser.c"
    break;

  case 532: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2479 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6139 "conf_parser.c"
    break;

  case 533: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2484 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6147 "conf_parser.c"
    break;

  case 534: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2489 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6155 "conf_parser.c"
    break;

  case 535: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2494 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 6163 "conf_parser.c"
    break;

  case 536: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2499 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 6171 "conf_parser.c"
    break;

  case 537: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2504 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6179 "conf_parser.c"
    break;

  case 538: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2509 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6187 "conf_parser.c"
    break;

  case 539: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2514 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6195 "conf_parser.c"
    break;

  case 540: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2519 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6203 "conf_parser.c"
    break;

  case 541: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2524 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6211 "conf_parser.c"
    break;

  case 542: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2529 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6219 "conf_parser.c"
    break;

  case 543: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2534 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6227 "conf_parser.c"
    break;

  case 544: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2539 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6235 "conf_parser.c"
    break;

  case 545: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2544 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6243 "conf_parser.c"
    break;

  case 546: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2549 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 6251 "conf_parser.c"
    break;

  case 547: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2554 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 6259 "conf_parser.c"
    break;

  case 548: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2559 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 6267 "conf_parser.c"
    break;

  case 549: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2564 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6275 "conf_parser.c"
    break;

  case 550: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2569 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 6283 "conf_parser.c"
    break;

  case 551: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2574 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 6291 "conf_parser.c"
    break;

  case 552: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2579 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6299 "conf_parser.c"
    break;

  case 553: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2584 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6307 "conf_parser.c"
    break;

  case 554: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2589 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6315 "conf_parser.c"
    break;

  case 555: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2594 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6323 "conf_parser.c"
    break;

  case 556: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2599 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6331 "conf_parser.c"
    break;

  case 557: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2604 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6339 "conf_parser.c"
    break;

  case 558: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2609 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6347 "conf_parser.c"
    break;

  case 559: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2614 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6355 "conf_parser.c"
    break;

  case 560: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2619 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6363 "conf_parser.c"
    break;

  case 561: /* general_disable_auth: DISABLE_AUTH '=' TBOOL ';'  */
#line 2624 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6371 "conf_parser.c"
    break;

  case 562: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2629 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6379 "conf_parser.c"
    break;

  case 563: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2634 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6387 "conf_parser.c"
    break;

  case 564: /* $@25: %empty  */
#line 2639 "conf_parser.y"
{
  ConfigGeneral.oper_umodes = 0;
}
#line 6395 "conf_parser.c"
    break;

  case 568: /* umode_oitem: BOT  */
#line 2645 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_BOT;
}
#line 6403 "conf_parser.c"
    break;

  case 569: /* umode_oitem: T_CCONN  */
#line 2648 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6411 "conf_parser.c"
    break;

  case 570: /* umode_oitem: T_DEAF  */
#line 2651 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6419 "conf_parser.c"
    break;

  case 571: /* umode_oitem: T_FLOOD  */
#line 2654 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FLOOD;
}
#line 6427 "conf_parser.c"
    break;

  case 572: /* umode_oitem: HIDDEN  */
#line 2657 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6435 "conf_parser.c"
    break;

  case 573: /* umode_oitem: HIDE_CHANS  */
#line 2660 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6443 "conf_parser.c"
    break;

  case 574: /* umode_oitem: HIDE_IDLE  */
#line 2663 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6451 "conf_parser.c"
    break;

  case 575: /* umode_oitem: T_SKILL  */
#line 2666 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6459 "conf_parser.c"
    break;

  case 576: /* umode_oitem: T_NCHANGE  */
#line 2669 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6467 "conf_parser.c"
    break;

  case 577: /* umode_oitem: T_REJ  */
#line 2672 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6475 "conf_parser.c"
    break;

  case 578: /* umode_oitem: T_SPY  */
#line 2675 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6483 "conf_parser.c"
    break;

  case 579: /* umode_oitem: T_EXTERNAL  */
#line 2678 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6491 "conf_parser.c"
    break;

  case 580: /* umode_oitem: T_SERVNOTICE  */
#line 2681 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6499 "conf_parser.c"
    break;

  case 581: /* umode_oitem: T_INVISIBLE  */
#line 2684 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6507 "conf_parser.c"
    break;

  case 582: /* umode_oitem: T_WALLOP  */
#line 2687 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6515 "conf_parser.c"
    break;

  case 583: /* umode_oitem: T_SOFTCALLERID  */
#line 2690 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6523 "conf_parser.c"
    break;

  case 584: /* umode_oitem: T_CALLERID  */
#line 2693 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6531 "conf_parser.c"
    break;

  case 585: /* umode_oitem: T_LOCOPS  */
#line 2696 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6539 "conf_parser.c"
    break;

  case 586: /* umode_oitem: T_NONONREG  */
#line 2699 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6547 "conf_parser.c"
    break;

  case 587: /* umode_oitem: T_FARCONNECT  */
#line 2702 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6555 "conf_parser.c"
    break;

  case 588: /* umode_oitem: EXPIRATION  */
#line 2705 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6563 "conf_parser.c"
    break;

  case 589: /* umode_oitem: T_SECUREONLY  */
#line 2708 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SECUREONLY;
}
#line 6571 "conf_parser.c"
    break;

  case 590: /* $@26: %empty  */
#line 2713 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6579 "conf_parser.c"
    break;

  case 594: /* umode_item: BOT  */
#line 2719 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_BOT;
}
#line 6587 "conf_parser.c"
    break;

  case 595: /* umode_item: T_CCONN  */
#line 2722 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6595 "conf_parser.c"
    break;

  case 596: /* umode_item: T_DEAF  */
#line 2725 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6603 "conf_parser.c"
    break;

  case 597: /* umode_item: T_FLOOD  */
#line 2728 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FLOOD;
}
#line 6611 "conf_parser.c"
    break;

  case 598: /* umode_item: T_SKILL  */
#line 2731 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6619 "conf_parser.c"
    break;

  case 599: /* umode_item: HIDDEN  */
#line 2734 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6627 "conf_parser.c"
    break;

  case 600: /* umode_item: HIDE_CHANS  */
#line 2737 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDECHANS;
}
#line 6635 "conf_parser.c"
    break;

  case 601: /* umode_item: HIDE_IDLE  */
#line 2740 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDEIDLE;
}
#line 6643 "conf_parser.c"
    break;

  case 602: /* umode_item: T_NCHANGE  */
#line 2743 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6651 "conf_parser.c"
    break;

  case 603: /* umode_item: T_REJ  */
#line 2746 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6659 "conf_parser.c"
    break;

  case 604: /* umode_item: T_SPY  */
#line 2749 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6667 "conf_parser.c"
    break;

  case 605: /* umode_item: T_EXTERNAL  */
#line 2752 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6675 "conf_parser.c"
    break;

  case 606: /* umode_item: T_SERVNOTICE  */
#line 2755 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6683 "conf_parser.c"
    break;

  case 607: /* umode_item: T_INVISIBLE  */
#line 2758 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6691 "conf_parser.c"
    break;

  case 608: /* umode_item: T_WALLOP  */
#line 2761 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6699 "conf_parser.c"
    break;

  case 609: /* umode_item: T_SOFTCALLERID  */
#line 2764 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6707 "conf_parser.c"
    break;

  case 610: /* umode_item: T_CALLERID  */
#line 2767 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6715 "conf_parser.c"
    break;

  case 611: /* umode_item: T_LOCOPS  */
#line 2770 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6723 "conf_parser.c"
    break;

  case 612: /* umode_item: T_NONONREG  */
#line 2773 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6731 "conf_parser.c"
    break;

  case 613: /* umode_item: T_FARCONNECT  */
#line 2776 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6739 "conf_parser.c"
    break;

  case 614: /* umode_item: EXPIRATION  */
#line 2779 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6747 "conf_parser.c"
    break;

  case 615: /* umode_item: T_SECUREONLY  */
#line 2782 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SECUREONLY;
}
#line 6755 "conf_parser.c"
    break;

  case 616: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2787 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6763 "conf_parser.c"
    break;

  case 617: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2792 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6771 "conf_parser.c"
    break;

  case 618: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2797 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6779 "conf_parser.c"
    break;

  case 619: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2802 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6787 "conf_parser.c"
    break;

  case 620: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2807 "conf_parser.y"
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
#line 6807 "conf_parser.c"
    break;

  case 621: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2824 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6818 "conf_parser.c"
    break;

  case 622: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2832 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6829 "conf_parser.c"
    break;

  case 623: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2840 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6840 "conf_parser.c"
    break;

  case 624: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2848 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6853 "conf_parser.c"
    break;

  case 625: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2858 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6866 "conf_parser.c"
    break;

  case 647: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2893 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6874 "conf_parser.c"
    break;

  case 648: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2898 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6883 "conf_parser.c"
    break;

  case 649: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2904 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6892 "conf_parser.c"
    break;

  case 650: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2910 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6900 "conf_parser.c"
    break;

  case 651: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2915 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6908 "conf_parser.c"
    break;

  case 652: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2920 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6916 "conf_parser.c"
    break;

  case 653: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2925 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6924 "conf_parser.c"
    break;

  case 654: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2930 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6932 "conf_parser.c"
    break;

  case 655: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2935 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6940 "conf_parser.c"
    break;

  case 656: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2940 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6948 "conf_parser.c"
    break;

  case 657: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2945 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6956 "conf_parser.c"
    break;

  case 658: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2950 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6964 "conf_parser.c"
    break;

  case 659: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2955 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6972 "conf_parser.c"
    break;

  case 660: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2960 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6980 "conf_parser.c"
    break;

  case 661: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2965 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6988 "conf_parser.c"
    break;

  case 662: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2970 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6996 "conf_parser.c"
    break;

  case 663: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2975 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 7004 "conf_parser.c"
    break;

  case 677: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2998 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 7013 "conf_parser.c"
    break;

  case 678: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 3004 "conf_parser.y"
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
#line 7032 "conf_parser.c"
    break;

  case 679: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 3020 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 7044 "conf_parser.c"
    break;

  case 680: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 3029 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 7053 "conf_parser.c"
    break;

  case 681: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 3035 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 7062 "conf_parser.c"
    break;

  case 682: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 3041 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 7071 "conf_parser.c"
    break;

  case 683: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 3047 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 7083 "conf_parser.c"
    break;

  case 684: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 3056 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 7092 "conf_parser.c"
    break;

  case 685: /* serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'  */
#line 3062 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 7101 "conf_parser.c"
    break;


#line 7105 "conf_parser.c"

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

