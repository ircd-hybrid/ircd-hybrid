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


#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "parse.h"
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
#include "hostmask.h"
#include "listener.h"
#include "user.h"
#include "motd.h"

int yylex(void);

static struct
{
  struct
  {
    dlink_list list;
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
  dlink_node *node, *node_next;
  dlink_list *tab[] = { &block_state.mask.list,
                        &block_state.leaf.list, &block_state.hub.list, NULL };

  for (dlink_list **list = tab; *list; ++list)
  {
    DLINK_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      xfree(node->data);
      dlinkDelete(node, *list);
      free_dlink_node(node);
    }
  }

  memset(&block_state, 0, sizeof(block_state));
}


#line 176 "conf_parser.c"

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
    CLOSE = 277,                   /* CLOSE  */
    CONNECT = 278,                 /* CONNECT  */
    CONNECTFREQ = 279,             /* CONNECTFREQ  */
    CYCLE_ON_HOST_CHANGE = 280,    /* CYCLE_ON_HOST_CHANGE  */
    DEFAULT_FLOODCOUNT = 281,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 282,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 283, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 284, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 285,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 286,                   /* DEFER  */
    DENY = 287,                    /* DENY  */
    DESCRIPTION = 288,             /* DESCRIPTION  */
    DIE = 289,                     /* DIE  */
    DISABLE_AUTH = 290,            /* DISABLE_AUTH  */
    DISABLE_FAKE_CHANNELS = 291,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 292, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 293,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 294,         /* DLINE_MIN_CIDR6  */
    EMAIL = 295,                   /* EMAIL  */
    ENABLE_ADMIN = 296,            /* ENABLE_ADMIN  */
    ENABLE_EXTBANS = 297,          /* ENABLE_EXTBANS  */
    ENABLE_OWNER = 298,            /* ENABLE_OWNER  */
    ENCRYPTED = 299,               /* ENCRYPTED  */
    EXCEED_LIMIT = 300,            /* EXCEED_LIMIT  */
    EXEMPT = 301,                  /* EXEMPT  */
    EXPIRATION = 302,              /* EXPIRATION  */
    FAILED_OPER_NOTICE = 303,      /* FAILED_OPER_NOTICE  */
    FLATTEN_LINKS = 304,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 305,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 306,      /* FLATTEN_LINKS_FILE  */
    GECOS = 307,                   /* GECOS  */
    GENERAL = 308,                 /* GENERAL  */
    HIDDEN = 309,                  /* HIDDEN  */
    HIDDEN_NAME = 310,             /* HIDDEN_NAME  */
    HIDE_CHANS = 311,              /* HIDE_CHANS  */
    HIDE_IDLE = 312,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 313,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVER_IPS = 314,         /* HIDE_SERVER_IPS  */
    HIDE_SERVERS = 315,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 316,           /* HIDE_SERVICES  */
    HOST = 317,                    /* HOST  */
    HUB = 318,                     /* HUB  */
    HUB_MASK = 319,                /* HUB_MASK  */
    INVISIBLE_ON_CONNECT = 320,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 321,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 322,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 323,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 324,      /* INVITE_EXPIRE_TIME  */
    IP = 325,                      /* IP  */
    IRCD_AUTH = 326,               /* IRCD_AUTH  */
    IRCD_FLAGS = 327,              /* IRCD_FLAGS  */
    IRCD_SID = 328,                /* IRCD_SID  */
    JOIN = 329,                    /* JOIN  */
    KILL = 330,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 331,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 332,                   /* KLINE  */
    KLINE_EXEMPT = 333,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 334,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 335,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 336,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 337,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 338,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 339,               /* LEAF_MASK  */
    LISTEN = 340,                  /* LISTEN  */
    MASK = 341,                    /* MASK  */
    MAX_ACCEPT = 342,              /* MAX_ACCEPT  */
    MAX_BANS = 343,                /* MAX_BANS  */
    MAX_BANS_LARGE = 344,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 345,            /* MAX_CHANNELS  */
    MAX_IDLE = 346,                /* MAX_IDLE  */
    MAX_INVITES = 347,             /* MAX_INVITES  */
    MAX_MONITOR = 348,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 349,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 350,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 351,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 352,              /* MAX_NUMBER  */
    MAX_TARGETS = 353,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 354,        /* MAX_TOPIC_LENGTH  */
    MIN_IDLE = 355,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 356,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 357,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 358,                  /* MODULE  */
    MODULES = 359,                 /* MODULES  */
    MOTD = 360,                    /* MOTD  */
    NAME = 361,                    /* NAME  */
    NEED_IDENT = 362,              /* NEED_IDENT  */
    NEED_PASSWORD = 363,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 364,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 365,            /* NETWORK_NAME  */
    NICK = 366,                    /* NICK  */
    NO_OPER_FLOOD = 367,           /* NO_OPER_FLOOD  */
    NO_TILDE = 368,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 369,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 370,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 371,     /* NUMBER_PER_IP_LOCAL  */
    OPER_ONLY_UMODES = 372,        /* OPER_ONLY_UMODES  */
    OPER_UMODES = 373,             /* OPER_UMODES  */
    OPERATOR = 374,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 375,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 376,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 377,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 378,                /* PASSWORD  */
    PATH = 379,                    /* PATH  */
    PING_COOKIE = 380,             /* PING_COOKIE  */
    PING_TIME = 381,               /* PING_TIME  */
    PORT = 382,                    /* PORT  */
    RANDOM_IDLE = 383,             /* RANDOM_IDLE  */
    REASON = 384,                  /* REASON  */
    REDIRPORT = 385,               /* REDIRPORT  */
    REDIRSERV = 386,               /* REDIRSERV  */
    REHASH = 387,                  /* REHASH  */
    REMOTE = 388,                  /* REMOTE  */
    REMOTEBAN = 389,               /* REMOTEBAN  */
    RESV = 390,                    /* RESV  */
    RESV_EXEMPT = 391,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 392,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 393,                 /* SECONDS  */
    MINUTES = 394,                 /* MINUTES  */
    HOURS = 395,                   /* HOURS  */
    DAYS = 396,                    /* DAYS  */
    WEEKS = 397,                   /* WEEKS  */
    MONTHS = 398,                  /* MONTHS  */
    YEARS = 399,                   /* YEARS  */
    SEND_PASSWORD = 400,           /* SEND_PASSWORD  */
    SENDQ = 401,                   /* SENDQ  */
    SERVERHIDE = 402,              /* SERVERHIDE  */
    SERVERINFO = 403,              /* SERVERINFO  */
    SHORT_MOTD = 404,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 405,       /* SPECIALS_IN_IDENT  */
    SPOOF = 406,                   /* SPOOF  */
    SQUIT = 407,                   /* SQUIT  */
    STATS_E_DISABLED = 408,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 409,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 410,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 411,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 412,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 413,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 414,       /* STATS_U_OPER_ONLY  */
    T_ALL = 415,                   /* T_ALL  */
    T_BIND = 416,                  /* T_BIND  */
    T_CALLERID = 417,              /* T_CALLERID  */
    T_CCONN = 418,                 /* T_CCONN  */
    T_COMMAND = 419,               /* T_COMMAND  */
    T_CLUSTER = 420,               /* T_CLUSTER  */
    T_DEAF = 421,                  /* T_DEAF  */
    T_DEBUG = 422,                 /* T_DEBUG  */
    T_DLINE = 423,                 /* T_DLINE  */
    T_EXTERNAL = 424,              /* T_EXTERNAL  */
    T_FARCONNECT = 425,            /* T_FARCONNECT  */
    T_FILE = 426,                  /* T_FILE  */
    T_FLOOD = 427,                 /* T_FLOOD  */
    T_GLOBOPS = 428,               /* T_GLOBOPS  */
    T_INVISIBLE = 429,             /* T_INVISIBLE  */
    T_IPV4 = 430,                  /* T_IPV4  */
    T_IPV6 = 431,                  /* T_IPV6  */
    T_LOCOPS = 432,                /* T_LOCOPS  */
    T_LOG = 433,                   /* T_LOG  */
    T_NCHANGE = 434,               /* T_NCHANGE  */
    T_NONONREG = 435,              /* T_NONONREG  */
    T_OPME = 436,                  /* T_OPME  */
    T_PREPEND = 437,               /* T_PREPEND  */
    T_PSEUDO = 438,                /* T_PSEUDO  */
    T_RECVQ = 439,                 /* T_RECVQ  */
    T_REJ = 440,                   /* T_REJ  */
    T_RESTART = 441,               /* T_RESTART  */
    T_SECUREONLY = 442,            /* T_SECUREONLY  */
    T_SERVER = 443,                /* T_SERVER  */
    T_SERVICE = 444,               /* T_SERVICE  */
    T_SERVNOTICE = 445,            /* T_SERVNOTICE  */
    T_SET = 446,                   /* T_SET  */
    T_SHARED = 447,                /* T_SHARED  */
    T_SIZE = 448,                  /* T_SIZE  */
    T_SKILL = 449,                 /* T_SKILL  */
    T_SOFTCALLERID = 450,          /* T_SOFTCALLERID  */
    T_SPY = 451,                   /* T_SPY  */
    T_TARGET = 452,                /* T_TARGET  */
    T_TLS = 453,                   /* T_TLS  */
    T_UMODES = 454,                /* T_UMODES  */
    T_UNDLINE = 455,               /* T_UNDLINE  */
    T_UNLIMITED = 456,             /* T_UNLIMITED  */
    T_UNRESV = 457,                /* T_UNRESV  */
    T_UNXLINE = 458,               /* T_UNXLINE  */
    T_WALLOP = 459,                /* T_WALLOP  */
    T_WALLOPS = 460,               /* T_WALLOPS  */
    T_WEBIRC = 461,                /* T_WEBIRC  */
    TBOOL = 462,                   /* TBOOL  */
    THROTTLE_COUNT = 463,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 464,           /* THROTTLE_TIME  */
    TIMEOUT = 465,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 466,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 467, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 468,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 469,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 470, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 471,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 472, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 473,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 474,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 475,           /* TS_WARN_DELTA  */
    TWODOTS = 476,                 /* TWODOTS  */
    TYPE = 477,                    /* TYPE  */
    UNKLINE = 478,                 /* UNKLINE  */
    USE_LOGGING = 479,             /* USE_LOGGING  */
    USER = 480,                    /* USER  */
    VHOST = 481,                   /* VHOST  */
    VHOST6 = 482,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 483,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 484,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 485,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 486,                   /* XLINE  */
    XLINE_EXEMPT = 487,            /* XLINE_EXEMPT  */
    QSTRING = 488,                 /* QSTRING  */
    NUMBER = 489                   /* NUMBER  */
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
#define CLOSE 277
#define CONNECT 278
#define CONNECTFREQ 279
#define CYCLE_ON_HOST_CHANGE 280
#define DEFAULT_FLOODCOUNT 281
#define DEFAULT_FLOODTIME 282
#define DEFAULT_JOIN_FLOOD_COUNT 283
#define DEFAULT_JOIN_FLOOD_TIME 284
#define DEFAULT_MAX_CLIENTS 285
#define DEFER 286
#define DENY 287
#define DESCRIPTION 288
#define DIE 289
#define DISABLE_AUTH 290
#define DISABLE_FAKE_CHANNELS 291
#define DISABLE_REMOTE_COMMANDS 292
#define DLINE_MIN_CIDR 293
#define DLINE_MIN_CIDR6 294
#define EMAIL 295
#define ENABLE_ADMIN 296
#define ENABLE_EXTBANS 297
#define ENABLE_OWNER 298
#define ENCRYPTED 299
#define EXCEED_LIMIT 300
#define EXEMPT 301
#define EXPIRATION 302
#define FAILED_OPER_NOTICE 303
#define FLATTEN_LINKS 304
#define FLATTEN_LINKS_DELAY 305
#define FLATTEN_LINKS_FILE 306
#define GECOS 307
#define GENERAL 308
#define HIDDEN 309
#define HIDDEN_NAME 310
#define HIDE_CHANS 311
#define HIDE_IDLE 312
#define HIDE_IDLE_FROM_OPERS 313
#define HIDE_SERVER_IPS 314
#define HIDE_SERVERS 315
#define HIDE_SERVICES 316
#define HOST 317
#define HUB 318
#define HUB_MASK 319
#define INVISIBLE_ON_CONNECT 320
#define INVITE_CLIENT_COUNT 321
#define INVITE_CLIENT_TIME 322
#define INVITE_DELAY_CHANNEL 323
#define INVITE_EXPIRE_TIME 324
#define IP 325
#define IRCD_AUTH 326
#define IRCD_FLAGS 327
#define IRCD_SID 328
#define JOIN 329
#define KILL 330
#define KILL_CHASE_TIME_LIMIT 331
#define KLINE 332
#define KLINE_EXEMPT 333
#define KLINE_MIN_CIDR 334
#define KLINE_MIN_CIDR6 335
#define KNOCK_CLIENT_COUNT 336
#define KNOCK_CLIENT_TIME 337
#define KNOCK_DELAY_CHANNEL 338
#define LEAF_MASK 339
#define LISTEN 340
#define MASK 341
#define MAX_ACCEPT 342
#define MAX_BANS 343
#define MAX_BANS_LARGE 344
#define MAX_CHANNELS 345
#define MAX_IDLE 346
#define MAX_INVITES 347
#define MAX_MONITOR 348
#define MAX_NICK_CHANGES 349
#define MAX_NICK_LENGTH 350
#define MAX_NICK_TIME 351
#define MAX_NUMBER 352
#define MAX_TARGETS 353
#define MAX_TOPIC_LENGTH 354
#define MIN_IDLE 355
#define MIN_NONWILDCARD 356
#define MIN_NONWILDCARD_SIMPLE 357
#define MODULE 358
#define MODULES 359
#define MOTD 360
#define NAME 361
#define NEED_IDENT 362
#define NEED_PASSWORD 363
#define NETWORK_DESCRIPTION 364
#define NETWORK_NAME 365
#define NICK 366
#define NO_OPER_FLOOD 367
#define NO_TILDE 368
#define NUMBER_PER_CIDR 369
#define NUMBER_PER_IP_GLOBAL 370
#define NUMBER_PER_IP_LOCAL 371
#define OPER_ONLY_UMODES 372
#define OPER_UMODES 373
#define OPERATOR 374
#define OPERS_BYPASS_CALLERID 375
#define PACE_WAIT 376
#define PACE_WAIT_SIMPLE 377
#define PASSWORD 378
#define PATH 379
#define PING_COOKIE 380
#define PING_TIME 381
#define PORT 382
#define RANDOM_IDLE 383
#define REASON 384
#define REDIRPORT 385
#define REDIRSERV 386
#define REHASH 387
#define REMOTE 388
#define REMOTEBAN 389
#define RESV 390
#define RESV_EXEMPT 391
#define RSA_PRIVATE_KEY_FILE 392
#define SECONDS 393
#define MINUTES 394
#define HOURS 395
#define DAYS 396
#define WEEKS 397
#define MONTHS 398
#define YEARS 399
#define SEND_PASSWORD 400
#define SENDQ 401
#define SERVERHIDE 402
#define SERVERINFO 403
#define SHORT_MOTD 404
#define SPECIALS_IN_IDENT 405
#define SPOOF 406
#define SQUIT 407
#define STATS_E_DISABLED 408
#define STATS_I_OPER_ONLY 409
#define STATS_K_OPER_ONLY 410
#define STATS_M_OPER_ONLY 411
#define STATS_O_OPER_ONLY 412
#define STATS_P_OPER_ONLY 413
#define STATS_U_OPER_ONLY 414
#define T_ALL 415
#define T_BIND 416
#define T_CALLERID 417
#define T_CCONN 418
#define T_COMMAND 419
#define T_CLUSTER 420
#define T_DEAF 421
#define T_DEBUG 422
#define T_DLINE 423
#define T_EXTERNAL 424
#define T_FARCONNECT 425
#define T_FILE 426
#define T_FLOOD 427
#define T_GLOBOPS 428
#define T_INVISIBLE 429
#define T_IPV4 430
#define T_IPV6 431
#define T_LOCOPS 432
#define T_LOG 433
#define T_NCHANGE 434
#define T_NONONREG 435
#define T_OPME 436
#define T_PREPEND 437
#define T_PSEUDO 438
#define T_RECVQ 439
#define T_REJ 440
#define T_RESTART 441
#define T_SECUREONLY 442
#define T_SERVER 443
#define T_SERVICE 444
#define T_SERVNOTICE 445
#define T_SET 446
#define T_SHARED 447
#define T_SIZE 448
#define T_SKILL 449
#define T_SOFTCALLERID 450
#define T_SPY 451
#define T_TARGET 452
#define T_TLS 453
#define T_UMODES 454
#define T_UNDLINE 455
#define T_UNLIMITED 456
#define T_UNRESV 457
#define T_UNXLINE 458
#define T_WALLOP 459
#define T_WALLOPS 460
#define T_WEBIRC 461
#define TBOOL 462
#define THROTTLE_COUNT 463
#define THROTTLE_TIME 464
#define TIMEOUT 465
#define TLS_CERTIFICATE_FILE 466
#define TLS_CERTIFICATE_FINGERPRINT 467
#define TLS_CIPHER_LIST 468
#define TLS_CIPHER_SUITES 469
#define TLS_CONNECTION_REQUIRED 470
#define TLS_DH_PARAM_FILE 471
#define TLS_MESSAGE_DIGEST_ALGORITHM 472
#define TLS_SUPPORTED_GROUPS 473
#define TS_MAX_DELTA 474
#define TS_WARN_DELTA 475
#define TWODOTS 476
#define TYPE 477
#define UNKLINE 478
#define USE_LOGGING 479
#define USER 480
#define VHOST 481
#define VHOST6 482
#define WARN_NO_CONNECT_BLOCK 483
#define WHOIS 484
#define WHOWAS_HISTORY_LENGTH 485
#define XLINE 486
#define XLINE_EXEMPT 487
#define QSTRING 488
#define NUMBER 489

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 132 "conf_parser.y"

  int number;
  char *string;

#line 702 "conf_parser.c"

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
  YYSYMBOL_CLOSE = 22,                     /* CLOSE  */
  YYSYMBOL_CONNECT = 23,                   /* CONNECT  */
  YYSYMBOL_CONNECTFREQ = 24,               /* CONNECTFREQ  */
  YYSYMBOL_CYCLE_ON_HOST_CHANGE = 25,      /* CYCLE_ON_HOST_CHANGE  */
  YYSYMBOL_DEFAULT_FLOODCOUNT = 26,        /* DEFAULT_FLOODCOUNT  */
  YYSYMBOL_DEFAULT_FLOODTIME = 27,         /* DEFAULT_FLOODTIME  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_COUNT = 28,  /* DEFAULT_JOIN_FLOOD_COUNT  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_TIME = 29,   /* DEFAULT_JOIN_FLOOD_TIME  */
  YYSYMBOL_DEFAULT_MAX_CLIENTS = 30,       /* DEFAULT_MAX_CLIENTS  */
  YYSYMBOL_DEFER = 31,                     /* DEFER  */
  YYSYMBOL_DENY = 32,                      /* DENY  */
  YYSYMBOL_DESCRIPTION = 33,               /* DESCRIPTION  */
  YYSYMBOL_DIE = 34,                       /* DIE  */
  YYSYMBOL_DISABLE_AUTH = 35,              /* DISABLE_AUTH  */
  YYSYMBOL_DISABLE_FAKE_CHANNELS = 36,     /* DISABLE_FAKE_CHANNELS  */
  YYSYMBOL_DISABLE_REMOTE_COMMANDS = 37,   /* DISABLE_REMOTE_COMMANDS  */
  YYSYMBOL_DLINE_MIN_CIDR = 38,            /* DLINE_MIN_CIDR  */
  YYSYMBOL_DLINE_MIN_CIDR6 = 39,           /* DLINE_MIN_CIDR6  */
  YYSYMBOL_EMAIL = 40,                     /* EMAIL  */
  YYSYMBOL_ENABLE_ADMIN = 41,              /* ENABLE_ADMIN  */
  YYSYMBOL_ENABLE_EXTBANS = 42,            /* ENABLE_EXTBANS  */
  YYSYMBOL_ENABLE_OWNER = 43,              /* ENABLE_OWNER  */
  YYSYMBOL_ENCRYPTED = 44,                 /* ENCRYPTED  */
  YYSYMBOL_EXCEED_LIMIT = 45,              /* EXCEED_LIMIT  */
  YYSYMBOL_EXEMPT = 46,                    /* EXEMPT  */
  YYSYMBOL_EXPIRATION = 47,                /* EXPIRATION  */
  YYSYMBOL_FAILED_OPER_NOTICE = 48,        /* FAILED_OPER_NOTICE  */
  YYSYMBOL_FLATTEN_LINKS = 49,             /* FLATTEN_LINKS  */
  YYSYMBOL_FLATTEN_LINKS_DELAY = 50,       /* FLATTEN_LINKS_DELAY  */
  YYSYMBOL_FLATTEN_LINKS_FILE = 51,        /* FLATTEN_LINKS_FILE  */
  YYSYMBOL_GECOS = 52,                     /* GECOS  */
  YYSYMBOL_GENERAL = 53,                   /* GENERAL  */
  YYSYMBOL_HIDDEN = 54,                    /* HIDDEN  */
  YYSYMBOL_HIDDEN_NAME = 55,               /* HIDDEN_NAME  */
  YYSYMBOL_HIDE_CHANS = 56,                /* HIDE_CHANS  */
  YYSYMBOL_HIDE_IDLE = 57,                 /* HIDE_IDLE  */
  YYSYMBOL_HIDE_IDLE_FROM_OPERS = 58,      /* HIDE_IDLE_FROM_OPERS  */
  YYSYMBOL_HIDE_SERVER_IPS = 59,           /* HIDE_SERVER_IPS  */
  YYSYMBOL_HIDE_SERVERS = 60,              /* HIDE_SERVERS  */
  YYSYMBOL_HIDE_SERVICES = 61,             /* HIDE_SERVICES  */
  YYSYMBOL_HOST = 62,                      /* HOST  */
  YYSYMBOL_HUB = 63,                       /* HUB  */
  YYSYMBOL_HUB_MASK = 64,                  /* HUB_MASK  */
  YYSYMBOL_INVISIBLE_ON_CONNECT = 65,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 66,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 67,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 68,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 69,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 70,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 71,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 72,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 73,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 74,                      /* JOIN  */
  YYSYMBOL_KILL = 75,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 76,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 77,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 78,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 79,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 80,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 81,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 82,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 83,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 84,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 85,                    /* LISTEN  */
  YYSYMBOL_MASK = 86,                      /* MASK  */
  YYSYMBOL_MAX_ACCEPT = 87,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_BANS = 88,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 89,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 90,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 91,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 92,               /* MAX_INVITES  */
  YYSYMBOL_MAX_MONITOR = 93,               /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 94,          /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 95,           /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 96,             /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 97,                /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 98,               /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 99,          /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MIN_IDLE = 100,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 101,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 102,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 103,                   /* MODULE  */
  YYSYMBOL_MODULES = 104,                  /* MODULES  */
  YYSYMBOL_MOTD = 105,                     /* MOTD  */
  YYSYMBOL_NAME = 106,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 107,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 108,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 109,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 110,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 111,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 112,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 113,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 114,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 115,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 116,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_ONLY_UMODES = 117,         /* OPER_ONLY_UMODES  */
  YYSYMBOL_OPER_UMODES = 118,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 119,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 120,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 121,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 122,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 123,                 /* PASSWORD  */
  YYSYMBOL_PATH = 124,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 125,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 126,                /* PING_TIME  */
  YYSYMBOL_PORT = 127,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 128,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 129,                   /* REASON  */
  YYSYMBOL_REDIRPORT = 130,                /* REDIRPORT  */
  YYSYMBOL_REDIRSERV = 131,                /* REDIRSERV  */
  YYSYMBOL_REHASH = 132,                   /* REHASH  */
  YYSYMBOL_REMOTE = 133,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 134,                /* REMOTEBAN  */
  YYSYMBOL_RESV = 135,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 136,              /* RESV_EXEMPT  */
  YYSYMBOL_RSA_PRIVATE_KEY_FILE = 137,     /* RSA_PRIVATE_KEY_FILE  */
  YYSYMBOL_SECONDS = 138,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 139,                  /* MINUTES  */
  YYSYMBOL_HOURS = 140,                    /* HOURS  */
  YYSYMBOL_DAYS = 141,                     /* DAYS  */
  YYSYMBOL_WEEKS = 142,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 143,                   /* MONTHS  */
  YYSYMBOL_YEARS = 144,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 145,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 146,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 147,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 148,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 149,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 150,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 151,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 152,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 153,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_I_OPER_ONLY = 154,        /* STATS_I_OPER_ONLY  */
  YYSYMBOL_STATS_K_OPER_ONLY = 155,        /* STATS_K_OPER_ONLY  */
  YYSYMBOL_STATS_M_OPER_ONLY = 156,        /* STATS_M_OPER_ONLY  */
  YYSYMBOL_STATS_O_OPER_ONLY = 157,        /* STATS_O_OPER_ONLY  */
  YYSYMBOL_STATS_P_OPER_ONLY = 158,        /* STATS_P_OPER_ONLY  */
  YYSYMBOL_STATS_U_OPER_ONLY = 159,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 160,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 161,                   /* T_BIND  */
  YYSYMBOL_T_CALLERID = 162,               /* T_CALLERID  */
  YYSYMBOL_T_CCONN = 163,                  /* T_CCONN  */
  YYSYMBOL_T_COMMAND = 164,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 165,                /* T_CLUSTER  */
  YYSYMBOL_T_DEAF = 166,                   /* T_DEAF  */
  YYSYMBOL_T_DEBUG = 167,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 168,                  /* T_DLINE  */
  YYSYMBOL_T_EXTERNAL = 169,               /* T_EXTERNAL  */
  YYSYMBOL_T_FARCONNECT = 170,             /* T_FARCONNECT  */
  YYSYMBOL_T_FILE = 171,                   /* T_FILE  */
  YYSYMBOL_T_FLOOD = 172,                  /* T_FLOOD  */
  YYSYMBOL_T_GLOBOPS = 173,                /* T_GLOBOPS  */
  YYSYMBOL_T_INVISIBLE = 174,              /* T_INVISIBLE  */
  YYSYMBOL_T_IPV4 = 175,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 176,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 177,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 178,                    /* T_LOG  */
  YYSYMBOL_T_NCHANGE = 179,                /* T_NCHANGE  */
  YYSYMBOL_T_NONONREG = 180,               /* T_NONONREG  */
  YYSYMBOL_T_OPME = 181,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 182,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 183,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 184,                  /* T_RECVQ  */
  YYSYMBOL_T_REJ = 185,                    /* T_REJ  */
  YYSYMBOL_T_RESTART = 186,                /* T_RESTART  */
  YYSYMBOL_T_SECUREONLY = 187,             /* T_SECUREONLY  */
  YYSYMBOL_T_SERVER = 188,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 189,                /* T_SERVICE  */
  YYSYMBOL_T_SERVNOTICE = 190,             /* T_SERVNOTICE  */
  YYSYMBOL_T_SET = 191,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 192,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 193,                   /* T_SIZE  */
  YYSYMBOL_T_SKILL = 194,                  /* T_SKILL  */
  YYSYMBOL_T_SOFTCALLERID = 195,           /* T_SOFTCALLERID  */
  YYSYMBOL_T_SPY = 196,                    /* T_SPY  */
  YYSYMBOL_T_TARGET = 197,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 198,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 199,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 200,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 201,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 202,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 203,                /* T_UNXLINE  */
  YYSYMBOL_T_WALLOP = 204,                 /* T_WALLOP  */
  YYSYMBOL_T_WALLOPS = 205,                /* T_WALLOPS  */
  YYSYMBOL_T_WEBIRC = 206,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 207,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 208,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 209,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 210,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 211,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 212, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 213,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 214,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 215,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 216,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 217, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 218,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 219,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 220,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 221,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 222,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 223,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 224,              /* USE_LOGGING  */
  YYSYMBOL_USER = 225,                     /* USER  */
  YYSYMBOL_VHOST = 226,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 227,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 228,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 229,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 230,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 231,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 232,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 233,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 234,                   /* NUMBER  */
  YYSYMBOL_235_ = 235,                     /* ';'  */
  YYSYMBOL_236_ = 236,                     /* '}'  */
  YYSYMBOL_237_ = 237,                     /* '{'  */
  YYSYMBOL_238_ = 238,                     /* '='  */
  YYSYMBOL_239_ = 239,                     /* ','  */
  YYSYMBOL_240_ = 240,                     /* ':'  */
  YYSYMBOL_YYACCEPT = 241,                 /* $accept  */
  YYSYMBOL_conf = 242,                     /* conf  */
  YYSYMBOL_conf_item = 243,                /* conf_item  */
  YYSYMBOL_timespec_ = 244,                /* timespec_  */
  YYSYMBOL_timespec = 245,                 /* timespec  */
  YYSYMBOL_sizespec_ = 246,                /* sizespec_  */
  YYSYMBOL_sizespec = 247,                 /* sizespec  */
  YYSYMBOL_modules_entry = 248,            /* modules_entry  */
  YYSYMBOL_modules_items = 249,            /* modules_items  */
  YYSYMBOL_modules_item = 250,             /* modules_item  */
  YYSYMBOL_modules_module = 251,           /* modules_module  */
  YYSYMBOL_modules_path = 252,             /* modules_path  */
  YYSYMBOL_serverinfo_entry = 253,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 254,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 255,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 256, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 257, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 258, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 259, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 260, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 261, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 262, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 263,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 264,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 265,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 266,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 267, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 268, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 269, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 270, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_hub = 271,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 272,              /* admin_entry  */
  YYSYMBOL_admin_items = 273,              /* admin_items  */
  YYSYMBOL_admin_item = 274,               /* admin_item  */
  YYSYMBOL_admin_name = 275,               /* admin_name  */
  YYSYMBOL_admin_email = 276,              /* admin_email  */
  YYSYMBOL_admin_description = 277,        /* admin_description  */
  YYSYMBOL_motd_entry = 278,               /* motd_entry  */
  YYSYMBOL_279_1 = 279,                    /* $@1  */
  YYSYMBOL_motd_items = 280,               /* motd_items  */
  YYSYMBOL_motd_item = 281,                /* motd_item  */
  YYSYMBOL_motd_mask = 282,                /* motd_mask  */
  YYSYMBOL_motd_file = 283,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 284,             /* pseudo_entry  */
  YYSYMBOL_285_2 = 285,                    /* $@2  */
  YYSYMBOL_pseudo_items = 286,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 287,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 288,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 289,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 290,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 291,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 292,            /* logging_entry  */
  YYSYMBOL_logging_items = 293,            /* logging_items  */
  YYSYMBOL_logging_item = 294,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 295,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 296,       /* logging_file_entry  */
  YYSYMBOL_297_3 = 297,                    /* $@3  */
  YYSYMBOL_logging_file_items = 298,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 299,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 300,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 301,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 302,        /* logging_file_type  */
  YYSYMBOL_303_4 = 303,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 304,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 305,               /* oper_entry  */
  YYSYMBOL_306_5 = 306,                    /* $@5  */
  YYSYMBOL_oper_items = 307,               /* oper_items  */
  YYSYMBOL_oper_item = 308,                /* oper_item  */
  YYSYMBOL_oper_name = 309,                /* oper_name  */
  YYSYMBOL_oper_user = 310,                /* oper_user  */
  YYSYMBOL_oper_password = 311,            /* oper_password  */
  YYSYMBOL_oper_whois = 312,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 313,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 314, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 315, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 316,               /* oper_class  */
  YYSYMBOL_oper_umodes = 317,              /* oper_umodes  */
  YYSYMBOL_318_6 = 318,                    /* $@6  */
  YYSYMBOL_oper_umodes_items = 319,        /* oper_umodes_items  */
  YYSYMBOL_oper_umodes_item = 320,         /* oper_umodes_item  */
  YYSYMBOL_oper_flags = 321,               /* oper_flags  */
  YYSYMBOL_322_7 = 322,                    /* $@7  */
  YYSYMBOL_oper_flags_items = 323,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 324,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 325,              /* class_entry  */
  YYSYMBOL_326_8 = 326,                    /* $@8  */
  YYSYMBOL_class_items = 327,              /* class_items  */
  YYSYMBOL_class_item = 328,               /* class_item  */
  YYSYMBOL_class_name = 329,               /* class_name  */
  YYSYMBOL_class_ping_time = 330,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 331, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 332, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 333,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 334,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 335,         /* class_max_number  */
  YYSYMBOL_class_sendq = 336,              /* class_sendq  */
  YYSYMBOL_class_recvq = 337,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 338,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 339,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 340,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 341,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 342,           /* class_max_idle  */
  YYSYMBOL_class_flags = 343,              /* class_flags  */
  YYSYMBOL_344_9 = 344,                    /* $@9  */
  YYSYMBOL_class_flags_items = 345,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 346,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 347,             /* listen_entry  */
  YYSYMBOL_348_10 = 348,                   /* $@10  */
  YYSYMBOL_listen_flags = 349,             /* listen_flags  */
  YYSYMBOL_350_11 = 350,                   /* $@11  */
  YYSYMBOL_listen_flags_items = 351,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 352,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 353,             /* listen_items  */
  YYSYMBOL_listen_item = 354,              /* listen_item  */
  YYSYMBOL_listen_port = 355,              /* listen_port  */
  YYSYMBOL_356_12 = 356,                   /* $@12  */
  YYSYMBOL_port_items = 357,               /* port_items  */
  YYSYMBOL_port_item = 358,                /* port_item  */
  YYSYMBOL_listen_address = 359,           /* listen_address  */
  YYSYMBOL_listen_host = 360,              /* listen_host  */
  YYSYMBOL_auth_entry = 361,               /* auth_entry  */
  YYSYMBOL_362_13 = 362,                   /* $@13  */
  YYSYMBOL_auth_items = 363,               /* auth_items  */
  YYSYMBOL_auth_item = 364,                /* auth_item  */
  YYSYMBOL_auth_user = 365,                /* auth_user  */
  YYSYMBOL_auth_passwd = 366,              /* auth_passwd  */
  YYSYMBOL_auth_class = 367,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 368,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 369,               /* auth_flags  */
  YYSYMBOL_370_14 = 370,                   /* $@14  */
  YYSYMBOL_auth_flags_items = 371,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 372,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 373,               /* auth_spoof  */
  YYSYMBOL_auth_redir_serv = 374,          /* auth_redir_serv  */
  YYSYMBOL_auth_redir_port = 375,          /* auth_redir_port  */
  YYSYMBOL_resv_entry = 376,               /* resv_entry  */
  YYSYMBOL_377_15 = 377,                   /* $@15  */
  YYSYMBOL_resv_items = 378,               /* resv_items  */
  YYSYMBOL_resv_item = 379,                /* resv_item  */
  YYSYMBOL_resv_mask = 380,                /* resv_mask  */
  YYSYMBOL_resv_reason = 381,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 382,              /* resv_exempt  */
  YYSYMBOL_service_entry = 383,            /* service_entry  */
  YYSYMBOL_service_items = 384,            /* service_items  */
  YYSYMBOL_service_item = 385,             /* service_item  */
  YYSYMBOL_service_name = 386,             /* service_name  */
  YYSYMBOL_shared_entry = 387,             /* shared_entry  */
  YYSYMBOL_388_16 = 388,                   /* $@16  */
  YYSYMBOL_shared_items = 389,             /* shared_items  */
  YYSYMBOL_shared_item = 390,              /* shared_item  */
  YYSYMBOL_shared_name = 391,              /* shared_name  */
  YYSYMBOL_shared_user = 392,              /* shared_user  */
  YYSYMBOL_shared_type = 393,              /* shared_type  */
  YYSYMBOL_394_17 = 394,                   /* $@17  */
  YYSYMBOL_shared_types = 395,             /* shared_types  */
  YYSYMBOL_shared_type_item = 396,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 397,            /* cluster_entry  */
  YYSYMBOL_398_18 = 398,                   /* $@18  */
  YYSYMBOL_cluster_items = 399,            /* cluster_items  */
  YYSYMBOL_cluster_item = 400,             /* cluster_item  */
  YYSYMBOL_cluster_name = 401,             /* cluster_name  */
  YYSYMBOL_cluster_type = 402,             /* cluster_type  */
  YYSYMBOL_403_19 = 403,                   /* $@19  */
  YYSYMBOL_cluster_types = 404,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 405,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 406,            /* connect_entry  */
  YYSYMBOL_407_20 = 407,                   /* $@20  */
  YYSYMBOL_connect_items = 408,            /* connect_items  */
  YYSYMBOL_connect_item = 409,             /* connect_item  */
  YYSYMBOL_connect_name = 410,             /* connect_name  */
  YYSYMBOL_connect_host = 411,             /* connect_host  */
  YYSYMBOL_connect_timeout = 412,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 413,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 414,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 415,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 416, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 417,             /* connect_port  */
  YYSYMBOL_connect_aftype = 418,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 419,            /* connect_flags  */
  YYSYMBOL_420_21 = 420,                   /* $@21  */
  YYSYMBOL_connect_flags_items = 421,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 422,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 423,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 424,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 425,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 426,            /* connect_class  */
  YYSYMBOL_connect_tls_cipher_list = 427,  /* connect_tls_cipher_list  */
  YYSYMBOL_kill_entry = 428,               /* kill_entry  */
  YYSYMBOL_429_22 = 429,                   /* $@22  */
  YYSYMBOL_kill_items = 430,               /* kill_items  */
  YYSYMBOL_kill_item = 431,                /* kill_item  */
  YYSYMBOL_kill_user = 432,                /* kill_user  */
  YYSYMBOL_kill_reason = 433,              /* kill_reason  */
  YYSYMBOL_deny_entry = 434,               /* deny_entry  */
  YYSYMBOL_435_23 = 435,                   /* $@23  */
  YYSYMBOL_deny_items = 436,               /* deny_items  */
  YYSYMBOL_deny_item = 437,                /* deny_item  */
  YYSYMBOL_deny_ip = 438,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 439,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 440,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 441,             /* exempt_items  */
  YYSYMBOL_exempt_item = 442,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 443,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 444,              /* gecos_entry  */
  YYSYMBOL_445_24 = 445,                   /* $@24  */
  YYSYMBOL_gecos_items = 446,              /* gecos_items  */
  YYSYMBOL_gecos_item = 447,               /* gecos_item  */
  YYSYMBOL_gecos_name = 448,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 449,             /* gecos_reason  */
  YYSYMBOL_general_entry = 450,            /* general_entry  */
  YYSYMBOL_general_items = 451,            /* general_items  */
  YYSYMBOL_general_item = 452,             /* general_item  */
  YYSYMBOL_general_away_count = 453,       /* general_away_count  */
  YYSYMBOL_general_away_time = 454,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 455,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 456, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 457, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 458,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 459,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 460,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 461,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 462, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 463, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 464,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 465,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 466, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 467,       /* general_max_accept  */
  YYSYMBOL_general_anti_spam_exit_message_time = 468, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 469,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 470,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 471, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 472, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 473, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 474, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 475, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 476, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 477, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 478, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 479, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 480,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 481,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 482, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 483, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 484,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 485,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 486, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 487,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 488,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_auth = 489,     /* general_disable_auth  */
  YYSYMBOL_general_throttle_count = 490,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 491,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 492,      /* general_oper_umodes  */
  YYSYMBOL_493_25 = 493,                   /* $@25  */
  YYSYMBOL_umode_oitems = 494,             /* umode_oitems  */
  YYSYMBOL_umode_oitem = 495,              /* umode_oitem  */
  YYSYMBOL_general_oper_only_umodes = 496, /* general_oper_only_umodes  */
  YYSYMBOL_497_26 = 497,                   /* $@26  */
  YYSYMBOL_umode_items = 498,              /* umode_items  */
  YYSYMBOL_umode_item = 499,               /* umode_item  */
  YYSYMBOL_general_min_nonwildcard = 500,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 501, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 502, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 503, /* general_default_floodtime  */
  YYSYMBOL_channel_entry = 504,            /* channel_entry  */
  YYSYMBOL_channel_items = 505,            /* channel_items  */
  YYSYMBOL_channel_item = 506,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 507,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 508,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 509,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 510, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 511, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 512, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 513, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 514, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 515, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 516, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 517, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 518,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 519,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 520,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 521,   /* channel_max_bans_large  */
  YYSYMBOL_channel_default_join_flood_count = 522, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 523, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 524,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 525,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 526,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 527, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 528, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 529, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 530, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 531,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 532, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 533,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 534,        /* serverhide_hidden  */
  YYSYMBOL_serverhide_hide_server_ips = 535 /* serverhide_hide_server_ips  */
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
#define YYLAST   1254

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  241
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  295
/* YYNRULES -- Number of rules.  */
#define YYNRULES  672
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1323

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   489


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
       2,     2,     2,     2,   239,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   240,   235,
       2,   238,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   237,     2,   236,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   368,   368,   369,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   399,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   410,   410,
     411,   412,   413,   414,   421,   423,   423,   424,   424,   424,
     426,   432,   442,   444,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   464,   473,   482,   491,   500,   509,   518,   527,
     542,   557,   567,   581,   590,   613,   636,   659,   669,   671,
     671,   672,   673,   674,   675,   677,   686,   695,   709,   708,
     726,   726,   727,   727,   727,   729,   735,   746,   745,   764,
     764,   765,   765,   765,   765,   765,   767,   773,   779,   785,
     807,   808,   808,   810,   810,   811,   813,   820,   820,   833,
     834,   836,   836,   837,   837,   839,   847,   850,   856,   855,
     861,   865,   869,   873,   877,   881,   885,   889,   900,   899,
     962,   962,   963,   964,   965,   966,   967,   968,   969,   970,
     971,   972,   973,   975,   981,   987,   993,   999,  1010,  1016,
    1027,  1034,  1033,  1039,  1039,  1040,  1044,  1048,  1052,  1056,
    1060,  1064,  1068,  1072,  1076,  1080,  1084,  1088,  1092,  1096,
    1100,  1104,  1108,  1112,  1116,  1120,  1124,  1128,  1135,  1134,
    1140,  1140,  1141,  1145,  1149,  1153,  1157,  1161,  1165,  1169,
    1173,  1177,  1181,  1185,  1189,  1193,  1197,  1201,  1205,  1209,
    1213,  1217,  1221,  1225,  1229,  1233,  1237,  1241,  1245,  1249,
    1253,  1264,  1263,  1319,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1335,  1337,  1343,  1349,  1355,  1361,  1367,  1373,  1379,  1385,
    1392,  1398,  1404,  1410,  1419,  1429,  1428,  1434,  1434,  1435,
    1439,  1450,  1449,  1456,  1455,  1460,  1460,  1461,  1465,  1469,
    1473,  1477,  1483,  1483,  1484,  1484,  1484,  1484,  1484,  1486,
    1486,  1488,  1488,  1490,  1503,  1520,  1526,  1537,  1536,  1583,
    1583,  1584,  1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,
    1594,  1600,  1606,  1612,  1624,  1623,  1629,  1629,  1630,  1634,
    1638,  1642,  1646,  1650,  1654,  1658,  1662,  1668,  1682,  1691,
    1705,  1704,  1719,  1719,  1720,  1720,  1720,  1720,  1722,  1728,
    1734,  1744,  1746,  1746,  1747,  1747,  1749,  1766,  1765,  1788,
    1788,  1789,  1789,  1789,  1789,  1791,  1797,  1817,  1816,  1822,
    1822,  1823,  1827,  1831,  1835,  1839,  1843,  1847,  1851,  1855,
    1859,  1870,  1869,  1888,  1888,  1889,  1889,  1889,  1891,  1898,
    1897,  1903,  1903,  1904,  1908,  1912,  1916,  1920,  1924,  1928,
    1932,  1936,  1940,  1951,  1950,  2028,  2028,  2029,  2030,  2031,
    2032,  2033,  2034,  2035,  2036,  2037,  2038,  2039,  2040,  2041,
    2042,  2043,  2044,  2046,  2052,  2058,  2064,  2070,  2083,  2096,
    2102,  2108,  2112,  2119,  2118,  2123,  2123,  2124,  2128,  2134,
    2145,  2151,  2157,  2163,  2179,  2178,  2202,  2202,  2203,  2203,
    2203,  2205,  2225,  2236,  2235,  2260,  2260,  2261,  2261,  2261,
    2263,  2269,  2279,  2281,  2281,  2282,  2282,  2284,  2302,  2301,
    2322,  2322,  2323,  2323,  2323,  2325,  2331,  2341,  2343,  2343,
    2344,  2345,  2346,  2347,  2348,  2349,  2350,  2351,  2352,  2353,
    2354,  2355,  2356,  2357,  2358,  2359,  2360,  2361,  2362,  2363,
    2364,  2365,  2366,  2367,  2368,  2369,  2370,  2371,  2372,  2373,
    2374,  2375,  2376,  2377,  2378,  2379,  2380,  2381,  2382,  2383,
    2384,  2385,  2386,  2387,  2388,  2389,  2392,  2397,  2402,  2407,
    2412,  2417,  2422,  2427,  2432,  2437,  2442,  2447,  2452,  2457,
    2462,  2467,  2472,  2477,  2482,  2487,  2492,  2497,  2502,  2507,
    2512,  2517,  2522,  2527,  2532,  2537,  2542,  2547,  2552,  2557,
    2562,  2567,  2572,  2577,  2582,  2588,  2587,  2592,  2592,  2593,
    2596,  2599,  2602,  2605,  2608,  2611,  2614,  2617,  2620,  2623,
    2626,  2629,  2632,  2635,  2638,  2641,  2644,  2647,  2650,  2653,
    2656,  2659,  2665,  2664,  2669,  2669,  2670,  2673,  2676,  2679,
    2682,  2685,  2688,  2691,  2694,  2697,  2700,  2703,  2706,  2709,
    2712,  2715,  2718,  2721,  2724,  2727,  2730,  2733,  2736,  2741,
    2746,  2751,  2756,  2765,  2767,  2767,  2768,  2769,  2770,  2771,
    2772,  2773,  2774,  2775,  2776,  2777,  2778,  2779,  2780,  2781,
    2782,  2783,  2784,  2785,  2787,  2792,  2798,  2804,  2809,  2814,
    2819,  2824,  2829,  2834,  2839,  2844,  2849,  2854,  2859,  2864,
    2869,  2878,  2880,  2880,  2881,  2882,  2883,  2884,  2885,  2886,
    2887,  2888,  2889,  2890,  2892,  2898,  2914,  2923,  2929,  2935,
    2941,  2950,  2956
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
  "CIDR_BITLEN_IPV6", "CLASS", "CLIENT", "CLOSE", "CONNECT", "CONNECTFREQ",
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
  "MASK", "MAX_ACCEPT", "MAX_BANS", "MAX_BANS_LARGE", "MAX_CHANNELS",
  "MAX_IDLE", "MAX_INVITES", "MAX_MONITOR", "MAX_NICK_CHANGES",
  "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_TOPIC_LENGTH", "MIN_IDLE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD", "NAME",
  "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESCRIPTION", "NETWORK_NAME",
  "NICK", "NO_OPER_FLOOD", "NO_TILDE", "NUMBER_PER_CIDR",
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
  "general_default_floodtime", "channel_entry", "channel_items",
  "channel_item", "channel_enable_extbans", "channel_enable_owner",
  "channel_enable_admin", "channel_disable_fake_channels",
  "channel_invite_client_count", "channel_invite_client_time",
  "channel_invite_delay_channel", "channel_invite_expire_time",
  "channel_knock_client_count", "channel_knock_client_time",
  "channel_knock_delay_channel", "channel_max_channels",
  "channel_max_invites", "channel_max_bans", "channel_max_bans_large",
  "channel_default_join_flood_count", "channel_default_join_flood_time",
  "serverhide_entry", "serverhide_items", "serverhide_item",
  "serverhide_flatten_links", "serverhide_flatten_links_delay",
  "serverhide_flatten_links_file", "serverhide_disable_remote_commands",
  "serverhide_hide_servers", "serverhide_hide_services",
  "serverhide_hidden_name", "serverhide_hidden",
  "serverhide_hide_server_ips", YY_NULLPTR
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

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -778,   853,  -778,  -159,  -220,  -209,  -778,  -778,  -778,  -207,
    -778,  -188,  -778,  -778,  -778,  -182,  -778,  -778,  -778,  -180,
    -173,  -778,  -150,  -778,  -140,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,   344,   966,  -138,  -132,  -123,    15,   -87,   405,   -85,
     -57,   -55,   294,   -50,   -22,   -12,   729,   589,   -10,    46,
      -8,    14,    -7,  -198,  -154,  -121,    25,     5,  -778,  -778,
    -778,  -778,  -778,    48,    52,    59,    69,    76,    81,    82,
      88,    90,    97,   103,   106,   108,   116,   117,   119,   120,
     155,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,   845,
     509,    28,  -778,   123,    20,  -778,  -778,    57,  -778,   128,
     129,   133,   134,   140,   142,   143,   145,   148,   149,   152,
     154,   156,   157,   160,   162,   163,   164,   165,   166,   167,
     170,   172,   178,  -778,  -778,   181,   183,   185,   186,   203,
     209,   210,   211,   216,   218,   220,   222,   223,   224,   225,
     229,   234,   235,   236,    53,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,   456,    50,   337,    23,   237,   239,    10,  -778,  -778,
    -778,    55,   290,   336,  -778,   241,   242,   244,   245,   248,
     249,   250,   252,   253,   314,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,    45,   255,   256,   257,   266,
     271,   273,   275,   278,   280,   282,   283,   286,   293,   301,
     302,   303,    95,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
      66,    49,   304,    24,  -778,  -778,  -778,   297,   188,  -778,
     305,    32,  -778,  -778,    60,  -778,    71,   110,   193,   158,
    -778,   310,   311,   264,   339,   340,   345,   322,   311,   311,
     311,   323,   311,   311,   331,   332,   333,   334,   335,  -778,
     341,   342,   350,   351,  -778,   353,   356,   357,   359,   360,
     361,   362,   363,   364,   365,   366,   233,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,   343,   367,   372,   373,   374,   378,   379,
    -778,   380,   383,   385,   393,   396,   399,   400,   401,   215,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,   402,   403,    13,
    -778,  -778,  -778,   349,   348,  -778,  -778,   406,   407,    33,
    -778,  -778,  -778,   368,   311,   338,   311,   311,   425,   409,
     311,   439,   414,   415,   446,   449,   311,   424,   427,   429,
     430,   432,   311,   433,   434,   435,   452,   440,   442,   464,
     311,   311,   465,   466,   448,   478,   479,   480,   482,   483,
     484,   487,   462,   311,   311,   311,   494,   470,   471,  -778,
     472,   473,   475,  -778,   476,   485,   486,   489,   491,    30,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
     493,   495,    40,  -778,  -778,  -778,   477,   496,   499,  -778,
     503,  -778,    65,  -778,  -778,  -778,  -778,  -778,   492,   511,
     481,  -778,   497,   510,   513,    17,  -778,  -778,  -778,   514,
     516,   517,  -778,   518,   519,  -778,   521,   523,   524,   527,
     230,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,   535,   534,   537,   538,    35,  -778,  -778,  -778,
    -778,   501,   502,   311,   548,   575,   552,   579,   580,   584,
     557,  -778,  -778,   559,   561,   588,   563,   564,   565,   568,
     571,   577,   578,   581,   586,   591,   594,   595,   596,   562,
    -778,   582,   583,  -778,    18,  -778,  -778,  -778,  -778,   615,
     597,  -778,   593,   599,   600,   601,   606,   607,     3,  -778,
    -778,  -778,  -778,  -778,   602,   612,  -778,   613,   611,  -778,
     614,    42,  -778,  -778,  -778,  -778,   616,   620,   621,  -778,
     623,   394,   624,   625,   626,   627,   630,   631,   632,   633,
     636,   637,   639,   640,   642,   643,   647,   653,  -778,  -778,
     603,   656,   311,   654,   659,   311,   661,   311,   648,   664,
     666,   669,   311,   674,   674,   675,  -778,  -778,   676,     1,
     681,   708,   683,   685,   682,   686,   689,   691,   690,   694,
     311,   696,   697,   698,  -778,   699,   704,   705,  -778,   706,
    -778,   711,   713,   712,  -778,   714,   715,   718,   719,   720,
     721,   727,   728,   730,   735,   738,   739,   740,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   573,
     646,   752,   755,   757,   758,   761,   763,   764,   768,   769,
     770,   771,   775,   776,   777,   778,   779,   780,   781,   782,
    -778,  -778,   731,   724,   701,   786,   787,   789,   790,   791,
     785,  -778,   792,   793,   795,  -778,  -778,   794,   804,   710,
     805,   803,  -778,   806,   808,  -778,  -778,   807,   811,   815,
    -778,  -778,   813,   821,   814,   818,   820,   819,   826,   854,
     827,   829,   828,  -778,  -778,   831,   832,   833,   834,  -778,
     835,   836,   837,   838,   839,   840,   841,   842,   843,  -778,
     844,   846,   847,   848,   849,   850,   851,   852,   855,   856,
     857,   858,   859,   860,   861,   862,  -778,  -778,   865,   830,
     864,  -778,   866,  -778,   107,  -778,   867,   869,   870,   871,
     872,  -778,   873,  -778,  -778,   876,   868,   877,   878,  -778,
    -778,  -778,  -778,  -778,   311,   311,   311,   311,   311,   311,
     311,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,   879,
     880,   881,   -53,   882,   883,   884,   885,   886,   887,   888,
     889,   890,    58,   891,   892,  -778,   893,   894,   895,   896,
     897,   898,   899,    16,   900,   901,   902,   903,   904,   905,
     906,   907,  -778,   908,   909,  -778,  -778,   910,   911,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -213,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -212,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,   912,   913,   -13,   914,   915,   916,   917,
     918,  -778,   919,   920,  -778,   921,   922,   105,   937,   330,
    -778,  -778,  -778,  -778,   924,   925,  -778,   926,   927,   474,
     928,   929,   717,   930,   931,   932,   933,  -778,   934,   935,
     936,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,   938,   515,  -778,
    -778,   939,   874,   940,  -778,     6,  -778,  -778,  -778,  -778,
     941,   942,   944,   945,  -778,  -778,   946,   766,   947,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -200,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,   674,   674,   674,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -195,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,   573,  -778,   646,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -193,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -187,  -778,   949,   805,   950,  -778,
    -778,  -778,  -778,  -778,  -778,   948,  -778,   951,   952,  -778,
    -778,   953,   954,  -778,  -778,   955,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -166,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -153,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -146,  -778,  -778,   956,  -181,
     958,   962,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -120,  -778,
    -778,  -778,   -53,  -778,  -778,  -778,  -778,    16,  -778,  -778,
    -778,   -13,  -778,   105,  -778,  -778,  -778,   441,   585,   972,
     817,   978,  1039,  -778,   474,  -778,   717,  -778,   515,   963,
     964,   965,   221,  -778,  -778,   766,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
     967,  -778,  -778
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
      93,    92,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   615,   630,   631,   632,   629,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   616,   617,   627,   628,     0,
       0,     0,   456,     0,     0,   454,   455,     0,   515,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   582,   555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   469,   470,   471,   513,   477,
     514,   508,   509,   510,   511,   481,   472,   473,   474,   475,
     476,   478,   479,   480,   482,   483,   512,   487,   488,   489,
     490,   486,   485,   491,   498,   499,   492,   493,   494,   484,
     496,   506,   507,   504,   505,   497,   495,   502,   503,   500,
     501,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,     0,     0,     0,   663,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   653,   654,   655,   656,   657,
     658,   659,   661,   660,   662,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    67,    65,    63,    68,    69,    70,
      64,    55,    66,    57,    58,    59,    60,    61,    62,    56,
       0,     0,     0,     0,   122,   123,   124,     0,     0,   345,
       0,     0,   343,   344,     0,    94,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   614,
       0,     0,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,   235,   238,
     240,   241,   242,   243,   244,   245,   246,   236,   237,   239,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
     423,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     396,   397,   398,   399,   400,   401,   402,   403,   405,   404,
     407,   411,   408,   409,   410,   406,   449,     0,     0,     0,
     446,   447,   448,     0,     0,   453,   464,     0,     0,     0,
     461,   462,   463,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   468,
       0,     0,     0,   314,     0,     0,     0,     0,     0,     0,
     300,   301,   302,   303,   308,   304,   305,   306,   307,   440,
       0,     0,     0,   437,   438,   439,     0,     0,     0,   273,
       0,   285,     0,   283,   284,   286,   287,    49,     0,     0,
       0,    45,     0,     0,     0,     0,   101,   102,   103,     0,
       0,     0,   198,     0,     0,   171,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   158,   159,   160,   157,
     156,   161,     0,     0,     0,     0,     0,   333,   334,   335,
     336,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   652,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,   379,     0,   374,   375,   376,   125,     0,
       0,   121,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   113,   112,   114,     0,     0,   342,     0,     0,   357,
       0,     0,   350,   351,   352,   353,     0,     0,     0,    88,
       0,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,   412,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   395,     0,     0,     0,   445,     0,
     452,     0,     0,     0,   460,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     467,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   299,     0,     0,     0,   436,   288,     0,     0,     0,
       0,     0,   282,     0,     0,    44,   104,     0,     0,     0,
     100,   162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   337,     0,     0,     0,     0,   332,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   651,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,   377,     0,     0,
       0,   373,     0,   120,     0,   115,     0,     0,     0,     0,
       0,   109,     0,   341,   354,     0,     0,     0,     0,   349,
      97,    96,    95,   649,    28,    28,    28,    28,    28,    28,
      28,    30,    29,   650,   637,   636,   634,   635,   638,   639,
     640,   641,   642,   643,   644,   647,   648,   645,   646,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   394,     0,     0,   444,   457,     0,     0,   459,
     527,   531,   516,   517,   544,   520,   611,   612,   552,   521,
     522,   526,   534,   525,   523,   524,   530,   518,   529,   528,
     550,   609,   610,   548,   586,   607,   592,   593,   594,   603,
     587,   588,   589,   598,   606,   590,   600,   604,   595,   605,
     596,   608,   599,   591,   602,   597,   601,     0,   585,   559,
     580,   564,   565,   566,   576,   560,   561,   562,   571,   579,
     563,   573,   577,   568,   578,   569,   581,   572,   567,   575,
     570,   574,     0,   558,   545,   543,   546,   551,   547,   549,
     536,   542,   541,   537,   538,   539,   540,   553,   554,   533,
     532,   535,   519,     0,     0,     0,     0,     0,     0,     0,
       0,   298,     0,     0,   435,     0,     0,     0,   293,   289,
     292,   272,    50,    51,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   331,   667,   664,   665,   666,   671,   670,   672,   668,
     669,    84,    81,    87,    80,    85,    86,    79,    83,    82,
      73,    72,    75,    76,    74,    77,    78,     0,     0,   372,
     126,     0,     0,     0,   138,     0,   130,   131,   133,   132,
       0,     0,     0,     0,   108,   346,     0,     0,     0,   348,
      31,    32,    33,    34,    35,    36,    37,   260,   261,   255,
     270,   269,     0,   268,   256,   264,   257,   263,   251,   262,
     254,   253,   252,    38,    38,    38,    40,    39,   258,   259,
     418,   421,   422,   432,   429,   414,   430,   427,   428,     0,
     426,   431,   413,   420,   417,   416,   415,   419,   433,   450,
     451,   465,   466,   583,     0,   556,     0,   312,   313,   322,
     318,   319,   321,   326,   323,   324,   325,   320,     0,   317,
     311,   329,   328,   327,   310,   442,   441,   296,   295,   280,
     281,   278,   279,   277,     0,   276,     0,     0,     0,   105,
     106,   170,   167,   218,   230,   205,   214,     0,   203,   208,
     224,     0,   217,   222,   228,   207,   210,   219,   221,   225,
     215,   223,   211,   229,   213,   220,   209,   212,     0,   201,
     163,   165,   175,   196,   180,   181,   182,   192,   176,   177,
     178,   187,   195,   179,   189,   193,   184,   194,   185,   197,
     188,   183,   191,   186,   190,     0,   174,   168,   169,   164,
     166,   340,   338,   339,   378,   383,   389,   392,   385,   391,
     386,   390,   388,   384,   387,     0,   382,   134,     0,     0,
       0,     0,   129,   117,   116,   118,   119,   355,   361,   367,
     370,   363,   369,   364,   368,   366,   362,   365,     0,   360,
     356,   266,     0,    41,    42,    43,   424,     0,   584,   557,
     315,     0,   274,     0,   294,   291,   290,     0,     0,     0,
       0,     0,     0,   199,     0,   172,     0,   380,     0,     0,
       0,     0,     0,   128,   358,     0,   267,   425,   316,   275,
     204,   227,   202,   226,   216,   206,   200,   173,   381,   135,
     137,   136,   146,   145,   141,   143,   147,   144,   140,   142,
       0,   359,   139
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -778,  -778,  -778,  -391,  -310,  -777,  -643,  -778,  -778,   957,
    -778,  -778,  -778,  -778,   438,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,   990,  -778,  -778,  -778,  -778,  -778,  -778,
     670,  -778,  -778,  -778,  -778,  -778,   500,  -778,  -778,  -778,
    -778,  -778,  -778,   796,  -778,  -778,  -778,  -778,   131,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,   560,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,   -99,
    -778,  -778,  -778,   -94,  -778,  -778,  -778,   863,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,   -61,  -778,  -778,  -778,  -778,
    -778,   -70,  -778,   716,  -778,  -778,  -778,    47,  -778,  -778,
    -778,  -778,  -778,   736,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,   -65,  -778,  -778,  -778,  -778,  -778,  -778,   671,  -778,
    -778,  -778,  -778,  -778,   923,  -778,  -778,  -778,  -778,   609,
    -778,  -778,  -778,  -778,  -778,   -84,  -778,  -778,  -778,   638,
    -778,  -778,  -778,  -778,   -75,  -778,  -778,  -778,   875,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,   -52,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
     732,  -778,  -778,  -778,  -778,  -778,   822,  -778,  -778,  -778,
    -778,  1092,  -778,  -778,  -778,  -778,   809,  -778,  -778,  -778,
    -778,  1043,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,    93,  -778,  -778,  -778,    96,  -778,
    -778,  -778,  -778,  -778,  -778,  1122,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778,   979,  -778,  -778,  -778,  -778,
    -778,  -778,  -778,  -778,  -778
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    26,   831,   832,  1096,  1097,    27,   227,   228,
     229,   230,    28,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,    29,    77,    78,    79,    80,    81,    30,    63,   505,
     506,   507,   508,    31,    70,   588,   589,   590,   591,   592,
     593,    32,   293,   294,   295,   296,   297,  1055,  1056,  1057,
    1058,  1059,  1240,  1320,    33,    64,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   757,  1215,  1216,
     531,   754,  1188,  1189,    34,    53,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   633,  1082,  1083,    35,    61,   491,   739,
    1154,  1155,   492,   493,   494,  1158,   999,  1000,   495,   496,
      36,    59,   469,   470,   471,   472,   473,   474,   475,   724,
    1138,  1139,   476,   477,   478,    37,    65,   536,   537,   538,
     539,   540,    38,   301,   302,   303,    39,    72,   601,   602,
     603,   604,   605,   816,  1258,  1259,    40,    68,   574,   575,
     576,   577,   799,  1235,  1236,    41,    54,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   654,
    1109,  1110,   391,   392,   393,   394,   395,    42,    60,   482,
     483,   484,   485,    43,    55,   399,   400,   401,   402,    44,
     124,   125,   126,    45,    57,   409,   410,   411,   412,    46,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   438,   962,   963,   216,   437,   937,   938,   217,
     218,   219,   220,    47,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    48,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     863,   864,   612,  1129,   583,  1080,    73,  1051,   618,   619,
     620,   224,   622,   623,   396,   299,   122,    51,   502,   571,
    1290,   122,  1123,  1125,  1107,   291,  1124,  1126,    52,   396,
      56,   460,  1130,   299,   406,  1261,   532,   305,    74,  1262,
    1266,   479,  1270,   597,  1267,    75,  1271,   291,  1272,    58,
     461,   479,  1273,   862,   128,    62,   502,    66,   406,   129,
     130,   597,   131,   132,    67,  1131,   486,   571,   133,  1283,
    1093,  1094,  1095,  1284,   462,  1081,    49,    50,   134,   135,
     136,   533,  1285,   397,   306,   123,  1286,    69,   137,  1287,
     123,   138,   139,  1288,  1132,  1133,   255,    71,   397,   119,
    1134,   140,   463,   503,   676,   120,   678,   679,  1051,   584,
     682,    76,  1052,   225,   121,  1294,   688,   307,   141,  1295,
     300,   534,   694,  1135,   572,   256,  1149,   487,   257,   142,
     702,   703,   143,   144,   226,   488,  1150,   489,   300,   407,
     145,   503,   398,   715,   716,   717,   146,   147,   598,   148,
     127,   149,   221,   464,   150,   151,    82,   398,   258,  1151,
     465,   466,   408,   407,   535,   152,   598,   585,   259,   480,
     153,   154,   572,   155,   156,   157,   867,   868,   158,   480,
     222,   467,   223,    83,    84,   586,   408,   231,   504,   583,
     260,    85,   490,  1136,   261,  -127,    86,    87,    88,  1053,
     587,   262,   159,   160,   263,   264,   161,   162,   163,   164,
     165,   166,   167,  1052,  1108,   232,   363,  -127,   364,  1137,
     365,    89,    90,    91,    92,   233,   504,   290,  1054,   298,
     304,   509,   265,   772,   330,   366,    93,    94,    95,   810,
     573,   309,  1241,    96,    97,    98,   500,    99,   292,   667,
     510,   331,   332,   749,   800,   468,   404,   333,   497,   367,
     580,   168,   169,   308,   599,   481,   730,   600,   595,   673,
     292,   768,   170,   171,   511,   481,   734,   368,   818,   369,
     552,   172,   599,   173,   578,   600,   311,   370,   573,   458,
     312,   509,   862,  1152,   584,   224,  1312,   313,  1313,   371,
    1053,   741,   512,  1153,   606,   334,   266,   314,   267,   268,
     510,   269,   270,   271,   315,   234,  1263,  1264,  1265,   316,
     317,   372,   851,   335,   336,   854,   318,   856,   319,  1054,
     337,   569,   861,   338,   511,   320,   513,   532,   486,   339,
    1314,   321,   373,   607,   322,    73,   323,   340,   341,   342,
     879,   235,   585,   514,   324,   325,  1315,   326,   327,   343,
     374,   403,   512,   236,   237,   238,   413,   414,   239,   240,
     586,   415,   416,   241,   242,   243,   375,    74,   417,   344,
     418,   419,   533,   420,    75,   587,   421,   422,  1316,  1317,
     423,   328,   424,   609,   425,   426,   513,   225,   427,   487,
     428,   429,   430,   431,   432,   433,   128,   488,   434,   489,
     435,   129,   130,   514,   131,   132,   436,   345,   226,   439,
     133,   440,   534,   441,   442,   376,   608,   377,   378,   515,
     134,   135,   136,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
     137,   443,   516,   138,   139,   517,  1318,   444,   445,   446,
      76,   663,  1319,   140,   447,   518,   448,   460,   449,   519,
     450,   451,   452,   453,   490,   535,   762,   454,   582,   645,
     141,   613,   455,   456,   457,   498,   461,   499,  1163,   541,
     542,   142,   543,   544,   143,   144,   545,   546,   547,   515,
     548,   549,   145,   553,   554,   555,  1164,  1165,   146,   147,
     462,   148,   516,   149,   556,   517,   150,   151,  1166,   557,
     363,   558,   364,   559,   365,   518,   560,   152,   561,   519,
     562,   563,   153,   154,   564,   155,   156,   157,   463,   366,
     158,   565,   824,   825,   826,   827,   828,   829,   830,   566,
     567,   568,   579,   594,   610,   611,   614,   615,  1167,  1168,
     550,  1169,   616,   367,   159,   160,   617,   621,   161,   162,
     163,   164,   165,   166,   167,   624,   625,   626,   627,  1157,
     628,   368,   677,   369,  1300,   675,   629,  1170,   647,   464,
     630,   370,   669,   670,   914,  1171,   465,   466,   631,   632,
     255,   634,  1225,   371,   635,   636,  1291,   637,   638,   639,
     640,   641,   642,   643,   644,   648,  1172,   467,  1173,  1174,
     649,   650,   651,   168,   169,   372,   652,   653,   655,   256,
     915,   656,   257,   657,   170,   171,  1175,   916,   611,   917,
     918,   658,   680,   172,   659,   173,   373,   660,   661,   662,
     665,   666,  1176,   681,   671,   672,   683,  1177,   684,   685,
    1226,  1178,   258,   686,   374,  1179,   687,   939,   689,   698,
    1180,   690,   259,   691,   692,  1181,   693,   695,   696,   697,
     375,   701,   704,   705,  1182,  1227,  1183,  1184,   699,  1185,
     700,   468,   706,  1228,   260,   707,   708,   709,   261,   710,
     711,   712,  1229,   940,   713,   262,   714,  1186,   263,   264,
     941,   718,   942,   943,   719,  1187,   720,   721,   770,   771,
     570,   722,   736,   723,   725,  1230,   745,  1231,  1232,   376,
    1301,   377,   378,   726,   727,   743,   265,   728,  1192,   729,
     234,   732,   746,   733,   737,   919,   920,   738,  1233,   921,
     922,   740,   923,   924,   744,   925,  1234,   926,   747,   751,
     927,   748,   928,   929,   752,   753,   755,   756,   930,   758,
     931,   759,   760,   932,  1193,   761,   235,   933,   934,   935,
     764,  1194,   765,  1195,  1196,   766,   767,   936,   236,   237,
     238,   773,   774,   239,   240,   775,   776,   777,   241,   242,
     243,   778,   779,   780,   781,   782,   783,   796,   784,   785,
     266,   786,   267,   268,   787,   269,   270,   271,   944,   945,
     788,   789,   946,   947,   790,   948,   949,   797,   950,   791,
     951,   798,   802,   952,   792,   953,   954,   793,   794,   795,
     804,   955,   803,   956,   805,   812,   957,   849,   806,   807,
     958,   959,   960,  1248,   808,   809,   330,   813,   814,   815,
     961,   820,   817,     2,     3,   821,   822,     4,   823,   833,
     834,   835,   836,   331,   332,   837,   838,   839,   840,   333,
       5,   841,   842,     6,   843,   844,     7,   845,   846,  1197,
    1198,   857,   847,  1199,  1200,     8,  1201,  1202,   848,  1203,
     850,  1204,   852,   853,  1205,   855,  1206,  1207,   858,     9,
     859,  1249,  1208,   860,  1209,    10,    11,  1210,   862,   866,
     865,  1211,  1212,  1213,   869,   870,   871,   334,   872,   874,
     873,  1214,   875,   877,    12,   876,  1250,   878,    13,   880,
     881,   984,   883,   882,  1251,   335,   336,   884,    14,   985,
     885,   886,   337,  1252,   887,   338,   888,   889,   997,   890,
     891,   339,  1303,   892,   893,   894,   895,    15,    16,   340,
     341,   342,   896,   897,   983,   898,  1253,    82,  1254,  1255,
     899,   343,    17,   900,   901,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   911,   912,   913,   964,    18,  1256,
     965,   344,   966,   967,    83,    84,   968,  1257,   969,   970,
      19,    20,    85,   971,   972,   973,   974,    86,    87,    88,
     975,   976,   977,   978,   979,   980,   981,   982,    21,   986,
     991,   987,   988,   989,   990,   992,   993,   995,  1008,   345,
     994,    22,    89,    90,    91,    92,    23,   996,  1001,   998,
    1004,  1002,    24,  1003,  1005,    25,  1007,    93,    94,    95,
    1006,  1010,  1009,  1011,    96,    97,    98,  1012,    99,  1013,
    1015,  1014,  1016,  1017,  1018,  1019,  1020,   310,  1048,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,
     763,  1032,  1033,  1034,  1035,  1036,  1037,  1038,   811,   581,
    1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,  1049,
    1060,  1050,  1061,  1062,  1063,  1302,  1067,  1064,  1065,  1066,
    1068,  1304,  1238,  1069,  1077,  1078,  1079,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1098,  1099,  1100,  1101,
    1102,  1103,  1104,  1105,  1106,  1111,  1112,  1113,  1114,  1115,
    1116,  1117,  1118,  1119,  1120,  1121,  1122,  1127,  1128,  1140,
    1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1156,  1159,
    1160,  1161,  1162,  1190,  1191,  1217,  1218,  1219,  1220,  1221,
    1222,  1223,  1305,  1224,  1237,   750,  1243,  1244,  1239,  1245,
    1246,  1247,  1260,  1274,   501,  1276,  1242,  1307,  1277,  1289,
    1306,  1278,  1279,  1280,  1281,  1282,  1292,  1293,  1309,  1310,
    1311,  1296,  1322,  1299,  1275,   731,  1298,   769,   742,   646,
     819,  1321,   801,  1308,   735,  1297,   405,   459,   674,  1269,
    1268,   668,   329,   551,   596,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   664
};

static const yytype_int16 yycheck[] =
{
     643,   644,   312,    16,     1,    58,     1,     1,   318,   319,
     320,     1,   322,   323,     1,     1,     1,   237,     1,     1,
     201,     1,   235,   235,     8,     1,   239,   239,   237,     1,
     237,     1,    45,     1,     1,   235,     1,   235,    33,   239,
     235,     1,   235,     1,   239,    40,   239,     1,   235,   237,
      20,     1,   239,   234,     1,   237,     1,   237,     1,     6,
       7,     1,     9,    10,   237,    78,     1,     1,    15,   235,
      12,    13,    14,   239,    44,   128,   235,   236,    25,    26,
      27,    46,   235,    70,   238,    70,   239,   237,    35,   235,
      70,    38,    39,   239,   107,   108,     1,   237,    70,   237,
     113,    48,    72,    86,   414,   237,   416,   417,     1,   106,
     420,   106,   106,   103,   237,   235,   426,   238,    65,   239,
     106,    86,   432,   136,   106,    30,    21,    62,    33,    76,
     440,   441,    79,    80,   124,    70,    31,    72,   106,   106,
      87,    86,   129,   453,   454,   455,    93,    94,   106,    96,
     237,    98,   237,   123,   101,   102,     1,   129,    63,    54,
     130,   131,   129,   106,   129,   112,   106,   164,    73,   129,
     117,   118,   106,   120,   121,   122,   175,   176,   125,   129,
     237,   151,   237,    28,    29,   182,   129,   237,   171,     1,
      95,    36,   127,   206,    99,   171,    41,    42,    43,   193,
     197,   106,   149,   150,   109,   110,   153,   154,   155,   156,
     157,   158,   159,   106,   198,   237,     1,   171,     3,   232,
       5,    66,    67,    68,    69,   237,   171,   237,   222,   237,
     237,     1,   137,   543,     1,    20,    81,    82,    83,   236,
     222,   236,   236,    88,    89,    90,   236,    92,   224,   236,
      20,    18,    19,   236,   236,   225,   236,    24,   235,    44,
     236,   208,   209,   238,   222,   225,   236,   225,   236,   236,
     224,   236,   219,   220,    44,   225,   236,    62,   236,    64,
     235,   228,   222,   230,   235,   225,   238,    72,   222,   236,
     238,     1,   234,   188,   106,     1,    75,   238,    77,    84,
     193,   236,    72,   198,   233,    72,   211,   238,   213,   214,
      20,   216,   217,   218,   238,     1,  1093,  1094,  1095,   238,
     238,   106,   632,    90,    91,   635,   238,   637,   238,   222,
      97,   236,   642,   100,    44,   238,   106,     1,     1,   106,
     119,   238,   127,   233,   238,     1,   238,   114,   115,   116,
     660,    37,   164,   123,   238,   238,   135,   238,   238,   126,
     145,   238,    72,    49,    50,    51,   238,   238,    54,    55,
     182,   238,   238,    59,    60,    61,   161,    33,   238,   146,
     238,   238,    46,   238,    40,   197,   238,   238,   167,   168,
     238,   236,   238,   235,   238,   238,   106,   103,   238,    62,
     238,   238,   238,   238,   238,   238,     1,    70,   238,    72,
     238,     6,     7,   123,     9,    10,   238,   184,   124,   238,
      15,   238,    86,   238,   238,   210,   233,   212,   213,   199,
      25,    26,    27,   824,   825,   826,   827,   828,   829,   830,
      35,   238,   212,    38,    39,   215,   225,   238,   238,   238,
     106,   236,   231,    48,   238,   225,   238,     1,   238,   229,
     238,   238,   238,   238,   127,   129,   236,   238,   171,   236,
      65,   207,   238,   238,   238,   238,    20,   238,     4,   238,
     238,    76,   238,   238,    79,    80,   238,   238,   238,   199,
     238,   238,    87,   238,   238,   238,    22,    23,    93,    94,
      44,    96,   212,    98,   238,   215,   101,   102,    34,   238,
       1,   238,     3,   238,     5,   225,   238,   112,   238,   229,
     238,   238,   117,   118,   238,   120,   121,   122,    72,    20,
     125,   238,   138,   139,   140,   141,   142,   143,   144,   238,
     238,   238,   238,   238,   234,   234,   207,   207,    74,    75,
     236,    77,   207,    44,   149,   150,   234,   234,   153,   154,
     155,   156,   157,   158,   159,   234,   234,   234,   234,   239,
     235,    62,   234,    64,   133,   207,   235,   103,   235,   123,
     238,    72,   233,   235,    11,   111,   130,   131,   238,   238,
       1,   238,    77,    84,   238,   238,  1239,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   132,   151,   134,   135,
     238,   238,   238,   208,   209,   106,   238,   238,   238,    30,
      47,   238,    33,   238,   219,   220,   152,    54,   234,    56,
      57,   238,   207,   228,   238,   230,   127,   238,   238,   238,
     238,   238,   168,   234,   238,   238,   207,   173,   234,   234,
     135,   177,    63,   207,   145,   181,   207,    11,   234,   207,
     186,   234,    73,   234,   234,   191,   234,   234,   234,   234,
     161,   207,   207,   207,   200,   160,   202,   203,   238,   205,
     238,   225,   234,   168,    95,   207,   207,   207,    99,   207,
     207,   207,   177,    47,   207,   106,   234,   223,   109,   110,
      54,   207,    56,    57,   234,   231,   235,   235,   207,   207,
     272,   238,   235,   238,   238,   200,   235,   202,   203,   210,
     135,   212,   213,   238,   238,   233,   137,   238,    11,   238,
       1,   238,   235,   238,   238,   162,   163,   238,   223,   166,
     167,   238,   169,   170,   233,   172,   231,   174,   238,   235,
     177,   238,   179,   180,   238,   238,   238,   238,   185,   238,
     187,   238,   238,   190,    47,   238,    37,   194,   195,   196,
     235,    54,   238,    56,    57,   238,   238,   204,    49,    50,
      51,   233,   207,    54,    55,   233,   207,   207,    59,    60,
      61,   207,   235,   234,   233,   207,   233,   235,   234,   234,
     211,   233,   213,   214,   233,   216,   217,   218,   162,   163,
     233,   233,   166,   167,   233,   169,   170,   235,   172,   233,
     174,   238,   207,   177,   233,   179,   180,   233,   233,   233,
     237,   185,   235,   187,   235,   233,   190,   234,   238,   238,
     194,   195,   196,    77,   238,   238,     1,   235,   235,   238,
     204,   235,   238,     0,     1,   235,   235,     4,   235,   235,
     235,   235,   235,    18,    19,   235,   235,   235,   235,    24,
      17,   235,   235,    20,   235,   235,    23,   235,   235,   162,
     163,   233,   235,   166,   167,    32,   169,   170,   235,   172,
     234,   174,   238,   234,   177,   234,   179,   180,   234,    46,
     234,   135,   185,   234,   187,    52,    53,   190,   234,   233,
     235,   194,   195,   196,   233,   207,   233,    72,   233,   233,
     238,   204,   233,   233,    71,   234,   160,   233,    75,   233,
     233,   207,   233,   235,   168,    90,    91,   233,    85,   238,
     235,   235,    97,   177,   233,   100,   233,   235,   238,   235,
     235,   106,   135,   235,   235,   235,   235,   104,   105,   114,
     115,   116,   235,   235,   233,   235,   200,     1,   202,   203,
     235,   126,   119,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   135,   223,
     235,   146,   235,   235,    28,    29,   235,   231,   235,   235,
     147,   148,    36,   235,   235,   235,   235,    41,    42,    43,
     235,   235,   235,   235,   235,   235,   235,   235,   165,   233,
     235,   234,   233,   233,   233,   233,   233,   233,   207,   184,
     235,   178,    66,    67,    68,    69,   183,   233,   235,   234,
     233,   235,   189,   235,   233,   192,   233,    81,    82,    83,
     235,   233,   238,   233,    88,    89,    90,   238,    92,   233,
     233,   207,   233,   235,   233,   233,   233,    77,   238,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     520,   235,   235,   235,   235,   235,   235,   235,   588,   293,
     235,   235,   235,   235,   235,   235,   235,   235,   233,   235,
     233,   235,   233,   233,   233,   133,   238,   235,   235,   233,
     233,   133,   238,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   221,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   133,   235,   235,   505,   235,   235,   238,   235,
     235,   235,   235,   234,   227,   235,  1055,  1286,   240,   233,
    1284,   240,   240,   240,   240,   240,   238,   235,   235,   235,
     235,  1262,   235,  1273,  1157,   469,  1271,   536,   492,   346,
     601,  1295,   574,  1288,   482,  1267,   124,   174,   409,  1126,
    1124,   399,   100,   244,   301,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   379
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   242,     0,     1,     4,    17,    20,    23,    32,    46,
      52,    53,    71,    75,    85,   104,   105,   119,   135,   147,
     148,   165,   178,   183,   189,   192,   243,   248,   253,   272,
     278,   284,   292,   305,   325,   347,   361,   376,   383,   387,
     397,   406,   428,   434,   440,   444,   450,   504,   524,   235,
     236,   237,   237,   326,   407,   435,   237,   445,   237,   362,
     429,   348,   237,   279,   306,   377,   237,   237,   398,   237,
     285,   237,   388,     1,    33,    40,   106,   273,   274,   275,
     276,   277,     1,    28,    29,    36,    41,    42,    43,    66,
      67,    68,    69,    81,    82,    83,    88,    89,    90,    92,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   237,
     237,   237,     1,    70,   441,   442,   443,   237,     1,     6,
       7,     9,    10,    15,    25,    26,    27,    35,    38,    39,
      48,    65,    76,    79,    80,    87,    93,    94,    96,    98,
     101,   102,   112,   117,   118,   120,   121,   122,   125,   149,
     150,   153,   154,   155,   156,   157,   158,   159,   208,   209,
     219,   220,   228,   230,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   496,   500,   501,   502,
     503,   237,   237,   237,     1,   103,   124,   249,   250,   251,
     252,   237,   237,   237,     1,    37,    49,    50,    51,    54,
      55,    59,    60,    61,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,     1,    30,    33,    63,    73,
      95,    99,   106,   109,   110,   137,   211,   213,   214,   216,
     217,   218,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     237,     1,   224,   293,   294,   295,   296,   297,   237,     1,
     106,   384,   385,   386,   237,   235,   238,   238,   238,   236,
     274,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   236,   506,
       1,    18,    19,    24,    72,    90,    91,    97,   100,   106,
     114,   115,   116,   126,   146,   184,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,     1,     3,     5,    20,    44,    62,    64,
      72,    84,   106,   127,   145,   161,   210,   212,   213,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   423,   424,   425,   426,   427,     1,    70,   129,   436,
     437,   438,   439,   238,   236,   442,     1,   106,   129,   446,
     447,   448,   449,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   497,   493,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   236,   452,
       1,    20,    44,    72,   123,   130,   131,   151,   225,   363,
     364,   365,   366,   367,   368,   369,   373,   374,   375,     1,
     129,   225,   430,   431,   432,   433,     1,    62,    70,    72,
     127,   349,   353,   354,   355,   359,   360,   235,   238,   238,
     236,   250,     1,    86,   171,   280,   281,   282,   283,     1,
      20,    44,    72,   106,   123,   199,   212,   215,   225,   229,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   321,     1,    46,    86,   129,   378,   379,   380,   381,
     382,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     236,   526,   235,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   236,
     255,     1,   106,   222,   399,   400,   401,   402,   235,   238,
     236,   294,   171,     1,   106,   164,   182,   197,   286,   287,
     288,   289,   290,   291,   238,   236,   385,     1,   106,   222,
     225,   389,   390,   391,   392,   393,   233,   233,   233,   235,
     234,   234,   245,   207,   207,   207,   207,   234,   245,   245,
     245,   234,   245,   245,   234,   234,   234,   234,   235,   235,
     238,   238,   238,   344,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   236,   328,   235,   238,   238,
     238,   238,   238,   238,   420,   238,   238,   238,   238,   238,
     238,   238,   238,   236,   409,   238,   238,   236,   437,   233,
     235,   238,   238,   236,   447,   207,   245,   234,   245,   245,
     207,   234,   245,   207,   234,   234,   207,   207,   245,   234,
     234,   234,   234,   234,   245,   234,   234,   234,   207,   238,
     238,   207,   245,   245,   207,   207,   234,   207,   207,   207,
     207,   207,   207,   207,   234,   245,   245,   245,   207,   234,
     235,   235,   238,   238,   370,   238,   238,   238,   238,   238,
     236,   364,   238,   238,   236,   431,   235,   238,   238,   350,
     238,   236,   354,   233,   233,   235,   235,   238,   238,   236,
     281,   235,   238,   238,   322,   238,   238,   318,   238,   238,
     238,   238,   236,   308,   235,   238,   238,   238,   236,   379,
     207,   207,   245,   233,   207,   233,   207,   207,   207,   235,
     234,   233,   207,   233,   234,   234,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   235,   235,   238,   403,
     236,   400,   207,   235,   237,   235,   238,   238,   238,   238,
     236,   287,   233,   235,   235,   238,   394,   238,   236,   390,
     235,   235,   235,   235,   138,   139,   140,   141,   142,   143,
     144,   244,   245,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   234,
     234,   245,   238,   234,   245,   234,   245,   233,   234,   234,
     234,   245,   234,   247,   247,   235,   233,   175,   176,   233,
     207,   233,   233,   238,   233,   233,   234,   233,   233,   245,
     233,   233,   235,   233,   233,   235,   235,   233,   233,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,    11,    47,    54,    56,    57,   162,
     163,   166,   167,   169,   170,   172,   174,   177,   179,   180,
     185,   187,   190,   194,   195,   196,   204,   498,   499,    11,
      47,    54,    56,    57,   162,   163,   166,   167,   169,   170,
     172,   174,   177,   179,   180,   185,   187,   190,   194,   195,
     196,   204,   494,   495,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   233,   207,   238,   233,   234,   233,   233,
     233,   235,   233,   233,   235,   233,   233,   238,   234,   357,
     358,   235,   235,   235,   233,   233,   235,   233,   207,   238,
     233,   233,   238,   233,   207,   233,   233,   235,   233,   233,
     233,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   233,   238,   235,
     235,     1,   106,   193,   222,   298,   299,   300,   301,   302,
     233,   233,   233,   233,   235,   235,   233,   238,   233,   235,
     244,   244,   244,   244,   244,   244,   244,   235,   235,   235,
      58,   128,   345,   346,   235,   235,   235,   235,   235,   235,
     235,   235,   235,    12,    13,    14,   246,   247,   235,   235,
     235,   235,   235,   235,   235,   235,   235,     8,   198,   421,
     422,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   239,   235,   239,   235,   235,    16,
      45,    78,   107,   108,   113,   136,   206,   232,   371,   372,
     235,   235,   235,   235,   235,   235,   235,   235,   235,    21,
      31,    54,   188,   198,   351,   352,   221,   239,   356,   235,
     235,   235,   235,     4,    22,    23,    34,    74,    75,    77,
     103,   111,   132,   134,   135,   152,   168,   173,   177,   181,
     186,   191,   200,   202,   203,   205,   223,   231,   323,   324,
     235,   235,    11,    47,    54,    56,    57,   162,   163,   166,
     167,   169,   170,   172,   174,   177,   179,   180,   185,   187,
     190,   194,   195,   196,   204,   319,   320,   235,   235,   235,
     235,   235,   235,   235,   235,    77,   135,   160,   168,   177,
     200,   202,   203,   223,   231,   404,   405,   235,   238,   238,
     303,   236,   299,   235,   235,   235,   235,   235,    77,   135,
     160,   168,   177,   200,   202,   203,   223,   231,   395,   396,
     235,   235,   239,   246,   246,   246,   235,   239,   499,   495,
     235,   239,   235,   239,   234,   358,   235,   240,   240,   240,
     240,   240,   240,   235,   239,   235,   239,   235,   239,   233,
     201,   247,   238,   235,   235,   239,   346,   422,   372,   352,
     133,   135,   133,   135,   133,   133,   324,   320,   405,   235,
     235,   235,    75,    77,   119,   135,   167,   168,   225,   231,
     304,   396,   235
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   241,   242,   242,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   244,   244,
     245,   245,   245,   245,   245,   245,   245,   245,   246,   246,
     247,   247,   247,   247,   248,   249,   249,   250,   250,   250,
     251,   252,   253,   254,   254,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     273,   274,   274,   274,   274,   275,   276,   277,   279,   278,
     280,   280,   281,   281,   281,   282,   283,   285,   284,   286,
     286,   287,   287,   287,   287,   287,   288,   289,   290,   291,
     292,   293,   293,   294,   294,   294,   295,   297,   296,   298,
     298,   299,   299,   299,   299,   300,   301,   301,   303,   302,
     304,   304,   304,   304,   304,   304,   304,   304,   306,   305,
     307,   307,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   318,   317,   319,   319,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   322,   321,
     323,   323,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   326,   325,   327,   327,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   344,   343,   345,   345,   346,
     346,   348,   347,   350,   349,   351,   351,   352,   352,   352,
     352,   352,   353,   353,   354,   354,   354,   354,   354,   356,
     355,   357,   357,   358,   358,   359,   360,   362,   361,   363,
     363,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     365,   366,   367,   368,   370,   369,   371,   371,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   373,   374,   375,
     377,   376,   378,   378,   379,   379,   379,   379,   380,   381,
     382,   383,   384,   384,   385,   385,   386,   388,   387,   389,
     389,   390,   390,   390,   390,   391,   392,   394,   393,   395,
     395,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     396,   398,   397,   399,   399,   400,   400,   400,   401,   403,
     402,   404,   404,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   407,   406,   408,   408,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   418,   420,   419,   421,   421,   422,   422,   423,
     424,   425,   426,   427,   429,   428,   430,   430,   431,   431,
     431,   432,   433,   435,   434,   436,   436,   437,   437,   437,
     438,   439,   440,   441,   441,   442,   442,   443,   445,   444,
     446,   446,   447,   447,   447,   448,   449,   450,   451,   451,
     452,   452,   452,   452,   452,   452,   452,   452,   452,   452,
     452,   452,   452,   452,   452,   452,   452,   452,   452,   452,
     452,   452,   452,   452,   452,   452,   452,   452,   452,   452,
     452,   452,   452,   452,   452,   452,   452,   452,   452,   452,
     452,   452,   452,   452,   452,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   493,   492,   494,   494,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   497,   496,   498,   498,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   500,
     501,   502,   503,   504,   505,   505,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   525,   526,   526,   526,   526,   526,   526,
     526,   526,   526,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535
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
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
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
#line 399 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3275 "conf_parser.c"
    break;

  case 30: /* timespec: NUMBER timespec_  */
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3281 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER SECONDS timespec_  */
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3287 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER MINUTES timespec_  */
#line 402 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3293 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER HOURS timespec_  */
#line 403 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3299 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER DAYS timespec_  */
#line 404 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3305 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER WEEKS timespec_  */
#line 405 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3311 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER MONTHS timespec_  */
#line 406 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3317 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER YEARS timespec_  */
#line 407 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3323 "conf_parser.c"
    break;

  case 38: /* sizespec_: %empty  */
#line 410 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3329 "conf_parser.c"
    break;

  case 40: /* sizespec: NUMBER sizespec_  */
#line 411 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3335 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER BYTES sizespec_  */
#line 412 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3341 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER KBYTES sizespec_  */
#line 413 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3347 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER MBYTES sizespec_  */
#line 414 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3353 "conf_parser.c"
    break;

  case 50: /* modules_module: MODULE '=' QSTRING ';'  */
#line 427 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 3362 "conf_parser.c"
    break;

  case 51: /* modules_path: PATH '=' QSTRING ';'  */
#line 433 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 3371 "conf_parser.c"
    break;

  case 72: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 465 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = xstrdup(yylval.string);
  }
}
#line 3383 "conf_parser.c"
    break;

  case 73: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 474 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 3395 "conf_parser.c"
    break;

  case 74: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 483 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3407 "conf_parser.c"
    break;

  case 75: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 492 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = xstrdup(yylval.string);
  }
}
#line 3419 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 501 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = xstrdup(yylval.string);
  }
}
#line 3431 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 510 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3443 "conf_parser.c"
    break;

  case 78: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 519 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = xstrdup(yylval.string);
  }
}
#line 3455 "conf_parser.c"
    break;

  case 79: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 528 "conf_parser.y"
{
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && ConfigServerInfo.name == NULL)
  {
    if (server_valid_name(yylval.string) == true)
      ConfigServerInfo.name = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3473 "conf_parser.c"
    break;

  case 80: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 543 "conf_parser.y"
{
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && ConfigServerInfo.sid == NULL)
  {
    if (valid_sid(yylval.string))
      ConfigServerInfo.sid = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3491 "conf_parser.c"
    break;

  case 81: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 558 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3504 "conf_parser.c"
    break;

  case 82: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 568 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    char *p = strchr(yylval.string, ' ');

    if (p)
      *p = '\0';

    xfree(ConfigServerInfo.network_name);
    ConfigServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3521 "conf_parser.c"
    break;

  case 83: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 582 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = xstrdup(yylval.string);
}
#line 3533 "conf_parser.c"
    break;

  case 84: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 591 "conf_parser.y"
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
#line 3559 "conf_parser.c"
    break;

  case 85: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 614 "conf_parser.y"
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
#line 3585 "conf_parser.c"
    break;

  case 86: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 637 "conf_parser.y"
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
#line 3611 "conf_parser.c"
    break;

  case 87: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 660 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3620 "conf_parser.c"
    break;

  case 95: /* admin_name: NAME '=' QSTRING ';'  */
#line 678 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3632 "conf_parser.c"
    break;

  case 96: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 687 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3644 "conf_parser.c"
    break;

  case 97: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 696 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3656 "conf_parser.c"
    break;

  case 98: /* $@1: %empty  */
#line 709 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3665 "conf_parser.c"
    break;

  case 99: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 713 "conf_parser.y"
{
  dlink_node *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3682 "conf_parser.c"
    break;

  case 105: /* motd_mask: MASK '=' QSTRING ';'  */
#line 730 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3691 "conf_parser.c"
    break;

  case 106: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 736 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3700 "conf_parser.c"
    break;

  case 107: /* $@2: %empty  */
#line 746 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3709 "conf_parser.c"
    break;

  case 108: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 750 "conf_parser.y"
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
#line 3727 "conf_parser.c"
    break;

  case 116: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 768 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3736 "conf_parser.c"
    break;

  case 117: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 774 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3745 "conf_parser.c"
    break;

  case 118: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 780 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3754 "conf_parser.c"
    break;

  case 119: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 786 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.nick.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.nick.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
#line 3775 "conf_parser.c"
    break;

  case 126: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 814 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3784 "conf_parser.c"
    break;

  case 127: /* $@3: %empty  */
#line 820 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3793 "conf_parser.c"
    break;

  case 128: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 824 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3806 "conf_parser.c"
    break;

  case 135: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 840 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3817 "conf_parser.c"
    break;

  case 136: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 848 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3825 "conf_parser.c"
    break;

  case 137: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 851 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3833 "conf_parser.c"
    break;

  case 138: /* $@4: %empty  */
#line 856 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3842 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: USER  */
#line 862 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3851 "conf_parser.c"
    break;

  case 141: /* logging_file_type_item: OPERATOR  */
#line 866 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3860 "conf_parser.c"
    break;

  case 142: /* logging_file_type_item: XLINE  */
#line 870 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3869 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: RESV  */
#line 874 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3878 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: T_DLINE  */
#line 878 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3887 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: KLINE  */
#line 882 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3896 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: KILL  */
#line 886 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3905 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: T_DEBUG  */
#line 890 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3914 "conf_parser.c"
    break;

  case 148: /* $@5: %empty  */
#line 900 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3926 "conf_parser.c"
    break;

  case 149: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 907 "conf_parser.y"
{
  dlink_node *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  if (!block_state.rpass.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct split_nuh_item nuh;
    char *s = node->data;

    if (EmptyString(s))
      continue;

    nuh.nuhmask  = s;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);

    struct MaskItem *conf = conf_make(CONF_OPER);
    conf->addr = xcalloc(sizeof(*conf->addr));
    conf->name = xstrdup(block_state.name.buf);
    conf->user = xstrdup(block_state.user.buf);
    conf->host = xstrdup(block_state.host.buf);

    if (block_state.cert.buf[0])
      conf->certfp = xstrdup(block_state.cert.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);

    if (block_state.whois.buf[0])
      conf->whois = xstrdup(block_state.whois.buf);

    conf->flags = block_state.flags.value;
    conf->modes = block_state.modes.value;
    conf->port  = block_state.port.value;
    conf->htype = parse_netmask(conf->host, conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);
  }
}
#line 3985 "conf_parser.c"
    break;

  case 163: /* oper_name: NAME '=' QSTRING ';'  */
#line 976 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3994 "conf_parser.c"
    break;

  case 164: /* oper_user: USER '=' QSTRING ';'  */
#line 982 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4003 "conf_parser.c"
    break;

  case 165: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 988 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4012 "conf_parser.c"
    break;

  case 166: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 994 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4021 "conf_parser.c"
    break;

  case 167: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1000 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 4035 "conf_parser.c"
    break;

  case 168: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1011 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4044 "conf_parser.c"
    break;

  case 169: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1017 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 4058 "conf_parser.c"
    break;

  case 170: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1028 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4067 "conf_parser.c"
    break;

  case 171: /* $@6: %empty  */
#line 1034 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 4076 "conf_parser.c"
    break;

  case 175: /* oper_umodes_item: BOT  */
#line 1041 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOT;
}
#line 4085 "conf_parser.c"
    break;

  case 176: /* oper_umodes_item: T_CCONN  */
#line 1045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 4094 "conf_parser.c"
    break;

  case 177: /* oper_umodes_item: T_DEAF  */
#line 1049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 4103 "conf_parser.c"
    break;

  case 178: /* oper_umodes_item: T_DEBUG  */
#line 1053 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 4112 "conf_parser.c"
    break;

  case 179: /* oper_umodes_item: T_FLOOD  */
#line 1057 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FLOOD;
}
#line 4121 "conf_parser.c"
    break;

  case 180: /* oper_umodes_item: HIDDEN  */
#line 1061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 4130 "conf_parser.c"
    break;

  case 181: /* oper_umodes_item: HIDE_CHANS  */
#line 1065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 4139 "conf_parser.c"
    break;

  case 182: /* oper_umodes_item: HIDE_IDLE  */
#line 1069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 4148 "conf_parser.c"
    break;

  case 183: /* oper_umodes_item: T_SKILL  */
#line 1073 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 4157 "conf_parser.c"
    break;

  case 184: /* oper_umodes_item: T_NCHANGE  */
#line 1077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 4166 "conf_parser.c"
    break;

  case 185: /* oper_umodes_item: T_REJ  */
#line 1081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 4175 "conf_parser.c"
    break;

  case 186: /* oper_umodes_item: T_SPY  */
#line 1085 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4184 "conf_parser.c"
    break;

  case 187: /* oper_umodes_item: T_EXTERNAL  */
#line 1089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4193 "conf_parser.c"
    break;

  case 188: /* oper_umodes_item: T_SERVNOTICE  */
#line 1093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4202 "conf_parser.c"
    break;

  case 189: /* oper_umodes_item: T_INVISIBLE  */
#line 1097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4211 "conf_parser.c"
    break;

  case 190: /* oper_umodes_item: T_WALLOP  */
#line 1101 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4220 "conf_parser.c"
    break;

  case 191: /* oper_umodes_item: T_SOFTCALLERID  */
#line 1105 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4229 "conf_parser.c"
    break;

  case 192: /* oper_umodes_item: T_CALLERID  */
#line 1109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4238 "conf_parser.c"
    break;

  case 193: /* oper_umodes_item: T_LOCOPS  */
#line 1113 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4247 "conf_parser.c"
    break;

  case 194: /* oper_umodes_item: T_NONONREG  */
#line 1117 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4256 "conf_parser.c"
    break;

  case 195: /* oper_umodes_item: T_FARCONNECT  */
#line 1121 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4265 "conf_parser.c"
    break;

  case 196: /* oper_umodes_item: EXPIRATION  */
#line 1125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 4274 "conf_parser.c"
    break;

  case 197: /* oper_umodes_item: T_SECUREONLY  */
#line 1129 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SECUREONLY;
}
#line 4283 "conf_parser.c"
    break;

  case 198: /* $@7: %empty  */
#line 1135 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4292 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: KILL ':' REMOTE  */
#line 1142 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4301 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: KILL  */
#line 1146 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4310 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1150 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4319 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: CONNECT  */
#line 1154 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4328 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1158 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4337 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: SQUIT  */
#line 1162 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4346 "conf_parser.c"
    break;

  case 208: /* oper_flags_item: KLINE  */
#line 1166 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4355 "conf_parser.c"
    break;

  case 209: /* oper_flags_item: UNKLINE  */
#line 1170 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4364 "conf_parser.c"
    break;

  case 210: /* oper_flags_item: T_DLINE  */
#line 1174 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4373 "conf_parser.c"
    break;

  case 211: /* oper_flags_item: T_UNDLINE  */
#line 1178 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4382 "conf_parser.c"
    break;

  case 212: /* oper_flags_item: XLINE  */
#line 1182 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4391 "conf_parser.c"
    break;

  case 213: /* oper_flags_item: T_UNXLINE  */
#line 1186 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4400 "conf_parser.c"
    break;

  case 214: /* oper_flags_item: DIE  */
#line 1190 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4409 "conf_parser.c"
    break;

  case 215: /* oper_flags_item: T_RESTART  */
#line 1194 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4418 "conf_parser.c"
    break;

  case 216: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1198 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4427 "conf_parser.c"
    break;

  case 217: /* oper_flags_item: REHASH  */
#line 1202 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4436 "conf_parser.c"
    break;

  case 218: /* oper_flags_item: ADMIN  */
#line 1206 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4445 "conf_parser.c"
    break;

  case 219: /* oper_flags_item: T_GLOBOPS  */
#line 1210 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4454 "conf_parser.c"
    break;

  case 220: /* oper_flags_item: T_WALLOPS  */
#line 1214 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4463 "conf_parser.c"
    break;

  case 221: /* oper_flags_item: T_LOCOPS  */
#line 1218 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4472 "conf_parser.c"
    break;

  case 222: /* oper_flags_item: REMOTEBAN  */
#line 1222 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4481 "conf_parser.c"
    break;

  case 223: /* oper_flags_item: T_SET  */
#line 1226 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4490 "conf_parser.c"
    break;

  case 224: /* oper_flags_item: MODULE  */
#line 1230 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4499 "conf_parser.c"
    break;

  case 225: /* oper_flags_item: T_OPME  */
#line 1234 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4508 "conf_parser.c"
    break;

  case 226: /* oper_flags_item: NICK ':' RESV  */
#line 1238 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4517 "conf_parser.c"
    break;

  case 227: /* oper_flags_item: JOIN ':' RESV  */
#line 1242 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4526 "conf_parser.c"
    break;

  case 228: /* oper_flags_item: RESV  */
#line 1246 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4535 "conf_parser.c"
    break;

  case 229: /* oper_flags_item: T_UNRESV  */
#line 1250 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4544 "conf_parser.c"
    break;

  case 230: /* oper_flags_item: CLOSE  */
#line 1254 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4553 "conf_parser.c"
    break;

  case 231: /* $@8: %empty  */
#line 1264 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4569 "conf_parser.c"
    break;

  case 232: /* class_entry: CLASS $@8 '{' class_items '}' ';'  */
#line 1275 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.class.buf[0])
    break;

  struct ClassItem *class = class_find(block_state.class.buf, false);
  if (class == NULL)
    class = class_make();

  class->active = true;
  xfree(class->name);
  class->name = xstrdup(block_state.class.buf);
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
#line 4617 "conf_parser.c"
    break;

  case 251: /* class_name: NAME '=' QSTRING ';'  */
#line 1338 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4626 "conf_parser.c"
    break;

  case 252: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1344 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4635 "conf_parser.c"
    break;

  case 253: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1350 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4644 "conf_parser.c"
    break;

  case 254: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1356 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4653 "conf_parser.c"
    break;

  case 255: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1362 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4662 "conf_parser.c"
    break;

  case 256: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1368 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4671 "conf_parser.c"
    break;

  case 257: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1374 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4680 "conf_parser.c"
    break;

  case 258: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1380 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4689 "conf_parser.c"
    break;

  case 259: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1386 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4699 "conf_parser.c"
    break;

  case 260: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1393 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4708 "conf_parser.c"
    break;

  case 261: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1399 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4717 "conf_parser.c"
    break;

  case 262: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1405 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4726 "conf_parser.c"
    break;

  case 263: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1411 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4738 "conf_parser.c"
    break;

  case 264: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1420 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4750 "conf_parser.c"
    break;

  case 265: /* $@9: %empty  */
#line 1429 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4759 "conf_parser.c"
    break;

  case 269: /* class_flags_item: RANDOM_IDLE  */
#line 1436 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4768 "conf_parser.c"
    break;

  case 270: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1440 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4777 "conf_parser.c"
    break;

  case 271: /* $@10: %empty  */
#line 1450 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4786 "conf_parser.c"
    break;

  case 273: /* $@11: %empty  */
#line 1456 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4794 "conf_parser.c"
    break;

  case 277: /* listen_flags_item: T_TLS  */
#line 1462 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4803 "conf_parser.c"
    break;

  case 278: /* listen_flags_item: HIDDEN  */
#line 1466 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4812 "conf_parser.c"
    break;

  case 279: /* listen_flags_item: T_SERVER  */
#line 1470 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4821 "conf_parser.c"
    break;

  case 280: /* listen_flags_item: CLIENT  */
#line 1474 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4830 "conf_parser.c"
    break;

  case 281: /* listen_flags_item: DEFER  */
#line 1478 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4839 "conf_parser.c"
    break;

  case 289: /* $@12: %empty  */
#line 1486 "conf_parser.y"
                                 { reset_block_state(); }
#line 4845 "conf_parser.c"
    break;

  case 293: /* port_item: NUMBER  */
#line 1491 "conf_parser.y"
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
#line 4863 "conf_parser.c"
    break;

  case 294: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1504 "conf_parser.y"
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
#line 4883 "conf_parser.c"
    break;

  case 295: /* listen_address: IP '=' QSTRING ';'  */
#line 1521 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4892 "conf_parser.c"
    break;

  case 296: /* listen_host: HOST '=' QSTRING ';'  */
#line 1527 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4901 "conf_parser.c"
    break;

  case 297: /* $@13: %empty  */
#line 1537 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4910 "conf_parser.c"
    break;

  case 298: /* auth_entry: IRCD_AUTH $@13 '{' auth_items '}' ';'  */
#line 1541 "conf_parser.y"
{
  dlink_node *node;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct split_nuh_item nuh;
    char *s = node->data;

    if (EmptyString(s))
      continue;

    nuh.nuhmask  = s;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);

    struct MaskItem *conf = conf_make(CONF_CLIENT);
    conf->user = xstrdup(block_state.user.buf);
    conf->host = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);
    if (block_state.name.buf[0])
      conf->name = xstrdup(block_state.name.buf);

    conf->flags = block_state.flags.value;
    conf->port = block_state.port.value;

    conf_add_class_to_conf(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
#line 4956 "conf_parser.c"
    break;

  case 310: /* auth_user: USER '=' QSTRING ';'  */
#line 1595 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4965 "conf_parser.c"
    break;

  case 311: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1601 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4974 "conf_parser.c"
    break;

  case 312: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1607 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4983 "conf_parser.c"
    break;

  case 313: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1613 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4997 "conf_parser.c"
    break;

  case 314: /* $@14: %empty  */
#line 1624 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 5006 "conf_parser.c"
    break;

  case 318: /* auth_flags_item: EXCEED_LIMIT  */
#line 1631 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 5015 "conf_parser.c"
    break;

  case 319: /* auth_flags_item: KLINE_EXEMPT  */
#line 1635 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 5024 "conf_parser.c"
    break;

  case 320: /* auth_flags_item: XLINE_EXEMPT  */
#line 1639 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 5033 "conf_parser.c"
    break;

  case 321: /* auth_flags_item: NEED_IDENT  */
#line 1643 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 5042 "conf_parser.c"
    break;

  case 322: /* auth_flags_item: CAN_FLOOD  */
#line 1647 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 5051 "conf_parser.c"
    break;

  case 323: /* auth_flags_item: NO_TILDE  */
#line 1651 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 5060 "conf_parser.c"
    break;

  case 324: /* auth_flags_item: RESV_EXEMPT  */
#line 1655 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 5069 "conf_parser.c"
    break;

  case 325: /* auth_flags_item: T_WEBIRC  */
#line 1659 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 5078 "conf_parser.c"
    break;

  case 326: /* auth_flags_item: NEED_PASSWORD  */
#line 1663 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 5087 "conf_parser.c"
    break;

  case 327: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1669 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_hostname(yylval.string))
  {
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
    block_state.flags.value |= CONF_FLAGS_SPOOF_IP;
  }
  else
    ilog(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 5104 "conf_parser.c"
    break;

  case 328: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1683 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 5116 "conf_parser.c"
    break;

  case 329: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1692 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 5128 "conf_parser.c"
    break;

  case 330: /* $@15: %empty  */
#line 1705 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5140 "conf_parser.c"
    break;

  case 331: /* resv_entry: RESV $@15 '{' resv_items '}' ';'  */
#line 1712 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5151 "conf_parser.c"
    break;

  case 338: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1723 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5160 "conf_parser.c"
    break;

  case 339: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1729 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5169 "conf_parser.c"
    break;

  case 340: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1735 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 5178 "conf_parser.c"
    break;

  case 346: /* service_name: NAME '=' QSTRING ';'  */
#line 1750 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 5193 "conf_parser.c"
    break;

  case 347: /* $@16: %empty  */
#line 1766 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5209 "conf_parser.c"
    break;

  case 348: /* shared_entry: T_SHARED $@16 '{' shared_items '}' ';'  */
#line 1777 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 5224 "conf_parser.c"
    break;

  case 355: /* shared_name: NAME '=' QSTRING ';'  */
#line 1792 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5233 "conf_parser.c"
    break;

  case 356: /* shared_user: USER '=' QSTRING ';'  */
#line 1798 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
#line 5255 "conf_parser.c"
    break;

  case 357: /* $@17: %empty  */
#line 1817 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5264 "conf_parser.c"
    break;

  case 361: /* shared_type_item: KLINE  */
#line 1824 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5273 "conf_parser.c"
    break;

  case 362: /* shared_type_item: UNKLINE  */
#line 1828 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5282 "conf_parser.c"
    break;

  case 363: /* shared_type_item: T_DLINE  */
#line 1832 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5291 "conf_parser.c"
    break;

  case 364: /* shared_type_item: T_UNDLINE  */
#line 1836 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5300 "conf_parser.c"
    break;

  case 365: /* shared_type_item: XLINE  */
#line 1840 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5309 "conf_parser.c"
    break;

  case 366: /* shared_type_item: T_UNXLINE  */
#line 1844 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5318 "conf_parser.c"
    break;

  case 367: /* shared_type_item: RESV  */
#line 1848 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5327 "conf_parser.c"
    break;

  case 368: /* shared_type_item: T_UNRESV  */
#line 1852 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5336 "conf_parser.c"
    break;

  case 369: /* shared_type_item: T_LOCOPS  */
#line 1856 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5345 "conf_parser.c"
    break;

  case 370: /* shared_type_item: T_ALL  */
#line 1860 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5354 "conf_parser.c"
    break;

  case 371: /* $@18: %empty  */
#line 1870 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5368 "conf_parser.c"
    break;

  case 372: /* cluster_entry: T_CLUSTER $@18 '{' cluster_items '}' ';'  */
#line 1879 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5381 "conf_parser.c"
    break;

  case 378: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1892 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5390 "conf_parser.c"
    break;

  case 379: /* $@19: %empty  */
#line 1898 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5399 "conf_parser.c"
    break;

  case 383: /* cluster_type_item: KLINE  */
#line 1905 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5408 "conf_parser.c"
    break;

  case 384: /* cluster_type_item: UNKLINE  */
#line 1909 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5417 "conf_parser.c"
    break;

  case 385: /* cluster_type_item: T_DLINE  */
#line 1913 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5426 "conf_parser.c"
    break;

  case 386: /* cluster_type_item: T_UNDLINE  */
#line 1917 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5435 "conf_parser.c"
    break;

  case 387: /* cluster_type_item: XLINE  */
#line 1921 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5444 "conf_parser.c"
    break;

  case 388: /* cluster_type_item: T_UNXLINE  */
#line 1925 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5453 "conf_parser.c"
    break;

  case 389: /* cluster_type_item: RESV  */
#line 1929 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5462 "conf_parser.c"
    break;

  case 390: /* cluster_type_item: T_UNRESV  */
#line 1933 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5471 "conf_parser.c"
    break;

  case 391: /* cluster_type_item: T_LOCOPS  */
#line 1937 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5480 "conf_parser.c"
    break;

  case 392: /* cluster_type_item: T_ALL  */
#line 1941 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5489 "conf_parser.c"
    break;

  case 393: /* $@20: %empty  */
#line 1951 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5504 "conf_parser.c"
    break;

  case 394: /* connect_entry: CONNECT $@20 '{' connect_items '}' ';'  */
#line 1961 "conf_parser.y"
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
  conf->addr = xcalloc(sizeof(*conf->addr));
  conf->port = block_state.port.value;
  conf->timeout = block_state.timeout.value;
  conf->flags = block_state.flags.value;
  conf->aftype = block_state.aftype.value;
  conf->host = xstrdup(block_state.host.buf);
  conf->name = xstrdup(block_state.name.buf);
  conf->passwd = xstrdup(block_state.rpass.buf);
  conf->spasswd = xstrdup(block_state.spass.buf);

  if (block_state.cert.buf[0])
    conf->certfp = xstrdup(block_state.cert.buf);

  if (block_state.ciph.buf[0])
    conf->cipher_list = xstrdup(block_state.ciph.buf);

  dlinkMoveList(&block_state.leaf.list, &conf->leaf_list);
  dlinkMoveList(&block_state.hub.list, &conf->hub_list);

  if (block_state.bind.buf[0])
  {
    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(block_state.bind.buf, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server bind(%s)", block_state.bind.buf);
    else
    {
      assert(res);

      conf->bind = xcalloc(sizeof(*conf->bind));

      memcpy(conf->bind, res->ai_addr, res->ai_addrlen);
      conf->bind->ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  conf_dns_lookup(conf);
}
#line 5575 "conf_parser.c"
    break;

  case 413: /* connect_name: NAME '=' QSTRING ';'  */
#line 2047 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5584 "conf_parser.c"
    break;

  case 414: /* connect_host: HOST '=' QSTRING ';'  */
#line 2053 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5593 "conf_parser.c"
    break;

  case 415: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 2059 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5602 "conf_parser.c"
    break;

  case 416: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 2065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5611 "conf_parser.c"
    break;

  case 417: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2071 "conf_parser.y"
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
#line 5627 "conf_parser.c"
    break;

  case 418: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2084 "conf_parser.y"
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
#line 5643 "conf_parser.c"
    break;

  case 419: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5652 "conf_parser.c"
    break;

  case 420: /* connect_port: PORT '=' NUMBER ';'  */
#line 2103 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5661 "conf_parser.c"
    break;

  case 421: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5670 "conf_parser.c"
    break;

  case 422: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2113 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5679 "conf_parser.c"
    break;

  case 423: /* $@21: %empty  */
#line 2119 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5687 "conf_parser.c"
    break;

  case 427: /* connect_flags_item: AUTOCONN  */
#line 2125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5696 "conf_parser.c"
    break;

  case 428: /* connect_flags_item: T_TLS  */
#line 2129 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5705 "conf_parser.c"
    break;

  case 429: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2135 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5719 "conf_parser.c"
    break;

  case 430: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2146 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5728 "conf_parser.c"
    break;

  case 431: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2152 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5737 "conf_parser.c"
    break;

  case 432: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2158 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5746 "conf_parser.c"
    break;

  case 433: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2164 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5760 "conf_parser.c"
    break;

  case 434: /* $@22: %empty  */
#line 2179 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5769 "conf_parser.c"
    break;

  case 435: /* kill_entry: KILL $@22 '{' kill_items '}' ';'  */
#line 2183 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.user.buf[0] ||
      !block_state.host.buf[0])
    break;

  struct MaskItem *conf = conf_make(CONF_KLINE);
  conf->user = xstrdup(block_state.user.buf);
  conf->host = xstrdup(block_state.host.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
  add_conf_by_address(CONF_KLINE, conf);
}
#line 5792 "conf_parser.c"
    break;

  case 441: /* kill_user: USER '=' QSTRING ';'  */
#line 2206 "conf_parser.y"
{

  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
#line 5815 "conf_parser.c"
    break;

  case 442: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2226 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5824 "conf_parser.c"
    break;

  case 443: /* $@23: %empty  */
#line 2236 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5833 "conf_parser.c"
    break;

  case 444: /* deny_entry: DENY $@23 '{' deny_items '}' ';'  */
#line 2240 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  if (parse_netmask(block_state.addr.buf, NULL, NULL) != HM_HOST)
  {
    struct MaskItem *conf = conf_make(CONF_DLINE);
    conf->host = xstrdup(block_state.addr.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
    add_conf_by_address(CONF_DLINE, conf);
  }
}
#line 5857 "conf_parser.c"
    break;

  case 450: /* deny_ip: IP '=' QSTRING ';'  */
#line 2264 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5866 "conf_parser.c"
    break;

  case 451: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2270 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5875 "conf_parser.c"
    break;

  case 457: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2285 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (*yylval.string && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      struct MaskItem *conf = conf_make(CONF_EXEMPT);
      conf->host = xstrdup(yylval.string);

      add_conf_by_address(CONF_EXEMPT, conf);
    }
  }
}
#line 5892 "conf_parser.c"
    break;

  case 458: /* $@24: %empty  */
#line 2302 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5901 "conf_parser.c"
    break;

  case 459: /* gecos_entry: GECOS $@24 '{' gecos_items '}' ';'  */
#line 2306 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  struct GecosItem *gecos = gecos_make();
  gecos->mask = xstrdup(block_state.name.buf);

  if (block_state.rpass.buf[0])
    gecos->reason = xstrdup(block_state.rpass.buf);
  else
    gecos->reason = xstrdup(CONF_NOREASON);
}
#line 5921 "conf_parser.c"
    break;

  case 465: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2326 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5930 "conf_parser.c"
    break;

  case 466: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2332 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5939 "conf_parser.c"
    break;

  case 516: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2393 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5947 "conf_parser.c"
    break;

  case 517: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2398 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5955 "conf_parser.c"
    break;

  case 518: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2403 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5963 "conf_parser.c"
    break;

  case 519: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2408 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5971 "conf_parser.c"
    break;

  case 520: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2413 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5979 "conf_parser.c"
    break;

  case 521: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2418 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5987 "conf_parser.c"
    break;

  case 522: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2423 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5995 "conf_parser.c"
    break;

  case 523: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2428 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6003 "conf_parser.c"
    break;

  case 524: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2433 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6011 "conf_parser.c"
    break;

  case 525: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2438 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6019 "conf_parser.c"
    break;

  case 526: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2443 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 6027 "conf_parser.c"
    break;

  case 527: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2448 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 6035 "conf_parser.c"
    break;

  case 528: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2453 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6043 "conf_parser.c"
    break;

  case 529: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2458 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6051 "conf_parser.c"
    break;

  case 530: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2463 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6059 "conf_parser.c"
    break;

  case 531: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2468 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6067 "conf_parser.c"
    break;

  case 532: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2473 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6075 "conf_parser.c"
    break;

  case 533: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2478 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6083 "conf_parser.c"
    break;

  case 534: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2483 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6091 "conf_parser.c"
    break;

  case 535: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2488 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6099 "conf_parser.c"
    break;

  case 536: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2493 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6107 "conf_parser.c"
    break;

  case 537: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2498 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 6115 "conf_parser.c"
    break;

  case 538: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2503 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 6123 "conf_parser.c"
    break;

  case 539: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2508 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 6131 "conf_parser.c"
    break;

  case 540: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2513 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6139 "conf_parser.c"
    break;

  case 541: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2518 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 6147 "conf_parser.c"
    break;

  case 542: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2523 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 6155 "conf_parser.c"
    break;

  case 543: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2528 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6163 "conf_parser.c"
    break;

  case 544: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2533 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6171 "conf_parser.c"
    break;

  case 545: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2538 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6179 "conf_parser.c"
    break;

  case 546: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2543 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6187 "conf_parser.c"
    break;

  case 547: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2548 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6195 "conf_parser.c"
    break;

  case 548: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2553 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6203 "conf_parser.c"
    break;

  case 549: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2558 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6211 "conf_parser.c"
    break;

  case 550: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2563 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6219 "conf_parser.c"
    break;

  case 551: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2568 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6227 "conf_parser.c"
    break;

  case 552: /* general_disable_auth: DISABLE_AUTH '=' TBOOL ';'  */
#line 2573 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6235 "conf_parser.c"
    break;

  case 553: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2578 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6243 "conf_parser.c"
    break;

  case 554: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2583 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6251 "conf_parser.c"
    break;

  case 555: /* $@25: %empty  */
#line 2588 "conf_parser.y"
{
  ConfigGeneral.oper_umodes = 0;
}
#line 6259 "conf_parser.c"
    break;

  case 559: /* umode_oitem: BOT  */
#line 2594 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_BOT;
}
#line 6267 "conf_parser.c"
    break;

  case 560: /* umode_oitem: T_CCONN  */
#line 2597 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6275 "conf_parser.c"
    break;

  case 561: /* umode_oitem: T_DEAF  */
#line 2600 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6283 "conf_parser.c"
    break;

  case 562: /* umode_oitem: T_DEBUG  */
#line 2603 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6291 "conf_parser.c"
    break;

  case 563: /* umode_oitem: T_FLOOD  */
#line 2606 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FLOOD;
}
#line 6299 "conf_parser.c"
    break;

  case 564: /* umode_oitem: HIDDEN  */
#line 2609 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6307 "conf_parser.c"
    break;

  case 565: /* umode_oitem: HIDE_CHANS  */
#line 2612 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6315 "conf_parser.c"
    break;

  case 566: /* umode_oitem: HIDE_IDLE  */
#line 2615 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6323 "conf_parser.c"
    break;

  case 567: /* umode_oitem: T_SKILL  */
#line 2618 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6331 "conf_parser.c"
    break;

  case 568: /* umode_oitem: T_NCHANGE  */
#line 2621 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6339 "conf_parser.c"
    break;

  case 569: /* umode_oitem: T_REJ  */
#line 2624 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6347 "conf_parser.c"
    break;

  case 570: /* umode_oitem: T_SPY  */
#line 2627 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6355 "conf_parser.c"
    break;

  case 571: /* umode_oitem: T_EXTERNAL  */
#line 2630 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6363 "conf_parser.c"
    break;

  case 572: /* umode_oitem: T_SERVNOTICE  */
#line 2633 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6371 "conf_parser.c"
    break;

  case 573: /* umode_oitem: T_INVISIBLE  */
#line 2636 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6379 "conf_parser.c"
    break;

  case 574: /* umode_oitem: T_WALLOP  */
#line 2639 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6387 "conf_parser.c"
    break;

  case 575: /* umode_oitem: T_SOFTCALLERID  */
#line 2642 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6395 "conf_parser.c"
    break;

  case 576: /* umode_oitem: T_CALLERID  */
#line 2645 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6403 "conf_parser.c"
    break;

  case 577: /* umode_oitem: T_LOCOPS  */
#line 2648 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6411 "conf_parser.c"
    break;

  case 578: /* umode_oitem: T_NONONREG  */
#line 2651 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6419 "conf_parser.c"
    break;

  case 579: /* umode_oitem: T_FARCONNECT  */
#line 2654 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6427 "conf_parser.c"
    break;

  case 580: /* umode_oitem: EXPIRATION  */
#line 2657 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6435 "conf_parser.c"
    break;

  case 581: /* umode_oitem: T_SECUREONLY  */
#line 2660 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SECUREONLY;
}
#line 6443 "conf_parser.c"
    break;

  case 582: /* $@26: %empty  */
#line 2665 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6451 "conf_parser.c"
    break;

  case 586: /* umode_item: BOT  */
#line 2671 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_BOT;
}
#line 6459 "conf_parser.c"
    break;

  case 587: /* umode_item: T_CCONN  */
#line 2674 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6467 "conf_parser.c"
    break;

  case 588: /* umode_item: T_DEAF  */
#line 2677 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6475 "conf_parser.c"
    break;

  case 589: /* umode_item: T_DEBUG  */
#line 2680 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6483 "conf_parser.c"
    break;

  case 590: /* umode_item: T_FLOOD  */
#line 2683 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FLOOD;
}
#line 6491 "conf_parser.c"
    break;

  case 591: /* umode_item: T_SKILL  */
#line 2686 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6499 "conf_parser.c"
    break;

  case 592: /* umode_item: HIDDEN  */
#line 2689 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6507 "conf_parser.c"
    break;

  case 593: /* umode_item: HIDE_CHANS  */
#line 2692 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDECHANS;
}
#line 6515 "conf_parser.c"
    break;

  case 594: /* umode_item: HIDE_IDLE  */
#line 2695 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDEIDLE;
}
#line 6523 "conf_parser.c"
    break;

  case 595: /* umode_item: T_NCHANGE  */
#line 2698 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6531 "conf_parser.c"
    break;

  case 596: /* umode_item: T_REJ  */
#line 2701 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6539 "conf_parser.c"
    break;

  case 597: /* umode_item: T_SPY  */
#line 2704 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6547 "conf_parser.c"
    break;

  case 598: /* umode_item: T_EXTERNAL  */
#line 2707 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6555 "conf_parser.c"
    break;

  case 599: /* umode_item: T_SERVNOTICE  */
#line 2710 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6563 "conf_parser.c"
    break;

  case 600: /* umode_item: T_INVISIBLE  */
#line 2713 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6571 "conf_parser.c"
    break;

  case 601: /* umode_item: T_WALLOP  */
#line 2716 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6579 "conf_parser.c"
    break;

  case 602: /* umode_item: T_SOFTCALLERID  */
#line 2719 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6587 "conf_parser.c"
    break;

  case 603: /* umode_item: T_CALLERID  */
#line 2722 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6595 "conf_parser.c"
    break;

  case 604: /* umode_item: T_LOCOPS  */
#line 2725 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6603 "conf_parser.c"
    break;

  case 605: /* umode_item: T_NONONREG  */
#line 2728 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6611 "conf_parser.c"
    break;

  case 606: /* umode_item: T_FARCONNECT  */
#line 2731 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6619 "conf_parser.c"
    break;

  case 607: /* umode_item: EXPIRATION  */
#line 2734 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6627 "conf_parser.c"
    break;

  case 608: /* umode_item: T_SECUREONLY  */
#line 2737 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SECUREONLY;
}
#line 6635 "conf_parser.c"
    break;

  case 609: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2742 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6643 "conf_parser.c"
    break;

  case 610: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2747 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6651 "conf_parser.c"
    break;

  case 611: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2752 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6659 "conf_parser.c"
    break;

  case 612: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2757 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6667 "conf_parser.c"
    break;

  case 634: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2788 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6675 "conf_parser.c"
    break;

  case 635: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2793 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6684 "conf_parser.c"
    break;

  case 636: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2799 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6693 "conf_parser.c"
    break;

  case 637: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2805 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6701 "conf_parser.c"
    break;

  case 638: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2810 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6709 "conf_parser.c"
    break;

  case 639: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2815 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6717 "conf_parser.c"
    break;

  case 640: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2820 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6725 "conf_parser.c"
    break;

  case 641: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2825 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6733 "conf_parser.c"
    break;

  case 642: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2830 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6741 "conf_parser.c"
    break;

  case 643: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2835 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6749 "conf_parser.c"
    break;

  case 644: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2840 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6757 "conf_parser.c"
    break;

  case 645: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2845 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6765 "conf_parser.c"
    break;

  case 646: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2850 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6773 "conf_parser.c"
    break;

  case 647: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2855 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6781 "conf_parser.c"
    break;

  case 648: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2860 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6789 "conf_parser.c"
    break;

  case 649: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2865 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6797 "conf_parser.c"
    break;

  case 650: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2870 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6805 "conf_parser.c"
    break;

  case 664: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6814 "conf_parser.c"
    break;

  case 665: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2899 "conf_parser.y"
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
#line 6833 "conf_parser.c"
    break;

  case 666: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2915 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6845 "conf_parser.c"
    break;

  case 667: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2924 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6854 "conf_parser.c"
    break;

  case 668: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2930 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6863 "conf_parser.c"
    break;

  case 669: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2936 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6872 "conf_parser.c"
    break;

  case 670: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2942 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6884 "conf_parser.c"
    break;

  case 671: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2951 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6893 "conf_parser.c"
    break;

  case 672: /* serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'  */
#line 2957 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6902 "conf_parser.c"
    break;


#line 6906 "conf_parser.c"

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

