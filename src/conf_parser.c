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


#line 246 "conf_parser.c"

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

#line 285 "conf_parser.c"

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
    MIN_NONWILDCARD = 358,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 359,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 360,                  /* MODULE  */
    MODULE_BASE_PATH = 361,        /* MODULE_BASE_PATH  */
    MOTD = 362,                    /* MOTD  */
    MOTD_FILE = 363,               /* MOTD_FILE  */
    NAME = 364,                    /* NAME  */
    NEED_IDENT = 365,              /* NEED_IDENT  */
    NEED_PASSWORD = 366,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 367,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 368,            /* NETWORK_NAME  */
    NICK = 369,                    /* NICK  */
    NO_TILDE = 370,                /* NO_TILDE  */
    NUM_BITS = 371,                /* NUM_BITS  */
    NUMBER_PER_CIDR = 372,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 373,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 374,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 375,             /* OPER_UMODES  */
    OPERATOR = 376,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 377,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 378,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 379,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 380,                /* PASSWORD  */
    PING_COOKIE = 381,             /* PING_COOKIE  */
    PING_TIME = 382,               /* PING_TIME  */
    PORT = 383,                    /* PORT  */
    REASON = 384,                  /* REASON  */
    REGISTRATION_TIMEOUT = 385,    /* REGISTRATION_TIMEOUT  */
    REHASH = 386,                  /* REHASH  */
    REMOTE = 387,                  /* REMOTE  */
    REMOTEBAN = 388,               /* REMOTEBAN  */
    REQUIRED = 389,                /* REQUIRED  */
    RESIDENT = 390,                /* RESIDENT  */
    RESV = 391,                    /* RESV  */
    RESV_EXEMPT = 392,             /* RESV_EXEMPT  */
    RETRY_DELAY = 393,             /* RETRY_DELAY  */
    SASL_SERVICE = 394,            /* SASL_SERVICE  */
    SECRET = 395,                  /* SECRET  */
    SECONDS = 396,                 /* SECONDS  */
    MINUTES = 397,                 /* MINUTES  */
    HOURS = 398,                   /* HOURS  */
    DAYS = 399,                    /* DAYS  */
    WEEKS = 400,                   /* WEEKS  */
    SEND_PASSWORD = 401,           /* SEND_PASSWORD  */
    SENDQ = 402,                   /* SENDQ  */
    SERVERHIDE = 403,              /* SERVERHIDE  */
    SERVERINFO = 404,              /* SERVERINFO  */
    SHORT_MOTD = 405,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 406,       /* SPECIALS_IN_IDENT  */
    SPOOF = 407,                   /* SPOOF  */
    SQUIT = 408,                   /* SQUIT  */
    STATS_E_DISABLED = 409,        /* STATS_E_DISABLED  */
    STATS_U_OPER_ONLY = 410,       /* STATS_U_OPER_ONLY  */
    SUFFIX = 411,                  /* SUFFIX  */
    T_ALL = 412,                   /* T_ALL  */
    T_BIND = 413,                  /* T_BIND  */
    T_COMMAND = 414,               /* T_COMMAND  */
    T_CLUSTER = 415,               /* T_CLUSTER  */
    T_DEBUG = 416,                 /* T_DEBUG  */
    T_DLINE = 417,                 /* T_DLINE  */
    T_FILE = 418,                  /* T_FILE  */
    T_GLOBOPS = 419,               /* T_GLOBOPS  */
    T_IPV4 = 420,                  /* T_IPV4  */
    T_IPV6 = 421,                  /* T_IPV6  */
    T_LOCOPS = 422,                /* T_LOCOPS  */
    T_LOG = 423,                   /* T_LOG  */
    T_OPME = 424,                  /* T_OPME  */
    T_PREPEND = 425,               /* T_PREPEND  */
    T_PSEUDO = 426,                /* T_PSEUDO  */
    T_RECVQ = 427,                 /* T_RECVQ  */
    T_RESTART = 428,               /* T_RESTART  */
    T_SERVER = 429,                /* T_SERVER  */
    T_SERVICE = 430,               /* T_SERVICE  */
    T_SET = 431,                   /* T_SET  */
    T_SHARED = 432,                /* T_SHARED  */
    T_SIZE = 433,                  /* T_SIZE  */
    T_TARGET = 434,                /* T_TARGET  */
    T_TLS = 435,                   /* T_TLS  */
    T_UMODES = 436,                /* T_UMODES  */
    T_UNDLINE = 437,               /* T_UNDLINE  */
    T_UNLIMITED = 438,             /* T_UNLIMITED  */
    T_UNRESV = 439,                /* T_UNRESV  */
    T_UNXLINE = 440,               /* T_UNXLINE  */
    T_WEBIRC = 441,                /* T_WEBIRC  */
    TBOOL = 442,                   /* TBOOL  */
    THROTTLE_COUNT = 443,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 444,           /* THROTTLE_TIME  */
    TIMEOUT = 445,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 446,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 447, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 448,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 449, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 450,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 451,           /* TS_WARN_DELTA  */
    TWODOTS = 452,                 /* TWODOTS  */
    TYPE = 453,                    /* TYPE  */
    UNKLINE = 454,                 /* UNKLINE  */
    USE_LOGGING = 455,             /* USE_LOGGING  */
    USER = 456,                    /* USER  */
    WARN_NO_CONNECT_BLOCK = 457,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 458,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 459,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 460,                   /* XLINE  */
    XLINE_EXEMPT = 461,            /* XLINE_EXEMPT  */
    QSTRING = 462,                 /* QSTRING  */
    DECIMAL = 463,                 /* DECIMAL  */
    NUMBER = 464                   /* NUMBER  */
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
#define MIN_NONWILDCARD 358
#define MIN_NONWILDCARD_SIMPLE 359
#define MODULE 360
#define MODULE_BASE_PATH 361
#define MOTD 362
#define MOTD_FILE 363
#define NAME 364
#define NEED_IDENT 365
#define NEED_PASSWORD 366
#define NETWORK_DESCRIPTION 367
#define NETWORK_NAME 368
#define NICK 369
#define NO_TILDE 370
#define NUM_BITS 371
#define NUMBER_PER_CIDR 372
#define NUMBER_PER_IP_GLOBAL 373
#define NUMBER_PER_IP_LOCAL 374
#define OPER_UMODES 375
#define OPERATOR 376
#define OPERS_BYPASS_CALLERID 377
#define PACE_WAIT 378
#define PACE_WAIT_SIMPLE 379
#define PASSWORD 380
#define PING_COOKIE 381
#define PING_TIME 382
#define PORT 383
#define REASON 384
#define REGISTRATION_TIMEOUT 385
#define REHASH 386
#define REMOTE 387
#define REMOTEBAN 388
#define REQUIRED 389
#define RESIDENT 390
#define RESV 391
#define RESV_EXEMPT 392
#define RETRY_DELAY 393
#define SASL_SERVICE 394
#define SECRET 395
#define SECONDS 396
#define MINUTES 397
#define HOURS 398
#define DAYS 399
#define WEEKS 400
#define SEND_PASSWORD 401
#define SENDQ 402
#define SERVERHIDE 403
#define SERVERINFO 404
#define SHORT_MOTD 405
#define SPECIALS_IN_IDENT 406
#define SPOOF 407
#define SQUIT 408
#define STATS_E_DISABLED 409
#define STATS_U_OPER_ONLY 410
#define SUFFIX 411
#define T_ALL 412
#define T_BIND 413
#define T_COMMAND 414
#define T_CLUSTER 415
#define T_DEBUG 416
#define T_DLINE 417
#define T_FILE 418
#define T_GLOBOPS 419
#define T_IPV4 420
#define T_IPV6 421
#define T_LOCOPS 422
#define T_LOG 423
#define T_OPME 424
#define T_PREPEND 425
#define T_PSEUDO 426
#define T_RECVQ 427
#define T_RESTART 428
#define T_SERVER 429
#define T_SERVICE 430
#define T_SET 431
#define T_SHARED 432
#define T_SIZE 433
#define T_TARGET 434
#define T_TLS 435
#define T_UMODES 436
#define T_UNDLINE 437
#define T_UNLIMITED 438
#define T_UNRESV 439
#define T_UNXLINE 440
#define T_WEBIRC 441
#define TBOOL 442
#define THROTTLE_COUNT 443
#define THROTTLE_TIME 444
#define TIMEOUT 445
#define TLS_CERTIFICATE_FILE 446
#define TLS_CERTIFICATE_FINGERPRINT 447
#define TLS_PRIVATE_KEY_FILE 448
#define TLS_CONNECTION_REQUIRED 449
#define TS_MAX_DELTA 450
#define TS_WARN_DELTA 451
#define TWODOTS 452
#define TYPE 453
#define UNKLINE 454
#define USE_LOGGING 455
#define USER 456
#define WARN_NO_CONNECT_BLOCK 457
#define WHOIS 458
#define WHOWAS_HISTORY_LENGTH 459
#define XLINE 460
#define XLINE_EXEMPT 461
#define QSTRING 462
#define DECIMAL 463
#define NUMBER 464

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 191 "conf_parser.y"

  bool boolean;
  unsigned int number;
  char *string;

#line 729 "conf_parser.c"

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
  YYSYMBOL_MIN_NONWILDCARD = 103,          /* MIN_NONWILDCARD  */
  YYSYMBOL_MIN_NONWILDCARD_SIMPLE = 104,   /* MIN_NONWILDCARD_SIMPLE  */
  YYSYMBOL_MODULE = 105,                   /* MODULE  */
  YYSYMBOL_MODULE_BASE_PATH = 106,         /* MODULE_BASE_PATH  */
  YYSYMBOL_MOTD = 107,                     /* MOTD  */
  YYSYMBOL_MOTD_FILE = 108,                /* MOTD_FILE  */
  YYSYMBOL_NAME = 109,                     /* NAME  */
  YYSYMBOL_NEED_IDENT = 110,               /* NEED_IDENT  */
  YYSYMBOL_NEED_PASSWORD = 111,            /* NEED_PASSWORD  */
  YYSYMBOL_NETWORK_DESCRIPTION = 112,      /* NETWORK_DESCRIPTION  */
  YYSYMBOL_NETWORK_NAME = 113,             /* NETWORK_NAME  */
  YYSYMBOL_NICK = 114,                     /* NICK  */
  YYSYMBOL_NO_TILDE = 115,                 /* NO_TILDE  */
  YYSYMBOL_NUM_BITS = 116,                 /* NUM_BITS  */
  YYSYMBOL_NUMBER_PER_CIDR = 117,          /* NUMBER_PER_CIDR  */
  YYSYMBOL_NUMBER_PER_IP_GLOBAL = 118,     /* NUMBER_PER_IP_GLOBAL  */
  YYSYMBOL_NUMBER_PER_IP_LOCAL = 119,      /* NUMBER_PER_IP_LOCAL  */
  YYSYMBOL_OPER_UMODES = 120,              /* OPER_UMODES  */
  YYSYMBOL_OPERATOR = 121,                 /* OPERATOR  */
  YYSYMBOL_OPERS_BYPASS_CALLERID = 122,    /* OPERS_BYPASS_CALLERID  */
  YYSYMBOL_PACE_WAIT = 123,                /* PACE_WAIT  */
  YYSYMBOL_PACE_WAIT_SIMPLE = 124,         /* PACE_WAIT_SIMPLE  */
  YYSYMBOL_PASSWORD = 125,                 /* PASSWORD  */
  YYSYMBOL_PING_COOKIE = 126,              /* PING_COOKIE  */
  YYSYMBOL_PING_TIME = 127,                /* PING_TIME  */
  YYSYMBOL_PORT = 128,                     /* PORT  */
  YYSYMBOL_REASON = 129,                   /* REASON  */
  YYSYMBOL_REGISTRATION_TIMEOUT = 130,     /* REGISTRATION_TIMEOUT  */
  YYSYMBOL_REHASH = 131,                   /* REHASH  */
  YYSYMBOL_REMOTE = 132,                   /* REMOTE  */
  YYSYMBOL_REMOTEBAN = 133,                /* REMOTEBAN  */
  YYSYMBOL_REQUIRED = 134,                 /* REQUIRED  */
  YYSYMBOL_RESIDENT = 135,                 /* RESIDENT  */
  YYSYMBOL_RESV = 136,                     /* RESV  */
  YYSYMBOL_RESV_EXEMPT = 137,              /* RESV_EXEMPT  */
  YYSYMBOL_RETRY_DELAY = 138,              /* RETRY_DELAY  */
  YYSYMBOL_SASL_SERVICE = 139,             /* SASL_SERVICE  */
  YYSYMBOL_SECRET = 140,                   /* SECRET  */
  YYSYMBOL_SECONDS = 141,                  /* SECONDS  */
  YYSYMBOL_MINUTES = 142,                  /* MINUTES  */
  YYSYMBOL_HOURS = 143,                    /* HOURS  */
  YYSYMBOL_DAYS = 144,                     /* DAYS  */
  YYSYMBOL_WEEKS = 145,                    /* WEEKS  */
  YYSYMBOL_SEND_PASSWORD = 146,            /* SEND_PASSWORD  */
  YYSYMBOL_SENDQ = 147,                    /* SENDQ  */
  YYSYMBOL_SERVERHIDE = 148,               /* SERVERHIDE  */
  YYSYMBOL_SERVERINFO = 149,               /* SERVERINFO  */
  YYSYMBOL_SHORT_MOTD = 150,               /* SHORT_MOTD  */
  YYSYMBOL_SPECIALS_IN_IDENT = 151,        /* SPECIALS_IN_IDENT  */
  YYSYMBOL_SPOOF = 152,                    /* SPOOF  */
  YYSYMBOL_SQUIT = 153,                    /* SQUIT  */
  YYSYMBOL_STATS_E_DISABLED = 154,         /* STATS_E_DISABLED  */
  YYSYMBOL_STATS_U_OPER_ONLY = 155,        /* STATS_U_OPER_ONLY  */
  YYSYMBOL_SUFFIX = 156,                   /* SUFFIX  */
  YYSYMBOL_T_ALL = 157,                    /* T_ALL  */
  YYSYMBOL_T_BIND = 158,                   /* T_BIND  */
  YYSYMBOL_T_COMMAND = 159,                /* T_COMMAND  */
  YYSYMBOL_T_CLUSTER = 160,                /* T_CLUSTER  */
  YYSYMBOL_T_DEBUG = 161,                  /* T_DEBUG  */
  YYSYMBOL_T_DLINE = 162,                  /* T_DLINE  */
  YYSYMBOL_T_FILE = 163,                   /* T_FILE  */
  YYSYMBOL_T_GLOBOPS = 164,                /* T_GLOBOPS  */
  YYSYMBOL_T_IPV4 = 165,                   /* T_IPV4  */
  YYSYMBOL_T_IPV6 = 166,                   /* T_IPV6  */
  YYSYMBOL_T_LOCOPS = 167,                 /* T_LOCOPS  */
  YYSYMBOL_T_LOG = 168,                    /* T_LOG  */
  YYSYMBOL_T_OPME = 169,                   /* T_OPME  */
  YYSYMBOL_T_PREPEND = 170,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 171,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 172,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 173,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 174,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 175,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 176,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 177,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 178,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 179,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 180,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 181,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 182,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 183,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 184,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 185,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 186,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 187,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 188,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 189,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 190,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 191,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 192, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_PRIVATE_KEY_FILE = 193,     /* TLS_PRIVATE_KEY_FILE  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 194,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TS_MAX_DELTA = 195,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 196,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 197,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 198,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 199,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 200,              /* USE_LOGGING  */
  YYSYMBOL_USER = 201,                     /* USER  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 202,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 203,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 204,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 205,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 206,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 207,                  /* QSTRING  */
  YYSYMBOL_DECIMAL = 208,                  /* DECIMAL  */
  YYSYMBOL_NUMBER = 209,                   /* NUMBER  */
  YYSYMBOL_210_ = 210,                     /* ';'  */
  YYSYMBOL_211_ = 211,                     /* '}'  */
  YYSYMBOL_212_ = 212,                     /* '='  */
  YYSYMBOL_213_ = 213,                     /* ':'  */
  YYSYMBOL_214_ = 214,                     /* ','  */
  YYSYMBOL_215_ = 215,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 216,                 /* $accept  */
  YYSYMBOL_conf = 217,                     /* conf  */
  YYSYMBOL_conf_item = 218,                /* conf_item  */
  YYSYMBOL_timespec = 219,                 /* timespec  */
  YYSYMBOL_time_components = 220,          /* time_components  */
  YYSYMBOL_time_component = 221,           /* time_component  */
  YYSYMBOL_time_unit = 222,                /* time_unit  */
  YYSYMBOL_sizespec = 223,                 /* sizespec  */
  YYSYMBOL_size_components = 224,          /* size_components  */
  YYSYMBOL_size_component = 225,           /* size_component  */
  YYSYMBOL_size_unit = 226,                /* size_unit  */
  YYSYMBOL_port_number = 227,              /* port_number  */
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
  YYSYMBOL_class_max_channels = 306,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 307,         /* class_max_number  */
  YYSYMBOL_class_sendq = 308,              /* class_sendq  */
  YYSYMBOL_class_recvq = 309,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 310,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 311,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 312,    /* class_number_per_cidr  */
  YYSYMBOL_listen_entry = 313,             /* listen_entry  */
  YYSYMBOL_314_8 = 314,                    /* $@8  */
  YYSYMBOL_listen_flags = 315,             /* listen_flags  */
  YYSYMBOL_316_9 = 316,                    /* $@9  */
  YYSYMBOL_listen_flags_items = 317,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 318,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 319,             /* listen_items  */
  YYSYMBOL_listen_item = 320,              /* listen_item  */
  YYSYMBOL_listen_port = 321,              /* listen_port  */
  YYSYMBOL_322_10 = 322,                   /* $@10  */
  YYSYMBOL_port_items = 323,               /* port_items  */
  YYSYMBOL_port_item = 324,                /* port_item  */
  YYSYMBOL_listen_address = 325,           /* listen_address  */
  YYSYMBOL_listen_host = 326,              /* listen_host  */
  YYSYMBOL_auth_entry = 327,               /* auth_entry  */
  YYSYMBOL_328_11 = 328,                   /* $@11  */
  YYSYMBOL_auth_items = 329,               /* auth_items  */
  YYSYMBOL_auth_item = 330,                /* auth_item  */
  YYSYMBOL_auth_user = 331,                /* auth_user  */
  YYSYMBOL_auth_passwd = 332,              /* auth_passwd  */
  YYSYMBOL_auth_class = 333,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 334,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 335,               /* auth_flags  */
  YYSYMBOL_336_12 = 336,                   /* $@12  */
  YYSYMBOL_auth_flags_items = 337,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 338,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 339,               /* auth_spoof  */
  YYSYMBOL_resv_entry = 340,               /* resv_entry  */
  YYSYMBOL_341_13 = 341,                   /* $@13  */
  YYSYMBOL_resv_items = 342,               /* resv_items  */
  YYSYMBOL_resv_item = 343,                /* resv_item  */
  YYSYMBOL_resv_mask = 344,                /* resv_mask  */
  YYSYMBOL_resv_reason = 345,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 346,              /* resv_exempt  */
  YYSYMBOL_service_entry = 347,            /* service_entry  */
  YYSYMBOL_service_items = 348,            /* service_items  */
  YYSYMBOL_service_item = 349,             /* service_item  */
  YYSYMBOL_service_name = 350,             /* service_name  */
  YYSYMBOL_shared_entry = 351,             /* shared_entry  */
  YYSYMBOL_352_14 = 352,                   /* $@14  */
  YYSYMBOL_shared_items = 353,             /* shared_items  */
  YYSYMBOL_shared_item = 354,              /* shared_item  */
  YYSYMBOL_shared_name = 355,              /* shared_name  */
  YYSYMBOL_shared_user = 356,              /* shared_user  */
  YYSYMBOL_shared_type = 357,              /* shared_type  */
  YYSYMBOL_358_15 = 358,                   /* $@15  */
  YYSYMBOL_shared_types = 359,             /* shared_types  */
  YYSYMBOL_shared_type_item = 360,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 361,            /* cluster_entry  */
  YYSYMBOL_362_16 = 362,                   /* $@16  */
  YYSYMBOL_cluster_items = 363,            /* cluster_items  */
  YYSYMBOL_cluster_item = 364,             /* cluster_item  */
  YYSYMBOL_cluster_name = 365,             /* cluster_name  */
  YYSYMBOL_cluster_type = 366,             /* cluster_type  */
  YYSYMBOL_367_17 = 367,                   /* $@17  */
  YYSYMBOL_cluster_types = 368,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 369,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 370,            /* connect_entry  */
  YYSYMBOL_371_18 = 371,                   /* $@18  */
  YYSYMBOL_connect_items = 372,            /* connect_items  */
  YYSYMBOL_connect_item = 373,             /* connect_item  */
  YYSYMBOL_connect_name = 374,             /* connect_name  */
  YYSYMBOL_connect_host = 375,             /* connect_host  */
  YYSYMBOL_connect_timeout = 376,          /* connect_timeout  */
  YYSYMBOL_connect_retry_delay = 377,      /* connect_retry_delay  */
  YYSYMBOL_connect_bind = 378,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 379,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 380,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 381, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 382,             /* connect_port  */
  YYSYMBOL_connect_aftype = 383,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 384,            /* connect_flags  */
  YYSYMBOL_385_19 = 385,                   /* $@19  */
  YYSYMBOL_connect_flags_items = 386,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 387,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 388,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 389,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 390,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 391,            /* connect_class  */
  YYSYMBOL_kill_entry = 392,               /* kill_entry  */
  YYSYMBOL_393_20 = 393,                   /* $@20  */
  YYSYMBOL_kill_items = 394,               /* kill_items  */
  YYSYMBOL_kill_item = 395,                /* kill_item  */
  YYSYMBOL_kill_user = 396,                /* kill_user  */
  YYSYMBOL_kill_reason = 397,              /* kill_reason  */
  YYSYMBOL_deny_entry = 398,               /* deny_entry  */
  YYSYMBOL_399_21 = 399,                   /* $@21  */
  YYSYMBOL_deny_items = 400,               /* deny_items  */
  YYSYMBOL_deny_item = 401,                /* deny_item  */
  YYSYMBOL_deny_ip = 402,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 403,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 404,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 405,             /* exempt_items  */
  YYSYMBOL_exempt_item = 406,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 407,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 408,              /* gecos_entry  */
  YYSYMBOL_409_22 = 409,                   /* $@22  */
  YYSYMBOL_gecos_items = 410,              /* gecos_items  */
  YYSYMBOL_gecos_item = 411,               /* gecos_item  */
  YYSYMBOL_gecos_name = 412,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 413,             /* gecos_reason  */
  YYSYMBOL_general_entry = 414,            /* general_entry  */
  YYSYMBOL_general_items = 415,            /* general_items  */
  YYSYMBOL_general_item = 416,             /* general_item  */
  YYSYMBOL_general_away_count = 417,       /* general_away_count  */
  YYSYMBOL_general_away_time = 418,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 419,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 420, /* general_whowas_history_length  */
  YYSYMBOL_general_dline_min_cidr = 421,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 422,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 423,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 424,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 425, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_max_nick_time = 426,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 427, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 428,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 429,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 430, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 431,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 432,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 433, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 434, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 435, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_u_oper_only = 436, /* general_stats_u_oper_only  */
  YYSYMBOL_general_pace_wait = 437,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 438,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 439, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 440, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 441,       /* general_short_motd  */
  YYSYMBOL_general_specials_in_ident = 442, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 443,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 444,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_ident = 445,    /* general_disable_ident  */
  YYSYMBOL_general_disable_dns = 446,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 447,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 448,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 449,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 450,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 451, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 452, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 453, /* general_default_floodtime  */
  YYSYMBOL_general_ident_timeout = 454,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 455, /* general_registration_timeout  */
  YYSYMBOL_general_sasl_service = 456,     /* general_sasl_service  */
  YYSYMBOL_cloak_entry = 457,              /* cloak_entry  */
  YYSYMBOL_cloak_items = 458,              /* cloak_items  */
  YYSYMBOL_cloak_item = 459,               /* cloak_item  */
  YYSYMBOL_cloak_enabled = 460,            /* cloak_enabled  */
  YYSYMBOL_cloak_cidr_len_ipv4 = 461,      /* cloak_cidr_len_ipv4  */
  YYSYMBOL_cloak_cidr_len_ipv6 = 462,      /* cloak_cidr_len_ipv6  */
  YYSYMBOL_cloak_num_bits = 463,           /* cloak_num_bits  */
  YYSYMBOL_cloak_secret = 464,             /* cloak_secret  */
  YYSYMBOL_cloak_suffix = 465,             /* cloak_suffix  */
  YYSYMBOL_channel_entry = 466,            /* channel_entry  */
  YYSYMBOL_channel_items = 467,            /* channel_items  */
  YYSYMBOL_channel_item = 468,             /* channel_item  */
  YYSYMBOL_channel_disable_fake_channels = 469, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 470, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 471, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 472, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 473, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 474, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 475, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 476, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 477,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 478,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 479,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 480,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 481,  /* channel_max_kick_length  */
  YYSYMBOL_channel_max_topic_length = 482, /* channel_max_topic_length  */
  YYSYMBOL_channel_default_join_flood_count = 483, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 484, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 485,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 486,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 487,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 488, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 489, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 490, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 491, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 492,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 493, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 494,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 495         /* serverhide_hidden  */
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
#define YYLAST   1147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  216
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  280
/* YYNRULES -- Number of rules.  */
#define YYNRULES  583
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1192

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   464


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
       2,     2,     2,     2,   214,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   213,   210,
       2,   212,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   215,     2,   211,     2,     2,     2,     2,
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
     205,   206,   207,   208,   209
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   403,   403,   404,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     436,   445,   447,   447,   456,   463,   475,   476,   477,   478,
     479,   482,   491,   493,   493,   502,   509,   521,   522,   523,
     524,   525,   526,   527,   530,   545,   560,   572,   578,   580,
     585,   588,   593,   596,   605,   607,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   622,
     631,   640,   654,   668,   678,   692,   701,   724,   747,   756,
     766,   768,   768,   769,   770,   771,   772,   774,   783,   792,
     806,   805,   823,   823,   824,   824,   824,   826,   832,   843,
     842,   877,   877,   878,   878,   878,   878,   878,   880,   886,
     892,   898,   921,   922,   922,   924,   924,   925,   927,   937,
     937,   950,   951,   953,   953,   954,   954,   956,   964,   967,
     973,   972,   978,   982,   986,   990,   994,   998,  1002,  1006,
    1017,  1016,  1078,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1091,  1097,  1103,  1109,  1115,
    1126,  1132,  1143,  1149,  1156,  1155,  1161,  1161,  1162,  1166,
    1170,  1174,  1178,  1182,  1186,  1190,  1194,  1198,  1202,  1206,
    1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,  1242,  1246,
    1250,  1254,  1258,  1262,  1266,  1270,  1274,  1278,  1289,  1288,
    1331,  1331,  1332,  1333,  1334,  1335,  1336,  1337,  1338,  1339,
    1340,  1341,  1342,  1343,  1345,  1351,  1357,  1363,  1369,  1375,
    1381,  1387,  1394,  1400,  1406,  1416,  1415,  1422,  1421,  1426,
    1426,  1427,  1431,  1435,  1439,  1443,  1449,  1449,  1450,  1450,
    1450,  1450,  1450,  1452,  1452,  1454,  1454,  1456,  1469,  1486,
    1492,  1503,  1502,  1558,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1567,  1573,  1579,  1585,  1597,  1596,  1602,  1602,
    1604,  1608,  1612,  1616,  1620,  1624,  1628,  1632,  1636,  1642,
    1657,  1656,  1671,  1671,  1672,  1672,  1672,  1672,  1674,  1680,
    1686,  1696,  1698,  1698,  1699,  1699,  1701,  1718,  1717,  1740,
    1740,  1741,  1741,  1741,  1741,  1743,  1749,  1769,  1768,  1774,
    1774,  1775,  1779,  1783,  1787,  1791,  1795,  1799,  1803,  1807,
    1811,  1815,  1826,  1825,  1844,  1844,  1845,  1845,  1845,  1847,
    1854,  1853,  1859,  1859,  1860,  1864,  1868,  1872,  1876,  1880,
    1884,  1888,  1892,  1896,  1907,  1906,  1962,  1962,  1963,  1964,
    1965,  1966,  1967,  1968,  1969,  1970,  1971,  1972,  1973,  1974,
    1975,  1976,  1977,  1978,  1980,  1986,  1992,  1998,  2004,  2010,
    2023,  2036,  2042,  2048,  2052,  2059,  2058,  2063,  2063,  2064,
    2068,  2074,  2085,  2091,  2097,  2108,  2107,  2132,  2132,  2133,
    2133,  2133,  2135,  2155,  2166,  2165,  2188,  2188,  2189,  2189,
    2189,  2191,  2197,  2207,  2209,  2209,  2210,  2210,  2212,  2226,
    2225,  2246,  2246,  2247,  2247,  2247,  2249,  2255,  2265,  2267,
    2267,  2268,  2269,  2270,  2271,  2272,  2273,  2274,  2275,  2276,
    2277,  2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,  2286,
    2287,  2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,  2296,
    2297,  2298,  2299,  2300,  2301,  2302,  2303,  2304,  2305,  2306,
    2307,  2308,  2311,  2316,  2321,  2326,  2331,  2336,  2341,  2346,
    2351,  2356,  2361,  2366,  2371,  2379,  2384,  2389,  2394,  2399,
    2404,  2409,  2414,  2419,  2424,  2429,  2434,  2439,  2444,  2449,
    2454,  2459,  2464,  2469,  2474,  2483,  2488,  2493,  2498,  2503,
    2511,  2516,  2540,  2542,  2542,  2543,  2544,  2545,  2546,  2547,
    2548,  2549,  2551,  2563,  2572,  2581,  2590,  2600,  2614,  2616,
    2616,  2617,  2618,  2619,  2620,  2621,  2622,  2623,  2624,  2625,
    2626,  2627,  2628,  2629,  2630,  2631,  2632,  2633,  2635,  2640,
    2645,  2650,  2655,  2660,  2665,  2670,  2675,  2680,  2685,  2690,
    2695,  2713,  2721,  2726,  2735,  2737,  2737,  2738,  2739,  2740,
    2741,  2742,  2743,  2744,  2745,  2746,  2748,  2754,  2765,  2774,
    2780,  2786,  2792,  2801
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
  "GECOS", "GENERAL", "HIDDEN", "HIDDEN_NAME", "HIDE_SERVERS",
  "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK", "IDENT_TIMEOUT",
  "INPUT_FLOOD", "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT",
  "INVITE_CLIENT_TIME", "INVITE_DELAY_CHANNEL", "INVITE_EXPIRE_TIME", "IP",
  "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID", "JOIN", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_MIN_CIDR",
  "KLINE_MIN_CIDR6", "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME",
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LISTEN", "LOADMODULE", "MASK",
  "MASS", "MAX_ACCEPT", "MAX_AWAY_LENGTH", "MAX_BANS", "MAX_BANS_LARGE",
  "MAX_CHANNELS", "MAX_INVITES", "MAX_KICK_LENGTH", "MAX_MONITOR",
  "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MESSAGE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULE_BASE_PATH", "MOTD",
  "MOTD_FILE", "NAME", "NEED_IDENT", "NEED_PASSWORD",
  "NETWORK_DESCRIPTION", "NETWORK_NAME", "NICK", "NO_TILDE", "NUM_BITS",
  "NUMBER_PER_CIDR", "NUMBER_PER_IP_GLOBAL", "NUMBER_PER_IP_LOCAL",
  "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID", "PACE_WAIT",
  "PACE_WAIT_SIMPLE", "PASSWORD", "PING_COOKIE", "PING_TIME", "PORT",
  "REASON", "REGISTRATION_TIMEOUT", "REHASH", "REMOTE", "REMOTEBAN",
  "REQUIRED", "RESIDENT", "RESV", "RESV_EXEMPT", "RETRY_DELAY",
  "SASL_SERVICE", "SECRET", "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS",
  "SEND_PASSWORD", "SENDQ", "SERVERHIDE", "SERVERINFO", "SHORT_MOTD",
  "SPECIALS_IN_IDENT", "SPOOF", "SQUIT", "STATS_E_DISABLED",
  "STATS_U_OPER_ONLY", "SUFFIX", "T_ALL", "T_BIND", "T_COMMAND",
  "T_CLUSTER", "T_DEBUG", "T_DLINE", "T_FILE", "T_GLOBOPS", "T_IPV4",
  "T_IPV6", "T_LOCOPS", "T_LOG", "T_OPME", "T_PREPEND", "T_PSEUDO",
  "T_RECVQ", "T_RESTART", "T_SERVER", "T_SERVICE", "T_SET", "T_SHARED",
  "T_SIZE", "T_TARGET", "T_TLS", "T_UMODES", "T_UNDLINE", "T_UNLIMITED",
  "T_UNRESV", "T_UNXLINE", "T_WEBIRC", "TBOOL", "THROTTLE_COUNT",
  "THROTTLE_TIME", "TIMEOUT", "TLS_CERTIFICATE_FILE",
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
  "class_cidr_bitlen_ipv6", "class_number_per_cidr", "listen_entry", "$@8",
  "listen_flags", "$@9", "listen_flags_items", "listen_flags_item",
  "listen_items", "listen_item", "listen_port", "$@10", "port_items",
  "port_item", "listen_address", "listen_host", "auth_entry", "$@11",
  "auth_items", "auth_item", "auth_user", "auth_passwd", "auth_class",
  "auth_encrypted", "auth_flags", "$@12", "auth_flags_items",
  "auth_flags_item", "auth_spoof", "resv_entry", "$@13", "resv_items",
  "resv_item", "resv_mask", "resv_reason", "resv_exempt", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@14",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@15", "shared_types", "shared_type_item",
  "cluster_entry", "$@16", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@17", "cluster_types", "cluster_type_item",
  "connect_entry", "$@18", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_timeout", "connect_retry_delay", "connect_bind",
  "connect_send_password", "connect_accept_password",
  "connect_tls_certificate_fingerprint", "connect_port", "connect_aftype",
  "connect_flags", "$@19", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "kill_entry", "$@20", "kill_items", "kill_item",
  "kill_user", "kill_reason", "deny_entry", "$@21", "deny_items",
  "deny_item", "deny_ip", "deny_reason", "exempt_entry", "exempt_items",
  "exempt_item", "exempt_ip", "gecos_entry", "$@22", "gecos_items",
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
  "general_ident_timeout", "general_registration_timeout",
  "general_sasl_service", "cloak_entry", "cloak_items", "cloak_item",
  "cloak_enabled", "cloak_cidr_len_ipv4", "cloak_cidr_len_ipv6",
  "cloak_num_bits", "cloak_secret", "cloak_suffix", "channel_entry",
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

#define YYPACT_NINF (-641)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-130)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -641,   601,  -641,  -189,  -199,  -196,  -641,  -173,  -641,  -641,
    -171,  -641,  -166,  -641,  -641,  -641,  -149,  -136,  -641,  -641,
    -641,  -123,  -118,  -641,  -112,  -641,  -108,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,    53,   751,  -105,   398,  -101,
     -95,    12,   -89,   402,   -86,   -77,   -60,  -641,  -134,  -149,
     -55,   -40,   -19,   642,   451,    -9,    16,    -1,     7,    34,
      49,    50,    60,    64,    32,  -641,  -641,  -641,  -641,  -641,
      68,    73,    91,    98,   102,   105,   106,   108,   110,   111,
     112,   118,   121,   122,   124,   127,   144,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,   428,  -641,   128,   135,   140,   147,
     148,   149,    47,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
     568,    17,  -641,   158,    11,  -641,  -641,    22,  -641,   159,
     160,   164,   165,   168,   169,   172,   173,   174,   176,   180,
     181,   184,   185,   192,   194,   200,   201,   203,   211,   212,
     213,   214,   219,   228,   235,   236,   239,   241,   244,   245,
     246,   247,   248,   249,   250,   251,   253,   255,   256,    44,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,   303,   152,   273,   -79,    92,   146,    10,   318,    14,
    -641,   257,   258,   259,   261,   263,   264,   266,   267,     9,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   153,
     270,   271,   272,   274,   275,   277,   280,   282,   283,   284,
     289,   155,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,    19,   154,   291,    94,  -641,  -641,
    -641,    66,   260,  -641,   295,    45,  -641,  -641,   156,  -641,
      93,   130,   188,   208,  -641,   182,   -96,   229,   299,   -96,
     -96,   -96,   304,   -96,   -96,   307,   308,   309,   320,   321,
     322,   262,  -641,   325,   324,   327,   328,   330,   332,   337,
     338,   339,   346,   349,   350,   179,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   356,   357,
     380,   359,   363,   365,   364,  -641,   366,   368,   370,   371,
     372,   373,   374,  -641,   375,   376,   377,   382,   383,   384,
     387,   391,   183,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
     396,   397,    36,  -641,  -641,  -641,   385,   367,  -641,  -641,
     399,   400,    84,  -641,  -641,  -641,   -96,   404,   -96,   -96,
     408,   -96,   431,   433,   413,   414,   -96,   437,   -96,   416,
     422,   423,   424,   425,   426,   -96,   436,   438,   439,   442,
     453,   -96,   -96,   459,   -96,   445,   466,   447,   472,   473,
     454,   -96,   -96,   -96,   475,   455,   456,  -641,   458,   461,
     467,  -641,   468,   470,   471,   157,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,   476,   479,    40,  -641,  -641,  -641,
     460,   483,   491,  -641,   493,  -641,    90,  -641,  -641,  -641,
    -641,  -641,  -641,   495,  -641,  -641,  -641,   501,   503,   504,
     116,  -641,  -641,  -641,   508,   507,   509,  -641,   511,   512,
     515,   516,   517,   518,   519,   206,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,   510,   520,   521,
     522,     8,  -641,  -641,  -641,  -641,   526,   548,   -96,   529,
     552,   533,   555,   557,   537,  -641,  -641,   544,   547,   570,
     560,   546,   561,   563,   572,   574,   575,   578,   549,  -641,
     554,   550,  -641,   151,  -641,  -641,  -641,  -641,   588,   567,
    -641,   576,   577,   583,   584,   585,   586,   114,  -641,  -641,
    -641,  -641,  -641,   582,   580,  -641,   590,   587,  -641,   591,
      88,  -641,  -641,  -641,  -641,   592,   594,   595,  -641,   596,
     293,   293,   597,   -37,  -641,   598,   599,   600,   602,   603,
     604,   605,   610,   611,   612,   613,   614,   615,   616,  -641,
    -641,   618,   619,   620,   621,   627,   626,   628,   629,   -96,
     -18,   -18,   630,  -641,   636,   637,   638,   639,   640,   641,
    -641,  -641,   632,   125,   646,   606,   647,   648,   624,   649,
     650,   651,   -96,   652,   654,   -96,   655,   653,  -641,   657,
     658,   656,  -641,   659,  -641,   660,   661,   662,  -641,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,   685,   686,   687,   688,   689,   690,   691,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   702,  -641,
    -641,   706,   727,   703,   709,   710,   711,   712,  -641,   713,
     714,   715,  -641,  -641,   716,   717,   707,   651,   718,  -641,
     -79,  -641,   719,   720,   721,  -641,  -641,   722,   743,   723,
     725,   726,   729,   730,   747,   731,   732,   733,  -641,  -641,
     734,   735,   737,   736,  -641,   738,   739,   740,   741,   742,
     744,   745,   746,  -641,   748,   749,   750,   752,   753,   754,
     755,   756,   757,   758,   759,  -641,  -641,   763,   728,   761,
    -641,   762,  -641,   204,  -641,   766,   767,   768,   769,   770,
    -641,   771,  -641,  -641,   772,   765,   775,   773,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,   293,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,   774,   776,   777,
     778,   779,   780,   781,   782,   783,    13,    13,   784,    99,
    -641,   785,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   786,
     787,   788,   789,   790,   791,   792,    -2,   793,   794,  -641,
     795,   796,   797,   798,   799,   800,  -641,   801,   802,  -641,
    -641,   803,   804,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,   805,   806,   268,   807,   808,   809,
    -641,   810,   811,  -641,   812,   813,    95,   170,   644,  -641,
    -641,  -641,   814,   815,  -641,   816,   817,   505,   818,   819,
     820,   821,   822,   823,   824,  -641,   825,   826,   827,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   828,
     589,  -641,  -641,   829,   830,   831,  -641,    72,  -641,  -641,
    -641,  -641,   834,   835,   836,   837,  -641,  -641,   838,   581,
     839,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,    13,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -179,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -178,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -176,  -641,   651,   651,   840,  -641,  -641,  -641,
    -641,  -641,   841,  -641,   842,  -641,   843,   844,  -641,   845,
    -641,   846,   847,  -641,  -641,   848,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -167,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -142,  -641,  -641,   833,  -169,   850,   853,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -132,  -641,  -641,  -641,    -2,  -641,
     268,  -641,    95,  -641,  -641,  -641,   882,   909,   849,   919,
     724,   916,   921,   932,  -641,   505,  -641,   589,   855,   856,
     857,   540,  -641,  -641,   581,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   858,
    -641,  -641
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   208,     0,   354,   404,
       0,   419,     0,   261,   395,   235,     0,     0,   100,   150,
     290,     0,     0,   332,     0,   109,     0,   307,     3,     4,
       5,    14,     6,    26,    27,     7,     8,    11,    12,    13,
      16,    17,    18,    19,    20,    21,    22,    23,    25,    24,
      10,     9,    15,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    95,    94,   547,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   530,   546,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   531,   532,
     542,   543,   544,   545,     0,   521,     0,     0,     0,     0,
       0,     0,     0,   514,   515,   516,   517,   518,   519,   520,
       0,     0,   417,     0,     0,   415,   416,     0,   471,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     430,   431,   432,   467,   436,   462,   463,   464,   465,   440,
     433,   434,   435,   449,   437,   438,   439,   441,   442,   466,
     444,   445,   451,   452,   446,   447,   443,   448,   459,   460,
     461,   457,   458,   450,   455,   456,   453,   454,   468,   469,
     470,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     575,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   574,   573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    77,    75,    67,    76,    69,    70,    71,
      72,    73,    74,    68,     0,     0,     0,     0,   124,   125,
     126,     0,     0,   305,     0,     0,   303,   304,     0,    96,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   529,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   211,   212,   215,   217,
     218,   219,   220,   221,   222,   213,   214,   216,     0,     0,
       0,     0,     0,     0,     0,   513,     0,     0,     0,     0,
       0,     0,     0,   385,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   367,   366,   368,   372,   369,   370,   371,   410,
       0,     0,     0,   407,   408,   409,     0,     0,   414,   425,
       0,     0,     0,   422,   423,   424,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,     0,     0,
       0,   276,     0,     0,     0,     0,   264,   265,   266,   267,
     270,   268,   269,   401,     0,     0,     0,   398,   399,   400,
       0,     0,     0,   237,     0,   249,     0,   247,   248,   250,
     251,    63,    62,    59,    61,    56,    55,     0,     0,     0,
       0,   103,   104,   105,     0,     0,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   160,   161,   162,   159,   158,   163,     0,     0,     0,
       0,     0,   293,   294,   295,   296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   565,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,   340,     0,   335,   336,   337,   127,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   112,   113,
     115,   114,   116,     0,     0,   302,     0,     0,   317,     0,
       0,   310,   311,   312,   313,     0,     0,     0,    90,     0,
       0,    30,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
     223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   210,     0,     0,     0,     0,     0,     0,
     512,   373,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   356,     0,
       0,     0,   406,     0,   413,     0,     0,     0,   421,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   428,
     271,     0,     0,     0,     0,     0,     0,     0,   263,     0,
       0,     0,   397,   252,     0,     0,     0,     0,     0,   246,
       0,   106,     0,     0,     0,   102,   164,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   297,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
       0,     0,     0,   564,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,   338,     0,     0,     0,
     334,     0,   122,     0,   117,     0,     0,     0,     0,     0,
     111,     0,   301,   314,     0,     0,     0,     0,   309,    99,
      98,    97,   562,    36,    37,    38,    39,    40,    35,    34,
     563,     0,    33,   548,   549,   550,   551,   552,   553,   554,
     555,   558,   559,   556,   557,   560,   561,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,    42,
      43,     0,   209,   523,   524,   522,   525,   526,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,   355,     0,     0,   405,
     418,     0,     0,   420,   485,   472,   473,   493,   507,   508,
     501,   500,   476,   477,   509,   488,   480,   478,   479,   483,
     484,   474,   482,   481,   498,   505,   506,   504,   494,   492,
     495,   499,   510,   511,   496,   497,   490,   491,   502,   503,
     487,   486,   489,   475,     0,     0,     0,     0,     0,     0,
     262,     0,     0,   396,     0,     0,     0,   257,   253,   256,
     236,    60,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,     0,     0,     0,   291,
     579,   576,   577,   578,   583,   582,   580,   581,    86,    83,
      89,    82,    87,    88,    81,    85,    84,    79,    80,     0,
       0,   333,   128,     0,     0,     0,   140,     0,   132,   133,
     135,   134,     0,     0,     0,     0,   110,   306,     0,     0,
       0,   308,   232,   233,   228,   229,   224,   234,   227,   226,
     225,    47,    48,    49,    50,    51,    52,    53,    46,    45,
     230,     0,    44,   231,   380,   383,   384,   394,   391,   375,
     392,   389,   390,     0,   388,   393,   374,   382,   377,   379,
     378,   376,   381,   411,   412,   426,   427,   274,   275,   284,
     280,   281,   283,   288,   285,   286,   287,   282,     0,   279,
     273,   289,   272,   403,   402,   260,   259,   244,   245,   242,
     243,   241,     0,   240,     0,     0,     0,   107,   108,   172,
     169,   194,     0,   205,   181,   190,     0,   179,   184,     0,
     199,     0,   193,   197,   203,   183,   186,   195,   196,   200,
     191,   198,   187,   204,   189,   185,   188,     0,   177,   165,
     167,   173,   170,   171,   166,   168,   300,   298,   299,   339,
     344,   350,   353,   346,   352,   347,   351,   349,   345,   348,
       0,   343,   136,     0,     0,     0,     0,   131,   119,   118,
     120,   121,   315,   321,   327,   328,   331,   323,   330,   324,
     329,   326,   322,   325,     0,   320,   316,   386,     0,   277,
       0,   238,     0,   258,   255,   254,     0,     0,     0,     0,
       0,     0,     0,     0,   175,     0,   341,     0,     0,     0,
       0,     0,   130,   318,     0,   387,   278,   239,   207,   180,
     202,   178,   206,   201,   192,   182,   176,   342,   137,   139,
     138,   148,   147,   143,   145,   149,   146,   142,   144,     0,
     319,   141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -641,  -641,  -641,  -307,  -641,   278,   388,  -621,  -641,   -28,
     131,  -640,  -641,  -641,   878,  -641,  -641,   150,  -641,  -641,
     832,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,   869,  -641,  -641,  -641,  -641,  -641,
    -641,   579,  -641,  -641,  -641,  -641,  -641,   394,  -641,  -641,
    -641,  -641,  -641,  -641,   851,  -641,  -641,  -641,  -641,   103,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   566,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,   -83,  -641,  -641,  -641,   760,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,   -69,  -641,   607,  -641,  -641,  -641,    20,  -641,
    -641,  -641,  -641,  -641,   622,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,   -66,  -641,  -641,  -641,  -641,   558,  -641,  -641,
    -641,  -641,  -641,   852,  -641,  -641,  -641,  -641,   496,  -641,
    -641,  -641,  -641,  -641,   -84,  -641,  -641,  -641,   525,  -641,
    -641,  -641,  -641,   -76,  -641,  -641,  -641,   764,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,   -56,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   623,
    -641,  -641,  -641,  -641,  -641,   704,  -641,  -641,  -641,  -641,
     940,  -641,  -641,  -641,  -641,   705,  -641,  -641,  -641,  -641,
     896,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,   954,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,   981,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,   859,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    28,   592,   593,   594,   799,   828,   829,   830,
     999,   917,    29,    30,    68,   235,   483,   484,    31,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,    32,    84,    85,    86,    87,    88,    33,    70,
     490,   491,   492,   493,    34,    77,   567,   568,   569,   570,
     571,   572,    35,   287,   288,   289,   290,   291,   967,   968,
     969,   970,   971,  1115,  1189,    36,    71,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   729,
    1087,  1088,    37,    57,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,    38,    66,   475,
     716,  1052,  1053,   476,   477,   478,  1056,   918,   919,   479,
     480,    39,    64,   455,   456,   457,   458,   459,   460,   461,
     703,  1038,  1039,   462,    40,    72,   521,   522,   523,   524,
     525,    41,   295,   296,   297,    42,    79,   580,   581,   582,
     583,   584,   785,  1134,  1135,    43,    75,   553,   554,   555,
     556,   768,  1110,  1111,    44,    59,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   638,
    1013,  1014,   385,   386,   387,   388,    45,    65,   466,   467,
     468,   469,    46,    60,   392,   393,   394,   395,    47,   144,
     145,   146,    48,    62,   402,   403,   404,   405,    49,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,    50,   132,   133,   134,   135,   136,   137,   138,   139,
      51,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,    52,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     831,   850,   597,   598,   599,  1011,   601,   602,   293,   517,
     240,   487,   142,   142,  1159,   517,    55,   285,   389,    56,
     550,    53,    54,   399,   991,   992,   993,   994,   995,   996,
     997,  1137,  1139,    80,  1141,  1138,  1140,   389,  1142,   826,
     827,   463,    58,  1154,    61,   148,   293,  1155,   125,    63,
     149,   241,   150,   151,    80,   481,   482,   518,    67,   242,
     243,   244,   152,   518,   245,   246,   247,   248,  1156,    81,
     126,   127,  1157,   963,   153,   154,    69,    82,  1163,   234,
     143,   143,  1164,   155,   156,   399,   390,   157,   158,   576,
      81,   470,    73,   128,   519,   285,   488,    74,    82,   659,
     519,   661,   662,    76,   664,   390,   159,    78,   160,   669,
     124,   671,   590,   591,   140,   562,   294,   487,   678,   161,
     141,  1047,   162,   163,   684,   685,   147,   687,   551,   231,
    1048,   400,   164,   165,   694,   695,   696,   520,   232,   166,
     167,    83,   168,   520,   169,    89,   391,   170,   171,   471,
    1049,   401,   550,   463,   294,   233,   259,   576,   448,   472,
     237,   473,    83,   129,   172,   391,   173,   174,   175,   464,
     176,   590,   801,   489,   177,   238,    90,    91,  1012,  -129,
     323,   964,   449,   178,   356,    92,   357,   130,   358,   260,
     826,   827,   261,   400,   179,   180,   239,   577,   181,   182,
     324,   325,   488,   131,   450,   963,   284,   494,   359,    93,
      94,    95,    96,   401,   292,   262,   286,   552,   474,   743,
     534,   747,   397,   563,    97,    98,    99,   263,   451,   561,
     360,   495,   183,   184,   100,   101,   102,   103,   104,   185,
     186,   465,   361,   303,   362,   105,   187,   651,   188,   298,
     965,   711,   264,   496,   363,   446,   574,  -129,   354,   299,
     551,   562,   300,   265,   266,   577,   364,   267,   268,  1050,
     966,   326,   301,   564,   470,  1051,   302,   497,   327,   489,
     305,   464,   452,  1116,   565,   306,   578,  1029,   328,   579,
     840,   841,   365,   566,   286,   657,   329,   330,   331,   787,
     585,   718,   485,   307,   448,   559,   332,   826,  1001,   453,
     308,   366,   825,   964,   309,   498,  1030,   310,   311,   494,
     312,   367,   313,   314,   315,   779,   333,   724,   449,   368,
     316,   499,   471,   317,   318,   851,   319,   586,   854,   320,
     348,   369,   472,   495,   473,  1031,   269,   349,   270,   552,
     450,   334,   350,   465,   578,   321,   486,   579,   454,   351,
     352,   353,   769,   536,   557,   496,   548,  1054,   707,   563,
     396,   406,   407,   370,   451,   371,   408,   409,  1032,  1033,
     410,   411,   965,  1034,   412,   413,   414,   500,   415,   497,
     622,   589,   416,   417,   647,   587,   418,   419,   501,   125,
     502,   474,   966,   148,   420,  1035,   421,   503,   149,   504,
     150,   151,   422,   423,  1143,   424,   595,   737,   588,   564,
     152,   126,   127,   425,   426,   427,   428,   498,   452,   323,
     565,   429,   153,   154,   793,   794,   795,   796,   797,   566,
     430,   155,   156,   499,   128,   157,   158,   431,   432,   324,
     325,   433,   259,   434,  1036,   453,   435,   436,   437,   438,
     439,   440,   441,   442,   159,   443,   160,   444,   445,   526,
     527,   528,   609,   529,  1037,   530,   531,   161,   532,   533,
     162,   163,   537,   538,   539,   260,   540,   541,   261,   542,
     164,   165,   543,  1160,   544,   545,   546,   166,   167,   500,
     168,   547,   169,   558,   454,   170,   171,   573,   596,  1061,
     501,   262,   502,   600,   129,  1062,   603,   604,   605,   503,
     326,   504,   172,   263,   173,   174,   175,   327,   176,   606,
     607,   608,   177,  1063,  1064,   610,   611,   328,   130,   612,
     613,   178,   614,  1065,   615,   329,   330,   331,   264,   616,
     617,   618,   179,   180,   131,   332,   181,   182,   619,   265,
     266,   620,   621,   267,   268,   624,   625,   626,   627,   356,
     628,   357,   629,   358,   630,   333,   631,   654,  1066,  1067,
     632,  1068,   633,   634,   635,   636,   637,   639,   640,   641,
     183,   184,   653,   359,   642,   643,   644,   185,   186,   645,
     334,     2,     3,   646,   187,     4,   188,  1069,   649,   650,
    1070,   655,   656,   660,  1181,   360,  1182,   663,   665,  1071,
     666,     5,   667,   668,   670,   672,     6,   361,     7,   362,
       8,   673,   674,   675,   676,   677,  1072,     9,  1073,   363,
     683,  1074,   269,   240,   270,   679,   686,   680,   681,   682,
      10,   364,   688,   689,    11,    12,   690,  1123,  1075,   691,
     692,  1183,   697,   693,   698,  1100,   699,  1076,   700,  1077,
     713,    13,  1078,   701,  1079,    14,  1184,   365,  1080,   702,
     704,  1081,   705,   706,   241,    15,    16,  1082,   709,  1083,
    1084,   710,   242,   243,   244,   714,   366,   245,   246,   247,
     248,  1185,  1186,   715,  1085,   717,   367,    17,    18,   720,
    1086,   721,  1124,   745,   368,   722,   723,  1125,   726,   727,
     739,   728,    19,   730,   731,  1101,   369,   732,   733,   734,
     735,   736,   740,   741,   742,   746,   748,    20,  1126,   749,
     750,  1187,   751,  1127,   752,  1188,  1102,   753,  1128,    21,
      22,  1103,    89,   754,   755,   758,  1104,   756,   370,   765,
     371,    23,   767,  1129,   766,  1130,  1131,   757,   759,    24,
     760,  1105,    25,  1106,  1107,   771,    26,   772,    27,   761,
    1132,   762,   763,    90,    91,   764,  1133,   774,  1108,   781,
     782,   773,    92,   843,  1109,   775,   776,   777,   778,   784,
     783,  1002,   789,   786,   790,   791,   792,   800,   803,   804,
     805,  1172,   806,   807,   808,   809,    93,    94,    95,    96,
     810,   811,   812,   813,   814,   815,   816,   817,   818,   819,
     820,    97,    98,    99,   821,   822,   846,   823,   824,   839,
     832,   100,   101,   102,   103,   104,   833,   834,   835,   836,
     837,   838,   105,   842,   844,   845,   847,   848,  1055,   852,
     849,   853,   855,   856,   857,   858,   859,   861,   862,   860,
     921,   802,   863,   864,   865,   866,   867,   868,   869,   870,
     871,   872,   873,   874,   875,   876,   877,   878,   879,   880,
     881,   882,   883,   884,   885,   886,   887,   888,   889,   890,
     891,   892,   893,   894,   895,   896,   897,   898,   899,   900,
     901,   902,   903,   904,   905,   906,   907,   908,   909,   916,
     911,   912,   910,   914,   915,   913,   922,   923,   920,   925,
     926,   924,   928,   929,   932,   927,   930,   931,   933,   934,
     960,   936,   937,   935,   938,  1168,   939,   236,   940,   941,
     942,   943,   944,   304,   945,   946,   947,   998,   948,   949,
     950,   780,   951,   952,   953,   954,   955,   956,   957,   958,
     959,   961,   962,   972,   973,   974,   975,   979,   798,   978,
     976,   977,   980,   981,   982,  1170,   983,   984,   985,   986,
     987,   988,   989,   990,  1000,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,  1010,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1040,  1041,  1042,
    1043,  1044,  1045,  1046,  1057,  1058,  1059,  1060,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1112,
    1158,  1169,  1113,  1114,  1118,  1119,  1120,  1121,  1122,  1136,
    1145,  1171,  1173,  1174,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1153,  1161,  1162,  1175,  1178,  1179,  1180,  1191,   725,
    1117,   738,  1176,  1167,  1166,  1144,   788,   708,   770,   744,
    1190,  1177,  1165,   719,   398,   447,   355,   322,     0,   712,
       0,     0,     0,     0,     0,   623,   652,     0,     0,     0,
       0,     0,     0,   549,     0,     0,     0,   658,   535,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   648,     0,   560,     0,
       0,     0,     0,     0,     0,     0,     0,   575
};

static const yytype_int16 yycheck[] =
{
     621,   641,   309,   310,   311,     7,   313,   314,     1,     1,
       1,     1,     1,     1,   183,     1,   215,     1,     1,   215,
       1,   210,   211,     1,    11,    12,    13,    14,    15,    16,
      17,   210,   210,     1,   210,   214,   214,     1,   214,   208,
     209,     1,   215,   210,   215,     1,     1,   214,     1,   215,
       6,    42,     8,     9,     1,   134,   135,    49,   207,    50,
      51,    52,    18,    49,    55,    56,    57,    58,   210,    37,
      23,    24,   214,     1,    30,    31,   212,    45,   210,   213,
      69,    69,   214,    39,    40,     1,    69,    43,    44,     1,
      37,     1,   215,    46,    86,     1,    86,   215,    45,   406,
      86,   408,   409,   215,   411,    69,    62,   215,    64,   416,
     215,   418,   208,   209,   215,     1,   109,     1,   425,    75,
     215,    26,    78,    79,   431,   432,   215,   434,   109,   215,
      35,   109,    88,    89,   441,   442,   443,   129,   215,    95,
      96,   109,    98,   129,   100,     1,   129,   103,   104,    59,
      55,   129,     1,     1,   109,   215,     1,     1,     1,    69,
     215,    71,   109,   116,   120,   129,   122,   123,   124,   129,
     126,   208,   209,   163,   130,   215,    32,    33,   180,   163,
       1,   109,    25,   139,     1,    41,     3,   140,     5,    34,
     208,   209,    37,   109,   150,   151,   215,   109,   154,   155,
      21,    22,    86,   156,    47,     1,   215,     1,    25,    65,
      66,    67,    68,   129,   215,    60,   200,   198,   128,   211,
     211,   528,   211,   109,    80,    81,    82,    72,    71,   163,
      47,    25,   188,   189,    90,    91,    92,    93,    94,   195,
     196,   201,    59,   211,    61,   101,   202,   211,   204,   215,
     178,   211,    97,    47,    71,   211,   211,   163,   211,   210,
     109,     1,   212,   108,   109,   109,    83,   112,   113,   174,
     198,    92,   212,   159,     1,   180,   212,    71,    99,   163,
     212,   129,   125,   211,   170,   212,   198,    19,   109,   201,
     165,   166,   109,   179,   200,   211,   117,   118,   119,   211,
     207,   211,   210,   212,     1,   211,   127,   208,   209,   152,
     212,   128,   619,   109,   212,   109,    48,   212,   212,     1,
     212,   138,   212,   212,   212,   211,   147,   211,    25,   146,
     212,   125,    59,   212,   212,   642,   212,   207,   645,   212,
     212,   158,    69,    25,    71,    77,   191,   212,   193,   198,
      47,   172,   212,   201,   198,   211,   210,   201,   201,   212,
     212,   212,   211,   210,   210,    47,   211,   197,   211,   109,
     212,   212,   212,   190,    71,   192,   212,   212,   110,   111,
     212,   212,   178,   115,   212,   212,   212,   181,   212,    71,
     211,   209,   212,   212,   211,   207,   212,   212,   192,     1,
     194,   128,   198,     1,   212,   137,   212,   201,     6,   203,
       8,     9,   212,   212,  1054,   212,   187,   211,   210,   159,
      18,    23,    24,   212,   212,   212,   212,   109,   125,     1,
     170,   212,    30,    31,   141,   142,   143,   144,   145,   179,
     212,    39,    40,   125,    46,    43,    44,   212,   212,    21,
      22,   212,     1,   212,   186,   152,   212,   212,   212,   212,
     212,   212,   212,   212,    62,   212,    64,   212,   212,   212,
     212,   212,   210,   212,   206,   212,   212,    75,   212,   212,
      78,    79,   212,   212,   212,    34,   212,   212,    37,   212,
      88,    89,   212,  1114,   212,   212,   212,    95,    96,   181,
      98,   212,   100,   212,   201,   103,   104,   212,   209,     4,
     192,    60,   194,   209,   116,    10,   209,   209,   209,   201,
      92,   203,   120,    72,   122,   123,   124,    99,   126,   209,
     209,   209,   130,    28,    29,   210,   212,   109,   140,   212,
     212,   139,   212,    38,   212,   117,   118,   119,    97,   212,
     212,   212,   150,   151,   156,   127,   154,   155,   212,   108,
     109,   212,   212,   112,   113,   209,   209,   187,   209,     1,
     207,     3,   207,     5,   210,   147,   210,   210,    73,    74,
     212,    76,   212,   212,   212,   212,   212,   212,   212,   212,
     188,   189,   207,    25,   212,   212,   212,   195,   196,   212,
     172,     0,     1,   212,   202,     4,   204,   102,   212,   212,
     105,   212,   212,   209,    74,    47,    76,   209,   187,   114,
     187,    20,   209,   209,   187,   209,    25,    59,    27,    61,
      29,   209,   209,   209,   209,   209,   131,    36,   133,    71,
     187,   136,   191,     1,   193,   209,   187,   209,   209,   207,
      49,    83,   207,   187,    53,    54,   209,    76,   153,   187,
     187,   121,   187,   209,   209,    76,   210,   162,   210,   164,
     210,    70,   167,   212,   169,    74,   136,   109,   173,   212,
     212,   176,   212,   212,    42,    84,    85,   182,   212,   184,
     185,   212,    50,    51,    52,   212,   128,    55,    56,    57,
      58,   161,   162,   212,   199,   212,   138,   106,   107,   214,
     205,   210,   131,   187,   146,   212,   212,   136,   210,   212,
     210,   212,   121,   212,   212,   136,   158,   212,   212,   212,
     212,   212,   212,   212,   212,   187,   207,   136,   157,   187,
     207,   201,   187,   162,   187,   205,   157,   210,   167,   148,
     149,   162,     1,   209,   207,   209,   167,   187,   190,   210,
     192,   160,   212,   182,   210,   184,   185,   207,   207,   168,
     207,   182,   171,   184,   185,   187,   175,   210,   177,   207,
     199,   207,   207,    32,    33,   207,   205,   210,   199,   207,
     210,   215,    41,   187,   205,   212,   212,   212,   212,   212,
     210,   829,   210,   212,   210,   210,   210,   210,   210,   210,
     210,    87,   210,   210,   210,   210,    65,    66,    67,    68,
     210,   210,   210,   210,   210,   210,   210,   209,   209,   209,
     209,    80,    81,    82,   207,   209,   212,   209,   209,   207,
     210,    90,    91,    92,    93,    94,   210,   210,   210,   210,
     210,   210,   101,   207,   207,   207,   207,   207,   214,   207,
     209,   207,   207,   210,   207,   207,   210,   207,   207,   210,
     720,   593,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   207,   187,   212,   207,   207,   207,   212,
     207,   207,   210,   207,   207,   210,   207,   207,   210,   207,
     187,   210,   207,   207,   187,   212,   207,   207,   207,   207,
     212,   207,   207,   210,   207,    63,   210,    69,   210,   210,
     210,   210,   210,    84,   210,   210,   210,   826,   210,   210,
     210,   567,   210,   210,   210,   210,   210,   210,   210,   210,
     207,   210,   210,   207,   207,   207,   207,   212,   590,   207,
     210,   210,   207,   210,   210,   136,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     207,   132,   212,   212,   210,   210,   210,   210,   210,   210,
     210,   132,   136,   132,   213,   213,   213,   213,   213,   213,
     213,   213,   212,   210,   132,   210,   210,   210,   210,   490,
     967,   505,  1155,  1142,  1140,  1055,   580,   455,   553,   521,
    1164,  1157,  1138,   476,   144,   189,   132,   106,    -1,   466,
      -1,    -1,    -1,    -1,    -1,   335,   392,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,   402,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,   287,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   295
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   217,     0,     1,     4,    20,    25,    27,    29,    36,
      49,    53,    54,    70,    74,    84,    85,   106,   107,   121,
     136,   148,   149,   160,   168,   171,   175,   177,   218,   228,
     229,   234,   248,   254,   260,   268,   281,   298,   313,   327,
     340,   347,   351,   361,   370,   392,   398,   404,   408,   414,
     457,   466,   485,   210,   211,   215,   215,   299,   215,   371,
     399,   215,   409,   215,   328,   393,   314,   207,   230,   212,
     255,   282,   341,   215,   215,   362,   215,   261,   215,   352,
       1,    37,    45,   109,   249,   250,   251,   252,   253,     1,
      32,    33,    41,    65,    66,    67,    68,    80,    81,    82,
      90,    91,    92,    93,    94,   101,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   215,     1,    23,    24,    46,   116,
     140,   156,   458,   459,   460,   461,   462,   463,   464,   465,
     215,   215,     1,    69,   405,   406,   407,   215,     1,     6,
       8,     9,    18,    30,    31,    39,    40,    43,    44,    62,
      64,    75,    78,    79,    88,    89,    95,    96,    98,   100,
     103,   104,   120,   122,   123,   124,   126,   130,   139,   150,
     151,   154,   155,   188,   189,   195,   196,   202,   204,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   215,   215,   215,   213,   231,   230,   215,   215,   215,
       1,    42,    50,    51,    52,    55,    56,    57,    58,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,     1,
      34,    37,    60,    72,    97,   108,   109,   112,   113,   191,
     193,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   215,     1,   200,   269,   270,   271,
     272,   273,   215,     1,   109,   348,   349,   350,   215,   210,
     212,   212,   212,   211,   250,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   211,   468,     1,    21,    22,    92,    99,   109,   117,
     118,   119,   127,   147,   172,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   212,   212,
     212,   212,   212,   212,   211,   459,     1,     3,     5,    25,
      47,    59,    61,    71,    83,   109,   128,   138,   146,   158,
     190,   192,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   388,   389,   390,   391,     1,
      69,   129,   400,   401,   402,   403,   212,   211,   406,     1,
     109,   129,   410,   411,   412,   413,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   211,   416,     1,    25,
      47,    71,   125,   152,   201,   329,   330,   331,   332,   333,
     334,   335,   339,     1,   129,   201,   394,   395,   396,   397,
       1,    59,    69,    71,   128,   315,   319,   320,   321,   325,
     326,   134,   135,   232,   233,   210,   210,     1,    86,   163,
     256,   257,   258,   259,     1,    25,    47,    71,   109,   125,
     181,   192,   194,   201,   203,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,     1,    49,    86,
     129,   342,   343,   344,   345,   346,   212,   212,   212,   212,
     212,   212,   212,   212,   211,   487,   210,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   211,   236,
       1,   109,   198,   363,   364,   365,   366,   210,   212,   211,
     270,   163,     1,   109,   159,   170,   179,   262,   263,   264,
     265,   266,   267,   212,   211,   349,     1,   109,   198,   201,
     353,   354,   355,   356,   357,   207,   207,   207,   210,   209,
     208,   209,   219,   220,   221,   187,   209,   219,   219,   219,
     209,   219,   219,   209,   209,   209,   209,   209,   209,   210,
     210,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   211,   301,   209,   209,   187,   209,   207,   207,
     210,   210,   212,   212,   212,   212,   212,   212,   385,   212,
     212,   212,   212,   212,   212,   212,   212,   211,   373,   212,
     212,   211,   401,   207,   210,   212,   212,   211,   411,   219,
     209,   219,   219,   209,   219,   187,   187,   209,   209,   219,
     187,   219,   209,   209,   209,   209,   209,   209,   219,   209,
     209,   209,   207,   187,   219,   219,   187,   219,   207,   187,
     209,   187,   187,   209,   219,   219,   219,   187,   209,   210,
     210,   212,   212,   336,   212,   212,   212,   211,   330,   212,
     212,   211,   395,   210,   212,   212,   316,   212,   211,   320,
     214,   210,   212,   212,   211,   257,   210,   212,   212,   295,
     212,   212,   212,   212,   212,   212,   212,   211,   284,   210,
     212,   212,   212,   211,   343,   187,   187,   219,   207,   187,
     207,   187,   187,   210,   209,   207,   187,   207,   209,   207,
     207,   207,   207,   207,   207,   210,   210,   212,   367,   211,
     364,   187,   210,   215,   210,   212,   212,   212,   212,   211,
     263,   207,   210,   210,   212,   358,   212,   211,   354,   210,
     210,   210,   210,   141,   142,   143,   144,   145,   222,   222,
     210,   209,   221,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   209,   209,   209,
     209,   207,   209,   209,   209,   219,   208,   209,   223,   224,
     225,   223,   210,   210,   210,   210,   210,   210,   210,   207,
     165,   166,   207,   187,   207,   207,   212,   207,   207,   209,
     227,   219,   207,   207,   219,   207,   210,   207,   207,   210,
     210,   207,   207,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   207,   187,   212,   207,   207,   207,
     210,   207,   207,   210,   207,   207,   212,   227,   323,   324,
     210,   233,   207,   207,   210,   207,   187,   212,   207,   207,
     207,   207,   187,   207,   207,   210,   207,   207,   207,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   207,
     212,   210,   210,     1,   109,   178,   198,   274,   275,   276,
     277,   278,   207,   207,   207,   207,   210,   210,   207,   212,
     207,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,    11,    12,    13,    14,    15,    16,    17,   226,   226,
     210,   209,   225,   210,   210,   210,   210,   210,   210,   210,
     210,     7,   180,   386,   387,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,    19,
      48,    77,   110,   111,   115,   137,   186,   206,   337,   338,
     210,   210,   210,   210,   210,   210,   210,    26,    35,    55,
     174,   180,   317,   318,   197,   214,   322,   210,   210,   210,
     210,     4,    10,    28,    29,    38,    73,    74,    76,   102,
     105,   114,   131,   133,   136,   153,   162,   164,   167,   169,
     173,   176,   182,   184,   185,   199,   205,   296,   297,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
      76,   136,   157,   162,   167,   182,   184,   185,   199,   205,
     368,   369,   210,   212,   212,   279,   211,   275,   210,   210,
     210,   210,   210,    76,   131,   136,   157,   162,   167,   182,
     184,   185,   199,   205,   359,   360,   210,   210,   214,   210,
     214,   210,   214,   227,   324,   210,   213,   213,   213,   213,
     213,   213,   213,   213,   210,   214,   210,   214,   207,   183,
     223,   212,   210,   210,   214,   387,   338,   318,    63,   132,
     136,   132,    87,   136,   132,   132,   297,   369,   210,   210,
     210,    74,    76,   121,   136,   161,   162,   201,   205,   280,
     360,   210
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   216,   217,   217,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     219,   219,   220,   220,   221,   221,   222,   222,   222,   222,
     222,   223,   223,   224,   224,   225,   225,   226,   226,   226,
     226,   226,   226,   226,   227,   228,   229,   230,   231,   231,
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
     297,   297,   297,   297,   297,   297,   297,   297,   299,   298,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   314,   313,   316,   315,   317,
     317,   318,   318,   318,   318,   318,   319,   319,   320,   320,
     320,   320,   320,   322,   321,   323,   323,   324,   324,   325,
     326,   328,   327,   329,   329,   330,   330,   330,   330,   330,
     330,   330,   331,   332,   333,   334,   336,   335,   337,   337,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   339,
     341,   340,   342,   342,   343,   343,   343,   343,   344,   345,
     346,   347,   348,   348,   349,   349,   350,   352,   351,   353,
     353,   354,   354,   354,   354,   355,   356,   358,   357,   359,
     359,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   362,   361,   363,   363,   364,   364,   364,   365,
     367,   366,   368,   368,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   371,   370,   372,   372,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   383,   385,   384,   386,   386,   387,
     387,   388,   389,   390,   391,   393,   392,   394,   394,   395,
     395,   395,   396,   397,   399,   398,   400,   400,   401,   401,
     401,   402,   403,   404,   405,   405,   406,   406,   407,   409,
     408,   410,   410,   411,   411,   411,   412,   413,   414,   415,
     415,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   458,   459,   459,   459,   459,   459,
     459,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     467,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   486,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   488,   489,   490,   491,
     492,   493,   494,   495
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
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     6,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     0,     5,     3,     1,     1,     3,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
#line 400 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3160 "conf_parser.c"
        break;

    case YYSYMBOL_module_string: /* module_string  */
#line 400 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3166 "conf_parser.c"
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
#line 437 "conf_parser.y"
{
  if ((yyvsp[0].number) != 0)
  {
    yyerror("Nonzero durations require a unit");
    YYERROR;
  }

  (yyval.number) = 0;
}
#line 3447 "conf_parser.c"
    break;

  case 33: /* time_components: time_components time_component  */
#line 448 "conf_parser.y"
{
  if (!_conf_parser_quantity_add((yyvsp[-1].number), (yyvsp[0].number), 1U, &(yyval.number)))
  {
    yyerror("Duration out of range");
    YYERROR;
  }
}
#line 3459 "conf_parser.c"
    break;

  case 34: /* time_component: NUMBER time_unit  */
#line 457 "conf_parser.y"
{
  if (!_conf_parser_quantity_add(0, (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Duration out of range");
    YYERROR;
  }
}
#line 3471 "conf_parser.c"
    break;

  case 35: /* time_component: DECIMAL time_unit  */
#line 464 "conf_parser.y"
{
  const enum conf_quantity_status status = _conf_parser_quantity_from_decimal((yyvsp[-1].string), (yyvsp[0].number), &(yyval.number));
  io_free((yyvsp[-1].string));

  if (status != CONF_QUANTITY_OK)
  {
    yyerror(status == CONF_QUANTITY_INEXACT ? "Duration component must resolve to whole seconds" : "Duration out of range");
    YYERROR;
  }
}
#line 3486 "conf_parser.c"
    break;

  case 36: /* time_unit: SECONDS  */
#line 475 "conf_parser.y"
                   { (yyval.number) = 1U; }
#line 3492 "conf_parser.c"
    break;

  case 37: /* time_unit: MINUTES  */
#line 476 "conf_parser.y"
                   { (yyval.number) = 60U; }
#line 3498 "conf_parser.c"
    break;

  case 38: /* time_unit: HOURS  */
#line 477 "conf_parser.y"
                   { (yyval.number) = 60U * 60U; }
#line 3504 "conf_parser.c"
    break;

  case 39: /* time_unit: DAYS  */
#line 478 "conf_parser.y"
                   { (yyval.number) = 60U * 60U * 24U; }
#line 3510 "conf_parser.c"
    break;

  case 40: /* time_unit: WEEKS  */
#line 479 "conf_parser.y"
                   { (yyval.number) = 60U * 60U * 24U * 7U; }
#line 3516 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER  */
#line 483 "conf_parser.y"
{
  if ((yyvsp[0].number) != 0)
  {
    yyerror("Nonzero sizes require a unit");
    YYERROR;
  }

  (yyval.number) = 0;
}
#line 3530 "conf_parser.c"
    break;

  case 44: /* size_components: size_components size_component  */
#line 494 "conf_parser.y"
{
  if (!_conf_parser_quantity_add((yyvsp[-1].number), (yyvsp[0].number), 1U, &(yyval.number)))
  {
    yyerror("Size out of range");
    YYERROR;
  }
}
#line 3542 "conf_parser.c"
    break;

  case 45: /* size_component: NUMBER size_unit  */
#line 503 "conf_parser.y"
{
  if (!_conf_parser_quantity_add(0, (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Size out of range");
    YYERROR;
  }
}
#line 3554 "conf_parser.c"
    break;

  case 46: /* size_component: DECIMAL size_unit  */
#line 510 "conf_parser.y"
{
  const enum conf_quantity_status status = _conf_parser_quantity_from_decimal((yyvsp[-1].string), (yyvsp[0].number), &(yyval.number));
  io_free((yyvsp[-1].string));

  if (status != CONF_QUANTITY_OK)
  {
    yyerror(status == CONF_QUANTITY_INEXACT ? "Size component must resolve to whole bytes" : "Size out of range");
    YYERROR;
  }
}
#line 3569 "conf_parser.c"
    break;

  case 47: /* size_unit: BYTES  */
#line 521 "conf_parser.y"
                   { (yyval.number) = 1U; }
#line 3575 "conf_parser.c"
    break;

  case 48: /* size_unit: KBYTES  */
#line 522 "conf_parser.y"
                   { (yyval.number) = 1000U; }
#line 3581 "conf_parser.c"
    break;

  case 49: /* size_unit: KIBYTES  */
#line 523 "conf_parser.y"
                   { (yyval.number) = 1024U; }
#line 3587 "conf_parser.c"
    break;

  case 50: /* size_unit: MBYTES  */
#line 524 "conf_parser.y"
                   { (yyval.number) = 1000U * 1000U; }
#line 3593 "conf_parser.c"
    break;

  case 51: /* size_unit: MIBYTES  */
#line 525 "conf_parser.y"
                   { (yyval.number) = 1024U * 1024U; }
#line 3599 "conf_parser.c"
    break;

  case 52: /* size_unit: GBYTES  */
#line 526 "conf_parser.y"
                   { (yyval.number) = 1000U * 1000U * 1000U; }
#line 3605 "conf_parser.c"
    break;

  case 53: /* size_unit: GIBYTES  */
#line 527 "conf_parser.y"
                   { (yyval.number) = 1024U * 1024U * 1024U; }
#line 3611 "conf_parser.c"
    break;

  case 54: /* port_number: NUMBER  */
#line 531 "conf_parser.y"
{
  if ((yyvsp[0].number) > UINT16_MAX)
  {
    yyerror("Port out of range");
    YYERROR;
  }

  (yyval.number) = (yyvsp[0].number);
}
#line 3625 "conf_parser.c"
    break;

  case 55: /* module_base_path_entry: MODULE_BASE_PATH '=' module_string ';'  */
#line 546 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct module_error_info error;
    if (module_config_set_base_path(conf_parser_ctx.module_config, (yyvsp[-1].string), &error) != MODULE_SUCCESS)
      conf_report_module_error(error.message);
  }
  io_free((yyvsp[-1].string));
}
#line 3639 "conf_parser.c"
    break;

  case 56: /* loadmodule_entry: LOADMODULE module_string module_attributes ';'  */
#line 561 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct module_error_info error;
    if (module_config_add(conf_parser_ctx.module_config, (yyvsp[-2].string), (module_flags_t)(yyvsp[-1].number), &error) != MODULE_SUCCESS)
      conf_report_module_error(error.message);
  }
  io_free((yyvsp[-2].string));
}
#line 3653 "conf_parser.c"
    break;

  case 57: /* module_string: QSTRING  */
#line 573 "conf_parser.y"
{
  (yyval.string) = io_strdup((yyvsp[0].string));
}
#line 3661 "conf_parser.c"
    break;

  case 58: /* module_attributes: %empty  */
#line 578 "conf_parser.y"
{
  (yyval.number) = 0;
}
#line 3669 "conf_parser.c"
    break;

  case 59: /* module_attributes: ':' module_attributes_items  */
#line 581 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3677 "conf_parser.c"
    break;

  case 60: /* module_attributes_items: module_attributes_items ',' module_attributes_item  */
#line 586 "conf_parser.y"
{
  (yyval.number) = (yyvsp[-2].number) | (yyvsp[0].number);
}
#line 3685 "conf_parser.c"
    break;

  case 61: /* module_attributes_items: module_attributes_item  */
#line 589 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3693 "conf_parser.c"
    break;

  case 62: /* module_attributes_item: RESIDENT  */
#line 594 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_DEACTIVATE;
}
#line 3701 "conf_parser.c"
    break;

  case 63: /* module_attributes_item: REQUIRED  */
#line 597 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_REMOVE;
}
#line 3709 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 623 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3721 "conf_parser.c"
    break;

  case 80: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 632 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3733 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 641 "conf_parser.y"
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
#line 3750 "conf_parser.c"
    break;

  case 82: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 655 "conf_parser.y"
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
#line 3767 "conf_parser.c"
    break;

  case 83: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 669 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3780 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 679 "conf_parser.y"
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
#line 3797 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 693 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3809 "conf_parser.c"
    break;

  case 86: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 702 "conf_parser.y"
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
#line 3835 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 725 "conf_parser.y"
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
#line 3861 "conf_parser.c"
    break;

  case 88: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 748 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3873 "conf_parser.c"
    break;

  case 89: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 757 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = (yyvsp[-1].boolean);
}
#line 3882 "conf_parser.c"
    break;

  case 97: /* admin_name: NAME '=' QSTRING ';'  */
#line 775 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3894 "conf_parser.c"
    break;

  case 98: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 784 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3906 "conf_parser.c"
    break;

  case 99: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 793 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3918 "conf_parser.c"
    break;

  case 100: /* $@1: %empty  */
#line 806 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3927 "conf_parser.c"
    break;

  case 101: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 810 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3944 "conf_parser.c"
    break;

  case 107: /* motd_mask: MASK '=' QSTRING ';'  */
#line 827 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3953 "conf_parser.c"
    break;

  case 108: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 833 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3962 "conf_parser.c"
    break;

  case 109: /* $@2: %empty  */
#line 843 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3971 "conf_parser.c"
    break;

  case 110: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 847 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.command.buf[0] ||
      !block_state.name.buf[0] ||
      !block_state.nick.buf[0] ||
      !block_state.host.buf[0])
    break;

  const command_result_t result =
    pseudo_register(block_state.name.buf, block_state.nick.buf, block_state.host.buf,
                    block_state.prepend.buf, block_state.command.buf);

  char message[IRCD_BUFSIZE];
  switch (result)
  {
    case COMMAND_SUCCESS:
      break;
    case COMMAND_INVALID_NAME:
      snprintf(message, sizeof(message), "Invalid pseudo::command: %s", block_state.command.buf);
      conf_report_error(message);
      break;
    case COMMAND_ALREADY_REGISTERED:
      snprintf(message, sizeof(message), "Pseudo command %s is already registered", block_state.command.buf);
      conf_report_error(message);
      break;
  }
}
#line 4005 "conf_parser.c"
    break;

  case 118: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 4014 "conf_parser.c"
    break;

  case 119: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 887 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4023 "conf_parser.c"
    break;

  case 120: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 4032 "conf_parser.c"
    break;

  case 121: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 899 "conf_parser.y"
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
#line 4054 "conf_parser.c"
    break;

  case 128: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 928 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = (yyvsp[-1].boolean);
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 4066 "conf_parser.c"
    break;

  case 129: /* $@3: %empty  */
#line 937 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4075 "conf_parser.c"
    break;

  case 130: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 941 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 4088 "conf_parser.c"
    break;

  case 137: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 957 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 4099 "conf_parser.c"
    break;

  case 138: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 965 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 4107 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 968 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 4115 "conf_parser.c"
    break;

  case 140: /* $@4: %empty  */
#line 973 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 4124 "conf_parser.c"
    break;

  case 142: /* logging_file_type_item: USER  */
#line 979 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4133 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: OPERATOR  */
#line 983 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4142 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: XLINE  */
#line 987 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4151 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: RESV  */
#line 991 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4160 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: T_DLINE  */
#line 995 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4169 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: KLINE  */
#line 999 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4178 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KILL  */
#line 1003 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4187 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: T_DEBUG  */
#line 1007 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4196 "conf_parser.c"
    break;

  case 150: /* $@5: %empty  */
#line 1017 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4208 "conf_parser.c"
    break;

  case 151: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 1024 "conf_parser.y"
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
#line 4266 "conf_parser.c"
    break;

  case 165: /* oper_name: NAME '=' QSTRING ';'  */
#line 1092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4275 "conf_parser.c"
    break;

  case 166: /* oper_user: USER '=' QSTRING ';'  */
#line 1098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4284 "conf_parser.c"
    break;

  case 167: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4293 "conf_parser.c"
    break;

  case 168: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1110 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4302 "conf_parser.c"
    break;

  case 169: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1116 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].boolean))
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4316 "conf_parser.c"
    break;

  case 170: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1127 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4325 "conf_parser.c"
    break;

  case 171: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1133 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].boolean))
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4339 "conf_parser.c"
    break;

  case 172: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1144 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4348 "conf_parser.c"
    break;

  case 173: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1150 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4357 "conf_parser.c"
    break;

  case 174: /* $@6: %empty  */
#line 1156 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4366 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: KILL ':' REMOTE  */
#line 1163 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4375 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: KILL  */
#line 1167 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4384 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1171 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4393 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: CONNECT  */
#line 1175 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4402 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1179 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4411 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: SQUIT  */
#line 1183 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4420 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: KLINE  */
#line 1187 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4429 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: UNKLINE  */
#line 1191 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4438 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_DLINE  */
#line 1195 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4447 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_UNDLINE  */
#line 1199 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4456 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: XLINE  */
#line 1203 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4465 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_UNXLINE  */
#line 1207 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4474 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: DIE  */
#line 1211 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4483 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_RESTART  */
#line 1215 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4492 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1219 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4501 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REHASH  */
#line 1223 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4510 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: ADMIN  */
#line 1227 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4519 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_GLOBOPS  */
#line 1231 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4528 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_LOCOPS  */
#line 1235 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4537 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: REMOTEBAN  */
#line 1239 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4546 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: T_SET  */
#line 1243 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4555 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: MODULE  */
#line 1247 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4564 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: T_OPME  */
#line 1251 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4573 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: NICK ':' RESV  */
#line 1255 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4582 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: JOIN ':' RESV  */
#line 1259 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4591 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: RESV  */
#line 1263 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4600 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: T_UNRESV  */
#line 1267 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4609 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: CLOSE  */
#line 1271 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4618 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1275 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4627 "conf_parser.c"
    break;

  case 207: /* oper_flags_item: BYPASS ':' INPUT_FLOOD  */
#line 1279 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_BYPASS_INPUT_FLOOD;
}
#line 4636 "conf_parser.c"
    break;

  case 208: /* $@7: %empty  */
#line 1289 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4651 "conf_parser.c"
    break;

  case 209: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1299 "conf_parser.y"
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

  bool diff = (klass->cidr_bitlen_ipv4 != block_state.cidr_bitlen_ipv4.value ||
               klass->cidr_bitlen_ipv6 != block_state.cidr_bitlen_ipv6.value);
  klass->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  klass->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  klass->number_per_cidr = block_state.number_per_cidr.value;

  if (diff)
    class_ip_limit_rebuild(klass);
}
#line 4687 "conf_parser.c"
    break;

  case 224: /* class_name: NAME '=' QSTRING ';'  */
#line 1346 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4696 "conf_parser.c"
    break;

  case 225: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1352 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4705 "conf_parser.c"
    break;

  case 226: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1358 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4714 "conf_parser.c"
    break;

  case 227: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1364 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4723 "conf_parser.c"
    break;

  case 228: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1370 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4732 "conf_parser.c"
    break;

  case 229: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1376 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4741 "conf_parser.c"
    break;

  case 230: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1382 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4750 "conf_parser.c"
    break;

  case 231: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1388 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4760 "conf_parser.c"
    break;

  case 232: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1395 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4769 "conf_parser.c"
    break;

  case 233: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1401 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4778 "conf_parser.c"
    break;

  case 234: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1407 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4787 "conf_parser.c"
    break;

  case 235: /* $@8: %empty  */
#line 1416 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4796 "conf_parser.c"
    break;

  case 237: /* $@9: %empty  */
#line 1422 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4804 "conf_parser.c"
    break;

  case 241: /* listen_flags_item: T_TLS  */
#line 1428 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4813 "conf_parser.c"
    break;

  case 242: /* listen_flags_item: HIDDEN  */
#line 1432 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4822 "conf_parser.c"
    break;

  case 243: /* listen_flags_item: T_SERVER  */
#line 1436 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4831 "conf_parser.c"
    break;

  case 244: /* listen_flags_item: CLIENT  */
#line 1440 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4840 "conf_parser.c"
    break;

  case 245: /* listen_flags_item: DEFER  */
#line 1444 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4849 "conf_parser.c"
    break;

  case 253: /* $@10: %empty  */
#line 1452 "conf_parser.y"
                                 { reset_block_state(); }
#line 4855 "conf_parser.c"
    break;

  case 257: /* port_item: port_number  */
#line 1457 "conf_parser.y"
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
#line 4873 "conf_parser.c"
    break;

  case 258: /* port_item: port_number TWODOTS port_number  */
#line 1470 "conf_parser.y"
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
#line 4893 "conf_parser.c"
    break;

  case 259: /* listen_address: IP '=' QSTRING ';'  */
#line 1487 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4902 "conf_parser.c"
    break;

  case 260: /* listen_host: HOST '=' QSTRING ';'  */
#line 1493 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4911 "conf_parser.c"
    break;

  case 261: /* $@11: %empty  */
#line 1503 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4920 "conf_parser.c"
    break;

  case 262: /* auth_entry: IRCD_AUTH $@11 '{' auth_items '}' ';'  */
#line 1507 "conf_parser.y"
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
#line 4975 "conf_parser.c"
    break;

  case 272: /* auth_user: USER '=' QSTRING ';'  */
#line 1568 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4984 "conf_parser.c"
    break;

  case 273: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1574 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4993 "conf_parser.c"
    break;

  case 274: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1580 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5002 "conf_parser.c"
    break;

  case 275: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1586 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].boolean))
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5016 "conf_parser.c"
    break;

  case 276: /* $@12: %empty  */
#line 1597 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 5025 "conf_parser.c"
    break;

  case 280: /* auth_flags_item: EXCEED_LIMIT  */
#line 1605 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 5034 "conf_parser.c"
    break;

  case 281: /* auth_flags_item: KLINE_EXEMPT  */
#line 1609 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 5043 "conf_parser.c"
    break;

  case 282: /* auth_flags_item: XLINE_EXEMPT  */
#line 1613 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 5052 "conf_parser.c"
    break;

  case 283: /* auth_flags_item: NEED_IDENT  */
#line 1617 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 5061 "conf_parser.c"
    break;

  case 284: /* auth_flags_item: CAN_FLOOD  */
#line 1621 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 5070 "conf_parser.c"
    break;

  case 285: /* auth_flags_item: NO_TILDE  */
#line 1625 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 5079 "conf_parser.c"
    break;

  case 286: /* auth_flags_item: RESV_EXEMPT  */
#line 1629 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 5088 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: T_WEBIRC  */
#line 1633 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5097 "conf_parser.c"
    break;

  case 288: /* auth_flags_item: NEED_PASSWORD  */
#line 1637 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5106 "conf_parser.c"
    break;

  case 289: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1643 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    conf_report_warning("Invalid auth::spoof; ignoring value");
}
#line 5120 "conf_parser.c"
    break;

  case 290: /* $@13: %empty  */
#line 1657 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5132 "conf_parser.c"
    break;

  case 291: /* resv_entry: RESV $@13 '{' resv_items '}' ';'  */
#line 1664 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 5143 "conf_parser.c"
    break;

  case 298: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1675 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5152 "conf_parser.c"
    break;

  case 299: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1681 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5161 "conf_parser.c"
    break;

  case 300: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1687 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5170 "conf_parser.c"
    break;

  case 306: /* service_name: NAME '=' QSTRING ';'  */
#line 1702 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5185 "conf_parser.c"
    break;

  case 307: /* $@14: %empty  */
#line 1718 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5201 "conf_parser.c"
    break;

  case 308: /* shared_entry: T_SHARED $@14 '{' shared_items '}' ';'  */
#line 1729 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5216 "conf_parser.c"
    break;

  case 315: /* shared_name: NAME '=' QSTRING ';'  */
#line 1744 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5225 "conf_parser.c"
    break;

  case 316: /* shared_user: USER '=' QSTRING ';'  */
#line 1750 "conf_parser.y"
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
#line 5247 "conf_parser.c"
    break;

  case 317: /* $@15: %empty  */
#line 1769 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5256 "conf_parser.c"
    break;

  case 321: /* shared_type_item: KLINE  */
#line 1776 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5265 "conf_parser.c"
    break;

  case 322: /* shared_type_item: UNKLINE  */
#line 1780 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5274 "conf_parser.c"
    break;

  case 323: /* shared_type_item: T_DLINE  */
#line 1784 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5283 "conf_parser.c"
    break;

  case 324: /* shared_type_item: T_UNDLINE  */
#line 1788 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5292 "conf_parser.c"
    break;

  case 325: /* shared_type_item: XLINE  */
#line 1792 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5301 "conf_parser.c"
    break;

  case 326: /* shared_type_item: T_UNXLINE  */
#line 1796 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5310 "conf_parser.c"
    break;

  case 327: /* shared_type_item: REHASH  */
#line 1800 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_REHASH;
}
#line 5319 "conf_parser.c"
    break;

  case 328: /* shared_type_item: RESV  */
#line 1804 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5328 "conf_parser.c"
    break;

  case 329: /* shared_type_item: T_UNRESV  */
#line 1808 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5337 "conf_parser.c"
    break;

  case 330: /* shared_type_item: T_LOCOPS  */
#line 1812 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5346 "conf_parser.c"
    break;

  case 331: /* shared_type_item: T_ALL  */
#line 1816 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5355 "conf_parser.c"
    break;

  case 332: /* $@16: %empty  */
#line 1826 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5369 "conf_parser.c"
    break;

  case 333: /* cluster_entry: T_CLUSTER $@16 '{' cluster_items '}' ';'  */
#line 1835 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5382 "conf_parser.c"
    break;

  case 339: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1848 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5391 "conf_parser.c"
    break;

  case 340: /* $@17: %empty  */
#line 1854 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5400 "conf_parser.c"
    break;

  case 344: /* cluster_type_item: KLINE  */
#line 1861 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5409 "conf_parser.c"
    break;

  case 345: /* cluster_type_item: UNKLINE  */
#line 1865 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5418 "conf_parser.c"
    break;

  case 346: /* cluster_type_item: T_DLINE  */
#line 1869 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5427 "conf_parser.c"
    break;

  case 347: /* cluster_type_item: T_UNDLINE  */
#line 1873 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5436 "conf_parser.c"
    break;

  case 348: /* cluster_type_item: XLINE  */
#line 1877 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5445 "conf_parser.c"
    break;

  case 349: /* cluster_type_item: T_UNXLINE  */
#line 1881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5454 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: RESV  */
#line 1885 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5463 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: T_UNRESV  */
#line 1889 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5472 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: T_LOCOPS  */
#line 1893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5481 "conf_parser.c"
    break;

  case 353: /* cluster_type_item: T_ALL  */
#line 1897 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5490 "conf_parser.c"
    break;

  case 354: /* $@18: %empty  */
#line 1907 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECT_DEFAULT_TIMEOUT_SEC;
  block_state.retry_delay_sec.value = CONNECT_DEFAULT_RETRY_DELAY_SEC;
}
#line 5505 "conf_parser.c"
    break;

  case 355: /* connect_entry: CONNECT $@18 '{' connect_items '}' ';'  */
#line 1917 "conf_parser.y"
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
#line 5554 "conf_parser.c"
    break;

  case 374: /* connect_name: NAME '=' QSTRING ';'  */
#line 1981 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5563 "conf_parser.c"
    break;

  case 375: /* connect_host: HOST '=' QSTRING ';'  */
#line 1987 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5572 "conf_parser.c"
    break;

  case 376: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 1993 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5581 "conf_parser.c"
    break;

  case 377: /* connect_retry_delay: RETRY_DELAY '=' timespec ';'  */
#line 1999 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.retry_delay_sec.value = (yyvsp[-1].number);
}
#line 5590 "conf_parser.c"
    break;

  case 378: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 2005 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5599 "conf_parser.c"
    break;

  case 379: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2011 "conf_parser.y"
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
#line 5615 "conf_parser.c"
    break;

  case 380: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2024 "conf_parser.y"
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
#line 5631 "conf_parser.c"
    break;

  case 381: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2037 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5640 "conf_parser.c"
    break;

  case 382: /* connect_port: PORT '=' port_number ';'  */
#line 2043 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5649 "conf_parser.c"
    break;

  case 383: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5658 "conf_parser.c"
    break;

  case 384: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2053 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5667 "conf_parser.c"
    break;

  case 385: /* $@19: %empty  */
#line 2059 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5675 "conf_parser.c"
    break;

  case 389: /* connect_flags_item: AUTOCONN  */
#line 2065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5684 "conf_parser.c"
    break;

  case 390: /* connect_flags_item: T_TLS  */
#line 2069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5693 "conf_parser.c"
    break;

  case 391: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2075 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].boolean))
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5707 "conf_parser.c"
    break;

  case 392: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2086 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5716 "conf_parser.c"
    break;

  case 393: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5725 "conf_parser.c"
    break;

  case 394: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5734 "conf_parser.c"
    break;

  case 395: /* $@20: %empty  */
#line 2108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5743 "conf_parser.c"
    break;

  case 396: /* kill_entry: KILL $@20 '{' kill_items '}' ';'  */
#line 2112 "conf_parser.y"
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
#line 5767 "conf_parser.c"
    break;

  case 402: /* kill_user: USER '=' QSTRING ';'  */
#line 2136 "conf_parser.y"
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
#line 5790 "conf_parser.c"
    break;

  case 403: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2156 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5799 "conf_parser.c"
    break;

  case 404: /* $@21: %empty  */
#line 2166 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5808 "conf_parser.c"
    break;

  case 405: /* deny_entry: DENY $@21 '{' deny_items '}' ';'  */
#line 2170 "conf_parser.y"
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
#line 5830 "conf_parser.c"
    break;

  case 411: /* deny_ip: IP '=' QSTRING ';'  */
#line 2192 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5839 "conf_parser.c"
    break;

  case 412: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2198 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5848 "conf_parser.c"
    break;

  case 418: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2213 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_report_error("Unable to add D-line exemption");
}
#line 5860 "conf_parser.c"
    break;

  case 419: /* $@22: %empty  */
#line 2226 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5869 "conf_parser.c"
    break;

  case 420: /* gecos_entry: GECOS $@22 '{' gecos_items '}' ';'  */
#line 2230 "conf_parser.y"
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
#line 5889 "conf_parser.c"
    break;

  case 426: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2250 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5898 "conf_parser.c"
    break;

  case 427: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2256 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5907 "conf_parser.c"
    break;

  case 472: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2312 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5915 "conf_parser.c"
    break;

  case 473: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2317 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5923 "conf_parser.c"
    break;

  case 474: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2322 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5931 "conf_parser.c"
    break;

  case 475: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2327 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5939 "conf_parser.c"
    break;

  case 476: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2332 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5947 "conf_parser.c"
    break;

  case 477: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2337 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5955 "conf_parser.c"
    break;

  case 478: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2342 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5963 "conf_parser.c"
    break;

  case 479: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2347 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5971 "conf_parser.c"
    break;

  case 480: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2352 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5979 "conf_parser.c"
    break;

  case 481: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2357 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5987 "conf_parser.c"
    break;

  case 482: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2362 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5995 "conf_parser.c"
    break;

  case 483: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2367 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6003 "conf_parser.c"
    break;

  case 484: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2372 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 6014 "conf_parser.c"
    break;

  case 485: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2380 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6022 "conf_parser.c"
    break;

  case 486: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2385 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6030 "conf_parser.c"
    break;

  case 487: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2390 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6038 "conf_parser.c"
    break;

  case 488: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2395 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = (yyvsp[-1].boolean);
}
#line 6046 "conf_parser.c"
    break;

  case 489: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2400 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = (yyvsp[-1].boolean);
}
#line 6054 "conf_parser.c"
    break;

  case 490: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2405 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = (yyvsp[-1].boolean);
}
#line 6062 "conf_parser.c"
    break;

  case 491: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2410 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = (yyvsp[-1].boolean);
}
#line 6070 "conf_parser.c"
    break;

  case 492: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2415 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6078 "conf_parser.c"
    break;

  case 493: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2420 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6086 "conf_parser.c"
    break;

  case 494: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2425 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = (yyvsp[-1].boolean);
}
#line 6094 "conf_parser.c"
    break;

  case 495: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2430 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6102 "conf_parser.c"
    break;

  case 496: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2435 "conf_parser.y"
{
  ConfigGeneral.short_motd = (yyvsp[-1].boolean);
}
#line 6110 "conf_parser.c"
    break;

  case 497: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2440 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6118 "conf_parser.c"
    break;

  case 498: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2445 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6126 "conf_parser.c"
    break;

  case 499: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2450 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = (yyvsp[-1].boolean);
}
#line 6134 "conf_parser.c"
    break;

  case 500: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2455 "conf_parser.y"
{
  ConfigGeneral.disable_ident = (yyvsp[-1].boolean);
}
#line 6142 "conf_parser.c"
    break;

  case 501: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2460 "conf_parser.y"
{
  ConfigGeneral.disable_dns = (yyvsp[-1].boolean);
}
#line 6150 "conf_parser.c"
    break;

  case 502: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2465 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6158 "conf_parser.c"
    break;

  case 503: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2470 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6166 "conf_parser.c"
    break;

  case 504: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2475 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6178 "conf_parser.c"
    break;

  case 505: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2484 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6186 "conf_parser.c"
    break;

  case 506: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2489 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6194 "conf_parser.c"
    break;

  case 507: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2494 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6202 "conf_parser.c"
    break;

  case 508: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2499 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6210 "conf_parser.c"
    break;

  case 509: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2504 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6221 "conf_parser.c"
    break;

  case 510: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2512 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6229 "conf_parser.c"
    break;

  case 511: /* general_sasl_service: SASL_SERVICE '=' QSTRING ';'  */
#line 2517 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.sasl_service);
  ConfigGeneral.sasl_service = NULL;

  if (string_is_empty((yyvsp[-1].string)))
    break;

  if (!server_is_valid_name((yyvsp[-1].string)))
  {
    conf_report_error("Invalid general::sasl_service");
    YYABORT;
  }

  ConfigGeneral.sasl_service = io_strdup((yyvsp[-1].string));
}
#line 6252 "conf_parser.c"
    break;

  case 522: /* cloak_enabled: ENABLED '=' TBOOL ';'  */
#line 2552 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.enabled = (yyvsp[-1].boolean);
  if (ConfigCloak.enabled)
    cloak_set_enabled();
  else
    cloak_set_disabled();
}
#line 6267 "conf_parser.c"
    break;

  case 523: /* cloak_cidr_len_ipv4: CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2564 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6279 "conf_parser.c"
    break;

  case 524: /* cloak_cidr_len_ipv6: CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2573 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6291 "conf_parser.c"
    break;

  case 525: /* cloak_num_bits: NUM_BITS '=' NUMBER ';'  */
#line 2582 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6303 "conf_parser.c"
    break;

  case 526: /* cloak_secret: SECRET '=' QSTRING ';'  */
#line 2591 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.secret);
  ConfigCloak.secret = io_strdup((yyvsp[-1].string));
  cloak_set_secret((yyvsp[-1].string));
}
#line 6316 "conf_parser.c"
    break;

  case 527: /* cloak_suffix: SUFFIX '=' QSTRING ';'  */
#line 2601 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.suffix);
  ConfigCloak.suffix = io_strdup((yyvsp[-1].string));
  cloak_set_suffix((yyvsp[-1].string));
}
#line 6329 "conf_parser.c"
    break;

  case 548: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2636 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = (yyvsp[-1].boolean);
}
#line 6337 "conf_parser.c"
    break;

  case 549: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2641 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6345 "conf_parser.c"
    break;

  case 550: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2646 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6353 "conf_parser.c"
    break;

  case 551: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2651 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6361 "conf_parser.c"
    break;

  case 552: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2656 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6369 "conf_parser.c"
    break;

  case 553: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2661 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6377 "conf_parser.c"
    break;

  case 554: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2666 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6385 "conf_parser.c"
    break;

  case 555: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2671 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6393 "conf_parser.c"
    break;

  case 556: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2676 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6401 "conf_parser.c"
    break;

  case 557: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2681 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6409 "conf_parser.c"
    break;

  case 558: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2686 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6417 "conf_parser.c"
    break;

  case 559: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2691 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6425 "conf_parser.c"
    break;

  case 560: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2696 "conf_parser.y"
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
#line 6446 "conf_parser.c"
    break;

  case 561: /* channel_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 2714 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigChannel.max_topic_length = TOPICLEN;
  else
    ConfigChannel.max_topic_length = (yyvsp[-1].number);
}
#line 6457 "conf_parser.c"
    break;

  case 562: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2722 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = (yyvsp[-1].number);
}
#line 6465 "conf_parser.c"
    break;

  case 563: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2727 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6473 "conf_parser.c"
    break;

  case 576: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2749 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = (yyvsp[-1].boolean);
}
#line 6482 "conf_parser.c"
    break;

  case 577: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2755 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6496 "conf_parser.c"
    break;

  case 578: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2766 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6508 "conf_parser.c"
    break;

  case 579: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2775 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = (yyvsp[-1].boolean);
}
#line 6517 "conf_parser.c"
    break;

  case 580: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2781 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = (yyvsp[-1].boolean);
}
#line 6526 "conf_parser.c"
    break;

  case 581: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2787 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = (yyvsp[-1].boolean);
}
#line 6535 "conf_parser.c"
    break;

  case 582: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2793 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6547 "conf_parser.c"
    break;

  case 583: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2802 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = (yyvsp[-1].boolean);
}
#line 6556 "conf_parser.c"
    break;


#line 6560 "conf_parser.c"

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

