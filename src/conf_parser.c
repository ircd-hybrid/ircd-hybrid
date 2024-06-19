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


#line 178 "conf_parser.c"

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
    MOTD = 369,                    /* MOTD  */
    NAME = 370,                    /* NAME  */
    NEED_IDENT = 371,              /* NEED_IDENT  */
    NEED_PASSWORD = 372,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 373,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 374,            /* NETWORK_NAME  */
    NICK = 375,                    /* NICK  */
    NO_OPER_FLOOD = 376,           /* NO_OPER_FLOOD  */
    NO_TILDE = 377,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 378,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 379,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 380,     /* NUMBER_PER_IP_LOCAL  */
    OPER_ONLY_UMODES = 381,        /* OPER_ONLY_UMODES  */
    OPER_UMODES = 382,             /* OPER_UMODES  */
    OPERATOR = 383,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 384,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 385,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 386,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 387,                /* PASSWORD  */
    PATH = 388,                    /* PATH  */
    PING_COOKIE = 389,             /* PING_COOKIE  */
    PING_TIME = 390,               /* PING_TIME  */
    PORT = 391,                    /* PORT  */
    RANDOM_IDLE = 392,             /* RANDOM_IDLE  */
    REASON = 393,                  /* REASON  */
    REDIRPORT = 394,               /* REDIRPORT  */
    REDIRSERV = 395,               /* REDIRSERV  */
    REHASH = 396,                  /* REHASH  */
    REMOTE = 397,                  /* REMOTE  */
    REMOTEBAN = 398,               /* REMOTEBAN  */
    RESIDENT = 399,                /* RESIDENT  */
    RESV = 400,                    /* RESV  */
    RESV_EXEMPT = 401,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 402,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 403,                 /* SECONDS  */
    MINUTES = 404,                 /* MINUTES  */
    HOURS = 405,                   /* HOURS  */
    DAYS = 406,                    /* DAYS  */
    WEEKS = 407,                   /* WEEKS  */
    MONTHS = 408,                  /* MONTHS  */
    YEARS = 409,                   /* YEARS  */
    SEND_PASSWORD = 410,           /* SEND_PASSWORD  */
    SENDQ = 411,                   /* SENDQ  */
    SERVERHIDE = 412,              /* SERVERHIDE  */
    SERVERINFO = 413,              /* SERVERINFO  */
    SHORT_MOTD = 414,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 415,       /* SPECIALS_IN_IDENT  */
    SPOOF = 416,                   /* SPOOF  */
    SQUIT = 417,                   /* SQUIT  */
    STATS_E_DISABLED = 418,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 419,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 420,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 421,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 422,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 423,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 424,       /* STATS_U_OPER_ONLY  */
    T_ALL = 425,                   /* T_ALL  */
    T_BIND = 426,                  /* T_BIND  */
    T_CALLERID = 427,              /* T_CALLERID  */
    T_CCONN = 428,                 /* T_CCONN  */
    T_COMMAND = 429,               /* T_COMMAND  */
    T_CLUSTER = 430,               /* T_CLUSTER  */
    T_DEAF = 431,                  /* T_DEAF  */
    T_DEBUG = 432,                 /* T_DEBUG  */
    T_DLINE = 433,                 /* T_DLINE  */
    T_EXTERNAL = 434,              /* T_EXTERNAL  */
    T_FARCONNECT = 435,            /* T_FARCONNECT  */
    T_FILE = 436,                  /* T_FILE  */
    T_FLOOD = 437,                 /* T_FLOOD  */
    T_GLOBOPS = 438,               /* T_GLOBOPS  */
    T_INVISIBLE = 439,             /* T_INVISIBLE  */
    T_IPV4 = 440,                  /* T_IPV4  */
    T_IPV6 = 441,                  /* T_IPV6  */
    T_LOCOPS = 442,                /* T_LOCOPS  */
    T_LOG = 443,                   /* T_LOG  */
    T_NCHANGE = 444,               /* T_NCHANGE  */
    T_NONONREG = 445,              /* T_NONONREG  */
    T_OPME = 446,                  /* T_OPME  */
    T_PREPEND = 447,               /* T_PREPEND  */
    T_PSEUDO = 448,                /* T_PSEUDO  */
    T_RECVQ = 449,                 /* T_RECVQ  */
    T_REJ = 450,                   /* T_REJ  */
    T_RESTART = 451,               /* T_RESTART  */
    T_SECUREONLY = 452,            /* T_SECUREONLY  */
    T_SERVER = 453,                /* T_SERVER  */
    T_SERVICE = 454,               /* T_SERVICE  */
    T_SERVNOTICE = 455,            /* T_SERVNOTICE  */
    T_SET = 456,                   /* T_SET  */
    T_SHARED = 457,                /* T_SHARED  */
    T_SIZE = 458,                  /* T_SIZE  */
    T_SKILL = 459,                 /* T_SKILL  */
    T_SOFTCALLERID = 460,          /* T_SOFTCALLERID  */
    T_SPY = 461,                   /* T_SPY  */
    T_TARGET = 462,                /* T_TARGET  */
    T_TLS = 463,                   /* T_TLS  */
    T_UMODES = 464,                /* T_UMODES  */
    T_UNDLINE = 465,               /* T_UNDLINE  */
    T_UNLIMITED = 466,             /* T_UNLIMITED  */
    T_UNRESV = 467,                /* T_UNRESV  */
    T_UNXLINE = 468,               /* T_UNXLINE  */
    T_WALLOP = 469,                /* T_WALLOP  */
    T_WALLOPS = 470,               /* T_WALLOPS  */
    T_WEBIRC = 471,                /* T_WEBIRC  */
    TBOOL = 472,                   /* TBOOL  */
    THROTTLE_COUNT = 473,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 474,           /* THROTTLE_TIME  */
    TIMEOUT = 475,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 476,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 477, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 478,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 479,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 480, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 481,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 482, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 483,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 484,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 485,           /* TS_WARN_DELTA  */
    TWODOTS = 486,                 /* TWODOTS  */
    TYPE = 487,                    /* TYPE  */
    UNKLINE = 488,                 /* UNKLINE  */
    USE_LOGGING = 489,             /* USE_LOGGING  */
    USER = 490,                    /* USER  */
    VHOST = 491,                   /* VHOST  */
    VHOST6 = 492,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 493,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 494,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 495,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 496,                   /* XLINE  */
    XLINE_EXEMPT = 497,            /* XLINE_EXEMPT  */
    QSTRING = 498,                 /* QSTRING  */
    NUMBER = 499                   /* NUMBER  */
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
#define MOTD 369
#define NAME 370
#define NEED_IDENT 371
#define NEED_PASSWORD 372
#define NETWORK_DESCRIPTION 373
#define NETWORK_NAME 374
#define NICK 375
#define NO_OPER_FLOOD 376
#define NO_TILDE 377
#define NUMBER_PER_CIDR 378
#define NUMBER_PER_IP_GLOBAL 379
#define NUMBER_PER_IP_LOCAL 380
#define OPER_ONLY_UMODES 381
#define OPER_UMODES 382
#define OPERATOR 383
#define OPERS_BYPASS_CALLERID 384
#define PACE_WAIT 385
#define PACE_WAIT_SIMPLE 386
#define PASSWORD 387
#define PATH 388
#define PING_COOKIE 389
#define PING_TIME 390
#define PORT 391
#define RANDOM_IDLE 392
#define REASON 393
#define REDIRPORT 394
#define REDIRSERV 395
#define REHASH 396
#define REMOTE 397
#define REMOTEBAN 398
#define RESIDENT 399
#define RESV 400
#define RESV_EXEMPT 401
#define RSA_PRIVATE_KEY_FILE 402
#define SECONDS 403
#define MINUTES 404
#define HOURS 405
#define DAYS 406
#define WEEKS 407
#define MONTHS 408
#define YEARS 409
#define SEND_PASSWORD 410
#define SENDQ 411
#define SERVERHIDE 412
#define SERVERINFO 413
#define SHORT_MOTD 414
#define SPECIALS_IN_IDENT 415
#define SPOOF 416
#define SQUIT 417
#define STATS_E_DISABLED 418
#define STATS_I_OPER_ONLY 419
#define STATS_K_OPER_ONLY 420
#define STATS_M_OPER_ONLY 421
#define STATS_O_OPER_ONLY 422
#define STATS_P_OPER_ONLY 423
#define STATS_U_OPER_ONLY 424
#define T_ALL 425
#define T_BIND 426
#define T_CALLERID 427
#define T_CCONN 428
#define T_COMMAND 429
#define T_CLUSTER 430
#define T_DEAF 431
#define T_DEBUG 432
#define T_DLINE 433
#define T_EXTERNAL 434
#define T_FARCONNECT 435
#define T_FILE 436
#define T_FLOOD 437
#define T_GLOBOPS 438
#define T_INVISIBLE 439
#define T_IPV4 440
#define T_IPV6 441
#define T_LOCOPS 442
#define T_LOG 443
#define T_NCHANGE 444
#define T_NONONREG 445
#define T_OPME 446
#define T_PREPEND 447
#define T_PSEUDO 448
#define T_RECVQ 449
#define T_REJ 450
#define T_RESTART 451
#define T_SECUREONLY 452
#define T_SERVER 453
#define T_SERVICE 454
#define T_SERVNOTICE 455
#define T_SET 456
#define T_SHARED 457
#define T_SIZE 458
#define T_SKILL 459
#define T_SOFTCALLERID 460
#define T_SPY 461
#define T_TARGET 462
#define T_TLS 463
#define T_UMODES 464
#define T_UNDLINE 465
#define T_UNLIMITED 466
#define T_UNRESV 467
#define T_UNXLINE 468
#define T_WALLOP 469
#define T_WALLOPS 470
#define T_WEBIRC 471
#define TBOOL 472
#define THROTTLE_COUNT 473
#define THROTTLE_TIME 474
#define TIMEOUT 475
#define TLS_CERTIFICATE_FILE 476
#define TLS_CERTIFICATE_FINGERPRINT 477
#define TLS_CIPHER_LIST 478
#define TLS_CIPHER_SUITES 479
#define TLS_CONNECTION_REQUIRED 480
#define TLS_DH_PARAM_FILE 481
#define TLS_MESSAGE_DIGEST_ALGORITHM 482
#define TLS_SUPPORTED_GROUPS 483
#define TS_MAX_DELTA 484
#define TS_WARN_DELTA 485
#define TWODOTS 486
#define TYPE 487
#define UNKLINE 488
#define USE_LOGGING 489
#define USER 490
#define VHOST 491
#define VHOST6 492
#define WARN_NO_CONNECT_BLOCK 493
#define WHOIS 494
#define WHOWAS_HISTORY_LENGTH 495
#define XLINE 496
#define XLINE_EXEMPT 497
#define QSTRING 498
#define NUMBER 499

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 134 "conf_parser.y"

  int number;
  char *string;

#line 724 "conf_parser.c"

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
  YYSYMBOL_MOTD = 114,                     /* MOTD  */
  YYSYMBOL_NAME = 115,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 116,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 117,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 118,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 119,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 120,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 121,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 122,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 123,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 124,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 125,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_ONLY_UMODES = 126,         /* OPER_ONLY_UMODES  */
  YYSYMBOL_OPER_UMODES = 127,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 128,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 129,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 130,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 131,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 132,                 /* PASSWORD  */
  YYSYMBOL_PATH = 133,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 134,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 135,                /* PING_TIME  */
  YYSYMBOL_PORT = 136,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 137,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 138,                   /* REASON  */
  YYSYMBOL_REDIRPORT = 139,                /* REDIRPORT  */
  YYSYMBOL_REDIRSERV = 140,                /* REDIRSERV  */
  YYSYMBOL_REHASH = 141,                   /* REHASH  */
  YYSYMBOL_REMOTE = 142,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 143,                /* REMOTEBAN  */
  YYSYMBOL_RESIDENT = 144,                 /* RESIDENT  */
  YYSYMBOL_RESV = 145,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 146,              /* RESV_EXEMPT  */
  YYSYMBOL_RSA_PRIVATE_KEY_FILE = 147,     /* RSA_PRIVATE_KEY_FILE  */
  YYSYMBOL_SECONDS = 148,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 149,                  /* MINUTES  */
  YYSYMBOL_HOURS = 150,                    /* HOURS  */
  YYSYMBOL_DAYS = 151,                     /* DAYS  */
  YYSYMBOL_WEEKS = 152,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 153,                   /* MONTHS  */
  YYSYMBOL_YEARS = 154,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 155,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 156,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 157,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 158,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 159,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 160,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 161,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 162,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 163,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_I_OPER_ONLY = 164,        /* STATS_I_OPER_ONLY  */
  YYSYMBOL_STATS_K_OPER_ONLY = 165,        /* STATS_K_OPER_ONLY  */
  YYSYMBOL_STATS_M_OPER_ONLY = 166,        /* STATS_M_OPER_ONLY  */
  YYSYMBOL_STATS_O_OPER_ONLY = 167,        /* STATS_O_OPER_ONLY  */
  YYSYMBOL_STATS_P_OPER_ONLY = 168,        /* STATS_P_OPER_ONLY  */
  YYSYMBOL_STATS_U_OPER_ONLY = 169,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 170,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 171,                   /* T_BIND  */
  YYSYMBOL_T_CALLERID = 172,               /* T_CALLERID  */
  YYSYMBOL_T_CCONN = 173,                  /* T_CCONN  */
  YYSYMBOL_T_COMMAND = 174,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 175,                /* T_CLUSTER  */
  YYSYMBOL_T_DEAF = 176,                   /* T_DEAF  */
  YYSYMBOL_T_DEBUG = 177,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 178,                  /* T_DLINE  */
  YYSYMBOL_T_EXTERNAL = 179,               /* T_EXTERNAL  */
  YYSYMBOL_T_FARCONNECT = 180,             /* T_FARCONNECT  */
  YYSYMBOL_T_FILE = 181,                   /* T_FILE  */
  YYSYMBOL_T_FLOOD = 182,                  /* T_FLOOD  */
  YYSYMBOL_T_GLOBOPS = 183,                /* T_GLOBOPS  */
  YYSYMBOL_T_INVISIBLE = 184,              /* T_INVISIBLE  */
  YYSYMBOL_T_IPV4 = 185,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 186,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 187,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 188,                    /* T_LOG  */
  YYSYMBOL_T_NCHANGE = 189,                /* T_NCHANGE  */
  YYSYMBOL_T_NONONREG = 190,               /* T_NONONREG  */
  YYSYMBOL_T_OPME = 191,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 192,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 193,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 194,                  /* T_RECVQ  */
  YYSYMBOL_T_REJ = 195,                    /* T_REJ  */
  YYSYMBOL_T_RESTART = 196,                /* T_RESTART  */
  YYSYMBOL_T_SECUREONLY = 197,             /* T_SECUREONLY  */
  YYSYMBOL_T_SERVER = 198,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 199,                /* T_SERVICE  */
  YYSYMBOL_T_SERVNOTICE = 200,             /* T_SERVNOTICE  */
  YYSYMBOL_T_SET = 201,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 202,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 203,                   /* T_SIZE  */
  YYSYMBOL_T_SKILL = 204,                  /* T_SKILL  */
  YYSYMBOL_T_SOFTCALLERID = 205,           /* T_SOFTCALLERID  */
  YYSYMBOL_T_SPY = 206,                    /* T_SPY  */
  YYSYMBOL_T_TARGET = 207,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 208,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 209,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 210,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 211,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 212,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 213,                /* T_UNXLINE  */
  YYSYMBOL_T_WALLOP = 214,                 /* T_WALLOP  */
  YYSYMBOL_T_WALLOPS = 215,                /* T_WALLOPS  */
  YYSYMBOL_T_WEBIRC = 216,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 217,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 218,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 219,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 220,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 221,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 222, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 223,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 224,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 225,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 226,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 227, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 228,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 229,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 230,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 231,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 232,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 233,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 234,              /* USE_LOGGING  */
  YYSYMBOL_USER = 235,                     /* USER  */
  YYSYMBOL_VHOST = 236,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 237,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 238,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 239,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 240,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 241,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 242,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 243,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 244,                   /* NUMBER  */
  YYSYMBOL_245_ = 245,                     /* ';'  */
  YYSYMBOL_246_ = 246,                     /* '}'  */
  YYSYMBOL_247_ = 247,                     /* ':'  */
  YYSYMBOL_248_ = 248,                     /* ','  */
  YYSYMBOL_249_ = 249,                     /* '{'  */
  YYSYMBOL_250_ = 250,                     /* '='  */
  YYSYMBOL_YYACCEPT = 251,                 /* $accept  */
  YYSYMBOL_conf = 252,                     /* conf  */
  YYSYMBOL_conf_item = 253,                /* conf_item  */
  YYSYMBOL_timespec_ = 254,                /* timespec_  */
  YYSYMBOL_timespec = 255,                 /* timespec  */
  YYSYMBOL_sizespec_ = 256,                /* sizespec_  */
  YYSYMBOL_sizespec = 257,                 /* sizespec  */
  YYSYMBOL_loadmodule_entry = 258,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 259,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 260,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 261,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 262,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 263,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 264,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 265, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 266, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 267, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 268, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 269, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 270, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 271, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 272,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 273,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 274,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 275,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 276, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 277, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 278, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 279, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_hub = 280,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 281,              /* admin_entry  */
  YYSYMBOL_admin_items = 282,              /* admin_items  */
  YYSYMBOL_admin_item = 283,               /* admin_item  */
  YYSYMBOL_admin_name = 284,               /* admin_name  */
  YYSYMBOL_admin_email = 285,              /* admin_email  */
  YYSYMBOL_admin_description = 286,        /* admin_description  */
  YYSYMBOL_motd_entry = 287,               /* motd_entry  */
  YYSYMBOL_288_1 = 288,                    /* $@1  */
  YYSYMBOL_motd_items = 289,               /* motd_items  */
  YYSYMBOL_motd_item = 290,                /* motd_item  */
  YYSYMBOL_motd_mask = 291,                /* motd_mask  */
  YYSYMBOL_motd_file = 292,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 293,             /* pseudo_entry  */
  YYSYMBOL_294_2 = 294,                    /* $@2  */
  YYSYMBOL_pseudo_items = 295,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 296,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 297,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 298,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 299,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 300,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 301,            /* logging_entry  */
  YYSYMBOL_logging_items = 302,            /* logging_items  */
  YYSYMBOL_logging_item = 303,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 304,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 305,       /* logging_file_entry  */
  YYSYMBOL_306_3 = 306,                    /* $@3  */
  YYSYMBOL_logging_file_items = 307,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 308,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 309,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 310,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 311,        /* logging_file_type  */
  YYSYMBOL_312_4 = 312,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 313,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 314,               /* oper_entry  */
  YYSYMBOL_315_5 = 315,                    /* $@5  */
  YYSYMBOL_oper_items = 316,               /* oper_items  */
  YYSYMBOL_oper_item = 317,                /* oper_item  */
  YYSYMBOL_oper_name = 318,                /* oper_name  */
  YYSYMBOL_oper_user = 319,                /* oper_user  */
  YYSYMBOL_oper_password = 320,            /* oper_password  */
  YYSYMBOL_oper_whois = 321,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 322,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 323, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 324, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 325,               /* oper_class  */
  YYSYMBOL_oper_umodes = 326,              /* oper_umodes  */
  YYSYMBOL_327_6 = 327,                    /* $@6  */
  YYSYMBOL_oper_umodes_items = 328,        /* oper_umodes_items  */
  YYSYMBOL_oper_umodes_item = 329,         /* oper_umodes_item  */
  YYSYMBOL_oper_flags = 330,               /* oper_flags  */
  YYSYMBOL_331_7 = 331,                    /* $@7  */
  YYSYMBOL_oper_flags_items = 332,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 333,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 334,              /* class_entry  */
  YYSYMBOL_335_8 = 335,                    /* $@8  */
  YYSYMBOL_class_items = 336,              /* class_items  */
  YYSYMBOL_class_item = 337,               /* class_item  */
  YYSYMBOL_class_name = 338,               /* class_name  */
  YYSYMBOL_class_ping_time = 339,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 340, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 341, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 342,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 343,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 344,         /* class_max_number  */
  YYSYMBOL_class_sendq = 345,              /* class_sendq  */
  YYSYMBOL_class_recvq = 346,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 347,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 348,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 349,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 350,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 351,           /* class_max_idle  */
  YYSYMBOL_class_flags = 352,              /* class_flags  */
  YYSYMBOL_353_9 = 353,                    /* $@9  */
  YYSYMBOL_class_flags_items = 354,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 355,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 356,             /* listen_entry  */
  YYSYMBOL_357_10 = 357,                   /* $@10  */
  YYSYMBOL_listen_flags = 358,             /* listen_flags  */
  YYSYMBOL_359_11 = 359,                   /* $@11  */
  YYSYMBOL_listen_flags_items = 360,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 361,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 362,             /* listen_items  */
  YYSYMBOL_listen_item = 363,              /* listen_item  */
  YYSYMBOL_listen_port = 364,              /* listen_port  */
  YYSYMBOL_365_12 = 365,                   /* $@12  */
  YYSYMBOL_port_items = 366,               /* port_items  */
  YYSYMBOL_port_item = 367,                /* port_item  */
  YYSYMBOL_listen_address = 368,           /* listen_address  */
  YYSYMBOL_listen_host = 369,              /* listen_host  */
  YYSYMBOL_auth_entry = 370,               /* auth_entry  */
  YYSYMBOL_371_13 = 371,                   /* $@13  */
  YYSYMBOL_auth_items = 372,               /* auth_items  */
  YYSYMBOL_auth_item = 373,                /* auth_item  */
  YYSYMBOL_auth_user = 374,                /* auth_user  */
  YYSYMBOL_auth_passwd = 375,              /* auth_passwd  */
  YYSYMBOL_auth_class = 376,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 377,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 378,               /* auth_flags  */
  YYSYMBOL_379_14 = 379,                   /* $@14  */
  YYSYMBOL_auth_flags_items = 380,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 381,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 382,               /* auth_spoof  */
  YYSYMBOL_auth_redir_serv = 383,          /* auth_redir_serv  */
  YYSYMBOL_auth_redir_port = 384,          /* auth_redir_port  */
  YYSYMBOL_resv_entry = 385,               /* resv_entry  */
  YYSYMBOL_386_15 = 386,                   /* $@15  */
  YYSYMBOL_resv_items = 387,               /* resv_items  */
  YYSYMBOL_resv_item = 388,                /* resv_item  */
  YYSYMBOL_resv_mask = 389,                /* resv_mask  */
  YYSYMBOL_resv_reason = 390,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 391,              /* resv_exempt  */
  YYSYMBOL_service_entry = 392,            /* service_entry  */
  YYSYMBOL_service_items = 393,            /* service_items  */
  YYSYMBOL_service_item = 394,             /* service_item  */
  YYSYMBOL_service_name = 395,             /* service_name  */
  YYSYMBOL_shared_entry = 396,             /* shared_entry  */
  YYSYMBOL_397_16 = 397,                   /* $@16  */
  YYSYMBOL_shared_items = 398,             /* shared_items  */
  YYSYMBOL_shared_item = 399,              /* shared_item  */
  YYSYMBOL_shared_name = 400,              /* shared_name  */
  YYSYMBOL_shared_user = 401,              /* shared_user  */
  YYSYMBOL_shared_type = 402,              /* shared_type  */
  YYSYMBOL_403_17 = 403,                   /* $@17  */
  YYSYMBOL_shared_types = 404,             /* shared_types  */
  YYSYMBOL_shared_type_item = 405,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 406,            /* cluster_entry  */
  YYSYMBOL_407_18 = 407,                   /* $@18  */
  YYSYMBOL_cluster_items = 408,            /* cluster_items  */
  YYSYMBOL_cluster_item = 409,             /* cluster_item  */
  YYSYMBOL_cluster_name = 410,             /* cluster_name  */
  YYSYMBOL_cluster_type = 411,             /* cluster_type  */
  YYSYMBOL_412_19 = 412,                   /* $@19  */
  YYSYMBOL_cluster_types = 413,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 414,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 415,            /* connect_entry  */
  YYSYMBOL_416_20 = 416,                   /* $@20  */
  YYSYMBOL_connect_items = 417,            /* connect_items  */
  YYSYMBOL_connect_item = 418,             /* connect_item  */
  YYSYMBOL_connect_name = 419,             /* connect_name  */
  YYSYMBOL_connect_host = 420,             /* connect_host  */
  YYSYMBOL_connect_timeout = 421,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 422,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 423,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 424,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 425, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 426,             /* connect_port  */
  YYSYMBOL_connect_aftype = 427,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 428,            /* connect_flags  */
  YYSYMBOL_429_21 = 429,                   /* $@21  */
  YYSYMBOL_connect_flags_items = 430,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 431,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 432,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 433,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 434,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 435,            /* connect_class  */
  YYSYMBOL_connect_tls_cipher_list = 436,  /* connect_tls_cipher_list  */
  YYSYMBOL_kill_entry = 437,               /* kill_entry  */
  YYSYMBOL_438_22 = 438,                   /* $@22  */
  YYSYMBOL_kill_items = 439,               /* kill_items  */
  YYSYMBOL_kill_item = 440,                /* kill_item  */
  YYSYMBOL_kill_user = 441,                /* kill_user  */
  YYSYMBOL_kill_reason = 442,              /* kill_reason  */
  YYSYMBOL_deny_entry = 443,               /* deny_entry  */
  YYSYMBOL_444_23 = 444,                   /* $@23  */
  YYSYMBOL_deny_items = 445,               /* deny_items  */
  YYSYMBOL_deny_item = 446,                /* deny_item  */
  YYSYMBOL_deny_ip = 447,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 448,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 449,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 450,             /* exempt_items  */
  YYSYMBOL_exempt_item = 451,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 452,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 453,              /* gecos_entry  */
  YYSYMBOL_454_24 = 454,                   /* $@24  */
  YYSYMBOL_gecos_items = 455,              /* gecos_items  */
  YYSYMBOL_gecos_item = 456,               /* gecos_item  */
  YYSYMBOL_gecos_name = 457,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 458,             /* gecos_reason  */
  YYSYMBOL_general_entry = 459,            /* general_entry  */
  YYSYMBOL_general_items = 460,            /* general_items  */
  YYSYMBOL_general_item = 461,             /* general_item  */
  YYSYMBOL_general_away_count = 462,       /* general_away_count  */
  YYSYMBOL_general_away_time = 463,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 464,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 465, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 466, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 467,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 468,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 469,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 470,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 471, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 472, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 473,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 474,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 475, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 476,       /* general_max_accept  */
  YYSYMBOL_general_anti_spam_exit_message_time = 477, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 478,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 479,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 480, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 481, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 482, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 483, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 484, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 485, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 486, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 487, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 488, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 489,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 490,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 491, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 492, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 493,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 494,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 495, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 496,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 497,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_auth = 498,     /* general_disable_auth  */
  YYSYMBOL_general_throttle_count = 499,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 500,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 501,      /* general_oper_umodes  */
  YYSYMBOL_502_25 = 502,                   /* $@25  */
  YYSYMBOL_umode_oitems = 503,             /* umode_oitems  */
  YYSYMBOL_umode_oitem = 504,              /* umode_oitem  */
  YYSYMBOL_general_oper_only_umodes = 505, /* general_oper_only_umodes  */
  YYSYMBOL_506_26 = 506,                   /* $@26  */
  YYSYMBOL_umode_items = 507,              /* umode_items  */
  YYSYMBOL_umode_item = 508,               /* umode_item  */
  YYSYMBOL_general_min_nonwildcard = 509,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 510, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 511, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 512, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 513,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 514, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 515, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 516,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 517,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 518,     /* general_cloak_suffix  */
  YYSYMBOL_channel_entry = 519,            /* channel_entry  */
  YYSYMBOL_channel_items = 520,            /* channel_items  */
  YYSYMBOL_channel_item = 521,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 522,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 523,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 524,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 525, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 526, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 527, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 528, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 529, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 530, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 531, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 532, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 533,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 534,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 535,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 536,   /* channel_max_bans_large  */
  YYSYMBOL_channel_default_join_flood_count = 537, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 538, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 539,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 540,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 541,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 542, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 543, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 544, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 545, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 546,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 547, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 548,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 549,        /* serverhide_hidden  */
  YYSYMBOL_serverhide_hide_server_ips = 550 /* serverhide_hide_server_ips  */
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
#define YYLAST   1273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  251
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  300
/* YYNRULES -- Number of rules.  */
#define YYNRULES  681
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1345

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   499


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
       2,     2,     2,     2,   248,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   247,   245,
       2,   250,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   249,     2,   246,     2,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   380,   380,   381,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   411,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   422,   422,
     423,   424,   425,   426,   433,   440,   442,   444,   444,   446,
     450,   460,   462,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   482,   491,   500,   509,   518,   527,   536,   545,   560,
     575,   585,   599,   608,   631,   654,   677,   687,   689,   689,
     690,   691,   692,   693,   695,   704,   713,   727,   726,   744,
     744,   745,   745,   745,   747,   753,   764,   763,   782,   782,
     783,   783,   783,   783,   783,   785,   791,   797,   803,   826,
     827,   827,   829,   829,   830,   832,   839,   839,   852,   853,
     855,   855,   856,   856,   858,   866,   869,   875,   874,   880,
     884,   888,   892,   896,   900,   904,   908,   919,   918,   982,
     982,   983,   984,   985,   986,   987,   988,   989,   990,   991,
     992,   993,   995,  1001,  1007,  1013,  1019,  1030,  1036,  1047,
    1054,  1053,  1059,  1059,  1060,  1064,  1068,  1072,  1076,  1080,
    1084,  1088,  1092,  1096,  1100,  1104,  1108,  1112,  1116,  1120,
    1124,  1128,  1132,  1136,  1140,  1144,  1151,  1150,  1156,  1156,
    1157,  1161,  1165,  1169,  1173,  1177,  1181,  1185,  1189,  1193,
    1197,  1201,  1205,  1209,  1213,  1217,  1221,  1225,  1229,  1233,
    1237,  1241,  1245,  1249,  1253,  1257,  1261,  1265,  1269,  1273,
    1284,  1283,  1339,  1339,  1340,  1341,  1342,  1343,  1344,  1345,
    1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,
    1357,  1363,  1369,  1375,  1381,  1387,  1393,  1399,  1405,  1412,
    1418,  1424,  1430,  1439,  1449,  1448,  1454,  1454,  1455,  1459,
    1470,  1469,  1476,  1475,  1480,  1480,  1481,  1485,  1489,  1493,
    1497,  1503,  1503,  1504,  1504,  1504,  1504,  1504,  1506,  1506,
    1508,  1508,  1510,  1523,  1540,  1546,  1557,  1556,  1604,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1615,
    1621,  1627,  1633,  1645,  1644,  1650,  1650,  1651,  1655,  1659,
    1663,  1667,  1671,  1675,  1679,  1683,  1689,  1703,  1712,  1726,
    1725,  1740,  1740,  1741,  1741,  1741,  1741,  1743,  1749,  1755,
    1765,  1767,  1767,  1768,  1768,  1770,  1787,  1786,  1809,  1809,
    1810,  1810,  1810,  1810,  1812,  1818,  1838,  1837,  1843,  1843,
    1844,  1848,  1852,  1856,  1860,  1864,  1868,  1872,  1876,  1880,
    1891,  1890,  1909,  1909,  1910,  1910,  1910,  1912,  1919,  1918,
    1924,  1924,  1925,  1929,  1933,  1937,  1941,  1945,  1949,  1953,
    1957,  1961,  1972,  1971,  2049,  2049,  2050,  2051,  2052,  2053,
    2054,  2055,  2056,  2057,  2058,  2059,  2060,  2061,  2062,  2063,
    2064,  2065,  2067,  2073,  2079,  2085,  2091,  2104,  2117,  2123,
    2129,  2133,  2140,  2139,  2144,  2144,  2145,  2149,  2155,  2166,
    2172,  2178,  2184,  2200,  2199,  2223,  2223,  2224,  2224,  2224,
    2226,  2246,  2257,  2256,  2281,  2281,  2282,  2282,  2282,  2284,
    2290,  2300,  2302,  2302,  2303,  2303,  2305,  2323,  2322,  2343,
    2343,  2344,  2344,  2344,  2346,  2352,  2362,  2364,  2364,  2365,
    2366,  2367,  2368,  2369,  2370,  2371,  2372,  2373,  2374,  2375,
    2376,  2377,  2378,  2379,  2380,  2381,  2382,  2383,  2384,  2385,
    2386,  2387,  2388,  2389,  2390,  2391,  2392,  2393,  2394,  2395,
    2396,  2397,  2398,  2399,  2400,  2401,  2402,  2403,  2404,  2405,
    2406,  2407,  2408,  2409,  2410,  2411,  2412,  2413,  2414,  2415,
    2416,  2419,  2424,  2429,  2434,  2439,  2444,  2449,  2454,  2459,
    2464,  2469,  2474,  2479,  2484,  2489,  2494,  2499,  2504,  2509,
    2514,  2519,  2524,  2529,  2534,  2539,  2544,  2549,  2554,  2559,
    2564,  2569,  2574,  2579,  2584,  2589,  2594,  2599,  2604,  2609,
    2615,  2614,  2619,  2619,  2620,  2623,  2626,  2629,  2632,  2635,
    2638,  2641,  2644,  2647,  2650,  2653,  2656,  2659,  2662,  2665,
    2668,  2671,  2674,  2677,  2680,  2683,  2689,  2688,  2693,  2693,
    2694,  2697,  2700,  2703,  2706,  2709,  2712,  2715,  2718,  2721,
    2724,  2727,  2730,  2733,  2736,  2739,  2742,  2745,  2748,  2751,
    2754,  2757,  2762,  2767,  2772,  2777,  2782,  2799,  2807,  2815,
    2823,  2833,  2846,  2848,  2848,  2849,  2850,  2851,  2852,  2853,
    2854,  2855,  2856,  2857,  2858,  2859,  2860,  2861,  2862,  2863,
    2864,  2865,  2866,  2868,  2873,  2879,  2885,  2890,  2895,  2900,
    2905,  2910,  2915,  2920,  2925,  2930,  2935,  2940,  2945,  2950,
    2959,  2961,  2961,  2962,  2963,  2964,  2965,  2966,  2967,  2968,
    2969,  2970,  2971,  2973,  2979,  2995,  3004,  3010,  3016,  3022,
    3031,  3037
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
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE", "MOTD", "NAME",
  "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESCRIPTION", "NETWORK_NAME",
  "NICK", "NO_OPER_FLOOD", "NO_TILDE", "NUMBER_PER_CIDR",
  "NUMBER_PER_IP_GLOBAL", "NUMBER_PER_IP_LOCAL", "OPER_ONLY_UMODES",
  "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID", "PACE_WAIT",
  "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME",
  "PORT", "RANDOM_IDLE", "REASON", "REDIRPORT", "REDIRSERV", "REHASH",
  "REMOTE", "REMOTEBAN", "RESIDENT", "RESV", "RESV_EXEMPT",
  "RSA_PRIVATE_KEY_FILE", "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS",
  "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ", "SERVERHIDE", "SERVERINFO",
  "SHORT_MOTD", "SPECIALS_IN_IDENT", "SPOOF", "SQUIT", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_M_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL",
  "T_BIND", "T_CALLERID", "T_CCONN", "T_COMMAND", "T_CLUSTER", "T_DEAF",
  "T_DEBUG", "T_DLINE", "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FLOOD",
  "T_GLOBOPS", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG",
  "T_NCHANGE", "T_NONONREG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ",
  "T_REJ", "T_RESTART", "T_SECUREONLY", "T_SERVER", "T_SERVICE",
  "T_SERVNOTICE", "T_SET", "T_SHARED", "T_SIZE", "T_SKILL",
  "T_SOFTCALLERID", "T_SPY", "T_TARGET", "T_TLS", "T_UMODES", "T_UNDLINE",
  "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_WALLOP", "T_WALLOPS",
  "T_WEBIRC", "TBOOL", "THROTTLE_COUNT", "THROTTLE_TIME", "TIMEOUT",
  "TLS_CERTIFICATE_FILE", "TLS_CERTIFICATE_FINGERPRINT", "TLS_CIPHER_LIST",
  "TLS_CIPHER_SUITES", "TLS_CONNECTION_REQUIRED", "TLS_DH_PARAM_FILE",
  "TLS_MESSAGE_DIGEST_ALGORITHM", "TLS_SUPPORTED_GROUPS", "TS_MAX_DELTA",
  "TS_WARN_DELTA", "TWODOTS", "TYPE", "UNKLINE", "USE_LOGGING", "USER",
  "VHOST", "VHOST6", "WARN_NO_CONNECT_BLOCK", "WHOIS",
  "WHOWAS_HISTORY_LENGTH", "XLINE", "XLINE_EXEMPT", "QSTRING", "NUMBER",
  "';'", "'}'", "':'", "','", "'{'", "'='", "$accept", "conf", "conf_item",
  "timespec_", "timespec", "sizespec_", "sizespec", "loadmodule_entry",
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

#define YYPACT_NINF (-1075)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-127)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1075,   878, -1075,  -200,  -233,  -231, -1075, -1075, -1075,  -229,
   -1075,  -214, -1075, -1075, -1075,  -186, -1075, -1075, -1075,  -202,
    -172, -1075,  -157, -1075,  -149, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075,   299,   914,  -138,  -134,  -132,    10,  -114,   425,   -83,
     -78,   -42,   -38,   -34,   -32,   -17,   976,   534,     5,    25,
      46,    55,    52,     8,   -22,    36,    42,    18, -1075, -1075,
   -1075, -1075, -1075,    69,    74,    76,    84,    85,    87,    97,
      98,    99,   100,   104,   107,   108,   109,   114,   115,   116,
     124, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,   718,
     544,    26, -1075,   122,    20, -1075, -1075,   215, -1075,   127,
     128,   129,   131,   132,   133,   134,   135,   137,   142,   143,
     155,   158,   159,   160,   163,   165,   166,   168,   169,   175,
     177,   179,   180,   183,   186,   192,   193,   194,   204, -1075,
   -1075,   205,   206,   210,   211,   212,   216,   218,   219,   222,
     223,   228,   240,   244,   245,   248,   250,   251,   253,   254,
      27, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,    23,    43,   317,   -25,    66,   125,   309,
     187, -1075,   255,   257,   259,   260,   263,   264,   265,   269,
     270,    22, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075,    75,   272,   273,   274,   275,   276,   288,   289,
     290,   291,   292,   293,   300,   303,   307,   308,   310,    61,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075,    62,   130,   311,
      29, -1075, -1075, -1075,   256,   188, -1075,   312,    31, -1075,
   -1075,    70, -1075,   236,   320,   322,   220, -1075,    68,   123,
     157,   282,   316,   349,   323,   123,   123,   123,   324,   123,
     123,   329,   331,   333,   334,   335, -1075,   336,   332,   337,
     346, -1075,   348,   350,   355,   356,   357,   359,   361,   362,
     366,   368,   369,   217, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
     338,   370,   371,   372,   374,   375,   376, -1075,   377,   378,
     380,   382,   384,   386,   387,   389,   200, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075,   390,   391,     4, -1075, -1075, -1075,
     343,   354, -1075, -1075,   395,   396,    30, -1075, -1075, -1075,
     393,   123,   403,   123,   123,   431,   407,   412,   413,   415,
     419,   447,   424,   123,   455,   429,   430,   459,   460,   123,
     434,   438,   439,   441,   442,   123,   443,   444,   446,   474,
     445,   452,   475,   123,   123,   476,   477,   461,   479,   489,
     490,   491,   492,   493,   495,   472,   123,   123,   123,   500,
     478,   473, -1075,   480,   470,   481, -1075,   482,   483,   484,
     485,   494,   229, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,   496,   501,    37, -1075, -1075, -1075,   497,
     502,   503, -1075,   504, -1075,    16, -1075, -1075, -1075, -1075,
   -1075, -1075,   508, -1075, -1075,   498,   509,   513,   117, -1075,
   -1075, -1075,   520,   518,   519, -1075,   521,   522, -1075,   523,
     524,   525,   526,   182, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075,   535,   531,   533,   537,     2,
   -1075, -1075, -1075, -1075,   506,   507,   123,   487,   510,   527,
     511,   528,   567,   546, -1075, -1075,   545,   549,   577,   555,
     556,   558,   561,   562,   564,   565,   566,   570,   571,   572,
     576,   578,   554, -1075,   580,   581, -1075,    67, -1075, -1075,
   -1075, -1075,   610,   590, -1075,   330,   591,   594,   596,   598,
     599,    63, -1075, -1075, -1075, -1075, -1075,   608,   607, -1075,
     612,   611, -1075,   617,     6, -1075, -1075, -1075, -1075,   615,
     624,   627, -1075,   639,   249,   640,   642,   643,   644,   648,
     649,   651,   652,   654,   656,   659,   663,   664,   666,   668,
     669, -1075, -1075,   672,   674,   123,   670,   677,   123,   678,
     123,   680,   681,   683,   684,   123,   685,   685,   679, -1075,
   -1075,   687,  -110,   689,   716,   692,   696,   690,   698,   700,
     702,   704,   705,   123,   708,   709,   691, -1075,   710,   711,
     713, -1075,   714, -1075,   712,   723,   722, -1075,   724,   727,
     729,   730,   731,   733,   734,   735,   736,   737,   738,   739,
     740,   741,   746,   748,   749,   750,   751,   752,   753,   754,
     755,   756,   760,   762,   763,   764,   765,   769,   606,   650,
     771,   772,   773,   774,   776,   777,   779,   780,   781,   782,
     783,   784,   785,   786,   794,   795,   796,   800,   801, -1075,
   -1075,   725,   744,   797,   805,   806,   808,   809,   811,   804,
   -1075,   812,   813,   814, -1075, -1075,   815,   817,   807,   818,
     816, -1075,   -25, -1075,   820,   821,   822, -1075, -1075,   825,
     848,   819,   827,   829,   823,   831,   858,   833,   835,   834,
   -1075, -1075,   838,   839,   840,   841, -1075,   842,   843,   844,
     845,   846,   847,   849,   850,   851, -1075,   852,   853,   854,
     855,   856,   857,   859,   860,   861,   862,   863,   864,   865,
     866,   867,   868, -1075, -1075,   871,   869,   870, -1075,   872,
   -1075,   119, -1075,   873,   875,   877,   879,   876, -1075,   880,
   -1075, -1075,   881,   882,   883,   884, -1075, -1075, -1075, -1075,
   -1075,   123,   123,   123,   123,   123,   123,   123, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075,   885,   886,   888,   -51,
     889,   890,   891,   892,   893,   894,   895,   896,   897,   230,
     898,   899, -1075,   900,   901,   902,   903,   904,   905,   906,
      -4,   907,   908,   909,   910,   911,   912,   913,   915, -1075,
     916,   917, -1075, -1075,   918,   919, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,  -223,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,  -178, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075,   920,   921,   360,   922,   923,   924,
     925,   926, -1075,   927,   928, -1075,   929,   930,   283,   945,
     836, -1075, -1075, -1075,   932,   933, -1075,   934,   935,   488,
     936,   937,   686,   938,   939,   940,   941, -1075,   942,   943,
     944, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075,   946,   693, -1075,
   -1075,   947,   948,   949, -1075,    28, -1075, -1075, -1075, -1075,
     950,   951,   952,   955, -1075, -1075,   956,   732,   957, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075,  -154, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,   685,   685,   685, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,  -140,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075,   606, -1075,   650, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,  -136, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075,  -121, -1075,   959,   818,   960, -1075,
   -1075, -1075, -1075, -1075, -1075,   961, -1075,   962,   963, -1075,
     964, -1075,   965,   966, -1075, -1075,   967, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,  -101,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075,   -21, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075,   -19, -1075, -1075,   972,  -196,
     954,   971, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,    45, -1075,
   -1075, -1075,   -51, -1075, -1075, -1075, -1075,    -4, -1075, -1075,
   -1075,   360, -1075,   283, -1075, -1075, -1075,   584,   593,   597,
     646,   958,   981,   985, -1075,   488, -1075,   686, -1075,   693,
     973,   974,   975,   261, -1075, -1075,   732, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075,   977, -1075, -1075
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   230,   392,   442,     0,
     457,     0,   296,   433,   270,     0,    97,   147,   329,     0,
       0,   370,     0,   106,     0,   346,     3,     4,    12,     5,
      24,    25,     6,     7,     9,    10,    11,    14,    15,    16,
      17,    18,    19,    20,    21,    23,    22,     8,    13,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      92,    91,   642,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   624,   639,   640,   641,   638,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   625,   626,   636,   637,     0,
       0,     0,   455,     0,     0,   453,   454,     0,   520,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     560,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   468,   469,   470,   512,   476,   513,   507,   508,   509,
     510,   480,   471,   472,   473,   474,   475,   477,   478,   479,
     481,   482,   511,   486,   487,   488,   489,   485,   484,   490,
     497,   498,   491,   492,   493,   483,   495,   505,   506,   503,
     504,   496,   494,   501,   502,   499,   500,   514,   515,   516,
     517,   518,   519,     0,     0,     0,     0,     0,     0,     0,
       0,   672,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   662,   663,   664,   665,   666,   667,   668,   670,
     669,   671,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    66,    64,    62,    67,    68,    69,    63,    54,    65,
      56,    57,    58,    59,    60,    61,    55,     0,     0,     0,
       0,   121,   122,   123,     0,     0,   344,     0,     0,   342,
     343,     0,    93,     0,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   623,     0,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,   234,   237,   239,   240,   241,
     242,   243,   244,   245,   235,   236,   238,   246,   247,   248,
       0,     0,     0,     0,     0,     0,     0,   422,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   395,   396,   397,
     398,   399,   400,   401,   402,   404,   403,   406,   410,   407,
     408,   409,   405,   448,     0,     0,     0,   445,   446,   447,
       0,     0,   452,   463,     0,     0,     0,   460,   461,   462,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   467,     0,     0,     0,   313,     0,     0,     0,
       0,     0,     0,   299,   300,   301,   302,   307,   303,   304,
     305,   306,   439,     0,     0,     0,   436,   437,   438,     0,
       0,     0,   272,     0,   284,     0,   282,   283,   285,   286,
      50,    49,    46,    48,    44,     0,     0,     0,     0,   100,
     101,   102,     0,     0,     0,   196,     0,     0,   170,     0,
       0,     0,     0,     0,   150,   151,   152,   153,   154,   157,
     158,   159,   156,   155,   160,     0,     0,     0,     0,     0,
     332,   333,   334,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   661,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,   378,     0,   373,   374,
     375,   124,     0,     0,   120,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   112,   111,   113,     0,     0,   341,
       0,     0,   356,     0,     0,   349,   350,   351,   352,     0,
       0,     0,    87,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   622,   249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     411,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   394,     0,     0,
       0,   444,     0,   451,     0,     0,     0,   459,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   466,
     308,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     298,     0,     0,     0,   435,   287,     0,     0,     0,     0,
       0,   281,     0,   103,     0,     0,     0,    99,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     149,   336,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   660,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,   376,     0,     0,     0,   372,     0,
     119,     0,   114,     0,     0,     0,     0,     0,   108,     0,
     340,   353,     0,     0,     0,     0,   348,    96,    95,    94,
     658,    28,    28,    28,    28,    28,    28,    28,    30,    29,
     659,   646,   645,   643,   644,   647,   648,   649,   650,   651,
     652,   653,   656,   657,   654,   655,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,   231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   393,
       0,     0,   443,   456,     0,     0,   458,   532,   536,   521,
     522,   549,   616,   617,   618,   619,   620,   621,   525,   614,
     615,   557,   526,   527,   531,   539,   530,   528,   529,   535,
     523,   534,   533,   555,   612,   613,   553,   590,   610,   595,
     596,   597,   606,   591,   592,   601,   609,   593,   603,   607,
     598,   608,   599,   611,   602,   594,   605,   600,   604,     0,
     589,   564,   584,   568,   569,   570,   580,   565,   566,   575,
     583,   567,   577,   581,   572,   582,   573,   585,   576,   571,
     579,   574,   578,     0,   563,   550,   548,   551,   556,   552,
     554,   541,   547,   546,   542,   543,   544,   545,   558,   559,
     538,   537,   540,   524,     0,     0,     0,     0,     0,     0,
       0,     0,   297,     0,     0,   434,     0,     0,     0,   292,
     288,   291,   271,    47,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
       0,   330,   676,   673,   674,   675,   680,   679,   681,   677,
     678,    83,    80,    86,    79,    84,    85,    78,    82,    81,
      72,    71,    74,    75,    73,    76,    77,     0,     0,   371,
     125,     0,     0,     0,   137,     0,   129,   130,   132,   131,
       0,     0,     0,     0,   107,   345,     0,     0,     0,   347,
      31,    32,    33,    34,    35,    36,    37,   259,   260,   254,
     269,   268,     0,   267,   255,   263,   256,   262,   250,   261,
     253,   252,   251,    38,    38,    38,    40,    39,   257,   258,
     417,   420,   421,   431,   428,   413,   429,   426,   427,     0,
     425,   430,   412,   419,   416,   415,   414,   418,   432,   449,
     450,   464,   465,   587,     0,   561,     0,   311,   312,   321,
     317,   318,   320,   325,   322,   323,   324,   319,     0,   316,
     310,   328,   327,   326,   309,   441,   440,   295,   294,   279,
     280,   277,   278,   276,     0,   275,     0,     0,     0,   104,
     105,   169,   166,   216,   228,   203,   212,     0,   201,   206,
       0,   222,     0,   215,   220,   226,   205,   208,   217,   219,
     223,   213,   221,   209,   227,   211,   218,   207,   210,     0,
     199,   162,   164,   174,   194,   178,   179,   180,   190,   175,
     176,   185,   193,   177,   187,   191,   182,   192,   183,   195,
     186,   181,   189,   184,   188,     0,   173,   167,   168,   163,
     165,   339,   337,   338,   377,   382,   388,   391,   384,   390,
     385,   389,   387,   383,   386,     0,   381,   133,     0,     0,
       0,     0,   128,   116,   115,   117,   118,   354,   360,   366,
     369,   362,   368,   363,   367,   365,   361,   364,     0,   359,
     355,   265,     0,    41,    42,    43,   423,     0,   588,   562,
     314,     0,   273,     0,   293,   290,   289,     0,     0,     0,
       0,     0,     0,     0,   197,     0,   171,     0,   379,     0,
       0,     0,     0,     0,   127,   357,     0,   266,   424,   315,
     274,   202,   225,   200,   229,   224,   214,   204,   198,   172,
     380,   134,   136,   135,   145,   144,   140,   142,   146,   143,
     139,   141,     0,   358,   138
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1075, -1075, -1075,  -358,  -317, -1074,  -656, -1075, -1075, -1075,
     397, -1075, -1075,   953, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075,  1008, -1075, -1075, -1075, -1075, -1075, -1075,   575,
   -1075, -1075, -1075, -1075, -1075,   589, -1075, -1075, -1075, -1075,
   -1075, -1075,   828, -1075, -1075, -1075, -1075,   118, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075,   661, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,  -100, -1075,
   -1075, -1075,   -99, -1075, -1075, -1075,   874, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075,   -65, -1075, -1075, -1075, -1075, -1075,
     -72, -1075,   719, -1075, -1075, -1075,    48, -1075, -1075, -1075,
   -1075, -1075,   747, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
     -68, -1075, -1075, -1075, -1075, -1075, -1075,   682, -1075, -1075,
   -1075, -1075, -1075,   931, -1075, -1075, -1075, -1075,   614, -1075,
   -1075, -1075, -1075, -1075,   -90, -1075, -1075, -1075,   647, -1075,
   -1075, -1075, -1075,   -79, -1075, -1075, -1075,   887, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
     -54, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,   742,
   -1075, -1075, -1075, -1075, -1075,   830, -1075, -1075, -1075, -1075,
    1111, -1075, -1075, -1075, -1075,   824, -1075, -1075, -1075, -1075,
    1058, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,    95, -1075, -1075, -1075,   101, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
    1142, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
     992, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    26,   848,   849,  1116,  1117,    27,   237,   512,
     513,    28,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
      29,    77,    78,    79,    80,    81,    30,    63,   518,   519,
     520,   521,    31,    70,   601,   602,   603,   604,   605,   606,
      32,   300,   301,   302,   303,   304,  1075,  1076,  1077,  1078,
    1079,  1260,  1342,    33,    64,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   774,  1235,  1236,   544,
     771,  1209,  1210,    34,    53,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   646,  1102,  1103,    35,    61,   504,   758,  1174,
    1175,   505,   506,   507,  1178,  1020,  1021,   508,   509,    36,
      59,   482,   483,   484,   485,   486,   487,   488,   743,  1158,
    1159,   489,   490,   491,    37,    65,   549,   550,   551,   552,
     553,    38,   308,   309,   310,    39,    72,   614,   615,   616,
     617,   618,   833,  1278,  1279,    40,    68,   587,   588,   589,
     590,   816,  1255,  1256,    41,    54,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   667,  1129,
    1130,   398,   399,   400,   401,   402,    42,    60,   495,   496,
     497,   498,    43,    55,   406,   407,   408,   409,    44,   124,
     125,   126,    45,    57,   416,   417,   418,   419,    46,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   451,   983,   984,   222,   450,   959,   960,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    47,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    48,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     880,   881,   625,   545,  1127,   403,   510,   610,   631,   632,
     633,   122,   635,   636,  1100,  1311,    51,   499,    52,    73,
      56,   122,  1143,   241,   473,  1144,   298,   403,   128,  1071,
     298,   413,   306,   129,   130,    58,   131,   132,   492,  1283,
    1284,  1285,   133,   474,   492,    49,    50,    66,   879,   134,
     135,   136,   137,   138,   139,   546,   306,    62,    74,   140,
     141,   142,   262,   584,   596,    75,   242,  1145,   584,   143,
    1146,   610,   144,   145,   475,   884,   885,    67,   243,   244,
     245,   404,   146,   246,   247,   500,  1101,   123,   248,   249,
     250,  1281,    69,   501,  1282,   502,   547,   123,   263,   147,
      71,   264,   476,   404,   689,  1286,   691,   692,  1287,  1290,
     148,   119,  1291,   149,   150,   120,   701,   121,   515,   511,
    1071,   611,   707,   151,  1292,    82,   515,  1293,   713,   152,
     153,   265,   154,    76,   155,   127,   721,   722,   156,   157,
     548,   266,   405,  1072,  1304,   414,   307,  1305,   158,   734,
     735,   736,   503,   159,   160,   477,   161,   162,   163,    83,
      84,   164,   478,   479,   405,   267,   233,    85,   415,   268,
     307,   234,    86,    87,    88,   493,   269,   585,   597,   270,
     271,   493,   585,   522,   480,   611,   165,   166,   545,   596,
     167,   168,   169,   170,   171,   172,   173,    89,    90,    91,
      92,   370,   523,   371,  1128,   372,  -126,   235,   272,   236,
    -126,   516,    93,    94,    95,   238,   413,   239,   337,   516,
     373,    96,    97,    98,  1306,    99,  1308,  1307,   313,  1309,
     473,  1073,   240,   524,  1072,   338,   339,   598,   612,   789,
     546,   613,  1113,  1114,  1115,   174,   175,   340,   785,   474,
     680,   374,   835,   312,   297,   599,   176,   177,   481,   299,
    1074,   525,   760,   299,   316,   178,   411,   179,   563,   375,
     600,   376,   494,   471,  1261,   593,   686,   608,   494,   377,
     475,   547,   273,   753,   274,   275,   314,   276,   277,   278,
    1315,   378,   315,  1316,   586,   305,   341,   526,   517,   586,
      73,   311,   612,   597,  1169,   613,   517,   582,   476,   827,
     522,   514,   623,   817,   527,   379,   342,   343,   499,   318,
     565,  1170,  1073,   344,   319,   548,   320,   345,   868,   523,
     414,   871,   346,   873,   321,   322,   380,   323,   878,    74,
     347,   348,   349,  1334,  1171,  1335,    75,   324,   325,   326,
     327,  1074,   350,   415,   328,   381,   896,   329,   330,   331,
     524,   477,   598,   766,   332,   333,   334,   624,   478,   479,
     335,   382,   410,   351,   626,   591,  1149,   420,   421,   422,
     599,   423,   424,   425,   426,   427,   500,   428,   525,  1336,
     480,   528,   429,   430,   501,   600,   502,   841,   842,   843,
     844,   845,   846,   847,   529,   431,  1337,   530,   432,   433,
     434,   352,  1150,   435,    76,   436,   437,   531,   438,   439,
     383,   532,   384,   385,   526,   440,   128,   441,   779,   442,
     443,   129,   130,   444,   131,   132,   445,   595,  1338,  1339,
     133,   527,   446,   447,   448,  1151,   676,   134,   135,   136,
     137,   138,   139,   503,   449,   452,   453,   140,   141,   142,
     454,   455,   456,   658,   481,   622,   457,   143,   458,   459,
     144,   145,   460,   461,   879,   749,  1152,  1153,   462,   619,
     146,  1172,  1154,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
     463,  1173,  1183,   624,   464,   465,  1340,   147,   466,   627,
     467,   468,  1341,   469,   470,   554,  1155,   555,   148,   556,
     557,   149,   150,   558,   559,   560,  1184,  1185,   528,   561,
     562,   151,   566,   567,   568,   569,   570,   152,   153,  1186,
     154,   529,   155,   628,   530,   262,   156,   157,   571,   572,
     573,   574,   575,   576,   531,   370,   158,   371,   532,   372,
     577,   159,   160,   578,   161,   162,   163,   579,   580,   164,
     581,   592,   607,   620,   373,   621,   629,   630,   634,  1187,
    1188,   263,  1189,   637,   264,   638,  1156,   639,   640,   821,
     641,   642,   643,   660,   165,   166,   682,   644,   167,   168,
     169,   170,   171,   172,   173,   374,   645,  1190,   647,   683,
     648,  1191,  1157,  1312,   265,   649,   650,   651,  1192,   652,
     688,   653,   654,   375,   266,   376,   655,   937,   656,   657,
     661,   662,   663,   377,   664,   665,   666,   668,   669,  1193,
     670,  1194,   671,  1195,   672,   378,   673,   674,   267,   675,
     678,   679,   268,   174,   175,   684,   685,   690,   693,   269,
    1196,   694,   270,   271,   176,   177,   695,   696,   697,   379,
     938,   961,   698,   178,   699,   179,  1197,   939,   700,   940,
     941,  1198,   702,   703,   704,  1199,   705,   706,   708,  1200,
     380,   272,   709,   710,  1201,   711,   712,   714,   715,  1202,
     716,   717,   720,   723,   724,   718,   726,  1213,  1203,   381,
    1204,  1205,   719,  1206,   962,   725,   727,   728,   729,   730,
     731,   963,   732,   964,   965,   382,   733,   737,   739,   337,
     741,  1207,   738,   787,   788,   740,  1321,   791,   793,  1208,
     790,   742,   744,   745,   746,   747,   338,   339,  1322,  1323,
    1214,  1324,   755,   763,   748,   794,   751,  1215,   340,  1216,
    1217,   752,   756,   757,   759,   273,   762,   274,   275,   764,
     276,   277,   278,   765,   383,   768,   384,   385,   769,   770,
     792,   772,   773,   775,   776,   777,   778,  1245,   942,   943,
     781,   782,   944,   783,   795,   945,   946,   784,   947,   797,
     948,   796,   798,   949,   799,   950,   951,   341,   800,   813,
     801,   952,   802,   953,   803,   804,   954,   805,   806,   807,
     955,   956,   957,   808,   809,   810,  1268,   342,   343,   811,
     958,   812,   966,   967,   344,   814,   968,   819,   345,   969,
     970,   815,   971,   346,   972,   820,   822,   973,  1246,   974,
     975,   347,   348,   349,   823,   976,   824,   977,   825,   826,
     978,   829,   830,   350,   979,   980,   981,   831,  1218,  1219,
     837,   832,  1220,  1247,   982,  1221,  1222,   834,  1223,   838,
    1224,  1248,   839,  1225,   351,  1226,  1227,  1269,     2,     3,
    1249,  1228,     4,  1229,   840,   850,  1230,   851,   852,   853,
    1231,  1232,  1233,   854,   855,     5,   856,   857,     6,   858,
    1234,   859,  1270,  1250,   860,  1251,  1252,     7,   861,   862,
    1271,   863,   352,   864,   865,    82,   866,     8,   867,  1272,
     869,   870,   872,   874,   882,   875,  1253,   876,   877,   879,
     883,     9,   886,   887,  1254,   888,   899,    10,    11,   889,
     890,   891,  1273,   892,  1274,  1275,   893,   894,   895,    83,
      84,   897,   898,   900,   901,   904,    12,    85,   902,   903,
      13,  1005,    86,    87,    88,  1276,   905,   906,  1004,   907,
      14,    15,   908,  1277,   909,   910,   911,   241,   912,   913,
     914,   915,   916,   917,   918,   919,   920,    89,    90,    91,
      92,   921,    16,   922,   923,   924,   925,   926,   927,   928,
     929,   930,    93,    94,    95,   931,    17,   932,   933,   934,
     935,    96,    97,    98,   936,    99,   985,   986,   987,   988,
     242,   989,   990,    18,   991,   992,   993,   994,   995,   996,
     997,   998,   243,   244,   245,    19,    20,   246,   247,   999,
    1000,  1001,   248,   249,   250,  1002,  1003,  1006,  1007,  1012,
    1008,  1009,  1010,    21,  1011,  1013,  1014,  1018,  1016,  1015,
    1017,  1022,  1019,  1024,  1025,  1028,    22,  1026,  1027,  1029,
    1030,    23,  1031,  1032,  1033,  1034,  1035,    24,  1036,  1037,
      25,  1038,  1039,  1040,  1177,   317,  1041,  1042,  1043,  1044,
    1045,  1046,  1047,   767,  1048,  1049,  1050,  1051,  1052,  1053,
    1054,  1055,  1056,  1325,  1057,  1058,  1059,  1060,  1061,  1062,
    1063,  1064,  1065,  1066,  1067,  1069,  1080,  1070,  1081,  1068,
    1082,  1084,  1083,  1326,  1086,  1085,  1088,  1327,   594,  1089,
    1097,  1098,  1087,  1099,  1104,  1105,  1106,  1107,  1108,  1109,
    1110,  1111,  1112,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1023,
    1138,  1139,  1140,  1141,  1142,  1147,  1148,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1176,  1179,  1180,  1181,
    1182,  1211,  1212,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
     828,  1244,  1257,  1262,   780,  1263,  1264,  1265,  1258,  1259,
    1266,  1267,  1280,  1294,  1313,  1296,  1328,  1329,  1297,  1298,
    1299,  1300,  1301,  1302,  1303,  1310,  1314,  1317,  1331,  1332,
    1333,  1320,  1344,  1319,   761,  1295,  1343,   659,   836,   750,
    1330,   786,   583,  1318,   818,   412,   681,   754,   472,   609,
     687,  1289,   336,   564,     0,  1288,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   677
};

static const yytype_int16 yycheck[] =
{
     656,   657,   319,     1,     8,     1,    31,     1,   325,   326,
     327,     1,   329,   330,    65,   211,   249,     1,   249,     1,
     249,     1,   245,     1,     1,   248,     1,     1,     1,     1,
       1,     1,     1,     6,     7,   249,     9,    10,     1,  1113,
    1114,  1115,    15,    20,     1,   245,   246,   249,   244,    22,
      23,    24,    25,    26,    27,    53,     1,   243,    40,    32,
      33,    34,     1,     1,     1,    47,    44,   245,     1,    42,
     248,     1,    45,    46,    51,   185,   186,   249,    56,    57,
      58,    77,    55,    61,    62,    69,   137,    77,    66,    67,
      68,   245,   249,    77,   248,    79,    94,    77,    37,    72,
     249,    40,    79,    77,   421,   245,   423,   424,   248,   245,
      83,   249,   248,    86,    87,   249,   433,   249,     1,   144,
       1,   115,   439,    96,   245,     1,     1,   248,   445,   102,
     103,    70,   105,   115,   107,   249,   453,   454,   111,   112,
     138,    80,   138,   115,   245,   115,   115,   248,   121,   466,
     467,   468,   136,   126,   127,   132,   129,   130,   131,    35,
      36,   134,   139,   140,   138,   104,   249,    43,   138,   108,
     115,   249,    48,    49,    50,   138,   115,   115,   115,   118,
     119,   138,   115,     1,   161,   115,   159,   160,     1,     1,
     163,   164,   165,   166,   167,   168,   169,    73,    74,    75,
      76,     1,    20,     3,   208,     5,   181,   249,   147,   247,
     181,    94,    88,    89,    90,   249,     1,   249,     1,    94,
      20,    97,    98,    99,   245,   101,   245,   248,   250,   248,
       1,   203,   249,    51,   115,    18,    19,   174,   232,   556,
      53,   235,    12,    13,    14,   218,   219,    30,   246,    20,
     246,    51,   246,   245,   249,   192,   229,   230,   235,   234,
     232,    79,   246,   234,   246,   238,   246,   240,   246,    69,
     207,    71,   235,   246,   246,   246,   246,   246,   235,    79,
      51,    94,   221,   246,   223,   224,   250,   226,   227,   228,
     245,    91,   250,   248,   232,   249,    79,   115,   181,   232,
       1,   249,   232,   115,    21,   235,   181,   246,    79,   246,
       1,   245,   244,   246,   132,   115,    99,   100,     1,   250,
     245,    38,   203,   106,   250,   138,   250,   110,   645,    20,
     115,   648,   115,   650,   250,   250,   136,   250,   655,    40,
     123,   124,   125,    82,    61,    84,    47,   250,   250,   250,
     250,   232,   135,   138,   250,   155,   673,   250,   250,   250,
      51,   132,   174,   246,   250,   250,   250,   244,   139,   140,
     246,   171,   250,   156,   217,   245,    16,   250,   250,   250,
     192,   250,   250,   250,   250,   250,    69,   250,    79,   128,
     161,   209,   250,   250,    77,   207,    79,   148,   149,   150,
     151,   152,   153,   154,   222,   250,   145,   225,   250,   250,
     250,   194,    52,   250,   115,   250,   250,   235,   250,   250,
     220,   239,   222,   223,   115,   250,     1,   250,   246,   250,
     250,     6,     7,   250,     9,    10,   250,   181,   177,   178,
      15,   132,   250,   250,   250,    85,   246,    22,    23,    24,
      25,    26,    27,   136,   250,   250,   250,    32,    33,    34,
     250,   250,   250,   246,   235,   245,   250,    42,   250,   250,
      45,    46,   250,   250,   244,   246,   116,   117,   250,   243,
      55,   198,   122,   841,   842,   843,   844,   845,   846,   847,
     250,   208,     4,   244,   250,   250,   235,    72,   250,   217,
     250,   250,   241,   250,   250,   250,   146,   250,    83,   250,
     250,    86,    87,   250,   250,   250,    28,    29,   209,   250,
     250,    96,   250,   250,   250,   250,   250,   102,   103,    41,
     105,   222,   107,   217,   225,     1,   111,   112,   250,   250,
     250,   250,   250,   250,   235,     1,   121,     3,   239,     5,
     250,   126,   127,   250,   129,   130,   131,   250,   250,   134,
     250,   250,   250,   243,    20,   243,   217,   244,   244,    81,
      82,    37,    84,   244,    40,   244,   216,   244,   244,   249,
     245,   245,   250,   245,   159,   160,   243,   250,   163,   164,
     165,   166,   167,   168,   169,    51,   250,   109,   250,   245,
     250,   113,   242,  1259,    70,   250,   250,   250,   120,   250,
     217,   250,   250,    69,    80,    71,   250,    11,   250,   250,
     250,   250,   250,    79,   250,   250,   250,   250,   250,   141,
     250,   143,   250,   145,   250,    91,   250,   250,   104,   250,
     250,   250,   108,   218,   219,   250,   250,   244,   217,   115,
     162,   244,   118,   119,   229,   230,   244,   244,   243,   115,
      54,    11,   243,   238,   217,   240,   178,    61,   244,    63,
      64,   183,   217,   244,   244,   187,   217,   217,   244,   191,
     136,   147,   244,   244,   196,   244,   244,   244,   244,   201,
     244,   217,   217,   217,   217,   250,   217,    11,   210,   155,
     212,   213,   250,   215,    54,   244,   217,   217,   217,   217,
     217,    61,   217,    63,    64,   171,   244,   217,   245,     1,
     250,   233,   244,   217,   217,   245,   142,   217,   217,   241,
     243,   250,   250,   250,   250,   250,    18,    19,   145,   142,
      54,    95,   245,   245,   250,   217,   250,    61,    30,    63,
      64,   250,   250,   250,   250,   221,   248,   223,   224,   250,
     226,   227,   228,   250,   220,   245,   222,   223,   250,   250,
     243,   250,   250,   250,   250,   250,   250,    84,   172,   173,
     245,   250,   176,   250,   217,   179,   180,   250,   182,   244,
     184,   245,   243,   187,   217,   189,   190,    79,   243,   245,
     244,   195,   244,   197,   243,   243,   200,   243,   243,   243,
     204,   205,   206,   243,   243,   243,    84,    99,   100,   243,
     214,   243,   172,   173,   106,   245,   176,   217,   110,   179,
     180,   250,   182,   115,   184,   245,   245,   187,   145,   189,
     190,   123,   124,   125,   250,   195,   250,   197,   250,   250,
     200,   243,   245,   135,   204,   205,   206,   245,   172,   173,
     245,   250,   176,   170,   214,   179,   180,   250,   182,   245,
     184,   178,   245,   187,   156,   189,   190,   145,     0,     1,
     187,   195,     4,   197,   245,   245,   200,   245,   245,   245,
     204,   205,   206,   245,   245,    17,   245,   245,    20,   245,
     214,   245,   170,   210,   245,   212,   213,    29,   245,   245,
     178,   245,   194,   245,   245,     1,   244,    39,   244,   187,
     250,   244,   244,   243,   245,   244,   233,   244,   244,   244,
     243,    53,   243,   217,   241,   243,   245,    59,    60,   243,
     250,   243,   210,   243,   212,   213,   244,   243,   243,    35,
      36,   243,   243,   243,   243,   243,    78,    43,   245,   245,
      82,   217,    48,    49,    50,   233,   243,   245,   243,   245,
      92,    93,   245,   241,   245,   245,   245,     1,   245,   245,
     245,   245,   245,   245,   245,   245,   245,    73,    74,    75,
      76,   245,   114,   245,   245,   245,   245,   245,   245,   245,
     245,   245,    88,    89,    90,   245,   128,   245,   245,   245,
     245,    97,    98,    99,   245,   101,   245,   245,   245,   245,
      44,   245,   245,   145,   245,   245,   245,   245,   245,   245,
     245,   245,    56,    57,    58,   157,   158,    61,    62,   245,
     245,   245,    66,    67,    68,   245,   245,   250,   243,   245,
     244,   243,   243,   175,   243,   243,   243,   250,   243,   245,
     243,   245,   244,   243,   243,   217,   188,   245,   243,   250,
     243,   193,   243,   250,   243,   217,   243,   199,   243,   245,
     202,   243,   243,   243,   248,    77,   245,   245,   245,   245,
     245,   245,   245,   518,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   145,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   243,   245,   243,   245,   243,   250,
     243,   245,   243,   142,   243,   245,   243,   142,   300,   245,
     245,   245,   250,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   762,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   231,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     601,   245,   245,  1075,   533,   245,   245,   245,   250,   250,
     245,   245,   245,   244,   250,   245,  1305,  1307,   247,   247,
     247,   247,   247,   247,   247,   243,   245,  1282,   245,   245,
     245,  1293,   245,  1291,   505,  1177,  1316,   353,   614,   482,
    1309,   549,   279,  1287,   587,   124,   406,   495,   180,   308,
     416,  1146,   100,   251,    -1,  1144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   386
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   252,     0,     1,     4,    17,    20,    29,    39,    53,
      59,    60,    78,    82,    92,    93,   114,   128,   145,   157,
     158,   175,   188,   193,   199,   202,   253,   258,   262,   281,
     287,   293,   301,   314,   334,   356,   370,   385,   392,   396,
     406,   415,   437,   443,   449,   453,   459,   519,   539,   245,
     246,   249,   249,   335,   416,   444,   249,   454,   249,   371,
     438,   357,   243,   288,   315,   386,   249,   249,   407,   249,
     294,   249,   397,     1,    40,    47,   115,   282,   283,   284,
     285,   286,     1,    35,    36,    43,    48,    49,    50,    73,
      74,    75,    76,    88,    89,    90,    97,    98,    99,   101,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   249,
     249,   249,     1,    77,   450,   451,   452,   249,     1,     6,
       7,     9,    10,    15,    22,    23,    24,    25,    26,    27,
      32,    33,    34,    42,    45,    46,    55,    72,    83,    86,
      87,    96,   102,   103,   105,   107,   111,   112,   121,   126,
     127,   129,   130,   131,   134,   159,   160,   163,   164,   165,
     166,   167,   168,   169,   218,   219,   229,   230,   238,   240,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   505,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   249,   249,   249,   247,   259,   249,   249,
     249,     1,    44,    56,    57,    58,    61,    62,    66,    67,
      68,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,     1,    37,    40,    70,    80,   104,   108,   115,
     118,   119,   147,   221,   223,   224,   226,   227,   228,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   249,     1,   234,
     302,   303,   304,   305,   306,   249,     1,   115,   393,   394,
     395,   249,   245,   250,   250,   250,   246,   283,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   246,   521,     1,    18,    19,
      30,    79,    99,   100,   106,   110,   115,   123,   124,   125,
     135,   156,   194,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
       1,     3,     5,    20,    51,    69,    71,    79,    91,   115,
     136,   155,   171,   220,   222,   223,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   432,   433,
     434,   435,   436,     1,    77,   138,   445,   446,   447,   448,
     250,   246,   451,     1,   115,   138,   455,   456,   457,   458,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     506,   502,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   246,   461,     1,    20,    51,    79,   132,   139,   140,
     161,   235,   372,   373,   374,   375,   376,   377,   378,   382,
     383,   384,     1,   138,   235,   439,   440,   441,   442,     1,
      69,    77,    79,   136,   358,   362,   363,   364,   368,   369,
      31,   144,   260,   261,   245,     1,    94,   181,   289,   290,
     291,   292,     1,    20,    51,    79,   115,   132,   209,   222,
     225,   235,   239,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   330,     1,    53,    94,   138,   387,
     388,   389,   390,   391,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   246,   541,   245,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   246,   264,     1,   115,   232,   408,   409,   410,
     411,   245,   250,   246,   303,   181,     1,   115,   174,   192,
     207,   295,   296,   297,   298,   299,   300,   250,   246,   394,
       1,   115,   232,   235,   398,   399,   400,   401,   402,   243,
     243,   243,   245,   244,   244,   255,   217,   217,   217,   217,
     244,   255,   255,   255,   244,   255,   255,   244,   244,   244,
     244,   245,   245,   250,   250,   250,   353,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   246,   337,
     245,   250,   250,   250,   250,   250,   250,   429,   250,   250,
     250,   250,   250,   250,   250,   250,   246,   418,   250,   250,
     246,   446,   243,   245,   250,   250,   246,   456,   217,   255,
     244,   255,   255,   217,   244,   244,   244,   243,   243,   217,
     244,   255,   217,   244,   244,   217,   217,   255,   244,   244,
     244,   244,   244,   255,   244,   244,   244,   217,   250,   250,
     217,   255,   255,   217,   217,   244,   217,   217,   217,   217,
     217,   217,   217,   244,   255,   255,   255,   217,   244,   245,
     245,   250,   250,   379,   250,   250,   250,   250,   250,   246,
     373,   250,   250,   246,   440,   245,   250,   250,   359,   250,
     246,   363,   248,   245,   250,   250,   246,   290,   245,   250,
     250,   331,   250,   250,   327,   250,   250,   250,   250,   246,
     317,   245,   250,   250,   250,   246,   388,   217,   217,   255,
     243,   217,   243,   217,   217,   217,   245,   244,   243,   217,
     243,   244,   244,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   245,   245,   250,   412,   246,   409,   217,
     245,   249,   245,   250,   250,   250,   250,   246,   296,   243,
     245,   245,   250,   403,   250,   246,   399,   245,   245,   245,
     245,   148,   149,   150,   151,   152,   153,   154,   254,   255,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   244,   244,   255,   250,
     244,   255,   244,   255,   243,   244,   244,   244,   255,   244,
     257,   257,   245,   243,   185,   186,   243,   217,   243,   243,
     250,   243,   243,   244,   243,   243,   255,   243,   243,   245,
     243,   243,   245,   245,   243,   243,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,    11,    54,    61,
      63,    64,   172,   173,   176,   179,   180,   182,   184,   187,
     189,   190,   195,   197,   200,   204,   205,   206,   214,   507,
     508,    11,    54,    61,    63,    64,   172,   173,   176,   179,
     180,   182,   184,   187,   189,   190,   195,   197,   200,   204,
     205,   206,   214,   503,   504,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   243,   217,   250,   243,   244,   243,
     243,   243,   245,   243,   243,   245,   243,   243,   250,   244,
     366,   367,   245,   261,   243,   243,   245,   243,   217,   250,
     243,   243,   250,   243,   217,   243,   243,   245,   243,   243,
     243,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   243,   250,   245,
     245,     1,   115,   203,   232,   307,   308,   309,   310,   311,
     243,   243,   243,   243,   245,   245,   243,   250,   243,   245,
     254,   254,   254,   254,   254,   254,   254,   245,   245,   245,
      65,   137,   354,   355,   245,   245,   245,   245,   245,   245,
     245,   245,   245,    12,    13,    14,   256,   257,   245,   245,
     245,   245,   245,   245,   245,   245,   245,     8,   208,   430,
     431,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   248,   245,   248,   245,   245,    16,
      52,    85,   116,   117,   122,   146,   216,   242,   380,   381,
     245,   245,   245,   245,   245,   245,   245,   245,   245,    21,
      38,    61,   198,   208,   360,   361,   231,   248,   365,   245,
     245,   245,   245,     4,    28,    29,    41,    81,    82,    84,
     109,   113,   120,   141,   143,   145,   162,   178,   183,   187,
     191,   196,   201,   210,   212,   213,   215,   233,   241,   332,
     333,   245,   245,    11,    54,    61,    63,    64,   172,   173,
     176,   179,   180,   182,   184,   187,   189,   190,   195,   197,
     200,   204,   205,   206,   214,   328,   329,   245,   245,   245,
     245,   245,   245,   245,   245,    84,   145,   170,   178,   187,
     210,   212,   213,   233,   241,   413,   414,   245,   250,   250,
     312,   246,   308,   245,   245,   245,   245,   245,    84,   145,
     170,   178,   187,   210,   212,   213,   233,   241,   404,   405,
     245,   245,   248,   256,   256,   256,   245,   248,   508,   504,
     245,   248,   245,   248,   244,   367,   245,   247,   247,   247,
     247,   247,   247,   247,   245,   248,   245,   248,   245,   248,
     243,   211,   257,   250,   245,   245,   248,   355,   431,   381,
     361,   142,   145,   142,    95,   145,   142,   142,   333,   329,
     414,   245,   245,   245,    82,    84,   128,   145,   177,   178,
     235,   241,   313,   405,   245
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   251,   252,   252,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   254,   254,
     255,   255,   255,   255,   255,   255,   255,   255,   256,   256,
     257,   257,   257,   257,   258,   259,   259,   260,   260,   261,
     261,   262,   263,   263,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   282,
     283,   283,   283,   283,   284,   285,   286,   288,   287,   289,
     289,   290,   290,   290,   291,   292,   294,   293,   295,   295,
     296,   296,   296,   296,   296,   297,   298,   299,   300,   301,
     302,   302,   303,   303,   303,   304,   306,   305,   307,   307,
     308,   308,   308,   308,   309,   310,   310,   312,   311,   313,
     313,   313,   313,   313,   313,   313,   313,   315,   314,   316,
     316,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     327,   326,   328,   328,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   331,   330,   332,   332,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     335,   334,   336,   336,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   353,   352,   354,   354,   355,   355,
     357,   356,   359,   358,   360,   360,   361,   361,   361,   361,
     361,   362,   362,   363,   363,   363,   363,   363,   365,   364,
     366,   366,   367,   367,   368,   369,   371,   370,   372,   372,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   374,
     375,   376,   377,   379,   378,   380,   380,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   382,   383,   384,   386,
     385,   387,   387,   388,   388,   388,   388,   389,   390,   391,
     392,   393,   393,   394,   394,   395,   397,   396,   398,   398,
     399,   399,   399,   399,   400,   401,   403,   402,   404,   404,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     407,   406,   408,   408,   409,   409,   409,   410,   412,   411,
     413,   413,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   416,   415,   417,   417,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   427,   429,   428,   430,   430,   431,   431,   432,   433,
     434,   435,   436,   438,   437,   439,   439,   440,   440,   440,
     441,   442,   444,   443,   445,   445,   446,   446,   446,   447,
     448,   449,   450,   450,   451,   451,   452,   454,   453,   455,
     455,   456,   456,   456,   457,   458,   459,   460,   460,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     502,   501,   503,   503,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   506,   505,   507,   507,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   520,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   540,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     0,     1,
       2,     3,     3,     3,     4,     0,     2,     3,     1,     1,
       1,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     2,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     2,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     2,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     4,     0,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     3,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       0,     6,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     0,     5,
       3,     1,     1,     3,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       5,     2,     1,     1,     1,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     2,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     4,     4,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4
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
  case 28: /* timespec_: %empty  */
#line 411 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3330 "conf_parser.c"
    break;

  case 30: /* timespec: NUMBER timespec_  */
#line 412 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3336 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER SECONDS timespec_  */
#line 413 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3342 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER MINUTES timespec_  */
#line 414 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3348 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER HOURS timespec_  */
#line 415 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3354 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER DAYS timespec_  */
#line 416 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3360 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER WEEKS timespec_  */
#line 417 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3366 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER MONTHS timespec_  */
#line 418 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3372 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER YEARS timespec_  */
#line 419 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3378 "conf_parser.c"
    break;

  case 38: /* sizespec_: %empty  */
#line 422 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3384 "conf_parser.c"
    break;

  case 40: /* sizespec: NUMBER sizespec_  */
#line 423 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3390 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER BYTES sizespec_  */
#line 424 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3396 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER KBYTES sizespec_  */
#line 425 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3402 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER MBYTES sizespec_  */
#line 426 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3408 "conf_parser.c"
    break;

  case 44: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 434 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_add_config((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3417 "conf_parser.c"
    break;

  case 45: /* module_attributes: %empty  */
#line 440 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3425 "conf_parser.c"
    break;

  case 49: /* module_attributes_item: RESIDENT  */
#line 447 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3434 "conf_parser.c"
    break;

  case 50: /* module_attributes_item: CORE  */
#line 451 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3443 "conf_parser.c"
    break;

  case 71: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 483 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3455 "conf_parser.c"
    break;

  case 72: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 492 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = io_strdup(yylval.string);
  }
}
#line 3467 "conf_parser.c"
    break;

  case 73: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 501 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = io_strdup(yylval.string);
  }
}
#line 3479 "conf_parser.c"
    break;

  case 74: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 510 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = io_strdup(yylval.string);
  }
}
#line 3491 "conf_parser.c"
    break;

  case 75: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 519 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = io_strdup(yylval.string);
  }
}
#line 3503 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 528 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = io_strdup(yylval.string);
  }
}
#line 3515 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 537 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = io_strdup(yylval.string);
  }
}
#line 3527 "conf_parser.c"
    break;

  case 78: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 546 "conf_parser.y"
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
#line 3545 "conf_parser.c"
    break;

  case 79: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 561 "conf_parser.y"
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
#line 3563 "conf_parser.c"
    break;

  case 80: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 576 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3576 "conf_parser.c"
    break;

  case 81: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 586 "conf_parser.y"
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
#line 3593 "conf_parser.c"
    break;

  case 82: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 600 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3605 "conf_parser.c"
    break;

  case 83: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 609 "conf_parser.y"
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
#line 3631 "conf_parser.c"
    break;

  case 84: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 632 "conf_parser.y"
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
#line 3657 "conf_parser.c"
    break;

  case 85: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 655 "conf_parser.y"
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
#line 3683 "conf_parser.c"
    break;

  case 86: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 678 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3692 "conf_parser.c"
    break;

  case 94: /* admin_name: NAME '=' QSTRING ';'  */
#line 696 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3704 "conf_parser.c"
    break;

  case 95: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 705 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3716 "conf_parser.c"
    break;

  case 96: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 714 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3728 "conf_parser.c"
    break;

  case 97: /* $@1: %empty  */
#line 727 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3737 "conf_parser.c"
    break;

  case 98: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 731 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3754 "conf_parser.c"
    break;

  case 104: /* motd_mask: MASK '=' QSTRING ';'  */
#line 748 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3763 "conf_parser.c"
    break;

  case 105: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 754 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3772 "conf_parser.c"
    break;

  case 106: /* $@2: %empty  */
#line 764 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3781 "conf_parser.c"
    break;

  case 107: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 768 "conf_parser.y"
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
#line 3799 "conf_parser.c"
    break;

  case 115: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 786 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3808 "conf_parser.c"
    break;

  case 116: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 792 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3817 "conf_parser.c"
    break;

  case 117: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 798 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3826 "conf_parser.c"
    break;

  case 118: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 804 "conf_parser.y"
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
#line 3848 "conf_parser.c"
    break;

  case 125: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 833 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3857 "conf_parser.c"
    break;

  case 126: /* $@3: %empty  */
#line 839 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3866 "conf_parser.c"
    break;

  case 127: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 843 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3879 "conf_parser.c"
    break;

  case 134: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 859 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3890 "conf_parser.c"
    break;

  case 135: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 867 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3898 "conf_parser.c"
    break;

  case 136: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 870 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3906 "conf_parser.c"
    break;

  case 137: /* $@4: %empty  */
#line 875 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3915 "conf_parser.c"
    break;

  case 139: /* logging_file_type_item: USER  */
#line 881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3924 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: OPERATOR  */
#line 885 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3933 "conf_parser.c"
    break;

  case 141: /* logging_file_type_item: XLINE  */
#line 889 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3942 "conf_parser.c"
    break;

  case 142: /* logging_file_type_item: RESV  */
#line 893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3951 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: T_DLINE  */
#line 897 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3960 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: KLINE  */
#line 901 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3969 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: KILL  */
#line 905 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3978 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: T_DEBUG  */
#line 909 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3987 "conf_parser.c"
    break;

  case 147: /* $@5: %empty  */
#line 919 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3999 "conf_parser.c"
    break;

  case 148: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 926 "conf_parser.y"
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
#line 4059 "conf_parser.c"
    break;

  case 162: /* oper_name: NAME '=' QSTRING ';'  */
#line 996 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4068 "conf_parser.c"
    break;

  case 163: /* oper_user: USER '=' QSTRING ';'  */
#line 1002 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4077 "conf_parser.c"
    break;

  case 164: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1008 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4086 "conf_parser.c"
    break;

  case 165: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1014 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4095 "conf_parser.c"
    break;

  case 166: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1020 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 4109 "conf_parser.c"
    break;

  case 167: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1031 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4118 "conf_parser.c"
    break;

  case 168: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1037 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 4132 "conf_parser.c"
    break;

  case 169: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4141 "conf_parser.c"
    break;

  case 170: /* $@6: %empty  */
#line 1054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 4150 "conf_parser.c"
    break;

  case 174: /* oper_umodes_item: BOT  */
#line 1061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOT;
}
#line 4159 "conf_parser.c"
    break;

  case 175: /* oper_umodes_item: T_CCONN  */
#line 1065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 4168 "conf_parser.c"
    break;

  case 176: /* oper_umodes_item: T_DEAF  */
#line 1069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 4177 "conf_parser.c"
    break;

  case 177: /* oper_umodes_item: T_FLOOD  */
#line 1073 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FLOOD;
}
#line 4186 "conf_parser.c"
    break;

  case 178: /* oper_umodes_item: HIDDEN  */
#line 1077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 4195 "conf_parser.c"
    break;

  case 179: /* oper_umodes_item: HIDE_CHANS  */
#line 1081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 4204 "conf_parser.c"
    break;

  case 180: /* oper_umodes_item: HIDE_IDLE  */
#line 1085 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 4213 "conf_parser.c"
    break;

  case 181: /* oper_umodes_item: T_SKILL  */
#line 1089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 4222 "conf_parser.c"
    break;

  case 182: /* oper_umodes_item: T_NCHANGE  */
#line 1093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 4231 "conf_parser.c"
    break;

  case 183: /* oper_umodes_item: T_REJ  */
#line 1097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 4240 "conf_parser.c"
    break;

  case 184: /* oper_umodes_item: T_SPY  */
#line 1101 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4249 "conf_parser.c"
    break;

  case 185: /* oper_umodes_item: T_EXTERNAL  */
#line 1105 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4258 "conf_parser.c"
    break;

  case 186: /* oper_umodes_item: T_SERVNOTICE  */
#line 1109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4267 "conf_parser.c"
    break;

  case 187: /* oper_umodes_item: T_INVISIBLE  */
#line 1113 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4276 "conf_parser.c"
    break;

  case 188: /* oper_umodes_item: T_WALLOP  */
#line 1117 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4285 "conf_parser.c"
    break;

  case 189: /* oper_umodes_item: T_SOFTCALLERID  */
#line 1121 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4294 "conf_parser.c"
    break;

  case 190: /* oper_umodes_item: T_CALLERID  */
#line 1125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4303 "conf_parser.c"
    break;

  case 191: /* oper_umodes_item: T_LOCOPS  */
#line 1129 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4312 "conf_parser.c"
    break;

  case 192: /* oper_umodes_item: T_NONONREG  */
#line 1133 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4321 "conf_parser.c"
    break;

  case 193: /* oper_umodes_item: T_FARCONNECT  */
#line 1137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4330 "conf_parser.c"
    break;

  case 194: /* oper_umodes_item: EXPIRATION  */
#line 1141 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 4339 "conf_parser.c"
    break;

  case 195: /* oper_umodes_item: T_SECUREONLY  */
#line 1145 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SECUREONLY;
}
#line 4348 "conf_parser.c"
    break;

  case 196: /* $@7: %empty  */
#line 1151 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4357 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: KILL ':' REMOTE  */
#line 1158 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4366 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: KILL  */
#line 1162 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4375 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1166 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4384 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: CONNECT  */
#line 1170 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4393 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1174 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4402 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: SQUIT  */
#line 1178 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4411 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: KLINE  */
#line 1182 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4420 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: UNKLINE  */
#line 1186 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4429 "conf_parser.c"
    break;

  case 208: /* oper_flags_item: T_DLINE  */
#line 1190 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4438 "conf_parser.c"
    break;

  case 209: /* oper_flags_item: T_UNDLINE  */
#line 1194 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4447 "conf_parser.c"
    break;

  case 210: /* oper_flags_item: XLINE  */
#line 1198 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4456 "conf_parser.c"
    break;

  case 211: /* oper_flags_item: T_UNXLINE  */
#line 1202 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4465 "conf_parser.c"
    break;

  case 212: /* oper_flags_item: DIE  */
#line 1206 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4474 "conf_parser.c"
    break;

  case 213: /* oper_flags_item: T_RESTART  */
#line 1210 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4483 "conf_parser.c"
    break;

  case 214: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1214 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4492 "conf_parser.c"
    break;

  case 215: /* oper_flags_item: REHASH  */
#line 1218 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4501 "conf_parser.c"
    break;

  case 216: /* oper_flags_item: ADMIN  */
#line 1222 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4510 "conf_parser.c"
    break;

  case 217: /* oper_flags_item: T_GLOBOPS  */
#line 1226 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4519 "conf_parser.c"
    break;

  case 218: /* oper_flags_item: T_WALLOPS  */
#line 1230 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4528 "conf_parser.c"
    break;

  case 219: /* oper_flags_item: T_LOCOPS  */
#line 1234 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4537 "conf_parser.c"
    break;

  case 220: /* oper_flags_item: REMOTEBAN  */
#line 1238 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4546 "conf_parser.c"
    break;

  case 221: /* oper_flags_item: T_SET  */
#line 1242 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4555 "conf_parser.c"
    break;

  case 222: /* oper_flags_item: MODULE  */
#line 1246 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4564 "conf_parser.c"
    break;

  case 223: /* oper_flags_item: T_OPME  */
#line 1250 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4573 "conf_parser.c"
    break;

  case 224: /* oper_flags_item: NICK ':' RESV  */
#line 1254 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4582 "conf_parser.c"
    break;

  case 225: /* oper_flags_item: JOIN ':' RESV  */
#line 1258 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4591 "conf_parser.c"
    break;

  case 226: /* oper_flags_item: RESV  */
#line 1262 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4600 "conf_parser.c"
    break;

  case 227: /* oper_flags_item: T_UNRESV  */
#line 1266 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4609 "conf_parser.c"
    break;

  case 228: /* oper_flags_item: CLOSE  */
#line 1270 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4618 "conf_parser.c"
    break;

  case 229: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1274 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4627 "conf_parser.c"
    break;

  case 230: /* $@8: %empty  */
#line 1284 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4643 "conf_parser.c"
    break;

  case 231: /* class_entry: CLASS $@8 '{' class_items '}' ';'  */
#line 1295 "conf_parser.y"
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
#line 4691 "conf_parser.c"
    break;

  case 250: /* class_name: NAME '=' QSTRING ';'  */
#line 1358 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4700 "conf_parser.c"
    break;

  case 251: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1364 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4709 "conf_parser.c"
    break;

  case 252: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1370 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4718 "conf_parser.c"
    break;

  case 253: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1376 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4727 "conf_parser.c"
    break;

  case 254: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1382 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4736 "conf_parser.c"
    break;

  case 255: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1388 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4745 "conf_parser.c"
    break;

  case 256: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1394 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4754 "conf_parser.c"
    break;

  case 257: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1400 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4763 "conf_parser.c"
    break;

  case 258: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1406 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4773 "conf_parser.c"
    break;

  case 259: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1413 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4782 "conf_parser.c"
    break;

  case 260: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1419 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4791 "conf_parser.c"
    break;

  case 261: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1425 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4800 "conf_parser.c"
    break;

  case 262: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1431 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4812 "conf_parser.c"
    break;

  case 263: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1440 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4824 "conf_parser.c"
    break;

  case 264: /* $@9: %empty  */
#line 1449 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4833 "conf_parser.c"
    break;

  case 268: /* class_flags_item: RANDOM_IDLE  */
#line 1456 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4842 "conf_parser.c"
    break;

  case 269: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1460 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4851 "conf_parser.c"
    break;

  case 270: /* $@10: %empty  */
#line 1470 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4860 "conf_parser.c"
    break;

  case 272: /* $@11: %empty  */
#line 1476 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4868 "conf_parser.c"
    break;

  case 276: /* listen_flags_item: T_TLS  */
#line 1482 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4877 "conf_parser.c"
    break;

  case 277: /* listen_flags_item: HIDDEN  */
#line 1486 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4886 "conf_parser.c"
    break;

  case 278: /* listen_flags_item: T_SERVER  */
#line 1490 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4895 "conf_parser.c"
    break;

  case 279: /* listen_flags_item: CLIENT  */
#line 1494 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4904 "conf_parser.c"
    break;

  case 280: /* listen_flags_item: DEFER  */
#line 1498 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4913 "conf_parser.c"
    break;

  case 288: /* $@12: %empty  */
#line 1506 "conf_parser.y"
                                 { reset_block_state(); }
#line 4919 "conf_parser.c"
    break;

  case 292: /* port_item: NUMBER  */
#line 1511 "conf_parser.y"
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
#line 4937 "conf_parser.c"
    break;

  case 293: /* port_item: NUMBER TWODOTS NUMBER  */
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

    for (int i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      listener_add(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4957 "conf_parser.c"
    break;

  case 294: /* listen_address: IP '=' QSTRING ';'  */
#line 1541 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4966 "conf_parser.c"
    break;

  case 295: /* listen_host: HOST '=' QSTRING ';'  */
#line 1547 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4975 "conf_parser.c"
    break;

  case 296: /* $@13: %empty  */
#line 1557 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4984 "conf_parser.c"
    break;

  case 297: /* auth_entry: IRCD_AUTH $@13 '{' auth_items '}' ';'  */
#line 1561 "conf_parser.y"
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
#line 5031 "conf_parser.c"
    break;

  case 309: /* auth_user: USER '=' QSTRING ';'  */
#line 1616 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5040 "conf_parser.c"
    break;

  case 310: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1622 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5049 "conf_parser.c"
    break;

  case 311: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1628 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5058 "conf_parser.c"
    break;

  case 312: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1634 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5072 "conf_parser.c"
    break;

  case 313: /* $@14: %empty  */
#line 1645 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 5081 "conf_parser.c"
    break;

  case 317: /* auth_flags_item: EXCEED_LIMIT  */
#line 1652 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 5090 "conf_parser.c"
    break;

  case 318: /* auth_flags_item: KLINE_EXEMPT  */
#line 1656 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 5099 "conf_parser.c"
    break;

  case 319: /* auth_flags_item: XLINE_EXEMPT  */
#line 1660 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 5108 "conf_parser.c"
    break;

  case 320: /* auth_flags_item: NEED_IDENT  */
#line 1664 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 5117 "conf_parser.c"
    break;

  case 321: /* auth_flags_item: CAN_FLOOD  */
#line 1668 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 5126 "conf_parser.c"
    break;

  case 322: /* auth_flags_item: NO_TILDE  */
#line 1672 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 5135 "conf_parser.c"
    break;

  case 323: /* auth_flags_item: RESV_EXEMPT  */
#line 1676 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 5144 "conf_parser.c"
    break;

  case 324: /* auth_flags_item: T_WEBIRC  */
#line 1680 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 5153 "conf_parser.c"
    break;

  case 325: /* auth_flags_item: NEED_PASSWORD  */
#line 1684 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 5162 "conf_parser.c"
    break;

  case 326: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1690 "conf_parser.y"
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
#line 5179 "conf_parser.c"
    break;

  case 327: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1704 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 5191 "conf_parser.c"
    break;

  case 328: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1713 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 5203 "conf_parser.c"
    break;

  case 329: /* $@15: %empty  */
#line 1726 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5215 "conf_parser.c"
    break;

  case 330: /* resv_entry: RESV $@15 '{' resv_items '}' ';'  */
#line 1733 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5226 "conf_parser.c"
    break;

  case 337: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1744 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5235 "conf_parser.c"
    break;

  case 338: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1750 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5244 "conf_parser.c"
    break;

  case 339: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1756 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5253 "conf_parser.c"
    break;

  case 345: /* service_name: NAME '=' QSTRING ';'  */
#line 1771 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5268 "conf_parser.c"
    break;

  case 346: /* $@16: %empty  */
#line 1787 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5284 "conf_parser.c"
    break;

  case 347: /* shared_entry: T_SHARED $@16 '{' shared_items '}' ';'  */
#line 1798 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5299 "conf_parser.c"
    break;

  case 354: /* shared_name: NAME '=' QSTRING ';'  */
#line 1813 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5308 "conf_parser.c"
    break;

  case 355: /* shared_user: USER '=' QSTRING ';'  */
#line 1819 "conf_parser.y"
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
#line 5330 "conf_parser.c"
    break;

  case 356: /* $@17: %empty  */
#line 1838 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5339 "conf_parser.c"
    break;

  case 360: /* shared_type_item: KLINE  */
#line 1845 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5348 "conf_parser.c"
    break;

  case 361: /* shared_type_item: UNKLINE  */
#line 1849 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5357 "conf_parser.c"
    break;

  case 362: /* shared_type_item: T_DLINE  */
#line 1853 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5366 "conf_parser.c"
    break;

  case 363: /* shared_type_item: T_UNDLINE  */
#line 1857 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5375 "conf_parser.c"
    break;

  case 364: /* shared_type_item: XLINE  */
#line 1861 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5384 "conf_parser.c"
    break;

  case 365: /* shared_type_item: T_UNXLINE  */
#line 1865 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5393 "conf_parser.c"
    break;

  case 366: /* shared_type_item: RESV  */
#line 1869 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5402 "conf_parser.c"
    break;

  case 367: /* shared_type_item: T_UNRESV  */
#line 1873 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5411 "conf_parser.c"
    break;

  case 368: /* shared_type_item: T_LOCOPS  */
#line 1877 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5420 "conf_parser.c"
    break;

  case 369: /* shared_type_item: T_ALL  */
#line 1881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5429 "conf_parser.c"
    break;

  case 370: /* $@18: %empty  */
#line 1891 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5443 "conf_parser.c"
    break;

  case 371: /* cluster_entry: T_CLUSTER $@18 '{' cluster_items '}' ';'  */
#line 1900 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5456 "conf_parser.c"
    break;

  case 377: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1913 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5465 "conf_parser.c"
    break;

  case 378: /* $@19: %empty  */
#line 1919 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5474 "conf_parser.c"
    break;

  case 382: /* cluster_type_item: KLINE  */
#line 1926 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5483 "conf_parser.c"
    break;

  case 383: /* cluster_type_item: UNKLINE  */
#line 1930 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5492 "conf_parser.c"
    break;

  case 384: /* cluster_type_item: T_DLINE  */
#line 1934 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5501 "conf_parser.c"
    break;

  case 385: /* cluster_type_item: T_UNDLINE  */
#line 1938 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5510 "conf_parser.c"
    break;

  case 386: /* cluster_type_item: XLINE  */
#line 1942 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5519 "conf_parser.c"
    break;

  case 387: /* cluster_type_item: T_UNXLINE  */
#line 1946 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5528 "conf_parser.c"
    break;

  case 388: /* cluster_type_item: RESV  */
#line 1950 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5537 "conf_parser.c"
    break;

  case 389: /* cluster_type_item: T_UNRESV  */
#line 1954 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5546 "conf_parser.c"
    break;

  case 390: /* cluster_type_item: T_LOCOPS  */
#line 1958 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5555 "conf_parser.c"
    break;

  case 391: /* cluster_type_item: T_ALL  */
#line 1962 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5564 "conf_parser.c"
    break;

  case 392: /* $@20: %empty  */
#line 1972 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5579 "conf_parser.c"
    break;

  case 393: /* connect_entry: CONNECT $@20 '{' connect_items '}' ';'  */
#line 1982 "conf_parser.y"
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
#line 5650 "conf_parser.c"
    break;

  case 412: /* connect_name: NAME '=' QSTRING ';'  */
#line 2068 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5659 "conf_parser.c"
    break;

  case 413: /* connect_host: HOST '=' QSTRING ';'  */
#line 2074 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5668 "conf_parser.c"
    break;

  case 414: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 2080 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5677 "conf_parser.c"
    break;

  case 415: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 2086 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5686 "conf_parser.c"
    break;

  case 416: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2092 "conf_parser.y"
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
#line 5702 "conf_parser.c"
    break;

  case 417: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2105 "conf_parser.y"
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
#line 5718 "conf_parser.c"
    break;

  case 418: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2118 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5727 "conf_parser.c"
    break;

  case 419: /* connect_port: PORT '=' NUMBER ';'  */
#line 2124 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5736 "conf_parser.c"
    break;

  case 420: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2130 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5745 "conf_parser.c"
    break;

  case 421: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2134 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5754 "conf_parser.c"
    break;

  case 422: /* $@21: %empty  */
#line 2140 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5762 "conf_parser.c"
    break;

  case 426: /* connect_flags_item: AUTOCONN  */
#line 2146 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5771 "conf_parser.c"
    break;

  case 427: /* connect_flags_item: T_TLS  */
#line 2150 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5780 "conf_parser.c"
    break;

  case 428: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2156 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5794 "conf_parser.c"
    break;

  case 429: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2167 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5803 "conf_parser.c"
    break;

  case 430: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2173 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5812 "conf_parser.c"
    break;

  case 431: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2179 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5821 "conf_parser.c"
    break;

  case 432: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2185 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5835 "conf_parser.c"
    break;

  case 433: /* $@22: %empty  */
#line 2200 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5844 "conf_parser.c"
    break;

  case 434: /* kill_entry: KILL $@22 '{' kill_items '}' ';'  */
#line 2204 "conf_parser.y"
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
#line 5867 "conf_parser.c"
    break;

  case 440: /* kill_user: USER '=' QSTRING ';'  */
#line 2227 "conf_parser.y"
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
#line 5890 "conf_parser.c"
    break;

  case 441: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2247 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5899 "conf_parser.c"
    break;

  case 442: /* $@23: %empty  */
#line 2257 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5908 "conf_parser.c"
    break;

  case 443: /* deny_entry: DENY $@23 '{' deny_items '}' ';'  */
#line 2261 "conf_parser.y"
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
#line 5932 "conf_parser.c"
    break;

  case 449: /* deny_ip: IP '=' QSTRING ';'  */
#line 2285 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5941 "conf_parser.c"
    break;

  case 450: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2291 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5950 "conf_parser.c"
    break;

  case 456: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2306 "conf_parser.y"
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
#line 5967 "conf_parser.c"
    break;

  case 457: /* $@24: %empty  */
#line 2323 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5976 "conf_parser.c"
    break;

  case 458: /* gecos_entry: GECOS $@24 '{' gecos_items '}' ';'  */
#line 2327 "conf_parser.y"
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
#line 5996 "conf_parser.c"
    break;

  case 464: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2347 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 6005 "conf_parser.c"
    break;

  case 465: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2353 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 6014 "conf_parser.c"
    break;

  case 521: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2420 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 6022 "conf_parser.c"
    break;

  case 522: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2425 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 6030 "conf_parser.c"
    break;

  case 523: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2430 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 6038 "conf_parser.c"
    break;

  case 524: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2435 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 6046 "conf_parser.c"
    break;

  case 525: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2440 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 6054 "conf_parser.c"
    break;

  case 526: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2445 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 6062 "conf_parser.c"
    break;

  case 527: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2450 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 6070 "conf_parser.c"
    break;

  case 528: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2455 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6078 "conf_parser.c"
    break;

  case 529: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2460 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6086 "conf_parser.c"
    break;

  case 530: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2465 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6094 "conf_parser.c"
    break;

  case 531: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2470 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 6102 "conf_parser.c"
    break;

  case 532: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2475 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 6110 "conf_parser.c"
    break;

  case 533: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2480 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6118 "conf_parser.c"
    break;

  case 534: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2485 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6126 "conf_parser.c"
    break;

  case 535: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2490 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6134 "conf_parser.c"
    break;

  case 536: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2495 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6142 "conf_parser.c"
    break;

  case 537: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2500 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6150 "conf_parser.c"
    break;

  case 538: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2505 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6158 "conf_parser.c"
    break;

  case 539: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2510 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6166 "conf_parser.c"
    break;

  case 540: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2515 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6174 "conf_parser.c"
    break;

  case 541: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2520 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6182 "conf_parser.c"
    break;

  case 542: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2525 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 6190 "conf_parser.c"
    break;

  case 543: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2530 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 6198 "conf_parser.c"
    break;

  case 544: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2535 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 6206 "conf_parser.c"
    break;

  case 545: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2540 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6214 "conf_parser.c"
    break;

  case 546: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2545 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 6222 "conf_parser.c"
    break;

  case 547: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2550 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 6230 "conf_parser.c"
    break;

  case 548: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2555 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6238 "conf_parser.c"
    break;

  case 549: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2560 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6246 "conf_parser.c"
    break;

  case 550: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2565 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6254 "conf_parser.c"
    break;

  case 551: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2570 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6262 "conf_parser.c"
    break;

  case 552: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2575 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6270 "conf_parser.c"
    break;

  case 553: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2580 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6278 "conf_parser.c"
    break;

  case 554: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2585 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6286 "conf_parser.c"
    break;

  case 555: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2590 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6294 "conf_parser.c"
    break;

  case 556: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2595 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6302 "conf_parser.c"
    break;

  case 557: /* general_disable_auth: DISABLE_AUTH '=' TBOOL ';'  */
#line 2600 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6310 "conf_parser.c"
    break;

  case 558: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2605 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6318 "conf_parser.c"
    break;

  case 559: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2610 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6326 "conf_parser.c"
    break;

  case 560: /* $@25: %empty  */
#line 2615 "conf_parser.y"
{
  ConfigGeneral.oper_umodes = 0;
}
#line 6334 "conf_parser.c"
    break;

  case 564: /* umode_oitem: BOT  */
#line 2621 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_BOT;
}
#line 6342 "conf_parser.c"
    break;

  case 565: /* umode_oitem: T_CCONN  */
#line 2624 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6350 "conf_parser.c"
    break;

  case 566: /* umode_oitem: T_DEAF  */
#line 2627 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6358 "conf_parser.c"
    break;

  case 567: /* umode_oitem: T_FLOOD  */
#line 2630 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FLOOD;
}
#line 6366 "conf_parser.c"
    break;

  case 568: /* umode_oitem: HIDDEN  */
#line 2633 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6374 "conf_parser.c"
    break;

  case 569: /* umode_oitem: HIDE_CHANS  */
#line 2636 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6382 "conf_parser.c"
    break;

  case 570: /* umode_oitem: HIDE_IDLE  */
#line 2639 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6390 "conf_parser.c"
    break;

  case 571: /* umode_oitem: T_SKILL  */
#line 2642 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6398 "conf_parser.c"
    break;

  case 572: /* umode_oitem: T_NCHANGE  */
#line 2645 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6406 "conf_parser.c"
    break;

  case 573: /* umode_oitem: T_REJ  */
#line 2648 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6414 "conf_parser.c"
    break;

  case 574: /* umode_oitem: T_SPY  */
#line 2651 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6422 "conf_parser.c"
    break;

  case 575: /* umode_oitem: T_EXTERNAL  */
#line 2654 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6430 "conf_parser.c"
    break;

  case 576: /* umode_oitem: T_SERVNOTICE  */
#line 2657 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6438 "conf_parser.c"
    break;

  case 577: /* umode_oitem: T_INVISIBLE  */
#line 2660 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6446 "conf_parser.c"
    break;

  case 578: /* umode_oitem: T_WALLOP  */
#line 2663 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6454 "conf_parser.c"
    break;

  case 579: /* umode_oitem: T_SOFTCALLERID  */
#line 2666 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6462 "conf_parser.c"
    break;

  case 580: /* umode_oitem: T_CALLERID  */
#line 2669 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6470 "conf_parser.c"
    break;

  case 581: /* umode_oitem: T_LOCOPS  */
#line 2672 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6478 "conf_parser.c"
    break;

  case 582: /* umode_oitem: T_NONONREG  */
#line 2675 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6486 "conf_parser.c"
    break;

  case 583: /* umode_oitem: T_FARCONNECT  */
#line 2678 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6494 "conf_parser.c"
    break;

  case 584: /* umode_oitem: EXPIRATION  */
#line 2681 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6502 "conf_parser.c"
    break;

  case 585: /* umode_oitem: T_SECUREONLY  */
#line 2684 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SECUREONLY;
}
#line 6510 "conf_parser.c"
    break;

  case 586: /* $@26: %empty  */
#line 2689 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6518 "conf_parser.c"
    break;

  case 590: /* umode_item: BOT  */
#line 2695 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_BOT;
}
#line 6526 "conf_parser.c"
    break;

  case 591: /* umode_item: T_CCONN  */
#line 2698 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6534 "conf_parser.c"
    break;

  case 592: /* umode_item: T_DEAF  */
#line 2701 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6542 "conf_parser.c"
    break;

  case 593: /* umode_item: T_FLOOD  */
#line 2704 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FLOOD;
}
#line 6550 "conf_parser.c"
    break;

  case 594: /* umode_item: T_SKILL  */
#line 2707 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6558 "conf_parser.c"
    break;

  case 595: /* umode_item: HIDDEN  */
#line 2710 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6566 "conf_parser.c"
    break;

  case 596: /* umode_item: HIDE_CHANS  */
#line 2713 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDECHANS;
}
#line 6574 "conf_parser.c"
    break;

  case 597: /* umode_item: HIDE_IDLE  */
#line 2716 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDEIDLE;
}
#line 6582 "conf_parser.c"
    break;

  case 598: /* umode_item: T_NCHANGE  */
#line 2719 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6590 "conf_parser.c"
    break;

  case 599: /* umode_item: T_REJ  */
#line 2722 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6598 "conf_parser.c"
    break;

  case 600: /* umode_item: T_SPY  */
#line 2725 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6606 "conf_parser.c"
    break;

  case 601: /* umode_item: T_EXTERNAL  */
#line 2728 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6614 "conf_parser.c"
    break;

  case 602: /* umode_item: T_SERVNOTICE  */
#line 2731 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6622 "conf_parser.c"
    break;

  case 603: /* umode_item: T_INVISIBLE  */
#line 2734 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6630 "conf_parser.c"
    break;

  case 604: /* umode_item: T_WALLOP  */
#line 2737 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6638 "conf_parser.c"
    break;

  case 605: /* umode_item: T_SOFTCALLERID  */
#line 2740 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6646 "conf_parser.c"
    break;

  case 606: /* umode_item: T_CALLERID  */
#line 2743 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6654 "conf_parser.c"
    break;

  case 607: /* umode_item: T_LOCOPS  */
#line 2746 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6662 "conf_parser.c"
    break;

  case 608: /* umode_item: T_NONONREG  */
#line 2749 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6670 "conf_parser.c"
    break;

  case 609: /* umode_item: T_FARCONNECT  */
#line 2752 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6678 "conf_parser.c"
    break;

  case 610: /* umode_item: EXPIRATION  */
#line 2755 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6686 "conf_parser.c"
    break;

  case 611: /* umode_item: T_SECUREONLY  */
#line 2758 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SECUREONLY;
}
#line 6694 "conf_parser.c"
    break;

  case 612: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2763 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6702 "conf_parser.c"
    break;

  case 613: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2768 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6710 "conf_parser.c"
    break;

  case 614: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2773 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6718 "conf_parser.c"
    break;

  case 615: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2778 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6726 "conf_parser.c"
    break;

  case 616: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2783 "conf_parser.y"
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
#line 6746 "conf_parser.c"
    break;

  case 617: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2800 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6757 "conf_parser.c"
    break;

  case 618: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2808 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6768 "conf_parser.c"
    break;

  case 619: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2816 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6779 "conf_parser.c"
    break;

  case 620: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2824 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6792 "conf_parser.c"
    break;

  case 621: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2834 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6805 "conf_parser.c"
    break;

  case 643: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2869 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6813 "conf_parser.c"
    break;

  case 644: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2874 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6822 "conf_parser.c"
    break;

  case 645: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2880 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6831 "conf_parser.c"
    break;

  case 646: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2886 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6839 "conf_parser.c"
    break;

  case 647: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2891 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6847 "conf_parser.c"
    break;

  case 648: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2896 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6855 "conf_parser.c"
    break;

  case 649: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2901 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6863 "conf_parser.c"
    break;

  case 650: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2906 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6871 "conf_parser.c"
    break;

  case 651: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2911 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6879 "conf_parser.c"
    break;

  case 652: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2916 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6887 "conf_parser.c"
    break;

  case 653: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2921 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6895 "conf_parser.c"
    break;

  case 654: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2926 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6903 "conf_parser.c"
    break;

  case 655: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2931 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6911 "conf_parser.c"
    break;

  case 656: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2936 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6919 "conf_parser.c"
    break;

  case 657: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2941 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6927 "conf_parser.c"
    break;

  case 658: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2946 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6935 "conf_parser.c"
    break;

  case 659: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2951 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6943 "conf_parser.c"
    break;

  case 673: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2974 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6952 "conf_parser.c"
    break;

  case 674: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2980 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].number) > 0)
    {
      event_write_links_file.when = (yyvsp[-1].number);
      event_add(&event_write_links_file, NULL);
    }
    else
     event_delete(&event_write_links_file);

    ConfigServerHide.flatten_links_delay = (yyvsp[-1].number);
  }
}
#line 6971 "conf_parser.c"
    break;

  case 675: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2996 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6983 "conf_parser.c"
    break;

  case 676: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 3005 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6992 "conf_parser.c"
    break;

  case 677: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 3011 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 7001 "conf_parser.c"
    break;

  case 678: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 3017 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 7010 "conf_parser.c"
    break;

  case 679: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 3023 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 7022 "conf_parser.c"
    break;

  case 680: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 3032 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 7031 "conf_parser.c"
    break;

  case 681: /* serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'  */
#line 3038 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 7040 "conf_parser.c"
    break;


#line 7044 "conf_parser.c"

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

