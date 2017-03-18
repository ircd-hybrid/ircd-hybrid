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
    DEFAULT_FLOODTIME = 281,
    DEFAULT_JOIN_FLOOD_COUNT = 282,
    DEFAULT_JOIN_FLOOD_TIME = 283,
    DEFAULT_MAX_CLIENTS = 284,
    DENY = 285,
    DESCRIPTION = 286,
    DIE = 287,
    DISABLE_AUTH = 288,
    DISABLE_FAKE_CHANNELS = 289,
    DISABLE_REMOTE_COMMANDS = 290,
    DLINE_MIN_CIDR = 291,
    DLINE_MIN_CIDR6 = 292,
    DOTS_IN_IDENT = 293,
    EMAIL = 294,
    ENCRYPTED = 295,
    EXCEED_LIMIT = 296,
    EXEMPT = 297,
    FAILED_OPER_NOTICE = 298,
    FLATTEN_LINKS = 299,
    FLATTEN_LINKS_DELAY = 300,
    FLATTEN_LINKS_FILE = 301,
    GECOS = 302,
    GENERAL = 303,
    HIDDEN = 304,
    HIDDEN_NAME = 305,
    HIDE_CHANS = 306,
    HIDE_IDLE = 307,
    HIDE_IDLE_FROM_OPERS = 308,
    HIDE_SERVER_IPS = 309,
    HIDE_SERVERS = 310,
    HIDE_SERVICES = 311,
    HOST = 312,
    HUB = 313,
    HUB_MASK = 314,
    IGNORE_BOGUS_TS = 315,
    INVISIBLE_ON_CONNECT = 316,
    INVITE_CLIENT_COUNT = 317,
    INVITE_CLIENT_TIME = 318,
    INVITE_DELAY_CHANNEL = 319,
    INVITE_EXPIRE_TIME = 320,
    IP = 321,
    IRCD_AUTH = 322,
    IRCD_FLAGS = 323,
    IRCD_SID = 324,
    JOIN = 325,
    KILL = 326,
    KILL_CHASE_TIME_LIMIT = 327,
    KLINE = 328,
    KLINE_EXEMPT = 329,
    KLINE_MIN_CIDR = 330,
    KLINE_MIN_CIDR6 = 331,
    KNOCK_CLIENT_COUNT = 332,
    KNOCK_CLIENT_TIME = 333,
    KNOCK_DELAY_CHANNEL = 334,
    LEAF_MASK = 335,
    LIBGEOIP_DATABASE_OPTIONS = 336,
    LIBGEOIP_IPV4_DATABASE_FILE = 337,
    LIBGEOIP_IPV6_DATABASE_FILE = 338,
    LISTEN = 339,
    MASK = 340,
    MAX_ACCEPT = 341,
    MAX_BANS = 342,
    MAX_BANS_LARGE = 343,
    MAX_CHANNELS = 344,
    MAX_GLOBAL = 345,
    MAX_IDLE = 346,
    MAX_INVITES = 347,
    MAX_LOCAL = 348,
    MAX_NICK_CHANGES = 349,
    MAX_NICK_LENGTH = 350,
    MAX_NICK_TIME = 351,
    MAX_NUMBER = 352,
    MAX_TARGETS = 353,
    MAX_TOPIC_LENGTH = 354,
    MAX_WATCH = 355,
    MEMORY_CACHE = 356,
    MIN_IDLE = 357,
    MIN_NONWILDCARD = 358,
    MIN_NONWILDCARD_SIMPLE = 359,
    MMAP_CACHE = 360,
    MODULE = 361,
    MODULES = 362,
    MOTD = 363,
    NAME = 364,
    NEED_IDENT = 365,
    NEED_PASSWORD = 366,
    NETWORK_DESC = 367,
    NETWORK_NAME = 368,
    NICK = 369,
    NO_OPER_FLOOD = 370,
    NO_TILDE = 371,
    NUMBER = 372,
    NUMBER_PER_CIDR = 373,
    NUMBER_PER_IP = 374,
    OPER_ONLY_UMODES = 375,
    OPER_UMODES = 376,
    OPERATOR = 377,
    OPERS_BYPASS_CALLERID = 378,
    PACE_WAIT = 379,
    PACE_WAIT_SIMPLE = 380,
    PASSWORD = 381,
    PATH = 382,
    PING_COOKIE = 383,
    PING_TIME = 384,
    PORT = 385,
    QSTRING = 386,
    RANDOM_IDLE = 387,
    REASON = 388,
    REDIRPORT = 389,
    REDIRSERV = 390,
    REHASH = 391,
    REMOTE = 392,
    REMOTEBAN = 393,
    RESV = 394,
    RESV_EXEMPT = 395,
    RSA_PRIVATE_KEY_FILE = 396,
    SECONDS = 397,
    MINUTES = 398,
    HOURS = 399,
    DAYS = 400,
    WEEKS = 401,
    MONTHS = 402,
    YEARS = 403,
    SEND_PASSWORD = 404,
    SENDQ = 405,
    SERVERHIDE = 406,
    SERVERINFO = 407,
    SHORT_MOTD = 408,
    SPOOF = 409,
    SPOOF_NOTICE = 410,
    SQUIT = 411,
    SSL_CERTIFICATE_FILE = 412,
    SSL_CERTIFICATE_FINGERPRINT = 413,
    SSL_CONNECTION_REQUIRED = 414,
    SSL_DH_ELLIPTIC_CURVE = 415,
    SSL_DH_PARAM_FILE = 416,
    SSL_MESSAGE_DIGEST_ALGORITHM = 417,
    STANDARD = 418,
    STATS_E_DISABLED = 419,
    STATS_I_OPER_ONLY = 420,
    STATS_K_OPER_ONLY = 421,
    STATS_M_OPER_ONLY = 422,
    STATS_O_OPER_ONLY = 423,
    STATS_P_OPER_ONLY = 424,
    STATS_U_OPER_ONLY = 425,
    T_ALL = 426,
    T_BOTS = 427,
    T_CALLERID = 428,
    T_CCONN = 429,
    T_COMMAND = 430,
    T_CLUSTER = 431,
    T_DEAF = 432,
    T_DEBUG = 433,
    T_DLINE = 434,
    T_EXTERNAL = 435,
    T_FARCONNECT = 436,
    T_FILE = 437,
    T_FULL = 438,
    T_GLOBOPS = 439,
    T_INVISIBLE = 440,
    T_IPV4 = 441,
    T_IPV6 = 442,
    T_LOCOPS = 443,
    T_LOG = 444,
    T_NCHANGE = 445,
    T_NONONREG = 446,
    T_OPME = 447,
    T_PREPEND = 448,
    T_PSEUDO = 449,
    T_RECVQ = 450,
    T_REJ = 451,
    T_RESTART = 452,
    T_SERVER = 453,
    T_SERVICE = 454,
    T_SERVNOTICE = 455,
    T_SET = 456,
    T_SHARED = 457,
    T_SIZE = 458,
    T_SKILL = 459,
    T_SOFTCALLERID = 460,
    T_SPY = 461,
    T_SSL = 462,
    T_SSL_CIPHER_LIST = 463,
    T_TARGET = 464,
    T_UMODES = 465,
    T_UNAUTH = 466,
    T_UNDLINE = 467,
    T_UNLIMITED = 468,
    T_UNRESV = 469,
    T_UNXLINE = 470,
    T_WALLOP = 471,
    T_WALLOPS = 472,
    T_WEBIRC = 473,
    TBOOL = 474,
    THROTTLE_COUNT = 475,
    THROTTLE_TIME = 476,
    TKLINE_EXPIRE_NOTICES = 477,
    TMASKED = 478,
    TS_MAX_DELTA = 479,
    TS_WARN_DELTA = 480,
    TWODOTS = 481,
    TYPE = 482,
    UNKLINE = 483,
    USE_LOGGING = 484,
    USER = 485,
    VHOST = 486,
    VHOST6 = 487,
    WARN_NO_CONNECT_BLOCK = 488,
    WHOIS = 489,
    WHOWAS_HISTORY_LENGTH = 490,
    XLINE = 491,
    XLINE_EXEMPT = 492
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
#define DEFAULT_FLOODTIME 281
#define DEFAULT_JOIN_FLOOD_COUNT 282
#define DEFAULT_JOIN_FLOOD_TIME 283
#define DEFAULT_MAX_CLIENTS 284
#define DENY 285
#define DESCRIPTION 286
#define DIE 287
#define DISABLE_AUTH 288
#define DISABLE_FAKE_CHANNELS 289
#define DISABLE_REMOTE_COMMANDS 290
#define DLINE_MIN_CIDR 291
#define DLINE_MIN_CIDR6 292
#define DOTS_IN_IDENT 293
#define EMAIL 294
#define ENCRYPTED 295
#define EXCEED_LIMIT 296
#define EXEMPT 297
#define FAILED_OPER_NOTICE 298
#define FLATTEN_LINKS 299
#define FLATTEN_LINKS_DELAY 300
#define FLATTEN_LINKS_FILE 301
#define GECOS 302
#define GENERAL 303
#define HIDDEN 304
#define HIDDEN_NAME 305
#define HIDE_CHANS 306
#define HIDE_IDLE 307
#define HIDE_IDLE_FROM_OPERS 308
#define HIDE_SERVER_IPS 309
#define HIDE_SERVERS 310
#define HIDE_SERVICES 311
#define HOST 312
#define HUB 313
#define HUB_MASK 314
#define IGNORE_BOGUS_TS 315
#define INVISIBLE_ON_CONNECT 316
#define INVITE_CLIENT_COUNT 317
#define INVITE_CLIENT_TIME 318
#define INVITE_DELAY_CHANNEL 319
#define INVITE_EXPIRE_TIME 320
#define IP 321
#define IRCD_AUTH 322
#define IRCD_FLAGS 323
#define IRCD_SID 324
#define JOIN 325
#define KILL 326
#define KILL_CHASE_TIME_LIMIT 327
#define KLINE 328
#define KLINE_EXEMPT 329
#define KLINE_MIN_CIDR 330
#define KLINE_MIN_CIDR6 331
#define KNOCK_CLIENT_COUNT 332
#define KNOCK_CLIENT_TIME 333
#define KNOCK_DELAY_CHANNEL 334
#define LEAF_MASK 335
#define LIBGEOIP_DATABASE_OPTIONS 336
#define LIBGEOIP_IPV4_DATABASE_FILE 337
#define LIBGEOIP_IPV6_DATABASE_FILE 338
#define LISTEN 339
#define MASK 340
#define MAX_ACCEPT 341
#define MAX_BANS 342
#define MAX_BANS_LARGE 343
#define MAX_CHANNELS 344
#define MAX_GLOBAL 345
#define MAX_IDLE 346
#define MAX_INVITES 347
#define MAX_LOCAL 348
#define MAX_NICK_CHANGES 349
#define MAX_NICK_LENGTH 350
#define MAX_NICK_TIME 351
#define MAX_NUMBER 352
#define MAX_TARGETS 353
#define MAX_TOPIC_LENGTH 354
#define MAX_WATCH 355
#define MEMORY_CACHE 356
#define MIN_IDLE 357
#define MIN_NONWILDCARD 358
#define MIN_NONWILDCARD_SIMPLE 359
#define MMAP_CACHE 360
#define MODULE 361
#define MODULES 362
#define MOTD 363
#define NAME 364
#define NEED_IDENT 365
#define NEED_PASSWORD 366
#define NETWORK_DESC 367
#define NETWORK_NAME 368
#define NICK 369
#define NO_OPER_FLOOD 370
#define NO_TILDE 371
#define NUMBER 372
#define NUMBER_PER_CIDR 373
#define NUMBER_PER_IP 374
#define OPER_ONLY_UMODES 375
#define OPER_UMODES 376
#define OPERATOR 377
#define OPERS_BYPASS_CALLERID 378
#define PACE_WAIT 379
#define PACE_WAIT_SIMPLE 380
#define PASSWORD 381
#define PATH 382
#define PING_COOKIE 383
#define PING_TIME 384
#define PORT 385
#define QSTRING 386
#define RANDOM_IDLE 387
#define REASON 388
#define REDIRPORT 389
#define REDIRSERV 390
#define REHASH 391
#define REMOTE 392
#define REMOTEBAN 393
#define RESV 394
#define RESV_EXEMPT 395
#define RSA_PRIVATE_KEY_FILE 396
#define SECONDS 397
#define MINUTES 398
#define HOURS 399
#define DAYS 400
#define WEEKS 401
#define MONTHS 402
#define YEARS 403
#define SEND_PASSWORD 404
#define SENDQ 405
#define SERVERHIDE 406
#define SERVERINFO 407
#define SHORT_MOTD 408
#define SPOOF 409
#define SPOOF_NOTICE 410
#define SQUIT 411
#define SSL_CERTIFICATE_FILE 412
#define SSL_CERTIFICATE_FINGERPRINT 413
#define SSL_CONNECTION_REQUIRED 414
#define SSL_DH_ELLIPTIC_CURVE 415
#define SSL_DH_PARAM_FILE 416
#define SSL_MESSAGE_DIGEST_ALGORITHM 417
#define STANDARD 418
#define STATS_E_DISABLED 419
#define STATS_I_OPER_ONLY 420
#define STATS_K_OPER_ONLY 421
#define STATS_M_OPER_ONLY 422
#define STATS_O_OPER_ONLY 423
#define STATS_P_OPER_ONLY 424
#define STATS_U_OPER_ONLY 425
#define T_ALL 426
#define T_BOTS 427
#define T_CALLERID 428
#define T_CCONN 429
#define T_COMMAND 430
#define T_CLUSTER 431
#define T_DEAF 432
#define T_DEBUG 433
#define T_DLINE 434
#define T_EXTERNAL 435
#define T_FARCONNECT 436
#define T_FILE 437
#define T_FULL 438
#define T_GLOBOPS 439
#define T_INVISIBLE 440
#define T_IPV4 441
#define T_IPV6 442
#define T_LOCOPS 443
#define T_LOG 444
#define T_NCHANGE 445
#define T_NONONREG 446
#define T_OPME 447
#define T_PREPEND 448
#define T_PSEUDO 449
#define T_RECVQ 450
#define T_REJ 451
#define T_RESTART 452
#define T_SERVER 453
#define T_SERVICE 454
#define T_SERVNOTICE 455
#define T_SET 456
#define T_SHARED 457
#define T_SIZE 458
#define T_SKILL 459
#define T_SOFTCALLERID 460
#define T_SPY 461
#define T_SSL 462
#define T_SSL_CIPHER_LIST 463
#define T_TARGET 464
#define T_UMODES 465
#define T_UNAUTH 466
#define T_UNDLINE 467
#define T_UNLIMITED 468
#define T_UNRESV 469
#define T_UNXLINE 470
#define T_WALLOP 471
#define T_WALLOPS 472
#define T_WEBIRC 473
#define TBOOL 474
#define THROTTLE_COUNT 475
#define THROTTLE_TIME 476
#define TKLINE_EXPIRE_NOTICES 477
#define TMASKED 478
#define TS_MAX_DELTA 479
#define TS_WARN_DELTA 480
#define TWODOTS 481
#define TYPE 482
#define UNKLINE 483
#define USE_LOGGING 484
#define USER 485
#define VHOST 486
#define VHOST6 487
#define WARN_NO_CONNECT_BLOCK 488
#define WHOIS 489
#define WHOWAS_HISTORY_LENGTH 490
#define XLINE 491
#define XLINE_EXEMPT 492

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 141 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 698 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 715 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1374

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  244
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  302
/* YYNRULES -- Number of rules.  */
#define YYNRULES  683
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1347

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   492

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
       2,     2,     2,     2,   242,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   243,   238,
       2,   241,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   240,     2,   239,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   382,   382,   383,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   413,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   424,   424,
     425,   426,   427,   428,   435,   437,   437,   438,   438,   438,
     440,   446,   456,   458,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   482,   491,   500,   509,
     518,   527,   537,   536,   542,   542,   543,   549,   555,   561,
     569,   584,   599,   614,   629,   639,   653,   662,   690,   718,
     743,   765,   787,   797,   799,   799,   800,   801,   802,   803,
     805,   814,   823,   837,   836,   854,   854,   855,   855,   855,
     857,   863,   874,   873,   892,   892,   893,   893,   893,   893,
     893,   895,   901,   907,   913,   935,   936,   936,   938,   938,
     939,   941,   948,   948,   961,   962,   964,   964,   965,   965,
     967,   975,   978,   984,   983,   989,   989,   990,   994,   998,
    1002,  1006,  1010,  1014,  1018,  1029,  1028,  1089,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,
    1102,  1108,  1114,  1120,  1126,  1137,  1143,  1154,  1161,  1160,
    1166,  1166,  1167,  1171,  1175,  1179,  1183,  1187,  1191,  1195,
    1199,  1203,  1207,  1211,  1215,  1219,  1223,  1227,  1231,  1235,
    1239,  1243,  1247,  1251,  1258,  1257,  1263,  1263,  1264,  1268,
    1272,  1276,  1280,  1284,  1288,  1292,  1296,  1300,  1304,  1308,
    1312,  1316,  1320,  1324,  1328,  1332,  1336,  1340,  1344,  1348,
    1352,  1356,  1360,  1364,  1368,  1372,  1376,  1387,  1386,  1442,
    1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,
    1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1461,  1467,
    1473,  1479,  1485,  1491,  1497,  1503,  1509,  1515,  1522,  1528,
    1534,  1540,  1549,  1559,  1558,  1564,  1564,  1565,  1569,  1580,
    1579,  1586,  1585,  1590,  1590,  1591,  1595,  1599,  1605,  1605,
    1606,  1606,  1606,  1606,  1606,  1608,  1608,  1610,  1610,  1612,
    1625,  1642,  1648,  1659,  1658,  1704,  1704,  1705,  1706,  1707,
    1708,  1709,  1710,  1711,  1712,  1713,  1715,  1721,  1727,  1733,
    1745,  1744,  1750,  1750,  1751,  1755,  1759,  1763,  1767,  1771,
    1775,  1779,  1783,  1787,  1793,  1807,  1816,  1830,  1829,  1844,
    1844,  1845,  1845,  1845,  1845,  1847,  1853,  1859,  1869,  1871,
    1871,  1872,  1872,  1874,  1891,  1890,  1913,  1913,  1914,  1914,
    1914,  1914,  1916,  1922,  1942,  1941,  1947,  1947,  1948,  1952,
    1956,  1960,  1964,  1968,  1972,  1976,  1980,  1984,  1995,  1994,
    2013,  2013,  2014,  2014,  2014,  2016,  2023,  2022,  2028,  2028,
    2029,  2033,  2037,  2041,  2045,  2049,  2053,  2057,  2061,  2065,
    2076,  2075,  2147,  2147,  2148,  2149,  2150,  2151,  2152,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,  2164,
    2170,  2176,  2182,  2195,  2208,  2214,  2220,  2224,  2231,  2230,
    2235,  2235,  2236,  2240,  2246,  2257,  2263,  2269,  2275,  2291,
    2290,  2316,  2316,  2317,  2317,  2317,  2319,  2339,  2350,  2349,
    2376,  2376,  2377,  2377,  2377,  2379,  2385,  2395,  2397,  2397,
    2398,  2398,  2400,  2418,  2417,  2438,  2438,  2439,  2439,  2439,
    2441,  2447,  2457,  2459,  2459,  2460,  2461,  2462,  2463,  2464,
    2465,  2466,  2467,  2468,  2469,  2470,  2471,  2472,  2473,  2474,
    2475,  2476,  2477,  2478,  2479,  2480,  2481,  2482,  2483,  2484,
    2485,  2486,  2487,  2488,  2489,  2490,  2491,  2492,  2493,  2494,
    2495,  2496,  2497,  2498,  2499,  2500,  2501,  2502,  2503,  2504,
    2505,  2506,  2507,  2510,  2515,  2520,  2525,  2530,  2536,  2541,
    2546,  2551,  2556,  2561,  2566,  2571,  2576,  2581,  2586,  2591,
    2596,  2601,  2606,  2612,  2617,  2622,  2627,  2632,  2637,  2642,
    2647,  2650,  2655,  2658,  2663,  2668,  2673,  2678,  2683,  2688,
    2693,  2698,  2703,  2708,  2713,  2718,  2724,  2723,  2728,  2728,
    2729,  2732,  2735,  2738,  2741,  2744,  2747,  2750,  2753,  2756,
    2759,  2762,  2765,  2768,  2771,  2774,  2777,  2780,  2783,  2786,
    2789,  2792,  2798,  2797,  2802,  2802,  2803,  2806,  2809,  2812,
    2815,  2818,  2821,  2824,  2827,  2830,  2833,  2836,  2839,  2842,
    2845,  2848,  2851,  2854,  2857,  2860,  2865,  2870,  2875,  2880,
    2889,  2891,  2891,  2892,  2893,  2894,  2895,  2896,  2897,  2898,
    2899,  2900,  2901,  2902,  2903,  2904,  2905,  2906,  2908,  2913,
    2918,  2923,  2928,  2933,  2938,  2943,  2948,  2953,  2958,  2963,
    2968,  2973,  2982,  2984,  2984,  2985,  2986,  2987,  2988,  2989,
    2990,  2991,  2992,  2993,  2994,  2996,  3002,  3018,  3027,  3033,
    3039,  3045,  3054,  3060
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
  "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME",
  "DEFAULT_JOIN_FLOOD_COUNT", "DEFAULT_JOIN_FLOOD_TIME",
  "DEFAULT_MAX_CLIENTS", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR",
  "DLINE_MIN_CIDR6", "DOTS_IN_IDENT", "EMAIL", "ENCRYPTED", "EXCEED_LIMIT",
  "EXEMPT", "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "FLATTEN_LINKS_DELAY",
  "FLATTEN_LINKS_FILE", "GECOS", "GENERAL", "HIDDEN", "HIDDEN_NAME",
  "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT",
  "INVITE_CLIENT_TIME", "INVITE_DELAY_CHANNEL", "INVITE_EXPIRE_TIME", "IP",
  "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID", "JOIN", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_MIN_CIDR",
  "KLINE_MIN_CIDR6", "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME",
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LIBGEOIP_DATABASE_OPTIONS",
  "LIBGEOIP_IPV4_DATABASE_FILE", "LIBGEOIP_IPV6_DATABASE_FILE", "LISTEN",
  "MASK", "MAX_ACCEPT", "MAX_BANS", "MAX_BANS_LARGE", "MAX_CHANNELS",
  "MAX_GLOBAL", "MAX_IDLE", "MAX_INVITES", "MAX_LOCAL", "MAX_NICK_CHANGES",
  "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_TOPIC_LENGTH", "MAX_WATCH", "MEMORY_CACHE", "MIN_IDLE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MMAP_CACHE", "MODULE",
  "MODULES", "MOTD", "NAME", "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESC",
  "NETWORK_NAME", "NICK", "NO_OPER_FLOOD", "NO_TILDE", "NUMBER",
  "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPER_ONLY_UMODES", "OPER_UMODES",
  "OPERATOR", "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE",
  "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME", "PORT", "QSTRING",
  "RANDOM_IDLE", "REASON", "REDIRPORT", "REDIRSERV", "REHASH", "REMOTE",
  "REMOTEBAN", "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE", "SECONDS",
  "MINUTES", "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD",
  "SENDQ", "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPOOF",
  "SPOOF_NOTICE", "SQUIT", "SSL_CERTIFICATE_FILE",
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
  "general_default_floodtime", "channel_entry", "channel_items",
  "channel_item", "channel_disable_fake_channels",
  "channel_invite_client_count", "channel_invite_client_time",
  "channel_invite_delay_channel", "channel_invite_expire_time",
  "channel_knock_client_count", "channel_knock_client_time",
  "channel_knock_delay_channel", "channel_max_channels",
  "channel_max_invites", "channel_max_bans", "channel_max_bans_large",
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
     485,   486,   487,   488,   489,   490,   491,   492,    59,   125,
     123,    61,    44,    58
};
# endif

#define YYPACT_NINF -775

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-775)))

#define YYTABLE_NINF -143

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -775,   761,  -775,  -183,  -211,  -203,  -775,  -775,  -775,  -198,
    -775,  -195,  -775,  -775,  -775,  -193,  -775,  -775,  -775,  -144,
    -131,  -775,  -122,  -775,  -121,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,    82,   973,  -115,  -108,  -107,    48,  -102,   438,  -101,
     -82,   -76,    42,   -62,   -29,    -6,   378,   625,    45,    14,
      55,    22,    57,   -55,   -38,     6,    46,     7,  -775,  -775,
    -775,  -775,  -775,    58,    62,    68,    69,    83,    90,    93,
     103,   105,   113,   117,   125,   126,   130,   273,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,   600,   520,    32,  -775,   134,    24,  -775,
    -775,    26,  -775,   135,   136,   137,   140,   141,   142,   143,
     144,   148,   150,   152,   154,   157,   165,   166,   170,   173,
     174,   178,   179,   180,   185,   188,   189,   194,   197,  -775,
    -775,   199,   200,   201,   202,   209,   219,   224,   225,   229,
     237,   239,   242,   246,   247,   248,   249,   251,   252,   254,
      51,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,   368,
      47,   416,    -3,   256,   259,    40,  -775,  -775,  -775,    10,
     411,    49,  -775,   260,   263,   264,   265,   266,   267,   268,
     270,   275,    18,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,    50,   276,   277,   285,   287,  -775,   290,
     294,   298,   302,   303,   304,   307,   308,   309,   310,   311,
     313,   314,   315,   316,   155,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,    15,    87,   326,    16,
    -775,  -775,  -775,   175,    19,  -775,   327,    43,  -775,  -775,
      84,  -775,   341,   398,   440,   158,  -775,   455,   456,   355,
     459,   456,   456,   456,   461,   456,   456,   463,   464,   465,
     466,   346,  -775,   347,   345,   348,   349,  -775,   351,   353,
     354,   356,   369,   370,   374,   376,   379,   381,   383,   384,
     230,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,   358,   386,
     387,   389,   391,   392,   393,  -775,   394,   395,   396,   397,
     399,   401,   402,   288,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
     403,   405,    20,  -775,  -775,  -775,   516,   413,  -775,  -775,
     412,   414,    27,  -775,  -775,  -775,   433,   456,   470,   456,
     456,   442,   547,   456,   446,   549,   550,   553,   457,   458,
     467,   456,   563,   567,   568,   570,   456,   575,   578,   581,
     583,   482,   462,   469,   485,   456,   456,   486,   492,   493,
    -189,  -184,   494,   495,   496,   497,   604,   456,   498,   456,
     456,   506,   609,   501,  -775,   503,   489,   491,  -775,   502,
     504,   505,   507,   508,   238,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,   511,   512,    30,  -775,  -775,
    -775,   509,   513,   515,  -775,   518,  -775,    12,  -775,  -775,
    -775,  -775,  -775,   602,   605,   525,  -775,   526,   527,   531,
      23,  -775,  -775,  -775,   535,   533,   534,  -775,   537,   539,
     551,   552,  -775,   555,   556,    31,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,   538,   557,   558,
     559,    17,  -775,  -775,  -775,  -775,   523,   565,   456,   657,
     571,   663,   582,   585,   586,   564,  -775,  -775,   689,   676,
     591,   680,   572,   681,   683,   699,   702,   691,   692,   693,
     694,   695,   696,   700,   703,   704,   705,   706,   592,  -775,
     601,   579,  -775,   116,  -775,  -775,  -775,  -775,   621,   603,
    -775,   606,   610,   608,   611,   612,   613,    13,  -775,  -775,
    -775,  -775,  -775,   711,   620,  -775,   622,   618,  -775,   626,
      53,  -775,  -775,  -775,  -775,   623,   628,   632,  -775,   633,
     257,   634,   635,   636,   637,   638,   639,   641,   642,   643,
     644,   646,   647,   649,  -775,  -775,   726,   727,   456,   648,
     730,   733,   456,   734,   746,   456,   757,   776,   777,   456,
     780,   780,   664,  -775,  -775,   773,  -105,   774,   688,   779,
     784,   670,   785,   786,   802,   789,   790,   794,   795,   690,
    -775,   796,   799,   697,  -775,   698,  -775,   800,   801,   707,
    -775,   710,   714,   715,   720,   721,   723,   729,   731,   735,
     737,   738,   743,   747,   750,   752,   754,   755,   760,   765,
     767,   770,   771,   775,   778,   781,   782,   806,   718,   783,
     787,   788,   791,   792,   793,   803,   804,   805,   807,   808,
     809,   810,   811,   815,   816,   817,   818,   819,   820,   821,
    -775,  -775,   833,   722,   701,   834,   851,   864,   868,   873,
     825,  -775,   883,   884,   826,  -775,  -775,   887,   892,   798,
     907,   828,  -775,   829,   830,  -775,  -775,   896,   897,   831,
    -775,  -775,   901,   814,   832,   903,   909,   913,   852,   835,
     939,   941,   836,  -775,  -775,   944,   946,   947,   841,  -775,
     842,   843,   844,   845,   846,   847,   848,   849,   850,  -775,
     853,   854,   855,   856,     5,   857,   858,   859,   860,   861,
     862,   863,   865,   866,   867,   869,   870,   871,   872,   874,
    -775,  -775,   958,   875,   876,  -775,   877,  -775,    78,  -775,
     959,   971,   975,   980,   879,  -775,   880,  -775,  -775,   982,
     878,   989,   885,  -775,  -775,  -775,  -775,  -775,   456,   456,
     456,   456,   456,   456,   456,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
     886,   888,   889,   -27,   890,   891,   893,   894,   895,   898,
     899,   900,   902,   904,   196,   905,   906,  -775,   908,   910,
     911,   912,   914,   915,   916,    -5,   917,   918,   919,   920,
     921,   922,   923,  -775,   924,   925,  -775,  -775,   926,   927,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -202,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -172,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,   928,   929,   375,   930,   931,   932,
     933,   934,  -775,   935,   936,  -775,   937,   938,   -37,   951,
     940,  -775,  -775,  -775,  -775,   942,   943,  -775,   945,   948,
     543,   949,   950,   952,   953,   766,   954,   955,  -775,   956,
     957,   960,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -145,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,   961,   460,  -775,
    -775,   962,   881,   963,  -775,    91,  -775,  -775,  -775,  -775,
     964,   965,   967,   968,  -775,  -775,   969,   650,   970,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,   -65,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,   780,   780,   780,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
     -57,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,   806,  -775,   718,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,   -43,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,   -41,  -775,  1004,   907,   972,  -775,  -775,
    -775,  -775,  -775,  -775,   882,  -775,   966,   974,  -775,  -775,
     976,   977,  -775,  -775,   978,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,   -28,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,   -15,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,     5,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,   -12,  -775,  -775,   999,  -113,
     981,   985,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,    -9,  -775,
    -775,  -775,   -27,  -775,  -775,  -775,  -775,    -5,  -775,  -775,
    -775,   375,  -775,   -37,  -775,  -775,  -775,   997,   996,  1002,
    1006,  1010,  1014,  -775,   543,  -775,   766,  -775,  -775,   460,
     986,   987,   988,   231,  -775,  -775,   650,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,     2,  -775,  -775,  -775,   231,  -775
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
     108,   107,   647,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   632,   646,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   633,
     634,   644,   645,     0,     0,     0,   471,     0,     0,   469,
     470,     0,   532,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   602,
     576,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   484,   485,   486,   530,   493,   531,   525,   526,   527,
     528,   524,   497,   487,   488,   489,   490,   491,   492,   494,
     495,   496,   498,   499,   529,   503,   504,   505,   506,   502,
     501,   507,   514,   515,   508,   509,   510,   500,   512,   522,
     523,   520,   521,   513,   511,   518,   519,   516,   517,     0,
       0,     0,     0,     0,     0,     0,    46,    47,    48,     0,
       0,     0,   674,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   664,   665,   666,   667,   668,   669,   670,
     672,   671,   673,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    69,    66,    64,    70,
      71,    65,    72,    73,    74,    55,    68,    58,    59,    60,
      56,    67,    61,    62,    63,    57,     0,     0,     0,     0,
     137,   138,   139,     0,     0,   362,     0,     0,   360,   361,
       0,   109,     0,     0,     0,     0,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   631,     0,     0,     0,     0,   283,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,   251,   254,   256,   257,   258,   259,   260,   261,
     262,   263,   252,   253,   255,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,   438,     0,     0,     0,     0,
       0,     0,     0,     0,   413,   414,   415,   416,   417,   418,
     419,   421,   420,   423,   427,   424,   425,   426,   422,   464,
       0,     0,     0,   461,   462,   463,     0,     0,   468,   479,
       0,     0,     0,   476,   477,   478,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   483,     0,     0,     0,   330,     0,
       0,     0,     0,     0,     0,   316,   317,   318,   319,   324,
     320,   321,   322,   323,   455,     0,     0,     0,   452,   453,
     454,     0,     0,     0,   291,     0,   301,     0,   299,   300,
     302,   303,    49,     0,     0,     0,    45,     0,     0,     0,
       0,   116,   117,   118,     0,     0,     0,   214,     0,     0,
       0,     0,   188,     0,     0,     0,   168,   169,   170,   171,
     172,   175,   176,   177,   174,   173,   178,     0,     0,     0,
       0,     0,   350,   351,   352,   353,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   663,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,   396,     0,   391,   392,   393,   140,     0,     0,
     136,     0,     0,     0,     0,     0,     0,     0,   125,   126,
     128,   127,   129,     0,     0,   359,     0,     0,   374,     0,
       0,   367,   368,   369,   370,     0,     0,     0,   103,     0,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,   267,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   249,   428,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     412,     0,     0,     0,   460,     0,   467,     0,     0,     0,
     475,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     482,   325,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   315,     0,     0,     0,   451,   304,     0,     0,     0,
       0,     0,   298,     0,     0,    44,   119,     0,     0,     0,
     115,   179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   354,     0,     0,     0,     0,   349,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   662,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,   394,     0,     0,     0,   390,     0,   135,     0,   130,
       0,     0,     0,     0,     0,   124,     0,   358,   371,     0,
       0,     0,     0,   366,   112,   111,   110,   660,    28,    28,
      28,    28,    28,    28,    28,    30,    29,   661,   648,   649,
     650,   651,   652,   653,   654,   655,   658,   659,   656,   657,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   411,     0,     0,   459,   472,     0,     0,
     474,   546,   550,   533,   534,   565,   537,   628,   629,   573,
     538,   539,   570,   545,   544,   553,   543,   540,   541,   549,
     548,   547,   571,   535,   626,   627,   569,   612,   606,   622,
     607,   608,   609,   617,   625,   610,   619,   623,   613,   624,
     614,   618,   611,   621,   616,   615,   620,     0,   605,   585,
     586,   587,   580,   598,   581,   582,   583,   593,   601,   584,
     595,   599,   589,   600,   590,   594,   588,   597,   592,   591,
     596,     0,   579,   566,   564,   567,   572,   568,   555,   562,
     563,   560,   561,   556,   557,   558,   559,   574,   575,   542,
     552,   551,   554,   536,     0,     0,     0,     0,     0,     0,
       0,     0,   314,     0,     0,   450,     0,     0,     0,   309,
     305,   308,   290,    50,    51,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
       0,     0,   348,   678,   675,   676,   677,   682,   681,   683,
     679,   680,    99,    94,   102,    93,    89,    87,    88,    86,
       0,    85,    90,    91,   100,   101,    92,    96,    95,    77,
      76,    81,    78,    80,    79,    97,    98,     0,     0,   389,
     141,     0,     0,     0,   153,     0,   145,   146,   148,   147,
       0,     0,     0,     0,   123,   363,     0,     0,     0,   365,
      31,    32,    33,    34,    35,    36,    37,   278,   279,   271,
     288,   287,     0,   286,   272,   274,   282,   275,   273,   281,
     268,   280,   270,   269,    38,    38,    38,    40,    39,   276,
     277,   433,   436,   437,   447,   444,   430,   445,   442,   443,
       0,   441,   446,   429,   435,   432,   434,   448,   431,   465,
     466,   480,   481,   603,     0,   577,     0,   328,   329,   339,
     335,   336,   338,   343,   340,   341,   334,   342,   337,     0,
     333,   327,   346,   345,   344,   326,   457,   456,   312,   311,
     296,   297,   295,     0,   294,     0,     0,     0,   120,   121,
     187,   184,   234,   246,   221,   230,     0,   219,   224,   240,
       0,   233,   238,   244,   223,   226,   235,   237,   241,   231,
     239,   227,   245,   229,   236,   225,   228,     0,   217,   180,
     182,   185,   186,   197,   198,   199,   192,   210,   193,   194,
     195,   205,   213,   196,   207,   211,   201,   212,   202,   206,
     200,   209,   204,   203,   208,     0,   191,   181,   183,   357,
     355,   356,    83,     0,   395,   400,   406,   409,   402,   408,
     403,   407,   405,   401,   404,     0,   399,   149,     0,     0,
       0,     0,   144,   132,   131,   133,   134,   372,   378,   384,
     387,   380,   386,   381,   385,   383,   379,   382,     0,   377,
     373,   284,     0,    41,    42,    43,   439,     0,   604,   578,
     331,     0,   292,     0,   310,   307,   306,     0,     0,     0,
       0,     0,     0,   215,     0,   189,     0,    84,   397,     0,
       0,     0,     0,     0,   143,   375,     0,   285,   440,   332,
     293,   220,   243,   218,   242,   232,   222,   216,   190,   398,
     150,   152,   151,   163,   162,   158,   160,   164,   161,   157,
     159,     0,   156,   376,   154,     0,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -775,  -775,  -775,  -385,  -316,  -774,  -650,  -775,  -775,   708,
    -775,  -775,  -775,  -775,   979,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,   -64,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    1064,  -775,  -775,  -775,  -775,  -775,  -775,   668,  -775,  -775,
    -775,  -775,  -775,   587,  -775,  -775,  -775,  -775,  -775,  -775,
     983,  -775,  -775,  -775,  -775,   110,  -775,  -775,  -775,  -775,
    -775,  -156,  -775,  -775,  -775,   671,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -109,  -775,  -775,
    -775,  -103,  -775,  -775,  -775,   984,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,   -71,  -775,  -775,  -775,  -775,  -775,
     -81,  -775,   716,  -775,  -775,  -775,    38,  -775,  -775,  -775,
    -775,  -775,   741,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
     -75,  -775,  -775,  -775,  -775,  -775,  -775,   677,  -775,  -775,
    -775,  -775,  -775,   990,  -775,  -775,  -775,  -775,   617,  -775,
    -775,  -775,  -775,  -775,   -88,  -775,  -775,  -775,   651,  -775,
    -775,  -775,  -775,   -80,  -775,  -775,  -775,   991,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,   -56,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,   745,  -775,
    -775,  -775,  -775,  -775,   837,  -775,  -775,  -775,  -775,  1112,
    -775,  -775,  -775,  -775,   823,  -775,  -775,  -775,  -775,  1063,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,    92,  -775,  -775,  -775,    96,  -775,
    -775,  -775,  -775,  -775,  -775,  1139,  -775,  -775,  -775,  -775,
    -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775,   995,  -775,  -775,  -775,  -775,  -775,  -775,  -775,
    -775,  -775
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   845,   846,  1117,  1118,    27,   225,   226,
     227,   228,    28,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   562,  1050,  1051,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,    29,    77,
      78,    79,    80,    81,    30,    63,   510,   511,   512,   513,
      31,    70,   597,   598,   599,   600,   601,   602,    32,   299,
     300,   301,   302,   303,  1075,  1076,  1077,  1078,  1079,  1260,
    1341,  1342,    33,    64,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   769,  1235,  1236,   536,   764,
    1207,  1208,    34,    53,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   639,  1102,  1103,    35,    61,   496,   749,  1173,
    1174,   497,   498,   499,  1177,  1010,  1011,   500,   501,    36,
      59,   474,   475,   476,   477,   478,   479,   480,   734,  1159,
    1160,   481,   482,   483,    37,    65,   541,   542,   543,   544,
     545,    38,   307,   308,   309,    39,    72,   610,   611,   612,
     613,   614,   830,  1278,  1279,    40,    68,   583,   584,   585,
     586,   813,  1255,  1256,    41,    54,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   661,  1130,  1131,
     394,   395,   396,   397,   398,    42,    60,   487,   488,   489,
     490,    43,    55,   402,   403,   404,   405,    44,   118,   119,
     120,    45,    57,   412,   413,   414,   415,    46,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   443,   971,   972,   214,   442,   947,   948,   215,
     216,   217,   218,    47,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      48,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     875,   876,   621,  1128,   874,   624,   625,   626,    73,   628,
     629,   507,  1170,   491,   592,   297,   580,   297,   537,   232,
     592,   399,  1046,   305,   507,   116,  1100,   409,   409,    51,
     715,   484,   514,   399,   716,   717,  1143,    52,    74,   718,
    1144,   222,    56,   222,   305,    58,    75,    62,   484,   116,
     537,   515,   122,   233,   606,    49,    50,   123,   124,   538,
     125,   126,   234,   235,   236,   127,  1145,   237,   238,   492,
    1146,   516,   239,   240,   241,   128,   129,   130,   493,  1071,
     494,   879,   880,    73,   131,   606,   400,   132,   133,   134,
     117,   538,  1071,  1242,   135,   508,    66,  1243,   400,   517,
    1311,   682,   539,   684,   685,  1101,  1047,   688,   508,    67,
    1048,   136,   137,    74,   117,   696,    76,   580,    69,    71,
     701,    75,   593,   138,   581,   113,   139,   140,   593,   710,
     711,   306,   114,   115,   539,   410,   410,   141,   121,   219,
     518,   724,   495,   726,   727,   142,   223,   143,   223,   144,
     540,   145,   306,   401,   146,   147,   253,   519,   220,   411,
     411,  1171,   607,   485,   221,   401,   148,   224,  1049,   224,
    1172,   149,   150,  1281,   151,   152,   153,  1282,   229,   154,
     485,  1286,   540,   311,   254,  1287,   255,  1072,   594,   520,
     521,    76,   509,   607,   594,  1290,  -142,  1292,  -142,  1291,
    1072,  1293,  1129,   312,   155,   509,   595,  1114,  1115,  1116,
    1303,   230,   595,   256,  1304,   156,   157,   158,   159,   160,
     161,   162,   596,  1305,   257,   581,  1308,  1306,   596,  1315,
    1309,   333,   782,  1316,   231,   502,   258,   259,   260,   465,
    1344,   522,   582,   298,  1345,   298,   315,   313,   334,   335,
     261,   751,   824,   336,   262,   589,   778,   555,   466,   673,
     486,   523,   759,   407,   263,   524,   679,   264,   265,   744,
     772,   163,   164,   165,    82,   166,   167,   486,   467,   505,
     608,  1073,   604,   609,   168,   296,   169,   314,   557,   368,
     463,   369,   832,   370,  1073,   304,   266,   310,   337,   317,
      83,    84,  1333,   318,  1334,  1074,   468,    85,   371,   319,
     320,   608,   267,   874,   609,   268,   269,   270,  1074,   338,
     339,   340,   862,   341,   321,   587,   866,   342,   372,   869,
    1261,   322,   343,   873,   323,    86,    87,    88,    89,   344,
    1283,  1284,  1285,   582,   324,   373,   325,   374,   345,   346,
      90,    91,    92,  1335,   326,   814,   375,   591,   327,   347,
      93,    94,    95,   271,   469,    96,   328,   329,   376,   465,
    1336,   330,   470,   471,   620,   406,   416,   417,   418,   232,
     348,   419,   420,   421,   422,   423,   272,   273,   466,   424,
    1149,   425,   472,   426,   578,   427,   618,   377,   428,   838,
     839,   840,   841,   842,   843,   844,   429,   430,   467,  1337,
    1338,   431,   514,   233,   432,   433,  1150,   491,   378,   434,
     435,   436,   234,   235,   236,   349,   437,   237,   238,   438,
     439,   515,   239,   240,   241,   440,   468,   379,   441,   122,
     444,   445,   446,   447,   123,   124,   380,   125,   126,  1151,
     448,   516,   127,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
     449,  1339,   128,   129,   130,   450,   451,  1340,   473,   652,
     452,   131,   615,   492,   132,   133,   134,   740,   453,   517,
     454,   135,   493,   455,   494,  1152,  1153,   456,   457,   458,
     459,  1154,   460,   461,   469,   462,   381,   503,   136,   137,
     504,   546,   470,   471,   547,   548,   549,   550,   551,   552,
     138,   553,   331,   139,   140,  1155,   554,   558,   559,   382,
     518,   368,   472,   369,   141,   370,   560,   669,   561,   616,
    1156,   563,   142,  1245,   143,   564,   144,   519,   145,   565,
     371,   146,   147,   566,   567,   568,   495,  1182,   569,   570,
     571,   572,   573,   148,   574,   575,   576,   577,   149,   150,
     372,   151,   152,   153,  1183,  1184,   154,   588,   603,   520,
     521,   617,   619,   620,   622,  1185,   623,   373,   627,   374,
     630,   631,   632,   633,   634,   635,   636,   683,   375,   637,
     638,   155,   640,  1157,   641,   642,   654,   643,   473,  1246,
     376,   333,   156,   157,   158,   159,   160,   161,   162,  1312,
     644,   645,  1158,  1186,  1187,   646,  1188,   647,   334,   335,
     648,   522,   649,   336,   650,   651,   253,   655,   656,   377,
     657,  1247,   658,   659,   660,   662,   663,   664,   665,  1248,
     666,   523,   667,   668,   671,   524,   672,   675,  1249,  1189,
     378,   676,   681,   677,   254,   678,   255,  1190,   163,   164,
     165,   686,   166,   167,   687,   689,   690,   691,   337,   379,
     692,   168,  1250,   169,  1251,  1252,   693,   694,   380,  1191,
     697,  1192,  1193,   256,   698,   699,   695,   700,  1253,   338,
     339,   340,   702,   341,   257,   703,  1254,   342,   704,  1194,
     705,   706,   343,   707,   709,   712,   258,   259,   260,   344,
     708,   713,   714,   719,   720,   721,   722,   725,   345,   346,
     261,   723,  1195,  1268,   262,   728,   729,  1196,   381,   347,
     732,  1197,   733,   753,   263,  1198,   754,   264,   265,   730,
    1199,   731,   780,   735,  1200,   736,   737,   746,   738,   739,
     348,   382,   742,   743,   747,  1201,   748,  1202,  1203,   750,
    1204,     2,     3,   755,   756,     4,   266,   949,   757,   950,
     951,  1205,   758,   761,   762,   763,   774,     5,   765,  1206,
     766,     6,   267,     7,   781,   268,   269,   270,   783,  1269,
     784,     8,   767,   768,   785,   349,   770,   771,   775,   776,
     777,   786,   789,     9,   787,   788,   790,   791,    10,    11,
     792,   793,   795,   794,   796,  1213,   797,  1214,  1215,   798,
     812,  1270,   799,   800,   801,   802,   803,   804,    12,  1271,
     810,   805,    13,   271,   806,   807,   808,   809,  1272,   811,
     816,   817,   826,   860,   861,    14,   818,   864,   819,   820,
     865,   867,   821,   822,   823,   927,   272,   273,   827,   829,
     828,   834,  1273,   868,  1274,  1275,   835,   831,    15,    16,
     836,   837,   847,   848,   849,   850,   851,   852,  1276,   853,
     854,   855,   856,    17,   857,   858,  1277,   859,   870,   863,
     952,   953,   954,   871,   872,   955,   956,   874,   957,   958,
      18,   959,   877,   960,   878,   881,   961,   882,   962,   963,
     883,   885,    19,    20,   964,   884,   886,   887,   965,   888,
     889,   890,   966,   967,   968,   891,   892,   894,   893,   969,
     895,   898,   899,   506,   970,   896,   897,    21,  1216,  1217,
    1218,   995,   996,  1219,  1220,   900,  1221,  1222,   901,  1223,
      22,  1224,   902,   903,  1225,    23,  1226,  1227,   904,   905,
      24,   906,  1228,    25,   994,   997,  1229,   907,   998,   908,
    1230,  1231,  1232,   909,    82,   910,   911,  1233,   928,   929,
     930,   912,  1234,   931,   932,   913,   933,   934,   914,   935,
     915,   936,   916,   917,   937,   999,   938,   939,   918,  1000,
      83,    84,   940,   919,  1001,   920,   941,    85,   921,   922,
     942,   943,   944,   923,  1003,  1004,   924,   945,  1006,   925,
     926,   973,   946,  1007,  1009,   974,   975,  1015,  1016,   976,
     977,   978,  1018,  1019,  1021,    86,    87,    88,    89,  1008,
    1022,   979,   980,   981,  1023,   982,   983,   984,   985,   986,
      90,    91,    92,   987,   988,   989,   990,   991,   992,   993,
      93,    94,    95,  1002,  1005,    96,  1012,  1013,  1014,  1017,
    1026,  1024,  1027,  1020,  1028,  1029,  1025,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1067,
    1080,  1042,  1043,  1044,  1045,  1052,  1053,  1054,  1055,  1056,
    1057,  1058,  1081,  1059,  1060,  1061,  1082,  1062,  1063,  1064,
    1065,  1083,  1066,  1086,  1069,  1070,  1068,  1084,  1085,  1087,
    1088,  1294,  1258,  1089,  1097,  1297,  1098,  1099,  1104,  1105,
    1310,  1106,  1107,  1108,  1321,  1322,  1109,  1110,  1111,  1323,
    1112,   316,  1113,  1119,  1120,  1324,  1121,  1325,  1122,  1123,
    1124,  1326,  1125,  1126,  1127,  1132,  1133,  1134,  1135,  1136,
    1137,  1138,  1139,  1140,  1141,  1142,  1147,  1148,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1175,   760,  1307,
    1178,  1179,  1176,  1180,   825,  1262,  1181,  1209,  1210,  1346,
    1211,  1212,  1237,  1238,  1239,  1240,   773,  1328,  1241,  1244,
    1257,  1327,  1263,  1264,  1259,  1265,  1266,  1267,  1280,  1298,
    1296,  1317,  1320,   752,  1295,   741,  1319,  1299,   779,  1300,
    1301,  1302,  1313,  1314,  1330,  1331,  1332,   833,  1343,  1329,
     408,  1318,   745,   464,   815,   680,   332,   556,  1289,   674,
    1288,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   653,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   670
};

static const yytype_int16 yycheck[] =
{
     650,   651,   318,     8,   117,   321,   322,   323,     1,   325,
     326,     1,    49,     1,     1,     1,     1,     1,     1,     1,
       1,     1,    17,     1,     1,     1,    53,     1,     1,   240,
     219,     1,     1,     1,   223,   219,   238,   240,    31,   223,
     242,     1,   240,     1,     1,   240,    39,   240,     1,     1,
       1,    20,     1,    35,     1,   238,   239,     6,     7,    42,
       9,    10,    44,    45,    46,    14,   238,    49,    50,    57,
     242,    40,    54,    55,    56,    24,    25,    26,    66,     1,
      68,   186,   187,     1,    33,     1,    66,    36,    37,    38,
      66,    42,     1,   238,    43,    85,   240,   242,    66,    68,
     213,   417,    85,   419,   420,   132,   101,   423,    85,   240,
     105,    60,    61,    31,    66,   431,   109,     1,   240,   240,
     436,    39,   109,    72,   109,   240,    75,    76,   109,   445,
     446,   109,   240,   240,    85,   109,   109,    86,   240,   240,
     109,   457,   130,   459,   460,    94,   106,    96,   106,    98,
     133,   100,   109,   133,   103,   104,     1,   126,   240,   133,
     133,   198,   109,   133,   240,   133,   115,   127,   163,   127,
     207,   120,   121,   238,   123,   124,   125,   242,   240,   128,
     133,   238,   133,   238,    29,   242,    31,   109,   175,   158,
     159,   109,   182,   109,   175,   238,   182,   238,   182,   242,
     109,   242,   207,   241,   153,   182,   193,    11,    12,    13,
     238,   240,   193,    58,   242,   164,   165,   166,   167,   168,
     169,   170,   209,   238,    69,   109,   238,   242,   209,   238,
     242,     1,   548,   242,   240,   238,    81,    82,    83,     1,
     238,   210,   227,   229,   242,   229,   239,   241,    18,    19,
      95,   239,   239,    23,    99,   239,   239,   239,    20,   239,
     230,   230,   239,   239,   109,   234,   239,   112,   113,   239,
     239,   220,   221,   222,     1,   224,   225,   230,    40,   239,
     227,   203,   239,   230,   233,   240,   235,   241,   238,     1,
     239,     3,   239,     5,   203,   240,   141,   240,    68,   241,
      27,    28,    71,   241,    73,   227,    68,    34,    20,   241,
     241,   227,   157,   117,   230,   160,   161,   162,   227,    89,
      90,    91,   638,    93,   241,   238,   642,    97,    40,   645,
     239,   241,   102,   649,   241,    62,    63,    64,    65,   109,
    1114,  1115,  1116,   227,   241,    57,   241,    59,   118,   119,
      77,    78,    79,   122,   241,   239,    68,   182,   241,   129,
      87,    88,    89,   208,   126,    92,   241,   241,    80,     1,
     139,   241,   134,   135,   117,   241,   241,   241,   241,     1,
     150,   241,   241,   241,   241,   241,   231,   232,    20,   241,
      15,   241,   154,   241,   239,   241,   238,   109,   241,   142,
     143,   144,   145,   146,   147,   148,   241,   241,    40,   178,
     179,   241,     1,    35,   241,   241,    41,     1,   130,   241,
     241,   241,    44,    45,    46,   195,   241,    49,    50,   241,
     241,    20,    54,    55,    56,   241,    68,   149,   241,     1,
     241,   241,   241,   241,     6,     7,   158,     9,    10,    74,
     241,    40,    14,   838,   839,   840,   841,   842,   843,   844,
     241,   230,    24,    25,    26,   241,   241,   236,   230,   239,
     241,    33,   131,    57,    36,    37,    38,   239,   241,    68,
     241,    43,    66,   241,    68,   110,   111,   241,   241,   241,
     241,   116,   241,   241,   126,   241,   208,   241,    60,    61,
     241,   241,   134,   135,   241,   241,   241,   241,   241,   241,
      72,   241,   239,    75,    76,   140,   241,   241,   241,   231,
     109,     1,   154,     3,    86,     5,   241,   239,   241,   131,
     155,   241,    94,    73,    96,   241,    98,   126,   100,   241,
      20,   103,   104,   241,   241,   241,   130,     4,   241,   241,
     241,   241,   241,   115,   241,   241,   241,   241,   120,   121,
      40,   123,   124,   125,    21,    22,   128,   241,   241,   158,
     159,   131,   117,   117,   219,    32,   117,    57,   117,    59,
     117,   117,   117,   117,   238,   238,   241,   117,    68,   241,
     241,   153,   241,   218,   241,   241,   238,   241,   230,   139,
      80,     1,   164,   165,   166,   167,   168,   169,   170,  1259,
     241,   241,   237,    70,    71,   241,    73,   241,    18,    19,
     241,   210,   241,    23,   241,   241,     1,   241,   241,   109,
     241,   171,   241,   241,   241,   241,   241,   241,   241,   179,
     241,   230,   241,   241,   241,   234,   241,   131,   188,   106,
     130,   238,   219,   241,    29,   241,    31,   114,   220,   221,
     222,   219,   224,   225,   117,   219,   117,   117,    68,   149,
     117,   233,   212,   235,   214,   215,   219,   219,   158,   136,
     117,   138,   139,    58,   117,   117,   219,   117,   228,    89,
      90,    91,   117,    93,    69,   117,   236,    97,   117,   156,
     117,   219,   102,   241,   219,   219,    81,    82,    83,   109,
     241,   219,   219,   219,   219,   219,   219,   219,   118,   119,
      95,   117,   179,    73,    99,   219,   117,   184,   208,   129,
     241,   188,   241,   131,   109,   192,   131,   112,   113,   238,
     197,   238,   219,   241,   201,   241,   241,   238,   241,   241,
     150,   231,   241,   241,   241,   212,   241,   214,   215,   241,
     217,     0,     1,   238,   238,     4,   141,    49,   241,    51,
      52,   228,   241,   238,   241,   241,   238,    16,   241,   236,
     241,    20,   157,    22,   219,   160,   161,   162,   131,   139,
     219,    30,   241,   241,   131,   195,   241,   241,   241,   241,
     241,   219,   238,    42,   219,   219,   117,   131,    47,    48,
     219,   131,   131,   241,   131,    49,   117,    51,    52,   117,
     241,   171,   131,   131,   131,   131,   131,   131,    67,   179,
     238,   131,    71,   208,   131,   131,   131,   131,   188,   238,
     219,   238,   131,   117,   117,    84,   240,   117,   238,   241,
     117,   117,   241,   241,   241,    49,   231,   232,   238,   241,
     238,   238,   212,   117,   214,   215,   238,   241,   107,   108,
     238,   238,   238,   238,   238,   238,   238,   238,   228,   238,
     238,   238,   238,   122,   238,   238,   236,   238,   131,   241,
     172,   173,   174,   117,   117,   177,   178,   117,   180,   181,
     139,   183,   238,   185,   131,   131,   188,   219,   190,   191,
     131,   241,   151,   152,   196,   131,   131,   131,   200,   117,
     131,   131,   204,   205,   206,   131,   131,   131,   238,   211,
     131,   131,   131,   225,   216,   238,   238,   176,   172,   173,
     174,   219,   241,   177,   178,   238,   180,   181,   238,   183,
     189,   185,   238,   238,   188,   194,   190,   191,   238,   238,
     199,   238,   196,   202,   131,   131,   200,   238,   117,   238,
     204,   205,   206,   238,     1,   238,   238,   211,   172,   173,
     174,   238,   216,   177,   178,   238,   180,   181,   238,   183,
     238,   185,   238,   238,   188,   131,   190,   191,   238,   131,
      27,    28,   196,   238,   131,   238,   200,    34,   238,   238,
     204,   205,   206,   238,   131,   131,   238,   211,   131,   238,
     238,   238,   216,   131,   117,   238,   238,   131,   131,   238,
     238,   238,   131,   219,   131,    62,    63,    64,    65,   241,
     131,   238,   238,   238,   131,   238,   238,   238,   238,   238,
      77,    78,    79,   238,   238,   238,   238,   238,   238,   238,
      87,    88,    89,   238,   238,    92,   238,   238,   238,   238,
     131,   219,   131,   241,   238,   131,   241,   131,   131,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   131,
     131,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   131,   238,   238,   238,   131,   238,   238,   238,
     238,   131,   238,   131,   238,   238,   241,   238,   238,   241,
     131,   117,   241,   238,   238,   243,   238,   238,   238,   238,
     131,   238,   238,   238,   137,   139,   238,   238,   238,   137,
     238,    77,   238,   238,   238,   139,   238,   137,   238,   238,
     238,   137,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   226,   510,  1243,
     238,   238,   242,   238,   597,  1075,   238,   238,   238,  1345,
     238,   238,   238,   238,   238,   238,   525,  1306,   238,   238,
     238,  1304,   238,   238,   241,   238,   238,   238,   238,   243,
     238,  1282,  1293,   497,  1176,   474,  1291,   243,   541,   243,
     243,   243,   241,   238,   238,   238,   238,   610,  1316,  1309,
     118,  1287,   487,   170,   583,   412,    97,   242,  1146,   402,
    1144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   307,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   350,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   383
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   245,     0,     1,     4,    16,    20,    22,    30,    42,
      47,    48,    67,    71,    84,   107,   108,   122,   139,   151,
     152,   176,   189,   194,   199,   202,   246,   251,   256,   282,
     288,   294,   302,   316,   336,   359,   373,   388,   395,   399,
     409,   418,   439,   445,   451,   455,   461,   517,   534,   238,
     239,   240,   240,   337,   419,   446,   240,   456,   240,   374,
     440,   360,   240,   289,   317,   389,   240,   240,   410,   240,
     295,   240,   400,     1,    31,    39,   109,   283,   284,   285,
     286,   287,     1,    27,    28,    34,    62,    63,    64,    65,
      77,    78,    79,    87,    88,    89,    92,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   240,   240,   240,     1,    66,   452,   453,
     454,   240,     1,     6,     7,     9,    10,    14,    24,    25,
      26,    33,    36,    37,    38,    43,    60,    61,    72,    75,
      76,    86,    94,    96,    98,   100,   103,   104,   115,   120,
     121,   123,   124,   125,   128,   153,   164,   165,   166,   167,
     168,   169,   170,   220,   221,   222,   224,   225,   233,   235,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   509,   513,   514,   515,   516,   240,
     240,   240,     1,   106,   127,   252,   253,   254,   255,   240,
     240,   240,     1,    35,    44,    45,    46,    49,    50,    54,
      55,    56,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,     1,    29,    31,    58,    69,    81,    82,
      83,    95,    99,   109,   112,   113,   141,   157,   160,   161,
     162,   208,   231,   232,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   240,     1,   229,   303,
     304,   305,   306,   307,   240,     1,   109,   396,   397,   398,
     240,   238,   241,   241,   241,   239,   284,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   239,   519,     1,    18,    19,    23,    68,    89,    90,
      91,    93,    97,   102,   109,   118,   119,   129,   150,   195,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,     1,     3,
       5,    20,    40,    57,    59,    68,    80,   109,   130,   149,
     158,   208,   231,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   434,   435,   436,   437,   438,     1,
      66,   133,   447,   448,   449,   450,   241,   239,   453,     1,
     109,   133,   457,   458,   459,   460,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   510,   506,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   239,   463,     1,    20,    40,    68,   126,
     134,   135,   154,   230,   375,   376,   377,   378,   379,   380,
     381,   385,   386,   387,     1,   133,   230,   441,   442,   443,
     444,     1,    57,    66,    68,   130,   361,   365,   366,   367,
     371,   372,   238,   241,   241,   239,   253,     1,    85,   182,
     290,   291,   292,   293,     1,    20,    40,    68,   109,   126,
     158,   159,   210,   230,   234,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   332,     1,    42,    85,
     133,   390,   391,   392,   393,   394,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   239,   536,   238,   241,   241,
     241,   241,   266,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   239,   258,
       1,   109,   227,   411,   412,   413,   414,   238,   241,   239,
     304,   182,     1,   109,   175,   193,   209,   296,   297,   298,
     299,   300,   301,   241,   239,   397,     1,   109,   227,   230,
     401,   402,   403,   404,   405,   131,   131,   131,   238,   117,
     117,   248,   219,   117,   248,   248,   248,   117,   248,   248,
     117,   117,   117,   117,   238,   238,   241,   241,   241,   356,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   239,   339,   238,   241,   241,   241,   241,   241,
     241,   431,   241,   241,   241,   241,   241,   241,   241,   239,
     421,   241,   241,   239,   448,   131,   238,   241,   241,   239,
     458,   219,   248,   117,   248,   248,   219,   117,   248,   219,
     117,   117,   117,   219,   219,   219,   248,   117,   117,   117,
     117,   248,   117,   117,   117,   117,   219,   241,   241,   219,
     248,   248,   219,   219,   219,   219,   223,   219,   223,   219,
     219,   219,   219,   117,   248,   219,   248,   248,   219,   117,
     238,   238,   241,   241,   382,   241,   241,   241,   241,   241,
     239,   376,   241,   241,   239,   442,   238,   241,   241,   362,
     241,   239,   366,   131,   131,   238,   238,   241,   241,   239,
     291,   238,   241,   241,   333,   241,   241,   241,   241,   329,
     241,   241,   239,   319,   238,   241,   241,   241,   239,   391,
     219,   219,   248,   131,   219,   131,   219,   219,   219,   238,
     117,   131,   219,   131,   241,   131,   131,   117,   117,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     238,   238,   241,   415,   239,   412,   219,   238,   240,   238,
     241,   241,   241,   241,   239,   297,   131,   238,   238,   241,
     406,   241,   239,   402,   238,   238,   238,   238,   142,   143,
     144,   145,   146,   147,   148,   247,   248,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     117,   117,   248,   241,   117,   117,   248,   117,   117,   248,
     131,   117,   117,   248,   117,   250,   250,   238,   131,   186,
     187,   131,   219,   131,   131,   241,   131,   131,   117,   131,
     131,   131,   131,   238,   131,   131,   238,   238,   131,   131,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,    49,   172,   173,
     174,   177,   178,   180,   181,   183,   185,   188,   190,   191,
     196,   200,   204,   205,   206,   211,   216,   511,   512,    49,
      51,    52,   172,   173,   174,   177,   178,   180,   181,   183,
     185,   188,   190,   191,   196,   200,   204,   205,   206,   211,
     216,   507,   508,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   131,   219,   241,   131,   117,   131,
     131,   131,   238,   131,   131,   238,   131,   131,   241,   117,
     369,   370,   238,   238,   238,   131,   131,   238,   131,   219,
     241,   131,   131,   131,   219,   241,   131,   131,   238,   131,
     131,   131,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,    17,   101,   105,   163,
     267,   268,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   131,   241,   238,
     238,     1,   109,   203,   227,   308,   309,   310,   311,   312,
     131,   131,   131,   131,   238,   238,   131,   241,   131,   238,
     247,   247,   247,   247,   247,   247,   247,   238,   238,   238,
      53,   132,   357,   358,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,    11,    12,    13,   249,   250,   238,
     238,   238,   238,   238,   238,   238,   238,   238,     8,   207,
     432,   433,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   242,   238,   242,   238,   238,    15,
      41,    74,   110,   111,   116,   140,   155,   218,   237,   383,
     384,   238,   238,   238,   238,   238,   238,   238,   238,   238,
      49,   198,   207,   363,   364,   226,   242,   368,   238,   238,
     238,   238,     4,    21,    22,    32,    70,    71,    73,   106,
     114,   136,   138,   139,   156,   179,   184,   188,   192,   197,
     201,   212,   214,   215,   217,   228,   236,   334,   335,   238,
     238,   238,   238,    49,    51,    52,   172,   173,   174,   177,
     178,   180,   181,   183,   185,   188,   190,   191,   196,   200,
     204,   205,   206,   211,   216,   330,   331,   238,   238,   238,
     238,   238,   238,   242,   238,    73,   139,   171,   179,   188,
     212,   214,   215,   228,   236,   416,   417,   238,   241,   241,
     313,   239,   309,   238,   238,   238,   238,   238,    73,   139,
     171,   179,   188,   212,   214,   215,   228,   236,   407,   408,
     238,   238,   242,   249,   249,   249,   238,   242,   512,   508,
     238,   242,   238,   242,   117,   370,   238,   243,   243,   243,
     243,   243,   243,   238,   242,   238,   242,   268,   238,   242,
     131,   213,   250,   241,   238,   238,   242,   358,   433,   384,
     364,   137,   139,   137,   139,   137,   137,   335,   331,   417,
     238,   238,   238,    71,    73,   122,   139,   178,   179,   230,
     236,   314,   315,   408,   238,   242,   315
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   244,   245,   245,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   247,   247,
     248,   248,   248,   248,   248,   248,   248,   248,   249,   249,
     250,   250,   250,   250,   251,   252,   252,   253,   253,   253,
     254,   255,   256,   257,   257,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   259,   260,   261,   262,
     263,   264,   266,   265,   267,   267,   268,   268,   268,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   283,   284,   284,   284,   284,
     285,   286,   287,   289,   288,   290,   290,   291,   291,   291,
     292,   293,   295,   294,   296,   296,   297,   297,   297,   297,
     297,   298,   299,   300,   301,   302,   303,   303,   304,   304,
     304,   305,   307,   306,   308,   308,   309,   309,   309,   309,
     310,   311,   311,   313,   312,   314,   314,   315,   315,   315,
     315,   315,   315,   315,   315,   317,   316,   318,   318,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   329,   328,
     330,   330,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   333,   332,   334,   334,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   337,   336,   338,
     338,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   356,   355,   357,   357,   358,   358,   360,
     359,   362,   361,   363,   363,   364,   364,   364,   365,   365,
     366,   366,   366,   366,   366,   368,   367,   369,   369,   370,
     370,   371,   372,   374,   373,   375,   375,   376,   376,   376,
     376,   376,   376,   376,   376,   376,   377,   378,   379,   380,
     382,   381,   383,   383,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   385,   386,   387,   389,   388,   390,
     390,   391,   391,   391,   391,   392,   393,   394,   395,   396,
     396,   397,   397,   398,   400,   399,   401,   401,   402,   402,
     402,   402,   403,   404,   406,   405,   407,   407,   408,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   410,   409,
     411,   411,   412,   412,   412,   413,   415,   414,   416,   416,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     419,   418,   420,   420,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   429,   431,   430,
     432,   432,   433,   433,   434,   435,   436,   437,   438,   440,
     439,   441,   441,   442,   442,   442,   443,   444,   446,   445,
     447,   447,   448,   448,   448,   449,   450,   451,   452,   452,
     453,   453,   454,   456,   455,   457,   457,   458,   458,   458,
     459,   460,   461,   462,   462,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   491,   492,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   506,   505,   507,   507,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   510,   509,   511,   511,   512,   512,   512,   512,
     512,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     512,   512,   512,   512,   512,   512,   513,   514,   515,   516,
     517,   518,   518,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   535,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545
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
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4
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
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2969 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2987 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 428 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 3002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 3011 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 483 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_certificate_file);
    ConfigServerInfo.ssl_certificate_file = xstrdup(yylval.string);
  }
}
#line 3023 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 492 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 3035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 501 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_param_file);
    ConfigServerInfo.ssl_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 510 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_cipher_list);
    ConfigServerInfo.ssl_cipher_list = xstrdup(yylval.string);
  }
}
#line 3059 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 519 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_message_digest_algorithm);
    ConfigServerInfo.ssl_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 528 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_elliptic_curve);
    ConfigServerInfo.ssl_dh_elliptic_curve = xstrdup(yylval.string);
  }
}
#line 3083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 537 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options = 0;
}
#line 3092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 544 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_STANDARD;
#endif
}
#line 3103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 550 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MEMORY_CACHE;
#endif
}
#line 3114 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 556 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MMAP_CACHE;
#endif
}
#line 3125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 562 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_CHECK_CACHE;
#endif
}
#line 3136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 570 "conf_parser.y" /* yacc.c:1646  */
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
#line 3154 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 585 "conf_parser.y" /* yacc.c:1646  */
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
#line 3172 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 600 "conf_parser.y" /* yacc.c:1646  */
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
#line 3190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 615 "conf_parser.y" /* yacc.c:1646  */
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
#line 3208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 630 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3221 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 640 "conf_parser.y" /* yacc.c:1646  */
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
#line 3238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 654 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3250 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 663 "conf_parser.y" /* yacc.c:1646  */
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
#line 3281 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 691 "conf_parser.y" /* yacc.c:1646  */
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
#line 3312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 719 "conf_parser.y" /* yacc.c:1646  */
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
#line 3340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 744 "conf_parser.y" /* yacc.c:1646  */
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
#line 3365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 766 "conf_parser.y" /* yacc.c:1646  */
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
#line 3390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 788 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 806 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3411 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 815 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 824 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 837 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 841 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 858 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 864 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3479 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 874 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3488 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 878 "conf_parser.y" /* yacc.c:1646  */
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
#line 3506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 896 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 902 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3524 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 908 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 914 "conf_parser.y" /* yacc.c:1646  */
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
#line 3554 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 942 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 948 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 952 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3596 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 976 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3604 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 979 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3612 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 984 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3621 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 991 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3630 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 995 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3639 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 999 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3648 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1003 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3657 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1007 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3666 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1011 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1015 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1019 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1036 "conf_parser.y" /* yacc.c:1646  */
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
#line 3762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1103 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3771 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1109 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3780 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1115 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3789 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1121 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3798 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1127 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3812 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1138 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3821 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1144 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3835 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1155 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3844 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1161 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3853 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1168 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3862 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1172 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1176 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1180 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1184 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1188 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1196 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1208 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1216 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3970 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3979 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1224 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3988 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1228 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3997 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4033 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4042 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1252 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4051 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1258 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4060 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4105 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4114 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4123 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4132 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4141 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1345 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1349 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4267 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4276 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1361 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4285 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1365 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1369 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4303 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1373 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1377 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4321 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1387 "conf_parser.y" /* yacc.c:1646  */
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
#line 4338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1399 "conf_parser.y" /* yacc.c:1646  */
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
#line 4385 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1462 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4394 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1468 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4403 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1474 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4412 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1480 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4421 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1486 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4430 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1492 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1498 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1504 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1510 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4466 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1516 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1523 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4485 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1529 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1535 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1541 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1550 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4527 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1559 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4536 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1566 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4545 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1570 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4554 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1580 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1586 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1592 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4580 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1596 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1600 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1608 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4604 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1613 "conf_parser.y" /* yacc.c:1646  */
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
#line 4622 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1626 "conf_parser.y" /* yacc.c:1646  */
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
#line 4642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1643 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1649 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4660 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1659 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4669 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1663 "conf_parser.y" /* yacc.c:1646  */
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
#line 4714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1716 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1722 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1728 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1734 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4755 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1745 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1752 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1756 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1760 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1764 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1768 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1772 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1776 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1780 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1784 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1788 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1794 "conf_parser.y" /* yacc.c:1646  */
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
#line 4871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1808 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1817 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1830 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1837 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1848 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1854 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1860 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1875 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1891 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1902 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1917 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1923 "conf_parser.y" /* yacc.c:1646  */
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
#line 5022 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1942 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5031 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1949 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1953 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5049 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1957 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5058 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1961 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5067 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1965 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5076 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1969 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1973 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1977 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1981 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1985 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5121 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1995 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2004 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5148 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2017 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5157 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2023 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5166 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2030 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5175 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5184 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2038 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5193 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2042 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5202 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 404:
#line 2046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5211 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2050 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5220 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2062 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5247 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2076 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2085 "conf_parser.y" /* yacc.c:1646  */
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
#line 5336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2165 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5345 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2171 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5354 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2177 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5363 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2183 "conf_parser.y" /* yacc.c:1646  */
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
#line 5379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2196 "conf_parser.y" /* yacc.c:1646  */
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
#line 5395 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2209 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5404 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2215 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2225 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5431 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2231 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2237 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2247 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5471 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2258 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2264 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2270 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2276 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2291 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2295 "conf_parser.y" /* yacc.c:1646  */
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
#line 5546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2320 "conf_parser.y" /* yacc.c:1646  */
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
#line 5569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2350 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5587 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2354 "conf_parser.y" /* yacc.c:1646  */
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
#line 5613 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2380 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5622 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2386 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5631 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 472:
#line 2401 "conf_parser.y" /* yacc.c:1646  */
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
#line 5648 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 473:
#line 2418 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5657 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 474:
#line 2422 "conf_parser.y" /* yacc.c:1646  */
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
#line 5677 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 480:
#line 2442 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5686 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 481:
#line 2448 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5695 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2511 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5703 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2516 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5711 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2521 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5719 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2526 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5727 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2531 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5736 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2537 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5744 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2542 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5752 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2547 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5760 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2552 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2557 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2562 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2567 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2572 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2577 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5808 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2582 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2587 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2592 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2597 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2602 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5848 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2607 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5857 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2613 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2618 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2623 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2628 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2633 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2638 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5905 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2643 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2648 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2651 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2656 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2659 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2664 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2669 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2674 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5969 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2679 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5977 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2684 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2689 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2694 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 6001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2699 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6009 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2704 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2709 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2714 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6033 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2719 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6041 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2724 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6049 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2730 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2733 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6065 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2736 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2739 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2745 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6105 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2751 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6113 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2754 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6121 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2760 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2763 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6145 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2766 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6153 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2769 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2775 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2778 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6185 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2781 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6193 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2784 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6201 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2790 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6217 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2793 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6225 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2798 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6233 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6257 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6265 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6273 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6281 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6289 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6297 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6305 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6313 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6321 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6329 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 618:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6337 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 619:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6345 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 620:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6353 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 621:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6361 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 622:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 623:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6377 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6385 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2861 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2871 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2876 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2909 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2914 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2919 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6449 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2924 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2929 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 2934 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 2939 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 2944 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 2949 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 2954 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 2959 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6513 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 2964 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6537 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 675:
#line 2997 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 676:
#line 3003 "conf_parser.y" /* yacc.c:1646  */
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
#line 6565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 677:
#line 3019 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6577 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 678:
#line 3028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6586 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 679:
#line 3034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6595 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 680:
#line 3040 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6604 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 681:
#line 3046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 682:
#line 3055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 683:
#line 3061 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6634 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6638 "conf_parser.c" /* yacc.c:1646  */
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
