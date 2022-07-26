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
    T_SERVER = 442,                /* T_SERVER  */
    T_SERVICE = 443,               /* T_SERVICE  */
    T_SERVNOTICE = 444,            /* T_SERVNOTICE  */
    T_SET = 445,                   /* T_SET  */
    T_SHARED = 446,                /* T_SHARED  */
    T_SIZE = 447,                  /* T_SIZE  */
    T_SKILL = 448,                 /* T_SKILL  */
    T_SOFTCALLERID = 449,          /* T_SOFTCALLERID  */
    T_SPY = 450,                   /* T_SPY  */
    T_TARGET = 451,                /* T_TARGET  */
    T_TLS = 452,                   /* T_TLS  */
    T_UMODES = 453,                /* T_UMODES  */
    T_UNDLINE = 454,               /* T_UNDLINE  */
    T_UNLIMITED = 455,             /* T_UNLIMITED  */
    T_UNRESV = 456,                /* T_UNRESV  */
    T_UNXLINE = 457,               /* T_UNXLINE  */
    T_WALLOP = 458,                /* T_WALLOP  */
    T_WALLOPS = 459,               /* T_WALLOPS  */
    T_WEBIRC = 460,                /* T_WEBIRC  */
    TBOOL = 461,                   /* TBOOL  */
    THROTTLE_COUNT = 462,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 463,           /* THROTTLE_TIME  */
    TIMEOUT = 464,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 465,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 466, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 467,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 468,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 469, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 470,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 471, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 472,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 473,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 474,           /* TS_WARN_DELTA  */
    TWODOTS = 475,                 /* TWODOTS  */
    TYPE = 476,                    /* TYPE  */
    UNKLINE = 477,                 /* UNKLINE  */
    USE_LOGGING = 478,             /* USE_LOGGING  */
    USER = 479,                    /* USER  */
    VHOST = 480,                   /* VHOST  */
    VHOST6 = 481,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 482,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 483,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 484,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 485,                   /* XLINE  */
    XLINE_EXEMPT = 486,            /* XLINE_EXEMPT  */
    QSTRING = 487,                 /* QSTRING  */
    NUMBER = 488                   /* NUMBER  */
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
#define T_SERVER 442
#define T_SERVICE 443
#define T_SERVNOTICE 444
#define T_SET 445
#define T_SHARED 446
#define T_SIZE 447
#define T_SKILL 448
#define T_SOFTCALLERID 449
#define T_SPY 450
#define T_TARGET 451
#define T_TLS 452
#define T_UMODES 453
#define T_UNDLINE 454
#define T_UNLIMITED 455
#define T_UNRESV 456
#define T_UNXLINE 457
#define T_WALLOP 458
#define T_WALLOPS 459
#define T_WEBIRC 460
#define TBOOL 461
#define THROTTLE_COUNT 462
#define THROTTLE_TIME 463
#define TIMEOUT 464
#define TLS_CERTIFICATE_FILE 465
#define TLS_CERTIFICATE_FINGERPRINT 466
#define TLS_CIPHER_LIST 467
#define TLS_CIPHER_SUITES 468
#define TLS_CONNECTION_REQUIRED 469
#define TLS_DH_PARAM_FILE 470
#define TLS_MESSAGE_DIGEST_ALGORITHM 471
#define TLS_SUPPORTED_GROUPS 472
#define TS_MAX_DELTA 473
#define TS_WARN_DELTA 474
#define TWODOTS 475
#define TYPE 476
#define UNKLINE 477
#define USE_LOGGING 478
#define USER 479
#define VHOST 480
#define VHOST6 481
#define WARN_NO_CONNECT_BLOCK 482
#define WHOIS 483
#define WHOWAS_HISTORY_LENGTH 484
#define XLINE 485
#define XLINE_EXEMPT 486
#define QSTRING 487
#define NUMBER 488

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 132 "conf_parser.y"

  int number;
  char *string;

#line 700 "conf_parser.c"

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
  YYSYMBOL_T_SERVER = 187,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 188,                /* T_SERVICE  */
  YYSYMBOL_T_SERVNOTICE = 189,             /* T_SERVNOTICE  */
  YYSYMBOL_T_SET = 190,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 191,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 192,                   /* T_SIZE  */
  YYSYMBOL_T_SKILL = 193,                  /* T_SKILL  */
  YYSYMBOL_T_SOFTCALLERID = 194,           /* T_SOFTCALLERID  */
  YYSYMBOL_T_SPY = 195,                    /* T_SPY  */
  YYSYMBOL_T_TARGET = 196,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 197,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 198,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 199,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 200,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 201,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 202,                /* T_UNXLINE  */
  YYSYMBOL_T_WALLOP = 203,                 /* T_WALLOP  */
  YYSYMBOL_T_WALLOPS = 204,                /* T_WALLOPS  */
  YYSYMBOL_T_WEBIRC = 205,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 206,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 207,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 208,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 209,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 210,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 211, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 212,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 213,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 214,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 215,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 216, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 217,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 218,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 219,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 220,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 221,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 222,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 223,              /* USE_LOGGING  */
  YYSYMBOL_USER = 224,                     /* USER  */
  YYSYMBOL_VHOST = 225,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 226,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 227,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 228,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 229,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 230,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 231,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 232,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 233,                   /* NUMBER  */
  YYSYMBOL_234_ = 234,                     /* ';'  */
  YYSYMBOL_235_ = 235,                     /* '}'  */
  YYSYMBOL_236_ = 236,                     /* '{'  */
  YYSYMBOL_237_ = 237,                     /* '='  */
  YYSYMBOL_238_ = 238,                     /* ','  */
  YYSYMBOL_239_ = 239,                     /* ':'  */
  YYSYMBOL_YYACCEPT = 240,                 /* $accept  */
  YYSYMBOL_conf = 241,                     /* conf  */
  YYSYMBOL_conf_item = 242,                /* conf_item  */
  YYSYMBOL_timespec_ = 243,                /* timespec_  */
  YYSYMBOL_timespec = 244,                 /* timespec  */
  YYSYMBOL_sizespec_ = 245,                /* sizespec_  */
  YYSYMBOL_sizespec = 246,                 /* sizespec  */
  YYSYMBOL_modules_entry = 247,            /* modules_entry  */
  YYSYMBOL_modules_items = 248,            /* modules_items  */
  YYSYMBOL_modules_item = 249,             /* modules_item  */
  YYSYMBOL_modules_module = 250,           /* modules_module  */
  YYSYMBOL_modules_path = 251,             /* modules_path  */
  YYSYMBOL_serverinfo_entry = 252,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 253,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 254,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 255, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 256, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 257, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 258, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 259, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 260, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 261, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 262,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 263,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 264,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 265,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 266, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 267, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 268, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 269, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_hub = 270,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 271,              /* admin_entry  */
  YYSYMBOL_admin_items = 272,              /* admin_items  */
  YYSYMBOL_admin_item = 273,               /* admin_item  */
  YYSYMBOL_admin_name = 274,               /* admin_name  */
  YYSYMBOL_admin_email = 275,              /* admin_email  */
  YYSYMBOL_admin_description = 276,        /* admin_description  */
  YYSYMBOL_motd_entry = 277,               /* motd_entry  */
  YYSYMBOL_278_1 = 278,                    /* $@1  */
  YYSYMBOL_motd_items = 279,               /* motd_items  */
  YYSYMBOL_motd_item = 280,                /* motd_item  */
  YYSYMBOL_motd_mask = 281,                /* motd_mask  */
  YYSYMBOL_motd_file = 282,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 283,             /* pseudo_entry  */
  YYSYMBOL_284_2 = 284,                    /* $@2  */
  YYSYMBOL_pseudo_items = 285,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 286,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 287,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 288,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 289,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 290,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 291,            /* logging_entry  */
  YYSYMBOL_logging_items = 292,            /* logging_items  */
  YYSYMBOL_logging_item = 293,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 294,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 295,       /* logging_file_entry  */
  YYSYMBOL_296_3 = 296,                    /* $@3  */
  YYSYMBOL_logging_file_items = 297,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 298,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 299,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 300,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 301,        /* logging_file_type  */
  YYSYMBOL_302_4 = 302,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 303,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 304,               /* oper_entry  */
  YYSYMBOL_305_5 = 305,                    /* $@5  */
  YYSYMBOL_oper_items = 306,               /* oper_items  */
  YYSYMBOL_oper_item = 307,                /* oper_item  */
  YYSYMBOL_oper_name = 308,                /* oper_name  */
  YYSYMBOL_oper_user = 309,                /* oper_user  */
  YYSYMBOL_oper_password = 310,            /* oper_password  */
  YYSYMBOL_oper_whois = 311,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 312,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 313, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 314, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 315,               /* oper_class  */
  YYSYMBOL_oper_umodes = 316,              /* oper_umodes  */
  YYSYMBOL_317_6 = 317,                    /* $@6  */
  YYSYMBOL_oper_umodes_items = 318,        /* oper_umodes_items  */
  YYSYMBOL_oper_umodes_item = 319,         /* oper_umodes_item  */
  YYSYMBOL_oper_flags = 320,               /* oper_flags  */
  YYSYMBOL_321_7 = 321,                    /* $@7  */
  YYSYMBOL_oper_flags_items = 322,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 323,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 324,              /* class_entry  */
  YYSYMBOL_325_8 = 325,                    /* $@8  */
  YYSYMBOL_class_items = 326,              /* class_items  */
  YYSYMBOL_class_item = 327,               /* class_item  */
  YYSYMBOL_class_name = 328,               /* class_name  */
  YYSYMBOL_class_ping_time = 329,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 330, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 331, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 332,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 333,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 334,         /* class_max_number  */
  YYSYMBOL_class_sendq = 335,              /* class_sendq  */
  YYSYMBOL_class_recvq = 336,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 337,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 338,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 339,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 340,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 341,           /* class_max_idle  */
  YYSYMBOL_class_flags = 342,              /* class_flags  */
  YYSYMBOL_343_9 = 343,                    /* $@9  */
  YYSYMBOL_class_flags_items = 344,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 345,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 346,             /* listen_entry  */
  YYSYMBOL_347_10 = 347,                   /* $@10  */
  YYSYMBOL_listen_flags = 348,             /* listen_flags  */
  YYSYMBOL_349_11 = 349,                   /* $@11  */
  YYSYMBOL_listen_flags_items = 350,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 351,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 352,             /* listen_items  */
  YYSYMBOL_listen_item = 353,              /* listen_item  */
  YYSYMBOL_listen_port = 354,              /* listen_port  */
  YYSYMBOL_355_12 = 355,                   /* $@12  */
  YYSYMBOL_port_items = 356,               /* port_items  */
  YYSYMBOL_port_item = 357,                /* port_item  */
  YYSYMBOL_listen_address = 358,           /* listen_address  */
  YYSYMBOL_listen_host = 359,              /* listen_host  */
  YYSYMBOL_auth_entry = 360,               /* auth_entry  */
  YYSYMBOL_361_13 = 361,                   /* $@13  */
  YYSYMBOL_auth_items = 362,               /* auth_items  */
  YYSYMBOL_auth_item = 363,                /* auth_item  */
  YYSYMBOL_auth_user = 364,                /* auth_user  */
  YYSYMBOL_auth_passwd = 365,              /* auth_passwd  */
  YYSYMBOL_auth_class = 366,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 367,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 368,               /* auth_flags  */
  YYSYMBOL_369_14 = 369,                   /* $@14  */
  YYSYMBOL_auth_flags_items = 370,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 371,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 372,               /* auth_spoof  */
  YYSYMBOL_auth_redir_serv = 373,          /* auth_redir_serv  */
  YYSYMBOL_auth_redir_port = 374,          /* auth_redir_port  */
  YYSYMBOL_resv_entry = 375,               /* resv_entry  */
  YYSYMBOL_376_15 = 376,                   /* $@15  */
  YYSYMBOL_resv_items = 377,               /* resv_items  */
  YYSYMBOL_resv_item = 378,                /* resv_item  */
  YYSYMBOL_resv_mask = 379,                /* resv_mask  */
  YYSYMBOL_resv_reason = 380,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 381,              /* resv_exempt  */
  YYSYMBOL_service_entry = 382,            /* service_entry  */
  YYSYMBOL_service_items = 383,            /* service_items  */
  YYSYMBOL_service_item = 384,             /* service_item  */
  YYSYMBOL_service_name = 385,             /* service_name  */
  YYSYMBOL_shared_entry = 386,             /* shared_entry  */
  YYSYMBOL_387_16 = 387,                   /* $@16  */
  YYSYMBOL_shared_items = 388,             /* shared_items  */
  YYSYMBOL_shared_item = 389,              /* shared_item  */
  YYSYMBOL_shared_name = 390,              /* shared_name  */
  YYSYMBOL_shared_user = 391,              /* shared_user  */
  YYSYMBOL_shared_type = 392,              /* shared_type  */
  YYSYMBOL_393_17 = 393,                   /* $@17  */
  YYSYMBOL_shared_types = 394,             /* shared_types  */
  YYSYMBOL_shared_type_item = 395,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 396,            /* cluster_entry  */
  YYSYMBOL_397_18 = 397,                   /* $@18  */
  YYSYMBOL_cluster_items = 398,            /* cluster_items  */
  YYSYMBOL_cluster_item = 399,             /* cluster_item  */
  YYSYMBOL_cluster_name = 400,             /* cluster_name  */
  YYSYMBOL_cluster_type = 401,             /* cluster_type  */
  YYSYMBOL_402_19 = 402,                   /* $@19  */
  YYSYMBOL_cluster_types = 403,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 404,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 405,            /* connect_entry  */
  YYSYMBOL_406_20 = 406,                   /* $@20  */
  YYSYMBOL_connect_items = 407,            /* connect_items  */
  YYSYMBOL_connect_item = 408,             /* connect_item  */
  YYSYMBOL_connect_name = 409,             /* connect_name  */
  YYSYMBOL_connect_host = 410,             /* connect_host  */
  YYSYMBOL_connect_timeout = 411,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 412,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 413,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 414,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 415, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 416,             /* connect_port  */
  YYSYMBOL_connect_aftype = 417,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 418,            /* connect_flags  */
  YYSYMBOL_419_21 = 419,                   /* $@21  */
  YYSYMBOL_connect_flags_items = 420,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 421,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 422,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 423,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 424,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 425,            /* connect_class  */
  YYSYMBOL_connect_tls_cipher_list = 426,  /* connect_tls_cipher_list  */
  YYSYMBOL_kill_entry = 427,               /* kill_entry  */
  YYSYMBOL_428_22 = 428,                   /* $@22  */
  YYSYMBOL_kill_items = 429,               /* kill_items  */
  YYSYMBOL_kill_item = 430,                /* kill_item  */
  YYSYMBOL_kill_user = 431,                /* kill_user  */
  YYSYMBOL_kill_reason = 432,              /* kill_reason  */
  YYSYMBOL_deny_entry = 433,               /* deny_entry  */
  YYSYMBOL_434_23 = 434,                   /* $@23  */
  YYSYMBOL_deny_items = 435,               /* deny_items  */
  YYSYMBOL_deny_item = 436,                /* deny_item  */
  YYSYMBOL_deny_ip = 437,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 438,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 439,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 440,             /* exempt_items  */
  YYSYMBOL_exempt_item = 441,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 442,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 443,              /* gecos_entry  */
  YYSYMBOL_444_24 = 444,                   /* $@24  */
  YYSYMBOL_gecos_items = 445,              /* gecos_items  */
  YYSYMBOL_gecos_item = 446,               /* gecos_item  */
  YYSYMBOL_gecos_name = 447,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 448,             /* gecos_reason  */
  YYSYMBOL_general_entry = 449,            /* general_entry  */
  YYSYMBOL_general_items = 450,            /* general_items  */
  YYSYMBOL_general_item = 451,             /* general_item  */
  YYSYMBOL_general_away_count = 452,       /* general_away_count  */
  YYSYMBOL_general_away_time = 453,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 454,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 455, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 456, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 457,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 458,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 459,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 460,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 461, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 462, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 463,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 464,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 465, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 466,       /* general_max_accept  */
  YYSYMBOL_general_anti_spam_exit_message_time = 467, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 468,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 469,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 470, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 471, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 472, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 473, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 474, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 475, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 476, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 477, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 478, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 479,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 480,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 481, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 482, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 483,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 484,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 485, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 486,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 487,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_auth = 488,     /* general_disable_auth  */
  YYSYMBOL_general_throttle_count = 489,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 490,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 491,      /* general_oper_umodes  */
  YYSYMBOL_492_25 = 492,                   /* $@25  */
  YYSYMBOL_umode_oitems = 493,             /* umode_oitems  */
  YYSYMBOL_umode_oitem = 494,              /* umode_oitem  */
  YYSYMBOL_general_oper_only_umodes = 495, /* general_oper_only_umodes  */
  YYSYMBOL_496_26 = 496,                   /* $@26  */
  YYSYMBOL_umode_items = 497,              /* umode_items  */
  YYSYMBOL_umode_item = 498,               /* umode_item  */
  YYSYMBOL_general_min_nonwildcard = 499,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 500, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 501, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 502, /* general_default_floodtime  */
  YYSYMBOL_channel_entry = 503,            /* channel_entry  */
  YYSYMBOL_channel_items = 504,            /* channel_items  */
  YYSYMBOL_channel_item = 505,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 506,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 507,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 508,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 509, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 510, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 511, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 512, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 513, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 514, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 515, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 516, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 517,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 518,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 519,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 520,   /* channel_max_bans_large  */
  YYSYMBOL_channel_default_join_flood_count = 521, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 522, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 523,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 524,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 525,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 526, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 527, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 528, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 529, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 530,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 531, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 532,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 533,        /* serverhide_hidden  */
  YYSYMBOL_serverhide_hide_server_ips = 534 /* serverhide_hide_server_ips  */
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
#define YYLAST   1257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  240
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  295
/* YYNRULES -- Number of rules.  */
#define YYNRULES  669
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1320

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   488


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
       2,     2,     2,     2,   238,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   239,   234,
       2,   237,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   236,     2,   235,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   367,   367,   368,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   398,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   409,   409,
     410,   411,   412,   413,   420,   422,   422,   423,   423,   423,
     425,   431,   441,   443,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   463,   472,   481,   490,   499,   508,   517,   526,
     541,   556,   566,   580,   589,   612,   635,   658,   668,   670,
     670,   671,   672,   673,   674,   676,   685,   694,   708,   707,
     725,   725,   726,   726,   726,   728,   734,   745,   744,   763,
     763,   764,   764,   764,   764,   764,   766,   772,   778,   784,
     806,   807,   807,   809,   809,   810,   812,   819,   819,   832,
     833,   835,   835,   836,   836,   838,   846,   849,   855,   854,
     860,   864,   868,   872,   876,   880,   884,   888,   899,   898,
     961,   961,   962,   963,   964,   965,   966,   967,   968,   969,
     970,   971,   972,   974,   980,   986,   992,   998,  1009,  1015,
    1026,  1033,  1032,  1038,  1038,  1039,  1043,  1047,  1051,  1055,
    1059,  1063,  1067,  1071,  1075,  1079,  1083,  1087,  1091,  1095,
    1099,  1103,  1107,  1111,  1115,  1119,  1123,  1130,  1129,  1135,
    1135,  1136,  1140,  1144,  1148,  1152,  1156,  1160,  1164,  1168,
    1172,  1176,  1180,  1184,  1188,  1192,  1196,  1200,  1204,  1208,
    1212,  1216,  1220,  1224,  1228,  1232,  1236,  1240,  1244,  1248,
    1259,  1258,  1314,  1314,  1315,  1316,  1317,  1318,  1319,  1320,
    1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,  1329,  1330,
    1332,  1338,  1344,  1350,  1356,  1362,  1368,  1374,  1380,  1387,
    1393,  1399,  1405,  1414,  1424,  1423,  1429,  1429,  1430,  1434,
    1445,  1444,  1451,  1450,  1455,  1455,  1456,  1460,  1464,  1468,
    1472,  1478,  1478,  1479,  1479,  1479,  1479,  1479,  1481,  1481,
    1483,  1483,  1485,  1498,  1515,  1521,  1532,  1531,  1578,  1578,
    1579,  1580,  1581,  1582,  1583,  1584,  1585,  1586,  1587,  1589,
    1595,  1601,  1607,  1619,  1618,  1624,  1624,  1625,  1629,  1633,
    1637,  1641,  1645,  1649,  1653,  1657,  1663,  1677,  1686,  1700,
    1699,  1714,  1714,  1715,  1715,  1715,  1715,  1717,  1723,  1729,
    1739,  1741,  1741,  1742,  1742,  1744,  1761,  1760,  1783,  1783,
    1784,  1784,  1784,  1784,  1786,  1792,  1812,  1811,  1817,  1817,
    1818,  1822,  1826,  1830,  1834,  1838,  1842,  1846,  1850,  1854,
    1865,  1864,  1883,  1883,  1884,  1884,  1884,  1886,  1893,  1892,
    1898,  1898,  1899,  1903,  1907,  1911,  1915,  1919,  1923,  1927,
    1931,  1935,  1946,  1945,  2023,  2023,  2024,  2025,  2026,  2027,
    2028,  2029,  2030,  2031,  2032,  2033,  2034,  2035,  2036,  2037,
    2038,  2039,  2041,  2047,  2053,  2059,  2065,  2078,  2091,  2097,
    2103,  2107,  2114,  2113,  2118,  2118,  2119,  2123,  2129,  2140,
    2146,  2152,  2158,  2174,  2173,  2197,  2197,  2198,  2198,  2198,
    2200,  2220,  2231,  2230,  2255,  2255,  2256,  2256,  2256,  2258,
    2264,  2274,  2276,  2276,  2277,  2277,  2279,  2297,  2296,  2317,
    2317,  2318,  2318,  2318,  2320,  2326,  2336,  2338,  2338,  2339,
    2340,  2341,  2342,  2343,  2344,  2345,  2346,  2347,  2348,  2349,
    2350,  2351,  2352,  2353,  2354,  2355,  2356,  2357,  2358,  2359,
    2360,  2361,  2362,  2363,  2364,  2365,  2366,  2367,  2368,  2369,
    2370,  2371,  2372,  2373,  2374,  2375,  2376,  2377,  2378,  2379,
    2380,  2381,  2382,  2383,  2384,  2387,  2392,  2397,  2402,  2407,
    2412,  2417,  2422,  2427,  2432,  2437,  2442,  2447,  2452,  2457,
    2462,  2467,  2472,  2477,  2482,  2487,  2492,  2497,  2502,  2507,
    2512,  2517,  2522,  2527,  2532,  2537,  2542,  2547,  2552,  2557,
    2562,  2567,  2572,  2577,  2583,  2582,  2587,  2587,  2588,  2591,
    2594,  2597,  2600,  2603,  2606,  2609,  2612,  2615,  2618,  2621,
    2624,  2627,  2630,  2633,  2636,  2639,  2642,  2645,  2648,  2651,
    2657,  2656,  2661,  2661,  2662,  2665,  2668,  2671,  2674,  2677,
    2680,  2683,  2686,  2689,  2692,  2695,  2698,  2701,  2704,  2707,
    2710,  2713,  2716,  2719,  2722,  2725,  2730,  2735,  2740,  2745,
    2754,  2756,  2756,  2757,  2758,  2759,  2760,  2761,  2762,  2763,
    2764,  2765,  2766,  2767,  2768,  2769,  2770,  2771,  2772,  2773,
    2774,  2776,  2781,  2787,  2793,  2798,  2803,  2808,  2813,  2818,
    2823,  2828,  2833,  2838,  2843,  2848,  2853,  2858,  2867,  2869,
    2869,  2870,  2871,  2872,  2873,  2874,  2875,  2876,  2877,  2878,
    2879,  2881,  2887,  2903,  2912,  2918,  2924,  2930,  2939,  2945
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
  "T_REJ", "T_RESTART", "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET",
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

#define YYPACT_NINF (-979)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -979,   878,  -979,  -230,  -201,  -196,  -979,  -979,  -979,  -194,
    -979,  -193,  -979,  -979,  -979,  -186,  -979,  -979,  -979,  -175,
    -154,  -979,  -152,  -979,  -151,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,   339,  1004,  -149,  -139,  -137,    24,  -115,   409,  -113,
     -77,   -70,    17,   -57,   -56,   -50,   763,   542,   -47,   108,
     -41,    55,   -23,  -181,   -21,   -20,   -17,     5,  -979,  -979,
    -979,  -979,  -979,   -12,    -9,    -8,    -6,    -2,    47,    52,
      59,    61,    62,    64,    72,    76,    79,    81,    87,    96,
     155,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,   895,
     654,    23,  -979,   102,    20,  -979,  -979,    13,  -979,   104,
     106,   115,   116,   119,   120,   125,   126,   128,   130,   131,
     132,   133,   137,   139,   140,   143,   144,   145,   152,   156,
     157,   158,   162,  -979,  -979,   163,   164,   165,   166,   167,
     170,   171,   174,   177,   180,   186,   193,   194,   195,   202,
     204,   213,   215,   217,    53,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,   275,    35,   313,  -134,   218,   221,    14,  -979,  -979,
    -979,    48,   314,   292,  -979,   223,   224,   225,   226,   227,
     228,   240,   242,   246,    15,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,    60,   247,   249,   250,   253,
     255,   258,   260,   261,   263,   264,   271,   272,   276,   278,
     279,   281,    95,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
      71,   248,   283,    16,  -979,  -979,  -979,   280,   191,  -979,
     285,    30,  -979,  -979,    57,  -979,   160,   274,   287,   289,
    -979,   291,   302,   331,   334,   335,   346,   320,   302,   302,
     302,   321,   302,   302,   322,   323,   324,   327,   336,  -979,
     337,   340,   342,   343,  -979,   344,   345,   349,   351,   352,
     353,   354,   355,   357,   358,   359,   245,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,   364,   367,   369,   370,   371,   372,   373,
    -979,   374,   375,   377,   381,   382,   383,   388,   389,   282,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,   392,   395,    19,
    -979,  -979,  -979,   402,   399,  -979,  -979,   398,   406,    21,
    -979,  -979,  -979,   440,   302,   341,   302,   302,   441,   350,
     302,   443,   417,   420,   448,   450,   302,   425,   432,   433,
     435,   438,   302,   439,   442,   447,   467,   444,   445,   470,
     302,   302,   479,   480,   455,   483,   484,   487,   488,   489,
     491,   493,   468,   302,   302,   302,   496,   471,   469,  -979,
     472,   473,   478,  -979,   482,   490,   492,   494,   497,   198,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
     498,   499,    38,  -979,  -979,  -979,   474,   500,   502,  -979,
     504,  -979,    33,  -979,  -979,  -979,  -979,  -979,   475,   485,
     508,  -979,   509,   507,   511,    22,  -979,  -979,  -979,   512,
     513,   514,  -979,   516,   519,  -979,   525,   526,   528,   529,
     214,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,   515,   530,   532,   535,    40,  -979,  -979,  -979,
    -979,   518,   522,   302,   501,   524,   541,   539,   568,   571,
     544,  -979,  -979,   551,   554,   582,   557,   558,   561,   563,
     564,   565,   569,   572,   573,   577,   578,   579,   587,   586,
    -979,   591,   566,  -979,    31,  -979,  -979,  -979,  -979,   615,
     592,  -979,   365,   593,   594,   597,   600,   602,    18,  -979,
    -979,  -979,  -979,  -979,   598,   607,  -979,   608,   610,  -979,
     611,     6,  -979,  -979,  -979,  -979,   616,   618,   619,  -979,
     620,   407,   622,   623,   624,   628,   630,   633,   634,   636,
     637,   638,   639,   640,   641,   651,   653,   655,  -979,  -979,
     657,   659,   302,   612,   664,   302,   667,   302,   670,   671,
     672,   673,   302,   678,   678,   681,  -979,  -979,   680,  -148,
     684,   712,   688,   689,   685,   691,   693,   694,   696,   697,
     302,   700,   701,   692,  -979,   702,   703,   704,  -979,   705,
    -979,   708,   709,   710,  -979,   711,   713,   716,   717,   718,
     720,   721,   722,   723,   724,   725,   726,   727,   728,   730,
     731,   732,   734,   735,   736,   737,   738,   739,   740,   613,
     666,   741,   742,   743,   744,   745,   746,   747,   750,   753,
     754,   755,   756,   757,   759,   760,   762,   764,   765,   766,
    -979,  -979,   770,   797,   699,   772,   715,   774,   775,   776,
     778,  -979,   782,   783,   784,  -979,  -979,   785,   787,   706,
     789,   786,  -979,   790,   793,  -979,  -979,   791,   796,   795,
    -979,  -979,   798,   810,   794,   802,   803,   799,   805,   832,
     807,   812,   808,  -979,  -979,   816,   817,   818,   819,  -979,
     820,   821,   823,   824,   825,   826,   828,   829,   830,  -979,
     831,   833,   834,   840,   841,   842,   843,   844,   846,   847,
     848,   849,   850,   854,   855,   856,  -979,  -979,   859,   814,
     861,  -979,   863,  -979,    82,  -979,   866,   867,   868,   869,
     870,  -979,   871,  -979,  -979,   874,   815,   875,   876,  -979,
    -979,  -979,  -979,  -979,   302,   302,   302,   302,   302,   302,
     302,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,   877,
     879,   880,   -55,   881,   882,   883,   884,   885,   886,   887,
     888,   889,    34,   890,   891,  -979,   892,   893,   894,   896,
     897,   898,   899,    29,   900,   901,   902,   903,   904,   905,
     906,   907,  -979,   908,   909,  -979,  -979,   910,   911,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -208,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -205,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,   912,   913,   368,   914,   915,   916,   917,   918,  -979,
     919,   920,  -979,   921,   922,   269,   356,   606,  -979,  -979,
    -979,  -979,   923,   924,  -979,   925,   926,   510,   927,   928,
     714,   929,   930,   931,   932,  -979,   933,   934,   935,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,   936,   401,  -979,  -979,   937,
     865,   872,  -979,    56,  -979,  -979,  -979,  -979,   938,   939,
     940,   941,  -979,  -979,   942,   462,   943,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -183,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,   678,   678,   678,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -167,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,   613,  -979,   666,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -157,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -136,  -979,   945,   789,   946,  -979,  -979,  -979,
    -979,  -979,  -979,   466,  -979,   698,   707,  -979,  -979,   864,
     873,  -979,  -979,   944,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,   -99,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,   -81,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,   -62,  -979,  -979,   947,  -189,   948,   950,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,   -53,  -979,  -979,  -979,   -55,
    -979,  -979,  -979,  -979,    29,  -979,  -979,  -979,   368,  -979,
     269,  -979,  -979,  -979,   588,   973,   614,   994,   809,  1048,
    -979,   510,  -979,   714,  -979,   401,   952,   953,   954,   229,
    -979,  -979,   462,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,   955,  -979,  -979
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   230,   392,   442,     0,
     457,     0,   296,   433,   270,     0,    98,   148,   329,     0,
       0,   370,     0,   107,     0,   346,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      93,    92,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   612,   627,   628,   629,   626,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   613,   614,   624,   625,     0,
       0,     0,   455,     0,     0,   453,   454,     0,   514,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   580,   554,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   468,   469,   470,   512,   476,
     513,   507,   508,   509,   510,   480,   471,   472,   473,   474,
     475,   477,   478,   479,   481,   482,   511,   486,   487,   488,
     489,   485,   484,   490,   497,   498,   491,   492,   493,   483,
     495,   505,   506,   503,   504,   496,   494,   501,   502,   499,
     500,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,     0,     0,     0,   660,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   650,   651,   652,   653,   654,
     655,   656,   658,   657,   659,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    67,    65,    63,    68,    69,    70,
      64,    55,    66,    57,    58,    59,    60,    61,    62,    56,
       0,     0,     0,     0,   122,   123,   124,     0,     0,   344,
       0,     0,   342,   343,     0,    94,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   611,
       0,     0,     0,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,   237,
     239,   240,   241,   242,   243,   244,   245,   235,   236,   238,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     395,   396,   397,   398,   399,   400,   401,   402,   404,   403,
     406,   410,   407,   408,   409,   405,   448,     0,     0,     0,
     445,   446,   447,     0,     0,   452,   463,     0,     0,     0,
     460,   461,   462,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   467,
       0,     0,     0,   313,     0,     0,     0,     0,     0,     0,
     299,   300,   301,   302,   307,   303,   304,   305,   306,   439,
       0,     0,     0,   436,   437,   438,     0,     0,     0,   272,
       0,   284,     0,   282,   283,   285,   286,    49,     0,     0,
       0,    45,     0,     0,     0,     0,   101,   102,   103,     0,
       0,     0,   197,     0,     0,   171,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   158,   159,   160,   157,
     156,   161,     0,     0,     0,     0,     0,   332,   333,   334,
     335,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   649,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,   378,     0,   373,   374,   375,   125,     0,
       0,   121,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   113,   112,   114,     0,     0,   341,     0,     0,   356,
       0,     0,   349,   350,   351,   352,     0,     0,     0,    88,
       0,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   610,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,   411,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   394,     0,     0,     0,   444,     0,
     451,     0,     0,     0,   459,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     466,   308,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   298,     0,     0,     0,   435,   287,     0,     0,     0,
       0,     0,   281,     0,     0,    44,   104,     0,     0,     0,
     100,   162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   336,     0,     0,     0,     0,   331,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   648,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,   376,     0,     0,
       0,   372,     0,   120,     0,   115,     0,     0,     0,     0,
       0,   109,     0,   340,   353,     0,     0,     0,     0,   348,
      97,    96,    95,   646,    28,    28,    28,    28,    28,    28,
      28,    30,    29,   647,   634,   633,   631,   632,   635,   636,
     637,   638,   639,   640,   641,   644,   645,   642,   643,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   393,     0,     0,   443,   456,     0,     0,   458,
     526,   530,   515,   516,   543,   519,   608,   609,   551,   520,
     521,   525,   533,   524,   522,   523,   529,   517,   528,   527,
     549,   606,   607,   547,   584,   605,   590,   591,   592,   601,
     585,   586,   587,   596,   604,   588,   598,   602,   593,   603,
     594,   597,   589,   600,   595,   599,     0,   583,   558,   579,
     563,   564,   565,   575,   559,   560,   561,   570,   578,   562,
     572,   576,   567,   577,   568,   571,   566,   574,   569,   573,
       0,   557,   544,   542,   545,   550,   546,   548,   535,   541,
     540,   536,   537,   538,   539,   552,   553,   532,   531,   534,
     518,     0,     0,     0,     0,     0,     0,     0,     0,   297,
       0,     0,   434,     0,     0,     0,   292,   288,   291,   271,
      50,    51,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   330,
     664,   661,   662,   663,   668,   667,   669,   665,   666,    84,
      81,    87,    80,    85,    86,    79,    83,    82,    73,    72,
      75,    76,    74,    77,    78,     0,     0,   371,   126,     0,
       0,     0,   138,     0,   130,   131,   133,   132,     0,     0,
       0,     0,   108,   345,     0,     0,     0,   347,    31,    32,
      33,    34,    35,    36,    37,   259,   260,   254,   269,   268,
       0,   267,   255,   263,   256,   262,   250,   261,   253,   252,
     251,    38,    38,    38,    40,    39,   257,   258,   417,   420,
     421,   431,   428,   413,   429,   426,   427,     0,   425,   430,
     412,   419,   416,   415,   414,   418,   432,   449,   450,   464,
     465,   581,     0,   555,     0,   311,   312,   321,   317,   318,
     320,   325,   322,   323,   324,   319,     0,   316,   310,   328,
     327,   326,   309,   441,   440,   295,   294,   279,   280,   277,
     278,   276,     0,   275,     0,     0,     0,   105,   106,   170,
     167,   217,   229,   204,   213,     0,   202,   207,   223,     0,
     216,   221,   227,   206,   209,   218,   220,   224,   214,   222,
     210,   228,   212,   219,   208,   211,     0,   200,   163,   165,
     175,   196,   180,   181,   182,   192,   176,   177,   178,   187,
     195,   179,   189,   193,   184,   194,   185,   188,   183,   191,
     186,   190,     0,   174,   168,   169,   164,   166,   339,   337,
     338,   377,   382,   388,   391,   384,   390,   385,   389,   387,
     383,   386,     0,   381,   134,     0,     0,     0,     0,   129,
     117,   116,   118,   119,   354,   360,   366,   369,   362,   368,
     363,   367,   365,   361,   364,     0,   359,   355,   265,     0,
      41,    42,    43,   423,     0,   582,   556,   314,     0,   273,
       0,   293,   290,   289,     0,     0,     0,     0,     0,     0,
     198,     0,   172,     0,   379,     0,     0,     0,     0,     0,
     128,   357,     0,   266,   424,   315,   274,   203,   226,   201,
     225,   215,   205,   199,   173,   380,   135,   137,   136,   146,
     145,   141,   143,   147,   144,   140,   142,     0,   358,   139
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -979,  -979,  -979,  -357,  -310,  -978,  -643,  -979,  -979,   963,
    -979,  -979,  -979,  -979,   949,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  1105,  -979,  -979,  -979,  -979,  -979,  -979,
     686,  -979,  -979,  -979,  -979,  -979,   604,  -979,  -979,  -979,
    -979,  -979,  -979,   951,  -979,  -979,  -979,  -979,   141,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,   675,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,   -90,
    -979,  -979,  -979,   -85,  -979,  -979,  -979,   851,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,   -61,  -979,  -979,  -979,  -979,
    -979,   -71,  -979,   719,  -979,  -979,  -979,    45,  -979,  -979,
    -979,  -979,  -979,   733,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,   -67,  -979,  -979,  -979,  -979,  -979,  -979,   668,  -979,
    -979,  -979,  -979,  -979,   956,  -979,  -979,  -979,  -979,   605,
    -979,  -979,  -979,  -979,  -979,   -89,  -979,  -979,  -979,   631,
    -979,  -979,  -979,  -979,   -78,  -979,  -979,  -979,   835,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,   -54,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
     748,  -979,  -979,  -979,  -979,  -979,   813,  -979,  -979,  -979,
    -979,  1084,  -979,  -979,  -979,  -979,   800,  -979,  -979,  -979,
    -979,  1039,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,    91,  -979,  -979,  -979,    94,  -979,
    -979,  -979,  -979,  -979,  -979,  1117,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,   974,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    26,   831,   832,  1094,  1095,    27,   227,   228,
     229,   230,    28,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,    29,    77,    78,    79,    80,    81,    30,    63,   505,
     506,   507,   508,    31,    70,   588,   589,   590,   591,   592,
     593,    32,   293,   294,   295,   296,   297,  1053,  1054,  1055,
    1056,  1057,  1237,  1317,    33,    64,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   757,  1212,  1213,
     531,   754,  1186,  1187,    34,    53,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   633,  1080,  1081,    35,    61,   491,   739,
    1152,  1153,   492,   493,   494,  1156,   997,   998,   495,   496,
      36,    59,   469,   470,   471,   472,   473,   474,   475,   724,
    1136,  1137,   476,   477,   478,    37,    65,   536,   537,   538,
     539,   540,    38,   301,   302,   303,    39,    72,   601,   602,
     603,   604,   605,   816,  1255,  1256,    40,    68,   574,   575,
     576,   577,   799,  1232,  1233,    41,    54,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   654,
    1107,  1108,   391,   392,   393,   394,   395,    42,    60,   482,
     483,   484,   485,    43,    55,   399,   400,   401,   402,    44,
     124,   125,   126,    45,    57,   409,   410,   411,   412,    46,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   438,   960,   961,   216,   437,   936,   937,   217,
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
     863,   864,   612,  1078,    49,    50,    73,   597,   618,   619,
     620,  1287,   622,   623,   406,   224,   234,   291,   224,   583,
     396,   122,   406,   502,   396,   122,  1121,   867,   868,  1123,
    1122,   299,   571,  1124,   486,    51,   479,  1105,    74,   479,
      52,   532,    56,    58,   862,    75,  1091,  1092,  1093,   502,
      62,  1258,   235,   305,   128,  1259,   299,  1049,   597,   129,
     130,    66,   131,   132,   236,   237,   238,  1263,   133,   239,
     240,  1264,   571,  1079,   241,   242,   243,  1267,   134,   135,
     136,  1268,    67,  1049,    69,    71,   533,   119,   137,   397,
     123,   138,   139,   397,   123,   487,   255,   120,  1269,   121,
     497,   140,  1270,   488,   676,   489,   678,   679,   503,   291,
     682,    76,   598,  1260,  1261,  1262,   688,   225,   141,   407,
     225,   127,   694,   221,   584,   256,   534,   407,   257,   142,
     702,   703,   143,   144,   503,  1280,   300,   572,   226,  1281,
     145,   226,   408,   715,   716,   717,   146,   147,   398,   148,
     408,   149,   398,  1282,   150,   151,    82,  1283,   258,   222,
     490,   300,  1050,   598,   480,   152,   223,   480,   259,   535,
     153,   154,  1284,   155,   156,   157,  1285,   572,   158,   231,
     232,  1291,   585,    83,    84,  1292,   233,  -127,  1050,   290,
     260,    85,   583,   504,   261,   298,    86,    87,    88,   460,
     586,   262,   159,   160,   263,   264,   161,   162,   163,   164,
     165,   166,   167,   304,   587,   509,   306,   307,   461,   504,
     308,    89,    90,    91,    92,   311,  1106,   599,   312,   313,
     600,   314,   265,   772,   510,   315,    93,    94,    95,   292,
     309,   818,   462,    96,    97,    98,   330,    99,  1051,   500,
     550,   580,   573,   810,   667,   404,   673,   749,   511,   481,
     168,   169,   481,   331,   332,   595,   800,   862,   741,   333,
     463,   170,   171,   734,  1051,   768,   460,  1052,   599,  -127,
     172,   600,   173,   363,   316,   364,   512,   365,   458,   317,
    1147,  1238,   573,   532,   552,   461,   318,   584,   319,   320,
    1148,   321,   366,  1052,  1309,   266,  1310,   267,   268,   322,
     269,   270,   271,   323,   486,   509,   324,   334,   325,   462,
     513,   464,   851,  1149,   326,   854,   367,   856,   465,   466,
     569,   292,   861,   327,   510,   335,   336,   514,   533,   403,
      73,   413,   337,   414,   368,   338,   369,   463,  1311,   467,
     879,   339,   415,   416,   370,   585,   417,   418,   511,   340,
     341,   342,   419,   420,  1312,   421,   371,   422,   423,   424,
     425,   343,    74,   586,   426,   487,   427,   428,   534,    75,
     429,   430,   431,   488,  1127,   489,   512,   587,   372,   432,
     328,   344,   606,   433,   434,   435,  1313,  1314,   464,   436,
     439,   440,   441,   442,   443,   465,   466,   444,   445,   373,
     128,   446,   515,  1128,   447,   129,   130,   448,   131,   132,
     513,   535,   468,   449,   133,   516,   467,   374,   517,   345,
     450,   451,   452,   730,   134,   135,   136,   514,   518,   453,
     490,   454,   519,   375,   137,    76,  1129,   138,   139,   762,
     455,   582,   456,  1315,   457,   498,  1150,   140,   499,  1316,
     541,   542,   543,   544,   545,   546,  1151,  1068,  1069,  1070,
    1071,  1072,  1073,  1074,   141,  1130,  1131,   547,  1222,   548,
     645,  1132,   578,   549,   553,   142,   554,   555,   143,   144,
     556,   376,   557,   377,   378,   558,   145,   559,   560,   468,
     561,   562,   146,   147,  1133,   148,   607,   149,   563,   564,
     150,   151,   515,   565,  1161,   566,   567,   663,   568,   608,
     579,   152,   594,   609,   610,   516,   153,   154,   517,   155,
     156,   157,  1162,  1163,   158,   611,  1223,   613,   518,  1245,
     614,   615,   519,   255,  1164,   824,   825,   826,   827,   828,
     829,   830,   616,   617,   621,   624,   625,   626,   159,   160,
     627,  1224,   161,   162,   163,   164,   165,   166,   167,  1225,
     628,   629,   256,  1134,   677,   257,  1154,   630,  1226,   631,
     632,   634,   635,   681,  1165,  1166,   636,  1167,   637,   638,
     639,   640,   641,  1288,   642,   643,   644,  1246,   647,  1135,
    1227,   804,  1228,  1229,   648,   258,   649,   650,   651,   652,
     653,   655,   656,  1168,   657,   259,   168,   169,   658,   659,
     660,  1169,  1247,  1230,   914,   661,   662,   170,   171,   665,
    1248,  1231,   666,   670,   669,   671,   172,   260,   173,  1249,
     611,   261,  1170,   672,  1171,  1172,   675,   680,   262,   683,
     684,   263,   264,   685,   686,   363,   687,   364,   689,   365,
     915,  1250,  1173,  1251,  1252,   690,   691,   916,   692,   917,
     918,   693,   695,   698,   366,   696,   701,   938,  1174,   265,
     697,   699,   700,  1175,  1253,   704,   705,  1176,   706,   707,
     708,  1177,  1254,   709,   710,   711,  1178,   712,   367,   713,
    1179,   714,   718,   720,   719,  1274,   721,   743,   736,  1180,
     722,  1181,  1182,   939,  1183,   723,   368,   744,   369,   725,
     940,  1297,   941,   942,   770,  1190,   370,   726,   771,   727,
     774,   728,  1184,   773,   729,   732,   733,   737,   371,   738,
    1185,   740,   745,   746,   747,   776,   751,  1299,   748,   764,
     752,   753,   266,   755,   267,   268,   756,   269,   270,   271,
     372,  1191,   758,   759,   234,   760,   761,   765,  1192,   766,
    1193,  1194,   767,   775,   777,   919,   920,   778,   779,   921,
     922,   373,   923,   924,   780,   925,   781,   926,   782,   783,
     927,   784,   928,   929,   785,   786,   787,   788,   930,   374,
     235,   789,   931,   798,   790,   791,   932,   933,   934,   792,
     793,   794,   236,   237,   238,   375,   935,   239,   240,   795,
     796,   802,   241,   242,   243,   797,   803,   805,   943,   944,
     812,   806,   945,   946,   807,   947,   948,   808,   949,   809,
     950,   813,   814,   951,  1155,   952,   953,   815,   817,   852,
     820,   954,   821,   822,   823,   955,   833,   834,   835,   956,
     957,   958,   836,   376,   837,   377,   378,   838,   839,   959,
     840,   841,   842,   843,   844,   845,  1195,  1196,     2,     3,
    1197,  1198,     4,  1199,  1200,   846,  1201,   847,  1202,   848,
     849,  1203,   850,  1204,  1205,     5,   330,   853,     6,  1206,
     855,     7,   857,  1207,   858,   859,   860,  1208,  1209,  1210,
       8,   862,   866,   331,   332,   865,   869,  1211,   870,   333,
     871,   872,   873,   874,     9,   875,   882,   876,   877,   878,
      10,    11,   880,   881,   883,   884,   983,  1275,   885,   886,
     887,   888,  1301,   995,   889,   890,  1276,   891,   985,    12,
     892,   893,   894,    13,   895,   896,   897,   898,   899,   900,
     901,   902,   903,    14,   904,   905,   906,   334,   907,   908,
     909,   910,   911,   912,   913,   962,   963,   964,   965,   966,
     967,   968,    15,    16,   969,   335,   336,   970,   971,   972,
     973,   974,   337,   975,   976,   338,   977,    17,   978,   979,
     980,   339,   981,   982,   984,    82,   986,   987,   988,   340,
     341,   342,   989,    18,   990,   991,  1006,   993,   992,   994,
     999,   343,   996,  1002,  1000,    19,    20,  1001,  1003,  1004,
    1005,  1007,    83,    84,  1008,  1009,  1010,  1011,  1012,  1013,
      85,   344,  1015,    21,  1014,    86,    87,    88,  1016,  1017,
    1018,  1046,  1065,  1019,  1020,  1021,    22,  1022,  1023,  1024,
    1025,    23,  1026,  1027,  1028,  1029,    24,  1030,  1031,    25,
      89,    90,    91,    92,  1032,  1033,  1034,  1035,  1036,   345,
    1037,  1038,  1039,  1040,  1041,    93,    94,    95,  1042,  1043,
    1044,  1045,    96,    97,    98,  1047,    99,  1048,  1058,  1059,
    1060,  1061,  1235,  1277,  1062,  1063,  1064,  1066,  1298,  1236,
    1067,  1075,  1278,  1076,  1077,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1096,  1097,  1098,  1099,  1100,  1300,
    1101,  1102,  1103,  1104,  1109,  1110,  1111,  1112,  1113,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1125,  1126,  1138,  1139,
    1140,  1141,  1142,  1143,  1144,  1145,  1146,  1157,  1158,  1159,
    1160,  1188,  1189,  1214,  1215,  1216,  1217,  1218,  1219,  1220,
    1221,  1234,  1240,  1241,  1242,  1243,  1244,  1257,  1271,  1286,
    1273,  1302,   310,  1279,  1290,  1289,  1306,  1307,  1308,  1319,
     501,   750,   811,  1304,  1239,   763,  1303,   646,  1293,  1296,
    1272,  1295,   731,  1318,   769,   801,   819,  1305,   405,   674,
    1294,   742,   668,   459,   664,  1266,  1265,   329,   551,     0,
       0,   570,     0,     0,     0,     0,     0,     0,     0,     0,
     735,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   581,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   596
};

static const yytype_int16 yycheck[] =
{
     643,   644,   312,    58,   234,   235,     1,     1,   318,   319,
     320,   200,   322,   323,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,   234,   175,   176,   234,
     238,     1,     1,   238,     1,   236,     1,     8,    33,     1,
     236,     1,   236,   236,   233,    40,    12,    13,    14,     1,
     236,   234,    37,   234,     1,   238,     1,     1,     1,     6,
       7,   236,     9,    10,    49,    50,    51,   234,    15,    54,
      55,   238,     1,   128,    59,    60,    61,   234,    25,    26,
      27,   238,   236,     1,   236,   236,    46,   236,    35,    70,
      70,    38,    39,    70,    70,    62,     1,   236,   234,   236,
     234,    48,   238,    70,   414,    72,   416,   417,    86,     1,
     420,   106,   106,  1091,  1092,  1093,   426,   103,    65,   106,
     103,   236,   432,   236,   106,    30,    86,   106,    33,    76,
     440,   441,    79,    80,    86,   234,   106,   106,   124,   238,
      87,   124,   129,   453,   454,   455,    93,    94,   129,    96,
     129,    98,   129,   234,   101,   102,     1,   238,    63,   236,
     127,   106,   106,   106,   129,   112,   236,   129,    73,   129,
     117,   118,   234,   120,   121,   122,   238,   106,   125,   236,
     236,   234,   164,    28,    29,   238,   236,   171,   106,   236,
      95,    36,     1,   171,    99,   236,    41,    42,    43,     1,
     182,   106,   149,   150,   109,   110,   153,   154,   155,   156,
     157,   158,   159,   236,   196,     1,   237,   237,    20,   171,
     237,    66,    67,    68,    69,   237,   197,   221,   237,   237,
     224,   237,   137,   543,    20,   237,    81,    82,    83,   223,
     235,   235,    44,    88,    89,    90,     1,    92,   192,   235,
     235,   235,   221,   235,   235,   235,   235,   235,    44,   224,
     207,   208,   224,    18,    19,   235,   235,   233,   235,    24,
      72,   218,   219,   235,   192,   235,     1,   221,   221,   171,
     227,   224,   229,     1,   237,     3,    72,     5,   235,   237,
      21,   235,   221,     1,   234,    20,   237,   106,   237,   237,
      31,   237,    20,   221,    75,   210,    77,   212,   213,   237,
     215,   216,   217,   237,     1,     1,   237,    72,   237,    44,
     106,   123,   632,    54,   237,   635,    44,   637,   130,   131,
     235,   223,   642,   237,    20,    90,    91,   123,    46,   237,
       1,   237,    97,   237,    62,   100,    64,    72,   119,   151,
     660,   106,   237,   237,    72,   164,   237,   237,    44,   114,
     115,   116,   237,   237,   135,   237,    84,   237,   237,   237,
     237,   126,    33,   182,   237,    62,   237,   237,    86,    40,
     237,   237,   237,    70,    16,    72,    72,   196,   106,   237,
     235,   146,   232,   237,   237,   237,   167,   168,   123,   237,
     237,   237,   237,   237,   237,   130,   131,   237,   237,   127,
       1,   237,   198,    45,   237,     6,     7,   237,     9,    10,
     106,   129,   224,   237,    15,   211,   151,   145,   214,   184,
     237,   237,   237,   235,    25,    26,    27,   123,   224,   237,
     127,   237,   228,   161,    35,   106,    78,    38,    39,   235,
     237,   171,   237,   224,   237,   237,   187,    48,   237,   230,
     237,   237,   237,   237,   237,   237,   197,   824,   825,   826,
     827,   828,   829,   830,    65,   107,   108,   237,    77,   237,
     235,   113,   234,   237,   237,    76,   237,   237,    79,    80,
     237,   209,   237,   211,   212,   237,    87,   237,   237,   224,
     237,   237,    93,    94,   136,    96,   232,    98,   237,   237,
     101,   102,   198,   237,     4,   237,   237,   235,   237,   232,
     237,   112,   237,   234,   233,   211,   117,   118,   214,   120,
     121,   122,    22,    23,   125,   233,   135,   206,   224,    77,
     206,   206,   228,     1,    34,   138,   139,   140,   141,   142,
     143,   144,   206,   233,   233,   233,   233,   233,   149,   150,
     233,   160,   153,   154,   155,   156,   157,   158,   159,   168,
     234,   234,    30,   205,   233,    33,   220,   237,   177,   237,
     237,   237,   237,   233,    74,    75,   237,    77,   237,   237,
     237,   237,   237,  1236,   237,   237,   237,   135,   234,   231,
     199,   236,   201,   202,   237,    63,   237,   237,   237,   237,
     237,   237,   237,   103,   237,    73,   207,   208,   237,   237,
     237,   111,   160,   222,    11,   237,   237,   218,   219,   237,
     168,   230,   237,   234,   232,   237,   227,    95,   229,   177,
     233,    99,   132,   237,   134,   135,   206,   206,   106,   206,
     233,   109,   110,   233,   206,     1,   206,     3,   233,     5,
      47,   199,   152,   201,   202,   233,   233,    54,   233,    56,
      57,   233,   233,   206,    20,   233,   206,    11,   168,   137,
     233,   237,   237,   173,   222,   206,   206,   177,   233,   206,
     206,   181,   230,   206,   206,   206,   186,   206,    44,   206,
     190,   233,   206,   234,   233,   239,   234,   232,   234,   199,
     237,   201,   202,    47,   204,   237,    62,   232,    64,   237,
      54,   133,    56,    57,   206,    11,    72,   237,   206,   237,
     206,   237,   222,   232,   237,   237,   237,   237,    84,   237,
     230,   237,   234,   234,   237,   206,   234,   133,   237,   234,
     237,   237,   210,   237,   212,   213,   237,   215,   216,   217,
     106,    47,   237,   237,     1,   237,   237,   237,    54,   237,
      56,    57,   237,   232,   206,   162,   163,   206,   234,   166,
     167,   127,   169,   170,   233,   172,   232,   174,   206,   232,
     177,   233,   179,   180,   233,   232,   232,   232,   185,   145,
      37,   232,   189,   237,   232,   232,   193,   194,   195,   232,
     232,   232,    49,    50,    51,   161,   203,    54,    55,   232,
     234,   206,    59,    60,    61,   234,   234,   234,   162,   163,
     232,   237,   166,   167,   237,   169,   170,   237,   172,   237,
     174,   234,   234,   177,   238,   179,   180,   237,   237,   237,
     234,   185,   234,   234,   234,   189,   234,   234,   234,   193,
     194,   195,   234,   209,   234,   211,   212,   234,   234,   203,
     234,   234,   234,   234,   234,   234,   162,   163,     0,     1,
     166,   167,     4,   169,   170,   234,   172,   234,   174,   234,
     233,   177,   233,   179,   180,    17,     1,   233,    20,   185,
     233,    23,   232,   189,   233,   233,   233,   193,   194,   195,
      32,   233,   232,    18,    19,   234,   232,   203,   206,    24,
     232,   232,   237,   232,    46,   232,   234,   233,   232,   232,
      52,    53,   232,   232,   232,   232,   237,   239,   234,   234,
     232,   232,   133,   237,   234,   234,   239,   234,   233,    71,
     234,   234,   234,    75,   234,   234,   234,   234,   234,   234,
     234,   234,   234,    85,   234,   234,   234,    72,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   104,   105,   234,    90,    91,   234,   234,   234,
     234,   234,    97,   234,   234,   100,   234,   119,   234,   234,
     234,   106,   232,   206,   232,     1,   232,   232,   232,   114,
     115,   116,   234,   135,   232,   232,   206,   232,   234,   232,
     234,   126,   233,   232,   234,   147,   148,   234,   232,   234,
     232,   237,    28,    29,   232,   232,   237,   232,   206,   232,
      36,   146,   234,   165,   232,    41,    42,    43,   232,   232,
     232,   237,   237,   234,   234,   234,   178,   234,   234,   234,
     234,   183,   234,   234,   234,   234,   188,   234,   234,   191,
      66,    67,    68,    69,   234,   234,   234,   234,   234,   184,
     234,   234,   234,   234,   234,    81,    82,    83,   234,   234,
     234,   232,    88,    89,    90,   234,    92,   234,   232,   232,
     232,   232,   237,   239,   234,   234,   232,   232,   135,   237,
     234,   234,   239,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   135,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   233,   232,
     234,   133,    77,   239,   234,   237,   234,   234,   234,   234,
     227,   505,   588,  1283,  1053,   520,  1281,   346,  1259,  1270,
    1155,  1268,   469,  1292,   536,   574,   601,  1285,   124,   409,
    1264,   492,   399,   174,   379,  1124,  1122,   100,   244,    -1,
      -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   301
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   241,     0,     1,     4,    17,    20,    23,    32,    46,
      52,    53,    71,    75,    85,   104,   105,   119,   135,   147,
     148,   165,   178,   183,   188,   191,   242,   247,   252,   271,
     277,   283,   291,   304,   324,   346,   360,   375,   382,   386,
     396,   405,   427,   433,   439,   443,   449,   503,   523,   234,
     235,   236,   236,   325,   406,   434,   236,   444,   236,   361,
     428,   347,   236,   278,   305,   376,   236,   236,   397,   236,
     284,   236,   387,     1,    33,    40,   106,   272,   273,   274,
     275,   276,     1,    28,    29,    36,    41,    42,    43,    66,
      67,    68,    69,    81,    82,    83,    88,    89,    90,    92,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   236,
     236,   236,     1,    70,   440,   441,   442,   236,     1,     6,
       7,     9,    10,    15,    25,    26,    27,    35,    38,    39,
      48,    65,    76,    79,    80,    87,    93,    94,    96,    98,
     101,   102,   112,   117,   118,   120,   121,   122,   125,   149,
     150,   153,   154,   155,   156,   157,   158,   159,   207,   208,
     218,   219,   227,   229,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   495,   499,   500,   501,
     502,   236,   236,   236,     1,   103,   124,   248,   249,   250,
     251,   236,   236,   236,     1,    37,    49,    50,    51,    54,
      55,    59,    60,    61,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,     1,    30,    33,    63,    73,
      95,    99,   106,   109,   110,   137,   210,   212,   213,   215,
     216,   217,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     236,     1,   223,   292,   293,   294,   295,   296,   236,     1,
     106,   383,   384,   385,   236,   234,   237,   237,   237,   235,
     273,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   235,   505,
       1,    18,    19,    24,    72,    90,    91,    97,   100,   106,
     114,   115,   116,   126,   146,   184,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,     1,     3,     5,    20,    44,    62,    64,
      72,    84,   106,   127,   145,   161,   209,   211,   212,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   422,   423,   424,   425,   426,     1,    70,   129,   435,
     436,   437,   438,   237,   235,   441,     1,   106,   129,   445,
     446,   447,   448,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   496,   492,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   235,   451,
       1,    20,    44,    72,   123,   130,   131,   151,   224,   362,
     363,   364,   365,   366,   367,   368,   372,   373,   374,     1,
     129,   224,   429,   430,   431,   432,     1,    62,    70,    72,
     127,   348,   352,   353,   354,   358,   359,   234,   237,   237,
     235,   249,     1,    86,   171,   279,   280,   281,   282,     1,
      20,    44,    72,   106,   123,   198,   211,   214,   224,   228,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   320,     1,    46,    86,   129,   377,   378,   379,   380,
     381,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     235,   525,   234,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   235,
     254,     1,   106,   221,   398,   399,   400,   401,   234,   237,
     235,   293,   171,     1,   106,   164,   182,   196,   285,   286,
     287,   288,   289,   290,   237,   235,   384,     1,   106,   221,
     224,   388,   389,   390,   391,   392,   232,   232,   232,   234,
     233,   233,   244,   206,   206,   206,   206,   233,   244,   244,
     244,   233,   244,   244,   233,   233,   233,   233,   234,   234,
     237,   237,   237,   343,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   235,   327,   234,   237,   237,
     237,   237,   237,   237,   419,   237,   237,   237,   237,   237,
     237,   237,   237,   235,   408,   237,   237,   235,   436,   232,
     234,   237,   237,   235,   446,   206,   244,   233,   244,   244,
     206,   233,   244,   206,   233,   233,   206,   206,   244,   233,
     233,   233,   233,   233,   244,   233,   233,   233,   206,   237,
     237,   206,   244,   244,   206,   206,   233,   206,   206,   206,
     206,   206,   206,   206,   233,   244,   244,   244,   206,   233,
     234,   234,   237,   237,   369,   237,   237,   237,   237,   237,
     235,   363,   237,   237,   235,   430,   234,   237,   237,   349,
     237,   235,   353,   232,   232,   234,   234,   237,   237,   235,
     280,   234,   237,   237,   321,   237,   237,   317,   237,   237,
     237,   237,   235,   307,   234,   237,   237,   237,   235,   378,
     206,   206,   244,   232,   206,   232,   206,   206,   206,   234,
     233,   232,   206,   232,   233,   233,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   234,   234,   237,   402,
     235,   399,   206,   234,   236,   234,   237,   237,   237,   237,
     235,   286,   232,   234,   234,   237,   393,   237,   235,   389,
     234,   234,   234,   234,   138,   139,   140,   141,   142,   143,
     144,   243,   244,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   233,
     233,   244,   237,   233,   244,   233,   244,   232,   233,   233,
     233,   244,   233,   246,   246,   234,   232,   175,   176,   232,
     206,   232,   232,   237,   232,   232,   233,   232,   232,   244,
     232,   232,   234,   232,   232,   234,   234,   232,   232,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,    11,    47,    54,    56,    57,   162,
     163,   166,   167,   169,   170,   172,   174,   177,   179,   180,
     185,   189,   193,   194,   195,   203,   497,   498,    11,    47,
      54,    56,    57,   162,   163,   166,   167,   169,   170,   172,
     174,   177,   179,   180,   185,   189,   193,   194,   195,   203,
     493,   494,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   232,   206,   237,   232,   233,   232,   232,   232,   234,
     232,   232,   234,   232,   232,   237,   233,   356,   357,   234,
     234,   234,   232,   232,   234,   232,   206,   237,   232,   232,
     237,   232,   206,   232,   232,   234,   232,   232,   232,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   232,   237,   234,   234,     1,
     106,   192,   221,   297,   298,   299,   300,   301,   232,   232,
     232,   232,   234,   234,   232,   237,   232,   234,   243,   243,
     243,   243,   243,   243,   243,   234,   234,   234,    58,   128,
     344,   345,   234,   234,   234,   234,   234,   234,   234,   234,
     234,    12,    13,    14,   245,   246,   234,   234,   234,   234,
     234,   234,   234,   234,   234,     8,   197,   420,   421,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   238,   234,   238,   234,   234,    16,    45,    78,
     107,   108,   113,   136,   205,   231,   370,   371,   234,   234,
     234,   234,   234,   234,   234,   234,   234,    21,    31,    54,
     187,   197,   350,   351,   220,   238,   355,   234,   234,   234,
     234,     4,    22,    23,    34,    74,    75,    77,   103,   111,
     132,   134,   135,   152,   168,   173,   177,   181,   186,   190,
     199,   201,   202,   204,   222,   230,   322,   323,   234,   234,
      11,    47,    54,    56,    57,   162,   163,   166,   167,   169,
     170,   172,   174,   177,   179,   180,   185,   189,   193,   194,
     195,   203,   318,   319,   234,   234,   234,   234,   234,   234,
     234,   234,    77,   135,   160,   168,   177,   199,   201,   202,
     222,   230,   403,   404,   234,   237,   237,   302,   235,   298,
     234,   234,   234,   234,   234,    77,   135,   160,   168,   177,
     199,   201,   202,   222,   230,   394,   395,   234,   234,   238,
     245,   245,   245,   234,   238,   498,   494,   234,   238,   234,
     238,   233,   357,   234,   239,   239,   239,   239,   239,   239,
     234,   238,   234,   238,   234,   238,   232,   200,   246,   237,
     234,   234,   238,   345,   421,   371,   351,   133,   135,   133,
     135,   133,   133,   323,   319,   404,   234,   234,   234,    75,
      77,   119,   135,   167,   168,   224,   230,   303,   395,   234
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   240,   241,   241,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   243,   243,
     244,   244,   244,   244,   244,   244,   244,   244,   245,   245,
     246,   246,   246,   246,   247,   248,   248,   249,   249,   249,
     250,   251,   252,   253,   253,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     272,   273,   273,   273,   273,   274,   275,   276,   278,   277,
     279,   279,   280,   280,   280,   281,   282,   284,   283,   285,
     285,   286,   286,   286,   286,   286,   287,   288,   289,   290,
     291,   292,   292,   293,   293,   293,   294,   296,   295,   297,
     297,   298,   298,   298,   298,   299,   300,   300,   302,   301,
     303,   303,   303,   303,   303,   303,   303,   303,   305,   304,
     306,   306,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   317,   316,   318,   318,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   321,   320,   322,
     322,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     325,   324,   326,   326,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   343,   342,   344,   344,   345,   345,
     347,   346,   349,   348,   350,   350,   351,   351,   351,   351,
     351,   352,   352,   353,   353,   353,   353,   353,   355,   354,
     356,   356,   357,   357,   358,   359,   361,   360,   362,   362,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   364,
     365,   366,   367,   369,   368,   370,   370,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   372,   373,   374,   376,
     375,   377,   377,   378,   378,   378,   378,   379,   380,   381,
     382,   383,   383,   384,   384,   385,   387,   386,   388,   388,
     389,   389,   389,   389,   390,   391,   393,   392,   394,   394,
     395,   395,   395,   395,   395,   395,   395,   395,   395,   395,
     397,   396,   398,   398,   399,   399,   399,   400,   402,   401,
     403,   403,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   404,   406,   405,   407,   407,   408,   408,   408,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   417,   419,   418,   420,   420,   421,   421,   422,   423,
     424,   425,   426,   428,   427,   429,   429,   430,   430,   430,
     431,   432,   434,   433,   435,   435,   436,   436,   436,   437,
     438,   439,   440,   440,   441,   441,   442,   444,   443,   445,
     445,   446,   446,   446,   447,   448,   449,   450,   450,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   492,   491,   493,   493,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     496,   495,   497,   497,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   499,   500,   501,   502,
     503,   504,   504,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     524,   525,   525,   525,   525,   525,   525,   525,   525,   525,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534
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
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4
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
#line 398 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3266 "conf_parser.c"
    break;

  case 30: /* timespec: NUMBER timespec_  */
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3272 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER SECONDS timespec_  */
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3278 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER MINUTES timespec_  */
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3284 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER HOURS timespec_  */
#line 402 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3290 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER DAYS timespec_  */
#line 403 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3296 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER WEEKS timespec_  */
#line 404 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3302 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER MONTHS timespec_  */
#line 405 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3308 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER YEARS timespec_  */
#line 406 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3314 "conf_parser.c"
    break;

  case 38: /* sizespec_: %empty  */
#line 409 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3320 "conf_parser.c"
    break;

  case 40: /* sizespec: NUMBER sizespec_  */
#line 410 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3326 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER BYTES sizespec_  */
#line 411 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3332 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER KBYTES sizespec_  */
#line 412 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3338 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER MBYTES sizespec_  */
#line 413 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3344 "conf_parser.c"
    break;

  case 50: /* modules_module: MODULE '=' QSTRING ';'  */
#line 426 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 3353 "conf_parser.c"
    break;

  case 51: /* modules_path: PATH '=' QSTRING ';'  */
#line 432 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 3362 "conf_parser.c"
    break;

  case 72: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 464 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = xstrdup(yylval.string);
  }
}
#line 3374 "conf_parser.c"
    break;

  case 73: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 473 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 3386 "conf_parser.c"
    break;

  case 74: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 482 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3398 "conf_parser.c"
    break;

  case 75: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 491 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = xstrdup(yylval.string);
  }
}
#line 3410 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 500 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = xstrdup(yylval.string);
  }
}
#line 3422 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 509 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3434 "conf_parser.c"
    break;

  case 78: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 518 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = xstrdup(yylval.string);
  }
}
#line 3446 "conf_parser.c"
    break;

  case 79: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 527 "conf_parser.y"
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
#line 3464 "conf_parser.c"
    break;

  case 80: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 542 "conf_parser.y"
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
#line 3482 "conf_parser.c"
    break;

  case 81: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 557 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3495 "conf_parser.c"
    break;

  case 82: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 567 "conf_parser.y"
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
#line 3512 "conf_parser.c"
    break;

  case 83: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 581 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = xstrdup(yylval.string);
}
#line 3524 "conf_parser.c"
    break;

  case 84: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 590 "conf_parser.y"
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
#line 3550 "conf_parser.c"
    break;

  case 85: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 613 "conf_parser.y"
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
#line 3576 "conf_parser.c"
    break;

  case 86: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 636 "conf_parser.y"
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
#line 3602 "conf_parser.c"
    break;

  case 87: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 659 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3611 "conf_parser.c"
    break;

  case 95: /* admin_name: NAME '=' QSTRING ';'  */
#line 677 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3623 "conf_parser.c"
    break;

  case 96: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 686 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3635 "conf_parser.c"
    break;

  case 97: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 695 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3647 "conf_parser.c"
    break;

  case 98: /* $@1: %empty  */
#line 708 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3656 "conf_parser.c"
    break;

  case 99: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 712 "conf_parser.y"
{
  dlink_node *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3673 "conf_parser.c"
    break;

  case 105: /* motd_mask: MASK '=' QSTRING ';'  */
#line 729 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3682 "conf_parser.c"
    break;

  case 106: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 735 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3691 "conf_parser.c"
    break;

  case 107: /* $@2: %empty  */
#line 745 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3700 "conf_parser.c"
    break;

  case 108: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 749 "conf_parser.y"
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
#line 3718 "conf_parser.c"
    break;

  case 116: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3727 "conf_parser.c"
    break;

  case 117: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 773 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3736 "conf_parser.c"
    break;

  case 118: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 779 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3745 "conf_parser.c"
    break;

  case 119: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 785 "conf_parser.y"
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
#line 3766 "conf_parser.c"
    break;

  case 126: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 813 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3775 "conf_parser.c"
    break;

  case 127: /* $@3: %empty  */
#line 819 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3784 "conf_parser.c"
    break;

  case 128: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 823 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3797 "conf_parser.c"
    break;

  case 135: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 839 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3808 "conf_parser.c"
    break;

  case 136: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 847 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3816 "conf_parser.c"
    break;

  case 137: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 850 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3824 "conf_parser.c"
    break;

  case 138: /* $@4: %empty  */
#line 855 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3833 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: USER  */
#line 861 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3842 "conf_parser.c"
    break;

  case 141: /* logging_file_type_item: OPERATOR  */
#line 865 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3851 "conf_parser.c"
    break;

  case 142: /* logging_file_type_item: XLINE  */
#line 869 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3860 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: RESV  */
#line 873 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3869 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: T_DLINE  */
#line 877 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3878 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: KLINE  */
#line 881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3887 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: KILL  */
#line 885 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3896 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: T_DEBUG  */
#line 889 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3905 "conf_parser.c"
    break;

  case 148: /* $@5: %empty  */
#line 899 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3917 "conf_parser.c"
    break;

  case 149: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 906 "conf_parser.y"
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
#line 3976 "conf_parser.c"
    break;

  case 163: /* oper_name: NAME '=' QSTRING ';'  */
#line 975 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3985 "conf_parser.c"
    break;

  case 164: /* oper_user: USER '=' QSTRING ';'  */
#line 981 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3994 "conf_parser.c"
    break;

  case 165: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 987 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4003 "conf_parser.c"
    break;

  case 166: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 993 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4012 "conf_parser.c"
    break;

  case 167: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 999 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 4026 "conf_parser.c"
    break;

  case 168: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1010 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4035 "conf_parser.c"
    break;

  case 169: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1016 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 4049 "conf_parser.c"
    break;

  case 170: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1027 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4058 "conf_parser.c"
    break;

  case 171: /* $@6: %empty  */
#line 1033 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 4067 "conf_parser.c"
    break;

  case 175: /* oper_umodes_item: BOT  */
#line 1040 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOT;
}
#line 4076 "conf_parser.c"
    break;

  case 176: /* oper_umodes_item: T_CCONN  */
#line 1044 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 4085 "conf_parser.c"
    break;

  case 177: /* oper_umodes_item: T_DEAF  */
#line 1048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 4094 "conf_parser.c"
    break;

  case 178: /* oper_umodes_item: T_DEBUG  */
#line 1052 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 4103 "conf_parser.c"
    break;

  case 179: /* oper_umodes_item: T_FLOOD  */
#line 1056 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FLOOD;
}
#line 4112 "conf_parser.c"
    break;

  case 180: /* oper_umodes_item: HIDDEN  */
#line 1060 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 4121 "conf_parser.c"
    break;

  case 181: /* oper_umodes_item: HIDE_CHANS  */
#line 1064 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 4130 "conf_parser.c"
    break;

  case 182: /* oper_umodes_item: HIDE_IDLE  */
#line 1068 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 4139 "conf_parser.c"
    break;

  case 183: /* oper_umodes_item: T_SKILL  */
#line 1072 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 4148 "conf_parser.c"
    break;

  case 184: /* oper_umodes_item: T_NCHANGE  */
#line 1076 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 4157 "conf_parser.c"
    break;

  case 185: /* oper_umodes_item: T_REJ  */
#line 1080 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 4166 "conf_parser.c"
    break;

  case 186: /* oper_umodes_item: T_SPY  */
#line 1084 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4175 "conf_parser.c"
    break;

  case 187: /* oper_umodes_item: T_EXTERNAL  */
#line 1088 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4184 "conf_parser.c"
    break;

  case 188: /* oper_umodes_item: T_SERVNOTICE  */
#line 1092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4193 "conf_parser.c"
    break;

  case 189: /* oper_umodes_item: T_INVISIBLE  */
#line 1096 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4202 "conf_parser.c"
    break;

  case 190: /* oper_umodes_item: T_WALLOP  */
#line 1100 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4211 "conf_parser.c"
    break;

  case 191: /* oper_umodes_item: T_SOFTCALLERID  */
#line 1104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4220 "conf_parser.c"
    break;

  case 192: /* oper_umodes_item: T_CALLERID  */
#line 1108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4229 "conf_parser.c"
    break;

  case 193: /* oper_umodes_item: T_LOCOPS  */
#line 1112 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4238 "conf_parser.c"
    break;

  case 194: /* oper_umodes_item: T_NONONREG  */
#line 1116 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4247 "conf_parser.c"
    break;

  case 195: /* oper_umodes_item: T_FARCONNECT  */
#line 1120 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4256 "conf_parser.c"
    break;

  case 196: /* oper_umodes_item: EXPIRATION  */
#line 1124 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 4265 "conf_parser.c"
    break;

  case 197: /* $@7: %empty  */
#line 1130 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4274 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: KILL ':' REMOTE  */
#line 1137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4283 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: KILL  */
#line 1141 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4292 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1145 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4301 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: CONNECT  */
#line 1149 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4310 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1153 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4319 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: SQUIT  */
#line 1157 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4328 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: KLINE  */
#line 1161 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4337 "conf_parser.c"
    break;

  case 208: /* oper_flags_item: UNKLINE  */
#line 1165 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4346 "conf_parser.c"
    break;

  case 209: /* oper_flags_item: T_DLINE  */
#line 1169 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4355 "conf_parser.c"
    break;

  case 210: /* oper_flags_item: T_UNDLINE  */
#line 1173 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4364 "conf_parser.c"
    break;

  case 211: /* oper_flags_item: XLINE  */
#line 1177 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4373 "conf_parser.c"
    break;

  case 212: /* oper_flags_item: T_UNXLINE  */
#line 1181 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4382 "conf_parser.c"
    break;

  case 213: /* oper_flags_item: DIE  */
#line 1185 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4391 "conf_parser.c"
    break;

  case 214: /* oper_flags_item: T_RESTART  */
#line 1189 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4400 "conf_parser.c"
    break;

  case 215: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1193 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4409 "conf_parser.c"
    break;

  case 216: /* oper_flags_item: REHASH  */
#line 1197 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4418 "conf_parser.c"
    break;

  case 217: /* oper_flags_item: ADMIN  */
#line 1201 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4427 "conf_parser.c"
    break;

  case 218: /* oper_flags_item: T_GLOBOPS  */
#line 1205 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4436 "conf_parser.c"
    break;

  case 219: /* oper_flags_item: T_WALLOPS  */
#line 1209 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4445 "conf_parser.c"
    break;

  case 220: /* oper_flags_item: T_LOCOPS  */
#line 1213 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4454 "conf_parser.c"
    break;

  case 221: /* oper_flags_item: REMOTEBAN  */
#line 1217 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4463 "conf_parser.c"
    break;

  case 222: /* oper_flags_item: T_SET  */
#line 1221 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4472 "conf_parser.c"
    break;

  case 223: /* oper_flags_item: MODULE  */
#line 1225 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4481 "conf_parser.c"
    break;

  case 224: /* oper_flags_item: T_OPME  */
#line 1229 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4490 "conf_parser.c"
    break;

  case 225: /* oper_flags_item: NICK ':' RESV  */
#line 1233 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4499 "conf_parser.c"
    break;

  case 226: /* oper_flags_item: JOIN ':' RESV  */
#line 1237 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4508 "conf_parser.c"
    break;

  case 227: /* oper_flags_item: RESV  */
#line 1241 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4517 "conf_parser.c"
    break;

  case 228: /* oper_flags_item: T_UNRESV  */
#line 1245 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4526 "conf_parser.c"
    break;

  case 229: /* oper_flags_item: CLOSE  */
#line 1249 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4535 "conf_parser.c"
    break;

  case 230: /* $@8: %empty  */
#line 1259 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4551 "conf_parser.c"
    break;

  case 231: /* class_entry: CLASS $@8 '{' class_items '}' ';'  */
#line 1270 "conf_parser.y"
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
#line 4599 "conf_parser.c"
    break;

  case 250: /* class_name: NAME '=' QSTRING ';'  */
#line 1333 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4608 "conf_parser.c"
    break;

  case 251: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1339 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4617 "conf_parser.c"
    break;

  case 252: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1345 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4626 "conf_parser.c"
    break;

  case 253: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1351 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4635 "conf_parser.c"
    break;

  case 254: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1357 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4644 "conf_parser.c"
    break;

  case 255: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1363 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4653 "conf_parser.c"
    break;

  case 256: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1369 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4662 "conf_parser.c"
    break;

  case 257: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1375 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4671 "conf_parser.c"
    break;

  case 258: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1381 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4681 "conf_parser.c"
    break;

  case 259: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1388 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4690 "conf_parser.c"
    break;

  case 260: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1394 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4699 "conf_parser.c"
    break;

  case 261: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1400 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4708 "conf_parser.c"
    break;

  case 262: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1406 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4720 "conf_parser.c"
    break;

  case 263: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1415 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4732 "conf_parser.c"
    break;

  case 264: /* $@9: %empty  */
#line 1424 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4741 "conf_parser.c"
    break;

  case 268: /* class_flags_item: RANDOM_IDLE  */
#line 1431 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4750 "conf_parser.c"
    break;

  case 269: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1435 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4759 "conf_parser.c"
    break;

  case 270: /* $@10: %empty  */
#line 1445 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4768 "conf_parser.c"
    break;

  case 272: /* $@11: %empty  */
#line 1451 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4776 "conf_parser.c"
    break;

  case 276: /* listen_flags_item: T_TLS  */
#line 1457 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4785 "conf_parser.c"
    break;

  case 277: /* listen_flags_item: HIDDEN  */
#line 1461 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4794 "conf_parser.c"
    break;

  case 278: /* listen_flags_item: T_SERVER  */
#line 1465 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4803 "conf_parser.c"
    break;

  case 279: /* listen_flags_item: CLIENT  */
#line 1469 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4812 "conf_parser.c"
    break;

  case 280: /* listen_flags_item: DEFER  */
#line 1473 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4821 "conf_parser.c"
    break;

  case 288: /* $@12: %empty  */
#line 1481 "conf_parser.y"
                                 { reset_block_state(); }
#line 4827 "conf_parser.c"
    break;

  case 292: /* port_item: NUMBER  */
#line 1486 "conf_parser.y"
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
#line 4845 "conf_parser.c"
    break;

  case 293: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1499 "conf_parser.y"
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
#line 4865 "conf_parser.c"
    break;

  case 294: /* listen_address: IP '=' QSTRING ';'  */
#line 1516 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4874 "conf_parser.c"
    break;

  case 295: /* listen_host: HOST '=' QSTRING ';'  */
#line 1522 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4883 "conf_parser.c"
    break;

  case 296: /* $@13: %empty  */
#line 1532 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4892 "conf_parser.c"
    break;

  case 297: /* auth_entry: IRCD_AUTH $@13 '{' auth_items '}' ';'  */
#line 1536 "conf_parser.y"
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
#line 4938 "conf_parser.c"
    break;

  case 309: /* auth_user: USER '=' QSTRING ';'  */
#line 1590 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4947 "conf_parser.c"
    break;

  case 310: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1596 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4956 "conf_parser.c"
    break;

  case 311: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1602 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4965 "conf_parser.c"
    break;

  case 312: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1608 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4979 "conf_parser.c"
    break;

  case 313: /* $@14: %empty  */
#line 1619 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4988 "conf_parser.c"
    break;

  case 317: /* auth_flags_item: EXCEED_LIMIT  */
#line 1626 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4997 "conf_parser.c"
    break;

  case 318: /* auth_flags_item: KLINE_EXEMPT  */
#line 1630 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 5006 "conf_parser.c"
    break;

  case 319: /* auth_flags_item: XLINE_EXEMPT  */
#line 1634 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 5015 "conf_parser.c"
    break;

  case 320: /* auth_flags_item: NEED_IDENT  */
#line 1638 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 5024 "conf_parser.c"
    break;

  case 321: /* auth_flags_item: CAN_FLOOD  */
#line 1642 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 5033 "conf_parser.c"
    break;

  case 322: /* auth_flags_item: NO_TILDE  */
#line 1646 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 5042 "conf_parser.c"
    break;

  case 323: /* auth_flags_item: RESV_EXEMPT  */
#line 1650 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 5051 "conf_parser.c"
    break;

  case 324: /* auth_flags_item: T_WEBIRC  */
#line 1654 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 5060 "conf_parser.c"
    break;

  case 325: /* auth_flags_item: NEED_PASSWORD  */
#line 1658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 5069 "conf_parser.c"
    break;

  case 326: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1664 "conf_parser.y"
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
#line 5086 "conf_parser.c"
    break;

  case 327: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1678 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 5098 "conf_parser.c"
    break;

  case 328: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1687 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 5110 "conf_parser.c"
    break;

  case 329: /* $@15: %empty  */
#line 1700 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5122 "conf_parser.c"
    break;

  case 330: /* resv_entry: RESV $@15 '{' resv_items '}' ';'  */
#line 1707 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5133 "conf_parser.c"
    break;

  case 337: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1718 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5142 "conf_parser.c"
    break;

  case 338: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1724 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5151 "conf_parser.c"
    break;

  case 339: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1730 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 5160 "conf_parser.c"
    break;

  case 345: /* service_name: NAME '=' QSTRING ';'  */
#line 1745 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 5175 "conf_parser.c"
    break;

  case 346: /* $@16: %empty  */
#line 1761 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5191 "conf_parser.c"
    break;

  case 347: /* shared_entry: T_SHARED $@16 '{' shared_items '}' ';'  */
#line 1772 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 5206 "conf_parser.c"
    break;

  case 354: /* shared_name: NAME '=' QSTRING ';'  */
#line 1787 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5215 "conf_parser.c"
    break;

  case 355: /* shared_user: USER '=' QSTRING ';'  */
#line 1793 "conf_parser.y"
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
#line 5237 "conf_parser.c"
    break;

  case 356: /* $@17: %empty  */
#line 1812 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5246 "conf_parser.c"
    break;

  case 360: /* shared_type_item: KLINE  */
#line 1819 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5255 "conf_parser.c"
    break;

  case 361: /* shared_type_item: UNKLINE  */
#line 1823 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5264 "conf_parser.c"
    break;

  case 362: /* shared_type_item: T_DLINE  */
#line 1827 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5273 "conf_parser.c"
    break;

  case 363: /* shared_type_item: T_UNDLINE  */
#line 1831 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5282 "conf_parser.c"
    break;

  case 364: /* shared_type_item: XLINE  */
#line 1835 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5291 "conf_parser.c"
    break;

  case 365: /* shared_type_item: T_UNXLINE  */
#line 1839 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5300 "conf_parser.c"
    break;

  case 366: /* shared_type_item: RESV  */
#line 1843 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5309 "conf_parser.c"
    break;

  case 367: /* shared_type_item: T_UNRESV  */
#line 1847 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5318 "conf_parser.c"
    break;

  case 368: /* shared_type_item: T_LOCOPS  */
#line 1851 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5327 "conf_parser.c"
    break;

  case 369: /* shared_type_item: T_ALL  */
#line 1855 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5336 "conf_parser.c"
    break;

  case 370: /* $@18: %empty  */
#line 1865 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5350 "conf_parser.c"
    break;

  case 371: /* cluster_entry: T_CLUSTER $@18 '{' cluster_items '}' ';'  */
#line 1874 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5363 "conf_parser.c"
    break;

  case 377: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1887 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5372 "conf_parser.c"
    break;

  case 378: /* $@19: %empty  */
#line 1893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5381 "conf_parser.c"
    break;

  case 382: /* cluster_type_item: KLINE  */
#line 1900 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5390 "conf_parser.c"
    break;

  case 383: /* cluster_type_item: UNKLINE  */
#line 1904 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5399 "conf_parser.c"
    break;

  case 384: /* cluster_type_item: T_DLINE  */
#line 1908 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5408 "conf_parser.c"
    break;

  case 385: /* cluster_type_item: T_UNDLINE  */
#line 1912 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5417 "conf_parser.c"
    break;

  case 386: /* cluster_type_item: XLINE  */
#line 1916 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5426 "conf_parser.c"
    break;

  case 387: /* cluster_type_item: T_UNXLINE  */
#line 1920 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5435 "conf_parser.c"
    break;

  case 388: /* cluster_type_item: RESV  */
#line 1924 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5444 "conf_parser.c"
    break;

  case 389: /* cluster_type_item: T_UNRESV  */
#line 1928 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5453 "conf_parser.c"
    break;

  case 390: /* cluster_type_item: T_LOCOPS  */
#line 1932 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5462 "conf_parser.c"
    break;

  case 391: /* cluster_type_item: T_ALL  */
#line 1936 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5471 "conf_parser.c"
    break;

  case 392: /* $@20: %empty  */
#line 1946 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5486 "conf_parser.c"
    break;

  case 393: /* connect_entry: CONNECT $@20 '{' connect_items '}' ';'  */
#line 1956 "conf_parser.y"
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
#line 5557 "conf_parser.c"
    break;

  case 412: /* connect_name: NAME '=' QSTRING ';'  */
#line 2042 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5566 "conf_parser.c"
    break;

  case 413: /* connect_host: HOST '=' QSTRING ';'  */
#line 2048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5575 "conf_parser.c"
    break;

  case 414: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 2054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5584 "conf_parser.c"
    break;

  case 415: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 2060 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5593 "conf_parser.c"
    break;

  case 416: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2066 "conf_parser.y"
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
#line 5609 "conf_parser.c"
    break;

  case 417: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2079 "conf_parser.y"
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
#line 5625 "conf_parser.c"
    break;

  case 418: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5634 "conf_parser.c"
    break;

  case 419: /* connect_port: PORT '=' NUMBER ';'  */
#line 2098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5643 "conf_parser.c"
    break;

  case 420: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5652 "conf_parser.c"
    break;

  case 421: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5661 "conf_parser.c"
    break;

  case 422: /* $@21: %empty  */
#line 2114 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5669 "conf_parser.c"
    break;

  case 426: /* connect_flags_item: AUTOCONN  */
#line 2120 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5678 "conf_parser.c"
    break;

  case 427: /* connect_flags_item: T_TLS  */
#line 2124 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5687 "conf_parser.c"
    break;

  case 428: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2130 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5701 "conf_parser.c"
    break;

  case 429: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2141 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5710 "conf_parser.c"
    break;

  case 430: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2147 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5719 "conf_parser.c"
    break;

  case 431: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2153 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5728 "conf_parser.c"
    break;

  case 432: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2159 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5742 "conf_parser.c"
    break;

  case 433: /* $@22: %empty  */
#line 2174 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5751 "conf_parser.c"
    break;

  case 434: /* kill_entry: KILL $@22 '{' kill_items '}' ';'  */
#line 2178 "conf_parser.y"
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
#line 5774 "conf_parser.c"
    break;

  case 440: /* kill_user: USER '=' QSTRING ';'  */
#line 2201 "conf_parser.y"
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
#line 5797 "conf_parser.c"
    break;

  case 441: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2221 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5806 "conf_parser.c"
    break;

  case 442: /* $@23: %empty  */
#line 2231 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5815 "conf_parser.c"
    break;

  case 443: /* deny_entry: DENY $@23 '{' deny_items '}' ';'  */
#line 2235 "conf_parser.y"
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
#line 5839 "conf_parser.c"
    break;

  case 449: /* deny_ip: IP '=' QSTRING ';'  */
#line 2259 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5848 "conf_parser.c"
    break;

  case 450: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2265 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5857 "conf_parser.c"
    break;

  case 456: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2280 "conf_parser.y"
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
#line 5874 "conf_parser.c"
    break;

  case 457: /* $@24: %empty  */
#line 2297 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5883 "conf_parser.c"
    break;

  case 458: /* gecos_entry: GECOS $@24 '{' gecos_items '}' ';'  */
#line 2301 "conf_parser.y"
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
#line 5903 "conf_parser.c"
    break;

  case 464: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2321 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5912 "conf_parser.c"
    break;

  case 465: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2327 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5921 "conf_parser.c"
    break;

  case 515: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2388 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5929 "conf_parser.c"
    break;

  case 516: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2393 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5937 "conf_parser.c"
    break;

  case 517: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2398 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5945 "conf_parser.c"
    break;

  case 518: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2403 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5953 "conf_parser.c"
    break;

  case 519: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2408 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5961 "conf_parser.c"
    break;

  case 520: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2413 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5969 "conf_parser.c"
    break;

  case 521: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2418 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5977 "conf_parser.c"
    break;

  case 522: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2423 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5985 "conf_parser.c"
    break;

  case 523: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2428 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5993 "conf_parser.c"
    break;

  case 524: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2433 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6001 "conf_parser.c"
    break;

  case 525: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2438 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 6009 "conf_parser.c"
    break;

  case 526: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2443 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 6017 "conf_parser.c"
    break;

  case 527: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2448 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6025 "conf_parser.c"
    break;

  case 528: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2453 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6033 "conf_parser.c"
    break;

  case 529: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2458 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6041 "conf_parser.c"
    break;

  case 530: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2463 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6049 "conf_parser.c"
    break;

  case 531: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2468 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6057 "conf_parser.c"
    break;

  case 532: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2473 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6065 "conf_parser.c"
    break;

  case 533: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2478 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6073 "conf_parser.c"
    break;

  case 534: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2483 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6081 "conf_parser.c"
    break;

  case 535: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2488 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6089 "conf_parser.c"
    break;

  case 536: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2493 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 6097 "conf_parser.c"
    break;

  case 537: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2498 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 6105 "conf_parser.c"
    break;

  case 538: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2503 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 6113 "conf_parser.c"
    break;

  case 539: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2508 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6121 "conf_parser.c"
    break;

  case 540: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2513 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 6129 "conf_parser.c"
    break;

  case 541: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2518 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 6137 "conf_parser.c"
    break;

  case 542: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2523 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6145 "conf_parser.c"
    break;

  case 543: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2528 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6153 "conf_parser.c"
    break;

  case 544: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2533 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6161 "conf_parser.c"
    break;

  case 545: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2538 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6169 "conf_parser.c"
    break;

  case 546: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2543 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6177 "conf_parser.c"
    break;

  case 547: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2548 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6185 "conf_parser.c"
    break;

  case 548: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2553 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6193 "conf_parser.c"
    break;

  case 549: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2558 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6201 "conf_parser.c"
    break;

  case 550: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2563 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6209 "conf_parser.c"
    break;

  case 551: /* general_disable_auth: DISABLE_AUTH '=' TBOOL ';'  */
#line 2568 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6217 "conf_parser.c"
    break;

  case 552: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2573 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6225 "conf_parser.c"
    break;

  case 553: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2578 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6233 "conf_parser.c"
    break;

  case 554: /* $@25: %empty  */
#line 2583 "conf_parser.y"
{
  ConfigGeneral.oper_umodes = 0;
}
#line 6241 "conf_parser.c"
    break;

  case 558: /* umode_oitem: BOT  */
#line 2589 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_BOT;
}
#line 6249 "conf_parser.c"
    break;

  case 559: /* umode_oitem: T_CCONN  */
#line 2592 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6257 "conf_parser.c"
    break;

  case 560: /* umode_oitem: T_DEAF  */
#line 2595 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6265 "conf_parser.c"
    break;

  case 561: /* umode_oitem: T_DEBUG  */
#line 2598 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6273 "conf_parser.c"
    break;

  case 562: /* umode_oitem: T_FLOOD  */
#line 2601 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FLOOD;
}
#line 6281 "conf_parser.c"
    break;

  case 563: /* umode_oitem: HIDDEN  */
#line 2604 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6289 "conf_parser.c"
    break;

  case 564: /* umode_oitem: HIDE_CHANS  */
#line 2607 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6297 "conf_parser.c"
    break;

  case 565: /* umode_oitem: HIDE_IDLE  */
#line 2610 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6305 "conf_parser.c"
    break;

  case 566: /* umode_oitem: T_SKILL  */
#line 2613 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6313 "conf_parser.c"
    break;

  case 567: /* umode_oitem: T_NCHANGE  */
#line 2616 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6321 "conf_parser.c"
    break;

  case 568: /* umode_oitem: T_REJ  */
#line 2619 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6329 "conf_parser.c"
    break;

  case 569: /* umode_oitem: T_SPY  */
#line 2622 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6337 "conf_parser.c"
    break;

  case 570: /* umode_oitem: T_EXTERNAL  */
#line 2625 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6345 "conf_parser.c"
    break;

  case 571: /* umode_oitem: T_SERVNOTICE  */
#line 2628 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6353 "conf_parser.c"
    break;

  case 572: /* umode_oitem: T_INVISIBLE  */
#line 2631 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6361 "conf_parser.c"
    break;

  case 573: /* umode_oitem: T_WALLOP  */
#line 2634 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6369 "conf_parser.c"
    break;

  case 574: /* umode_oitem: T_SOFTCALLERID  */
#line 2637 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6377 "conf_parser.c"
    break;

  case 575: /* umode_oitem: T_CALLERID  */
#line 2640 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6385 "conf_parser.c"
    break;

  case 576: /* umode_oitem: T_LOCOPS  */
#line 2643 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6393 "conf_parser.c"
    break;

  case 577: /* umode_oitem: T_NONONREG  */
#line 2646 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6401 "conf_parser.c"
    break;

  case 578: /* umode_oitem: T_FARCONNECT  */
#line 2649 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6409 "conf_parser.c"
    break;

  case 579: /* umode_oitem: EXPIRATION  */
#line 2652 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6417 "conf_parser.c"
    break;

  case 580: /* $@26: %empty  */
#line 2657 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6425 "conf_parser.c"
    break;

  case 584: /* umode_item: BOT  */
#line 2663 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_BOT;
}
#line 6433 "conf_parser.c"
    break;

  case 585: /* umode_item: T_CCONN  */
#line 2666 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6441 "conf_parser.c"
    break;

  case 586: /* umode_item: T_DEAF  */
#line 2669 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6449 "conf_parser.c"
    break;

  case 587: /* umode_item: T_DEBUG  */
#line 2672 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6457 "conf_parser.c"
    break;

  case 588: /* umode_item: T_FLOOD  */
#line 2675 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FLOOD;
}
#line 6465 "conf_parser.c"
    break;

  case 589: /* umode_item: T_SKILL  */
#line 2678 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6473 "conf_parser.c"
    break;

  case 590: /* umode_item: HIDDEN  */
#line 2681 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6481 "conf_parser.c"
    break;

  case 591: /* umode_item: HIDE_CHANS  */
#line 2684 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDECHANS;
}
#line 6489 "conf_parser.c"
    break;

  case 592: /* umode_item: HIDE_IDLE  */
#line 2687 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDEIDLE;
}
#line 6497 "conf_parser.c"
    break;

  case 593: /* umode_item: T_NCHANGE  */
#line 2690 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6505 "conf_parser.c"
    break;

  case 594: /* umode_item: T_REJ  */
#line 2693 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6513 "conf_parser.c"
    break;

  case 595: /* umode_item: T_SPY  */
#line 2696 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6521 "conf_parser.c"
    break;

  case 596: /* umode_item: T_EXTERNAL  */
#line 2699 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6529 "conf_parser.c"
    break;

  case 597: /* umode_item: T_SERVNOTICE  */
#line 2702 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6537 "conf_parser.c"
    break;

  case 598: /* umode_item: T_INVISIBLE  */
#line 2705 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6545 "conf_parser.c"
    break;

  case 599: /* umode_item: T_WALLOP  */
#line 2708 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6553 "conf_parser.c"
    break;

  case 600: /* umode_item: T_SOFTCALLERID  */
#line 2711 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6561 "conf_parser.c"
    break;

  case 601: /* umode_item: T_CALLERID  */
#line 2714 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6569 "conf_parser.c"
    break;

  case 602: /* umode_item: T_LOCOPS  */
#line 2717 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6577 "conf_parser.c"
    break;

  case 603: /* umode_item: T_NONONREG  */
#line 2720 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6585 "conf_parser.c"
    break;

  case 604: /* umode_item: T_FARCONNECT  */
#line 2723 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6593 "conf_parser.c"
    break;

  case 605: /* umode_item: EXPIRATION  */
#line 2726 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6601 "conf_parser.c"
    break;

  case 606: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2731 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6609 "conf_parser.c"
    break;

  case 607: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2736 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6617 "conf_parser.c"
    break;

  case 608: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2741 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6625 "conf_parser.c"
    break;

  case 609: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2746 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6633 "conf_parser.c"
    break;

  case 631: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2777 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6641 "conf_parser.c"
    break;

  case 632: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2782 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6650 "conf_parser.c"
    break;

  case 633: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2788 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6659 "conf_parser.c"
    break;

  case 634: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2794 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6667 "conf_parser.c"
    break;

  case 635: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2799 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6675 "conf_parser.c"
    break;

  case 636: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2804 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6683 "conf_parser.c"
    break;

  case 637: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2809 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6691 "conf_parser.c"
    break;

  case 638: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2814 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6699 "conf_parser.c"
    break;

  case 639: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2819 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6707 "conf_parser.c"
    break;

  case 640: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2824 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6715 "conf_parser.c"
    break;

  case 641: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2829 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6723 "conf_parser.c"
    break;

  case 642: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2834 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6731 "conf_parser.c"
    break;

  case 643: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2839 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6739 "conf_parser.c"
    break;

  case 644: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2844 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6747 "conf_parser.c"
    break;

  case 645: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2849 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6755 "conf_parser.c"
    break;

  case 646: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2854 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6763 "conf_parser.c"
    break;

  case 647: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2859 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6771 "conf_parser.c"
    break;

  case 661: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2882 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6780 "conf_parser.c"
    break;

  case 662: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2888 "conf_parser.y"
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
#line 6799 "conf_parser.c"
    break;

  case 663: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2904 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6811 "conf_parser.c"
    break;

  case 664: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2913 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6820 "conf_parser.c"
    break;

  case 665: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2919 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6829 "conf_parser.c"
    break;

  case 666: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2925 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6838 "conf_parser.c"
    break;

  case 667: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2931 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6850 "conf_parser.c"
    break;

  case 668: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2940 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6859 "conf_parser.c"
    break;

  case 669: /* serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'  */
#line 2946 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6868 "conf_parser.c"
    break;


#line 6872 "conf_parser.c"

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

