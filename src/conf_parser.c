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
    CIDR_LEN_IPV4 = 274,           /* CIDR_LEN_IPV4  */
    CIDR_LEN_IPV6 = 275,           /* CIDR_LEN_IPV6  */
    CLASS = 276,                   /* CLASS  */
    CLIENT = 277,                  /* CLIENT  */
    CLOAK = 278,                   /* CLOAK  */
    CLOSE = 279,                   /* CLOSE  */
    CONNECT = 280,                 /* CONNECT  */
    CONNECTFREQ = 281,             /* CONNECTFREQ  */
    CYCLE_ON_HOST_CHANGE = 282,    /* CYCLE_ON_HOST_CHANGE  */
    DEFAULT_FLOODCOUNT = 283,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 284,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 285, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 286, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 287,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 288,                   /* DEFER  */
    DENY = 289,                    /* DENY  */
    DESCRIPTION = 290,             /* DESCRIPTION  */
    DIE = 291,                     /* DIE  */
    DISABLE_DNS = 292,             /* DISABLE_DNS  */
    DISABLE_IDENT = 293,           /* DISABLE_IDENT  */
    DISABLE_FAKE_CHANNELS = 294,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 295, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 296,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 297,         /* DLINE_MIN_CIDR6  */
    EMAIL = 298,                   /* EMAIL  */
    ENABLED = 299,                 /* ENABLED  */
    ENCRYPTED = 300,               /* ENCRYPTED  */
    EXCEED_LIMIT = 301,            /* EXCEED_LIMIT  */
    EXEMPT = 302,                  /* EXEMPT  */
    FLATTEN_LINKS = 303,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 304,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 305,      /* FLATTEN_LINKS_FILE  */
    GECOS = 306,                   /* GECOS  */
    GENERAL = 307,                 /* GENERAL  */
    HIDDEN = 308,                  /* HIDDEN  */
    HIDDEN_NAME = 309,             /* HIDDEN_NAME  */
    HIDE_CHANS = 310,              /* HIDE_CHANS  */
    HIDE_IDLE = 311,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 312,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVERS = 313,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 314,           /* HIDE_SERVICES  */
    HOST = 315,                    /* HOST  */
    HUB = 316,                     /* HUB  */
    HUB_MASK = 317,                /* HUB_MASK  */
    IDENT_TIMEOUT = 318,           /* IDENT_TIMEOUT  */
    INVISIBLE_ON_CONNECT = 319,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 320,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 321,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 322,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 323,      /* INVITE_EXPIRE_TIME  */
    IP = 324,                      /* IP  */
    IRCD_AUTH = 325,               /* IRCD_AUTH  */
    IRCD_FLAGS = 326,              /* IRCD_FLAGS  */
    IRCD_SID = 327,                /* IRCD_SID  */
    JOIN = 328,                    /* JOIN  */
    KILL = 329,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 330,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 331,                   /* KLINE  */
    KLINE_EXEMPT = 332,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 333,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 334,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 335,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 336,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 337,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 338,               /* LEAF_MASK  */
    LISTEN = 339,                  /* LISTEN  */
    LOADMODULE = 340,              /* LOADMODULE  */
    MASK = 341,                    /* MASK  */
    MASS = 342,                    /* MASS  */
    MAX_ACCEPT = 343,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 344,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 345,                /* MAX_BANS  */
    MAX_BANS_LARGE = 346,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 347,            /* MAX_CHANNELS  */
    MAX_IDLE = 348,                /* MAX_IDLE  */
    MAX_INVITES = 349,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 350,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 351,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 352,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 353,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 354,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 355,              /* MAX_NUMBER  */
    MAX_TARGETS = 356,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 357,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 358,                 /* MESSAGE  */
    MIN_IDLE = 359,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 360,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 361,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 362,                  /* MODULE  */
    MODULE_BASE_PATH = 363,        /* MODULE_BASE_PATH  */
    MOTD = 364,                    /* MOTD  */
    MOTD_FILE = 365,               /* MOTD_FILE  */
    NAME = 366,                    /* NAME  */
    NEED_IDENT = 367,              /* NEED_IDENT  */
    NEED_PASSWORD = 368,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 369,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 370,            /* NETWORK_NAME  */
    NICK = 371,                    /* NICK  */
    NO_OPER_FLOOD = 372,           /* NO_OPER_FLOOD  */
    NO_TILDE = 373,                /* NO_TILDE  */
    NUM_BITS = 374,                /* NUM_BITS  */
    NUMBER_PER_CIDR = 375,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 376,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 377,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 378,             /* OPER_UMODES  */
    OPERATOR = 379,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 380,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 381,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 382,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 383,                /* PASSWORD  */
    PATH = 384,                    /* PATH  */
    PING_COOKIE = 385,             /* PING_COOKIE  */
    PING_TIME = 386,               /* PING_TIME  */
    PORT = 387,                    /* PORT  */
    RANDOM_IDLE = 388,             /* RANDOM_IDLE  */
    REASON = 389,                  /* REASON  */
    REGISTRATION_TIMEOUT = 390,    /* REGISTRATION_TIMEOUT  */
    REHASH = 391,                  /* REHASH  */
    REMOTE = 392,                  /* REMOTE  */
    REMOTEBAN = 393,               /* REMOTEBAN  */
    REQUIRED = 394,                /* REQUIRED  */
    RESIDENT = 395,                /* RESIDENT  */
    RESV = 396,                    /* RESV  */
    RESV_EXEMPT = 397,             /* RESV_EXEMPT  */
    SECRET = 398,                  /* SECRET  */
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
    SUFFIX = 416,                  /* SUFFIX  */
    T_ALL = 417,                   /* T_ALL  */
    T_BIND = 418,                  /* T_BIND  */
    T_COMMAND = 419,               /* T_COMMAND  */
    T_CLUSTER = 420,               /* T_CLUSTER  */
    T_DEBUG = 421,                 /* T_DEBUG  */
    T_DLINE = 422,                 /* T_DLINE  */
    T_FILE = 423,                  /* T_FILE  */
    T_GLOBOPS = 424,               /* T_GLOBOPS  */
    T_IPV4 = 425,                  /* T_IPV4  */
    T_IPV6 = 426,                  /* T_IPV6  */
    T_LOCOPS = 427,                /* T_LOCOPS  */
    T_LOG = 428,                   /* T_LOG  */
    T_OPME = 429,                  /* T_OPME  */
    T_PREPEND = 430,               /* T_PREPEND  */
    T_PSEUDO = 431,                /* T_PSEUDO  */
    T_RECVQ = 432,                 /* T_RECVQ  */
    T_RESTART = 433,               /* T_RESTART  */
    T_SERVER = 434,                /* T_SERVER  */
    T_SERVICE = 435,               /* T_SERVICE  */
    T_SET = 436,                   /* T_SET  */
    T_SHARED = 437,                /* T_SHARED  */
    T_SIZE = 438,                  /* T_SIZE  */
    T_TARGET = 439,                /* T_TARGET  */
    T_TLS = 440,                   /* T_TLS  */
    T_UMODES = 441,                /* T_UMODES  */
    T_UNDLINE = 442,               /* T_UNDLINE  */
    T_UNLIMITED = 443,             /* T_UNLIMITED  */
    T_UNRESV = 444,                /* T_UNRESV  */
    T_UNXLINE = 445,               /* T_UNXLINE  */
    T_WEBIRC = 446,                /* T_WEBIRC  */
    TBOOL = 447,                   /* TBOOL  */
    THROTTLE_COUNT = 448,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 449,           /* THROTTLE_TIME  */
    TIMEOUT = 450,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 451,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 452, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 453,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 454, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 455,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 456,           /* TS_WARN_DELTA  */
    TWODOTS = 457,                 /* TWODOTS  */
    TYPE = 458,                    /* TYPE  */
    UNKLINE = 459,                 /* UNKLINE  */
    USE_LOGGING = 460,             /* USE_LOGGING  */
    USER = 461,                    /* USER  */
    VHOST = 462,                   /* VHOST  */
    VHOST6 = 463,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 464,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 465,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 466,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 467,                   /* XLINE  */
    XLINE_EXEMPT = 468,            /* XLINE_EXEMPT  */
    QSTRING = 469,                 /* QSTRING  */
    NUMBER = 470                   /* NUMBER  */
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
#define CIDR_LEN_IPV4 274
#define CIDR_LEN_IPV6 275
#define CLASS 276
#define CLIENT 277
#define CLOAK 278
#define CLOSE 279
#define CONNECT 280
#define CONNECTFREQ 281
#define CYCLE_ON_HOST_CHANGE 282
#define DEFAULT_FLOODCOUNT 283
#define DEFAULT_FLOODTIME 284
#define DEFAULT_JOIN_FLOOD_COUNT 285
#define DEFAULT_JOIN_FLOOD_TIME 286
#define DEFAULT_MAX_CLIENTS 287
#define DEFER 288
#define DENY 289
#define DESCRIPTION 290
#define DIE 291
#define DISABLE_DNS 292
#define DISABLE_IDENT 293
#define DISABLE_FAKE_CHANNELS 294
#define DISABLE_REMOTE_COMMANDS 295
#define DLINE_MIN_CIDR 296
#define DLINE_MIN_CIDR6 297
#define EMAIL 298
#define ENABLED 299
#define ENCRYPTED 300
#define EXCEED_LIMIT 301
#define EXEMPT 302
#define FLATTEN_LINKS 303
#define FLATTEN_LINKS_DELAY 304
#define FLATTEN_LINKS_FILE 305
#define GECOS 306
#define GENERAL 307
#define HIDDEN 308
#define HIDDEN_NAME 309
#define HIDE_CHANS 310
#define HIDE_IDLE 311
#define HIDE_IDLE_FROM_OPERS 312
#define HIDE_SERVERS 313
#define HIDE_SERVICES 314
#define HOST 315
#define HUB 316
#define HUB_MASK 317
#define IDENT_TIMEOUT 318
#define INVISIBLE_ON_CONNECT 319
#define INVITE_CLIENT_COUNT 320
#define INVITE_CLIENT_TIME 321
#define INVITE_DELAY_CHANNEL 322
#define INVITE_EXPIRE_TIME 323
#define IP 324
#define IRCD_AUTH 325
#define IRCD_FLAGS 326
#define IRCD_SID 327
#define JOIN 328
#define KILL 329
#define KILL_CHASE_TIME_LIMIT 330
#define KLINE 331
#define KLINE_EXEMPT 332
#define KLINE_MIN_CIDR 333
#define KLINE_MIN_CIDR6 334
#define KNOCK_CLIENT_COUNT 335
#define KNOCK_CLIENT_TIME 336
#define KNOCK_DELAY_CHANNEL 337
#define LEAF_MASK 338
#define LISTEN 339
#define LOADMODULE 340
#define MASK 341
#define MASS 342
#define MAX_ACCEPT 343
#define MAX_AWAY_LENGTH 344
#define MAX_BANS 345
#define MAX_BANS_LARGE 346
#define MAX_CHANNELS 347
#define MAX_IDLE 348
#define MAX_INVITES 349
#define MAX_KICK_LENGTH 350
#define MAX_MONITOR 351
#define MAX_NICK_CHANGES 352
#define MAX_NICK_LENGTH 353
#define MAX_NICK_TIME 354
#define MAX_NUMBER 355
#define MAX_TARGETS 356
#define MAX_TOPIC_LENGTH 357
#define MESSAGE 358
#define MIN_IDLE 359
#define MIN_NONWILDCARD 360
#define MIN_NONWILDCARD_SIMPLE 361
#define MODULE 362
#define MODULE_BASE_PATH 363
#define MOTD 364
#define MOTD_FILE 365
#define NAME 366
#define NEED_IDENT 367
#define NEED_PASSWORD 368
#define NETWORK_DESCRIPTION 369
#define NETWORK_NAME 370
#define NICK 371
#define NO_OPER_FLOOD 372
#define NO_TILDE 373
#define NUM_BITS 374
#define NUMBER_PER_CIDR 375
#define NUMBER_PER_IP_GLOBAL 376
#define NUMBER_PER_IP_LOCAL 377
#define OPER_UMODES 378
#define OPERATOR 379
#define OPERS_BYPASS_CALLERID 380
#define PACE_WAIT 381
#define PACE_WAIT_SIMPLE 382
#define PASSWORD 383
#define PATH 384
#define PING_COOKIE 385
#define PING_TIME 386
#define PORT 387
#define RANDOM_IDLE 388
#define REASON 389
#define REGISTRATION_TIMEOUT 390
#define REHASH 391
#define REMOTE 392
#define REMOTEBAN 393
#define REQUIRED 394
#define RESIDENT 395
#define RESV 396
#define RESV_EXEMPT 397
#define SECRET 398
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
#define SUFFIX 416
#define T_ALL 417
#define T_BIND 418
#define T_COMMAND 419
#define T_CLUSTER 420
#define T_DEBUG 421
#define T_DLINE 422
#define T_FILE 423
#define T_GLOBOPS 424
#define T_IPV4 425
#define T_IPV6 426
#define T_LOCOPS 427
#define T_LOG 428
#define T_OPME 429
#define T_PREPEND 430
#define T_PSEUDO 431
#define T_RECVQ 432
#define T_RESTART 433
#define T_SERVER 434
#define T_SERVICE 435
#define T_SET 436
#define T_SHARED 437
#define T_SIZE 438
#define T_TARGET 439
#define T_TLS 440
#define T_UMODES 441
#define T_UNDLINE 442
#define T_UNLIMITED 443
#define T_UNRESV 444
#define T_UNXLINE 445
#define T_WEBIRC 446
#define TBOOL 447
#define THROTTLE_COUNT 448
#define THROTTLE_TIME 449
#define TIMEOUT 450
#define TLS_CERTIFICATE_FILE 451
#define TLS_CERTIFICATE_FINGERPRINT 452
#define TLS_PRIVATE_KEY_FILE 453
#define TLS_CONNECTION_REQUIRED 454
#define TS_MAX_DELTA 455
#define TS_WARN_DELTA 456
#define TWODOTS 457
#define TYPE 458
#define UNKLINE 459
#define USE_LOGGING 460
#define USER 461
#define VHOST 462
#define VHOST6 463
#define WARN_NO_CONNECT_BLOCK 464
#define WHOIS 465
#define WHOWAS_HISTORY_LENGTH 466
#define XLINE 467
#define XLINE_EXEMPT 468
#define QSTRING 469
#define NUMBER 470

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 680 "conf_parser.c"

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
  YYSYMBOL_CIDR_LEN_IPV4 = 19,             /* CIDR_LEN_IPV4  */
  YYSYMBOL_CIDR_LEN_IPV6 = 20,             /* CIDR_LEN_IPV6  */
  YYSYMBOL_CLASS = 21,                     /* CLASS  */
  YYSYMBOL_CLIENT = 22,                    /* CLIENT  */
  YYSYMBOL_CLOAK = 23,                     /* CLOAK  */
  YYSYMBOL_CLOSE = 24,                     /* CLOSE  */
  YYSYMBOL_CONNECT = 25,                   /* CONNECT  */
  YYSYMBOL_CONNECTFREQ = 26,               /* CONNECTFREQ  */
  YYSYMBOL_CYCLE_ON_HOST_CHANGE = 27,      /* CYCLE_ON_HOST_CHANGE  */
  YYSYMBOL_DEFAULT_FLOODCOUNT = 28,        /* DEFAULT_FLOODCOUNT  */
  YYSYMBOL_DEFAULT_FLOODTIME = 29,         /* DEFAULT_FLOODTIME  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_COUNT = 30,  /* DEFAULT_JOIN_FLOOD_COUNT  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_TIME = 31,   /* DEFAULT_JOIN_FLOOD_TIME  */
  YYSYMBOL_DEFAULT_MAX_CLIENTS = 32,       /* DEFAULT_MAX_CLIENTS  */
  YYSYMBOL_DEFER = 33,                     /* DEFER  */
  YYSYMBOL_DENY = 34,                      /* DENY  */
  YYSYMBOL_DESCRIPTION = 35,               /* DESCRIPTION  */
  YYSYMBOL_DIE = 36,                       /* DIE  */
  YYSYMBOL_DISABLE_DNS = 37,               /* DISABLE_DNS  */
  YYSYMBOL_DISABLE_IDENT = 38,             /* DISABLE_IDENT  */
  YYSYMBOL_DISABLE_FAKE_CHANNELS = 39,     /* DISABLE_FAKE_CHANNELS  */
  YYSYMBOL_DISABLE_REMOTE_COMMANDS = 40,   /* DISABLE_REMOTE_COMMANDS  */
  YYSYMBOL_DLINE_MIN_CIDR = 41,            /* DLINE_MIN_CIDR  */
  YYSYMBOL_DLINE_MIN_CIDR6 = 42,           /* DLINE_MIN_CIDR6  */
  YYSYMBOL_EMAIL = 43,                     /* EMAIL  */
  YYSYMBOL_ENABLED = 44,                   /* ENABLED  */
  YYSYMBOL_ENCRYPTED = 45,                 /* ENCRYPTED  */
  YYSYMBOL_EXCEED_LIMIT = 46,              /* EXCEED_LIMIT  */
  YYSYMBOL_EXEMPT = 47,                    /* EXEMPT  */
  YYSYMBOL_FLATTEN_LINKS = 48,             /* FLATTEN_LINKS  */
  YYSYMBOL_FLATTEN_LINKS_DELAY = 49,       /* FLATTEN_LINKS_DELAY  */
  YYSYMBOL_FLATTEN_LINKS_FILE = 50,        /* FLATTEN_LINKS_FILE  */
  YYSYMBOL_GECOS = 51,                     /* GECOS  */
  YYSYMBOL_GENERAL = 52,                   /* GENERAL  */
  YYSYMBOL_HIDDEN = 53,                    /* HIDDEN  */
  YYSYMBOL_HIDDEN_NAME = 54,               /* HIDDEN_NAME  */
  YYSYMBOL_HIDE_CHANS = 55,                /* HIDE_CHANS  */
  YYSYMBOL_HIDE_IDLE = 56,                 /* HIDE_IDLE  */
  YYSYMBOL_HIDE_IDLE_FROM_OPERS = 57,      /* HIDE_IDLE_FROM_OPERS  */
  YYSYMBOL_HIDE_SERVERS = 58,              /* HIDE_SERVERS  */
  YYSYMBOL_HIDE_SERVICES = 59,             /* HIDE_SERVICES  */
  YYSYMBOL_HOST = 60,                      /* HOST  */
  YYSYMBOL_HUB = 61,                       /* HUB  */
  YYSYMBOL_HUB_MASK = 62,                  /* HUB_MASK  */
  YYSYMBOL_IDENT_TIMEOUT = 63,             /* IDENT_TIMEOUT  */
  YYSYMBOL_INVISIBLE_ON_CONNECT = 64,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 65,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 66,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 67,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 68,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 69,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 70,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 71,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 72,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 73,                      /* JOIN  */
  YYSYMBOL_KILL = 74,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 75,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 76,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 77,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 78,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 79,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 80,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 81,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 82,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 83,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 84,                    /* LISTEN  */
  YYSYMBOL_LOADMODULE = 85,                /* LOADMODULE  */
  YYSYMBOL_MASK = 86,                      /* MASK  */
  YYSYMBOL_MASS = 87,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 88,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_AWAY_LENGTH = 89,           /* MAX_AWAY_LENGTH  */
  YYSYMBOL_MAX_BANS = 90,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 91,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 92,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 93,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 94,               /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 95,           /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 96,               /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 97,          /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 98,           /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 99,             /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 100,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 101,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 102,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 103,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 104,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 105,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 106,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 107,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 108,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 109,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 110,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 111,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 112,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 113,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 114,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 115,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 116,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 117,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 118,                 /* NO_TILDE  */
  YYSYMBOL_NUM_BITS = 119,                 /* NUM_BITS  */
  YYSYMBOL_NUMBER_PER_CIDR = 120,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 121,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 122,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_UMODES = 123,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 124,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 125,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 126,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 127,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 128,                 /* PASSWORD  */
  YYSYMBOL_PATH = 129,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 130,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 131,                /* PING_TIME  */
  YYSYMBOL_PORT = 132,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 133,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 134,                   /* REASON  */
  YYSYMBOL_REGISTRATION_TIMEOUT = 135,     /* REGISTRATION_TIMEOUT  */
  YYSYMBOL_REHASH = 136,                   /* REHASH  */
  YYSYMBOL_REMOTE = 137,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 138,                /* REMOTEBAN  */
  YYSYMBOL_REQUIRED = 139,                 /* REQUIRED  */
  YYSYMBOL_RESIDENT = 140,                 /* RESIDENT  */
  YYSYMBOL_RESV = 141,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 142,              /* RESV_EXEMPT  */
  YYSYMBOL_SECRET = 143,                   /* SECRET  */
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
  YYSYMBOL_SUFFIX = 161,                   /* SUFFIX  */
  YYSYMBOL_T_ALL = 162,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 163,                   /* T_BIND  */
  YYSYMBOL_T_COMMAND = 164,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 165,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 166,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 167,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 168,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 169,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 170,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 171,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 172,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 173,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 174,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 175,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 176,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 177,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 178,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 179,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 180,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 181,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 182,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 183,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 184,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 185,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 186,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 187,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 188,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 189,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 190,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 191,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 192,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 193,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 194,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 195,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 196,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 197, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_PRIVATE_KEY_FILE = 198,     /* TLS_PRIVATE_KEY_FILE  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 199,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TS_MAX_DELTA = 200,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 201,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 202,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 203,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 204,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 205,              /* USE_LOGGING  */
  YYSYMBOL_USER = 206,                     /* USER  */
  YYSYMBOL_VHOST = 207,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 208,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 209,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 210,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 211,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 212,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 213,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 214,                  /* QSTRING  */
  YYSYMBOL_NUMBER = 215,                   /* NUMBER  */
  YYSYMBOL_216_ = 216,                     /* ';'  */
  YYSYMBOL_217_ = 217,                     /* '}'  */
  YYSYMBOL_218_ = 218,                     /* '='  */
  YYSYMBOL_219_ = 219,                     /* ':'  */
  YYSYMBOL_220_ = 220,                     /* ','  */
  YYSYMBOL_221_ = 221,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 222,                 /* $accept  */
  YYSYMBOL_conf = 223,                     /* conf  */
  YYSYMBOL_conf_item = 224,                /* conf_item  */
  YYSYMBOL_timespec_ = 225,                /* timespec_  */
  YYSYMBOL_timespec = 226,                 /* timespec  */
  YYSYMBOL_sizespec_ = 227,                /* sizespec_  */
  YYSYMBOL_sizespec = 228,                 /* sizespec  */
  YYSYMBOL_module_base_path_entry = 229,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 230,         /* loadmodule_entry  */
  YYSYMBOL_module_string = 231,            /* module_string  */
  YYSYMBOL_module_attributes = 232,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 233,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 234,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 235,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 236,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 237,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 238, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_tls_private_key_file = 239, /* serverinfo_tls_private_key_file  */
  YYSYMBOL_serverinfo_name = 240,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 241,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 242,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 243,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 244, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 245, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 246, /* serverinfo_max_nick_length  */
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
  YYSYMBOL_general_ident_timeout = 464,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 465, /* general_registration_timeout  */
  YYSYMBOL_cloak_entry = 466,              /* cloak_entry  */
  YYSYMBOL_cloak_items = 467,              /* cloak_items  */
  YYSYMBOL_cloak_item = 468,               /* cloak_item  */
  YYSYMBOL_cloak_enabled = 469,            /* cloak_enabled  */
  YYSYMBOL_cloak_cidr_len_ipv4 = 470,      /* cloak_cidr_len_ipv4  */
  YYSYMBOL_cloak_cidr_len_ipv6 = 471,      /* cloak_cidr_len_ipv6  */
  YYSYMBOL_cloak_num_bits = 472,           /* cloak_num_bits  */
  YYSYMBOL_cloak_secret = 473,             /* cloak_secret  */
  YYSYMBOL_cloak_suffix = 474,             /* cloak_suffix  */
  YYSYMBOL_channel_entry = 475,            /* channel_entry  */
  YYSYMBOL_channel_items = 476,            /* channel_items  */
  YYSYMBOL_channel_item = 477,             /* channel_item  */
  YYSYMBOL_channel_disable_fake_channels = 478, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 479, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 480, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 481, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 482, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 483, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 484, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 485, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 486,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 487,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 488,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 489,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 490,  /* channel_max_kick_length  */
  YYSYMBOL_channel_max_topic_length = 491, /* channel_max_topic_length  */
  YYSYMBOL_channel_default_join_flood_count = 492, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 493, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 494,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 495,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 496,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 497, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 498, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 499, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 500, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 501,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 502, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 503,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 504         /* serverhide_hidden  */
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
#define YYLAST   1286

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  222
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  283
/* YYNRULES -- Number of rules.  */
#define YYNRULES  587
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1216

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   470


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
       2,     2,     2,     2,   220,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   219,   216,
       2,   218,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   221,     2,   217,     2,     2,     2,     2,
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
     215
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   353,   353,   354,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     386,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     397,   397,   398,   399,   400,   401,   408,   426,   441,   447,
     449,   454,   457,   462,   465,   474,   476,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     491,   500,   509,   524,   539,   549,   563,   572,   595,   618,
     627,   637,   639,   639,   640,   641,   642,   643,   645,   654,
     663,   677,   676,   694,   694,   695,   695,   695,   697,   703,
     714,   713,   732,   732,   733,   733,   733,   733,   733,   735,
     741,   747,   753,   776,   777,   777,   779,   779,   780,   782,
     792,   792,   805,   806,   808,   808,   809,   809,   811,   819,
     822,   828,   827,   833,   837,   841,   845,   849,   853,   857,
     861,   872,   871,   933,   933,   934,   935,   936,   937,   938,
     939,   940,   941,   942,   943,   944,   946,   952,   958,   964,
     970,   981,   987,   998,  1004,  1011,  1010,  1016,  1016,  1017,
    1021,  1025,  1029,  1033,  1037,  1041,  1045,  1049,  1053,  1057,
    1061,  1065,  1069,  1073,  1077,  1081,  1085,  1089,  1093,  1097,
    1101,  1105,  1109,  1113,  1117,  1121,  1125,  1129,  1140,  1139,
    1195,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,
    1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1213,  1219,
    1225,  1231,  1237,  1243,  1249,  1255,  1261,  1268,  1274,  1280,
    1286,  1295,  1305,  1304,  1310,  1310,  1311,  1315,  1326,  1325,
    1332,  1331,  1336,  1336,  1337,  1341,  1345,  1349,  1353,  1359,
    1359,  1360,  1360,  1360,  1360,  1360,  1362,  1362,  1364,  1364,
    1366,  1379,  1396,  1402,  1413,  1412,  1468,  1468,  1469,  1470,
    1471,  1472,  1473,  1474,  1475,  1477,  1483,  1489,  1495,  1507,
    1506,  1512,  1512,  1514,  1518,  1522,  1526,  1530,  1534,  1538,
    1542,  1546,  1552,  1568,  1567,  1582,  1582,  1583,  1583,  1583,
    1583,  1585,  1591,  1597,  1607,  1609,  1609,  1610,  1610,  1612,
    1629,  1628,  1651,  1651,  1652,  1652,  1652,  1652,  1654,  1660,
    1680,  1679,  1685,  1685,  1686,  1690,  1694,  1698,  1702,  1706,
    1710,  1714,  1718,  1722,  1733,  1732,  1751,  1751,  1752,  1752,
    1752,  1754,  1761,  1760,  1766,  1766,  1767,  1771,  1775,  1779,
    1783,  1787,  1791,  1795,  1799,  1803,  1814,  1813,  1867,  1867,
    1868,  1869,  1870,  1871,  1872,  1873,  1874,  1875,  1876,  1877,
    1878,  1879,  1880,  1881,  1882,  1884,  1890,  1896,  1902,  1908,
    1921,  1934,  1940,  1946,  1950,  1957,  1956,  1961,  1961,  1962,
    1966,  1972,  1983,  1989,  1995,  2006,  2005,  2030,  2030,  2031,
    2031,  2031,  2033,  2053,  2064,  2063,  2086,  2086,  2087,  2087,
    2087,  2089,  2095,  2105,  2107,  2107,  2108,  2108,  2110,  2124,
    2123,  2144,  2144,  2145,  2145,  2145,  2147,  2153,  2163,  2165,
    2165,  2166,  2167,  2168,  2169,  2170,  2171,  2172,  2173,  2174,
    2175,  2176,  2177,  2178,  2179,  2180,  2181,  2182,  2183,  2184,
    2185,  2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,  2194,
    2195,  2196,  2197,  2198,  2199,  2200,  2201,  2202,  2203,  2204,
    2205,  2206,  2207,  2208,  2211,  2216,  2221,  2226,  2231,  2236,
    2241,  2246,  2251,  2256,  2261,  2266,  2271,  2276,  2281,  2289,
    2294,  2299,  2304,  2309,  2314,  2319,  2324,  2329,  2334,  2339,
    2344,  2349,  2354,  2359,  2364,  2369,  2374,  2379,  2384,  2389,
    2398,  2403,  2408,  2413,  2418,  2426,  2435,  2437,  2437,  2438,
    2439,  2440,  2441,  2442,  2443,  2444,  2446,  2463,  2472,  2481,
    2490,  2500,  2514,  2516,  2516,  2517,  2518,  2519,  2520,  2521,
    2522,  2523,  2524,  2525,  2526,  2527,  2528,  2529,  2530,  2531,
    2532,  2533,  2535,  2540,  2545,  2550,  2555,  2560,  2565,  2570,
    2575,  2580,  2585,  2590,  2595,  2618,  2626,  2631,  2640,  2642,
    2642,  2643,  2644,  2645,  2646,  2647,  2648,  2649,  2650,  2651,
    2653,  2659,  2670,  2679,  2685,  2691,  2697,  2706
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
  "CIDR_BITLEN_IPV6", "CIDR_LEN_IPV4", "CIDR_LEN_IPV6", "CLASS", "CLIENT",
  "CLOAK", "CLOSE", "CONNECT", "CONNECTFREQ", "CYCLE_ON_HOST_CHANGE",
  "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME", "DEFAULT_JOIN_FLOOD_COUNT",
  "DEFAULT_JOIN_FLOOD_TIME", "DEFAULT_MAX_CLIENTS", "DEFER", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_DNS", "DISABLE_IDENT",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR",
  "DLINE_MIN_CIDR6", "EMAIL", "ENABLED", "ENCRYPTED", "EXCEED_LIMIT",
  "EXEMPT", "FLATTEN_LINKS", "FLATTEN_LINKS_DELAY", "FLATTEN_LINKS_FILE",
  "GECOS", "GENERAL", "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
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
  "NO_OPER_FLOOD", "NO_TILDE", "NUM_BITS", "NUMBER_PER_CIDR",
  "NUMBER_PER_IP_GLOBAL", "NUMBER_PER_IP_LOCAL", "OPER_UMODES", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD",
  "PATH", "PING_COOKIE", "PING_TIME", "PORT", "RANDOM_IDLE", "REASON",
  "REGISTRATION_TIMEOUT", "REHASH", "REMOTE", "REMOTEBAN", "REQUIRED",
  "RESIDENT", "RESV", "RESV_EXEMPT", "SECRET", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ",
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPECIALS_IN_IDENT", "SPOOF",
  "SQUIT", "STATS_E_DISABLED", "STATS_U_OPER_ONLY", "SUFFIX", "T_ALL",
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
  "general_default_floodtime", "general_ident_timeout",
  "general_registration_timeout", "cloak_entry", "cloak_items",
  "cloak_item", "cloak_enabled", "cloak_cidr_len_ipv4",
  "cloak_cidr_len_ipv6", "cloak_num_bits", "cloak_secret", "cloak_suffix",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_invite_delay_channel",
  "channel_invite_expire_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_channels", "channel_max_invites", "channel_max_bans",
  "channel_max_bans_large", "channel_max_kick_length",
  "channel_max_topic_length", "channel_default_join_flood_count",
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

#define YYPACT_NINF (-924)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -924,   574,  -924,  -133,  -206,  -197,  -924,  -183,  -924,  -924,
    -175,  -924,  -166,  -924,  -924,  -924,  -188,  -186,  -924,  -924,
    -924,  -163,  -160,  -924,  -153,  -924,  -148,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,     2,   759,  -145,   354,  -143,
    -129,     3,  -120,   393,  -116,  -111,  -100,  -924,  -170,  -188,
     -86,   -83,   -78,   506,   505,   -73,    43,   -64,    12,   -55,
     -48,   -41,   -36,   -34,     7,  -924,  -924,  -924,  -924,  -924,
     -31,    -4,     0,    24,    51,    66,    82,    84,    94,    97,
     100,   103,   107,   110,   114,   115,   125,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,   651,  -924,   116,   119,   122,   128,
     129,   135,   152,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
     568,    10,  -924,   136,    18,  -924,  -924,    29,  -924,   141,
     142,   143,   145,   148,   150,   154,   160,   161,   162,   163,
     164,   169,   171,   173,   175,   177,   178,   179,   183,   186,
     188,   190,   191,   195,   196,   201,   205,   207,   208,   214,
     221,   223,   224,   225,   226,   227,   228,   231,   233,   236,
     240,    53,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,   305,   133,   296,    58,    42,
     120,   118,   277,   276,  -924,   242,   243,   247,   248,   249,
     251,   252,   257,    16,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,   170,   259,   260,   261,   262,   270,   273,
     275,   283,   285,   286,   287,   194,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,    56,   202,
     290,    35,  -924,  -924,  -924,    60,   200,  -924,   291,    13,
    -924,  -924,   132,  -924,   130,   137,   156,   222,  -924,   197,
     280,   256,   297,   280,   280,   280,   298,   280,   280,   299,
     309,   310,   311,   314,   315,   316,  -924,   319,   313,   320,
     321,  -924,   323,   326,   327,   329,   332,   339,   340,   343,
     344,   350,   352,   168,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
     357,   364,   389,   368,   370,   371,   375,  -924,   390,   374,
     387,   391,   392,   394,   396,  -924,   399,   405,   406,   413,
     415,   417,   418,   220,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
     419,   422,    27,  -924,  -924,  -924,   397,   426,  -924,  -924,
     425,   428,    40,  -924,  -924,  -924,   461,   280,   439,   280,
     280,   463,   441,   280,   465,   468,   446,   447,   280,   471,
     280,   450,   452,   455,   459,   466,   477,   280,   480,   481,
     482,   483,   464,   488,   280,   280,   507,   280,   510,   489,
     513,   514,   492,   280,   280,   280,   517,   495,   496,  -924,
     497,   493,   499,  -924,   500,   502,   503,    32,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,   508,   511,    28,  -924,
    -924,  -924,   498,   512,   515,  -924,   516,  -924,    33,  -924,
    -924,  -924,  -924,  -924,  -924,   520,  -924,  -924,  -924,   509,
     518,   519,   113,  -924,  -924,  -924,   525,   524,   527,  -924,
     528,   530,   531,   534,   535,   539,   540,   230,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,   545,
     548,   549,   550,    39,  -924,  -924,  -924,  -924,   532,   543,
     280,   556,   589,   569,   593,   596,   575,  -924,  -924,   577,
     579,   602,   581,   582,   585,   586,   588,   590,   591,   592,
     580,  -924,   594,   595,  -924,   126,  -924,  -924,  -924,  -924,
     615,   598,  -924,   386,   599,   600,   601,   603,   604,    99,
    -924,  -924,  -924,  -924,  -924,   606,   607,  -924,   613,   612,
    -924,   614,    70,  -924,  -924,  -924,  -924,   617,   618,   619,
    -924,   620,   630,   621,   622,   626,   627,   628,   631,   632,
     636,   639,   640,   641,   642,   643,   644,   646,  -924,  -924,
     616,   648,   280,   647,   649,   280,   652,   280,   654,   655,
     656,   657,   280,   658,   658,   650,  -924,   653,   659,   660,
     661,   662,   663,  -924,  -924,   666,   123,   667,   624,   668,
     669,   670,   671,   672,   674,   673,   676,   280,   677,   678,
    -924,   679,   681,   680,  -924,   682,  -924,   683,   685,   684,
    -924,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,  -924,  -924,   730,   625,   728,   731,   733,
     734,   735,  -924,   736,   738,   737,  -924,  -924,   740,   741,
     739,   743,   744,  -924,    58,  -924,   742,   745,   746,  -924,
    -924,   747,   757,   748,   749,   750,   751,   753,   776,   755,
     756,   758,  -924,  -924,   761,   762,   763,   764,  -924,   765,
     766,   767,   768,   769,   770,   771,   772,  -924,   773,   774,
     775,   777,   778,   779,   780,   781,   782,   783,   784,  -924,
    -924,   787,   754,   786,  -924,   788,  -924,   174,  -924,   789,
     791,   792,   793,   794,  -924,   795,  -924,  -924,   798,   760,
     799,   800,  -924,  -924,  -924,  -924,  -924,   280,   280,   280,
     280,   280,   280,   280,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,   801,   802,   803,   -45,   804,   805,   806,   807,   808,
     809,   810,   811,   812,    95,   813,   814,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,   815,   816,   817,   818,   819,   820,
     821,    15,   822,   823,   824,   825,   826,   827,   828,  -924,
     829,   830,  -924,  -924,   831,   832,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,   833,
     834,   409,   835,   836,   837,  -924,   838,   839,  -924,   840,
     841,   274,   521,   664,  -924,  -924,  -924,   842,   843,  -924,
     844,   845,   460,   846,   847,   848,   849,   850,   851,   852,
    -924,   853,   854,   855,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,   856,   504,  -924,  -924,   857,   790,
     796,  -924,    19,  -924,  -924,  -924,  -924,   858,   859,   860,
     861,  -924,  -924,   862,   597,   863,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -198,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
     658,   658,   658,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -195,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -189,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -181,  -924,   865,   743,   866,  -924,
    -924,  -924,  -924,  -924,  -924,   752,  -924,   864,   867,  -924,
     868,  -924,   869,   870,  -924,  -924,   871,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -169,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -168,  -924,  -924,   877,  -172,   797,   876,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -131,  -924,  -924,  -924,   -45,  -924,
    -924,  -924,  -924,    15,  -924,   409,  -924,   274,  -924,  -924,
    -924,   675,   940,   872,   645,   943,   948,   956,  -924,   460,
    -924,   504,   878,   879,   880,   376,  -924,  -924,   597,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,   881,  -924,  -924
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   198,     0,   356,   404,
       0,   419,     0,   264,   395,   238,     0,     0,    91,   141,
     293,     0,     0,   334,     0,   100,     0,   310,     3,     4,
       5,    14,     6,    26,    27,     7,     8,    11,    12,    13,
      16,    17,    18,    19,    20,    21,    22,    23,    25,    24,
      10,     9,    15,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    86,    85,   551,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   534,   550,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   535,   536,
     546,   547,   548,   549,     0,   525,     0,     0,     0,     0,
       0,     0,     0,   518,   519,   520,   521,   522,   523,   524,
       0,     0,   417,     0,     0,   415,   416,     0,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   430,   431,   432,   469,   437,   470,   464,   465,
     466,   467,   441,   433,   434,   435,   436,   451,   438,   439,
     440,   442,   443,   468,   445,   446,   453,   454,   447,   448,
     449,   444,   450,   461,   462,   463,   459,   460,   452,   457,
     458,   455,   456,   471,   472,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   579,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   570,   571,   572,   573,   574,   575,
     576,   578,   577,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,    68,    66,    58,
      67,    60,    61,    62,    63,    64,    65,    59,     0,     0,
       0,     0,   115,   116,   117,     0,     0,   308,     0,     0,
     306,   307,     0,    87,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   533,     0,     0,     0,
       0,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   202,   205,   207,   208,   209,
     210,   211,   212,   213,   203,   204,   206,   214,   215,   216,
       0,     0,     0,     0,     0,     0,     0,   517,     0,     0,
       0,     0,     0,     0,     0,   385,     0,     0,     0,     0,
       0,     0,     0,     0,   359,   360,   361,   362,   363,   364,
     365,   366,   368,   367,   369,   373,   370,   371,   372,   410,
       0,     0,     0,   407,   408,   409,     0,     0,   414,   425,
       0,     0,     0,   422,   423,   424,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
       0,     0,     0,   279,     0,     0,     0,     0,   267,   268,
     269,   270,   273,   271,   272,   401,     0,     0,     0,   398,
     399,   400,     0,     0,     0,   240,     0,   252,     0,   250,
     251,   253,   254,    54,    53,    50,    52,    47,    46,     0,
       0,     0,     0,    94,    95,    96,     0,     0,     0,   165,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   145,
     146,   147,   148,   151,   152,   153,   150,   149,   154,     0,
       0,     0,     0,     0,   296,   297,   298,   299,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   569,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,   342,     0,   337,   338,   339,   118,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
     103,   104,   106,   105,   107,     0,     0,   305,     0,     0,
     320,     0,     0,   313,   314,   315,   316,     0,     0,     0,
      81,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   532,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,     0,     0,
       0,     0,     0,   516,   374,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     358,     0,     0,     0,   406,     0,   413,     0,     0,     0,
     421,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   428,   274,     0,     0,     0,     0,     0,
       0,     0,   266,     0,     0,     0,   397,   255,     0,     0,
       0,     0,     0,   249,     0,    97,     0,     0,     0,    93,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   300,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,     0,     0,   568,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
     340,     0,     0,     0,   336,     0,   113,     0,   108,     0,
       0,     0,     0,     0,   102,     0,   304,   317,     0,     0,
       0,     0,   312,    90,    89,    88,   566,    30,    30,    30,
      30,    30,    30,    30,    32,    31,   567,   552,   553,   554,
     555,   556,   557,   558,   559,   562,   563,   560,   561,   564,
     565,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,   199,   527,   528,
     526,   529,   530,   531,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   357,
       0,     0,   405,   418,     0,     0,   420,   484,   489,   474,
     475,   497,   478,   512,   513,   506,   505,   479,   480,   514,
     492,   483,   481,   482,   487,   488,   476,   486,   485,   503,
     510,   511,   501,   509,   498,   496,   499,   504,   515,   500,
     502,   494,   495,   507,   508,   491,   490,   493,   477,     0,
       0,     0,     0,     0,     0,   265,     0,     0,   396,     0,
       0,     0,   260,   256,   259,   239,    51,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,     0,     0,     0,   294,   583,   580,   581,   582,   587,
     586,   584,   585,    77,    74,    80,    73,    78,    79,    72,
      76,    75,    70,    71,     0,     0,   335,   119,     0,     0,
       0,   131,     0,   123,   124,   126,   125,     0,     0,     0,
       0,   101,   309,     0,     0,     0,   311,    33,    34,    35,
      36,    37,    38,    39,   227,   228,   222,   237,   236,     0,
     235,   223,   231,   224,   230,   218,   229,   221,   220,   219,
      40,    40,    40,    42,    41,   225,   226,   380,   383,   384,
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
     331,   329,   325,   328,     0,   323,   319,   233,     0,    43,
      44,    45,   386,     0,   280,     0,   241,     0,   261,   258,
     257,     0,     0,     0,     0,     0,     0,     0,   166,     0,
     343,     0,     0,     0,     0,     0,   121,   321,     0,   234,
     387,   281,   242,   171,   193,   169,   197,   192,   183,   173,
     167,   344,   128,   130,   129,   139,   138,   134,   136,   140,
     137,   133,   135,     0,   322,   132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -924,  -924,  -924,  -123,  -308,  -923,  -633,  -924,  -924,   904,
    -924,  -924,    74,  -924,  -924,   536,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,   895,
    -924,  -924,  -924,  -924,  -924,  -924,   372,  -924,  -924,  -924,
    -924,  -924,   267,  -924,  -924,  -924,  -924,  -924,  -924,   610,
    -924,  -924,  -924,  -924,   -90,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,   475,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,   -81,  -924,  -924,  -924,
     785,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,   -59,  -924,
    -924,  -924,  -924,  -924,   -67,  -924,   623,  -924,  -924,  -924,
      25,  -924,  -924,  -924,  -924,  -924,   634,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,   -62,  -924,  -924,  -924,  -924,   571,
    -924,  -924,  -924,  -924,  -924,   873,  -924,  -924,  -924,  -924,
     522,  -924,  -924,  -924,  -924,  -924,   -82,  -924,  -924,  -924,
     542,  -924,  -924,  -924,  -924,   -76,  -924,  -924,  -924,   729,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,   -54,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
     635,  -924,  -924,  -924,  -924,  -924,   732,  -924,  -924,  -924,
    -924,   964,  -924,  -924,  -924,  -924,   874,  -924,  -924,  -924,
    -924,   919,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,   983,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  1010,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924,  -924,   882,  -924,  -924,  -924,  -924,  -924,
    -924,  -924,  -924
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    28,   814,   815,  1023,  1024,    29,    30,    68,
     239,   495,   496,    31,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,    32,    84,    85,
      86,    87,    88,    33,    70,   502,   503,   504,   505,    34,
      77,   579,   580,   581,   582,   583,   584,    35,   291,   292,
     293,   294,   295,   982,   983,   984,   985,   986,  1136,  1213,
      36,    71,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   743,  1108,  1109,    37,    57,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   623,  1009,  1010,    38,
      66,   487,   730,  1074,  1075,   488,   489,   490,  1078,   933,
     934,   491,   492,    39,    64,   467,   468,   469,   470,   471,
     472,   473,   717,  1060,  1061,   474,    40,    72,   533,   534,
     535,   536,   537,    41,   299,   300,   301,    42,    79,   592,
     593,   594,   595,   596,   799,  1154,  1155,    43,    75,   565,
     566,   567,   568,   782,  1131,  1132,    44,    59,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     651,  1036,  1037,   395,   396,   397,   398,    45,    65,   478,
     479,   480,   481,    46,    60,   402,   403,   404,   405,    47,
     144,   145,   146,    48,    62,   412,   413,   414,   415,    49,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    50,   132,   133,   134,   135,   136,
     137,   138,   139,    51,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    52,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     845,   846,   603,    80,   142,   606,   607,   608,    80,   610,
     611,   399,  1007,   297,   297,    55,  1183,   244,  1157,   142,
     978,  1162,  1158,  1034,    56,  1163,    67,  1164,   399,   475,
     409,  1165,    69,   460,   482,  1166,   289,    81,    58,  1167,
     529,   409,    81,   844,   289,    82,    61,  1178,  1180,   238,
      82,  1179,  1181,   461,   148,    63,   245,   562,    73,   149,
     150,    74,   151,   152,   246,   247,   248,   153,    76,   249,
     250,   588,   143,    78,   251,   252,   124,   462,   140,   400,
     154,   155,   156,    53,    54,  1187,   530,   143,  1008,  1188,
     157,   158,   141,   483,   159,   160,   400,  1159,  1160,  1161,
     574,   147,   484,   463,   485,   235,  1020,  1021,  1022,   672,
     236,   674,   675,    83,   499,   678,   161,   162,    83,   499,
     683,   237,   685,   298,   298,   531,    89,   562,   163,   692,
     979,   164,   165,   588,   475,   241,   699,   700,   242,   702,
     410,   166,   167,   243,   401,   708,   709,   710,   288,   168,
     169,   410,   170,   125,   171,    90,    91,   296,   172,   173,
     464,   401,   476,   411,    92,   486,   302,   563,   303,   327,
     174,   126,   127,   532,   411,   978,   175,   304,   176,   177,
     178,   589,   305,   179,   306,   328,   329,   309,   180,   465,
      93,    94,    95,    96,   330,   263,   128,   493,   494,   500,
    1035,   574,   980,  -120,   500,    97,    98,    99,   181,   182,
     575,  -120,   183,   184,   310,   100,   101,   102,   311,   103,
     104,   368,   981,   369,   307,   370,   264,   105,   573,   265,
     586,   506,   761,   546,   477,   407,  1137,   563,   466,   331,
     290,   371,   312,   589,   663,   725,   185,   186,   290,   721,
     732,   507,   571,   187,   188,   266,   757,   669,   497,   564,
     332,   333,   189,   576,   190,   372,   267,   476,   334,   313,
     458,   129,   335,   590,   577,   508,   591,   529,   506,   336,
     373,   501,   374,   578,   314,   979,   501,   801,   337,   338,
     339,   375,   268,   855,   856,   130,  1069,   482,   507,   340,
     315,   509,   316,   376,   269,   270,   460,  1070,   271,   272,
     844,   575,   317,   131,   833,   318,   793,   836,   319,   838,
     341,   320,   508,   530,   843,   321,   461,  1071,   322,   564,
     738,   377,   323,   324,   360,   590,   498,   361,   591,   477,
     362,   510,   325,   783,   597,   342,   363,   364,   509,   867,
     462,   598,   378,   365,   406,   125,   483,   980,   511,   416,
     417,   418,   531,   419,   576,   484,   420,   485,   421,   366,
     599,   379,   422,   126,   127,   577,   463,   981,   423,   424,
     425,   426,   427,   380,   578,   635,   548,   428,   510,   429,
     273,   430,   274,   431,   148,   432,   433,   434,   128,   149,
     150,   435,   151,   152,   436,   511,   437,   153,   438,   439,
     532,   560,   601,   440,   441,   381,   512,   382,   569,   442,
     154,   155,   156,   443,  1051,   444,   445,   513,   486,   514,
     157,   158,   446,   464,   159,   160,   515,   659,   600,   447,
     516,   448,   449,   450,   451,   452,   453,   751,   604,   454,
    1205,   455,  1206,  1072,   456,  1052,   161,   162,   457,  1073,
     538,   539,   465,   512,  1083,   540,   541,   542,   163,   543,
     544,   164,   165,   129,   513,   545,   514,   549,   550,   551,
     552,   166,   167,   515,  1084,  1085,  1053,   516,   553,   168,
     169,   554,   170,   555,   171,   602,  1086,   130,   172,   173,
    1207,   556,  1184,   557,   558,   559,   263,   244,   570,   585,
     174,   466,   605,   609,   612,   131,   175,  1208,   176,   177,
     178,  1054,  1055,   179,   613,   614,   615,  1056,   180,   616,
     617,   620,   618,  1087,  1088,   619,  1089,   264,   621,   622,
     265,   624,  1209,  1210,   625,   626,   245,   627,   181,   182,
     628,  1057,   183,   184,   246,   247,   248,   629,   630,   249,
     250,   631,   632,  1090,   251,   252,   266,  1091,   633,   368,
     634,   369,   637,   370,     2,     3,  1092,   267,     4,   638,
    1121,   639,  1211,   640,   641,   642,   185,   186,  1212,   371,
       5,   643,   645,   187,   188,     6,  1093,     7,  1094,     8,
    1058,  1095,   189,   268,   190,   646,   644,   787,     9,   647,
     648,   665,   649,   372,   650,   269,   270,   652,  1096,   271,
     272,    10,  1059,   653,   654,    11,    12,  1097,   373,  1098,
     374,   655,  1099,   656,  1100,   657,   658,   661,  1101,   375,
     662,  1102,   666,   667,    13,  1122,   668,  1103,    14,  1104,
    1105,   376,   327,   671,   673,   676,   677,   679,    15,    16,
     680,   681,   682,   684,  1106,   686,  1123,   687,   328,   329,
     688,  1124,  1107,  1144,   689,   696,  1125,   330,   697,   377,
     698,   690,    17,    18,   997,   998,   999,  1000,  1001,  1002,
    1003,  1126,   691,  1127,  1128,   693,   694,   695,    19,   701,
     378,   273,   703,   274,   704,   705,   706,   707,  1129,   711,
     712,   715,   713,   714,   727,    20,  1130,   716,   718,   379,
     719,   720,   331,  1076,   759,   735,   723,    21,    22,   724,
     728,   380,  1196,   729,   731,   760,   736,   737,  1145,    23,
     734,   740,   741,   332,   333,   742,   744,    24,   745,   746,
      25,   334,   747,   748,    26,   335,    27,   749,   750,  1146,
      89,   753,   336,   381,  1147,   382,   754,   755,   756,  1148,
     762,   337,   338,   339,   807,   808,   809,   810,   811,   812,
     813,   763,   340,   764,  1149,   765,  1150,  1151,   766,    90,
      91,   767,   768,   769,   770,   771,   779,   772,    92,   773,
     774,  1152,   775,   341,   776,   777,   778,   785,   936,  1153,
     780,   561,  1193,   781,   786,   788,   858,   920,   789,   790,
     795,   791,   792,   796,    93,    94,    95,    96,   342,   797,
     798,   831,   800,   803,   804,   805,   806,   816,   817,    97,
      98,    99,   818,   819,   820,   602,   794,   821,   822,   100,
     101,   102,   823,   103,   104,   824,   825,   826,   827,   828,
     829,   105,   830,   832,   835,   834,   847,   837,   839,   848,
     840,   841,   842,   844,   739,   849,   850,   851,   852,   853,
     854,   857,   859,   860,  1077,   862,   863,   865,   861,   864,
     866,   868,  1138,   870,   869,   871,   872,   874,   873,   875,
     876,   572,   877,   878,   879,   880,   881,   882,   883,   884,
     885,   886,   887,   888,   889,   890,   891,   892,   893,   894,
     895,   896,   897,   898,   899,   900,   901,   902,   903,   904,
     905,   906,   907,   908,   909,   910,   911,   912,   913,   914,
     915,   916,   917,   918,   919,   922,   921,   923,   924,   941,
     926,   925,   927,   928,   929,   930,   937,   931,   932,   938,
     935,   940,   939,   943,   944,   945,   942,   946,   947,   948,
     949,  1171,   975,   240,   950,   951,   952,   953,   994,   308,
     954,   955,   956,   957,   958,   959,   960,   961,   962,   963,
     964,   965,   752,   966,   967,   968,   969,   970,   971,   972,
     973,   974,   976,   987,   977,   988,   989,   990,  1134,  1195,
     991,   992,   993,   995,  1135,  1185,   996,  1004,  1005,  1006,
    1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1038,  1039,
    1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,
    1050,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1079,  1080,
    1081,  1082,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1117,
    1118,  1119,  1120,  1133,  1139,  1140,  1141,  1142,  1143,  1156,
    1168,  1194,  1170,  1172,  1197,  1198,  1173,  1174,  1175,  1176,
    1177,  1182,  1186,  1199,  1202,  1203,  1204,  1215,  1200,  1189,
    1192,   722,  1169,  1191,   758,  1201,  1214,   784,   408,  1190,
     459,   733,   660,   726,   802,   367,   326,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   636,     0,
       0,     0,     0,     0,   664,   547,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   670
};

static const yytype_int16 yycheck[] =
{
     633,   634,   310,     1,     1,   313,   314,   315,     1,   317,
     318,     1,    57,     1,     1,   221,   188,     1,   216,     1,
       1,   216,   220,     8,   221,   220,   214,   216,     1,     1,
       1,   220,   218,     1,     1,   216,     1,    35,   221,   220,
       1,     1,    35,   215,     1,    43,   221,   216,   216,   219,
      43,   220,   220,    21,     1,   221,    40,     1,   221,     6,
       7,   221,     9,    10,    48,    49,    50,    14,   221,    53,
      54,     1,    69,   221,    58,    59,   221,    45,   221,    69,
      27,    28,    29,   216,   217,   216,    47,    69,   133,   220,
      37,    38,   221,    60,    41,    42,    69,  1020,  1021,  1022,
       1,   221,    69,    71,    71,   221,    11,    12,    13,   417,
     221,   419,   420,   111,     1,   423,    63,    64,   111,     1,
     428,   221,   430,   111,   111,    86,     1,     1,    75,   437,
     111,    78,    79,     1,     1,   221,   444,   445,   221,   447,
     111,    88,    89,   221,   134,   453,   454,   455,   221,    96,
      97,   111,    99,     1,   101,    30,    31,   221,   105,   106,
     128,   134,   134,   134,    39,   132,   221,   111,   216,     1,
     117,    19,    20,   134,   134,     1,   123,   218,   125,   126,
     127,   111,   218,   130,   218,    17,    18,   218,   135,   157,
      65,    66,    67,    68,    26,     1,    44,   139,   140,    86,
     185,     1,   183,   168,    86,    80,    81,    82,   155,   156,
     111,   168,   159,   160,   218,    90,    91,    92,   218,    94,
      95,     1,   203,     3,   217,     5,    32,   102,   168,    35,
     217,     1,   540,   217,   206,   217,   217,   111,   206,    71,
     205,    21,   218,   111,   217,   217,   193,   194,   205,   217,
     217,    21,   217,   200,   201,    61,   217,   217,   216,   203,
      92,    93,   209,   164,   211,    45,    72,   134,   100,   218,
     217,   119,   104,   203,   175,    45,   206,     1,     1,   111,
      60,   168,    62,   184,   218,   111,   168,   217,   120,   121,
     122,    71,    98,   170,   171,   143,    22,     1,    21,   131,
     218,    71,   218,    83,   110,   111,     1,    33,   114,   115,
     215,   111,   218,   161,   622,   218,   217,   625,   218,   627,
     152,   218,    45,    47,   632,   218,    21,    53,   218,   203,
     217,   111,   218,   218,   218,   203,   216,   218,   206,   206,
     218,   111,   217,   217,   214,   177,   218,   218,    71,   657,
      45,   214,   132,   218,   218,     1,    60,   183,   128,   218,
     218,   218,    86,   218,   164,    69,   218,    71,   218,   217,
     214,   151,   218,    19,    20,   175,    71,   203,   218,   218,
     218,   218,   218,   163,   184,   217,   216,   218,   111,   218,
     196,   218,   198,   218,     1,   218,   218,   218,    44,     6,
       7,   218,     9,    10,   218,   128,   218,    14,   218,   218,
     134,   217,   215,   218,   218,   195,   186,   197,   216,   218,
      27,    28,    29,   218,    15,   218,   218,   197,   132,   199,
      37,    38,   218,   128,    41,    42,   206,   217,   216,   218,
     210,   218,   218,   218,   218,   218,   218,   217,   192,   218,
      74,   218,    76,   179,   218,    46,    63,    64,   218,   185,
     218,   218,   157,   186,     4,   218,   218,   218,    75,   218,
     218,    78,    79,   119,   197,   218,   199,   218,   218,   218,
     218,    88,    89,   206,    24,    25,    77,   210,   218,    96,
      97,   218,    99,   218,   101,   215,    36,   143,   105,   106,
     124,   218,  1135,   218,   218,   218,     1,     1,   218,   218,
     117,   206,   215,   215,   215,   161,   123,   141,   125,   126,
     127,   112,   113,   130,   215,   215,   215,   118,   135,   215,
     215,   218,   216,    73,    74,   216,    76,    32,   218,   218,
      35,   218,   166,   167,   218,   218,    40,   218,   155,   156,
     218,   142,   159,   160,    48,    49,    50,   218,   218,    53,
      54,   218,   218,   103,    58,    59,    61,   107,   218,     1,
     218,     3,   215,     5,     0,     1,   116,    72,     4,   215,
      76,   192,   206,   215,   214,   214,   193,   194,   212,    21,
      16,   216,   218,   200,   201,    21,   136,    23,   138,    25,
     191,   141,   209,    98,   211,   218,   216,   221,    34,   218,
     218,   214,   218,    45,   218,   110,   111,   218,   158,   114,
     115,    47,   213,   218,   218,    51,    52,   167,    60,   169,
      62,   218,   172,   218,   174,   218,   218,   218,   178,    71,
     218,   181,   216,   218,    70,   141,   218,   187,    74,   189,
     190,    83,     1,   192,   215,   192,   215,   192,    84,    85,
     192,   215,   215,   192,   204,   215,   162,   215,    17,    18,
     215,   167,   212,    76,   215,   192,   172,    26,   214,   111,
     192,   215,   108,   109,   807,   808,   809,   810,   811,   812,
     813,   187,   215,   189,   190,   215,   215,   215,   124,   192,
     132,   196,   192,   198,   215,   192,   192,   215,   204,   192,
     215,   218,   216,   216,   216,   141,   212,   218,   218,   151,
     218,   218,    71,   202,   192,   216,   218,   153,   154,   218,
     218,   163,    87,   218,   218,   192,   218,   218,   141,   165,
     220,   216,   218,    92,    93,   218,   218,   173,   218,   218,
     176,   100,   218,   218,   180,   104,   182,   218,   218,   162,
       1,   216,   111,   195,   167,   197,   218,   218,   218,   172,
     214,   120,   121,   122,   144,   145,   146,   147,   148,   149,
     150,   192,   131,   214,   187,   192,   189,   190,   192,    30,
      31,   216,   215,   214,   192,   214,   216,   215,    39,   214,
     214,   204,   214,   152,   214,   214,   214,   192,   734,   212,
     216,   275,   137,   218,   216,   216,   192,   192,   218,   218,
     214,   218,   218,   216,    65,    66,    67,    68,   177,   216,
     218,   215,   218,   216,   216,   216,   216,   216,   216,    80,
      81,    82,   216,   216,   216,   215,   579,   216,   216,    90,
      91,    92,   216,    94,    95,   216,   216,   216,   216,   216,
     216,   102,   216,   215,   215,   218,   216,   215,   214,   216,
     215,   215,   215,   215,   502,   216,   216,   216,   216,   216,
     214,   214,   214,   214,   220,   214,   214,   214,   218,   215,
     214,   214,   982,   214,   216,   214,   216,   214,   216,   214,
     216,   291,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   214,   214,   218,   214,   214,   192,
     214,   216,   214,   216,   214,   214,   214,   218,   215,   214,
     216,   214,   216,   214,   214,   214,   218,   214,   192,   214,
     214,   219,   218,    69,   216,   214,   214,   214,   218,    84,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   517,   216,   216,   216,   216,   216,   216,   216,
     216,   214,   216,   214,   216,   214,   214,   214,   218,   137,
     216,   216,   214,   214,   218,   218,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     215,   141,   216,   219,   141,   137,   219,   219,   219,   219,
     219,   214,   216,   137,   216,   216,   216,   216,  1179,  1158,
    1167,   467,  1077,  1165,   533,  1181,  1188,   565,   144,  1163,
     191,   488,   383,   478,   592,   132,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,
      -1,    -1,    -1,    -1,   402,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   412
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   223,     0,     1,     4,    16,    21,    23,    25,    34,
      47,    51,    52,    70,    74,    84,    85,   108,   109,   124,
     141,   153,   154,   165,   173,   176,   180,   182,   224,   229,
     230,   235,   249,   255,   261,   269,   282,   299,   321,   335,
     348,   355,   359,   369,   378,   399,   405,   411,   415,   421,
     466,   475,   494,   216,   217,   221,   221,   300,   221,   379,
     406,   221,   416,   221,   336,   400,   322,   214,   231,   218,
     256,   283,   349,   221,   221,   370,   221,   262,   221,   360,
       1,    35,    43,   111,   250,   251,   252,   253,   254,     1,
      30,    31,    39,    65,    66,    67,    68,    80,    81,    82,
      90,    91,    92,    94,    95,   102,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   221,     1,    19,    20,    44,   119,
     143,   161,   467,   468,   469,   470,   471,   472,   473,   474,
     221,   221,     1,    69,   412,   413,   414,   221,     1,     6,
       7,     9,    10,    14,    27,    28,    29,    37,    38,    41,
      42,    63,    64,    75,    78,    79,    88,    89,    96,    97,
      99,   101,   105,   106,   117,   123,   125,   126,   127,   130,
     135,   155,   156,   159,   160,   193,   194,   200,   201,   209,
     211,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   221,   221,   221,   219,   232,
     231,   221,   221,   221,     1,    40,    48,    49,    50,    53,
      54,    58,    59,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,     1,    32,    35,    61,    72,    98,   110,
     111,   114,   115,   196,   198,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   221,     1,
     205,   270,   271,   272,   273,   274,   221,     1,   111,   356,
     357,   358,   221,   216,   218,   218,   218,   217,   251,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   217,   477,     1,    17,    18,
      26,    71,    92,    93,   100,   104,   111,   120,   121,   122,
     131,   152,   177,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     218,   218,   218,   218,   218,   218,   217,   468,     1,     3,
       5,    21,    45,    60,    62,    71,    83,   111,   132,   151,
     163,   195,   197,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   395,   396,   397,   398,     1,
      69,   134,   407,   408,   409,   410,   218,   217,   413,     1,
     111,   134,   417,   418,   419,   420,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   217,   423,
       1,    21,    45,    71,   128,   157,   206,   337,   338,   339,
     340,   341,   342,   343,   347,     1,   134,   206,   401,   402,
     403,   404,     1,    60,    69,    71,   132,   323,   327,   328,
     329,   333,   334,   139,   140,   233,   234,   216,   216,     1,
      86,   168,   257,   258,   259,   260,     1,    21,    45,    71,
     111,   128,   186,   197,   199,   206,   210,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,     1,
      47,    86,   134,   350,   351,   352,   353,   354,   218,   218,
     218,   218,   218,   218,   218,   218,   217,   496,   216,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     217,   237,     1,   111,   203,   371,   372,   373,   374,   216,
     218,   217,   271,   168,     1,   111,   164,   175,   184,   263,
     264,   265,   266,   267,   268,   218,   217,   357,     1,   111,
     203,   206,   361,   362,   363,   364,   365,   214,   214,   214,
     216,   215,   215,   226,   192,   215,   226,   226,   226,   215,
     226,   226,   215,   215,   215,   215,   215,   215,   216,   216,
     218,   218,   218,   318,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   217,   302,   215,   215,   192,
     215,   214,   214,   216,   216,   218,   218,   218,   218,   218,
     218,   392,   218,   218,   218,   218,   218,   218,   218,   217,
     381,   218,   218,   217,   408,   214,   216,   218,   218,   217,
     418,   192,   226,   215,   226,   226,   192,   215,   226,   192,
     192,   215,   215,   226,   192,   226,   215,   215,   215,   215,
     215,   215,   226,   215,   215,   215,   192,   214,   192,   226,
     226,   192,   226,   192,   215,   192,   192,   215,   226,   226,
     226,   192,   215,   216,   216,   218,   218,   344,   218,   218,
     218,   217,   338,   218,   218,   217,   402,   216,   218,   218,
     324,   218,   217,   328,   220,   216,   218,   218,   217,   258,
     216,   218,   218,   296,   218,   218,   218,   218,   218,   218,
     218,   217,   285,   216,   218,   218,   218,   217,   351,   192,
     192,   226,   214,   192,   214,   192,   192,   216,   215,   214,
     192,   214,   215,   214,   214,   214,   214,   214,   214,   216,
     216,   218,   375,   217,   372,   192,   216,   221,   216,   218,
     218,   218,   218,   217,   264,   214,   216,   216,   218,   366,
     218,   217,   362,   216,   216,   216,   216,   144,   145,   146,
     147,   148,   149,   150,   225,   226,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   215,   215,   226,   218,   215,   226,   215,   226,   214,
     215,   215,   215,   226,   215,   228,   228,   216,   216,   216,
     216,   216,   216,   216,   214,   170,   171,   214,   192,   214,
     214,   218,   214,   214,   215,   214,   214,   226,   214,   216,
     214,   214,   216,   216,   214,   214,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   214,
     192,   218,   214,   214,   214,   216,   214,   214,   216,   214,
     214,   218,   215,   331,   332,   216,   234,   214,   214,   216,
     214,   192,   218,   214,   214,   214,   214,   192,   214,   214,
     216,   214,   214,   214,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   214,   218,   216,   216,     1,   111,
     183,   203,   275,   276,   277,   278,   279,   214,   214,   214,
     214,   216,   216,   214,   218,   214,   216,   225,   225,   225,
     225,   225,   225,   225,   216,   216,   216,    57,   133,   319,
     320,   216,   216,   216,   216,   216,   216,   216,   216,   216,
      11,    12,    13,   227,   228,   216,   216,   216,   216,   216,
     216,   216,   216,   216,     8,   185,   393,   394,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,    15,    46,    77,   112,   113,   118,   142,   191,   213,
     345,   346,   216,   216,   216,   216,   216,   216,   216,    22,
      33,    53,   179,   185,   325,   326,   202,   220,   330,   216,
     216,   216,   216,     4,    24,    25,    36,    73,    74,    76,
     103,   107,   116,   136,   138,   141,   158,   167,   169,   172,
     174,   178,   181,   187,   189,   190,   204,   212,   297,   298,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,    76,   141,   162,   167,   172,   187,   189,   190,   204,
     212,   376,   377,   216,   218,   218,   280,   217,   276,   216,
     216,   216,   216,   216,    76,   141,   162,   167,   172,   187,
     189,   190,   204,   212,   367,   368,   216,   216,   220,   227,
     227,   227,   216,   220,   216,   220,   216,   220,   215,   332,
     216,   219,   219,   219,   219,   219,   219,   219,   216,   220,
     216,   220,   214,   188,   228,   218,   216,   216,   220,   320,
     394,   346,   326,   137,   141,   137,    87,   141,   137,   137,
     298,   377,   216,   216,   216,    74,    76,   124,   141,   166,
     167,   206,   212,   281,   368,   216
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   222,   223,   223,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     225,   225,   226,   226,   226,   226,   226,   226,   226,   226,
     227,   227,   228,   228,   228,   228,   229,   230,   231,   232,
     232,   233,   233,   234,   234,   235,   236,   236,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   250,   251,   251,   251,   251,   252,   253,
     254,   256,   255,   257,   257,   258,   258,   258,   259,   260,
     262,   261,   263,   263,   264,   264,   264,   264,   264,   265,
     266,   267,   268,   269,   270,   270,   271,   271,   271,   272,
     274,   273,   275,   275,   276,   276,   276,   276,   277,   278,
     278,   280,   279,   281,   281,   281,   281,   281,   281,   281,
     281,   283,   282,   284,   284,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   296,   295,   297,   297,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   300,   299,
     301,   301,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   318,   317,   319,   319,   320,   320,   322,   321,
     324,   323,   325,   325,   326,   326,   326,   326,   326,   327,
     327,   328,   328,   328,   328,   328,   330,   329,   331,   331,
     332,   332,   333,   334,   336,   335,   337,   337,   338,   338,
     338,   338,   338,   338,   338,   339,   340,   341,   342,   344,
     343,   345,   345,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   347,   349,   348,   350,   350,   351,   351,   351,
     351,   352,   353,   354,   355,   356,   356,   357,   357,   358,
     360,   359,   361,   361,   362,   362,   362,   362,   363,   364,
     366,   365,   367,   367,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   370,   369,   371,   371,   372,   372,
     372,   373,   375,   374,   376,   376,   377,   377,   377,   377,
     377,   377,   377,   377,   377,   377,   379,   378,   380,   380,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   390,   392,   391,   393,   393,   394,
     394,   395,   396,   397,   398,   400,   399,   401,   401,   402,
     402,   402,   403,   404,   406,   405,   407,   407,   408,   408,
     408,   409,   410,   411,   412,   412,   413,   413,   414,   416,
     415,   417,   417,   418,   418,   418,   419,   420,   421,   422,
     422,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   467,   468,
     468,   468,   468,   468,   468,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   476,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     495,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     497,   498,   499,   500,   501,   502,   503,   504
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       0,     1,     2,     3,     3,     3,     3,     3,     3,     3,
       0,     1,     2,     3,     3,     3,     4,     4,     1,     0,
       2,     3,     1,     1,     1,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
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
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
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
  switch (yykind)
    {
    case YYSYMBOL_module_string: /* module_string  */
#line 350 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3160 "conf_parser.c"
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
  case 30: /* timespec_: %empty  */
#line 386 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3433 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER timespec_  */
#line 387 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3439 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER SECONDS timespec_  */
#line 388 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3445 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER MINUTES timespec_  */
#line 389 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3451 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER HOURS timespec_  */
#line 390 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3457 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER DAYS timespec_  */
#line 391 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3463 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER WEEKS timespec_  */
#line 392 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3469 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER MONTHS timespec_  */
#line 393 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3475 "conf_parser.c"
    break;

  case 39: /* timespec: NUMBER YEARS timespec_  */
#line 394 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3481 "conf_parser.c"
    break;

  case 40: /* sizespec_: %empty  */
#line 397 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3487 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER sizespec_  */
#line 398 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3493 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER BYTES sizespec_  */
#line 399 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3499 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER KBYTES sizespec_  */
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3505 "conf_parser.c"
    break;

  case 45: /* sizespec: NUMBER MBYTES sizespec_  */
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3511 "conf_parser.c"
    break;

  case 46: /* module_base_path_entry: MODULE_BASE_PATH '=' module_string ';'  */
#line 409 "conf_parser.y"
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
#line 3528 "conf_parser.c"
    break;

  case 47: /* loadmodule_entry: LOADMODULE module_string module_attributes ';'  */
#line 427 "conf_parser.y"
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
#line 3545 "conf_parser.c"
    break;

  case 48: /* module_string: QSTRING  */
#line 442 "conf_parser.y"
{
  (yyval.string) = io_strdup((yyvsp[0].string));
}
#line 3553 "conf_parser.c"
    break;

  case 49: /* module_attributes: %empty  */
#line 447 "conf_parser.y"
{
  (yyval.number) = 0;
}
#line 3561 "conf_parser.c"
    break;

  case 50: /* module_attributes: ':' module_attributes_items  */
#line 450 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3569 "conf_parser.c"
    break;

  case 51: /* module_attributes_items: module_attributes_items ',' module_attributes_item  */
#line 455 "conf_parser.y"
{
  (yyval.number) = (yyvsp[-2].number) | (yyvsp[0].number);
}
#line 3577 "conf_parser.c"
    break;

  case 52: /* module_attributes_items: module_attributes_item  */
#line 458 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3585 "conf_parser.c"
    break;

  case 53: /* module_attributes_item: RESIDENT  */
#line 463 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_DEACTIVATE;
}
#line 3593 "conf_parser.c"
    break;

  case 54: /* module_attributes_item: REQUIRED  */
#line 466 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_REMOVE;
}
#line 3601 "conf_parser.c"
    break;

  case 70: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 492 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3613 "conf_parser.c"
    break;

  case 71: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 501 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3625 "conf_parser.c"
    break;

  case 72: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 510 "conf_parser.y"
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
#line 3643 "conf_parser.c"
    break;

  case 73: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 525 "conf_parser.y"
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
#line 3661 "conf_parser.c"
    break;

  case 74: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 540 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3674 "conf_parser.c"
    break;

  case 75: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 550 "conf_parser.y"
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
#line 3691 "conf_parser.c"
    break;

  case 76: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 564 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3703 "conf_parser.c"
    break;

  case 77: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 573 "conf_parser.y"
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
#line 3729 "conf_parser.c"
    break;

  case 78: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 596 "conf_parser.y"
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
#line 3755 "conf_parser.c"
    break;

  case 79: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 619 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3767 "conf_parser.c"
    break;

  case 80: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 628 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3776 "conf_parser.c"
    break;

  case 88: /* admin_name: NAME '=' QSTRING ';'  */
#line 646 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3788 "conf_parser.c"
    break;

  case 89: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 655 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3800 "conf_parser.c"
    break;

  case 90: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 664 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3812 "conf_parser.c"
    break;

  case 91: /* $@1: %empty  */
#line 677 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3821 "conf_parser.c"
    break;

  case 92: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 681 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3838 "conf_parser.c"
    break;

  case 98: /* motd_mask: MASK '=' QSTRING ';'  */
#line 698 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3847 "conf_parser.c"
    break;

  case 99: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 704 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3856 "conf_parser.c"
    break;

  case 100: /* $@2: %empty  */
#line 714 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3865 "conf_parser.c"
    break;

  case 101: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 718 "conf_parser.y"
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
#line 3883 "conf_parser.c"
    break;

  case 109: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 736 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3892 "conf_parser.c"
    break;

  case 110: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 742 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3901 "conf_parser.c"
    break;

  case 111: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 748 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3910 "conf_parser.c"
    break;

  case 112: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 754 "conf_parser.y"
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
#line 3932 "conf_parser.c"
    break;

  case 119: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 783 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 3944 "conf_parser.c"
    break;

  case 120: /* $@3: %empty  */
#line 792 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3953 "conf_parser.c"
    break;

  case 121: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 796 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3966 "conf_parser.c"
    break;

  case 128: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 812 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3977 "conf_parser.c"
    break;

  case 129: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 820 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3985 "conf_parser.c"
    break;

  case 130: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 823 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3993 "conf_parser.c"
    break;

  case 131: /* $@4: %empty  */
#line 828 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 4002 "conf_parser.c"
    break;

  case 133: /* logging_file_type_item: USER  */
#line 834 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4011 "conf_parser.c"
    break;

  case 134: /* logging_file_type_item: OPERATOR  */
#line 838 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4020 "conf_parser.c"
    break;

  case 135: /* logging_file_type_item: XLINE  */
#line 842 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4029 "conf_parser.c"
    break;

  case 136: /* logging_file_type_item: RESV  */
#line 846 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4038 "conf_parser.c"
    break;

  case 137: /* logging_file_type_item: T_DLINE  */
#line 850 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4047 "conf_parser.c"
    break;

  case 138: /* logging_file_type_item: KLINE  */
#line 854 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4056 "conf_parser.c"
    break;

  case 139: /* logging_file_type_item: KILL  */
#line 858 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4065 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: T_DEBUG  */
#line 862 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4074 "conf_parser.c"
    break;

  case 141: /* $@5: %empty  */
#line 872 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4086 "conf_parser.c"
    break;

  case 142: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 879 "conf_parser.y"
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
#line 4144 "conf_parser.c"
    break;

  case 156: /* oper_name: NAME '=' QSTRING ';'  */
#line 947 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4153 "conf_parser.c"
    break;

  case 157: /* oper_user: USER '=' QSTRING ';'  */
#line 953 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4162 "conf_parser.c"
    break;

  case 158: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 959 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4171 "conf_parser.c"
    break;

  case 159: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 965 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4180 "conf_parser.c"
    break;

  case 160: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 971 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4194 "conf_parser.c"
    break;

  case 161: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 982 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4203 "conf_parser.c"
    break;

  case 162: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 988 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4217 "conf_parser.c"
    break;

  case 163: /* oper_class: CLASS '=' QSTRING ';'  */
#line 999 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4226 "conf_parser.c"
    break;

  case 164: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1005 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4235 "conf_parser.c"
    break;

  case 165: /* $@6: %empty  */
#line 1011 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4244 "conf_parser.c"
    break;

  case 169: /* oper_flags_item: KILL ':' REMOTE  */
#line 1018 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4253 "conf_parser.c"
    break;

  case 170: /* oper_flags_item: KILL  */
#line 1022 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4262 "conf_parser.c"
    break;

  case 171: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1026 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4271 "conf_parser.c"
    break;

  case 172: /* oper_flags_item: CONNECT  */
#line 1030 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4280 "conf_parser.c"
    break;

  case 173: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1034 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4289 "conf_parser.c"
    break;

  case 174: /* oper_flags_item: SQUIT  */
#line 1038 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4298 "conf_parser.c"
    break;

  case 175: /* oper_flags_item: KLINE  */
#line 1042 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4307 "conf_parser.c"
    break;

  case 176: /* oper_flags_item: UNKLINE  */
#line 1046 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4316 "conf_parser.c"
    break;

  case 177: /* oper_flags_item: T_DLINE  */
#line 1050 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4325 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: T_UNDLINE  */
#line 1054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4334 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: XLINE  */
#line 1058 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4343 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: T_UNXLINE  */
#line 1062 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4352 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: DIE  */
#line 1066 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4361 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: T_RESTART  */
#line 1070 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4370 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1074 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4379 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: REHASH  */
#line 1078 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4388 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: ADMIN  */
#line 1082 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4397 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_GLOBOPS  */
#line 1086 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4406 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_LOCOPS  */
#line 1090 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4415 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: REMOTEBAN  */
#line 1094 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4424 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_SET  */
#line 1098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4433 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: MODULE  */
#line 1102 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4442 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_OPME  */
#line 1106 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4451 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: NICK ':' RESV  */
#line 1110 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4460 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: JOIN ':' RESV  */
#line 1114 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4469 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: RESV  */
#line 1118 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4478 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_UNRESV  */
#line 1122 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4487 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: CLOSE  */
#line 1126 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4496 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1130 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4505 "conf_parser.c"
    break;

  case 198: /* $@7: %empty  */
#line 1140 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.con_freq.value  = CLASS_DEFAULT_CONNECT_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4521 "conf_parser.c"
    break;

  case 199: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1151 "conf_parser.y"
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
#line 4569 "conf_parser.c"
    break;

  case 218: /* class_name: NAME '=' QSTRING ';'  */
#line 1214 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4578 "conf_parser.c"
    break;

  case 219: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1220 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4587 "conf_parser.c"
    break;

  case 220: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1226 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4596 "conf_parser.c"
    break;

  case 221: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1232 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4605 "conf_parser.c"
    break;

  case 222: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1238 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4614 "conf_parser.c"
    break;

  case 223: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1244 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4623 "conf_parser.c"
    break;

  case 224: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1250 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4632 "conf_parser.c"
    break;

  case 225: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1256 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4641 "conf_parser.c"
    break;

  case 226: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1262 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4651 "conf_parser.c"
    break;

  case 227: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1269 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4660 "conf_parser.c"
    break;

  case 228: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1275 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4669 "conf_parser.c"
    break;

  case 229: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1281 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4678 "conf_parser.c"
    break;

  case 230: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1287 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4690 "conf_parser.c"
    break;

  case 231: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1296 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4702 "conf_parser.c"
    break;

  case 232: /* $@8: %empty  */
#line 1305 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4711 "conf_parser.c"
    break;

  case 236: /* class_flags_item: RANDOM_IDLE  */
#line 1312 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4720 "conf_parser.c"
    break;

  case 237: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1316 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4729 "conf_parser.c"
    break;

  case 238: /* $@9: %empty  */
#line 1326 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4738 "conf_parser.c"
    break;

  case 240: /* $@10: %empty  */
#line 1332 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4746 "conf_parser.c"
    break;

  case 244: /* listen_flags_item: T_TLS  */
#line 1338 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4755 "conf_parser.c"
    break;

  case 245: /* listen_flags_item: HIDDEN  */
#line 1342 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4764 "conf_parser.c"
    break;

  case 246: /* listen_flags_item: T_SERVER  */
#line 1346 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4773 "conf_parser.c"
    break;

  case 247: /* listen_flags_item: CLIENT  */
#line 1350 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4782 "conf_parser.c"
    break;

  case 248: /* listen_flags_item: DEFER  */
#line 1354 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4791 "conf_parser.c"
    break;

  case 256: /* $@11: %empty  */
#line 1362 "conf_parser.y"
                                 { reset_block_state(); }
#line 4797 "conf_parser.c"
    break;

  case 260: /* port_item: NUMBER  */
#line 1367 "conf_parser.y"
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
#line 4815 "conf_parser.c"
    break;

  case 261: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1380 "conf_parser.y"
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
#line 4835 "conf_parser.c"
    break;

  case 262: /* listen_address: IP '=' QSTRING ';'  */
#line 1397 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4844 "conf_parser.c"
    break;

  case 263: /* listen_host: HOST '=' QSTRING ';'  */
#line 1403 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4853 "conf_parser.c"
    break;

  case 264: /* $@12: %empty  */
#line 1413 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4862 "conf_parser.c"
    break;

  case 265: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1417 "conf_parser.y"
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
#line 4917 "conf_parser.c"
    break;

  case 275: /* auth_user: USER '=' QSTRING ';'  */
#line 1478 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4926 "conf_parser.c"
    break;

  case 276: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1484 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4935 "conf_parser.c"
    break;

  case 277: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1490 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4944 "conf_parser.c"
    break;

  case 278: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1496 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 4958 "conf_parser.c"
    break;

  case 279: /* $@13: %empty  */
#line 1507 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 4967 "conf_parser.c"
    break;

  case 283: /* auth_flags_item: EXCEED_LIMIT  */
#line 1515 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 4976 "conf_parser.c"
    break;

  case 284: /* auth_flags_item: KLINE_EXEMPT  */
#line 1519 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 4985 "conf_parser.c"
    break;

  case 285: /* auth_flags_item: XLINE_EXEMPT  */
#line 1523 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 4994 "conf_parser.c"
    break;

  case 286: /* auth_flags_item: NEED_IDENT  */
#line 1527 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 5003 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: CAN_FLOOD  */
#line 1531 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 5012 "conf_parser.c"
    break;

  case 288: /* auth_flags_item: NO_TILDE  */
#line 1535 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 5021 "conf_parser.c"
    break;

  case 289: /* auth_flags_item: RESV_EXEMPT  */
#line 1539 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 5030 "conf_parser.c"
    break;

  case 290: /* auth_flags_item: T_WEBIRC  */
#line 1543 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5039 "conf_parser.c"
    break;

  case 291: /* auth_flags_item: NEED_PASSWORD  */
#line 1547 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5048 "conf_parser.c"
    break;

  case 292: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1553 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    log_write(LOG_TYPE_IRCD,
              "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 5063 "conf_parser.c"
    break;

  case 293: /* $@14: %empty  */
#line 1568 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5075 "conf_parser.c"
    break;

  case 294: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1575 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5086 "conf_parser.c"
    break;

  case 301: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1586 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5095 "conf_parser.c"
    break;

  case 302: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1592 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5104 "conf_parser.c"
    break;

  case 303: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1598 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5113 "conf_parser.c"
    break;

  case 309: /* service_name: NAME '=' QSTRING ';'  */
#line 1613 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5128 "conf_parser.c"
    break;

  case 310: /* $@15: %empty  */
#line 1629 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5144 "conf_parser.c"
    break;

  case 311: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1640 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5159 "conf_parser.c"
    break;

  case 318: /* shared_name: NAME '=' QSTRING ';'  */
#line 1655 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5168 "conf_parser.c"
    break;

  case 319: /* shared_user: USER '=' QSTRING ';'  */
#line 1661 "conf_parser.y"
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
#line 5190 "conf_parser.c"
    break;

  case 320: /* $@16: %empty  */
#line 1680 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5199 "conf_parser.c"
    break;

  case 324: /* shared_type_item: KLINE  */
#line 1687 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5208 "conf_parser.c"
    break;

  case 325: /* shared_type_item: UNKLINE  */
#line 1691 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5217 "conf_parser.c"
    break;

  case 326: /* shared_type_item: T_DLINE  */
#line 1695 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5226 "conf_parser.c"
    break;

  case 327: /* shared_type_item: T_UNDLINE  */
#line 1699 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5235 "conf_parser.c"
    break;

  case 328: /* shared_type_item: XLINE  */
#line 1703 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5244 "conf_parser.c"
    break;

  case 329: /* shared_type_item: T_UNXLINE  */
#line 1707 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5253 "conf_parser.c"
    break;

  case 330: /* shared_type_item: RESV  */
#line 1711 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5262 "conf_parser.c"
    break;

  case 331: /* shared_type_item: T_UNRESV  */
#line 1715 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5271 "conf_parser.c"
    break;

  case 332: /* shared_type_item: T_LOCOPS  */
#line 1719 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5280 "conf_parser.c"
    break;

  case 333: /* shared_type_item: T_ALL  */
#line 1723 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5289 "conf_parser.c"
    break;

  case 334: /* $@17: %empty  */
#line 1733 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5303 "conf_parser.c"
    break;

  case 335: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1742 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5316 "conf_parser.c"
    break;

  case 341: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1755 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5325 "conf_parser.c"
    break;

  case 342: /* $@18: %empty  */
#line 1761 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5334 "conf_parser.c"
    break;

  case 346: /* cluster_type_item: KLINE  */
#line 1768 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5343 "conf_parser.c"
    break;

  case 347: /* cluster_type_item: UNKLINE  */
#line 1772 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5352 "conf_parser.c"
    break;

  case 348: /* cluster_type_item: T_DLINE  */
#line 1776 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5361 "conf_parser.c"
    break;

  case 349: /* cluster_type_item: T_UNDLINE  */
#line 1780 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5370 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: XLINE  */
#line 1784 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5379 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: T_UNXLINE  */
#line 1788 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5388 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: RESV  */
#line 1792 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5397 "conf_parser.c"
    break;

  case 353: /* cluster_type_item: T_UNRESV  */
#line 1796 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5406 "conf_parser.c"
    break;

  case 354: /* cluster_type_item: T_LOCOPS  */
#line 1800 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5415 "conf_parser.c"
    break;

  case 355: /* cluster_type_item: T_ALL  */
#line 1804 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5424 "conf_parser.c"
    break;

  case 356: /* $@19: %empty  */
#line 1814 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5438 "conf_parser.c"
    break;

  case 357: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1823 "conf_parser.y"
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
#line 5486 "conf_parser.c"
    break;

  case 375: /* connect_name: NAME '=' QSTRING ';'  */
#line 1885 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5495 "conf_parser.c"
    break;

  case 376: /* connect_host: HOST '=' QSTRING ';'  */
#line 1891 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5504 "conf_parser.c"
    break;

  case 377: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1897 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5513 "conf_parser.c"
    break;

  case 378: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1903 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5522 "conf_parser.c"
    break;

  case 379: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1909 "conf_parser.y"
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
#line 5538 "conf_parser.c"
    break;

  case 380: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1922 "conf_parser.y"
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
#line 5554 "conf_parser.c"
    break;

  case 381: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1935 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5563 "conf_parser.c"
    break;

  case 382: /* connect_port: PORT '=' NUMBER ';'  */
#line 1941 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5572 "conf_parser.c"
    break;

  case 383: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 1947 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5581 "conf_parser.c"
    break;

  case 384: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 1951 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5590 "conf_parser.c"
    break;

  case 385: /* $@20: %empty  */
#line 1957 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5598 "conf_parser.c"
    break;

  case 389: /* connect_flags_item: AUTOCONN  */
#line 1963 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5607 "conf_parser.c"
    break;

  case 390: /* connect_flags_item: T_TLS  */
#line 1967 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5616 "conf_parser.c"
    break;

  case 391: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1973 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5630 "conf_parser.c"
    break;

  case 392: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 1984 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5639 "conf_parser.c"
    break;

  case 393: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 1990 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5648 "conf_parser.c"
    break;

  case 394: /* connect_class: CLASS '=' QSTRING ';'  */
#line 1996 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5657 "conf_parser.c"
    break;

  case 395: /* $@21: %empty  */
#line 2006 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5666 "conf_parser.c"
    break;

  case 396: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2010 "conf_parser.y"
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
#line 5690 "conf_parser.c"
    break;

  case 402: /* kill_user: USER '=' QSTRING ';'  */
#line 2034 "conf_parser.y"
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
#line 5713 "conf_parser.c"
    break;

  case 403: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5722 "conf_parser.c"
    break;

  case 404: /* $@22: %empty  */
#line 2064 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5731 "conf_parser.c"
    break;

  case 405: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2068 "conf_parser.y"
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
#line 5753 "conf_parser.c"
    break;

  case 411: /* deny_ip: IP '=' QSTRING ';'  */
#line 2090 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5762 "conf_parser.c"
    break;

  case 412: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2096 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5771 "conf_parser.c"
    break;

  case 418: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2111 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_error_report("Unable to add D-line exemption");
}
#line 5783 "conf_parser.c"
    break;

  case 419: /* $@23: %empty  */
#line 2124 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5792 "conf_parser.c"
    break;

  case 420: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2128 "conf_parser.y"
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
#line 5812 "conf_parser.c"
    break;

  case 426: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2148 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5821 "conf_parser.c"
    break;

  case 427: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2154 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5830 "conf_parser.c"
    break;

  case 474: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2212 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5838 "conf_parser.c"
    break;

  case 475: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2217 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5846 "conf_parser.c"
    break;

  case 476: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2222 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5854 "conf_parser.c"
    break;

  case 477: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2227 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5862 "conf_parser.c"
    break;

  case 478: /* general_cycle_on_host_change: CYCLE_ON_HOST_CHANGE '=' TBOOL ';'  */
#line 2232 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5870 "conf_parser.c"
    break;

  case 479: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2237 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5878 "conf_parser.c"
    break;

  case 480: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2242 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5886 "conf_parser.c"
    break;

  case 481: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2247 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5894 "conf_parser.c"
    break;

  case 482: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2252 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5902 "conf_parser.c"
    break;

  case 483: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2257 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5910 "conf_parser.c"
    break;

  case 484: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2262 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5918 "conf_parser.c"
    break;

  case 485: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2267 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5926 "conf_parser.c"
    break;

  case 486: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2272 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5934 "conf_parser.c"
    break;

  case 487: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2277 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5942 "conf_parser.c"
    break;

  case 488: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2282 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 5953 "conf_parser.c"
    break;

  case 489: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2290 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5961 "conf_parser.c"
    break;

  case 490: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2295 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5969 "conf_parser.c"
    break;

  case 491: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2300 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5977 "conf_parser.c"
    break;

  case 492: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2305 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5985 "conf_parser.c"
    break;

  case 493: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2310 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5993 "conf_parser.c"
    break;

  case 494: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2315 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6001 "conf_parser.c"
    break;

  case 495: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2320 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6009 "conf_parser.c"
    break;

  case 496: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2325 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6017 "conf_parser.c"
    break;

  case 497: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2330 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6025 "conf_parser.c"
    break;

  case 498: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2335 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6033 "conf_parser.c"
    break;

  case 499: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2340 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6041 "conf_parser.c"
    break;

  case 500: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2345 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6049 "conf_parser.c"
    break;

  case 501: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2350 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6057 "conf_parser.c"
    break;

  case 502: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2355 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6065 "conf_parser.c"
    break;

  case 503: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2360 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6073 "conf_parser.c"
    break;

  case 504: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2365 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6081 "conf_parser.c"
    break;

  case 505: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2370 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6089 "conf_parser.c"
    break;

  case 506: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2375 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6097 "conf_parser.c"
    break;

  case 507: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2380 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6105 "conf_parser.c"
    break;

  case 508: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2385 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6113 "conf_parser.c"
    break;

  case 509: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2390 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6125 "conf_parser.c"
    break;

  case 510: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2399 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6133 "conf_parser.c"
    break;

  case 511: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2404 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6141 "conf_parser.c"
    break;

  case 512: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2409 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6149 "conf_parser.c"
    break;

  case 513: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2414 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6157 "conf_parser.c"
    break;

  case 514: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2419 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6168 "conf_parser.c"
    break;

  case 515: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2427 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6176 "conf_parser.c"
    break;

  case 526: /* cloak_enabled: ENABLED '=' TBOOL ';'  */
#line 2447 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number))
  {
    ConfigCloak.enabled = true;
    cloak_set_enabled();
  }
  else
  {
    ConfigCloak.enabled = false;
    cloak_set_disabled();
  }
}
#line 6196 "conf_parser.c"
    break;

  case 527: /* cloak_cidr_len_ipv4: CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2464 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6208 "conf_parser.c"
    break;

  case 528: /* cloak_cidr_len_ipv6: CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2473 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6220 "conf_parser.c"
    break;

  case 529: /* cloak_num_bits: NUM_BITS '=' NUMBER ';'  */
#line 2482 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6232 "conf_parser.c"
    break;

  case 530: /* cloak_secret: SECRET '=' QSTRING ';'  */
#line 2491 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.secret);
  ConfigCloak.secret = io_strdup((yyvsp[-1].string));
  cloak_set_secret((yyvsp[-1].string));
}
#line 6245 "conf_parser.c"
    break;

  case 531: /* cloak_suffix: SUFFIX '=' QSTRING ';'  */
#line 2501 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.suffix);
  ConfigCloak.suffix = io_strdup((yyvsp[-1].string));
  cloak_set_suffix((yyvsp[-1].string));
}
#line 6258 "conf_parser.c"
    break;

  case 552: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2536 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6266 "conf_parser.c"
    break;

  case 553: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2541 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6274 "conf_parser.c"
    break;

  case 554: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2546 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6282 "conf_parser.c"
    break;

  case 555: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2551 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6290 "conf_parser.c"
    break;

  case 556: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2556 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6298 "conf_parser.c"
    break;

  case 557: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2561 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6306 "conf_parser.c"
    break;

  case 558: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2566 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6314 "conf_parser.c"
    break;

  case 559: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2571 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6322 "conf_parser.c"
    break;

  case 560: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2576 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6330 "conf_parser.c"
    break;

  case 561: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2581 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6338 "conf_parser.c"
    break;

  case 562: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2586 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6346 "conf_parser.c"
    break;

  case 563: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2591 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6354 "conf_parser.c"
    break;

  case 564: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2596 "conf_parser.y"
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
#line 6380 "conf_parser.c"
    break;

  case 565: /* channel_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 2619 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigChannel.max_topic_length = TOPICLEN;
  else
    ConfigChannel.max_topic_length = (yyvsp[-1].number);
}
#line 6391 "conf_parser.c"
    break;

  case 566: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2627 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6399 "conf_parser.c"
    break;

  case 567: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2632 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6407 "conf_parser.c"
    break;

  case 580: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2654 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6416 "conf_parser.c"
    break;

  case 581: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2660 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6430 "conf_parser.c"
    break;

  case 582: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2671 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6442 "conf_parser.c"
    break;

  case 583: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2680 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6451 "conf_parser.c"
    break;

  case 584: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2686 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6460 "conf_parser.c"
    break;

  case 585: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2692 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6469 "conf_parser.c"
    break;

  case 586: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2698 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6481 "conf_parser.c"
    break;

  case 587: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2707 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6490 "conf_parser.c"
    break;


#line 6494 "conf_parser.c"

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

