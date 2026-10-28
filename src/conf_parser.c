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

enum conf_quantity_status
{
  CONF_QUANTITY_OK,
  CONF_QUANTITY_OUT_OF_RANGE,
  CONF_QUANTITY_INEXACT,
};

static enum conf_quantity_status
_conf_parser_quantity_from_decimal(const char *text, unsigned int unit, unsigned int *result)
{
  unsigned int whole = 0;

  const char *fraction = text;
  while (*fraction != '.')
  {
    const unsigned int digit = (unsigned int)(*fraction++ - '0');
    if (whole > (UINT_MAX - digit) / 10U)
      return CONF_QUANTITY_OUT_OF_RANGE;

    whole = whole * 10U + digit;
  }

  ++fraction;

  unsigned int scaled_fraction = 0;

  for (const char *cursor = fraction + strlen(fraction); cursor != fraction;)
  {
    const unsigned int digit = (unsigned int)(*--cursor - '0');
    const unsigned int decimal_tail = digit * (unit % 10U) + scaled_fraction % 10U;
    if (decimal_tail % 10U != 0)
      return CONF_QUANTITY_INEXACT;

    scaled_fraction = digit * (unit / 10U) + scaled_fraction / 10U + decimal_tail / 10U;
  }

  if (!_conf_parser_quantity_add(scaled_fraction, whole, unit, result))
    return CONF_QUANTITY_OUT_OF_RANGE;

  return CONF_QUANTITY_OK;
}


#line 249 "conf_parser.c"

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
    DECIMAL = 472,                 /* DECIMAL  */
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
#define DECIMAL 472
#define NUMBER 473

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 190 "conf_parser.y"

  unsigned int number;
  char *string;

#line 743 "conf_parser.c"

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
  YYSYMBOL_DECIMAL = 217,                  /* DECIMAL  */
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
  YYSYMBOL_timespec = 228,                 /* timespec  */
  YYSYMBOL_time_components = 229,          /* time_components  */
  YYSYMBOL_time_component = 230,           /* time_component  */
  YYSYMBOL_time_unit = 231,                /* time_unit  */
  YYSYMBOL_sizespec = 232,                 /* sizespec  */
  YYSYMBOL_size_components = 233,          /* size_components  */
  YYSYMBOL_size_component = 234,           /* size_component  */
  YYSYMBOL_size_unit = 235,                /* size_unit  */
  YYSYMBOL_port_number = 236,              /* port_number  */
  YYSYMBOL_module_base_path_entry = 237,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 238,         /* loadmodule_entry  */
  YYSYMBOL_module_string = 239,            /* module_string  */
  YYSYMBOL_module_attributes = 240,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 241,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 242,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 243,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 244,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 245,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 246, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_tls_private_key_file = 247, /* serverinfo_tls_private_key_file  */
  YYSYMBOL_serverinfo_name = 248,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 249,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 250,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 251,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 252, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 253, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 254, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_motd_file = 255,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 256,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 257,              /* admin_entry  */
  YYSYMBOL_admin_items = 258,              /* admin_items  */
  YYSYMBOL_admin_item = 259,               /* admin_item  */
  YYSYMBOL_admin_name = 260,               /* admin_name  */
  YYSYMBOL_admin_email = 261,              /* admin_email  */
  YYSYMBOL_admin_description = 262,        /* admin_description  */
  YYSYMBOL_motd_entry = 263,               /* motd_entry  */
  YYSYMBOL_264_1 = 264,                    /* $@1  */
  YYSYMBOL_motd_items = 265,               /* motd_items  */
  YYSYMBOL_motd_item = 266,                /* motd_item  */
  YYSYMBOL_motd_mask = 267,                /* motd_mask  */
  YYSYMBOL_motd_file = 268,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 269,             /* pseudo_entry  */
  YYSYMBOL_270_2 = 270,                    /* $@2  */
  YYSYMBOL_pseudo_items = 271,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 272,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 273,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 274,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 275,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 276,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 277,            /* logging_entry  */
  YYSYMBOL_logging_items = 278,            /* logging_items  */
  YYSYMBOL_logging_item = 279,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 280,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 281,       /* logging_file_entry  */
  YYSYMBOL_282_3 = 282,                    /* $@3  */
  YYSYMBOL_logging_file_items = 283,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 284,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 285,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 286,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 287,        /* logging_file_type  */
  YYSYMBOL_288_4 = 288,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 289,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 290,               /* oper_entry  */
  YYSYMBOL_291_5 = 291,                    /* $@5  */
  YYSYMBOL_oper_items = 292,               /* oper_items  */
  YYSYMBOL_oper_item = 293,                /* oper_item  */
  YYSYMBOL_oper_name = 294,                /* oper_name  */
  YYSYMBOL_oper_user = 295,                /* oper_user  */
  YYSYMBOL_oper_password = 296,            /* oper_password  */
  YYSYMBOL_oper_whois = 297,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 298,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 299, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 300, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 301,               /* oper_class  */
  YYSYMBOL_oper_umodes = 302,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 303,               /* oper_flags  */
  YYSYMBOL_304_6 = 304,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 305,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 306,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 307,              /* class_entry  */
  YYSYMBOL_308_7 = 308,                    /* $@7  */
  YYSYMBOL_class_items = 309,              /* class_items  */
  YYSYMBOL_class_item = 310,               /* class_item  */
  YYSYMBOL_class_name = 311,               /* class_name  */
  YYSYMBOL_class_ping_time = 312,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 313, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 314, /* class_number_per_ip_global  */
  YYSYMBOL_class_max_channels = 315,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 316,         /* class_max_number  */
  YYSYMBOL_class_sendq = 317,              /* class_sendq  */
  YYSYMBOL_class_recvq = 318,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 319,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 320,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 321,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 322,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 323,           /* class_max_idle  */
  YYSYMBOL_class_flags = 324,              /* class_flags  */
  YYSYMBOL_325_8 = 325,                    /* $@8  */
  YYSYMBOL_class_flags_items = 326,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 327,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 328,             /* listen_entry  */
  YYSYMBOL_329_9 = 329,                    /* $@9  */
  YYSYMBOL_listen_flags = 330,             /* listen_flags  */
  YYSYMBOL_331_10 = 331,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 332,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 333,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 334,             /* listen_items  */
  YYSYMBOL_listen_item = 335,              /* listen_item  */
  YYSYMBOL_listen_port = 336,              /* listen_port  */
  YYSYMBOL_337_11 = 337,                   /* $@11  */
  YYSYMBOL_port_items = 338,               /* port_items  */
  YYSYMBOL_port_item = 339,                /* port_item  */
  YYSYMBOL_listen_address = 340,           /* listen_address  */
  YYSYMBOL_listen_host = 341,              /* listen_host  */
  YYSYMBOL_auth_entry = 342,               /* auth_entry  */
  YYSYMBOL_343_12 = 343,                   /* $@12  */
  YYSYMBOL_auth_items = 344,               /* auth_items  */
  YYSYMBOL_auth_item = 345,                /* auth_item  */
  YYSYMBOL_auth_user = 346,                /* auth_user  */
  YYSYMBOL_auth_passwd = 347,              /* auth_passwd  */
  YYSYMBOL_auth_class = 348,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 349,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 350,               /* auth_flags  */
  YYSYMBOL_351_13 = 351,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 352,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 353,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 354,               /* auth_spoof  */
  YYSYMBOL_resv_entry = 355,               /* resv_entry  */
  YYSYMBOL_356_14 = 356,                   /* $@14  */
  YYSYMBOL_resv_items = 357,               /* resv_items  */
  YYSYMBOL_resv_item = 358,                /* resv_item  */
  YYSYMBOL_resv_mask = 359,                /* resv_mask  */
  YYSYMBOL_resv_reason = 360,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 361,              /* resv_exempt  */
  YYSYMBOL_service_entry = 362,            /* service_entry  */
  YYSYMBOL_service_items = 363,            /* service_items  */
  YYSYMBOL_service_item = 364,             /* service_item  */
  YYSYMBOL_service_name = 365,             /* service_name  */
  YYSYMBOL_shared_entry = 366,             /* shared_entry  */
  YYSYMBOL_367_15 = 367,                   /* $@15  */
  YYSYMBOL_shared_items = 368,             /* shared_items  */
  YYSYMBOL_shared_item = 369,              /* shared_item  */
  YYSYMBOL_shared_name = 370,              /* shared_name  */
  YYSYMBOL_shared_user = 371,              /* shared_user  */
  YYSYMBOL_shared_type = 372,              /* shared_type  */
  YYSYMBOL_373_16 = 373,                   /* $@16  */
  YYSYMBOL_shared_types = 374,             /* shared_types  */
  YYSYMBOL_shared_type_item = 375,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 376,            /* cluster_entry  */
  YYSYMBOL_377_17 = 377,                   /* $@17  */
  YYSYMBOL_cluster_items = 378,            /* cluster_items  */
  YYSYMBOL_cluster_item = 379,             /* cluster_item  */
  YYSYMBOL_cluster_name = 380,             /* cluster_name  */
  YYSYMBOL_cluster_type = 381,             /* cluster_type  */
  YYSYMBOL_382_18 = 382,                   /* $@18  */
  YYSYMBOL_cluster_types = 383,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 384,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 385,            /* connect_entry  */
  YYSYMBOL_386_19 = 386,                   /* $@19  */
  YYSYMBOL_connect_items = 387,            /* connect_items  */
  YYSYMBOL_connect_item = 388,             /* connect_item  */
  YYSYMBOL_connect_name = 389,             /* connect_name  */
  YYSYMBOL_connect_host = 390,             /* connect_host  */
  YYSYMBOL_connect_timeout = 391,          /* connect_timeout  */
  YYSYMBOL_connect_retry_delay = 392,      /* connect_retry_delay  */
  YYSYMBOL_connect_bind = 393,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 394,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 395,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 396, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 397,             /* connect_port  */
  YYSYMBOL_connect_aftype = 398,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 399,            /* connect_flags  */
  YYSYMBOL_400_20 = 400,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 401,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 402,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 403,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 404,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 405,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 406,            /* connect_class  */
  YYSYMBOL_kill_entry = 407,               /* kill_entry  */
  YYSYMBOL_408_21 = 408,                   /* $@21  */
  YYSYMBOL_kill_items = 409,               /* kill_items  */
  YYSYMBOL_kill_item = 410,                /* kill_item  */
  YYSYMBOL_kill_user = 411,                /* kill_user  */
  YYSYMBOL_kill_reason = 412,              /* kill_reason  */
  YYSYMBOL_deny_entry = 413,               /* deny_entry  */
  YYSYMBOL_414_22 = 414,                   /* $@22  */
  YYSYMBOL_deny_items = 415,               /* deny_items  */
  YYSYMBOL_deny_item = 416,                /* deny_item  */
  YYSYMBOL_deny_ip = 417,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 418,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 419,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 420,             /* exempt_items  */
  YYSYMBOL_exempt_item = 421,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 422,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 423,              /* gecos_entry  */
  YYSYMBOL_424_23 = 424,                   /* $@23  */
  YYSYMBOL_gecos_items = 425,              /* gecos_items  */
  YYSYMBOL_gecos_item = 426,               /* gecos_item  */
  YYSYMBOL_gecos_name = 427,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 428,             /* gecos_reason  */
  YYSYMBOL_general_entry = 429,            /* general_entry  */
  YYSYMBOL_general_items = 430,            /* general_items  */
  YYSYMBOL_general_item = 431,             /* general_item  */
  YYSYMBOL_general_away_count = 432,       /* general_away_count  */
  YYSYMBOL_general_away_time = 433,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 434,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 435, /* general_whowas_history_length  */
  YYSYMBOL_general_dline_min_cidr = 436,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 437,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 438,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 439,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 440, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_anti_nick_flood = 441,  /* general_anti_nick_flood  */
  YYSYMBOL_general_max_nick_time = 442,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 443, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 444,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 445,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 446, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 447,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 448,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 449, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 450, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 451, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_u_oper_only = 452, /* general_stats_u_oper_only  */
  YYSYMBOL_general_pace_wait = 453,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 454,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 455, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 456, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 457,       /* general_short_motd  */
  YYSYMBOL_general_specials_in_ident = 458, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 459,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 460,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_ident = 461,    /* general_disable_ident  */
  YYSYMBOL_general_disable_dns = 462,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 463,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 464,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 465,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 466,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 467, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 468, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 469, /* general_default_floodtime  */
  YYSYMBOL_general_ident_timeout = 470,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 471, /* general_registration_timeout  */
  YYSYMBOL_cloak_entry = 472,              /* cloak_entry  */
  YYSYMBOL_cloak_items = 473,              /* cloak_items  */
  YYSYMBOL_cloak_item = 474,               /* cloak_item  */
  YYSYMBOL_cloak_enabled = 475,            /* cloak_enabled  */
  YYSYMBOL_cloak_cidr_len_ipv4 = 476,      /* cloak_cidr_len_ipv4  */
  YYSYMBOL_cloak_cidr_len_ipv6 = 477,      /* cloak_cidr_len_ipv6  */
  YYSYMBOL_cloak_num_bits = 478,           /* cloak_num_bits  */
  YYSYMBOL_cloak_secret = 479,             /* cloak_secret  */
  YYSYMBOL_cloak_suffix = 480,             /* cloak_suffix  */
  YYSYMBOL_channel_entry = 481,            /* channel_entry  */
  YYSYMBOL_channel_items = 482,            /* channel_items  */
  YYSYMBOL_channel_item = 483,             /* channel_item  */
  YYSYMBOL_channel_disable_fake_channels = 484, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 485, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 486, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 487, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 488, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 489, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 490, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 491, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 492,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 493,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 494,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 495,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 496,  /* channel_max_kick_length  */
  YYSYMBOL_channel_max_topic_length = 497, /* channel_max_topic_length  */
  YYSYMBOL_channel_default_join_flood_count = 498, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 499, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 500,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 501,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 502,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 503, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 504, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 505, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 506, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 507,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 508, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 509,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 510         /* serverhide_hidden  */
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
#define YYLAST   1146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  225
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  286
/* YYNRULES -- Number of rules.  */
#define YYNRULES  593
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1212

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
       0,   410,   410,   411,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     443,   452,   454,   454,   463,   470,   482,   483,   484,   485,
     486,   489,   498,   500,   500,   509,   516,   528,   529,   530,
     531,   532,   533,   534,   537,   552,   570,   585,   591,   593,
     598,   601,   606,   609,   618,   620,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   635,
     644,   653,   668,   683,   693,   707,   716,   739,   762,   771,
     781,   783,   783,   784,   785,   786,   787,   789,   798,   807,
     821,   820,   838,   838,   839,   839,   839,   841,   847,   858,
     857,   876,   876,   877,   877,   877,   877,   877,   879,   885,
     891,   897,   920,   921,   921,   923,   923,   924,   926,   936,
     936,   949,   950,   952,   952,   953,   953,   955,   963,   966,
     972,   971,   977,   981,   985,   989,   993,   997,  1001,  1005,
    1016,  1015,  1077,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1090,  1096,  1102,  1108,  1114,
    1125,  1131,  1142,  1148,  1155,  1154,  1160,  1160,  1161,  1165,
    1169,  1173,  1177,  1181,  1185,  1189,  1193,  1197,  1201,  1205,
    1209,  1213,  1217,  1221,  1225,  1229,  1233,  1237,  1241,  1245,
    1249,  1253,  1257,  1261,  1265,  1269,  1273,  1277,  1288,  1287,
    1341,  1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,
    1350,  1351,  1352,  1353,  1354,  1355,  1356,  1358,  1364,  1370,
    1376,  1382,  1388,  1394,  1400,  1407,  1413,  1419,  1425,  1434,
    1444,  1443,  1449,  1449,  1450,  1454,  1465,  1464,  1471,  1470,
    1475,  1475,  1476,  1480,  1484,  1488,  1492,  1498,  1498,  1499,
    1499,  1499,  1499,  1499,  1501,  1501,  1503,  1503,  1505,  1518,
    1535,  1541,  1552,  1551,  1607,  1607,  1608,  1609,  1610,  1611,
    1612,  1613,  1614,  1616,  1622,  1628,  1634,  1646,  1645,  1651,
    1651,  1653,  1657,  1661,  1665,  1669,  1673,  1677,  1681,  1685,
    1691,  1707,  1706,  1721,  1721,  1722,  1722,  1722,  1722,  1724,
    1730,  1736,  1746,  1748,  1748,  1749,  1749,  1751,  1768,  1767,
    1790,  1790,  1791,  1791,  1791,  1791,  1793,  1799,  1819,  1818,
    1824,  1824,  1825,  1829,  1833,  1837,  1841,  1845,  1849,  1853,
    1857,  1861,  1872,  1871,  1890,  1890,  1891,  1891,  1891,  1893,
    1900,  1899,  1905,  1905,  1906,  1910,  1914,  1918,  1922,  1926,
    1930,  1934,  1938,  1942,  1953,  1952,  2008,  2008,  2009,  2010,
    2011,  2012,  2013,  2014,  2015,  2016,  2017,  2018,  2019,  2020,
    2021,  2022,  2023,  2024,  2026,  2032,  2038,  2044,  2050,  2056,
    2069,  2082,  2088,  2094,  2098,  2105,  2104,  2109,  2109,  2110,
    2114,  2120,  2131,  2137,  2143,  2154,  2153,  2178,  2178,  2179,
    2179,  2179,  2181,  2201,  2212,  2211,  2234,  2234,  2235,  2235,
    2235,  2237,  2243,  2253,  2255,  2255,  2256,  2256,  2258,  2272,
    2271,  2292,  2292,  2293,  2293,  2293,  2295,  2301,  2311,  2313,
    2313,  2314,  2315,  2316,  2317,  2318,  2319,  2320,  2321,  2322,
    2323,  2324,  2325,  2326,  2327,  2328,  2329,  2330,  2331,  2332,
    2333,  2334,  2335,  2336,  2337,  2338,  2339,  2340,  2341,  2342,
    2343,  2344,  2345,  2346,  2347,  2348,  2349,  2350,  2351,  2352,
    2353,  2354,  2357,  2362,  2367,  2372,  2377,  2382,  2387,  2392,
    2397,  2402,  2407,  2412,  2417,  2422,  2430,  2435,  2440,  2445,
    2450,  2455,  2460,  2465,  2470,  2475,  2480,  2485,  2490,  2495,
    2500,  2505,  2510,  2515,  2520,  2525,  2534,  2539,  2544,  2549,
    2554,  2562,  2571,  2573,  2573,  2574,  2575,  2576,  2577,  2578,
    2579,  2580,  2582,  2599,  2608,  2617,  2626,  2636,  2650,  2652,
    2652,  2653,  2654,  2655,  2656,  2657,  2658,  2659,  2660,  2661,
    2662,  2663,  2664,  2665,  2666,  2667,  2668,  2669,  2671,  2676,
    2681,  2686,  2691,  2696,  2701,  2706,  2711,  2716,  2721,  2726,
    2731,  2754,  2762,  2767,  2776,  2778,  2778,  2779,  2780,  2781,
    2782,  2783,  2784,  2785,  2786,  2787,  2789,  2795,  2806,  2815,
    2821,  2827,  2833,  2842
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
  "XLINE_EXEMPT", "QSTRING", "DECIMAL", "NUMBER", "';'", "'}'", "'='",
  "':'", "','", "'{'", "$accept", "conf", "conf_item", "timespec",
  "time_components", "time_component", "time_unit", "sizespec",
  "size_components", "size_component", "size_unit", "port_number",
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

#define YYPACT_NINF (-650)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-130)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -650,   683,  -650,  -193,  -212,  -209,  -650,  -190,  -650,  -650,
    -175,  -650,  -172,  -650,  -650,  -650,  -157,  -177,  -650,  -650,
    -650,  -152,  -144,  -650,  -138,  -650,  -131,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,   311,   746,  -122,   308,  -120,
    -117,    22,  -111,   380,  -109,  -103,   -96,  -650,  -181,  -157,
     -86,   -78,   -76,   751,   459,   -63,    13,   -33,    20,   -14,
       4,  -154,     5,    48,    18,  -650,  -650,  -650,  -650,  -650,
      50,    55,    63,    78,    85,    92,    94,   102,   104,   106,
     107,   109,   113,   114,   116,   118,   123,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,   620,  -650,   119,   125,   131,   135,
     137,   139,     8,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
     554,    41,  -650,   141,    10,  -650,  -650,    61,  -650,   142,
     151,   152,   154,   156,   162,   172,   173,   175,   176,   181,
     182,   183,   187,   189,   192,   193,   194,   195,   196,   198,
     201,   206,   207,   211,   212,   213,   214,   215,   219,   222,
     223,   224,   226,   228,   231,   236,   237,   240,   244,    44,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,   278,    60,    28,   -85,    26,    72,    30,   276,    27,
    -650,   245,   246,   247,   248,   249,   253,   255,   257,    17,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,   103,
     258,   261,   266,   271,   272,   274,   275,   279,   280,   283,
     284,   178,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,    89,   117,   286,    91,  -650,  -650,
    -650,   140,   188,  -650,   290,    45,  -650,  -650,   180,  -650,
     126,   179,   190,   220,  -650,   294,   -51,   320,   297,   -51,
     -51,   -51,   301,   -51,   -51,   303,   304,   306,   309,   312,
     314,   232,  -650,   310,   313,   315,  -650,   318,   319,   322,
     332,   333,   335,   337,   341,   342,   345,   347,   128,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,   351,   352,   339,   353,   356,   363,
     362,  -650,   366,   365,   367,   368,   371,   378,   382,  -650,
     383,   384,   385,   387,   388,   389,   390,   391,   185,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,   392,   393,    21,  -650,
    -650,  -650,   381,   396,  -650,  -650,   395,   397,    47,  -650,
    -650,  -650,   407,   -51,   369,   -51,   -51,   402,   -51,   428,
     429,   409,   412,   -51,   431,   -51,   414,   415,   416,   417,
     418,   419,   -51,   420,   421,   422,   430,   450,   -51,   -51,
     451,   -51,   454,   432,   455,   457,   434,   -51,   -51,   -51,
     460,   435,   436,  -650,   441,   443,   444,  -650,   447,   452,
     453,   233,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
     456,   461,   121,  -650,  -650,  -650,   462,   464,   465,  -650,
     467,  -650,    24,  -650,  -650,  -650,  -650,  -650,  -650,   439,
    -650,  -650,  -650,   471,   470,   475,    29,  -650,  -650,  -650,
     473,   476,   477,  -650,   478,   481,   482,   484,   485,   489,
     491,   230,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,   495,   494,   497,   500,    15,  -650,  -650,
    -650,  -650,   486,   514,   -51,   506,   529,   509,   532,   533,
     510,  -650,  -650,   513,   516,   540,   520,   522,   525,   526,
     530,   542,   546,   547,   537,  -650,   548,   527,  -650,    70,
    -650,  -650,  -650,  -650,   555,   549,  -650,   177,   551,   544,
     545,   552,   560,    97,  -650,  -650,  -650,  -650,  -650,   566,
     557,  -650,   564,   568,  -650,   569,    65,  -650,  -650,  -650,
    -650,   572,   574,   578,  -650,   579,   218,   218,   587,   -49,
    -650,   592,   600,   601,   602,   603,   604,   605,   606,   607,
     609,   610,   614,   615,   616,  -650,  -650,   567,   596,   584,
     618,   -51,   619,   -51,   627,   628,   629,   630,   -51,    -3,
      -3,   632,  -650,   634,   635,   636,   637,   638,   640,  -650,
    -650,   633,   115,   644,   668,   647,   648,   645,   652,   653,
     654,   -51,   655,   657,   -51,   658,   651,  -650,   659,   660,
     661,  -650,   662,  -650,   663,   666,   664,  -650,   665,   667,
     669,   670,   671,   672,   673,   674,   675,   676,   677,   678,
     679,   680,   681,   682,   684,   685,   686,   687,   688,   689,
     690,   691,   692,   693,   694,   695,   696,   697,   698,   699,
     700,   701,   702,   703,   704,   705,   706,   707,  -650,  -650,
     711,   708,   656,   712,   713,   714,   715,  -650,   716,   717,
     718,  -650,  -650,   719,   720,   710,   654,   721,  -650,   -85,
    -650,   722,   723,   724,  -650,  -650,   725,   748,   726,   728,
     729,   730,   732,   755,   734,   735,   733,  -650,  -650,   737,
     738,   739,   740,  -650,   741,   742,   743,   744,   745,   747,
     749,   750,  -650,   752,   753,   754,   756,   757,   758,   759,
     760,   761,   762,   763,  -650,  -650,   767,   736,   765,  -650,
     766,  -650,   174,  -650,   770,   771,   772,   773,   774,  -650,
     775,  -650,  -650,   776,   769,   779,   777,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
     218,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,   778,   780,   -55,   781,
     782,   783,   784,   785,   786,   787,   788,   789,   534,   534,
     790,   101,  -650,   791,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,   792,   793,   794,   795,   796,   797,   798,     0,   799,
     800,  -650,   801,   802,   803,   804,   805,   806,  -650,   807,
     808,  -650,  -650,   809,   810,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,   811,   812,   479,   813,
     814,   815,  -650,   816,   817,  -650,   818,   819,   344,   835,
     448,  -650,  -650,  -650,   821,   822,  -650,   823,   824,   487,
     825,   826,   827,   828,   829,   830,   831,  -650,   832,   833,
     834,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,   836,   586,  -650,  -650,   837,   838,   839,  -650,    81,
    -650,  -650,  -650,  -650,   842,   843,   844,   845,  -650,  -650,
     846,   595,   847,  -650,  -650,  -650,  -650,  -650,  -206,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,   534,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -199,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -184,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -183,  -650,   654,   654,   848,  -650,  -650,  -650,  -650,  -650,
     849,  -650,   850,  -650,   851,   852,  -650,   853,  -650,   854,
     855,  -650,  -650,   856,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -176,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -123,  -650,
    -650,   841,  -180,   858,   861,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,   -80,  -650,  -650,  -650,   -55,  -650,     0,  -650,   479,
    -650,   344,  -650,  -650,  -650,   820,   914,   924,   918,   865,
     925,   930,   941,  -650,   487,  -650,   586,   863,   864,   866,
     376,  -650,  -650,   595,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,   867,
    -650,  -650
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   208,     0,   364,   414,
       0,   429,     0,   272,   405,   246,     0,     0,   100,   150,
     301,     0,     0,   342,     0,   109,     0,   318,     3,     4,
       5,    14,     6,    26,    27,     7,     8,    11,    12,    13,
      16,    17,    18,    19,    20,    21,    22,    23,    25,    24,
      10,     9,    15,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    95,    94,   557,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   540,   556,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   541,   542,
     552,   553,   554,   555,     0,   531,     0,     0,     0,     0,
       0,     0,     0,   524,   525,   526,   527,   528,   529,   530,
       0,     0,   427,     0,     0,   425,   426,     0,   481,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   478,   447,   473,   474,   475,   476,   451,
     443,   444,   445,   446,   460,   448,   449,   450,   452,   453,
     477,   455,   456,   462,   463,   457,   458,   454,   459,   470,
     471,   472,   468,   469,   461,   466,   467,   464,   465,   479,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     585,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     576,   577,   578,   579,   580,   581,   582,   584,   583,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    77,    75,    67,    76,    69,    70,    71,
      72,    73,    74,    68,     0,     0,     0,     0,   124,   125,
     126,     0,     0,   316,     0,     0,   314,   315,     0,    96,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   539,     0,     0,     0,   240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   211,
     212,   215,   217,   218,   219,   220,   221,   222,   213,   214,
     216,   223,   224,   225,     0,     0,     0,     0,     0,     0,
       0,   523,     0,     0,     0,     0,     0,     0,     0,   395,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   377,   376,
     378,   382,   379,   380,   381,   420,     0,     0,     0,   417,
     418,   419,     0,     0,   424,   435,     0,     0,     0,   432,
     433,   434,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   439,     0,     0,     0,   287,     0,     0,
       0,     0,   275,   276,   277,   278,   281,   279,   280,   411,
       0,     0,     0,   408,   409,   410,     0,     0,     0,   248,
       0,   260,     0,   258,   259,   261,   262,    63,    62,    59,
      61,    56,    55,     0,     0,     0,     0,   103,   104,   105,
       0,     0,     0,   174,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   154,   155,   156,   157,   160,   161,   162,
     159,   158,   163,     0,     0,     0,     0,     0,   304,   305,
     306,   307,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   575,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,   350,     0,
     345,   346,   347,   127,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   112,   113,   115,   114,   116,     0,
       0,   313,     0,     0,   328,     0,     0,   321,   322,   323,
     324,     0,     0,     0,    90,     0,     0,    30,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   538,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   210,     0,     0,     0,     0,     0,     0,   522,
     383,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   366,     0,     0,
       0,   416,     0,   423,     0,     0,     0,   431,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   438,   282,
       0,     0,     0,     0,     0,     0,     0,   274,     0,     0,
       0,   407,   263,     0,     0,     0,     0,     0,   257,     0,
     106,     0,     0,     0,   102,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,   308,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
       0,     0,   574,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,   348,     0,     0,     0,   344,
       0,   122,     0,   117,     0,     0,     0,     0,     0,   111,
       0,   312,   325,     0,     0,     0,     0,   320,    99,    98,
      97,   572,    36,    37,    38,    39,    40,    35,    34,   573,
       0,    33,   558,   559,   560,   561,   562,   563,   564,   565,
     568,   569,   566,   567,   570,   571,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,    42,    43,     0,   209,   533,   534,   532,   535,   536,
     537,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,   365,     0,
       0,   415,   428,     0,     0,   430,   491,   496,   482,   483,
     504,   518,   519,   512,   511,   486,   487,   520,   499,   490,
     488,   489,   494,   495,   484,   493,   492,   509,   516,   517,
     515,   505,   503,   506,   510,   521,   507,   508,   501,   502,
     513,   514,   498,   497,   500,   485,     0,     0,     0,     0,
       0,     0,   273,     0,     0,   406,     0,     0,     0,   268,
     264,   267,   247,    60,     0,     0,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   151,     0,     0,
       0,   302,   589,   586,   587,   588,   593,   592,   590,   591,
      86,    83,    89,    82,    87,    88,    81,    85,    84,    79,
      80,     0,     0,   343,   128,     0,     0,     0,   140,     0,
     132,   133,   135,   134,     0,     0,     0,     0,   110,   317,
       0,     0,     0,   319,   235,   236,   245,   244,     0,   243,
     231,   239,   232,   238,   227,   237,   230,   229,   228,    47,
      48,    49,    50,    51,    52,    53,    46,    45,   233,     0,
      44,   234,   390,   393,   394,   404,   401,   385,   402,   399,
     400,     0,   398,   403,   384,   392,   387,   389,   388,   386,
     391,   421,   422,   436,   437,   285,   286,   295,   291,   292,
     294,   299,   296,   297,   298,   293,     0,   290,   284,   300,
     283,   413,   412,   271,   270,   255,   256,   253,   254,   252,
       0,   251,     0,     0,     0,   107,   108,   172,   169,   194,
       0,   205,   181,   190,     0,   179,   184,     0,   199,     0,
     193,   197,   203,   183,   186,   195,   196,   200,   191,   198,
     187,   204,   189,   185,   188,     0,   177,   165,   167,   173,
     170,   171,   166,   168,   311,   309,   310,   349,   354,   360,
     363,   356,   362,   357,   361,   359,   355,   358,     0,   353,
     136,     0,     0,     0,     0,   131,   119,   118,   120,   121,
     326,   332,   338,   341,   334,   340,   335,   339,   337,   333,
     336,     0,   331,   327,   241,     0,   396,     0,   288,     0,
     249,     0,   269,   266,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,   351,     0,     0,     0,     0,
       0,   130,   329,     0,   242,   397,   289,   250,   207,   180,
     202,   178,   206,   201,   192,   182,   176,   352,   137,   139,
     138,   148,   147,   143,   145,   149,   146,   142,   144,     0,
     330,   141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -650,  -650,  -650,  -307,  -650,   359,   282,  -630,  -650,   124,
     129,  -649,  -650,  -650,   901,  -650,  -650,   262,  -650,  -650,
     727,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,   890,  -650,  -650,  -650,  -650,  -650,
    -650,   588,  -650,  -650,  -650,  -650,  -650,   515,  -650,  -650,
    -650,  -650,  -650,  -650,   598,  -650,  -650,  -650,  -650,   108,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,   580,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,   -84,  -650,  -650,  -650,   764,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,   -66,  -650,  -650,  -650,  -650,  -650,   -69,  -650,
     611,  -650,  -650,  -650,    23,  -650,  -650,  -650,  -650,  -650,
     639,  -650,  -650,  -650,  -650,  -650,  -650,  -650,   -65,  -650,
    -650,  -650,  -650,   570,  -650,  -650,  -650,  -650,  -650,   840,
    -650,  -650,  -650,  -650,   512,  -650,  -650,  -650,  -650,  -650,
     -88,  -650,  -650,  -650,   550,  -650,  -650,  -650,  -650,   -77,
    -650,  -650,  -650,   768,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,   -56,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,   631,  -650,  -650,  -650,  -650,
    -650,   709,  -650,  -650,  -650,  -650,   960,  -650,  -650,  -650,
    -650,   731,  -650,  -650,  -650,  -650,   916,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,   974,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  1002,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,   862,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    28,   598,   599,   600,   808,   840,   841,   842,
    1017,   929,    29,    30,    68,   235,   489,   490,    31,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,    32,    84,    85,    86,    87,    88,    33,    70,
     496,   497,   498,   499,    34,    77,   573,   574,   575,   576,
     577,   578,    35,   287,   288,   289,   290,   291,   979,   980,
     981,   982,   983,  1133,  1209,    36,    71,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   738,
    1105,  1106,    37,    57,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     619,   998,   999,    38,    66,   481,   725,  1070,  1071,   482,
     483,   484,  1074,   930,   931,   485,   486,    39,    64,   461,
     462,   463,   464,   465,   466,   467,   712,  1056,  1057,   468,
      40,    72,   527,   528,   529,   530,   531,    41,   295,   296,
     297,    42,    79,   586,   587,   588,   589,   590,   794,  1151,
    1152,    43,    75,   559,   560,   561,   562,   777,  1128,  1129,
      44,    59,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   647,  1031,  1032,   391,   392,
     393,   394,    45,    65,   472,   473,   474,   475,    46,    60,
     398,   399,   400,   401,    47,   144,   145,   146,    48,    62,
     408,   409,   410,   411,    49,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,    50,   132,   133,
     134,   135,   136,   137,   138,   139,    51,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    52,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     843,   862,   603,   604,   605,   996,   607,   608,  1029,   125,
    1178,   142,    55,  1154,   285,    56,   523,  1155,   240,    80,
    1156,   293,   395,   142,  1157,   476,    53,    54,   523,   476,
     493,   493,   126,   127,    58,  1158,  1160,   838,   839,  1159,
    1161,   234,   395,  1173,    69,   148,   293,  1174,   405,    61,
     149,   150,    63,   151,   152,   128,    81,   487,   488,    67,
     241,   469,   405,   153,    82,   524,   582,   300,   242,   243,
     244,   556,    73,   245,   246,   154,   155,   524,   247,   248,
      74,   997,   975,   143,   156,   157,    76,   477,   158,   159,
     556,   477,   285,    78,   396,   143,  1175,   478,   568,   479,
    1176,   478,   124,   479,   140,   525,   669,   141,   671,   672,
     160,   674,   161,   147,   396,   231,   679,   525,   681,   494,
     494,   232,   469,   162,    89,   688,   163,   164,   233,   323,
     129,   694,   695,    83,   697,   294,   165,   166,   237,  1182,
     703,   704,   705,  1183,   167,   168,   238,   169,   239,   170,
     324,   325,   526,   171,   172,   130,    90,    91,   397,   480,
     294,   284,   406,   480,   526,    92,   596,   597,   596,   810,
     173,   131,   174,   175,   176,   975,   406,   177,   397,   259,
     583,   582,   178,  -129,   407,   557,   362,  1030,   363,   568,
     364,   292,    93,    94,    95,    96,   976,   470,   407,   495,
     495,   179,   180,   326,   557,   181,   182,    97,    98,    99,
     298,   365,   569,   260,   838,   839,   261,   100,   101,   102,
     286,   103,   104,   299,   327,   328,   301,   756,   360,   105,
     403,   500,   329,   366,   454,   752,   330,   540,   303,   183,
     184,   660,   262,   331,   727,   491,   185,   186,   367,   733,
     368,   332,   333,   334,   263,   187,   501,   188,   470,   455,
     369,  -129,   335,   570,   452,   580,   977,   666,   471,   302,
     584,   305,   370,   585,   571,   558,   306,   500,   502,   454,
     264,   456,   336,   572,   307,   796,   978,   852,   853,   976,
     778,   492,   265,   266,   558,   583,   267,   268,   286,   308,
     371,  1134,   501,   569,   455,   503,   309,   337,   457,   125,
     567,   565,    80,   310,   830,   311,   832,   788,   838,  1019,
     372,   837,   542,   312,   502,   313,   456,   314,   315,   471,
     316,   373,   126,   127,   317,   318,   563,   319,   374,   320,
     354,   720,   591,   321,   863,   504,   355,   866,   631,    81,
     375,   503,   356,   457,   570,   128,   357,    82,   358,   977,
     359,   505,   402,   412,   458,   571,   802,   803,   804,   805,
     806,  1065,   413,   414,   572,   415,   269,   416,   270,   978,
    1066,   148,   376,   417,   377,   584,   149,   150,   585,   151,
     152,   504,   459,   418,   419,   592,   420,   421,   554,   153,
    1067,   782,   422,   423,   424,   656,   593,   505,   425,   458,
     426,   154,   155,   427,   428,   429,   430,   431,   506,   432,
     156,   157,   433,  1162,   158,   159,    83,   434,   435,   507,
     129,   508,   436,   437,   438,   439,   440,   459,   509,   594,
     441,   460,   510,   442,   443,   444,   160,   445,   161,   446,
     746,   615,   447,   716,  1201,   130,  1202,   448,   449,   162,
     259,   450,   163,   164,   506,   451,   532,   533,   534,   535,
     536,   131,   165,   166,   537,   507,   538,   508,   539,   543,
     167,   168,   544,   169,   509,   170,   460,   545,   510,   171,
     172,  1079,   546,   547,   260,   548,   549,   261,  1080,  1047,
     550,   551,  1179,  1203,   552,   553,   173,   564,   174,   175,
     176,   579,   595,   177,   601,   602,  1081,  1082,   178,   606,
    1204,   609,   610,   262,   611,  1068,  1083,   612,  1048,   616,
     613,  1069,   614,   635,   617,   263,   618,   179,   180,   620,
     621,   181,   182,   622,  1205,  1206,  1009,  1010,  1011,  1012,
    1013,  1014,  1015,   623,   624,   362,   625,   363,   626,   364,
    1049,   264,   627,   628,  1084,  1085,   629,  1086,   630,   633,
     634,   636,   637,   265,   266,   183,   184,   267,   268,   638,
     365,   639,   185,   186,  1207,   640,   641,   670,   642,   643,
    1208,   187,   644,   188,  1087,  1050,  1051,   662,  1088,   645,
    1052,   668,   366,   646,   648,   649,   650,  1089,   651,   652,
     653,   654,   655,   658,   659,   663,   664,   367,   665,   368,
     673,   323,   675,   676,  1053,   680,  1090,   677,  1091,   369,
     678,  1092,   682,   683,   684,   685,   686,   687,   689,   690,
     691,   370,   324,   325,   693,   696,   692,  1093,   698,   700,
     699,   701,   702,   707,   706,   708,  1094,   269,  1095,   270,
     709,  1096,   729,  1097,   710,   711,  1118,  1098,   713,   371,
    1099,  1073,  1054,   714,   715,  1141,  1100,   718,  1101,  1102,
     754,   722,   719,     2,     3,   723,   724,     4,   726,   372,
     730,   731,   735,  1103,  1055,   326,   732,   736,   737,   739,
     373,  1104,   740,   741,     5,   742,   743,   374,   755,     6,
     744,     7,   745,     8,   748,   749,   327,   328,   750,   375,
       9,   751,   757,   758,   329,   759,   760,   761,   330,   762,
    1119,   763,   764,    10,   765,   331,   766,    11,    12,  1142,
     767,   768,   769,   332,   333,   334,   770,    89,   776,   780,
    1120,   376,   240,   377,   335,  1121,   774,    13,   771,  1143,
    1122,    14,   772,   773,  1144,   784,   785,   775,   781,  1145,
     783,    15,    16,   786,   336,  1123,   791,  1124,  1125,    90,
      91,   787,   790,   792,  1146,   826,  1147,  1148,    92,   793,
     795,   798,  1126,   799,   241,    17,    18,   800,   801,   337,
    1127,  1149,   242,   243,   244,   828,   809,   245,   246,  1150,
      19,   812,   247,   248,   827,    93,    94,    95,    96,   813,
     814,   815,   816,   817,   818,   819,   820,    20,   821,   822,
      97,    98,    99,   823,   824,   825,   829,   831,    21,    22,
     100,   101,   102,   833,   103,   104,   834,   835,   836,   851,
      23,   844,   105,   845,   846,   847,   848,   849,    24,   850,
     854,    25,   855,   856,   857,    26,   858,    27,   859,   860,
     868,   864,   861,   865,   867,   869,   870,   918,   807,   873,
     871,   872,   874,   875,   876,   566,   877,  1188,   878,   879,
     880,   881,   882,   883,   884,   885,   886,   887,   888,   889,
     890,   891,   917,   892,   893,   894,   895,   896,   897,   898,
     899,   900,   901,   902,   903,   904,   905,   906,   907,   908,
     909,   910,   911,   912,   913,   914,   915,   916,   919,   920,
     921,   928,   923,   924,   922,   926,   927,   925,   934,   935,
     932,   937,   938,   936,   940,   941,   942,   939,   943,   944,
     945,   946,   947,   948,   949,   950,  1192,   972,   811,   951,
     952,   953,   954,   955,   956,  1020,   957,  1016,   958,   959,
     236,   960,   961,   962,   304,   963,   964,   965,   966,   967,
     968,   969,   970,   971,   973,   974,   984,   985,   986,   987,
     991,   933,   990,   988,   989,   992,   993,   994,   555,   995,
    1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1018,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,
    1045,  1046,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1072,
    1075,  1076,  1077,  1078,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1189,  1117,  1130,  1177,  1191,  1131,
    1132,  1136,  1137,  1138,  1139,  1140,  1153,  1164,  1190,  1193,
    1194,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1180,
    1181,  1195,  1198,  1199,   734,  1200,  1211,  1135,   789,  1184,
    1196,   747,  1187,   728,  1186,  1210,  1163,   753,   797,  1197,
     717,  1185,   632,   721,   404,   453,   361,   661,   322,   779,
       0,   541,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   581,     0,     0,     0,   667,
       0,     0,     0,     0,     0,     0,   657
};

static const yytype_int16 yycheck[] =
{
     630,   650,   309,   310,   311,    60,   313,   314,     8,     1,
     190,     1,   224,   219,     1,   224,     1,   223,     1,     1,
     219,     1,     1,     1,   223,     1,   219,   220,     1,     1,
       1,     1,    24,    25,   224,   219,   219,   217,   218,   223,
     223,   222,     1,   219,   221,     1,     1,   223,     1,   224,
       6,     7,   224,     9,    10,    47,    38,   142,   143,   216,
      43,     1,     1,    19,    46,    50,     1,   221,    51,    52,
      53,     1,   224,    56,    57,    31,    32,    50,    61,    62,
     224,   136,     1,    73,    40,    41,   224,    63,    44,    45,
       1,    63,     1,   224,    73,    73,   219,    73,     1,    75,
     223,    73,   224,    75,   224,    90,   413,   224,   415,   416,
      66,   418,    68,   224,    73,   224,   423,    90,   425,    90,
      90,   224,     1,    79,     1,   432,    82,    83,   224,     1,
     122,   438,   439,   115,   441,   115,    92,    93,   224,   219,
     447,   448,   449,   223,   100,   101,   224,   103,   224,   105,
      22,    23,   137,   109,   110,   147,    33,    34,   137,   135,
     115,   224,   115,   135,   137,    42,   217,   218,   217,   218,
     126,   163,   128,   129,   130,     1,   115,   133,   137,     1,
     115,     1,   138,   170,   137,   115,     1,   187,     3,     1,
       5,   224,    69,    70,    71,    72,   115,   137,   137,   170,
     170,   157,   158,    75,   115,   161,   162,    84,    85,    86,
     224,    26,   115,    35,   217,   218,    38,    94,    95,    96,
     207,    98,    99,   219,    96,    97,   221,   534,   220,   106,
     220,     1,   104,    48,     1,   220,   108,   220,   220,   195,
     196,   220,    64,   115,   220,   219,   202,   203,    63,   220,
      65,   123,   124,   125,    76,   211,    26,   213,   137,    26,
      75,   170,   134,   166,   220,   220,   185,   220,   208,   221,
     205,   221,    87,   208,   177,   205,   221,     1,    48,     1,
     102,    48,   154,   186,   221,   220,   205,   172,   173,   115,
     220,   219,   114,   115,   205,   115,   118,   119,   207,   221,
     115,   220,    26,   115,    26,    75,   221,   179,    75,     1,
     170,   220,     1,   221,   621,   221,   623,   220,   217,   218,
     135,   628,   219,   221,    48,   221,    48,   221,   221,   208,
     221,   146,    24,    25,   221,   221,   219,   221,   153,   221,
     221,   220,   216,   220,   651,   115,   221,   654,   220,    38,
     165,    75,   221,    75,   166,    47,   221,    46,   221,   185,
     221,   131,   221,   221,   131,   177,   148,   149,   150,   151,
     152,    27,   221,   221,   186,   221,   198,   221,   200,   205,
      36,     1,   197,   221,   199,   205,     6,     7,   208,     9,
      10,   115,   159,   221,   221,   216,   221,   221,   220,    19,
      56,   224,   221,   221,   221,   220,   216,   131,   221,   131,
     221,    31,    32,   221,   221,   221,   221,   221,   188,   221,
      40,    41,   221,  1072,    44,    45,   115,   221,   221,   199,
     122,   201,   221,   221,   221,   221,   221,   159,   208,   219,
     221,   208,   212,   221,   221,   221,    66,   221,    68,   221,
     220,   219,   221,   220,    78,   147,    80,   221,   221,    79,
       1,   221,    82,    83,   188,   221,   221,   221,   221,   221,
     221,   163,    92,    93,   221,   199,   221,   201,   221,   221,
     100,   101,   221,   103,   208,   105,   208,   221,   212,   109,
     110,     4,   221,   221,    35,   221,   221,    38,    11,    20,
     221,   221,  1132,   127,   221,   221,   126,   221,   128,   129,
     130,   221,   218,   133,   194,   218,    29,    30,   138,   218,
     144,   218,   218,    64,   218,   181,    39,   218,    49,   219,
     218,   187,   218,   194,   221,    76,   221,   157,   158,   221,
     221,   161,   162,   221,   168,   169,    12,    13,    14,    15,
      16,    17,    18,   221,   221,     1,   221,     3,   221,     5,
      81,   102,   221,   221,    77,    78,   221,    80,   221,   218,
     218,   218,   216,   114,   115,   195,   196,   118,   119,   216,
      26,   219,   202,   203,   208,   219,   221,   218,   221,   221,
     214,   211,   221,   213,   107,   116,   117,   216,   111,   221,
     121,   194,    48,   221,   221,   221,   221,   120,   221,   221,
     221,   221,   221,   221,   221,   219,   221,    63,   221,    65,
     218,     1,   194,   194,   145,   194,   139,   218,   141,    75,
     218,   144,   218,   218,   218,   218,   218,   218,   218,   218,
     218,    87,    22,    23,   194,   194,   216,   160,   194,   194,
     218,   194,   218,   218,   194,   219,   169,   198,   171,   200,
     219,   174,   223,   176,   221,   221,    80,   180,   221,   115,
     183,   223,   193,   221,   221,    80,   189,   221,   191,   192,
     194,   219,   221,     0,     1,   221,   221,     4,   221,   135,
     219,   221,   219,   206,   215,    75,   221,   221,   221,   221,
     146,   214,   221,   221,    21,   221,   221,   153,   194,    26,
     221,    28,   221,    30,   219,   221,    96,    97,   221,   165,
      37,   221,   216,   194,   104,   216,   194,   194,   108,   219,
     144,   218,   216,    50,   194,   115,   216,    54,    55,   144,
     218,   216,   216,   123,   124,   125,   216,     1,   221,   194,
     164,   197,     1,   199,   134,   169,   219,    74,   216,   164,
     174,    78,   216,   216,   169,   221,   221,   219,   219,   174,
     219,    88,    89,   221,   154,   189,   219,   191,   192,    33,
      34,   221,   216,   219,   189,   218,   191,   192,    42,   221,
     221,   219,   206,   219,    43,   112,   113,   219,   219,   179,
     214,   206,    51,    52,    53,   221,   219,    56,    57,   214,
     127,   219,    61,    62,   218,    69,    70,    71,    72,   219,
     219,   219,   219,   219,   219,   219,   219,   144,   219,   219,
      84,    85,    86,   219,   219,   219,   218,   218,   155,   156,
      94,    95,    96,   216,    98,    99,   218,   218,   218,   216,
     167,   219,   106,   219,   219,   219,   219,   219,   175,   219,
     216,   178,   194,   216,   216,   182,   221,   184,   216,   216,
     219,   216,   218,   216,   216,   216,   216,   221,   596,   216,
     219,   219,   216,   219,   219,   287,   219,    67,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   194,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   216,   216,   216,
     216,   221,   216,   216,   219,   216,   216,   219,   216,   216,
     219,   216,   194,   219,   216,   216,   216,   221,   216,   194,
     216,   216,   219,   216,   216,   216,    91,   221,   599,   219,
     219,   219,   219,   219,   219,   841,   219,   838,   219,   219,
      69,   219,   219,   219,    84,   219,   219,   219,   219,   219,
     219,   219,   219,   216,   219,   219,   216,   216,   216,   216,
     221,   729,   216,   219,   219,   216,   219,   219,   271,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   204,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   140,   219,   219,   216,   140,   221,
     221,   219,   219,   219,   219,   219,   219,   219,   144,   144,
     140,   222,   222,   222,   222,   222,   222,   222,   222,   221,
     219,   140,   219,   219,   496,   219,   219,   979,   573,  1155,
    1174,   511,  1161,   482,  1159,  1183,  1073,   527,   586,  1176,
     461,  1157,   338,   472,   144,   189,   132,   398,   106,   559,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   295,    -1,    -1,    -1,   408,
      -1,    -1,    -1,    -1,    -1,    -1,   378
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   226,     0,     1,     4,    21,    26,    28,    30,    37,
      50,    54,    55,    74,    78,    88,    89,   112,   113,   127,
     144,   155,   156,   167,   175,   178,   182,   184,   227,   237,
     238,   243,   257,   263,   269,   277,   290,   307,   328,   342,
     355,   362,   366,   376,   385,   407,   413,   419,   423,   429,
     472,   481,   500,   219,   220,   224,   224,   308,   224,   386,
     414,   224,   424,   224,   343,   408,   329,   216,   239,   221,
     264,   291,   356,   224,   224,   377,   224,   270,   224,   367,
       1,    38,    46,   115,   258,   259,   260,   261,   262,     1,
      33,    34,    42,    69,    70,    71,    72,    84,    85,    86,
      94,    95,    96,    98,    99,   106,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   224,     1,    24,    25,    47,   122,
     147,   163,   473,   474,   475,   476,   477,   478,   479,   480,
     224,   224,     1,    73,   420,   421,   422,   224,     1,     6,
       7,     9,    10,    19,    31,    32,    40,    41,    44,    45,
      66,    68,    79,    82,    83,    92,    93,   100,   101,   103,
     105,   109,   110,   126,   128,   129,   130,   133,   138,   157,
     158,   161,   162,   195,   196,   202,   203,   211,   213,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   224,   224,   224,   222,   240,   239,   224,   224,   224,
       1,    43,    51,    52,    53,    56,    57,    61,    62,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,     1,
      35,    38,    64,    76,   102,   114,   115,   118,   119,   198,
     200,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   224,     1,   207,   278,   279,   280,
     281,   282,   224,     1,   115,   363,   364,   365,   224,   219,
     221,   221,   221,   220,   259,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   220,   483,     1,    22,    23,    75,    96,    97,   104,
     108,   115,   123,   124,   125,   134,   154,   179,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   221,   221,   221,   221,   221,   221,
     220,   474,     1,     3,     5,    26,    48,    63,    65,    75,
      87,   115,   135,   146,   153,   165,   197,   199,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   403,   404,   405,   406,     1,    73,   137,   415,   416,
     417,   418,   221,   220,   421,     1,   115,   137,   425,   426,
     427,   428,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   220,   431,     1,    26,    48,    75,   131,   159,
     208,   344,   345,   346,   347,   348,   349,   350,   354,     1,
     137,   208,   409,   410,   411,   412,     1,    63,    73,    75,
     135,   330,   334,   335,   336,   340,   341,   142,   143,   241,
     242,   219,   219,     1,    90,   170,   265,   266,   267,   268,
       1,    26,    48,    75,   115,   131,   188,   199,   201,   208,
     212,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,     1,    50,    90,   137,   357,   358,   359,
     360,   361,   221,   221,   221,   221,   221,   221,   221,   221,
     220,   502,   219,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   220,   245,     1,   115,   205,   378,
     379,   380,   381,   219,   221,   220,   279,   170,     1,   115,
     166,   177,   186,   271,   272,   273,   274,   275,   276,   221,
     220,   364,     1,   115,   205,   208,   368,   369,   370,   371,
     372,   216,   216,   216,   219,   218,   217,   218,   228,   229,
     230,   194,   218,   228,   228,   228,   218,   228,   228,   218,
     218,   218,   218,   218,   218,   219,   219,   221,   221,   325,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   220,   310,   218,   218,   194,   218,   216,   216,   219,
     219,   221,   221,   221,   221,   221,   221,   400,   221,   221,
     221,   221,   221,   221,   221,   221,   220,   388,   221,   221,
     220,   416,   216,   219,   221,   221,   220,   426,   194,   228,
     218,   228,   228,   218,   228,   194,   194,   218,   218,   228,
     194,   228,   218,   218,   218,   218,   218,   218,   228,   218,
     218,   218,   216,   194,   228,   228,   194,   228,   194,   218,
     194,   194,   218,   228,   228,   228,   194,   218,   219,   219,
     221,   221,   351,   221,   221,   221,   220,   345,   221,   221,
     220,   410,   219,   221,   221,   331,   221,   220,   335,   223,
     219,   221,   221,   220,   266,   219,   221,   221,   304,   221,
     221,   221,   221,   221,   221,   221,   220,   293,   219,   221,
     221,   221,   220,   358,   194,   194,   228,   216,   194,   216,
     194,   194,   219,   218,   216,   194,   216,   218,   216,   216,
     216,   216,   216,   216,   219,   219,   221,   382,   220,   379,
     194,   219,   224,   219,   221,   221,   221,   221,   220,   272,
     216,   219,   219,   221,   373,   221,   220,   369,   219,   219,
     219,   219,   148,   149,   150,   151,   152,   231,   231,   219,
     218,   230,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   218,   218,   221,   218,
     228,   218,   228,   216,   218,   218,   218,   228,   217,   218,
     232,   233,   234,   232,   219,   219,   219,   219,   219,   219,
     219,   216,   172,   173,   216,   194,   216,   216,   221,   216,
     216,   218,   236,   228,   216,   216,   228,   216,   219,   216,
     216,   219,   219,   216,   216,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   216,   194,   221,   216,
     216,   216,   219,   216,   216,   219,   216,   216,   221,   236,
     338,   339,   219,   242,   216,   216,   219,   216,   194,   221,
     216,   216,   216,   216,   194,   216,   216,   219,   216,   216,
     216,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   216,   221,   219,   219,     1,   115,   185,   205,   283,
     284,   285,   286,   287,   216,   216,   216,   216,   219,   219,
     216,   221,   216,   219,   219,   219,    60,   136,   326,   327,
     219,   219,   219,   219,   219,   219,   219,   219,   219,    12,
      13,    14,    15,    16,    17,    18,   235,   235,   219,   218,
     234,   219,   219,   219,   219,   219,   219,   219,   219,     8,
     187,   401,   402,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,    20,    49,    81,
     116,   117,   121,   145,   193,   215,   352,   353,   219,   219,
     219,   219,   219,   219,   219,    27,    36,    56,   181,   187,
     332,   333,   204,   223,   337,   219,   219,   219,   219,     4,
      11,    29,    30,    39,    77,    78,    80,   107,   111,   120,
     139,   141,   144,   160,   169,   171,   174,   176,   180,   183,
     189,   191,   192,   206,   214,   305,   306,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,    80,   144,
     164,   169,   174,   189,   191,   192,   206,   214,   383,   384,
     219,   221,   221,   288,   220,   284,   219,   219,   219,   219,
     219,    80,   144,   164,   169,   174,   189,   191,   192,   206,
     214,   374,   375,   219,   219,   223,   219,   223,   219,   223,
     219,   223,   236,   339,   219,   222,   222,   222,   222,   222,
     222,   222,   222,   219,   223,   219,   223,   216,   190,   232,
     221,   219,   219,   223,   327,   402,   353,   333,    67,   140,
     144,   140,    91,   144,   140,   140,   306,   384,   219,   219,
     219,    78,    80,   127,   144,   168,   169,   208,   214,   289,
     375,   219
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   225,   226,   226,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     228,   228,   229,   229,   230,   230,   231,   231,   231,   231,
     231,   232,   232,   233,   233,   234,   234,   235,   235,   235,
     235,   235,   235,   235,   236,   237,   238,   239,   240,   240,
     241,   241,   242,   242,   243,   244,   244,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   258,   259,   259,   259,   259,   260,   261,   262,
     264,   263,   265,   265,   266,   266,   266,   267,   268,   270,
     269,   271,   271,   272,   272,   272,   272,   272,   273,   274,
     275,   276,   277,   278,   278,   279,   279,   279,   280,   282,
     281,   283,   283,   284,   284,   284,   284,   285,   286,   286,
     288,   287,   289,   289,   289,   289,   289,   289,   289,   289,
     291,   290,   292,   292,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   304,   303,   305,   305,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   308,   307,
     309,   309,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     325,   324,   326,   326,   327,   327,   329,   328,   331,   330,
     332,   332,   333,   333,   333,   333,   333,   334,   334,   335,
     335,   335,   335,   335,   337,   336,   338,   338,   339,   339,
     340,   341,   343,   342,   344,   344,   345,   345,   345,   345,
     345,   345,   345,   346,   347,   348,   349,   351,   350,   352,
     352,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     354,   356,   355,   357,   357,   358,   358,   358,   358,   359,
     360,   361,   362,   363,   363,   364,   364,   365,   367,   366,
     368,   368,   369,   369,   369,   369,   370,   371,   373,   372,
     374,   374,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   377,   376,   378,   378,   379,   379,   379,   380,
     382,   381,   383,   383,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   386,   385,   387,   387,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   398,   400,   399,   401,   401,   402,
     402,   403,   404,   405,   406,   408,   407,   409,   409,   410,
     410,   410,   411,   412,   414,   413,   415,   415,   416,   416,
     416,   417,   418,   419,   420,   420,   421,   421,   422,   424,
     423,   425,   425,   426,   426,   426,   427,   428,   429,   430,
     430,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   473,   474,   474,   474,   474,   474,
     474,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     482,   483,   483,   483,   483,   483,   483,   483,   483,   483,
     483,   483,   483,   483,   483,   483,   483,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   501,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   503,   504,   505,   506,
     507,   508,   509,   510
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     1,     0,     2,
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
       1,     3,     3,     1,     1,     1,     3,     3,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     0,     6,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     0,     5,     3,     1,     1,     3,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     2,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     4,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4
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
    case YYSYMBOL_DECIMAL: /* DECIMAL  */
#line 407 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3205 "conf_parser.c"
        break;

    case YYSYMBOL_module_string: /* module_string  */
#line 407 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3211 "conf_parser.c"
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
#line 444 "conf_parser.y"
{
  if ((yyvsp[0].number) != 0)
  {
    yyerror("Nonzero durations require a unit");
    YYERROR;
  }

  (yyval.number) = 0;
}
#line 3492 "conf_parser.c"
    break;

  case 33: /* time_components: time_components time_component  */
#line 455 "conf_parser.y"
{
  if (!_conf_parser_quantity_add((yyvsp[-1].number), (yyvsp[0].number), 1U, &(yyval.number)))
  {
    yyerror("Duration out of range");
    YYERROR;
  }
}
#line 3504 "conf_parser.c"
    break;

  case 34: /* time_component: NUMBER time_unit  */
#line 464 "conf_parser.y"
{
  if (!_conf_parser_quantity_add(0, (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Duration out of range");
    YYERROR;
  }
}
#line 3516 "conf_parser.c"
    break;

  case 35: /* time_component: DECIMAL time_unit  */
#line 471 "conf_parser.y"
{
  const enum conf_quantity_status status = _conf_parser_quantity_from_decimal((yyvsp[-1].string), (yyvsp[0].number), &(yyval.number));
  io_free((yyvsp[-1].string));

  if (status != CONF_QUANTITY_OK)
  {
    yyerror(status == CONF_QUANTITY_INEXACT ? "Duration component must resolve to whole seconds" : "Duration out of range");
    YYERROR;
  }
}
#line 3531 "conf_parser.c"
    break;

  case 36: /* time_unit: SECONDS  */
#line 482 "conf_parser.y"
                   { (yyval.number) = 1U; }
#line 3537 "conf_parser.c"
    break;

  case 37: /* time_unit: MINUTES  */
#line 483 "conf_parser.y"
                   { (yyval.number) = 60U; }
#line 3543 "conf_parser.c"
    break;

  case 38: /* time_unit: HOURS  */
#line 484 "conf_parser.y"
                   { (yyval.number) = 60U * 60U; }
#line 3549 "conf_parser.c"
    break;

  case 39: /* time_unit: DAYS  */
#line 485 "conf_parser.y"
                   { (yyval.number) = 60U * 60U * 24U; }
#line 3555 "conf_parser.c"
    break;

  case 40: /* time_unit: WEEKS  */
#line 486 "conf_parser.y"
                   { (yyval.number) = 60U * 60U * 24U * 7U; }
#line 3561 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER  */
#line 490 "conf_parser.y"
{
  if ((yyvsp[0].number) != 0)
  {
    yyerror("Nonzero sizes require a unit");
    YYERROR;
  }

  (yyval.number) = 0;
}
#line 3575 "conf_parser.c"
    break;

  case 44: /* size_components: size_components size_component  */
#line 501 "conf_parser.y"
{
  if (!_conf_parser_quantity_add((yyvsp[-1].number), (yyvsp[0].number), 1U, &(yyval.number)))
  {
    yyerror("Size out of range");
    YYERROR;
  }
}
#line 3587 "conf_parser.c"
    break;

  case 45: /* size_component: NUMBER size_unit  */
#line 510 "conf_parser.y"
{
  if (!_conf_parser_quantity_add(0, (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Size out of range");
    YYERROR;
  }
}
#line 3599 "conf_parser.c"
    break;

  case 46: /* size_component: DECIMAL size_unit  */
#line 517 "conf_parser.y"
{
  const enum conf_quantity_status status = _conf_parser_quantity_from_decimal((yyvsp[-1].string), (yyvsp[0].number), &(yyval.number));
  io_free((yyvsp[-1].string));

  if (status != CONF_QUANTITY_OK)
  {
    yyerror(status == CONF_QUANTITY_INEXACT ? "Size component must resolve to whole bytes" : "Size out of range");
    YYERROR;
  }
}
#line 3614 "conf_parser.c"
    break;

  case 47: /* size_unit: BYTES  */
#line 528 "conf_parser.y"
                   { (yyval.number) = 1U; }
#line 3620 "conf_parser.c"
    break;

  case 48: /* size_unit: KBYTES  */
#line 529 "conf_parser.y"
                   { (yyval.number) = 1000U; }
#line 3626 "conf_parser.c"
    break;

  case 49: /* size_unit: KIBYTES  */
#line 530 "conf_parser.y"
                   { (yyval.number) = 1024U; }
#line 3632 "conf_parser.c"
    break;

  case 50: /* size_unit: MBYTES  */
#line 531 "conf_parser.y"
                   { (yyval.number) = 1000U * 1000U; }
#line 3638 "conf_parser.c"
    break;

  case 51: /* size_unit: MIBYTES  */
#line 532 "conf_parser.y"
                   { (yyval.number) = 1024U * 1024U; }
#line 3644 "conf_parser.c"
    break;

  case 52: /* size_unit: GBYTES  */
#line 533 "conf_parser.y"
                   { (yyval.number) = 1000U * 1000U * 1000U; }
#line 3650 "conf_parser.c"
    break;

  case 53: /* size_unit: GIBYTES  */
#line 534 "conf_parser.y"
                   { (yyval.number) = 1024U * 1024U * 1024U; }
#line 3656 "conf_parser.c"
    break;

  case 54: /* port_number: NUMBER  */
#line 538 "conf_parser.y"
{
  if ((yyvsp[0].number) > UINT16_MAX)
  {
    yyerror("Port out of range");
    YYERROR;
  }

  (yyval.number) = (yyvsp[0].number);
}
#line 3670 "conf_parser.c"
    break;

  case 55: /* module_base_path_entry: MODULE_BASE_PATH '=' module_string ';'  */
#line 553 "conf_parser.y"
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
#line 3687 "conf_parser.c"
    break;

  case 56: /* loadmodule_entry: LOADMODULE module_string module_attributes ';'  */
#line 571 "conf_parser.y"
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
#line 3704 "conf_parser.c"
    break;

  case 57: /* module_string: QSTRING  */
#line 586 "conf_parser.y"
{
  (yyval.string) = io_strdup((yyvsp[0].string));
}
#line 3712 "conf_parser.c"
    break;

  case 58: /* module_attributes: %empty  */
#line 591 "conf_parser.y"
{
  (yyval.number) = 0;
}
#line 3720 "conf_parser.c"
    break;

  case 59: /* module_attributes: ':' module_attributes_items  */
#line 594 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3728 "conf_parser.c"
    break;

  case 60: /* module_attributes_items: module_attributes_items ',' module_attributes_item  */
#line 599 "conf_parser.y"
{
  (yyval.number) = (yyvsp[-2].number) | (yyvsp[0].number);
}
#line 3736 "conf_parser.c"
    break;

  case 61: /* module_attributes_items: module_attributes_item  */
#line 602 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3744 "conf_parser.c"
    break;

  case 62: /* module_attributes_item: RESIDENT  */
#line 607 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_DEACTIVATE;
}
#line 3752 "conf_parser.c"
    break;

  case 63: /* module_attributes_item: REQUIRED  */
#line 610 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_REMOVE;
}
#line 3760 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 636 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3772 "conf_parser.c"
    break;

  case 80: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 645 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3784 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 654 "conf_parser.y"
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
#line 3802 "conf_parser.c"
    break;

  case 82: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 669 "conf_parser.y"
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
#line 3820 "conf_parser.c"
    break;

  case 83: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 684 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3833 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 694 "conf_parser.y"
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
#line 3850 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 708 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3862 "conf_parser.c"
    break;

  case 86: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 717 "conf_parser.y"
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
#line 3888 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 740 "conf_parser.y"
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
#line 3914 "conf_parser.c"
    break;

  case 88: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 763 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3926 "conf_parser.c"
    break;

  case 89: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 772 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3935 "conf_parser.c"
    break;

  case 97: /* admin_name: NAME '=' QSTRING ';'  */
#line 790 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3947 "conf_parser.c"
    break;

  case 98: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 799 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3959 "conf_parser.c"
    break;

  case 99: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 808 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3971 "conf_parser.c"
    break;

  case 100: /* $@1: %empty  */
#line 821 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3980 "conf_parser.c"
    break;

  case 101: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 825 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3997 "conf_parser.c"
    break;

  case 107: /* motd_mask: MASK '=' QSTRING ';'  */
#line 842 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4006 "conf_parser.c"
    break;

  case 108: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 848 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 4015 "conf_parser.c"
    break;

  case 109: /* $@2: %empty  */
#line 858 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4024 "conf_parser.c"
    break;

  case 110: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 862 "conf_parser.y"
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
#line 4042 "conf_parser.c"
    break;

  case 118: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 880 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 4051 "conf_parser.c"
    break;

  case 119: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 886 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4060 "conf_parser.c"
    break;

  case 120: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 892 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 4069 "conf_parser.c"
    break;

  case 121: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 898 "conf_parser.y"
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
#line 4091 "conf_parser.c"
    break;

  case 128: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 927 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = yylval.number;
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 4103 "conf_parser.c"
    break;

  case 129: /* $@3: %empty  */
#line 936 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4112 "conf_parser.c"
    break;

  case 130: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 940 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 4125 "conf_parser.c"
    break;

  case 137: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 956 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 4136 "conf_parser.c"
    break;

  case 138: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 964 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 4144 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 967 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 4152 "conf_parser.c"
    break;

  case 140: /* $@4: %empty  */
#line 972 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 4161 "conf_parser.c"
    break;

  case 142: /* logging_file_type_item: USER  */
#line 978 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4170 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: OPERATOR  */
#line 982 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4179 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: XLINE  */
#line 986 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4188 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: RESV  */
#line 990 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4197 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: T_DLINE  */
#line 994 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4206 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: KLINE  */
#line 998 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4215 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KILL  */
#line 1002 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4224 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: T_DEBUG  */
#line 1006 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4233 "conf_parser.c"
    break;

  case 150: /* $@5: %empty  */
#line 1016 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4245 "conf_parser.c"
    break;

  case 151: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 1023 "conf_parser.y"
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
#line 4303 "conf_parser.c"
    break;

  case 165: /* oper_name: NAME '=' QSTRING ';'  */
#line 1091 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4312 "conf_parser.c"
    break;

  case 166: /* oper_user: USER '=' QSTRING ';'  */
#line 1097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4321 "conf_parser.c"
    break;

  case 167: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1103 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4330 "conf_parser.c"
    break;

  case 168: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4339 "conf_parser.c"
    break;

  case 169: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1115 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4353 "conf_parser.c"
    break;

  case 170: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1126 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4362 "conf_parser.c"
    break;

  case 171: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1132 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4376 "conf_parser.c"
    break;

  case 172: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1143 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4385 "conf_parser.c"
    break;

  case 173: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1149 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4394 "conf_parser.c"
    break;

  case 174: /* $@6: %empty  */
#line 1155 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4403 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: KILL ':' REMOTE  */
#line 1162 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4412 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: KILL  */
#line 1166 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4421 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1170 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4430 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: CONNECT  */
#line 1174 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4439 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1178 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4448 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: SQUIT  */
#line 1182 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4457 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: KLINE  */
#line 1186 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4466 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: UNKLINE  */
#line 1190 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4475 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_DLINE  */
#line 1194 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4484 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_UNDLINE  */
#line 1198 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4493 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: XLINE  */
#line 1202 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4502 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_UNXLINE  */
#line 1206 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4511 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: DIE  */
#line 1210 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4520 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_RESTART  */
#line 1214 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4529 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1218 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4538 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REHASH  */
#line 1222 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4547 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: ADMIN  */
#line 1226 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4556 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_GLOBOPS  */
#line 1230 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4565 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_LOCOPS  */
#line 1234 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4574 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: REMOTEBAN  */
#line 1238 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4583 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: T_SET  */
#line 1242 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4592 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: MODULE  */
#line 1246 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4601 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: T_OPME  */
#line 1250 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4610 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: NICK ':' RESV  */
#line 1254 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4619 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: JOIN ':' RESV  */
#line 1258 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4628 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: RESV  */
#line 1262 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4637 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: T_UNRESV  */
#line 1266 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4646 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: CLOSE  */
#line 1270 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4655 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1274 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4664 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: BYPASS ':' INPUT_FLOOD  */
#line 1278 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_BYPASS_INPUT_FLOOD;
}
#line 4673 "conf_parser.c"
    break;

  case 208: /* $@7: %empty  */
#line 1288 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4688 "conf_parser.c"
    break;

  case 209: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1298 "conf_parser.y"
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
#line 4735 "conf_parser.c"
    break;

  case 227: /* class_name: NAME '=' QSTRING ';'  */
#line 1359 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4744 "conf_parser.c"
    break;

  case 228: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1365 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4753 "conf_parser.c"
    break;

  case 229: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1371 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4762 "conf_parser.c"
    break;

  case 230: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1377 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4771 "conf_parser.c"
    break;

  case 231: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1383 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4780 "conf_parser.c"
    break;

  case 232: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1389 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4789 "conf_parser.c"
    break;

  case 233: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1395 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4798 "conf_parser.c"
    break;

  case 234: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1401 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4808 "conf_parser.c"
    break;

  case 235: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1408 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4817 "conf_parser.c"
    break;

  case 236: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1414 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4826 "conf_parser.c"
    break;

  case 237: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1420 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4835 "conf_parser.c"
    break;

  case 238: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1426 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4847 "conf_parser.c"
    break;

  case 239: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1435 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4859 "conf_parser.c"
    break;

  case 240: /* $@8: %empty  */
#line 1444 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4868 "conf_parser.c"
    break;

  case 244: /* class_flags_item: RANDOM_IDLE  */
#line 1451 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4877 "conf_parser.c"
    break;

  case 245: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1455 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4886 "conf_parser.c"
    break;

  case 246: /* $@9: %empty  */
#line 1465 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4895 "conf_parser.c"
    break;

  case 248: /* $@10: %empty  */
#line 1471 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4903 "conf_parser.c"
    break;

  case 252: /* listen_flags_item: T_TLS  */
#line 1477 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4912 "conf_parser.c"
    break;

  case 253: /* listen_flags_item: HIDDEN  */
#line 1481 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4921 "conf_parser.c"
    break;

  case 254: /* listen_flags_item: T_SERVER  */
#line 1485 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4930 "conf_parser.c"
    break;

  case 255: /* listen_flags_item: CLIENT  */
#line 1489 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4939 "conf_parser.c"
    break;

  case 256: /* listen_flags_item: DEFER  */
#line 1493 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4948 "conf_parser.c"
    break;

  case 264: /* $@11: %empty  */
#line 1501 "conf_parser.y"
                                 { reset_block_state(); }
#line 4954 "conf_parser.c"
    break;

  case 268: /* port_item: port_number  */
#line 1506 "conf_parser.y"
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
#line 4972 "conf_parser.c"
    break;

  case 269: /* port_item: port_number TWODOTS port_number  */
#line 1519 "conf_parser.y"
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
#line 4992 "conf_parser.c"
    break;

  case 270: /* listen_address: IP '=' QSTRING ';'  */
#line 1536 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5001 "conf_parser.c"
    break;

  case 271: /* listen_host: HOST '=' QSTRING ';'  */
#line 1542 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5010 "conf_parser.c"
    break;

  case 272: /* $@12: %empty  */
#line 1552 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5019 "conf_parser.c"
    break;

  case 273: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1556 "conf_parser.y"
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
#line 5074 "conf_parser.c"
    break;

  case 283: /* auth_user: USER '=' QSTRING ';'  */
#line 1617 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5083 "conf_parser.c"
    break;

  case 284: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1623 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5092 "conf_parser.c"
    break;

  case 285: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1629 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5101 "conf_parser.c"
    break;

  case 286: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1635 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5115 "conf_parser.c"
    break;

  case 287: /* $@13: %empty  */
#line 1646 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 5124 "conf_parser.c"
    break;

  case 291: /* auth_flags_item: EXCEED_LIMIT  */
#line 1654 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 5133 "conf_parser.c"
    break;

  case 292: /* auth_flags_item: KLINE_EXEMPT  */
#line 1658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 5142 "conf_parser.c"
    break;

  case 293: /* auth_flags_item: XLINE_EXEMPT  */
#line 1662 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 5151 "conf_parser.c"
    break;

  case 294: /* auth_flags_item: NEED_IDENT  */
#line 1666 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 5160 "conf_parser.c"
    break;

  case 295: /* auth_flags_item: CAN_FLOOD  */
#line 1670 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 5169 "conf_parser.c"
    break;

  case 296: /* auth_flags_item: NO_TILDE  */
#line 1674 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 5178 "conf_parser.c"
    break;

  case 297: /* auth_flags_item: RESV_EXEMPT  */
#line 1678 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 5187 "conf_parser.c"
    break;

  case 298: /* auth_flags_item: T_WEBIRC  */
#line 1682 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5196 "conf_parser.c"
    break;

  case 299: /* auth_flags_item: NEED_PASSWORD  */
#line 1686 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5205 "conf_parser.c"
    break;

  case 300: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1692 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    log_write(LOG_TYPE_IRCD,
              "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 5220 "conf_parser.c"
    break;

  case 301: /* $@14: %empty  */
#line 1707 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5232 "conf_parser.c"
    break;

  case 302: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1714 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5243 "conf_parser.c"
    break;

  case 309: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1725 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5252 "conf_parser.c"
    break;

  case 310: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1731 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5261 "conf_parser.c"
    break;

  case 311: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1737 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5270 "conf_parser.c"
    break;

  case 317: /* service_name: NAME '=' QSTRING ';'  */
#line 1752 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5285 "conf_parser.c"
    break;

  case 318: /* $@15: %empty  */
#line 1768 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5301 "conf_parser.c"
    break;

  case 319: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1779 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5316 "conf_parser.c"
    break;

  case 326: /* shared_name: NAME '=' QSTRING ';'  */
#line 1794 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5325 "conf_parser.c"
    break;

  case 327: /* shared_user: USER '=' QSTRING ';'  */
#line 1800 "conf_parser.y"
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
#line 5347 "conf_parser.c"
    break;

  case 328: /* $@16: %empty  */
#line 1819 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5356 "conf_parser.c"
    break;

  case 332: /* shared_type_item: KLINE  */
#line 1826 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5365 "conf_parser.c"
    break;

  case 333: /* shared_type_item: UNKLINE  */
#line 1830 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5374 "conf_parser.c"
    break;

  case 334: /* shared_type_item: T_DLINE  */
#line 1834 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5383 "conf_parser.c"
    break;

  case 335: /* shared_type_item: T_UNDLINE  */
#line 1838 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5392 "conf_parser.c"
    break;

  case 336: /* shared_type_item: XLINE  */
#line 1842 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5401 "conf_parser.c"
    break;

  case 337: /* shared_type_item: T_UNXLINE  */
#line 1846 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5410 "conf_parser.c"
    break;

  case 338: /* shared_type_item: RESV  */
#line 1850 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5419 "conf_parser.c"
    break;

  case 339: /* shared_type_item: T_UNRESV  */
#line 1854 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5428 "conf_parser.c"
    break;

  case 340: /* shared_type_item: T_LOCOPS  */
#line 1858 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5437 "conf_parser.c"
    break;

  case 341: /* shared_type_item: T_ALL  */
#line 1862 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5446 "conf_parser.c"
    break;

  case 342: /* $@17: %empty  */
#line 1872 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5460 "conf_parser.c"
    break;

  case 343: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1881 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5473 "conf_parser.c"
    break;

  case 349: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1894 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5482 "conf_parser.c"
    break;

  case 350: /* $@18: %empty  */
#line 1900 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5491 "conf_parser.c"
    break;

  case 354: /* cluster_type_item: KLINE  */
#line 1907 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5500 "conf_parser.c"
    break;

  case 355: /* cluster_type_item: UNKLINE  */
#line 1911 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5509 "conf_parser.c"
    break;

  case 356: /* cluster_type_item: T_DLINE  */
#line 1915 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5518 "conf_parser.c"
    break;

  case 357: /* cluster_type_item: T_UNDLINE  */
#line 1919 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5527 "conf_parser.c"
    break;

  case 358: /* cluster_type_item: XLINE  */
#line 1923 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5536 "conf_parser.c"
    break;

  case 359: /* cluster_type_item: T_UNXLINE  */
#line 1927 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5545 "conf_parser.c"
    break;

  case 360: /* cluster_type_item: RESV  */
#line 1931 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5554 "conf_parser.c"
    break;

  case 361: /* cluster_type_item: T_UNRESV  */
#line 1935 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5563 "conf_parser.c"
    break;

  case 362: /* cluster_type_item: T_LOCOPS  */
#line 1939 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5572 "conf_parser.c"
    break;

  case 363: /* cluster_type_item: T_ALL  */
#line 1943 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5581 "conf_parser.c"
    break;

  case 364: /* $@19: %empty  */
#line 1953 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECT_DEFAULT_TIMEOUT_SEC;
  block_state.retry_delay_sec.value = CONNECT_DEFAULT_RETRY_DELAY_SEC;
}
#line 5596 "conf_parser.c"
    break;

  case 365: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1963 "conf_parser.y"
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
#line 5645 "conf_parser.c"
    break;

  case 384: /* connect_name: NAME '=' QSTRING ';'  */
#line 2027 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5654 "conf_parser.c"
    break;

  case 385: /* connect_host: HOST '=' QSTRING ';'  */
#line 2033 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5663 "conf_parser.c"
    break;

  case 386: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 2039 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5672 "conf_parser.c"
    break;

  case 387: /* connect_retry_delay: RETRY_DELAY '=' timespec ';'  */
#line 2045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.retry_delay_sec.value = (yyvsp[-1].number);
}
#line 5681 "conf_parser.c"
    break;

  case 388: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 2051 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5690 "conf_parser.c"
    break;

  case 389: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2057 "conf_parser.y"
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
#line 5706 "conf_parser.c"
    break;

  case 390: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2070 "conf_parser.y"
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
#line 5722 "conf_parser.c"
    break;

  case 391: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2083 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5731 "conf_parser.c"
    break;

  case 392: /* connect_port: PORT '=' port_number ';'  */
#line 2089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5740 "conf_parser.c"
    break;

  case 393: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2095 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5749 "conf_parser.c"
    break;

  case 394: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5758 "conf_parser.c"
    break;

  case 395: /* $@20: %empty  */
#line 2105 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5766 "conf_parser.c"
    break;

  case 399: /* connect_flags_item: AUTOCONN  */
#line 2111 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5775 "conf_parser.c"
    break;

  case 400: /* connect_flags_item: T_TLS  */
#line 2115 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5784 "conf_parser.c"
    break;

  case 401: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2121 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5798 "conf_parser.c"
    break;

  case 402: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2132 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5807 "conf_parser.c"
    break;

  case 403: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2138 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5816 "conf_parser.c"
    break;

  case 404: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2144 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5825 "conf_parser.c"
    break;

  case 405: /* $@21: %empty  */
#line 2154 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5834 "conf_parser.c"
    break;

  case 406: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2158 "conf_parser.y"
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
#line 5858 "conf_parser.c"
    break;

  case 412: /* kill_user: USER '=' QSTRING ';'  */
#line 2182 "conf_parser.y"
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
#line 5881 "conf_parser.c"
    break;

  case 413: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2202 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5890 "conf_parser.c"
    break;

  case 414: /* $@22: %empty  */
#line 2212 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5899 "conf_parser.c"
    break;

  case 415: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2216 "conf_parser.y"
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
#line 5921 "conf_parser.c"
    break;

  case 421: /* deny_ip: IP '=' QSTRING ';'  */
#line 2238 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5930 "conf_parser.c"
    break;

  case 422: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2244 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5939 "conf_parser.c"
    break;

  case 428: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2259 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_error_report("Unable to add D-line exemption");
}
#line 5951 "conf_parser.c"
    break;

  case 429: /* $@23: %empty  */
#line 2272 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5960 "conf_parser.c"
    break;

  case 430: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2276 "conf_parser.y"
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
#line 5980 "conf_parser.c"
    break;

  case 436: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2296 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5989 "conf_parser.c"
    break;

  case 437: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2302 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5998 "conf_parser.c"
    break;

  case 482: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2358 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 6006 "conf_parser.c"
    break;

  case 483: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2363 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 6014 "conf_parser.c"
    break;

  case 484: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2368 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 6022 "conf_parser.c"
    break;

  case 485: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2373 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 6030 "conf_parser.c"
    break;

  case 486: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2378 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 6038 "conf_parser.c"
    break;

  case 487: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2383 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 6046 "conf_parser.c"
    break;

  case 488: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2388 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6054 "conf_parser.c"
    break;

  case 489: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2393 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6062 "conf_parser.c"
    break;

  case 490: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2398 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6070 "conf_parser.c"
    break;

  case 491: /* general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'  */
#line 2403 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 6078 "conf_parser.c"
    break;

  case 492: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2408 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6086 "conf_parser.c"
    break;

  case 493: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2413 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6094 "conf_parser.c"
    break;

  case 494: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2418 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6102 "conf_parser.c"
    break;

  case 495: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2423 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 6113 "conf_parser.c"
    break;

  case 496: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2431 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6121 "conf_parser.c"
    break;

  case 497: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2436 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6129 "conf_parser.c"
    break;

  case 498: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2441 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6137 "conf_parser.c"
    break;

  case 499: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2446 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 6145 "conf_parser.c"
    break;

  case 500: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2451 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 6153 "conf_parser.c"
    break;

  case 501: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2456 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 6161 "conf_parser.c"
    break;

  case 502: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2461 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 6169 "conf_parser.c"
    break;

  case 503: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2466 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6177 "conf_parser.c"
    break;

  case 504: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2471 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6185 "conf_parser.c"
    break;

  case 505: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2476 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6193 "conf_parser.c"
    break;

  case 506: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2481 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6201 "conf_parser.c"
    break;

  case 507: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2486 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 6209 "conf_parser.c"
    break;

  case 508: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2491 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6217 "conf_parser.c"
    break;

  case 509: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2496 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6225 "conf_parser.c"
    break;

  case 510: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2501 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6233 "conf_parser.c"
    break;

  case 511: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2506 "conf_parser.y"
{
  ConfigGeneral.disable_ident = yylval.number;
}
#line 6241 "conf_parser.c"
    break;

  case 512: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2511 "conf_parser.y"
{
  ConfigGeneral.disable_dns = yylval.number;
}
#line 6249 "conf_parser.c"
    break;

  case 513: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2516 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6257 "conf_parser.c"
    break;

  case 514: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2521 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6265 "conf_parser.c"
    break;

  case 515: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2526 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6277 "conf_parser.c"
    break;

  case 516: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2535 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6285 "conf_parser.c"
    break;

  case 517: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2540 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6293 "conf_parser.c"
    break;

  case 518: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2545 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6301 "conf_parser.c"
    break;

  case 519: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2550 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6309 "conf_parser.c"
    break;

  case 520: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2555 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6320 "conf_parser.c"
    break;

  case 521: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2563 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6328 "conf_parser.c"
    break;

  case 532: /* cloak_enabled: ENABLED '=' TBOOL ';'  */
#line 2583 "conf_parser.y"
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
#line 6348 "conf_parser.c"
    break;

  case 533: /* cloak_cidr_len_ipv4: CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2600 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6360 "conf_parser.c"
    break;

  case 534: /* cloak_cidr_len_ipv6: CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2609 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6372 "conf_parser.c"
    break;

  case 535: /* cloak_num_bits: NUM_BITS '=' NUMBER ';'  */
#line 2618 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6384 "conf_parser.c"
    break;

  case 536: /* cloak_secret: SECRET '=' QSTRING ';'  */
#line 2627 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.secret);
  ConfigCloak.secret = io_strdup((yyvsp[-1].string));
  cloak_set_secret((yyvsp[-1].string));
}
#line 6397 "conf_parser.c"
    break;

  case 537: /* cloak_suffix: SUFFIX '=' QSTRING ';'  */
#line 2637 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.suffix);
  ConfigCloak.suffix = io_strdup((yyvsp[-1].string));
  cloak_set_suffix((yyvsp[-1].string));
}
#line 6410 "conf_parser.c"
    break;

  case 558: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2672 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6418 "conf_parser.c"
    break;

  case 559: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2677 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6426 "conf_parser.c"
    break;

  case 560: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2682 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6434 "conf_parser.c"
    break;

  case 561: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2687 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6442 "conf_parser.c"
    break;

  case 562: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2692 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6450 "conf_parser.c"
    break;

  case 563: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2697 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6458 "conf_parser.c"
    break;

  case 564: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2702 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6466 "conf_parser.c"
    break;

  case 565: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2707 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6474 "conf_parser.c"
    break;

  case 566: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2712 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6482 "conf_parser.c"
    break;

  case 567: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2717 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6490 "conf_parser.c"
    break;

  case 568: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2722 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6498 "conf_parser.c"
    break;

  case 569: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2727 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6506 "conf_parser.c"
    break;

  case 570: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2732 "conf_parser.y"
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
#line 6532 "conf_parser.c"
    break;

  case 571: /* channel_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 2755 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigChannel.max_topic_length = TOPICLEN;
  else
    ConfigChannel.max_topic_length = (yyvsp[-1].number);
}
#line 6543 "conf_parser.c"
    break;

  case 572: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2763 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6551 "conf_parser.c"
    break;

  case 573: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2768 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6559 "conf_parser.c"
    break;

  case 586: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2790 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6568 "conf_parser.c"
    break;

  case 587: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2796 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6582 "conf_parser.c"
    break;

  case 588: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2807 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6594 "conf_parser.c"
    break;

  case 589: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2816 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6603 "conf_parser.c"
    break;

  case 590: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2822 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6612 "conf_parser.c"
    break;

  case 591: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2828 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6621 "conf_parser.c"
    break;

  case 592: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2834 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6633 "conf_parser.c"
    break;

  case 593: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2843 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6642 "conf_parser.c"
    break;


#line 6646 "conf_parser.c"

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

