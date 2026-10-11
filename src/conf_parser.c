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
    STATS_U_OPER_ONLY = 419,       /* STATS_U_OPER_ONLY  */
    T_ALL = 420,                   /* T_ALL  */
    T_BIND = 421,                  /* T_BIND  */
    T_COMMAND = 422,               /* T_COMMAND  */
    T_CLUSTER = 423,               /* T_CLUSTER  */
    T_DEBUG = 424,                 /* T_DEBUG  */
    T_DLINE = 425,                 /* T_DLINE  */
    T_FILE = 426,                  /* T_FILE  */
    T_GLOBOPS = 427,               /* T_GLOBOPS  */
    T_IPV4 = 428,                  /* T_IPV4  */
    T_IPV6 = 429,                  /* T_IPV6  */
    T_LOCOPS = 430,                /* T_LOCOPS  */
    T_LOG = 431,                   /* T_LOG  */
    T_OPME = 432,                  /* T_OPME  */
    T_PREPEND = 433,               /* T_PREPEND  */
    T_PSEUDO = 434,                /* T_PSEUDO  */
    T_RECVQ = 435,                 /* T_RECVQ  */
    T_RESTART = 436,               /* T_RESTART  */
    T_SERVER = 437,                /* T_SERVER  */
    T_SERVICE = 438,               /* T_SERVICE  */
    T_SET = 439,                   /* T_SET  */
    T_SHARED = 440,                /* T_SHARED  */
    T_SIZE = 441,                  /* T_SIZE  */
    T_TARGET = 442,                /* T_TARGET  */
    T_TLS = 443,                   /* T_TLS  */
    T_UMODES = 444,                /* T_UMODES  */
    T_UNDLINE = 445,               /* T_UNDLINE  */
    T_UNLIMITED = 446,             /* T_UNLIMITED  */
    T_UNRESV = 447,                /* T_UNRESV  */
    T_UNXLINE = 448,               /* T_UNXLINE  */
    T_WEBIRC = 449,                /* T_WEBIRC  */
    TBOOL = 450,                   /* TBOOL  */
    THROTTLE_COUNT = 451,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 452,           /* THROTTLE_TIME  */
    TIMEOUT = 453,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 454,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 455, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 456,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 457, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 458,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 459,           /* TS_WARN_DELTA  */
    TWODOTS = 460,                 /* TWODOTS  */
    TYPE = 461,                    /* TYPE  */
    UNKLINE = 462,                 /* UNKLINE  */
    USE_LOGGING = 463,             /* USE_LOGGING  */
    USER = 464,                    /* USER  */
    VHOST = 465,                   /* VHOST  */
    VHOST6 = 466,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 467,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 468,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 469,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 470,                   /* XLINE  */
    XLINE_EXEMPT = 471,            /* XLINE_EXEMPT  */
    QSTRING = 472,                 /* QSTRING  */
    NUMBER = 473                   /* NUMBER  */
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
#define STATS_U_OPER_ONLY 419
#define T_ALL 420
#define T_BIND 421
#define T_COMMAND 422
#define T_CLUSTER 423
#define T_DEBUG 424
#define T_DLINE 425
#define T_FILE 426
#define T_GLOBOPS 427
#define T_IPV4 428
#define T_IPV6 429
#define T_LOCOPS 430
#define T_LOG 431
#define T_OPME 432
#define T_PREPEND 433
#define T_PSEUDO 434
#define T_RECVQ 435
#define T_RESTART 436
#define T_SERVER 437
#define T_SERVICE 438
#define T_SET 439
#define T_SHARED 440
#define T_SIZE 441
#define T_TARGET 442
#define T_TLS 443
#define T_UMODES 444
#define T_UNDLINE 445
#define T_UNLIMITED 446
#define T_UNRESV 447
#define T_UNXLINE 448
#define T_WEBIRC 449
#define TBOOL 450
#define THROTTLE_COUNT 451
#define THROTTLE_TIME 452
#define TIMEOUT 453
#define TLS_CERTIFICATE_FILE 454
#define TLS_CERTIFICATE_FINGERPRINT 455
#define TLS_PRIVATE_KEY_FILE 456
#define TLS_CONNECTION_REQUIRED 457
#define TS_MAX_DELTA 458
#define TS_WARN_DELTA 459
#define TWODOTS 460
#define TYPE 461
#define UNKLINE 462
#define USE_LOGGING 463
#define USER 464
#define VHOST 465
#define VHOST6 466
#define WARN_NO_CONNECT_BLOCK 467
#define WHOIS 468
#define WHOWAS_HISTORY_LENGTH 469
#define XLINE 470
#define XLINE_EXEMPT 471
#define QSTRING 472
#define NUMBER 473

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 686 "conf_parser.c"

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
  YYSYMBOL_STATS_U_OPER_ONLY = 164,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 165,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 166,                   /* T_BIND  */
  YYSYMBOL_T_COMMAND = 167,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 168,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 169,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 170,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 171,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 172,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 173,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 174,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 175,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 176,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 177,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 178,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 179,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 180,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 181,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 182,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 183,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 184,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 185,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 186,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 187,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 188,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 189,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 190,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 191,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 192,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 193,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 194,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 195,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 196,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 197,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 198,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 199,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 200, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_PRIVATE_KEY_FILE = 201,     /* TLS_PRIVATE_KEY_FILE  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 202,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TS_MAX_DELTA = 203,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 204,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 205,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 206,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 207,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 208,              /* USE_LOGGING  */
  YYSYMBOL_USER = 209,                     /* USER  */
  YYSYMBOL_VHOST = 210,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 211,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 212,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 213,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 214,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 215,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 216,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 217,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 218,                   /* NUMBER  */
  YYSYMBOL_219_ = 219,                     /* ';'  */
  YYSYMBOL_220_ = 220,                     /* '}'  */
  YYSYMBOL_221_ = 221,                     /* '='  */
  YYSYMBOL_222_ = 222,                     /* ':'  */
  YYSYMBOL_223_ = 223,                     /* ','  */
  YYSYMBOL_224_ = 224,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 225,                 /* $accept  */
  YYSYMBOL_conf = 226,                     /* conf  */
  YYSYMBOL_conf_item = 227,                /* conf_item  */
  YYSYMBOL_timespec_ = 228,                /* timespec_  */
  YYSYMBOL_timespec = 229,                 /* timespec  */
  YYSYMBOL_sizespec_ = 230,                /* sizespec_  */
  YYSYMBOL_sizespec = 231,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 232,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 233,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 234,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 235,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 236,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 237,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 238,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 239,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 240, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_tls_private_key_file = 241, /* serverinfo_tls_private_key_file  */
  YYSYMBOL_serverinfo_name = 242,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 243,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 244,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 245,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 246, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 247, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 248, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 249, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_motd_file = 250,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 251,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 252,              /* admin_entry  */
  YYSYMBOL_admin_items = 253,              /* admin_items  */
  YYSYMBOL_admin_item = 254,               /* admin_item  */
  YYSYMBOL_admin_name = 255,               /* admin_name  */
  YYSYMBOL_admin_email = 256,              /* admin_email  */
  YYSYMBOL_admin_description = 257,        /* admin_description  */
  YYSYMBOL_motd_entry = 258,               /* motd_entry  */
  YYSYMBOL_259_1 = 259,                    /* $@1  */
  YYSYMBOL_motd_items = 260,               /* motd_items  */
  YYSYMBOL_motd_item = 261,                /* motd_item  */
  YYSYMBOL_motd_mask = 262,                /* motd_mask  */
  YYSYMBOL_motd_file = 263,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 264,             /* pseudo_entry  */
  YYSYMBOL_265_2 = 265,                    /* $@2  */
  YYSYMBOL_pseudo_items = 266,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 267,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 268,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 269,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 270,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 271,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 272,            /* logging_entry  */
  YYSYMBOL_logging_items = 273,            /* logging_items  */
  YYSYMBOL_logging_item = 274,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 275,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 276,       /* logging_file_entry  */
  YYSYMBOL_277_3 = 277,                    /* $@3  */
  YYSYMBOL_logging_file_items = 278,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 279,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 280,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 281,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 282,        /* logging_file_type  */
  YYSYMBOL_283_4 = 283,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 284,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 285,               /* oper_entry  */
  YYSYMBOL_286_5 = 286,                    /* $@5  */
  YYSYMBOL_oper_items = 287,               /* oper_items  */
  YYSYMBOL_oper_item = 288,                /* oper_item  */
  YYSYMBOL_oper_name = 289,                /* oper_name  */
  YYSYMBOL_oper_user = 290,                /* oper_user  */
  YYSYMBOL_oper_password = 291,            /* oper_password  */
  YYSYMBOL_oper_whois = 292,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 293,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 294, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 295, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 296,               /* oper_class  */
  YYSYMBOL_oper_umodes = 297,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 298,               /* oper_flags  */
  YYSYMBOL_299_6 = 299,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 300,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 301,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 302,              /* class_entry  */
  YYSYMBOL_303_7 = 303,                    /* $@7  */
  YYSYMBOL_class_items = 304,              /* class_items  */
  YYSYMBOL_class_item = 305,               /* class_item  */
  YYSYMBOL_class_name = 306,               /* class_name  */
  YYSYMBOL_class_ping_time = 307,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 308, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 309, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 310,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 311,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 312,         /* class_max_number  */
  YYSYMBOL_class_sendq = 313,              /* class_sendq  */
  YYSYMBOL_class_recvq = 314,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 315,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 316,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 317,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 318,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 319,           /* class_max_idle  */
  YYSYMBOL_class_flags = 320,              /* class_flags  */
  YYSYMBOL_321_8 = 321,                    /* $@8  */
  YYSYMBOL_class_flags_items = 322,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 323,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 324,             /* listen_entry  */
  YYSYMBOL_325_9 = 325,                    /* $@9  */
  YYSYMBOL_listen_flags = 326,             /* listen_flags  */
  YYSYMBOL_327_10 = 327,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 328,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 329,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 330,             /* listen_items  */
  YYSYMBOL_listen_item = 331,              /* listen_item  */
  YYSYMBOL_listen_port = 332,              /* listen_port  */
  YYSYMBOL_333_11 = 333,                   /* $@11  */
  YYSYMBOL_port_items = 334,               /* port_items  */
  YYSYMBOL_port_item = 335,                /* port_item  */
  YYSYMBOL_listen_address = 336,           /* listen_address  */
  YYSYMBOL_listen_host = 337,              /* listen_host  */
  YYSYMBOL_auth_entry = 338,               /* auth_entry  */
  YYSYMBOL_339_12 = 339,                   /* $@12  */
  YYSYMBOL_auth_items = 340,               /* auth_items  */
  YYSYMBOL_auth_item = 341,                /* auth_item  */
  YYSYMBOL_auth_user = 342,                /* auth_user  */
  YYSYMBOL_auth_passwd = 343,              /* auth_passwd  */
  YYSYMBOL_auth_class = 344,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 345,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 346,               /* auth_flags  */
  YYSYMBOL_347_13 = 347,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 348,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 349,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 350,               /* auth_spoof  */
  YYSYMBOL_resv_entry = 351,               /* resv_entry  */
  YYSYMBOL_352_14 = 352,                   /* $@14  */
  YYSYMBOL_resv_items = 353,               /* resv_items  */
  YYSYMBOL_resv_item = 354,                /* resv_item  */
  YYSYMBOL_resv_mask = 355,                /* resv_mask  */
  YYSYMBOL_resv_reason = 356,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 357,              /* resv_exempt  */
  YYSYMBOL_service_entry = 358,            /* service_entry  */
  YYSYMBOL_service_items = 359,            /* service_items  */
  YYSYMBOL_service_item = 360,             /* service_item  */
  YYSYMBOL_service_name = 361,             /* service_name  */
  YYSYMBOL_shared_entry = 362,             /* shared_entry  */
  YYSYMBOL_363_15 = 363,                   /* $@15  */
  YYSYMBOL_shared_items = 364,             /* shared_items  */
  YYSYMBOL_shared_item = 365,              /* shared_item  */
  YYSYMBOL_shared_name = 366,              /* shared_name  */
  YYSYMBOL_shared_user = 367,              /* shared_user  */
  YYSYMBOL_shared_type = 368,              /* shared_type  */
  YYSYMBOL_369_16 = 369,                   /* $@16  */
  YYSYMBOL_shared_types = 370,             /* shared_types  */
  YYSYMBOL_shared_type_item = 371,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 372,            /* cluster_entry  */
  YYSYMBOL_373_17 = 373,                   /* $@17  */
  YYSYMBOL_cluster_items = 374,            /* cluster_items  */
  YYSYMBOL_cluster_item = 375,             /* cluster_item  */
  YYSYMBOL_cluster_name = 376,             /* cluster_name  */
  YYSYMBOL_cluster_type = 377,             /* cluster_type  */
  YYSYMBOL_378_18 = 378,                   /* $@18  */
  YYSYMBOL_cluster_types = 379,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 380,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 381,            /* connect_entry  */
  YYSYMBOL_382_19 = 382,                   /* $@19  */
  YYSYMBOL_connect_items = 383,            /* connect_items  */
  YYSYMBOL_connect_item = 384,             /* connect_item  */
  YYSYMBOL_connect_name = 385,             /* connect_name  */
  YYSYMBOL_connect_host = 386,             /* connect_host  */
  YYSYMBOL_connect_timeout = 387,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 388,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 389,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 390,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 391, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 392,             /* connect_port  */
  YYSYMBOL_connect_aftype = 393,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 394,            /* connect_flags  */
  YYSYMBOL_395_20 = 395,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 396,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 397,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 398,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 399,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 400,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 401,            /* connect_class  */
  YYSYMBOL_kill_entry = 402,               /* kill_entry  */
  YYSYMBOL_403_21 = 403,                   /* $@21  */
  YYSYMBOL_kill_items = 404,               /* kill_items  */
  YYSYMBOL_kill_item = 405,                /* kill_item  */
  YYSYMBOL_kill_user = 406,                /* kill_user  */
  YYSYMBOL_kill_reason = 407,              /* kill_reason  */
  YYSYMBOL_deny_entry = 408,               /* deny_entry  */
  YYSYMBOL_409_22 = 409,                   /* $@22  */
  YYSYMBOL_deny_items = 410,               /* deny_items  */
  YYSYMBOL_deny_item = 411,                /* deny_item  */
  YYSYMBOL_deny_ip = 412,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 413,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 414,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 415,             /* exempt_items  */
  YYSYMBOL_exempt_item = 416,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 417,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 418,              /* gecos_entry  */
  YYSYMBOL_419_23 = 419,                   /* $@23  */
  YYSYMBOL_gecos_items = 420,              /* gecos_items  */
  YYSYMBOL_gecos_item = 421,               /* gecos_item  */
  YYSYMBOL_gecos_name = 422,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 423,             /* gecos_reason  */
  YYSYMBOL_general_entry = 424,            /* general_entry  */
  YYSYMBOL_general_items = 425,            /* general_items  */
  YYSYMBOL_general_item = 426,             /* general_item  */
  YYSYMBOL_general_away_count = 427,       /* general_away_count  */
  YYSYMBOL_general_away_time = 428,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 429,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 430, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 431, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 432,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 433,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 434,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 435,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 436, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_failed_oper_notice = 437, /* general_failed_oper_notice  */
  YYSYMBOL_general_anti_nick_flood = 438,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 439,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 440, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 441,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 442,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 443, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 444,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 445,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 446, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 447, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 448, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_u_oper_only = 449, /* general_stats_u_oper_only  */
  YYSYMBOL_general_pace_wait = 450,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 451,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 452, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 453, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 454,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 455,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 456, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 457,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 458,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_ident = 459,    /* general_disable_ident  */
  YYSYMBOL_general_disable_dns = 460,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 461,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 462,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 463,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 464,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 465, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 466, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 467, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 468,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 469, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 470, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 471,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 472,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 473,     /* general_cloak_suffix  */
  YYSYMBOL_general_ident_timeout = 474,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 475, /* general_registration_timeout  */
  YYSYMBOL_channel_entry = 476,            /* channel_entry  */
  YYSYMBOL_channel_items = 477,            /* channel_items  */
  YYSYMBOL_channel_item = 478,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 479,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 480,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 481,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 482, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 483, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 484, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 485, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 486, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 487, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 488, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 489, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 490,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 491,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 492,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 493,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 494,  /* channel_max_kick_length  */
  YYSYMBOL_channel_default_join_flood_count = 495, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 496, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 497,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 498,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 499,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 500, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 501, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 502, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 503, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 504,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 505, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 506,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 507         /* serverhide_hidden  */
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
#define YYLAST   1301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  225
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  283
/* YYNRULES -- Number of rules.  */
#define YYNRULES  589
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1226

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   473


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
       2,     2,     2,     2,   223,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   222,   219,
       2,   221,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   224,     2,   220,     2,     2,     2,     2,
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
     215,   216,   217,   218
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   353,   353,   354,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   385,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   396,
     396,   397,   398,   399,   400,   407,   417,   424,   426,   428,
     428,   430,   434,   444,   446,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   462,
     471,   480,   495,   510,   520,   534,   543,   566,   589,   597,
     606,   616,   618,   618,   619,   620,   621,   622,   624,   633,
     642,   656,   655,   673,   673,   674,   674,   674,   676,   682,
     693,   692,   711,   711,   712,   712,   712,   712,   712,   714,
     720,   726,   732,   755,   756,   756,   758,   758,   759,   761,
     771,   771,   784,   785,   787,   787,   788,   788,   790,   798,
     801,   807,   806,   812,   816,   820,   824,   828,   832,   836,
     840,   851,   850,   912,   912,   913,   914,   915,   916,   917,
     918,   919,   920,   921,   922,   923,   925,   931,   937,   943,
     949,   960,   966,   977,   983,   990,   989,   995,   995,   996,
    1000,  1004,  1008,  1012,  1016,  1020,  1024,  1028,  1032,  1036,
    1040,  1044,  1048,  1052,  1056,  1060,  1064,  1068,  1072,  1076,
    1080,  1084,  1088,  1092,  1096,  1100,  1104,  1108,  1119,  1118,
    1174,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1192,  1198,
    1204,  1210,  1216,  1222,  1228,  1234,  1240,  1247,  1253,  1259,
    1265,  1274,  1284,  1283,  1289,  1289,  1290,  1294,  1305,  1304,
    1311,  1310,  1315,  1315,  1316,  1320,  1324,  1328,  1332,  1338,
    1338,  1339,  1339,  1339,  1339,  1339,  1341,  1341,  1343,  1343,
    1345,  1358,  1375,  1381,  1392,  1391,  1447,  1447,  1448,  1449,
    1450,  1451,  1452,  1453,  1454,  1456,  1462,  1468,  1474,  1486,
    1485,  1491,  1491,  1493,  1497,  1501,  1505,  1509,  1513,  1517,
    1521,  1525,  1531,  1547,  1546,  1561,  1561,  1562,  1562,  1562,
    1562,  1564,  1570,  1576,  1586,  1588,  1588,  1589,  1589,  1591,
    1608,  1607,  1630,  1630,  1631,  1631,  1631,  1631,  1633,  1639,
    1659,  1658,  1664,  1664,  1665,  1669,  1673,  1677,  1681,  1685,
    1689,  1693,  1697,  1701,  1712,  1711,  1730,  1730,  1731,  1731,
    1731,  1733,  1740,  1739,  1745,  1745,  1746,  1750,  1754,  1758,
    1762,  1766,  1770,  1774,  1778,  1782,  1793,  1792,  1846,  1846,
    1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,
    1857,  1858,  1859,  1860,  1861,  1863,  1869,  1875,  1881,  1887,
    1900,  1913,  1919,  1925,  1929,  1936,  1935,  1940,  1940,  1941,
    1945,  1951,  1962,  1968,  1974,  1985,  1984,  2009,  2009,  2010,
    2010,  2010,  2012,  2032,  2043,  2042,  2065,  2065,  2066,  2066,
    2066,  2068,  2074,  2084,  2086,  2086,  2087,  2087,  2089,  2103,
    2102,  2123,  2123,  2124,  2124,  2124,  2126,  2132,  2142,  2144,
    2144,  2145,  2146,  2147,  2148,  2149,  2150,  2151,  2152,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,  2167,  2168,  2169,  2170,  2171,  2172,  2173,
    2174,  2175,  2176,  2177,  2178,  2179,  2180,  2181,  2182,  2183,
    2184,  2185,  2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,
    2194,  2197,  2202,  2207,  2212,  2217,  2222,  2227,  2232,  2237,
    2242,  2247,  2252,  2257,  2262,  2267,  2272,  2280,  2285,  2290,
    2295,  2300,  2305,  2310,  2315,  2320,  2325,  2330,  2335,  2340,
    2345,  2350,  2355,  2360,  2365,  2370,  2375,  2380,  2389,  2394,
    2399,  2404,  2409,  2426,  2434,  2442,  2450,  2460,  2470,  2478,
    2487,  2489,  2489,  2490,  2491,  2492,  2493,  2494,  2495,  2496,
    2497,  2498,  2499,  2500,  2501,  2502,  2503,  2504,  2505,  2506,
    2507,  2508,  2510,  2515,  2521,  2527,  2532,  2537,  2542,  2547,
    2552,  2557,  2562,  2567,  2572,  2577,  2582,  2587,  2610,  2615,
    2624,  2626,  2626,  2627,  2628,  2629,  2630,  2631,  2632,  2633,
    2634,  2635,  2637,  2643,  2654,  2663,  2669,  2675,  2681,  2690
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
  "general_kill_chase_time_limit", "general_failed_oper_notice",
  "general_anti_nick_flood", "general_max_nick_time",
  "general_max_nick_changes", "general_max_accept",
  "general_max_away_length", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_invisible_on_connect", "general_warn_no_connect_block",
  "general_stats_e_disabled", "general_stats_u_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_opers_bypass_callerid", "general_pace_wait_simple",
  "general_short_motd", "general_no_oper_flood",
  "general_specials_in_ident", "general_max_targets",
  "general_ping_cookie", "general_disable_ident", "general_disable_dns",
  "general_throttle_count", "general_throttle_time", "general_oper_umodes",
  "general_min_nonwildcard", "general_min_nonwildcard_simple",
  "general_default_floodcount", "general_default_floodtime",
  "general_cloak_enabled", "general_cloak_cidr_len_ipv4",
  "general_cloak_cidr_len_ipv6", "general_cloak_num_bits",
  "general_cloak_secret", "general_cloak_suffix", "general_ident_timeout",
  "general_registration_timeout", "channel_entry", "channel_items",
  "channel_item", "channel_enable_extbans", "channel_enable_owner",
  "channel_enable_admin", "channel_disable_fake_channels",
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

#define YYPACT_NINF (-970)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -970,   601,  -970,  -169,  -207,  -202,  -970,  -970,  -970,  -193,
    -970,  -183,  -970,  -970,  -970,  -171,  -173,  -970,  -970,  -970,
    -165,  -160,  -970,  -150,  -970,  -148,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,   330,   740,  -143,  -139,  -125,    14,  -122,
     400,  -120,   -99,   -97,   -86,   -61,   -63,   -58,   -56,   765,
     501,   -55,     3,   -53,     4,   -23,   -11,    -8,     6,    38,
      26,  -970,  -970,  -970,  -970,  -970,    62,    63,    66,    71,
      73,    86,    87,    93,    94,    98,    99,   103,   105,   109,
     111,   112,   113,   114,   180,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,   607,   383,    13,  -970,   115,    20,
    -970,  -970,    33,  -970,   118,   120,   121,   127,   128,   129,
     132,   133,   134,   135,   139,   141,   142,   144,   145,   146,
     151,   155,   158,   159,   160,   166,   168,   174,   176,   177,
     182,   183,   190,   197,   199,   207,   208,   209,   215,   216,
     222,   223,   234,   235,   237,   238,   239,   241,   243,   245,
     247,   251,   254,    46,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,   161,    48,   297,   -10,     7,   140,
      36,   274,   360,  -970,   256,   257,   258,   259,   263,   267,
     268,   270,    53,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,   164,   273,   276,   277,   278,   288,   289,   290,
     294,   298,   299,   302,   304,   195,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,   193,
     221,   305,    24,  -970,  -970,  -970,   173,   260,  -970,   306,
      15,  -970,  -970,   184,  -970,   301,   311,   317,   271,  -970,
     198,   321,   340,   347,   348,   352,   332,   321,   321,   321,
     333,   321,   321,   334,   337,   338,   339,   343,   346,  -970,
     349,   341,   345,   350,  -970,   351,   353,   355,   356,   357,
     361,   363,   364,   365,   368,   369,    65,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,   354,   371,   373,   374,   377,   379,   394,
    -970,   395,   405,   407,   409,   410,   411,   412,   219,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,   413,   417,    44,  -970,  -970,
    -970,   404,   422,  -970,  -970,   423,   424,    79,  -970,  -970,
    -970,   372,   321,   425,   321,   321,   375,   429,   430,   433,
     435,   436,   461,   452,   321,   476,   478,   457,   458,   482,
     321,   486,   321,   466,   468,   469,   470,   471,   472,   321,
     473,   477,   480,   488,   484,   508,   321,   321,   509,   321,
     510,   481,   513,   515,   491,   321,   321,   321,   517,   495,
     496,  -970,   502,   499,   505,  -970,   506,   507,   516,    56,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,   518,   519,
      27,  -970,  -970,  -970,   503,   521,   524,  -970,   525,  -970,
      17,  -970,  -970,  -970,  -970,  -970,  -970,   335,  -970,  -970,
    -970,   511,   528,   529,   125,  -970,  -970,  -970,   532,   531,
     533,  -970,   534,   535,   536,   539,   540,   541,   543,   138,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,   546,   551,   552,   555,     5,  -970,  -970,  -970,  -970,
     572,   583,   321,   512,   584,   564,   587,   596,   573,  -970,
    -970,   520,   585,   606,   586,   588,   589,   591,   593,   594,
     599,   600,   602,   604,  -970,   605,   597,  -970,   162,  -970,
    -970,  -970,  -970,   609,   613,  -970,   581,   614,   615,   619,
     622,   623,   123,  -970,  -970,  -970,  -970,  -970,   617,   616,
    -970,   626,   625,  -970,   627,    42,  -970,  -970,  -970,  -970,
     628,   630,   631,  -970,   632,   514,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,  -970,  -970,   651,   652,   321,   650,   654,
     321,   655,   321,   657,   658,   659,   660,   321,   661,   661,
     656,  -970,  -970,   663,   -62,   664,   687,   666,   667,   665,
     668,   670,   671,   673,   674,   321,   675,   669,  -970,   676,
     677,   678,  -970,   679,  -970,   682,   683,   684,  -970,   685,
     686,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   734,  -970,  -970,
     737,   760,   680,   739,   741,   742,   738,  -970,   743,   744,
     745,  -970,  -970,   746,   748,   681,   749,   747,  -970,   -10,
    -970,   751,   752,   753,  -970,  -970,   754,   767,   755,   756,
     757,   758,   761,   775,   762,   763,   764,  -970,  -970,   768,
     769,   770,   771,  -970,   772,   773,   774,   776,   777,   778,
     779,   780,  -970,   781,   782,   783,   784,   785,   786,   787,
     788,   789,   790,   791,   792,  -970,  -970,   795,   793,   794,
    -970,   796,  -970,   185,  -970,   799,   800,   801,   802,   803,
    -970,   804,  -970,  -970,   807,   805,   808,   809,  -970,  -970,
    -970,  -970,  -970,   321,   321,   321,   321,   321,   321,   321,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,   810,
     811,   812,   -38,   813,   814,   815,   816,   817,   818,   819,
     820,   821,   187,   822,   823,  -970,   824,   825,   826,   827,
     828,   829,   830,    16,   831,   832,   833,   834,   835,   836,
     837,  -970,   838,   839,  -970,  -970,   840,   841,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,   842,   843,
     397,   844,   845,   846,  -970,   847,   848,  -970,   849,   850,
     269,   865,   500,  -970,  -970,  -970,   852,   853,  -970,   854,
     855,   465,   856,   857,   858,   859,   860,   861,   862,  -970,
     863,   864,   866,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,   867,   504,  -970,  -970,   868,   806,
     869,  -970,    85,  -970,  -970,  -970,  -970,   870,   872,   873,
     874,  -970,  -970,   875,   578,   876,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -212,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
     661,   661,   661,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -200,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -190,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -187,  -970,   759,   749,   877,  -970,
    -970,  -970,  -970,  -970,  -970,   766,  -970,   798,   878,  -970,
     879,  -970,   880,   881,  -970,  -970,   882,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -184,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -181,  -970,  -970,   871,  -188,   884,   887,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -179,  -970,  -970,  -970,   -38,  -970,
    -970,  -970,  -970,    16,  -970,   397,  -970,   269,  -970,  -970,
    -970,   851,   590,   941,   888,   750,   954,   955,  -970,   465,
    -970,   504,   889,   890,   891,   384,  -970,  -970,   578,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,   892,  -970,  -970
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
       0,    83,    84,    86,    85,   551,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   532,   548,   549,   550,   547,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   533,
     534,   544,   545,   546,     0,     0,     0,   417,     0,     0,
     415,   416,     0,   480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   430,   431,   432,   470,   438,   471,
     465,   466,   467,   468,   442,   433,   434,   435,   436,   437,
     452,   439,   440,   441,   443,   444,   469,   446,   447,   454,
     455,   448,   449,   450,   445,   451,   462,   463,   464,   460,
     461,   453,   458,   459,   456,   457,   472,   473,   474,   475,
     476,   477,   478,   479,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   581,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   572,   573,   574,   575,   576,   577,   578,
     580,   579,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    67,    65,    56,
      66,    58,    59,    60,    61,    62,    63,    64,    57,     0,
       0,     0,     0,   115,   116,   117,     0,     0,   308,     0,
       0,   306,   307,     0,    87,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   531,
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
       0,   429,     0,     0,     0,   279,     0,     0,     0,     0,
     267,   268,   269,   270,   273,   271,   272,   401,     0,     0,
       0,   398,   399,   400,     0,     0,     0,   240,     0,   252,
       0,   250,   251,   253,   254,    52,    51,    48,    50,    46,
      45,     0,     0,     0,     0,    94,    95,    96,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
     144,   145,   146,   147,   148,   151,   152,   153,   150,   149,
     154,     0,     0,     0,     0,     0,   296,   297,   298,   299,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   571,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,     0,   342,     0,   337,
     338,   339,   118,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   106,   105,   107,     0,     0,
     305,     0,     0,   320,     0,     0,   313,   314,   315,   316,
       0,     0,     0,    81,     0,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   530,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,   374,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   358,     0,
       0,     0,   406,     0,   413,     0,     0,     0,   421,     0,
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
       0,     0,   570,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,   340,     0,     0,     0,
     336,     0,   113,     0,   108,     0,     0,     0,     0,     0,
     102,     0,   304,   317,     0,     0,     0,     0,   312,    90,
      89,    88,   568,    29,    29,    29,    29,    29,    29,    29,
      31,    30,   569,   555,   554,   552,   553,   556,   557,   558,
     559,   560,   561,   562,   565,   566,   563,   564,   567,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,     0,     0,   199,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   357,     0,     0,   405,   418,     0,     0,   420,   492,
     497,   481,   482,   505,   522,   523,   524,   525,   526,   527,
     485,   520,   521,   514,   513,   486,   487,   491,   528,   500,
     490,   488,   489,   495,   496,   483,   494,   493,   511,   518,
     519,   509,   517,   506,   504,   507,   512,   529,   508,   510,
     502,   503,   515,   516,   499,   498,   501,   484,     0,     0,
       0,     0,     0,     0,   265,     0,     0,   396,     0,     0,
       0,   260,   256,   259,   239,    49,     0,     0,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,     0,     0,   294,   585,   582,   583,   584,   589,   588,
     586,   587,    76,    73,    80,    72,    77,    78,    79,    71,
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
    -970,  -970,  -970,   -19,  -309,  -969,  -638,  -970,  -970,  -970,
    -970,   156,  -970,  -970,   883,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,   901,
    -970,  -970,  -970,  -970,  -970,  -970,   402,  -970,  -970,  -970,
    -970,  -970,   439,  -970,  -970,  -970,  -970,  -970,  -970,   885,
    -970,  -970,  -970,  -970,    -3,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,   580,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -205,  -970,  -970,  -970,
     797,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,   -54,  -970,
    -970,  -970,  -970,  -970,   -70,  -970,   629,  -970,  -970,  -970,
      25,  -970,  -970,  -970,  -970,  -970,   653,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,   -60,  -970,  -970,  -970,  -970,   582,
    -970,  -970,  -970,  -970,  -970,   886,  -970,  -970,  -970,  -970,
     523,  -970,  -970,  -970,  -970,  -970,   -85,  -970,  -970,  -970,
     548,  -970,  -970,  -970,  -970,   -71,  -970,  -970,  -970,   893,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,   -52,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
     662,  -970,  -970,  -970,  -970,  -970,   735,  -970,  -970,  -970,
    -970,   994,  -970,  -970,  -970,  -970,   894,  -970,  -970,  -970,
    -970,   942,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  1020,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970,  -970,   895,  -970,  -970,  -970,  -970,  -970,
    -970,  -970,  -970
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   820,   821,  1033,  1034,    28,    29,   238,
     497,   498,    30,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,    31,    80,    81,
      82,    83,    84,    32,    66,   504,   505,   506,   507,    33,
      73,   582,   583,   584,   585,   586,   587,    34,   292,   293,
     294,   295,   296,   992,   993,   994,   995,   996,  1146,  1223,
      35,    67,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   748,  1118,  1119,    36,    55,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   628,  1019,  1020,    37,
      63,   489,   735,  1084,  1085,   490,   491,   492,  1088,   942,
     943,   493,   494,    38,    61,   469,   470,   471,   472,   473,
     474,   475,   722,  1070,  1071,   476,    39,    68,   535,   536,
     537,   538,   539,    40,   300,   301,   302,    41,    75,   595,
     596,   597,   598,   599,   805,  1164,  1165,    42,    71,   568,
     569,   570,   571,   788,  1141,  1142,    43,    56,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     649,  1046,  1047,   390,   391,   392,   393,    44,    62,   480,
     481,   482,   483,    45,    57,   397,   398,   399,   400,    46,
     129,   130,   131,    47,    59,   407,   408,   409,   410,    48,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    49,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    50,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     853,   854,   606,  1193,   290,   298,   531,  1167,   612,   613,
     614,  1168,   616,   617,   394,   127,   298,    53,   484,  1172,
     495,   127,    54,  1173,  1044,   290,  1017,    76,   477,  1174,
     852,    58,  1176,  1175,   404,  1188,  1177,   501,  1190,  1189,
    1197,    60,  1191,   591,  1198,   394,    64,   133,    65,   477,
      51,    52,   134,   135,   243,   136,   137,   462,   532,    69,
     138,  1169,  1170,  1171,    70,    77,   330,   139,   140,   141,
     142,   143,   144,    78,    72,   463,    74,   145,   146,   147,
     404,   124,   331,   332,   485,   125,   988,   148,   149,   395,
     128,   150,   151,   486,   333,   487,   128,   244,   533,   126,
     152,  1018,   132,   670,   234,   672,   673,   464,   245,   246,
     247,   857,   858,   248,   249,   682,   153,   154,   250,   251,
     395,   688,   299,   690,   577,   235,   501,   236,   155,   502,
     697,   156,   157,   299,   465,   496,   237,   704,   705,   508,
     707,   158,   159,   334,    79,   534,   713,   714,   715,   160,
     161,   405,   162,   396,   163,   488,   239,   509,   164,   165,
     592,   240,   462,   565,   335,   336,   241,   478,   242,   289,
     166,   297,   337,   406,  -120,   167,   338,   168,   169,   170,
     463,    85,   171,   339,   396,   591,   988,   172,   478,   510,
     466,   340,   341,   342,   565,  -120,   262,   405,  1030,  1031,
    1032,   303,   343,   989,  1045,   173,   174,   503,   304,   175,
     176,   291,   464,   305,    86,    87,   511,   467,   502,   406,
     363,   344,   364,    88,   365,   762,   499,   306,    89,    90,
      91,   263,   291,   766,   264,   589,   479,   737,   366,   465,
     402,   578,   177,   178,   574,   345,   308,   730,   593,   179,
     180,   594,    92,    93,    94,    95,   512,   479,   181,   307,
     182,   577,   807,   265,   661,   468,   460,    96,    97,    98,
     367,   990,   513,   548,   266,   508,   726,    99,   100,   101,
     566,   102,   103,   310,   311,   640,   368,   312,   369,  1079,
     579,   991,   313,   509,   314,   466,   503,   370,   484,   667,
     267,   580,   592,   989,   268,  1147,  1080,   315,   316,   371,
     581,   566,   269,   270,   317,   318,   271,   272,   841,   319,
     320,   844,   467,   846,   321,   510,   322,   514,   851,  1081,
     323,    76,   324,   325,   326,   327,   401,   372,   515,   411,
     516,   412,   413,   799,   576,   743,   869,   517,   414,   415,
     416,   518,   511,   417,   418,   419,   420,   373,   756,   500,
     421,   531,   422,   423,   485,   424,   425,   426,   567,    77,
     468,   990,   427,   486,   374,   487,   428,    78,   578,   429,
     430,   431,   789,   550,   363,   375,   364,   432,   365,   433,
     593,   991,   512,   594,   273,   434,   274,   435,   436,   567,
     328,   133,   366,   437,   438,   852,   134,   135,   513,   136,
     137,   439,  1061,   532,   138,   563,   604,   376,   440,   377,
     441,   139,   140,   141,   142,   143,   144,   579,   442,   443,
     444,   145,   146,   147,   367,   488,   445,   446,   580,   657,
     572,   148,   149,   447,   448,   150,   151,   581,    79,  1062,
     368,  1082,   369,   533,   152,   449,   450,  1083,   451,   452,
     453,   370,   454,   514,   455,  1215,   456,  1216,   457,  1093,
     153,   154,   458,   371,   515,   459,   516,   540,   541,   542,
     543,  1063,   155,   517,   544,   156,   157,   518,   545,   546,
     603,   547,  1094,  1095,   551,   158,   159,   552,   553,   554,
     534,   372,   262,   160,   161,  1096,   162,  1194,   163,   555,
     556,   557,   164,   165,  1217,   558,  1064,  1065,   600,   559,
     560,   373,  1066,   561,   166,   562,   573,   588,   601,   167,
    1218,   168,   169,   170,   602,   607,   171,   263,   374,   605,
     264,   172,   608,   609,  1067,  1097,  1098,   610,  1099,   375,
     611,   615,   618,  1219,  1220,   619,   620,   621,   739,   173,
     174,   622,   625,   175,   176,   623,   626,   669,   624,   265,
     674,   627,   629,   642,   630,  1100,   631,   632,   633,  1101,
     266,   376,   634,   377,   635,   636,   637,  1131,  1102,   638,
     639,  1068,   643,  1221,   644,   645,   177,   178,   646,  1222,
     647,     2,     3,   179,   180,     4,   267,  1103,   330,  1104,
     268,  1105,   181,  1069,   182,   648,   650,     5,   269,   270,
       6,   663,   271,   272,   331,   332,   651,  1106,   652,     7,
     653,   654,   655,   656,   659,  1107,   333,  1108,   660,     8,
    1109,   664,  1110,   671,   665,   666,  1111,   675,   676,  1112,
    1132,   677,   678,   679,     9,  1113,   680,  1114,  1115,    10,
      11,  1154,   813,   814,   815,   816,   817,   818,   819,  1133,
     681,   683,  1116,   684,  1134,   685,   686,   687,    12,  1135,
    1117,   689,    13,   701,   691,   334,   692,   693,   694,   695,
     696,   698,    14,    15,  1136,   699,  1137,  1138,   700,   709,
     273,   702,   274,   703,   706,   708,   335,   336,   710,   712,
     711,  1139,   716,   717,   337,   718,    16,    17,   338,  1140,
     720,   719,   732,  1087,  1155,   339,   721,   723,   724,   767,
     740,    18,   605,   340,   341,   342,  1204,   725,   773,   728,
     729,    85,   733,  1156,   343,   734,   736,    19,  1157,   741,
     742,   745,   746,  1158,   747,   749,   750,   751,    20,    21,
     752,   753,   754,   344,   755,   758,   243,   764,  1159,    22,
    1160,  1161,   759,   760,    86,    87,   761,    23,   765,   768,
      24,   769,   770,    88,    25,  1162,    26,   345,    89,    90,
      91,   771,   772,  1163,  1007,  1008,  1009,  1010,  1011,  1012,
    1013,   775,   774,   776,   791,   793,   777,   778,   779,   244,
     780,   781,    92,    93,    94,    95,   782,   783,   787,   784,
     245,   246,   247,   785,   786,   248,   249,    96,    97,    98,
     250,   251,   792,   794,   801,   802,   795,    99,   100,   101,
     796,   102,   103,   797,   798,   803,   804,   809,   806,   810,
     811,   812,   822,   823,   824,   825,   826,   827,   828,   829,
     830,   831,   832,   833,   834,   835,   836,   837,   838,   839,
     840,   842,   843,   845,   847,   855,   848,   849,   850,   852,
     856,   859,   860,   861,   862,   864,   863,   865,   871,   866,
     867,   868,   870,   872,   873,   945,  1207,   874,   875,   876,
     877,   930,   940,   878,   879,   880,   744,   881,   882,   883,
     884,   885,   886,   887,   888,   889,   890,   891,   892,   893,
     894,   895,   896,   897,   898,   899,   900,   901,   902,   903,
     904,   905,   906,   907,   908,   909,   910,   911,   912,   913,
     914,   915,   916,   917,   918,   919,   920,   921,   922,   923,
     924,   925,   926,   927,   928,   929,   931,   934,   932,   933,
     935,   936,   950,   938,   937,   939,   944,   941,   946,   947,
     956,   949,   948,   952,   953,   954,   951,  1178,   955,   957,
     958,   309,  1206,   959,  1210,   960,   961,   962,  1181,  1148,
     963,   964,   965,   966,  1203,   967,   968,   969,   970,   971,
     972,   973,   974,   975,   976,   977,   978,   979,   980,   981,
     982,   983,   984,   986,   985,   987,   997,   998,   999,  1000,
    1182,   800,  1001,  1002,  1003,  1005,  1004,  1144,  1006,  1014,
    1015,  1016,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,
    1029,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,
    1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1086,  1089,  1090,  1091,  1092,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1205,  1129,  1130,  1143,  1192,  1149,
    1145,  1150,  1151,  1152,  1153,  1166,  1180,  1208,  1209,   757,
    1183,  1184,  1185,  1186,  1187,  1195,  1196,  1202,  1212,  1213,
    1214,  1225,  1179,  1224,  1199,  1201,   790,   763,   808,   738,
    1211,  1200,   727,   403,   329,   461,     0,     0,     0,     0,
       0,     0,   662,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   731,   641,     0,     0,     0,   549,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   564,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   575,     0,     0,
       0,     0,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   658,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   668
};

static const yytype_int16 yycheck[] =
{
     638,   639,   311,   191,     1,     1,     1,   219,   317,   318,
     319,   223,   321,   322,     1,     1,     1,   224,     1,   219,
      30,     1,   224,   223,     8,     1,    64,     1,     1,   219,
     218,   224,   219,   223,     1,   219,   223,     1,   219,   223,
     219,   224,   223,     1,   223,     1,   217,     1,   221,     1,
     219,   220,     6,     7,     1,     9,    10,     1,    53,   224,
      14,  1030,  1031,  1032,   224,    39,     1,    21,    22,    23,
      24,    25,    26,    47,   224,    19,   224,    31,    32,    33,
       1,   224,    17,    18,    67,   224,     1,    41,    42,    76,
      76,    45,    46,    76,    29,    78,    76,    44,    93,   224,
      54,   139,   224,   412,   224,   414,   415,    51,    55,    56,
      57,   173,   174,    60,    61,   424,    70,    71,    65,    66,
      76,   430,   118,   432,     1,   224,     1,   224,    82,    93,
     439,    85,    86,   118,    78,   145,   222,   446,   447,     1,
     449,    95,    96,    78,   118,   140,   455,   456,   457,   103,
     104,   118,   106,   140,   108,   138,   217,    19,   112,   113,
     118,   224,     1,     1,    99,   100,   224,   140,   224,   224,
     124,   224,   107,   140,   171,   129,   111,   131,   132,   133,
      19,     1,   136,   118,   140,     1,     1,   141,   140,    51,
     134,   126,   127,   128,     1,   171,     1,   118,    11,    12,
      13,   224,   137,   118,   188,   159,   160,   171,   219,   163,
     164,   208,    51,   221,    34,    35,    78,   161,    93,   140,
       1,   156,     3,    43,     5,   220,   219,   221,    48,    49,
      50,    36,   208,   542,    39,   220,   209,   220,    19,    78,
     220,   118,   196,   197,   220,   180,   220,   220,   206,   203,
     204,   209,    72,    73,    74,    75,   118,   209,   212,   221,
     214,     1,   220,    68,   220,   209,   220,    87,    88,    89,
      51,   186,   134,   220,    79,     1,   220,    97,    98,    99,
     118,   101,   102,   221,   221,   220,    67,   221,    69,    20,
     167,   206,   221,    19,   221,   134,   171,    78,     1,   220,
     105,   178,   118,   118,   109,   220,    37,   221,   221,    90,
     187,   118,   117,   118,   221,   221,   121,   122,   627,   221,
     221,   630,   161,   632,   221,    51,   221,   189,   637,    60,
     221,     1,   221,   221,   221,   221,   221,   118,   200,   221,
     202,   221,   221,   220,   171,   220,   655,   209,   221,   221,
     221,   213,    78,   221,   221,   221,   221,   138,   220,   219,
     221,     1,   221,   221,    67,   221,   221,   221,   206,    39,
     209,   186,   221,    76,   155,    78,   221,    47,   118,   221,
     221,   221,   220,   219,     1,   166,     3,   221,     5,   221,
     206,   206,   118,   209,   199,   221,   201,   221,   221,   206,
     220,     1,    19,   221,   221,   218,     6,     7,   134,     9,
      10,   221,    15,    53,    14,   220,   218,   198,   221,   200,
     221,    21,    22,    23,    24,    25,    26,   167,   221,   221,
     221,    31,    32,    33,    51,   138,   221,   221,   178,   220,
     219,    41,    42,   221,   221,    45,    46,   187,   118,    52,
      67,   182,    69,    93,    54,   221,   221,   188,   221,   221,
     221,    78,   221,   189,   221,    81,   221,    83,   221,     4,
      70,    71,   221,    90,   200,   221,   202,   221,   221,   221,
     221,    84,    82,   209,   221,    85,    86,   213,   221,   221,
     219,   221,    27,    28,   221,    95,    96,   221,   221,   221,
     140,   118,     1,   103,   104,    40,   106,  1145,   108,   221,
     221,   221,   112,   113,   130,   221,   119,   120,   217,   221,
     221,   138,   125,   221,   124,   221,   221,   221,   217,   129,
     146,   131,   132,   133,   217,   195,   136,    36,   155,   218,
      39,   141,   195,   195,   147,    80,    81,   195,    83,   166,
     218,   218,   218,   169,   170,   218,   218,   218,   223,   159,
     160,   218,   221,   163,   164,   219,   221,   195,   219,    68,
     195,   221,   221,   219,   221,   110,   221,   221,   221,   114,
      79,   198,   221,   200,   221,   221,   221,    83,   123,   221,
     221,   194,   221,   209,   221,   221,   196,   197,   221,   215,
     221,     0,     1,   203,   204,     4,   105,   142,     1,   144,
     109,   146,   212,   216,   214,   221,   221,    16,   117,   118,
      19,   217,   121,   122,    17,    18,   221,   162,   221,    28,
     221,   221,   221,   221,   221,   170,    29,   172,   221,    38,
     175,   219,   177,   218,   221,   221,   181,   218,   218,   184,
     146,   218,   217,   217,    53,   190,   195,   192,   193,    58,
      59,    83,   148,   149,   150,   151,   152,   153,   154,   165,
     218,   195,   207,   195,   170,   218,   218,   195,    77,   175,
     215,   195,    81,   195,   218,    78,   218,   218,   218,   218,
     218,   218,    91,    92,   190,   218,   192,   193,   218,   218,
     199,   217,   201,   195,   195,   195,    99,   100,   195,   218,
     195,   207,   195,   218,   107,   219,   115,   116,   111,   215,
     221,   219,   219,   223,   146,   118,   221,   221,   221,   217,
     219,   130,   218,   126,   127,   128,   146,   221,   218,   221,
     221,     1,   221,   165,   137,   221,   221,   146,   170,   221,
     221,   219,   221,   175,   221,   221,   221,   221,   157,   158,
     221,   221,   221,   156,   221,   219,     1,   195,   190,   168,
     192,   193,   221,   221,    34,    35,   221,   176,   195,   195,
     179,   217,   195,    43,   183,   207,   185,   180,    48,    49,
      50,   195,   219,   215,   813,   814,   815,   816,   817,   818,
     819,   195,   217,   217,   195,   224,   218,   218,   217,    44,
     217,   217,    72,    73,    74,    75,   217,   217,   221,   217,
      55,    56,    57,   219,   219,    60,    61,    87,    88,    89,
      65,    66,   219,   219,   217,   219,   221,    97,    98,    99,
     221,   101,   102,   221,   221,   219,   221,   219,   221,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   218,
     218,   221,   218,   218,   217,   219,   218,   218,   218,   218,
     217,   217,   195,   217,   217,   217,   221,   217,   219,   218,
     217,   217,   217,   217,   217,   739,   146,   219,   219,   217,
     217,   221,   221,   219,   219,   219,   504,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   217,   195,   217,   219,   217,   217,
     217,   217,   195,   217,   219,   217,   219,   218,   217,   217,
     195,   217,   219,   217,   217,   217,   221,   218,   217,   217,
     217,    80,    94,   219,  1189,   217,   217,   217,   222,   992,
     219,   219,   219,   219,   143,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   217,   219,   221,   219,   217,   217,   217,   217,
     222,   582,   219,   219,   217,   217,   221,   221,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     205,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   143,   219,   219,   219,   217,   219,
     221,   219,   219,   219,   219,   219,   219,   143,   143,   519,
     222,   222,   222,   222,   222,   221,   219,  1177,   219,   219,
     219,   219,  1087,  1198,  1168,  1175,   568,   535,   595,   490,
    1191,  1173,   469,   129,   104,   183,    -1,    -1,    -1,    -1,
      -1,    -1,   397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,   346,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   292,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   300,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   407
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   226,     0,     1,     4,    16,    19,    28,    38,    53,
      58,    59,    77,    81,    91,    92,   115,   116,   130,   146,
     157,   158,   168,   176,   179,   183,   185,   227,   232,   233,
     237,   252,   258,   264,   272,   285,   302,   324,   338,   351,
     358,   362,   372,   381,   402,   408,   414,   418,   424,   476,
     497,   219,   220,   224,   224,   303,   382,   409,   224,   419,
     224,   339,   403,   325,   217,   221,   259,   286,   352,   224,
     224,   373,   224,   265,   224,   363,     1,    39,    47,   118,
     253,   254,   255,   256,   257,     1,    34,    35,    43,    48,
      49,    50,    72,    73,    74,    75,    87,    88,    89,    97,
      98,    99,   101,   102,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   224,   224,   224,     1,    76,   415,
     416,   417,   224,     1,     6,     7,     9,    10,    14,    21,
      22,    23,    24,    25,    26,    31,    32,    33,    41,    42,
      45,    46,    54,    70,    71,    82,    85,    86,    95,    96,
     103,   104,   106,   108,   112,   113,   124,   129,   131,   132,
     133,   136,   141,   159,   160,   163,   164,   196,   197,   203,
     204,   212,   214,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   224,   224,   224,   222,   234,   217,
     224,   224,   224,     1,    44,    55,    56,    57,    60,    61,
      65,    66,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,     1,    36,    39,    68,    79,   105,   109,   117,
     118,   121,   122,   199,   201,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   224,
       1,   208,   273,   274,   275,   276,   277,   224,     1,   118,
     359,   360,   361,   224,   219,   221,   221,   221,   220,   254,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   220,   478,
       1,    17,    18,    29,    78,    99,   100,   107,   111,   118,
     126,   127,   128,   137,   156,   180,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,     1,     3,     5,    19,    51,    67,    69,
      78,    90,   118,   138,   155,   166,   198,   200,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     398,   399,   400,   401,     1,    76,   140,   410,   411,   412,
     413,   221,   220,   416,     1,   118,   140,   420,   421,   422,
     423,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     220,   426,     1,    19,    51,    78,   134,   161,   209,   340,
     341,   342,   343,   344,   345,   346,   350,     1,   140,   209,
     404,   405,   406,   407,     1,    67,    76,    78,   138,   326,
     330,   331,   332,   336,   337,    30,   145,   235,   236,   219,
     219,     1,    93,   171,   260,   261,   262,   263,     1,    19,
      51,    78,   118,   134,   189,   200,   202,   209,   213,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,     1,    53,    93,   140,   353,   354,   355,   356,   357,
     221,   221,   221,   221,   221,   221,   221,   221,   220,   499,
     219,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   220,   239,     1,   118,   206,   374,   375,
     376,   377,   219,   221,   220,   274,   171,     1,   118,   167,
     178,   187,   266,   267,   268,   269,   270,   271,   221,   220,
     360,     1,   118,   206,   209,   364,   365,   366,   367,   368,
     217,   217,   217,   219,   218,   218,   229,   195,   195,   195,
     195,   218,   229,   229,   229,   218,   229,   229,   218,   218,
     218,   218,   218,   219,   219,   221,   221,   221,   321,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     220,   305,   219,   221,   221,   221,   221,   221,   221,   395,
     221,   221,   221,   221,   221,   221,   221,   220,   384,   221,
     221,   220,   411,   217,   219,   221,   221,   220,   421,   195,
     229,   218,   229,   229,   195,   218,   218,   218,   217,   217,
     195,   218,   229,   195,   195,   218,   218,   195,   229,   195,
     229,   218,   218,   218,   218,   218,   218,   229,   218,   218,
     218,   195,   217,   195,   229,   229,   195,   229,   195,   218,
     195,   195,   218,   229,   229,   229,   195,   218,   219,   219,
     221,   221,   347,   221,   221,   221,   220,   341,   221,   221,
     220,   405,   219,   221,   221,   327,   221,   220,   331,   223,
     219,   221,   221,   220,   261,   219,   221,   221,   299,   221,
     221,   221,   221,   221,   221,   221,   220,   288,   219,   221,
     221,   221,   220,   354,   195,   195,   229,   217,   195,   217,
     195,   195,   219,   218,   217,   195,   217,   218,   218,   217,
     217,   217,   217,   217,   217,   219,   219,   221,   378,   220,
     375,   195,   219,   224,   219,   221,   221,   221,   221,   220,
     267,   217,   219,   219,   221,   369,   221,   220,   365,   219,
     219,   219,   219,   148,   149,   150,   151,   152,   153,   154,
     228,   229,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   218,
     218,   229,   221,   218,   229,   218,   229,   217,   218,   218,
     218,   229,   218,   231,   231,   219,   217,   173,   174,   217,
     195,   217,   217,   221,   217,   217,   218,   217,   217,   229,
     217,   219,   217,   217,   219,   219,   217,   217,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   217,   195,
     221,   217,   217,   217,   219,   217,   217,   219,   217,   217,
     221,   218,   334,   335,   219,   236,   217,   217,   219,   217,
     195,   221,   217,   217,   217,   217,   195,   217,   217,   219,
     217,   217,   217,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   217,   221,   219,   219,     1,   118,
     186,   206,   278,   279,   280,   281,   282,   217,   217,   217,
     217,   219,   219,   217,   221,   217,   219,   228,   228,   228,
     228,   228,   228,   228,   219,   219,   219,    64,   139,   322,
     323,   219,   219,   219,   219,   219,   219,   219,   219,   219,
      11,    12,    13,   230,   231,   219,   219,   219,   219,   219,
     219,   219,   219,   219,     8,   188,   396,   397,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,    15,    52,    84,   119,   120,   125,   147,   194,   216,
     348,   349,   219,   219,   219,   219,   219,   219,   219,    20,
      37,    60,   182,   188,   328,   329,   205,   223,   333,   219,
     219,   219,   219,     4,    27,    28,    40,    80,    81,    83,
     110,   114,   123,   142,   144,   146,   162,   170,   172,   175,
     177,   181,   184,   190,   192,   193,   207,   215,   300,   301,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,    83,   146,   165,   170,   175,   190,   192,   193,   207,
     215,   379,   380,   219,   221,   221,   283,   220,   279,   219,
     219,   219,   219,   219,    83,   146,   165,   170,   175,   190,
     192,   193,   207,   215,   370,   371,   219,   219,   223,   230,
     230,   230,   219,   223,   219,   223,   219,   223,   218,   335,
     219,   222,   222,   222,   222,   222,   222,   222,   219,   223,
     219,   223,   217,   191,   231,   221,   219,   219,   223,   323,
     397,   349,   329,   143,   146,   143,    94,   146,   143,   143,
     301,   380,   219,   219,   219,    81,    83,   130,   146,   169,
     170,   209,   215,   284,   371,   219
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   225,   226,   226,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   228,
     228,   229,   229,   229,   229,   229,   229,   229,   229,   230,
     230,   231,   231,   231,   231,   232,   233,   234,   234,   235,
     235,   236,   236,   237,   238,   238,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   253,   254,   254,   254,   254,   255,   256,
     257,   259,   258,   260,   260,   261,   261,   261,   262,   263,
     265,   264,   266,   266,   267,   267,   267,   267,   267,   268,
     269,   270,   271,   272,   273,   273,   274,   274,   274,   275,
     277,   276,   278,   278,   279,   279,   279,   279,   280,   281,
     281,   283,   282,   284,   284,   284,   284,   284,   284,   284,
     284,   286,   285,   287,   287,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   299,   298,   300,   300,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   303,   302,
     304,   304,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   321,   320,   322,   322,   323,   323,   325,   324,
     327,   326,   328,   328,   329,   329,   329,   329,   329,   330,
     330,   331,   331,   331,   331,   331,   333,   332,   334,   334,
     335,   335,   336,   337,   339,   338,   340,   340,   341,   341,
     341,   341,   341,   341,   341,   342,   343,   344,   345,   347,
     346,   348,   348,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   350,   352,   351,   353,   353,   354,   354,   354,
     354,   355,   356,   357,   358,   359,   359,   360,   360,   361,
     363,   362,   364,   364,   365,   365,   365,   365,   366,   367,
     369,   368,   370,   370,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   373,   372,   374,   374,   375,   375,
     375,   376,   378,   377,   379,   379,   380,   380,   380,   380,
     380,   380,   380,   380,   380,   380,   382,   381,   383,   383,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   393,   395,   394,   396,   396,   397,
     397,   398,   399,   400,   401,   403,   402,   404,   404,   405,
     405,   405,   406,   407,   409,   408,   410,   410,   411,   411,
     411,   412,   413,   414,   415,   415,   416,   416,   417,   419,
     418,   420,   420,   421,   421,   421,   422,   423,   424,   425,
     425,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   477,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   498,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   500,   501,   502,   503,   504,   505,   506,   507
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
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
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
#line 385 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3444 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 386 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3450 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 387 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3456 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 388 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3462 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 389 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3468 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 390 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3474 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 391 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3480 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 392 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3486 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 393 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3492 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 396 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3498 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 397 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3504 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 398 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3510 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3516 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3522 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 408 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3531 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 418 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3540 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 424 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3548 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 431 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3557 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 435 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3566 "conf_parser.c"
    break;

  case 69: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 463 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3578 "conf_parser.c"
    break;

  case 70: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 472 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3590 "conf_parser.c"
    break;

  case 71: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 481 "conf_parser.y"
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
#line 3608 "conf_parser.c"
    break;

  case 72: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 496 "conf_parser.y"
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
#line 3626 "conf_parser.c"
    break;

  case 73: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 511 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3639 "conf_parser.c"
    break;

  case 74: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 521 "conf_parser.y"
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
#line 3656 "conf_parser.c"
    break;

  case 75: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 535 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3668 "conf_parser.c"
    break;

  case 76: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 544 "conf_parser.y"
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
#line 3694 "conf_parser.c"
    break;

  case 77: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 567 "conf_parser.y"
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
#line 3720 "conf_parser.c"
    break;

  case 78: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 590 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigServerInfo.max_topic_length = TOPICLEN;
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3731 "conf_parser.c"
    break;

  case 79: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 598 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3743 "conf_parser.c"
    break;

  case 80: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 607 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3752 "conf_parser.c"
    break;

  case 88: /* admin_name: NAME '=' QSTRING ';'  */
#line 625 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3764 "conf_parser.c"
    break;

  case 89: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 634 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3776 "conf_parser.c"
    break;

  case 90: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 643 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3788 "conf_parser.c"
    break;

  case 91: /* $@1: %empty  */
#line 656 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3797 "conf_parser.c"
    break;

  case 92: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 660 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3814 "conf_parser.c"
    break;

  case 98: /* motd_mask: MASK '=' QSTRING ';'  */
#line 677 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3823 "conf_parser.c"
    break;

  case 99: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 683 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3832 "conf_parser.c"
    break;

  case 100: /* $@2: %empty  */
#line 693 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3841 "conf_parser.c"
    break;

  case 101: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 697 "conf_parser.y"
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
#line 3859 "conf_parser.c"
    break;

  case 109: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 715 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3868 "conf_parser.c"
    break;

  case 110: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 721 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3877 "conf_parser.c"
    break;

  case 111: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 727 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3886 "conf_parser.c"
    break;

  case 112: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 733 "conf_parser.y"
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
#line 3908 "conf_parser.c"
    break;

  case 119: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 762 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 3920 "conf_parser.c"
    break;

  case 120: /* $@3: %empty  */
#line 771 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3929 "conf_parser.c"
    break;

  case 121: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 775 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3942 "conf_parser.c"
    break;

  case 128: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 791 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3953 "conf_parser.c"
    break;

  case 129: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 799 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3961 "conf_parser.c"
    break;

  case 130: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 802 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3969 "conf_parser.c"
    break;

  case 131: /* $@4: %empty  */
#line 807 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3978 "conf_parser.c"
    break;

  case 133: /* logging_file_type_item: USER  */
#line 813 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3987 "conf_parser.c"
    break;

  case 134: /* logging_file_type_item: OPERATOR  */
#line 817 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3996 "conf_parser.c"
    break;

  case 135: /* logging_file_type_item: XLINE  */
#line 821 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4005 "conf_parser.c"
    break;

  case 136: /* logging_file_type_item: RESV  */
#line 825 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4014 "conf_parser.c"
    break;

  case 137: /* logging_file_type_item: T_DLINE  */
#line 829 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4023 "conf_parser.c"
    break;

  case 138: /* logging_file_type_item: KLINE  */
#line 833 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4032 "conf_parser.c"
    break;

  case 139: /* logging_file_type_item: KILL  */
#line 837 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4041 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: T_DEBUG  */
#line 841 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4050 "conf_parser.c"
    break;

  case 141: /* $@5: %empty  */
#line 851 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4062 "conf_parser.c"
    break;

  case 142: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 858 "conf_parser.y"
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
#line 4120 "conf_parser.c"
    break;

  case 156: /* oper_name: NAME '=' QSTRING ';'  */
#line 926 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4129 "conf_parser.c"
    break;

  case 157: /* oper_user: USER '=' QSTRING ';'  */
#line 932 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4138 "conf_parser.c"
    break;

  case 158: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 938 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4147 "conf_parser.c"
    break;

  case 159: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 944 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4156 "conf_parser.c"
    break;

  case 160: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 950 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4170 "conf_parser.c"
    break;

  case 161: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 961 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4179 "conf_parser.c"
    break;

  case 162: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 967 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4193 "conf_parser.c"
    break;

  case 163: /* oper_class: CLASS '=' QSTRING ';'  */
#line 978 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4202 "conf_parser.c"
    break;

  case 164: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 984 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4211 "conf_parser.c"
    break;

  case 165: /* $@6: %empty  */
#line 990 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4220 "conf_parser.c"
    break;

  case 169: /* oper_flags_item: KILL ':' REMOTE  */
#line 997 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4229 "conf_parser.c"
    break;

  case 170: /* oper_flags_item: KILL  */
#line 1001 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4238 "conf_parser.c"
    break;

  case 171: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1005 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4247 "conf_parser.c"
    break;

  case 172: /* oper_flags_item: CONNECT  */
#line 1009 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4256 "conf_parser.c"
    break;

  case 173: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1013 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4265 "conf_parser.c"
    break;

  case 174: /* oper_flags_item: SQUIT  */
#line 1017 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4274 "conf_parser.c"
    break;

  case 175: /* oper_flags_item: KLINE  */
#line 1021 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4283 "conf_parser.c"
    break;

  case 176: /* oper_flags_item: UNKLINE  */
#line 1025 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4292 "conf_parser.c"
    break;

  case 177: /* oper_flags_item: T_DLINE  */
#line 1029 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4301 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: T_UNDLINE  */
#line 1033 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4310 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: XLINE  */
#line 1037 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4319 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: T_UNXLINE  */
#line 1041 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4328 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: DIE  */
#line 1045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4337 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: T_RESTART  */
#line 1049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4346 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1053 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4355 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: REHASH  */
#line 1057 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4364 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: ADMIN  */
#line 1061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4373 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_GLOBOPS  */
#line 1065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4382 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_LOCOPS  */
#line 1069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4391 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: REMOTEBAN  */
#line 1073 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4400 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_SET  */
#line 1077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4409 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: MODULE  */
#line 1081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4418 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_OPME  */
#line 1085 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4427 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: NICK ':' RESV  */
#line 1089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4436 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: JOIN ':' RESV  */
#line 1093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4445 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: RESV  */
#line 1097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4454 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_UNRESV  */
#line 1101 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4463 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: CLOSE  */
#line 1105 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4472 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4481 "conf_parser.c"
    break;

  case 198: /* $@7: %empty  */
#line 1119 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.con_freq.value  = CLASS_DEFAULT_CONNECT_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4497 "conf_parser.c"
    break;

  case 199: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1130 "conf_parser.y"
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
#line 4545 "conf_parser.c"
    break;

  case 218: /* class_name: NAME '=' QSTRING ';'  */
#line 1193 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4554 "conf_parser.c"
    break;

  case 219: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1199 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4563 "conf_parser.c"
    break;

  case 220: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1205 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4572 "conf_parser.c"
    break;

  case 221: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1211 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4581 "conf_parser.c"
    break;

  case 222: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1217 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4590 "conf_parser.c"
    break;

  case 223: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1223 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4599 "conf_parser.c"
    break;

  case 224: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1229 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4608 "conf_parser.c"
    break;

  case 225: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1235 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4617 "conf_parser.c"
    break;

  case 226: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1241 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4627 "conf_parser.c"
    break;

  case 227: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1248 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4636 "conf_parser.c"
    break;

  case 228: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1254 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4645 "conf_parser.c"
    break;

  case 229: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1260 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4654 "conf_parser.c"
    break;

  case 230: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1266 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4666 "conf_parser.c"
    break;

  case 231: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1275 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4678 "conf_parser.c"
    break;

  case 232: /* $@8: %empty  */
#line 1284 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4687 "conf_parser.c"
    break;

  case 236: /* class_flags_item: RANDOM_IDLE  */
#line 1291 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4696 "conf_parser.c"
    break;

  case 237: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1295 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4705 "conf_parser.c"
    break;

  case 238: /* $@9: %empty  */
#line 1305 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4714 "conf_parser.c"
    break;

  case 240: /* $@10: %empty  */
#line 1311 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4722 "conf_parser.c"
    break;

  case 244: /* listen_flags_item: T_TLS  */
#line 1317 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4731 "conf_parser.c"
    break;

  case 245: /* listen_flags_item: HIDDEN  */
#line 1321 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4740 "conf_parser.c"
    break;

  case 246: /* listen_flags_item: T_SERVER  */
#line 1325 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4749 "conf_parser.c"
    break;

  case 247: /* listen_flags_item: CLIENT  */
#line 1329 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4758 "conf_parser.c"
    break;

  case 248: /* listen_flags_item: DEFER  */
#line 1333 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4767 "conf_parser.c"
    break;

  case 256: /* $@11: %empty  */
#line 1341 "conf_parser.y"
                                 { reset_block_state(); }
#line 4773 "conf_parser.c"
    break;

  case 260: /* port_item: NUMBER  */
#line 1346 "conf_parser.y"
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
#line 4791 "conf_parser.c"
    break;

  case 261: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1359 "conf_parser.y"
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
#line 4811 "conf_parser.c"
    break;

  case 262: /* listen_address: IP '=' QSTRING ';'  */
#line 1376 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4820 "conf_parser.c"
    break;

  case 263: /* listen_host: HOST '=' QSTRING ';'  */
#line 1382 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4829 "conf_parser.c"
    break;

  case 264: /* $@12: %empty  */
#line 1392 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4838 "conf_parser.c"
    break;

  case 265: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1396 "conf_parser.y"
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
#line 4893 "conf_parser.c"
    break;

  case 275: /* auth_user: USER '=' QSTRING ';'  */
#line 1457 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4902 "conf_parser.c"
    break;

  case 276: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1463 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4911 "conf_parser.c"
    break;

  case 277: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1469 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4920 "conf_parser.c"
    break;

  case 278: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1475 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 4934 "conf_parser.c"
    break;

  case 279: /* $@13: %empty  */
#line 1486 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 4943 "conf_parser.c"
    break;

  case 283: /* auth_flags_item: EXCEED_LIMIT  */
#line 1494 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 4952 "conf_parser.c"
    break;

  case 284: /* auth_flags_item: KLINE_EXEMPT  */
#line 1498 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 4961 "conf_parser.c"
    break;

  case 285: /* auth_flags_item: XLINE_EXEMPT  */
#line 1502 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 4970 "conf_parser.c"
    break;

  case 286: /* auth_flags_item: NEED_IDENT  */
#line 1506 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 4979 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: CAN_FLOOD  */
#line 1510 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 4988 "conf_parser.c"
    break;

  case 288: /* auth_flags_item: NO_TILDE  */
#line 1514 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 4997 "conf_parser.c"
    break;

  case 289: /* auth_flags_item: RESV_EXEMPT  */
#line 1518 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 5006 "conf_parser.c"
    break;

  case 290: /* auth_flags_item: T_WEBIRC  */
#line 1522 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5015 "conf_parser.c"
    break;

  case 291: /* auth_flags_item: NEED_PASSWORD  */
#line 1526 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5024 "conf_parser.c"
    break;

  case 292: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1532 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    log_write(LOG_TYPE_IRCD,
              "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 5039 "conf_parser.c"
    break;

  case 293: /* $@14: %empty  */
#line 1547 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5051 "conf_parser.c"
    break;

  case 294: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1554 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5062 "conf_parser.c"
    break;

  case 301: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1565 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5071 "conf_parser.c"
    break;

  case 302: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1571 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5080 "conf_parser.c"
    break;

  case 303: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1577 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5089 "conf_parser.c"
    break;

  case 309: /* service_name: NAME '=' QSTRING ';'  */
#line 1592 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5104 "conf_parser.c"
    break;

  case 310: /* $@15: %empty  */
#line 1608 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5120 "conf_parser.c"
    break;

  case 311: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1619 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5135 "conf_parser.c"
    break;

  case 318: /* shared_name: NAME '=' QSTRING ';'  */
#line 1634 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5144 "conf_parser.c"
    break;

  case 319: /* shared_user: USER '=' QSTRING ';'  */
#line 1640 "conf_parser.y"
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
#line 5166 "conf_parser.c"
    break;

  case 320: /* $@16: %empty  */
#line 1659 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5175 "conf_parser.c"
    break;

  case 324: /* shared_type_item: KLINE  */
#line 1666 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5184 "conf_parser.c"
    break;

  case 325: /* shared_type_item: UNKLINE  */
#line 1670 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5193 "conf_parser.c"
    break;

  case 326: /* shared_type_item: T_DLINE  */
#line 1674 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5202 "conf_parser.c"
    break;

  case 327: /* shared_type_item: T_UNDLINE  */
#line 1678 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5211 "conf_parser.c"
    break;

  case 328: /* shared_type_item: XLINE  */
#line 1682 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5220 "conf_parser.c"
    break;

  case 329: /* shared_type_item: T_UNXLINE  */
#line 1686 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5229 "conf_parser.c"
    break;

  case 330: /* shared_type_item: RESV  */
#line 1690 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5238 "conf_parser.c"
    break;

  case 331: /* shared_type_item: T_UNRESV  */
#line 1694 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5247 "conf_parser.c"
    break;

  case 332: /* shared_type_item: T_LOCOPS  */
#line 1698 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5256 "conf_parser.c"
    break;

  case 333: /* shared_type_item: T_ALL  */
#line 1702 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5265 "conf_parser.c"
    break;

  case 334: /* $@17: %empty  */
#line 1712 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5279 "conf_parser.c"
    break;

  case 335: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1721 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5292 "conf_parser.c"
    break;

  case 341: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1734 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5301 "conf_parser.c"
    break;

  case 342: /* $@18: %empty  */
#line 1740 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5310 "conf_parser.c"
    break;

  case 346: /* cluster_type_item: KLINE  */
#line 1747 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5319 "conf_parser.c"
    break;

  case 347: /* cluster_type_item: UNKLINE  */
#line 1751 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5328 "conf_parser.c"
    break;

  case 348: /* cluster_type_item: T_DLINE  */
#line 1755 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5337 "conf_parser.c"
    break;

  case 349: /* cluster_type_item: T_UNDLINE  */
#line 1759 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5346 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: XLINE  */
#line 1763 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5355 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: T_UNXLINE  */
#line 1767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5364 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: RESV  */
#line 1771 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5373 "conf_parser.c"
    break;

  case 353: /* cluster_type_item: T_UNRESV  */
#line 1775 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5382 "conf_parser.c"
    break;

  case 354: /* cluster_type_item: T_LOCOPS  */
#line 1779 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5391 "conf_parser.c"
    break;

  case 355: /* cluster_type_item: T_ALL  */
#line 1783 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5400 "conf_parser.c"
    break;

  case 356: /* $@19: %empty  */
#line 1793 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5414 "conf_parser.c"
    break;

  case 357: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1802 "conf_parser.y"
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
#line 5462 "conf_parser.c"
    break;

  case 375: /* connect_name: NAME '=' QSTRING ';'  */
#line 1864 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5471 "conf_parser.c"
    break;

  case 376: /* connect_host: HOST '=' QSTRING ';'  */
#line 1870 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5480 "conf_parser.c"
    break;

  case 377: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1876 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5489 "conf_parser.c"
    break;

  case 378: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1882 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5498 "conf_parser.c"
    break;

  case 379: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1888 "conf_parser.y"
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
#line 5514 "conf_parser.c"
    break;

  case 380: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1901 "conf_parser.y"
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
#line 5530 "conf_parser.c"
    break;

  case 381: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1914 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5539 "conf_parser.c"
    break;

  case 382: /* connect_port: PORT '=' NUMBER ';'  */
#line 1920 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5548 "conf_parser.c"
    break;

  case 383: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 1926 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5557 "conf_parser.c"
    break;

  case 384: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 1930 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5566 "conf_parser.c"
    break;

  case 385: /* $@20: %empty  */
#line 1936 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5574 "conf_parser.c"
    break;

  case 389: /* connect_flags_item: AUTOCONN  */
#line 1942 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5583 "conf_parser.c"
    break;

  case 390: /* connect_flags_item: T_TLS  */
#line 1946 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5592 "conf_parser.c"
    break;

  case 391: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1952 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5606 "conf_parser.c"
    break;

  case 392: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 1963 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5615 "conf_parser.c"
    break;

  case 393: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 1969 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5624 "conf_parser.c"
    break;

  case 394: /* connect_class: CLASS '=' QSTRING ';'  */
#line 1975 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5633 "conf_parser.c"
    break;

  case 395: /* $@21: %empty  */
#line 1985 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5642 "conf_parser.c"
    break;

  case 396: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 1989 "conf_parser.y"
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
#line 5666 "conf_parser.c"
    break;

  case 402: /* kill_user: USER '=' QSTRING ';'  */
#line 2013 "conf_parser.y"
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
#line 5689 "conf_parser.c"
    break;

  case 403: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2033 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5698 "conf_parser.c"
    break;

  case 404: /* $@22: %empty  */
#line 2043 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5707 "conf_parser.c"
    break;

  case 405: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2047 "conf_parser.y"
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
#line 5729 "conf_parser.c"
    break;

  case 411: /* deny_ip: IP '=' QSTRING ';'  */
#line 2069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5738 "conf_parser.c"
    break;

  case 412: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2075 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5747 "conf_parser.c"
    break;

  case 418: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2090 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_error_report("Unable to add D-line exemption");
}
#line 5759 "conf_parser.c"
    break;

  case 419: /* $@23: %empty  */
#line 2103 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5768 "conf_parser.c"
    break;

  case 420: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2107 "conf_parser.y"
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
#line 5788 "conf_parser.c"
    break;

  case 426: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2127 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5797 "conf_parser.c"
    break;

  case 427: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2133 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5806 "conf_parser.c"
    break;

  case 481: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2198 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5814 "conf_parser.c"
    break;

  case 482: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2203 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5822 "conf_parser.c"
    break;

  case 483: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2208 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5830 "conf_parser.c"
    break;

  case 484: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2213 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5838 "conf_parser.c"
    break;

  case 485: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2218 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5846 "conf_parser.c"
    break;

  case 486: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2223 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5854 "conf_parser.c"
    break;

  case 487: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2228 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5862 "conf_parser.c"
    break;

  case 488: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2233 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5870 "conf_parser.c"
    break;

  case 489: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2238 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5878 "conf_parser.c"
    break;

  case 490: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2243 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5886 "conf_parser.c"
    break;

  case 491: /* general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'  */
#line 2248 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5894 "conf_parser.c"
    break;

  case 492: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2253 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5902 "conf_parser.c"
    break;

  case 493: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2258 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5910 "conf_parser.c"
    break;

  case 494: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2263 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5918 "conf_parser.c"
    break;

  case 495: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2268 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5926 "conf_parser.c"
    break;

  case 496: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2273 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 5937 "conf_parser.c"
    break;

  case 497: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2281 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5945 "conf_parser.c"
    break;

  case 498: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2286 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5953 "conf_parser.c"
    break;

  case 499: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2291 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5961 "conf_parser.c"
    break;

  case 500: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2296 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5969 "conf_parser.c"
    break;

  case 501: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2301 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5977 "conf_parser.c"
    break;

  case 502: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2306 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5985 "conf_parser.c"
    break;

  case 503: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2311 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5993 "conf_parser.c"
    break;

  case 504: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2316 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6001 "conf_parser.c"
    break;

  case 505: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2321 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6009 "conf_parser.c"
    break;

  case 506: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2326 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6017 "conf_parser.c"
    break;

  case 507: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2331 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6025 "conf_parser.c"
    break;

  case 508: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2336 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6033 "conf_parser.c"
    break;

  case 509: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2341 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6041 "conf_parser.c"
    break;

  case 510: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2346 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6049 "conf_parser.c"
    break;

  case 511: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2351 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6057 "conf_parser.c"
    break;

  case 512: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2356 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6065 "conf_parser.c"
    break;

  case 513: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2361 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6073 "conf_parser.c"
    break;

  case 514: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2366 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6081 "conf_parser.c"
    break;

  case 515: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2371 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6089 "conf_parser.c"
    break;

  case 516: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2376 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6097 "conf_parser.c"
    break;

  case 517: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2381 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6109 "conf_parser.c"
    break;

  case 518: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2390 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6117 "conf_parser.c"
    break;

  case 519: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2395 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6125 "conf_parser.c"
    break;

  case 520: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2400 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6133 "conf_parser.c"
    break;

  case 521: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2405 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6141 "conf_parser.c"
    break;

  case 522: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2410 "conf_parser.y"
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
#line 6161 "conf_parser.c"
    break;

  case 523: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2427 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6172 "conf_parser.c"
    break;

  case 524: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2435 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6183 "conf_parser.c"
    break;

  case 525: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2443 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6194 "conf_parser.c"
    break;

  case 526: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2451 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6207 "conf_parser.c"
    break;

  case 527: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2461 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6220 "conf_parser.c"
    break;

  case 528: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2471 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6231 "conf_parser.c"
    break;

  case 529: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2479 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6239 "conf_parser.c"
    break;

  case 552: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2511 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6247 "conf_parser.c"
    break;

  case 553: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2516 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6256 "conf_parser.c"
    break;

  case 554: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2522 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6265 "conf_parser.c"
    break;

  case 555: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2528 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6273 "conf_parser.c"
    break;

  case 556: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2533 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6281 "conf_parser.c"
    break;

  case 557: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2538 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6289 "conf_parser.c"
    break;

  case 558: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2543 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6297 "conf_parser.c"
    break;

  case 559: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2548 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6305 "conf_parser.c"
    break;

  case 560: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2553 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6313 "conf_parser.c"
    break;

  case 561: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2558 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6321 "conf_parser.c"
    break;

  case 562: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2563 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6329 "conf_parser.c"
    break;

  case 563: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2568 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6337 "conf_parser.c"
    break;

  case 564: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2573 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6345 "conf_parser.c"
    break;

  case 565: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2578 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6353 "conf_parser.c"
    break;

  case 566: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2583 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6361 "conf_parser.c"
    break;

  case 567: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2588 "conf_parser.y"
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
#line 6387 "conf_parser.c"
    break;

  case 568: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2611 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6395 "conf_parser.c"
    break;

  case 569: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2616 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6403 "conf_parser.c"
    break;

  case 582: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2638 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6412 "conf_parser.c"
    break;

  case 583: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2644 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6426 "conf_parser.c"
    break;

  case 584: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2655 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6438 "conf_parser.c"
    break;

  case 585: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2664 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6447 "conf_parser.c"
    break;

  case 586: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2670 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6456 "conf_parser.c"
    break;

  case 587: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2676 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6465 "conf_parser.c"
    break;

  case 588: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2682 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6477 "conf_parser.c"
    break;

  case 589: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2691 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6486 "conf_parser.c"
    break;


#line 6490 "conf_parser.c"

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

