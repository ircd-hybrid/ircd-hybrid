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
    FAILED_OPER_NOTICE = 308,      /* FAILED_OPER_NOTICE  */
    FLATTEN_LINKS = 309,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 310,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 311,      /* FLATTEN_LINKS_FILE  */
    GECOS = 312,                   /* GECOS  */
    GENERAL = 313,                 /* GENERAL  */
    HIDDEN = 314,                  /* HIDDEN  */
    HIDDEN_NAME = 315,             /* HIDDEN_NAME  */
    HIDE_CHANS = 316,              /* HIDE_CHANS  */
    HIDE_IDLE = 317,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 318,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVER_IPS = 319,         /* HIDE_SERVER_IPS  */
    HIDE_SERVERS = 320,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 321,           /* HIDE_SERVICES  */
    HOST = 322,                    /* HOST  */
    HUB = 323,                     /* HUB  */
    HUB_MASK = 324,                /* HUB_MASK  */
    INVISIBLE_ON_CONNECT = 325,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 326,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 327,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 328,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 329,      /* INVITE_EXPIRE_TIME  */
    IP = 330,                      /* IP  */
    IRCD_AUTH = 331,               /* IRCD_AUTH  */
    IRCD_FLAGS = 332,              /* IRCD_FLAGS  */
    IRCD_SID = 333,                /* IRCD_SID  */
    JOIN = 334,                    /* JOIN  */
    KILL = 335,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 336,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 337,                   /* KLINE  */
    KLINE_EXEMPT = 338,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 339,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 340,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 341,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 342,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 343,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 344,               /* LEAF_MASK  */
    LISTEN = 345,                  /* LISTEN  */
    LOADMODULE = 346,              /* LOADMODULE  */
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
    MODULE_BASE_PATH = 367,        /* MODULE_BASE_PATH  */
    MOTD = 368,                    /* MOTD  */
    MOTD_FILE = 369,               /* MOTD_FILE  */
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
    RESIDENT = 398,                /* RESIDENT  */
    RESV = 399,                    /* RESV  */
    RESV_EXEMPT = 400,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 401,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 402,                 /* SECONDS  */
    MINUTES = 403,                 /* MINUTES  */
    HOURS = 404,                   /* HOURS  */
    DAYS = 405,                    /* DAYS  */
    WEEKS = 406,                   /* WEEKS  */
    MONTHS = 407,                  /* MONTHS  */
    YEARS = 408,                   /* YEARS  */
    SEND_PASSWORD = 409,           /* SEND_PASSWORD  */
    SENDQ = 410,                   /* SENDQ  */
    SERVERHIDE = 411,              /* SERVERHIDE  */
    SERVERINFO = 412,              /* SERVERINFO  */
    SHORT_MOTD = 413,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 414,       /* SPECIALS_IN_IDENT  */
    SPOOF = 415,                   /* SPOOF  */
    SQUIT = 416,                   /* SQUIT  */
    STATS_E_DISABLED = 417,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 418,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 419,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 420,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 421,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 422,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 423,       /* STATS_U_OPER_ONLY  */
    T_ALL = 424,                   /* T_ALL  */
    T_BIND = 425,                  /* T_BIND  */
    T_COMMAND = 426,               /* T_COMMAND  */
    T_CLUSTER = 427,               /* T_CLUSTER  */
    T_DEBUG = 428,                 /* T_DEBUG  */
    T_DLINE = 429,                 /* T_DLINE  */
    T_FILE = 430,                  /* T_FILE  */
    T_GLOBOPS = 431,               /* T_GLOBOPS  */
    T_IPV4 = 432,                  /* T_IPV4  */
    T_IPV6 = 433,                  /* T_IPV6  */
    T_LOCOPS = 434,                /* T_LOCOPS  */
    T_LOG = 435,                   /* T_LOG  */
    T_OPME = 436,                  /* T_OPME  */
    T_PREPEND = 437,               /* T_PREPEND  */
    T_PSEUDO = 438,                /* T_PSEUDO  */
    T_RECVQ = 439,                 /* T_RECVQ  */
    T_RESTART = 440,               /* T_RESTART  */
    T_SERVER = 441,                /* T_SERVER  */
    T_SERVICE = 442,               /* T_SERVICE  */
    T_SET = 443,                   /* T_SET  */
    T_SHARED = 444,                /* T_SHARED  */
    T_SIZE = 445,                  /* T_SIZE  */
    T_TARGET = 446,                /* T_TARGET  */
    T_TLS = 447,                   /* T_TLS  */
    T_UMODES = 448,                /* T_UMODES  */
    T_UNDLINE = 449,               /* T_UNDLINE  */
    T_UNLIMITED = 450,             /* T_UNLIMITED  */
    T_UNRESV = 451,                /* T_UNRESV  */
    T_UNXLINE = 452,               /* T_UNXLINE  */
    T_WEBIRC = 453,                /* T_WEBIRC  */
    TBOOL = 454,                   /* TBOOL  */
    THROTTLE_COUNT = 455,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 456,           /* THROTTLE_TIME  */
    TIMEOUT = 457,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 458,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 459, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 460,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 461,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 462, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 463,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 464, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 465,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 466,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 467,           /* TS_WARN_DELTA  */
    TWODOTS = 468,                 /* TWODOTS  */
    TYPE = 469,                    /* TYPE  */
    UNKLINE = 470,                 /* UNKLINE  */
    USE_LOGGING = 471,             /* USE_LOGGING  */
    USER = 472,                    /* USER  */
    VHOST = 473,                   /* VHOST  */
    VHOST6 = 474,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 475,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 476,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 477,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 478,                   /* XLINE  */
    XLINE_EXEMPT = 479,            /* XLINE_EXEMPT  */
    QSTRING = 480,                 /* QSTRING  */
    NUMBER = 481                   /* NUMBER  */
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
#define FAILED_OPER_NOTICE 308
#define FLATTEN_LINKS 309
#define FLATTEN_LINKS_DELAY 310
#define FLATTEN_LINKS_FILE 311
#define GECOS 312
#define GENERAL 313
#define HIDDEN 314
#define HIDDEN_NAME 315
#define HIDE_CHANS 316
#define HIDE_IDLE 317
#define HIDE_IDLE_FROM_OPERS 318
#define HIDE_SERVER_IPS 319
#define HIDE_SERVERS 320
#define HIDE_SERVICES 321
#define HOST 322
#define HUB 323
#define HUB_MASK 324
#define INVISIBLE_ON_CONNECT 325
#define INVITE_CLIENT_COUNT 326
#define INVITE_CLIENT_TIME 327
#define INVITE_DELAY_CHANNEL 328
#define INVITE_EXPIRE_TIME 329
#define IP 330
#define IRCD_AUTH 331
#define IRCD_FLAGS 332
#define IRCD_SID 333
#define JOIN 334
#define KILL 335
#define KILL_CHASE_TIME_LIMIT 336
#define KLINE 337
#define KLINE_EXEMPT 338
#define KLINE_MIN_CIDR 339
#define KLINE_MIN_CIDR6 340
#define KNOCK_CLIENT_COUNT 341
#define KNOCK_CLIENT_TIME 342
#define KNOCK_DELAY_CHANNEL 343
#define LEAF_MASK 344
#define LISTEN 345
#define LOADMODULE 346
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
#define MODULE_BASE_PATH 367
#define MOTD 368
#define MOTD_FILE 369
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
#define RESIDENT 398
#define RESV 399
#define RESV_EXEMPT 400
#define RSA_PRIVATE_KEY_FILE 401
#define SECONDS 402
#define MINUTES 403
#define HOURS 404
#define DAYS 405
#define WEEKS 406
#define MONTHS 407
#define YEARS 408
#define SEND_PASSWORD 409
#define SENDQ 410
#define SERVERHIDE 411
#define SERVERINFO 412
#define SHORT_MOTD 413
#define SPECIALS_IN_IDENT 414
#define SPOOF 415
#define SQUIT 416
#define STATS_E_DISABLED 417
#define STATS_I_OPER_ONLY 418
#define STATS_K_OPER_ONLY 419
#define STATS_M_OPER_ONLY 420
#define STATS_O_OPER_ONLY 421
#define STATS_P_OPER_ONLY 422
#define STATS_U_OPER_ONLY 423
#define T_ALL 424
#define T_BIND 425
#define T_COMMAND 426
#define T_CLUSTER 427
#define T_DEBUG 428
#define T_DLINE 429
#define T_FILE 430
#define T_GLOBOPS 431
#define T_IPV4 432
#define T_IPV6 433
#define T_LOCOPS 434
#define T_LOG 435
#define T_OPME 436
#define T_PREPEND 437
#define T_PSEUDO 438
#define T_RECVQ 439
#define T_RESTART 440
#define T_SERVER 441
#define T_SERVICE 442
#define T_SET 443
#define T_SHARED 444
#define T_SIZE 445
#define T_TARGET 446
#define T_TLS 447
#define T_UMODES 448
#define T_UNDLINE 449
#define T_UNLIMITED 450
#define T_UNRESV 451
#define T_UNXLINE 452
#define T_WEBIRC 453
#define TBOOL 454
#define THROTTLE_COUNT 455
#define THROTTLE_TIME 456
#define TIMEOUT 457
#define TLS_CERTIFICATE_FILE 458
#define TLS_CERTIFICATE_FINGERPRINT 459
#define TLS_CIPHER_LIST 460
#define TLS_CIPHER_SUITES 461
#define TLS_CONNECTION_REQUIRED 462
#define TLS_DH_PARAM_FILE 463
#define TLS_MESSAGE_DIGEST_ALGORITHM 464
#define TLS_SUPPORTED_GROUPS 465
#define TS_MAX_DELTA 466
#define TS_WARN_DELTA 467
#define TWODOTS 468
#define TYPE 469
#define UNKLINE 470
#define USE_LOGGING 471
#define USER 472
#define VHOST 473
#define VHOST6 474
#define WARN_NO_CONNECT_BLOCK 475
#define WHOIS 476
#define WHOWAS_HISTORY_LENGTH 477
#define XLINE 478
#define XLINE_EXEMPT 479
#define QSTRING 480
#define NUMBER 481

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 135 "conf_parser.y"

  int number;
  char *string;

#line 689 "conf_parser.c"

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
  YYSYMBOL_FAILED_OPER_NOTICE = 53,        /* FAILED_OPER_NOTICE  */
  YYSYMBOL_FLATTEN_LINKS = 54,             /* FLATTEN_LINKS  */
  YYSYMBOL_FLATTEN_LINKS_DELAY = 55,       /* FLATTEN_LINKS_DELAY  */
  YYSYMBOL_FLATTEN_LINKS_FILE = 56,        /* FLATTEN_LINKS_FILE  */
  YYSYMBOL_GECOS = 57,                     /* GECOS  */
  YYSYMBOL_GENERAL = 58,                   /* GENERAL  */
  YYSYMBOL_HIDDEN = 59,                    /* HIDDEN  */
  YYSYMBOL_HIDDEN_NAME = 60,               /* HIDDEN_NAME  */
  YYSYMBOL_HIDE_CHANS = 61,                /* HIDE_CHANS  */
  YYSYMBOL_HIDE_IDLE = 62,                 /* HIDE_IDLE  */
  YYSYMBOL_HIDE_IDLE_FROM_OPERS = 63,      /* HIDE_IDLE_FROM_OPERS  */
  YYSYMBOL_HIDE_SERVER_IPS = 64,           /* HIDE_SERVER_IPS  */
  YYSYMBOL_HIDE_SERVERS = 65,              /* HIDE_SERVERS  */
  YYSYMBOL_HIDE_SERVICES = 66,             /* HIDE_SERVICES  */
  YYSYMBOL_HOST = 67,                      /* HOST  */
  YYSYMBOL_HUB = 68,                       /* HUB  */
  YYSYMBOL_HUB_MASK = 69,                  /* HUB_MASK  */
  YYSYMBOL_INVISIBLE_ON_CONNECT = 70,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 71,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 72,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 73,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 74,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 75,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 76,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 77,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 78,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 79,                      /* JOIN  */
  YYSYMBOL_KILL = 80,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 81,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 82,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 83,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 84,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 85,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 86,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 87,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 88,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 89,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 90,                    /* LISTEN  */
  YYSYMBOL_LOADMODULE = 91,                /* LOADMODULE  */
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
  YYSYMBOL_MODULE_BASE_PATH = 112,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 113,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 114,                /* MOTD_FILE  */
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
  YYSYMBOL_RESIDENT = 143,                 /* RESIDENT  */
  YYSYMBOL_RESV = 144,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 145,              /* RESV_EXEMPT  */
  YYSYMBOL_RSA_PRIVATE_KEY_FILE = 146,     /* RSA_PRIVATE_KEY_FILE  */
  YYSYMBOL_SECONDS = 147,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 148,                  /* MINUTES  */
  YYSYMBOL_HOURS = 149,                    /* HOURS  */
  YYSYMBOL_DAYS = 150,                     /* DAYS  */
  YYSYMBOL_WEEKS = 151,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 152,                   /* MONTHS  */
  YYSYMBOL_YEARS = 153,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 154,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 155,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 156,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 157,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 158,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 159,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 160,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 161,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 162,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_I_OPER_ONLY = 163,        /* STATS_I_OPER_ONLY  */
  YYSYMBOL_STATS_K_OPER_ONLY = 164,        /* STATS_K_OPER_ONLY  */
  YYSYMBOL_STATS_M_OPER_ONLY = 165,        /* STATS_M_OPER_ONLY  */
  YYSYMBOL_STATS_O_OPER_ONLY = 166,        /* STATS_O_OPER_ONLY  */
  YYSYMBOL_STATS_P_OPER_ONLY = 167,        /* STATS_P_OPER_ONLY  */
  YYSYMBOL_STATS_U_OPER_ONLY = 168,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 169,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 170,                   /* T_BIND  */
  YYSYMBOL_T_COMMAND = 171,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 172,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 173,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 174,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 175,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 176,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 177,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 178,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 179,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 180,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 181,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 182,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 183,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 184,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 185,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 186,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 187,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 188,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 189,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 190,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 191,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 192,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 193,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 194,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 195,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 196,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 197,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 198,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 199,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 200,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 201,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 202,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 203,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 204, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 205,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 206,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 207,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 208,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 209, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 210,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 211,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 212,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 213,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 214,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 215,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 216,              /* USE_LOGGING  */
  YYSYMBOL_USER = 217,                     /* USER  */
  YYSYMBOL_VHOST = 218,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 219,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 220,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 221,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 222,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 223,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 224,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 225,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 226,                   /* NUMBER  */
  YYSYMBOL_227_ = 227,                     /* ';'  */
  YYSYMBOL_228_ = 228,                     /* '}'  */
  YYSYMBOL_229_ = 229,                     /* '='  */
  YYSYMBOL_230_ = 230,                     /* ':'  */
  YYSYMBOL_231_ = 231,                     /* ','  */
  YYSYMBOL_232_ = 232,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 233,                 /* $accept  */
  YYSYMBOL_conf = 234,                     /* conf  */
  YYSYMBOL_conf_item = 235,                /* conf_item  */
  YYSYMBOL_timespec_ = 236,                /* timespec_  */
  YYSYMBOL_timespec = 237,                 /* timespec  */
  YYSYMBOL_sizespec_ = 238,                /* sizespec_  */
  YYSYMBOL_sizespec = 239,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 240,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 241,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 242,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 243,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 244,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 245,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 246,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 247,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 248, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 249, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 250, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 251, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 252, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 253, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 254, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 255,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 256,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 257,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 258,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 259, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 260, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 261, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 262, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_motd_file = 263,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 264,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 265,              /* admin_entry  */
  YYSYMBOL_admin_items = 266,              /* admin_items  */
  YYSYMBOL_admin_item = 267,               /* admin_item  */
  YYSYMBOL_admin_name = 268,               /* admin_name  */
  YYSYMBOL_admin_email = 269,              /* admin_email  */
  YYSYMBOL_admin_description = 270,        /* admin_description  */
  YYSYMBOL_motd_entry = 271,               /* motd_entry  */
  YYSYMBOL_272_1 = 272,                    /* $@1  */
  YYSYMBOL_motd_items = 273,               /* motd_items  */
  YYSYMBOL_motd_item = 274,                /* motd_item  */
  YYSYMBOL_motd_mask = 275,                /* motd_mask  */
  YYSYMBOL_motd_file = 276,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 277,             /* pseudo_entry  */
  YYSYMBOL_278_2 = 278,                    /* $@2  */
  YYSYMBOL_pseudo_items = 279,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 280,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 281,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 282,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 283,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 284,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 285,            /* logging_entry  */
  YYSYMBOL_logging_items = 286,            /* logging_items  */
  YYSYMBOL_logging_item = 287,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 288,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 289,       /* logging_file_entry  */
  YYSYMBOL_290_3 = 290,                    /* $@3  */
  YYSYMBOL_logging_file_items = 291,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 292,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 293,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 294,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 295,        /* logging_file_type  */
  YYSYMBOL_296_4 = 296,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 297,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 298,               /* oper_entry  */
  YYSYMBOL_299_5 = 299,                    /* $@5  */
  YYSYMBOL_oper_items = 300,               /* oper_items  */
  YYSYMBOL_oper_item = 301,                /* oper_item  */
  YYSYMBOL_oper_name = 302,                /* oper_name  */
  YYSYMBOL_oper_user = 303,                /* oper_user  */
  YYSYMBOL_oper_password = 304,            /* oper_password  */
  YYSYMBOL_oper_whois = 305,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 306,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 307, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 308, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 309,               /* oper_class  */
  YYSYMBOL_oper_umodes = 310,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 311,               /* oper_flags  */
  YYSYMBOL_312_6 = 312,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 313,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 314,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 315,              /* class_entry  */
  YYSYMBOL_316_7 = 316,                    /* $@7  */
  YYSYMBOL_class_items = 317,              /* class_items  */
  YYSYMBOL_class_item = 318,               /* class_item  */
  YYSYMBOL_class_name = 319,               /* class_name  */
  YYSYMBOL_class_ping_time = 320,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 321, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 322, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 323,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 324,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 325,         /* class_max_number  */
  YYSYMBOL_class_sendq = 326,              /* class_sendq  */
  YYSYMBOL_class_recvq = 327,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 328,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 329,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 330,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 331,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 332,           /* class_max_idle  */
  YYSYMBOL_class_flags = 333,              /* class_flags  */
  YYSYMBOL_334_8 = 334,                    /* $@8  */
  YYSYMBOL_class_flags_items = 335,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 336,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 337,             /* listen_entry  */
  YYSYMBOL_338_9 = 338,                    /* $@9  */
  YYSYMBOL_listen_flags = 339,             /* listen_flags  */
  YYSYMBOL_340_10 = 340,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 341,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 342,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 343,             /* listen_items  */
  YYSYMBOL_listen_item = 344,              /* listen_item  */
  YYSYMBOL_listen_port = 345,              /* listen_port  */
  YYSYMBOL_346_11 = 346,                   /* $@11  */
  YYSYMBOL_port_items = 347,               /* port_items  */
  YYSYMBOL_port_item = 348,                /* port_item  */
  YYSYMBOL_listen_address = 349,           /* listen_address  */
  YYSYMBOL_listen_host = 350,              /* listen_host  */
  YYSYMBOL_auth_entry = 351,               /* auth_entry  */
  YYSYMBOL_352_12 = 352,                   /* $@12  */
  YYSYMBOL_auth_items = 353,               /* auth_items  */
  YYSYMBOL_auth_item = 354,                /* auth_item  */
  YYSYMBOL_auth_user = 355,                /* auth_user  */
  YYSYMBOL_auth_passwd = 356,              /* auth_passwd  */
  YYSYMBOL_auth_class = 357,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 358,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 359,               /* auth_flags  */
  YYSYMBOL_360_13 = 360,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 361,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 362,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 363,               /* auth_spoof  */
  YYSYMBOL_auth_redir_serv = 364,          /* auth_redir_serv  */
  YYSYMBOL_auth_redir_port = 365,          /* auth_redir_port  */
  YYSYMBOL_resv_entry = 366,               /* resv_entry  */
  YYSYMBOL_367_14 = 367,                   /* $@14  */
  YYSYMBOL_resv_items = 368,               /* resv_items  */
  YYSYMBOL_resv_item = 369,                /* resv_item  */
  YYSYMBOL_resv_mask = 370,                /* resv_mask  */
  YYSYMBOL_resv_reason = 371,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 372,              /* resv_exempt  */
  YYSYMBOL_service_entry = 373,            /* service_entry  */
  YYSYMBOL_service_items = 374,            /* service_items  */
  YYSYMBOL_service_item = 375,             /* service_item  */
  YYSYMBOL_service_name = 376,             /* service_name  */
  YYSYMBOL_shared_entry = 377,             /* shared_entry  */
  YYSYMBOL_378_15 = 378,                   /* $@15  */
  YYSYMBOL_shared_items = 379,             /* shared_items  */
  YYSYMBOL_shared_item = 380,              /* shared_item  */
  YYSYMBOL_shared_name = 381,              /* shared_name  */
  YYSYMBOL_shared_user = 382,              /* shared_user  */
  YYSYMBOL_shared_type = 383,              /* shared_type  */
  YYSYMBOL_384_16 = 384,                   /* $@16  */
  YYSYMBOL_shared_types = 385,             /* shared_types  */
  YYSYMBOL_shared_type_item = 386,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 387,            /* cluster_entry  */
  YYSYMBOL_388_17 = 388,                   /* $@17  */
  YYSYMBOL_cluster_items = 389,            /* cluster_items  */
  YYSYMBOL_cluster_item = 390,             /* cluster_item  */
  YYSYMBOL_cluster_name = 391,             /* cluster_name  */
  YYSYMBOL_cluster_type = 392,             /* cluster_type  */
  YYSYMBOL_393_18 = 393,                   /* $@18  */
  YYSYMBOL_cluster_types = 394,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 395,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 396,            /* connect_entry  */
  YYSYMBOL_397_19 = 397,                   /* $@19  */
  YYSYMBOL_connect_items = 398,            /* connect_items  */
  YYSYMBOL_connect_item = 399,             /* connect_item  */
  YYSYMBOL_connect_name = 400,             /* connect_name  */
  YYSYMBOL_connect_host = 401,             /* connect_host  */
  YYSYMBOL_connect_timeout = 402,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 403,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 404,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 405,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 406, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 407,             /* connect_port  */
  YYSYMBOL_connect_aftype = 408,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 409,            /* connect_flags  */
  YYSYMBOL_410_20 = 410,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 411,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 412,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 413,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 414,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 415,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 416,            /* connect_class  */
  YYSYMBOL_connect_tls_cipher_list = 417,  /* connect_tls_cipher_list  */
  YYSYMBOL_kill_entry = 418,               /* kill_entry  */
  YYSYMBOL_419_21 = 419,                   /* $@21  */
  YYSYMBOL_kill_items = 420,               /* kill_items  */
  YYSYMBOL_kill_item = 421,                /* kill_item  */
  YYSYMBOL_kill_user = 422,                /* kill_user  */
  YYSYMBOL_kill_reason = 423,              /* kill_reason  */
  YYSYMBOL_deny_entry = 424,               /* deny_entry  */
  YYSYMBOL_425_22 = 425,                   /* $@22  */
  YYSYMBOL_deny_items = 426,               /* deny_items  */
  YYSYMBOL_deny_item = 427,                /* deny_item  */
  YYSYMBOL_deny_ip = 428,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 429,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 430,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 431,             /* exempt_items  */
  YYSYMBOL_exempt_item = 432,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 433,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 434,              /* gecos_entry  */
  YYSYMBOL_435_23 = 435,                   /* $@23  */
  YYSYMBOL_gecos_items = 436,              /* gecos_items  */
  YYSYMBOL_gecos_item = 437,               /* gecos_item  */
  YYSYMBOL_gecos_name = 438,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 439,             /* gecos_reason  */
  YYSYMBOL_general_entry = 440,            /* general_entry  */
  YYSYMBOL_general_items = 441,            /* general_items  */
  YYSYMBOL_general_item = 442,             /* general_item  */
  YYSYMBOL_general_away_count = 443,       /* general_away_count  */
  YYSYMBOL_general_away_time = 444,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 445,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 446, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 447, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 448,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 449,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 450,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 451,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 452, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 453, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 454,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 455,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 456, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 457,       /* general_max_accept  */
  YYSYMBOL_general_anti_spam_exit_message_time = 458, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 459,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 460,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 461, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 462, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 463, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 464, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 465, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 466, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 467, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 468, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 469, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 470,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 471,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 472, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 473, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 474,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 475,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 476, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 477,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 478,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_auth = 479,     /* general_disable_auth  */
  YYSYMBOL_general_throttle_count = 480,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 481,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 482,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 483,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 484, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 485, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 486, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 487,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 488, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 489, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 490,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 491,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 492,     /* general_cloak_suffix  */
  YYSYMBOL_channel_entry = 493,            /* channel_entry  */
  YYSYMBOL_channel_items = 494,            /* channel_items  */
  YYSYMBOL_channel_item = 495,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 496,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 497,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 498,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 499, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 500, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 501, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 502, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 503, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 504, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 505, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 506, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 507,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 508,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 509,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 510,   /* channel_max_bans_large  */
  YYSYMBOL_channel_default_join_flood_count = 511, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 512, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 513,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 514,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 515,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 516, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 517, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 518, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 519, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 520,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 521, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 522,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 523,        /* serverhide_hidden  */
  YYSYMBOL_serverhide_hide_server_ips = 524 /* serverhide_hide_server_ips  */
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
#define YYLAST   1220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  233
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  292
/* YYNRULES -- Number of rules.  */
#define YYNRULES  607
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1271

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   481


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
       2,     2,     2,     2,   231,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   230,   227,
       2,   229,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   232,     2,   228,     2,     2,     2,     2,
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
     225,   226
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   363,   363,   364,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   395,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   406,
     406,   407,   408,   409,   410,   417,   427,   434,   436,   438,
     438,   440,   444,   454,   456,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   477,   486,   495,   504,   513,   522,
     531,   540,   555,   570,   580,   594,   603,   626,   649,   672,
     681,   691,   693,   693,   694,   695,   696,   697,   699,   708,
     717,   731,   730,   748,   748,   749,   749,   749,   751,   757,
     768,   767,   786,   786,   787,   787,   787,   787,   787,   789,
     795,   801,   807,   830,   831,   831,   833,   833,   834,   836,
     843,   843,   856,   857,   859,   859,   860,   860,   862,   870,
     873,   879,   878,   884,   888,   892,   896,   900,   904,   908,
     912,   923,   922,   988,   988,   989,   990,   991,   992,   993,
     994,   995,   996,   997,   998,   999,  1001,  1007,  1013,  1019,
    1025,  1036,  1042,  1053,  1059,  1066,  1065,  1071,  1071,  1072,
    1076,  1080,  1084,  1088,  1092,  1096,  1100,  1104,  1108,  1112,
    1116,  1120,  1124,  1128,  1132,  1136,  1140,  1144,  1148,  1152,
    1156,  1160,  1164,  1168,  1172,  1176,  1180,  1184,  1195,  1194,
    1250,  1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,
    1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,  1268,  1274,
    1280,  1286,  1292,  1298,  1304,  1310,  1316,  1323,  1329,  1335,
    1341,  1350,  1360,  1359,  1365,  1365,  1366,  1370,  1381,  1380,
    1387,  1386,  1391,  1391,  1392,  1396,  1400,  1404,  1408,  1414,
    1414,  1415,  1415,  1415,  1415,  1415,  1417,  1417,  1419,  1419,
    1421,  1434,  1451,  1457,  1468,  1467,  1515,  1515,  1516,  1517,
    1518,  1519,  1520,  1521,  1522,  1523,  1524,  1526,  1532,  1538,
    1544,  1556,  1555,  1561,  1561,  1562,  1566,  1570,  1574,  1578,
    1582,  1586,  1590,  1594,  1600,  1614,  1623,  1637,  1636,  1651,
    1651,  1652,  1652,  1652,  1652,  1654,  1660,  1666,  1676,  1678,
    1678,  1679,  1679,  1681,  1698,  1697,  1720,  1720,  1721,  1721,
    1721,  1721,  1723,  1729,  1749,  1748,  1754,  1754,  1755,  1759,
    1763,  1767,  1771,  1775,  1779,  1783,  1787,  1791,  1802,  1801,
    1820,  1820,  1821,  1821,  1821,  1823,  1830,  1829,  1835,  1835,
    1836,  1840,  1844,  1848,  1852,  1856,  1860,  1864,  1868,  1872,
    1883,  1882,  1960,  1960,  1961,  1962,  1963,  1964,  1965,  1966,
    1967,  1968,  1969,  1970,  1971,  1972,  1973,  1974,  1975,  1976,
    1978,  1984,  1990,  1996,  2002,  2015,  2028,  2034,  2040,  2044,
    2051,  2050,  2055,  2055,  2056,  2060,  2066,  2077,  2083,  2089,
    2095,  2111,  2110,  2134,  2134,  2135,  2135,  2135,  2137,  2157,
    2168,  2167,  2192,  2192,  2193,  2193,  2193,  2195,  2201,  2211,
    2213,  2213,  2214,  2214,  2216,  2234,  2233,  2254,  2254,  2255,
    2255,  2255,  2257,  2263,  2273,  2275,  2275,  2276,  2277,  2278,
    2279,  2280,  2281,  2282,  2283,  2284,  2285,  2286,  2287,  2288,
    2289,  2290,  2291,  2292,  2293,  2294,  2295,  2296,  2297,  2298,
    2299,  2300,  2301,  2302,  2303,  2304,  2305,  2306,  2307,  2308,
    2309,  2310,  2311,  2312,  2313,  2314,  2315,  2316,  2317,  2318,
    2319,  2320,  2321,  2322,  2323,  2324,  2325,  2326,  2329,  2334,
    2339,  2344,  2349,  2354,  2359,  2364,  2369,  2374,  2379,  2384,
    2389,  2394,  2399,  2404,  2409,  2414,  2419,  2424,  2429,  2434,
    2439,  2444,  2449,  2454,  2459,  2464,  2469,  2474,  2479,  2484,
    2489,  2494,  2499,  2504,  2509,  2514,  2519,  2524,  2533,  2538,
    2543,  2548,  2553,  2570,  2578,  2586,  2594,  2604,  2617,  2619,
    2619,  2620,  2621,  2622,  2623,  2624,  2625,  2626,  2627,  2628,
    2629,  2630,  2631,  2632,  2633,  2634,  2635,  2636,  2637,  2639,
    2644,  2650,  2656,  2661,  2666,  2671,  2676,  2681,  2686,  2691,
    2696,  2701,  2706,  2711,  2716,  2721,  2730,  2732,  2732,  2733,
    2734,  2735,  2736,  2737,  2738,  2739,  2740,  2741,  2742,  2744,
    2750,  2766,  2775,  2781,  2787,  2793,  2802,  2808
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
  "AUTOCONN", "AWAY_COUNT", "AWAY_TIME", "BYTES", "KBYTES", "MBYTES",
  "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL", "CIDR_BITLEN_IPV4",
  "CIDR_BITLEN_IPV6", "CLASS", "CLIENT", "CLOAK_ENABLED",
  "CLOAK_CIDR_LEN_IPV4", "CLOAK_CIDR_LEN_IPV6", "CLOAK_NUM_BITS",
  "CLOAK_SECRET", "CLOAK_SUFFIX", "CLOSE", "CONNECT", "CONNECTFREQ",
  "CORE", "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_FLOODTIME", "DEFAULT_JOIN_FLOOD_COUNT",
  "DEFAULT_JOIN_FLOOD_TIME", "DEFAULT_MAX_CLIENTS", "DEFER", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6", "EMAIL",
  "ENABLE_ADMIN", "ENABLE_EXTBANS", "ENABLE_OWNER", "ENCRYPTED",
  "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE", "FLATTEN_LINKS",
  "FLATTEN_LINKS_DELAY", "FLATTEN_LINKS_FILE", "GECOS", "GENERAL",
  "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
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
  "general_throttle_time", "general_oper_umodes",
  "general_min_nonwildcard", "general_min_nonwildcard_simple",
  "general_default_floodcount", "general_default_floodtime",
  "general_cloak_enabled", "general_cloak_cidr_len_ipv4",
  "general_cloak_cidr_len_ipv6", "general_cloak_num_bits",
  "general_cloak_secret", "general_cloak_suffix", "channel_entry",
  "channel_items", "channel_item", "channel_enable_extbans",
  "channel_enable_owner", "channel_enable_admin",
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

#define YYPACT_NINF (-1018)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-131)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1018,   719, -1018,  -152,  -208,  -199, -1018, -1018, -1018,  -186,
   -1018,  -170, -1018, -1018, -1018,  -128,  -129, -1018, -1018, -1018,
    -119,  -118, -1018,  -117, -1018,  -107, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018,    22,   823,  -106,  -101,   -99,    44,   -89,
     438,   -88,   -87,   -86,  -127,  -114,   -78,   -63,   -40,   784,
     476,   -39,    95,   -38,     5,   -31,   -25,   -26,   -24,   -19,
       3, -1018, -1018, -1018, -1018, -1018,    12,    26,    43,    49,
      54,    61,    62,    66,    75,    79,    81,    91,    93,    94,
      96,    97,    98,   164, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018,   618,   624,    24, -1018,    99,    34, -1018, -1018,
      59, -1018,   102,   106,   107,   112,   113,   117,   119,   120,
     122,   124,   131,   132,   133,   135,   137,   146,   148,   151,
     153,   160,   161,   167,   169,   170,   171,   172,   173,   174,
     176,   180,   182,   184,   185,   186,   190,   191,   193,   197,
     202,   204,   206,   207,   209,   211,   212,   214,   220,   221,
     222,   226,    57, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018,   357,    10,   288,   -11,    46,    55,
      16,   293,    71, -1018,   228,   229,   236,   237,   238,   244,
     245,   246,   247,   116, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018,    74,   249,   251,   252,   255,   256,
     261,   263,   264,   265,   272,   273,   274,   280,   282,   284,
     289,   291,   178, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018,    40,   118,   292,    58, -1018, -1018, -1018,   -35,   239,
   -1018,   295,    38, -1018, -1018,    92, -1018,   187,   203,   243,
     298, -1018,   300,   301,   329,   332,   334,   336,   310,   301,
     301,   301,   314,   301,   301,   316,   319,   320,   323,   326,
   -1018,   328,   321,   327,   333, -1018,   340,   341,   343,   346,
     347,   348,   350,   354,   356,   358,   359,   270, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018,   330,   360,   363,   364,   369,   370,
     378, -1018,   379,   380,   381,   382,   385,   387,   391,   392,
     302, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   397,   399,
       2, -1018, -1018, -1018,   338,   331, -1018, -1018,   402,   403,
      19, -1018, -1018, -1018,   366,   301,   408,   301,   301,   434,
     411,   415,   416,   361,   420,   449,   425,   301,   453,   428,
     429,   457,   458,   301,   433,   435,   436,   437,   439,   301,
     440,   441,   442,   465,   444,   471,   301,   301,   472,   473,
     450,   481,   484,   488,   489,   490,   491,   497,   474,   301,
     301,   301,   498,   477,   475, -1018,   478,   469,   479, -1018,
     482,   495,   499,   502,   503,   199, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018,   505,   507,    36, -1018,
   -1018, -1018,   483,   508,   515, -1018,   516, -1018,    17, -1018,
   -1018, -1018, -1018, -1018, -1018,   486, -1018, -1018, -1018,   519,
     520,   521,    20, -1018, -1018, -1018,   524,   526,   529, -1018,
     531,   532,   534,   535,   537,   538,   539,   225, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   542,
     543,   545,   551,    72, -1018, -1018, -1018, -1018,   554,   563,
     301,   556,   583,   558,   587,   588,   589,   564, -1018, -1018,
     480,   571,   598,   573,   574,   575,   578,   580,   590,   591,
     592,   593,   595,   597,   605,   609,   611,   581, -1018,   585,
     584, -1018,    53, -1018, -1018, -1018, -1018,   615,   594, -1018,
     603,   614,   608,   613,   616,   622,     6, -1018, -1018, -1018,
   -1018, -1018,   627,   620, -1018,   626,   625, -1018,   630,    15,
   -1018, -1018, -1018, -1018,   628,   629,   633, -1018,   634,  -121,
     635,   637,   639,   640,   641,   642,   646,   647,   650,   651,
     652,   653,   654,   655,   656,   657, -1018, -1018,   659,   660,
     301,   658,   662,   301,   663,   301,   665,   666,   667,   672,
     301,   674,   674,   676, -1018, -1018,   679,   -92,   680,   702,
     682,   687,   684,   689,   690,   691,   696,   698,   301,   699,
     700,   701, -1018,   704,   705,   706, -1018,   707, -1018,   710,
     711,   712, -1018,   713,   714,   715,   716,   717,   718,   720,
     721,   722,   723,   724,   725,   726,   727,   728,   729,   730,
     731,   732,   733,   734,   735,   736,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   746,   747,   748,   749,   750,
     751,   752,   753,   754,   755,   756,   757,   758,   759,   760,
     761,   762,   763, -1018, -1018,   766,   793,   697,   768,   769,
     771,   772,   773,   767, -1018,   774,   775,   776, -1018, -1018,
     777,   779,   703,   780,   778, -1018,   -11, -1018,   782,   783,
     785, -1018, -1018,   786,   802,   708,   788,   789,   790,   791,
     810,   792,   794,   795, -1018, -1018,   796,   798,   799,   800,
   -1018,   801,   803,   804,   805,   806,   807,   808,   809,   811,
   -1018,   812,   813,   814,   815,   816,   817,   818,   819,   820,
     821,   822,   824,   825,   826,   827,   828,   829, -1018, -1018,
     832,   709,   831, -1018,   833, -1018,   183, -1018,   834,   836,
     837,   838,   839, -1018,   840, -1018, -1018,   843,   781,   844,
     845, -1018, -1018, -1018, -1018, -1018,   301,   301,   301,   301,
     301,   301,   301, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018,   846,   847,   848,   -49,   849,   850,   851,   852,   853,
     854,   855,   856,   857,    39,   858,   859, -1018,   860,   861,
     862,   863,   864,   865,   866,    -3,   867,   868,   869,   870,
     871,   872,   873,   874, -1018,   875,   876, -1018, -1018,   877,
     878, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018,   879,   880,   501,   881,   882,   883,   884,   885,
   -1018,   886,   887, -1018,   888,   889,   313,   904,   685, -1018,
   -1018, -1018,   891,   892, -1018,   893,   894,   533,   895,   896,
     897,   898,   899,   900,   901, -1018,   902,   903,   905, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018,   906,   596, -1018, -1018,
     907,   797,   835, -1018,    14, -1018, -1018, -1018, -1018,   908,
     909,   910,   911, -1018, -1018,   912,   610,   913, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018,  -193, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018,   674,   674,   674, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,  -191, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018,  -184, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,  -183,
   -1018,   915,   780,   916, -1018, -1018, -1018, -1018, -1018, -1018,
     841, -1018,   914,   917, -1018,   918, -1018,   919,   920, -1018,
   -1018,   921, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018,  -162, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018,  -157, -1018, -1018,   927,
    -173,   924,   928, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,  -136,
   -1018, -1018, -1018,   -49, -1018, -1018, -1018, -1018,    -3, -1018,
     501, -1018,   313, -1018, -1018, -1018,   929,   560,   990,   925,
     787,  1001,  1004, -1018,   533, -1018,   596,   930,   931,   932,
     407, -1018, -1018,   610, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   933, -1018,
   -1018
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
       0,    93,    94,    96,    95,   568,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   550,   565,   566,   567,   564,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   551,   552,
     562,   563,     0,     0,     0,   433,     0,     0,   431,   432,
       0,   497,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   446,   447,   448,   489,   454,   490,   484,
     485,   486,   487,   458,   449,   450,   451,   452,   453,   455,
     456,   457,   459,   460,   488,   464,   465,   466,   467,   463,
     462,   468,   474,   475,   469,   470,   471,   461,   472,   482,
     483,   480,   481,   473,   478,   479,   476,   477,   491,   492,
     493,   494,   495,   496,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   588,   589,   590,   591,   592,   593,
     594,   596,   595,   597,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    69,    67,    65,    70,    71,    72,
      66,    56,    68,    58,    59,    60,    61,    62,    63,    64,
      57,     0,     0,     0,     0,   125,   126,   127,     0,     0,
     322,     0,     0,   320,   321,     0,    97,     0,     0,     0,
       0,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     549,     0,     0,     0,     0,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   211,   212,
     215,   217,   218,   219,   220,   221,   222,   223,   213,   214,
     216,   224,   225,   226,     0,     0,     0,     0,     0,     0,
       0,   400,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   373,   374,   375,   376,   377,   378,   379,   380,   382,
     381,   384,   388,   385,   386,   387,   383,   426,     0,     0,
       0,   423,   424,   425,     0,     0,   430,   441,     0,     0,
       0,   438,   439,   440,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   445,     0,     0,     0,   291,
       0,     0,     0,     0,     0,     0,   277,   278,   279,   280,
     285,   281,   282,   283,   284,   417,     0,     0,     0,   414,
     415,   416,     0,     0,     0,   250,     0,   262,     0,   260,
     261,   263,   264,    52,    51,    48,    50,    46,    45,     0,
       0,     0,     0,   104,   105,   106,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,   154,   155,
     156,   157,   158,   161,   162,   163,   160,   159,   164,     0,
       0,     0,     0,     0,   310,   311,   312,   313,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   587,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,   356,     0,   351,   352,   353,   128,     0,     0,   124,
       0,     0,     0,     0,     0,     0,     0,   113,   114,   116,
     115,   117,     0,     0,   319,     0,     0,   334,     0,     0,
     327,   328,   329,   330,     0,     0,     0,    91,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   548,   227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   210,   389,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   372,     0,     0,     0,   422,     0,   429,     0,
       0,     0,   437,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   444,   286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   276,     0,     0,     0,   413,   265,
       0,     0,     0,     0,     0,   259,     0,   107,     0,     0,
       0,   103,   165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   314,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,   354,
       0,     0,     0,   350,     0,   123,     0,   118,     0,     0,
       0,     0,     0,   112,     0,   318,   331,     0,     0,     0,
       0,   326,   100,    99,    98,   584,    29,    29,    29,    29,
      29,    29,    29,    31,    30,   585,   572,   571,   569,   570,
     573,   574,   575,   576,   577,   578,   579,   582,   583,   580,
     581,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     0,   209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   371,     0,     0,   421,   434,     0,
       0,   436,   509,   513,   498,   499,   526,   542,   543,   544,
     545,   546,   547,   502,   540,   541,   534,   503,   504,   508,
     516,   507,   505,   506,   512,   500,   511,   510,   532,   538,
     539,   530,   537,   527,   525,   528,   533,   529,   531,   518,
     524,   523,   519,   520,   521,   522,   535,   536,   515,   514,
     517,   501,     0,     0,     0,     0,     0,     0,     0,     0,
     275,     0,     0,   412,     0,     0,     0,   270,   266,   269,
     249,    49,     0,     0,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,     0,     0,   308,
     602,   599,   600,   601,   606,   605,   607,   603,   604,    86,
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
   -1018, -1018, -1018,  -533,  -321, -1017,  -661, -1018, -1018, -1018,
   -1018,   254, -1018, -1018,   541, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018,   945, -1018, -1018, -1018, -1018, -1018,
   -1018,   405, -1018, -1018, -1018, -1018, -1018,   423, -1018, -1018,
   -1018, -1018, -1018, -1018,   842, -1018, -1018, -1018, -1018,    31,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   409, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018,  -197, -1018, -1018, -1018,   693, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018,   -59, -1018, -1018, -1018, -1018, -1018,   -66,
   -1018,   661, -1018, -1018, -1018,    29, -1018, -1018, -1018, -1018,
   -1018,   677, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   -57,
   -1018, -1018, -1018, -1018, -1018, -1018,   612, -1018, -1018, -1018,
   -1018, -1018,   890, -1018, -1018, -1018, -1018,   547, -1018, -1018,
   -1018, -1018, -1018,   -79, -1018, -1018, -1018,   576, -1018, -1018,
   -1018, -1018,   -69, -1018, -1018, -1018,   830, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   -48,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,   673, -1018,
   -1018, -1018, -1018, -1018,   764, -1018, -1018, -1018, -1018,  1045,
   -1018, -1018, -1018, -1018,   765, -1018, -1018, -1018, -1018,   991,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018,  1072, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018,   923, -1018, -1018, -1018, -1018, -1018, -1018, -1018,
   -1018, -1018
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   853,   854,  1075,  1076,    28,    29,   238,
     515,   516,    30,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,    31,    80,    81,    82,    83,    84,    32,    66,
     522,   523,   524,   525,    33,    73,   606,   607,   608,   609,
     610,   611,    34,   304,   305,   306,   307,   308,  1034,  1035,
    1036,  1037,  1038,  1191,  1268,    35,    67,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   775,
    1163,  1164,    36,    55,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   651,  1061,  1062,    37,    63,   507,   762,  1129,  1130,
     508,   509,   510,  1133,   978,   979,   511,   512,    38,    61,
     485,   486,   487,   488,   489,   490,   491,   747,  1113,  1114,
     492,   493,   494,    39,    68,   553,   554,   555,   556,   557,
      40,   312,   313,   314,    41,    75,   619,   620,   621,   622,
     623,   838,  1209,  1210,    42,    71,   592,   593,   594,   595,
     821,  1186,  1187,    43,    56,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   672,  1088,  1089,
     402,   403,   404,   405,   406,    44,    62,   498,   499,   500,
     501,    45,    57,   410,   411,   412,   413,    46,   127,   128,
     129,    47,    59,   420,   421,   422,   423,    48,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      49,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      50,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     885,   886,   630,   407,    76,  1086,   310,   601,   636,   637,
     638,   495,   640,   641,  1059,  1030,   615,   519,   502,   513,
     417,   519,  1238,    76,    53,   407,   846,   847,   848,   849,
     850,   851,   852,    54,  1212,   125,  1217,   495,  1213,   310,
    1218,   589,    77,  1219,  1221,   125,    58,  1220,  1222,    78,
    1072,  1073,  1074,   884,   589,  1214,  1215,  1216,   131,   302,
     417,    77,    60,   132,   133,  1233,   134,   135,    78,  1234,
    1235,   136,   549,   549,  1236,    51,    52,   408,   137,   138,
     139,   140,   141,   142,   503,   889,   890,  1060,   143,   144,
     145,  1242,   504,   615,   505,  1243,   302,    64,   146,   408,
      65,   147,   148,   237,   694,   629,   696,   697,   520,   126,
     149,   239,   520,    69,    70,    72,   706,   243,    79,   126,
     311,   602,   712,   550,   550,    74,   122,   150,   718,  1031,
     616,   123,   514,   124,   418,   725,   726,    79,   151,   409,
     600,   152,   153,   130,   234,   235,   236,   496,   738,   739,
     740,   154,   506,   311,   240,   590,   419,   155,   156,   244,
     157,   409,   158,   551,   551,    85,   159,   160,   590,   241,
     245,   246,   247,   496,   418,   248,   249,   603,   161,   264,
     250,   251,   252,   162,  1030,   163,   164,   165,   604,  1087,
     166,   521,   242,   301,   309,   521,   419,   605,    86,    87,
     476,   315,   316,   317,  1032,   318,    88,   616,   552,   552,
     319,    89,    90,    91,   265,   167,   168,   266,   477,   169,
     170,   171,   172,   173,   174,   175,   526,   497,  1033,   617,
     685,   320,   618,  -130,   832,    92,    93,    94,    95,   793,
     601,   322,  1192,   840,   527,   764,   267,   691,   770,   478,
      96,    97,    98,   497,   591,   323,   268,   176,   177,    99,
     100,   101,   415,   102,   757,   884,   613,   591,   178,   179,
    -130,   341,   324,   517,   303,   528,   479,   180,   325,   181,
     269,   822,   518,   326,   270,   474,   598,   342,   343,   502,
     327,   328,   271,   272,   526,   329,   273,   274,  1031,   344,
     789,   569,   529,   374,   330,   375,   617,   376,   331,   618,
     332,   303,   527,  1049,  1050,  1051,  1052,  1053,  1054,  1055,
     333,   377,   334,   335,   275,   336,   337,   338,   414,   873,
     480,   424,   876,  1124,   878,   425,   426,   481,   482,   883,
     530,   427,   428,   528,   567,   596,   429,   345,   430,   431,
    1125,   432,   378,   433,   602,   503,   531,   901,   476,   483,
     434,   435,   436,   504,   437,   505,   438,   346,   347,   379,
     529,   380,  1126,  1032,   348,   439,   477,   440,   349,   381,
     441,   276,   442,   277,   278,   350,   279,   280,   281,   443,
     444,   382,   339,   351,   352,   353,   445,  1033,   446,   447,
     448,   449,   450,   451,   354,   452,   587,   478,   530,   453,
     603,   454,   624,   455,   456,   457,   484,   383,   532,   458,
     459,   604,   460,   506,   531,   355,   461,   753,   625,   533,
     605,   462,   534,   463,   479,   464,   465,   384,   466,   131,
     467,   468,   535,   469,   132,   133,   536,   134,   135,   470,
     471,   472,   136,   783,   356,   473,   385,   558,   559,   137,
     138,   139,   140,   141,   142,   560,   561,   562,   626,   143,
     144,   145,   386,   563,   564,   565,   566,   264,   570,   146,
     571,   572,   147,   148,   573,   574,   532,  1260,   480,  1261,
     575,   149,   576,   577,   578,   481,   482,   533,   663,  1127,
     534,   579,   580,   581,   387,  1128,   388,   389,   150,   582,
     535,   583,   265,   584,   536,   266,  1104,   483,   585,   151,
     586,   597,   152,   153,   612,   627,   628,   629,   631,  1239,
     681,   632,   154,   633,  1262,   634,   635,  1138,   155,   156,
     639,   157,   642,   158,   267,   643,   644,   159,   160,   645,
     648,  1263,  1105,   646,   268,   647,   649,   665,   688,   161,
    1139,  1140,   650,   687,   162,   693,   163,   164,   165,   652,
     653,   166,   654,  1141,   484,   655,   656,   657,   269,   658,
    1264,  1265,   270,   659,  1106,   660,   702,   661,   662,   666,
     271,   272,   667,   668,   273,   274,   167,   168,   669,   670,
     169,   170,   171,   172,   173,   174,   175,   671,   673,   674,
     675,   676,  1142,  1143,   677,  1144,   678,  1107,  1108,   341,
     679,   680,   275,  1109,  1266,   374,   683,   375,   684,   376,
    1267,   689,   690,   698,   695,   342,   343,   699,   176,   177,
    1145,   700,   701,   377,  1146,   703,  1110,   344,   704,   178,
     179,   705,   707,  1147,   708,   709,   710,   711,   180,   713,
     181,   714,   715,   716,   722,   717,   719,   720,   721,   723,
     724,   727,   728,  1148,   378,  1149,   729,  1150,  1176,   276,
     730,   277,   278,   731,   279,   280,   281,   732,   733,   734,
     735,   379,  1199,   380,  1151,   345,   736,   741,   745,  1111,
     737,   381,   743,   742,  1249,   744,   801,  1152,   746,  1153,
     759,   748,  1154,   382,  1155,   346,   347,   766,  1156,     2,
       3,  1157,   348,     4,   749,  1112,   349,  1158,   750,  1159,
    1160,   751,   752,   350,   755,     5,   756,   760,     6,   383,
    1177,   351,   352,   353,   761,   763,   767,     7,  1161,   768,
     769,   772,   354,   791,  1200,   773,  1162,     8,   774,   384,
     776,   777,   792,   778,   779,  1178,   780,   781,   782,   785,
    1179,     9,   786,   355,   787,  1180,    10,    11,   385,  1201,
     788,   794,   795,   796,  1202,   243,   797,   798,   799,  1203,
    1181,   800,  1182,  1183,   386,    12,   802,   803,   804,    13,
     805,   806,   356,   807,  1204,   808,  1205,  1206,   818,    14,
      15,  1184,   819,   820,   824,   809,   810,   811,   812,  1185,
     813,   825,   814,   588,    85,  1207,   387,   244,   388,   389,
     815,    16,    17,  1208,   816,   826,   817,   828,   245,   246,
     247,   827,   829,   248,   249,   830,    18,   835,   250,   251,
     252,   831,   834,   836,   837,   842,   843,    86,    87,   839,
     844,   845,   855,    19,   856,    88,   857,   858,   859,   860,
      89,    90,    91,   861,   862,    20,    21,   863,   864,   865,
     866,   867,   868,   869,   870,   871,   872,   874,   875,   877,
     879,    22,   880,   881,    92,    93,    94,    95,   882,    23,
     884,   892,    24,   887,   888,   891,    25,   893,    26,    96,
      97,    98,   894,   895,   896,   897,  1132,   898,    99,   100,
     101,   899,   102,   900,   902,   903,   964,   771,   904,   905,
     906,  1252,   976,   907,   908,   909,   910,   987,  1027,   911,
     912,   913,   914,   915,   916,   917,   784,   918,   919,   920,
     921,   922,   923,   924,   925,   926,   927,   928,   929,   930,
     931,   932,   933,   934,   935,   936,   937,   938,   939,   940,
     941,   942,   943,   944,   945,   946,   947,   948,   949,   950,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   965,   970,   966,   967,   968,   969,   971,
     972,   986,   974,   973,   975,   980,   977,   982,   983,   992,
    1046,   985,   984,   988,   989,   990,   991,   993,  1251,   994,
     981,   996,   995,   997,   998,   321,  1189,   999,  1000,   833,
    1001,  1002,  1003,  1004,  1005,  1006,  1007,  1255,  1008,  1009,
    1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
     664,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1028,  1039,
    1029,  1040,  1041,  1042,  1190,  1193,  1043,  1044,  1045,  1047,
    1248,  1226,  1048,  1056,  1057,  1058,  1063,  1064,  1065,  1066,
    1067,  1068,  1069,  1070,  1071,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1115,  1116,
    1117,  1118,  1119,  1120,  1121,  1122,  1123,  1131,  1134,  1135,
    1136,  1137,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1250,  1174,  1175,  1188,  1194,  1195,  1196,  1197,  1198,
    1211,  1223,  1253,  1225,  1227,  1254,   599,  1228,  1229,  1230,
    1231,  1232,  1237,  1240,  1244,  1241,  1247,  1257,  1258,  1259,
    1270,  1224,   754,  1246,  1269,   790,   841,  1256,   823,   765,
    1245,   758,   416,   475,   686,   340,   568,     0,     0,     0,
       0,     0,     0,     0,     0,   692,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   614,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     682
};

static const yytype_int16 yycheck[] =
{
     661,   662,   323,     1,     1,     8,     1,     1,   329,   330,
     331,     1,   333,   334,    63,     1,     1,     1,     1,    30,
       1,     1,   195,     1,   232,     1,   147,   148,   149,   150,
     151,   152,   153,   232,   227,     1,   227,     1,   231,     1,
     231,     1,    39,   227,   227,     1,   232,   231,   231,    46,
      11,    12,    13,   226,     1,  1072,  1073,  1074,     1,     1,
       1,    39,   232,     6,     7,   227,     9,    10,    46,   231,
     227,    14,     1,     1,   231,   227,   228,    75,    21,    22,
      23,    24,    25,    26,    67,   177,   178,   136,    31,    32,
      33,   227,    75,     1,    77,   231,     1,   225,    41,    75,
     229,    44,    45,   230,   425,   226,   427,   428,    92,    75,
      53,   225,    92,   232,   232,   232,   437,     1,   115,    75,
     115,   115,   443,    52,    52,   232,   232,    70,   449,   115,
     115,   232,   143,   232,   115,   456,   457,   115,    81,   137,
     175,    84,    85,   232,   232,   232,   232,   137,   469,   470,
     471,    94,   135,   115,   232,   115,   137,   100,   101,    43,
     103,   137,   105,    92,    92,     1,   109,   110,   115,   232,
      54,    55,    56,   137,   115,    59,    60,   171,   121,     1,
      64,    65,    66,   126,     1,   128,   129,   130,   182,   192,
     133,   175,   232,   232,   232,   175,   137,   191,    34,    35,
       1,   232,   227,   229,   190,   229,    42,   115,   137,   137,
     229,    47,    48,    49,    36,   158,   159,    39,    19,   162,
     163,   164,   165,   166,   167,   168,     1,   217,   214,   214,
     228,   228,   217,   175,   228,    71,    72,    73,    74,   560,
       1,   229,   228,   228,    19,   228,    68,   228,   228,    50,
      86,    87,    88,   217,   214,   229,    78,   200,   201,    95,
      96,    97,   228,    99,   228,   226,   228,   214,   211,   212,
     175,     1,   229,   227,   216,    50,    77,   220,   229,   222,
     102,   228,   227,   229,   106,   228,   228,    17,    18,     1,
     229,   229,   114,   115,     1,   229,   118,   119,   115,    29,
     228,   227,    77,     1,   229,     3,   214,     5,   229,   217,
     229,   216,    19,   846,   847,   848,   849,   850,   851,   852,
     229,    19,   229,   229,   146,   229,   229,   229,   229,   650,
     131,   229,   653,    20,   655,   229,   229,   138,   139,   660,
     115,   229,   229,    50,   228,   227,   229,    77,   229,   229,
      37,   229,    50,   229,   115,    67,   131,   678,     1,   160,
     229,   229,   229,    75,   229,    77,   229,    97,    98,    67,
      77,    69,    59,   190,   104,   229,    19,   229,   108,    77,
     229,   203,   229,   205,   206,   115,   208,   209,   210,   229,
     229,    89,   228,   123,   124,   125,   229,   214,   229,   229,
     229,   229,   229,   229,   134,   229,   228,    50,   115,   229,
     171,   229,   225,   229,   229,   229,   217,   115,   193,   229,
     229,   182,   229,   135,   131,   155,   229,   228,   225,   204,
     191,   229,   207,   229,    77,   229,   229,   135,   229,     1,
     229,   229,   217,   229,     6,     7,   221,     9,    10,   229,
     229,   229,    14,   228,   184,   229,   154,   229,   229,    21,
      22,    23,    24,    25,    26,   229,   229,   229,   225,    31,
      32,    33,   170,   229,   229,   229,   229,     1,   229,    41,
     229,   229,    44,    45,   229,   229,   193,    80,   131,    82,
     229,    53,   229,   229,   229,   138,   139,   204,   228,   186,
     207,   229,   229,   229,   202,   192,   204,   205,    70,   229,
     217,   229,    36,   229,   221,    39,    15,   160,   229,    81,
     229,   229,    84,    85,   229,   227,   226,   226,   199,  1190,
     228,   199,    94,   199,   127,   199,   226,     4,   100,   101,
     226,   103,   226,   105,    68,   226,   226,   109,   110,   226,
     229,   144,    51,   227,    78,   227,   229,   227,   227,   121,
      27,    28,   229,   225,   126,   199,   128,   129,   130,   229,
     229,   133,   229,    40,   217,   229,   229,   229,   102,   229,
     173,   174,   106,   229,    83,   229,   225,   229,   229,   229,
     114,   115,   229,   229,   118,   119,   158,   159,   229,   229,
     162,   163,   164,   165,   166,   167,   168,   229,   229,   229,
     229,   229,    79,    80,   229,    82,   229,   116,   117,     1,
     229,   229,   146,   122,   217,     1,   229,     3,   229,     5,
     223,   229,   229,   199,   226,    17,    18,   226,   200,   201,
     107,   226,   226,    19,   111,   225,   145,    29,   199,   211,
     212,   226,   199,   120,   226,   226,   199,   199,   220,   226,
     222,   226,   226,   226,   199,   226,   226,   226,   226,   225,
     199,   199,   199,   140,    50,   142,   226,   144,    82,   203,
     199,   205,   206,   199,   208,   209,   210,   199,   199,   199,
     199,    67,    82,    69,   161,    77,   199,   199,   229,   198,
     226,    77,   227,   226,   144,   227,   226,   174,   229,   176,
     227,   229,   179,    89,   181,    97,    98,   231,   185,     0,
       1,   188,   104,     4,   229,   224,   108,   194,   229,   196,
     197,   229,   229,   115,   229,    16,   229,   229,    19,   115,
     144,   123,   124,   125,   229,   229,   227,    28,   215,   229,
     229,   227,   134,   199,   144,   229,   223,    38,   229,   135,
     229,   229,   199,   229,   229,   169,   229,   229,   229,   227,
     174,    52,   229,   155,   229,   179,    57,    58,   154,   169,
     229,   225,   199,   225,   174,     1,   199,   199,   199,   179,
     194,   227,   196,   197,   170,    76,   225,   199,   225,    80,
     226,   226,   184,   225,   194,   225,   196,   197,   227,    90,
      91,   215,   227,   229,   199,   225,   225,   225,   225,   223,
     225,   227,   225,   282,     1,   215,   202,    43,   204,   205,
     225,   112,   113,   223,   225,   232,   225,   229,    54,    55,
      56,   227,   229,    59,    60,   229,   127,   227,    64,    65,
      66,   229,   225,   227,   229,   227,   227,    34,    35,   229,
     227,   227,   227,   144,   227,    42,   227,   227,   227,   227,
      47,    48,    49,   227,   227,   156,   157,   227,   227,   227,
     227,   227,   227,   227,   227,   226,   226,   229,   226,   226,
     225,   172,   226,   226,    71,    72,    73,    74,   226,   180,
     226,   199,   183,   227,   225,   225,   187,   225,   189,    86,
      87,    88,   225,   229,   225,   225,   231,   226,    95,    96,
      97,   225,    99,   225,   225,   225,   229,   522,   227,   225,
     225,   144,   229,   227,   227,   225,   225,   229,   229,   227,
     227,   227,   227,   227,   227,   227,   537,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   225,   199,   225,   227,   226,   225,   225,   225,   225,
     225,   199,   225,   227,   225,   227,   226,   225,   225,   199,
     229,   225,   227,   225,   225,   225,   225,   225,    93,   225,
     766,   225,   227,   225,   225,    80,   229,   227,   227,   606,
     227,   227,   227,   227,   227,   227,   227,  1234,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     357,   227,   227,   227,   227,   227,   227,   225,   227,   225,
     227,   225,   225,   225,   229,  1034,   227,   227,   225,   225,
     141,   230,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   213,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   141,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   226,   141,   227,   230,   141,   304,   230,   230,   230,
     230,   230,   225,   229,  1213,   227,  1222,   227,   227,   227,
     227,  1132,   485,  1220,  1243,   553,   619,  1236,   592,   508,
    1218,   498,   127,   182,   410,   103,   253,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     390
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   234,     0,     1,     4,    16,    19,    28,    38,    52,
      57,    58,    76,    80,    90,    91,   112,   113,   127,   144,
     156,   157,   172,   180,   183,   187,   189,   235,   240,   241,
     245,   265,   271,   277,   285,   298,   315,   337,   351,   366,
     373,   377,   387,   396,   418,   424,   430,   434,   440,   493,
     513,   227,   228,   232,   232,   316,   397,   425,   232,   435,
     232,   352,   419,   338,   225,   229,   272,   299,   367,   232,
     232,   388,   232,   278,   232,   378,     1,    39,    46,   115,
     266,   267,   268,   269,   270,     1,    34,    35,    42,    47,
      48,    49,    71,    72,    73,    74,    86,    87,    88,    95,
      96,    97,    99,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   232,   232,   232,     1,    75,   431,   432,   433,
     232,     1,     6,     7,     9,    10,    14,    21,    22,    23,
      24,    25,    26,    31,    32,    33,    41,    44,    45,    53,
      70,    81,    84,    85,    94,   100,   101,   103,   105,   109,
     110,   121,   126,   128,   129,   130,   133,   158,   159,   162,
     163,   164,   165,   166,   167,   168,   200,   201,   211,   212,
     220,   222,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   232,   232,   232,   230,   242,   225,
     232,   232,   232,     1,    43,    54,    55,    56,    59,    60,
      64,    65,    66,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,     1,    36,    39,    68,    78,   102,
     106,   114,   115,   118,   119,   146,   203,   205,   206,   208,
     209,   210,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   232,     1,   216,   286,   287,   288,   289,   290,   232,
       1,   115,   374,   375,   376,   232,   227,   229,   229,   229,
     228,   267,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   228,
     495,     1,    17,    18,    29,    77,    97,    98,   104,   108,
     115,   123,   124,   125,   134,   155,   184,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,     1,     3,     5,    19,    50,    67,
      69,    77,    89,   115,   135,   154,   170,   202,   204,   205,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   413,   414,   415,   416,   417,     1,    75,   137,
     426,   427,   428,   429,   229,   228,   432,     1,   115,   137,
     436,   437,   438,   439,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   228,   442,     1,    19,    50,    77,
     131,   138,   139,   160,   217,   353,   354,   355,   356,   357,
     358,   359,   363,   364,   365,     1,   137,   217,   420,   421,
     422,   423,     1,    67,    75,    77,   135,   339,   343,   344,
     345,   349,   350,    30,   143,   243,   244,   227,   227,     1,
      92,   175,   273,   274,   275,   276,     1,    19,    50,    77,
     115,   131,   193,   204,   207,   217,   221,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,     1,
      52,    92,   137,   368,   369,   370,   371,   372,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   228,   515,   227,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   228,   247,     1,
     115,   214,   389,   390,   391,   392,   227,   229,   228,   287,
     175,     1,   115,   171,   182,   191,   279,   280,   281,   282,
     283,   284,   229,   228,   375,     1,   115,   214,   217,   379,
     380,   381,   382,   383,   225,   225,   225,   227,   226,   226,
     237,   199,   199,   199,   199,   226,   237,   237,   237,   226,
     237,   237,   226,   226,   226,   226,   227,   227,   229,   229,
     229,   334,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   228,   318,   227,   229,   229,   229,   229,
     229,   229,   410,   229,   229,   229,   229,   229,   229,   229,
     229,   228,   399,   229,   229,   228,   427,   225,   227,   229,
     229,   228,   437,   199,   237,   226,   237,   237,   199,   226,
     226,   226,   225,   225,   199,   226,   237,   199,   226,   226,
     199,   199,   237,   226,   226,   226,   226,   226,   237,   226,
     226,   226,   199,   225,   199,   237,   237,   199,   199,   226,
     199,   199,   199,   199,   199,   199,   199,   226,   237,   237,
     237,   199,   226,   227,   227,   229,   229,   360,   229,   229,
     229,   229,   229,   228,   354,   229,   229,   228,   421,   227,
     229,   229,   340,   229,   228,   344,   231,   227,   229,   229,
     228,   274,   227,   229,   229,   312,   229,   229,   229,   229,
     229,   229,   229,   228,   301,   227,   229,   229,   229,   228,
     369,   199,   199,   237,   225,   199,   225,   199,   199,   199,
     227,   226,   225,   199,   225,   226,   226,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   227,   227,
     229,   393,   228,   390,   199,   227,   232,   227,   229,   229,
     229,   229,   228,   280,   225,   227,   227,   229,   384,   229,
     228,   380,   227,   227,   227,   227,   147,   148,   149,   150,
     151,   152,   153,   236,   237,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   226,   226,   237,   229,   226,   237,   226,   237,   225,
     226,   226,   226,   237,   226,   239,   239,   227,   225,   177,
     178,   225,   199,   225,   225,   229,   225,   225,   226,   225,
     225,   237,   225,   225,   227,   225,   225,   227,   227,   225,
     225,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   225,   199,   229,   225,   226,   225,   225,   225,
     227,   225,   225,   227,   225,   225,   229,   226,   347,   348,
     227,   244,   225,   225,   227,   225,   199,   229,   225,   225,
     225,   225,   199,   225,   225,   227,   225,   225,   225,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   225,   229,   227,   227,
       1,   115,   190,   214,   291,   292,   293,   294,   295,   225,
     225,   225,   225,   227,   227,   225,   229,   225,   227,   236,
     236,   236,   236,   236,   236,   236,   227,   227,   227,    63,
     136,   335,   336,   227,   227,   227,   227,   227,   227,   227,
     227,   227,    11,    12,    13,   238,   239,   227,   227,   227,
     227,   227,   227,   227,   227,   227,     8,   192,   411,   412,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,    15,    51,    83,   116,   117,   122,
     145,   198,   224,   361,   362,   227,   227,   227,   227,   227,
     227,   227,   227,   227,    20,    37,    59,   186,   192,   341,
     342,   213,   231,   346,   227,   227,   227,   227,     4,    27,
      28,    40,    79,    80,    82,   107,   111,   120,   140,   142,
     144,   161,   174,   176,   179,   181,   185,   188,   194,   196,
     197,   215,   223,   313,   314,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,    82,   144,   169,   174,
     179,   194,   196,   197,   215,   223,   394,   395,   227,   229,
     229,   296,   228,   292,   227,   227,   227,   227,   227,    82,
     144,   169,   174,   179,   194,   196,   197,   215,   223,   385,
     386,   227,   227,   231,   238,   238,   238,   227,   231,   227,
     231,   227,   231,   226,   348,   227,   230,   230,   230,   230,
     230,   230,   230,   227,   231,   227,   231,   225,   195,   239,
     229,   227,   227,   231,   336,   412,   362,   342,   141,   144,
     141,    93,   144,   141,   141,   314,   395,   227,   227,   227,
      80,    82,   127,   144,   173,   174,   217,   223,   297,   386,
     227
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   233,   234,   234,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   236,
     236,   237,   237,   237,   237,   237,   237,   237,   237,   238,
     238,   239,   239,   239,   239,   240,   241,   242,   242,   243,
     243,   244,   244,   245,   246,   246,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   266,   267,   267,   267,   267,   268,   269,
     270,   272,   271,   273,   273,   274,   274,   274,   275,   276,
     278,   277,   279,   279,   280,   280,   280,   280,   280,   281,
     282,   283,   284,   285,   286,   286,   287,   287,   287,   288,
     290,   289,   291,   291,   292,   292,   292,   292,   293,   294,
     294,   296,   295,   297,   297,   297,   297,   297,   297,   297,
     297,   299,   298,   300,   300,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   312,   311,   313,   313,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   316,   315,
     317,   317,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   334,   333,   335,   335,   336,   336,   338,   337,
     340,   339,   341,   341,   342,   342,   342,   342,   342,   343,
     343,   344,   344,   344,   344,   344,   346,   345,   347,   347,
     348,   348,   349,   350,   352,   351,   353,   353,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   355,   356,   357,
     358,   360,   359,   361,   361,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   363,   364,   365,   367,   366,   368,
     368,   369,   369,   369,   369,   370,   371,   372,   373,   374,
     374,   375,   375,   376,   378,   377,   379,   379,   380,   380,
     380,   380,   381,   382,   384,   383,   385,   385,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   388,   387,
     389,   389,   390,   390,   390,   391,   393,   392,   394,   394,
     395,   395,   395,   395,   395,   395,   395,   395,   395,   395,
     397,   396,   398,   398,   399,   399,   399,   399,   399,   399,
     399,   399,   399,   399,   399,   399,   399,   399,   399,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   408,
     410,   409,   411,   411,   412,   412,   413,   414,   415,   416,
     417,   419,   418,   420,   420,   421,   421,   421,   422,   423,
     425,   424,   426,   426,   427,   427,   427,   428,   429,   430,
     431,   431,   432,   432,   433,   435,   434,   436,   436,   437,
     437,   437,   438,   439,   440,   441,   441,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     494,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   514,   515,
     515,   515,   515,   515,   515,   515,   515,   515,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4
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
#line 395 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3210 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 396 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3216 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 397 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3222 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 398 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3228 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3234 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3240 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3246 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 402 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3252 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 403 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3258 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 406 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3264 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 407 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3270 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 408 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3276 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 409 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3282 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 410 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3288 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 418 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3297 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 428 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3306 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 434 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3314 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 441 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3323 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 445 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3332 "conf_parser.c"
    break;

  case 74: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 478 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3344 "conf_parser.c"
    break;

  case 75: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 487 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = io_strdup(yylval.string);
  }
}
#line 3356 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 496 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = io_strdup(yylval.string);
  }
}
#line 3368 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 505 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = io_strdup(yylval.string);
  }
}
#line 3380 "conf_parser.c"
    break;

  case 78: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 514 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = io_strdup(yylval.string);
  }
}
#line 3392 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 523 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = io_strdup(yylval.string);
  }
}
#line 3404 "conf_parser.c"
    break;

  case 80: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 532 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = io_strdup(yylval.string);
  }
}
#line 3416 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 541 "conf_parser.y"
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
#line 3434 "conf_parser.c"
    break;

  case 82: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 556 "conf_parser.y"
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
#line 3452 "conf_parser.c"
    break;

  case 83: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 571 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3465 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 581 "conf_parser.y"
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
#line 3482 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 595 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3494 "conf_parser.c"
    break;

  case 86: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 604 "conf_parser.y"
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
#line 3520 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 627 "conf_parser.y"
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
#line 3546 "conf_parser.c"
    break;

  case 88: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 650 "conf_parser.y"
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
#line 3572 "conf_parser.c"
    break;

  case 89: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 673 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3584 "conf_parser.c"
    break;

  case 90: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 682 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3593 "conf_parser.c"
    break;

  case 98: /* admin_name: NAME '=' QSTRING ';'  */
#line 700 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3605 "conf_parser.c"
    break;

  case 99: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 709 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3617 "conf_parser.c"
    break;

  case 100: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 718 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3629 "conf_parser.c"
    break;

  case 101: /* $@1: %empty  */
#line 731 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3638 "conf_parser.c"
    break;

  case 102: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 735 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3655 "conf_parser.c"
    break;

  case 108: /* motd_mask: MASK '=' QSTRING ';'  */
#line 752 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3664 "conf_parser.c"
    break;

  case 109: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 758 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3673 "conf_parser.c"
    break;

  case 110: /* $@2: %empty  */
#line 768 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3682 "conf_parser.c"
    break;

  case 111: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 772 "conf_parser.y"
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
#line 3700 "conf_parser.c"
    break;

  case 119: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 790 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3709 "conf_parser.c"
    break;

  case 120: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 796 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3718 "conf_parser.c"
    break;

  case 121: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 802 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3727 "conf_parser.c"
    break;

  case 122: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 808 "conf_parser.y"
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
#line 3749 "conf_parser.c"
    break;

  case 129: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 837 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3758 "conf_parser.c"
    break;

  case 130: /* $@3: %empty  */
#line 843 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3767 "conf_parser.c"
    break;

  case 131: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 847 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3780 "conf_parser.c"
    break;

  case 138: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 863 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3791 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 871 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3799 "conf_parser.c"
    break;

  case 140: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 874 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3807 "conf_parser.c"
    break;

  case 141: /* $@4: %empty  */
#line 879 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3816 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: USER  */
#line 885 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3825 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: OPERATOR  */
#line 889 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3834 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: XLINE  */
#line 893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3843 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: RESV  */
#line 897 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3852 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: T_DLINE  */
#line 901 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3861 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KLINE  */
#line 905 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3870 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: KILL  */
#line 909 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3879 "conf_parser.c"
    break;

  case 150: /* logging_file_type_item: T_DEBUG  */
#line 913 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3888 "conf_parser.c"
    break;

  case 151: /* $@5: %empty  */
#line 923 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3900 "conf_parser.c"
    break;

  case 152: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 930 "conf_parser.y"
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

    if (block_state.modes.buf[0])
      conf->modes = io_strdup(block_state.modes.buf);

    conf->flags = block_state.flags.value;
    conf->port  = block_state.port.value;
    conf->htype = parse_netmask(conf->host, conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);
  }
}
#line 3962 "conf_parser.c"
    break;

  case 166: /* oper_name: NAME '=' QSTRING ';'  */
#line 1002 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3971 "conf_parser.c"
    break;

  case 167: /* oper_user: USER '=' QSTRING ';'  */
#line 1008 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3980 "conf_parser.c"
    break;

  case 168: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1014 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3989 "conf_parser.c"
    break;

  case 169: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1020 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3998 "conf_parser.c"
    break;

  case 170: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1026 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 4012 "conf_parser.c"
    break;

  case 171: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1037 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4021 "conf_parser.c"
    break;

  case 172: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1043 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 4035 "conf_parser.c"
    break;

  case 173: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4044 "conf_parser.c"
    break;

  case 174: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1060 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4053 "conf_parser.c"
    break;

  case 175: /* $@6: %empty  */
#line 1066 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4062 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: KILL ':' REMOTE  */
#line 1073 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4071 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: KILL  */
#line 1077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4080 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4089 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: CONNECT  */
#line 1085 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4098 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4107 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: SQUIT  */
#line 1093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4116 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: KLINE  */
#line 1097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4125 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: UNKLINE  */
#line 1101 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4134 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_DLINE  */
#line 1105 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4143 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: T_UNDLINE  */
#line 1109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4152 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: XLINE  */
#line 1113 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4161 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: T_UNXLINE  */
#line 1117 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4170 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: DIE  */
#line 1121 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4179 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: T_RESTART  */
#line 1125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4188 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1129 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4197 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: REHASH  */
#line 1133 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4206 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: ADMIN  */
#line 1137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4215 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_GLOBOPS  */
#line 1141 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4224 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: T_LOCOPS  */
#line 1145 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4233 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: REMOTEBAN  */
#line 1149 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4242 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: T_SET  */
#line 1153 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4251 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: MODULE  */
#line 1157 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4260 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: T_OPME  */
#line 1161 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4269 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: NICK ':' RESV  */
#line 1165 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4278 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: JOIN ':' RESV  */
#line 1169 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4287 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: RESV  */
#line 1173 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4296 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: T_UNRESV  */
#line 1177 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4305 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: CLOSE  */
#line 1181 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4314 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1185 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4323 "conf_parser.c"
    break;

  case 208: /* $@7: %empty  */
#line 1195 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4339 "conf_parser.c"
    break;

  case 209: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1206 "conf_parser.y"
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
#line 4387 "conf_parser.c"
    break;

  case 228: /* class_name: NAME '=' QSTRING ';'  */
#line 1269 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4396 "conf_parser.c"
    break;

  case 229: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1275 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4405 "conf_parser.c"
    break;

  case 230: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1281 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4414 "conf_parser.c"
    break;

  case 231: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1287 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4423 "conf_parser.c"
    break;

  case 232: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1293 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4432 "conf_parser.c"
    break;

  case 233: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1299 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4441 "conf_parser.c"
    break;

  case 234: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1305 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4450 "conf_parser.c"
    break;

  case 235: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1311 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4459 "conf_parser.c"
    break;

  case 236: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1317 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4469 "conf_parser.c"
    break;

  case 237: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1324 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4478 "conf_parser.c"
    break;

  case 238: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1330 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4487 "conf_parser.c"
    break;

  case 239: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1336 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4496 "conf_parser.c"
    break;

  case 240: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1342 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4508 "conf_parser.c"
    break;

  case 241: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1351 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4520 "conf_parser.c"
    break;

  case 242: /* $@8: %empty  */
#line 1360 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4529 "conf_parser.c"
    break;

  case 246: /* class_flags_item: RANDOM_IDLE  */
#line 1367 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4538 "conf_parser.c"
    break;

  case 247: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1371 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4547 "conf_parser.c"
    break;

  case 248: /* $@9: %empty  */
#line 1381 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4556 "conf_parser.c"
    break;

  case 250: /* $@10: %empty  */
#line 1387 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4564 "conf_parser.c"
    break;

  case 254: /* listen_flags_item: T_TLS  */
#line 1393 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4573 "conf_parser.c"
    break;

  case 255: /* listen_flags_item: HIDDEN  */
#line 1397 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4582 "conf_parser.c"
    break;

  case 256: /* listen_flags_item: T_SERVER  */
#line 1401 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4591 "conf_parser.c"
    break;

  case 257: /* listen_flags_item: CLIENT  */
#line 1405 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4600 "conf_parser.c"
    break;

  case 258: /* listen_flags_item: DEFER  */
#line 1409 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4609 "conf_parser.c"
    break;

  case 266: /* $@11: %empty  */
#line 1417 "conf_parser.y"
                                 { reset_block_state(); }
#line 4615 "conf_parser.c"
    break;

  case 270: /* port_item: NUMBER  */
#line 1422 "conf_parser.y"
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
#line 4633 "conf_parser.c"
    break;

  case 271: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1435 "conf_parser.y"
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
#line 4653 "conf_parser.c"
    break;

  case 272: /* listen_address: IP '=' QSTRING ';'  */
#line 1452 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4662 "conf_parser.c"
    break;

  case 273: /* listen_host: HOST '=' QSTRING ';'  */
#line 1458 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4671 "conf_parser.c"
    break;

  case 274: /* $@12: %empty  */
#line 1468 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4680 "conf_parser.c"
    break;

  case 275: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1472 "conf_parser.y"
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
#line 4727 "conf_parser.c"
    break;

  case 287: /* auth_user: USER '=' QSTRING ';'  */
#line 1527 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4736 "conf_parser.c"
    break;

  case 288: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1533 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4745 "conf_parser.c"
    break;

  case 289: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1539 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4754 "conf_parser.c"
    break;

  case 290: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1545 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4768 "conf_parser.c"
    break;

  case 291: /* $@13: %empty  */
#line 1556 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4777 "conf_parser.c"
    break;

  case 295: /* auth_flags_item: EXCEED_LIMIT  */
#line 1563 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4786 "conf_parser.c"
    break;

  case 296: /* auth_flags_item: KLINE_EXEMPT  */
#line 1567 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4795 "conf_parser.c"
    break;

  case 297: /* auth_flags_item: XLINE_EXEMPT  */
#line 1571 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4804 "conf_parser.c"
    break;

  case 298: /* auth_flags_item: NEED_IDENT  */
#line 1575 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4813 "conf_parser.c"
    break;

  case 299: /* auth_flags_item: CAN_FLOOD  */
#line 1579 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4822 "conf_parser.c"
    break;

  case 300: /* auth_flags_item: NO_TILDE  */
#line 1583 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4831 "conf_parser.c"
    break;

  case 301: /* auth_flags_item: RESV_EXEMPT  */
#line 1587 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4840 "conf_parser.c"
    break;

  case 302: /* auth_flags_item: T_WEBIRC  */
#line 1591 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4849 "conf_parser.c"
    break;

  case 303: /* auth_flags_item: NEED_PASSWORD  */
#line 1595 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4858 "conf_parser.c"
    break;

  case 304: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1601 "conf_parser.y"
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
#line 4875 "conf_parser.c"
    break;

  case 305: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1615 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4887 "conf_parser.c"
    break;

  case 306: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1624 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4899 "conf_parser.c"
    break;

  case 307: /* $@14: %empty  */
#line 1637 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4911 "conf_parser.c"
    break;

  case 308: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1644 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4922 "conf_parser.c"
    break;

  case 315: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1655 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4931 "conf_parser.c"
    break;

  case 316: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1661 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4940 "conf_parser.c"
    break;

  case 317: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1667 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4949 "conf_parser.c"
    break;

  case 323: /* service_name: NAME '=' QSTRING ';'  */
#line 1682 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 4964 "conf_parser.c"
    break;

  case 324: /* $@15: %empty  */
#line 1698 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4980 "conf_parser.c"
    break;

  case 325: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1709 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 4995 "conf_parser.c"
    break;

  case 332: /* shared_name: NAME '=' QSTRING ';'  */
#line 1724 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5004 "conf_parser.c"
    break;

  case 333: /* shared_user: USER '=' QSTRING ';'  */
#line 1730 "conf_parser.y"
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
#line 5026 "conf_parser.c"
    break;

  case 334: /* $@16: %empty  */
#line 1749 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5035 "conf_parser.c"
    break;

  case 338: /* shared_type_item: KLINE  */
#line 1756 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5044 "conf_parser.c"
    break;

  case 339: /* shared_type_item: UNKLINE  */
#line 1760 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5053 "conf_parser.c"
    break;

  case 340: /* shared_type_item: T_DLINE  */
#line 1764 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5062 "conf_parser.c"
    break;

  case 341: /* shared_type_item: T_UNDLINE  */
#line 1768 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5071 "conf_parser.c"
    break;

  case 342: /* shared_type_item: XLINE  */
#line 1772 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5080 "conf_parser.c"
    break;

  case 343: /* shared_type_item: T_UNXLINE  */
#line 1776 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5089 "conf_parser.c"
    break;

  case 344: /* shared_type_item: RESV  */
#line 1780 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5098 "conf_parser.c"
    break;

  case 345: /* shared_type_item: T_UNRESV  */
#line 1784 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5107 "conf_parser.c"
    break;

  case 346: /* shared_type_item: T_LOCOPS  */
#line 1788 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5116 "conf_parser.c"
    break;

  case 347: /* shared_type_item: T_ALL  */
#line 1792 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5125 "conf_parser.c"
    break;

  case 348: /* $@17: %empty  */
#line 1802 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5139 "conf_parser.c"
    break;

  case 349: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1811 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5152 "conf_parser.c"
    break;

  case 355: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1824 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5161 "conf_parser.c"
    break;

  case 356: /* $@18: %empty  */
#line 1830 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5170 "conf_parser.c"
    break;

  case 360: /* cluster_type_item: KLINE  */
#line 1837 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5179 "conf_parser.c"
    break;

  case 361: /* cluster_type_item: UNKLINE  */
#line 1841 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5188 "conf_parser.c"
    break;

  case 362: /* cluster_type_item: T_DLINE  */
#line 1845 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5197 "conf_parser.c"
    break;

  case 363: /* cluster_type_item: T_UNDLINE  */
#line 1849 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5206 "conf_parser.c"
    break;

  case 364: /* cluster_type_item: XLINE  */
#line 1853 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5215 "conf_parser.c"
    break;

  case 365: /* cluster_type_item: T_UNXLINE  */
#line 1857 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5224 "conf_parser.c"
    break;

  case 366: /* cluster_type_item: RESV  */
#line 1861 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5233 "conf_parser.c"
    break;

  case 367: /* cluster_type_item: T_UNRESV  */
#line 1865 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5242 "conf_parser.c"
    break;

  case 368: /* cluster_type_item: T_LOCOPS  */
#line 1869 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5251 "conf_parser.c"
    break;

  case 369: /* cluster_type_item: T_ALL  */
#line 1873 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5260 "conf_parser.c"
    break;

  case 370: /* $@19: %empty  */
#line 1883 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5275 "conf_parser.c"
    break;

  case 371: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1893 "conf_parser.y"
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
#line 5346 "conf_parser.c"
    break;

  case 390: /* connect_name: NAME '=' QSTRING ';'  */
#line 1979 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5355 "conf_parser.c"
    break;

  case 391: /* connect_host: HOST '=' QSTRING ';'  */
#line 1985 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5364 "conf_parser.c"
    break;

  case 392: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1991 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5373 "conf_parser.c"
    break;

  case 393: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1997 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5382 "conf_parser.c"
    break;

  case 394: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2003 "conf_parser.y"
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
#line 5398 "conf_parser.c"
    break;

  case 395: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2016 "conf_parser.y"
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
#line 5414 "conf_parser.c"
    break;

  case 396: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2029 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5423 "conf_parser.c"
    break;

  case 397: /* connect_port: PORT '=' NUMBER ';'  */
#line 2035 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5432 "conf_parser.c"
    break;

  case 398: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2041 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5441 "conf_parser.c"
    break;

  case 399: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5450 "conf_parser.c"
    break;

  case 400: /* $@20: %empty  */
#line 2051 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5458 "conf_parser.c"
    break;

  case 404: /* connect_flags_item: AUTOCONN  */
#line 2057 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5467 "conf_parser.c"
    break;

  case 405: /* connect_flags_item: T_TLS  */
#line 2061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5476 "conf_parser.c"
    break;

  case 406: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2067 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5490 "conf_parser.c"
    break;

  case 407: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2078 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5499 "conf_parser.c"
    break;

  case 408: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2084 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5508 "conf_parser.c"
    break;

  case 409: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2090 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5517 "conf_parser.c"
    break;

  case 410: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2096 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5531 "conf_parser.c"
    break;

  case 411: /* $@21: %empty  */
#line 2111 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5540 "conf_parser.c"
    break;

  case 412: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2115 "conf_parser.y"
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
#line 5563 "conf_parser.c"
    break;

  case 418: /* kill_user: USER '=' QSTRING ';'  */
#line 2138 "conf_parser.y"
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
#line 5586 "conf_parser.c"
    break;

  case 419: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2158 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5595 "conf_parser.c"
    break;

  case 420: /* $@22: %empty  */
#line 2168 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5604 "conf_parser.c"
    break;

  case 421: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2172 "conf_parser.y"
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
#line 5628 "conf_parser.c"
    break;

  case 427: /* deny_ip: IP '=' QSTRING ';'  */
#line 2196 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5637 "conf_parser.c"
    break;

  case 428: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2202 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5646 "conf_parser.c"
    break;

  case 434: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2217 "conf_parser.y"
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
#line 5663 "conf_parser.c"
    break;

  case 435: /* $@23: %empty  */
#line 2234 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5672 "conf_parser.c"
    break;

  case 436: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2238 "conf_parser.y"
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
#line 5692 "conf_parser.c"
    break;

  case 442: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2258 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5701 "conf_parser.c"
    break;

  case 443: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2264 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5710 "conf_parser.c"
    break;

  case 498: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2330 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5718 "conf_parser.c"
    break;

  case 499: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2335 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5726 "conf_parser.c"
    break;

  case 500: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2340 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5734 "conf_parser.c"
    break;

  case 501: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2345 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5742 "conf_parser.c"
    break;

  case 502: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2350 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5750 "conf_parser.c"
    break;

  case 503: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2355 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5758 "conf_parser.c"
    break;

  case 504: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2360 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5766 "conf_parser.c"
    break;

  case 505: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2365 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5774 "conf_parser.c"
    break;

  case 506: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2370 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5782 "conf_parser.c"
    break;

  case 507: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2375 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5790 "conf_parser.c"
    break;

  case 508: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2380 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5798 "conf_parser.c"
    break;

  case 509: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2385 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5806 "conf_parser.c"
    break;

  case 510: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2390 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5814 "conf_parser.c"
    break;

  case 511: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2395 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5822 "conf_parser.c"
    break;

  case 512: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2400 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5830 "conf_parser.c"
    break;

  case 513: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2405 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5838 "conf_parser.c"
    break;

  case 514: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2410 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5846 "conf_parser.c"
    break;

  case 515: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2415 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5854 "conf_parser.c"
    break;

  case 516: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2420 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5862 "conf_parser.c"
    break;

  case 517: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2425 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5870 "conf_parser.c"
    break;

  case 518: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2430 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5878 "conf_parser.c"
    break;

  case 519: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2435 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5886 "conf_parser.c"
    break;

  case 520: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2440 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5894 "conf_parser.c"
    break;

  case 521: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2445 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5902 "conf_parser.c"
    break;

  case 522: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2450 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5910 "conf_parser.c"
    break;

  case 523: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2455 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 5918 "conf_parser.c"
    break;

  case 524: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2460 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 5926 "conf_parser.c"
    break;

  case 525: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2465 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5934 "conf_parser.c"
    break;

  case 526: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2470 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5942 "conf_parser.c"
    break;

  case 527: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2475 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5950 "conf_parser.c"
    break;

  case 528: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2480 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5958 "conf_parser.c"
    break;

  case 529: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2485 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 5966 "conf_parser.c"
    break;

  case 530: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2490 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5974 "conf_parser.c"
    break;

  case 531: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2495 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 5982 "conf_parser.c"
    break;

  case 532: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2500 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5990 "conf_parser.c"
    break;

  case 533: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2505 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5998 "conf_parser.c"
    break;

  case 534: /* general_disable_auth: DISABLE_AUTH '=' TBOOL ';'  */
#line 2510 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6006 "conf_parser.c"
    break;

  case 535: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2515 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6014 "conf_parser.c"
    break;

  case 536: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2520 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6022 "conf_parser.c"
    break;

  case 537: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2525 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6034 "conf_parser.c"
    break;

  case 538: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2534 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6042 "conf_parser.c"
    break;

  case 539: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2539 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6050 "conf_parser.c"
    break;

  case 540: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2544 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6058 "conf_parser.c"
    break;

  case 541: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2549 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6066 "conf_parser.c"
    break;

  case 542: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2554 "conf_parser.y"
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
#line 6086 "conf_parser.c"
    break;

  case 543: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2571 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6097 "conf_parser.c"
    break;

  case 544: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2579 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6108 "conf_parser.c"
    break;

  case 545: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2587 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6119 "conf_parser.c"
    break;

  case 546: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2595 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6132 "conf_parser.c"
    break;

  case 547: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2605 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6145 "conf_parser.c"
    break;

  case 569: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2640 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6153 "conf_parser.c"
    break;

  case 570: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2645 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6162 "conf_parser.c"
    break;

  case 571: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2651 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6171 "conf_parser.c"
    break;

  case 572: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2657 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6179 "conf_parser.c"
    break;

  case 573: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2662 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6187 "conf_parser.c"
    break;

  case 574: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2667 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6195 "conf_parser.c"
    break;

  case 575: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2672 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6203 "conf_parser.c"
    break;

  case 576: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2677 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6211 "conf_parser.c"
    break;

  case 577: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2682 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6219 "conf_parser.c"
    break;

  case 578: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2687 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6227 "conf_parser.c"
    break;

  case 579: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2692 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6235 "conf_parser.c"
    break;

  case 580: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2697 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6243 "conf_parser.c"
    break;

  case 581: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2702 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6251 "conf_parser.c"
    break;

  case 582: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2707 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6259 "conf_parser.c"
    break;

  case 583: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2712 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6267 "conf_parser.c"
    break;

  case 584: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2717 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6275 "conf_parser.c"
    break;

  case 585: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2722 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6283 "conf_parser.c"
    break;

  case 599: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2745 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6292 "conf_parser.c"
    break;

  case 600: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2751 "conf_parser.y"
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
#line 6311 "conf_parser.c"
    break;

  case 601: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6323 "conf_parser.c"
    break;

  case 602: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2776 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6332 "conf_parser.c"
    break;

  case 603: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2782 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6341 "conf_parser.c"
    break;

  case 604: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2788 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6350 "conf_parser.c"
    break;

  case 605: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2794 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6362 "conf_parser.c"
    break;

  case 606: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2803 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6371 "conf_parser.c"
    break;

  case 607: /* serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'  */
#line 2809 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6380 "conf_parser.c"
    break;


#line 6384 "conf_parser.c"

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

