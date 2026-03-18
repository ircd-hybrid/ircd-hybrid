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
#include "links_cache.h"
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
    modes,
    klass,
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
    DISABLE_DNS = 296,             /* DISABLE_DNS  */
    DISABLE_IDENT = 297,           /* DISABLE_IDENT  */
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
    HIDE_SERVERS = 320,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 321,           /* HIDE_SERVICES  */
    HOST = 322,                    /* HOST  */
    HUB = 323,                     /* HUB  */
    HUB_MASK = 324,                /* HUB_MASK  */
    IDENT_TIMEOUT = 325,           /* IDENT_TIMEOUT  */
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
    LOADMODULE = 347,              /* LOADMODULE  */
    MASK = 348,                    /* MASK  */
    MASS = 349,                    /* MASS  */
    MAX_ACCEPT = 350,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 351,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 352,                /* MAX_BANS  */
    MAX_BANS_LARGE = 353,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 354,            /* MAX_CHANNELS  */
    MAX_IDLE = 355,                /* MAX_IDLE  */
    MAX_INVITES = 356,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 357,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 358,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 359,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 360,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 361,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 362,              /* MAX_NUMBER  */
    MAX_TARGETS = 363,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 364,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 365,                 /* MESSAGE  */
    MIN_IDLE = 366,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 367,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 368,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 369,                  /* MODULE  */
    MODULE_BASE_PATH = 370,        /* MODULE_BASE_PATH  */
    MOTD = 371,                    /* MOTD  */
    MOTD_FILE = 372,               /* MOTD_FILE  */
    NAME = 373,                    /* NAME  */
    NEED_IDENT = 374,              /* NEED_IDENT  */
    NEED_PASSWORD = 375,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 376,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 377,            /* NETWORK_NAME  */
    NICK = 378,                    /* NICK  */
    NO_OPER_FLOOD = 379,           /* NO_OPER_FLOOD  */
    NO_TILDE = 380,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 381,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 382,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 383,     /* NUMBER_PER_IP_LOCAL  */
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
    REGISTRATION_TIMEOUT = 398,    /* REGISTRATION_TIMEOUT  */
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
#define DISABLE_DNS 296
#define DISABLE_IDENT 297
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
#define HIDE_SERVERS 320
#define HIDE_SERVICES 321
#define HOST 322
#define HUB 323
#define HUB_MASK 324
#define IDENT_TIMEOUT 325
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
#define LOADMODULE 347
#define MASK 348
#define MASS 349
#define MAX_ACCEPT 350
#define MAX_AWAY_LENGTH 351
#define MAX_BANS 352
#define MAX_BANS_LARGE 353
#define MAX_CHANNELS 354
#define MAX_IDLE 355
#define MAX_INVITES 356
#define MAX_KICK_LENGTH 357
#define MAX_MONITOR 358
#define MAX_NICK_CHANGES 359
#define MAX_NICK_LENGTH 360
#define MAX_NICK_TIME 361
#define MAX_NUMBER 362
#define MAX_TARGETS 363
#define MAX_TOPIC_LENGTH 364
#define MESSAGE 365
#define MIN_IDLE 366
#define MIN_NONWILDCARD 367
#define MIN_NONWILDCARD_SIMPLE 368
#define MODULE 369
#define MODULE_BASE_PATH 370
#define MOTD 371
#define MOTD_FILE 372
#define NAME 373
#define NEED_IDENT 374
#define NEED_PASSWORD 375
#define NETWORK_DESCRIPTION 376
#define NETWORK_NAME 377
#define NICK 378
#define NO_OPER_FLOOD 379
#define NO_TILDE 380
#define NUMBER_PER_CIDR 381
#define NUMBER_PER_IP_GLOBAL 382
#define NUMBER_PER_IP_LOCAL 383
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
#define REGISTRATION_TIMEOUT 398
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
  YYSYMBOL_DISABLE_DNS = 41,               /* DISABLE_DNS  */
  YYSYMBOL_DISABLE_IDENT = 42,             /* DISABLE_IDENT  */
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
  YYSYMBOL_HIDE_SERVERS = 65,              /* HIDE_SERVERS  */
  YYSYMBOL_HIDE_SERVICES = 66,             /* HIDE_SERVICES  */
  YYSYMBOL_HOST = 67,                      /* HOST  */
  YYSYMBOL_HUB = 68,                       /* HUB  */
  YYSYMBOL_HUB_MASK = 69,                  /* HUB_MASK  */
  YYSYMBOL_IDENT_TIMEOUT = 70,             /* IDENT_TIMEOUT  */
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
  YYSYMBOL_LOADMODULE = 92,                /* LOADMODULE  */
  YYSYMBOL_MASK = 93,                      /* MASK  */
  YYSYMBOL_MASS = 94,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 95,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_AWAY_LENGTH = 96,           /* MAX_AWAY_LENGTH  */
  YYSYMBOL_MAX_BANS = 97,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 98,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 99,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 100,                 /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 101,              /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 102,          /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 103,              /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 104,         /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 105,          /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 106,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 107,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 108,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 109,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 110,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 111,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 112,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 113,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 114,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 115,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 116,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 117,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 118,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 119,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 120,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 121,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 122,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 123,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 124,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 125,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 126,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 127,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 128,      /* NUMBER_PER_IP_LOCAL  */
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
  YYSYMBOL_REGISTRATION_TIMEOUT = 143,     /* REGISTRATION_TIMEOUT  */
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
  YYSYMBOL_general_disable_ident = 484,    /* general_disable_ident  */
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
  YYSYMBOL_general_registration_timeout = 500, /* general_registration_timeout  */
  YYSYMBOL_channel_entry = 501,            /* channel_entry  */
  YYSYMBOL_channel_items = 502,            /* channel_items  */
  YYSYMBOL_channel_item = 503,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 504,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 505,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 506,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 507, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 508, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 509, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 510, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 511, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 512, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 513, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 514, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 515,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 516,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 517,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 518,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 519,  /* channel_max_kick_length  */
  YYSYMBOL_channel_default_join_flood_count = 520, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 521, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 522,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 523,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 524,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 525, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 526, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 527, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 528, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 529,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 530, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 531,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 532         /* serverhide_hidden  */
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
#define YYLAST   1262

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
     841,   841,   854,   855,   857,   857,   858,   858,   860,   868,
     871,   877,   876,   882,   886,   890,   894,   898,   902,   906,
     910,   921,   920,   982,   982,   983,   984,   985,   986,   987,
     988,   989,   990,   991,   992,   993,   995,  1001,  1007,  1013,
    1019,  1030,  1036,  1047,  1053,  1060,  1059,  1065,  1065,  1066,
    1070,  1074,  1078,  1082,  1086,  1090,  1094,  1098,  1102,  1106,
    1110,  1114,  1118,  1122,  1126,  1130,  1134,  1138,  1142,  1146,
    1150,  1154,  1158,  1162,  1166,  1170,  1174,  1178,  1189,  1188,
    1244,  1244,  1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,
    1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1262,  1268,
    1274,  1280,  1286,  1292,  1298,  1304,  1310,  1317,  1323,  1329,
    1335,  1344,  1354,  1353,  1359,  1359,  1360,  1364,  1375,  1374,
    1381,  1380,  1385,  1385,  1386,  1390,  1394,  1398,  1402,  1408,
    1408,  1409,  1409,  1409,  1409,  1409,  1411,  1411,  1413,  1413,
    1415,  1428,  1445,  1451,  1462,  1461,  1509,  1509,  1510,  1511,
    1512,  1513,  1514,  1515,  1516,  1517,  1518,  1520,  1526,  1532,
    1538,  1550,  1549,  1555,  1555,  1556,  1560,  1564,  1568,  1572,
    1576,  1580,  1584,  1588,  1594,  1608,  1617,  1631,  1630,  1645,
    1645,  1646,  1646,  1646,  1646,  1648,  1654,  1660,  1670,  1672,
    1672,  1673,  1673,  1675,  1692,  1691,  1714,  1714,  1715,  1715,
    1715,  1715,  1717,  1723,  1743,  1742,  1748,  1748,  1749,  1753,
    1757,  1761,  1765,  1769,  1773,  1777,  1781,  1785,  1796,  1795,
    1814,  1814,  1815,  1815,  1815,  1817,  1824,  1823,  1829,  1829,
    1830,  1834,  1838,  1842,  1846,  1850,  1854,  1858,  1862,  1866,
    1877,  1876,  1933,  1933,  1934,  1935,  1936,  1937,  1938,  1939,
    1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,  1948,  1949,
    1951,  1957,  1963,  1969,  1975,  1988,  2001,  2007,  2013,  2017,
    2024,  2023,  2028,  2028,  2029,  2033,  2039,  2050,  2056,  2062,
    2068,  2084,  2083,  2107,  2107,  2108,  2108,  2108,  2110,  2130,
    2141,  2140,  2165,  2165,  2166,  2166,  2166,  2168,  2174,  2184,
    2186,  2186,  2187,  2187,  2189,  2207,  2206,  2227,  2227,  2228,
    2228,  2228,  2230,  2236,  2246,  2248,  2248,  2249,  2250,  2251,
    2252,  2253,  2254,  2255,  2256,  2257,  2258,  2259,  2260,  2261,
    2262,  2263,  2264,  2265,  2266,  2267,  2268,  2269,  2270,  2271,
    2272,  2273,  2274,  2275,  2276,  2277,  2278,  2279,  2280,  2281,
    2282,  2283,  2284,  2285,  2286,  2287,  2288,  2289,  2290,  2291,
    2292,  2293,  2294,  2295,  2296,  2297,  2298,  2299,  2300,  2301,
    2302,  2303,  2306,  2311,  2316,  2321,  2326,  2331,  2336,  2341,
    2346,  2351,  2356,  2361,  2366,  2371,  2376,  2381,  2389,  2394,
    2399,  2404,  2409,  2414,  2419,  2424,  2429,  2434,  2439,  2444,
    2449,  2454,  2459,  2464,  2469,  2474,  2479,  2484,  2489,  2494,
    2499,  2504,  2509,  2514,  2523,  2528,  2533,  2538,  2543,  2560,
    2568,  2576,  2584,  2594,  2604,  2612,  2620,  2622,  2622,  2623,
    2624,  2625,  2626,  2627,  2628,  2629,  2630,  2631,  2632,  2633,
    2634,  2635,  2636,  2637,  2638,  2639,  2640,  2641,  2643,  2648,
    2654,  2660,  2665,  2670,  2675,  2680,  2685,  2690,  2695,  2700,
    2705,  2710,  2715,  2720,  2743,  2748,  2757,  2759,  2759,  2760,
    2761,  2762,  2763,  2764,  2765,  2766,  2767,  2768,  2770,  2776,
    2787,  2796,  2802,  2808,  2814,  2823
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
  "DESCRIPTION", "DIE", "DISABLE_DNS", "DISABLE_IDENT",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR",
  "DLINE_MIN_CIDR6", "EMAIL", "ENABLE_ADMIN", "ENABLE_EXTBANS",
  "ENABLE_OWNER", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "FLATTEN_LINKS_DELAY",
  "FLATTEN_LINKS_FILE", "GECOS", "GENERAL", "HIDDEN", "HIDDEN_NAME",
  "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVERS",
  "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK", "IDENT_TIMEOUT",
  "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME",
  "INVITE_DELAY_CHANNEL", "INVITE_EXPIRE_TIME", "IP", "IRCD_AUTH",
  "IRCD_FLAGS", "IRCD_SID", "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT",
  "KLINE", "KLINE_EXEMPT", "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6",
  "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL",
  "LEAF_MASK", "LISTEN", "LOADMODULE", "MASK", "MASS", "MAX_ACCEPT",
  "MAX_AWAY_LENGTH", "MAX_BANS", "MAX_BANS_LARGE", "MAX_CHANNELS",
  "MAX_IDLE", "MAX_INVITES", "MAX_KICK_LENGTH", "MAX_MONITOR",
  "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MESSAGE", "MIN_IDLE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE",
  "MODULE_BASE_PATH", "MOTD", "MOTD_FILE", "NAME", "NEED_IDENT",
  "NEED_PASSWORD", "NETWORK_DESCRIPTION", "NETWORK_NAME", "NICK",
  "NO_OPER_FLOOD", "NO_TILDE", "NUMBER_PER_CIDR", "NUMBER_PER_IP_GLOBAL",
  "NUMBER_PER_IP_LOCAL", "OPER_UMODES", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD",
  "PATH", "PING_COOKIE", "PING_TIME", "PORT", "RANDOM_IDLE", "REASON",
  "REDIRPORT", "REDIRSERV", "REGISTRATION_TIMEOUT", "REHASH", "REMOTE",
  "REMOTEBAN", "RESIDENT", "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS",
  "SEND_PASSWORD", "SENDQ", "SERVERHIDE", "SERVERINFO", "SHORT_MOTD",
  "SPECIALS_IN_IDENT", "SPOOF", "SQUIT", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_M_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL",
  "T_BIND", "T_COMMAND", "T_CLUSTER", "T_DEBUG", "T_DLINE", "T_FILE",
  "T_GLOBOPS", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_OPME",
  "T_PREPEND", "T_PSEUDO", "T_RECVQ", "T_RESTART", "T_SERVER", "T_SERVICE",
  "T_SET", "T_SHARED", "T_SIZE", "T_TARGET", "T_TLS", "T_UMODES",
  "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_WEBIRC", "TBOOL",
  "THROTTLE_COUNT", "THROTTLE_TIME", "TIMEOUT", "TLS_CERTIFICATE_FILE",
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
  "general_max_targets", "general_ping_cookie", "general_disable_ident",
  "general_disable_dns", "general_throttle_count", "general_throttle_time",
  "general_oper_umodes", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_default_floodtime", "general_cloak_enabled",
  "general_cloak_cidr_len_ipv4", "general_cloak_cidr_len_ipv6",
  "general_cloak_num_bits", "general_cloak_secret", "general_cloak_suffix",
  "general_ident_timeout", "general_registration_timeout", "channel_entry",
  "channel_items", "channel_item", "channel_enable_extbans",
  "channel_enable_owner", "channel_enable_admin",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_invite_delay_channel",
  "channel_invite_expire_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_channels", "channel_max_invites", "channel_max_bans",
  "channel_max_bans_large", "channel_max_kick_length",
  "channel_default_join_flood_count", "channel_default_join_flood_time",
  "serverhide_entry", "serverhide_items", "serverhide_item",
  "serverhide_flatten_links", "serverhide_flatten_links_delay",
  "serverhide_flatten_links_file", "serverhide_disable_remote_commands",
  "serverhide_hide_servers", "serverhide_hide_services",
  "serverhide_hidden_name", "serverhide_hidden", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-864)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-131)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -864,   761,  -864,  -170,  -220,  -211,  -864,  -864,  -864,  -209,
    -864,  -199,  -864,  -864,  -864,  -207,  -194,  -864,  -864,  -864,
    -188,  -165,  -864,  -160,  -864,  -149,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,    55,   901,  -148,  -135,  -132,    42,  -130,
     540,  -127,  -120,  -108,  -179,   -91,   -74,   -70,   -69,   403,
     654,   -64,   132,   -60,    19,   -59,   -52,   -53,   -51,   -50,
       6,  -864,  -864,  -864,  -864,  -864,   -45,   -43,   -39,   -35,
     -28,   -26,   -25,   -23,   -22,   -14,   -10,     7,    57,    66,
      69,    79,    81,    83,   199,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,   805,   599,    17,  -864,    87,    43,
    -864,  -864,    18,  -864,    93,    97,    98,    99,   102,   103,
     105,   107,   108,   109,   112,   114,   117,   120,   121,   130,
     131,   138,   143,   144,   146,   147,   148,   149,   151,   153,
     155,   161,   162,   163,   166,   170,   174,   178,   179,   180,
     182,   186,   188,   193,   196,   197,   200,   208,   210,   211,
     213,   215,   218,   222,   223,   224,   232,   234,    89,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,   347,    25,   282,    -1,    36,    45,
      33,   332,    76,  -864,   244,   246,   250,   251,   252,   253,
     254,   257,     3,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,   134,   258,   259,   260,   261,   262,   263,   266,
     267,   268,   269,   271,   273,   274,   275,   277,   279,   281,
     160,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,    23,
     169,   284,    48,  -864,  -864,  -864,   145,    29,  -864,   285,
      34,  -864,  -864,    71,  -864,   203,   280,   286,   288,  -864,
      92,   291,   313,   317,   320,   322,   296,   291,   291,   291,
     297,   291,   291,   298,   304,   307,   309,   312,   329,  -864,
     336,   311,   318,   325,  -864,   341,   343,   344,   350,   351,
     354,   355,   356,   357,   359,   360,   290,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,   338,   363,   366,   368,   370,   372,   373,
    -864,   374,   375,   376,   379,   380,   381,   382,   384,   324,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,   386,   387,     5,
    -864,  -864,  -864,   392,   396,  -864,  -864,   390,   395,    30,
    -864,  -864,  -864,   426,   291,   400,   291,   291,   430,   407,
     408,   409,   411,   412,   439,   415,   291,   444,   446,   421,
     424,   453,   291,   454,   291,   428,   429,   432,   433,   437,
     440,   291,   445,   448,   449,   457,   451,   478,   291,   291,
     479,   291,   481,   455,   483,   484,   485,   488,   489,   491,
     493,   468,   291,   291,   291,   497,   471,   473,  -864,   474,
     480,   482,  -864,   486,   487,   490,   492,   494,    22,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,   495,
     499,    74,  -864,  -864,  -864,   504,   505,   506,  -864,   508,
    -864,    13,  -864,  -864,  -864,  -864,  -864,  -864,   507,  -864,
    -864,  -864,   515,   514,   517,   177,  -864,  -864,  -864,   522,
     521,   525,  -864,   527,   534,   535,   536,   541,   546,   548,
     327,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,   552,   549,   553,   554,     4,  -864,  -864,  -864,
    -864,   511,   518,   291,   501,   545,   555,   582,   585,   559,
    -864,  -864,   562,   564,   591,   566,   567,   568,   571,   572,
     573,   574,   580,   581,   583,   584,   586,   588,   589,   565,
    -864,   593,   578,  -864,    91,  -864,  -864,  -864,  -864,   622,
     596,  -864,   592,   598,   597,   600,   602,   603,    31,  -864,
    -864,  -864,  -864,  -864,   608,   601,  -864,   609,   606,  -864,
     612,    32,  -864,  -864,  -864,  -864,   615,   616,   617,  -864,
     618,   283,   619,   620,   623,   624,   625,   626,   627,   628,
     629,   634,   638,   640,   641,   642,   644,   647,   648,  -864,
    -864,   650,   651,   291,   649,   655,   291,   656,   291,   645,
     657,   658,   659,   291,   660,   660,   653,  -864,  -864,   663,
     -97,   664,   691,   666,   667,   665,   668,   670,   671,   674,
     677,   291,   678,   679,   669,  -864,   681,   682,   683,  -864,
     684,  -864,   688,   689,   693,  -864,   694,   695,   696,   697,
     698,   699,   703,   707,   708,   709,   710,   712,   715,   716,
     722,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     734,   735,   736,   737,   738,   739,   740,   741,   746,   747,
     748,   749,   750,   751,   752,   753,   754,   755,   756,   760,
     763,   764,   765,   766,   770,   773,   774,   775,   776,   777,
    -864,  -864,   690,   717,   680,   780,   762,   781,   782,   783,
     784,  -864,   785,   787,   786,  -864,  -864,   789,   790,   788,
     792,   793,  -864,    -1,  -864,   791,   794,   795,  -864,  -864,
     796,   810,   797,   798,   799,   800,   802,   829,   804,   806,
     803,  -864,  -864,   807,   808,   809,   811,  -864,   812,   813,
     814,   815,   816,   817,   818,   819,  -864,   820,   821,   822,
     823,   824,   825,   826,   827,   828,   830,   831,   832,   833,
     834,   835,   836,   837,  -864,  -864,   840,   838,   839,  -864,
     841,  -864,   167,  -864,   844,   845,   846,   847,   848,  -864,
     849,  -864,  -864,   852,   850,   853,   854,  -864,  -864,  -864,
    -864,  -864,   291,   291,   291,   291,   291,   291,   291,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,   855,   856,
     857,   -12,   858,   859,   860,   861,   862,   863,   864,   865,
     866,    54,   867,   868,  -864,   869,   870,   871,   872,   873,
     874,   875,    -5,   876,   877,   878,   879,   880,   881,   882,
     883,  -864,   884,   885,  -864,  -864,   886,   887,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,   888,   889,   303,   890,   891,   892,   893,
     894,  -864,   895,   896,  -864,   897,   898,    -9,   614,   842,
    -864,  -864,  -864,   899,   900,  -864,   902,   903,   551,   904,
     905,   906,   907,   908,   909,   910,  -864,   911,   912,   913,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,   914,   397,  -864,  -864,
     915,   851,   916,  -864,    85,  -864,  -864,  -864,  -864,   917,
     919,   920,   921,  -864,  -864,   922,   643,   923,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -214,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,   660,   660,   660,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -195,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -193,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -181,
    -864,   925,   792,   926,  -864,  -864,  -864,  -864,  -864,  -864,
     924,  -864,   927,   928,  -864,   929,  -864,   930,   931,  -864,
    -864,   932,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -161,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -153,  -864,  -864,   918,
    -184,   934,   937,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -152,
    -864,  -864,  -864,   -12,  -864,  -864,  -864,  -864,    -5,  -864,
     303,  -864,    -9,  -864,  -864,  -864,   579,   570,   933,   945,
     984,  1011,  1014,  -864,   551,  -864,   397,   938,   939,   940,
     276,  -864,  -864,   643,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,   941,  -864,
    -864
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
       0,    93,    94,    96,    95,   577,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   558,   574,   575,   576,   573,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   559,
     560,   570,   571,   572,     0,     0,     0,   433,     0,     0,
     431,   432,     0,   501,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   446,
     447,   448,   491,   454,   492,   486,   487,   488,   489,   458,
     449,   450,   451,   452,   453,   473,   455,   456,   457,   459,
     460,   490,   464,   465,   466,   467,   463,   462,   468,   475,
     476,   469,   470,   471,   461,   472,   483,   484,   485,   481,
     482,   474,   479,   480,   477,   478,   493,   494,   495,   496,
     497,   498,   499,   500,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   598,   599,   600,   601,   602,   603,   604,
     606,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    69,    67,    65,    70,    71,    72,    66,    56,
      68,    58,    59,    60,    61,    62,    63,    64,    57,     0,
       0,     0,     0,   125,   126,   127,     0,     0,   322,     0,
       0,   320,   321,     0,    97,     0,     0,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   557,
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
       0,     0,     0,     0,     0,     0,     0,     0,   445,     0,
       0,     0,   291,     0,     0,     0,     0,     0,     0,   277,
     278,   279,   280,   285,   281,   282,   283,   284,   417,     0,
       0,     0,   414,   415,   416,     0,     0,     0,   250,     0,
     262,     0,   260,   261,   263,   264,    52,    51,    48,    50,
      46,    45,     0,     0,     0,     0,   104,   105,   106,     0,
       0,     0,   175,     0,     0,     0,     0,     0,     0,     0,
       0,   154,   155,   156,   157,   158,   161,   162,   163,   160,
     159,   164,     0,     0,     0,     0,     0,   310,   311,   312,
     313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     597,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,   356,     0,   351,   352,   353,   128,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,   113,
     114,   116,   115,   117,     0,     0,   319,     0,     0,   334,
       0,     0,   327,   328,   329,   330,     0,     0,     0,    91,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   556,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   210,   389,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   372,     0,     0,     0,   422,
       0,   429,     0,     0,     0,   437,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     444,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,     0,     0,   413,   265,     0,     0,     0,
       0,     0,   259,     0,   107,     0,     0,     0,   103,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   314,     0,     0,     0,     0,   309,     0,     0,
       0,     0,     0,     0,     0,     0,   596,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,   354,     0,     0,     0,   350,
       0,   123,     0,   118,     0,     0,     0,     0,     0,   112,
       0,   318,   331,     0,     0,     0,     0,   326,   100,    99,
      98,   594,    29,    29,    29,    29,    29,    29,    29,    31,
      30,   595,   581,   580,   578,   579,   582,   583,   584,   585,
     586,   587,   588,   591,   592,   589,   590,   593,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,     0,     0,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   371,     0,     0,   421,   434,     0,     0,   436,   513,
     518,   502,   503,   531,   548,   549,   550,   551,   552,   553,
     506,   546,   547,   540,   539,   507,   508,   512,   554,   521,
     511,   509,   510,   516,   517,   504,   515,   514,   537,   544,
     545,   535,   543,   532,   530,   533,   538,   555,   534,   536,
     523,   529,   528,   524,   525,   526,   527,   541,   542,   520,
     519,   522,   505,     0,     0,     0,     0,     0,     0,     0,
       0,   275,     0,     0,   412,     0,     0,     0,   270,   266,
     269,   249,    49,     0,     0,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     0,     0,     0,
     308,   611,   608,   609,   610,   615,   614,   612,   613,    86,
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
    -864,  -864,  -864,  -392,  -329,  -863,  -674,  -864,  -864,  -864,
    -864,   377,  -864,  -864,   935,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,   960,  -864,  -864,  -864,  -864,  -864,
    -864,   639,  -864,  -864,  -864,  -864,  -864,   423,  -864,  -864,
    -864,  -864,  -864,  -864,   936,  -864,  -864,  -864,  -864,   119,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,   510,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,   -79,  -864,  -864,  -864,   843,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,   -57,  -864,  -864,  -864,  -864,  -864,   -65,
    -864,   661,  -864,  -864,  -864,    26,  -864,  -864,  -864,  -864,
    -864,   685,  -864,  -864,  -864,  -864,  -864,  -864,  -864,   -61,
    -864,  -864,  -864,  -864,  -864,  -864,   621,  -864,  -864,  -864,
    -864,  -864,   942,  -864,  -864,  -864,  -864,   550,  -864,  -864,
    -864,  -864,  -864,   -83,  -864,  -864,  -864,   587,  -864,  -864,
    -864,  -864,   -72,  -864,  -864,  -864,   801,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,   -49,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,   675,  -864,
    -864,  -864,  -864,  -864,   769,  -864,  -864,  -864,  -864,  1056,
    -864,  -864,  -864,  -864,   767,  -864,  -864,  -864,  -864,  1002,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  1088,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,   943,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   869,   870,  1095,  1096,    28,    29,   248,
     528,   529,    30,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    31,    80,    81,    82,    83,    84,    32,    66,
     535,   536,   537,   538,    33,    73,   618,   619,   620,   621,
     622,   623,    34,   312,   313,   314,   315,   316,  1054,  1055,
    1056,  1057,  1058,  1211,  1288,    35,    67,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   792,
    1183,  1184,    36,    55,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   664,  1081,  1082,    37,    63,   520,   779,  1149,  1150,
     521,   522,   523,  1153,   999,  1000,   524,   525,    38,    61,
     498,   499,   500,   501,   502,   503,   504,   764,  1133,  1134,
     505,   506,   507,    39,    68,   566,   567,   568,   569,   570,
      40,   320,   321,   322,    41,    75,   631,   632,   633,   634,
     635,   854,  1229,  1230,    42,    71,   604,   605,   606,   607,
     837,  1206,  1207,    43,    56,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   685,  1108,  1109,
     411,   412,   413,   414,   415,    44,    62,   511,   512,   513,
     514,    45,    57,   419,   420,   421,   422,    46,   129,   130,
     131,    47,    59,   429,   430,   431,   432,    48,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    49,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    50,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     902,   903,   642,  1106,   253,   562,   416,    76,   648,   649,
     650,  1144,   652,   653,   515,  1258,    53,  1232,   416,   426,
     318,  1233,    64,   489,   601,    54,   508,    58,  1145,   526,
     613,   426,   613,   627,   532,   318,  1237,    60,  1239,    65,
    1238,   490,  1240,   127,   127,    77,   901,   254,    69,   310,
    1241,  1146,  1079,    78,  1242,   247,    76,   563,   255,   256,
     257,    51,    52,   258,   259,  1092,  1093,  1094,   260,   261,
    1253,    70,   627,   491,  1254,   508,    72,   562,  1255,  1262,
     516,   417,  1256,  1263,   906,   907,  1050,    74,   124,   517,
     133,   518,   601,   417,    77,   134,   135,   564,   136,   137,
     492,   125,    78,   138,   126,   707,   132,   709,   710,   244,
     139,   140,   141,   142,   143,   144,   245,   719,   128,   128,
     145,   146,   147,   725,    79,   727,   533,  1080,   246,   563,
     148,   149,   734,   310,   150,   151,   427,   319,   249,   741,
     742,   602,   744,   152,   565,   418,   527,   614,   427,   614,
     628,   519,   319,   755,   756,   757,   493,   418,   428,   153,
     154,   272,   250,   494,   495,   509,   251,   252,  1050,   564,
     428,   155,   309,    79,   156,   157,   317,   323,   532,   324,
     325,  1147,   326,   327,   158,   159,   496,  1148,   330,   628,
     331,  1107,   160,   161,   332,   162,   273,   163,   333,   274,
      85,   164,   165,  1051,   615,   334,   615,   335,   336,   602,
     337,   338,   534,   166,   509,   616,   565,   616,   167,   339,
     168,   169,   170,   340,   617,   171,   617,  -130,   275,  1234,
    1235,  1236,   172,    86,    87,   579,   806,   698,   328,   276,
     341,   603,    88,   497,   810,   781,   510,    89,    90,    91,
     629,   173,   174,   630,   770,   175,   176,   177,   178,   179,
     180,   181,   704,   848,   856,   277,   625,   530,   311,   278,
     533,    92,    93,    94,    95,   424,   531,   279,   280,  1052,
     610,   281,   282,   515,   901,  1051,    96,    97,    98,   629,
     342,   350,   630,   182,   183,   510,    99,   100,   101,   343,
     102,   103,   344,  1053,   184,   185,   774,   351,   352,   603,
     283,  -130,   345,   186,   346,   187,   347,  1212,  1124,   353,
     423,   487,   640,   838,   612,   383,   433,   384,   539,   385,
     434,   435,   436,   539,   890,   437,   438,   893,   439,   895,
     440,   441,   442,   386,   900,   443,   540,   444,   489,   516,
     445,   540,   311,   446,   447,  1125,   534,  1280,   517,  1281,
     518,  1052,   918,   448,   449,   581,   490,   284,   354,   285,
     286,   450,   287,   288,   289,   387,   451,   452,   541,   453,
     454,   455,   456,   541,   457,  1053,   458,  1126,   459,   355,
     356,   388,   599,   389,   460,   461,   462,   357,   491,   463,
     608,   358,   390,   464,   253,   542,  1282,   465,   359,   787,
     542,   466,   467,   468,   391,   469,   360,   361,   362,   470,
     519,   471,  1127,  1128,  1283,   492,   472,   363,  1129,   473,
     474,   348,   636,   475,   862,   863,   864,   865,   866,   867,
     868,   476,   392,   477,   478,   543,   479,   254,   480,   364,
     543,   481,  1130,  1284,  1285,   482,   483,   484,   255,   256,
     257,   544,   393,   258,   259,   485,   544,   486,   260,   261,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,   571,   365,   572,
    1196,   493,   394,   573,   574,   575,   576,   577,   494,   495,
     578,   582,   583,   584,   585,   586,   587,  1286,   395,   588,
     589,   590,   591,  1287,   592,  1131,   593,   594,   595,   637,
     596,   496,   597,   641,   598,   638,   643,   609,   624,   639,
     644,   641,   676,   645,   545,   646,   647,   651,   654,   545,
     396,  1132,   397,   398,   655,   546,  1259,   656,   547,   657,
     546,   133,   658,   547,   661,  1197,   134,   135,   548,   136,
     137,   662,   549,   548,   138,  1158,   694,   549,   663,   800,
     659,   139,   140,   141,   142,   143,   144,   660,   497,   678,
    1198,   145,   146,   147,   665,  1199,   666,   667,  1159,  1160,
    1200,   148,   149,   668,   669,   150,   151,   670,   671,   672,
     673,  1161,   674,   675,   152,  1201,   679,  1202,  1203,   680,
     383,   681,   384,   682,   385,   683,   684,   686,   687,   688,
     153,   154,   689,   690,   691,   692,  1204,   693,   386,   696,
     697,   700,   155,   702,  1205,   156,   157,   701,   703,   706,
     708,  1162,  1163,   711,  1164,   158,   159,   712,   713,   714,
     715,   716,   717,   160,   161,   718,   162,   720,   163,   721,
     387,   722,   164,   165,   723,   272,   724,   726,   728,   729,
     738,  1165,   730,   731,   166,  1166,   388,   732,   389,   167,
     733,   168,   169,   170,  1167,   735,   171,   390,   736,   737,
     739,   740,   743,   172,   745,   746,   747,   748,   749,   391,
     273,   750,   751,   274,   752,  1168,   753,  1169,   754,  1170,
     758,   759,   173,   174,   760,   761,   175,   176,   177,   178,
     179,   180,   181,   762,   808,   763,  1171,   392,  1269,   765,
     766,   809,   275,   767,  1268,   768,  1219,   769,   772,  1172,
     811,  1173,   773,   276,  1174,   776,  1175,   393,   777,   778,
    1176,   780,   783,  1177,   182,   183,   784,   785,   812,  1178,
     786,  1179,  1180,   789,   790,   184,   185,   394,   791,   277,
     793,     2,     3,   278,   186,     4,   187,   794,   795,   796,
    1181,   279,   280,   395,   797,   281,   282,     5,  1182,   798,
       6,   799,   803,   802,   813,   814,   804,   805,   815,     7,
     816,  1220,   817,   818,   819,   820,   834,   821,   822,     8,
     823,   824,   825,   826,   283,   396,   350,   397,   398,   827,
     828,   836,   829,   830,     9,   831,  1221,   832,   833,    10,
      11,  1222,   351,   352,   835,   840,  1223,   841,   842,   843,
     844,  1151,   851,   845,   353,   846,   847,   850,    12,   853,
     852,  1224,    13,  1225,  1226,   855,   858,   859,   860,   861,
     871,   872,    14,    15,   873,   874,   875,   876,   877,   878,
     879,   284,  1227,   285,   286,   880,   287,   288,   289,   881,
    1228,   882,   883,   884,   896,   885,    16,    17,   886,   887,
     888,   889,   891,   354,   904,   892,   894,   897,   898,   899,
     901,    18,   905,   908,   909,   910,   911,   913,   912,   914,
     921,   915,    85,   916,   355,   356,   917,   919,   920,    19,
     922,   923,   357,   985,   924,   925,   358,   926,   927,   983,
     984,    20,    21,   359,   928,   929,   930,   931,   932,   933,
     934,   360,   361,   362,   935,    86,    87,    22,   936,   937,
     938,   939,   363,   940,    88,    23,   941,   942,    24,    89,
      90,    91,    25,   943,    26,   944,   945,   946,   947,   948,
     949,   950,   951,   952,   364,   953,   954,   955,   956,   957,
     958,   959,   960,    92,    93,    94,    95,   961,   962,   963,
     964,   965,   966,   967,   968,   969,   970,   971,    96,    97,
      98,   972,   987,   365,   973,   974,   975,   976,    99,   100,
     101,   977,   102,   103,   978,   979,   980,   981,   982,   986,
     988,   989,   990,  1007,   992,   991,   993,   994,   995,   996,
    1003,   997,   998,  1004,  1001,  1006,  1005,  1009,  1010,  1011,
    1008,  1012,  1013,  1014,  1016,  1015,  1017,  1018,  1019,  1271,
     329,   849,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
     801,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,
    1048,  1047,  1049,  1059,  1060,  1061,  1062,  1152,  1270,  1063,
    1064,  1065,  1067,  1066,  1209,  1068,  1076,  1077,  1078,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1097,  1098,
    1099,  1100,  1101,  1102,  1103,  1104,  1105,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1154,  1155,  1272,  1156,  1157,  1185,  1186,  1187,  1188,  1189,
    1190,  1191,  1192,  1193,  1194,  1195,  1208,  1257,  1214,  1210,
    1215,  1216,  1217,  1218,  1231,  1243,  1273,  1245,  1246,  1274,
    1002,  1247,  1248,  1249,  1250,  1251,  1252,  1260,  1261,  1277,
    1278,  1279,  1290,  1213,   788,  1275,  1264,  1267,  1244,  1266,
    1289,   857,   782,   771,  1276,   425,   775,   807,   699,  1265,
     488,   839,   349,     0,     0,     0,   705,     0,     0,     0,
     695,     0,     0,     0,     0,   580,     0,     0,     0,   677,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   600,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   611,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   626
};

static const yytype_int16 yycheck[] =
{
     674,   675,   331,     8,     1,     1,     1,     1,   337,   338,
     339,    20,   341,   342,     1,   199,   236,   231,     1,     1,
       1,   235,   229,     1,     1,   236,     1,   236,    37,    30,
       1,     1,     1,     1,     1,     1,   231,   236,   231,   233,
     235,    19,   235,     1,     1,    39,   230,    44,   236,     1,
     231,    60,    64,    47,   235,   234,     1,    53,    55,    56,
      57,   231,   232,    60,    61,    11,    12,    13,    65,    66,
     231,   236,     1,    51,   235,     1,   236,     1,   231,   231,
      67,    76,   235,   235,   181,   182,     1,   236,   236,    76,
       1,    78,     1,    76,    39,     6,     7,    93,     9,    10,
      78,   236,    47,    14,   236,   434,   236,   436,   437,   236,
      21,    22,    23,    24,    25,    26,   236,   446,    76,    76,
      31,    32,    33,   452,   118,   454,    93,   139,   236,    53,
      41,    42,   461,     1,    45,    46,   118,   118,   229,   468,
     469,   118,   471,    54,   140,   140,   147,   118,   118,   118,
     118,   138,   118,   482,   483,   484,   134,   140,   140,    70,
      71,     1,   236,   141,   142,   140,   236,   236,     1,    93,
     140,    82,   236,   118,    85,    86,   236,   236,     1,   231,
     233,   190,   233,   233,    95,    96,   164,   196,   233,   118,
     233,   196,   103,   104,   233,   106,    36,   108,   233,    39,
       1,   112,   113,   118,   175,   233,   175,   233,   233,   118,
     233,   233,   179,   124,   140,   186,   140,   186,   129,   233,
     131,   132,   133,   233,   195,   136,   195,   179,    68,  1092,
    1093,  1094,   143,    34,    35,   232,   232,   232,   232,    79,
     233,   218,    43,   221,   573,   232,   221,    48,    49,    50,
     218,   162,   163,   221,   232,   166,   167,   168,   169,   170,
     171,   172,   232,   232,   232,   105,   232,   231,   220,   109,
      93,    72,    73,    74,    75,   232,   231,   117,   118,   194,
     232,   121,   122,     1,   230,   118,    87,    88,    89,   218,
     233,     1,   221,   204,   205,   221,    97,    98,    99,   233,
     101,   102,   233,   218,   215,   216,   232,    17,    18,   218,
     150,   179,   233,   224,   233,   226,   233,   232,    15,    29,
     233,   232,   230,   232,   179,     1,   233,     3,     1,     5,
     233,   233,   233,     1,   663,   233,   233,   666,   233,   668,
     233,   233,   233,    19,   673,   233,    19,   233,     1,    67,
     233,    19,   220,   233,   233,    52,   179,    81,    76,    83,
      78,   194,   691,   233,   233,   231,    19,   207,    78,   209,
     210,   233,   212,   213,   214,    51,   233,   233,    51,   233,
     233,   233,   233,    51,   233,   218,   233,    84,   233,    99,
     100,    67,   232,    69,   233,   233,   233,   107,    51,   233,
     231,   111,    78,   233,     1,    78,   130,   233,   118,   232,
      78,   233,   233,   233,    90,   233,   126,   127,   128,   233,
     138,   233,   119,   120,   148,    78,   233,   137,   125,   233,
     233,   232,   229,   233,   151,   152,   153,   154,   155,   156,
     157,   233,   118,   233,   233,   118,   233,    44,   233,   159,
     118,   233,   149,   177,   178,   233,   233,   233,    55,    56,
      57,   134,   138,    60,    61,   233,   134,   233,    65,    66,
     862,   863,   864,   865,   866,   867,   868,   233,   188,   233,
      83,   134,   158,   233,   233,   233,   233,   233,   141,   142,
     233,   233,   233,   233,   233,   233,   233,   221,   174,   233,
     233,   233,   233,   227,   233,   202,   233,   233,   233,   229,
     233,   164,   233,   230,   233,   229,   203,   233,   233,   231,
     203,   230,   232,   203,   197,   203,   230,   230,   230,   197,
     206,   228,   208,   209,   230,   208,  1210,   230,   211,   230,
     208,     1,   230,   211,   233,   148,     6,     7,   221,     9,
      10,   233,   225,   221,    14,     4,   232,   225,   233,   232,
     231,    21,    22,    23,    24,    25,    26,   231,   221,   231,
     173,    31,    32,    33,   233,   178,   233,   233,    27,    28,
     183,    41,    42,   233,   233,    45,    46,   233,   233,   233,
     233,    40,   233,   233,    54,   198,   233,   200,   201,   233,
       1,   233,     3,   233,     5,   233,   233,   233,   233,   233,
      70,    71,   233,   233,   233,   233,   219,   233,    19,   233,
     233,   229,    82,   233,   227,    85,    86,   231,   233,   203,
     230,    80,    81,   203,    83,    95,    96,   230,   230,   230,
     229,   229,   203,   103,   104,   230,   106,   203,   108,   203,
      51,   230,   112,   113,   230,     1,   203,   203,   230,   230,
     203,   110,   230,   230,   124,   114,    67,   230,    69,   129,
     230,   131,   132,   133,   123,   230,   136,    78,   230,   230,
     229,   203,   203,   143,   203,   230,   203,   203,   203,    90,
      36,   203,   203,    39,   203,   144,   203,   146,   230,   148,
     203,   230,   162,   163,   231,   231,   166,   167,   168,   169,
     170,   171,   172,   233,   203,   233,   165,   118,   148,   233,
     233,   203,    68,   233,   145,   233,    83,   233,   233,   178,
     229,   180,   233,    79,   183,   231,   185,   138,   233,   233,
     189,   233,   235,   192,   204,   205,   231,   233,   203,   198,
     233,   200,   201,   231,   233,   215,   216,   158,   233,   105,
     233,     0,     1,   109,   224,     4,   226,   233,   233,   233,
     219,   117,   118,   174,   233,   121,   122,    16,   227,   233,
      19,   233,   233,   231,   229,   203,   233,   233,   203,    28,
     231,   148,   230,   229,   203,   229,   231,   230,   230,    38,
     229,   229,   229,   229,   150,   206,     1,   208,   209,   229,
     229,   233,   229,   229,    53,   229,   173,   229,   229,    58,
      59,   178,    17,    18,   231,   203,   183,   231,   236,   231,
     233,   217,   231,   233,    29,   233,   233,   229,    77,   233,
     231,   198,    81,   200,   201,   233,   231,   231,   231,   231,
     231,   231,    91,    92,   231,   231,   231,   231,   231,   231,
     231,   207,   219,   209,   210,   231,   212,   213,   214,   231,
     227,   231,   231,   231,   229,   231,   115,   116,   231,   231,
     230,   230,   233,    78,   231,   230,   230,   230,   230,   230,
     230,   130,   229,   229,   203,   229,   229,   229,   233,   229,
     231,   230,     1,   229,    99,   100,   229,   229,   229,   148,
     229,   229,   107,   233,   231,   231,   111,   229,   229,   229,
     203,   160,   161,   118,   231,   231,   231,   231,   231,   231,
     231,   126,   127,   128,   231,    34,    35,   176,   231,   231,
     231,   231,   137,   231,    43,   184,   231,   231,   187,    48,
      49,    50,   191,   231,   193,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   159,   231,   231,   231,   231,   231,
     231,   231,   231,    72,    73,    74,    75,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,    87,    88,
      89,   231,   230,   188,   231,   231,   231,   231,    97,    98,
      99,   231,   101,   102,   231,   231,   231,   231,   231,   229,
     229,   229,   229,   203,   229,   231,   229,   231,   229,   229,
     229,   233,   230,   229,   231,   229,   231,   229,   229,   229,
     233,   229,   203,   229,   231,   229,   229,   229,   229,    94,
      80,   618,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     550,   231,   231,   231,   231,   231,   231,   231,   231,   229,
     231,   233,   231,   229,   229,   229,   229,   235,   145,   231,
     231,   229,   229,   233,   233,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   148,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   229,   231,   233,
     231,   231,   231,   231,   231,   230,   145,   231,   234,   145,
     783,   234,   234,   234,   234,   234,   234,   233,   231,   231,
     231,   231,   231,  1054,   535,  1254,  1233,  1242,  1152,  1240,
    1263,   631,   521,   498,  1256,   129,   511,   566,   419,  1238,
     188,   604,   104,    -1,    -1,    -1,   429,    -1,    -1,    -1,
     399,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,   366,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   290,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   320
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   238,     0,     1,     4,    16,    19,    28,    38,    53,
      58,    59,    77,    81,    91,    92,   115,   116,   130,   148,
     160,   161,   176,   184,   187,   191,   193,   239,   244,   245,
     249,   269,   275,   281,   289,   302,   319,   341,   355,   370,
     377,   381,   391,   400,   422,   428,   434,   438,   444,   501,
     522,   231,   232,   236,   236,   320,   401,   429,   236,   439,
     236,   356,   423,   342,   229,   233,   276,   303,   371,   236,
     236,   392,   236,   282,   236,   382,     1,    39,    47,   118,
     270,   271,   272,   273,   274,     1,    34,    35,    43,    48,
      49,    50,    72,    73,    74,    75,    87,    88,    89,    97,
      98,    99,   101,   102,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   236,   236,   236,     1,    76,   435,
     436,   437,   236,     1,     6,     7,     9,    10,    14,    21,
      22,    23,    24,    25,    26,    31,    32,    33,    41,    42,
      45,    46,    54,    70,    71,    82,    85,    86,    95,    96,
     103,   104,   106,   108,   112,   113,   124,   129,   131,   132,
     133,   136,   143,   162,   163,   166,   167,   168,   169,   170,
     171,   172,   204,   205,   215,   216,   224,   226,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   236,   236,   236,   234,   246,   229,
     236,   236,   236,     1,    44,    55,    56,    57,    60,    61,
      65,    66,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,     1,    36,    39,    68,    79,   105,   109,   117,
     118,   121,   122,   150,   207,   209,   210,   212,   213,   214,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   236,
       1,   220,   290,   291,   292,   293,   294,   236,     1,   118,
     378,   379,   380,   236,   231,   233,   233,   233,   232,   271,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   232,   503,
       1,    17,    18,    29,    78,    99,   100,   107,   111,   118,
     126,   127,   128,   137,   159,   188,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,     1,     3,     5,    19,    51,    67,    69,
      78,    90,   118,   138,   158,   174,   206,   208,   209,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   417,   418,   419,   420,   421,     1,    76,   140,   430,
     431,   432,   433,   233,   232,   436,     1,   118,   140,   440,
     441,   442,   443,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   232,   446,     1,
      19,    51,    78,   134,   141,   142,   164,   221,   357,   358,
     359,   360,   361,   362,   363,   367,   368,   369,     1,   140,
     221,   424,   425,   426,   427,     1,    67,    76,    78,   138,
     343,   347,   348,   349,   353,   354,    30,   147,   247,   248,
     231,   231,     1,    93,   179,   277,   278,   279,   280,     1,
      19,    51,    78,   118,   134,   197,   208,   211,   221,   225,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,     1,    53,    93,   140,   372,   373,   374,   375,
     376,   233,   233,   233,   233,   233,   233,   233,   233,   232,
     524,   231,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   232,
     251,     1,   118,   218,   393,   394,   395,   396,   231,   233,
     232,   291,   179,     1,   118,   175,   186,   195,   283,   284,
     285,   286,   287,   288,   233,   232,   379,     1,   118,   218,
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
     203,   241,   241,   203,   241,   203,   230,   203,   203,   203,
     203,   203,   203,   203,   230,   241,   241,   241,   203,   230,
     231,   231,   233,   233,   364,   233,   233,   233,   233,   233,
     232,   358,   233,   233,   232,   425,   231,   233,   233,   344,
     233,   232,   348,   235,   231,   233,   233,   232,   278,   231,
     233,   233,   316,   233,   233,   233,   233,   233,   233,   233,
     232,   305,   231,   233,   233,   233,   232,   373,   203,   203,
     241,   229,   203,   229,   203,   203,   231,   230,   229,   203,
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
     231,   231,   231,   229,   203,   233,   229,   230,   229,   229,
     229,   231,   229,   229,   231,   229,   229,   233,   230,   351,
     352,   231,   248,   229,   229,   231,   229,   203,   233,   229,
     229,   229,   229,   203,   229,   229,   231,   229,   229,   229,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   229,   233,   231,   231,
       1,   118,   194,   218,   295,   296,   297,   298,   299,   229,
     229,   229,   229,   231,   231,   229,   233,   229,   231,   240,
     240,   240,   240,   240,   240,   240,   231,   231,   231,    64,
     139,   339,   340,   231,   231,   231,   231,   231,   231,   231,
     231,   231,    11,    12,    13,   242,   243,   231,   231,   231,
     231,   231,   231,   231,   231,   231,     8,   196,   415,   416,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,    15,    52,    84,   119,   120,   125,
     149,   202,   228,   365,   366,   231,   231,   231,   231,   231,
     231,   231,   231,   231,    20,    37,    60,   190,   196,   345,
     346,   217,   235,   350,   231,   231,   231,   231,     4,    27,
      28,    40,    80,    81,    83,   110,   114,   123,   144,   146,
     148,   165,   178,   180,   183,   185,   189,   192,   198,   200,
     201,   219,   227,   317,   318,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,    83,   148,   173,   178,
     183,   198,   200,   201,   219,   227,   398,   399,   231,   233,
     233,   300,   232,   296,   231,   231,   231,   231,   231,    83,
     148,   173,   178,   183,   198,   200,   201,   219,   227,   389,
     390,   231,   231,   235,   242,   242,   242,   231,   235,   231,
     235,   231,   235,   230,   352,   231,   234,   234,   234,   234,
     234,   234,   234,   231,   235,   231,   235,   229,   199,   243,
     233,   231,   231,   235,   340,   416,   366,   346,   145,   148,
     145,    94,   148,   145,   145,   318,   399,   231,   231,   231,
      81,    83,   130,   148,   177,   178,   221,   227,   301,   390,
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
     446,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   502,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   523,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   525,   526,
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
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
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
#line 3519 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 406 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3525 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 407 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3531 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 408 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3537 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 409 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3543 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 410 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3549 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 411 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3555 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 412 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3561 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 413 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3567 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 416 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3573 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 417 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3579 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 418 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3585 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 419 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3591 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 420 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3597 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 428 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3606 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 438 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3615 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 444 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3623 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 451 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3632 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 455 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3641 "conf_parser.c"
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
#line 3653 "conf_parser.c"
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
#line 3665 "conf_parser.c"
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
#line 3677 "conf_parser.c"
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
#line 3689 "conf_parser.c"
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
#line 3701 "conf_parser.c"
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
#line 3713 "conf_parser.c"
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
#line 3725 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 551 "conf_parser.y"
{
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && ConfigServerInfo.name == NULL)
  {
    if (server_is_valid_name(yylval.string))
      ConfigServerInfo.name = io_strdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3743 "conf_parser.c"
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
#line 3761 "conf_parser.c"
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
#line 3774 "conf_parser.c"
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
#line 3791 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 605 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3803 "conf_parser.c"
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
#line 3829 "conf_parser.c"
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
#line 3855 "conf_parser.c"
    break;

  case 88: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 660 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigServerInfo.max_topic_length = TOPICLEN;
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3866 "conf_parser.c"
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
#line 3878 "conf_parser.c"
    break;

  case 90: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 677 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3887 "conf_parser.c"
    break;

  case 98: /* admin_name: NAME '=' QSTRING ';'  */
#line 695 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3899 "conf_parser.c"
    break;

  case 99: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 704 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3911 "conf_parser.c"
    break;

  case 100: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 713 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3923 "conf_parser.c"
    break;

  case 101: /* $@1: %empty  */
#line 726 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3932 "conf_parser.c"
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
#line 3949 "conf_parser.c"
    break;

  case 108: /* motd_mask: MASK '=' QSTRING ';'  */
#line 747 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3958 "conf_parser.c"
    break;

  case 109: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 753 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3967 "conf_parser.c"
    break;

  case 110: /* $@2: %empty  */
#line 763 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3976 "conf_parser.c"
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
#line 3994 "conf_parser.c"
    break;

  case 119: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 785 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 4003 "conf_parser.c"
    break;

  case 120: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 791 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4012 "conf_parser.c"
    break;

  case 121: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 797 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 4021 "conf_parser.c"
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
#line 4043 "conf_parser.c"
    break;

  case 129: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 832 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 4055 "conf_parser.c"
    break;

  case 130: /* $@3: %empty  */
#line 841 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4064 "conf_parser.c"
    break;

  case 131: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 845 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 4077 "conf_parser.c"
    break;

  case 138: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 861 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 4088 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 869 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 4096 "conf_parser.c"
    break;

  case 140: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 872 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 4104 "conf_parser.c"
    break;

  case 141: /* $@4: %empty  */
#line 877 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 4113 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: USER  */
#line 883 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4122 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: OPERATOR  */
#line 887 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4131 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: XLINE  */
#line 891 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4140 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: RESV  */
#line 895 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4149 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: T_DLINE  */
#line 899 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4158 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KLINE  */
#line 903 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4167 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: KILL  */
#line 907 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4176 "conf_parser.c"
    break;

  case 150: /* logging_file_type_item: T_DEBUG  */
#line 911 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4185 "conf_parser.c"
    break;

  case 151: /* $@5: %empty  */
#line 921 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4197 "conf_parser.c"
    break;

  case 152: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 928 "conf_parser.y"
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

    oper_assign_class(oper, block_state.klass.buf);
  }
}
#line 4255 "conf_parser.c"
    break;

  case 166: /* oper_name: NAME '=' QSTRING ';'  */
#line 996 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4264 "conf_parser.c"
    break;

  case 167: /* oper_user: USER '=' QSTRING ';'  */
#line 1002 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4273 "conf_parser.c"
    break;

  case 168: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1008 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4282 "conf_parser.c"
    break;

  case 169: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1014 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4291 "conf_parser.c"
    break;

  case 170: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1020 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4305 "conf_parser.c"
    break;

  case 171: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1031 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4314 "conf_parser.c"
    break;

  case 172: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1037 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4328 "conf_parser.c"
    break;

  case 173: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4337 "conf_parser.c"
    break;

  case 174: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4346 "conf_parser.c"
    break;

  case 175: /* $@6: %empty  */
#line 1060 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4355 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: KILL ':' REMOTE  */
#line 1067 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4364 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: KILL  */
#line 1071 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4373 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1075 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4382 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: CONNECT  */
#line 1079 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4391 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1083 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4400 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: SQUIT  */
#line 1087 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4409 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: KLINE  */
#line 1091 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4418 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: UNKLINE  */
#line 1095 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4427 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_DLINE  */
#line 1099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4436 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: T_UNDLINE  */
#line 1103 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4445 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: XLINE  */
#line 1107 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4454 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: T_UNXLINE  */
#line 1111 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4463 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: DIE  */
#line 1115 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4472 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: T_RESTART  */
#line 1119 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4481 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1123 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4490 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: REHASH  */
#line 1127 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4499 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: ADMIN  */
#line 1131 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4508 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_GLOBOPS  */
#line 1135 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4517 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: T_LOCOPS  */
#line 1139 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4526 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: REMOTEBAN  */
#line 1143 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4535 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: T_SET  */
#line 1147 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4544 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: MODULE  */
#line 1151 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4553 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: T_OPME  */
#line 1155 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4562 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: NICK ':' RESV  */
#line 1159 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4571 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: JOIN ':' RESV  */
#line 1163 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4580 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: RESV  */
#line 1167 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4589 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: T_UNRESV  */
#line 1171 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4598 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: CLOSE  */
#line 1175 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4607 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1179 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4616 "conf_parser.c"
    break;

  case 208: /* $@7: %empty  */
#line 1189 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4632 "conf_parser.c"
    break;

  case 209: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1200 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.klass.buf[0])
    break;

  struct ClassItem *klass = class_find(block_state.klass.buf, false);
  if (klass == NULL)
    klass = class_create();

  klass->active = true;
  io_free(klass->name);
  klass->name = io_strdup(block_state.klass.buf);
  klass->ping_freq = block_state.ping_freq.value;
  klass->max_perip_local = block_state.max_perip_local.value;
  klass->max_perip_global = block_state.max_perip_global.value;
  klass->con_freq = block_state.con_freq.value;
  klass->max_total = block_state.max_total.value;
  klass->max_sendq = block_state.max_sendq.value;
  klass->max_recvq = block_state.max_recvq.value;
  klass->max_channels = block_state.max_channels.value;

  if (block_state.min_idle.value > block_state.max_idle.value)
  {
    block_state.min_idle.value = 0;
    block_state.max_idle.value = 0;
    block_state.flags.value &= ~CLASS_FLAGS_FAKE_IDLE;
  }

  klass->flags = block_state.flags.value;
  klass->min_idle = block_state.min_idle.value;
  klass->max_idle = block_state.max_idle.value;

  bool diff = (klass->cidr_bitlen_ipv4 != block_state.cidr_bitlen_ipv4.value ||
               klass->cidr_bitlen_ipv6 != block_state.cidr_bitlen_ipv6.value);
  klass->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  klass->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  klass->number_per_cidr = block_state.number_per_cidr.value;

  if (diff)
    class_ip_limit_rebuild(klass);
}
#line 4680 "conf_parser.c"
    break;

  case 228: /* class_name: NAME '=' QSTRING ';'  */
#line 1263 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4689 "conf_parser.c"
    break;

  case 229: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1269 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4698 "conf_parser.c"
    break;

  case 230: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1275 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4707 "conf_parser.c"
    break;

  case 231: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1281 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4716 "conf_parser.c"
    break;

  case 232: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1287 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4725 "conf_parser.c"
    break;

  case 233: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1293 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4734 "conf_parser.c"
    break;

  case 234: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1299 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4743 "conf_parser.c"
    break;

  case 235: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1305 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4752 "conf_parser.c"
    break;

  case 236: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1311 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4762 "conf_parser.c"
    break;

  case 237: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1318 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4771 "conf_parser.c"
    break;

  case 238: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1324 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4780 "conf_parser.c"
    break;

  case 239: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1330 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4789 "conf_parser.c"
    break;

  case 240: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1336 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4801 "conf_parser.c"
    break;

  case 241: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1345 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4813 "conf_parser.c"
    break;

  case 242: /* $@8: %empty  */
#line 1354 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4822 "conf_parser.c"
    break;

  case 246: /* class_flags_item: RANDOM_IDLE  */
#line 1361 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4831 "conf_parser.c"
    break;

  case 247: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1365 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4840 "conf_parser.c"
    break;

  case 248: /* $@9: %empty  */
#line 1375 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4849 "conf_parser.c"
    break;

  case 250: /* $@10: %empty  */
#line 1381 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4857 "conf_parser.c"
    break;

  case 254: /* listen_flags_item: T_TLS  */
#line 1387 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4866 "conf_parser.c"
    break;

  case 255: /* listen_flags_item: HIDDEN  */
#line 1391 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4875 "conf_parser.c"
    break;

  case 256: /* listen_flags_item: T_SERVER  */
#line 1395 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4884 "conf_parser.c"
    break;

  case 257: /* listen_flags_item: CLIENT  */
#line 1399 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4893 "conf_parser.c"
    break;

  case 258: /* listen_flags_item: DEFER  */
#line 1403 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4902 "conf_parser.c"
    break;

  case 266: /* $@11: %empty  */
#line 1411 "conf_parser.y"
                                 { reset_block_state(); }
#line 4908 "conf_parser.c"
    break;

  case 270: /* port_item: NUMBER  */
#line 1416 "conf_parser.y"
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
#line 4926 "conf_parser.c"
    break;

  case 271: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1429 "conf_parser.y"
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
#line 4946 "conf_parser.c"
    break;

  case 272: /* listen_address: IP '=' QSTRING ';'  */
#line 1446 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4955 "conf_parser.c"
    break;

  case 273: /* listen_host: HOST '=' QSTRING ';'  */
#line 1452 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4964 "conf_parser.c"
    break;

  case 274: /* $@12: %empty  */
#line 1462 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4973 "conf_parser.c"
    break;

  case 275: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1466 "conf_parser.y"
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

    conf_assign_class(conf, block_state.klass.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
#line 5020 "conf_parser.c"
    break;

  case 287: /* auth_user: USER '=' QSTRING ';'  */
#line 1521 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5029 "conf_parser.c"
    break;

  case 288: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1527 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5038 "conf_parser.c"
    break;

  case 289: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1533 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5047 "conf_parser.c"
    break;

  case 290: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1539 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5061 "conf_parser.c"
    break;

  case 291: /* $@13: %empty  */
#line 1550 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 5070 "conf_parser.c"
    break;

  case 295: /* auth_flags_item: EXCEED_LIMIT  */
#line 1557 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 5079 "conf_parser.c"
    break;

  case 296: /* auth_flags_item: KLINE_EXEMPT  */
#line 1561 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 5088 "conf_parser.c"
    break;

  case 297: /* auth_flags_item: XLINE_EXEMPT  */
#line 1565 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 5097 "conf_parser.c"
    break;

  case 298: /* auth_flags_item: NEED_IDENT  */
#line 1569 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 5106 "conf_parser.c"
    break;

  case 299: /* auth_flags_item: CAN_FLOOD  */
#line 1573 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 5115 "conf_parser.c"
    break;

  case 300: /* auth_flags_item: NO_TILDE  */
#line 1577 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 5124 "conf_parser.c"
    break;

  case 301: /* auth_flags_item: RESV_EXEMPT  */
#line 1581 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 5133 "conf_parser.c"
    break;

  case 302: /* auth_flags_item: T_WEBIRC  */
#line 1585 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 5142 "conf_parser.c"
    break;

  case 303: /* auth_flags_item: NEED_PASSWORD  */
#line 1589 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 5151 "conf_parser.c"
    break;

  case 304: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1595 "conf_parser.y"
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
#line 5168 "conf_parser.c"
    break;

  case 305: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1609 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 5180 "conf_parser.c"
    break;

  case 306: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1618 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 5192 "conf_parser.c"
    break;

  case 307: /* $@14: %empty  */
#line 1631 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5204 "conf_parser.c"
    break;

  case 308: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1638 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5215 "conf_parser.c"
    break;

  case 315: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1649 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5224 "conf_parser.c"
    break;

  case 316: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1655 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5233 "conf_parser.c"
    break;

  case 317: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1661 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5242 "conf_parser.c"
    break;

  case 323: /* service_name: NAME '=' QSTRING ';'  */
#line 1676 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5257 "conf_parser.c"
    break;

  case 324: /* $@15: %empty  */
#line 1692 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5273 "conf_parser.c"
    break;

  case 325: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1703 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5288 "conf_parser.c"
    break;

  case 332: /* shared_name: NAME '=' QSTRING ';'  */
#line 1718 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5297 "conf_parser.c"
    break;

  case 333: /* shared_user: USER '=' QSTRING ';'  */
#line 1724 "conf_parser.y"
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
#line 5319 "conf_parser.c"
    break;

  case 334: /* $@16: %empty  */
#line 1743 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5328 "conf_parser.c"
    break;

  case 338: /* shared_type_item: KLINE  */
#line 1750 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5337 "conf_parser.c"
    break;

  case 339: /* shared_type_item: UNKLINE  */
#line 1754 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5346 "conf_parser.c"
    break;

  case 340: /* shared_type_item: T_DLINE  */
#line 1758 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5355 "conf_parser.c"
    break;

  case 341: /* shared_type_item: T_UNDLINE  */
#line 1762 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5364 "conf_parser.c"
    break;

  case 342: /* shared_type_item: XLINE  */
#line 1766 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5373 "conf_parser.c"
    break;

  case 343: /* shared_type_item: T_UNXLINE  */
#line 1770 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5382 "conf_parser.c"
    break;

  case 344: /* shared_type_item: RESV  */
#line 1774 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5391 "conf_parser.c"
    break;

  case 345: /* shared_type_item: T_UNRESV  */
#line 1778 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5400 "conf_parser.c"
    break;

  case 346: /* shared_type_item: T_LOCOPS  */
#line 1782 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5409 "conf_parser.c"
    break;

  case 347: /* shared_type_item: T_ALL  */
#line 1786 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5418 "conf_parser.c"
    break;

  case 348: /* $@17: %empty  */
#line 1796 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5432 "conf_parser.c"
    break;

  case 349: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1805 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5445 "conf_parser.c"
    break;

  case 355: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1818 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5454 "conf_parser.c"
    break;

  case 356: /* $@18: %empty  */
#line 1824 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5463 "conf_parser.c"
    break;

  case 360: /* cluster_type_item: KLINE  */
#line 1831 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5472 "conf_parser.c"
    break;

  case 361: /* cluster_type_item: UNKLINE  */
#line 1835 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5481 "conf_parser.c"
    break;

  case 362: /* cluster_type_item: T_DLINE  */
#line 1839 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5490 "conf_parser.c"
    break;

  case 363: /* cluster_type_item: T_UNDLINE  */
#line 1843 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5499 "conf_parser.c"
    break;

  case 364: /* cluster_type_item: XLINE  */
#line 1847 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5508 "conf_parser.c"
    break;

  case 365: /* cluster_type_item: T_UNXLINE  */
#line 1851 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5517 "conf_parser.c"
    break;

  case 366: /* cluster_type_item: RESV  */
#line 1855 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5526 "conf_parser.c"
    break;

  case 367: /* cluster_type_item: T_UNRESV  */
#line 1859 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5535 "conf_parser.c"
    break;

  case 368: /* cluster_type_item: T_LOCOPS  */
#line 1863 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5544 "conf_parser.c"
    break;

  case 369: /* cluster_type_item: T_ALL  */
#line 1867 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5553 "conf_parser.c"
    break;

  case 370: /* $@19: %empty  */
#line 1877 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5567 "conf_parser.c"
    break;

  case 371: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1886 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0] ||
      !block_state.host.buf[0])
    break;

  if (!block_state.rpass.buf[0] ||
      !block_state.spass.buf[0])
    break;

  if (server_is_valid_name(block_state.name.buf) == false)
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

  list_concat(&connect->hub_masks, &block_state.hub.list);
  list_concat(&connect->leaf_masks, &block_state.leaf.list);

  if (block_state.bind.buf[0])
    if (address_from_string(block_state.bind.buf, &connect->bind_addr) == false)
      conf_error_report("Invalid IP address for bind address");

  connect_assign_class(connect, block_state.klass.buf);
  connect_dns_lookup(connect);
}
#line 5618 "conf_parser.c"
    break;

  case 390: /* connect_name: NAME '=' QSTRING ';'  */
#line 1952 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5627 "conf_parser.c"
    break;

  case 391: /* connect_host: HOST '=' QSTRING ';'  */
#line 1958 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5636 "conf_parser.c"
    break;

  case 392: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1964 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5645 "conf_parser.c"
    break;

  case 393: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1970 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5654 "conf_parser.c"
    break;

  case 394: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1976 "conf_parser.y"
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
#line 5670 "conf_parser.c"
    break;

  case 395: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1989 "conf_parser.y"
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
#line 5686 "conf_parser.c"
    break;

  case 396: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2002 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5695 "conf_parser.c"
    break;

  case 397: /* connect_port: PORT '=' NUMBER ';'  */
#line 2008 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5704 "conf_parser.c"
    break;

  case 398: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2014 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5713 "conf_parser.c"
    break;

  case 399: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2018 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5722 "conf_parser.c"
    break;

  case 400: /* $@20: %empty  */
#line 2024 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5730 "conf_parser.c"
    break;

  case 404: /* connect_flags_item: AUTOCONN  */
#line 2030 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5739 "conf_parser.c"
    break;

  case 405: /* connect_flags_item: T_TLS  */
#line 2034 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5748 "conf_parser.c"
    break;

  case 406: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2040 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5762 "conf_parser.c"
    break;

  case 407: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2051 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5771 "conf_parser.c"
    break;

  case 408: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2057 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5780 "conf_parser.c"
    break;

  case 409: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2063 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5789 "conf_parser.c"
    break;

  case 410: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2069 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5803 "conf_parser.c"
    break;

  case 411: /* $@21: %empty  */
#line 2084 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5812 "conf_parser.c"
    break;

  case 412: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2088 "conf_parser.y"
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
#line 5835 "conf_parser.c"
    break;

  case 418: /* kill_user: USER '=' QSTRING ';'  */
#line 2111 "conf_parser.y"
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
#line 5858 "conf_parser.c"
    break;

  case 419: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2131 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5867 "conf_parser.c"
    break;

  case 420: /* $@22: %empty  */
#line 2141 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5876 "conf_parser.c"
    break;

  case 421: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2145 "conf_parser.y"
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
#line 5900 "conf_parser.c"
    break;

  case 427: /* deny_ip: IP '=' QSTRING ';'  */
#line 2169 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5909 "conf_parser.c"
    break;

  case 428: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2175 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5918 "conf_parser.c"
    break;

  case 434: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2190 "conf_parser.y"
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
#line 5935 "conf_parser.c"
    break;

  case 435: /* $@23: %empty  */
#line 2207 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5944 "conf_parser.c"
    break;

  case 436: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2211 "conf_parser.y"
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
#line 5964 "conf_parser.c"
    break;

  case 442: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2231 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5973 "conf_parser.c"
    break;

  case 443: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2237 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5982 "conf_parser.c"
    break;

  case 502: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2307 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5990 "conf_parser.c"
    break;

  case 503: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2312 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5998 "conf_parser.c"
    break;

  case 504: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2317 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 6006 "conf_parser.c"
    break;

  case 505: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2322 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 6014 "conf_parser.c"
    break;

  case 506: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2327 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 6022 "conf_parser.c"
    break;

  case 507: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2332 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 6030 "conf_parser.c"
    break;

  case 508: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2337 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 6038 "conf_parser.c"
    break;

  case 509: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2342 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6046 "conf_parser.c"
    break;

  case 510: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2347 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6054 "conf_parser.c"
    break;

  case 511: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2352 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6062 "conf_parser.c"
    break;

  case 512: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2357 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 6070 "conf_parser.c"
    break;

  case 513: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2362 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 6078 "conf_parser.c"
    break;

  case 514: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2367 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6086 "conf_parser.c"
    break;

  case 515: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2372 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6094 "conf_parser.c"
    break;

  case 516: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2377 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6102 "conf_parser.c"
    break;

  case 517: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2382 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 6113 "conf_parser.c"
    break;

  case 518: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2390 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6121 "conf_parser.c"
    break;

  case 519: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2395 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6129 "conf_parser.c"
    break;

  case 520: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2400 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6137 "conf_parser.c"
    break;

  case 521: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2405 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6145 "conf_parser.c"
    break;

  case 522: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2410 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6153 "conf_parser.c"
    break;

  case 523: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2415 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6161 "conf_parser.c"
    break;

  case 524: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2420 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 6169 "conf_parser.c"
    break;

  case 525: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2425 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 6177 "conf_parser.c"
    break;

  case 526: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2430 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 6185 "conf_parser.c"
    break;

  case 527: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2435 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6193 "conf_parser.c"
    break;

  case 528: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2440 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 6201 "conf_parser.c"
    break;

  case 529: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2445 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 6209 "conf_parser.c"
    break;

  case 530: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2450 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6217 "conf_parser.c"
    break;

  case 531: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2455 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6225 "conf_parser.c"
    break;

  case 532: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2460 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6233 "conf_parser.c"
    break;

  case 533: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2465 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6241 "conf_parser.c"
    break;

  case 534: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2470 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6249 "conf_parser.c"
    break;

  case 535: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2475 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6257 "conf_parser.c"
    break;

  case 536: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2480 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6265 "conf_parser.c"
    break;

  case 537: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2485 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6273 "conf_parser.c"
    break;

  case 538: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2490 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6281 "conf_parser.c"
    break;

  case 539: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2495 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6289 "conf_parser.c"
    break;

  case 540: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2500 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6297 "conf_parser.c"
    break;

  case 541: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2505 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6305 "conf_parser.c"
    break;

  case 542: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2510 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6313 "conf_parser.c"
    break;

  case 543: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2515 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6325 "conf_parser.c"
    break;

  case 544: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2524 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6333 "conf_parser.c"
    break;

  case 545: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2529 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6341 "conf_parser.c"
    break;

  case 546: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2534 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6349 "conf_parser.c"
    break;

  case 547: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2539 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6357 "conf_parser.c"
    break;

  case 548: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2544 "conf_parser.y"
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
#line 6377 "conf_parser.c"
    break;

  case 549: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2561 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6388 "conf_parser.c"
    break;

  case 550: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2569 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6399 "conf_parser.c"
    break;

  case 551: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2577 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6410 "conf_parser.c"
    break;

  case 552: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2585 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6423 "conf_parser.c"
    break;

  case 553: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2595 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6436 "conf_parser.c"
    break;

  case 554: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2605 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6447 "conf_parser.c"
    break;

  case 555: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2613 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6455 "conf_parser.c"
    break;

  case 578: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2644 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6463 "conf_parser.c"
    break;

  case 579: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2649 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6472 "conf_parser.c"
    break;

  case 580: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2655 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6481 "conf_parser.c"
    break;

  case 581: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2661 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6489 "conf_parser.c"
    break;

  case 582: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2666 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6497 "conf_parser.c"
    break;

  case 583: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2671 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6505 "conf_parser.c"
    break;

  case 584: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2676 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6513 "conf_parser.c"
    break;

  case 585: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2681 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6521 "conf_parser.c"
    break;

  case 586: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2686 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6529 "conf_parser.c"
    break;

  case 587: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2691 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6537 "conf_parser.c"
    break;

  case 588: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2696 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6545 "conf_parser.c"
    break;

  case 589: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2701 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6553 "conf_parser.c"
    break;

  case 590: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2706 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6561 "conf_parser.c"
    break;

  case 591: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2711 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6569 "conf_parser.c"
    break;

  case 592: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2716 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6577 "conf_parser.c"
    break;

  case 593: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2721 "conf_parser.y"
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
#line 6603 "conf_parser.c"
    break;

  case 594: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2744 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6611 "conf_parser.c"
    break;

  case 595: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2749 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6619 "conf_parser.c"
    break;

  case 608: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2771 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6628 "conf_parser.c"
    break;

  case 609: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2777 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6642 "conf_parser.c"
    break;

  case 610: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2788 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6654 "conf_parser.c"
    break;

  case 611: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2797 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6663 "conf_parser.c"
    break;

  case 612: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2803 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6672 "conf_parser.c"
    break;

  case 613: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2809 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6681 "conf_parser.c"
    break;

  case 614: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2815 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6693 "conf_parser.c"
    break;

  case 615: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2824 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6702 "conf_parser.c"
    break;


#line 6706 "conf_parser.c"

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

