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
#line 12 "conf_parser.y"

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


#line 188 "conf_parser.c"

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
    T_COMMAND = 427,               /* T_COMMAND  */
    T_CLUSTER = 428,               /* T_CLUSTER  */
    T_DEBUG = 429,                 /* T_DEBUG  */
    T_DLINE = 430,                 /* T_DLINE  */
    T_FILE = 431,                  /* T_FILE  */
    T_GLOBOPS = 432,               /* T_GLOBOPS  */
    T_IPV4 = 433,                  /* T_IPV4  */
    T_IPV6 = 434,                  /* T_IPV6  */
    T_LOCOPS = 435,                /* T_LOCOPS  */
    T_LOG = 436,                   /* T_LOG  */
    T_OPME = 437,                  /* T_OPME  */
    T_PREPEND = 438,               /* T_PREPEND  */
    T_PSEUDO = 439,                /* T_PSEUDO  */
    T_RECVQ = 440,                 /* T_RECVQ  */
    T_RESTART = 441,               /* T_RESTART  */
    T_SERVER = 442,                /* T_SERVER  */
    T_SERVICE = 443,               /* T_SERVICE  */
    T_SET = 444,                   /* T_SET  */
    T_SHARED = 445,                /* T_SHARED  */
    T_SIZE = 446,                  /* T_SIZE  */
    T_TARGET = 447,                /* T_TARGET  */
    T_TLS = 448,                   /* T_TLS  */
    T_UMODES = 449,                /* T_UMODES  */
    T_UNDLINE = 450,               /* T_UNDLINE  */
    T_UNLIMITED = 451,             /* T_UNLIMITED  */
    T_UNRESV = 452,                /* T_UNRESV  */
    T_UNXLINE = 453,               /* T_UNXLINE  */
    T_WEBIRC = 454,                /* T_WEBIRC  */
    TBOOL = 455,                   /* TBOOL  */
    THROTTLE_COUNT = 456,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 457,           /* THROTTLE_TIME  */
    TIMEOUT = 458,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 459,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 460, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 461,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 462, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 463,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 464,           /* TS_WARN_DELTA  */
    TWODOTS = 465,                 /* TWODOTS  */
    TYPE = 466,                    /* TYPE  */
    UNKLINE = 467,                 /* UNKLINE  */
    USE_LOGGING = 468,             /* USE_LOGGING  */
    USER = 469,                    /* USER  */
    VHOST = 470,                   /* VHOST  */
    VHOST6 = 471,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 472,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 473,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 474,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 475,                   /* XLINE  */
    XLINE_EXEMPT = 476,            /* XLINE_EXEMPT  */
    QSTRING = 477,                 /* QSTRING  */
    NUMBER = 478                   /* NUMBER  */
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
#define T_COMMAND 427
#define T_CLUSTER 428
#define T_DEBUG 429
#define T_DLINE 430
#define T_FILE 431
#define T_GLOBOPS 432
#define T_IPV4 433
#define T_IPV6 434
#define T_LOCOPS 435
#define T_LOG 436
#define T_OPME 437
#define T_PREPEND 438
#define T_PSEUDO 439
#define T_RECVQ 440
#define T_RESTART 441
#define T_SERVER 442
#define T_SERVICE 443
#define T_SET 444
#define T_SHARED 445
#define T_SIZE 446
#define T_TARGET 447
#define T_TLS 448
#define T_UMODES 449
#define T_UNDLINE 450
#define T_UNLIMITED 451
#define T_UNRESV 452
#define T_UNXLINE 453
#define T_WEBIRC 454
#define TBOOL 455
#define THROTTLE_COUNT 456
#define THROTTLE_TIME 457
#define TIMEOUT 458
#define TLS_CERTIFICATE_FILE 459
#define TLS_CERTIFICATE_FINGERPRINT 460
#define TLS_PRIVATE_KEY_FILE 461
#define TLS_CONNECTION_REQUIRED 462
#define TS_MAX_DELTA 463
#define TS_WARN_DELTA 464
#define TWODOTS 465
#define TYPE 466
#define UNKLINE 467
#define USE_LOGGING 468
#define USER 469
#define VHOST 470
#define VHOST6 471
#define WARN_NO_CONNECT_BLOCK 472
#define WHOIS 473
#define WHOWAS_HISTORY_LENGTH 474
#define XLINE 475
#define XLINE_EXEMPT 476
#define QSTRING 477
#define NUMBER 478

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 129 "conf_parser.y"

  int number;
  char *string;

#line 692 "conf_parser.c"

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
  YYSYMBOL_T_COMMAND = 172,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 173,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 174,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 175,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 176,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 177,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 178,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 179,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 180,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 181,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 182,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 183,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 184,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 185,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 186,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 187,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 188,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 189,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 190,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 191,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 192,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 193,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 194,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 195,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 196,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 197,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 198,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 199,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 200,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 201,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 202,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 203,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 204,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 205, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_PRIVATE_KEY_FILE = 206,     /* TLS_PRIVATE_KEY_FILE  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 207,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TS_MAX_DELTA = 208,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 209,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 210,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 211,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 212,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 213,              /* USE_LOGGING  */
  YYSYMBOL_USER = 214,                     /* USER  */
  YYSYMBOL_VHOST = 215,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 216,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 217,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 218,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 219,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 220,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 221,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 222,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 223,                   /* NUMBER  */
  YYSYMBOL_224_ = 224,                     /* ';'  */
  YYSYMBOL_225_ = 225,                     /* '}'  */
  YYSYMBOL_226_ = 226,                     /* '='  */
  YYSYMBOL_227_ = 227,                     /* ':'  */
  YYSYMBOL_228_ = 228,                     /* ','  */
  YYSYMBOL_229_ = 229,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 230,                 /* $accept  */
  YYSYMBOL_conf = 231,                     /* conf  */
  YYSYMBOL_conf_item = 232,                /* conf_item  */
  YYSYMBOL_timespec_ = 233,                /* timespec_  */
  YYSYMBOL_timespec = 234,                 /* timespec  */
  YYSYMBOL_sizespec_ = 235,                /* sizespec_  */
  YYSYMBOL_sizespec = 236,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 237,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 238,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 239,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 240,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 241,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 242,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 243,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 244,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 245, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_tls_private_key_file = 246, /* serverinfo_tls_private_key_file  */
  YYSYMBOL_serverinfo_name = 247,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 248,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 249,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 250,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 251, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 252, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 253, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 254, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_motd_file = 255,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 256,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 257,              /* admin_entry  */
  YYSYMBOL_admin_items = 258,              /* admin_items  */
  YYSYMBOL_admin_item = 259,               /* admin_item  */
  YYSYMBOL_admin_name = 260,               /* admin_name  */
  YYSYMBOL_admin_email = 261,              /* admin_email  */
  YYSYMBOL_admin_description = 262,        /* admin_description  */
  YYSYMBOL_motd_entry = 263,               /* motd_entry  */
  YYSYMBOL_264_1 = 264,                    /* $@1  */
  YYSYMBOL_motd_items = 265,               /* motd_items  */
  YYSYMBOL_motd_item = 266,                /* motd_item  */
  YYSYMBOL_motd_mask = 267,                /* motd_mask  */
  YYSYMBOL_motd_file = 268,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 269,             /* pseudo_entry  */
  YYSYMBOL_270_2 = 270,                    /* $@2  */
  YYSYMBOL_pseudo_items = 271,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 272,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 273,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 274,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 275,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 276,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 277,            /* logging_entry  */
  YYSYMBOL_logging_items = 278,            /* logging_items  */
  YYSYMBOL_logging_item = 279,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 280,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 281,       /* logging_file_entry  */
  YYSYMBOL_282_3 = 282,                    /* $@3  */
  YYSYMBOL_logging_file_items = 283,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 284,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 285,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 286,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 287,        /* logging_file_type  */
  YYSYMBOL_288_4 = 288,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 289,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 290,               /* oper_entry  */
  YYSYMBOL_291_5 = 291,                    /* $@5  */
  YYSYMBOL_oper_items = 292,               /* oper_items  */
  YYSYMBOL_oper_item = 293,                /* oper_item  */
  YYSYMBOL_oper_name = 294,                /* oper_name  */
  YYSYMBOL_oper_user = 295,                /* oper_user  */
  YYSYMBOL_oper_password = 296,            /* oper_password  */
  YYSYMBOL_oper_whois = 297,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 298,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 299, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 300, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 301,               /* oper_class  */
  YYSYMBOL_oper_umodes = 302,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 303,               /* oper_flags  */
  YYSYMBOL_304_6 = 304,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 305,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 306,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 307,              /* class_entry  */
  YYSYMBOL_308_7 = 308,                    /* $@7  */
  YYSYMBOL_class_items = 309,              /* class_items  */
  YYSYMBOL_class_item = 310,               /* class_item  */
  YYSYMBOL_class_name = 311,               /* class_name  */
  YYSYMBOL_class_ping_time = 312,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 313, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 314, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 315,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 316,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 317,         /* class_max_number  */
  YYSYMBOL_class_sendq = 318,              /* class_sendq  */
  YYSYMBOL_class_recvq = 319,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 320,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 321,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 322,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 323,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 324,           /* class_max_idle  */
  YYSYMBOL_class_flags = 325,              /* class_flags  */
  YYSYMBOL_326_8 = 326,                    /* $@8  */
  YYSYMBOL_class_flags_items = 327,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 328,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 329,             /* listen_entry  */
  YYSYMBOL_330_9 = 330,                    /* $@9  */
  YYSYMBOL_listen_flags = 331,             /* listen_flags  */
  YYSYMBOL_332_10 = 332,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 333,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 334,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 335,             /* listen_items  */
  YYSYMBOL_listen_item = 336,              /* listen_item  */
  YYSYMBOL_listen_port = 337,              /* listen_port  */
  YYSYMBOL_338_11 = 338,                   /* $@11  */
  YYSYMBOL_port_items = 339,               /* port_items  */
  YYSYMBOL_port_item = 340,                /* port_item  */
  YYSYMBOL_listen_address = 341,           /* listen_address  */
  YYSYMBOL_listen_host = 342,              /* listen_host  */
  YYSYMBOL_auth_entry = 343,               /* auth_entry  */
  YYSYMBOL_344_12 = 344,                   /* $@12  */
  YYSYMBOL_auth_items = 345,               /* auth_items  */
  YYSYMBOL_auth_item = 346,                /* auth_item  */
  YYSYMBOL_auth_user = 347,                /* auth_user  */
  YYSYMBOL_auth_passwd = 348,              /* auth_passwd  */
  YYSYMBOL_auth_class = 349,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 350,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 351,               /* auth_flags  */
  YYSYMBOL_352_13 = 352,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 353,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 354,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 355,               /* auth_spoof  */
  YYSYMBOL_resv_entry = 356,               /* resv_entry  */
  YYSYMBOL_357_14 = 357,                   /* $@14  */
  YYSYMBOL_resv_items = 358,               /* resv_items  */
  YYSYMBOL_resv_item = 359,                /* resv_item  */
  YYSYMBOL_resv_mask = 360,                /* resv_mask  */
  YYSYMBOL_resv_reason = 361,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 362,              /* resv_exempt  */
  YYSYMBOL_service_entry = 363,            /* service_entry  */
  YYSYMBOL_service_items = 364,            /* service_items  */
  YYSYMBOL_service_item = 365,             /* service_item  */
  YYSYMBOL_service_name = 366,             /* service_name  */
  YYSYMBOL_shared_entry = 367,             /* shared_entry  */
  YYSYMBOL_368_15 = 368,                   /* $@15  */
  YYSYMBOL_shared_items = 369,             /* shared_items  */
  YYSYMBOL_shared_item = 370,              /* shared_item  */
  YYSYMBOL_shared_name = 371,              /* shared_name  */
  YYSYMBOL_shared_user = 372,              /* shared_user  */
  YYSYMBOL_shared_type = 373,              /* shared_type  */
  YYSYMBOL_374_16 = 374,                   /* $@16  */
  YYSYMBOL_shared_types = 375,             /* shared_types  */
  YYSYMBOL_shared_type_item = 376,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 377,            /* cluster_entry  */
  YYSYMBOL_378_17 = 378,                   /* $@17  */
  YYSYMBOL_cluster_items = 379,            /* cluster_items  */
  YYSYMBOL_cluster_item = 380,             /* cluster_item  */
  YYSYMBOL_cluster_name = 381,             /* cluster_name  */
  YYSYMBOL_cluster_type = 382,             /* cluster_type  */
  YYSYMBOL_383_18 = 383,                   /* $@18  */
  YYSYMBOL_cluster_types = 384,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 385,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 386,            /* connect_entry  */
  YYSYMBOL_387_19 = 387,                   /* $@19  */
  YYSYMBOL_connect_items = 388,            /* connect_items  */
  YYSYMBOL_connect_item = 389,             /* connect_item  */
  YYSYMBOL_connect_name = 390,             /* connect_name  */
  YYSYMBOL_connect_host = 391,             /* connect_host  */
  YYSYMBOL_connect_timeout = 392,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 393,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 394,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 395,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 396, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 397,             /* connect_port  */
  YYSYMBOL_connect_aftype = 398,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 399,            /* connect_flags  */
  YYSYMBOL_400_20 = 400,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 401,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 402,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 403,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 404,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 405,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 406,            /* connect_class  */
  YYSYMBOL_kill_entry = 407,               /* kill_entry  */
  YYSYMBOL_408_21 = 408,                   /* $@21  */
  YYSYMBOL_kill_items = 409,               /* kill_items  */
  YYSYMBOL_kill_item = 410,                /* kill_item  */
  YYSYMBOL_kill_user = 411,                /* kill_user  */
  YYSYMBOL_kill_reason = 412,              /* kill_reason  */
  YYSYMBOL_deny_entry = 413,               /* deny_entry  */
  YYSYMBOL_414_22 = 414,                   /* $@22  */
  YYSYMBOL_deny_items = 415,               /* deny_items  */
  YYSYMBOL_deny_item = 416,                /* deny_item  */
  YYSYMBOL_deny_ip = 417,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 418,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 419,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 420,             /* exempt_items  */
  YYSYMBOL_exempt_item = 421,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 422,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 423,              /* gecos_entry  */
  YYSYMBOL_424_23 = 424,                   /* $@23  */
  YYSYMBOL_gecos_items = 425,              /* gecos_items  */
  YYSYMBOL_gecos_item = 426,               /* gecos_item  */
  YYSYMBOL_gecos_name = 427,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 428,             /* gecos_reason  */
  YYSYMBOL_general_entry = 429,            /* general_entry  */
  YYSYMBOL_general_items = 430,            /* general_items  */
  YYSYMBOL_general_item = 431,             /* general_item  */
  YYSYMBOL_general_away_count = 432,       /* general_away_count  */
  YYSYMBOL_general_away_time = 433,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 434,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 435, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 436, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 437,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 438,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 439,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 440,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 441, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 442, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 443,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 444,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 445, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 446,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 447,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 448, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 449,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 450,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 451, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 452, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 453, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_m_oper_only = 454, /* general_stats_m_oper_only  */
  YYSYMBOL_general_stats_o_oper_only = 455, /* general_stats_o_oper_only  */
  YYSYMBOL_general_stats_P_oper_only = 456, /* general_stats_P_oper_only  */
  YYSYMBOL_general_stats_u_oper_only = 457, /* general_stats_u_oper_only  */
  YYSYMBOL_general_stats_k_oper_only = 458, /* general_stats_k_oper_only  */
  YYSYMBOL_general_stats_i_oper_only = 459, /* general_stats_i_oper_only  */
  YYSYMBOL_general_pace_wait = 460,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 461,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 462, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 463, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 464,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 465,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 466, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 467,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 468,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_ident = 469,    /* general_disable_ident  */
  YYSYMBOL_general_disable_dns = 470,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 471,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 472,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 473,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 474,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 475, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 476, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 477, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 478,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 479, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 480, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 481,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 482,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 483,     /* general_cloak_suffix  */
  YYSYMBOL_general_ident_timeout = 484,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 485, /* general_registration_timeout  */
  YYSYMBOL_channel_entry = 486,            /* channel_entry  */
  YYSYMBOL_channel_items = 487,            /* channel_items  */
  YYSYMBOL_channel_item = 488,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 489,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 490,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 491,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 492, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 493, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 494, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 495, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 496, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 497, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 498, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 499, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 500,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 501,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 502,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 503,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 504,  /* channel_max_kick_length  */
  YYSYMBOL_channel_default_join_flood_count = 505, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 506, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 507,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 508,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 509,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 510, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 511, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 512, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 513, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 514,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 515, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 516,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 517         /* serverhide_hidden  */
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
#define YYLAST   1211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  230
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  288
/* YYNRULES -- Number of rules.  */
#define YYNRULES  599
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1251

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   478


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
       2,     2,     2,     2,   228,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   227,   224,
       2,   226,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   229,     2,   225,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221,   222,   223
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   354,   354,   355,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   386,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   397,
     397,   398,   399,   400,   401,   408,   418,   425,   427,   429,
     429,   431,   435,   445,   447,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   463,
     472,   481,   496,   511,   521,   535,   544,   567,   590,   598,
     607,   617,   619,   619,   620,   621,   622,   623,   625,   634,
     643,   657,   656,   674,   674,   675,   675,   675,   677,   683,
     694,   693,   712,   712,   713,   713,   713,   713,   713,   715,
     721,   727,   733,   756,   757,   757,   759,   759,   760,   762,
     772,   772,   785,   786,   788,   788,   789,   789,   791,   799,
     802,   808,   807,   813,   817,   821,   825,   829,   833,   837,
     841,   852,   851,   913,   913,   914,   915,   916,   917,   918,
     919,   920,   921,   922,   923,   924,   926,   932,   938,   944,
     950,   961,   967,   978,   984,   991,   990,   996,   996,   997,
    1001,  1005,  1009,  1013,  1017,  1021,  1025,  1029,  1033,  1037,
    1041,  1045,  1049,  1053,  1057,  1061,  1065,  1069,  1073,  1077,
    1081,  1085,  1089,  1093,  1097,  1101,  1105,  1109,  1120,  1119,
    1175,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1193,  1199,
    1205,  1211,  1217,  1223,  1229,  1235,  1241,  1248,  1254,  1260,
    1266,  1275,  1285,  1284,  1290,  1290,  1291,  1295,  1306,  1305,
    1312,  1311,  1316,  1316,  1317,  1321,  1325,  1329,  1333,  1339,
    1339,  1340,  1340,  1340,  1340,  1340,  1342,  1342,  1344,  1344,
    1346,  1359,  1376,  1382,  1393,  1392,  1440,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1447,  1449,  1455,  1461,  1467,  1479,
    1478,  1484,  1484,  1485,  1489,  1493,  1497,  1501,  1505,  1509,
    1513,  1517,  1523,  1542,  1541,  1556,  1556,  1557,  1557,  1557,
    1557,  1559,  1565,  1571,  1581,  1583,  1583,  1584,  1584,  1586,
    1603,  1602,  1625,  1625,  1626,  1626,  1626,  1626,  1628,  1634,
    1654,  1653,  1659,  1659,  1660,  1664,  1668,  1672,  1676,  1680,
    1684,  1688,  1692,  1696,  1707,  1706,  1725,  1725,  1726,  1726,
    1726,  1728,  1735,  1734,  1740,  1740,  1741,  1745,  1749,  1753,
    1757,  1761,  1765,  1769,  1773,  1777,  1788,  1787,  1841,  1841,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    1852,  1853,  1854,  1855,  1856,  1858,  1864,  1870,  1876,  1882,
    1895,  1908,  1914,  1920,  1924,  1931,  1930,  1935,  1935,  1936,
    1940,  1946,  1957,  1963,  1969,  1980,  1979,  2003,  2003,  2004,
    2004,  2004,  2006,  2026,  2037,  2036,  2061,  2061,  2062,  2062,
    2062,  2064,  2070,  2080,  2082,  2082,  2083,  2083,  2085,  2104,
    2103,  2124,  2124,  2125,  2125,  2125,  2127,  2133,  2143,  2145,
    2145,  2146,  2147,  2148,  2149,  2150,  2151,  2152,  2153,  2154,
    2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2170,  2171,  2172,  2173,  2174,
    2175,  2176,  2177,  2178,  2179,  2180,  2181,  2182,  2183,  2184,
    2185,  2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,  2194,
    2195,  2196,  2197,  2198,  2199,  2200,  2203,  2208,  2213,  2218,
    2223,  2228,  2233,  2238,  2243,  2248,  2253,  2258,  2263,  2268,
    2273,  2278,  2286,  2291,  2296,  2301,  2306,  2311,  2316,  2321,
    2326,  2331,  2336,  2341,  2346,  2351,  2356,  2361,  2366,  2371,
    2376,  2381,  2386,  2391,  2396,  2401,  2406,  2411,  2420,  2425,
    2430,  2435,  2440,  2457,  2465,  2473,  2481,  2491,  2501,  2509,
    2518,  2520,  2520,  2521,  2522,  2523,  2524,  2525,  2526,  2527,
    2528,  2529,  2530,  2531,  2532,  2533,  2534,  2535,  2536,  2537,
    2538,  2539,  2541,  2546,  2552,  2558,  2563,  2568,  2573,  2578,
    2583,  2588,  2593,  2598,  2603,  2608,  2613,  2618,  2641,  2646,
    2655,  2657,  2657,  2658,  2659,  2660,  2661,  2662,  2663,  2664,
    2665,  2666,  2668,  2674,  2685,  2694,  2700,  2706,  2712,  2721
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
  "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS",
  "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ", "SERVERHIDE", "SERVERINFO",
  "SHORT_MOTD", "SPECIALS_IN_IDENT", "SPOOF", "SQUIT", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_M_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL",
  "T_BIND", "T_COMMAND", "T_CLUSTER", "T_DEBUG", "T_DLINE", "T_FILE",
  "T_GLOBOPS", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_OPME",
  "T_PREPEND", "T_PSEUDO", "T_RECVQ", "T_RESTART", "T_SERVER", "T_SERVICE",
  "T_SET", "T_SHARED", "T_SIZE", "T_TARGET", "T_TLS", "T_UMODES",
  "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_WEBIRC", "TBOOL",
  "THROTTLE_COUNT", "THROTTLE_TIME", "TIMEOUT", "TLS_CERTIFICATE_FILE",
  "TLS_CERTIFICATE_FINGERPRINT", "TLS_PRIVATE_KEY_FILE",
  "TLS_CONNECTION_REQUIRED", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "TYPE", "UNKLINE", "USE_LOGGING", "USER", "VHOST", "VHOST6",
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "WHOWAS_HISTORY_LENGTH", "XLINE",
  "XLINE_EXEMPT", "QSTRING", "NUMBER", "';'", "'}'", "'='", "':'", "','",
  "'{'", "$accept", "conf", "conf_item", "timespec_", "timespec",
  "sizespec_", "sizespec", "module_base_path_entry", "loadmodule_entry",
  "module_attributes", "module_attributes_items", "module_attributes_item",
  "serverinfo_entry", "serverinfo_items", "serverinfo_item",
  "serverinfo_tls_certificate_file", "serverinfo_tls_private_key_file",
  "serverinfo_name", "serverinfo_sid", "serverinfo_description",
  "serverinfo_network_name", "serverinfo_network_description",
  "serverinfo_default_max_clients", "serverinfo_max_nick_length",
  "serverinfo_max_topic_length", "serverinfo_motd_file", "serverinfo_hub",
  "admin_entry", "admin_items", "admin_item", "admin_name", "admin_email",
  "admin_description", "motd_entry", "$@1", "motd_items", "motd_item",
  "motd_mask", "motd_file", "pseudo_entry", "$@2", "pseudo_items",
  "pseudo_item", "pseudo_command", "pseudo_name", "pseudo_prepend",
  "pseudo_target", "logging_entry", "logging_items", "logging_item",
  "logging_use_logging", "logging_file_entry", "$@3", "logging_file_items",
  "logging_file_item", "logging_file_name", "logging_file_size",
  "logging_file_type", "$@4", "logging_file_type_item", "oper_entry",
  "$@5", "oper_items", "oper_item", "oper_name", "oper_user",
  "oper_password", "oper_whois", "oper_encrypted",
  "oper_tls_certificate_fingerprint", "oper_tls_connection_required",
  "oper_class", "oper_umodes", "oper_flags", "$@6", "oper_flags_items",
  "oper_flags_item", "class_entry", "$@7", "class_items", "class_item",
  "class_name", "class_ping_time", "class_number_per_ip_local",
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
  "connect_class", "kill_entry", "$@21", "kill_items", "kill_item",
  "kill_user", "kill_reason", "deny_entry", "$@22", "deny_items",
  "deny_item", "deny_ip", "deny_reason", "exempt_entry", "exempt_items",
  "exempt_item", "exempt_ip", "gecos_entry", "$@23", "gecos_items",
  "gecos_item", "gecos_name", "gecos_reason", "general_entry",
  "general_items", "general_item", "general_away_count",
  "general_away_time", "general_max_monitor",
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

#define YYPACT_NINF (-984)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -984,   751,  -984,  -149,  -206,  -176,  -984,  -984,  -984,  -174,
    -984,  -168,  -984,  -984,  -984,  -184,  -185,  -984,  -984,  -984,
    -146,  -145,  -984,  -144,  -984,  -138,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,    31,   855,  -137,  -130,  -129,     6,  -127,
     452,  -125,  -122,  -112,   -71,   -62,   -68,   -52,   -51,   444,
     623,   -49,    27,   -43,    18,   -41,   -57,   -34,   -32,   -30,
       4,  -984,  -984,  -984,  -984,  -984,   -24,   -21,   -20,   -17,
     -16,   -13,   -12,   -11,    -5,    -1,    33,    36,    39,    71,
      73,    75,    77,    81,   242,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,   664,   647,     5,  -984,    83,    14,
    -984,  -984,    28,  -984,    99,   101,   112,   116,   120,   124,
     128,   132,   135,   136,   137,   139,   144,   146,   148,   150,
     151,   153,   155,   156,   158,   164,   165,   166,   167,   168,
     171,   173,   174,   175,   176,   177,   180,   181,   182,   183,
     184,   185,   188,   190,   191,   192,   193,   194,   195,   197,
     199,   200,   201,   202,   203,   204,   207,   208,    87,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,   281,   123,   293,    -3,    -2,     8,
      21,   385,   320,  -984,   213,   217,   220,   221,   223,   224,
     225,   226,     2,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,    51,   228,   231,   238,   239,   243,   245,   253,
     255,   256,   261,   263,   265,   162,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,    47,
      96,   270,    85,  -984,  -984,  -984,   212,   206,  -984,   285,
      17,  -984,  -984,   169,  -984,   210,   234,   246,   283,  -984,
     172,   289,   313,   314,   316,   318,   292,   289,   289,   289,
     297,   289,   289,   298,   301,   302,   303,   305,   307,  -984,
     308,   309,   310,   323,  -984,   324,   325,   326,   331,   335,
     336,   337,   348,   349,   351,   352,    48,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,   322,   354,   356,   360,   361,   363,   365,
    -984,   370,   371,   372,   375,   376,   378,   379,   267,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,   382,   384,    68,  -984,  -984,
    -984,   311,   389,  -984,  -984,   397,   399,    44,  -984,  -984,
    -984,   329,   289,   403,   289,   289,   427,   405,   406,   407,
     409,   410,   433,   411,   289,   435,   437,   415,   416,   441,
     289,   442,   289,   420,   421,   422,   423,   424,   428,   289,
     432,   434,   440,   456,   436,   464,   289,   289,   467,   289,
     473,   453,   477,   478,   479,   480,   483,   484,   485,   463,
     289,   289,   289,   487,   466,   451,  -984,   468,   469,   471,
    -984,   474,   481,   491,    20,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,   492,   493,    10,  -984,  -984,  -984,   470,
     494,   496,  -984,   500,  -984,    49,  -984,  -984,  -984,  -984,
    -984,  -984,   462,  -984,  -984,  -984,   486,   501,   503,    41,
    -984,  -984,  -984,   489,   504,   505,  -984,   507,   508,   509,
     510,   513,   517,   521,   230,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,   524,   527,   528,   530,
      86,  -984,  -984,  -984,  -984,   499,   550,   289,   482,   557,
     536,   559,   560,   537,  -984,  -984,   539,   544,   568,   547,
     549,   553,   551,   555,   556,   558,   561,   562,   563,  -984,
     564,   567,  -984,    94,  -984,  -984,  -984,  -984,   581,   570,
    -984,   476,   571,   573,   574,   579,   580,   130,  -984,  -984,
    -984,  -984,  -984,   575,   572,  -984,   583,   585,  -984,   587,
     142,  -984,  -984,  -984,  -984,   590,   591,   592,  -984,   593,
     391,   595,   597,   598,   600,   606,   607,   609,   610,   611,
     613,   614,   615,   620,   621,   627,   629,   630,  -984,  -984,
     624,   632,   289,   631,   635,   289,   636,   289,   638,   639,
     642,   645,   289,   646,   646,   648,  -984,  -984,   649,   -99,
     651,   586,   652,   653,   644,   654,   655,   656,   658,   660,
     289,   661,   663,  -984,   662,   669,   668,  -984,   670,  -984,
     671,   673,   672,  -984,   675,   676,   677,   678,   682,   683,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   701,   702,   707,   709,   710,   712,
     713,   714,   716,   721,   722,   723,   724,   725,   726,   727,
     731,   734,   735,   736,   737,   738,   739,   740,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   750,  -984,  -984,
     753,   685,   752,   754,   755,   757,   756,  -984,   759,   760,
     761,  -984,  -984,   762,   764,   763,   665,   766,  -984,    -3,
    -984,   765,   769,   768,  -984,  -984,   771,   783,   770,   772,
     773,   775,   776,   788,   777,   778,   779,  -984,  -984,   780,
     782,   784,   781,  -984,   785,   786,   787,   789,   790,   791,
     792,   793,  -984,   794,   795,   796,   797,   798,   799,   800,
     801,   802,   803,   804,   805,  -984,  -984,   808,   806,   807,
    -984,   809,  -984,    46,  -984,   812,   813,   814,   815,   816,
    -984,   817,  -984,  -984,   820,   818,   821,   822,  -984,  -984,
    -984,  -984,  -984,   289,   289,   289,   289,   289,   289,   289,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,   823,
     824,   825,   -50,   826,   827,   828,   829,   830,   831,   832,
     833,   834,    13,   835,   836,  -984,   837,   838,   839,   840,
     841,   842,   843,    -4,   844,   845,   846,   847,   848,   849,
     850,  -984,   851,   852,  -984,  -984,   853,   854,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,   856,   857,   475,   858,   859,   860,  -984,
     861,   862,  -984,   863,   864,   315,   869,   810,  -984,  -984,
    -984,   865,   866,  -984,   867,   868,   526,   870,   871,   872,
     873,   874,   875,   876,  -984,   877,   878,   879,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,   880,
     628,  -984,  -984,   881,   819,   882,  -984,    53,  -984,  -984,
    -984,  -984,   883,   885,   886,   887,  -984,  -984,   888,   666,
     889,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -208,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,   646,   646,   646,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -194,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -193,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -191,
    -984,   891,   665,   892,  -984,  -984,  -984,  -984,  -984,  -984,
     774,  -984,   890,   893,  -984,   894,  -984,   895,   896,  -984,
    -984,   897,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -188,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -172,  -984,  -984,   884,
    -179,   899,   902,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -164,
    -984,  -984,  -984,   -50,  -984,  -984,  -984,  -984,    -4,  -984,
     475,  -984,   315,  -984,  -984,  -984,   566,   947,   972,   913,
     973,   975,   984,  -984,   526,  -984,   628,   904,   905,   906,
     266,  -984,  -984,   666,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,   907,  -984,
    -984
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   198,   356,   404,     0,
     419,     0,   264,   395,   238,     0,     0,    91,   141,   293,
       0,     0,   334,     0,   100,     0,   310,     3,     4,     5,
      13,     6,    25,    26,     7,     8,    10,    11,    12,    15,
      16,    17,    18,    19,    20,    21,    22,    24,    23,     9,
      14,    27,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    86,    85,   561,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   542,   558,   559,   560,   557,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   543,
     544,   554,   555,   556,     0,     0,     0,   417,     0,     0,
     415,   416,     0,   485,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   430,
     431,   432,   475,   438,   476,   470,   471,   472,   473,   442,
     433,   434,   435,   436,   437,   457,   439,   440,   441,   443,
     444,   474,   448,   449,   450,   451,   447,   446,   452,   459,
     460,   453,   454,   455,   445,   456,   467,   468,   469,   465,
     466,   458,   463,   464,   461,   462,   477,   478,   479,   480,
     481,   482,   483,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   591,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   582,   583,   584,   585,   586,   587,   588,
     590,   589,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    67,    65,    56,
      66,    58,    59,    60,    61,    62,    63,    64,    57,     0,
       0,     0,     0,   115,   116,   117,     0,     0,   308,     0,
       0,   306,   307,     0,    87,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   541,
       0,     0,     0,     0,   232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   202,   205,
     207,   208,   209,   210,   211,   212,   213,   203,   204,   206,
     214,   215,   216,     0,     0,     0,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,   362,   363,   364,   365,   366,   368,   367,   369,
     373,   370,   371,   372,   410,     0,     0,     0,   407,   408,
     409,     0,     0,   414,   425,     0,     0,     0,   422,   423,
     424,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   429,     0,     0,     0,
     279,     0,     0,     0,     0,   267,   268,   269,   270,   273,
     271,   272,   401,     0,     0,     0,   398,   399,   400,     0,
       0,     0,   240,     0,   252,     0,   250,   251,   253,   254,
      52,    51,    48,    50,    46,    45,     0,     0,     0,     0,
      94,    95,    96,     0,     0,     0,   165,     0,     0,     0,
       0,     0,     0,     0,     0,   144,   145,   146,   147,   148,
     151,   152,   153,   150,   149,   154,     0,     0,     0,     0,
       0,   296,   297,   298,   299,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   581,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,   342,     0,   337,   338,   339,   118,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,   103,   104,
     106,   105,   107,     0,     0,   305,     0,     0,   320,     0,
       0,   313,   314,   315,   316,     0,     0,     0,    81,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   540,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,   374,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   358,     0,     0,     0,   406,     0,   413,
       0,     0,     0,   421,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   428,   274,
       0,     0,     0,     0,     0,     0,     0,   266,     0,     0,
       0,   397,   255,     0,     0,     0,     0,     0,   249,     0,
      97,     0,     0,     0,    93,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   300,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,   580,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,   340,     0,     0,     0,
     336,     0,   113,     0,   108,     0,     0,     0,     0,     0,
     102,     0,   304,   317,     0,     0,     0,     0,   312,    90,
      89,    88,   578,    29,    29,    29,    29,    29,    29,    29,
      31,    30,   579,   565,   564,   562,   563,   566,   567,   568,
     569,   570,   571,   572,   575,   576,   573,   574,   577,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,     0,     0,   199,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   357,     0,     0,   405,   418,     0,     0,   420,   497,
     502,   486,   487,   515,   532,   533,   534,   535,   536,   537,
     490,   530,   531,   524,   523,   491,   492,   496,   538,   505,
     495,   493,   494,   500,   501,   488,   499,   498,   521,   528,
     529,   519,   527,   516,   514,   517,   522,   539,   518,   520,
     507,   513,   512,   508,   509,   510,   511,   525,   526,   504,
     503,   506,   489,     0,     0,     0,     0,     0,     0,   265,
       0,     0,   396,     0,     0,     0,   260,   256,   259,   239,
      49,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,     0,     0,     0,   294,   595,
     592,   593,   594,   599,   598,   596,   597,    76,    73,    80,
      72,    77,    78,    79,    71,    75,    74,    69,    70,     0,
       0,   335,   119,     0,     0,     0,   131,     0,   123,   124,
     126,   125,     0,     0,     0,     0,   101,   309,     0,     0,
       0,   311,    32,    33,    34,    35,    36,    37,    38,   227,
     228,   222,   237,   236,     0,   235,   223,   231,   224,   230,
     218,   229,   221,   220,   219,    39,    39,    39,    41,    40,
     225,   226,   380,   383,   384,   394,   391,   376,   392,   389,
     390,     0,   388,   393,   375,   382,   379,   378,   377,   381,
     411,   412,   426,   427,   277,   278,   287,   283,   284,   286,
     291,   288,   289,   290,   285,     0,   282,   276,   292,   275,
     403,   402,   263,   262,   247,   248,   245,   246,   244,     0,
     243,     0,     0,     0,    98,    99,   163,   160,   185,   196,
     172,   181,     0,   170,   175,     0,   190,     0,   184,   188,
     194,   174,   177,   186,   187,   191,   182,   189,   178,   195,
     180,   176,   179,     0,   168,   156,   158,   164,   161,   162,
     157,   159,   303,   301,   302,   341,   346,   352,   355,   348,
     354,   349,   353,   351,   347,   350,     0,   345,   127,     0,
       0,     0,     0,   122,   110,   109,   111,   112,   318,   324,
     330,   333,   326,   332,   327,   331,   329,   325,   328,     0,
     323,   319,   233,     0,    42,    43,    44,   386,     0,   280,
       0,   241,     0,   261,   258,   257,     0,     0,     0,     0,
       0,     0,     0,   166,     0,   343,     0,     0,     0,     0,
       0,   121,   321,     0,   234,   387,   281,   242,   171,   193,
     169,   197,   192,   183,   173,   167,   344,   128,   130,   129,
     139,   138,   134,   136,   140,   137,   133,   135,     0,   322,
     132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -984,  -984,  -984,  -266,  -319,  -983,  -653,  -984,  -984,  -984,
    -984,   249,  -984,  -984,   898,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,   932,
    -984,  -984,  -984,  -984,  -984,  -984,   520,  -984,  -984,  -984,
    -984,  -984,   535,  -984,  -984,  -984,  -984,  -984,  -984,   900,
    -984,  -984,  -984,  -984,   117,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,   599,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,   -79,  -984,  -984,  -984,
     811,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,   -56,  -984,
    -984,  -984,  -984,  -984,   -66,  -984,   633,  -984,  -984,  -984,
      29,  -984,  -984,  -984,  -984,  -984,   659,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,   -61,  -984,  -984,  -984,  -984,   594,
    -984,  -984,  -984,  -984,  -984,   901,  -984,  -984,  -984,  -984,
     532,  -984,  -984,  -984,  -984,  -984,   -83,  -984,  -984,  -984,
     565,  -984,  -984,  -984,  -984,   -70,  -984,  -984,  -984,   767,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,   -53,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
     657,  -984,  -984,  -984,  -984,  -984,   758,  -984,  -984,  -984,
    -984,  1018,  -984,  -984,  -984,  -984,   732,  -984,  -984,  -984,
    -984,   962,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  1047,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,   908,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   840,   841,  1058,  1059,    28,    29,   248,
     512,   513,    30,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    31,    80,    81,
      82,    83,    84,    32,    66,   519,   520,   521,   522,    33,
      73,   597,   598,   599,   600,   601,   602,    34,   302,   303,
     304,   305,   306,  1017,  1018,  1019,  1020,  1021,  1171,  1248,
      35,    67,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   768,  1143,  1144,    36,    55,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   643,  1044,  1045,    37,
      63,   504,   755,  1109,  1110,   505,   506,   507,  1113,   967,
     968,   508,   509,    38,    61,   484,   485,   486,   487,   488,
     489,   490,   742,  1095,  1096,   491,    39,    68,   550,   551,
     552,   553,   554,    40,   310,   311,   312,    41,    75,   610,
     611,   612,   613,   614,   825,  1189,  1190,    42,    71,   583,
     584,   585,   586,   808,  1166,  1167,    43,    56,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     664,  1071,  1072,   400,   401,   402,   403,    44,    62,   495,
     496,   497,   498,    45,    57,   407,   408,   409,   410,    46,
     129,   130,   131,    47,    59,   417,   418,   419,   420,    48,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    49,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    50,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     873,   874,   621,   253,  1069,    76,   404,   127,   627,   628,
     629,   492,   631,   632,  1042,   127,  1192,  1218,   308,   308,
    1193,   477,   516,    53,  1055,  1056,  1057,   510,   300,   414,
    1197,  1199,    76,  1201,  1198,  1200,  1213,  1202,    64,   478,
    1214,    65,   516,    77,   872,   414,   254,  1013,   580,   340,
     499,    78,  1215,    54,  1013,    58,  1216,   255,   256,   257,
    1222,    60,   258,   259,  1223,   341,   342,   260,   261,   404,
      77,   479,  1194,  1195,  1196,    51,    52,   343,    78,   877,
     878,   405,   128,    69,    70,    72,   300,   546,   133,  1043,
     128,    74,   124,   134,   135,   580,   136,   137,   480,   125,
     126,   138,   132,   685,   244,   687,   688,   245,   139,   140,
     141,   142,   143,   144,   517,   697,   500,   246,   145,   146,
     147,   703,    79,   705,   492,   501,   344,   502,   148,   149,
     712,   592,   150,   151,   517,   309,   309,   719,   720,   547,
     722,   152,   511,   606,   405,   406,   415,   345,   346,    79,
     493,   733,   734,   735,   481,   347,   247,   153,   154,   348,
     249,   250,   415,   272,  1014,   581,   349,   314,   416,   155,
     606,  1014,   156,   157,   350,   351,   352,   251,   252,   548,
     299,   482,   158,   159,   416,   353,   307,   503,   313,  1070,
     160,   161,   315,   162,   316,   163,   317,   518,   273,   164,
     165,   274,   320,  -120,   354,   321,   322,   592,   406,   323,
     324,   166,   581,   325,   326,   327,   167,   518,   168,   169,
     170,   328,   514,   171,   494,   329,   549,   563,   172,   318,
     275,   523,   515,   355,   483,   750,   872,  1015,   786,   412,
     301,   276,   604,    85,  1015,   746,   173,   174,   593,   524,
     175,   176,   177,   178,   179,   180,   181,  1016,   582,   330,
     607,  -120,   331,   493,  1016,   332,   763,   277,   373,   682,
     374,   278,   375,   655,   757,   565,    86,    87,  1172,   279,
     280,   525,   477,   281,   282,    88,   376,   607,   182,   183,
      89,    90,    91,   676,   499,   184,   185,   333,   301,   334,
     478,   335,   594,   336,   186,   582,   187,   337,   526,   411,
     589,   782,   475,   595,    92,    93,    94,    95,   377,   809,
     587,   546,   596,   861,   593,   421,   864,   422,   866,    96,
      97,    98,   479,   871,   378,  1104,   379,   494,   423,    99,
     100,   101,   424,   102,   103,   380,   425,  1240,   527,  1241,
     426,   889,  1105,   608,   427,   819,   609,   381,   428,   480,
     500,   429,   430,   431,   528,   432,   283,   827,   284,   501,
     433,   502,   434,   547,   435,  1106,   436,   437,   594,   438,
     608,   439,   440,   609,   441,   382,   523,   578,   591,   595,
     442,   443,   444,   445,   446,   619,  1242,   447,   596,   448,
     449,   450,   451,   452,   524,   383,   453,   454,   455,   456,
     457,   458,  1243,   548,   459,   481,   460,   461,   462,   463,
     464,   465,   384,   466,   529,   467,   468,   469,   470,   471,
     472,   503,   615,   473,   474,   530,   525,   531,   385,   555,
    1244,  1245,   482,   556,   532,   253,   557,   558,   533,   559,
     560,   561,   562,   133,   566,   776,   616,   567,   134,   135,
     549,   136,   137,   526,   568,   569,   138,   338,   617,   570,
     386,   571,   387,   139,   140,   141,   142,   143,   144,   572,
    1246,   573,   574,   145,   146,   147,  1247,   575,   254,   576,
    1086,   577,   672,   148,   149,   483,   588,   150,   151,   255,
     256,   257,  1107,   527,   258,   259,   152,   618,  1108,   260,
     261,   603,   620,   622,   623,   626,   624,  1219,   625,   528,
     630,   633,   153,   154,   634,   635,   636,  1087,   637,   684,
    1118,   638,   639,   678,   155,   640,   641,   156,   157,   833,
     834,   835,   836,   837,   838,   839,   657,   158,   159,   642,
     644,   645,   646,  1119,  1120,   160,   161,   647,   162,  1088,
     163,   648,   649,   650,   164,   165,  1121,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,   651,   652,   166,   653,   654,   529,
     658,   167,   659,   168,   169,   170,   660,   661,   171,   662,
     530,   663,   531,   172,  1089,  1090,   665,   666,   667,   532,
    1091,   668,   669,   533,   670,   671,  1122,  1123,   674,  1124,
     675,   173,   174,   679,   620,   175,   176,   177,   178,   179,
     180,   181,  1092,   680,   272,   681,   686,   689,   690,   691,
     692,   693,   694,   695,   696,   698,  1125,   699,   700,   701,
    1126,   702,   704,   706,   707,   708,   709,   710,   373,  1127,
     374,   711,   375,   182,   183,   713,   716,   714,   717,   273,
     184,   185,   274,   715,   718,   340,   376,   721,  1128,   186,
    1129,   187,  1130,   723,  1093,   738,   724,   725,   726,   727,
     728,   341,   342,   729,   730,   731,   732,   736,  1131,   737,
     759,   275,   739,   343,   752,   740,  1094,   741,   377,   784,
     743,  1132,   276,  1133,   787,   813,  1134,   744,  1135,  1228,
     760,  1156,  1136,   765,   378,  1137,   379,   745,   748,   749,
     753,  1138,   754,  1139,  1140,   380,   756,   761,   277,   762,
     766,   767,   278,   769,   770,   771,   772,   381,  1141,   773,
     279,   280,   344,   774,   281,   282,  1142,   775,   778,  1179,
     785,     2,     3,   779,   780,     4,   781,   788,   789,   790,
     791,   792,   793,   345,   346,   382,   794,     5,   795,   796,
       6,   347,   797,   799,  1157,   348,   798,   800,   801,     7,
     802,   811,   349,   803,   804,   383,   880,   805,   806,     8,
     350,   351,   352,   807,   812,   814,   822,   821,  1158,   815,
     816,   353,   384,  1159,     9,   817,   818,   823,  1160,    10,
      11,   824,  1180,   826,   829,   830,   831,   832,   385,   842,
     354,   843,   844,  1161,   845,  1162,  1163,   283,    12,   284,
     846,   847,    13,   848,   849,   850,  1181,   851,   852,   853,
    1164,  1182,    14,    15,   854,   855,  1183,   859,  1165,   355,
     386,   856,   387,   857,   858,   860,    85,   862,   863,   865,
     867,  1184,   868,  1185,  1186,   869,    16,    17,   870,   872,
     883,   876,   875,   879,   881,   882,   884,   885,  1187,   886,
     887,    18,   888,   890,   892,   954,  1188,   891,   966,    86,
      87,   893,   894,   896,   895,   897,   898,    19,    88,   899,
     900,   901,   902,    89,    90,    91,   903,   904,    20,    21,
     905,   906,   907,   908,   909,   910,   911,   912,   913,   914,
     915,   916,   917,   918,    22,   919,   920,    92,    93,    94,
      95,   921,    23,   922,   923,    24,   924,   925,   926,    25,
     927,    26,    96,    97,    98,   928,   929,   930,   931,   932,
     933,   934,    99,   100,   101,   935,   102,   103,   936,   937,
     938,   939,   940,   941,   942,   943,   944,   945,   946,   947,
     948,   949,   950,   951,   952,   953,   956,   957,   955,   958,
     959,   960,   961,   975,   963,   962,   964,   971,   981,   965,
     969,   972,   973,   974,   977,   978,   976,   979,   980,   982,
     983,  1206,   985,   984,   986,   988,   987,  1231,   970,   989,
     990,   991,   319,   992,   993,   994,   995,   996,   997,   998,
     999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,  1011,  1010,  1012,  1022,  1023,  1024,  1025,  1112,   764,
    1026,  1027,  1028,  1030,  1029,  1169,  1031,  1039,  1040,  1041,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1060,
    1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1111,
    1084,  1085,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1114,
    1115,  1116,  1117,  1229,  1145,  1146,  1147,  1148,  1149,  1150,
    1151,  1152,  1153,  1154,  1155,  1168,  1217,  1174,  1170,  1175,
    1176,  1177,  1178,  1191,  1203,  1230,  1205,  1207,  1233,  1232,
    1208,  1209,  1210,  1211,  1212,  1220,  1221,  1234,  1237,  1238,
    1239,  1250,   820,   777,  1173,  1235,  1227,  1224,   758,  1226,
    1249,  1204,   828,   747,   783,  1225,  1236,   413,   810,   683,
     476,   339,   751,     0,     0,   673,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   677,     0,   656,     0,     0,
     564,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,     0,     0,
       0,   605
};

static const yytype_int16 yycheck[] =
{
     653,   654,   321,     1,     8,     1,     1,     1,   327,   328,
     329,     1,   331,   332,    64,     1,   224,   196,     1,     1,
     228,     1,     1,   229,    11,    12,    13,    30,     1,     1,
     224,   224,     1,   224,   228,   228,   224,   228,   222,    19,
     228,   226,     1,    39,   223,     1,    44,     1,     1,     1,
       1,    47,   224,   229,     1,   229,   228,    55,    56,    57,
     224,   229,    60,    61,   228,    17,    18,    65,    66,     1,
      39,    51,  1055,  1056,  1057,   224,   225,    29,    47,   178,
     179,    76,    76,   229,   229,   229,     1,     1,     1,   139,
      76,   229,   229,     6,     7,     1,     9,    10,    78,   229,
     229,    14,   229,   422,   229,   424,   425,   229,    21,    22,
      23,    24,    25,    26,    93,   434,    67,   229,    31,    32,
      33,   440,   118,   442,     1,    76,    78,    78,    41,    42,
     449,     1,    45,    46,    93,   118,   118,   456,   457,    53,
     459,    54,   145,     1,    76,   140,   118,    99,   100,   118,
     140,   470,   471,   472,   134,   107,   227,    70,    71,   111,
     222,   229,   118,     1,   118,   118,   118,   224,   140,    82,
       1,   118,    85,    86,   126,   127,   128,   229,   229,    93,
     229,   161,    95,    96,   140,   137,   229,   138,   229,   193,
     103,   104,   226,   106,   226,   108,   226,   176,    36,   112,
     113,    39,   226,   176,   156,   226,   226,     1,   140,   226,
     226,   124,   118,   226,   226,   226,   129,   176,   131,   132,
     133,   226,   224,   136,   214,   226,   140,   225,   141,   225,
      68,     1,   224,   185,   214,   225,   223,   191,   557,   225,
     213,    79,   225,     1,   191,   225,   159,   160,   118,    19,
     163,   164,   165,   166,   167,   168,   169,   211,   211,   226,
     118,   176,   226,   140,   211,   226,   225,   105,     1,   225,
       3,   109,     5,   225,   225,   224,    34,    35,   225,   117,
     118,    51,     1,   121,   122,    43,    19,   118,   201,   202,
      48,    49,    50,   225,     1,   208,   209,   226,   213,   226,
      19,   226,   172,   226,   217,   211,   219,   226,    78,   226,
     225,   225,   225,   183,    72,    73,    74,    75,    51,   225,
     224,     1,   192,   642,   118,   226,   645,   226,   647,    87,
      88,    89,    51,   652,    67,    20,    69,   214,   226,    97,
      98,    99,   226,   101,   102,    78,   226,    81,   118,    83,
     226,   670,    37,   211,   226,   225,   214,    90,   226,    78,
      67,   226,   226,   226,   134,   226,   204,   225,   206,    76,
     226,    78,   226,    53,   226,    60,   226,   226,   172,   226,
     211,   226,   226,   214,   226,   118,     1,   225,   176,   183,
     226,   226,   226,   226,   226,   223,   130,   226,   192,   226,
     226,   226,   226,   226,    19,   138,   226,   226,   226,   226,
     226,   226,   146,    93,   226,   134,   226,   226,   226,   226,
     226,   226,   155,   226,   194,   226,   226,   226,   226,   226,
     226,   138,   222,   226,   226,   205,    51,   207,   171,   226,
     174,   175,   161,   226,   214,     1,   226,   226,   218,   226,
     226,   226,   226,     1,   226,   225,   222,   226,     6,     7,
     140,     9,    10,    78,   226,   226,    14,   225,   222,   226,
     203,   226,   205,    21,    22,    23,    24,    25,    26,   226,
     214,   226,   226,    31,    32,    33,   220,   226,    44,   226,
      15,   226,   225,    41,    42,   214,   226,    45,    46,    55,
      56,    57,   187,   118,    60,    61,    54,   224,   193,    65,
      66,   226,   223,   200,   200,   223,   200,  1170,   200,   134,
     223,   223,    70,    71,   223,   223,   223,    52,   223,   200,
       4,   224,   224,   222,    82,   226,   226,    85,    86,   148,
     149,   150,   151,   152,   153,   154,   224,    95,    96,   226,
     226,   226,   226,    27,    28,   103,   104,   226,   106,    84,
     108,   226,   226,   226,   112,   113,    40,   833,   834,   835,
     836,   837,   838,   839,   226,   226,   124,   226,   226,   194,
     226,   129,   226,   131,   132,   133,   226,   226,   136,   226,
     205,   226,   207,   141,   119,   120,   226,   226,   226,   214,
     125,   226,   226,   218,   226,   226,    80,    81,   226,    83,
     226,   159,   160,   224,   223,   163,   164,   165,   166,   167,
     168,   169,   147,   226,     1,   226,   223,   200,   223,   223,
     223,   222,   222,   200,   223,   200,   110,   200,   223,   223,
     114,   200,   200,   223,   223,   223,   223,   223,     1,   123,
       3,   223,     5,   201,   202,   223,   200,   223,   222,    36,
     208,   209,    39,   223,   200,     1,    19,   200,   142,   217,
     144,   219,   146,   200,   199,   224,   223,   200,   200,   200,
     200,    17,    18,   200,   200,   200,   223,   200,   162,   223,
     228,    68,   224,    29,   224,   226,   221,   226,    51,   200,
     226,   175,    79,   177,   222,   229,   180,   226,   182,   143,
     224,    83,   186,   224,    67,   189,    69,   226,   226,   226,
     226,   195,   226,   197,   198,    78,   226,   226,   105,   226,
     226,   226,   109,   226,   226,   226,   226,    90,   212,   226,
     117,   118,    78,   226,   121,   122,   220,   226,   224,    83,
     200,     0,     1,   226,   226,     4,   226,   200,   222,   200,
     200,   224,   223,    99,   100,   118,   222,    16,   200,   222,
      19,   107,   223,   222,   146,   111,   223,   222,   222,    28,
     222,   200,   118,   222,   222,   138,   200,   224,   224,    38,
     126,   127,   128,   226,   224,   224,   224,   222,   170,   226,
     226,   137,   155,   175,    53,   226,   226,   224,   180,    58,
      59,   226,   146,   226,   224,   224,   224,   224,   171,   224,
     156,   224,   224,   195,   224,   197,   198,   204,    77,   206,
     224,   224,    81,   224,   224,   224,   170,   224,   224,   224,
     212,   175,    91,    92,   224,   224,   180,   223,   220,   185,
     203,   224,   205,   224,   224,   223,     1,   226,   223,   223,
     222,   195,   223,   197,   198,   223,   115,   116,   223,   223,
     226,   222,   224,   222,   222,   222,   222,   222,   212,   223,
     222,   130,   222,   222,   222,   200,   220,   224,   223,    34,
      35,   222,   224,   222,   224,   222,   224,   146,    43,   224,
     224,   224,   224,    48,    49,    50,   224,   224,   157,   158,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   173,   224,   224,    72,    73,    74,
      75,   224,   181,   224,   224,   184,   224,   224,   224,   188,
     224,   190,    87,    88,    89,   224,   224,   224,   224,   224,
     224,   224,    97,    98,    99,   224,   101,   102,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   222,   222,   222,   226,   222,
     224,   222,   222,   200,   222,   224,   222,   222,   200,   226,
     224,   222,   224,   222,   222,   222,   226,   222,   222,   222,
     222,   227,   222,   224,   222,   224,   222,    94,   759,   224,
     224,   224,    80,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     222,   224,   226,   224,   222,   222,   222,   222,   228,   519,
     224,   224,   222,   222,   226,   226,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   210,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   146,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   222,   224,   226,   224,
     224,   224,   224,   224,   223,   143,   224,   227,   143,   146,
     227,   227,   227,   227,   227,   226,   224,   143,   224,   224,
     224,   224,   597,   534,  1017,  1214,  1202,  1193,   505,  1200,
    1223,  1112,   610,   484,   550,  1198,  1216,   129,   583,   417,
     188,   104,   495,    -1,    -1,   388,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   407,    -1,   356,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   285,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   231,     0,     1,     4,    16,    19,    28,    38,    53,
      58,    59,    77,    81,    91,    92,   115,   116,   130,   146,
     157,   158,   173,   181,   184,   188,   190,   232,   237,   238,
     242,   257,   263,   269,   277,   290,   307,   329,   343,   356,
     363,   367,   377,   386,   407,   413,   419,   423,   429,   486,
     507,   224,   225,   229,   229,   308,   387,   414,   229,   424,
     229,   344,   408,   330,   222,   226,   264,   291,   357,   229,
     229,   378,   229,   270,   229,   368,     1,    39,    47,   118,
     258,   259,   260,   261,   262,     1,    34,    35,    43,    48,
      49,    50,    72,    73,    74,    75,    87,    88,    89,    97,
      98,    99,   101,   102,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   229,   229,   229,     1,    76,   420,
     421,   422,   229,     1,     6,     7,     9,    10,    14,    21,
      22,    23,    24,    25,    26,    31,    32,    33,    41,    42,
      45,    46,    54,    70,    71,    82,    85,    86,    95,    96,
     103,   104,   106,   108,   112,   113,   124,   129,   131,   132,
     133,   136,   141,   159,   160,   163,   164,   165,   166,   167,
     168,   169,   201,   202,   208,   209,   217,   219,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   229,   229,   229,   227,   239,   222,
     229,   229,   229,     1,    44,    55,    56,    57,    60,    61,
      65,    66,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,     1,    36,    39,    68,    79,   105,   109,   117,
     118,   121,   122,   204,   206,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   229,
       1,   213,   278,   279,   280,   281,   282,   229,     1,   118,
     364,   365,   366,   229,   224,   226,   226,   226,   225,   259,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   225,   488,
       1,    17,    18,    29,    78,    99,   100,   107,   111,   118,
     126,   127,   128,   137,   156,   185,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,     1,     3,     5,    19,    51,    67,    69,
      78,    90,   118,   138,   155,   171,   203,   205,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     403,   404,   405,   406,     1,    76,   140,   415,   416,   417,
     418,   226,   225,   421,     1,   118,   140,   425,   426,   427,
     428,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   225,   431,     1,    19,    51,
      78,   134,   161,   214,   345,   346,   347,   348,   349,   350,
     351,   355,     1,   140,   214,   409,   410,   411,   412,     1,
      67,    76,    78,   138,   331,   335,   336,   337,   341,   342,
      30,   145,   240,   241,   224,   224,     1,    93,   176,   265,
     266,   267,   268,     1,    19,    51,    78,   118,   134,   194,
     205,   207,   214,   218,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,     1,    53,    93,   140,
     358,   359,   360,   361,   362,   226,   226,   226,   226,   226,
     226,   226,   226,   225,   509,   224,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   225,   244,
       1,   118,   211,   379,   380,   381,   382,   224,   226,   225,
     279,   176,     1,   118,   172,   183,   192,   271,   272,   273,
     274,   275,   276,   226,   225,   365,     1,   118,   211,   214,
     369,   370,   371,   372,   373,   222,   222,   222,   224,   223,
     223,   234,   200,   200,   200,   200,   223,   234,   234,   234,
     223,   234,   234,   223,   223,   223,   223,   223,   224,   224,
     226,   226,   226,   326,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   225,   310,   224,   226,   226,
     226,   226,   226,   226,   400,   226,   226,   226,   226,   226,
     226,   226,   225,   389,   226,   226,   225,   416,   222,   224,
     226,   226,   225,   426,   200,   234,   223,   234,   234,   200,
     223,   223,   223,   222,   222,   200,   223,   234,   200,   200,
     223,   223,   200,   234,   200,   234,   223,   223,   223,   223,
     223,   223,   234,   223,   223,   223,   200,   222,   200,   234,
     234,   200,   234,   200,   223,   200,   200,   200,   200,   200,
     200,   200,   223,   234,   234,   234,   200,   223,   224,   224,
     226,   226,   352,   226,   226,   226,   225,   346,   226,   226,
     225,   410,   224,   226,   226,   332,   226,   225,   336,   228,
     224,   226,   226,   225,   266,   224,   226,   226,   304,   226,
     226,   226,   226,   226,   226,   226,   225,   293,   224,   226,
     226,   226,   225,   359,   200,   200,   234,   222,   200,   222,
     200,   200,   224,   223,   222,   200,   222,   223,   223,   222,
     222,   222,   222,   222,   222,   224,   224,   226,   383,   225,
     380,   200,   224,   229,   224,   226,   226,   226,   226,   225,
     272,   222,   224,   224,   226,   374,   226,   225,   370,   224,
     224,   224,   224,   148,   149,   150,   151,   152,   153,   154,
     233,   234,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   223,
     223,   234,   226,   223,   234,   223,   234,   222,   223,   223,
     223,   234,   223,   236,   236,   224,   222,   178,   179,   222,
     200,   222,   222,   226,   222,   222,   223,   222,   222,   234,
     222,   224,   222,   222,   224,   224,   222,   222,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   222,   200,   226,   222,   222,   222,   224,
     222,   222,   224,   222,   222,   226,   223,   339,   340,   224,
     241,   222,   222,   224,   222,   200,   226,   222,   222,   222,
     222,   200,   222,   222,   224,   222,   222,   222,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   222,
     226,   224,   224,     1,   118,   191,   211,   283,   284,   285,
     286,   287,   222,   222,   222,   222,   224,   224,   222,   226,
     222,   224,   233,   233,   233,   233,   233,   233,   233,   224,
     224,   224,    64,   139,   327,   328,   224,   224,   224,   224,
     224,   224,   224,   224,   224,    11,    12,    13,   235,   236,
     224,   224,   224,   224,   224,   224,   224,   224,   224,     8,
     193,   401,   402,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,    15,    52,    84,   119,
     120,   125,   147,   199,   221,   353,   354,   224,   224,   224,
     224,   224,   224,   224,    20,    37,    60,   187,   193,   333,
     334,   210,   228,   338,   224,   224,   224,   224,     4,    27,
      28,    40,    80,    81,    83,   110,   114,   123,   142,   144,
     146,   162,   175,   177,   180,   182,   186,   189,   195,   197,
     198,   212,   220,   305,   306,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,    83,   146,   170,   175,
     180,   195,   197,   198,   212,   220,   384,   385,   224,   226,
     226,   288,   225,   284,   224,   224,   224,   224,   224,    83,
     146,   170,   175,   180,   195,   197,   198,   212,   220,   375,
     376,   224,   224,   228,   235,   235,   235,   224,   228,   224,
     228,   224,   228,   223,   340,   224,   227,   227,   227,   227,
     227,   227,   227,   224,   228,   224,   228,   222,   196,   236,
     226,   224,   224,   228,   328,   402,   354,   334,   143,   146,
     143,    94,   146,   143,   143,   306,   385,   224,   224,   224,
      81,    83,   130,   146,   174,   175,   214,   220,   289,   376,
     224
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   230,   231,   231,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   233,
     233,   234,   234,   234,   234,   234,   234,   234,   234,   235,
     235,   236,   236,   236,   236,   237,   238,   239,   239,   240,
     240,   241,   241,   242,   243,   243,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   258,   259,   259,   259,   259,   260,   261,
     262,   264,   263,   265,   265,   266,   266,   266,   267,   268,
     270,   269,   271,   271,   272,   272,   272,   272,   272,   273,
     274,   275,   276,   277,   278,   278,   279,   279,   279,   280,
     282,   281,   283,   283,   284,   284,   284,   284,   285,   286,
     286,   288,   287,   289,   289,   289,   289,   289,   289,   289,
     289,   291,   290,   292,   292,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   304,   303,   305,   305,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   308,   307,
     309,   309,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   326,   325,   327,   327,   328,   328,   330,   329,
     332,   331,   333,   333,   334,   334,   334,   334,   334,   335,
     335,   336,   336,   336,   336,   336,   338,   337,   339,   339,
     340,   340,   341,   342,   344,   343,   345,   345,   346,   346,
     346,   346,   346,   346,   346,   347,   348,   349,   350,   352,
     351,   353,   353,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   355,   357,   356,   358,   358,   359,   359,   359,
     359,   360,   361,   362,   363,   364,   364,   365,   365,   366,
     368,   367,   369,   369,   370,   370,   370,   370,   371,   372,
     374,   373,   375,   375,   376,   376,   376,   376,   376,   376,
     376,   376,   376,   376,   378,   377,   379,   379,   380,   380,
     380,   381,   383,   382,   384,   384,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   387,   386,   388,   388,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   398,   400,   399,   401,   401,   402,
     402,   403,   404,   405,   406,   408,   407,   409,   409,   410,
     410,   410,   411,   412,   414,   413,   415,   415,   416,   416,
     416,   417,   418,   419,   420,   420,   421,   421,   422,   424,
     423,   425,   425,   426,   426,   426,   427,   428,   429,   430,
     430,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   487,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   508,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   510,   511,   512,   513,   514,   515,   516,   517
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
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
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     4,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4
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
#line 386 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3457 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 387 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3463 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 388 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3469 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 389 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3475 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 390 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3481 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 391 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3487 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 392 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3493 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 393 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3499 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 394 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3505 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 397 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3511 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 398 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3517 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 399 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3523 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3529 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3535 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 409 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3544 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 419 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3553 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 425 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3561 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 432 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3570 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 436 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3579 "conf_parser.c"
    break;

  case 69: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 464 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3591 "conf_parser.c"
    break;

  case 70: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 473 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3603 "conf_parser.c"
    break;

  case 71: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 482 "conf_parser.y"
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
#line 3621 "conf_parser.c"
    break;

  case 72: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 497 "conf_parser.y"
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
#line 3639 "conf_parser.c"
    break;

  case 73: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 512 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3652 "conf_parser.c"
    break;

  case 74: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 522 "conf_parser.y"
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
#line 3669 "conf_parser.c"
    break;

  case 75: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 536 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3681 "conf_parser.c"
    break;

  case 76: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 545 "conf_parser.y"
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
#line 3707 "conf_parser.c"
    break;

  case 77: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 568 "conf_parser.y"
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
#line 3733 "conf_parser.c"
    break;

  case 78: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 591 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigServerInfo.max_topic_length = TOPICLEN;
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3744 "conf_parser.c"
    break;

  case 79: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 599 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3756 "conf_parser.c"
    break;

  case 80: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 608 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3765 "conf_parser.c"
    break;

  case 88: /* admin_name: NAME '=' QSTRING ';'  */
#line 626 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3777 "conf_parser.c"
    break;

  case 89: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 635 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3789 "conf_parser.c"
    break;

  case 90: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 644 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3801 "conf_parser.c"
    break;

  case 91: /* $@1: %empty  */
#line 657 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3810 "conf_parser.c"
    break;

  case 92: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 661 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3827 "conf_parser.c"
    break;

  case 98: /* motd_mask: MASK '=' QSTRING ';'  */
#line 678 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3836 "conf_parser.c"
    break;

  case 99: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 684 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3845 "conf_parser.c"
    break;

  case 100: /* $@2: %empty  */
#line 694 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3854 "conf_parser.c"
    break;

  case 101: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 698 "conf_parser.y"
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
#line 3872 "conf_parser.c"
    break;

  case 109: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 716 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3881 "conf_parser.c"
    break;

  case 110: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 722 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3890 "conf_parser.c"
    break;

  case 111: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 728 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3899 "conf_parser.c"
    break;

  case 112: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 734 "conf_parser.y"
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
#line 3921 "conf_parser.c"
    break;

  case 119: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 763 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 3933 "conf_parser.c"
    break;

  case 120: /* $@3: %empty  */
#line 772 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3942 "conf_parser.c"
    break;

  case 121: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 776 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3955 "conf_parser.c"
    break;

  case 128: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 792 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3966 "conf_parser.c"
    break;

  case 129: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 800 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3974 "conf_parser.c"
    break;

  case 130: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 803 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3982 "conf_parser.c"
    break;

  case 131: /* $@4: %empty  */
#line 808 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3991 "conf_parser.c"
    break;

  case 133: /* logging_file_type_item: USER  */
#line 814 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4000 "conf_parser.c"
    break;

  case 134: /* logging_file_type_item: OPERATOR  */
#line 818 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4009 "conf_parser.c"
    break;

  case 135: /* logging_file_type_item: XLINE  */
#line 822 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4018 "conf_parser.c"
    break;

  case 136: /* logging_file_type_item: RESV  */
#line 826 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4027 "conf_parser.c"
    break;

  case 137: /* logging_file_type_item: T_DLINE  */
#line 830 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4036 "conf_parser.c"
    break;

  case 138: /* logging_file_type_item: KLINE  */
#line 834 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4045 "conf_parser.c"
    break;

  case 139: /* logging_file_type_item: KILL  */
#line 838 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4054 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: T_DEBUG  */
#line 842 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4063 "conf_parser.c"
    break;

  case 141: /* $@5: %empty  */
#line 852 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4075 "conf_parser.c"
    break;

  case 142: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 859 "conf_parser.y"
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
#line 4133 "conf_parser.c"
    break;

  case 156: /* oper_name: NAME '=' QSTRING ';'  */
#line 927 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4142 "conf_parser.c"
    break;

  case 157: /* oper_user: USER '=' QSTRING ';'  */
#line 933 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4151 "conf_parser.c"
    break;

  case 158: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 939 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4160 "conf_parser.c"
    break;

  case 159: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 945 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4169 "conf_parser.c"
    break;

  case 160: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 951 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4183 "conf_parser.c"
    break;

  case 161: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 962 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4192 "conf_parser.c"
    break;

  case 162: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 968 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4206 "conf_parser.c"
    break;

  case 163: /* oper_class: CLASS '=' QSTRING ';'  */
#line 979 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4215 "conf_parser.c"
    break;

  case 164: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 985 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4224 "conf_parser.c"
    break;

  case 165: /* $@6: %empty  */
#line 991 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4233 "conf_parser.c"
    break;

  case 169: /* oper_flags_item: KILL ':' REMOTE  */
#line 998 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4242 "conf_parser.c"
    break;

  case 170: /* oper_flags_item: KILL  */
#line 1002 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4251 "conf_parser.c"
    break;

  case 171: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1006 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4260 "conf_parser.c"
    break;

  case 172: /* oper_flags_item: CONNECT  */
#line 1010 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4269 "conf_parser.c"
    break;

  case 173: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1014 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4278 "conf_parser.c"
    break;

  case 174: /* oper_flags_item: SQUIT  */
#line 1018 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4287 "conf_parser.c"
    break;

  case 175: /* oper_flags_item: KLINE  */
#line 1022 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4296 "conf_parser.c"
    break;

  case 176: /* oper_flags_item: UNKLINE  */
#line 1026 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4305 "conf_parser.c"
    break;

  case 177: /* oper_flags_item: T_DLINE  */
#line 1030 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4314 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: T_UNDLINE  */
#line 1034 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4323 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: XLINE  */
#line 1038 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4332 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: T_UNXLINE  */
#line 1042 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4341 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: DIE  */
#line 1046 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4350 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: T_RESTART  */
#line 1050 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4359 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4368 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: REHASH  */
#line 1058 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4377 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: ADMIN  */
#line 1062 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4386 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_GLOBOPS  */
#line 1066 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4395 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_LOCOPS  */
#line 1070 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4404 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: REMOTEBAN  */
#line 1074 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4413 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_SET  */
#line 1078 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4422 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: MODULE  */
#line 1082 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4431 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_OPME  */
#line 1086 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4440 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: NICK ':' RESV  */
#line 1090 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4449 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: JOIN ':' RESV  */
#line 1094 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4458 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: RESV  */
#line 1098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4467 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_UNRESV  */
#line 1102 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4476 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: CLOSE  */
#line 1106 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4485 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1110 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4494 "conf_parser.c"
    break;

  case 198: /* $@7: %empty  */
#line 1120 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.con_freq.value  = CLASS_DEFAULT_CONNECT_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4510 "conf_parser.c"
    break;

  case 199: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1131 "conf_parser.y"
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
#line 4558 "conf_parser.c"
    break;

  case 218: /* class_name: NAME '=' QSTRING ';'  */
#line 1194 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4567 "conf_parser.c"
    break;

  case 219: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1200 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4576 "conf_parser.c"
    break;

  case 220: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1206 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4585 "conf_parser.c"
    break;

  case 221: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1212 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4594 "conf_parser.c"
    break;

  case 222: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1218 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4603 "conf_parser.c"
    break;

  case 223: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1224 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4612 "conf_parser.c"
    break;

  case 224: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1230 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4621 "conf_parser.c"
    break;

  case 225: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1236 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4630 "conf_parser.c"
    break;

  case 226: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1242 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4640 "conf_parser.c"
    break;

  case 227: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1249 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4649 "conf_parser.c"
    break;

  case 228: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1255 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4658 "conf_parser.c"
    break;

  case 229: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1261 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4667 "conf_parser.c"
    break;

  case 230: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1267 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4679 "conf_parser.c"
    break;

  case 231: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1276 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4691 "conf_parser.c"
    break;

  case 232: /* $@8: %empty  */
#line 1285 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4700 "conf_parser.c"
    break;

  case 236: /* class_flags_item: RANDOM_IDLE  */
#line 1292 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4709 "conf_parser.c"
    break;

  case 237: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1296 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4718 "conf_parser.c"
    break;

  case 238: /* $@9: %empty  */
#line 1306 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4727 "conf_parser.c"
    break;

  case 240: /* $@10: %empty  */
#line 1312 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4735 "conf_parser.c"
    break;

  case 244: /* listen_flags_item: T_TLS  */
#line 1318 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4744 "conf_parser.c"
    break;

  case 245: /* listen_flags_item: HIDDEN  */
#line 1322 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4753 "conf_parser.c"
    break;

  case 246: /* listen_flags_item: T_SERVER  */
#line 1326 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4762 "conf_parser.c"
    break;

  case 247: /* listen_flags_item: CLIENT  */
#line 1330 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4771 "conf_parser.c"
    break;

  case 248: /* listen_flags_item: DEFER  */
#line 1334 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4780 "conf_parser.c"
    break;

  case 256: /* $@11: %empty  */
#line 1342 "conf_parser.y"
                                 { reset_block_state(); }
#line 4786 "conf_parser.c"
    break;

  case 260: /* port_item: NUMBER  */
#line 1347 "conf_parser.y"
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
#line 4804 "conf_parser.c"
    break;

  case 261: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1360 "conf_parser.y"
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
#line 4824 "conf_parser.c"
    break;

  case 262: /* listen_address: IP '=' QSTRING ';'  */
#line 1377 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4833 "conf_parser.c"
    break;

  case 263: /* listen_host: HOST '=' QSTRING ';'  */
#line 1383 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4842 "conf_parser.c"
    break;

  case 264: /* $@12: %empty  */
#line 1393 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4851 "conf_parser.c"
    break;

  case 265: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1397 "conf_parser.y"
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
#line 4898 "conf_parser.c"
    break;

  case 275: /* auth_user: USER '=' QSTRING ';'  */
#line 1450 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4907 "conf_parser.c"
    break;

  case 276: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1456 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4916 "conf_parser.c"
    break;

  case 277: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1462 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4925 "conf_parser.c"
    break;

  case 278: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1468 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4939 "conf_parser.c"
    break;

  case 279: /* $@13: %empty  */
#line 1479 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4948 "conf_parser.c"
    break;

  case 283: /* auth_flags_item: EXCEED_LIMIT  */
#line 1486 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4957 "conf_parser.c"
    break;

  case 284: /* auth_flags_item: KLINE_EXEMPT  */
#line 1490 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4966 "conf_parser.c"
    break;

  case 285: /* auth_flags_item: XLINE_EXEMPT  */
#line 1494 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4975 "conf_parser.c"
    break;

  case 286: /* auth_flags_item: NEED_IDENT  */
#line 1498 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4984 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: CAN_FLOOD  */
#line 1502 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4993 "conf_parser.c"
    break;

  case 288: /* auth_flags_item: NO_TILDE  */
#line 1506 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 5002 "conf_parser.c"
    break;

  case 289: /* auth_flags_item: RESV_EXEMPT  */
#line 1510 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 5011 "conf_parser.c"
    break;

  case 290: /* auth_flags_item: T_WEBIRC  */
#line 1514 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 5020 "conf_parser.c"
    break;

  case 291: /* auth_flags_item: NEED_PASSWORD  */
#line 1518 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 5029 "conf_parser.c"
    break;

  case 292: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1524 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
  {
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
    block_state.flags.value |= CONF_FLAGS_SPOOF_IP;
  }
  else
    log_write(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 5046 "conf_parser.c"
    break;

  case 293: /* $@14: %empty  */
#line 1542 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5058 "conf_parser.c"
    break;

  case 294: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1549 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5069 "conf_parser.c"
    break;

  case 301: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1560 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5078 "conf_parser.c"
    break;

  case 302: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1566 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5087 "conf_parser.c"
    break;

  case 303: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1572 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5096 "conf_parser.c"
    break;

  case 309: /* service_name: NAME '=' QSTRING ';'  */
#line 1587 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5111 "conf_parser.c"
    break;

  case 310: /* $@15: %empty  */
#line 1603 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5127 "conf_parser.c"
    break;

  case 311: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1614 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5142 "conf_parser.c"
    break;

  case 318: /* shared_name: NAME '=' QSTRING ';'  */
#line 1629 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5151 "conf_parser.c"
    break;

  case 319: /* shared_user: USER '=' QSTRING ';'  */
#line 1635 "conf_parser.y"
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
#line 5173 "conf_parser.c"
    break;

  case 320: /* $@16: %empty  */
#line 1654 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5182 "conf_parser.c"
    break;

  case 324: /* shared_type_item: KLINE  */
#line 1661 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5191 "conf_parser.c"
    break;

  case 325: /* shared_type_item: UNKLINE  */
#line 1665 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5200 "conf_parser.c"
    break;

  case 326: /* shared_type_item: T_DLINE  */
#line 1669 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5209 "conf_parser.c"
    break;

  case 327: /* shared_type_item: T_UNDLINE  */
#line 1673 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5218 "conf_parser.c"
    break;

  case 328: /* shared_type_item: XLINE  */
#line 1677 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5227 "conf_parser.c"
    break;

  case 329: /* shared_type_item: T_UNXLINE  */
#line 1681 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5236 "conf_parser.c"
    break;

  case 330: /* shared_type_item: RESV  */
#line 1685 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5245 "conf_parser.c"
    break;

  case 331: /* shared_type_item: T_UNRESV  */
#line 1689 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5254 "conf_parser.c"
    break;

  case 332: /* shared_type_item: T_LOCOPS  */
#line 1693 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5263 "conf_parser.c"
    break;

  case 333: /* shared_type_item: T_ALL  */
#line 1697 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5272 "conf_parser.c"
    break;

  case 334: /* $@17: %empty  */
#line 1707 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5286 "conf_parser.c"
    break;

  case 335: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1716 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5299 "conf_parser.c"
    break;

  case 341: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1729 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5308 "conf_parser.c"
    break;

  case 342: /* $@18: %empty  */
#line 1735 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5317 "conf_parser.c"
    break;

  case 346: /* cluster_type_item: KLINE  */
#line 1742 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5326 "conf_parser.c"
    break;

  case 347: /* cluster_type_item: UNKLINE  */
#line 1746 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5335 "conf_parser.c"
    break;

  case 348: /* cluster_type_item: T_DLINE  */
#line 1750 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5344 "conf_parser.c"
    break;

  case 349: /* cluster_type_item: T_UNDLINE  */
#line 1754 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5353 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: XLINE  */
#line 1758 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5362 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: T_UNXLINE  */
#line 1762 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5371 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: RESV  */
#line 1766 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5380 "conf_parser.c"
    break;

  case 353: /* cluster_type_item: T_UNRESV  */
#line 1770 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5389 "conf_parser.c"
    break;

  case 354: /* cluster_type_item: T_LOCOPS  */
#line 1774 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5398 "conf_parser.c"
    break;

  case 355: /* cluster_type_item: T_ALL  */
#line 1778 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5407 "conf_parser.c"
    break;

  case 356: /* $@19: %empty  */
#line 1788 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5421 "conf_parser.c"
    break;

  case 357: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1797 "conf_parser.y"
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

  list_concat(&connect->hub_masks, &block_state.hub.list);
  list_concat(&connect->leaf_masks, &block_state.leaf.list);

  if (block_state.bind.buf[0])
    if (!address_from_string(block_state.bind.buf, &connect->bind_addr))
      conf_error_report("Invalid IP address for bind address");

  connect_assign_class(connect, block_state.klass.buf);
  connect_dns_lookup(connect);
}
#line 5469 "conf_parser.c"
    break;

  case 375: /* connect_name: NAME '=' QSTRING ';'  */
#line 1859 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5478 "conf_parser.c"
    break;

  case 376: /* connect_host: HOST '=' QSTRING ';'  */
#line 1865 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5487 "conf_parser.c"
    break;

  case 377: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1871 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5496 "conf_parser.c"
    break;

  case 378: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1877 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5505 "conf_parser.c"
    break;

  case 379: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1883 "conf_parser.y"
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
#line 5521 "conf_parser.c"
    break;

  case 380: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1896 "conf_parser.y"
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
#line 5537 "conf_parser.c"
    break;

  case 381: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1909 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5546 "conf_parser.c"
    break;

  case 382: /* connect_port: PORT '=' NUMBER ';'  */
#line 1915 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5555 "conf_parser.c"
    break;

  case 383: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 1921 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5564 "conf_parser.c"
    break;

  case 384: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 1925 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5573 "conf_parser.c"
    break;

  case 385: /* $@20: %empty  */
#line 1931 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5581 "conf_parser.c"
    break;

  case 389: /* connect_flags_item: AUTOCONN  */
#line 1937 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5590 "conf_parser.c"
    break;

  case 390: /* connect_flags_item: T_TLS  */
#line 1941 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5599 "conf_parser.c"
    break;

  case 391: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1947 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5613 "conf_parser.c"
    break;

  case 392: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 1958 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5622 "conf_parser.c"
    break;

  case 393: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 1964 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5631 "conf_parser.c"
    break;

  case 394: /* connect_class: CLASS '=' QSTRING ';'  */
#line 1970 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5640 "conf_parser.c"
    break;

  case 395: /* $@21: %empty  */
#line 1980 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5649 "conf_parser.c"
    break;

  case 396: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 1984 "conf_parser.y"
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
#line 5672 "conf_parser.c"
    break;

  case 402: /* kill_user: USER '=' QSTRING ';'  */
#line 2007 "conf_parser.y"
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
#line 5695 "conf_parser.c"
    break;

  case 403: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2027 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5704 "conf_parser.c"
    break;

  case 404: /* $@22: %empty  */
#line 2037 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5713 "conf_parser.c"
    break;

  case 405: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2041 "conf_parser.y"
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
#line 5737 "conf_parser.c"
    break;

  case 411: /* deny_ip: IP '=' QSTRING ';'  */
#line 2065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5746 "conf_parser.c"
    break;

  case 412: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2071 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5755 "conf_parser.c"
    break;

  case 418: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2086 "conf_parser.y"
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
#line 5772 "conf_parser.c"
    break;

  case 419: /* $@23: %empty  */
#line 2104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5781 "conf_parser.c"
    break;

  case 420: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2108 "conf_parser.y"
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
#line 5801 "conf_parser.c"
    break;

  case 426: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2128 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5810 "conf_parser.c"
    break;

  case 427: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2134 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5819 "conf_parser.c"
    break;

  case 486: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2204 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5827 "conf_parser.c"
    break;

  case 487: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2209 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5835 "conf_parser.c"
    break;

  case 488: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2214 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5843 "conf_parser.c"
    break;

  case 489: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2219 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5851 "conf_parser.c"
    break;

  case 490: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2224 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5859 "conf_parser.c"
    break;

  case 491: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2229 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5867 "conf_parser.c"
    break;

  case 492: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2234 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5875 "conf_parser.c"
    break;

  case 493: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2239 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5883 "conf_parser.c"
    break;

  case 494: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2244 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5891 "conf_parser.c"
    break;

  case 495: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2249 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5899 "conf_parser.c"
    break;

  case 496: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2254 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5907 "conf_parser.c"
    break;

  case 497: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2259 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5915 "conf_parser.c"
    break;

  case 498: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2264 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5923 "conf_parser.c"
    break;

  case 499: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2269 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5931 "conf_parser.c"
    break;

  case 500: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2274 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5939 "conf_parser.c"
    break;

  case 501: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2279 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 5950 "conf_parser.c"
    break;

  case 502: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2287 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5958 "conf_parser.c"
    break;

  case 503: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2292 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5966 "conf_parser.c"
    break;

  case 504: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2297 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5974 "conf_parser.c"
    break;

  case 505: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2302 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5982 "conf_parser.c"
    break;

  case 506: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2307 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5990 "conf_parser.c"
    break;

  case 507: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2312 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5998 "conf_parser.c"
    break;

  case 508: /* general_stats_m_oper_only: STATS_M_OPER_ONLY '=' TBOOL ';'  */
#line 2317 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 6006 "conf_parser.c"
    break;

  case 509: /* general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'  */
#line 2322 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 6014 "conf_parser.c"
    break;

  case 510: /* general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'  */
#line 2327 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 6022 "conf_parser.c"
    break;

  case 511: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2332 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6030 "conf_parser.c"
    break;

  case 512: /* general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'  */
#line 2337 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 6038 "conf_parser.c"
    break;

  case 513: /* general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'  */
#line 2342 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 6046 "conf_parser.c"
    break;

  case 514: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2347 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6054 "conf_parser.c"
    break;

  case 515: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2352 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6062 "conf_parser.c"
    break;

  case 516: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2357 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6070 "conf_parser.c"
    break;

  case 517: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2362 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6078 "conf_parser.c"
    break;

  case 518: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2367 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6086 "conf_parser.c"
    break;

  case 519: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2372 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6094 "conf_parser.c"
    break;

  case 520: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2377 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6102 "conf_parser.c"
    break;

  case 521: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2382 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6110 "conf_parser.c"
    break;

  case 522: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2387 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6118 "conf_parser.c"
    break;

  case 523: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2392 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6126 "conf_parser.c"
    break;

  case 524: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2397 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6134 "conf_parser.c"
    break;

  case 525: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2402 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6142 "conf_parser.c"
    break;

  case 526: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2407 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6150 "conf_parser.c"
    break;

  case 527: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2412 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6162 "conf_parser.c"
    break;

  case 528: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2421 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6170 "conf_parser.c"
    break;

  case 529: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2426 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6178 "conf_parser.c"
    break;

  case 530: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2431 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6186 "conf_parser.c"
    break;

  case 531: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2436 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6194 "conf_parser.c"
    break;

  case 532: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2441 "conf_parser.y"
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
#line 6214 "conf_parser.c"
    break;

  case 533: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2458 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6225 "conf_parser.c"
    break;

  case 534: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2466 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6236 "conf_parser.c"
    break;

  case 535: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2474 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6247 "conf_parser.c"
    break;

  case 536: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2482 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6260 "conf_parser.c"
    break;

  case 537: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2492 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6273 "conf_parser.c"
    break;

  case 538: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2502 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6284 "conf_parser.c"
    break;

  case 539: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2510 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6292 "conf_parser.c"
    break;

  case 562: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2542 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6300 "conf_parser.c"
    break;

  case 563: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2547 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6309 "conf_parser.c"
    break;

  case 564: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2553 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6318 "conf_parser.c"
    break;

  case 565: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2559 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6326 "conf_parser.c"
    break;

  case 566: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2564 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6334 "conf_parser.c"
    break;

  case 567: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2569 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6342 "conf_parser.c"
    break;

  case 568: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2574 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6350 "conf_parser.c"
    break;

  case 569: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2579 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6358 "conf_parser.c"
    break;

  case 570: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2584 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6366 "conf_parser.c"
    break;

  case 571: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2589 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6374 "conf_parser.c"
    break;

  case 572: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2594 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6382 "conf_parser.c"
    break;

  case 573: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2599 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6390 "conf_parser.c"
    break;

  case 574: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2604 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6398 "conf_parser.c"
    break;

  case 575: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2609 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6406 "conf_parser.c"
    break;

  case 576: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2614 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6414 "conf_parser.c"
    break;

  case 577: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2619 "conf_parser.y"
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
#line 6440 "conf_parser.c"
    break;

  case 578: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2642 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6448 "conf_parser.c"
    break;

  case 579: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2647 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6456 "conf_parser.c"
    break;

  case 592: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2669 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6465 "conf_parser.c"
    break;

  case 593: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2675 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6479 "conf_parser.c"
    break;

  case 594: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2686 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6491 "conf_parser.c"
    break;

  case 595: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2695 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6500 "conf_parser.c"
    break;

  case 596: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2701 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6509 "conf_parser.c"
    break;

  case 597: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2707 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6518 "conf_parser.c"
    break;

  case 598: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2713 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6530 "conf_parser.c"
    break;

  case 599: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2722 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6539 "conf_parser.c"
    break;


#line 6543 "conf_parser.c"

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

