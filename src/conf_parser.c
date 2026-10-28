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

#include <limits.h>
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

static bool
_conf_parser_quantity_add(unsigned int total, unsigned int amount, unsigned int unit, unsigned int *result)
{
  if (amount > (UINT_MAX - total) / unit)
    return false;

  *result = total + amount * unit;
  return true;
}


#line 207 "conf_parser.c"

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
    KIBYTES = 269,                 /* KIBYTES  */
    MBYTES = 270,                  /* MBYTES  */
    MIBYTES = 271,                 /* MIBYTES  */
    GBYTES = 272,                  /* GBYTES  */
    GIBYTES = 273,                 /* GIBYTES  */
    CALLER_ID_WAIT = 274,          /* CALLER_ID_WAIT  */
    CAN_FLOOD = 275,               /* CAN_FLOOD  */
    CHANNEL = 276,                 /* CHANNEL  */
    CIDR_BITLEN_IPV4 = 277,        /* CIDR_BITLEN_IPV4  */
    CIDR_BITLEN_IPV6 = 278,        /* CIDR_BITLEN_IPV6  */
    CIDR_LEN_IPV4 = 279,           /* CIDR_LEN_IPV4  */
    CIDR_LEN_IPV6 = 280,           /* CIDR_LEN_IPV6  */
    CLASS = 281,                   /* CLASS  */
    CLIENT = 282,                  /* CLIENT  */
    CLOAK = 283,                   /* CLOAK  */
    CLOSE = 284,                   /* CLOSE  */
    CONNECT = 285,                 /* CONNECT  */
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
    ENABLED = 302,                 /* ENABLED  */
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
    INPUT_FLOOD = 322,             /* INPUT_FLOOD  */
    INVISIBLE_ON_CONNECT = 323,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 324,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 325,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 326,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 327,      /* INVITE_EXPIRE_TIME  */
    IP = 328,                      /* IP  */
    IRCD_AUTH = 329,               /* IRCD_AUTH  */
    IRCD_FLAGS = 330,              /* IRCD_FLAGS  */
    IRCD_SID = 331,                /* IRCD_SID  */
    JOIN = 332,                    /* JOIN  */
    KILL = 333,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 334,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 335,                   /* KLINE  */
    KLINE_EXEMPT = 336,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 337,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 338,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 339,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 340,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 341,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 342,               /* LEAF_MASK  */
    LISTEN = 343,                  /* LISTEN  */
    LOADMODULE = 344,              /* LOADMODULE  */
    MASK = 345,                    /* MASK  */
    MASS = 346,                    /* MASS  */
    MAX_ACCEPT = 347,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 348,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 349,                /* MAX_BANS  */
    MAX_BANS_LARGE = 350,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 351,            /* MAX_CHANNELS  */
    MAX_IDLE = 352,                /* MAX_IDLE  */
    MAX_INVITES = 353,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 354,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 355,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 356,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 357,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 358,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 359,              /* MAX_NUMBER  */
    MAX_TARGETS = 360,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 361,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 362,                 /* MESSAGE  */
    MIN_IDLE = 363,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 364,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 365,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 366,                  /* MODULE  */
    MODULE_BASE_PATH = 367,        /* MODULE_BASE_PATH  */
    MOTD = 368,                    /* MOTD  */
    MOTD_FILE = 369,               /* MOTD_FILE  */
    NAME = 370,                    /* NAME  */
    NEED_IDENT = 371,              /* NEED_IDENT  */
    NEED_PASSWORD = 372,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 373,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 374,            /* NETWORK_NAME  */
    NICK = 375,                    /* NICK  */
    NO_TILDE = 376,                /* NO_TILDE  */
    NUM_BITS = 377,                /* NUM_BITS  */
    NUMBER_PER_CIDR = 378,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 379,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 380,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 381,             /* OPER_UMODES  */
    OPERATOR = 382,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 383,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 384,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 385,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 386,                /* PASSWORD  */
    PATH = 387,                    /* PATH  */
    PING_COOKIE = 388,             /* PING_COOKIE  */
    PING_TIME = 389,               /* PING_TIME  */
    PORT = 390,                    /* PORT  */
    RANDOM_IDLE = 391,             /* RANDOM_IDLE  */
    REASON = 392,                  /* REASON  */
    REGISTRATION_TIMEOUT = 393,    /* REGISTRATION_TIMEOUT  */
    REHASH = 394,                  /* REHASH  */
    REMOTE = 395,                  /* REMOTE  */
    REMOTEBAN = 396,               /* REMOTEBAN  */
    REQUIRED = 397,                /* REQUIRED  */
    RESIDENT = 398,                /* RESIDENT  */
    RESV = 399,                    /* RESV  */
    RESV_EXEMPT = 400,             /* RESV_EXEMPT  */
    RETRY_DELAY = 401,             /* RETRY_DELAY  */
    SECRET = 402,                  /* SECRET  */
    SECONDS = 403,                 /* SECONDS  */
    MINUTES = 404,                 /* MINUTES  */
    HOURS = 405,                   /* HOURS  */
    DAYS = 406,                    /* DAYS  */
    WEEKS = 407,                   /* WEEKS  */
    SEND_PASSWORD = 408,           /* SEND_PASSWORD  */
    SENDQ = 409,                   /* SENDQ  */
    SERVERHIDE = 410,              /* SERVERHIDE  */
    SERVERINFO = 411,              /* SERVERINFO  */
    SHORT_MOTD = 412,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 413,       /* SPECIALS_IN_IDENT  */
    SPOOF = 414,                   /* SPOOF  */
    SQUIT = 415,                   /* SQUIT  */
    STATS_E_DISABLED = 416,        /* STATS_E_DISABLED  */
    STATS_U_OPER_ONLY = 417,       /* STATS_U_OPER_ONLY  */
    SUFFIX = 418,                  /* SUFFIX  */
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
#define BYPASS 266
#define BYTES 267
#define KBYTES 268
#define KIBYTES 269
#define MBYTES 270
#define MIBYTES 271
#define GBYTES 272
#define GIBYTES 273
#define CALLER_ID_WAIT 274
#define CAN_FLOOD 275
#define CHANNEL 276
#define CIDR_BITLEN_IPV4 277
#define CIDR_BITLEN_IPV6 278
#define CIDR_LEN_IPV4 279
#define CIDR_LEN_IPV6 280
#define CLASS 281
#define CLIENT 282
#define CLOAK 283
#define CLOSE 284
#define CONNECT 285
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
#define ENABLED 302
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
#define INPUT_FLOOD 322
#define INVISIBLE_ON_CONNECT 323
#define INVITE_CLIENT_COUNT 324
#define INVITE_CLIENT_TIME 325
#define INVITE_DELAY_CHANNEL 326
#define INVITE_EXPIRE_TIME 327
#define IP 328
#define IRCD_AUTH 329
#define IRCD_FLAGS 330
#define IRCD_SID 331
#define JOIN 332
#define KILL 333
#define KILL_CHASE_TIME_LIMIT 334
#define KLINE 335
#define KLINE_EXEMPT 336
#define KLINE_MIN_CIDR 337
#define KLINE_MIN_CIDR6 338
#define KNOCK_CLIENT_COUNT 339
#define KNOCK_CLIENT_TIME 340
#define KNOCK_DELAY_CHANNEL 341
#define LEAF_MASK 342
#define LISTEN 343
#define LOADMODULE 344
#define MASK 345
#define MASS 346
#define MAX_ACCEPT 347
#define MAX_AWAY_LENGTH 348
#define MAX_BANS 349
#define MAX_BANS_LARGE 350
#define MAX_CHANNELS 351
#define MAX_IDLE 352
#define MAX_INVITES 353
#define MAX_KICK_LENGTH 354
#define MAX_MONITOR 355
#define MAX_NICK_CHANGES 356
#define MAX_NICK_LENGTH 357
#define MAX_NICK_TIME 358
#define MAX_NUMBER 359
#define MAX_TARGETS 360
#define MAX_TOPIC_LENGTH 361
#define MESSAGE 362
#define MIN_IDLE 363
#define MIN_NONWILDCARD 364
#define MIN_NONWILDCARD_SIMPLE 365
#define MODULE 366
#define MODULE_BASE_PATH 367
#define MOTD 368
#define MOTD_FILE 369
#define NAME 370
#define NEED_IDENT 371
#define NEED_PASSWORD 372
#define NETWORK_DESCRIPTION 373
#define NETWORK_NAME 374
#define NICK 375
#define NO_TILDE 376
#define NUM_BITS 377
#define NUMBER_PER_CIDR 378
#define NUMBER_PER_IP_GLOBAL 379
#define NUMBER_PER_IP_LOCAL 380
#define OPER_UMODES 381
#define OPERATOR 382
#define OPERS_BYPASS_CALLERID 383
#define PACE_WAIT 384
#define PACE_WAIT_SIMPLE 385
#define PASSWORD 386
#define PATH 387
#define PING_COOKIE 388
#define PING_TIME 389
#define PORT 390
#define RANDOM_IDLE 391
#define REASON 392
#define REGISTRATION_TIMEOUT 393
#define REHASH 394
#define REMOTE 395
#define REMOTEBAN 396
#define REQUIRED 397
#define RESIDENT 398
#define RESV 399
#define RESV_EXEMPT 400
#define RETRY_DELAY 401
#define SECRET 402
#define SECONDS 403
#define MINUTES 404
#define HOURS 405
#define DAYS 406
#define WEEKS 407
#define SEND_PASSWORD 408
#define SENDQ 409
#define SERVERHIDE 410
#define SERVERINFO 411
#define SHORT_MOTD 412
#define SPECIALS_IN_IDENT 413
#define SPOOF 414
#define SQUIT 415
#define STATS_E_DISABLED 416
#define STATS_U_OPER_ONLY 417
#define SUFFIX 418
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
#line 148 "conf_parser.y"

  unsigned int number;
  char *string;

#line 699 "conf_parser.c"

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
  YYSYMBOL_KIBYTES = 14,                   /* KIBYTES  */
  YYSYMBOL_MBYTES = 15,                    /* MBYTES  */
  YYSYMBOL_MIBYTES = 16,                   /* MIBYTES  */
  YYSYMBOL_GBYTES = 17,                    /* GBYTES  */
  YYSYMBOL_GIBYTES = 18,                   /* GIBYTES  */
  YYSYMBOL_CALLER_ID_WAIT = 19,            /* CALLER_ID_WAIT  */
  YYSYMBOL_CAN_FLOOD = 20,                 /* CAN_FLOOD  */
  YYSYMBOL_CHANNEL = 21,                   /* CHANNEL  */
  YYSYMBOL_CIDR_BITLEN_IPV4 = 22,          /* CIDR_BITLEN_IPV4  */
  YYSYMBOL_CIDR_BITLEN_IPV6 = 23,          /* CIDR_BITLEN_IPV6  */
  YYSYMBOL_CIDR_LEN_IPV4 = 24,             /* CIDR_LEN_IPV4  */
  YYSYMBOL_CIDR_LEN_IPV6 = 25,             /* CIDR_LEN_IPV6  */
  YYSYMBOL_CLASS = 26,                     /* CLASS  */
  YYSYMBOL_CLIENT = 27,                    /* CLIENT  */
  YYSYMBOL_CLOAK = 28,                     /* CLOAK  */
  YYSYMBOL_CLOSE = 29,                     /* CLOSE  */
  YYSYMBOL_CONNECT = 30,                   /* CONNECT  */
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
  YYSYMBOL_ENABLED = 47,                   /* ENABLED  */
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
  YYSYMBOL_INPUT_FLOOD = 67,               /* INPUT_FLOOD  */
  YYSYMBOL_INVISIBLE_ON_CONNECT = 68,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 69,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 70,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 71,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 72,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 73,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 74,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 75,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 76,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 77,                      /* JOIN  */
  YYSYMBOL_KILL = 78,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 79,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 80,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 81,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 82,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 83,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 84,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 85,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 86,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 87,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 88,                    /* LISTEN  */
  YYSYMBOL_LOADMODULE = 89,                /* LOADMODULE  */
  YYSYMBOL_MASK = 90,                      /* MASK  */
  YYSYMBOL_MASS = 91,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 92,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_AWAY_LENGTH = 93,           /* MAX_AWAY_LENGTH  */
  YYSYMBOL_MAX_BANS = 94,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 95,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 96,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 97,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 98,               /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 99,           /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 100,              /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 101,         /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 102,          /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 103,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 104,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 105,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 106,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 107,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 108,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 109,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 110,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 111,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 112,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 113,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 114,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 115,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 116,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 117,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 118,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 119,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 120,                     /* NICK  */
  YYSYMBOL_NO_TILDE = 121,                 /* NO_TILDE  */
  YYSYMBOL_NUM_BITS = 122,                 /* NUM_BITS  */
  YYSYMBOL_NUMBER_PER_CIDR = 123,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 124,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 125,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_UMODES = 126,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 127,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 128,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 129,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 130,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 131,                 /* PASSWORD  */
  YYSYMBOL_PATH = 132,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 133,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 134,                /* PING_TIME  */
  YYSYMBOL_PORT = 135,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 136,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 137,                   /* REASON  */
  YYSYMBOL_REGISTRATION_TIMEOUT = 138,     /* REGISTRATION_TIMEOUT  */
  YYSYMBOL_REHASH = 139,                   /* REHASH  */
  YYSYMBOL_REMOTE = 140,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 141,                /* REMOTEBAN  */
  YYSYMBOL_REQUIRED = 142,                 /* REQUIRED  */
  YYSYMBOL_RESIDENT = 143,                 /* RESIDENT  */
  YYSYMBOL_RESV = 144,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 145,              /* RESV_EXEMPT  */
  YYSYMBOL_RETRY_DELAY = 146,              /* RETRY_DELAY  */
  YYSYMBOL_SECRET = 147,                   /* SECRET  */
  YYSYMBOL_SECONDS = 148,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 149,                  /* MINUTES  */
  YYSYMBOL_HOURS = 150,                    /* HOURS  */
  YYSYMBOL_DAYS = 151,                     /* DAYS  */
  YYSYMBOL_WEEKS = 152,                    /* WEEKS  */
  YYSYMBOL_SEND_PASSWORD = 153,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 154,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 155,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 156,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 157,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 158,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 159,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 160,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 161,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_U_OPER_ONLY = 162,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_SUFFIX = 163,                   /* SUFFIX  */
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
  YYSYMBOL_timespec = 227,                 /* timespec  */
  YYSYMBOL_time_components = 228,          /* time_components  */
  YYSYMBOL_time_unit = 229,                /* time_unit  */
  YYSYMBOL_sizespec = 230,                 /* sizespec  */
  YYSYMBOL_size_components = 231,          /* size_components  */
  YYSYMBOL_size_unit = 232,                /* size_unit  */
  YYSYMBOL_port_number = 233,              /* port_number  */
  YYSYMBOL_module_base_path_entry = 234,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 235,         /* loadmodule_entry  */
  YYSYMBOL_module_string = 236,            /* module_string  */
  YYSYMBOL_module_attributes = 237,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 238,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 239,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 240,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 241,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 242,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 243, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_tls_private_key_file = 244, /* serverinfo_tls_private_key_file  */
  YYSYMBOL_serverinfo_name = 245,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 246,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 247,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 248,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 249, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 250, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 251, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_motd_file = 252,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 253,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 254,              /* admin_entry  */
  YYSYMBOL_admin_items = 255,              /* admin_items  */
  YYSYMBOL_admin_item = 256,               /* admin_item  */
  YYSYMBOL_admin_name = 257,               /* admin_name  */
  YYSYMBOL_admin_email = 258,              /* admin_email  */
  YYSYMBOL_admin_description = 259,        /* admin_description  */
  YYSYMBOL_motd_entry = 260,               /* motd_entry  */
  YYSYMBOL_261_1 = 261,                    /* $@1  */
  YYSYMBOL_motd_items = 262,               /* motd_items  */
  YYSYMBOL_motd_item = 263,                /* motd_item  */
  YYSYMBOL_motd_mask = 264,                /* motd_mask  */
  YYSYMBOL_motd_file = 265,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 266,             /* pseudo_entry  */
  YYSYMBOL_267_2 = 267,                    /* $@2  */
  YYSYMBOL_pseudo_items = 268,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 269,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 270,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 271,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 272,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 273,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 274,            /* logging_entry  */
  YYSYMBOL_logging_items = 275,            /* logging_items  */
  YYSYMBOL_logging_item = 276,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 277,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 278,       /* logging_file_entry  */
  YYSYMBOL_279_3 = 279,                    /* $@3  */
  YYSYMBOL_logging_file_items = 280,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 281,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 282,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 283,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 284,        /* logging_file_type  */
  YYSYMBOL_285_4 = 285,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 286,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 287,               /* oper_entry  */
  YYSYMBOL_288_5 = 288,                    /* $@5  */
  YYSYMBOL_oper_items = 289,               /* oper_items  */
  YYSYMBOL_oper_item = 290,                /* oper_item  */
  YYSYMBOL_oper_name = 291,                /* oper_name  */
  YYSYMBOL_oper_user = 292,                /* oper_user  */
  YYSYMBOL_oper_password = 293,            /* oper_password  */
  YYSYMBOL_oper_whois = 294,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 295,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 296, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 297, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 298,               /* oper_class  */
  YYSYMBOL_oper_umodes = 299,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 300,               /* oper_flags  */
  YYSYMBOL_301_6 = 301,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 302,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 303,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 304,              /* class_entry  */
  YYSYMBOL_305_7 = 305,                    /* $@7  */
  YYSYMBOL_class_items = 306,              /* class_items  */
  YYSYMBOL_class_item = 307,               /* class_item  */
  YYSYMBOL_class_name = 308,               /* class_name  */
  YYSYMBOL_class_ping_time = 309,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 310, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 311, /* class_number_per_ip_global  */
  YYSYMBOL_class_max_channels = 312,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 313,         /* class_max_number  */
  YYSYMBOL_class_sendq = 314,              /* class_sendq  */
  YYSYMBOL_class_recvq = 315,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 316,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 317,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 318,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 319,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 320,           /* class_max_idle  */
  YYSYMBOL_class_flags = 321,              /* class_flags  */
  YYSYMBOL_322_8 = 322,                    /* $@8  */
  YYSYMBOL_class_flags_items = 323,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 324,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 325,             /* listen_entry  */
  YYSYMBOL_326_9 = 326,                    /* $@9  */
  YYSYMBOL_listen_flags = 327,             /* listen_flags  */
  YYSYMBOL_328_10 = 328,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 329,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 330,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 331,             /* listen_items  */
  YYSYMBOL_listen_item = 332,              /* listen_item  */
  YYSYMBOL_listen_port = 333,              /* listen_port  */
  YYSYMBOL_334_11 = 334,                   /* $@11  */
  YYSYMBOL_port_items = 335,               /* port_items  */
  YYSYMBOL_port_item = 336,                /* port_item  */
  YYSYMBOL_listen_address = 337,           /* listen_address  */
  YYSYMBOL_listen_host = 338,              /* listen_host  */
  YYSYMBOL_auth_entry = 339,               /* auth_entry  */
  YYSYMBOL_340_12 = 340,                   /* $@12  */
  YYSYMBOL_auth_items = 341,               /* auth_items  */
  YYSYMBOL_auth_item = 342,                /* auth_item  */
  YYSYMBOL_auth_user = 343,                /* auth_user  */
  YYSYMBOL_auth_passwd = 344,              /* auth_passwd  */
  YYSYMBOL_auth_class = 345,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 346,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 347,               /* auth_flags  */
  YYSYMBOL_348_13 = 348,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 349,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 350,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 351,               /* auth_spoof  */
  YYSYMBOL_resv_entry = 352,               /* resv_entry  */
  YYSYMBOL_353_14 = 353,                   /* $@14  */
  YYSYMBOL_resv_items = 354,               /* resv_items  */
  YYSYMBOL_resv_item = 355,                /* resv_item  */
  YYSYMBOL_resv_mask = 356,                /* resv_mask  */
  YYSYMBOL_resv_reason = 357,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 358,              /* resv_exempt  */
  YYSYMBOL_service_entry = 359,            /* service_entry  */
  YYSYMBOL_service_items = 360,            /* service_items  */
  YYSYMBOL_service_item = 361,             /* service_item  */
  YYSYMBOL_service_name = 362,             /* service_name  */
  YYSYMBOL_shared_entry = 363,             /* shared_entry  */
  YYSYMBOL_364_15 = 364,                   /* $@15  */
  YYSYMBOL_shared_items = 365,             /* shared_items  */
  YYSYMBOL_shared_item = 366,              /* shared_item  */
  YYSYMBOL_shared_name = 367,              /* shared_name  */
  YYSYMBOL_shared_user = 368,              /* shared_user  */
  YYSYMBOL_shared_type = 369,              /* shared_type  */
  YYSYMBOL_370_16 = 370,                   /* $@16  */
  YYSYMBOL_shared_types = 371,             /* shared_types  */
  YYSYMBOL_shared_type_item = 372,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 373,            /* cluster_entry  */
  YYSYMBOL_374_17 = 374,                   /* $@17  */
  YYSYMBOL_cluster_items = 375,            /* cluster_items  */
  YYSYMBOL_cluster_item = 376,             /* cluster_item  */
  YYSYMBOL_cluster_name = 377,             /* cluster_name  */
  YYSYMBOL_cluster_type = 378,             /* cluster_type  */
  YYSYMBOL_379_18 = 379,                   /* $@18  */
  YYSYMBOL_cluster_types = 380,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 381,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 382,            /* connect_entry  */
  YYSYMBOL_383_19 = 383,                   /* $@19  */
  YYSYMBOL_connect_items = 384,            /* connect_items  */
  YYSYMBOL_connect_item = 385,             /* connect_item  */
  YYSYMBOL_connect_name = 386,             /* connect_name  */
  YYSYMBOL_connect_host = 387,             /* connect_host  */
  YYSYMBOL_connect_timeout = 388,          /* connect_timeout  */
  YYSYMBOL_connect_retry_delay = 389,      /* connect_retry_delay  */
  YYSYMBOL_connect_bind = 390,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 391,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 392,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 393, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 394,             /* connect_port  */
  YYSYMBOL_connect_aftype = 395,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 396,            /* connect_flags  */
  YYSYMBOL_397_20 = 397,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 398,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 399,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 400,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 401,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 402,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 403,            /* connect_class  */
  YYSYMBOL_kill_entry = 404,               /* kill_entry  */
  YYSYMBOL_405_21 = 405,                   /* $@21  */
  YYSYMBOL_kill_items = 406,               /* kill_items  */
  YYSYMBOL_kill_item = 407,                /* kill_item  */
  YYSYMBOL_kill_user = 408,                /* kill_user  */
  YYSYMBOL_kill_reason = 409,              /* kill_reason  */
  YYSYMBOL_deny_entry = 410,               /* deny_entry  */
  YYSYMBOL_411_22 = 411,                   /* $@22  */
  YYSYMBOL_deny_items = 412,               /* deny_items  */
  YYSYMBOL_deny_item = 413,                /* deny_item  */
  YYSYMBOL_deny_ip = 414,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 415,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 416,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 417,             /* exempt_items  */
  YYSYMBOL_exempt_item = 418,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 419,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 420,              /* gecos_entry  */
  YYSYMBOL_421_23 = 421,                   /* $@23  */
  YYSYMBOL_gecos_items = 422,              /* gecos_items  */
  YYSYMBOL_gecos_item = 423,               /* gecos_item  */
  YYSYMBOL_gecos_name = 424,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 425,             /* gecos_reason  */
  YYSYMBOL_general_entry = 426,            /* general_entry  */
  YYSYMBOL_general_items = 427,            /* general_items  */
  YYSYMBOL_general_item = 428,             /* general_item  */
  YYSYMBOL_general_away_count = 429,       /* general_away_count  */
  YYSYMBOL_general_away_time = 430,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 431,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 432, /* general_whowas_history_length  */
  YYSYMBOL_general_dline_min_cidr = 433,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 434,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 435,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 436,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 437, /* general_kill_chase_time_limit  */
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
  YYSYMBOL_general_specials_in_ident = 455, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 456,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 457,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_ident = 458,    /* general_disable_ident  */
  YYSYMBOL_general_disable_dns = 459,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 460,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 461,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 462,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 463,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 464, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 465, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 466, /* general_default_floodtime  */
  YYSYMBOL_general_ident_timeout = 467,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 468, /* general_registration_timeout  */
  YYSYMBOL_cloak_entry = 469,              /* cloak_entry  */
  YYSYMBOL_cloak_items = 470,              /* cloak_items  */
  YYSYMBOL_cloak_item = 471,               /* cloak_item  */
  YYSYMBOL_cloak_enabled = 472,            /* cloak_enabled  */
  YYSYMBOL_cloak_cidr_len_ipv4 = 473,      /* cloak_cidr_len_ipv4  */
  YYSYMBOL_cloak_cidr_len_ipv6 = 474,      /* cloak_cidr_len_ipv6  */
  YYSYMBOL_cloak_num_bits = 475,           /* cloak_num_bits  */
  YYSYMBOL_cloak_secret = 476,             /* cloak_secret  */
  YYSYMBOL_cloak_suffix = 477,             /* cloak_suffix  */
  YYSYMBOL_channel_entry = 478,            /* channel_entry  */
  YYSYMBOL_channel_items = 479,            /* channel_items  */
  YYSYMBOL_channel_item = 480,             /* channel_item  */
  YYSYMBOL_channel_disable_fake_channels = 481, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 482, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 483, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 484, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 485, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 486, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 487, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 488, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 489,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 490,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 491,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 492,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 493,  /* channel_max_kick_length  */
  YYSYMBOL_channel_max_topic_length = 494, /* channel_max_topic_length  */
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
#define YYLAST   1153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  224
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  284
/* YYNRULES -- Number of rules.  */
#define YYNRULES  589
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1206

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
       0,   367,   367,   368,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     400,   409,   411,   418,   427,   428,   429,   430,   431,   434,
     443,   445,   452,   461,   462,   463,   464,   465,   466,   467,
     470,   485,   503,   518,   524,   526,   531,   534,   539,   542,
     551,   553,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   568,   577,   586,   601,   616,
     626,   640,   649,   672,   695,   704,   714,   716,   716,   717,
     718,   719,   720,   722,   731,   740,   754,   753,   771,   771,
     772,   772,   772,   774,   780,   791,   790,   809,   809,   810,
     810,   810,   810,   810,   812,   818,   824,   830,   853,   854,
     854,   856,   856,   857,   859,   869,   869,   882,   883,   885,
     885,   886,   886,   888,   896,   899,   905,   904,   910,   914,
     918,   922,   926,   930,   934,   938,   949,   948,  1010,  1010,
    1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,
    1021,  1023,  1029,  1035,  1041,  1047,  1058,  1064,  1075,  1081,
    1088,  1087,  1093,  1093,  1094,  1098,  1102,  1106,  1110,  1114,
    1118,  1122,  1126,  1130,  1134,  1138,  1142,  1146,  1150,  1154,
    1158,  1162,  1166,  1170,  1174,  1178,  1182,  1186,  1190,  1194,
    1198,  1202,  1206,  1210,  1221,  1220,  1274,  1274,  1275,  1276,
    1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,
    1287,  1288,  1289,  1291,  1297,  1303,  1309,  1315,  1321,  1327,
    1333,  1340,  1346,  1352,  1358,  1367,  1377,  1376,  1382,  1382,
    1383,  1387,  1398,  1397,  1404,  1403,  1408,  1408,  1409,  1413,
    1417,  1421,  1425,  1431,  1431,  1432,  1432,  1432,  1432,  1432,
    1434,  1434,  1436,  1436,  1438,  1451,  1468,  1474,  1485,  1484,
    1540,  1540,  1541,  1542,  1543,  1544,  1545,  1546,  1547,  1549,
    1555,  1561,  1567,  1579,  1578,  1584,  1584,  1586,  1590,  1594,
    1598,  1602,  1606,  1610,  1614,  1618,  1624,  1640,  1639,  1654,
    1654,  1655,  1655,  1655,  1655,  1657,  1663,  1669,  1679,  1681,
    1681,  1682,  1682,  1684,  1701,  1700,  1723,  1723,  1724,  1724,
    1724,  1724,  1726,  1732,  1752,  1751,  1757,  1757,  1758,  1762,
    1766,  1770,  1774,  1778,  1782,  1786,  1790,  1794,  1805,  1804,
    1823,  1823,  1824,  1824,  1824,  1826,  1833,  1832,  1838,  1838,
    1839,  1843,  1847,  1851,  1855,  1859,  1863,  1867,  1871,  1875,
    1886,  1885,  1941,  1941,  1942,  1943,  1944,  1945,  1946,  1947,
    1948,  1949,  1950,  1951,  1952,  1953,  1954,  1955,  1956,  1957,
    1959,  1965,  1971,  1977,  1983,  1989,  2002,  2015,  2021,  2027,
    2031,  2038,  2037,  2042,  2042,  2043,  2047,  2053,  2064,  2070,
    2076,  2087,  2086,  2111,  2111,  2112,  2112,  2112,  2114,  2134,
    2145,  2144,  2167,  2167,  2168,  2168,  2168,  2170,  2176,  2186,
    2188,  2188,  2189,  2189,  2191,  2205,  2204,  2225,  2225,  2226,
    2226,  2226,  2228,  2234,  2244,  2246,  2246,  2247,  2248,  2249,
    2250,  2251,  2252,  2253,  2254,  2255,  2256,  2257,  2258,  2259,
    2260,  2261,  2262,  2263,  2264,  2265,  2266,  2267,  2268,  2269,
    2270,  2271,  2272,  2273,  2274,  2275,  2276,  2277,  2278,  2279,
    2280,  2281,  2282,  2283,  2284,  2285,  2286,  2287,  2290,  2295,
    2300,  2305,  2310,  2315,  2320,  2325,  2330,  2335,  2340,  2345,
    2350,  2355,  2363,  2368,  2373,  2378,  2383,  2388,  2393,  2398,
    2403,  2408,  2413,  2418,  2423,  2428,  2433,  2438,  2443,  2448,
    2453,  2458,  2467,  2472,  2477,  2482,  2487,  2495,  2504,  2506,
    2506,  2507,  2508,  2509,  2510,  2511,  2512,  2513,  2515,  2532,
    2541,  2550,  2559,  2569,  2583,  2585,  2585,  2586,  2587,  2588,
    2589,  2590,  2591,  2592,  2593,  2594,  2595,  2596,  2597,  2598,
    2599,  2600,  2601,  2602,  2604,  2609,  2614,  2619,  2624,  2629,
    2634,  2639,  2644,  2649,  2654,  2659,  2664,  2687,  2695,  2700,
    2709,  2711,  2711,  2712,  2713,  2714,  2715,  2716,  2717,  2718,
    2719,  2720,  2722,  2728,  2739,  2748,  2754,  2760,  2766,  2775
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
  "KIBYTES", "MBYTES", "MIBYTES", "GBYTES", "GIBYTES", "CALLER_ID_WAIT",
  "CAN_FLOOD", "CHANNEL", "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6",
  "CIDR_LEN_IPV4", "CIDR_LEN_IPV6", "CLASS", "CLIENT", "CLOAK", "CLOSE",
  "CONNECT", "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME",
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
  "MINUTES", "HOURS", "DAYS", "WEEKS", "SEND_PASSWORD", "SENDQ",
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
  "'{'", "$accept", "conf", "conf_item", "timespec", "time_components",
  "time_unit", "sizespec", "size_components", "size_unit", "port_number",
  "module_base_path_entry", "loadmodule_entry", "module_string",
  "module_attributes", "module_attributes_items", "module_attributes_item",
  "serverinfo_entry", "serverinfo_items", "serverinfo_item",
  "serverinfo_tls_certificate_file", "serverinfo_tls_private_key_file",
  "serverinfo_name", "serverinfo_sid", "serverinfo_description",
  "serverinfo_network_name", "serverinfo_network_description",
  "serverinfo_default_max_clients", "serverinfo_max_nick_length",
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

#define YYPACT_NINF (-648)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-126)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -648,   598,  -648,  -203,  -193,  -167,  -648,  -166,  -648,  -648,
    -151,  -648,  -150,  -648,  -648,  -648,  -136,  -138,  -648,  -648,
    -648,  -133,  -129,  -648,  -127,  -648,  -123,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,   305,   722,  -122,   377,  -120,
    -119,     8,  -116,   365,  -110,  -106,  -104,  -648,  -101,  -136,
     -93,   -85,   -84,   780,   387,   -67,    17,   -66,     7,   -59,
     -47,   -45,   -44,   -34,   120,  -648,  -648,  -648,  -648,  -648,
     -30,   -28,   -17,   -16,   -12,    -4,    11,    30,    52,    70,
      71,    74,    77,    80,    82,    84,   127,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,   616,  -648,    85,    87,    90,    91,
      93,    96,    67,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
     531,    13,  -648,    97,    10,  -648,  -648,    28,  -648,   102,
     106,   109,   113,   121,   124,   129,   133,   134,   135,   138,
     139,   140,   141,   142,   143,   147,   149,   153,   156,   165,
     171,   172,   173,   175,   179,   180,   184,   191,   192,   193,
     195,   197,   199,   201,   203,   206,   207,   208,   214,    44,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,   277,    57,   314,  -107,   122,   220,    45,   381,   300,
    -648,   219,   221,   222,   223,   225,   226,   234,   239,     9,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,   235,
     240,   241,   244,   247,   249,   251,   252,   253,   256,   257,
     258,   216,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,    78,   265,   264,    25,  -648,  -648,
    -648,   -72,   217,  -648,   266,    33,  -648,  -648,    40,  -648,
     224,   271,   276,   282,  -648,   148,   287,   313,   291,   287,
     287,   287,   292,   287,   287,   293,   303,   304,   308,   316,
     318,   312,  -648,   319,   322,   323,  -648,   324,   325,   328,
     329,   330,   332,   333,   334,   335,   336,   339,   145,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,   321,   346,   370,   348,   350,   354,
     355,  -648,   356,   352,   357,   361,   363,   364,   366,  -648,
     371,   380,   383,   384,   388,   389,   392,   393,   233,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   394,   395,    42,  -648,
    -648,  -648,   385,   379,  -648,  -648,   396,   401,    63,  -648,
    -648,  -648,   413,   287,   415,   287,   287,   416,   287,   442,
     443,   424,   427,   287,   453,   287,   432,   433,   434,   437,
     438,   439,   287,   441,   444,   445,   448,   465,   287,   287,
     466,   287,   473,   454,   474,   476,   456,   287,   287,   287,
     484,   462,   463,  -648,   464,   460,   468,  -648,   469,   470,
     472,   162,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
     475,   477,    48,  -648,  -648,  -648,   467,   478,   480,  -648,
     481,  -648,    24,  -648,  -648,  -648,  -648,  -648,  -648,   471,
    -648,  -648,  -648,   485,   482,   486,    39,  -648,  -648,  -648,
     487,   488,   489,  -648,   494,   495,   496,   497,   498,   506,
     509,    76,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,   514,   513,   515,   517,    43,  -648,  -648,
    -648,  -648,   540,   544,   287,   491,   549,   529,   552,   554,
     533,  -648,  -648,   532,   542,   565,   545,   543,   546,   547,
     550,   551,   553,   555,   559,  -648,   560,   548,  -648,    68,
    -648,  -648,  -648,  -648,   585,   566,  -648,   562,   568,   563,
     567,   570,   576,   161,  -648,  -648,  -648,  -648,  -648,   572,
     580,  -648,   581,   582,  -648,   584,    66,  -648,  -648,  -648,
    -648,   587,   591,   592,  -648,   593,  -128,   594,   586,   595,
     596,   597,   601,   604,   606,   607,   608,   609,   611,   612,
     617,   620,   621,  -648,  -648,   623,   626,   614,   627,   287,
     628,   287,   630,   631,   632,   633,   287,   634,   634,   629,
    -648,   635,   636,   637,   638,   639,   640,  -648,  -648,   643,
    -125,   644,   658,   645,   646,   647,   648,   649,   651,   287,
     650,   653,   287,   654,   655,  -648,   656,   659,   660,  -648,
     661,  -648,   664,   665,   666,  -648,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,   706,  -648,  -648,   709,   732,
     657,   711,   712,   713,   714,  -648,   715,   717,   716,  -648,
    -648,   719,   720,   662,   651,   721,  -648,  -107,  -648,   724,
     725,   726,  -648,  -648,   727,   736,   663,   729,   730,   731,
     733,   743,   734,   735,   737,  -648,  -648,   738,   740,   741,
     742,  -648,   744,   745,   746,   747,   748,   749,   750,   751,
    -648,   752,   753,   754,   755,   756,   757,   758,   759,   760,
     761,   762,  -648,  -648,   765,   718,   764,  -648,   766,  -648,
     151,  -648,   767,   769,   770,   771,   772,  -648,   773,  -648,
    -648,   776,   728,   777,   778,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -128,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,   779,   781,   -41,   782,   783,   784,   785,   786,
     787,   788,   789,   790,   501,   791,   793,   794,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,   795,   796,   797,   798,   799,
     800,   801,    -3,   802,   803,  -648,   804,   805,   806,   807,
     808,   809,  -648,   810,   811,  -648,  -648,   812,   813,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
     814,   815,   430,   816,   817,   818,  -648,   819,   820,  -648,
     821,   822,   301,   479,   578,  -648,  -648,  -648,   823,   824,
    -648,   825,   826,   451,   827,   828,   829,   830,   831,   832,
     833,  -648,   834,   835,   836,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,   837,   530,  -648,  -648,   838,
     739,   768,  -648,   104,  -648,  -648,  -648,  -648,   839,   840,
     841,   842,  -648,  -648,   843,   583,   844,  -648,  -648,  -648,
    -648,  -648,  -648,  -205,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,   501,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -191,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -190,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -185,  -648,   651,   651,   845,  -648,  -648,
    -648,  -648,  -648,   642,  -648,   774,  -648,   846,   847,  -648,
     848,  -648,   849,   850,  -648,  -648,   851,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -180,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -163,  -648,  -648,   857,  -178,   854,   858,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -144,  -648,  -648,  -648,   -41,  -648,
    -648,    -3,  -648,   430,  -648,   301,  -648,  -648,  -648,   875,
     871,   920,   925,   710,   922,   935,   937,  -648,   451,  -648,
     530,   860,   861,   862,   461,  -648,  -648,   583,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,   863,  -648,  -648
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   204,     0,   360,   410,
       0,   425,     0,   268,   401,   242,     0,     0,    96,   146,
     297,     0,     0,   338,     0,   105,     0,   314,     3,     4,
       5,    14,     6,    26,    27,     7,     8,    11,    12,    13,
      16,    17,    18,    19,    20,    21,    22,    23,    25,    24,
      10,     9,    15,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    91,    90,   553,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   536,   552,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   537,   538,
     548,   549,   550,   551,     0,   527,     0,     0,     0,     0,
       0,     0,     0,   520,   521,   522,   523,   524,   525,   526,
       0,     0,   423,     0,     0,   421,   422,     0,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     436,   437,   438,   474,   443,   469,   470,   471,   472,   447,
     439,   440,   441,   442,   456,   444,   445,   446,   448,   449,
     473,   451,   452,   458,   459,   453,   454,   450,   455,   466,
     467,   468,   464,   465,   457,   462,   463,   460,   461,   475,
     476,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     581,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     572,   573,   574,   575,   576,   577,   578,   580,   579,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    73,    71,    63,    72,    65,    66,    67,
      68,    69,    70,    64,     0,     0,     0,     0,   120,   121,
     122,     0,     0,   312,     0,     0,   310,   311,     0,    92,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   535,     0,     0,     0,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
     208,   211,   213,   214,   215,   216,   217,   218,   209,   210,
     212,   219,   220,   221,     0,     0,     0,     0,     0,     0,
       0,   519,     0,     0,     0,     0,     0,     0,     0,   391,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   373,   372,
     374,   378,   375,   376,   377,   416,     0,     0,     0,   413,
     414,   415,     0,     0,   420,   431,     0,     0,     0,   428,
     429,   430,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   435,     0,     0,     0,   283,     0,     0,
       0,     0,   271,   272,   273,   274,   277,   275,   276,   407,
       0,     0,     0,   404,   405,   406,     0,     0,     0,   244,
       0,   256,     0,   254,   255,   257,   258,    59,    58,    55,
      57,    52,    51,     0,     0,     0,     0,    99,   100,   101,
       0,     0,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,   149,   150,   151,   152,   153,   156,   157,   158,
     155,   154,   159,     0,     0,     0,     0,     0,   300,   301,
     302,   303,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   571,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,   346,     0,
     341,   342,   343,   123,     0,     0,   119,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   111,   110,   112,     0,
       0,   309,     0,     0,   324,     0,     0,   317,   318,   319,
     320,     0,     0,     0,    86,     0,    30,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   534,   222,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     206,     0,     0,     0,     0,     0,     0,   518,   379,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   362,     0,     0,     0,   412,
       0,   419,     0,     0,     0,   427,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   434,   278,     0,     0,
       0,     0,     0,     0,     0,   270,     0,     0,     0,   403,
     259,     0,     0,     0,     0,     0,   253,     0,   102,     0,
       0,     0,    98,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   304,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
     570,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,   344,     0,     0,     0,   340,     0,   118,
       0,   113,     0,     0,     0,     0,     0,   107,     0,   308,
     321,     0,     0,     0,     0,   316,    95,    94,    93,   568,
      34,    35,    36,    37,    38,    32,   569,     0,   554,   555,
     556,   557,   558,   559,   560,   561,   564,   565,   562,   563,
     566,   567,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,    40,     0,   205,   529,
     530,   528,   531,   532,   533,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,   361,     0,     0,   411,   424,     0,     0,   426,
     487,   492,   478,   479,   500,   514,   515,   508,   507,   482,
     483,   516,   495,   486,   484,   485,   490,   491,   480,   489,
     488,   505,   512,   513,   511,   501,   499,   502,   506,   517,
     503,   504,   497,   498,   509,   510,   494,   493,   496,   481,
       0,     0,     0,     0,     0,     0,   269,     0,     0,   402,
       0,     0,     0,   264,   260,   263,   243,    56,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,   298,   585,   582,   583,   584,
     589,   588,   586,   587,    82,    79,    85,    78,    83,    84,
      77,    81,    80,    75,    76,     0,     0,   339,   124,     0,
       0,     0,   136,     0,   128,   129,   131,   130,     0,     0,
       0,     0,   106,   313,     0,     0,     0,   315,    33,   231,
     232,   241,   240,     0,   239,   227,   235,   228,   234,   223,
     233,   226,   225,   224,    43,    44,    45,    46,    47,    48,
      49,    41,   229,     0,   230,   386,   389,   390,   400,   397,
     381,   398,   395,   396,     0,   394,   399,   380,   388,   383,
     385,   384,   382,   387,   417,   418,   432,   433,   281,   282,
     291,   287,   288,   290,   295,   292,   293,   294,   289,     0,
     286,   280,   296,   279,   409,   408,   267,   266,   251,   252,
     249,   250,   248,     0,   247,     0,     0,     0,   103,   104,
     168,   165,   190,     0,   201,   177,   186,     0,   175,   180,
       0,   195,     0,   189,   193,   199,   179,   182,   191,   192,
     196,   187,   194,   183,   200,   185,   181,   184,     0,   173,
     161,   163,   169,   166,   167,   162,   164,   307,   305,   306,
     345,   350,   356,   359,   352,   358,   353,   357,   355,   351,
     354,     0,   349,   132,     0,     0,     0,     0,   127,   115,
     114,   116,   117,   322,   328,   334,   337,   330,   336,   331,
     335,   333,   329,   332,     0,   327,   323,   237,     0,    42,
     392,     0,   284,     0,   245,     0,   265,   262,   261,     0,
       0,     0,     0,     0,     0,     0,     0,   171,     0,   347,
       0,     0,     0,     0,     0,   126,   325,     0,   238,   393,
     285,   246,   203,   176,   198,   174,   202,   197,   188,   178,
     172,   348,   133,   135,   134,   144,   143,   139,   141,   145,
     142,   138,   140,     0,   326,   137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -648,  -648,  -648,  -307,  -648,    64,  -628,  -648,  -139,  -647,
    -648,  -648,   883,  -648,  -648,   231,  -648,  -648,   605,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,   869,  -648,  -648,  -648,  -648,  -648,  -648,   493,
    -648,  -648,  -648,  -648,  -648,   421,  -648,  -648,  -648,  -648,
    -648,  -648,   852,  -648,  -648,  -648,  -648,   110,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   450,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -170,
    -648,  -648,  -648,   763,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
     -64,  -648,  -648,  -648,  -648,  -648,   -73,  -648,   603,  -648,
    -648,  -648,    20,  -648,  -648,  -648,  -648,  -648,   641,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   -65,  -648,  -648,  -648,
    -648,   564,  -648,  -648,  -648,  -648,  -648,   792,  -648,  -648,
    -648,  -648,   503,  -648,  -648,  -648,  -648,  -648,   -87,  -648,
    -648,  -648,   534,  -648,  -648,  -648,  -648,   -78,  -648,  -648,
    -648,   775,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,   -57,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,   624,  -648,  -648,  -648,  -648,  -648,   707,
    -648,  -648,  -648,  -648,   951,  -648,  -648,  -648,  -648,   708,
    -648,  -648,  -648,  -648,   908,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,   966,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   993,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,   855,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    28,   597,   598,   805,   835,   836,  1011,   923,
      29,    30,    68,   235,   489,   490,    31,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
      32,    84,    85,    86,    87,    88,    33,    70,   496,   497,
     498,   499,    34,    77,   573,   574,   575,   576,   577,   578,
      35,   287,   288,   289,   290,   291,   973,   974,   975,   976,
     977,  1126,  1203,    36,    71,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   736,  1098,  1099,
      37,    57,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   617,   993,
     994,    38,    66,   481,   723,  1063,  1064,   482,   483,   484,
    1067,   924,   925,   485,   486,    39,    64,   461,   462,   463,
     464,   465,   466,   467,   710,  1049,  1050,   468,    40,    72,
     527,   528,   529,   530,   531,    41,   295,   296,   297,    42,
      79,   586,   587,   588,   589,   590,   792,  1144,  1145,    43,
      75,   559,   560,   561,   562,   775,  1121,  1122,    44,    59,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   645,  1024,  1025,   391,   392,   393,   394,
      45,    65,   472,   473,   474,   475,    46,    60,   398,   399,
     400,   401,    47,   144,   145,   146,    48,    62,   408,   409,
     410,   411,    49,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,    50,   132,   133,   134,   135,
     136,   137,   138,   139,    51,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    52,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     837,   856,   601,   602,   603,  1022,   605,   606,   293,   142,
     240,   142,  1172,  1147,   395,    53,    54,  1148,   285,   991,
     800,   801,   802,   803,   804,   476,   285,  1150,  1152,   405,
      55,  1151,  1153,  1154,   293,   487,   488,  1155,  1167,   834,
     493,   582,  1168,   395,   523,   148,   493,   846,   847,   469,
     149,   150,   241,   151,   152,  1169,    56,    58,   469,  1170,
     242,   243,   244,   153,   405,   245,   246,   582,   125,   556,
     247,   248,    61,    63,  1176,   154,   155,   500,  1177,   556,
      67,   143,    69,   143,   156,   157,   396,   477,   158,   159,
      73,   126,   127,   524,    74,   992,    76,   478,   567,   479,
      78,   124,   501,   140,   141,   969,   667,   147,   669,   670,
     160,   672,   161,   231,   128,   396,   677,   232,   679,   233,
     234,    80,   294,   162,   502,   686,   163,   164,    89,   494,
     237,   692,   693,   525,   695,   494,   165,   166,   238,   239,
     701,   702,   703,   406,   167,   168,   323,   169,   294,   170,
     397,   503,   969,   171,   172,   583,   284,   292,    81,   480,
      90,    91,   568,   454,   298,   407,    82,   324,   325,    92,
     173,   299,   174,   175,   176,   300,   301,   177,   406,   397,
     526,   583,   178,   557,  1023,   470,   302,  -125,   455,   129,
     305,   504,   306,   557,   470,  -125,    93,    94,    95,    96,
     407,   179,   180,   307,   308,   181,   182,   505,   309,   495,
     456,    97,    98,    99,   130,   495,   310,   259,   568,   970,
     326,   100,   101,   102,   286,   103,   104,   754,   540,   403,
     131,   311,   286,   105,   362,    83,   363,   457,   364,   183,
     184,   327,   328,   725,   565,   584,   185,   186,   585,   329,
     312,   260,   580,   330,   261,   187,   471,   188,   731,   365,
     331,   658,   750,   452,   506,   471,   970,   718,   332,   333,
     334,   584,   313,   558,   585,   507,   569,   508,   454,   335,
     262,   366,   664,   558,   509,   794,   360,   776,   510,   971,
     314,   315,   263,   458,   316,   744,   367,   317,   368,   336,
     318,   523,   319,   455,   320,   354,    80,   355,   369,   972,
     356,   357,   826,   358,   828,   476,   359,   402,   264,   833,
     370,   459,   412,  1127,   337,   456,   413,   570,  1058,   414,
     265,   266,   569,   415,   267,   268,   971,  1059,   571,   303,
     491,   416,   857,    81,   417,   860,   321,   572,   371,   418,
     524,    82,   457,   419,   420,   421,   972,  1060,   422,   423,
     424,   425,   426,   427,   629,   595,   148,   428,   372,   429,
     460,   149,   150,   430,   151,   152,   431,   477,   125,   373,
     786,   714,   500,   570,   153,   432,   374,   478,   259,   479,
     525,   433,   434,   435,   571,   436,   154,   155,   375,   437,
     438,   126,   127,   572,   439,   156,   157,   501,   458,   158,
     159,   440,   441,   442,   269,   443,   270,   444,  1156,   445,
      83,   446,   260,   447,   128,   261,   448,   449,   450,   502,
     376,   160,   377,   161,   451,   554,   459,   526,   492,   532,
     591,   533,   534,   535,   162,   536,   537,   163,   164,   480,
    1040,   262,   654,   542,   538,  1072,   503,   165,   166,   539,
     543,   544,  1073,   263,   545,   167,   168,   546,   169,   547,
     170,   548,   549,   550,   171,   172,   551,   552,   553,  1041,
    1074,  1075,  1061,   563,   564,   460,   579,   592,  1062,   264,
    1076,   173,   593,   174,   175,   176,   504,  1173,   177,   129,
     594,   265,   266,   178,   596,   267,   268,   599,   600,   604,
     607,  1042,   505,  1004,  1005,  1006,  1007,  1008,  1009,  1010,
     608,   609,   179,   180,   130,   610,   181,   182,  1077,  1078,
     613,  1079,   362,   611,   363,   612,   364,   614,   631,  1195,
     131,  1196,   615,   616,   618,   619,  1043,  1044,   620,   621,
     622,  1045,   623,   624,   625,   626,   627,   365,  1080,   628,
     183,   184,  1081,   632,   633,   634,   635,   185,   186,   506,
     636,  1082,   639,   637,   638,  1046,   187,   640,   188,   366,
     507,   641,   508,   642,   643,   269,   644,   270,  1197,   509,
    1083,   646,  1084,   510,   367,  1085,   368,   661,     2,     3,
     647,   660,     4,   648,   649,  1198,   369,   666,   650,   651,
    1111,  1086,   652,   653,   656,   657,   662,   323,   370,     5,
    1087,   663,  1088,  1047,     6,  1089,     7,  1090,     8,  1199,
    1200,  1091,   668,   671,  1092,     9,   673,   674,   324,   325,
    1093,   675,  1094,  1095,   676,  1048,   371,   678,    10,   680,
     681,   682,    11,    12,   683,   684,   685,  1096,   687,   691,
     694,   688,   689,  1134,   690,  1097,   372,   696,   698,  1201,
     699,   697,    13,   700,  1112,  1202,    14,   373,   704,   705,
     708,   706,   707,  1065,   374,   720,    15,    16,   709,   711,
     712,   326,   713,   727,  1113,   716,   375,   717,   721,  1114,
     722,   724,   729,   728,  1115,   733,   730,   755,   734,   735,
      17,    18,   327,   328,   737,   738,   739,   740,   741,  1116,
     329,  1117,  1118,    89,   330,    19,   742,  1135,   376,   743,
     377,   331,   746,   747,   752,   748,  1119,   749,   753,   332,
     333,   334,    20,   756,  1120,   757,   758,  1136,   759,   761,
     335,   760,  1137,    21,    22,    90,    91,  1138,   762,   763,
     765,   764,   766,   767,    92,    23,   768,   769,   774,   770,
     336,   771,  1139,    24,  1140,  1141,    25,   772,   773,   778,
      26,   240,    27,   782,   779,   780,   781,   783,   788,  1142,
     784,    93,    94,    95,    96,   337,   785,  1143,   789,   790,
    1066,  1186,   791,   807,   793,   796,    97,    98,    99,   797,
     798,   799,   806,   808,   809,   810,   100,   101,   102,   811,
     103,   104,   812,   241,   813,   814,   815,   816,   105,   817,
     818,   242,   243,   244,   824,   819,   245,   246,   820,   821,
     822,   247,   248,   823,   825,   827,   829,   838,   830,   831,
     832,   834,   849,   839,   840,   841,   842,   843,   844,   845,
     848,   850,   851,  1159,   853,   854,   858,   852,   855,   859,
     861,   988,   863,   862,  1149,   864,   555,   912,   865,   866,
     867,   868,   922,   933,   869,   870,   871,   872,   873,   874,
     875,   876,   877,   878,   879,   880,   881,   882,   883,   884,
     885,   886,   887,   888,   889,   890,   891,   892,   893,   894,
     895,   896,   897,   898,   899,   900,   901,   902,   903,   904,
     905,   906,   907,   908,   909,   910,   911,   913,   914,   915,
     932,   917,   916,   918,   919,   920,   921,   938,   966,   926,
     928,   929,  1182,   931,   930,   934,   935,   936,   985,   937,
     939,   940,   236,   304,   942,   941,   943,   944,   927,  1124,
     945,   745,   946,   947,   948,   949,   950,   951,   952,   953,
     954,   955,   956,   957,   958,   959,   960,   961,   962,   963,
     964,   965,   967,   978,   968,   979,   980,   981,  1125,   732,
     982,   983,   984,   986,   787,  1160,   987,   989,  1190,   990,
     995,   996,   997,   998,   999,  1000,  1001,  1002,  1003,  1012,
    1013,  1183,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1051,  1052,  1053,  1054,  1055,  1056,
    1057,  1068,  1069,  1070,  1071,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1123,  1129,  1130,  1131,
    1132,  1133,  1146,  1158,  1184,  1185,  1187,  1161,  1162,  1163,
    1164,  1165,  1166,  1171,  1174,  1188,  1175,  1189,  1192,  1193,
    1194,  1205,  1181,  1128,  1178,   726,  1157,   581,  1180,   795,
    1204,   751,  1191,   777,  1179,   404,   719,   453,   361,   322,
       0,   630,   715,     0,   541,   659,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   665,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   566,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   655
};

static const yytype_int16 yycheck[] =
{
     628,   648,   309,   310,   311,     8,   313,   314,     1,     1,
       1,     1,   190,   218,     1,   218,   219,   222,     1,    60,
     148,   149,   150,   151,   152,     1,     1,   218,   218,     1,
     223,   222,   222,   218,     1,   142,   143,   222,   218,   217,
       1,     1,   222,     1,     1,     1,     1,   172,   173,     1,
       6,     7,    43,     9,    10,   218,   223,   223,     1,   222,
      51,    52,    53,    19,     1,    56,    57,     1,     1,     1,
      61,    62,   223,   223,   218,    31,    32,     1,   222,     1,
     216,    73,   220,    73,    40,    41,    73,    63,    44,    45,
     223,    24,    25,    50,   223,   136,   223,    73,   170,    75,
     223,   223,    26,   223,   223,     1,   413,   223,   415,   416,
      66,   418,    68,   223,    47,    73,   423,   223,   425,   223,
     221,     1,   115,    79,    48,   432,    82,    83,     1,    90,
     223,   438,   439,    90,   441,    90,    92,    93,   223,   223,
     447,   448,   449,   115,   100,   101,     1,   103,   115,   105,
     137,    75,     1,   109,   110,   115,   223,   223,    38,   135,
      33,    34,     1,     1,   223,   137,    46,    22,    23,    42,
     126,   218,   128,   129,   130,   220,   220,   133,   115,   137,
     137,   115,   138,   115,   187,   137,   220,   170,    26,   122,
     220,   115,   220,   115,   137,   170,    69,    70,    71,    72,
     137,   157,   158,   220,   220,   161,   162,   131,   220,   170,
      48,    84,    85,    86,   147,   170,   220,     1,     1,   115,
      75,    94,    95,    96,   207,    98,    99,   534,   219,   219,
     163,   220,   207,   106,     1,   115,     3,    75,     5,   195,
     196,    96,    97,   219,   219,   205,   202,   203,   208,   104,
     220,    35,   219,   108,    38,   211,   208,   213,   219,    26,
     115,   219,   219,   219,   188,   208,   115,   219,   123,   124,
     125,   205,   220,   205,   208,   199,   115,   201,     1,   134,
      64,    48,   219,   205,   208,   219,   219,   219,   212,   185,
     220,   220,    76,   131,   220,   219,    63,   220,    65,   154,
     220,     1,   220,    26,   220,   220,     1,   220,    75,   205,
     220,   220,   619,   220,   621,     1,   220,   220,   102,   626,
      87,   159,   220,   219,   179,    48,   220,   166,    27,   220,
     114,   115,   115,   220,   118,   119,   185,    36,   177,   219,
     218,   220,   649,    38,   220,   652,   219,   186,   115,   220,
      50,    46,    75,   220,   220,   220,   205,    56,   220,   220,
     220,   220,   220,   220,   219,   217,     1,   220,   135,   220,
     208,     6,     7,   220,     9,    10,   220,    63,     1,   146,
     219,   219,     1,   166,    19,   220,   153,    73,     1,    75,
      90,   220,   220,   220,   177,   220,    31,    32,   165,   220,
     220,    24,    25,   186,   220,    40,    41,    26,   131,    44,
      45,   220,   220,   220,   198,   220,   200,   220,  1065,   220,
     115,   220,    35,   220,    47,    38,   220,   220,   220,    48,
     197,    66,   199,    68,   220,   219,   159,   137,   218,   220,
     216,   220,   220,   220,    79,   220,   220,    82,    83,   135,
      20,    64,   219,   218,   220,     4,    75,    92,    93,   220,
     220,   220,    11,    76,   220,   100,   101,   220,   103,   220,
     105,   220,   220,   220,   109,   110,   220,   220,   220,    49,
      29,    30,   181,   218,   220,   208,   220,   216,   187,   102,
      39,   126,   216,   128,   129,   130,   115,  1125,   133,   122,
     218,   114,   115,   138,   217,   118,   119,   194,   217,   217,
     217,    81,   131,    12,    13,    14,    15,    16,    17,    18,
     217,   217,   157,   158,   147,   217,   161,   162,    77,    78,
     218,    80,     1,   217,     3,   217,     5,   218,   217,    78,
     163,    80,   220,   220,   220,   220,   116,   117,   220,   220,
     220,   121,   220,   220,   220,   220,   220,    26,   107,   220,
     195,   196,   111,   217,   194,   217,   216,   202,   203,   188,
     216,   120,   220,   218,   218,   145,   211,   220,   213,    48,
     199,   220,   201,   220,   220,   198,   220,   200,   127,   208,
     139,   220,   141,   212,    63,   144,    65,   218,     0,     1,
     220,   216,     4,   220,   220,   144,    75,   194,   220,   220,
      80,   160,   220,   220,   220,   220,   220,     1,    87,    21,
     169,   220,   171,   193,    26,   174,    28,   176,    30,   168,
     169,   180,   217,   217,   183,    37,   194,   194,    22,    23,
     189,   217,   191,   192,   217,   215,   115,   194,    50,   217,
     217,   217,    54,    55,   217,   217,   217,   206,   217,   194,
     194,   217,   217,    80,   216,   214,   135,   194,   194,   208,
     194,   217,    74,   217,   144,   214,    78,   146,   194,   217,
     220,   218,   218,   204,   153,   218,    88,    89,   220,   220,
     220,    75,   220,   222,   164,   220,   165,   220,   220,   169,
     220,   220,   220,   218,   174,   218,   220,   216,   220,   220,
     112,   113,    96,    97,   220,   220,   220,   220,   220,   189,
     104,   191,   192,     1,   108,   127,   220,   144,   197,   220,
     199,   115,   218,   220,   194,   220,   206,   220,   194,   123,
     124,   125,   144,   194,   214,   216,   194,   164,   194,   217,
     134,   218,   169,   155,   156,    33,    34,   174,   216,   194,
     217,   216,   216,   216,    42,   167,   216,   216,   220,   216,
     154,   216,   189,   175,   191,   192,   178,   218,   218,   194,
     182,     1,   184,   220,   218,   223,   218,   220,   216,   206,
     220,    69,    70,    71,    72,   179,   220,   214,   218,   218,
     222,    91,   220,   217,   220,   218,    84,    85,    86,   218,
     218,   218,   218,   218,   218,   218,    94,    95,    96,   218,
      98,    99,   218,    43,   218,   218,   218,   218,   106,   218,
     218,    51,    52,    53,   220,   218,    56,    57,   218,   218,
     217,    61,    62,   217,   217,   217,   216,   218,   217,   217,
     217,   217,   194,   218,   218,   218,   218,   218,   218,   216,
     216,   216,   216,   221,   216,   216,   216,   220,   217,   216,
     216,   807,   216,   218,  1013,   216,   271,   220,   218,   218,
     216,   216,   220,   220,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   216,   194,   216,   216,   216,
     194,   216,   218,   216,   218,   216,   216,   194,   220,   218,
     216,   216,    67,   216,   218,   216,   216,   216,   220,   216,
     216,   216,    69,    84,   216,   218,   216,   216,   727,   220,
     218,   511,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   216,   218,   216,   218,   216,   216,   216,   220,   496,
     218,   218,   216,   216,   573,   221,   218,   218,  1168,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     217,   140,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   144,   140,   144,   221,   221,   221,
     221,   221,   221,   216,   220,   140,   218,   140,   218,   218,
     218,   218,  1155,   973,  1148,   482,  1066,   295,  1153,   586,
    1177,   527,  1170,   559,  1151,   144,   472,   189,   132,   106,
      -1,   338,   461,    -1,   249,   398,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   408,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   378
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   225,     0,     1,     4,    21,    26,    28,    30,    37,
      50,    54,    55,    74,    78,    88,    89,   112,   113,   127,
     144,   155,   156,   167,   175,   178,   182,   184,   226,   234,
     235,   240,   254,   260,   266,   274,   287,   304,   325,   339,
     352,   359,   363,   373,   382,   404,   410,   416,   420,   426,
     469,   478,   497,   218,   219,   223,   223,   305,   223,   383,
     411,   223,   421,   223,   340,   405,   326,   216,   236,   220,
     261,   288,   353,   223,   223,   374,   223,   267,   223,   364,
       1,    38,    46,   115,   255,   256,   257,   258,   259,     1,
      33,    34,    42,    69,    70,    71,    72,    84,    85,    86,
      94,    95,    96,    98,    99,   106,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   223,     1,    24,    25,    47,   122,
     147,   163,   470,   471,   472,   473,   474,   475,   476,   477,
     223,   223,     1,    73,   417,   418,   419,   223,     1,     6,
       7,     9,    10,    19,    31,    32,    40,    41,    44,    45,
      66,    68,    79,    82,    83,    92,    93,   100,   101,   103,
     105,   109,   110,   126,   128,   129,   130,   133,   138,   157,
     158,   161,   162,   195,   196,   202,   203,   211,   213,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   223,   223,   223,   221,   237,   236,   223,   223,   223,
       1,    43,    51,    52,    53,    56,    57,    61,    62,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,     1,
      35,    38,    64,    76,   102,   114,   115,   118,   119,   198,
     200,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   223,     1,   207,   275,   276,   277,
     278,   279,   223,     1,   115,   360,   361,   362,   223,   218,
     220,   220,   220,   219,   256,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   219,   480,     1,    22,    23,    75,    96,    97,   104,
     108,   115,   123,   124,   125,   134,   154,   179,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   220,   220,   220,   220,   220,   220,
     219,   471,     1,     3,     5,    26,    48,    63,    65,    75,
      87,   115,   135,   146,   153,   165,   197,   199,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   400,   401,   402,   403,     1,    73,   137,   412,   413,
     414,   415,   220,   219,   418,     1,   115,   137,   422,   423,
     424,   425,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   219,   428,     1,    26,    48,    75,   131,   159,
     208,   341,   342,   343,   344,   345,   346,   347,   351,     1,
     137,   208,   406,   407,   408,   409,     1,    63,    73,    75,
     135,   327,   331,   332,   333,   337,   338,   142,   143,   238,
     239,   218,   218,     1,    90,   170,   262,   263,   264,   265,
       1,    26,    48,    75,   115,   131,   188,   199,   201,   208,
     212,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,     1,    50,    90,   137,   354,   355,   356,
     357,   358,   220,   220,   220,   220,   220,   220,   220,   220,
     219,   499,   218,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   219,   242,     1,   115,   205,   375,
     376,   377,   378,   218,   220,   219,   276,   170,     1,   115,
     166,   177,   186,   268,   269,   270,   271,   272,   273,   220,
     219,   361,     1,   115,   205,   208,   365,   366,   367,   368,
     369,   216,   216,   216,   218,   217,   217,   227,   228,   194,
     217,   227,   227,   227,   217,   227,   227,   217,   217,   217,
     217,   217,   217,   218,   218,   220,   220,   322,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   219,
     307,   217,   217,   194,   217,   216,   216,   218,   218,   220,
     220,   220,   220,   220,   220,   397,   220,   220,   220,   220,
     220,   220,   220,   220,   219,   385,   220,   220,   219,   413,
     216,   218,   220,   220,   219,   423,   194,   227,   217,   227,
     227,   217,   227,   194,   194,   217,   217,   227,   194,   227,
     217,   217,   217,   217,   217,   217,   227,   217,   217,   217,
     216,   194,   227,   227,   194,   227,   194,   217,   194,   194,
     217,   227,   227,   227,   194,   217,   218,   218,   220,   220,
     348,   220,   220,   220,   219,   342,   220,   220,   219,   407,
     218,   220,   220,   328,   220,   219,   332,   222,   218,   220,
     220,   219,   263,   218,   220,   220,   301,   220,   220,   220,
     220,   220,   220,   220,   219,   290,   218,   220,   220,   220,
     219,   355,   194,   194,   227,   216,   194,   216,   194,   194,
     218,   217,   216,   194,   216,   217,   216,   216,   216,   216,
     216,   216,   218,   218,   220,   379,   219,   376,   194,   218,
     223,   218,   220,   220,   220,   220,   219,   269,   216,   218,
     218,   220,   370,   220,   219,   366,   218,   218,   218,   218,
     148,   149,   150,   151,   152,   229,   218,   217,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   217,   217,   220,   217,   227,   217,   227,   216,
     217,   217,   217,   227,   217,   230,   231,   230,   218,   218,
     218,   218,   218,   218,   218,   216,   172,   173,   216,   194,
     216,   216,   220,   216,   216,   217,   233,   227,   216,   216,
     227,   216,   218,   216,   216,   218,   218,   216,   216,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     216,   194,   220,   216,   216,   216,   218,   216,   216,   218,
     216,   216,   220,   233,   335,   336,   218,   239,   216,   216,
     218,   216,   194,   220,   216,   216,   216,   216,   194,   216,
     216,   218,   216,   216,   216,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   216,   220,   218,   218,     1,
     115,   185,   205,   280,   281,   282,   283,   284,   216,   216,
     216,   216,   218,   218,   216,   220,   216,   218,   229,   218,
     218,    60,   136,   323,   324,   218,   218,   218,   218,   218,
     218,   218,   218,   218,    12,    13,    14,    15,    16,    17,
      18,   232,   218,   217,   218,   218,   218,   218,   218,   218,
     218,   218,     8,   187,   398,   399,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
      20,    49,    81,   116,   117,   121,   145,   193,   215,   349,
     350,   218,   218,   218,   218,   218,   218,   218,    27,    36,
      56,   181,   187,   329,   330,   204,   222,   334,   218,   218,
     218,   218,     4,    11,    29,    30,    39,    77,    78,    80,
     107,   111,   120,   139,   141,   144,   160,   169,   171,   174,
     176,   180,   183,   189,   191,   192,   206,   214,   302,   303,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,    80,   144,   164,   169,   174,   189,   191,   192,   206,
     214,   380,   381,   218,   220,   220,   285,   219,   281,   218,
     218,   218,   218,   218,    80,   144,   164,   169,   174,   189,
     191,   192,   206,   214,   371,   372,   218,   218,   222,   232,
     218,   222,   218,   222,   218,   222,   233,   336,   218,   221,
     221,   221,   221,   221,   221,   221,   221,   218,   222,   218,
     222,   216,   190,   230,   220,   218,   218,   222,   324,   399,
     350,   330,    67,   140,   144,   140,    91,   144,   140,   140,
     303,   381,   218,   218,   218,    78,    80,   127,   144,   168,
     169,   208,   214,   286,   372,   218
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   224,   225,   225,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     227,   227,   228,   228,   229,   229,   229,   229,   229,   230,
     230,   231,   231,   232,   232,   232,   232,   232,   232,   232,
     233,   234,   235,   236,   237,   237,   238,   238,   239,   239,
     240,   241,   241,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   255,   256,
     256,   256,   256,   257,   258,   259,   261,   260,   262,   262,
     263,   263,   263,   264,   265,   267,   266,   268,   268,   269,
     269,   269,   269,   269,   270,   271,   272,   273,   274,   275,
     275,   276,   276,   276,   277,   279,   278,   280,   280,   281,
     281,   281,   281,   282,   283,   283,   285,   284,   286,   286,
     286,   286,   286,   286,   286,   286,   288,   287,   289,   289,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     301,   300,   302,   302,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   305,   304,   306,   306,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   322,   321,   323,   323,
     324,   324,   326,   325,   328,   327,   329,   329,   330,   330,
     330,   330,   330,   331,   331,   332,   332,   332,   332,   332,
     334,   333,   335,   335,   336,   336,   337,   338,   340,   339,
     341,   341,   342,   342,   342,   342,   342,   342,   342,   343,
     344,   345,   346,   348,   347,   349,   349,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   351,   353,   352,   354,
     354,   355,   355,   355,   355,   356,   357,   358,   359,   360,
     360,   361,   361,   362,   364,   363,   365,   365,   366,   366,
     366,   366,   367,   368,   370,   369,   371,   371,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   374,   373,
     375,   375,   376,   376,   376,   377,   379,   378,   380,   380,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     383,   382,   384,   384,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     395,   397,   396,   398,   398,   399,   399,   400,   401,   402,
     403,   405,   404,   406,   406,   407,   407,   407,   408,   409,
     411,   410,   412,   412,   413,   413,   413,   414,   415,   416,
     417,   417,   418,   418,   419,   421,   420,   422,   422,   423,
     423,   423,   424,   425,   426,   427,   427,   428,   428,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     470,   471,   471,   471,   471,   471,   471,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   479,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   498,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   500,   501,   502,   503,   504,   505,   506,   507
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     1,     0,     2,     3,     1,     1,     1,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     2,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     2,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     0,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     3,     3,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     0,     6,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       0,     5,     3,     1,     1,     3,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     5,     2,
       1,     1,     1,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     2,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     4,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
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
  switch (yykind)
    {
    case YYSYMBOL_module_string: /* module_string  */
#line 364 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3153 "conf_parser.c"
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
  case 30: /* timespec: NUMBER  */
#line 401 "conf_parser.y"
{
  if ((yyvsp[0].number) != 0)
  {
    yyerror("Nonzero durations require a unit");
    YYERROR;
  }

  (yyval.number) = 0;
}
#line 3434 "conf_parser.c"
    break;

  case 32: /* time_components: NUMBER time_unit  */
#line 412 "conf_parser.y"
{
  if (!_conf_parser_quantity_add(0, (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Duration out of range");
    YYERROR;
  }
}
#line 3446 "conf_parser.c"
    break;

  case 33: /* time_components: time_components NUMBER time_unit  */
#line 419 "conf_parser.y"
{
  if (!_conf_parser_quantity_add((yyvsp[-2].number), (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Duration out of range");
    YYERROR;
  }
}
#line 3458 "conf_parser.c"
    break;

  case 34: /* time_unit: SECONDS  */
#line 427 "conf_parser.y"
                   { (yyval.number) = 1U; }
#line 3464 "conf_parser.c"
    break;

  case 35: /* time_unit: MINUTES  */
#line 428 "conf_parser.y"
                   { (yyval.number) = 60U; }
#line 3470 "conf_parser.c"
    break;

  case 36: /* time_unit: HOURS  */
#line 429 "conf_parser.y"
                   { (yyval.number) = 60U * 60U; }
#line 3476 "conf_parser.c"
    break;

  case 37: /* time_unit: DAYS  */
#line 430 "conf_parser.y"
                   { (yyval.number) = 60U * 60U * 24U; }
#line 3482 "conf_parser.c"
    break;

  case 38: /* time_unit: WEEKS  */
#line 431 "conf_parser.y"
                   { (yyval.number) = 60U * 60U * 24U * 7U; }
#line 3488 "conf_parser.c"
    break;

  case 39: /* sizespec: NUMBER  */
#line 435 "conf_parser.y"
{
  if ((yyvsp[0].number) != 0)
  {
    yyerror("Nonzero sizes require a unit");
    YYERROR;
  }

  (yyval.number) = 0;
}
#line 3502 "conf_parser.c"
    break;

  case 41: /* size_components: NUMBER size_unit  */
#line 446 "conf_parser.y"
{
  if (!_conf_parser_quantity_add(0, (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Size out of range");
    YYERROR;
  }
}
#line 3514 "conf_parser.c"
    break;

  case 42: /* size_components: size_components NUMBER size_unit  */
#line 453 "conf_parser.y"
{
  if (!_conf_parser_quantity_add((yyvsp[-2].number), (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Size out of range");
    YYERROR;
  }
}
#line 3526 "conf_parser.c"
    break;

  case 43: /* size_unit: BYTES  */
#line 461 "conf_parser.y"
                   { (yyval.number) = 1U; }
#line 3532 "conf_parser.c"
    break;

  case 44: /* size_unit: KBYTES  */
#line 462 "conf_parser.y"
                   { (yyval.number) = 1000U; }
#line 3538 "conf_parser.c"
    break;

  case 45: /* size_unit: KIBYTES  */
#line 463 "conf_parser.y"
                   { (yyval.number) = 1024U; }
#line 3544 "conf_parser.c"
    break;

  case 46: /* size_unit: MBYTES  */
#line 464 "conf_parser.y"
                   { (yyval.number) = 1000U * 1000U; }
#line 3550 "conf_parser.c"
    break;

  case 47: /* size_unit: MIBYTES  */
#line 465 "conf_parser.y"
                   { (yyval.number) = 1024U * 1024U; }
#line 3556 "conf_parser.c"
    break;

  case 48: /* size_unit: GBYTES  */
#line 466 "conf_parser.y"
                   { (yyval.number) = 1000U * 1000U * 1000U; }
#line 3562 "conf_parser.c"
    break;

  case 49: /* size_unit: GIBYTES  */
#line 467 "conf_parser.y"
                   { (yyval.number) = 1024U * 1024U * 1024U; }
#line 3568 "conf_parser.c"
    break;

  case 50: /* port_number: NUMBER  */
#line 471 "conf_parser.y"
{
  if ((yyvsp[0].number) > UINT16_MAX)
  {
    yyerror("Port out of range");
    YYERROR;
  }

  (yyval.number) = (yyvsp[0].number);
}
#line 3582 "conf_parser.c"
    break;

  case 51: /* module_base_path_entry: MODULE_BASE_PATH '=' module_string ';'  */
#line 486 "conf_parser.y"
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
#line 3599 "conf_parser.c"
    break;

  case 52: /* loadmodule_entry: LOADMODULE module_string module_attributes ';'  */
#line 504 "conf_parser.y"
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
#line 3616 "conf_parser.c"
    break;

  case 53: /* module_string: QSTRING  */
#line 519 "conf_parser.y"
{
  (yyval.string) = io_strdup((yyvsp[0].string));
}
#line 3624 "conf_parser.c"
    break;

  case 54: /* module_attributes: %empty  */
#line 524 "conf_parser.y"
{
  (yyval.number) = 0;
}
#line 3632 "conf_parser.c"
    break;

  case 55: /* module_attributes: ':' module_attributes_items  */
#line 527 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3640 "conf_parser.c"
    break;

  case 56: /* module_attributes_items: module_attributes_items ',' module_attributes_item  */
#line 532 "conf_parser.y"
{
  (yyval.number) = (yyvsp[-2].number) | (yyvsp[0].number);
}
#line 3648 "conf_parser.c"
    break;

  case 57: /* module_attributes_items: module_attributes_item  */
#line 535 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3656 "conf_parser.c"
    break;

  case 58: /* module_attributes_item: RESIDENT  */
#line 540 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_DEACTIVATE;
}
#line 3664 "conf_parser.c"
    break;

  case 59: /* module_attributes_item: REQUIRED  */
#line 543 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_REMOVE;
}
#line 3672 "conf_parser.c"
    break;

  case 75: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 569 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3684 "conf_parser.c"
    break;

  case 76: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 578 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3696 "conf_parser.c"
    break;

  case 77: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 587 "conf_parser.y"
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
#line 3714 "conf_parser.c"
    break;

  case 78: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 602 "conf_parser.y"
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
#line 3732 "conf_parser.c"
    break;

  case 79: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 617 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3745 "conf_parser.c"
    break;

  case 80: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 627 "conf_parser.y"
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
#line 3762 "conf_parser.c"
    break;

  case 81: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 641 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3774 "conf_parser.c"
    break;

  case 82: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 650 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 1)
  {
    conf_error_report("default_max_clients too low, setting to 1");
    ConfigServerInfo.default_max_clients = 1;
  }
  else if ((yyvsp[-1].number) > (unsigned int)MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "default_max_clients too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);

    ConfigServerInfo.default_max_clients = (unsigned int)MAXCLIENTS_MAX;
  }
  else
    ConfigServerInfo.default_max_clients = (yyvsp[-1].number);
}
#line 3800 "conf_parser.c"
    break;

  case 83: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 673 "conf_parser.y"
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
#line 3826 "conf_parser.c"
    break;

  case 84: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 696 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3838 "conf_parser.c"
    break;

  case 85: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 705 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3847 "conf_parser.c"
    break;

  case 93: /* admin_name: NAME '=' QSTRING ';'  */
#line 723 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3859 "conf_parser.c"
    break;

  case 94: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 732 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3871 "conf_parser.c"
    break;

  case 95: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 741 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3883 "conf_parser.c"
    break;

  case 96: /* $@1: %empty  */
#line 754 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3892 "conf_parser.c"
    break;

  case 97: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 758 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3909 "conf_parser.c"
    break;

  case 103: /* motd_mask: MASK '=' QSTRING ';'  */
#line 775 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3918 "conf_parser.c"
    break;

  case 104: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 781 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3927 "conf_parser.c"
    break;

  case 105: /* $@2: %empty  */
#line 791 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3936 "conf_parser.c"
    break;

  case 106: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 795 "conf_parser.y"
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
#line 3954 "conf_parser.c"
    break;

  case 114: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 813 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3963 "conf_parser.c"
    break;

  case 115: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 819 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3972 "conf_parser.c"
    break;

  case 116: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 825 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3981 "conf_parser.c"
    break;

  case 117: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 831 "conf_parser.y"
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
#line 4003 "conf_parser.c"
    break;

  case 124: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 860 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 4015 "conf_parser.c"
    break;

  case 125: /* $@3: %empty  */
#line 869 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4024 "conf_parser.c"
    break;

  case 126: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 873 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 4037 "conf_parser.c"
    break;

  case 133: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 889 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 4048 "conf_parser.c"
    break;

  case 134: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 897 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 4056 "conf_parser.c"
    break;

  case 135: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 900 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 4064 "conf_parser.c"
    break;

  case 136: /* $@4: %empty  */
#line 905 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 4073 "conf_parser.c"
    break;

  case 138: /* logging_file_type_item: USER  */
#line 911 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4082 "conf_parser.c"
    break;

  case 139: /* logging_file_type_item: OPERATOR  */
#line 915 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4091 "conf_parser.c"
    break;

  case 140: /* logging_file_type_item: XLINE  */
#line 919 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4100 "conf_parser.c"
    break;

  case 141: /* logging_file_type_item: RESV  */
#line 923 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4109 "conf_parser.c"
    break;

  case 142: /* logging_file_type_item: T_DLINE  */
#line 927 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4118 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: KLINE  */
#line 931 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4127 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: KILL  */
#line 935 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4136 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: T_DEBUG  */
#line 939 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4145 "conf_parser.c"
    break;

  case 146: /* $@5: %empty  */
#line 949 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4157 "conf_parser.c"
    break;

  case 147: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 956 "conf_parser.y"
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
#line 4215 "conf_parser.c"
    break;

  case 161: /* oper_name: NAME '=' QSTRING ';'  */
#line 1024 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4224 "conf_parser.c"
    break;

  case 162: /* oper_user: USER '=' QSTRING ';'  */
#line 1030 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4233 "conf_parser.c"
    break;

  case 163: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1036 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4242 "conf_parser.c"
    break;

  case 164: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1042 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4251 "conf_parser.c"
    break;

  case 165: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1048 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4265 "conf_parser.c"
    break;

  case 166: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1059 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4274 "conf_parser.c"
    break;

  case 167: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1065 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4288 "conf_parser.c"
    break;

  case 168: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1076 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4297 "conf_parser.c"
    break;

  case 169: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1082 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4306 "conf_parser.c"
    break;

  case 170: /* $@6: %empty  */
#line 1088 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4315 "conf_parser.c"
    break;

  case 174: /* oper_flags_item: KILL ':' REMOTE  */
#line 1095 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4324 "conf_parser.c"
    break;

  case 175: /* oper_flags_item: KILL  */
#line 1099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4333 "conf_parser.c"
    break;

  case 176: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1103 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4342 "conf_parser.c"
    break;

  case 177: /* oper_flags_item: CONNECT  */
#line 1107 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4351 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1111 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4360 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: SQUIT  */
#line 1115 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4369 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: KLINE  */
#line 1119 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4378 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: UNKLINE  */
#line 1123 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4387 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: T_DLINE  */
#line 1127 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4396 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: T_UNDLINE  */
#line 1131 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4405 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: XLINE  */
#line 1135 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4414 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: T_UNXLINE  */
#line 1139 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4423 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: DIE  */
#line 1143 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4432 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_RESTART  */
#line 1147 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4441 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1151 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4450 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: REHASH  */
#line 1155 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4459 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: ADMIN  */
#line 1159 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4468 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_GLOBOPS  */
#line 1163 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4477 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: T_LOCOPS  */
#line 1167 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4486 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REMOTEBAN  */
#line 1171 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4495 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: T_SET  */
#line 1175 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4504 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: MODULE  */
#line 1179 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4513 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_OPME  */
#line 1183 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4522 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: NICK ':' RESV  */
#line 1187 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4531 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: JOIN ':' RESV  */
#line 1191 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4540 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: RESV  */
#line 1195 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4549 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: T_UNRESV  */
#line 1199 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4558 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: CLOSE  */
#line 1203 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4567 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1207 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4576 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: BYPASS ':' INPUT_FLOOD  */
#line 1211 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_BYPASS_INPUT_FLOOD;
}
#line 4585 "conf_parser.c"
    break;

  case 204: /* $@7: %empty  */
#line 1221 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4600 "conf_parser.c"
    break;

  case 205: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1231 "conf_parser.y"
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
#line 4647 "conf_parser.c"
    break;

  case 223: /* class_name: NAME '=' QSTRING ';'  */
#line 1292 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4656 "conf_parser.c"
    break;

  case 224: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1298 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4665 "conf_parser.c"
    break;

  case 225: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1304 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4674 "conf_parser.c"
    break;

  case 226: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1310 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4683 "conf_parser.c"
    break;

  case 227: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1316 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4692 "conf_parser.c"
    break;

  case 228: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1322 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4701 "conf_parser.c"
    break;

  case 229: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1328 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4710 "conf_parser.c"
    break;

  case 230: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1334 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4720 "conf_parser.c"
    break;

  case 231: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1341 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4729 "conf_parser.c"
    break;

  case 232: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1347 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4738 "conf_parser.c"
    break;

  case 233: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1353 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4747 "conf_parser.c"
    break;

  case 234: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1359 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4759 "conf_parser.c"
    break;

  case 235: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1368 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4771 "conf_parser.c"
    break;

  case 236: /* $@8: %empty  */
#line 1377 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4780 "conf_parser.c"
    break;

  case 240: /* class_flags_item: RANDOM_IDLE  */
#line 1384 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4789 "conf_parser.c"
    break;

  case 241: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1388 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4798 "conf_parser.c"
    break;

  case 242: /* $@9: %empty  */
#line 1398 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4807 "conf_parser.c"
    break;

  case 244: /* $@10: %empty  */
#line 1404 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4815 "conf_parser.c"
    break;

  case 248: /* listen_flags_item: T_TLS  */
#line 1410 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4824 "conf_parser.c"
    break;

  case 249: /* listen_flags_item: HIDDEN  */
#line 1414 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4833 "conf_parser.c"
    break;

  case 250: /* listen_flags_item: T_SERVER  */
#line 1418 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4842 "conf_parser.c"
    break;

  case 251: /* listen_flags_item: CLIENT  */
#line 1422 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4851 "conf_parser.c"
    break;

  case 252: /* listen_flags_item: DEFER  */
#line 1426 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4860 "conf_parser.c"
    break;

  case 260: /* $@11: %empty  */
#line 1434 "conf_parser.y"
                                 { reset_block_state(); }
#line 4866 "conf_parser.c"
    break;

  case 264: /* port_item: port_number  */
#line 1439 "conf_parser.y"
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
    listener_add((uint16_t)(yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4884 "conf_parser.c"
    break;

  case 265: /* port_item: port_number TWODOTS port_number  */
#line 1452 "conf_parser.y"
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

    for (unsigned int port = (yyvsp[-2].number); port <= (yyvsp[0].number); ++port)
      listener_add((uint16_t)port, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4904 "conf_parser.c"
    break;

  case 266: /* listen_address: IP '=' QSTRING ';'  */
#line 1469 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4913 "conf_parser.c"
    break;

  case 267: /* listen_host: HOST '=' QSTRING ';'  */
#line 1475 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4922 "conf_parser.c"
    break;

  case 268: /* $@12: %empty  */
#line 1485 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4931 "conf_parser.c"
    break;

  case 269: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1489 "conf_parser.y"
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
#line 4986 "conf_parser.c"
    break;

  case 279: /* auth_user: USER '=' QSTRING ';'  */
#line 1550 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4995 "conf_parser.c"
    break;

  case 280: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1556 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5004 "conf_parser.c"
    break;

  case 281: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1562 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5013 "conf_parser.c"
    break;

  case 282: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1568 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5027 "conf_parser.c"
    break;

  case 283: /* $@13: %empty  */
#line 1579 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 5036 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: EXCEED_LIMIT  */
#line 1587 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 5045 "conf_parser.c"
    break;

  case 288: /* auth_flags_item: KLINE_EXEMPT  */
#line 1591 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 5054 "conf_parser.c"
    break;

  case 289: /* auth_flags_item: XLINE_EXEMPT  */
#line 1595 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 5063 "conf_parser.c"
    break;

  case 290: /* auth_flags_item: NEED_IDENT  */
#line 1599 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 5072 "conf_parser.c"
    break;

  case 291: /* auth_flags_item: CAN_FLOOD  */
#line 1603 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 5081 "conf_parser.c"
    break;

  case 292: /* auth_flags_item: NO_TILDE  */
#line 1607 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 5090 "conf_parser.c"
    break;

  case 293: /* auth_flags_item: RESV_EXEMPT  */
#line 1611 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 5099 "conf_parser.c"
    break;

  case 294: /* auth_flags_item: T_WEBIRC  */
#line 1615 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5108 "conf_parser.c"
    break;

  case 295: /* auth_flags_item: NEED_PASSWORD  */
#line 1619 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5117 "conf_parser.c"
    break;

  case 296: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1625 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    log_write(LOG_TYPE_IRCD,
              "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 5132 "conf_parser.c"
    break;

  case 297: /* $@14: %empty  */
#line 1640 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5144 "conf_parser.c"
    break;

  case 298: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1647 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5155 "conf_parser.c"
    break;

  case 305: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5164 "conf_parser.c"
    break;

  case 306: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1664 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5173 "conf_parser.c"
    break;

  case 307: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1670 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5182 "conf_parser.c"
    break;

  case 313: /* service_name: NAME '=' QSTRING ';'  */
#line 1685 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5197 "conf_parser.c"
    break;

  case 314: /* $@15: %empty  */
#line 1701 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5213 "conf_parser.c"
    break;

  case 315: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1712 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5228 "conf_parser.c"
    break;

  case 322: /* shared_name: NAME '=' QSTRING ';'  */
#line 1727 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5237 "conf_parser.c"
    break;

  case 323: /* shared_user: USER '=' QSTRING ';'  */
#line 1733 "conf_parser.y"
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
#line 5259 "conf_parser.c"
    break;

  case 324: /* $@16: %empty  */
#line 1752 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5268 "conf_parser.c"
    break;

  case 328: /* shared_type_item: KLINE  */
#line 1759 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5277 "conf_parser.c"
    break;

  case 329: /* shared_type_item: UNKLINE  */
#line 1763 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5286 "conf_parser.c"
    break;

  case 330: /* shared_type_item: T_DLINE  */
#line 1767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5295 "conf_parser.c"
    break;

  case 331: /* shared_type_item: T_UNDLINE  */
#line 1771 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5304 "conf_parser.c"
    break;

  case 332: /* shared_type_item: XLINE  */
#line 1775 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5313 "conf_parser.c"
    break;

  case 333: /* shared_type_item: T_UNXLINE  */
#line 1779 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5322 "conf_parser.c"
    break;

  case 334: /* shared_type_item: RESV  */
#line 1783 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5331 "conf_parser.c"
    break;

  case 335: /* shared_type_item: T_UNRESV  */
#line 1787 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5340 "conf_parser.c"
    break;

  case 336: /* shared_type_item: T_LOCOPS  */
#line 1791 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5349 "conf_parser.c"
    break;

  case 337: /* shared_type_item: T_ALL  */
#line 1795 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5358 "conf_parser.c"
    break;

  case 338: /* $@17: %empty  */
#line 1805 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5372 "conf_parser.c"
    break;

  case 339: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1814 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5385 "conf_parser.c"
    break;

  case 345: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1827 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5394 "conf_parser.c"
    break;

  case 346: /* $@18: %empty  */
#line 1833 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5403 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: KLINE  */
#line 1840 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5412 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: UNKLINE  */
#line 1844 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5421 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: T_DLINE  */
#line 1848 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5430 "conf_parser.c"
    break;

  case 353: /* cluster_type_item: T_UNDLINE  */
#line 1852 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5439 "conf_parser.c"
    break;

  case 354: /* cluster_type_item: XLINE  */
#line 1856 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5448 "conf_parser.c"
    break;

  case 355: /* cluster_type_item: T_UNXLINE  */
#line 1860 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5457 "conf_parser.c"
    break;

  case 356: /* cluster_type_item: RESV  */
#line 1864 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5466 "conf_parser.c"
    break;

  case 357: /* cluster_type_item: T_UNRESV  */
#line 1868 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5475 "conf_parser.c"
    break;

  case 358: /* cluster_type_item: T_LOCOPS  */
#line 1872 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5484 "conf_parser.c"
    break;

  case 359: /* cluster_type_item: T_ALL  */
#line 1876 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5493 "conf_parser.c"
    break;

  case 360: /* $@19: %empty  */
#line 1886 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECT_DEFAULT_TIMEOUT_SEC;
  block_state.retry_delay_sec.value = CONNECT_DEFAULT_RETRY_DELAY_SEC;
}
#line 5508 "conf_parser.c"
    break;

  case 361: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1896 "conf_parser.y"
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

  connect->port = (uint16_t)block_state.port.value;
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
#line 5557 "conf_parser.c"
    break;

  case 380: /* connect_name: NAME '=' QSTRING ';'  */
#line 1960 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5566 "conf_parser.c"
    break;

  case 381: /* connect_host: HOST '=' QSTRING ';'  */
#line 1966 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5575 "conf_parser.c"
    break;

  case 382: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1972 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5584 "conf_parser.c"
    break;

  case 383: /* connect_retry_delay: RETRY_DELAY '=' timespec ';'  */
#line 1978 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.retry_delay_sec.value = (yyvsp[-1].number);
}
#line 5593 "conf_parser.c"
    break;

  case 384: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 1984 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5602 "conf_parser.c"
    break;

  case 385: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 1990 "conf_parser.y"
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
#line 5618 "conf_parser.c"
    break;

  case 386: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2003 "conf_parser.y"
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
#line 5634 "conf_parser.c"
    break;

  case 387: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2016 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5643 "conf_parser.c"
    break;

  case 388: /* connect_port: PORT '=' port_number ';'  */
#line 2022 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5652 "conf_parser.c"
    break;

  case 389: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2028 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5661 "conf_parser.c"
    break;

  case 390: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2032 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5670 "conf_parser.c"
    break;

  case 391: /* $@20: %empty  */
#line 2038 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5678 "conf_parser.c"
    break;

  case 395: /* connect_flags_item: AUTOCONN  */
#line 2044 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5687 "conf_parser.c"
    break;

  case 396: /* connect_flags_item: T_TLS  */
#line 2048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5696 "conf_parser.c"
    break;

  case 397: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5710 "conf_parser.c"
    break;

  case 398: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5719 "conf_parser.c"
    break;

  case 399: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2071 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5728 "conf_parser.c"
    break;

  case 400: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5737 "conf_parser.c"
    break;

  case 401: /* $@21: %empty  */
#line 2087 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5746 "conf_parser.c"
    break;

  case 402: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2091 "conf_parser.y"
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
#line 5770 "conf_parser.c"
    break;

  case 408: /* kill_user: USER '=' QSTRING ';'  */
#line 2115 "conf_parser.y"
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
#line 5793 "conf_parser.c"
    break;

  case 409: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2135 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5802 "conf_parser.c"
    break;

  case 410: /* $@22: %empty  */
#line 2145 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5811 "conf_parser.c"
    break;

  case 411: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2149 "conf_parser.y"
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
#line 5833 "conf_parser.c"
    break;

  case 417: /* deny_ip: IP '=' QSTRING ';'  */
#line 2171 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5842 "conf_parser.c"
    break;

  case 418: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2177 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5851 "conf_parser.c"
    break;

  case 424: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2192 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_error_report("Unable to add D-line exemption");
}
#line 5863 "conf_parser.c"
    break;

  case 425: /* $@23: %empty  */
#line 2205 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5872 "conf_parser.c"
    break;

  case 426: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2209 "conf_parser.y"
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
#line 5892 "conf_parser.c"
    break;

  case 432: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2229 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5901 "conf_parser.c"
    break;

  case 433: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2235 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5910 "conf_parser.c"
    break;

  case 478: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2291 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5918 "conf_parser.c"
    break;

  case 479: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2296 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5926 "conf_parser.c"
    break;

  case 480: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2301 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5934 "conf_parser.c"
    break;

  case 481: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2306 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5942 "conf_parser.c"
    break;

  case 482: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2311 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5950 "conf_parser.c"
    break;

  case 483: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2316 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5958 "conf_parser.c"
    break;

  case 484: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2321 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5966 "conf_parser.c"
    break;

  case 485: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2326 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5974 "conf_parser.c"
    break;

  case 486: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2331 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5982 "conf_parser.c"
    break;

  case 487: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2336 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5990 "conf_parser.c"
    break;

  case 488: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2341 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5998 "conf_parser.c"
    break;

  case 489: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2346 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6006 "conf_parser.c"
    break;

  case 490: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2351 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6014 "conf_parser.c"
    break;

  case 491: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2356 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 6025 "conf_parser.c"
    break;

  case 492: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2364 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6033 "conf_parser.c"
    break;

  case 493: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2369 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6041 "conf_parser.c"
    break;

  case 494: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2374 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6049 "conf_parser.c"
    break;

  case 495: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2379 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6057 "conf_parser.c"
    break;

  case 496: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2384 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6065 "conf_parser.c"
    break;

  case 497: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2389 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6073 "conf_parser.c"
    break;

  case 498: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2394 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6081 "conf_parser.c"
    break;

  case 499: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2399 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6089 "conf_parser.c"
    break;

  case 500: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2404 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6097 "conf_parser.c"
    break;

  case 501: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2409 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6105 "conf_parser.c"
    break;

  case 502: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2414 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6113 "conf_parser.c"
    break;

  case 503: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2419 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6121 "conf_parser.c"
    break;

  case 504: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2424 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6129 "conf_parser.c"
    break;

  case 505: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2429 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6137 "conf_parser.c"
    break;

  case 506: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2434 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6145 "conf_parser.c"
    break;

  case 507: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2439 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6153 "conf_parser.c"
    break;

  case 508: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2444 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6161 "conf_parser.c"
    break;

  case 509: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2449 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6169 "conf_parser.c"
    break;

  case 510: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2454 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6177 "conf_parser.c"
    break;

  case 511: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2459 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6189 "conf_parser.c"
    break;

  case 512: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2468 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6197 "conf_parser.c"
    break;

  case 513: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2473 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6205 "conf_parser.c"
    break;

  case 514: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2478 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6213 "conf_parser.c"
    break;

  case 515: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2483 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6221 "conf_parser.c"
    break;

  case 516: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2488 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6232 "conf_parser.c"
    break;

  case 517: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2496 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6240 "conf_parser.c"
    break;

  case 528: /* cloak_enabled: ENABLED '=' TBOOL ';'  */
#line 2516 "conf_parser.y"
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
#line 6260 "conf_parser.c"
    break;

  case 529: /* cloak_cidr_len_ipv4: CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2533 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6272 "conf_parser.c"
    break;

  case 530: /* cloak_cidr_len_ipv6: CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2542 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6284 "conf_parser.c"
    break;

  case 531: /* cloak_num_bits: NUM_BITS '=' NUMBER ';'  */
#line 2551 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6296 "conf_parser.c"
    break;

  case 532: /* cloak_secret: SECRET '=' QSTRING ';'  */
#line 2560 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.secret);
  ConfigCloak.secret = io_strdup((yyvsp[-1].string));
  cloak_set_secret((yyvsp[-1].string));
}
#line 6309 "conf_parser.c"
    break;

  case 533: /* cloak_suffix: SUFFIX '=' QSTRING ';'  */
#line 2570 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.suffix);
  ConfigCloak.suffix = io_strdup((yyvsp[-1].string));
  cloak_set_suffix((yyvsp[-1].string));
}
#line 6322 "conf_parser.c"
    break;

  case 554: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2605 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6330 "conf_parser.c"
    break;

  case 555: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2610 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6338 "conf_parser.c"
    break;

  case 556: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2615 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6346 "conf_parser.c"
    break;

  case 557: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2620 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6354 "conf_parser.c"
    break;

  case 558: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2625 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6362 "conf_parser.c"
    break;

  case 559: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2630 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6370 "conf_parser.c"
    break;

  case 560: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2635 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6378 "conf_parser.c"
    break;

  case 561: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2640 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6386 "conf_parser.c"
    break;

  case 562: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2645 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6394 "conf_parser.c"
    break;

  case 563: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2650 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6402 "conf_parser.c"
    break;

  case 564: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2655 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6410 "conf_parser.c"
    break;

  case 565: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2660 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6418 "conf_parser.c"
    break;

  case 566: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2665 "conf_parser.y"
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
#line 6444 "conf_parser.c"
    break;

  case 567: /* channel_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 2688 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigChannel.max_topic_length = TOPICLEN;
  else
    ConfigChannel.max_topic_length = (yyvsp[-1].number);
}
#line 6455 "conf_parser.c"
    break;

  case 568: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2696 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6463 "conf_parser.c"
    break;

  case 569: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2701 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6471 "conf_parser.c"
    break;

  case 582: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2723 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6480 "conf_parser.c"
    break;

  case 583: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2729 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6494 "conf_parser.c"
    break;

  case 584: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2740 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6506 "conf_parser.c"
    break;

  case 585: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2749 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6515 "conf_parser.c"
    break;

  case 586: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2755 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6524 "conf_parser.c"
    break;

  case 587: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2761 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6533 "conf_parser.c"
    break;

  case 588: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6545 "conf_parser.c"
    break;

  case 589: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2776 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6554 "conf_parser.c"
    break;


#line 6558 "conf_parser.c"

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

