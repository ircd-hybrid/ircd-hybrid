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

static void
_conf_parser_add_listeners(uint16_t first_port, uint16_t last_port, const char *address, listener_flag_t flags)
{
  if (first_port > last_port)
  {
    conf_report_error("Invalid listener port range");
    return;
  }

  for (unsigned int port = first_port; port <= last_port; ++port)
  {
    const listener_result_t result = listener_add((uint16_t)port, address, flags);
    if (result == LISTENER_SUCCESS)
      continue;

    char message[IRCD_BUFSIZE];
    snprintf(message, sizeof(message), "Listener on port %u: %s (address: %s)", port,
             listener_result_to_string(result), string_is_empty(address) ? "all addresses" : address);

    if (result == LISTENER_PARTIAL_SUCCESS)
      conf_report_warning(message);
    else
      conf_report_error(message);

    if (result == LISTENER_INVALID_ADDRESS || result == LISTENER_TLS_UNAVAILABLE)
      break;
  }
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


#line 275 "conf_parser.c"

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

#line 314 "conf_parser.c"

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
    T_PREPEND = 424,               /* T_PREPEND  */
    T_PSEUDO = 425,                /* T_PSEUDO  */
    T_RECVQ = 426,                 /* T_RECVQ  */
    T_RESTART = 427,               /* T_RESTART  */
    T_SERVER = 428,                /* T_SERVER  */
    T_SERVICE = 429,               /* T_SERVICE  */
    T_SET = 430,                   /* T_SET  */
    T_SHARED = 431,                /* T_SHARED  */
    T_SIZE = 432,                  /* T_SIZE  */
    T_TARGET = 433,                /* T_TARGET  */
    T_TLS = 434,                   /* T_TLS  */
    T_UMODES = 435,                /* T_UMODES  */
    T_UNDLINE = 436,               /* T_UNDLINE  */
    T_UNLIMITED = 437,             /* T_UNLIMITED  */
    T_UNRESV = 438,                /* T_UNRESV  */
    T_UNXLINE = 439,               /* T_UNXLINE  */
    T_WEBIRC = 440,                /* T_WEBIRC  */
    TBOOL = 441,                   /* TBOOL  */
    THROTTLE_COUNT = 442,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 443,           /* THROTTLE_TIME  */
    TIMEOUT = 444,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 445,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 446, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 447,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 448, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 449,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 450,           /* TS_WARN_DELTA  */
    TWODOTS = 451,                 /* TWODOTS  */
    TYPE = 452,                    /* TYPE  */
    UNKLINE = 453,                 /* UNKLINE  */
    USE_LOGGING = 454,             /* USE_LOGGING  */
    USER = 455,                    /* USER  */
    WARN_NO_CONNECT_BLOCK = 456,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 457,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 458,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 459,                   /* XLINE  */
    XLINE_EXEMPT = 460,            /* XLINE_EXEMPT  */
    QSTRING = 461,                 /* QSTRING  */
    DECIMAL = 462,                 /* DECIMAL  */
    NUMBER = 463                   /* NUMBER  */
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
#define T_PREPEND 424
#define T_PSEUDO 425
#define T_RECVQ 426
#define T_RESTART 427
#define T_SERVER 428
#define T_SERVICE 429
#define T_SET 430
#define T_SHARED 431
#define T_SIZE 432
#define T_TARGET 433
#define T_TLS 434
#define T_UMODES 435
#define T_UNDLINE 436
#define T_UNLIMITED 437
#define T_UNRESV 438
#define T_UNXLINE 439
#define T_WEBIRC 440
#define TBOOL 441
#define THROTTLE_COUNT 442
#define THROTTLE_TIME 443
#define TIMEOUT 444
#define TLS_CERTIFICATE_FILE 445
#define TLS_CERTIFICATE_FINGERPRINT 446
#define TLS_PRIVATE_KEY_FILE 447
#define TLS_CONNECTION_REQUIRED 448
#define TS_MAX_DELTA 449
#define TS_WARN_DELTA 450
#define TWODOTS 451
#define TYPE 452
#define UNKLINE 453
#define USE_LOGGING 454
#define USER 455
#define WARN_NO_CONNECT_BLOCK 456
#define WHOIS 457
#define WHOWAS_HISTORY_LENGTH 458
#define XLINE 459
#define XLINE_EXEMPT 460
#define QSTRING 461
#define DECIMAL 462
#define NUMBER 463

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 220 "conf_parser.y"

  bool boolean;
  unsigned int number;
  char *string;

#line 756 "conf_parser.c"

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
  YYSYMBOL_T_PREPEND = 169,                /* T_PREPEND  */
  YYSYMBOL_T_PSEUDO = 170,                 /* T_PSEUDO  */
  YYSYMBOL_T_RECVQ = 171,                  /* T_RECVQ  */
  YYSYMBOL_T_RESTART = 172,                /* T_RESTART  */
  YYSYMBOL_T_SERVER = 173,                 /* T_SERVER  */
  YYSYMBOL_T_SERVICE = 174,                /* T_SERVICE  */
  YYSYMBOL_T_SET = 175,                    /* T_SET  */
  YYSYMBOL_T_SHARED = 176,                 /* T_SHARED  */
  YYSYMBOL_T_SIZE = 177,                   /* T_SIZE  */
  YYSYMBOL_T_TARGET = 178,                 /* T_TARGET  */
  YYSYMBOL_T_TLS = 179,                    /* T_TLS  */
  YYSYMBOL_T_UMODES = 180,                 /* T_UMODES  */
  YYSYMBOL_T_UNDLINE = 181,                /* T_UNDLINE  */
  YYSYMBOL_T_UNLIMITED = 182,              /* T_UNLIMITED  */
  YYSYMBOL_T_UNRESV = 183,                 /* T_UNRESV  */
  YYSYMBOL_T_UNXLINE = 184,                /* T_UNXLINE  */
  YYSYMBOL_T_WEBIRC = 185,                 /* T_WEBIRC  */
  YYSYMBOL_TBOOL = 186,                    /* TBOOL  */
  YYSYMBOL_THROTTLE_COUNT = 187,           /* THROTTLE_COUNT  */
  YYSYMBOL_THROTTLE_TIME = 188,            /* THROTTLE_TIME  */
  YYSYMBOL_TIMEOUT = 189,                  /* TIMEOUT  */
  YYSYMBOL_TLS_CERTIFICATE_FILE = 190,     /* TLS_CERTIFICATE_FILE  */
  YYSYMBOL_TLS_CERTIFICATE_FINGERPRINT = 191, /* TLS_CERTIFICATE_FINGERPRINT  */
  YYSYMBOL_TLS_PRIVATE_KEY_FILE = 192,     /* TLS_PRIVATE_KEY_FILE  */
  YYSYMBOL_TLS_CONNECTION_REQUIRED = 193,  /* TLS_CONNECTION_REQUIRED  */
  YYSYMBOL_TS_MAX_DELTA = 194,             /* TS_MAX_DELTA  */
  YYSYMBOL_TS_WARN_DELTA = 195,            /* TS_WARN_DELTA  */
  YYSYMBOL_TWODOTS = 196,                  /* TWODOTS  */
  YYSYMBOL_TYPE = 197,                     /* TYPE  */
  YYSYMBOL_UNKLINE = 198,                  /* UNKLINE  */
  YYSYMBOL_USE_LOGGING = 199,              /* USE_LOGGING  */
  YYSYMBOL_USER = 200,                     /* USER  */
  YYSYMBOL_WARN_NO_CONNECT_BLOCK = 201,    /* WARN_NO_CONNECT_BLOCK  */
  YYSYMBOL_WHOIS = 202,                    /* WHOIS  */
  YYSYMBOL_WHOWAS_HISTORY_LENGTH = 203,    /* WHOWAS_HISTORY_LENGTH  */
  YYSYMBOL_XLINE = 204,                    /* XLINE  */
  YYSYMBOL_XLINE_EXEMPT = 205,             /* XLINE_EXEMPT  */
  YYSYMBOL_QSTRING = 206,                  /* QSTRING  */
  YYSYMBOL_DECIMAL = 207,                  /* DECIMAL  */
  YYSYMBOL_NUMBER = 208,                   /* NUMBER  */
  YYSYMBOL_209_ = 209,                     /* ';'  */
  YYSYMBOL_210_ = 210,                     /* '}'  */
  YYSYMBOL_211_ = 211,                     /* '='  */
  YYSYMBOL_212_ = 212,                     /* ':'  */
  YYSYMBOL_213_ = 213,                     /* ','  */
  YYSYMBOL_214_ = 214,                     /* '{'  */
  YYSYMBOL_YYACCEPT = 215,                 /* $accept  */
  YYSYMBOL_conf = 216,                     /* conf  */
  YYSYMBOL_conf_item = 217,                /* conf_item  */
  YYSYMBOL_timespec = 218,                 /* timespec  */
  YYSYMBOL_time_components = 219,          /* time_components  */
  YYSYMBOL_time_component = 220,           /* time_component  */
  YYSYMBOL_time_unit = 221,                /* time_unit  */
  YYSYMBOL_sizespec = 222,                 /* sizespec  */
  YYSYMBOL_size_components = 223,          /* size_components  */
  YYSYMBOL_size_component = 224,           /* size_component  */
  YYSYMBOL_size_unit = 225,                /* size_unit  */
  YYSYMBOL_port_number = 226,              /* port_number  */
  YYSYMBOL_module_base_path_entry = 227,   /* module_base_path_entry  */
  YYSYMBOL_loadmodule_entry = 228,         /* loadmodule_entry  */
  YYSYMBOL_module_string = 229,            /* module_string  */
  YYSYMBOL_module_attributes = 230,        /* module_attributes  */
  YYSYMBOL_module_attributes_items = 231,  /* module_attributes_items  */
  YYSYMBOL_module_attributes_item = 232,   /* module_attributes_item  */
  YYSYMBOL_serverinfo_entry = 233,         /* serverinfo_entry  */
  YYSYMBOL_serverinfo_items = 234,         /* serverinfo_items  */
  YYSYMBOL_serverinfo_item = 235,          /* serverinfo_item  */
  YYSYMBOL_serverinfo_tls_certificate_file = 236, /* serverinfo_tls_certificate_file  */
  YYSYMBOL_serverinfo_tls_private_key_file = 237, /* serverinfo_tls_private_key_file  */
  YYSYMBOL_serverinfo_name = 238,          /* serverinfo_name  */
  YYSYMBOL_serverinfo_sid = 239,           /* serverinfo_sid  */
  YYSYMBOL_serverinfo_description = 240,   /* serverinfo_description  */
  YYSYMBOL_serverinfo_network_name = 241,  /* serverinfo_network_name  */
  YYSYMBOL_serverinfo_network_description = 242, /* serverinfo_network_description  */
  YYSYMBOL_serverinfo_default_max_clients = 243, /* serverinfo_default_max_clients  */
  YYSYMBOL_serverinfo_max_nick_length = 244, /* serverinfo_max_nick_length  */
  YYSYMBOL_serverinfo_motd_file = 245,     /* serverinfo_motd_file  */
  YYSYMBOL_serverinfo_hub = 246,           /* serverinfo_hub  */
  YYSYMBOL_admin_entry = 247,              /* admin_entry  */
  YYSYMBOL_admin_items = 248,              /* admin_items  */
  YYSYMBOL_admin_item = 249,               /* admin_item  */
  YYSYMBOL_admin_name = 250,               /* admin_name  */
  YYSYMBOL_admin_email = 251,              /* admin_email  */
  YYSYMBOL_admin_description = 252,        /* admin_description  */
  YYSYMBOL_motd_entry = 253,               /* motd_entry  */
  YYSYMBOL_254_1 = 254,                    /* $@1  */
  YYSYMBOL_motd_items = 255,               /* motd_items  */
  YYSYMBOL_motd_item = 256,                /* motd_item  */
  YYSYMBOL_motd_mask = 257,                /* motd_mask  */
  YYSYMBOL_motd_file = 258,                /* motd_file  */
  YYSYMBOL_pseudo_entry = 259,             /* pseudo_entry  */
  YYSYMBOL_260_2 = 260,                    /* $@2  */
  YYSYMBOL_pseudo_items = 261,             /* pseudo_items  */
  YYSYMBOL_pseudo_item = 262,              /* pseudo_item  */
  YYSYMBOL_pseudo_command = 263,           /* pseudo_command  */
  YYSYMBOL_pseudo_name = 264,              /* pseudo_name  */
  YYSYMBOL_pseudo_prepend = 265,           /* pseudo_prepend  */
  YYSYMBOL_pseudo_target = 266,            /* pseudo_target  */
  YYSYMBOL_logging_entry = 267,            /* logging_entry  */
  YYSYMBOL_logging_items = 268,            /* logging_items  */
  YYSYMBOL_logging_item = 269,             /* logging_item  */
  YYSYMBOL_logging_use_logging = 270,      /* logging_use_logging  */
  YYSYMBOL_logging_file_entry = 271,       /* logging_file_entry  */
  YYSYMBOL_272_3 = 272,                    /* $@3  */
  YYSYMBOL_logging_file_items = 273,       /* logging_file_items  */
  YYSYMBOL_logging_file_item = 274,        /* logging_file_item  */
  YYSYMBOL_logging_file_name = 275,        /* logging_file_name  */
  YYSYMBOL_logging_file_size = 276,        /* logging_file_size  */
  YYSYMBOL_logging_file_type = 277,        /* logging_file_type  */
  YYSYMBOL_278_4 = 278,                    /* $@4  */
  YYSYMBOL_logging_file_type_item = 279,   /* logging_file_type_item  */
  YYSYMBOL_oper_entry = 280,               /* oper_entry  */
  YYSYMBOL_281_5 = 281,                    /* $@5  */
  YYSYMBOL_oper_items = 282,               /* oper_items  */
  YYSYMBOL_oper_item = 283,                /* oper_item  */
  YYSYMBOL_oper_name = 284,                /* oper_name  */
  YYSYMBOL_oper_user = 285,                /* oper_user  */
  YYSYMBOL_oper_password = 286,            /* oper_password  */
  YYSYMBOL_oper_whois = 287,               /* oper_whois  */
  YYSYMBOL_oper_encrypted = 288,           /* oper_encrypted  */
  YYSYMBOL_oper_tls_certificate_fingerprint = 289, /* oper_tls_certificate_fingerprint  */
  YYSYMBOL_oper_tls_connection_required = 290, /* oper_tls_connection_required  */
  YYSYMBOL_oper_class = 291,               /* oper_class  */
  YYSYMBOL_oper_umodes = 292,              /* oper_umodes  */
  YYSYMBOL_oper_flags = 293,               /* oper_flags  */
  YYSYMBOL_294_6 = 294,                    /* $@6  */
  YYSYMBOL_oper_flags_items = 295,         /* oper_flags_items  */
  YYSYMBOL_oper_flags_item = 296,          /* oper_flags_item  */
  YYSYMBOL_class_entry = 297,              /* class_entry  */
  YYSYMBOL_298_7 = 298,                    /* $@7  */
  YYSYMBOL_class_items = 299,              /* class_items  */
  YYSYMBOL_class_item = 300,               /* class_item  */
  YYSYMBOL_class_name = 301,               /* class_name  */
  YYSYMBOL_class_ping_time = 302,          /* class_ping_time  */
  YYSYMBOL_class_number_per_ip_local = 303, /* class_number_per_ip_local  */
  YYSYMBOL_class_number_per_ip_global = 304, /* class_number_per_ip_global  */
  YYSYMBOL_class_max_channels = 305,       /* class_max_channels  */
  YYSYMBOL_class_max_number = 306,         /* class_max_number  */
  YYSYMBOL_class_sendq = 307,              /* class_sendq  */
  YYSYMBOL_class_recvq = 308,              /* class_recvq  */
  YYSYMBOL_class_cidr_bitlen_ipv4 = 309,   /* class_cidr_bitlen_ipv4  */
  YYSYMBOL_class_cidr_bitlen_ipv6 = 310,   /* class_cidr_bitlen_ipv6  */
  YYSYMBOL_class_number_per_cidr = 311,    /* class_number_per_cidr  */
  YYSYMBOL_listen_entry = 312,             /* listen_entry  */
  YYSYMBOL_313_8 = 313,                    /* $@8  */
  YYSYMBOL_listen_flags = 314,             /* listen_flags  */
  YYSYMBOL_315_9 = 315,                    /* $@9  */
  YYSYMBOL_listen_flags_items = 316,       /* listen_flags_items  */
  YYSYMBOL_listen_flags_item = 317,        /* listen_flags_item  */
  YYSYMBOL_listen_items = 318,             /* listen_items  */
  YYSYMBOL_listen_item = 319,              /* listen_item  */
  YYSYMBOL_listen_port = 320,              /* listen_port  */
  YYSYMBOL_321_10 = 321,                   /* $@10  */
  YYSYMBOL_port_items = 322,               /* port_items  */
  YYSYMBOL_port_item = 323,                /* port_item  */
  YYSYMBOL_listen_address = 324,           /* listen_address  */
  YYSYMBOL_listen_host = 325,              /* listen_host  */
  YYSYMBOL_auth_entry = 326,               /* auth_entry  */
  YYSYMBOL_327_11 = 327,                   /* $@11  */
  YYSYMBOL_auth_items = 328,               /* auth_items  */
  YYSYMBOL_auth_item = 329,                /* auth_item  */
  YYSYMBOL_auth_user = 330,                /* auth_user  */
  YYSYMBOL_auth_passwd = 331,              /* auth_passwd  */
  YYSYMBOL_auth_class = 332,               /* auth_class  */
  YYSYMBOL_auth_encrypted = 333,           /* auth_encrypted  */
  YYSYMBOL_auth_flags = 334,               /* auth_flags  */
  YYSYMBOL_335_12 = 335,                   /* $@12  */
  YYSYMBOL_auth_flags_items = 336,         /* auth_flags_items  */
  YYSYMBOL_auth_flags_item = 337,          /* auth_flags_item  */
  YYSYMBOL_auth_spoof = 338,               /* auth_spoof  */
  YYSYMBOL_resv_entry = 339,               /* resv_entry  */
  YYSYMBOL_340_13 = 340,                   /* $@13  */
  YYSYMBOL_resv_items = 341,               /* resv_items  */
  YYSYMBOL_resv_item = 342,                /* resv_item  */
  YYSYMBOL_resv_mask = 343,                /* resv_mask  */
  YYSYMBOL_resv_reason = 344,              /* resv_reason  */
  YYSYMBOL_resv_exempt = 345,              /* resv_exempt  */
  YYSYMBOL_service_entry = 346,            /* service_entry  */
  YYSYMBOL_service_items = 347,            /* service_items  */
  YYSYMBOL_service_item = 348,             /* service_item  */
  YYSYMBOL_service_name = 349,             /* service_name  */
  YYSYMBOL_shared_entry = 350,             /* shared_entry  */
  YYSYMBOL_351_14 = 351,                   /* $@14  */
  YYSYMBOL_shared_items = 352,             /* shared_items  */
  YYSYMBOL_shared_item = 353,              /* shared_item  */
  YYSYMBOL_shared_name = 354,              /* shared_name  */
  YYSYMBOL_shared_user = 355,              /* shared_user  */
  YYSYMBOL_shared_type = 356,              /* shared_type  */
  YYSYMBOL_357_15 = 357,                   /* $@15  */
  YYSYMBOL_shared_types = 358,             /* shared_types  */
  YYSYMBOL_shared_type_item = 359,         /* shared_type_item  */
  YYSYMBOL_cluster_entry = 360,            /* cluster_entry  */
  YYSYMBOL_361_16 = 361,                   /* $@16  */
  YYSYMBOL_cluster_items = 362,            /* cluster_items  */
  YYSYMBOL_cluster_item = 363,             /* cluster_item  */
  YYSYMBOL_cluster_name = 364,             /* cluster_name  */
  YYSYMBOL_cluster_type = 365,             /* cluster_type  */
  YYSYMBOL_366_17 = 366,                   /* $@17  */
  YYSYMBOL_cluster_types = 367,            /* cluster_types  */
  YYSYMBOL_cluster_type_item = 368,        /* cluster_type_item  */
  YYSYMBOL_connect_entry = 369,            /* connect_entry  */
  YYSYMBOL_370_18 = 370,                   /* $@18  */
  YYSYMBOL_connect_items = 371,            /* connect_items  */
  YYSYMBOL_connect_item = 372,             /* connect_item  */
  YYSYMBOL_connect_name = 373,             /* connect_name  */
  YYSYMBOL_connect_host = 374,             /* connect_host  */
  YYSYMBOL_connect_timeout = 375,          /* connect_timeout  */
  YYSYMBOL_connect_retry_delay = 376,      /* connect_retry_delay  */
  YYSYMBOL_connect_bind = 377,             /* connect_bind  */
  YYSYMBOL_connect_send_password = 378,    /* connect_send_password  */
  YYSYMBOL_connect_accept_password = 379,  /* connect_accept_password  */
  YYSYMBOL_connect_tls_certificate_fingerprint = 380, /* connect_tls_certificate_fingerprint  */
  YYSYMBOL_connect_port = 381,             /* connect_port  */
  YYSYMBOL_connect_aftype = 382,           /* connect_aftype  */
  YYSYMBOL_connect_flags = 383,            /* connect_flags  */
  YYSYMBOL_384_19 = 384,                   /* $@19  */
  YYSYMBOL_connect_flags_items = 385,      /* connect_flags_items  */
  YYSYMBOL_connect_flags_item = 386,       /* connect_flags_item  */
  YYSYMBOL_connect_encrypted = 387,        /* connect_encrypted  */
  YYSYMBOL_connect_hub_mask = 388,         /* connect_hub_mask  */
  YYSYMBOL_connect_leaf_mask = 389,        /* connect_leaf_mask  */
  YYSYMBOL_connect_class = 390,            /* connect_class  */
  YYSYMBOL_kill_entry = 391,               /* kill_entry  */
  YYSYMBOL_392_20 = 392,                   /* $@20  */
  YYSYMBOL_kill_items = 393,               /* kill_items  */
  YYSYMBOL_kill_item = 394,                /* kill_item  */
  YYSYMBOL_kill_user = 395,                /* kill_user  */
  YYSYMBOL_kill_reason = 396,              /* kill_reason  */
  YYSYMBOL_deny_entry = 397,               /* deny_entry  */
  YYSYMBOL_398_21 = 398,                   /* $@21  */
  YYSYMBOL_deny_items = 399,               /* deny_items  */
  YYSYMBOL_deny_item = 400,                /* deny_item  */
  YYSYMBOL_deny_ip = 401,                  /* deny_ip  */
  YYSYMBOL_deny_reason = 402,              /* deny_reason  */
  YYSYMBOL_exempt_entry = 403,             /* exempt_entry  */
  YYSYMBOL_exempt_items = 404,             /* exempt_items  */
  YYSYMBOL_exempt_item = 405,              /* exempt_item  */
  YYSYMBOL_exempt_ip = 406,                /* exempt_ip  */
  YYSYMBOL_gecos_entry = 407,              /* gecos_entry  */
  YYSYMBOL_408_22 = 408,                   /* $@22  */
  YYSYMBOL_gecos_items = 409,              /* gecos_items  */
  YYSYMBOL_gecos_item = 410,               /* gecos_item  */
  YYSYMBOL_gecos_name = 411,               /* gecos_name  */
  YYSYMBOL_gecos_reason = 412,             /* gecos_reason  */
  YYSYMBOL_general_entry = 413,            /* general_entry  */
  YYSYMBOL_general_items = 414,            /* general_items  */
  YYSYMBOL_general_item = 415,             /* general_item  */
  YYSYMBOL_general_away_count = 416,       /* general_away_count  */
  YYSYMBOL_general_away_time = 417,        /* general_away_time  */
  YYSYMBOL_general_max_monitor = 418,      /* general_max_monitor  */
  YYSYMBOL_general_whowas_history_length = 419, /* general_whowas_history_length  */
  YYSYMBOL_general_dline_min_cidr = 420,   /* general_dline_min_cidr  */
  YYSYMBOL_general_dline_min_cidr6 = 421,  /* general_dline_min_cidr6  */
  YYSYMBOL_general_kline_min_cidr = 422,   /* general_kline_min_cidr  */
  YYSYMBOL_general_kline_min_cidr6 = 423,  /* general_kline_min_cidr6  */
  YYSYMBOL_general_kill_chase_time_limit = 424, /* general_kill_chase_time_limit  */
  YYSYMBOL_general_max_nick_time = 425,    /* general_max_nick_time  */
  YYSYMBOL_general_max_nick_changes = 426, /* general_max_nick_changes  */
  YYSYMBOL_general_max_accept = 427,       /* general_max_accept  */
  YYSYMBOL_general_max_away_length = 428,  /* general_max_away_length  */
  YYSYMBOL_general_anti_spam_exit_message_time = 429, /* general_anti_spam_exit_message_time  */
  YYSYMBOL_general_ts_warn_delta = 430,    /* general_ts_warn_delta  */
  YYSYMBOL_general_ts_max_delta = 431,     /* general_ts_max_delta  */
  YYSYMBOL_general_invisible_on_connect = 432, /* general_invisible_on_connect  */
  YYSYMBOL_general_warn_no_connect_block = 433, /* general_warn_no_connect_block  */
  YYSYMBOL_general_stats_e_disabled = 434, /* general_stats_e_disabled  */
  YYSYMBOL_general_stats_u_oper_only = 435, /* general_stats_u_oper_only  */
  YYSYMBOL_general_pace_wait = 436,        /* general_pace_wait  */
  YYSYMBOL_general_caller_id_wait = 437,   /* general_caller_id_wait  */
  YYSYMBOL_general_opers_bypass_callerid = 438, /* general_opers_bypass_callerid  */
  YYSYMBOL_general_pace_wait_simple = 439, /* general_pace_wait_simple  */
  YYSYMBOL_general_short_motd = 440,       /* general_short_motd  */
  YYSYMBOL_general_specials_in_ident = 441, /* general_specials_in_ident  */
  YYSYMBOL_general_max_targets = 442,      /* general_max_targets  */
  YYSYMBOL_general_ping_cookie = 443,      /* general_ping_cookie  */
  YYSYMBOL_general_disable_ident = 444,    /* general_disable_ident  */
  YYSYMBOL_general_disable_dns = 445,      /* general_disable_dns  */
  YYSYMBOL_general_throttle_count = 446,   /* general_throttle_count  */
  YYSYMBOL_general_throttle_time = 447,    /* general_throttle_time  */
  YYSYMBOL_general_oper_umodes = 448,      /* general_oper_umodes  */
  YYSYMBOL_general_min_nonwildcard = 449,  /* general_min_nonwildcard  */
  YYSYMBOL_general_min_nonwildcard_simple = 450, /* general_min_nonwildcard_simple  */
  YYSYMBOL_general_default_floodcount = 451, /* general_default_floodcount  */
  YYSYMBOL_general_default_floodtime = 452, /* general_default_floodtime  */
  YYSYMBOL_general_ident_timeout = 453,    /* general_ident_timeout  */
  YYSYMBOL_general_registration_timeout = 454, /* general_registration_timeout  */
  YYSYMBOL_general_sasl_service = 455,     /* general_sasl_service  */
  YYSYMBOL_cloak_entry = 456,              /* cloak_entry  */
  YYSYMBOL_cloak_items = 457,              /* cloak_items  */
  YYSYMBOL_cloak_item = 458,               /* cloak_item  */
  YYSYMBOL_cloak_enabled = 459,            /* cloak_enabled  */
  YYSYMBOL_cloak_cidr_len_ipv4 = 460,      /* cloak_cidr_len_ipv4  */
  YYSYMBOL_cloak_cidr_len_ipv6 = 461,      /* cloak_cidr_len_ipv6  */
  YYSYMBOL_cloak_num_bits = 462,           /* cloak_num_bits  */
  YYSYMBOL_cloak_secret = 463,             /* cloak_secret  */
  YYSYMBOL_cloak_suffix = 464,             /* cloak_suffix  */
  YYSYMBOL_channel_entry = 465,            /* channel_entry  */
  YYSYMBOL_channel_items = 466,            /* channel_items  */
  YYSYMBOL_channel_item = 467,             /* channel_item  */
  YYSYMBOL_channel_disable_fake_channels = 468, /* channel_disable_fake_channels  */
  YYSYMBOL_channel_invite_client_count = 469, /* channel_invite_client_count  */
  YYSYMBOL_channel_invite_client_time = 470, /* channel_invite_client_time  */
  YYSYMBOL_channel_invite_delay_channel = 471, /* channel_invite_delay_channel  */
  YYSYMBOL_channel_invite_expire_time = 472, /* channel_invite_expire_time  */
  YYSYMBOL_channel_knock_client_count = 473, /* channel_knock_client_count  */
  YYSYMBOL_channel_knock_client_time = 474, /* channel_knock_client_time  */
  YYSYMBOL_channel_knock_delay_channel = 475, /* channel_knock_delay_channel  */
  YYSYMBOL_channel_max_channels = 476,     /* channel_max_channels  */
  YYSYMBOL_channel_max_invites = 477,      /* channel_max_invites  */
  YYSYMBOL_channel_max_bans = 478,         /* channel_max_bans  */
  YYSYMBOL_channel_max_bans_large = 479,   /* channel_max_bans_large  */
  YYSYMBOL_channel_max_kick_length = 480,  /* channel_max_kick_length  */
  YYSYMBOL_channel_max_topic_length = 481, /* channel_max_topic_length  */
  YYSYMBOL_channel_default_join_flood_count = 482, /* channel_default_join_flood_count  */
  YYSYMBOL_channel_default_join_flood_time = 483, /* channel_default_join_flood_time  */
  YYSYMBOL_serverhide_entry = 484,         /* serverhide_entry  */
  YYSYMBOL_serverhide_items = 485,         /* serverhide_items  */
  YYSYMBOL_serverhide_item = 486,          /* serverhide_item  */
  YYSYMBOL_serverhide_flatten_links = 487, /* serverhide_flatten_links  */
  YYSYMBOL_serverhide_flatten_links_delay = 488, /* serverhide_flatten_links_delay  */
  YYSYMBOL_serverhide_flatten_links_file = 489, /* serverhide_flatten_links_file  */
  YYSYMBOL_serverhide_disable_remote_commands = 490, /* serverhide_disable_remote_commands  */
  YYSYMBOL_serverhide_hide_servers = 491,  /* serverhide_hide_servers  */
  YYSYMBOL_serverhide_hide_services = 492, /* serverhide_hide_services  */
  YYSYMBOL_serverhide_hidden_name = 493,   /* serverhide_hidden_name  */
  YYSYMBOL_serverhide_hidden = 494         /* serverhide_hidden  */
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
#define YYLAST   1175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  215
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  280
/* YYNRULES -- Number of rules.  */
#define YYNRULES  582
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1191

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   463


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
       2,     2,     2,     2,   213,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   212,   209,
       2,   211,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   214,     2,   210,     2,     2,     2,     2,
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
     205,   206,   207,   208
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   431,   431,   432,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     464,   473,   475,   475,   484,   491,   503,   504,   505,   506,
     507,   510,   519,   521,   521,   530,   537,   549,   550,   551,
     552,   553,   554,   555,   558,   573,   588,   600,   606,   608,
     613,   616,   621,   624,   633,   635,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   650,
     659,   668,   682,   696,   706,   720,   729,   752,   775,   784,
     794,   796,   796,   797,   798,   799,   800,   802,   811,   820,
     834,   833,   851,   851,   852,   852,   852,   854,   860,   871,
     870,   905,   905,   906,   906,   906,   906,   906,   908,   914,
     920,   926,   949,   950,   950,   952,   952,   953,   955,   965,
     965,   978,   979,   981,   981,   982,   982,   984,   992,   995,
    1001,  1000,  1006,  1010,  1014,  1018,  1022,  1026,  1030,  1034,
    1045,  1044,  1106,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1117,  1119,  1125,  1131,  1137,  1143,
    1154,  1160,  1171,  1177,  1184,  1183,  1189,  1189,  1190,  1194,
    1198,  1202,  1206,  1210,  1214,  1218,  1222,  1226,  1230,  1234,
    1238,  1242,  1246,  1250,  1254,  1258,  1262,  1266,  1270,  1274,
    1278,  1282,  1286,  1290,  1294,  1298,  1302,  1313,  1312,  1355,
    1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,  1367,  1369,  1375,  1381,  1387,  1393,  1399,  1405,
    1411,  1418,  1424,  1430,  1440,  1439,  1446,  1445,  1450,  1450,
    1451,  1455,  1459,  1463,  1467,  1473,  1473,  1474,  1474,  1474,
    1474,  1474,  1476,  1476,  1478,  1478,  1480,  1484,  1490,  1496,
    1507,  1506,  1562,  1562,  1563,  1564,  1565,  1566,  1567,  1568,
    1569,  1571,  1577,  1583,  1589,  1601,  1600,  1606,  1606,  1608,
    1612,  1616,  1620,  1624,  1628,  1632,  1636,  1640,  1646,  1661,
    1660,  1683,  1683,  1684,  1684,  1684,  1684,  1686,  1692,  1698,
    1708,  1710,  1710,  1711,  1711,  1713,  1730,  1729,  1752,  1752,
    1753,  1753,  1753,  1753,  1755,  1761,  1781,  1780,  1786,  1786,
    1787,  1791,  1795,  1799,  1803,  1807,  1811,  1815,  1819,  1823,
    1827,  1838,  1837,  1856,  1856,  1857,  1857,  1857,  1859,  1866,
    1865,  1871,  1871,  1872,  1876,  1880,  1884,  1888,  1892,  1896,
    1900,  1904,  1908,  1919,  1918,  1974,  1974,  1975,  1976,  1977,
    1978,  1979,  1980,  1981,  1982,  1983,  1984,  1985,  1986,  1987,
    1988,  1989,  1990,  1992,  1998,  2004,  2010,  2016,  2022,  2035,
    2048,  2054,  2060,  2064,  2071,  2070,  2075,  2075,  2076,  2080,
    2086,  2097,  2103,  2109,  2120,  2119,  2144,  2144,  2145,  2145,
    2145,  2147,  2167,  2178,  2177,  2200,  2200,  2201,  2201,  2201,
    2203,  2209,  2219,  2221,  2221,  2222,  2222,  2224,  2238,  2237,
    2256,  2256,  2257,  2257,  2257,  2259,  2265,  2275,  2277,  2277,
    2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,  2286,  2287,
    2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,  2296,  2297,
    2298,  2299,  2300,  2301,  2302,  2303,  2304,  2305,  2306,  2307,
    2308,  2309,  2310,  2311,  2312,  2313,  2314,  2315,  2316,  2317,
    2318,  2321,  2326,  2331,  2336,  2341,  2346,  2351,  2356,  2361,
    2366,  2371,  2376,  2381,  2389,  2394,  2399,  2404,  2409,  2414,
    2419,  2424,  2429,  2434,  2439,  2444,  2449,  2454,  2459,  2464,
    2469,  2474,  2479,  2484,  2493,  2498,  2503,  2508,  2513,  2521,
    2526,  2550,  2552,  2552,  2553,  2554,  2555,  2556,  2557,  2558,
    2559,  2561,  2573,  2582,  2591,  2600,  2610,  2624,  2626,  2626,
    2627,  2628,  2629,  2630,  2631,  2632,  2633,  2634,  2635,  2636,
    2637,  2638,  2639,  2640,  2641,  2642,  2643,  2645,  2650,  2655,
    2660,  2665,  2670,  2675,  2680,  2685,  2690,  2695,  2700,  2705,
    2723,  2731,  2736,  2745,  2747,  2747,  2748,  2749,  2750,  2751,
    2752,  2753,  2754,  2755,  2756,  2758,  2764,  2775,  2784,  2790,
    2796,  2802,  2811
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
  "T_IPV6", "T_LOCOPS", "T_LOG", "T_PREPEND", "T_PSEUDO", "T_RECVQ",
  "T_RESTART", "T_SERVER", "T_SERVICE", "T_SET", "T_SHARED", "T_SIZE",
  "T_TARGET", "T_TLS", "T_UMODES", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV",
  "T_UNXLINE", "T_WEBIRC", "TBOOL", "THROTTLE_COUNT", "THROTTLE_TIME",
  "TIMEOUT", "TLS_CERTIFICATE_FILE", "TLS_CERTIFICATE_FINGERPRINT",
  "TLS_PRIVATE_KEY_FILE", "TLS_CONNECTION_REQUIRED", "TS_MAX_DELTA",
  "TS_WARN_DELTA", "TWODOTS", "TYPE", "UNKLINE", "USE_LOGGING", "USER",
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
    -641,   644,  -641,  -144,  -202,  -195,  -641,  -178,  -641,  -641,
    -171,  -641,  -169,  -641,  -641,  -641,  -184,  -162,  -641,  -641,
    -641,  -161,  -159,  -641,  -155,  -641,  -143,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,   322,   667,  -139,   361,  -132,
    -127,     9,  -124,   348,  -120,  -117,  -111,  -641,  -104,  -184,
     -91,   -83,   -59,   665,   449,   -17,    36,   -11,   209,    -8,
       5,    37,    45,    53,     7,  -641,  -641,  -641,  -641,  -641,
      62,    67,    77,   102,   104,   106,   108,   111,   122,   123,
     125,   129,   130,   131,   132,   139,    97,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,   420,  -641,   141,   142,   144,   154,
     158,   159,   192,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
     505,   235,  -641,   161,    50,  -641,  -641,   201,  -641,   162,
     165,   166,   169,   172,   175,   178,   188,   189,   190,   194,
     195,   197,   198,   200,   202,   204,   205,   206,   207,   208,
     213,   214,   217,   219,   223,   224,   227,   228,   229,   234,
     236,   238,   243,   246,   247,   248,   249,   254,   256,    17,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,   304,    79,   240,    25,    42,    52,    90,   273,    28,
    -641,   265,   270,   271,   274,   277,   279,   280,   282,    12,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   211,
     286,   294,   296,   300,   302,   303,   305,   307,   309,   312,
     315,    73,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,    85,   275,   317,    29,  -641,  -641,
    -641,   140,   212,  -641,   320,    23,  -641,  -641,    92,  -641,
     327,   334,   335,   306,  -641,    26,    83,   145,   152,    83,
      83,    83,   336,    83,    83,   337,   340,   342,   347,   351,
     352,   354,  -641,   359,   358,   360,   362,   363,   366,   367,
     370,   372,   375,   378,   381,   153,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   364,   387,
     407,   388,   392,   394,   403,  -641,   408,   410,   413,   414,
     416,   417,   419,  -641,   425,   426,   427,   429,   431,   435,
     436,   439,   148,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
     442,   443,    15,  -641,  -641,  -641,   397,   422,  -641,  -641,
     445,   448,    19,  -641,  -641,  -641,    83,   421,    83,    83,
     452,    83,   475,   479,   459,   462,    83,   486,    83,   466,
     467,   468,   469,   471,   473,    83,   474,   476,   477,   480,
     501,    83,    83,   503,    83,   484,   506,   483,   509,   515,
     495,    83,    83,    83,   520,   502,   500,  -641,   504,   513,
     516,  -641,   519,   525,   526,   222,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,   527,   528,    32,  -641,  -641,  -641,
     517,   529,   530,  -641,   531,  -641,    14,  -641,  -641,  -641,
    -641,  -641,  -641,   498,  -641,  -641,  -641,   522,   532,   533,
     151,  -641,  -641,  -641,   536,   535,   541,  -641,   542,   543,
     544,   545,   551,   552,   553,    75,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,   557,   556,   558,
     559,    40,  -641,  -641,  -641,  -641,   585,   586,    83,   567,
     588,   569,   590,   591,   570,  -641,  -641,   573,   572,   596,
     577,   576,   579,   580,   581,   582,   583,   584,   587,  -641,
     589,   592,  -641,    57,  -641,  -641,  -641,  -641,   605,   593,
    -641,   595,   597,   599,   600,   602,   604,    71,  -641,  -641,
    -641,  -641,  -641,   601,   607,  -641,   608,   610,  -641,   611,
      87,  -641,  -641,  -641,  -641,   614,   615,   616,  -641,   617,
     252,   252,   618,    88,  -641,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,  -641,
    -641,   634,   635,   636,   637,   613,   638,   639,   640,    83,
      94,    94,   641,  -641,   642,   643,   645,   646,   647,   648,
    -641,  -641,   652,    78,   653,   609,   654,   655,   651,   657,
     658,   659,    83,   660,   662,    83,   663,   656,  -641,   664,
     666,   668,  -641,   669,  -641,   670,   673,   671,  -641,   672,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,   685,   686,   687,   688,   689,   690,   691,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   702,   703,
     704,   705,   706,   707,   708,   709,   710,   711,   712,  -641,
    -641,   716,   737,   713,   719,   720,   721,   722,  -641,   723,
     724,   725,  -641,  -641,   726,   727,   717,   659,   728,  -641,
      25,  -641,   729,   730,   731,  -641,  -641,   732,   753,   733,
     735,   736,   739,   740,   757,   741,   742,   743,  -641,  -641,
     744,   745,   747,   746,  -641,   748,   749,   750,   751,   752,
     754,   755,   756,  -641,   758,   759,   760,   761,   762,   763,
     764,   765,   766,   767,   768,  -641,  -641,   772,   738,   770,
    -641,   771,  -641,   149,  -641,   775,   776,   777,   778,   779,
    -641,   780,  -641,  -641,   781,   774,   784,   782,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,   252,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,   783,   785,   786,
     787,   788,   789,   790,   791,   792,   594,   594,   793,   120,
    -641,   794,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   795,
     796,   797,   798,   799,   800,   801,     4,   802,   803,  -641,
     804,   805,   806,   807,   808,   809,  -641,   810,   811,  -641,
    -641,   812,   813,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,   814,   815,   385,   816,   817,   818,
    -641,   819,   820,  -641,   821,   822,   290,   598,   499,  -641,
    -641,  -641,   823,   824,  -641,   825,   826,   451,   827,   828,
     829,   830,   831,   832,   833,  -641,   834,   835,   836,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   837,
     418,  -641,  -641,   838,   839,   840,  -641,    49,  -641,  -641,
    -641,  -641,   843,   844,   845,   846,  -641,  -641,   847,   521,
     848,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,   594,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -204,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -192,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -182,  -641,   659,   659,   849,  -641,  -641,  -641,
    -641,  -641,   191,  -641,   661,  -641,   850,   851,  -641,   852,
    -641,   853,   854,  -641,  -641,   855,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -181,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -175,
    -641,  -641,   842,  -168,   857,   860,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -167,  -641,  -641,  -641,     4,  -641,   385,
    -641,   290,  -641,  -641,  -641,   734,   861,   913,   927,   714,
     924,   929,   938,  -641,   451,  -641,   418,   862,   863,   864,
     458,  -641,  -641,   521,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   865,  -641,
    -641
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   207,     0,   353,   403,
       0,   418,     0,   260,   394,   234,     0,     0,   100,   150,
     289,     0,     0,   331,     0,   109,     0,   306,     3,     4,
       5,    14,     6,    26,    27,     7,     8,    11,    12,    13,
      16,    17,    18,    19,    20,    21,    22,    23,    25,    24,
      10,     9,    15,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    95,    94,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   529,   545,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   530,   531,
     541,   542,   543,   544,     0,   520,     0,     0,     0,     0,
       0,     0,     0,   513,   514,   515,   516,   517,   518,   519,
       0,     0,   416,     0,     0,   414,   415,     0,   470,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     429,   430,   431,   466,   435,   461,   462,   463,   464,   439,
     432,   433,   434,   448,   436,   437,   438,   440,   441,   465,
     443,   444,   450,   451,   445,   446,   442,   447,   458,   459,
     460,   456,   457,   449,   454,   455,   452,   453,   467,   468,
     469,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     574,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     565,   566,   567,   568,   569,   570,   571,   573,   572,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    77,    75,    67,    76,    69,    70,    71,
      72,    73,    74,    68,     0,     0,     0,     0,   124,   125,
     126,     0,     0,   304,     0,     0,   302,   303,     0,    96,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   210,   211,   214,   216,
     217,   218,   219,   220,   221,   212,   213,   215,     0,     0,
       0,     0,     0,     0,     0,   512,     0,     0,     0,     0,
       0,     0,     0,   384,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   366,   365,   367,   371,   368,   369,   370,   409,
       0,     0,     0,   406,   407,   408,     0,     0,   413,   424,
       0,     0,     0,   421,   422,   423,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   428,     0,     0,
       0,   275,     0,     0,     0,     0,   263,   264,   265,   266,
     269,   267,   268,   400,     0,     0,     0,   397,   398,   399,
       0,     0,     0,   236,     0,   248,     0,   246,   247,   249,
     250,    63,    62,    59,    61,    56,    55,     0,     0,     0,
       0,   103,   104,   105,     0,     0,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   160,   161,   162,   159,   158,   163,     0,     0,     0,
       0,     0,   292,   293,   294,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   564,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,   339,     0,   334,   335,   336,   127,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   112,   113,
     115,   114,   116,     0,     0,   301,     0,     0,   316,     0,
       0,   309,   310,   311,   312,     0,     0,     0,    90,     0,
       0,    30,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
     222,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,     0,     0,     0,     0,     0,     0,
     511,   372,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   355,     0,
       0,     0,   405,     0,   412,     0,     0,     0,   420,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   427,
     270,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,     0,   396,   251,     0,     0,     0,     0,     0,   245,
       0,   106,     0,     0,     0,   102,   164,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   296,
       0,     0,     0,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,   563,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,   337,     0,     0,     0,
     333,     0,   122,     0,   117,     0,     0,     0,     0,     0,
     111,     0,   300,   313,     0,     0,     0,     0,   308,    99,
      98,    97,   561,    36,    37,    38,    39,    40,    35,    34,
     562,     0,    33,   547,   548,   549,   550,   551,   552,   553,
     554,   557,   558,   555,   556,   559,   560,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,    42,
      43,     0,   208,   522,   523,   521,   524,   525,   526,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,   354,     0,     0,   404,
     417,     0,     0,   419,   484,   471,   472,   492,   506,   507,
     500,   499,   475,   476,   508,   487,   479,   477,   478,   482,
     483,   473,   481,   480,   497,   504,   505,   503,   493,   491,
     494,   498,   509,   510,   495,   496,   489,   490,   501,   502,
     486,   485,   488,   474,     0,     0,     0,     0,     0,     0,
     261,     0,     0,   395,     0,     0,     0,   256,   252,   255,
     235,    60,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,     0,     0,     0,   290,
     578,   575,   576,   577,   582,   581,   579,   580,    86,    83,
      89,    82,    87,    88,    81,    85,    84,    79,    80,     0,
       0,   332,   128,     0,     0,     0,   140,     0,   132,   133,
     135,   134,     0,     0,     0,     0,   110,   305,     0,     0,
       0,   307,   231,   232,   227,   228,   223,   233,   226,   225,
     224,    47,    48,    49,    50,    51,    52,    53,    46,    45,
     229,     0,    44,   230,   379,   382,   383,   393,   390,   374,
     391,   388,   389,     0,   387,   392,   373,   381,   376,   378,
     377,   375,   380,   410,   411,   425,   426,   273,   274,   283,
     279,   280,   282,   287,   284,   285,   286,   281,     0,   278,
     272,   288,   271,   402,   401,   259,   258,   243,   244,   241,
     242,   240,     0,   239,     0,     0,     0,   107,   108,   172,
     169,   194,     0,   204,   181,   190,     0,   179,   184,     0,
     199,     0,   193,   197,   202,   183,   186,   195,   196,   191,
     198,   187,   203,   189,   185,   188,     0,   177,   165,   167,
     173,   170,   171,   166,   168,   299,   297,   298,   338,   343,
     349,   352,   345,   351,   346,   350,   348,   344,   347,     0,
     342,   136,     0,     0,     0,     0,   131,   119,   118,   120,
     121,   314,   320,   326,   327,   330,   322,   329,   323,   328,
     325,   321,   324,     0,   319,   315,   385,     0,   276,     0,
     237,     0,   257,   254,   253,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,   340,     0,     0,     0,     0,
       0,   130,   317,     0,   386,   277,   238,   206,   180,   201,
     178,   205,   200,   192,   182,   176,   341,   137,   139,   138,
     148,   147,   143,   145,   149,   146,   142,   144,     0,   318,
     141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -641,  -641,  -641,  -307,  -641,   215,   210,  -621,  -641,   -30,
     -21,  -640,  -641,  -641,   885,  -641,  -641,   133,  -641,  -641,
     578,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,   872,  -641,  -641,  -641,  -641,  -641,
    -641,   384,  -641,  -641,  -641,  -641,  -641,   308,  -641,  -641,
    -641,  -641,  -641,  -641,   841,  -641,  -641,  -641,  -641,   -96,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   377,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -188,  -641,  -641,  -641,   769,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -179,  -641,   510,  -641,  -641,  -641,    20,  -641,
    -641,  -641,  -641,  -641,   633,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,   -63,  -641,  -641,  -641,  -641,   560,  -641,  -641,
    -641,  -641,  -641,   856,  -641,  -641,  -641,  -641,   497,  -641,
    -641,  -641,  -641,  -641,   -85,  -641,  -641,  -641,   534,  -641,
    -641,  -641,  -641,   -77,  -641,  -641,  -641,   718,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,   -57,  -641,  -641,  -641,  -641,  -641,  -641,  -641,   649,
    -641,  -641,  -641,  -641,  -641,   715,  -641,  -641,  -641,  -641,
     939,  -641,  -641,  -641,  -641,   773,  -641,  -641,  -641,  -641,
     893,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,  -641,   952,  -641,  -641,  -641,  -641,  -641,  -641,
    -641,  -641,   979,  -641,  -641,  -641,  -641,  -641,  -641,  -641,
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
     969,   970,   971,  1114,  1188,    36,    71,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   729,
    1086,  1087,    37,    57,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,    38,    66,   475,
     716,  1052,  1053,   476,   477,   478,  1056,   918,   919,   479,
     480,    39,    64,   455,   456,   457,   458,   459,   460,   461,
     703,  1038,  1039,   462,    40,    72,   521,   522,   523,   524,
     525,    41,   295,   296,   297,    42,    79,   580,   581,   582,
     583,   584,   785,  1133,  1134,    43,    75,   553,   554,   555,
     556,   768,  1109,  1110,    44,    59,   372,   373,   374,   375,
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
     831,   850,   597,   598,   599,  1136,   601,   602,    80,  1137,
     142,  1011,    55,   240,  1158,   470,   389,  1138,   148,    56,
     399,  1139,    67,   149,   293,   150,   151,  1140,  1153,   517,
     285,  1141,  1154,   463,  1155,   152,    58,   285,  1156,   826,
     827,   517,  1162,    61,    81,    63,  1163,   153,   154,    69,
     963,   142,    82,    73,   241,    74,   155,   156,   550,    76,
     157,   158,   242,   243,   244,    53,    54,   245,   246,   247,
     248,    78,   562,   471,   259,   124,   494,   518,   143,   159,
     463,   160,   140,   472,   390,   473,   550,   141,   576,   518,
     147,   487,   161,   576,   231,   162,   163,   232,    89,   659,
     495,   661,   662,   233,   664,   164,   165,   260,   234,   669,
     261,   671,   166,   167,   519,   168,    83,   169,   678,   143,
     170,   171,   496,   237,   684,   685,   519,   687,   400,    90,
      91,   238,   294,   262,   694,   695,   696,   172,    92,   173,
     174,   175,   474,   176,   391,   263,   497,   177,   401,   356,
     963,   357,   487,   358,   323,   239,   178,   520,   964,   481,
     482,   464,    93,    94,    95,    96,   551,   179,   180,   520,
     264,   181,   182,   359,   324,   325,   488,    97,    98,    99,
     563,   265,   266,  1012,   498,   267,   268,   100,   101,   102,
     103,   104,  -129,   125,   551,   360,   577,   284,   105,  -129,
     499,   577,   399,   292,   183,   184,   298,   361,   464,   362,
     293,   185,   186,   562,   299,   126,   127,   303,   187,   363,
     188,   747,   534,   448,   718,   651,   965,   446,   286,   657,
     564,   364,   465,   574,   589,   286,   389,   488,   128,   559,
     565,   470,   711,   840,   841,   326,   966,   449,   300,   566,
     743,   485,   327,   489,   552,   500,   301,   365,   964,  1115,
     397,   486,   328,   269,   302,   270,   501,   769,   502,   450,
     329,   330,   331,   305,   494,   503,   366,   504,   306,   465,
     332,   779,   552,   548,   578,   737,   367,   579,   307,   578,
     590,   591,   579,   451,   368,   590,   801,   787,   495,   471,
     333,   826,   827,   561,   390,   448,   369,   321,   129,   472,
     400,   473,   825,   308,   489,   309,  1047,   310,   294,   311,
     496,   563,   312,    80,   334,  1048,   965,   826,  1001,   449,
     401,   595,   130,   313,   314,   851,   315,   370,   854,   371,
     316,   317,   318,   319,   497,  1049,   966,   452,   131,   148,
     320,   450,   348,   349,   149,   350,   150,   151,   647,    81,
     596,   724,   125,   622,   391,   351,   152,    82,   474,   352,
     353,   564,   396,   406,   453,   451,   407,   408,   153,   154,
     409,   565,   498,   410,   126,   127,   411,   155,   156,   412,
     566,   157,   158,   793,   794,   795,   796,   797,   499,   413,
     414,   415,   354,  1145,  1029,   416,   417,   128,   418,   419,
     159,   420,   160,   421,  1142,   422,   423,   424,   425,   426,
     536,   323,   454,   161,   427,   428,   162,   163,   429,   452,
     430,    83,   707,  1030,   431,   432,   164,   165,   433,   434,
     435,   324,   325,   166,   167,   436,   168,   437,   169,   438,
     259,   170,   171,   500,   439,  1061,   453,   440,   441,   442,
     443,  1062,  1031,  1050,   501,   444,   502,   445,   172,  1051,
     173,   174,   175,   503,   176,   504,   526,   129,   177,  1063,
    1064,   527,   528,   260,   557,   529,   261,   178,   530,  1065,
     531,   532,  1159,   533,  1099,  1032,  1033,   537,   179,   180,
    1034,   130,   181,   182,   454,   538,   356,   539,   357,   262,
     358,   540,   326,   541,   542,   588,   543,   131,   544,   327,
     545,   263,  1035,   546,  1066,  1067,   547,  1068,   558,   328,
     359,   573,  1180,   585,  1181,   183,   184,   329,   330,   331,
     586,   587,   185,   186,   600,   603,   264,   332,   604,   187,
     605,   188,   360,  1069,  1100,   606,  1070,   265,   266,   607,
     608,   267,   268,   609,   361,  1071,   362,   333,   610,   611,
    1036,   612,   624,   613,   614,  1101,   363,   615,   616,  1182,
    1102,   617,  1072,   618,  1073,  1103,   619,  1074,   364,   620,
    1037,   334,   621,   626,  1183,   625,   627,  1122,   628,  1104,
     629,  1105,  1106,   653,  1075,   991,   992,   993,   994,   995,
     996,   997,   630,  1076,   365,  1077,  1107,   631,  1078,  1184,
    1185,   632,  1108,  1079,   633,   634,  1080,   635,   636,   660,
     637,   654,  1081,   366,  1082,  1083,   639,   640,   641,   269,
     642,   270,   643,   367,     2,     3,   644,   645,     4,  1084,
     646,   368,  1123,   649,   650,  1085,   655,  1124,  1186,   656,
     663,   665,  1187,   369,     5,   666,   240,   667,    89,     6,
     668,     7,   670,     8,   672,   673,   674,   675,  1125,   676,
       9,   677,   679,  1126,   680,   681,   682,   683,  1127,   686,
     688,   690,   689,    10,   370,   691,   371,    11,    12,    90,
      91,   692,  1128,   693,  1129,  1130,   697,   241,    92,   699,
     698,   720,  1055,   700,    13,   242,   243,   244,    14,  1131,
     245,   246,   247,   248,   701,  1132,   713,   702,    15,    16,
     704,   721,    93,    94,    95,    96,   705,   706,   709,   710,
     714,   715,   717,   722,   723,   726,   727,    97,    98,    99,
      17,    18,   728,   730,   731,   732,   733,   100,   101,   102,
     103,   104,   734,   735,   736,    19,   739,   740,   105,   741,
     742,   745,   746,   748,   749,   750,   751,   752,   755,   753,
      20,   754,   756,   757,   758,   759,   760,   761,   762,   763,
     764,   771,    21,    22,  1054,   843,   765,  1167,   766,  1002,
     798,  1171,   772,   767,    23,   998,   774,   781,   802,   773,
     775,   776,    24,   777,    25,   778,   782,   783,    26,   821,
      27,   784,   786,   789,   790,   791,   792,   800,   803,   804,
     805,   806,   807,   808,   809,   810,   811,   812,   813,   814,
     815,   816,   817,   818,   819,   820,   822,   823,   824,   549,
     832,   833,   834,   921,   835,   836,   837,   838,   839,   842,
     844,   845,   846,   847,   848,   856,   852,   849,   853,   855,
     857,  1116,   858,  1146,   725,   780,   861,   859,   860,   862,
     863,   864,   738,   865,   866,   867,   868,   869,   870,   871,
     872,   873,   874,   875,   876,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   886,   887,   888,   889,   890,   891,
     892,   893,   894,   895,   896,   897,   898,   899,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   916,   911,
     912,   910,   914,   915,   913,   922,   923,   920,   925,   926,
     924,   928,   929,   932,   927,   930,   931,   933,   934,   960,
     936,   937,   935,   938,   236,   939,   304,   940,   941,   942,
     943,   944,  1166,   945,   946,   947,  1175,   948,   949,   950,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   961,
     962,   972,   973,   974,   975,   979,   719,   978,   976,   977,
     980,   981,   982,  1168,   983,   984,   985,   986,   987,   988,
     989,   990,  1000,  1003,  1004,  1005,  1006,  1007,  1008,  1009,
    1010,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1040,  1041,  1042,  1043,  1044,
    1045,  1046,  1057,  1058,  1059,  1060,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,  1097,  1098,  1111,  1157,  1169,
    1112,  1113,  1117,  1118,  1119,  1120,  1121,  1135,  1144,  1170,
    1172,  1173,  1147,  1148,  1149,  1150,  1151,  1152,  1160,  1161,
    1174,  1177,  1178,  1179,  1190,  1143,  1165,   788,  1189,  1176,
    1164,   744,   447,   398,   355,   322,     0,   770,   708,     0,
     648,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   623,     0,     0,   652,   535,     0,
       0,     0,     0,     0,     0,   712,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   560,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   575,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   658
};

static const yytype_int16 yycheck[] =
{
     621,   641,   309,   310,   311,   209,   313,   314,     1,   213,
       1,     7,   214,     1,   182,     1,     1,   209,     1,   214,
       1,   213,   206,     6,     1,     8,     9,   209,   209,     1,
       1,   213,   213,     1,   209,    18,   214,     1,   213,   207,
     208,     1,   209,   214,    37,   214,   213,    30,    31,   211,
       1,     1,    45,   214,    42,   214,    39,    40,     1,   214,
      43,    44,    50,    51,    52,   209,   210,    55,    56,    57,
      58,   214,     1,    59,     1,   214,     1,    49,    69,    62,
       1,    64,   214,    69,    69,    71,     1,   214,     1,    49,
     214,     1,    75,     1,   214,    78,    79,   214,     1,   406,
      25,   408,   409,   214,   411,    88,    89,    34,   212,   416,
      37,   418,    95,    96,    86,    98,   109,   100,   425,    69,
     103,   104,    47,   214,   431,   432,    86,   434,   109,    32,
      33,   214,   109,    60,   441,   442,   443,   120,    41,   122,
     123,   124,   128,   126,   129,    72,    71,   130,   129,     1,
       1,     3,     1,     5,     1,   214,   139,   129,   109,   134,
     135,   129,    65,    66,    67,    68,   109,   150,   151,   129,
      97,   154,   155,    25,    21,    22,    86,    80,    81,    82,
     109,   108,   109,   179,   109,   112,   113,    90,    91,    92,
      93,    94,   163,     1,   109,    47,   109,   214,   101,   163,
     125,   109,     1,   214,   187,   188,   214,    59,   129,    61,
       1,   194,   195,     1,   209,    23,    24,   210,   201,    71,
     203,   528,   210,     1,   210,   210,   177,   210,   199,   210,
     159,    83,   200,   210,   208,   199,     1,    86,    46,   210,
     169,     1,   210,   165,   166,    92,   197,    25,   211,   178,
     210,   209,    99,   163,   197,   180,   211,   109,   109,   210,
     210,   209,   109,   190,   211,   192,   191,   210,   193,    47,
     117,   118,   119,   211,     1,   200,   128,   202,   211,   200,
     127,   210,   197,   210,   197,   210,   138,   200,   211,   197,
     207,   208,   200,    71,   146,   207,   208,   210,    25,    59,
     147,   207,   208,   163,    69,     1,   158,   210,   116,    69,
     109,    71,   619,   211,   163,   211,    26,   211,   109,   211,
      47,   109,   211,     1,   171,    35,   177,   207,   208,    25,
     129,   186,   140,   211,   211,   642,   211,   189,   645,   191,
     211,   211,   211,   211,    71,    55,   197,   125,   156,     1,
     211,    47,   211,   211,     6,   211,     8,     9,   210,    37,
     208,   210,     1,   210,   129,   211,    18,    45,   128,   211,
     211,   159,   211,   211,   152,    71,   211,   211,    30,    31,
     211,   169,   109,   211,    23,    24,   211,    39,    40,   211,
     178,    43,    44,   141,   142,   143,   144,   145,   125,   211,
     211,   211,   210,   212,    19,   211,   211,    46,   211,   211,
      62,   211,    64,   211,  1054,   211,   211,   211,   211,   211,
     209,     1,   200,    75,   211,   211,    78,    79,   211,   125,
     211,   109,   210,    48,   211,   211,    88,    89,   211,   211,
     211,    21,    22,    95,    96,   211,    98,   211,   100,   211,
       1,   103,   104,   180,   211,     4,   152,   211,   211,   211,
     211,    10,    77,   173,   191,   211,   193,   211,   120,   179,
     122,   123,   124,   200,   126,   202,   211,   116,   130,    28,
      29,   211,   211,    34,   209,   211,    37,   139,   211,    38,
     211,   211,  1113,   211,    76,   110,   111,   211,   150,   151,
     115,   140,   154,   155,   200,   211,     1,   211,     3,    60,
       5,   211,    92,   211,   211,   209,   211,   156,   211,    99,
     211,    72,   137,   211,    73,    74,   211,    76,   211,   109,
      25,   211,    74,   206,    76,   187,   188,   117,   118,   119,
     206,   206,   194,   195,   208,   208,    97,   127,   208,   201,
     208,   203,    47,   102,   136,   208,   105,   108,   109,   208,
     208,   112,   113,   209,    59,   114,    61,   147,   209,   211,
     185,   211,   208,   211,   211,   157,    71,   211,   211,   121,
     162,   211,   131,   211,   133,   167,   211,   136,    83,   211,
     205,   171,   211,   186,   136,   208,   208,    76,   206,   181,
     206,   183,   184,   206,   153,    11,    12,    13,    14,    15,
      16,    17,   209,   162,   109,   164,   198,   209,   167,   161,
     162,   211,   204,   172,   211,   211,   175,   211,   211,   208,
     211,   209,   181,   128,   183,   184,   211,   211,   211,   190,
     211,   192,   211,   138,     0,     1,   211,   211,     4,   198,
     211,   146,   131,   211,   211,   204,   211,   136,   200,   211,
     208,   186,   204,   158,    20,   186,     1,   208,     1,    25,
     208,    27,   186,    29,   208,   208,   208,   208,   157,   208,
      36,   208,   208,   162,   208,   208,   206,   186,   167,   186,
     206,   208,   186,    49,   189,   186,   191,    53,    54,    32,
      33,   186,   181,   208,   183,   184,   186,    42,    41,   209,
     208,   213,   213,   209,    70,    50,    51,    52,    74,   198,
      55,    56,    57,    58,   211,   204,   209,   211,    84,    85,
     211,   209,    65,    66,    67,    68,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   209,   211,    80,    81,    82,
     106,   107,   211,   211,   211,   211,   211,    90,    91,    92,
      93,    94,   211,   211,   211,   121,   209,   211,   101,   211,
     211,   186,   186,   206,   186,   206,   186,   186,   206,   209,
     136,   208,   186,   206,   208,   206,   206,   206,   206,   206,
     206,   186,   148,   149,   196,   186,   209,    63,   209,   829,
     590,    87,   209,   211,   160,   826,   209,   206,   593,   214,
     211,   211,   168,   211,   170,   211,   209,   209,   174,   206,
     176,   211,   211,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   208,   208,   208,   208,   208,   208,   208,   271,
     209,   209,   209,   720,   209,   209,   209,   209,   206,   206,
     206,   206,   211,   206,   206,   209,   206,   208,   206,   206,
     206,   967,   206,   212,   490,   567,   206,   209,   209,   206,
     209,   209,   505,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   206,   186,   211,   206,   206,   206,   211,   206,
     206,   209,   206,   206,   209,   206,   206,   209,   206,   186,
     209,   206,   206,   186,   211,   206,   206,   206,   206,   211,
     206,   206,   209,   206,    69,   209,    84,   209,   209,   209,
     209,   209,  1141,   209,   209,   209,  1154,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   206,   209,
     209,   206,   206,   206,   206,   211,   476,   206,   209,   209,
     206,   209,   209,   132,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   206,   136,
     211,   211,   209,   209,   209,   209,   209,   209,   209,   132,
     136,   132,   212,   212,   212,   212,   212,   212,   211,   209,
     132,   209,   209,   209,   209,  1055,  1139,   580,  1163,  1156,
    1137,   521,   189,   144,   132,   106,    -1,   553,   455,    -1,
     372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   335,    -1,    -1,   392,   249,    -1,
      -1,    -1,    -1,    -1,    -1,   466,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   402
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   216,     0,     1,     4,    20,    25,    27,    29,    36,
      49,    53,    54,    70,    74,    84,    85,   106,   107,   121,
     136,   148,   149,   160,   168,   170,   174,   176,   217,   227,
     228,   233,   247,   253,   259,   267,   280,   297,   312,   326,
     339,   346,   350,   360,   369,   391,   397,   403,   407,   413,
     456,   465,   484,   209,   210,   214,   214,   298,   214,   370,
     398,   214,   408,   214,   327,   392,   313,   206,   229,   211,
     254,   281,   340,   214,   214,   361,   214,   260,   214,   351,
       1,    37,    45,   109,   248,   249,   250,   251,   252,     1,
      32,    33,    41,    65,    66,    67,    68,    80,    81,    82,
      90,    91,    92,    93,    94,   101,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   214,     1,    23,    24,    46,   116,
     140,   156,   457,   458,   459,   460,   461,   462,   463,   464,
     214,   214,     1,    69,   404,   405,   406,   214,     1,     6,
       8,     9,    18,    30,    31,    39,    40,    43,    44,    62,
      64,    75,    78,    79,    88,    89,    95,    96,    98,   100,
     103,   104,   120,   122,   123,   124,   126,   130,   139,   150,
     151,   154,   155,   187,   188,   194,   195,   201,   203,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   214,   214,   214,   212,   230,   229,   214,   214,   214,
       1,    42,    50,    51,    52,    55,    56,    57,    58,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,     1,
      34,    37,    60,    72,    97,   108,   109,   112,   113,   190,
     192,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   214,     1,   199,   268,   269,   270,
     271,   272,   214,     1,   109,   347,   348,   349,   214,   209,
     211,   211,   211,   210,   249,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   210,   467,     1,    21,    22,    92,    99,   109,   117,
     118,   119,   127,   147,   171,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   211,   211,
     211,   211,   211,   211,   210,   458,     1,     3,     5,    25,
      47,    59,    61,    71,    83,   109,   128,   138,   146,   158,
     189,   191,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   387,   388,   389,   390,     1,
      69,   129,   399,   400,   401,   402,   211,   210,   405,     1,
     109,   129,   409,   410,   411,   412,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   210,   415,     1,    25,
      47,    71,   125,   152,   200,   328,   329,   330,   331,   332,
     333,   334,   338,     1,   129,   200,   393,   394,   395,   396,
       1,    59,    69,    71,   128,   314,   318,   319,   320,   324,
     325,   134,   135,   231,   232,   209,   209,     1,    86,   163,
     255,   256,   257,   258,     1,    25,    47,    71,   109,   125,
     180,   191,   193,   200,   202,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,     1,    49,    86,
     129,   341,   342,   343,   344,   345,   211,   211,   211,   211,
     211,   211,   211,   211,   210,   486,   209,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   210,   235,
       1,   109,   197,   362,   363,   364,   365,   209,   211,   210,
     269,   163,     1,   109,   159,   169,   178,   261,   262,   263,
     264,   265,   266,   211,   210,   348,     1,   109,   197,   200,
     352,   353,   354,   355,   356,   206,   206,   206,   209,   208,
     207,   208,   218,   219,   220,   186,   208,   218,   218,   218,
     208,   218,   218,   208,   208,   208,   208,   208,   208,   209,
     209,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   210,   300,   208,   208,   186,   208,   206,   206,
     209,   209,   211,   211,   211,   211,   211,   211,   384,   211,
     211,   211,   211,   211,   211,   211,   211,   210,   372,   211,
     211,   210,   400,   206,   209,   211,   211,   210,   410,   218,
     208,   218,   218,   208,   218,   186,   186,   208,   208,   218,
     186,   218,   208,   208,   208,   208,   208,   208,   218,   208,
     208,   208,   206,   186,   218,   218,   186,   218,   206,   186,
     208,   186,   186,   208,   218,   218,   218,   186,   208,   209,
     209,   211,   211,   335,   211,   211,   211,   210,   329,   211,
     211,   210,   394,   209,   211,   211,   315,   211,   210,   319,
     213,   209,   211,   211,   210,   256,   209,   211,   211,   294,
     211,   211,   211,   211,   211,   211,   211,   210,   283,   209,
     211,   211,   211,   210,   342,   186,   186,   218,   206,   186,
     206,   186,   186,   209,   208,   206,   186,   206,   208,   206,
     206,   206,   206,   206,   206,   209,   209,   211,   366,   210,
     363,   186,   209,   214,   209,   211,   211,   211,   211,   210,
     262,   206,   209,   209,   211,   357,   211,   210,   353,   209,
     209,   209,   209,   141,   142,   143,   144,   145,   221,   221,
     209,   208,   220,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   208,   208,   208,
     208,   206,   208,   208,   208,   218,   207,   208,   222,   223,
     224,   222,   209,   209,   209,   209,   209,   209,   209,   206,
     165,   166,   206,   186,   206,   206,   211,   206,   206,   208,
     226,   218,   206,   206,   218,   206,   209,   206,   206,   209,
     209,   206,   206,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   206,   186,   211,   206,   206,   206,
     209,   206,   206,   209,   206,   206,   211,   226,   322,   323,
     209,   232,   206,   206,   209,   206,   186,   211,   206,   206,
     206,   206,   186,   206,   206,   209,   206,   206,   206,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   206,
     211,   209,   209,     1,   109,   177,   197,   273,   274,   275,
     276,   277,   206,   206,   206,   206,   209,   209,   206,   211,
     206,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,    11,    12,    13,    14,    15,    16,    17,   225,   225,
     209,   208,   224,   209,   209,   209,   209,   209,   209,   209,
     209,     7,   179,   385,   386,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,    19,
      48,    77,   110,   111,   115,   137,   185,   205,   336,   337,
     209,   209,   209,   209,   209,   209,   209,    26,    35,    55,
     173,   179,   316,   317,   196,   213,   321,   209,   209,   209,
     209,     4,    10,    28,    29,    38,    73,    74,    76,   102,
     105,   114,   131,   133,   136,   153,   162,   164,   167,   172,
     175,   181,   183,   184,   198,   204,   295,   296,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,    76,
     136,   157,   162,   167,   181,   183,   184,   198,   204,   367,
     368,   209,   211,   211,   278,   210,   274,   209,   209,   209,
     209,   209,    76,   131,   136,   157,   162,   167,   181,   183,
     184,   198,   204,   358,   359,   209,   209,   213,   209,   213,
     209,   213,   226,   323,   209,   212,   212,   212,   212,   212,
     212,   212,   212,   209,   213,   209,   213,   206,   182,   222,
     211,   209,   209,   213,   386,   337,   317,    63,   132,   136,
     132,    87,   136,   132,   132,   296,   368,   209,   209,   209,
      74,    76,   121,   136,   161,   162,   200,   204,   279,   359,
     209
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   215,   216,   216,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     218,   218,   219,   219,   220,   220,   221,   221,   221,   221,
     221,   222,   222,   223,   223,   224,   224,   225,   225,   225,
     225,   225,   225,   225,   226,   227,   228,   229,   230,   230,
     231,   231,   232,   232,   233,   234,   234,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   248,   249,   249,   249,   249,   250,   251,   252,
     254,   253,   255,   255,   256,   256,   256,   257,   258,   260,
     259,   261,   261,   262,   262,   262,   262,   262,   263,   264,
     265,   266,   267,   268,   268,   269,   269,   269,   270,   272,
     271,   273,   273,   274,   274,   274,   274,   275,   276,   276,
     278,   277,   279,   279,   279,   279,   279,   279,   279,   279,
     281,   280,   282,   282,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   294,   293,   295,   295,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   298,   297,   299,
     299,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   313,   312,   315,   314,   316,   316,
     317,   317,   317,   317,   317,   318,   318,   319,   319,   319,
     319,   319,   321,   320,   322,   322,   323,   323,   324,   325,
     327,   326,   328,   328,   329,   329,   329,   329,   329,   329,
     329,   330,   331,   332,   333,   335,   334,   336,   336,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   338,   340,
     339,   341,   341,   342,   342,   342,   342,   343,   344,   345,
     346,   347,   347,   348,   348,   349,   351,   350,   352,   352,
     353,   353,   353,   353,   354,   355,   357,   356,   358,   358,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   361,   360,   362,   362,   363,   363,   363,   364,   366,
     365,   367,   367,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   370,   369,   371,   371,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   382,   384,   383,   385,   385,   386,   386,
     387,   388,   389,   390,   392,   391,   393,   393,   394,   394,
     394,   395,   396,   398,   397,   399,   399,   400,   400,   400,
     401,   402,   403,   404,   404,   405,   405,   406,   408,   407,
     409,   409,   410,   410,   410,   411,   412,   413,   414,   414,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   457,   458,   458,   458,   458,   458,   458,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   466,
     467,   467,   467,   467,   467,   467,   467,   467,   467,   467,
     467,   467,   467,   467,   467,   467,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   485,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   487,   488,   489,   490,   491,
     492,   493,   494
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
       3,     3,     1,     1,     1,     3,     3,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     6,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     0,     5,     3,     1,     1,     3,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       5,     2,     1,     1,     1,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     2,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
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
#line 428 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3192 "conf_parser.c"
        break;

    case YYSYMBOL_module_string: /* module_string  */
#line 428 "conf_parser.y"
            { io_free(((*yyvaluep).string)); }
#line 3198 "conf_parser.c"
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
#line 465 "conf_parser.y"
{
  if ((yyvsp[0].number) != 0)
  {
    yyerror("Nonzero durations require a unit");
    YYERROR;
  }

  (yyval.number) = 0;
}
#line 3479 "conf_parser.c"
    break;

  case 33: /* time_components: time_components time_component  */
#line 476 "conf_parser.y"
{
  if (!_conf_parser_quantity_add((yyvsp[-1].number), (yyvsp[0].number), 1U, &(yyval.number)))
  {
    yyerror("Duration out of range");
    YYERROR;
  }
}
#line 3491 "conf_parser.c"
    break;

  case 34: /* time_component: NUMBER time_unit  */
#line 485 "conf_parser.y"
{
  if (!_conf_parser_quantity_add(0, (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Duration out of range");
    YYERROR;
  }
}
#line 3503 "conf_parser.c"
    break;

  case 35: /* time_component: DECIMAL time_unit  */
#line 492 "conf_parser.y"
{
  const enum conf_quantity_status status = _conf_parser_quantity_from_decimal((yyvsp[-1].string), (yyvsp[0].number), &(yyval.number));
  io_free((yyvsp[-1].string));

  if (status != CONF_QUANTITY_OK)
  {
    yyerror(status == CONF_QUANTITY_INEXACT ? "Duration component must resolve to whole seconds" : "Duration out of range");
    YYERROR;
  }
}
#line 3518 "conf_parser.c"
    break;

  case 36: /* time_unit: SECONDS  */
#line 503 "conf_parser.y"
                   { (yyval.number) = 1U; }
#line 3524 "conf_parser.c"
    break;

  case 37: /* time_unit: MINUTES  */
#line 504 "conf_parser.y"
                   { (yyval.number) = 60U; }
#line 3530 "conf_parser.c"
    break;

  case 38: /* time_unit: HOURS  */
#line 505 "conf_parser.y"
                   { (yyval.number) = 60U * 60U; }
#line 3536 "conf_parser.c"
    break;

  case 39: /* time_unit: DAYS  */
#line 506 "conf_parser.y"
                   { (yyval.number) = 60U * 60U * 24U; }
#line 3542 "conf_parser.c"
    break;

  case 40: /* time_unit: WEEKS  */
#line 507 "conf_parser.y"
                   { (yyval.number) = 60U * 60U * 24U * 7U; }
#line 3548 "conf_parser.c"
    break;

  case 41: /* sizespec: NUMBER  */
#line 511 "conf_parser.y"
{
  if ((yyvsp[0].number) != 0)
  {
    yyerror("Nonzero sizes require a unit");
    YYERROR;
  }

  (yyval.number) = 0;
}
#line 3562 "conf_parser.c"
    break;

  case 44: /* size_components: size_components size_component  */
#line 522 "conf_parser.y"
{
  if (!_conf_parser_quantity_add((yyvsp[-1].number), (yyvsp[0].number), 1U, &(yyval.number)))
  {
    yyerror("Size out of range");
    YYERROR;
  }
}
#line 3574 "conf_parser.c"
    break;

  case 45: /* size_component: NUMBER size_unit  */
#line 531 "conf_parser.y"
{
  if (!_conf_parser_quantity_add(0, (yyvsp[-1].number), (yyvsp[0].number), &(yyval.number)))
  {
    yyerror("Size out of range");
    YYERROR;
  }
}
#line 3586 "conf_parser.c"
    break;

  case 46: /* size_component: DECIMAL size_unit  */
#line 538 "conf_parser.y"
{
  const enum conf_quantity_status status = _conf_parser_quantity_from_decimal((yyvsp[-1].string), (yyvsp[0].number), &(yyval.number));
  io_free((yyvsp[-1].string));

  if (status != CONF_QUANTITY_OK)
  {
    yyerror(status == CONF_QUANTITY_INEXACT ? "Size component must resolve to whole bytes" : "Size out of range");
    YYERROR;
  }
}
#line 3601 "conf_parser.c"
    break;

  case 47: /* size_unit: BYTES  */
#line 549 "conf_parser.y"
                   { (yyval.number) = 1U; }
#line 3607 "conf_parser.c"
    break;

  case 48: /* size_unit: KBYTES  */
#line 550 "conf_parser.y"
                   { (yyval.number) = 1000U; }
#line 3613 "conf_parser.c"
    break;

  case 49: /* size_unit: KIBYTES  */
#line 551 "conf_parser.y"
                   { (yyval.number) = 1024U; }
#line 3619 "conf_parser.c"
    break;

  case 50: /* size_unit: MBYTES  */
#line 552 "conf_parser.y"
                   { (yyval.number) = 1000U * 1000U; }
#line 3625 "conf_parser.c"
    break;

  case 51: /* size_unit: MIBYTES  */
#line 553 "conf_parser.y"
                   { (yyval.number) = 1024U * 1024U; }
#line 3631 "conf_parser.c"
    break;

  case 52: /* size_unit: GBYTES  */
#line 554 "conf_parser.y"
                   { (yyval.number) = 1000U * 1000U * 1000U; }
#line 3637 "conf_parser.c"
    break;

  case 53: /* size_unit: GIBYTES  */
#line 555 "conf_parser.y"
                   { (yyval.number) = 1024U * 1024U * 1024U; }
#line 3643 "conf_parser.c"
    break;

  case 54: /* port_number: NUMBER  */
#line 559 "conf_parser.y"
{
  if ((yyvsp[0].number) > UINT16_MAX)
  {
    yyerror("Port out of range");
    YYERROR;
  }

  (yyval.number) = (yyvsp[0].number);
}
#line 3657 "conf_parser.c"
    break;

  case 55: /* module_base_path_entry: MODULE_BASE_PATH '=' module_string ';'  */
#line 574 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct module_error_info error;
    if (module_config_set_base_path(conf_parser_ctx.module_config, (yyvsp[-1].string), &error) != MODULE_SUCCESS)
      conf_report_module_error(error.message);
  }
  io_free((yyvsp[-1].string));
}
#line 3671 "conf_parser.c"
    break;

  case 56: /* loadmodule_entry: LOADMODULE module_string module_attributes ';'  */
#line 589 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct module_error_info error;
    if (module_config_add(conf_parser_ctx.module_config, (yyvsp[-2].string), (module_flags_t)(yyvsp[-1].number), &error) != MODULE_SUCCESS)
      conf_report_module_error(error.message);
  }
  io_free((yyvsp[-2].string));
}
#line 3685 "conf_parser.c"
    break;

  case 57: /* module_string: QSTRING  */
#line 601 "conf_parser.y"
{
  (yyval.string) = io_strdup((yyvsp[0].string));
}
#line 3693 "conf_parser.c"
    break;

  case 58: /* module_attributes: %empty  */
#line 606 "conf_parser.y"
{
  (yyval.number) = 0;
}
#line 3701 "conf_parser.c"
    break;

  case 59: /* module_attributes: ':' module_attributes_items  */
#line 609 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3709 "conf_parser.c"
    break;

  case 60: /* module_attributes_items: module_attributes_items ',' module_attributes_item  */
#line 614 "conf_parser.y"
{
  (yyval.number) = (yyvsp[-2].number) | (yyvsp[0].number);
}
#line 3717 "conf_parser.c"
    break;

  case 61: /* module_attributes_items: module_attributes_item  */
#line 617 "conf_parser.y"
{
  (yyval.number) = (yyvsp[0].number);
}
#line 3725 "conf_parser.c"
    break;

  case 62: /* module_attributes_item: RESIDENT  */
#line 622 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_DEACTIVATE;
}
#line 3733 "conf_parser.c"
    break;

  case 63: /* module_attributes_item: REQUIRED  */
#line 625 "conf_parser.y"
{
  (yyval.number) = MODULE_FLAG_NO_REMOVE;
}
#line 3741 "conf_parser.c"
    break;

  case 79: /* serverinfo_tls_certificate_file: TLS_CERTIFICATE_FILE '=' QSTRING ';'  */
#line 651 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = io_strdup(yylval.string);
  }
}
#line 3753 "conf_parser.c"
    break;

  case 80: /* serverinfo_tls_private_key_file: TLS_PRIVATE_KEY_FILE '=' QSTRING ';'  */
#line 660 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.tls_private_key_file);
    ConfigServerInfo.tls_private_key_file = io_strdup(yylval.string);
  }
}
#line 3765 "conf_parser.c"
    break;

  case 81: /* serverinfo_name: NAME '=' QSTRING ';'  */
#line 669 "conf_parser.y"
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
#line 3782 "conf_parser.c"
    break;

  case 82: /* serverinfo_sid: IRCD_SID '=' QSTRING ';'  */
#line 683 "conf_parser.y"
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
#line 3799 "conf_parser.c"
    break;

  case 83: /* serverinfo_description: DESCRIPTION '=' QSTRING ';'  */
#line 697 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.description);
    ConfigServerInfo.description = io_strdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3812 "conf_parser.c"
    break;

  case 84: /* serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'  */
#line 707 "conf_parser.y"
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
#line 3829 "conf_parser.c"
    break;

  case 85: /* serverinfo_network_description: NETWORK_DESCRIPTION '=' QSTRING ';'  */
#line 721 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = io_strdup(yylval.string);
}
#line 3841 "conf_parser.c"
    break;

  case 86: /* serverinfo_default_max_clients: DEFAULT_MAX_CLIENTS '=' NUMBER ';'  */
#line 730 "conf_parser.y"
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
#line 3867 "conf_parser.c"
    break;

  case 87: /* serverinfo_max_nick_length: MAX_NICK_LENGTH '=' NUMBER ';'  */
#line 753 "conf_parser.y"
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
#line 3893 "conf_parser.c"
    break;

  case 88: /* serverinfo_motd_file: MOTD_FILE '=' QSTRING ';'  */
#line 776 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerInfo.motd_file);
    ConfigServerInfo.motd_file = io_strdup(yylval.string);
  }
}
#line 3905 "conf_parser.c"
    break;

  case 89: /* serverinfo_hub: HUB '=' TBOOL ';'  */
#line 785 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = (yyvsp[-1].boolean);
}
#line 3914 "conf_parser.c"
    break;

  case 97: /* admin_name: NAME '=' QSTRING ';'  */
#line 803 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = io_strdup(yylval.string);
}
#line 3926 "conf_parser.c"
    break;

  case 98: /* admin_email: EMAIL '=' QSTRING ';'  */
#line 812 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = io_strdup(yylval.string);
}
#line 3938 "conf_parser.c"
    break;

  case 99: /* admin_description: DESCRIPTION '=' QSTRING ';'  */
#line 821 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = io_strdup(yylval.string);
}
#line 3950 "conf_parser.c"
    break;

  case 100: /* $@1: %empty  */
#line 834 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3959 "conf_parser.c"
    break;

  case 101: /* motd_entry: MOTD $@1 '{' motd_items '}' ';'  */
#line 838 "conf_parser.y"
{
  list_node_t *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  LIST_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3976 "conf_parser.c"
    break;

  case 107: /* motd_mask: MASK '=' QSTRING ';'  */
#line 855 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 3985 "conf_parser.c"
    break;

  case 108: /* motd_file: T_FILE '=' QSTRING ';'  */
#line 861 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3994 "conf_parser.c"
    break;

  case 109: /* $@2: %empty  */
#line 871 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4003 "conf_parser.c"
    break;

  case 110: /* pseudo_entry: T_PSEUDO $@2 '{' pseudo_items '}' ';'  */
#line 875 "conf_parser.y"
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
#line 4037 "conf_parser.c"
    break;

  case 118: /* pseudo_command: T_COMMAND '=' QSTRING ';'  */
#line 909 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 4046 "conf_parser.c"
    break;

  case 119: /* pseudo_name: NAME '=' QSTRING ';'  */
#line 915 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4055 "conf_parser.c"
    break;

  case 120: /* pseudo_prepend: T_PREPEND '=' QSTRING ';'  */
#line 921 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 4064 "conf_parser.c"
    break;

  case 121: /* pseudo_target: T_TARGET '=' QSTRING ';'  */
#line 927 "conf_parser.y"
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
#line 4086 "conf_parser.c"
    break;

  case 128: /* logging_use_logging: USE_LOGGING '=' TBOOL ';'  */
#line 956 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    ConfigLog.use_logging = (yyvsp[-1].boolean);
    log_set_enabled(ConfigLog.use_logging);
  }
}
#line 4098 "conf_parser.c"
    break;

  case 129: /* $@3: %empty  */
#line 965 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4107 "conf_parser.c"
    break;

  case 130: /* logging_file_entry: $@3 T_FILE '{' logging_file_items '}' ';'  */
#line 969 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add(block_state.type.value, false, block_state.size.value,
            block_state.file.buf);
}
#line 4120 "conf_parser.c"
    break;

  case 137: /* logging_file_name: NAME '=' QSTRING ';'  */
#line 985 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 4131 "conf_parser.c"
    break;

  case 138: /* logging_file_size: T_SIZE '=' sizespec ';'  */
#line 993 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 4139 "conf_parser.c"
    break;

  case 139: /* logging_file_size: T_SIZE '=' T_UNLIMITED ';'  */
#line 996 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 4147 "conf_parser.c"
    break;

  case 140: /* $@4: %empty  */
#line 1001 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 4156 "conf_parser.c"
    break;

  case 142: /* logging_file_type_item: USER  */
#line 1007 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 4165 "conf_parser.c"
    break;

  case 143: /* logging_file_type_item: OPERATOR  */
#line 1011 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 4174 "conf_parser.c"
    break;

  case 144: /* logging_file_type_item: XLINE  */
#line 1015 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 4183 "conf_parser.c"
    break;

  case 145: /* logging_file_type_item: RESV  */
#line 1019 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 4192 "conf_parser.c"
    break;

  case 146: /* logging_file_type_item: T_DLINE  */
#line 1023 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 4201 "conf_parser.c"
    break;

  case 147: /* logging_file_type_item: KLINE  */
#line 1027 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 4210 "conf_parser.c"
    break;

  case 148: /* logging_file_type_item: KILL  */
#line 1031 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 4219 "conf_parser.c"
    break;

  case 149: /* logging_file_type_item: T_DEBUG  */
#line 1035 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 4228 "conf_parser.c"
    break;

  case 150: /* $@5: %empty  */
#line 1045 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4240 "conf_parser.c"
    break;

  case 151: /* oper_entry: OPERATOR $@5 '{' oper_items '}' ';'  */
#line 1052 "conf_parser.y"
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
#line 4298 "conf_parser.c"
    break;

  case 165: /* oper_name: NAME '=' QSTRING ';'  */
#line 1120 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4307 "conf_parser.c"
    break;

  case 166: /* oper_user: USER '=' QSTRING ';'  */
#line 1126 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4316 "conf_parser.c"
    break;

  case 167: /* oper_password: PASSWORD '=' QSTRING ';'  */
#line 1132 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4325 "conf_parser.c"
    break;

  case 168: /* oper_whois: WHOIS '=' QSTRING ';'  */
#line 1138 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 4334 "conf_parser.c"
    break;

  case 169: /* oper_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1144 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].boolean))
    block_state.flags.value |= OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_ENCRYPTED_PASSWORD;
}
#line 4348 "conf_parser.c"
    break;

  case 170: /* oper_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 1155 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 4357 "conf_parser.c"
    break;

  case 171: /* oper_tls_connection_required: TLS_CONNECTION_REQUIRED '=' TBOOL ';'  */
#line 1161 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].boolean))
    block_state.flags.value |= OPER_CONF_FLAG_REQUIRE_TLS;
  else
    block_state.flags.value &= ~OPER_CONF_FLAG_REQUIRE_TLS;
}
#line 4371 "conf_parser.c"
    break;

  case 172: /* oper_class: CLASS '=' QSTRING ';'  */
#line 1172 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4380 "conf_parser.c"
    break;

  case 173: /* oper_umodes: T_UMODES '=' QSTRING ';'  */
#line 1178 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.modes.buf, yylval.string, sizeof(block_state.modes.buf));
}
#line 4389 "conf_parser.c"
    break;

  case 174: /* $@6: %empty  */
#line 1184 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4398 "conf_parser.c"
    break;

  case 178: /* oper_flags_item: KILL ':' REMOTE  */
#line 1191 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4407 "conf_parser.c"
    break;

  case 179: /* oper_flags_item: KILL  */
#line 1195 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4416 "conf_parser.c"
    break;

  case 180: /* oper_flags_item: CONNECT ':' REMOTE  */
#line 1199 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4425 "conf_parser.c"
    break;

  case 181: /* oper_flags_item: CONNECT  */
#line 1203 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4434 "conf_parser.c"
    break;

  case 182: /* oper_flags_item: SQUIT ':' REMOTE  */
#line 1207 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4443 "conf_parser.c"
    break;

  case 183: /* oper_flags_item: SQUIT  */
#line 1211 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4452 "conf_parser.c"
    break;

  case 184: /* oper_flags_item: KLINE  */
#line 1215 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4461 "conf_parser.c"
    break;

  case 185: /* oper_flags_item: UNKLINE  */
#line 1219 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4470 "conf_parser.c"
    break;

  case 186: /* oper_flags_item: T_DLINE  */
#line 1223 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4479 "conf_parser.c"
    break;

  case 187: /* oper_flags_item: T_UNDLINE  */
#line 1227 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4488 "conf_parser.c"
    break;

  case 188: /* oper_flags_item: XLINE  */
#line 1231 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4497 "conf_parser.c"
    break;

  case 189: /* oper_flags_item: T_UNXLINE  */
#line 1235 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4506 "conf_parser.c"
    break;

  case 190: /* oper_flags_item: DIE  */
#line 1239 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4515 "conf_parser.c"
    break;

  case 191: /* oper_flags_item: T_RESTART  */
#line 1243 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4524 "conf_parser.c"
    break;

  case 192: /* oper_flags_item: REHASH ':' REMOTE  */
#line 1247 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4533 "conf_parser.c"
    break;

  case 193: /* oper_flags_item: REHASH  */
#line 1251 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4542 "conf_parser.c"
    break;

  case 194: /* oper_flags_item: ADMIN  */
#line 1255 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4551 "conf_parser.c"
    break;

  case 195: /* oper_flags_item: T_GLOBOPS  */
#line 1259 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4560 "conf_parser.c"
    break;

  case 196: /* oper_flags_item: T_LOCOPS  */
#line 1263 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4569 "conf_parser.c"
    break;

  case 197: /* oper_flags_item: REMOTEBAN  */
#line 1267 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4578 "conf_parser.c"
    break;

  case 198: /* oper_flags_item: T_SET  */
#line 1271 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4587 "conf_parser.c"
    break;

  case 199: /* oper_flags_item: MODULE  */
#line 1275 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4596 "conf_parser.c"
    break;

  case 200: /* oper_flags_item: NICK ':' RESV  */
#line 1279 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4605 "conf_parser.c"
    break;

  case 201: /* oper_flags_item: JOIN ':' RESV  */
#line 1283 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4614 "conf_parser.c"
    break;

  case 202: /* oper_flags_item: RESV  */
#line 1287 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4623 "conf_parser.c"
    break;

  case 203: /* oper_flags_item: T_UNRESV  */
#line 1291 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4632 "conf_parser.c"
    break;

  case 204: /* oper_flags_item: CLOSE  */
#line 1295 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4641 "conf_parser.c"
    break;

  case 205: /* oper_flags_item: MESSAGE ':' MASS  */
#line 1299 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MESSAGE_MASS;
}
#line 4650 "conf_parser.c"
    break;

  case 206: /* oper_flags_item: BYPASS ':' INPUT_FLOOD  */
#line 1303 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_BYPASS_INPUT_FLOOD;
}
#line 4659 "conf_parser.c"
    break;

  case 207: /* $@7: %empty  */
#line 1313 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = CLASS_DEFAULT_PING_FREQ;
  block_state.max_sendq.value = CLASS_DEFAULT_MAX_SENDQ;
  block_state.max_recvq.value = CLASS_DEFAULT_MAX_RECVQ;
}
#line 4674 "conf_parser.c"
    break;

  case 208: /* class_entry: CLASS $@7 '{' class_items '}' ';'  */
#line 1323 "conf_parser.y"
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
#line 4710 "conf_parser.c"
    break;

  case 223: /* class_name: NAME '=' QSTRING ';'  */
#line 1370 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 4719 "conf_parser.c"
    break;

  case 224: /* class_ping_time: PING_TIME '=' timespec ';'  */
#line 1376 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4728 "conf_parser.c"
    break;

  case 225: /* class_number_per_ip_local: NUMBER_PER_IP_LOCAL '=' NUMBER ';'  */
#line 1382 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4737 "conf_parser.c"
    break;

  case 226: /* class_number_per_ip_global: NUMBER_PER_IP_GLOBAL '=' NUMBER ';'  */
#line 1388 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4746 "conf_parser.c"
    break;

  case 227: /* class_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 1394 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4755 "conf_parser.c"
    break;

  case 228: /* class_max_number: MAX_NUMBER '=' NUMBER ';'  */
#line 1400 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4764 "conf_parser.c"
    break;

  case 229: /* class_sendq: SENDQ '=' sizespec ';'  */
#line 1406 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4773 "conf_parser.c"
    break;

  case 230: /* class_recvq: T_RECVQ '=' sizespec ';'  */
#line 1412 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4783 "conf_parser.c"
    break;

  case 231: /* class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'  */
#line 1419 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4792 "conf_parser.c"
    break;

  case 232: /* class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'  */
#line 1425 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4801 "conf_parser.c"
    break;

  case 233: /* class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'  */
#line 1431 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4810 "conf_parser.c"
    break;

  case 234: /* $@8: %empty  */
#line 1440 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4819 "conf_parser.c"
    break;

  case 236: /* $@9: %empty  */
#line 1446 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4827 "conf_parser.c"
    break;

  case 240: /* listen_flags_item: T_TLS  */
#line 1452 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4836 "conf_parser.c"
    break;

  case 241: /* listen_flags_item: HIDDEN  */
#line 1456 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4845 "conf_parser.c"
    break;

  case 242: /* listen_flags_item: T_SERVER  */
#line 1460 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4854 "conf_parser.c"
    break;

  case 243: /* listen_flags_item: CLIENT  */
#line 1464 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4863 "conf_parser.c"
    break;

  case 244: /* listen_flags_item: DEFER  */
#line 1468 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4872 "conf_parser.c"
    break;

  case 252: /* $@10: %empty  */
#line 1476 "conf_parser.y"
                                 { reset_block_state(); }
#line 4878 "conf_parser.c"
    break;

  case 256: /* port_item: port_number  */
#line 1481 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    _conf_parser_add_listeners((uint16_t)(yyvsp[0].number), (uint16_t)(yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
}
#line 4887 "conf_parser.c"
    break;

  case 257: /* port_item: port_number TWODOTS port_number  */
#line 1485 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    _conf_parser_add_listeners((uint16_t)(yyvsp[-2].number), (uint16_t)(yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
}
#line 4896 "conf_parser.c"
    break;

  case 258: /* listen_address: IP '=' QSTRING ';'  */
#line 1491 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4905 "conf_parser.c"
    break;

  case 259: /* listen_host: HOST '=' QSTRING ';'  */
#line 1497 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4914 "conf_parser.c"
    break;

  case 260: /* $@11: %empty  */
#line 1507 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4923 "conf_parser.c"
    break;

  case 261: /* auth_entry: IRCD_AUTH $@11 '{' auth_items '}' ';'  */
#line 1511 "conf_parser.y"
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
#line 4978 "conf_parser.c"
    break;

  case 271: /* auth_user: USER '=' QSTRING ';'  */
#line 1572 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 4987 "conf_parser.c"
    break;

  case 272: /* auth_passwd: PASSWORD '=' QSTRING ';'  */
#line 1578 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4996 "conf_parser.c"
    break;

  case 273: /* auth_class: CLASS '=' QSTRING ';'  */
#line 1584 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5005 "conf_parser.c"
    break;

  case 274: /* auth_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 1590 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].boolean))
      block_state.flags.value |= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5019 "conf_parser.c"
    break;

  case 275: /* $@12: %empty  */
#line 1601 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_AUTH_FLAG_ENCRYPTED_PASSWORD;
}
#line 5028 "conf_parser.c"
    break;

  case 279: /* auth_flags_item: EXCEED_LIMIT  */
#line 1609 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_LIMITS;
}
#line 5037 "conf_parser.c"
    break;

  case 280: /* auth_flags_item: KLINE_EXEMPT  */
#line 1613 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_KLINE;
}
#line 5046 "conf_parser.c"
    break;

  case 281: /* auth_flags_item: XLINE_EXEMPT  */
#line 1617 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_XLINE;
}
#line 5055 "conf_parser.c"
    break;

  case 282: /* auth_flags_item: NEED_IDENT  */
#line 1621 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REQUIRE_IDENT;
}
#line 5064 "conf_parser.c"
    break;

  case 283: /* auth_flags_item: CAN_FLOOD  */
#line 1625 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_CAN_FLOOD;
}
#line 5073 "conf_parser.c"
    break;

  case 284: /* auth_flags_item: NO_TILDE  */
#line 1629 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_NO_TILDE;
}
#line 5082 "conf_parser.c"
    break;

  case 285: /* auth_flags_item: RESV_EXEMPT  */
#line 1633 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_EXEMPT_RESV;
}
#line 5091 "conf_parser.c"
    break;

  case 286: /* auth_flags_item: T_WEBIRC  */
#line 1637 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_WEBIRC;
}
#line 5100 "conf_parser.c"
    break;

  case 287: /* auth_flags_item: NEED_PASSWORD  */
#line 1641 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH;
}
#line 5109 "conf_parser.c"
    break;

  case 288: /* auth_spoof: SPOOF '=' QSTRING ';'  */
#line 1647 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (hostname_is_valid(yylval.string))
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  else
    conf_report_warning("Invalid auth::spoof; ignoring value");
}
#line 5123 "conf_parser.c"
    break;

  case 289: /* $@13: %empty  */
#line 1661 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 5135 "conf_parser.c"
    break;

  case 290: /* resv_entry: RESV $@13 '{' resv_items '}' ';'  */
#line 1668 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  const struct conf_resv_spec spec =
  {
    .mask = block_state.name.buf,
    .reason = block_state.rpass.buf,
    .exemptions = &block_state.mask.list,
    .origin = CONF_RESV_ORIGIN_CONFIG
  };
  if (conf_resv_add(&spec) == NULL)
    conf_report_error("Unable to add reservation");
}
#line 5154 "conf_parser.c"
    break;

  case 297: /* resv_mask: MASK '=' QSTRING ';'  */
#line 1687 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5163 "conf_parser.c"
    break;

  case 298: /* resv_reason: REASON '=' QSTRING ';'  */
#line 1693 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5172 "conf_parser.c"
    break;

  case 299: /* resv_exempt: EXEMPT '=' QSTRING ';'  */
#line 1699 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.mask.list);
}
#line 5181 "conf_parser.c"
    break;

  case 305: /* service_name: NAME '=' QSTRING ';'  */
#line 1714 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_is_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = io_strdup(yylval.string);
  }
}
#line 5196 "conf_parser.c"
    break;

  case 306: /* $@14: %empty  */
#line 1730 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5212 "conf_parser.c"
    break;

  case 307: /* shared_entry: T_SHARED $@14 '{' shared_items '}' ';'  */
#line 1741 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = io_strdup(block_state.name.buf);
  shared->user = io_strdup(block_state.user.buf);
  shared->host = io_strdup(block_state.host.buf);
}
#line 5227 "conf_parser.c"
    break;

  case 314: /* shared_name: NAME '=' QSTRING ';'  */
#line 1756 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5236 "conf_parser.c"
    break;

  case 315: /* shared_user: USER '=' QSTRING ';'  */
#line 1762 "conf_parser.y"
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
#line 5258 "conf_parser.c"
    break;

  case 316: /* $@15: %empty  */
#line 1781 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5267 "conf_parser.c"
    break;

  case 320: /* shared_type_item: KLINE  */
#line 1788 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5276 "conf_parser.c"
    break;

  case 321: /* shared_type_item: UNKLINE  */
#line 1792 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5285 "conf_parser.c"
    break;

  case 322: /* shared_type_item: T_DLINE  */
#line 1796 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5294 "conf_parser.c"
    break;

  case 323: /* shared_type_item: T_UNDLINE  */
#line 1800 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5303 "conf_parser.c"
    break;

  case 324: /* shared_type_item: XLINE  */
#line 1804 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5312 "conf_parser.c"
    break;

  case 325: /* shared_type_item: T_UNXLINE  */
#line 1808 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5321 "conf_parser.c"
    break;

  case 326: /* shared_type_item: REHASH  */
#line 1812 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_REHASH;
}
#line 5330 "conf_parser.c"
    break;

  case 327: /* shared_type_item: RESV  */
#line 1816 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5339 "conf_parser.c"
    break;

  case 328: /* shared_type_item: T_UNRESV  */
#line 1820 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5348 "conf_parser.c"
    break;

  case 329: /* shared_type_item: T_LOCOPS  */
#line 1824 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5357 "conf_parser.c"
    break;

  case 330: /* shared_type_item: T_ALL  */
#line 1828 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5366 "conf_parser.c"
    break;

  case 331: /* $@16: %empty  */
#line 1838 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5380 "conf_parser.c"
    break;

  case 332: /* cluster_entry: T_CLUSTER $@16 '{' cluster_items '}' ';'  */
#line 1847 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = io_strdup(block_state.name.buf);
}
#line 5393 "conf_parser.c"
    break;

  case 338: /* cluster_name: NAME '=' QSTRING ';'  */
#line 1860 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5402 "conf_parser.c"
    break;

  case 339: /* $@17: %empty  */
#line 1866 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5411 "conf_parser.c"
    break;

  case 343: /* cluster_type_item: KLINE  */
#line 1873 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5420 "conf_parser.c"
    break;

  case 344: /* cluster_type_item: UNKLINE  */
#line 1877 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5429 "conf_parser.c"
    break;

  case 345: /* cluster_type_item: T_DLINE  */
#line 1881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5438 "conf_parser.c"
    break;

  case 346: /* cluster_type_item: T_UNDLINE  */
#line 1885 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5447 "conf_parser.c"
    break;

  case 347: /* cluster_type_item: XLINE  */
#line 1889 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5456 "conf_parser.c"
    break;

  case 348: /* cluster_type_item: T_UNXLINE  */
#line 1893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5465 "conf_parser.c"
    break;

  case 349: /* cluster_type_item: RESV  */
#line 1897 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5474 "conf_parser.c"
    break;

  case 350: /* cluster_type_item: T_UNRESV  */
#line 1901 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5483 "conf_parser.c"
    break;

  case 351: /* cluster_type_item: T_LOCOPS  */
#line 1905 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5492 "conf_parser.c"
    break;

  case 352: /* cluster_type_item: T_ALL  */
#line 1909 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5501 "conf_parser.c"
    break;

  case 353: /* $@18: %empty  */
#line 1919 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.timeout.value = CONNECT_DEFAULT_TIMEOUT_SEC;
  block_state.retry_delay_sec.value = CONNECT_DEFAULT_RETRY_DELAY_SEC;
}
#line 5516 "conf_parser.c"
    break;

  case 354: /* connect_entry: CONNECT $@18 '{' connect_items '}' ';'  */
#line 1929 "conf_parser.y"
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
#line 5565 "conf_parser.c"
    break;

  case 373: /* connect_name: NAME '=' QSTRING ';'  */
#line 1993 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5574 "conf_parser.c"
    break;

  case 374: /* connect_host: HOST '=' QSTRING ';'  */
#line 1999 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5583 "conf_parser.c"
    break;

  case 375: /* connect_timeout: TIMEOUT '=' timespec ';'  */
#line 2005 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5592 "conf_parser.c"
    break;

  case 376: /* connect_retry_delay: RETRY_DELAY '=' timespec ';'  */
#line 2011 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.retry_delay_sec.value = (yyvsp[-1].number);
}
#line 5601 "conf_parser.c"
    break;

  case 377: /* connect_bind: T_BIND '=' QSTRING ';'  */
#line 2017 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5610 "conf_parser.c"
    break;

  case 378: /* connect_send_password: SEND_PASSWORD '=' QSTRING ';'  */
#line 2023 "conf_parser.y"
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
#line 5626 "conf_parser.c"
    break;

  case 379: /* connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'  */
#line 2036 "conf_parser.y"
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
#line 5642 "conf_parser.c"
    break;

  case 380: /* connect_tls_certificate_fingerprint: TLS_CERTIFICATE_FINGERPRINT '=' QSTRING ';'  */
#line 2049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5651 "conf_parser.c"
    break;

  case 381: /* connect_port: PORT '=' port_number ';'  */
#line 2055 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5660 "conf_parser.c"
    break;

  case 382: /* connect_aftype: AFTYPE '=' T_IPV4 ';'  */
#line 2061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5669 "conf_parser.c"
    break;

  case 383: /* connect_aftype: AFTYPE '=' T_IPV6 ';'  */
#line 2065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5678 "conf_parser.c"
    break;

  case 384: /* $@19: %empty  */
#line 2071 "conf_parser.y"
{
  block_state.flags.value &= CONNECT_FLAG_ENCRYPTED_PASSWORD;
}
#line 5686 "conf_parser.c"
    break;

  case 388: /* connect_flags_item: AUTOCONN  */
#line 2077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_ALLOW_AUTO_CONN;
}
#line 5695 "conf_parser.c"
    break;

  case 389: /* connect_flags_item: T_TLS  */
#line 2081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONNECT_FLAG_USE_TLS;
}
#line 5704 "conf_parser.c"
    break;

  case 390: /* connect_encrypted: ENCRYPTED '=' TBOOL ';'  */
#line 2087 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].boolean))
      block_state.flags.value |= CONNECT_FLAG_ENCRYPTED_PASSWORD;
    else
      block_state.flags.value &= ~CONNECT_FLAG_ENCRYPTED_PASSWORD;
  }
}
#line 5718 "conf_parser.c"
    break;

  case 391: /* connect_hub_mask: HUB_MASK '=' QSTRING ';'  */
#line 2098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.hub.list);
}
#line 5727 "conf_parser.c"
    break;

  case 392: /* connect_leaf_mask: LEAF_MASK '=' QSTRING ';'  */
#line 2104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    list_add(io_strdup(yylval.string), list_make_node(), &block_state.leaf.list);
}
#line 5736 "conf_parser.c"
    break;

  case 393: /* connect_class: CLASS '=' QSTRING ';'  */
#line 2110 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.klass.buf, yylval.string, sizeof(block_state.klass.buf));
}
#line 5745 "conf_parser.c"
    break;

  case 394: /* $@20: %empty  */
#line 2120 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5754 "conf_parser.c"
    break;

  case 395: /* kill_entry: KILL $@20 '{' kill_items '}' ';'  */
#line 2124 "conf_parser.y"
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
#line 5778 "conf_parser.c"
    break;

  case 401: /* kill_user: USER '=' QSTRING ';'  */
#line 2148 "conf_parser.y"
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
#line 5801 "conf_parser.c"
    break;

  case 402: /* kill_reason: REASON '=' QSTRING ';'  */
#line 2168 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5810 "conf_parser.c"
    break;

  case 403: /* $@21: %empty  */
#line 2178 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5819 "conf_parser.c"
    break;

  case 404: /* deny_entry: DENY $@21 '{' deny_items '}' ';'  */
#line 2182 "conf_parser.y"
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
#line 5841 "conf_parser.c"
    break;

  case 410: /* deny_ip: IP '=' QSTRING ';'  */
#line 2204 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5850 "conf_parser.c"
    break;

  case 411: /* deny_reason: REASON '=' QSTRING ';'  */
#line 2210 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5859 "conf_parser.c"
    break;

  case 417: /* exempt_ip: IP '=' QSTRING ';'  */
#line 2225 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (conf_exempt_add(yylval.string) == NULL)
    conf_report_error("Unable to add D-line exemption");
}
#line 5871 "conf_parser.c"
    break;

  case 418: /* $@22: %empty  */
#line 2238 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5880 "conf_parser.c"
    break;

  case 419: /* gecos_entry: GECOS $@22 '{' gecos_items '}' ';'  */
#line 2242 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  const struct conf_gecos_spec spec =
  {
    .mask = block_state.name.buf,
    .reason = block_state.rpass.buf[0] ? block_state.rpass.buf : CONF_NOREASON,
    .origin = CONF_GECOS_ORIGIN_CONFIG
  };
  if (conf_gecos_add(&spec) == NULL)
    conf_report_error("Unable to add X-line");
}
#line 5898 "conf_parser.c"
    break;

  case 425: /* gecos_name: NAME '=' QSTRING ';'  */
#line 2260 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5907 "conf_parser.c"
    break;

  case 426: /* gecos_reason: REASON '=' QSTRING ';'  */
#line 2266 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5916 "conf_parser.c"
    break;

  case 471: /* general_away_count: AWAY_COUNT '=' NUMBER ';'  */
#line 2322 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5924 "conf_parser.c"
    break;

  case 472: /* general_away_time: AWAY_TIME '=' timespec ';'  */
#line 2327 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5932 "conf_parser.c"
    break;

  case 473: /* general_max_monitor: MAX_MONITOR '=' NUMBER ';'  */
#line 2332 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5940 "conf_parser.c"
    break;

  case 474: /* general_whowas_history_length: WHOWAS_HISTORY_LENGTH '=' NUMBER ';'  */
#line 2337 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5948 "conf_parser.c"
    break;

  case 475: /* general_dline_min_cidr: DLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2342 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5956 "conf_parser.c"
    break;

  case 476: /* general_dline_min_cidr6: DLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2347 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5964 "conf_parser.c"
    break;

  case 477: /* general_kline_min_cidr: KLINE_MIN_CIDR '=' NUMBER ';'  */
#line 2352 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5972 "conf_parser.c"
    break;

  case 478: /* general_kline_min_cidr6: KLINE_MIN_CIDR6 '=' NUMBER ';'  */
#line 2357 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5980 "conf_parser.c"
    break;

  case 479: /* general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'  */
#line 2362 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5988 "conf_parser.c"
    break;

  case 480: /* general_max_nick_time: MAX_NICK_TIME '=' timespec ';'  */
#line 2367 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5996 "conf_parser.c"
    break;

  case 481: /* general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'  */
#line 2372 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 6004 "conf_parser.c"
    break;

  case 482: /* general_max_accept: MAX_ACCEPT '=' NUMBER ';'  */
#line 2377 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 6012 "conf_parser.c"
    break;

  case 483: /* general_max_away_length: MAX_AWAY_LENGTH '=' NUMBER ';'  */
#line 2382 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > AWAYLEN)
    ConfigGeneral.max_away_length = AWAYLEN;
  else
    ConfigGeneral.max_away_length = (yyvsp[-1].number);
}
#line 6023 "conf_parser.c"
    break;

  case 484: /* general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'  */
#line 2390 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 6031 "conf_parser.c"
    break;

  case 485: /* general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'  */
#line 2395 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 6039 "conf_parser.c"
    break;

  case 486: /* general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'  */
#line 2400 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 6047 "conf_parser.c"
    break;

  case 487: /* general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'  */
#line 2405 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = (yyvsp[-1].boolean);
}
#line 6055 "conf_parser.c"
    break;

  case 488: /* general_warn_no_connect_block: WARN_NO_CONNECT_BLOCK '=' TBOOL ';'  */
#line 2410 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = (yyvsp[-1].boolean);
}
#line 6063 "conf_parser.c"
    break;

  case 489: /* general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'  */
#line 2415 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = (yyvsp[-1].boolean);
}
#line 6071 "conf_parser.c"
    break;

  case 490: /* general_stats_u_oper_only: STATS_U_OPER_ONLY '=' TBOOL ';'  */
#line 2420 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = (yyvsp[-1].boolean);
}
#line 6079 "conf_parser.c"
    break;

  case 491: /* general_pace_wait: PACE_WAIT '=' timespec ';'  */
#line 2425 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6087 "conf_parser.c"
    break;

  case 492: /* general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'  */
#line 2430 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6095 "conf_parser.c"
    break;

  case 493: /* general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'  */
#line 2435 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = (yyvsp[-1].boolean);
}
#line 6103 "conf_parser.c"
    break;

  case 494: /* general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'  */
#line 2440 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6111 "conf_parser.c"
    break;

  case 495: /* general_short_motd: SHORT_MOTD '=' TBOOL ';'  */
#line 2445 "conf_parser.y"
{
  ConfigGeneral.short_motd = (yyvsp[-1].boolean);
}
#line 6119 "conf_parser.c"
    break;

  case 496: /* general_specials_in_ident: SPECIALS_IN_IDENT '=' NUMBER ';'  */
#line 2450 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 6127 "conf_parser.c"
    break;

  case 497: /* general_max_targets: MAX_TARGETS '=' NUMBER ';'  */
#line 2455 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6135 "conf_parser.c"
    break;

  case 498: /* general_ping_cookie: PING_COOKIE '=' TBOOL ';'  */
#line 2460 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = (yyvsp[-1].boolean);
}
#line 6143 "conf_parser.c"
    break;

  case 499: /* general_disable_ident: DISABLE_IDENT '=' TBOOL ';'  */
#line 2465 "conf_parser.y"
{
  ConfigGeneral.disable_ident = (yyvsp[-1].boolean);
}
#line 6151 "conf_parser.c"
    break;

  case 500: /* general_disable_dns: DISABLE_DNS '=' TBOOL ';'  */
#line 2470 "conf_parser.y"
{
  ConfigGeneral.disable_dns = (yyvsp[-1].boolean);
}
#line 6159 "conf_parser.c"
    break;

  case 501: /* general_throttle_count: THROTTLE_COUNT '=' NUMBER ';'  */
#line 2475 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6167 "conf_parser.c"
    break;

  case 502: /* general_throttle_time: THROTTLE_TIME '=' timespec ';'  */
#line 2480 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6175 "conf_parser.c"
    break;

  case 503: /* general_oper_umodes: OPER_UMODES '=' QSTRING ';'  */
#line 2485 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = io_strdup(yylval.string);
}
#line 6187 "conf_parser.c"
    break;

  case 504: /* general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'  */
#line 2494 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6195 "conf_parser.c"
    break;

  case 505: /* general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'  */
#line 2499 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6203 "conf_parser.c"
    break;

  case 506: /* general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'  */
#line 2504 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6211 "conf_parser.c"
    break;

  case 507: /* general_default_floodtime: DEFAULT_FLOODTIME '=' timespec ';'  */
#line 2509 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6219 "conf_parser.c"
    break;

  case 508: /* general_ident_timeout: IDENT_TIMEOUT '=' timespec ';'  */
#line 2514 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > 30)
    break;

  ConfigGeneral.ident_timeout = (yyvsp[-1].number);
}
#line 6230 "conf_parser.c"
    break;

  case 509: /* general_registration_timeout: REGISTRATION_TIMEOUT '=' timespec ';'  */
#line 2522 "conf_parser.y"
{
  ConfigGeneral.registration_timeout = (yyvsp[-1].number);
}
#line 6238 "conf_parser.c"
    break;

  case 510: /* general_sasl_service: SASL_SERVICE '=' QSTRING ';'  */
#line 2527 "conf_parser.y"
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
#line 6261 "conf_parser.c"
    break;

  case 521: /* cloak_enabled: ENABLED '=' TBOOL ';'  */
#line 2562 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.enabled = (yyvsp[-1].boolean);
  if (ConfigCloak.enabled)
    cloak_set_enabled();
  else
    cloak_set_disabled();
}
#line 6276 "conf_parser.c"
    break;

  case 522: /* cloak_cidr_len_ipv4: CIDR_LEN_IPV4 '=' NUMBER ';'  */
#line 2574 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv4 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv4((yyvsp[-1].number));
}
#line 6288 "conf_parser.c"
    break;

  case 523: /* cloak_cidr_len_ipv6: CIDR_LEN_IPV6 '=' NUMBER ';'  */
#line 2583 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.cidr_len_ipv6 = (yyvsp[-1].number);
  cloak_set_cidr_len_ipv6((yyvsp[-1].number));
}
#line 6300 "conf_parser.c"
    break;

  case 524: /* cloak_num_bits: NUM_BITS '=' NUMBER ';'  */
#line 2592 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  ConfigCloak.num_bits = (yyvsp[-1].number);
  cloak_set_num_bits((yyvsp[-1].number));
}
#line 6312 "conf_parser.c"
    break;

  case 525: /* cloak_secret: SECRET '=' QSTRING ';'  */
#line 2601 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.secret);
  ConfigCloak.secret = io_strdup((yyvsp[-1].string));
  cloak_set_secret((yyvsp[-1].string));
}
#line 6325 "conf_parser.c"
    break;

  case 526: /* cloak_suffix: SUFFIX '=' QSTRING ';'  */
#line 2611 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  io_free(ConfigCloak.suffix);
  ConfigCloak.suffix = io_strdup((yyvsp[-1].string));
  cloak_set_suffix((yyvsp[-1].string));
}
#line 6338 "conf_parser.c"
    break;

  case 547: /* channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'  */
#line 2646 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = (yyvsp[-1].boolean);
}
#line 6346 "conf_parser.c"
    break;

  case 548: /* channel_invite_client_count: INVITE_CLIENT_COUNT '=' NUMBER ';'  */
#line 2651 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6354 "conf_parser.c"
    break;

  case 549: /* channel_invite_client_time: INVITE_CLIENT_TIME '=' timespec ';'  */
#line 2656 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6362 "conf_parser.c"
    break;

  case 550: /* channel_invite_delay_channel: INVITE_DELAY_CHANNEL '=' timespec ';'  */
#line 2661 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6370 "conf_parser.c"
    break;

  case 551: /* channel_invite_expire_time: INVITE_EXPIRE_TIME '=' timespec ';'  */
#line 2666 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6378 "conf_parser.c"
    break;

  case 552: /* channel_knock_client_count: KNOCK_CLIENT_COUNT '=' NUMBER ';'  */
#line 2671 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6386 "conf_parser.c"
    break;

  case 553: /* channel_knock_client_time: KNOCK_CLIENT_TIME '=' timespec ';'  */
#line 2676 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6394 "conf_parser.c"
    break;

  case 554: /* channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'  */
#line 2681 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6402 "conf_parser.c"
    break;

  case 555: /* channel_max_channels: MAX_CHANNELS '=' NUMBER ';'  */
#line 2686 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6410 "conf_parser.c"
    break;

  case 556: /* channel_max_invites: MAX_INVITES '=' NUMBER ';'  */
#line 2691 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6418 "conf_parser.c"
    break;

  case 557: /* channel_max_bans: MAX_BANS '=' NUMBER ';'  */
#line 2696 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6426 "conf_parser.c"
    break;

  case 558: /* channel_max_bans_large: MAX_BANS_LARGE '=' NUMBER ';'  */
#line 2701 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6434 "conf_parser.c"
    break;

  case 559: /* channel_max_kick_length: MAX_KICK_LENGTH '=' NUMBER ';'  */
#line 2706 "conf_parser.y"
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
#line 6455 "conf_parser.c"
    break;

  case 560: /* channel_max_topic_length: MAX_TOPIC_LENGTH '=' NUMBER ';'  */
#line 2724 "conf_parser.y"
{
  if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > TOPICLEN)
    ConfigChannel.max_topic_length = TOPICLEN;
  else
    ConfigChannel.max_topic_length = (yyvsp[-1].number);
}
#line 6466 "conf_parser.c"
    break;

  case 561: /* channel_default_join_flood_count: DEFAULT_JOIN_FLOOD_COUNT '=' NUMBER ';'  */
#line 2732 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = (yyvsp[-1].number);
}
#line 6474 "conf_parser.c"
    break;

  case 562: /* channel_default_join_flood_time: DEFAULT_JOIN_FLOOD_TIME '=' timespec ';'  */
#line 2737 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6482 "conf_parser.c"
    break;

  case 575: /* serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'  */
#line 2759 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = (yyvsp[-1].boolean);
}
#line 6491 "conf_parser.c"
    break;

  case 576: /* serverhide_flatten_links_delay: FLATTEN_LINKS_DELAY '=' timespec ';'  */
#line 2765 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    uintmax_t interval_seconds = (yyvsp[-1].number);
    ConfigServerHide.flatten_links_delay = interval_seconds;

    links_cache_set_timer(interval_seconds);
  }
}
#line 6505 "conf_parser.c"
    break;

  case 577: /* serverhide_flatten_links_file: FLATTEN_LINKS_FILE '=' QSTRING ';'  */
#line 2776 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = io_strdup(yylval.string);
  }
}
#line 6517 "conf_parser.c"
    break;

  case 578: /* serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'  */
#line 2785 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = (yyvsp[-1].boolean);
}
#line 6526 "conf_parser.c"
    break;

  case 579: /* serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'  */
#line 2791 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = (yyvsp[-1].boolean);
}
#line 6535 "conf_parser.c"
    break;

  case 580: /* serverhide_hide_services: HIDE_SERVICES '=' TBOOL ';'  */
#line 2797 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = (yyvsp[-1].boolean);
}
#line 6544 "conf_parser.c"
    break;

  case 581: /* serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'  */
#line 2803 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    io_free(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = io_strdup(yylval.string);
  }
}
#line 6556 "conf_parser.c"
    break;

  case 582: /* serverhide_hidden: HIDDEN '=' TBOOL ';'  */
#line 2812 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = (yyvsp[-1].boolean);
}
#line 6565 "conf_parser.c"
    break;


#line 6569 "conf_parser.c"

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

