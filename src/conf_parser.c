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
  YYSYMBOL_serverinfo_max_topic_length = 246, /* serverinfo_max_topic_length  */
  YYSYMBOL_serverinfo_motd_file = 247,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 248,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 249,              /* admin_entry  */
  YYSYMBOL_admin_items = 250,              /* admin_items  */
  YYSYMBOL_admin_item = 251,               /* admin_item  */
  YYSYMBOL_admin_name = 252,               /* admin_name  */
  YYSYMBOL_admin_email = 253,              /* admin_email  */
  YYSYMBOL_admin_description = 254,        /* admin_description  */
  YYSYMBOL_motd_entry = 255,               /* motd_entry  */
  YYSYMBOL_256_1 = 256,                    /* $@1  */
  YYSYMBOL_motd_items = 257,               /* motd_items  */
  YYSYMBOL_motd_item = 258,                /* motd_item  */
  YYSYMBOL_motd_mask = 259,                /* motd_mask  */
  YYSYMBOL_motd_file = 260,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 261,             /* pseudo_entry  */
  YYSYMBOL_262_2 = 262,                    /* $@2  */
  YYSYMBOL_pseudo_items = 263,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 264,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 265,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 266,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 267,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 268,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 269,            /* logging_entry  */
  YYSYMBOL_logging_items = 270,            /* logging_items  */
  YYSYMBOL_logging_item = 271,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 272,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 273,       /* logging_file_entry  */
  YYSYMBOL_274_3 = 274,                    /* $@3  */
  YYSYMBOL_logging_file_items = 275,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 276,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 277,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 278,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 279,        /* logging_file_type  */
  YYSYMBOL_280_4 = 280,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 281,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 282,               /* oper_entry  */
  YYSYMBOL_283_5 = 283,                    /* $@5  */
  YYSYMBOL_oper_items = 284,               /* oper_items  */
  YYSYMBOL_oper_item = 285,                /* oper_item  */
  YYSYMBOL_oper_name = 286,                /* oper_name  */
  YYSYMBOL_oper_user = 287,                /* oper_user  */
  YYSYMBOL_oper_password = 288,            /* oper_password  */
  YYSYMBOL_oper_whois = 289,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 290,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 291, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 292, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 293,               /* oper_class  */
  YYSYMBOL_oper_umodes = 294,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 295,               /* oper_flags  */
  YYSYMBOL_296_6 = 296,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 297,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 298,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 299,              /* class_entry  */
  YYSYMBOL_300_7 = 300,                    /* $@7  */
  YYSYMBOL_class_items = 301,              /* class_items  */
  YYSYMBOL_class_item = 302,               /* class_item  */
  YYSYMBOL_class_name = 303,               /* class_name  */
  YYSYMBOL_class_ping_time = 304,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 305, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 306, /* class_number_per_ip_global  */
  YYSYMBOL_class_connectfreq = 307,        /* class_connectfreq  */
  YYSYMBOL_class_max_channels = 308,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 309,         /* class_max_number  */
  YYSYMBOL_class_sendq = 310,              /* class_sendq  */
  YYSYMBOL_class_recvq = 311,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 312,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 313,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 314,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 315,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 316,           /* class_max_idle  */
  YYSYMBOL_class_flags = 317,              /* class_flags  */
  YYSYMBOL_318_8 = 318,                    /* $@8  */
  YYSYMBOL_class_flags_items = 319,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 320,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 321,             /* listen_entry  */
  YYSYMBOL_322_9 = 322,                    /* $@9  */
  YYSYMBOL_listen_flags = 323,             /* listen_flags  */
  YYSYMBOL_324_10 = 324,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 325,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 326,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 327,             /* listen_items  */
  YYSYMBOL_listen_item = 328,              /* listen_item  */
  YYSYMBOL_listen_port = 329,              /* listen_port  */
  YYSYMBOL_330_11 = 330,                   /* $@11  */
  YYSYMBOL_port_items = 331,               /* port_items  */
  YYSYMBOL_port_item = 332,                /* port_item  */
  YYSYMBOL_listen_address = 333,           /* listen_address  */
  YYSYMBOL_listen_host = 334,              /* listen_host  */
  YYSYMBOL_auth_entry = 335,               /* auth_entry  */
  YYSYMBOL_336_12 = 336,                   /* $@12  */
  YYSYMBOL_auth_items = 337,               /* auth_items  */
  YYSYMBOL_auth_item = 338,                /* auth_item  */
  YYSYMBOL_auth_user = 339,                /* auth_user  */
  YYSYMBOL_auth_passwd = 340,              /* auth_passwd  */
  YYSYMBOL_auth_class = 341,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 342,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 343,               /* auth_flags  */
  YYSYMBOL_344_13 = 344,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 345,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 346,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 347,               /* auth_spoof  */
  YYSYMBOL_resv_entry = 348,               /* resv_entry  */
  YYSYMBOL_349_14 = 349,                   /* $@14  */
  YYSYMBOL_resv_items = 350,               /* resv_items  */
  YYSYMBOL_resv_item = 351,                /* resv_item  */
  YYSYMBOL_resv_mask = 352,                /* resv_mask  */
  YYSYMBOL_resv_reason = 353,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 354,              /* resv_exempt  */
  YYSYMBOL_service_entry = 355,            /* service_entry  */
  YYSYMBOL_service_items = 356,            /* service_items  */
  YYSYMBOL_service_item = 357,             /* service_item  */
  YYSYMBOL_service_name = 358,             /* service_name  */
  YYSYMBOL_shared_entry = 359,             /* shared_entry  */
  YYSYMBOL_360_15 = 360,                   /* $@15  */
  YYSYMBOL_shared_items = 361,             /* shared_items  */
  YYSYMBOL_shared_item = 362,              /* shared_item  */
  YYSYMBOL_shared_name = 363,              /* shared_name  */
  YYSYMBOL_shared_user = 364,              /* shared_user  */
  YYSYMBOL_shared_type = 365,              /* shared_type  */
  YYSYMBOL_366_16 = 366,                   /* $@16  */
  YYSYMBOL_shared_types = 367,             /* shared_types  */
  YYSYMBOL_shared_type_item = 368,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 369,            /* cluster_entry  */
  YYSYMBOL_370_17 = 370,                   /* $@17  */
  YYSYMBOL_cluster_items = 371,            /* cluster_items  */
  YYSYMBOL_cluster_item = 372,             /* cluster_item  */
  YYSYMBOL_cluster_name = 373,             /* cluster_name  */
  YYSYMBOL_cluster_type = 374,             /* cluster_type  */
  YYSYMBOL_375_18 = 375,                   /* $@18  */
  YYSYMBOL_cluster_types = 376,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 377,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 378,            /* connect_entry  */
  YYSYMBOL_379_19 = 379,                   /* $@19  */
  YYSYMBOL_connect_items = 380,            /* connect_items  */
  YYSYMBOL_connect_item = 381,             /* connect_item  */
  YYSYMBOL_connect_name = 382,             /* connect_name  */
  YYSYMBOL_connect_host = 383,             /* connect_host  */
  YYSYMBOL_connect_timeout = 384,          /* connect_timeout  */
  YYSYMBOL_connect_bind = 385,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 386,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 387,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 388, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 389,             /* connect_port  */
  YYSYMBOL_connect_aftype = 390,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 391,            /* connect_flags  */
  YYSYMBOL_392_20 = 392,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 393,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 394,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 395,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 396,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 397,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 398,            /* connect_class  */
  YYSYMBOL_kill_entry = 399,               /* kill_entry  */
  YYSYMBOL_400_21 = 400,                   /* $@21  */
  YYSYMBOL_kill_items = 401,               /* kill_items  */
  YYSYMBOL_kill_item = 402,                /* kill_item  */
  YYSYMBOL_kill_user = 403,                /* kill_user  */
  YYSYMBOL_kill_reason = 404,              /* kill_reason  */
  YYSYMBOL_deny_entry = 405,               /* deny_entry  */
  YYSYMBOL_406_22 = 406,                   /* $@22  */
  YYSYMBOL_deny_items = 407,               /* deny_items  */
  YYSYMBOL_deny_item = 408,                /* deny_item  */
  YYSYMBOL_deny_ip = 409,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 410,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 411,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 412,             /* exempt_items  */
  YYSYMBOL_exempt_item = 413,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 414,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 415,              /* gecos_entry  */
  YYSYMBOL_416_23 = 416,                   /* $@23  */
  YYSYMBOL_gecos_items = 417,              /* gecos_items  */
  YYSYMBOL_gecos_item = 418,               /* gecos_item  */
  YYSYMBOL_gecos_name = 419,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 420,             /* gecos_reason  */
  YYSYMBOL_general_entry = 421,            /* general_entry  */
  YYSYMBOL_general_items = 422,            /* general_items  */
  YYSYMBOL_general_item = 423,             /* general_item  */
  YYSYMBOL_general_away_count = 424,       /* general_away_count  */
  YYSYMBOL_general_away_time = 425,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 426,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 427, /* general_whowas_history_length  */
  YYSYMBOL_general_cycle_on_host_change = 428, /* general_cycle_on_host_change  */
  YYSYMBOL_general_dline_min_cidr = 429,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 430,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 431,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 432,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 433, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_anti_nick_flood = 434,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 435,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 436, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 437,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 438,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 439, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 440,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 441,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 442, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 443, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 444, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_u_oper_only = 445, /* general_stats_u_oper_only  */
  YYSYMBOL_general_pace_wait = 446,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 447,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 448, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 449, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 450,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 451,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 452, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 453,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 454,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_ident = 455,    /* general_disable_ident  */
  YYSYMBOL_general_disable_dns = 456,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 457,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 458,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 459,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 460,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 461, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 462, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 463, /* general_default_floodtime  */
  YYSYMBOL_general_cloak_enabled = 464,    /* general_cloak_enabled  */
  YYSYMBOL_general_cloak_cidr_len_ipv4 = 465, /* general_cloak_cidr_len_ipv4  */
  YYSYMBOL_general_cloak_cidr_len_ipv6 = 466, /* general_cloak_cidr_len_ipv6  */
  YYSYMBOL_general_cloak_num_bits = 467,   /* general_cloak_num_bits  */
  YYSYMBOL_general_cloak_secret = 468,     /* general_cloak_secret  */
  YYSYMBOL_general_cloak_suffix = 469,     /* general_cloak_suffix  */
  YYSYMBOL_general_ident_timeout = 470,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 471, /* general_registration_timeout  */
  YYSYMBOL_channel_entry = 472,            /* channel_entry  */
  YYSYMBOL_channel_items = 473,            /* channel_items  */
  YYSYMBOL_channel_item = 474,             /* channel_item  */
  YYSYMBOL_channel_disable_fake_channels = 475, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 476, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 477, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 478, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 479, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 480, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 481, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 482, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 483,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 484,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 485,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 486,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 487,  /* channel_max_kick_length  */
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
#define YYLAST   1240

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
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     490,   499,   508,   523,   538,   548,   562,   571,   594,   617,
     625,   634,   644,   646,   646,   647,   648,   649,   650,   652,
     661,   670,   684,   683,   701,   701,   702,   702,   702,   704,
     710,   721,   720,   739,   739,   740,   740,   740,   740,   740,
     742,   748,   754,   760,   783,   784,   784,   786,   786,   787,
     789,   799,   799,   812,   813,   815,   815,   816,   816,   818,
     826,   829,   835,   834,   840,   844,   848,   852,   856,   860,
     864,   868,   879,   878,   940,   940,   941,   942,   943,   944,
     945,   946,   947,   948,   949,   950,   951,   953,   959,   965,
     971,   977,   988,   994,  1005,  1011,  1018,  1017,  1023,  1023,
    1024,  1028,  1032,  1036,  1040,  1044,  1048,  1052,  1056,  1060,
    1064,  1068,  1072,  1076,  1080,  1084,  1088,  1092,  1096,  1100,
    1104,  1108,  1112,  1116,  1120,  1124,  1128,  1132,  1136,  1147,
    1146,  1202,  1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,
    1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1220,
    1226,  1232,  1238,  1244,  1250,  1256,  1262,  1268,  1275,  1281,
    1287,  1293,  1302,  1312,  1311,  1317,  1317,  1318,  1322,  1333,
    1332,  1339,  1338,  1343,  1343,  1344,  1348,  1352,  1356,  1360,
    1366,  1366,  1367,  1367,  1367,  1367,  1367,  1369,  1369,  1371,
    1371,  1373,  1386,  1403,  1409,  1420,  1419,  1475,  1475,  1476,
    1477,  1478,  1479,  1480,  1481,  1482,  1484,  1490,  1496,  1502,
    1514,  1513,  1519,  1519,  1521,  1525,  1529,  1533,  1537,  1541,
    1545,  1549,  1553,  1559,  1575,  1574,  1589,  1589,  1590,  1590,
    1590,  1590,  1592,  1598,  1604,  1614,  1616,  1616,  1617,  1617,
    1619,  1636,  1635,  1658,  1658,  1659,  1659,  1659,  1659,  1661,
    1667,  1687,  1686,  1692,  1692,  1693,  1697,  1701,  1705,  1709,
    1713,  1717,  1721,  1725,  1729,  1740,  1739,  1758,  1758,  1759,
    1759,  1759,  1761,  1768,  1767,  1773,  1773,  1774,  1778,  1782,
    1786,  1790,  1794,  1798,  1802,  1806,  1810,  1821,  1820,  1874,
    1874,  1875,  1876,  1877,  1878,  1879,  1880,  1881,  1882,  1883,
    1884,  1885,  1886,  1887,  1888,  1889,  1891,  1897,  1903,  1909,
    1915,  1928,  1941,  1947,  1953,  1957,  1964,  1963,  1968,  1968,
    1969,  1973,  1979,  1990,  1996,  2002,  2013,  2012,  2037,  2037,
    2038,  2038,  2038,  2040,  2060,  2071,  2070,  2093,  2093,  2094,
    2094,  2094,  2096,  2102,  2112,  2114,  2114,  2115,  2115,  2117,
    2131,  2130,  2151,  2151,  2152,  2152,  2152,  2154,  2160,  2170,
    2172,  2172,  2173,  2174,  2175,  2176,  2177,  2178,  2179,  2180,
    2181,  2182,  2183,  2184,  2185,  2186,  2187,  2188,  2189,  2190,
    2191,  2192,  2193,  2194,  2195,  2196,  2197,  2198,  2199,  2200,
    2201,  2202,  2203,  2204,  2205,  2206,  2207,  2208,  2209,  2210,
    2211,  2212,  2213,  2214,  2215,  2216,  2217,  2218,  2219,  2220,
    2221,  2224,  2229,  2234,  2239,  2244,  2249,  2254,  2259,  2264,
    2269,  2274,  2279,  2284,  2289,  2294,  2302,  2307,  2312,  2317,
    2322,  2327,  2332,  2337,  2342,  2347,  2352,  2357,  2362,  2367,
    2372,  2377,  2382,  2387,  2392,  2397,  2402,  2411,  2416,  2421,
    2426,  2431,  2448,  2456,  2464,  2472,  2482,  2492,  2500,  2509,
    2511,  2511,  2512,  2513,  2514,  2515,  2516,  2517,  2518,  2519,
    2520,  2521,  2522,  2523,  2524,  2525,  2526,  2527,  2529,  2534,
    2539,  2544,  2549,  2554,  2559,  2564,  2569,  2574,  2579,  2584,
    2589,  2612,  2617,  2626,  2628,  2628,  2629,  2630,  2631,  2632,
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

#define YYPACT_NINF (-706)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-122)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -706,   613,  -706,  -189,  -181,  -177,  -706,  -706,  -706,  -170,
    -706,  -157,  -706,  -706,  -706,  -147,  -132,  -706,  -706,  -706,
    -116,  -105,  -706,  -102,  -706,   -99,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,     7,   730,   -85,   -60,   -43,    51,   -42,
     367,   -22,     8,    17,  -706,    31,  -147,    52,    53,    59,
     530,   408,    65,    86,    77,    40,    79,    46,    61,    69,
      85,   168,  -706,  -706,  -706,  -706,  -706,    95,   100,   102,
     105,   109,   110,   111,   112,   115,   119,   123,   130,   133,
     135,   145,    14,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,   607,
     510,    24,  -706,   148,    15,  -706,  -706,   180,  -706,   152,
     154,   158,   161,   163,   169,   170,   179,   184,   185,   186,
     193,   197,   198,   200,   203,   205,   207,   208,   209,   210,
     214,   217,   219,   220,   222,   225,   232,   233,   236,   237,
     242,   243,   245,   255,   256,   261,   262,   263,   264,   266,
     267,   268,   272,   275,   279,   280,   283,    48,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,   348,    90,   357,
     -65,    88,   142,   167,   332,   235,  -706,   284,   287,   289,
     290,   292,   297,   299,   301,   140,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,   146,   302,   315,   316,   317,
     322,   323,   333,   335,   337,   338,   339,   344,   188,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,    41,   149,   345,    66,  -706,  -706,  -706,   285,
     293,  -706,   346,    67,  -706,  -706,   108,  -706,   355,   358,
     363,   254,  -706,   296,   356,   134,   365,   356,   356,   356,
     370,   356,   356,   373,   374,   375,   378,   379,   381,  -706,
     386,   377,   387,   389,  -706,   390,   392,   393,   394,   395,
     399,   402,   403,   404,   405,   410,   144,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,   415,   417,   418,   425,   427,   428,   430,
    -706,   434,   435,   436,   437,   438,   439,   440,   147,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,   441,   442,    28,  -706,  -706,
    -706,   447,   450,  -706,  -706,   451,   452,   156,  -706,  -706,
    -706,   479,   356,   459,   356,   356,   483,   461,   462,   463,
     466,   468,   491,   472,   356,   496,   499,   477,   478,   356,
     503,   356,   481,   482,   484,   489,   493,   498,   356,   500,
     501,   502,   506,   492,   526,   356,   356,   527,   356,   528,
     507,   531,   535,   513,   356,   356,   356,   541,   520,   521,
    -706,   525,   518,   524,  -706,   529,   532,   533,    58,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,   534,   536,    29,
    -706,  -706,  -706,   537,   539,   540,  -706,   543,  -706,   126,
    -706,  -706,  -706,  -706,  -706,  -706,   523,  -706,  -706,  -706,
     546,   545,   548,   122,  -706,  -706,  -706,   553,   552,   554,
    -706,   556,   557,   558,   559,   561,   562,   563,   139,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
     555,   564,   565,   567,     2,  -706,  -706,  -706,  -706,   595,
     596,   356,   576,   599,   578,   602,   604,   581,  -706,  -706,
     544,   588,   611,   590,   591,   592,   594,   597,   598,   603,
     605,   606,   589,  -706,   593,   600,  -706,   129,  -706,  -706,
    -706,  -706,   618,   610,  -706,   517,   614,   615,   616,   617,
     619,    19,  -706,  -706,  -706,  -706,  -706,   608,   620,  -706,
     622,   621,  -706,   623,    11,  -706,  -706,  -706,  -706,   624,
     626,   627,  -706,   628,  -113,   629,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,  -706,
    -706,   601,   644,   356,   643,   645,   356,   647,   356,   649,
     650,   651,   652,   356,   653,   653,   648,  -706,  -706,   655,
       1,   656,   679,   658,   659,   657,   660,   662,   663,   665,
     666,   356,   667,   661,  -706,   668,   669,   670,  -706,   671,
    -706,   674,   675,   676,  -706,   677,   678,   680,   681,   682,
     683,   684,   685,   686,   687,   688,   689,   690,   691,   692,
     693,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   708,   709,   710,   711,   712,
     713,   714,   715,   716,   717,   718,   719,   720,   721,   722,
     723,   724,   725,  -706,  -706,   728,   751,   672,   731,   732,
     733,   734,  -706,   735,   737,   736,  -706,  -706,   739,   740,
     673,   729,   741,  -706,   -65,  -706,   742,   744,   743,  -706,
    -706,   746,   756,   745,   747,   748,   750,   752,   763,   753,
     754,   749,  -706,  -706,   755,   757,   758,   759,  -706,   760,
     761,   762,   764,   765,   766,   767,   768,  -706,   769,   770,
     771,   772,   773,   774,   775,   776,   777,   778,   779,   780,
    -706,  -706,   783,   781,   782,  -706,   784,  -706,   164,  -706,
     787,   788,   789,   790,   791,  -706,   792,  -706,  -706,   795,
     793,   796,   797,  -706,  -706,  -706,  -706,  -706,   356,   356,
     356,   356,   356,   356,   356,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,   798,   799,   800,   -40,   801,   802,   803,   804,   805,
     806,   807,   808,   809,    10,   810,   811,  -706,   812,   813,
     814,   815,   816,   817,   818,    38,   819,   820,   821,   822,
     823,   824,   825,  -706,   826,   827,  -706,  -706,   828,   829,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,   830,
     831,   239,   832,   833,   834,  -706,   835,   836,  -706,   837,
     838,   380,   542,   609,  -706,  -706,  -706,   839,   840,  -706,
     841,   842,   460,   843,   844,   845,   846,   847,   848,   849,
    -706,   850,   851,   852,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,   853,   252,  -706,  -706,   854,
     794,   855,  -706,     3,  -706,  -706,  -706,  -706,   856,   858,
     859,   860,  -706,  -706,   861,   522,   862,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -202,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,   653,   653,   653,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -201,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -191,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -175,  -706,   864,   729,   865,
    -706,  -706,  -706,  -706,  -706,  -706,   612,  -706,   786,   863,
    -706,   866,  -706,   867,   868,  -706,  -706,   869,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -155,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -154,  -706,  -706,   857,  -176,   871,   874,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,    56,  -706,  -706,  -706,   -40,
    -706,  -706,  -706,  -706,    38,  -706,   239,  -706,   380,  -706,
    -706,  -706,   941,   940,   945,   880,   948,   953,   954,  -706,
     460,  -706,   252,   878,   879,   881,   473,  -706,  -706,   522,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,   882,  -706,  -706
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   199,   357,   405,     0,
     420,     0,   265,   396,   239,     0,     0,    92,   142,   294,
       0,     0,   335,     0,   101,     0,   311,     3,     4,     5,
      13,     6,    25,    26,     7,     8,    10,    11,    12,    15,
      16,    17,    18,    19,    20,    21,    22,    24,    23,     9,
      14,    27,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    85,    87,    86,   547,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   531,   546,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   532,   533,   543,   544,   545,     0,
       0,     0,   418,     0,     0,   416,   417,     0,   480,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   431,   432,
     433,   470,   438,   471,   465,   466,   467,   468,   442,   434,
     435,   436,   437,   452,   439,   440,   441,   443,   444,   469,
     446,   447,   454,   455,   448,   449,   450,   445,   451,   462,
     463,   464,   460,   461,   453,   458,   459,   456,   457,   472,
     473,   474,   475,   476,   477,   478,   479,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   574,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   565,   566,   567,   568,
     569,   570,   571,   573,   572,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
      68,    66,    57,    67,    59,    60,    61,    62,    63,    64,
      65,    58,     0,     0,     0,     0,   116,   117,   118,     0,
       0,   309,     0,     0,   307,   308,     0,    88,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   530,
       0,     0,     0,     0,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   203,   206,
     208,   209,   210,   211,   212,   213,   214,   204,   205,   207,
     215,   216,   217,     0,     0,     0,     0,     0,     0,     0,
     386,     0,     0,     0,     0,     0,     0,     0,     0,   360,
     361,   362,   363,   364,   365,   366,   367,   369,   368,   370,
     374,   371,   372,   373,   411,     0,     0,     0,   408,   409,
     410,     0,     0,   415,   426,     0,     0,     0,   423,   424,
     425,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     430,     0,     0,     0,   280,     0,     0,     0,     0,   268,
     269,   270,   271,   274,   272,   273,   402,     0,     0,     0,
     399,   400,   401,     0,     0,     0,   241,     0,   253,     0,
     251,   252,   254,   255,    53,    52,    49,    51,    46,    45,
       0,     0,     0,     0,    95,    96,    97,     0,     0,     0,
     166,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,   148,   149,   152,   153,   154,   151,   150,   155,
       0,     0,     0,     0,     0,   297,   298,   299,   300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   564,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,   343,     0,   338,   339,
     340,   119,     0,     0,   115,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   107,   106,   108,     0,     0,   306,
       0,     0,   321,     0,     0,   314,   315,   316,   317,     0,
       0,     0,    82,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   529,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   375,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,     0,     0,     0,   407,     0,
     414,     0,     0,     0,   422,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   429,   275,     0,     0,     0,     0,     0,
       0,     0,   267,     0,     0,     0,   398,   256,     0,     0,
       0,     0,     0,   250,     0,    98,     0,     0,     0,    94,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   301,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,   563,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,   341,     0,     0,     0,   337,     0,   114,     0,   109,
       0,     0,     0,     0,     0,   103,     0,   305,   318,     0,
       0,     0,     0,   313,    91,    90,    89,   561,    29,    29,
      29,    29,    29,    29,    29,    31,    30,   562,   548,   549,
     550,   551,   552,   553,   554,   555,   558,   559,   556,   557,
     560,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     0,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   358,     0,     0,   406,   419,     0,     0,
     421,   491,   496,   481,   482,   504,   521,   522,   523,   524,
     525,   526,   485,   519,   520,   513,   512,   486,   487,   527,
     499,   490,   488,   489,   494,   495,   483,   493,   492,   510,
     517,   518,   508,   516,   505,   503,   506,   511,   528,   507,
     509,   501,   502,   514,   515,   498,   497,   500,   484,     0,
       0,     0,     0,     0,     0,   266,     0,     0,   397,     0,
       0,     0,   261,   257,   260,   240,    50,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,     0,     0,     0,   295,   578,   575,   576,   577,   582,
     581,   579,   580,    77,    74,    81,    73,    78,    79,    80,
      72,    76,    75,    70,    71,     0,     0,   336,   120,     0,
       0,     0,   132,     0,   124,   125,   127,   126,     0,     0,
       0,     0,   102,   310,     0,     0,     0,   312,    32,    33,
      34,    35,    36,    37,    38,   228,   229,   223,   238,   237,
       0,   236,   224,   232,   225,   231,   219,   230,   222,   221,
     220,    39,    39,    39,    41,    40,   226,   227,   381,   384,
     385,   395,   392,   377,   393,   390,   391,     0,   389,   394,
     376,   383,   380,   379,   378,   382,   412,   413,   427,   428,
     278,   279,   288,   284,   285,   287,   292,   289,   290,   291,
     286,     0,   283,   277,   293,   276,   404,   403,   264,   263,
     248,   249,   246,   247,   245,     0,   244,     0,     0,     0,
      99,   100,   164,   161,   186,   197,   173,   182,     0,   171,
     176,     0,   191,     0,   185,   189,   195,   175,   178,   187,
     188,   192,   183,   190,   179,   196,   181,   177,   180,     0,
     169,   157,   159,   165,   162,   163,   158,   160,   304,   302,
     303,   342,   347,   353,   356,   349,   355,   350,   354,   352,
     348,   351,     0,   346,   128,     0,     0,     0,     0,   123,
     111,   110,   112,   113,   319,   325,   331,   334,   327,   333,
     328,   332,   330,   326,   329,     0,   324,   320,   234,     0,
      42,    43,    44,   387,     0,   281,     0,   242,     0,   262,
     259,   258,     0,     0,     0,     0,     0,     0,     0,   167,
       0,   344,     0,     0,     0,     0,     0,   122,   322,     0,
     235,   388,   282,   243,   172,   194,   170,   198,   193,   184,
     174,   168,   345,   129,   131,   130,   140,   139,   135,   137,
     141,   138,   134,   136,     0,   323,   133
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -706,  -706,  -706,  -256,  -302,  -705,  -624,  -706,  -706,   906,
    -706,  -706,    20,  -706,  -706,   480,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
     664,  -706,  -706,  -706,  -706,  -706,  -706,   327,  -706,  -706,
    -706,  -706,  -706,   176,  -706,  -706,  -706,  -706,  -706,  -706,
     469,  -706,  -706,  -706,  -706,  -142,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,   376,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -287,  -706,  -706,
    -706,   785,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -255,
    -706,  -706,  -706,  -706,  -706,  -185,  -706,   625,  -706,  -706,
    -706,   -90,  -706,  -706,  -706,  -706,  -706,   547,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,   -61,  -706,  -706,  -706,  -706,
     574,  -706,  -706,  -706,  -706,  -706,   870,  -706,  -706,  -706,
    -706,   515,  -706,  -706,  -706,  -706,  -706,   -79,  -706,  -706,
    -706,   549,  -706,  -706,  -706,  -706,   -71,  -706,  -706,  -706,
     872,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,   -52,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,   646,  -706,  -706,  -706,  -706,  -706,   726,  -706,  -706,
    -706,  -706,   979,  -706,  -706,  -706,  -706,   727,  -706,  -706,
    -706,  -706,   928,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  1005,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,   873,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,   805,   806,  1014,  1015,    28,    29,    65,
     231,   486,   487,    30,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,    31,    81,
      82,    83,    84,    85,    32,    67,   493,   494,   495,   496,
      33,    74,   571,   572,   573,   574,   575,   576,    34,   285,
     286,   287,   288,   289,   973,   974,   975,   976,   977,  1127,
    1204,    35,    68,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   733,  1099,  1100,    36,    55,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   614,  1000,  1001,
      37,    63,   478,   720,  1065,  1066,   479,   480,   481,  1069,
     923,   924,   482,   483,    38,    61,   458,   459,   460,   461,
     462,   463,   464,   707,  1051,  1052,   465,    39,    69,   524,
     525,   526,   527,   528,    40,   293,   294,   295,    41,    76,
     584,   585,   586,   587,   588,   790,  1145,  1146,    42,    72,
     557,   558,   559,   560,   773,  1122,  1123,    43,    56,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   635,  1027,  1028,   380,   381,   382,   383,    44,    62,
     469,   470,   471,   472,    45,    57,   387,   388,   389,   390,
      46,   124,   125,   126,    47,    59,   397,   398,   399,   400,
      48,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,    49,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    50,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     835,   836,   595,   520,   969,   598,   599,   600,    77,   602,
     603,  1174,   580,  1148,  1153,    86,   122,  1149,  1154,   998,
     566,  1011,  1012,  1013,  1155,   384,    51,    52,  1156,   384,
     466,   798,   799,   800,   801,   802,   803,   804,   834,    53,
    1157,   291,   554,    54,  1158,    78,  1025,    87,    88,   128,
      58,   521,   122,    79,   129,   130,    89,   131,   132,   451,
    1169,  1171,   133,    60,  1170,  1172,    64,   283,   291,   134,
     135,   136,   137,   138,   139,   484,   485,   452,   140,   141,
     142,    90,    91,    92,    93,    66,   123,   283,   143,   144,
     522,   466,   145,   146,   999,   385,    94,    95,    96,   385,
     656,   594,   658,   659,    70,   453,    97,    98,    99,   580,
     100,   101,   668,   147,   148,    71,   970,   673,    73,   675,
      80,    75,   123,   490,   581,   149,   682,   473,   150,   151,
     554,   454,   567,   689,   690,   119,   692,   523,   152,   153,
     497,   236,   698,   699,   700,   320,   154,   155,   353,   156,
     354,   157,   355,   292,   555,   158,   159,   394,   498,   386,
     120,   321,   322,   386,   467,   969,   356,   160,   490,    77,
     839,   840,   161,   323,   162,   163,   164,   121,   127,   165,
     292,   394,   568,   237,   166,   971,   499,   455,   474,   255,
     238,   239,   240,   569,   357,   241,   242,   475,   227,   476,
     243,   244,   570,   167,   168,   972,    78,   169,   170,   358,
     491,   359,   500,   582,    79,   456,   583,   324,   747,  1128,
     360,   581,  1026,   256,   834,   467,   257,   792,   228,   751,
     318,   392,   361,  -121,   468,   784,   520,   229,   325,   326,
     171,   172,   555,   556,   647,   715,   327,   173,   174,   230,
     328,   258,   501,  -121,  1042,   491,   175,   329,   176,   477,
     362,   297,   259,   457,   449,   330,   331,   332,   502,   395,
     284,  1178,   233,   234,   711,  1179,   333,   970,   298,   235,
     363,    80,   563,   578,   521,   282,   299,  1043,   260,   492,
     284,   396,   261,   395,   566,   468,   334,   290,   364,   296,
     262,   263,   300,   488,   264,   265,  1150,  1151,  1152,   365,
     582,   823,   303,   583,   826,   396,   828,   304,  1044,   305,
     335,   833,   306,   522,   503,   596,   307,   308,   309,   310,
    1112,   556,   311,   497,   492,   504,   312,   505,   728,   851,
     313,   366,   722,   367,   506,   774,   971,   314,   507,   451,
     315,   498,   316,  1045,  1046,   741,   537,   489,   473,  1047,
     626,   539,   317,   643,   561,   391,   972,   452,   128,   401,
     523,   402,   653,   129,   130,   403,   131,   132,   404,   499,
     405,   133,  1048,   266,   301,   267,   406,   407,   134,   135,
     136,   137,   138,   139,  1113,   453,   408,   140,   141,   142,
    1060,   409,   410,   411,   552,   500,   567,   143,   144,   255,
     412,   145,   146,  1114,   413,   414,  1061,   415,  1115,   474,
     416,   454,   417,  1116,   418,   419,   420,   421,   475,  1049,
     476,   422,   147,   148,   423,  1062,   424,   425,  1117,   426,
    1118,  1119,   427,   256,   149,   501,   257,   150,   151,   428,
     429,  1050,   565,   430,   431,  1120,   568,   152,   153,   432,
     433,   502,   434,  1121,  1074,   154,   155,   569,   156,   592,
     157,   258,   435,   436,   158,   159,   570,   455,   437,   438,
     439,   440,   259,   441,   442,   443,   160,  1075,  1076,   444,
     477,   161,   445,   162,   163,   164,   446,   447,   165,  1077,
     448,   529,  1175,   166,   530,   456,   531,   532,   260,   533,
     593,   353,   261,   354,   534,   355,   535,   503,   536,   540,
     262,   263,   167,   168,   264,   265,   169,   170,   504,   356,
     505,   236,   541,   542,   543,  1078,  1079,   506,  1080,   544,
     545,   507,   988,   989,   990,   991,   992,   993,   994,  1196,
     546,  1197,   547,   457,   548,   549,   550,   357,  1063,   171,
     172,   551,   562,   577,  1064,  1081,   173,   174,   589,  1082,
     594,   590,   358,   237,   359,   175,   591,   176,  1083,   597,
     238,   239,   240,   360,   601,   241,   242,   604,   605,   606,
     243,   244,   607,   608,   611,   361,   609,  1084,  1198,  1085,
    1135,   610,  1086,   266,   612,   267,   613,   615,   320,   616,
     617,   618,   619,     2,     3,  1199,   620,     4,  1087,   621,
     622,   623,   624,   362,   321,   322,  1088,   625,  1089,     5,
     628,  1090,     6,  1091,   629,   630,   323,  1092,  1200,  1201,
    1093,     7,   631,   363,   632,   633,  1094,   634,  1095,  1096,
       8,   636,   637,   638,   639,   640,   641,   642,   645,   646,
     649,   364,     9,  1097,  1136,   650,    10,    11,   651,   652,
     655,  1098,   365,   657,   660,   661,   662,   663,  1202,   664,
     324,   665,   666,  1137,  1203,    12,   667,   669,  1138,    13,
     670,   671,   672,  1139,   674,   676,   677,   686,   678,    14,
      15,   325,   326,   679,   366,   687,   367,   680,  1140,   327,
    1141,  1142,   681,   328,   683,   684,   685,   688,   691,   693,
     329,   694,   695,    16,    17,  1143,   696,   697,   330,   331,
     332,    86,   701,  1144,   702,   705,   703,   778,    18,   333,
     704,   706,   724,  1067,   926,   302,   708,   785,   553,   709,
     710,   713,   717,   714,   564,    19,   718,   719,   758,   334,
     721,   725,   726,    87,    88,   727,    20,    21,   730,   731,
     743,   732,    89,   734,   735,   736,   737,    22,   738,   739,
     740,   744,   745,   335,   746,    23,   749,   750,    24,   752,
     753,   754,    25,   755,    26,   756,   757,    90,    91,    92,
      93,   759,   760,   761,   770,   762,   763,   764,   771,   776,
     765,   766,    94,    95,    96,   821,   767,   772,   768,   769,
     729,   786,    97,    98,    99,   777,   100,   101,  1068,   779,
    1162,  1129,   780,   781,   782,   787,   783,   788,   789,   794,
     791,   795,   796,   797,   807,   808,   809,   810,   811,   812,
     813,   814,   815,   816,   817,   818,   819,   820,   822,   825,
     824,   827,   829,   837,   830,   831,   832,   834,   838,   841,
     842,   843,   844,   846,   845,   847,   853,   848,   849,   850,
     852,   854,   855,  1191,   742,   856,   857,   858,   859,   911,
     921,   860,   861,   862,  1180,   863,   864,   865,   866,   867,
     868,   869,   870,   871,   872,   873,   874,   875,   876,   877,
     878,   879,   880,   881,   882,   883,   884,   885,   886,   887,
     888,   889,   890,   891,   892,   893,   894,   895,   896,   897,
     898,   899,   900,   901,   902,   903,   904,   905,   906,   907,
     908,   909,   910,   922,   912,   913,   914,   931,   916,   915,
     917,   918,   919,   920,   937,   927,   925,   928,   929,   930,
     933,   934,   932,   935,   940,   936,   938,   939,   941,  1187,
     942,   943,   232,  1183,   944,   945,   946,   947,  1160,   948,
     949,   950,   951,   952,   953,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   963,   964,   965,   967,   966,   968,
     978,   979,   980,   981,  1163,   712,   982,   983,   984,   986,
     985,  1125,   987,   995,   996,   997,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,  1016,  1017,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1029,  1030,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1053,  1054,  1055,
    1056,  1057,  1058,  1059,  1070,  1071,  1072,  1073,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1124,
    1173,  1130,  1126,  1131,  1132,  1133,  1134,  1147,  1159,  1184,
    1161,  1164,  1185,  1186,  1165,  1166,  1167,  1168,  1176,  1177,
    1188,  1189,  1190,  1193,  1194,  1182,  1195,  1206,   748,   793,
    1205,  1192,  1181,   393,   723,   450,   775,   319,     0,     0,
       0,     0,     0,   648,     0,   716,     0,     0,   538,     0,
       0,   627,     0,     0,   654,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     644
};

static const yytype_int16 yycheck[] =
{
     624,   625,   304,     1,     1,   307,   308,   309,     1,   311,
     312,   187,     1,   215,   215,     1,     1,   219,   219,    59,
       1,    11,    12,    13,   215,     1,   215,   216,   219,     1,
       1,   144,   145,   146,   147,   148,   149,   150,   214,   220,
     215,     1,     1,   220,   219,    38,     8,    33,    34,     1,
     220,    49,     1,    46,     6,     7,    42,     9,    10,     1,
     215,   215,    14,   220,   219,   219,   213,     1,     1,    21,
      22,    23,    24,    25,    26,   140,   141,    19,    30,    31,
      32,    67,    68,    69,    70,   217,    71,     1,    40,    41,
      88,     1,    44,    45,   134,    71,    82,    83,    84,    71,
     402,   214,   404,   405,   220,    47,    92,    93,    94,     1,
      96,    97,   414,    65,    66,   220,   113,   419,   220,   421,
     113,   220,    71,     1,   113,    77,   428,     1,    80,    81,
       1,    73,   113,   435,   436,   220,   438,   135,    90,    91,
       1,     1,   444,   445,   446,     1,    98,    99,     1,   101,
       3,   103,     5,   113,   113,   107,   108,     1,    19,   135,
     220,    17,    18,   135,   135,     1,    19,   119,     1,     1,
     169,   170,   124,    29,   126,   127,   128,   220,   220,   131,
     113,     1,   163,    43,   136,   182,    47,   129,    62,     1,
      50,    51,    52,   174,    47,    55,    56,    71,   220,    73,
      60,    61,   183,   155,   156,   202,    38,   159,   160,    62,
      88,    64,    73,   202,    46,   157,   205,    73,   216,   216,
      73,   113,   184,    35,   214,   135,    38,   216,   220,   531,
     216,   216,    85,   167,   205,   216,     1,   220,    94,    95,
     192,   193,   113,   202,   216,   216,   102,   199,   200,   218,
     106,    63,   113,   167,    15,    88,   208,   113,   210,   133,
     113,   215,    74,   205,   216,   121,   122,   123,   129,   113,
     204,   215,   220,   220,   216,   219,   132,   113,   217,   220,
     133,   113,   216,   216,    49,   220,   217,    48,   100,   167,
     204,   135,   104,   113,     1,   205,   152,   220,   151,   220,
     112,   113,   217,   215,   116,   117,  1011,  1012,  1013,   162,
     202,   613,   217,   205,   616,   135,   618,   217,    79,   217,
     176,   623,   217,    88,   185,   191,   217,   217,   217,   217,
      78,   202,   217,     1,   167,   196,   217,   198,   216,   641,
     217,   194,   216,   196,   205,   216,   182,   217,   209,     1,
     217,    19,   217,   114,   115,   216,   216,   215,     1,   120,
     216,   215,   217,   216,   215,   217,   202,    19,     1,   217,
     135,   217,   216,     6,     7,   217,     9,    10,   217,    47,
     217,    14,   143,   195,   216,   197,   217,   217,    21,    22,
      23,    24,    25,    26,   142,    47,   217,    30,    31,    32,
      20,   217,   217,   217,   216,    73,   113,    40,    41,     1,
     217,    44,    45,   161,   217,   217,    36,   217,   166,    62,
     217,    73,   217,   171,   217,   217,   217,   217,    71,   190,
      73,   217,    65,    66,   217,    55,   217,   217,   186,   217,
     188,   189,   217,    35,    77,   113,    38,    80,    81,   217,
     217,   212,   167,   217,   217,   203,   163,    90,    91,   217,
     217,   129,   217,   211,     4,    98,    99,   174,   101,   215,
     103,    63,   217,   217,   107,   108,   183,   129,   217,   217,
     217,   217,    74,   217,   217,   217,   119,    27,    28,   217,
     133,   124,   217,   126,   127,   128,   217,   217,   131,    39,
     217,   217,  1126,   136,   217,   157,   217,   217,   100,   217,
     214,     1,   104,     3,   217,     5,   217,   185,   217,   217,
     112,   113,   155,   156,   116,   117,   159,   160,   196,    19,
     198,     1,   217,   217,   217,    75,    76,   205,    78,   217,
     217,   209,   798,   799,   800,   801,   802,   803,   804,    76,
     217,    78,   217,   205,   217,   217,   217,    47,   178,   192,
     193,   217,   217,   217,   184,   105,   199,   200,   213,   109,
     214,   213,    62,    43,    64,   208,   213,   210,   118,   214,
      50,    51,    52,    73,   214,    55,    56,   214,   214,   214,
      60,    61,   214,   214,   217,    85,   215,   137,   125,   139,
      78,   215,   142,   195,   217,   197,   217,   217,     1,   217,
     217,   217,   217,     0,     1,   142,   217,     4,   158,   217,
     217,   217,   217,   113,    17,    18,   166,   217,   168,    16,
     215,   171,    19,   173,   217,   217,    29,   177,   165,   166,
     180,    28,   217,   133,   217,   217,   186,   217,   188,   189,
      37,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     213,   151,    49,   203,   142,   215,    53,    54,   217,   217,
     191,   211,   162,   214,   191,   214,   214,   214,   205,   213,
      73,   213,   191,   161,   211,    72,   214,   191,   166,    76,
     191,   214,   214,   171,   191,   214,   214,   191,   214,    86,
      87,    94,    95,   214,   194,   213,   196,   214,   186,   102,
     188,   189,   214,   106,   214,   214,   214,   191,   191,   191,
     113,   214,   191,   110,   111,   203,   191,   214,   121,   122,
     123,     1,   191,   211,   214,   217,   215,   220,   125,   132,
     215,   217,   219,   201,   724,    81,   217,   571,   268,   217,
     217,   217,   215,   217,   285,   142,   217,   217,   214,   152,
     217,   215,   217,    33,    34,   217,   153,   154,   215,   217,
     215,   217,    42,   217,   217,   217,   217,   164,   217,   217,
     217,   217,   217,   176,   217,   172,   191,   191,   175,   213,
     191,   213,   179,   191,   181,   191,   215,    67,    68,    69,
      70,   213,   191,   213,   215,   214,   214,   213,   215,   191,
     213,   213,    82,    83,    84,   214,   213,   217,   213,   213,
     493,   213,    92,    93,    94,   215,    96,    97,   219,   215,
     218,   973,   217,   217,   217,   215,   217,   215,   217,   215,
     217,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   214,   214,
     217,   214,   213,   215,   214,   214,   214,   214,   213,   213,
     191,   213,   213,   213,   217,   213,   215,   214,   213,   213,
     213,   213,   213,  1170,   508,   215,   215,   213,   213,   217,
     217,   215,   215,   215,  1149,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   213,   191,   214,   213,   213,   213,   191,   213,   215,
     213,   215,   213,   213,   191,   213,   215,   213,   215,   213,
     213,   213,   217,   213,   215,   213,   213,   213,   213,    89,
     213,   213,    66,  1158,   215,   215,   215,   215,  1068,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   213,   215,   217,   215,
     213,   213,   213,   213,   218,   458,   215,   215,   213,   213,
     217,   217,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     213,   215,   217,   215,   215,   215,   215,   215,   214,   138,
     215,   218,   142,   138,   218,   218,   218,   218,   217,   215,
     142,   138,   138,   215,   215,  1156,   215,   215,   524,   584,
    1179,  1172,  1154,   124,   479,   177,   557,   102,    -1,    -1,
      -1,    -1,    -1,   387,    -1,   469,    -1,    -1,   245,    -1,
      -1,   336,    -1,    -1,   397,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     368
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   222,     0,     1,     4,    16,    19,    28,    37,    49,
      53,    54,    72,    76,    86,    87,   110,   111,   125,   142,
     153,   154,   164,   172,   175,   179,   181,   223,   228,   229,
     234,   249,   255,   261,   269,   282,   299,   321,   335,   348,
     355,   359,   369,   378,   399,   405,   411,   415,   421,   472,
     490,   215,   216,   220,   220,   300,   379,   406,   220,   416,
     220,   336,   400,   322,   213,   230,   217,   256,   283,   349,
     220,   220,   370,   220,   262,   220,   360,     1,    38,    46,
     113,   250,   251,   252,   253,   254,     1,    33,    34,    42,
      67,    68,    69,    70,    82,    83,    84,    92,    93,    94,
      96,    97,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   220,
     220,   220,     1,    71,   412,   413,   414,   220,     1,     6,
       7,     9,    10,    14,    21,    22,    23,    24,    25,    26,
      30,    31,    32,    40,    41,    44,    45,    65,    66,    77,
      80,    81,    90,    91,    98,    99,   101,   103,   107,   108,
     119,   124,   126,   127,   128,   131,   136,   155,   156,   159,
     160,   192,   193,   199,   200,   208,   210,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   220,   220,   220,
     218,   231,   230,   220,   220,   220,     1,    43,    50,    51,
      52,    55,    56,    60,    61,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,     1,    35,    38,    63,    74,
     100,   104,   112,   113,   116,   117,   195,   197,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   220,     1,   204,   270,   271,   272,   273,   274,
     220,     1,   113,   356,   357,   358,   220,   215,   217,   217,
     217,   216,   251,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   216,   474,
       1,    17,    18,    29,    73,    94,    95,   102,   106,   113,
     121,   122,   123,   132,   152,   176,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,     1,     3,     5,    19,    47,    62,    64,
      73,    85,   113,   133,   151,   162,   194,   196,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     395,   396,   397,   398,     1,    71,   135,   407,   408,   409,
     410,   217,   216,   413,     1,   113,   135,   417,   418,   419,
     420,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   216,
     423,     1,    19,    47,    73,   129,   157,   205,   337,   338,
     339,   340,   341,   342,   343,   347,     1,   135,   205,   401,
     402,   403,   404,     1,    62,    71,    73,   133,   323,   327,
     328,   329,   333,   334,   140,   141,   232,   233,   215,   215,
       1,    88,   167,   257,   258,   259,   260,     1,    19,    47,
      73,   113,   129,   185,   196,   198,   205,   209,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
       1,    49,    88,   135,   350,   351,   352,   353,   354,   217,
     217,   217,   217,   217,   217,   217,   217,   216,   492,   215,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   216,   236,     1,   113,   202,   371,   372,   373,
     374,   215,   217,   216,   271,   167,     1,   113,   163,   174,
     183,   263,   264,   265,   266,   267,   268,   217,   216,   357,
       1,   113,   202,   205,   361,   362,   363,   364,   365,   213,
     213,   213,   215,   214,   214,   225,   191,   214,   225,   225,
     225,   214,   225,   225,   214,   214,   214,   214,   214,   215,
     215,   217,   217,   217,   318,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   216,   302,   215,   217,
     217,   217,   217,   217,   217,   392,   217,   217,   217,   217,
     217,   217,   217,   216,   381,   217,   217,   216,   408,   213,
     215,   217,   217,   216,   418,   191,   225,   214,   225,   225,
     191,   214,   214,   214,   213,   213,   191,   214,   225,   191,
     191,   214,   214,   225,   191,   225,   214,   214,   214,   214,
     214,   214,   225,   214,   214,   214,   191,   213,   191,   225,
     225,   191,   225,   191,   214,   191,   191,   214,   225,   225,
     225,   191,   214,   215,   215,   217,   217,   344,   217,   217,
     217,   216,   338,   217,   217,   216,   402,   215,   217,   217,
     324,   217,   216,   328,   219,   215,   217,   217,   216,   258,
     215,   217,   217,   296,   217,   217,   217,   217,   217,   217,
     217,   216,   285,   215,   217,   217,   217,   216,   351,   191,
     191,   225,   213,   191,   213,   191,   191,   215,   214,   213,
     191,   213,   214,   214,   213,   213,   213,   213,   213,   213,
     215,   215,   217,   375,   216,   372,   191,   215,   220,   215,
     217,   217,   217,   217,   216,   264,   213,   215,   215,   217,
     366,   217,   216,   362,   215,   215,   215,   215,   144,   145,
     146,   147,   148,   149,   150,   224,   225,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   214,   214,   225,   217,   214,   225,   214,   225,   213,
     214,   214,   214,   225,   214,   227,   227,   215,   213,   169,
     170,   213,   191,   213,   213,   217,   213,   213,   214,   213,
     213,   225,   213,   215,   213,   213,   215,   215,   213,   213,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   213,
     191,   217,   213,   213,   213,   215,   213,   213,   215,   213,
     213,   217,   214,   331,   332,   215,   233,   213,   213,   215,
     213,   191,   217,   213,   213,   213,   213,   191,   213,   213,
     215,   213,   213,   213,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   213,   217,   215,   215,     1,
     113,   182,   202,   275,   276,   277,   278,   279,   213,   213,
     213,   213,   215,   215,   213,   217,   213,   215,   224,   224,
     224,   224,   224,   224,   224,   215,   215,   215,    59,   134,
     319,   320,   215,   215,   215,   215,   215,   215,   215,   215,
     215,    11,    12,    13,   226,   227,   215,   215,   215,   215,
     215,   215,   215,   215,   215,     8,   184,   393,   394,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,    15,    48,    79,   114,   115,   120,   143,   190,
     212,   345,   346,   215,   215,   215,   215,   215,   215,   215,
      20,    36,    55,   178,   184,   325,   326,   201,   219,   330,
     215,   215,   215,   215,     4,    27,    28,    39,    75,    76,
      78,   105,   109,   118,   137,   139,   142,   158,   166,   168,
     171,   173,   177,   180,   186,   188,   189,   203,   211,   297,
     298,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,    78,   142,   161,   166,   171,   186,   188,   189,
     203,   211,   376,   377,   215,   217,   217,   280,   216,   276,
     215,   215,   215,   215,   215,    78,   142,   161,   166,   171,
     186,   188,   189,   203,   211,   367,   368,   215,   215,   219,
     226,   226,   226,   215,   219,   215,   219,   215,   219,   214,
     332,   215,   218,   218,   218,   218,   218,   218,   218,   215,
     219,   215,   219,   213,   187,   227,   217,   215,   215,   219,
     320,   394,   346,   326,   138,   142,   138,    89,   142,   138,
     138,   298,   377,   215,   215,   215,    76,    78,   125,   142,
     165,   166,   205,   211,   281,   368,   215
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
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   250,   251,   251,   251,   251,   252,
     253,   254,   256,   255,   257,   257,   258,   258,   258,   259,
     260,   262,   261,   263,   263,   264,   264,   264,   264,   264,
     265,   266,   267,   268,   269,   270,   270,   271,   271,   271,
     272,   274,   273,   275,   275,   276,   276,   276,   276,   277,
     278,   278,   280,   279,   281,   281,   281,   281,   281,   281,
     281,   281,   283,   282,   284,   284,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   296,   295,   297,   297,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   300,
     299,   301,   301,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   318,   317,   319,   319,   320,   320,   322,
     321,   324,   323,   325,   325,   326,   326,   326,   326,   326,
     327,   327,   328,   328,   328,   328,   328,   330,   329,   331,
     331,   332,   332,   333,   334,   336,   335,   337,   337,   338,
     338,   338,   338,   338,   338,   338,   339,   340,   341,   342,
     344,   343,   345,   345,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   347,   349,   348,   350,   350,   351,   351,
     351,   351,   352,   353,   354,   355,   356,   356,   357,   357,
     358,   360,   359,   361,   361,   362,   362,   362,   362,   363,
     364,   366,   365,   367,   367,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   370,   369,   371,   371,   372,
     372,   372,   373,   375,   374,   376,   376,   377,   377,   377,
     377,   377,   377,   377,   377,   377,   377,   379,   378,   380,
     380,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   390,   392,   391,   393,   393,
     394,   394,   395,   396,   397,   398,   400,   399,   401,   401,
     402,   402,   402,   403,   404,   406,   405,   407,   407,   408,
     408,   408,   409,   410,   411,   412,   412,   413,   413,   414,
     416,   415,   417,   417,   418,   418,   418,   419,   420,   421,
     422,   422,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   473,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   475,   476,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     0,     6,     2,     1,     1,     1,     2,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     2,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     0,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     3,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     0,
       6,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     0,     5,     3,
       1,     1,     3,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     2,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     4,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
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
#line 3142 "conf_parser.c"
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
#line 3415 "conf_parser.c"
    break;

  case 31: /* timespec: NUMBER timespec_  */
#line 385 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3421 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER SECONDS timespec_  */
#line 386 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3427 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER MINUTES timespec_  */
#line 387 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3433 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER HOURS timespec_  */
#line 388 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3439 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER DAYS timespec_  */
#line 389 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3445 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER WEEKS timespec_  */
#line 390 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3451 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER MONTHS timespec_  */
#line 391 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3457 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER YEARS timespec_  */
#line 392 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3463 "conf_parser.c"
    break;

  case 39: /* sizespec_: %empty  */
#line 395 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3469 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER sizespec_  */
#line 396 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3475 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER BYTES sizespec_  */
#line 397 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3481 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER KBYTES sizespec_  */
#line 398 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3487 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER MBYTES sizespec_  */
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3493 "conf_parser.c"
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
#line 3510 "conf_parser.c"
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
#line 3527 "conf_parser.c"
    break;

  case 47: /* module_string: QSTRING  */
#line 440 "conf_parser.y"
{
  (yyval.string) = io_strdup((yyvsp[0].string));
}
#line 3535 "conf_parser.c"
    break;

  case 48: /* module_attributes: %empty  */
#line 445 "conf_parser.y"
{
  (yyval.number) = 0;
}
#line 3543 "conf_parser.c"
    break;

  case 49: /* module_attributes: ':' module_attributes_items  */
#line 448 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3551 "conf_parser.c"
    break;

  case 50: /* module_attributes_items: module_attributes_items ',' module_attributes_item  */
#line 453 "conf_parser.y"
{
  (yyval.number) = (yyvsp[-2].number) | (yyvsp[0].number);
}
#line 3559 "conf_parser.c"
    break;

  case 51: /* module_attributes_items: module_attributes_item  */
#line 456 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3567 "conf_parser.c"
    break;

  case 52: /* module_attributes_item: RESIDENT  */
#line 461 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_DEACTIVATE;
}
#line 3575 "conf_parser.c"
    break;

  case 53: /* module_attributes_item: REQUIRED  */
#line 464 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_REMOVE;
}
#line 3583 "conf_parser.c"
    break;

  case 70: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 491 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3595 "conf_parser.c"
    break;

  case 71: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 500 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3607 "conf_parser.c"
    break;

  case 72: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 509 "conf_parser.y"
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
#line 3625 "conf_parser.c"
    break;

  case 73: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 524 "conf_parser.y"
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
#line 3643 "conf_parser.c"
    break;

  case 74: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 539 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3656 "conf_parser.c"
    break;

  case 75: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 549 "conf_parser.y"
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
#line 3673 "conf_parser.c"
    break;

  case 76: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 563 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3685 "conf_parser.c"
    break;

  case 77: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 572 "conf_parser.y"
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
#line 3711 "conf_parser.c"
    break;

  case 78: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 595 "conf_parser.y"
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
#line 3737 "conf_parser.c"
    break;

  case 79: /* serverinfo_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 618 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigServerInfo.max_topic_length = TOPICLEN;
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3748 "conf_parser.c"
    break;

  case 80: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 626 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3760 "conf_parser.c"
    break;

  case 81: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 635 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3769 "conf_parser.c"
    break;

  case 89: /* admin_name: NAME '=' QSTRING ';'  */
#line 653 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3781 "conf_parser.c"
    break;

  case 90: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 662 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3793 "conf_parser.c"
    break;

  case 91: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 671 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3805 "conf_parser.c"
    break;

  case 92: /* $@1: %empty  */
#line 684 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3814 "conf_parser.c"
    break;

  case 93: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 688 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3831 "conf_parser.c"
    break;

  case 99: /* motd_mask: MASK '=' QSTRING ';'  */
#line 705 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3840 "conf_parser.c"
    break;

  case 100: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 711 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3849 "conf_parser.c"
    break;

  case 101: /* $@2: %empty  */
#line 721 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3858 "conf_parser.c"
    break;

  case 102: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 725 "conf_parser.y"
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
#line 3876 "conf_parser.c"
    break;

  case 110: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 743 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3885 "conf_parser.c"
    break;

  case 111: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 749 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3894 "conf_parser.c"
    break;

  case 112: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 755 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3903 "conf_parser.c"
    break;

  case 113: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 761 "conf_parser.y"
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
#line 3925 "conf_parser.c"
    break;

  case 120: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 790 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 3937 "conf_parser.c"
    break;

  case 121: /* $@3: %empty  */
#line 799 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3946 "conf_parser.c"
    break;

  case 122: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 803 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3959 "conf_parser.c"
    break;

  case 129: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 819 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3970 "conf_parser.c"
    break;

  case 130: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 827 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3978 "conf_parser.c"
    break;

  case 131: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 830 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3986 "conf_parser.c"
    break;

  case 132: /* $@4: %empty  */
#line 835 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3995 "conf_parser.c"
    break;

  case 134: /* logging_file_type_item: USER  */
#line 841 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4004 "conf_parser.c"
    break;

  case 135: /* logging_file_type_item: OPERATOR  */
#line 845 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4013 "conf_parser.c"
    break;

  case 136: /* logging_file_type_item: XLINE  */
#line 849 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4022 "conf_parser.c"
    break;

  case 137: /* logging_file_type_item: RESV  */
#line 853 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4031 "conf_parser.c"
    break;

  case 138: /* logging_file_type_item: T_DLINE  */
#line 857 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4040 "conf_parser.c"
    break;

  case 139: /* logging_file_type_item: KLINE  */
#line 861 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4049 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: KILL  */
#line 865 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4058 "conf_parser.c"
    break;

  case 141: /* logging_file_type_item: T_DEBUG  */
#line 869 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4067 "conf_parser.c"
    break;

  case 142: /* $@5: %empty  */
#line 879 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4079 "conf_parser.c"
    break;

  case 143: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 886 "conf_parser.y"
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
#line 4137 "conf_parser.c"
    break;

  case 157: /* oper_name: NAME '=' QSTRING ';'  */
#line 954 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4146 "conf_parser.c"
    break;

  case 158: /* oper_user: USER '=' QSTRING ';'  */
#line 960 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4155 "conf_parser.c"
    break;

  case 159: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 966 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4164 "conf_parser.c"
    break;

  case 160: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 972 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4173 "conf_parser.c"
    break;

  case 161: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 978 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4187 "conf_parser.c"
    break;

  case 162: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 989 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4196 "conf_parser.c"
    break;

  case 163: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 995 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4210 "conf_parser.c"
    break;

  case 164: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1006 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4219 "conf_parser.c"
    break;

  case 165: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1012 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4228 "conf_parser.c"
    break;

  case 166: /* $@6: %empty  */
#line 1018 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4237 "conf_parser.c"
    break;

  case 170: /* oper_flags_item: KILL ':' REMOTE  */
#line 1025 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4246 "conf_parser.c"
    break;

  case 171: /* oper_flags_item: KILL  */
#line 1029 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4255 "conf_parser.c"
    break;

  case 172: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1033 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4264 "conf_parser.c"
    break;

  case 173: /* oper_flags_item: CONNECT  */
#line 1037 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4273 "conf_parser.c"
    break;

  case 174: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1041 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4282 "conf_parser.c"
    break;

  case 175: /* oper_flags_item: SQUIT  */
#line 1045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4291 "conf_parser.c"
    break;

  case 176: /* oper_flags_item: KLINE  */
#line 1049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4300 "conf_parser.c"
    break;

  case 177: /* oper_flags_item: UNKLINE  */
#line 1053 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4309 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: T_DLINE  */
#line 1057 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4318 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: T_UNDLINE  */
#line 1061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4327 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: XLINE  */
#line 1065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4336 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: T_UNXLINE  */
#line 1069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4345 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: DIE  */
#line 1073 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4354 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: T_RESTART  */
#line 1077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4363 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4372 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: REHASH  */
#line 1085 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4381 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: ADMIN  */
#line 1089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4390 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_GLOBOPS  */
#line 1093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4399 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: T_LOCOPS  */
#line 1097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4408 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: REMOTEBAN  */
#line 1101 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4417 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: T_SET  */
#line 1105 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4426 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: MODULE  */
#line 1109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4435 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: T_OPME  */
#line 1113 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4444 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: NICK ':' RESV  */
#line 1117 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4453 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: JOIN ':' RESV  */
#line 1121 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4462 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: RESV  */
#line 1125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4471 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_UNRESV  */
#line 1129 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4480 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: CLOSE  */
#line 1133 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4489 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4498 "conf_parser.c"
    break;

  case 199: /* $@7: %empty  */
#line 1147 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.con_freq.value  = CLASS_DEFAULT_CONNECT_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4514 "conf_parser.c"
    break;

  case 200: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1158 "conf_parser.y"
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
#line 4562 "conf_parser.c"
    break;

  case 219: /* class_name: NAME '=' QSTRING ';'  */
#line 1221 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4571 "conf_parser.c"
    break;

  case 220: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1227 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4580 "conf_parser.c"
    break;

  case 221: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1233 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4589 "conf_parser.c"
    break;

  case 222: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1239 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4598 "conf_parser.c"
    break;

  case 223: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1245 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4607 "conf_parser.c"
    break;

  case 224: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1251 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4616 "conf_parser.c"
    break;

  case 225: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1257 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4625 "conf_parser.c"
    break;

  case 226: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1263 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4634 "conf_parser.c"
    break;

  case 227: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1269 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4644 "conf_parser.c"
    break;

  case 228: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1276 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4653 "conf_parser.c"
    break;

  case 229: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1282 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4662 "conf_parser.c"
    break;

  case 230: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1288 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4671 "conf_parser.c"
    break;

  case 231: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1294 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4683 "conf_parser.c"
    break;

  case 232: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1303 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4695 "conf_parser.c"
    break;

  case 233: /* $@8: %empty  */
#line 1312 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4704 "conf_parser.c"
    break;

  case 237: /* class_flags_item: RANDOM_IDLE  */
#line 1319 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4713 "conf_parser.c"
    break;

  case 238: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1323 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4722 "conf_parser.c"
    break;

  case 239: /* $@9: %empty  */
#line 1333 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4731 "conf_parser.c"
    break;

  case 241: /* $@10: %empty  */
#line 1339 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4739 "conf_parser.c"
    break;

  case 245: /* listen_flags_item: T_TLS  */
#line 1345 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4748 "conf_parser.c"
    break;

  case 246: /* listen_flags_item: HIDDEN  */
#line 1349 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4757 "conf_parser.c"
    break;

  case 247: /* listen_flags_item: T_SERVER  */
#line 1353 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4766 "conf_parser.c"
    break;

  case 248: /* listen_flags_item: CLIENT  */
#line 1357 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4775 "conf_parser.c"
    break;

  case 249: /* listen_flags_item: DEFER  */
#line 1361 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4784 "conf_parser.c"
    break;

  case 257: /* $@11: %empty  */
#line 1369 "conf_parser.y"
                                 { reset_block_state(); }
#line 4790 "conf_parser.c"
    break;

  case 261: /* port_item: NUMBER  */
#line 1374 "conf_parser.y"
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
#line 4808 "conf_parser.c"
    break;

  case 262: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1387 "conf_parser.y"
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
#line 4828 "conf_parser.c"
    break;

  case 263: /* listen_address: IP '=' QSTRING ';'  */
#line 1404 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4837 "conf_parser.c"
    break;

  case 264: /* listen_host: HOST '=' QSTRING ';'  */
#line 1410 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4846 "conf_parser.c"
    break;

  case 265: /* $@12: %empty  */
#line 1420 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4855 "conf_parser.c"
    break;

  case 266: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1424 "conf_parser.y"
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
#line 4910 "conf_parser.c"
    break;

  case 276: /* auth_user: USER '=' QSTRING ';'  */
#line 1485 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4919 "conf_parser.c"
    break;

  case 277: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1491 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4928 "conf_parser.c"
    break;

  case 278: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1497 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4937 "conf_parser.c"
    break;

  case 279: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1503 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 4951 "conf_parser.c"
    break;

  case 280: /* $@13: %empty  */
#line 1514 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 4960 "conf_parser.c"
    break;

  case 284: /* auth_flags_item: EXCEED_LIMIT  */
#line 1522 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 4969 "conf_parser.c"
    break;

  case 285: /* auth_flags_item: KLINE_EXEMPT  */
#line 1526 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 4978 "conf_parser.c"
    break;

  case 286: /* auth_flags_item: XLINE_EXEMPT  */
#line 1530 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 4987 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: NEED_IDENT  */
#line 1534 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 4996 "conf_parser.c"
    break;

  case 288: /* auth_flags_item: CAN_FLOOD  */
#line 1538 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 5005 "conf_parser.c"
    break;

  case 289: /* auth_flags_item: NO_TILDE  */
#line 1542 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 5014 "conf_parser.c"
    break;

  case 290: /* auth_flags_item: RESV_EXEMPT  */
#line 1546 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 5023 "conf_parser.c"
    break;

  case 291: /* auth_flags_item: T_WEBIRC  */
#line 1550 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5032 "conf_parser.c"
    break;

  case 292: /* auth_flags_item: NEED_PASSWORD  */
#line 1554 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5041 "conf_parser.c"
    break;

  case 293: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1560 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    log_write(LOG_TYPE_IRCD,
              "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 5056 "conf_parser.c"
    break;

  case 294: /* $@14: %empty  */
#line 1575 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5068 "conf_parser.c"
    break;

  case 295: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1582 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5079 "conf_parser.c"
    break;

  case 302: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1593 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5088 "conf_parser.c"
    break;

  case 303: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1599 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5097 "conf_parser.c"
    break;

  case 304: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1605 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5106 "conf_parser.c"
    break;

  case 310: /* service_name: NAME '=' QSTRING ';'  */
#line 1620 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5121 "conf_parser.c"
    break;

  case 311: /* $@15: %empty  */
#line 1636 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5137 "conf_parser.c"
    break;

  case 312: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1647 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5152 "conf_parser.c"
    break;

  case 319: /* shared_name: NAME '=' QSTRING ';'  */
#line 1662 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5161 "conf_parser.c"
    break;

  case 320: /* shared_user: USER '=' QSTRING ';'  */
#line 1668 "conf_parser.y"
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
#line 5183 "conf_parser.c"
    break;

  case 321: /* $@16: %empty  */
#line 1687 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5192 "conf_parser.c"
    break;

  case 325: /* shared_type_item: KLINE  */
#line 1694 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5201 "conf_parser.c"
    break;

  case 326: /* shared_type_item: UNKLINE  */
#line 1698 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5210 "conf_parser.c"
    break;

  case 327: /* shared_type_item: T_DLINE  */
#line 1702 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5219 "conf_parser.c"
    break;

  case 328: /* shared_type_item: T_UNDLINE  */
#line 1706 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5228 "conf_parser.c"
    break;

  case 329: /* shared_type_item: XLINE  */
#line 1710 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5237 "conf_parser.c"
    break;

  case 330: /* shared_type_item: T_UNXLINE  */
#line 1714 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5246 "conf_parser.c"
    break;

  case 331: /* shared_type_item: RESV  */
#line 1718 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5255 "conf_parser.c"
    break;

  case 332: /* shared_type_item: T_UNRESV  */
#line 1722 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5264 "conf_parser.c"
    break;

  case 333: /* shared_type_item: T_LOCOPS  */
#line 1726 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5273 "conf_parser.c"
    break;

  case 334: /* shared_type_item: T_ALL  */
#line 1730 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5282 "conf_parser.c"
    break;

  case 335: /* $@17: %empty  */
#line 1740 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5296 "conf_parser.c"
    break;

  case 336: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1749 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5309 "conf_parser.c"
    break;

  case 342: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1762 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5318 "conf_parser.c"
    break;

  case 343: /* $@18: %empty  */
#line 1768 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5327 "conf_parser.c"
    break;

  case 347: /* cluster_type_item: KLINE  */
#line 1775 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5336 "conf_parser.c"
    break;

  case 348: /* cluster_type_item: UNKLINE  */
#line 1779 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5345 "conf_parser.c"
    break;

  case 349: /* cluster_type_item: T_DLINE  */
#line 1783 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5354 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: T_UNDLINE  */
#line 1787 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5363 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: XLINE  */
#line 1791 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5372 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: T_UNXLINE  */
#line 1795 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5381 "conf_parser.c"
    break;

  case 353: /* cluster_type_item: RESV  */
#line 1799 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5390 "conf_parser.c"
    break;

  case 354: /* cluster_type_item: T_UNRESV  */
#line 1803 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5399 "conf_parser.c"
    break;

  case 355: /* cluster_type_item: T_LOCOPS  */
#line 1807 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5408 "conf_parser.c"
    break;

  case 356: /* cluster_type_item: T_ALL  */
#line 1811 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5417 "conf_parser.c"
    break;

  case 357: /* $@19: %empty  */
#line 1821 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5431 "conf_parser.c"
    break;

  case 358: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1830 "conf_parser.y"
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
#line 5479 "conf_parser.c"
    break;

  case 376: /* connect_name: NAME '=' QSTRING ';'  */
#line 1892 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5488 "conf_parser.c"
    break;

  case 377: /* connect_host: HOST '=' QSTRING ';'  */
#line 1898 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5497 "conf_parser.c"
    break;

  case 378: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1904 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5506 "conf_parser.c"
    break;

  case 379: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1910 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5515 "conf_parser.c"
    break;

  case 380: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1916 "conf_parser.y"
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
#line 5531 "conf_parser.c"
    break;

  case 381: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1929 "conf_parser.y"
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
#line 5547 "conf_parser.c"
    break;

  case 382: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1942 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5556 "conf_parser.c"
    break;

  case 383: /* connect_port: PORT '=' NUMBER ';'  */
#line 1948 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5565 "conf_parser.c"
    break;

  case 384: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 1954 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5574 "conf_parser.c"
    break;

  case 385: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 1958 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5583 "conf_parser.c"
    break;

  case 386: /* $@20: %empty  */
#line 1964 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5591 "conf_parser.c"
    break;

  case 390: /* connect_flags_item: AUTOCONN  */
#line 1970 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5600 "conf_parser.c"
    break;

  case 391: /* connect_flags_item: T_TLS  */
#line 1974 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5609 "conf_parser.c"
    break;

  case 392: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1980 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5623 "conf_parser.c"
    break;

  case 393: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 1991 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5632 "conf_parser.c"
    break;

  case 394: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 1997 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5641 "conf_parser.c"
    break;

  case 395: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2003 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5650 "conf_parser.c"
    break;

  case 396: /* $@21: %empty  */
#line 2013 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5659 "conf_parser.c"
    break;

  case 397: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2017 "conf_parser.y"
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
#line 5683 "conf_parser.c"
    break;

  case 403: /* kill_user: USER '=' QSTRING ';'  */
#line 2041 "conf_parser.y"
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
#line 5706 "conf_parser.c"
    break;

  case 404: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5715 "conf_parser.c"
    break;

  case 405: /* $@22: %empty  */
#line 2071 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5724 "conf_parser.c"
    break;

  case 406: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2075 "conf_parser.y"
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
#line 5746 "conf_parser.c"
    break;

  case 412: /* deny_ip: IP '=' QSTRING ';'  */
#line 2097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5755 "conf_parser.c"
    break;

  case 413: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2103 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5764 "conf_parser.c"
    break;

  case 419: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2118 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_error_report("Unable to add D-line exemption");
}
#line 5776 "conf_parser.c"
    break;

  case 420: /* $@23: %empty  */
#line 2131 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5785 "conf_parser.c"
    break;

  case 421: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2135 "conf_parser.y"
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
#line 5805 "conf_parser.c"
    break;

  case 427: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2155 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5814 "conf_parser.c"
    break;

  case 428: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2161 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5823 "conf_parser.c"
    break;

  case 481: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2225 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5831 "conf_parser.c"
    break;

  case 482: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2230 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5839 "conf_parser.c"
    break;

  case 483: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2235 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5847 "conf_parser.c"
    break;

  case 484: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2240 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5855 "conf_parser.c"
    break;

  case 485: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2245 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5863 "conf_parser.c"
    break;

  case 486: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2250 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5871 "conf_parser.c"
    break;

  case 487: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2255 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5879 "conf_parser.c"
    break;

  case 488: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2260 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5887 "conf_parser.c"
    break;

  case 489: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2265 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5895 "conf_parser.c"
    break;

  case 490: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2270 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5903 "conf_parser.c"
    break;

  case 491: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2275 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5911 "conf_parser.c"
    break;

  case 492: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2280 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5919 "conf_parser.c"
    break;

  case 493: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2285 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5927 "conf_parser.c"
    break;

  case 494: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2290 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5935 "conf_parser.c"
    break;

  case 495: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2295 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 5946 "conf_parser.c"
    break;

  case 496: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2303 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5954 "conf_parser.c"
    break;

  case 497: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2308 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5962 "conf_parser.c"
    break;

  case 498: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2313 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5970 "conf_parser.c"
    break;

  case 499: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2318 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5978 "conf_parser.c"
    break;

  case 500: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2323 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5986 "conf_parser.c"
    break;

  case 501: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2328 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5994 "conf_parser.c"
    break;

  case 502: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2333 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6002 "conf_parser.c"
    break;

  case 503: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2338 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6010 "conf_parser.c"
    break;

  case 504: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2343 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6018 "conf_parser.c"
    break;

  case 505: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2348 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6026 "conf_parser.c"
    break;

  case 506: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2353 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6034 "conf_parser.c"
    break;

  case 507: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2358 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6042 "conf_parser.c"
    break;

  case 508: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2363 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6050 "conf_parser.c"
    break;

  case 509: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2368 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6058 "conf_parser.c"
    break;

  case 510: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2373 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6066 "conf_parser.c"
    break;

  case 511: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2378 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6074 "conf_parser.c"
    break;

  case 512: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2383 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6082 "conf_parser.c"
    break;

  case 513: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2388 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6090 "conf_parser.c"
    break;

  case 514: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2393 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6098 "conf_parser.c"
    break;

  case 515: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2398 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6106 "conf_parser.c"
    break;

  case 516: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2403 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6118 "conf_parser.c"
    break;

  case 517: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2412 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6126 "conf_parser.c"
    break;

  case 518: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2417 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6134 "conf_parser.c"
    break;

  case 519: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2422 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6142 "conf_parser.c"
    break;

  case 520: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2427 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6150 "conf_parser.c"
    break;

  case 521: /* general_cloak_enabled: CLOAK_ENABLED '=' TBOOL ';'  */
#line 2432 "conf_parser.y"
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
#line 6170 "conf_parser.c"
    break;

  case 522: /* general_cloak_cidr_len_ipv4: CLOAK_CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2449 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6181 "conf_parser.c"
    break;

  case 523: /* general_cloak_cidr_len_ipv6: CLOAK_CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2457 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6192 "conf_parser.c"
    break;

  case 524: /* general_cloak_num_bits: CLOAK_NUM_BITS '=' NUMBER ';'  */
#line 2465 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;
  ConfigGeneral.cloak_num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6203 "conf_parser.c"
    break;

  case 525: /* general_cloak_secret: CLOAK_SECRET '=' QSTRING ';'  */
#line 2473 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = io_strdup(yylval.string);
  cloak_set_secret(yylval.string);
}
#line 6216 "conf_parser.c"
    break;

  case 526: /* general_cloak_suffix: CLOAK_SUFFIX '=' QSTRING ';'  */
#line 2483 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = io_strdup(yylval.string);
  cloak_set_suffix(yylval.string);
}
#line 6229 "conf_parser.c"
    break;

  case 527: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2493 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6240 "conf_parser.c"
    break;

  case 528: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2501 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6248 "conf_parser.c"
    break;

  case 548: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2530 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6256 "conf_parser.c"
    break;

  case 549: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2535 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6264 "conf_parser.c"
    break;

  case 550: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2540 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6272 "conf_parser.c"
    break;

  case 551: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2545 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6280 "conf_parser.c"
    break;

  case 552: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2550 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6288 "conf_parser.c"
    break;

  case 553: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2555 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6296 "conf_parser.c"
    break;

  case 554: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2560 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6304 "conf_parser.c"
    break;

  case 555: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2565 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6312 "conf_parser.c"
    break;

  case 556: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2570 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6320 "conf_parser.c"
    break;

  case 557: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2575 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6328 "conf_parser.c"
    break;

  case 558: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2580 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6336 "conf_parser.c"
    break;

  case 559: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2585 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6344 "conf_parser.c"
    break;

  case 560: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2590 "conf_parser.y"
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
#line 6370 "conf_parser.c"
    break;

  case 561: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2613 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6378 "conf_parser.c"
    break;

  case 562: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2618 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6386 "conf_parser.c"
    break;

  case 575: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2640 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6395 "conf_parser.c"
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
#line 6409 "conf_parser.c"
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
#line 6421 "conf_parser.c"
    break;

  case 578: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2666 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6430 "conf_parser.c"
    break;

  case 579: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2672 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6439 "conf_parser.c"
    break;

  case 580: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2678 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6448 "conf_parser.c"
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
#line 6460 "conf_parser.c"
    break;

  case 582: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2693 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6469 "conf_parser.c"
    break;


#line 6473 "conf_parser.c"

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

