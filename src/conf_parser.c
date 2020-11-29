/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 28 "conf_parser.y"


#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "parse.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_cluster.h"
#include "conf_gecos.h"
#include "conf_pseudo.h"
#include "conf_resv.h"
#include "conf_service.h"
#include "conf_shared.h"
#include "event.h"
#include "id.h"
#include "log.h"
#include "irc_string.h"
#include "memory.h"
#include "modules.h"
#include "server.h"
#include "hostmask.h"
#include "listener.h"
#include "user.h"
#include "motd.h"

int yylex(void);

static struct
{
  struct
  {
    dlink_list list;
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
    ciph,
    cert,
    rpass,
    spass,
    whois,
    class,
    target,
    prepend,
    command;

  struct
  {
    unsigned int value;
  } flags,
    modes,
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
  dlink_node *node, *node_next;
  dlink_list *tab[] = { &block_state.mask.list,
                        &block_state.leaf.list, &block_state.hub.list, NULL };

  for (dlink_list **list = tab; *list; ++list)
  {
    DLINK_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      xfree(node->data);
      dlinkDelete(node, *list);
      free_dlink_node(node);
    }
  }

  memset(&block_state, 0, sizeof(block_state));
}


#line 175 "conf_parser.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ACCEPT_PASSWORD = 258,
    ADMIN = 259,
    AFTYPE = 260,
    ANTI_NICK_FLOOD = 261,
    ANTI_SPAM_EXIT_MESSAGE_TIME = 262,
    AUTOCONN = 263,
    AWAY_COUNT = 264,
    AWAY_TIME = 265,
    BYTES = 266,
    KBYTES = 267,
    MBYTES = 268,
    CALLER_ID_WAIT = 269,
    CAN_FLOOD = 270,
    CHANNEL = 271,
    CIDR_BITLEN_IPV4 = 272,
    CIDR_BITLEN_IPV6 = 273,
    CLASS = 274,
    CLIENT = 275,
    CLOSE = 276,
    CONNECT = 277,
    CONNECTFREQ = 278,
    CYCLE_ON_HOST_CHANGE = 279,
    DEFAULT_FLOODCOUNT = 280,
    DEFAULT_FLOODTIME = 281,
    DEFAULT_JOIN_FLOOD_COUNT = 282,
    DEFAULT_JOIN_FLOOD_TIME = 283,
    DEFAULT_MAX_CLIENTS = 284,
    DEFER = 285,
    DENY = 286,
    DESCRIPTION = 287,
    DIE = 288,
    DISABLE_AUTH = 289,
    DISABLE_FAKE_CHANNELS = 290,
    DISABLE_REMOTE_COMMANDS = 291,
    DLINE_MIN_CIDR = 292,
    DLINE_MIN_CIDR6 = 293,
    DOTS_IN_IDENT = 294,
    EMAIL = 295,
    ENABLE_EXTBANS = 296,
    ENCRYPTED = 297,
    EXCEED_LIMIT = 298,
    EXEMPT = 299,
    EXPIRATION = 300,
    FAILED_OPER_NOTICE = 301,
    FLATTEN_LINKS = 302,
    FLATTEN_LINKS_DELAY = 303,
    FLATTEN_LINKS_FILE = 304,
    GECOS = 305,
    GENERAL = 306,
    HIDDEN = 307,
    HIDDEN_NAME = 308,
    HIDE_CHANS = 309,
    HIDE_IDLE = 310,
    HIDE_IDLE_FROM_OPERS = 311,
    HIDE_SERVER_IPS = 312,
    HIDE_SERVERS = 313,
    HIDE_SERVICES = 314,
    HOST = 315,
    HUB = 316,
    HUB_MASK = 317,
    INVISIBLE_ON_CONNECT = 318,
    INVITE_CLIENT_COUNT = 319,
    INVITE_CLIENT_TIME = 320,
    INVITE_DELAY_CHANNEL = 321,
    INVITE_EXPIRE_TIME = 322,
    IP = 323,
    IRCD_AUTH = 324,
    IRCD_FLAGS = 325,
    IRCD_SID = 326,
    JOIN = 327,
    KILL = 328,
    KILL_CHASE_TIME_LIMIT = 329,
    KLINE = 330,
    KLINE_EXEMPT = 331,
    KLINE_MIN_CIDR = 332,
    KLINE_MIN_CIDR6 = 333,
    KNOCK_CLIENT_COUNT = 334,
    KNOCK_CLIENT_TIME = 335,
    KNOCK_DELAY_CHANNEL = 336,
    LEAF_MASK = 337,
    LISTEN = 338,
    MASK = 339,
    MAX_ACCEPT = 340,
    MAX_BANS = 341,
    MAX_BANS_LARGE = 342,
    MAX_CHANNELS = 343,
    MAX_IDLE = 344,
    MAX_INVITES = 345,
    MAX_MONITOR = 346,
    MAX_NICK_CHANGES = 347,
    MAX_NICK_LENGTH = 348,
    MAX_NICK_TIME = 349,
    MAX_NUMBER = 350,
    MAX_TARGETS = 351,
    MAX_TOPIC_LENGTH = 352,
    MIN_IDLE = 353,
    MIN_NONWILDCARD = 354,
    MIN_NONWILDCARD_SIMPLE = 355,
    MODULE = 356,
    MODULES = 357,
    MOTD = 358,
    NAME = 359,
    NEED_IDENT = 360,
    NEED_PASSWORD = 361,
    NETWORK_DESCRIPTION = 362,
    NETWORK_NAME = 363,
    NICK = 364,
    NO_OPER_FLOOD = 365,
    NO_TILDE = 366,
    NUMBER_PER_CIDR = 367,
    NUMBER_PER_IP_GLOBAL = 368,
    NUMBER_PER_IP_LOCAL = 369,
    OPER_ONLY_UMODES = 370,
    OPER_UMODES = 371,
    OPERATOR = 372,
    OPERS_BYPASS_CALLERID = 373,
    PACE_WAIT = 374,
    PACE_WAIT_SIMPLE = 375,
    PASSWORD = 376,
    PATH = 377,
    PING_COOKIE = 378,
    PING_TIME = 379,
    PORT = 380,
    RANDOM_IDLE = 381,
    REASON = 382,
    REDIRPORT = 383,
    REDIRSERV = 384,
    REHASH = 385,
    REMOTE = 386,
    REMOTEBAN = 387,
    RESV = 388,
    RESV_EXEMPT = 389,
    RSA_PRIVATE_KEY_FILE = 390,
    SECONDS = 391,
    MINUTES = 392,
    HOURS = 393,
    DAYS = 394,
    WEEKS = 395,
    MONTHS = 396,
    YEARS = 397,
    SEND_PASSWORD = 398,
    SENDQ = 399,
    SERVERHIDE = 400,
    SERVERINFO = 401,
    SHORT_MOTD = 402,
    SPOOF = 403,
    SQUIT = 404,
    STATS_E_DISABLED = 405,
    STATS_I_OPER_ONLY = 406,
    STATS_K_OPER_ONLY = 407,
    STATS_M_OPER_ONLY = 408,
    STATS_O_OPER_ONLY = 409,
    STATS_P_OPER_ONLY = 410,
    STATS_U_OPER_ONLY = 411,
    T_ALL = 412,
    T_BIND = 413,
    T_CALLERID = 414,
    T_CCONN = 415,
    T_COMMAND = 416,
    T_CLUSTER = 417,
    T_DEAF = 418,
    T_DEBUG = 419,
    T_DLINE = 420,
    T_EXTERNAL = 421,
    T_FARCONNECT = 422,
    T_FILE = 423,
    T_FLOOD = 424,
    T_GLOBOPS = 425,
    T_INVISIBLE = 426,
    T_IPV4 = 427,
    T_IPV6 = 428,
    T_LOCOPS = 429,
    T_LOG = 430,
    T_NCHANGE = 431,
    T_NONONREG = 432,
    T_OPME = 433,
    T_PREPEND = 434,
    T_PSEUDO = 435,
    T_RECVQ = 436,
    T_REJ = 437,
    T_RESTART = 438,
    T_SERVER = 439,
    T_SERVICE = 440,
    T_SERVNOTICE = 441,
    T_SET = 442,
    T_SHARED = 443,
    T_SIZE = 444,
    T_SKILL = 445,
    T_SOFTCALLERID = 446,
    T_SPY = 447,
    T_TARGET = 448,
    T_TLS = 449,
    T_UMODES = 450,
    T_UNDLINE = 451,
    T_UNLIMITED = 452,
    T_UNRESV = 453,
    T_UNXLINE = 454,
    T_WALLOP = 455,
    T_WALLOPS = 456,
    T_WEBIRC = 457,
    TBOOL = 458,
    THROTTLE_COUNT = 459,
    THROTTLE_TIME = 460,
    TIMEOUT = 461,
    TLS_CERTIFICATE_FILE = 462,
    TLS_CERTIFICATE_FINGERPRINT = 463,
    TLS_CIPHER_LIST = 464,
    TLS_CIPHER_SUITES = 465,
    TLS_CONNECTION_REQUIRED = 466,
    TLS_DH_PARAM_FILE = 467,
    TLS_MESSAGE_DIGEST_ALGORITHM = 468,
    TLS_SUPPORTED_GROUPS = 469,
    TS_MAX_DELTA = 470,
    TS_WARN_DELTA = 471,
    TWODOTS = 472,
    TYPE = 473,
    UNKLINE = 474,
    USE_LOGGING = 475,
    USER = 476,
    VHOST = 477,
    VHOST6 = 478,
    WARN_NO_CONNECT_BLOCK = 479,
    WHOIS = 480,
    WHOWAS_HISTORY_LENGTH = 481,
    XLINE = 482,
    XLINE_EXEMPT = 483,
    QSTRING = 484,
    NUMBER = 485
  };
#endif
/* Tokens.  */
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
#define CLASS 274
#define CLIENT 275
#define CLOSE 276
#define CONNECT 277
#define CONNECTFREQ 278
#define CYCLE_ON_HOST_CHANGE 279
#define DEFAULT_FLOODCOUNT 280
#define DEFAULT_FLOODTIME 281
#define DEFAULT_JOIN_FLOOD_COUNT 282
#define DEFAULT_JOIN_FLOOD_TIME 283
#define DEFAULT_MAX_CLIENTS 284
#define DEFER 285
#define DENY 286
#define DESCRIPTION 287
#define DIE 288
#define DISABLE_AUTH 289
#define DISABLE_FAKE_CHANNELS 290
#define DISABLE_REMOTE_COMMANDS 291
#define DLINE_MIN_CIDR 292
#define DLINE_MIN_CIDR6 293
#define DOTS_IN_IDENT 294
#define EMAIL 295
#define ENABLE_EXTBANS 296
#define ENCRYPTED 297
#define EXCEED_LIMIT 298
#define EXEMPT 299
#define EXPIRATION 300
#define FAILED_OPER_NOTICE 301
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
#define HIDE_SERVER_IPS 312
#define HIDE_SERVERS 313
#define HIDE_SERVICES 314
#define HOST 315
#define HUB 316
#define HUB_MASK 317
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
#define MASK 339
#define MAX_ACCEPT 340
#define MAX_BANS 341
#define MAX_BANS_LARGE 342
#define MAX_CHANNELS 343
#define MAX_IDLE 344
#define MAX_INVITES 345
#define MAX_MONITOR 346
#define MAX_NICK_CHANGES 347
#define MAX_NICK_LENGTH 348
#define MAX_NICK_TIME 349
#define MAX_NUMBER 350
#define MAX_TARGETS 351
#define MAX_TOPIC_LENGTH 352
#define MIN_IDLE 353
#define MIN_NONWILDCARD 354
#define MIN_NONWILDCARD_SIMPLE 355
#define MODULE 356
#define MODULES 357
#define MOTD 358
#define NAME 359
#define NEED_IDENT 360
#define NEED_PASSWORD 361
#define NETWORK_DESCRIPTION 362
#define NETWORK_NAME 363
#define NICK 364
#define NO_OPER_FLOOD 365
#define NO_TILDE 366
#define NUMBER_PER_CIDR 367
#define NUMBER_PER_IP_GLOBAL 368
#define NUMBER_PER_IP_LOCAL 369
#define OPER_ONLY_UMODES 370
#define OPER_UMODES 371
#define OPERATOR 372
#define OPERS_BYPASS_CALLERID 373
#define PACE_WAIT 374
#define PACE_WAIT_SIMPLE 375
#define PASSWORD 376
#define PATH 377
#define PING_COOKIE 378
#define PING_TIME 379
#define PORT 380
#define RANDOM_IDLE 381
#define REASON 382
#define REDIRPORT 383
#define REDIRSERV 384
#define REHASH 385
#define REMOTE 386
#define REMOTEBAN 387
#define RESV 388
#define RESV_EXEMPT 389
#define RSA_PRIVATE_KEY_FILE 390
#define SECONDS 391
#define MINUTES 392
#define HOURS 393
#define DAYS 394
#define WEEKS 395
#define MONTHS 396
#define YEARS 397
#define SEND_PASSWORD 398
#define SENDQ 399
#define SERVERHIDE 400
#define SERVERINFO 401
#define SHORT_MOTD 402
#define SPOOF 403
#define SQUIT 404
#define STATS_E_DISABLED 405
#define STATS_I_OPER_ONLY 406
#define STATS_K_OPER_ONLY 407
#define STATS_M_OPER_ONLY 408
#define STATS_O_OPER_ONLY 409
#define STATS_P_OPER_ONLY 410
#define STATS_U_OPER_ONLY 411
#define T_ALL 412
#define T_BIND 413
#define T_CALLERID 414
#define T_CCONN 415
#define T_COMMAND 416
#define T_CLUSTER 417
#define T_DEAF 418
#define T_DEBUG 419
#define T_DLINE 420
#define T_EXTERNAL 421
#define T_FARCONNECT 422
#define T_FILE 423
#define T_FLOOD 424
#define T_GLOBOPS 425
#define T_INVISIBLE 426
#define T_IPV4 427
#define T_IPV6 428
#define T_LOCOPS 429
#define T_LOG 430
#define T_NCHANGE 431
#define T_NONONREG 432
#define T_OPME 433
#define T_PREPEND 434
#define T_PSEUDO 435
#define T_RECVQ 436
#define T_REJ 437
#define T_RESTART 438
#define T_SERVER 439
#define T_SERVICE 440
#define T_SERVNOTICE 441
#define T_SET 442
#define T_SHARED 443
#define T_SIZE 444
#define T_SKILL 445
#define T_SOFTCALLERID 446
#define T_SPY 447
#define T_TARGET 448
#define T_TLS 449
#define T_UMODES 450
#define T_UNDLINE 451
#define T_UNLIMITED 452
#define T_UNRESV 453
#define T_UNXLINE 454
#define T_WALLOP 455
#define T_WALLOPS 456
#define T_WEBIRC 457
#define TBOOL 458
#define THROTTLE_COUNT 459
#define THROTTLE_TIME 460
#define TIMEOUT 461
#define TLS_CERTIFICATE_FILE 462
#define TLS_CERTIFICATE_FINGERPRINT 463
#define TLS_CIPHER_LIST 464
#define TLS_CIPHER_SUITES 465
#define TLS_CONNECTION_REQUIRED 466
#define TLS_DH_PARAM_FILE 467
#define TLS_MESSAGE_DIGEST_ALGORITHM 468
#define TLS_SUPPORTED_GROUPS 469
#define TS_MAX_DELTA 470
#define TS_WARN_DELTA 471
#define TWODOTS 472
#define TYPE 473
#define UNKLINE 474
#define USE_LOGGING 475
#define USER 476
#define VHOST 477
#define VHOST6 478
#define WARN_NO_CONNECT_BLOCK 479
#define WHOIS 480
#define WHOWAS_HISTORY_LENGTH 481
#define XLINE 482
#define XLINE_EXEMPT 483
#define QSTRING 484
#define NUMBER 485

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 692 "conf_parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   1318

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  662
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1308

#define YYUNDEFTOK  2
#define YYMAXUTOK   485


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   235,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   236,   231,
       2,   234,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   233,     2,   232,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   365,   365,   366,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   396,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   407,   407,
     408,   409,   410,   411,   418,   420,   420,   421,   421,   421,
     423,   429,   439,   441,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   461,   470,   479,   488,   497,   506,   515,   524,
     539,   554,   564,   578,   587,   610,   633,   656,   666,   668,
     668,   669,   670,   671,   672,   674,   683,   692,   706,   705,
     723,   723,   724,   724,   724,   726,   732,   743,   742,   761,
     761,   762,   762,   762,   762,   762,   764,   770,   776,   782,
     804,   805,   805,   807,   807,   808,   810,   817,   817,   830,
     831,   833,   833,   834,   834,   836,   844,   847,   853,   852,
     858,   858,   859,   863,   867,   871,   875,   879,   883,   887,
     898,   897,   960,   960,   961,   962,   963,   964,   965,   966,
     967,   968,   969,   970,   971,   973,   979,   985,   991,   997,
    1008,  1014,  1025,  1032,  1031,  1037,  1037,  1038,  1042,  1046,
    1050,  1054,  1058,  1062,  1066,  1070,  1074,  1078,  1082,  1086,
    1090,  1094,  1098,  1102,  1106,  1110,  1114,  1118,  1125,  1124,
    1130,  1130,  1131,  1135,  1139,  1143,  1147,  1151,  1155,  1159,
    1163,  1167,  1171,  1175,  1179,  1183,  1187,  1191,  1195,  1199,
    1203,  1207,  1211,  1215,  1219,  1223,  1227,  1231,  1235,  1239,
    1243,  1254,  1253,  1309,  1309,  1310,  1311,  1312,  1313,  1314,
    1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1327,  1333,  1339,  1345,  1351,  1357,  1363,  1369,  1375,
    1382,  1388,  1394,  1400,  1409,  1419,  1418,  1424,  1424,  1425,
    1429,  1440,  1439,  1446,  1445,  1450,  1450,  1451,  1455,  1459,
    1463,  1467,  1473,  1473,  1474,  1474,  1474,  1474,  1474,  1476,
    1476,  1478,  1478,  1480,  1493,  1510,  1516,  1527,  1526,  1573,
    1573,  1574,  1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,
    1584,  1590,  1596,  1602,  1614,  1613,  1619,  1619,  1620,  1624,
    1628,  1632,  1636,  1640,  1644,  1648,  1652,  1658,  1672,  1681,
    1695,  1694,  1709,  1709,  1710,  1710,  1710,  1710,  1712,  1718,
    1724,  1734,  1736,  1736,  1737,  1737,  1739,  1756,  1755,  1778,
    1778,  1779,  1779,  1779,  1779,  1781,  1787,  1807,  1806,  1812,
    1812,  1813,  1817,  1821,  1825,  1829,  1833,  1837,  1841,  1845,
    1849,  1860,  1859,  1878,  1878,  1879,  1879,  1879,  1881,  1888,
    1887,  1893,  1893,  1894,  1898,  1902,  1906,  1910,  1914,  1918,
    1922,  1926,  1930,  1941,  1940,  2018,  2018,  2019,  2020,  2021,
    2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,  2031,
    2032,  2033,  2034,  2036,  2042,  2048,  2054,  2060,  2073,  2086,
    2092,  2098,  2102,  2109,  2108,  2113,  2113,  2114,  2118,  2124,
    2135,  2141,  2147,  2153,  2169,  2168,  2192,  2192,  2193,  2193,
    2193,  2195,  2215,  2226,  2225,  2250,  2250,  2251,  2251,  2251,
    2253,  2259,  2269,  2271,  2271,  2272,  2272,  2274,  2292,  2291,
    2312,  2312,  2313,  2313,  2313,  2315,  2321,  2331,  2333,  2333,
    2334,  2335,  2336,  2337,  2338,  2339,  2340,  2341,  2342,  2343,
    2344,  2345,  2346,  2347,  2348,  2349,  2350,  2351,  2352,  2353,
    2354,  2355,  2356,  2357,  2358,  2359,  2360,  2361,  2362,  2363,
    2364,  2365,  2366,  2367,  2368,  2369,  2370,  2371,  2372,  2373,
    2374,  2375,  2376,  2377,  2378,  2379,  2382,  2387,  2392,  2397,
    2402,  2407,  2412,  2417,  2422,  2427,  2432,  2437,  2442,  2447,
    2452,  2457,  2462,  2467,  2472,  2477,  2482,  2487,  2492,  2497,
    2502,  2507,  2512,  2517,  2522,  2527,  2532,  2537,  2542,  2547,
    2552,  2557,  2562,  2567,  2572,  2578,  2577,  2582,  2582,  2583,
    2586,  2589,  2592,  2595,  2598,  2601,  2604,  2607,  2610,  2613,
    2616,  2619,  2622,  2625,  2628,  2631,  2634,  2637,  2640,  2643,
    2649,  2648,  2653,  2653,  2654,  2657,  2660,  2663,  2666,  2669,
    2672,  2675,  2678,  2681,  2684,  2687,  2690,  2693,  2696,  2699,
    2702,  2705,  2708,  2713,  2718,  2723,  2728,  2737,  2739,  2739,
    2740,  2741,  2742,  2743,  2744,  2745,  2746,  2747,  2748,  2749,
    2750,  2751,  2752,  2753,  2754,  2755,  2757,  2762,  2767,  2772,
    2777,  2782,  2787,  2792,  2797,  2802,  2807,  2812,  2817,  2822,
    2827,  2836,  2838,  2838,  2839,  2840,  2841,  2842,  2843,  2844,
    2845,  2846,  2847,  2848,  2850,  2856,  2872,  2881,  2887,  2893,
    2899,  2908,  2914
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ADMIN", "AFTYPE",
  "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME", "AUTOCONN",
  "AWAY_COUNT", "AWAY_TIME", "BYTES", "KBYTES", "MBYTES", "CALLER_ID_WAIT",
  "CAN_FLOOD", "CHANNEL", "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CLASS",
  "CLIENT", "CLOSE", "CONNECT", "CONNECTFREQ", "CYCLE_ON_HOST_CHANGE",
  "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME", "DEFAULT_JOIN_FLOOD_COUNT",
  "DEFAULT_JOIN_FLOOD_TIME", "DEFAULT_MAX_CLIENTS", "DEFER", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6",
  "DOTS_IN_IDENT", "EMAIL", "ENABLE_EXTBANS", "ENCRYPTED", "EXCEED_LIMIT",
  "EXEMPT", "EXPIRATION", "FAILED_OPER_NOTICE", "FLATTEN_LINKS",
  "FLATTEN_LINKS_DELAY", "FLATTEN_LINKS_FILE", "GECOS", "GENERAL",
  "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
  "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS", "HIDE_SERVERS",
  "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK", "INVISIBLE_ON_CONNECT",
  "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME", "INVITE_DELAY_CHANNEL",
  "INVITE_EXPIRE_TIME", "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID",
  "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6", "KNOCK_CLIENT_COUNT",
  "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LISTEN",
  "MASK", "MAX_ACCEPT", "MAX_BANS", "MAX_BANS_LARGE", "MAX_CHANNELS",
  "MAX_IDLE", "MAX_INVITES", "MAX_MONITOR", "MAX_NICK_CHANGES",
  "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_TOPIC_LENGTH", "MIN_IDLE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD", "NAME",
  "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESCRIPTION", "NETWORK_NAME",
  "NICK", "NO_OPER_FLOOD", "NO_TILDE", "NUMBER_PER_CIDR",
  "NUMBER_PER_IP_GLOBAL", "NUMBER_PER_IP_LOCAL", "OPER_ONLY_UMODES",
  "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID", "PACE_WAIT",
  "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME",
  "PORT", "RANDOM_IDLE", "REASON", "REDIRPORT", "REDIRSERV", "REHASH",
  "REMOTE", "REMOTEBAN", "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS",
  "SEND_PASSWORD", "SENDQ", "SERVERHIDE", "SERVERINFO", "SHORT_MOTD",
  "SPOOF", "SQUIT", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_M_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL", "T_BIND",
  "T_CALLERID", "T_CCONN", "T_COMMAND", "T_CLUSTER", "T_DEAF", "T_DEBUG",
  "T_DLINE", "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FLOOD",
  "T_GLOBOPS", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG",
  "T_NCHANGE", "T_NONONREG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ",
  "T_REJ", "T_RESTART", "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET",
  "T_SHARED", "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_TARGET",
  "T_TLS", "T_UMODES", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE",
  "T_WALLOP", "T_WALLOPS", "T_WEBIRC", "TBOOL", "THROTTLE_COUNT",
  "THROTTLE_TIME", "TIMEOUT", "TLS_CERTIFICATE_FILE",
  "TLS_CERTIFICATE_FINGERPRINT", "TLS_CIPHER_LIST", "TLS_CIPHER_SUITES",
  "TLS_CONNECTION_REQUIRED", "TLS_DH_PARAM_FILE",
  "TLS_MESSAGE_DIGEST_ALGORITHM", "TLS_SUPPORTED_GROUPS", "TS_MAX_DELTA",
  "TS_WARN_DELTA", "TWODOTS", "TYPE", "UNKLINE", "USE_LOGGING", "USER",
  "VHOST", "VHOST6", "WARN_NO_CONNECT_BLOCK", "WHOIS",
  "WHOWAS_HISTORY_LENGTH", "XLINE", "XLINE_EXEMPT", "QSTRING", "NUMBER",
  "';'", "'}'", "'{'", "'='", "','", "':'", "$accept", "conf", "conf_item",
  "timespec_", "timespec", "sizespec_", "sizespec", "modules_entry",
  "modules_items", "modules_item", "modules_module", "modules_path",
  "serverinfo_entry", "serverinfo_items", "serverinfo_item",
  "serverinfo_tls_certificate_file", "serverinfo_rsa_private_key_file",
  "serverinfo_tls_dh_param_file", "serverinfo_tls_cipher_list",
  "serverinfo_tls_cipher_suites",
  "serverinfo_tls_message_digest_algorithm",
  "serverinfo_tls_supported_groups", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_description", "serverinfo_default_max_clients",
  "serverinfo_max_nick_length", "serverinfo_max_topic_length",
  "serverinfo_hub", "admin_entry", "admin_items", "admin_item",
  "admin_name", "admin_email", "admin_description", "motd_entry", "$@1",
  "motd_items", "motd_item", "motd_mask", "motd_file", "pseudo_entry",
  "$@2", "pseudo_items", "pseudo_item", "pseudo_command", "pseudo_name",
  "pseudo_prepend", "pseudo_target", "logging_entry", "logging_items",
  "logging_item", "logging_use_logging", "logging_file_entry", "$@3",
  "logging_file_items", "logging_file_item", "logging_file_name",
  "logging_file_size", "logging_file_type", "$@4",
  "logging_file_type_items", "logging_file_type_item", "oper_entry", "$@5",
  "oper_items", "oper_item", "oper_name", "oper_user", "oper_password",
  "oper_whois", "oper_encrypted", "oper_tls_certificate_fingerprint",
  "oper_tls_connection_required", "oper_class", "oper_umodes", "$@6",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@7",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@8",
  "class_items", "class_item", "class_name", "class_ping_time",
  "class_number_per_ip_local", "class_number_per_ip_global",
  "class_connectfreq", "class_max_channels", "class_max_number",
  "class_sendq", "class_recvq", "class_cidr_bitlen_ipv4",
  "class_cidr_bitlen_ipv6", "class_number_per_cidr", "class_min_idle",
  "class_max_idle", "class_flags", "$@9", "class_flags_items",
  "class_flags_item", "listen_entry", "$@10", "listen_flags", "$@11",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "$@12", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "$@13", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_class", "auth_encrypted", "auth_flags",
  "$@14", "auth_flags_items", "auth_flags_item", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "resv_entry", "$@15", "resv_items",
  "resv_item", "resv_mask", "resv_reason", "resv_exempt", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@16",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@17", "shared_types", "shared_type_item",
  "cluster_entry", "$@18", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@19", "cluster_types", "cluster_type_item",
  "connect_entry", "$@20", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_timeout", "connect_bind",
  "connect_send_password", "connect_accept_password",
  "connect_tls_certificate_fingerprint", "connect_port", "connect_aftype",
  "connect_flags", "$@21", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_tls_cipher_list", "kill_entry", "$@22",
  "kill_items", "kill_item", "kill_user", "kill_reason", "deny_entry",
  "$@23", "deny_items", "deny_item", "deny_ip", "deny_reason",
  "exempt_entry", "exempt_items", "exempt_item", "exempt_ip",
  "gecos_entry", "$@24", "gecos_items", "gecos_item", "gecos_name",
  "gecos_reason", "general_entry", "general_items", "general_item",
  "general_away_count", "general_away_time", "general_max_monitor",
  "general_whowas_history_length", "general_cycle_on_host_change",
  "general_dline_min_cidr", "general_dline_min_cidr6",
  "general_kline_min_cidr", "general_kline_min_cidr6",
  "general_kill_chase_time_limit", "general_failed_oper_notice",
  "general_anti_nick_flood", "general_max_nick_time",
  "general_max_nick_changes", "general_max_accept",
  "general_anti_spam_exit_message_time", "general_ts_warn_delta",
  "general_ts_max_delta", "general_invisible_on_connect",
  "general_warn_no_connect_block", "general_stats_e_disabled",
  "general_stats_m_oper_only", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_u_oper_only",
  "general_stats_k_oper_only", "general_stats_i_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_opers_bypass_callerid", "general_pace_wait_simple",
  "general_short_motd", "general_no_oper_flood", "general_dots_in_ident",
  "general_max_targets", "general_ping_cookie", "general_disable_auth",
  "general_throttle_count", "general_throttle_time", "general_oper_umodes",
  "$@25", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@26", "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_default_floodtime", "channel_entry", "channel_items",
  "channel_item", "channel_enable_extbans",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_invite_delay_channel",
  "channel_invite_expire_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_channels", "channel_max_invites", "channel_max_bans",
  "channel_max_bans_large", "channel_default_join_flood_count",
  "channel_default_join_flood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_flatten_links_delay", "serverhide_flatten_links_file",
  "serverhide_disable_remote_commands", "serverhide_hide_servers",
  "serverhide_hide_services", "serverhide_hidden_name",
  "serverhide_hidden", "serverhide_hide_server_ips", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF (-725)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -725,   680,  -725,  -212,  -205,  -203,  -725,  -725,  -725,  -200,
    -725,  -194,  -725,  -725,  -725,  -178,  -725,  -725,  -725,  -176,
    -171,  -725,  -166,  -725,  -163,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,   301,   627,  -148,  -142,  -136,    13,  -105,   418,  -100,
     -87,   -81,    52,   -72,   -63,   -58,   330,   528,   -53,     8,
     -45,    15,   -28,   -21,   -10,    -7,    31,     3,  -725,  -725,
    -725,  -725,  -725,    46,    62,    69,    76,    86,    88,   102,
     106,   109,   111,   116,   117,   124,   126,   128,   172,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,   686,   542,    21,  -725,   129,
      55,  -725,  -725,    20,  -725,   130,   131,   133,   137,   138,
     139,   140,   141,   156,   157,   160,   161,   162,   168,   179,
     181,   184,   187,   195,   196,   197,   200,   203,   204,   206,
    -725,  -725,   211,   212,   213,   214,   217,   220,   224,   227,
     229,   231,   234,   235,   236,   237,   238,   240,   241,   242,
      40,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,   338,    11,   316,
      43,   243,   244,    44,  -725,  -725,  -725,    51,   380,   308,
    -725,   246,   249,   251,   253,   254,   255,   256,   257,   263,
      35,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,    70,   264,   268,   271,   273,   274,   279,   281,   282,
     285,   296,   297,   298,   305,   306,   310,   312,     2,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,    23,    82,   314,    57,
    -725,  -725,  -725,    78,   177,  -725,   315,    58,  -725,  -725,
      12,  -725,   105,   182,   185,   275,  -725,   176,   232,    39,
     332,   322,   232,   232,   232,   324,   232,   232,   325,   326,
     328,   333,   311,  -725,   331,   342,   343,   344,  -725,   346,
     347,   348,   349,   351,   356,   366,   369,   372,   373,   375,
     180,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,   335,   379,   382,
     383,   384,   386,   392,  -725,   395,   396,   397,   403,   404,
     405,   406,   407,   201,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,   411,   413,    22,  -725,  -725,  -725,   390,   336,  -725,
    -725,   415,   416,    50,  -725,  -725,  -725,   361,   232,   421,
     232,   232,   450,   427,   232,   455,   429,   430,   434,   463,
     466,   232,   440,   441,   442,   443,   445,   232,   448,   452,
     453,   483,   456,   461,   486,   232,   232,   495,   498,   507,
     509,   513,   515,   516,   517,   518,   492,   232,   232,   232,
     520,   496,   494,  -725,   497,   493,   499,  -725,   500,   502,
     505,   510,   511,   272,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,   523,   524,    74,  -725,  -725,  -725,
     501,   526,   527,  -725,   532,  -725,    97,  -725,  -725,  -725,
    -725,  -725,   514,   525,   521,  -725,   536,   534,   535,    16,
    -725,  -725,  -725,   540,   538,   539,  -725,   543,   545,  -725,
     546,   551,   552,   554,   228,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,   558,   557,   559,   561,
      17,  -725,  -725,  -725,  -725,   544,   573,   232,   563,   593,
     576,   599,   603,   604,   577,  -725,  -725,   584,   586,   615,
     587,   589,   590,   592,   594,   595,   598,   602,   605,   606,
     608,   609,   610,   591,  -725,   597,   611,  -725,    79,  -725,
    -725,  -725,  -725,   630,   612,  -725,   381,   616,   614,   617,
     618,   619,    47,  -725,  -725,  -725,  -725,  -725,   621,   623,
    -725,   625,   628,  -725,   629,    67,  -725,  -725,  -725,  -725,
     626,   633,   635,  -725,   640,   385,   641,   644,   647,   654,
     657,   658,   659,   660,   662,   663,   664,   666,   667,   668,
    -725,  -725,   631,   674,   232,   671,   676,   232,   677,   232,
     685,   687,   689,   691,   232,   692,   692,   693,  -725,  -725,
     698,   175,   699,   643,   700,   701,   702,   703,   704,   707,
     705,   709,   232,   713,   716,   715,  -725,   723,   725,   726,
    -725,   728,  -725,   727,   733,   732,  -725,   734,   736,   737,
     738,   740,   741,   742,   746,   747,   748,   750,   751,   752,
     754,   755,   756,   757,   758,   759,   760,   761,   762,   763,
     764,   765,   784,   710,   766,   767,   768,   769,   770,   771,
     772,   773,   774,   775,   776,   777,   778,   779,   780,   781,
     782,   783,  -725,  -725,   735,   656,   785,   786,   787,   789,
     791,   792,   793,  -725,   794,   796,   795,  -725,  -725,   798,
     799,   788,   800,   801,  -725,   802,   803,  -725,  -725,   806,
     807,   808,  -725,  -725,   809,   813,   797,   811,   812,   810,
     814,   826,   816,   817,   818,  -725,  -725,   819,   821,   822,
     823,  -725,   824,   825,   827,   828,   829,   830,   831,   832,
     833,  -725,   834,   835,   836,   837,   838,   839,   840,   841,
     842,   843,   844,   845,   846,   847,   848,   849,  -725,  -725,
     852,   850,   851,  -725,   854,  -725,   119,  -725,   857,   858,
     859,   860,   861,  -725,   862,  -725,  -725,   865,   856,   866,
     867,  -725,  -725,  -725,  -725,  -725,   232,   232,   232,   232,
     232,   232,   232,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,   868,
     869,   870,   -30,   871,   872,   873,   874,   875,   876,   877,
     878,   879,   100,   880,   881,  -725,   882,   883,   884,   885,
     886,   887,   888,    24,   889,   890,   891,   892,   893,   894,
     895,   896,  -725,   897,   898,  -725,  -725,   899,   900,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -206,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -193,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,   901,   902,   292,
     903,   904,   905,   906,   907,  -725,   908,   909,  -725,   910,
     911,   -15,   512,   745,  -725,  -725,  -725,  -725,   912,   913,
    -725,   914,   915,   478,   916,   917,   749,   918,   919,   920,
     921,  -725,   922,   923,   924,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,   925,   613,  -725,  -725,   926,   863,   927,  -725,    68,
    -725,  -725,  -725,  -725,   928,   929,   931,   932,  -725,  -725,
     933,   684,   934,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -191,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,   692,   692,   692,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -159,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,   784,  -725,
     710,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -109,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,   -67,  -725,
     853,   800,   935,  -725,  -725,  -725,  -725,  -725,  -725,   855,
    -725,   936,   937,  -725,  -725,   938,   939,  -725,  -725,   940,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,   -49,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,   -46,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,   -14,  -725,  -725,
     941,  -170,   943,   947,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
      81,  -725,  -725,  -725,   -30,  -725,  -725,  -725,  -725,    24,
    -725,  -725,  -725,   292,  -725,   -15,  -725,  -725,  -725,   965,
     711,  1027,  1034,  1037,  1038,  -725,   478,  -725,   749,  -725,
     613,   948,   949,   950,   252,  -725,  -725,   684,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,    84,  -725,  -725,  -725,   252,  -725
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   231,   393,   443,     0,
     458,     0,   297,   434,   271,     0,    98,   150,   330,     0,
       0,   371,     0,   107,     0,   347,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      93,    92,   625,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   609,
     624,   623,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   610,   611,   621,   622,     0,     0,     0,   456,     0,
       0,   454,   455,     0,   515,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     580,   555,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   469,   470,   471,   513,   477,   514,   508,   509,   510,
     511,   481,   472,   473,   474,   475,   476,   478,   479,   480,
     482,   483,   512,   487,   488,   489,   490,   486,   485,   491,
     498,   499,   492,   493,   494,   484,   496,   506,   507,   504,
     505,   497,   495,   502,   503,   500,   501,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     653,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   643,   644,   645,   646,   647,   648,   649,   651,   650,
     652,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      67,    65,    63,    68,    69,    70,    64,    55,    66,    57,
      58,    59,    60,    61,    62,    56,     0,     0,     0,     0,
     122,   123,   124,     0,     0,   345,     0,     0,   343,   344,
       0,    94,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   608,     0,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,   235,   238,   240,   241,   242,   243,   244,   245,
     246,   236,   237,   239,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,   423,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,   405,   404,   407,   411,   408,   409,   410,   406,
     449,     0,     0,     0,   446,   447,   448,     0,     0,   453,
     464,     0,     0,     0,   461,   462,   463,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   468,     0,     0,     0,   314,     0,     0,
       0,     0,     0,     0,   300,   301,   302,   303,   308,   304,
     305,   306,   307,   440,     0,     0,     0,   437,   438,   439,
       0,     0,     0,   273,     0,   285,     0,   283,   284,   286,
     287,    49,     0,     0,     0,    45,     0,     0,     0,     0,
     101,   102,   103,     0,     0,     0,   198,     0,     0,   173,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     160,   161,   162,   159,   158,   163,     0,     0,     0,     0,
       0,   333,   334,   335,   336,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   642,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,   379,     0,   374,
     375,   376,   125,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   113,   112,   114,     0,     0,
     342,     0,     0,   357,     0,     0,   350,   351,   352,   353,
       0,     0,     0,    88,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     607,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   412,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   395,     0,     0,     0,
     445,     0,   452,     0,     0,     0,   460,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   467,   309,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   299,     0,     0,     0,   436,   288,     0,
       0,     0,     0,     0,   282,     0,     0,    44,   104,     0,
       0,     0,   100,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,   337,     0,     0,     0,
       0,   332,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   641,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,   377,
       0,     0,     0,   373,     0,   120,     0,   115,     0,     0,
       0,     0,     0,   109,     0,   341,   354,     0,     0,     0,
       0,   349,    97,    96,    95,   639,    28,    28,    28,    28,
      28,    28,    28,    30,    29,   640,   627,   626,   628,   629,
     630,   631,   632,   633,   634,   637,   638,   635,   636,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   394,     0,     0,   444,   457,     0,     0,   459,
     527,   531,   516,   517,   544,   520,   605,   606,   552,   521,
     522,   549,   526,   534,   525,   523,   524,   530,   518,   529,
     528,   550,   603,   604,   548,   602,   589,   598,   584,   585,
     586,   593,   601,   587,   595,   599,   590,   600,   591,   594,
     588,   597,   592,   596,     0,   583,   579,   563,   564,   565,
     575,   559,   560,   561,   570,   578,   562,   572,   576,   567,
     577,   568,   571,   566,   574,   569,   573,     0,   558,   545,
     543,   546,   551,   547,   536,   542,   541,   537,   538,   539,
     540,   553,   554,   533,   532,   535,   519,     0,     0,     0,
       0,     0,     0,     0,     0,   298,     0,     0,   435,     0,
       0,     0,   293,   289,   292,   272,    50,    51,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,     0,     0,     0,   331,   657,   654,   655,   656,
     661,   660,   662,   658,   659,    84,    81,    87,    80,    85,
      86,    79,    83,    82,    73,    72,    75,    76,    74,    77,
      78,     0,     0,   372,   126,     0,     0,     0,   138,     0,
     130,   131,   133,   132,     0,     0,     0,     0,   108,   346,
       0,     0,     0,   348,    31,    32,    33,    34,    35,    36,
      37,   260,   261,   255,   270,   269,     0,   268,   256,   264,
     257,   263,   251,   262,   254,   253,   252,    38,    38,    38,
      40,    39,   258,   259,   418,   421,   422,   432,   429,   414,
     430,   427,   428,     0,   426,   431,   413,   420,   417,   416,
     415,   419,   433,   450,   451,   465,   466,   581,     0,   556,
       0,   312,   313,   322,   318,   319,   321,   326,   323,   324,
     325,   320,     0,   317,   311,   329,   328,   327,   310,   442,
     441,   296,   295,   280,   281,   278,   279,   277,     0,   276,
       0,     0,     0,   105,   106,   172,   169,   218,   230,   205,
     214,     0,   203,   208,   224,     0,   217,   222,   228,   207,
     210,   219,   221,   225,   215,   223,   211,   229,   213,   220,
     209,   212,     0,   201,   165,   167,   197,   181,   182,   183,
     193,   177,   178,   179,   188,   196,   180,   190,   194,   185,
     195,   186,   189,   184,   192,   187,   191,     0,   176,   170,
     171,   166,   168,   340,   338,   339,   378,   383,   389,   392,
     385,   391,   386,   390,   388,   384,   387,     0,   382,   134,
       0,     0,     0,     0,   129,   117,   116,   118,   119,   355,
     361,   367,   370,   363,   369,   364,   368,   366,   362,   365,
       0,   360,   356,   266,     0,    41,    42,    43,   424,     0,
     582,   557,   315,     0,   274,     0,   294,   291,   290,     0,
       0,     0,     0,     0,     0,   199,     0,   174,     0,   380,
       0,     0,     0,     0,     0,   128,   358,     0,   267,   425,
     316,   275,   204,   227,   202,   226,   216,   206,   200,   175,
     381,   135,   137,   136,   148,   147,   143,   145,   149,   146,
     142,   144,     0,   141,   359,   139,     0,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -725,  -725,  -725,  -224,  -306,  -724,  -635,  -725,  -725,   959,
    -725,  -725,  -725,  -725,   930,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,   960,  -725,  -725,  -725,  -725,  -725,  -725,
     548,  -725,  -725,  -725,  -725,  -725,   460,  -725,  -725,  -725,
    -725,  -725,  -725,   942,  -725,  -725,  -725,  -725,    14,  -725,
    -725,  -725,  -725,  -725,  -254,  -725,  -725,  -725,   669,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -211,  -725,  -725,  -725,   -95,  -725,  -725,  -725,   864,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,   -60,  -725,  -725,  -725,
    -725,  -725,   -70,  -725,   706,  -725,  -725,  -725,    45,  -725,
    -725,  -725,  -725,  -725,   724,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,   -65,  -725,  -725,  -725,  -725,  -725,  -725,   661,
    -725,  -725,  -725,  -725,  -725,   944,  -725,  -725,  -725,  -725,
     600,  -725,  -725,  -725,  -725,  -725,   -88,  -725,  -725,  -725,
     622,  -725,  -725,  -725,  -725,   -77,  -725,  -725,  -725,   945,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,   -55,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,   720,  -725,  -725,  -725,  -725,  -725,   804,  -725,  -725,
    -725,  -725,  1079,  -725,  -725,  -725,  -725,   805,  -725,  -725,
    -725,  -725,  1030,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,    91,  -725,  -725,  -725,    94,
    -725,  -725,  -725,  -725,  -725,  -725,  1105,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725,   966,  -725,  -725,  -725,  -725,  -725,
    -725,  -725,  -725,  -725
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   823,   824,  1080,  1081,    27,   223,   224,
     225,   226,    28,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    29,    77,    78,    79,    80,    81,    30,    63,   499,
     500,   501,   502,    31,    70,   582,   583,   584,   585,   586,
     587,    32,   289,   290,   291,   292,   293,  1039,  1040,  1041,
    1042,  1043,  1222,  1302,  1303,    33,    64,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   749,  1197,
    1198,   525,   746,  1172,  1173,    34,    53,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   625,  1066,  1067,    35,    61,   485,
     731,  1138,  1139,   486,   487,   488,  1142,   983,   984,   489,
     490,    36,    59,   463,   464,   465,   466,   467,   468,   469,
     716,  1122,  1123,   470,   471,   472,    37,    65,   530,   531,
     532,   533,   534,    38,   297,   298,   299,    39,    72,   595,
     596,   597,   598,   599,   808,  1240,  1241,    40,    68,   568,
     569,   570,   571,   791,  1217,  1218,    41,    54,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     646,  1093,  1094,   385,   386,   387,   388,   389,    42,    60,
     476,   477,   478,   479,    43,    55,   393,   394,   395,   396,
      44,   120,   121,   122,    45,    57,   403,   404,   405,   406,
      46,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   433,   947,   948,   212,   432,   924,   925,
     213,   214,   215,   216,    47,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    48,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     853,   854,   606,   251,    73,  1133,   610,   611,   612,   287,
     614,   615,   473,   591,   118,  1134,   295,   496,   526,    49,
      50,   400,   390,   390,   565,  1107,  1064,  1272,    51,  1108,
      52,   252,  1091,    56,   253,    74,   230,  1135,  1109,    58,
    1243,   124,  1110,    75,  1244,   220,   125,   126,   577,   127,
     128,   400,   496,   220,   129,    62,   118,    66,   287,   295,
     852,   527,    67,   254,   130,   131,   132,    69,   591,  1035,
      71,   231,  1248,   255,   133,   473,  1249,   134,   135,   136,
     565,   119,   232,   233,   234,   115,   137,   235,   236,   391,
     391,   116,   237,   238,   239,   256,  1065,   117,   480,   257,
     497,   528,   668,   138,   670,   671,   258,    76,   674,   259,
     260,  1077,  1078,  1079,   139,   681,   592,   140,   141,   296,
    1035,   687,  1252,   119,   401,   142,  1253,   566,   123,   695,
     696,   143,   144,   217,   145,   497,   146,   261,   474,   147,
     148,   707,   708,   709,   529,   221,   218,   402,   392,   392,
     149,   578,   219,   221,   401,   150,   151,   481,   152,   153,
     154,   227,   296,   155,  1254,   482,   222,   483,  1255,  1136,
     228,   592,  1036,    82,   222,   229,  -127,   402,   577,  1137,
     286,   324,  1265,   566,   498,  1267,  1266,   156,   294,  1268,
     157,   158,   159,   160,   161,   162,   163,   325,   326,    83,
      84,   474,   357,   327,   358,   300,   359,    85,   579,   262,
     301,   263,   264,    86,   265,   266,   267,  1269,  1092,   498,
     360,  1270,   484,  1036,   302,  -127,   580,   303,   288,   503,
     593,   764,   475,   594,   563,   305,    87,    88,    89,    90,
     581,   567,   607,   361,   164,   165,   576,   504,   741,   760,
     328,    91,    92,    93,   659,   166,   167,  1037,    94,    95,
      96,   362,    97,   363,   168,   304,   169,   544,   329,   330,
     505,   364,   452,   454,   491,   331,   494,   288,   332,   802,
     307,   578,   665,   365,   333,   593,  1038,   398,   594,   574,
     589,   455,   334,   335,   336,   475,   308,   567,   506,   810,
    1223,   546,    73,   309,   337,   366,   726,  1113,  1037,   526,
     310,   792,  1276,   572,   456,  1305,  1277,   480,   841,  1306,
     311,   844,   312,   846,   338,  1294,   367,  1295,   851,   733,
     852,   230,   507,    74,   600,  1114,   313,  1038,   579,   454,
     314,    75,   457,   315,   368,   316,   869,   857,   858,   508,
     317,   318,   527,  1245,  1246,  1247,   580,   455,   319,   369,
     320,   339,   321,   397,   407,   408,   231,   409,  1115,  1296,
     581,   410,   411,   412,   413,   414,   481,   232,   233,   234,
     456,   503,   235,   236,   482,  1297,   483,   237,   238,   239,
     415,   416,   528,   458,   417,   418,   419,  1116,  1117,   504,
     459,   460,   420,  1118,   322,    76,   604,   370,   457,   371,
     372,   601,   637,   421,   602,   422,  1298,  1299,   423,   124,
     461,   424,   505,   509,   125,   126,  1119,   127,   128,   425,
     426,   427,   129,   655,   428,   529,   510,   429,   430,   511,
     431,   484,   130,   131,   132,   434,   435,   436,   437,   512,
     506,   438,   133,   513,   439,   134,   135,   136,   440,   458,
     754,   441,   605,   442,   137,   443,   459,   460,   444,   445,
     446,   447,   448,  1300,   449,   450,   451,   492,   493,  1301,
     535,   138,  1147,   536,   507,   537,   461,   538,   539,   540,
     541,   542,   139,   462,  1120,   140,   141,   543,   547,  1148,
    1149,   508,   548,   142,   722,   549,   603,   550,   551,   143,
     144,  1150,   145,   552,   146,   553,   554,   147,   148,   555,
    1121,   816,   817,   818,   819,   820,   821,   822,   149,   251,
     556,   557,   558,   150,   151,   608,   152,   153,   154,   559,
     560,   155,   620,   357,   561,   358,   562,   359,   573,   588,
    1151,  1152,   609,  1153,   613,   616,   617,   252,   618,   462,
     253,   360,   621,   619,   667,   156,   639,   662,   157,   158,
     159,   160,   161,   162,   163,   509,   622,   623,   624,  1154,
     626,   627,   628,   629,   361,   630,  1273,  1155,   510,   254,
     631,   511,  1054,  1055,  1056,  1057,  1058,  1059,  1060,   255,
     632,   512,   362,   633,   363,   513,   634,   635,  1156,   636,
    1157,  1158,   364,   640,   796,   605,   641,   642,   643,   661,
     644,   256,   164,   165,   365,   257,   645,  1159,    82,   647,
     648,   649,   258,   166,   167,   259,   260,   650,   651,   652,
     653,   654,   168,  1160,   169,   657,   366,   658,  1161,   663,
     664,   669,  1162,   672,    83,    84,  1163,   673,   675,   676,
     677,  1164,    85,   261,   678,  1165,   679,   367,    86,   680,
     682,   683,   684,   685,  1166,   686,  1167,  1168,   688,  1169,
       2,     3,   689,   690,     4,   368,   691,   324,  1207,   694,
     692,    87,    88,    89,    90,   693,     5,  1170,   697,     6,
     369,   698,     7,   325,   326,  1171,    91,    92,    93,   327,
     699,     8,   700,    94,    95,    96,   701,    97,   702,   703,
     704,   705,   706,   710,     9,   712,   711,   714,   713,  1140,
      10,    11,   728,   715,   717,   262,   718,   263,   264,   719,
     265,   266,   267,   735,   720,   721,  1208,   762,   370,    12,
     371,   372,   737,    13,   736,   926,   328,   724,   725,  1230,
     729,   730,   927,    14,   928,   929,   732,   738,   739,   740,
    1209,   743,   744,   745,   329,   330,   763,   747,  1210,   748,
     750,   331,    15,    16,   332,   751,   752,  1211,   753,   756,
     333,   757,   765,   758,  1176,   759,   766,    17,   334,   335,
     336,  1177,   768,  1178,  1179,   767,   769,   770,   771,  1212,
     337,  1213,  1214,    18,   772,   773,   775,  1231,   774,   776,
     777,   778,   788,   779,   780,    19,    20,   781,   789,   905,
     338,   782,  1215,   794,   783,   784,   906,   785,   786,   787,
    1216,  1232,    21,   795,  1283,   790,   860,   797,   798,  1233,
     804,   799,   800,   801,   805,    22,   806,   812,  1234,   968,
      23,   839,   807,   809,   813,    24,   814,   339,    25,   930,
     931,   815,   825,   932,   933,   826,   934,   935,   827,   936,
    1235,   937,  1236,  1237,   938,   828,   939,   940,   829,   830,
     831,   832,   941,   833,   834,   835,   942,   836,   837,   838,
     943,   944,   945,  1238,   840,   842,   843,   845,  1180,  1181,
     946,  1239,  1182,  1183,   847,  1184,  1185,   848,  1186,   849,
    1187,   850,   852,  1188,   855,  1189,  1190,   856,   859,   861,
     862,  1191,   864,   865,   867,  1192,   863,   866,   868,  1193,
    1194,  1195,   870,   907,   908,   871,   872,   909,   910,  1196,
     911,   912,   873,   913,   874,   914,   877,   875,   915,   876,
     916,   917,   878,   879,   967,   880,   918,   881,   882,   883,
     919,   884,   885,   886,   920,   921,   922,   887,   888,   889,
    1141,   890,   891,   892,   923,   893,   894,   895,   896,   897,
     898,   899,   900,   901,   902,   903,   904,   949,   950,   951,
     952,   953,   954,   955,   956,   957,   958,   959,   960,   961,
     962,   963,   964,   965,   966,   970,   992,   971,   972,   969,
     973,   974,   981,   976,   975,   977,   978,   979,   980,   998,
     982,   993,   985,   986,   987,   988,   989,   306,   991,   990,
     994,   995,   803,   997,   996,   999,  1000,   742,  1002,  1001,
    1003,  1004,  1307,  1224,  1005,  1006,  1007,  1289,  1008,  1009,
    1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,
    1030,  1031,  1033,  1256,  1032,  1034,  1044,  1045,  1046,  1047,
    1051,  1259,  1048,  1049,  1050,  1052,  1282,  1220,  1053,  1061,
    1062,  1063,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1111,  1112,  1124,  1125,  1126,  1127,  1128,  1129,
    1130,  1131,  1132,  1143,  1144,  1145,  1146,  1174,  1175,  1199,
    1200,  1201,  1202,  1203,  1204,  1205,  1206,  1219,  1284,  1225,
    1226,  1221,  1227,  1228,  1229,  1242,  1258,  1285,  1286,  1287,
    1271,  1288,  1260,  1261,  1262,  1263,  1264,  1274,  1275,  1291,
    1292,  1293,   495,   755,  1278,  1281,  1257,   723,  1280,  1304,
     793,   761,   734,  1290,  1279,   811,   727,   660,   564,   399,
     453,  1251,  1250,   323,   638,     0,   545,     0,   666,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   575,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   656
};

static const yytype_int16 yycheck[] =
{
     635,   636,   308,     1,     1,    20,   312,   313,   314,     1,
     316,   317,     1,     1,     1,    30,     1,     1,     1,   231,
     232,     1,     1,     1,     1,   231,    56,   197,   233,   235,
     233,    29,     8,   233,    32,    32,     1,    52,   231,   233,
     231,     1,   235,    40,   235,     1,     6,     7,     1,     9,
      10,     1,     1,     1,    14,   233,     1,   233,     1,     1,
     230,    44,   233,    61,    24,    25,    26,   233,     1,     1,
     233,    36,   231,    71,    34,     1,   235,    37,    38,    39,
       1,    68,    47,    48,    49,   233,    46,    52,    53,    68,
      68,   233,    57,    58,    59,    93,   126,   233,     1,    97,
      84,    84,   408,    63,   410,   411,   104,   104,   414,   107,
     108,    11,    12,    13,    74,   421,   104,    77,    78,   104,
       1,   427,   231,    68,   104,    85,   235,   104,   233,   435,
     436,    91,    92,   233,    94,    84,    96,   135,   127,    99,
     100,   447,   448,   449,   127,   101,   233,   127,   127,   127,
     110,   104,   233,   101,   104,   115,   116,    60,   118,   119,
     120,   233,   104,   123,   231,    68,   122,    70,   235,   184,
     233,   104,   104,     1,   122,   233,   168,   127,     1,   194,
     233,     1,   231,   104,   168,   231,   235,   147,   233,   235,
     150,   151,   152,   153,   154,   155,   156,    17,    18,    27,
      28,   127,     1,    23,     3,   233,     5,    35,   161,   207,
     231,   209,   210,    41,   212,   213,   214,   231,   194,   168,
      19,   235,   125,   104,   234,   168,   179,   234,   220,     1,
     218,   537,   221,   221,   232,   232,    64,    65,    66,    67,
     193,   218,   203,    42,   204,   205,   168,    19,   232,   232,
      70,    79,    80,    81,   232,   215,   216,   189,    86,    87,
      88,    60,    90,    62,   224,   234,   226,   232,    88,    89,
      42,    70,   232,     1,   231,    95,   232,   220,    98,   232,
     234,   104,   232,    82,   104,   218,   218,   232,   221,   232,
     232,    19,   112,   113,   114,   221,   234,   218,    70,   232,
     232,   231,     1,   234,   124,   104,   232,    15,   189,     1,
     234,   232,   231,   231,    42,   231,   235,     1,   624,   235,
     234,   627,   234,   629,   144,    73,   125,    75,   634,   232,
     230,     1,   104,    32,   229,    43,   234,   218,   161,     1,
     234,    40,    70,   234,   143,   234,   652,   172,   173,   121,
     234,   234,    44,  1077,  1078,  1079,   179,    19,   234,   158,
     234,   181,   234,   234,   234,   234,    36,   234,    76,   117,
     193,   234,   234,   234,   234,   234,    60,    47,    48,    49,
      42,     1,    52,    53,    68,   133,    70,    57,    58,    59,
     234,   234,    84,   121,   234,   234,   234,   105,   106,    19,
     128,   129,   234,   111,   232,   104,   230,   206,    70,   208,
     209,   229,   232,   234,   229,   234,   164,   165,   234,     1,
     148,   234,    42,   195,     6,     7,   134,     9,    10,   234,
     234,   234,    14,   232,   234,   127,   208,   234,   234,   211,
     234,   125,    24,    25,    26,   234,   234,   234,   234,   221,
      70,   234,    34,   225,   234,    37,    38,    39,   234,   121,
     232,   234,   230,   234,    46,   234,   128,   129,   234,   234,
     234,   234,   234,   221,   234,   234,   234,   234,   234,   227,
     234,    63,     4,   234,   104,   234,   148,   234,   234,   234,
     234,   234,    74,   221,   202,    77,    78,   234,   234,    21,
      22,   121,   234,    85,   232,   234,   231,   234,   234,    91,
      92,    33,    94,   234,    96,   234,   234,    99,   100,   234,
     228,   136,   137,   138,   139,   140,   141,   142,   110,     1,
     234,   234,   234,   115,   116,   203,   118,   119,   120,   234,
     234,   123,   231,     1,   234,     3,   234,     5,   234,   234,
      72,    73,   230,    75,   230,   230,   230,    29,   230,   221,
      32,    19,   231,   230,   203,   147,   231,   231,   150,   151,
     152,   153,   154,   155,   156,   195,   234,   234,   234,   101,
     234,   234,   234,   234,    42,   234,  1221,   109,   208,    61,
     234,   211,   816,   817,   818,   819,   820,   821,   822,    71,
     234,   221,    60,   234,    62,   225,   234,   234,   130,   234,
     132,   133,    70,   234,   233,   230,   234,   234,   234,   229,
     234,    93,   204,   205,    82,    97,   234,   149,     1,   234,
     234,   234,   104,   215,   216,   107,   108,   234,   234,   234,
     234,   234,   224,   165,   226,   234,   104,   234,   170,   234,
     234,   230,   174,   203,    27,    28,   178,   230,   203,   230,
     230,   183,    35,   135,   230,   187,   203,   125,    41,   203,
     230,   230,   230,   230,   196,   230,   198,   199,   230,   201,
       0,     1,   230,   230,     4,   143,   203,     1,    75,   203,
     234,    64,    65,    66,    67,   234,    16,   219,   203,    19,
     158,   203,    22,    17,    18,   227,    79,    80,    81,    23,
     203,    31,   203,    86,    87,    88,   203,    90,   203,   203,
     203,   203,   230,   203,    44,   231,   230,   234,   231,   217,
      50,    51,   231,   234,   234,   207,   234,   209,   210,   234,
     212,   213,   214,   229,   234,   234,   133,   203,   206,    69,
     208,   209,   231,    73,   229,    45,    70,   234,   234,    75,
     234,   234,    52,    83,    54,    55,   234,   231,   234,   234,
     157,   231,   234,   234,    88,    89,   203,   234,   165,   234,
     234,    95,   102,   103,    98,   234,   234,   174,   234,   231,
     104,   234,   229,   234,    45,   234,   203,   117,   112,   113,
     114,    52,   203,    54,    55,   229,   203,   203,   231,   196,
     124,   198,   199,   133,   230,   229,   229,   133,   203,   230,
     230,   229,   231,   229,   229,   145,   146,   229,   231,    45,
     144,   229,   219,   203,   229,   229,    52,   229,   229,   229,
     227,   157,   162,   231,   133,   234,   203,   231,   234,   165,
     229,   234,   234,   234,   231,   175,   231,   231,   174,   203,
     180,   230,   234,   234,   231,   185,   231,   181,   188,   159,
     160,   231,   231,   163,   164,   231,   166,   167,   231,   169,
     196,   171,   198,   199,   174,   231,   176,   177,   231,   231,
     231,   231,   182,   231,   231,   231,   186,   231,   231,   231,
     190,   191,   192,   219,   230,   234,   230,   230,   159,   160,
     200,   227,   163,   164,   229,   166,   167,   230,   169,   230,
     171,   230,   230,   174,   231,   176,   177,   229,   229,   229,
     229,   182,   229,   229,   229,   186,   234,   230,   229,   190,
     191,   192,   229,   159,   160,   229,   231,   163,   164,   200,
     166,   167,   229,   169,   229,   171,   229,   231,   174,   231,
     176,   177,   229,   231,   229,   231,   182,   231,   231,   231,
     186,   231,   231,   231,   190,   191,   192,   231,   231,   231,
     235,   231,   231,   231,   200,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   229,   203,   230,   229,   234,
     229,   229,   234,   229,   231,   229,   231,   229,   229,   203,
     230,   234,   231,   231,   231,   229,   229,    77,   229,   231,
     229,   229,   582,   229,   234,   229,   229,   499,   229,   231,
     229,   229,  1306,  1039,   231,   231,   231,  1268,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   229,   231,   230,   234,   231,   229,   229,   229,   229,
     234,   236,   231,   231,   229,   229,   131,   234,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   131,   231,
     231,   234,   231,   231,   231,   231,   231,   133,   131,   131,
     229,  1266,   236,   236,   236,   236,   236,   234,   231,   231,
     231,   231,   223,   514,  1244,  1255,  1141,   463,  1253,  1277,
     568,   530,   486,  1270,  1249,   595,   476,   393,   268,   120,
     170,  1110,  1108,    98,   340,    -1,   240,    -1,   403,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   373
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   238,     0,     1,     4,    16,    19,    22,    31,    44,
      50,    51,    69,    73,    83,   102,   103,   117,   133,   145,
     146,   162,   175,   180,   185,   188,   239,   244,   249,   268,
     274,   280,   288,   302,   322,   344,   358,   373,   380,   384,
     394,   403,   425,   431,   437,   441,   447,   501,   519,   231,
     232,   233,   233,   323,   404,   432,   233,   442,   233,   359,
     426,   345,   233,   275,   303,   374,   233,   233,   395,   233,
     281,   233,   385,     1,    32,    40,   104,   269,   270,   271,
     272,   273,     1,    27,    28,    35,    41,    64,    65,    66,
      67,    79,    80,    81,    86,    87,    88,    90,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   233,   233,   233,     1,    68,
     438,   439,   440,   233,     1,     6,     7,     9,    10,    14,
      24,    25,    26,    34,    37,    38,    39,    46,    63,    74,
      77,    78,    85,    91,    92,    94,    96,    99,   100,   110,
     115,   116,   118,   119,   120,   123,   147,   150,   151,   152,
     153,   154,   155,   156,   204,   205,   215,   216,   224,   226,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   493,   497,   498,   499,   500,   233,   233,   233,
       1,   101,   122,   245,   246,   247,   248,   233,   233,   233,
       1,    36,    47,    48,    49,    52,    53,    57,    58,    59,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,     1,    29,    32,    61,    71,    93,    97,   104,   107,
     108,   135,   207,   209,   210,   212,   213,   214,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   233,     1,   220,   289,
     290,   291,   292,   293,   233,     1,   104,   381,   382,   383,
     233,   231,   234,   234,   234,   232,   270,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   232,   503,     1,    17,    18,    23,    70,    88,
      89,    95,    98,   104,   112,   113,   114,   124,   144,   181,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,     1,     3,     5,
      19,    42,    60,    62,    70,    82,   104,   125,   143,   158,
     206,   208,   209,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   420,   421,   422,   423,   424,
       1,    68,   127,   433,   434,   435,   436,   234,   232,   439,
       1,   104,   127,   443,   444,   445,   446,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   494,   490,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   232,   449,     1,    19,    42,    70,   121,   128,
     129,   148,   221,   360,   361,   362,   363,   364,   365,   366,
     370,   371,   372,     1,   127,   221,   427,   428,   429,   430,
       1,    60,    68,    70,   125,   346,   350,   351,   352,   356,
     357,   231,   234,   234,   232,   246,     1,    84,   168,   276,
     277,   278,   279,     1,    19,    42,    70,   104,   121,   195,
     208,   211,   221,   225,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   318,     1,    44,    84,   127,
     375,   376,   377,   378,   379,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   232,   521,   231,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   232,   251,     1,   104,   218,   396,   397,
     398,   399,   231,   234,   232,   290,   168,     1,   104,   161,
     179,   193,   282,   283,   284,   285,   286,   287,   234,   232,
     382,     1,   104,   218,   221,   386,   387,   388,   389,   390,
     229,   229,   229,   231,   230,   230,   241,   203,   203,   230,
     241,   241,   241,   230,   241,   241,   230,   230,   230,   230,
     231,   231,   234,   234,   234,   341,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   232,   325,   231,
     234,   234,   234,   234,   234,   234,   417,   234,   234,   234,
     234,   234,   234,   234,   234,   232,   406,   234,   234,   232,
     434,   229,   231,   234,   234,   232,   444,   203,   241,   230,
     241,   241,   203,   230,   241,   203,   230,   230,   230,   203,
     203,   241,   230,   230,   230,   230,   230,   241,   230,   230,
     230,   203,   234,   234,   203,   241,   241,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   230,   241,   241,   241,
     203,   230,   231,   231,   234,   234,   367,   234,   234,   234,
     234,   234,   232,   361,   234,   234,   232,   428,   231,   234,
     234,   347,   234,   232,   351,   229,   229,   231,   231,   234,
     234,   232,   277,   231,   234,   234,   319,   234,   234,   315,
     234,   234,   234,   234,   232,   305,   231,   234,   234,   234,
     232,   376,   203,   203,   241,   229,   203,   229,   203,   203,
     203,   231,   230,   229,   203,   229,   230,   230,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   231,   231,
     234,   400,   232,   397,   203,   231,   233,   231,   234,   234,
     234,   234,   232,   283,   229,   231,   231,   234,   391,   234,
     232,   387,   231,   231,   231,   231,   136,   137,   138,   139,
     140,   141,   142,   240,   241,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   230,
     230,   241,   234,   230,   241,   230,   241,   229,   230,   230,
     230,   241,   230,   243,   243,   231,   229,   172,   173,   229,
     203,   229,   229,   234,   229,   229,   230,   229,   229,   241,
     229,   229,   231,   229,   229,   231,   231,   229,   229,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,    45,    52,   159,   160,   163,
     164,   166,   167,   169,   171,   174,   176,   177,   182,   186,
     190,   191,   192,   200,   495,   496,    45,    52,    54,    55,
     159,   160,   163,   164,   166,   167,   169,   171,   174,   176,
     177,   182,   186,   190,   191,   192,   200,   491,   492,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   229,   203,   234,
     229,   230,   229,   229,   229,   231,   229,   229,   231,   229,
     229,   234,   230,   354,   355,   231,   231,   231,   229,   229,
     231,   229,   203,   234,   229,   229,   234,   229,   203,   229,
     229,   231,   229,   229,   229,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   229,   234,   231,   231,     1,   104,   189,   218,   294,
     295,   296,   297,   298,   229,   229,   229,   229,   231,   231,
     229,   234,   229,   231,   240,   240,   240,   240,   240,   240,
     240,   231,   231,   231,    56,   126,   342,   343,   231,   231,
     231,   231,   231,   231,   231,   231,   231,    11,    12,    13,
     242,   243,   231,   231,   231,   231,   231,   231,   231,   231,
     231,     8,   194,   418,   419,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   235,   231,
     235,   231,   231,    15,    43,    76,   105,   106,   111,   134,
     202,   228,   368,   369,   231,   231,   231,   231,   231,   231,
     231,   231,   231,    20,    30,    52,   184,   194,   348,   349,
     217,   235,   353,   231,   231,   231,   231,     4,    21,    22,
      33,    72,    73,    75,   101,   109,   130,   132,   133,   149,
     165,   170,   174,   178,   183,   187,   196,   198,   199,   201,
     219,   227,   320,   321,   231,   231,    45,    52,    54,    55,
     159,   160,   163,   164,   166,   167,   169,   171,   174,   176,
     177,   182,   186,   190,   191,   192,   200,   316,   317,   231,
     231,   231,   231,   231,   231,   231,   231,    75,   133,   157,
     165,   174,   196,   198,   199,   219,   227,   401,   402,   231,
     234,   234,   299,   232,   295,   231,   231,   231,   231,   231,
      75,   133,   157,   165,   174,   196,   198,   199,   219,   227,
     392,   393,   231,   231,   235,   242,   242,   242,   231,   235,
     496,   492,   231,   235,   231,   235,   230,   355,   231,   236,
     236,   236,   236,   236,   236,   231,   235,   231,   235,   231,
     235,   229,   197,   243,   234,   231,   231,   235,   343,   419,
     369,   349,   131,   133,   131,   133,   131,   131,   321,   317,
     402,   231,   231,   231,    73,    75,   117,   133,   164,   165,
     221,   227,   300,   301,   393,   231,   235,   301
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   237,   238,   238,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   240,   240,
     241,   241,   241,   241,   241,   241,   241,   241,   242,   242,
     243,   243,   243,   243,   244,   245,   245,   246,   246,   246,
     247,   248,   249,   250,   250,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     269,   270,   270,   270,   270,   271,   272,   273,   275,   274,
     276,   276,   277,   277,   277,   278,   279,   281,   280,   282,
     282,   283,   283,   283,   283,   283,   284,   285,   286,   287,
     288,   289,   289,   290,   290,   290,   291,   293,   292,   294,
     294,   295,   295,   295,   295,   296,   297,   297,   299,   298,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   301,
     303,   302,   304,   304,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   315,   314,   316,   316,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   319,   318,
     320,   320,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   323,   322,   324,   324,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   341,   340,   342,   342,   343,
     343,   345,   344,   347,   346,   348,   348,   349,   349,   349,
     349,   349,   350,   350,   351,   351,   351,   351,   351,   353,
     352,   354,   354,   355,   355,   356,   357,   359,   358,   360,
     360,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     362,   363,   364,   365,   367,   366,   368,   368,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   370,   371,   372,
     374,   373,   375,   375,   376,   376,   376,   376,   377,   378,
     379,   380,   381,   381,   382,   382,   383,   385,   384,   386,
     386,   387,   387,   387,   387,   388,   389,   391,   390,   392,
     392,   393,   393,   393,   393,   393,   393,   393,   393,   393,
     393,   395,   394,   396,   396,   397,   397,   397,   398,   400,
     399,   401,   401,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   404,   403,   405,   405,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   415,   417,   416,   418,   418,   419,   419,   420,
     421,   422,   423,   424,   426,   425,   427,   427,   428,   428,
     428,   429,   430,   432,   431,   433,   433,   434,   434,   434,
     435,   436,   437,   438,   438,   439,   439,   440,   442,   441,
     443,   443,   444,   444,   444,   445,   446,   447,   448,   448,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   490,   489,   491,   491,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     494,   493,   495,   495,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   497,   498,   499,   500,   501,   502,   502,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   520,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     0,     1,
       2,     3,     3,     3,     5,     2,     1,     1,     1,     2,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     0,     6,
       2,     1,     1,     1,     2,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     2,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     0,     6,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     0,
       5,     3,     1,     1,     3,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     2,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     4,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 28:
#line 396 "conf_parser.y"
           { (yyval.number) = 0; }
#line 2950 "conf_parser.c"
    break;

  case 30:
#line 397 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2956 "conf_parser.c"
    break;

  case 31:
#line 398 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2962 "conf_parser.c"
    break;

  case 32:
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2968 "conf_parser.c"
    break;

  case 33:
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2974 "conf_parser.c"
    break;

  case 34:
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2980 "conf_parser.c"
    break;

  case 35:
#line 402 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2986 "conf_parser.c"
    break;

  case 36:
#line 403 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2992 "conf_parser.c"
    break;

  case 37:
#line 404 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2998 "conf_parser.c"
    break;

  case 38:
#line 407 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3004 "conf_parser.c"
    break;

  case 40:
#line 408 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3010 "conf_parser.c"
    break;

  case 41:
#line 409 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3016 "conf_parser.c"
    break;

  case 42:
#line 410 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3022 "conf_parser.c"
    break;

  case 43:
#line 411 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3028 "conf_parser.c"
    break;

  case 50:
#line 424 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 3037 "conf_parser.c"
    break;

  case 51:
#line 430 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 3046 "conf_parser.c"
    break;

  case 72:
#line 462 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = xstrdup(yylval.string);
  }
}
#line 3058 "conf_parser.c"
    break;

  case 73:
#line 471 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 3070 "conf_parser.c"
    break;

  case 74:
#line 480 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3082 "conf_parser.c"
    break;

  case 75:
#line 489 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = xstrdup(yylval.string);
  }
}
#line 3094 "conf_parser.c"
    break;

  case 76:
#line 498 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = xstrdup(yylval.string);
  }
}
#line 3106 "conf_parser.c"
    break;

  case 77:
#line 507 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3118 "conf_parser.c"
    break;

  case 78:
#line 516 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = xstrdup(yylval.string);
  }
}
#line 3130 "conf_parser.c"
    break;

  case 79:
#line 525 "conf_parser.y"
{
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && ConfigServerInfo.name == NULL)
  {
    if (server_valid_name(yylval.string) == true)
      ConfigServerInfo.name = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3148 "conf_parser.c"
    break;

  case 80:
#line 540 "conf_parser.y"
{
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && ConfigServerInfo.sid == NULL)
  {
    if (valid_sid(yylval.string))
      ConfigServerInfo.sid = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3166 "conf_parser.c"
    break;

  case 81:
#line 555 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3179 "conf_parser.c"
    break;

  case 82:
#line 565 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    char *p = strchr(yylval.string, ' ');

    if (p)
      *p = '\0';

    xfree(ConfigServerInfo.network_name);
    ConfigServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3196 "conf_parser.c"
    break;

  case 83:
#line 579 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = xstrdup(yylval.string);
}
#line 3208 "conf_parser.c"
    break;

  case 84:
#line 588 "conf_parser.y"
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
#line 3234 "conf_parser.c"
    break;

  case 85:
#line 611 "conf_parser.y"
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
#line 3260 "conf_parser.c"
    break;

  case 86:
#line 634 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 80)
  {
    conf_error_report("max_topic_length too low, setting to 80");
    ConfigServerInfo.max_topic_length = 80;
  }
  else if ((yyvsp[-1].number) > TOPICLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
    conf_error_report(buf);

    ConfigServerInfo.max_topic_length = TOPICLEN;
  }
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3286 "conf_parser.c"
    break;

  case 87:
#line 657 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3295 "conf_parser.c"
    break;

  case 95:
#line 675 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3307 "conf_parser.c"
    break;

  case 96:
#line 684 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3319 "conf_parser.c"
    break;

  case 97:
#line 693 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3331 "conf_parser.c"
    break;

  case 98:
#line 706 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3340 "conf_parser.c"
    break;

  case 99:
#line 710 "conf_parser.y"
{
  dlink_node *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3357 "conf_parser.c"
    break;

  case 105:
#line 727 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3366 "conf_parser.c"
    break;

  case 106:
#line 733 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3375 "conf_parser.c"
    break;

  case 107:
#line 743 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3384 "conf_parser.c"
    break;

  case 108:
#line 747 "conf_parser.y"
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
#line 3402 "conf_parser.c"
    break;

  case 116:
#line 765 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3411 "conf_parser.c"
    break;

  case 117:
#line 771 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3420 "conf_parser.c"
    break;

  case 118:
#line 777 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3429 "conf_parser.c"
    break;

  case 119:
#line 783 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.nick.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.nick.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
#line 3450 "conf_parser.c"
    break;

  case 126:
#line 811 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3459 "conf_parser.c"
    break;

  case 127:
#line 817 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3468 "conf_parser.c"
    break;

  case 128:
#line 821 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3481 "conf_parser.c"
    break;

  case 135:
#line 837 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3492 "conf_parser.c"
    break;

  case 136:
#line 845 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3500 "conf_parser.c"
    break;

  case 137:
#line 848 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3508 "conf_parser.c"
    break;

  case 138:
#line 853 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3517 "conf_parser.c"
    break;

  case 142:
#line 860 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3526 "conf_parser.c"
    break;

  case 143:
#line 864 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3535 "conf_parser.c"
    break;

  case 144:
#line 868 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3544 "conf_parser.c"
    break;

  case 145:
#line 872 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3553 "conf_parser.c"
    break;

  case 146:
#line 876 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3562 "conf_parser.c"
    break;

  case 147:
#line 880 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3571 "conf_parser.c"
    break;

  case 148:
#line 884 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3580 "conf_parser.c"
    break;

  case 149:
#line 888 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3589 "conf_parser.c"
    break;

  case 150:
#line 898 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3601 "conf_parser.c"
    break;

  case 151:
#line 905 "conf_parser.y"
{
  dlink_node *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  if (!block_state.rpass.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct split_nuh_item nuh;
    char *s = node->data;

    if (EmptyString(s))
      continue;

    nuh.nuhmask  = s;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);

    struct MaskItem *conf = conf_make(CONF_OPER);
    conf->addr = xcalloc(sizeof(*conf->addr));
    conf->name = xstrdup(block_state.name.buf);
    conf->user = xstrdup(block_state.user.buf);
    conf->host = xstrdup(block_state.host.buf);

    if (block_state.cert.buf[0])
      conf->certfp = xstrdup(block_state.cert.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);

    if (block_state.whois.buf[0])
      conf->whois = xstrdup(block_state.whois.buf);

    conf->flags = block_state.flags.value;
    conf->modes = block_state.modes.value;
    conf->port  = block_state.port.value;
    conf->htype = parse_netmask(conf->host, conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);
  }
}
#line 3660 "conf_parser.c"
    break;

  case 165:
#line 974 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3669 "conf_parser.c"
    break;

  case 166:
#line 980 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3678 "conf_parser.c"
    break;

  case 167:
#line 986 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3687 "conf_parser.c"
    break;

  case 168:
#line 992 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3696 "conf_parser.c"
    break;

  case 169:
#line 998 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3710 "conf_parser.c"
    break;

  case 170:
#line 1009 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3719 "conf_parser.c"
    break;

  case 171:
#line 1015 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 3733 "conf_parser.c"
    break;

  case 172:
#line 1026 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3742 "conf_parser.c"
    break;

  case 173:
#line 1032 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3751 "conf_parser.c"
    break;

  case 177:
#line 1039 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3760 "conf_parser.c"
    break;

  case 178:
#line 1043 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3769 "conf_parser.c"
    break;

  case 179:
#line 1047 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3778 "conf_parser.c"
    break;

  case 180:
#line 1051 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FLOOD;
}
#line 3787 "conf_parser.c"
    break;

  case 181:
#line 1055 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3796 "conf_parser.c"
    break;

  case 182:
#line 1059 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3805 "conf_parser.c"
    break;

  case 183:
#line 1063 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3814 "conf_parser.c"
    break;

  case 184:
#line 1067 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3823 "conf_parser.c"
    break;

  case 185:
#line 1071 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3832 "conf_parser.c"
    break;

  case 186:
#line 1075 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3841 "conf_parser.c"
    break;

  case 187:
#line 1079 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3850 "conf_parser.c"
    break;

  case 188:
#line 1083 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3859 "conf_parser.c"
    break;

  case 189:
#line 1087 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3868 "conf_parser.c"
    break;

  case 190:
#line 1091 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3877 "conf_parser.c"
    break;

  case 191:
#line 1095 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3886 "conf_parser.c"
    break;

  case 192:
#line 1099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3895 "conf_parser.c"
    break;

  case 193:
#line 1103 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3904 "conf_parser.c"
    break;

  case 194:
#line 1107 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3913 "conf_parser.c"
    break;

  case 195:
#line 1111 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3922 "conf_parser.c"
    break;

  case 196:
#line 1115 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3931 "conf_parser.c"
    break;

  case 197:
#line 1119 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3940 "conf_parser.c"
    break;

  case 198:
#line 1125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3949 "conf_parser.c"
    break;

  case 202:
#line 1132 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3958 "conf_parser.c"
    break;

  case 203:
#line 1136 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3967 "conf_parser.c"
    break;

  case 204:
#line 1140 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3976 "conf_parser.c"
    break;

  case 205:
#line 1144 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3985 "conf_parser.c"
    break;

  case 206:
#line 1148 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3994 "conf_parser.c"
    break;

  case 207:
#line 1152 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4003 "conf_parser.c"
    break;

  case 208:
#line 1156 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4012 "conf_parser.c"
    break;

  case 209:
#line 1160 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4021 "conf_parser.c"
    break;

  case 210:
#line 1164 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4030 "conf_parser.c"
    break;

  case 211:
#line 1168 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4039 "conf_parser.c"
    break;

  case 212:
#line 1172 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4048 "conf_parser.c"
    break;

  case 213:
#line 1176 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4057 "conf_parser.c"
    break;

  case 214:
#line 1180 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4066 "conf_parser.c"
    break;

  case 215:
#line 1184 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4075 "conf_parser.c"
    break;

  case 216:
#line 1188 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4084 "conf_parser.c"
    break;

  case 217:
#line 1192 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4093 "conf_parser.c"
    break;

  case 218:
#line 1196 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4102 "conf_parser.c"
    break;

  case 219:
#line 1200 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4111 "conf_parser.c"
    break;

  case 220:
#line 1204 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4120 "conf_parser.c"
    break;

  case 221:
#line 1208 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4129 "conf_parser.c"
    break;

  case 222:
#line 1212 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4138 "conf_parser.c"
    break;

  case 223:
#line 1216 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4147 "conf_parser.c"
    break;

  case 224:
#line 1220 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4156 "conf_parser.c"
    break;

  case 225:
#line 1224 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4165 "conf_parser.c"
    break;

  case 226:
#line 1228 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4174 "conf_parser.c"
    break;

  case 227:
#line 1232 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4183 "conf_parser.c"
    break;

  case 228:
#line 1236 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4192 "conf_parser.c"
    break;

  case 229:
#line 1240 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4201 "conf_parser.c"
    break;

  case 230:
#line 1244 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4210 "conf_parser.c"
    break;

  case 231:
#line 1254 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4226 "conf_parser.c"
    break;

  case 232:
#line 1265 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.class.buf[0])
    break;

  struct ClassItem *class = class_find(block_state.class.buf, false);
  if (class == NULL)
    class = class_make();

  class->active = true;
  xfree(class->name);
  class->name = xstrdup(block_state.class.buf);
  class->ping_freq = block_state.ping_freq.value;
  class->max_perip_local = block_state.max_perip_local.value;
  class->max_perip_global = block_state.max_perip_global.value;
  class->con_freq = block_state.con_freq.value;
  class->max_total = block_state.max_total.value;
  class->max_sendq = block_state.max_sendq.value;
  class->max_recvq = block_state.max_recvq.value;
  class->max_channels = block_state.max_channels.value;

  if (block_state.min_idle.value > block_state.max_idle.value)
  {
    block_state.min_idle.value = 0;
    block_state.max_idle.value = 0;
    block_state.flags.value &= ~CLASS_FLAGS_FAKE_IDLE;
  }

  class->flags = block_state.flags.value;
  class->min_idle = block_state.min_idle.value;
  class->max_idle = block_state.max_idle.value;

  bool diff = (class->cidr_bitlen_ipv4 != block_state.cidr_bitlen_ipv4.value ||
               class->cidr_bitlen_ipv6 != block_state.cidr_bitlen_ipv6.value);
  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;

  if (diff)
    class_ip_limit_rebuild(class);
}
#line 4274 "conf_parser.c"
    break;

  case 251:
#line 1328 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4283 "conf_parser.c"
    break;

  case 252:
#line 1334 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4292 "conf_parser.c"
    break;

  case 253:
#line 1340 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4301 "conf_parser.c"
    break;

  case 254:
#line 1346 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4310 "conf_parser.c"
    break;

  case 255:
#line 1352 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4319 "conf_parser.c"
    break;

  case 256:
#line 1358 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4328 "conf_parser.c"
    break;

  case 257:
#line 1364 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4337 "conf_parser.c"
    break;

  case 258:
#line 1370 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4346 "conf_parser.c"
    break;

  case 259:
#line 1376 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4356 "conf_parser.c"
    break;

  case 260:
#line 1383 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4365 "conf_parser.c"
    break;

  case 261:
#line 1389 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4374 "conf_parser.c"
    break;

  case 262:
#line 1395 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4383 "conf_parser.c"
    break;

  case 263:
#line 1401 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4395 "conf_parser.c"
    break;

  case 264:
#line 1410 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4407 "conf_parser.c"
    break;

  case 265:
#line 1419 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4416 "conf_parser.c"
    break;

  case 269:
#line 1426 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4425 "conf_parser.c"
    break;

  case 270:
#line 1430 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4434 "conf_parser.c"
    break;

  case 271:
#line 1440 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4443 "conf_parser.c"
    break;

  case 273:
#line 1446 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4451 "conf_parser.c"
    break;

  case 277:
#line 1452 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4460 "conf_parser.c"
    break;

  case 278:
#line 1456 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4469 "conf_parser.c"
    break;

  case 279:
#line 1460 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4478 "conf_parser.c"
    break;

  case 280:
#line 1464 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4487 "conf_parser.c"
    break;

  case 281:
#line 1468 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4496 "conf_parser.c"
    break;

  case 289:
#line 1476 "conf_parser.y"
                                 { block_state.flags.value = 0; }
#line 4502 "conf_parser.c"
    break;

  case 293:
#line 1481 "conf_parser.y"
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
#line 4520 "conf_parser.c"
    break;

  case 294:
#line 1494 "conf_parser.y"
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
#line 4540 "conf_parser.c"
    break;

  case 295:
#line 1511 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4549 "conf_parser.c"
    break;

  case 296:
#line 1517 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4558 "conf_parser.c"
    break;

  case 297:
#line 1527 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4567 "conf_parser.c"
    break;

  case 298:
#line 1531 "conf_parser.y"
{
  dlink_node *node;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct split_nuh_item nuh;
    char *s = node->data;

    if (EmptyString(s))
      continue;

    nuh.nuhmask  = s;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);

    struct MaskItem *conf = conf_make(CONF_CLIENT);
    conf->user = xstrdup(block_state.user.buf);
    conf->host = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);
    if (block_state.name.buf[0])
      conf->name = xstrdup(block_state.name.buf);

    conf->flags = block_state.flags.value;
    conf->port = block_state.port.value;

    conf_add_class_to_conf(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
#line 4613 "conf_parser.c"
    break;

  case 310:
#line 1585 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4622 "conf_parser.c"
    break;

  case 311:
#line 1591 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4631 "conf_parser.c"
    break;

  case 312:
#line 1597 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4640 "conf_parser.c"
    break;

  case 313:
#line 1603 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4654 "conf_parser.c"
    break;

  case 314:
#line 1614 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4663 "conf_parser.c"
    break;

  case 318:
#line 1621 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4672 "conf_parser.c"
    break;

  case 319:
#line 1625 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4681 "conf_parser.c"
    break;

  case 320:
#line 1629 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4690 "conf_parser.c"
    break;

  case 321:
#line 1633 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4699 "conf_parser.c"
    break;

  case 322:
#line 1637 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4708 "conf_parser.c"
    break;

  case 323:
#line 1641 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4717 "conf_parser.c"
    break;

  case 324:
#line 1645 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4726 "conf_parser.c"
    break;

  case 325:
#line 1649 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4735 "conf_parser.c"
    break;

  case 326:
#line 1653 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4744 "conf_parser.c"
    break;

  case 327:
#line 1659 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_hostname(yylval.string))
  {
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
    block_state.flags.value |= CONF_FLAGS_SPOOF_IP;
  }
  else
    ilog(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 4761 "conf_parser.c"
    break;

  case 328:
#line 1673 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4773 "conf_parser.c"
    break;

  case 329:
#line 1682 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4785 "conf_parser.c"
    break;

  case 330:
#line 1695 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4797 "conf_parser.c"
    break;

  case 331:
#line 1702 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4808 "conf_parser.c"
    break;

  case 338:
#line 1713 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4817 "conf_parser.c"
    break;

  case 339:
#line 1719 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4826 "conf_parser.c"
    break;

  case 340:
#line 1725 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4835 "conf_parser.c"
    break;

  case 346:
#line 1740 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4850 "conf_parser.c"
    break;

  case 347:
#line 1756 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4866 "conf_parser.c"
    break;

  case 348:
#line 1767 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4881 "conf_parser.c"
    break;

  case 355:
#line 1782 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4890 "conf_parser.c"
    break;

  case 356:
#line 1788 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
#line 4912 "conf_parser.c"
    break;

  case 357:
#line 1807 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4921 "conf_parser.c"
    break;

  case 361:
#line 1814 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4930 "conf_parser.c"
    break;

  case 362:
#line 1818 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4939 "conf_parser.c"
    break;

  case 363:
#line 1822 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4948 "conf_parser.c"
    break;

  case 364:
#line 1826 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4957 "conf_parser.c"
    break;

  case 365:
#line 1830 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4966 "conf_parser.c"
    break;

  case 366:
#line 1834 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4975 "conf_parser.c"
    break;

  case 367:
#line 1838 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4984 "conf_parser.c"
    break;

  case 368:
#line 1842 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4993 "conf_parser.c"
    break;

  case 369:
#line 1846 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5002 "conf_parser.c"
    break;

  case 370:
#line 1850 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5011 "conf_parser.c"
    break;

  case 371:
#line 1860 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5025 "conf_parser.c"
    break;

  case 372:
#line 1869 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5038 "conf_parser.c"
    break;

  case 378:
#line 1882 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5047 "conf_parser.c"
    break;

  case 379:
#line 1888 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5056 "conf_parser.c"
    break;

  case 383:
#line 1895 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5065 "conf_parser.c"
    break;

  case 384:
#line 1899 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5074 "conf_parser.c"
    break;

  case 385:
#line 1903 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5083 "conf_parser.c"
    break;

  case 386:
#line 1907 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5092 "conf_parser.c"
    break;

  case 387:
#line 1911 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5101 "conf_parser.c"
    break;

  case 388:
#line 1915 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5110 "conf_parser.c"
    break;

  case 389:
#line 1919 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5119 "conf_parser.c"
    break;

  case 390:
#line 1923 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5128 "conf_parser.c"
    break;

  case 391:
#line 1927 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5137 "conf_parser.c"
    break;

  case 392:
#line 1931 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5146 "conf_parser.c"
    break;

  case 393:
#line 1941 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5161 "conf_parser.c"
    break;

  case 394:
#line 1951 "conf_parser.y"
{
  struct addrinfo hints, *res;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0] ||
      !block_state.host.buf[0])
    break;

  if (!block_state.rpass.buf[0] ||
      !block_state.spass.buf[0])
    break;

  if (server_valid_name(block_state.name.buf) == false)
    break;

  if (has_wildcards(block_state.name.buf) ||
      has_wildcards(block_state.host.buf))
    break;

  struct MaskItem *conf = conf_make(CONF_SERVER);
  conf->addr = xcalloc(sizeof(*conf->addr));
  conf->port = block_state.port.value;
  conf->timeout = block_state.timeout.value;
  conf->flags = block_state.flags.value;
  conf->aftype = block_state.aftype.value;
  conf->host = xstrdup(block_state.host.buf);
  conf->name = xstrdup(block_state.name.buf);
  conf->passwd = xstrdup(block_state.rpass.buf);
  conf->spasswd = xstrdup(block_state.spass.buf);

  if (block_state.cert.buf[0])
    conf->certfp = xstrdup(block_state.cert.buf);

  if (block_state.ciph.buf[0])
    conf->cipher_list = xstrdup(block_state.ciph.buf);

  dlinkMoveList(&block_state.leaf.list, &conf->leaf_list);
  dlinkMoveList(&block_state.hub.list, &conf->hub_list);

  if (block_state.bind.buf[0])
  {
    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(block_state.bind.buf, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server bind(%s)", block_state.bind.buf);
    else
    {
      assert(res);

      conf->bind = xcalloc(sizeof(*conf->bind));

      memcpy(conf->bind, res->ai_addr, res->ai_addrlen);
      conf->bind->ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  conf_dns_lookup(conf);
}
#line 5232 "conf_parser.c"
    break;

  case 413:
#line 2037 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5241 "conf_parser.c"
    break;

  case 414:
#line 2043 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5250 "conf_parser.c"
    break;

  case 415:
#line 2049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5259 "conf_parser.c"
    break;

  case 416:
#line 2055 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5268 "conf_parser.c"
    break;

  case 417:
#line 2061 "conf_parser.y"
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
#line 5284 "conf_parser.c"
    break;

  case 418:
#line 2074 "conf_parser.y"
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
#line 5300 "conf_parser.c"
    break;

  case 419:
#line 2087 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5309 "conf_parser.c"
    break;

  case 420:
#line 2093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5318 "conf_parser.c"
    break;

  case 421:
#line 2099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5327 "conf_parser.c"
    break;

  case 422:
#line 2103 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5336 "conf_parser.c"
    break;

  case 423:
#line 2109 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5344 "conf_parser.c"
    break;

  case 427:
#line 2115 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5353 "conf_parser.c"
    break;

  case 428:
#line 2119 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5362 "conf_parser.c"
    break;

  case 429:
#line 2125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5376 "conf_parser.c"
    break;

  case 430:
#line 2136 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5385 "conf_parser.c"
    break;

  case 431:
#line 2142 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5394 "conf_parser.c"
    break;

  case 432:
#line 2148 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5403 "conf_parser.c"
    break;

  case 433:
#line 2154 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5417 "conf_parser.c"
    break;

  case 434:
#line 2169 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5426 "conf_parser.c"
    break;

  case 435:
#line 2173 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.user.buf[0] ||
      !block_state.host.buf[0])
    break;

  struct MaskItem *conf = conf_make(CONF_KLINE);
  conf->user = xstrdup(block_state.user.buf);
  conf->host = xstrdup(block_state.host.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
  add_conf_by_address(CONF_KLINE, conf);
}
#line 5449 "conf_parser.c"
    break;

  case 441:
#line 2196 "conf_parser.y"
{

  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
#line 5472 "conf_parser.c"
    break;

  case 442:
#line 2216 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5481 "conf_parser.c"
    break;

  case 443:
#line 2226 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5490 "conf_parser.c"
    break;

  case 444:
#line 2230 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  if (parse_netmask(block_state.addr.buf, NULL, NULL) != HM_HOST)
  {
    struct MaskItem *conf = conf_make(CONF_DLINE);
    conf->host = xstrdup(block_state.addr.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
    add_conf_by_address(CONF_DLINE, conf);
  }
}
#line 5514 "conf_parser.c"
    break;

  case 450:
#line 2254 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5523 "conf_parser.c"
    break;

  case 451:
#line 2260 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5532 "conf_parser.c"
    break;

  case 457:
#line 2275 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (*yylval.string && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      struct MaskItem *conf = conf_make(CONF_EXEMPT);
      conf->host = xstrdup(yylval.string);

      add_conf_by_address(CONF_EXEMPT, conf);
    }
  }
}
#line 5549 "conf_parser.c"
    break;

  case 458:
#line 2292 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5558 "conf_parser.c"
    break;

  case 459:
#line 2296 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  struct GecosItem *gecos = gecos_make();
  gecos->mask = xstrdup(block_state.name.buf);

  if (block_state.rpass.buf[0])
    gecos->reason = xstrdup(block_state.rpass.buf);
  else
    gecos->reason = xstrdup(CONF_NOREASON);
}
#line 5578 "conf_parser.c"
    break;

  case 465:
#line 2316 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5587 "conf_parser.c"
    break;

  case 466:
#line 2322 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5596 "conf_parser.c"
    break;

  case 516:
#line 2383 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5604 "conf_parser.c"
    break;

  case 517:
#line 2388 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5612 "conf_parser.c"
    break;

  case 518:
#line 2393 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5620 "conf_parser.c"
    break;

  case 519:
#line 2398 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5628 "conf_parser.c"
    break;

  case 520:
#line 2403 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5636 "conf_parser.c"
    break;

  case 521:
#line 2408 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5644 "conf_parser.c"
    break;

  case 522:
#line 2413 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5652 "conf_parser.c"
    break;

  case 523:
#line 2418 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5660 "conf_parser.c"
    break;

  case 524:
#line 2423 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5668 "conf_parser.c"
    break;

  case 525:
#line 2428 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5676 "conf_parser.c"
    break;

  case 526:
#line 2433 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5684 "conf_parser.c"
    break;

  case 527:
#line 2438 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5692 "conf_parser.c"
    break;

  case 528:
#line 2443 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5700 "conf_parser.c"
    break;

  case 529:
#line 2448 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5708 "conf_parser.c"
    break;

  case 530:
#line 2453 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5716 "conf_parser.c"
    break;

  case 531:
#line 2458 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5724 "conf_parser.c"
    break;

  case 532:
#line 2463 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5732 "conf_parser.c"
    break;

  case 533:
#line 2468 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5740 "conf_parser.c"
    break;

  case 534:
#line 2473 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5748 "conf_parser.c"
    break;

  case 535:
#line 2478 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5756 "conf_parser.c"
    break;

  case 536:
#line 2483 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5764 "conf_parser.c"
    break;

  case 537:
#line 2488 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5772 "conf_parser.c"
    break;

  case 538:
#line 2493 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5780 "conf_parser.c"
    break;

  case 539:
#line 2498 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5788 "conf_parser.c"
    break;

  case 540:
#line 2503 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5796 "conf_parser.c"
    break;

  case 541:
#line 2508 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 5804 "conf_parser.c"
    break;

  case 542:
#line 2513 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 5812 "conf_parser.c"
    break;

  case 543:
#line 2518 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5820 "conf_parser.c"
    break;

  case 544:
#line 2523 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5828 "conf_parser.c"
    break;

  case 545:
#line 2528 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5836 "conf_parser.c"
    break;

  case 546:
#line 2533 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5844 "conf_parser.c"
    break;

  case 547:
#line 2538 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 5852 "conf_parser.c"
    break;

  case 548:
#line 2543 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5860 "conf_parser.c"
    break;

  case 549:
#line 2548 "conf_parser.y"
{
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5868 "conf_parser.c"
    break;

  case 550:
#line 2553 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5876 "conf_parser.c"
    break;

  case 551:
#line 2558 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5884 "conf_parser.c"
    break;

  case 552:
#line 2563 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5892 "conf_parser.c"
    break;

  case 553:
#line 2568 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5900 "conf_parser.c"
    break;

  case 554:
#line 2573 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5908 "conf_parser.c"
    break;

  case 555:
#line 2578 "conf_parser.y"
{
  ConfigGeneral.oper_umodes = 0;
}
#line 5916 "conf_parser.c"
    break;

  case 559:
#line 2584 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5924 "conf_parser.c"
    break;

  case 560:
#line 2587 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5932 "conf_parser.c"
    break;

  case 561:
#line 2590 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5940 "conf_parser.c"
    break;

  case 562:
#line 2593 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FLOOD;
}
#line 5948 "conf_parser.c"
    break;

  case 563:
#line 2596 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5956 "conf_parser.c"
    break;

  case 564:
#line 2599 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5964 "conf_parser.c"
    break;

  case 565:
#line 2602 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5972 "conf_parser.c"
    break;

  case 566:
#line 2605 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5980 "conf_parser.c"
    break;

  case 567:
#line 2608 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5988 "conf_parser.c"
    break;

  case 568:
#line 2611 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5996 "conf_parser.c"
    break;

  case 569:
#line 2614 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6004 "conf_parser.c"
    break;

  case 570:
#line 2617 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6012 "conf_parser.c"
    break;

  case 571:
#line 2620 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6020 "conf_parser.c"
    break;

  case 572:
#line 2623 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6028 "conf_parser.c"
    break;

  case 573:
#line 2626 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6036 "conf_parser.c"
    break;

  case 574:
#line 2629 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6044 "conf_parser.c"
    break;

  case 575:
#line 2632 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6052 "conf_parser.c"
    break;

  case 576:
#line 2635 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6060 "conf_parser.c"
    break;

  case 577:
#line 2638 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6068 "conf_parser.c"
    break;

  case 578:
#line 2641 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6076 "conf_parser.c"
    break;

  case 579:
#line 2644 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6084 "conf_parser.c"
    break;

  case 580:
#line 2649 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6092 "conf_parser.c"
    break;

  case 584:
#line 2655 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6100 "conf_parser.c"
    break;

  case 585:
#line 2658 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6108 "conf_parser.c"
    break;

  case 586:
#line 2661 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6116 "conf_parser.c"
    break;

  case 587:
#line 2664 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FLOOD;
}
#line 6124 "conf_parser.c"
    break;

  case 588:
#line 2667 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6132 "conf_parser.c"
    break;

  case 589:
#line 2670 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6140 "conf_parser.c"
    break;

  case 590:
#line 2673 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6148 "conf_parser.c"
    break;

  case 591:
#line 2676 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6156 "conf_parser.c"
    break;

  case 592:
#line 2679 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6164 "conf_parser.c"
    break;

  case 593:
#line 2682 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6172 "conf_parser.c"
    break;

  case 594:
#line 2685 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6180 "conf_parser.c"
    break;

  case 595:
#line 2688 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6188 "conf_parser.c"
    break;

  case 596:
#line 2691 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6196 "conf_parser.c"
    break;

  case 597:
#line 2694 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6204 "conf_parser.c"
    break;

  case 598:
#line 2697 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6212 "conf_parser.c"
    break;

  case 599:
#line 2700 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6220 "conf_parser.c"
    break;

  case 600:
#line 2703 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6228 "conf_parser.c"
    break;

  case 601:
#line 2706 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6236 "conf_parser.c"
    break;

  case 602:
#line 2709 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6244 "conf_parser.c"
    break;

  case 603:
#line 2714 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6252 "conf_parser.c"
    break;

  case 604:
#line 2719 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6260 "conf_parser.c"
    break;

  case 605:
#line 2724 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6268 "conf_parser.c"
    break;

  case 606:
#line 2729 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6276 "conf_parser.c"
    break;

  case 626:
#line 2758 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6284 "conf_parser.c"
    break;

  case 627:
#line 2763 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6292 "conf_parser.c"
    break;

  case 628:
#line 2768 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6300 "conf_parser.c"
    break;

  case 629:
#line 2773 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6308 "conf_parser.c"
    break;

  case 630:
#line 2778 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6316 "conf_parser.c"
    break;

  case 631:
#line 2783 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6324 "conf_parser.c"
    break;

  case 632:
#line 2788 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6332 "conf_parser.c"
    break;

  case 633:
#line 2793 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6340 "conf_parser.c"
    break;

  case 634:
#line 2798 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6348 "conf_parser.c"
    break;

  case 635:
#line 2803 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6356 "conf_parser.c"
    break;

  case 636:
#line 2808 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6364 "conf_parser.c"
    break;

  case 637:
#line 2813 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6372 "conf_parser.c"
    break;

  case 638:
#line 2818 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6380 "conf_parser.c"
    break;

  case 639:
#line 2823 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6388 "conf_parser.c"
    break;

  case 640:
#line 2828 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6396 "conf_parser.c"
    break;

  case 654:
#line 2851 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6405 "conf_parser.c"
    break;

  case 655:
#line 2857 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].number) > 0)
    {
      event_write_links_file.when = (yyvsp[-1].number);
      event_add(&event_write_links_file, NULL);
    }
    else
     event_delete(&event_write_links_file);

    ConfigServerHide.flatten_links_delay = (yyvsp[-1].number);
  }
}
#line 6424 "conf_parser.c"
    break;

  case 656:
#line 2873 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6436 "conf_parser.c"
    break;

  case 657:
#line 2882 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6445 "conf_parser.c"
    break;

  case 658:
#line 2888 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6454 "conf_parser.c"
    break;

  case 659:
#line 2894 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6463 "conf_parser.c"
    break;

  case 660:
#line 2900 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6475 "conf_parser.c"
    break;

  case 661:
#line 2909 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6484 "conf_parser.c"
    break;

  case 662:
#line 2915 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6493 "conf_parser.c"
    break;


#line 6497 "conf_parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
