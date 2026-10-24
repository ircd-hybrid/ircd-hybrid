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
#include "ircd_module.h"
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
    CYCLE_ON_HOST_CHANGE = 285,    /* CYCLE_ON_HOST_CHANGE  */
    DEFAULT_FLOODCOUNT = 286,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 287,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 288, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 289, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 290,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 291,                   /* DEFER  */
    DENY = 292,                    /* DENY  */
    DESCRIPTION = 293,             /* DESCRIPTION  */
    DIE = 294,                     /* DIE  */
    DISABLE_DNS = 295,             /* DISABLE_DNS  */
    DISABLE_IDENT = 296,           /* DISABLE_IDENT  */
    DISABLE_FAKE_CHANNELS = 297,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 298, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 299,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 300,         /* DLINE_MIN_CIDR6  */
    EMAIL = 301,                   /* EMAIL  */
    ENCRYPTED = 302,               /* ENCRYPTED  */
    EXCEED_LIMIT = 303,            /* EXCEED_LIMIT  */
    EXEMPT = 304,                  /* EXEMPT  */
    FLATTEN_LINKS = 305,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 306,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 307,      /* FLATTEN_LINKS_FILE  */
    GECOS = 308,                   /* GECOS  */
    GENERAL = 309,                 /* GENERAL  */
    HIDDEN = 310,                  /* HIDDEN  */
    HIDDEN_NAME = 311,             /* HIDDEN_NAME  */
    HIDE_CHANS = 312,              /* HIDE_CHANS  */
    HIDE_IDLE = 313,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 314,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVERS = 315,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 316,           /* HIDE_SERVICES  */
    HOST = 317,                    /* HOST  */
    HUB = 318,                     /* HUB  */
    HUB_MASK = 319,                /* HUB_MASK  */
    IDENT_TIMEOUT = 320,           /* IDENT_TIMEOUT  */
    INVISIBLE_ON_CONNECT = 321,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 322,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 323,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 324,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 325,      /* INVITE_EXPIRE_TIME  */
    IP = 326,                      /* IP  */
    IRCD_AUTH = 327,               /* IRCD_AUTH  */
    IRCD_FLAGS = 328,              /* IRCD_FLAGS  */
    IRCD_SID = 329,                /* IRCD_SID  */
    JOIN = 330,                    /* JOIN  */
    KILL = 331,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 332,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 333,                   /* KLINE  */
    KLINE_EXEMPT = 334,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 335,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 336,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 337,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 338,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 339,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 340,               /* LEAF_MASK  */
    LISTEN = 341,                  /* LISTEN  */
    LOADMODULE = 342,              /* LOADMODULE  */
    MASK = 343,                    /* MASK  */
    MASS = 344,                    /* MASS  */
    MAX_ACCEPT = 345,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 346,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 347,                /* MAX_BANS  */
    MAX_BANS_LARGE = 348,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 349,            /* MAX_CHANNELS  */
    MAX_IDLE = 350,                /* MAX_IDLE  */
    MAX_INVITES = 351,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 352,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 353,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 354,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 355,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 356,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 357,              /* MAX_NUMBER  */
    MAX_TARGETS = 358,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 359,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 360,                 /* MESSAGE  */
    MIN_IDLE = 361,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 362,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 363,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 364,                  /* MODULE  */
    MODULE_BASE_PATH = 365,        /* MODULE_BASE_PATH  */
    MOTD = 366,                    /* MOTD  */
    MOTD_FILE = 367,               /* MOTD_FILE  */
    NAME = 368,                    /* NAME  */
    NEED_IDENT = 369,              /* NEED_IDENT  */
    NEED_PASSWORD = 370,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 371,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 372,            /* NETWORK_NAME  */
    NICK = 373,                    /* NICK  */
    NO_OPER_FLOOD = 374,           /* NO_OPER_FLOOD  */
    NO_TILDE = 375,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 376,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 377,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 378,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 379,             /* OPER_UMODES  */
    OPERATOR = 380,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 381,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 382,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 383,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 384,                /* PASSWORD  */
    PATH = 385,                    /* PATH  */
    PING_COOKIE = 386,             /* PING_COOKIE  */
    PING_TIME = 387,               /* PING_TIME  */
    PORT = 388,                    /* PORT  */
    RANDOM_IDLE = 389,             /* RANDOM_IDLE  */
    REASON = 390,                  /* REASON  */
    REGISTRATION_TIMEOUT = 391,    /* REGISTRATION_TIMEOUT  */
    REHASH = 392,                  /* REHASH  */
    REMOTE = 393,                  /* REMOTE  */
    REMOTEBAN = 394,               /* REMOTEBAN  */
    REQUIRED = 395,                /* REQUIRED  */
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
#define CYCLE_ON_HOST_CHANGE 285
#define DEFAULT_FLOODCOUNT 286
#define DEFAULT_FLOODTIME 287
#define DEFAULT_JOIN_FLOOD_COUNT 288
#define DEFAULT_JOIN_FLOOD_TIME 289
#define DEFAULT_MAX_CLIENTS 290
#define DEFER 291
#define DENY 292
#define DESCRIPTION 293
#define DIE 294
#define DISABLE_DNS 295
#define DISABLE_IDENT 296
#define DISABLE_FAKE_CHANNELS 297
#define DISABLE_REMOTE_COMMANDS 298
#define DLINE_MIN_CIDR 299
#define DLINE_MIN_CIDR6 300
#define EMAIL 301
#define ENCRYPTED 302
#define EXCEED_LIMIT 303
#define EXEMPT 304
#define FLATTEN_LINKS 305
#define FLATTEN_LINKS_DELAY 306
#define FLATTEN_LINKS_FILE 307
#define GECOS 308
#define GENERAL 309
#define HIDDEN 310
#define HIDDEN_NAME 311
#define HIDE_CHANS 312
#define HIDE_IDLE 313
#define HIDE_IDLE_FROM_OPERS 314
#define HIDE_SERVERS 315
#define HIDE_SERVICES 316
#define HOST 317
#define HUB 318
#define HUB_MASK 319
#define IDENT_TIMEOUT 320
#define INVISIBLE_ON_CONNECT 321
#define INVITE_CLIENT_COUNT 322
#define INVITE_CLIENT_TIME 323
#define INVITE_DELAY_CHANNEL 324
#define INVITE_EXPIRE_TIME 325
#define IP 326
#define IRCD_AUTH 327
#define IRCD_FLAGS 328
#define IRCD_SID 329
#define JOIN 330
#define KILL 331
#define KILL_CHASE_TIME_LIMIT 332
#define KLINE 333
#define KLINE_EXEMPT 334
#define KLINE_MIN_CIDR 335
#define KLINE_MIN_CIDR6 336
#define KNOCK_CLIENT_COUNT 337
#define KNOCK_CLIENT_TIME 338
#define KNOCK_DELAY_CHANNEL 339
#define LEAF_MASK 340
#define LISTEN 341
#define LOADMODULE 342
#define MASK 343
#define MASS 344
#define MAX_ACCEPT 345
#define MAX_AWAY_LENGTH 346
#define MAX_BANS 347
#define MAX_BANS_LARGE 348
#define MAX_CHANNELS 349
#define MAX_IDLE 350
#define MAX_INVITES 351
#define MAX_KICK_LENGTH 352
#define MAX_MONITOR 353
#define MAX_NICK_CHANGES 354
#define MAX_NICK_LENGTH 355
#define MAX_NICK_TIME 356
#define MAX_NUMBER 357
#define MAX_TARGETS 358
#define MAX_TOPIC_LENGTH 359
#define MESSAGE 360
#define MIN_IDLE 361
#define MIN_NONWILDCARD 362
#define MIN_NONWILDCARD_SIMPLE 363
#define MODULE 364
#define MODULE_BASE_PATH 365
#define MOTD 366
#define MOTD_FILE 367
#define NAME 368
#define NEED_IDENT 369
#define NEED_PASSWORD 370
#define NETWORK_DESCRIPTION 371
#define NETWORK_NAME 372
#define NICK 373
#define NO_OPER_FLOOD 374
#define NO_TILDE 375
#define NUMBER_PER_CIDR 376
#define NUMBER_PER_IP_GLOBAL 377
#define NUMBER_PER_IP_LOCAL 378
#define OPER_UMODES 379
#define OPERATOR 380
#define OPERS_BYPASS_CALLERID 381
#define PACE_WAIT 382
#define PACE_WAIT_SIMPLE 383
#define PASSWORD 384
#define PATH 385
#define PING_COOKIE 386
#define PING_TIME 387
#define PORT 388
#define RANDOM_IDLE 389
#define REASON 390
#define REGISTRATION_TIMEOUT 391
#define REHASH 392
#define REMOTE 393
#define REMOTEBAN 394
#define REQUIRED 395
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
  YYSYMBOL_CYCLE_ON_HOST_CHANGE = 30,      /* CYCLE_ON_HOST_CHANGE  */
  YYSYMBOL_DEFAULT_FLOODCOUNT = 31,        /* DEFAULT_FLOODCOUNT  */
  YYSYMBOL_DEFAULT_FLOODTIME = 32,         /* DEFAULT_FLOODTIME  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_COUNT = 33,  /* DEFAULT_JOIN_FLOOD_COUNT  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_TIME = 34,   /* DEFAULT_JOIN_FLOOD_TIME  */
  YYSYMBOL_DEFAULT_MAX_CLIENTS = 35,       /* DEFAULT_MAX_CLIENTS  */
  YYSYMBOL_DEFER = 36,                     /* DEFER  */
  YYSYMBOL_DENY = 37,                      /* DENY  */
  YYSYMBOL_DESCRIPTION = 38,               /* DESCRIPTION  */
  YYSYMBOL_DIE = 39,                       /* DIE  */
  YYSYMBOL_DISABLE_DNS = 40,               /* DISABLE_DNS  */
  YYSYMBOL_DISABLE_IDENT = 41,             /* DISABLE_IDENT  */
  YYSYMBOL_DISABLE_FAKE_CHANNELS = 42,     /* DISABLE_FAKE_CHANNELS  */
  YYSYMBOL_DISABLE_REMOTE_COMMANDS = 43,   /* DISABLE_REMOTE_COMMANDS  */
  YYSYMBOL_DLINE_MIN_CIDR = 44,            /* DLINE_MIN_CIDR  */
  YYSYMBOL_DLINE_MIN_CIDR6 = 45,           /* DLINE_MIN_CIDR6  */
  YYSYMBOL_EMAIL = 46,                     /* EMAIL  */
  YYSYMBOL_ENCRYPTED = 47,                 /* ENCRYPTED  */
  YYSYMBOL_EXCEED_LIMIT = 48,              /* EXCEED_LIMIT  */
  YYSYMBOL_EXEMPT = 49,                    /* EXEMPT  */
  YYSYMBOL_FLATTEN_LINKS = 50,             /* FLATTEN_LINKS  */
  YYSYMBOL_FLATTEN_LINKS_DELAY = 51,       /* FLATTEN_LINKS_DELAY  */
  YYSYMBOL_FLATTEN_LINKS_FILE = 52,        /* FLATTEN_LINKS_FILE  */
  YYSYMBOL_GECOS = 53,                     /* GECOS  */
  YYSYMBOL_GENERAL = 54,                   /* GENERAL  */
  YYSYMBOL_HIDDEN = 55,                    /* HIDDEN  */
  YYSYMBOL_HIDDEN_NAME = 56,               /* HIDDEN_NAME  */
  YYSYMBOL_HIDE_CHANS = 57,                /* HIDE_CHANS  */
  YYSYMBOL_HIDE_IDLE = 58,                 /* HIDE_IDLE  */
  YYSYMBOL_HIDE_IDLE_FROM_OPERS = 59,      /* HIDE_IDLE_FROM_OPERS  */
  YYSYMBOL_HIDE_SERVERS = 60,              /* HIDE_SERVERS  */
  YYSYMBOL_HIDE_SERVICES = 61,             /* HIDE_SERVICES  */
  YYSYMBOL_HOST = 62,                      /* HOST  */
  YYSYMBOL_HUB = 63,                       /* HUB  */
  YYSYMBOL_HUB_MASK = 64,                  /* HUB_MASK  */
  YYSYMBOL_IDENT_TIMEOUT = 65,             /* IDENT_TIMEOUT  */
  YYSYMBOL_INVISIBLE_ON_CONNECT = 66,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 67,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 68,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 69,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 70,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 71,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 72,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 73,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 74,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 75,                      /* JOIN  */
  YYSYMBOL_KILL = 76,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 77,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 78,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 79,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 80,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 81,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 82,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 83,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 84,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 85,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 86,                    /* LISTEN  */
  YYSYMBOL_LOADMODULE = 87,                /* LOADMODULE  */
  YYSYMBOL_MASK = 88,                      /* MASK  */
  YYSYMBOL_MASS = 89,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 90,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_AWAY_LENGTH = 91,           /* MAX_AWAY_LENGTH  */
  YYSYMBOL_MAX_BANS = 92,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 93,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 94,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 95,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 96,               /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 97,           /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 98,               /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 99,          /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 100,          /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 101,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 102,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 103,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 104,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 105,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 106,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 107,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 108,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 109,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 110,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 111,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 112,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 113,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 114,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 115,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 116,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 117,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 118,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 119,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 120,                 /* NO_TILDE  */
  YYSYMBOL_NUMBER_PER_CIDR = 121,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 122,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 123,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_UMODES = 124,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 125,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 126,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 127,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 128,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 129,                 /* PASSWORD  */
  YYSYMBOL_PATH = 130,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 131,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 132,                /* PING_TIME  */
  YYSYMBOL_PORT = 133,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 134,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 135,                   /* REASON  */
  YYSYMBOL_REGISTRATION_TIMEOUT = 136,     /* REGISTRATION_TIMEOUT  */
  YYSYMBOL_REHASH = 137,                   /* REHASH  */
  YYSYMBOL_REMOTE = 138,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 139,                /* REMOTEBAN  */
  YYSYMBOL_REQUIRED = 140,                 /* REQUIRED  */
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
  YYSYMBOL_module_string = 230,            /* module_string  */
  YYSYMBOL_module_attributes = 231,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 232,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 233,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 234,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 235,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 236,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 237, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_tls_private_key_file = 238, /* serverinfo_tls_private_key_file  */
  YYSYMBOL_serverinfo_name = 239,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 240,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 241,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 242,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 243, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 244, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 245, /* serverinfo_max_nick_length  */
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
  YYSYMBOL_channel_max_topic_length = 487, /* channel_max_topic_length  */
  YYSYMBOL_channel_default_join_flood_count = 488, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 489, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 490,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 491,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 492,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 493, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 494, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 495, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 496, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 497,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 498, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 499,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 500         /* serverhide_hidden  */
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
#define YYLAST   1238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  221
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  280
/* YYNRULES -- Number of rules.  */
#define YYNRULES  582
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1207

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
       0,   352,   352,   353,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   384,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   395,
     395,   396,   397,   398,   399,   406,   424,   439,   445,   447,
     452,   455,   460,   463,   472,   474,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   489,
     498,   507,   522,   537,   547,   561,   570,   593,   616,   625,
     635,   637,   637,   638,   639,   640,   641,   643,   652,   661,
     675,   674,   692,   692,   693,   693,   693,   695,   701,   712,
     711,   730,   730,   731,   731,   731,   731,   731,   733,   739,
     745,   751,   774,   775,   775,   777,   777,   778,   780,   790,
     790,   803,   804,   806,   806,   807,   807,   809,   817,   820,
     826,   825,   831,   835,   839,   843,   847,   851,   855,   859,
     870,   869,   931,   931,   932,   933,   934,   935,   936,   937,
     938,   939,   940,   941,   942,   944,   950,   956,   962,   968,
     979,   985,   996,  1002,  1009,  1008,  1014,  1014,  1015,  1019,
    1023,  1027,  1031,  1035,  1039,  1043,  1047,  1051,  1055,  1059,
    1063,  1067,  1071,  1075,  1079,  1083,  1087,  1091,  1095,  1099,
    1103,  1107,  1111,  1115,  1119,  1123,  1127,  1138,  1137,  1193,
    1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,
    1203,  1204,  1205,  1206,  1207,  1208,  1209,  1211,  1217,  1223,
    1229,  1235,  1241,  1247,  1253,  1259,  1266,  1272,  1278,  1284,
    1293,  1303,  1302,  1308,  1308,  1309,  1313,  1324,  1323,  1330,
    1329,  1334,  1334,  1335,  1339,  1343,  1347,  1351,  1357,  1357,
    1358,  1358,  1358,  1358,  1358,  1360,  1360,  1362,  1362,  1364,
    1377,  1394,  1400,  1411,  1410,  1466,  1466,  1467,  1468,  1469,
    1470,  1471,  1472,  1473,  1475,  1481,  1487,  1493,  1505,  1504,
    1510,  1510,  1512,  1516,  1520,  1524,  1528,  1532,  1536,  1540,
    1544,  1550,  1566,  1565,  1580,  1580,  1581,  1581,  1581,  1581,
    1583,  1589,  1595,  1605,  1607,  1607,  1608,  1608,  1610,  1627,
    1626,  1649,  1649,  1650,  1650,  1650,  1650,  1652,  1658,  1678,
    1677,  1683,  1683,  1684,  1688,  1692,  1696,  1700,  1704,  1708,
    1712,  1716,  1720,  1731,  1730,  1749,  1749,  1750,  1750,  1750,
    1752,  1759,  1758,  1764,  1764,  1765,  1769,  1773,  1777,  1781,
    1785,  1789,  1793,  1797,  1801,  1812,  1811,  1865,  1865,  1866,
    1867,  1868,  1869,  1870,  1871,  1872,  1873,  1874,  1875,  1876,
    1877,  1878,  1879,  1880,  1882,  1888,  1894,  1900,  1906,  1919,
    1932,  1938,  1944,  1948,  1955,  1954,  1959,  1959,  1960,  1964,
    1970,  1981,  1987,  1993,  2004,  2003,  2028,  2028,  2029,  2029,
    2029,  2031,  2051,  2062,  2061,  2084,  2084,  2085,  2085,  2085,
    2087,  2093,  2103,  2105,  2105,  2106,  2106,  2108,  2122,  2121,
    2142,  2142,  2143,  2143,  2143,  2145,  2151,  2161,  2163,  2163,
    2164,  2165,  2166,  2167,  2168,  2169,  2170,  2171,  2172,  2173,
    2174,  2175,  2176,  2177,  2178,  2179,  2180,  2181,  2182,  2183,
    2184,  2185,  2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,
    2194,  2195,  2196,  2197,  2198,  2199,  2200,  2201,  2202,  2203,
    2204,  2205,  2206,  2207,  2208,  2209,  2210,  2211,  2212,  2215,
    2220,  2225,  2230,  2235,  2240,  2245,  2250,  2255,  2260,  2265,
    2270,  2275,  2280,  2285,  2293,  2298,  2303,  2308,  2313,  2318,
    2323,  2328,  2333,  2338,  2343,  2348,  2353,  2358,  2363,  2368,
    2373,  2378,  2383,  2388,  2393,  2402,  2407,  2412,  2417,  2422,
    2439,  2447,  2455,  2463,  2473,  2483,  2491,  2500,  2502,  2502,
    2503,  2504,  2505,  2506,  2507,  2508,  2509,  2510,  2511,  2512,
    2513,  2514,  2515,  2516,  2517,  2518,  2519,  2521,  2526,  2531,
    2536,  2541,  2546,  2551,  2556,  2561,  2566,  2571,  2576,  2581,
    2604,  2612,  2617,  2626,  2628,  2628,  2629,  2630,  2631,  2632,
    2633,  2634,  2635,  2636,  2637,  2639,  2645,  2656,  2665,  2671,
    2677,  2683,  2692
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
  "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME",
  "DEFAULT_JOIN_FLOOD_COUNT", "DEFAULT_JOIN_FLOOD_TIME",
  "DEFAULT_MAX_CLIENTS", "DEFER", "DENY", "DESCRIPTION", "DIE",
  "DISABLE_DNS", "DISABLE_IDENT", "DISABLE_FAKE_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6", "EMAIL",
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FLATTEN_LINKS",
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
  "REGISTRATION_TIMEOUT", "REHASH", "REMOTE", "REMOTEBAN", "REQUIRED",
  "RESIDENT", "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES", "HOURS", "DAYS",
  "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ", "SERVERHIDE",
  "SERVERINFO", "SHORT_MOTD", "SPECIALS_IN_IDENT", "SPOOF", "SQUIT",
  "STATS_E_DISABLED", "STATS_U_OPER_ONLY", "T_ALL", "T_BIND", "T_COMMAND",
  "T_CLUSTER", "T_DEBUG", "T_DLINE", "T_FILE", "T_GLOBOPS", "T_IPV4",
  "T_IPV6", "T_LOCOPS", "T_LOG", "T_OPME", "T_PREPEND", "T_PSEUDO",
  "T_RECVQ", "T_RESTART", "T_SERVER", "T_SERVICE", "T_SET", "T_SHARED",
  "T_SIZE", "T_TARGET", "T_TLS", "T_UMODES", "T_UNDLINE", "T_UNLIMITED",
  "T_UNRESV", "T_UNXLINE", "T_WEBIRC", "TBOOL", "THROTTLE_COUNT",
  "THROTTLE_TIME", "TIMEOUT", "TLS_CERTIFICATE_FILE",
  "TLS_CERTIFICATE_FINGERPRINT", "TLS_PRIVATE_KEY_FILE",
  "TLS_CONNECTION_REQUIRED", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "TYPE", "UNKLINE", "USE_LOGGING", "USER", "VHOST", "VHOST6",
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "WHOWAS_HISTORY_LENGTH", "XLINE",
  "XLINE_EXEMPT", "QSTRING", "NUMBER", "';'", "'}'", "'='", "':'", "','",
  "'{'", "$accept", "conf", "conf_item", "timespec_", "timespec",
  "sizespec_", "sizespec", "module_base_path_entry", "loadmodule_entry",
  "module_string", "module_attributes", "module_attributes_items",
  "module_attributes_item", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_tls_certificate_file",
  "serverinfo_tls_private_key_file", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_description", "serverinfo_default_max_clients",
  "serverinfo_max_nick_length", "serverinfo_motd_file", "serverinfo_hub",
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
  "channel_max_kick_length", "channel_max_topic_length",
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

#define YYPACT_NINF (-987)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-120)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -987,   601,  -987,  -171,  -183,  -178,  -987,  -987,  -987,  -174,
    -987,  -158,  -987,  -987,  -987,  -149,  -150,  -987,  -987,  -987,
    -151,  -144,  -987,   -49,  -987,   -37,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,   287,   730,   -34,     5,     9,    17,    23,
     364,    26,    32,    40,  -987,   -21,  -149,    54,    66,    69,
     456,   467,    70,     2,    73,    77,    74,     7,    21,    55,
      56,    90,  -987,  -987,  -987,  -987,  -987,    83,    94,   101,
     110,   111,   114,   115,   117,   118,   124,   126,   128,   132,
     133,   134,   135,    15,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,   664,   546,    52,  -987,   142,    39,  -987,  -987,    65,
    -987,   146,   149,   150,   151,   152,   155,   158,   160,   164,
     165,   166,   174,   175,   176,   180,   182,   184,   186,   189,
     190,   196,   197,   200,   202,   203,   204,   205,   206,   207,
     209,   214,   215,   223,   231,   233,   234,   236,   239,   242,
     243,   247,   256,   257,   259,   260,   262,   263,   264,    49,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,   337,
      59,   354,   -89,    72,    92,   157,   329,    37,  -987,   269,
     276,   280,   292,   293,   296,   298,   301,   253,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,   139,   304,   309,
     311,   312,   314,   319,   323,   326,   328,   331,   333,   163,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,    11,   147,   335,     3,  -987,  -987,  -987,   303,
     315,  -987,   336,    28,  -987,  -987,   210,  -987,   291,   341,
     342,   267,  -987,   344,   345,    41,   346,   345,   345,   345,
     347,   345,   345,   355,   356,   357,   359,   362,   363,   353,
    -987,   366,   361,   365,   368,  -987,   370,   371,   372,   373,
     374,   378,   380,   381,   383,   387,   389,   145,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,   392,   394,   395,   396,   397,   399,
     401,  -987,   404,   405,   407,   415,   416,   418,   419,   148,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,   422,   423,    46,  -987,
    -987,  -987,   428,   427,  -987,  -987,   430,   431,    19,  -987,
    -987,  -987,   453,   345,   435,   345,   345,   460,   438,   439,
     443,   445,   448,   472,   455,   345,   476,   479,   462,   464,
     345,   480,   345,   469,   470,   475,   477,   478,   481,   345,
     484,   485,   487,   483,   473,   499,   345,   345,   503,   345,
     513,   491,   515,   516,   495,   345,   345,   345,   519,   500,
     498,  -987,   501,   502,   504,  -987,   505,   506,   507,   141,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,   510,   511,
     121,  -987,  -987,  -987,   517,   512,   518,  -987,   521,  -987,
     120,  -987,  -987,  -987,  -987,  -987,  -987,   327,  -987,  -987,
    -987,   524,   527,   528,    12,  -987,  -987,  -987,   526,   529,
     530,  -987,   531,   532,   533,   534,   535,   536,   539,    86,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,   542,   544,   545,   550,    67,  -987,  -987,  -987,  -987,
     543,   577,   345,   520,   578,   523,   580,   583,   560,  -987,
    -987,   564,   568,   592,   575,   576,   579,   581,   582,   588,
     589,   590,   593,  -987,   594,   574,  -987,    76,  -987,  -987,
    -987,  -987,   602,   595,  -987,   585,   596,   598,   600,   603,
     608,    53,  -987,  -987,  -987,  -987,  -987,   605,   604,  -987,
     613,   614,  -987,   615,    18,  -987,  -987,  -987,  -987,   620,
     621,   622,  -987,   623,   289,   624,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   637,   638,   639,
    -987,  -987,   616,   619,   345,   640,   641,   345,   642,   345,
     645,   646,   647,   648,   345,   649,   649,   644,  -987,  -987,
     651,   -74,   652,   675,   654,   655,   653,   656,   658,   659,
     661,   662,   345,   663,   657,  -987,   665,   666,   667,  -987,
     668,  -987,   671,   672,   673,  -987,   674,   676,   677,   678,
     679,   680,   681,   682,   683,   684,   685,   686,   687,   688,
     689,   690,   691,   692,   693,   694,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,   706,   707,   708,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,  -987,  -987,   725,   748,   660,   727,
     728,   729,   731,  -987,   732,   734,   733,  -987,  -987,   736,
     737,   669,   738,   739,  -987,   -89,  -987,   740,   742,   741,
    -987,  -987,   744,   752,   670,   745,   746,   747,   749,   753,
     750,   751,   754,  -987,  -987,   755,   757,   758,   759,  -987,
     760,   761,   762,   763,   764,   765,   766,   767,  -987,   768,
     769,   770,   771,   772,   773,   774,   775,   776,   777,   778,
    -987,  -987,   781,   756,   780,  -987,   782,  -987,   216,  -987,
     783,   785,   786,   787,   788,  -987,   789,  -987,  -987,   792,
     784,   793,   794,  -987,  -987,  -987,  -987,  -987,   345,   345,
     345,   345,   345,   345,   345,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,   795,   796,   797,   -42,   798,   799,   800,   801,
     802,   803,   804,   805,   806,    10,   807,   808,  -987,   809,
     810,   811,   812,   813,   814,   815,     0,   816,   817,   818,
     819,   820,   821,   822,  -987,   823,   824,  -987,  -987,   825,
     826,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
     827,   828,   332,   829,   830,   831,  -987,   832,   833,  -987,
     834,   835,   265,   408,   496,  -987,  -987,  -987,   836,   837,
    -987,   838,   839,   457,   840,   841,   842,   843,   844,   845,
     846,  -987,   847,   848,   849,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,   850,   514,  -987,  -987,   851,
     790,   791,  -987,   137,  -987,  -987,  -987,  -987,   852,   853,
     854,   855,  -987,  -987,   856,   618,   857,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -204,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,   649,   649,   649,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -191,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -176,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -154,  -987,   859,   738,   860,
    -987,  -987,  -987,  -987,  -987,  -987,   743,  -987,   858,   861,
    -987,   862,  -987,   863,   864,  -987,  -987,   865,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -113,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,   -54,  -987,  -987,   871,  -173,   868,   872,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,   -23,  -987,  -987,  -987,   -42,
    -987,  -987,  -987,  -987,     0,  -987,   332,  -987,   265,  -987,
    -987,  -987,   936,   935,   940,   876,   944,   950,   951,  -987,
     457,  -987,   514,   875,   877,   878,   461,  -987,  -987,   618,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,   879,  -987,  -987
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   197,   355,   403,     0,
     418,     0,   263,   394,   237,     0,     0,    90,   140,   292,
       0,     0,   333,     0,    99,     0,   309,     3,     4,     5,
      13,     6,    25,    26,     7,     8,    10,    11,    12,    15,
      16,    17,    18,    19,    20,    21,    22,    24,    23,     9,
      14,    27,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,    83,    85,    84,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   529,   545,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   530,   531,   541,   542,   543,
     544,     0,     0,     0,   416,     0,     0,   414,   415,     0,
     478,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     429,   430,   431,   468,   436,   469,   463,   464,   465,   466,
     440,   432,   433,   434,   435,   450,   437,   438,   439,   441,
     442,   467,   444,   445,   452,   453,   446,   447,   448,   443,
     449,   460,   461,   462,   458,   459,   451,   456,   457,   454,
     455,   470,   471,   472,   473,   474,   475,   476,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   574,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   565,   566,
     567,   568,   569,   570,   571,   573,   572,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    67,    65,    57,    66,    59,    60,    61,    62,    63,
      64,    58,     0,     0,     0,     0,   114,   115,   116,     0,
       0,   307,     0,     0,   305,   306,     0,    86,     0,     0,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,     0,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,   201,
     204,   206,   207,   208,   209,   210,   211,   212,   202,   203,
     205,   213,   214,   215,     0,     0,     0,     0,     0,     0,
       0,   384,     0,     0,     0,     0,     0,     0,     0,     0,
     358,   359,   360,   361,   362,   363,   364,   365,   367,   366,
     368,   372,   369,   370,   371,   409,     0,     0,     0,   406,
     407,   408,     0,     0,   413,   424,     0,     0,     0,   421,
     422,   423,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   428,     0,     0,     0,   278,     0,     0,     0,     0,
     266,   267,   268,   269,   272,   270,   271,   400,     0,     0,
       0,   397,   398,   399,     0,     0,     0,   239,     0,   251,
       0,   249,   250,   252,   253,    53,    52,    49,    51,    46,
      45,     0,     0,     0,     0,    93,    94,    95,     0,     0,
       0,   164,     0,     0,     0,     0,     0,     0,     0,     0,
     143,   144,   145,   146,   147,   150,   151,   152,   149,   148,
     153,     0,     0,     0,     0,     0,   295,   296,   297,   298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   564,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,   341,     0,   336,   337,
     338,   117,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   105,   104,   106,     0,     0,   304,
       0,     0,   319,     0,     0,   312,   313,   314,   315,     0,
       0,     0,    80,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,   216,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,   373,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   357,     0,     0,     0,   405,
       0,   412,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   427,   273,     0,     0,     0,     0,
       0,     0,     0,   265,     0,     0,     0,   396,   254,     0,
       0,     0,     0,     0,   248,     0,    96,     0,     0,     0,
      92,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   142,   299,     0,     0,     0,     0,   294,
       0,     0,     0,     0,     0,     0,     0,     0,   563,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,   339,     0,     0,     0,   335,     0,   112,     0,   107,
       0,     0,     0,     0,     0,   101,     0,   303,   316,     0,
       0,     0,     0,   311,    89,    88,    87,   561,    29,    29,
      29,    29,    29,    29,    29,    31,    30,   562,   547,   548,
     549,   550,   551,   552,   553,   554,   557,   558,   555,   556,
     559,   560,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   356,     0,     0,   404,   417,     0,
       0,   419,   489,   494,   479,   480,   502,   519,   520,   521,
     522,   523,   524,   483,   517,   518,   511,   510,   484,   485,
     525,   497,   488,   486,   487,   492,   493,   481,   491,   490,
     508,   515,   516,   506,   514,   503,   501,   504,   509,   526,
     505,   507,   499,   500,   512,   513,   496,   495,   498,   482,
       0,     0,     0,     0,     0,     0,   264,     0,     0,   395,
       0,     0,     0,   259,   255,   258,   238,    50,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,   293,   578,   575,   576,   577,
     582,   581,   579,   580,    76,    73,    79,    72,    77,    78,
      71,    75,    74,    69,    70,     0,     0,   334,   118,     0,
       0,     0,   130,     0,   122,   123,   125,   124,     0,     0,
       0,     0,   100,   308,     0,     0,     0,   310,    32,    33,
      34,    35,    36,    37,    38,   226,   227,   221,   236,   235,
       0,   234,   222,   230,   223,   229,   217,   228,   220,   219,
     218,    39,    39,    39,    41,    40,   224,   225,   379,   382,
     383,   393,   390,   375,   391,   388,   389,     0,   387,   392,
     374,   381,   378,   377,   376,   380,   410,   411,   425,   426,
     276,   277,   286,   282,   283,   285,   290,   287,   288,   289,
     284,     0,   281,   275,   291,   274,   402,   401,   262,   261,
     246,   247,   244,   245,   243,     0,   242,     0,     0,     0,
      97,    98,   162,   159,   184,   195,   171,   180,     0,   169,
     174,     0,   189,     0,   183,   187,   193,   173,   176,   185,
     186,   190,   181,   188,   177,   194,   179,   175,   178,     0,
     167,   155,   157,   163,   160,   161,   156,   158,   302,   300,
     301,   340,   345,   351,   354,   347,   353,   348,   352,   350,
     346,   349,     0,   344,   126,     0,     0,     0,     0,   121,
     109,   108,   110,   111,   317,   323,   329,   332,   325,   331,
     326,   330,   328,   324,   327,     0,   322,   318,   232,     0,
      42,    43,    44,   385,     0,   279,     0,   240,     0,   260,
     257,   256,     0,     0,     0,     0,     0,     0,     0,   165,
       0,   342,     0,     0,     0,     0,     0,   120,   320,     0,
     233,   386,   280,   241,   170,   192,   168,   196,   191,   182,
     172,   166,   343,   127,   129,   128,   138,   137,   133,   135,
     139,   136,   132,   134,     0,   321,   131
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -987,  -987,  -987,  -768,  -302,  -986,  -625,  -987,  -987,   885,
    -987,  -987,    -7,  -987,  -987,   451,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,   886,
    -987,  -987,  -987,  -987,  -987,  -987,   386,  -987,  -987,  -987,
    -987,  -987,   159,  -987,  -987,  -987,  -987,  -987,  -987,   866,
    -987,  -987,  -987,  -987,   -92,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,   463,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -280,  -987,  -987,  -987,
     779,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -147,  -987,
    -987,  -987,  -987,  -987,  -192,  -987,   611,  -987,  -987,  -987,
      27,  -987,  -987,  -987,  -987,  -987,   643,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,   -60,  -987,  -987,  -987,  -987,   572,
    -987,  -987,  -987,  -987,  -987,   867,  -987,  -987,  -987,  -987,
     522,  -987,  -987,  -987,  -987,  -987,   -81,  -987,  -987,  -987,
     547,  -987,  -987,  -987,  -987,   -73,  -987,  -987,  -987,   869,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,   -53,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
     650,  -987,  -987,  -987,  -987,  -987,   723,  -987,  -987,  -987,
    -987,   974,  -987,  -987,  -987,  -987,   724,  -987,  -987,  -987,
    -987,   924,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  1002,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987,
    -987,   870,  -987,  -987,  -987,  -987,  -987,  -987,  -987,  -987
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   805,   806,  1014,  1015,    28,    29,    65,
     233,   487,   488,    30,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    31,    81,    82,
      83,    84,    85,    32,    67,   494,   495,   496,   497,    33,
      74,   571,   572,   573,   574,   575,   576,    34,   285,   286,
     287,   288,   289,   973,   974,   975,   976,   977,  1127,  1204,
      35,    68,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   734,  1099,  1100,    36,    55,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   615,  1000,  1001,    37,
      63,   479,   721,  1065,  1066,   480,   481,   482,  1069,   924,
     925,   483,   484,    38,    61,   459,   460,   461,   462,   463,
     464,   465,   708,  1051,  1052,   466,    39,    69,   525,   526,
     527,   528,   529,    40,   293,   294,   295,    41,    76,   584,
     585,   586,   587,   588,   790,  1145,  1146,    42,    72,   557,
     558,   559,   560,   773,  1122,  1123,    43,    56,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     636,  1027,  1028,   381,   382,   383,   384,    44,    62,   470,
     471,   472,   473,    45,    57,   388,   389,   390,   391,    46,
     126,   127,   128,    47,    59,   398,   399,   400,   401,    48,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
      49,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    50,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     836,   837,   595,   283,   283,   598,   599,   600,  1025,   602,
     603,  1148,   554,   491,  1174,  1149,    86,   998,   124,   580,
     395,  1011,  1012,  1013,  1153,  1150,  1151,  1152,  1154,   291,
     988,   989,   990,   991,   992,   993,   994,    53,   521,  1155,
     124,   835,    54,  1156,    51,    52,    58,   385,    87,    88,
     130,   485,   486,   385,   566,   131,   132,    89,   133,   134,
     467,  1157,    60,   135,    64,  1158,   395,    66,   521,    70,
     136,   137,   138,   139,   140,   141,    71,   554,   291,   142,
     143,   144,    90,    91,    92,    93,   522,   498,   125,   145,
     146,    77,   999,   147,   148,   840,   841,    94,    95,    96,
     492,   657,  1169,   659,   660,   499,  1170,    97,    98,    99,
     125,   100,   101,   669,   149,   150,   522,   386,   674,   102,
     676,   474,   467,   386,   555,   523,   151,   683,    78,   152,
     153,   581,   396,   500,   690,   691,    79,   693,   969,   154,
     155,   292,   452,   699,   700,   701,   321,   156,   157,   354,
     158,   355,   159,   356,   397,   523,   160,   161,   491,   501,
     453,  1171,   322,   323,   257,  1172,   567,   357,   162,  -119,
    -119,    73,   524,   163,   324,   164,   165,   166,   396,   493,
     167,   387,   475,    75,  1026,   168,   121,   387,   454,   555,
     292,   476,  1178,   477,   468,   358,  1179,   232,   258,   502,
     397,   259,   524,    80,   169,   170,   284,   284,   171,   172,
     359,   580,   360,   556,   455,   503,   568,   969,   325,   563,
     582,   361,   297,   583,   835,   122,   260,   569,   729,   123,
     752,   319,   596,   362,   792,   654,   570,   261,   298,   326,
     327,   173,   174,   129,   578,   492,   229,   328,   175,   176,
     970,   329,   230,   478,   238,   393,   468,   177,   330,   178,
     231,   363,   648,   262,   469,   450,   331,   332,   333,   784,
     456,   504,   299,   300,   235,   263,   264,   334,   556,   265,
     266,   364,   505,   748,   506,  1060,   236,   489,    77,   237,
     282,   507,   774,   290,   296,   508,   239,   335,   457,   365,
     303,  1061,   742,   240,   241,   242,   301,   490,   243,   244,
     366,   304,   824,   245,   246,   827,   566,   829,   305,   971,
    1062,   336,   834,   581,   493,    78,   469,   306,   307,   970,
     498,   308,   309,    79,   310,   311,   723,   716,   452,   972,
     852,   312,   367,   313,   368,   314,   458,  1042,   499,   315,
     316,   317,   318,  1128,   540,   474,   453,   712,   267,   392,
     268,   627,   561,   402,   644,   130,   403,   404,   405,   406,
     131,   132,   407,   133,   134,   408,   500,   409,   135,   552,
    1043,   410,   411,   412,   454,   136,   137,   138,   139,   140,
     141,   413,   414,   415,   142,   143,   144,   416,   971,   417,
      80,   418,   501,   419,   145,   146,   420,   421,   147,   148,
     455,  1044,   582,   422,   423,   583,   475,   424,   972,   425,
     426,   427,   428,   429,   430,   476,   431,   477,   567,   149,
     150,   432,   433,   798,   799,   800,   801,   802,   803,   804,
     434,   151,   502,  1063,   152,   153,  1045,  1046,   435,  1064,
     436,   437,  1047,   438,   154,   155,   439,   238,   503,   440,
     441,  1074,   156,   157,   442,   158,   456,   159,   257,   538,
     565,   160,   161,   443,   444,  1048,   445,   446,   568,   447,
     448,   449,   592,   162,  1075,  1076,   530,   478,   163,   569,
     164,   165,   166,   531,   457,   167,  1077,   532,   570,   239,
     168,  1175,   258,   594,   589,   259,   240,   241,   242,   533,
     534,   243,   244,   535,   504,   536,   245,   246,   537,   169,
     170,   541,  1049,   171,   172,   505,   542,   506,   543,   544,
     260,   545,  1078,  1079,   507,  1080,   546,  1196,   508,  1197,
     547,   261,   458,   548,  1050,   549,   725,   354,   550,   355,
     551,   356,   562,   577,   590,   591,   173,   174,   593,   594,
     597,   601,  1081,   175,   176,   357,  1082,   262,   610,   604,
     605,   606,   177,   607,   178,  1083,   608,   609,   612,   263,
     264,   611,   613,   265,   266,   614,  1198,   616,   617,   618,
     619,   620,  1112,   358,  1084,   621,  1085,   622,   623,  1086,
     624,     2,     3,  1199,   625,     4,   626,   629,   359,  1067,
     360,   630,   631,   632,   633,  1087,   634,     5,   635,   361,
       6,   637,   638,  1088,   639,  1089,  1200,  1201,  1090,     7,
    1091,   362,   640,   641,  1092,   642,   643,  1093,     8,   646,
     647,   650,   651,  1094,   656,  1095,  1096,   652,   653,   658,
       9,   661,   662,   663,    10,    11,  1113,   664,   665,   363,
    1097,   666,   267,   667,   268,   321,  1202,   670,  1098,   668,
     671,   675,  1203,    12,   687,  1114,   672,    13,   673,   364,
    1115,   322,   323,   677,   678,  1116,   688,    14,    15,   679,
     689,   680,   681,   324,   692,   682,  1135,   365,   684,   685,
    1117,   686,  1118,  1119,   694,   695,   696,   697,   366,   698,
     702,    16,    17,   704,   703,  1068,   705,  1120,   927,   706,
     553,   707,   709,   710,   711,  1121,    18,   714,   715,   719,
     785,    86,   718,   753,   750,   720,   755,   325,   722,   726,
     367,   731,   368,    19,   727,   728,   732,   733,   735,   736,
     737,   738,   739,   740,    20,    21,   741,   744,   326,   327,
    1136,   745,   746,    87,    88,    22,   328,   747,   751,   754,
     329,   756,    89,    23,   757,   758,    24,   330,   759,  1137,
      25,   760,    26,   761,  1138,   331,   332,   333,   762,  1139,
     763,   772,   764,   776,   765,   766,   334,    90,    91,    92,
      93,   767,   768,   769,  1140,   778,  1141,  1142,   770,   771,
     777,   779,    94,    95,    96,   780,   335,   781,   786,   787,
     782,  1143,    97,    98,    99,   783,   100,   101,   788,  1144,
     822,   789,   791,   823,   102,   794,   795,   796,   797,   807,
     336,   808,   809,   810,   811,   812,   813,   814,   815,   816,
     817,   818,   819,   820,   821,   826,   828,   825,   830,   838,
     831,   832,   833,   835,   839,   842,   843,   844,   845,   847,
     846,   848,   854,   849,   850,   851,   853,   912,   855,   856,
     730,  1129,   857,   858,   859,   860,   922,   933,   861,   862,
    1191,   863,   864,   865,   866,   867,   868,   869,   870,   871,
     872,   873,   874,   875,   876,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   886,   887,   888,   889,   890,   891,
     892,   893,   894,   895,   896,   897,   898,   899,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
     913,   914,   915,   932,   938,   917,   916,   918,   919,   920,
     921,   234,   923,   928,   926,   929,   930,   931,   934,   935,
     936,  1162,   937,   939,   940,  1187,  1183,   302,   942,   941,
     943,   944,   743,   966,   945,   946,   947,   948,   949,   950,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   965,   967,   978,   968,   979,   980,
     981,   985,  1180,   982,   983,   984,   986,  1125,  1126,   987,
     995,   996,   997,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,  1010,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1053,  1054,  1055,  1056,  1057,  1058,
    1059,  1070,  1071,  1072,  1073,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1124,  1130,  1131,  1132,
    1133,  1134,  1147,  1159,  1184,  1161,  1163,  1185,  1186,  1164,
    1165,  1166,  1167,  1168,  1173,  1176,  1188,  1177,  1189,  1190,
    1193,   724,  1194,  1195,  1206,  1160,  1182,   749,  1205,  1192,
     394,  1181,   713,   451,   775,   320,   793,     0,     0,     0,
       0,   649,     0,     0,     0,     0,   628,   539,     0,     0,
     717,     0,   655,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   564,     0,     0,     0,     0,     0,     0,     0,     0,
     579,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   645
};

static const yytype_int16 yycheck[] =
{
     625,   626,   304,     1,     1,   307,   308,   309,     8,   311,
     312,   215,     1,     1,   187,   219,     1,    59,     1,     1,
       1,    11,    12,    13,   215,  1011,  1012,  1013,   219,     1,
     798,   799,   800,   801,   802,   803,   804,   220,     1,   215,
       1,   214,   220,   219,   215,   216,   220,     1,    33,    34,
       1,   140,   141,     1,     1,     6,     7,    42,     9,    10,
       1,   215,   220,    14,   213,   219,     1,   217,     1,   220,
      21,    22,    23,    24,    25,    26,   220,     1,     1,    30,
      31,    32,    67,    68,    69,    70,    49,     1,    71,    40,
      41,     1,   134,    44,    45,   169,   170,    82,    83,    84,
      88,   403,   215,   405,   406,    19,   219,    92,    93,    94,
      71,    96,    97,   415,    65,    66,    49,    71,   420,   104,
     422,     1,     1,    71,   113,    88,    77,   429,    38,    80,
      81,   113,   113,    47,   436,   437,    46,   439,     1,    90,
      91,   113,     1,   445,   446,   447,     1,    98,    99,     1,
     101,     3,   103,     5,   135,    88,   107,   108,     1,    73,
      19,   215,    17,    18,     1,   219,   113,    19,   119,   167,
     167,   220,   135,   124,    29,   126,   127,   128,   113,   167,
     131,   135,    62,   220,   184,   136,   220,   135,    47,   113,
     113,    71,   215,    73,   135,    47,   219,   218,    35,   113,
     135,    38,   135,   113,   155,   156,   204,   204,   159,   160,
      62,     1,    64,   202,    73,   129,   163,     1,    73,   216,
     202,    73,   215,   205,   214,   220,    63,   174,   216,   220,
     532,   216,   191,    85,   216,   216,   183,    74,   217,    94,
      95,   192,   193,   220,   216,    88,   220,   102,   199,   200,
     113,   106,   220,   133,     1,   216,   135,   208,   113,   210,
     220,   113,   216,   100,   205,   216,   121,   122,   123,   216,
     129,   185,   217,   217,   220,   112,   113,   132,   202,   116,
     117,   133,   196,   216,   198,    20,   220,   215,     1,   220,
     220,   205,   216,   220,   220,   209,    43,   152,   157,   151,
     217,    36,   216,    50,    51,    52,   216,   215,    55,    56,
     162,   217,   614,    60,    61,   617,     1,   619,   217,   182,
      55,   176,   624,   113,   167,    38,   205,   217,   217,   113,
       1,   217,   217,    46,   217,   217,   216,   216,     1,   202,
     642,   217,   194,   217,   196,   217,   205,    15,    19,   217,
     217,   217,   217,   216,   215,     1,    19,   216,   195,   217,
     197,   216,   215,   217,   216,     1,   217,   217,   217,   217,
       6,     7,   217,     9,    10,   217,    47,   217,    14,   216,
      48,   217,   217,   217,    47,    21,    22,    23,    24,    25,
      26,   217,   217,   217,    30,    31,    32,   217,   182,   217,
     113,   217,    73,   217,    40,    41,   217,   217,    44,    45,
      73,    79,   202,   217,   217,   205,    62,   217,   202,   217,
     217,   217,   217,   217,   217,    71,   217,    73,   113,    65,
      66,   217,   217,   144,   145,   146,   147,   148,   149,   150,
     217,    77,   113,   178,    80,    81,   114,   115,   217,   184,
     217,   217,   120,   217,    90,    91,   217,     1,   129,   217,
     217,     4,    98,    99,   217,   101,   129,   103,     1,   216,
     167,   107,   108,   217,   217,   143,   217,   217,   163,   217,
     217,   217,   215,   119,    27,    28,   217,   133,   124,   174,
     126,   127,   128,   217,   157,   131,    39,   217,   183,    43,
     136,  1126,    35,   214,   213,    38,    50,    51,    52,   217,
     217,    55,    56,   217,   185,   217,    60,    61,   217,   155,
     156,   217,   190,   159,   160,   196,   217,   198,   217,   217,
      63,   217,    75,    76,   205,    78,   217,    76,   209,    78,
     217,    74,   205,   217,   212,   217,   219,     1,   217,     3,
     217,     5,   217,   217,   213,   213,   192,   193,   214,   214,
     214,   214,   105,   199,   200,    19,   109,   100,   215,   214,
     214,   214,   208,   214,   210,   118,   214,   214,   217,   112,
     113,   215,   217,   116,   117,   217,   125,   217,   217,   217,
     217,   217,    78,    47,   137,   217,   139,   217,   217,   142,
     217,     0,     1,   142,   217,     4,   217,   215,    62,   201,
      64,   217,   217,   217,   217,   158,   217,    16,   217,    73,
      19,   217,   217,   166,   217,   168,   165,   166,   171,    28,
     173,    85,   217,   217,   177,   217,   217,   180,    37,   217,
     217,   213,   215,   186,   191,   188,   189,   217,   217,   214,
      49,   191,   214,   214,    53,    54,   142,   214,   213,   113,
     203,   213,   195,   191,   197,     1,   205,   191,   211,   214,
     191,   191,   211,    72,   191,   161,   214,    76,   214,   133,
     166,    17,    18,   214,   214,   171,   213,    86,    87,   214,
     191,   214,   214,    29,   191,   214,    78,   151,   214,   214,
     186,   214,   188,   189,   191,   214,   191,   191,   162,   214,
     191,   110,   111,   215,   214,   219,   215,   203,   725,   217,
     269,   217,   217,   217,   217,   211,   125,   217,   217,   217,
     571,     1,   215,   213,   191,   217,   213,    73,   217,   215,
     194,   215,   196,   142,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   153,   154,   217,   215,    94,    95,
     142,   217,   217,    33,    34,   164,   102,   217,   191,   191,
     106,   191,    42,   172,   191,   215,   175,   113,   214,   161,
     179,   213,   181,   191,   166,   121,   122,   123,   213,   171,
     214,   217,   213,   191,   213,   213,   132,    67,    68,    69,
      70,   213,   213,   213,   186,   220,   188,   189,   215,   215,
     215,   215,    82,    83,    84,   217,   152,   217,   213,   215,
     217,   203,    92,    93,    94,   217,    96,    97,   215,   211,
     214,   217,   217,   214,   104,   215,   215,   215,   215,   215,
     176,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   214,   214,   217,   213,   215,
     214,   214,   214,   214,   213,   213,   191,   213,   213,   213,
     217,   213,   215,   214,   213,   213,   213,   217,   213,   213,
     494,   973,   215,   215,   213,   213,   217,   217,   215,   215,
    1170,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   213,   191,
     213,   213,   213,   191,   191,   213,   215,   213,   215,   213,
     213,    66,   214,   213,   215,   213,   215,   213,   213,   213,
     213,   218,   213,   213,   213,    89,  1158,    81,   213,   215,
     213,   213,   509,   217,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   213,   215,   213,   215,   213,   213,
     213,   217,  1149,   215,   215,   213,   213,   217,   217,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   214,   138,   215,   218,   142,   138,   218,
     218,   218,   218,   218,   213,   217,   142,   215,   138,   138,
     215,   480,   215,   215,   215,  1068,  1156,   525,  1179,  1172,
     126,  1154,   459,   179,   557,   103,   584,    -1,    -1,    -1,
      -1,   388,    -1,    -1,    -1,    -1,   337,   247,    -1,    -1,
     470,    -1,   398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   369
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   222,     0,     1,     4,    16,    19,    28,    37,    49,
      53,    54,    72,    76,    86,    87,   110,   111,   125,   142,
     153,   154,   164,   172,   175,   179,   181,   223,   228,   229,
     234,   248,   254,   260,   268,   281,   298,   320,   334,   347,
     354,   358,   368,   377,   398,   404,   410,   414,   420,   471,
     490,   215,   216,   220,   220,   299,   378,   405,   220,   415,
     220,   335,   399,   321,   213,   230,   217,   255,   282,   348,
     220,   220,   369,   220,   261,   220,   359,     1,    38,    46,
     113,   249,   250,   251,   252,   253,     1,    33,    34,    42,
      67,    68,    69,    70,    82,    83,    84,    92,    93,    94,
      96,    97,   104,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   220,   220,   220,     1,    71,   411,   412,   413,   220,
       1,     6,     7,     9,    10,    14,    21,    22,    23,    24,
      25,    26,    30,    31,    32,    40,    41,    44,    45,    65,
      66,    77,    80,    81,    90,    91,    98,    99,   101,   103,
     107,   108,   119,   124,   126,   127,   128,   131,   136,   155,
     156,   159,   160,   192,   193,   199,   200,   208,   210,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   220,
     220,   220,   218,   231,   230,   220,   220,   220,     1,    43,
      50,    51,    52,    55,    56,    60,    61,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,     1,    35,    38,
      63,    74,   100,   112,   113,   116,   117,   195,   197,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   220,     1,   204,   269,   270,   271,   272,   273,
     220,     1,   113,   355,   356,   357,   220,   215,   217,   217,
     217,   216,   250,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   216,
     473,     1,    17,    18,    29,    73,    94,    95,   102,   106,
     113,   121,   122,   123,   132,   152,   176,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     1,     3,     5,    19,    47,    62,
      64,    73,    85,   113,   133,   151,   162,   194,   196,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   394,   395,   396,   397,     1,    71,   135,   406,   407,
     408,   409,   217,   216,   412,     1,   113,   135,   416,   417,
     418,   419,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     216,   422,     1,    19,    47,    73,   129,   157,   205,   336,
     337,   338,   339,   340,   341,   342,   346,     1,   135,   205,
     400,   401,   402,   403,     1,    62,    71,    73,   133,   322,
     326,   327,   328,   332,   333,   140,   141,   232,   233,   215,
     215,     1,    88,   167,   256,   257,   258,   259,     1,    19,
      47,    73,   113,   129,   185,   196,   198,   205,   209,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,     1,    49,    88,   135,   349,   350,   351,   352,   353,
     217,   217,   217,   217,   217,   217,   217,   217,   216,   492,
     215,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   216,   236,     1,   113,   202,   370,   371,   372,
     373,   215,   217,   216,   270,   167,     1,   113,   163,   174,
     183,   262,   263,   264,   265,   266,   267,   217,   216,   356,
       1,   113,   202,   205,   360,   361,   362,   363,   364,   213,
     213,   213,   215,   214,   214,   225,   191,   214,   225,   225,
     225,   214,   225,   225,   214,   214,   214,   214,   214,   214,
     215,   215,   217,   217,   217,   317,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   216,   301,   215,
     217,   217,   217,   217,   217,   217,   391,   217,   217,   217,
     217,   217,   217,   217,   216,   380,   217,   217,   216,   407,
     213,   215,   217,   217,   216,   417,   191,   225,   214,   225,
     225,   191,   214,   214,   214,   213,   213,   191,   214,   225,
     191,   191,   214,   214,   225,   191,   225,   214,   214,   214,
     214,   214,   214,   225,   214,   214,   214,   191,   213,   191,
     225,   225,   191,   225,   191,   214,   191,   191,   214,   225,
     225,   225,   191,   214,   215,   215,   217,   217,   343,   217,
     217,   217,   216,   337,   217,   217,   216,   401,   215,   217,
     217,   323,   217,   216,   327,   219,   215,   217,   217,   216,
     257,   215,   217,   217,   295,   217,   217,   217,   217,   217,
     217,   217,   216,   284,   215,   217,   217,   217,   216,   350,
     191,   191,   225,   213,   191,   213,   191,   191,   215,   214,
     213,   191,   213,   214,   213,   213,   213,   213,   213,   213,
     215,   215,   217,   374,   216,   371,   191,   215,   220,   215,
     217,   217,   217,   217,   216,   263,   213,   215,   215,   217,
     365,   217,   216,   361,   215,   215,   215,   215,   144,   145,
     146,   147,   148,   149,   150,   224,   225,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   214,   214,   225,   217,   214,   225,   214,   225,
     213,   214,   214,   214,   225,   214,   227,   227,   215,   213,
     169,   170,   213,   191,   213,   213,   217,   213,   213,   214,
     213,   213,   225,   213,   215,   213,   213,   215,   215,   213,
     213,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     213,   191,   217,   213,   213,   213,   215,   213,   213,   215,
     213,   213,   217,   214,   330,   331,   215,   233,   213,   213,
     215,   213,   191,   217,   213,   213,   213,   213,   191,   213,
     213,   215,   213,   213,   213,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   213,   217,   215,   215,     1,
     113,   182,   202,   274,   275,   276,   277,   278,   213,   213,
     213,   213,   215,   215,   213,   217,   213,   215,   224,   224,
     224,   224,   224,   224,   224,   215,   215,   215,    59,   134,
     318,   319,   215,   215,   215,   215,   215,   215,   215,   215,
     215,    11,    12,    13,   226,   227,   215,   215,   215,   215,
     215,   215,   215,   215,   215,     8,   184,   392,   393,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,    15,    48,    79,   114,   115,   120,   143,   190,
     212,   344,   345,   215,   215,   215,   215,   215,   215,   215,
      20,    36,    55,   178,   184,   324,   325,   201,   219,   329,
     215,   215,   215,   215,     4,    27,    28,    39,    75,    76,
      78,   105,   109,   118,   137,   139,   142,   158,   166,   168,
     171,   173,   177,   180,   186,   188,   189,   203,   211,   296,
     297,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,    78,   142,   161,   166,   171,   186,   188,   189,
     203,   211,   375,   376,   215,   217,   217,   279,   216,   275,
     215,   215,   215,   215,   215,    78,   142,   161,   166,   171,
     186,   188,   189,   203,   211,   366,   367,   215,   215,   219,
     226,   226,   226,   215,   219,   215,   219,   215,   219,   214,
     331,   215,   218,   218,   218,   218,   218,   218,   218,   215,
     219,   215,   219,   213,   187,   227,   217,   215,   215,   219,
     319,   393,   345,   325,   138,   142,   138,    89,   142,   138,
     138,   297,   376,   215,   215,   215,    76,    78,   125,   142,
     165,   166,   205,   211,   280,   367,   215
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   221,   222,   222,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   224,
     224,   225,   225,   225,   225,   225,   225,   225,   225,   226,
     226,   227,   227,   227,   227,   228,   229,   230,   231,   231,
     232,   232,   233,   233,   234,   235,   235,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   249,   250,   250,   250,   250,   251,   252,   253,
     255,   254,   256,   256,   257,   257,   257,   258,   259,   261,
     260,   262,   262,   263,   263,   263,   263,   263,   264,   265,
     266,   267,   268,   269,   269,   270,   270,   270,   271,   273,
     272,   274,   274,   275,   275,   275,   275,   276,   277,   277,
     279,   278,   280,   280,   280,   280,   280,   280,   280,   280,
     282,   281,   283,   283,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   295,   294,   296,   296,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   299,   298,   300,
     300,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   317,   316,   318,   318,   319,   319,   321,   320,   323,
     322,   324,   324,   325,   325,   325,   325,   325,   326,   326,
     327,   327,   327,   327,   327,   329,   328,   330,   330,   331,
     331,   332,   333,   335,   334,   336,   336,   337,   337,   337,
     337,   337,   337,   337,   338,   339,   340,   341,   343,   342,
     344,   344,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   346,   348,   347,   349,   349,   350,   350,   350,   350,
     351,   352,   353,   354,   355,   355,   356,   356,   357,   359,
     358,   360,   360,   361,   361,   361,   361,   362,   363,   365,
     364,   366,   366,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   369,   368,   370,   370,   371,   371,   371,
     372,   374,   373,   375,   375,   376,   376,   376,   376,   376,
     376,   376,   376,   376,   376,   378,   377,   379,   379,   380,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   389,   391,   390,   392,   392,   393,   393,
     394,   395,   396,   397,   399,   398,   400,   400,   401,   401,
     401,   402,   403,   405,   404,   406,   406,   407,   407,   407,
     408,   409,   410,   411,   411,   412,   412,   413,   415,   414,
     416,   416,   417,   417,   417,   418,   419,   420,   421,   421,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   472,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   491,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   493,   494,   495,   496,   497,
     498,   499,   500
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     0,
       1,     2,     3,     3,     3,     4,     4,     1,     0,     2,
       3,     1,     1,     1,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     2,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     2,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       0,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     3,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     0,     6,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     0,     5,     3,     1,     1,
       3,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     2,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
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
  switch (yykind)
    {
    case YYSYMBOL_module_string: /* module_string  */
#line 349 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3139 "conf_parser.c"
        break;

      default:
        break;
    }
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
#line 3412 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 385 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3418 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 386 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3424 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 387 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3430 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 388 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3436 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 389 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3442 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 390 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3448 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 391 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3454 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 392 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3460 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 395 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3466 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 396 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3472 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 397 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3478 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 398 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3484 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3490 "conf_parser.c"
    break;

  case 45: /* module_base_path_entry: MODULE_BASE_PATH '=' module_string ';'  */
#line 407 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct module_error_info error;
    if (module_config_set_base_path(conf_parser_ctx.module_config, (yyvsp[-1].string), &error) != MODULE_SUCCESS)
    {
      conf_parser_ctx.module_config_valid = false;
      conf_error_report(error.message);
    }
  }
  io_free((yyvsp[-1].string));
}
#line 3507 "conf_parser.c"
    break;

  case 46: /* loadmodule_entry: LOADMODULE module_string module_attributes ';'  */
#line 425 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct module_error_info error;
    if (module_config_add(conf_parser_ctx.module_config, (yyvsp[-2].string), (module_flags_t)(yyvsp[-1].number), &error) != MODULE_SUCCESS)
    {
      conf_parser_ctx.module_config_valid = false;
      conf_error_report(error.message);
    }
  }
  io_free((yyvsp[-2].string));
}
#line 3524 "conf_parser.c"
    break;

  case 47: /* module_string: QSTRING  */
#line 440 "conf_parser.y"
{
  (yyval.string) = io_strdup((yyvsp[0].string));
}
#line 3532 "conf_parser.c"
    break;

  case 48: /* module_attributes: %empty  */
#line 445 "conf_parser.y"
{
  (yyval.number) = 0;
}
#line 3540 "conf_parser.c"
    break;

  case 49: /* module_attributes: ':' module_attributes_items  */
#line 448 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3548 "conf_parser.c"
    break;

  case 50: /* module_attributes_items: module_attributes_items ',' module_attributes_item  */
#line 453 "conf_parser.y"
{
  (yyval.number) = (yyvsp[-2].number) | (yyvsp[0].number);
}
#line 3556 "conf_parser.c"
    break;

  case 51: /* module_attributes_items: module_attributes_item  */
#line 456 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3564 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: RESIDENT  */
#line 461 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_DEACTIVATE;
}
#line 3572 "conf_parser.c"
    break;

  case 53: /* module_attributes_item: REQUIRED  */
#line 464 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_REMOVE;
}
#line 3580 "conf_parser.c"
    break;

  case 69: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 490 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3592 "conf_parser.c"
    break;

  case 70: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 499 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3604 "conf_parser.c"
    break;

  case 71: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 508 "conf_parser.y"
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
#line 3622 "conf_parser.c"
    break;

  case 72: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 523 "conf_parser.y"
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
#line 3640 "conf_parser.c"
    break;

  case 73: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 538 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3653 "conf_parser.c"
    break;

  case 74: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 548 "conf_parser.y"
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
#line 3670 "conf_parser.c"
    break;

  case 75: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 562 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3682 "conf_parser.c"
    break;

  case 76: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 571 "conf_parser.y"
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
#line 3708 "conf_parser.c"
    break;

  case 77: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 594 "conf_parser.y"
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
#line 3734 "conf_parser.c"
    break;

  case 78: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 617 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3746 "conf_parser.c"
    break;

  case 79: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 626 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3755 "conf_parser.c"
    break;

  case 87: /* admin_name: NAME '=' QSTRING ';'  */
#line 644 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3767 "conf_parser.c"
    break;

  case 88: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 653 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3779 "conf_parser.c"
    break;

  case 89: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 662 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3791 "conf_parser.c"
    break;

  case 90: /* $@1: %empty  */
#line 675 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3800 "conf_parser.c"
    break;

  case 91: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 679 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3817 "conf_parser.c"
    break;

  case 97: /* motd_mask: MASK '=' QSTRING ';'  */
#line 696 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3826 "conf_parser.c"
    break;

  case 98: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 702 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3835 "conf_parser.c"
    break;

  case 99: /* $@2: %empty  */
#line 712 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3844 "conf_parser.c"
    break;

  case 100: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 716 "conf_parser.y"
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
#line 3862 "conf_parser.c"
    break;

  case 108: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 734 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3871 "conf_parser.c"
    break;

  case 109: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 740 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3880 "conf_parser.c"
    break;

  case 110: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 746 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3889 "conf_parser.c"
    break;

  case 111: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 752 "conf_parser.y"
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
#line 3911 "conf_parser.c"
    break;

  case 118: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 781 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 3923 "conf_parser.c"
    break;

  case 119: /* $@3: %empty  */
#line 790 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3932 "conf_parser.c"
    break;

  case 120: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 794 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3945 "conf_parser.c"
    break;

  case 127: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 810 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3956 "conf_parser.c"
    break;

  case 128: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 818 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3964 "conf_parser.c"
    break;

  case 129: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 821 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3972 "conf_parser.c"
    break;

  case 130: /* $@4: %empty  */
#line 826 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3981 "conf_parser.c"
    break;

  case 132: /* logging_file_type_item: USER  */
#line 832 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3990 "conf_parser.c"
    break;

  case 133: /* logging_file_type_item: OPERATOR  */
#line 836 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3999 "conf_parser.c"
    break;

  case 134: /* logging_file_type_item: XLINE  */
#line 840 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4008 "conf_parser.c"
    break;

  case 135: /* logging_file_type_item: RESV  */
#line 844 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4017 "conf_parser.c"
    break;

  case 136: /* logging_file_type_item: T_DLINE  */
#line 848 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4026 "conf_parser.c"
    break;

  case 137: /* logging_file_type_item: KLINE  */
#line 852 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4035 "conf_parser.c"
    break;

  case 138: /* logging_file_type_item: KILL  */
#line 856 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4044 "conf_parser.c"
    break;

  case 139: /* logging_file_type_item: T_DEBUG  */
#line 860 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4053 "conf_parser.c"
    break;

  case 140: /* $@5: %empty  */
#line 870 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4065 "conf_parser.c"
    break;

  case 141: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 877 "conf_parser.y"
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
#line 4123 "conf_parser.c"
    break;

  case 155: /* oper_name: NAME '=' QSTRING ';'  */
#line 945 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4132 "conf_parser.c"
    break;

  case 156: /* oper_user: USER '=' QSTRING ';'  */
#line 951 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4141 "conf_parser.c"
    break;

  case 157: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 957 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4150 "conf_parser.c"
    break;

  case 158: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 963 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4159 "conf_parser.c"
    break;

  case 159: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 969 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4173 "conf_parser.c"
    break;

  case 160: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 980 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4182 "conf_parser.c"
    break;

  case 161: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 986 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4196 "conf_parser.c"
    break;

  case 162: /* oper_class: CLASS '=' QSTRING ';'  */
#line 997 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4205 "conf_parser.c"
    break;

  case 163: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1003 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4214 "conf_parser.c"
    break;

  case 164: /* $@6: %empty  */
#line 1009 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4223 "conf_parser.c"
    break;

  case 168: /* oper_flags_item: KILL ':' REMOTE  */
#line 1016 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4232 "conf_parser.c"
    break;

  case 169: /* oper_flags_item: KILL  */
#line 1020 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4241 "conf_parser.c"
    break;

  case 170: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1024 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4250 "conf_parser.c"
    break;

  case 171: /* oper_flags_item: CONNECT  */
#line 1028 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4259 "conf_parser.c"
    break;

  case 172: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1032 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4268 "conf_parser.c"
    break;

  case 173: /* oper_flags_item: SQUIT  */
#line 1036 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4277 "conf_parser.c"
    break;

  case 174: /* oper_flags_item: KLINE  */
#line 1040 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4286 "conf_parser.c"
    break;

  case 175: /* oper_flags_item: UNKLINE  */
#line 1044 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4295 "conf_parser.c"
    break;

  case 176: /* oper_flags_item: T_DLINE  */
#line 1048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4304 "conf_parser.c"
    break;

  case 177: /* oper_flags_item: T_UNDLINE  */
#line 1052 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4313 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: XLINE  */
#line 1056 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4322 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: T_UNXLINE  */
#line 1060 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4331 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: DIE  */
#line 1064 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4340 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: T_RESTART  */
#line 1068 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4349 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1072 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4358 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: REHASH  */
#line 1076 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4367 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: ADMIN  */
#line 1080 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4376 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: T_GLOBOPS  */
#line 1084 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4385 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_LOCOPS  */
#line 1088 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4394 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: REMOTEBAN  */
#line 1092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4403 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: T_SET  */
#line 1096 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4412 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: MODULE  */
#line 1100 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4421 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: T_OPME  */
#line 1104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4430 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: NICK ':' RESV  */
#line 1108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4439 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: JOIN ':' RESV  */
#line 1112 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4448 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: RESV  */
#line 1116 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4457 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: T_UNRESV  */
#line 1120 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4466 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: CLOSE  */
#line 1124 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4475 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1128 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4484 "conf_parser.c"
    break;

  case 197: /* $@7: %empty  */
#line 1138 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.con_freq.value  = CLASS_DEFAULT_CONNECT_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4500 "conf_parser.c"
    break;

  case 198: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1149 "conf_parser.y"
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
#line 4548 "conf_parser.c"
    break;

  case 217: /* class_name: NAME '=' QSTRING ';'  */
#line 1212 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4557 "conf_parser.c"
    break;

  case 218: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1218 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4566 "conf_parser.c"
    break;

  case 219: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1224 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4575 "conf_parser.c"
    break;

  case 220: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1230 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4584 "conf_parser.c"
    break;

  case 221: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1236 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4593 "conf_parser.c"
    break;

  case 222: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1242 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4602 "conf_parser.c"
    break;

  case 223: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1248 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4611 "conf_parser.c"
    break;

  case 224: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1254 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4620 "conf_parser.c"
    break;

  case 225: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1260 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4630 "conf_parser.c"
    break;

  case 226: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1267 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4639 "conf_parser.c"
    break;

  case 227: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1273 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4648 "conf_parser.c"
    break;

  case 228: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1279 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4657 "conf_parser.c"
    break;

  case 229: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1285 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4669 "conf_parser.c"
    break;

  case 230: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1294 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4681 "conf_parser.c"
    break;

  case 231: /* $@8: %empty  */
#line 1303 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4690 "conf_parser.c"
    break;

  case 235: /* class_flags_item: RANDOM_IDLE  */
#line 1310 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4699 "conf_parser.c"
    break;

  case 236: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1314 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4708 "conf_parser.c"
    break;

  case 237: /* $@9: %empty  */
#line 1324 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4717 "conf_parser.c"
    break;

  case 239: /* $@10: %empty  */
#line 1330 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4725 "conf_parser.c"
    break;

  case 243: /* listen_flags_item: T_TLS  */
#line 1336 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4734 "conf_parser.c"
    break;

  case 244: /* listen_flags_item: HIDDEN  */
#line 1340 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4743 "conf_parser.c"
    break;

  case 245: /* listen_flags_item: T_SERVER  */
#line 1344 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4752 "conf_parser.c"
    break;

  case 246: /* listen_flags_item: CLIENT  */
#line 1348 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4761 "conf_parser.c"
    break;

  case 247: /* listen_flags_item: DEFER  */
#line 1352 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4770 "conf_parser.c"
    break;

  case 255: /* $@11: %empty  */
#line 1360 "conf_parser.y"
                                 { reset_block_state(); }
#line 4776 "conf_parser.c"
    break;

  case 259: /* port_item: NUMBER  */
#line 1365 "conf_parser.y"
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
#line 4794 "conf_parser.c"
    break;

  case 260: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1378 "conf_parser.y"
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
#line 4814 "conf_parser.c"
    break;

  case 261: /* listen_address: IP '=' QSTRING ';'  */
#line 1395 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4823 "conf_parser.c"
    break;

  case 262: /* listen_host: HOST '=' QSTRING ';'  */
#line 1401 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4832 "conf_parser.c"
    break;

  case 263: /* $@12: %empty  */
#line 1411 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4841 "conf_parser.c"
    break;

  case 264: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1415 "conf_parser.y"
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
#line 4896 "conf_parser.c"
    break;

  case 274: /* auth_user: USER '=' QSTRING ';'  */
#line 1476 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4905 "conf_parser.c"
    break;

  case 275: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1482 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4914 "conf_parser.c"
    break;

  case 276: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1488 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4923 "conf_parser.c"
    break;

  case 277: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1494 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 4937 "conf_parser.c"
    break;

  case 278: /* $@13: %empty  */
#line 1505 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 4946 "conf_parser.c"
    break;

  case 282: /* auth_flags_item: EXCEED_LIMIT  */
#line 1513 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 4955 "conf_parser.c"
    break;

  case 283: /* auth_flags_item: KLINE_EXEMPT  */
#line 1517 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 4964 "conf_parser.c"
    break;

  case 284: /* auth_flags_item: XLINE_EXEMPT  */
#line 1521 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 4973 "conf_parser.c"
    break;

  case 285: /* auth_flags_item: NEED_IDENT  */
#line 1525 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 4982 "conf_parser.c"
    break;

  case 286: /* auth_flags_item: CAN_FLOOD  */
#line 1529 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 4991 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: NO_TILDE  */
#line 1533 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 5000 "conf_parser.c"
    break;

  case 288: /* auth_flags_item: RESV_EXEMPT  */
#line 1537 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 5009 "conf_parser.c"
    break;

  case 289: /* auth_flags_item: T_WEBIRC  */
#line 1541 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5018 "conf_parser.c"
    break;

  case 290: /* auth_flags_item: NEED_PASSWORD  */
#line 1545 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5027 "conf_parser.c"
    break;

  case 291: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1551 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    log_write(LOG_TYPE_IRCD,
              "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 5042 "conf_parser.c"
    break;

  case 292: /* $@14: %empty  */
#line 1566 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5054 "conf_parser.c"
    break;

  case 293: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1573 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5065 "conf_parser.c"
    break;

  case 300: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1584 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5074 "conf_parser.c"
    break;

  case 301: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1590 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5083 "conf_parser.c"
    break;

  case 302: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1596 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5092 "conf_parser.c"
    break;

  case 308: /* service_name: NAME '=' QSTRING ';'  */
#line 1611 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5107 "conf_parser.c"
    break;

  case 309: /* $@15: %empty  */
#line 1627 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5123 "conf_parser.c"
    break;

  case 310: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1638 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5138 "conf_parser.c"
    break;

  case 317: /* shared_name: NAME '=' QSTRING ';'  */
#line 1653 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5147 "conf_parser.c"
    break;

  case 318: /* shared_user: USER '=' QSTRING ';'  */
#line 1659 "conf_parser.y"
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
#line 5169 "conf_parser.c"
    break;

  case 319: /* $@16: %empty  */
#line 1678 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5178 "conf_parser.c"
    break;

  case 323: /* shared_type_item: KLINE  */
#line 1685 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5187 "conf_parser.c"
    break;

  case 324: /* shared_type_item: UNKLINE  */
#line 1689 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5196 "conf_parser.c"
    break;

  case 325: /* shared_type_item: T_DLINE  */
#line 1693 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5205 "conf_parser.c"
    break;

  case 326: /* shared_type_item: T_UNDLINE  */
#line 1697 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5214 "conf_parser.c"
    break;

  case 327: /* shared_type_item: XLINE  */
#line 1701 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5223 "conf_parser.c"
    break;

  case 328: /* shared_type_item: T_UNXLINE  */
#line 1705 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5232 "conf_parser.c"
    break;

  case 329: /* shared_type_item: RESV  */
#line 1709 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5241 "conf_parser.c"
    break;

  case 330: /* shared_type_item: T_UNRESV  */
#line 1713 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5250 "conf_parser.c"
    break;

  case 331: /* shared_type_item: T_LOCOPS  */
#line 1717 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5259 "conf_parser.c"
    break;

  case 332: /* shared_type_item: T_ALL  */
#line 1721 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5268 "conf_parser.c"
    break;

  case 333: /* $@17: %empty  */
#line 1731 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5282 "conf_parser.c"
    break;

  case 334: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1740 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5295 "conf_parser.c"
    break;

  case 340: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1753 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5304 "conf_parser.c"
    break;

  case 341: /* $@18: %empty  */
#line 1759 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5313 "conf_parser.c"
    break;

  case 345: /* cluster_type_item: KLINE  */
#line 1766 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5322 "conf_parser.c"
    break;

  case 346: /* cluster_type_item: UNKLINE  */
#line 1770 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5331 "conf_parser.c"
    break;

  case 347: /* cluster_type_item: T_DLINE  */
#line 1774 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5340 "conf_parser.c"
    break;

  case 348: /* cluster_type_item: T_UNDLINE  */
#line 1778 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5349 "conf_parser.c"
    break;

  case 349: /* cluster_type_item: XLINE  */
#line 1782 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5358 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: T_UNXLINE  */
#line 1786 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5367 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: RESV  */
#line 1790 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5376 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: T_UNRESV  */
#line 1794 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5385 "conf_parser.c"
    break;

  case 353: /* cluster_type_item: T_LOCOPS  */
#line 1798 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5394 "conf_parser.c"
    break;

  case 354: /* cluster_type_item: T_ALL  */
#line 1802 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5403 "conf_parser.c"
    break;

  case 355: /* $@19: %empty  */
#line 1812 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5417 "conf_parser.c"
    break;

  case 356: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1821 "conf_parser.y"
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
#line 5465 "conf_parser.c"
    break;

  case 374: /* connect_name: NAME '=' QSTRING ';'  */
#line 1883 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5474 "conf_parser.c"
    break;

  case 375: /* connect_host: HOST '=' QSTRING ';'  */
#line 1889 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5483 "conf_parser.c"
    break;

  case 376: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1895 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5492 "conf_parser.c"
    break;

  case 377: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1901 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5501 "conf_parser.c"
    break;

  case 378: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1907 "conf_parser.y"
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
#line 5517 "conf_parser.c"
    break;

  case 379: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1920 "conf_parser.y"
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
#line 5533 "conf_parser.c"
    break;

  case 380: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1933 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5542 "conf_parser.c"
    break;

  case 381: /* connect_port: PORT '=' NUMBER ';'  */
#line 1939 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5551 "conf_parser.c"
    break;

  case 382: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 1945 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5560 "conf_parser.c"
    break;

  case 383: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 1949 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5569 "conf_parser.c"
    break;

  case 384: /* $@20: %empty  */
#line 1955 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5577 "conf_parser.c"
    break;

  case 388: /* connect_flags_item: AUTOCONN  */
#line 1961 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5586 "conf_parser.c"
    break;

  case 389: /* connect_flags_item: T_TLS  */
#line 1965 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5595 "conf_parser.c"
    break;

  case 390: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1971 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5609 "conf_parser.c"
    break;

  case 391: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 1982 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5618 "conf_parser.c"
    break;

  case 392: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 1988 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5627 "conf_parser.c"
    break;

  case 393: /* connect_class: CLASS '=' QSTRING ';'  */
#line 1994 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5636 "conf_parser.c"
    break;

  case 394: /* $@21: %empty  */
#line 2004 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5645 "conf_parser.c"
    break;

  case 395: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2008 "conf_parser.y"
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
#line 5669 "conf_parser.c"
    break;

  case 401: /* kill_user: USER '=' QSTRING ';'  */
#line 2032 "conf_parser.y"
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
#line 5692 "conf_parser.c"
    break;

  case 402: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2052 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5701 "conf_parser.c"
    break;

  case 403: /* $@22: %empty  */
#line 2062 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5710 "conf_parser.c"
    break;

  case 404: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2066 "conf_parser.y"
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
#line 5732 "conf_parser.c"
    break;

  case 410: /* deny_ip: IP '=' QSTRING ';'  */
#line 2088 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5741 "conf_parser.c"
    break;

  case 411: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2094 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5750 "conf_parser.c"
    break;

  case 417: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2109 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_error_report("Unable to add D-line exemption");
}
#line 5762 "conf_parser.c"
    break;

  case 418: /* $@23: %empty  */
#line 2122 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5771 "conf_parser.c"
    break;

  case 419: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2126 "conf_parser.y"
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
#line 5791 "conf_parser.c"
    break;

  case 425: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2146 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5800 "conf_parser.c"
    break;

  case 426: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2152 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5809 "conf_parser.c"
    break;

  case 479: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2216 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5817 "conf_parser.c"
    break;

  case 480: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2221 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5825 "conf_parser.c"
    break;

  case 481: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2226 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5833 "conf_parser.c"
    break;

  case 482: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2231 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5841 "conf_parser.c"
    break;

  case 483: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2236 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5849 "conf_parser.c"
    break;

  case 484: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2241 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5857 "conf_parser.c"
    break;

  case 485: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2246 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5865 "conf_parser.c"
    break;

  case 486: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2251 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5873 "conf_parser.c"
    break;

  case 487: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2256 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5881 "conf_parser.c"
    break;

  case 488: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2261 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5889 "conf_parser.c"
    break;

  case 489: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2266 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5897 "conf_parser.c"
    break;

  case 490: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2271 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5905 "conf_parser.c"
    break;

  case 491: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2276 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5913 "conf_parser.c"
    break;

  case 492: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2281 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5921 "conf_parser.c"
    break;

  case 493: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2286 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 5932 "conf_parser.c"
    break;

  case 494: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2294 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5940 "conf_parser.c"
    break;

  case 495: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2299 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5948 "conf_parser.c"
    break;

  case 496: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2304 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5956 "conf_parser.c"
    break;

  case 497: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2309 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5964 "conf_parser.c"
    break;

  case 498: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2314 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5972 "conf_parser.c"
    break;

  case 499: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2319 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5980 "conf_parser.c"
    break;

  case 500: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2324 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5988 "conf_parser.c"
    break;

  case 501: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2329 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5996 "conf_parser.c"
    break;

  case 502: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2334 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6004 "conf_parser.c"
    break;

  case 503: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2339 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6012 "conf_parser.c"
    break;

  case 504: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2344 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6020 "conf_parser.c"
    break;

  case 505: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2349 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6028 "conf_parser.c"
    break;

  case 506: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2354 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6036 "conf_parser.c"
    break;

  case 507: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2359 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6044 "conf_parser.c"
    break;

  case 508: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2364 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6052 "conf_parser.c"
    break;

  case 509: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2369 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6060 "conf_parser.c"
    break;

  case 510: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2374 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6068 "conf_parser.c"
    break;

  case 511: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2379 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6076 "conf_parser.c"
    break;

  case 512: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2384 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6084 "conf_parser.c"
    break;

  case 513: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2389 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6092 "conf_parser.c"
    break;

  case 514: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2394 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6104 "conf_parser.c"
    break;

  case 515: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2403 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6112 "conf_parser.c"
    break;

  case 516: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2408 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6120 "conf_parser.c"
    break;

  case 517: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2413 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6128 "conf_parser.c"
    break;

  case 518: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2418 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6136 "conf_parser.c"
    break;

  case 519: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2423 "conf_parser.y"
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
#line 6156 "conf_parser.c"
    break;

  case 520: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2440 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6167 "conf_parser.c"
    break;

  case 521: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2448 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6178 "conf_parser.c"
    break;

  case 522: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2456 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6189 "conf_parser.c"
    break;

  case 523: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2464 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6202 "conf_parser.c"
    break;

  case 524: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2474 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6215 "conf_parser.c"
    break;

  case 525: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2484 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6226 "conf_parser.c"
    break;

  case 526: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2492 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6234 "conf_parser.c"
    break;

  case 547: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2522 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6242 "conf_parser.c"
    break;

  case 548: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2527 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6250 "conf_parser.c"
    break;

  case 549: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2532 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6258 "conf_parser.c"
    break;

  case 550: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2537 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6266 "conf_parser.c"
    break;

  case 551: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2542 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6274 "conf_parser.c"
    break;

  case 552: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2547 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6282 "conf_parser.c"
    break;

  case 553: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2552 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6290 "conf_parser.c"
    break;

  case 554: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2557 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6298 "conf_parser.c"
    break;

  case 555: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2562 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6306 "conf_parser.c"
    break;

  case 556: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2567 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6314 "conf_parser.c"
    break;

  case 557: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2572 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6322 "conf_parser.c"
    break;

  case 558: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2577 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6330 "conf_parser.c"
    break;

  case 559: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2582 "conf_parser.y"
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
#line 6356 "conf_parser.c"
    break;

  case 560: /* channel_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 2605 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigChannel.max_topic_length = TOPICLEN;
  else
    ConfigChannel.max_topic_length = (yyvsp[-1].number);
}
#line 6367 "conf_parser.c"
    break;

  case 561: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2613 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6375 "conf_parser.c"
    break;

  case 562: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2618 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6383 "conf_parser.c"
    break;

  case 575: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2640 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6392 "conf_parser.c"
    break;

  case 576: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2646 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6406 "conf_parser.c"
    break;

  case 577: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2657 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6418 "conf_parser.c"
    break;

  case 578: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2666 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6427 "conf_parser.c"
    break;

  case 579: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2672 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6436 "conf_parser.c"
    break;

  case 580: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2678 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6445 "conf_parser.c"
    break;

  case 581: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2684 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6457 "conf_parser.c"
    break;

  case 582: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2693 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6466 "conf_parser.c"
    break;


#line 6470 "conf_parser.c"

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

