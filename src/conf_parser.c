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
    MASS = 342,                    /* MASS  */
    MAX_ACCEPT = 343,              /* MAX_ACCEPT  */
    MAX_BANS = 344,                /* MAX_BANS  */
    MAX_BANS_LARGE = 345,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 346,            /* MAX_CHANNELS  */
    MAX_IDLE = 347,                /* MAX_IDLE  */
    MAX_INVITES = 348,             /* MAX_INVITES  */
    MAX_MONITOR = 349,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 350,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 351,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 352,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 353,              /* MAX_NUMBER  */
    MAX_TARGETS = 354,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 355,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 356,                 /* MESSAGE  */
    MIN_IDLE = 357,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 358,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 359,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 360,                  /* MODULE  */
    MODULES = 361,                 /* MODULES  */
    MOTD = 362,                    /* MOTD  */
    NAME = 363,                    /* NAME  */
    NEED_IDENT = 364,              /* NEED_IDENT  */
    NEED_PASSWORD = 365,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 366,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 367,            /* NETWORK_NAME  */
    NICK = 368,                    /* NICK  */
    NO_OPER_FLOOD = 369,           /* NO_OPER_FLOOD  */
    NO_TILDE = 370,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 371,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 372,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 373,     /* NUMBER_PER_IP_LOCAL  */
    OPER_ONLY_UMODES = 374,        /* OPER_ONLY_UMODES  */
    OPER_UMODES = 375,             /* OPER_UMODES  */
    OPERATOR = 376,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 377,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 378,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 379,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 380,                /* PASSWORD  */
    PATH = 381,                    /* PATH  */
    PING_COOKIE = 382,             /* PING_COOKIE  */
    PING_TIME = 383,               /* PING_TIME  */
    PORT = 384,                    /* PORT  */
    RANDOM_IDLE = 385,             /* RANDOM_IDLE  */
    REASON = 386,                  /* REASON  */
    REDIRPORT = 387,               /* REDIRPORT  */
    REDIRSERV = 388,               /* REDIRSERV  */
    REHASH = 389,                  /* REHASH  */
    REMOTE = 390,                  /* REMOTE  */
    REMOTEBAN = 391,               /* REMOTEBAN  */
    RESV = 392,                    /* RESV  */
    RESV_EXEMPT = 393,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 394,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 395,                 /* SECONDS  */
    MINUTES = 396,                 /* MINUTES  */
    HOURS = 397,                   /* HOURS  */
    DAYS = 398,                    /* DAYS  */
    WEEKS = 399,                   /* WEEKS  */
    MONTHS = 400,                  /* MONTHS  */
    YEARS = 401,                   /* YEARS  */
    SEND_PASSWORD = 402,           /* SEND_PASSWORD  */
    SENDQ = 403,                   /* SENDQ  */
    SERVERHIDE = 404,              /* SERVERHIDE  */
    SERVERINFO = 405,              /* SERVERINFO  */
    SHORT_MOTD = 406,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 407,       /* SPECIALS_IN_IDENT  */
    SPOOF = 408,                   /* SPOOF  */
    SQUIT = 409,                   /* SQUIT  */
    STATS_E_DISABLED = 410,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 411,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 412,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 413,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 414,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 415,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 416,       /* STATS_U_OPER_ONLY  */
    T_ALL = 417,                   /* T_ALL  */
    T_BIND = 418,                  /* T_BIND  */
    T_CALLERID = 419,              /* T_CALLERID  */
    T_CCONN = 420,                 /* T_CCONN  */
    T_COMMAND = 421,               /* T_COMMAND  */
    T_CLUSTER = 422,               /* T_CLUSTER  */
    T_DEAF = 423,                  /* T_DEAF  */
    T_DEBUG = 424,                 /* T_DEBUG  */
    T_DLINE = 425,                 /* T_DLINE  */
    T_EXTERNAL = 426,              /* T_EXTERNAL  */
    T_FARCONNECT = 427,            /* T_FARCONNECT  */
    T_FILE = 428,                  /* T_FILE  */
    T_FLOOD = 429,                 /* T_FLOOD  */
    T_GLOBOPS = 430,               /* T_GLOBOPS  */
    T_INVISIBLE = 431,             /* T_INVISIBLE  */
    T_IPV4 = 432,                  /* T_IPV4  */
    T_IPV6 = 433,                  /* T_IPV6  */
    T_LOCOPS = 434,                /* T_LOCOPS  */
    T_LOG = 435,                   /* T_LOG  */
    T_NCHANGE = 436,               /* T_NCHANGE  */
    T_NONONREG = 437,              /* T_NONONREG  */
    T_OPME = 438,                  /* T_OPME  */
    T_PREPEND = 439,               /* T_PREPEND  */
    T_PSEUDO = 440,                /* T_PSEUDO  */
    T_RECVQ = 441,                 /* T_RECVQ  */
    T_REJ = 442,                   /* T_REJ  */
    T_RESTART = 443,               /* T_RESTART  */
    T_SECUREONLY = 444,            /* T_SECUREONLY  */
    T_SERVER = 445,                /* T_SERVER  */
    T_SERVICE = 446,               /* T_SERVICE  */
    T_SERVNOTICE = 447,            /* T_SERVNOTICE  */
    T_SET = 448,                   /* T_SET  */
    T_SHARED = 449,                /* T_SHARED  */
    T_SIZE = 450,                  /* T_SIZE  */
    T_SKILL = 451,                 /* T_SKILL  */
    T_SOFTCALLERID = 452,          /* T_SOFTCALLERID  */
    T_SPY = 453,                   /* T_SPY  */
    T_TARGET = 454,                /* T_TARGET  */
    T_TLS = 455,                   /* T_TLS  */
    T_UMODES = 456,                /* T_UMODES  */
    T_UNDLINE = 457,               /* T_UNDLINE  */
    T_UNLIMITED = 458,             /* T_UNLIMITED  */
    T_UNRESV = 459,                /* T_UNRESV  */
    T_UNXLINE = 460,               /* T_UNXLINE  */
    T_WALLOP = 461,                /* T_WALLOP  */
    T_WALLOPS = 462,               /* T_WALLOPS  */
    T_WEBIRC = 463,                /* T_WEBIRC  */
    TBOOL = 464,                   /* TBOOL  */
    THROTTLE_COUNT = 465,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 466,           /* THROTTLE_TIME  */
    TIMEOUT = 467,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 468,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 469, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 470,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 471,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 472, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 473,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 474, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 475,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 476,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 477,           /* TS_WARN_DELTA  */
    TWODOTS = 478,                 /* TWODOTS  */
    TYPE = 479,                    /* TYPE  */
    UNKLINE = 480,                 /* UNKLINE  */
    USE_LOGGING = 481,             /* USE_LOGGING  */
    USER = 482,                    /* USER  */
    VHOST = 483,                   /* VHOST  */
    VHOST6 = 484,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 485,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 486,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 487,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 488,                   /* XLINE  */
    XLINE_EXEMPT = 489,            /* XLINE_EXEMPT  */
    QSTRING = 490,                 /* QSTRING  */
    NUMBER = 491                   /* NUMBER  */
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
#define MASS 342
#define MAX_ACCEPT 343
#define MAX_BANS 344
#define MAX_BANS_LARGE 345
#define MAX_CHANNELS 346
#define MAX_IDLE 347
#define MAX_INVITES 348
#define MAX_MONITOR 349
#define MAX_NICK_CHANGES 350
#define MAX_NICK_LENGTH 351
#define MAX_NICK_TIME 352
#define MAX_NUMBER 353
#define MAX_TARGETS 354
#define MAX_TOPIC_LENGTH 355
#define MESSAGE 356
#define MIN_IDLE 357
#define MIN_NONWILDCARD 358
#define MIN_NONWILDCARD_SIMPLE 359
#define MODULE 360
#define MODULES 361
#define MOTD 362
#define NAME 363
#define NEED_IDENT 364
#define NEED_PASSWORD 365
#define NETWORK_DESCRIPTION 366
#define NETWORK_NAME 367
#define NICK 368
#define NO_OPER_FLOOD 369
#define NO_TILDE 370
#define NUMBER_PER_CIDR 371
#define NUMBER_PER_IP_GLOBAL 372
#define NUMBER_PER_IP_LOCAL 373
#define OPER_ONLY_UMODES 374
#define OPER_UMODES 375
#define OPERATOR 376
#define OPERS_BYPASS_CALLERID 377
#define PACE_WAIT 378
#define PACE_WAIT_SIMPLE 379
#define PASSWORD 380
#define PATH 381
#define PING_COOKIE 382
#define PING_TIME 383
#define PORT 384
#define RANDOM_IDLE 385
#define REASON 386
#define REDIRPORT 387
#define REDIRSERV 388
#define REHASH 389
#define REMOTE 390
#define REMOTEBAN 391
#define RESV 392
#define RESV_EXEMPT 393
#define RSA_PRIVATE_KEY_FILE 394
#define SECONDS 395
#define MINUTES 396
#define HOURS 397
#define DAYS 398
#define WEEKS 399
#define MONTHS 400
#define YEARS 401
#define SEND_PASSWORD 402
#define SENDQ 403
#define SERVERHIDE 404
#define SERVERINFO 405
#define SHORT_MOTD 406
#define SPECIALS_IN_IDENT 407
#define SPOOF 408
#define SQUIT 409
#define STATS_E_DISABLED 410
#define STATS_I_OPER_ONLY 411
#define STATS_K_OPER_ONLY 412
#define STATS_M_OPER_ONLY 413
#define STATS_O_OPER_ONLY 414
#define STATS_P_OPER_ONLY 415
#define STATS_U_OPER_ONLY 416
#define T_ALL 417
#define T_BIND 418
#define T_CALLERID 419
#define T_CCONN 420
#define T_COMMAND 421
#define T_CLUSTER 422
#define T_DEAF 423
#define T_DEBUG 424
#define T_DLINE 425
#define T_EXTERNAL 426
#define T_FARCONNECT 427
#define T_FILE 428
#define T_FLOOD 429
#define T_GLOBOPS 430
#define T_INVISIBLE 431
#define T_IPV4 432
#define T_IPV6 433
#define T_LOCOPS 434
#define T_LOG 435
#define T_NCHANGE 436
#define T_NONONREG 437
#define T_OPME 438
#define T_PREPEND 439
#define T_PSEUDO 440
#define T_RECVQ 441
#define T_REJ 442
#define T_RESTART 443
#define T_SECUREONLY 444
#define T_SERVER 445
#define T_SERVICE 446
#define T_SERVNOTICE 447
#define T_SET 448
#define T_SHARED 449
#define T_SIZE 450
#define T_SKILL 451
#define T_SOFTCALLERID 452
#define T_SPY 453
#define T_TARGET 454
#define T_TLS 455
#define T_UMODES 456
#define T_UNDLINE 457
#define T_UNLIMITED 458
#define T_UNRESV 459
#define T_UNXLINE 460
#define T_WALLOP 461
#define T_WALLOPS 462
#define T_WEBIRC 463
#define TBOOL 464
#define THROTTLE_COUNT 465
#define THROTTLE_TIME 466
#define TIMEOUT 467
#define TLS_CERTIFICATE_FILE 468
#define TLS_CERTIFICATE_FINGERPRINT 469
#define TLS_CIPHER_LIST 470
#define TLS_CIPHER_SUITES 471
#define TLS_CONNECTION_REQUIRED 472
#define TLS_DH_PARAM_FILE 473
#define TLS_MESSAGE_DIGEST_ALGORITHM 474
#define TLS_SUPPORTED_GROUPS 475
#define TS_MAX_DELTA 476
#define TS_WARN_DELTA 477
#define TWODOTS 478
#define TYPE 479
#define UNKLINE 480
#define USE_LOGGING 481
#define USER 482
#define VHOST 483
#define VHOST6 484
#define WARN_NO_CONNECT_BLOCK 485
#define WHOIS 486
#define WHOWAS_HISTORY_LENGTH 487
#define XLINE 488
#define XLINE_EXEMPT 489
#define QSTRING 490
#define NUMBER 491

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 132 "conf_parser.y"

  int number;
  char *string;

#line 706 "conf_parser.c"

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
  YYSYMBOL_MASS = 87,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 88,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_BANS = 89,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 90,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 91,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 92,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 93,               /* MAX_INVITES  */
  YYSYMBOL_MAX_MONITOR = 94,               /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 95,          /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 96,           /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 97,             /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 98,                /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 99,               /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 100,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 101,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 102,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 103,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 104,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 105,                   /* MODULE  */
  YYSYMBOL_MODULES = 106,                  /* MODULES  */
  YYSYMBOL_MOTD = 107,                     /* MOTD  */
  YYSYMBOL_NAME = 108,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 109,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 110,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 111,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 112,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 113,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 114,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 115,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 116,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 117,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 118,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_ONLY_UMODES = 119,         /* OPER_ONLY_UMODES  */
  YYSYMBOL_OPER_UMODES = 120,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 121,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 122,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 123,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 124,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 125,                 /* PASSWORD  */
  YYSYMBOL_PATH = 126,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 127,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 128,                /* PING_TIME  */
  YYSYMBOL_PORT = 129,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 130,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 131,                   /* REASON  */
  YYSYMBOL_REDIRPORT = 132,                /* REDIRPORT  */
  YYSYMBOL_REDIRSERV = 133,                /* REDIRSERV  */
  YYSYMBOL_REHASH = 134,                   /* REHASH  */
  YYSYMBOL_REMOTE = 135,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 136,                /* REMOTEBAN  */
  YYSYMBOL_RESV = 137,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 138,              /* RESV_EXEMPT  */
  YYSYMBOL_RSA_PRIVATE_KEY_FILE = 139,     /* RSA_PRIVATE_KEY_FILE  */
  YYSYMBOL_SECONDS = 140,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 141,                  /* MINUTES  */
  YYSYMBOL_HOURS = 142,                    /* HOURS  */
  YYSYMBOL_DAYS = 143,                     /* DAYS  */
  YYSYMBOL_WEEKS = 144,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 145,                   /* MONTHS  */
  YYSYMBOL_YEARS = 146,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 147,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 148,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 149,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 150,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 151,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 152,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 153,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 154,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 155,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_I_OPER_ONLY = 156,        /* STATS_I_OPER_ONLY  */
  YYSYMBOL_STATS_K_OPER_ONLY = 157,        /* STATS_K_OPER_ONLY  */
  YYSYMBOL_STATS_M_OPER_ONLY = 158,        /* STATS_M_OPER_ONLY  */
  YYSYMBOL_STATS_O_OPER_ONLY = 159,        /* STATS_O_OPER_ONLY  */
  YYSYMBOL_STATS_P_OPER_ONLY = 160,        /* STATS_P_OPER_ONLY  */
  YYSYMBOL_STATS_U_OPER_ONLY = 161,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 162,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 163,                   /* T_BIND  */
  YYSYMBOL_T_CALLERID = 164,               /* T_CALLERID  */
  YYSYMBOL_T_CCONN = 165,                  /* T_CCONN  */
  YYSYMBOL_T_COMMAND = 166,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 167,                /* T_CLUSTER  */
  YYSYMBOL_T_DEAF = 168,                   /* T_DEAF  */
  YYSYMBOL_T_DEBUG = 169,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 170,                  /* T_DLINE  */
  YYSYMBOL_T_EXTERNAL = 171,               /* T_EXTERNAL  */
  YYSYMBOL_T_FARCONNECT = 172,             /* T_FARCONNECT  */
  YYSYMBOL_T_FILE = 173,                   /* T_FILE  */
  YYSYMBOL_T_FLOOD = 174,                  /* T_FLOOD  */
  YYSYMBOL_T_GLOBOPS = 175,                /* T_GLOBOPS  */
  YYSYMBOL_T_INVISIBLE = 176,              /* T_INVISIBLE  */
  YYSYMBOL_T_IPV4 = 177,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 178,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 179,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 180,                    /* T_LOG  */
  YYSYMBOL_T_NCHANGE = 181,                /* T_NCHANGE  */
  YYSYMBOL_T_NONONREG = 182,               /* T_NONONREG  */
  YYSYMBOL_T_OPME = 183,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 184,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 185,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 186,                  /* T_RECVQ  */
  YYSYMBOL_T_REJ = 187,                    /* T_REJ  */
  YYSYMBOL_T_RESTART = 188,                /* T_RESTART  */
  YYSYMBOL_T_SECUREONLY = 189,             /* T_SECUREONLY  */
  YYSYMBOL_T_SERVER = 190,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 191,                /* T_SERVICE  */
  YYSYMBOL_T_SERVNOTICE = 192,             /* T_SERVNOTICE  */
  YYSYMBOL_T_SET = 193,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 194,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 195,                   /* T_SIZE  */
  YYSYMBOL_T_SKILL = 196,                  /* T_SKILL  */
  YYSYMBOL_T_SOFTCALLERID = 197,           /* T_SOFTCALLERID  */
  YYSYMBOL_T_SPY = 198,                    /* T_SPY  */
  YYSYMBOL_T_TARGET = 199,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 200,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 201,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 202,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 203,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 204,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 205,                /* T_UNXLINE  */
  YYSYMBOL_T_WALLOP = 206,                 /* T_WALLOP  */
  YYSYMBOL_T_WALLOPS = 207,                /* T_WALLOPS  */
  YYSYMBOL_T_WEBIRC = 208,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 209,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 210,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 211,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 212,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 213,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 214, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 215,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 216,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 217,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 218,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 219, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 220,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 221,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 222,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 223,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 224,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 225,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 226,              /* USE_LOGGING  */
  YYSYMBOL_USER = 227,                     /* USER  */
  YYSYMBOL_VHOST = 228,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 229,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 230,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 231,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 232,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 233,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 234,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 235,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 236,                   /* NUMBER  */
  YYSYMBOL_237_ = 237,                     /* ';'  */
  YYSYMBOL_238_ = 238,                     /* '}'  */
  YYSYMBOL_239_ = 239,                     /* '{'  */
  YYSYMBOL_240_ = 240,                     /* '='  */
  YYSYMBOL_241_ = 241,                     /* ','  */
  YYSYMBOL_242_ = 242,                     /* ':'  */
  YYSYMBOL_YYACCEPT = 243,                 /* $accept  */
  YYSYMBOL_conf = 244,                     /* conf  */
  YYSYMBOL_conf_item = 245,                /* conf_item  */
  YYSYMBOL_timespec_ = 246,                /* timespec_  */
  YYSYMBOL_timespec = 247,                 /* timespec  */
  YYSYMBOL_sizespec_ = 248,                /* sizespec_  */
  YYSYMBOL_sizespec = 249,                 /* sizespec  */
  YYSYMBOL_modules_entry = 250,            /* modules_entry  */
  YYSYMBOL_modules_items = 251,            /* modules_items  */
  YYSYMBOL_modules_item = 252,             /* modules_item  */
  YYSYMBOL_modules_module = 253,           /* modules_module  */
  YYSYMBOL_modules_path = 254,             /* modules_path  */
  YYSYMBOL_serverinfo_entry = 255,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 256,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 257,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 258, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 259, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 260, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 261, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 262, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 263, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 264, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 265,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 266,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 267,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 268,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 269, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 270, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 271, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 272, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_hub = 273,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 274,              /* admin_entry  */
  YYSYMBOL_admin_items = 275,              /* admin_items  */
  YYSYMBOL_admin_item = 276,               /* admin_item  */
  YYSYMBOL_admin_name = 277,               /* admin_name  */
  YYSYMBOL_admin_email = 278,              /* admin_email  */
  YYSYMBOL_admin_description = 279,        /* admin_description  */
  YYSYMBOL_motd_entry = 280,               /* motd_entry  */
  YYSYMBOL_281_1 = 281,                    /* $@1  */
  YYSYMBOL_motd_items = 282,               /* motd_items  */
  YYSYMBOL_motd_item = 283,                /* motd_item  */
  YYSYMBOL_motd_mask = 284,                /* motd_mask  */
  YYSYMBOL_motd_file = 285,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 286,             /* pseudo_entry  */
  YYSYMBOL_287_2 = 287,                    /* $@2  */
  YYSYMBOL_pseudo_items = 288,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 289,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 290,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 291,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 292,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 293,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 294,            /* logging_entry  */
  YYSYMBOL_logging_items = 295,            /* logging_items  */
  YYSYMBOL_logging_item = 296,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 297,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 298,       /* logging_file_entry  */
  YYSYMBOL_299_3 = 299,                    /* $@3  */
  YYSYMBOL_logging_file_items = 300,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 301,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 302,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 303,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 304,        /* logging_file_type  */
  YYSYMBOL_305_4 = 305,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 306,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 307,               /* oper_entry  */
  YYSYMBOL_308_5 = 308,                    /* $@5  */
  YYSYMBOL_oper_items = 309,               /* oper_items  */
  YYSYMBOL_oper_item = 310,                /* oper_item  */
  YYSYMBOL_oper_name = 311,                /* oper_name  */
  YYSYMBOL_oper_user = 312,                /* oper_user  */
  YYSYMBOL_oper_password = 313,            /* oper_password  */
  YYSYMBOL_oper_whois = 314,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 315,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 316, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 317, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 318,               /* oper_class  */
  YYSYMBOL_oper_umodes = 319,              /* oper_umodes  */
  YYSYMBOL_320_6 = 320,                    /* $@6  */
  YYSYMBOL_oper_umodes_items = 321,        /* oper_umodes_items  */
  YYSYMBOL_oper_umodes_item = 322,         /* oper_umodes_item  */
  YYSYMBOL_oper_flags = 323,               /* oper_flags  */
  YYSYMBOL_324_7 = 324,                    /* $@7  */
  YYSYMBOL_oper_flags_items = 325,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 326,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 327,              /* class_entry  */
  YYSYMBOL_328_8 = 328,                    /* $@8  */
  YYSYMBOL_class_items = 329,              /* class_items  */
  YYSYMBOL_class_item = 330,               /* class_item  */
  YYSYMBOL_class_name = 331,               /* class_name  */
  YYSYMBOL_class_ping_time = 332,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 333, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 334, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 335,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 336,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 337,         /* class_max_number  */
  YYSYMBOL_class_sendq = 338,              /* class_sendq  */
  YYSYMBOL_class_recvq = 339,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 340,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 341,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 342,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 343,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 344,           /* class_max_idle  */
  YYSYMBOL_class_flags = 345,              /* class_flags  */
  YYSYMBOL_346_9 = 346,                    /* $@9  */
  YYSYMBOL_class_flags_items = 347,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 348,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 349,             /* listen_entry  */
  YYSYMBOL_350_10 = 350,                   /* $@10  */
  YYSYMBOL_listen_flags = 351,             /* listen_flags  */
  YYSYMBOL_352_11 = 352,                   /* $@11  */
  YYSYMBOL_listen_flags_items = 353,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 354,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 355,             /* listen_items  */
  YYSYMBOL_listen_item = 356,              /* listen_item  */
  YYSYMBOL_listen_port = 357,              /* listen_port  */
  YYSYMBOL_358_12 = 358,                   /* $@12  */
  YYSYMBOL_port_items = 359,               /* port_items  */
  YYSYMBOL_port_item = 360,                /* port_item  */
  YYSYMBOL_listen_address = 361,           /* listen_address  */
  YYSYMBOL_listen_host = 362,              /* listen_host  */
  YYSYMBOL_auth_entry = 363,               /* auth_entry  */
  YYSYMBOL_364_13 = 364,                   /* $@13  */
  YYSYMBOL_auth_items = 365,               /* auth_items  */
  YYSYMBOL_auth_item = 366,                /* auth_item  */
  YYSYMBOL_auth_user = 367,                /* auth_user  */
  YYSYMBOL_auth_passwd = 368,              /* auth_passwd  */
  YYSYMBOL_auth_class = 369,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 370,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 371,               /* auth_flags  */
  YYSYMBOL_372_14 = 372,                   /* $@14  */
  YYSYMBOL_auth_flags_items = 373,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 374,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 375,               /* auth_spoof  */
  YYSYMBOL_auth_redir_serv = 376,          /* auth_redir_serv  */
  YYSYMBOL_auth_redir_port = 377,          /* auth_redir_port  */
  YYSYMBOL_resv_entry = 378,               /* resv_entry  */
  YYSYMBOL_379_15 = 379,                   /* $@15  */
  YYSYMBOL_resv_items = 380,               /* resv_items  */
  YYSYMBOL_resv_item = 381,                /* resv_item  */
  YYSYMBOL_resv_mask = 382,                /* resv_mask  */
  YYSYMBOL_resv_reason = 383,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 384,              /* resv_exempt  */
  YYSYMBOL_service_entry = 385,            /* service_entry  */
  YYSYMBOL_service_items = 386,            /* service_items  */
  YYSYMBOL_service_item = 387,             /* service_item  */
  YYSYMBOL_service_name = 388,             /* service_name  */
  YYSYMBOL_shared_entry = 389,             /* shared_entry  */
  YYSYMBOL_390_16 = 390,                   /* $@16  */
  YYSYMBOL_shared_items = 391,             /* shared_items  */
  YYSYMBOL_shared_item = 392,              /* shared_item  */
  YYSYMBOL_shared_name = 393,              /* shared_name  */
  YYSYMBOL_shared_user = 394,              /* shared_user  */
  YYSYMBOL_shared_type = 395,              /* shared_type  */
  YYSYMBOL_396_17 = 396,                   /* $@17  */
  YYSYMBOL_shared_types = 397,             /* shared_types  */
  YYSYMBOL_shared_type_item = 398,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 399,            /* cluster_entry  */
  YYSYMBOL_400_18 = 400,                   /* $@18  */
  YYSYMBOL_cluster_items = 401,            /* cluster_items  */
  YYSYMBOL_cluster_item = 402,             /* cluster_item  */
  YYSYMBOL_cluster_name = 403,             /* cluster_name  */
  YYSYMBOL_cluster_type = 404,             /* cluster_type  */
  YYSYMBOL_405_19 = 405,                   /* $@19  */
  YYSYMBOL_cluster_types = 406,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 407,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 408,            /* connect_entry  */
  YYSYMBOL_409_20 = 409,                   /* $@20  */
  YYSYMBOL_connect_items = 410,            /* connect_items  */
  YYSYMBOL_connect_item = 411,             /* connect_item  */
  YYSYMBOL_connect_name = 412,             /* connect_name  */
  YYSYMBOL_connect_host = 413,             /* connect_host  */
  YYSYMBOL_connect_timeout = 414,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 415,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 416,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 417,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 418, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 419,             /* connect_port  */
  YYSYMBOL_connect_aftype = 420,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 421,            /* connect_flags  */
  YYSYMBOL_422_21 = 422,                   /* $@21  */
  YYSYMBOL_connect_flags_items = 423,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 424,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 425,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 426,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 427,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 428,            /* connect_class  */
  YYSYMBOL_connect_tls_cipher_list = 429,  /* connect_tls_cipher_list  */
  YYSYMBOL_kill_entry = 430,               /* kill_entry  */
  YYSYMBOL_431_22 = 431,                   /* $@22  */
  YYSYMBOL_kill_items = 432,               /* kill_items  */
  YYSYMBOL_kill_item = 433,                /* kill_item  */
  YYSYMBOL_kill_user = 434,                /* kill_user  */
  YYSYMBOL_kill_reason = 435,              /* kill_reason  */
  YYSYMBOL_deny_entry = 436,               /* deny_entry  */
  YYSYMBOL_437_23 = 437,                   /* $@23  */
  YYSYMBOL_deny_items = 438,               /* deny_items  */
  YYSYMBOL_deny_item = 439,                /* deny_item  */
  YYSYMBOL_deny_ip = 440,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 441,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 442,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 443,             /* exempt_items  */
  YYSYMBOL_exempt_item = 444,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 445,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 446,              /* gecos_entry  */
  YYSYMBOL_447_24 = 447,                   /* $@24  */
  YYSYMBOL_gecos_items = 448,              /* gecos_items  */
  YYSYMBOL_gecos_item = 449,               /* gecos_item  */
  YYSYMBOL_gecos_name = 450,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 451,             /* gecos_reason  */
  YYSYMBOL_general_entry = 452,            /* general_entry  */
  YYSYMBOL_general_items = 453,            /* general_items  */
  YYSYMBOL_general_item = 454,             /* general_item  */
  YYSYMBOL_general_away_count = 455,       /* general_away_count  */
  YYSYMBOL_general_away_time = 456,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 457,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 458, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 459, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 460,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 461,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 462,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 463,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 464, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 465, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 466,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 467,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 468, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 469,       /* general_max_accept  */
  YYSYMBOL_general_anti_spam_exit_message_time = 470, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 471,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 472,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 473, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 474, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 475, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 476, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 477, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 478, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 479, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 480, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 481, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 482,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 483,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 484, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 485, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 486,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 487,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 488, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 489,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 490,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_auth = 491,     /* general_disable_auth  */
  YYSYMBOL_general_throttle_count = 492,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 493,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 494,      /* general_oper_umodes  */
  YYSYMBOL_495_25 = 495,                   /* $@25  */
  YYSYMBOL_umode_oitems = 496,             /* umode_oitems  */
  YYSYMBOL_umode_oitem = 497,              /* umode_oitem  */
  YYSYMBOL_general_oper_only_umodes = 498, /* general_oper_only_umodes  */
  YYSYMBOL_499_26 = 499,                   /* $@26  */
  YYSYMBOL_umode_items = 500,              /* umode_items  */
  YYSYMBOL_umode_item = 501,               /* umode_item  */
  YYSYMBOL_general_min_nonwildcard = 502,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 503, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 504, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 505, /* general_default_floodtime  */
  YYSYMBOL_channel_entry = 506,            /* channel_entry  */
  YYSYMBOL_channel_items = 507,            /* channel_items  */
  YYSYMBOL_channel_item = 508,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 509,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 510,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 511,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 512, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 513, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 514, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 515, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 516, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 517, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 518, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 519, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 520,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 521,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 522,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 523,   /* channel_max_bans_large  */
  YYSYMBOL_channel_default_join_flood_count = 524, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 525, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 526,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 527,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 528,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 529, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 530, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 531, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 532, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 533,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 534, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 535,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 536,        /* serverhide_hidden  */
  YYSYMBOL_serverhide_hide_server_ips = 537 /* serverhide_hide_server_ips  */
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
#define YYLAST   1255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  243
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  295
/* YYNRULES -- Number of rules.  */
#define YYNRULES  670
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1323

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   491


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
       2,     2,     2,     2,   241,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   242,   237,
       2,   240,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   239,     2,   238,     2,     2,     2,     2,
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
     235,   236
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   370,   370,   371,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   401,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   412,   412,
     413,   414,   415,   416,   423,   425,   425,   426,   426,   426,
     428,   434,   444,   446,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   466,   475,   484,   493,   502,   511,   520,   529,
     544,   559,   569,   583,   592,   615,   638,   661,   671,   673,
     673,   674,   675,   676,   677,   679,   688,   697,   711,   710,
     728,   728,   729,   729,   729,   731,   737,   748,   747,   766,
     766,   767,   767,   767,   767,   767,   769,   775,   781,   787,
     810,   811,   811,   813,   813,   814,   816,   823,   823,   836,
     837,   839,   839,   840,   840,   842,   850,   853,   859,   858,
     864,   868,   872,   876,   880,   884,   888,   892,   903,   902,
     966,   966,   967,   968,   969,   970,   971,   972,   973,   974,
     975,   976,   977,   979,   985,   991,   997,  1003,  1014,  1020,
    1031,  1038,  1037,  1043,  1043,  1044,  1048,  1052,  1056,  1060,
    1064,  1068,  1072,  1076,  1080,  1084,  1088,  1092,  1096,  1100,
    1104,  1108,  1112,  1116,  1120,  1124,  1128,  1135,  1134,  1140,
    1140,  1141,  1145,  1149,  1153,  1157,  1161,  1165,  1169,  1173,
    1177,  1181,  1185,  1189,  1193,  1197,  1201,  1205,  1209,  1213,
    1217,  1221,  1225,  1229,  1233,  1237,  1241,  1245,  1249,  1253,
    1257,  1268,  1267,  1323,  1323,  1324,  1325,  1326,  1327,  1328,
    1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,  1337,  1338,
    1339,  1341,  1347,  1353,  1359,  1365,  1371,  1377,  1383,  1389,
    1396,  1402,  1408,  1414,  1423,  1433,  1432,  1438,  1438,  1439,
    1443,  1454,  1453,  1460,  1459,  1464,  1464,  1465,  1469,  1473,
    1477,  1481,  1487,  1487,  1488,  1488,  1488,  1488,  1488,  1490,
    1490,  1492,  1492,  1494,  1507,  1524,  1530,  1541,  1540,  1588,
    1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,  1596,  1597,
    1599,  1605,  1611,  1617,  1629,  1628,  1634,  1634,  1635,  1639,
    1643,  1647,  1651,  1655,  1659,  1663,  1667,  1673,  1687,  1696,
    1710,  1709,  1724,  1724,  1725,  1725,  1725,  1725,  1727,  1733,
    1739,  1749,  1751,  1751,  1752,  1752,  1754,  1771,  1770,  1793,
    1793,  1794,  1794,  1794,  1794,  1796,  1802,  1822,  1821,  1827,
    1827,  1828,  1832,  1836,  1840,  1844,  1848,  1852,  1856,  1860,
    1864,  1875,  1874,  1893,  1893,  1894,  1894,  1894,  1896,  1903,
    1902,  1908,  1908,  1909,  1913,  1917,  1921,  1925,  1929,  1933,
    1937,  1941,  1945,  1956,  1955,  2033,  2033,  2034,  2035,  2036,
    2037,  2038,  2039,  2040,  2041,  2042,  2043,  2044,  2045,  2046,
    2047,  2048,  2049,  2051,  2057,  2063,  2069,  2075,  2088,  2101,
    2107,  2113,  2117,  2124,  2123,  2128,  2128,  2129,  2133,  2139,
    2150,  2156,  2162,  2168,  2184,  2183,  2207,  2207,  2208,  2208,
    2208,  2210,  2230,  2241,  2240,  2265,  2265,  2266,  2266,  2266,
    2268,  2274,  2284,  2286,  2286,  2287,  2287,  2289,  2307,  2306,
    2327,  2327,  2328,  2328,  2328,  2330,  2336,  2346,  2348,  2348,
    2349,  2350,  2351,  2352,  2353,  2354,  2355,  2356,  2357,  2358,
    2359,  2360,  2361,  2362,  2363,  2364,  2365,  2366,  2367,  2368,
    2369,  2370,  2371,  2372,  2373,  2374,  2375,  2376,  2377,  2378,
    2379,  2380,  2381,  2382,  2383,  2384,  2385,  2386,  2387,  2388,
    2389,  2390,  2391,  2392,  2393,  2394,  2397,  2402,  2407,  2412,
    2417,  2422,  2427,  2432,  2437,  2442,  2447,  2452,  2457,  2462,
    2467,  2472,  2477,  2482,  2487,  2492,  2497,  2502,  2507,  2512,
    2517,  2522,  2527,  2532,  2537,  2542,  2547,  2552,  2557,  2562,
    2567,  2572,  2577,  2582,  2587,  2593,  2592,  2597,  2597,  2598,
    2601,  2604,  2607,  2610,  2613,  2616,  2619,  2622,  2625,  2628,
    2631,  2634,  2637,  2640,  2643,  2646,  2649,  2652,  2655,  2658,
    2661,  2667,  2666,  2671,  2671,  2672,  2675,  2678,  2681,  2684,
    2687,  2690,  2693,  2696,  2699,  2702,  2705,  2708,  2711,  2714,
    2717,  2720,  2723,  2726,  2729,  2732,  2735,  2740,  2745,  2750,
    2755,  2764,  2766,  2766,  2767,  2768,  2769,  2770,  2771,  2772,
    2773,  2774,  2775,  2776,  2777,  2778,  2779,  2780,  2781,  2782,
    2783,  2784,  2786,  2791,  2797,  2803,  2808,  2813,  2818,  2823,
    2828,  2833,  2838,  2843,  2848,  2853,  2858,  2863,  2868,  2877,
    2879,  2879,  2880,  2881,  2882,  2883,  2884,  2885,  2886,  2887,
    2888,  2889,  2891,  2897,  2913,  2922,  2928,  2934,  2940,  2949,
    2955
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

#define YYPACT_NINF (-896)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -896,   851,  -896,  -201,  -213,  -181,  -896,  -896,  -896,  -176,
    -896,  -171,  -896,  -896,  -896,  -170,  -896,  -896,  -896,  -168,
    -155,  -896,  -147,  -896,  -144,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,   327,   926,  -124,  -112,   -80,     2,   -72,   394,   -57,
     -36,   -27,   156,   -18,   -12,   -11,   558,   527,    -1,    98,
      48,    18,    69,  -150,    35,    41,    78,    17,  -896,  -896,
    -896,  -896,  -896,    86,    90,   100,   102,   103,   106,   108,
     121,   122,   123,   125,   126,   128,   129,   130,   131,   137,
     111,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,   843,
     440,    30,  -896,   138,     3,  -896,  -896,   208,  -896,   139,
     140,   144,   145,   146,   147,   150,   151,   153,   154,   158,
     165,   168,   170,   171,   172,   176,   178,   182,   183,   188,
     190,   191,   196,  -896,  -896,   197,   200,   207,   209,   218,
     221,   222,   223,   224,   225,   226,   228,   229,   231,   232,
     243,   245,   246,   247,    14,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,   219,     4,   285,    72,   250,   252,    81,  -896,  -896,
    -896,   148,   309,    37,  -896,   254,   255,   256,   259,   260,
     263,   265,   266,   267,     5,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,   162,   269,   271,   275,   282,
     287,   289,   290,   292,   293,   294,   295,   298,   299,   301,
     302,   303,   118,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
      77,   211,   304,    16,  -896,  -896,  -896,   185,   198,  -896,
     316,    34,  -896,  -896,    21,  -896,   161,   180,   323,   288,
    -896,   152,   325,   353,   355,   356,   357,   331,   325,   325,
     325,   337,   325,   325,   339,   340,   341,   342,   344,  -896,
     345,   343,   346,   348,  -896,   349,   351,   352,   359,   366,
     371,   380,   381,   382,   385,   388,   187,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,   347,   389,   392,   396,   402,   403,   405,
    -896,   408,   409,   410,   413,   416,   417,   418,   419,   212,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,   420,   421,    27,
    -896,  -896,  -896,   350,   360,  -896,  -896,   424,   428,    79,
    -896,  -896,  -896,   370,   325,   433,   325,   325,   384,   434,
     325,   387,   435,   438,   466,   470,   325,   445,   447,   452,
     453,   455,   325,   456,   457,   458,   486,   460,   463,   487,
     325,   325,   488,   489,   473,   501,   502,   504,   506,   507,
     508,   509,   476,   325,   325,   325,   510,   491,   469,  -896,
     492,   485,   494,  -896,   495,   498,   499,   511,   512,    31,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
     513,   516,    85,  -896,  -896,  -896,   496,   517,   519,  -896,
     520,  -896,    26,  -896,  -896,  -896,  -896,  -896,   514,   515,
     500,  -896,   526,   525,   528,    76,  -896,  -896,  -896,   530,
     534,   535,  -896,   536,   538,  -896,   540,   541,   543,   544,
     175,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,   533,   545,   549,   550,    15,  -896,  -896,  -896,
    -896,   522,   523,   325,   556,   532,   557,   539,   584,   588,
     562,  -896,  -896,   564,   568,   596,   572,   574,   577,   573,
     579,   580,   581,   583,   585,   586,   589,   594,   595,   597,
    -896,   600,   602,  -896,    42,  -896,  -896,  -896,  -896,   614,
     603,  -896,   505,   608,   607,   610,   613,   617,    24,  -896,
    -896,  -896,  -896,  -896,   625,   632,  -896,   633,   636,  -896,
     637,    13,  -896,  -896,  -896,  -896,   635,   641,   642,  -896,
     643,   311,   644,   645,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   662,  -896,  -896,
     666,   669,   325,   668,   670,   325,   671,   325,   674,   675,
     676,   677,   325,   678,   678,   673,  -896,  -896,   681,  -130,
     682,   616,   683,   684,   680,   688,   689,   692,   690,   695,
     325,   697,   698,   694,  -896,   702,   703,   705,  -896,   706,
    -896,   704,   709,   710,  -896,   711,   712,   713,   715,   716,
     719,   726,   727,   728,   729,   733,   736,   737,   738,   739,
     740,   741,   742,   743,   744,   745,   746,   747,   748,   590,
     630,   749,   750,   752,   753,   759,   760,   761,   762,   765,
     766,   767,   768,   769,   773,   774,   775,   776,   777,   783,
    -896,  -896,   786,   731,   782,   788,   789,   791,   792,   793,
     787,  -896,   795,   797,   796,  -896,  -896,   799,   800,   798,
     801,   802,  -896,   803,   804,  -896,  -896,   808,   809,   810,
    -896,  -896,   811,   839,   812,   814,   815,   813,   816,   845,
     820,   821,   822,  -896,  -896,   823,   825,   826,   827,  -896,
     828,   829,   830,   831,   832,   833,   834,   835,   836,  -896,
     837,   838,   840,   841,   842,   844,   846,   847,   848,   849,
     850,   852,   853,   854,   855,   856,  -896,  -896,   859,   817,
     858,  -896,   860,  -896,   159,  -896,   861,   863,   864,   865,
     866,  -896,   867,  -896,  -896,   870,   862,   871,   872,  -896,
    -896,  -896,  -896,  -896,   325,   325,   325,   325,   325,   325,
     325,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,   873,
     874,   875,   -25,   876,   877,   878,   879,   880,   881,   882,
     883,   884,    32,   885,   886,  -896,   887,   888,   889,   890,
     891,   892,   893,    22,   894,   895,   896,   897,   898,   899,
     900,   901,  -896,   902,   903,  -896,  -896,   904,   905,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -230,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -167,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,   906,   907,   329,   908,   909,   910,   911,   912,  -896,
     913,   914,  -896,   915,   916,    60,   723,   917,  -896,  -896,
    -896,  -896,   918,   919,  -896,   920,   922,   497,   923,   924,
     667,   925,   927,   928,   929,  -896,   930,   931,   932,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,   933,   503,  -896,  -896,   934,
     868,   935,  -896,    75,  -896,  -896,  -896,  -896,   936,   937,
     939,   940,  -896,  -896,   941,   696,   942,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -152,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,   678,   678,   678,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -117,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,   590,  -896,   630,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,    36,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,    51,  -896,   944,   801,   945,  -896,  -896,  -896,
    -896,  -896,  -896,   921,  -896,   943,   946,  -896,   947,  -896,
     948,   949,  -896,  -896,   950,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,    53,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,    56,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,    61,  -896,  -896,   951,  -169,   953,   957,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,    70,  -896,  -896,  -896,
     -25,  -896,  -896,  -896,  -896,    22,  -896,  -896,  -896,   329,
    -896,    60,  -896,  -896,  -896,   966,   970,  1019,   975,  1035,
    1046,  1048,  -896,   497,  -896,   667,  -896,   503,   958,   959,
     960,   493,  -896,  -896,   696,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
     961,  -896,  -896
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
      93,    92,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   628,   629,   630,   627,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   614,   615,   625,   626,     0,
       0,     0,   456,     0,     0,   454,   455,     0,   515,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   581,   555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   469,   470,   471,   513,   477,
     514,   508,   509,   510,   511,   481,   472,   473,   474,   475,
     476,   478,   479,   480,   482,   483,   512,   487,   488,   489,
     490,   486,   485,   491,   498,   499,   492,   493,   494,   484,
     496,   506,   507,   504,   505,   497,   495,   502,   503,   500,
     501,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,     0,     0,     0,   661,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   651,   652,   653,   654,   655,
     656,   657,   659,   658,   660,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    67,    65,    63,    68,    69,    70,
      64,    55,    66,    57,    58,    59,    60,    61,    62,    56,
       0,     0,     0,     0,   122,   123,   124,     0,     0,   345,
       0,     0,   343,   344,     0,    94,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   612,
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
       0,     0,   197,     0,     0,   171,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   158,   159,   160,   157,
     156,   161,     0,     0,     0,     0,     0,   333,   334,   335,
     336,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   650,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,   379,     0,   374,   375,   376,   125,     0,
       0,   121,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   113,   112,   114,     0,     0,   342,     0,     0,   357,
       0,     0,   350,   351,   352,   353,     0,     0,     0,    88,
       0,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   611,   250,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   649,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,   377,     0,     0,
       0,   373,     0,   120,     0,   115,     0,     0,     0,     0,
       0,   109,     0,   341,   354,     0,     0,     0,     0,   349,
      97,    96,    95,   647,    28,    28,    28,    28,    28,    28,
      28,    30,    29,   648,   635,   634,   632,   633,   636,   637,
     638,   639,   640,   641,   642,   645,   646,   643,   644,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   394,     0,     0,   444,   457,     0,     0,   459,
     527,   531,   516,   517,   544,   520,   609,   610,   552,   521,
     522,   526,   534,   525,   523,   524,   530,   518,   529,   528,
     550,   607,   608,   548,   585,   605,   590,   591,   592,   601,
     586,   587,   596,   604,   588,   598,   602,   593,   603,   594,
     606,   597,   589,   600,   595,   599,     0,   584,   559,   579,
     563,   564,   565,   575,   560,   561,   570,   578,   562,   572,
     576,   567,   577,   568,   580,   571,   566,   574,   569,   573,
       0,   558,   545,   543,   546,   551,   547,   549,   536,   542,
     541,   537,   538,   539,   540,   553,   554,   533,   532,   535,
     519,     0,     0,     0,     0,     0,     0,     0,     0,   298,
       0,     0,   435,     0,     0,     0,   293,   289,   292,   272,
      50,    51,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   331,
     665,   662,   663,   664,   669,   668,   670,   666,   667,    84,
      81,    87,    80,    85,    86,    79,    83,    82,    73,    72,
      75,    76,    74,    77,    78,     0,     0,   372,   126,     0,
       0,     0,   138,     0,   130,   131,   133,   132,     0,     0,
       0,     0,   108,   346,     0,     0,     0,   348,    31,    32,
      33,    34,    35,    36,    37,   260,   261,   255,   270,   269,
       0,   268,   256,   264,   257,   263,   251,   262,   254,   253,
     252,    38,    38,    38,    40,    39,   258,   259,   418,   421,
     422,   432,   429,   414,   430,   427,   428,     0,   426,   431,
     413,   420,   417,   416,   415,   419,   433,   450,   451,   465,
     466,   582,     0,   556,     0,   312,   313,   322,   318,   319,
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
       0,    41,    42,    43,   424,     0,   583,   557,   315,     0,
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
    -896,  -896,  -896,  -349,  -310,  -895,  -643,  -896,  -896,   972,
    -896,  -896,  -896,  -896,   938,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,   986,  -896,  -896,  -896,  -896,  -896,  -896,
     571,  -896,  -896,  -896,  -896,  -896,   599,  -896,  -896,  -896,
    -896,  -896,  -896,   952,  -896,  -896,  -896,  -896,    29,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,   560,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -197,
    -896,  -896,  -896,   -99,  -896,  -896,  -896,   857,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,   -60,  -896,  -896,  -896,  -896,
    -896,   -70,  -896,   714,  -896,  -896,  -896,    47,  -896,  -896,
    -896,  -896,  -896,   735,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,   -64,  -896,  -896,  -896,  -896,  -896,  -896,   672,  -896,
    -896,  -896,  -896,  -896,   954,  -896,  -896,  -896,  -896,   606,
    -896,  -896,  -896,  -896,  -896,   -85,  -896,  -896,  -896,   638,
    -896,  -896,  -896,  -896,   -76,  -896,  -896,  -896,   869,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,   -52,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
     732,  -896,  -896,  -896,  -896,  -896,   818,  -896,  -896,  -896,
    -896,  1091,  -896,  -896,  -896,  -896,   807,  -896,  -896,  -896,
    -896,  1044,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,    95,  -896,  -896,  -896,    99,  -896,
    -896,  -896,  -896,  -896,  -896,  1120,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896,   978,  -896,  -896,  -896,  -896,
    -896,  -896,  -896,  -896,  -896
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
    1056,  1057,  1238,  1320,    33,    64,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   757,  1213,  1214,
     531,   754,  1187,  1188,    34,    53,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   633,  1080,  1081,    35,    61,   491,   739,
    1152,  1153,   492,   493,   494,  1156,   997,   998,   495,   496,
      36,    59,   469,   470,   471,   472,   473,   474,   475,   724,
    1136,  1137,   476,   477,   478,    37,    65,   536,   537,   538,
     539,   540,    38,   301,   302,   303,    39,    72,   601,   602,
     603,   604,   605,   816,  1256,  1257,    40,    68,   574,   575,
     576,   577,   799,  1233,  1234,    41,    54,   379,   380,   381,
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
     863,   864,   612,   122,   122,   479,   234,  1121,   618,   619,
     620,  1122,   622,   623,   597,   128,   532,   291,    73,   299,
     129,   130,   597,   131,   132,   583,    51,   486,   396,   133,
    1105,   396,   460,  1078,  1289,   299,    49,    50,   532,   134,
     135,   136,   235,   571,  1091,  1092,  1093,   867,   868,   137,
      74,   461,   138,   139,   236,   237,   238,    75,    52,   239,
     240,   533,   140,    56,   241,   242,   243,   862,    58,    62,
    1123,    66,   123,   123,  1124,   462,  1049,   502,   571,   141,
     406,  1147,   224,   533,    67,  1259,   479,   305,   487,  1260,
     142,  1148,    69,   143,   144,    71,   488,   397,   489,   291,
     397,   534,   145,   463,   676,  1079,   678,   679,   146,   147,
     682,   148,    82,   149,  1149,   119,   688,   150,   151,   255,
    1264,   598,   694,   534,  1265,    76,   300,   120,   152,   598,
     702,   703,   584,   153,   154,   480,   155,   156,   157,    83,
      84,   158,   300,   715,   716,   717,   535,    85,   256,   502,
     572,   257,    86,    87,    88,   490,   464,   224,   398,   121,
    1049,   398,   503,   465,   466,   159,   160,   127,   535,   161,
     162,   163,   164,   165,   166,   167,   509,    89,    90,    91,
      92,   258,   221,  1050,   467,   572,   225,   407,   330,  -127,
     585,   259,    93,    94,    95,   510,  1261,  1262,  1263,   583,
      96,    97,    98,   222,    99,   331,   332,   226,   586,   406,
     408,   333,   223,   363,   260,   364,   480,   365,   261,   511,
     460,   231,  1106,   587,   168,   169,   262,   232,   233,   263,
     264,   481,   366,   772,   503,   170,   171,   599,   290,   461,
     600,   404,   292,   550,   172,   599,   173,   512,   600,   504,
    1150,   818,   458,   768,   580,   309,   367,   265,   468,   334,
    1151,   225,   810,   462,   741,   667,   573,  1050,   862,   730,
    1051,  -127,   595,  1268,   368,   306,   369,  1269,   335,   336,
     800,   307,   226,   513,   370,   337,   486,   298,  1270,   338,
    1282,   463,  1271,  1284,  1283,   339,   371,  1285,  1286,  1052,
     514,   573,  1287,   340,   341,   342,   584,  1293,   304,   497,
     509,  1294,   481,  1239,   749,   343,   407,   673,   308,   500,
     372,   504,   851,   734,   292,   854,   311,   856,    73,   510,
     312,   266,   861,   267,   268,   344,   269,   270,   271,   408,
     313,   373,   314,   315,   464,  1127,   316,   487,   317,   328,
     879,   465,   466,   511,  1051,   488,   569,   489,   582,   374,
      74,   318,   319,   320,   585,   321,   322,    75,   323,   324,
     325,   326,   467,   345,  1128,   375,   515,   327,   403,   413,
     414,   512,   586,  1052,   415,   416,   417,   418,   610,   516,
     419,   420,   517,   421,   422,   128,   606,   587,   423,   552,
     129,   130,   518,   131,   132,   424,   519,  1129,   425,   133,
     426,   427,   428,   762,   490,   607,   429,   513,   430,   134,
     135,   136,   431,   432,   376,   645,   377,   378,   433,   137,
     434,   435,   138,   139,   514,    76,   436,   439,  1130,  1131,
     440,   363,   140,   364,  1132,   365,   468,   441,   578,   442,
     663,   824,   825,   826,   827,   828,   829,   830,   443,   141,
     366,   444,   445,   446,   447,   448,   449,  1133,   450,   451,
     142,   452,   453,   143,   144,  1068,  1069,  1070,  1071,  1072,
    1073,  1074,   145,   454,   367,   455,   456,   457,   146,   147,
     498,   148,   499,   149,   541,   542,   543,   150,   151,   544,
     545,  1161,   368,   546,   369,   547,   548,   549,   152,   553,
     515,   554,   370,   153,   154,   555,   155,   156,   157,  1162,
    1163,   158,   556,   516,   371,   609,   517,   557,   255,   558,
     559,  1164,   560,   561,   562,   563,   518,  1134,   564,   565,
     519,   566,   567,   568,   579,   159,   160,   611,   372,   161,
     162,   163,   164,   165,   166,   167,   594,   256,   608,   234,
     257,   611,   613,  1135,   614,   615,   616,   617,  1312,   373,
    1313,  1165,  1166,   621,  1167,   624,   625,   626,   627,   675,
    1223,   628,   629,   630,   647,   669,   631,   374,   632,   634,
     258,   635,   636,   680,  1290,   235,   683,   670,  1168,   637,
     259,   914,  1169,   375,   168,   169,   638,   236,   237,   238,
    1170,   639,   239,   240,  1314,   170,   171,   241,   242,   243,
     640,   641,   642,   260,   172,   643,   173,   261,   644,   648,
    1315,  1171,   649,  1172,  1173,   262,   650,   915,   263,   264,
    1224,   938,   651,   652,   916,   653,   917,   918,   655,   656,
     657,  1174,   376,   658,   377,   378,   659,   660,   661,   662,
     665,   666,  1316,  1317,   671,  1225,   265,  1175,   672,   677,
     681,   684,  1176,  1226,   685,   686,  1177,   939,  1191,   687,
    1178,   689,  1227,   690,   940,  1179,   941,   942,   691,   692,
    1180,   693,   695,   696,   697,   698,   701,   704,   705,  1181,
     699,  1182,  1183,   700,  1184,  1228,   720,  1229,  1230,   706,
     707,   708,   714,   709,  1192,   710,   711,   712,   713,   718,
    1318,  1193,  1185,  1194,  1195,   722,  1319,   719,  1231,   721,
    1186,   770,   771,   736,   723,   725,  1232,   745,   726,   727,
     266,   774,   267,   268,   804,   269,   270,   271,   776,   743,
     744,   728,   729,   732,   919,   920,   733,   737,   921,   738,
     740,   922,   923,   746,   924,   747,   925,   751,   748,   926,
     764,   927,   928,  1246,   752,   753,   755,   929,   756,   930,
     758,   759,   931,   760,   761,   765,   932,   933,   934,   766,
     767,   773,   775,   777,   943,   944,   935,   778,   945,   779,
     780,   946,   947,   781,   948,   782,   949,   783,   786,   950,
     784,   951,   952,   785,   787,   788,   789,   953,   790,   954,
     791,   792,   955,   802,   793,   870,   956,   957,   958,   794,
     795,  1196,  1197,  1247,   796,  1198,   959,   797,  1199,  1200,
     803,  1201,   798,  1202,   330,   805,  1203,   806,  1204,  1205,
     807,     2,     3,   808,  1206,     4,  1207,   809,  1248,  1208,
     812,   331,   332,  1209,  1210,  1211,  1249,   333,     5,   813,
     814,     6,   820,  1212,     7,  1250,   815,   817,   821,   822,
     823,   833,   834,     8,   835,   836,   837,   838,   839,   840,
     841,   842,   843,   844,   845,   846,   847,     9,  1251,   848,
    1252,  1253,   849,    10,    11,   850,   853,   855,   852,   857,
     865,   858,   859,   860,   862,   334,   866,   869,   871,   872,
     873,  1254,    12,   874,   875,   877,    13,    82,   876,  1255,
     878,   882,   880,   881,   335,   336,    14,   883,   884,   887,
     982,   337,   885,   886,   888,   338,  1154,   889,   890,   891,
     892,   339,   893,   894,    83,    84,   895,    15,    16,   340,
     341,   342,    85,   896,   897,   898,   899,    86,    87,    88,
     900,   343,    17,   901,   902,   903,   904,   905,   906,   907,
     908,   909,   910,   911,   912,   913,   962,   963,    18,   964,
     965,   344,    89,    90,    91,    92,   966,   967,   968,   969,
      19,    20,   970,   971,   972,   973,   974,    93,    94,    95,
     975,   976,   977,   978,   979,    96,    97,    98,    21,    99,
     980,   981,   983,   984,   989,   985,   986,   987,   988,   345,
     990,    22,   991,   992,   993,   994,    23,   996,   995,   999,
    1000,  1001,    24,  1002,  1003,    25,  1005,  1004,  1006,  1008,
    1009,  1011,  1007,  1010,  1012,  1013,  1014,  1046,  1016,  1015,
    1017,  1018,  1302,   310,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,  1030,   750,  1031,  1032,  1033,
     763,  1034,  1240,  1035,  1036,  1037,  1038,  1039,  1307,  1040,
    1041,  1042,  1043,  1044,  1045,  1047,  1058,  1048,  1059,  1060,
    1061,  1299,  1065,  1062,  1063,  1064,  1066,  1300,  1236,  1067,
    1075,  1076,  1077,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1117,
    1118,  1119,  1120,  1125,  1126,  1138,  1139,  1140,  1141,  1142,
    1143,  1144,  1145,  1146,  1301,  1157,  1158,  1159,  1155,  1160,
    1189,  1190,  1215,  1275,  1216,  1217,  1218,  1219,  1220,  1221,
    1222,  1235,  1303,  1241,  1242,  1237,  1243,  1244,  1245,  1258,
    1272,  1304,  1274,  1305,  1306,  1276,  1288,   811,  1277,  1278,
    1279,  1280,  1281,  1291,  1292,  1309,  1310,  1311,  1322,   501,
    1295,  1298,  1273,   646,   731,  1297,   742,   819,   769,  1321,
     570,  1308,   801,  1296,   735,   405,   674,   668,   459,  1267,
     329,  1266,   551,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   581,     0,     0,   664,     0,
       0,     0,     0,     0,     0,   596
};

static const yytype_int16 yycheck[] =
{
     643,   644,   312,     1,     1,     1,     1,   237,   318,   319,
     320,   241,   322,   323,     1,     1,     1,     1,     1,     1,
       6,     7,     1,     9,    10,     1,   239,     1,     1,    15,
       8,     1,     1,    58,   203,     1,   237,   238,     1,    25,
      26,    27,    37,     1,    12,    13,    14,   177,   178,    35,
      33,    20,    38,    39,    49,    50,    51,    40,   239,    54,
      55,    46,    48,   239,    59,    60,    61,   236,   239,   239,
     237,   239,    70,    70,   241,    44,     1,     1,     1,    65,
       1,    21,     1,    46,   239,   237,     1,   237,    62,   241,
      76,    31,   239,    79,    80,   239,    70,    70,    72,     1,
      70,    86,    88,    72,   414,   130,   416,   417,    94,    95,
     420,    97,     1,    99,    54,   239,   426,   103,   104,     1,
     237,   108,   432,    86,   241,   108,   108,   239,   114,   108,
     440,   441,   108,   119,   120,   131,   122,   123,   124,    28,
      29,   127,   108,   453,   454,   455,   131,    36,    30,     1,
     108,    33,    41,    42,    43,   129,   125,     1,   131,   239,
       1,   131,    86,   132,   133,   151,   152,   239,   131,   155,
     156,   157,   158,   159,   160,   161,     1,    66,    67,    68,
      69,    63,   239,   108,   153,   108,   105,   108,     1,   173,
     166,    73,    81,    82,    83,    20,  1091,  1092,  1093,     1,
      89,    90,    91,   239,    93,    18,    19,   126,   184,     1,
     131,    24,   239,     1,    96,     3,   131,     5,   100,    44,
       1,   239,   200,   199,   210,   211,   108,   239,   239,   111,
     112,   227,    20,   543,    86,   221,   222,   224,   239,    20,
     227,   238,   226,   238,   230,   224,   232,    72,   227,   173,
     190,   238,   238,   238,   238,   238,    44,   139,   227,    72,
     200,   105,   238,    44,   238,   238,   224,   108,   236,   238,
     195,   173,   238,   237,    62,   240,    64,   241,    91,    92,
     238,   240,   126,   108,    72,    98,     1,   239,   237,   102,
     237,    72,   241,   237,   241,   108,    84,   241,   237,   224,
     125,   224,   241,   116,   117,   118,   108,   237,   239,   237,
       1,   241,   227,   238,   238,   128,   108,   238,   240,   238,
     108,   173,   632,   238,   226,   635,   240,   637,     1,    20,
     240,   213,   642,   215,   216,   148,   218,   219,   220,   131,
     240,   129,   240,   240,   125,    16,   240,    62,   240,   238,
     660,   132,   133,    44,   195,    70,   238,    72,   173,   147,
      33,   240,   240,   240,   166,   240,   240,    40,   240,   240,
     240,   240,   153,   186,    45,   163,   201,   240,   240,   240,
     240,    72,   184,   224,   240,   240,   240,   240,   236,   214,
     240,   240,   217,   240,   240,     1,   235,   199,   240,   237,
       6,     7,   227,     9,    10,   240,   231,    78,   240,    15,
     240,   240,   240,   238,   129,   235,   240,   108,   240,    25,
      26,    27,   240,   240,   212,   238,   214,   215,   240,    35,
     240,   240,    38,    39,   125,   108,   240,   240,   109,   110,
     240,     1,    48,     3,   115,     5,   227,   240,   237,   240,
     238,   140,   141,   142,   143,   144,   145,   146,   240,    65,
      20,   240,   240,   240,   240,   240,   240,   138,   240,   240,
      76,   240,   240,    79,    80,   824,   825,   826,   827,   828,
     829,   830,    88,   240,    44,   240,   240,   240,    94,    95,
     240,    97,   240,    99,   240,   240,   240,   103,   104,   240,
     240,     4,    62,   240,    64,   240,   240,   240,   114,   240,
     201,   240,    72,   119,   120,   240,   122,   123,   124,    22,
      23,   127,   240,   214,    84,   237,   217,   240,     1,   240,
     240,    34,   240,   240,   240,   240,   227,   208,   240,   240,
     231,   240,   240,   240,   240,   151,   152,   236,   108,   155,
     156,   157,   158,   159,   160,   161,   240,    30,   235,     1,
      33,   236,   209,   234,   209,   209,   209,   236,    75,   129,
      77,    74,    75,   236,    77,   236,   236,   236,   236,   209,
      77,   237,   237,   240,   237,   235,   240,   147,   240,   240,
      63,   240,   240,   209,  1237,    37,   209,   237,   101,   240,
      73,    11,   105,   163,   210,   211,   240,    49,    50,    51,
     113,   240,    54,    55,   121,   221,   222,    59,    60,    61,
     240,   240,   240,    96,   230,   240,   232,   100,   240,   240,
     137,   134,   240,   136,   137,   108,   240,    47,   111,   112,
     137,    11,   240,   240,    54,   240,    56,    57,   240,   240,
     240,   154,   212,   240,   214,   215,   240,   240,   240,   240,
     240,   240,   169,   170,   240,   162,   139,   170,   240,   236,
     236,   236,   175,   170,   236,   209,   179,    47,    11,   209,
     183,   236,   179,   236,    54,   188,    56,    57,   236,   236,
     193,   236,   236,   236,   236,   209,   209,   209,   209,   202,
     240,   204,   205,   240,   207,   202,   237,   204,   205,   236,
     209,   209,   236,   209,    47,   209,   209,   209,   209,   209,
     227,    54,   225,    56,    57,   240,   233,   236,   225,   237,
     233,   209,   209,   237,   240,   240,   233,   237,   240,   240,
     213,   209,   215,   216,   239,   218,   219,   220,   209,   235,
     235,   240,   240,   240,   164,   165,   240,   240,   168,   240,
     240,   171,   172,   237,   174,   240,   176,   237,   240,   179,
     237,   181,   182,    77,   240,   240,   240,   187,   240,   189,
     240,   240,   192,   240,   240,   240,   196,   197,   198,   240,
     240,   235,   235,   209,   164,   165,   206,   209,   168,   237,
     236,   171,   172,   235,   174,   209,   176,   235,   235,   179,
     236,   181,   182,   236,   235,   235,   235,   187,   235,   189,
     235,   235,   192,   209,   235,   209,   196,   197,   198,   235,
     235,   164,   165,   137,   237,   168,   206,   237,   171,   172,
     237,   174,   240,   176,     1,   237,   179,   240,   181,   182,
     240,     0,     1,   240,   187,     4,   189,   240,   162,   192,
     235,    18,    19,   196,   197,   198,   170,    24,    17,   237,
     237,    20,   237,   206,    23,   179,   240,   240,   237,   237,
     237,   237,   237,    32,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,    46,   202,   237,
     204,   205,   236,    52,    53,   236,   236,   236,   240,   235,
     237,   236,   236,   236,   236,    72,   235,   235,   235,   235,
     240,   225,    71,   235,   235,   235,    75,     1,   236,   233,
     235,   237,   235,   235,    91,    92,    85,   235,   235,   235,
     209,    98,   237,   237,   235,   102,   223,   237,   237,   237,
     237,   108,   237,   237,    28,    29,   237,   106,   107,   116,
     117,   118,    36,   237,   237,   237,   237,    41,    42,    43,
     237,   128,   121,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   137,   237,
     237,   148,    66,    67,    68,    69,   237,   237,   237,   237,
     149,   150,   237,   237,   237,   237,   237,    81,    82,    83,
     237,   237,   237,   237,   237,    89,    90,    91,   167,    93,
     237,   235,   240,   235,   237,   236,   235,   235,   235,   186,
     235,   180,   235,   237,   235,   235,   185,   236,   240,   237,
     237,   237,   191,   235,   235,   194,   235,   237,   209,   235,
     235,   235,   240,   240,   209,   235,   235,   240,   235,   237,
     235,   235,    87,    77,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   505,   237,   237,   237,
     520,   237,  1053,   237,   237,   237,   237,   237,  1285,   237,
     237,   237,   237,   237,   235,   237,   235,   237,   235,   235,
     235,   135,   240,   237,   237,   235,   235,   137,   240,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   135,   237,   237,   237,   241,   237,
     237,   237,   237,   242,   237,   237,   237,   237,   237,   237,
     237,   237,   137,   237,   237,   240,   237,   237,   237,   237,
     236,   135,   237,   135,  1283,   242,   235,   588,   242,   242,
     242,   242,   242,   240,   237,   237,   237,   237,   237,   227,
    1260,  1271,  1155,   346,   469,  1269,   492,   601,   536,  1294,
     272,  1287,   574,  1265,   482,   124,   409,   399,   174,  1124,
     100,  1122,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   293,    -1,    -1,   379,    -1,
      -1,    -1,    -1,    -1,    -1,   301
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   244,     0,     1,     4,    17,    20,    23,    32,    46,
      52,    53,    71,    75,    85,   106,   107,   121,   137,   149,
     150,   167,   180,   185,   191,   194,   245,   250,   255,   274,
     280,   286,   294,   307,   327,   349,   363,   378,   385,   389,
     399,   408,   430,   436,   442,   446,   452,   506,   526,   237,
     238,   239,   239,   328,   409,   437,   239,   447,   239,   364,
     431,   350,   239,   281,   308,   379,   239,   239,   400,   239,
     287,   239,   390,     1,    33,    40,   108,   275,   276,   277,
     278,   279,     1,    28,    29,    36,    41,    42,    43,    66,
      67,    68,    69,    81,    82,    83,    89,    90,    91,    93,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   239,
     239,   239,     1,    70,   443,   444,   445,   239,     1,     6,
       7,     9,    10,    15,    25,    26,    27,    35,    38,    39,
      48,    65,    76,    79,    80,    88,    94,    95,    97,    99,
     103,   104,   114,   119,   120,   122,   123,   124,   127,   151,
     152,   155,   156,   157,   158,   159,   160,   161,   210,   211,
     221,   222,   230,   232,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   498,   502,   503,   504,
     505,   239,   239,   239,     1,   105,   126,   251,   252,   253,
     254,   239,   239,   239,     1,    37,    49,    50,    51,    54,
      55,    59,    60,    61,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,     1,    30,    33,    63,    73,
      96,   100,   108,   111,   112,   139,   213,   215,   216,   218,
     219,   220,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     239,     1,   226,   295,   296,   297,   298,   299,   239,     1,
     108,   386,   387,   388,   239,   237,   240,   240,   240,   238,
     276,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   238,   508,
       1,    18,    19,    24,    72,    91,    92,    98,   102,   108,
     116,   117,   118,   128,   148,   186,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,     1,     3,     5,    20,    44,    62,    64,
      72,    84,   108,   129,   147,   163,   212,   214,   215,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   425,   426,   427,   428,   429,     1,    70,   131,   438,
     439,   440,   441,   240,   238,   444,     1,   108,   131,   448,
     449,   450,   451,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   499,   495,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   238,   454,
       1,    20,    44,    72,   125,   132,   133,   153,   227,   365,
     366,   367,   368,   369,   370,   371,   375,   376,   377,     1,
     131,   227,   432,   433,   434,   435,     1,    62,    70,    72,
     129,   351,   355,   356,   357,   361,   362,   237,   240,   240,
     238,   252,     1,    86,   173,   282,   283,   284,   285,     1,
      20,    44,    72,   108,   125,   201,   214,   217,   227,   231,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   323,     1,    46,    86,   131,   380,   381,   382,   383,
     384,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     238,   528,   237,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   238,
     257,     1,   108,   224,   401,   402,   403,   404,   237,   240,
     238,   296,   173,     1,   108,   166,   184,   199,   288,   289,
     290,   291,   292,   293,   240,   238,   387,     1,   108,   224,
     227,   391,   392,   393,   394,   395,   235,   235,   235,   237,
     236,   236,   247,   209,   209,   209,   209,   236,   247,   247,
     247,   236,   247,   247,   236,   236,   236,   236,   237,   237,
     240,   240,   240,   346,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   238,   330,   237,   240,   240,
     240,   240,   240,   240,   422,   240,   240,   240,   240,   240,
     240,   240,   240,   238,   411,   240,   240,   238,   439,   235,
     237,   240,   240,   238,   449,   209,   247,   236,   247,   247,
     209,   236,   247,   209,   236,   236,   209,   209,   247,   236,
     236,   236,   236,   236,   247,   236,   236,   236,   209,   240,
     240,   209,   247,   247,   209,   209,   236,   209,   209,   209,
     209,   209,   209,   209,   236,   247,   247,   247,   209,   236,
     237,   237,   240,   240,   372,   240,   240,   240,   240,   240,
     238,   366,   240,   240,   238,   433,   237,   240,   240,   352,
     240,   238,   356,   235,   235,   237,   237,   240,   240,   238,
     283,   237,   240,   240,   324,   240,   240,   320,   240,   240,
     240,   240,   238,   310,   237,   240,   240,   240,   238,   381,
     209,   209,   247,   235,   209,   235,   209,   209,   209,   237,
     236,   235,   209,   235,   236,   236,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   237,   237,   240,   405,
     238,   402,   209,   237,   239,   237,   240,   240,   240,   240,
     238,   289,   235,   237,   237,   240,   396,   240,   238,   392,
     237,   237,   237,   237,   140,   141,   142,   143,   144,   145,
     146,   246,   247,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   236,
     236,   247,   240,   236,   247,   236,   247,   235,   236,   236,
     236,   247,   236,   249,   249,   237,   235,   177,   178,   235,
     209,   235,   235,   240,   235,   235,   236,   235,   235,   247,
     235,   235,   237,   235,   235,   237,   237,   235,   235,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,    11,    47,    54,    56,    57,   164,
     165,   168,   171,   172,   174,   176,   179,   181,   182,   187,
     189,   192,   196,   197,   198,   206,   500,   501,    11,    47,
      54,    56,    57,   164,   165,   168,   171,   172,   174,   176,
     179,   181,   182,   187,   189,   192,   196,   197,   198,   206,
     496,   497,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   235,   209,   240,   235,   236,   235,   235,   235,   237,
     235,   235,   237,   235,   235,   240,   236,   359,   360,   237,
     237,   237,   235,   235,   237,   235,   209,   240,   235,   235,
     240,   235,   209,   235,   235,   237,   235,   235,   235,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   235,   240,   237,   237,     1,
     108,   195,   224,   300,   301,   302,   303,   304,   235,   235,
     235,   235,   237,   237,   235,   240,   235,   237,   246,   246,
     246,   246,   246,   246,   246,   237,   237,   237,    58,   130,
     347,   348,   237,   237,   237,   237,   237,   237,   237,   237,
     237,    12,    13,    14,   248,   249,   237,   237,   237,   237,
     237,   237,   237,   237,   237,     8,   200,   423,   424,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   241,   237,   241,   237,   237,    16,    45,    78,
     109,   110,   115,   138,   208,   234,   373,   374,   237,   237,
     237,   237,   237,   237,   237,   237,   237,    21,    31,    54,
     190,   200,   353,   354,   223,   241,   358,   237,   237,   237,
     237,     4,    22,    23,    34,    74,    75,    77,   101,   105,
     113,   134,   136,   137,   154,   170,   175,   179,   183,   188,
     193,   202,   204,   205,   207,   225,   233,   325,   326,   237,
     237,    11,    47,    54,    56,    57,   164,   165,   168,   171,
     172,   174,   176,   179,   181,   182,   187,   189,   192,   196,
     197,   198,   206,   321,   322,   237,   237,   237,   237,   237,
     237,   237,   237,    77,   137,   162,   170,   179,   202,   204,
     205,   225,   233,   406,   407,   237,   240,   240,   305,   238,
     301,   237,   237,   237,   237,   237,    77,   137,   162,   170,
     179,   202,   204,   205,   225,   233,   397,   398,   237,   237,
     241,   248,   248,   248,   237,   241,   501,   497,   237,   241,
     237,   241,   236,   360,   237,   242,   242,   242,   242,   242,
     242,   242,   237,   241,   237,   241,   237,   241,   235,   203,
     249,   240,   237,   237,   241,   348,   424,   374,   354,   135,
     137,   135,    87,   137,   135,   135,   326,   322,   407,   237,
     237,   237,    75,    77,   121,   137,   169,   170,   227,   233,
     306,   398,   237
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   243,   244,   244,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   246,   246,
     247,   247,   247,   247,   247,   247,   247,   247,   248,   248,
     249,   249,   249,   249,   250,   251,   251,   252,   252,   252,
     253,   254,   255,   256,   256,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     275,   276,   276,   276,   276,   277,   278,   279,   281,   280,
     282,   282,   283,   283,   283,   284,   285,   287,   286,   288,
     288,   289,   289,   289,   289,   289,   290,   291,   292,   293,
     294,   295,   295,   296,   296,   296,   297,   299,   298,   300,
     300,   301,   301,   301,   301,   302,   303,   303,   305,   304,
     306,   306,   306,   306,   306,   306,   306,   306,   308,   307,
     309,   309,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   320,   319,   321,   321,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   324,   323,   325,
     325,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   328,   327,   329,   329,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   346,   345,   347,   347,   348,
     348,   350,   349,   352,   351,   353,   353,   354,   354,   354,
     354,   354,   355,   355,   356,   356,   356,   356,   356,   358,
     357,   359,   359,   360,   360,   361,   362,   364,   363,   365,
     365,   366,   366,   366,   366,   366,   366,   366,   366,   366,
     367,   368,   369,   370,   372,   371,   373,   373,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   375,   376,   377,
     379,   378,   380,   380,   381,   381,   381,   381,   382,   383,
     384,   385,   386,   386,   387,   387,   388,   390,   389,   391,
     391,   392,   392,   392,   392,   393,   394,   396,   395,   397,
     397,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   400,   399,   401,   401,   402,   402,   402,   403,   405,
     404,   406,   406,   407,   407,   407,   407,   407,   407,   407,
     407,   407,   407,   409,   408,   410,   410,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   420,   422,   421,   423,   423,   424,   424,   425,
     426,   427,   428,   429,   431,   430,   432,   432,   433,   433,
     433,   434,   435,   437,   436,   438,   438,   439,   439,   439,
     440,   441,   442,   443,   443,   444,   444,   445,   447,   446,
     448,   448,   449,   449,   449,   450,   451,   452,   453,   453,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   495,   494,   496,   496,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   499,   498,   500,   500,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   502,   503,   504,
     505,   506,   507,   507,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   527,   528,   528,   528,   528,   528,   528,   528,   528,
     528,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537
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
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4
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
#line 401 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3282 "conf_parser.c"
    break;

  case 30: /* timespec: NUMBER timespec_  */
#line 402 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3288 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER SECONDS timespec_  */
#line 403 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3294 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER MINUTES timespec_  */
#line 404 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3300 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER HOURS timespec_  */
#line 405 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3306 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER DAYS timespec_  */
#line 406 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3312 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER WEEKS timespec_  */
#line 407 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3318 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER MONTHS timespec_  */
#line 408 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3324 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER YEARS timespec_  */
#line 409 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3330 "conf_parser.c"
    break;

  case 38: /* sizespec_: %empty  */
#line 412 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3336 "conf_parser.c"
    break;

  case 40: /* sizespec: NUMBER sizespec_  */
#line 413 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3342 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER BYTES sizespec_  */
#line 414 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3348 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER KBYTES sizespec_  */
#line 415 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3354 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER MBYTES sizespec_  */
#line 416 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3360 "conf_parser.c"
    break;

  case 50: /* modules_module: MODULE '=' QSTRING ';'  */
#line 429 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    add_conf_module(io_basename(yylval.string));
}
#line 3369 "conf_parser.c"
    break;

  case 51: /* modules_path: PATH '=' QSTRING ';'  */
#line 435 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 3378 "conf_parser.c"
    break;

  case 72: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 467 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3390 "conf_parser.c"
    break;

  case 73: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 476 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = io_strdup(yylval.string);
  }
}
#line 3402 "conf_parser.c"
    break;

  case 74: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 485 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = io_strdup(yylval.string);
  }
}
#line 3414 "conf_parser.c"
    break;

  case 75: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 494 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = io_strdup(yylval.string);
  }
}
#line 3426 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 503 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = io_strdup(yylval.string);
  }
}
#line 3438 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 512 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = io_strdup(yylval.string);
  }
}
#line 3450 "conf_parser.c"
    break;

  case 78: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 521 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = io_strdup(yylval.string);
  }
}
#line 3462 "conf_parser.c"
    break;

  case 79: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 530 "conf_parser.y"
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
#line 3480 "conf_parser.c"
    break;

  case 80: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 545 "conf_parser.y"
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
#line 3498 "conf_parser.c"
    break;

  case 81: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 560 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3511 "conf_parser.c"
    break;

  case 82: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 570 "conf_parser.y"
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
#line 3528 "conf_parser.c"
    break;

  case 83: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 584 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3540 "conf_parser.c"
    break;

  case 84: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 593 "conf_parser.y"
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
#line 3566 "conf_parser.c"
    break;

  case 85: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 616 "conf_parser.y"
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
#line 3592 "conf_parser.c"
    break;

  case 86: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 639 "conf_parser.y"
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
#line 3618 "conf_parser.c"
    break;

  case 87: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 662 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3627 "conf_parser.c"
    break;

  case 95: /* admin_name: NAME '=' QSTRING ';'  */
#line 680 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3639 "conf_parser.c"
    break;

  case 96: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 689 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3651 "conf_parser.c"
    break;

  case 97: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 698 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3663 "conf_parser.c"
    break;

  case 98: /* $@1: %empty  */
#line 711 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3672 "conf_parser.c"
    break;

  case 99: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 715 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3689 "conf_parser.c"
    break;

  case 105: /* motd_mask: MASK '=' QSTRING ';'  */
#line 732 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3698 "conf_parser.c"
    break;

  case 106: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 738 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3707 "conf_parser.c"
    break;

  case 107: /* $@2: %empty  */
#line 748 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3716 "conf_parser.c"
    break;

  case 108: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 752 "conf_parser.y"
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
#line 3734 "conf_parser.c"
    break;

  case 116: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 770 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3743 "conf_parser.c"
    break;

  case 117: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 776 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3752 "conf_parser.c"
    break;

  case 118: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 782 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3761 "conf_parser.c"
    break;

  case 119: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 788 "conf_parser.y"
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
#line 3783 "conf_parser.c"
    break;

  case 126: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 817 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3792 "conf_parser.c"
    break;

  case 127: /* $@3: %empty  */
#line 823 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3801 "conf_parser.c"
    break;

  case 128: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 827 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3814 "conf_parser.c"
    break;

  case 135: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 843 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3825 "conf_parser.c"
    break;

  case 136: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 851 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3833 "conf_parser.c"
    break;

  case 137: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 854 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3841 "conf_parser.c"
    break;

  case 138: /* $@4: %empty  */
#line 859 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3850 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: USER  */
#line 865 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3859 "conf_parser.c"
    break;

  case 141: /* logging_file_type_item: OPERATOR  */
#line 869 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3868 "conf_parser.c"
    break;

  case 142: /* logging_file_type_item: XLINE  */
#line 873 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3877 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: RESV  */
#line 877 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3886 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: T_DLINE  */
#line 881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3895 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: KLINE  */
#line 885 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3904 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: KILL  */
#line 889 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3913 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: T_DEBUG  */
#line 893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3922 "conf_parser.c"
    break;

  case 148: /* $@5: %empty  */
#line 903 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3934 "conf_parser.c"
    break;

  case 149: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 910 "conf_parser.y"
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
#line 3994 "conf_parser.c"
    break;

  case 163: /* oper_name: NAME '=' QSTRING ';'  */
#line 980 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4003 "conf_parser.c"
    break;

  case 164: /* oper_user: USER '=' QSTRING ';'  */
#line 986 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4012 "conf_parser.c"
    break;

  case 165: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 992 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4021 "conf_parser.c"
    break;

  case 166: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 998 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4030 "conf_parser.c"
    break;

  case 167: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1004 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 4044 "conf_parser.c"
    break;

  case 168: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1015 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4053 "conf_parser.c"
    break;

  case 169: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1021 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 4067 "conf_parser.c"
    break;

  case 170: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1032 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4076 "conf_parser.c"
    break;

  case 171: /* $@6: %empty  */
#line 1038 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 4085 "conf_parser.c"
    break;

  case 175: /* oper_umodes_item: BOT  */
#line 1045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOT;
}
#line 4094 "conf_parser.c"
    break;

  case 176: /* oper_umodes_item: T_CCONN  */
#line 1049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 4103 "conf_parser.c"
    break;

  case 177: /* oper_umodes_item: T_DEAF  */
#line 1053 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 4112 "conf_parser.c"
    break;

  case 178: /* oper_umodes_item: T_FLOOD  */
#line 1057 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FLOOD;
}
#line 4121 "conf_parser.c"
    break;

  case 179: /* oper_umodes_item: HIDDEN  */
#line 1061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 4130 "conf_parser.c"
    break;

  case 180: /* oper_umodes_item: HIDE_CHANS  */
#line 1065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 4139 "conf_parser.c"
    break;

  case 181: /* oper_umodes_item: HIDE_IDLE  */
#line 1069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 4148 "conf_parser.c"
    break;

  case 182: /* oper_umodes_item: T_SKILL  */
#line 1073 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 4157 "conf_parser.c"
    break;

  case 183: /* oper_umodes_item: T_NCHANGE  */
#line 1077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 4166 "conf_parser.c"
    break;

  case 184: /* oper_umodes_item: T_REJ  */
#line 1081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 4175 "conf_parser.c"
    break;

  case 185: /* oper_umodes_item: T_SPY  */
#line 1085 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4184 "conf_parser.c"
    break;

  case 186: /* oper_umodes_item: T_EXTERNAL  */
#line 1089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4193 "conf_parser.c"
    break;

  case 187: /* oper_umodes_item: T_SERVNOTICE  */
#line 1093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4202 "conf_parser.c"
    break;

  case 188: /* oper_umodes_item: T_INVISIBLE  */
#line 1097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4211 "conf_parser.c"
    break;

  case 189: /* oper_umodes_item: T_WALLOP  */
#line 1101 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4220 "conf_parser.c"
    break;

  case 190: /* oper_umodes_item: T_SOFTCALLERID  */
#line 1105 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4229 "conf_parser.c"
    break;

  case 191: /* oper_umodes_item: T_CALLERID  */
#line 1109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4238 "conf_parser.c"
    break;

  case 192: /* oper_umodes_item: T_LOCOPS  */
#line 1113 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4247 "conf_parser.c"
    break;

  case 193: /* oper_umodes_item: T_NONONREG  */
#line 1117 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4256 "conf_parser.c"
    break;

  case 194: /* oper_umodes_item: T_FARCONNECT  */
#line 1121 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4265 "conf_parser.c"
    break;

  case 195: /* oper_umodes_item: EXPIRATION  */
#line 1125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 4274 "conf_parser.c"
    break;

  case 196: /* oper_umodes_item: T_SECUREONLY  */
#line 1129 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SECUREONLY;
}
#line 4283 "conf_parser.c"
    break;

  case 197: /* $@7: %empty  */
#line 1135 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4292 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: KILL ':' REMOTE  */
#line 1142 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4301 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: KILL  */
#line 1146 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4310 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1150 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4319 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: CONNECT  */
#line 1154 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4328 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1158 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4337 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: SQUIT  */
#line 1162 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4346 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: KLINE  */
#line 1166 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4355 "conf_parser.c"
    break;

  case 208: /* oper_flags_item: UNKLINE  */
#line 1170 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4364 "conf_parser.c"
    break;

  case 209: /* oper_flags_item: T_DLINE  */
#line 1174 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4373 "conf_parser.c"
    break;

  case 210: /* oper_flags_item: T_UNDLINE  */
#line 1178 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4382 "conf_parser.c"
    break;

  case 211: /* oper_flags_item: XLINE  */
#line 1182 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4391 "conf_parser.c"
    break;

  case 212: /* oper_flags_item: T_UNXLINE  */
#line 1186 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4400 "conf_parser.c"
    break;

  case 213: /* oper_flags_item: DIE  */
#line 1190 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4409 "conf_parser.c"
    break;

  case 214: /* oper_flags_item: T_RESTART  */
#line 1194 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4418 "conf_parser.c"
    break;

  case 215: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1198 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4427 "conf_parser.c"
    break;

  case 216: /* oper_flags_item: REHASH  */
#line 1202 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4436 "conf_parser.c"
    break;

  case 217: /* oper_flags_item: ADMIN  */
#line 1206 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4445 "conf_parser.c"
    break;

  case 218: /* oper_flags_item: T_GLOBOPS  */
#line 1210 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4454 "conf_parser.c"
    break;

  case 219: /* oper_flags_item: T_WALLOPS  */
#line 1214 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4463 "conf_parser.c"
    break;

  case 220: /* oper_flags_item: T_LOCOPS  */
#line 1218 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4472 "conf_parser.c"
    break;

  case 221: /* oper_flags_item: REMOTEBAN  */
#line 1222 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4481 "conf_parser.c"
    break;

  case 222: /* oper_flags_item: T_SET  */
#line 1226 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4490 "conf_parser.c"
    break;

  case 223: /* oper_flags_item: MODULE  */
#line 1230 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4499 "conf_parser.c"
    break;

  case 224: /* oper_flags_item: T_OPME  */
#line 1234 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4508 "conf_parser.c"
    break;

  case 225: /* oper_flags_item: NICK ':' RESV  */
#line 1238 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4517 "conf_parser.c"
    break;

  case 226: /* oper_flags_item: JOIN ':' RESV  */
#line 1242 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4526 "conf_parser.c"
    break;

  case 227: /* oper_flags_item: RESV  */
#line 1246 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4535 "conf_parser.c"
    break;

  case 228: /* oper_flags_item: T_UNRESV  */
#line 1250 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4544 "conf_parser.c"
    break;

  case 229: /* oper_flags_item: CLOSE  */
#line 1254 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4553 "conf_parser.c"
    break;

  case 230: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1258 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4562 "conf_parser.c"
    break;

  case 231: /* $@8: %empty  */
#line 1268 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4578 "conf_parser.c"
    break;

  case 232: /* class_entry: CLASS $@8 '{' class_items '}' ';'  */
#line 1279 "conf_parser.y"
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
#line 4626 "conf_parser.c"
    break;

  case 251: /* class_name: NAME '=' QSTRING ';'  */
#line 1342 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4635 "conf_parser.c"
    break;

  case 252: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1348 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4644 "conf_parser.c"
    break;

  case 253: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1354 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4653 "conf_parser.c"
    break;

  case 254: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1360 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4662 "conf_parser.c"
    break;

  case 255: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1366 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4671 "conf_parser.c"
    break;

  case 256: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1372 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4680 "conf_parser.c"
    break;

  case 257: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1378 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4689 "conf_parser.c"
    break;

  case 258: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1384 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4698 "conf_parser.c"
    break;

  case 259: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1390 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4708 "conf_parser.c"
    break;

  case 260: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1397 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4717 "conf_parser.c"
    break;

  case 261: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1403 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4726 "conf_parser.c"
    break;

  case 262: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1409 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4735 "conf_parser.c"
    break;

  case 263: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1415 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4747 "conf_parser.c"
    break;

  case 264: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1424 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4759 "conf_parser.c"
    break;

  case 265: /* $@9: %empty  */
#line 1433 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4768 "conf_parser.c"
    break;

  case 269: /* class_flags_item: RANDOM_IDLE  */
#line 1440 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4777 "conf_parser.c"
    break;

  case 270: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1444 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4786 "conf_parser.c"
    break;

  case 271: /* $@10: %empty  */
#line 1454 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4795 "conf_parser.c"
    break;

  case 273: /* $@11: %empty  */
#line 1460 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4803 "conf_parser.c"
    break;

  case 277: /* listen_flags_item: T_TLS  */
#line 1466 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4812 "conf_parser.c"
    break;

  case 278: /* listen_flags_item: HIDDEN  */
#line 1470 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4821 "conf_parser.c"
    break;

  case 279: /* listen_flags_item: T_SERVER  */
#line 1474 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4830 "conf_parser.c"
    break;

  case 280: /* listen_flags_item: CLIENT  */
#line 1478 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4839 "conf_parser.c"
    break;

  case 281: /* listen_flags_item: DEFER  */
#line 1482 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4848 "conf_parser.c"
    break;

  case 289: /* $@12: %empty  */
#line 1490 "conf_parser.y"
                                 { reset_block_state(); }
#line 4854 "conf_parser.c"
    break;

  case 293: /* port_item: NUMBER  */
#line 1495 "conf_parser.y"
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
#line 4872 "conf_parser.c"
    break;

  case 294: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1508 "conf_parser.y"
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
#line 4892 "conf_parser.c"
    break;

  case 295: /* listen_address: IP '=' QSTRING ';'  */
#line 1525 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4901 "conf_parser.c"
    break;

  case 296: /* listen_host: HOST '=' QSTRING ';'  */
#line 1531 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4910 "conf_parser.c"
    break;

  case 297: /* $@13: %empty  */
#line 1541 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4919 "conf_parser.c"
    break;

  case 298: /* auth_entry: IRCD_AUTH $@13 '{' auth_items '}' ';'  */
#line 1545 "conf_parser.y"
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
#line 4966 "conf_parser.c"
    break;

  case 310: /* auth_user: USER '=' QSTRING ';'  */
#line 1600 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4975 "conf_parser.c"
    break;

  case 311: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1606 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4984 "conf_parser.c"
    break;

  case 312: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1612 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4993 "conf_parser.c"
    break;

  case 313: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1618 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5007 "conf_parser.c"
    break;

  case 314: /* $@14: %empty  */
#line 1629 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 5016 "conf_parser.c"
    break;

  case 318: /* auth_flags_item: EXCEED_LIMIT  */
#line 1636 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 5025 "conf_parser.c"
    break;

  case 319: /* auth_flags_item: KLINE_EXEMPT  */
#line 1640 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 5034 "conf_parser.c"
    break;

  case 320: /* auth_flags_item: XLINE_EXEMPT  */
#line 1644 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 5043 "conf_parser.c"
    break;

  case 321: /* auth_flags_item: NEED_IDENT  */
#line 1648 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 5052 "conf_parser.c"
    break;

  case 322: /* auth_flags_item: CAN_FLOOD  */
#line 1652 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 5061 "conf_parser.c"
    break;

  case 323: /* auth_flags_item: NO_TILDE  */
#line 1656 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 5070 "conf_parser.c"
    break;

  case 324: /* auth_flags_item: RESV_EXEMPT  */
#line 1660 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 5079 "conf_parser.c"
    break;

  case 325: /* auth_flags_item: T_WEBIRC  */
#line 1664 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 5088 "conf_parser.c"
    break;

  case 326: /* auth_flags_item: NEED_PASSWORD  */
#line 1668 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 5097 "conf_parser.c"
    break;

  case 327: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1674 "conf_parser.y"
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
#line 5114 "conf_parser.c"
    break;

  case 328: /* auth_redir_serv: REDIRSERV '=' QSTRING ';'  */
#line 1688 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 5126 "conf_parser.c"
    break;

  case 329: /* auth_redir_port: REDIRPORT '=' NUMBER ';'  */
#line 1697 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 5138 "conf_parser.c"
    break;

  case 330: /* $@15: %empty  */
#line 1710 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5150 "conf_parser.c"
    break;

  case 331: /* resv_entry: RESV $@15 '{' resv_items '}' ';'  */
#line 1717 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5161 "conf_parser.c"
    break;

  case 338: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1728 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5170 "conf_parser.c"
    break;

  case 339: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1734 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5179 "conf_parser.c"
    break;

  case 340: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1740 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5188 "conf_parser.c"
    break;

  case 346: /* service_name: NAME '=' QSTRING ';'  */
#line 1755 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5203 "conf_parser.c"
    break;

  case 347: /* $@16: %empty  */
#line 1771 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5219 "conf_parser.c"
    break;

  case 348: /* shared_entry: T_SHARED $@16 '{' shared_items '}' ';'  */
#line 1782 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5234 "conf_parser.c"
    break;

  case 355: /* shared_name: NAME '=' QSTRING ';'  */
#line 1797 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5243 "conf_parser.c"
    break;

  case 356: /* shared_user: USER '=' QSTRING ';'  */
#line 1803 "conf_parser.y"
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
#line 5265 "conf_parser.c"
    break;

  case 357: /* $@17: %empty  */
#line 1822 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5274 "conf_parser.c"
    break;

  case 361: /* shared_type_item: KLINE  */
#line 1829 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5283 "conf_parser.c"
    break;

  case 362: /* shared_type_item: UNKLINE  */
#line 1833 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5292 "conf_parser.c"
    break;

  case 363: /* shared_type_item: T_DLINE  */
#line 1837 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5301 "conf_parser.c"
    break;

  case 364: /* shared_type_item: T_UNDLINE  */
#line 1841 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5310 "conf_parser.c"
    break;

  case 365: /* shared_type_item: XLINE  */
#line 1845 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5319 "conf_parser.c"
    break;

  case 366: /* shared_type_item: T_UNXLINE  */
#line 1849 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5328 "conf_parser.c"
    break;

  case 367: /* shared_type_item: RESV  */
#line 1853 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5337 "conf_parser.c"
    break;

  case 368: /* shared_type_item: T_UNRESV  */
#line 1857 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5346 "conf_parser.c"
    break;

  case 369: /* shared_type_item: T_LOCOPS  */
#line 1861 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5355 "conf_parser.c"
    break;

  case 370: /* shared_type_item: T_ALL  */
#line 1865 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5364 "conf_parser.c"
    break;

  case 371: /* $@18: %empty  */
#line 1875 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5378 "conf_parser.c"
    break;

  case 372: /* cluster_entry: T_CLUSTER $@18 '{' cluster_items '}' ';'  */
#line 1884 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5391 "conf_parser.c"
    break;

  case 378: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1897 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5400 "conf_parser.c"
    break;

  case 379: /* $@19: %empty  */
#line 1903 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5409 "conf_parser.c"
    break;

  case 383: /* cluster_type_item: KLINE  */
#line 1910 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5418 "conf_parser.c"
    break;

  case 384: /* cluster_type_item: UNKLINE  */
#line 1914 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5427 "conf_parser.c"
    break;

  case 385: /* cluster_type_item: T_DLINE  */
#line 1918 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5436 "conf_parser.c"
    break;

  case 386: /* cluster_type_item: T_UNDLINE  */
#line 1922 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5445 "conf_parser.c"
    break;

  case 387: /* cluster_type_item: XLINE  */
#line 1926 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5454 "conf_parser.c"
    break;

  case 388: /* cluster_type_item: T_UNXLINE  */
#line 1930 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5463 "conf_parser.c"
    break;

  case 389: /* cluster_type_item: RESV  */
#line 1934 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5472 "conf_parser.c"
    break;

  case 390: /* cluster_type_item: T_UNRESV  */
#line 1938 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5481 "conf_parser.c"
    break;

  case 391: /* cluster_type_item: T_LOCOPS  */
#line 1942 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5490 "conf_parser.c"
    break;

  case 392: /* cluster_type_item: T_ALL  */
#line 1946 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5499 "conf_parser.c"
    break;

  case 393: /* $@20: %empty  */
#line 1956 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5514 "conf_parser.c"
    break;

  case 394: /* connect_entry: CONNECT $@20 '{' connect_items '}' ';'  */
#line 1966 "conf_parser.y"
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
#line 5585 "conf_parser.c"
    break;

  case 413: /* connect_name: NAME '=' QSTRING ';'  */
#line 2052 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5594 "conf_parser.c"
    break;

  case 414: /* connect_host: HOST '=' QSTRING ';'  */
#line 2058 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5603 "conf_parser.c"
    break;

  case 415: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 2064 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5612 "conf_parser.c"
    break;

  case 416: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 2070 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5621 "conf_parser.c"
    break;

  case 417: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2076 "conf_parser.y"
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
#line 5637 "conf_parser.c"
    break;

  case 418: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2089 "conf_parser.y"
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
#line 5653 "conf_parser.c"
    break;

  case 419: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2102 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5662 "conf_parser.c"
    break;

  case 420: /* connect_port: PORT '=' NUMBER ';'  */
#line 2108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5671 "conf_parser.c"
    break;

  case 421: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2114 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5680 "conf_parser.c"
    break;

  case 422: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2118 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5689 "conf_parser.c"
    break;

  case 423: /* $@21: %empty  */
#line 2124 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5697 "conf_parser.c"
    break;

  case 427: /* connect_flags_item: AUTOCONN  */
#line 2130 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5706 "conf_parser.c"
    break;

  case 428: /* connect_flags_item: T_TLS  */
#line 2134 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5715 "conf_parser.c"
    break;

  case 429: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2140 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5729 "conf_parser.c"
    break;

  case 430: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2151 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5738 "conf_parser.c"
    break;

  case 431: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2157 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5747 "conf_parser.c"
    break;

  case 432: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2163 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5756 "conf_parser.c"
    break;

  case 433: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2169 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5770 "conf_parser.c"
    break;

  case 434: /* $@22: %empty  */
#line 2184 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5779 "conf_parser.c"
    break;

  case 435: /* kill_entry: KILL $@22 '{' kill_items '}' ';'  */
#line 2188 "conf_parser.y"
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
#line 5802 "conf_parser.c"
    break;

  case 441: /* kill_user: USER '=' QSTRING ';'  */
#line 2211 "conf_parser.y"
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
#line 5825 "conf_parser.c"
    break;

  case 442: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2231 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5834 "conf_parser.c"
    break;

  case 443: /* $@23: %empty  */
#line 2241 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5843 "conf_parser.c"
    break;

  case 444: /* deny_entry: DENY $@23 '{' deny_items '}' ';'  */
#line 2245 "conf_parser.y"
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
#line 5867 "conf_parser.c"
    break;

  case 450: /* deny_ip: IP '=' QSTRING ';'  */
#line 2269 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5876 "conf_parser.c"
    break;

  case 451: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2275 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5885 "conf_parser.c"
    break;

  case 457: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2290 "conf_parser.y"
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
#line 5902 "conf_parser.c"
    break;

  case 458: /* $@24: %empty  */
#line 2307 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5911 "conf_parser.c"
    break;

  case 459: /* gecos_entry: GECOS $@24 '{' gecos_items '}' ';'  */
#line 2311 "conf_parser.y"
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
#line 5931 "conf_parser.c"
    break;

  case 465: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2331 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5940 "conf_parser.c"
    break;

  case 466: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2337 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5949 "conf_parser.c"
    break;

  case 516: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2398 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5957 "conf_parser.c"
    break;

  case 517: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2403 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5965 "conf_parser.c"
    break;

  case 518: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2408 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5973 "conf_parser.c"
    break;

  case 519: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2413 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5981 "conf_parser.c"
    break;

  case 520: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2418 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5989 "conf_parser.c"
    break;

  case 521: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2423 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5997 "conf_parser.c"
    break;

  case 522: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2428 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 6005 "conf_parser.c"
    break;

  case 523: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2433 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6013 "conf_parser.c"
    break;

  case 524: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2438 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6021 "conf_parser.c"
    break;

  case 525: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2443 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6029 "conf_parser.c"
    break;

  case 526: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2448 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 6037 "conf_parser.c"
    break;

  case 527: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2453 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 6045 "conf_parser.c"
    break;

  case 528: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2458 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6053 "conf_parser.c"
    break;

  case 529: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2463 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6061 "conf_parser.c"
    break;

  case 530: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2468 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6069 "conf_parser.c"
    break;

  case 531: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2473 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6077 "conf_parser.c"
    break;

  case 532: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2478 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6085 "conf_parser.c"
    break;

  case 533: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2483 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6093 "conf_parser.c"
    break;

  case 534: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2488 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6101 "conf_parser.c"
    break;

  case 535: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2493 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6109 "conf_parser.c"
    break;

  case 536: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2498 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6117 "conf_parser.c"
    break;

  case 537: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2503 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 6125 "conf_parser.c"
    break;

  case 538: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2508 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 6133 "conf_parser.c"
    break;

  case 539: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2513 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 6141 "conf_parser.c"
    break;

  case 540: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2518 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6149 "conf_parser.c"
    break;

  case 541: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2523 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 6157 "conf_parser.c"
    break;

  case 542: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2528 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 6165 "conf_parser.c"
    break;

  case 543: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2533 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6173 "conf_parser.c"
    break;

  case 544: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2538 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6181 "conf_parser.c"
    break;

  case 545: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2543 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6189 "conf_parser.c"
    break;

  case 546: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2548 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6197 "conf_parser.c"
    break;

  case 547: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2553 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6205 "conf_parser.c"
    break;

  case 548: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2558 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6213 "conf_parser.c"
    break;

  case 549: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2563 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6221 "conf_parser.c"
    break;

  case 550: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2568 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6229 "conf_parser.c"
    break;

  case 551: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2573 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6237 "conf_parser.c"
    break;

  case 552: /* general_disable_auth: DISABLE_AUTH '=' TBOOL ';'  */
#line 2578 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6245 "conf_parser.c"
    break;

  case 553: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2583 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6253 "conf_parser.c"
    break;

  case 554: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2588 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6261 "conf_parser.c"
    break;

  case 555: /* $@25: %empty  */
#line 2593 "conf_parser.y"
{
  ConfigGeneral.oper_umodes = 0;
}
#line 6269 "conf_parser.c"
    break;

  case 559: /* umode_oitem: BOT  */
#line 2599 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_BOT;
}
#line 6277 "conf_parser.c"
    break;

  case 560: /* umode_oitem: T_CCONN  */
#line 2602 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6285 "conf_parser.c"
    break;

  case 561: /* umode_oitem: T_DEAF  */
#line 2605 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6293 "conf_parser.c"
    break;

  case 562: /* umode_oitem: T_FLOOD  */
#line 2608 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FLOOD;
}
#line 6301 "conf_parser.c"
    break;

  case 563: /* umode_oitem: HIDDEN  */
#line 2611 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6309 "conf_parser.c"
    break;

  case 564: /* umode_oitem: HIDE_CHANS  */
#line 2614 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6317 "conf_parser.c"
    break;

  case 565: /* umode_oitem: HIDE_IDLE  */
#line 2617 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6325 "conf_parser.c"
    break;

  case 566: /* umode_oitem: T_SKILL  */
#line 2620 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6333 "conf_parser.c"
    break;

  case 567: /* umode_oitem: T_NCHANGE  */
#line 2623 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6341 "conf_parser.c"
    break;

  case 568: /* umode_oitem: T_REJ  */
#line 2626 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6349 "conf_parser.c"
    break;

  case 569: /* umode_oitem: T_SPY  */
#line 2629 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6357 "conf_parser.c"
    break;

  case 570: /* umode_oitem: T_EXTERNAL  */
#line 2632 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6365 "conf_parser.c"
    break;

  case 571: /* umode_oitem: T_SERVNOTICE  */
#line 2635 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6373 "conf_parser.c"
    break;

  case 572: /* umode_oitem: T_INVISIBLE  */
#line 2638 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6381 "conf_parser.c"
    break;

  case 573: /* umode_oitem: T_WALLOP  */
#line 2641 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6389 "conf_parser.c"
    break;

  case 574: /* umode_oitem: T_SOFTCALLERID  */
#line 2644 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6397 "conf_parser.c"
    break;

  case 575: /* umode_oitem: T_CALLERID  */
#line 2647 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6405 "conf_parser.c"
    break;

  case 576: /* umode_oitem: T_LOCOPS  */
#line 2650 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6413 "conf_parser.c"
    break;

  case 577: /* umode_oitem: T_NONONREG  */
#line 2653 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6421 "conf_parser.c"
    break;

  case 578: /* umode_oitem: T_FARCONNECT  */
#line 2656 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6429 "conf_parser.c"
    break;

  case 579: /* umode_oitem: EXPIRATION  */
#line 2659 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6437 "conf_parser.c"
    break;

  case 580: /* umode_oitem: T_SECUREONLY  */
#line 2662 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SECUREONLY;
}
#line 6445 "conf_parser.c"
    break;

  case 581: /* $@26: %empty  */
#line 2667 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6453 "conf_parser.c"
    break;

  case 585: /* umode_item: BOT  */
#line 2673 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_BOT;
}
#line 6461 "conf_parser.c"
    break;

  case 586: /* umode_item: T_CCONN  */
#line 2676 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6469 "conf_parser.c"
    break;

  case 587: /* umode_item: T_DEAF  */
#line 2679 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6477 "conf_parser.c"
    break;

  case 588: /* umode_item: T_FLOOD  */
#line 2682 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FLOOD;
}
#line 6485 "conf_parser.c"
    break;

  case 589: /* umode_item: T_SKILL  */
#line 2685 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6493 "conf_parser.c"
    break;

  case 590: /* umode_item: HIDDEN  */
#line 2688 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6501 "conf_parser.c"
    break;

  case 591: /* umode_item: HIDE_CHANS  */
#line 2691 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDECHANS;
}
#line 6509 "conf_parser.c"
    break;

  case 592: /* umode_item: HIDE_IDLE  */
#line 2694 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDEIDLE;
}
#line 6517 "conf_parser.c"
    break;

  case 593: /* umode_item: T_NCHANGE  */
#line 2697 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6525 "conf_parser.c"
    break;

  case 594: /* umode_item: T_REJ  */
#line 2700 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6533 "conf_parser.c"
    break;

  case 595: /* umode_item: T_SPY  */
#line 2703 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6541 "conf_parser.c"
    break;

  case 596: /* umode_item: T_EXTERNAL  */
#line 2706 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6549 "conf_parser.c"
    break;

  case 597: /* umode_item: T_SERVNOTICE  */
#line 2709 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6557 "conf_parser.c"
    break;

  case 598: /* umode_item: T_INVISIBLE  */
#line 2712 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6565 "conf_parser.c"
    break;

  case 599: /* umode_item: T_WALLOP  */
#line 2715 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6573 "conf_parser.c"
    break;

  case 600: /* umode_item: T_SOFTCALLERID  */
#line 2718 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6581 "conf_parser.c"
    break;

  case 601: /* umode_item: T_CALLERID  */
#line 2721 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6589 "conf_parser.c"
    break;

  case 602: /* umode_item: T_LOCOPS  */
#line 2724 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6597 "conf_parser.c"
    break;

  case 603: /* umode_item: T_NONONREG  */
#line 2727 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6605 "conf_parser.c"
    break;

  case 604: /* umode_item: T_FARCONNECT  */
#line 2730 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6613 "conf_parser.c"
    break;

  case 605: /* umode_item: EXPIRATION  */
#line 2733 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6621 "conf_parser.c"
    break;

  case 606: /* umode_item: T_SECUREONLY  */
#line 2736 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SECUREONLY;
}
#line 6629 "conf_parser.c"
    break;

  case 607: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2741 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6637 "conf_parser.c"
    break;

  case 608: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2746 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6645 "conf_parser.c"
    break;

  case 609: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2751 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6653 "conf_parser.c"
    break;

  case 610: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2756 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6661 "conf_parser.c"
    break;

  case 632: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2787 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6669 "conf_parser.c"
    break;

  case 633: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2792 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6678 "conf_parser.c"
    break;

  case 634: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2798 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6687 "conf_parser.c"
    break;

  case 635: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2804 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6695 "conf_parser.c"
    break;

  case 636: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2809 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6703 "conf_parser.c"
    break;

  case 637: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2814 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6711 "conf_parser.c"
    break;

  case 638: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2819 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6719 "conf_parser.c"
    break;

  case 639: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2824 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6727 "conf_parser.c"
    break;

  case 640: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2829 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6735 "conf_parser.c"
    break;

  case 641: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2834 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6743 "conf_parser.c"
    break;

  case 642: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2839 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6751 "conf_parser.c"
    break;

  case 643: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2844 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6759 "conf_parser.c"
    break;

  case 644: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2849 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6767 "conf_parser.c"
    break;

  case 645: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2854 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6775 "conf_parser.c"
    break;

  case 646: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2859 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6783 "conf_parser.c"
    break;

  case 647: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2864 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6791 "conf_parser.c"
    break;

  case 648: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2869 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6799 "conf_parser.c"
    break;

  case 662: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2892 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6808 "conf_parser.c"
    break;

  case 663: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2898 "conf_parser.y"
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
#line 6827 "conf_parser.c"
    break;

  case 664: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2914 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6839 "conf_parser.c"
    break;

  case 665: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2923 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6848 "conf_parser.c"
    break;

  case 666: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2929 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6857 "conf_parser.c"
    break;

  case 667: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2935 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6866 "conf_parser.c"
    break;

  case 668: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2941 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6878 "conf_parser.c"
    break;

  case 669: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2950 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6887 "conf_parser.c"
    break;

  case 670: /* serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'  */
#line 2956 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6896 "conf_parser.c"
    break;


#line 6900 "conf_parser.c"

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

