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
#line 16 "conf_parser.y"

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
/* "%code requires" blocks.  */
#line 12 "conf_parser.y"

#include <stdbool.h>

#line 288 "conf_parser.c"

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
    ANTI_SPAM_EXIT_MESSAGE_TIME = 261, /* ANTI_SPAM_EXIT_MESSAGE_TIME  */
    AUTOCONN = 262,                /* AUTOCONN  */
    AWAY_COUNT = 263,              /* AWAY_COUNT  */
    AWAY_TIME = 264,               /* AWAY_TIME  */
    BYPASS = 265,                  /* BYPASS  */
    BYTES = 266,                   /* BYTES  */
    KBYTES = 267,                  /* KBYTES  */
    KIBYTES = 268,                 /* KIBYTES  */
    MBYTES = 269,                  /* MBYTES  */
    MIBYTES = 270,                 /* MIBYTES  */
    GBYTES = 271,                  /* GBYTES  */
    GIBYTES = 272,                 /* GIBYTES  */
    CALLER_ID_WAIT = 273,          /* CALLER_ID_WAIT  */
    CAN_FLOOD = 274,               /* CAN_FLOOD  */
    CHANNEL = 275,                 /* CHANNEL  */
    CIDR_BITLEN_IPV4 = 276,        /* CIDR_BITLEN_IPV4  */
    CIDR_BITLEN_IPV6 = 277,        /* CIDR_BITLEN_IPV6  */
    CIDR_LEN_IPV4 = 278,           /* CIDR_LEN_IPV4  */
    CIDR_LEN_IPV6 = 279,           /* CIDR_LEN_IPV6  */
    CLASS = 280,                   /* CLASS  */
    CLIENT = 281,                  /* CLIENT  */
    CLOAK = 282,                   /* CLOAK  */
    CLOSE = 283,                   /* CLOSE  */
    CONNECT = 284,                 /* CONNECT  */
    DEFAULT_FLOODCOUNT = 285,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 286,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 287, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 288, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 289,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 290,                   /* DEFER  */
    DENY = 291,                    /* DENY  */
    DESCRIPTION = 292,             /* DESCRIPTION  */
    DIE = 293,                     /* DIE  */
    DISABLE_DNS = 294,             /* DISABLE_DNS  */
    DISABLE_IDENT = 295,           /* DISABLE_IDENT  */
    DISABLE_FAKE_CHANNELS = 296,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 297, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 298,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 299,         /* DLINE_MIN_CIDR6  */
    EMAIL = 300,                   /* EMAIL  */
    ENABLED = 301,                 /* ENABLED  */
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
    INPUT_FLOOD = 321,             /* INPUT_FLOOD  */
    INVISIBLE_ON_CONNECT = 322,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 323,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 324,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 325,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 326,      /* INVITE_EXPIRE_TIME  */
    IP = 327,                      /* IP  */
    IRCD_AUTH = 328,               /* IRCD_AUTH  */
    IRCD_FLAGS = 329,              /* IRCD_FLAGS  */
    IRCD_SID = 330,                /* IRCD_SID  */
    JOIN = 331,                    /* JOIN  */
    KILL = 332,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 333,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 334,                   /* KLINE  */
    KLINE_EXEMPT = 335,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 336,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 337,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 338,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 339,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 340,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 341,               /* LEAF_MASK  */
    LISTEN = 342,                  /* LISTEN  */
    LOADMODULE = 343,              /* LOADMODULE  */
    MASK = 344,                    /* MASK  */
    MASS = 345,                    /* MASS  */
    MAX_ACCEPT = 346,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 347,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 348,                /* MAX_BANS  */
    MAX_BANS_LARGE = 349,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 350,            /* MAX_CHANNELS  */
    MAX_IDLE = 351,                /* MAX_IDLE  */
    MAX_INVITES = 352,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 353,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 354,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 355,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 356,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 357,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 358,              /* MAX_NUMBER  */
    MAX_TARGETS = 359,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 360,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 361,                 /* MESSAGE  */
    MIN_IDLE = 362,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 363,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 364,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 365,                  /* MODULE  */
    MODULE_BASE_PATH = 366,        /* MODULE_BASE_PATH  */
    MOTD = 367,                    /* MOTD  */
    MOTD_FILE = 368,               /* MOTD_FILE  */
    NAME = 369,                    /* NAME  */
    NEED_IDENT = 370,              /* NEED_IDENT  */
    NEED_PASSWORD = 371,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 372,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 373,            /* NETWORK_NAME  */
    NICK = 374,                    /* NICK  */
    NO_TILDE = 375,                /* NO_TILDE  */
    NUM_BITS = 376,                /* NUM_BITS  */
    NUMBER_PER_CIDR = 377,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 378,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 379,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 380,             /* OPER_UMODES  */
    OPERATOR = 381,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 382,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 383,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 384,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 385,                /* PASSWORD  */
    PATH = 386,                    /* PATH  */
    PING_COOKIE = 387,             /* PING_COOKIE  */
    PING_TIME = 388,               /* PING_TIME  */
    PORT = 389,                    /* PORT  */
    RANDOM_IDLE = 390,             /* RANDOM_IDLE  */
    REASON = 391,                  /* REASON  */
    REGISTRATION_TIMEOUT = 392,    /* REGISTRATION_TIMEOUT  */
    REHASH = 393,                  /* REHASH  */
    REMOTE = 394,                  /* REMOTE  */
    REMOTEBAN = 395,               /* REMOTEBAN  */
    REQUIRED = 396,                /* REQUIRED  */
    RESIDENT = 397,                /* RESIDENT  */
    RESV = 398,                    /* RESV  */
    RESV_EXEMPT = 399,             /* RESV_EXEMPT  */
    RETRY_DELAY = 400,             /* RETRY_DELAY  */
    SECRET = 401,                  /* SECRET  */
    SECONDS = 402,                 /* SECONDS  */
    MINUTES = 403,                 /* MINUTES  */
    HOURS = 404,                   /* HOURS  */
    DAYS = 405,                    /* DAYS  */
    WEEKS = 406,                   /* WEEKS  */
    SEND_PASSWORD = 407,           /* SEND_PASSWORD  */
    SENDQ = 408,                   /* SENDQ  */
    SERVERHIDE = 409,              /* SERVERHIDE  */
    SERVERINFO = 410,              /* SERVERINFO  */
    SHORT_MOTD = 411,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 412,       /* SPECIALS_IN_IDENT  */
    SPOOF = 413,                   /* SPOOF  */
    SQUIT = 414,                   /* SQUIT  */
    STATS_E_DISABLED = 415,        /* STATS_E_DISABLED  */
    STATS_U_OPER_ONLY = 416,       /* STATS_U_OPER_ONLY  */
    SUFFIX = 417,                  /* SUFFIX  */
    T_ALL = 418,                   /* T_ALL  */
    T_BIND = 419,                  /* T_BIND  */
    T_COMMAND = 420,               /* T_COMMAND  */
    T_CLUSTER = 421,               /* T_CLUSTER  */
    T_DEBUG = 422,                 /* T_DEBUG  */
    T_DLINE = 423,                 /* T_DLINE  */
    T_FILE = 424,                  /* T_FILE  */
    T_GLOBOPS = 425,               /* T_GLOBOPS  */
    T_IPV4 = 426,                  /* T_IPV4  */
    T_IPV6 = 427,                  /* T_IPV6  */
    T_LOCOPS = 428,                /* T_LOCOPS  */
    T_LOG = 429,                   /* T_LOG  */
    T_OPME = 430,                  /* T_OPME  */
    T_PREPEND = 431,               /* T_PREPEND  */
    T_PSEUDO = 432,                /* T_PSEUDO  */
    T_RECVQ = 433,                 /* T_RECVQ  */
    T_RESTART = 434,               /* T_RESTART  */
    T_SERVER = 435,                /* T_SERVER  */
    T_SERVICE = 436,               /* T_SERVICE  */
    T_SET = 437,                   /* T_SET  */
    T_SHARED = 438,                /* T_SHARED  */
    T_SIZE = 439,                  /* T_SIZE  */
    T_TARGET = 440,                /* T_TARGET  */
    T_TLS = 441,                   /* T_TLS  */
    T_UMODES = 442,                /* T_UMODES  */
    T_UNDLINE = 443,               /* T_UNDLINE  */
    T_UNLIMITED = 444,             /* T_UNLIMITED  */
    T_UNRESV = 445,                /* T_UNRESV  */
    T_UNXLINE = 446,               /* T_UNXLINE  */
    T_WEBIRC = 447,                /* T_WEBIRC  */
    TBOOL = 448,                   /* TBOOL  */
    THROTTLE_COUNT = 449,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 450,           /* THROTTLE_TIME  */
    TIMEOUT = 451,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 452,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 453, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 454,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 455, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 456,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 457,           /* TS_WARN_DELTA  */
    TWODOTS = 458,                 /* TWODOTS  */
    TYPE = 459,                    /* TYPE  */
    UNKLINE = 460,                 /* UNKLINE  */
    USE_LOGGING = 461,             /* USE_LOGGING  */
    USER = 462,                    /* USER  */
    VHOST = 463,                   /* VHOST  */
    VHOST6 = 464,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 465,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 466,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 467,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 468,                   /* XLINE  */
    XLINE_EXEMPT = 469,            /* XLINE_EXEMPT  */
    QSTRING = 470,                 /* QSTRING  */
    DECIMAL = 471,                 /* DECIMAL  */
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
#define ANTI_SPAM_EXIT_MESSAGE_TIME 261
#define AUTOCONN 262
#define AWAY_COUNT 263
#define AWAY_TIME 264
#define BYPASS 265
#define BYTES 266
#define KBYTES 267
#define KIBYTES 268
#define MBYTES 269
#define MIBYTES 270
#define GBYTES 271
#define GIBYTES 272
#define CALLER_ID_WAIT 273
#define CAN_FLOOD 274
#define CHANNEL 275
#define CIDR_BITLEN_IPV4 276
#define CIDR_BITLEN_IPV6 277
#define CIDR_LEN_IPV4 278
#define CIDR_LEN_IPV6 279
#define CLASS 280
#define CLIENT 281
#define CLOAK 282
#define CLOSE 283
#define CONNECT 284
#define DEFAULT_FLOODCOUNT 285
#define DEFAULT_FLOODTIME 286
#define DEFAULT_JOIN_FLOOD_COUNT 287
#define DEFAULT_JOIN_FLOOD_TIME 288
#define DEFAULT_MAX_CLIENTS 289
#define DEFER 290
#define DENY 291
#define DESCRIPTION 292
#define DIE 293
#define DISABLE_DNS 294
#define DISABLE_IDENT 295
#define DISABLE_FAKE_CHANNELS 296
#define DISABLE_REMOTE_COMMANDS 297
#define DLINE_MIN_CIDR 298
#define DLINE_MIN_CIDR6 299
#define EMAIL 300
#define ENABLED 301
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
#define INPUT_FLOOD 321
#define INVISIBLE_ON_CONNECT 322
#define INVITE_CLIENT_COUNT 323
#define INVITE_CLIENT_TIME 324
#define INVITE_DELAY_CHANNEL 325
#define INVITE_EXPIRE_TIME 326
#define IP 327
#define IRCD_AUTH 328
#define IRCD_FLAGS 329
#define IRCD_SID 330
#define JOIN 331
#define KILL 332
#define KILL_CHASE_TIME_LIMIT 333
#define KLINE 334
#define KLINE_EXEMPT 335
#define KLINE_MIN_CIDR 336
#define KLINE_MIN_CIDR6 337
#define KNOCK_CLIENT_COUNT 338
#define KNOCK_CLIENT_TIME 339
#define KNOCK_DELAY_CHANNEL 340
#define LEAF_MASK 341
#define LISTEN 342
#define LOADMODULE 343
#define MASK 344
#define MASS 345
#define MAX_ACCEPT 346
#define MAX_AWAY_LENGTH 347
#define MAX_BANS 348
#define MAX_BANS_LARGE 349
#define MAX_CHANNELS 350
#define MAX_IDLE 351
#define MAX_INVITES 352
#define MAX_KICK_LENGTH 353
#define MAX_MONITOR 354
#define MAX_NICK_CHANGES 355
#define MAX_NICK_LENGTH 356
#define MAX_NICK_TIME 357
#define MAX_NUMBER 358
#define MAX_TARGETS 359
#define MAX_TOPIC_LENGTH 360
#define MESSAGE 361
#define MIN_IDLE 362
#define MIN_NONWILDCARD 363
#define MIN_NONWILDCARD_SIMPLE 364
#define MODULE 365
#define MODULE_BASE_PATH 366
#define MOTD 367
#define MOTD_FILE 368
#define NAME 369
#define NEED_IDENT 370
#define NEED_PASSWORD 371
#define NETWORK_DESCRIPTION 372
#define NETWORK_NAME 373
#define NICK 374
#define NO_TILDE 375
#define NUM_BITS 376
#define NUMBER_PER_CIDR 377
#define NUMBER_PER_IP_GLOBAL 378
#define NUMBER_PER_IP_LOCAL 379
#define OPER_UMODES 380
#define OPERATOR 381
#define OPERS_BYPASS_CALLERID 382
#define PACE_WAIT 383
#define PACE_WAIT_SIMPLE 384
#define PASSWORD 385
#define PATH 386
#define PING_COOKIE 387
#define PING_TIME 388
#define PORT 389
#define RANDOM_IDLE 390
#define REASON 391
#define REGISTRATION_TIMEOUT 392
#define REHASH 393
#define REMOTE 394
#define REMOTEBAN 395
#define REQUIRED 396
#define RESIDENT 397
#define RESV 398
#define RESV_EXEMPT 399
#define RETRY_DELAY 400
#define SECRET 401
#define SECONDS 402
#define MINUTES 403
#define HOURS 404
#define DAYS 405
#define WEEKS 406
#define SEND_PASSWORD 407
#define SENDQ 408
#define SERVERHIDE 409
#define SERVERINFO 410
#define SHORT_MOTD 411
#define SPECIALS_IN_IDENT 412
#define SPOOF 413
#define SQUIT 414
#define STATS_E_DISABLED 415
#define STATS_U_OPER_ONLY 416
#define SUFFIX 417
#define T_ALL 418
#define T_BIND 419
#define T_COMMAND 420
#define T_CLUSTER 421
#define T_DEBUG 422
#define T_DLINE 423
#define T_FILE 424
#define T_GLOBOPS 425
#define T_IPV4 426
#define T_IPV6 427
#define T_LOCOPS 428
#define T_LOG 429
#define T_OPME 430
#define T_PREPEND 431
#define T_PSEUDO 432
#define T_RECVQ 433
#define T_RESTART 434
#define T_SERVER 435
#define T_SERVICE 436
#define T_SET 437
#define T_SHARED 438
#define T_SIZE 439
#define T_TARGET 440
#define T_TLS 441
#define T_UMODES 442
#define T_UNDLINE 443
#define T_UNLIMITED 444
#define T_UNRESV 445
#define T_UNXLINE 446
#define T_WEBIRC 447
#define TBOOL 448
#define THROTTLE_COUNT 449
#define THROTTLE_TIME 450
#define TIMEOUT 451
#define TLS_CERTIFICATE_FILE 452
#define TLS_CERTIFICATE_FINGERPRINT 453
#define TLS_PRIVATE_KEY_FILE 454
#define TLS_CONNECTION_REQUIRED 455
#define TS_MAX_DELTA 456
#define TS_WARN_DELTA 457
#define TWODOTS 458
#define TYPE 459
#define UNKLINE 460
#define USE_LOGGING 461
#define USER 462
#define VHOST 463
#define VHOST6 464
#define WARN_NO_CONNECT_BLOCK 465
#define WHOIS 466
#define WHOWAS_HISTORY_LENGTH 467
#define XLINE 468
#define XLINE_EXEMPT 469
#define QSTRING 470
#define DECIMAL 471
#define NUMBER 472

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 194 "conf_parser.y"

  bool boolean;
  unsigned int number;
  char *string;

#line 748 "conf_parser.c"

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
  YYSYMBOL_ANTI_SPAM_EXIT_MESSAGE_TIME = 6, /* ANTI_SPAM_EXIT_MESSAGE_TIME  */
  YYSYMBOL_AUTOCONN = 7,                   /* AUTOCONN  */
  YYSYMBOL_AWAY_COUNT = 8,                 /* AWAY_COUNT  */
  YYSYMBOL_AWAY_TIME = 9,                  /* AWAY_TIME  */
  YYSYMBOL_BYPASS = 10,                    /* BYPASS  */
  YYSYMBOL_BYTES = 11,                     /* BYTES  */
  YYSYMBOL_KBYTES = 12,                    /* KBYTES  */
  YYSYMBOL_KIBYTES = 13,                   /* KIBYTES  */
  YYSYMBOL_MBYTES = 14,                    /* MBYTES  */
  YYSYMBOL_MIBYTES = 15,                   /* MIBYTES  */
  YYSYMBOL_GBYTES = 16,                    /* GBYTES  */
  YYSYMBOL_GIBYTES = 17,                   /* GIBYTES  */
  YYSYMBOL_CALLER_ID_WAIT = 18,            /* CALLER_ID_WAIT  */
  YYSYMBOL_CAN_FLOOD = 19,                 /* CAN_FLOOD  */
  YYSYMBOL_CHANNEL = 20,                   /* CHANNEL  */
  YYSYMBOL_CIDR_BITLEN_IPV4 = 21,          /* CIDR_BITLEN_IPV4  */
  YYSYMBOL_CIDR_BITLEN_IPV6 = 22,          /* CIDR_BITLEN_IPV6  */
  YYSYMBOL_CIDR_LEN_IPV4 = 23,             /* CIDR_LEN_IPV4  */
  YYSYMBOL_CIDR_LEN_IPV6 = 24,             /* CIDR_LEN_IPV6  */
  YYSYMBOL_CLASS = 25,                     /* CLASS  */
  YYSYMBOL_CLIENT = 26,                    /* CLIENT  */
  YYSYMBOL_CLOAK = 27,                     /* CLOAK  */
  YYSYMBOL_CLOSE = 28,                     /* CLOSE  */
  YYSYMBOL_CONNECT = 29,                   /* CONNECT  */
  YYSYMBOL_DEFAULT_FLOODCOUNT = 30,        /* DEFAULT_FLOODCOUNT  */
  YYSYMBOL_DEFAULT_FLOODTIME = 31,         /* DEFAULT_FLOODTIME  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_COUNT = 32,  /* DEFAULT_JOIN_FLOOD_COUNT  */
  YYSYMBOL_DEFAULT_JOIN_FLOOD_TIME = 33,   /* DEFAULT_JOIN_FLOOD_TIME  */
  YYSYMBOL_DEFAULT_MAX_CLIENTS = 34,       /* DEFAULT_MAX_CLIENTS  */
  YYSYMBOL_DEFER = 35,                     /* DEFER  */
  YYSYMBOL_DENY = 36,                      /* DENY  */
  YYSYMBOL_DESCRIPTION = 37,               /* DESCRIPTION  */
  YYSYMBOL_DIE = 38,                       /* DIE  */
  YYSYMBOL_DISABLE_DNS = 39,               /* DISABLE_DNS  */
  YYSYMBOL_DISABLE_IDENT = 40,             /* DISABLE_IDENT  */
  YYSYMBOL_DISABLE_FAKE_CHANNELS = 41,     /* DISABLE_FAKE_CHANNELS  */
  YYSYMBOL_DISABLE_REMOTE_COMMANDS = 42,   /* DISABLE_REMOTE_COMMANDS  */
  YYSYMBOL_DLINE_MIN_CIDR = 43,            /* DLINE_MIN_CIDR  */
  YYSYMBOL_DLINE_MIN_CIDR6 = 44,           /* DLINE_MIN_CIDR6  */
  YYSYMBOL_EMAIL = 45,                     /* EMAIL  */
  YYSYMBOL_ENABLED = 46,                   /* ENABLED  */
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
  YYSYMBOL_INPUT_FLOOD = 66,               /* INPUT_FLOOD  */
  YYSYMBOL_INVISIBLE_ON_CONNECT = 67,      /* INVISIBLE_ON_CONNECT  */
  YYSYMBOL_INVITE_CLIENT_COUNT = 68,       /* INVITE_CLIENT_COUNT  */
  YYSYMBOL_INVITE_CLIENT_TIME = 69,        /* INVITE_CLIENT_TIME  */
  YYSYMBOL_INVITE_DELAY_CHANNEL = 70,      /* INVITE_DELAY_CHANNEL  */
  YYSYMBOL_INVITE_EXPIRE_TIME = 71,        /* INVITE_EXPIRE_TIME  */
  YYSYMBOL_IP = 72,                        /* IP  */
  YYSYMBOL_IRCD_AUTH = 73,                 /* IRCD_AUTH  */
  YYSYMBOL_IRCD_FLAGS = 74,                /* IRCD_FLAGS  */
  YYSYMBOL_IRCD_SID = 75,                  /* IRCD_SID  */
  YYSYMBOL_JOIN = 76,                      /* JOIN  */
  YYSYMBOL_KILL = 77,                      /* KILL  */
  YYSYMBOL_KILL_CHASE_TIME_LIMIT = 78,     /* KILL_CHASE_TIME_LIMIT  */
  YYSYMBOL_KLINE = 79,                     /* KLINE  */
  YYSYMBOL_KLINE_EXEMPT = 80,              /* KLINE_EXEMPT  */
  YYSYMBOL_KLINE_MIN_CIDR = 81,            /* KLINE_MIN_CIDR  */
  YYSYMBOL_KLINE_MIN_CIDR6 = 82,           /* KLINE_MIN_CIDR6  */
  YYSYMBOL_KNOCK_CLIENT_COUNT = 83,        /* KNOCK_CLIENT_COUNT  */
  YYSYMBOL_KNOCK_CLIENT_TIME = 84,         /* KNOCK_CLIENT_TIME  */
  YYSYMBOL_KNOCK_DELAY_CHANNEL = 85,       /* KNOCK_DELAY_CHANNEL  */
  YYSYMBOL_LEAF_MASK = 86,                 /* LEAF_MASK  */
  YYSYMBOL_LISTEN = 87,                    /* LISTEN  */
  YYSYMBOL_LOADMODULE = 88,                /* LOADMODULE  */
  YYSYMBOL_MASK = 89,                      /* MASK  */
  YYSYMBOL_MASS = 90,                      /* MASS  */
  YYSYMBOL_MAX_ACCEPT = 91,                /* MAX_ACCEPT  */
  YYSYMBOL_MAX_AWAY_LENGTH = 92,           /* MAX_AWAY_LENGTH  */
  YYSYMBOL_MAX_BANS = 93,                  /* MAX_BANS  */
  YYSYMBOL_MAX_BANS_LARGE = 94,            /* MAX_BANS_LARGE  */
  YYSYMBOL_MAX_CHANNELS = 95,              /* MAX_CHANNELS  */
  YYSYMBOL_MAX_IDLE = 96,                  /* MAX_IDLE  */
  YYSYMBOL_MAX_INVITES = 97,               /* MAX_INVITES  */
  YYSYMBOL_MAX_KICK_LENGTH = 98,           /* MAX_KICK_LENGTH  */
  YYSYMBOL_MAX_MONITOR = 99,               /* MAX_MONITOR  */
  YYSYMBOL_MAX_NICK_CHANGES = 100,         /* MAX_NICK_CHANGES  */
  YYSYMBOL_MAX_NICK_LENGTH = 101,          /* MAX_NICK_LENGTH  */
  YYSYMBOL_MAX_NICK_TIME = 102,            /* MAX_NICK_TIME  */
  YYSYMBOL_MAX_NUMBER = 103,               /* MAX_NUMBER  */
  YYSYMBOL_MAX_TARGETS = 104,              /* MAX_TARGETS  */
  YYSYMBOL_MAX_TOPIC_LENGTH = 105,         /* MAX_TOPIC_LENGTH  */
  YYSYMBOL_MESSAGE = 106,                  /* MESSAGE  */
  YYSYMBOL_MIN_IDLE = 107,                 /* MIN_IDLE  */
  YYSYMBOL_MIN_NONWILDCARD = 108,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 109,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 110,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 111,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 112,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 113,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 114,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 115,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 116,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 117,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 118,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 119,                     /* NICK  */
  YYSYMBOL_NO_TILDE = 120,                 /* NO_TILDE  */
  YYSYMBOL_NUM_BITS = 121,                 /* NUM_BITS  */
  YYSYMBOL_NUMBER_PER_CIDR = 122,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 123,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 124,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_UMODES = 125,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 126,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 127,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 128,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 129,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 130,                 /* PASSWORD  */
  YYSYMBOL_PATH = 131,                     /* PATH  */
  YYSYMBOL_PING_COOKIE = 132,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 133,                /* PING_TIME  */
  YYSYMBOL_PORT = 134,                     /* PORT  */
  YYSYMBOL_RANDOM_IDLE = 135,              /* RANDOM_IDLE  */
  YYSYMBOL_REASON = 136,                   /* REASON  */
  YYSYMBOL_REGISTRATION_TIMEOUT = 137,     /* REGISTRATION_TIMEOUT  */
  YYSYMBOL_REHASH = 138,                   /* REHASH  */
  YYSYMBOL_REMOTE = 139,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 140,                /* REMOTEBAN  */
  YYSYMBOL_REQUIRED = 141,                 /* REQUIRED  */
  YYSYMBOL_RESIDENT = 142,                 /* RESIDENT  */
  YYSYMBOL_RESV = 143,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 144,              /* RESV_EXEMPT  */
  YYSYMBOL_RETRY_DELAY = 145,              /* RETRY_DELAY  */
  YYSYMBOL_SECRET = 146,                   /* SECRET  */
  YYSYMBOL_SECONDS = 147,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 148,                  /* MINUTES  */
  YYSYMBOL_HOURS = 149,                    /* HOURS  */
  YYSYMBOL_DAYS = 150,                     /* DAYS  */
  YYSYMBOL_WEEKS = 151,                    /* WEEKS  */
  YYSYMBOL_SEND_PASSWORD = 152,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 153,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 154,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 155,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 156,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 157,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 158,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 159,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 160,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_U_OPER_ONLY = 161,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_SUFFIX = 162,                   /* SUFFIX  */
  YYSYMBOL_T_ALL = 163,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 164,                   /* T_BIND  */
  YYSYMBOL_T_COMMAND = 165,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 166,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 167,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 168,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 169,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 170,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 171,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 172,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 173,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 174,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 175,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 176,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 177,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 178,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 179,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 180,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 181,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 182,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 183,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 184,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 185,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 186,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 187,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 188,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 189,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 190,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 191,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 192,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 193,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 194,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 195,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 196,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 197,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 198, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_PRIVATE_KEY_FILE = 199,     /* TLS_PRIVATE_KEY_FILE  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 200,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TS_MAX_DELTA = 201,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 202,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 203,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 204,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 205,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 206,              /* USE_LOGGING  */
  YYSYMBOL_USER = 207,                     /* USER  */
  YYSYMBOL_VHOST = 208,                    /* VHOST  */
  YYSYMBOL_VHOST6 = 209,                   /* VHOST6  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 210,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 211,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 212,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 213,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 214,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 215,                  /* QSTRING  */
  YYSYMBOL_DECIMAL = 216,                  /* DECIMAL  */
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
  YYSYMBOL_time_component = 229,           /* time_component  */
  YYSYMBOL_time_unit = 230,                /* time_unit  */
  YYSYMBOL_sizespec = 231,                 /* sizespec  */
  YYSYMBOL_size_components = 232,          /* size_components  */
  YYSYMBOL_size_component = 233,           /* size_component  */
  YYSYMBOL_size_unit = 234,                /* size_unit  */
  YYSYMBOL_port_number = 235,              /* port_number  */
  YYSYMBOL_module_base_path_entry = 236,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 237,         /* loadmodule_entry  */
  YYSYMBOL_module_string = 238,            /* module_string  */
  YYSYMBOL_module_attributes = 239,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 240,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 241,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 242,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 243,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 244,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 245, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_tls_private_key_file = 246, /* serverinfo_tls_private_key_file  */
  YYSYMBOL_serverinfo_name = 247,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 248,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 249,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 250,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 251, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 252, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 253, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_motd_file = 254,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 255,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 256,              /* admin_entry  */
  YYSYMBOL_admin_items = 257,              /* admin_items  */
  YYSYMBOL_admin_item = 258,               /* admin_item  */
  YYSYMBOL_admin_name = 259,               /* admin_name  */
  YYSYMBOL_admin_email = 260,              /* admin_email  */
  YYSYMBOL_admin_description = 261,        /* admin_description  */
  YYSYMBOL_motd_entry = 262,               /* motd_entry  */
  YYSYMBOL_263_1 = 263,                    /* $@1  */
  YYSYMBOL_motd_items = 264,               /* motd_items  */
  YYSYMBOL_motd_item = 265,                /* motd_item  */
  YYSYMBOL_motd_mask = 266,                /* motd_mask  */
  YYSYMBOL_motd_file = 267,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 268,             /* pseudo_entry  */
  YYSYMBOL_269_2 = 269,                    /* $@2  */
  YYSYMBOL_pseudo_items = 270,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 271,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 272,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 273,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 274,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 275,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 276,            /* logging_entry  */
  YYSYMBOL_logging_items = 277,            /* logging_items  */
  YYSYMBOL_logging_item = 278,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 279,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 280,       /* logging_file_entry  */
  YYSYMBOL_281_3 = 281,                    /* $@3  */
  YYSYMBOL_logging_file_items = 282,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 283,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 284,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 285,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 286,        /* logging_file_type  */
  YYSYMBOL_287_4 = 287,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 288,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 289,               /* oper_entry  */
  YYSYMBOL_290_5 = 290,                    /* $@5  */
  YYSYMBOL_oper_items = 291,               /* oper_items  */
  YYSYMBOL_oper_item = 292,                /* oper_item  */
  YYSYMBOL_oper_name = 293,                /* oper_name  */
  YYSYMBOL_oper_user = 294,                /* oper_user  */
  YYSYMBOL_oper_password = 295,            /* oper_password  */
  YYSYMBOL_oper_whois = 296,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 297,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 298, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 299, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 300,               /* oper_class  */
  YYSYMBOL_oper_umodes = 301,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 302,               /* oper_flags  */
  YYSYMBOL_303_6 = 303,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 304,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 305,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 306,              /* class_entry  */
  YYSYMBOL_307_7 = 307,                    /* $@7  */
  YYSYMBOL_class_items = 308,              /* class_items  */
  YYSYMBOL_class_item = 309,               /* class_item  */
  YYSYMBOL_class_name = 310,               /* class_name  */
  YYSYMBOL_class_ping_time = 311,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 312, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 313, /* class_number_per_ip_global  */
  YYSYMBOL_class_max_channels = 314,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 315,         /* class_max_number  */
  YYSYMBOL_class_sendq = 316,              /* class_sendq  */
  YYSYMBOL_class_recvq = 317,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 318,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 319,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 320,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 321,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 322,           /* class_max_idle  */
  YYSYMBOL_class_flags = 323,              /* class_flags  */
  YYSYMBOL_324_8 = 324,                    /* $@8  */
  YYSYMBOL_class_flags_items = 325,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 326,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 327,             /* listen_entry  */
  YYSYMBOL_328_9 = 328,                    /* $@9  */
  YYSYMBOL_listen_flags = 329,             /* listen_flags  */
  YYSYMBOL_330_10 = 330,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 331,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 332,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 333,             /* listen_items  */
  YYSYMBOL_listen_item = 334,              /* listen_item  */
  YYSYMBOL_listen_port = 335,              /* listen_port  */
  YYSYMBOL_336_11 = 336,                   /* $@11  */
  YYSYMBOL_port_items = 337,               /* port_items  */
  YYSYMBOL_port_item = 338,                /* port_item  */
  YYSYMBOL_listen_address = 339,           /* listen_address  */
  YYSYMBOL_listen_host = 340,              /* listen_host  */
  YYSYMBOL_auth_entry = 341,               /* auth_entry  */
  YYSYMBOL_342_12 = 342,                   /* $@12  */
  YYSYMBOL_auth_items = 343,               /* auth_items  */
  YYSYMBOL_auth_item = 344,                /* auth_item  */
  YYSYMBOL_auth_user = 345,                /* auth_user  */
  YYSYMBOL_auth_passwd = 346,              /* auth_passwd  */
  YYSYMBOL_auth_class = 347,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 348,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 349,               /* auth_flags  */
  YYSYMBOL_350_13 = 350,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 351,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 352,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 353,               /* auth_spoof  */
  YYSYMBOL_resv_entry = 354,               /* resv_entry  */
  YYSYMBOL_355_14 = 355,                   /* $@14  */
  YYSYMBOL_resv_items = 356,               /* resv_items  */
  YYSYMBOL_resv_item = 357,                /* resv_item  */
  YYSYMBOL_resv_mask = 358,                /* resv_mask  */
  YYSYMBOL_resv_reason = 359,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 360,              /* resv_exempt  */
  YYSYMBOL_service_entry = 361,            /* service_entry  */
  YYSYMBOL_service_items = 362,            /* service_items  */
  YYSYMBOL_service_item = 363,             /* service_item  */
  YYSYMBOL_service_name = 364,             /* service_name  */
  YYSYMBOL_shared_entry = 365,             /* shared_entry  */
  YYSYMBOL_366_15 = 366,                   /* $@15  */
  YYSYMBOL_shared_items = 367,             /* shared_items  */
  YYSYMBOL_shared_item = 368,              /* shared_item  */
  YYSYMBOL_shared_name = 369,              /* shared_name  */
  YYSYMBOL_shared_user = 370,              /* shared_user  */
  YYSYMBOL_shared_type = 371,              /* shared_type  */
  YYSYMBOL_372_16 = 372,                   /* $@16  */
  YYSYMBOL_shared_types = 373,             /* shared_types  */
  YYSYMBOL_shared_type_item = 374,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 375,            /* cluster_entry  */
  YYSYMBOL_376_17 = 376,                   /* $@17  */
  YYSYMBOL_cluster_items = 377,            /* cluster_items  */
  YYSYMBOL_cluster_item = 378,             /* cluster_item  */
  YYSYMBOL_cluster_name = 379,             /* cluster_name  */
  YYSYMBOL_cluster_type = 380,             /* cluster_type  */
  YYSYMBOL_381_18 = 381,                   /* $@18  */
  YYSYMBOL_cluster_types = 382,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 383,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 384,            /* connect_entry  */
  YYSYMBOL_385_19 = 385,                   /* $@19  */
  YYSYMBOL_connect_items = 386,            /* connect_items  */
  YYSYMBOL_connect_item = 387,             /* connect_item  */
  YYSYMBOL_connect_name = 388,             /* connect_name  */
  YYSYMBOL_connect_host = 389,             /* connect_host  */
  YYSYMBOL_connect_timeout = 390,          /* connect_timeout  */
  YYSYMBOL_connect_retry_delay = 391,      /* connect_retry_delay  */
  YYSYMBOL_connect_bind = 392,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 393,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 394,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 395, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 396,             /* connect_port  */
  YYSYMBOL_connect_aftype = 397,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 398,            /* connect_flags  */
  YYSYMBOL_399_20 = 399,                   /* $@20  */
  YYSYMBOL_connect_flags_items = 400,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 401,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 402,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 403,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 404,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 405,            /* connect_class  */
  YYSYMBOL_kill_entry = 406,               /* kill_entry  */
  YYSYMBOL_407_21 = 407,                   /* $@21  */
  YYSYMBOL_kill_items = 408,               /* kill_items  */
  YYSYMBOL_kill_item = 409,                /* kill_item  */
  YYSYMBOL_kill_user = 410,                /* kill_user  */
  YYSYMBOL_kill_reason = 411,              /* kill_reason  */
  YYSYMBOL_deny_entry = 412,               /* deny_entry  */
  YYSYMBOL_413_22 = 413,                   /* $@22  */
  YYSYMBOL_deny_items = 414,               /* deny_items  */
  YYSYMBOL_deny_item = 415,                /* deny_item  */
  YYSYMBOL_deny_ip = 416,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 417,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 418,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 419,             /* exempt_items  */
  YYSYMBOL_exempt_item = 420,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 421,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 422,              /* gecos_entry  */
  YYSYMBOL_423_23 = 423,                   /* $@23  */
  YYSYMBOL_gecos_items = 424,              /* gecos_items  */
  YYSYMBOL_gecos_item = 425,               /* gecos_item  */
  YYSYMBOL_gecos_name = 426,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 427,             /* gecos_reason  */
  YYSYMBOL_general_entry = 428,            /* general_entry  */
  YYSYMBOL_general_items = 429,            /* general_items  */
  YYSYMBOL_general_item = 430,             /* general_item  */
  YYSYMBOL_general_away_count = 431,       /* general_away_count  */
  YYSYMBOL_general_away_time = 432,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 433,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 434, /* general_whowas_history_length  */
  YYSYMBOL_general_dline_min_cidr = 435,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 436,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 437,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 438,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 439, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_max_nick_time = 440,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 441, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 442,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 443,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 444, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 445,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 446,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 447, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 448, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 449, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_u_oper_only = 450, /* general_stats_u_oper_only  */
  YYSYMBOL_general_pace_wait = 451,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 452,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 453, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 454, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 455,       /* general_short_motd  */
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
  YYSYMBOL_general_ident_timeout = 468,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 469, /* general_registration_timeout  */
  YYSYMBOL_cloak_entry = 470,              /* cloak_entry  */
  YYSYMBOL_cloak_items = 471,              /* cloak_items  */
  YYSYMBOL_cloak_item = 472,               /* cloak_item  */
  YYSYMBOL_cloak_enabled = 473,            /* cloak_enabled  */
  YYSYMBOL_cloak_cidr_len_ipv4 = 474,      /* cloak_cidr_len_ipv4  */
  YYSYMBOL_cloak_cidr_len_ipv6 = 475,      /* cloak_cidr_len_ipv6  */
  YYSYMBOL_cloak_num_bits = 476,           /* cloak_num_bits  */
  YYSYMBOL_cloak_secret = 477,             /* cloak_secret  */
  YYSYMBOL_cloak_suffix = 478,             /* cloak_suffix  */
  YYSYMBOL_channel_entry = 479,            /* channel_entry  */
  YYSYMBOL_channel_items = 480,            /* channel_items  */
  YYSYMBOL_channel_item = 481,             /* channel_item  */
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
  YYSYMBOL_channel_max_topic_length = 495, /* channel_max_topic_length  */
  YYSYMBOL_channel_default_join_flood_count = 496, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 497, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 498,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 499,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 500,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 501, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 502, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 503, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 504, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 505,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 506, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 507,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 508         /* serverhide_hidden  */
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
#define YYNTOKENS  224
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  285
/* YYNRULES -- Number of rules.  */
#define YYNRULES  592
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1208

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
       0,   414,   414,   415,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     447,   456,   458,   458,   467,   474,   486,   487,   488,   489,
     490,   493,   502,   504,   504,   513,   520,   532,   533,   534,
     535,   536,   537,   538,   541,   556,   574,   589,   595,   597,
     602,   605,   610,   613,   622,   624,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   639,
     648,   657,   672,   687,   697,   711,   720,   743,   766,   775,
     785,   787,   787,   788,   789,   790,   791,   793,   802,   811,
     825,   824,   842,   842,   843,   843,   843,   845,   851,   862,
     861,   880,   880,   881,   881,   881,   881,   881,   883,   889,
     895,   901,   924,   925,   925,   927,   927,   928,   930,   940,
     940,   953,   954,   956,   956,   957,   957,   959,   967,   970,
     976,   975,   981,   985,   989,   993,   997,  1001,  1005,  1009,
    1020,  1019,  1081,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1094,  1100,  1106,  1112,  1118,
    1129,  1135,  1146,  1152,  1159,  1158,  1164,  1164,  1165,  1169,
    1173,  1177,  1181,  1185,  1189,  1193,  1197,  1201,  1205,  1209,
    1213,  1217,  1221,  1225,  1229,  1233,  1237,  1241,  1245,  1249,
    1253,  1257,  1261,  1265,  1269,  1273,  1277,  1281,  1292,  1291,
    1345,  1345,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,
    1354,  1355,  1356,  1357,  1358,  1359,  1360,  1362,  1368,  1374,
    1380,  1386,  1392,  1398,  1404,  1411,  1417,  1423,  1429,  1438,
    1448,  1447,  1453,  1453,  1454,  1458,  1469,  1468,  1475,  1474,
    1479,  1479,  1480,  1484,  1488,  1492,  1496,  1502,  1502,  1503,
    1503,  1503,  1503,  1503,  1505,  1505,  1507,  1507,  1509,  1522,
    1539,  1545,  1556,  1555,  1611,  1611,  1612,  1613,  1614,  1615,
    1616,  1617,  1618,  1620,  1626,  1632,  1638,  1650,  1649,  1655,
    1655,  1657,  1661,  1665,  1669,  1673,  1677,  1681,  1685,  1689,
    1695,  1711,  1710,  1725,  1725,  1726,  1726,  1726,  1726,  1728,
    1734,  1740,  1750,  1752,  1752,  1753,  1753,  1755,  1772,  1771,
    1794,  1794,  1795,  1795,  1795,  1795,  1797,  1803,  1823,  1822,
    1828,  1828,  1829,  1833,  1837,  1841,  1845,  1849,  1853,  1857,
    1861,  1865,  1869,  1880,  1879,  1898,  1898,  1899,  1899,  1899,
    1901,  1908,  1907,  1913,  1913,  1914,  1918,  1922,  1926,  1930,
    1934,  1938,  1942,  1946,  1950,  1961,  1960,  2016,  2016,  2017,
    2018,  2019,  2020,  2021,  2022,  2023,  2024,  2025,  2026,  2027,
    2028,  2029,  2030,  2031,  2032,  2034,  2040,  2046,  2052,  2058,
    2064,  2077,  2090,  2096,  2102,  2106,  2113,  2112,  2117,  2117,
    2118,  2122,  2128,  2139,  2145,  2151,  2162,  2161,  2186,  2186,
    2187,  2187,  2187,  2189,  2209,  2220,  2219,  2242,  2242,  2243,
    2243,  2243,  2245,  2251,  2261,  2263,  2263,  2264,  2264,  2266,
    2280,  2279,  2300,  2300,  2301,  2301,  2301,  2303,  2309,  2319,
    2321,  2321,  2322,  2323,  2324,  2325,  2326,  2327,  2328,  2329,
    2330,  2331,  2332,  2333,  2334,  2335,  2336,  2337,  2338,  2339,
    2340,  2341,  2342,  2343,  2344,  2345,  2346,  2347,  2348,  2349,
    2350,  2351,  2352,  2353,  2354,  2355,  2356,  2357,  2358,  2359,
    2360,  2361,  2364,  2369,  2374,  2379,  2384,  2389,  2394,  2399,
    2404,  2409,  2414,  2419,  2424,  2432,  2437,  2442,  2447,  2452,
    2457,  2462,  2467,  2472,  2477,  2482,  2487,  2492,  2497,  2502,
    2507,  2512,  2517,  2522,  2527,  2536,  2541,  2546,  2551,  2556,
    2564,  2573,  2575,  2575,  2576,  2577,  2578,  2579,  2580,  2581,
    2582,  2584,  2596,  2605,  2614,  2623,  2633,  2647,  2649,  2649,
    2650,  2651,  2652,  2653,  2654,  2655,  2656,  2657,  2658,  2659,
    2660,  2661,  2662,  2663,  2664,  2665,  2666,  2668,  2673,  2678,
    2683,  2688,  2693,  2698,  2703,  2708,  2713,  2718,  2723,  2728,
    2751,  2759,  2764,  2773,  2775,  2775,  2776,  2777,  2778,  2779,
    2780,  2781,  2782,  2783,  2784,  2786,  2792,  2803,  2812,  2818,
    2824,  2830,  2839
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
  "ADMIN", "AFTYPE", "ANTI_SPAM_EXIT_MESSAGE_TIME", "AUTOCONN",
  "AWAY_COUNT", "AWAY_TIME", "BYPASS", "BYTES", "KBYTES", "KIBYTES",
  "MBYTES", "MIBYTES", "GBYTES", "GIBYTES", "CALLER_ID_WAIT", "CAN_FLOOD",
  "CHANNEL", "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CIDR_LEN_IPV4",
  "CIDR_LEN_IPV6", "CLASS", "CLIENT", "CLOAK", "CLOSE", "CONNECT",
  "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME", "DEFAULT_JOIN_FLOOD_COUNT",
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
  "general_max_nick_time", "general_max_nick_changes",
  "general_max_accept", "general_max_away_length",
  "general_anti_spam_exit_message_time", "general_ts_warn_delta",
  "general_ts_max_delta", "general_invisible_on_connect",
  "general_warn_no_connect_block", "general_stats_e_disabled",
  "general_stats_u_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
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

#define YYPACT_NINF (-647)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-130)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -647,   656,  -647,   -98,  -218,  -210,  -647,  -205,  -647,  -647,
    -193,  -647,  -183,  -647,  -647,  -647,  -166,  -192,  -647,  -647,
    -647,  -172,  -167,  -647,  -159,  -647,  -154,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,    20,   719,  -143,   369,  -137,
    -125,    25,   -60,   347,   -16,   -10,    -5,  -647,  -121,  -166,
      37,    45,    53,   723,   426,    55,    84,    57,    35,    65,
     -50,   -42,    81,    86,    33,  -647,  -647,  -647,  -647,  -647,
      92,   104,   105,   107,   114,   115,   124,   129,   130,   131,
     132,   138,   141,   143,   144,   147,   126,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   497,  -647,   153,   154,   159,   160,
     161,   162,    36,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
     520,    19,  -647,   163,    21,  -647,  -647,    28,  -647,   164,
     175,   177,   178,   179,   181,   183,   185,   187,   188,   190,
     193,   196,   197,   198,   199,   200,   203,   210,   212,   213,
     214,   217,   220,   221,   222,   225,   230,   234,   237,   238,
     239,   241,   245,   247,   249,   251,   257,   258,    44,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,     7,
       9,   332,    49,   157,   171,    24,   322,   273,  -647,   260,
     261,   263,   265,   271,   272,   274,   275,    16,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   226,   277,   279,
     282,   285,   286,   290,   291,   292,   293,   294,   296,   169,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,    18,   299,   304,    11,  -647,  -647,  -647,    74,
     288,  -647,   306,    40,  -647,  -647,   101,  -647,    26,   127,
     278,   310,  -647,   313,   -55,   339,   319,   -55,   -55,   -55,
     321,   -55,   -55,   329,   330,   341,   343,   345,   348,   351,
    -647,   352,   346,   353,  -647,   354,   355,   356,   358,   359,
     360,   361,   363,   365,   366,   367,   207,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,   371,   372,   379,   373,   376,   380,   381,  -647,
     384,   377,   383,   385,   387,   388,   389,  -647,   392,   393,
     395,   396,   398,   402,   404,   409,   113,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   412,   415,    47,  -647,  -647,  -647,
     421,   423,  -647,  -647,   419,   422,    15,  -647,  -647,  -647,
     -55,   427,   -55,   -55,   428,   -55,   450,   454,   436,   438,
     -55,   465,   -55,   442,   444,   445,   447,   449,   451,   -55,
     452,   453,   457,   462,   474,   -55,   -55,   486,   -55,   487,
     469,   489,   494,   471,   -55,   -55,   -55,   496,   473,   475,
    -647,   476,   479,   480,  -647,   481,   491,   492,    54,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   493,   495,    43,
    -647,  -647,  -647,   477,   499,   501,  -647,   508,  -647,    32,
    -647,  -647,  -647,  -647,  -647,  -647,   482,  -647,  -647,  -647,
     478,   510,   511,    23,  -647,  -647,  -647,   488,   514,   515,
    -647,   516,   517,   518,   519,   521,   522,   525,   224,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
     528,   533,   534,   536,    14,  -647,  -647,  -647,  -647,   524,
     562,   -55,   542,   565,   544,   568,   569,   545,  -647,  -647,
     490,   551,   576,   555,   554,   561,   566,   570,   571,   577,
     578,   573,  -647,   579,   557,  -647,   122,  -647,  -647,  -647,
    -647,   587,   580,  -647,   572,   582,   574,   581,   585,   586,
      72,  -647,  -647,  -647,  -647,  -647,   592,   590,  -647,   591,
     595,  -647,   598,    60,  -647,  -647,  -647,  -647,   601,   602,
     603,  -647,   605,   146,   146,   607,    68,  -647,   608,   609,
     610,   611,   613,   614,   616,   617,   618,   620,   622,   623,
     624,   625,  -647,  -647,   627,   628,   626,   630,   -55,   631,
     -55,   634,   633,   635,   636,   -55,    83,    83,   637,  -647,
     638,   639,   640,   641,   642,   643,  -647,  -647,   647,   145,
     648,   658,   649,   650,   646,   652,   653,   654,   -55,   655,
     657,   -55,   659,   651,  -647,   660,   661,   662,  -647,   663,
    -647,   664,   667,   665,  -647,   666,   668,   669,   670,   671,
     672,   673,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   683,   684,   685,   686,   687,   688,   689,   690,   691,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,  -647,  -647,   709,   732,   706,   712,
     713,   714,   715,  -647,   716,   717,   718,  -647,  -647,   720,
     722,   710,   654,   721,  -647,    49,  -647,   725,   726,   724,
    -647,  -647,   728,   741,   727,   729,   730,   731,   733,   745,
     734,   735,   736,  -647,  -647,   737,   738,   740,   739,  -647,
     742,   743,   744,   746,   747,   748,   749,   750,  -647,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   761,
    -647,  -647,   765,   762,   763,  -647,   766,  -647,   155,  -647,
     768,   770,   771,   772,   773,  -647,   774,  -647,  -647,   775,
     769,   778,   776,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,   146,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,   777,   779,   -45,   780,   781,   782,   783,   784,
     785,   786,   787,   788,   539,   539,   789,   102,  -647,   790,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   791,   792,   793,
     794,   795,   796,   797,     2,   798,   799,  -647,   800,   801,
     802,   803,   804,   805,  -647,   806,   807,  -647,  -647,   808,
     809,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,   810,   811,   256,   812,   813,   814,  -647,   815,   816,
    -647,   817,   818,   302,   593,   632,  -647,  -647,  -647,   819,
     820,  -647,   821,   822,   458,   823,   824,   825,   826,   827,
     828,   829,  -647,   830,   831,   832,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,   833,   559,  -647,  -647,
     834,   835,   836,  -647,    88,  -647,  -647,  -647,  -647,   839,
     840,   841,   842,  -647,  -647,   843,   535,   844,  -647,  -647,
    -647,  -647,  -647,  -195,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   539,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -187,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -176,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -175,  -647,   654,   654,   845,
    -647,  -647,  -647,  -647,  -647,   767,  -647,   846,  -647,   847,
     848,  -647,   849,  -647,   850,   851,  -647,  -647,   852,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -126,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -123,  -647,  -647,   838,  -178,   854,   857,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   -33,  -647,  -647,
    -647,   -45,  -647,     2,  -647,   256,  -647,   302,  -647,  -647,
    -647,   885,   575,   853,   915,   866,   921,   926,   927,  -647,
     458,  -647,   559,   858,   859,   860,   484,  -647,  -647,   535,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,   861,  -647,  -647
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   208,     0,   365,   415,
       0,   430,     0,   272,   406,   246,     0,     0,   100,   150,
     301,     0,     0,   343,     0,   109,     0,   318,     3,     4,
       5,    14,     6,    26,    27,     7,     8,    11,    12,    13,
      16,    17,    18,    19,    20,    21,    22,    23,    25,    24,
      10,     9,    15,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    95,    94,   556,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   539,   555,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   540,   541,
     551,   552,   553,   554,     0,   530,     0,     0,     0,     0,
       0,     0,     0,   523,   524,   525,   526,   527,   528,   529,
       0,     0,   428,     0,     0,   426,   427,     0,   481,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   441,
     442,   443,   478,   447,   473,   474,   475,   476,   451,   444,
     445,   446,   460,   448,   449,   450,   452,   453,   477,   455,
     456,   462,   463,   457,   458,   454,   459,   470,   471,   472,
     468,   469,   461,   466,   467,   464,   465,   479,   480,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   575,   576,
     577,   578,   579,   580,   581,   583,   582,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,    77,    75,    67,    76,    69,    70,    71,    72,    73,
      74,    68,     0,     0,     0,     0,   124,   125,   126,     0,
       0,   316,     0,     0,   314,   315,     0,    96,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     538,     0,     0,     0,   240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   211,   212,   215,
     217,   218,   219,   220,   221,   222,   213,   214,   216,   223,
     224,   225,     0,     0,     0,     0,     0,     0,     0,   522,
       0,     0,     0,     0,     0,     0,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   378,   377,   379,   383,
     380,   381,   382,   421,     0,     0,     0,   418,   419,   420,
       0,     0,   425,   436,     0,     0,     0,   433,   434,   435,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     440,     0,     0,     0,   287,     0,     0,     0,     0,   275,
     276,   277,   278,   281,   279,   280,   412,     0,     0,     0,
     409,   410,   411,     0,     0,     0,   248,     0,   260,     0,
     258,   259,   261,   262,    63,    62,    59,    61,    56,    55,
       0,     0,     0,     0,   103,   104,   105,     0,     0,     0,
     174,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     154,   155,   156,   157,   160,   161,   162,   159,   158,   163,
       0,     0,     0,     0,     0,   304,   305,   306,   307,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   574,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,     0,     0,   351,     0,   346,   347,   348,
     127,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   112,   113,   115,   114,   116,     0,     0,   313,     0,
       0,   328,     0,     0,   321,   322,   323,   324,     0,     0,
       0,    90,     0,     0,    30,     0,    31,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   537,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   210,
       0,     0,     0,     0,     0,     0,   521,   384,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   367,     0,     0,     0,   417,     0,
     424,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   439,   282,     0,     0,     0,     0,
       0,     0,     0,   274,     0,     0,     0,   408,   263,     0,
       0,     0,     0,     0,   257,     0,   106,     0,     0,     0,
     102,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   152,   308,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,     0,     0,   573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,   349,     0,     0,     0,   345,     0,   122,     0,   117,
       0,     0,     0,     0,     0,   111,     0,   312,   325,     0,
       0,     0,     0,   320,    99,    98,    97,   571,    36,    37,
      38,    39,    40,    35,    34,   572,     0,    33,   557,   558,
     559,   560,   561,   562,   563,   564,   567,   568,   565,   566,
     569,   570,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,    42,    43,     0,
     209,   532,   533,   531,   534,   535,   536,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,   366,     0,     0,   416,   429,     0,
       0,   431,   495,   482,   483,   503,   517,   518,   511,   510,
     486,   487,   519,   498,   490,   488,   489,   493,   494,   484,
     492,   491,   508,   515,   516,   514,   504,   502,   505,   509,
     520,   506,   507,   500,   501,   512,   513,   497,   496,   499,
     485,     0,     0,     0,     0,     0,     0,   273,     0,     0,
     407,     0,     0,     0,   268,   264,   267,   247,    60,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,     0,     0,     0,   302,   588,   585,   586,
     587,   592,   591,   589,   590,    86,    83,    89,    82,    87,
      88,    81,    85,    84,    79,    80,     0,     0,   344,   128,
       0,     0,     0,   140,     0,   132,   133,   135,   134,     0,
       0,     0,     0,   110,   317,     0,     0,     0,   319,   235,
     236,   245,   244,     0,   243,   231,   239,   232,   238,   227,
     237,   230,   229,   228,    47,    48,    49,    50,    51,    52,
      53,    46,    45,   233,     0,    44,   234,   391,   394,   395,
     405,   402,   386,   403,   400,   401,     0,   399,   404,   385,
     393,   388,   390,   389,   387,   392,   422,   423,   437,   438,
     285,   286,   295,   291,   292,   294,   299,   296,   297,   298,
     293,     0,   290,   284,   300,   283,   414,   413,   271,   270,
     255,   256,   253,   254,   252,     0,   251,     0,     0,     0,
     107,   108,   172,   169,   194,     0,   205,   181,   190,     0,
     179,   184,     0,   199,     0,   193,   197,   203,   183,   186,
     195,   196,   200,   191,   198,   187,   204,   189,   185,   188,
       0,   177,   165,   167,   173,   170,   171,   166,   168,   311,
     309,   310,   350,   355,   361,   364,   357,   363,   358,   362,
     360,   356,   359,     0,   354,   136,     0,     0,     0,     0,
     131,   119,   118,   120,   121,   326,   332,   338,   339,   342,
     334,   341,   335,   340,   337,   333,   336,     0,   331,   327,
     241,     0,   397,     0,   288,     0,   249,     0,   269,   266,
     265,     0,     0,     0,     0,     0,     0,     0,     0,   175,
       0,   352,     0,     0,     0,     0,     0,   130,   329,     0,
     242,   398,   289,   250,   207,   180,   202,   178,   206,   201,
     192,   182,   176,   353,   137,   139,   138,   148,   147,   143,
     145,   149,   146,   142,   144,     0,   330,   141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -647,  -647,  -647,  -305,  -647,   281,   280,  -627,  -647,    41,
      51,  -646,  -647,  -647,   889,  -647,  -647,   357,  -647,  -647,
     837,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   875,  -647,  -647,  -647,  -647,  -647,
    -647,   470,  -647,  -647,  -647,  -647,  -647,   513,  -647,  -647,
    -647,  -647,  -647,  -647,   855,  -647,  -647,  -647,  -647,   106,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   583,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,   -89,  -647,  -647,  -647,   764,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,   -67,  -647,  -647,  -647,  -647,  -647,   -72,  -647,
     615,  -647,  -647,  -647,    22,  -647,  -647,  -647,  -647,  -647,
     629,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   -69,  -647,
    -647,  -647,  -647,   564,  -647,  -647,  -647,  -647,  -647,   856,
    -647,  -647,  -647,  -647,   506,  -647,  -647,  -647,  -647,  -647,
     -87,  -647,  -647,  -647,   537,  -647,  -647,  -647,  -647,   -77,
    -647,  -647,  -647,   862,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   -57,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,   644,  -647,  -647,  -647,  -647,
    -647,   707,  -647,  -647,  -647,  -647,   953,  -647,  -647,  -647,
    -647,   708,  -647,  -647,  -647,  -647,   910,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   967,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   995,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,   863,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    28,   595,   596,   597,   804,   836,   837,   838,
    1012,   924,    29,    30,    68,   233,   486,   487,    31,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,    32,    84,    85,    86,    87,    88,    33,    70,
     493,   494,   495,   496,    34,    77,   570,   571,   572,   573,
     574,   575,    35,   285,   286,   287,   288,   289,   974,   975,
     976,   977,   978,  1128,  1205,    36,    71,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   734,
    1100,  1101,    37,    57,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     616,   993,   994,    38,    66,   478,   721,  1065,  1066,   479,
     480,   481,  1069,   925,   926,   482,   483,    39,    64,   458,
     459,   460,   461,   462,   463,   464,   708,  1051,  1052,   465,
      40,    72,   524,   525,   526,   527,   528,    41,   293,   294,
     295,    42,    79,   583,   584,   585,   586,   587,   790,  1147,
    1148,    43,    75,   556,   557,   558,   559,   773,  1123,  1124,
      44,    59,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   644,  1026,  1027,   389,   390,
     391,   392,    45,    65,   469,   470,   471,   472,    46,    60,
     396,   397,   398,   399,    47,   144,   145,   146,    48,    62,
     406,   407,   408,   409,    49,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    50,   132,   133,   134,
     135,   136,   137,   138,   139,    51,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,    52,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     839,   858,   600,   601,   602,    55,   604,   605,   451,  1024,
     466,  1174,   283,    56,   991,   520,   403,   238,    58,   553,
     393,    80,   142,  1150,   490,   490,   142,  1151,    69,   403,
      61,  1152,   452,   473,    80,  1153,   291,   125,   834,   835,
      63,   291,  1154,  1156,   466,   148,  1155,  1157,   393,    67,
     149,    73,   150,   151,   453,   451,    74,    81,   239,   126,
     127,   579,   152,   521,    76,    82,   240,   241,   242,    78,
      81,   243,   244,   565,   153,   154,   245,   246,    82,   452,
     124,   454,   128,   155,   156,   283,   140,   157,   158,   970,
     992,   394,  1169,   143,   474,  1171,  1170,   143,   141,  1172,
     232,   453,   579,   522,   475,   665,   476,   667,   668,   159,
     670,   160,   491,   491,   360,   675,   361,   677,   362,   394,
      53,    54,   161,   553,   684,   162,   163,    89,   454,   404,
     690,   691,   554,   693,    83,   164,   165,   455,   363,   699,
     700,   701,   404,   166,   167,   467,   168,    83,   169,   292,
     523,   405,   170,   171,   292,   395,   970,   129,    90,    91,
     364,   593,   594,   147,   405,   456,   477,    92,   297,   172,
     257,   173,   174,   175,   580,   365,   176,   366,   298,   467,
    -129,   177,   130,   395,   455,  1178,   566,   367,  1025,  1179,
     484,   485,   492,   492,    93,    94,    95,    96,   131,   368,
     178,   179,   971,   258,   180,   181,   259,   229,   321,    97,
      98,    99,   456,   230,   457,   580,   468,   284,   231,   100,
     101,   102,   555,   103,   104,   497,   752,   369,   322,   323,
     562,   105,   260,   748,   663,   537,   554,   567,   182,   183,
     401,   588,   729,   564,   261,   184,   185,   370,   568,   498,
     468,   723,   301,  -129,   186,   358,   187,   569,   371,   577,
     235,   457,   716,   449,   581,   372,   657,   582,   236,   971,
     262,   499,   972,   712,   520,  1042,   237,   373,   282,   792,
     290,   324,   263,   264,   593,   806,   265,   266,   296,   565,
     284,   784,   973,   798,   799,   800,   801,   802,   500,   834,
     835,   299,   325,   326,  1043,   581,   300,  1129,   582,   374,
     327,   375,   303,   826,   328,   828,   848,   849,   834,  1014,
     833,   329,   521,   497,   304,   305,   555,   306,  1060,   330,
     331,   332,   653,   473,   307,   308,  1044,  1061,   501,   972,
     333,   774,   589,   859,   309,   319,   862,   498,   148,   310,
     311,   312,   313,   149,   502,   150,   151,  1062,   314,   973,
     334,   315,   522,   316,   317,   152,   267,   318,   268,   499,
     125,  1045,  1046,   352,   353,   488,  1047,   153,   154,   354,
     355,   356,   357,   400,   410,   335,   155,   156,   551,   489,
     157,   158,   126,   127,   474,   411,   500,   412,   413,   414,
    1048,   415,   566,   416,   475,   417,   476,   418,   419,   523,
     420,   503,   159,   421,   160,   128,   422,   423,   424,   425,
     426,  1158,   504,   427,   505,   161,   628,   257,   162,   163,
     428,   506,   429,   430,   431,   507,   501,   432,   164,   165,
     433,   434,   435,   742,   539,   436,   166,   167,  1049,   168,
     437,   169,   502,   567,   438,   170,   171,   439,   440,   441,
     258,   442,  1074,   259,   568,   443,   477,   444,  1075,   445,
    1050,   446,   172,   569,   173,   174,   175,   447,   448,   176,
     529,   530,  1063,   531,   177,   532,  1076,  1077,  1064,   260,
     129,   533,   534,   590,   535,   536,  1078,   540,   321,   541,
    1175,   261,   542,   178,   179,   543,   544,   180,   181,   503,
     545,   546,   547,   548,   549,   130,   550,   560,   322,   323,
     504,   360,   505,   361,   561,   362,   576,   262,   591,   506,
     592,   131,   598,   507,  1079,  1080,   599,  1081,   603,   263,
     264,   182,   183,   265,   266,   363,   606,   607,   184,   185,
    1004,  1005,  1006,  1007,  1008,  1009,  1010,   186,   608,   187,
     609,  1197,   610,  1198,  1082,   611,   614,   364,  1083,   612,
     613,   324,   632,   615,   617,   618,   619,  1084,   620,   621,
     622,   623,   365,   624,   366,   625,   626,   627,   630,   631,
     633,   634,   325,   326,   367,   635,  1085,   638,  1086,   636,
     327,  1087,   637,   639,   328,   640,   368,   641,   642,   643,
    1199,   329,   645,   646,  1136,   647,   648,  1088,   649,   330,
     331,   332,   650,   267,   651,   268,  1089,  1200,  1090,   652,
     333,  1091,   655,  1092,   369,   656,   659,  1093,  1113,   661,
    1094,   660,   662,   671,   666,   669,  1095,   672,  1096,  1097,
     334,  1201,  1202,   673,   370,   674,     2,     3,   676,   678,
       4,   679,   680,  1098,   681,   371,   682,   689,   683,   685,
     686,  1099,   372,  1137,   687,   335,     5,   688,  1138,   692,
     694,     6,   696,     7,   373,     8,   695,   697,   698,   702,
     703,  1203,     9,   704,   705,   718,   726,  1204,  1139,   706,
     707,   709,  1114,  1140,   725,    10,   731,   759,  1141,    11,
      12,   710,   711,   714,  1185,   715,   374,   750,   375,   719,
      89,   720,  1115,  1142,   238,  1143,  1144,  1116,   722,    13,
     727,   728,  1117,    14,   732,   733,   735,   736,   737,   738,
    1145,   739,   740,    15,    16,   741,   744,  1118,  1146,  1119,
    1120,    90,    91,   745,   746,   751,   747,   753,   754,   755,
      92,   756,   757,   758,  1121,   239,   760,    17,    18,   761,
     762,   763,  1122,   240,   241,   242,   764,   772,   243,   244,
     776,   765,    19,   245,   246,   766,   767,    93,    94,    95,
      96,   770,   768,   769,   780,   778,  1067,   771,   777,    20,
     779,   781,    97,    98,    99,   782,   783,   786,   787,   788,
      21,    22,   100,   101,   102,   789,   103,   104,   791,   794,
     795,   796,    23,   797,   105,   805,   808,   809,   810,   811,
      24,   812,   813,    25,   814,   815,   816,    26,   817,    27,
     818,   819,   820,   821,   822,   823,   824,   825,   827,   829,
     830,   851,   831,   832,  1068,   840,   841,   842,   843,   844,
     845,   846,   847,   850,   852,   853,   854,   855,   856,   864,
     860,   857,   861,   803,   863,   865,   866,   807,  1015,   869,
     867,   868,   870,   871,   872,  1011,   873,   874,   875,   876,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
     887,   888,   889,   890,   891,   892,   893,   894,   895,   896,
     897,   898,   899,   900,   901,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   911,   912,   913,   914,   915,   916,
     923,   918,   919,   917,   933,   921,   920,   922,   939,   927,
     929,   930,   931,   932,   935,   936,   937,   934,   938,   940,
     941,  1184,   943,   944,   942,   945,  1188,   946,   234,   302,
     947,   948,   949,   730,   950,   951,   952,   953,   954,   955,
     956,   957,   958,   959,   960,   961,   962,   963,   964,   965,
     966,   968,   967,   979,   969,   980,   981,   982,  1161,   986,
     985,   983,   984,   987,   988,   989,  1186,   990,   995,   996,
     997,   998,   999,  1000,  1001,  1002,  1003,  1013,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1028,  1029,  1030,  1031,
    1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,
    1053,  1054,  1055,  1056,  1057,  1058,  1059,  1070,  1071,  1072,
    1073,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1125,  1173,  1187,  1126,  1127,  1131,  1132,  1133,
    1134,  1135,  1149,  1160,  1189,  1190,  1191,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1176,  1177,  1194,  1195,  1196,  1207,
    1130,  1192,   928,   785,  1180,  1183,  1182,   713,   749,   793,
    1159,   743,  1206,   775,   724,  1193,  1181,   402,   450,   359,
     629,   320,     0,   658,     0,     0,   552,     0,     0,     0,
     538,     0,     0,   717,   664,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     563,     0,     0,     0,     0,     0,     0,     0,     0,   578,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   654
};

static const yytype_int16 yycheck[] =
{
     627,   647,   307,   308,   309,   223,   311,   312,     1,     7,
       1,   189,     1,   223,    59,     1,     1,     1,   223,     1,
       1,     1,     1,   218,     1,     1,     1,   222,   220,     1,
     223,   218,    25,     1,     1,   222,     1,     1,   216,   217,
     223,     1,   218,   218,     1,     1,   222,   222,     1,   215,
       6,   223,     8,     9,    47,     1,   223,    37,    42,    23,
      24,     1,    18,    49,   223,    45,    50,    51,    52,   223,
      37,    55,    56,     1,    30,    31,    60,    61,    45,    25,
     223,    74,    46,    39,    40,     1,   223,    43,    44,     1,
     135,    72,   218,    72,    62,   218,   222,    72,   223,   222,
     221,    47,     1,    89,    72,   410,    74,   412,   413,    65,
     415,    67,    89,    89,     1,   420,     3,   422,     5,    72,
     218,   219,    78,     1,   429,    81,    82,     1,    74,   114,
     435,   436,   114,   438,   114,    91,    92,   130,    25,   444,
     445,   446,   114,    99,   100,   136,   102,   114,   104,   114,
     136,   136,   108,   109,   114,   136,     1,   121,    32,    33,
      47,   216,   217,   223,   136,   158,   134,    41,   218,   125,
       1,   127,   128,   129,   114,    62,   132,    64,   220,   136,
     169,   137,   146,   136,   130,   218,   114,    74,   186,   222,
     141,   142,   169,   169,    68,    69,    70,    71,   162,    86,
     156,   157,   114,    34,   160,   161,    37,   223,     1,    83,
      84,    85,   158,   223,   207,   114,   207,   206,   223,    93,
      94,    95,   204,    97,    98,     1,   531,   114,    21,    22,
     219,   105,    63,   219,   219,   219,   114,   165,   194,   195,
     219,   215,   219,   169,    75,   201,   202,   134,   176,    25,
     207,   219,   219,   169,   210,   219,   212,   185,   145,   219,
     223,   207,   219,   219,   204,   152,   219,   207,   223,   114,
     101,    47,   184,   219,     1,    19,   223,   164,   223,   219,
     223,    74,   113,   114,   216,   217,   117,   118,   223,     1,
     206,   219,   204,   147,   148,   149,   150,   151,    74,   216,
     217,   220,    95,    96,    48,   204,   220,   219,   207,   196,
     103,   198,   220,   618,   107,   620,   171,   172,   216,   217,
     625,   114,    49,     1,   220,   220,   204,   220,    26,   122,
     123,   124,   219,     1,   220,   220,    80,    35,   114,   184,
     133,   219,   215,   648,   220,   219,   651,    25,     1,   220,
     220,   220,   220,     6,   130,     8,     9,    55,   220,   204,
     153,   220,    89,   220,   220,    18,   197,   220,   199,    47,
       1,   115,   116,   220,   220,   218,   120,    30,    31,   220,
     220,   220,   220,   220,   220,   178,    39,    40,   219,   218,
      43,    44,    23,    24,    62,   220,    74,   220,   220,   220,
     144,   220,   114,   220,    72,   220,    74,   220,   220,   136,
     220,   187,    65,   220,    67,    46,   220,   220,   220,   220,
     220,  1067,   198,   220,   200,    78,   219,     1,    81,    82,
     220,   207,   220,   220,   220,   211,   114,   220,    91,    92,
     220,   220,   220,   219,   218,   220,    99,   100,   192,   102,
     220,   104,   130,   165,   220,   108,   109,   220,   220,   220,
      34,   220,     4,    37,   176,   220,   134,   220,    10,   220,
     214,   220,   125,   185,   127,   128,   129,   220,   220,   132,
     220,   220,   180,   220,   137,   220,    28,    29,   186,    63,
     121,   220,   220,   215,   220,   220,    38,   220,     1,   220,
    1127,    75,   220,   156,   157,   220,   220,   160,   161,   187,
     220,   220,   220,   220,   220,   146,   220,   218,    21,    22,
     198,     1,   200,     3,   220,     5,   220,   101,   218,   207,
     217,   162,   193,   211,    76,    77,   217,    79,   217,   113,
     114,   194,   195,   117,   118,    25,   217,   217,   201,   202,
      11,    12,    13,    14,    15,    16,    17,   210,   217,   212,
     217,    77,   217,    79,   106,   217,   220,    47,   110,   218,
     218,    74,   193,   220,   220,   220,   220,   119,   220,   220,
     220,   220,    62,   220,    64,   220,   220,   220,   217,   217,
     217,   215,    95,    96,    74,   215,   138,   220,   140,   218,
     103,   143,   218,   220,   107,   220,    86,   220,   220,   220,
     126,   114,   220,   220,    79,   220,   220,   159,   220,   122,
     123,   124,   220,   197,   220,   199,   168,   143,   170,   220,
     133,   173,   220,   175,   114,   220,   215,   179,    79,   220,
     182,   218,   220,   193,   217,   217,   188,   193,   190,   191,
     153,   167,   168,   217,   134,   217,     0,     1,   193,   217,
       4,   217,   217,   205,   217,   145,   217,   193,   217,   217,
     217,   213,   152,   138,   217,   178,    20,   215,   143,   193,
     193,    25,   193,    27,   164,    29,   217,   193,   217,   193,
     217,   207,    36,   218,   218,   218,   218,   213,   163,   220,
     220,   220,   143,   168,   222,    49,   218,   217,   173,    53,
      54,   220,   220,   220,   139,   220,   196,   193,   198,   220,
       1,   220,   163,   188,     1,   190,   191,   168,   220,    73,
     220,   220,   173,    77,   220,   220,   220,   220,   220,   220,
     205,   220,   220,    87,    88,   220,   218,   188,   213,   190,
     191,    32,    33,   220,   220,   193,   220,   215,   193,   215,
      41,   193,   193,   218,   205,    42,   215,   111,   112,   193,
     215,   217,   213,    50,    51,    52,   215,   220,    55,    56,
     193,   215,   126,    60,    61,   215,   215,    68,    69,    70,
      71,   218,   215,   215,   220,   223,   203,   218,   218,   143,
     218,   220,    83,    84,    85,   220,   220,   215,   218,   218,
     154,   155,    93,    94,    95,   220,    97,    98,   220,   218,
     218,   218,   166,   218,   105,   218,   218,   218,   218,   218,
     174,   218,   218,   177,   218,   218,   218,   181,   218,   183,
     218,   218,   218,   218,   217,   217,   220,   217,   217,   215,
     217,   193,   217,   217,   222,   218,   218,   218,   218,   218,
     218,   218,   215,   215,   215,   215,   220,   215,   215,   218,
     215,   217,   215,   593,   215,   215,   215,   596,   837,   215,
     218,   218,   215,   218,   218,   834,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   215,   193,   220,   215,   215,   215,
     220,   215,   215,   218,   193,   215,   218,   215,   193,   218,
     215,   215,   218,   215,   215,   215,   215,   220,   215,   215,
     215,    66,   215,   215,   218,   215,    90,   218,    69,    84,
     218,   218,   218,   493,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     215,   218,   220,   215,   218,   215,   215,   215,   221,   220,
     215,   218,   218,   215,   218,   218,   143,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   215,   139,   220,   220,   218,   218,   218,
     218,   218,   218,   218,   143,   139,   139,   221,   221,   221,
     221,   221,   221,   221,   220,   218,   218,   218,   218,   218,
     974,  1170,   725,   570,  1151,  1157,  1155,   458,   524,   583,
    1068,   508,  1179,   556,   479,  1172,  1153,   144,   188,   132,
     336,   106,    -1,   396,    -1,    -1,   269,    -1,    -1,    -1,
     247,    -1,    -1,   469,   406,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   293,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   376
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   225,     0,     1,     4,    20,    25,    27,    29,    36,
      49,    53,    54,    73,    77,    87,    88,   111,   112,   126,
     143,   154,   155,   166,   174,   177,   181,   183,   226,   236,
     237,   242,   256,   262,   268,   276,   289,   306,   327,   341,
     354,   361,   365,   375,   384,   406,   412,   418,   422,   428,
     470,   479,   498,   218,   219,   223,   223,   307,   223,   385,
     413,   223,   423,   223,   342,   407,   328,   215,   238,   220,
     263,   290,   355,   223,   223,   376,   223,   269,   223,   366,
       1,    37,    45,   114,   257,   258,   259,   260,   261,     1,
      32,    33,    41,    68,    69,    70,    71,    83,    84,    85,
      93,    94,    95,    97,    98,   105,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   223,     1,    23,    24,    46,   121,
     146,   162,   471,   472,   473,   474,   475,   476,   477,   478,
     223,   223,     1,    72,   419,   420,   421,   223,     1,     6,
       8,     9,    18,    30,    31,    39,    40,    43,    44,    65,
      67,    78,    81,    82,    91,    92,    99,   100,   102,   104,
     108,   109,   125,   127,   128,   129,   132,   137,   156,   157,
     160,   161,   194,   195,   201,   202,   210,   212,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   223,
     223,   223,   221,   239,   238,   223,   223,   223,     1,    42,
      50,    51,    52,    55,    56,    60,    61,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,     1,    34,    37,
      63,    75,   101,   113,   114,   117,   118,   197,   199,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   223,     1,   206,   277,   278,   279,   280,   281,
     223,     1,   114,   362,   363,   364,   223,   218,   220,   220,
     220,   219,   258,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   219,
     481,     1,    21,    22,    74,    95,    96,   103,   107,   114,
     122,   123,   124,   133,   153,   178,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   220,   220,   220,   220,   220,   220,   219,   472,
       1,     3,     5,    25,    47,    62,    64,    74,    86,   114,
     134,   145,   152,   164,   196,   198,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   402,
     403,   404,   405,     1,    72,   136,   414,   415,   416,   417,
     220,   219,   420,     1,   114,   136,   424,   425,   426,   427,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   219,
     430,     1,    25,    47,    74,   130,   158,   207,   343,   344,
     345,   346,   347,   348,   349,   353,     1,   136,   207,   408,
     409,   410,   411,     1,    62,    72,    74,   134,   329,   333,
     334,   335,   339,   340,   141,   142,   240,   241,   218,   218,
       1,    89,   169,   264,   265,   266,   267,     1,    25,    47,
      74,   114,   130,   187,   198,   200,   207,   211,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
       1,    49,    89,   136,   356,   357,   358,   359,   360,   220,
     220,   220,   220,   220,   220,   220,   220,   219,   500,   218,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   219,   244,     1,   114,   204,   377,   378,   379,   380,
     218,   220,   219,   278,   169,     1,   114,   165,   176,   185,
     270,   271,   272,   273,   274,   275,   220,   219,   363,     1,
     114,   204,   207,   367,   368,   369,   370,   371,   215,   215,
     215,   218,   217,   216,   217,   227,   228,   229,   193,   217,
     227,   227,   227,   217,   227,   227,   217,   217,   217,   217,
     217,   217,   218,   218,   220,   220,   324,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   219,   309,
     217,   217,   193,   217,   215,   215,   218,   218,   220,   220,
     220,   220,   220,   220,   399,   220,   220,   220,   220,   220,
     220,   220,   220,   219,   387,   220,   220,   219,   415,   215,
     218,   220,   220,   219,   425,   227,   217,   227,   227,   217,
     227,   193,   193,   217,   217,   227,   193,   227,   217,   217,
     217,   217,   217,   217,   227,   217,   217,   217,   215,   193,
     227,   227,   193,   227,   193,   217,   193,   193,   217,   227,
     227,   227,   193,   217,   218,   218,   220,   220,   350,   220,
     220,   220,   219,   344,   220,   220,   219,   409,   218,   220,
     220,   330,   220,   219,   334,   222,   218,   220,   220,   219,
     265,   218,   220,   220,   303,   220,   220,   220,   220,   220,
     220,   220,   219,   292,   218,   220,   220,   220,   219,   357,
     193,   193,   227,   215,   193,   215,   193,   193,   218,   217,
     215,   193,   215,   217,   215,   215,   215,   215,   215,   215,
     218,   218,   220,   381,   219,   378,   193,   218,   223,   218,
     220,   220,   220,   220,   219,   271,   215,   218,   218,   220,
     372,   220,   219,   368,   218,   218,   218,   218,   147,   148,
     149,   150,   151,   230,   230,   218,   217,   229,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   217,   217,   220,   217,   227,   217,   227,   215,
     217,   217,   217,   227,   216,   217,   231,   232,   233,   231,
     218,   218,   218,   218,   218,   218,   218,   215,   171,   172,
     215,   193,   215,   215,   220,   215,   215,   217,   235,   227,
     215,   215,   227,   215,   218,   215,   215,   218,   218,   215,
     215,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   215,   193,   220,   215,   215,   215,   218,   215,   215,
     218,   215,   215,   220,   235,   337,   338,   218,   241,   215,
     215,   218,   215,   193,   220,   215,   215,   215,   215,   193,
     215,   215,   218,   215,   215,   215,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   215,   220,   218,   218,
       1,   114,   184,   204,   282,   283,   284,   285,   286,   215,
     215,   215,   215,   218,   218,   215,   220,   215,   218,   218,
     218,    59,   135,   325,   326,   218,   218,   218,   218,   218,
     218,   218,   218,   218,    11,    12,    13,    14,    15,    16,
      17,   234,   234,   218,   217,   233,   218,   218,   218,   218,
     218,   218,   218,   218,     7,   186,   400,   401,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,    19,    48,    80,   115,   116,   120,   144,   192,
     214,   351,   352,   218,   218,   218,   218,   218,   218,   218,
      26,    35,    55,   180,   186,   331,   332,   203,   222,   336,
     218,   218,   218,   218,     4,    10,    28,    29,    38,    76,
      77,    79,   106,   110,   119,   138,   140,   143,   159,   168,
     170,   173,   175,   179,   182,   188,   190,   191,   205,   213,
     304,   305,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,    79,   143,   163,   168,   173,   188,   190,
     191,   205,   213,   382,   383,   218,   220,   220,   287,   219,
     283,   218,   218,   218,   218,   218,    79,   138,   143,   163,
     168,   173,   188,   190,   191,   205,   213,   373,   374,   218,
     218,   222,   218,   222,   218,   222,   218,   222,   235,   338,
     218,   221,   221,   221,   221,   221,   221,   221,   221,   218,
     222,   218,   222,   215,   189,   231,   220,   218,   218,   222,
     326,   401,   352,   332,    66,   139,   143,   139,    90,   143,
     139,   139,   305,   383,   218,   218,   218,    77,    79,   126,
     143,   167,   168,   207,   213,   288,   374,   218
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   224,   225,   225,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     227,   227,   228,   228,   229,   229,   230,   230,   230,   230,
     230,   231,   231,   232,   232,   233,   233,   234,   234,   234,
     234,   234,   234,   234,   235,   236,   237,   238,   239,   239,
     240,   240,   241,   241,   242,   243,   243,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   257,   258,   258,   258,   258,   259,   260,   261,
     263,   262,   264,   264,   265,   265,   265,   266,   267,   269,
     268,   270,   270,   271,   271,   271,   271,   271,   272,   273,
     274,   275,   276,   277,   277,   278,   278,   278,   279,   281,
     280,   282,   282,   283,   283,   283,   283,   284,   285,   285,
     287,   286,   288,   288,   288,   288,   288,   288,   288,   288,
     290,   289,   291,   291,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   303,   302,   304,   304,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   307,   306,
     308,   308,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     324,   323,   325,   325,   326,   326,   328,   327,   330,   329,
     331,   331,   332,   332,   332,   332,   332,   333,   333,   334,
     334,   334,   334,   334,   336,   335,   337,   337,   338,   338,
     339,   340,   342,   341,   343,   343,   344,   344,   344,   344,
     344,   344,   344,   345,   346,   347,   348,   350,   349,   351,
     351,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     353,   355,   354,   356,   356,   357,   357,   357,   357,   358,
     359,   360,   361,   362,   362,   363,   363,   364,   366,   365,
     367,   367,   368,   368,   368,   368,   369,   370,   372,   371,
     373,   373,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   376,   375,   377,   377,   378,   378,   378,
     379,   381,   380,   382,   382,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   385,   384,   386,   386,   387,
     387,   387,   387,   387,   387,   387,   387,   387,   387,   387,
     387,   387,   387,   387,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   397,   399,   398,   400,   400,
     401,   401,   402,   403,   404,   405,   407,   406,   408,   408,
     409,   409,   409,   410,   411,   413,   412,   414,   414,   415,
     415,   415,   416,   417,   418,   419,   419,   420,   420,   421,
     423,   422,   424,   424,   425,   425,   425,   426,   427,   428,
     429,   429,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   471,   472,   472,   472,   472,   472,   472,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   480,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   499,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   501,   502,   503,   504,   505,
     506,   507,   508
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
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     5,     2,     1,
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
    case YYSYMBOL_DECIMAL: /* DECIMAL  */
#line 411 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3222 "conf_parser.c"
        break;

    case YYSYMBOL_module_string: /* module_string  */
#line 411 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3228 "conf_parser.c"
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
#line 448 "conf_parser.y"
{
  if ((yyvsp[0].number) != 0)
  {
    yyerror("Nonzero durations require a unit");
    YYERROR;
  }

  (yyval.number) = 0;
}
#line 3509 "conf_parser.c"
    break;

  case 33: /* time_components: time_components time_component  */
#line 459 "conf_parser.y"
{
  if (!_conf_parser_quantity_add((yyvsp[-1].number), (yyvsp[0].number), 1U, &(yyval.number)))
  {
    yyerror("Duration out of range");
    YYERROR;
  }
}
#line 3521 "conf_parser.c"
    break;

  case 34: /* time_component: NUMBER time_unit  */
#line 468 "conf_parser.y"
{
  if (!_conf_parser_quantity_add(0, (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Duration out of range");
    YYERROR;
  }
}
#line 3533 "conf_parser.c"
    break;

  case 35: /* time_component: DECIMAL time_unit  */
#line 475 "conf_parser.y"
{
  const enum conf_quantity_status status = _conf_parser_quantity_from_decimal((yyvsp[-1].string), (yyvsp[0].number), &(yyval.number));
  io_free((yyvsp[-1].string));

  if (status != CONF_QUANTITY_OK)
  {
    yyerror(status == CONF_QUANTITY_INEXACT ? "Duration component must resolve to whole seconds" : "Duration out of range");
    YYERROR;
  }
}
#line 3548 "conf_parser.c"
    break;

  case 36: /* time_unit: SECONDS  */
#line 486 "conf_parser.y"
                   { (yyval.number) = 1U; }
#line 3554 "conf_parser.c"
    break;

  case 37: /* time_unit: MINUTES  */
#line 487 "conf_parser.y"
                   { (yyval.number) = 60U; }
#line 3560 "conf_parser.c"
    break;

  case 38: /* time_unit: HOURS  */
#line 488 "conf_parser.y"
                   { (yyval.number) = 60U * 60U; }
#line 3566 "conf_parser.c"
    break;

  case 39: /* time_unit: DAYS  */
#line 489 "conf_parser.y"
                   { (yyval.number) = 60U * 60U * 24U; }
#line 3572 "conf_parser.c"
    break;

  case 40: /* time_unit: WEEKS  */
#line 490 "conf_parser.y"
                   { (yyval.number) = 60U * 60U * 24U * 7U; }
#line 3578 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER  */
#line 494 "conf_parser.y"
{
  if ((yyvsp[0].number) != 0)
  {
    yyerror("Nonzero sizes require a unit");
    YYERROR;
  }

  (yyval.number) = 0;
}
#line 3592 "conf_parser.c"
    break;

  case 44: /* size_components: size_components size_component  */
#line 505 "conf_parser.y"
{
  if (!_conf_parser_quantity_add((yyvsp[-1].number), (yyvsp[0].number), 1U, &(yyval.number)))
  {
    yyerror("Size out of range");
    YYERROR;
  }
}
#line 3604 "conf_parser.c"
    break;

  case 45: /* size_component: NUMBER size_unit  */
#line 514 "conf_parser.y"
{
  if (!_conf_parser_quantity_add(0, (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Size out of range");
    YYERROR;
  }
}
#line 3616 "conf_parser.c"
    break;

  case 46: /* size_component: DECIMAL size_unit  */
#line 521 "conf_parser.y"
{
  const enum conf_quantity_status status = _conf_parser_quantity_from_decimal((yyvsp[-1].string), (yyvsp[0].number), &(yyval.number));
  io_free((yyvsp[-1].string));

  if (status != CONF_QUANTITY_OK)
  {
    yyerror(status == CONF_QUANTITY_INEXACT ? "Size component must resolve to whole bytes" : "Size out of range");
    YYERROR;
  }
}
#line 3631 "conf_parser.c"
    break;

  case 47: /* size_unit: BYTES  */
#line 532 "conf_parser.y"
                   { (yyval.number) = 1U; }
#line 3637 "conf_parser.c"
    break;

  case 48: /* size_unit: KBYTES  */
#line 533 "conf_parser.y"
                   { (yyval.number) = 1000U; }
#line 3643 "conf_parser.c"
    break;

  case 49: /* size_unit: KIBYTES  */
#line 534 "conf_parser.y"
                   { (yyval.number) = 1024U; }
#line 3649 "conf_parser.c"
    break;

  case 50: /* size_unit: MBYTES  */
#line 535 "conf_parser.y"
                   { (yyval.number) = 1000U * 1000U; }
#line 3655 "conf_parser.c"
    break;

  case 51: /* size_unit: MIBYTES  */
#line 536 "conf_parser.y"
                   { (yyval.number) = 1024U * 1024U; }
#line 3661 "conf_parser.c"
    break;

  case 52: /* size_unit: GBYTES  */
#line 537 "conf_parser.y"
                   { (yyval.number) = 1000U * 1000U * 1000U; }
#line 3667 "conf_parser.c"
    break;

  case 53: /* size_unit: GIBYTES  */
#line 538 "conf_parser.y"
                   { (yyval.number) = 1024U * 1024U * 1024U; }
#line 3673 "conf_parser.c"
    break;

  case 54: /* port_number: NUMBER  */
#line 542 "conf_parser.y"
{
  if ((yyvsp[0].number) > UINT16_MAX)
  {
    yyerror("Port out of range");
    YYERROR;
  }

  (yyval.number) = (yyvsp[0].number);
}
#line 3687 "conf_parser.c"
    break;

  case 55: /* module_base_path_entry: MODULE_BASE_PATH '=' module_string ';'  */
#line 557 "conf_parser.y"
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
#line 3704 "conf_parser.c"
    break;

  case 56: /* loadmodule_entry: LOADMODULE module_string module_attributes ';'  */
#line 575 "conf_parser.y"
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
#line 3721 "conf_parser.c"
    break;

  case 57: /* module_string: QSTRING  */
#line 590 "conf_parser.y"
{
  (yyval.string) = io_strdup((yyvsp[0].string));
}
#line 3729 "conf_parser.c"
    break;

  case 58: /* module_attributes: %empty  */
#line 595 "conf_parser.y"
{
  (yyval.number) = 0;
}
#line 3737 "conf_parser.c"
    break;

  case 59: /* module_attributes: ':' module_attributes_items  */
#line 598 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3745 "conf_parser.c"
    break;

  case 60: /* module_attributes_items: module_attributes_items ',' module_attributes_item  */
#line 603 "conf_parser.y"
{
  (yyval.number) = (yyvsp[-2].number) | (yyvsp[0].number);
}
#line 3753 "conf_parser.c"
    break;

  case 61: /* module_attributes_items: module_attributes_item  */
#line 606 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3761 "conf_parser.c"
    break;

  case 62: /* module_attributes_item: RESIDENT  */
#line 611 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_DEACTIVATE;
}
#line 3769 "conf_parser.c"
    break;

  case 63: /* module_attributes_item: REQUIRED  */
#line 614 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_REMOVE;
}
#line 3777 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 640 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3789 "conf_parser.c"
    break;

  case 80: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 649 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3801 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 658 "conf_parser.y"
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
#line 3819 "conf_parser.c"
    break;

  case 82: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 673 "conf_parser.y"
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
#line 3837 "conf_parser.c"
    break;

  case 83: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 688 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3850 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 698 "conf_parser.y"
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
#line 3867 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 712 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3879 "conf_parser.c"
    break;

  case 86: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 721 "conf_parser.y"
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
#line 3905 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 744 "conf_parser.y"
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
#line 3931 "conf_parser.c"
    break;

  case 88: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3943 "conf_parser.c"
    break;

  case 89: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 776 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = (yyvsp[-1].boolean);
}
#line 3952 "conf_parser.c"
    break;

  case 97: /* admin_name: NAME '=' QSTRING ';'  */
#line 794 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3964 "conf_parser.c"
    break;

  case 98: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 803 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3976 "conf_parser.c"
    break;

  case 99: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 812 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3988 "conf_parser.c"
    break;

  case 100: /* $@1: %empty  */
#line 825 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3997 "conf_parser.c"
    break;

  case 101: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 829 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 4014 "conf_parser.c"
    break;

  case 107: /* motd_mask: MASK '=' QSTRING ';'  */
#line 846 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4023 "conf_parser.c"
    break;

  case 108: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 852 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 4032 "conf_parser.c"
    break;

  case 109: /* $@2: %empty  */
#line 862 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4041 "conf_parser.c"
    break;

  case 110: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 866 "conf_parser.y"
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
#line 4059 "conf_parser.c"
    break;

  case 118: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 884 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 4068 "conf_parser.c"
    break;

  case 119: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 890 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4077 "conf_parser.c"
    break;

  case 120: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 896 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 4086 "conf_parser.c"
    break;

  case 121: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 902 "conf_parser.y"
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
#line 4108 "conf_parser.c"
    break;

  case 128: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 931 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = (yyvsp[-1].boolean);
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 4120 "conf_parser.c"
    break;

  case 129: /* $@3: %empty  */
#line 940 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4129 "conf_parser.c"
    break;

  case 130: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 944 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 4142 "conf_parser.c"
    break;

  case 137: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 960 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 4153 "conf_parser.c"
    break;

  case 138: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 968 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 4161 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 971 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 4169 "conf_parser.c"
    break;

  case 140: /* $@4: %empty  */
#line 976 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 4178 "conf_parser.c"
    break;

  case 142: /* logging_file_type_item: USER  */
#line 982 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4187 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: OPERATOR  */
#line 986 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4196 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: XLINE  */
#line 990 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4205 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: RESV  */
#line 994 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4214 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: T_DLINE  */
#line 998 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4223 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: KLINE  */
#line 1002 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4232 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KILL  */
#line 1006 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4241 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: T_DEBUG  */
#line 1010 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4250 "conf_parser.c"
    break;

  case 150: /* $@5: %empty  */
#line 1020 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4262 "conf_parser.c"
    break;

  case 151: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 1027 "conf_parser.y"
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
#line 4320 "conf_parser.c"
    break;

  case 165: /* oper_name: NAME '=' QSTRING ';'  */
#line 1095 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4329 "conf_parser.c"
    break;

  case 166: /* oper_user: USER '=' QSTRING ';'  */
#line 1101 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4338 "conf_parser.c"
    break;

  case 167: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1107 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4347 "conf_parser.c"
    break;

  case 168: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1113 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4356 "conf_parser.c"
    break;

  case 169: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1119 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].boolean))
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4370 "conf_parser.c"
    break;

  case 170: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1130 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4379 "conf_parser.c"
    break;

  case 171: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1136 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].boolean))
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4393 "conf_parser.c"
    break;

  case 172: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1147 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4402 "conf_parser.c"
    break;

  case 173: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1153 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4411 "conf_parser.c"
    break;

  case 174: /* $@6: %empty  */
#line 1159 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4420 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: KILL ':' REMOTE  */
#line 1166 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4429 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: KILL  */
#line 1170 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4438 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1174 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4447 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: CONNECT  */
#line 1178 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4456 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1182 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4465 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: SQUIT  */
#line 1186 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4474 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: KLINE  */
#line 1190 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4483 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: UNKLINE  */
#line 1194 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4492 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_DLINE  */
#line 1198 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4501 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_UNDLINE  */
#line 1202 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4510 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: XLINE  */
#line 1206 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4519 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_UNXLINE  */
#line 1210 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4528 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: DIE  */
#line 1214 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4537 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_RESTART  */
#line 1218 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4546 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1222 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4555 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REHASH  */
#line 1226 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4564 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: ADMIN  */
#line 1230 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4573 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_GLOBOPS  */
#line 1234 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4582 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_LOCOPS  */
#line 1238 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4591 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: REMOTEBAN  */
#line 1242 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4600 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: T_SET  */
#line 1246 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4609 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: MODULE  */
#line 1250 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4618 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: T_OPME  */
#line 1254 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4627 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: NICK ':' RESV  */
#line 1258 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4636 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: JOIN ':' RESV  */
#line 1262 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4645 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: RESV  */
#line 1266 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4654 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: T_UNRESV  */
#line 1270 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4663 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: CLOSE  */
#line 1274 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4672 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1278 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4681 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: BYPASS ':' INPUT_FLOOD  */
#line 1282 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_BYPASS_INPUT_FLOOD;
}
#line 4690 "conf_parser.c"
    break;

  case 208: /* $@7: %empty  */
#line 1292 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4705 "conf_parser.c"
    break;

  case 209: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1302 "conf_parser.y"
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
#line 4752 "conf_parser.c"
    break;

  case 227: /* class_name: NAME '=' QSTRING ';'  */
#line 1363 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4761 "conf_parser.c"
    break;

  case 228: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1369 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4770 "conf_parser.c"
    break;

  case 229: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1375 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4779 "conf_parser.c"
    break;

  case 230: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1381 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4788 "conf_parser.c"
    break;

  case 231: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1387 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4797 "conf_parser.c"
    break;

  case 232: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1393 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4806 "conf_parser.c"
    break;

  case 233: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1399 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4815 "conf_parser.c"
    break;

  case 234: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1405 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4825 "conf_parser.c"
    break;

  case 235: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1412 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4834 "conf_parser.c"
    break;

  case 236: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1418 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4843 "conf_parser.c"
    break;

  case 237: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1424 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4852 "conf_parser.c"
    break;

  case 238: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1430 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4864 "conf_parser.c"
    break;

  case 239: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1439 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4876 "conf_parser.c"
    break;

  case 240: /* $@8: %empty  */
#line 1448 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4885 "conf_parser.c"
    break;

  case 244: /* class_flags_item: RANDOM_IDLE  */
#line 1455 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4894 "conf_parser.c"
    break;

  case 245: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1459 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4903 "conf_parser.c"
    break;

  case 246: /* $@9: %empty  */
#line 1469 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4912 "conf_parser.c"
    break;

  case 248: /* $@10: %empty  */
#line 1475 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4920 "conf_parser.c"
    break;

  case 252: /* listen_flags_item: T_TLS  */
#line 1481 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4929 "conf_parser.c"
    break;

  case 253: /* listen_flags_item: HIDDEN  */
#line 1485 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4938 "conf_parser.c"
    break;

  case 254: /* listen_flags_item: T_SERVER  */
#line 1489 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4947 "conf_parser.c"
    break;

  case 255: /* listen_flags_item: CLIENT  */
#line 1493 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4956 "conf_parser.c"
    break;

  case 256: /* listen_flags_item: DEFER  */
#line 1497 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4965 "conf_parser.c"
    break;

  case 264: /* $@11: %empty  */
#line 1505 "conf_parser.y"
                                 { reset_block_state(); }
#line 4971 "conf_parser.c"
    break;

  case 268: /* port_item: port_number  */
#line 1510 "conf_parser.y"
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
#line 4989 "conf_parser.c"
    break;

  case 269: /* port_item: port_number TWODOTS port_number  */
#line 1523 "conf_parser.y"
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
#line 5009 "conf_parser.c"
    break;

  case 270: /* listen_address: IP '=' QSTRING ';'  */
#line 1540 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5018 "conf_parser.c"
    break;

  case 271: /* listen_host: HOST '=' QSTRING ';'  */
#line 1546 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5027 "conf_parser.c"
    break;

  case 272: /* $@12: %empty  */
#line 1556 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5036 "conf_parser.c"
    break;

  case 273: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1560 "conf_parser.y"
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
#line 5091 "conf_parser.c"
    break;

  case 283: /* auth_user: USER '=' QSTRING ';'  */
#line 1621 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5100 "conf_parser.c"
    break;

  case 284: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1627 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5109 "conf_parser.c"
    break;

  case 285: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1633 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5118 "conf_parser.c"
    break;

  case 286: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1639 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].boolean))
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5132 "conf_parser.c"
    break;

  case 287: /* $@13: %empty  */
#line 1650 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 5141 "conf_parser.c"
    break;

  case 291: /* auth_flags_item: EXCEED_LIMIT  */
#line 1658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 5150 "conf_parser.c"
    break;

  case 292: /* auth_flags_item: KLINE_EXEMPT  */
#line 1662 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 5159 "conf_parser.c"
    break;

  case 293: /* auth_flags_item: XLINE_EXEMPT  */
#line 1666 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 5168 "conf_parser.c"
    break;

  case 294: /* auth_flags_item: NEED_IDENT  */
#line 1670 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 5177 "conf_parser.c"
    break;

  case 295: /* auth_flags_item: CAN_FLOOD  */
#line 1674 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 5186 "conf_parser.c"
    break;

  case 296: /* auth_flags_item: NO_TILDE  */
#line 1678 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 5195 "conf_parser.c"
    break;

  case 297: /* auth_flags_item: RESV_EXEMPT  */
#line 1682 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 5204 "conf_parser.c"
    break;

  case 298: /* auth_flags_item: T_WEBIRC  */
#line 1686 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5213 "conf_parser.c"
    break;

  case 299: /* auth_flags_item: NEED_PASSWORD  */
#line 1690 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5222 "conf_parser.c"
    break;

  case 300: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1696 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    log_write(LOG_TYPE_IRCD,
              "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 5237 "conf_parser.c"
    break;

  case 301: /* $@14: %empty  */
#line 1711 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5249 "conf_parser.c"
    break;

  case 302: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1718 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5260 "conf_parser.c"
    break;

  case 309: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1729 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5269 "conf_parser.c"
    break;

  case 310: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1735 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5278 "conf_parser.c"
    break;

  case 311: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1741 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5287 "conf_parser.c"
    break;

  case 317: /* service_name: NAME '=' QSTRING ';'  */
#line 1756 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5302 "conf_parser.c"
    break;

  case 318: /* $@15: %empty  */
#line 1772 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5318 "conf_parser.c"
    break;

  case 319: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1783 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5333 "conf_parser.c"
    break;

  case 326: /* shared_name: NAME '=' QSTRING ';'  */
#line 1798 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5342 "conf_parser.c"
    break;

  case 327: /* shared_user: USER '=' QSTRING ';'  */
#line 1804 "conf_parser.y"
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
#line 5364 "conf_parser.c"
    break;

  case 328: /* $@16: %empty  */
#line 1823 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5373 "conf_parser.c"
    break;

  case 332: /* shared_type_item: KLINE  */
#line 1830 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5382 "conf_parser.c"
    break;

  case 333: /* shared_type_item: UNKLINE  */
#line 1834 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5391 "conf_parser.c"
    break;

  case 334: /* shared_type_item: T_DLINE  */
#line 1838 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5400 "conf_parser.c"
    break;

  case 335: /* shared_type_item: T_UNDLINE  */
#line 1842 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5409 "conf_parser.c"
    break;

  case 336: /* shared_type_item: XLINE  */
#line 1846 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5418 "conf_parser.c"
    break;

  case 337: /* shared_type_item: T_UNXLINE  */
#line 1850 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5427 "conf_parser.c"
    break;

  case 338: /* shared_type_item: REHASH  */
#line 1854 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_REHASH;
}
#line 5436 "conf_parser.c"
    break;

  case 339: /* shared_type_item: RESV  */
#line 1858 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5445 "conf_parser.c"
    break;

  case 340: /* shared_type_item: T_UNRESV  */
#line 1862 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5454 "conf_parser.c"
    break;

  case 341: /* shared_type_item: T_LOCOPS  */
#line 1866 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5463 "conf_parser.c"
    break;

  case 342: /* shared_type_item: T_ALL  */
#line 1870 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5472 "conf_parser.c"
    break;

  case 343: /* $@17: %empty  */
#line 1880 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5486 "conf_parser.c"
    break;

  case 344: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1889 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5499 "conf_parser.c"
    break;

  case 350: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1902 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5508 "conf_parser.c"
    break;

  case 351: /* $@18: %empty  */
#line 1908 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5517 "conf_parser.c"
    break;

  case 355: /* cluster_type_item: KLINE  */
#line 1915 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5526 "conf_parser.c"
    break;

  case 356: /* cluster_type_item: UNKLINE  */
#line 1919 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5535 "conf_parser.c"
    break;

  case 357: /* cluster_type_item: T_DLINE  */
#line 1923 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5544 "conf_parser.c"
    break;

  case 358: /* cluster_type_item: T_UNDLINE  */
#line 1927 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5553 "conf_parser.c"
    break;

  case 359: /* cluster_type_item: XLINE  */
#line 1931 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5562 "conf_parser.c"
    break;

  case 360: /* cluster_type_item: T_UNXLINE  */
#line 1935 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5571 "conf_parser.c"
    break;

  case 361: /* cluster_type_item: RESV  */
#line 1939 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5580 "conf_parser.c"
    break;

  case 362: /* cluster_type_item: T_UNRESV  */
#line 1943 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5589 "conf_parser.c"
    break;

  case 363: /* cluster_type_item: T_LOCOPS  */
#line 1947 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5598 "conf_parser.c"
    break;

  case 364: /* cluster_type_item: T_ALL  */
#line 1951 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5607 "conf_parser.c"
    break;

  case 365: /* $@19: %empty  */
#line 1961 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECT_DEFAULT_TIMEOUT_SEC;
  block_state.retry_delay_sec.value = CONNECT_DEFAULT_RETRY_DELAY_SEC;
}
#line 5622 "conf_parser.c"
    break;

  case 366: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1971 "conf_parser.y"
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
#line 5671 "conf_parser.c"
    break;

  case 385: /* connect_name: NAME '=' QSTRING ';'  */
#line 2035 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5680 "conf_parser.c"
    break;

  case 386: /* connect_host: HOST '=' QSTRING ';'  */
#line 2041 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5689 "conf_parser.c"
    break;

  case 387: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 2047 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5698 "conf_parser.c"
    break;

  case 388: /* connect_retry_delay: RETRY_DELAY '=' timespec ';'  */
#line 2053 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.retry_delay_sec.value = (yyvsp[-1].number);
}
#line 5707 "conf_parser.c"
    break;

  case 389: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 2059 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5716 "conf_parser.c"
    break;

  case 390: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2065 "conf_parser.y"
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
#line 5732 "conf_parser.c"
    break;

  case 391: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2078 "conf_parser.y"
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
#line 5748 "conf_parser.c"
    break;

  case 392: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2091 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5757 "conf_parser.c"
    break;

  case 393: /* connect_port: PORT '=' port_number ';'  */
#line 2097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5766 "conf_parser.c"
    break;

  case 394: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2103 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5775 "conf_parser.c"
    break;

  case 395: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2107 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5784 "conf_parser.c"
    break;

  case 396: /* $@20: %empty  */
#line 2113 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5792 "conf_parser.c"
    break;

  case 400: /* connect_flags_item: AUTOCONN  */
#line 2119 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5801 "conf_parser.c"
    break;

  case 401: /* connect_flags_item: T_TLS  */
#line 2123 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5810 "conf_parser.c"
    break;

  case 402: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2129 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].boolean))
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5824 "conf_parser.c"
    break;

  case 403: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2140 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5833 "conf_parser.c"
    break;

  case 404: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2146 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5842 "conf_parser.c"
    break;

  case 405: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2152 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5851 "conf_parser.c"
    break;

  case 406: /* $@21: %empty  */
#line 2162 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5860 "conf_parser.c"
    break;

  case 407: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2166 "conf_parser.y"
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
#line 5884 "conf_parser.c"
    break;

  case 413: /* kill_user: USER '=' QSTRING ';'  */
#line 2190 "conf_parser.y"
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
#line 5907 "conf_parser.c"
    break;

  case 414: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2210 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5916 "conf_parser.c"
    break;

  case 415: /* $@22: %empty  */
#line 2220 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5925 "conf_parser.c"
    break;

  case 416: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2224 "conf_parser.y"
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
#line 5947 "conf_parser.c"
    break;

  case 422: /* deny_ip: IP '=' QSTRING ';'  */
#line 2246 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5956 "conf_parser.c"
    break;

  case 423: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2252 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5965 "conf_parser.c"
    break;

  case 429: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2267 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_error_report("Unable to add D-line exemption");
}
#line 5977 "conf_parser.c"
    break;

  case 430: /* $@23: %empty  */
#line 2280 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5986 "conf_parser.c"
    break;

  case 431: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2284 "conf_parser.y"
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
#line 6006 "conf_parser.c"
    break;

  case 437: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2304 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 6015 "conf_parser.c"
    break;

  case 438: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2310 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 6024 "conf_parser.c"
    break;

  case 482: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2365 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 6032 "conf_parser.c"
    break;

  case 483: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2370 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 6040 "conf_parser.c"
    break;

  case 484: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2375 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 6048 "conf_parser.c"
    break;

  case 485: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2380 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 6056 "conf_parser.c"
    break;

  case 486: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2385 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 6064 "conf_parser.c"
    break;

  case 487: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2390 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 6072 "conf_parser.c"
    break;

  case 488: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2395 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6080 "conf_parser.c"
    break;

  case 489: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2400 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6088 "conf_parser.c"
    break;

  case 490: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2405 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6096 "conf_parser.c"
    break;

  case 491: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2410 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6104 "conf_parser.c"
    break;

  case 492: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2415 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6112 "conf_parser.c"
    break;

  case 493: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2420 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6120 "conf_parser.c"
    break;

  case 494: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2425 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 6131 "conf_parser.c"
    break;

  case 495: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2433 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6139 "conf_parser.c"
    break;

  case 496: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2438 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6147 "conf_parser.c"
    break;

  case 497: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2443 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6155 "conf_parser.c"
    break;

  case 498: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2448 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = (yyvsp[-1].boolean);
}
#line 6163 "conf_parser.c"
    break;

  case 499: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2453 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = (yyvsp[-1].boolean);
}
#line 6171 "conf_parser.c"
    break;

  case 500: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2458 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = (yyvsp[-1].boolean);
}
#line 6179 "conf_parser.c"
    break;

  case 501: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2463 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = (yyvsp[-1].boolean);
}
#line 6187 "conf_parser.c"
    break;

  case 502: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2468 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6195 "conf_parser.c"
    break;

  case 503: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2473 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6203 "conf_parser.c"
    break;

  case 504: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2478 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = (yyvsp[-1].boolean);
}
#line 6211 "conf_parser.c"
    break;

  case 505: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2483 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6219 "conf_parser.c"
    break;

  case 506: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2488 "conf_parser.y"
{
  ConfigGeneral.short_motd = (yyvsp[-1].boolean);
}
#line 6227 "conf_parser.c"
    break;

  case 507: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2493 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6235 "conf_parser.c"
    break;

  case 508: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2498 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6243 "conf_parser.c"
    break;

  case 509: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2503 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = (yyvsp[-1].boolean);
}
#line 6251 "conf_parser.c"
    break;

  case 510: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2508 "conf_parser.y"
{
  ConfigGeneral.disable_ident = (yyvsp[-1].boolean);
}
#line 6259 "conf_parser.c"
    break;

  case 511: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2513 "conf_parser.y"
{
  ConfigGeneral.disable_dns = (yyvsp[-1].boolean);
}
#line 6267 "conf_parser.c"
    break;

  case 512: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2518 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6275 "conf_parser.c"
    break;

  case 513: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2523 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6283 "conf_parser.c"
    break;

  case 514: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2528 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6295 "conf_parser.c"
    break;

  case 515: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2537 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6303 "conf_parser.c"
    break;

  case 516: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2542 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6311 "conf_parser.c"
    break;

  case 517: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2547 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6319 "conf_parser.c"
    break;

  case 518: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2552 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6327 "conf_parser.c"
    break;

  case 519: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2557 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6338 "conf_parser.c"
    break;

  case 520: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2565 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6346 "conf_parser.c"
    break;

  case 531: /* cloak_enabled: ENABLED '=' TBOOL ';'  */
#line 2585 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.enabled = (yyvsp[-1].boolean);
  if (ConfigCloak.enabled)
    cloak_set_enabled();
  else
    cloak_set_disabled();
}
#line 6361 "conf_parser.c"
    break;

  case 532: /* cloak_cidr_len_ipv4: CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2597 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6373 "conf_parser.c"
    break;

  case 533: /* cloak_cidr_len_ipv6: CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2606 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6385 "conf_parser.c"
    break;

  case 534: /* cloak_num_bits: NUM_BITS '=' NUMBER ';'  */
#line 2615 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6397 "conf_parser.c"
    break;

  case 535: /* cloak_secret: SECRET '=' QSTRING ';'  */
#line 2624 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.secret);
  ConfigCloak.secret = io_strdup((yyvsp[-1].string));
  cloak_set_secret((yyvsp[-1].string));
}
#line 6410 "conf_parser.c"
    break;

  case 536: /* cloak_suffix: SUFFIX '=' QSTRING ';'  */
#line 2634 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.suffix);
  ConfigCloak.suffix = io_strdup((yyvsp[-1].string));
  cloak_set_suffix((yyvsp[-1].string));
}
#line 6423 "conf_parser.c"
    break;

  case 557: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2669 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = (yyvsp[-1].boolean);
}
#line 6431 "conf_parser.c"
    break;

  case 558: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2674 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6439 "conf_parser.c"
    break;

  case 559: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2679 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6447 "conf_parser.c"
    break;

  case 560: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2684 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6455 "conf_parser.c"
    break;

  case 561: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2689 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6463 "conf_parser.c"
    break;

  case 562: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2694 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6471 "conf_parser.c"
    break;

  case 563: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2699 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6479 "conf_parser.c"
    break;

  case 564: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2704 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6487 "conf_parser.c"
    break;

  case 565: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2709 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6495 "conf_parser.c"
    break;

  case 566: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2714 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6503 "conf_parser.c"
    break;

  case 567: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2719 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6511 "conf_parser.c"
    break;

  case 568: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2724 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6519 "conf_parser.c"
    break;

  case 569: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2729 "conf_parser.y"
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
#line 6545 "conf_parser.c"
    break;

  case 570: /* channel_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 2752 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigChannel.max_topic_length = TOPICLEN;
  else
    ConfigChannel.max_topic_length = (yyvsp[-1].number);
}
#line 6556 "conf_parser.c"
    break;

  case 571: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2760 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = (yyvsp[-1].number);
}
#line 6564 "conf_parser.c"
    break;

  case 572: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2765 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6572 "conf_parser.c"
    break;

  case 585: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2787 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = (yyvsp[-1].boolean);
}
#line 6581 "conf_parser.c"
    break;

  case 586: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2793 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6595 "conf_parser.c"
    break;

  case 587: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2804 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6607 "conf_parser.c"
    break;

  case 588: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2813 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = (yyvsp[-1].boolean);
}
#line 6616 "conf_parser.c"
    break;

  case 589: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2819 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = (yyvsp[-1].boolean);
}
#line 6625 "conf_parser.c"
    break;

  case 590: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2825 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = (yyvsp[-1].boolean);
}
#line 6634 "conf_parser.c"
    break;

  case 591: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2831 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6646 "conf_parser.c"
    break;

  case 592: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2840 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = (yyvsp[-1].boolean);
}
#line 6655 "conf_parser.c"
    break;


#line 6659 "conf_parser.c"

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

