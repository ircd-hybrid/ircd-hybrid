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
    DEFAULT_FLOODCOUNT = 282,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 283,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 284, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 285, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 286,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 287,                   /* DEFER  */
    DENY = 288,                    /* DENY  */
    DESCRIPTION = 289,             /* DESCRIPTION  */
    DIE = 290,                     /* DIE  */
    DISABLE_DNS = 291,             /* DISABLE_DNS  */
    DISABLE_IDENT = 292,           /* DISABLE_IDENT  */
    DISABLE_FAKE_CHANNELS = 293,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 294, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 295,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 296,         /* DLINE_MIN_CIDR6  */
    EMAIL = 297,                   /* EMAIL  */
    ENABLED = 298,                 /* ENABLED  */
    ENCRYPTED = 299,               /* ENCRYPTED  */
    EXCEED_LIMIT = 300,            /* EXCEED_LIMIT  */
    EXEMPT = 301,                  /* EXEMPT  */
    FLATTEN_LINKS = 302,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 303,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 304,      /* FLATTEN_LINKS_FILE  */
    GECOS = 305,                   /* GECOS  */
    GENERAL = 306,                 /* GENERAL  */
    HIDDEN = 307,                  /* HIDDEN  */
    HIDDEN_NAME = 308,             /* HIDDEN_NAME  */
    HIDE_CHANS = 309,              /* HIDE_CHANS  */
    HIDE_IDLE = 310,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 311,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVERS = 312,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 313,           /* HIDE_SERVICES  */
    HOST = 314,                    /* HOST  */
    HUB = 315,                     /* HUB  */
    HUB_MASK = 316,                /* HUB_MASK  */
    IDENT_TIMEOUT = 317,           /* IDENT_TIMEOUT  */
    INVISIBLE_ON_CONNECT = 318,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 319,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 320,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 321,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 322,      /* INVITE_EXPIRE_TIME  */
    IP = 323,                      /* IP  */
    IRCD_AUTH = 324,               /* IRCD_AUTH  */
    IRCD_FLAGS = 325,              /* IRCD_FLAGS  */
    IRCD_SID = 326,                /* IRCD_SID  */
    JOIN = 327,                    /* JOIN  */
    KILL = 328,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 329,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 330,                   /* KLINE  */
    KLINE_EXEMPT = 331,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 332,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 333,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 334,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 335,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 336,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 337,               /* LEAF_MASK  */
    LISTEN = 338,                  /* LISTEN  */
    LOADMODULE = 339,              /* LOADMODULE  */
    MASK = 340,                    /* MASK  */
    MASS = 341,                    /* MASS  */
    MAX_ACCEPT = 342,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 343,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 344,                /* MAX_BANS  */
    MAX_BANS_LARGE = 345,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 346,            /* MAX_CHANNELS  */
    MAX_IDLE = 347,                /* MAX_IDLE  */
    MAX_INVITES = 348,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 349,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 350,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 351,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 352,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 353,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 354,              /* MAX_NUMBER  */
    MAX_TARGETS = 355,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 356,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 357,                 /* MESSAGE  */
    MIN_IDLE = 358,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 359,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 360,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 361,                  /* MODULE  */
    MODULE_BASE_PATH = 362,        /* MODULE_BASE_PATH  */
    MOTD = 363,                    /* MOTD  */
    MOTD_FILE = 364,               /* MOTD_FILE  */
    NAME = 365,                    /* NAME  */
    NEED_IDENT = 366,              /* NEED_IDENT  */
    NEED_PASSWORD = 367,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 368,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 369,            /* NETWORK_NAME  */
    NICK = 370,                    /* NICK  */
    NO_OPER_FLOOD = 371,           /* NO_OPER_FLOOD  */
    NO_TILDE = 372,                /* NO_TILDE  */
    NUM_BITS = 373,                /* NUM_BITS  */
    NUMBER_PER_CIDR = 374,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 375,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 376,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 377,             /* OPER_UMODES  */
    OPERATOR = 378,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 379,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 380,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 381,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 382,                /* PASSWORD  */
    PATH = 383,                    /* PATH  */
    PING_COOKIE = 384,             /* PING_COOKIE  */
    PING_TIME = 385,               /* PING_TIME  */
    PORT = 386,                    /* PORT  */
    RANDOM_IDLE = 387,             /* RANDOM_IDLE  */
    REASON = 388,                  /* REASON  */
    REGISTRATION_TIMEOUT = 389,    /* REGISTRATION_TIMEOUT  */
    REHASH = 390,                  /* REHASH  */
    REMOTE = 391,                  /* REMOTE  */
    REMOTEBAN = 392,               /* REMOTEBAN  */
    REQUIRED = 393,                /* REQUIRED  */
    RESIDENT = 394,                /* RESIDENT  */
    RESV = 395,                    /* RESV  */
    RESV_EXEMPT = 396,             /* RESV_EXEMPT  */
    SECRET = 397,                  /* SECRET  */
    SECONDS = 398,                 /* SECONDS  */
    MINUTES = 399,                 /* MINUTES  */
    HOURS = 400,                   /* HOURS  */
    DAYS = 401,                    /* DAYS  */
    WEEKS = 402,                   /* WEEKS  */
    MONTHS = 403,                  /* MONTHS  */
    YEARS = 404,                   /* YEARS  */
    SEND_PASSWORD = 405,           /* SEND_PASSWORD  */
    SENDQ = 406,                   /* SENDQ  */
    SERVERHIDE = 407,              /* SERVERHIDE  */
    SERVERINFO = 408,              /* SERVERINFO  */
    SHORT_MOTD = 409,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 410,       /* SPECIALS_IN_IDENT  */
    SPOOF = 411,                   /* SPOOF  */
    SQUIT = 412,                   /* SQUIT  */
    STATS_E_DISABLED = 413,        /* STATS_E_DISABLED  */
    STATS_U_OPER_ONLY = 414,       /* STATS_U_OPER_ONLY  */
    SUFFIX = 415,                  /* SUFFIX  */
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
#define CIDR_LEN_IPV4 274
#define CIDR_LEN_IPV6 275
#define CLASS 276
#define CLIENT 277
#define CLOAK 278
#define CLOSE 279
#define CONNECT 280
#define CONNECTFREQ 281
#define DEFAULT_FLOODCOUNT 282
#define DEFAULT_FLOODTIME 283
#define DEFAULT_JOIN_FLOOD_COUNT 284
#define DEFAULT_JOIN_FLOOD_TIME 285
#define DEFAULT_MAX_CLIENTS 286
#define DEFER 287
#define DENY 288
#define DESCRIPTION 289
#define DIE 290
#define DISABLE_DNS 291
#define DISABLE_IDENT 292
#define DISABLE_FAKE_CHANNELS 293
#define DISABLE_REMOTE_COMMANDS 294
#define DLINE_MIN_CIDR 295
#define DLINE_MIN_CIDR6 296
#define EMAIL 297
#define ENABLED 298
#define ENCRYPTED 299
#define EXCEED_LIMIT 300
#define EXEMPT 301
#define FLATTEN_LINKS 302
#define FLATTEN_LINKS_DELAY 303
#define FLATTEN_LINKS_FILE 304
#define GECOS 305
#define GENERAL 306
#define HIDDEN 307
#define HIDDEN_NAME 308
#define HIDE_CHANS 309
#define HIDE_IDLE 310
#define HIDE_IDLE_FROM_OPERS 311
#define HIDE_SERVERS 312
#define HIDE_SERVICES 313
#define HOST 314
#define HUB 315
#define HUB_MASK 316
#define IDENT_TIMEOUT 317
#define INVISIBLE_ON_CONNECT 318
#define INVITE_CLIENT_COUNT 319
#define INVITE_CLIENT_TIME 320
#define INVITE_DELAY_CHANNEL 321
#define INVITE_EXPIRE_TIME 322
#define IP 323
#define IRCD_AUTH 324
#define IRCD_FLAGS 325
#define IRCD_SID 326
#define JOIN 327
#define KILL 328
#define KILL_CHASE_TIME_LIMIT 329
#define KLINE 330
#define KLINE_EXEMPT 331
#define KLINE_MIN_CIDR 332
#define KLINE_MIN_CIDR6 333
#define KNOCK_CLIENT_COUNT 334
#define KNOCK_CLIENT_TIME 335
#define KNOCK_DELAY_CHANNEL 336
#define LEAF_MASK 337
#define LISTEN 338
#define LOADMODULE 339
#define MASK 340
#define MASS 341
#define MAX_ACCEPT 342
#define MAX_AWAY_LENGTH 343
#define MAX_BANS 344
#define MAX_BANS_LARGE 345
#define MAX_CHANNELS 346
#define MAX_IDLE 347
#define MAX_INVITES 348
#define MAX_KICK_LENGTH 349
#define MAX_MONITOR 350
#define MAX_NICK_CHANGES 351
#define MAX_NICK_LENGTH 352
#define MAX_NICK_TIME 353
#define MAX_NUMBER 354
#define MAX_TARGETS 355
#define MAX_TOPIC_LENGTH 356
#define MESSAGE 357
#define MIN_IDLE 358
#define MIN_NONWILDCARD 359
#define MIN_NONWILDCARD_SIMPLE 360
#define MODULE 361
#define MODULE_BASE_PATH 362
#define MOTD 363
#define MOTD_FILE 364
#define NAME 365
#define NEED_IDENT 366
#define NEED_PASSWORD 367
#define NETWORK_DESCRIPTION 368
#define NETWORK_NAME 369
#define NICK 370
#define NO_OPER_FLOOD 371
#define NO_TILDE 372
#define NUM_BITS 373
#define NUMBER_PER_CIDR 374
#define NUMBER_PER_IP_GLOBAL 375
#define NUMBER_PER_IP_LOCAL 376
#define OPER_UMODES 377
#define OPERATOR 378
#define OPERS_BYPASS_CALLERID 379
#define PACE_WAIT 380
#define PACE_WAIT_SIMPLE 381
#define PASSWORD 382
#define PATH 383
#define PING_COOKIE 384
#define PING_TIME 385
#define PORT 386
#define RANDOM_IDLE 387
#define REASON 388
#define REGISTRATION_TIMEOUT 389
#define REHASH 390
#define REMOTE 391
#define REMOTEBAN 392
#define REQUIRED 393
#define RESIDENT 394
#define RESV 395
#define RESV_EXEMPT 396
#define SECRET 397
#define SECONDS 398
#define MINUTES 399
#define HOURS 400
#define DAYS 401
#define WEEKS 402
#define MONTHS 403
#define YEARS 404
#define SEND_PASSWORD 405
#define SENDQ 406
#define SERVERHIDE 407
#define SERVERINFO 408
#define SHORT_MOTD 409
#define SPECIALS_IN_IDENT 410
#define SPOOF 411
#define SQUIT 412
#define STATS_E_DISABLED 413
#define STATS_U_OPER_ONLY 414
#define SUFFIX 415
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
  YYSYMBOL_CIDR_LEN_IPV4 = 19,             /* CIDR_LEN_IPV4  */
  YYSYMBOL_CIDR_LEN_IPV6 = 20,             /* CIDR_LEN_IPV6  */
  YYSYMBOL_CLASS = 21,                     /* CLASS  */
  YYSYMBOL_CLIENT = 22,                    /* CLIENT  */
  YYSYMBOL_CLOAK = 23,                     /* CLOAK  */
  YYSYMBOL_CLOSE = 24,                     /* CLOSE  */
  YYSYMBOL_CONNECT = 25,                   /* CONNECT  */
  YYSYMBOL_CONNECTFREQ = 26,               /* CONNECTFREQ  */
  YYSYMBOL_DEFAULT_FLOODCOUNT = 27,        /* DEFAULT_FLOODCOUNT  */
  YYSYMBOL_DEFAULT_FLOODTIME = 28,         /* DEFAULT_FLOODTIME  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_COUNT = 29,  /* DEFAULT_JOIN_FLOOD_COUNT  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_TIME = 30,   /* DEFAULT_JOIN_FLOOD_TIME  */
  YYSYMBOL_DEFAULT_MAX_CLIENTS = 31,       /* DEFAULT_MAX_CLIENTS  */
  YYSYMBOL_DEFER = 32,                     /* DEFER  */
  YYSYMBOL_DENY = 33,                      /* DENY  */
  YYSYMBOL_DESCRIPTION = 34,               /* DESCRIPTION  */
  YYSYMBOL_DIE = 35,                       /* DIE  */
  YYSYMBOL_DISABLE_DNS = 36,               /* DISABLE_DNS  */
  YYSYMBOL_DISABLE_IDENT = 37,             /* DISABLE_IDENT  */
  YYSYMBOL_DISABLE_FAKE_CHANNELS = 38,     /* DISABLE_FAKE_CHANNELS  */
  YYSYMBOL_DISABLE_REMOTE_COMMANDS = 39,   /* DISABLE_REMOTE_COMMANDS  */
  YYSYMBOL_DLINE_MIN_CIDR = 40,            /* DLINE_MIN_CIDR  */
  YYSYMBOL_DLINE_MIN_CIDR6 = 41,           /* DLINE_MIN_CIDR6  */
  YYSYMBOL_EMAIL = 42,                     /* EMAIL  */
  YYSYMBOL_ENABLED = 43,                   /* ENABLED  */
  YYSYMBOL_ENCRYPTED = 44,                 /* ENCRYPTED  */
  YYSYMBOL_EXCEED_LIMIT = 45,              /* EXCEED_LIMIT  */
  YYSYMBOL_EXEMPT = 46,                    /* EXEMPT  */
  YYSYMBOL_FLATTEN_LINKS = 47,             /* FLATTEN_LINKS  */
  YYSYMBOL_FLATTEN_LINKS_DELAY = 48,       /* FLATTEN_LINKS_DELAY  */
  YYSYMBOL_FLATTEN_LINKS_FILE = 49,        /* FLATTEN_LINKS_FILE  */
  YYSYMBOL_GECOS = 50,                     /* GECOS  */
  YYSYMBOL_GENERAL = 51,                   /* GENERAL  */
  YYSYMBOL_HIDDEN = 52,                    /* HIDDEN  */
  YYSYMBOL_HIDDEN_NAME = 53,               /* HIDDEN_NAME  */
  YYSYMBOL_HIDE_CHANS = 54,                /* HIDE_CHANS  */
  YYSYMBOL_HIDE_IDLE = 55,                 /* HIDE_IDLE  */
  YYSYMBOL_HIDE_IDLE_FROM_OPERS = 56,      /* HIDE_IDLE_FROM_OPERS  */
  YYSYMBOL_HIDE_SERVERS = 57,              /* HIDE_SERVERS  */
  YYSYMBOL_HIDE_SERVICES = 58,             /* HIDE_SERVICES  */
  YYSYMBOL_HOST = 59,                      /* HOST  */
  YYSYMBOL_HUB = 60,                       /* HUB  */
  YYSYMBOL_HUB_MASK = 61,                  /* HUB_MASK  */
  YYSYMBOL_IDENT_TIMEOUT = 62,             /* IDENT_TIMEOUT  */
  YYSYMBOL_INVISIBLE_ON_CONNECT = 63,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 64,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 65,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 66,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 67,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 68,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 69,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 70,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 71,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 72,                      /* JOIN  */
  YYSYMBOL_KILL = 73,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 74,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 75,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 76,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 77,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 78,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 79,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 80,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 81,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 82,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 83,                    /* LISTEN  */
  YYSYMBOL_LOADMODULE = 84,                /* LOADMODULE  */
  YYSYMBOL_MASK = 85,                      /* MASK  */
  YYSYMBOL_MASS = 86,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 87,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_AWAY_LENGTH = 88,           /* MAX_AWAY_LENGTH  */
  YYSYMBOL_MAX_BANS = 89,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 90,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 91,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 92,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 93,               /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 94,           /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 95,               /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 96,          /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 97,           /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 98,             /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 99,                /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 100,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 101,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 102,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 103,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 104,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 105,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 106,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 107,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 108,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 109,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 110,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 111,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 112,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 113,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 114,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 115,                     /* NICK  */
  YYSYMBOL_NO_OPER_FLOOD = 116,            /* NO_OPER_FLOOD  */
  YYSYMBOL_NO_TILDE = 117,                 /* NO_TILDE  */
  YYSYMBOL_NUM_BITS = 118,                 /* NUM_BITS  */
  YYSYMBOL_NUMBER_PER_CIDR = 119,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 120,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 121,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_UMODES = 122,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 123,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 124,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 125,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 126,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 127,                 /* PASSWORD  */
  YYSYMBOL_PATH = 128,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 129,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 130,                /* PING_TIME  */
  YYSYMBOL_PORT = 131,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 132,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 133,                   /* REASON  */
  YYSYMBOL_REGISTRATION_TIMEOUT = 134,     /* REGISTRATION_TIMEOUT  */
  YYSYMBOL_REHASH = 135,                   /* REHASH  */
  YYSYMBOL_REMOTE = 136,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 137,                /* REMOTEBAN  */
  YYSYMBOL_REQUIRED = 138,                 /* REQUIRED  */
  YYSYMBOL_RESIDENT = 139,                 /* RESIDENT  */
  YYSYMBOL_RESV = 140,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 141,              /* RESV_EXEMPT  */
  YYSYMBOL_SECRET = 142,                   /* SECRET  */
  YYSYMBOL_SECONDS = 143,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 144,                  /* MINUTES  */
  YYSYMBOL_HOURS = 145,                    /* HOURS  */
  YYSYMBOL_DAYS = 146,                     /* DAYS  */
  YYSYMBOL_WEEKS = 147,                    /* WEEKS  */
  YYSYMBOL_MONTHS = 148,                   /* MONTHS  */
  YYSYMBOL_YEARS = 149,                    /* YEARS  */
  YYSYMBOL_SEND_PASSWORD = 150,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 151,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 152,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 153,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 154,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 155,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 156,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 157,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 158,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_U_OPER_ONLY = 159,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_SUFFIX = 160,                   /* SUFFIX  */
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
  YYSYMBOL_general_dline_min_cidr = 427,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 428,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 429,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 430,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 431, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_anti_nick_flood = 432,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 433,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 434, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 435,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 436,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 437, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 438,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 439,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 440, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 441, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 442, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_u_oper_only = 443, /* general_stats_u_oper_only  */
  YYSYMBOL_general_pace_wait = 444,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 445,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 446, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 447, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 448,       /* general_short_motd  */
  YYSYMBOL_general_no_oper_flood = 449,    /* general_no_oper_flood  */
  YYSYMBOL_general_specials_in_ident = 450, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 451,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 452,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_ident = 453,    /* general_disable_ident  */
  YYSYMBOL_general_disable_dns = 454,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 455,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 456,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 457,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 458,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 459, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 460, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 461, /* general_default_floodtime  */
  YYSYMBOL_general_ident_timeout = 462,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 463, /* general_registration_timeout  */
  YYSYMBOL_cloak_entry = 464,              /* cloak_entry  */
  YYSYMBOL_cloak_items = 465,              /* cloak_items  */
  YYSYMBOL_cloak_item = 466,               /* cloak_item  */
  YYSYMBOL_cloak_enabled = 467,            /* cloak_enabled  */
  YYSYMBOL_cloak_cidr_len_ipv4 = 468,      /* cloak_cidr_len_ipv4  */
  YYSYMBOL_cloak_cidr_len_ipv6 = 469,      /* cloak_cidr_len_ipv6  */
  YYSYMBOL_cloak_num_bits = 470,           /* cloak_num_bits  */
  YYSYMBOL_cloak_secret = 471,             /* cloak_secret  */
  YYSYMBOL_cloak_suffix = 472,             /* cloak_suffix  */
  YYSYMBOL_channel_entry = 473,            /* channel_entry  */
  YYSYMBOL_channel_items = 474,            /* channel_items  */
  YYSYMBOL_channel_item = 475,             /* channel_item  */
  YYSYMBOL_channel_disable_fake_channels = 476, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 477, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 478, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 479, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 480, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 481, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 482, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 483, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 484,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 485,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 486,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 487,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 488,  /* channel_max_kick_length  */
  YYSYMBOL_channel_max_topic_length = 489, /* channel_max_topic_length  */
  YYSYMBOL_channel_default_join_flood_count = 490, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 491, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 492,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 493,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 494,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 495, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 496, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 497, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 498, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 499,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 500, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 501,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 502         /* serverhide_hidden  */
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
#define YYLAST   1165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  221
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  282
/* YYNRULES -- Number of rules.  */
#define YYNRULES  585
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1211

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
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     385,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     396,   396,   397,   398,   399,   400,   407,   425,   440,   446,
     448,   453,   456,   461,   464,   473,   475,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     490,   499,   508,   523,   538,   548,   562,   571,   594,   617,
     626,   636,   638,   638,   639,   640,   641,   642,   644,   653,
     662,   676,   675,   693,   693,   694,   694,   694,   696,   702,
     713,   712,   731,   731,   732,   732,   732,   732,   732,   734,
     740,   746,   752,   775,   776,   776,   778,   778,   779,   781,
     791,   791,   804,   805,   807,   807,   808,   808,   810,   818,
     821,   827,   826,   832,   836,   840,   844,   848,   852,   856,
     860,   871,   870,   932,   932,   933,   934,   935,   936,   937,
     938,   939,   940,   941,   942,   943,   945,   951,   957,   963,
     969,   980,   986,   997,  1003,  1010,  1009,  1015,  1015,  1016,
    1020,  1024,  1028,  1032,  1036,  1040,  1044,  1048,  1052,  1056,
    1060,  1064,  1068,  1072,  1076,  1080,  1084,  1088,  1092,  1096,
    1100,  1104,  1108,  1112,  1116,  1120,  1124,  1128,  1139,  1138,
    1194,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,
    1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1212,  1218,
    1224,  1230,  1236,  1242,  1248,  1254,  1260,  1267,  1273,  1279,
    1285,  1294,  1304,  1303,  1309,  1309,  1310,  1314,  1325,  1324,
    1331,  1330,  1335,  1335,  1336,  1340,  1344,  1348,  1352,  1358,
    1358,  1359,  1359,  1359,  1359,  1359,  1361,  1361,  1363,  1363,
    1365,  1378,  1395,  1401,  1412,  1411,  1467,  1467,  1468,  1469,
    1470,  1471,  1472,  1473,  1474,  1476,  1482,  1488,  1494,  1506,
    1505,  1511,  1511,  1513,  1517,  1521,  1525,  1529,  1533,  1537,
    1541,  1545,  1551,  1567,  1566,  1581,  1581,  1582,  1582,  1582,
    1582,  1584,  1590,  1596,  1606,  1608,  1608,  1609,  1609,  1611,
    1628,  1627,  1650,  1650,  1651,  1651,  1651,  1651,  1653,  1659,
    1679,  1678,  1684,  1684,  1685,  1689,  1693,  1697,  1701,  1705,
    1709,  1713,  1717,  1721,  1732,  1731,  1750,  1750,  1751,  1751,
    1751,  1753,  1760,  1759,  1765,  1765,  1766,  1770,  1774,  1778,
    1782,  1786,  1790,  1794,  1798,  1802,  1813,  1812,  1866,  1866,
    1867,  1868,  1869,  1870,  1871,  1872,  1873,  1874,  1875,  1876,
    1877,  1878,  1879,  1880,  1881,  1883,  1889,  1895,  1901,  1907,
    1920,  1933,  1939,  1945,  1949,  1956,  1955,  1960,  1960,  1961,
    1965,  1971,  1982,  1988,  1994,  2005,  2004,  2029,  2029,  2030,
    2030,  2030,  2032,  2052,  2063,  2062,  2085,  2085,  2086,  2086,
    2086,  2088,  2094,  2104,  2106,  2106,  2107,  2107,  2109,  2123,
    2122,  2143,  2143,  2144,  2144,  2144,  2146,  2152,  2162,  2164,
    2164,  2165,  2166,  2167,  2168,  2169,  2170,  2171,  2172,  2173,
    2174,  2175,  2176,  2177,  2178,  2179,  2180,  2181,  2182,  2183,
    2184,  2185,  2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,
    2194,  2195,  2196,  2197,  2198,  2199,  2200,  2201,  2202,  2203,
    2204,  2205,  2206,  2209,  2214,  2219,  2224,  2229,  2234,  2239,
    2244,  2249,  2254,  2259,  2264,  2269,  2274,  2282,  2287,  2292,
    2297,  2302,  2307,  2312,  2317,  2322,  2327,  2332,  2337,  2342,
    2347,  2352,  2357,  2362,  2367,  2372,  2377,  2382,  2391,  2396,
    2401,  2406,  2411,  2419,  2428,  2430,  2430,  2431,  2432,  2433,
    2434,  2435,  2436,  2437,  2439,  2456,  2465,  2474,  2483,  2493,
    2507,  2509,  2509,  2510,  2511,  2512,  2513,  2514,  2515,  2516,
    2517,  2518,  2519,  2520,  2521,  2522,  2523,  2524,  2525,  2526,
    2528,  2533,  2538,  2543,  2548,  2553,  2558,  2563,  2568,  2573,
    2578,  2583,  2588,  2611,  2619,  2624,  2633,  2635,  2635,  2636,
    2637,  2638,  2639,  2640,  2641,  2642,  2643,  2644,  2646,  2652,
    2663,  2672,  2678,  2684,  2690,  2699
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
  "CLOAK", "CLOSE", "CONNECT", "CONNECTFREQ", "DEFAULT_FLOODCOUNT",
  "DEFAULT_FLOODTIME", "DEFAULT_JOIN_FLOOD_COUNT",
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
  "general_whowas_history_length", "general_dline_min_cidr",
  "general_dline_min_cidr6", "general_kline_min_cidr",
  "general_kline_min_cidr6", "general_kill_chase_time_limit",
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
  "general_ident_timeout", "general_registration_timeout", "cloak_entry",
  "cloak_items", "cloak_item", "cloak_enabled", "cloak_cidr_len_ipv4",
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

#define YYPACT_NINF (-1005)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1005,   624, -1005,  -150,  -206,  -199, -1005,  -191, -1005, -1005,
    -189, -1005,  -186, -1005, -1005, -1005,  -164,  -165, -1005, -1005,
   -1005,  -144,  -136, -1005,  -135, -1005,  -125, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005,   272,   727,  -116,   412,  -115,
    -114,    52,  -110,   388,  -102,   -83,   -78, -1005,   -85,  -164,
     -77,   -73,   -65,   638,   410,   -59,   128,   -57,    24,   -56,
     -47,   -44,   -37,   -31,    16, -1005, -1005, -1005, -1005, -1005,
     -24,   -21,   -18,   -15,   -13,   -11,    -7,     4,    45,    82,
      85,    86,    88,    93,    98,   103,     7, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005,   559, -1005,   107,   108,   112,   113,
     116,   117,   258, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
     550,    23, -1005,   118,    54, -1005, -1005,    29, -1005,   119,
     121,   122,   123,   124,   126,   127,   129,   132,   133,   134,
     135,   142,   143,   144,   145,   149,   150,   151,   154,   155,
     156,   171,   174,   176,   188,   191,   195,   197,   203,   204,
     205,   206,   210,   213,   216,   217,   218,   219,   221,   222,
      53, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005,   326,    55,   286,   -69,   172,   225,    14,
     336,   363, -1005,   226,   228,   230,   232,   242,   244,   247,
     250,   236, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005,   227,   252,   254,   255,   256,   260,   263,   268,   270,
     274,   277,   278,   158, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005,   199,   282,   281,    76,
   -1005, -1005, -1005,   322,   316, -1005,   284,     3, -1005, -1005,
      15, -1005,    36,    78,   289,   288, -1005,   295,   297,   324,
     302,   297,   297,   297,   304,   297,   297,   311,   312,   313,
     314,   315,   319,   321, -1005,   323,   320,   327,   332, -1005,
     339,   340,   341,   342,   352,   357,   358,   361,   362,   365,
     366,   106, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,   370,   372,
     349,   375,   378,   379,   380, -1005,   382,   376,   385,   386,
     391,   395,   397, -1005,   398,   399,   401,   406,   409,   413,
     414,   169, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,   416,   417,
      34, -1005, -1005, -1005,   422,   426, -1005, -1005,   420,   429,
      50, -1005, -1005, -1005,   457,   297,   438,   297,   297,   439,
     297,   463,   464,   442,   445,   297,   470,   297,   449,   450,
     451,   452,   453,   454,   297,   458,   459,   462,   480,   471,
     492,   297,   297,   503,   297,   507,   485,   510,   511,   490,
     297,   297,   297,   514,   495,   491, -1005,   496,   497,   498,
   -1005,   499,   500,   502,   170, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005,   504,   505,   153, -1005, -1005, -1005,   512,
     508,   509, -1005,   513, -1005,   165, -1005, -1005, -1005, -1005,
   -1005, -1005,   200, -1005, -1005, -1005,   518,   519,   520,    18,
   -1005, -1005, -1005,   524,   525,   526, -1005,   528,   531,   533,
     536,   537,   541,   542,   194, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005,   545,   544,   551,   553,
      32, -1005, -1005, -1005, -1005,   529,   571,   297,   554,   578,
     558,   581,   582,   560, -1005, -1005,   572,   574,   594,   576,
     583,   577,   585,   587,   588,   589,   591,   580, -1005,   595,
     592, -1005,    74, -1005, -1005, -1005, -1005,   620,   597, -1005,
     593,   599,   598,   602,   605,   606,    91, -1005, -1005, -1005,
   -1005, -1005,   611,   610, -1005,   612,   609, -1005,   613,    42,
   -1005, -1005, -1005, -1005,   614,   616,   617, -1005,   618,   635,
     619,   621,   622,   623,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   636,   637, -1005, -1005,   639,   640,   297,
     641,   642,   297,   643,   297,   646,   647,   648,   649,   297,
     650,   650,   645, -1005,   651,   652,   653,   654,   655,   656,
   -1005, -1005,   659,   -87,   660,   644,   661,   662,   663,   664,
     665,   667,   666,   669,   297,   670,   671, -1005,   672,   674,
     673, -1005,   675, -1005,   676,   678,   677, -1005,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,   706,   707,   708,   709,   710,
     711,   712,   713,   714,   715,   716,   717,   718,   719, -1005,
   -1005,   722,   745,   720,   725,   726,   728,   729, -1005,   730,
     732,   731, -1005, -1005,   734,   735,   723,   736,   737, -1005,
     -69, -1005,   738,   740,   739, -1005, -1005,   742,   751,   741,
     743,   744,   746,   747,   758,   748,   749,   750, -1005, -1005,
     753,   754,   755,   756, -1005,   757,   759,   760,   761,   762,
     763,   764,   765, -1005,   766,   767,   768,   769,   770,   771,
     772,   773,   774,   775,   776, -1005, -1005,   779,   752,   778,
   -1005,   780, -1005,   202, -1005,   781,   783,   784,   785,   786,
   -1005,   787, -1005, -1005,   790,   782,   791,   792, -1005, -1005,
   -1005, -1005, -1005,   297,   297,   297,   297,   297,   297,   297,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005,   793,   794,   795,
     -53,   796,   797,   798,   799,   800,   801,   802,   803,   804,
      27,   805,   806, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
     807,   808,   809,   810,   811,   812,   813,    10,   814,   815,
     816,   817,   818,   819,   820, -1005,   821,   822, -1005, -1005,
     823,   824, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005,   825,   826,   266,   827,   828,   829,
   -1005,   830,   831, -1005,   832,   833,   276,   848,   657, -1005,
   -1005, -1005,   835,   836, -1005,   837,   838,   433,   839,   840,
     841,   842,   843,   844,   845, -1005,   846,   847,   849, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,   850,
     552, -1005, -1005,   851,   788,   789, -1005,    40, -1005, -1005,
   -1005, -1005,   852,   853,   854,   855, -1005, -1005,   856,   563,
     857, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005,  -193, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005,   650,   650,   650, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005,  -192, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005,  -187, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,  -173,
   -1005,   859,   736,   860, -1005, -1005, -1005, -1005, -1005, -1005,
     858, -1005,   861,   862, -1005,   863, -1005,   864,   865, -1005,
   -1005,   866, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005,  -171, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005,  -158, -1005, -1005,   872,
    -167,   869,   873, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,  -151,
   -1005, -1005, -1005,   -53, -1005, -1005, -1005, -1005,    10, -1005,
     266, -1005,   276, -1005, -1005, -1005,   834,   923,   938,   877,
     937,   942,   951, -1005,   433, -1005,   552,   874,   875,   876,
     477, -1005, -1005,   563, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,   878, -1005,
   -1005
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
       0,     0,     0,     0,     0,    83,    84,    86,    85,   549,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   532,   548,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   533,   534,
     544,   545,   546,   547,     0,   523,     0,     0,     0,     0,
       0,     0,     0,   516,   517,   518,   519,   520,   521,   522,
       0,     0,   417,     0,     0,   415,   416,     0,   472,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   430,   431,   432,   469,   437,   464,   465,   466,   467,
     441,   433,   434,   435,   436,   451,   438,   439,   440,   442,
     443,   468,   445,   446,   453,   454,   447,   448,   449,   444,
     450,   461,   462,   463,   459,   460,   452,   457,   458,   455,
     456,   470,   471,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   577,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   568,   569,   570,   571,   572,   573,   574,   576,
     575,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,    68,    66,    58,    67,    60,
      61,    62,    63,    64,    65,    59,     0,     0,     0,     0,
     115,   116,   117,     0,     0,   308,     0,     0,   306,   307,
       0,    87,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   531,     0,     0,     0,     0,   232,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,   202,   205,   207,   208,   209,   210,   211,
     212,   213,   203,   204,   206,   214,   215,   216,     0,     0,
       0,     0,     0,     0,     0,   515,     0,     0,     0,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
       0,     0,   359,   360,   361,   362,   363,   364,   365,   366,
     368,   367,   369,   373,   370,   371,   372,   410,     0,     0,
       0,   407,   408,   409,     0,     0,   414,   425,     0,     0,
       0,   422,   423,   424,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   429,     0,     0,     0,
     279,     0,     0,     0,     0,   267,   268,   269,   270,   273,
     271,   272,   401,     0,     0,     0,   398,   399,   400,     0,
       0,     0,   240,     0,   252,     0,   250,   251,   253,   254,
      54,    53,    50,    52,    47,    46,     0,     0,     0,     0,
      94,    95,    96,     0,     0,     0,   165,     0,     0,     0,
       0,     0,     0,     0,     0,   144,   145,   146,   147,   148,
     151,   152,   153,   150,   149,   154,     0,     0,     0,     0,
       0,   296,   297,   298,   299,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   567,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
       0,   342,     0,   337,   338,   339,   118,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   106,
     105,   107,     0,     0,   305,     0,     0,   320,     0,     0,
     313,   314,   315,   316,     0,     0,     0,    81,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   530,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
     514,   374,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   358,     0,     0,
       0,   406,     0,   413,     0,     0,     0,   421,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   428,
     274,     0,     0,     0,     0,     0,     0,     0,   266,     0,
       0,     0,   397,   255,     0,     0,     0,     0,     0,   249,
       0,    97,     0,     0,     0,    93,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   300,
       0,     0,     0,     0,   295,     0,     0,     0,     0,     0,
       0,     0,     0,   566,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,   340,     0,     0,     0,
     336,     0,   113,     0,   108,     0,     0,     0,     0,     0,
     102,     0,   304,   317,     0,     0,     0,     0,   312,    90,
      89,    88,   564,    30,    30,    30,    30,    30,    30,    30,
      32,    31,   565,   550,   551,   552,   553,   554,   555,   556,
     557,   560,   561,   558,   559,   562,   563,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,     0,     0,   199,   525,   526,   524,   527,   528,   529,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   357,     0,     0,   405,   418,
       0,     0,   420,   482,   487,   473,   474,   495,   510,   511,
     504,   503,   477,   478,   512,   490,   481,   479,   480,   485,
     486,   475,   484,   483,   501,   508,   509,   499,   507,   496,
     494,   497,   502,   513,   498,   500,   492,   493,   505,   506,
     489,   488,   491,   476,     0,     0,     0,     0,     0,     0,
     265,     0,     0,   396,     0,     0,     0,   260,   256,   259,
     239,    51,     0,     0,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,     0,     0,     0,   294,
     581,   578,   579,   580,   585,   584,   582,   583,    77,    74,
      80,    73,    78,    79,    72,    76,    75,    70,    71,     0,
       0,   335,   119,     0,     0,     0,   131,     0,   123,   124,
     126,   125,     0,     0,     0,     0,   101,   309,     0,     0,
       0,   311,    33,    34,    35,    36,    37,    38,    39,   227,
     228,   222,   237,   236,     0,   235,   223,   231,   224,   230,
     218,   229,   221,   220,   219,    40,    40,    40,    42,    41,
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
     323,   319,   233,     0,    43,    44,    45,   386,     0,   280,
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
   -1005, -1005, -1005,  -242,  -306, -1004,  -630, -1005, -1005,   895,
   -1005, -1005,   109, -1005, -1005,   867, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,   889,
   -1005, -1005, -1005, -1005, -1005, -1005,   351, -1005, -1005, -1005,
   -1005, -1005,   279, -1005, -1005, -1005, -1005, -1005, -1005,   604,
   -1005, -1005, -1005, -1005,  -112, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005,   486, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005,  -290, -1005, -1005, -1005,
     777, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,   -61, -1005,
   -1005, -1005, -1005, -1005,   -68, -1005,   615, -1005, -1005, -1005,
      25, -1005, -1005, -1005, -1005, -1005,   634, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005,   -64, -1005, -1005, -1005, -1005,   565,
   -1005, -1005, -1005, -1005, -1005,   868, -1005, -1005, -1005, -1005,
     515, -1005, -1005, -1005, -1005, -1005,   -84, -1005, -1005, -1005,
     539, -1005, -1005, -1005, -1005,   -74, -1005, -1005, -1005,   724,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005,   -55, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
     658, -1005, -1005, -1005, -1005, -1005,   721, -1005, -1005, -1005,
   -1005,   962, -1005, -1005, -1005, -1005,   733, -1005, -1005, -1005,
   -1005,   917, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005,   976, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005,  1003, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005, -1005,   871, -1005, -1005, -1005, -1005, -1005, -1005,
   -1005, -1005
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    28,   810,   811,  1018,  1019,    29,    30,    68,
     237,   492,   493,    31,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,    32,    84,    85,
      86,    87,    88,    33,    70,   499,   500,   501,   502,    34,
      77,   576,   577,   578,   579,   580,   581,    35,   289,   290,
     291,   292,   293,   977,   978,   979,   980,   981,  1131,  1208,
      36,    71,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   739,  1103,  1104,    37,    57,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   620,  1004,  1005,    38,
      66,   484,   726,  1069,  1070,   485,   486,   487,  1073,   928,
     929,   488,   489,    39,    64,   464,   465,   466,   467,   468,
     469,   470,   713,  1055,  1056,   471,    40,    72,   530,   531,
     532,   533,   534,    41,   297,   298,   299,    42,    79,   589,
     590,   591,   592,   593,   795,  1149,  1150,    43,    75,   562,
     563,   564,   565,   778,  1126,  1127,    44,    59,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     648,  1031,  1032,   393,   394,   395,   396,    45,    65,   475,
     476,   477,   478,    46,    60,   400,   401,   402,   403,    47,
     144,   145,   146,    48,    62,   410,   411,   412,   413,    49,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    50,   132,   133,   134,   135,   136,   137,
     138,   139,    51,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    52,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     841,   842,   600,  1002,   295,   603,   604,   605,    89,   607,
     608,  1154,  1155,  1156,    55,   496,   585,    80,  1029,   496,
    1178,    56,  1152,  1157,   397,   295,  1153,  1158,  1159,    58,
     407,    61,  1160,   526,    63,   397,    90,    91,  1015,  1016,
    1017,   973,  1161,   585,  1173,    92,  1162,   840,  1174,    67,
      81,   407,    69,   142,   148,   142,   472,  1175,    82,   149,
     150,  1176,   151,   152,  1182,    53,    54,   153,  1183,   490,
     491,    93,    94,    95,    96,   559,    73,   287,   527,  1003,
     154,   155,   851,   852,    74,    76,    97,    98,    99,   156,
     157,   398,   571,   158,   159,    78,   100,   101,   102,   497,
     103,   104,   398,   497,   124,   140,   141,   325,   105,   669,
     147,   671,   672,   296,   674,   160,   161,   528,   233,   679,
     143,   681,   143,   326,   327,   586,    83,   162,   688,   287,
     163,   164,   328,   236,   296,   695,   696,   234,   698,   408,
     165,   166,   235,   239,   704,   705,   706,   240,   167,   168,
     974,   169,   586,   170,   472,   241,   399,   171,   172,   261,
     408,   286,   409,   294,   300,   529,   479,   399,   301,   173,
     366,   457,   367,   302,   368,   174,   329,   175,   176,   177,
     303,   498,   178,   409,   560,   498,   304,   179,   473,   262,
     369,   458,   263,   307,  1030,   503,   308,   330,   331,   309,
     559,   572,   310,   973,   311,   332,   312,   180,   181,   333,
     313,   182,   183,   370,   459,   504,   334,   587,   264,   583,
     588,   314,   975,   323,   480,   335,   336,   337,   371,   265,
     372,   757,   305,   481,   734,   482,   338,   242,   505,   373,
     460,   840,   976,  -120,   587,   184,   185,   588,   753,   594,
     660,   374,   186,   187,   573,   266,  1132,   339,   797,   125,
     474,   188,   315,   189,   506,   574,   666,   267,   268,   455,
     405,   269,   270,    80,   575,   243,   561,   126,   127,   375,
     288,  1046,   340,   244,   245,   246,   473,   479,   247,   248,
     779,   595,   568,   249,   250,  -120,   483,   461,  1064,   316,
     376,   128,   317,   318,   507,   319,    81,   789,  1065,   560,
     320,  1047,   974,   829,    82,   321,   832,   571,   834,   377,
     322,   508,   632,   839,   358,   359,   462,   457,  1066,   360,
     361,   378,   288,   362,   363,   404,   414,   503,   415,   416,
     417,   418,  1048,   419,   420,   480,   421,   458,   863,   422,
     423,   424,   425,   271,   481,   272,   482,   504,   474,   426,
     427,   428,   429,   379,   526,   380,   430,   431,   432,   721,
     459,   433,   434,   435,   557,   463,   129,  1049,  1050,   509,
     505,   728,    83,  1051,   975,   656,   717,   494,   436,   148,
     510,   437,   511,   438,   149,   150,   460,   151,   152,   512,
     130,   561,   153,   513,   976,   439,   506,  1052,   440,   527,
     747,   261,   441,   125,   442,   154,   155,   483,   131,   730,
     443,   444,   445,   446,   156,   157,   572,   447,   158,   159,
     448,   126,   127,   449,   450,   451,   452,  1078,   453,   454,
     495,   262,   545,   535,   263,   536,   507,   537,   528,   538,
     160,   161,   543,   461,  1067,   128,  1053,  1079,  1080,   539,
    1068,   540,   162,   508,   541,   163,   164,   542,  1081,   546,
     264,   547,   548,   549,   364,   165,   166,   550,  1054,   573,
     551,   265,   462,   167,   168,   552,   169,   553,   170,   570,
     574,   554,   171,   172,   555,   556,   529,   566,   567,   575,
    1179,   582,   596,   597,   173,  1082,  1083,   266,  1084,   598,
     174,   599,   175,   176,   177,   601,   602,   178,   606,   267,
     268,   509,   179,   269,   270,   609,   610,   611,   612,   613,
     129,   463,   510,   614,   511,  1085,   615,   617,   616,  1086,
     636,   512,   180,   181,   618,   513,   182,   183,  1087,   619,
    1200,   366,  1201,   367,   130,   368,   621,   622,   623,   624,
     325,   992,   993,   994,   995,   996,   997,   998,  1088,   625,
    1089,   369,   131,  1090,   626,   627,   326,   327,   628,   629,
     184,   185,   630,   631,   634,   328,   635,   186,   187,   637,
    1091,   638,   639,   642,   370,   640,   188,   641,   189,  1092,
    1202,  1093,   643,   644,  1094,   271,  1095,   272,   645,   371,
    1096,   372,   646,  1097,   647,   649,   650,  1203,   651,  1098,
     373,  1099,  1100,   652,     2,     3,   653,  1116,     4,   329,
     654,   655,   374,   658,   659,   662,  1101,   664,  1139,   242,
       5,   663,  1204,  1205,  1102,     6,   665,     7,   668,     8,
     330,   331,   670,   673,   675,   676,   677,     9,   332,   678,
     375,   680,   333,   682,   683,   684,   685,   686,   687,   334,
      10,   692,   689,   690,    11,    12,   691,   243,   335,   336,
     337,   376,  1206,   694,   693,   244,   245,   246,  1207,   338,
     247,   248,  1117,    13,   697,   249,   250,    14,   699,   700,
     377,   701,   702,  1140,   703,   707,   709,    15,    16,   708,
     339,   710,   378,  1118,   711,   712,   714,   715,  1119,   716,
     755,   719,   720,  1120,  1141,   724,   725,   723,    89,  1142,
     727,    17,    18,   731,  1143,   340,   732,   733,  1121,   736,
    1122,  1123,   737,   738,   379,   740,   380,    19,   741,  1144,
     742,  1145,  1146,   743,   744,  1124,    90,    91,   745,   746,
     749,   750,   756,  1125,    20,    92,  1147,   758,   751,   759,
     752,   760,   761,   762,  1148,   763,    21,    22,   803,   804,
     805,   806,   807,   808,   809,   766,   764,   765,    23,   767,
     769,    93,    94,    95,    96,   775,    24,   768,   770,    25,
     771,   772,   773,    26,   774,    27,    97,    98,    99,   777,
     776,   781,   782,   783,   784,   785,   100,   101,   102,   786,
     103,   104,   787,   788,   791,   792,   794,   793,   105,   799,
     796,   800,   801,   802,   812,   854,   813,   814,   815,   931,
     816,   817,   818,   819,   820,   821,   822,   823,   824,   599,
     735,   825,   826,   827,   828,   790,   831,   833,   830,   835,
     843,   836,   837,   838,   840,  1133,   844,   845,   846,   847,
     848,   849,   850,   853,   855,   856,  1072,   858,   859,   861,
     857,   860,   862,   864,  1195,   866,   865,   867,   868,   870,
     869,   871,   872,   569,   873,   874,   875,   876,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,   887,   888,
     889,   890,   891,   892,   893,   894,   895,   896,   897,   898,
     899,   900,   901,   902,   903,   904,   905,   906,   907,   908,
     909,   910,   911,   912,   913,   914,   915,   916,   917,   918,
     926,   919,   936,   921,   920,   922,   923,   924,   925,   942,
     927,   932,   930,   933,   934,   935,   938,   939,   937,   940,
     941,   943,   944,  1191,   238,   945,   946,   947,   948,   970,
    1188,   949,   950,   306,   951,   952,   953,   954,   955,   956,
     957,   958,   959,   960,   961,   962,   963,   964,   965,   966,
     967,   968,   969,   971,   982,   972,   983,   984,   985,   989,
     748,   986,   987,   988,   990,  1129,  1130,   991,   999,  1000,
    1001,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,
    1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1033,
    1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,
    1044,  1045,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1071,
    1074,  1075,  1076,  1077,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,  1189,  1114,  1115,  1128,  1134,  1135,  1136,
    1137,  1138,  1151,  1163,  1190,  1165,  1166,  1192,  1193,  1167,
    1168,  1169,  1170,  1171,  1172,  1177,  1180,  1194,  1181,  1197,
    1198,  1199,  1184,  1210,  1187,   754,  1186,  1164,   718,  1209,
     729,   780,  1196,  1185,   798,   657,   406,   456,   365,   324,
       0,     0,     0,     0,     0,     0,     0,     0,   633,     0,
       0,   661,   544,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   722,     0,     0,     0,     0,     0,     0,
     558,     0,     0,   667,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   584
};

static const yytype_int16 yycheck[] =
{
     630,   631,   308,    56,     1,   311,   312,   313,     1,   315,
     316,  1015,  1016,  1017,   220,     1,     1,     1,     8,     1,
     187,   220,   215,   215,     1,     1,   219,   219,   215,   220,
       1,   220,   219,     1,   220,     1,    29,    30,    11,    12,
      13,     1,   215,     1,   215,    38,   219,   214,   219,   213,
      34,     1,   217,     1,     1,     1,     1,   215,    42,     6,
       7,   219,     9,    10,   215,   215,   216,    14,   219,   138,
     139,    64,    65,    66,    67,     1,   220,     1,    46,   132,
      27,    28,   169,   170,   220,   220,    79,    80,    81,    36,
      37,    68,     1,    40,    41,   220,    89,    90,    91,    85,
      93,    94,    68,    85,   220,   220,   220,     1,   101,   415,
     220,   417,   418,   110,   420,    62,    63,    85,   220,   425,
      68,   427,    68,    17,    18,   110,   110,    74,   434,     1,
      77,    78,    26,   218,   110,   441,   442,   220,   444,   110,
      87,    88,   220,   220,   450,   451,   452,   220,    95,    96,
     110,    98,   110,   100,     1,   220,   133,   104,   105,     1,
     110,   220,   133,   220,   220,   133,     1,   133,   215,   116,
       1,     1,     3,   217,     5,   122,    70,   124,   125,   126,
     217,   167,   129,   133,   110,   167,   217,   134,   133,    31,
      21,    21,    34,   217,   184,     1,   217,    91,    92,   217,
       1,   110,   217,     1,   217,    99,   217,   154,   155,   103,
     217,   158,   159,    44,    44,    21,   110,   202,    60,   216,
     205,   217,   182,   216,    59,   119,   120,   121,    59,    71,
      61,   537,   216,    68,   216,    70,   130,     1,    44,    70,
      70,   214,   202,   167,   202,   192,   193,   205,   216,   213,
     216,    82,   199,   200,   163,    97,   216,   151,   216,     1,
     205,   208,   217,   210,    70,   174,   216,   109,   110,   216,
     216,   113,   114,     1,   183,    39,   202,    19,    20,   110,
     204,    15,   176,    47,    48,    49,   133,     1,    52,    53,
     216,   213,   216,    57,    58,   167,   131,   127,    22,   217,
     131,    43,   217,   217,   110,   217,    34,   216,    32,   110,
     217,    45,   110,   619,    42,   217,   622,     1,   624,   150,
     217,   127,   216,   629,   217,   217,   156,     1,    52,   217,
     217,   162,   204,   217,   217,   217,   217,     1,   217,   217,
     217,   217,    76,   217,   217,    59,   217,    21,   654,   217,
     217,   217,   217,   195,    68,   197,    70,    21,   205,   217,
     217,   217,   217,   194,     1,   196,   217,   217,   217,   216,
      44,   217,   217,   217,   216,   205,   118,   111,   112,   185,
      44,   216,   110,   117,   182,   216,   216,   215,   217,     1,
     196,   217,   198,   217,     6,     7,    70,     9,    10,   205,
     142,   202,    14,   209,   202,   217,    70,   141,   217,    46,
     216,     1,   217,     1,   217,    27,    28,   131,   160,   219,
     217,   217,   217,   217,    36,    37,   110,   217,    40,    41,
     217,    19,    20,   217,   217,   217,   217,     4,   217,   217,
     215,    31,   215,   217,    34,   217,   110,   217,    85,   217,
      62,    63,   216,   127,   178,    43,   190,    24,    25,   217,
     184,   217,    74,   127,   217,    77,    78,   217,    35,   217,
      60,   217,   217,   217,   216,    87,    88,   217,   212,   163,
     217,    71,   156,    95,    96,   217,    98,   217,   100,   167,
     174,   217,   104,   105,   217,   217,   133,   215,   217,   183,
    1130,   217,   213,   215,   116,    72,    73,    97,    75,   214,
     122,   214,   124,   125,   126,   191,   214,   129,   214,   109,
     110,   185,   134,   113,   114,   214,   214,   214,   214,   214,
     118,   205,   196,   214,   198,   102,   215,   217,   215,   106,
     191,   205,   154,   155,   217,   209,   158,   159,   115,   217,
      73,     1,    75,     3,   142,     5,   217,   217,   217,   217,
       1,   803,   804,   805,   806,   807,   808,   809,   135,   217,
     137,    21,   160,   140,   217,   217,    17,    18,   217,   217,
     192,   193,   217,   217,   214,    26,   214,   199,   200,   214,
     157,   213,   213,   217,    44,   215,   208,   215,   210,   166,
     123,   168,   217,   217,   171,   195,   173,   197,   217,    59,
     177,    61,   217,   180,   217,   217,   217,   140,   217,   186,
      70,   188,   189,   217,     0,     1,   217,    75,     4,    70,
     217,   217,    82,   217,   217,   213,   203,   217,    75,     1,
      16,   215,   165,   166,   211,    21,   217,    23,   191,    25,
      91,    92,   214,   214,   191,   191,   214,    33,    99,   214,
     110,   191,   103,   214,   214,   214,   214,   214,   214,   110,
      46,   191,   214,   214,    50,    51,   214,    39,   119,   120,
     121,   131,   205,   191,   213,    47,    48,    49,   211,   130,
      52,    53,   140,    69,   191,    57,    58,    73,   191,   214,
     150,   191,   191,   140,   214,   191,   215,    83,    84,   214,
     151,   215,   162,   161,   217,   217,   217,   217,   166,   217,
     191,   217,   217,   171,   161,   217,   217,   215,     1,   166,
     217,   107,   108,   215,   171,   176,   217,   217,   186,   215,
     188,   189,   217,   217,   194,   217,   196,   123,   217,   186,
     217,   188,   189,   217,   217,   203,    29,    30,   217,   217,
     215,   217,   191,   211,   140,    38,   203,   213,   217,   191,
     217,   213,   191,   191,   211,   215,   152,   153,   143,   144,
     145,   146,   147,   148,   149,   191,   214,   213,   164,   213,
     213,    64,    65,    66,    67,   215,   172,   214,   213,   175,
     213,   213,   213,   179,   213,   181,    79,    80,    81,   217,
     215,   191,   215,   220,   215,   217,    89,    90,    91,   217,
      93,    94,   217,   217,   213,   215,   217,   215,   101,   215,
     217,   215,   215,   215,   215,   191,   215,   215,   215,   730,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   214,
     499,   215,   215,   214,   214,   576,   214,   214,   217,   213,
     215,   214,   214,   214,   214,   977,   215,   215,   215,   215,
     215,   215,   213,   213,   213,   213,   219,   213,   213,   213,
     217,   214,   213,   213,  1174,   213,   215,   213,   215,   213,
     215,   213,   215,   289,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   213,   191,   217,   213,   213,
     217,   213,   191,   213,   215,   213,   215,   213,   213,   191,
     214,   213,   215,   213,   215,   213,   213,   213,   217,   213,
     213,   213,   213,    86,    69,   215,   213,   213,   213,   217,
     136,   215,   215,    84,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   213,   215,   213,   215,   213,   213,   213,   217,
     514,   215,   215,   213,   213,   217,   217,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   201,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   140,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   214,   136,   215,   218,   140,   136,   218,
     218,   218,   218,   218,   218,   213,   217,   136,   215,   215,
     215,   215,  1153,   215,  1162,   530,  1160,  1072,   464,  1183,
     485,   562,  1176,  1158,   589,   381,   144,   190,   132,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,    -1,
      -1,   400,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   475,    -1,    -1,    -1,    -1,    -1,    -1,
     273,    -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   297
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   222,     0,     1,     4,    16,    21,    23,    25,    33,
      46,    50,    51,    69,    73,    83,    84,   107,   108,   123,
     140,   152,   153,   164,   172,   175,   179,   181,   223,   228,
     229,   234,   248,   254,   260,   268,   281,   298,   320,   334,
     347,   354,   358,   368,   377,   398,   404,   410,   414,   420,
     464,   473,   492,   215,   216,   220,   220,   299,   220,   378,
     405,   220,   415,   220,   335,   399,   321,   213,   230,   217,
     255,   282,   348,   220,   220,   369,   220,   261,   220,   359,
       1,    34,    42,   110,   249,   250,   251,   252,   253,     1,
      29,    30,    38,    64,    65,    66,    67,    79,    80,    81,
      89,    90,    91,    93,    94,   101,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   220,     1,    19,    20,    43,   118,
     142,   160,   465,   466,   467,   468,   469,   470,   471,   472,
     220,   220,     1,    68,   411,   412,   413,   220,     1,     6,
       7,     9,    10,    14,    27,    28,    36,    37,    40,    41,
      62,    63,    74,    77,    78,    87,    88,    95,    96,    98,
     100,   104,   105,   116,   122,   124,   125,   126,   129,   134,
     154,   155,   158,   159,   192,   193,   199,   200,   208,   210,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   220,   220,   220,   218,   231,   230,   220,
     220,   220,     1,    39,    47,    48,    49,    52,    53,    57,
      58,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,     1,    31,    34,    60,    71,    97,   109,   110,   113,
     114,   195,   197,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   220,     1,   204,   269,
     270,   271,   272,   273,   220,     1,   110,   355,   356,   357,
     220,   215,   217,   217,   217,   216,   250,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   216,   475,     1,    17,    18,    26,    70,
      91,    92,    99,   103,   110,   119,   120,   121,   130,   151,
     176,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   217,   217,
     217,   217,   217,   217,   216,   466,     1,     3,     5,    21,
      44,    59,    61,    70,    82,   110,   131,   150,   162,   194,
     196,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   394,   395,   396,   397,     1,    68,   133,
     406,   407,   408,   409,   217,   216,   412,     1,   110,   133,
     416,   417,   418,   419,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   216,   422,     1,    21,    44,
      70,   127,   156,   205,   336,   337,   338,   339,   340,   341,
     342,   346,     1,   133,   205,   400,   401,   402,   403,     1,
      59,    68,    70,   131,   322,   326,   327,   328,   332,   333,
     138,   139,   232,   233,   215,   215,     1,    85,   167,   256,
     257,   258,   259,     1,    21,    44,    70,   110,   127,   185,
     196,   198,   205,   209,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     1,    46,    85,   133,
     349,   350,   351,   352,   353,   217,   217,   217,   217,   217,
     217,   217,   217,   216,   494,   215,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   216,   236,     1,
     110,   202,   370,   371,   372,   373,   215,   217,   216,   270,
     167,     1,   110,   163,   174,   183,   262,   263,   264,   265,
     266,   267,   217,   216,   356,     1,   110,   202,   205,   360,
     361,   362,   363,   364,   213,   213,   213,   215,   214,   214,
     225,   191,   214,   225,   225,   225,   214,   225,   225,   214,
     214,   214,   214,   214,   214,   215,   215,   217,   217,   217,
     317,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   216,   301,   214,   214,   191,   214,   213,   213,
     215,   215,   217,   217,   217,   217,   217,   217,   391,   217,
     217,   217,   217,   217,   217,   217,   216,   380,   217,   217,
     216,   407,   213,   215,   217,   217,   216,   417,   191,   225,
     214,   225,   225,   214,   225,   191,   191,   214,   214,   225,
     191,   225,   214,   214,   214,   214,   214,   214,   225,   214,
     214,   214,   191,   213,   191,   225,   225,   191,   225,   191,
     214,   191,   191,   214,   225,   225,   225,   191,   214,   215,
     215,   217,   217,   343,   217,   217,   217,   216,   337,   217,
     217,   216,   401,   215,   217,   217,   323,   217,   216,   327,
     219,   215,   217,   217,   216,   257,   215,   217,   217,   295,
     217,   217,   217,   217,   217,   217,   217,   216,   284,   215,
     217,   217,   217,   216,   350,   191,   191,   225,   213,   191,
     213,   191,   191,   215,   214,   213,   191,   213,   214,   213,
     213,   213,   213,   213,   213,   215,   215,   217,   374,   216,
     371,   191,   215,   220,   215,   217,   217,   217,   217,   216,
     263,   213,   215,   215,   217,   365,   217,   216,   361,   215,
     215,   215,   215,   143,   144,   145,   146,   147,   148,   149,
     224,   225,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   214,   214,   225,
     217,   214,   225,   214,   225,   213,   214,   214,   214,   225,
     214,   227,   227,   215,   215,   215,   215,   215,   215,   215,
     213,   169,   170,   213,   191,   213,   213,   217,   213,   213,
     214,   213,   213,   225,   213,   215,   213,   213,   215,   215,
     213,   213,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   213,   191,   217,   213,   213,   213,
     215,   213,   213,   215,   213,   213,   217,   214,   330,   331,
     215,   233,   213,   213,   215,   213,   191,   217,   213,   213,
     213,   213,   191,   213,   213,   215,   213,   213,   213,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   213,
     217,   215,   215,     1,   110,   182,   202,   274,   275,   276,
     277,   278,   213,   213,   213,   213,   215,   215,   213,   217,
     213,   215,   224,   224,   224,   224,   224,   224,   224,   215,
     215,   215,    56,   132,   318,   319,   215,   215,   215,   215,
     215,   215,   215,   215,   215,    11,    12,    13,   226,   227,
     215,   215,   215,   215,   215,   215,   215,   215,   215,     8,
     184,   392,   393,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,    15,    45,    76,   111,
     112,   117,   141,   190,   212,   344,   345,   215,   215,   215,
     215,   215,   215,   215,    22,    32,    52,   178,   184,   324,
     325,   201,   219,   329,   215,   215,   215,   215,     4,    24,
      25,    35,    72,    73,    75,   102,   106,   115,   135,   137,
     140,   157,   166,   168,   171,   173,   177,   180,   186,   188,
     189,   203,   211,   296,   297,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,    75,   140,   161,   166,
     171,   186,   188,   189,   203,   211,   375,   376,   215,   217,
     217,   279,   216,   275,   215,   215,   215,   215,   215,    75,
     140,   161,   166,   171,   186,   188,   189,   203,   211,   366,
     367,   215,   215,   219,   226,   226,   226,   215,   219,   215,
     219,   215,   219,   214,   331,   215,   218,   218,   218,   218,
     218,   218,   218,   215,   219,   215,   219,   213,   187,   227,
     217,   215,   215,   219,   319,   393,   345,   325,   136,   140,
     136,    86,   140,   136,   136,   297,   376,   215,   215,   215,
      73,    75,   123,   140,   165,   166,   205,   211,   280,   367,
     215
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   221,   222,   222,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     224,   224,   225,   225,   225,   225,   225,   225,   225,   225,
     226,   226,   227,   227,   227,   227,   228,   229,   230,   231,
     231,   232,   232,   233,   233,   234,   235,   235,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
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
     422,   422,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   465,   466,   466,   466,
     466,   466,   466,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   474,   475,   475,   475,   475,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   493,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   495,   496,
     497,   498,   499,   500,   501,   502
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
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4
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
#line 3130 "conf_parser.c"
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
#line 385 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3403 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER timespec_  */
#line 386 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3409 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER SECONDS timespec_  */
#line 387 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3415 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER MINUTES timespec_  */
#line 388 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3421 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER HOURS timespec_  */
#line 389 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3427 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER DAYS timespec_  */
#line 390 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3433 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER WEEKS timespec_  */
#line 391 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3439 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER MONTHS timespec_  */
#line 392 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3445 "conf_parser.c"
    break;

  case 39: /* timespec: NUMBER YEARS timespec_  */
#line 393 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3451 "conf_parser.c"
    break;

  case 40: /* sizespec_: %empty  */
#line 396 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3457 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER sizespec_  */
#line 397 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3463 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER BYTES sizespec_  */
#line 398 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3469 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER KBYTES sizespec_  */
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3475 "conf_parser.c"
    break;

  case 45: /* sizespec: NUMBER MBYTES sizespec_  */
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3481 "conf_parser.c"
    break;

  case 46: /* module_base_path_entry: MODULE_BASE_PATH '=' module_string ';'  */
#line 408 "conf_parser.y"
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
#line 3498 "conf_parser.c"
    break;

  case 47: /* loadmodule_entry: LOADMODULE module_string module_attributes ';'  */
#line 426 "conf_parser.y"
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
#line 3515 "conf_parser.c"
    break;

  case 48: /* module_string: QSTRING  */
#line 441 "conf_parser.y"
{
  (yyval.string) = io_strdup((yyvsp[0].string));
}
#line 3523 "conf_parser.c"
    break;

  case 49: /* module_attributes: %empty  */
#line 446 "conf_parser.y"
{
  (yyval.number) = 0;
}
#line 3531 "conf_parser.c"
    break;

  case 50: /* module_attributes: ':' module_attributes_items  */
#line 449 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3539 "conf_parser.c"
    break;

  case 51: /* module_attributes_items: module_attributes_items ',' module_attributes_item  */
#line 454 "conf_parser.y"
{
  (yyval.number) = (yyvsp[-2].number) | (yyvsp[0].number);
}
#line 3547 "conf_parser.c"
    break;

  case 52: /* module_attributes_items: module_attributes_item  */
#line 457 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3555 "conf_parser.c"
    break;

  case 53: /* module_attributes_item: RESIDENT  */
#line 462 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_DEACTIVATE;
}
#line 3563 "conf_parser.c"
    break;

  case 54: /* module_attributes_item: REQUIRED  */
#line 465 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_REMOVE;
}
#line 3571 "conf_parser.c"
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
#line 3583 "conf_parser.c"
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
#line 3595 "conf_parser.c"
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
#line 3613 "conf_parser.c"
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
#line 3631 "conf_parser.c"
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
#line 3644 "conf_parser.c"
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
#line 3661 "conf_parser.c"
    break;

  case 76: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 563 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3673 "conf_parser.c"
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
#line 3699 "conf_parser.c"
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
#line 3725 "conf_parser.c"
    break;

  case 79: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 618 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3737 "conf_parser.c"
    break;

  case 80: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 627 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3746 "conf_parser.c"
    break;

  case 88: /* admin_name: NAME '=' QSTRING ';'  */
#line 645 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3758 "conf_parser.c"
    break;

  case 89: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 654 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3770 "conf_parser.c"
    break;

  case 90: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 663 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3782 "conf_parser.c"
    break;

  case 91: /* $@1: %empty  */
#line 676 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3791 "conf_parser.c"
    break;

  case 92: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 680 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3808 "conf_parser.c"
    break;

  case 98: /* motd_mask: MASK '=' QSTRING ';'  */
#line 697 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3817 "conf_parser.c"
    break;

  case 99: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 703 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3826 "conf_parser.c"
    break;

  case 100: /* $@2: %empty  */
#line 713 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3835 "conf_parser.c"
    break;

  case 101: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 717 "conf_parser.y"
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
#line 3853 "conf_parser.c"
    break;

  case 109: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 735 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3862 "conf_parser.c"
    break;

  case 110: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 741 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3871 "conf_parser.c"
    break;

  case 111: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 747 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3880 "conf_parser.c"
    break;

  case 112: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 753 "conf_parser.y"
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
#line 3902 "conf_parser.c"
    break;

  case 119: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 782 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 3914 "conf_parser.c"
    break;

  case 120: /* $@3: %empty  */
#line 791 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3923 "conf_parser.c"
    break;

  case 121: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 795 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3936 "conf_parser.c"
    break;

  case 128: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 811 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3947 "conf_parser.c"
    break;

  case 129: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 819 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3955 "conf_parser.c"
    break;

  case 130: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 822 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3963 "conf_parser.c"
    break;

  case 131: /* $@4: %empty  */
#line 827 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3972 "conf_parser.c"
    break;

  case 133: /* logging_file_type_item: USER  */
#line 833 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3981 "conf_parser.c"
    break;

  case 134: /* logging_file_type_item: OPERATOR  */
#line 837 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3990 "conf_parser.c"
    break;

  case 135: /* logging_file_type_item: XLINE  */
#line 841 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3999 "conf_parser.c"
    break;

  case 136: /* logging_file_type_item: RESV  */
#line 845 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4008 "conf_parser.c"
    break;

  case 137: /* logging_file_type_item: T_DLINE  */
#line 849 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4017 "conf_parser.c"
    break;

  case 138: /* logging_file_type_item: KLINE  */
#line 853 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4026 "conf_parser.c"
    break;

  case 139: /* logging_file_type_item: KILL  */
#line 857 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4035 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: T_DEBUG  */
#line 861 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4044 "conf_parser.c"
    break;

  case 141: /* $@5: %empty  */
#line 871 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4056 "conf_parser.c"
    break;

  case 142: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 878 "conf_parser.y"
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
#line 4114 "conf_parser.c"
    break;

  case 156: /* oper_name: NAME '=' QSTRING ';'  */
#line 946 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4123 "conf_parser.c"
    break;

  case 157: /* oper_user: USER '=' QSTRING ';'  */
#line 952 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4132 "conf_parser.c"
    break;

  case 158: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 958 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4141 "conf_parser.c"
    break;

  case 159: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 964 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4150 "conf_parser.c"
    break;

  case 160: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 970 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4164 "conf_parser.c"
    break;

  case 161: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 981 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4173 "conf_parser.c"
    break;

  case 162: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 987 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4187 "conf_parser.c"
    break;

  case 163: /* oper_class: CLASS '=' QSTRING ';'  */
#line 998 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4196 "conf_parser.c"
    break;

  case 164: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1004 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4205 "conf_parser.c"
    break;

  case 165: /* $@6: %empty  */
#line 1010 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4214 "conf_parser.c"
    break;

  case 169: /* oper_flags_item: KILL ':' REMOTE  */
#line 1017 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4223 "conf_parser.c"
    break;

  case 170: /* oper_flags_item: KILL  */
#line 1021 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4232 "conf_parser.c"
    break;

  case 171: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1025 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4241 "conf_parser.c"
    break;

  case 172: /* oper_flags_item: CONNECT  */
#line 1029 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4250 "conf_parser.c"
    break;

  case 173: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1033 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4259 "conf_parser.c"
    break;

  case 174: /* oper_flags_item: SQUIT  */
#line 1037 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4268 "conf_parser.c"
    break;

  case 175: /* oper_flags_item: KLINE  */
#line 1041 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4277 "conf_parser.c"
    break;

  case 176: /* oper_flags_item: UNKLINE  */
#line 1045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4286 "conf_parser.c"
    break;

  case 177: /* oper_flags_item: T_DLINE  */
#line 1049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4295 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: T_UNDLINE  */
#line 1053 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4304 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: XLINE  */
#line 1057 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4313 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: T_UNXLINE  */
#line 1061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4322 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: DIE  */
#line 1065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4331 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: T_RESTART  */
#line 1069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4340 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1073 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4349 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: REHASH  */
#line 1077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4358 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: ADMIN  */
#line 1081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4367 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_GLOBOPS  */
#line 1085 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4376 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_LOCOPS  */
#line 1089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4385 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: REMOTEBAN  */
#line 1093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4394 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_SET  */
#line 1097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4403 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: MODULE  */
#line 1101 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4412 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_OPME  */
#line 1105 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4421 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: NICK ':' RESV  */
#line 1109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4430 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: JOIN ':' RESV  */
#line 1113 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4439 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: RESV  */
#line 1117 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4448 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_UNRESV  */
#line 1121 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4457 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: CLOSE  */
#line 1125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4466 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1129 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4475 "conf_parser.c"
    break;

  case 198: /* $@7: %empty  */
#line 1139 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.con_freq.value  = CLASS_DEFAULT_CONNECT_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4491 "conf_parser.c"
    break;

  case 199: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1150 "conf_parser.y"
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
#line 4539 "conf_parser.c"
    break;

  case 218: /* class_name: NAME '=' QSTRING ';'  */
#line 1213 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4548 "conf_parser.c"
    break;

  case 219: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1219 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4557 "conf_parser.c"
    break;

  case 220: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1225 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4566 "conf_parser.c"
    break;

  case 221: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1231 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4575 "conf_parser.c"
    break;

  case 222: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1237 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4584 "conf_parser.c"
    break;

  case 223: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1243 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4593 "conf_parser.c"
    break;

  case 224: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1249 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4602 "conf_parser.c"
    break;

  case 225: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1255 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4611 "conf_parser.c"
    break;

  case 226: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1261 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4621 "conf_parser.c"
    break;

  case 227: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1268 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4630 "conf_parser.c"
    break;

  case 228: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1274 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4639 "conf_parser.c"
    break;

  case 229: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1280 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4648 "conf_parser.c"
    break;

  case 230: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1286 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4660 "conf_parser.c"
    break;

  case 231: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1295 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4672 "conf_parser.c"
    break;

  case 232: /* $@8: %empty  */
#line 1304 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4681 "conf_parser.c"
    break;

  case 236: /* class_flags_item: RANDOM_IDLE  */
#line 1311 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4690 "conf_parser.c"
    break;

  case 237: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1315 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4699 "conf_parser.c"
    break;

  case 238: /* $@9: %empty  */
#line 1325 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4708 "conf_parser.c"
    break;

  case 240: /* $@10: %empty  */
#line 1331 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4716 "conf_parser.c"
    break;

  case 244: /* listen_flags_item: T_TLS  */
#line 1337 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4725 "conf_parser.c"
    break;

  case 245: /* listen_flags_item: HIDDEN  */
#line 1341 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4734 "conf_parser.c"
    break;

  case 246: /* listen_flags_item: T_SERVER  */
#line 1345 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4743 "conf_parser.c"
    break;

  case 247: /* listen_flags_item: CLIENT  */
#line 1349 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4752 "conf_parser.c"
    break;

  case 248: /* listen_flags_item: DEFER  */
#line 1353 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4761 "conf_parser.c"
    break;

  case 256: /* $@11: %empty  */
#line 1361 "conf_parser.y"
                                 { reset_block_state(); }
#line 4767 "conf_parser.c"
    break;

  case 260: /* port_item: NUMBER  */
#line 1366 "conf_parser.y"
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
#line 4785 "conf_parser.c"
    break;

  case 261: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1379 "conf_parser.y"
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
#line 4805 "conf_parser.c"
    break;

  case 262: /* listen_address: IP '=' QSTRING ';'  */
#line 1396 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4814 "conf_parser.c"
    break;

  case 263: /* listen_host: HOST '=' QSTRING ';'  */
#line 1402 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4823 "conf_parser.c"
    break;

  case 264: /* $@12: %empty  */
#line 1412 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4832 "conf_parser.c"
    break;

  case 265: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1416 "conf_parser.y"
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
#line 4887 "conf_parser.c"
    break;

  case 275: /* auth_user: USER '=' QSTRING ';'  */
#line 1477 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4896 "conf_parser.c"
    break;

  case 276: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1483 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4905 "conf_parser.c"
    break;

  case 277: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1489 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4914 "conf_parser.c"
    break;

  case 278: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1495 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 4928 "conf_parser.c"
    break;

  case 279: /* $@13: %empty  */
#line 1506 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 4937 "conf_parser.c"
    break;

  case 283: /* auth_flags_item: EXCEED_LIMIT  */
#line 1514 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 4946 "conf_parser.c"
    break;

  case 284: /* auth_flags_item: KLINE_EXEMPT  */
#line 1518 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 4955 "conf_parser.c"
    break;

  case 285: /* auth_flags_item: XLINE_EXEMPT  */
#line 1522 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 4964 "conf_parser.c"
    break;

  case 286: /* auth_flags_item: NEED_IDENT  */
#line 1526 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 4973 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: CAN_FLOOD  */
#line 1530 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 4982 "conf_parser.c"
    break;

  case 288: /* auth_flags_item: NO_TILDE  */
#line 1534 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 4991 "conf_parser.c"
    break;

  case 289: /* auth_flags_item: RESV_EXEMPT  */
#line 1538 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 5000 "conf_parser.c"
    break;

  case 290: /* auth_flags_item: T_WEBIRC  */
#line 1542 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5009 "conf_parser.c"
    break;

  case 291: /* auth_flags_item: NEED_PASSWORD  */
#line 1546 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5018 "conf_parser.c"
    break;

  case 292: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1552 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    log_write(LOG_TYPE_IRCD,
              "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 5033 "conf_parser.c"
    break;

  case 293: /* $@14: %empty  */
#line 1567 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5045 "conf_parser.c"
    break;

  case 294: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1574 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5056 "conf_parser.c"
    break;

  case 301: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1585 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5065 "conf_parser.c"
    break;

  case 302: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1591 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5074 "conf_parser.c"
    break;

  case 303: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1597 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5083 "conf_parser.c"
    break;

  case 309: /* service_name: NAME '=' QSTRING ';'  */
#line 1612 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5098 "conf_parser.c"
    break;

  case 310: /* $@15: %empty  */
#line 1628 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5114 "conf_parser.c"
    break;

  case 311: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1639 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5129 "conf_parser.c"
    break;

  case 318: /* shared_name: NAME '=' QSTRING ';'  */
#line 1654 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5138 "conf_parser.c"
    break;

  case 319: /* shared_user: USER '=' QSTRING ';'  */
#line 1660 "conf_parser.y"
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
#line 5160 "conf_parser.c"
    break;

  case 320: /* $@16: %empty  */
#line 1679 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5169 "conf_parser.c"
    break;

  case 324: /* shared_type_item: KLINE  */
#line 1686 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5178 "conf_parser.c"
    break;

  case 325: /* shared_type_item: UNKLINE  */
#line 1690 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5187 "conf_parser.c"
    break;

  case 326: /* shared_type_item: T_DLINE  */
#line 1694 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5196 "conf_parser.c"
    break;

  case 327: /* shared_type_item: T_UNDLINE  */
#line 1698 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5205 "conf_parser.c"
    break;

  case 328: /* shared_type_item: XLINE  */
#line 1702 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5214 "conf_parser.c"
    break;

  case 329: /* shared_type_item: T_UNXLINE  */
#line 1706 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5223 "conf_parser.c"
    break;

  case 330: /* shared_type_item: RESV  */
#line 1710 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5232 "conf_parser.c"
    break;

  case 331: /* shared_type_item: T_UNRESV  */
#line 1714 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5241 "conf_parser.c"
    break;

  case 332: /* shared_type_item: T_LOCOPS  */
#line 1718 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5250 "conf_parser.c"
    break;

  case 333: /* shared_type_item: T_ALL  */
#line 1722 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5259 "conf_parser.c"
    break;

  case 334: /* $@17: %empty  */
#line 1732 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5273 "conf_parser.c"
    break;

  case 335: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1741 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5286 "conf_parser.c"
    break;

  case 341: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1754 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5295 "conf_parser.c"
    break;

  case 342: /* $@18: %empty  */
#line 1760 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5304 "conf_parser.c"
    break;

  case 346: /* cluster_type_item: KLINE  */
#line 1767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5313 "conf_parser.c"
    break;

  case 347: /* cluster_type_item: UNKLINE  */
#line 1771 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5322 "conf_parser.c"
    break;

  case 348: /* cluster_type_item: T_DLINE  */
#line 1775 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5331 "conf_parser.c"
    break;

  case 349: /* cluster_type_item: T_UNDLINE  */
#line 1779 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5340 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: XLINE  */
#line 1783 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5349 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: T_UNXLINE  */
#line 1787 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5358 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: RESV  */
#line 1791 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5367 "conf_parser.c"
    break;

  case 353: /* cluster_type_item: T_UNRESV  */
#line 1795 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5376 "conf_parser.c"
    break;

  case 354: /* cluster_type_item: T_LOCOPS  */
#line 1799 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5385 "conf_parser.c"
    break;

  case 355: /* cluster_type_item: T_ALL  */
#line 1803 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5394 "conf_parser.c"
    break;

  case 356: /* $@19: %empty  */
#line 1813 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5408 "conf_parser.c"
    break;

  case 357: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1822 "conf_parser.y"
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
#line 5456 "conf_parser.c"
    break;

  case 375: /* connect_name: NAME '=' QSTRING ';'  */
#line 1884 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5465 "conf_parser.c"
    break;

  case 376: /* connect_host: HOST '=' QSTRING ';'  */
#line 1890 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5474 "conf_parser.c"
    break;

  case 377: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1896 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5483 "conf_parser.c"
    break;

  case 378: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1902 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5492 "conf_parser.c"
    break;

  case 379: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1908 "conf_parser.y"
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
#line 5508 "conf_parser.c"
    break;

  case 380: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1921 "conf_parser.y"
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
#line 5524 "conf_parser.c"
    break;

  case 381: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1934 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5533 "conf_parser.c"
    break;

  case 382: /* connect_port: PORT '=' NUMBER ';'  */
#line 1940 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5542 "conf_parser.c"
    break;

  case 383: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 1946 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5551 "conf_parser.c"
    break;

  case 384: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 1950 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5560 "conf_parser.c"
    break;

  case 385: /* $@20: %empty  */
#line 1956 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5568 "conf_parser.c"
    break;

  case 389: /* connect_flags_item: AUTOCONN  */
#line 1962 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5577 "conf_parser.c"
    break;

  case 390: /* connect_flags_item: T_TLS  */
#line 1966 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5586 "conf_parser.c"
    break;

  case 391: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1972 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5600 "conf_parser.c"
    break;

  case 392: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 1983 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5609 "conf_parser.c"
    break;

  case 393: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 1989 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5618 "conf_parser.c"
    break;

  case 394: /* connect_class: CLASS '=' QSTRING ';'  */
#line 1995 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5627 "conf_parser.c"
    break;

  case 395: /* $@21: %empty  */
#line 2005 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5636 "conf_parser.c"
    break;

  case 396: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2009 "conf_parser.y"
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
#line 5660 "conf_parser.c"
    break;

  case 402: /* kill_user: USER '=' QSTRING ';'  */
#line 2033 "conf_parser.y"
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
#line 5683 "conf_parser.c"
    break;

  case 403: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2053 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5692 "conf_parser.c"
    break;

  case 404: /* $@22: %empty  */
#line 2063 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5701 "conf_parser.c"
    break;

  case 405: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2067 "conf_parser.y"
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
#line 5723 "conf_parser.c"
    break;

  case 411: /* deny_ip: IP '=' QSTRING ';'  */
#line 2089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5732 "conf_parser.c"
    break;

  case 412: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2095 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5741 "conf_parser.c"
    break;

  case 418: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2110 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_error_report("Unable to add D-line exemption");
}
#line 5753 "conf_parser.c"
    break;

  case 419: /* $@23: %empty  */
#line 2123 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5762 "conf_parser.c"
    break;

  case 420: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2127 "conf_parser.y"
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
#line 5782 "conf_parser.c"
    break;

  case 426: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2147 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5791 "conf_parser.c"
    break;

  case 427: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2153 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5800 "conf_parser.c"
    break;

  case 473: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2210 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5808 "conf_parser.c"
    break;

  case 474: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2215 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5816 "conf_parser.c"
    break;

  case 475: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2220 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5824 "conf_parser.c"
    break;

  case 476: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2225 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5832 "conf_parser.c"
    break;

  case 477: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2230 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5840 "conf_parser.c"
    break;

  case 478: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2235 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5848 "conf_parser.c"
    break;

  case 479: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2240 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5856 "conf_parser.c"
    break;

  case 480: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2245 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5864 "conf_parser.c"
    break;

  case 481: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2250 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5872 "conf_parser.c"
    break;

  case 482: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2255 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5880 "conf_parser.c"
    break;

  case 483: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2260 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5888 "conf_parser.c"
    break;

  case 484: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2265 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5896 "conf_parser.c"
    break;

  case 485: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2270 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5904 "conf_parser.c"
    break;

  case 486: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2275 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 5915 "conf_parser.c"
    break;

  case 487: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2283 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5923 "conf_parser.c"
    break;

  case 488: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2288 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5931 "conf_parser.c"
    break;

  case 489: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2293 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5939 "conf_parser.c"
    break;

  case 490: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2298 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5947 "conf_parser.c"
    break;

  case 491: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2303 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5955 "conf_parser.c"
    break;

  case 492: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2308 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5963 "conf_parser.c"
    break;

  case 493: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2313 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5971 "conf_parser.c"
    break;

  case 494: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2318 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5979 "conf_parser.c"
    break;

  case 495: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2323 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5987 "conf_parser.c"
    break;

  case 496: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2328 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5995 "conf_parser.c"
    break;

  case 497: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2333 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6003 "conf_parser.c"
    break;

  case 498: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2338 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6011 "conf_parser.c"
    break;

  case 499: /* general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'  */
#line 2343 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6019 "conf_parser.c"
    break;

  case 500: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2348 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6027 "conf_parser.c"
    break;

  case 501: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2353 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6035 "conf_parser.c"
    break;

  case 502: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2358 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6043 "conf_parser.c"
    break;

  case 503: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2363 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6051 "conf_parser.c"
    break;

  case 504: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2368 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6059 "conf_parser.c"
    break;

  case 505: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2373 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6067 "conf_parser.c"
    break;

  case 506: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2378 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6075 "conf_parser.c"
    break;

  case 507: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2383 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6087 "conf_parser.c"
    break;

  case 508: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2392 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6095 "conf_parser.c"
    break;

  case 509: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2397 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6103 "conf_parser.c"
    break;

  case 510: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2402 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6111 "conf_parser.c"
    break;

  case 511: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2407 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6119 "conf_parser.c"
    break;

  case 512: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2412 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6130 "conf_parser.c"
    break;

  case 513: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2420 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6138 "conf_parser.c"
    break;

  case 524: /* cloak_enabled: ENABLED '=' TBOOL ';'  */
#line 2440 "conf_parser.y"
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
#line 6158 "conf_parser.c"
    break;

  case 525: /* cloak_cidr_len_ipv4: CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2457 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6170 "conf_parser.c"
    break;

  case 526: /* cloak_cidr_len_ipv6: CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2466 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6182 "conf_parser.c"
    break;

  case 527: /* cloak_num_bits: NUM_BITS '=' NUMBER ';'  */
#line 2475 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6194 "conf_parser.c"
    break;

  case 528: /* cloak_secret: SECRET '=' QSTRING ';'  */
#line 2484 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.secret);
  ConfigCloak.secret = io_strdup((yyvsp[-1].string));
  cloak_set_secret((yyvsp[-1].string));
}
#line 6207 "conf_parser.c"
    break;

  case 529: /* cloak_suffix: SUFFIX '=' QSTRING ';'  */
#line 2494 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.suffix);
  ConfigCloak.suffix = io_strdup((yyvsp[-1].string));
  cloak_set_suffix((yyvsp[-1].string));
}
#line 6220 "conf_parser.c"
    break;

  case 550: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2529 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6228 "conf_parser.c"
    break;

  case 551: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2534 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6236 "conf_parser.c"
    break;

  case 552: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2539 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6244 "conf_parser.c"
    break;

  case 553: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2544 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6252 "conf_parser.c"
    break;

  case 554: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2549 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6260 "conf_parser.c"
    break;

  case 555: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2554 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6268 "conf_parser.c"
    break;

  case 556: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2559 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6276 "conf_parser.c"
    break;

  case 557: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2564 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6284 "conf_parser.c"
    break;

  case 558: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2569 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6292 "conf_parser.c"
    break;

  case 559: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2574 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6300 "conf_parser.c"
    break;

  case 560: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2579 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6308 "conf_parser.c"
    break;

  case 561: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2584 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6316 "conf_parser.c"
    break;

  case 562: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2589 "conf_parser.y"
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
#line 6342 "conf_parser.c"
    break;

  case 563: /* channel_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 2612 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigChannel.max_topic_length = TOPICLEN;
  else
    ConfigChannel.max_topic_length = (yyvsp[-1].number);
}
#line 6353 "conf_parser.c"
    break;

  case 564: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2620 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6361 "conf_parser.c"
    break;

  case 565: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2625 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6369 "conf_parser.c"
    break;

  case 578: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2647 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6378 "conf_parser.c"
    break;

  case 579: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2653 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6392 "conf_parser.c"
    break;

  case 580: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2664 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6404 "conf_parser.c"
    break;

  case 581: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2673 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6413 "conf_parser.c"
    break;

  case 582: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2679 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6422 "conf_parser.c"
    break;

  case 583: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2685 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6431 "conf_parser.c"
    break;

  case 584: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2691 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6443 "conf_parser.c"
    break;

  case 585: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2700 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6452 "conf_parser.c"
    break;


#line 6456 "conf_parser.c"

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

