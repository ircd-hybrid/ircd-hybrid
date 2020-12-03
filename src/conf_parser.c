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
    BOT = 266,
    BYTES = 267,
    KBYTES = 268,
    MBYTES = 269,
    CALLER_ID_WAIT = 270,
    CAN_FLOOD = 271,
    CHANNEL = 272,
    CIDR_BITLEN_IPV4 = 273,
    CIDR_BITLEN_IPV6 = 274,
    CLASS = 275,
    CLIENT = 276,
    CLOSE = 277,
    CONNECT = 278,
    CONNECTFREQ = 279,
    CYCLE_ON_HOST_CHANGE = 280,
    DEFAULT_FLOODCOUNT = 281,
    DEFAULT_FLOODTIME = 282,
    DEFAULT_JOIN_FLOOD_COUNT = 283,
    DEFAULT_JOIN_FLOOD_TIME = 284,
    DEFAULT_MAX_CLIENTS = 285,
    DEFER = 286,
    DENY = 287,
    DESCRIPTION = 288,
    DIE = 289,
    DISABLE_AUTH = 290,
    DISABLE_FAKE_CHANNELS = 291,
    DISABLE_REMOTE_COMMANDS = 292,
    DLINE_MIN_CIDR = 293,
    DLINE_MIN_CIDR6 = 294,
    DOTS_IN_IDENT = 295,
    EMAIL = 296,
    ENABLE_EXTBANS = 297,
    ENCRYPTED = 298,
    EXCEED_LIMIT = 299,
    EXEMPT = 300,
    EXPIRATION = 301,
    FAILED_OPER_NOTICE = 302,
    FLATTEN_LINKS = 303,
    FLATTEN_LINKS_DELAY = 304,
    FLATTEN_LINKS_FILE = 305,
    GECOS = 306,
    GENERAL = 307,
    HIDDEN = 308,
    HIDDEN_NAME = 309,
    HIDE_CHANS = 310,
    HIDE_IDLE = 311,
    HIDE_IDLE_FROM_OPERS = 312,
    HIDE_SERVER_IPS = 313,
    HIDE_SERVERS = 314,
    HIDE_SERVICES = 315,
    HOST = 316,
    HUB = 317,
    HUB_MASK = 318,
    INVISIBLE_ON_CONNECT = 319,
    INVITE_CLIENT_COUNT = 320,
    INVITE_CLIENT_TIME = 321,
    INVITE_DELAY_CHANNEL = 322,
    INVITE_EXPIRE_TIME = 323,
    IP = 324,
    IRCD_AUTH = 325,
    IRCD_FLAGS = 326,
    IRCD_SID = 327,
    JOIN = 328,
    KILL = 329,
    KILL_CHASE_TIME_LIMIT = 330,
    KLINE = 331,
    KLINE_EXEMPT = 332,
    KLINE_MIN_CIDR = 333,
    KLINE_MIN_CIDR6 = 334,
    KNOCK_CLIENT_COUNT = 335,
    KNOCK_CLIENT_TIME = 336,
    KNOCK_DELAY_CHANNEL = 337,
    LEAF_MASK = 338,
    LISTEN = 339,
    MASK = 340,
    MAX_ACCEPT = 341,
    MAX_BANS = 342,
    MAX_BANS_LARGE = 343,
    MAX_CHANNELS = 344,
    MAX_IDLE = 345,
    MAX_INVITES = 346,
    MAX_MONITOR = 347,
    MAX_NICK_CHANGES = 348,
    MAX_NICK_LENGTH = 349,
    MAX_NICK_TIME = 350,
    MAX_NUMBER = 351,
    MAX_TARGETS = 352,
    MAX_TOPIC_LENGTH = 353,
    MIN_IDLE = 354,
    MIN_NONWILDCARD = 355,
    MIN_NONWILDCARD_SIMPLE = 356,
    MODULE = 357,
    MODULES = 358,
    MOTD = 359,
    NAME = 360,
    NEED_IDENT = 361,
    NEED_PASSWORD = 362,
    NETWORK_DESCRIPTION = 363,
    NETWORK_NAME = 364,
    NICK = 365,
    NO_OPER_FLOOD = 366,
    NO_TILDE = 367,
    NUMBER_PER_CIDR = 368,
    NUMBER_PER_IP_GLOBAL = 369,
    NUMBER_PER_IP_LOCAL = 370,
    OPER_ONLY_UMODES = 371,
    OPER_UMODES = 372,
    OPERATOR = 373,
    OPERS_BYPASS_CALLERID = 374,
    PACE_WAIT = 375,
    PACE_WAIT_SIMPLE = 376,
    PASSWORD = 377,
    PATH = 378,
    PING_COOKIE = 379,
    PING_TIME = 380,
    PORT = 381,
    RANDOM_IDLE = 382,
    REASON = 383,
    REDIRPORT = 384,
    REDIRSERV = 385,
    REHASH = 386,
    REMOTE = 387,
    REMOTEBAN = 388,
    RESV = 389,
    RESV_EXEMPT = 390,
    RSA_PRIVATE_KEY_FILE = 391,
    SECONDS = 392,
    MINUTES = 393,
    HOURS = 394,
    DAYS = 395,
    WEEKS = 396,
    MONTHS = 397,
    YEARS = 398,
    SEND_PASSWORD = 399,
    SENDQ = 400,
    SERVERHIDE = 401,
    SERVERINFO = 402,
    SHORT_MOTD = 403,
    SPOOF = 404,
    SQUIT = 405,
    STATS_E_DISABLED = 406,
    STATS_I_OPER_ONLY = 407,
    STATS_K_OPER_ONLY = 408,
    STATS_M_OPER_ONLY = 409,
    STATS_O_OPER_ONLY = 410,
    STATS_P_OPER_ONLY = 411,
    STATS_U_OPER_ONLY = 412,
    T_ALL = 413,
    T_BIND = 414,
    T_CALLERID = 415,
    T_CCONN = 416,
    T_COMMAND = 417,
    T_CLUSTER = 418,
    T_DEAF = 419,
    T_DEBUG = 420,
    T_DLINE = 421,
    T_EXTERNAL = 422,
    T_FARCONNECT = 423,
    T_FILE = 424,
    T_FLOOD = 425,
    T_GLOBOPS = 426,
    T_INVISIBLE = 427,
    T_IPV4 = 428,
    T_IPV6 = 429,
    T_LOCOPS = 430,
    T_LOG = 431,
    T_NCHANGE = 432,
    T_NONONREG = 433,
    T_OPME = 434,
    T_PREPEND = 435,
    T_PSEUDO = 436,
    T_RECVQ = 437,
    T_REJ = 438,
    T_RESTART = 439,
    T_SERVER = 440,
    T_SERVICE = 441,
    T_SERVNOTICE = 442,
    T_SET = 443,
    T_SHARED = 444,
    T_SIZE = 445,
    T_SKILL = 446,
    T_SOFTCALLERID = 447,
    T_SPY = 448,
    T_TARGET = 449,
    T_TLS = 450,
    T_UMODES = 451,
    T_UNDLINE = 452,
    T_UNLIMITED = 453,
    T_UNRESV = 454,
    T_UNXLINE = 455,
    T_WALLOP = 456,
    T_WALLOPS = 457,
    T_WEBIRC = 458,
    TBOOL = 459,
    THROTTLE_COUNT = 460,
    THROTTLE_TIME = 461,
    TIMEOUT = 462,
    TLS_CERTIFICATE_FILE = 463,
    TLS_CERTIFICATE_FINGERPRINT = 464,
    TLS_CIPHER_LIST = 465,
    TLS_CIPHER_SUITES = 466,
    TLS_CONNECTION_REQUIRED = 467,
    TLS_DH_PARAM_FILE = 468,
    TLS_MESSAGE_DIGEST_ALGORITHM = 469,
    TLS_SUPPORTED_GROUPS = 470,
    TS_MAX_DELTA = 471,
    TS_WARN_DELTA = 472,
    TWODOTS = 473,
    TYPE = 474,
    UNKLINE = 475,
    USE_LOGGING = 476,
    USER = 477,
    VHOST = 478,
    VHOST6 = 479,
    WARN_NO_CONNECT_BLOCK = 480,
    WHOIS = 481,
    WHOWAS_HISTORY_LENGTH = 482,
    XLINE = 483,
    XLINE_EXEMPT = 484,
    QSTRING = 485,
    NUMBER = 486
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
#define BOT 266
#define BYTES 267
#define KBYTES 268
#define MBYTES 269
#define CALLER_ID_WAIT 270
#define CAN_FLOOD 271
#define CHANNEL 272
#define CIDR_BITLEN_IPV4 273
#define CIDR_BITLEN_IPV6 274
#define CLASS 275
#define CLIENT 276
#define CLOSE 277
#define CONNECT 278
#define CONNECTFREQ 279
#define CYCLE_ON_HOST_CHANGE 280
#define DEFAULT_FLOODCOUNT 281
#define DEFAULT_FLOODTIME 282
#define DEFAULT_JOIN_FLOOD_COUNT 283
#define DEFAULT_JOIN_FLOOD_TIME 284
#define DEFAULT_MAX_CLIENTS 285
#define DEFER 286
#define DENY 287
#define DESCRIPTION 288
#define DIE 289
#define DISABLE_AUTH 290
#define DISABLE_FAKE_CHANNELS 291
#define DISABLE_REMOTE_COMMANDS 292
#define DLINE_MIN_CIDR 293
#define DLINE_MIN_CIDR6 294
#define DOTS_IN_IDENT 295
#define EMAIL 296
#define ENABLE_EXTBANS 297
#define ENCRYPTED 298
#define EXCEED_LIMIT 299
#define EXEMPT 300
#define EXPIRATION 301
#define FAILED_OPER_NOTICE 302
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
#define HIDE_SERVER_IPS 313
#define HIDE_SERVERS 314
#define HIDE_SERVICES 315
#define HOST 316
#define HUB 317
#define HUB_MASK 318
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
#define MASK 340
#define MAX_ACCEPT 341
#define MAX_BANS 342
#define MAX_BANS_LARGE 343
#define MAX_CHANNELS 344
#define MAX_IDLE 345
#define MAX_INVITES 346
#define MAX_MONITOR 347
#define MAX_NICK_CHANGES 348
#define MAX_NICK_LENGTH 349
#define MAX_NICK_TIME 350
#define MAX_NUMBER 351
#define MAX_TARGETS 352
#define MAX_TOPIC_LENGTH 353
#define MIN_IDLE 354
#define MIN_NONWILDCARD 355
#define MIN_NONWILDCARD_SIMPLE 356
#define MODULE 357
#define MODULES 358
#define MOTD 359
#define NAME 360
#define NEED_IDENT 361
#define NEED_PASSWORD 362
#define NETWORK_DESCRIPTION 363
#define NETWORK_NAME 364
#define NICK 365
#define NO_OPER_FLOOD 366
#define NO_TILDE 367
#define NUMBER_PER_CIDR 368
#define NUMBER_PER_IP_GLOBAL 369
#define NUMBER_PER_IP_LOCAL 370
#define OPER_ONLY_UMODES 371
#define OPER_UMODES 372
#define OPERATOR 373
#define OPERS_BYPASS_CALLERID 374
#define PACE_WAIT 375
#define PACE_WAIT_SIMPLE 376
#define PASSWORD 377
#define PATH 378
#define PING_COOKIE 379
#define PING_TIME 380
#define PORT 381
#define RANDOM_IDLE 382
#define REASON 383
#define REDIRPORT 384
#define REDIRSERV 385
#define REHASH 386
#define REMOTE 387
#define REMOTEBAN 388
#define RESV 389
#define RESV_EXEMPT 390
#define RSA_PRIVATE_KEY_FILE 391
#define SECONDS 392
#define MINUTES 393
#define HOURS 394
#define DAYS 395
#define WEEKS 396
#define MONTHS 397
#define YEARS 398
#define SEND_PASSWORD 399
#define SENDQ 400
#define SERVERHIDE 401
#define SERVERINFO 402
#define SHORT_MOTD 403
#define SPOOF 404
#define SQUIT 405
#define STATS_E_DISABLED 406
#define STATS_I_OPER_ONLY 407
#define STATS_K_OPER_ONLY 408
#define STATS_M_OPER_ONLY 409
#define STATS_O_OPER_ONLY 410
#define STATS_P_OPER_ONLY 411
#define STATS_U_OPER_ONLY 412
#define T_ALL 413
#define T_BIND 414
#define T_CALLERID 415
#define T_CCONN 416
#define T_COMMAND 417
#define T_CLUSTER 418
#define T_DEAF 419
#define T_DEBUG 420
#define T_DLINE 421
#define T_EXTERNAL 422
#define T_FARCONNECT 423
#define T_FILE 424
#define T_FLOOD 425
#define T_GLOBOPS 426
#define T_INVISIBLE 427
#define T_IPV4 428
#define T_IPV6 429
#define T_LOCOPS 430
#define T_LOG 431
#define T_NCHANGE 432
#define T_NONONREG 433
#define T_OPME 434
#define T_PREPEND 435
#define T_PSEUDO 436
#define T_RECVQ 437
#define T_REJ 438
#define T_RESTART 439
#define T_SERVER 440
#define T_SERVICE 441
#define T_SERVNOTICE 442
#define T_SET 443
#define T_SHARED 444
#define T_SIZE 445
#define T_SKILL 446
#define T_SOFTCALLERID 447
#define T_SPY 448
#define T_TARGET 449
#define T_TLS 450
#define T_UMODES 451
#define T_UNDLINE 452
#define T_UNLIMITED 453
#define T_UNRESV 454
#define T_UNXLINE 455
#define T_WALLOP 456
#define T_WALLOPS 457
#define T_WEBIRC 458
#define TBOOL 459
#define THROTTLE_COUNT 460
#define THROTTLE_TIME 461
#define TIMEOUT 462
#define TLS_CERTIFICATE_FILE 463
#define TLS_CERTIFICATE_FINGERPRINT 464
#define TLS_CIPHER_LIST 465
#define TLS_CIPHER_SUITES 466
#define TLS_CONNECTION_REQUIRED 467
#define TLS_DH_PARAM_FILE 468
#define TLS_MESSAGE_DIGEST_ALGORITHM 469
#define TLS_SUPPORTED_GROUPS 470
#define TS_MAX_DELTA 471
#define TS_WARN_DELTA 472
#define TWODOTS 473
#define TYPE 474
#define UNKLINE 475
#define USE_LOGGING 476
#define USER 477
#define VHOST 478
#define VHOST6 479
#define WARN_NO_CONNECT_BLOCK 480
#define WHOIS 481
#define WHOWAS_HISTORY_LENGTH 482
#define XLINE 483
#define XLINE_EXEMPT 484
#define QSTRING 485
#define NUMBER 486

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 694 "conf_parser.c"

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
#define YYLAST   1240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  238
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  665
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1311

#define YYUNDEFTOK  2
#define YYMAXUTOK   486


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
       2,     2,     2,     2,   236,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   237,   232,
       2,   235,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   234,     2,   233,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   366,   366,   367,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   397,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   408,   408,
     409,   410,   411,   412,   419,   421,   421,   422,   422,   422,
     424,   430,   440,   442,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   462,   471,   480,   489,   498,   507,   516,   525,
     540,   555,   565,   579,   588,   611,   634,   657,   667,   669,
     669,   670,   671,   672,   673,   675,   684,   693,   707,   706,
     724,   724,   725,   725,   725,   727,   733,   744,   743,   762,
     762,   763,   763,   763,   763,   763,   765,   771,   777,   783,
     805,   806,   806,   808,   808,   809,   811,   818,   818,   831,
     832,   834,   834,   835,   835,   837,   845,   848,   854,   853,
     859,   859,   860,   864,   868,   872,   876,   880,   884,   888,
     899,   898,   961,   961,   962,   963,   964,   965,   966,   967,
     968,   969,   970,   971,   972,   974,   980,   986,   992,   998,
    1009,  1015,  1026,  1033,  1032,  1038,  1038,  1039,  1043,  1047,
    1051,  1055,  1059,  1063,  1067,  1071,  1075,  1079,  1083,  1087,
    1091,  1095,  1099,  1103,  1107,  1111,  1115,  1119,  1123,  1130,
    1129,  1135,  1135,  1136,  1140,  1144,  1148,  1152,  1156,  1160,
    1164,  1168,  1172,  1176,  1180,  1184,  1188,  1192,  1196,  1200,
    1204,  1208,  1212,  1216,  1220,  1224,  1228,  1232,  1236,  1240,
    1244,  1248,  1259,  1258,  1314,  1314,  1315,  1316,  1317,  1318,
    1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,
    1329,  1330,  1332,  1338,  1344,  1350,  1356,  1362,  1368,  1374,
    1380,  1387,  1393,  1399,  1405,  1414,  1424,  1423,  1429,  1429,
    1430,  1434,  1445,  1444,  1451,  1450,  1455,  1455,  1456,  1460,
    1464,  1468,  1472,  1478,  1478,  1479,  1479,  1479,  1479,  1479,
    1481,  1481,  1483,  1483,  1485,  1498,  1515,  1521,  1532,  1531,
    1578,  1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,  1586,
    1587,  1589,  1595,  1601,  1607,  1619,  1618,  1624,  1624,  1625,
    1629,  1633,  1637,  1641,  1645,  1649,  1653,  1657,  1663,  1677,
    1686,  1700,  1699,  1714,  1714,  1715,  1715,  1715,  1715,  1717,
    1723,  1729,  1739,  1741,  1741,  1742,  1742,  1744,  1761,  1760,
    1783,  1783,  1784,  1784,  1784,  1784,  1786,  1792,  1812,  1811,
    1817,  1817,  1818,  1822,  1826,  1830,  1834,  1838,  1842,  1846,
    1850,  1854,  1865,  1864,  1883,  1883,  1884,  1884,  1884,  1886,
    1893,  1892,  1898,  1898,  1899,  1903,  1907,  1911,  1915,  1919,
    1923,  1927,  1931,  1935,  1946,  1945,  2023,  2023,  2024,  2025,
    2026,  2027,  2028,  2029,  2030,  2031,  2032,  2033,  2034,  2035,
    2036,  2037,  2038,  2039,  2041,  2047,  2053,  2059,  2065,  2078,
    2091,  2097,  2103,  2107,  2114,  2113,  2118,  2118,  2119,  2123,
    2129,  2140,  2146,  2152,  2158,  2174,  2173,  2197,  2197,  2198,
    2198,  2198,  2200,  2220,  2231,  2230,  2255,  2255,  2256,  2256,
    2256,  2258,  2264,  2274,  2276,  2276,  2277,  2277,  2279,  2297,
    2296,  2317,  2317,  2318,  2318,  2318,  2320,  2326,  2336,  2338,
    2338,  2339,  2340,  2341,  2342,  2343,  2344,  2345,  2346,  2347,
    2348,  2349,  2350,  2351,  2352,  2353,  2354,  2355,  2356,  2357,
    2358,  2359,  2360,  2361,  2362,  2363,  2364,  2365,  2366,  2367,
    2368,  2369,  2370,  2371,  2372,  2373,  2374,  2375,  2376,  2377,
    2378,  2379,  2380,  2381,  2382,  2383,  2384,  2387,  2392,  2397,
    2402,  2407,  2412,  2417,  2422,  2427,  2432,  2437,  2442,  2447,
    2452,  2457,  2462,  2467,  2472,  2477,  2482,  2487,  2492,  2497,
    2502,  2507,  2512,  2517,  2522,  2527,  2532,  2537,  2542,  2547,
    2552,  2557,  2562,  2567,  2572,  2577,  2583,  2582,  2587,  2587,
    2588,  2591,  2594,  2597,  2600,  2603,  2606,  2609,  2612,  2615,
    2618,  2621,  2624,  2627,  2630,  2633,  2636,  2639,  2642,  2645,
    2648,  2651,  2657,  2656,  2661,  2661,  2662,  2665,  2668,  2671,
    2674,  2677,  2680,  2683,  2686,  2689,  2692,  2695,  2698,  2701,
    2704,  2707,  2710,  2713,  2716,  2719,  2724,  2729,  2734,  2739,
    2748,  2750,  2750,  2751,  2752,  2753,  2754,  2755,  2756,  2757,
    2758,  2759,  2760,  2761,  2762,  2763,  2764,  2765,  2766,  2768,
    2773,  2778,  2783,  2788,  2793,  2798,  2803,  2808,  2813,  2818,
    2823,  2828,  2833,  2838,  2847,  2849,  2849,  2850,  2851,  2852,
    2853,  2854,  2855,  2856,  2857,  2858,  2859,  2861,  2867,  2883,
    2892,  2898,  2904,  2910,  2919,  2925
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ADMIN", "AFTYPE",
  "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME", "AUTOCONN",
  "AWAY_COUNT", "AWAY_TIME", "BOT", "BYTES", "KBYTES", "MBYTES",
  "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL", "CIDR_BITLEN_IPV4",
  "CIDR_BITLEN_IPV6", "CLASS", "CLIENT", "CLOSE", "CONNECT", "CONNECTFREQ",
  "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME",
  "DEFAULT_JOIN_FLOOD_COUNT", "DEFAULT_JOIN_FLOOD_TIME",
  "DEFAULT_MAX_CLIENTS", "DEFER", "DENY", "DESCRIPTION", "DIE",
  "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS",
  "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6", "DOTS_IN_IDENT", "EMAIL",
  "ENABLE_EXTBANS", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "EXPIRATION",
  "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "FLATTEN_LINKS_DELAY",
  "FLATTEN_LINKS_FILE", "GECOS", "GENERAL", "HIDDEN", "HIDDEN_NAME",
  "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK",
  "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME",
  "INVITE_DELAY_CHANNEL", "INVITE_EXPIRE_TIME", "IP", "IRCD_AUTH",
  "IRCD_FLAGS", "IRCD_SID", "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT",
  "KLINE", "KLINE_EXEMPT", "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6",
  "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL",
  "LEAF_MASK", "LISTEN", "MASK", "MAX_ACCEPT", "MAX_BANS",
  "MAX_BANS_LARGE", "MAX_CHANNELS", "MAX_IDLE", "MAX_INVITES",
  "MAX_MONITOR", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME",
  "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MIN_IDLE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD",
  "NAME", "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESCRIPTION",
  "NETWORK_NAME", "NICK", "NO_OPER_FLOOD", "NO_TILDE", "NUMBER_PER_CIDR",
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
     485,   486,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF (-981)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -981,   902,  -981,  -173,  -229,  -202,  -981,  -981,  -981,  -184,
    -981,  -177,  -981,  -981,  -981,  -172,  -981,  -981,  -981,  -163,
    -161,  -981,  -123,  -981,  -106,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,   281,   927,   -97,   -96,   -80,    27,   -56,   398,   -48,
     -45,   -34,    51,   -25,    -6,    -2,   558,   547,    20,    12,
      36,    15,    49,  -212,    54,    56,    61,    14,  -981,  -981,
    -981,  -981,  -981,    68,    70,    71,    72,    75,    81,    82,
      91,    92,    94,    96,    97,    98,    99,   100,     2,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,   846,   633,    23,  -981,   102,
      16,  -981,  -981,    42,  -981,   104,   106,   108,   110,   112,
     117,   124,   127,   137,   138,   139,   140,   148,   149,   150,
     152,   153,   154,   156,   158,   160,   163,   174,   180,   181,
    -981,  -981,   182,   187,   191,   192,   193,   194,   196,   197,
     199,   200,   206,   207,   208,   213,   214,   215,   217,   218,
      39,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,   359,    40,   349,
      83,   219,   221,    25,  -981,  -981,  -981,    50,   335,   264,
    -981,   223,   225,   230,   231,   232,   233,   234,   236,   239,
     164,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,   171,   243,   245,   250,   251,   252,   257,   261,   262,
     265,   268,   269,   270,   271,   277,   278,   285,   143,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,    57,   284,   286,    13,
    -981,  -981,  -981,   363,   220,  -981,   300,    28,  -981,  -981,
       8,  -981,   307,   308,   309,   310,  -981,   224,   312,   336,
     337,   314,   312,   312,   312,   325,   312,   312,   327,   329,
     332,   333,   334,  -981,   339,   330,   340,   341,  -981,   343,
     347,   348,   350,   351,   352,   353,   355,   357,   361,   362,
     179,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,   342,   364,   365,
     366,   367,   370,   378,  -981,   385,   386,   387,   392,   397,
     405,   407,   408,   237,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,   411,   412,    38,  -981,  -981,  -981,   338,   401,  -981,
    -981,   414,   415,   115,  -981,  -981,  -981,   368,   312,   399,
     312,   312,   380,   420,   312,   450,   427,   432,   434,   462,
     463,   312,   437,   439,   441,   444,   446,   312,   448,   451,
     453,   477,   452,   454,   481,   312,   312,   486,   487,   488,
     489,   493,   494,   495,   497,   501,   475,   312,   312,   312,
     504,   476,   479,  -981,   480,   474,   478,  -981,   482,   484,
     485,   490,   491,    55,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,   499,   500,    80,  -981,  -981,  -981,
     483,   506,   507,  -981,   508,  -981,    26,  -981,  -981,  -981,
    -981,  -981,   492,   498,   512,  -981,   513,   511,   515,     3,
    -981,  -981,  -981,   516,   518,   519,  -981,   521,   528,  -981,
     529,   530,   531,   532,   168,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,   537,   535,   536,   538,
      79,  -981,  -981,  -981,  -981,   510,   517,   312,   502,   520,
     544,   525,   543,   572,   549,  -981,  -981,   505,   554,   583,
     559,   560,   563,   567,   568,   569,   570,   573,   574,   576,
     577,   578,   582,   581,  -981,   584,   579,  -981,    62,  -981,
    -981,  -981,  -981,   598,   585,  -981,    52,   586,   580,   587,
     588,   589,   105,  -981,  -981,  -981,  -981,  -981,   590,   593,
    -981,   594,   592,  -981,   595,    41,  -981,  -981,  -981,  -981,
     596,   597,   599,  -981,   600,   228,   601,   602,   603,   604,
     605,   606,   607,   609,   614,   621,   623,   625,   626,   628,
    -981,  -981,   619,   632,   312,   631,   637,   312,   638,   312,
     591,   641,   642,   643,   312,   647,   647,   648,  -981,  -981,
     649,   -64,   651,   680,   658,   661,   660,   663,   666,   667,
     671,   674,   312,   677,   678,   679,  -981,   682,   686,   688,
    -981,   689,  -981,   694,   696,   695,  -981,   697,   698,   699,
     700,   701,   705,   706,   707,   708,   709,   711,   712,   714,
     716,   717,   718,   720,   725,   726,   730,   732,   733,   734,
     735,   736,   722,   618,   738,   741,   742,   743,   745,   746,
     747,   748,   749,   750,   751,   752,   753,   755,   756,   757,
     758,   764,  -981,  -981,   767,   794,   675,   769,   687,   770,
     771,   772,   778,  -981,   773,   774,   779,  -981,  -981,   782,
     783,   784,   786,   789,  -981,   790,   791,  -981,  -981,   795,
     796,   792,  -981,  -981,   797,   825,   798,   800,   801,   799,
     802,   831,   807,   808,   809,  -981,  -981,   810,   812,   813,
     814,  -981,   815,   818,   819,   820,   821,   822,   823,   824,
     826,  -981,   827,   828,   829,   830,   832,   834,   835,   836,
     837,   838,   839,   840,   841,   842,   843,   844,  -981,  -981,
     833,   804,   845,  -981,   847,  -981,   121,  -981,   850,   851,
     852,   854,   853,  -981,   855,  -981,  -981,   856,   857,   859,
     858,  -981,  -981,  -981,  -981,  -981,   312,   312,   312,   312,
     312,   312,   312,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,   861,
     862,   863,    -4,   864,   865,   866,   867,   868,   869,   870,
     871,   872,    22,   873,   874,  -981,   875,   876,   877,   878,
     879,   880,   881,     4,   882,   883,   884,   885,   886,   887,
     888,   889,  -981,   890,   891,  -981,  -981,   892,   893,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -214,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -213,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,   894,
     895,   395,   896,   897,   898,   899,   900,  -981,   901,   903,
    -981,   904,   905,   266,   916,   906,  -981,  -981,  -981,  -981,
     907,   908,  -981,   909,   911,   460,   912,   913,   684,   914,
     915,   917,   918,  -981,   919,   920,   921,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,   922,   503,  -981,  -981,   923,   924,   925,
    -981,   111,  -981,  -981,  -981,  -981,   926,   929,   930,   931,
    -981,  -981,   932,   552,   933,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -211,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,   647,
     647,   647,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -199,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
     722,  -981,   618,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -160,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
     -87,  -981,   935,   786,   936,  -981,  -981,  -981,  -981,  -981,
    -981,   934,  -981,   937,   938,  -981,  -981,   939,   940,  -981,
    -981,   941,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,   -75,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
     -61,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
     -53,  -981,  -981,   942,  -137,   944,   948,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,   -30,  -981,  -981,  -981,    -4,  -981,  -981,
    -981,  -981,     4,  -981,  -981,  -981,   395,  -981,   266,  -981,
    -981,  -981,  1006,   435,  1016,   910,  1024,  1025,  -981,   460,
    -981,   684,  -981,   503,   949,   950,   951,   345,  -981,  -981,
     552,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,    -7,  -981,  -981,  -981,   345,
    -981
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   232,   394,   444,     0,
     459,     0,   298,   435,   272,     0,    98,   150,   331,     0,
       0,   372,     0,   107,     0,   348,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      93,    92,   628,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   612,
     627,   626,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   613,   614,   624,   625,     0,     0,     0,   457,     0,
       0,   455,   456,     0,   516,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     582,   556,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   470,   471,   472,   514,   478,   515,   509,   510,   511,
     512,   482,   473,   474,   475,   476,   477,   479,   480,   481,
     483,   484,   513,   488,   489,   490,   491,   487,   486,   492,
     499,   500,   493,   494,   495,   485,   497,   507,   508,   505,
     506,   498,   496,   503,   504,   501,   502,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     656,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   646,   647,   648,   649,   650,   651,   652,   654,   653,
     655,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      67,    65,    63,    68,    69,    70,    64,    55,    66,    57,
      58,    59,    60,    61,    62,    56,     0,     0,     0,     0,
     122,   123,   124,     0,     0,   346,     0,     0,   344,   345,
       0,    94,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   611,     0,     0,     0,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   235,   236,   239,   241,   242,   243,   244,   245,   246,
     247,   237,   238,   240,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   397,   398,   399,   400,   401,   402,
     403,   404,   406,   405,   408,   412,   409,   410,   411,   407,
     450,     0,     0,     0,   447,   448,   449,     0,     0,   454,
     465,     0,     0,     0,   462,   463,   464,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   469,     0,     0,     0,   315,     0,     0,
       0,     0,     0,     0,   301,   302,   303,   304,   309,   305,
     306,   307,   308,   441,     0,     0,     0,   438,   439,   440,
       0,     0,     0,   274,     0,   286,     0,   284,   285,   287,
     288,    49,     0,     0,     0,    45,     0,     0,     0,     0,
     101,   102,   103,     0,     0,     0,   199,     0,     0,   173,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     160,   161,   162,   159,   158,   163,     0,     0,     0,     0,
       0,   334,   335,   336,   337,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   645,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,   380,     0,   375,
     376,   377,   125,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   113,   112,   114,     0,     0,
     343,     0,     0,   358,     0,     0,   351,   352,   353,   354,
       0,     0,     0,    88,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     610,   251,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   413,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   396,     0,     0,     0,
     446,     0,   453,     0,     0,     0,   461,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   468,   310,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   300,     0,     0,     0,   437,   289,     0,
       0,     0,     0,     0,   283,     0,     0,    44,   104,     0,
       0,     0,   100,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,   338,     0,     0,     0,
       0,   333,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   644,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,   378,
       0,     0,     0,   374,     0,   120,     0,   115,     0,     0,
       0,     0,     0,   109,     0,   342,   355,     0,     0,     0,
       0,   350,    97,    96,    95,   642,    28,    28,    28,    28,
      28,    28,    28,    30,    29,   643,   630,   629,   631,   632,
     633,   634,   635,   636,   637,   640,   641,   638,   639,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   395,     0,     0,   445,   458,     0,     0,   460,
     528,   532,   517,   518,   545,   521,   608,   609,   553,   522,
     523,   550,   527,   535,   526,   524,   525,   531,   519,   530,
     529,   551,   606,   607,   549,   586,   605,   592,   601,   587,
     588,   589,   596,   604,   590,   598,   602,   593,   603,   594,
     597,   591,   600,   595,   599,     0,   585,   560,   581,   565,
     566,   567,   577,   561,   562,   563,   572,   580,   564,   574,
     578,   569,   579,   570,   573,   568,   576,   571,   575,     0,
     559,   546,   544,   547,   552,   548,   537,   543,   542,   538,
     539,   540,   541,   554,   555,   534,   533,   536,   520,     0,
       0,     0,     0,     0,     0,     0,     0,   299,     0,     0,
     436,     0,     0,     0,   294,   290,   293,   273,    50,    51,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   151,     0,     0,     0,   332,   660,   657,
     658,   659,   664,   663,   665,   661,   662,    84,    81,    87,
      80,    85,    86,    79,    83,    82,    73,    72,    75,    76,
      74,    77,    78,     0,     0,   373,   126,     0,     0,     0,
     138,     0,   130,   131,   133,   132,     0,     0,     0,     0,
     108,   347,     0,     0,     0,   349,    31,    32,    33,    34,
      35,    36,    37,   261,   262,   256,   271,   270,     0,   269,
     257,   265,   258,   264,   252,   263,   255,   254,   253,    38,
      38,    38,    40,    39,   259,   260,   419,   422,   423,   433,
     430,   415,   431,   428,   429,     0,   427,   432,   414,   421,
     418,   417,   416,   420,   434,   451,   452,   466,   467,   583,
       0,   557,     0,   313,   314,   323,   319,   320,   322,   327,
     324,   325,   326,   321,     0,   318,   312,   330,   329,   328,
     311,   443,   442,   297,   296,   281,   282,   279,   280,   278,
       0,   277,     0,     0,     0,   105,   106,   172,   169,   219,
     231,   206,   215,     0,   204,   209,   225,     0,   218,   223,
     229,   208,   211,   220,   222,   226,   216,   224,   212,   230,
     214,   221,   210,   213,     0,   202,   165,   167,   177,   198,
     182,   183,   184,   194,   178,   179,   180,   189,   197,   181,
     191,   195,   186,   196,   187,   190,   185,   193,   188,   192,
       0,   176,   170,   171,   166,   168,   341,   339,   340,   379,
     384,   390,   393,   386,   392,   387,   391,   389,   385,   388,
       0,   383,   134,     0,     0,     0,     0,   129,   117,   116,
     118,   119,   356,   362,   368,   371,   364,   370,   365,   369,
     367,   363,   366,     0,   361,   357,   267,     0,    41,    42,
      43,   425,     0,   584,   558,   316,     0,   275,     0,   295,
     292,   291,     0,     0,     0,     0,     0,     0,   200,     0,
     174,     0,   381,     0,     0,     0,     0,     0,   128,   359,
       0,   268,   426,   317,   276,   205,   228,   203,   227,   217,
     207,   201,   175,   382,   135,   137,   136,   148,   147,   143,
     145,   149,   146,   142,   144,     0,   141,   360,   139,     0,
     140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -981,  -981,  -981,  -293,  -306,  -980,  -635,  -981,  -981,   946,
    -981,  -981,  -981,  -981,   777,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,   980,  -981,  -981,  -981,  -981,  -981,  -981,
     668,  -981,  -981,  -981,  -981,  -981,   608,  -981,  -981,  -981,
    -981,  -981,  -981,   928,  -981,  -981,  -981,  -981,   129,  -981,
    -981,  -981,  -981,  -981,  -136,  -981,  -981,  -981,   670,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
     -86,  -981,  -981,  -981,   -83,  -981,  -981,  -981,   848,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,   -60,  -981,  -981,  -981,
    -981,  -981,   -69,  -981,   710,  -981,  -981,  -981,    48,  -981,
    -981,  -981,  -981,  -981,   729,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,   -63,  -981,  -981,  -981,  -981,  -981,  -981,   664,
    -981,  -981,  -981,  -981,  -981,   943,  -981,  -981,  -981,  -981,
     610,  -981,  -981,  -981,  -981,  -981,   -85,  -981,  -981,  -981,
     629,  -981,  -981,  -981,  -981,   -74,  -981,  -981,  -981,   849,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,   -54,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,   724,  -981,  -981,  -981,  -981,  -981,   811,  -981,  -981,
    -981,  -981,  1081,  -981,  -981,  -981,  -981,   803,  -981,  -981,
    -981,  -981,  1032,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,    95,  -981,  -981,  -981,    93,
    -981,  -981,  -981,  -981,  -981,  -981,  1110,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981,   969,  -981,  -981,  -981,  -981,  -981,
    -981,  -981,  -981,  -981
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   823,   824,  1082,  1083,    27,   223,   224,
     225,   226,    28,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    29,    77,    78,    79,    80,    81,    30,    63,   499,
     500,   501,   502,    31,    70,   582,   583,   584,   585,   586,
     587,    32,   289,   290,   291,   292,   293,  1041,  1042,  1043,
    1044,  1045,  1225,  1305,  1306,    33,    64,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   749,  1200,
    1201,   525,   746,  1174,  1175,    34,    53,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   625,  1068,  1069,    35,    61,   485,
     731,  1140,  1141,   486,   487,   488,  1144,   985,   986,   489,
     490,    36,    59,   463,   464,   465,   466,   467,   468,   469,
     716,  1124,  1125,   470,   471,   472,    37,    65,   530,   531,
     532,   533,   534,    38,   297,   298,   299,    39,    72,   595,
     596,   597,   598,   599,   808,  1243,  1244,    40,    68,   568,
     569,   570,   571,   791,  1220,  1221,    41,    54,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     646,  1095,  1096,   385,   386,   387,   388,   389,    42,    60,
     476,   477,   478,   479,    43,    55,   393,   394,   395,   396,
      44,   120,   121,   122,    45,    57,   403,   404,   405,   406,
      46,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   433,   949,   950,   212,   432,   925,   926,
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
     853,   854,   606,    82,   496,    51,   610,   611,   612,   591,
     614,   615,  1093,   287,   287,    73,   295,   118,  1109,  1111,
     301,  1246,  1110,  1112,   390,  1247,   220,   480,   118,   295,
      83,    84,    52,  1251,  1079,  1080,  1081,  1252,    85,   390,
     124,   473,   591,   400,    86,   125,   126,    74,   127,   128,
      56,   496,   220,  1066,   129,    75,   454,    58,   565,    49,
      50,  1275,    62,   565,   130,   131,   132,    87,    88,    89,
      90,    66,  1255,    67,   133,   455,  1256,   134,   135,   136,
     526,   473,    91,    92,    93,   119,   137,   481,   497,    94,
      95,    96,   391,    97,   852,   482,   119,   483,   456,  1248,
    1249,  1250,   668,   138,   670,   671,   577,   391,   674,   857,
     858,    69,  1037,   592,   139,   681,   400,   140,   141,    76,
     296,   687,  1037,  1067,   527,   142,   457,   221,    71,   695,
     696,   143,   144,   296,   145,   497,   146,   115,   116,   147,
     148,   707,   708,   709,   251,  1257,   592,   401,   222,  1258,
     149,   392,   484,   221,   117,   150,   151,  1268,   152,   153,
     154,  1269,   566,   155,   528,   230,   392,   566,   474,   503,
     402,  1270,   498,   252,   222,  1271,   253,   458,   123,  1272,
     324,  -127,  -127,  1273,   459,   460,   217,   156,   504,   218,
     157,   158,   159,   160,   161,   162,   163,   325,   326,  1094,
     219,   231,  1279,   327,   461,   254,  1280,   529,   474,   227,
     578,   505,   232,   233,   234,   255,  1038,   235,   236,   498,
     401,   577,   237,   238,   239,  1308,  1038,   593,   228,  1309,
     594,   764,   229,   288,   288,   322,   741,   256,   357,   506,
     358,   257,   359,   402,   164,   165,   574,   305,   258,   398,
     328,   259,   260,   852,   286,   166,   167,   360,   494,   733,
     593,   589,   475,   594,   168,   526,   169,   579,   329,   330,
     294,   659,   452,   507,   810,   331,   567,   462,   332,   261,
     361,   567,    73,   300,   333,   580,   796,  1135,   722,   302,
     508,   303,   334,   335,   336,   792,   304,  1136,   362,   581,
     363,  1039,   475,   307,   337,   308,   309,   310,   364,   527,
     311,  1039,   760,   726,    74,   491,   312,   313,   841,  1137,
     365,   844,    75,   846,   338,   578,   314,   315,   851,   316,
    1040,   317,   318,   319,   320,   321,   503,   397,   802,   407,
    1040,   408,   366,   409,  1226,   410,   869,   411,   665,   528,
     480,   262,   412,   263,   264,   504,   265,   266,   267,   413,
     454,   339,   414,   367,   509,   816,   817,   818,   819,   820,
     821,   822,   415,   416,   417,   418,   563,   510,   505,   455,
     511,   368,   579,   419,   420,   421,    76,   422,   423,   424,
     512,   425,   529,   426,   513,   427,   369,   544,   428,   124,
     580,   754,   456,   546,   125,   126,   506,   127,   128,   429,
     481,  1115,   637,   129,   581,   430,   431,   434,   482,  1297,
     483,  1298,   435,   130,   131,   132,   436,   437,   438,   439,
     457,   440,   441,   133,   442,   443,   134,   135,   136,  1116,
     507,   444,   445,   446,   370,   137,   371,   372,   447,   448,
     449,  1138,   450,   451,   492,   604,   493,   508,   535,   605,
     536,  1139,   138,  1299,  1149,   537,   538,   539,   540,   541,
     655,   542,  1117,   139,   543,   484,   140,   141,   547,  1300,
     548,   458,  1150,  1151,   142,   549,   550,   551,   459,   460,
     143,   144,   552,   145,  1152,   146,   553,   554,   147,   148,
     555,  1118,  1119,   556,   557,   558,   559,  1120,   461,   149,
    1301,  1302,   560,   561,   150,   151,   572,   152,   153,   154,
     562,   573,   155,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
    1121,   509,   576,  1153,  1154,   588,  1155,   600,   601,   602,
     607,   608,   603,   605,   510,   609,   156,   511,   251,   157,
     158,   159,   160,   161,   162,   163,   613,   512,   616,   230,
     617,   513,  1156,   618,   619,   622,   620,  1303,   661,  1286,
    1157,   621,   667,  1304,   639,   623,   624,   252,   626,  1210,
     253,   462,   627,   628,   672,   629,   630,   631,   632,  1276,
     633,  1158,   634,  1159,  1160,   231,   635,   636,  1122,   640,
     641,   642,   643,   164,   165,   644,   232,   233,   234,   254,
    1161,   235,   236,   645,   166,   167,   237,   238,   239,   255,
     647,   648,   649,   168,  1123,   169,  1162,   650,  1233,   927,
     669,  1163,   651,   662,   357,  1164,   358,  1211,   359,  1165,
     652,   256,   653,   654,  1166,   257,   657,   658,  1167,   663,
     664,   673,   258,   360,   675,   259,   260,  1168,   676,  1169,
    1170,  1212,  1171,   677,   928,   678,   679,   680,   682,  1213,
     683,   929,   684,   930,   931,   685,   361,   686,  1214,   688,
    1172,   691,   689,   261,   690,   694,  1234,   692,  1173,   693,
     697,   698,   699,   700,   362,  1178,   363,   701,   702,   703,
    1215,   704,  1216,  1217,   364,   705,   706,   711,   710,   714,
    1235,   712,   713,   715,   762,   728,   365,   717,  1236,   718,
     719,   763,   735,  1218,   766,   720,   721,  1237,   736,   768,
    1179,  1219,   765,   905,   724,   725,   772,  1180,   366,  1181,
    1182,   729,   730,   732,   737,   738,   739,   769,   743,  1238,
     740,  1239,  1240,   744,   745,   262,   747,   263,   264,   367,
     265,   266,   267,   748,   750,   751,   752,   753,   906,   756,
     757,   758,  1241,   759,   767,   907,   770,   368,   932,   933,
    1242,   771,   934,   935,   773,   936,   937,   774,   938,   775,
     939,   776,   369,   940,   777,   941,   942,   778,   779,   780,
     781,   943,   794,   782,   783,   944,   784,   785,   786,   945,
     946,   947,   787,   788,   790,   798,   789,   795,   797,   948,
     804,   847,   799,   800,   801,   805,   806,   807,   812,   813,
     809,   814,   815,   825,   826,   827,   828,   829,   830,   831,
     370,   832,   371,   372,  1183,  1184,   833,   324,  1185,  1186,
     839,  1187,  1188,   834,  1189,   835,  1190,   836,   837,  1191,
     838,  1192,  1193,   840,   325,   326,   842,  1194,   843,   845,
     327,  1195,   848,   849,   850,  1196,  1197,  1198,   852,   856,
     855,   859,   908,   909,   860,  1199,   910,   911,   861,   912,
     913,   862,   914,   864,   915,   863,   865,   916,   866,   917,
     918,   867,     2,     3,   868,   919,     4,   870,   871,   920,
     971,   872,   873,   921,   922,   923,   874,   328,   973,     5,
     875,   876,     6,   924,   877,     7,   878,   879,    82,   880,
     881,   882,   883,   884,     8,   329,   330,   885,   886,   887,
     888,   889,   331,   890,   891,   332,   892,     9,   893,   894,
     895,   333,   896,    10,    11,    83,    84,   897,   898,   334,
     335,   336,   899,    85,   900,   901,   902,   903,   904,    86,
     951,   337,    12,   952,   953,   954,    13,   955,   956,   957,
     958,   959,   960,   961,   962,   963,    14,   964,   965,   966,
     967,   338,    87,    88,    89,    90,   968,   969,   970,   972,
     974,   975,   976,   978,   979,    15,    16,    91,    92,    93,
     977,   980,   981,   982,    94,    95,    96,   984,    97,   983,
      17,   987,   988,   989,   992,   990,   991,   993,   339,   994,
     996,   997,   999,   995,   998,  1000,    18,  1001,  1002,  1034,
    1004,  1003,  1005,  1006,  1288,   564,  1007,  1008,    19,    20,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,   306,  1016,  1017,
    1018,  1019,  1020,  1033,  1021,    21,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1035,    22,  1036,
    1046,  1047,  1048,    23,  1049,  1050,  1052,  1051,    24,  1054,
    1055,    25,  1053,  1063,  1064,  1065,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1097,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1108,  1113,  1114,  1126,  1127,
    1128,  1129,  1130,  1131,  1142,  1132,  1133,  1134,  1285,  1145,
    1146,  1147,  1143,  1148,  1176,  1177,  1202,  1203,  1287,  1204,
    1205,  1206,  1207,  1208,  1209,  1222,  1289,  1290,  1228,  1223,
    1224,  1229,  1230,  1231,  1232,  1245,  1259,   742,  1261,   495,
    1227,  1262,  1274,  1310,  1263,  1264,  1265,  1266,  1267,  1277,
    1278,  1294,  1295,  1296,   755,  1292,  1291,  1281,   638,  1284,
     803,  1260,   723,  1283,   761,  1307,   734,   793,  1282,  1293,
     727,   399,   453,  1253,   660,   811,   666,  1254,   323,   545,
       0,     0,     0,     0,     0,     0,     0,   575,     0,     0,
       0,     0,   656,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590
};

static const yytype_int16 yycheck[] =
{
     635,   636,   308,     1,     1,   234,   312,   313,   314,     1,
     316,   317,     8,     1,     1,     1,     1,     1,   232,   232,
     232,   232,   236,   236,     1,   236,     1,     1,     1,     1,
      28,    29,   234,   232,    12,    13,    14,   236,    36,     1,
       1,     1,     1,     1,    42,     6,     7,    33,     9,    10,
     234,     1,     1,    57,    15,    41,     1,   234,     1,   232,
     233,   198,   234,     1,    25,    26,    27,    65,    66,    67,
      68,   234,   232,   234,    35,    20,   236,    38,    39,    40,
       1,     1,    80,    81,    82,    69,    47,    61,    85,    87,
      88,    89,    69,    91,   231,    69,    69,    71,    43,  1079,
    1080,  1081,   408,    64,   410,   411,     1,    69,   414,   173,
     174,   234,     1,   105,    75,   421,     1,    78,    79,   105,
     105,   427,     1,   127,    45,    86,    71,   102,   234,   435,
     436,    92,    93,   105,    95,    85,    97,   234,   234,   100,
     101,   447,   448,   449,     1,   232,   105,   105,   123,   236,
     111,   128,   126,   102,   234,   116,   117,   232,   119,   120,
     121,   236,   105,   124,    85,     1,   128,   105,   128,     1,
     128,   232,   169,    30,   123,   236,    33,   122,   234,   232,
       1,   169,   169,   236,   129,   130,   234,   148,    20,   234,
     151,   152,   153,   154,   155,   156,   157,    18,    19,   195,
     234,    37,   232,    24,   149,    62,   236,   128,   128,   234,
     105,    43,    48,    49,    50,    72,   105,    53,    54,   169,
     105,     1,    58,    59,    60,   232,   105,   219,   234,   236,
     222,   537,   234,   221,   221,   233,   233,    94,     1,    71,
       3,    98,     5,   128,   205,   206,   233,   233,   105,   233,
      71,   108,   109,   231,   234,   216,   217,    20,   233,   233,
     219,   233,   222,   222,   225,     1,   227,   162,    89,    90,
     234,   233,   233,   105,   233,    96,   219,   222,    99,   136,
      43,   219,     1,   234,   105,   180,   234,    21,   233,   235,
     122,   235,   113,   114,   115,   233,   235,    31,    61,   194,
      63,   190,   222,   235,   125,   235,   235,   235,    71,    45,
     235,   190,   233,   233,    33,   232,   235,   235,   624,    53,
      83,   627,    41,   629,   145,   105,   235,   235,   634,   235,
     219,   235,   235,   235,   235,   235,     1,   235,   233,   235,
     219,   235,   105,   235,   233,   235,   652,   235,   233,    85,
       1,   208,   235,   210,   211,    20,   213,   214,   215,   235,
       1,   182,   235,   126,   196,   137,   138,   139,   140,   141,
     142,   143,   235,   235,   235,   235,   233,   209,    43,    20,
     212,   144,   162,   235,   235,   235,   105,   235,   235,   235,
     222,   235,   128,   235,   226,   235,   159,   233,   235,     1,
     180,   233,    43,   232,     6,     7,    71,     9,    10,   235,
      61,    16,   233,    15,   194,   235,   235,   235,    69,    74,
      71,    76,   235,    25,    26,    27,   235,   235,   235,   235,
      71,   235,   235,    35,   235,   235,    38,    39,    40,    44,
     105,   235,   235,   235,   207,    47,   209,   210,   235,   235,
     235,   185,   235,   235,   235,   231,   235,   122,   235,   231,
     235,   195,    64,   118,     4,   235,   235,   235,   235,   235,
     233,   235,    77,    75,   235,   126,    78,    79,   235,   134,
     235,   122,    22,    23,    86,   235,   235,   235,   129,   130,
      92,    93,   235,    95,    34,    97,   235,   235,   100,   101,
     235,   106,   107,   235,   235,   235,   235,   112,   149,   111,
     165,   166,   235,   235,   116,   117,   232,   119,   120,   121,
     235,   235,   124,   816,   817,   818,   819,   820,   821,   822,
     135,   196,   169,    73,    74,   235,    76,   230,   230,   230,
     204,   204,   232,   231,   209,   231,   148,   212,     1,   151,
     152,   153,   154,   155,   156,   157,   231,   222,   231,     1,
     231,   226,   102,   231,   231,   235,   232,   222,   230,   134,
     110,   232,   204,   228,   232,   235,   235,    30,   235,    76,
      33,   222,   235,   235,   204,   235,   235,   235,   235,  1224,
     235,   131,   235,   133,   134,    37,   235,   235,   203,   235,
     235,   235,   235,   205,   206,   235,    48,    49,    50,    62,
     150,    53,    54,   235,   216,   217,    58,    59,    60,    72,
     235,   235,   235,   225,   229,   227,   166,   235,    76,    11,
     231,   171,   235,   232,     1,   175,     3,   134,     5,   179,
     235,    94,   235,   235,   184,    98,   235,   235,   188,   235,
     235,   231,   105,    20,   204,   108,   109,   197,   231,   199,
     200,   158,   202,   231,    46,   231,   204,   204,   231,   166,
     231,    53,   231,    55,    56,   231,    43,   231,   175,   231,
     220,   204,   231,   136,   231,   204,   134,   235,   228,   235,
     204,   204,   204,   204,    61,    11,    63,   204,   204,   204,
     197,   204,   199,   200,    71,   204,   231,   231,   204,   235,
     158,   232,   232,   235,   204,   232,    83,   235,   166,   235,
     235,   204,   230,   220,   204,   235,   235,   175,   230,   204,
      46,   228,   230,    11,   235,   235,   231,    53,   105,    55,
      56,   235,   235,   235,   232,   232,   235,   204,   232,   197,
     235,   199,   200,   235,   235,   208,   235,   210,   211,   126,
     213,   214,   215,   235,   235,   235,   235,   235,    46,   232,
     235,   235,   220,   235,   230,    53,   204,   144,   160,   161,
     228,   232,   164,   165,   230,   167,   168,   204,   170,   230,
     172,   231,   159,   175,   231,   177,   178,   230,   230,   230,
     230,   183,   204,   230,   230,   187,   230,   230,   230,   191,
     192,   193,   230,   232,   235,   235,   232,   232,   232,   201,
     230,   230,   235,   235,   235,   232,   232,   235,   232,   232,
     235,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     207,   232,   209,   210,   160,   161,   232,     1,   164,   165,
     231,   167,   168,   232,   170,   232,   172,   232,   232,   175,
     232,   177,   178,   231,    18,    19,   235,   183,   231,   231,
      24,   187,   231,   231,   231,   191,   192,   193,   231,   230,
     232,   230,   160,   161,   204,   201,   164,   165,   230,   167,
     168,   230,   170,   230,   172,   235,   230,   175,   231,   177,
     178,   230,     0,     1,   230,   183,     4,   230,   230,   187,
     235,   232,   230,   191,   192,   193,   230,    71,   231,    17,
     232,   232,    20,   201,   230,    23,   230,   232,     1,   232,
     232,   232,   232,   232,    32,    89,    90,   232,   232,   232,
     232,   232,    96,   232,   232,    99,   232,    45,   232,   232,
     232,   105,   232,    51,    52,    28,    29,   232,   232,   113,
     114,   115,   232,    36,   232,   232,   232,   232,   232,    42,
     232,   125,    70,   232,   232,   232,    74,   232,   232,   232,
     232,   232,   232,   232,   232,   232,    84,   232,   232,   232,
     232,   145,    65,    66,    67,    68,   232,   230,   204,   230,
     230,   230,   230,   230,   230,   103,   104,    80,    81,    82,
     232,   232,   230,   230,    87,    88,    89,   231,    91,   235,
     118,   232,   232,   232,   232,   230,   230,   230,   182,   204,
     230,   230,   230,   235,   235,   204,   134,   230,   230,   235,
     230,   232,   230,   230,   134,   268,   232,   232,   146,   147,
     232,   232,   232,   232,   232,   232,   232,    77,   232,   232,
     232,   232,   232,   230,   232,   163,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   176,   232,
     230,   230,   230,   181,   230,   232,   230,   232,   186,   230,
     232,   189,   235,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   218,   232,   232,   232,   132,   232,
     232,   232,   236,   232,   232,   232,   232,   232,   132,   232,
     232,   232,   232,   232,   232,   232,   132,   132,   232,   235,
     235,   232,   232,   232,   232,   232,   231,   499,   232,   223,
    1041,   237,   230,  1309,   237,   237,   237,   237,   237,   235,
     232,   232,   232,   232,   514,  1271,  1269,  1247,   340,  1258,
     582,  1143,   463,  1256,   530,  1280,   486,   568,  1252,  1273,
     476,   120,   170,  1110,   393,   595,   403,  1112,    98,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   289,    -1,    -1,
      -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     297
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   239,     0,     1,     4,    17,    20,    23,    32,    45,
      51,    52,    70,    74,    84,   103,   104,   118,   134,   146,
     147,   163,   176,   181,   186,   189,   240,   245,   250,   269,
     275,   281,   289,   303,   323,   345,   359,   374,   381,   385,
     395,   404,   426,   432,   438,   442,   448,   502,   520,   232,
     233,   234,   234,   324,   405,   433,   234,   443,   234,   360,
     427,   346,   234,   276,   304,   375,   234,   234,   396,   234,
     282,   234,   386,     1,    33,    41,   105,   270,   271,   272,
     273,   274,     1,    28,    29,    36,    42,    65,    66,    67,
      68,    80,    81,    82,    87,    88,    89,    91,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   234,   234,   234,     1,    69,
     439,   440,   441,   234,     1,     6,     7,     9,    10,    15,
      25,    26,    27,    35,    38,    39,    40,    47,    64,    75,
      78,    79,    86,    92,    93,    95,    97,   100,   101,   111,
     116,   117,   119,   120,   121,   124,   148,   151,   152,   153,
     154,   155,   156,   157,   205,   206,   216,   217,   225,   227,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   494,   498,   499,   500,   501,   234,   234,   234,
       1,   102,   123,   246,   247,   248,   249,   234,   234,   234,
       1,    37,    48,    49,    50,    53,    54,    58,    59,    60,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,     1,    30,    33,    62,    72,    94,    98,   105,   108,
     109,   136,   208,   210,   211,   213,   214,   215,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   234,     1,   221,   290,
     291,   292,   293,   294,   234,     1,   105,   382,   383,   384,
     234,   232,   235,   235,   235,   233,   271,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   233,   504,     1,    18,    19,    24,    71,    89,
      90,    96,    99,   105,   113,   114,   115,   125,   145,   182,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,     1,     3,     5,
      20,    43,    61,    63,    71,    83,   105,   126,   144,   159,
     207,   209,   210,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   421,   422,   423,   424,   425,
       1,    69,   128,   434,   435,   436,   437,   235,   233,   440,
       1,   105,   128,   444,   445,   446,   447,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   495,   491,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   233,   450,     1,    20,    43,    71,   122,   129,
     130,   149,   222,   361,   362,   363,   364,   365,   366,   367,
     371,   372,   373,     1,   128,   222,   428,   429,   430,   431,
       1,    61,    69,    71,   126,   347,   351,   352,   353,   357,
     358,   232,   235,   235,   233,   247,     1,    85,   169,   277,
     278,   279,   280,     1,    20,    43,    71,   105,   122,   196,
     209,   212,   222,   226,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   319,     1,    45,    85,   128,
     376,   377,   378,   379,   380,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   233,   522,   232,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   233,   252,     1,   105,   219,   397,   398,
     399,   400,   232,   235,   233,   291,   169,     1,   105,   162,
     180,   194,   283,   284,   285,   286,   287,   288,   235,   233,
     383,     1,   105,   219,   222,   387,   388,   389,   390,   391,
     230,   230,   230,   232,   231,   231,   242,   204,   204,   231,
     242,   242,   242,   231,   242,   242,   231,   231,   231,   231,
     232,   232,   235,   235,   235,   342,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   233,   326,   232,
     235,   235,   235,   235,   235,   235,   418,   235,   235,   235,
     235,   235,   235,   235,   235,   233,   407,   235,   235,   233,
     435,   230,   232,   235,   235,   233,   445,   204,   242,   231,
     242,   242,   204,   231,   242,   204,   231,   231,   231,   204,
     204,   242,   231,   231,   231,   231,   231,   242,   231,   231,
     231,   204,   235,   235,   204,   242,   242,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   231,   242,   242,   242,
     204,   231,   232,   232,   235,   235,   368,   235,   235,   235,
     235,   235,   233,   362,   235,   235,   233,   429,   232,   235,
     235,   348,   235,   233,   352,   230,   230,   232,   232,   235,
     235,   233,   278,   232,   235,   235,   320,   235,   235,   316,
     235,   235,   235,   235,   233,   306,   232,   235,   235,   235,
     233,   377,   204,   204,   242,   230,   204,   230,   204,   204,
     204,   232,   231,   230,   204,   230,   231,   231,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   232,   232,
     235,   401,   233,   398,   204,   232,   234,   232,   235,   235,
     235,   235,   233,   284,   230,   232,   232,   235,   392,   235,
     233,   388,   232,   232,   232,   232,   137,   138,   139,   140,
     141,   142,   143,   241,   242,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   231,
     231,   242,   235,   231,   242,   231,   242,   230,   231,   231,
     231,   242,   231,   244,   244,   232,   230,   173,   174,   230,
     204,   230,   230,   235,   230,   230,   231,   230,   230,   242,
     230,   230,   232,   230,   230,   232,   232,   230,   230,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,    11,    46,    53,   160,   161,
     164,   165,   167,   168,   170,   172,   175,   177,   178,   183,
     187,   191,   192,   193,   201,   496,   497,    11,    46,    53,
      55,    56,   160,   161,   164,   165,   167,   168,   170,   172,
     175,   177,   178,   183,   187,   191,   192,   193,   201,   492,
     493,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   230,
     204,   235,   230,   231,   230,   230,   230,   232,   230,   230,
     232,   230,   230,   235,   231,   355,   356,   232,   232,   232,
     230,   230,   232,   230,   204,   235,   230,   230,   235,   230,
     204,   230,   230,   232,   230,   230,   230,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   230,   235,   232,   232,     1,   105,   190,
     219,   295,   296,   297,   298,   299,   230,   230,   230,   230,
     232,   232,   230,   235,   230,   232,   241,   241,   241,   241,
     241,   241,   241,   232,   232,   232,    57,   127,   343,   344,
     232,   232,   232,   232,   232,   232,   232,   232,   232,    12,
      13,    14,   243,   244,   232,   232,   232,   232,   232,   232,
     232,   232,   232,     8,   195,   419,   420,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     236,   232,   236,   232,   232,    16,    44,    77,   106,   107,
     112,   135,   203,   229,   369,   370,   232,   232,   232,   232,
     232,   232,   232,   232,   232,    21,    31,    53,   185,   195,
     349,   350,   218,   236,   354,   232,   232,   232,   232,     4,
      22,    23,    34,    73,    74,    76,   102,   110,   131,   133,
     134,   150,   166,   171,   175,   179,   184,   188,   197,   199,
     200,   202,   220,   228,   321,   322,   232,   232,    11,    46,
      53,    55,    56,   160,   161,   164,   165,   167,   168,   170,
     172,   175,   177,   178,   183,   187,   191,   192,   193,   201,
     317,   318,   232,   232,   232,   232,   232,   232,   232,   232,
      76,   134,   158,   166,   175,   197,   199,   200,   220,   228,
     402,   403,   232,   235,   235,   300,   233,   296,   232,   232,
     232,   232,   232,    76,   134,   158,   166,   175,   197,   199,
     200,   220,   228,   393,   394,   232,   232,   236,   243,   243,
     243,   232,   236,   497,   493,   232,   236,   232,   236,   231,
     356,   232,   237,   237,   237,   237,   237,   237,   232,   236,
     232,   236,   232,   236,   230,   198,   244,   235,   232,   232,
     236,   344,   420,   370,   350,   132,   134,   132,   134,   132,
     132,   322,   318,   403,   232,   232,   232,    74,    76,   118,
     134,   165,   166,   222,   228,   301,   302,   394,   232,   236,
     302
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   238,   239,   239,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   241,   241,
     242,   242,   242,   242,   242,   242,   242,   242,   243,   243,
     244,   244,   244,   244,   245,   246,   246,   247,   247,   247,
     248,   249,   250,   251,   251,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     270,   271,   271,   271,   271,   272,   273,   274,   276,   275,
     277,   277,   278,   278,   278,   279,   280,   282,   281,   283,
     283,   284,   284,   284,   284,   284,   285,   286,   287,   288,
     289,   290,   290,   291,   291,   291,   292,   294,   293,   295,
     295,   296,   296,   296,   296,   297,   298,   298,   300,   299,
     301,   301,   302,   302,   302,   302,   302,   302,   302,   302,
     304,   303,   305,   305,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   316,   315,   317,   317,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   320,
     319,   321,   321,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   324,   323,   325,   325,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   342,   341,   343,   343,
     344,   344,   346,   345,   348,   347,   349,   349,   350,   350,
     350,   350,   350,   351,   351,   352,   352,   352,   352,   352,
     354,   353,   355,   355,   356,   356,   357,   358,   360,   359,
     361,   361,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   363,   364,   365,   366,   368,   367,   369,   369,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   371,   372,
     373,   375,   374,   376,   376,   377,   377,   377,   377,   378,
     379,   380,   381,   382,   382,   383,   383,   384,   386,   385,
     387,   387,   388,   388,   388,   388,   389,   390,   392,   391,
     393,   393,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   396,   395,   397,   397,   398,   398,   398,   399,
     401,   400,   402,   402,   403,   403,   403,   403,   403,   403,
     403,   403,   403,   403,   405,   404,   406,   406,   407,   407,
     407,   407,   407,   407,   407,   407,   407,   407,   407,   407,
     407,   407,   407,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   416,   418,   417,   419,   419,   420,   420,
     421,   422,   423,   424,   425,   427,   426,   428,   428,   429,
     429,   429,   430,   431,   433,   432,   434,   434,   435,   435,
     435,   436,   437,   438,   439,   439,   440,   440,   441,   443,
     442,   444,   444,   445,   445,   445,   446,   447,   448,   449,
     449,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   491,   490,   492,   492,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   495,   494,   496,   496,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   498,   499,   500,   501,
     502,   503,   503,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   521,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     0,     6,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       0,     5,     3,     1,     1,     3,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     2,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       4,     4,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4
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
#line 397 "conf_parser.y"
           { (yyval.number) = 0; }
#line 2941 "conf_parser.c"
    break;

  case 30:
#line 398 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2947 "conf_parser.c"
    break;

  case 31:
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2953 "conf_parser.c"
    break;

  case 32:
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2959 "conf_parser.c"
    break;

  case 33:
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2965 "conf_parser.c"
    break;

  case 34:
#line 402 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2971 "conf_parser.c"
    break;

  case 35:
#line 403 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2977 "conf_parser.c"
    break;

  case 36:
#line 404 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2983 "conf_parser.c"
    break;

  case 37:
#line 405 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2989 "conf_parser.c"
    break;

  case 38:
#line 408 "conf_parser.y"
            { (yyval.number) = 0; }
#line 2995 "conf_parser.c"
    break;

  case 40:
#line 409 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3001 "conf_parser.c"
    break;

  case 41:
#line 410 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3007 "conf_parser.c"
    break;

  case 42:
#line 411 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3013 "conf_parser.c"
    break;

  case 43:
#line 412 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3019 "conf_parser.c"
    break;

  case 50:
#line 425 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 3028 "conf_parser.c"
    break;

  case 51:
#line 431 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 3037 "conf_parser.c"
    break;

  case 72:
#line 463 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = xstrdup(yylval.string);
  }
}
#line 3049 "conf_parser.c"
    break;

  case 73:
#line 472 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 3061 "conf_parser.c"
    break;

  case 74:
#line 481 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3073 "conf_parser.c"
    break;

  case 75:
#line 490 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = xstrdup(yylval.string);
  }
}
#line 3085 "conf_parser.c"
    break;

  case 76:
#line 499 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = xstrdup(yylval.string);
  }
}
#line 3097 "conf_parser.c"
    break;

  case 77:
#line 508 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3109 "conf_parser.c"
    break;

  case 78:
#line 517 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = xstrdup(yylval.string);
  }
}
#line 3121 "conf_parser.c"
    break;

  case 79:
#line 526 "conf_parser.y"
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
#line 3139 "conf_parser.c"
    break;

  case 80:
#line 541 "conf_parser.y"
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
#line 3157 "conf_parser.c"
    break;

  case 81:
#line 556 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3170 "conf_parser.c"
    break;

  case 82:
#line 566 "conf_parser.y"
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
#line 3187 "conf_parser.c"
    break;

  case 83:
#line 580 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = xstrdup(yylval.string);
}
#line 3199 "conf_parser.c"
    break;

  case 84:
#line 589 "conf_parser.y"
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
#line 3225 "conf_parser.c"
    break;

  case 85:
#line 612 "conf_parser.y"
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
#line 3251 "conf_parser.c"
    break;

  case 86:
#line 635 "conf_parser.y"
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
#line 3277 "conf_parser.c"
    break;

  case 87:
#line 658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3286 "conf_parser.c"
    break;

  case 95:
#line 676 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3298 "conf_parser.c"
    break;

  case 96:
#line 685 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3310 "conf_parser.c"
    break;

  case 97:
#line 694 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3322 "conf_parser.c"
    break;

  case 98:
#line 707 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3331 "conf_parser.c"
    break;

  case 99:
#line 711 "conf_parser.y"
{
  dlink_node *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3348 "conf_parser.c"
    break;

  case 105:
#line 728 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3357 "conf_parser.c"
    break;

  case 106:
#line 734 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3366 "conf_parser.c"
    break;

  case 107:
#line 744 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3375 "conf_parser.c"
    break;

  case 108:
#line 748 "conf_parser.y"
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
#line 3393 "conf_parser.c"
    break;

  case 116:
#line 766 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3402 "conf_parser.c"
    break;

  case 117:
#line 772 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3411 "conf_parser.c"
    break;

  case 118:
#line 778 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3420 "conf_parser.c"
    break;

  case 119:
#line 784 "conf_parser.y"
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
#line 3441 "conf_parser.c"
    break;

  case 126:
#line 812 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3450 "conf_parser.c"
    break;

  case 127:
#line 818 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3459 "conf_parser.c"
    break;

  case 128:
#line 822 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3472 "conf_parser.c"
    break;

  case 135:
#line 838 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3483 "conf_parser.c"
    break;

  case 136:
#line 846 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3491 "conf_parser.c"
    break;

  case 137:
#line 849 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3499 "conf_parser.c"
    break;

  case 138:
#line 854 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3508 "conf_parser.c"
    break;

  case 142:
#line 861 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3517 "conf_parser.c"
    break;

  case 143:
#line 865 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3526 "conf_parser.c"
    break;

  case 144:
#line 869 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3535 "conf_parser.c"
    break;

  case 145:
#line 873 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3544 "conf_parser.c"
    break;

  case 146:
#line 877 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3553 "conf_parser.c"
    break;

  case 147:
#line 881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3562 "conf_parser.c"
    break;

  case 148:
#line 885 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3571 "conf_parser.c"
    break;

  case 149:
#line 889 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3580 "conf_parser.c"
    break;

  case 150:
#line 899 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3592 "conf_parser.c"
    break;

  case 151:
#line 906 "conf_parser.y"
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
#line 3651 "conf_parser.c"
    break;

  case 165:
#line 975 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3660 "conf_parser.c"
    break;

  case 166:
#line 981 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3669 "conf_parser.c"
    break;

  case 167:
#line 987 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3678 "conf_parser.c"
    break;

  case 168:
#line 993 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3687 "conf_parser.c"
    break;

  case 169:
#line 999 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3701 "conf_parser.c"
    break;

  case 170:
#line 1010 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3710 "conf_parser.c"
    break;

  case 171:
#line 1016 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 3724 "conf_parser.c"
    break;

  case 172:
#line 1027 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3733 "conf_parser.c"
    break;

  case 173:
#line 1033 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3742 "conf_parser.c"
    break;

  case 177:
#line 1040 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOT;
}
#line 3751 "conf_parser.c"
    break;

  case 178:
#line 1044 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3760 "conf_parser.c"
    break;

  case 179:
#line 1048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3769 "conf_parser.c"
    break;

  case 180:
#line 1052 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3778 "conf_parser.c"
    break;

  case 181:
#line 1056 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FLOOD;
}
#line 3787 "conf_parser.c"
    break;

  case 182:
#line 1060 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3796 "conf_parser.c"
    break;

  case 183:
#line 1064 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3805 "conf_parser.c"
    break;

  case 184:
#line 1068 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3814 "conf_parser.c"
    break;

  case 185:
#line 1072 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3823 "conf_parser.c"
    break;

  case 186:
#line 1076 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3832 "conf_parser.c"
    break;

  case 187:
#line 1080 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3841 "conf_parser.c"
    break;

  case 188:
#line 1084 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3850 "conf_parser.c"
    break;

  case 189:
#line 1088 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3859 "conf_parser.c"
    break;

  case 190:
#line 1092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3868 "conf_parser.c"
    break;

  case 191:
#line 1096 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3877 "conf_parser.c"
    break;

  case 192:
#line 1100 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3886 "conf_parser.c"
    break;

  case 193:
#line 1104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3895 "conf_parser.c"
    break;

  case 194:
#line 1108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3904 "conf_parser.c"
    break;

  case 195:
#line 1112 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3913 "conf_parser.c"
    break;

  case 196:
#line 1116 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3922 "conf_parser.c"
    break;

  case 197:
#line 1120 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3931 "conf_parser.c"
    break;

  case 198:
#line 1124 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3940 "conf_parser.c"
    break;

  case 199:
#line 1130 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3949 "conf_parser.c"
    break;

  case 203:
#line 1137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3958 "conf_parser.c"
    break;

  case 204:
#line 1141 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3967 "conf_parser.c"
    break;

  case 205:
#line 1145 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3976 "conf_parser.c"
    break;

  case 206:
#line 1149 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3985 "conf_parser.c"
    break;

  case 207:
#line 1153 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3994 "conf_parser.c"
    break;

  case 208:
#line 1157 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4003 "conf_parser.c"
    break;

  case 209:
#line 1161 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4012 "conf_parser.c"
    break;

  case 210:
#line 1165 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4021 "conf_parser.c"
    break;

  case 211:
#line 1169 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4030 "conf_parser.c"
    break;

  case 212:
#line 1173 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4039 "conf_parser.c"
    break;

  case 213:
#line 1177 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4048 "conf_parser.c"
    break;

  case 214:
#line 1181 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4057 "conf_parser.c"
    break;

  case 215:
#line 1185 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4066 "conf_parser.c"
    break;

  case 216:
#line 1189 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4075 "conf_parser.c"
    break;

  case 217:
#line 1193 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4084 "conf_parser.c"
    break;

  case 218:
#line 1197 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4093 "conf_parser.c"
    break;

  case 219:
#line 1201 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4102 "conf_parser.c"
    break;

  case 220:
#line 1205 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4111 "conf_parser.c"
    break;

  case 221:
#line 1209 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4120 "conf_parser.c"
    break;

  case 222:
#line 1213 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4129 "conf_parser.c"
    break;

  case 223:
#line 1217 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4138 "conf_parser.c"
    break;

  case 224:
#line 1221 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4147 "conf_parser.c"
    break;

  case 225:
#line 1225 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4156 "conf_parser.c"
    break;

  case 226:
#line 1229 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4165 "conf_parser.c"
    break;

  case 227:
#line 1233 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4174 "conf_parser.c"
    break;

  case 228:
#line 1237 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4183 "conf_parser.c"
    break;

  case 229:
#line 1241 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4192 "conf_parser.c"
    break;

  case 230:
#line 1245 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4201 "conf_parser.c"
    break;

  case 231:
#line 1249 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4210 "conf_parser.c"
    break;

  case 232:
#line 1259 "conf_parser.y"
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

  case 233:
#line 1270 "conf_parser.y"
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

  case 252:
#line 1333 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4283 "conf_parser.c"
    break;

  case 253:
#line 1339 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4292 "conf_parser.c"
    break;

  case 254:
#line 1345 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4301 "conf_parser.c"
    break;

  case 255:
#line 1351 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4310 "conf_parser.c"
    break;

  case 256:
#line 1357 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4319 "conf_parser.c"
    break;

  case 257:
#line 1363 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4328 "conf_parser.c"
    break;

  case 258:
#line 1369 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4337 "conf_parser.c"
    break;

  case 259:
#line 1375 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4346 "conf_parser.c"
    break;

  case 260:
#line 1381 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4356 "conf_parser.c"
    break;

  case 261:
#line 1388 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4365 "conf_parser.c"
    break;

  case 262:
#line 1394 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4374 "conf_parser.c"
    break;

  case 263:
#line 1400 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4383 "conf_parser.c"
    break;

  case 264:
#line 1406 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4395 "conf_parser.c"
    break;

  case 265:
#line 1415 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4407 "conf_parser.c"
    break;

  case 266:
#line 1424 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4416 "conf_parser.c"
    break;

  case 270:
#line 1431 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4425 "conf_parser.c"
    break;

  case 271:
#line 1435 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4434 "conf_parser.c"
    break;

  case 272:
#line 1445 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4443 "conf_parser.c"
    break;

  case 274:
#line 1451 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4451 "conf_parser.c"
    break;

  case 278:
#line 1457 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4460 "conf_parser.c"
    break;

  case 279:
#line 1461 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4469 "conf_parser.c"
    break;

  case 280:
#line 1465 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4478 "conf_parser.c"
    break;

  case 281:
#line 1469 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4487 "conf_parser.c"
    break;

  case 282:
#line 1473 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4496 "conf_parser.c"
    break;

  case 290:
#line 1481 "conf_parser.y"
                                 { block_state.flags.value = 0; }
#line 4502 "conf_parser.c"
    break;

  case 294:
#line 1486 "conf_parser.y"
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

  case 295:
#line 1499 "conf_parser.y"
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

  case 296:
#line 1516 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4549 "conf_parser.c"
    break;

  case 297:
#line 1522 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4558 "conf_parser.c"
    break;

  case 298:
#line 1532 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4567 "conf_parser.c"
    break;

  case 299:
#line 1536 "conf_parser.y"
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

  case 311:
#line 1590 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4622 "conf_parser.c"
    break;

  case 312:
#line 1596 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4631 "conf_parser.c"
    break;

  case 313:
#line 1602 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4640 "conf_parser.c"
    break;

  case 314:
#line 1608 "conf_parser.y"
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

  case 315:
#line 1619 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4663 "conf_parser.c"
    break;

  case 319:
#line 1626 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4672 "conf_parser.c"
    break;

  case 320:
#line 1630 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4681 "conf_parser.c"
    break;

  case 321:
#line 1634 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4690 "conf_parser.c"
    break;

  case 322:
#line 1638 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4699 "conf_parser.c"
    break;

  case 323:
#line 1642 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4708 "conf_parser.c"
    break;

  case 324:
#line 1646 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4717 "conf_parser.c"
    break;

  case 325:
#line 1650 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4726 "conf_parser.c"
    break;

  case 326:
#line 1654 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4735 "conf_parser.c"
    break;

  case 327:
#line 1658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4744 "conf_parser.c"
    break;

  case 328:
#line 1664 "conf_parser.y"
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

  case 329:
#line 1678 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4773 "conf_parser.c"
    break;

  case 330:
#line 1687 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4785 "conf_parser.c"
    break;

  case 331:
#line 1700 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4797 "conf_parser.c"
    break;

  case 332:
#line 1707 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4808 "conf_parser.c"
    break;

  case 339:
#line 1718 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4817 "conf_parser.c"
    break;

  case 340:
#line 1724 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4826 "conf_parser.c"
    break;

  case 341:
#line 1730 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4835 "conf_parser.c"
    break;

  case 347:
#line 1745 "conf_parser.y"
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

  case 348:
#line 1761 "conf_parser.y"
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

  case 349:
#line 1772 "conf_parser.y"
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

  case 356:
#line 1787 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4890 "conf_parser.c"
    break;

  case 357:
#line 1793 "conf_parser.y"
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

  case 358:
#line 1812 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4921 "conf_parser.c"
    break;

  case 362:
#line 1819 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4930 "conf_parser.c"
    break;

  case 363:
#line 1823 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4939 "conf_parser.c"
    break;

  case 364:
#line 1827 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4948 "conf_parser.c"
    break;

  case 365:
#line 1831 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4957 "conf_parser.c"
    break;

  case 366:
#line 1835 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4966 "conf_parser.c"
    break;

  case 367:
#line 1839 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4975 "conf_parser.c"
    break;

  case 368:
#line 1843 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4984 "conf_parser.c"
    break;

  case 369:
#line 1847 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4993 "conf_parser.c"
    break;

  case 370:
#line 1851 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5002 "conf_parser.c"
    break;

  case 371:
#line 1855 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5011 "conf_parser.c"
    break;

  case 372:
#line 1865 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5025 "conf_parser.c"
    break;

  case 373:
#line 1874 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5038 "conf_parser.c"
    break;

  case 379:
#line 1887 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5047 "conf_parser.c"
    break;

  case 380:
#line 1893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5056 "conf_parser.c"
    break;

  case 384:
#line 1900 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5065 "conf_parser.c"
    break;

  case 385:
#line 1904 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5074 "conf_parser.c"
    break;

  case 386:
#line 1908 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5083 "conf_parser.c"
    break;

  case 387:
#line 1912 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5092 "conf_parser.c"
    break;

  case 388:
#line 1916 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5101 "conf_parser.c"
    break;

  case 389:
#line 1920 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5110 "conf_parser.c"
    break;

  case 390:
#line 1924 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5119 "conf_parser.c"
    break;

  case 391:
#line 1928 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5128 "conf_parser.c"
    break;

  case 392:
#line 1932 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5137 "conf_parser.c"
    break;

  case 393:
#line 1936 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5146 "conf_parser.c"
    break;

  case 394:
#line 1946 "conf_parser.y"
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

  case 395:
#line 1956 "conf_parser.y"
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

  case 414:
#line 2042 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5241 "conf_parser.c"
    break;

  case 415:
#line 2048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5250 "conf_parser.c"
    break;

  case 416:
#line 2054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5259 "conf_parser.c"
    break;

  case 417:
#line 2060 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5268 "conf_parser.c"
    break;

  case 418:
#line 2066 "conf_parser.y"
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

  case 419:
#line 2079 "conf_parser.y"
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

  case 420:
#line 2092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5309 "conf_parser.c"
    break;

  case 421:
#line 2098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5318 "conf_parser.c"
    break;

  case 422:
#line 2104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5327 "conf_parser.c"
    break;

  case 423:
#line 2108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5336 "conf_parser.c"
    break;

  case 424:
#line 2114 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5344 "conf_parser.c"
    break;

  case 428:
#line 2120 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5353 "conf_parser.c"
    break;

  case 429:
#line 2124 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5362 "conf_parser.c"
    break;

  case 430:
#line 2130 "conf_parser.y"
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

  case 431:
#line 2141 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5385 "conf_parser.c"
    break;

  case 432:
#line 2147 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5394 "conf_parser.c"
    break;

  case 433:
#line 2153 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5403 "conf_parser.c"
    break;

  case 434:
#line 2159 "conf_parser.y"
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

  case 435:
#line 2174 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5426 "conf_parser.c"
    break;

  case 436:
#line 2178 "conf_parser.y"
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

  case 442:
#line 2201 "conf_parser.y"
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

  case 443:
#line 2221 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5481 "conf_parser.c"
    break;

  case 444:
#line 2231 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5490 "conf_parser.c"
    break;

  case 445:
#line 2235 "conf_parser.y"
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

  case 451:
#line 2259 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5523 "conf_parser.c"
    break;

  case 452:
#line 2265 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5532 "conf_parser.c"
    break;

  case 458:
#line 2280 "conf_parser.y"
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

  case 459:
#line 2297 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5558 "conf_parser.c"
    break;

  case 460:
#line 2301 "conf_parser.y"
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

  case 466:
#line 2321 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5587 "conf_parser.c"
    break;

  case 467:
#line 2327 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5596 "conf_parser.c"
    break;

  case 517:
#line 2388 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5604 "conf_parser.c"
    break;

  case 518:
#line 2393 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5612 "conf_parser.c"
    break;

  case 519:
#line 2398 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5620 "conf_parser.c"
    break;

  case 520:
#line 2403 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5628 "conf_parser.c"
    break;

  case 521:
#line 2408 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5636 "conf_parser.c"
    break;

  case 522:
#line 2413 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5644 "conf_parser.c"
    break;

  case 523:
#line 2418 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5652 "conf_parser.c"
    break;

  case 524:
#line 2423 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5660 "conf_parser.c"
    break;

  case 525:
#line 2428 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5668 "conf_parser.c"
    break;

  case 526:
#line 2433 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5676 "conf_parser.c"
    break;

  case 527:
#line 2438 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5684 "conf_parser.c"
    break;

  case 528:
#line 2443 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5692 "conf_parser.c"
    break;

  case 529:
#line 2448 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5700 "conf_parser.c"
    break;

  case 530:
#line 2453 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5708 "conf_parser.c"
    break;

  case 531:
#line 2458 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5716 "conf_parser.c"
    break;

  case 532:
#line 2463 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5724 "conf_parser.c"
    break;

  case 533:
#line 2468 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5732 "conf_parser.c"
    break;

  case 534:
#line 2473 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5740 "conf_parser.c"
    break;

  case 535:
#line 2478 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5748 "conf_parser.c"
    break;

  case 536:
#line 2483 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5756 "conf_parser.c"
    break;

  case 537:
#line 2488 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5764 "conf_parser.c"
    break;

  case 538:
#line 2493 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5772 "conf_parser.c"
    break;

  case 539:
#line 2498 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5780 "conf_parser.c"
    break;

  case 540:
#line 2503 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5788 "conf_parser.c"
    break;

  case 541:
#line 2508 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5796 "conf_parser.c"
    break;

  case 542:
#line 2513 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 5804 "conf_parser.c"
    break;

  case 543:
#line 2518 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 5812 "conf_parser.c"
    break;

  case 544:
#line 2523 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5820 "conf_parser.c"
    break;

  case 545:
#line 2528 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5828 "conf_parser.c"
    break;

  case 546:
#line 2533 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5836 "conf_parser.c"
    break;

  case 547:
#line 2538 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5844 "conf_parser.c"
    break;

  case 548:
#line 2543 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 5852 "conf_parser.c"
    break;

  case 549:
#line 2548 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5860 "conf_parser.c"
    break;

  case 550:
#line 2553 "conf_parser.y"
{
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5868 "conf_parser.c"
    break;

  case 551:
#line 2558 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5876 "conf_parser.c"
    break;

  case 552:
#line 2563 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5884 "conf_parser.c"
    break;

  case 553:
#line 2568 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5892 "conf_parser.c"
    break;

  case 554:
#line 2573 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5900 "conf_parser.c"
    break;

  case 555:
#line 2578 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5908 "conf_parser.c"
    break;

  case 556:
#line 2583 "conf_parser.y"
{
  ConfigGeneral.oper_umodes = 0;
}
#line 5916 "conf_parser.c"
    break;

  case 560:
#line 2589 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_BOT;
}
#line 5924 "conf_parser.c"
    break;

  case 561:
#line 2592 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5932 "conf_parser.c"
    break;

  case 562:
#line 2595 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5940 "conf_parser.c"
    break;

  case 563:
#line 2598 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5948 "conf_parser.c"
    break;

  case 564:
#line 2601 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FLOOD;
}
#line 5956 "conf_parser.c"
    break;

  case 565:
#line 2604 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5964 "conf_parser.c"
    break;

  case 566:
#line 2607 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5972 "conf_parser.c"
    break;

  case 567:
#line 2610 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5980 "conf_parser.c"
    break;

  case 568:
#line 2613 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5988 "conf_parser.c"
    break;

  case 569:
#line 2616 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5996 "conf_parser.c"
    break;

  case 570:
#line 2619 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6004 "conf_parser.c"
    break;

  case 571:
#line 2622 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6012 "conf_parser.c"
    break;

  case 572:
#line 2625 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6020 "conf_parser.c"
    break;

  case 573:
#line 2628 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6028 "conf_parser.c"
    break;

  case 574:
#line 2631 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6036 "conf_parser.c"
    break;

  case 575:
#line 2634 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6044 "conf_parser.c"
    break;

  case 576:
#line 2637 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6052 "conf_parser.c"
    break;

  case 577:
#line 2640 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6060 "conf_parser.c"
    break;

  case 578:
#line 2643 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6068 "conf_parser.c"
    break;

  case 579:
#line 2646 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6076 "conf_parser.c"
    break;

  case 580:
#line 2649 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6084 "conf_parser.c"
    break;

  case 581:
#line 2652 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6092 "conf_parser.c"
    break;

  case 582:
#line 2657 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6100 "conf_parser.c"
    break;

  case 586:
#line 2663 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_BOT;
}
#line 6108 "conf_parser.c"
    break;

  case 587:
#line 2666 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6116 "conf_parser.c"
    break;

  case 588:
#line 2669 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6124 "conf_parser.c"
    break;

  case 589:
#line 2672 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6132 "conf_parser.c"
    break;

  case 590:
#line 2675 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FLOOD;
}
#line 6140 "conf_parser.c"
    break;

  case 591:
#line 2678 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6148 "conf_parser.c"
    break;

  case 592:
#line 2681 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6156 "conf_parser.c"
    break;

  case 593:
#line 2684 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6164 "conf_parser.c"
    break;

  case 594:
#line 2687 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6172 "conf_parser.c"
    break;

  case 595:
#line 2690 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6180 "conf_parser.c"
    break;

  case 596:
#line 2693 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6188 "conf_parser.c"
    break;

  case 597:
#line 2696 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6196 "conf_parser.c"
    break;

  case 598:
#line 2699 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6204 "conf_parser.c"
    break;

  case 599:
#line 2702 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6212 "conf_parser.c"
    break;

  case 600:
#line 2705 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6220 "conf_parser.c"
    break;

  case 601:
#line 2708 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6228 "conf_parser.c"
    break;

  case 602:
#line 2711 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6236 "conf_parser.c"
    break;

  case 603:
#line 2714 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6244 "conf_parser.c"
    break;

  case 604:
#line 2717 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6252 "conf_parser.c"
    break;

  case 605:
#line 2720 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6260 "conf_parser.c"
    break;

  case 606:
#line 2725 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6268 "conf_parser.c"
    break;

  case 607:
#line 2730 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6276 "conf_parser.c"
    break;

  case 608:
#line 2735 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6284 "conf_parser.c"
    break;

  case 609:
#line 2740 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6292 "conf_parser.c"
    break;

  case 629:
#line 2769 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6300 "conf_parser.c"
    break;

  case 630:
#line 2774 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6308 "conf_parser.c"
    break;

  case 631:
#line 2779 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6316 "conf_parser.c"
    break;

  case 632:
#line 2784 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6324 "conf_parser.c"
    break;

  case 633:
#line 2789 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6332 "conf_parser.c"
    break;

  case 634:
#line 2794 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6340 "conf_parser.c"
    break;

  case 635:
#line 2799 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6348 "conf_parser.c"
    break;

  case 636:
#line 2804 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6356 "conf_parser.c"
    break;

  case 637:
#line 2809 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6364 "conf_parser.c"
    break;

  case 638:
#line 2814 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6372 "conf_parser.c"
    break;

  case 639:
#line 2819 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6380 "conf_parser.c"
    break;

  case 640:
#line 2824 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6388 "conf_parser.c"
    break;

  case 641:
#line 2829 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6396 "conf_parser.c"
    break;

  case 642:
#line 2834 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6404 "conf_parser.c"
    break;

  case 643:
#line 2839 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6412 "conf_parser.c"
    break;

  case 657:
#line 2862 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6421 "conf_parser.c"
    break;

  case 658:
#line 2868 "conf_parser.y"
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
#line 6440 "conf_parser.c"
    break;

  case 659:
#line 2884 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6452 "conf_parser.c"
    break;

  case 660:
#line 2893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6461 "conf_parser.c"
    break;

  case 661:
#line 2899 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6470 "conf_parser.c"
    break;

  case 662:
#line 2905 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6479 "conf_parser.c"
    break;

  case 663:
#line 2911 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6491 "conf_parser.c"
    break;

  case 664:
#line 2920 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6500 "conf_parser.c"
    break;

  case 665:
#line 2926 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6509 "conf_parser.c"
    break;


#line 6513 "conf_parser.c"

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
