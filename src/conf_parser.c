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
#line 13 "conf_parser.y"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "address.h"
#include "io_string.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "module.h"

#include "client.h"
#include "client_id.h"
#include "cloak.h"
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
#include "defaults.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "links_cache.h"
#include "listener.h"
#include "motd.h"
#include "nuh.h"
#include "server.h"
#include "user.h"

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


#line 189 "conf_parser.c"

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
    REGISTRATION_TIMEOUT = 396,    /* REGISTRATION_TIMEOUT  */
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
    T_COMMAND = 428,               /* T_COMMAND  */
    T_CLUSTER = 429,               /* T_CLUSTER  */
    T_DEBUG = 430,                 /* T_DEBUG  */
    T_DLINE = 431,                 /* T_DLINE  */
    T_FILE = 432,                  /* T_FILE  */
    T_GLOBOPS = 433,               /* T_GLOBOPS  */
    T_IPV4 = 434,                  /* T_IPV4  */
    T_IPV6 = 435,                  /* T_IPV6  */
    T_LOCOPS = 436,                /* T_LOCOPS  */
    T_LOG = 437,                   /* T_LOG  */
    T_OPME = 438,                  /* T_OPME  */
    T_PREPEND = 439,               /* T_PREPEND  */
    T_PSEUDO = 440,                /* T_PSEUDO  */
    T_RECVQ = 441,                 /* T_RECVQ  */
    T_RESTART = 442,               /* T_RESTART  */
    T_SERVER = 443,                /* T_SERVER  */
    T_SERVICE = 444,               /* T_SERVICE  */
    T_SET = 445,                   /* T_SET  */
    T_SHARED = 446,                /* T_SHARED  */
    T_SIZE = 447,                  /* T_SIZE  */
    T_TARGET = 448,                /* T_TARGET  */
    T_TLS = 449,                   /* T_TLS  */
    T_UMODES = 450,                /* T_UMODES  */
    T_UNDLINE = 451,               /* T_UNDLINE  */
    T_UNLIMITED = 452,             /* T_UNLIMITED  */
    T_UNRESV = 453,                /* T_UNRESV  */
    T_UNXLINE = 454,               /* T_UNXLINE  */
    T_WEBIRC = 455,                /* T_WEBIRC  */
    TBOOL = 456,                   /* TBOOL  */
    THROTTLE_COUNT = 457,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 458,           /* THROTTLE_TIME  */
    TIMEOUT = 459,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 460,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 461, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 462,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 463,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 464, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 465,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 466, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 467,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 468,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 469,           /* TS_WARN_DELTA  */
    TWODOTS = 470,                 /* TWODOTS  */
    TYPE = 471,                    /* TYPE  */
    UNKLINE = 472,                 /* UNKLINE  */
    USE_LOGGING = 473,             /* USE_LOGGING  */
    USER = 474,                    /* USER  */
    VHOST = 475,                   /* VHOST  */
    VHOST6 = 476,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 477,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 478,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 479,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 480,                   /* XLINE  */
    XLINE_EXEMPT = 481,            /* XLINE_EXEMPT  */
    QSTRING = 482,                 /* QSTRING  */
    NUMBER = 483                   /* NUMBER  */
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
#define REGISTRATION_TIMEOUT 396
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
#define T_COMMAND 428
#define T_CLUSTER 429
#define T_DEBUG 430
#define T_DLINE 431
#define T_FILE 432
#define T_GLOBOPS 433
#define T_IPV4 434
#define T_IPV6 435
#define T_LOCOPS 436
#define T_LOG 437
#define T_OPME 438
#define T_PREPEND 439
#define T_PSEUDO 440
#define T_RECVQ 441
#define T_RESTART 442
#define T_SERVER 443
#define T_SERVICE 444
#define T_SET 445
#define T_SHARED 446
#define T_SIZE 447
#define T_TARGET 448
#define T_TLS 449
#define T_UMODES 450
#define T_UNDLINE 451
#define T_UNLIMITED 452
#define T_UNRESV 453
#define T_UNXLINE 454
#define T_WEBIRC 455
#define TBOOL 456
#define THROTTLE_COUNT 457
#define THROTTLE_TIME 458
#define TIMEOUT 459
#define TLS_CERTIFICATE_FILE 460
#define TLS_CERTIFICATE_FINGERPRINT 461
#define TLS_CIPHER_LIST 462
#define TLS_CIPHER_SUITES 463
#define TLS_CONNECTION_REQUIRED 464
#define TLS_DH_PARAM_FILE 465
#define TLS_MESSAGE_DIGEST_ALGORITHM 466
#define TLS_SUPPORTED_GROUPS 467
#define TS_MAX_DELTA 468
#define TS_WARN_DELTA 469
#define TWODOTS 470
#define TYPE 471
#define UNKLINE 472
#define USE_LOGGING 473
#define USER 474
#define VHOST 475
#define VHOST6 476
#define WARN_NO_CONNECT_BLOCK 477
#define WHOIS 478
#define WHOWAS_HISTORY_LENGTH 479
#define XLINE 480
#define XLINE_EXEMPT 481
#define QSTRING 482
#define NUMBER 483

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 131 "conf_parser.y"

  int number;
  char *string;

#line 703 "conf_parser.c"

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
  YYSYMBOL_REGISTRATION_TIMEOUT = 141,     /* REGISTRATION_TIMEOUT  */
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
  YYSYMBOL_T_COMMAND = 173,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 174,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 175,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 176,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 177,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 178,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 179,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 180,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 181,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 182,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 183,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 184,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 185,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 186,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 187,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 188,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 189,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 190,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 191,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 192,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 193,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 194,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 195,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 196,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 197,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 198,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 199,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 200,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 201,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 202,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 203,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 204,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 205,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 206, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_CIPHER_LIST = 207,          /* TLS_CIPHER_LIST  */
  YYSYMBOL_TLS_CIPHER_SUITES = 208,        /* TLS_CIPHER_SUITES  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 209,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TLS_DH_PARAM_FILE = 210,        /* TLS_DH_PARAM_FILE  */
  YYSYMBOL_TLS_MESSAGE_DIGEST_ALGORITHM = 211, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
  YYSYMBOL_TLS_SUPPORTED_GROUPS = 212,     /* TLS_SUPPORTED_GROUPS  */
  YYSYMBOL_TS_MAX_DELTA = 213,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 214,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 215,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 216,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 217,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 218,              /* USE_LOGGING  */
  YYSYMBOL_USER = 219,                     /* USER  */
  YYSYMBOL_VHOST = 220,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 221,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 222,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 223,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 224,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 225,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 226,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 227,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 228,                   /* NUMBER  */
  YYSYMBOL_229_ = 229,                     /* ';'  */
  YYSYMBOL_230_ = 230,                     /* '}'  */
  YYSYMBOL_231_ = 231,                     /* '='  */
  YYSYMBOL_232_ = 232,                     /* ':'  */
  YYSYMBOL_233_ = 233,                     /* ','  */
  YYSYMBOL_234_ = 234,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 235,                 /* $accept  */
  YYSYMBOL_conf = 236,                     /* conf  */
  YYSYMBOL_conf_item = 237,                /* conf_item  */
  YYSYMBOL_timespec_ = 238,                /* timespec_  */
  YYSYMBOL_timespec = 239,                 /* timespec  */
  YYSYMBOL_sizespec_ = 240,                /* sizespec_  */
  YYSYMBOL_sizespec = 241,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 242,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 243,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 244,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 245,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 246,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 247,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 248,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 249,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 250, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_rsa_private_key_file = 251, /* serverinfo_rsa_private_key_file  */
  YYSYMBOL_serverinfo_tls_dh_param_file = 252, /* serverinfo_tls_dh_param_file  */
  YYSYMBOL_serverinfo_tls_cipher_list = 253, /* serverinfo_tls_cipher_list  */
  YYSYMBOL_serverinfo_tls_cipher_suites = 254, /* serverinfo_tls_cipher_suites  */
  YYSYMBOL_serverinfo_tls_message_digest_algorithm = 255, /* serverinfo_tls_message_digest_algorithm  */
  YYSYMBOL_serverinfo_tls_supported_groups = 256, /* serverinfo_tls_supported_groups  */
  YYSYMBOL_serverinfo_name = 257,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 258,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 259,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 260,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 261, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 262, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 263, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 264, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_motd_file = 265,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 266,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 267,              /* admin_entry  */
  YYSYMBOL_admin_items = 268,              /* admin_items  */
  YYSYMBOL_admin_item = 269,               /* admin_item  */
  YYSYMBOL_admin_name = 270,               /* admin_name  */
  YYSYMBOL_admin_email = 271,              /* admin_email  */
  YYSYMBOL_admin_description = 272,        /* admin_description  */
  YYSYMBOL_motd_entry = 273,               /* motd_entry  */
  YYSYMBOL_274_1 = 274,                    /* $@1  */
  YYSYMBOL_motd_items = 275,               /* motd_items  */
  YYSYMBOL_motd_item = 276,                /* motd_item  */
  YYSYMBOL_motd_mask = 277,                /* motd_mask  */
  YYSYMBOL_motd_file = 278,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 279,             /* pseudo_entry  */
  YYSYMBOL_280_2 = 280,                    /* $@2  */
  YYSYMBOL_pseudo_items = 281,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 282,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 283,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 284,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 285,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 286,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 287,            /* logging_entry  */
  YYSYMBOL_logging_items = 288,            /* logging_items  */
  YYSYMBOL_logging_item = 289,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 290,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 291,       /* logging_file_entry  */
  YYSYMBOL_292_3 = 292,                    /* $@3  */
  YYSYMBOL_logging_file_items = 293,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 294,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 295,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 296,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 297,        /* logging_file_type  */
  YYSYMBOL_298_4 = 298,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 299,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 300,               /* oper_entry  */
  YYSYMBOL_301_5 = 301,                    /* $@5  */
  YYSYMBOL_oper_items = 302,               /* oper_items  */
  YYSYMBOL_oper_item = 303,                /* oper_item  */
  YYSYMBOL_oper_name = 304,                /* oper_name  */
  YYSYMBOL_oper_user = 305,                /* oper_user  */
  YYSYMBOL_oper_password = 306,            /* oper_password  */
  YYSYMBOL_oper_whois = 307,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 308,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 309, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 310, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 311,               /* oper_class  */
  YYSYMBOL_oper_umodes = 312,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 313,               /* oper_flags  */
  YYSYMBOL_314_6 = 314,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 315,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 316,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 317,              /* class_entry  */
  YYSYMBOL_318_7 = 318,                    /* $@7  */
  YYSYMBOL_class_items = 319,              /* class_items  */
  YYSYMBOL_class_item = 320,               /* class_item  */
  YYSYMBOL_class_name = 321,               /* class_name  */
  YYSYMBOL_class_ping_time = 322,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 323, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 324, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 325,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 326,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 327,         /* class_max_number  */
  YYSYMBOL_class_sendq = 328,              /* class_sendq  */
  YYSYMBOL_class_recvq = 329,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 330,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 331,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 332,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 333,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 334,           /* class_max_idle  */
  YYSYMBOL_class_flags = 335,              /* class_flags  */
  YYSYMBOL_336_8 = 336,                    /* $@8  */
  YYSYMBOL_class_flags_items = 337,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 338,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 339,             /* listen_entry  */
  YYSYMBOL_340_9 = 340,                    /* $@9  */
  YYSYMBOL_listen_flags = 341,             /* listen_flags  */
  YYSYMBOL_342_10 = 342,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 343,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 344,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 345,             /* listen_items  */
  YYSYMBOL_listen_item = 346,              /* listen_item  */
  YYSYMBOL_listen_port = 347,              /* listen_port  */
  YYSYMBOL_348_11 = 348,                   /* $@11  */
  YYSYMBOL_port_items = 349,               /* port_items  */
  YYSYMBOL_port_item = 350,                /* port_item  */
  YYSYMBOL_listen_address = 351,           /* listen_address  */
  YYSYMBOL_listen_host = 352,              /* listen_host  */
  YYSYMBOL_auth_entry = 353,               /* auth_entry  */
  YYSYMBOL_354_12 = 354,                   /* $@12  */
  YYSYMBOL_auth_items = 355,               /* auth_items  */
  YYSYMBOL_auth_item = 356,                /* auth_item  */
  YYSYMBOL_auth_user = 357,                /* auth_user  */
  YYSYMBOL_auth_passwd = 358,              /* auth_passwd  */
  YYSYMBOL_auth_class = 359,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 360,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 361,               /* auth_flags  */
  YYSYMBOL_362_13 = 362,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 363,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 364,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 365,               /* auth_spoof  */
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
  YYSYMBOL_general_max_away_length = 458,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 459, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 460,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 461,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 462, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 463, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 464, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 465, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 466, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 467, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 468, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 469, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 470, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 471,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 472,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 473, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 474, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 475,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 476,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 477, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 478,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 479,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_ident = 480,    /* general_disable_ident  */
  YYSYMBOL_general_disable_dns = 481,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 482,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 483,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 484,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 485,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 486, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 487, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 488, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 489,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 490, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 491, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 492,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 493,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 494,     /* general_cloak_suffix  */
  YYSYMBOL_general_ident_timeout = 495,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 496, /* general_registration_timeout  */
  YYSYMBOL_channel_entry = 497,            /* channel_entry  */
  YYSYMBOL_channel_items = 498,            /* channel_items  */
  YYSYMBOL_channel_item = 499,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 500,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 501,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 502,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 503, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 504, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 505, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 506, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 507, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 508, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 509, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 510, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 511,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 512,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 513,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 514,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 515,  /* channel_max_kick_length  */
  YYSYMBOL_channel_default_join_flood_count = 516, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 517, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 518,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 519,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 520,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 521, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 522, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 523, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 524, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 525,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 526, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 527,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 528         /* serverhide_hidden  */
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
#define YYLAST   1365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  611
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1281

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   483


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
       2,     2,     2,     2,   233,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   232,   229,
       2,   231,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   234,     2,   230,     2,     2,     2,     2,
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
     225,   226,   227,   228
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   361,   361,   362,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   393,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   404,
     404,   405,   406,   407,   408,   415,   425,   432,   434,   436,
     436,   438,   442,   452,   454,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   475,   484,   493,   502,   511,   520,
     529,   538,   553,   568,   578,   592,   601,   624,   647,   655,
     664,   674,   676,   676,   677,   678,   679,   680,   682,   691,
     700,   714,   713,   731,   731,   732,   732,   732,   734,   740,
     751,   750,   769,   769,   770,   770,   770,   770,   770,   772,
     778,   784,   790,   813,   814,   814,   816,   816,   817,   819,
     829,   829,   842,   843,   845,   845,   846,   846,   848,   856,
     859,   865,   864,   870,   874,   878,   882,   886,   890,   894,
     898,   909,   908,   970,   970,   971,   972,   973,   974,   975,
     976,   977,   978,   979,   980,   981,   983,   989,   995,  1001,
    1007,  1018,  1024,  1035,  1041,  1048,  1047,  1053,  1053,  1054,
    1058,  1062,  1066,  1070,  1074,  1078,  1082,  1086,  1090,  1094,
    1098,  1102,  1106,  1110,  1114,  1118,  1122,  1126,  1130,  1134,
    1138,  1142,  1146,  1150,  1154,  1158,  1162,  1166,  1177,  1176,
    1232,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,  1240,
    1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,  1250,  1256,
    1262,  1268,  1274,  1280,  1286,  1292,  1298,  1305,  1311,  1317,
    1323,  1332,  1342,  1341,  1347,  1347,  1348,  1352,  1363,  1362,
    1369,  1368,  1373,  1373,  1374,  1378,  1382,  1386,  1390,  1396,
    1396,  1397,  1397,  1397,  1397,  1397,  1399,  1399,  1401,  1401,
    1403,  1416,  1433,  1439,  1450,  1449,  1497,  1497,  1498,  1499,
    1500,  1501,  1502,  1503,  1504,  1506,  1512,  1518,  1524,  1536,
    1535,  1541,  1541,  1542,  1546,  1550,  1554,  1558,  1562,  1566,
    1570,  1574,  1580,  1599,  1598,  1613,  1613,  1614,  1614,  1614,
    1614,  1616,  1622,  1628,  1638,  1640,  1640,  1641,  1641,  1643,
    1660,  1659,  1682,  1682,  1683,  1683,  1683,  1683,  1685,  1691,
    1711,  1710,  1716,  1716,  1717,  1721,  1725,  1729,  1733,  1737,
    1741,  1745,  1749,  1753,  1764,  1763,  1782,  1782,  1783,  1783,
    1783,  1785,  1792,  1791,  1797,  1797,  1798,  1802,  1806,  1810,
    1814,  1818,  1822,  1826,  1830,  1834,  1845,  1844,  1901,  1901,
    1902,  1903,  1904,  1905,  1906,  1907,  1908,  1909,  1910,  1911,
    1912,  1913,  1914,  1915,  1916,  1917,  1919,  1925,  1931,  1937,
    1943,  1956,  1969,  1975,  1981,  1985,  1992,  1991,  1996,  1996,
    1997,  2001,  2007,  2018,  2024,  2030,  2036,  2052,  2051,  2075,
    2075,  2076,  2076,  2076,  2078,  2098,  2109,  2108,  2133,  2133,
    2134,  2134,  2134,  2136,  2142,  2152,  2154,  2154,  2155,  2155,
    2157,  2176,  2175,  2196,  2196,  2197,  2197,  2197,  2199,  2205,
    2215,  2217,  2217,  2218,  2219,  2220,  2221,  2222,  2223,  2224,
    2225,  2226,  2227,  2228,  2229,  2230,  2231,  2232,  2233,  2234,
    2235,  2236,  2237,  2238,  2239,  2240,  2241,  2242,  2243,  2244,
    2245,  2246,  2247,  2248,  2249,  2250,  2251,  2252,  2253,  2254,
    2255,  2256,  2257,  2258,  2259,  2260,  2261,  2262,  2263,  2264,
    2265,  2266,  2267,  2268,  2269,  2270,  2271,  2272,  2275,  2280,
    2285,  2290,  2295,  2300,  2305,  2310,  2315,  2320,  2325,  2330,
    2335,  2340,  2345,  2350,  2358,  2363,  2368,  2373,  2378,  2383,
    2388,  2393,  2398,  2403,  2408,  2413,  2418,  2423,  2428,  2433,
    2438,  2443,  2448,  2453,  2458,  2463,  2468,  2473,  2478,  2483,
    2492,  2497,  2502,  2507,  2512,  2529,  2537,  2545,  2553,  2563,
    2573,  2581,  2590,  2592,  2592,  2593,  2594,  2595,  2596,  2597,
    2598,  2599,  2600,  2601,  2602,  2603,  2604,  2605,  2606,  2607,
    2608,  2609,  2610,  2611,  2613,  2618,  2624,  2630,  2635,  2640,
    2645,  2650,  2655,  2660,  2665,  2670,  2675,  2680,  2685,  2690,
    2713,  2718,  2727,  2729,  2729,  2730,  2731,  2732,  2733,  2734,
    2735,  2736,  2737,  2738,  2740,  2746,  2757,  2766,  2772,  2778,
    2784,  2793
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
  "REGISTRATION_TIMEOUT", "REHASH", "REMOTE", "REMOTEBAN", "RESIDENT",
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
  "auth_flags_items", "auth_flags_item", "auth_spoof", "resv_entry",
  "$@14", "resv_items", "resv_item", "resv_mask", "resv_reason",
  "resv_exempt", "service_entry", "service_items", "service_item",
  "service_name", "shared_entry", "$@15", "shared_items", "shared_item",
  "shared_name", "shared_user", "shared_type", "$@16", "shared_types",
  "shared_type_item", "cluster_entry", "$@17", "cluster_items",
  "cluster_item", "cluster_name", "cluster_type", "$@18", "cluster_types",
  "cluster_type_item", "connect_entry", "$@19", "connect_items",
  "connect_item", "connect_name", "connect_host", "connect_timeout",
  "connect_bind", "connect_send_password", "connect_accept_password",
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

#define YYPACT_NINF (-1002)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-131)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1002,   706, -1002,  -173,  -219,  -216, -1002, -1002, -1002,  -211,
   -1002,  -209, -1002, -1002, -1002,  -192,  -168, -1002, -1002, -1002,
    -162,  -160, -1002,  -156, -1002,  -147, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,    19,   844,  -146,  -137,  -134,     5,  -133,
     430,  -132,  -130,  -128,  -194,   -98,   -93,   -90,   -68,   729,
     544,   -67,    92,   -65,    20,   -64,   -50,   -95,   -51,   -49,
      15, -1002, -1002, -1002, -1002, -1002,   -35,   -27,   -25,   -22,
     -19,   -15,   -14,   -12,    -7,    -4,    -3,    -2,     0,    35,
      43,    53,    59,    95,   198, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,   749,   605,     6, -1002,    97,    76,
   -1002, -1002,    54, -1002,   101,   103,   106,   113,   114,   115,
     118,   119,   120,   122,   124,   125,   126,   130,   136,   137,
     138,   140,   141,   145,   147,   150,   151,   153,   154,   155,
     159,   162,   165,   168,   170,   171,   174,   177,   190,   192,
     193,   194,   196,   202,   203,   210,   211,   212,   214,   216,
     217,   218,   226,   227,   228,   229,   233,   234,    89, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,   288,    18,   251,   -26,   -48,   166,
     117,   419,    23, -1002,   235,   238,   243,   246,   248,   254,
     255,   256,     4, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002,   206,   258,   259,   261,   265,   267,   271,   272,
     275,   277,   278,   279,   280,   282,   283,   286,   287,   289,
     199, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,    72,
     276,   290,    21, -1002, -1002, -1002,   342,   204, -1002,   293,
      38, -1002, -1002,   146, -1002,   121,   148,   300,   299, -1002,
     301,   303,   331,   338,   340,   343,   318,   303,   303,   303,
     319,   303,   303,   321,   322,   323,   324,   327,   328, -1002,
     329,   333,   334,   336, -1002,   337,   339,   341,   346,   350,
     351,   353,   356,   357,   358,   361,    50, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,   344,   362,   370,   371,   372,   373,   376,
   -1002,   380,   382,   384,   385,   386,   388,   389,   390,   274,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002,   391,   396,    51,
   -1002, -1002, -1002,   352,   401, -1002, -1002,   400,   403,    46,
   -1002, -1002, -1002,   359,   303,   408,   303,   303,   368,   412,
     417,   418,   420,   421,   449,   423,   303,   454,   456,   431,
     432,   462,   303,   463,   303,   439,   440,   441,   442,   447,
     451,   303,   452,   453,   458,   476,   457,   486,   303,   303,
     487,   303,   489,   475,   503,   504,   507,   508,   510,   512,
     514,   488,   303,   303,   303,   517,   493,   497, -1002,   498,
     500,   501, -1002,   502,   505,   506,   264, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002,   509,   515,   161, -1002, -1002,
   -1002,   499,   516,   522, -1002,   526, -1002,    13, -1002, -1002,
   -1002, -1002, -1002, -1002,   496, -1002, -1002, -1002,   519,   527,
     531,    31, -1002, -1002, -1002,   534,   538,   539, -1002,   540,
     541,   545,   548,   550,   551,   557,   164, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,   562,   561,
     565,   568,    33, -1002, -1002, -1002, -1002,   537,   573,   303,
     518,   592,   574,   599,   601,   575, -1002, -1002,   578,   576,
     606,   581,   585,   586,   589,   590,   591,   593,   596,   597,
     598,   602,   604,   607,   608,   609, -1002,   610,   588, -1002,
     108, -1002, -1002, -1002, -1002,   625,   611, -1002,   594,   612,
     613,   615,   616,   619,    30, -1002, -1002, -1002, -1002, -1002,
     626,   614, -1002,   628,   623, -1002,   624,    93, -1002, -1002,
   -1002, -1002,   629,   632,   633, -1002,   637,   547,   639,   640,
     641,   642,   643,   644,   645,   652,   653,   654,   655,   656,
     660,   661,   667,   669,   670, -1002, -1002,   635,   672,   303,
     671,   673,   303,   675,   303,   677,   679,   680,   681,   303,
     682,   682,   676, -1002, -1002,   684,  -136,   685,   636,   686,
     687,   689,   688,   694,   695,   697,   698,   303,   699,   700,
     693, -1002,   701,   702,   705, -1002,   707, -1002,   703,   710,
     709, -1002,   711,   715,   718,   719,   720,   721,   722,   723,
     724,   725,   726,   727,   728,   730,   731,   732,   733,   734,
     735,   736,   737,   738,   739,   740,   741,   742,   743,   744,
     745,   746,   747,   748,   750,   751,   752,   753,   754,   755,
     756,   757,   758,   759,   760,   761,   762,   763,   764,   765,
     766,   767,   768,   769,   770,   771, -1002, -1002,   712,   777,
     772,   774,   775,   778,   779, -1002,   780,   782,   781, -1002,
   -1002,   784,   785,   773,   786,   787, -1002,   -26, -1002,   788,
     790,   789, -1002, -1002,   792,   805,   791,   793,   794,   796,
     797,   812,   798,   799,   800, -1002, -1002,   801,   803,   804,
     806, -1002,   807,   808,   809,   810,   811,   813,   814,   815,
   -1002,   816,   817,   818,   819,   820,   821,   822,   823,   824,
     825,   826,   827,   828,   829,   830,   831,   832, -1002, -1002,
     835,   802,   834, -1002,   836, -1002,   187, -1002,   837,   839,
     840,   841,   842, -1002,   843, -1002, -1002,   846,   838,   847,
     848, -1002, -1002, -1002, -1002, -1002,   303,   303,   303,   303,
     303,   303,   303, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002,   849,   850,   851,   -47,   852,   853,   854,   855,
     856,   857,   858,   859,   860,    16,   861,   862, -1002,   863,
     864,   865,   866,   867,   868,   869,    -5,   870,   871,   872,
     873,   874,   875,   876,   877, -1002,   878,   879, -1002, -1002,
     880,   881, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002,   882,   883,   348,
     884,   885,   886, -1002,   887,   888, -1002,   889,   890,   294,
     520,   891, -1002, -1002, -1002,   892,   893, -1002,   894,   896,
     495,   897,   898,   899,   900,   901,   902,   903, -1002,   904,
     905,   906, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,   907,   543,
   -1002, -1002,   908,   845,   909, -1002,   144, -1002, -1002, -1002,
   -1002,   910,   912,   913,   914, -1002, -1002,   915,   634,   916,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,  -203, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,   682,   682,   682, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
    -196, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002,  -193, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,  -188,
   -1002,   918,   786,   919, -1002, -1002, -1002, -1002, -1002, -1002,
     795, -1002,   917,   920, -1002,   921, -1002,   922,   923, -1002,
   -1002,   924, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,  -183, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002,  -180, -1002, -1002,   911,
    -186,   926,   929, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,  -158,
   -1002, -1002, -1002,   -47, -1002, -1002, -1002, -1002,    -5, -1002,
     348, -1002,   294, -1002, -1002, -1002,   927,   696,   932,   938,
     895,   977,  1004, -1002,   495, -1002,   543,   930,   931,   933,
     410, -1002, -1002,   634, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,   934, -1002,
   -1002
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   208,   366,   416,     0,
     431,     0,   274,   407,   248,     0,     0,   101,   151,   303,
       0,     0,   344,     0,   110,     0,   320,     3,     4,     5,
      13,     6,    25,    26,     7,     8,    10,    11,    12,    15,
      16,    17,    18,    19,    20,    21,    22,    24,    23,     9,
      14,    27,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    96,    95,   573,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   554,   570,   571,   572,   569,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   555,
     556,   566,   567,   568,     0,     0,     0,   429,     0,     0,
     427,   428,     0,   497,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   442,
     443,   444,   487,   450,   488,   482,   483,   484,   485,   454,
     445,   446,   447,   448,   449,   469,   451,   452,   453,   455,
     456,   486,   460,   461,   462,   463,   459,   458,   464,   471,
     472,   465,   466,   467,   457,   468,   479,   480,   481,   477,
     478,   470,   475,   476,   473,   474,   489,   490,   491,   492,
     493,   494,   495,   496,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   595,   596,   597,   598,   599,   600,
     602,   601,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    69,    67,    65,    70,    71,    72,    66,    56,
      68,    58,    59,    60,    61,    62,    63,    64,    57,     0,
       0,     0,     0,   125,   126,   127,     0,     0,   318,     0,
       0,   316,   317,     0,    97,     0,     0,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   553,
       0,     0,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   211,   212,   215,
     217,   218,   219,   220,   221,   222,   223,   213,   214,   216,
     224,   225,   226,     0,     0,     0,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     369,   370,   371,   372,   373,   374,   375,   376,   378,   377,
     380,   384,   381,   382,   383,   379,   422,     0,     0,     0,
     419,   420,   421,     0,     0,   426,   437,     0,     0,     0,
     434,   435,   436,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   441,     0,
       0,     0,   289,     0,     0,     0,     0,   277,   278,   279,
     280,   283,   281,   282,   413,     0,     0,     0,   410,   411,
     412,     0,     0,     0,   250,     0,   262,     0,   260,   261,
     263,   264,    52,    51,    48,    50,    46,    45,     0,     0,
       0,     0,   104,   105,   106,     0,     0,     0,   175,     0,
       0,     0,     0,     0,     0,     0,     0,   154,   155,   156,
     157,   158,   161,   162,   163,   160,   159,   164,     0,     0,
       0,     0,     0,   306,   307,   308,   309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   593,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,     0,   352,
       0,   347,   348,   349,   128,     0,     0,   124,     0,     0,
       0,     0,     0,     0,     0,   113,   114,   116,   115,   117,
       0,     0,   315,     0,     0,   330,     0,     0,   323,   324,
     325,   326,     0,     0,     0,    91,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   552,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   210,   385,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   368,     0,     0,     0,   418,     0,   425,     0,     0,
       0,   433,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   440,   284,     0,     0,
       0,     0,     0,     0,     0,   276,     0,     0,     0,   409,
     265,     0,     0,     0,     0,     0,   259,     0,   107,     0,
       0,     0,   103,   165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   310,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
     592,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,   350,
       0,     0,     0,   346,     0,   123,     0,   118,     0,     0,
       0,     0,     0,   112,     0,   314,   327,     0,     0,     0,
       0,   322,   100,    99,    98,   590,    29,    29,    29,    29,
      29,    29,    29,    31,    30,   591,   577,   576,   574,   575,
     578,   579,   580,   581,   582,   583,   584,   587,   588,   585,
     586,   589,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,   209,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   367,     0,     0,   417,   430,
       0,     0,   432,   509,   514,   498,   499,   527,   544,   545,
     546,   547,   548,   549,   502,   542,   543,   536,   535,   503,
     504,   508,   550,   517,   507,   505,   506,   512,   513,   500,
     511,   510,   533,   540,   541,   531,   539,   528,   526,   529,
     534,   551,   530,   532,   519,   525,   524,   520,   521,   522,
     523,   537,   538,   516,   515,   518,   501,     0,     0,     0,
       0,     0,     0,   275,     0,     0,   408,     0,     0,     0,
     270,   266,   269,   249,    49,     0,     0,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
       0,     0,   304,   607,   604,   605,   606,   611,   610,   608,
     609,    86,    83,    90,    82,    87,    88,    89,    81,    85,
      84,    75,    74,    77,    78,    76,    79,    80,     0,     0,
     345,   129,     0,     0,     0,   141,     0,   133,   134,   136,
     135,     0,     0,     0,     0,   111,   319,     0,     0,     0,
     321,    32,    33,    34,    35,    36,    37,    38,   237,   238,
     232,   247,   246,     0,   245,   233,   241,   234,   240,   228,
     239,   231,   230,   229,    39,    39,    39,    41,    40,   235,
     236,   391,   394,   395,   405,   402,   387,   403,   400,   401,
       0,   399,   404,   386,   393,   390,   389,   388,   392,   406,
     423,   424,   438,   439,   287,   288,   297,   293,   294,   296,
     301,   298,   299,   300,   295,     0,   292,   286,   302,   285,
     415,   414,   273,   272,   257,   258,   255,   256,   254,     0,
     253,     0,     0,     0,   108,   109,   173,   170,   195,   206,
     182,   191,     0,   180,   185,     0,   200,     0,   194,   198,
     204,   184,   187,   196,   197,   201,   192,   199,   188,   205,
     190,   186,   189,     0,   178,   166,   168,   174,   171,   172,
     167,   169,   313,   311,   312,   351,   356,   362,   365,   358,
     364,   359,   363,   361,   357,   360,     0,   355,   137,     0,
       0,     0,     0,   132,   120,   119,   121,   122,   328,   334,
     340,   343,   336,   342,   337,   341,   339,   335,   338,     0,
     333,   329,   243,     0,    42,    43,    44,   397,     0,   290,
       0,   251,     0,   271,   268,   267,     0,     0,     0,     0,
       0,     0,     0,   176,     0,   353,     0,     0,     0,     0,
       0,   131,   331,     0,   244,   398,   291,   252,   181,   203,
     179,   207,   202,   193,   183,   177,   354,   138,   140,   139,
     149,   148,   144,   146,   150,   147,   143,   145,     0,   332,
     142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1002, -1002, -1002,  -443,  -329, -1001,  -670, -1002, -1002, -1002,
   -1002,   181, -1002, -1002,   925, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,   954, -1002, -1002, -1002, -1002, -1002,
   -1002,   620, -1002, -1002, -1002, -1002, -1002,   536, -1002, -1002,
   -1002, -1002, -1002, -1002,   928, -1002, -1002, -1002, -1002,   123,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,   618, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002,   -83, -1002, -1002, -1002,   833, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,   -58, -1002, -1002, -1002, -1002, -1002,   -66,
   -1002,   650, -1002, -1002, -1002,    26, -1002, -1002, -1002, -1002,
   -1002,   674, -1002, -1002, -1002, -1002, -1002, -1002, -1002,   -59,
   -1002, -1002, -1002, -1002,   617, -1002, -1002, -1002, -1002, -1002,
     935, -1002, -1002, -1002, -1002,   546, -1002, -1002, -1002, -1002,
   -1002,   -81, -1002, -1002, -1002,   577, -1002, -1002, -1002, -1002,
     -72, -1002, -1002, -1002,   776, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002,   -52, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002,   678, -1002, -1002, -1002,
   -1002, -1002,   783, -1002, -1002, -1002, -1002,  1049, -1002, -1002,
   -1002, -1002,   936, -1002, -1002, -1002, -1002,   992, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,  1077, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002,   939, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   863,   864,  1087,  1088,    28,    29,   248,
     524,   525,    30,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    31,    80,    81,    82,    83,    84,    32,    66,
     531,   532,   533,   534,    33,    73,   614,   615,   616,   617,
     618,   619,    34,   312,   313,   314,   315,   316,  1046,  1047,
    1048,  1049,  1050,  1201,  1278,    35,    67,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   786,
    1173,  1174,    36,    55,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   660,  1073,  1074,    37,    63,   516,   773,  1139,  1140,
     517,   518,   519,  1143,   991,   992,   520,   521,    38,    61,
     496,   497,   498,   499,   500,   501,   502,   760,  1125,  1126,
     503,    39,    68,   562,   563,   564,   565,   566,    40,   320,
     321,   322,    41,    75,   627,   628,   629,   630,   631,   848,
    1219,  1220,    42,    71,   600,   601,   602,   603,   831,  1196,
    1197,    43,    56,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   681,  1100,  1101,   411,   412,
     413,   414,   415,    44,    62,   507,   508,   509,   510,    45,
      57,   419,   420,   421,   422,    46,   129,   130,   131,    47,
      59,   429,   430,   431,   432,    48,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    49,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    50,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     896,   897,   638,  1098,   522,   253,   127,   416,   644,   645,
     646,  1248,   648,   649,   511,    53,    76,  1071,    54,   504,
      76,   318,   310,    58,   558,    60,  1222,  1084,  1085,  1086,
    1223,   609,   528,  1227,   558,    64,  1229,  1228,   247,   318,
    1230,  1231,   895,   900,   901,  1232,  1243,   426,   254,  1245,
    1244,   350,   416,  1246,    77,   426,    51,    52,    77,   255,
     256,   257,    78,    65,   258,   259,    78,   351,   352,   260,
     261,  1252,    69,   597,    70,  1253,   559,   127,    72,   353,
     512,   128,   417,  1224,  1225,  1226,   559,    74,   124,   513,
     133,   514,  1072,   310,   623,   134,   135,   125,   136,   137,
     126,   132,   244,   138,   245,   703,   246,   705,   706,   597,
     139,   140,   141,   142,   143,   144,   560,   715,   528,   523,
     145,   146,   147,   721,   529,   723,   560,   417,   354,   249,
     148,   149,   730,    79,   150,   151,   325,    79,   319,   737,
     738,   250,   740,   152,   251,  1042,   418,   623,   610,   355,
     356,   515,   128,   751,   752,   753,   319,   357,   505,   153,
     154,   358,   504,   561,   427,   535,   252,   309,   359,   317,
     323,   155,   427,   561,   156,   157,   360,   361,   362,   324,
     326,   526,   327,   536,   158,   159,   428,   363,  1042,  1099,
     598,   418,   160,   161,   428,   162,   330,   163,  -130,    85,
     272,   164,   165,   611,   331,   609,   332,   364,   530,   333,
     529,   624,   334,   166,   612,   537,   335,   336,   167,   337,
     168,   169,   170,   613,   338,   171,   598,   339,   340,   341,
     172,   342,    86,    87,   575,   273,   365,   506,   274,   311,
     804,    88,   538,   775,   895,   328,    89,    90,    91,   173,
     174,   606,   511,   175,   176,   177,   178,   179,   180,   181,
     842,   781,  1043,   800,   624,   489,   343,   275,   621,  -130,
      92,    93,    94,    95,   344,   383,   700,   384,   276,   385,
     672,   694,   539,   490,   345,    96,    97,    98,   599,   489,
     346,   182,   183,   386,   530,    99,   100,   101,   540,   102,
     103,   505,   184,   185,   277,  1043,   424,   490,   278,   625,
     311,   186,   626,   187,  1134,   491,   279,   280,   512,   487,
     281,   282,   610,   850,   599,   387,   347,   513,   423,   514,
     884,  1135,   433,   887,   434,   889,  1044,   435,   832,   491,
     894,   388,   492,   389,   436,   437,   438,   283,   632,   439,
     440,   441,   390,   442,  1136,   443,   444,   445,   912,   541,
    1045,   446,   625,  1116,   391,   626,   492,   447,   448,   449,
     542,   450,   451,   543,  1202,   633,   452,   611,   453,  1044,
     506,   454,   455,   544,   456,   457,   458,   545,   612,   515,
     459,   768,   392,   460,   794,   527,   461,   613,   493,   462,
    1117,   463,   464,  1045,   284,   465,   285,   286,   466,   287,
     288,   289,   393,  1061,  1062,  1063,  1064,  1065,  1066,  1067,
     535,   467,   493,   468,   469,   470,   494,   471,   348,   595,
     394,   133,  1118,   472,   473,   577,   134,   135,   536,   136,
     137,   474,   475,   476,   138,   477,   395,   478,   479,   480,
     494,   139,   140,   141,   142,   143,   144,   481,   482,   483,
     484,   145,   146,   147,   485,   486,   567,  1119,  1120,   568,
     537,   148,   149,  1121,   569,   150,   151,   570,   396,   571,
     397,   398,  1137,   495,   152,   572,   573,   574,  1138,   578,
     579,  1270,   580,  1271,   764,  1122,   581,   538,   582,  1148,
     153,   154,   583,   584,   690,   604,   585,   495,   586,   587,
     588,   589,   155,   590,   591,   156,   157,   592,   593,   608,
     594,   605,  1149,  1150,   620,   158,   159,   634,   635,   636,
    1249,   637,   639,   160,   161,  1151,   162,   539,   163,   640,
    1272,   641,   164,   165,   642,   272,   643,   647,  1123,   650,
     651,   652,   653,   540,   166,   654,  1273,   655,   656,   167,
     702,   168,   169,   170,   657,   658,   171,   659,   661,   707,
     662,   172,   663,   674,  1124,  1152,  1153,   664,  1154,   696,
     273,   665,   666,   274,   667,  1274,  1275,   668,   669,   670,
     173,   174,   671,   675,   175,   176,   177,   178,   179,   180,
     181,   676,   677,   678,   679,  1155,   383,   680,   384,  1156,
     385,   682,   275,   683,   541,   684,   685,   686,  1157,   687,
     688,   689,   692,   276,   386,   542,  1186,   693,   543,  1276,
     697,   698,   182,   183,   699,  1277,   704,  1158,   544,  1159,
     708,  1160,   545,   184,   185,   709,   710,   711,   712,   277,
     713,   714,   186,   278,   187,   716,   387,   717,  1161,   718,
     719,   279,   280,   720,   722,   281,   282,   724,   725,   726,
     727,  1162,   388,  1163,   389,   728,  1164,   734,  1165,   729,
     731,   732,  1166,   390,   735,  1167,   733,   736,   739,  1187,
     741,  1168,   283,  1169,  1170,   391,   856,   857,   858,   859,
     860,   861,   862,   742,   743,   744,     2,     3,   745,   746,
       4,   747,  1171,   748,  1188,   749,   750,  1209,   754,  1189,
    1172,   755,     5,   392,  1190,     6,   756,   757,   770,   777,
     253,   758,   759,   761,     7,  1141,   762,   763,   802,  1191,
     766,  1192,  1193,   393,     8,   805,   767,   771,   778,   284,
     350,   285,   286,   772,   287,   288,   289,   774,   779,     9,
    1194,   394,   780,   783,    10,    11,   351,   352,  1195,   784,
     785,   787,   788,   254,   803,   637,   789,   395,   353,   790,
    1210,   791,   792,    12,   255,   256,   257,    13,   793,   258,
     259,   796,   797,   806,   260,   261,   798,    14,    15,   799,
     808,   807,   809,   812,   810,  1211,   811,   813,   814,   396,
    1212,   397,   398,   815,   816,  1213,   817,   818,   819,   830,
     820,    16,    17,   821,   822,   823,   834,   354,   836,   824,
    1214,   825,  1215,  1216,   826,   827,    18,   903,   828,   829,
     835,   837,  1259,   845,   838,    85,   839,   840,   355,   356,
     841,  1217,    19,   844,   847,   849,   357,   846,   852,  1218,
     358,   853,   854,   882,    20,    21,   855,   359,   865,   866,
     867,   868,   869,   870,   871,   360,   361,   362,    86,    87,
      22,   872,   873,   874,   875,   876,   363,    88,    23,   877,
     878,    24,    89,    90,    91,    25,   879,    26,   880,   881,
     883,   886,   885,   888,   890,   898,   364,   891,   892,   893,
     895,   899,   902,   904,   905,   907,    92,    93,    94,    95,
     906,   908,   915,   909,   910,   911,   913,   914,   916,   917,
     920,    96,    97,    98,   918,   365,   919,   921,   922,   977,
     923,    99,   100,   101,   924,   102,   103,   925,   926,   927,
     928,   929,   930,   931,   932,   933,   934,   935,   994,   936,
     937,   938,   939,   940,   941,   942,   943,   944,   945,   946,
     947,   948,   949,   950,   951,   952,   953,   954,   978,   955,
     956,   957,   958,   959,   960,   961,   962,   963,   964,   965,
     966,   967,   968,   969,   970,   971,   972,   973,   974,   975,
     976,   980,   981,   979,   989,   982,   999,   984,   983,   985,
     986,   987,   988,  1005,   990,   995,   993,   996,   997,   998,
    1001,  1002,  1000,  1003,  1004,  1006,  1007,  1236,  1009,  1008,
    1010,  1011,  1261,  1039,   329,  1012,  1013,  1014,  1015,  1016,
    1017,  1262,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1040,  1051,  1041,  1052,  1053,  1054,  1058,
    1258,  1055,  1056,  1057,  1059,  1260,  1199,  1060,  1068,  1069,
    1070,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1102,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,  1127,  1128,  1129,  1130,  1131,  1132,  1133,
    1263,  1144,  1145,  1146,  1142,  1147,  1175,  1176,  1177,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1198,  1247,  1204,
    1200,  1205,  1206,  1207,  1208,  1221,  1233,  1264,  1235,  1237,
     843,   782,  1238,  1239,  1240,  1241,  1242,  1250,  1251,  1267,
    1268,  1265,  1269,  1280,   795,  1254,  1257,   776,  1234,  1203,
     765,  1256,  1279,   851,  1266,   691,  1255,   833,   425,   801,
     488,   349,     0,     0,     0,   769,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   673,
       0,   576,   695,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   596,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   622,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   701
};

static const yytype_int16 yycheck[] =
{
     670,   671,   331,     8,    30,     1,     1,     1,   337,   338,
     339,   197,   341,   342,     1,   234,     1,    64,   234,     1,
       1,     1,     1,   234,     1,   234,   229,    11,    12,    13,
     233,     1,     1,   229,     1,   227,   229,   233,   232,     1,
     233,   229,   228,   179,   180,   233,   229,     1,    44,   229,
     233,     1,     1,   233,    39,     1,   229,   230,    39,    55,
      56,    57,    47,   231,    60,    61,    47,    17,    18,    65,
      66,   229,   234,     1,   234,   233,    53,     1,   234,    29,
      67,    76,    76,  1084,  1085,  1086,    53,   234,   234,    76,
       1,    78,   139,     1,     1,     6,     7,   234,     9,    10,
     234,   234,   234,    14,   234,   434,   234,   436,   437,     1,
      21,    22,    23,    24,    25,    26,    93,   446,     1,   145,
      31,    32,    33,   452,    93,   454,    93,    76,    78,   227,
      41,    42,   461,   118,    45,    46,   231,   118,   118,   468,
     469,   234,   471,    54,   234,     1,   140,     1,   118,    99,
     100,   138,    76,   482,   483,   484,   118,   107,   140,    70,
      71,   111,     1,   140,   118,     1,   234,   234,   118,   234,
     234,    82,   118,   140,    85,    86,   126,   127,   128,   229,
     231,   229,   231,    19,    95,    96,   140,   137,     1,   194,
     118,   140,   103,   104,   140,   106,   231,   108,   177,     1,
       1,   112,   113,   173,   231,     1,   231,   157,   177,   231,
      93,   118,   231,   124,   184,    51,   231,   231,   129,   231,
     131,   132,   133,   193,   231,   136,   118,   231,   231,   231,
     141,   231,    34,    35,   230,    36,   186,   219,    39,   218,
     569,    43,    78,   230,   228,   230,    48,    49,    50,   160,
     161,   230,     1,   164,   165,   166,   167,   168,   169,   170,
     230,   230,   118,   230,   118,     1,   231,    68,   230,   177,
      72,    73,    74,    75,   231,     1,   230,     3,    79,     5,
     230,   230,   118,    19,   231,    87,    88,    89,   216,     1,
     231,   202,   203,    19,   177,    97,    98,    99,   134,   101,
     102,   140,   213,   214,   105,   118,   230,    19,   109,   216,
     218,   222,   219,   224,    20,    51,   117,   118,    67,   230,
     121,   122,   118,   230,   216,    51,   231,    76,   231,    78,
     659,    37,   231,   662,   231,   664,   192,   231,   230,    51,
     669,    67,    78,    69,   231,   231,   231,   148,   227,   231,
     231,   231,    78,   231,    60,   231,   231,   231,   687,   195,
     216,   231,   216,    15,    90,   219,    78,   231,   231,   231,
     206,   231,   231,   209,   230,   227,   231,   173,   231,   192,
     219,   231,   231,   219,   231,   231,   231,   223,   184,   138,
     231,   230,   118,   231,   230,   229,   231,   193,   134,   231,
      52,   231,   231,   216,   205,   231,   207,   208,   231,   210,
     211,   212,   138,   856,   857,   858,   859,   860,   861,   862,
       1,   231,   134,   231,   231,   231,   162,   231,   230,   230,
     156,     1,    84,   231,   231,   229,     6,     7,    19,     9,
      10,   231,   231,   231,    14,   231,   172,   231,   231,   231,
     162,    21,    22,    23,    24,    25,    26,   231,   231,   231,
     231,    31,    32,    33,   231,   231,   231,   119,   120,   231,
      51,    41,    42,   125,   231,    45,    46,   231,   204,   231,
     206,   207,   188,   219,    54,   231,   231,   231,   194,   231,
     231,    81,   231,    83,   230,   147,   231,    78,   231,     4,
      70,    71,   231,   231,   230,   229,   231,   219,   231,   231,
     231,   231,    82,   231,   231,    85,    86,   231,   231,   177,
     231,   231,    27,    28,   231,    95,    96,   227,   229,   228,
    1200,   228,   201,   103,   104,    40,   106,   118,   108,   201,
     130,   201,   112,   113,   201,     1,   228,   228,   200,   228,
     228,   228,   228,   134,   124,   228,   146,   229,   229,   129,
     201,   131,   132,   133,   231,   231,   136,   231,   231,   201,
     231,   141,   231,   229,   226,    80,    81,   231,    83,   227,
      36,   231,   231,    39,   231,   175,   176,   231,   231,   231,
     160,   161,   231,   231,   164,   165,   166,   167,   168,   169,
     170,   231,   231,   231,   231,   110,     1,   231,     3,   114,
       5,   231,    68,   231,   195,   231,   231,   231,   123,   231,
     231,   231,   231,    79,    19,   206,    83,   231,   209,   219,
     229,   231,   202,   203,   231,   225,   228,   142,   219,   144,
     228,   146,   223,   213,   214,   228,   228,   227,   227,   105,
     201,   228,   222,   109,   224,   201,    51,   201,   163,   228,
     228,   117,   118,   201,   201,   121,   122,   228,   228,   228,
     228,   176,    67,   178,    69,   228,   181,   201,   183,   228,
     228,   228,   187,    78,   227,   190,   228,   201,   201,   146,
     201,   196,   148,   198,   199,    90,   149,   150,   151,   152,
     153,   154,   155,   228,   201,   201,     0,     1,   201,   201,
       4,   201,   217,   201,   171,   201,   228,    83,   201,   176,
     225,   228,    16,   118,   181,    19,   229,   229,   229,   233,
       1,   231,   231,   231,    28,   215,   231,   231,   201,   196,
     231,   198,   199,   138,    38,   227,   231,   231,   229,   205,
       1,   207,   208,   231,   210,   211,   212,   231,   231,    53,
     217,   156,   231,   229,    58,    59,    17,    18,   225,   231,
     231,   231,   231,    44,   201,   228,   231,   172,    29,   231,
     146,   231,   231,    77,    55,    56,    57,    81,   231,    60,
      61,   229,   231,   201,    65,    66,   231,    91,    92,   231,
     201,   227,   201,   227,   229,   171,   228,   201,   227,   204,
     176,   206,   207,   228,   228,   181,   227,   227,   227,   231,
     227,   115,   116,   227,   227,   227,   201,    78,   234,   227,
     196,   227,   198,   199,   227,   227,   130,   201,   229,   229,
     229,   229,   146,   229,   231,     1,   231,   231,    99,   100,
     231,   217,   146,   227,   231,   231,   107,   229,   229,   225,
     111,   229,   229,   228,   158,   159,   229,   118,   229,   229,
     229,   229,   229,   229,   229,   126,   127,   128,    34,    35,
     174,   229,   229,   229,   229,   229,   137,    43,   182,   229,
     229,   185,    48,    49,    50,   189,   229,   191,   229,   229,
     228,   228,   231,   228,   227,   229,   157,   228,   228,   228,
     228,   227,   227,   227,   227,   227,    72,    73,    74,    75,
     231,   227,   229,   228,   227,   227,   227,   227,   227,   227,
     227,    87,    88,    89,   229,   186,   229,   227,   229,   227,
     229,    97,    98,    99,   229,   101,   102,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   777,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   201,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   227,   227,   231,   231,   227,   201,   227,   229,   227,
     229,   227,   227,   201,   228,   227,   229,   227,   229,   227,
     227,   227,   231,   227,   227,   227,   227,   232,   227,   229,
     227,   227,    94,   231,    80,   229,   229,   229,   229,   229,
     229,   146,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   227,   229,   227,   229,   227,   227,   227,   231,
     143,   229,   229,   227,   227,   143,   231,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     143,   229,   229,   229,   233,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   227,   229,
     231,   229,   229,   229,   229,   229,   228,   143,   229,   232,
     614,   531,   232,   232,   232,   232,   232,   231,   229,   229,
     229,  1244,   229,   229,   546,  1223,  1232,   517,  1142,  1046,
     496,  1230,  1253,   627,  1246,   399,  1228,   600,   129,   562,
     188,   104,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,
      -1,   262,   419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   290,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   320,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   429
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   236,     0,     1,     4,    16,    19,    28,    38,    53,
      58,    59,    77,    81,    91,    92,   115,   116,   130,   146,
     158,   159,   174,   182,   185,   189,   191,   237,   242,   243,
     247,   267,   273,   279,   287,   300,   317,   339,   353,   366,
     373,   377,   387,   396,   418,   424,   430,   434,   440,   497,
     518,   229,   230,   234,   234,   318,   397,   425,   234,   435,
     234,   354,   419,   340,   227,   231,   274,   301,   367,   234,
     234,   388,   234,   280,   234,   378,     1,    39,    47,   118,
     268,   269,   270,   271,   272,     1,    34,    35,    43,    48,
      49,    50,    72,    73,    74,    75,    87,    88,    89,    97,
      98,    99,   101,   102,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   234,   234,   234,     1,    76,   431,
     432,   433,   234,     1,     6,     7,     9,    10,    14,    21,
      22,    23,    24,    25,    26,    31,    32,    33,    41,    42,
      45,    46,    54,    70,    71,    82,    85,    86,    95,    96,
     103,   104,   106,   108,   112,   113,   124,   129,   131,   132,
     133,   136,   141,   160,   161,   164,   165,   166,   167,   168,
     169,   170,   202,   203,   213,   214,   222,   224,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   234,   234,   234,   232,   244,   227,
     234,   234,   234,     1,    44,    55,    56,    57,    60,    61,
      65,    66,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,     1,    36,    39,    68,    79,   105,   109,   117,
     118,   121,   122,   148,   205,   207,   208,   210,   211,   212,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   234,
       1,   218,   288,   289,   290,   291,   292,   234,     1,   118,
     374,   375,   376,   234,   229,   231,   231,   231,   230,   269,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   230,   499,
       1,    17,    18,    29,    78,    99,   100,   107,   111,   118,
     126,   127,   128,   137,   157,   186,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,     1,     3,     5,    19,    51,    67,    69,
      78,    90,   118,   138,   156,   172,   204,   206,   207,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   413,   414,   415,   416,   417,     1,    76,   140,   426,
     427,   428,   429,   231,   230,   432,     1,   118,   140,   436,
     437,   438,   439,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   230,   442,     1,
      19,    51,    78,   134,   162,   219,   355,   356,   357,   358,
     359,   360,   361,   365,     1,   140,   219,   420,   421,   422,
     423,     1,    67,    76,    78,   138,   341,   345,   346,   347,
     351,   352,    30,   145,   245,   246,   229,   229,     1,    93,
     177,   275,   276,   277,   278,     1,    19,    51,    78,   118,
     134,   195,   206,   209,   219,   223,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,     1,    53,
      93,   140,   368,   369,   370,   371,   372,   231,   231,   231,
     231,   231,   231,   231,   231,   230,   520,   229,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   230,   249,     1,   118,   216,
     389,   390,   391,   392,   229,   231,   230,   289,   177,     1,
     118,   173,   184,   193,   281,   282,   283,   284,   285,   286,
     231,   230,   375,     1,   118,   216,   219,   379,   380,   381,
     382,   383,   227,   227,   227,   229,   228,   228,   239,   201,
     201,   201,   201,   228,   239,   239,   239,   228,   239,   239,
     228,   228,   228,   228,   228,   229,   229,   231,   231,   231,
     336,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   230,   320,   229,   231,   231,   231,   231,   231,
     231,   410,   231,   231,   231,   231,   231,   231,   231,   231,
     230,   399,   231,   231,   230,   427,   227,   229,   231,   231,
     230,   437,   201,   239,   228,   239,   239,   201,   228,   228,
     228,   227,   227,   201,   228,   239,   201,   201,   228,   228,
     201,   239,   201,   239,   228,   228,   228,   228,   228,   228,
     239,   228,   228,   228,   201,   227,   201,   239,   239,   201,
     239,   201,   228,   201,   201,   201,   201,   201,   201,   201,
     228,   239,   239,   239,   201,   228,   229,   229,   231,   231,
     362,   231,   231,   231,   230,   356,   231,   231,   230,   421,
     229,   231,   231,   342,   231,   230,   346,   233,   229,   231,
     231,   230,   276,   229,   231,   231,   314,   231,   231,   231,
     231,   231,   231,   231,   230,   303,   229,   231,   231,   231,
     230,   369,   201,   201,   239,   227,   201,   227,   201,   201,
     229,   228,   227,   201,   227,   228,   228,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   229,   229,
     231,   393,   230,   390,   201,   229,   234,   229,   231,   231,
     231,   231,   230,   282,   227,   229,   229,   231,   384,   231,
     230,   380,   229,   229,   229,   229,   149,   150,   151,   152,
     153,   154,   155,   238,   239,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   228,   228,   239,   231,   228,   239,   228,   239,
     227,   228,   228,   228,   239,   228,   241,   241,   229,   227,
     179,   180,   227,   201,   227,   227,   231,   227,   227,   228,
     227,   227,   239,   227,   227,   229,   227,   227,   229,   229,
     227,   227,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   227,   201,   231,
     227,   227,   227,   229,   227,   227,   229,   227,   227,   231,
     228,   349,   350,   229,   246,   227,   227,   229,   227,   201,
     231,   227,   227,   227,   227,   201,   227,   227,   229,   227,
     227,   227,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   227,   231,
     229,   229,     1,   118,   192,   216,   293,   294,   295,   296,
     297,   227,   227,   227,   227,   229,   229,   227,   231,   227,
     229,   238,   238,   238,   238,   238,   238,   238,   229,   229,
     229,    64,   139,   337,   338,   229,   229,   229,   229,   229,
     229,   229,   229,   229,    11,    12,    13,   240,   241,   229,
     229,   229,   229,   229,   229,   229,   229,   229,     8,   194,
     411,   412,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,    15,    52,    84,   119,
     120,   125,   147,   200,   226,   363,   364,   229,   229,   229,
     229,   229,   229,   229,    20,    37,    60,   188,   194,   343,
     344,   215,   233,   348,   229,   229,   229,   229,     4,    27,
      28,    40,    80,    81,    83,   110,   114,   123,   142,   144,
     146,   163,   176,   178,   181,   183,   187,   190,   196,   198,
     199,   217,   225,   315,   316,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,    83,   146,   171,   176,
     181,   196,   198,   199,   217,   225,   394,   395,   229,   231,
     231,   298,   230,   294,   229,   229,   229,   229,   229,    83,
     146,   171,   176,   181,   196,   198,   199,   217,   225,   385,
     386,   229,   229,   233,   240,   240,   240,   229,   233,   229,
     233,   229,   233,   228,   350,   229,   232,   232,   232,   232,
     232,   232,   232,   229,   233,   229,   233,   227,   197,   241,
     231,   229,   229,   233,   338,   412,   364,   344,   143,   146,
     143,    94,   146,   143,   143,   316,   395,   229,   229,   229,
      81,    83,   130,   146,   175,   176,   219,   225,   299,   386,
     229
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   235,   236,   236,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   238,
     238,   239,   239,   239,   239,   239,   239,   239,   239,   240,
     240,   241,   241,   241,   241,   242,   243,   244,   244,   245,
     245,   246,   246,   247,   248,   248,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   268,   269,   269,   269,   269,   270,   271,
     272,   274,   273,   275,   275,   276,   276,   276,   277,   278,
     280,   279,   281,   281,   282,   282,   282,   282,   282,   283,
     284,   285,   286,   287,   288,   288,   289,   289,   289,   290,
     292,   291,   293,   293,   294,   294,   294,   294,   295,   296,
     296,   298,   297,   299,   299,   299,   299,   299,   299,   299,
     299,   301,   300,   302,   302,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   314,   313,   315,   315,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   318,   317,
     319,   319,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   336,   335,   337,   337,   338,   338,   340,   339,
     342,   341,   343,   343,   344,   344,   344,   344,   344,   345,
     345,   346,   346,   346,   346,   346,   348,   347,   349,   349,
     350,   350,   351,   352,   354,   353,   355,   355,   356,   356,
     356,   356,   356,   356,   356,   357,   358,   359,   360,   362,
     361,   363,   363,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   365,   367,   366,   368,   368,   369,   369,   369,
     369,   370,   371,   372,   373,   374,   374,   375,   375,   376,
     378,   377,   379,   379,   380,   380,   380,   380,   381,   382,
     384,   383,   385,   385,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   388,   387,   389,   389,   390,   390,
     390,   391,   393,   392,   394,   394,   395,   395,   395,   395,
     395,   395,   395,   395,   395,   395,   397,   396,   398,   398,
     399,   399,   399,   399,   399,   399,   399,   399,   399,   399,
     399,   399,   399,   399,   399,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   408,   410,   409,   411,   411,
     412,   412,   413,   414,   415,   416,   417,   419,   418,   420,
     420,   421,   421,   421,   422,   423,   425,   424,   426,   426,
     427,   427,   427,   428,   429,   430,   431,   431,   432,   432,
     433,   435,   434,   436,   436,   437,   437,   437,   438,   439,
     440,   441,   441,   442,   442,   442,   442,   442,   442,   442,
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
     495,   496,   497,   498,   498,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   519,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   521,   522,   523,   524,   525,   526,
     527,   528
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
       1,     1,     1,     1,     2,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     6,     2,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
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
#line 393 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3533 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 394 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3539 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 395 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3545 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 396 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3551 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 397 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3557 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 398 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3563 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3569 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3575 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3581 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 404 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3587 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 405 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3593 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 406 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3599 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 407 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3605 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 408 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3611 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 416 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3620 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 426 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3629 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 432 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3637 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 439 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3646 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 443 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3655 "conf_parser.c"
    break;

  case 74: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 476 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3667 "conf_parser.c"
    break;

  case 75: /* serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 485 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = io_strdup(yylval.string);
  }
}
#line 3679 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_dh_param_file: TLS_DH_PARAM_FILE '=' QSTRING ';'  */
#line 494 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = io_strdup(yylval.string);
  }
}
#line 3691 "conf_parser.c"
    break;

  case 77: /* serverinfo_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 503 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = io_strdup(yylval.string);
  }
}
#line 3703 "conf_parser.c"
    break;

  case 78: /* serverinfo_tls_cipher_suites: TLS_CIPHER_SUITES '=' QSTRING ';'  */
#line 512 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = io_strdup(yylval.string);
  }
}
#line 3715 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_message_digest_algorithm: TLS_MESSAGE_DIGEST_ALGORITHM '=' QSTRING ';'  */
#line 521 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = io_strdup(yylval.string);
  }
}
#line 3727 "conf_parser.c"
    break;

  case 80: /* serverinfo_tls_supported_groups: TLS_SUPPORTED_GROUPS '=' QSTRING ';'  */
#line 530 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = io_strdup(yylval.string);
  }
}
#line 3739 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 539 "conf_parser.y"
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
#line 3757 "conf_parser.c"
    break;

  case 82: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 554 "conf_parser.y"
{
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && ConfigServerInfo.sid == NULL)
  {
    if (client_id_is_valid_sid(yylval.string))
      ConfigServerInfo.sid = io_strdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3775 "conf_parser.c"
    break;

  case 83: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 569 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3788 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 579 "conf_parser.y"
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
#line 3805 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 593 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3817 "conf_parser.c"
    break;

  case 86: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 602 "conf_parser.y"
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
#line 3843 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 625 "conf_parser.y"
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
#line 3869 "conf_parser.c"
    break;

  case 88: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 648 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigServerInfo.max_topic_length = TOPICLEN;
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3880 "conf_parser.c"
    break;

  case 89: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 656 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3892 "conf_parser.c"
    break;

  case 90: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 665 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3901 "conf_parser.c"
    break;

  case 98: /* admin_name: NAME '=' QSTRING ';'  */
#line 683 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3913 "conf_parser.c"
    break;

  case 99: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 692 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3925 "conf_parser.c"
    break;

  case 100: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 701 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3937 "conf_parser.c"
    break;

  case 101: /* $@1: %empty  */
#line 714 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3946 "conf_parser.c"
    break;

  case 102: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 718 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3963 "conf_parser.c"
    break;

  case 108: /* motd_mask: MASK '=' QSTRING ';'  */
#line 735 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3972 "conf_parser.c"
    break;

  case 109: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 741 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3981 "conf_parser.c"
    break;

  case 110: /* $@2: %empty  */
#line 751 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3990 "conf_parser.c"
    break;

  case 111: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 755 "conf_parser.y"
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
#line 4008 "conf_parser.c"
    break;

  case 119: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 773 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 4017 "conf_parser.c"
    break;

  case 120: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 779 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4026 "conf_parser.c"
    break;

  case 121: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 785 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 4035 "conf_parser.c"
    break;

  case 122: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 791 "conf_parser.y"
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
#line 4057 "conf_parser.c"
    break;

  case 129: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 820 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 4069 "conf_parser.c"
    break;

  case 130: /* $@3: %empty  */
#line 829 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4078 "conf_parser.c"
    break;

  case 131: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 833 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 4091 "conf_parser.c"
    break;

  case 138: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 849 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 4102 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 857 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 4110 "conf_parser.c"
    break;

  case 140: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 860 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 4118 "conf_parser.c"
    break;

  case 141: /* $@4: %empty  */
#line 865 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 4127 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: USER  */
#line 871 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4136 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: OPERATOR  */
#line 875 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4145 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: XLINE  */
#line 879 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4154 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: RESV  */
#line 883 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4163 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: T_DLINE  */
#line 887 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4172 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KLINE  */
#line 891 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4181 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: KILL  */
#line 895 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4190 "conf_parser.c"
    break;

  case 150: /* logging_file_type_item: T_DEBUG  */
#line 899 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4199 "conf_parser.c"
    break;

  case 151: /* $@5: %empty  */
#line 909 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4211 "conf_parser.c"
    break;

  case 152: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 916 "conf_parser.y"
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
#line 4269 "conf_parser.c"
    break;

  case 166: /* oper_name: NAME '=' QSTRING ';'  */
#line 984 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4278 "conf_parser.c"
    break;

  case 167: /* oper_user: USER '=' QSTRING ';'  */
#line 990 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4287 "conf_parser.c"
    break;

  case 168: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 996 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4296 "conf_parser.c"
    break;

  case 169: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1002 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4305 "conf_parser.c"
    break;

  case 170: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1008 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4319 "conf_parser.c"
    break;

  case 171: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1019 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4328 "conf_parser.c"
    break;

  case 172: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1025 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4342 "conf_parser.c"
    break;

  case 173: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1036 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4351 "conf_parser.c"
    break;

  case 174: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1042 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4360 "conf_parser.c"
    break;

  case 175: /* $@6: %empty  */
#line 1048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4369 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: KILL ':' REMOTE  */
#line 1055 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4378 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: KILL  */
#line 1059 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4387 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1063 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4396 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: CONNECT  */
#line 1067 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4405 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1071 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4414 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: SQUIT  */
#line 1075 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4423 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: KLINE  */
#line 1079 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4432 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: UNKLINE  */
#line 1083 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4441 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_DLINE  */
#line 1087 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4450 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: T_UNDLINE  */
#line 1091 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4459 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: XLINE  */
#line 1095 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4468 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: T_UNXLINE  */
#line 1099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4477 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: DIE  */
#line 1103 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4486 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: T_RESTART  */
#line 1107 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4495 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1111 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4504 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: REHASH  */
#line 1115 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4513 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: ADMIN  */
#line 1119 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4522 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_GLOBOPS  */
#line 1123 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4531 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: T_LOCOPS  */
#line 1127 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4540 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: REMOTEBAN  */
#line 1131 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4549 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: T_SET  */
#line 1135 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4558 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: MODULE  */
#line 1139 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4567 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: T_OPME  */
#line 1143 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4576 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: NICK ':' RESV  */
#line 1147 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4585 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: JOIN ':' RESV  */
#line 1151 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4594 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: RESV  */
#line 1155 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4603 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: T_UNRESV  */
#line 1159 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4612 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: CLOSE  */
#line 1163 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4621 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1167 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4630 "conf_parser.c"
    break;

  case 208: /* $@7: %empty  */
#line 1177 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.con_freq.value  = CLASS_DEFAULT_CONNECT_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4646 "conf_parser.c"
    break;

  case 209: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1188 "conf_parser.y"
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
#line 4694 "conf_parser.c"
    break;

  case 228: /* class_name: NAME '=' QSTRING ';'  */
#line 1251 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4703 "conf_parser.c"
    break;

  case 229: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1257 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4712 "conf_parser.c"
    break;

  case 230: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1263 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4721 "conf_parser.c"
    break;

  case 231: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1269 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4730 "conf_parser.c"
    break;

  case 232: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1275 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4739 "conf_parser.c"
    break;

  case 233: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1281 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4748 "conf_parser.c"
    break;

  case 234: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1287 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4757 "conf_parser.c"
    break;

  case 235: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1293 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4766 "conf_parser.c"
    break;

  case 236: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1299 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4776 "conf_parser.c"
    break;

  case 237: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1306 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4785 "conf_parser.c"
    break;

  case 238: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1312 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4794 "conf_parser.c"
    break;

  case 239: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1318 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4803 "conf_parser.c"
    break;

  case 240: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1324 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4815 "conf_parser.c"
    break;

  case 241: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1333 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4827 "conf_parser.c"
    break;

  case 242: /* $@8: %empty  */
#line 1342 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4836 "conf_parser.c"
    break;

  case 246: /* class_flags_item: RANDOM_IDLE  */
#line 1349 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4845 "conf_parser.c"
    break;

  case 247: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1353 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4854 "conf_parser.c"
    break;

  case 248: /* $@9: %empty  */
#line 1363 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4863 "conf_parser.c"
    break;

  case 250: /* $@10: %empty  */
#line 1369 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4871 "conf_parser.c"
    break;

  case 254: /* listen_flags_item: T_TLS  */
#line 1375 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4880 "conf_parser.c"
    break;

  case 255: /* listen_flags_item: HIDDEN  */
#line 1379 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4889 "conf_parser.c"
    break;

  case 256: /* listen_flags_item: T_SERVER  */
#line 1383 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4898 "conf_parser.c"
    break;

  case 257: /* listen_flags_item: CLIENT  */
#line 1387 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4907 "conf_parser.c"
    break;

  case 258: /* listen_flags_item: DEFER  */
#line 1391 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4916 "conf_parser.c"
    break;

  case 266: /* $@11: %empty  */
#line 1399 "conf_parser.y"
                                 { reset_block_state(); }
#line 4922 "conf_parser.c"
    break;

  case 270: /* port_item: NUMBER  */
#line 1404 "conf_parser.y"
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
#line 4940 "conf_parser.c"
    break;

  case 271: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1417 "conf_parser.y"
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
#line 4960 "conf_parser.c"
    break;

  case 272: /* listen_address: IP '=' QSTRING ';'  */
#line 1434 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4969 "conf_parser.c"
    break;

  case 273: /* listen_host: HOST '=' QSTRING ';'  */
#line 1440 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4978 "conf_parser.c"
    break;

  case 274: /* $@12: %empty  */
#line 1450 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4987 "conf_parser.c"
    break;

  case 275: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1454 "conf_parser.y"
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
#line 5034 "conf_parser.c"
    break;

  case 285: /* auth_user: USER '=' QSTRING ';'  */
#line 1507 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5043 "conf_parser.c"
    break;

  case 286: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1513 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5052 "conf_parser.c"
    break;

  case 287: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1519 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5061 "conf_parser.c"
    break;

  case 288: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1525 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5075 "conf_parser.c"
    break;

  case 289: /* $@13: %empty  */
#line 1536 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 5084 "conf_parser.c"
    break;

  case 293: /* auth_flags_item: EXCEED_LIMIT  */
#line 1543 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 5093 "conf_parser.c"
    break;

  case 294: /* auth_flags_item: KLINE_EXEMPT  */
#line 1547 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 5102 "conf_parser.c"
    break;

  case 295: /* auth_flags_item: XLINE_EXEMPT  */
#line 1551 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 5111 "conf_parser.c"
    break;

  case 296: /* auth_flags_item: NEED_IDENT  */
#line 1555 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 5120 "conf_parser.c"
    break;

  case 297: /* auth_flags_item: CAN_FLOOD  */
#line 1559 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 5129 "conf_parser.c"
    break;

  case 298: /* auth_flags_item: NO_TILDE  */
#line 1563 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 5138 "conf_parser.c"
    break;

  case 299: /* auth_flags_item: RESV_EXEMPT  */
#line 1567 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 5147 "conf_parser.c"
    break;

  case 300: /* auth_flags_item: T_WEBIRC  */
#line 1571 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 5156 "conf_parser.c"
    break;

  case 301: /* auth_flags_item: NEED_PASSWORD  */
#line 1575 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 5165 "conf_parser.c"
    break;

  case 302: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1581 "conf_parser.y"
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
#line 5182 "conf_parser.c"
    break;

  case 303: /* $@14: %empty  */
#line 1599 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5194 "conf_parser.c"
    break;

  case 304: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1606 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5205 "conf_parser.c"
    break;

  case 311: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1617 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5214 "conf_parser.c"
    break;

  case 312: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1623 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5223 "conf_parser.c"
    break;

  case 313: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1629 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5232 "conf_parser.c"
    break;

  case 319: /* service_name: NAME '=' QSTRING ';'  */
#line 1644 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5247 "conf_parser.c"
    break;

  case 320: /* $@15: %empty  */
#line 1660 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5263 "conf_parser.c"
    break;

  case 321: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1671 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5278 "conf_parser.c"
    break;

  case 328: /* shared_name: NAME '=' QSTRING ';'  */
#line 1686 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5287 "conf_parser.c"
    break;

  case 329: /* shared_user: USER '=' QSTRING ';'  */
#line 1692 "conf_parser.y"
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
#line 5309 "conf_parser.c"
    break;

  case 330: /* $@16: %empty  */
#line 1711 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5318 "conf_parser.c"
    break;

  case 334: /* shared_type_item: KLINE  */
#line 1718 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5327 "conf_parser.c"
    break;

  case 335: /* shared_type_item: UNKLINE  */
#line 1722 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5336 "conf_parser.c"
    break;

  case 336: /* shared_type_item: T_DLINE  */
#line 1726 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5345 "conf_parser.c"
    break;

  case 337: /* shared_type_item: T_UNDLINE  */
#line 1730 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5354 "conf_parser.c"
    break;

  case 338: /* shared_type_item: XLINE  */
#line 1734 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5363 "conf_parser.c"
    break;

  case 339: /* shared_type_item: T_UNXLINE  */
#line 1738 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5372 "conf_parser.c"
    break;

  case 340: /* shared_type_item: RESV  */
#line 1742 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5381 "conf_parser.c"
    break;

  case 341: /* shared_type_item: T_UNRESV  */
#line 1746 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5390 "conf_parser.c"
    break;

  case 342: /* shared_type_item: T_LOCOPS  */
#line 1750 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5399 "conf_parser.c"
    break;

  case 343: /* shared_type_item: T_ALL  */
#line 1754 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5408 "conf_parser.c"
    break;

  case 344: /* $@17: %empty  */
#line 1764 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5422 "conf_parser.c"
    break;

  case 345: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1773 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5435 "conf_parser.c"
    break;

  case 351: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1786 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5444 "conf_parser.c"
    break;

  case 352: /* $@18: %empty  */
#line 1792 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5453 "conf_parser.c"
    break;

  case 356: /* cluster_type_item: KLINE  */
#line 1799 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5462 "conf_parser.c"
    break;

  case 357: /* cluster_type_item: UNKLINE  */
#line 1803 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5471 "conf_parser.c"
    break;

  case 358: /* cluster_type_item: T_DLINE  */
#line 1807 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5480 "conf_parser.c"
    break;

  case 359: /* cluster_type_item: T_UNDLINE  */
#line 1811 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5489 "conf_parser.c"
    break;

  case 360: /* cluster_type_item: XLINE  */
#line 1815 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5498 "conf_parser.c"
    break;

  case 361: /* cluster_type_item: T_UNXLINE  */
#line 1819 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5507 "conf_parser.c"
    break;

  case 362: /* cluster_type_item: RESV  */
#line 1823 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5516 "conf_parser.c"
    break;

  case 363: /* cluster_type_item: T_UNRESV  */
#line 1827 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5525 "conf_parser.c"
    break;

  case 364: /* cluster_type_item: T_LOCOPS  */
#line 1831 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5534 "conf_parser.c"
    break;

  case 365: /* cluster_type_item: T_ALL  */
#line 1835 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5543 "conf_parser.c"
    break;

  case 366: /* $@19: %empty  */
#line 1845 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5557 "conf_parser.c"
    break;

  case 367: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1854 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0] ||
      !block_state.host.buf[0])
    break;

  if (!block_state.rpass.buf[0] ||
      !block_state.spass.buf[0])
    break;

  if (!server_is_valid_name(block_state.name.buf))
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
    if (!address_from_string(block_state.bind.buf, &connect->bind_addr))
      conf_error_report("Invalid IP address for bind address");

  connect_assign_class(connect, block_state.klass.buf);
  connect_dns_lookup(connect);
}
#line 5608 "conf_parser.c"
    break;

  case 386: /* connect_name: NAME '=' QSTRING ';'  */
#line 1920 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5617 "conf_parser.c"
    break;

  case 387: /* connect_host: HOST '=' QSTRING ';'  */
#line 1926 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5626 "conf_parser.c"
    break;

  case 388: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1932 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5635 "conf_parser.c"
    break;

  case 389: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1938 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5644 "conf_parser.c"
    break;

  case 390: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1944 "conf_parser.y"
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
#line 5660 "conf_parser.c"
    break;

  case 391: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1957 "conf_parser.y"
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
#line 5676 "conf_parser.c"
    break;

  case 392: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1970 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5685 "conf_parser.c"
    break;

  case 393: /* connect_port: PORT '=' NUMBER ';'  */
#line 1976 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5694 "conf_parser.c"
    break;

  case 394: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 1982 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5703 "conf_parser.c"
    break;

  case 395: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 1986 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5712 "conf_parser.c"
    break;

  case 396: /* $@20: %empty  */
#line 1992 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5720 "conf_parser.c"
    break;

  case 400: /* connect_flags_item: AUTOCONN  */
#line 1998 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5729 "conf_parser.c"
    break;

  case 401: /* connect_flags_item: T_TLS  */
#line 2002 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5738 "conf_parser.c"
    break;

  case 402: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2008 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5752 "conf_parser.c"
    break;

  case 403: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2019 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5761 "conf_parser.c"
    break;

  case 404: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2025 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5770 "conf_parser.c"
    break;

  case 405: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2031 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5779 "conf_parser.c"
    break;

  case 406: /* connect_tls_cipher_list: TLS_CIPHER_LIST '=' QSTRING ';'  */
#line 2037 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5793 "conf_parser.c"
    break;

  case 407: /* $@21: %empty  */
#line 2052 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5802 "conf_parser.c"
    break;

  case 408: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2056 "conf_parser.y"
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
#line 5825 "conf_parser.c"
    break;

  case 414: /* kill_user: USER '=' QSTRING ';'  */
#line 2079 "conf_parser.y"
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
#line 5848 "conf_parser.c"
    break;

  case 415: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5857 "conf_parser.c"
    break;

  case 416: /* $@22: %empty  */
#line 2109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5866 "conf_parser.c"
    break;

  case 417: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2113 "conf_parser.y"
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
#line 5890 "conf_parser.c"
    break;

  case 423: /* deny_ip: IP '=' QSTRING ';'  */
#line 2137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5899 "conf_parser.c"
    break;

  case 424: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2143 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5908 "conf_parser.c"
    break;

  case 430: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2158 "conf_parser.y"
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
#line 5925 "conf_parser.c"
    break;

  case 431: /* $@23: %empty  */
#line 2176 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5934 "conf_parser.c"
    break;

  case 432: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2180 "conf_parser.y"
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
#line 5954 "conf_parser.c"
    break;

  case 438: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2200 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5963 "conf_parser.c"
    break;

  case 439: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2206 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5972 "conf_parser.c"
    break;

  case 498: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2276 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5980 "conf_parser.c"
    break;

  case 499: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2281 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5988 "conf_parser.c"
    break;

  case 500: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2286 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5996 "conf_parser.c"
    break;

  case 501: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2291 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 6004 "conf_parser.c"
    break;

  case 502: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2296 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 6012 "conf_parser.c"
    break;

  case 503: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2301 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 6020 "conf_parser.c"
    break;

  case 504: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2306 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 6028 "conf_parser.c"
    break;

  case 505: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2311 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6036 "conf_parser.c"
    break;

  case 506: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2316 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6044 "conf_parser.c"
    break;

  case 507: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2321 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6052 "conf_parser.c"
    break;

  case 508: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2326 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 6060 "conf_parser.c"
    break;

  case 509: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2331 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 6068 "conf_parser.c"
    break;

  case 510: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2336 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6076 "conf_parser.c"
    break;

  case 511: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2341 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6084 "conf_parser.c"
    break;

  case 512: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2346 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6092 "conf_parser.c"
    break;

  case 513: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2351 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 6103 "conf_parser.c"
    break;

  case 514: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2359 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6111 "conf_parser.c"
    break;

  case 515: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2364 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6119 "conf_parser.c"
    break;

  case 516: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2369 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6127 "conf_parser.c"
    break;

  case 517: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2374 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6135 "conf_parser.c"
    break;

  case 518: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2379 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6143 "conf_parser.c"
    break;

  case 519: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2384 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6151 "conf_parser.c"
    break;

  case 520: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2389 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 6159 "conf_parser.c"
    break;

  case 521: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2394 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 6167 "conf_parser.c"
    break;

  case 522: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2399 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 6175 "conf_parser.c"
    break;

  case 523: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2404 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6183 "conf_parser.c"
    break;

  case 524: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2409 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 6191 "conf_parser.c"
    break;

  case 525: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2414 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 6199 "conf_parser.c"
    break;

  case 526: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2419 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6207 "conf_parser.c"
    break;

  case 527: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2424 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6215 "conf_parser.c"
    break;

  case 528: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2429 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6223 "conf_parser.c"
    break;

  case 529: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2434 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6231 "conf_parser.c"
    break;

  case 530: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2439 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6239 "conf_parser.c"
    break;

  case 531: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2444 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6247 "conf_parser.c"
    break;

  case 532: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2449 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6255 "conf_parser.c"
    break;

  case 533: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2454 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6263 "conf_parser.c"
    break;

  case 534: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2459 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6271 "conf_parser.c"
    break;

  case 535: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2464 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6279 "conf_parser.c"
    break;

  case 536: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2469 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6287 "conf_parser.c"
    break;

  case 537: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2474 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6295 "conf_parser.c"
    break;

  case 538: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2479 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6303 "conf_parser.c"
    break;

  case 539: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2484 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6315 "conf_parser.c"
    break;

  case 540: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2493 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6323 "conf_parser.c"
    break;

  case 541: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2498 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6331 "conf_parser.c"
    break;

  case 542: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2503 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6339 "conf_parser.c"
    break;

  case 543: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2508 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6347 "conf_parser.c"
    break;

  case 544: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2513 "conf_parser.y"
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
#line 6367 "conf_parser.c"
    break;

  case 545: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2530 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6378 "conf_parser.c"
    break;

  case 546: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2538 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6389 "conf_parser.c"
    break;

  case 547: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2546 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6400 "conf_parser.c"
    break;

  case 548: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2554 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6413 "conf_parser.c"
    break;

  case 549: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2564 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6426 "conf_parser.c"
    break;

  case 550: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2574 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6437 "conf_parser.c"
    break;

  case 551: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2582 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6445 "conf_parser.c"
    break;

  case 574: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2614 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6453 "conf_parser.c"
    break;

  case 575: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2619 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6462 "conf_parser.c"
    break;

  case 576: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2625 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6471 "conf_parser.c"
    break;

  case 577: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2631 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6479 "conf_parser.c"
    break;

  case 578: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2636 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6487 "conf_parser.c"
    break;

  case 579: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2641 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6495 "conf_parser.c"
    break;

  case 580: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2646 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6503 "conf_parser.c"
    break;

  case 581: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2651 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6511 "conf_parser.c"
    break;

  case 582: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2656 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6519 "conf_parser.c"
    break;

  case 583: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2661 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6527 "conf_parser.c"
    break;

  case 584: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2666 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6535 "conf_parser.c"
    break;

  case 585: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2671 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6543 "conf_parser.c"
    break;

  case 586: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2676 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6551 "conf_parser.c"
    break;

  case 587: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2681 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6559 "conf_parser.c"
    break;

  case 588: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2686 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6567 "conf_parser.c"
    break;

  case 589: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2691 "conf_parser.y"
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
#line 6593 "conf_parser.c"
    break;

  case 590: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2714 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6601 "conf_parser.c"
    break;

  case 591: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2719 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6609 "conf_parser.c"
    break;

  case 604: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2741 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6618 "conf_parser.c"
    break;

  case 605: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2747 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6632 "conf_parser.c"
    break;

  case 606: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2758 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6644 "conf_parser.c"
    break;

  case 607: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6653 "conf_parser.c"
    break;

  case 608: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2773 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6662 "conf_parser.c"
    break;

  case 609: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2779 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6671 "conf_parser.c"
    break;

  case 610: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2785 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6683 "conf_parser.c"
    break;

  case 611: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2794 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6692 "conf_parser.c"
    break;


#line 6696 "conf_parser.c"

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

