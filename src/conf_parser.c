/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 28 "conf_parser.y" /* yacc.c:339  */


#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
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
    aftype,
    ping_freq,
    max_perip,
    con_freq,
    min_idle,
    max_idle,
    max_total,
    max_global,
    max_local,
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
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, block_state.mask.list.head)
  {
    xfree(node->data);
    dlinkDelete(node, &block_state.mask.list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, block_state.leaf.list.head)
  {
    xfree(node->data);
    dlinkDelete(node, &block_state.leaf.list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, block_state.hub.list.head)
  {
    xfree(node->data);
    dlinkDelete(node, &block_state.hub.list);
    free_dlink_node(node);
  }

  memset(&block_state, 0, sizeof(block_state));
}


#line 179 "conf_parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    CHECK_CACHE = 272,
    CIDR_BITLEN_IPV4 = 273,
    CIDR_BITLEN_IPV6 = 274,
    CLASS = 275,
    CLOSE = 276,
    CONNECT = 277,
    CONNECTFREQ = 278,
    CYCLE_ON_HOST_CHANGE = 279,
    DEFAULT_FLOODCOUNT = 280,
    DEFAULT_JOIN_FLOOD_COUNT = 281,
    DEFAULT_JOIN_FLOOD_TIME = 282,
    DEFAULT_MAX_CLIENTS = 283,
    DENY = 284,
    DESCRIPTION = 285,
    DIE = 286,
    DISABLE_AUTH = 287,
    DISABLE_FAKE_CHANNELS = 288,
    DISABLE_REMOTE_COMMANDS = 289,
    DLINE_MIN_CIDR = 290,
    DLINE_MIN_CIDR6 = 291,
    DOTS_IN_IDENT = 292,
    EMAIL = 293,
    ENCRYPTED = 294,
    EXCEED_LIMIT = 295,
    EXEMPT = 296,
    FAILED_OPER_NOTICE = 297,
    FLATTEN_LINKS = 298,
    FLATTEN_LINKS_DELAY = 299,
    FLATTEN_LINKS_FILE = 300,
    GECOS = 301,
    GENERAL = 302,
    HIDDEN = 303,
    HIDDEN_NAME = 304,
    HIDE_CHANS = 305,
    HIDE_IDLE = 306,
    HIDE_IDLE_FROM_OPERS = 307,
    HIDE_SERVER_IPS = 308,
    HIDE_SERVERS = 309,
    HIDE_SERVICES = 310,
    HOST = 311,
    HUB = 312,
    HUB_MASK = 313,
    IGNORE_BOGUS_TS = 314,
    INVISIBLE_ON_CONNECT = 315,
    INVITE_CLIENT_COUNT = 316,
    INVITE_CLIENT_TIME = 317,
    INVITE_DELAY_CHANNEL = 318,
    IP = 319,
    IRCD_AUTH = 320,
    IRCD_FLAGS = 321,
    IRCD_SID = 322,
    JOIN = 323,
    KILL = 324,
    KILL_CHASE_TIME_LIMIT = 325,
    KLINE = 326,
    KLINE_EXEMPT = 327,
    KLINE_MIN_CIDR = 328,
    KLINE_MIN_CIDR6 = 329,
    KNOCK_CLIENT_COUNT = 330,
    KNOCK_CLIENT_TIME = 331,
    KNOCK_DELAY_CHANNEL = 332,
    LEAF_MASK = 333,
    LIBGEOIP_DATABASE_OPTIONS = 334,
    LIBGEOIP_IPV4_DATABASE_FILE = 335,
    LIBGEOIP_IPV6_DATABASE_FILE = 336,
    LISTEN = 337,
    MASK = 338,
    MAX_ACCEPT = 339,
    MAX_BANS = 340,
    MAX_CHANNELS = 341,
    MAX_GLOBAL = 342,
    MAX_IDLE = 343,
    MAX_INVITES = 344,
    MAX_LOCAL = 345,
    MAX_NICK_CHANGES = 346,
    MAX_NICK_LENGTH = 347,
    MAX_NICK_TIME = 348,
    MAX_NUMBER = 349,
    MAX_TARGETS = 350,
    MAX_TOPIC_LENGTH = 351,
    MAX_WATCH = 352,
    MEMORY_CACHE = 353,
    MIN_IDLE = 354,
    MIN_NONWILDCARD = 355,
    MIN_NONWILDCARD_SIMPLE = 356,
    MMAP_CACHE = 357,
    MODULE = 358,
    MODULES = 359,
    MOTD = 360,
    NAME = 361,
    NEED_IDENT = 362,
    NEED_PASSWORD = 363,
    NETWORK_DESC = 364,
    NETWORK_NAME = 365,
    NICK = 366,
    NO_OPER_FLOOD = 367,
    NO_TILDE = 368,
    NUMBER = 369,
    NUMBER_PER_CIDR = 370,
    NUMBER_PER_IP = 371,
    OPER_ONLY_UMODES = 372,
    OPER_UMODES = 373,
    OPERATOR = 374,
    OPERS_BYPASS_CALLERID = 375,
    PACE_WAIT = 376,
    PACE_WAIT_SIMPLE = 377,
    PASSWORD = 378,
    PATH = 379,
    PING_COOKIE = 380,
    PING_TIME = 381,
    PORT = 382,
    QSTRING = 383,
    RANDOM_IDLE = 384,
    REASON = 385,
    REDIRPORT = 386,
    REDIRSERV = 387,
    REHASH = 388,
    REMOTE = 389,
    REMOTEBAN = 390,
    RESV = 391,
    RESV_EXEMPT = 392,
    RSA_PRIVATE_KEY_FILE = 393,
    SECONDS = 394,
    MINUTES = 395,
    HOURS = 396,
    DAYS = 397,
    WEEKS = 398,
    MONTHS = 399,
    YEARS = 400,
    SEND_PASSWORD = 401,
    SENDQ = 402,
    SERVERHIDE = 403,
    SERVERINFO = 404,
    SHORT_MOTD = 405,
    SPOOF = 406,
    SPOOF_NOTICE = 407,
    SQUIT = 408,
    SSL_CERTIFICATE_FILE = 409,
    SSL_CERTIFICATE_FINGERPRINT = 410,
    SSL_CONNECTION_REQUIRED = 411,
    SSL_DH_ELLIPTIC_CURVE = 412,
    SSL_DH_PARAM_FILE = 413,
    SSL_MESSAGE_DIGEST_ALGORITHM = 414,
    STANDARD = 415,
    STATS_E_DISABLED = 416,
    STATS_I_OPER_ONLY = 417,
    STATS_K_OPER_ONLY = 418,
    STATS_M_OPER_ONLY = 419,
    STATS_O_OPER_ONLY = 420,
    STATS_P_OPER_ONLY = 421,
    STATS_U_OPER_ONLY = 422,
    T_ALL = 423,
    T_BOTS = 424,
    T_CALLERID = 425,
    T_CCONN = 426,
    T_COMMAND = 427,
    T_CLUSTER = 428,
    T_DEAF = 429,
    T_DEBUG = 430,
    T_DLINE = 431,
    T_EXTERNAL = 432,
    T_FARCONNECT = 433,
    T_FILE = 434,
    T_FULL = 435,
    T_GLOBOPS = 436,
    T_INVISIBLE = 437,
    T_IPV4 = 438,
    T_IPV6 = 439,
    T_LOCOPS = 440,
    T_LOG = 441,
    T_NCHANGE = 442,
    T_NONONREG = 443,
    T_OPME = 444,
    T_PREPEND = 445,
    T_PSEUDO = 446,
    T_RECVQ = 447,
    T_REJ = 448,
    T_RESTART = 449,
    T_SERVER = 450,
    T_SERVICE = 451,
    T_SERVNOTICE = 452,
    T_SET = 453,
    T_SHARED = 454,
    T_SIZE = 455,
    T_SKILL = 456,
    T_SOFTCALLERID = 457,
    T_SPY = 458,
    T_SSL = 459,
    T_SSL_CIPHER_LIST = 460,
    T_TARGET = 461,
    T_UMODES = 462,
    T_UNAUTH = 463,
    T_UNDLINE = 464,
    T_UNLIMITED = 465,
    T_UNRESV = 466,
    T_UNXLINE = 467,
    T_WALLOP = 468,
    T_WALLOPS = 469,
    T_WEBIRC = 470,
    TBOOL = 471,
    THROTTLE_COUNT = 472,
    THROTTLE_TIME = 473,
    TKLINE_EXPIRE_NOTICES = 474,
    TMASKED = 475,
    TS_MAX_DELTA = 476,
    TS_WARN_DELTA = 477,
    TWODOTS = 478,
    TYPE = 479,
    UNKLINE = 480,
    USE_LOGGING = 481,
    USER = 482,
    VHOST = 483,
    VHOST6 = 484,
    WARN_NO_CONNECT_BLOCK = 485,
    WHOIS = 486,
    WHOWAS_HISTORY_LENGTH = 487,
    XLINE = 488,
    XLINE_EXEMPT = 489
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
#define CHECK_CACHE 272
#define CIDR_BITLEN_IPV4 273
#define CIDR_BITLEN_IPV6 274
#define CLASS 275
#define CLOSE 276
#define CONNECT 277
#define CONNECTFREQ 278
#define CYCLE_ON_HOST_CHANGE 279
#define DEFAULT_FLOODCOUNT 280
#define DEFAULT_JOIN_FLOOD_COUNT 281
#define DEFAULT_JOIN_FLOOD_TIME 282
#define DEFAULT_MAX_CLIENTS 283
#define DENY 284
#define DESCRIPTION 285
#define DIE 286
#define DISABLE_AUTH 287
#define DISABLE_FAKE_CHANNELS 288
#define DISABLE_REMOTE_COMMANDS 289
#define DLINE_MIN_CIDR 290
#define DLINE_MIN_CIDR6 291
#define DOTS_IN_IDENT 292
#define EMAIL 293
#define ENCRYPTED 294
#define EXCEED_LIMIT 295
#define EXEMPT 296
#define FAILED_OPER_NOTICE 297
#define FLATTEN_LINKS 298
#define FLATTEN_LINKS_DELAY 299
#define FLATTEN_LINKS_FILE 300
#define GECOS 301
#define GENERAL 302
#define HIDDEN 303
#define HIDDEN_NAME 304
#define HIDE_CHANS 305
#define HIDE_IDLE 306
#define HIDE_IDLE_FROM_OPERS 307
#define HIDE_SERVER_IPS 308
#define HIDE_SERVERS 309
#define HIDE_SERVICES 310
#define HOST 311
#define HUB 312
#define HUB_MASK 313
#define IGNORE_BOGUS_TS 314
#define INVISIBLE_ON_CONNECT 315
#define INVITE_CLIENT_COUNT 316
#define INVITE_CLIENT_TIME 317
#define INVITE_DELAY_CHANNEL 318
#define IP 319
#define IRCD_AUTH 320
#define IRCD_FLAGS 321
#define IRCD_SID 322
#define JOIN 323
#define KILL 324
#define KILL_CHASE_TIME_LIMIT 325
#define KLINE 326
#define KLINE_EXEMPT 327
#define KLINE_MIN_CIDR 328
#define KLINE_MIN_CIDR6 329
#define KNOCK_CLIENT_COUNT 330
#define KNOCK_CLIENT_TIME 331
#define KNOCK_DELAY_CHANNEL 332
#define LEAF_MASK 333
#define LIBGEOIP_DATABASE_OPTIONS 334
#define LIBGEOIP_IPV4_DATABASE_FILE 335
#define LIBGEOIP_IPV6_DATABASE_FILE 336
#define LISTEN 337
#define MASK 338
#define MAX_ACCEPT 339
#define MAX_BANS 340
#define MAX_CHANNELS 341
#define MAX_GLOBAL 342
#define MAX_IDLE 343
#define MAX_INVITES 344
#define MAX_LOCAL 345
#define MAX_NICK_CHANGES 346
#define MAX_NICK_LENGTH 347
#define MAX_NICK_TIME 348
#define MAX_NUMBER 349
#define MAX_TARGETS 350
#define MAX_TOPIC_LENGTH 351
#define MAX_WATCH 352
#define MEMORY_CACHE 353
#define MIN_IDLE 354
#define MIN_NONWILDCARD 355
#define MIN_NONWILDCARD_SIMPLE 356
#define MMAP_CACHE 357
#define MODULE 358
#define MODULES 359
#define MOTD 360
#define NAME 361
#define NEED_IDENT 362
#define NEED_PASSWORD 363
#define NETWORK_DESC 364
#define NETWORK_NAME 365
#define NICK 366
#define NO_OPER_FLOOD 367
#define NO_TILDE 368
#define NUMBER 369
#define NUMBER_PER_CIDR 370
#define NUMBER_PER_IP 371
#define OPER_ONLY_UMODES 372
#define OPER_UMODES 373
#define OPERATOR 374
#define OPERS_BYPASS_CALLERID 375
#define PACE_WAIT 376
#define PACE_WAIT_SIMPLE 377
#define PASSWORD 378
#define PATH 379
#define PING_COOKIE 380
#define PING_TIME 381
#define PORT 382
#define QSTRING 383
#define RANDOM_IDLE 384
#define REASON 385
#define REDIRPORT 386
#define REDIRSERV 387
#define REHASH 388
#define REMOTE 389
#define REMOTEBAN 390
#define RESV 391
#define RESV_EXEMPT 392
#define RSA_PRIVATE_KEY_FILE 393
#define SECONDS 394
#define MINUTES 395
#define HOURS 396
#define DAYS 397
#define WEEKS 398
#define MONTHS 399
#define YEARS 400
#define SEND_PASSWORD 401
#define SENDQ 402
#define SERVERHIDE 403
#define SERVERINFO 404
#define SHORT_MOTD 405
#define SPOOF 406
#define SPOOF_NOTICE 407
#define SQUIT 408
#define SSL_CERTIFICATE_FILE 409
#define SSL_CERTIFICATE_FINGERPRINT 410
#define SSL_CONNECTION_REQUIRED 411
#define SSL_DH_ELLIPTIC_CURVE 412
#define SSL_DH_PARAM_FILE 413
#define SSL_MESSAGE_DIGEST_ALGORITHM 414
#define STANDARD 415
#define STATS_E_DISABLED 416
#define STATS_I_OPER_ONLY 417
#define STATS_K_OPER_ONLY 418
#define STATS_M_OPER_ONLY 419
#define STATS_O_OPER_ONLY 420
#define STATS_P_OPER_ONLY 421
#define STATS_U_OPER_ONLY 422
#define T_ALL 423
#define T_BOTS 424
#define T_CALLERID 425
#define T_CCONN 426
#define T_COMMAND 427
#define T_CLUSTER 428
#define T_DEAF 429
#define T_DEBUG 430
#define T_DLINE 431
#define T_EXTERNAL 432
#define T_FARCONNECT 433
#define T_FILE 434
#define T_FULL 435
#define T_GLOBOPS 436
#define T_INVISIBLE 437
#define T_IPV4 438
#define T_IPV6 439
#define T_LOCOPS 440
#define T_LOG 441
#define T_NCHANGE 442
#define T_NONONREG 443
#define T_OPME 444
#define T_PREPEND 445
#define T_PSEUDO 446
#define T_RECVQ 447
#define T_REJ 448
#define T_RESTART 449
#define T_SERVER 450
#define T_SERVICE 451
#define T_SERVNOTICE 452
#define T_SET 453
#define T_SHARED 454
#define T_SIZE 455
#define T_SKILL 456
#define T_SOFTCALLERID 457
#define T_SPY 458
#define T_SSL 459
#define T_SSL_CIPHER_LIST 460
#define T_TARGET 461
#define T_UMODES 462
#define T_UNAUTH 463
#define T_UNDLINE 464
#define T_UNLIMITED 465
#define T_UNRESV 466
#define T_UNXLINE 467
#define T_WALLOP 468
#define T_WALLOPS 469
#define T_WEBIRC 470
#define TBOOL 471
#define THROTTLE_COUNT 472
#define THROTTLE_TIME 473
#define TKLINE_EXPIRE_NOTICES 474
#define TMASKED 475
#define TS_MAX_DELTA 476
#define TS_WARN_DELTA 477
#define TWODOTS 478
#define TYPE 479
#define UNKLINE 480
#define USE_LOGGING 481
#define USER 482
#define VHOST 483
#define VHOST6 484
#define WARN_NO_CONNECT_BLOCK 485
#define WHOIS 486
#define WHOWAS_HISTORY_LENGTH 487
#define XLINE 488
#define XLINE_EXEMPT 489

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 141 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 692 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 709 "conf_parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   1356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  241
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  299
/* YYNRULES -- Number of rules.  */
#define YYNRULES  677
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1332

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   489

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   239,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   240,   235,
       2,   238,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   237,     2,   236,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   379,   379,   380,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   410,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   421,   421,
     422,   423,   424,   425,   432,   434,   434,   435,   435,   435,
     437,   443,   453,   455,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   479,   488,   497,   506,
     515,   524,   534,   533,   539,   539,   540,   546,   552,   558,
     566,   581,   596,   611,   626,   636,   650,   659,   687,   715,
     740,   762,   784,   794,   796,   796,   797,   798,   799,   800,
     802,   811,   820,   834,   833,   851,   851,   852,   852,   852,
     854,   860,   871,   870,   889,   889,   890,   890,   890,   890,
     890,   892,   898,   904,   910,   932,   933,   933,   935,   935,
     936,   938,   945,   945,   958,   959,   961,   961,   962,   962,
     964,   972,   975,   981,   980,   986,   986,   987,   991,   995,
     999,  1003,  1007,  1011,  1015,  1026,  1025,  1086,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,
    1099,  1105,  1111,  1117,  1123,  1134,  1140,  1151,  1158,  1157,
    1163,  1163,  1164,  1168,  1172,  1176,  1180,  1184,  1188,  1192,
    1196,  1200,  1204,  1208,  1212,  1216,  1220,  1224,  1228,  1232,
    1236,  1240,  1244,  1248,  1255,  1254,  1260,  1260,  1261,  1265,
    1269,  1273,  1277,  1281,  1285,  1289,  1293,  1297,  1301,  1305,
    1309,  1313,  1317,  1321,  1325,  1329,  1333,  1337,  1341,  1345,
    1349,  1353,  1357,  1361,  1365,  1369,  1373,  1384,  1383,  1439,
    1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,
    1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,  1458,  1464,
    1470,  1476,  1482,  1488,  1494,  1500,  1506,  1512,  1519,  1525,
    1531,  1537,  1546,  1556,  1555,  1561,  1561,  1562,  1566,  1577,
    1576,  1583,  1582,  1587,  1587,  1588,  1592,  1596,  1602,  1602,
    1603,  1603,  1603,  1603,  1603,  1605,  1605,  1607,  1607,  1609,
    1622,  1639,  1645,  1656,  1655,  1701,  1701,  1702,  1703,  1704,
    1705,  1706,  1707,  1708,  1709,  1710,  1712,  1718,  1724,  1730,
    1742,  1741,  1747,  1747,  1748,  1752,  1756,  1760,  1764,  1768,
    1772,  1776,  1780,  1784,  1790,  1804,  1813,  1827,  1826,  1841,
    1841,  1842,  1842,  1842,  1842,  1844,  1850,  1856,  1866,  1868,
    1868,  1869,  1869,  1871,  1888,  1887,  1910,  1910,  1911,  1911,
    1911,  1911,  1913,  1919,  1939,  1938,  1944,  1944,  1945,  1949,
    1953,  1957,  1961,  1965,  1969,  1973,  1977,  1981,  1992,  1991,
    2010,  2010,  2011,  2011,  2011,  2013,  2020,  2019,  2025,  2025,
    2026,  2030,  2034,  2038,  2042,  2046,  2050,  2054,  2058,  2062,
    2073,  2072,  2144,  2144,  2145,  2146,  2147,  2148,  2149,  2150,
    2151,  2152,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2161,
    2167,  2173,  2179,  2192,  2205,  2211,  2217,  2221,  2228,  2227,
    2232,  2232,  2233,  2237,  2243,  2254,  2260,  2266,  2272,  2288,
    2287,  2313,  2313,  2314,  2314,  2314,  2316,  2336,  2347,  2346,
    2373,  2373,  2374,  2374,  2374,  2376,  2382,  2392,  2394,  2394,
    2395,  2395,  2397,  2415,  2414,  2435,  2435,  2436,  2436,  2436,
    2438,  2444,  2454,  2456,  2456,  2457,  2458,  2459,  2460,  2461,
    2462,  2463,  2464,  2465,  2466,  2467,  2468,  2469,  2470,  2471,
    2472,  2473,  2474,  2475,  2476,  2477,  2478,  2479,  2480,  2481,
    2482,  2483,  2484,  2485,  2486,  2487,  2488,  2489,  2490,  2491,
    2492,  2493,  2494,  2495,  2496,  2497,  2498,  2499,  2500,  2501,
    2502,  2503,  2506,  2511,  2516,  2521,  2526,  2532,  2537,  2542,
    2547,  2552,  2557,  2562,  2567,  2572,  2577,  2582,  2587,  2592,
    2597,  2602,  2608,  2613,  2618,  2623,  2628,  2633,  2638,  2643,
    2646,  2651,  2654,  2659,  2664,  2669,  2674,  2679,  2684,  2689,
    2694,  2699,  2704,  2709,  2714,  2720,  2719,  2724,  2724,  2725,
    2728,  2731,  2734,  2737,  2740,  2743,  2746,  2749,  2752,  2755,
    2758,  2761,  2764,  2767,  2770,  2773,  2776,  2779,  2782,  2785,
    2788,  2794,  2793,  2798,  2798,  2799,  2802,  2805,  2808,  2811,
    2814,  2817,  2820,  2823,  2826,  2829,  2832,  2835,  2838,  2841,
    2844,  2847,  2850,  2853,  2856,  2861,  2866,  2871,  2880,  2882,
    2882,  2883,  2884,  2885,  2886,  2887,  2888,  2889,  2890,  2891,
    2892,  2893,  2894,  2895,  2897,  2902,  2907,  2912,  2917,  2922,
    2927,  2932,  2937,  2942,  2947,  2952,  2961,  2963,  2963,  2964,
    2965,  2966,  2967,  2968,  2969,  2970,  2971,  2972,  2973,  2975,
    2981,  2997,  3006,  3012,  3018,  3024,  3033,  3039
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
  "CAN_FLOOD", "CHANNEL", "CHECK_CACHE", "CIDR_BITLEN_IPV4",
  "CIDR_BITLEN_IPV6", "CLASS", "CLOSE", "CONNECT", "CONNECTFREQ",
  "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT", "DEFAULT_JOIN_FLOOD_COUNT",
  "DEFAULT_JOIN_FLOOD_TIME", "DEFAULT_MAX_CLIENTS", "DENY", "DESCRIPTION",
  "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6",
  "DOTS_IN_IDENT", "EMAIL", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "FLATTEN_LINKS_DELAY",
  "FLATTEN_LINKS_FILE", "GECOS", "GENERAL", "HIDDEN", "HIDDEN_NAME",
  "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT",
  "INVITE_CLIENT_TIME", "INVITE_DELAY_CHANNEL", "IP", "IRCD_AUTH",
  "IRCD_FLAGS", "IRCD_SID", "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT",
  "KLINE", "KLINE_EXEMPT", "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6",
  "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL",
  "LEAF_MASK", "LIBGEOIP_DATABASE_OPTIONS", "LIBGEOIP_IPV4_DATABASE_FILE",
  "LIBGEOIP_IPV6_DATABASE_FILE", "LISTEN", "MASK", "MAX_ACCEPT",
  "MAX_BANS", "MAX_CHANNELS", "MAX_GLOBAL", "MAX_IDLE", "MAX_INVITES",
  "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME",
  "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MAX_WATCH",
  "MEMORY_CACHE", "MIN_IDLE", "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE",
  "MMAP_CACHE", "MODULE", "MODULES", "MOTD", "NAME", "NEED_IDENT",
  "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK", "NO_OPER_FLOOD",
  "NO_TILDE", "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP",
  "OPER_ONLY_UMODES", "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID",
  "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE",
  "PING_TIME", "PORT", "QSTRING", "RANDOM_IDLE", "REASON", "REDIRPORT",
  "REDIRSERV", "REHASH", "REMOTE", "REMOTEBAN", "RESV", "RESV_EXEMPT",
  "RSA_PRIVATE_KEY_FILE", "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS",
  "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ", "SERVERHIDE", "SERVERINFO",
  "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE", "SQUIT", "SSL_CERTIFICATE_FILE",
  "SSL_CERTIFICATE_FINGERPRINT", "SSL_CONNECTION_REQUIRED",
  "SSL_DH_ELLIPTIC_CURVE", "SSL_DH_PARAM_FILE",
  "SSL_MESSAGE_DIGEST_ALGORITHM", "STANDARD", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_M_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL",
  "T_BOTS", "T_CALLERID", "T_CCONN", "T_COMMAND", "T_CLUSTER", "T_DEAF",
  "T_DEBUG", "T_DLINE", "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FULL",
  "T_GLOBOPS", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG",
  "T_NCHANGE", "T_NONONREG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ",
  "T_REJ", "T_RESTART", "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET",
  "T_SHARED", "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL",
  "T_SSL_CIPHER_LIST", "T_TARGET", "T_UMODES", "T_UNAUTH", "T_UNDLINE",
  "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_WALLOP", "T_WALLOPS",
  "T_WEBIRC", "TBOOL", "THROTTLE_COUNT", "THROTTLE_TIME",
  "TKLINE_EXPIRE_NOTICES", "TMASKED", "TS_MAX_DELTA", "TS_WARN_DELTA",
  "TWODOTS", "TYPE", "UNKLINE", "USE_LOGGING", "USER", "VHOST", "VHOST6",
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "WHOWAS_HISTORY_LENGTH", "XLINE",
  "XLINE_EXEMPT", "';'", "'}'", "'{'", "'='", "','", "':'", "$accept",
  "conf", "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_ssl_message_digest_algorithm",
  "serverinfo_ssl_dh_elliptic_curve",
  "serverinfo_libgeoip_database_options", "$@1", "options_items",
  "options_item", "serverinfo_libgeoip_ipv4_database_file",
  "serverinfo_libgeoip_ipv6_database_file", "serverinfo_name",
  "serverinfo_sid", "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_default_max_clients", "serverinfo_max_nick_length",
  "serverinfo_max_topic_length", "serverinfo_hub", "admin_entry",
  "admin_items", "admin_item", "admin_name", "admin_email",
  "admin_description", "motd_entry", "$@2", "motd_items", "motd_item",
  "motd_mask", "motd_file", "pseudo_entry", "$@3", "pseudo_items",
  "pseudo_item", "pseudo_command", "pseudo_name", "pseudo_prepend",
  "pseudo_target", "logging_entry", "logging_items", "logging_item",
  "logging_use_logging", "logging_file_entry", "$@4", "logging_file_items",
  "logging_file_item", "logging_file_name", "logging_file_size",
  "logging_file_type", "$@5", "logging_file_type_items",
  "logging_file_type_item", "oper_entry", "$@6", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_whois",
  "oper_encrypted", "oper_ssl_certificate_fingerprint",
  "oper_ssl_connection_required", "oper_class", "oper_umodes", "$@7",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@8",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@9",
  "class_items", "class_item", "class_name", "class_ping_time",
  "class_number_per_ip", "class_connectfreq", "class_max_channels",
  "class_max_number", "class_max_global", "class_max_local", "class_sendq",
  "class_recvq", "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "class_min_idle", "class_max_idle",
  "class_flags", "$@10", "class_flags_items", "class_flags_item",
  "listen_entry", "$@11", "listen_flags", "$@12", "listen_flags_items",
  "listen_flags_item", "listen_items", "listen_item", "listen_port",
  "$@13", "port_items", "port_item", "listen_address", "listen_host",
  "auth_entry", "$@14", "auth_items", "auth_item", "auth_user",
  "auth_passwd", "auth_class", "auth_encrypted", "auth_flags", "$@15",
  "auth_flags_items", "auth_flags_item", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@16", "resv_items", "resv_item",
  "resv_mask", "resv_reason", "resv_exempt", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@17",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@18", "shared_types", "shared_type_item",
  "cluster_entry", "$@19", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@20", "cluster_types", "cluster_type_item",
  "connect_entry", "$@21", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_ssl_certificate_fingerprint",
  "connect_port", "connect_aftype", "connect_flags", "$@22",
  "connect_flags_items", "connect_flags_item", "connect_encrypted",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_ssl_cipher_list", "kill_entry", "$@23", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@24",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@25",
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason",
  "general_entry", "general_items", "general_item", "general_away_count",
  "general_away_time", "general_max_watch",
  "general_whowas_history_length", "general_cycle_on_host_change",
  "general_dline_min_cidr", "general_dline_min_cidr6",
  "general_kline_min_cidr", "general_kline_min_cidr6",
  "general_tkline_expire_notices", "general_kill_chase_time_limit",
  "general_ignore_bogus_ts", "general_failed_oper_notice",
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
  "$@26", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@27", "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_invite_delay_channel",
  "channel_knock_client_count", "channel_knock_client_time",
  "channel_knock_delay_channel", "channel_max_channels",
  "channel_max_invites", "channel_max_bans",
  "channel_default_join_flood_count", "channel_default_join_flood_time",
  "serverhide_entry", "serverhide_items", "serverhide_item",
  "serverhide_flatten_links", "serverhide_flatten_links_delay",
  "serverhide_flatten_links_file", "serverhide_disable_remote_commands",
  "serverhide_hide_servers", "serverhide_hide_services",
  "serverhide_hidden_name", "serverhide_hidden",
  "serverhide_hide_server_ips", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
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
     485,   486,   487,   488,   489,    59,   125,   123,    61,    44,
      58
};
# endif

#define YYPACT_NINF -795

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-795)))

#define YYTABLE_NINF -143

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -795,   693,  -795,   -43,  -217,  -212,  -795,  -795,  -795,  -210,
    -795,  -194,  -795,  -795,  -795,  -174,  -795,  -795,  -795,  -165,
    -163,  -795,  -157,  -795,  -152,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,   322,   953,  -137,  -128,  -123,    14,  -106,   376,  -100,
     -88,   -70,    80,   -62,   -53,   -51,   948,   520,   -42,     2,
     -17,    12,   -16,  -169,  -104,   -11,    -4,     9,  -795,  -795,
    -795,  -795,  -795,    42,    44,    58,    75,    99,   113,   115,
     120,   121,   123,   124,   128,   161,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,   705,
     514,    15,  -795,   129,    91,  -795,  -795,    48,  -795,   130,
     131,   132,   134,   138,   140,   141,   146,   149,   151,   153,
     154,   155,   160,   166,   168,   171,   172,   177,   178,   179,
     181,   184,   186,   187,  -795,  -795,   188,   189,   191,   192,
     193,   199,   200,   201,   203,   204,   205,   206,   207,   209,
     210,   213,   215,   216,   217,    51,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,   413,    81,    39,    83,   218,   220,    40,
    -795,  -795,  -795,    11,   355,    30,  -795,   224,   225,   226,
     228,   230,   232,   234,   236,   237,   250,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,    84,   242,   243,
     247,   249,  -795,   252,   253,   254,   257,   264,   265,   266,
     267,   268,   270,   274,   275,   276,   278,   280,   152,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
      41,   164,   282,    28,  -795,  -795,  -795,   136,   401,  -795,
     284,    23,  -795,  -795,   196,  -795,   245,   306,   395,   292,
    -795,   414,   415,   315,   418,   415,   415,   419,   415,   415,
     421,   437,   438,   320,  -795,   321,   319,   323,   325,  -795,
     327,   328,   329,   330,   333,   336,   337,   338,   340,   341,
     345,   346,   248,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
     324,   347,   350,   352,   358,   364,   366,  -795,   371,   372,
     377,   379,   380,   381,   383,    50,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,   384,   385,    20,  -795,  -795,  -795,   430,   389,
    -795,  -795,   387,   390,    27,  -795,  -795,  -795,   344,   415,
     513,   415,   415,   420,   519,   422,   521,   523,   525,   426,
     427,   428,   415,   534,   535,   536,   538,   415,   539,   542,
     543,   547,   446,   396,   408,   448,   415,   415,   449,   450,
     454,  -197,  -190,   455,   457,   459,   472,   577,   415,   480,
     415,   415,   482,   585,   466,  -795,   467,   469,   476,  -795,
     483,   488,   489,   491,   492,   169,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,   493,   494,    61,  -795,
    -795,  -795,   470,   499,   500,  -795,   507,  -795,     3,  -795,
    -795,  -795,  -795,  -795,   582,   588,   485,  -795,   511,   509,
     512,    21,  -795,  -795,  -795,   518,   516,   517,  -795,   522,
     526,   528,   529,  -795,   530,   531,   119,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,   524,   544,
     545,   546,    49,  -795,  -795,  -795,  -795,   502,   540,   415,
     633,   554,   635,   556,   557,   558,   550,  -795,  -795,   590,
     648,   561,   651,   548,   659,   660,   675,   676,   666,   668,
     672,   673,   674,   677,   678,   679,   680,   682,   686,   578,
    -795,   580,   579,  -795,    55,  -795,  -795,  -795,  -795,   600,
     584,  -795,   111,   587,   586,   589,   592,   594,   135,  -795,
    -795,  -795,  -795,  -795,   695,   591,  -795,   593,   595,  -795,
     596,    16,  -795,  -795,  -795,  -795,   601,   602,   603,  -795,
     604,   541,   605,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   618,  -795,  -795,   711,   721,   415,   619,   744,
     747,   415,   750,   754,   415,   741,   760,   761,   415,   762,
     762,   642,  -795,  -795,   752,  -138,   753,   667,   757,   763,
     652,   766,   767,   782,   774,   775,   778,   781,   681,  -795,
     783,   785,   684,  -795,   687,  -795,   786,   792,   689,  -795,
     690,   691,   694,   699,   700,   702,   707,   716,   718,   724,
     725,   726,   727,   729,   731,   734,   735,   739,   740,   742,
     746,   749,   755,   759,   764,   770,   685,   765,   769,   771,
     772,   773,   784,   787,   788,   789,   791,   796,   797,   799,
     801,   802,   805,   806,   808,   809,   810,   811,  -795,  -795,
     793,   712,   692,   818,   842,   837,   859,   860,   812,  -795,
     861,   867,   813,  -795,  -795,   870,   877,   779,   896,   814,
    -795,   815,   816,  -795,  -795,   885,   890,   817,  -795,  -795,
     892,   819,   820,   893,   899,   925,   838,   821,   927,   928,
     822,  -795,  -795,   932,   933,   934,   828,  -795,   829,   830,
     831,   832,   833,   834,   835,   836,   839,  -795,   840,   841,
     843,   844,   305,   845,   846,   847,   848,   849,   850,   851,
     852,   853,   854,   855,   856,   857,   858,   862,  -795,  -795,
     944,   863,   864,  -795,   865,  -795,   259,  -795,   945,   949,
     966,   967,   868,  -795,   869,  -795,  -795,   968,   871,   970,
     872,  -795,  -795,  -795,  -795,  -795,   415,   415,   415,   415,
     415,   415,   415,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,   873,   875,   876,   -38,
     878,   879,   880,   881,   882,   883,   884,   886,   887,   888,
      85,   889,   891,  -795,   894,   895,   897,   898,   900,   901,
     902,    -1,   903,   904,   905,   906,   907,   908,   909,  -795,
     910,   911,  -795,  -795,   912,   913,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -191,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -171,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,   914,
     915,   417,   916,   917,   918,   919,   920,  -795,   921,   922,
    -795,   923,   924,   -30,   937,   866,  -795,  -795,  -795,  -795,
     926,   929,  -795,   930,   931,   478,   935,   936,   938,   939,
     730,   940,   941,  -795,   942,   943,   946,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -162,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,   947,   532,  -795,  -795,   950,   874,   951,  -795,
      53,  -795,  -795,  -795,  -795,   952,   955,   956,   957,  -795,
    -795,   958,   800,   959,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -116,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,   762,
     762,   762,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,   -37,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,   770,
    -795,   685,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,   -29,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,    -9,  -795,
     988,   896,   960,  -795,  -795,  -795,  -795,  -795,  -795,   961,
    -795,   962,   963,  -795,  -795,   964,   965,  -795,  -795,   969,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,    77,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
      94,  -795,  -795,  -795,  -795,  -795,  -795,  -795,   305,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
     104,  -795,  -795,   978,  -103,   972,   971,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,   105,  -795,  -795,  -795,   -38,  -795,  -795,
    -795,  -795,    -1,  -795,  -795,  -795,   417,  -795,   -30,  -795,
    -795,  -795,   986,   989,   993,   992,   997,  1000,  -795,   478,
    -795,   730,  -795,  -795,   532,   973,   976,   977,   576,  -795,
    -795,   800,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,   110,  -795,  -795,  -795,
     576,  -795
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   247,   410,   458,     0,
     473,     0,   313,   449,   289,     0,   113,   165,   347,     0,
       0,   388,     0,   122,     0,   364,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     108,   107,   643,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   630,   642,   632,   633,
     634,   635,   636,   637,   638,   639,   631,   640,   641,     0,
       0,     0,   471,     0,     0,   469,   470,     0,   531,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   601,   575,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   484,   485,   486,   529,
     493,   530,   524,   525,   526,   527,   523,   497,   487,   488,
     489,   490,   491,   492,   494,   495,   496,   498,   499,   528,
     503,   504,   505,   506,   502,   501,   507,   514,   515,   508,
     509,   510,   500,   512,   521,   522,   519,   520,   513,   511,
     517,   518,   516,     0,     0,     0,     0,     0,     0,     0,
      46,    47,    48,     0,     0,     0,   668,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   658,   659,   660,
     661,   662,   663,   664,   666,   665,   667,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      69,    66,    64,    70,    71,    65,    72,    73,    74,    55,
      68,    58,    59,    60,    56,    67,    61,    62,    63,    57,
       0,     0,     0,     0,   137,   138,   139,     0,     0,   362,
       0,     0,   360,   361,     0,   109,     0,     0,     0,     0,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   629,     0,     0,     0,     0,   283,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   250,   251,   254,   256,   257,   258,   259,
     260,   261,   262,   263,   252,   253,   255,   264,   265,   266,
       0,     0,     0,     0,     0,     0,     0,   438,     0,     0,
       0,     0,     0,     0,     0,     0,   413,   414,   415,   416,
     417,   418,   419,   421,   420,   423,   427,   424,   425,   426,
     422,   464,     0,     0,     0,   461,   462,   463,     0,     0,
     468,   479,     0,     0,     0,   476,   477,   478,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,     0,     0,   330,
       0,     0,     0,     0,     0,     0,   316,   317,   318,   319,
     324,   320,   321,   322,   323,   455,     0,     0,     0,   452,
     453,   454,     0,     0,     0,   291,     0,   301,     0,   299,
     300,   302,   303,    49,     0,     0,     0,    45,     0,     0,
       0,     0,   116,   117,   118,     0,     0,     0,   214,     0,
       0,     0,     0,   188,     0,     0,     0,   168,   169,   170,
     171,   172,   175,   176,   177,   174,   173,   178,     0,     0,
       0,     0,     0,   350,   351,   352,   353,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   657,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,   396,     0,   391,   392,   393,   140,     0,
       0,   136,     0,     0,     0,     0,     0,     0,     0,   125,
     126,   128,   127,   129,     0,     0,   359,     0,     0,   374,
       0,     0,   367,   368,   369,   370,     0,     0,     0,   103,
       0,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   628,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   249,   428,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   412,
       0,     0,     0,   460,     0,   467,     0,     0,     0,   475,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   482,   325,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   315,
       0,     0,     0,   451,   304,     0,     0,     0,     0,     0,
     298,     0,     0,    44,   119,     0,     0,     0,   115,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   354,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   656,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,   394,
       0,     0,     0,   390,     0,   135,     0,   130,     0,     0,
       0,     0,     0,   124,     0,   358,   371,     0,     0,     0,
       0,   366,   112,   111,   110,   654,    28,    28,    28,    28,
      28,    28,    28,    30,    29,   655,   644,   645,   646,   647,
     648,   649,   650,   653,   651,   652,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,   248,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   411,
       0,     0,   459,   472,     0,     0,   474,   545,   549,   532,
     533,   564,   536,   627,   572,   537,   538,   569,   544,   543,
     552,   542,   539,   540,   548,   547,   546,   570,   534,   625,
     626,   568,   611,   605,   621,   606,   607,   608,   616,   624,
     609,   618,   622,   612,   623,   613,   617,   610,   620,   615,
     614,   619,     0,   604,   584,   585,   586,   579,   597,   580,
     581,   582,   592,   600,   583,   594,   598,   588,   599,   589,
     593,   587,   596,   591,   590,   595,     0,   578,   565,   563,
     566,   571,   567,   554,   561,   562,   559,   560,   555,   556,
     557,   558,   573,   574,   541,   551,   550,   553,   535,     0,
       0,     0,     0,     0,     0,     0,     0,   314,     0,     0,
     450,     0,     0,     0,   309,   305,   308,   290,    50,    51,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,     0,     0,     0,   348,   672,   669,
     670,   671,   676,   675,   677,   673,   674,    99,    94,   102,
      93,    89,    87,    88,    86,     0,    85,    90,    91,   100,
     101,    92,    96,    95,    77,    76,    81,    78,    80,    79,
      97,    98,     0,     0,   389,   141,     0,     0,     0,   153,
       0,   145,   146,   148,   147,     0,     0,     0,     0,   123,
     363,     0,     0,     0,   365,    31,    32,    33,    34,    35,
      36,    37,   278,   279,   271,   288,   287,     0,   286,   272,
     274,   282,   275,   273,   281,   268,   280,   270,   269,    38,
      38,    38,    40,    39,   276,   277,   433,   436,   437,   447,
     444,   430,   445,   442,   443,     0,   441,   446,   429,   435,
     432,   434,   448,   431,   465,   466,   480,   481,   602,     0,
     576,     0,   328,   329,   339,   335,   336,   338,   343,   340,
     341,   334,   342,   337,     0,   333,   327,   346,   345,   344,
     326,   457,   456,   312,   311,   296,   297,   295,     0,   294,
       0,     0,     0,   120,   121,   187,   184,   234,   246,   221,
     230,     0,   219,   224,   240,     0,   233,   238,   244,   223,
     226,   235,   237,   241,   231,   239,   227,   245,   229,   236,
     225,   228,     0,   217,   180,   182,   185,   186,   197,   198,
     199,   192,   210,   193,   194,   195,   205,   213,   196,   207,
     211,   201,   212,   202,   206,   200,   209,   204,   203,   208,
       0,   191,   181,   183,   357,   355,   356,    83,     0,   395,
     400,   406,   409,   402,   408,   403,   407,   405,   401,   404,
       0,   399,   149,     0,     0,     0,     0,   144,   132,   131,
     133,   134,   372,   378,   384,   387,   380,   386,   381,   385,
     383,   379,   382,     0,   377,   373,   284,     0,    41,    42,
      43,   439,     0,   603,   577,   331,     0,   292,     0,   310,
     307,   306,     0,     0,     0,     0,     0,     0,   215,     0,
     189,     0,    84,   397,     0,     0,     0,     0,     0,   143,
     375,     0,   285,   440,   332,   293,   220,   243,   218,   242,
     232,   222,   216,   190,   398,   150,   152,   151,   163,   162,
     158,   160,   164,   161,   157,   159,     0,   156,   376,   154,
       0,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -795,  -795,  -795,  -794,  -310,  -769,  -639,  -795,  -795,   979,
    -795,  -795,  -795,  -795,   954,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,   -66,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    1086,  -795,  -795,  -795,  -795,  -795,  -795,   671,  -795,  -795,
    -795,  -795,  -795,   581,  -795,  -795,  -795,  -795,  -795,  -795,
     974,  -795,  -795,  -795,  -795,   107,  -795,  -795,  -795,  -795,
    -795,  -151,  -795,  -795,  -795,   664,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -108,  -795,  -795,
    -795,  -121,  -795,  -795,  -795,   975,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,   -83,  -795,  -795,  -795,  -795,  -795,
     -92,  -795,   708,  -795,  -795,  -795,    36,  -795,  -795,  -795,
    -795,  -795,   723,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
     -77,  -795,  -795,  -795,  -795,  -795,  -795,   683,  -795,  -795,
    -795,  -795,  -795,   980,  -795,  -795,  -795,  -795,   599,  -795,
    -795,  -795,  -795,  -795,   -94,  -795,  -795,  -795,   639,  -795,
    -795,  -795,  -795,   -80,  -795,  -795,  -795,   981,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,   -56,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,   743,  -795,
    -795,  -795,  -795,  -795,   823,  -795,  -795,  -795,  -795,  1104,
    -795,  -795,  -795,  -795,   824,  -795,  -795,  -795,  -795,  1054,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,    89,  -795,  -795,  -795,    95,  -795,
    -795,  -795,  -795,  -795,  1128,  -795,  -795,  -795,  -795,  -795,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,   990,
    -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795,  -795
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   833,   834,  1102,  1103,    27,   219,   220,
     221,   222,    28,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   553,  1035,  1036,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,    29,    77,
      78,    79,    80,    81,    30,    63,   501,   502,   503,   504,
      31,    70,   588,   589,   590,   591,   592,   593,    32,   293,
     294,   295,   296,   297,  1060,  1061,  1062,  1063,  1064,  1245,
    1326,  1327,    33,    64,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   757,  1220,  1221,   527,   752,
    1192,  1193,    34,    53,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   628,  1087,  1088,    35,    61,   487,   737,  1158,
    1159,   488,   489,   490,  1162,   995,   996,   491,   492,    36,
      59,   465,   466,   467,   468,   469,   470,   471,   722,  1144,
    1145,   472,   473,   474,    37,    65,   532,   533,   534,   535,
     536,    38,   301,   302,   303,    39,    72,   601,   602,   603,
     604,   605,   818,  1263,  1264,    40,    68,   574,   575,   576,
     577,   801,  1240,  1241,    41,    54,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   650,  1115,  1116,
     386,   387,   388,   389,   390,    42,    60,   478,   479,   480,
     481,    43,    55,   394,   395,   396,   397,    44,   114,   115,
     116,    45,    57,   404,   405,   406,   407,    46,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   434,   956,   957,   209,   433,   932,   933,   210,
     211,   212,    47,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    48,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     861,   862,   612,   291,   482,   615,   616,  1113,   618,   619,
      73,   860,   498,   299,  1085,   112,   391,   597,  1155,   703,
      51,   391,   498,   704,   299,    52,   705,    56,   401,   291,
     706,   528,  1075,  1076,  1077,  1078,  1079,  1080,  1081,    74,
     482,   216,   571,    58,  1128,   865,   866,    75,  1129,   401,
     528,   360,   118,   361,  1056,   362,   571,   119,   120,   483,
     121,   122,   475,    62,  1130,   123,   305,   484,  1131,   485,
     363,   529,    66,  1227,    67,   124,   125,  1228,   113,   392,
      69,   216,   475,   126,   392,    71,   127,   128,   129,   364,
     529,  1086,   112,   130,   499,   483,  1099,  1100,  1101,   671,
     109,   673,   674,   484,   499,   485,   365,  1296,   366,   110,
     131,   132,   684,   530,   111,    76,   367,   689,   300,  1266,
     505,   133,   598,  1267,   134,   135,   698,   699,   368,   300,
     486,   117,   530,   402,   306,   136,   583,   213,   712,   506,
     714,   715,   137,   217,   138,   393,   139,   572,   140,   214,
     393,   141,   142,   247,   402,   113,   369,   403,   507,  1057,
     531,   572,    82,   143,   218,  1156,   486,   215,   144,   145,
     456,   146,   147,   148,  1157,   223,   149,   370,   403,   531,
     248,  -142,   249,   217,   224,   508,   225,    83,    84,   457,
     500,   476,    49,    50,    85,   290,   371,   597,  1271,   860,
     500,   150,  1272,  1114,   218,   372,  1275,  -142,   458,   250,
    1276,   476,   151,   152,   153,   154,   155,   156,   157,   251,
     298,   304,    86,    87,    88,   509,  1277,   307,   292,   770,
    1278,   252,   253,   254,   308,   459,    89,    90,    91,   739,
     599,   584,   510,   600,   255,   309,    92,    93,   256,   325,
      94,   226,   820,  1058,   292,   373,   662,   747,   257,   595,
    1056,   258,   259,   668,   580,   573,   326,   327,   158,   159,
     160,   328,   161,   162,   511,   512,   496,  1059,   374,   573,
     311,   163,   312,   164,   227,   766,   658,   454,   477,  1246,
     260,   802,   460,   228,   229,   230,   313,   732,   231,   232,
     461,   462,   598,   233,   234,   235,   261,   585,   477,   262,
     263,   264,  1288,   314,   329,   582,  1289,   848,   493,   548,
     463,   852,  1031,    73,   855,   586,   513,   399,   859,  1290,
    1268,  1269,  1270,  1291,   330,   331,   332,   315,   333,  1293,
    1300,   587,   334,  1294,  1301,  1329,   514,   335,   806,  1330,
     515,   316,    74,   317,   336,   760,   505,   265,   318,   319,
      75,   320,   321,   337,   338,  1057,   322,   398,   408,   409,
     410,   812,   411,   606,   339,   506,   412,   118,   413,   414,
     266,   267,   119,   120,   415,   121,   122,   416,   569,   417,
     123,   418,   419,   420,   507,   340,   464,   323,   421,   578,
     124,   125,   583,  1032,   422,   728,   423,  1033,   126,   424,
     425,   127,   128,   129,   456,   426,   427,   428,   130,   429,
     599,   508,   430,   600,   431,   432,   435,   436,    76,   437,
     438,   439,  1134,   457,   607,   131,   132,   440,   441,   442,
     341,   443,   444,   445,   446,   447,   133,   448,   449,   134,
     135,   450,   458,   451,   452,   453,   494,  1135,   495,  1058,
     136,   509,   537,   538,   539,  1034,   540,   137,   541,   138,
     542,   139,   543,   140,   544,   545,   141,   142,   510,   459,
     549,   550,  1167,  1059,   641,   551,   546,   552,   143,  1136,
     554,   555,   556,   144,   145,   557,   146,   147,   148,  1168,
    1169,   149,   558,   559,   560,   561,   562,   584,   563,  1170,
     511,   512,   564,   565,   566,   360,   567,   361,   568,   362,
     579,   247,   594,   608,  1137,  1138,   150,   609,   610,   611,
    1139,   613,   614,   617,   363,   620,   460,   151,   152,   153,
     154,   155,   156,   157,   461,   462,  1171,  1172,   248,  1173,
     249,   621,   622,   364,  1140,   623,   624,   625,   664,   643,
     670,   626,   513,   627,   463,   629,   630,   631,   632,  1141,
     365,   633,   366,   585,   634,   635,   636,   250,   637,   638,
     367,  1174,   514,   639,   640,   644,   515,   251,   645,  1175,
     646,   586,   368,   158,   159,   160,   647,   161,   162,   252,
     253,   254,   648,  1230,   649,  1297,   163,   587,   164,   651,
     652,  1176,   255,  1177,  1178,   653,   256,   654,   655,   656,
     369,   657,   660,   661,   665,   666,   257,   672,   667,   258,
     259,  1179,  1142,   676,   695,   678,   675,   679,   677,   680,
     464,   370,   681,   682,   683,  1318,   696,  1319,   685,   686,
     687,  1143,   688,   690,  1180,   611,   691,   692,   260,  1181,
     371,   693,   694,  1182,   697,   700,   701,  1183,  1231,   372,
     702,   707,  1184,   708,   261,   709,  1185,   262,   263,   264,
     826,   827,   828,   829,   830,   831,   832,  1186,   710,  1187,
    1188,   711,  1189,     2,     3,  1320,   713,     4,   716,   717,
    1232,   718,   719,  1190,   778,   734,   325,   720,  1233,     5,
     741,  1191,  1321,     6,   721,     7,   742,  1234,   768,   373,
     743,   723,     8,   326,   327,   265,   724,   725,   328,   726,
     727,   730,   731,   934,     9,   935,   936,   735,   736,    10,
      11,  1235,   374,  1236,  1237,   738,   744,   745,   266,   267,
     746,  1322,  1323,   749,   750,   751,   769,  1238,    12,   762,
     753,   771,    13,   773,   754,  1239,   755,   756,   758,   759,
     772,   329,   774,   775,   776,    14,   779,   780,  1198,   781,
    1199,  1200,   763,   764,   765,   777,   782,   783,   784,   785,
     786,   330,   331,   332,   787,   333,   788,    15,    16,   334,
     789,   790,   791,  1324,   335,   792,   793,   794,   795,  1325,
     796,   336,    17,   798,   797,   799,   804,   800,   912,   805,
     337,   338,   807,   814,   808,   846,   815,   809,   816,    18,
     810,   339,   811,   817,   819,   847,   822,   823,   824,   825,
     835,    19,    20,   836,   837,   838,   839,   840,   841,   842,
     843,   844,   340,   845,   937,   938,   939,   849,   850,   940,
     941,   851,   942,   943,   853,   944,    21,   945,   854,   856,
     946,  1253,   947,   948,   857,   858,   860,   863,   949,    22,
     864,   867,   950,   868,    23,   869,   951,   952,   953,    24,
     871,   870,    25,   954,   872,   873,   874,   341,   955,  1201,
    1202,  1203,   875,   876,  1204,  1205,   877,  1206,  1207,   878,
    1208,   880,  1209,   881,   884,  1210,   879,  1211,  1212,   882,
     885,   979,   883,  1213,   886,   887,   888,  1214,   980,   889,
     981,  1215,  1216,  1217,   890,   891,  1254,   892,  1218,   913,
     914,   915,   893,  1219,   916,   917,   982,   918,   919,   226,
     920,   894,   921,   895,    82,   922,   983,   923,   924,   896,
     897,   898,   899,   925,   900,   984,   901,   926,  1255,   902,
     903,   927,   928,   929,   904,   905,  1256,   906,   930,    83,
      84,   907,   227,   931,   908,  1257,    85,   985,   986,   988,
     909,   228,   229,   230,   910,   989,   231,   232,   991,   911,
     958,   233,   234,   235,   959,   992,   960,   961,   962,  1258,
     994,  1259,  1260,  1000,    86,    87,    88,   993,  1001,   963,
    1003,  1006,   964,   965,   966,  1261,   967,  1007,    89,    90,
      91,   968,   969,  1262,   970,  1004,   971,   972,    92,    93,
     973,   974,    94,   975,   976,   977,   978,   987,   990,   997,
     998,   999,  1002,  1008,  1009,  1011,  1012,  1013,  1005,  1010,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1052,  1065,  1026,  1027,  1028,  1066,  1029,  1030,
    1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,
    1047,  1048,  1049,  1050,  1067,  1068,  1071,  1051,  1073,  1054,
    1055,  1053,  1279,  1069,  1070,  1161,  1295,  1074,  1082,  1072,
    1083,  1084,  1243,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1306,  1096,  1097,  1098,  1104,  1307,  1105,  1308,  1309,  1106,
    1107,  1310,  1108,  1109,  1311,  1110,  1111,  1112,  1117,  1118,
    1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1132,
    1133,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,
    1160,  1163,  1292,   310,  1164,  1165,  1166,  1247,  1312,   813,
    1194,  1195,   748,  1196,  1197,  1222,  1223,  1224,  1225,  1331,
     761,  1226,  1229,  1313,  1302,  1242,  1305,  1248,   729,  1244,
    1249,  1250,  1251,  1252,  1265,  1281,   740,  1280,   497,  1304,
     821,  1282,  1283,  1284,  1285,  1286,  1299,  1328,  1315,  1287,
    1298,  1316,  1317,   803,  1314,   767,  1303,   663,   400,   455,
    1274,   733,   570,   324,  1273,     0,   547,     0,   669,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   581,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   596,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   642,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   659
};

static const yytype_int16 yycheck[] =
{
     639,   640,   312,     1,     1,   315,   316,     8,   318,   319,
       1,   114,     1,     1,    52,     1,     1,     1,    48,   216,
     237,     1,     1,   220,     1,   237,   216,   237,     1,     1,
     220,     1,   826,   827,   828,   829,   830,   831,   832,    30,
       1,     1,     1,   237,   235,   183,   184,    38,   239,     1,
       1,     1,     1,     3,     1,     5,     1,     6,     7,    56,
       9,    10,     1,   237,   235,    14,   235,    64,   239,    66,
      20,    41,   237,   235,   237,    24,    25,   239,    64,    64,
     237,     1,     1,    32,    64,   237,    35,    36,    37,    39,
      41,   129,     1,    42,    83,    56,    11,    12,    13,   409,
     237,   411,   412,    64,    83,    66,    56,   210,    58,   237,
      59,    60,   422,    83,   237,   106,    66,   427,   106,   235,
       1,    70,   106,   239,    73,    74,   436,   437,    78,   106,
     127,   237,    83,   106,   238,    84,     1,   237,   448,    20,
     450,   451,    91,   103,    93,   130,    95,   106,    97,   237,
     130,   100,   101,     1,   106,    64,   106,   130,    39,   106,
     130,   106,     1,   112,   124,   195,   127,   237,   117,   118,
       1,   120,   121,   122,   204,   237,   125,   127,   130,   130,
      28,   179,    30,   103,   237,    66,   237,    26,    27,    20,
     179,   130,   235,   236,    33,   237,   146,     1,   235,   114,
     179,   150,   239,   204,   124,   155,   235,   179,    39,    57,
     239,   130,   161,   162,   163,   164,   165,   166,   167,    67,
     237,   237,    61,    62,    63,   106,   235,   238,   226,   539,
     239,    79,    80,    81,   238,    66,    75,    76,    77,   236,
     224,   106,   123,   227,    92,   236,    85,    86,    96,     1,
      89,     1,   236,   200,   226,   205,   236,   236,   106,   236,
       1,   109,   110,   236,   236,   224,    18,    19,   217,   218,
     219,    23,   221,   222,   155,   156,   236,   224,   228,   224,
     238,   230,   238,   232,    34,   236,   236,   236,   227,   236,
     138,   236,   123,    43,    44,    45,   238,   236,    48,    49,
     131,   132,   106,    53,    54,    55,   154,   172,   227,   157,
     158,   159,   235,   238,    66,   179,   239,   627,   235,   235,
     151,   631,    17,     1,   634,   190,   207,   236,   638,   235,
    1099,  1100,  1101,   239,    86,    87,    88,   238,    90,   235,
     235,   206,    94,   239,   239,   235,   227,    99,   237,   239,
     231,   238,    30,   238,   106,   236,     1,   205,   238,   238,
      38,   238,   238,   115,   116,   106,   238,   238,   238,   238,
     238,   236,   238,   128,   126,    20,   238,     1,   238,   238,
     228,   229,     6,     7,   238,     9,    10,   238,   236,   238,
      14,   238,   238,   238,    39,   147,   227,   236,   238,   235,
      24,    25,     1,    98,   238,   236,   238,   102,    32,   238,
     238,    35,    36,    37,     1,   238,   238,   238,    42,   238,
     224,    66,   238,   227,   238,   238,   238,   238,   106,   238,
     238,   238,    15,    20,   128,    59,    60,   238,   238,   238,
     192,   238,   238,   238,   238,   238,    70,   238,   238,    73,
      74,   238,    39,   238,   238,   238,   238,    40,   238,   200,
      84,   106,   238,   238,   238,   160,   238,    91,   238,    93,
     238,    95,   238,    97,   238,   238,   100,   101,   123,    66,
     238,   238,     4,   224,   236,   238,   236,   238,   112,    72,
     238,   238,   238,   117,   118,   238,   120,   121,   122,    21,
      22,   125,   238,   238,   238,   238,   238,   106,   238,    31,
     155,   156,   238,   238,   238,     1,   238,     3,   238,     5,
     238,     1,   238,   128,   107,   108,   150,   235,   114,   114,
     113,   216,   114,   114,    20,   114,   123,   161,   162,   163,
     164,   165,   166,   167,   131,   132,    68,    69,    28,    71,
      30,   114,   114,    39,   137,   235,   235,   238,   128,   235,
     216,   238,   207,   238,   151,   238,   238,   238,   238,   152,
      56,   238,    58,   172,   238,   238,   238,    57,   238,   238,
      66,   103,   227,   238,   238,   238,   231,    67,   238,   111,
     238,   190,    78,   217,   218,   219,   238,   221,   222,    79,
      80,    81,   238,    71,   238,  1244,   230,   206,   232,   238,
     238,   133,    92,   135,   136,   238,    96,   238,   238,   238,
     106,   238,   238,   238,   235,   238,   106,   114,   238,   109,
     110,   153,   215,   114,   238,   114,   216,   114,   216,   114,
     227,   127,   216,   216,   216,    69,   238,    71,   114,   114,
     114,   234,   114,   114,   176,   114,   114,   114,   138,   181,
     146,   114,   216,   185,   216,   216,   216,   189,   136,   155,
     216,   216,   194,   216,   154,   216,   198,   157,   158,   159,
     139,   140,   141,   142,   143,   144,   145,   209,   216,   211,
     212,   114,   214,     0,     1,   119,   216,     4,   216,   114,
     168,   235,   235,   225,   114,   235,     1,   238,   176,    16,
     128,   233,   136,    20,   238,    22,   128,   185,   216,   205,
     235,   238,    29,    18,    19,   205,   238,   238,    23,   238,
     238,   238,   238,    48,    41,    50,    51,   238,   238,    46,
      47,   209,   228,   211,   212,   238,   235,   238,   228,   229,
     238,   175,   176,   235,   238,   238,   216,   225,    65,   235,
     238,   128,    69,   128,   238,   233,   238,   238,   238,   238,
     216,    66,   216,   216,   216,    82,   128,   216,    48,   128,
      50,    51,   238,   238,   238,   235,   238,   128,   128,   114,
     114,    86,    87,    88,   128,    90,   128,   104,   105,    94,
     128,   128,   128,   227,    99,   128,   128,   128,   128,   233,
     128,   106,   119,   235,   128,   235,   216,   238,    48,   235,
     115,   116,   235,   128,   238,   114,   235,   238,   235,   136,
     238,   126,   238,   238,   238,   114,   235,   235,   235,   235,
     235,   148,   149,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   147,   235,   169,   170,   171,   238,   114,   174,
     175,   114,   177,   178,   114,   180,   173,   182,   114,   128,
     185,    71,   187,   188,   114,   114,   114,   235,   193,   186,
     128,   128,   197,   216,   191,   128,   201,   202,   203,   196,
     238,   128,   199,   208,   128,   128,   114,   192,   213,   169,
     170,   171,   128,   128,   174,   175,   128,   177,   178,   128,
     180,   128,   182,   128,   128,   185,   235,   187,   188,   235,
     128,   128,   235,   193,   235,   235,   235,   197,   216,   235,
     238,   201,   202,   203,   235,   235,   136,   235,   208,   169,
     170,   171,   235,   213,   174,   175,   128,   177,   178,     1,
     180,   235,   182,   235,     1,   185,   114,   187,   188,   235,
     235,   235,   235,   193,   235,   128,   235,   197,   168,   235,
     235,   201,   202,   203,   235,   235,   176,   235,   208,    26,
      27,   235,    34,   213,   235,   185,    33,   128,   128,   128,
     235,    43,    44,    45,   235,   128,    48,    49,   128,   235,
     235,    53,    54,    55,   235,   128,   235,   235,   235,   209,
     114,   211,   212,   128,    61,    62,    63,   238,   128,   235,
     128,   128,   235,   235,   235,   225,   235,   128,    75,    76,
      77,   235,   235,   233,   235,   216,   235,   235,    85,    86,
     235,   235,    89,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   128,   216,   128,   128,   235,   238,   238,
     128,   128,   128,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   128,   128,   235,   235,   235,   128,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   128,   128,   128,   235,   128,   235,
     235,   238,   114,   235,   235,   239,   128,   235,   235,   238,
     235,   235,   238,   235,   235,   235,   235,   235,   235,   235,
     134,   235,   235,   235,   235,   136,   235,   134,   136,   235,
     235,   134,   235,   235,   134,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     223,   235,  1228,    77,   235,   235,   235,  1060,  1289,   588,
     235,   235,   501,   235,   235,   235,   235,   235,   235,  1330,
     516,   235,   235,  1291,  1267,   235,  1278,   235,   465,   238,
     235,   235,   235,   235,   235,   235,   488,  1161,   219,  1276,
     601,   240,   240,   240,   240,   240,   235,  1301,   235,   240,
     238,   235,   235,   574,  1294,   532,  1272,   394,   114,   165,
    1131,   478,   268,    95,  1129,    -1,   236,    -1,   404,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   293,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   342,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   375
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   242,     0,     1,     4,    16,    20,    22,    29,    41,
      46,    47,    65,    69,    82,   104,   105,   119,   136,   148,
     149,   173,   186,   191,   196,   199,   243,   248,   253,   279,
     285,   291,   299,   313,   333,   356,   370,   385,   392,   396,
     406,   415,   436,   442,   448,   452,   458,   513,   528,   235,
     236,   237,   237,   334,   416,   443,   237,   453,   237,   371,
     437,   357,   237,   286,   314,   386,   237,   237,   407,   237,
     292,   237,   397,     1,    30,    38,   106,   280,   281,   282,
     283,   284,     1,    26,    27,    33,    61,    62,    63,    75,
      76,    77,    85,    86,    89,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   237,
     237,   237,     1,    64,   449,   450,   451,   237,     1,     6,
       7,     9,    10,    14,    24,    25,    32,    35,    36,    37,
      42,    59,    60,    70,    73,    74,    84,    91,    93,    95,
      97,   100,   101,   112,   117,   118,   120,   121,   122,   125,
     150,   161,   162,   163,   164,   165,   166,   167,   217,   218,
     219,   221,   222,   230,   232,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   506,
     510,   511,   512,   237,   237,   237,     1,   103,   124,   249,
     250,   251,   252,   237,   237,   237,     1,    34,    43,    44,
      45,    48,    49,    53,    54,    55,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,     1,    28,    30,
      57,    67,    79,    80,    81,    92,    96,   106,   109,   110,
     138,   154,   157,   158,   159,   205,   228,   229,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     237,     1,   226,   300,   301,   302,   303,   304,   237,     1,
     106,   393,   394,   395,   237,   235,   238,   238,   238,   236,
     281,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   236,   515,     1,    18,    19,    23,    66,
      86,    87,    88,    90,    94,    99,   106,   115,   116,   126,
     147,   192,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
       1,     3,     5,    20,    39,    56,    58,    66,    78,   106,
     127,   146,   155,   205,   228,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   431,   432,   433,   434,
     435,     1,    64,   130,   444,   445,   446,   447,   238,   236,
     450,     1,   106,   130,   454,   455,   456,   457,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   507,   503,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   236,   460,     1,    20,    39,    66,
     123,   131,   132,   151,   227,   372,   373,   374,   375,   376,
     377,   378,   382,   383,   384,     1,   130,   227,   438,   439,
     440,   441,     1,    56,    64,    66,   127,   358,   362,   363,
     364,   368,   369,   235,   238,   238,   236,   250,     1,    83,
     179,   287,   288,   289,   290,     1,    20,    39,    66,   106,
     123,   155,   156,   207,   227,   231,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   329,     1,    41,
      83,   130,   387,   388,   389,   390,   391,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   236,   530,   235,   238,
     238,   238,   238,   263,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   236,
     255,     1,   106,   224,   408,   409,   410,   411,   235,   238,
     236,   301,   179,     1,   106,   172,   190,   206,   293,   294,
     295,   296,   297,   298,   238,   236,   394,     1,   106,   224,
     227,   398,   399,   400,   401,   402,   128,   128,   128,   235,
     114,   114,   245,   216,   114,   245,   245,   114,   245,   245,
     114,   114,   114,   235,   235,   238,   238,   238,   353,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   236,   336,   235,   238,   238,   238,   238,   238,   238,
     428,   238,   238,   238,   238,   238,   238,   238,   236,   418,
     238,   238,   236,   445,   128,   235,   238,   238,   236,   455,
     216,   245,   114,   245,   245,   216,   114,   216,   114,   114,
     114,   216,   216,   216,   245,   114,   114,   114,   114,   245,
     114,   114,   114,   114,   216,   238,   238,   216,   245,   245,
     216,   216,   216,   216,   220,   216,   220,   216,   216,   216,
     216,   114,   245,   216,   245,   245,   216,   114,   235,   235,
     238,   238,   379,   238,   238,   238,   238,   238,   236,   373,
     238,   238,   236,   439,   235,   238,   238,   359,   238,   236,
     363,   128,   128,   235,   235,   238,   238,   236,   288,   235,
     238,   238,   330,   238,   238,   238,   238,   326,   238,   238,
     236,   316,   235,   238,   238,   238,   236,   388,   216,   216,
     245,   128,   216,   128,   216,   216,   216,   235,   114,   128,
     216,   128,   238,   128,   128,   114,   114,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   235,   235,
     238,   412,   236,   409,   216,   235,   237,   235,   238,   238,
     238,   238,   236,   294,   128,   235,   235,   238,   403,   238,
     236,   399,   235,   235,   235,   235,   139,   140,   141,   142,
     143,   144,   145,   244,   245,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   114,   114,   245,   238,
     114,   114,   245,   114,   114,   245,   128,   114,   114,   245,
     114,   247,   247,   235,   128,   183,   184,   128,   216,   128,
     128,   238,   128,   128,   114,   128,   128,   128,   128,   235,
     128,   128,   235,   235,   128,   128,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,    48,   169,   170,   171,   174,   175,   177,   178,
     180,   182,   185,   187,   188,   193,   197,   201,   202,   203,
     208,   213,   508,   509,    48,    50,    51,   169,   170,   171,
     174,   175,   177,   178,   180,   182,   185,   187,   188,   193,
     197,   201,   202,   203,   208,   213,   504,   505,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   128,
     216,   238,   128,   114,   128,   128,   128,   235,   128,   128,
     235,   128,   128,   238,   114,   366,   367,   235,   235,   235,
     128,   128,   235,   128,   216,   238,   128,   128,   128,   216,
     238,   128,   128,   235,   128,   128,   128,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,    17,    98,   102,   160,   264,   265,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   128,   238,   235,   235,     1,   106,   200,   224,
     305,   306,   307,   308,   309,   128,   128,   128,   128,   235,
     235,   128,   238,   128,   235,   244,   244,   244,   244,   244,
     244,   244,   235,   235,   235,    52,   129,   354,   355,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,    11,
      12,    13,   246,   247,   235,   235,   235,   235,   235,   235,
     235,   235,   235,     8,   204,   429,   430,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   239,
     235,   239,   235,   235,    15,    40,    72,   107,   108,   113,
     137,   152,   215,   234,   380,   381,   235,   235,   235,   235,
     235,   235,   235,   235,   235,    48,   195,   204,   360,   361,
     223,   239,   365,   235,   235,   235,   235,     4,    21,    22,
      31,    68,    69,    71,   103,   111,   133,   135,   136,   153,
     176,   181,   185,   189,   194,   198,   209,   211,   212,   214,
     225,   233,   331,   332,   235,   235,   235,   235,    48,    50,
      51,   169,   170,   171,   174,   175,   177,   178,   180,   182,
     185,   187,   188,   193,   197,   201,   202,   203,   208,   213,
     327,   328,   235,   235,   235,   235,   235,   235,   239,   235,
      71,   136,   168,   176,   185,   209,   211,   212,   225,   233,
     413,   414,   235,   238,   238,   310,   236,   306,   235,   235,
     235,   235,   235,    71,   136,   168,   176,   185,   209,   211,
     212,   225,   233,   404,   405,   235,   235,   239,   246,   246,
     246,   235,   239,   509,   505,   235,   239,   235,   239,   114,
     367,   235,   240,   240,   240,   240,   240,   240,   235,   239,
     235,   239,   265,   235,   239,   128,   210,   247,   238,   235,
     235,   239,   355,   430,   381,   361,   134,   136,   134,   136,
     134,   134,   332,   328,   414,   235,   235,   235,    69,    71,
     119,   136,   175,   176,   227,   233,   311,   312,   405,   235,
     239,   312
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   241,   242,   242,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   244,   244,
     245,   245,   245,   245,   245,   245,   245,   245,   246,   246,
     247,   247,   247,   247,   248,   249,   249,   250,   250,   250,
     251,   252,   253,   254,   254,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   256,   257,   258,   259,
     260,   261,   263,   262,   264,   264,   265,   265,   265,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   280,   281,   281,   281,   281,
     282,   283,   284,   286,   285,   287,   287,   288,   288,   288,
     289,   290,   292,   291,   293,   293,   294,   294,   294,   294,
     294,   295,   296,   297,   298,   299,   300,   300,   301,   301,
     301,   302,   304,   303,   305,   305,   306,   306,   306,   306,
     307,   308,   308,   310,   309,   311,   311,   312,   312,   312,
     312,   312,   312,   312,   312,   314,   313,   315,   315,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   326,   325,
     327,   327,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   330,   329,   331,   331,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   334,   333,   335,
     335,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   353,   352,   354,   354,   355,   355,   357,
     356,   359,   358,   360,   360,   361,   361,   361,   362,   362,
     363,   363,   363,   363,   363,   365,   364,   366,   366,   367,
     367,   368,   369,   371,   370,   372,   372,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   374,   375,   376,   377,
     379,   378,   380,   380,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   382,   383,   384,   386,   385,   387,
     387,   388,   388,   388,   388,   389,   390,   391,   392,   393,
     393,   394,   394,   395,   397,   396,   398,   398,   399,   399,
     399,   399,   400,   401,   403,   402,   404,   404,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   407,   406,
     408,   408,   409,   409,   409,   410,   412,   411,   413,   413,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     416,   415,   417,   417,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   426,   428,   427,
     429,   429,   430,   430,   431,   432,   433,   434,   435,   437,
     436,   438,   438,   439,   439,   439,   440,   441,   443,   442,
     444,   444,   445,   445,   445,   446,   447,   448,   449,   449,
     450,   450,   451,   453,   452,   454,   454,   455,   455,   455,
     456,   457,   458,   459,   459,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     488,   489,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   503,   502,   504,   504,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   507,   506,   508,   508,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   510,   511,   512,   513,   514,
     514,   515,   515,   515,   515,   515,   515,   515,   515,   515,
     515,   515,   515,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   529,   530,
     530,   530,   530,   530,   530,   530,   530,   530,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     0,     1,
       2,     3,     3,     3,     5,     2,     1,     1,     1,     2,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     2,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     2,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     5,     2,     1,     1,     1,
       2,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     0,
       6,     0,     5,     3,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     0,     5,     3,     1,     1,
       3,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     5,     2,
       1,     1,     1,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     2,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     4,     4,     4,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     4,     4,     5,     2,     1,
       1,     1,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
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

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 410 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 438 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 444 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 480 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_certificate_file);
    ConfigServerInfo.ssl_certificate_file = xstrdup(yylval.string);
  }
}
#line 3002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 489 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 3014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 498 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_param_file);
    ConfigServerInfo.ssl_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 507 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_cipher_list);
    ConfigServerInfo.ssl_cipher_list = xstrdup(yylval.string);
  }
}
#line 3038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 516 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_message_digest_algorithm);
    ConfigServerInfo.ssl_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3050 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 525 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_elliptic_curve);
    ConfigServerInfo.ssl_dh_elliptic_curve = xstrdup(yylval.string);
  }
}
#line 3062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 534 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options = 0;
}
#line 3071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 541 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_STANDARD;
#endif
}
#line 3082 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 547 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MEMORY_CACHE;
#endif
}
#line 3093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 553 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MMAP_CACHE;
#endif
}
#line 3104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 559 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_CHECK_CACHE;
#endif
}
#line 3115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 567 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.libgeoip_ipv4_database_file);
    ConfigServerInfo.libgeoip_ipv4_database_file = xstrdup(yylval.string);

#ifdef HAVE_LIBGEOIP
    if (GeoIPv4_ctx)
      GeoIP_delete(GeoIPv4_ctx);
    GeoIPv4_ctx = GeoIP_open(yylval.string, ConfigServerInfo.libgeoip_database_options);
#endif
  }
}
#line 3133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 582 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.libgeoip_ipv6_database_file);
    ConfigServerInfo.libgeoip_ipv6_database_file = xstrdup(yylval.string);

#ifdef HAVE_LIBGEOIP
    if (GeoIPv6_ctx)
      GeoIP_delete(GeoIPv6_ctx);
    GeoIPv6_ctx = GeoIP_open(yylval.string, ConfigServerInfo.libgeoip_database_options);
#endif
  }
}
#line 3151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 597 "conf_parser.y" /* yacc.c:1646  */
    {
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.name)
  {
    if (valid_servname(yylval.string))
      ConfigServerInfo.name = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 612 "conf_parser.y" /* yacc.c:1646  */
    {
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.sid)
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
#line 3187 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 627 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 637 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')))
      *p = '\0';

    xfree(ConfigServerInfo.network_name);
    ConfigServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3217 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 651 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 660 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res);

      memcpy(&ConfigServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ConfigServerInfo.ip.ss.ss_family = res->ai_family;
      ConfigServerInfo.ip.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ConfigServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
#line 3260 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 688 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost6(%s)", yylval.string);
    else
    {
      assert(res);

      memcpy(&ConfigServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ConfigServerInfo.ip6.ss.ss_family = res->ai_family;
      ConfigServerInfo.ip6.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ConfigServerInfo.specific_ipv6_vhost = 1;
    }
  }
}
#line 3291 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 716 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < MAXCLIENTS_MIN)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
    conf_error_report(buf);
    ConfigServerInfo.default_max_clients = MAXCLIENTS_MIN;
  }
  else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);
    ConfigServerInfo.default_max_clients = MAXCLIENTS_MAX;
  }
  else
    ConfigServerInfo.default_max_clients = (yyvsp[-1].number);
}
#line 3319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 741 "conf_parser.y" /* yacc.c:1646  */
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
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
    conf_error_report(buf);
    ConfigServerInfo.max_nick_length = NICKLEN;
  }
  else
    ConfigServerInfo.max_nick_length = (yyvsp[-1].number);
}
#line 3344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 763 "conf_parser.y" /* yacc.c:1646  */
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
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
    conf_error_report(buf);
    ConfigServerInfo.max_topic_length = TOPICLEN;
  }
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 785 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 803 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 812 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 821 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 838 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 855 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3449 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 861 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3458 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 871 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3467 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 875 "conf_parser.y" /* yacc.c:1646  */
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
#line 3485 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 893 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 899 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 905 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 911 "conf_parser.y" /* yacc.c:1646  */
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
#line 3533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 945 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3551 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 949 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3564 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 965 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3575 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 973 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 976 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3591 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 981 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3600 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 988 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3609 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3618 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 996 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3627 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3636 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1004 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3645 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1008 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3654 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1012 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3663 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1016 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3672 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1026 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1033 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  if (!block_state.rpass.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
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

    conf         = conf_make(CONF_OPER);
    conf->name   = xstrdup(block_state.name.buf);
    conf->user   = xstrdup(block_state.user.buf);
    conf->host   = xstrdup(block_state.host.buf);

    if (block_state.cert.buf[0])
      conf->certfp = xstrdup(block_state.cert.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);

    if (block_state.whois.buf[0])
      conf->whois = xstrdup(block_state.whois.buf);

    conf->flags = block_state.flags.value;
    conf->modes = block_state.modes.value;
    conf->port  = block_state.port.value;
    conf->htype = parse_netmask(conf->host, &conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);
  }
}
#line 3741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1100 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3750 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1106 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3759 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1112 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1118 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1124 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1135 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1141 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1152 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1158 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1165 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1169 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1173 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1177 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1181 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1185 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1189 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1193 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1201 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1205 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1209 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1213 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1217 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1225 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1237 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4003 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1245 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1266 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1270 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1274 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1278 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1282 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1286 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1290 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1294 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1298 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1302 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1306 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1310 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1314 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1318 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1322 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1326 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1330 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4201 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1334 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1338 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1342 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1346 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1350 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1354 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1358 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1362 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4273 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1366 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4282 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1370 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4291 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1374 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1384 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_total.value = MAXIMUM_LINKS_DEFAULT;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4317 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1396 "conf_parser.y" /* yacc.c:1646  */
    {
  struct ClassItem *class = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.class.buf[0])
    break;

  if (!(class = class_find(block_state.class.buf, 0)))
    class = class_make();

  class->active = 1;
  xfree(class->name);
  class->name = xstrdup(block_state.class.buf);
  class->ping_freq = block_state.ping_freq.value;
  class->max_perip = block_state.max_perip.value;
  class->con_freq = block_state.con_freq.value;
  class->max_total = block_state.max_total.value;
  class->max_global = block_state.max_global.value;
  class->max_local = block_state.max_local.value;
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

  rebuild_cidr_list(class);

  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;
}
#line 4364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1459 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1465 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1471 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1477 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1483 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1489 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1495 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1501 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4436 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1507 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4445 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1513 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1520 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1526 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1532 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1538 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1547 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1556 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1563 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4524 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1567 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1577 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1583 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1589 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1593 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4568 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1597 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4577 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1605 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1610 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_TLS
    if (block_state.flags.value & LISTENER_SSL)
    {
      conf_error_report("TLS not available - port closed");
      break;
    }
#endif
    listener_add((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4601 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1623 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_TLS
    if (block_state.flags.value & LISTENER_SSL)
    {
      conf_error_report("TLS not available - port closed");
      break;
    }
#endif

    for (int i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      listener_add(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4621 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1640 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4630 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1646 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4639 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1656 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4648 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1660 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
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

    conf        = conf_make(CONF_CLIENT);
    conf->user  = xstrdup(block_state.user.buf);
    conf->host  = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);
    if (block_state.name.buf[0])
      conf->name = xstrdup(block_state.name.buf);

    conf->flags = block_state.flags.value;
    conf->port  = block_state.port.value;

    conf_add_class_to_conf(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
#line 4693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1713 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4702 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1719 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4711 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1725 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4720 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1731 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4734 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1742 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4743 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1749 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4752 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1753 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4761 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1757 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4770 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1761 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4779 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1765 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4788 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1769 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4797 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1773 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4806 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1777 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1781 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1785 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4833 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1791 "conf_parser.y" /* yacc.c:1646  */
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
#line 4850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1805 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4862 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1814 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1827 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1845 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1857 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1872 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1888 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1899 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4970 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1914 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4979 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1920 "conf_parser.y" /* yacc.c:1646  */
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
#line 5001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5010 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1946 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5019 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1950 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5028 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1954 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1958 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1966 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1970 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1974 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5082 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1978 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5091 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1982 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5100 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5114 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2001 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2020 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5145 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5154 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2031 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5163 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5172 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2039 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 404:
#line 2043 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2047 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5199 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2051 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5217 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2059 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5226 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2063 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5235 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2073 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2082 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;
  struct addrinfo hints, *res;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0] ||
      !block_state.host.buf[0])
    break;

  if (!block_state.rpass.buf[0] ||
      !block_state.spass.buf[0])
    break;

  if (has_wildcards(block_state.name.buf) ||
      has_wildcards(block_state.host.buf))
    break;

  conf = conf_make(CONF_SERVER);
  conf->port = block_state.port.value;
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
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost(%s)", block_state.bind.buf);
    else
    {
      assert(res);

      memcpy(&conf->bind, res->ai_addr, res->ai_addrlen);
      conf->bind.ss.ss_family = res->ai_family;
      conf->bind.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  lookup_confhost(conf);
}
#line 5315 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2162 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2168 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2174 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2180 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].string)[0] == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[-1].string), ' '))
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.spass.buf, yylval.string, sizeof(block_state.spass.buf));
}
#line 5358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2193 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].string)[0] == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[-1].string), ' '))
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2206 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2218 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2222 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2228 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2234 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2238 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5436 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2261 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2267 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5477 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2273 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2292 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.user.buf[0] ||
      !block_state.host.buf[0])
    break;

  conf = conf_make(CONF_KLINE);
  conf->user = xstrdup(block_state.user.buf);
  conf->host = xstrdup(block_state.host.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
  add_conf_by_address(CONF_KLINE, conf);
}
#line 5525 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2317 "conf_parser.y" /* yacc.c:1646  */
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
#line 5548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5557 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2347 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5566 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2351 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  if (parse_netmask(block_state.addr.buf, NULL, NULL) != HM_HOST)
  {
    conf = conf_make(CONF_DLINE);
    conf->host = xstrdup(block_state.addr.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
    add_conf_by_address(CONF_DLINE, conf);
  }
}
#line 5592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2377 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5601 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2383 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5610 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 472:
#line 2398 "conf_parser.y" /* yacc.c:1646  */
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
#line 5627 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 473:
#line 2415 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5636 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 474:
#line 2419 "conf_parser.y" /* yacc.c:1646  */
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
#line 5656 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 480:
#line 2439 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 481:
#line 2445 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5674 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2507 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2512 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5690 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2517 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5698 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2522 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5706 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2527 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2533 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2538 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5731 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2543 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5739 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2548 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2553 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5755 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2558 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5763 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2563 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5771 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2568 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5779 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2573 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5787 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2578 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5795 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2583 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5803 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2588 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5811 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2593 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5819 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2598 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2603 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2609 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5844 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2614 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2619 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5860 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2624 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2629 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2634 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2639 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2644 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2652 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2655 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2660 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5932 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2665 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2670 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2675 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2680 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2685 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2690 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5980 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2695 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5988 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2700 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5996 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2705 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6004 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2710 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2715 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6020 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2720 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6028 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2726 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6036 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2729 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2732 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2735 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6060 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2738 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2741 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6076 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2744 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2747 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2750 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6100 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2753 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6108 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2756 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2759 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6132 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2765 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6140 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2768 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6148 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2771 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2774 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6172 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6180 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2783 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2789 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2794 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2800 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6220 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2803 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2806 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2809 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6244 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2812 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6252 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2815 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6260 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2818 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6268 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2821 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6276 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2824 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6284 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2827 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6292 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2830 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2833 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6308 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2836 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6316 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 618:
#line 2839 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 619:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6332 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 620:
#line 2845 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 621:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 622:
#line 2851 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 623:
#line 2854 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2862 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6380 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2867 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2898 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6404 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 2903 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6412 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 2908 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 2913 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2918 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6436 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2923 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2928 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2933 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2938 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 2943 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 2948 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6484 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 2953 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 669:
#line 2976 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6501 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 670:
#line 2982 "conf_parser.y" /* yacc.c:1646  */
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
#line 6520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 671:
#line 2998 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 672:
#line 3007 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 673:
#line 3013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 674:
#line 3019 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 675:
#line 3025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 676:
#line 3034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6580 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 677:
#line 3040 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6589 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6593 "conf_parser.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
