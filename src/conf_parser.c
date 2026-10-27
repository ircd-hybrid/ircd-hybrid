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
    CONNECTFREQ = 282,             /* CONNECTFREQ  */
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
    INPUT_FLOOD = 319,             /* INPUT_FLOOD  */
    INVISIBLE_ON_CONNECT = 320,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 321,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 322,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 323,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 324,      /* INVITE_EXPIRE_TIME  */
    IP = 325,                      /* IP  */
    IRCD_AUTH = 326,               /* IRCD_AUTH  */
    IRCD_FLAGS = 327,              /* IRCD_FLAGS  */
    IRCD_SID = 328,                /* IRCD_SID  */
    JOIN = 329,                    /* JOIN  */
    KILL = 330,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 331,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 332,                   /* KLINE  */
    KLINE_EXEMPT = 333,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 334,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 335,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 336,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 337,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 338,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 339,               /* LEAF_MASK  */
    LISTEN = 340,                  /* LISTEN  */
    LOADMODULE = 341,              /* LOADMODULE  */
    MASK = 342,                    /* MASK  */
    MASS = 343,                    /* MASS  */
    MAX_ACCEPT = 344,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 345,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 346,                /* MAX_BANS  */
    MAX_BANS_LARGE = 347,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 348,            /* MAX_CHANNELS  */
    MAX_IDLE = 349,                /* MAX_IDLE  */
    MAX_INVITES = 350,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 351,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 352,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 353,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 354,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 355,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 356,              /* MAX_NUMBER  */
    MAX_TARGETS = 357,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 358,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 359,                 /* MESSAGE  */
    MIN_IDLE = 360,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 361,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 362,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 363,                  /* MODULE  */
    MODULE_BASE_PATH = 364,        /* MODULE_BASE_PATH  */
    MOTD = 365,                    /* MOTD  */
    MOTD_FILE = 366,               /* MOTD_FILE  */
    NAME = 367,                    /* NAME  */
    NEED_IDENT = 368,              /* NEED_IDENT  */
    NEED_PASSWORD = 369,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 370,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 371,            /* NETWORK_NAME  */
    NICK = 372,                    /* NICK  */
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
#define CONNECTFREQ 282
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
#define INPUT_FLOOD 319
#define INVISIBLE_ON_CONNECT 320
#define INVITE_CLIENT_COUNT 321
#define INVITE_CLIENT_TIME 322
#define INVITE_DELAY_CHANNEL 323
#define INVITE_EXPIRE_TIME 324
#define IP 325
#define IRCD_AUTH 326
#define IRCD_FLAGS 327
#define IRCD_SID 328
#define JOIN 329
#define KILL 330
#define KILL_CHASE_TIME_LIMIT 331
#define KLINE 332
#define KLINE_EXEMPT 333
#define KLINE_MIN_CIDR 334
#define KLINE_MIN_CIDR6 335
#define KNOCK_CLIENT_COUNT 336
#define KNOCK_CLIENT_TIME 337
#define KNOCK_DELAY_CHANNEL 338
#define LEAF_MASK 339
#define LISTEN 340
#define LOADMODULE 341
#define MASK 342
#define MASS 343
#define MAX_ACCEPT 344
#define MAX_AWAY_LENGTH 345
#define MAX_BANS 346
#define MAX_BANS_LARGE 347
#define MAX_CHANNELS 348
#define MAX_IDLE 349
#define MAX_INVITES 350
#define MAX_KICK_LENGTH 351
#define MAX_MONITOR 352
#define MAX_NICK_CHANGES 353
#define MAX_NICK_LENGTH 354
#define MAX_NICK_TIME 355
#define MAX_NUMBER 356
#define MAX_TARGETS 357
#define MAX_TOPIC_LENGTH 358
#define MESSAGE 359
#define MIN_IDLE 360
#define MIN_NONWILDCARD 361
#define MIN_NONWILDCARD_SIMPLE 362
#define MODULE 363
#define MODULE_BASE_PATH 364
#define MOTD 365
#define MOTD_FILE 366
#define NAME 367
#define NEED_IDENT 368
#define NEED_PASSWORD 369
#define NETWORK_DESCRIPTION 370
#define NETWORK_NAME 371
#define NICK 372
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
  YYSYMBOL_CONNECTFREQ = 27,               /* CONNECTFREQ  */
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
  YYSYMBOL_INPUT_FLOOD = 64,               /* INPUT_FLOOD  */
  YYSYMBOL_INVISIBLE_ON_CONNECT = 65,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 66,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 67,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 68,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 69,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 70,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 71,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 72,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 73,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 74,                      /* JOIN  */
  YYSYMBOL_KILL = 75,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 76,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 77,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 78,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 79,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 80,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 81,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 82,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 83,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 84,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 85,                    /* LISTEN  */
  YYSYMBOL_LOADMODULE = 86,                /* LOADMODULE  */
  YYSYMBOL_MASK = 87,                      /* MASK  */
  YYSYMBOL_MASS = 88,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 89,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_AWAY_LENGTH = 90,           /* MAX_AWAY_LENGTH  */
  YYSYMBOL_MAX_BANS = 91,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 92,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 93,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 94,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 95,               /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 96,           /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 97,               /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 98,          /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 99,           /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 100,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 101,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 102,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 103,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 104,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 105,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 106,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 107,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 108,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 109,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 110,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 111,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 112,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 113,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 114,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 115,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 116,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 117,                     /* NICK  */
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
#define YYLAST   1278

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
    1101,  1105,  1109,  1113,  1117,  1121,  1125,  1129,  1133,  1144,
    1143,  1199,  1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,
    1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1217,
    1223,  1229,  1235,  1241,  1247,  1253,  1259,  1265,  1272,  1278,
    1284,  1290,  1299,  1309,  1308,  1314,  1314,  1315,  1319,  1330,
    1329,  1336,  1335,  1340,  1340,  1341,  1345,  1349,  1353,  1357,
    1363,  1363,  1364,  1364,  1364,  1364,  1364,  1366,  1366,  1368,
    1368,  1370,  1383,  1400,  1406,  1417,  1416,  1472,  1472,  1473,
    1474,  1475,  1476,  1477,  1478,  1479,  1481,  1487,  1493,  1499,
    1511,  1510,  1516,  1516,  1518,  1522,  1526,  1530,  1534,  1538,
    1542,  1546,  1550,  1556,  1572,  1571,  1586,  1586,  1587,  1587,
    1587,  1587,  1589,  1595,  1601,  1611,  1613,  1613,  1614,  1614,
    1616,  1633,  1632,  1655,  1655,  1656,  1656,  1656,  1656,  1658,
    1664,  1684,  1683,  1689,  1689,  1690,  1694,  1698,  1702,  1706,
    1710,  1714,  1718,  1722,  1726,  1737,  1736,  1755,  1755,  1756,
    1756,  1756,  1758,  1765,  1764,  1770,  1770,  1771,  1775,  1779,
    1783,  1787,  1791,  1795,  1799,  1803,  1807,  1818,  1817,  1871,
    1871,  1872,  1873,  1874,  1875,  1876,  1877,  1878,  1879,  1880,
    1881,  1882,  1883,  1884,  1885,  1886,  1888,  1894,  1900,  1906,
    1912,  1925,  1938,  1944,  1950,  1954,  1961,  1960,  1965,  1965,
    1966,  1970,  1976,  1987,  1993,  1999,  2010,  2009,  2034,  2034,
    2035,  2035,  2035,  2037,  2057,  2068,  2067,  2090,  2090,  2091,
    2091,  2091,  2093,  2099,  2109,  2111,  2111,  2112,  2112,  2114,
    2128,  2127,  2148,  2148,  2149,  2149,  2149,  2151,  2157,  2167,
    2169,  2169,  2170,  2171,  2172,  2173,  2174,  2175,  2176,  2177,
    2178,  2179,  2180,  2181,  2182,  2183,  2184,  2185,  2186,  2187,
    2188,  2189,  2190,  2191,  2192,  2193,  2194,  2195,  2196,  2197,
    2198,  2199,  2200,  2201,  2202,  2203,  2204,  2205,  2206,  2207,
    2208,  2209,  2210,  2213,  2218,  2223,  2228,  2233,  2238,  2243,
    2248,  2253,  2258,  2263,  2268,  2273,  2278,  2286,  2291,  2296,
    2301,  2306,  2311,  2316,  2321,  2326,  2331,  2336,  2341,  2346,
    2351,  2356,  2361,  2366,  2371,  2376,  2381,  2390,  2395,  2400,
    2405,  2410,  2418,  2427,  2429,  2429,  2430,  2431,  2432,  2433,
    2434,  2435,  2436,  2438,  2455,  2464,  2473,  2482,  2492,  2506,
    2508,  2508,  2509,  2510,  2511,  2512,  2513,  2514,  2515,  2516,
    2517,  2518,  2519,  2520,  2521,  2522,  2523,  2524,  2525,  2527,
    2532,  2537,  2542,  2547,  2552,  2557,  2562,  2567,  2572,  2577,
    2582,  2587,  2610,  2618,  2623,  2632,  2634,  2634,  2635,  2636,
    2637,  2638,  2639,  2640,  2641,  2642,  2643,  2645,  2651,  2662,
    2671,  2677,  2683,  2689,  2698
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
  "CLOAK", "CLOSE", "CONNECT", "CONNECTFREQ", "DEFAULT_FLOODCOUNT",
  "DEFAULT_FLOODTIME", "DEFAULT_JOIN_FLOOD_COUNT",
  "DEFAULT_JOIN_FLOOD_TIME", "DEFAULT_MAX_CLIENTS", "DEFER", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_DNS", "DISABLE_IDENT",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR",
  "DLINE_MIN_CIDR6", "EMAIL", "ENABLED", "ENCRYPTED", "EXCEED_LIMIT",
  "EXEMPT", "FLATTEN_LINKS", "FLATTEN_LINKS_DELAY", "FLATTEN_LINKS_FILE",
  "GECOS", "GENERAL", "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
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

#define YYPACT_NINF (-668)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -668,   581,  -668,  -190,  -204,  -202,  -668,  -192,  -668,  -668,
    -184,  -668,  -176,  -668,  -668,  -668,  -164,  -166,  -668,  -668,
    -668,  -168,  -157,  -668,  -148,  -668,  -147,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,   299,   646,  -145,   453,  -132,
    -125,     7,  -122,   326,  -117,  -114,  -111,  -668,  -156,  -164,
     -97,   -88,   -83,   731,   399,   -55,    35,   -47,    24,   -28,
    -161,   -19,   -17,    -7,    11,  -668,  -668,  -668,  -668,  -668,
      17,    46,    55,    66,    69,    75,    83,    89,    91,    93,
      98,   100,   103,   105,   106,   113,     2,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,   599,  -668,   120,   122,   128,   130,
     131,   134,     3,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
     499,   267,  -668,   140,    12,  -668,  -668,    79,  -668,   147,
     148,   151,   155,   156,   157,   163,   166,   168,   190,   192,
     195,   196,   203,   207,   209,   211,   212,   217,   219,   220,
     224,   226,   227,   230,   232,   237,   244,   245,   246,   248,
     251,   252,   257,   258,   259,   261,   265,   266,   270,    50,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,   284,    27,   488,  -105,    29,    62,    14,   281,   360,
    -668,   274,   275,   278,   283,   285,   287,   290,   294,   222,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,   179,
     295,   300,   305,   306,   307,   320,   321,   323,   324,   325,
     328,   180,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,   177,   188,   329,    21,  -668,  -668,
    -668,   272,   187,  -668,   332,    19,  -668,  -668,   102,  -668,
     184,   338,   339,   255,  -668,   336,   340,   362,   341,   340,
     340,   340,   342,   340,   340,   347,   348,   349,   350,   351,
     352,   353,  -668,   359,   358,   361,   366,  -668,   368,   369,
     370,   371,   373,   374,   375,   376,   384,   390,   394,    48,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,   363,   365,   385,   401,
     409,   410,   411,  -668,   413,   407,   416,   419,   421,   423,
     424,  -668,   425,   427,   428,   430,   431,   433,   435,   162,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,   436,   442,    38,  -668,
    -668,  -668,   447,   449,  -668,  -668,   445,   450,    20,  -668,
    -668,  -668,   478,   340,   458,   340,   340,   459,   340,   483,
     486,   464,   466,   340,   490,   340,   473,   474,   480,   482,
     484,   487,   340,   491,   492,   493,   469,   506,   340,   340,
     511,   340,   518,   501,   525,   526,   508,   340,   340,   340,
     532,   510,   515,  -668,   517,   522,   527,  -668,   529,   530,
     534,   182,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
     535,   537,    60,  -668,  -668,  -668,   520,   538,   540,  -668,
     541,  -668,    30,  -668,  -668,  -668,  -668,  -668,  -668,   523,
    -668,  -668,  -668,   528,   542,   544,    71,  -668,  -668,  -668,
     556,   555,   557,  -668,   559,   560,   564,   565,   568,   569,
     570,   186,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,   558,   573,   574,   575,   170,  -668,  -668,
    -668,  -668,   602,   603,   340,   512,   604,   536,   605,   606,
     583,  -668,  -668,   585,   587,   610,   589,   590,   592,   593,
     594,   595,   596,   597,   588,  -668,   598,   600,  -668,    39,
    -668,  -668,  -668,  -668,   621,   601,  -668,   591,   607,   608,
     609,   611,   612,    85,  -668,  -668,  -668,  -668,  -668,   614,
     615,  -668,   616,   618,  -668,   619,    15,  -668,  -668,  -668,
    -668,   617,   622,   623,  -668,   624,   620,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   639,  -668,  -668,   641,   642,   340,   640,   644,   340,
     645,   340,   647,   648,   649,   650,   340,   651,   651,   652,
    -668,   653,   654,   655,   656,   657,   658,  -668,  -668,   661,
    -128,   662,   670,   663,   664,   665,   666,   667,   669,   668,
     671,   340,   672,   673,  -668,   674,   676,   675,  -668,   677,
    -668,   678,   680,   679,  -668,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,  -668,  -668,   723,   746,   721,
     726,   727,   728,   729,  -668,   730,   732,   733,  -668,  -668,
     734,   736,   725,   737,   735,  -668,  -105,  -668,   739,   740,
     741,  -668,  -668,   742,   755,   743,   744,   745,   748,   749,
     763,   750,   751,   752,  -668,  -668,   753,   756,   757,   758,
    -668,   759,   760,   761,   762,   764,   765,   766,   767,  -668,
     768,   769,   770,   771,   772,   773,   774,   775,   776,   777,
     778,  -668,  -668,   781,   754,   780,  -668,   782,  -668,    13,
    -668,   783,   785,   786,   787,   788,  -668,   789,  -668,  -668,
     792,   784,   793,   794,  -668,  -668,  -668,  -668,  -668,   340,
     340,   340,   340,   340,   340,   340,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,   795,   796,   797,   -27,   798,   799,   800,
     801,   802,   803,   804,   805,   806,   104,   807,   808,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,   809,   810,   811,   812,
     813,   814,   815,    10,   816,   817,   818,   819,   820,   821,
     822,  -668,   823,   824,  -668,  -668,   825,   826,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,   827,
     828,   304,   829,   830,   831,  -668,   832,   833,  -668,   834,
     835,   337,   613,   659,  -668,  -668,  -668,   836,   837,  -668,
     838,   839,   432,   840,   841,   842,   843,   844,   845,   846,
    -668,   847,   848,   849,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,   850,   468,  -668,  -668,   851,   790,
     791,  -668,    80,  -668,  -668,  -668,  -668,   852,   853,   854,
     855,  -668,  -668,   856,   497,   857,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -172,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
     651,   651,   651,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -158,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
     -61,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,   -30,  -668,   859,   737,   860,  -668,
    -668,  -668,  -668,  -668,   747,  -668,   858,  -668,   861,   862,
    -668,   863,  -668,   864,   865,  -668,  -668,   866,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,   -18,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,    32,  -668,  -668,   872,  -177,   869,   873,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,    70,  -668,  -668,  -668,   -27,
    -668,  -668,  -668,  -668,    10,  -668,   304,  -668,   337,  -668,
    -668,  -668,   896,   938,   937,   942,   779,   947,   953,   954,
    -668,   432,  -668,   468,   876,   877,   878,   253,  -668,  -668,
     497,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,   879,  -668,  -668
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   199,     0,   357,   405,
       0,   420,     0,   265,   396,   239,     0,     0,    91,   141,
     294,     0,     0,   335,     0,   100,     0,   311,     3,     4,
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
     117,     0,     0,   309,     0,     0,   307,   308,     0,    87,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   530,     0,     0,     0,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     202,   203,   206,   208,   209,   210,   211,   212,   213,   214,
     204,   205,   207,   215,   216,   217,     0,     0,     0,     0,
       0,     0,     0,   514,     0,     0,     0,     0,     0,     0,
       0,   386,     0,     0,     0,     0,     0,     0,     0,     0,
     360,   361,   362,   363,   364,   365,   366,   367,   369,   368,
     370,   374,   371,   372,   373,   411,     0,     0,     0,   408,
     409,   410,     0,     0,   415,   426,     0,     0,     0,   423,
     424,   425,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   430,     0,     0,     0,   280,     0,     0,
       0,     0,   268,   269,   270,   271,   274,   272,   273,   402,
       0,     0,     0,   399,   400,   401,     0,     0,     0,   241,
       0,   253,     0,   251,   252,   254,   255,    54,    53,    50,
      52,    47,    46,     0,     0,     0,     0,    94,    95,    96,
       0,     0,     0,   165,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   145,   146,   147,   148,   151,   152,   153,
     150,   149,   154,     0,     0,     0,     0,     0,   297,   298,
     299,   300,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   566,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,   343,     0,
     338,   339,   340,   118,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,   103,   104,   106,   105,   107,     0,
       0,   306,     0,     0,   321,     0,     0,   314,   315,   316,
     317,     0,     0,     0,    81,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   529,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,     0,     0,     0,     0,     0,     0,   513,   375,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,     0,     0,     0,   407,     0,
     414,     0,     0,     0,   422,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   429,   275,     0,     0,     0,
       0,     0,     0,     0,   267,     0,     0,     0,   398,   256,
       0,     0,     0,     0,     0,   250,     0,    97,     0,     0,
       0,    93,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   301,     0,     0,     0,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,   565,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,   341,     0,     0,     0,   337,     0,   113,     0,
     108,     0,     0,     0,     0,     0,   102,     0,   305,   318,
       0,     0,     0,     0,   313,    90,    89,    88,   563,    30,
      30,    30,    30,    30,    30,    30,    32,    31,   564,   549,
     550,   551,   552,   553,   554,   555,   556,   559,   560,   557,
     558,   561,   562,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,     0,     0,   200,
     524,   525,   523,   526,   527,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   358,     0,     0,   406,   419,     0,     0,   421,   482,
     487,   473,   474,   495,   509,   510,   503,   502,   477,   478,
     511,   490,   481,   479,   480,   485,   486,   475,   484,   483,
     500,   507,   508,   506,   496,   494,   497,   501,   512,   498,
     499,   492,   493,   504,   505,   489,   488,   491,   476,     0,
       0,     0,     0,     0,     0,   266,     0,     0,   397,     0,
       0,     0,   261,   257,   260,   240,    51,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,     0,     0,     0,   295,   580,   577,   578,   579,   584,
     583,   581,   582,    77,    74,    80,    73,    78,    79,    72,
      76,    75,    70,    71,     0,     0,   336,   119,     0,     0,
       0,   131,     0,   123,   124,   126,   125,     0,     0,     0,
       0,   101,   310,     0,     0,     0,   312,    33,    34,    35,
      36,    37,    38,    39,   228,   229,   223,   238,   237,     0,
     236,   224,   232,   225,   231,   219,   230,   222,   221,   220,
      40,    40,    40,    42,    41,   226,   227,   381,   384,   385,
     395,   392,   377,   393,   390,   391,     0,   389,   394,   376,
     383,   380,   379,   378,   382,   412,   413,   427,   428,   278,
     279,   288,   284,   285,   287,   292,   289,   290,   291,   286,
       0,   283,   277,   293,   276,   404,   403,   264,   263,   248,
     249,   246,   247,   245,     0,   244,     0,     0,     0,    98,
      99,   163,   160,   185,     0,   196,   172,   181,     0,   170,
     175,     0,   190,     0,   184,   188,   194,   174,   177,   186,
     187,   191,   182,   189,   178,   195,   180,   176,   179,     0,
     168,   156,   158,   164,   161,   162,   157,   159,   304,   302,
     303,   342,   347,   353,   356,   349,   355,   350,   354,   352,
     348,   351,     0,   346,   127,     0,     0,     0,     0,   122,
     110,   109,   111,   112,   319,   325,   331,   334,   327,   333,
     328,   332,   330,   326,   329,     0,   324,   320,   234,     0,
      43,    44,    45,   387,     0,   281,     0,   242,     0,   262,
     259,   258,     0,     0,     0,     0,     0,     0,     0,     0,
     166,     0,   344,     0,     0,     0,     0,     0,   121,   322,
       0,   235,   388,   282,   243,   198,   171,   193,   169,   197,
     192,   183,   173,   167,   345,   128,   130,   129,   139,   138,
     134,   136,   140,   137,   133,   135,     0,   323,   132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -668,  -668,  -668,  -271,  -304,  -667,  -627,  -668,  -668,   900,
    -668,  -668,    90,  -668,  -668,   548,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,   738,
    -668,  -668,  -668,  -668,  -668,  -668,   391,  -668,  -668,  -668,
    -668,  -668,   247,  -668,  -668,  -668,  -668,  -668,  -668,   547,
    -668,  -668,  -668,  -668,  -151,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,   313,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -346,  -668,  -668,  -668,
     867,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -253,  -668,
    -668,  -668,  -668,  -668,  -185,  -668,   521,  -668,  -668,  -668,
      31,  -668,  -668,  -668,  -668,  -668,   643,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,   -60,  -668,  -668,  -668,  -668,   452,
    -668,  -668,  -668,  -668,  -668,   868,  -668,  -668,  -668,  -668,
     513,  -668,  -668,  -668,  -668,  -668,   -80,  -668,  -668,  -668,
     543,  -668,  -668,  -668,  -668,   -76,  -668,  -668,  -668,   722,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,   -51,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
     660,  -668,  -668,  -668,  -668,  -668,   724,  -668,  -668,  -668,
    -668,   961,  -668,  -668,  -668,  -668,   870,  -668,  -668,  -668,
    -668,   917,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,   975,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  1002,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668,  -668,   871,  -668,  -668,  -668,  -668,  -668,  -668,  -668,
    -668
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    28,   806,   807,  1013,  1014,    29,    30,    68,
     235,   489,   490,    31,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,    32,    84,    85,
      86,    87,    88,    33,    70,   496,   497,   498,   499,    34,
      77,   573,   574,   575,   576,   577,   578,    35,   287,   288,
     289,   290,   291,   972,   973,   974,   975,   976,  1127,  1206,
      36,    71,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   735,  1099,  1100,    37,    57,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   617,   999,  1000,    38,
      66,   481,   722,  1064,  1065,   482,   483,   484,  1068,   923,
     924,   485,   486,    39,    64,   461,   462,   463,   464,   465,
     466,   467,   709,  1050,  1051,   468,    40,    72,   527,   528,
     529,   530,   531,    41,   295,   296,   297,    42,    79,   586,
     587,   588,   589,   590,   791,  1145,  1146,    43,    75,   559,
     560,   561,   562,   774,  1122,  1123,    44,    59,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     645,  1026,  1027,   391,   392,   393,   394,    45,    65,   472,
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
     837,   838,   597,    89,   125,   600,   601,   602,   142,   604,
     605,  1175,    80,   142,   968,   493,   582,    55,  1024,    56,
     293,   405,   285,   126,   127,   293,    53,    54,   469,    58,
     997,   476,    90,    91,   487,   488,   285,    61,   836,   395,
     556,    92,   847,   848,  1148,    63,    81,   128,  1149,   323,
      67,   148,    69,    73,    82,   299,   149,   150,  1153,   151,
     152,   469,  1154,   234,    74,   153,   324,   325,    93,    94,
      95,    96,   493,    76,    78,   326,   124,   143,   154,   155,
     405,   968,   143,    97,    98,    99,   568,   156,   157,   140,
     477,   158,   159,   100,   101,   102,   141,   103,   104,   147,
     478,   494,   479,   582,   231,   105,   998,   232,   396,   666,
     233,   668,   669,   160,   671,   161,  1010,  1011,  1012,   676,
     327,   678,   129,    83,   237,   969,   162,   583,   685,   163,
     164,   294,   406,   238,   691,   692,   294,   694,   239,   165,
     166,   328,   329,   700,   701,   702,   130,   167,   168,   330,
     169,   557,   170,   331,   407,  1155,   171,   172,   494,  1156,
     332,   470,   480,   364,   131,   365,   284,   366,   333,   334,
     335,   523,   397,   173,   292,   174,   175,   176,   556,   336,
     177,   259,   495,   454,   367,   178,  1157,   500,   568,  -120,
    1158,   406,   969,   298,   470,  1025,   970,   569,  1170,   300,
     337,   301,  1171,  -120,   455,   179,   180,   368,   501,   181,
     182,   302,   260,   407,   583,   261,   971,   524,   584,   321,
     362,   585,   369,   240,   370,   338,   286,   456,   303,   403,
     753,   502,   793,   471,   371,   305,   580,   663,   565,   495,
     286,   262,   558,   183,   184,   491,   372,   724,  1172,   570,
     185,   186,  1173,   263,   457,   657,   775,   525,   503,   187,
     571,   188,   241,   970,   306,   629,   471,   452,   395,   572,
     242,   243,   244,   307,   373,   245,   246,   717,   492,   264,
     247,   248,   500,   971,   308,   454,  1179,   309,   730,   557,
    1180,   265,   266,   310,   374,   267,   268,  1128,   504,   569,
      80,   311,   785,   501,   526,   584,   455,   312,   585,   313,
     458,   314,   825,   375,   505,   828,   315,   830,   316,   836,
    1041,   317,   835,   318,   319,   376,   502,   148,  1198,   456,
    1199,   320,   149,   150,    81,   151,   152,   396,   356,   459,
     357,   153,    82,  1150,  1151,  1152,   358,   859,   359,   360,
    1042,   570,   361,   503,   154,   155,   457,   377,   402,   378,
    1059,   523,   571,   156,   157,   412,   413,   158,   159,   414,
    1060,   572,   506,   415,   416,   417,   269,  1200,   270,   653,
     558,   418,  1043,   507,   419,   508,   420,   749,   460,   160,
    1061,   161,   509,   504,  1201,   542,   510,   554,   591,   713,
     259,   397,   162,   743,   563,   163,   164,   524,   421,   505,
     422,    83,   458,   423,   424,   165,   166,  1044,  1045,  1202,
    1203,   425,  1046,   167,   168,   426,   169,   427,   170,   428,
     429,   260,   171,   172,   261,   430,  1073,   431,   432,   540,
     567,   459,   433,  1074,   434,   435,  1047,   525,   436,   173,
     437,   174,   175,   176,   125,   438,   177,  1075,  1076,  1204,
     262,   178,   439,   440,   441,  1205,   442,   506,  1077,   443,
     444,   594,   263,   126,   127,   445,   446,   447,   507,   448,
     508,   179,   180,   449,   450,   181,   182,   509,   451,   476,
     460,   510,   532,   533,   526,  1048,   534,   128,   264,  1176,
     364,   535,   365,   536,   366,   537,  1078,  1079,   538,  1080,
     265,   266,   539,   543,   267,   268,  1062,  1049,   544,   183,
     184,   367,  1063,   545,   546,   547,   185,   186,   987,   988,
     989,   990,   991,   992,   993,   187,  1081,   188,   548,   549,
    1082,   550,   551,   552,   368,  1112,   553,   564,   477,  1083,
     579,   595,   592,   593,   598,   596,   599,   603,   478,   369,
     479,   370,   606,   607,   608,   609,   610,   611,  1084,   612,
    1085,   371,   129,  1086,  1135,   613,   614,   633,   631,   615,
     632,     2,     3,   372,   616,     4,   618,   619,   620,   621,
    1087,   622,   623,   624,   625,   269,   130,   270,     5,  1088,
     323,  1089,   626,     6,  1090,     7,  1091,     8,   627,  1113,
    1092,   373,   628,  1093,   131,     9,   634,   324,   325,  1094,
     480,  1095,  1096,   635,   636,   639,   326,   637,    10,   638,
    1114,   374,    11,    12,   640,  1115,  1097,   641,  1136,   642,
    1116,   643,   644,   646,  1098,   647,   648,    89,   649,   650,
     375,   651,    13,   652,   655,  1117,    14,  1118,  1119,  1137,
     656,   659,   376,   661,  1138,   660,    15,    16,   662,  1139,
     665,   327,  1120,   667,   670,   672,    90,    91,   673,   674,
    1121,   675,   677,   689,  1140,    92,  1141,  1142,   679,   680,
      17,    18,   328,   329,   377,   681,   378,   682,   690,   683,
     330,  1143,   684,   693,   331,    19,   686,   687,   688,  1144,
     695,   332,    93,    94,    95,    96,   696,   697,   698,   333,
     334,   335,    20,   699,   703,   704,   754,    97,    98,    99,
     336,   705,   240,   706,    21,    22,   719,   100,   101,   102,
     707,   103,   104,   726,   727,   708,    23,   710,   711,   105,
     756,   337,   712,   715,    24,   716,   720,    25,   721,   723,
     728,    26,   729,    27,   799,   800,   801,   802,   803,   804,
     805,   241,   732,   733,   745,   734,   338,   736,   737,   242,
     243,   244,   738,   739,   245,   246,   740,   741,   742,   247,
     248,   746,   747,   748,   751,   752,   755,   757,   758,   759,
     760,   761,   762,   763,   771,   764,   765,   766,   767,   768,
     769,   770,   779,   777,   772,  1066,   926,   778,   773,   555,
     786,  1129,   304,   780,   744,  1193,   781,   782,   787,   783,
     784,   788,   789,   795,   566,   596,   790,   792,   796,   797,
     798,   808,   809,   810,   811,   812,   813,   814,   815,   816,
     817,   818,   819,   820,   821,   822,   823,   824,   826,   827,
     829,   831,   850,   832,   833,   834,   836,  1189,   839,   840,
     841,   842,   843,   844,   845,   846,   849,   851,   852,  1067,
     854,   855,   857,   853,   856,   858,   860,   731,   862,   861,
     863,   864,   866,   865,   867,   868,  1181,   869,   870,   871,
     872,   873,   874,   875,   876,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   886,   887,   888,   889,   890,   891,
     892,   893,   894,   895,   896,   897,   898,   899,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
     912,   913,   914,   921,   916,   915,   917,   931,   919,   918,
     920,   925,   922,   927,   928,   937,   930,   929,   933,   934,
    1185,   932,   935,   936,   938,   939,  1162,   941,   940,   236,
     942,   943,   965,  1184,   944,   945,   946,   947,   948,   750,
     949,   950,   951,   952,   953,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   963,   964,   966,   977,   967,   978,
     979,   980,   984,   725,   981,   982,   983,   985,  1125,  1126,
     986,   994,   995,   996,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1052,  1053,  1054,  1055,  1056,
    1057,  1058,  1069,  1070,  1071,  1072,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1124,  1130,  1131,
    1132,  1133,  1134,  1147,  1159,  1186,  1161,  1163,  1187,  1188,
    1164,  1165,  1166,  1167,  1168,  1169,  1174,  1177,  1190,  1178,
    1191,  1192,  1195,  1196,  1197,  1208,  1183,  1194,  1160,   794,
    1207,   654,   776,  1182,   714,   404,   453,   363,   322,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     541,     0,   658,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   718,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   581,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   664
};

static const yytype_int16 yycheck[] =
{
     627,   628,   306,     1,     1,   309,   310,   311,     1,   313,
     314,   188,     1,     1,     1,     1,     1,   221,     8,   221,
       1,     1,     1,    20,    21,     1,   216,   217,     1,   221,
      57,     1,    30,    31,   139,   140,     1,   221,   215,     1,
       1,    39,   170,   171,   216,   221,    35,    44,   220,     1,
     214,     1,   218,   221,    43,   216,     6,     7,   216,     9,
      10,     1,   220,   219,   221,    15,    18,    19,    66,    67,
      68,    69,     1,   221,   221,    27,   221,    70,    28,    29,
       1,     1,    70,    81,    82,    83,     1,    37,    38,   221,
      60,    41,    42,    91,    92,    93,   221,    95,    96,   221,
      70,    87,    72,     1,   221,   103,   133,   221,    70,   413,
     221,   415,   416,    63,   418,    65,    12,    13,    14,   423,
      72,   425,   119,   112,   221,   112,    76,   112,   432,    79,
      80,   112,   112,   221,   438,   439,   112,   441,   221,    89,
      90,    93,    94,   447,   448,   449,   143,    97,    98,   101,
     100,   112,   102,   105,   134,   216,   106,   107,    87,   220,
     112,   134,   132,     1,   161,     3,   221,     5,   120,   121,
     122,     1,   134,   123,   221,   125,   126,   127,     1,   131,
     130,     1,   168,     1,    22,   135,   216,     1,     1,   168,
     220,   112,   112,   221,   134,   185,   183,   112,   216,   218,
     152,   218,   220,   168,    22,   155,   156,    45,    22,   159,
     160,   218,    32,   134,   112,    35,   203,    47,   203,   217,
     217,   206,    60,     1,    62,   177,   205,    45,   217,   217,
     534,    45,   217,   206,    72,   218,   217,   217,   217,   168,
     205,    61,   203,   193,   194,   216,    84,   217,   216,   164,
     200,   201,   220,    73,    72,   217,   217,    87,    72,   209,
     175,   211,    40,   183,   218,   217,   206,   217,     1,   184,
      48,    49,    50,   218,   112,    53,    54,   217,   216,    99,
      58,    59,     1,   203,   218,     1,   216,   218,   217,   112,
     220,   111,   112,   218,   132,   115,   116,   217,   112,   112,
       1,   218,   217,    22,   134,   203,    22,   218,   206,   218,
     128,   218,   616,   151,   128,   619,   218,   621,   218,   215,
      16,   218,   626,   218,   218,   163,    45,     1,    75,    45,
      77,   218,     6,     7,    35,     9,    10,    70,   218,   157,
     218,    15,    43,  1010,  1011,  1012,   218,   651,   218,   218,
      46,   164,   218,    72,    28,    29,    72,   195,   218,   197,
      23,     1,   175,    37,    38,   218,   218,    41,    42,   218,
      33,   184,   186,   218,   218,   218,   196,   124,   198,   217,
     203,   218,    78,   197,   218,   199,   218,   217,   206,    63,
      53,    65,   206,   112,   141,   216,   210,   217,   214,   217,
       1,   134,    76,   217,   216,    79,    80,    47,   218,   128,
     218,   112,   128,   218,   218,    89,    90,   113,   114,   166,
     167,   218,   118,    97,    98,   218,   100,   218,   102,   218,
     218,    32,   106,   107,    35,   218,     4,   218,   218,   217,
     168,   157,   218,    11,   218,   218,   142,    87,   218,   123,
     218,   125,   126,   127,     1,   218,   130,    25,    26,   206,
      61,   135,   218,   218,   218,   212,   218,   186,    36,   218,
     218,   216,    73,    20,    21,   218,   218,   218,   197,   218,
     199,   155,   156,   218,   218,   159,   160,   206,   218,     1,
     206,   210,   218,   218,   134,   191,   218,    44,    99,  1126,
       1,   218,     3,   218,     5,   218,    74,    75,   218,    77,
     111,   112,   218,   218,   115,   116,   179,   213,   218,   193,
     194,    22,   185,   218,   218,   218,   200,   201,   799,   800,
     801,   802,   803,   804,   805,   209,   104,   211,   218,   218,
     108,   218,   218,   218,    45,    77,   218,   218,    60,   117,
     218,   215,   214,   214,   192,   215,   215,   215,    70,    60,
      72,    62,   215,   215,   215,   215,   215,   215,   136,   216,
     138,    72,   119,   141,    77,   216,   218,   192,   215,   218,
     215,     0,     1,    84,   218,     4,   218,   218,   218,   218,
     158,   218,   218,   218,   218,   196,   143,   198,    17,   167,
       1,   169,   218,    22,   172,    24,   174,    26,   218,   141,
     178,   112,   218,   181,   161,    34,   215,    18,    19,   187,
     132,   189,   190,   214,   214,   218,    27,   216,    47,   216,
     162,   132,    51,    52,   218,   167,   204,   218,   141,   218,
     172,   218,   218,   218,   212,   218,   218,     1,   218,   218,
     151,   218,    71,   218,   218,   187,    75,   189,   190,   162,
     218,   214,   163,   218,   167,   216,    85,    86,   218,   172,
     192,    72,   204,   215,   215,   192,    30,    31,   192,   215,
     212,   215,   192,   214,   187,    39,   189,   190,   215,   215,
     109,   110,    93,    94,   195,   215,   197,   215,   192,   215,
     101,   204,   215,   192,   105,   124,   215,   215,   215,   212,
     192,   112,    66,    67,    68,    69,   215,   192,   192,   120,
     121,   122,   141,   215,   192,   215,   214,    81,    82,    83,
     131,   216,     1,   216,   153,   154,   216,    91,    92,    93,
     218,    95,    96,   220,   216,   218,   165,   218,   218,   103,
     214,   152,   218,   218,   173,   218,   218,   176,   218,   218,
     218,   180,   218,   182,   144,   145,   146,   147,   148,   149,
     150,    40,   216,   218,   216,   218,   177,   218,   218,    48,
      49,    50,   218,   218,    53,    54,   218,   218,   218,    58,
      59,   218,   218,   218,   192,   192,   192,   192,   192,   216,
     215,   214,   192,   214,   216,   215,   214,   214,   214,   214,
     214,   214,   221,   192,   216,   202,   726,   216,   218,   271,
     573,   972,    84,   216,   511,  1171,   218,   218,   214,   218,
     218,   216,   216,   216,   287,   215,   218,   218,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   215,   215,   218,   215,
     215,   214,   192,   215,   215,   215,   215,    88,   216,   216,
     216,   216,   216,   216,   216,   214,   214,   214,   214,   220,
     214,   214,   214,   218,   215,   214,   214,   496,   214,   216,
     214,   216,   214,   216,   214,   216,  1149,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   214,   192,   218,
     214,   214,   214,   218,   214,   216,   214,   192,   214,   216,
     214,   216,   215,   214,   214,   192,   214,   216,   214,   214,
      64,   218,   214,   214,   214,   214,   219,   214,   216,    69,
     214,   214,   218,  1158,   216,   216,   216,   216,   216,   527,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   214,   216,   214,   216,   214,
     214,   214,   218,   482,   216,   216,   214,   214,   218,   218,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   215,   137,   216,   219,   141,   137,
     219,   219,   219,   219,   219,   219,   214,   218,   141,   216,
     137,   137,   216,   216,   216,   216,  1156,  1173,  1067,   586,
    1180,   379,   559,  1154,   461,   144,   189,   132,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,    -1,   398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   223,     0,     1,     4,    17,    22,    24,    26,    34,
      47,    51,    52,    71,    75,    85,    86,   109,   110,   124,
     141,   153,   154,   165,   173,   176,   180,   182,   224,   229,
     230,   235,   249,   255,   261,   269,   282,   299,   321,   335,
     348,   355,   359,   369,   378,   399,   405,   411,   415,   421,
     464,   473,   492,   216,   217,   221,   221,   300,   221,   379,
     406,   221,   416,   221,   336,   400,   322,   214,   231,   218,
     256,   283,   349,   221,   221,   370,   221,   262,   221,   360,
       1,    35,    43,   112,   250,   251,   252,   253,   254,     1,
      30,    31,    39,    66,    67,    68,    69,    81,    82,    83,
      91,    92,    93,    95,    96,   103,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   221,     1,    20,    21,    44,   119,
     143,   161,   465,   466,   467,   468,   469,   470,   471,   472,
     221,   221,     1,    70,   412,   413,   414,   221,     1,     6,
       7,     9,    10,    15,    28,    29,    37,    38,    41,    42,
      63,    65,    76,    79,    80,    89,    90,    97,    98,   100,
     102,   106,   107,   123,   125,   126,   127,   130,   135,   155,
     156,   159,   160,   193,   194,   200,   201,   209,   211,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   221,   221,   221,   219,   232,   231,   221,   221,   221,
       1,    40,    48,    49,    50,    53,    54,    58,    59,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     1,
      32,    35,    61,    73,    99,   111,   112,   115,   116,   196,
     198,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   221,     1,   205,   270,   271,   272,
     273,   274,   221,     1,   112,   356,   357,   358,   221,   216,
     218,   218,   218,   217,   251,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   217,   475,     1,    18,    19,    27,    72,    93,    94,
     101,   105,   112,   120,   121,   122,   131,   152,   177,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   218,   218,   218,   218,
     218,   218,   217,   466,     1,     3,     5,    22,    45,    60,
      62,    72,    84,   112,   132,   151,   163,   195,   197,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   395,   396,   397,   398,     1,    70,   134,   407,   408,
     409,   410,   218,   217,   413,     1,   112,   134,   417,   418,
     419,   420,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   217,   423,     1,    22,    45,    72,   128,   157,
     206,   337,   338,   339,   340,   341,   342,   343,   347,     1,
     134,   206,   401,   402,   403,   404,     1,    60,    70,    72,
     132,   323,   327,   328,   329,   333,   334,   139,   140,   233,
     234,   216,   216,     1,    87,   168,   257,   258,   259,   260,
       1,    22,    45,    72,   112,   128,   186,   197,   199,   206,
     210,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,     1,    47,    87,   134,   350,   351,   352,
     353,   354,   218,   218,   218,   218,   218,   218,   218,   218,
     217,   494,   216,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   217,   237,     1,   112,   203,   371,
     372,   373,   374,   216,   218,   217,   271,   168,     1,   112,
     164,   175,   184,   263,   264,   265,   266,   267,   268,   218,
     217,   357,     1,   112,   203,   206,   361,   362,   363,   364,
     365,   214,   214,   214,   216,   215,   215,   226,   192,   215,
     226,   226,   226,   215,   226,   226,   215,   215,   215,   215,
     215,   215,   216,   216,   218,   218,   218,   318,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   217,
     302,   215,   215,   192,   215,   214,   214,   216,   216,   218,
     218,   218,   218,   218,   218,   392,   218,   218,   218,   218,
     218,   218,   218,   217,   381,   218,   218,   217,   408,   214,
     216,   218,   218,   217,   418,   192,   226,   215,   226,   226,
     215,   226,   192,   192,   215,   215,   226,   192,   226,   215,
     215,   215,   215,   215,   215,   226,   215,   215,   215,   214,
     192,   226,   226,   192,   226,   192,   215,   192,   192,   215,
     226,   226,   226,   192,   215,   216,   216,   218,   218,   344,
     218,   218,   218,   217,   338,   218,   218,   217,   402,   216,
     218,   218,   324,   218,   217,   328,   220,   216,   218,   218,
     217,   258,   216,   218,   218,   296,   218,   218,   218,   218,
     218,   218,   218,   217,   285,   216,   218,   218,   218,   217,
     351,   192,   192,   226,   214,   192,   214,   192,   192,   216,
     215,   214,   192,   214,   215,   214,   214,   214,   214,   214,
     214,   216,   216,   218,   375,   217,   372,   192,   216,   221,
     216,   218,   218,   218,   218,   217,   264,   214,   216,   216,
     218,   366,   218,   217,   362,   216,   216,   216,   216,   144,
     145,   146,   147,   148,   149,   150,   225,   226,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   215,   215,   226,   218,   215,   226,   215,
     226,   214,   215,   215,   215,   226,   215,   228,   228,   216,
     216,   216,   216,   216,   216,   216,   214,   170,   171,   214,
     192,   214,   214,   218,   214,   214,   215,   214,   214,   226,
     214,   216,   214,   214,   216,   216,   214,   214,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   214,
     192,   218,   214,   214,   214,   216,   214,   214,   216,   214,
     214,   218,   215,   331,   332,   216,   234,   214,   214,   216,
     214,   192,   218,   214,   214,   214,   214,   192,   214,   214,
     216,   214,   214,   214,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   214,   218,   216,   216,     1,   112,
     183,   203,   275,   276,   277,   278,   279,   214,   214,   214,
     214,   216,   216,   214,   218,   214,   216,   225,   225,   225,
     225,   225,   225,   225,   216,   216,   216,    57,   133,   319,
     320,   216,   216,   216,   216,   216,   216,   216,   216,   216,
      12,    13,    14,   227,   228,   216,   216,   216,   216,   216,
     216,   216,   216,   216,     8,   185,   393,   394,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,    16,    46,    78,   113,   114,   118,   142,   191,   213,
     345,   346,   216,   216,   216,   216,   216,   216,   216,    23,
      33,    53,   179,   185,   325,   326,   202,   220,   330,   216,
     216,   216,   216,     4,    11,    25,    26,    36,    74,    75,
      77,   104,   108,   117,   136,   138,   141,   158,   167,   169,
     172,   174,   178,   181,   187,   189,   190,   204,   212,   297,
     298,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,    77,   141,   162,   167,   172,   187,   189,   190,
     204,   212,   376,   377,   216,   218,   218,   280,   217,   276,
     216,   216,   216,   216,   216,    77,   141,   162,   167,   172,
     187,   189,   190,   204,   212,   367,   368,   216,   216,   220,
     227,   227,   227,   216,   220,   216,   220,   216,   220,   215,
     332,   216,   219,   219,   219,   219,   219,   219,   219,   219,
     216,   220,   216,   220,   214,   188,   228,   218,   216,   216,
     220,   320,   394,   346,   326,    64,   137,   141,   137,    88,
     141,   137,   137,   298,   377,   216,   216,   216,    75,    77,
     124,   141,   166,   167,   206,   212,   281,   368,   216
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
#line 350 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3151 "conf_parser.c"
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
#line 3424 "conf_parser.c"
    break;

  case 32: /* timespec: NUMBER timespec_  */
#line 387 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3430 "conf_parser.c"
    break;

  case 33: /* timespec: NUMBER SECONDS timespec_  */
#line 388 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3436 "conf_parser.c"
    break;

  case 34: /* timespec: NUMBER MINUTES timespec_  */
#line 389 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 3442 "conf_parser.c"
    break;

  case 35: /* timespec: NUMBER HOURS timespec_  */
#line 390 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 3448 "conf_parser.c"
    break;

  case 36: /* timespec: NUMBER DAYS timespec_  */
#line 391 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 3454 "conf_parser.c"
    break;

  case 37: /* timespec: NUMBER WEEKS timespec_  */
#line 392 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 3460 "conf_parser.c"
    break;

  case 38: /* timespec: NUMBER MONTHS timespec_  */
#line 393 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 3466 "conf_parser.c"
    break;

  case 39: /* timespec: NUMBER YEARS timespec_  */
#line 394 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 3472 "conf_parser.c"
    break;

  case 40: /* sizespec_: %empty  */
#line 397 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3478 "conf_parser.c"
    break;

  case 42: /* sizespec: NUMBER sizespec_  */
#line 398 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3484 "conf_parser.c"
    break;

  case 43: /* sizespec: NUMBER BYTES sizespec_  */
#line 399 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3490 "conf_parser.c"
    break;

  case 44: /* sizespec: NUMBER KBYTES sizespec_  */
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3496 "conf_parser.c"
    break;

  case 45: /* sizespec: NUMBER MBYTES sizespec_  */
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3502 "conf_parser.c"
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
#line 3519 "conf_parser.c"
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
#line 3536 "conf_parser.c"
    break;

  case 48: /* module_string: QSTRING  */
#line 442 "conf_parser.y"
{
  (yyval.string) = io_strdup((yyvsp[0].string));
}
#line 3544 "conf_parser.c"
    break;

  case 49: /* module_attributes: %empty  */
#line 447 "conf_parser.y"
{
  (yyval.number) = 0;
}
#line 3552 "conf_parser.c"
    break;

  case 50: /* module_attributes: ':' module_attributes_items  */
#line 450 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3560 "conf_parser.c"
    break;

  case 51: /* module_attributes_items: module_attributes_items ',' module_attributes_item  */
#line 455 "conf_parser.y"
{
  (yyval.number) = (yyvsp[-2].number) | (yyvsp[0].number);
}
#line 3568 "conf_parser.c"
    break;

  case 52: /* module_attributes_items: module_attributes_item  */
#line 458 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3576 "conf_parser.c"
    break;

  case 53: /* module_attributes_item: RESIDENT  */
#line 463 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_DEACTIVATE;
}
#line 3584 "conf_parser.c"
    break;

  case 54: /* module_attributes_item: REQUIRED  */
#line 466 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_REMOVE;
}
#line 3592 "conf_parser.c"
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
#line 3604 "conf_parser.c"
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
#line 3616 "conf_parser.c"
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
#line 3634 "conf_parser.c"
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
#line 3652 "conf_parser.c"
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
#line 3665 "conf_parser.c"
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
#line 3682 "conf_parser.c"
    break;

  case 76: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 564 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3694 "conf_parser.c"
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
#line 3720 "conf_parser.c"
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
#line 3746 "conf_parser.c"
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
#line 3758 "conf_parser.c"
    break;

  case 80: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 628 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3767 "conf_parser.c"
    break;

  case 88: /* admin_name: NAME '=' QSTRING ';'  */
#line 646 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3779 "conf_parser.c"
    break;

  case 89: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 655 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3791 "conf_parser.c"
    break;

  case 90: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 664 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3803 "conf_parser.c"
    break;

  case 91: /* $@1: %empty  */
#line 677 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3812 "conf_parser.c"
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
#line 3829 "conf_parser.c"
    break;

  case 98: /* motd_mask: MASK '=' QSTRING ';'  */
#line 698 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3838 "conf_parser.c"
    break;

  case 99: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 704 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3847 "conf_parser.c"
    break;

  case 100: /* $@2: %empty  */
#line 714 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3856 "conf_parser.c"
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
#line 3874 "conf_parser.c"
    break;

  case 109: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 736 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3883 "conf_parser.c"
    break;

  case 110: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 742 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3892 "conf_parser.c"
    break;

  case 111: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 748 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3901 "conf_parser.c"
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
#line 3923 "conf_parser.c"
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
#line 3935 "conf_parser.c"
    break;

  case 120: /* $@3: %empty  */
#line 792 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3944 "conf_parser.c"
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
#line 3957 "conf_parser.c"
    break;

  case 128: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 812 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3968 "conf_parser.c"
    break;

  case 129: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 820 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3976 "conf_parser.c"
    break;

  case 130: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 823 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3984 "conf_parser.c"
    break;

  case 131: /* $@4: %empty  */
#line 828 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3993 "conf_parser.c"
    break;

  case 133: /* logging_file_type_item: USER  */
#line 834 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4002 "conf_parser.c"
    break;

  case 134: /* logging_file_type_item: OPERATOR  */
#line 838 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4011 "conf_parser.c"
    break;

  case 135: /* logging_file_type_item: XLINE  */
#line 842 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4020 "conf_parser.c"
    break;

  case 136: /* logging_file_type_item: RESV  */
#line 846 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4029 "conf_parser.c"
    break;

  case 137: /* logging_file_type_item: T_DLINE  */
#line 850 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4038 "conf_parser.c"
    break;

  case 138: /* logging_file_type_item: KLINE  */
#line 854 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4047 "conf_parser.c"
    break;

  case 139: /* logging_file_type_item: KILL  */
#line 858 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4056 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: T_DEBUG  */
#line 862 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4065 "conf_parser.c"
    break;

  case 141: /* $@5: %empty  */
#line 872 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4077 "conf_parser.c"
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
#line 4135 "conf_parser.c"
    break;

  case 156: /* oper_name: NAME '=' QSTRING ';'  */
#line 947 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4144 "conf_parser.c"
    break;

  case 157: /* oper_user: USER '=' QSTRING ';'  */
#line 953 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4153 "conf_parser.c"
    break;

  case 158: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 959 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4162 "conf_parser.c"
    break;

  case 159: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 965 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4171 "conf_parser.c"
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
#line 4185 "conf_parser.c"
    break;

  case 161: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 982 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4194 "conf_parser.c"
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
#line 4208 "conf_parser.c"
    break;

  case 163: /* oper_class: CLASS '=' QSTRING ';'  */
#line 999 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4217 "conf_parser.c"
    break;

  case 164: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1005 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4226 "conf_parser.c"
    break;

  case 165: /* $@6: %empty  */
#line 1011 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4235 "conf_parser.c"
    break;

  case 169: /* oper_flags_item: KILL ':' REMOTE  */
#line 1018 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4244 "conf_parser.c"
    break;

  case 170: /* oper_flags_item: KILL  */
#line 1022 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4253 "conf_parser.c"
    break;

  case 171: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1026 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4262 "conf_parser.c"
    break;

  case 172: /* oper_flags_item: CONNECT  */
#line 1030 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4271 "conf_parser.c"
    break;

  case 173: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1034 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4280 "conf_parser.c"
    break;

  case 174: /* oper_flags_item: SQUIT  */
#line 1038 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4289 "conf_parser.c"
    break;

  case 175: /* oper_flags_item: KLINE  */
#line 1042 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4298 "conf_parser.c"
    break;

  case 176: /* oper_flags_item: UNKLINE  */
#line 1046 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4307 "conf_parser.c"
    break;

  case 177: /* oper_flags_item: T_DLINE  */
#line 1050 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4316 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: T_UNDLINE  */
#line 1054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4325 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: XLINE  */
#line 1058 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4334 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: T_UNXLINE  */
#line 1062 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4343 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: DIE  */
#line 1066 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4352 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: T_RESTART  */
#line 1070 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4361 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1074 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4370 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: REHASH  */
#line 1078 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4379 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: ADMIN  */
#line 1082 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4388 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_GLOBOPS  */
#line 1086 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4397 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_LOCOPS  */
#line 1090 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4406 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: REMOTEBAN  */
#line 1094 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4415 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_SET  */
#line 1098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4424 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: MODULE  */
#line 1102 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4433 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_OPME  */
#line 1106 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4442 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: NICK ':' RESV  */
#line 1110 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4451 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: JOIN ':' RESV  */
#line 1114 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4460 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: RESV  */
#line 1118 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4469 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_UNRESV  */
#line 1122 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4478 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: CLOSE  */
#line 1126 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4487 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1130 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4496 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: BYPASS ':' INPUT_FLOOD  */
#line 1134 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_BYPASS_INPUT_FLOOD;
}
#line 4505 "conf_parser.c"
    break;

  case 199: /* $@7: %empty  */
#line 1144 "conf_parser.y"
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

  case 200: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1155 "conf_parser.y"
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

  case 219: /* class_name: NAME '=' QSTRING ';'  */
#line 1218 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4578 "conf_parser.c"
    break;

  case 220: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1224 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4587 "conf_parser.c"
    break;

  case 221: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1230 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4596 "conf_parser.c"
    break;

  case 222: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1236 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4605 "conf_parser.c"
    break;

  case 223: /* class_connectfreq: CONNECTFREQ '=' timespec ';'  */
#line 1242 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4614 "conf_parser.c"
    break;

  case 224: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1248 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4623 "conf_parser.c"
    break;

  case 225: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1254 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4632 "conf_parser.c"
    break;

  case 226: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1260 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4641 "conf_parser.c"
    break;

  case 227: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1266 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4651 "conf_parser.c"
    break;

  case 228: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1273 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4660 "conf_parser.c"
    break;

  case 229: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1279 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4669 "conf_parser.c"
    break;

  case 230: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1285 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4678 "conf_parser.c"
    break;

  case 231: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1291 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4690 "conf_parser.c"
    break;

  case 232: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1300 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4702 "conf_parser.c"
    break;

  case 233: /* $@8: %empty  */
#line 1309 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4711 "conf_parser.c"
    break;

  case 237: /* class_flags_item: RANDOM_IDLE  */
#line 1316 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4720 "conf_parser.c"
    break;

  case 238: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1320 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4729 "conf_parser.c"
    break;

  case 239: /* $@9: %empty  */
#line 1330 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4738 "conf_parser.c"
    break;

  case 241: /* $@10: %empty  */
#line 1336 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4746 "conf_parser.c"
    break;

  case 245: /* listen_flags_item: T_TLS  */
#line 1342 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4755 "conf_parser.c"
    break;

  case 246: /* listen_flags_item: HIDDEN  */
#line 1346 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4764 "conf_parser.c"
    break;

  case 247: /* listen_flags_item: T_SERVER  */
#line 1350 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4773 "conf_parser.c"
    break;

  case 248: /* listen_flags_item: CLIENT  */
#line 1354 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4782 "conf_parser.c"
    break;

  case 249: /* listen_flags_item: DEFER  */
#line 1358 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4791 "conf_parser.c"
    break;

  case 257: /* $@11: %empty  */
#line 1366 "conf_parser.y"
                                 { reset_block_state(); }
#line 4797 "conf_parser.c"
    break;

  case 261: /* port_item: NUMBER  */
#line 1371 "conf_parser.y"
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

  case 262: /* port_item: NUMBER TWODOTS NUMBER  */
#line 1384 "conf_parser.y"
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

  case 263: /* listen_address: IP '=' QSTRING ';'  */
#line 1401 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4844 "conf_parser.c"
    break;

  case 264: /* listen_host: HOST '=' QSTRING ';'  */
#line 1407 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4853 "conf_parser.c"
    break;

  case 265: /* $@12: %empty  */
#line 1417 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4862 "conf_parser.c"
    break;

  case 266: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1421 "conf_parser.y"
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

  case 276: /* auth_user: USER '=' QSTRING ';'  */
#line 1482 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4926 "conf_parser.c"
    break;

  case 277: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1488 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4935 "conf_parser.c"
    break;

  case 278: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1494 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4944 "conf_parser.c"
    break;

  case 279: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1500 "conf_parser.y"
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

  case 280: /* $@13: %empty  */
#line 1511 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 4967 "conf_parser.c"
    break;

  case 284: /* auth_flags_item: EXCEED_LIMIT  */
#line 1519 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 4976 "conf_parser.c"
    break;

  case 285: /* auth_flags_item: KLINE_EXEMPT  */
#line 1523 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 4985 "conf_parser.c"
    break;

  case 286: /* auth_flags_item: XLINE_EXEMPT  */
#line 1527 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 4994 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: NEED_IDENT  */
#line 1531 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 5003 "conf_parser.c"
    break;

  case 288: /* auth_flags_item: CAN_FLOOD  */
#line 1535 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 5012 "conf_parser.c"
    break;

  case 289: /* auth_flags_item: NO_TILDE  */
#line 1539 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 5021 "conf_parser.c"
    break;

  case 290: /* auth_flags_item: RESV_EXEMPT  */
#line 1543 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 5030 "conf_parser.c"
    break;

  case 291: /* auth_flags_item: T_WEBIRC  */
#line 1547 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5039 "conf_parser.c"
    break;

  case 292: /* auth_flags_item: NEED_PASSWORD  */
#line 1551 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5048 "conf_parser.c"
    break;

  case 293: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1557 "conf_parser.y"
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

  case 294: /* $@14: %empty  */
#line 1572 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5075 "conf_parser.c"
    break;

  case 295: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1579 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5086 "conf_parser.c"
    break;

  case 302: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1590 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5095 "conf_parser.c"
    break;

  case 303: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1596 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5104 "conf_parser.c"
    break;

  case 304: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1602 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5113 "conf_parser.c"
    break;

  case 310: /* service_name: NAME '=' QSTRING ';'  */
#line 1617 "conf_parser.y"
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

  case 311: /* $@15: %empty  */
#line 1633 "conf_parser.y"
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

  case 312: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1644 "conf_parser.y"
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

  case 319: /* shared_name: NAME '=' QSTRING ';'  */
#line 1659 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5168 "conf_parser.c"
    break;

  case 320: /* shared_user: USER '=' QSTRING ';'  */
#line 1665 "conf_parser.y"
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

  case 321: /* $@16: %empty  */
#line 1684 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5199 "conf_parser.c"
    break;

  case 325: /* shared_type_item: KLINE  */
#line 1691 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5208 "conf_parser.c"
    break;

  case 326: /* shared_type_item: UNKLINE  */
#line 1695 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5217 "conf_parser.c"
    break;

  case 327: /* shared_type_item: T_DLINE  */
#line 1699 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5226 "conf_parser.c"
    break;

  case 328: /* shared_type_item: T_UNDLINE  */
#line 1703 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5235 "conf_parser.c"
    break;

  case 329: /* shared_type_item: XLINE  */
#line 1707 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5244 "conf_parser.c"
    break;

  case 330: /* shared_type_item: T_UNXLINE  */
#line 1711 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5253 "conf_parser.c"
    break;

  case 331: /* shared_type_item: RESV  */
#line 1715 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5262 "conf_parser.c"
    break;

  case 332: /* shared_type_item: T_UNRESV  */
#line 1719 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5271 "conf_parser.c"
    break;

  case 333: /* shared_type_item: T_LOCOPS  */
#line 1723 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5280 "conf_parser.c"
    break;

  case 334: /* shared_type_item: T_ALL  */
#line 1727 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5289 "conf_parser.c"
    break;

  case 335: /* $@17: %empty  */
#line 1737 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5303 "conf_parser.c"
    break;

  case 336: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1746 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5316 "conf_parser.c"
    break;

  case 342: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1759 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5325 "conf_parser.c"
    break;

  case 343: /* $@18: %empty  */
#line 1765 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5334 "conf_parser.c"
    break;

  case 347: /* cluster_type_item: KLINE  */
#line 1772 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5343 "conf_parser.c"
    break;

  case 348: /* cluster_type_item: UNKLINE  */
#line 1776 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5352 "conf_parser.c"
    break;

  case 349: /* cluster_type_item: T_DLINE  */
#line 1780 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5361 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: T_UNDLINE  */
#line 1784 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5370 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: XLINE  */
#line 1788 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5379 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: T_UNXLINE  */
#line 1792 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5388 "conf_parser.c"
    break;

  case 353: /* cluster_type_item: RESV  */
#line 1796 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5397 "conf_parser.c"
    break;

  case 354: /* cluster_type_item: T_UNRESV  */
#line 1800 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5406 "conf_parser.c"
    break;

  case 355: /* cluster_type_item: T_LOCOPS  */
#line 1804 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5415 "conf_parser.c"
    break;

  case 356: /* cluster_type_item: T_ALL  */
#line 1808 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5424 "conf_parser.c"
    break;

  case 357: /* $@19: %empty  */
#line 1818 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5438 "conf_parser.c"
    break;

  case 358: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1827 "conf_parser.y"
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

  case 376: /* connect_name: NAME '=' QSTRING ';'  */
#line 1889 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5495 "conf_parser.c"
    break;

  case 377: /* connect_host: HOST '=' QSTRING ';'  */
#line 1895 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5504 "conf_parser.c"
    break;

  case 378: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1901 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5513 "conf_parser.c"
    break;

  case 379: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1907 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5522 "conf_parser.c"
    break;

  case 380: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1913 "conf_parser.y"
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

  case 381: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 1926 "conf_parser.y"
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

  case 382: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1939 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5563 "conf_parser.c"
    break;

  case 383: /* connect_port: PORT '=' NUMBER ';'  */
#line 1945 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5572 "conf_parser.c"
    break;

  case 384: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 1951 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5581 "conf_parser.c"
    break;

  case 385: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 1955 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5590 "conf_parser.c"
    break;

  case 386: /* $@20: %empty  */
#line 1961 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5598 "conf_parser.c"
    break;

  case 390: /* connect_flags_item: AUTOCONN  */
#line 1967 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5607 "conf_parser.c"
    break;

  case 391: /* connect_flags_item: T_TLS  */
#line 1971 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5616 "conf_parser.c"
    break;

  case 392: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1977 "conf_parser.y"
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

  case 393: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 1988 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5639 "conf_parser.c"
    break;

  case 394: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 1994 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5648 "conf_parser.c"
    break;

  case 395: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2000 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5657 "conf_parser.c"
    break;

  case 396: /* $@21: %empty  */
#line 2010 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5666 "conf_parser.c"
    break;

  case 397: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2014 "conf_parser.y"
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

  case 403: /* kill_user: USER '=' QSTRING ';'  */
#line 2038 "conf_parser.y"
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

  case 404: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2058 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5722 "conf_parser.c"
    break;

  case 405: /* $@22: %empty  */
#line 2068 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5731 "conf_parser.c"
    break;

  case 406: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2072 "conf_parser.y"
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

  case 412: /* deny_ip: IP '=' QSTRING ';'  */
#line 2094 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5762 "conf_parser.c"
    break;

  case 413: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2100 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5771 "conf_parser.c"
    break;

  case 419: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2115 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_error_report("Unable to add D-line exemption");
}
#line 5783 "conf_parser.c"
    break;

  case 420: /* $@23: %empty  */
#line 2128 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5792 "conf_parser.c"
    break;

  case 421: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2132 "conf_parser.y"
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

  case 427: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2152 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5821 "conf_parser.c"
    break;

  case 428: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2158 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5830 "conf_parser.c"
    break;

  case 473: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2214 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5838 "conf_parser.c"
    break;

  case 474: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2219 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5846 "conf_parser.c"
    break;

  case 475: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2224 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5854 "conf_parser.c"
    break;

  case 476: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2229 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5862 "conf_parser.c"
    break;

  case 477: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2234 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5870 "conf_parser.c"
    break;

  case 478: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2239 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5878 "conf_parser.c"
    break;

  case 479: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2244 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5886 "conf_parser.c"
    break;

  case 480: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2249 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5894 "conf_parser.c"
    break;

  case 481: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2254 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5902 "conf_parser.c"
    break;

  case 482: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2259 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5910 "conf_parser.c"
    break;

  case 483: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2264 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5918 "conf_parser.c"
    break;

  case 484: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2269 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5926 "conf_parser.c"
    break;

  case 485: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2274 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5934 "conf_parser.c"
    break;

  case 486: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2279 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 5945 "conf_parser.c"
    break;

  case 487: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2287 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5953 "conf_parser.c"
    break;

  case 488: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2292 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5961 "conf_parser.c"
    break;

  case 489: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2297 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5969 "conf_parser.c"
    break;

  case 490: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2302 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5977 "conf_parser.c"
    break;

  case 491: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2307 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5985 "conf_parser.c"
    break;

  case 492: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2312 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5993 "conf_parser.c"
    break;

  case 493: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2317 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6001 "conf_parser.c"
    break;

  case 494: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2322 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6009 "conf_parser.c"
    break;

  case 495: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2327 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6017 "conf_parser.c"
    break;

  case 496: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2332 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6025 "conf_parser.c"
    break;

  case 497: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2337 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6033 "conf_parser.c"
    break;

  case 498: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2342 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6041 "conf_parser.c"
    break;

  case 499: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2347 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6049 "conf_parser.c"
    break;

  case 500: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2352 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6057 "conf_parser.c"
    break;

  case 501: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2357 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6065 "conf_parser.c"
    break;

  case 502: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2362 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6073 "conf_parser.c"
    break;

  case 503: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2367 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6081 "conf_parser.c"
    break;

  case 504: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2372 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6089 "conf_parser.c"
    break;

  case 505: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2377 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6097 "conf_parser.c"
    break;

  case 506: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2382 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6109 "conf_parser.c"
    break;

  case 507: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2391 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6117 "conf_parser.c"
    break;

  case 508: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2396 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6125 "conf_parser.c"
    break;

  case 509: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2401 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6133 "conf_parser.c"
    break;

  case 510: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2406 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6141 "conf_parser.c"
    break;

  case 511: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2411 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6152 "conf_parser.c"
    break;

  case 512: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2419 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6160 "conf_parser.c"
    break;

  case 523: /* cloak_enabled: ENABLED '=' TBOOL ';'  */
#line 2439 "conf_parser.y"
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
#line 6180 "conf_parser.c"
    break;

  case 524: /* cloak_cidr_len_ipv4: CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2456 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6192 "conf_parser.c"
    break;

  case 525: /* cloak_cidr_len_ipv6: CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2465 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6204 "conf_parser.c"
    break;

  case 526: /* cloak_num_bits: NUM_BITS '=' NUMBER ';'  */
#line 2474 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6216 "conf_parser.c"
    break;

  case 527: /* cloak_secret: SECRET '=' QSTRING ';'  */
#line 2483 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.secret);
  ConfigCloak.secret = io_strdup((yyvsp[-1].string));
  cloak_set_secret((yyvsp[-1].string));
}
#line 6229 "conf_parser.c"
    break;

  case 528: /* cloak_suffix: SUFFIX '=' QSTRING ';'  */
#line 2493 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.suffix);
  ConfigCloak.suffix = io_strdup((yyvsp[-1].string));
  cloak_set_suffix((yyvsp[-1].string));
}
#line 6242 "conf_parser.c"
    break;

  case 549: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2528 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6250 "conf_parser.c"
    break;

  case 550: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2533 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6258 "conf_parser.c"
    break;

  case 551: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2538 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6266 "conf_parser.c"
    break;

  case 552: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2543 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6274 "conf_parser.c"
    break;

  case 553: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2548 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6282 "conf_parser.c"
    break;

  case 554: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2553 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6290 "conf_parser.c"
    break;

  case 555: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2558 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6298 "conf_parser.c"
    break;

  case 556: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2563 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6306 "conf_parser.c"
    break;

  case 557: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2568 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6314 "conf_parser.c"
    break;

  case 558: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2573 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6322 "conf_parser.c"
    break;

  case 559: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2578 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6330 "conf_parser.c"
    break;

  case 560: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2583 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6338 "conf_parser.c"
    break;

  case 561: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
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
#line 6364 "conf_parser.c"
    break;

  case 562: /* channel_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 2611 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigChannel.max_topic_length = TOPICLEN;
  else
    ConfigChannel.max_topic_length = (yyvsp[-1].number);
}
#line 6375 "conf_parser.c"
    break;

  case 563: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2619 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6383 "conf_parser.c"
    break;

  case 564: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2624 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6391 "conf_parser.c"
    break;

  case 577: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2646 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6400 "conf_parser.c"
    break;

  case 578: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2652 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6414 "conf_parser.c"
    break;

  case 579: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2663 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6426 "conf_parser.c"
    break;

  case 580: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2672 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6435 "conf_parser.c"
    break;

  case 581: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2678 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6444 "conf_parser.c"
    break;

  case 582: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2684 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6453 "conf_parser.c"
    break;

  case 583: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2690 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6465 "conf_parser.c"
    break;

  case 584: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2699 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6474 "conf_parser.c"
    break;


#line 6478 "conf_parser.c"

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

