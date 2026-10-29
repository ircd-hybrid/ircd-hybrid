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


#line 248 "conf_parser.c"

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

#line 287 "conf_parser.c"

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
    SEND_PASSWORD = 404,           /* SEND_PASSWORD  */
    SENDQ = 405,                   /* SENDQ  */
    SERVERHIDE = 406,              /* SERVERHIDE  */
    SERVERINFO = 407,              /* SERVERINFO  */
    SHORT_MOTD = 408,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 409,       /* SPECIALS_IN_IDENT  */
    SPOOF = 410,                   /* SPOOF  */
    SQUIT = 411,                   /* SQUIT  */
    STATS_E_DISABLED = 412,        /* STATS_E_DISABLED  */
    STATS_U_OPER_ONLY = 413,       /* STATS_U_OPER_ONLY  */
    SUFFIX = 414,                  /* SUFFIX  */
    T_ALL = 415,                   /* T_ALL  */
    T_BIND = 416,                  /* T_BIND  */
    T_COMMAND = 417,               /* T_COMMAND  */
    T_CLUSTER = 418,               /* T_CLUSTER  */
    T_DEBUG = 419,                 /* T_DEBUG  */
    T_DLINE = 420,                 /* T_DLINE  */
    T_FILE = 421,                  /* T_FILE  */
    T_GLOBOPS = 422,               /* T_GLOBOPS  */
    T_IPV4 = 423,                  /* T_IPV4  */
    T_IPV6 = 424,                  /* T_IPV6  */
    T_LOCOPS = 425,                /* T_LOCOPS  */
    T_LOG = 426,                   /* T_LOG  */
    T_OPME = 427,                  /* T_OPME  */
    T_PREPEND = 428,               /* T_PREPEND  */
    T_PSEUDO = 429,                /* T_PSEUDO  */
    T_RECVQ = 430,                 /* T_RECVQ  */
    T_RESTART = 431,               /* T_RESTART  */
    T_SERVER = 432,                /* T_SERVER  */
    T_SERVICE = 433,               /* T_SERVICE  */
    T_SET = 434,                   /* T_SET  */
    T_SHARED = 435,                /* T_SHARED  */
    T_SIZE = 436,                  /* T_SIZE  */
    T_TARGET = 437,                /* T_TARGET  */
    T_TLS = 438,                   /* T_TLS  */
    T_UMODES = 439,                /* T_UMODES  */
    T_UNDLINE = 440,               /* T_UNDLINE  */
    T_UNLIMITED = 441,             /* T_UNLIMITED  */
    T_UNRESV = 442,                /* T_UNRESV  */
    T_UNXLINE = 443,               /* T_UNXLINE  */
    T_WEBIRC = 444,                /* T_WEBIRC  */
    TBOOL = 445,                   /* TBOOL  */
    THROTTLE_COUNT = 446,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 447,           /* THROTTLE_TIME  */
    TIMEOUT = 448,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 449,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 450, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 451,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 452, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 453,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 454,           /* TS_WARN_DELTA  */
    TWODOTS = 455,                 /* TWODOTS  */
    TYPE = 456,                    /* TYPE  */
    UNKLINE = 457,                 /* UNKLINE  */
    USE_LOGGING = 458,             /* USE_LOGGING  */
    USER = 459,                    /* USER  */
    WARN_NO_CONNECT_BLOCK = 460,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 461,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 462,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 463,                   /* XLINE  */
    XLINE_EXEMPT = 464,            /* XLINE_EXEMPT  */
    QSTRING = 465,                 /* QSTRING  */
    DECIMAL = 466,                 /* DECIMAL  */
    NUMBER = 467                   /* NUMBER  */
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
#define SEND_PASSWORD 404
#define SENDQ 405
#define SERVERHIDE 406
#define SERVERINFO 407
#define SHORT_MOTD 408
#define SPECIALS_IN_IDENT 409
#define SPOOF 410
#define SQUIT 411
#define STATS_E_DISABLED 412
#define STATS_U_OPER_ONLY 413
#define SUFFIX 414
#define T_ALL 415
#define T_BIND 416
#define T_COMMAND 417
#define T_CLUSTER 418
#define T_DEBUG 419
#define T_DLINE 420
#define T_FILE 421
#define T_GLOBOPS 422
#define T_IPV4 423
#define T_IPV6 424
#define T_LOCOPS 425
#define T_LOG 426
#define T_OPME 427
#define T_PREPEND 428
#define T_PSEUDO 429
#define T_RECVQ 430
#define T_RESTART 431
#define T_SERVER 432
#define T_SERVICE 433
#define T_SET 434
#define T_SHARED 435
#define T_SIZE 436
#define T_TARGET 437
#define T_TLS 438
#define T_UMODES 439
#define T_UNDLINE 440
#define T_UNLIMITED 441
#define T_UNRESV 442
#define T_UNXLINE 443
#define T_WEBIRC 444
#define TBOOL 445
#define THROTTLE_COUNT 446
#define THROTTLE_TIME 447
#define TIMEOUT 448
#define TLS_CERTIFICATE_FILE 449
#define TLS_CERTIFICATE_FINGERPRINT 450
#define TLS_PRIVATE_KEY_FILE 451
#define TLS_CONNECTION_REQUIRED 452
#define TS_MAX_DELTA 453
#define TS_WARN_DELTA 454
#define TWODOTS 455
#define TYPE 456
#define UNKLINE 457
#define USE_LOGGING 458
#define USER 459
#define WARN_NO_CONNECT_BLOCK 460
#define WHOIS 461
#define WHOWAS_HISTORY_LENGTH 462
#define XLINE 463
#define XLINE_EXEMPT 464
#define QSTRING 465
#define DECIMAL 466
#define NUMBER 467

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 193 "conf_parser.y"

  bool boolean;
  unsigned int number;
  char *string;

#line 737 "conf_parser.c"

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
  YYSYMBOL_SEND_PASSWORD = 149,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 150,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 151,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 152,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 153,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 154,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 155,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 156,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 157,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_U_OPER_ONLY = 158,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_SUFFIX = 159,                   /* SUFFIX  */
  YYSYMBOL_T_ALL = 160,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 161,                   /* T_BIND  */
  YYSYMBOL_T_COMMAND = 162,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 163,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 164,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 165,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 166,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 167,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 168,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 169,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 170,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 171,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 172,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 173,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 174,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 175,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 176,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 177,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 178,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 179,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 180,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 181,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 182,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 183,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 184,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 185,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 186,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 187,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 188,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 189,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 190,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 191,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 192,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 193,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 194,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 195, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_PRIVATE_KEY_FILE = 196,     /* TLS_PRIVATE_KEY_FILE  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 197,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TS_MAX_DELTA = 198,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 199,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 200,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 201,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 202,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 203,              /* USE_LOGGING  */
  YYSYMBOL_USER = 204,                     /* USER  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 205,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 206,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 207,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 208,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 209,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 210,                  /* QSTRING  */
  YYSYMBOL_DECIMAL = 211,                  /* DECIMAL  */
  YYSYMBOL_NUMBER = 212,                   /* NUMBER  */
  YYSYMBOL_213_ = 213,                     /* ';'  */
  YYSYMBOL_214_ = 214,                     /* '}'  */
  YYSYMBOL_215_ = 215,                     /* '='  */
  YYSYMBOL_216_ = 216,                     /* ':'  */
  YYSYMBOL_217_ = 217,                     /* ','  */
  YYSYMBOL_218_ = 218,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 219,                 /* $accept  */
  YYSYMBOL_conf = 220,                     /* conf  */
  YYSYMBOL_conf_item = 221,                /* conf_item  */
  YYSYMBOL_timespec = 222,                 /* timespec  */
  YYSYMBOL_time_components = 223,          /* time_components  */
  YYSYMBOL_time_component = 224,           /* time_component  */
  YYSYMBOL_time_unit = 225,                /* time_unit  */
  YYSYMBOL_sizespec = 226,                 /* sizespec  */
  YYSYMBOL_size_components = 227,          /* size_components  */
  YYSYMBOL_size_component = 228,           /* size_component  */
  YYSYMBOL_size_unit = 229,                /* size_unit  */
  YYSYMBOL_port_number = 230,              /* port_number  */
  YYSYMBOL_module_base_path_entry = 231,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 232,         /* loadmodule_entry  */
  YYSYMBOL_module_string = 233,            /* module_string  */
  YYSYMBOL_module_attributes = 234,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 235,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 236,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 237,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 238,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 239,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 240, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_tls_private_key_file = 241, /* serverinfo_tls_private_key_file  */
  YYSYMBOL_serverinfo_name = 242,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 243,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 244,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 245,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 246, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 247, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 248, /* serverinfo_max_nick_length  */
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
  YYSYMBOL_class_max_channels = 309,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 310,         /* class_max_number  */
  YYSYMBOL_class_sendq = 311,              /* class_sendq  */
  YYSYMBOL_class_recvq = 312,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 313,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 314,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 315,    /* class_number_per_cidr  */
  YYSYMBOL_class_min_idle = 316,           /* class_min_idle  */
  YYSYMBOL_class_max_idle = 317,           /* class_max_idle  */
  YYSYMBOL_class_flags = 318,              /* class_flags  */
  YYSYMBOL_319_8 = 319,                    /* $@8  */
  YYSYMBOL_class_flags_items = 320,        /* class_flags_items  */
  YYSYMBOL_class_flags_item = 321,         /* class_flags_item  */
  YYSYMBOL_listen_entry = 322,             /* listen_entry  */
  YYSYMBOL_323_9 = 323,                    /* $@9  */
  YYSYMBOL_listen_flags = 324,             /* listen_flags  */
  YYSYMBOL_325_10 = 325,                   /* $@10  */
  YYSYMBOL_listen_flags_items = 326,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 327,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 328,             /* listen_items  */
  YYSYMBOL_listen_item = 329,              /* listen_item  */
  YYSYMBOL_listen_port = 330,              /* listen_port  */
  YYSYMBOL_331_11 = 331,                   /* $@11  */
  YYSYMBOL_port_items = 332,               /* port_items  */
  YYSYMBOL_port_item = 333,                /* port_item  */
  YYSYMBOL_listen_address = 334,           /* listen_address  */
  YYSYMBOL_listen_host = 335,              /* listen_host  */
  YYSYMBOL_auth_entry = 336,               /* auth_entry  */
  YYSYMBOL_337_12 = 337,                   /* $@12  */
  YYSYMBOL_auth_items = 338,               /* auth_items  */
  YYSYMBOL_auth_item = 339,                /* auth_item  */
  YYSYMBOL_auth_user = 340,                /* auth_user  */
  YYSYMBOL_auth_passwd = 341,              /* auth_passwd  */
  YYSYMBOL_auth_class = 342,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 343,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 344,               /* auth_flags  */
  YYSYMBOL_345_13 = 345,                   /* $@13  */
  YYSYMBOL_auth_flags_items = 346,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 347,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 348,               /* auth_spoof  */
  YYSYMBOL_resv_entry = 349,               /* resv_entry  */
  YYSYMBOL_350_14 = 350,                   /* $@14  */
  YYSYMBOL_resv_items = 351,               /* resv_items  */
  YYSYMBOL_resv_item = 352,                /* resv_item  */
  YYSYMBOL_resv_mask = 353,                /* resv_mask  */
  YYSYMBOL_resv_reason = 354,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 355,              /* resv_exempt  */
  YYSYMBOL_service_entry = 356,            /* service_entry  */
  YYSYMBOL_service_items = 357,            /* service_items  */
  YYSYMBOL_service_item = 358,             /* service_item  */
  YYSYMBOL_service_name = 359,             /* service_name  */
  YYSYMBOL_shared_entry = 360,             /* shared_entry  */
  YYSYMBOL_361_15 = 361,                   /* $@15  */
  YYSYMBOL_shared_items = 362,             /* shared_items  */
  YYSYMBOL_shared_item = 363,              /* shared_item  */
  YYSYMBOL_shared_name = 364,              /* shared_name  */
  YYSYMBOL_shared_user = 365,              /* shared_user  */
  YYSYMBOL_shared_type = 366,              /* shared_type  */
  YYSYMBOL_367_16 = 367,                   /* $@16  */
  YYSYMBOL_shared_types = 368,             /* shared_types  */
  YYSYMBOL_shared_type_item = 369,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 370,            /* cluster_entry  */
  YYSYMBOL_371_17 = 371,                   /* $@17  */
  YYSYMBOL_cluster_items = 372,            /* cluster_items  */
  YYSYMBOL_cluster_item = 373,             /* cluster_item  */
  YYSYMBOL_cluster_name = 374,             /* cluster_name  */
  YYSYMBOL_cluster_type = 375,             /* cluster_type  */
  YYSYMBOL_376_18 = 376,                   /* $@18  */
  YYSYMBOL_cluster_types = 377,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 378,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 379,            /* connect_entry  */
  YYSYMBOL_380_19 = 380,                   /* $@19  */
  YYSYMBOL_connect_items = 381,            /* connect_items  */
  YYSYMBOL_connect_item = 382,             /* connect_item  */
  YYSYMBOL_connect_name = 383,             /* connect_name  */
  YYSYMBOL_connect_host = 384,             /* connect_host  */
  YYSYMBOL_connect_timeout = 385,          /* connect_timeout  */
  YYSYMBOL_connect_retry_delay = 386,      /* connect_retry_delay  */
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
  YYSYMBOL_general_dline_min_cidr = 430,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 431,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 432,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 433,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 434, /* general_kill_chase_time_limit  */
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
  YYSYMBOL_general_ident_timeout = 463,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 464, /* general_registration_timeout  */
  YYSYMBOL_cloak_entry = 465,              /* cloak_entry  */
  YYSYMBOL_cloak_items = 466,              /* cloak_items  */
  YYSYMBOL_cloak_item = 467,               /* cloak_item  */
  YYSYMBOL_cloak_enabled = 468,            /* cloak_enabled  */
  YYSYMBOL_cloak_cidr_len_ipv4 = 469,      /* cloak_cidr_len_ipv4  */
  YYSYMBOL_cloak_cidr_len_ipv6 = 470,      /* cloak_cidr_len_ipv6  */
  YYSYMBOL_cloak_num_bits = 471,           /* cloak_num_bits  */
  YYSYMBOL_cloak_secret = 472,             /* cloak_secret  */
  YYSYMBOL_cloak_suffix = 473,             /* cloak_suffix  */
  YYSYMBOL_channel_entry = 474,            /* channel_entry  */
  YYSYMBOL_channel_items = 475,            /* channel_items  */
  YYSYMBOL_channel_item = 476,             /* channel_item  */
  YYSYMBOL_channel_disable_fake_channels = 477, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 478, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 479, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 480, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 481, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 482, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 483, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 484, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 485,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 486,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 487,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 488,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 489,  /* channel_max_kick_length  */
  YYSYMBOL_channel_max_topic_length = 490, /* channel_max_topic_length  */
  YYSYMBOL_channel_default_join_flood_count = 491, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 492, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 493,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 494,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 495,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 496, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 497, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 498, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 499, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 500,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 501, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 502,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 503         /* serverhide_hidden  */
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
#define YYLAST   1154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  219
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  285
/* YYNRULES -- Number of rules.  */
#define YYNRULES  592
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1208

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   467


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
       2,     2,     2,     2,   217,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   216,   213,
       2,   215,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   218,     2,   214,     2,     2,     2,     2,
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
     205,   206,   207,   208,   209,   210,   211,   212
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   408,   408,   409,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     441,   450,   452,   452,   461,   468,   480,   481,   482,   483,
     484,   487,   496,   498,   498,   507,   514,   526,   527,   528,
     529,   530,   531,   532,   535,   550,   565,   577,   583,   585,
     590,   593,   598,   601,   610,   612,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   627,
     636,   645,   659,   673,   683,   697,   706,   729,   752,   761,
     771,   773,   773,   774,   775,   776,   777,   779,   788,   797,
     811,   810,   828,   828,   829,   829,   829,   831,   837,   848,
     847,   866,   866,   867,   867,   867,   867,   867,   869,   875,
     881,   887,   910,   911,   911,   913,   913,   914,   916,   926,
     926,   939,   940,   942,   942,   943,   943,   945,   953,   956,
     962,   961,   967,   971,   975,   979,   983,   987,   991,   995,
    1006,  1005,  1067,  1067,  1068,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1080,  1086,  1092,  1098,  1104,
    1115,  1121,  1132,  1138,  1145,  1144,  1150,  1150,  1151,  1155,
    1159,  1163,  1167,  1171,  1175,  1179,  1183,  1187,  1191,  1195,
    1199,  1203,  1207,  1211,  1215,  1219,  1223,  1227,  1231,  1235,
    1239,  1243,  1247,  1251,  1255,  1259,  1263,  1267,  1278,  1277,
    1331,  1331,  1332,  1333,  1334,  1335,  1336,  1337,  1338,  1339,
    1340,  1341,  1342,  1343,  1344,  1345,  1346,  1348,  1354,  1360,
    1366,  1372,  1378,  1384,  1390,  1397,  1403,  1409,  1415,  1424,
    1434,  1433,  1439,  1439,  1440,  1444,  1455,  1454,  1461,  1460,
    1465,  1465,  1466,  1470,  1474,  1478,  1482,  1488,  1488,  1489,
    1489,  1489,  1489,  1489,  1491,  1491,  1493,  1493,  1495,  1508,
    1525,  1531,  1542,  1541,  1597,  1597,  1598,  1599,  1600,  1601,
    1602,  1603,  1604,  1606,  1612,  1618,  1624,  1636,  1635,  1641,
    1641,  1643,  1647,  1651,  1655,  1659,  1663,  1667,  1671,  1675,
    1681,  1696,  1695,  1710,  1710,  1711,  1711,  1711,  1711,  1713,
    1719,  1725,  1735,  1737,  1737,  1738,  1738,  1740,  1757,  1756,
    1779,  1779,  1780,  1780,  1780,  1780,  1782,  1788,  1808,  1807,
    1813,  1813,  1814,  1818,  1822,  1826,  1830,  1834,  1838,  1842,
    1846,  1850,  1854,  1865,  1864,  1883,  1883,  1884,  1884,  1884,
    1886,  1893,  1892,  1898,  1898,  1899,  1903,  1907,  1911,  1915,
    1919,  1923,  1927,  1931,  1935,  1946,  1945,  2001,  2001,  2002,
    2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,  2012,
    2013,  2014,  2015,  2016,  2017,  2019,  2025,  2031,  2037,  2043,
    2049,  2062,  2075,  2081,  2087,  2091,  2098,  2097,  2102,  2102,
    2103,  2107,  2113,  2124,  2130,  2136,  2147,  2146,  2171,  2171,
    2172,  2172,  2172,  2174,  2194,  2205,  2204,  2227,  2227,  2228,
    2228,  2228,  2230,  2236,  2246,  2248,  2248,  2249,  2249,  2251,
    2265,  2264,  2285,  2285,  2286,  2286,  2286,  2288,  2294,  2304,
    2306,  2306,  2307,  2308,  2309,  2310,  2311,  2312,  2313,  2314,
    2315,  2316,  2317,  2318,  2319,  2320,  2321,  2322,  2323,  2324,
    2325,  2326,  2327,  2328,  2329,  2330,  2331,  2332,  2333,  2334,
    2335,  2336,  2337,  2338,  2339,  2340,  2341,  2342,  2343,  2344,
    2345,  2346,  2349,  2354,  2359,  2364,  2369,  2374,  2379,  2384,
    2389,  2394,  2399,  2404,  2409,  2417,  2422,  2427,  2432,  2437,
    2442,  2447,  2452,  2457,  2462,  2467,  2472,  2477,  2482,  2487,
    2492,  2497,  2502,  2507,  2512,  2521,  2526,  2531,  2536,  2541,
    2549,  2558,  2560,  2560,  2561,  2562,  2563,  2564,  2565,  2566,
    2567,  2569,  2581,  2590,  2599,  2608,  2618,  2632,  2634,  2634,
    2635,  2636,  2637,  2638,  2639,  2640,  2641,  2642,  2643,  2644,
    2645,  2646,  2647,  2648,  2649,  2650,  2651,  2653,  2658,  2663,
    2668,  2673,  2678,  2683,  2688,  2693,  2698,  2703,  2708,  2713,
    2731,  2739,  2744,  2753,  2755,  2755,  2756,  2757,  2758,  2759,
    2760,  2761,  2762,  2763,  2764,  2766,  2772,  2783,  2792,  2798,
    2804,  2810,  2819
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
  "GECOS", "GENERAL", "HIDDEN", "HIDDEN_NAME", "HIDE_IDLE_FROM_OPERS",
  "HIDE_SERVERS", "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK",
  "IDENT_TIMEOUT", "INPUT_FLOOD", "INVISIBLE_ON_CONNECT",
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
  "PING_COOKIE", "PING_TIME", "PORT", "RANDOM_IDLE", "REASON",
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
  "TYPE", "UNKLINE", "USE_LOGGING", "USER", "WARN_NO_CONNECT_BLOCK",
  "WHOIS", "WHOWAS_HISTORY_LENGTH", "XLINE", "XLINE_EXEMPT", "QSTRING",
  "DECIMAL", "NUMBER", "';'", "'}'", "'='", "':'", "','", "'{'", "$accept",
  "conf", "conf_item", "timespec", "time_components", "time_component",
  "time_unit", "sizespec", "size_components", "size_component",
  "size_unit", "port_number", "module_base_path_entry", "loadmodule_entry",
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
    -647,   675,  -647,  -182,  -203,  -196,  -647,  -184,  -647,  -647,
    -176,  -647,  -173,  -647,  -647,  -647,  -160,  -162,  -647,  -647,
    -647,  -148,  -122,  -647,  -115,  -647,  -112,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,     4,   737,  -105,   336,   -90,
     -69,    23,   -53,   380,   -36,   -31,   -21,  -647,   -97,  -160,
     -17,    48,    52,   580,   424,    56,    45,    64,    26,    66,
     -52,    73,    74,    81,    20,  -647,  -647,  -647,  -647,  -647,
      83,    84,    85,    95,    96,   101,   102,   103,   106,   113,
     115,   121,   123,   124,   130,   135,   126,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   661,  -647,   136,   138,   139,   140,
     142,   147,    55,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
     581,    17,  -647,   148,    27,  -647,  -647,     9,  -647,   151,
     152,   159,   160,   165,   168,   170,   176,   182,   187,   189,
     191,   192,   193,   198,   199,   200,   202,   203,   207,   220,
     223,   224,   225,   226,   227,   233,   236,   238,   239,   242,
     247,   248,   250,   251,   256,   257,   258,   259,    46,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   272,
      12,   333,   -76,   255,   262,    13,   324,   254,  -647,   266,
     268,   269,   274,   275,   276,   277,   278,    16,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   283,   284,   286,
     287,   289,   295,   296,   301,   302,   303,   305,   309,   253,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,    94,   285,   310,    10,  -647,  -647,  -647,    97,
     264,  -647,   311,    42,  -647,  -647,    11,  -647,    99,   185,
     317,   316,  -647,   149,  -131,   188,   319,  -131,  -131,  -131,
     320,  -131,  -131,   329,   330,   331,   334,   335,   337,   332,
    -647,   338,   339,   340,  -647,   341,   342,   345,   347,   348,
     349,   350,   351,   352,   353,   354,   156,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,   358,   361,   360,   363,   343,   366,   364,  -647,
     367,   368,   374,   375,   376,   378,   379,  -647,   381,   382,
     383,   384,   385,   387,   388,   389,   163,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   390,   392,    18,  -647,  -647,  -647,
     398,   399,  -647,  -647,   396,   400,    22,  -647,  -647,  -647,
    -131,   401,  -131,  -131,   404,  -131,   362,   405,   411,   413,
    -131,   427,  -131,   415,   422,   430,   432,   433,   434,  -131,
     435,   436,   438,   419,   462,  -131,  -131,   465,  -131,   467,
     446,   469,   471,   452,  -131,  -131,  -131,   476,   455,   457,
    -647,   460,   453,   459,  -647,   463,   466,   472,   180,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   473,   475,    29,
    -647,  -647,  -647,   464,   479,   482,  -647,   483,  -647,    32,
    -647,  -647,  -647,  -647,  -647,  -647,   474,  -647,  -647,  -647,
     486,   488,   491,    25,  -647,  -647,  -647,   494,   493,   495,
    -647,   498,   500,   502,   503,   505,   507,   510,   195,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
     514,   516,   517,   520,    50,  -647,  -647,  -647,  -647,   490,
     511,  -131,   529,   550,   535,   557,   558,   536,  -647,  -647,
     540,   543,   566,   553,   547,   555,   561,   562,   565,   567,
     569,   554,  -647,   573,   572,  -647,   128,  -647,  -647,  -647,
    -647,   578,   575,  -647,   571,   577,   579,   582,   583,   585,
     119,  -647,  -647,  -647,  -647,  -647,   570,   588,  -647,   589,
     592,  -647,   593,    58,  -647,  -647,  -647,  -647,   596,   597,
     599,  -647,   600,  -108,  -108,   601,  -129,  -647,   603,   604,
     608,   609,   610,   611,   612,   618,   621,   622,   624,   626,
     628,   629,  -647,  -647,   584,   631,   630,   632,  -131,   635,
    -131,   638,   639,   640,   642,  -131,   -26,   -26,   637,  -647,
     643,   644,   645,   646,   647,   648,  -647,  -647,   652,    21,
     653,   602,   654,   655,   651,   657,   658,   659,  -131,   660,
     662,  -131,   663,   656,  -647,   664,   665,   666,  -647,   667,
    -647,   668,   671,   669,  -647,   670,   672,   673,   674,   676,
     677,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,  -647,  -647,   714,   605,   711,   715,
     717,   718,   716,  -647,   720,   721,   719,  -647,  -647,   723,
     724,   722,   659,   725,  -647,   -76,  -647,   726,   729,   727,
    -647,  -647,   731,   745,   728,   732,   734,   735,   736,   757,
     738,   739,   740,  -647,  -647,   741,   742,   744,   743,  -647,
     746,   747,   748,   749,   750,   751,   752,   753,  -647,   754,
     755,   756,   758,   759,   760,   761,   762,   763,   764,   765,
    -647,  -647,   769,   766,   767,  -647,   770,  -647,   146,  -647,
     772,   774,   775,   776,   777,  -647,   778,  -647,  -647,   779,
     773,   782,   780,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -108,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,   781,   783,   -48,   784,   785,   786,   787,   788,
     789,   790,   791,   792,   417,   417,   793,    68,  -647,   794,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   795,   796,   797,
     798,   799,   800,   801,     1,   802,   803,  -647,   804,   805,
     806,   807,   808,   809,  -647,   810,   811,  -647,  -647,   812,
     813,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,   814,   815,   496,   816,   817,   818,  -647,   819,   820,
    -647,   821,   822,   267,   836,   576,  -647,  -647,  -647,   824,
     825,  -647,   826,   827,   484,   828,   829,   830,   831,   832,
     833,   834,  -647,   835,   837,   838,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,   839,   556,  -647,  -647,
     840,   841,   842,  -647,    90,  -647,  -647,  -647,  -647,   845,
     846,   847,   848,  -647,  -647,   849,   549,   850,  -647,  -647,
    -647,  -647,  -647,  -197,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   417,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -188,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -169,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -144,  -647,   659,   659,   851,
    -647,  -647,  -647,  -647,  -647,   771,  -647,   852,  -647,   853,
     854,  -647,   855,  -647,   856,   857,  -647,  -647,   858,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -119,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,   -99,  -647,  -647,   844,  -151,   860,   863,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   -57,  -647,  -647,
    -647,   -48,  -647,     1,  -647,   496,  -647,   267,  -647,  -647,
    -647,   886,   412,   909,   859,   867,   915,   929,   930,  -647,
     484,  -647,   556,   864,   865,   866,   208,  -647,  -647,   549,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,   868,  -647,  -647
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
    -647,  -647,  -647,  -305,  -647,   280,   291,  -627,  -647,    40,
      54,  -646,  -647,  -647,   888,  -647,  -647,   245,  -647,  -647,
     823,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   874,  -647,  -647,  -647,  -647,  -647,
    -647,   574,  -647,  -647,  -647,  -647,  -647,   512,  -647,  -647,
    -647,  -647,  -647,  -647,   843,  -647,  -647,  -647,  -647,   109,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   586,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,   -86,  -647,  -647,  -647,   768,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,   -71,  -647,  -647,  -647,  -647,  -647,   -72,  -647,
     607,  -647,  -647,  -647,    19,  -647,  -647,  -647,  -647,  -647,
     633,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   -67,  -647,
    -647,  -647,  -647,   587,  -647,  -647,  -647,  -647,  -647,   861,
    -647,  -647,  -647,  -647,   506,  -647,  -647,  -647,  -647,  -647,
     -89,  -647,  -647,  -647,   537,  -647,  -647,  -647,  -647,   -77,
    -647,  -647,  -647,   730,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   -56,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,   627,  -647,  -647,  -647,  -647,
    -647,   712,  -647,  -647,  -647,  -647,   954,  -647,  -647,  -647,
    -647,   713,  -647,  -647,  -647,  -647,   911,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   968,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   995,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,   862,  -647,  -647,  -647,
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
     839,   858,   600,   601,   602,    80,   604,   605,  1024,   991,
     403,   283,   579,   466,   490,    55,  1150,   238,   393,   393,
    1151,    80,    56,   403,   142,  1152,   490,   291,   142,  1153,
     466,    53,    54,   473,    58,  1174,   798,   799,   800,   801,
     802,    81,    61,   291,  1154,    63,   283,   148,  1155,    82,
      67,   520,   149,    69,   150,   151,   125,    81,   239,   579,
     834,   835,   484,   485,   152,    82,   240,   241,   242,  1156,
      73,   243,   244,  1157,   245,   246,   153,   154,   126,   127,
     593,   594,   593,   806,   992,   155,   156,   394,   394,   157,
     158,   970,   474,   143,  1169,   553,    74,   143,  1170,   521,
     491,   128,   475,    76,   476,   665,    78,   667,   668,   159,
     670,   160,   491,   124,  1171,   675,    83,   677,  1172,   232,
     565,   404,   161,   580,   684,   162,   163,    89,   140,   553,
     690,   691,    83,   693,   404,   164,   165,   522,   292,   699,
     700,   701,   405,   166,   167,   467,   168,   970,   169,   141,
     395,   395,   170,   171,   292,   405,  1178,   321,    90,    91,
    1179,   297,   467,   477,   360,   147,   361,    92,   362,   172,
     580,   173,   174,   175,   129,   176,  -129,   322,   323,   492,
     177,   451,   229,   523,  1025,   834,   835,   230,   363,   848,
     849,   492,    93,    94,    95,    96,   497,   231,   130,   178,
     179,   235,   971,   180,   181,   452,   554,    97,    98,    99,
     364,  -129,   581,   284,   131,   582,   468,   100,   101,   102,
     498,   103,   104,   365,   562,   366,   752,   453,   324,   105,
     537,   566,   657,   468,   301,   367,   663,   182,   183,   729,
     554,   401,   499,   716,   184,   185,   723,   368,   284,   325,
     326,   186,   454,   187,   257,   520,   577,   327,   971,   581,
     449,   328,   582,   564,   748,   565,   236,   500,   329,   358,
     237,   972,   792,   451,   282,   369,   330,   331,   332,   834,
    1014,   567,   290,  1197,   296,  1198,   333,   258,   298,   299,
     259,   973,   568,  1060,   370,   555,   300,   452,   303,   304,
     305,   569,  1061,   521,  1129,   371,   334,   501,   455,   588,
     306,   307,   372,   826,   260,   828,   308,   309,   310,   453,
     833,   311,  1062,   502,   373,   497,   261,   972,   312,   555,
     313,   335,  1199,   784,   473,   456,   314,   125,   315,   316,
     319,   522,   774,   859,   454,   317,   862,   973,  1200,   498,
     318,   352,   262,   353,   354,   355,   374,   356,   375,   126,
     127,   592,   357,   400,   263,   264,   410,   411,   265,   266,
     628,   499,  1201,  1202,   412,   413,   566,   653,   598,   503,
     414,   148,   128,   415,   457,   416,   149,   523,   150,   151,
     504,   417,   505,   474,   712,   589,   500,   418,   152,   506,
     455,   507,   419,   475,   420,   476,   421,   422,   423,   742,
     153,   154,  1203,   424,   425,   426,  1204,   427,   428,   155,
     156,  1158,   429,   157,   158,   257,   567,   456,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,   430,   501,   568,   431,   432,
     433,   434,   435,   159,  1063,   160,   569,   267,   436,   268,
    1064,   437,   502,   438,   439,   129,   161,   440,   258,   162,
     163,   259,   441,   442,   477,   443,   444,   551,   488,   164,
     165,   445,   446,   447,   448,   489,   457,   166,   167,   130,
     168,   529,   169,   530,   531,   260,   170,   171,  1074,   532,
     533,   534,   535,   536,  1075,   131,   539,   261,   560,   540,
    1175,   541,   542,   172,   543,   173,   174,   175,   503,   176,
     544,   545,  1076,  1077,   177,  1042,   546,   547,   548,   504,
     549,   505,  1078,   262,   550,   561,   576,   590,   506,   591,
     507,   599,   603,   178,   179,   263,   264,   180,   181,   265,
     266,   606,   607,   608,  1043,   612,   609,   610,  1185,   611,
     632,   613,   671,   634,   614,   615,   617,   618,  1079,  1080,
     619,  1081,   620,   621,   622,   623,   624,   625,   626,   627,
     630,   182,   183,   631,  1044,   633,   635,   636,   184,   185,
     637,   238,   360,   638,   361,   186,   362,   187,  1082,   639,
     640,   641,  1083,   642,   643,   672,   645,   646,   647,   648,
     649,  1084,   650,   651,   652,   655,   363,   656,   659,  1045,
    1046,   661,   660,   666,  1047,   662,   669,   676,   267,  1085,
     268,  1086,   239,   673,  1087,   674,  1136,   678,   364,   688,
     240,   241,   242,  1113,   679,   243,   244,  1048,   245,   246,
    1088,   365,   680,   366,   681,   682,   683,   685,   686,  1089,
     687,  1090,   689,   367,  1091,   692,  1092,   694,   695,   696,
    1093,   697,   321,  1094,   698,   368,   702,   703,   706,  1095,
     704,  1096,  1097,   705,   707,     2,     3,   718,   709,     4,
     750,   710,   322,   323,  1137,  1049,  1098,   711,   714,  1138,
     715,   725,  1099,   369,   719,     5,  1114,   720,   722,   726,
       6,   751,     7,   727,     8,  1050,   728,   731,   732,  1139,
     733,     9,   370,   735,  1140,   736,  1115,   737,   738,  1141,
     739,  1116,   740,   371,    10,   741,  1117,   744,    11,    12,
     372,   745,   746,   324,  1142,   747,  1143,  1144,    89,   753,
     754,  1118,   373,  1119,  1120,   755,    13,   756,   757,   758,
      14,  1145,   759,   760,   325,   326,   761,  1146,  1121,   763,
      15,    16,   327,   762,  1122,   764,   328,   770,   776,    90,
      91,   765,   766,   329,   374,   767,   375,   768,    92,   769,
     786,   330,   331,   332,    17,    18,   771,   772,   777,   778,
     779,   333,   851,  1068,   780,   912,   822,   781,   782,    19,
     783,   787,   788,    93,    94,    95,    96,   789,   791,   794,
     795,   334,   796,   797,   805,    20,   808,   809,    97,    98,
      99,   810,   811,   812,   813,   814,    21,    22,   100,   101,
     102,   815,   103,   104,   816,   817,   335,   818,    23,   819,
     105,   820,   821,   823,   825,   824,    24,   827,   829,    25,
     840,   830,   831,    26,   832,    27,   841,   842,   843,   844,
     845,   846,   847,   850,   852,   853,   854,   855,   856,   864,
     860,   857,   861,   863,   865,   866,   807,  1015,   869,   867,
     868,   870,   871,   872,   803,   873,   874,   875,  1011,   876,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
     887,   888,   889,   890,   891,   892,   893,   894,   895,   896,
     897,   898,   899,   900,   901,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   911,   914,   913,   915,   916,   917,
     918,   919,   920,   921,   922,   933,   929,   923,   927,   930,
     931,   932,   935,   934,   936,   937,   938,   939,   940,   941,
    1184,   943,   944,   942,   945,  1188,   946,   234,   302,   947,
     948,   949,   950,   951,   952,   953,   954,   955,   956,   957,
     928,   958,   959,   960,   961,   962,   963,   964,   965,   966,
     968,   967,   979,   969,   980,   981,   982,  1161,   986,   985,
     983,   984,   987,   988,   989,  1187,   990,   995,   996,   997,
     998,   999,  1000,  1001,  1002,  1003,  1013,  1016,  1017,  1018,
    1019,  1020,  1021,  1022,  1023,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1053,
    1054,  1055,  1056,  1057,  1058,  1059,  1067,  1070,  1071,  1072,
    1073,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1186,
    1110,  1111,  1112,  1125,  1173,  1189,  1126,  1127,  1131,  1132,
    1133,  1134,  1135,  1149,  1160,  1190,  1191,   730,  1162,  1163,
    1164,  1165,  1166,  1167,  1168,  1176,  1177,  1194,  1195,  1196,
    1180,  1207,   785,  1130,  1192,  1183,   724,  1159,  1182,   793,
    1206,   713,   552,   775,   743,  1193,   717,  1181,   402,   450,
     359,   320,     0,     0,   629,     0,   654,     0,   658,   538,
       0,   749,     0,     0,     0,     0,     0,     0,     0,   664,
       0,     0,     0,     0,     0,     0,     0,     0,   563,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   578
};

static const yytype_int16 yycheck[] =
{
     627,   647,   307,   308,   309,     1,   311,   312,     7,    57,
       1,     1,     1,     1,     1,   218,   213,     1,     1,     1,
     217,     1,   218,     1,     1,   213,     1,     1,     1,   217,
       1,   213,   214,     1,   218,   186,   144,   145,   146,   147,
     148,    37,   218,     1,   213,   218,     1,     1,   217,    45,
     210,     1,     6,   215,     8,     9,     1,    37,    42,     1,
     211,   212,   138,   139,    18,    45,    50,    51,    52,   213,
     218,    55,    56,   217,    58,    59,    30,    31,    23,    24,
     211,   212,   211,   212,   132,    39,    40,    70,    70,    43,
      44,     1,    60,    70,   213,     1,   218,    70,   217,    49,
      87,    46,    70,   218,    72,   410,   218,   412,   413,    63,
     415,    65,    87,   218,   213,   420,   112,   422,   217,   216,
       1,   112,    76,   112,   429,    79,    80,     1,   218,     1,
     435,   436,   112,   438,   112,    89,    90,    87,   112,   444,
     445,   446,   133,    97,    98,   133,   100,     1,   102,   218,
     133,   133,   106,   107,   112,   133,   213,     1,    32,    33,
     217,   213,   133,   131,     1,   218,     3,    41,     5,   123,
     112,   125,   126,   127,   119,   129,   166,    21,    22,   166,
     134,     1,   218,   133,   183,   211,   212,   218,    25,   168,
     169,   166,    66,    67,    68,    69,     1,   218,   143,   153,
     154,   218,   112,   157,   158,    25,   112,    81,    82,    83,
      47,   166,   201,   203,   159,   204,   204,    91,    92,    93,
      25,    95,    96,    60,   214,    62,   531,    47,    72,   103,
     214,   112,   214,   204,   214,    72,   214,   191,   192,   214,
     112,   214,    47,   214,   198,   199,   214,    84,   203,    93,
      94,   205,    72,   207,     1,     1,   214,   101,   112,   201,
     214,   105,   204,   166,   214,     1,   218,    72,   112,   214,
     218,   181,   214,     1,   218,   112,   120,   121,   122,   211,
     212,   162,   218,    75,   218,    77,   130,    34,   215,   215,
      37,   201,   173,    26,   131,   201,   215,    25,   215,   215,
     215,   182,    35,    49,   214,   142,   150,   112,   128,   210,
     215,   215,   149,   618,    61,   620,   215,   215,   215,    47,
     625,   215,    55,   128,   161,     1,    73,   181,   215,   201,
     215,   175,   124,   214,     1,   155,   215,     1,   215,   215,
     214,    87,   214,   648,    72,   215,   651,   201,   140,    25,
     215,   215,    99,   215,   215,   215,   193,   215,   195,    23,
      24,   212,   215,   215,   111,   112,   215,   215,   115,   116,
     214,    47,   164,   165,   215,   215,   112,   214,   190,   184,
     215,     1,    46,   215,   204,   215,     6,   133,     8,     9,
     195,   215,   197,    60,   214,   210,    72,   215,    18,   204,
     128,   206,   215,    70,   215,    72,   215,   215,   215,   214,
      30,    31,   204,   215,   215,   215,   208,   215,   215,    39,
      40,  1067,   215,    43,    44,     1,   162,   155,    11,    12,
      13,    14,    15,    16,    17,   215,   112,   173,   215,   215,
     215,   215,   215,    63,   177,    65,   182,   194,   215,   196,
     183,   215,   128,   215,   215,   119,    76,   215,    34,    79,
      80,    37,   215,   215,   131,   215,   215,   214,   213,    89,
      90,   215,   215,   215,   215,   213,   204,    97,    98,   143,
     100,   215,   102,   215,   215,    61,   106,   107,     4,   215,
     215,   215,   215,   215,    10,   159,   213,    73,   213,   215,
    1127,   215,   215,   123,   215,   125,   126,   127,   184,   129,
     215,   215,    28,    29,   134,    19,   215,   215,   215,   195,
     215,   197,    38,    99,   215,   215,   215,   210,   204,   213,
     206,   212,   212,   153,   154,   111,   112,   157,   158,   115,
     116,   212,   212,   212,    48,   213,   212,   212,   136,   212,
     190,   213,   190,   210,   215,   215,   215,   215,    74,    75,
     215,    77,   215,   215,   215,   215,   215,   215,   215,   215,
     212,   191,   192,   212,    78,   212,   210,   213,   198,   199,
     213,     1,     1,   215,     3,   205,     5,   207,   104,   215,
     215,   215,   108,   215,   215,   190,   215,   215,   215,   215,
     215,   117,   215,   215,   215,   215,    25,   215,   210,   113,
     114,   215,   213,   212,   118,   215,   212,   190,   194,   135,
     196,   137,    42,   212,   140,   212,    77,   212,    47,   210,
      50,    51,    52,    77,   212,    55,    56,   141,    58,    59,
     156,    60,   212,    62,   212,   212,   212,   212,   212,   165,
     212,   167,   190,    72,   170,   190,   172,   190,   212,   190,
     176,   190,     1,   179,   212,    84,   190,   212,   215,   185,
     213,   187,   188,   213,   215,     0,     1,   213,   215,     4,
     190,   215,    21,    22,   135,   189,   202,   215,   215,   140,
     215,   217,   208,   112,   215,    20,   140,   215,   215,   213,
      25,   190,    27,   215,    29,   209,   215,   213,   215,   160,
     215,    36,   131,   215,   165,   215,   160,   215,   215,   170,
     215,   165,   215,   142,    49,   215,   170,   213,    53,    54,
     149,   215,   215,    72,   185,   215,   187,   188,     1,   210,
     190,   185,   161,   187,   188,   210,    71,   190,   190,   213,
      75,   202,   212,   210,    93,    94,   190,   208,   202,   212,
      85,    86,   101,   210,   208,   210,   105,   213,   190,    32,
      33,   210,   210,   112,   193,   210,   195,   210,    41,   210,
     210,   120,   121,   122,   109,   110,   213,   215,   213,   218,
     213,   130,   190,   217,   215,   190,   212,   215,   215,   124,
     215,   213,   213,    66,    67,    68,    69,   215,   215,   213,
     213,   150,   213,   213,   213,   140,   213,   213,    81,    82,
      83,   213,   213,   213,   213,   213,   151,   152,    91,    92,
      93,   213,    95,    96,   213,   213,   175,   213,   163,   213,
     103,   213,   213,   212,   212,   215,   171,   212,   210,   174,
     213,   212,   212,   178,   212,   180,   213,   213,   213,   213,
     213,   213,   210,   210,   210,   210,   215,   210,   210,   213,
     210,   212,   210,   210,   210,   210,   596,   837,   210,   213,
     213,   210,   213,   213,   593,   213,   213,   213,   834,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   210,   210,   215,   210,   210,   213,
     210,   210,   213,   210,   210,   190,   210,   215,   213,   210,
     213,   210,   210,   215,   210,   210,   210,   190,   210,   210,
      64,   210,   210,   213,   210,    88,   213,    69,    84,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     725,   213,   213,   213,   213,   213,   213,   213,   213,   210,
     213,   215,   210,   213,   210,   210,   210,   216,   215,   210,
     213,   213,   210,   213,   213,   136,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   200,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   140,
     213,   213,   213,   213,   210,   140,   215,   215,   213,   213,
     213,   213,   213,   213,   213,   136,   136,   493,   216,   216,
     216,   216,   216,   216,   216,   215,   213,   213,   213,   213,
    1151,   213,   570,   974,  1170,  1157,   479,  1068,  1155,   583,
    1179,   458,   269,   556,   508,  1172,   469,  1153,   144,   188,
     132,   106,    -1,    -1,   336,    -1,   376,    -1,   396,   247,
      -1,   524,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   293
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   220,     0,     1,     4,    20,    25,    27,    29,    36,
      49,    53,    54,    71,    75,    85,    86,   109,   110,   124,
     140,   151,   152,   163,   171,   174,   178,   180,   221,   231,
     232,   237,   251,   257,   263,   271,   284,   301,   322,   336,
     349,   356,   360,   370,   379,   401,   407,   413,   417,   423,
     465,   474,   493,   213,   214,   218,   218,   302,   218,   380,
     408,   218,   418,   218,   337,   402,   323,   210,   233,   215,
     258,   285,   350,   218,   218,   371,   218,   264,   218,   361,
       1,    37,    45,   112,   252,   253,   254,   255,   256,     1,
      32,    33,    41,    66,    67,    68,    69,    81,    82,    83,
      91,    92,    93,    95,    96,   103,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   218,     1,    23,    24,    46,   119,
     143,   159,   466,   467,   468,   469,   470,   471,   472,   473,
     218,   218,     1,    70,   414,   415,   416,   218,     1,     6,
       8,     9,    18,    30,    31,    39,    40,    43,    44,    63,
      65,    76,    79,    80,    89,    90,    97,    98,   100,   102,
     106,   107,   123,   125,   126,   127,   129,   134,   153,   154,
     157,   158,   191,   192,   198,   199,   205,   207,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   218,
     218,   218,   216,   234,   233,   218,   218,   218,     1,    42,
      50,    51,    52,    55,    56,    58,    59,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,     1,    34,    37,
      61,    73,    99,   111,   112,   115,   116,   194,   196,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   218,     1,   203,   272,   273,   274,   275,   276,
     218,     1,   112,   357,   358,   359,   218,   213,   215,   215,
     215,   214,   253,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   214,
     476,     1,    21,    22,    72,    93,    94,   101,   105,   112,
     120,   121,   122,   130,   150,   175,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   215,   215,   215,   215,   215,   215,   214,   467,
       1,     3,     5,    25,    47,    60,    62,    72,    84,   112,
     131,   142,   149,   161,   193,   195,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   397,
     398,   399,   400,     1,    70,   133,   409,   410,   411,   412,
     215,   214,   415,     1,   112,   133,   419,   420,   421,   422,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   214,
     425,     1,    25,    47,    72,   128,   155,   204,   338,   339,
     340,   341,   342,   343,   344,   348,     1,   133,   204,   403,
     404,   405,   406,     1,    60,    70,    72,   131,   324,   328,
     329,   330,   334,   335,   138,   139,   235,   236,   213,   213,
       1,    87,   166,   259,   260,   261,   262,     1,    25,    47,
      72,   112,   128,   184,   195,   197,   204,   206,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
       1,    49,    87,   133,   351,   352,   353,   354,   355,   215,
     215,   215,   215,   215,   215,   215,   215,   214,   495,   213,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   214,   239,     1,   112,   201,   372,   373,   374,   375,
     213,   215,   214,   273,   166,     1,   112,   162,   173,   182,
     265,   266,   267,   268,   269,   270,   215,   214,   358,     1,
     112,   201,   204,   362,   363,   364,   365,   366,   210,   210,
     210,   213,   212,   211,   212,   222,   223,   224,   190,   212,
     222,   222,   222,   212,   222,   222,   212,   212,   212,   212,
     212,   212,   213,   213,   215,   215,   319,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   214,   304,
     212,   212,   190,   212,   210,   210,   213,   213,   215,   215,
     215,   215,   215,   215,   394,   215,   215,   215,   215,   215,
     215,   215,   215,   214,   382,   215,   215,   214,   410,   210,
     213,   215,   215,   214,   420,   222,   212,   222,   222,   212,
     222,   190,   190,   212,   212,   222,   190,   222,   212,   212,
     212,   212,   212,   212,   222,   212,   212,   212,   210,   190,
     222,   222,   190,   222,   190,   212,   190,   190,   212,   222,
     222,   222,   190,   212,   213,   213,   215,   215,   345,   215,
     215,   215,   214,   339,   215,   215,   214,   404,   213,   215,
     215,   325,   215,   214,   329,   217,   213,   215,   215,   214,
     260,   213,   215,   215,   298,   215,   215,   215,   215,   215,
     215,   215,   214,   287,   213,   215,   215,   215,   214,   352,
     190,   190,   222,   210,   190,   210,   190,   190,   213,   212,
     210,   190,   210,   212,   210,   210,   210,   210,   210,   210,
     213,   213,   215,   376,   214,   373,   190,   213,   218,   213,
     215,   215,   215,   215,   214,   266,   210,   213,   213,   215,
     367,   215,   214,   363,   213,   213,   213,   213,   144,   145,
     146,   147,   148,   225,   225,   213,   212,   224,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   212,   212,   215,   212,   222,   212,   222,   210,
     212,   212,   212,   222,   211,   212,   226,   227,   228,   226,
     213,   213,   213,   213,   213,   213,   213,   210,   168,   169,
     210,   190,   210,   210,   215,   210,   210,   212,   230,   222,
     210,   210,   222,   210,   213,   210,   210,   213,   213,   210,
     210,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   210,   190,   215,   210,   210,   210,   213,   210,   210,
     213,   210,   210,   215,   230,   332,   333,   213,   236,   210,
     210,   213,   210,   190,   215,   210,   210,   210,   210,   190,
     210,   210,   213,   210,   210,   210,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   210,   215,   213,   213,
       1,   112,   181,   201,   277,   278,   279,   280,   281,   210,
     210,   210,   210,   213,   213,   210,   215,   210,   213,   213,
     213,    57,   132,   320,   321,   213,   213,   213,   213,   213,
     213,   213,   213,   213,    11,    12,    13,    14,    15,    16,
      17,   229,   229,   213,   212,   228,   213,   213,   213,   213,
     213,   213,   213,   213,     7,   183,   395,   396,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,    19,    48,    78,   113,   114,   118,   141,   189,
     209,   346,   347,   213,   213,   213,   213,   213,   213,   213,
      26,    35,    55,   177,   183,   326,   327,   200,   217,   331,
     213,   213,   213,   213,     4,    10,    28,    29,    38,    74,
      75,    77,   104,   108,   117,   135,   137,   140,   156,   165,
     167,   170,   172,   176,   179,   185,   187,   188,   202,   208,
     299,   300,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,    77,   140,   160,   165,   170,   185,   187,
     188,   202,   208,   377,   378,   213,   215,   215,   282,   214,
     278,   213,   213,   213,   213,   213,    77,   135,   140,   160,
     165,   170,   185,   187,   188,   202,   208,   368,   369,   213,
     213,   217,   213,   217,   213,   217,   213,   217,   230,   333,
     213,   216,   216,   216,   216,   216,   216,   216,   216,   213,
     217,   213,   217,   210,   186,   226,   215,   213,   213,   217,
     321,   396,   347,   327,    64,   136,   140,   136,    88,   140,
     136,   136,   300,   378,   213,   213,   213,    75,    77,   124,
     140,   164,   165,   204,   208,   283,   369,   213
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   219,   220,   220,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     222,   222,   223,   223,   224,   224,   225,   225,   225,   225,
     225,   226,   226,   227,   227,   228,   228,   229,   229,   229,
     229,   229,   229,   229,   230,   231,   232,   233,   234,   234,
     235,   235,   236,   236,   237,   238,   238,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   252,   253,   253,   253,   253,   254,   255,   256,
     258,   257,   259,   259,   260,   260,   260,   261,   262,   264,
     263,   265,   265,   266,   266,   266,   266,   266,   267,   268,
     269,   270,   271,   272,   272,   273,   273,   273,   274,   276,
     275,   277,   277,   278,   278,   278,   278,   279,   280,   280,
     282,   281,   283,   283,   283,   283,   283,   283,   283,   283,
     285,   284,   286,   286,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   298,   297,   299,   299,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   302,   301,
     303,   303,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     319,   318,   320,   320,   321,   321,   323,   322,   325,   324,
     326,   326,   327,   327,   327,   327,   327,   328,   328,   329,
     329,   329,   329,   329,   331,   330,   332,   332,   333,   333,
     334,   335,   337,   336,   338,   338,   339,   339,   339,   339,
     339,   339,   339,   340,   341,   342,   343,   345,   344,   346,
     346,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     348,   350,   349,   351,   351,   352,   352,   352,   352,   353,
     354,   355,   356,   357,   357,   358,   358,   359,   361,   360,
     362,   362,   363,   363,   363,   363,   364,   365,   367,   366,
     368,   368,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   371,   370,   372,   372,   373,   373,   373,
     374,   376,   375,   377,   377,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   380,   379,   381,   381,   382,
     382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   392,   394,   393,   395,   395,
     396,   396,   397,   398,   399,   400,   402,   401,   403,   403,
     404,   404,   404,   405,   406,   408,   407,   409,   409,   410,
     410,   410,   411,   412,   413,   414,   414,   415,   415,   416,
     418,   417,   419,   419,   420,   420,   420,   421,   422,   423,
     424,   424,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   466,   467,   467,   467,   467,   467,   467,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   475,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   494,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   496,   497,   498,   499,   500,
     501,   502,   503
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
#line 405 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3188 "conf_parser.c"
        break;

    case YYSYMBOL_module_string: /* module_string  */
#line 405 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3194 "conf_parser.c"
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
#line 442 "conf_parser.y"
{
  if ((yyvsp[0].number) != 0)
  {
    yyerror("Nonzero durations require a unit");
    YYERROR;
  }

  (yyval.number) = 0;
}
#line 3475 "conf_parser.c"
    break;

  case 33: /* time_components: time_components time_component  */
#line 453 "conf_parser.y"
{
  if (!_conf_parser_quantity_add((yyvsp[-1].number), (yyvsp[0].number), 1U, &(yyval.number)))
  {
    yyerror("Duration out of range");
    YYERROR;
  }
}
#line 3487 "conf_parser.c"
    break;

  case 34: /* time_component: NUMBER time_unit  */
#line 462 "conf_parser.y"
{
  if (!_conf_parser_quantity_add(0, (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Duration out of range");
    YYERROR;
  }
}
#line 3499 "conf_parser.c"
    break;

  case 35: /* time_component: DECIMAL time_unit  */
#line 469 "conf_parser.y"
{
  const enum conf_quantity_status status = _conf_parser_quantity_from_decimal((yyvsp[-1].string), (yyvsp[0].number), &(yyval.number));
  io_free((yyvsp[-1].string));

  if (status != CONF_QUANTITY_OK)
  {
    yyerror(status == CONF_QUANTITY_INEXACT ? "Duration component must resolve to whole seconds" : "Duration out of range");
    YYERROR;
  }
}
#line 3514 "conf_parser.c"
    break;

  case 36: /* time_unit: SECONDS  */
#line 480 "conf_parser.y"
                   { (yyval.number) = 1U; }
#line 3520 "conf_parser.c"
    break;

  case 37: /* time_unit: MINUTES  */
#line 481 "conf_parser.y"
                   { (yyval.number) = 60U; }
#line 3526 "conf_parser.c"
    break;

  case 38: /* time_unit: HOURS  */
#line 482 "conf_parser.y"
                   { (yyval.number) = 60U * 60U; }
#line 3532 "conf_parser.c"
    break;

  case 39: /* time_unit: DAYS  */
#line 483 "conf_parser.y"
                   { (yyval.number) = 60U * 60U * 24U; }
#line 3538 "conf_parser.c"
    break;

  case 40: /* time_unit: WEEKS  */
#line 484 "conf_parser.y"
                   { (yyval.number) = 60U * 60U * 24U * 7U; }
#line 3544 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER  */
#line 488 "conf_parser.y"
{
  if ((yyvsp[0].number) != 0)
  {
    yyerror("Nonzero sizes require a unit");
    YYERROR;
  }

  (yyval.number) = 0;
}
#line 3558 "conf_parser.c"
    break;

  case 44: /* size_components: size_components size_component  */
#line 499 "conf_parser.y"
{
  if (!_conf_parser_quantity_add((yyvsp[-1].number), (yyvsp[0].number), 1U, &(yyval.number)))
  {
    yyerror("Size out of range");
    YYERROR;
  }
}
#line 3570 "conf_parser.c"
    break;

  case 45: /* size_component: NUMBER size_unit  */
#line 508 "conf_parser.y"
{
  if (!_conf_parser_quantity_add(0, (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Size out of range");
    YYERROR;
  }
}
#line 3582 "conf_parser.c"
    break;

  case 46: /* size_component: DECIMAL size_unit  */
#line 515 "conf_parser.y"
{
  const enum conf_quantity_status status = _conf_parser_quantity_from_decimal((yyvsp[-1].string), (yyvsp[0].number), &(yyval.number));
  io_free((yyvsp[-1].string));

  if (status != CONF_QUANTITY_OK)
  {
    yyerror(status == CONF_QUANTITY_INEXACT ? "Size component must resolve to whole bytes" : "Size out of range");
    YYERROR;
  }
}
#line 3597 "conf_parser.c"
    break;

  case 47: /* size_unit: BYTES  */
#line 526 "conf_parser.y"
                   { (yyval.number) = 1U; }
#line 3603 "conf_parser.c"
    break;

  case 48: /* size_unit: KBYTES  */
#line 527 "conf_parser.y"
                   { (yyval.number) = 1000U; }
#line 3609 "conf_parser.c"
    break;

  case 49: /* size_unit: KIBYTES  */
#line 528 "conf_parser.y"
                   { (yyval.number) = 1024U; }
#line 3615 "conf_parser.c"
    break;

  case 50: /* size_unit: MBYTES  */
#line 529 "conf_parser.y"
                   { (yyval.number) = 1000U * 1000U; }
#line 3621 "conf_parser.c"
    break;

  case 51: /* size_unit: MIBYTES  */
#line 530 "conf_parser.y"
                   { (yyval.number) = 1024U * 1024U; }
#line 3627 "conf_parser.c"
    break;

  case 52: /* size_unit: GBYTES  */
#line 531 "conf_parser.y"
                   { (yyval.number) = 1000U * 1000U * 1000U; }
#line 3633 "conf_parser.c"
    break;

  case 53: /* size_unit: GIBYTES  */
#line 532 "conf_parser.y"
                   { (yyval.number) = 1024U * 1024U * 1024U; }
#line 3639 "conf_parser.c"
    break;

  case 54: /* port_number: NUMBER  */
#line 536 "conf_parser.y"
{
  if ((yyvsp[0].number) > UINT16_MAX)
  {
    yyerror("Port out of range");
    YYERROR;
  }

  (yyval.number) = (yyvsp[0].number);
}
#line 3653 "conf_parser.c"
    break;

  case 55: /* module_base_path_entry: MODULE_BASE_PATH '=' module_string ';'  */
#line 551 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct module_error_info error;
    if (module_config_set_base_path(conf_parser_ctx.module_config, (yyvsp[-1].string), &error) != MODULE_SUCCESS)
      conf_report_module_error(error.message);
  }
  io_free((yyvsp[-1].string));
}
#line 3667 "conf_parser.c"
    break;

  case 56: /* loadmodule_entry: LOADMODULE module_string module_attributes ';'  */
#line 566 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct module_error_info error;
    if (module_config_add(conf_parser_ctx.module_config, (yyvsp[-2].string), (module_flags_t)(yyvsp[-1].number), &error) != MODULE_SUCCESS)
      conf_report_module_error(error.message);
  }
  io_free((yyvsp[-2].string));
}
#line 3681 "conf_parser.c"
    break;

  case 57: /* module_string: QSTRING  */
#line 578 "conf_parser.y"
{
  (yyval.string) = io_strdup((yyvsp[0].string));
}
#line 3689 "conf_parser.c"
    break;

  case 58: /* module_attributes: %empty  */
#line 583 "conf_parser.y"
{
  (yyval.number) = 0;
}
#line 3697 "conf_parser.c"
    break;

  case 59: /* module_attributes: ':' module_attributes_items  */
#line 586 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3705 "conf_parser.c"
    break;

  case 60: /* module_attributes_items: module_attributes_items ',' module_attributes_item  */
#line 591 "conf_parser.y"
{
  (yyval.number) = (yyvsp[-2].number) | (yyvsp[0].number);
}
#line 3713 "conf_parser.c"
    break;

  case 61: /* module_attributes_items: module_attributes_item  */
#line 594 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3721 "conf_parser.c"
    break;

  case 62: /* module_attributes_item: RESIDENT  */
#line 599 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_DEACTIVATE;
}
#line 3729 "conf_parser.c"
    break;

  case 63: /* module_attributes_item: REQUIRED  */
#line 602 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_REMOVE;
}
#line 3737 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 628 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3749 "conf_parser.c"
    break;

  case 80: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 637 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3761 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 646 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2 || ConfigServerInfo.name)
    break;

  if (!server_is_valid_name((yyvsp[-1].string)))
  {
    conf_report_error("Invalid serverinfo::name");
    YYABORT;
  }

  ConfigServerInfo.name = io_strdup((yyvsp[-1].string));
}
#line 3778 "conf_parser.c"
    break;

  case 82: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 660 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2 || ConfigServerInfo.sid)
    break;

  if (!client_id_is_valid_sid((yyvsp[-1].string)))
  {
    conf_report_error("Invalid serverinfo::sid");
    YYABORT;
  }

  ConfigServerInfo.sid = io_strdup((yyvsp[-1].string));
}
#line 3795 "conf_parser.c"
    break;

  case 83: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 674 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3808 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 684 "conf_parser.y"
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
#line 3825 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 698 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3837 "conf_parser.c"
    break;

  case 86: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 707 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 1)
  {
    conf_report_warning("default_max_clients too low, setting to 1");
    ConfigServerInfo.default_max_clients = 1;
  }
  else if ((yyvsp[-1].number) > (unsigned int)MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "default_max_clients too high, setting to %d", MAXCLIENTS_MAX);
    conf_report_warning(buf);

    ConfigServerInfo.default_max_clients = (unsigned int)MAXCLIENTS_MAX;
  }
  else
    ConfigServerInfo.default_max_clients = (yyvsp[-1].number);
}
#line 3863 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 730 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 9)
  {
    conf_report_warning("max_nick_length too low, setting to 9");
    ConfigServerInfo.max_nick_length = 9;
  }
  else if ((yyvsp[-1].number) > NICKLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
    conf_report_warning(buf);

    ConfigServerInfo.max_nick_length = NICKLEN;
  }
  else
    ConfigServerInfo.max_nick_length = (yyvsp[-1].number);
}
#line 3889 "conf_parser.c"
    break;

  case 88: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 753 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3901 "conf_parser.c"
    break;

  case 89: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 762 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = (yyvsp[-1].boolean);
}
#line 3910 "conf_parser.c"
    break;

  case 97: /* admin_name: NAME '=' QSTRING ';'  */
#line 780 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3922 "conf_parser.c"
    break;

  case 98: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 789 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3934 "conf_parser.c"
    break;

  case 99: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 798 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3946 "conf_parser.c"
    break;

  case 100: /* $@1: %empty  */
#line 811 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3955 "conf_parser.c"
    break;

  case 101: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 815 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3972 "conf_parser.c"
    break;

  case 107: /* motd_mask: MASK '=' QSTRING ';'  */
#line 832 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3981 "conf_parser.c"
    break;

  case 108: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 838 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3990 "conf_parser.c"
    break;

  case 109: /* $@2: %empty  */
#line 848 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3999 "conf_parser.c"
    break;

  case 110: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 852 "conf_parser.y"
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
#line 4017 "conf_parser.c"
    break;

  case 118: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 870 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 4026 "conf_parser.c"
    break;

  case 119: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 876 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4035 "conf_parser.c"
    break;

  case 120: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 882 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 4044 "conf_parser.c"
    break;

  case 121: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 888 "conf_parser.y"
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
#line 4066 "conf_parser.c"
    break;

  case 128: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 917 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = (yyvsp[-1].boolean);
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 4078 "conf_parser.c"
    break;

  case 129: /* $@3: %empty  */
#line 926 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4087 "conf_parser.c"
    break;

  case 130: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 930 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 4100 "conf_parser.c"
    break;

  case 137: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 946 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 4111 "conf_parser.c"
    break;

  case 138: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 954 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 4119 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 957 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 4127 "conf_parser.c"
    break;

  case 140: /* $@4: %empty  */
#line 962 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 4136 "conf_parser.c"
    break;

  case 142: /* logging_file_type_item: USER  */
#line 968 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4145 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: OPERATOR  */
#line 972 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4154 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: XLINE  */
#line 976 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4163 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: RESV  */
#line 980 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4172 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: T_DLINE  */
#line 984 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4181 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: KLINE  */
#line 988 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4190 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KILL  */
#line 992 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4199 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: T_DEBUG  */
#line 996 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4208 "conf_parser.c"
    break;

  case 150: /* $@5: %empty  */
#line 1006 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4220 "conf_parser.c"
    break;

  case 151: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 1013 "conf_parser.y"
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
#line 4278 "conf_parser.c"
    break;

  case 165: /* oper_name: NAME '=' QSTRING ';'  */
#line 1081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4287 "conf_parser.c"
    break;

  case 166: /* oper_user: USER '=' QSTRING ';'  */
#line 1087 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4296 "conf_parser.c"
    break;

  case 167: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4305 "conf_parser.c"
    break;

  case 168: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4314 "conf_parser.c"
    break;

  case 169: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1105 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].boolean))
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4328 "conf_parser.c"
    break;

  case 170: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1116 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4337 "conf_parser.c"
    break;

  case 171: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1122 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].boolean))
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4351 "conf_parser.c"
    break;

  case 172: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1133 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4360 "conf_parser.c"
    break;

  case 173: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1139 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4369 "conf_parser.c"
    break;

  case 174: /* $@6: %empty  */
#line 1145 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4378 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: KILL ':' REMOTE  */
#line 1152 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4387 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: KILL  */
#line 1156 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4396 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1160 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4405 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: CONNECT  */
#line 1164 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4414 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1168 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4423 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: SQUIT  */
#line 1172 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4432 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: KLINE  */
#line 1176 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4441 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: UNKLINE  */
#line 1180 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4450 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_DLINE  */
#line 1184 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4459 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_UNDLINE  */
#line 1188 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4468 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: XLINE  */
#line 1192 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4477 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_UNXLINE  */
#line 1196 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4486 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: DIE  */
#line 1200 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4495 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_RESTART  */
#line 1204 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4504 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1208 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4513 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REHASH  */
#line 1212 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4522 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: ADMIN  */
#line 1216 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4531 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_GLOBOPS  */
#line 1220 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4540 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_LOCOPS  */
#line 1224 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4549 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: REMOTEBAN  */
#line 1228 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4558 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: T_SET  */
#line 1232 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4567 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: MODULE  */
#line 1236 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4576 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: T_OPME  */
#line 1240 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4585 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: NICK ':' RESV  */
#line 1244 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4594 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: JOIN ':' RESV  */
#line 1248 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4603 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: RESV  */
#line 1252 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4612 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: T_UNRESV  */
#line 1256 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4621 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: CLOSE  */
#line 1260 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4630 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1264 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4639 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: BYPASS ':' INPUT_FLOOD  */
#line 1268 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_BYPASS_INPUT_FLOOD;
}
#line 4648 "conf_parser.c"
    break;

  case 208: /* $@7: %empty  */
#line 1278 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4663 "conf_parser.c"
    break;

  case 209: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1288 "conf_parser.y"
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
#line 4710 "conf_parser.c"
    break;

  case 227: /* class_name: NAME '=' QSTRING ';'  */
#line 1349 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4719 "conf_parser.c"
    break;

  case 228: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1355 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4728 "conf_parser.c"
    break;

  case 229: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1361 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4737 "conf_parser.c"
    break;

  case 230: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1367 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4746 "conf_parser.c"
    break;

  case 231: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1373 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4755 "conf_parser.c"
    break;

  case 232: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1379 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4764 "conf_parser.c"
    break;

  case 233: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1385 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4773 "conf_parser.c"
    break;

  case 234: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1391 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4783 "conf_parser.c"
    break;

  case 235: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1398 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4792 "conf_parser.c"
    break;

  case 236: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1404 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4801 "conf_parser.c"
    break;

  case 237: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1410 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4810 "conf_parser.c"
    break;

  case 238: /* class_min_idle: MIN_IDLE '=' timespec ';'  */
#line 1416 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4822 "conf_parser.c"
    break;

  case 239: /* class_max_idle: MAX_IDLE '=' timespec ';'  */
#line 1425 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4834 "conf_parser.c"
    break;

  case 240: /* $@8: %empty  */
#line 1434 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4843 "conf_parser.c"
    break;

  case 244: /* class_flags_item: RANDOM_IDLE  */
#line 1441 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4852 "conf_parser.c"
    break;

  case 245: /* class_flags_item: HIDE_IDLE_FROM_OPERS  */
#line 1445 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4861 "conf_parser.c"
    break;

  case 246: /* $@9: %empty  */
#line 1455 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4870 "conf_parser.c"
    break;

  case 248: /* $@10: %empty  */
#line 1461 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4878 "conf_parser.c"
    break;

  case 252: /* listen_flags_item: T_TLS  */
#line 1467 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4887 "conf_parser.c"
    break;

  case 253: /* listen_flags_item: HIDDEN  */
#line 1471 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4896 "conf_parser.c"
    break;

  case 254: /* listen_flags_item: T_SERVER  */
#line 1475 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4905 "conf_parser.c"
    break;

  case 255: /* listen_flags_item: CLIENT  */
#line 1479 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4914 "conf_parser.c"
    break;

  case 256: /* listen_flags_item: DEFER  */
#line 1483 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4923 "conf_parser.c"
    break;

  case 264: /* $@11: %empty  */
#line 1491 "conf_parser.y"
                                 { reset_block_state(); }
#line 4929 "conf_parser.c"
    break;

  case 268: /* port_item: port_number  */
#line 1496 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_TLS
    if (block_state.flags.value & LISTENER_TLS)
    {
      conf_report_error("TLS not available - port closed");
      break;
    }
#endif
    listener_add((uint16_t)(yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4947 "conf_parser.c"
    break;

  case 269: /* port_item: port_number TWODOTS port_number  */
#line 1509 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_TLS
    if (block_state.flags.value & LISTENER_TLS)
    {
      conf_report_error("TLS not available - port closed");
      break;
    }
#endif

    for (unsigned int port = (yyvsp[-2].number); port <= (yyvsp[0].number); ++port)
      listener_add((uint16_t)port, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4967 "conf_parser.c"
    break;

  case 270: /* listen_address: IP '=' QSTRING ';'  */
#line 1526 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4976 "conf_parser.c"
    break;

  case 271: /* listen_host: HOST '=' QSTRING ';'  */
#line 1532 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4985 "conf_parser.c"
    break;

  case 272: /* $@12: %empty  */
#line 1542 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4994 "conf_parser.c"
    break;

  case 273: /* auth_entry: IRCD_AUTH $@12 '{' auth_items '}' ';'  */
#line 1546 "conf_parser.y"
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
        conf_report_error("Unable to add auth rule");

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
      conf_report_error("Unable to add auth block");
  }
}
#line 5049 "conf_parser.c"
    break;

  case 283: /* auth_user: USER '=' QSTRING ';'  */
#line 1607 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5058 "conf_parser.c"
    break;

  case 284: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1613 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5067 "conf_parser.c"
    break;

  case 285: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1619 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5076 "conf_parser.c"
    break;

  case 286: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1625 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].boolean))
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5090 "conf_parser.c"
    break;

  case 287: /* $@13: %empty  */
#line 1636 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 5099 "conf_parser.c"
    break;

  case 291: /* auth_flags_item: EXCEED_LIMIT  */
#line 1644 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 5108 "conf_parser.c"
    break;

  case 292: /* auth_flags_item: KLINE_EXEMPT  */
#line 1648 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 5117 "conf_parser.c"
    break;

  case 293: /* auth_flags_item: XLINE_EXEMPT  */
#line 1652 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 5126 "conf_parser.c"
    break;

  case 294: /* auth_flags_item: NEED_IDENT  */
#line 1656 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 5135 "conf_parser.c"
    break;

  case 295: /* auth_flags_item: CAN_FLOOD  */
#line 1660 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 5144 "conf_parser.c"
    break;

  case 296: /* auth_flags_item: NO_TILDE  */
#line 1664 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 5153 "conf_parser.c"
    break;

  case 297: /* auth_flags_item: RESV_EXEMPT  */
#line 1668 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 5162 "conf_parser.c"
    break;

  case 298: /* auth_flags_item: T_WEBIRC  */
#line 1672 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5171 "conf_parser.c"
    break;

  case 299: /* auth_flags_item: NEED_PASSWORD  */
#line 1676 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5180 "conf_parser.c"
    break;

  case 300: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1682 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    conf_report_warning("Invalid auth::spoof; ignoring value");
}
#line 5194 "conf_parser.c"
    break;

  case 301: /* $@14: %empty  */
#line 1696 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5206 "conf_parser.c"
    break;

  case 302: /* resv_entry: RESV $@14 '{' resv_items '}' ';'  */
#line 1703 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5217 "conf_parser.c"
    break;

  case 309: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1714 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5226 "conf_parser.c"
    break;

  case 310: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1720 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5235 "conf_parser.c"
    break;

  case 311: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1726 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5244 "conf_parser.c"
    break;

  case 317: /* service_name: NAME '=' QSTRING ';'  */
#line 1741 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5259 "conf_parser.c"
    break;

  case 318: /* $@15: %empty  */
#line 1757 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5275 "conf_parser.c"
    break;

  case 319: /* shared_entry: T_SHARED $@15 '{' shared_items '}' ';'  */
#line 1768 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5290 "conf_parser.c"
    break;

  case 326: /* shared_name: NAME '=' QSTRING ';'  */
#line 1783 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5299 "conf_parser.c"
    break;

  case 327: /* shared_user: USER '=' QSTRING ';'  */
#line 1789 "conf_parser.y"
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
#line 5321 "conf_parser.c"
    break;

  case 328: /* $@16: %empty  */
#line 1808 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5330 "conf_parser.c"
    break;

  case 332: /* shared_type_item: KLINE  */
#line 1815 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5339 "conf_parser.c"
    break;

  case 333: /* shared_type_item: UNKLINE  */
#line 1819 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5348 "conf_parser.c"
    break;

  case 334: /* shared_type_item: T_DLINE  */
#line 1823 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5357 "conf_parser.c"
    break;

  case 335: /* shared_type_item: T_UNDLINE  */
#line 1827 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5366 "conf_parser.c"
    break;

  case 336: /* shared_type_item: XLINE  */
#line 1831 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5375 "conf_parser.c"
    break;

  case 337: /* shared_type_item: T_UNXLINE  */
#line 1835 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5384 "conf_parser.c"
    break;

  case 338: /* shared_type_item: REHASH  */
#line 1839 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_REHASH;
}
#line 5393 "conf_parser.c"
    break;

  case 339: /* shared_type_item: RESV  */
#line 1843 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5402 "conf_parser.c"
    break;

  case 340: /* shared_type_item: T_UNRESV  */
#line 1847 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5411 "conf_parser.c"
    break;

  case 341: /* shared_type_item: T_LOCOPS  */
#line 1851 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5420 "conf_parser.c"
    break;

  case 342: /* shared_type_item: T_ALL  */
#line 1855 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5429 "conf_parser.c"
    break;

  case 343: /* $@17: %empty  */
#line 1865 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5443 "conf_parser.c"
    break;

  case 344: /* cluster_entry: T_CLUSTER $@17 '{' cluster_items '}' ';'  */
#line 1874 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5456 "conf_parser.c"
    break;

  case 350: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1887 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5465 "conf_parser.c"
    break;

  case 351: /* $@18: %empty  */
#line 1893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5474 "conf_parser.c"
    break;

  case 355: /* cluster_type_item: KLINE  */
#line 1900 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5483 "conf_parser.c"
    break;

  case 356: /* cluster_type_item: UNKLINE  */
#line 1904 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5492 "conf_parser.c"
    break;

  case 357: /* cluster_type_item: T_DLINE  */
#line 1908 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5501 "conf_parser.c"
    break;

  case 358: /* cluster_type_item: T_UNDLINE  */
#line 1912 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5510 "conf_parser.c"
    break;

  case 359: /* cluster_type_item: XLINE  */
#line 1916 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5519 "conf_parser.c"
    break;

  case 360: /* cluster_type_item: T_UNXLINE  */
#line 1920 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5528 "conf_parser.c"
    break;

  case 361: /* cluster_type_item: RESV  */
#line 1924 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5537 "conf_parser.c"
    break;

  case 362: /* cluster_type_item: T_UNRESV  */
#line 1928 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5546 "conf_parser.c"
    break;

  case 363: /* cluster_type_item: T_LOCOPS  */
#line 1932 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5555 "conf_parser.c"
    break;

  case 364: /* cluster_type_item: T_ALL  */
#line 1936 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5564 "conf_parser.c"
    break;

  case 365: /* $@19: %empty  */
#line 1946 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECT_DEFAULT_TIMEOUT_SEC;
  block_state.retry_delay_sec.value = CONNECT_DEFAULT_RETRY_DELAY_SEC;
}
#line 5579 "conf_parser.c"
    break;

  case 366: /* connect_entry: CONNECT $@19 '{' connect_items '}' ';'  */
#line 1956 "conf_parser.y"
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
      conf_report_error("Invalid IP address for bind address");

  connect_assign_class(connect, block_state.klass.buf);
  connect_dns_lookup(connect);
}
#line 5628 "conf_parser.c"
    break;

  case 385: /* connect_name: NAME '=' QSTRING ';'  */
#line 2020 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5637 "conf_parser.c"
    break;

  case 386: /* connect_host: HOST '=' QSTRING ';'  */
#line 2026 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5646 "conf_parser.c"
    break;

  case 387: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 2032 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5655 "conf_parser.c"
    break;

  case 388: /* connect_retry_delay: RETRY_DELAY '=' timespec ';'  */
#line 2038 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.retry_delay_sec.value = (yyvsp[-1].number);
}
#line 5664 "conf_parser.c"
    break;

  case 389: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 2044 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5673 "conf_parser.c"
    break;

  case 390: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2050 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (*yylval.string == ':')
    conf_report_error("Server passwords cannot begin with a colon");
  else if (strchr(yylval.string, ' '))
    conf_report_error("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.spass.buf, yylval.string, sizeof(block_state.spass.buf));
}
#line 5689 "conf_parser.c"
    break;

  case 391: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2063 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (*yylval.string == ':')
    conf_report_error("Server passwords cannot begin with a colon");
  else if (strchr(yylval.string, ' '))
    conf_report_error("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5705 "conf_parser.c"
    break;

  case 392: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2076 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5714 "conf_parser.c"
    break;

  case 393: /* connect_port: PORT '=' port_number ';'  */
#line 2082 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5723 "conf_parser.c"
    break;

  case 394: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2088 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5732 "conf_parser.c"
    break;

  case 395: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5741 "conf_parser.c"
    break;

  case 396: /* $@20: %empty  */
#line 2098 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5749 "conf_parser.c"
    break;

  case 400: /* connect_flags_item: AUTOCONN  */
#line 2104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5758 "conf_parser.c"
    break;

  case 401: /* connect_flags_item: T_TLS  */
#line 2108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5767 "conf_parser.c"
    break;

  case 402: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2114 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].boolean))
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5781 "conf_parser.c"
    break;

  case 403: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5790 "conf_parser.c"
    break;

  case 404: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2131 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5799 "conf_parser.c"
    break;

  case 405: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5808 "conf_parser.c"
    break;

  case 406: /* $@21: %empty  */
#line 2147 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5817 "conf_parser.c"
    break;

  case 407: /* kill_entry: KILL $@21 '{' kill_items '}' ';'  */
#line 2151 "conf_parser.y"
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
    conf_report_error("Unable to add K-line");
}
#line 5841 "conf_parser.c"
    break;

  case 413: /* kill_user: USER '=' QSTRING ';'  */
#line 2175 "conf_parser.y"
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
#line 5864 "conf_parser.c"
    break;

  case 414: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2195 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5873 "conf_parser.c"
    break;

  case 415: /* $@22: %empty  */
#line 2205 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5882 "conf_parser.c"
    break;

  case 416: /* deny_entry: DENY $@22 '{' deny_items '}' ';'  */
#line 2209 "conf_parser.y"
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
    conf_report_error("Unable to add D-line");
}
#line 5904 "conf_parser.c"
    break;

  case 422: /* deny_ip: IP '=' QSTRING ';'  */
#line 2231 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5913 "conf_parser.c"
    break;

  case 423: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2237 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5922 "conf_parser.c"
    break;

  case 429: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2252 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_report_error("Unable to add D-line exemption");
}
#line 5934 "conf_parser.c"
    break;

  case 430: /* $@23: %empty  */
#line 2265 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5943 "conf_parser.c"
    break;

  case 431: /* gecos_entry: GECOS $@23 '{' gecos_items '}' ';'  */
#line 2269 "conf_parser.y"
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
#line 5963 "conf_parser.c"
    break;

  case 437: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2289 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5972 "conf_parser.c"
    break;

  case 438: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2295 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5981 "conf_parser.c"
    break;

  case 482: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2350 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5989 "conf_parser.c"
    break;

  case 483: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2355 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5997 "conf_parser.c"
    break;

  case 484: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2360 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 6005 "conf_parser.c"
    break;

  case 485: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2365 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 6013 "conf_parser.c"
    break;

  case 486: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2370 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 6021 "conf_parser.c"
    break;

  case 487: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2375 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 6029 "conf_parser.c"
    break;

  case 488: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2380 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 6037 "conf_parser.c"
    break;

  case 489: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2385 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 6045 "conf_parser.c"
    break;

  case 490: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2390 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 6053 "conf_parser.c"
    break;

  case 491: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2395 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 6061 "conf_parser.c"
    break;

  case 492: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2400 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6069 "conf_parser.c"
    break;

  case 493: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2405 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6077 "conf_parser.c"
    break;

  case 494: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2410 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 6088 "conf_parser.c"
    break;

  case 495: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2418 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6096 "conf_parser.c"
    break;

  case 496: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2423 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6104 "conf_parser.c"
    break;

  case 497: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2428 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6112 "conf_parser.c"
    break;

  case 498: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2433 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = (yyvsp[-1].boolean);
}
#line 6120 "conf_parser.c"
    break;

  case 499: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2438 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = (yyvsp[-1].boolean);
}
#line 6128 "conf_parser.c"
    break;

  case 500: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2443 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = (yyvsp[-1].boolean);
}
#line 6136 "conf_parser.c"
    break;

  case 501: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2448 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = (yyvsp[-1].boolean);
}
#line 6144 "conf_parser.c"
    break;

  case 502: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2453 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6152 "conf_parser.c"
    break;

  case 503: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2458 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6160 "conf_parser.c"
    break;

  case 504: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2463 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = (yyvsp[-1].boolean);
}
#line 6168 "conf_parser.c"
    break;

  case 505: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2468 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6176 "conf_parser.c"
    break;

  case 506: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2473 "conf_parser.y"
{
  ConfigGeneral.short_motd = (yyvsp[-1].boolean);
}
#line 6184 "conf_parser.c"
    break;

  case 507: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2478 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6192 "conf_parser.c"
    break;

  case 508: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2483 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6200 "conf_parser.c"
    break;

  case 509: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2488 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = (yyvsp[-1].boolean);
}
#line 6208 "conf_parser.c"
    break;

  case 510: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2493 "conf_parser.y"
{
  ConfigGeneral.disable_ident = (yyvsp[-1].boolean);
}
#line 6216 "conf_parser.c"
    break;

  case 511: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2498 "conf_parser.y"
{
  ConfigGeneral.disable_dns = (yyvsp[-1].boolean);
}
#line 6224 "conf_parser.c"
    break;

  case 512: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2503 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6232 "conf_parser.c"
    break;

  case 513: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2508 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6240 "conf_parser.c"
    break;

  case 514: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2513 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6252 "conf_parser.c"
    break;

  case 515: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2522 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6260 "conf_parser.c"
    break;

  case 516: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2527 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6268 "conf_parser.c"
    break;

  case 517: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2532 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6276 "conf_parser.c"
    break;

  case 518: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2537 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6284 "conf_parser.c"
    break;

  case 519: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2542 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6295 "conf_parser.c"
    break;

  case 520: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2550 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6303 "conf_parser.c"
    break;

  case 531: /* cloak_enabled: ENABLED '=' TBOOL ';'  */
#line 2570 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.enabled = (yyvsp[-1].boolean);
  if (ConfigCloak.enabled)
    cloak_set_enabled();
  else
    cloak_set_disabled();
}
#line 6318 "conf_parser.c"
    break;

  case 532: /* cloak_cidr_len_ipv4: CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2582 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6330 "conf_parser.c"
    break;

  case 533: /* cloak_cidr_len_ipv6: CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2591 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6342 "conf_parser.c"
    break;

  case 534: /* cloak_num_bits: NUM_BITS '=' NUMBER ';'  */
#line 2600 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6354 "conf_parser.c"
    break;

  case 535: /* cloak_secret: SECRET '=' QSTRING ';'  */
#line 2609 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.secret);
  ConfigCloak.secret = io_strdup((yyvsp[-1].string));
  cloak_set_secret((yyvsp[-1].string));
}
#line 6367 "conf_parser.c"
    break;

  case 536: /* cloak_suffix: SUFFIX '=' QSTRING ';'  */
#line 2619 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.suffix);
  ConfigCloak.suffix = io_strdup((yyvsp[-1].string));
  cloak_set_suffix((yyvsp[-1].string));
}
#line 6380 "conf_parser.c"
    break;

  case 557: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2654 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = (yyvsp[-1].boolean);
}
#line 6388 "conf_parser.c"
    break;

  case 558: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2659 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6396 "conf_parser.c"
    break;

  case 559: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2664 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6404 "conf_parser.c"
    break;

  case 560: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2669 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6412 "conf_parser.c"
    break;

  case 561: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2674 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6420 "conf_parser.c"
    break;

  case 562: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2679 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6428 "conf_parser.c"
    break;

  case 563: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2684 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6436 "conf_parser.c"
    break;

  case 564: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2689 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6444 "conf_parser.c"
    break;

  case 565: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2694 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6452 "conf_parser.c"
    break;

  case 566: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2699 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6460 "conf_parser.c"
    break;

  case 567: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2704 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6468 "conf_parser.c"
    break;

  case 568: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2709 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6476 "conf_parser.c"
    break;

  case 569: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2714 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > KICKLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_kick_length out of range, setting to %d", KICKLEN);
    conf_report_warning(buf);

    ConfigChannel.max_kick_length = KICKLEN;
  }
  else
    ConfigChannel.max_kick_length = (yyvsp[-1].number);
}
#line 6497 "conf_parser.c"
    break;

  case 570: /* channel_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 2732 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigChannel.max_topic_length = TOPICLEN;
  else
    ConfigChannel.max_topic_length = (yyvsp[-1].number);
}
#line 6508 "conf_parser.c"
    break;

  case 571: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2740 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = (yyvsp[-1].number);
}
#line 6516 "conf_parser.c"
    break;

  case 572: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2745 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6524 "conf_parser.c"
    break;

  case 585: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2767 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = (yyvsp[-1].boolean);
}
#line 6533 "conf_parser.c"
    break;

  case 586: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2773 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6547 "conf_parser.c"
    break;

  case 587: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2784 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6559 "conf_parser.c"
    break;

  case 588: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2793 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = (yyvsp[-1].boolean);
}
#line 6568 "conf_parser.c"
    break;

  case 589: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2799 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = (yyvsp[-1].boolean);
}
#line 6577 "conf_parser.c"
    break;

  case 590: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2805 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = (yyvsp[-1].boolean);
}
#line 6586 "conf_parser.c"
    break;

  case 591: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2811 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6598 "conf_parser.c"
    break;

  case 592: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2820 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = (yyvsp[-1].boolean);
}
#line 6607 "conf_parser.c"
    break;


#line 6611 "conf_parser.c"

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

