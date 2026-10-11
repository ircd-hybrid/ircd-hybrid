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
    HIDE_SERVERS = 319,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 320,           /* HIDE_SERVICES  */
    HOST = 321,                    /* HOST  */
    HUB = 322,                     /* HUB  */
    HUB_MASK = 323,                /* HUB_MASK  */
    IDENT_TIMEOUT = 324,           /* IDENT_TIMEOUT  */
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
    MAX_AWAY_LENGTH = 350,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 351,                /* MAX_BANS  */
    MAX_BANS_LARGE = 352,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 353,            /* MAX_CHANNELS  */
    MAX_IDLE = 354,                /* MAX_IDLE  */
    MAX_INVITES = 355,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 356,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 357,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 358,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 359,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 360,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 361,              /* MAX_NUMBER  */
    MAX_TARGETS = 362,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 363,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 364,                 /* MESSAGE  */
    MIN_IDLE = 365,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 366,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 367,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 368,                  /* MODULE  */
    MODULE_BASE_PATH = 369,        /* MODULE_BASE_PATH  */
    MOTD = 370,                    /* MOTD  */
    MOTD_FILE = 371,               /* MOTD_FILE  */
    NAME = 372,                    /* NAME  */
    NEED_IDENT = 373,              /* NEED_IDENT  */
    NEED_PASSWORD = 374,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 375,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 376,            /* NETWORK_NAME  */
    NICK = 377,                    /* NICK  */
    NO_OPER_FLOOD = 378,           /* NO_OPER_FLOOD  */
    NO_TILDE = 379,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 380,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 381,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 382,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 383,             /* OPER_UMODES  */
    OPERATOR = 384,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 385,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 386,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 387,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 388,                /* PASSWORD  */
    PATH = 389,                    /* PATH  */
    PING_COOKIE = 390,             /* PING_COOKIE  */
    PING_TIME = 391,               /* PING_TIME  */
    PORT = 392,                    /* PORT  */
    RANDOM_IDLE = 393,             /* RANDOM_IDLE  */
    REASON = 394,                  /* REASON  */
    REGISTRATION_TIMEOUT = 395,    /* REGISTRATION_TIMEOUT  */
    REHASH = 396,                  /* REHASH  */
    REMOTE = 397,                  /* REMOTE  */
    REMOTEBAN = 398,               /* REMOTEBAN  */
    RESIDENT = 399,                /* RESIDENT  */
    RESV = 400,                    /* RESV  */
    RESV_EXEMPT = 401,             /* RESV_EXEMPT  */
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
    STATS_U_OPER_ONLY = 418,       /* STATS_U_OPER_ONLY  */
    T_ALL = 419,                   /* T_ALL  */
    T_BIND = 420,                  /* T_BIND  */
    T_COMMAND = 421,               /* T_COMMAND  */
    T_CLUSTER = 422,               /* T_CLUSTER  */
    T_DEBUG = 423,                 /* T_DEBUG  */
    T_DLINE = 424,                 /* T_DLINE  */
    T_FILE = 425,                  /* T_FILE  */
    T_GLOBOPS = 426,               /* T_GLOBOPS  */
    T_IPV4 = 427,                  /* T_IPV4  */
    T_IPV6 = 428,                  /* T_IPV6  */
    T_LOCOPS = 429,                /* T_LOCOPS  */
    T_LOG = 430,                   /* T_LOG  */
    T_OPME = 431,                  /* T_OPME  */
    T_PREPEND = 432,               /* T_PREPEND  */
    T_PSEUDO = 433,                /* T_PSEUDO  */
    T_RECVQ = 434,                 /* T_RECVQ  */
    T_RESTART = 435,               /* T_RESTART  */
    T_SERVER = 436,                /* T_SERVER  */
    T_SERVICE = 437,               /* T_SERVICE  */
    T_SET = 438,                   /* T_SET  */
    T_SHARED = 439,                /* T_SHARED  */
    T_SIZE = 440,                  /* T_SIZE  */
    T_TARGET = 441,                /* T_TARGET  */
    T_TLS = 442,                   /* T_TLS  */
    T_UMODES = 443,                /* T_UMODES  */
    T_UNDLINE = 444,               /* T_UNDLINE  */
    T_UNLIMITED = 445,             /* T_UNLIMITED  */
    T_UNRESV = 446,                /* T_UNRESV  */
    T_UNXLINE = 447,               /* T_UNXLINE  */
    T_WEBIRC = 448,                /* T_WEBIRC  */
    TBOOL = 449,                   /* TBOOL  */
    THROTTLE_COUNT = 450,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 451,           /* THROTTLE_TIME  */
    TIMEOUT = 452,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 453,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 454, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 455,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 456, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 457,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 458,           /* TS_WARN_DELTA  */
    TWODOTS = 459,                 /* TWODOTS  */
    TYPE = 460,                    /* TYPE  */
    UNKLINE = 461,                 /* UNKLINE  */
    USE_LOGGING = 462,             /* USE_LOGGING  */
    USER = 463,                    /* USER  */
    VHOST = 464,                   /* VHOST  */
    VHOST6 = 465,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 466,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 467,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 468,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 469,                   /* XLINE  */
    XLINE_EXEMPT = 470,            /* XLINE_EXEMPT  */
    QSTRING = 471,                 /* QSTRING  */
    NUMBER = 472                   /* NUMBER  */
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
#define HIDE_SERVERS 319
#define HIDE_SERVICES 320
#define HOST 321
#define HUB 322
#define HUB_MASK 323
#define IDENT_TIMEOUT 324
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
#define MAX_AWAY_LENGTH 350
#define MAX_BANS 351
#define MAX_BANS_LARGE 352
#define MAX_CHANNELS 353
#define MAX_IDLE 354
#define MAX_INVITES 355
#define MAX_KICK_LENGTH 356
#define MAX_MONITOR 357
#define MAX_NICK_CHANGES 358
#define MAX_NICK_LENGTH 359
#define MAX_NICK_TIME 360
#define MAX_NUMBER 361
#define MAX_TARGETS 362
#define MAX_TOPIC_LENGTH 363
#define MESSAGE 364
#define MIN_IDLE 365
#define MIN_NONWILDCARD 366
#define MIN_NONWILDCARD_SIMPLE 367
#define MODULE 368
#define MODULE_BASE_PATH 369
#define MOTD 370
#define MOTD_FILE 371
#define NAME 372
#define NEED_IDENT 373
#define NEED_PASSWORD 374
#define NETWORK_DESCRIPTION 375
#define NETWORK_NAME 376
#define NICK 377
#define NO_OPER_FLOOD 378
#define NO_TILDE 379
#define NUMBER_PER_CIDR 380
#define NUMBER_PER_IP_GLOBAL 381
#define NUMBER_PER_IP_LOCAL 382
#define OPER_UMODES 383
#define OPERATOR 384
#define OPERS_BYPASS_CALLERID 385
#define PACE_WAIT 386
#define PACE_WAIT_SIMPLE 387
#define PASSWORD 388
#define PATH 389
#define PING_COOKIE 390
#define PING_TIME 391
#define PORT 392
#define RANDOM_IDLE 393
#define REASON 394
#define REGISTRATION_TIMEOUT 395
#define REHASH 396
#define REMOTE 397
#define REMOTEBAN 398
#define RESIDENT 399
#define RESV 400
#define RESV_EXEMPT 401
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
#define STATS_U_OPER_ONLY 418
#define T_ALL 419
#define T_BIND 420
#define T_COMMAND 421
#define T_CLUSTER 422
#define T_DEBUG 423
#define T_DLINE 424
#define T_FILE 425
#define T_GLOBOPS 426
#define T_IPV4 427
#define T_IPV6 428
#define T_LOCOPS 429
#define T_LOG 430
#define T_OPME 431
#define T_PREPEND 432
#define T_PSEUDO 433
#define T_RECVQ 434
#define T_RESTART 435
#define T_SERVER 436
#define T_SERVICE 437
#define T_SET 438
#define T_SHARED 439
#define T_SIZE 440
#define T_TARGET 441
#define T_TLS 442
#define T_UMODES 443
#define T_UNDLINE 444
#define T_UNLIMITED 445
#define T_UNRESV 446
#define T_UNXLINE 447
#define T_WEBIRC 448
#define TBOOL 449
#define THROTTLE_COUNT 450
#define THROTTLE_TIME 451
#define TIMEOUT 452
#define TLS_CERTIFICATE_FILE 453
#define TLS_CERTIFICATE_FINGERPRINT 454
#define TLS_PRIVATE_KEY_FILE 455
#define TLS_CONNECTION_REQUIRED 456
#define TS_MAX_DELTA 457
#define TS_WARN_DELTA 458
#define TWODOTS 459
#define TYPE 460
#define UNKLINE 461
#define USE_LOGGING 462
#define USER 463
#define VHOST 464
#define VHOST6 465
#define WARN_NO_CONNECT_BLOCK 466
#define WHOIS 467
#define WHOWAS_HISTORY_LENGTH 468
#define XLINE 469
#define XLINE_EXEMPT 470
#define QSTRING 471
#define NUMBER 472

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 684 "conf_parser.c"

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
  YYSYMBOL_HIDE_SERVERS = 64,              /* HIDE_SERVERS  */
  YYSYMBOL_HIDE_SERVICES = 65,             /* HIDE_SERVICES  */
  YYSYMBOL_HOST = 66,                      /* HOST  */
  YYSYMBOL_HUB = 67,                       /* HUB  */
  YYSYMBOL_HUB_MASK = 68,                  /* HUB_MASK  */
  YYSYMBOL_IDENT_TIMEOUT = 69,             /* IDENT_TIMEOUT  */
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
  YYSYMBOL_MAX_AWAY_LENGTH = 95,           /* MAX_AWAY_LENGTH  */
  YYSYMBOL_MAX_BANS = 96,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 97,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 98,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 99,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 100,              /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 101,          /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 102,              /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 103,         /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 104,          /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 105,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 106,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 107,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 108,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 109,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 110,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 111,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 112,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 113,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 114,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 115,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 116,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 117,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 118,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 119,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 120,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 121,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 122,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 123,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 124,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 125,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 126,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 127,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_UMODES = 128,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 129,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 130,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 131,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 132,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 133,                 /* PASSWORD  */
  YYSYMBOL_PATH = 134,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 135,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 136,                /* PING_TIME  */
  YYSYMBOL_PORT = 137,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 138,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 139,                   /* REASON  */
  YYSYMBOL_REGISTRATION_TIMEOUT = 140,     /* REGISTRATION_TIMEOUT  */
  YYSYMBOL_REHASH = 141,                   /* REHASH  */
  YYSYMBOL_REMOTE = 142,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 143,                /* REMOTEBAN  */
  YYSYMBOL_RESIDENT = 144,                 /* RESIDENT  */
  YYSYMBOL_RESV = 145,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 146,              /* RESV_EXEMPT  */
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
  YYSYMBOL_STATS_U_OPER_ONLY = 163,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_T_ALL = 164,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 165,                   /* T_BIND  */
  YYSYMBOL_T_COMMAND = 166,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 167,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 168,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 169,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 170,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 171,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 172,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 173,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 174,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 175,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 176,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 177,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 178,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 179,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 180,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 181,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 182,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 183,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 184,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 185,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 186,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 187,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 188,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 189,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 190,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 191,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 192,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 193,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 194,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 195,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 196,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 197,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 198,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 199, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_PRIVATE_KEY_FILE = 200,     /* TLS_PRIVATE_KEY_FILE  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 201,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TS_MAX_DELTA = 202,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 203,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 204,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 205,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 206,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 207,              /* USE_LOGGING  */
  YYSYMBOL_USER = 208,                     /* USER  */
  YYSYMBOL_VHOST = 209,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 210,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 211,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 212,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 213,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 214,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 215,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 216,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 217,                   /* NUMBER  */
  YYSYMBOL_218_ = 218,                     /* ';'  */
  YYSYMBOL_219_ = 219,                     /* '}'  */
  YYSYMBOL_220_ = 220,                     /* '='  */
  YYSYMBOL_221_ = 221,                     /* ':'  */
  YYSYMBOL_222_ = 222,                     /* ','  */
  YYSYMBOL_223_ = 223,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 224,                 /* $accept  */
  YYSYMBOL_conf = 225,                     /* conf  */
  YYSYMBOL_conf_item = 226,                /* conf_item  */
  YYSYMBOL_timespec_ = 227,                /* timespec_  */
  YYSYMBOL_timespec = 228,                 /* timespec  */
  YYSYMBOL_sizespec_ = 229,                /* sizespec_  */
  YYSYMBOL_sizespec = 230,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 231,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 232,         /* loadmodule_entry  */
  YYSYMBOL_module_attributes = 233,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 234,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 235,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 236,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 237,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 238,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 239, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_tls_private_key_file = 240, /* serverinfo_tls_private_key_file  */
  YYSYMBOL_serverinfo_name = 241,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 242,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 243,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 244,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 245, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 246, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 247, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_max_topic_length = 248, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_motd_file = 249,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 250,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 251,              /* admin_entry  */
  YYSYMBOL_admin_items = 252,              /* admin_items  */
  YYSYMBOL_admin_item = 253,               /* admin_item  */
  YYSYMBOL_admin_name = 254,               /* admin_name  */
  YYSYMBOL_admin_email = 255,              /* admin_email  */
  YYSYMBOL_admin_description = 256,        /* admin_description  */
  YYSYMBOL_motd_entry = 257,               /* motd_entry  */
  YYSYMBOL_258_1 = 258,                    /* $@1  */
  YYSYMBOL_motd_items = 259,               /* motd_items  */
  YYSYMBOL_motd_item = 260,                /* motd_item  */
  YYSYMBOL_motd_mask = 261,                /* motd_mask  */
  YYSYMBOL_motd_file = 262,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 263,             /* pseudo_entry  */
  YYSYMBOL_264_2 = 264,                    /* $@2  */
  YYSYMBOL_pseudo_items = 265,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 266,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 267,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 268,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 269,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 270,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 271,            /* logging_entry  */
  YYSYMBOL_logging_items = 272,            /* logging_items  */
  YYSYMBOL_logging_item = 273,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 274,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 275,       /* logging_file_entry  */
  YYSYMBOL_276_3 = 276,                    /* $@3  */
  YYSYMBOL_logging_file_items = 277,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 278,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 279,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 280,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 281,        /* logging_file_type  */
  YYSYMBOL_282_4 = 282,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 283,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 284,               /* oper_entry  */
  YYSYMBOL_285_5 = 285,                    /* $@5  */
  YYSYMBOL_oper_items = 286,               /* oper_items  */
  YYSYMBOL_oper_item = 287,                /* oper_item  */
  YYSYMBOL_oper_name = 288,                /* oper_name  */
  YYSYMBOL_oper_user = 289,                /* oper_user  */
  YYSYMBOL_oper_password = 290,            /* oper_password  */
  YYSYMBOL_oper_whois = 291,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 292,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 293, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 294, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 295,               /* oper_class  */
  YYSYMBOL_oper_umodes = 296,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 297,               /* oper_flags  */
  YYSYMBOL_298_6 = 298,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 299,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 300,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 301,              /* class_entry  */
  YYSYMBOL_302_7 = 302,                    /* $@7  */
  YYSYMBOL_class_items = 303,              /* class_items  */
  YYSYMBOL_class_item = 304,               /* class_item  */
  YYSYMBOL_class_name = 305,               /* class_name  */
  YYSYMBOL_class_ping_time = 306,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 307, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 308, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 309,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 310,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 311,         /* class_max_number  */
  YYSYMBOL_class_sendq = 312,              /* class_sendq  */
  YYSYMBOL_class_recvq = 313,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 314,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 315,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 316,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 317,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 318,           /* class_max_idle  */
  YYSYMBOL_class_flags = 319,              /* class_flags  */
  YYSYMBOL_320_8 = 320,                    /* $@8  */
  YYSYMBOL_class_flags_items = 321,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 322,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 323,             /* listen_entry  */
  YYSYMBOL_324_9 = 324,                    /* $@9  */
  YYSYMBOL_listen_flags = 325,             /* listen_flags  */
  YYSYMBOL_326_10 = 326,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 327,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 328,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 329,             /* listen_items  */
  YYSYMBOL_listen_item = 330,              /* listen_item  */
  YYSYMBOL_listen_port = 331,              /* listen_port  */
  YYSYMBOL_332_11 = 332,                   /* $@11  */
  YYSYMBOL_port_items = 333,               /* port_items  */
  YYSYMBOL_port_item = 334,                /* port_item  */
  YYSYMBOL_listen_address = 335,           /* listen_address  */
  YYSYMBOL_listen_host = 336,              /* listen_host  */
  YYSYMBOL_auth_entry = 337,               /* auth_entry  */
  YYSYMBOL_338_12 = 338,                   /* $@12  */
  YYSYMBOL_auth_items = 339,               /* auth_items  */
  YYSYMBOL_auth_item = 340,                /* auth_item  */
  YYSYMBOL_auth_user = 341,                /* auth_user  */
  YYSYMBOL_auth_passwd = 342,              /* auth_passwd  */
  YYSYMBOL_auth_class = 343,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 344,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 345,               /* auth_flags  */
  YYSYMBOL_346_13 = 346,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 347,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 348,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 349,               /* auth_spoof  */
  YYSYMBOL_resv_entry = 350,               /* resv_entry  */
  YYSYMBOL_351_14 = 351,                   /* $@14  */
  YYSYMBOL_resv_items = 352,               /* resv_items  */
  YYSYMBOL_resv_item = 353,                /* resv_item  */
  YYSYMBOL_resv_mask = 354,                /* resv_mask  */
  YYSYMBOL_resv_reason = 355,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 356,              /* resv_exempt  */
  YYSYMBOL_service_entry = 357,            /* service_entry  */
  YYSYMBOL_service_items = 358,            /* service_items  */
  YYSYMBOL_service_item = 359,             /* service_item  */
  YYSYMBOL_service_name = 360,             /* service_name  */
  YYSYMBOL_shared_entry = 361,             /* shared_entry  */
  YYSYMBOL_362_15 = 362,                   /* $@15  */
  YYSYMBOL_shared_items = 363,             /* shared_items  */
  YYSYMBOL_shared_item = 364,              /* shared_item  */
  YYSYMBOL_shared_name = 365,              /* shared_name  */
  YYSYMBOL_shared_user = 366,              /* shared_user  */
  YYSYMBOL_shared_type = 367,              /* shared_type  */
  YYSYMBOL_368_16 = 368,                   /* $@16  */
  YYSYMBOL_shared_types = 369,             /* shared_types  */
  YYSYMBOL_shared_type_item = 370,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 371,            /* cluster_entry  */
  YYSYMBOL_372_17 = 372,                   /* $@17  */
  YYSYMBOL_cluster_items = 373,            /* cluster_items  */
  YYSYMBOL_cluster_item = 374,             /* cluster_item  */
  YYSYMBOL_cluster_name = 375,             /* cluster_name  */
  YYSYMBOL_cluster_type = 376,             /* cluster_type  */
  YYSYMBOL_377_18 = 377,                   /* $@18  */
  YYSYMBOL_cluster_types = 378,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 379,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 380,            /* connect_entry  */
  YYSYMBOL_381_19 = 381,                   /* $@19  */
  YYSYMBOL_connect_items = 382,            /* connect_items  */
  YYSYMBOL_connect_item = 383,             /* connect_item  */
  YYSYMBOL_connect_name = 384,             /* connect_name  */
  YYSYMBOL_connect_host = 385,             /* connect_host  */
  YYSYMBOL_connect_timeout = 386,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 387,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 388,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 389,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 390, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 391,             /* connect_port  */
  YYSYMBOL_connect_aftype = 392,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 393,            /* connect_flags  */
  YYSYMBOL_394_20 = 394,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 395,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 396,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 397,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 398,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 399,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 400,            /* connect_class  */
  YYSYMBOL_kill_entry = 401,               /* kill_entry  */
  YYSYMBOL_402_21 = 402,                   /* $@21  */
  YYSYMBOL_kill_items = 403,               /* kill_items  */
  YYSYMBOL_kill_item = 404,                /* kill_item  */
  YYSYMBOL_kill_user = 405,                /* kill_user  */
  YYSYMBOL_kill_reason = 406,              /* kill_reason  */
  YYSYMBOL_deny_entry = 407,               /* deny_entry  */
  YYSYMBOL_408_22 = 408,                   /* $@22  */
  YYSYMBOL_deny_items = 409,               /* deny_items  */
  YYSYMBOL_deny_item = 410,                /* deny_item  */
  YYSYMBOL_deny_ip = 411,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 412,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 413,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 414,             /* exempt_items  */
  YYSYMBOL_exempt_item = 415,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 416,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 417,              /* gecos_entry  */
  YYSYMBOL_418_23 = 418,                   /* $@23  */
  YYSYMBOL_gecos_items = 419,              /* gecos_items  */
  YYSYMBOL_gecos_item = 420,               /* gecos_item  */
  YYSYMBOL_gecos_name = 421,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 422,             /* gecos_reason  */
  YYSYMBOL_general_entry = 423,            /* general_entry  */
  YYSYMBOL_general_items = 424,            /* general_items  */
  YYSYMBOL_general_item = 425,             /* general_item  */
  YYSYMBOL_general_away_count = 426,       /* general_away_count  */
  YYSYMBOL_general_away_time = 427,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 428,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 429, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 430, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 431,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 432,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 433,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 434,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 435, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_anti_nick_flood = 436,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 437,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 438, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 439,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 440,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 441, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 442,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 443,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 444, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 445, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 446, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_u_oper_only = 447, /* general_stats_u_oper_only  */
  YYSYMBOL_general_pace_wait = 448,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 449,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 450, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 451, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 452,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 453,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 454, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 455,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 456,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_ident = 457,    /* general_disable_ident  */
  YYSYMBOL_general_disable_dns = 458,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 459,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 460,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 461,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 462,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 463, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 464, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 465, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 466,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 467, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 468, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 469,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 470,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 471,     /* general_cloak_suffix  */
  YYSYMBOL_general_ident_timeout = 472,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 473, /* general_registration_timeout  */
  YYSYMBOL_channel_entry = 474,            /* channel_entry  */
  YYSYMBOL_channel_items = 475,            /* channel_items  */
  YYSYMBOL_channel_item = 476,             /* channel_item  */
  YYSYMBOL_channel_enable_extbans = 477,   /* channel_enable_extbans  */
  YYSYMBOL_channel_enable_owner = 478,     /* channel_enable_owner  */
  YYSYMBOL_channel_enable_admin = 479,     /* channel_enable_admin  */
  YYSYMBOL_channel_disable_fake_channels = 480, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 481, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 482, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 483, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 484, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 485, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 486, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 487, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 488,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 489,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 490,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 491,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 492,  /* channel_max_kick_length  */
  YYSYMBOL_channel_default_join_flood_count = 493, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 494, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 495,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 496,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 497,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 498, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 499, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 500, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 501, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 502,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 503, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 504,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 505         /* serverhide_hidden  */
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
#define YYLAST   1180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  224
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  282
/* YYNRULES -- Number of rules.  */
#define YYNRULES  587
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1221

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   472


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
       2,     2,     2,     2,   222,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   221,   218,
       2,   220,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   223,     2,   219,     2,     2,     2,     2,
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
     215,   216,   217
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   352,   352,   353,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   384,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   395,
     395,   396,   397,   398,   399,   406,   416,   423,   425,   427,
     427,   429,   433,   443,   445,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   461,
     470,   479,   494,   509,   519,   533,   542,   565,   588,   596,
     605,   615,   617,   617,   618,   619,   620,   621,   623,   632,
     641,   655,   654,   672,   672,   673,   673,   673,   675,   681,
     692,   691,   710,   710,   711,   711,   711,   711,   711,   713,
     719,   725,   731,   754,   755,   755,   757,   757,   758,   760,
     770,   770,   783,   784,   786,   786,   787,   787,   789,   797,
     800,   806,   805,   811,   815,   819,   823,   827,   831,   835,
     839,   850,   849,   911,   911,   912,   913,   914,   915,   916,
     917,   918,   919,   920,   921,   922,   924,   930,   936,   942,
     948,   959,   965,   976,   982,   989,   988,   994,   994,   995,
     999,  1003,  1007,  1011,  1015,  1019,  1023,  1027,  1031,  1035,
    1039,  1043,  1047,  1051,  1055,  1059,  1063,  1067,  1071,  1075,
    1079,  1083,  1087,  1091,  1095,  1099,  1103,  1107,  1118,  1117,
    1173,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1191,  1197,
    1203,  1209,  1215,  1221,  1227,  1233,  1239,  1246,  1252,  1258,
    1264,  1273,  1283,  1282,  1288,  1288,  1289,  1293,  1304,  1303,
    1310,  1309,  1314,  1314,  1315,  1319,  1323,  1327,  1331,  1337,
    1337,  1338,  1338,  1338,  1338,  1338,  1340,  1340,  1342,  1342,
    1344,  1357,  1374,  1380,  1391,  1390,  1446,  1446,  1447,  1448,
    1449,  1450,  1451,  1452,  1453,  1455,  1461,  1467,  1473,  1485,
    1484,  1490,  1490,  1492,  1496,  1500,  1504,  1508,  1512,  1516,
    1520,  1524,  1530,  1546,  1545,  1560,  1560,  1561,  1561,  1561,
    1561,  1563,  1569,  1575,  1585,  1587,  1587,  1588,  1588,  1590,
    1607,  1606,  1629,  1629,  1630,  1630,  1630,  1630,  1632,  1638,
    1658,  1657,  1663,  1663,  1664,  1668,  1672,  1676,  1680,  1684,
    1688,  1692,  1696,  1700,  1711,  1710,  1729,  1729,  1730,  1730,
    1730,  1732,  1739,  1738,  1744,  1744,  1745,  1749,  1753,  1757,
    1761,  1765,  1769,  1773,  1777,  1781,  1792,  1791,  1845,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,
    1856,  1857,  1858,  1859,  1860,  1862,  1868,  1874,  1880,  1886,
    1899,  1912,  1918,  1924,  1928,  1935,  1934,  1939,  1939,  1940,
    1944,  1950,  1961,  1967,  1973,  1984,  1983,  2008,  2008,  2009,
    2009,  2009,  2011,  2031,  2042,  2041,  2064,  2064,  2065,  2065,
    2065,  2067,  2073,  2083,  2085,  2085,  2086,  2086,  2088,  2102,
    2101,  2122,  2122,  2123,  2123,  2123,  2125,  2131,  2141,  2143,
    2143,  2144,  2145,  2146,  2147,  2148,  2149,  2150,  2151,  2152,
    2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,  2171,  2172,
    2173,  2174,  2175,  2176,  2177,  2178,  2179,  2180,  2181,  2182,
    2183,  2184,  2185,  2186,  2187,  2188,  2189,  2190,  2191,  2192,
    2195,  2200,  2205,  2210,  2215,  2220,  2225,  2230,  2235,  2240,
    2245,  2250,  2255,  2260,  2265,  2273,  2278,  2283,  2288,  2293,
    2298,  2303,  2308,  2313,  2318,  2323,  2328,  2333,  2338,  2343,
    2348,  2353,  2358,  2363,  2368,  2373,  2382,  2387,  2392,  2397,
    2402,  2419,  2427,  2435,  2443,  2453,  2463,  2471,  2480,  2482,
    2482,  2483,  2484,  2485,  2486,  2487,  2488,  2489,  2490,  2491,
    2492,  2493,  2494,  2495,  2496,  2497,  2498,  2499,  2500,  2501,
    2503,  2508,  2514,  2520,  2525,  2530,  2535,  2540,  2545,  2550,
    2555,  2560,  2565,  2570,  2575,  2580,  2603,  2608,  2617,  2619,
    2619,  2620,  2621,  2622,  2623,  2624,  2625,  2626,  2627,  2628,
    2630,  2636,  2647,  2656,  2662,  2668,  2674,  2683
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
  "ENABLE_OWNER", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FLATTEN_LINKS",
  "FLATTEN_LINKS_DELAY", "FLATTEN_LINKS_FILE", "GECOS", "GENERAL",
  "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
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

#define YYPACT_NINF (-952)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -952,   651,  -952,  -137,  -209,  -207,  -952,  -952,  -952,  -183,
    -952,  -178,  -952,  -952,  -952,  -179,  -170,  -952,  -952,  -952,
    -171,  -156,  -952,  -136,  -952,  -126,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,   294,   805,  -125,  -124,  -122,    19,  -119,
     423,  -110,  -109,  -100,  -161,  -153,   -97,   -85,   -75,   417,
     500,   -67,    20,   -61,    10,   -42,   -21,    -6,    14,    51,
       4,  -952,  -952,  -952,  -952,  -952,    52,    54,    61,    64,
      77,    78,    81,    85,    88,    96,    98,   104,   105,   106,
     110,   111,   112,   118,   190,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,   646,   556,    37,  -952,   119,     2,
    -952,  -952,   198,  -952,   120,   122,   124,   128,   129,   132,
     133,   136,   137,   145,   146,   148,   152,   153,   154,   155,
     156,   157,   159,   161,   163,   164,   165,   166,   169,   172,
     174,   175,   176,   187,   192,   193,   195,   197,   199,   200,
     201,   202,   203,   206,   207,   208,   211,   214,   215,   218,
     219,   222,    47,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,   292,     5,   322,   -26,    29,    39,    38,   389,
     254,  -952,   230,   231,   233,   237,   238,   240,   247,   255,
     109,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
      55,   258,   259,   263,   264,   265,   267,   268,   269,   270,
     271,   274,   275,   243,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,    43,    86,   279,
      22,  -952,  -952,  -952,   293,    17,  -952,   282,    40,  -952,
    -952,    23,  -952,   113,   194,   287,   144,  -952,   295,   296,
     315,   317,   320,   321,   302,   296,   296,   296,   303,   296,
     296,   304,   306,   307,   310,   312,   298,  -952,   313,   318,
     323,   324,  -952,   325,   327,   328,   336,   340,   342,   345,
     346,   356,   360,   364,    90,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,   314,   367,   369,   371,   373,   374,   375,  -952,   376,
     378,   382,   383,   386,   390,   392,   217,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,   394,   403,    27,  -952,  -952,  -952,   326,
     319,  -952,  -952,   408,   409,    16,  -952,  -952,  -952,   347,
     296,   413,   296,   296,   415,   418,   420,   421,   416,   424,
     448,   426,   296,   454,   455,   437,   439,   296,   463,   296,
     441,   443,   449,   451,   460,   461,   296,   464,   465,   466,
     471,   456,   486,   296,   296,   491,   296,   492,   473,   493,
     494,   474,   296,   296,   296,   498,   477,   479,  -952,   483,
     475,   482,  -952,   485,   487,   495,   142,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,   496,   497,    46,  -952,  -952,
    -952,   501,   502,   504,  -952,   505,  -952,    34,  -952,  -952,
    -952,  -952,  -952,  -952,   489,  -952,  -952,  -952,   508,   509,
     510,    32,  -952,  -952,  -952,   514,   513,   515,  -952,   516,
     517,   518,   519,   520,   523,   526,   179,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,   529,   528,
     530,   531,    33,  -952,  -952,  -952,  -952,   534,   555,   296,
     538,   565,   544,   567,   568,   546,  -952,  -952,   503,   551,
     574,   554,   557,   559,   561,   562,   563,   569,   570,   571,
     566,  -952,   572,   575,  -952,    94,  -952,  -952,  -952,  -952,
     587,   573,  -952,   147,   582,   585,   590,   591,   592,    18,
    -952,  -952,  -952,  -952,  -952,   576,   584,  -952,   596,   597,
    -952,   600,    84,  -952,  -952,  -952,  -952,   605,   606,   609,
    -952,   610,   253,   613,   614,   616,   619,   623,   625,   627,
     628,   629,   631,   632,   633,   634,   638,   639,   640,   641,
    -952,  -952,   643,   644,   296,   622,   645,   296,   647,   296,
     593,   648,   649,   650,   296,   652,   652,   653,  -952,  -952,
     654,   -89,   656,   595,   657,   658,   655,   664,   665,   666,
     668,   669,   296,   670,   671,  -952,   672,   674,   676,  -952,
     677,  -952,   680,   681,   682,  -952,   686,   689,   690,   691,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,   706,   707,   708,   709,   710,   711,
     712,   713,   714,   715,   716,   717,   718,   719,   720,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,   734,   735,  -952,  -952,   683,   688,   667,   738,
     739,   740,   741,  -952,   742,   744,   743,  -952,  -952,   746,
     747,   678,   748,   749,  -952,   -26,  -952,   750,   752,   751,
    -952,  -952,   754,   763,   753,   755,   756,   758,   759,   770,
     760,   761,   762,  -952,  -952,   765,   766,   767,   768,  -952,
     769,   771,   772,   773,   774,   775,   776,   777,  -952,   778,
     779,   780,   781,   782,   783,   784,   785,   786,   787,   788,
     789,  -952,  -952,   792,   764,   791,  -952,   793,  -952,   150,
    -952,   794,   796,   797,   798,   799,  -952,   800,  -952,  -952,
     803,   795,   804,   806,  -952,  -952,  -952,  -952,  -952,   296,
     296,   296,   296,   296,   296,   296,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,   807,   808,   809,   -48,   810,
     811,   812,   813,   814,   815,   816,   817,   818,    53,   819,
     820,  -952,   821,   822,   823,   824,   825,   826,   827,    -1,
     828,   829,   830,   831,   832,   833,   834,  -952,   835,   836,
    -952,  -952,   837,   838,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,   839,   840,   481,   841,   842,   843,  -952,
     844,   845,  -952,   846,   847,   299,   499,   757,  -952,  -952,
    -952,   848,   849,  -952,   850,   851,   470,   852,   853,   854,
     855,   856,   857,   858,  -952,   859,   860,   861,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,   862,
     624,  -952,  -952,   863,   801,   802,  -952,    95,  -952,  -952,
    -952,  -952,   864,   865,   866,   867,  -952,  -952,   868,   630,
     869,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -193,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,   652,   652,   652,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -192,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -191,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -186,
    -952,   871,   748,   872,  -952,  -952,  -952,  -952,  -952,  -952,
     478,  -952,   642,   870,  -952,   873,  -952,   874,   875,  -952,
    -952,   876,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -176,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -163,  -952,  -952,   877,
    -168,   878,   881,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -160,
    -952,  -952,  -952,   -48,  -952,  -952,  -952,  -952,    -1,  -952,
     481,  -952,   299,  -952,  -952,  -952,   398,   944,   950,   620,
     955,   959,   960,  -952,   470,  -952,   624,   885,   886,   887,
     589,  -952,  -952,   630,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,   888,  -952,
    -952
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
       0,    83,    84,    86,    85,   549,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   530,   546,   547,   548,   545,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   531,
     532,   542,   543,   544,     0,     0,     0,   417,     0,     0,
     415,   416,     0,   479,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   430,   431,   432,   469,   437,   470,   464,
     465,   466,   467,   441,   433,   434,   435,   436,   451,   438,
     439,   440,   442,   443,   468,   445,   446,   453,   454,   447,
     448,   449,   444,   450,   461,   462,   463,   459,   460,   452,
     457,   458,   455,   456,   471,   472,   473,   474,   475,   476,
     477,   478,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   579,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   570,   571,   572,   573,   574,   575,   576,   578,   577,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    67,    65,    56,    66,    58,
      59,    60,    61,    62,    63,    64,    57,     0,     0,     0,
       0,   115,   116,   117,     0,     0,   308,     0,     0,   306,
     307,     0,    87,     0,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   529,     0,     0,
       0,     0,   232,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   202,   205,   207,   208,
     209,   210,   211,   212,   213,   203,   204,   206,   214,   215,
     216,     0,     0,     0,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
     362,   363,   364,   365,   366,   368,   367,   369,   373,   370,
     371,   372,   410,     0,     0,     0,   407,   408,   409,     0,
       0,   414,   425,     0,     0,     0,   422,   423,   424,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   429,     0,
       0,     0,   279,     0,     0,     0,     0,   267,   268,   269,
     270,   273,   271,   272,   401,     0,     0,     0,   398,   399,
     400,     0,     0,     0,   240,     0,   252,     0,   250,   251,
     253,   254,    52,    51,    48,    50,    46,    45,     0,     0,
       0,     0,    94,    95,    96,     0,     0,     0,   165,     0,
       0,     0,     0,     0,     0,     0,     0,   144,   145,   146,
     147,   148,   151,   152,   153,   150,   149,   154,     0,     0,
       0,     0,     0,   296,   297,   298,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   569,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,   342,     0,   337,   338,   339,   118,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
     103,   104,   106,   105,   107,     0,     0,   305,     0,     0,
     320,     0,     0,   313,   314,   315,   316,     0,     0,     0,
      81,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,   374,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   358,     0,     0,     0,   406,
       0,   413,     0,     0,     0,   421,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   428,   274,     0,     0,     0,     0,
       0,     0,     0,   266,     0,     0,     0,   397,   255,     0,
       0,     0,     0,     0,   249,     0,    97,     0,     0,     0,
      93,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   300,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,     0,     0,   568,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,   340,     0,     0,     0,   336,     0,   113,     0,
     108,     0,     0,     0,     0,     0,   102,     0,   304,   317,
       0,     0,     0,     0,   312,    90,    89,    88,   566,    29,
      29,    29,    29,    29,    29,    29,    31,    30,   567,   553,
     552,   550,   551,   554,   555,   556,   557,   558,   559,   560,
     563,   564,   561,   562,   565,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,     0,
       0,   199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   357,     0,     0,
     405,   418,     0,     0,   420,   490,   495,   480,   481,   503,
     520,   521,   522,   523,   524,   525,   484,   518,   519,   512,
     511,   485,   486,   526,   498,   489,   487,   488,   493,   494,
     482,   492,   491,   509,   516,   517,   507,   515,   504,   502,
     505,   510,   527,   506,   508,   500,   501,   513,   514,   497,
     496,   499,   483,     0,     0,     0,     0,     0,     0,   265,
       0,     0,   396,     0,     0,     0,   260,   256,   259,   239,
      49,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,     0,     0,     0,   294,   583,
     580,   581,   582,   587,   586,   584,   585,    76,    73,    80,
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
    -952,  -952,  -952,  -241,  -307,  -951,  -635,  -952,  -952,  -952,
    -952,    48,  -952,  -952,   879,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,   898,
    -952,  -952,  -952,  -952,  -952,  -952,   213,  -952,  -952,  -952,
    -952,  -952,   289,  -952,  -952,  -952,  -952,  -952,  -952,   880,
    -952,  -952,  -952,  -952,    -2,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,   472,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,   -77,  -952,  -952,  -952,
     679,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -147,  -952,
    -952,  -952,  -952,  -952,   -64,  -952,   626,  -952,  -952,  -952,
      28,  -952,  -952,  -952,  -952,  -952,   659,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,   -59,  -952,  -952,  -952,  -952,   577,
    -952,  -952,  -952,  -952,  -952,   882,  -952,  -952,  -952,  -952,
     522,  -952,  -952,  -952,  -952,  -952,   -81,  -952,  -952,  -952,
     550,  -952,  -952,  -952,  -952,   -70,  -952,  -952,  -952,   745,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,   -51,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
     660,  -952,  -952,  -952,  -952,  -952,   736,  -952,  -952,  -952,
    -952,   989,  -952,  -952,  -952,  -952,   737,  -952,  -952,  -952,
    -952,   937,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  1016,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,   883,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   816,   817,  1028,  1029,    28,    29,   236,
     494,   495,    30,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,    31,    80,    81,
      82,    83,    84,    32,    66,   501,   502,   503,   504,    33,
      73,   579,   580,   581,   582,   583,   584,    34,   290,   291,
     292,   293,   294,   987,   988,   989,   990,   991,  1141,  1218,
      35,    67,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   744,  1113,  1114,    36,    55,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   625,  1014,  1015,    37,
      63,   486,   731,  1079,  1080,   487,   488,   489,  1083,   937,
     938,   490,   491,    38,    61,   466,   467,   468,   469,   470,
     471,   472,   718,  1065,  1066,   473,    39,    68,   532,   533,
     534,   535,   536,    40,   298,   299,   300,    41,    75,   592,
     593,   594,   595,   596,   801,  1159,  1160,    42,    71,   565,
     566,   567,   568,   784,  1136,  1137,    43,    56,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     646,  1041,  1042,   388,   389,   390,   391,    44,    62,   477,
     478,   479,   480,    45,    57,   395,   396,   397,   398,    46,
     129,   130,   131,    47,    59,   405,   406,   407,   408,    48,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
      49,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    50,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     849,   850,   603,   127,   492,    76,   474,  1039,   609,   610,
     611,   296,   613,   614,    53,  1012,    54,   402,   574,   574,
     127,   288,  1188,   288,   588,  1162,  1167,  1169,   392,  1163,
    1168,  1170,  1171,   498,   528,   481,  1172,    64,   392,   498,
      58,   296,  1183,    77,   562,    60,  1184,   474,   133,   848,
      65,    78,    69,   134,   135,  1185,   136,   137,  1192,  1186,
     235,   138,  1193,   237,  1025,  1026,  1027,    70,   139,   140,
     141,   142,   143,   144,  1164,  1165,  1166,   128,   145,   146,
     147,    51,    52,   853,   854,   588,   529,    72,   148,   149,
    1013,   328,   150,   151,   128,   562,   983,    74,   124,   125,
     482,   126,   393,   667,   132,   669,   670,   329,   330,   483,
     241,   484,   393,   232,   233,   679,   152,   153,   493,   331,
     684,    79,   686,   234,   499,   530,   238,   297,   154,   693,
     499,   155,   156,   403,   575,   575,   700,   701,   239,   703,
     589,   157,   158,   459,   475,   709,   710,   711,   240,   159,
     160,   983,   161,   242,   162,   404,   287,   297,   163,   164,
     563,   460,   295,   243,   244,   245,   394,   332,   246,   247,
     165,   485,   531,   248,   249,   166,   394,   167,   168,   169,
     505,   301,   170,   576,   576,   475,  1040,   171,   333,   334,
    -120,    85,  -120,   461,   577,   577,   335,   302,   506,   402,
     336,   589,   500,   578,   578,   172,   173,   337,   500,   174,
     175,   563,   984,   476,   303,   338,   339,   340,   361,   462,
     362,   400,   363,   306,    86,    87,   341,   289,   590,   289,
     507,   591,   762,    88,   304,   664,   364,   795,    89,    90,
      91,   571,   176,   177,   260,   342,   658,   496,   564,   178,
     179,   739,   758,   733,   476,   528,   508,   497,   180,   586,
     181,    92,    93,    94,    95,   726,   457,   984,   365,   343,
     848,   305,   308,   547,   309,   463,    96,    97,    98,   261,
     985,   310,   262,   366,   311,   367,    99,   100,   101,   590,
     102,   103,   591,   459,   368,    76,   509,   312,   313,   564,
     986,   314,   464,   803,   569,   315,   369,   529,   316,   637,
     263,   460,   510,   785,  1142,   403,   317,   837,   318,  1074,
     840,   264,   842,   481,   319,   320,   321,   847,   545,   597,
     322,   323,   324,    77,   370,   985,  1075,   404,   325,   399,
     409,    78,   410,   461,   411,   865,   530,   265,   412,   413,
     465,   266,   414,   415,   371,   986,   416,   417,  1076,   267,
     268,   722,   600,   269,   270,   418,   419,   511,   420,   462,
     789,   372,   421,   422,   423,   424,   425,   426,   512,   427,
     513,   428,   373,   429,   430,   431,   432,   514,   482,   433,
     505,   515,   434,   531,   435,   436,   437,   483,   752,   484,
     809,   810,   811,   812,   813,   814,   815,   438,   506,   326,
     598,    79,   439,   440,   374,   441,   375,   442,   241,   443,
     444,   445,   446,   447,   133,   463,   448,   449,   450,   134,
     135,   451,   136,   137,   452,   453,   654,   138,   454,   455,
     507,   271,   456,   272,   139,   140,   141,   142,   143,   144,
     537,   538,   464,   539,   145,   146,   147,   540,   541,   485,
     542,   242,   560,   573,   148,   149,   508,   543,   150,   151,
     602,   243,   244,   245,  1088,   544,   246,   247,   548,   549,
    1077,   248,   249,   550,   551,   552,  1078,   553,   554,   555,
     556,   557,   152,   153,   558,   559,  1056,  1089,  1090,   570,
     465,   260,   585,   599,   154,  1189,   509,   155,   156,   604,
    1091,   605,   601,   602,   606,   607,   620,   157,   158,   608,
     612,   615,   510,   616,   617,   159,   160,   618,   161,   619,
     162,   621,   639,  1057,   163,   164,   261,   661,   622,   262,
    1198,   666,   660,   623,   624,   626,   165,   627,   628,  1092,
    1093,   166,  1094,   167,   168,   169,   629,   361,   170,   362,
     630,   363,   631,   171,  1058,   632,   633,   263,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,   364,   634,   511,   264,  1095,
     635,   172,   173,  1096,   636,   174,   175,   640,   512,   641,
     513,   642,  1097,   643,   644,   645,   647,   514,   648,  1059,
    1060,   515,   649,   650,   265,  1061,   651,   365,   266,   671,
     652,  1098,   653,  1099,   656,  1100,   267,   268,   176,   177,
     269,   270,   366,   657,   367,   178,   179,  1062,   662,   663,
     668,  1101,   675,   368,   180,   672,   181,   673,   674,  1102,
     676,  1103,   677,   678,  1104,   369,  1105,   328,   680,   681,
    1106,     2,     3,  1107,   682,     4,   683,   685,   687,  1108,
     688,  1109,  1110,   329,   330,   697,   689,     5,   690,  1210,
       6,  1211,   698,   370,  1063,   331,  1111,   691,   692,     7,
     699,   694,   695,   696,  1112,   702,   704,   706,   707,     8,
     705,   708,   712,   371,   713,   716,  1064,   714,   271,  1176,
     272,   715,   717,  1081,     9,   719,  1126,   720,    10,    11,
     372,   735,  1149,  1201,   740,   721,   724,   725,  1212,   728,
     769,   373,   729,   332,   730,   732,   736,    12,   760,   737,
     738,    13,   741,   742,  1213,   743,   745,   746,   747,   748,
     749,    14,    15,   750,   333,   334,   751,   754,   755,   761,
     756,   757,   335,   374,   763,   375,   336,  1214,  1215,   764,
     765,   766,   767,   337,   768,    16,    17,   770,   771,  1127,
     772,   338,   339,   340,   773,  1150,   774,   775,   776,   777,
      18,   787,   341,   940,   781,   778,   779,   780,  1128,   856,
     782,   788,   797,  1129,  1151,   783,    19,  1216,  1130,  1152,
     790,   342,   798,  1217,  1153,   791,    85,    20,    21,   843,
     792,   793,   794,  1131,   799,  1132,  1133,   800,    22,  1154,
     802,  1155,  1156,   805,   806,   343,    23,   807,   808,    24,
    1134,   818,   819,    25,   820,    26,  1157,   821,  1135,    86,
      87,   822,   838,   823,  1158,   824,   825,   826,    88,   827,
     828,   829,   830,    89,    90,    91,   831,   832,   833,   834,
     835,   836,   839,  1177,   841,   844,   845,   846,   796,   848,
     852,   851,   855,   857,   858,   859,    92,    93,    94,    95,
     860,   861,   924,   862,   863,   864,   866,   925,   868,   867,
     869,    96,    97,    98,   870,   871,   872,   873,   935,   923,
     874,    99,   100,   101,   875,   102,   103,   876,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,   887,   888,
     889,   890,   891,   892,   893,   894,   895,   896,   897,   898,
     899,   900,   901,   902,   903,   904,   905,   906,   907,   908,
     909,   910,   911,   912,   913,   914,   915,   916,   917,   918,
     919,   920,   921,   922,   926,   927,   928,   945,   930,   929,
     931,   932,   933,   934,   951,   936,   941,   939,   942,   943,
     944,   947,   948,   946,   949,   950,   952,   953,   307,  1082,
     954,   955,   956,   957,   980,  1143,   958,   959,   753,   960,
     961,   962,   963,   964,   965,   966,   967,   968,   969,   970,
     971,   972,   973,   974,   975,   976,   977,   978,   979,   981,
     992,   982,   993,   994,   995,   999,  1194,   996,   997,   998,
    1000,  1139,  1140,   638,  1001,  1009,  1010,  1011,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1037,  1038,  1043,  1044,  1045,  1046,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,  1067,
    1068,  1069,  1070,  1071,  1072,  1073,  1084,  1085,  1086,  1087,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1138,  1144,  1145,  1146,  1147,  1148,  1161,  1173,  1199,
    1175,  1178,  1200,  1187,  1179,  1180,  1181,  1182,  1190,  1191,
    1202,  1203,  1204,  1207,  1208,  1209,  1220,  1205,  1197,   759,
    1174,  1196,  1219,   734,   804,   786,  1206,  1195,   401,   458,
     327,   655,     0,     0,     0,   723,     0,     0,     0,     0,
       0,   659,     0,   546,     0,     0,     0,   727,     0,     0,
       0,     0,   665,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   561,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     572,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     587
};

static const yytype_int16 yycheck[] =
{
     635,   636,   309,     1,    30,     1,     1,     8,   315,   316,
     317,     1,   319,   320,   223,    63,   223,     1,     1,     1,
       1,     1,   190,     1,     1,   218,   218,   218,     1,   222,
     222,   222,   218,     1,     1,     1,   222,   216,     1,     1,
     223,     1,   218,    39,     1,   223,   222,     1,     1,   217,
     220,    47,   223,     6,     7,   218,     9,    10,   218,   222,
     221,    14,   222,   216,    11,    12,    13,   223,    21,    22,
      23,    24,    25,    26,  1025,  1026,  1027,    75,    31,    32,
      33,   218,   219,   172,   173,     1,    53,   223,    41,    42,
     138,     1,    45,    46,    75,     1,     1,   223,   223,   223,
      66,   223,    75,   410,   223,   412,   413,    17,    18,    75,
       1,    77,    75,   223,   223,   422,    69,    70,   144,    29,
     427,   117,   429,   223,    92,    92,   223,   117,    81,   436,
      92,    84,    85,   117,   117,   117,   443,   444,   223,   446,
     117,    94,    95,     1,   139,   452,   453,   454,   223,   102,
     103,     1,   105,    44,   107,   139,   223,   117,   111,   112,
     117,    19,   223,    54,    55,    56,   139,    77,    59,    60,
     123,   137,   139,    64,    65,   128,   139,   130,   131,   132,
       1,   223,   135,   166,   166,   139,   187,   140,    98,    99,
     170,     1,   170,    51,   177,   177,   106,   218,    19,     1,
     110,   117,   170,   186,   186,   158,   159,   117,   170,   162,
     163,   117,   117,   208,   220,   125,   126,   127,     1,    77,
       3,   219,     5,   219,    34,    35,   136,   207,   205,   207,
      51,   208,   539,    43,   220,   219,    19,   219,    48,    49,
      50,   219,   195,   196,     1,   155,   219,   218,   205,   202,
     203,   219,   219,   219,   208,     1,    77,   218,   211,   219,
     213,    71,    72,    73,    74,   219,   219,   117,    51,   179,
     217,   220,   220,   218,   220,   133,    86,    87,    88,    36,
     185,   220,    39,    66,   220,    68,    96,    97,    98,   205,
     100,   101,   208,     1,    77,     1,   117,   220,   220,   205,
     205,   220,   160,   219,   218,   220,    89,    53,   220,   219,
      67,    19,   133,   219,   219,   117,   220,   624,   220,    20,
     627,    78,   629,     1,   220,   220,   220,   634,   219,   216,
     220,   220,   220,    39,   117,   185,    37,   139,   220,   220,
     220,    47,   220,    51,   220,   652,    92,   104,   220,   220,
     208,   108,   220,   220,   137,   205,   220,   220,    59,   116,
     117,   219,   218,   120,   121,   220,   220,   188,   220,    77,
     223,   154,   220,   220,   220,   220,   220,   220,   199,   220,
     201,   220,   165,   220,   220,   220,   220,   208,    66,   220,
       1,   212,   220,   139,   220,   220,   220,    75,   219,    77,
     147,   148,   149,   150,   151,   152,   153,   220,    19,   219,
     216,   117,   220,   220,   197,   220,   199,   220,     1,   220,
     220,   220,   220,   220,     1,   133,   220,   220,   220,     6,
       7,   220,     9,    10,   220,   220,   219,    14,   220,   220,
      51,   198,   220,   200,    21,    22,    23,    24,    25,    26,
     220,   220,   160,   220,    31,    32,    33,   220,   220,   137,
     220,    44,   219,   170,    41,    42,    77,   220,    45,    46,
     217,    54,    55,    56,     4,   220,    59,    60,   220,   220,
     181,    64,    65,   220,   220,   220,   187,   220,   220,   220,
     220,   220,    69,    70,   220,   220,    15,    27,    28,   220,
     208,     1,   220,   216,    81,  1140,   117,    84,    85,   194,
      40,   194,   217,   217,   194,   194,   218,    94,    95,   217,
     217,   217,   133,   217,   217,   102,   103,   217,   105,   217,
     107,   218,   218,    52,   111,   112,    36,   218,   220,    39,
     142,   194,   216,   220,   220,   220,   123,   220,   220,    79,
      80,   128,    82,   130,   131,   132,   220,     1,   135,     3,
     220,     5,   220,   140,    83,   220,   220,    67,   809,   810,
     811,   812,   813,   814,   815,    19,   220,   188,    78,   109,
     220,   158,   159,   113,   220,   162,   163,   220,   199,   220,
     201,   220,   122,   220,   220,   220,   220,   208,   220,   118,
     119,   212,   220,   220,   104,   124,   220,    51,   108,   194,
     220,   141,   220,   143,   220,   145,   116,   117,   195,   196,
     120,   121,    66,   220,    68,   202,   203,   146,   220,   220,
     217,   161,   216,    77,   211,   217,   213,   217,   217,   169,
     216,   171,   194,   217,   174,    89,   176,     1,   194,   194,
     180,     0,     1,   183,   217,     4,   217,   194,   217,   189,
     217,   191,   192,    17,    18,   194,   217,    16,   217,    80,
      19,    82,   216,   117,   193,    29,   206,   217,   217,    28,
     194,   217,   217,   217,   214,   194,   194,   194,   194,    38,
     217,   217,   194,   137,   217,   220,   215,   218,   198,   221,
     200,   218,   220,   204,    53,   220,    82,   220,    57,    58,
     154,   222,    82,    93,   501,   220,   220,   220,   129,   218,
     217,   165,   220,    77,   220,   220,   218,    76,   194,   220,
     220,    80,   218,   220,   145,   220,   220,   220,   220,   220,
     220,    90,    91,   220,    98,    99,   220,   218,   220,   194,
     220,   220,   106,   197,   216,   199,   110,   168,   169,   194,
     216,   194,   194,   117,   218,   114,   115,   216,   194,   145,
     216,   125,   126,   127,   217,   145,   217,   216,   216,   216,
     129,   194,   136,   735,   218,   216,   216,   216,   164,   194,
     218,   218,   216,   169,   164,   220,   145,   208,   174,   169,
     218,   155,   218,   214,   174,   220,     1,   156,   157,   216,
     220,   220,   220,   189,   218,   191,   192,   220,   167,   189,
     220,   191,   192,   218,   218,   179,   175,   218,   218,   178,
     206,   218,   218,   182,   218,   184,   206,   218,   214,    34,
      35,   218,   220,   218,   214,   218,   218,   218,    43,   218,
     218,   218,   218,    48,    49,    50,   218,   218,   218,   218,
     217,   217,   217,   221,   217,   217,   217,   217,   579,   217,
     216,   218,   216,   216,   216,   220,    71,    72,    73,    74,
     216,   216,   194,   217,   216,   216,   216,   220,   216,   218,
     216,    86,    87,    88,   218,   218,   216,   216,   220,   216,
     218,    96,    97,    98,   218,   100,   101,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   216,   216,   216,   194,   216,   218,
     216,   218,   216,   216,   194,   217,   216,   218,   216,   218,
     216,   216,   216,   220,   216,   216,   216,   216,    80,   222,
     218,   216,   216,   216,   220,   987,   218,   218,   516,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   216,   218,
     216,   218,   216,   216,   216,   220,  1163,   218,   218,   216,
     216,   220,   220,   344,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   217,   145,
     218,   221,   142,   216,   221,   221,   221,   221,   220,   218,
     145,   142,   142,   218,   218,   218,   218,  1184,  1172,   532,
    1082,  1170,  1193,   487,   592,   565,  1186,  1168,   129,   182,
     104,   376,    -1,    -1,    -1,   466,    -1,    -1,    -1,    -1,
      -1,   395,    -1,   250,    -1,    -1,    -1,   477,    -1,    -1,
      -1,    -1,   405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     298
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   225,     0,     1,     4,    16,    19,    28,    38,    53,
      57,    58,    76,    80,    90,    91,   114,   115,   129,   145,
     156,   157,   167,   175,   178,   182,   184,   226,   231,   232,
     236,   251,   257,   263,   271,   284,   301,   323,   337,   350,
     357,   361,   371,   380,   401,   407,   413,   417,   423,   474,
     495,   218,   219,   223,   223,   302,   381,   408,   223,   418,
     223,   338,   402,   324,   216,   220,   258,   285,   351,   223,
     223,   372,   223,   264,   223,   362,     1,    39,    47,   117,
     252,   253,   254,   255,   256,     1,    34,    35,    43,    48,
      49,    50,    71,    72,    73,    74,    86,    87,    88,    96,
      97,    98,   100,   101,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   223,   223,   223,     1,    75,   414,
     415,   416,   223,     1,     6,     7,     9,    10,    14,    21,
      22,    23,    24,    25,    26,    31,    32,    33,    41,    42,
      45,    46,    69,    70,    81,    84,    85,    94,    95,   102,
     103,   105,   107,   111,   112,   123,   128,   130,   131,   132,
     135,   140,   158,   159,   162,   163,   195,   196,   202,   203,
     211,   213,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   223,   223,   223,   221,   233,   216,   223,   223,
     223,     1,    44,    54,    55,    56,    59,    60,    64,    65,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
       1,    36,    39,    67,    78,   104,   108,   116,   117,   120,
     121,   198,   200,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   223,     1,   207,
     272,   273,   274,   275,   276,   223,     1,   117,   358,   359,
     360,   223,   218,   220,   220,   220,   219,   253,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   219,   476,     1,    17,
      18,    29,    77,    98,    99,   106,   110,   117,   125,   126,
     127,   136,   155,   179,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,     1,     3,     5,    19,    51,    66,    68,    77,    89,
     117,   137,   154,   165,   197,   199,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   397,   398,
     399,   400,     1,    75,   139,   409,   410,   411,   412,   220,
     219,   415,     1,   117,   139,   419,   420,   421,   422,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   219,   425,     1,
      19,    51,    77,   133,   160,   208,   339,   340,   341,   342,
     343,   344,   345,   349,     1,   139,   208,   403,   404,   405,
     406,     1,    66,    75,    77,   137,   325,   329,   330,   331,
     335,   336,    30,   144,   234,   235,   218,   218,     1,    92,
     170,   259,   260,   261,   262,     1,    19,    51,    77,   117,
     133,   188,   199,   201,   208,   212,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,     1,    53,
      92,   139,   352,   353,   354,   355,   356,   220,   220,   220,
     220,   220,   220,   220,   220,   219,   497,   218,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     219,   238,     1,   117,   205,   373,   374,   375,   376,   218,
     220,   219,   273,   170,     1,   117,   166,   177,   186,   265,
     266,   267,   268,   269,   270,   220,   219,   359,     1,   117,
     205,   208,   363,   364,   365,   366,   367,   216,   216,   216,
     218,   217,   217,   228,   194,   194,   194,   194,   217,   228,
     228,   228,   217,   228,   228,   217,   217,   217,   217,   217,
     218,   218,   220,   220,   220,   320,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   219,   304,   218,
     220,   220,   220,   220,   220,   220,   394,   220,   220,   220,
     220,   220,   220,   220,   219,   383,   220,   220,   219,   410,
     216,   218,   220,   220,   219,   420,   194,   228,   217,   228,
     228,   194,   217,   217,   217,   216,   216,   194,   217,   228,
     194,   194,   217,   217,   228,   194,   228,   217,   217,   217,
     217,   217,   217,   228,   217,   217,   217,   194,   216,   194,
     228,   228,   194,   228,   194,   217,   194,   194,   217,   228,
     228,   228,   194,   217,   218,   218,   220,   220,   346,   220,
     220,   220,   219,   340,   220,   220,   219,   404,   218,   220,
     220,   326,   220,   219,   330,   222,   218,   220,   220,   219,
     260,   218,   220,   220,   298,   220,   220,   220,   220,   220,
     220,   220,   219,   287,   218,   220,   220,   220,   219,   353,
     194,   194,   228,   216,   194,   216,   194,   194,   218,   217,
     216,   194,   216,   217,   217,   216,   216,   216,   216,   216,
     216,   218,   218,   220,   377,   219,   374,   194,   218,   223,
     218,   220,   220,   220,   220,   219,   266,   216,   218,   218,
     220,   368,   220,   219,   364,   218,   218,   218,   218,   147,
     148,   149,   150,   151,   152,   153,   227,   228,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   217,   217,   228,   220,   217,
     228,   217,   228,   216,   217,   217,   217,   228,   217,   230,
     230,   218,   216,   172,   173,   216,   194,   216,   216,   220,
     216,   216,   217,   216,   216,   228,   216,   218,   216,   216,
     218,   218,   216,   216,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   216,   194,   220,   216,   216,   216,   218,
     216,   216,   218,   216,   216,   220,   217,   333,   334,   218,
     235,   216,   216,   218,   216,   194,   220,   216,   216,   216,
     216,   194,   216,   216,   218,   216,   216,   216,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   216,
     220,   218,   218,     1,   117,   185,   205,   277,   278,   279,
     280,   281,   216,   216,   216,   216,   218,   218,   216,   220,
     216,   218,   227,   227,   227,   227,   227,   227,   227,   218,
     218,   218,    63,   138,   321,   322,   218,   218,   218,   218,
     218,   218,   218,   218,   218,    11,    12,    13,   229,   230,
     218,   218,   218,   218,   218,   218,   218,   218,   218,     8,
     187,   395,   396,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,    15,    52,    83,   118,
     119,   124,   146,   193,   215,   347,   348,   218,   218,   218,
     218,   218,   218,   218,    20,    37,    59,   181,   187,   327,
     328,   204,   222,   332,   218,   218,   218,   218,     4,    27,
      28,    40,    79,    80,    82,   109,   113,   122,   141,   143,
     145,   161,   169,   171,   174,   176,   180,   183,   189,   191,
     192,   206,   214,   299,   300,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,    82,   145,   164,   169,
     174,   189,   191,   192,   206,   214,   378,   379,   218,   220,
     220,   282,   219,   278,   218,   218,   218,   218,   218,    82,
     145,   164,   169,   174,   189,   191,   192,   206,   214,   369,
     370,   218,   218,   222,   229,   229,   229,   218,   222,   218,
     222,   218,   222,   217,   334,   218,   221,   221,   221,   221,
     221,   221,   221,   218,   222,   218,   222,   216,   190,   230,
     220,   218,   218,   222,   322,   396,   348,   328,   142,   145,
     142,    93,   145,   142,   142,   300,   379,   218,   218,   218,
      80,    82,   129,   145,   168,   169,   208,   214,   283,   370,
     218
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   224,   225,   225,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   227,
     227,   228,   228,   228,   228,   228,   228,   228,   228,   229,
     229,   230,   230,   230,   230,   231,   232,   233,   233,   234,
     234,   235,   235,   236,   237,   237,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   252,   253,   253,   253,   253,   254,   255,
     256,   258,   257,   259,   259,   260,   260,   260,   261,   262,
     264,   263,   265,   265,   266,   266,   266,   266,   266,   267,
     268,   269,   270,   271,   272,   272,   273,   273,   273,   274,
     276,   275,   277,   277,   278,   278,   278,   278,   279,   280,
     280,   282,   281,   283,   283,   283,   283,   283,   283,   283,
     283,   285,   284,   286,   286,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   298,   297,   299,   299,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   302,   301,
     303,   303,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   320,   319,   321,   321,   322,   322,   324,   323,
     326,   325,   327,   327,   328,   328,   328,   328,   328,   329,
     329,   330,   330,   330,   330,   330,   332,   331,   333,   333,
     334,   334,   335,   336,   338,   337,   339,   339,   340,   340,
     340,   340,   340,   340,   340,   341,   342,   343,   344,   346,
     345,   347,   347,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   349,   351,   350,   352,   352,   353,   353,   353,
     353,   354,   355,   356,   357,   358,   358,   359,   359,   360,
     362,   361,   363,   363,   364,   364,   364,   364,   365,   366,
     368,   367,   369,   369,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   372,   371,   373,   373,   374,   374,
     374,   375,   377,   376,   378,   378,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   381,   380,   382,   382,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   392,   394,   393,   395,   395,   396,
     396,   397,   398,   399,   400,   402,   401,   403,   403,   404,
     404,   404,   405,   406,   408,   407,   409,   409,   410,   410,
     410,   411,   412,   413,   414,   414,   415,   415,   416,   418,
     417,   419,   419,   420,   420,   420,   421,   422,   423,   424,
     424,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     475,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     496,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     498,   499,   500,   501,   502,   503,   504,   505
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
#line 384 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3414 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 385 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3420 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 386 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3426 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 387 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3432 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 388 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3438 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 389 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3444 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 390 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3450 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 391 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3456 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 392 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3462 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 395 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3468 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 396 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3474 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 397 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3480 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 398 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3486 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3492 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' QSTRING ';'  */
#line 407 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_set_base_path(yylval.string);
}
#line 3501 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE QSTRING module_attributes ';'  */
#line 417 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    module_config_add((yyvsp[-2].string), block_state.attributes.value & MODULE_RESIDENT, block_state.attributes.value & MODULE_CORE);
}
#line 3510 "conf_parser.c"
    break;

  case 47: /* module_attributes: %empty  */
#line 423 "conf_parser.y"
{
  block_state.attributes.value = 0;
}
#line 3518 "conf_parser.c"
    break;

  case 51: /* module_attributes_item: RESIDENT  */
#line 430 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_RESIDENT;
}
#line 3527 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: CORE  */
#line 434 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.attributes.value |= MODULE_CORE;
}
#line 3536 "conf_parser.c"
    break;

  case 69: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 462 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3548 "conf_parser.c"
    break;

  case 70: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 471 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3560 "conf_parser.c"
    break;

  case 71: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 480 "conf_parser.y"
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
#line 3578 "conf_parser.c"
    break;

  case 72: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 495 "conf_parser.y"
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
#line 3596 "conf_parser.c"
    break;

  case 73: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 510 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3609 "conf_parser.c"
    break;

  case 74: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 520 "conf_parser.y"
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
#line 3626 "conf_parser.c"
    break;

  case 75: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 534 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3638 "conf_parser.c"
    break;

  case 76: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 543 "conf_parser.y"
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
#line 3664 "conf_parser.c"
    break;

  case 77: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 566 "conf_parser.y"
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
#line 3690 "conf_parser.c"
    break;

  case 78: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 589 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigServerInfo.max_topic_length = TOPICLEN;
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3701 "conf_parser.c"
    break;

  case 79: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 597 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3713 "conf_parser.c"
    break;

  case 80: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 606 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3722 "conf_parser.c"
    break;

  case 88: /* admin_name: NAME '=' QSTRING ';'  */
#line 624 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3734 "conf_parser.c"
    break;

  case 89: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 633 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3746 "conf_parser.c"
    break;

  case 90: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 642 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3758 "conf_parser.c"
    break;

  case 91: /* $@1: %empty  */
#line 655 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3767 "conf_parser.c"
    break;

  case 92: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 659 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3784 "conf_parser.c"
    break;

  case 98: /* motd_mask: MASK '=' QSTRING ';'  */
#line 676 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3793 "conf_parser.c"
    break;

  case 99: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 682 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3802 "conf_parser.c"
    break;

  case 100: /* $@2: %empty  */
#line 692 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3811 "conf_parser.c"
    break;

  case 101: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 696 "conf_parser.y"
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
#line 3829 "conf_parser.c"
    break;

  case 109: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 714 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3838 "conf_parser.c"
    break;

  case 110: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 720 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3847 "conf_parser.c"
    break;

  case 111: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 726 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3856 "conf_parser.c"
    break;

  case 112: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 732 "conf_parser.y"
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
#line 3878 "conf_parser.c"
    break;

  case 119: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 761 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 3890 "conf_parser.c"
    break;

  case 120: /* $@3: %empty  */
#line 770 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3899 "conf_parser.c"
    break;

  case 121: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 774 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3912 "conf_parser.c"
    break;

  case 128: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 790 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3923 "conf_parser.c"
    break;

  case 129: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 798 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3931 "conf_parser.c"
    break;

  case 130: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 801 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3939 "conf_parser.c"
    break;

  case 131: /* $@4: %empty  */
#line 806 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3948 "conf_parser.c"
    break;

  case 133: /* logging_file_type_item: USER  */
#line 812 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3957 "conf_parser.c"
    break;

  case 134: /* logging_file_type_item: OPERATOR  */
#line 816 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3966 "conf_parser.c"
    break;

  case 135: /* logging_file_type_item: XLINE  */
#line 820 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3975 "conf_parser.c"
    break;

  case 136: /* logging_file_type_item: RESV  */
#line 824 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3984 "conf_parser.c"
    break;

  case 137: /* logging_file_type_item: T_DLINE  */
#line 828 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3993 "conf_parser.c"
    break;

  case 138: /* logging_file_type_item: KLINE  */
#line 832 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4002 "conf_parser.c"
    break;

  case 139: /* logging_file_type_item: KILL  */
#line 836 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4011 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: T_DEBUG  */
#line 840 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4020 "conf_parser.c"
    break;

  case 141: /* $@5: %empty  */
#line 850 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4032 "conf_parser.c"
    break;

  case 142: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 857 "conf_parser.y"
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
#line 4090 "conf_parser.c"
    break;

  case 156: /* oper_name: NAME '=' QSTRING ';'  */
#line 925 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4099 "conf_parser.c"
    break;

  case 157: /* oper_user: USER '=' QSTRING ';'  */
#line 931 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4108 "conf_parser.c"
    break;

  case 158: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 937 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4117 "conf_parser.c"
    break;

  case 159: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 943 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4126 "conf_parser.c"
    break;

  case 160: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 949 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4140 "conf_parser.c"
    break;

  case 161: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 960 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4149 "conf_parser.c"
    break;

  case 162: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 966 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4163 "conf_parser.c"
    break;

  case 163: /* oper_class: CLASS '=' QSTRING ';'  */
#line 977 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4172 "conf_parser.c"
    break;

  case 164: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 983 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4181 "conf_parser.c"
    break;

  case 165: /* $@6: %empty  */
#line 989 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4190 "conf_parser.c"
    break;

  case 169: /* oper_flags_item: KILL ':' REMOTE  */
#line 996 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4199 "conf_parser.c"
    break;

  case 170: /* oper_flags_item: KILL  */
#line 1000 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4208 "conf_parser.c"
    break;

  case 171: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1004 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4217 "conf_parser.c"
    break;

  case 172: /* oper_flags_item: CONNECT  */
#line 1008 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4226 "conf_parser.c"
    break;

  case 173: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1012 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4235 "conf_parser.c"
    break;

  case 174: /* oper_flags_item: SQUIT  */
#line 1016 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4244 "conf_parser.c"
    break;

  case 175: /* oper_flags_item: KLINE  */
#line 1020 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4253 "conf_parser.c"
    break;

  case 176: /* oper_flags_item: UNKLINE  */
#line 1024 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4262 "conf_parser.c"
    break;

  case 177: /* oper_flags_item: T_DLINE  */
#line 1028 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4271 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: T_UNDLINE  */
#line 1032 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4280 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: XLINE  */
#line 1036 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4289 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: T_UNXLINE  */
#line 1040 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4298 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: DIE  */
#line 1044 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4307 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: T_RESTART  */
#line 1048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4316 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1052 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4325 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: REHASH  */
#line 1056 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4334 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: ADMIN  */
#line 1060 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4343 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_GLOBOPS  */
#line 1064 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4352 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_LOCOPS  */
#line 1068 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4361 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: REMOTEBAN  */
#line 1072 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4370 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_SET  */
#line 1076 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4379 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: MODULE  */
#line 1080 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4388 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_OPME  */
#line 1084 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4397 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: NICK ':' RESV  */
#line 1088 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4406 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: JOIN ':' RESV  */
#line 1092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4415 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: RESV  */
#line 1096 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4424 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_UNRESV  */
#line 1100 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4433 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: CLOSE  */
#line 1104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4442 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4451 "conf_parser.c"
    break;

  case 198: /* $@7: %empty  */
#line 1118 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.con_freq.value  = CLASS_DEFAULT_CONNECT_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4467 "conf_parser.c"
    break;

  case 199: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1129 "conf_parser.y"
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
#line 4515 "conf_parser.c"
    break;

  case 218: /* class_name: NAME '=' QSTRING ';'  */
#line 1192 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4524 "conf_parser.c"
    break;

  case 219: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1198 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4533 "conf_parser.c"
    break;

  case 220: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1204 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4542 "conf_parser.c"
    break;

  case 221: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1210 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4551 "conf_parser.c"
    break;

  case 222: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1216 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4560 "conf_parser.c"
    break;

  case 223: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1222 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4569 "conf_parser.c"
    break;

  case 224: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1228 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4578 "conf_parser.c"
    break;

  case 225: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1234 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4587 "conf_parser.c"
    break;

  case 226: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1240 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4597 "conf_parser.c"
    break;

  case 227: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1247 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4606 "conf_parser.c"
    break;

  case 228: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1253 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4615 "conf_parser.c"
    break;

  case 229: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1259 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4624 "conf_parser.c"
    break;

  case 230: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1265 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4636 "conf_parser.c"
    break;

  case 231: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1274 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4648 "conf_parser.c"
    break;

  case 232: /* $@8: %empty  */
#line 1283 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4657 "conf_parser.c"
    break;

  case 236: /* class_flags_item: RANDOM_IDLE  */
#line 1290 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4666 "conf_parser.c"
    break;

  case 237: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1294 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4675 "conf_parser.c"
    break;

  case 238: /* $@9: %empty  */
#line 1304 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4684 "conf_parser.c"
    break;

  case 240: /* $@10: %empty  */
#line 1310 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4692 "conf_parser.c"
    break;

  case 244: /* listen_flags_item: T_TLS  */
#line 1316 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4701 "conf_parser.c"
    break;

  case 245: /* listen_flags_item: HIDDEN  */
#line 1320 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4710 "conf_parser.c"
    break;

  case 246: /* listen_flags_item: T_SERVER  */
#line 1324 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4719 "conf_parser.c"
    break;

  case 247: /* listen_flags_item: CLIENT  */
#line 1328 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4728 "conf_parser.c"
    break;

  case 248: /* listen_flags_item: DEFER  */
#line 1332 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4737 "conf_parser.c"
    break;

  case 256: /* $@11: %empty  */
#line 1340 "conf_parser.y"
                                 { reset_block_state(); }
#line 4743 "conf_parser.c"
    break;

  case 260: /* port_item: NUMBER  */
#line 1345 "conf_parser.y"
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
#line 4761 "conf_parser.c"
    break;

  case 261: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1358 "conf_parser.y"
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
#line 4781 "conf_parser.c"
    break;

  case 262: /* listen_address: IP '=' QSTRING ';'  */
#line 1375 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4790 "conf_parser.c"
    break;

  case 263: /* listen_host: HOST '=' QSTRING ';'  */
#line 1381 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4799 "conf_parser.c"
    break;

  case 264: /* $@12: %empty  */
#line 1391 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4808 "conf_parser.c"
    break;

  case 265: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1395 "conf_parser.y"
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
#line 4863 "conf_parser.c"
    break;

  case 275: /* auth_user: USER '=' QSTRING ';'  */
#line 1456 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4872 "conf_parser.c"
    break;

  case 276: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1462 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4881 "conf_parser.c"
    break;

  case 277: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1468 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4890 "conf_parser.c"
    break;

  case 278: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1474 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 4904 "conf_parser.c"
    break;

  case 279: /* $@13: %empty  */
#line 1485 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 4913 "conf_parser.c"
    break;

  case 283: /* auth_flags_item: EXCEED_LIMIT  */
#line 1493 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 4922 "conf_parser.c"
    break;

  case 284: /* auth_flags_item: KLINE_EXEMPT  */
#line 1497 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 4931 "conf_parser.c"
    break;

  case 285: /* auth_flags_item: XLINE_EXEMPT  */
#line 1501 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 4940 "conf_parser.c"
    break;

  case 286: /* auth_flags_item: NEED_IDENT  */
#line 1505 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 4949 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: CAN_FLOOD  */
#line 1509 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 4958 "conf_parser.c"
    break;

  case 288: /* auth_flags_item: NO_TILDE  */
#line 1513 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 4967 "conf_parser.c"
    break;

  case 289: /* auth_flags_item: RESV_EXEMPT  */
#line 1517 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 4976 "conf_parser.c"
    break;

  case 290: /* auth_flags_item: T_WEBIRC  */
#line 1521 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 4985 "conf_parser.c"
    break;

  case 291: /* auth_flags_item: NEED_PASSWORD  */
#line 1525 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 4994 "conf_parser.c"
    break;

  case 292: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1531 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    log_write(LOG_TYPE_IRCD,
              "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 5009 "conf_parser.c"
    break;

  case 293: /* $@14: %empty  */
#line 1546 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5021 "conf_parser.c"
    break;

  case 294: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1553 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5032 "conf_parser.c"
    break;

  case 301: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1564 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5041 "conf_parser.c"
    break;

  case 302: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1570 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5050 "conf_parser.c"
    break;

  case 303: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1576 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5059 "conf_parser.c"
    break;

  case 309: /* service_name: NAME '=' QSTRING ';'  */
#line 1591 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5074 "conf_parser.c"
    break;

  case 310: /* $@15: %empty  */
#line 1607 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5090 "conf_parser.c"
    break;

  case 311: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1618 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5105 "conf_parser.c"
    break;

  case 318: /* shared_name: NAME '=' QSTRING ';'  */
#line 1633 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5114 "conf_parser.c"
    break;

  case 319: /* shared_user: USER '=' QSTRING ';'  */
#line 1639 "conf_parser.y"
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
#line 5136 "conf_parser.c"
    break;

  case 320: /* $@16: %empty  */
#line 1658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5145 "conf_parser.c"
    break;

  case 324: /* shared_type_item: KLINE  */
#line 1665 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5154 "conf_parser.c"
    break;

  case 325: /* shared_type_item: UNKLINE  */
#line 1669 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5163 "conf_parser.c"
    break;

  case 326: /* shared_type_item: T_DLINE  */
#line 1673 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5172 "conf_parser.c"
    break;

  case 327: /* shared_type_item: T_UNDLINE  */
#line 1677 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5181 "conf_parser.c"
    break;

  case 328: /* shared_type_item: XLINE  */
#line 1681 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5190 "conf_parser.c"
    break;

  case 329: /* shared_type_item: T_UNXLINE  */
#line 1685 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5199 "conf_parser.c"
    break;

  case 330: /* shared_type_item: RESV  */
#line 1689 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5208 "conf_parser.c"
    break;

  case 331: /* shared_type_item: T_UNRESV  */
#line 1693 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5217 "conf_parser.c"
    break;

  case 332: /* shared_type_item: T_LOCOPS  */
#line 1697 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5226 "conf_parser.c"
    break;

  case 333: /* shared_type_item: T_ALL  */
#line 1701 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5235 "conf_parser.c"
    break;

  case 334: /* $@17: %empty  */
#line 1711 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5249 "conf_parser.c"
    break;

  case 335: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1720 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5262 "conf_parser.c"
    break;

  case 341: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1733 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5271 "conf_parser.c"
    break;

  case 342: /* $@18: %empty  */
#line 1739 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5280 "conf_parser.c"
    break;

  case 346: /* cluster_type_item: KLINE  */
#line 1746 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5289 "conf_parser.c"
    break;

  case 347: /* cluster_type_item: UNKLINE  */
#line 1750 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5298 "conf_parser.c"
    break;

  case 348: /* cluster_type_item: T_DLINE  */
#line 1754 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5307 "conf_parser.c"
    break;

  case 349: /* cluster_type_item: T_UNDLINE  */
#line 1758 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5316 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: XLINE  */
#line 1762 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5325 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: T_UNXLINE  */
#line 1766 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5334 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: RESV  */
#line 1770 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5343 "conf_parser.c"
    break;

  case 353: /* cluster_type_item: T_UNRESV  */
#line 1774 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5352 "conf_parser.c"
    break;

  case 354: /* cluster_type_item: T_LOCOPS  */
#line 1778 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5361 "conf_parser.c"
    break;

  case 355: /* cluster_type_item: T_ALL  */
#line 1782 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5370 "conf_parser.c"
    break;

  case 356: /* $@19: %empty  */
#line 1792 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5384 "conf_parser.c"
    break;

  case 357: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1801 "conf_parser.y"
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
#line 5432 "conf_parser.c"
    break;

  case 375: /* connect_name: NAME '=' QSTRING ';'  */
#line 1863 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5441 "conf_parser.c"
    break;

  case 376: /* connect_host: HOST '=' QSTRING ';'  */
#line 1869 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5450 "conf_parser.c"
    break;

  case 377: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1875 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5459 "conf_parser.c"
    break;

  case 378: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5468 "conf_parser.c"
    break;

  case 379: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1887 "conf_parser.y"
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
#line 5484 "conf_parser.c"
    break;

  case 380: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1900 "conf_parser.y"
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
#line 5500 "conf_parser.c"
    break;

  case 381: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1913 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5509 "conf_parser.c"
    break;

  case 382: /* connect_port: PORT '=' NUMBER ';'  */
#line 1919 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5518 "conf_parser.c"
    break;

  case 383: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 1925 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5527 "conf_parser.c"
    break;

  case 384: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 1929 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5536 "conf_parser.c"
    break;

  case 385: /* $@20: %empty  */
#line 1935 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5544 "conf_parser.c"
    break;

  case 389: /* connect_flags_item: AUTOCONN  */
#line 1941 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5553 "conf_parser.c"
    break;

  case 390: /* connect_flags_item: T_TLS  */
#line 1945 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5562 "conf_parser.c"
    break;

  case 391: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1951 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5576 "conf_parser.c"
    break;

  case 392: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 1962 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5585 "conf_parser.c"
    break;

  case 393: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 1968 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5594 "conf_parser.c"
    break;

  case 394: /* connect_class: CLASS '=' QSTRING ';'  */
#line 1974 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5603 "conf_parser.c"
    break;

  case 395: /* $@21: %empty  */
#line 1984 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5612 "conf_parser.c"
    break;

  case 396: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 1988 "conf_parser.y"
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
#line 5636 "conf_parser.c"
    break;

  case 402: /* kill_user: USER '=' QSTRING ';'  */
#line 2012 "conf_parser.y"
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
#line 5659 "conf_parser.c"
    break;

  case 403: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2032 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5668 "conf_parser.c"
    break;

  case 404: /* $@22: %empty  */
#line 2042 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5677 "conf_parser.c"
    break;

  case 405: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2046 "conf_parser.y"
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
#line 5699 "conf_parser.c"
    break;

  case 411: /* deny_ip: IP '=' QSTRING ';'  */
#line 2068 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5708 "conf_parser.c"
    break;

  case 412: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2074 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5717 "conf_parser.c"
    break;

  case 418: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2089 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_error_report("Unable to add D-line exemption");
}
#line 5729 "conf_parser.c"
    break;

  case 419: /* $@23: %empty  */
#line 2102 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5738 "conf_parser.c"
    break;

  case 420: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2106 "conf_parser.y"
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
#line 5758 "conf_parser.c"
    break;

  case 426: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2126 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5767 "conf_parser.c"
    break;

  case 427: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2132 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5776 "conf_parser.c"
    break;

  case 480: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2196 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5784 "conf_parser.c"
    break;

  case 481: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2201 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5792 "conf_parser.c"
    break;

  case 482: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2206 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5800 "conf_parser.c"
    break;

  case 483: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2211 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5808 "conf_parser.c"
    break;

  case 484: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2216 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5816 "conf_parser.c"
    break;

  case 485: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2221 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5824 "conf_parser.c"
    break;

  case 486: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2226 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5832 "conf_parser.c"
    break;

  case 487: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2231 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5840 "conf_parser.c"
    break;

  case 488: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2236 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5848 "conf_parser.c"
    break;

  case 489: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2241 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5856 "conf_parser.c"
    break;

  case 490: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2246 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5864 "conf_parser.c"
    break;

  case 491: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2251 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5872 "conf_parser.c"
    break;

  case 492: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2256 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5880 "conf_parser.c"
    break;

  case 493: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2261 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5888 "conf_parser.c"
    break;

  case 494: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2266 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 5899 "conf_parser.c"
    break;

  case 495: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2274 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5907 "conf_parser.c"
    break;

  case 496: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2279 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5915 "conf_parser.c"
    break;

  case 497: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2284 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5923 "conf_parser.c"
    break;

  case 498: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2289 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5931 "conf_parser.c"
    break;

  case 499: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2294 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5939 "conf_parser.c"
    break;

  case 500: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2299 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5947 "conf_parser.c"
    break;

  case 501: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2304 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5955 "conf_parser.c"
    break;

  case 502: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2309 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5963 "conf_parser.c"
    break;

  case 503: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2314 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5971 "conf_parser.c"
    break;

  case 504: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2319 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5979 "conf_parser.c"
    break;

  case 505: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2324 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5987 "conf_parser.c"
    break;

  case 506: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2329 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 5995 "conf_parser.c"
    break;

  case 507: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2334 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6003 "conf_parser.c"
    break;

  case 508: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2339 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6011 "conf_parser.c"
    break;

  case 509: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2344 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6019 "conf_parser.c"
    break;

  case 510: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2349 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6027 "conf_parser.c"
    break;

  case 511: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2354 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6035 "conf_parser.c"
    break;

  case 512: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2359 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6043 "conf_parser.c"
    break;

  case 513: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2364 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6051 "conf_parser.c"
    break;

  case 514: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2369 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6059 "conf_parser.c"
    break;

  case 515: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2374 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6071 "conf_parser.c"
    break;

  case 516: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2383 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6079 "conf_parser.c"
    break;

  case 517: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2388 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6087 "conf_parser.c"
    break;

  case 518: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2393 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6095 "conf_parser.c"
    break;

  case 519: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2398 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6103 "conf_parser.c"
    break;

  case 520: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2403 "conf_parser.y"
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
#line 6123 "conf_parser.c"
    break;

  case 521: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2420 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6134 "conf_parser.c"
    break;

  case 522: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2428 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6145 "conf_parser.c"
    break;

  case 523: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2436 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6156 "conf_parser.c"
    break;

  case 524: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2444 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6169 "conf_parser.c"
    break;

  case 525: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2454 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6182 "conf_parser.c"
    break;

  case 526: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2464 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6193 "conf_parser.c"
    break;

  case 527: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2472 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6201 "conf_parser.c"
    break;

  case 550: /* channel_enable_extbans: ENABLE_EXTBANS '=' TBOOL ';'  */
#line 2504 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6209 "conf_parser.c"
    break;

  case 551: /* channel_enable_owner: ENABLE_OWNER '=' TBOOL ';'  */
#line 2509 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6218 "conf_parser.c"
    break;

  case 552: /* channel_enable_admin: ENABLE_ADMIN '=' TBOOL ';'  */
#line 2515 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6227 "conf_parser.c"
    break;

  case 553: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2521 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6235 "conf_parser.c"
    break;

  case 554: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2526 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6243 "conf_parser.c"
    break;

  case 555: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2531 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6251 "conf_parser.c"
    break;

  case 556: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2536 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6259 "conf_parser.c"
    break;

  case 557: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2541 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6267 "conf_parser.c"
    break;

  case 558: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2546 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6275 "conf_parser.c"
    break;

  case 559: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2551 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6283 "conf_parser.c"
    break;

  case 560: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2556 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6291 "conf_parser.c"
    break;

  case 561: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2561 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6299 "conf_parser.c"
    break;

  case 562: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2566 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6307 "conf_parser.c"
    break;

  case 563: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2571 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6315 "conf_parser.c"
    break;

  case 564: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2576 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6323 "conf_parser.c"
    break;

  case 565: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2581 "conf_parser.y"
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
#line 6349 "conf_parser.c"
    break;

  case 566: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2604 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6357 "conf_parser.c"
    break;

  case 567: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2609 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6365 "conf_parser.c"
    break;

  case 580: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2631 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6374 "conf_parser.c"
    break;

  case 581: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2637 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6388 "conf_parser.c"
    break;

  case 582: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2648 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6400 "conf_parser.c"
    break;

  case 583: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2657 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6409 "conf_parser.c"
    break;

  case 584: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2663 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6418 "conf_parser.c"
    break;

  case 585: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2669 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6427 "conf_parser.c"
    break;

  case 586: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2675 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6439 "conf_parser.c"
    break;

  case 587: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2684 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6448 "conf_parser.c"
    break;


#line 6452 "conf_parser.c"

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

