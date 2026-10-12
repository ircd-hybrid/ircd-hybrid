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
#include "conf_auth.h"
#include "conf_class.h"
#include "conf_cluster.h"
#include "conf_connect.h"
#include "conf_deny.h"
#include "conf_exempt.h"
#include "conf_gecos.h"
#include "conf_kill.h"
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


#line 192 "conf_parser.c"

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
    ENCRYPTED = 303,               /* ENCRYPTED  */
    EXCEED_LIMIT = 304,            /* EXCEED_LIMIT  */
    EXEMPT = 305,                  /* EXEMPT  */
    FLATTEN_LINKS = 306,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 307,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 308,      /* FLATTEN_LINKS_FILE  */
    GECOS = 309,                   /* GECOS  */
    GENERAL = 310,                 /* GENERAL  */
    HIDDEN = 311,                  /* HIDDEN  */
    HIDDEN_NAME = 312,             /* HIDDEN_NAME  */
    HIDE_CHANS = 313,              /* HIDE_CHANS  */
    HIDE_IDLE = 314,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 315,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVERS = 316,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 317,           /* HIDE_SERVICES  */
    HOST = 318,                    /* HOST  */
    HUB = 319,                     /* HUB  */
    HUB_MASK = 320,                /* HUB_MASK  */
    IDENT_TIMEOUT = 321,           /* IDENT_TIMEOUT  */
    INVISIBLE_ON_CONNECT = 322,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 323,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 324,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 325,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 326,      /* INVITE_EXPIRE_TIME  */
    IP = 327,                      /* IP  */
    IRCD_AUTH = 328,               /* IRCD_AUTH  */
    IRCD_FLAGS = 329,              /* IRCD_FLAGS  */
    IRCD_SID = 330,                /* IRCD_SID  */
    JOIN = 331,                    /* JOIN  */
    KILL = 332,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 333,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 334,                   /* KLINE  */
    KLINE_EXEMPT = 335,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 336,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 337,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 338,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 339,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 340,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 341,               /* LEAF_MASK  */
    LISTEN = 342,                  /* LISTEN  */
    LOADMODULE = 343,              /* LOADMODULE  */
    MASK = 344,                    /* MASK  */
    MASS = 345,                    /* MASS  */
    MAX_ACCEPT = 346,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 347,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 348,                /* MAX_BANS  */
    MAX_BANS_LARGE = 349,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 350,            /* MAX_CHANNELS  */
    MAX_IDLE = 351,                /* MAX_IDLE  */
    MAX_INVITES = 352,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 353,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 354,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 355,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 356,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 357,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 358,              /* MAX_NUMBER  */
    MAX_TARGETS = 359,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 360,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 361,                 /* MESSAGE  */
    MIN_IDLE = 362,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 363,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 364,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 365,                  /* MODULE  */
    MODULE_BASE_PATH = 366,        /* MODULE_BASE_PATH  */
    MOTD = 367,                    /* MOTD  */
    MOTD_FILE = 368,               /* MOTD_FILE  */
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
    OPER_UMODES = 380,             /* OPER_UMODES  */
    OPERATOR = 381,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 382,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 383,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 384,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 385,                /* PASSWORD  */
    PATH = 386,                    /* PATH  */
    PING_COOKIE = 387,             /* PING_COOKIE  */
    PING_TIME = 388,               /* PING_TIME  */
    PORT = 389,                    /* PORT  */
    RANDOM_IDLE = 390,             /* RANDOM_IDLE  */
    REASON = 391,                  /* REASON  */
    REGISTRATION_TIMEOUT = 392,    /* REGISTRATION_TIMEOUT  */
    REHASH = 393,                  /* REHASH  */
    REMOTE = 394,                  /* REMOTE  */
    REMOTEBAN = 395,               /* REMOTEBAN  */
    RESIDENT = 396,                /* RESIDENT  */
    RESV = 397,                    /* RESV  */
    RESV_EXEMPT = 398,             /* RESV_EXEMPT  */
    SECONDS = 399,                 /* SECONDS  */
    MINUTES = 400,                 /* MINUTES  */
    HOURS = 401,                   /* HOURS  */
    DAYS = 402,                    /* DAYS  */
    WEEKS = 403,                   /* WEEKS  */
    MONTHS = 404,                  /* MONTHS  */
    YEARS = 405,                   /* YEARS  */
    SEND_PASSWORD = 406,           /* SEND_PASSWORD  */
    SENDQ = 407,                   /* SENDQ  */
    SERVERHIDE = 408,              /* SERVERHIDE  */
    SERVERINFO = 409,              /* SERVERINFO  */
    SHORT_MOTD = 410,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 411,       /* SPECIALS_IN_IDENT  */
    SPOOF = 412,                   /* SPOOF  */
    SQUIT = 413,                   /* SQUIT  */
    STATS_E_DISABLED = 414,        /* STATS_E_DISABLED  */
    STATS_U_OPER_ONLY = 415,       /* STATS_U_OPER_ONLY  */
    T_ALL = 416,                   /* T_ALL  */
    T_BIND = 417,                  /* T_BIND  */
    T_COMMAND = 418,               /* T_COMMAND  */
    T_CLUSTER = 419,               /* T_CLUSTER  */
    T_DEBUG = 420,                 /* T_DEBUG  */
    T_DLINE = 421,                 /* T_DLINE  */
    T_FILE = 422,                  /* T_FILE  */
    T_GLOBOPS = 423,               /* T_GLOBOPS  */
    T_IPV4 = 424,                  /* T_IPV4  */
    T_IPV6 = 425,                  /* T_IPV6  */
    T_LOCOPS = 426,                /* T_LOCOPS  */
    T_LOG = 427,                   /* T_LOG  */
    T_OPME = 428,                  /* T_OPME  */
    T_PREPEND = 429,               /* T_PREPEND  */
    T_PSEUDO = 430,                /* T_PSEUDO  */
    T_RECVQ = 431,                 /* T_RECVQ  */
    T_RESTART = 432,               /* T_RESTART  */
    T_SERVER = 433,                /* T_SERVER  */
    T_SERVICE = 434,               /* T_SERVICE  */
    T_SET = 435,                   /* T_SET  */
    T_SHARED = 436,                /* T_SHARED  */
    T_SIZE = 437,                  /* T_SIZE  */
    T_TARGET = 438,                /* T_TARGET  */
    T_TLS = 439,                   /* T_TLS  */
    T_UMODES = 440,                /* T_UMODES  */
    T_UNDLINE = 441,               /* T_UNDLINE  */
    T_UNLIMITED = 442,             /* T_UNLIMITED  */
    T_UNRESV = 443,                /* T_UNRESV  */
    T_UNXLINE = 444,               /* T_UNXLINE  */
    T_WEBIRC = 445,                /* T_WEBIRC  */
    TBOOL = 446,                   /* TBOOL  */
    THROTTLE_COUNT = 447,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 448,           /* THROTTLE_TIME  */
    TIMEOUT = 449,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 450,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 451, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 452,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 453, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 454,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 455,           /* TS_WARN_DELTA  */
    TWODOTS = 456,                 /* TWODOTS  */
    TYPE = 457,                    /* TYPE  */
    UNKLINE = 458,                 /* UNKLINE  */
    USE_LOGGING = 459,             /* USE_LOGGING  */
    USER = 460,                    /* USER  */
    VHOST = 461,                   /* VHOST  */
    VHOST6 = 462,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 463,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 464,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 465,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 466,                   /* XLINE  */
    XLINE_EXEMPT = 467,            /* XLINE_EXEMPT  */
    QSTRING = 468,                 /* QSTRING  */
    NUMBER = 469                   /* NUMBER  */
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
#define ENCRYPTED 303
#define EXCEED_LIMIT 304
#define EXEMPT 305
#define FLATTEN_LINKS 306
#define FLATTEN_LINKS_DELAY 307
#define FLATTEN_LINKS_FILE 308
#define GECOS 309
#define GENERAL 310
#define HIDDEN 311
#define HIDDEN_NAME 312
#define HIDE_CHANS 313
#define HIDE_IDLE 314
#define HIDE_IDLE_FROM_OPERS 315
#define HIDE_SERVERS 316
#define HIDE_SERVICES 317
#define HOST 318
#define HUB 319
#define HUB_MASK 320
#define IDENT_TIMEOUT 321
#define INVISIBLE_ON_CONNECT 322
#define INVITE_CLIENT_COUNT 323
#define INVITE_CLIENT_TIME 324
#define INVITE_DELAY_CHANNEL 325
#define INVITE_EXPIRE_TIME 326
#define IP 327
#define IRCD_AUTH 328
#define IRCD_FLAGS 329
#define IRCD_SID 330
#define JOIN 331
#define KILL 332
#define KILL_CHASE_TIME_LIMIT 333
#define KLINE 334
#define KLINE_EXEMPT 335
#define KLINE_MIN_CIDR 336
#define KLINE_MIN_CIDR6 337
#define KNOCK_CLIENT_COUNT 338
#define KNOCK_CLIENT_TIME 339
#define KNOCK_DELAY_CHANNEL 340
#define LEAF_MASK 341
#define LISTEN 342
#define LOADMODULE 343
#define MASK 344
#define MASS 345
#define MAX_ACCEPT 346
#define MAX_AWAY_LENGTH 347
#define MAX_BANS 348
#define MAX_BANS_LARGE 349
#define MAX_CHANNELS 350
#define MAX_IDLE 351
#define MAX_INVITES 352
#define MAX_KICK_LENGTH 353
#define MAX_MONITOR 354
#define MAX_NICK_CHANGES 355
#define MAX_NICK_LENGTH 356
#define MAX_NICK_TIME 357
#define MAX_NUMBER 358
#define MAX_TARGETS 359
#define MAX_TOPIC_LENGTH 360
#define MESSAGE 361
#define MIN_IDLE 362
#define MIN_NONWILDCARD 363
#define MIN_NONWILDCARD_SIMPLE 364
#define MODULE 365
#define MODULE_BASE_PATH 366
#define MOTD 367
#define MOTD_FILE 368
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
#define OPER_UMODES 380
#define OPERATOR 381
#define OPERS_BYPASS_CALLERID 382
#define PACE_WAIT 383
#define PACE_WAIT_SIMPLE 384
#define PASSWORD 385
#define PATH 386
#define PING_COOKIE 387
#define PING_TIME 388
#define PORT 389
#define RANDOM_IDLE 390
#define REASON 391
#define REGISTRATION_TIMEOUT 392
#define REHASH 393
#define REMOTE 394
#define REMOTEBAN 395
#define RESIDENT 396
#define RESV 397
#define RESV_EXEMPT 398
#define SECONDS 399
#define MINUTES 400
#define HOURS 401
#define DAYS 402
#define WEEKS 403
#define MONTHS 404
#define YEARS 405
#define SEND_PASSWORD 406
#define SENDQ 407
#define SERVERHIDE 408
#define SERVERINFO 409
#define SHORT_MOTD 410
#define SPECIALS_IN_IDENT 411
#define SPOOF 412
#define SQUIT 413
#define STATS_E_DISABLED 414
#define STATS_U_OPER_ONLY 415
#define T_ALL 416
#define T_BIND 417
#define T_COMMAND 418
#define T_CLUSTER 419
#define T_DEBUG 420
#define T_DLINE 421
#define T_FILE 422
#define T_GLOBOPS 423
#define T_IPV4 424
#define T_IPV6 425
#define T_LOCOPS 426
#define T_LOG 427
#define T_OPME 428
#define T_PREPEND 429
#define T_PSEUDO 430
#define T_RECVQ 431
#define T_RESTART 432
#define T_SERVER 433
#define T_SERVICE 434
#define T_SET 435
#define T_SHARED 436
#define T_SIZE 437
#define T_TARGET 438
#define T_TLS 439
#define T_UMODES 440
#define T_UNDLINE 441
#define T_UNLIMITED 442
#define T_UNRESV 443
#define T_UNXLINE 444
#define T_WEBIRC 445
#define TBOOL 446
#define THROTTLE_COUNT 447
#define THROTTLE_TIME 448
#define TIMEOUT 449
#define TLS_CERTIFICATE_FILE 450
#define TLS_CERTIFICATE_FINGERPRINT 451
#define TLS_PRIVATE_KEY_FILE 452
#define TLS_CONNECTION_REQUIRED 453
#define TS_MAX_DELTA 454
#define TS_WARN_DELTA 455
#define TWODOTS 456
#define TYPE 457
#define UNKLINE 458
#define USE_LOGGING 459
#define USER 460
#define VHOST 461
#define VHOST6 462
#define WARN_NO_CONNECT_BLOCK 463
#define WHOIS 464
#define WHOWAS_HISTORY_LENGTH 465
#define XLINE 466
#define XLINE_EXEMPT 467
#define QSTRING 468
#define NUMBER 469

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 678 "conf_parser.c"

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
  YYSYMBOL_ENCRYPTED = 48,                 /* ENCRYPTED  */
  YYSYMBOL_EXCEED_LIMIT = 49,              /* EXCEED_LIMIT  */
  YYSYMBOL_EXEMPT = 50,                    /* EXEMPT  */
  YYSYMBOL_FLATTEN_LINKS = 51,             /* FLATTEN_LINKS  */
  YYSYMBOL_FLATTEN_LINKS_DELAY = 52,       /* FLATTEN_LINKS_DELAY  */
  YYSYMBOL_FLATTEN_LINKS_FILE = 53,        /* FLATTEN_LINKS_FILE  */
  YYSYMBOL_GECOS = 54,                     /* GECOS  */
  YYSYMBOL_GENERAL = 55,                   /* GENERAL  */
  YYSYMBOL_HIDDEN = 56,                    /* HIDDEN  */
  YYSYMBOL_HIDDEN_NAME = 57,               /* HIDDEN_NAME  */
  YYSYMBOL_HIDE_CHANS = 58,                /* HIDE_CHANS  */
  YYSYMBOL_HIDE_IDLE = 59,                 /* HIDE_IDLE  */
  YYSYMBOL_HIDE_IDLE_FROM_OPERS = 60,      /* HIDE_IDLE_FROM_OPERS  */
  YYSYMBOL_HIDE_SERVERS = 61,              /* HIDE_SERVERS  */
  YYSYMBOL_HIDE_SERVICES = 62,             /* HIDE_SERVICES  */
  YYSYMBOL_HOST = 63,                      /* HOST  */
  YYSYMBOL_HUB = 64,                       /* HUB  */
  YYSYMBOL_HUB_MASK = 65,                  /* HUB_MASK  */
  YYSYMBOL_IDENT_TIMEOUT = 66,             /* IDENT_TIMEOUT  */
  YYSYMBOL_INVISIBLE_ON_CONNECT = 67,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 68,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 69,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 70,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 71,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 72,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 73,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 74,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 75,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 76,                      /* JOIN  */
  YYSYMBOL_KILL = 77,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 78,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 79,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 80,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 81,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 82,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 83,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 84,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 85,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 86,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 87,                    /* LISTEN  */
  YYSYMBOL_LOADMODULE = 88,                /* LOADMODULE  */
  YYSYMBOL_MASK = 89,                      /* MASK  */
  YYSYMBOL_MASS = 90,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 91,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_AWAY_LENGTH = 92,           /* MAX_AWAY_LENGTH  */
  YYSYMBOL_MAX_BANS = 93,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 94,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 95,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 96,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 97,               /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 98,           /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 99,               /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 100,         /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 101,          /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 102,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 103,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 104,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 105,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 106,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 107,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 108,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 109,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 110,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 111,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 112,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 113,                /* MOTD_FILE  */
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
  YYSYMBOL_OPER_UMODES = 125,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 126,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 127,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 128,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 129,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 130,                 /* PASSWORD  */
  YYSYMBOL_PATH = 131,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 132,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 133,                /* PING_TIME  */
  YYSYMBOL_PORT = 134,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 135,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 136,                   /* REASON  */
  YYSYMBOL_REGISTRATION_TIMEOUT = 137,     /* REGISTRATION_TIMEOUT  */
  YYSYMBOL_REHASH = 138,                   /* REHASH  */
  YYSYMBOL_REMOTE = 139,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 140,                /* REMOTEBAN  */
  YYSYMBOL_RESIDENT = 141,                 /* RESIDENT  */
  YYSYMBOL_RESV = 142,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 143,              /* RESV_EXEMPT  */
  YYSYMBOL_SECONDS = 144,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 145,                  /* MINUTES  */
  YYSYMBOL_HOURS = 146,                    /* HOURS  */
  YYSYMBOL_DAYS = 147,                     /* DAYS  */
  YYSYMBOL_WEEKS = 148,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 149,                   /* MONTHS  */
  YYSYMBOL_YEARS = 150,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 151,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 152,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 153,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 154,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 155,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 156,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 157,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 158,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 159,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_U_OPER_ONLY = 160,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 161,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 162,                   /* T_BIND  */
  YYSYMBOL_T_COMMAND = 163,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 164,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 165,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 166,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 167,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 168,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 169,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 170,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 171,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 172,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 173,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 174,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 175,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 176,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 177,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 178,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 179,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 180,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 181,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 182,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 183,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 184,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 185,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 186,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 187,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 188,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 189,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 190,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 191,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 192,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 193,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 194,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 195,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 196, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_PRIVATE_KEY_FILE = 197,     /* TLS_PRIVATE_KEY_FILE  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 198,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TS_MAX_DELTA = 199,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 200,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 201,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 202,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 203,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 204,              /* USE_LOGGING  */
  YYSYMBOL_USER = 205,                     /* USER  */
  YYSYMBOL_VHOST = 206,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 207,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 208,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 209,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 210,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 211,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 212,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 213,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 214,                   /* NUMBER  */
  YYSYMBOL_215_ = 215,                     /* ';'  */
  YYSYMBOL_216_ = 216,                     /* '}'  */
  YYSYMBOL_217_ = 217,                     /* '='  */
  YYSYMBOL_218_ = 218,                     /* ':'  */
  YYSYMBOL_219_ = 219,                     /* ','  */
  YYSYMBOL_220_ = 220,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 221,                 /* $accept  */
  YYSYMBOL_conf = 222,                     /* conf  */
  YYSYMBOL_conf_item = 223,                /* conf_item  */
  YYSYMBOL_timespec_ = 224,                /* timespec_  */
  YYSYMBOL_timespec = 225,                 /* timespec  */
  YYSYMBOL_sizespec_ = 226,                /* sizespec_  */
  YYSYMBOL_sizespec = 227,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 228,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 229,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 230,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 231,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 232,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 233,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 234,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 235,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 236, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_tls_private_key_file = 237, /* serverinfo_tls_private_key_file  */
  YYSYMBOL_serverinfo_name = 238,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 239,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 240,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 241,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 242, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 243, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 244, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 245, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_motd_file = 246,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 247,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 248,              /* admin_entry  */
  YYSYMBOL_admin_items = 249,              /* admin_items  */
  YYSYMBOL_admin_item = 250,               /* admin_item  */
  YYSYMBOL_admin_name = 251,               /* admin_name  */
  YYSYMBOL_admin_email = 252,              /* admin_email  */
  YYSYMBOL_admin_description = 253,        /* admin_description  */
  YYSYMBOL_motd_entry = 254,               /* motd_entry  */
  YYSYMBOL_255_1 = 255,                    /* $@1  */
  YYSYMBOL_motd_items = 256,               /* motd_items  */
  YYSYMBOL_motd_item = 257,                /* motd_item  */
  YYSYMBOL_motd_mask = 258,                /* motd_mask  */
  YYSYMBOL_motd_file = 259,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 260,             /* pseudo_entry  */
  YYSYMBOL_261_2 = 261,                    /* $@2  */
  YYSYMBOL_pseudo_items = 262,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 263,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 264,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 265,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 266,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 267,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 268,            /* logging_entry  */
  YYSYMBOL_logging_items = 269,            /* logging_items  */
  YYSYMBOL_logging_item = 270,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 271,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 272,       /* logging_file_entry  */
  YYSYMBOL_273_3 = 273,                    /* $@3  */
  YYSYMBOL_logging_file_items = 274,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 275,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 276,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 277,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 278,        /* logging_file_type  */
  YYSYMBOL_279_4 = 279,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 280,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 281,               /* oper_entry  */
  YYSYMBOL_282_5 = 282,                    /* $@5  */
  YYSYMBOL_oper_items = 283,               /* oper_items  */
  YYSYMBOL_oper_item = 284,                /* oper_item  */
  YYSYMBOL_oper_name = 285,                /* oper_name  */
  YYSYMBOL_oper_user = 286,                /* oper_user  */
  YYSYMBOL_oper_password = 287,            /* oper_password  */
  YYSYMBOL_oper_whois = 288,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 289,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 290, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 291, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 292,               /* oper_class  */
  YYSYMBOL_oper_umodes = 293,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 294,               /* oper_flags  */
  YYSYMBOL_295_6 = 295,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 296,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 297,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 298,              /* class_entry  */
  YYSYMBOL_299_7 = 299,                    /* $@7  */
  YYSYMBOL_class_items = 300,              /* class_items  */
  YYSYMBOL_class_item = 301,               /* class_item  */
  YYSYMBOL_class_name = 302,               /* class_name  */
  YYSYMBOL_class_ping_time = 303,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 304, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 305, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 306,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 307,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 308,         /* class_max_number  */
  YYSYMBOL_class_sendq = 309,              /* class_sendq  */
  YYSYMBOL_class_recvq = 310,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 311,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 312,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 313,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 314,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 315,           /* class_max_idle  */
  YYSYMBOL_class_flags = 316,              /* class_flags  */
  YYSYMBOL_317_8 = 317,                    /* $@8  */
  YYSYMBOL_class_flags_items = 318,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 319,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 320,             /* listen_entry  */
  YYSYMBOL_321_9 = 321,                    /* $@9  */
  YYSYMBOL_listen_flags = 322,             /* listen_flags  */
  YYSYMBOL_323_10 = 323,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 324,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 325,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 326,             /* listen_items  */
  YYSYMBOL_listen_item = 327,              /* listen_item  */
  YYSYMBOL_listen_port = 328,              /* listen_port  */
  YYSYMBOL_329_11 = 329,                   /* $@11  */
  YYSYMBOL_port_items = 330,               /* port_items  */
  YYSYMBOL_port_item = 331,                /* port_item  */
  YYSYMBOL_listen_address = 332,           /* listen_address  */
  YYSYMBOL_listen_host = 333,              /* listen_host  */
  YYSYMBOL_auth_entry = 334,               /* auth_entry  */
  YYSYMBOL_335_12 = 335,                   /* $@12  */
  YYSYMBOL_auth_items = 336,               /* auth_items  */
  YYSYMBOL_auth_item = 337,                /* auth_item  */
  YYSYMBOL_auth_user = 338,                /* auth_user  */
  YYSYMBOL_auth_passwd = 339,              /* auth_passwd  */
  YYSYMBOL_auth_class = 340,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 341,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 342,               /* auth_flags  */
  YYSYMBOL_343_13 = 343,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 344,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 345,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 346,               /* auth_spoof  */
  YYSYMBOL_resv_entry = 347,               /* resv_entry  */
  YYSYMBOL_348_14 = 348,                   /* $@14  */
  YYSYMBOL_resv_items = 349,               /* resv_items  */
  YYSYMBOL_resv_item = 350,                /* resv_item  */
  YYSYMBOL_resv_mask = 351,                /* resv_mask  */
  YYSYMBOL_resv_reason = 352,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 353,              /* resv_exempt  */
  YYSYMBOL_service_entry = 354,            /* service_entry  */
  YYSYMBOL_service_items = 355,            /* service_items  */
  YYSYMBOL_service_item = 356,             /* service_item  */
  YYSYMBOL_service_name = 357,             /* service_name  */
  YYSYMBOL_shared_entry = 358,             /* shared_entry  */
  YYSYMBOL_359_15 = 359,                   /* $@15  */
  YYSYMBOL_shared_items = 360,             /* shared_items  */
  YYSYMBOL_shared_item = 361,              /* shared_item  */
  YYSYMBOL_shared_name = 362,              /* shared_name  */
  YYSYMBOL_shared_user = 363,              /* shared_user  */
  YYSYMBOL_shared_type = 364,              /* shared_type  */
  YYSYMBOL_365_16 = 365,                   /* $@16  */
  YYSYMBOL_shared_types = 366,             /* shared_types  */
  YYSYMBOL_shared_type_item = 367,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 368,            /* cluster_entry  */
  YYSYMBOL_369_17 = 369,                   /* $@17  */
  YYSYMBOL_cluster_items = 370,            /* cluster_items  */
  YYSYMBOL_cluster_item = 371,             /* cluster_item  */
  YYSYMBOL_cluster_name = 372,             /* cluster_name  */
  YYSYMBOL_cluster_type = 373,             /* cluster_type  */
  YYSYMBOL_374_18 = 374,                   /* $@18  */
  YYSYMBOL_cluster_types = 375,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 376,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 377,            /* connect_entry  */
  YYSYMBOL_378_19 = 378,                   /* $@19  */
  YYSYMBOL_connect_items = 379,            /* connect_items  */
  YYSYMBOL_connect_item = 380,             /* connect_item  */
  YYSYMBOL_connect_name = 381,             /* connect_name  */
  YYSYMBOL_connect_host = 382,             /* connect_host  */
  YYSYMBOL_connect_timeout = 383,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 384,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 385,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 386,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 387, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 388,             /* connect_port  */
  YYSYMBOL_connect_aftype = 389,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 390,            /* connect_flags  */
  YYSYMBOL_391_20 = 391,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 392,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 393,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 394,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 395,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 396,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 397,            /* connect_class  */
  YYSYMBOL_kill_entry = 398,               /* kill_entry  */
  YYSYMBOL_399_21 = 399,                   /* $@21  */
  YYSYMBOL_kill_items = 400,               /* kill_items  */
  YYSYMBOL_kill_item = 401,                /* kill_item  */
  YYSYMBOL_kill_user = 402,                /* kill_user  */
  YYSYMBOL_kill_reason = 403,              /* kill_reason  */
  YYSYMBOL_deny_entry = 404,               /* deny_entry  */
  YYSYMBOL_405_22 = 405,                   /* $@22  */
  YYSYMBOL_deny_items = 406,               /* deny_items  */
  YYSYMBOL_deny_item = 407,                /* deny_item  */
  YYSYMBOL_deny_ip = 408,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 409,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 410,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 411,             /* exempt_items  */
  YYSYMBOL_exempt_item = 412,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 413,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 414,              /* gecos_entry  */
  YYSYMBOL_415_23 = 415,                   /* $@23  */
  YYSYMBOL_gecos_items = 416,              /* gecos_items  */
  YYSYMBOL_gecos_item = 417,               /* gecos_item  */
  YYSYMBOL_gecos_name = 418,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 419,             /* gecos_reason  */
  YYSYMBOL_general_entry = 420,            /* general_entry  */
  YYSYMBOL_general_items = 421,            /* general_items  */
  YYSYMBOL_general_item = 422,             /* general_item  */
  YYSYMBOL_general_away_count = 423,       /* general_away_count  */
  YYSYMBOL_general_away_time = 424,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 425,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 426, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 427, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 428,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 429,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 430,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 431,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 432, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_anti_nick_flood = 433,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 434,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 435, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 436,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 437,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 438, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 439,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 440,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 441, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 442, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 443, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_u_oper_only = 444, /* general_stats_u_oper_only  */
  YYSYMBOL_general_pace_wait = 445,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 446,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 447, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 448, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 449,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 450,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 451, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 452,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 453,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_ident = 454,    /* general_disable_ident  */
  YYSYMBOL_general_disable_dns = 455,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 456,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 457,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 458,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 459,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 460, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 461, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 462, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 463,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 464, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 465, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 466,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 467,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 468,     /* general_cloak_suffix  */
  YYSYMBOL_general_ident_timeout = 469,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 470, /* general_registration_timeout  */
  YYSYMBOL_channel_entry = 471,            /* channel_entry  */
  YYSYMBOL_channel_items = 472,            /* channel_items  */
  YYSYMBOL_channel_item = 473,             /* channel_item  */
  YYSYMBOL_channel_disable_fake_channels = 474, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 475, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 476, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 477, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 478, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 479, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 480, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 481, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 482,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 483,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 484,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 485,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 486,  /* channel_max_kick_length  */
  YYSYMBOL_channel_default_join_flood_count = 487, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 488, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 489,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 490,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 491,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 492, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 493, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 494, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 495, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 496,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 497, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 498,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 499         /* serverhide_hidden  */
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
#define YYLAST   1156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  221
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  279
/* YYNRULES -- Number of rules.  */
#define YYNRULES  581
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1206

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   469


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
       2,     2,     2,     2,   219,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   218,   215,
       2,   217,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   220,     2,   216,     2,     2,     2,     2,
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
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   349,   349,   350,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   381,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   392,
     392,   393,   394,   395,   396,   403,   413,   420,   422,   424,
     424,   426,   430,   440,   442,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   458,
     467,   476,   491,   506,   516,   530,   539,   562,   585,   593,
     602,   612,   614,   614,   615,   616,   617,   618,   620,   629,
     638,   652,   651,   669,   669,   670,   670,   670,   672,   678,
     689,   688,   707,   707,   708,   708,   708,   708,   708,   710,
     716,   722,   728,   751,   752,   752,   754,   754,   755,   757,
     767,   767,   780,   781,   783,   783,   784,   784,   786,   794,
     797,   803,   802,   808,   812,   816,   820,   824,   828,   832,
     836,   847,   846,   908,   908,   909,   910,   911,   912,   913,
     914,   915,   916,   917,   918,   919,   921,   927,   933,   939,
     945,   956,   962,   973,   979,   986,   985,   991,   991,   992,
     996,  1000,  1004,  1008,  1012,  1016,  1020,  1024,  1028,  1032,
    1036,  1040,  1044,  1048,  1052,  1056,  1060,  1064,  1068,  1072,
    1076,  1080,  1084,  1088,  1092,  1096,  1100,  1104,  1115,  1114,
    1170,  1170,  1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1188,  1194,
    1200,  1206,  1212,  1218,  1224,  1230,  1236,  1243,  1249,  1255,
    1261,  1270,  1280,  1279,  1285,  1285,  1286,  1290,  1301,  1300,
    1307,  1306,  1311,  1311,  1312,  1316,  1320,  1324,  1328,  1334,
    1334,  1335,  1335,  1335,  1335,  1335,  1337,  1337,  1339,  1339,
    1341,  1354,  1371,  1377,  1388,  1387,  1443,  1443,  1444,  1445,
    1446,  1447,  1448,  1449,  1450,  1452,  1458,  1464,  1470,  1482,
    1481,  1487,  1487,  1489,  1493,  1497,  1501,  1505,  1509,  1513,
    1517,  1521,  1527,  1543,  1542,  1557,  1557,  1558,  1558,  1558,
    1558,  1560,  1566,  1572,  1582,  1584,  1584,  1585,  1585,  1587,
    1604,  1603,  1626,  1626,  1627,  1627,  1627,  1627,  1629,  1635,
    1655,  1654,  1660,  1660,  1661,  1665,  1669,  1673,  1677,  1681,
    1685,  1689,  1693,  1697,  1708,  1707,  1726,  1726,  1727,  1727,
    1727,  1729,  1736,  1735,  1741,  1741,  1742,  1746,  1750,  1754,
    1758,  1762,  1766,  1770,  1774,  1778,  1789,  1788,  1842,  1842,
    1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,
    1853,  1854,  1855,  1856,  1857,  1859,  1865,  1871,  1877,  1883,
    1896,  1909,  1915,  1921,  1925,  1932,  1931,  1936,  1936,  1937,
    1941,  1947,  1958,  1964,  1970,  1981,  1980,  2005,  2005,  2006,
    2006,  2006,  2008,  2028,  2039,  2038,  2061,  2061,  2062,  2062,
    2062,  2064,  2070,  2080,  2082,  2082,  2083,  2083,  2085,  2099,
    2098,  2119,  2119,  2120,  2120,  2120,  2122,  2128,  2138,  2140,
    2140,  2141,  2142,  2143,  2144,  2145,  2146,  2147,  2148,  2149,
    2150,  2151,  2152,  2153,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,
    2170,  2171,  2172,  2173,  2174,  2175,  2176,  2177,  2178,  2179,
    2180,  2181,  2182,  2183,  2184,  2185,  2186,  2187,  2188,  2189,
    2192,  2197,  2202,  2207,  2212,  2217,  2222,  2227,  2232,  2237,
    2242,  2247,  2252,  2257,  2262,  2270,  2275,  2280,  2285,  2290,
    2295,  2300,  2305,  2310,  2315,  2320,  2325,  2330,  2335,  2340,
    2345,  2350,  2355,  2360,  2365,  2370,  2379,  2384,  2389,  2394,
    2399,  2416,  2424,  2432,  2440,  2450,  2460,  2468,  2477,  2479,
    2479,  2480,  2481,  2482,  2483,  2484,  2485,  2486,  2487,  2488,
    2489,  2490,  2491,  2492,  2493,  2494,  2495,  2497,  2502,  2507,
    2512,  2517,  2522,  2527,  2532,  2537,  2542,  2547,  2552,  2557,
    2580,  2585,  2594,  2596,  2596,  2597,  2598,  2599,  2600,  2601,
    2602,  2603,  2604,  2605,  2607,  2613,  2624,  2633,  2639,  2645,
    2651,  2660
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
  "DLINE_MIN_CIDR6", "EMAIL", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FLATTEN_LINKS", "FLATTEN_LINKS_DELAY", "FLATTEN_LINKS_FILE", "GECOS",
  "GENERAL", "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
  "HIDE_IDLE_FROM_OPERS", "HIDE_SERVERS", "HIDE_SERVICES", "HOST", "HUB",
  "HUB_MASK", "IDENT_TIMEOUT", "INVISIBLE_ON_CONNECT",
  "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME", "INVITE_DELAY_CHANNEL",
  "INVITE_EXPIRE_TIME", "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID",
  "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6", "KNOCK_CLIENT_COUNT",
  "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LISTEN",
  "LOADMODULE", "MASK", "MASS", "MAX_ACCEPT", "MAX_AWAY_LENGTH",
  "MAX_BANS", "MAX_BANS_LARGE", "MAX_CHANNELS", "MAX_IDLE", "MAX_INVITES",
  "MAX_KICK_LENGTH", "MAX_MONITOR", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH",
  "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH",
  "MESSAGE", "MIN_IDLE", "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE",
  "MODULE", "MODULE_BASE_PATH", "MOTD", "MOTD_FILE", "NAME", "NEED_IDENT",
  "NEED_PASSWORD", "NETWORK_DESCRIPTION", "NETWORK_NAME", "NICK",
  "NO_OPER_FLOOD", "NO_TILDE", "NUMBER_PER_CIDR", "NUMBER_PER_IP_GLOBAL",
  "NUMBER_PER_IP_LOCAL", "OPER_UMODES", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD",
  "PATH", "PING_COOKIE", "PING_TIME", "PORT", "RANDOM_IDLE", "REASON",
  "REGISTRATION_TIMEOUT", "REHASH", "REMOTE", "REMOTEBAN", "RESIDENT",
  "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS",
  "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ", "SERVERHIDE", "SERVERINFO",
  "SHORT_MOTD", "SPECIALS_IN_IDENT", "SPOOF", "SQUIT", "STATS_E_DISABLED",
  "STATS_U_OPER_ONLY", "T_ALL", "T_BIND", "T_COMMAND", "T_CLUSTER",
  "T_DEBUG", "T_DLINE", "T_FILE", "T_GLOBOPS", "T_IPV4", "T_IPV6",
  "T_LOCOPS", "T_LOG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ",
  "T_RESTART", "T_SERVER", "T_SERVICE", "T_SET", "T_SHARED", "T_SIZE",
  "T_TARGET", "T_TLS", "T_UMODES", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV",
  "T_UNXLINE", "T_WEBIRC", "TBOOL", "THROTTLE_COUNT", "THROTTLE_TIME",
  "TIMEOUT", "TLS_CERTIFICATE_FILE", "TLS_CERTIFICATE_FINGERPRINT",
  "TLS_PRIVATE_KEY_FILE", "TLS_CONNECTION_REQUIRED", "TS_MAX_DELTA",
  "TS_WARN_DELTA", "TWODOTS", "TYPE", "UNKLINE", "USE_LOGGING", "USER",
  "VHOST", "VHOST6", "WARN_NO_CONNECT_BLOCK", "WHOIS",
  "WHOWAS_HISTORY_LENGTH", "XLINE", "XLINE_EXEMPT", "QSTRING", "NUMBER",
  "';'", "'}'", "'='", "':'", "','", "'{'", "$accept", "conf", "conf_item",
  "timespec_", "timespec", "sizespec_", "sizespec",
  "module_base_path_entry", "loadmodule_entry", "module_attributes",
  "module_attributes_items", "module_attributes_item", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_tls_certificate_file",
  "serverinfo_tls_private_key_file", "serverinfo_name", "serverinfo_sid",
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
  "general_kill_chase_time_limit", "general_anti_nick_flood",
  "general_max_nick_time", "general_max_nick_changes",
  "general_max_accept", "general_max_away_length",
  "general_anti_spam_exit_message_time", "general_ts_warn_delta",
  "general_ts_max_delta", "general_invisible_on_connect",
  "general_warn_no_connect_block", "general_stats_e_disabled",
  "general_stats_u_oper_only", "general_pace_wait",
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
  "channel_items", "channel_item", "channel_disable_fake_channels",
  "channel_invite_client_count", "channel_invite_client_time",
  "channel_invite_delay_channel", "channel_invite_expire_time",
  "channel_knock_client_count", "channel_knock_client_time",
  "channel_knock_delay_channel", "channel_max_channels",
  "channel_max_invites", "channel_max_bans", "channel_max_bans_large",
  "channel_max_kick_length", "channel_default_join_flood_count",
  "channel_default_join_flood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_flatten_links_delay", "serverhide_flatten_links_file",
  "serverhide_disable_remote_commands", "serverhide_hide_servers",
  "serverhide_hide_services", "serverhide_hidden_name",
  "serverhide_hidden", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-946)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -946,   680,  -946,  -141,  -208,  -206,  -946,  -946,  -946,  -191,
    -946,  -180,  -946,  -946,  -946,  -182,  -172,  -946,  -946,  -946,
    -168,  -162,  -946,  -144,  -946,  -130,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,   144,   794,  -126,  -122,  -121,    23,  -116,
     391,  -115,  -114,  -113,  -107,   -90,   -83,   -57,   -56,   610,
     532,   -52,    32,   -42,    21,   -15,    -7,    -1,     0,    55,
       2,  -946,  -946,  -946,  -946,  -946,    57,    65,    66,    68,
      73,    74,    77,    82,    91,    92,    93,    95,   103,   106,
     107,   126,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,   647,   555,
      49,  -946,   109,    50,  -946,  -946,   270,  -946,   116,   117,
     118,   120,   123,   124,   134,   135,   137,   143,   147,   148,
     155,   156,   157,   158,   161,   162,   163,   164,   165,   168,
     169,   170,   171,   172,   173,   176,   178,   179,   182,   190,
     193,   202,   203,   204,   208,   210,   212,   217,   223,   227,
     229,   243,   251,   257,   258,   260,    47,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,   139,    17,   375,   -26,
      72,   128,    19,   329,   272,  -946,   262,   263,   267,   268,
     269,   271,   275,   277,   306,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,   132,   279,   280,   284,   286,   287,
     288,   290,   291,   293,   295,   296,   298,   214,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,    10,   216,   300,    22,  -946,  -946,  -946,   311,   130,
    -946,   304,    84,  -946,  -946,    59,  -946,    88,   313,   319,
     274,  -946,   310,   321,   345,   323,   321,   321,   321,   325,
     321,   321,   326,   327,   330,   334,   335,   328,  -946,   337,
     336,   338,   340,  -946,   342,   344,   346,   347,   348,   349,
     352,   353,   356,   358,   359,   153,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,   339,   360,   363,   365,   368,   369,   370,  -946,
     371,   372,   376,   377,   378,   380,   381,   232,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,   383,   385,    14,  -946,  -946,  -946,
     379,   357,  -946,  -946,   387,   388,    16,  -946,  -946,  -946,
     415,   321,   395,   321,   321,   419,   399,   400,   402,   404,
     406,   431,   409,   321,   433,   434,   412,   413,   321,   437,
     321,   416,   417,   418,   420,   421,   422,   321,   424,   425,
     429,   456,   438,   461,   321,   321,   462,   321,   464,   442,
     466,   467,   445,   321,   321,   321,   483,   463,   468,  -946,
     470,   469,   475,  -946,   476,   477,   481,    36,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,   484,   486,    26,  -946,
    -946,  -946,   472,   487,   492,  -946,   493,  -946,    46,  -946,
    -946,  -946,  -946,  -946,  -946,   343,  -946,  -946,  -946,   485,
     494,   495,    76,  -946,  -946,  -946,   499,   498,   503,  -946,
     506,   509,   511,   514,   515,   516,   519,   140,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,   501,
     520,   521,   523,    12,  -946,  -946,  -946,  -946,   528,   550,
     321,   531,   554,   533,   557,   561,   540,  -946,  -946,   542,
     546,   569,   549,   551,   552,   559,   560,   562,   563,   565,
     566,   548,  -946,   568,   547,  -946,    86,  -946,  -946,  -946,
    -946,   583,   570,  -946,   564,   571,   572,   573,   576,   577,
      18,  -946,  -946,  -946,  -946,  -946,   575,   581,  -946,   582,
     584,  -946,   586,    63,  -946,  -946,  -946,  -946,   585,   592,
     593,  -946,   594,   317,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   605,   606,   609,   611,   615,  -946,  -946,
     567,   617,   321,   608,   618,   321,   621,   321,   623,   624,
     625,   626,   321,   627,   627,   628,  -946,  -946,   629,   -73,
     632,   607,   633,   634,   631,   636,   637,   639,   638,   641,
     321,   643,   642,  -946,   645,   653,   652,  -946,   654,  -946,
     655,   657,   656,  -946,   658,   659,   660,   661,   665,   666,
     667,   668,   669,   670,   671,   675,   678,   679,   681,   682,
     683,   684,   685,   686,   687,   688,   689,   690,   691,   692,
     693,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   708,   709,   710,   711,   712,
     713,   714,  -946,  -946,   717,   740,   715,   720,   721,   722,
     723,  -946,   724,   726,   725,  -946,  -946,   728,   729,   719,
     646,   730,  -946,   -26,  -946,   731,   733,   732,  -946,  -946,
     735,   752,   734,   736,   737,   739,   741,   762,   742,   743,
     744,  -946,  -946,   745,   747,   748,   749,  -946,   750,   751,
     753,   754,   755,   756,   757,   758,  -946,   759,   760,   761,
     763,   764,   765,   766,   767,   768,   769,   770,   771,  -946,
    -946,   774,   746,   773,  -946,   775,  -946,   189,  -946,   776,
     778,   779,   780,   781,  -946,   782,  -946,  -946,   785,   777,
     786,   787,  -946,  -946,  -946,  -946,  -946,   321,   321,   321,
     321,   321,   321,   321,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
     788,   789,   790,   -44,   791,   792,   793,   795,   796,   797,
     798,   799,   800,    70,   801,   802,  -946,   803,   804,   805,
     806,   807,   808,   809,    20,   810,   811,   812,   813,   814,
     815,   816,  -946,   817,   818,  -946,  -946,   819,   820,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,   821,   822,
     355,   823,   824,   825,  -946,   826,   827,  -946,   828,   829,
     261,   844,   676,  -946,  -946,  -946,   831,   832,  -946,   833,
     834,   502,   835,   836,   837,   838,   839,   840,   841,  -946,
     842,   843,   845,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,   846,   536,  -946,  -946,   847,   783,
     784,  -946,    43,  -946,  -946,  -946,  -946,   848,   849,   850,
     851,  -946,  -946,   852,   616,   853,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -194,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
     627,   627,   627,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -189,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -183,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -181,  -946,   855,   646,   856,  -946,
    -946,  -946,  -946,  -946,  -946,   854,  -946,   857,   858,  -946,
     859,  -946,   860,   861,  -946,  -946,   862,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -176,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -173,  -946,  -946,   868,  -179,   865,   869,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -156,  -946,  -946,  -946,   -44,  -946,
    -946,  -946,  -946,    20,  -946,   355,  -946,   261,  -946,  -946,
    -946,   870,   917,   931,   867,   932,   934,   944,  -946,   502,
    -946,   536,   871,   872,   873,   276,  -946,  -946,   616,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,   874,  -946,  -946
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
       0,    83,    84,    86,    85,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   530,   545,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   531,   532,   542,   543,   544,     0,     0,
       0,   417,     0,     0,   415,   416,     0,   479,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   430,   431,   432,
     469,   437,   470,   464,   465,   466,   467,   441,   433,   434,
     435,   436,   451,   438,   439,   440,   442,   443,   468,   445,
     446,   453,   454,   447,   448,   449,   444,   450,   461,   462,
     463,   459,   460,   452,   457,   458,   455,   456,   471,   472,
     473,   474,   475,   476,   477,   478,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   573,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   564,   565,   566,   567,   568,
     569,   570,   572,   571,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    67,
      65,    56,    66,    58,    59,    60,    61,    62,    63,    64,
      57,     0,     0,     0,     0,   115,   116,   117,     0,     0,
     308,     0,     0,   306,   307,     0,    87,     0,     0,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   529,     0,
       0,     0,     0,   232,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,   202,   205,   207,
     208,   209,   210,   211,   212,   213,   203,   204,   206,   214,
     215,   216,     0,     0,     0,     0,     0,     0,     0,   385,
       0,     0,     0,     0,     0,     0,     0,     0,   359,   360,
     361,   362,   363,   364,   365,   366,   368,   367,   369,   373,
     370,   371,   372,   410,     0,     0,     0,   407,   408,   409,
       0,     0,   414,   425,     0,     0,     0,   422,   423,   424,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
       0,     0,     0,   279,     0,     0,     0,     0,   267,   268,
     269,   270,   273,   271,   272,   401,     0,     0,     0,   398,
     399,   400,     0,     0,     0,   240,     0,   252,     0,   250,
     251,   253,   254,    52,    51,    48,    50,    46,    45,     0,
       0,     0,     0,    94,    95,    96,     0,     0,     0,   165,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   145,
     146,   147,   148,   151,   152,   153,   150,   149,   154,     0,
       0,     0,     0,     0,   296,   297,   298,   299,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   563,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,   342,     0,   337,   338,   339,
     118,     0,     0,   114,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   106,   105,   107,     0,     0,   305,     0,
       0,   320,     0,     0,   313,   314,   315,   316,     0,     0,
       0,    81,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   528,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,   374,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   358,     0,     0,     0,   406,     0,   413,
       0,     0,     0,   421,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   428,   274,     0,     0,     0,     0,     0,     0,
       0,   266,     0,     0,     0,   397,   255,     0,     0,     0,
       0,     0,   249,     0,    97,     0,     0,     0,    93,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   300,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,   562,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
     340,     0,     0,     0,   336,     0,   113,     0,   108,     0,
       0,     0,     0,     0,   102,     0,   304,   317,     0,     0,
       0,     0,   312,    90,    89,    88,   560,    29,    29,    29,
      29,    29,    29,    29,    31,    30,   561,   547,   548,   549,
     550,   551,   552,   553,   554,   557,   558,   555,   556,   559,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,     0,   199,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   357,     0,     0,   405,   418,     0,     0,   420,
     490,   495,   480,   481,   503,   520,   521,   522,   523,   524,
     525,   484,   518,   519,   512,   511,   485,   486,   526,   498,
     489,   487,   488,   493,   494,   482,   492,   491,   509,   516,
     517,   507,   515,   504,   502,   505,   510,   527,   506,   508,
     500,   501,   513,   514,   497,   496,   499,   483,     0,     0,
       0,     0,     0,     0,   265,     0,     0,   396,     0,     0,
       0,   260,   256,   259,   239,    49,     0,     0,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,     0,     0,   294,   577,   574,   575,   576,   581,   580,
     578,   579,    76,    73,    80,    72,    77,    78,    79,    71,
      75,    74,    69,    70,     0,     0,   335,   119,     0,     0,
       0,   131,     0,   123,   124,   126,   125,     0,     0,     0,
       0,   101,   309,     0,     0,     0,   311,    32,    33,    34,
      35,    36,    37,    38,   227,   228,   222,   237,   236,     0,
     235,   223,   231,   224,   230,   218,   229,   221,   220,   219,
      39,    39,    39,    41,    40,   225,   226,   380,   383,   384,
     394,   391,   376,   392,   389,   390,     0,   388,   393,   375,
     382,   379,   378,   377,   381,   411,   412,   426,   427,   277,
     278,   287,   283,   284,   286,   291,   288,   289,   290,   285,
       0,   282,   276,   292,   275,   403,   402,   263,   262,   247,
     248,   245,   246,   244,     0,   243,     0,     0,     0,    98,
      99,   163,   160,   185,   196,   172,   181,     0,   170,   175,
       0,   190,     0,   184,   188,   194,   174,   177,   186,   187,
     191,   182,   189,   178,   195,   180,   176,   179,     0,   168,
     156,   158,   164,   161,   162,   157,   159,   303,   301,   302,
     341,   346,   352,   355,   348,   354,   349,   353,   351,   347,
     350,     0,   345,   127,     0,     0,     0,     0,   122,   110,
     109,   111,   112,   318,   324,   330,   333,   326,   332,   327,
     331,   329,   325,   328,     0,   323,   319,   233,     0,    42,
      43,    44,   386,     0,   280,     0,   241,     0,   261,   258,
     257,     0,     0,     0,     0,     0,     0,     0,   166,     0,
     343,     0,     0,     0,     0,     0,   121,   321,     0,   234,
     387,   281,   242,   171,   193,   169,   197,   192,   183,   173,
     167,   344,   128,   130,   129,   139,   138,   134,   136,   140,
     137,   133,   135,     0,   322,   132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -946,  -946,  -946,  -347,  -301,  -945,  -623,  -946,  -946,  -946,
    -946,   149,  -946,  -946,   830,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,   882,
    -946,  -946,  -946,  -946,  -946,  -946,   604,  -946,  -946,  -946,
    -946,  -946,   397,  -946,  -946,  -946,  -946,  -946,  -946,   863,
    -946,  -946,  -946,  -946,     5,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,   488,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,   -84,  -946,  -946,  -946,
     772,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,   -58,  -946,
    -946,  -946,  -946,  -946,   -66,  -946,   614,  -946,  -946,  -946,
      27,  -946,  -946,  -946,  -946,  -946,   644,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,   -62,  -946,  -946,  -946,  -946,   579,
    -946,  -946,  -946,  -946,  -946,   864,  -946,  -946,  -946,  -946,
     512,  -946,  -946,  -946,  -946,  -946,   -80,  -946,  -946,  -946,
     543,  -946,  -946,  -946,  -946,   -71,  -946,  -946,  -946,   738,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,   -50,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
     640,  -946,  -946,  -946,  -946,  -946,   718,  -946,  -946,  -946,
    -946,   983,  -946,  -946,  -946,  -946,   716,  -946,  -946,  -946,
    -946,   933,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  1009,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
     875,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   804,   805,  1013,  1014,    28,    29,   230,
     485,   486,    30,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,    31,    80,    81,
      82,    83,    84,    32,    66,   492,   493,   494,   495,    33,
      73,   570,   571,   572,   573,   574,   575,    34,   284,   285,
     286,   287,   288,   972,   973,   974,   975,   976,  1126,  1203,
      35,    67,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   732,  1098,  1099,    36,    55,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   613,   999,  1000,    37,
      63,   477,   719,  1064,  1065,   478,   479,   480,  1068,   922,
     923,   481,   482,    38,    61,   457,   458,   459,   460,   461,
     462,   463,   706,  1050,  1051,   464,    39,    68,   523,   524,
     525,   526,   527,    40,   292,   293,   294,    41,    75,   583,
     584,   585,   586,   587,   789,  1144,  1145,    42,    71,   556,
     557,   558,   559,   772,  1121,  1122,    43,    56,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     634,  1026,  1027,   379,   380,   381,   382,    44,    62,   468,
     469,   470,   471,    45,    57,   386,   387,   388,   389,    46,
     123,   124,   125,    47,    59,   396,   397,   398,   399,    48,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      49,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    50,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     834,   835,   594,    76,   483,   597,   598,   599,  1173,   601,
     602,   553,    53,   519,    54,   383,   997,   393,   465,   565,
     489,  1147,   290,   282,   121,  1148,  1152,   465,  1024,    58,
    1153,    64,  1154,   282,  1156,   833,  1155,   450,  1157,  1168,
      60,    77,  1170,  1169,   968,    65,  1171,   472,   127,    78,
     383,   121,    69,   128,   129,   451,   130,   131,    70,  1177,
     579,   132,   520,  1178,   579,  1149,  1150,  1151,   133,   134,
     135,   136,   137,   138,    51,    52,    72,   489,   139,   140,
     141,  1010,  1011,  1012,   452,   290,   384,   553,   142,   143,
      74,   998,   144,   145,   118,   122,   838,   839,   119,   120,
     655,   521,   657,   658,   126,   226,   227,   228,   490,   473,
     453,   229,   667,   146,   147,   484,    79,   672,   474,   674,
     475,   384,   122,   231,   554,   148,   681,    85,   149,   150,
     394,   565,   566,   688,   689,   291,   691,   232,   151,   152,
     450,   496,   697,   698,   699,    76,   153,   154,   522,   155,
     385,   156,   395,   466,   319,   157,   158,   969,   451,   497,
      86,    87,   466,   233,   234,   490,   454,   159,   281,    88,
     320,   321,   160,   580,   161,   162,   163,   580,   289,   164,
     476,   567,   322,    77,   165,   385,   491,   452,   498,  -120,
     968,    78,   568,   455,    89,    90,    91,    92,   291,  -120,
     554,   569,   166,   167,  1025,   295,   168,   169,   296,    93,
      94,    95,   555,   453,   499,   254,   297,   298,   300,    96,
      97,    98,   467,    99,   100,   970,   283,   323,   746,   750,
     646,   467,   652,   352,   783,   353,   283,   354,   562,   170,
     171,   456,   714,   491,   566,   971,   172,   173,   324,   325,
     255,   355,   710,   256,   500,   174,   326,   175,    79,  1127,
     327,   581,   721,   448,   582,   581,   391,   328,   582,   454,
     501,   393,   299,   519,   302,   329,   330,   331,   257,   791,
     356,  1059,   303,   304,   833,   305,   332,   487,   555,   258,
     306,   307,   727,   567,   308,   357,   455,   358,  1060,   309,
     577,   588,   773,   969,   568,   333,   359,   235,   310,   311,
     312,   822,   313,   569,   825,   259,   827,  1061,   360,   260,
     314,   832,   520,   315,   316,   502,   390,   261,   262,   334,
     496,   263,   264,   400,   401,   402,   503,   403,   504,   850,
     404,   405,   317,   488,   456,   505,   361,   538,   497,   506,
     236,   406,   407,  1195,   408,  1196,   740,   237,   238,   239,
     409,   521,   240,   241,   410,   411,   362,   242,   243,   625,
    1041,   970,   412,   413,   414,   415,   472,   498,   416,   417,
     418,   419,   420,   363,   394,   421,   422,   423,   424,   425,
     426,   971,   127,   427,   364,   428,   429,   128,   129,   430,
     130,   131,  1197,   499,  1042,   132,   395,   431,   522,   265,
     432,   266,   133,   134,   135,   136,   137,   138,  1198,   433,
     434,   435,   139,   140,   141,   436,   365,   437,   366,   438,
     551,   560,   142,   143,   439,  1043,   144,   145,   473,  1062,
     440,  1199,  1200,   500,   441,  1063,   442,   474,   642,   475,
     987,   988,   989,   990,   991,   992,   993,   146,   147,   501,
     443,   797,   798,   799,   800,   801,   802,   803,   444,   148,
    1044,  1045,   149,   150,   445,   446,  1046,   447,   564,   528,
     529,  1201,   151,   152,   530,   531,   532,  1202,   533,   591,
     153,   154,   534,   155,   535,   156,   539,   540,  1047,   157,
     158,   541,  1174,   542,   543,   544,  1073,   545,   546,   476,
     547,   159,   548,   549,   502,   550,   160,   561,   161,   162,
     163,   576,   536,   164,   592,   503,   589,   504,   165,  1074,
    1075,   593,   590,   254,   505,   593,   595,   596,   506,   600,
     603,   604,  1076,   608,   605,  1048,   166,   167,   606,   607,
     168,   169,   609,   610,   627,   611,   352,   612,   353,   614,
     354,   615,   723,   616,   617,   618,   619,  1049,   255,   620,
     621,   256,   649,   622,   355,   623,   624,   628,  1077,  1078,
     629,  1079,   630,   170,   171,   631,   632,   633,   635,   636,
     172,   173,   648,   637,   638,   639,   257,   640,   641,   174,
     644,   175,   645,   356,   650,   651,   654,   258,  1080,   656,
     659,   235,  1081,   660,   661,  1111,   662,   663,   357,   664,
     358,  1082,   665,   666,   668,   669,   670,   671,   673,   359,
     675,   676,   677,   259,   678,   679,   680,   260,   682,   683,
    1083,   360,  1084,   684,  1085,   261,   262,   685,   319,   263,
     264,   686,   687,   690,   236,   692,   693,   694,   695,   696,
    1086,   237,   238,   239,   320,   321,   240,   241,  1087,   361,
    1088,   242,   243,  1089,   700,  1090,   322,   701,  1112,  1091,
       2,     3,  1092,   702,     4,   703,   704,   716,  1093,   362,
    1094,  1095,   705,   707,   708,  1134,     5,  1113,   709,     6,
     724,   712,  1114,   713,   717,  1096,   363,  1115,     7,   718,
     720,   725,   726,  1097,   729,   730,   742,   364,     8,   748,
     731,   323,  1116,   733,  1117,  1118,   734,   265,   735,   266,
       9,   736,   737,   738,    10,    11,   739,   743,   744,  1119,
     745,   749,   324,   325,   751,   752,   753,  1120,   754,   365,
     326,   366,   755,    12,   327,   756,   757,    13,  1135,   758,
     759,   328,   760,   769,   771,   761,   762,    14,    15,   329,
     330,   331,   763,   764,   775,   765,   766,  1136,   767,   768,
     332,   820,  1137,   770,   777,   776,   778,  1138,   785,   779,
     780,    16,    17,   781,   782,    85,   786,   787,   841,   333,
     793,   788,  1139,   790,  1140,  1141,    18,   794,   795,   796,
     806,   807,   808,   809,   810,   811,   812,   813,   814,  1142,
     815,   816,    19,   334,   817,   823,   818,  1143,    86,    87,
     819,   821,   824,    20,    21,   826,   828,    88,   829,   830,
     831,   833,   837,   836,    22,   840,   842,   843,   844,   845,
     846,   848,    23,   847,   849,    24,   851,   852,   853,    25,
     921,    26,    89,    90,    91,    92,   854,   855,   857,   856,
     858,   859,   925,   860,   861,   862,   863,    93,    94,    95,
     864,   865,   866,   867,   868,   869,   870,    96,    97,    98,
     871,    99,   100,   872,   873,  1067,   874,   875,   876,   877,
     878,   879,   880,   881,   882,   883,   884,   885,   886,   887,
     888,   889,   890,   891,   892,   893,   894,   895,   896,   897,
     898,   899,   900,   901,   902,   903,   904,   905,   906,   907,
     908,   909,   910,   911,   912,   913,   920,   915,   914,   916,
     917,   918,   919,   930,   926,   924,   927,   928,   929,   932,
     933,   931,   934,   936,   935,   937,   938,  1186,   940,   939,
     941,   942,   301,   965,   943,   944,   945,   784,   946,   947,
     948,   949,   950,   951,   952,   953,   954,  1128,   955,   956,
     957,   958,   959,   960,   961,   962,   963,   964,   966,   977,
     967,   978,   979,   980,   984,   741,   981,   982,   983,   985,
    1124,  1125,   986,   994,   995,   996,  1001,  1002,  1003,  1183,
    1004,  1005,  1006,  1007,  1008,  1009,  1015,  1016,  1017,  1018,
    1019,  1020,  1021,  1022,  1023,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1052,  1053,
    1054,  1055,  1056,  1057,  1058,  1066,  1069,  1070,  1071,  1072,
    1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1184,
    1109,  1110,  1123,  1129,  1130,  1131,  1132,  1133,  1146,  1158,
    1185,  1160,  1161,  1188,  1187,  1162,  1163,  1164,  1165,  1166,
    1167,  1172,  1175,  1189,  1176,  1190,  1192,  1193,  1194,  1205,
    1179,  1182,   722,  1181,  1159,   792,   728,   552,  1204,   774,
    1191,   711,   747,  1180,   647,   643,   392,   626,   715,   449,
     318,     0,   653,     0,     0,     0,     0,     0,     0,   537,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   563,     0,     0,
       0,     0,     0,     0,     0,     0,   578
};

static const yytype_int16 yycheck[] =
{
     623,   624,   303,     1,    30,   306,   307,   308,   187,   310,
     311,     1,   220,     1,   220,     1,    60,     1,     1,     1,
       1,   215,     1,     1,     1,   219,   215,     1,     8,   220,
     219,   213,   215,     1,   215,   214,   219,     1,   219,   215,
     220,    39,   215,   219,     1,   217,   219,     1,     1,    47,
       1,     1,   220,     6,     7,    19,     9,    10,   220,   215,
       1,    14,    50,   219,     1,  1010,  1011,  1012,    21,    22,
      23,    24,    25,    26,   215,   216,   220,     1,    31,    32,
      33,    11,    12,    13,    48,     1,    72,     1,    41,    42,
     220,   135,    45,    46,   220,    72,   169,   170,   220,   220,
     401,    89,   403,   404,   220,   220,   220,   220,    89,    63,
      74,   218,   413,    66,    67,   141,   114,   418,    72,   420,
      74,    72,    72,   213,   114,    78,   427,     1,    81,    82,
     114,     1,   114,   434,   435,   114,   437,   220,    91,    92,
       1,     1,   443,   444,   445,     1,    99,   100,   136,   102,
     136,   104,   136,   136,     1,   108,   109,   114,    19,    19,
      34,    35,   136,   220,   220,    89,   130,   120,   220,    43,
      17,    18,   125,   114,   127,   128,   129,   114,   220,   132,
     134,   163,    29,    39,   137,   136,   167,    48,    48,   167,
       1,    47,   174,   157,    68,    69,    70,    71,   114,   167,
     114,   183,   155,   156,   184,   220,   159,   160,   215,    83,
      84,    85,   202,    74,    74,     1,   217,   217,   216,    93,
      94,    95,   205,    97,    98,   182,   204,    74,   216,   530,
     216,   205,   216,     1,   216,     3,   204,     5,   216,   192,
     193,   205,   216,   167,   114,   202,   199,   200,    95,    96,
      36,    19,   216,    39,   114,   208,   103,   210,   114,   216,
     107,   202,   216,   216,   205,   202,   216,   114,   205,   130,
     130,     1,   217,     1,   217,   122,   123,   124,    64,   216,
      48,    20,   217,   217,   214,   217,   133,   215,   202,    75,
     217,   217,   216,   163,   217,    63,   157,    65,    37,   217,
     216,   213,   216,   114,   174,   152,    74,     1,   217,   217,
     217,   612,   217,   183,   615,   101,   617,    56,    86,   105,
     217,   622,    50,   217,   217,   185,   217,   113,   114,   176,
       1,   117,   118,   217,   217,   217,   196,   217,   198,   640,
     217,   217,   216,   215,   205,   205,   114,   215,    19,   209,
      44,   217,   217,    77,   217,    79,   216,    51,    52,    53,
     217,    89,    56,    57,   217,   217,   134,    61,    62,   216,
      15,   182,   217,   217,   217,   217,     1,    48,   217,   217,
     217,   217,   217,   151,   114,   217,   217,   217,   217,   217,
     217,   202,     1,   217,   162,   217,   217,     6,     7,   217,
       9,    10,   126,    74,    49,    14,   136,   217,   136,   195,
     217,   197,    21,    22,    23,    24,    25,    26,   142,   217,
     217,   217,    31,    32,    33,   217,   194,   217,   196,   217,
     216,   215,    41,    42,   217,    80,    45,    46,    63,   178,
     217,   165,   166,   114,   217,   184,   217,    72,   216,    74,
     797,   798,   799,   800,   801,   802,   803,    66,    67,   130,
     217,   144,   145,   146,   147,   148,   149,   150,   217,    78,
     115,   116,    81,    82,   217,   217,   121,   217,   167,   217,
     217,   205,    91,    92,   217,   217,   217,   211,   217,   215,
      99,   100,   217,   102,   217,   104,   217,   217,   143,   108,
     109,   217,  1125,   217,   217,   217,     4,   217,   217,   134,
     217,   120,   217,   217,   185,   217,   125,   217,   127,   128,
     129,   217,   216,   132,   214,   196,   213,   198,   137,    27,
      28,   214,   213,     1,   205,   214,   191,   214,   209,   214,
     214,   214,    40,   215,   214,   190,   155,   156,   214,   214,
     159,   160,   215,   217,   215,   217,     1,   217,     3,   217,
       5,   217,   219,   217,   217,   217,   217,   212,    36,   217,
     217,    39,   215,   217,    19,   217,   217,   217,    76,    77,
     217,    79,   217,   192,   193,   217,   217,   217,   217,   217,
     199,   200,   213,   217,   217,   217,    64,   217,   217,   208,
     217,   210,   217,    48,   217,   217,   191,    75,   106,   214,
     191,     1,   110,   214,   214,    79,   214,   213,    63,   213,
      65,   119,   191,   214,   191,   191,   214,   214,   191,    74,
     214,   214,   214,   101,   214,   214,   214,   105,   214,   214,
     138,    86,   140,   214,   142,   113,   114,   191,     1,   117,
     118,   213,   191,   191,    44,   191,   214,   191,   191,   214,
     158,    51,    52,    53,    17,    18,    56,    57,   166,   114,
     168,    61,    62,   171,   191,   173,    29,   214,   142,   177,
       0,     1,   180,   215,     4,   215,   217,   215,   186,   134,
     188,   189,   217,   217,   217,    79,    16,   161,   217,    19,
     215,   217,   166,   217,   217,   203,   151,   171,    28,   217,
     217,   217,   217,   211,   215,   217,   215,   162,    38,   191,
     217,    74,   186,   217,   188,   189,   217,   195,   217,   197,
      50,   217,   217,   217,    54,    55,   217,   217,   217,   203,
     217,   191,    95,    96,   213,   191,   213,   211,   191,   194,
     103,   196,   191,    73,   107,   215,   214,    77,   142,   213,
     191,   114,   213,   215,   217,   214,   214,    87,    88,   122,
     123,   124,   213,   213,   191,   213,   213,   161,   213,   213,
     133,   214,   166,   215,   220,   215,   215,   171,   213,   217,
     217,   111,   112,   217,   217,     1,   215,   215,   191,   152,
     215,   217,   186,   217,   188,   189,   126,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   203,
     215,   215,   142,   176,   215,   217,   215,   211,    34,    35,
     215,   214,   214,   153,   154,   214,   213,    43,   214,   214,
     214,   214,   213,   215,   164,   213,   213,   213,   217,   213,
     213,   213,   172,   214,   213,   175,   213,   215,   213,   179,
     214,   181,    68,    69,    70,    71,   213,   215,   213,   215,
     213,   215,   723,   215,   215,   215,   215,    83,    84,    85,
     215,   215,   215,   215,   215,   215,   215,    93,    94,    95,
     215,    97,    98,   215,   215,   219,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     213,   191,   217,   213,   213,   213,   217,   213,   215,   213,
     215,   213,   213,   191,   213,   215,   213,   215,   213,   213,
     213,   217,   213,   191,   213,   213,   213,    90,   213,   215,
     213,   213,    80,   217,   215,   215,   215,   570,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   972,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   213,   215,   213,
     215,   213,   213,   213,   217,   507,   215,   215,   213,   213,
     217,   217,   215,   215,   215,   215,   215,   215,   215,   139,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   201,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   142,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   214,
     139,   215,   218,   139,   142,   218,   218,   218,   218,   218,
     218,   213,   217,   139,   215,  1169,   215,   215,   215,   215,
    1148,  1157,   478,  1155,  1067,   583,   492,   267,  1178,   556,
    1171,   457,   523,  1153,   386,   367,   123,   335,   468,   176,
     101,    -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   292
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   222,     0,     1,     4,    16,    19,    28,    38,    50,
      54,    55,    73,    77,    87,    88,   111,   112,   126,   142,
     153,   154,   164,   172,   175,   179,   181,   223,   228,   229,
     233,   248,   254,   260,   268,   281,   298,   320,   334,   347,
     354,   358,   368,   377,   398,   404,   410,   414,   420,   471,
     489,   215,   216,   220,   220,   299,   378,   405,   220,   415,
     220,   335,   399,   321,   213,   217,   255,   282,   348,   220,
     220,   369,   220,   261,   220,   359,     1,    39,    47,   114,
     249,   250,   251,   252,   253,     1,    34,    35,    43,    68,
      69,    70,    71,    83,    84,    85,    93,    94,    95,    97,
      98,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   220,   220,
     220,     1,    72,   411,   412,   413,   220,     1,     6,     7,
       9,    10,    14,    21,    22,    23,    24,    25,    26,    31,
      32,    33,    41,    42,    45,    46,    66,    67,    78,    81,
      82,    91,    92,    99,   100,   102,   104,   108,   109,   120,
     125,   127,   128,   129,   132,   137,   155,   156,   159,   160,
     192,   193,   199,   200,   208,   210,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   220,   220,   220,   218,
     230,   213,   220,   220,   220,     1,    44,    51,    52,    53,
      56,    57,    61,    62,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,     1,    36,    39,    64,    75,   101,
     105,   113,   114,   117,   118,   195,   197,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   220,     1,   204,   269,   270,   271,   272,   273,   220,
       1,   114,   355,   356,   357,   220,   215,   217,   217,   217,
     216,   250,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   216,   473,     1,
      17,    18,    29,    74,    95,    96,   103,   107,   114,   122,
     123,   124,   133,   152,   176,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     1,     3,     5,    19,    48,    63,    65,    74,
      86,   114,   134,   151,   162,   194,   196,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   394,
     395,   396,   397,     1,    72,   136,   406,   407,   408,   409,
     217,   216,   412,     1,   114,   136,   416,   417,   418,   419,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   216,   422,
       1,    19,    48,    74,   130,   157,   205,   336,   337,   338,
     339,   340,   341,   342,   346,     1,   136,   205,   400,   401,
     402,   403,     1,    63,    72,    74,   134,   322,   326,   327,
     328,   332,   333,    30,   141,   231,   232,   215,   215,     1,
      89,   167,   256,   257,   258,   259,     1,    19,    48,    74,
     114,   130,   185,   196,   198,   205,   209,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,     1,
      50,    89,   136,   349,   350,   351,   352,   353,   217,   217,
     217,   217,   217,   217,   217,   217,   216,   491,   215,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   216,   235,     1,   114,   202,   370,   371,   372,   373,
     215,   217,   216,   270,   167,     1,   114,   163,   174,   183,
     262,   263,   264,   265,   266,   267,   217,   216,   356,     1,
     114,   202,   205,   360,   361,   362,   363,   364,   213,   213,
     213,   215,   214,   214,   225,   191,   214,   225,   225,   225,
     214,   225,   225,   214,   214,   214,   214,   214,   215,   215,
     217,   217,   217,   317,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   216,   301,   215,   217,   217,
     217,   217,   217,   217,   391,   217,   217,   217,   217,   217,
     217,   217,   216,   380,   217,   217,   216,   407,   213,   215,
     217,   217,   216,   417,   191,   225,   214,   225,   225,   191,
     214,   214,   214,   213,   213,   191,   214,   225,   191,   191,
     214,   214,   225,   191,   225,   214,   214,   214,   214,   214,
     214,   225,   214,   214,   214,   191,   213,   191,   225,   225,
     191,   225,   191,   214,   191,   191,   214,   225,   225,   225,
     191,   214,   215,   215,   217,   217,   343,   217,   217,   217,
     216,   337,   217,   217,   216,   401,   215,   217,   217,   323,
     217,   216,   327,   219,   215,   217,   217,   216,   257,   215,
     217,   217,   295,   217,   217,   217,   217,   217,   217,   217,
     216,   284,   215,   217,   217,   217,   216,   350,   191,   191,
     225,   213,   191,   213,   191,   191,   215,   214,   213,   191,
     213,   214,   214,   213,   213,   213,   213,   213,   213,   215,
     215,   217,   374,   216,   371,   191,   215,   220,   215,   217,
     217,   217,   217,   216,   263,   213,   215,   215,   217,   365,
     217,   216,   361,   215,   215,   215,   215,   144,   145,   146,
     147,   148,   149,   150,   224,   225,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     214,   214,   225,   217,   214,   225,   214,   225,   213,   214,
     214,   214,   225,   214,   227,   227,   215,   213,   169,   170,
     213,   191,   213,   213,   217,   213,   213,   214,   213,   213,
     225,   213,   215,   213,   213,   215,   215,   213,   213,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   213,   191,
     217,   213,   213,   213,   215,   213,   213,   215,   213,   213,
     217,   214,   330,   331,   215,   232,   213,   213,   215,   213,
     191,   217,   213,   213,   213,   213,   191,   213,   213,   215,
     213,   213,   213,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   213,   217,   215,   215,     1,   114,
     182,   202,   274,   275,   276,   277,   278,   213,   213,   213,
     213,   215,   215,   213,   217,   213,   215,   224,   224,   224,
     224,   224,   224,   224,   215,   215,   215,    60,   135,   318,
     319,   215,   215,   215,   215,   215,   215,   215,   215,   215,
      11,    12,    13,   226,   227,   215,   215,   215,   215,   215,
     215,   215,   215,   215,     8,   184,   392,   393,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,    15,    49,    80,   115,   116,   121,   143,   190,   212,
     344,   345,   215,   215,   215,   215,   215,   215,   215,    20,
      37,    56,   178,   184,   324,   325,   201,   219,   329,   215,
     215,   215,   215,     4,    27,    28,    40,    76,    77,    79,
     106,   110,   119,   138,   140,   142,   158,   166,   168,   171,
     173,   177,   180,   186,   188,   189,   203,   211,   296,   297,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,    79,   142,   161,   166,   171,   186,   188,   189,   203,
     211,   375,   376,   215,   217,   217,   279,   216,   275,   215,
     215,   215,   215,   215,    79,   142,   161,   166,   171,   186,
     188,   189,   203,   211,   366,   367,   215,   215,   219,   226,
     226,   226,   215,   219,   215,   219,   215,   219,   214,   331,
     215,   218,   218,   218,   218,   218,   218,   218,   215,   219,
     215,   219,   213,   187,   227,   217,   215,   215,   219,   319,
     393,   345,   325,   139,   142,   139,    90,   142,   139,   139,
     297,   376,   215,   215,   215,    77,    79,   126,   142,   165,
     166,   205,   211,   280,   367,   215
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   221,   222,   222,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   224,
     224,   225,   225,   225,   225,   225,   225,   225,   225,   226,
     226,   227,   227,   227,   227,   228,   229,   230,   230,   231,
     231,   232,   232,   233,   234,   234,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   249,   250,   250,   250,   250,   251,   252,
     253,   255,   254,   256,   256,   257,   257,   257,   258,   259,
     261,   260,   262,   262,   263,   263,   263,   263,   263,   264,
     265,   266,   267,   268,   269,   269,   270,   270,   270,   271,
     273,   272,   274,   274,   275,   275,   275,   275,   276,   277,
     277,   279,   278,   280,   280,   280,   280,   280,   280,   280,
     280,   282,   281,   283,   283,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   295,   294,   296,   296,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   299,   298,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   317,   316,   318,   318,   319,   319,   321,   320,
     323,   322,   324,   324,   325,   325,   325,   325,   325,   326,
     326,   327,   327,   327,   327,   327,   329,   328,   330,   330,
     331,   331,   332,   333,   335,   334,   336,   336,   337,   337,
     337,   337,   337,   337,   337,   338,   339,   340,   341,   343,
     342,   344,   344,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   346,   348,   347,   349,   349,   350,   350,   350,
     350,   351,   352,   353,   354,   355,   355,   356,   356,   357,
     359,   358,   360,   360,   361,   361,   361,   361,   362,   363,
     365,   364,   366,   366,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   369,   368,   370,   370,   371,   371,
     371,   372,   374,   373,   375,   375,   376,   376,   376,   376,
     376,   376,   376,   376,   376,   376,   378,   377,   379,   379,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   389,   391,   390,   392,   392,   393,
     393,   394,   395,   396,   397,   399,   398,   400,   400,   401,
     401,   401,   402,   403,   405,   404,   406,   406,   407,   407,
     407,   408,   409,   410,   411,   411,   412,   412,   413,   415,
     414,   416,   416,   417,   417,   417,   418,   419,   420,   421,
     421,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     472,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   490,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   492,   493,   494,   495,   496,   497,
     498,   499
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
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
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
#line 381 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3385 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 382 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3391 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 383 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3397 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 384 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3403 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 385 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3409 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 386 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3415 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 387 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3421 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 388 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3427 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 389 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3433 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 392 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3439 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 393 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3445 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 394 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3451 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 395 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3457 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 396 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3463 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 404 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3472 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 414 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3481 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 420 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3489 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 427 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3498 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 431 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3507 "conf_parser.c"
    break;

  case 69: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 459 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3519 "conf_parser.c"
    break;

  case 70: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 468 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3531 "conf_parser.c"
    break;

  case 71: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 477 "conf_parser.y"
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
#line 3549 "conf_parser.c"
    break;

  case 72: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 492 "conf_parser.y"
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
#line 3567 "conf_parser.c"
    break;

  case 73: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 507 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3580 "conf_parser.c"
    break;

  case 74: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 517 "conf_parser.y"
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
#line 3597 "conf_parser.c"
    break;

  case 75: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 531 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3609 "conf_parser.c"
    break;

  case 76: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 540 "conf_parser.y"
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
#line 3635 "conf_parser.c"
    break;

  case 77: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 563 "conf_parser.y"
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
#line 3661 "conf_parser.c"
    break;

  case 78: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 586 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigServerInfo.max_topic_length = TOPICLEN;
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3672 "conf_parser.c"
    break;

  case 79: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 594 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3684 "conf_parser.c"
    break;

  case 80: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 603 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3693 "conf_parser.c"
    break;

  case 88: /* admin_name: NAME '=' QSTRING ';'  */
#line 621 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3705 "conf_parser.c"
    break;

  case 89: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 630 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3717 "conf_parser.c"
    break;

  case 90: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 639 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3729 "conf_parser.c"
    break;

  case 91: /* $@1: %empty  */
#line 652 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3738 "conf_parser.c"
    break;

  case 92: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 656 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3755 "conf_parser.c"
    break;

  case 98: /* motd_mask: MASK '=' QSTRING ';'  */
#line 673 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3764 "conf_parser.c"
    break;

  case 99: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 679 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3773 "conf_parser.c"
    break;

  case 100: /* $@2: %empty  */
#line 689 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3782 "conf_parser.c"
    break;

  case 101: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 693 "conf_parser.y"
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
#line 3800 "conf_parser.c"
    break;

  case 109: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 711 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3809 "conf_parser.c"
    break;

  case 110: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 717 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3818 "conf_parser.c"
    break;

  case 111: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 723 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3827 "conf_parser.c"
    break;

  case 112: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 729 "conf_parser.y"
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
#line 3849 "conf_parser.c"
    break;

  case 119: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 758 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 3861 "conf_parser.c"
    break;

  case 120: /* $@3: %empty  */
#line 767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3870 "conf_parser.c"
    break;

  case 121: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 771 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3883 "conf_parser.c"
    break;

  case 128: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 787 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3894 "conf_parser.c"
    break;

  case 129: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 795 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3902 "conf_parser.c"
    break;

  case 130: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 798 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3910 "conf_parser.c"
    break;

  case 131: /* $@4: %empty  */
#line 803 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3919 "conf_parser.c"
    break;

  case 133: /* logging_file_type_item: USER  */
#line 809 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3928 "conf_parser.c"
    break;

  case 134: /* logging_file_type_item: OPERATOR  */
#line 813 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3937 "conf_parser.c"
    break;

  case 135: /* logging_file_type_item: XLINE  */
#line 817 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3946 "conf_parser.c"
    break;

  case 136: /* logging_file_type_item: RESV  */
#line 821 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3955 "conf_parser.c"
    break;

  case 137: /* logging_file_type_item: T_DLINE  */
#line 825 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3964 "conf_parser.c"
    break;

  case 138: /* logging_file_type_item: KLINE  */
#line 829 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3973 "conf_parser.c"
    break;

  case 139: /* logging_file_type_item: KILL  */
#line 833 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3982 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: T_DEBUG  */
#line 837 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3991 "conf_parser.c"
    break;

  case 141: /* $@5: %empty  */
#line 847 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4003 "conf_parser.c"
    break;

  case 142: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 854 "conf_parser.y"
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
    address_parse_prefix(oper->host, &oper->addr, &oper->bits);

    oper_assign_class(oper, block_state.klass.buf);
  }
}
#line 4061 "conf_parser.c"
    break;

  case 156: /* oper_name: NAME '=' QSTRING ';'  */
#line 922 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4070 "conf_parser.c"
    break;

  case 157: /* oper_user: USER '=' QSTRING ';'  */
#line 928 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4079 "conf_parser.c"
    break;

  case 158: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 934 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4088 "conf_parser.c"
    break;

  case 159: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 940 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4097 "conf_parser.c"
    break;

  case 160: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 946 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4111 "conf_parser.c"
    break;

  case 161: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 957 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4120 "conf_parser.c"
    break;

  case 162: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 963 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4134 "conf_parser.c"
    break;

  case 163: /* oper_class: CLASS '=' QSTRING ';'  */
#line 974 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4143 "conf_parser.c"
    break;

  case 164: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 980 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4152 "conf_parser.c"
    break;

  case 165: /* $@6: %empty  */
#line 986 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4161 "conf_parser.c"
    break;

  case 169: /* oper_flags_item: KILL ':' REMOTE  */
#line 993 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4170 "conf_parser.c"
    break;

  case 170: /* oper_flags_item: KILL  */
#line 997 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4179 "conf_parser.c"
    break;

  case 171: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1001 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4188 "conf_parser.c"
    break;

  case 172: /* oper_flags_item: CONNECT  */
#line 1005 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4197 "conf_parser.c"
    break;

  case 173: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1009 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4206 "conf_parser.c"
    break;

  case 174: /* oper_flags_item: SQUIT  */
#line 1013 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4215 "conf_parser.c"
    break;

  case 175: /* oper_flags_item: KLINE  */
#line 1017 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4224 "conf_parser.c"
    break;

  case 176: /* oper_flags_item: UNKLINE  */
#line 1021 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4233 "conf_parser.c"
    break;

  case 177: /* oper_flags_item: T_DLINE  */
#line 1025 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4242 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: T_UNDLINE  */
#line 1029 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4251 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: XLINE  */
#line 1033 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4260 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: T_UNXLINE  */
#line 1037 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4269 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: DIE  */
#line 1041 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4278 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: T_RESTART  */
#line 1045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4287 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4296 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: REHASH  */
#line 1053 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4305 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: ADMIN  */
#line 1057 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4314 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_GLOBOPS  */
#line 1061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4323 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_LOCOPS  */
#line 1065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4332 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: REMOTEBAN  */
#line 1069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4341 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_SET  */
#line 1073 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4350 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: MODULE  */
#line 1077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4359 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_OPME  */
#line 1081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4368 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: NICK ':' RESV  */
#line 1085 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4377 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: JOIN ':' RESV  */
#line 1089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4386 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: RESV  */
#line 1093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4395 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_UNRESV  */
#line 1097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4404 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: CLOSE  */
#line 1101 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4413 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1105 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4422 "conf_parser.c"
    break;

  case 198: /* $@7: %empty  */
#line 1115 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.con_freq.value  = CLASS_DEFAULT_CONNECT_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4438 "conf_parser.c"
    break;

  case 199: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1126 "conf_parser.y"
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
#line 4486 "conf_parser.c"
    break;

  case 218: /* class_name: NAME '=' QSTRING ';'  */
#line 1189 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4495 "conf_parser.c"
    break;

  case 219: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1195 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4504 "conf_parser.c"
    break;

  case 220: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1201 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4513 "conf_parser.c"
    break;

  case 221: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1207 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4522 "conf_parser.c"
    break;

  case 222: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1213 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4531 "conf_parser.c"
    break;

  case 223: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1219 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4540 "conf_parser.c"
    break;

  case 224: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1225 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4549 "conf_parser.c"
    break;

  case 225: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1231 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4558 "conf_parser.c"
    break;

  case 226: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1237 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4568 "conf_parser.c"
    break;

  case 227: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1244 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4577 "conf_parser.c"
    break;

  case 228: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1250 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4586 "conf_parser.c"
    break;

  case 229: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1256 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4595 "conf_parser.c"
    break;

  case 230: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1262 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4607 "conf_parser.c"
    break;

  case 231: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1271 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4619 "conf_parser.c"
    break;

  case 232: /* $@8: %empty  */
#line 1280 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4628 "conf_parser.c"
    break;

  case 236: /* class_flags_item: RANDOM_IDLE  */
#line 1287 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4637 "conf_parser.c"
    break;

  case 237: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1291 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4646 "conf_parser.c"
    break;

  case 238: /* $@9: %empty  */
#line 1301 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4655 "conf_parser.c"
    break;

  case 240: /* $@10: %empty  */
#line 1307 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4663 "conf_parser.c"
    break;

  case 244: /* listen_flags_item: T_TLS  */
#line 1313 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4672 "conf_parser.c"
    break;

  case 245: /* listen_flags_item: HIDDEN  */
#line 1317 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4681 "conf_parser.c"
    break;

  case 246: /* listen_flags_item: T_SERVER  */
#line 1321 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4690 "conf_parser.c"
    break;

  case 247: /* listen_flags_item: CLIENT  */
#line 1325 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4699 "conf_parser.c"
    break;

  case 248: /* listen_flags_item: DEFER  */
#line 1329 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4708 "conf_parser.c"
    break;

  case 256: /* $@11: %empty  */
#line 1337 "conf_parser.y"
                                 { reset_block_state(); }
#line 4714 "conf_parser.c"
    break;

  case 260: /* port_item: NUMBER  */
#line 1342 "conf_parser.y"
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
#line 4732 "conf_parser.c"
    break;

  case 261: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1355 "conf_parser.y"
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
#line 4752 "conf_parser.c"
    break;

  case 262: /* listen_address: IP '=' QSTRING ';'  */
#line 1372 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4761 "conf_parser.c"
    break;

  case 263: /* listen_host: HOST '=' QSTRING ';'  */
#line 1378 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4770 "conf_parser.c"
    break;

  case 264: /* $@12: %empty  */
#line 1388 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4779 "conf_parser.c"
    break;

  case 265: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1392 "conf_parser.y"
{
  struct conf_auth *auth = NULL;
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
  {
    char *const mask = node->data;

    if (string_is_empty(mask))
      continue;

    struct nuh_split nuh =
    {
      .nuhmask = mask,
      .nickptr = NULL,
      .userptr = block_state.user.buf,
      .hostptr = block_state.host.buf,
      .nicksize = 0,
      .usersize = sizeof(block_state.user.buf),
      .hostsize = sizeof(block_state.host.buf)
    };

    nuh_split(&nuh);

    if (auth)
    {
      if (!conf_auth_add_rule(auth, block_state.user.buf, block_state.host.buf))
        conf_error_report("Unable to add auth rule");

      continue;
    }

    const struct conf_auth_spec spec =
    {
      .user = block_state.user.buf,
      .host = block_state.host.buf,
      .password = block_state.rpass.buf,
      .spoof = block_state.name.buf,
      .class_name = block_state.klass.buf,
      .flags = block_state.flags.value
    };

    auth = conf_auth_add(&spec);
    if (auth == NULL)
      conf_error_report("Unable to add auth block");
  }
}
#line 4834 "conf_parser.c"
    break;

  case 275: /* auth_user: USER '=' QSTRING ';'  */
#line 1453 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4843 "conf_parser.c"
    break;

  case 276: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1459 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4852 "conf_parser.c"
    break;

  case 277: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1465 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4861 "conf_parser.c"
    break;

  case 278: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1471 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 4875 "conf_parser.c"
    break;

  case 279: /* $@13: %empty  */
#line 1482 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 4884 "conf_parser.c"
    break;

  case 283: /* auth_flags_item: EXCEED_LIMIT  */
#line 1490 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 4893 "conf_parser.c"
    break;

  case 284: /* auth_flags_item: KLINE_EXEMPT  */
#line 1494 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 4902 "conf_parser.c"
    break;

  case 285: /* auth_flags_item: XLINE_EXEMPT  */
#line 1498 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 4911 "conf_parser.c"
    break;

  case 286: /* auth_flags_item: NEED_IDENT  */
#line 1502 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 4920 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: CAN_FLOOD  */
#line 1506 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 4929 "conf_parser.c"
    break;

  case 288: /* auth_flags_item: NO_TILDE  */
#line 1510 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 4938 "conf_parser.c"
    break;

  case 289: /* auth_flags_item: RESV_EXEMPT  */
#line 1514 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 4947 "conf_parser.c"
    break;

  case 290: /* auth_flags_item: T_WEBIRC  */
#line 1518 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 4956 "conf_parser.c"
    break;

  case 291: /* auth_flags_item: NEED_PASSWORD  */
#line 1522 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 4965 "conf_parser.c"
    break;

  case 292: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1528 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    log_write(LOG_TYPE_IRCD,
              "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 4980 "conf_parser.c"
    break;

  case 293: /* $@14: %empty  */
#line 1543 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4992 "conf_parser.c"
    break;

  case 294: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1550 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5003 "conf_parser.c"
    break;

  case 301: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1561 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5012 "conf_parser.c"
    break;

  case 302: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1567 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5021 "conf_parser.c"
    break;

  case 303: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1573 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5030 "conf_parser.c"
    break;

  case 309: /* service_name: NAME '=' QSTRING ';'  */
#line 1588 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5045 "conf_parser.c"
    break;

  case 310: /* $@15: %empty  */
#line 1604 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5061 "conf_parser.c"
    break;

  case 311: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1615 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5076 "conf_parser.c"
    break;

  case 318: /* shared_name: NAME '=' QSTRING ';'  */
#line 1630 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5085 "conf_parser.c"
    break;

  case 319: /* shared_user: USER '=' QSTRING ';'  */
#line 1636 "conf_parser.y"
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
#line 5107 "conf_parser.c"
    break;

  case 320: /* $@16: %empty  */
#line 1655 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5116 "conf_parser.c"
    break;

  case 324: /* shared_type_item: KLINE  */
#line 1662 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5125 "conf_parser.c"
    break;

  case 325: /* shared_type_item: UNKLINE  */
#line 1666 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5134 "conf_parser.c"
    break;

  case 326: /* shared_type_item: T_DLINE  */
#line 1670 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5143 "conf_parser.c"
    break;

  case 327: /* shared_type_item: T_UNDLINE  */
#line 1674 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5152 "conf_parser.c"
    break;

  case 328: /* shared_type_item: XLINE  */
#line 1678 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5161 "conf_parser.c"
    break;

  case 329: /* shared_type_item: T_UNXLINE  */
#line 1682 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5170 "conf_parser.c"
    break;

  case 330: /* shared_type_item: RESV  */
#line 1686 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5179 "conf_parser.c"
    break;

  case 331: /* shared_type_item: T_UNRESV  */
#line 1690 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5188 "conf_parser.c"
    break;

  case 332: /* shared_type_item: T_LOCOPS  */
#line 1694 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5197 "conf_parser.c"
    break;

  case 333: /* shared_type_item: T_ALL  */
#line 1698 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5206 "conf_parser.c"
    break;

  case 334: /* $@17: %empty  */
#line 1708 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5220 "conf_parser.c"
    break;

  case 335: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1717 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5233 "conf_parser.c"
    break;

  case 341: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1730 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5242 "conf_parser.c"
    break;

  case 342: /* $@18: %empty  */
#line 1736 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5251 "conf_parser.c"
    break;

  case 346: /* cluster_type_item: KLINE  */
#line 1743 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5260 "conf_parser.c"
    break;

  case 347: /* cluster_type_item: UNKLINE  */
#line 1747 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5269 "conf_parser.c"
    break;

  case 348: /* cluster_type_item: T_DLINE  */
#line 1751 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5278 "conf_parser.c"
    break;

  case 349: /* cluster_type_item: T_UNDLINE  */
#line 1755 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5287 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: XLINE  */
#line 1759 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5296 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: T_UNXLINE  */
#line 1763 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5305 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: RESV  */
#line 1767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5314 "conf_parser.c"
    break;

  case 353: /* cluster_type_item: T_UNRESV  */
#line 1771 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5323 "conf_parser.c"
    break;

  case 354: /* cluster_type_item: T_LOCOPS  */
#line 1775 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5332 "conf_parser.c"
    break;

  case 355: /* cluster_type_item: T_ALL  */
#line 1779 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5341 "conf_parser.c"
    break;

  case 356: /* $@19: %empty  */
#line 1789 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5355 "conf_parser.c"
    break;

  case 357: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1798 "conf_parser.y"
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
#line 5403 "conf_parser.c"
    break;

  case 375: /* connect_name: NAME '=' QSTRING ';'  */
#line 1860 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5412 "conf_parser.c"
    break;

  case 376: /* connect_host: HOST '=' QSTRING ';'  */
#line 1866 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5421 "conf_parser.c"
    break;

  case 377: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1872 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5430 "conf_parser.c"
    break;

  case 378: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1878 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5439 "conf_parser.c"
    break;

  case 379: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1884 "conf_parser.y"
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
#line 5455 "conf_parser.c"
    break;

  case 380: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1897 "conf_parser.y"
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
#line 5471 "conf_parser.c"
    break;

  case 381: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1910 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5480 "conf_parser.c"
    break;

  case 382: /* connect_port: PORT '=' NUMBER ';'  */
#line 1916 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5489 "conf_parser.c"
    break;

  case 383: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 1922 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5498 "conf_parser.c"
    break;

  case 384: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 1926 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5507 "conf_parser.c"
    break;

  case 385: /* $@20: %empty  */
#line 1932 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5515 "conf_parser.c"
    break;

  case 389: /* connect_flags_item: AUTOCONN  */
#line 1938 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5524 "conf_parser.c"
    break;

  case 390: /* connect_flags_item: T_TLS  */
#line 1942 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5533 "conf_parser.c"
    break;

  case 391: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1948 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5547 "conf_parser.c"
    break;

  case 392: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 1959 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5556 "conf_parser.c"
    break;

  case 393: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 1965 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5565 "conf_parser.c"
    break;

  case 394: /* connect_class: CLASS '=' QSTRING ';'  */
#line 1971 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5574 "conf_parser.c"
    break;

  case 395: /* $@21: %empty  */
#line 1981 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5583 "conf_parser.c"
    break;

  case 396: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 1985 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.user.buf[0] ||
      !block_state.host.buf[0])
    break;

  const struct conf_kill_spec spec =
  {
    .user = block_state.user.buf,
    .host = block_state.host.buf,
    .reason = block_state.rpass.buf[0] ? block_state.rpass.buf : CONF_NOREASON,
    .origin = CONF_KILL_ORIGIN_CONFIG
  };

  if (conf_kill_add(&spec) == NULL)
    conf_error_report("Unable to add K-line");
}
#line 5607 "conf_parser.c"
    break;

  case 402: /* kill_user: USER '=' QSTRING ';'  */
#line 2009 "conf_parser.y"
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
#line 5630 "conf_parser.c"
    break;

  case 403: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2029 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5639 "conf_parser.c"
    break;

  case 404: /* $@22: %empty  */
#line 2039 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5648 "conf_parser.c"
    break;

  case 405: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2043 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  const struct conf_deny_spec spec =
  {
    .prefix = block_state.addr.buf,
    .reason = block_state.rpass.buf[0] ? block_state.rpass.buf : CONF_NOREASON,
    .origin = CONF_DENY_ORIGIN_CONFIG
  };

  if (conf_deny_add(&spec) == NULL)
    conf_error_report("Unable to add D-line");
}
#line 5670 "conf_parser.c"
    break;

  case 411: /* deny_ip: IP '=' QSTRING ';'  */
#line 2065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5679 "conf_parser.c"
    break;

  case 412: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2071 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5688 "conf_parser.c"
    break;

  case 418: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2086 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_error_report("Unable to add D-line exemption");
}
#line 5700 "conf_parser.c"
    break;

  case 419: /* $@23: %empty  */
#line 2099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5709 "conf_parser.c"
    break;

  case 420: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2103 "conf_parser.y"
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
#line 5729 "conf_parser.c"
    break;

  case 426: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2123 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5738 "conf_parser.c"
    break;

  case 427: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2129 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5747 "conf_parser.c"
    break;

  case 480: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2193 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5755 "conf_parser.c"
    break;

  case 481: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2198 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5763 "conf_parser.c"
    break;

  case 482: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2203 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5771 "conf_parser.c"
    break;

  case 483: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2208 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5779 "conf_parser.c"
    break;

  case 484: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2213 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5787 "conf_parser.c"
    break;

  case 485: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2218 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5795 "conf_parser.c"
    break;

  case 486: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2223 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5803 "conf_parser.c"
    break;

  case 487: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2228 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5811 "conf_parser.c"
    break;

  case 488: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2233 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5819 "conf_parser.c"
    break;

  case 489: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2238 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5827 "conf_parser.c"
    break;

  case 490: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2243 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5835 "conf_parser.c"
    break;

  case 491: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2248 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5843 "conf_parser.c"
    break;

  case 492: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2253 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5851 "conf_parser.c"
    break;

  case 493: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2258 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5859 "conf_parser.c"
    break;

  case 494: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2263 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 5870 "conf_parser.c"
    break;

  case 495: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2271 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5878 "conf_parser.c"
    break;

  case 496: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2276 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5886 "conf_parser.c"
    break;

  case 497: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2281 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5894 "conf_parser.c"
    break;

  case 498: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2286 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5902 "conf_parser.c"
    break;

  case 499: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2291 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5910 "conf_parser.c"
    break;

  case 500: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2296 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5918 "conf_parser.c"
    break;

  case 501: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2301 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5926 "conf_parser.c"
    break;

  case 502: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2306 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5934 "conf_parser.c"
    break;

  case 503: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2311 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5942 "conf_parser.c"
    break;

  case 504: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2316 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5950 "conf_parser.c"
    break;

  case 505: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2321 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5958 "conf_parser.c"
    break;

  case 506: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2326 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 5966 "conf_parser.c"
    break;

  case 507: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2331 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5974 "conf_parser.c"
    break;

  case 508: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2336 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 5982 "conf_parser.c"
    break;

  case 509: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2341 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5990 "conf_parser.c"
    break;

  case 510: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2346 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5998 "conf_parser.c"
    break;

  case 511: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2351 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6006 "conf_parser.c"
    break;

  case 512: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2356 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6014 "conf_parser.c"
    break;

  case 513: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2361 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6022 "conf_parser.c"
    break;

  case 514: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2366 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6030 "conf_parser.c"
    break;

  case 515: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2371 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6042 "conf_parser.c"
    break;

  case 516: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2380 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6050 "conf_parser.c"
    break;

  case 517: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2385 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6058 "conf_parser.c"
    break;

  case 518: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2390 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6066 "conf_parser.c"
    break;

  case 519: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2395 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6074 "conf_parser.c"
    break;

  case 520: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2400 "conf_parser.y"
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
#line 6094 "conf_parser.c"
    break;

  case 521: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2417 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6105 "conf_parser.c"
    break;

  case 522: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2425 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6116 "conf_parser.c"
    break;

  case 523: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2433 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6127 "conf_parser.c"
    break;

  case 524: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2441 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6140 "conf_parser.c"
    break;

  case 525: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2451 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6153 "conf_parser.c"
    break;

  case 526: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2461 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6164 "conf_parser.c"
    break;

  case 527: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2469 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6172 "conf_parser.c"
    break;

  case 547: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2498 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6180 "conf_parser.c"
    break;

  case 548: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2503 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6188 "conf_parser.c"
    break;

  case 549: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2508 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6196 "conf_parser.c"
    break;

  case 550: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2513 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6204 "conf_parser.c"
    break;

  case 551: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2518 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6212 "conf_parser.c"
    break;

  case 552: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2523 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6220 "conf_parser.c"
    break;

  case 553: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2528 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6228 "conf_parser.c"
    break;

  case 554: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2533 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6236 "conf_parser.c"
    break;

  case 555: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2538 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6244 "conf_parser.c"
    break;

  case 556: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2543 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6252 "conf_parser.c"
    break;

  case 557: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2548 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6260 "conf_parser.c"
    break;

  case 558: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2553 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6268 "conf_parser.c"
    break;

  case 559: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2558 "conf_parser.y"
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
#line 6294 "conf_parser.c"
    break;

  case 560: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2581 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6302 "conf_parser.c"
    break;

  case 561: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2586 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6310 "conf_parser.c"
    break;

  case 574: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2608 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6319 "conf_parser.c"
    break;

  case 575: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2614 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6333 "conf_parser.c"
    break;

  case 576: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2625 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6345 "conf_parser.c"
    break;

  case 577: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2634 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6354 "conf_parser.c"
    break;

  case 578: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2640 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6363 "conf_parser.c"
    break;

  case 579: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2646 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6372 "conf_parser.c"
    break;

  case 580: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2652 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6384 "conf_parser.c"
    break;

  case 581: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2661 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6393 "conf_parser.c"
    break;


#line 6397 "conf_parser.c"

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

