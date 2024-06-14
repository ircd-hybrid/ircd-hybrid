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
#include "modules.h"
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


#line 177 "conf_parser.c"

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
    DISABLE_FAKE_CHANNELS = 297,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 298, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 299,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 300,         /* DLINE_MIN_CIDR6  */
    EMAIL = 301,                   /* EMAIL  */
    ENABLE_ADMIN = 302,            /* ENABLE_ADMIN  */
    ENABLE_EXTBANS = 303,          /* ENABLE_EXTBANS  */
    ENABLE_OWNER = 304,            /* ENABLE_OWNER  */
    ENCRYPTED = 305,               /* ENCRYPTED  */
    EXCEED_LIMIT = 306,            /* EXCEED_LIMIT  */
    EXEMPT = 307,                  /* EXEMPT  */
    EXPIRATION = 308,              /* EXPIRATION  */
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
    INVISIBLE_ON_CONNECT = 326,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 327,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 328,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 329,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 330,      /* INVITE_EXPIRE_TIME  */
    IP = 331,                      /* IP  */
    IRCD_AUTH = 332,               /* IRCD_AUTH  */
    IRCD_FLAGS = 333,              /* IRCD_FLAGS  */
    IRCD_SID = 334,                /* IRCD_SID  */
    JOIN = 335,                    /* JOIN  */
    KILL = 336,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 337,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 338,                   /* KLINE  */
    KLINE_EXEMPT = 339,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 340,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 341,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 342,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 343,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 344,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 345,               /* LEAF_MASK  */
    LISTEN = 346,                  /* LISTEN  */
    MASK = 347,                    /* MASK  */
    MASS = 348,                    /* MASS  */
    MAX_ACCEPT = 349,              /* MAX_ACCEPT  */
    MAX_BANS = 350,                /* MAX_BANS  */
    MAX_BANS_LARGE = 351,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 352,            /* MAX_CHANNELS  */
    MAX_IDLE = 353,                /* MAX_IDLE  */
    MAX_INVITES = 354,             /* MAX_INVITES  */
    MAX_MONITOR = 355,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 356,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 357,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 358,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 359,              /* MAX_NUMBER  */
    MAX_TARGETS = 360,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 361,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 362,                 /* MESSAGE  */
    MIN_IDLE = 363,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 364,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 365,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 366,                  /* MODULE  */
    MODULES = 367,                 /* MODULES  */
    MOTD = 368,                    /* MOTD  */
    NAME = 369,                    /* NAME  */
    NEED_IDENT = 370,              /* NEED_IDENT  */
    NEED_PASSWORD = 371,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 372,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 373,            /* NETWORK_NAME  */
    NICK = 374,                    /* NICK  */
    NO_OPER_FLOOD = 375,           /* NO_OPER_FLOOD  */
    NO_TILDE = 376,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 377,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 378,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 379,     /* NUMBER_PER_IP_LOCAL  */
    OPER_ONLY_UMODES = 380,        /* OPER_ONLY_UMODES  */
    OPER_UMODES = 381,             /* OPER_UMODES  */
    OPERATOR = 382,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 383,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 384,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 385,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 386,                /* PASSWORD  */
    PATH = 387,                    /* PATH  */
    PING_COOKIE = 388,             /* PING_COOKIE  */
    PING_TIME = 389,               /* PING_TIME  */
    PORT = 390,                    /* PORT  */
    RANDOM_IDLE = 391,             /* RANDOM_IDLE  */
    REASON = 392,                  /* REASON  */
    REDIRPORT = 393,               /* REDIRPORT  */
    REDIRSERV = 394,               /* REDIRSERV  */
    REHASH = 395,                  /* REHASH  */
    REMOTE = 396,                  /* REMOTE  */
    REMOTEBAN = 397,               /* REMOTEBAN  */
    RESV = 398,                    /* RESV  */
    RESV_EXEMPT = 399,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 400,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 401,                 /* SECONDS  */
    MINUTES = 402,                 /* MINUTES  */
    HOURS = 403,                   /* HOURS  */
    DAYS = 404,                    /* DAYS  */
    WEEKS = 405,                   /* WEEKS  */
    MONTHS = 406,                  /* MONTHS  */
    YEARS = 407,                   /* YEARS  */
    SEND_PASSWORD = 408,           /* SEND_PASSWORD  */
    SENDQ = 409,                   /* SENDQ  */
    SERVERHIDE = 410,              /* SERVERHIDE  */
    SERVERINFO = 411,              /* SERVERINFO  */
    SHORT_MOTD = 412,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 413,       /* SPECIALS_IN_IDENT  */
    SPOOF = 414,                   /* SPOOF  */
    SQUIT = 415,                   /* SQUIT  */
    STATS_E_DISABLED = 416,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 417,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 418,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 419,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 420,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 421,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 422,       /* STATS_U_OPER_ONLY  */
    T_ALL = 423,                   /* T_ALL  */
    T_BIND = 424,                  /* T_BIND  */
    T_CALLERID = 425,              /* T_CALLERID  */
    T_CCONN = 426,                 /* T_CCONN  */
    T_COMMAND = 427,               /* T_COMMAND  */
    T_CLUSTER = 428,               /* T_CLUSTER  */
    T_DEAF = 429,                  /* T_DEAF  */
    T_DEBUG = 430,                 /* T_DEBUG  */
    T_DLINE = 431,                 /* T_DLINE  */
    T_EXTERNAL = 432,              /* T_EXTERNAL  */
    T_FARCONNECT = 433,            /* T_FARCONNECT  */
    T_FILE = 434,                  /* T_FILE  */
    T_FLOOD = 435,                 /* T_FLOOD  */
    T_GLOBOPS = 436,               /* T_GLOBOPS  */
    T_INVISIBLE = 437,             /* T_INVISIBLE  */
    T_IPV4 = 438,                  /* T_IPV4  */
    T_IPV6 = 439,                  /* T_IPV6  */
    T_LOCOPS = 440,                /* T_LOCOPS  */
    T_LOG = 441,                   /* T_LOG  */
    T_NCHANGE = 442,               /* T_NCHANGE  */
    T_NONONREG = 443,              /* T_NONONREG  */
    T_OPME = 444,                  /* T_OPME  */
    T_PREPEND = 445,               /* T_PREPEND  */
    T_PSEUDO = 446,                /* T_PSEUDO  */
    T_RECVQ = 447,                 /* T_RECVQ  */
    T_REJ = 448,                   /* T_REJ  */
    T_RESTART = 449,               /* T_RESTART  */
    T_SECUREONLY = 450,            /* T_SECUREONLY  */
    T_SERVER = 451,                /* T_SERVER  */
    T_SERVICE = 452,               /* T_SERVICE  */
    T_SERVNOTICE = 453,            /* T_SERVNOTICE  */
    T_SET = 454,                   /* T_SET  */
    T_SHARED = 455,                /* T_SHARED  */
    T_SIZE = 456,                  /* T_SIZE  */
    T_SKILL = 457,                 /* T_SKILL  */
    T_SOFTCALLERID = 458,          /* T_SOFTCALLERID  */
    T_SPY = 459,                   /* T_SPY  */
    T_TARGET = 460,                /* T_TARGET  */
    T_TLS = 461,                   /* T_TLS  */
    T_UMODES = 462,                /* T_UMODES  */
    T_UNDLINE = 463,               /* T_UNDLINE  */
    T_UNLIMITED = 464,             /* T_UNLIMITED  */
    T_UNRESV = 465,                /* T_UNRESV  */
    T_UNXLINE = 466,               /* T_UNXLINE  */
    T_WALLOP = 467,                /* T_WALLOP  */
    T_WALLOPS = 468,               /* T_WALLOPS  */
    T_WEBIRC = 469,                /* T_WEBIRC  */
    TBOOL = 470,                   /* TBOOL  */
    THROTTLE_COUNT = 471,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 472,           /* THROTTLE_TIME  */
    TIMEOUT = 473,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 474,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 475, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 476,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 477,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 478, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 479,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 480, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 481,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 482,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 483,           /* TS_WARN_DELTA  */
    TWODOTS = 484,                 /* TWODOTS  */
    TYPE = 485,                    /* TYPE  */
    UNKLINE = 486,                 /* UNKLINE  */
    USE_LOGGING = 487,             /* USE_LOGGING  */
    USER = 488,                    /* USER  */
    VHOST = 489,                   /* VHOST  */
    VHOST6 = 490,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 491,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 492,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 493,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 494,                   /* XLINE  */
    XLINE_EXEMPT = 495,            /* XLINE_EXEMPT  */
    QSTRING = 496,                 /* QSTRING  */
    NUMBER = 497                   /* NUMBER  */
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
#define DISABLE_FAKE_CHANNELS 297
#define DISABLE_REMOTE_COMMANDS 298
#define DLINE_MIN_CIDR 299
#define DLINE_MIN_CIDR6 300
#define EMAIL 301
#define ENABLE_ADMIN 302
#define ENABLE_EXTBANS 303
#define ENABLE_OWNER 304
#define ENCRYPTED 305
#define EXCEED_LIMIT 306
#define EXEMPT 307
#define EXPIRATION 308
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
#define INVISIBLE_ON_CONNECT 326
#define INVITE_CLIENT_COUNT 327
#define INVITE_CLIENT_TIME 328
#define INVITE_DELAY_CHANNEL 329
#define INVITE_EXPIRE_TIME 330
#define IP 331
#define IRCD_AUTH 332
#define IRCD_FLAGS 333
#define IRCD_SID 334
#define JOIN 335
#define KILL 336
#define KILL_CHASE_TIME_LIMIT 337
#define KLINE 338
#define KLINE_EXEMPT 339
#define KLINE_MIN_CIDR 340
#define KLINE_MIN_CIDR6 341
#define KNOCK_CLIENT_COUNT 342
#define KNOCK_CLIENT_TIME 343
#define KNOCK_DELAY_CHANNEL 344
#define LEAF_MASK 345
#define LISTEN 346
#define MASK 347
#define MASS 348
#define MAX_ACCEPT 349
#define MAX_BANS 350
#define MAX_BANS_LARGE 351
#define MAX_CHANNELS 352
#define MAX_IDLE 353
#define MAX_INVITES 354
#define MAX_MONITOR 355
#define MAX_NICK_CHANGES 356
#define MAX_NICK_LENGTH 357
#define MAX_NICK_TIME 358
#define MAX_NUMBER 359
#define MAX_TARGETS 360
#define MAX_TOPIC_LENGTH 361
#define MESSAGE 362
#define MIN_IDLE 363
#define MIN_NONWILDCARD 364
#define MIN_NONWILDCARD_SIMPLE 365
#define MODULE 366
#define MODULES 367
#define MOTD 368
#define NAME 369
#define NEED_IDENT 370
#define NEED_PASSWORD 371
#define NETWORK_DESCRIPTION 372
#define NETWORK_NAME 373
#define NICK 374
#define NO_OPER_FLOOD 375
#define NO_TILDE 376
#define NUMBER_PER_CIDR 377
#define NUMBER_PER_IP_GLOBAL 378
#define NUMBER_PER_IP_LOCAL 379
#define OPER_ONLY_UMODES 380
#define OPER_UMODES 381
#define OPERATOR 382
#define OPERS_BYPASS_CALLERID 383
#define PACE_WAIT 384
#define PACE_WAIT_SIMPLE 385
#define PASSWORD 386
#define PATH 387
#define PING_COOKIE 388
#define PING_TIME 389
#define PORT 390
#define RANDOM_IDLE 391
#define REASON 392
#define REDIRPORT 393
#define REDIRSERV 394
#define REHASH 395
#define REMOTE 396
#define REMOTEBAN 397
#define RESV 398
#define RESV_EXEMPT 399
#define RSA_PRIVATE_KEY_FILE 400
#define SECONDS 401
#define MINUTES 402
#define HOURS 403
#define DAYS 404
#define WEEKS 405
#define MONTHS 406
#define YEARS 407
#define SEND_PASSWORD 408
#define SENDQ 409
#define SERVERHIDE 410
#define SERVERINFO 411
#define SHORT_MOTD 412
#define SPECIALS_IN_IDENT 413
#define SPOOF 414
#define SQUIT 415
#define STATS_E_DISABLED 416
#define STATS_I_OPER_ONLY 417
#define STATS_K_OPER_ONLY 418
#define STATS_M_OPER_ONLY 419
#define STATS_O_OPER_ONLY 420
#define STATS_P_OPER_ONLY 421
#define STATS_U_OPER_ONLY 422
#define T_ALL 423
#define T_BIND 424
#define T_CALLERID 425
#define T_CCONN 426
#define T_COMMAND 427
#define T_CLUSTER 428
#define T_DEAF 429
#define T_DEBUG 430
#define T_DLINE 431
#define T_EXTERNAL 432
#define T_FARCONNECT 433
#define T_FILE 434
#define T_FLOOD 435
#define T_GLOBOPS 436
#define T_INVISIBLE 437
#define T_IPV4 438
#define T_IPV6 439
#define T_LOCOPS 440
#define T_LOG 441
#define T_NCHANGE 442
#define T_NONONREG 443
#define T_OPME 444
#define T_PREPEND 445
#define T_PSEUDO 446
#define T_RECVQ 447
#define T_REJ 448
#define T_RESTART 449
#define T_SECUREONLY 450
#define T_SERVER 451
#define T_SERVICE 452
#define T_SERVNOTICE 453
#define T_SET 454
#define T_SHARED 455
#define T_SIZE 456
#define T_SKILL 457
#define T_SOFTCALLERID 458
#define T_SPY 459
#define T_TARGET 460
#define T_TLS 461
#define T_UMODES 462
#define T_UNDLINE 463
#define T_UNLIMITED 464
#define T_UNRESV 465
#define T_UNXLINE 466
#define T_WALLOP 467
#define T_WALLOPS 468
#define T_WEBIRC 469
#define TBOOL 470
#define THROTTLE_COUNT 471
#define THROTTLE_TIME 472
#define TIMEOUT 473
#define TLS_CERTIFICATE_FILE 474
#define TLS_CERTIFICATE_FINGERPRINT 475
#define TLS_CIPHER_LIST 476
#define TLS_CIPHER_SUITES 477
#define TLS_CONNECTION_REQUIRED 478
#define TLS_DH_PARAM_FILE 479
#define TLS_MESSAGE_DIGEST_ALGORITHM 480
#define TLS_SUPPORTED_GROUPS 481
#define TS_MAX_DELTA 482
#define TS_WARN_DELTA 483
#define TWODOTS 484
#define TYPE 485
#define UNKLINE 486
#define USE_LOGGING 487
#define USER 488
#define VHOST 489
#define VHOST6 490
#define WARN_NO_CONNECT_BLOCK 491
#define WHOIS 492
#define WHOWAS_HISTORY_LENGTH 493
#define XLINE 494
#define XLINE_EXEMPT 495
#define QSTRING 496
#define NUMBER 497

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 719 "conf_parser.c"

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
  YYSYMBOL_DISABLE_FAKE_CHANNELS = 42,     /* DISABLE_FAKE_CHANNELS  */
  YYSYMBOL_DISABLE_REMOTE_COMMANDS = 43,   /* DISABLE_REMOTE_COMMANDS  */
  YYSYMBOL_DLINE_MIN_CIDR = 44,            /* DLINE_MIN_CIDR  */
  YYSYMBOL_DLINE_MIN_CIDR6 = 45,           /* DLINE_MIN_CIDR6  */
  YYSYMBOL_EMAIL = 46,                     /* EMAIL  */
  YYSYMBOL_ENABLE_ADMIN = 47,              /* ENABLE_ADMIN  */
  YYSYMBOL_ENABLE_EXTBANS = 48,            /* ENABLE_EXTBANS  */
  YYSYMBOL_ENABLE_OWNER = 49,              /* ENABLE_OWNER  */
  YYSYMBOL_ENCRYPTED = 50,                 /* ENCRYPTED  */
  YYSYMBOL_EXCEED_LIMIT = 51,              /* EXCEED_LIMIT  */
  YYSYMBOL_EXEMPT = 52,                    /* EXEMPT  */
  YYSYMBOL_EXPIRATION = 53,                /* EXPIRATION  */
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
  YYSYMBOL_INVISIBLE_ON_CONNECT = 71,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 72,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 73,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 74,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 75,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 76,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 77,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 78,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 79,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 80,                      /* JOIN  */
  YYSYMBOL_KILL = 81,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 82,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 83,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 84,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 85,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 86,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 87,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 88,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 89,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 90,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 91,                    /* LISTEN  */
  YYSYMBOL_MASK = 92,                      /* MASK  */
  YYSYMBOL_MASS = 93,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 94,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_BANS = 95,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 96,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 97,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 98,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 99,               /* MAX_INVITES  */
  YYSYMBOL_MAX_MONITOR = 100,              /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 101,         /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 102,          /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 103,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 104,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 105,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 106,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 107,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 108,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 109,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 110,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 111,                   /* MODULE  */
  YYSYMBOL_MODULES = 112,                  /* MODULES  */
  YYSYMBOL_MOTD = 113,                     /* MOTD  */
  YYSYMBOL_NAME = 114,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 115,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 116,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 117,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 118,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 119,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 120,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 121,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 122,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 123,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 124,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_ONLY_UMODES = 125,         /* OPER_ONLY_UMODES  */
  YYSYMBOL_OPER_UMODES = 126,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 127,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 128,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 129,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 130,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 131,                 /* PASSWORD  */
  YYSYMBOL_PATH = 132,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 133,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 134,                /* PING_TIME  */
  YYSYMBOL_PORT = 135,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 136,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 137,                   /* REASON  */
  YYSYMBOL_REDIRPORT = 138,                /* REDIRPORT  */
  YYSYMBOL_REDIRSERV = 139,                /* REDIRSERV  */
  YYSYMBOL_REHASH = 140,                   /* REHASH  */
  YYSYMBOL_REMOTE = 141,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 142,                /* REMOTEBAN  */
  YYSYMBOL_RESV = 143,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 144,              /* RESV_EXEMPT  */
  YYSYMBOL_RSA_PRIVATE_KEY_FILE = 145,     /* RSA_PRIVATE_KEY_FILE  */
  YYSYMBOL_SECONDS = 146,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 147,                  /* MINUTES  */
  YYSYMBOL_HOURS = 148,                    /* HOURS  */
  YYSYMBOL_DAYS = 149,                     /* DAYS  */
  YYSYMBOL_WEEKS = 150,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 151,                   /* MONTHS  */
  YYSYMBOL_YEARS = 152,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 153,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 154,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 155,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 156,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 157,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 158,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 159,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 160,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 161,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_I_OPER_ONLY = 162,        /* STATS_I_OPER_ONLY  */
  YYSYMBOL_STATS_K_OPER_ONLY = 163,        /* STATS_K_OPER_ONLY  */
  YYSYMBOL_STATS_M_OPER_ONLY = 164,        /* STATS_M_OPER_ONLY  */
  YYSYMBOL_STATS_O_OPER_ONLY = 165,        /* STATS_O_OPER_ONLY  */
  YYSYMBOL_STATS_P_OPER_ONLY = 166,        /* STATS_P_OPER_ONLY  */
  YYSYMBOL_STATS_U_OPER_ONLY = 167,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 168,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 169,                   /* T_BIND  */
  YYSYMBOL_T_CALLERID = 170,               /* T_CALLERID  */
  YYSYMBOL_T_CCONN = 171,                  /* T_CCONN  */
  YYSYMBOL_T_COMMAND = 172,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 173,                /* T_CLUSTER  */
  YYSYMBOL_T_DEAF = 174,                   /* T_DEAF  */
  YYSYMBOL_T_DEBUG = 175,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 176,                  /* T_DLINE  */
  YYSYMBOL_T_EXTERNAL = 177,               /* T_EXTERNAL  */
  YYSYMBOL_T_FARCONNECT = 178,             /* T_FARCONNECT  */
  YYSYMBOL_T_FILE = 179,                   /* T_FILE  */
  YYSYMBOL_T_FLOOD = 180,                  /* T_FLOOD  */
  YYSYMBOL_T_GLOBOPS = 181,                /* T_GLOBOPS  */
  YYSYMBOL_T_INVISIBLE = 182,              /* T_INVISIBLE  */
  YYSYMBOL_T_IPV4 = 183,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 184,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 185,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 186,                    /* T_LOG  */
  YYSYMBOL_T_NCHANGE = 187,                /* T_NCHANGE  */
  YYSYMBOL_T_NONONREG = 188,               /* T_NONONREG  */
  YYSYMBOL_T_OPME = 189,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 190,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 191,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 192,                  /* T_RECVQ  */
  YYSYMBOL_T_REJ = 193,                    /* T_REJ  */
  YYSYMBOL_T_RESTART = 194,                /* T_RESTART  */
  YYSYMBOL_T_SECUREONLY = 195,             /* T_SECUREONLY  */
  YYSYMBOL_T_SERVER = 196,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 197,                /* T_SERVICE  */
  YYSYMBOL_T_SERVNOTICE = 198,             /* T_SERVNOTICE  */
  YYSYMBOL_T_SET = 199,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 200,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 201,                   /* T_SIZE  */
  YYSYMBOL_T_SKILL = 202,                  /* T_SKILL  */
  YYSYMBOL_T_SOFTCALLERID = 203,           /* T_SOFTCALLERID  */
  YYSYMBOL_T_SPY = 204,                    /* T_SPY  */
  YYSYMBOL_T_TARGET = 205,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 206,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 207,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 208,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 209,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 210,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 211,                /* T_UNXLINE  */
  YYSYMBOL_T_WALLOP = 212,                 /* T_WALLOP  */
  YYSYMBOL_T_WALLOPS = 213,                /* T_WALLOPS  */
  YYSYMBOL_T_WEBIRC = 214,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 215,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 216,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 217,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 218,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 219,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 220, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 221,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 222,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 223,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 224,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 225, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 226,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 227,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 228,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 229,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 230,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 231,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 232,              /* USE_LOGGING  */
  YYSYMBOL_USER = 233,                     /* USER  */
  YYSYMBOL_VHOST = 234,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 235,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 236,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 237,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 238,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 239,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 240,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 241,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 242,                   /* NUMBER  */
  YYSYMBOL_243_ = 243,                     /* ';'  */
  YYSYMBOL_244_ = 244,                     /* '}'  */
  YYSYMBOL_245_ = 245,                     /* '{'  */
  YYSYMBOL_246_ = 246,                     /* '='  */
  YYSYMBOL_247_ = 247,                     /* ','  */
  YYSYMBOL_248_ = 248,                     /* ':'  */
  YYSYMBOL_YYACCEPT = 249,                 /* $accept  */
  YYSYMBOL_conf = 250,                     /* conf  */
  YYSYMBOL_conf_item = 251,                /* conf_item  */
  YYSYMBOL_timespec_ = 252,                /* timespec_  */
  YYSYMBOL_timespec = 253,                 /* timespec  */
  YYSYMBOL_sizespec_ = 254,                /* sizespec_  */
  YYSYMBOL_sizespec = 255,                 /* sizespec  */
  YYSYMBOL_modules_entry = 256,            /* modules_entry  */
  YYSYMBOL_modules_items = 257,            /* modules_items  */
  YYSYMBOL_modules_item = 258,             /* modules_item  */
  YYSYMBOL_modules_module = 259,           /* modules_module  */
  YYSYMBOL_modules_path = 260,             /* modules_path  */
  YYSYMBOL_serverinfo_entry = 261,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 262,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 263,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 264, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 265, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 266, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 267, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 268, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 269, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 270, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 271,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 272,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 273,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 274,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 275, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 276, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 277, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 278, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_hub = 279,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 280,              /* admin_entry  */
  YYSYMBOL_admin_items = 281,              /* admin_items  */
  YYSYMBOL_admin_item = 282,               /* admin_item  */
  YYSYMBOL_admin_name = 283,               /* admin_name  */
  YYSYMBOL_admin_email = 284,              /* admin_email  */
  YYSYMBOL_admin_description = 285,        /* admin_description  */
  YYSYMBOL_motd_entry = 286,               /* motd_entry  */
  YYSYMBOL_287_1 = 287,                    /* $@1  */
  YYSYMBOL_motd_items = 288,               /* motd_items  */
  YYSYMBOL_motd_item = 289,                /* motd_item  */
  YYSYMBOL_motd_mask = 290,                /* motd_mask  */
  YYSYMBOL_motd_file = 291,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 292,             /* pseudo_entry  */
  YYSYMBOL_293_2 = 293,                    /* $@2  */
  YYSYMBOL_pseudo_items = 294,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 295,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 296,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 297,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 298,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 299,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 300,            /* logging_entry  */
  YYSYMBOL_logging_items = 301,            /* logging_items  */
  YYSYMBOL_logging_item = 302,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 303,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 304,       /* logging_file_entry  */
  YYSYMBOL_305_3 = 305,                    /* $@3  */
  YYSYMBOL_logging_file_items = 306,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 307,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 308,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 309,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 310,        /* logging_file_type  */
  YYSYMBOL_311_4 = 311,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 312,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 313,               /* oper_entry  */
  YYSYMBOL_314_5 = 314,                    /* $@5  */
  YYSYMBOL_oper_items = 315,               /* oper_items  */
  YYSYMBOL_oper_item = 316,                /* oper_item  */
  YYSYMBOL_oper_name = 317,                /* oper_name  */
  YYSYMBOL_oper_user = 318,                /* oper_user  */
  YYSYMBOL_oper_password = 319,            /* oper_password  */
  YYSYMBOL_oper_whois = 320,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 321,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 322, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 323, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 324,               /* oper_class  */
  YYSYMBOL_oper_umodes = 325,              /* oper_umodes  */
  YYSYMBOL_326_6 = 326,                    /* $@6  */
  YYSYMBOL_oper_umodes_items = 327,        /* oper_umodes_items  */
  YYSYMBOL_oper_umodes_item = 328,         /* oper_umodes_item  */
  YYSYMBOL_oper_flags = 329,               /* oper_flags  */
  YYSYMBOL_330_7 = 330,                    /* $@7  */
  YYSYMBOL_oper_flags_items = 331,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 332,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 333,              /* class_entry  */
  YYSYMBOL_334_8 = 334,                    /* $@8  */
  YYSYMBOL_class_items = 335,              /* class_items  */
  YYSYMBOL_class_item = 336,               /* class_item  */
  YYSYMBOL_class_name = 337,               /* class_name  */
  YYSYMBOL_class_ping_time = 338,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 339, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 340, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 341,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 342,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 343,         /* class_max_number  */
  YYSYMBOL_class_sendq = 344,              /* class_sendq  */
  YYSYMBOL_class_recvq = 345,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 346,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 347,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 348,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 349,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 350,           /* class_max_idle  */
  YYSYMBOL_class_flags = 351,              /* class_flags  */
  YYSYMBOL_352_9 = 352,                    /* $@9  */
  YYSYMBOL_class_flags_items = 353,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 354,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 355,             /* listen_entry  */
  YYSYMBOL_356_10 = 356,                   /* $@10  */
  YYSYMBOL_listen_flags = 357,             /* listen_flags  */
  YYSYMBOL_358_11 = 358,                   /* $@11  */
  YYSYMBOL_listen_flags_items = 359,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 360,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 361,             /* listen_items  */
  YYSYMBOL_listen_item = 362,              /* listen_item  */
  YYSYMBOL_listen_port = 363,              /* listen_port  */
  YYSYMBOL_364_12 = 364,                   /* $@12  */
  YYSYMBOL_port_items = 365,               /* port_items  */
  YYSYMBOL_port_item = 366,                /* port_item  */
  YYSYMBOL_listen_address = 367,           /* listen_address  */
  YYSYMBOL_listen_host = 368,              /* listen_host  */
  YYSYMBOL_auth_entry = 369,               /* auth_entry  */
  YYSYMBOL_370_13 = 370,                   /* $@13  */
  YYSYMBOL_auth_items = 371,               /* auth_items  */
  YYSYMBOL_auth_item = 372,                /* auth_item  */
  YYSYMBOL_auth_user = 373,                /* auth_user  */
  YYSYMBOL_auth_passwd = 374,              /* auth_passwd  */
  YYSYMBOL_auth_class = 375,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 376,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 377,               /* auth_flags  */
  YYSYMBOL_378_14 = 378,                   /* $@14  */
  YYSYMBOL_auth_flags_items = 379,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 380,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 381,               /* auth_spoof  */
  YYSYMBOL_auth_redir_serv = 382,          /* auth_redir_serv  */
  YYSYMBOL_auth_redir_port = 383,          /* auth_redir_port  */
  YYSYMBOL_resv_entry = 384,               /* resv_entry  */
  YYSYMBOL_385_15 = 385,                   /* $@15  */
  YYSYMBOL_resv_items = 386,               /* resv_items  */
  YYSYMBOL_resv_item = 387,                /* resv_item  */
  YYSYMBOL_resv_mask = 388,                /* resv_mask  */
  YYSYMBOL_resv_reason = 389,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 390,              /* resv_exempt  */
  YYSYMBOL_service_entry = 391,            /* service_entry  */
  YYSYMBOL_service_items = 392,            /* service_items  */
  YYSYMBOL_service_item = 393,             /* service_item  */
  YYSYMBOL_service_name = 394,             /* service_name  */
  YYSYMBOL_shared_entry = 395,             /* shared_entry  */
  YYSYMBOL_396_16 = 396,                   /* $@16  */
  YYSYMBOL_shared_items = 397,             /* shared_items  */
  YYSYMBOL_shared_item = 398,              /* shared_item  */
  YYSYMBOL_shared_name = 399,              /* shared_name  */
  YYSYMBOL_shared_user = 400,              /* shared_user  */
  YYSYMBOL_shared_type = 401,              /* shared_type  */
  YYSYMBOL_402_17 = 402,                   /* $@17  */
  YYSYMBOL_shared_types = 403,             /* shared_types  */
  YYSYMBOL_shared_type_item = 404,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 405,            /* cluster_entry  */
  YYSYMBOL_406_18 = 406,                   /* $@18  */
  YYSYMBOL_cluster_items = 407,            /* cluster_items  */
  YYSYMBOL_cluster_item = 408,             /* cluster_item  */
  YYSYMBOL_cluster_name = 409,             /* cluster_name  */
  YYSYMBOL_cluster_type = 410,             /* cluster_type  */
  YYSYMBOL_411_19 = 411,                   /* $@19  */
  YYSYMBOL_cluster_types = 412,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 413,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 414,            /* connect_entry  */
  YYSYMBOL_415_20 = 415,                   /* $@20  */
  YYSYMBOL_connect_items = 416,            /* connect_items  */
  YYSYMBOL_connect_item = 417,             /* connect_item  */
  YYSYMBOL_connect_name = 418,             /* connect_name  */
  YYSYMBOL_connect_host = 419,             /* connect_host  */
  YYSYMBOL_connect_timeout = 420,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 421,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 422,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 423,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 424, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 425,             /* connect_port  */
  YYSYMBOL_connect_aftype = 426,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 427,            /* connect_flags  */
  YYSYMBOL_428_21 = 428,                   /* $@21  */
  YYSYMBOL_connect_flags_items = 429,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 430,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 431,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 432,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 433,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 434,            /* connect_class  */
  YYSYMBOL_connect_tls_cipher_list = 435,  /* connect_tls_cipher_list  */
  YYSYMBOL_kill_entry = 436,               /* kill_entry  */
  YYSYMBOL_437_22 = 437,                   /* $@22  */
  YYSYMBOL_kill_items = 438,               /* kill_items  */
  YYSYMBOL_kill_item = 439,                /* kill_item  */
  YYSYMBOL_kill_user = 440,                /* kill_user  */
  YYSYMBOL_kill_reason = 441,              /* kill_reason  */
  YYSYMBOL_deny_entry = 442,               /* deny_entry  */
  YYSYMBOL_443_23 = 443,                   /* $@23  */
  YYSYMBOL_deny_items = 444,               /* deny_items  */
  YYSYMBOL_deny_item = 445,                /* deny_item  */
  YYSYMBOL_deny_ip = 446,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 447,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 448,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 449,             /* exempt_items  */
  YYSYMBOL_exempt_item = 450,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 451,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 452,              /* gecos_entry  */
  YYSYMBOL_453_24 = 453,                   /* $@24  */
  YYSYMBOL_gecos_items = 454,              /* gecos_items  */
  YYSYMBOL_gecos_item = 455,               /* gecos_item  */
  YYSYMBOL_gecos_name = 456,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 457,             /* gecos_reason  */
  YYSYMBOL_general_entry = 458,            /* general_entry  */
  YYSYMBOL_general_items = 459,            /* general_items  */
  YYSYMBOL_general_item = 460,             /* general_item  */
  YYSYMBOL_general_away_count = 461,       /* general_away_count  */
  YYSYMBOL_general_away_time = 462,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 463,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 464, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 465, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 466,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 467,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 468,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 469,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 470, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 471, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 472,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 473,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 474, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 475,       /* general_max_accept  */
  YYSYMBOL_general_anti_spam_exit_message_time = 476, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 477,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 478,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 479, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 480, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 481, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 482, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 483, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 484, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 485, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 486, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 487, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 488,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 489,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 490, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 491, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 492,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 493,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 494, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 495,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 496,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_auth = 497,     /* general_disable_auth  */
  YYSYMBOL_general_throttle_count = 498,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 499,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 500,      /* general_oper_umodes  */
  YYSYMBOL_501_25 = 501,                   /* $@25  */
  YYSYMBOL_umode_oitems = 502,             /* umode_oitems  */
  YYSYMBOL_umode_oitem = 503,              /* umode_oitem  */
  YYSYMBOL_general_oper_only_umodes = 504, /* general_oper_only_umodes  */
  YYSYMBOL_505_26 = 505,                   /* $@26  */
  YYSYMBOL_umode_items = 506,              /* umode_items  */
  YYSYMBOL_umode_item = 507,               /* umode_item  */
  YYSYMBOL_general_min_nonwildcard = 508,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 509, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 510, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 511, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 512,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 513, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 514, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 515,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 516,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 517,     /* general_cloak_suffix  */
  YYSYMBOL_channel_entry = 518,            /* channel_entry  */
  YYSYMBOL_channel_items = 519,            /* channel_items  */
  YYSYMBOL_channel_item = 520,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 521,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 522,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 523,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 524, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 525, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 526, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 527, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 528, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 529, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 530, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 531, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 532,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 533,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 534,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 535,   /* channel_max_bans_large  */
  YYSYMBOL_channel_default_join_flood_count = 536, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 537, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 538,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 539,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 540,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 541, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 542, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 543, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 544, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 545,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 546, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 547,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 548,        /* serverhide_hidden  */
  YYSYMBOL_serverhide_hide_server_ips = 549 /* serverhide_hide_server_ips  */
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
#define YYLAST   1366

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  249
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  301
/* YYNRULES -- Number of rules.  */
#define YYNRULES  682
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1353

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   497


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
       2,     2,     2,     2,   247,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   248,   243,
       2,   246,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   245,     2,   244,     2,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240,   241,   242
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   377,   377,   378,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   408,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   419,   419,
     420,   421,   422,   423,   430,   432,   432,   433,   433,   433,
     435,   441,   451,   453,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   473,   482,   491,   500,   509,   518,   527,   536,
     551,   566,   576,   590,   599,   622,   645,   668,   678,   680,
     680,   681,   682,   683,   684,   686,   695,   704,   718,   717,
     735,   735,   736,   736,   736,   738,   744,   755,   754,   773,
     773,   774,   774,   774,   774,   774,   776,   782,   788,   794,
     817,   818,   818,   820,   820,   821,   823,   830,   830,   843,
     844,   846,   846,   847,   847,   849,   857,   860,   866,   865,
     871,   875,   879,   883,   887,   891,   895,   899,   910,   909,
     973,   973,   974,   975,   976,   977,   978,   979,   980,   981,
     982,   983,   984,   986,   992,   998,  1004,  1010,  1021,  1027,
    1038,  1045,  1044,  1050,  1050,  1051,  1055,  1059,  1063,  1067,
    1071,  1075,  1079,  1083,  1087,  1091,  1095,  1099,  1103,  1107,
    1111,  1115,  1119,  1123,  1127,  1131,  1135,  1142,  1141,  1147,
    1147,  1148,  1152,  1156,  1160,  1164,  1168,  1172,  1176,  1180,
    1184,  1188,  1192,  1196,  1200,  1204,  1208,  1212,  1216,  1220,
    1224,  1228,  1232,  1236,  1240,  1244,  1248,  1252,  1256,  1260,
    1264,  1275,  1274,  1330,  1330,  1331,  1332,  1333,  1334,  1335,
    1336,  1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,
    1346,  1348,  1354,  1360,  1366,  1372,  1378,  1384,  1390,  1396,
    1403,  1409,  1415,  1421,  1430,  1440,  1439,  1445,  1445,  1446,
    1450,  1461,  1460,  1467,  1466,  1471,  1471,  1472,  1476,  1480,
    1484,  1488,  1494,  1494,  1495,  1495,  1495,  1495,  1495,  1497,
    1497,  1499,  1499,  1501,  1514,  1531,  1537,  1548,  1547,  1595,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1606,  1612,  1618,  1624,  1636,  1635,  1641,  1641,  1642,  1646,
    1650,  1654,  1658,  1662,  1666,  1670,  1674,  1680,  1694,  1703,
    1717,  1716,  1731,  1731,  1732,  1732,  1732,  1732,  1734,  1740,
    1746,  1756,  1758,  1758,  1759,  1759,  1761,  1778,  1777,  1800,
    1800,  1801,  1801,  1801,  1801,  1803,  1809,  1829,  1828,  1834,
    1834,  1835,  1839,  1843,  1847,  1851,  1855,  1859,  1863,  1867,
    1871,  1882,  1881,  1900,  1900,  1901,  1901,  1901,  1903,  1910,
    1909,  1915,  1915,  1916,  1920,  1924,  1928,  1932,  1936,  1940,
    1944,  1948,  1952,  1963,  1962,  2040,  2040,  2041,  2042,  2043,
    2044,  2045,  2046,  2047,  2048,  2049,  2050,  2051,  2052,  2053,
    2054,  2055,  2056,  2058,  2064,  2070,  2076,  2082,  2095,  2108,
    2114,  2120,  2124,  2131,  2130,  2135,  2135,  2136,  2140,  2146,
    2157,  2163,  2169,  2175,  2191,  2190,  2214,  2214,  2215,  2215,
    2215,  2217,  2237,  2248,  2247,  2272,  2272,  2273,  2273,  2273,
    2275,  2281,  2291,  2293,  2293,  2294,  2294,  2296,  2314,  2313,
    2334,  2334,  2335,  2335,  2335,  2337,  2343,  2353,  2355,  2355,
    2356,  2357,  2358,  2359,  2360,  2361,  2362,  2363,  2364,  2365,
    2366,  2367,  2368,  2369,  2370,  2371,  2372,  2373,  2374,  2375,
    2376,  2377,  2378,  2379,  2380,  2381,  2382,  2383,  2384,  2385,
    2386,  2387,  2388,  2389,  2390,  2391,  2392,  2393,  2394,  2395,
    2396,  2397,  2398,  2399,  2400,  2401,  2402,  2403,  2404,  2405,
    2406,  2407,  2410,  2415,  2420,  2425,  2430,  2435,  2440,  2445,
    2450,  2455,  2460,  2465,  2470,  2475,  2480,  2485,  2490,  2495,
    2500,  2505,  2510,  2515,  2520,  2525,  2530,  2535,  2540,  2545,
    2550,  2555,  2560,  2565,  2570,  2575,  2580,  2585,  2590,  2595,
    2600,  2606,  2605,  2610,  2610,  2611,  2614,  2617,  2620,  2623,
    2626,  2629,  2632,  2635,  2638,  2641,  2644,  2647,  2650,  2653,
    2656,  2659,  2662,  2665,  2668,  2671,  2674,  2680,  2679,  2684,
    2684,  2685,  2688,  2691,  2694,  2697,  2700,  2703,  2706,  2709,
    2712,  2715,  2718,  2721,  2724,  2727,  2730,  2733,  2736,  2739,
    2742,  2745,  2748,  2753,  2758,  2763,  2768,  2773,  2790,  2798,
    2806,  2814,  2824,  2837,  2839,  2839,  2840,  2841,  2842,  2843,
    2844,  2845,  2846,  2847,  2848,  2849,  2850,  2851,  2852,  2853,
    2854,  2855,  2856,  2857,  2859,  2864,  2870,  2876,  2881,  2886,
    2891,  2896,  2901,  2906,  2911,  2916,  2921,  2926,  2931,  2936,
    2941,  2950,  2952,  2952,  2953,  2954,  2955,  2956,  2957,  2958,
    2959,  2960,  2961,  2962,  2964,  2970,  2986,  2995,  3001,  3007,
    3013,  3022,  3028
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
  "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME",
  "DEFAULT_JOIN_FLOOD_COUNT", "DEFAULT_JOIN_FLOOD_TIME",
  "DEFAULT_MAX_CLIENTS", "DEFER", "DENY", "DESCRIPTION", "DIE",
  "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS",
  "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6", "EMAIL", "ENABLE_ADMIN",
  "ENABLE_EXTBANS", "ENABLE_OWNER", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "EXPIRATION", "FAILED_OPER_NOTICE", "FLATTEN_LINKS",
  "FLATTEN_LINKS_DELAY", "FLATTEN_LINKS_FILE", "GECOS", "GENERAL",
  "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
  "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS", "HIDE_SERVERS",
  "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK", "INVISIBLE_ON_CONNECT",
  "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME", "INVITE_DELAY_CHANNEL",
  "INVITE_EXPIRE_TIME", "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID",
  "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6", "KNOCK_CLIENT_COUNT",
  "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LISTEN",
  "MASK", "MASS", "MAX_ACCEPT", "MAX_BANS", "MAX_BANS_LARGE",
  "MAX_CHANNELS", "MAX_IDLE", "MAX_INVITES", "MAX_MONITOR",
  "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MESSAGE", "MIN_IDLE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD",
  "NAME", "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESCRIPTION",
  "NETWORK_NAME", "NICK", "NO_OPER_FLOOD", "NO_TILDE", "NUMBER_PER_CIDR",
  "NUMBER_PER_IP_GLOBAL", "NUMBER_PER_IP_LOCAL", "OPER_ONLY_UMODES",
  "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID", "PACE_WAIT",
  "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME",
  "PORT", "RANDOM_IDLE", "REASON", "REDIRPORT", "REDIRSERV", "REHASH",
  "REMOTE", "REMOTEBAN", "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS",
  "SEND_PASSWORD", "SENDQ", "SERVERHIDE", "SERVERINFO", "SHORT_MOTD",
  "SPECIALS_IN_IDENT", "SPOOF", "SQUIT", "STATS_E_DISABLED",
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
  "';'", "'}'", "'{'", "'='", "','", "':'", "$accept", "conf", "conf_item",
  "timespec_", "timespec", "sizespec_", "sizespec", "modules_entry",
  "modules_items", "modules_item", "modules_module", "modules_path",
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

#define YYPACT_NINF (-1050)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1050,   862, -1050,  -209,  -242,  -213, -1050, -1050, -1050,  -194,
   -1050,  -189, -1050, -1050, -1050,  -158, -1050, -1050, -1050,  -150,
    -140, -1050,  -120, -1050,  -119, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050,   342,   977,  -114,  -113,  -107,    21,   -90,   422,   -79,
     -72,   -56,    79,   -27,   -24,   -18,   626,   502,   -11,     3,
      -8,    43,    11,    12,    29,    42,    49,     4, -1050, -1050,
   -1050, -1050, -1050,    52,    60,    64,    65,    70,    80,    81,
      98,   100,   107,   115,   119,   121,   122,   123,   125,   127,
     111, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,   868,
     598,    27, -1050,   129,    25, -1050, -1050,    89, -1050,   130,
     131,   132,   136,   138,   139,   143,   146,   148,   149,   152,
     154,   157,   158,   159,   161,   162,   165,   166,   168,   169,
     170,   172,   174,   175,   176,   178,   179,   180,   181, -1050,
   -1050,   184,   187,   190,   192,   194,   206,   211,   214,   215,
     222,   223,   224,   231,   232,   234,   235,   236,   237,   238,
      14, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050,   312,    51,   323,    23,   240,   241,    24,
   -1050, -1050, -1050,    18,   252,   186, -1050,   245,   248,   250,
     251,   253,   254,   255,   260,   263,    10, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050,    82,   264,   265,
     266,   267,   271,   272,   273,   274,   275,   278,   282,   283,
     284,   287,   288,   289,   126, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050,     6,    92,   290,    30, -1050, -1050, -1050,   262,
     167, -1050,   291,    77, -1050, -1050,    56, -1050,   298,   302,
     303,   120, -1050,   177,   304,   325,   334,   338,   339,   321,
     304,   304,   304,   322,   304,   304,   326,   328,   331,   332,
     333, -1050,   335,   319,   329,   336, -1050,   344,   345,   346,
     348,   349,   350,   354,   361,   371,   375,   376,   195, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050,   380,   378,   379,   384,   385,
     386,   387, -1050,   388,   389,   390,   391,   394,   395,   396,
     397,   244, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,   399,
     409,    26, -1050, -1050, -1050,   415,   414, -1050, -1050,   413,
     417,    15, -1050, -1050, -1050,   362,   304,   419,   304,   304,
     450,   428,   430,   431,   433,   436,   463,   437,   304,   469,
     447,   448,   480,   483,   304,   458,   460,   461,   462,   465,
     304,   466,   467,   468,   490,   472,   473,   496,   304,   304,
     499,   505,   487,   507,   515,   516,   517,   519,   520,   521,
     495,   304,   304,   304,   523,   497,   498, -1050,   501,   494,
     500, -1050,   503,   508,   509,   510,   511,    63, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,   512,   513,
      32, -1050, -1050, -1050,   504,   514,   518, -1050,   524, -1050,
      13, -1050, -1050, -1050, -1050, -1050,   522,   525,   529, -1050,
     531,   534,   535,    41, -1050, -1050, -1050,   532,   536,   537,
   -1050,   539,   541, -1050,   542,   544,   545,   546,   173, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
     553,   551,   552,   554,    17, -1050, -1050, -1050, -1050,   527,
     530,   304,   558,   533,   560,   562,   587,   589,   563, -1050,
   -1050,   565,   564,   593,   568,   569,   570,   572,   573,   574,
     576,   579,   580,   581,   584,   585,   588,   567, -1050,   594,
     582, -1050,    53, -1050, -1050, -1050, -1050,   617,   596, -1050,
     597,   600,   590,   599,   601,   603,   110, -1050, -1050, -1050,
   -1050, -1050,   609,   610, -1050,   611,   612, -1050,   625,    47,
   -1050, -1050, -1050, -1050,   630,   631,   633, -1050,   637,   410,
     638,   641,   646,   647,   652,   654,   656,   658,   660,   661,
     662,   663,   664,   665,   666,   667, -1050, -1050,   592,   602,
     304,   650,   669,   304,   671,   304,   674,   675,   676,   680,
     304,   681,   681,   673, -1050, -1050,   683,   -91,   684,   711,
     686,   687,   685,   688,   689,   691,   693,   694,   304,   695,
     697,   698, -1050,   699,   701,   704, -1050,   705, -1050,   708,
     709,   712, -1050,   713,   714,   715,   716,   717,   719,   720,
     721,   724,   725,   726,   727,   728,   730,   738,   740,   742,
     745,   750,   751,   752,   753,   754,   755,   756,   758,   760,
     761,   763,   766,   591,   653,   767,   770,   771,   773,   777,
     778,   780,   784,   785,   786,   787,   788,   789,   790,   791,
     793,   794,   795,   796, -1050, -1050,   710,   825,   797,   800,
     802,   801,   804,   805,   811, -1050,   806,   814,   813, -1050,
   -1050,   816,   817,   815,   821,   824, -1050,   826,   827, -1050,
   -1050,   830,   834,   835, -1050, -1050,   836,   853,   833,   839,
     840,   837,   841,   869,   844,   845,   846, -1050, -1050,   847,
     849,   850,   851, -1050,   852,   854,   855,   856,   857,   858,
     859,   860,   861, -1050,   863,   864,   865,   866,   867,   870,
     871,   872,   873,   874,   875,   876,   877,   878,   879,   880,
   -1050, -1050,   883,   881,   882, -1050,   885, -1050,    78, -1050,
     888,   889,   890,   891,   892, -1050,   893, -1050, -1050,   896,
     887,   897,   898, -1050, -1050, -1050, -1050, -1050,   304,   304,
     304,   304,   304,   304,   304, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050,   899,   900,   901,   -15,   902,   903,   904,
     905,   906,   907,   908,   909,   910,    48,   911,   912, -1050,
     913,   914,   915,   916,   917,   918,   919,    -2,   920,   921,
     922,   923,   924,   925,   926,   927, -1050,   928,   929, -1050,
   -1050,   930,   931, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050,  -161, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
    -159, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050,   932,   933,   358,   934,   935,   936,   937,   938, -1050,
     939,   940, -1050,   941,   942,   299,   703,   943, -1050, -1050,
   -1050, -1050,   944,   945, -1050,   946,   948,   486,   949,   950,
     690,   951,   952,   953,   954, -1050,   955,   956,   957, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050,   958,   769, -1050, -1050,   959,
     894,   960, -1050,    16, -1050, -1050, -1050, -1050,   961,   962,
     964,   965, -1050, -1050,   966,   776,   967, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
    -149, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050,   681,   681,   681, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050,   -31, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050,   591, -1050,   653, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050,   -28, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050,   -14, -1050,   884,   821,   968, -1050, -1050, -1050,
   -1050, -1050, -1050,   848, -1050,   886,   969, -1050,   970, -1050,
     971,   972, -1050, -1050,   973, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050,    20, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050,    58, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050,    94, -1050, -1050,   974,  -179,   976,   980,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050,   117, -1050, -1050, -1050,
     -15, -1050, -1050, -1050, -1050,    -2, -1050, -1050, -1050,   358,
   -1050,   299, -1050, -1050, -1050,   998,  1043,  1062,   994,  1069,
    1072,  1073, -1050,   486, -1050,   690, -1050,   769,   981,   982,
     983,   259, -1050, -1050,   776, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
     984, -1050, -1050
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   231,   393,   443,     0,
     458,     0,   297,   434,   271,     0,    98,   148,   330,     0,
       0,   371,     0,   107,     0,   347,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      93,    92,   643,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   625,   640,   641,   642,   639,   628,   629,   630,   631,
     632,   633,   634,   635,   636,   626,   627,   637,   638,     0,
       0,     0,   456,     0,     0,   454,   455,     0,   521,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   587,
     561,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   469,   470,   471,   513,   477,   514,   508,   509,   510,
     511,   481,   472,   473,   474,   475,   476,   478,   479,   480,
     482,   483,   512,   487,   488,   489,   490,   486,   485,   491,
     498,   499,   492,   493,   494,   484,   496,   506,   507,   504,
     505,   497,   495,   502,   503,   500,   501,   515,   516,   517,
     518,   519,   520,     0,     0,     0,     0,     0,     0,     0,
      46,    47,    48,     0,     0,     0,   673,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   663,   664,   665,
     666,   667,   668,   669,   671,   670,   672,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    67,    65,    63,    68,
      69,    70,    64,    55,    66,    57,    58,    59,    60,    61,
      62,    56,     0,     0,     0,     0,   122,   123,   124,     0,
       0,   345,     0,     0,   343,   344,     0,    94,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   624,     0,     0,     0,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   238,   240,   241,   242,   243,   244,   245,   246,   236,
     237,   239,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,   423,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   396,   397,   398,   399,   400,   401,   402,   403,
     405,   404,   407,   411,   408,   409,   410,   406,   449,     0,
       0,     0,   446,   447,   448,     0,     0,   453,   464,     0,
       0,     0,   461,   462,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   468,     0,     0,
       0,   314,     0,     0,     0,     0,     0,     0,   300,   301,
     302,   303,   308,   304,   305,   306,   307,   440,     0,     0,
       0,   437,   438,   439,     0,     0,     0,   273,     0,   285,
       0,   283,   284,   286,   287,    49,     0,     0,     0,    45,
       0,     0,     0,     0,   101,   102,   103,     0,     0,     0,
     197,     0,     0,   171,     0,     0,     0,     0,     0,   151,
     152,   153,   154,   155,   158,   159,   160,   157,   156,   161,
       0,     0,     0,     0,     0,   333,   334,   335,   336,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   662,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,   379,     0,   374,   375,   376,   125,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,   110,   111,   113,
     112,   114,     0,     0,   342,     0,     0,   357,     0,     0,
     350,   351,   352,   353,     0,     0,     0,    88,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   623,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,   412,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   395,     0,     0,     0,   445,     0,   452,     0,
       0,     0,   460,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   467,   309,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   299,     0,     0,     0,   436,
     288,     0,     0,     0,     0,     0,   282,     0,     0,    44,
     104,     0,     0,     0,   100,   162,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   337,     0,
       0,     0,     0,   332,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   661,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,   377,     0,     0,     0,   373,     0,   120,     0,   115,
       0,     0,     0,     0,     0,   109,     0,   341,   354,     0,
       0,     0,     0,   349,    97,    96,    95,   659,    28,    28,
      28,    28,    28,    28,    28,    30,    29,   660,   647,   646,
     644,   645,   648,   649,   650,   651,   652,   653,   654,   657,
     658,   655,   656,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,   232,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   394,     0,     0,   444,
     457,     0,     0,   459,   533,   537,   522,   523,   550,   617,
     618,   619,   620,   621,   622,   526,   615,   616,   558,   527,
     528,   532,   540,   531,   529,   530,   536,   524,   535,   534,
     556,   613,   614,   554,   591,   611,   596,   597,   598,   607,
     592,   593,   602,   610,   594,   604,   608,   599,   609,   600,
     612,   603,   595,   606,   601,   605,     0,   590,   565,   585,
     569,   570,   571,   581,   566,   567,   576,   584,   568,   578,
     582,   573,   583,   574,   586,   577,   572,   580,   575,   579,
       0,   564,   551,   549,   552,   557,   553,   555,   542,   548,
     547,   543,   544,   545,   546,   559,   560,   539,   538,   541,
     525,     0,     0,     0,     0,     0,     0,     0,     0,   298,
       0,     0,   435,     0,     0,     0,   293,   289,   292,   272,
      50,    51,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   331,
     677,   674,   675,   676,   681,   680,   682,   678,   679,    84,
      81,    87,    80,    85,    86,    79,    83,    82,    73,    72,
      75,    76,    74,    77,    78,     0,     0,   372,   126,     0,
       0,     0,   138,     0,   130,   131,   133,   132,     0,     0,
       0,     0,   108,   346,     0,     0,     0,   348,    31,    32,
      33,    34,    35,    36,    37,   260,   261,   255,   270,   269,
       0,   268,   256,   264,   257,   263,   251,   262,   254,   253,
     252,    38,    38,    38,    40,    39,   258,   259,   418,   421,
     422,   432,   429,   414,   430,   427,   428,     0,   426,   431,
     413,   420,   417,   416,   415,   419,   433,   450,   451,   465,
     466,   588,     0,   562,     0,   312,   313,   322,   318,   319,
     321,   326,   323,   324,   325,   320,     0,   317,   311,   329,
     328,   327,   310,   442,   441,   296,   295,   280,   281,   278,
     279,   277,     0,   276,     0,     0,     0,   105,   106,   170,
     167,   217,   229,   204,   213,     0,   202,   207,     0,   223,
       0,   216,   221,   227,   206,   209,   218,   220,   224,   214,
     222,   210,   228,   212,   219,   208,   211,     0,   200,   163,
     165,   175,   195,   179,   180,   181,   191,   176,   177,   186,
     194,   178,   188,   192,   183,   193,   184,   196,   187,   182,
     190,   185,   189,     0,   174,   168,   169,   164,   166,   340,
     338,   339,   378,   383,   389,   392,   385,   391,   386,   390,
     388,   384,   387,     0,   382,   134,     0,     0,     0,     0,
     129,   117,   116,   118,   119,   355,   361,   367,   370,   363,
     369,   364,   368,   366,   362,   365,     0,   360,   356,   266,
       0,    41,    42,    43,   424,     0,   589,   563,   315,     0,
     274,     0,   294,   291,   290,     0,     0,     0,     0,     0,
       0,     0,   198,     0,   172,     0,   380,     0,     0,     0,
       0,     0,   128,   358,     0,   267,   425,   316,   275,   203,
     226,   201,   230,   225,   215,   205,   199,   173,   381,   135,
     137,   136,   146,   145,   141,   143,   147,   144,   140,   142,
       0,   359,   139
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1050, -1050, -1050,  -239,  -322, -1049,  -661, -1050, -1050,   989,
   -1050, -1050, -1050, -1050,   808, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050,  1016, -1050, -1050, -1050, -1050, -1050, -1050,
     706, -1050, -1050, -1050, -1050, -1050,   506, -1050, -1050, -1050,
   -1050, -1050, -1050,   947, -1050, -1050, -1050, -1050,    22, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050,   678, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,  -204,
   -1050, -1050, -1050,   -83, -1050, -1050, -1050,   895, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050,   -59, -1050, -1050, -1050, -1050,
   -1050,   -69, -1050,   723, -1050, -1050, -1050,    50, -1050, -1050,
   -1050, -1050, -1050,   747, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050,   -63, -1050, -1050, -1050, -1050, -1050, -1050,   692, -1050,
   -1050, -1050, -1050, -1050,   963, -1050, -1050, -1050, -1050,   618,
   -1050, -1050, -1050, -1050, -1050,   -86, -1050, -1050, -1050,   648,
   -1050, -1050, -1050, -1050,   -78, -1050, -1050, -1050,   975, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050,   -54, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
     743, -1050, -1050, -1050, -1050, -1050,   831, -1050, -1050, -1050,
   -1050,  1120, -1050, -1050, -1050, -1050,   828, -1050, -1050, -1050,
   -1050,  1065, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050,    93, -1050, -1050, -1050,    96, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050,  1150, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050,   995, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    26,   855,   856,  1124,  1125,    27,   239,   240,
     241,   242,    28,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,    29,    77,    78,    79,    80,    81,    30,    63,   523,
     524,   525,   526,    31,    70,   606,   607,   608,   609,   610,
     611,    32,   305,   306,   307,   308,   309,  1083,  1084,  1085,
    1086,  1087,  1268,  1350,    33,    64,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   781,  1243,  1244,
     549,   778,  1217,  1218,    34,    53,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   651,  1110,  1111,    35,    61,   509,   763,
    1182,  1183,   510,   511,   512,  1186,  1027,  1028,   513,   514,
      36,    59,   487,   488,   489,   490,   491,   492,   493,   748,
    1166,  1167,   494,   495,   496,    37,    65,   554,   555,   556,
     557,   558,    38,   313,   314,   315,    39,    72,   619,   620,
     621,   622,   623,   840,  1286,  1287,    40,    68,   592,   593,
     594,   595,   823,  1263,  1264,    41,    54,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   672,
    1137,  1138,   403,   404,   405,   406,   407,    42,    60,   500,
     501,   502,   503,    43,    55,   411,   412,   413,   414,    44,
     124,   125,   126,    45,    57,   421,   422,   423,   424,    46,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   456,   990,   991,   222,   455,   966,   967,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    47,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    48,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     887,   888,   630,    51,   303,    73,  1135,   589,   636,   637,
     638,   246,   640,   641,   504,   128,   418,  1079,   550,   520,
     129,   130,   122,   131,   132,   236,   122,   408,   408,   133,
    1319,   303,    52,   497,    49,    50,   134,   135,   136,   137,
     138,   139,   520,    74,   311,   140,   141,   142,   615,  1108,
      75,    56,   497,   247,   589,   143,    58,   615,   144,   145,
    1121,  1122,  1123,   886,   478,   248,   249,   250,   146,   551,
     251,   252,  1291,  1292,  1293,   253,   254,   255,   311,  1079,
     236,   505,  1151,   479,  1153,   147,  1152,    62,  1154,   506,
     418,   507,   891,   892,  1289,    66,   148,   123,  1290,   149,
     150,   123,   409,   409,   694,    67,   696,   697,   151,   552,
     521,   601,    82,   480,   152,   153,   706,   154,    76,   155,
     590,  1109,   712,   156,   157,    69,    71,   267,   718,   419,
    1080,   119,   120,   521,   158,   237,   726,   727,   121,   159,
     160,   481,   161,   162,   163,    83,    84,   164,   508,   739,
     740,   741,   420,    85,   553,   127,   238,   312,    86,    87,
      88,   616,   268,   410,   410,   269,   233,   590,   601,   498,
     616,   165,   166,   234,   527,   167,   168,   169,   170,   171,
     172,   173,  -127,    89,    90,    91,    92,   550,   498,   235,
     237,   312,  1080,   528,   482,   270,   342,   522,    93,    94,
      95,   483,   484,   419,  1136,   271,    96,    97,    98,  -127,
      99,   238,  1294,   343,   344,  1298,  1295,  1081,   243,  1299,
     522,   244,   485,   529,   602,   345,   420,   245,   272,  1300,
     174,   175,   273,  1301,   302,   304,   591,   310,   551,   796,
     274,   176,   177,   275,   276,   375,  1082,   376,   321,   377,
     178,   530,   179,   527,   568,   317,   316,   765,   476,   691,
    1269,   792,   304,  1312,   378,   499,   515,  1313,   518,   416,
     685,   277,   528,   346,   598,   318,   758,   617,   552,  1081,
     618,   602,   603,   591,   499,   773,   617,   531,   319,   618,
     886,   842,   347,   348,   379,   320,   486,   824,   323,   349,
     604,  1314,   529,   350,   532,  1315,   324,   754,  1082,   351,
     325,   326,   380,   478,   381,   605,   327,   352,   353,   354,
    1177,   613,   382,   553,   504,   570,   328,   329,   875,   355,
     530,   878,   479,   880,   383,   596,  1178,  1316,   885,   603,
    1342,  1317,  1343,    73,   330,   278,   331,   279,   280,   356,
     281,   282,   283,   332,   834,   340,   903,   604,   384,  1179,
    1323,   333,   480,   627,  1324,   334,   531,   335,   336,   337,
     587,   338,   605,   339,  1157,   415,   425,   426,   427,   385,
     533,    74,   428,   532,   429,   430,  1344,   357,    75,   431,
     481,   505,   432,   534,   433,   434,   535,   386,   435,   506,
     436,   507,  1345,   437,   438,   439,   536,   440,   441,  1158,
     537,   442,   443,   387,   444,   445,   446,   786,   447,   628,
     448,   449,   450,   128,   451,   452,   453,   454,   129,   130,
     457,   131,   132,   458,  1346,  1347,   459,   133,   460,   663,
     461,   600,  1159,   482,   134,   135,   136,   137,   138,   139,
     483,   484,   462,   140,   141,   142,    76,   463,   508,   533,
     464,   465,   388,   143,   389,   390,   144,   145,   466,   467,
     468,   485,   534,  1160,  1161,   535,   146,   469,   470,  1162,
     471,   472,   473,   474,   475,   536,   516,   517,   681,   537,
    1191,   559,  1348,   147,   560,  1180,   561,   562,  1349,   563,
     564,   565,  1163,   267,   148,  1181,   566,   149,   150,   567,
     571,   572,   573,   574,  1192,  1193,   151,   575,   576,   577,
     578,   579,   152,   153,   580,   154,  1194,   155,   581,   582,
     583,   156,   157,   584,   585,   586,   597,   612,   268,   624,
     631,   269,   158,   625,   626,   486,   629,   159,   160,   632,
     161,   162,   163,   633,   634,   164,   848,   849,   850,   851,
     852,   853,   854,   635,   639,   648,  1195,  1196,   642,  1197,
     643,   270,  1164,   644,   645,   649,   646,   693,   647,   165,
     166,   271,   650,   167,   168,   169,   170,   171,   172,   173,
     652,   653,   654,  1198,   655,   656,   657,  1199,  1165,   375,
     658,   376,   944,   377,   272,  1200,  1320,   659,   273,  1098,
    1099,  1100,  1101,  1102,  1103,  1104,   274,   660,   378,   275,
     276,   661,   662,   665,   666,   667,  1201,   246,  1202,  1203,
     668,   669,   670,   671,   673,   674,   675,   676,   174,   175,
     677,   678,   679,   680,   945,   683,  1204,   277,   379,   176,
     177,   946,   629,   947,   948,   684,   687,   688,   178,   689,
     179,   695,  1205,   690,   968,   698,   380,  1206,   381,   247,
     699,  1207,   700,   701,   702,  1208,   382,   703,   704,   705,
    1209,   248,   249,   250,   707,  1210,   251,   252,   383,   708,
     709,   253,   254,   255,  1211,   710,  1212,  1213,   711,  1214,
     713,  1221,   714,   715,   716,   722,   969,   717,   719,   720,
     721,   725,   384,   970,   728,   971,   972,  1215,   723,   724,
     729,   278,   731,   279,   280,  1216,   281,   282,   283,   730,
     732,   733,   734,   385,   735,   736,   737,   738,   742,   743,
     746,   744,   794,  1222,   745,   795,   747,   760,   798,   749,
    1223,   386,  1224,  1225,   750,   751,   752,   753,   756,   757,
     761,   949,   950,   767,   762,   951,   768,   387,   952,   953,
     764,   954,   769,   955,   770,   775,   956,   800,   957,   958,
     771,   772,   776,   777,   959,   779,   960,   780,   782,   961,
     783,   784,   785,   962,   963,   964,   788,   789,   790,   797,
     791,   799,   801,   965,   802,   805,   803,   804,   806,   807,
     820,   808,   809,   810,   811,   812,   388,   813,   389,   390,
     814,   815,   816,   973,   974,   817,   818,   975,   822,   819,
     976,   977,   826,   978,   873,   979,   830,   821,   980,   827,
     981,   982,   828,   829,   874,   831,   983,   832,   984,   833,
     836,   985,  1253,   837,   838,   986,   987,   988,   839,  1276,
    1226,  1227,     2,     3,  1228,   989,     4,  1229,  1230,   342,
    1231,   841,  1232,   844,   845,  1233,   846,  1234,  1235,     5,
     847,   857,     6,  1236,   858,  1237,   343,   344,  1238,   859,
     860,     7,  1239,  1240,  1241,   861,   876,   862,   345,   863,
       8,   864,  1242,   865,   866,   867,   868,   869,   870,   871,
     872,   877,  1254,   879,     9,   881,   889,   882,   883,  1277,
      10,    11,   884,   886,   890,   893,   894,   895,   896,   898,
     899,   897,  1184,   900,   901,   902,   904,  1255,   905,    12,
     907,   906,   908,    13,  1278,  1256,   346,   909,   910,   911,
     912,  1011,  1279,    14,  1257,   913,   914,   915,   916,   917,
     918,  1280,   919,   920,   921,   347,   348,   922,   923,   924,
     925,   926,   349,   927,    15,    16,   350,  1258,    82,  1259,
    1260,   928,   351,   929,  1281,   930,  1282,  1283,   931,    17,
     352,   353,   354,   932,   933,   934,   935,   936,   937,   938,
    1261,   939,   355,   940,   941,    18,   942,  1284,  1262,   943,
     992,    83,    84,   993,   994,  1285,   995,    19,    20,    85,
     996,   997,   356,   998,    86,    87,    88,   999,  1000,  1001,
    1002,  1003,  1004,  1005,  1006,    21,  1007,  1008,  1009,  1010,
    1012,  1014,  1016,  1013,  1015,  1017,  1018,  1020,    22,    89,
      90,    91,    92,    23,  1019,  1021,  1022,  1023,  1024,    24,
     357,  1025,    25,  1026,    93,    94,    95,  1029,  1036,  1030,
    1031,  1032,    96,    97,    98,  1033,    99,  1035,  1034,  1037,
    1038,  1039,  1041,  1040,  1042,  1043,  1044,  1332,  1046,  1045,
    1047,  1048,   588,   322,  1049,  1050,  1305,  1051,  1052,  1053,
    1054,  1055,  1056,  1057,  1058,  1270,  1059,  1060,  1061,  1062,
    1063,  1337,   835,  1064,  1065,  1066,  1067,  1068,  1069,  1070,
    1071,  1072,  1073,  1074,  1075,  1077,  1302,  1076,  1078,  1088,
    1089,  1090,  1091,  1095,  1306,  1092,  1093,  1094,  1096,  1329,
    1266,  1097,  1105,  1106,  1107,  1112,  1113,  1114,  1115,  1116,
    1117,  1118,  1119,  1120,  1126,  1127,  1128,  1129,  1130,  1131,
    1132,  1133,  1134,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1155,  1156,  1168,  1169,  1170,
    1171,  1172,  1173,  1174,  1175,  1176,  1330,  1187,  1188,  1189,
    1185,  1190,  1219,  1220,  1245,  1246,  1247,  1248,  1249,  1250,
    1251,  1252,  1265,  1331,  1271,  1272,  1267,  1273,  1274,  1275,
    1288,  1304,  1333,  1334,  1335,  1318,   787,  1307,  1308,  1309,
    1310,  1311,  1321,  1322,  1339,  1340,  1341,  1352,   519,   774,
    1336,  1325,  1328,   766,   755,  1303,  1327,   843,  1351,  1338,
     825,  1326,   686,   759,   417,   477,   793,  1297,  1296,   692,
     341,   569,   599,   664,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   682
};

static const yytype_int16 yycheck[] =
{
     661,   662,   324,   245,     1,     1,     8,     1,   330,   331,
     332,     1,   334,   335,     1,     1,     1,     1,     1,     1,
       6,     7,     1,     9,    10,     1,     1,     1,     1,    15,
     209,     1,   245,     1,   243,   244,    22,    23,    24,    25,
      26,    27,     1,    39,     1,    31,    32,    33,     1,    64,
      46,   245,     1,    43,     1,    41,   245,     1,    44,    45,
      12,    13,    14,   242,     1,    55,    56,    57,    54,    52,
      60,    61,  1121,  1122,  1123,    65,    66,    67,     1,     1,
       1,    68,   243,    20,   243,    71,   247,   245,   247,    76,
       1,    78,   183,   184,   243,   245,    82,    76,   247,    85,
      86,    76,    76,    76,   426,   245,   428,   429,    94,    92,
      92,     1,     1,    50,   100,   101,   438,   103,   114,   105,
     114,   136,   444,   109,   110,   245,   245,     1,   450,   114,
     114,   245,   245,    92,   120,   111,   458,   459,   245,   125,
     126,    78,   128,   129,   130,    34,    35,   133,   135,   471,
     472,   473,   137,    42,   137,   245,   132,   114,    47,    48,
      49,   114,    36,   137,   137,    39,   245,   114,     1,   137,
     114,   157,   158,   245,     1,   161,   162,   163,   164,   165,
     166,   167,   179,    72,    73,    74,    75,     1,   137,   245,
     111,   114,   114,    20,   131,    69,     1,   179,    87,    88,
      89,   138,   139,   114,   206,    79,    95,    96,    97,   179,
      99,   132,   243,    18,    19,   243,   247,   201,   245,   247,
     179,   245,   159,    50,   114,    30,   137,   245,   102,   243,
     216,   217,   106,   247,   245,   232,   230,   245,    52,   561,
     114,   227,   228,   117,   118,     1,   230,     3,   244,     5,
     236,    78,   238,     1,   244,   243,   245,   244,   244,   244,
     244,   244,   232,   243,    20,   233,   243,   247,   244,   244,
     244,   145,    20,    78,   244,   246,   244,   230,    92,   201,
     233,   114,   172,   230,   233,   244,   230,   114,   246,   233,
     242,   244,    97,    98,    50,   246,   233,   244,   246,   104,
     190,   243,    50,   108,   131,   247,   246,   244,   230,   114,
     246,   246,    68,     1,    70,   205,   246,   122,   123,   124,
      21,   244,    78,   137,     1,   243,   246,   246,   650,   134,
      78,   653,    20,   655,    90,   243,    37,   243,   660,   172,
      81,   247,    83,     1,   246,   219,   246,   221,   222,   154,
     224,   225,   226,   246,   244,   244,   678,   190,   114,    60,
     243,   246,    50,   243,   247,   246,   114,   246,   246,   246,
     244,   246,   205,   246,    16,   246,   246,   246,   246,   135,
     207,    39,   246,   131,   246,   246,   127,   192,    46,   246,
      78,    68,   246,   220,   246,   246,   223,   153,   246,    76,
     246,    78,   143,   246,   246,   246,   233,   246,   246,    51,
     237,   246,   246,   169,   246,   246,   246,   244,   246,   242,
     246,   246,   246,     1,   246,   246,   246,   246,     6,     7,
     246,     9,    10,   246,   175,   176,   246,    15,   246,   244,
     246,   179,    84,   131,    22,    23,    24,    25,    26,    27,
     138,   139,   246,    31,    32,    33,   114,   246,   135,   207,
     246,   246,   218,    41,   220,   221,    44,    45,   246,   246,
     246,   159,   220,   115,   116,   223,    54,   246,   246,   121,
     246,   246,   246,   246,   246,   233,   246,   246,   244,   237,
       4,   246,   233,    71,   246,   196,   246,   246,   239,   246,
     246,   246,   144,     1,    82,   206,   246,    85,    86,   246,
     246,   246,   246,   246,    28,    29,    94,   246,   246,   246,
     246,   246,   100,   101,   246,   103,    40,   105,   246,   246,
     246,   109,   110,   246,   246,   246,   246,   246,    36,   241,
     215,    39,   120,   241,   241,   233,   242,   125,   126,   215,
     128,   129,   130,   215,   215,   133,   146,   147,   148,   149,
     150,   151,   152,   242,   242,   246,    80,    81,   242,    83,
     242,    69,   214,   242,   242,   246,   243,   215,   243,   157,
     158,    79,   246,   161,   162,   163,   164,   165,   166,   167,
     246,   246,   246,   107,   246,   246,   246,   111,   240,     1,
     246,     3,    11,     5,   102,   119,  1267,   246,   106,   848,
     849,   850,   851,   852,   853,   854,   114,   246,    20,   117,
     118,   246,   246,   243,   246,   246,   140,     1,   142,   143,
     246,   246,   246,   246,   246,   246,   246,   246,   216,   217,
     246,   246,   246,   246,    53,   246,   160,   145,    50,   227,
     228,    60,   242,    62,    63,   246,   241,   243,   236,   246,
     238,   242,   176,   246,    11,   215,    68,   181,    70,    43,
     242,   185,   242,   242,   241,   189,    78,   241,   215,   242,
     194,    55,    56,    57,   215,   199,    60,    61,    90,   242,
     242,    65,    66,    67,   208,   215,   210,   211,   215,   213,
     242,    11,   242,   242,   242,   215,    53,   242,   242,   242,
     242,   215,   114,    60,   215,    62,    63,   231,   246,   246,
     215,   219,   215,   221,   222,   239,   224,   225,   226,   242,
     215,   215,   215,   135,   215,   215,   215,   242,   215,   242,
     246,   243,   215,    53,   243,   215,   246,   243,   215,   246,
      60,   153,    62,    63,   246,   246,   246,   246,   246,   246,
     246,   170,   171,   241,   246,   174,   241,   169,   177,   178,
     246,   180,   243,   182,   243,   243,   185,   215,   187,   188,
     246,   246,   246,   246,   193,   246,   195,   246,   246,   198,
     246,   246,   246,   202,   203,   204,   243,   246,   246,   241,
     246,   241,   215,   212,   215,   241,   243,   242,   215,   241,
     243,   242,   242,   241,   241,   241,   218,   241,   220,   221,
     241,   241,   241,   170,   171,   241,   241,   174,   246,   241,
     177,   178,   215,   180,   242,   182,   246,   243,   185,   243,
     187,   188,   245,   243,   242,   246,   193,   246,   195,   246,
     241,   198,    83,   243,   243,   202,   203,   204,   246,    83,
     170,   171,     0,     1,   174,   212,     4,   177,   178,     1,
     180,   246,   182,   243,   243,   185,   243,   187,   188,    17,
     243,   243,    20,   193,   243,   195,    18,    19,   198,   243,
     243,    29,   202,   203,   204,   243,   246,   243,    30,   243,
      38,   243,   212,   243,   243,   243,   243,   243,   243,   243,
     243,   242,   143,   242,    52,   241,   243,   242,   242,   143,
      58,    59,   242,   242,   241,   241,   215,   241,   241,   241,
     241,   246,   229,   242,   241,   241,   241,   168,   241,    77,
     241,   243,   241,    81,   168,   176,    78,   243,   243,   241,
     241,   241,   176,    91,   185,   243,   243,   243,   243,   243,
     243,   185,   243,   243,   243,    97,    98,   243,   243,   243,
     243,   243,   104,   243,   112,   113,   108,   208,     1,   210,
     211,   243,   114,   243,   208,   243,   210,   211,   243,   127,
     122,   123,   124,   243,   243,   243,   243,   243,   243,   243,
     231,   243,   134,   243,   243,   143,   243,   231,   239,   243,
     243,    34,    35,   243,   243,   239,   243,   155,   156,    42,
     243,   243,   154,   243,    47,    48,    49,   243,   243,   243,
     243,   243,   243,   243,   243,   173,   243,   243,   243,   243,
     215,   241,   241,   246,   242,   241,   241,   241,   186,    72,
      73,    74,    75,   191,   243,   241,   243,   241,   241,   197,
     192,   246,   200,   242,    87,    88,    89,   243,   215,   243,
     243,   241,    95,    96,    97,   241,    99,   241,   243,   246,
     241,   241,   241,   246,   215,   241,   241,    93,   241,   243,
     241,   241,   284,    77,   243,   243,   248,   243,   243,   243,
     243,   243,   243,   243,   243,  1083,   243,   243,   243,   243,
     243,  1315,   606,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   241,   243,   242,   246,   243,   241,
     241,   241,   241,   246,   248,   243,   243,   241,   241,   141,
     246,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   143,   243,   243,   243,
     247,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   141,   243,   243,   246,   243,   243,   243,
     243,   243,   143,   141,   141,   241,   538,   248,   248,   248,
     248,   248,   246,   243,   243,   243,   243,   243,   239,   523,
    1313,  1290,  1301,   510,   487,  1185,  1299,   619,  1324,  1317,
     592,  1295,   411,   500,   124,   180,   554,  1154,  1152,   421,
     100,   256,   305,   358,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   313,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   391
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   250,     0,     1,     4,    17,    20,    29,    38,    52,
      58,    59,    77,    81,    91,   112,   113,   127,   143,   155,
     156,   173,   186,   191,   197,   200,   251,   256,   261,   280,
     286,   292,   300,   313,   333,   355,   369,   384,   391,   395,
     405,   414,   436,   442,   448,   452,   458,   518,   538,   243,
     244,   245,   245,   334,   415,   443,   245,   453,   245,   370,
     437,   356,   245,   287,   314,   385,   245,   245,   406,   245,
     293,   245,   396,     1,    39,    46,   114,   281,   282,   283,
     284,   285,     1,    34,    35,    42,    47,    48,    49,    72,
      73,    74,    75,    87,    88,    89,    95,    96,    97,    99,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   245,
     245,   245,     1,    76,   449,   450,   451,   245,     1,     6,
       7,     9,    10,    15,    22,    23,    24,    25,    26,    27,
      31,    32,    33,    41,    44,    45,    54,    71,    82,    85,
      86,    94,   100,   101,   103,   105,   109,   110,   120,   125,
     126,   128,   129,   130,   133,   157,   158,   161,   162,   163,
     164,   165,   166,   167,   216,   217,   227,   228,   236,   238,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   504,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   245,   245,   245,     1,   111,   132,   257,
     258,   259,   260,   245,   245,   245,     1,    43,    55,    56,
      57,    60,    61,    65,    66,    67,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,     1,    36,    39,
      69,    79,   102,   106,   114,   117,   118,   145,   219,   221,
     222,   224,   225,   226,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   245,     1,   232,   301,   302,   303,   304,   305,
     245,     1,   114,   392,   393,   394,   245,   243,   246,   246,
     246,   244,   282,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     244,   520,     1,    18,    19,    30,    78,    97,    98,   104,
     108,   114,   122,   123,   124,   134,   154,   192,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     1,     3,     5,    20,    50,
      68,    70,    78,    90,   114,   135,   153,   169,   218,   220,
     221,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   431,   432,   433,   434,   435,     1,    76,
     137,   444,   445,   446,   447,   246,   244,   450,     1,   114,
     137,   454,   455,   456,   457,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   505,   501,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   244,   460,     1,    20,
      50,    78,   131,   138,   139,   159,   233,   371,   372,   373,
     374,   375,   376,   377,   381,   382,   383,     1,   137,   233,
     438,   439,   440,   441,     1,    68,    76,    78,   135,   357,
     361,   362,   363,   367,   368,   243,   246,   246,   244,   258,
       1,    92,   179,   288,   289,   290,   291,     1,    20,    50,
      78,   114,   131,   207,   220,   223,   233,   237,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   329,
       1,    52,    92,   137,   386,   387,   388,   389,   390,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   244,   540,
     243,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   244,   263,     1,
     114,   230,   407,   408,   409,   410,   243,   246,   244,   302,
     179,     1,   114,   172,   190,   205,   294,   295,   296,   297,
     298,   299,   246,   244,   393,     1,   114,   230,   233,   397,
     398,   399,   400,   401,   241,   241,   241,   243,   242,   242,
     253,   215,   215,   215,   215,   242,   253,   253,   253,   242,
     253,   253,   242,   242,   242,   242,   243,   243,   246,   246,
     246,   352,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   244,   336,   243,   246,   246,   246,   246,
     246,   246,   428,   246,   246,   246,   246,   246,   246,   246,
     246,   244,   417,   246,   246,   244,   445,   241,   243,   246,
     246,   244,   455,   215,   253,   242,   253,   253,   215,   242,
     242,   242,   241,   241,   215,   242,   253,   215,   242,   242,
     215,   215,   253,   242,   242,   242,   242,   242,   253,   242,
     242,   242,   215,   246,   246,   215,   253,   253,   215,   215,
     242,   215,   215,   215,   215,   215,   215,   215,   242,   253,
     253,   253,   215,   242,   243,   243,   246,   246,   378,   246,
     246,   246,   246,   246,   244,   372,   246,   246,   244,   439,
     243,   246,   246,   358,   246,   244,   362,   241,   241,   243,
     243,   246,   246,   244,   289,   243,   246,   246,   330,   246,
     246,   326,   246,   246,   246,   246,   244,   316,   243,   246,
     246,   246,   244,   387,   215,   215,   253,   241,   215,   241,
     215,   215,   215,   243,   242,   241,   215,   241,   242,   242,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     243,   243,   246,   411,   244,   408,   215,   243,   245,   243,
     246,   246,   246,   246,   244,   295,   241,   243,   243,   246,
     402,   246,   244,   398,   243,   243,   243,   243,   146,   147,
     148,   149,   150,   151,   152,   252,   253,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   242,   242,   253,   246,   242,   253,   242,
     253,   241,   242,   242,   242,   253,   242,   255,   255,   243,
     241,   183,   184,   241,   215,   241,   241,   246,   241,   241,
     242,   241,   241,   253,   241,   241,   243,   241,   241,   243,
     243,   241,   241,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,    11,    53,    60,    62,    63,   170,
     171,   174,   177,   178,   180,   182,   185,   187,   188,   193,
     195,   198,   202,   203,   204,   212,   506,   507,    11,    53,
      60,    62,    63,   170,   171,   174,   177,   178,   180,   182,
     185,   187,   188,   193,   195,   198,   202,   203,   204,   212,
     502,   503,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   241,   215,   246,   241,   242,   241,   241,   241,   243,
     241,   241,   243,   241,   241,   246,   242,   365,   366,   243,
     243,   243,   241,   241,   243,   241,   215,   246,   241,   241,
     246,   241,   215,   241,   241,   243,   241,   241,   241,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   241,   246,   243,   243,     1,
     114,   201,   230,   306,   307,   308,   309,   310,   241,   241,
     241,   241,   243,   243,   241,   246,   241,   243,   252,   252,
     252,   252,   252,   252,   252,   243,   243,   243,    64,   136,
     353,   354,   243,   243,   243,   243,   243,   243,   243,   243,
     243,    12,    13,    14,   254,   255,   243,   243,   243,   243,
     243,   243,   243,   243,   243,     8,   206,   429,   430,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   247,   243,   247,   243,   243,    16,    51,    84,
     115,   116,   121,   144,   214,   240,   379,   380,   243,   243,
     243,   243,   243,   243,   243,   243,   243,    21,    37,    60,
     196,   206,   359,   360,   229,   247,   364,   243,   243,   243,
     243,     4,    28,    29,    40,    80,    81,    83,   107,   111,
     119,   140,   142,   143,   160,   176,   181,   185,   189,   194,
     199,   208,   210,   211,   213,   231,   239,   331,   332,   243,
     243,    11,    53,    60,    62,    63,   170,   171,   174,   177,
     178,   180,   182,   185,   187,   188,   193,   195,   198,   202,
     203,   204,   212,   327,   328,   243,   243,   243,   243,   243,
     243,   243,   243,    83,   143,   168,   176,   185,   208,   210,
     211,   231,   239,   412,   413,   243,   246,   246,   311,   244,
     307,   243,   243,   243,   243,   243,    83,   143,   168,   176,
     185,   208,   210,   211,   231,   239,   403,   404,   243,   243,
     247,   254,   254,   254,   243,   247,   507,   503,   243,   247,
     243,   247,   242,   366,   243,   248,   248,   248,   248,   248,
     248,   248,   243,   247,   243,   247,   243,   247,   241,   209,
     255,   246,   243,   243,   247,   354,   430,   380,   360,   141,
     143,   141,    93,   143,   141,   141,   332,   328,   413,   243,
     243,   243,    81,    83,   127,   143,   175,   176,   233,   239,
     312,   404,   243
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   249,   250,   250,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   252,   252,
     253,   253,   253,   253,   253,   253,   253,   253,   254,   254,
     255,   255,   255,   255,   256,   257,   257,   258,   258,   258,
     259,   260,   261,   262,   262,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     281,   282,   282,   282,   282,   283,   284,   285,   287,   286,
     288,   288,   289,   289,   289,   290,   291,   293,   292,   294,
     294,   295,   295,   295,   295,   295,   296,   297,   298,   299,
     300,   301,   301,   302,   302,   302,   303,   305,   304,   306,
     306,   307,   307,   307,   307,   308,   309,   309,   311,   310,
     312,   312,   312,   312,   312,   312,   312,   312,   314,   313,
     315,   315,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   326,   325,   327,   327,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   330,   329,   331,
     331,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   334,   333,   335,   335,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   352,   351,   353,   353,   354,
     354,   356,   355,   358,   357,   359,   359,   360,   360,   360,
     360,   360,   361,   361,   362,   362,   362,   362,   362,   364,
     363,   365,   365,   366,   366,   367,   368,   370,   369,   371,
     371,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     373,   374,   375,   376,   378,   377,   379,   379,   380,   380,
     380,   380,   380,   380,   380,   380,   380,   381,   382,   383,
     385,   384,   386,   386,   387,   387,   387,   387,   388,   389,
     390,   391,   392,   392,   393,   393,   394,   396,   395,   397,
     397,   398,   398,   398,   398,   399,   400,   402,   401,   403,
     403,   404,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   406,   405,   407,   407,   408,   408,   408,   409,   411,
     410,   412,   412,   413,   413,   413,   413,   413,   413,   413,
     413,   413,   413,   415,   414,   416,   416,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   426,   428,   427,   429,   429,   430,   430,   431,
     432,   433,   434,   435,   437,   436,   438,   438,   439,   439,
     439,   440,   441,   443,   442,   444,   444,   445,   445,   445,
     446,   447,   448,   449,   449,   450,   450,   451,   453,   452,
     454,   454,   455,   455,   455,   456,   457,   458,   459,   459,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   501,   500,   502,   502,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   505,   504,   506,
     506,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   519,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   539,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     0,     1,
       2,     3,     3,     3,     5,     2,     1,     1,     1,     2,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     0,     6,
       2,     1,     1,     1,     2,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     2,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     0,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       3,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     0,     6,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     0,
       5,     3,     1,     1,     3,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     2,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     4,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4
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
#line 408 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3347 "conf_parser.c"
    break;

  case 30: /* timespec: NUMBER timespec_  */
#line 409 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3353 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER SECONDS timespec_  */
#line 410 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3359 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER MINUTES timespec_  */
#line 411 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3365 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER HOURS timespec_  */
#line 412 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3371 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER DAYS timespec_  */
#line 413 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3377 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER WEEKS timespec_  */
#line 414 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3383 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER MONTHS timespec_  */
#line 415 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3389 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER YEARS timespec_  */
#line 416 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3395 "conf_parser.c"
    break;

  case 38: /* sizespec_: %empty  */
#line 419 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3401 "conf_parser.c"
    break;

  case 40: /* sizespec: NUMBER sizespec_  */
#line 420 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3407 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER BYTES sizespec_  */
#line 421 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3413 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER KBYTES sizespec_  */
#line 422 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3419 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER MBYTES sizespec_  */
#line 423 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3425 "conf_parser.c"
    break;

  case 50: /* modules_module: MODULE '=' QSTRING ';'  */
#line 436 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    add_conf_module(io_basename(yylval.string));
}
#line 3434 "conf_parser.c"
    break;

  case 51: /* modules_path: PATH '=' QSTRING ';'  */
#line 442 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 3443 "conf_parser.c"
    break;

  case 72: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 474 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3455 "conf_parser.c"
    break;

  case 73: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 483 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = io_strdup(yylval.string);
  }
}
#line 3467 "conf_parser.c"
    break;

  case 74: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 492 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = io_strdup(yylval.string);
  }
}
#line 3479 "conf_parser.c"
    break;

  case 75: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 501 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = io_strdup(yylval.string);
  }
}
#line 3491 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 510 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = io_strdup(yylval.string);
  }
}
#line 3503 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 519 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = io_strdup(yylval.string);
  }
}
#line 3515 "conf_parser.c"
    break;

  case 78: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 528 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = io_strdup(yylval.string);
  }
}
#line 3527 "conf_parser.c"
    break;

  case 79: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 537 "conf_parser.y"
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

  case 80: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 552 "conf_parser.y"
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

  case 81: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 567 "conf_parser.y"
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

  case 82: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 577 "conf_parser.y"
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

  case 83: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 591 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3605 "conf_parser.c"
    break;

  case 84: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 600 "conf_parser.y"
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

  case 85: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 623 "conf_parser.y"
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

  case 86: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 646 "conf_parser.y"
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

  case 87: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 669 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3692 "conf_parser.c"
    break;

  case 95: /* admin_name: NAME '=' QSTRING ';'  */
#line 687 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3704 "conf_parser.c"
    break;

  case 96: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 696 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3716 "conf_parser.c"
    break;

  case 97: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 705 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3728 "conf_parser.c"
    break;

  case 98: /* $@1: %empty  */
#line 718 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3737 "conf_parser.c"
    break;

  case 99: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 722 "conf_parser.y"
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

  case 105: /* motd_mask: MASK '=' QSTRING ';'  */
#line 739 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3763 "conf_parser.c"
    break;

  case 106: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 745 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3772 "conf_parser.c"
    break;

  case 107: /* $@2: %empty  */
#line 755 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3781 "conf_parser.c"
    break;

  case 108: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 759 "conf_parser.y"
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

  case 116: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 777 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3808 "conf_parser.c"
    break;

  case 117: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 783 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3817 "conf_parser.c"
    break;

  case 118: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 789 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3826 "conf_parser.c"
    break;

  case 119: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 795 "conf_parser.y"
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

  case 126: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 824 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3857 "conf_parser.c"
    break;

  case 127: /* $@3: %empty  */
#line 830 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3866 "conf_parser.c"
    break;

  case 128: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 834 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3879 "conf_parser.c"
    break;

  case 135: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 850 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3890 "conf_parser.c"
    break;

  case 136: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 858 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3898 "conf_parser.c"
    break;

  case 137: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 861 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3906 "conf_parser.c"
    break;

  case 138: /* $@4: %empty  */
#line 866 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3915 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: USER  */
#line 872 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3924 "conf_parser.c"
    break;

  case 141: /* logging_file_type_item: OPERATOR  */
#line 876 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3933 "conf_parser.c"
    break;

  case 142: /* logging_file_type_item: XLINE  */
#line 880 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3942 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: RESV  */
#line 884 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3951 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: T_DLINE  */
#line 888 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3960 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: KLINE  */
#line 892 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3969 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: KILL  */
#line 896 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3978 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: T_DEBUG  */
#line 900 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3987 "conf_parser.c"
    break;

  case 148: /* $@5: %empty  */
#line 910 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3999 "conf_parser.c"
    break;

  case 149: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 917 "conf_parser.y"
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

  case 163: /* oper_name: NAME '=' QSTRING ';'  */
#line 987 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4068 "conf_parser.c"
    break;

  case 164: /* oper_user: USER '=' QSTRING ';'  */
#line 993 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4077 "conf_parser.c"
    break;

  case 165: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 999 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4086 "conf_parser.c"
    break;

  case 166: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1005 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4095 "conf_parser.c"
    break;

  case 167: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1011 "conf_parser.y"
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

  case 168: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1022 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4118 "conf_parser.c"
    break;

  case 169: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1028 "conf_parser.y"
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

  case 170: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1039 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4141 "conf_parser.c"
    break;

  case 171: /* $@6: %empty  */
#line 1045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 4150 "conf_parser.c"
    break;

  case 175: /* oper_umodes_item: BOT  */
#line 1052 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOT;
}
#line 4159 "conf_parser.c"
    break;

  case 176: /* oper_umodes_item: T_CCONN  */
#line 1056 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 4168 "conf_parser.c"
    break;

  case 177: /* oper_umodes_item: T_DEAF  */
#line 1060 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 4177 "conf_parser.c"
    break;

  case 178: /* oper_umodes_item: T_FLOOD  */
#line 1064 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FLOOD;
}
#line 4186 "conf_parser.c"
    break;

  case 179: /* oper_umodes_item: HIDDEN  */
#line 1068 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 4195 "conf_parser.c"
    break;

  case 180: /* oper_umodes_item: HIDE_CHANS  */
#line 1072 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 4204 "conf_parser.c"
    break;

  case 181: /* oper_umodes_item: HIDE_IDLE  */
#line 1076 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 4213 "conf_parser.c"
    break;

  case 182: /* oper_umodes_item: T_SKILL  */
#line 1080 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 4222 "conf_parser.c"
    break;

  case 183: /* oper_umodes_item: T_NCHANGE  */
#line 1084 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 4231 "conf_parser.c"
    break;

  case 184: /* oper_umodes_item: T_REJ  */
#line 1088 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 4240 "conf_parser.c"
    break;

  case 185: /* oper_umodes_item: T_SPY  */
#line 1092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4249 "conf_parser.c"
    break;

  case 186: /* oper_umodes_item: T_EXTERNAL  */
#line 1096 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4258 "conf_parser.c"
    break;

  case 187: /* oper_umodes_item: T_SERVNOTICE  */
#line 1100 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4267 "conf_parser.c"
    break;

  case 188: /* oper_umodes_item: T_INVISIBLE  */
#line 1104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4276 "conf_parser.c"
    break;

  case 189: /* oper_umodes_item: T_WALLOP  */
#line 1108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4285 "conf_parser.c"
    break;

  case 190: /* oper_umodes_item: T_SOFTCALLERID  */
#line 1112 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4294 "conf_parser.c"
    break;

  case 191: /* oper_umodes_item: T_CALLERID  */
#line 1116 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4303 "conf_parser.c"
    break;

  case 192: /* oper_umodes_item: T_LOCOPS  */
#line 1120 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4312 "conf_parser.c"
    break;

  case 193: /* oper_umodes_item: T_NONONREG  */
#line 1124 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4321 "conf_parser.c"
    break;

  case 194: /* oper_umodes_item: T_FARCONNECT  */
#line 1128 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4330 "conf_parser.c"
    break;

  case 195: /* oper_umodes_item: EXPIRATION  */
#line 1132 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 4339 "conf_parser.c"
    break;

  case 196: /* oper_umodes_item: T_SECUREONLY  */
#line 1136 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SECUREONLY;
}
#line 4348 "conf_parser.c"
    break;

  case 197: /* $@7: %empty  */
#line 1142 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4357 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: KILL ':' REMOTE  */
#line 1149 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4366 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: KILL  */
#line 1153 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4375 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1157 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4384 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: CONNECT  */
#line 1161 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4393 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1165 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4402 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: SQUIT  */
#line 1169 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4411 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: KLINE  */
#line 1173 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4420 "conf_parser.c"
    break;

  case 208: /* oper_flags_item: UNKLINE  */
#line 1177 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4429 "conf_parser.c"
    break;

  case 209: /* oper_flags_item: T_DLINE  */
#line 1181 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4438 "conf_parser.c"
    break;

  case 210: /* oper_flags_item: T_UNDLINE  */
#line 1185 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4447 "conf_parser.c"
    break;

  case 211: /* oper_flags_item: XLINE  */
#line 1189 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4456 "conf_parser.c"
    break;

  case 212: /* oper_flags_item: T_UNXLINE  */
#line 1193 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4465 "conf_parser.c"
    break;

  case 213: /* oper_flags_item: DIE  */
#line 1197 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4474 "conf_parser.c"
    break;

  case 214: /* oper_flags_item: T_RESTART  */
#line 1201 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4483 "conf_parser.c"
    break;

  case 215: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1205 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4492 "conf_parser.c"
    break;

  case 216: /* oper_flags_item: REHASH  */
#line 1209 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4501 "conf_parser.c"
    break;

  case 217: /* oper_flags_item: ADMIN  */
#line 1213 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4510 "conf_parser.c"
    break;

  case 218: /* oper_flags_item: T_GLOBOPS  */
#line 1217 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4519 "conf_parser.c"
    break;

  case 219: /* oper_flags_item: T_WALLOPS  */
#line 1221 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4528 "conf_parser.c"
    break;

  case 220: /* oper_flags_item: T_LOCOPS  */
#line 1225 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4537 "conf_parser.c"
    break;

  case 221: /* oper_flags_item: REMOTEBAN  */
#line 1229 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4546 "conf_parser.c"
    break;

  case 222: /* oper_flags_item: T_SET  */
#line 1233 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4555 "conf_parser.c"
    break;

  case 223: /* oper_flags_item: MODULE  */
#line 1237 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4564 "conf_parser.c"
    break;

  case 224: /* oper_flags_item: T_OPME  */
#line 1241 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4573 "conf_parser.c"
    break;

  case 225: /* oper_flags_item: NICK ':' RESV  */
#line 1245 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4582 "conf_parser.c"
    break;

  case 226: /* oper_flags_item: JOIN ':' RESV  */
#line 1249 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4591 "conf_parser.c"
    break;

  case 227: /* oper_flags_item: RESV  */
#line 1253 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4600 "conf_parser.c"
    break;

  case 228: /* oper_flags_item: T_UNRESV  */
#line 1257 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4609 "conf_parser.c"
    break;

  case 229: /* oper_flags_item: CLOSE  */
#line 1261 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4618 "conf_parser.c"
    break;

  case 230: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1265 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4627 "conf_parser.c"
    break;

  case 231: /* $@8: %empty  */
#line 1275 "conf_parser.y"
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

  case 232: /* class_entry: CLASS $@8 '{' class_items '}' ';'  */
#line 1286 "conf_parser.y"
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

  case 251: /* class_name: NAME '=' QSTRING ';'  */
#line 1349 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4700 "conf_parser.c"
    break;

  case 252: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1355 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4709 "conf_parser.c"
    break;

  case 253: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1361 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4718 "conf_parser.c"
    break;

  case 254: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1367 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4727 "conf_parser.c"
    break;

  case 255: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1373 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4736 "conf_parser.c"
    break;

  case 256: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1379 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4745 "conf_parser.c"
    break;

  case 257: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1385 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4754 "conf_parser.c"
    break;

  case 258: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1391 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4763 "conf_parser.c"
    break;

  case 259: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1397 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4773 "conf_parser.c"
    break;

  case 260: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1404 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4782 "conf_parser.c"
    break;

  case 261: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1410 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4791 "conf_parser.c"
    break;

  case 262: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1416 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4800 "conf_parser.c"
    break;

  case 263: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1422 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4812 "conf_parser.c"
    break;

  case 264: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1431 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4824 "conf_parser.c"
    break;

  case 265: /* $@9: %empty  */
#line 1440 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4833 "conf_parser.c"
    break;

  case 269: /* class_flags_item: RANDOM_IDLE  */
#line 1447 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4842 "conf_parser.c"
    break;

  case 270: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1451 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4851 "conf_parser.c"
    break;

  case 271: /* $@10: %empty  */
#line 1461 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4860 "conf_parser.c"
    break;

  case 273: /* $@11: %empty  */
#line 1467 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4868 "conf_parser.c"
    break;

  case 277: /* listen_flags_item: T_TLS  */
#line 1473 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4877 "conf_parser.c"
    break;

  case 278: /* listen_flags_item: HIDDEN  */
#line 1477 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4886 "conf_parser.c"
    break;

  case 279: /* listen_flags_item: T_SERVER  */
#line 1481 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4895 "conf_parser.c"
    break;

  case 280: /* listen_flags_item: CLIENT  */
#line 1485 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4904 "conf_parser.c"
    break;

  case 281: /* listen_flags_item: DEFER  */
#line 1489 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4913 "conf_parser.c"
    break;

  case 289: /* $@12: %empty  */
#line 1497 "conf_parser.y"
                                 { reset_block_state(); }
#line 4919 "conf_parser.c"
    break;

  case 293: /* port_item: NUMBER  */
#line 1502 "conf_parser.y"
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

  case 294: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1515 "conf_parser.y"
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

  case 295: /* listen_address: IP '=' QSTRING ';'  */
#line 1532 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4966 "conf_parser.c"
    break;

  case 296: /* listen_host: HOST '=' QSTRING ';'  */
#line 1538 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4975 "conf_parser.c"
    break;

  case 297: /* $@13: %empty  */
#line 1548 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4984 "conf_parser.c"
    break;

  case 298: /* auth_entry: IRCD_AUTH $@13 '{' auth_items '}' ';'  */
#line 1552 "conf_parser.y"
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

  case 310: /* auth_user: USER '=' QSTRING ';'  */
#line 1607 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5040 "conf_parser.c"
    break;

  case 311: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1613 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5049 "conf_parser.c"
    break;

  case 312: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1619 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5058 "conf_parser.c"
    break;

  case 313: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1625 "conf_parser.y"
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

  case 314: /* $@14: %empty  */
#line 1636 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 5081 "conf_parser.c"
    break;

  case 318: /* auth_flags_item: EXCEED_LIMIT  */
#line 1643 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 5090 "conf_parser.c"
    break;

  case 319: /* auth_flags_item: KLINE_EXEMPT  */
#line 1647 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 5099 "conf_parser.c"
    break;

  case 320: /* auth_flags_item: XLINE_EXEMPT  */
#line 1651 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 5108 "conf_parser.c"
    break;

  case 321: /* auth_flags_item: NEED_IDENT  */
#line 1655 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 5117 "conf_parser.c"
    break;

  case 322: /* auth_flags_item: CAN_FLOOD  */
#line 1659 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 5126 "conf_parser.c"
    break;

  case 323: /* auth_flags_item: NO_TILDE  */
#line 1663 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 5135 "conf_parser.c"
    break;

  case 324: /* auth_flags_item: RESV_EXEMPT  */
#line 1667 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 5144 "conf_parser.c"
    break;

  case 325: /* auth_flags_item: T_WEBIRC  */
#line 1671 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 5153 "conf_parser.c"
    break;

  case 326: /* auth_flags_item: NEED_PASSWORD  */
#line 1675 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 5162 "conf_parser.c"
    break;

  case 327: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1681 "conf_parser.y"
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

  case 328: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1695 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 5191 "conf_parser.c"
    break;

  case 329: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1704 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 5203 "conf_parser.c"
    break;

  case 330: /* $@15: %empty  */
#line 1717 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5215 "conf_parser.c"
    break;

  case 331: /* resv_entry: RESV $@15 '{' resv_items '}' ';'  */
#line 1724 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5226 "conf_parser.c"
    break;

  case 338: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1735 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5235 "conf_parser.c"
    break;

  case 339: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1741 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5244 "conf_parser.c"
    break;

  case 340: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1747 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5253 "conf_parser.c"
    break;

  case 346: /* service_name: NAME '=' QSTRING ';'  */
#line 1762 "conf_parser.y"
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

  case 347: /* $@16: %empty  */
#line 1778 "conf_parser.y"
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

  case 348: /* shared_entry: T_SHARED $@16 '{' shared_items '}' ';'  */
#line 1789 "conf_parser.y"
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

  case 355: /* shared_name: NAME '=' QSTRING ';'  */
#line 1804 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5308 "conf_parser.c"
    break;

  case 356: /* shared_user: USER '=' QSTRING ';'  */
#line 1810 "conf_parser.y"
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

  case 357: /* $@17: %empty  */
#line 1829 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5339 "conf_parser.c"
    break;

  case 361: /* shared_type_item: KLINE  */
#line 1836 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5348 "conf_parser.c"
    break;

  case 362: /* shared_type_item: UNKLINE  */
#line 1840 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5357 "conf_parser.c"
    break;

  case 363: /* shared_type_item: T_DLINE  */
#line 1844 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5366 "conf_parser.c"
    break;

  case 364: /* shared_type_item: T_UNDLINE  */
#line 1848 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5375 "conf_parser.c"
    break;

  case 365: /* shared_type_item: XLINE  */
#line 1852 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5384 "conf_parser.c"
    break;

  case 366: /* shared_type_item: T_UNXLINE  */
#line 1856 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5393 "conf_parser.c"
    break;

  case 367: /* shared_type_item: RESV  */
#line 1860 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5402 "conf_parser.c"
    break;

  case 368: /* shared_type_item: T_UNRESV  */
#line 1864 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5411 "conf_parser.c"
    break;

  case 369: /* shared_type_item: T_LOCOPS  */
#line 1868 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5420 "conf_parser.c"
    break;

  case 370: /* shared_type_item: T_ALL  */
#line 1872 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5429 "conf_parser.c"
    break;

  case 371: /* $@18: %empty  */
#line 1882 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5443 "conf_parser.c"
    break;

  case 372: /* cluster_entry: T_CLUSTER $@18 '{' cluster_items '}' ';'  */
#line 1891 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5456 "conf_parser.c"
    break;

  case 378: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1904 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5465 "conf_parser.c"
    break;

  case 379: /* $@19: %empty  */
#line 1910 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5474 "conf_parser.c"
    break;

  case 383: /* cluster_type_item: KLINE  */
#line 1917 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5483 "conf_parser.c"
    break;

  case 384: /* cluster_type_item: UNKLINE  */
#line 1921 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5492 "conf_parser.c"
    break;

  case 385: /* cluster_type_item: T_DLINE  */
#line 1925 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5501 "conf_parser.c"
    break;

  case 386: /* cluster_type_item: T_UNDLINE  */
#line 1929 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5510 "conf_parser.c"
    break;

  case 387: /* cluster_type_item: XLINE  */
#line 1933 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5519 "conf_parser.c"
    break;

  case 388: /* cluster_type_item: T_UNXLINE  */
#line 1937 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5528 "conf_parser.c"
    break;

  case 389: /* cluster_type_item: RESV  */
#line 1941 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5537 "conf_parser.c"
    break;

  case 390: /* cluster_type_item: T_UNRESV  */
#line 1945 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5546 "conf_parser.c"
    break;

  case 391: /* cluster_type_item: T_LOCOPS  */
#line 1949 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5555 "conf_parser.c"
    break;

  case 392: /* cluster_type_item: T_ALL  */
#line 1953 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5564 "conf_parser.c"
    break;

  case 393: /* $@20: %empty  */
#line 1963 "conf_parser.y"
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

  case 394: /* connect_entry: CONNECT $@20 '{' connect_items '}' ';'  */
#line 1973 "conf_parser.y"
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

  case 413: /* connect_name: NAME '=' QSTRING ';'  */
#line 2059 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5659 "conf_parser.c"
    break;

  case 414: /* connect_host: HOST '=' QSTRING ';'  */
#line 2065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5668 "conf_parser.c"
    break;

  case 415: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 2071 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5677 "conf_parser.c"
    break;

  case 416: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 2077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5686 "conf_parser.c"
    break;

  case 417: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2083 "conf_parser.y"
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

  case 418: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2096 "conf_parser.y"
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

  case 419: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5727 "conf_parser.c"
    break;

  case 420: /* connect_port: PORT '=' NUMBER ';'  */
#line 2115 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5736 "conf_parser.c"
    break;

  case 421: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2121 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5745 "conf_parser.c"
    break;

  case 422: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5754 "conf_parser.c"
    break;

  case 423: /* $@21: %empty  */
#line 2131 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5762 "conf_parser.c"
    break;

  case 427: /* connect_flags_item: AUTOCONN  */
#line 2137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5771 "conf_parser.c"
    break;

  case 428: /* connect_flags_item: T_TLS  */
#line 2141 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5780 "conf_parser.c"
    break;

  case 429: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2147 "conf_parser.y"
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

  case 430: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2158 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5803 "conf_parser.c"
    break;

  case 431: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2164 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5812 "conf_parser.c"
    break;

  case 432: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2170 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5821 "conf_parser.c"
    break;

  case 433: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2176 "conf_parser.y"
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

  case 434: /* $@22: %empty  */
#line 2191 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5844 "conf_parser.c"
    break;

  case 435: /* kill_entry: KILL $@22 '{' kill_items '}' ';'  */
#line 2195 "conf_parser.y"
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

  case 441: /* kill_user: USER '=' QSTRING ';'  */
#line 2218 "conf_parser.y"
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

  case 442: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2238 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5899 "conf_parser.c"
    break;

  case 443: /* $@23: %empty  */
#line 2248 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5908 "conf_parser.c"
    break;

  case 444: /* deny_entry: DENY $@23 '{' deny_items '}' ';'  */
#line 2252 "conf_parser.y"
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

  case 450: /* deny_ip: IP '=' QSTRING ';'  */
#line 2276 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5941 "conf_parser.c"
    break;

  case 451: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2282 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5950 "conf_parser.c"
    break;

  case 457: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2297 "conf_parser.y"
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

  case 458: /* $@24: %empty  */
#line 2314 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5976 "conf_parser.c"
    break;

  case 459: /* gecos_entry: GECOS $@24 '{' gecos_items '}' ';'  */
#line 2318 "conf_parser.y"
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

  case 465: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2338 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 6005 "conf_parser.c"
    break;

  case 466: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2344 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 6014 "conf_parser.c"
    break;

  case 522: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2411 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 6022 "conf_parser.c"
    break;

  case 523: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2416 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 6030 "conf_parser.c"
    break;

  case 524: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2421 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 6038 "conf_parser.c"
    break;

  case 525: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2426 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 6046 "conf_parser.c"
    break;

  case 526: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2431 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 6054 "conf_parser.c"
    break;

  case 527: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2436 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 6062 "conf_parser.c"
    break;

  case 528: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2441 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 6070 "conf_parser.c"
    break;

  case 529: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2446 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6078 "conf_parser.c"
    break;

  case 530: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2451 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6086 "conf_parser.c"
    break;

  case 531: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2456 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6094 "conf_parser.c"
    break;

  case 532: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2461 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 6102 "conf_parser.c"
    break;

  case 533: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2466 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 6110 "conf_parser.c"
    break;

  case 534: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2471 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6118 "conf_parser.c"
    break;

  case 535: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2476 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6126 "conf_parser.c"
    break;

  case 536: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2481 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6134 "conf_parser.c"
    break;

  case 537: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2486 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6142 "conf_parser.c"
    break;

  case 538: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2491 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6150 "conf_parser.c"
    break;

  case 539: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2496 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6158 "conf_parser.c"
    break;

  case 540: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2501 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6166 "conf_parser.c"
    break;

  case 541: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2506 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6174 "conf_parser.c"
    break;

  case 542: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2511 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6182 "conf_parser.c"
    break;

  case 543: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2516 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 6190 "conf_parser.c"
    break;

  case 544: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2521 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 6198 "conf_parser.c"
    break;

  case 545: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2526 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 6206 "conf_parser.c"
    break;

  case 546: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2531 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6214 "conf_parser.c"
    break;

  case 547: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2536 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 6222 "conf_parser.c"
    break;

  case 548: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2541 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 6230 "conf_parser.c"
    break;

  case 549: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2546 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6238 "conf_parser.c"
    break;

  case 550: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2551 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6246 "conf_parser.c"
    break;

  case 551: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2556 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6254 "conf_parser.c"
    break;

  case 552: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2561 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6262 "conf_parser.c"
    break;

  case 553: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2566 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6270 "conf_parser.c"
    break;

  case 554: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2571 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6278 "conf_parser.c"
    break;

  case 555: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2576 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6286 "conf_parser.c"
    break;

  case 556: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2581 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6294 "conf_parser.c"
    break;

  case 557: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2586 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6302 "conf_parser.c"
    break;

  case 558: /* general_disable_auth: DISABLE_AUTH '=' TBOOL ';'  */
#line 2591 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6310 "conf_parser.c"
    break;

  case 559: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2596 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6318 "conf_parser.c"
    break;

  case 560: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2601 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6326 "conf_parser.c"
    break;

  case 561: /* $@25: %empty  */
#line 2606 "conf_parser.y"
{
  ConfigGeneral.oper_umodes = 0;
}
#line 6334 "conf_parser.c"
    break;

  case 565: /* umode_oitem: BOT  */
#line 2612 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_BOT;
}
#line 6342 "conf_parser.c"
    break;

  case 566: /* umode_oitem: T_CCONN  */
#line 2615 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6350 "conf_parser.c"
    break;

  case 567: /* umode_oitem: T_DEAF  */
#line 2618 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6358 "conf_parser.c"
    break;

  case 568: /* umode_oitem: T_FLOOD  */
#line 2621 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FLOOD;
}
#line 6366 "conf_parser.c"
    break;

  case 569: /* umode_oitem: HIDDEN  */
#line 2624 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6374 "conf_parser.c"
    break;

  case 570: /* umode_oitem: HIDE_CHANS  */
#line 2627 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6382 "conf_parser.c"
    break;

  case 571: /* umode_oitem: HIDE_IDLE  */
#line 2630 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6390 "conf_parser.c"
    break;

  case 572: /* umode_oitem: T_SKILL  */
#line 2633 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6398 "conf_parser.c"
    break;

  case 573: /* umode_oitem: T_NCHANGE  */
#line 2636 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6406 "conf_parser.c"
    break;

  case 574: /* umode_oitem: T_REJ  */
#line 2639 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6414 "conf_parser.c"
    break;

  case 575: /* umode_oitem: T_SPY  */
#line 2642 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6422 "conf_parser.c"
    break;

  case 576: /* umode_oitem: T_EXTERNAL  */
#line 2645 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6430 "conf_parser.c"
    break;

  case 577: /* umode_oitem: T_SERVNOTICE  */
#line 2648 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6438 "conf_parser.c"
    break;

  case 578: /* umode_oitem: T_INVISIBLE  */
#line 2651 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6446 "conf_parser.c"
    break;

  case 579: /* umode_oitem: T_WALLOP  */
#line 2654 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6454 "conf_parser.c"
    break;

  case 580: /* umode_oitem: T_SOFTCALLERID  */
#line 2657 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6462 "conf_parser.c"
    break;

  case 581: /* umode_oitem: T_CALLERID  */
#line 2660 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6470 "conf_parser.c"
    break;

  case 582: /* umode_oitem: T_LOCOPS  */
#line 2663 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6478 "conf_parser.c"
    break;

  case 583: /* umode_oitem: T_NONONREG  */
#line 2666 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6486 "conf_parser.c"
    break;

  case 584: /* umode_oitem: T_FARCONNECT  */
#line 2669 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6494 "conf_parser.c"
    break;

  case 585: /* umode_oitem: EXPIRATION  */
#line 2672 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6502 "conf_parser.c"
    break;

  case 586: /* umode_oitem: T_SECUREONLY  */
#line 2675 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SECUREONLY;
}
#line 6510 "conf_parser.c"
    break;

  case 587: /* $@26: %empty  */
#line 2680 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6518 "conf_parser.c"
    break;

  case 591: /* umode_item: BOT  */
#line 2686 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_BOT;
}
#line 6526 "conf_parser.c"
    break;

  case 592: /* umode_item: T_CCONN  */
#line 2689 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6534 "conf_parser.c"
    break;

  case 593: /* umode_item: T_DEAF  */
#line 2692 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6542 "conf_parser.c"
    break;

  case 594: /* umode_item: T_FLOOD  */
#line 2695 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FLOOD;
}
#line 6550 "conf_parser.c"
    break;

  case 595: /* umode_item: T_SKILL  */
#line 2698 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6558 "conf_parser.c"
    break;

  case 596: /* umode_item: HIDDEN  */
#line 2701 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6566 "conf_parser.c"
    break;

  case 597: /* umode_item: HIDE_CHANS  */
#line 2704 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDECHANS;
}
#line 6574 "conf_parser.c"
    break;

  case 598: /* umode_item: HIDE_IDLE  */
#line 2707 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDEIDLE;
}
#line 6582 "conf_parser.c"
    break;

  case 599: /* umode_item: T_NCHANGE  */
#line 2710 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6590 "conf_parser.c"
    break;

  case 600: /* umode_item: T_REJ  */
#line 2713 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6598 "conf_parser.c"
    break;

  case 601: /* umode_item: T_SPY  */
#line 2716 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6606 "conf_parser.c"
    break;

  case 602: /* umode_item: T_EXTERNAL  */
#line 2719 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6614 "conf_parser.c"
    break;

  case 603: /* umode_item: T_SERVNOTICE  */
#line 2722 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6622 "conf_parser.c"
    break;

  case 604: /* umode_item: T_INVISIBLE  */
#line 2725 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6630 "conf_parser.c"
    break;

  case 605: /* umode_item: T_WALLOP  */
#line 2728 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6638 "conf_parser.c"
    break;

  case 606: /* umode_item: T_SOFTCALLERID  */
#line 2731 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6646 "conf_parser.c"
    break;

  case 607: /* umode_item: T_CALLERID  */
#line 2734 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6654 "conf_parser.c"
    break;

  case 608: /* umode_item: T_LOCOPS  */
#line 2737 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6662 "conf_parser.c"
    break;

  case 609: /* umode_item: T_NONONREG  */
#line 2740 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6670 "conf_parser.c"
    break;

  case 610: /* umode_item: T_FARCONNECT  */
#line 2743 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6678 "conf_parser.c"
    break;

  case 611: /* umode_item: EXPIRATION  */
#line 2746 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6686 "conf_parser.c"
    break;

  case 612: /* umode_item: T_SECUREONLY  */
#line 2749 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SECUREONLY;
}
#line 6694 "conf_parser.c"
    break;

  case 613: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2754 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6702 "conf_parser.c"
    break;

  case 614: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2759 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6710 "conf_parser.c"
    break;

  case 615: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2764 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6718 "conf_parser.c"
    break;

  case 616: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2769 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6726 "conf_parser.c"
    break;

  case 617: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2774 "conf_parser.y"
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

  case 618: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2791 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6757 "conf_parser.c"
    break;

  case 619: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2799 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6768 "conf_parser.c"
    break;

  case 620: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2807 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6779 "conf_parser.c"
    break;

  case 621: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2815 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6792 "conf_parser.c"
    break;

  case 622: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2825 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6805 "conf_parser.c"
    break;

  case 644: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2860 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6813 "conf_parser.c"
    break;

  case 645: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2865 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6822 "conf_parser.c"
    break;

  case 646: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2871 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6831 "conf_parser.c"
    break;

  case 647: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2877 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6839 "conf_parser.c"
    break;

  case 648: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2882 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6847 "conf_parser.c"
    break;

  case 649: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2887 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6855 "conf_parser.c"
    break;

  case 650: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2892 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6863 "conf_parser.c"
    break;

  case 651: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2897 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6871 "conf_parser.c"
    break;

  case 652: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2902 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6879 "conf_parser.c"
    break;

  case 653: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2907 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6887 "conf_parser.c"
    break;

  case 654: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2912 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6895 "conf_parser.c"
    break;

  case 655: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2917 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6903 "conf_parser.c"
    break;

  case 656: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2922 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6911 "conf_parser.c"
    break;

  case 657: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2927 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6919 "conf_parser.c"
    break;

  case 658: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2932 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6927 "conf_parser.c"
    break;

  case 659: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2937 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6935 "conf_parser.c"
    break;

  case 660: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2942 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6943 "conf_parser.c"
    break;

  case 674: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2965 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6952 "conf_parser.c"
    break;

  case 675: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2971 "conf_parser.y"
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

  case 676: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2987 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6983 "conf_parser.c"
    break;

  case 677: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2996 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6992 "conf_parser.c"
    break;

  case 678: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 3002 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 7001 "conf_parser.c"
    break;

  case 679: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 3008 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 7010 "conf_parser.c"
    break;

  case 680: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 3014 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 7022 "conf_parser.c"
    break;

  case 681: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 3023 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 7031 "conf_parser.c"
    break;

  case 682: /* serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'  */
#line 3029 "conf_parser.y"
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

