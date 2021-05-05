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
    SPECIALS_IN_IDENT = 403,
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
#define SPECIALS_IN_IDENT 403
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
#define YYLAST   1243

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  238
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  667
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1313

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
    2704,  2707,  2710,  2713,  2716,  2719,  2722,  2725,  2730,  2735,
    2740,  2745,  2754,  2756,  2756,  2757,  2758,  2759,  2760,  2761,
    2762,  2763,  2764,  2765,  2766,  2767,  2768,  2769,  2770,  2771,
    2772,  2774,  2779,  2784,  2789,  2794,  2799,  2804,  2809,  2814,
    2819,  2824,  2829,  2834,  2839,  2844,  2853,  2855,  2855,  2856,
    2857,  2858,  2859,  2860,  2861,  2862,  2863,  2864,  2865,  2867,
    2873,  2889,  2898,  2904,  2910,  2916,  2925,  2931
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
  "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6", "EMAIL", "ENABLE_EXTBANS",
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "EXPIRATION",
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
  "SPECIALS_IN_IDENT", "SPOOF", "SQUIT", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_M_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL",
  "T_BIND", "T_CALLERID", "T_CCONN", "T_COMMAND", "T_CLUSTER", "T_DEAF",
  "T_DEBUG", "T_DLINE", "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FLOOD",
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
  "general_short_motd", "general_no_oper_flood",
  "general_specials_in_ident", "general_max_targets",
  "general_ping_cookie", "general_disable_auth", "general_throttle_count",
  "general_throttle_time", "general_oper_umodes", "$@25", "umode_oitems",
  "umode_oitem", "general_oper_only_umodes", "$@26", "umode_items",
  "umode_item", "general_min_nonwildcard",
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

#define YYPACT_NINF (-1017)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1017,   849, -1017,  -183,  -193,  -187, -1017, -1017, -1017,  -159,
   -1017,  -157, -1017, -1017, -1017,  -136, -1017, -1017, -1017,  -131,
    -124, -1017,  -117, -1017,  -108, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017,   367,   975,  -102,   -97,   -78,     2,   -77,   396,   -59,
     -53,   -51,   110,   -45,   -40,   -36,   605,   525,   -35,    19,
     -31,    17,   -21,  -206,  -200,   -89,   -19,     3, -1017, -1017,
   -1017, -1017, -1017,   -12,    -7,    -2,    -1,    21,    40,    49,
      66,    70,    76,    77,    80,    85,    91,    95,   186, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017,   866,   460,    57, -1017,    98,
      50, -1017, -1017,    31, -1017,   101,   103,   104,   107,   109,
     112,   127,   131,   136,   139,   141,   143,   152,   154,   155,
     156,   157,   164,   166,   169,   177,   179,   182,   185, -1017,
   -1017,   189,   191,   193,   197,   198,   202,   204,   205,   206,
     210,   218,   219,   220,   225,   232,   233,   240,   241,   242,
      53, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017,   315,    68,   313,
       6,   243,   247,    12, -1017, -1017, -1017,    16,   309,   331,
   -1017,   248,   249,   251,   256,   258,   259,   262,   263,   264,
     306, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017,    59,   266,   268,   269,   272,   273,   274,   278,   282,
     288,   289,   290,   292,   297,   298,   299,   301,    89, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017,   122,   113,   303,     8,
   -1017, -1017, -1017,    74,   190, -1017,   311,    75, -1017, -1017,
      20, -1017,    62,    65,   195,   324, -1017,    54,   314,   275,
     353,   328,   314,   314,   314,   329,   314,   314,   330,   332,
     342,   343,   344, -1017,   345,   340,   347,   348, -1017,   349,
     352,   354,   355,   357,   358,   359,   360,   362,   363,   364,
     236, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017,   356,   369,   370,
     373,   374,   375,   376, -1017,   379,   381,   382,   385,   389,
     390,   391,   392,    11, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017,   393,   395,    38, -1017, -1017, -1017,   401,   403, -1017,
   -1017,   402,   405,    63, -1017, -1017, -1017,   442,   314,   416,
     314,   314,   444,   418,   314,   446,   420,   424,   455,   457,
     314,   434,   435,   437,   440,   443,   314,   445,   447,   451,
     469,   448,   449,   471,   314,   314,   483,   487,   461,   489,
     491,   492,   493,   494,   495,   496,   470,   314,   314,   314,
     498,   473,   475, -1017,   477,   476,   478, -1017,   480,   481,
     482,   484,   485,   267, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017,   490,   497,    24, -1017, -1017, -1017,
     486,   502,   507, -1017,   508, -1017,    14, -1017, -1017, -1017,
   -1017, -1017,   499,   500,   509, -1017,   512,   510,   511,    56,
   -1017, -1017, -1017,   515,   513,   516, -1017,   517,   520, -1017,
     523,   527,   528,   530,   160, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017,   536,   534,   535,   538,
      28, -1017, -1017, -1017, -1017,   518,   524,   314,   501,   556,
     541,   570,   571,   573,   546, -1017, -1017,   479,   549,   579,
     554,   555,   557,   559,   561,   562,   563,   566,   567,   577,
     578,   580,   583,   553, -1017,   568,   552, -1017,    44, -1017,
   -1017, -1017, -1017,   599,   582, -1017,   584,   587,   581,   585,
     588,   593,    55, -1017, -1017, -1017, -1017, -1017,   592,   600,
   -1017,   606,   596, -1017,   607,    60, -1017, -1017, -1017, -1017,
     608,   611,   613, -1017,   616,   310,   619,   622,   623,   625,
     626,   627,   632,   633,   636,   639,   642,   643,   644,   645,
   -1017, -1017,   647,   648,   314,   651,   649,   314,   652,   314,
     594,   656,   658,   660,   314,   661,   661,   650, -1017, -1017,
     664,   -88,   665,   693,   671,   672,   668,   674,   677,   678,
     680,   681,   314,   682,   683,   676, -1017,   684,   686,   685,
   -1017,   687, -1017,   690,   691,   692, -1017,   694,   696,   699,
     701,   702,   703,   706,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   721,   724,   725,   727,   731,   733,   735,
     737,   589,   634,   739,   741,   742,   743,   745,   749,   751,
     752,   753,   754,   755,   756,   757,   759,   760,   761,   764,
     765,   766, -1017, -1017,   695,   719,   767,   732,   768,   770,
     771,   775,   774, -1017,   777,   778,   781, -1017, -1017,   779,
     784,   780,   786,   787, -1017,   788,   789, -1017, -1017,   792,
     793,   794, -1017, -1017,   797,   814,   796,   798,   799,   801,
     802,   820,   803,   804,   805, -1017, -1017,   813,   815,   816,
     812, -1017,   817,   818,   819,   821,   825,   826,   827,   828,
     832, -1017,   834,   835,   836,   837,   838,   839,   840,   841,
     842,   843,   844,   845,   846,   847,   848,   850, -1017, -1017,
     822,   851,   852, -1017,   853, -1017,   108, -1017,   857,   858,
     859,   860,   861, -1017,   862, -1017, -1017,   865,   856,   867,
     864, -1017, -1017, -1017, -1017, -1017,   314,   314,   314,   314,
     314,   314,   314, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,   868,
     869,   870,   -37,   871,   872,   873,   874,   875,   876,   877,
     878,   879,    82,   880,   881, -1017,   882,   883,   884,   885,
     886,   887,   888,    -3,   889,   890,   891,   892,   893,   894,
     895,   896, -1017,   897,   898, -1017, -1017,   899,   900, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017,  -209, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
    -208, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017,   901,   902,   351,   903,   904,   905,   906,   907, -1017,
     908,   909, -1017,   910,   911,   377,   829,   736, -1017, -1017,
   -1017, -1017,   912,   913, -1017,   914,   915,   506,   916,   917,
     669,   918,   919,   920,   921, -1017,   922,   923,   924, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017,   925,   730, -1017, -1017,   926,
     863,   927, -1017,    29, -1017, -1017, -1017, -1017,   928,   929,
     931,   932, -1017, -1017,   933,   740,   934, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
    -199, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017,   661,   661,   661, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017,  -198, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017,   589, -1017,   634, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017,  -192, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017,  -190, -1017,   936,   786,   937, -1017, -1017, -1017,
   -1017, -1017, -1017,   855, -1017,   935,   938, -1017, -1017,   939,
     940, -1017, -1017,   941, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017,  -184, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017,  -149, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017,  -135, -1017, -1017,   943,  -176,   944,   942, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017,   -70, -1017, -1017, -1017,   -37,
   -1017, -1017, -1017, -1017,    -3, -1017, -1017, -1017,   351, -1017,
     377, -1017, -1017, -1017,   950,   966,   952,  1026,  1037,  1039,
   -1017,   506, -1017,   669, -1017,   730,   948,   949,   951,   244,
   -1017, -1017,   740, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017,   -58, -1017, -1017,
   -1017,   244, -1017
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
      93,    92,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   614,
     629,   628,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   615,   616,   626,   627,     0,     0,     0,   457,     0,
       0,   455,   456,     0,   516,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   582,
     556,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   470,   471,   472,   514,   478,   515,   509,   510,   511,
     512,   482,   473,   474,   475,   476,   477,   479,   480,   481,
     483,   484,   513,   488,   489,   490,   491,   487,   486,   492,
     499,   500,   493,   494,   495,   485,   497,   507,   508,   505,
     506,   498,   496,   503,   504,   501,   502,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     658,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   648,   649,   650,   651,   652,   653,   654,   656,   655,
     657,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      67,    65,    63,    68,    69,    70,    64,    55,    66,    57,
      58,    59,    60,    61,    62,    56,     0,     0,     0,     0,
     122,   123,   124,     0,     0,   346,     0,     0,   344,   345,
       0,    94,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   613,     0,     0,     0,     0,   266,     0,
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
       0,     0,     0,     0,     0,   647,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,   380,     0,   375,
     376,   377,   125,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   113,   112,   114,     0,     0,
     343,     0,     0,   358,     0,     0,   351,   352,   353,   354,
       0,     0,     0,    88,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     612,   251,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,   646,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,   378,
       0,     0,     0,   374,     0,   120,     0,   115,     0,     0,
       0,     0,     0,   109,     0,   342,   355,     0,     0,     0,
       0,   350,    97,    96,    95,   644,    28,    28,    28,    28,
      28,    28,    28,    30,    29,   645,   632,   631,   633,   634,
     635,   636,   637,   638,   639,   642,   643,   640,   641,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   395,     0,     0,   445,   458,     0,     0,   460,
     528,   532,   517,   518,   545,   521,   610,   611,   553,   522,
     523,   527,   535,   526,   524,   525,   531,   519,   530,   529,
     551,   608,   609,   549,   586,   607,   592,   593,   594,   603,
     587,   588,   589,   598,   606,   590,   600,   604,   595,   605,
     596,   599,   591,   602,   597,   601,     0,   585,   560,   581,
     565,   566,   567,   577,   561,   562,   563,   572,   580,   564,
     574,   578,   569,   579,   570,   573,   568,   576,   571,   575,
       0,   559,   546,   544,   547,   552,   548,   550,   537,   543,
     542,   538,   539,   540,   541,   554,   555,   534,   533,   536,
     520,     0,     0,     0,     0,     0,     0,     0,     0,   299,
       0,     0,   436,     0,     0,     0,   294,   290,   293,   273,
      50,    51,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,     0,     0,     0,   332,
     662,   659,   660,   661,   666,   665,   667,   663,   664,    84,
      81,    87,    80,    85,    86,    79,    83,    82,    73,    72,
      75,    76,    74,    77,    78,     0,     0,   373,   126,     0,
       0,     0,   138,     0,   130,   131,   133,   132,     0,     0,
       0,     0,   108,   347,     0,     0,     0,   349,    31,    32,
      33,    34,    35,    36,    37,   261,   262,   256,   271,   270,
       0,   269,   257,   265,   258,   264,   252,   263,   255,   254,
     253,    38,    38,    38,    40,    39,   259,   260,   419,   422,
     423,   433,   430,   415,   431,   428,   429,     0,   427,   432,
     414,   421,   418,   417,   416,   420,   434,   451,   452,   466,
     467,   583,     0,   557,     0,   313,   314,   323,   319,   320,
     322,   327,   324,   325,   326,   321,     0,   318,   312,   330,
     329,   328,   311,   443,   442,   297,   296,   281,   282,   279,
     280,   278,     0,   277,     0,     0,     0,   105,   106,   172,
     169,   219,   231,   206,   215,     0,   204,   209,   225,     0,
     218,   223,   229,   208,   211,   220,   222,   226,   216,   224,
     212,   230,   214,   221,   210,   213,     0,   202,   165,   167,
     177,   198,   182,   183,   184,   194,   178,   179,   180,   189,
     197,   181,   191,   195,   186,   196,   187,   190,   185,   193,
     188,   192,     0,   176,   170,   171,   166,   168,   341,   339,
     340,   379,   384,   390,   393,   386,   392,   387,   391,   389,
     385,   388,     0,   383,   134,     0,     0,     0,     0,   129,
     117,   116,   118,   119,   356,   362,   368,   371,   364,   370,
     365,   369,   367,   363,   366,     0,   361,   357,   267,     0,
      41,    42,    43,   425,     0,   584,   558,   316,     0,   275,
       0,   295,   292,   291,     0,     0,     0,     0,     0,     0,
     200,     0,   174,     0,   381,     0,     0,     0,     0,     0,
     128,   359,     0,   268,   426,   317,   276,   205,   228,   203,
     227,   217,   207,   201,   175,   382,   135,   137,   136,   148,
     147,   143,   145,   149,   146,   142,   144,     0,   141,   360,
     139,     0,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1017, -1017, -1017,  -251,  -306, -1016,  -635, -1017, -1017,   504,
   -1017, -1017, -1017, -1017,   930, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017,   635, -1017, -1017, -1017, -1017, -1017, -1017,
     688, -1017, -1017, -1017, -1017, -1017,   602, -1017, -1017, -1017,
   -1017, -1017, -1017,   945, -1017, -1017, -1017, -1017,   128, -1017,
   -1017, -1017, -1017, -1017,  -129, -1017, -1017, -1017,   675, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
     -87, -1017, -1017, -1017,   -86, -1017, -1017, -1017,   854, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017,   -61, -1017, -1017, -1017,
   -1017, -1017,   -69, -1017,   704, -1017, -1017, -1017,    47, -1017,
   -1017, -1017, -1017, -1017,   734, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017,   -65, -1017, -1017, -1017, -1017, -1017, -1017,   666,
   -1017, -1017, -1017, -1017, -1017,   946, -1017, -1017, -1017, -1017,
     604, -1017, -1017, -1017, -1017, -1017,   -82, -1017, -1017, -1017,
     637, -1017, -1017, -1017, -1017,   -80, -1017, -1017, -1017,   830,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017,   -52, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017,   728, -1017, -1017, -1017, -1017, -1017,   808, -1017, -1017,
   -1017, -1017,  1086, -1017, -1017, -1017, -1017,   806, -1017, -1017,
   -1017, -1017,  1038, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017,    93, -1017, -1017, -1017,    99,
   -1017, -1017, -1017, -1017, -1017, -1017,  1112, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017,   972, -1017, -1017, -1017, -1017, -1017,
   -1017, -1017, -1017, -1017
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   823,   824,  1084,  1085,    27,   223,   224,
     225,   226,    28,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    29,    77,    78,    79,    80,    81,    30,    63,   499,
     500,   501,   502,    31,    70,   582,   583,   584,   585,   586,
     587,    32,   289,   290,   291,   292,   293,  1043,  1044,  1045,
    1046,  1047,  1227,  1307,  1308,    33,    64,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   749,  1202,
    1203,   525,   746,  1176,  1177,    34,    53,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   625,  1070,  1071,    35,    61,   485,
     731,  1142,  1143,   486,   487,   488,  1146,   987,   988,   489,
     490,    36,    59,   463,   464,   465,   466,   467,   468,   469,
     716,  1126,  1127,   470,   471,   472,    37,    65,   530,   531,
     532,   533,   534,    38,   297,   298,   299,    39,    72,   595,
     596,   597,   598,   599,   808,  1245,  1246,    40,    68,   568,
     569,   570,   571,   791,  1222,  1223,    41,    54,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     646,  1097,  1098,   385,   386,   387,   388,   389,    42,    60,
     476,   477,   478,   479,    43,    55,   393,   394,   395,   396,
      44,   120,   121,   122,    45,    57,   403,   404,   405,   406,
      46,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   432,   950,   951,   212,   431,   926,   927,
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
     853,   854,   606,   118,    73,  1095,   610,   611,   612,   287,
     614,   615,   357,   220,   358,   480,   359,   496,   295,  1068,
     287,   591,  1277,  1111,  1113,   473,   301,  1112,  1114,   526,
    1039,   360,   400,  1248,  1253,   302,    74,  1249,  1254,   390,
    1257,    51,  1259,    75,  1258,   565,  1260,    52,  1270,    49,
      50,   118,  1271,   361,   124,   852,   577,   496,   390,   125,
     126,   591,   127,   128,   400,  1250,  1251,  1252,   129,   473,
     119,   362,   527,   363,   481,    56,   295,    58,   130,   131,
     132,   364,   482,  1272,   483,   857,   858,  1273,   133,  1069,
     251,   134,   135,   365,  1081,  1082,  1083,  1274,    62,   136,
     497,  1275,   668,    66,   670,   671,   391,    76,   674,  1039,
      67,   220,   528,   221,   680,   366,   137,    69,   119,   252,
     686,   296,   253,   565,   592,   391,    71,   138,   694,   695,
     139,   140,   115,  1040,   222,   401,   367,   116,   141,   484,
     497,   707,   708,   709,   142,   143,   303,   144,   566,   145,
     254,   474,   146,   147,   368,   529,   117,   123,   402,   578,
     255,   503,  1281,   148,   592,   392,  1282,   401,   149,   150,
     369,   151,   152,   153,  1310,   217,   154,  -127,  1311,   296,
     504,   218,   256,   219,   392,   498,   257,    82,  -127,   227,
     402,   577,  1096,   258,   228,   474,   259,   260,   229,   286,
     155,   156,   505,   294,   157,   158,   159,   160,   161,   162,
     163,   221,  1040,   300,    83,    84,   304,   579,   370,  1041,
     371,   372,    85,   307,   261,   498,   566,    86,   308,   288,
     506,   764,   222,   309,   310,   580,   305,   324,   491,   593,
     288,   574,   594,   576,   655,   494,   475,   733,  1042,   581,
      87,    88,    89,    90,   325,   326,   311,   726,   164,   165,
     327,   760,  1228,   567,   507,    91,    92,    93,   454,   166,
     167,   659,    94,    95,    96,   312,    97,   792,   168,   593,
     169,   508,   594,   398,   313,   604,   452,   455,   802,   741,
     475,   546,   600,   810,   578,   601,   665,   262,  1041,   263,
     264,   314,   265,   266,   267,   315,   328,   230,   589,   456,
     503,   316,   317,   852,   480,   318,   454,  1299,   841,  1300,
     319,   844,   563,   846,   329,   330,   320,  1042,   851,   504,
     321,   331,   526,   397,   332,   455,   407,   457,   408,   409,
     333,   567,   410,   231,   411,   572,   869,   412,   334,   335,
     336,   505,   579,   232,   233,   234,   509,   456,   235,   236,
     337,  1301,   413,   237,   238,   239,   414,  1117,    73,   510,
     580,   415,   511,   481,   416,   527,   417,  1302,   418,   506,
     338,   482,   512,   483,   581,   457,   513,   419,   458,   420,
     421,   422,   423,   754,  1118,   459,   460,   124,  1137,   424,
      74,   425,   125,   126,   426,   127,   128,    75,  1138,  1303,
    1304,   129,   427,   507,   428,   528,   461,   429,   339,   322,
     430,   130,   131,   132,   433,   602,   434,  1119,   435,  1139,
     508,   133,   436,   437,   134,   135,   458,   438,   484,   439,
     440,   441,   136,   459,   460,   442,   816,   817,   818,   819,
     820,   821,   822,   443,   444,   445,  1120,  1121,   529,   137,
     446,   357,  1122,   358,   461,   359,  1305,   447,   448,   637,
     138,    76,  1306,   139,   140,   449,   450,   451,   492,   607,
     360,   141,   493,   535,   536,  1123,   537,   142,   143,   462,
     144,   538,   145,   539,   540,   146,   147,   541,   542,   543,
     722,   547,   361,   548,   549,   509,   148,   550,   551,   552,
    1151,   149,   150,   553,   151,   152,   153,   554,   510,   154,
     362,   511,   363,   555,   556,   557,   251,   558,  1152,  1153,
     364,   512,   559,   560,   561,   513,   562,   462,   573,   544,
    1154,   605,   365,   155,   156,   605,   588,   157,   158,   159,
     160,   161,   162,   163,  1124,   252,   603,   608,   253,   609,
     613,   616,  1140,   617,   366,  1058,  1059,  1060,  1061,  1062,
    1063,  1064,  1141,   618,   619,   622,   620,   621,  1155,  1156,
    1125,  1157,   623,   624,   626,   367,   254,   627,   639,   628,
     629,  1278,   630,   631,   632,   633,   255,   634,   635,   636,
     904,   164,   165,   368,   640,   641,   230,  1158,   642,   643,
     644,   645,   166,   167,   647,  1159,   648,   649,   256,   369,
     650,   168,   257,   169,   651,   652,   653,   654,   657,   258,
     658,   661,   259,   260,   905,   662,  1160,   663,  1161,  1162,
     664,   906,   231,   907,   908,   928,   667,   669,   672,   673,
     675,   676,   232,   233,   234,   677,  1163,   235,   236,   678,
     261,   679,   237,   238,   239,   681,   682,   370,   683,   371,
     372,   684,  1164,   690,   685,   693,   687,  1165,   688,   929,
    1180,  1166,   689,   691,   692,  1167,   930,   696,   931,   932,
    1168,   697,   698,   699,  1169,   700,   701,   702,   703,   704,
     705,   706,   710,  1170,   711,  1171,  1172,   712,  1173,   713,
     772,   714,   306,   715,  1181,   717,   718,   719,   728,   720,
     721,  1182,   762,  1183,  1184,   724,  1174,   495,   763,   735,
     736,   765,   725,   262,  1175,   263,   264,   729,   265,   266,
     267,   737,   730,   732,   738,   739,   740,   743,   744,   909,
     910,   745,   747,   911,   912,   748,   913,   914,   750,   915,
     766,   916,   751,   752,   917,   753,   918,   919,   756,   757,
     758,   767,   920,   759,   768,   769,   921,   770,   771,   773,
     922,   923,   924,   774,   775,   788,   776,   790,   777,   778,
     925,   779,   780,   781,   933,   934,   782,   783,   935,   936,
     789,   937,   938,   794,   939,  1212,   940,   784,   785,   941,
     786,   942,   943,   787,   795,  1235,   798,   944,   796,   797,
     799,   945,   804,   800,   847,   946,   947,   948,   801,  1185,
    1186,   807,   805,  1187,  1188,   949,  1189,  1190,   806,  1191,
     812,  1192,   809,   813,  1193,   814,  1194,  1195,   815,     2,
       3,   825,  1196,     4,   826,   827,  1197,   828,   829,   830,
    1198,  1199,  1200,  1213,   831,   832,     5,   324,   833,     6,
    1201,   834,     7,  1236,   835,   836,   837,   838,   839,   840,
     843,     8,   855,   845,   325,   326,   842,   848,  1214,   849,
     327,   850,   852,     9,   856,   859,  1215,   860,  1237,    10,
      11,   861,   862,   863,   864,  1216,  1238,   865,   872,   866,
     867,   868,   870,   871,   873,  1239,   874,   875,    12,   876,
     877,   878,    13,   972,   879,   971,   880,  1217,   881,  1218,
    1219,   882,    14,   883,   884,   885,   328,  1240,   886,  1241,
    1242,   887,   888,   889,   890,   891,   892,   893,   894,   895,
    1220,    15,    16,   896,   329,   330,   897,   898,  1221,   899,
    1243,   331,   974,   900,   332,   901,    17,   902,  1244,   903,
     333,   952,  1145,   953,   954,   955,    82,   956,   334,   335,
     336,   957,    18,   958,   959,   960,   961,   962,   963,   964,
     337,   965,   966,   967,    19,    20,   968,   969,   970,   975,
     976,   977,   973,    83,    84,   978,   979,   980,   981,   983,
     338,    85,    21,   982,   984,   985,    86,   986,   996,   989,
     990,   991,   992,   993,  1002,    22,   994,   995,   998,   999,
      23,   997,  1001,  1003,  1004,    24,  1000,  1005,    25,    87,
      88,    89,    90,  1006,  1009,  1007,  1008,  1144,   339,  1010,
    1011,  1012,  1035,  1013,    91,    92,    93,  1014,  1015,  1016,
    1017,    94,    95,    96,  1018,    97,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1287,  1034,  1289,  1037,  1038,  1036,  1048,  1049,  1050,
    1051,  1055,  1264,  1052,  1053,  1054,  1057,  1056,  1225,  1288,
    1065,  1066,  1067,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1115,  1116,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1147,  1148,  1149,  1150,  1178,  1179,
    1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1224,  1290,
    1230,  1231,  1226,  1232,  1233,  1234,  1247,  1261,  1291,  1263,
    1292,  1229,  1265,  1276,  1280,  1266,  1267,  1268,  1269,  1279,
    1296,  1297,  1312,  1298,   803,  1293,  1294,   742,  1283,   755,
     734,  1286,  1262,  1285,   638,  1295,   761,   723,   564,   811,
    1309,   660,  1284,   656,   727,   793,   399,  1256,   453,   666,
     323,  1255,   545,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   575,     0,     0,     0,     0,     0,
       0,     0,     0,   590
};

static const yytype_int16 yycheck[] =
{
     635,   636,   308,     1,     1,     8,   312,   313,   314,     1,
     316,   317,     1,     1,     3,     1,     5,     1,     1,    56,
       1,     1,   198,   232,   232,     1,   232,   236,   236,     1,
       1,    20,     1,   232,   232,   235,    33,   236,   236,     1,
     232,   234,   232,    40,   236,     1,   236,   234,   232,   232,
     233,     1,   236,    42,     1,   231,     1,     1,     1,     6,
       7,     1,     9,    10,     1,  1081,  1082,  1083,    15,     1,
      68,    60,    44,    62,    60,   234,     1,   234,    25,    26,
      27,    70,    68,   232,    70,   173,   174,   236,    35,   126,
       1,    38,    39,    82,    12,    13,    14,   232,   234,    46,
      84,   236,   408,   234,   410,   411,    68,   104,   414,     1,
     234,     1,    84,   101,   420,   104,    63,   234,    68,    30,
     426,   104,    33,     1,   104,    68,   234,    74,   434,   435,
      77,    78,   234,   104,   122,   104,   125,   234,    85,   125,
      84,   447,   448,   449,    91,    92,   235,    94,   104,    96,
      61,   127,    99,   100,   143,   127,   234,   234,   127,   104,
      71,     1,   232,   110,   104,   127,   236,   104,   115,   116,
     159,   118,   119,   120,   232,   234,   123,   169,   236,   104,
      20,   234,    93,   234,   127,   169,    97,     1,   169,   234,
     127,     1,   195,   104,   234,   127,   107,   108,   234,   234,
     147,   148,    42,   234,   151,   152,   153,   154,   155,   156,
     157,   101,   104,   234,    28,    29,   235,   162,   207,   190,
     209,   210,    36,   235,   135,   169,   104,    41,   235,   221,
      70,   537,   122,   235,   235,   180,   233,     1,   232,   219,
     221,   233,   222,   169,   233,   233,   222,   233,   219,   194,
      64,    65,    66,    67,    18,    19,   235,   233,   205,   206,
      24,   233,   233,   219,   104,    79,    80,    81,     1,   216,
     217,   233,    86,    87,    88,   235,    90,   233,   225,   219,
     227,   121,   222,   233,   235,   231,   233,    20,   233,   233,
     222,   232,   230,   233,   104,   230,   233,   208,   190,   210,
     211,   235,   213,   214,   215,   235,    70,     1,   233,    42,
       1,   235,   235,   231,     1,   235,     1,    73,   624,    75,
     235,   627,   233,   629,    88,    89,   235,   219,   634,    20,
     235,    95,     1,   235,    98,    20,   235,    70,   235,   235,
     104,   219,   235,    37,   235,   232,   652,   235,   112,   113,
     114,    42,   162,    47,    48,    49,   196,    42,    52,    53,
     124,   117,   235,    57,    58,    59,   235,    16,     1,   209,
     180,   235,   212,    60,   235,    44,   235,   133,   235,    70,
     144,    68,   222,    70,   194,    70,   226,   235,   121,   235,
     235,   235,   235,   233,    43,   128,   129,     1,    21,   235,
      33,   235,     6,     7,   235,     9,    10,    40,    31,   165,
     166,    15,   235,   104,   235,    84,   149,   235,   182,   233,
     235,    25,    26,    27,   235,   230,   235,    76,   235,    52,
     121,    35,   235,   235,    38,    39,   121,   235,   125,   235,
     235,   235,    46,   128,   129,   235,   136,   137,   138,   139,
     140,   141,   142,   235,   235,   235,   105,   106,   127,    63,
     235,     1,   111,     3,   149,     5,   222,   235,   235,   233,
      74,   104,   228,    77,    78,   235,   235,   235,   235,   204,
      20,    85,   235,   235,   235,   134,   235,    91,    92,   222,
      94,   235,    96,   235,   235,    99,   100,   235,   235,   235,
     233,   235,    42,   235,   235,   196,   110,   235,   235,   235,
       4,   115,   116,   235,   118,   119,   120,   235,   209,   123,
      60,   212,    62,   235,   235,   235,     1,   235,    22,    23,
      70,   222,   235,   235,   235,   226,   235,   222,   235,   233,
      34,   231,    82,   147,   148,   231,   235,   151,   152,   153,
     154,   155,   156,   157,   203,    30,   232,   204,    33,   231,
     231,   231,   185,   231,   104,   816,   817,   818,   819,   820,
     821,   822,   195,   231,   231,   235,   232,   232,    72,    73,
     229,    75,   235,   235,   235,   125,    61,   235,   232,   235,
     235,  1226,   235,   235,   235,   235,    71,   235,   235,   235,
      11,   205,   206,   143,   235,   235,     1,   101,   235,   235,
     235,   235,   216,   217,   235,   109,   235,   235,    93,   159,
     235,   225,    97,   227,   235,   235,   235,   235,   235,   104,
     235,   230,   107,   108,    45,   232,   130,   235,   132,   133,
     235,    52,    37,    54,    55,    11,   204,   231,   204,   231,
     204,   231,    47,    48,    49,   231,   150,    52,    53,   204,
     135,   204,    57,    58,    59,   231,   231,   207,   231,   209,
     210,   231,   166,   204,   231,   204,   231,   171,   231,    45,
      11,   175,   231,   235,   235,   179,    52,   204,    54,    55,
     184,   204,   231,   204,   188,   204,   204,   204,   204,   204,
     204,   231,   204,   197,   231,   199,   200,   232,   202,   232,
     231,   235,    77,   235,    45,   235,   235,   235,   232,   235,
     235,    52,   204,    54,    55,   235,   220,   223,   204,   230,
     230,   230,   235,   208,   228,   210,   211,   235,   213,   214,
     215,   232,   235,   235,   232,   235,   235,   232,   235,   160,
     161,   235,   235,   164,   165,   235,   167,   168,   235,   170,
     204,   172,   235,   235,   175,   235,   177,   178,   232,   235,
     235,   230,   183,   235,   204,   204,   187,   204,   232,   230,
     191,   192,   193,   204,   230,   232,   231,   235,   231,   230,
     201,   230,   230,   230,   160,   161,   230,   230,   164,   165,
     232,   167,   168,   204,   170,    75,   172,   230,   230,   175,
     230,   177,   178,   230,   232,    75,   235,   183,   234,   232,
     235,   187,   230,   235,   230,   191,   192,   193,   235,   160,
     161,   235,   232,   164,   165,   201,   167,   168,   232,   170,
     232,   172,   235,   232,   175,   232,   177,   178,   232,     0,
       1,   232,   183,     4,   232,   232,   187,   232,   232,   232,
     191,   192,   193,   133,   232,   232,    17,     1,   232,    20,
     201,   232,    23,   133,   232,   232,   232,   232,   231,   231,
     231,    32,   232,   231,    18,    19,   235,   231,   158,   231,
      24,   231,   231,    44,   230,   230,   166,   204,   158,    50,
      51,   230,   230,   235,   230,   175,   166,   230,   232,   231,
     230,   230,   230,   230,   230,   175,   230,   232,    69,   232,
     230,   230,    73,   204,   232,   230,   232,   197,   232,   199,
     200,   232,    83,   232,   232,   232,    70,   197,   232,   199,
     200,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     220,   102,   103,   232,    88,    89,   232,   232,   228,   232,
     220,    95,   230,   232,    98,   232,   117,   232,   228,   232,
     104,   232,   236,   232,   232,   232,     1,   232,   112,   113,
     114,   232,   133,   232,   232,   232,   232,   232,   232,   232,
     124,   232,   232,   232,   145,   146,   232,   232,   232,   231,
     230,   230,   235,    28,    29,   230,   232,   230,   230,   230,
     144,    36,   163,   232,   230,   235,    41,   231,   204,   232,
     232,   232,   230,   230,   204,   176,   232,   230,   230,   230,
     181,   235,   230,   230,   230,   186,   235,   232,   189,    64,
      65,    66,    67,   230,   232,   230,   230,   218,   182,   232,
     232,   232,   230,   232,    79,    80,    81,   232,   232,   232,
     232,    86,    87,    88,   232,    90,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   131,   232,   131,   232,   232,   235,   230,   230,   230,
     230,   235,   237,   232,   232,   230,   232,   230,   235,   133,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   133,
     232,   232,   235,   232,   232,   232,   232,   231,   131,   232,
     131,  1043,   237,   230,   232,   237,   237,   237,   237,   235,
     232,   232,  1311,   232,   582,  1271,  1273,   499,  1249,   514,
     486,  1260,  1145,  1258,   340,  1275,   530,   463,   268,   595,
    1282,   393,  1254,   373,   476,   568,   120,  1114,   170,   403,
      98,  1112,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   289,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   297
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   239,     0,     1,     4,    17,    20,    23,    32,    44,
      50,    51,    69,    73,    83,   102,   103,   117,   133,   145,
     146,   163,   176,   181,   186,   189,   240,   245,   250,   269,
     275,   281,   289,   303,   323,   345,   359,   374,   381,   385,
     395,   404,   426,   432,   438,   442,   448,   502,   520,   232,
     233,   234,   234,   324,   405,   433,   234,   443,   234,   360,
     427,   346,   234,   276,   304,   375,   234,   234,   396,   234,
     282,   234,   386,     1,    33,    40,   104,   270,   271,   272,
     273,   274,     1,    28,    29,    36,    41,    64,    65,    66,
      67,    79,    80,    81,    86,    87,    88,    90,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   234,   234,   234,     1,    68,
     439,   440,   441,   234,     1,     6,     7,     9,    10,    15,
      25,    26,    27,    35,    38,    39,    46,    63,    74,    77,
      78,    85,    91,    92,    94,    96,    99,   100,   110,   115,
     116,   118,   119,   120,   123,   147,   148,   151,   152,   153,
     154,   155,   156,   157,   205,   206,   216,   217,   225,   227,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   494,   498,   499,   500,   501,   234,   234,   234,
       1,   101,   122,   246,   247,   248,   249,   234,   234,   234,
       1,    37,    47,    48,    49,    52,    53,    57,    58,    59,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,     1,    30,    33,    61,    71,    93,    97,   104,   107,
     108,   135,   208,   210,   211,   213,   214,   215,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   234,     1,   221,   290,
     291,   292,   293,   294,   234,     1,   104,   382,   383,   384,
     234,   232,   235,   235,   235,   233,   271,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   233,   504,     1,    18,    19,    24,    70,    88,
      89,    95,    98,   104,   112,   113,   114,   124,   144,   182,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,     1,     3,     5,
      20,    42,    60,    62,    70,    82,   104,   125,   143,   159,
     207,   209,   210,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   421,   422,   423,   424,   425,
       1,    68,   127,   434,   435,   436,   437,   235,   233,   440,
       1,   104,   127,   444,   445,   446,   447,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   495,   491,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   233,   450,     1,    20,    42,    70,   121,   128,
     129,   149,   222,   361,   362,   363,   364,   365,   366,   367,
     371,   372,   373,     1,   127,   222,   428,   429,   430,   431,
       1,    60,    68,    70,   125,   347,   351,   352,   353,   357,
     358,   232,   235,   235,   233,   247,     1,    84,   169,   277,
     278,   279,   280,     1,    20,    42,    70,   104,   121,   196,
     209,   212,   222,   226,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   319,     1,    44,    84,   127,
     376,   377,   378,   379,   380,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   233,   522,   232,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   233,   252,     1,   104,   219,   397,   398,
     399,   400,   232,   235,   233,   291,   169,     1,   104,   162,
     180,   194,   283,   284,   285,   286,   287,   288,   235,   233,
     383,     1,   104,   219,   222,   387,   388,   389,   390,   391,
     230,   230,   230,   232,   231,   231,   242,   204,   204,   231,
     242,   242,   242,   231,   242,   242,   231,   231,   231,   231,
     232,   232,   235,   235,   235,   342,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   233,   326,   232,
     235,   235,   235,   235,   235,   235,   418,   235,   235,   235,
     235,   235,   235,   235,   235,   233,   407,   235,   235,   233,
     435,   230,   232,   235,   235,   233,   445,   204,   242,   231,
     242,   242,   204,   231,   242,   204,   231,   231,   204,   204,
     242,   231,   231,   231,   231,   231,   242,   231,   231,   231,
     204,   235,   235,   204,   242,   242,   204,   204,   231,   204,
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
     233,   388,   232,   232,   232,   232,   136,   137,   138,   139,
     140,   141,   142,   241,   242,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   231,
     231,   242,   235,   231,   242,   231,   242,   230,   231,   231,
     231,   242,   231,   244,   244,   232,   230,   173,   174,   230,
     204,   230,   230,   235,   230,   230,   231,   230,   230,   242,
     230,   230,   232,   230,   230,   232,   232,   230,   230,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,    11,    45,    52,    54,    55,   160,
     161,   164,   165,   167,   168,   170,   172,   175,   177,   178,
     183,   187,   191,   192,   193,   201,   496,   497,    11,    45,
      52,    54,    55,   160,   161,   164,   165,   167,   168,   170,
     172,   175,   177,   178,   183,   187,   191,   192,   193,   201,
     492,   493,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   230,   204,   235,   230,   231,   230,   230,   230,   232,
     230,   230,   232,   230,   230,   235,   231,   355,   356,   232,
     232,   232,   230,   230,   232,   230,   204,   235,   230,   230,
     235,   230,   204,   230,   230,   232,   230,   230,   230,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   230,   235,   232,   232,     1,
     104,   190,   219,   295,   296,   297,   298,   299,   230,   230,
     230,   230,   232,   232,   230,   235,   230,   232,   241,   241,
     241,   241,   241,   241,   241,   232,   232,   232,    56,   126,
     343,   344,   232,   232,   232,   232,   232,   232,   232,   232,
     232,    12,    13,    14,   243,   244,   232,   232,   232,   232,
     232,   232,   232,   232,   232,     8,   195,   419,   420,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   236,   232,   236,   232,   232,    16,    43,    76,
     105,   106,   111,   134,   203,   229,   369,   370,   232,   232,
     232,   232,   232,   232,   232,   232,   232,    21,    31,    52,
     185,   195,   349,   350,   218,   236,   354,   232,   232,   232,
     232,     4,    22,    23,    34,    72,    73,    75,   101,   109,
     130,   132,   133,   150,   166,   171,   175,   179,   184,   188,
     197,   199,   200,   202,   220,   228,   321,   322,   232,   232,
      11,    45,    52,    54,    55,   160,   161,   164,   165,   167,
     168,   170,   172,   175,   177,   178,   183,   187,   191,   192,
     193,   201,   317,   318,   232,   232,   232,   232,   232,   232,
     232,   232,    75,   133,   158,   166,   175,   197,   199,   200,
     220,   228,   402,   403,   232,   235,   235,   300,   233,   296,
     232,   232,   232,   232,   232,    75,   133,   158,   166,   175,
     197,   199,   200,   220,   228,   393,   394,   232,   232,   236,
     243,   243,   243,   232,   236,   497,   493,   232,   236,   232,
     236,   231,   356,   232,   237,   237,   237,   237,   237,   237,
     232,   236,   232,   236,   232,   236,   230,   198,   244,   235,
     232,   232,   236,   344,   420,   370,   350,   131,   133,   131,
     133,   131,   131,   322,   318,   403,   232,   232,   232,    73,
      75,   117,   133,   165,   166,   222,   228,   301,   302,   394,
     232,   236,   302
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
     497,   497,   497,   497,   497,   497,   497,   497,   498,   499,
     500,   501,   502,   503,   503,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   521,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4
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
#line 2942 "conf_parser.c"
    break;

  case 30:
#line 398 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2948 "conf_parser.c"
    break;

  case 31:
#line 399 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2954 "conf_parser.c"
    break;

  case 32:
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2960 "conf_parser.c"
    break;

  case 33:
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2966 "conf_parser.c"
    break;

  case 34:
#line 402 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2972 "conf_parser.c"
    break;

  case 35:
#line 403 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2978 "conf_parser.c"
    break;

  case 36:
#line 404 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2984 "conf_parser.c"
    break;

  case 37:
#line 405 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2990 "conf_parser.c"
    break;

  case 38:
#line 408 "conf_parser.y"
            { (yyval.number) = 0; }
#line 2996 "conf_parser.c"
    break;

  case 40:
#line 409 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3002 "conf_parser.c"
    break;

  case 41:
#line 410 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3008 "conf_parser.c"
    break;

  case 42:
#line 411 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3014 "conf_parser.c"
    break;

  case 43:
#line 412 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3020 "conf_parser.c"
    break;

  case 50:
#line 425 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 3029 "conf_parser.c"
    break;

  case 51:
#line 431 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 3038 "conf_parser.c"
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
#line 3050 "conf_parser.c"
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
#line 3062 "conf_parser.c"
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
#line 3074 "conf_parser.c"
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
#line 3086 "conf_parser.c"
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
#line 3098 "conf_parser.c"
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
#line 3110 "conf_parser.c"
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
#line 3122 "conf_parser.c"
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
#line 3140 "conf_parser.c"
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
#line 3158 "conf_parser.c"
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
#line 3171 "conf_parser.c"
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
#line 3188 "conf_parser.c"
    break;

  case 83:
#line 580 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = xstrdup(yylval.string);
}
#line 3200 "conf_parser.c"
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
#line 3226 "conf_parser.c"
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
#line 3252 "conf_parser.c"
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
#line 3278 "conf_parser.c"
    break;

  case 87:
#line 658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3287 "conf_parser.c"
    break;

  case 95:
#line 676 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3299 "conf_parser.c"
    break;

  case 96:
#line 685 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3311 "conf_parser.c"
    break;

  case 97:
#line 694 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3323 "conf_parser.c"
    break;

  case 98:
#line 707 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3332 "conf_parser.c"
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
#line 3349 "conf_parser.c"
    break;

  case 105:
#line 728 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3358 "conf_parser.c"
    break;

  case 106:
#line 734 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3367 "conf_parser.c"
    break;

  case 107:
#line 744 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3376 "conf_parser.c"
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
#line 3394 "conf_parser.c"
    break;

  case 116:
#line 766 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3403 "conf_parser.c"
    break;

  case 117:
#line 772 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3412 "conf_parser.c"
    break;

  case 118:
#line 778 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3421 "conf_parser.c"
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
#line 3442 "conf_parser.c"
    break;

  case 126:
#line 812 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3451 "conf_parser.c"
    break;

  case 127:
#line 818 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3460 "conf_parser.c"
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
#line 3473 "conf_parser.c"
    break;

  case 135:
#line 838 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3484 "conf_parser.c"
    break;

  case 136:
#line 846 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3492 "conf_parser.c"
    break;

  case 137:
#line 849 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3500 "conf_parser.c"
    break;

  case 138:
#line 854 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3509 "conf_parser.c"
    break;

  case 142:
#line 861 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3518 "conf_parser.c"
    break;

  case 143:
#line 865 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3527 "conf_parser.c"
    break;

  case 144:
#line 869 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3536 "conf_parser.c"
    break;

  case 145:
#line 873 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3545 "conf_parser.c"
    break;

  case 146:
#line 877 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3554 "conf_parser.c"
    break;

  case 147:
#line 881 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3563 "conf_parser.c"
    break;

  case 148:
#line 885 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3572 "conf_parser.c"
    break;

  case 149:
#line 889 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3581 "conf_parser.c"
    break;

  case 150:
#line 899 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3593 "conf_parser.c"
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
#line 3652 "conf_parser.c"
    break;

  case 165:
#line 975 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3661 "conf_parser.c"
    break;

  case 166:
#line 981 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3670 "conf_parser.c"
    break;

  case 167:
#line 987 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3679 "conf_parser.c"
    break;

  case 168:
#line 993 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3688 "conf_parser.c"
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
#line 3702 "conf_parser.c"
    break;

  case 170:
#line 1010 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3711 "conf_parser.c"
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
#line 3725 "conf_parser.c"
    break;

  case 172:
#line 1027 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3734 "conf_parser.c"
    break;

  case 173:
#line 1033 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3743 "conf_parser.c"
    break;

  case 177:
#line 1040 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOT;
}
#line 3752 "conf_parser.c"
    break;

  case 178:
#line 1044 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3761 "conf_parser.c"
    break;

  case 179:
#line 1048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3770 "conf_parser.c"
    break;

  case 180:
#line 1052 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3779 "conf_parser.c"
    break;

  case 181:
#line 1056 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FLOOD;
}
#line 3788 "conf_parser.c"
    break;

  case 182:
#line 1060 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3797 "conf_parser.c"
    break;

  case 183:
#line 1064 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3806 "conf_parser.c"
    break;

  case 184:
#line 1068 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3815 "conf_parser.c"
    break;

  case 185:
#line 1072 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3824 "conf_parser.c"
    break;

  case 186:
#line 1076 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3833 "conf_parser.c"
    break;

  case 187:
#line 1080 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3842 "conf_parser.c"
    break;

  case 188:
#line 1084 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3851 "conf_parser.c"
    break;

  case 189:
#line 1088 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3860 "conf_parser.c"
    break;

  case 190:
#line 1092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3869 "conf_parser.c"
    break;

  case 191:
#line 1096 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3878 "conf_parser.c"
    break;

  case 192:
#line 1100 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3887 "conf_parser.c"
    break;

  case 193:
#line 1104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3896 "conf_parser.c"
    break;

  case 194:
#line 1108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3905 "conf_parser.c"
    break;

  case 195:
#line 1112 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3914 "conf_parser.c"
    break;

  case 196:
#line 1116 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3923 "conf_parser.c"
    break;

  case 197:
#line 1120 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3932 "conf_parser.c"
    break;

  case 198:
#line 1124 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3941 "conf_parser.c"
    break;

  case 199:
#line 1130 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3950 "conf_parser.c"
    break;

  case 203:
#line 1137 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3959 "conf_parser.c"
    break;

  case 204:
#line 1141 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3968 "conf_parser.c"
    break;

  case 205:
#line 1145 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3977 "conf_parser.c"
    break;

  case 206:
#line 1149 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3986 "conf_parser.c"
    break;

  case 207:
#line 1153 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3995 "conf_parser.c"
    break;

  case 208:
#line 1157 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4004 "conf_parser.c"
    break;

  case 209:
#line 1161 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4013 "conf_parser.c"
    break;

  case 210:
#line 1165 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4022 "conf_parser.c"
    break;

  case 211:
#line 1169 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4031 "conf_parser.c"
    break;

  case 212:
#line 1173 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4040 "conf_parser.c"
    break;

  case 213:
#line 1177 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4049 "conf_parser.c"
    break;

  case 214:
#line 1181 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4058 "conf_parser.c"
    break;

  case 215:
#line 1185 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4067 "conf_parser.c"
    break;

  case 216:
#line 1189 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4076 "conf_parser.c"
    break;

  case 217:
#line 1193 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4085 "conf_parser.c"
    break;

  case 218:
#line 1197 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4094 "conf_parser.c"
    break;

  case 219:
#line 1201 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4103 "conf_parser.c"
    break;

  case 220:
#line 1205 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4112 "conf_parser.c"
    break;

  case 221:
#line 1209 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4121 "conf_parser.c"
    break;

  case 222:
#line 1213 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4130 "conf_parser.c"
    break;

  case 223:
#line 1217 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4139 "conf_parser.c"
    break;

  case 224:
#line 1221 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4148 "conf_parser.c"
    break;

  case 225:
#line 1225 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4157 "conf_parser.c"
    break;

  case 226:
#line 1229 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4166 "conf_parser.c"
    break;

  case 227:
#line 1233 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4175 "conf_parser.c"
    break;

  case 228:
#line 1237 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4184 "conf_parser.c"
    break;

  case 229:
#line 1241 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4193 "conf_parser.c"
    break;

  case 230:
#line 1245 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4202 "conf_parser.c"
    break;

  case 231:
#line 1249 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4211 "conf_parser.c"
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
#line 4227 "conf_parser.c"
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
#line 4275 "conf_parser.c"
    break;

  case 252:
#line 1333 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4284 "conf_parser.c"
    break;

  case 253:
#line 1339 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4293 "conf_parser.c"
    break;

  case 254:
#line 1345 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4302 "conf_parser.c"
    break;

  case 255:
#line 1351 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4311 "conf_parser.c"
    break;

  case 256:
#line 1357 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4320 "conf_parser.c"
    break;

  case 257:
#line 1363 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4329 "conf_parser.c"
    break;

  case 258:
#line 1369 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4338 "conf_parser.c"
    break;

  case 259:
#line 1375 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4347 "conf_parser.c"
    break;

  case 260:
#line 1381 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4357 "conf_parser.c"
    break;

  case 261:
#line 1388 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4366 "conf_parser.c"
    break;

  case 262:
#line 1394 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4375 "conf_parser.c"
    break;

  case 263:
#line 1400 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4384 "conf_parser.c"
    break;

  case 264:
#line 1406 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4396 "conf_parser.c"
    break;

  case 265:
#line 1415 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4408 "conf_parser.c"
    break;

  case 266:
#line 1424 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4417 "conf_parser.c"
    break;

  case 270:
#line 1431 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4426 "conf_parser.c"
    break;

  case 271:
#line 1435 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4435 "conf_parser.c"
    break;

  case 272:
#line 1445 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4444 "conf_parser.c"
    break;

  case 274:
#line 1451 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4452 "conf_parser.c"
    break;

  case 278:
#line 1457 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4461 "conf_parser.c"
    break;

  case 279:
#line 1461 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4470 "conf_parser.c"
    break;

  case 280:
#line 1465 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4479 "conf_parser.c"
    break;

  case 281:
#line 1469 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4488 "conf_parser.c"
    break;

  case 282:
#line 1473 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4497 "conf_parser.c"
    break;

  case 290:
#line 1481 "conf_parser.y"
                                 { block_state.flags.value = 0; }
#line 4503 "conf_parser.c"
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
#line 4521 "conf_parser.c"
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
#line 4541 "conf_parser.c"
    break;

  case 296:
#line 1516 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4550 "conf_parser.c"
    break;

  case 297:
#line 1522 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4559 "conf_parser.c"
    break;

  case 298:
#line 1532 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4568 "conf_parser.c"
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
#line 4614 "conf_parser.c"
    break;

  case 311:
#line 1590 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4623 "conf_parser.c"
    break;

  case 312:
#line 1596 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4632 "conf_parser.c"
    break;

  case 313:
#line 1602 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4641 "conf_parser.c"
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
#line 4655 "conf_parser.c"
    break;

  case 315:
#line 1619 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4664 "conf_parser.c"
    break;

  case 319:
#line 1626 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4673 "conf_parser.c"
    break;

  case 320:
#line 1630 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4682 "conf_parser.c"
    break;

  case 321:
#line 1634 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4691 "conf_parser.c"
    break;

  case 322:
#line 1638 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4700 "conf_parser.c"
    break;

  case 323:
#line 1642 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4709 "conf_parser.c"
    break;

  case 324:
#line 1646 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4718 "conf_parser.c"
    break;

  case 325:
#line 1650 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4727 "conf_parser.c"
    break;

  case 326:
#line 1654 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4736 "conf_parser.c"
    break;

  case 327:
#line 1658 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4745 "conf_parser.c"
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
#line 4762 "conf_parser.c"
    break;

  case 329:
#line 1678 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4774 "conf_parser.c"
    break;

  case 330:
#line 1687 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4786 "conf_parser.c"
    break;

  case 331:
#line 1700 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4798 "conf_parser.c"
    break;

  case 332:
#line 1707 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4809 "conf_parser.c"
    break;

  case 339:
#line 1718 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4818 "conf_parser.c"
    break;

  case 340:
#line 1724 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4827 "conf_parser.c"
    break;

  case 341:
#line 1730 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4836 "conf_parser.c"
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
#line 4851 "conf_parser.c"
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
#line 4867 "conf_parser.c"
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
#line 4882 "conf_parser.c"
    break;

  case 356:
#line 1787 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4891 "conf_parser.c"
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
#line 4913 "conf_parser.c"
    break;

  case 358:
#line 1812 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4922 "conf_parser.c"
    break;

  case 362:
#line 1819 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4931 "conf_parser.c"
    break;

  case 363:
#line 1823 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4940 "conf_parser.c"
    break;

  case 364:
#line 1827 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4949 "conf_parser.c"
    break;

  case 365:
#line 1831 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4958 "conf_parser.c"
    break;

  case 366:
#line 1835 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4967 "conf_parser.c"
    break;

  case 367:
#line 1839 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4976 "conf_parser.c"
    break;

  case 368:
#line 1843 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4985 "conf_parser.c"
    break;

  case 369:
#line 1847 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4994 "conf_parser.c"
    break;

  case 370:
#line 1851 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5003 "conf_parser.c"
    break;

  case 371:
#line 1855 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5012 "conf_parser.c"
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
#line 5026 "conf_parser.c"
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
#line 5039 "conf_parser.c"
    break;

  case 379:
#line 1887 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5048 "conf_parser.c"
    break;

  case 380:
#line 1893 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5057 "conf_parser.c"
    break;

  case 384:
#line 1900 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5066 "conf_parser.c"
    break;

  case 385:
#line 1904 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5075 "conf_parser.c"
    break;

  case 386:
#line 1908 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5084 "conf_parser.c"
    break;

  case 387:
#line 1912 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5093 "conf_parser.c"
    break;

  case 388:
#line 1916 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5102 "conf_parser.c"
    break;

  case 389:
#line 1920 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5111 "conf_parser.c"
    break;

  case 390:
#line 1924 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5120 "conf_parser.c"
    break;

  case 391:
#line 1928 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5129 "conf_parser.c"
    break;

  case 392:
#line 1932 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5138 "conf_parser.c"
    break;

  case 393:
#line 1936 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5147 "conf_parser.c"
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
#line 5162 "conf_parser.c"
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
#line 5233 "conf_parser.c"
    break;

  case 414:
#line 2042 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5242 "conf_parser.c"
    break;

  case 415:
#line 2048 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5251 "conf_parser.c"
    break;

  case 416:
#line 2054 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5260 "conf_parser.c"
    break;

  case 417:
#line 2060 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5269 "conf_parser.c"
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
#line 5285 "conf_parser.c"
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
#line 5301 "conf_parser.c"
    break;

  case 420:
#line 2092 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5310 "conf_parser.c"
    break;

  case 421:
#line 2098 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5319 "conf_parser.c"
    break;

  case 422:
#line 2104 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5328 "conf_parser.c"
    break;

  case 423:
#line 2108 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5337 "conf_parser.c"
    break;

  case 424:
#line 2114 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5345 "conf_parser.c"
    break;

  case 428:
#line 2120 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5354 "conf_parser.c"
    break;

  case 429:
#line 2124 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5363 "conf_parser.c"
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
#line 5377 "conf_parser.c"
    break;

  case 431:
#line 2141 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5386 "conf_parser.c"
    break;

  case 432:
#line 2147 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5395 "conf_parser.c"
    break;

  case 433:
#line 2153 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5404 "conf_parser.c"
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
#line 5418 "conf_parser.c"
    break;

  case 435:
#line 2174 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5427 "conf_parser.c"
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
#line 5450 "conf_parser.c"
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
#line 5473 "conf_parser.c"
    break;

  case 443:
#line 2221 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5482 "conf_parser.c"
    break;

  case 444:
#line 2231 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5491 "conf_parser.c"
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
#line 5515 "conf_parser.c"
    break;

  case 451:
#line 2259 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5524 "conf_parser.c"
    break;

  case 452:
#line 2265 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5533 "conf_parser.c"
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
#line 5550 "conf_parser.c"
    break;

  case 459:
#line 2297 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5559 "conf_parser.c"
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
#line 5579 "conf_parser.c"
    break;

  case 466:
#line 2321 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5588 "conf_parser.c"
    break;

  case 467:
#line 2327 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5597 "conf_parser.c"
    break;

  case 517:
#line 2388 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5605 "conf_parser.c"
    break;

  case 518:
#line 2393 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5613 "conf_parser.c"
    break;

  case 519:
#line 2398 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5621 "conf_parser.c"
    break;

  case 520:
#line 2403 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5629 "conf_parser.c"
    break;

  case 521:
#line 2408 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5637 "conf_parser.c"
    break;

  case 522:
#line 2413 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5645 "conf_parser.c"
    break;

  case 523:
#line 2418 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5653 "conf_parser.c"
    break;

  case 524:
#line 2423 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5661 "conf_parser.c"
    break;

  case 525:
#line 2428 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5669 "conf_parser.c"
    break;

  case 526:
#line 2433 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5677 "conf_parser.c"
    break;

  case 527:
#line 2438 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5685 "conf_parser.c"
    break;

  case 528:
#line 2443 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5693 "conf_parser.c"
    break;

  case 529:
#line 2448 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5701 "conf_parser.c"
    break;

  case 530:
#line 2453 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5709 "conf_parser.c"
    break;

  case 531:
#line 2458 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5717 "conf_parser.c"
    break;

  case 532:
#line 2463 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5725 "conf_parser.c"
    break;

  case 533:
#line 2468 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5733 "conf_parser.c"
    break;

  case 534:
#line 2473 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5741 "conf_parser.c"
    break;

  case 535:
#line 2478 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5749 "conf_parser.c"
    break;

  case 536:
#line 2483 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5757 "conf_parser.c"
    break;

  case 537:
#line 2488 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5765 "conf_parser.c"
    break;

  case 538:
#line 2493 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5773 "conf_parser.c"
    break;

  case 539:
#line 2498 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5781 "conf_parser.c"
    break;

  case 540:
#line 2503 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5789 "conf_parser.c"
    break;

  case 541:
#line 2508 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5797 "conf_parser.c"
    break;

  case 542:
#line 2513 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 5805 "conf_parser.c"
    break;

  case 543:
#line 2518 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 5813 "conf_parser.c"
    break;

  case 544:
#line 2523 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5821 "conf_parser.c"
    break;

  case 545:
#line 2528 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5829 "conf_parser.c"
    break;

  case 546:
#line 2533 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5837 "conf_parser.c"
    break;

  case 547:
#line 2538 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5845 "conf_parser.c"
    break;

  case 548:
#line 2543 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 5853 "conf_parser.c"
    break;

  case 549:
#line 2548 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5861 "conf_parser.c"
    break;

  case 550:
#line 2553 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 5869 "conf_parser.c"
    break;

  case 551:
#line 2558 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5877 "conf_parser.c"
    break;

  case 552:
#line 2563 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5885 "conf_parser.c"
    break;

  case 553:
#line 2568 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5893 "conf_parser.c"
    break;

  case 554:
#line 2573 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5901 "conf_parser.c"
    break;

  case 555:
#line 2578 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5909 "conf_parser.c"
    break;

  case 556:
#line 2583 "conf_parser.y"
{
  ConfigGeneral.oper_umodes = 0;
}
#line 5917 "conf_parser.c"
    break;

  case 560:
#line 2589 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_BOT;
}
#line 5925 "conf_parser.c"
    break;

  case 561:
#line 2592 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5933 "conf_parser.c"
    break;

  case 562:
#line 2595 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5941 "conf_parser.c"
    break;

  case 563:
#line 2598 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5949 "conf_parser.c"
    break;

  case 564:
#line 2601 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FLOOD;
}
#line 5957 "conf_parser.c"
    break;

  case 565:
#line 2604 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5965 "conf_parser.c"
    break;

  case 566:
#line 2607 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5973 "conf_parser.c"
    break;

  case 567:
#line 2610 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5981 "conf_parser.c"
    break;

  case 568:
#line 2613 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5989 "conf_parser.c"
    break;

  case 569:
#line 2616 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5997 "conf_parser.c"
    break;

  case 570:
#line 2619 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6005 "conf_parser.c"
    break;

  case 571:
#line 2622 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6013 "conf_parser.c"
    break;

  case 572:
#line 2625 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6021 "conf_parser.c"
    break;

  case 573:
#line 2628 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6029 "conf_parser.c"
    break;

  case 574:
#line 2631 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6037 "conf_parser.c"
    break;

  case 575:
#line 2634 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6045 "conf_parser.c"
    break;

  case 576:
#line 2637 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6053 "conf_parser.c"
    break;

  case 577:
#line 2640 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6061 "conf_parser.c"
    break;

  case 578:
#line 2643 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6069 "conf_parser.c"
    break;

  case 579:
#line 2646 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6077 "conf_parser.c"
    break;

  case 580:
#line 2649 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6085 "conf_parser.c"
    break;

  case 581:
#line 2652 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6093 "conf_parser.c"
    break;

  case 582:
#line 2657 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6101 "conf_parser.c"
    break;

  case 586:
#line 2663 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_BOT;
}
#line 6109 "conf_parser.c"
    break;

  case 587:
#line 2666 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6117 "conf_parser.c"
    break;

  case 588:
#line 2669 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6125 "conf_parser.c"
    break;

  case 589:
#line 2672 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6133 "conf_parser.c"
    break;

  case 590:
#line 2675 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FLOOD;
}
#line 6141 "conf_parser.c"
    break;

  case 591:
#line 2678 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6149 "conf_parser.c"
    break;

  case 592:
#line 2681 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6157 "conf_parser.c"
    break;

  case 593:
#line 2684 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDECHANS;
}
#line 6165 "conf_parser.c"
    break;

  case 594:
#line 2687 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDEIDLE;
}
#line 6173 "conf_parser.c"
    break;

  case 595:
#line 2690 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6181 "conf_parser.c"
    break;

  case 596:
#line 2693 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6189 "conf_parser.c"
    break;

  case 597:
#line 2696 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6197 "conf_parser.c"
    break;

  case 598:
#line 2699 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6205 "conf_parser.c"
    break;

  case 599:
#line 2702 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6213 "conf_parser.c"
    break;

  case 600:
#line 2705 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6221 "conf_parser.c"
    break;

  case 601:
#line 2708 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6229 "conf_parser.c"
    break;

  case 602:
#line 2711 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6237 "conf_parser.c"
    break;

  case 603:
#line 2714 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6245 "conf_parser.c"
    break;

  case 604:
#line 2717 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6253 "conf_parser.c"
    break;

  case 605:
#line 2720 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6261 "conf_parser.c"
    break;

  case 606:
#line 2723 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6269 "conf_parser.c"
    break;

  case 607:
#line 2726 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6277 "conf_parser.c"
    break;

  case 608:
#line 2731 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6285 "conf_parser.c"
    break;

  case 609:
#line 2736 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6293 "conf_parser.c"
    break;

  case 610:
#line 2741 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6301 "conf_parser.c"
    break;

  case 611:
#line 2746 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6309 "conf_parser.c"
    break;

  case 631:
#line 2775 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6317 "conf_parser.c"
    break;

  case 632:
#line 2780 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6325 "conf_parser.c"
    break;

  case 633:
#line 2785 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6333 "conf_parser.c"
    break;

  case 634:
#line 2790 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6341 "conf_parser.c"
    break;

  case 635:
#line 2795 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6349 "conf_parser.c"
    break;

  case 636:
#line 2800 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6357 "conf_parser.c"
    break;

  case 637:
#line 2805 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6365 "conf_parser.c"
    break;

  case 638:
#line 2810 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6373 "conf_parser.c"
    break;

  case 639:
#line 2815 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6381 "conf_parser.c"
    break;

  case 640:
#line 2820 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6389 "conf_parser.c"
    break;

  case 641:
#line 2825 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6397 "conf_parser.c"
    break;

  case 642:
#line 2830 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6405 "conf_parser.c"
    break;

  case 643:
#line 2835 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6413 "conf_parser.c"
    break;

  case 644:
#line 2840 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6421 "conf_parser.c"
    break;

  case 645:
#line 2845 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6429 "conf_parser.c"
    break;

  case 659:
#line 2868 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6438 "conf_parser.c"
    break;

  case 660:
#line 2874 "conf_parser.y"
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
#line 6457 "conf_parser.c"
    break;

  case 661:
#line 2890 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6469 "conf_parser.c"
    break;

  case 662:
#line 2899 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6478 "conf_parser.c"
    break;

  case 663:
#line 2905 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6487 "conf_parser.c"
    break;

  case 664:
#line 2911 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6496 "conf_parser.c"
    break;

  case 665:
#line 2917 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6508 "conf_parser.c"
    break;

  case 666:
#line 2926 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6517 "conf_parser.c"
    break;

  case 667:
#line 2932 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6526 "conf_parser.c"
    break;


#line 6530 "conf_parser.c"

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
