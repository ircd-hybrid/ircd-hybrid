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
    min_idle,
    max_idle,
    max_total,
    max_sendq,
    max_recvq,
    max_channels,
    cidr_bitlen_ipv4,
    cidr_bitlen_ipv6,
    number_per_cidr;

  struct
  {
    uintmax_t value;
  } retry_delay_sec;
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


#line 196 "conf_parser.c"

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
    BYPASS = 266,                  /* BYPASS  */
    BYTES = 267,                   /* BYTES  */
    KBYTES = 268,                  /* KBYTES  */
    MBYTES = 269,                  /* MBYTES  */
    CALLER_ID_WAIT = 270,          /* CALLER_ID_WAIT  */
    CAN_FLOOD = 271,               /* CAN_FLOOD  */
    CHANNEL = 272,                 /* CHANNEL  */
    CIDR_BITLEN_IPV4 = 273,        /* CIDR_BITLEN_IPV4  */
    CIDR_BITLEN_IPV6 = 274,        /* CIDR_BITLEN_IPV6  */
    CIDR_LEN_IPV4 = 275,           /* CIDR_LEN_IPV4  */
    CIDR_LEN_IPV6 = 276,           /* CIDR_LEN_IPV6  */
    CLASS = 277,                   /* CLASS  */
    CLIENT = 278,                  /* CLIENT  */
    CLOAK = 279,                   /* CLOAK  */
    CLOSE = 280,                   /* CLOSE  */
    CONNECT = 281,                 /* CONNECT  */
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
    INPUT_FLOOD = 318,             /* INPUT_FLOOD  */
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
    RETRY_DELAY = 397,             /* RETRY_DELAY  */
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
#define BYPASS 266
#define BYTES 267
#define KBYTES 268
#define MBYTES 269
#define CALLER_ID_WAIT 270
#define CAN_FLOOD 271
#define CHANNEL 272
#define CIDR_BITLEN_IPV4 273
#define CIDR_BITLEN_IPV6 274
#define CIDR_LEN_IPV4 275
#define CIDR_LEN_IPV6 276
#define CLASS 277
#define CLIENT 278
#define CLOAK 279
#define CLOSE 280
#define CONNECT 281
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
#define INPUT_FLOOD 318
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
#define RETRY_DELAY 397
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
#line 137 "conf_parser.y"

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
  YYSYMBOL_BYPASS = 11,                    /* BYPASS  */
  YYSYMBOL_BYTES = 12,                     /* BYTES  */
  YYSYMBOL_KBYTES = 13,                    /* KBYTES  */
  YYSYMBOL_MBYTES = 14,                    /* MBYTES  */
  YYSYMBOL_CALLER_ID_WAIT = 15,            /* CALLER_ID_WAIT  */
  YYSYMBOL_CAN_FLOOD = 16,                 /* CAN_FLOOD  */
  YYSYMBOL_CHANNEL = 17,                   /* CHANNEL  */
  YYSYMBOL_CIDR_BITLEN_IPV4 = 18,          /* CIDR_BITLEN_IPV4  */
  YYSYMBOL_CIDR_BITLEN_IPV6 = 19,          /* CIDR_BITLEN_IPV6  */
  YYSYMBOL_CIDR_LEN_IPV4 = 20,             /* CIDR_LEN_IPV4  */
  YYSYMBOL_CIDR_LEN_IPV6 = 21,             /* CIDR_LEN_IPV6  */
  YYSYMBOL_CLASS = 22,                     /* CLASS  */
  YYSYMBOL_CLIENT = 23,                    /* CLIENT  */
  YYSYMBOL_CLOAK = 24,                     /* CLOAK  */
  YYSYMBOL_CLOSE = 25,                     /* CLOSE  */
  YYSYMBOL_CONNECT = 26,                   /* CONNECT  */
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
  YYSYMBOL_INPUT_FLOOD = 63,               /* INPUT_FLOOD  */
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
  YYSYMBOL_RETRY_DELAY = 142,              /* RETRY_DELAY  */
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
  YYSYMBOL_connect_retry_delay = 384,      /* connect_retry_delay  */
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
#define YYLAST   1159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  222
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  281
/* YYNRULES -- Number of rules.  */
#define YYNRULES  584
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1209

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
       0,   357,   357,   358,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     390,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     401,   401,   402,   403,   404,   405,   412,   430,   445,   451,
     453,   458,   461,   466,   469,   478,   480,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     495,   504,   513,   528,   543,   553,   567,   576,   599,   622,
     631,   641,   643,   643,   644,   645,   646,   647,   649,   658,
     667,   681,   680,   698,   698,   699,   699,   699,   701,   707,
     718,   717,   736,   736,   737,   737,   737,   737,   737,   739,
     745,   751,   757,   780,   781,   781,   783,   783,   784,   786,
     796,   796,   809,   810,   812,   812,   813,   813,   815,   823,
     826,   832,   831,   837,   841,   845,   849,   853,   857,   861,
     865,   876,   875,   937,   937,   938,   939,   940,   941,   942,
     943,   944,   945,   946,   947,   948,   950,   956,   962,   968,
     974,   985,   991,  1002,  1008,  1015,  1014,  1020,  1020,  1021,
    1025,  1029,  1033,  1037,  1041,  1045,  1049,  1053,  1057,  1061,
    1065,  1069,  1073,  1077,  1081,  1085,  1089,  1093,  1097,  1101,
    1105,  1109,  1113,  1117,  1121,  1125,  1129,  1133,  1137,  1148,
    1147,  1201,  1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,
    1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1218,  1224,
    1230,  1236,  1242,  1248,  1254,  1260,  1267,  1273,  1279,  1285,
    1294,  1304,  1303,  1309,  1309,  1310,  1314,  1325,  1324,  1331,
    1330,  1335,  1335,  1336,  1340,  1344,  1348,  1352,  1358,  1358,
    1359,  1359,  1359,  1359,  1359,  1361,  1361,  1363,  1363,  1365,
    1378,  1395,  1401,  1412,  1411,  1467,  1467,  1468,  1469,  1470,
    1471,  1472,  1473,  1474,  1476,  1482,  1488,  1494,  1506,  1505,
    1511,  1511,  1513,  1517,  1521,  1525,  1529,  1533,  1537,  1541,
    1545,  1551,  1567,  1566,  1581,  1581,  1582,  1582,  1582,  1582,
    1584,  1590,  1596,  1606,  1608,  1608,  1609,  1609,  1611,  1628,
    1627,  1650,  1650,  1651,  1651,  1651,  1651,  1653,  1659,  1679,
    1678,  1684,  1684,  1685,  1689,  1693,  1697,  1701,  1705,  1709,
    1713,  1717,  1721,  1732,  1731,  1750,  1750,  1751,  1751,  1751,
    1753,  1760,  1759,  1765,  1765,  1766,  1770,  1774,  1778,  1782,
    1786,  1790,  1794,  1798,  1802,  1813,  1812,  1868,  1868,  1869,
    1870,  1871,  1872,  1873,  1874,  1875,  1876,  1877,  1878,  1879,
    1880,  1881,  1882,  1883,  1884,  1886,  1892,  1898,  1904,  1910,
    1916,  1929,  1942,  1948,  1954,  1958,  1965,  1964,  1969,  1969,
    1970,  1974,  1980,  1991,  1997,  2003,  2014,  2013,  2038,  2038,
    2039,  2039,  2039,  2041,  2061,  2072,  2071,  2094,  2094,  2095,
    2095,  2095,  2097,  2103,  2113,  2115,  2115,  2116,  2116,  2118,
    2132,  2131,  2152,  2152,  2153,  2153,  2153,  2155,  2161,  2171,
    2173,  2173,  2174,  2175,  2176,  2177,  2178,  2179,  2180,  2181,
    2182,  2183,  2184,  2185,  2186,  2187,  2188,  2189,  2190,  2191,
    2192,  2193,  2194,  2195,  2196,  2197,  2198,  2199,  2200,  2201,
    2202,  2203,  2204,  2205,  2206,  2207,  2208,  2209,  2210,  2211,
    2212,  2213,  2214,  2217,  2222,  2227,  2232,  2237,  2242,  2247,
    2252,  2257,  2262,  2267,  2272,  2277,  2282,  2290,  2295,  2300,
    2305,  2310,  2315,  2320,  2325,  2330,  2335,  2340,  2345,  2350,
    2355,  2360,  2365,  2370,  2375,  2380,  2385,  2394,  2399,  2404,
    2409,  2414,  2422,  2431,  2433,  2433,  2434,  2435,  2436,  2437,
    2438,  2439,  2440,  2442,  2459,  2468,  2477,  2486,  2496,  2510,
    2512,  2512,  2513,  2514,  2515,  2516,  2517,  2518,  2519,  2520,
    2521,  2522,  2523,  2524,  2525,  2526,  2527,  2528,  2529,  2531,
    2536,  2541,  2546,  2551,  2556,  2561,  2566,  2571,  2576,  2581,
    2586,  2591,  2614,  2622,  2627,  2636,  2638,  2638,  2639,  2640,
    2641,  2642,  2643,  2644,  2645,  2646,  2647,  2649,  2655,  2666,
    2675,  2681,  2687,  2693,  2702
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
  "AUTOCONN", "AWAY_COUNT", "AWAY_TIME", "BYPASS", "BYTES", "KBYTES",
  "MBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL", "CIDR_BITLEN_IPV4",
  "CIDR_BITLEN_IPV6", "CIDR_LEN_IPV4", "CIDR_LEN_IPV6", "CLASS", "CLIENT",
  "CLOAK", "CLOSE", "CONNECT", "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME",
  "DEFAULT_JOIN_FLOOD_COUNT", "DEFAULT_JOIN_FLOOD_TIME",
  "DEFAULT_MAX_CLIENTS", "DEFER", "DENY", "DESCRIPTION", "DIE",
  "DISABLE_DNS", "DISABLE_IDENT", "DISABLE_FAKE_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6", "EMAIL",
  "ENABLED", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FLATTEN_LINKS",
  "FLATTEN_LINKS_DELAY", "FLATTEN_LINKS_FILE", "GECOS", "GENERAL",
  "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
  "HIDE_IDLE_FROM_OPERS", "HIDE_SERVERS", "HIDE_SERVICES", "HOST", "HUB",
  "HUB_MASK", "IDENT_TIMEOUT", "INPUT_FLOOD", "INVISIBLE_ON_CONNECT",
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
  "NO_TILDE", "NUM_BITS", "NUMBER_PER_CIDR", "NUMBER_PER_IP_GLOBAL",
  "NUMBER_PER_IP_LOCAL", "OPER_UMODES", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD",
  "PATH", "PING_COOKIE", "PING_TIME", "PORT", "RANDOM_IDLE", "REASON",
  "REGISTRATION_TIMEOUT", "REHASH", "REMOTE", "REMOTEBAN", "REQUIRED",
  "RESIDENT", "RESV", "RESV_EXEMPT", "RETRY_DELAY", "SECRET", "SECONDS",
  "MINUTES", "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD",
  "SENDQ", "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPECIALS_IN_IDENT",
  "SPOOF", "SQUIT", "STATS_E_DISABLED", "STATS_U_OPER_ONLY", "SUFFIX",
  "T_ALL", "T_BIND", "T_COMMAND", "T_CLUSTER", "T_DEBUG", "T_DLINE",
  "T_FILE", "T_GLOBOPS", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_OPME",
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
  "class_number_per_ip_global", "class_max_channels", "class_max_number",
  "class_sendq", "class_recvq", "class_cidr_bitlen_ipv4",
  "class_cidr_bitlen_ipv6", "class_number_per_cidr", "class_min_idle",
  "class_max_idle", "class_flags", "$@8", "class_flags_items",
  "class_flags_item", "listen_entry", "$@9", "listen_flags", "$@10",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "$@11", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "$@12", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_class", "auth_encrypted", "auth_flags",
  "$@13", "auth_flags_items", "auth_flags_item", "auth_spoof",
  "resv_entry", "$@14", "resv_items", "resv_item", "resv_mask",
  "resv_reason", "resv_exempt", "service_entry", "service_items",
  "service_item", "service_name", "shared_entry", "$@15", "shared_items",
  "shared_item", "shared_name", "shared_user", "shared_type", "$@16",
  "shared_types", "shared_type_item", "cluster_entry", "$@17",
  "cluster_items", "cluster_item", "cluster_name", "cluster_type", "$@18",
  "cluster_types", "cluster_type_item", "connect_entry", "$@19",
  "connect_items", "connect_item", "connect_name", "connect_host",
  "connect_timeout", "connect_retry_delay", "connect_bind",
  "connect_send_password", "connect_accept_password",
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
  "general_short_motd", "general_specials_in_ident", "general_max_targets",
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

#define YYPACT_NINF (-938)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -938,   598,  -938,  -188,  -198,  -195,  -938,  -179,  -938,  -938,
    -174,  -938,  -171,  -938,  -938,  -938,  -158,  -143,  -938,  -938,
    -938,  -131,  -111,  -938,  -104,  -938,   -97,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,    47,   724,   -57,   528,   -54,
     -51,    38,   -49,   382,   -42,   -40,   -27,  -938,   -24,  -158,
     -12,     4,    35,   781,   455,    45,    10,    49,    44,    59,
      71,    72,    76,    83,    12,  -938,  -938,  -938,  -938,  -938,
      86,    89,    92,    95,    97,   100,   104,   107,   109,   111,
     112,   121,   125,   127,   128,   132,     3,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,   620,  -938,   133,   134,   136,   140,
     142,   143,    79,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
     584,    13,  -938,   144,    17,  -938,  -938,   198,  -938,   145,
     147,   148,   154,   155,   156,   163,   166,   168,   176,   178,
     181,   182,   183,   185,   186,   188,   190,   194,   196,   199,
     202,   206,   207,   208,   212,   214,   215,   227,   229,   233,
     234,   235,   237,   244,   245,   246,   248,   251,   254,    51,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,   327,    26,   336,   -74,    73,    77,    34,   304,   278,
    -938,   255,   257,   258,   259,   267,   273,   274,   275,   225,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,   119,
     276,   277,   284,   287,   291,   294,   295,   301,   302,   303,
     305,   102,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,   137,   152,   306,    50,  -938,  -938,
    -938,   210,   195,  -938,   307,    42,  -938,  -938,    43,  -938,
     179,   266,   314,   197,  -938,    48,   201,   339,   228,   201,
     201,   201,   283,   201,   201,   317,   319,   320,   321,   325,
     328,   329,  -938,   331,   326,   332,  -938,   333,   334,   337,
     338,   341,   343,   344,   346,   349,   350,   354,   165,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,   342,   359,   362,   363,   365,   366,
     361,  -938,   368,   370,   376,   385,   387,   389,   390,  -938,
     391,   393,   396,   398,   399,   401,   407,   408,   160,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,   411,   412,    58,  -938,
    -938,  -938,   372,   384,  -938,  -938,   415,   416,    75,  -938,
    -938,  -938,   431,   201,   421,   201,   201,   425,   201,   449,
     450,   432,   435,   201,   460,   201,   439,   441,   442,   443,
     445,   446,   201,   447,   448,   451,   456,   473,   201,   201,
     488,   201,   489,   470,   496,   498,   477,   201,   201,   201,
     501,   479,   481,  -938,   482,   484,   485,  -938,   486,   487,
     490,    33,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
     492,   493,    36,  -938,  -938,  -938,   483,   499,   504,  -938,
     509,  -938,    37,  -938,  -938,  -938,  -938,  -938,  -938,   480,
    -938,  -938,  -938,   500,   511,   512,    30,  -938,  -938,  -938,
     503,   514,   515,  -938,   516,   518,   519,   524,   530,   531,
     537,   170,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,   540,   539,   541,   543,    16,  -938,  -938,
    -938,  -938,   522,   566,   201,   550,   573,   552,   575,   577,
     554,  -938,  -938,   558,   561,   585,   562,   568,   570,   571,
     572,   574,   579,   580,   582,  -938,   583,   569,  -938,   117,
    -938,  -938,  -938,  -938,   603,   586,  -938,   587,   591,   578,
     592,   593,   594,   124,  -938,  -938,  -938,  -938,  -938,   589,
     597,  -938,   601,   604,  -938,   605,    21,  -938,  -938,  -938,
    -938,   608,   609,   611,  -938,   615,   529,   616,   619,   621,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,  -938,  -938,   606,   637,   618,   638,   201,   639,
     201,   595,   640,   641,   642,   201,   643,   643,   644,  -938,
     645,   646,   647,   648,   649,   650,  -938,  -938,   653,   -29,
     654,   667,   655,   656,   657,   658,   659,   661,   201,   660,
     663,   201,   664,   665,  -938,   666,   668,   669,  -938,   670,
    -938,   673,   674,   675,  -938,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,   706,   707,   708,   709,   710,
     711,   712,   713,   714,   715,  -938,  -938,   718,   741,   671,
     720,   721,   722,   723,  -938,   726,   727,   728,  -938,  -938,
     729,   731,   672,   732,   730,  -938,   -74,  -938,   734,   735,
     736,  -938,  -938,   737,   745,   738,   739,   740,   743,   744,
     746,   747,   748,   749,  -938,  -938,   750,   752,   753,   754,
    -938,   755,   756,   757,   758,   759,   760,   761,   762,  -938,
     763,   764,   765,   766,   767,   768,   769,   770,   771,   772,
     773,  -938,  -938,   776,   742,   775,  -938,   777,  -938,   150,
    -938,   778,   780,   782,   783,   779,  -938,   784,  -938,  -938,
     785,   751,   787,   786,  -938,  -938,  -938,  -938,  -938,   201,
     201,   201,   201,   201,   201,   201,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,   788,   789,   -31,   790,   791,   792,   793,
     794,   795,   796,   797,   798,   175,   799,   800,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,   801,   802,   803,   804,   805,
     806,   807,     8,   808,   809,   810,   811,   812,   813,   814,
     815,  -938,   816,   817,  -938,  -938,   818,   819,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,   820,
     821,   405,   822,   823,   824,  -938,   825,   826,  -938,   827,
     828,   280,   599,   651,  -938,  -938,  -938,   829,   830,  -938,
     831,   832,   423,   833,   834,   835,   836,   837,   838,   839,
    -938,   840,   841,   842,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,   843,   497,  -938,  -938,   844,   845,
     846,  -938,    20,  -938,  -938,  -938,  -938,   849,   850,   851,
     852,  -938,  -938,   853,   556,   854,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -208,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,   643,
     643,   643,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -201,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -196,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -180,  -938,   847,   732,   855,  -938,
    -938,  -938,  -938,  -938,   581,  -938,   856,  -938,   857,   858,
    -938,   859,  -938,   860,   861,  -938,  -938,   862,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -167,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -153,  -938,  -938,   868,  -185,   865,   869,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,   -15,  -938,  -938,  -938,   -31,
    -938,  -938,  -938,  -938,     8,  -938,   405,  -938,   280,  -938,
    -938,  -938,   879,   867,   921,   936,   863,   933,   938,   948,
    -938,   423,  -938,   497,   870,   871,   872,   262,  -938,  -938,
     556,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,   873,  -938,  -938
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   199,     0,   355,   405,
       0,   420,     0,   263,   396,   237,     0,     0,    91,   141,
     292,     0,     0,   333,     0,   100,     0,   309,     3,     4,
       5,    14,     6,    26,    27,     7,     8,    11,    12,    13,
      16,    17,    18,    19,    20,    21,    22,    23,    25,    24,
      10,     9,    15,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    86,    85,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   531,   547,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   532,   533,
     543,   544,   545,   546,     0,   522,     0,     0,     0,     0,
       0,     0,     0,   515,   516,   517,   518,   519,   520,   521,
       0,     0,   418,     0,     0,   416,   417,     0,   472,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     431,   432,   433,   469,   438,   464,   465,   466,   467,   442,
     434,   435,   436,   437,   451,   439,   440,   441,   443,   444,
     468,   446,   447,   453,   454,   448,   449,   445,   450,   461,
     462,   463,   459,   460,   452,   457,   458,   455,   456,   470,
     471,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     576,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     567,   568,   569,   570,   571,   572,   573,   575,   574,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,    68,    66,    58,    67,    60,    61,    62,
      63,    64,    65,    59,     0,     0,     0,     0,   115,   116,
     117,     0,     0,   307,     0,     0,   305,   306,     0,    87,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   530,     0,     0,     0,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     203,   206,   208,   209,   210,   211,   212,   213,   204,   205,
     207,   214,   215,   216,     0,     0,     0,     0,     0,     0,
       0,   514,     0,     0,     0,     0,     0,     0,     0,   386,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   368,   367,
     369,   373,   370,   371,   372,   411,     0,     0,     0,   408,
     409,   410,     0,     0,   415,   426,     0,     0,     0,   423,
     424,   425,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   430,     0,     0,     0,   278,     0,     0,
       0,     0,   266,   267,   268,   269,   272,   270,   271,   402,
       0,     0,     0,   399,   400,   401,     0,     0,     0,   239,
       0,   251,     0,   249,   250,   252,   253,    54,    53,    50,
      52,    47,    46,     0,     0,     0,     0,    94,    95,    96,
       0,     0,     0,   165,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   145,   146,   147,   148,   151,   152,   153,
     150,   149,   154,     0,     0,     0,     0,     0,   295,   296,
     297,   298,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   566,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,   341,     0,
     336,   337,   338,   118,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,   103,   104,   106,   105,   107,     0,
       0,   304,     0,     0,   319,     0,     0,   312,   313,   314,
     315,     0,     0,     0,    81,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   529,   217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
       0,     0,     0,     0,     0,     0,   513,   374,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   357,     0,     0,     0,   407,     0,
     414,     0,     0,     0,   422,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   429,   273,     0,     0,     0,
       0,     0,     0,     0,   265,     0,     0,     0,   398,   254,
       0,     0,     0,     0,     0,   248,     0,    97,     0,     0,
       0,    93,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   299,     0,     0,     0,     0,
     294,     0,     0,     0,     0,     0,     0,     0,     0,   565,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,   339,     0,     0,     0,   335,     0,   113,     0,
     108,     0,     0,     0,     0,     0,   102,     0,   303,   316,
       0,     0,     0,     0,   311,    90,    89,    88,   563,    30,
      30,    30,    30,    30,    30,    30,    32,    31,   564,   549,
     550,   551,   552,   553,   554,   555,   556,   559,   560,   557,
     558,   561,   562,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,     0,     0,   200,   524,
     525,   523,   526,   527,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   356,     0,     0,   406,   419,     0,     0,   421,   482,
     487,   473,   474,   495,   509,   510,   503,   502,   477,   478,
     511,   490,   481,   479,   480,   485,   486,   475,   484,   483,
     500,   507,   508,   506,   496,   494,   497,   501,   512,   498,
     499,   492,   493,   504,   505,   489,   488,   491,   476,     0,
       0,     0,     0,     0,     0,   264,     0,     0,   397,     0,
       0,     0,   259,   255,   258,   238,    51,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,     0,     0,     0,   293,   580,   577,   578,   579,   584,
     583,   581,   582,    77,    74,    80,    73,    78,    79,    72,
      76,    75,    70,    71,     0,     0,   334,   119,     0,     0,
       0,   131,     0,   123,   124,   126,   125,     0,     0,     0,
       0,   101,   308,     0,     0,     0,   310,    33,    34,    35,
      36,    37,    38,    39,   226,   227,   236,   235,     0,   234,
     222,   230,   223,   229,   218,   228,   221,   220,   219,    40,
      40,    40,    42,    41,   224,   225,   381,   384,   385,   395,
     392,   376,   393,   390,   391,     0,   389,   394,   375,   383,
     378,   380,   379,   377,   382,   412,   413,   427,   428,   276,
     277,   286,   282,   283,   285,   290,   287,   288,   289,   284,
       0,   281,   275,   291,   274,   404,   403,   262,   261,   246,
     247,   244,   245,   243,     0,   242,     0,     0,     0,    98,
      99,   163,   160,   185,     0,   196,   172,   181,     0,   170,
     175,     0,   190,     0,   184,   188,   194,   174,   177,   186,
     187,   191,   182,   189,   178,   195,   180,   176,   179,     0,
     168,   156,   158,   164,   161,   162,   157,   159,   302,   300,
     301,   340,   345,   351,   354,   347,   353,   348,   352,   350,
     346,   349,     0,   344,   127,     0,     0,     0,     0,   122,
     110,   109,   111,   112,   317,   323,   329,   332,   325,   331,
     326,   330,   328,   324,   327,     0,   322,   318,   232,     0,
      43,    44,    45,   387,     0,   279,     0,   240,     0,   260,
     257,   256,     0,     0,     0,     0,     0,     0,     0,     0,
     166,     0,   342,     0,     0,     0,     0,     0,   121,   320,
       0,   233,   388,   280,   241,   198,   171,   193,   169,   197,
     192,   183,   173,   167,   343,   128,   130,   129,   139,   138,
     134,   136,   140,   137,   133,   135,     0,   321,   132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -938,  -938,  -938,  -364,  -304,  -937,  -626,  -938,  -938,   886,
    -938,  -938,   153,  -938,  -938,   612,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,   875,
    -938,  -938,  -938,  -938,  -938,  -938,   388,  -938,  -938,  -938,
    -938,  -938,   395,  -938,  -938,  -938,  -938,  -938,  -938,   848,
    -938,  -938,  -938,  -938,    -9,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,   588,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -173,  -938,  -938,  -938,
     774,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,   -59,  -938,  -938,
    -938,  -938,  -938,   -67,  -938,   610,  -938,  -938,  -938,    27,
    -938,  -938,  -938,  -938,  -938,   636,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,   -63,  -938,  -938,  -938,  -938,   576,  -938,
    -938,  -938,  -938,  -938,   864,  -938,  -938,  -938,  -938,   510,
    -938,  -938,  -938,  -938,  -938,   -85,  -938,  -938,  -938,   542,
    -938,  -938,  -938,  -938,   -75,  -938,  -938,  -938,   733,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,   -52,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
     652,  -938,  -938,  -938,  -938,  -938,   716,  -938,  -938,  -938,
    -938,   956,  -938,  -938,  -938,  -938,   717,  -938,  -938,  -938,
    -938,   915,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,   973,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  1000,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938,  -938,   866,  -938,  -938,  -938,  -938,  -938,  -938,  -938,
    -938
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    28,   806,   807,  1012,  1013,    29,    30,    68,
     235,   489,   490,    31,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,    32,    84,    85,
      86,    87,    88,    33,    70,   496,   497,   498,   499,    34,
      77,   573,   574,   575,   576,   577,   578,    35,   287,   288,
     289,   290,   291,   972,   973,   974,   975,   976,  1127,  1206,
      36,    71,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   735,  1099,  1100,    37,    57,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   616,   998,   999,    38,    66,
     481,   722,  1064,  1065,   482,   483,   484,  1068,   923,   924,
     485,   486,    39,    64,   461,   462,   463,   464,   465,   466,
     467,   709,  1050,  1051,   468,    40,    72,   527,   528,   529,
     530,   531,    41,   295,   296,   297,    42,    79,   586,   587,
     588,   589,   590,   791,  1145,  1146,    43,    75,   559,   560,
     561,   562,   774,  1122,  1123,    44,    59,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     644,  1025,  1026,   391,   392,   393,   394,    45,    65,   472,
     473,   474,   475,    46,    60,   398,   399,   400,   401,    47,
     144,   145,   146,    48,    62,   408,   409,   410,   411,    49,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,    50,   132,   133,   134,   135,   136,   137,   138,
     139,    51,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      52,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     836,   837,   597,  1175,    89,   600,   601,   602,  1148,   604,
     605,   285,  1149,    80,   395,  1153,  1023,   523,   142,  1154,
    1155,   968,   582,    55,  1156,   996,    56,   469,    53,    54,
     835,   493,    90,    91,   454,   493,  1157,   469,   476,   142,
    1158,    92,    58,   293,   582,   293,    81,    61,    80,  1170,
      63,   285,   148,  1171,    82,   455,    67,   149,   150,   395,
     151,   152,   524,  1172,   487,   488,   153,  1173,    93,    94,
      95,    96,  1150,  1151,  1152,    69,   405,   456,   154,   155,
     125,    81,   396,    97,    98,    99,   143,   156,   157,    82,
      73,   158,   159,   100,   101,   102,   477,   103,   104,   126,
     127,   997,   525,   259,   457,   105,   478,   143,   479,   666,
      74,   668,   669,   160,   671,   161,   494,    76,   556,   676,
     494,   678,   128,    83,    78,   568,   162,   396,   685,   163,
     164,   969,   583,   260,   691,   692,   261,   694,   556,   165,
     166,   846,   847,   700,   701,   702,   397,   167,   168,   526,
     169,   968,   170,   294,   583,   294,   171,   172,    83,   470,
     458,   362,   262,   363,   124,   364,   323,   140,   480,   470,
     141,   500,   147,   173,   263,   174,   175,   176,  -120,   231,
     177,   232,   365,   324,   325,   178,   406,  1009,  1010,  1011,
     459,   397,   501,  1024,   233,   234,   568,   129,   495,   405,
     264,  1179,   495,   970,   366,  1180,   179,   180,   407,   237,
     181,   182,   265,   266,   502,   286,   267,   268,  -120,   367,
     321,   368,   130,   971,   584,   238,   240,   585,   557,   303,
     753,   369,   471,   749,   403,   569,   326,  1128,   793,   460,
     131,   503,   471,   370,   183,   184,   584,   730,   557,   585,
     713,   185,   186,   717,   724,   286,   239,   327,   328,   580,
     187,   969,   188,   595,   241,   329,   284,   565,   452,   330,
     292,   371,   242,   243,   244,   657,   331,   245,   246,   523,
     298,   504,   247,   248,   332,   333,   334,   299,   570,   491,
     300,   372,   663,   492,   301,   335,   360,   505,   269,   571,
     270,   302,   373,  1059,   305,   500,   569,   306,   572,   406,
     307,   374,  1060,   308,   827,   309,   829,   336,   310,   554,
     558,   834,   311,   375,   524,   312,   501,   313,   454,   314,
     315,   407,  1061,   970,   775,   542,  1198,   476,  1199,   316,
     558,   785,   337,   317,   856,   318,   319,   859,   502,   455,
     320,   354,   355,   971,   356,   376,   506,   377,   357,   570,
     358,   359,   402,   412,   525,   413,   414,   507,   563,   508,
     571,   456,   415,   416,   417,   503,   509,   653,   567,   572,
     510,   418,   628,   148,   419,  1200,   420,   743,   149,   150,
     835,   151,   152,   591,   421,   477,   422,   153,   457,   423,
     424,   425,  1201,   426,   427,   478,   428,   479,   429,   154,
     155,   526,   430,   594,   431,   504,   596,   432,   156,   157,
     433,  1041,   158,   159,   434,   435,   436,  1073,  1202,  1203,
     437,   505,   438,   439,  1074,   987,   988,   989,   990,   991,
     992,   993,   540,   599,   160,   440,   161,   441,  1075,  1076,
    1042,   442,   443,   444,   458,   445,   259,   162,  1077,  1062,
     163,   164,   446,   447,   448,  1063,   449,   480,  1204,   450,
     165,   166,   451,   532,  1205,   533,   534,   535,   167,   168,
     592,   169,  1043,   170,   459,   536,   260,   171,   172,   261,
     506,   537,   538,   539,   543,   544,  1078,  1079,   603,  1080,
    1176,   507,   545,   508,   173,   546,   174,   175,   176,   547,
     509,   177,   548,   549,   510,   262,   178,  1044,  1045,   550,
     551,   552,  1046,   553,   564,   579,  1081,   263,   593,   125,
    1082,   598,   606,   460,   607,   608,   609,   179,   180,  1083,
     610,   181,   182,   611,   614,   612,  1047,   613,   126,   127,
     615,   617,   618,   264,   632,   619,   620,   630,  1084,   621,
    1085,   622,   623,  1086,   624,   265,   266,   625,   626,   267,
     268,   128,   627,  1112,   631,   183,   184,   636,   633,   634,
     635,  1087,   185,   186,   637,   362,   659,   363,   638,   364,
    1088,   187,  1089,   188,   639,  1090,  1048,  1091,     2,     3,
     660,  1092,     4,   640,  1093,   641,   365,   642,   643,   645,
    1094,   646,  1095,  1096,   647,     5,   648,   649,  1049,   650,
       6,   323,     7,   665,     8,   651,   652,  1097,   366,   655,
     656,     9,  1135,   661,   662,  1098,   667,  1113,   324,   325,
     670,   672,   673,   367,    10,   368,   129,   674,    11,    12,
     675,   269,   677,   270,   679,   369,   680,   681,   682,  1114,
     683,   684,   686,   687,  1115,   690,   688,   370,    13,  1116,
     689,   130,    14,   799,   800,   801,   802,   803,   804,   805,
     693,   695,    15,    16,  1117,   696,  1118,  1119,   697,   131,
     698,   326,   699,   703,   704,   371,  1136,   705,   706,   719,
     726,  1120,   707,   708,   710,   711,    17,    18,   712,  1121,
     715,   716,   327,   328,   751,   372,   727,   720,  1137,   732,
     329,    19,   721,  1138,   330,    89,   373,   723,  1139,   728,
     729,   331,   733,   734,   736,   374,   737,   738,    20,   332,
     333,   334,   739,  1140,   596,  1141,  1142,   375,   740,   741,
     335,    21,    22,    90,    91,   742,   745,   746,   752,   747,
    1143,   748,    92,    23,   754,   755,   756,   757,  1144,   758,
     759,    24,   336,   760,    25,   761,   763,   762,    26,   376,
      27,   377,   240,   764,   765,   766,   767,   773,   768,    93,
      94,    95,    96,   769,   770,   777,   781,   337,   771,   772,
    1162,  1066,   778,   787,    97,    98,    99,   780,   779,   830,
     782,   783,   784,   788,   100,   101,   102,   789,   103,   104,
     241,   823,   790,   792,   795,   796,   105,   797,   242,   243,
     244,   798,   808,   245,   246,   809,   825,   810,   247,   248,
     811,   812,   813,   814,   815,   816,   817,   818,   819,   820,
     821,   822,   824,   826,   828,   831,   832,   833,   835,   849,
     838,   839,   840,   841,   842,   843,   844,   845,   848,   850,
     851,  1067,   853,   854,   857,   852,   855,   858,   860,   926,
     862,   861,   863,   555,   731,   864,   865,   866,   867,   911,
     921,   868,   869,   870,   871,   872,   873,   874,   875,   876,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
     887,   888,   889,   890,   891,   892,   893,   894,   895,   896,
     897,   898,   899,   900,   901,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   912,   913,   914,   931,   937,   915,
     916,   917,  1185,   919,   918,   920,   925,   922,   927,   928,
    1189,   930,   929,   933,   934,   236,   932,   935,   936,   304,
     965,   938,   939,  1129,   941,   940,   942,   943,   786,   984,
     944,   945,   946,   947,   948,   949,   950,   951,   952,   953,
     954,   955,   956,   957,   958,   959,   960,   961,   962,   963,
     964,   966,   977,   967,   978,   981,   979,   980,  1193,   983,
     982,   985,   986,  1186,   994,   995,  1000,  1001,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,  1014,  1015,  1016,  1017,  1018,
    1019,  1020,  1021,  1022,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1052,  1053,
    1054,  1055,  1056,  1057,  1058,  1069,  1070,  1071,  1072,  1101,
    1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
    1124,  1187,  1159,  1125,  1126,  1130,  1131,  1132,  1133,  1134,
    1147,  1161,  1188,  1190,  1191,  1163,  1164,  1165,  1166,  1167,
    1168,  1169,  1174,  1177,  1192,  1178,  1195,  1196,  1197,  1208,
    1181,  1184,   725,  1183,  1160,  1207,   794,   714,  1194,   744,
     404,   776,  1182,   750,   453,   361,   322,     0,     0,     0,
       0,   654,   629,     0,   658,   541,     0,     0,     0,     0,
       0,     0,     0,     0,   718,   664,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   566,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   581
};

static const yytype_int16 yycheck[] =
{
     626,   627,   306,   188,     1,   309,   310,   311,   216,   313,
     314,     1,   220,     1,     1,   216,     8,     1,     1,   220,
     216,     1,     1,   221,   220,    56,   221,     1,   216,   217,
     215,     1,    29,    30,     1,     1,   216,     1,     1,     1,
     220,    38,   221,     1,     1,     1,    34,   221,     1,   216,
     221,     1,     1,   220,    42,    22,   214,     6,     7,     1,
       9,    10,    46,   216,   138,   139,    15,   220,    65,    66,
      67,    68,  1009,  1010,  1011,   218,     1,    44,    27,    28,
       1,    34,    69,    80,    81,    82,    69,    36,    37,    42,
     221,    40,    41,    90,    91,    92,    59,    94,    95,    20,
      21,   132,    86,     1,    71,   102,    69,    69,    71,   413,
     221,   415,   416,    62,   418,    64,    86,   221,     1,   423,
      86,   425,    43,   111,   221,     1,    75,    69,   432,    78,
      79,   111,   111,    31,   438,   439,    34,   441,     1,    88,
      89,   170,   171,   447,   448,   449,   133,    96,    97,   133,
      99,     1,   101,   111,   111,   111,   105,   106,   111,   133,
     127,     1,    60,     3,   221,     5,     1,   221,   131,   133,
     221,     1,   221,   122,    72,   124,   125,   126,   168,   221,
     129,   221,    22,    18,    19,   134,   111,    12,    13,    14,
     157,   133,    22,   185,   221,   219,     1,   118,   168,     1,
      98,   216,   168,   183,    44,   220,   155,   156,   133,   221,
     159,   160,   110,   111,    44,   205,   114,   115,   168,    59,
     217,    61,   143,   203,   203,   221,     1,   206,   111,   217,
     534,    71,   206,   217,   217,   111,    71,   217,   217,   206,
     161,    71,   206,    83,   193,   194,   203,   217,   111,   206,
     217,   200,   201,   217,   217,   205,   221,    92,    93,   217,
     209,   111,   211,   215,    39,   100,   221,   217,   217,   104,
     221,   111,    47,    48,    49,   217,   111,    52,    53,     1,
     221,   111,    57,    58,   119,   120,   121,   216,   164,   216,
     218,   131,   217,   216,   218,   130,   217,   127,   196,   175,
     198,   218,   142,    23,   218,     1,   111,   218,   184,   111,
     218,   151,    32,   218,   618,   218,   620,   152,   218,   217,
     203,   625,   218,   163,    46,   218,    22,   218,     1,   218,
     218,   133,    52,   183,   217,   216,    74,     1,    76,   218,
     203,   217,   177,   218,   648,   218,   218,   651,    44,    22,
     218,   218,   218,   203,   218,   195,   186,   197,   218,   164,
     218,   218,   218,   218,    86,   218,   218,   197,   216,   199,
     175,    44,   218,   218,   218,    71,   206,   217,   168,   184,
     210,   218,   217,     1,   218,   123,   218,   217,     6,     7,
     215,     9,    10,   214,   218,    59,   218,    15,    71,   218,
     218,   218,   140,   218,   218,    69,   218,    71,   218,    27,
      28,   133,   218,   216,   218,   111,   215,   218,    36,    37,
     218,    16,    40,    41,   218,   218,   218,     4,   166,   167,
     218,   127,   218,   218,    11,   799,   800,   801,   802,   803,
     804,   805,   217,   215,    62,   218,    64,   218,    25,    26,
      45,   218,   218,   218,   127,   218,     1,    75,    35,   179,
      78,    79,   218,   218,   218,   185,   218,   131,   206,   218,
      88,    89,   218,   218,   212,   218,   218,   218,    96,    97,
     214,    99,    77,   101,   157,   218,    31,   105,   106,    34,
     186,   218,   218,   218,   218,   218,    73,    74,   215,    76,
    1126,   197,   218,   199,   122,   218,   124,   125,   126,   218,
     206,   129,   218,   218,   210,    60,   134,   112,   113,   218,
     218,   218,   117,   218,   218,   218,   103,    72,   214,     1,
     107,   192,   215,   206,   215,   215,   215,   155,   156,   116,
     215,   159,   160,   215,   218,   216,   141,   216,    20,    21,
     218,   218,   218,    98,   192,   218,   218,   215,   135,   218,
     137,   218,   218,   140,   218,   110,   111,   218,   218,   114,
     115,    43,   218,    76,   215,   193,   194,   216,   215,   214,
     214,   158,   200,   201,   216,     1,   214,     3,   218,     5,
     167,   209,   169,   211,   218,   172,   191,   174,     0,     1,
     216,   178,     4,   218,   181,   218,    22,   218,   218,   218,
     187,   218,   189,   190,   218,    17,   218,   218,   213,   218,
      22,     1,    24,   192,    26,   218,   218,   204,    44,   218,
     218,    33,    76,   218,   218,   212,   215,   140,    18,    19,
     215,   192,   192,    59,    46,    61,   118,   215,    50,    51,
     215,   196,   192,   198,   215,    71,   215,   215,   215,   162,
     215,   215,   215,   215,   167,   192,   215,    83,    70,   172,
     214,   143,    74,   144,   145,   146,   147,   148,   149,   150,
     192,   192,    84,    85,   187,   215,   189,   190,   192,   161,
     192,    71,   215,   192,   215,   111,   140,   216,   216,   216,
     220,   204,   218,   218,   218,   218,   108,   109,   218,   212,
     218,   218,    92,    93,   192,   131,   216,   218,   162,   216,
     100,   123,   218,   167,   104,     1,   142,   218,   172,   218,
     218,   111,   218,   218,   218,   151,   218,   218,   140,   119,
     120,   121,   218,   187,   215,   189,   190,   163,   218,   218,
     130,   153,   154,    29,    30,   218,   216,   218,   192,   218,
     204,   218,    38,   165,   214,   192,   214,   192,   212,   192,
     216,   173,   152,   215,   176,   214,   214,   192,   180,   195,
     182,   197,     1,   215,   214,   214,   214,   218,   214,    65,
      66,    67,    68,   214,   214,   192,   218,   177,   216,   216,
     219,   202,   216,   214,    80,    81,    82,   216,   221,   214,
     218,   218,   218,   216,    90,    91,    92,   216,    94,    95,
      39,   215,   218,   218,   216,   216,   102,   216,    47,    48,
      49,   216,   216,    52,    53,   216,   218,   216,    57,    58,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   215,   215,   215,   215,   215,   215,   215,   192,
     216,   216,   216,   216,   216,   216,   216,   214,   214,   214,
     214,   220,   214,   214,   214,   218,   215,   214,   214,   726,
     214,   216,   214,   271,   496,   216,   216,   214,   214,   218,
     218,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   214,   192,   214,   214,   214,   192,   192,   216,
     214,   214,    63,   214,   216,   214,   216,   215,   214,   214,
      87,   214,   216,   214,   214,    69,   218,   214,   214,    84,
     218,   214,   214,   972,   214,   216,   214,   214,   573,   218,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     214,   216,   214,   216,   214,   216,   214,   214,  1171,   214,
     216,   214,   216,   136,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   140,   215,   218,   218,   216,   216,   216,   216,   216,
     216,   216,   136,   140,   136,   219,   219,   219,   219,   219,
     219,   219,   214,   218,   136,   216,   216,   216,   216,   216,
    1149,  1158,   482,  1156,  1067,  1180,   586,   461,  1173,   511,
     144,   559,  1154,   527,   189,   132,   106,    -1,    -1,    -1,
      -1,   378,   338,    -1,   398,   249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   472,   408,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   295
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   223,     0,     1,     4,    17,    22,    24,    26,    33,
      46,    50,    51,    70,    74,    84,    85,   108,   109,   123,
     140,   153,   154,   165,   173,   176,   180,   182,   224,   229,
     230,   235,   249,   255,   261,   269,   282,   299,   320,   334,
     347,   354,   358,   368,   377,   399,   405,   411,   415,   421,
     464,   473,   492,   216,   217,   221,   221,   300,   221,   378,
     406,   221,   416,   221,   335,   400,   321,   214,   231,   218,
     256,   283,   348,   221,   221,   369,   221,   262,   221,   359,
       1,    34,    42,   111,   250,   251,   252,   253,   254,     1,
      29,    30,    38,    65,    66,    67,    68,    80,    81,    82,
      90,    91,    92,    94,    95,   102,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   221,     1,    20,    21,    43,   118,
     143,   161,   465,   466,   467,   468,   469,   470,   471,   472,
     221,   221,     1,    69,   412,   413,   414,   221,     1,     6,
       7,     9,    10,    15,    27,    28,    36,    37,    40,    41,
      62,    64,    75,    78,    79,    88,    89,    96,    97,    99,
     101,   105,   106,   122,   124,   125,   126,   129,   134,   155,
     156,   159,   160,   193,   194,   200,   201,   209,   211,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   221,   221,   221,   219,   232,   231,   221,   221,   221,
       1,    39,    47,    48,    49,    52,    53,    57,    58,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     1,
      31,    34,    60,    72,    98,   110,   111,   114,   115,   196,
     198,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   221,     1,   205,   270,   271,   272,
     273,   274,   221,     1,   111,   355,   356,   357,   221,   216,
     218,   218,   218,   217,   251,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   217,   475,     1,    18,    19,    71,    92,    93,   100,
     104,   111,   119,   120,   121,   130,   152,   177,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   218,   218,   218,   218,   218,   218,
     217,   466,     1,     3,     5,    22,    44,    59,    61,    71,
      83,   111,   131,   142,   151,   163,   195,   197,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   395,   396,   397,   398,     1,    69,   133,   407,   408,
     409,   410,   218,   217,   413,     1,   111,   133,   417,   418,
     419,   420,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   217,   423,     1,    22,    44,    71,   127,   157,
     206,   336,   337,   338,   339,   340,   341,   342,   346,     1,
     133,   206,   401,   402,   403,   404,     1,    59,    69,    71,
     131,   322,   326,   327,   328,   332,   333,   138,   139,   233,
     234,   216,   216,     1,    86,   168,   257,   258,   259,   260,
       1,    22,    44,    71,   111,   127,   186,   197,   199,   206,
     210,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     1,    46,    86,   133,   349,   350,   351,
     352,   353,   218,   218,   218,   218,   218,   218,   218,   218,
     217,   494,   216,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   217,   237,     1,   111,   203,   370,
     371,   372,   373,   216,   218,   217,   271,   168,     1,   111,
     164,   175,   184,   263,   264,   265,   266,   267,   268,   218,
     217,   356,     1,   111,   203,   206,   360,   361,   362,   363,
     364,   214,   214,   214,   216,   215,   215,   226,   192,   215,
     226,   226,   226,   215,   226,   226,   215,   215,   215,   215,
     215,   215,   216,   216,   218,   218,   317,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   217,   302,
     215,   215,   192,   215,   214,   214,   216,   216,   218,   218,
     218,   218,   218,   218,   392,   218,   218,   218,   218,   218,
     218,   218,   218,   217,   380,   218,   218,   217,   408,   214,
     216,   218,   218,   217,   418,   192,   226,   215,   226,   226,
     215,   226,   192,   192,   215,   215,   226,   192,   226,   215,
     215,   215,   215,   215,   215,   226,   215,   215,   215,   214,
     192,   226,   226,   192,   226,   192,   215,   192,   192,   215,
     226,   226,   226,   192,   215,   216,   216,   218,   218,   343,
     218,   218,   218,   217,   337,   218,   218,   217,   402,   216,
     218,   218,   323,   218,   217,   327,   220,   216,   218,   218,
     217,   258,   216,   218,   218,   296,   218,   218,   218,   218,
     218,   218,   218,   217,   285,   216,   218,   218,   218,   217,
     350,   192,   192,   226,   214,   192,   214,   192,   192,   216,
     215,   214,   192,   214,   215,   214,   214,   214,   214,   214,
     214,   216,   216,   218,   374,   217,   371,   192,   216,   221,
     216,   218,   218,   218,   218,   217,   264,   214,   216,   216,
     218,   365,   218,   217,   361,   216,   216,   216,   216,   144,
     145,   146,   147,   148,   149,   150,   225,   226,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   215,   215,   218,   215,   226,   215,   226,
     214,   215,   215,   215,   226,   215,   228,   228,   216,   216,
     216,   216,   216,   216,   216,   214,   170,   171,   214,   192,
     214,   214,   218,   214,   214,   215,   226,   214,   214,   226,
     214,   216,   214,   214,   216,   216,   214,   214,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   214,
     192,   218,   214,   214,   214,   216,   214,   214,   216,   214,
     214,   218,   215,   330,   331,   216,   234,   214,   214,   216,
     214,   192,   218,   214,   214,   214,   214,   192,   214,   214,
     216,   214,   214,   214,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   214,   218,   216,   216,     1,   111,
     183,   203,   275,   276,   277,   278,   279,   214,   214,   214,
     214,   216,   216,   214,   218,   214,   216,   225,   225,   225,
     225,   225,   225,   225,   216,   216,    56,   132,   318,   319,
     216,   216,   216,   216,   216,   216,   216,   216,   216,    12,
      13,    14,   227,   228,   216,   216,   216,   216,   216,   216,
     216,   216,   216,     8,   185,   393,   394,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,    16,    45,    77,   112,   113,   117,   141,   191,   213,
     344,   345,   216,   216,   216,   216,   216,   216,   216,    23,
      32,    52,   179,   185,   324,   325,   202,   220,   329,   216,
     216,   216,   216,     4,    11,    25,    26,    35,    73,    74,
      76,   103,   107,   116,   135,   137,   140,   158,   167,   169,
     172,   174,   178,   181,   187,   189,   190,   204,   212,   297,
     298,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,    76,   140,   162,   167,   172,   187,   189,   190,
     204,   212,   375,   376,   216,   218,   218,   280,   217,   276,
     216,   216,   216,   216,   216,    76,   140,   162,   167,   172,
     187,   189,   190,   204,   212,   366,   367,   216,   216,   220,
     227,   227,   227,   216,   220,   216,   220,   216,   220,   215,
     331,   216,   219,   219,   219,   219,   219,   219,   219,   219,
     216,   220,   216,   220,   214,   188,   228,   218,   216,   216,
     220,   319,   394,   345,   325,    63,   136,   140,   136,    87,
     140,   136,   136,   298,   376,   216,   216,   216,    74,    76,
     123,   140,   166,   167,   206,   212,   281,   367,   216
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
     298,   298,   298,   298,   298,   298,   298,   298,   298,   300,
     299,   301,   301,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   303,   304,
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
     380,   380,   380,   380,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   390,   392,   391,   393,   393,
     394,   394,   395,   396,   397,   398,   400,   399,   401,   401,
     402,   402,   402,   403,   404,   406,   405,   407,   407,   408,
     408,   408,   409,   410,   411,   412,   412,   413,   413,   414,
     416,   415,   417,   417,   418,   418,   418,   419,   420,   421,
     422,   422,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   465,   466,   466,   466,   466,
     466,   466,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   474,   475,   475,   475,   475,   475,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   493,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   495,   496,   497,
     498,   499,   500,   501,   502
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
       1,     1,     3,     3,     1,     1,     1,     3,     3,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
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
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     4,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4
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
#line 354 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3131 "conf_parser.c"
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
#line 390 "conf_parser.y"
           { (yyval.number) = 0; }
#line 3404 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER timespec_  */
#line 391 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3410 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER SECONDS timespec_  */
#line 392 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3416 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER MINUTES timespec_  */
#line 393 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3422 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER HOURS timespec_  */
#line 394 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3428 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER DAYS timespec_  */
#line 395 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3434 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER WEEKS timespec_  */
#line 396 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3440 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER MONTHS timespec_  */
#line 397 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3446 "conf_parser.c"
    break;

  case 39: /* timespec: NUMBER YEARS timespec_  */
#line 398 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3452 "conf_parser.c"
    break;

  case 40: /* sizespec_: %empty  */
#line 401 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3458 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER sizespec_  */
#line 402 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3464 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER BYTES sizespec_  */
#line 403 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3470 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER KBYTES sizespec_  */
#line 404 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3476 "conf_parser.c"
    break;

  case 45: /* sizespec: NUMBER MBYTES sizespec_  */
#line 405 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3482 "conf_parser.c"
    break;

  case 46: /* module_base_path_entry: MODULE_BASE_PATH '=' module_string ';'  */
#line 413 "conf_parser.y"
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
#line 3499 "conf_parser.c"
    break;

  case 47: /* loadmodule_entry: LOADMODULE module_string module_attributes ';'  */
#line 431 "conf_parser.y"
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
#line 3516 "conf_parser.c"
    break;

  case 48: /* module_string: QSTRING  */
#line 446 "conf_parser.y"
{
  (yyval.string) = io_strdup((yyvsp[0].string));
}
#line 3524 "conf_parser.c"
    break;

  case 49: /* module_attributes: %empty  */
#line 451 "conf_parser.y"
{
  (yyval.number) = 0;
}
#line 3532 "conf_parser.c"
    break;

  case 50: /* module_attributes: ':' module_attributes_items  */
#line 454 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3540 "conf_parser.c"
    break;

  case 51: /* module_attributes_items: module_attributes_items ',' module_attributes_item  */
#line 459 "conf_parser.y"
{
  (yyval.number) = (yyvsp[-2].number) | (yyvsp[0].number);
}
#line 3548 "conf_parser.c"
    break;

  case 52: /* module_attributes_items: module_attributes_item  */
#line 462 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3556 "conf_parser.c"
    break;

  case 53: /* module_attributes_item: RESIDENT  */
#line 467 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_DEACTIVATE;
}
#line 3564 "conf_parser.c"
    break;

  case 54: /* module_attributes_item: REQUIRED  */
#line 470 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_REMOVE;
}
#line 3572 "conf_parser.c"
    break;

  case 70: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 496 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3584 "conf_parser.c"
    break;

  case 71: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 505 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3596 "conf_parser.c"
    break;

  case 72: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 514 "conf_parser.y"
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
#line 3614 "conf_parser.c"
    break;

  case 73: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 529 "conf_parser.y"
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
#line 3632 "conf_parser.c"
    break;

  case 74: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 544 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3645 "conf_parser.c"
    break;

  case 75: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 554 "conf_parser.y"
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
#line 3662 "conf_parser.c"
    break;

  case 76: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 568 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3674 "conf_parser.c"
    break;

  case 77: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 577 "conf_parser.y"
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
#line 3700 "conf_parser.c"
    break;

  case 78: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 600 "conf_parser.y"
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
#line 3726 "conf_parser.c"
    break;

  case 79: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 623 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3738 "conf_parser.c"
    break;

  case 80: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 632 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3747 "conf_parser.c"
    break;

  case 88: /* admin_name: NAME '=' QSTRING ';'  */
#line 650 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3759 "conf_parser.c"
    break;

  case 89: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 659 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3771 "conf_parser.c"
    break;

  case 90: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 668 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3783 "conf_parser.c"
    break;

  case 91: /* $@1: %empty  */
#line 681 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3792 "conf_parser.c"
    break;

  case 92: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 685 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3809 "conf_parser.c"
    break;

  case 98: /* motd_mask: MASK '=' QSTRING ';'  */
#line 702 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3818 "conf_parser.c"
    break;

  case 99: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 708 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3827 "conf_parser.c"
    break;

  case 100: /* $@2: %empty  */
#line 718 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3836 "conf_parser.c"
    break;

  case 101: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 722 "conf_parser.y"
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
#line 3854 "conf_parser.c"
    break;

  case 109: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 740 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3863 "conf_parser.c"
    break;

  case 110: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 746 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3872 "conf_parser.c"
    break;

  case 111: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 752 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3881 "conf_parser.c"
    break;

  case 112: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 758 "conf_parser.y"
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
#line 3903 "conf_parser.c"
    break;

  case 119: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 787 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 3915 "conf_parser.c"
    break;

  case 120: /* $@3: %empty  */
#line 796 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3924 "conf_parser.c"
    break;

  case 121: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 800 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 3937 "conf_parser.c"
    break;

  case 128: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 816 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3948 "conf_parser.c"
    break;

  case 129: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 824 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3956 "conf_parser.c"
    break;

  case 130: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 827 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3964 "conf_parser.c"
    break;

  case 131: /* $@4: %empty  */
#line 832 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3973 "conf_parser.c"
    break;

  case 133: /* logging_file_type_item: USER  */
#line 838 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3982 "conf_parser.c"
    break;

  case 134: /* logging_file_type_item: OPERATOR  */
#line 842 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3991 "conf_parser.c"
    break;

  case 135: /* logging_file_type_item: XLINE  */
#line 846 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4000 "conf_parser.c"
    break;

  case 136: /* logging_file_type_item: RESV  */
#line 850 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4009 "conf_parser.c"
    break;

  case 137: /* logging_file_type_item: T_DLINE  */
#line 854 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4018 "conf_parser.c"
    break;

  case 138: /* logging_file_type_item: KLINE  */
#line 858 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4027 "conf_parser.c"
    break;

  case 139: /* logging_file_type_item: KILL  */
#line 862 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4036 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: T_DEBUG  */
#line 866 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4045 "conf_parser.c"
    break;

  case 141: /* $@5: %empty  */
#line 876 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4057 "conf_parser.c"
    break;

  case 142: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 883 "conf_parser.y"
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
#line 4115 "conf_parser.c"
    break;

  case 156: /* oper_name: NAME '=' QSTRING ';'  */
#line 951 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4124 "conf_parser.c"
    break;

  case 157: /* oper_user: USER '=' QSTRING ';'  */
#line 957 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4133 "conf_parser.c"
    break;

  case 158: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 963 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4142 "conf_parser.c"
    break;

  case 159: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 969 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4151 "conf_parser.c"
    break;

  case 160: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 975 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4165 "conf_parser.c"
    break;

  case 161: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 986 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4174 "conf_parser.c"
    break;

  case 162: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 992 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4188 "conf_parser.c"
    break;

  case 163: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1003 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4197 "conf_parser.c"
    break;

  case 164: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1009 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4206 "conf_parser.c"
    break;

  case 165: /* $@6: %empty  */
#line 1015 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4215 "conf_parser.c"
    break;

  case 169: /* oper_flags_item: KILL ':' REMOTE  */
#line 1022 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4224 "conf_parser.c"
    break;

  case 170: /* oper_flags_item: KILL  */
#line 1026 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4233 "conf_parser.c"
    break;

  case 171: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1030 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4242 "conf_parser.c"
    break;

  case 172: /* oper_flags_item: CONNECT  */
#line 1034 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4251 "conf_parser.c"
    break;

  case 173: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1038 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4260 "conf_parser.c"
    break;

  case 174: /* oper_flags_item: SQUIT  */
#line 1042 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4269 "conf_parser.c"
    break;

  case 175: /* oper_flags_item: KLINE  */
#line 1046 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4278 "conf_parser.c"
    break;

  case 176: /* oper_flags_item: UNKLINE  */
#line 1050 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4287 "conf_parser.c"
    break;

  case 177: /* oper_flags_item: T_DLINE  */
#line 1054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4296 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: T_UNDLINE  */
#line 1058 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4305 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: XLINE  */
#line 1062 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4314 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: T_UNXLINE  */
#line 1066 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4323 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: DIE  */
#line 1070 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4332 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: T_RESTART  */
#line 1074 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4341 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1078 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4350 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: REHASH  */
#line 1082 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4359 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: ADMIN  */
#line 1086 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4368 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_GLOBOPS  */
#line 1090 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4377 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_LOCOPS  */
#line 1094 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4386 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: REMOTEBAN  */
#line 1098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4395 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_SET  */
#line 1102 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4404 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: MODULE  */
#line 1106 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4413 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_OPME  */
#line 1110 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4422 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: NICK ':' RESV  */
#line 1114 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4431 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: JOIN ':' RESV  */
#line 1118 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4440 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: RESV  */
#line 1122 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4449 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_UNRESV  */
#line 1126 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4458 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: CLOSE  */
#line 1130 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4467 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1134 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4476 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: BYPASS ':' INPUT_FLOOD  */
#line 1138 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_BYPASS_INPUT_FLOOD;
}
#line 4485 "conf_parser.c"
    break;

  case 199: /* $@7: %empty  */
#line 1148 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4500 "conf_parser.c"
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
#line 4547 "conf_parser.c"
    break;

  case 218: /* class_name: NAME '=' QSTRING ';'  */
#line 1219 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4556 "conf_parser.c"
    break;

  case 219: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1225 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4565 "conf_parser.c"
    break;

  case 220: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1231 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4574 "conf_parser.c"
    break;

  case 221: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1237 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4583 "conf_parser.c"
    break;

  case 222: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1243 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4592 "conf_parser.c"
    break;

  case 223: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1249 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4601 "conf_parser.c"
    break;

  case 224: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1255 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4610 "conf_parser.c"
    break;

  case 225: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1261 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4620 "conf_parser.c"
    break;

  case 226: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1268 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4629 "conf_parser.c"
    break;

  case 227: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1274 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4638 "conf_parser.c"
    break;

  case 228: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1280 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4647 "conf_parser.c"
    break;

  case 229: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1286 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4659 "conf_parser.c"
    break;

  case 230: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1295 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4671 "conf_parser.c"
    break;

  case 231: /* $@8: %empty  */
#line 1304 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4680 "conf_parser.c"
    break;

  case 235: /* class_flags_item: RANDOM_IDLE  */
#line 1311 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4689 "conf_parser.c"
    break;

  case 236: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1315 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4698 "conf_parser.c"
    break;

  case 237: /* $@9: %empty  */
#line 1325 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4707 "conf_parser.c"
    break;

  case 239: /* $@10: %empty  */
#line 1331 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4715 "conf_parser.c"
    break;

  case 243: /* listen_flags_item: T_TLS  */
#line 1337 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4724 "conf_parser.c"
    break;

  case 244: /* listen_flags_item: HIDDEN  */
#line 1341 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4733 "conf_parser.c"
    break;

  case 245: /* listen_flags_item: T_SERVER  */
#line 1345 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4742 "conf_parser.c"
    break;

  case 246: /* listen_flags_item: CLIENT  */
#line 1349 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4751 "conf_parser.c"
    break;

  case 247: /* listen_flags_item: DEFER  */
#line 1353 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4760 "conf_parser.c"
    break;

  case 255: /* $@11: %empty  */
#line 1361 "conf_parser.y"
                                 { reset_block_state(); }
#line 4766 "conf_parser.c"
    break;

  case 259: /* port_item: NUMBER  */
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
#line 4784 "conf_parser.c"
    break;

  case 260: /* port_item: NUMBER TWODOTS NUMBER  */
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
#line 4804 "conf_parser.c"
    break;

  case 261: /* listen_address: IP '=' QSTRING ';'  */
#line 1396 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4813 "conf_parser.c"
    break;

  case 262: /* listen_host: HOST '=' QSTRING ';'  */
#line 1402 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4822 "conf_parser.c"
    break;

  case 263: /* $@12: %empty  */
#line 1412 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4831 "conf_parser.c"
    break;

  case 264: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
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
#line 4886 "conf_parser.c"
    break;

  case 274: /* auth_user: USER '=' QSTRING ';'  */
#line 1477 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4895 "conf_parser.c"
    break;

  case 275: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1483 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4904 "conf_parser.c"
    break;

  case 276: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1489 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4913 "conf_parser.c"
    break;

  case 277: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
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
#line 4927 "conf_parser.c"
    break;

  case 278: /* $@13: %empty  */
#line 1506 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 4936 "conf_parser.c"
    break;

  case 282: /* auth_flags_item: EXCEED_LIMIT  */
#line 1514 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 4945 "conf_parser.c"
    break;

  case 283: /* auth_flags_item: KLINE_EXEMPT  */
#line 1518 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 4954 "conf_parser.c"
    break;

  case 284: /* auth_flags_item: XLINE_EXEMPT  */
#line 1522 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 4963 "conf_parser.c"
    break;

  case 285: /* auth_flags_item: NEED_IDENT  */
#line 1526 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 4972 "conf_parser.c"
    break;

  case 286: /* auth_flags_item: CAN_FLOOD  */
#line 1530 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 4981 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: NO_TILDE  */
#line 1534 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 4990 "conf_parser.c"
    break;

  case 288: /* auth_flags_item: RESV_EXEMPT  */
#line 1538 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 4999 "conf_parser.c"
    break;

  case 289: /* auth_flags_item: T_WEBIRC  */
#line 1542 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5008 "conf_parser.c"
    break;

  case 290: /* auth_flags_item: NEED_PASSWORD  */
#line 1546 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5017 "conf_parser.c"
    break;

  case 291: /* auth_spoof: SPOOF '=' QSTRING ';'  */
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
#line 5032 "conf_parser.c"
    break;

  case 292: /* $@14: %empty  */
#line 1567 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5044 "conf_parser.c"
    break;

  case 293: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1574 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5055 "conf_parser.c"
    break;

  case 300: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1585 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5064 "conf_parser.c"
    break;

  case 301: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1591 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5073 "conf_parser.c"
    break;

  case 302: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1597 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5082 "conf_parser.c"
    break;

  case 308: /* service_name: NAME '=' QSTRING ';'  */
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
#line 5097 "conf_parser.c"
    break;

  case 309: /* $@15: %empty  */
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
#line 5113 "conf_parser.c"
    break;

  case 310: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
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
#line 5128 "conf_parser.c"
    break;

  case 317: /* shared_name: NAME '=' QSTRING ';'  */
#line 1654 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5137 "conf_parser.c"
    break;

  case 318: /* shared_user: USER '=' QSTRING ';'  */
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
#line 5159 "conf_parser.c"
    break;

  case 319: /* $@16: %empty  */
#line 1679 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5168 "conf_parser.c"
    break;

  case 323: /* shared_type_item: KLINE  */
#line 1686 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5177 "conf_parser.c"
    break;

  case 324: /* shared_type_item: UNKLINE  */
#line 1690 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5186 "conf_parser.c"
    break;

  case 325: /* shared_type_item: T_DLINE  */
#line 1694 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5195 "conf_parser.c"
    break;

  case 326: /* shared_type_item: T_UNDLINE  */
#line 1698 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5204 "conf_parser.c"
    break;

  case 327: /* shared_type_item: XLINE  */
#line 1702 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5213 "conf_parser.c"
    break;

  case 328: /* shared_type_item: T_UNXLINE  */
#line 1706 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5222 "conf_parser.c"
    break;

  case 329: /* shared_type_item: RESV  */
#line 1710 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5231 "conf_parser.c"
    break;

  case 330: /* shared_type_item: T_UNRESV  */
#line 1714 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5240 "conf_parser.c"
    break;

  case 331: /* shared_type_item: T_LOCOPS  */
#line 1718 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5249 "conf_parser.c"
    break;

  case 332: /* shared_type_item: T_ALL  */
#line 1722 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5258 "conf_parser.c"
    break;

  case 333: /* $@17: %empty  */
#line 1732 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5272 "conf_parser.c"
    break;

  case 334: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1741 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5285 "conf_parser.c"
    break;

  case 340: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1754 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5294 "conf_parser.c"
    break;

  case 341: /* $@18: %empty  */
#line 1760 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5303 "conf_parser.c"
    break;

  case 345: /* cluster_type_item: KLINE  */
#line 1767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5312 "conf_parser.c"
    break;

  case 346: /* cluster_type_item: UNKLINE  */
#line 1771 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5321 "conf_parser.c"
    break;

  case 347: /* cluster_type_item: T_DLINE  */
#line 1775 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5330 "conf_parser.c"
    break;

  case 348: /* cluster_type_item: T_UNDLINE  */
#line 1779 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5339 "conf_parser.c"
    break;

  case 349: /* cluster_type_item: XLINE  */
#line 1783 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5348 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: T_UNXLINE  */
#line 1787 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5357 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: RESV  */
#line 1791 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5366 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: T_UNRESV  */
#line 1795 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5375 "conf_parser.c"
    break;

  case 353: /* cluster_type_item: T_LOCOPS  */
#line 1799 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5384 "conf_parser.c"
    break;

  case 354: /* cluster_type_item: T_ALL  */
#line 1803 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5393 "conf_parser.c"
    break;

  case 355: /* $@19: %empty  */
#line 1813 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECT_DEFAULT_TIMEOUT_SEC;
  block_state.retry_delay_sec.value = CONNECT_DEFAULT_RETRY_DELAY_SEC;
}
#line 5408 "conf_parser.c"
    break;

  case 356: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
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
  connect->retry_delay_sec = block_state.retry_delay_sec.value;
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
#line 5457 "conf_parser.c"
    break;

  case 375: /* connect_name: NAME '=' QSTRING ';'  */
#line 1887 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5466 "conf_parser.c"
    break;

  case 376: /* connect_host: HOST '=' QSTRING ';'  */
#line 1893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5475 "conf_parser.c"
    break;

  case 377: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1899 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5484 "conf_parser.c"
    break;

  case 378: /* connect_retry_delay: RETRY_DELAY '=' timespec ';'  */
#line 1905 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.retry_delay_sec.value = (yyvsp[-1].number);
}
#line 5493 "conf_parser.c"
    break;

  case 379: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1911 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5502 "conf_parser.c"
    break;

  case 380: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1917 "conf_parser.y"
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
#line 5518 "conf_parser.c"
    break;

  case 381: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1930 "conf_parser.y"
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
#line 5534 "conf_parser.c"
    break;

  case 382: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1943 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5543 "conf_parser.c"
    break;

  case 383: /* connect_port: PORT '=' NUMBER ';'  */
#line 1949 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5552 "conf_parser.c"
    break;

  case 384: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 1955 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5561 "conf_parser.c"
    break;

  case 385: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 1959 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5570 "conf_parser.c"
    break;

  case 386: /* $@20: %empty  */
#line 1965 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5578 "conf_parser.c"
    break;

  case 390: /* connect_flags_item: AUTOCONN  */
#line 1971 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5587 "conf_parser.c"
    break;

  case 391: /* connect_flags_item: T_TLS  */
#line 1975 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5596 "conf_parser.c"
    break;

  case 392: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1981 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5610 "conf_parser.c"
    break;

  case 393: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 1992 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5619 "conf_parser.c"
    break;

  case 394: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 1998 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5628 "conf_parser.c"
    break;

  case 395: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2004 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5637 "conf_parser.c"
    break;

  case 396: /* $@21: %empty  */
#line 2014 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5646 "conf_parser.c"
    break;

  case 397: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2018 "conf_parser.y"
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
#line 5670 "conf_parser.c"
    break;

  case 403: /* kill_user: USER '=' QSTRING ';'  */
#line 2042 "conf_parser.y"
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
#line 5693 "conf_parser.c"
    break;

  case 404: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2062 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5702 "conf_parser.c"
    break;

  case 405: /* $@22: %empty  */
#line 2072 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5711 "conf_parser.c"
    break;

  case 406: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2076 "conf_parser.y"
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
#line 5733 "conf_parser.c"
    break;

  case 412: /* deny_ip: IP '=' QSTRING ';'  */
#line 2098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5742 "conf_parser.c"
    break;

  case 413: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5751 "conf_parser.c"
    break;

  case 419: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2119 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_error_report("Unable to add D-line exemption");
}
#line 5763 "conf_parser.c"
    break;

  case 420: /* $@23: %empty  */
#line 2132 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5772 "conf_parser.c"
    break;

  case 421: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2136 "conf_parser.y"
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
#line 5792 "conf_parser.c"
    break;

  case 427: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2156 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5801 "conf_parser.c"
    break;

  case 428: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2162 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5810 "conf_parser.c"
    break;

  case 473: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2218 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5818 "conf_parser.c"
    break;

  case 474: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2223 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5826 "conf_parser.c"
    break;

  case 475: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2228 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5834 "conf_parser.c"
    break;

  case 476: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2233 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5842 "conf_parser.c"
    break;

  case 477: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2238 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5850 "conf_parser.c"
    break;

  case 478: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2243 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5858 "conf_parser.c"
    break;

  case 479: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2248 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5866 "conf_parser.c"
    break;

  case 480: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2253 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5874 "conf_parser.c"
    break;

  case 481: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2258 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5882 "conf_parser.c"
    break;

  case 482: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2263 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5890 "conf_parser.c"
    break;

  case 483: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2268 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5898 "conf_parser.c"
    break;

  case 484: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2273 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5906 "conf_parser.c"
    break;

  case 485: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2278 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5914 "conf_parser.c"
    break;

  case 486: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2283 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 5925 "conf_parser.c"
    break;

  case 487: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2291 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5933 "conf_parser.c"
    break;

  case 488: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2296 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5941 "conf_parser.c"
    break;

  case 489: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2301 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5949 "conf_parser.c"
    break;

  case 490: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2306 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5957 "conf_parser.c"
    break;

  case 491: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2311 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5965 "conf_parser.c"
    break;

  case 492: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2316 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5973 "conf_parser.c"
    break;

  case 493: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2321 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5981 "conf_parser.c"
    break;

  case 494: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2326 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5989 "conf_parser.c"
    break;

  case 495: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2331 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5997 "conf_parser.c"
    break;

  case 496: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2336 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6005 "conf_parser.c"
    break;

  case 497: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2341 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6013 "conf_parser.c"
    break;

  case 498: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2346 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6021 "conf_parser.c"
    break;

  case 499: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2351 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6029 "conf_parser.c"
    break;

  case 500: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2356 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6037 "conf_parser.c"
    break;

  case 501: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2361 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6045 "conf_parser.c"
    break;

  case 502: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2366 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6053 "conf_parser.c"
    break;

  case 503: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2371 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6061 "conf_parser.c"
    break;

  case 504: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2376 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6069 "conf_parser.c"
    break;

  case 505: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2381 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6077 "conf_parser.c"
    break;

  case 506: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2386 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6089 "conf_parser.c"
    break;

  case 507: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2395 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6097 "conf_parser.c"
    break;

  case 508: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2400 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6105 "conf_parser.c"
    break;

  case 509: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2405 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6113 "conf_parser.c"
    break;

  case 510: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2410 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6121 "conf_parser.c"
    break;

  case 511: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2415 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6132 "conf_parser.c"
    break;

  case 512: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2423 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6140 "conf_parser.c"
    break;

  case 523: /* cloak_enabled: ENABLED '=' TBOOL ';'  */
#line 2443 "conf_parser.y"
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
#line 6160 "conf_parser.c"
    break;

  case 524: /* cloak_cidr_len_ipv4: CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2460 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6172 "conf_parser.c"
    break;

  case 525: /* cloak_cidr_len_ipv6: CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2469 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6184 "conf_parser.c"
    break;

  case 526: /* cloak_num_bits: NUM_BITS '=' NUMBER ';'  */
#line 2478 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6196 "conf_parser.c"
    break;

  case 527: /* cloak_secret: SECRET '=' QSTRING ';'  */
#line 2487 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.secret);
  ConfigCloak.secret = io_strdup((yyvsp[-1].string));
  cloak_set_secret((yyvsp[-1].string));
}
#line 6209 "conf_parser.c"
    break;

  case 528: /* cloak_suffix: SUFFIX '=' QSTRING ';'  */
#line 2497 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.suffix);
  ConfigCloak.suffix = io_strdup((yyvsp[-1].string));
  cloak_set_suffix((yyvsp[-1].string));
}
#line 6222 "conf_parser.c"
    break;

  case 549: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2532 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6230 "conf_parser.c"
    break;

  case 550: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2537 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6238 "conf_parser.c"
    break;

  case 551: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2542 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6246 "conf_parser.c"
    break;

  case 552: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2547 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6254 "conf_parser.c"
    break;

  case 553: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2552 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6262 "conf_parser.c"
    break;

  case 554: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2557 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6270 "conf_parser.c"
    break;

  case 555: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2562 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6278 "conf_parser.c"
    break;

  case 556: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2567 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6286 "conf_parser.c"
    break;

  case 557: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2572 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6294 "conf_parser.c"
    break;

  case 558: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2577 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6302 "conf_parser.c"
    break;

  case 559: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2582 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6310 "conf_parser.c"
    break;

  case 560: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2587 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6318 "conf_parser.c"
    break;

  case 561: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2592 "conf_parser.y"
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
#line 6344 "conf_parser.c"
    break;

  case 562: /* channel_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 2615 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigChannel.max_topic_length = TOPICLEN;
  else
    ConfigChannel.max_topic_length = (yyvsp[-1].number);
}
#line 6355 "conf_parser.c"
    break;

  case 563: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2623 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6363 "conf_parser.c"
    break;

  case 564: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2628 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6371 "conf_parser.c"
    break;

  case 577: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2650 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6380 "conf_parser.c"
    break;

  case 578: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2656 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6394 "conf_parser.c"
    break;

  case 579: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2667 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6406 "conf_parser.c"
    break;

  case 580: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2676 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6415 "conf_parser.c"
    break;

  case 581: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2682 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6424 "conf_parser.c"
    break;

  case 582: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2688 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6433 "conf_parser.c"
    break;

  case 583: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2694 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6445 "conf_parser.c"
    break;

  case 584: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2703 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6454 "conf_parser.c"
    break;


#line 6458 "conf_parser.c"

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

