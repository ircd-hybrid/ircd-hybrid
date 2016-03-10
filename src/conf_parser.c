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
    max_ident,
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


#line 180 "conf_parser.c" /* yacc.c:339  */

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
    MAX_IDENT = 343,
    MAX_IDLE = 344,
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
#define MAX_IDENT 343
#define MAX_IDLE 344
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
#line 142 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 693 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 710 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1390

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
       0,   380,   380,   381,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   411,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   422,   422,
     423,   424,   425,   426,   433,   435,   435,   436,   436,   436,
     438,   444,   454,   456,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   480,   489,   498,   507,
     516,   525,   535,   534,   540,   540,   541,   547,   553,   559,
     567,   582,   597,   612,   627,   637,   651,   660,   688,   716,
     741,   763,   785,   795,   797,   797,   798,   799,   800,   801,
     803,   812,   821,   835,   834,   852,   852,   853,   853,   853,
     855,   861,   872,   871,   890,   890,   891,   891,   891,   891,
     891,   893,   899,   905,   911,   933,   934,   934,   936,   936,
     937,   939,   946,   946,   959,   960,   962,   962,   963,   963,
     965,   973,   976,   982,   981,   987,   987,   988,   992,   996,
    1000,  1004,  1008,  1012,  1016,  1027,  1026,  1087,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,
    1100,  1106,  1112,  1118,  1124,  1135,  1141,  1152,  1159,  1158,
    1164,  1164,  1165,  1169,  1173,  1177,  1181,  1185,  1189,  1193,
    1197,  1201,  1205,  1209,  1213,  1217,  1221,  1225,  1229,  1233,
    1237,  1241,  1245,  1249,  1256,  1255,  1261,  1261,  1262,  1266,
    1270,  1274,  1278,  1282,  1286,  1290,  1294,  1298,  1302,  1306,
    1310,  1314,  1318,  1322,  1326,  1330,  1334,  1338,  1342,  1346,
    1350,  1354,  1358,  1362,  1366,  1370,  1374,  1385,  1384,  1441,
    1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,
    1451,  1452,  1453,  1454,  1454,  1455,  1456,  1457,  1458,  1460,
    1466,  1472,  1478,  1484,  1490,  1496,  1502,  1508,  1514,  1520,
    1527,  1533,  1539,  1545,  1554,  1564,  1563,  1569,  1569,  1570,
    1574,  1585,  1584,  1591,  1590,  1595,  1595,  1596,  1600,  1604,
    1610,  1610,  1611,  1611,  1611,  1611,  1611,  1613,  1613,  1615,
    1615,  1617,  1630,  1647,  1653,  1664,  1663,  1709,  1709,  1710,
    1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1720,  1726,
    1732,  1738,  1750,  1749,  1755,  1755,  1756,  1760,  1764,  1768,
    1772,  1776,  1780,  1784,  1788,  1792,  1798,  1812,  1821,  1835,
    1834,  1849,  1849,  1850,  1850,  1850,  1850,  1852,  1858,  1864,
    1874,  1876,  1876,  1877,  1877,  1879,  1896,  1895,  1918,  1918,
    1919,  1919,  1919,  1919,  1921,  1927,  1947,  1946,  1952,  1952,
    1953,  1957,  1961,  1965,  1969,  1973,  1977,  1981,  1985,  1989,
    2000,  1999,  2018,  2018,  2019,  2019,  2019,  2021,  2028,  2027,
    2033,  2033,  2034,  2038,  2042,  2046,  2050,  2054,  2058,  2062,
    2066,  2070,  2081,  2080,  2152,  2152,  2153,  2154,  2155,  2156,
    2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,
    2167,  2169,  2175,  2181,  2187,  2200,  2213,  2219,  2225,  2229,
    2236,  2235,  2240,  2240,  2241,  2245,  2251,  2262,  2268,  2274,
    2280,  2296,  2295,  2321,  2321,  2322,  2322,  2322,  2324,  2344,
    2355,  2354,  2381,  2381,  2382,  2382,  2382,  2384,  2390,  2400,
    2402,  2402,  2403,  2403,  2405,  2423,  2422,  2443,  2443,  2444,
    2444,  2444,  2446,  2452,  2462,  2464,  2464,  2465,  2466,  2467,
    2468,  2469,  2470,  2471,  2472,  2473,  2474,  2475,  2476,  2477,
    2478,  2479,  2480,  2481,  2482,  2483,  2484,  2485,  2486,  2487,
    2488,  2489,  2490,  2491,  2492,  2493,  2494,  2495,  2496,  2497,
    2498,  2499,  2500,  2501,  2502,  2503,  2504,  2505,  2506,  2507,
    2508,  2509,  2510,  2511,  2514,  2519,  2524,  2529,  2534,  2540,
    2545,  2550,  2555,  2560,  2565,  2570,  2575,  2580,  2585,  2590,
    2595,  2600,  2605,  2610,  2616,  2621,  2626,  2631,  2636,  2641,
    2646,  2651,  2654,  2659,  2662,  2667,  2672,  2677,  2682,  2687,
    2692,  2697,  2702,  2707,  2712,  2717,  2722,  2728,  2727,  2732,
    2732,  2733,  2736,  2739,  2742,  2745,  2748,  2751,  2754,  2757,
    2760,  2763,  2766,  2769,  2772,  2775,  2778,  2781,  2784,  2787,
    2790,  2793,  2796,  2802,  2801,  2806,  2806,  2807,  2810,  2813,
    2816,  2819,  2822,  2825,  2828,  2831,  2834,  2837,  2840,  2843,
    2846,  2849,  2852,  2855,  2858,  2861,  2864,  2869,  2874,  2879,
    2888,  2890,  2890,  2891,  2892,  2893,  2894,  2895,  2896,  2897,
    2898,  2899,  2900,  2901,  2902,  2904,  2909,  2914,  2919,  2924,
    2929,  2934,  2939,  2944,  2949,  2954,  2963,  2965,  2965,  2966,
    2967,  2968,  2969,  2970,  2971,  2972,  2973,  2974,  2975,  2977,
    2983,  2999,  3008,  3014,  3020,  3026,  3035,  3041
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
  "MAX_BANS", "MAX_CHANNELS", "MAX_GLOBAL", "MAX_IDENT", "MAX_IDLE",
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
  "class_max_number", "class_max_global", "class_max_local",
  "class_max_ident", "class_sendq", "class_recvq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
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
  "channel_max_bans", "channel_default_join_flood_count",
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

#define YYPACT_NINF -724

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-724)))

#define YYTABLE_NINF -143

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -724,   644,  -724,  -208,  -224,  -216,  -724,  -724,  -724,  -203,
    -724,  -201,  -724,  -724,  -724,  -182,  -724,  -724,  -724,  -165,
    -164,  -724,  -162,  -724,  -141,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,   302,   911,  -129,  -127,   -99,    15,   -93,   378,   -74,
     -72,   -71,    34,   -57,   -55,   -52,   649,   426,   -16,     9,
     -15,    69,   -12,  -136,    -7,    39,    43,    10,  -724,  -724,
    -724,  -724,  -724,    45,    68,    70,    75,    76,    81,    88,
      90,    93,    96,   114,     6,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,   656,   562,    16,
    -724,   119,    42,  -724,  -724,    49,  -724,   121,   122,   124,
     130,   133,   142,   152,   155,   156,   157,   163,   166,   167,
     169,   173,   178,   180,   183,   187,   190,   191,   193,   194,
     195,   198,  -724,  -724,   201,   202,   204,   205,   209,   211,
     212,   215,   217,   219,   222,   223,   225,   226,   227,   228,
     229,   230,   232,    52,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,   511,     2,   297,    54,   234,   238,    11,  -724,  -724,
    -724,    21,   303,   289,  -724,   239,   248,   250,   251,   253,
     254,   256,   259,   264,   150,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,    64,   266,   270,   271,   273,
    -724,   275,   276,   277,   279,   281,   282,   283,   285,   287,
     291,   295,   299,   300,   309,   320,   153,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,    62,   109,
     321,    59,  -724,  -724,  -724,    65,   240,  -724,   322,    25,
    -724,  -724,    13,  -724,   263,   317,   359,   292,  -724,   447,
     448,    78,   461,   448,   448,   462,   448,   448,   465,   467,
     351,  -724,   352,   350,   353,   354,  -724,   355,   366,   367,
     371,   374,   375,   376,   377,   379,   381,   383,   385,   388,
     249,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   394,
     392,   395,   398,   399,   401,   403,  -724,   409,   411,   414,
     415,   418,   420,   421,    51,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,   423,   425,    97,  -724,  -724,  -724,   488,   397,  -724,
    -724,   427,   429,    18,  -724,  -724,  -724,   435,   448,   476,
     448,   448,   453,   558,   464,   564,   567,   568,   472,   479,
     480,   448,   585,   587,   591,   592,   448,   593,   596,   597,
     598,   498,   439,   478,   502,   448,   448,   503,   504,   505,
    -179,  -174,   507,   508,   509,   512,   613,   448,   514,   448,
     448,   517,   620,   500,  -724,   501,   499,   513,  -724,   515,
     516,   518,   519,   520,   170,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,   521,   522,    30,  -724,  -724,
    -724,   506,   523,   526,  -724,   527,  -724,    29,  -724,  -724,
    -724,  -724,  -724,   611,   612,   531,  -724,   533,   532,   535,
      22,  -724,  -724,  -724,   539,   537,   538,  -724,   541,   543,
     545,   546,  -724,   547,   548,   120,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,   542,   549,   550,
     551,     3,  -724,  -724,  -724,  -724,   536,   575,   448,   619,
     578,   667,   580,   582,   583,   565,  -724,  -724,   687,   674,
     588,   680,   571,   684,   691,   701,   706,   697,   698,   699,
     703,   704,   708,   713,   714,   717,   718,   719,   599,  -724,
     618,   616,  -724,    56,  -724,  -724,  -724,  -724,   641,   625,
    -724,    60,   627,   626,   629,   632,   633,    17,  -724,  -724,
    -724,  -724,  -724,   737,   637,  -724,   638,   639,  -724,   642,
      24,  -724,  -724,  -724,  -724,   640,   646,   650,  -724,   651,
     412,   653,   662,   665,   669,   670,   672,   675,   676,   678,
     682,  -724,  -724,   762,   765,   448,   664,   801,   802,   806,
     448,   807,   812,   448,   800,   816,   817,   448,   818,   818,
     700,  -724,  -724,   811,  -119,   813,   724,   815,   819,   707,
     820,   821,   832,   822,   823,   824,   825,   720,  -724,   826,
     828,   722,  -724,   723,  -724,   831,   833,   729,  -724,   730,
     732,   735,   736,   740,   742,   743,   744,   745,   746,   748,
     750,   754,   756,   758,   759,   760,   763,   764,   766,   767,
     768,   769,   770,   771,   721,   636,   772,   773,   774,   775,
     776,   777,   778,   779,   780,   781,   782,   783,   784,   785,
     786,   787,   788,   789,   790,   791,   792,  -724,  -724,   864,
     814,   793,   872,   914,   901,   904,   905,   799,  -724,   907,
     908,   803,  -724,  -724,   909,   912,   804,   925,   808,  -724,
     809,   810,  -724,  -724,   913,   918,   827,  -724,  -724,   919,
     834,   829,   920,   921,   923,   836,   830,   926,   927,   835,
    -724,  -724,   928,   929,   930,   837,  -724,   838,   839,   840,
     841,   842,   843,   844,   845,   846,  -724,   847,   848,   849,
     850,   207,   851,   852,   853,   854,   855,   856,   857,   858,
     859,   860,   861,   862,   863,   865,   866,  -724,  -724,   931,
     867,   868,  -724,   869,  -724,   149,  -724,   932,   933,   935,
     936,   871,  -724,   873,  -724,  -724,   937,   874,   938,   875,
    -724,  -724,  -724,  -724,  -724,   448,   448,   448,   448,   448,
     448,   448,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,   876,   878,   879,   -14,   880,   881,
     882,   883,   884,   885,   886,   887,   888,   889,   890,   387,
     891,   892,  -724,   893,   894,   895,   896,   897,   898,   899,
       7,   900,   902,   903,   906,   910,   915,   916,  -724,   917,
     922,  -724,  -724,   924,   934,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -190,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -188,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   939,   940,
     563,   941,   942,   943,   944,   945,  -724,   946,   947,  -724,
     948,   949,   -28,   950,   870,  -724,  -724,  -724,  -724,   951,
     952,  -724,   953,   954,   413,   955,   956,   957,   958,   681,
     959,   960,  -724,   961,   962,   963,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -161,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,   964,   751,  -724,  -724,   965,   966,   967,  -724,    28,
    -724,  -724,  -724,  -724,   968,   971,   972,   973,  -724,  -724,
     974,   757,   975,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -138,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   818,
     818,   818,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,   -48,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   721,
    -724,   636,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,   -43,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   -27,  -724,
     985,   925,   976,  -724,  -724,  -724,  -724,  -724,  -724,   977,
    -724,   978,   979,  -724,  -724,   980,   981,  -724,  -724,   982,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,    61,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
      85,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   207,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
     106,  -724,  -724,  1008,   -90,   986,   988,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,   115,  -724,  -724,  -724,   -14,  -724,  -724,
    -724,  -724,     7,  -724,  -724,  -724,   563,  -724,   -28,  -724,
    -724,  -724,  1005,  1004,  1009,  1006,  1010,  1012,  -724,   413,
    -724,   681,  -724,  -724,   751,   990,   991,   992,   247,  -724,
    -724,   757,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,   135,  -724,  -724,  -724,
     247,  -724
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   247,   412,   460,     0,
     475,     0,   315,   451,   291,     0,   113,   165,   349,     0,
       0,   390,     0,   122,     0,   366,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     108,   107,   644,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   632,   643,   634,   635,   636,
     637,   638,   639,   640,   633,   641,   642,     0,     0,     0,
     473,     0,     0,   471,   472,     0,   533,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   603,   577,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   486,   487,   488,   531,   495,   532,
     526,   527,   528,   529,   525,   499,   489,   490,   491,   492,
     493,   494,   496,   497,   498,   500,   501,   530,   505,   506,
     507,   508,   504,   503,   509,   516,   517,   510,   511,   512,
     502,   514,   523,   524,   521,   522,   515,   513,   519,   520,
     518,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,     0,     0,     0,   668,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   658,   659,   660,   661,   662,
     663,   664,   666,   665,   667,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    69,    66,
      64,    70,    71,    65,    72,    73,    74,    55,    68,    58,
      59,    60,    56,    67,    61,    62,    63,    57,     0,     0,
       0,     0,   137,   138,   139,     0,     0,   364,     0,     0,
     362,   363,     0,   109,     0,     0,     0,     0,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   631,     0,     0,     0,     0,   285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,   251,   254,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   252,   253,   255,   265,   266,   267,     0,
       0,     0,     0,     0,     0,     0,   440,     0,     0,     0,
       0,     0,     0,     0,     0,   415,   416,   417,   418,   419,
     420,   421,   423,   422,   425,   429,   426,   427,   428,   424,
     466,     0,     0,     0,   463,   464,   465,     0,     0,   470,
     481,     0,     0,     0,   478,   479,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   485,     0,     0,     0,   332,     0,
       0,     0,     0,     0,     0,   318,   319,   320,   321,   326,
     322,   323,   324,   325,   457,     0,     0,     0,   454,   455,
     456,     0,     0,     0,   293,     0,   303,     0,   301,   302,
     304,   305,    49,     0,     0,     0,    45,     0,     0,     0,
       0,   116,   117,   118,     0,     0,     0,   214,     0,     0,
       0,     0,   188,     0,     0,     0,   168,   169,   170,   171,
     172,   175,   176,   177,   174,   173,   178,     0,     0,     0,
       0,     0,   352,   353,   354,   355,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   657,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,   398,     0,   393,   394,   395,   140,     0,     0,
     136,     0,     0,     0,     0,     0,     0,     0,   125,   126,
     128,   127,   129,     0,     0,   361,     0,     0,   376,     0,
       0,   369,   370,   371,   372,     0,     0,     0,   103,     0,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   249,   430,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   414,     0,
       0,     0,   462,     0,   469,     0,     0,     0,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,   327,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   317,     0,
       0,     0,   453,   306,     0,     0,     0,     0,     0,   300,
       0,     0,    44,   119,     0,     0,     0,   115,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   356,     0,     0,     0,     0,   351,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   656,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,   396,     0,
       0,     0,   392,     0,   135,     0,   130,     0,     0,     0,
       0,     0,   124,     0,   360,   373,     0,     0,     0,     0,
     368,   112,   111,   110,   654,    28,    28,    28,    28,    28,
      28,    28,    30,    29,   655,   645,   646,   647,   648,   649,
     650,   651,   653,   652,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   413,     0,
       0,   461,   474,     0,     0,   476,   547,   551,   534,   535,
     566,   538,   629,   574,   539,   540,   571,   546,   545,   554,
     544,   541,   542,   550,   549,   548,   572,   536,   627,   628,
     570,   613,   607,   623,   608,   609,   610,   618,   626,   611,
     620,   624,   614,   625,   615,   619,   612,   622,   617,   616,
     621,     0,   606,   586,   587,   588,   581,   599,   582,   583,
     584,   594,   602,   585,   596,   600,   590,   601,   591,   595,
     589,   598,   593,   592,   597,     0,   580,   567,   565,   568,
     573,   569,   556,   563,   564,   561,   562,   557,   558,   559,
     560,   575,   576,   543,   553,   552,   555,   537,     0,     0,
       0,     0,     0,     0,     0,     0,   316,     0,     0,   452,
       0,     0,     0,   311,   307,   310,   292,    50,    51,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,     0,     0,     0,   350,   672,   669,   670,
     671,   676,   675,   677,   673,   674,    99,    94,   102,    93,
      89,    87,    88,    86,     0,    85,    90,    91,   100,   101,
      92,    96,    95,    77,    76,    81,    78,    80,    79,    97,
      98,     0,     0,   391,   141,     0,     0,     0,   153,     0,
     145,   146,   148,   147,     0,     0,     0,     0,   123,   365,
       0,     0,     0,   367,    31,    32,    33,    34,    35,    36,
      37,   280,   281,   272,   290,   289,     0,   288,   273,   275,
     277,   284,   276,   274,   283,   269,   282,   271,   270,    38,
      38,    38,    40,    39,   278,   279,   435,   438,   439,   449,
     446,   432,   447,   444,   445,     0,   443,   448,   431,   437,
     434,   436,   450,   433,   467,   468,   482,   483,   604,     0,
     578,     0,   330,   331,   341,   337,   338,   340,   345,   342,
     343,   336,   344,   339,     0,   335,   329,   348,   347,   346,
     328,   459,   458,   314,   313,   298,   299,   297,     0,   296,
       0,     0,     0,   120,   121,   187,   184,   234,   246,   221,
     230,     0,   219,   224,   240,     0,   233,   238,   244,   223,
     226,   235,   237,   241,   231,   239,   227,   245,   229,   236,
     225,   228,     0,   217,   180,   182,   185,   186,   197,   198,
     199,   192,   210,   193,   194,   195,   205,   213,   196,   207,
     211,   201,   212,   202,   206,   200,   209,   204,   203,   208,
       0,   191,   181,   183,   359,   357,   358,    83,     0,   397,
     402,   408,   411,   404,   410,   405,   409,   407,   403,   406,
       0,   401,   149,     0,     0,     0,     0,   144,   132,   131,
     133,   134,   374,   380,   386,   389,   382,   388,   383,   387,
     385,   381,   384,     0,   379,   375,   286,     0,    41,    42,
      43,   441,     0,   605,   579,   333,     0,   294,     0,   312,
     309,   308,     0,     0,     0,     0,     0,     0,   215,     0,
     189,     0,    84,   399,     0,     0,     0,     0,     0,   143,
     377,     0,   287,   442,   334,   295,   220,   243,   218,   242,
     232,   222,   216,   190,   400,   150,   152,   151,   163,   162,
     158,   160,   164,   161,   157,   159,     0,   156,   378,   154,
       0,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -724,  -724,  -724,  -257,  -308,  -723,  -638,  -724,  -724,   984,
    -724,  -724,  -724,  -724,   805,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -175,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    1025,  -724,  -724,  -724,  -724,  -724,  -724,   569,  -724,  -724,
    -724,  -724,  -724,   560,  -724,  -724,  -724,  -724,  -724,  -724,
     877,  -724,  -724,  -724,  -724,    48,  -724,  -724,  -724,  -724,
    -724,  -181,  -724,  -724,  -724,   643,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -143,  -724,  -724,
    -724,  -135,  -724,  -724,  -724,   969,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -114,  -724,  -724,  -724,  -724,
    -724,  -123,  -724,   673,  -724,  -724,  -724,    -5,  -724,  -724,
    -724,  -724,  -724,   702,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -115,  -724,  -724,  -724,  -724,  -724,  -724,   631,  -724,
    -724,  -724,  -724,  -724,   970,  -724,  -724,  -724,  -724,   570,
    -724,  -724,  -724,  -724,  -724,  -137,  -724,  -724,  -724,   590,
    -724,  -724,  -724,  -724,  -122,  -724,  -724,  -724,   797,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -107,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   690,
    -724,  -724,  -724,  -724,  -724,   983,  -724,  -724,  -724,  -724,
    1073,  -724,  -724,  -724,  -724,   987,  -724,  -724,  -724,  -724,
    1039,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,    82,  -724,  -724,  -724,    83,
    -724,  -724,  -724,  -724,  -724,  1120,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   994,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   832,   833,  1102,  1103,    27,   217,   218,
     219,   220,    28,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   552,  1034,  1035,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,    29,    77,
      78,    79,    80,    81,    30,    63,   500,   501,   502,   503,
      31,    70,   587,   588,   589,   590,   591,   592,    32,   291,
     292,   293,   294,   295,  1059,  1060,  1061,  1062,  1063,  1245,
    1326,  1327,    33,    64,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   756,  1220,  1221,   526,   751,
    1192,  1193,    34,    53,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   626,  1086,  1087,    35,    61,   486,   736,
    1158,  1159,   487,   488,   489,  1162,   994,   995,   490,   491,
      36,    59,   464,   465,   466,   467,   468,   469,   470,   721,
    1144,  1145,   471,   472,   473,    37,    65,   531,   532,   533,
     534,   535,    38,   299,   300,   301,    39,    72,   600,   601,
     602,   603,   604,   817,  1263,  1264,    40,    68,   573,   574,
     575,   576,   800,  1240,  1241,    41,    54,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   649,  1115,
    1116,   385,   386,   387,   388,   389,    42,    60,   477,   478,
     479,   480,    43,    55,   393,   394,   395,   396,    44,   112,
     113,   114,    45,    57,   403,   404,   405,   406,    46,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   433,   955,   956,   207,   432,   931,   932,
     208,   209,   210,    47,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    48,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     860,   861,   611,   474,   527,   614,   615,    82,   617,   618,
     289,    73,   214,    51,   596,  1113,   110,   390,   582,   400,
    1155,    52,   497,   497,   859,   596,   297,    49,    50,  1055,
     481,   474,    83,    84,    56,   214,    58,   702,  1084,    85,
      74,   703,   704,   110,   528,  1128,   705,  1130,    75,  1129,
     400,  1131,   359,   116,   360,    62,   361,   570,   117,   118,
     289,   119,   120,   570,   864,   865,   121,    86,    87,    88,
     297,   362,    66,    67,  1227,    69,   122,   123,  1228,   111,
     391,    89,    90,    91,   124,   482,   529,   125,   126,   127,
     363,    92,    93,   483,   128,   484,    71,  1266,   390,   303,
     670,  1267,   672,   673,   498,   498,   111,   364,   107,   365,
     108,   129,   130,   683,   215,  1085,    76,   366,   688,   597,
    1296,   504,   131,   583,   401,   132,   133,   697,   698,   367,
     597,   298,   475,   530,  1056,   216,   134,   215,   109,   711,
     505,   713,   714,   135,   115,   136,   392,   137,   402,   138,
    1055,   224,   139,   140,   245,   401,   485,   368,   216,   506,
     475,   391,   571,   211,   141,   212,   213,  1156,   571,   142,
     143,   455,   144,   145,   146,   298,  1157,   147,   369,   402,
     221,   246,   222,   247,   225,   223,   507,  1271,  -142,   584,
     456,  1272,  1275,   226,   227,   228,  1276,   370,   229,   230,
     499,   499,   148,   231,   232,   233,   371,   585,  1277,   457,
     248,  1114,  1278,   149,   150,   151,   152,   153,   154,   155,
     249,   288,   296,   586,  1030,   302,   508,   392,  1057,   476,
     769,   304,   250,   251,   252,   290,   458,   598,  -142,   765,
     599,   582,   320,   509,   581,   253,   307,   495,   598,   254,
     322,   599,  1058,   811,   667,  1056,   372,   476,   746,   255,
     819,   594,   256,   257,  1246,   738,   731,   323,   324,   156,
     157,   158,   325,   159,   160,   510,   511,   305,   398,   373,
     572,   306,   161,   309,   162,   290,   572,   657,   453,   492,
     527,   258,   801,   459,   612,   579,  1288,   805,   481,   547,
    1289,   460,   461,    73,   504,  1031,   310,   259,   311,  1032,
     260,   261,   262,   312,   313,   326,  1318,   846,  1319,   314,
    1290,   462,   851,   505,  1291,   854,   315,   512,   316,   858,
     528,   317,    74,   661,   318,   327,   328,   329,   330,   331,
      75,  1293,   506,   332,   577,  1294,   583,   513,   333,  1057,
    1300,   514,   319,   482,  1301,   334,   759,   397,   263,   407,
     408,   483,   409,   484,   335,   336,  1320,  1033,   410,   507,
    1329,   411,   529,  1058,  1330,   337,  1268,  1269,  1270,   116,
     412,   264,   265,  1321,   117,   118,   545,   119,   120,   568,
     413,   605,   121,   414,   415,   416,   338,   463,  1099,  1100,
    1101,   417,   122,   123,   418,   419,   727,   420,    76,   508,
     124,   421,   584,   125,   126,   127,   422,  1167,   423,   530,
     128,   424,  1322,  1323,   485,   425,   509,   245,   426,   427,
     585,   428,   429,   430,  1168,  1169,   431,   129,   130,   434,
     435,   339,   436,   437,  1170,   606,   586,   438,   131,   439,
     440,   132,   133,   441,   246,   442,   247,   443,   510,   511,
     444,   445,   134,   446,   447,   448,   449,   450,   451,   135,
     452,   136,   493,   137,  1324,   138,   494,   536,   139,   140,
    1325,  1171,  1172,   248,  1173,   640,   537,   607,   538,   539,
     141,   540,   541,   249,   542,   142,   143,   543,   144,   145,
     146,   859,   544,   147,   548,   250,   251,   252,   549,   550,
     512,   551,   455,   553,   554,   555,  1174,   556,   253,   557,
     558,   559,   254,   560,  1175,   561,   610,   608,   148,   562,
     513,   456,   255,   563,   514,   256,   257,   564,   565,   149,
     150,   151,   152,   153,   154,   155,  1176,   566,  1177,  1178,
     457,   825,   826,   827,   828,   829,   830,   831,   567,   578,
     593,   609,   610,   359,   258,   360,  1179,   361,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,   613,   616,   458,  1134,   619,
     259,   620,   362,   260,   261,   262,   621,   622,   623,  1180,
     671,   624,   625,   627,  1181,   156,   157,   158,  1182,   159,
     160,   363,  1183,  1135,   628,   629,  1297,  1184,   161,   630,
     162,  1185,   631,   632,   633,   634,   663,   635,   364,   636,
     365,   637,  1186,   638,  1187,  1188,   639,  1189,   366,   642,
     643,   263,   664,   644,   459,  1136,   645,   646,  1190,   647,
     367,   648,   460,   461,     2,     3,  1191,   650,     4,   651,
     224,   669,   652,   653,   264,   265,   654,   322,   655,   656,
       5,   659,   462,   660,     6,   665,     7,   666,   368,   674,
    1137,  1138,   675,     8,   323,   324,  1139,   694,   677,   325,
     676,   678,   679,   225,   933,     9,   934,   935,   680,   369,
      10,    11,   226,   227,   228,   681,   682,   229,   230,   684,
    1140,   685,   231,   232,   233,   686,   687,   689,   370,    12,
     690,   691,   692,    13,   693,  1141,   695,   371,   696,   699,
     700,   701,   326,   706,   707,   708,    14,   710,   709,  1198,
     712,  1199,  1200,   715,   716,   717,   718,   719,   463,   740,
     741,   733,   327,   328,   329,   330,   331,   770,    15,    16,
     332,   720,   767,   722,   723,   333,   724,   725,   726,   729,
     730,   734,   334,    17,   735,   737,   742,   372,   743,   911,
     744,   335,   336,   745,   748,   749,   750,   761,  1142,   752,
      18,   753,   337,   754,   755,   757,   758,   762,   763,   764,
     373,   768,    19,    20,   771,   772,   773,  1143,   774,   775,
     776,   777,   778,   338,   779,   936,   937,   938,   780,   781,
     939,   940,   782,   941,   942,   784,   943,    21,   944,   783,
     785,   945,  1230,   946,   947,   786,   787,   788,  1253,   948,
      22,   789,   790,   949,   797,    23,   791,   950,   951,   952,
      24,   792,   793,    25,   953,   794,   795,   796,   339,   954,
    1201,  1202,  1203,   798,   799,  1204,  1205,   803,  1206,  1207,
     804,  1208,   806,  1209,   807,   813,  1210,   808,  1211,  1212,
     809,   810,   814,   815,  1213,   821,   844,   816,  1214,   845,
     818,   822,  1215,  1216,  1217,   823,   824,  1231,   834,  1218,
     912,   913,   914,  1254,  1219,   915,   916,   835,   917,   918,
     836,   919,   847,   920,   837,   838,   921,   839,   922,   923,
     840,   841,    82,   842,   924,   848,   849,   843,   925,  1232,
     850,   852,   926,   927,   928,  1255,   853,  1233,   855,   929,
     856,   857,   859,  1256,   930,   862,  1234,    83,    84,   863,
     867,   866,  1257,   868,    85,   870,   873,   869,   871,   872,
     874,   875,   876,   877,   879,   878,   880,   881,   882,   883,
    1235,   884,  1236,  1237,   885,   886,  1258,   887,  1259,  1260,
     888,   889,    86,    87,    88,   890,  1238,   891,   892,   893,
     894,   895,  1261,   896,  1239,   897,    89,    90,    91,   898,
    1262,   899,   978,   900,   901,   902,    92,    93,   903,   904,
     981,   905,   906,   907,   908,   909,   910,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   967,   968,   969,
     970,   971,   972,   973,   974,   975,   976,   977,   982,   983,
     979,   980,   984,   985,   986,   987,   988,   990,   989,   993,
     991,   999,   992,   996,   997,   998,  1000,  1002,  1005,  1006,
    1003,  1007,  1008,  1292,  1010,  1011,  1013,  1014,  1015,  1051,
    1064,  1065,  1001,  1066,  1067,  1070,  1072,  1004,  1009,   747,
    1012,   569,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1036,  1037,  1038,  1039,
    1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,  1279,
    1049,  1050,   308,  1053,  1054,  1052,  1068,  1247,  1069,  1161,
    1073,  1081,  1071,  1082,  1083,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,  1097,  1098,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1117,  1295,  1118,  1119,  1306,
    1307,  1120,  1309,  1308,  1310,  1121,  1311,   812,  1313,  1331,
    1122,  1123,  1124,  1302,  1312,  1305,  1280,  1125,   760,  1126,
     739,  1304,   766,   802,  1328,  1303,   728,   732,   580,  1127,
     820,   658,  1314,  1160,  1132,  1133,  1146,  1147,  1148,  1149,
    1150,  1151,  1152,  1153,  1154,   399,  1163,  1164,  1165,  1166,
    1194,  1195,  1196,  1197,  1222,  1223,  1224,  1225,  1226,  1229,
    1242,   496,   454,  1248,  1243,  1244,  1249,  1250,  1251,  1252,
    1265,  1281,  1273,  1274,   321,     0,     0,  1282,  1283,  1284,
    1285,  1286,  1287,  1299,  1298,  1315,  1316,  1317,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   641,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   662,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     668
};

static const yytype_int16 yycheck[] =
{
     638,   639,   310,     1,     1,   313,   314,     1,   316,   317,
       1,     1,     1,   237,     1,     8,     1,     1,     1,     1,
      48,   237,     1,     1,   114,     1,     1,   235,   236,     1,
       1,     1,    26,    27,   237,     1,   237,   216,    52,    33,
      30,   220,   216,     1,    41,   235,   220,   235,    38,   239,
       1,   239,     1,     1,     3,   237,     5,     1,     6,     7,
       1,     9,    10,     1,   183,   184,    14,    61,    62,    63,
       1,    20,   237,   237,   235,   237,    24,    25,   239,    64,
      64,    75,    76,    77,    32,    56,    83,    35,    36,    37,
      39,    85,    86,    64,    42,    66,   237,   235,     1,   235,
     408,   239,   410,   411,    83,    83,    64,    56,   237,    58,
     237,    59,    60,   421,   103,   129,   106,    66,   426,   106,
     210,     1,    70,   106,   106,    73,    74,   435,   436,    78,
     106,   106,   130,   130,   106,   124,    84,   103,   237,   447,
      20,   449,   450,    91,   237,    93,   130,    95,   130,    97,
       1,     1,   100,   101,     1,   106,   127,   106,   124,    39,
     130,    64,   106,   237,   112,   237,   237,   195,   106,   117,
     118,     1,   120,   121,   122,   106,   204,   125,   127,   130,
     237,    28,   237,    30,    34,   237,    66,   235,   179,   172,
      20,   239,   235,    43,    44,    45,   239,   146,    48,    49,
     179,   179,   150,    53,    54,    55,   155,   190,   235,    39,
      57,   204,   239,   161,   162,   163,   164,   165,   166,   167,
      67,   237,   237,   206,    17,   237,   106,   130,   200,   227,
     538,   238,    79,    80,    81,   226,    66,   224,   179,   236,
     227,     1,   236,   123,   179,    92,   236,   236,   224,    96,
       1,   227,   224,   236,   236,   106,   205,   227,   236,   106,
     236,   236,   109,   110,   236,   236,   236,    18,    19,   217,
     218,   219,    23,   221,   222,   155,   156,   238,   236,   228,
     224,   238,   230,   238,   232,   226,   224,   236,   236,   235,
       1,   138,   236,   123,   216,   236,   235,   237,     1,   235,
     239,   131,   132,     1,     1,    98,   238,   154,   238,   102,
     157,   158,   159,   238,   238,    66,    69,   625,    71,   238,
     235,   151,   630,    20,   239,   633,   238,   207,   238,   637,
      41,   238,    30,   236,   238,    86,    87,    88,    89,    90,
      38,   235,    39,    94,   235,   239,   106,   227,    99,   200,
     235,   231,   238,    56,   239,   106,   236,   238,   205,   238,
     238,    64,   238,    66,   115,   116,   119,   160,   238,    66,
     235,   238,    83,   224,   239,   126,  1099,  1100,  1101,     1,
     238,   228,   229,   136,     6,     7,   236,     9,    10,   236,
     238,   128,    14,   238,   238,   238,   147,   227,    11,    12,
      13,   238,    24,    25,   238,   238,   236,   238,   106,   106,
      32,   238,   172,    35,    36,    37,   238,     4,   238,   130,
      42,   238,   175,   176,   127,   238,   123,     1,   238,   238,
     190,   238,   238,   238,    21,    22,   238,    59,    60,   238,
     238,   192,   238,   238,    31,   128,   206,   238,    70,   238,
     238,    73,    74,   238,    28,   238,    30,   238,   155,   156,
     238,   238,    84,   238,   238,   238,   238,   238,   238,    91,
     238,    93,   238,    95,   227,    97,   238,   238,   100,   101,
     233,    68,    69,    57,    71,   236,   238,   128,   238,   238,
     112,   238,   238,    67,   238,   117,   118,   238,   120,   121,
     122,   114,   238,   125,   238,    79,    80,    81,   238,   238,
     207,   238,     1,   238,   238,   238,   103,   238,    92,   238,
     238,   238,    96,   238,   111,   238,   114,   235,   150,   238,
     227,    20,   106,   238,   231,   109,   110,   238,   238,   161,
     162,   163,   164,   165,   166,   167,   133,   238,   135,   136,
      39,   139,   140,   141,   142,   143,   144,   145,   238,   238,
     238,   114,   114,     1,   138,     3,   153,     5,   825,   826,
     827,   828,   829,   830,   831,   114,   114,    66,    15,   114,
     154,   114,    20,   157,   158,   159,   235,   235,   238,   176,
     114,   238,   238,   238,   181,   217,   218,   219,   185,   221,
     222,    39,   189,    40,   238,   238,  1244,   194,   230,   238,
     232,   198,   238,   238,   238,   238,   128,   238,    56,   238,
      58,   238,   209,   238,   211,   212,   238,   214,    66,   235,
     238,   205,   235,   238,   123,    72,   238,   238,   225,   238,
      78,   238,   131,   132,     0,     1,   233,   238,     4,   238,
       1,   216,   238,   238,   228,   229,   238,     1,   238,   238,
      16,   238,   151,   238,    20,   238,    22,   238,   106,   216,
     107,   108,   114,    29,    18,    19,   113,   238,   114,    23,
     216,   114,   114,    34,    48,    41,    50,    51,   216,   127,
      46,    47,    43,    44,    45,   216,   216,    48,    49,   114,
     137,   114,    53,    54,    55,   114,   114,   114,   146,    65,
     114,   114,   114,    69,   216,   152,   238,   155,   216,   216,
     216,   216,    66,   216,   216,   216,    82,   114,   216,    48,
     216,    50,    51,   216,   114,   235,   235,   238,   227,   128,
     128,   235,    86,    87,    88,    89,    90,   128,   104,   105,
      94,   238,   216,   238,   238,    99,   238,   238,   238,   238,
     238,   238,   106,   119,   238,   238,   235,   205,   235,    48,
     238,   115,   116,   238,   235,   238,   238,   235,   215,   238,
     136,   238,   126,   238,   238,   238,   238,   238,   238,   238,
     228,   216,   148,   149,   216,   128,   216,   234,   216,   216,
     235,   114,   128,   147,   216,   169,   170,   171,   128,   238,
     174,   175,   128,   177,   178,   114,   180,   173,   182,   128,
     114,   185,    71,   187,   188,   128,   128,   128,    71,   193,
     186,   128,   128,   197,   235,   191,   128,   201,   202,   203,
     196,   128,   128,   199,   208,   128,   128,   128,   192,   213,
     169,   170,   171,   235,   238,   174,   175,   216,   177,   178,
     235,   180,   235,   182,   238,   128,   185,   238,   187,   188,
     238,   238,   235,   235,   193,   235,   114,   238,   197,   114,
     238,   235,   201,   202,   203,   235,   235,   136,   235,   208,
     169,   170,   171,   136,   213,   174,   175,   235,   177,   178,
     235,   180,   238,   182,   235,   235,   185,   235,   187,   188,
     235,   235,     1,   235,   193,   114,   114,   235,   197,   168,
     114,   114,   201,   202,   203,   168,   114,   176,   128,   208,
     114,   114,   114,   176,   213,   235,   185,    26,    27,   128,
     216,   128,   185,   128,    33,   238,   114,   128,   128,   128,
     128,   128,   128,   128,   128,   235,   128,   235,   235,   128,
     209,   128,   211,   212,   235,   235,   209,   235,   211,   212,
     235,   235,    61,    62,    63,   235,   225,   235,   235,   235,
     235,   235,   225,   235,   233,   235,    75,    76,    77,   235,
     233,   235,   128,   235,   235,   235,    85,    86,   235,   235,
     128,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   114,   128,
     216,   238,   128,   128,   235,   128,   128,   128,   235,   114,
     128,   128,   238,   235,   235,   235,   128,   128,   128,   128,
     216,   128,   216,  1228,   128,   128,   128,   128,   128,   128,
     128,   128,   235,   128,   128,   128,   128,   238,   238,   500,
     235,   266,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   114,
     235,   235,    77,   235,   235,   238,   235,  1059,   235,   239,
     235,   235,   238,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   128,   235,   235,   134,
     136,   235,   136,   134,   134,   235,   134,   587,  1291,  1330,
     235,   235,   235,  1267,  1289,  1278,  1161,   235,   515,   235,
     487,  1276,   531,   573,  1301,  1272,   464,   477,   291,   235,
     600,   374,  1294,   223,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   112,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   217,   163,   235,   238,   238,   235,   235,   235,   235,
     235,   235,  1129,  1131,    94,    -1,    -1,   240,   240,   240,
     240,   240,   240,   235,   238,   235,   235,   235,   234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   340,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   393,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     403
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   242,     0,     1,     4,    16,    20,    22,    29,    41,
      46,    47,    65,    69,    82,   104,   105,   119,   136,   148,
     149,   173,   186,   191,   196,   199,   243,   248,   253,   279,
     285,   291,   299,   313,   333,   357,   371,   386,   393,   397,
     407,   416,   437,   443,   449,   453,   459,   514,   528,   235,
     236,   237,   237,   334,   417,   444,   237,   454,   237,   372,
     438,   358,   237,   286,   314,   387,   237,   237,   408,   237,
     292,   237,   398,     1,    30,    38,   106,   280,   281,   282,
     283,   284,     1,    26,    27,    33,    61,    62,    63,    75,
      76,    77,    85,    86,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   237,   237,   237,
       1,    64,   450,   451,   452,   237,     1,     6,     7,     9,
      10,    14,    24,    25,    32,    35,    36,    37,    42,    59,
      60,    70,    73,    74,    84,    91,    93,    95,    97,   100,
     101,   112,   117,   118,   120,   121,   122,   125,   150,   161,
     162,   163,   164,   165,   166,   167,   217,   218,   219,   221,
     222,   230,   232,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   507,   511,   512,
     513,   237,   237,   237,     1,   103,   124,   249,   250,   251,
     252,   237,   237,   237,     1,    34,    43,    44,    45,    48,
      49,    53,    54,    55,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,     1,    28,    30,    57,    67,
      79,    80,    81,    92,    96,   106,   109,   110,   138,   154,
     157,   158,   159,   205,   228,   229,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   237,     1,
     226,   300,   301,   302,   303,   304,   237,     1,   106,   394,
     395,   396,   237,   235,   238,   238,   238,   236,   281,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     236,   516,     1,    18,    19,    23,    66,    86,    87,    88,
      89,    90,    94,    99,   106,   115,   116,   126,   147,   192,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,     1,
       3,     5,    20,    39,    56,    58,    66,    78,   106,   127,
     146,   155,   205,   228,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   432,   433,   434,   435,   436,
       1,    64,   130,   445,   446,   447,   448,   238,   236,   451,
       1,   106,   130,   455,   456,   457,   458,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   508,   504,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   236,   461,     1,    20,    39,    66,   123,
     131,   132,   151,   227,   373,   374,   375,   376,   377,   378,
     379,   383,   384,   385,     1,   130,   227,   439,   440,   441,
     442,     1,    56,    64,    66,   127,   359,   363,   364,   365,
     369,   370,   235,   238,   238,   236,   250,     1,    83,   179,
     287,   288,   289,   290,     1,    20,    39,    66,   106,   123,
     155,   156,   207,   227,   231,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   329,     1,    41,    83,
     130,   388,   389,   390,   391,   392,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   236,   530,   235,   238,   238,
     238,   238,   263,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   236,   255,
       1,   106,   224,   409,   410,   411,   412,   235,   238,   236,
     301,   179,     1,   106,   172,   190,   206,   293,   294,   295,
     296,   297,   298,   238,   236,   395,     1,   106,   224,   227,
     399,   400,   401,   402,   403,   128,   128,   128,   235,   114,
     114,   245,   216,   114,   245,   245,   114,   245,   245,   114,
     114,   235,   235,   238,   238,   238,   354,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     236,   336,   235,   238,   238,   238,   238,   238,   238,   429,
     238,   238,   238,   238,   238,   238,   238,   236,   419,   238,
     238,   236,   446,   128,   235,   238,   238,   236,   456,   216,
     245,   114,   245,   245,   216,   114,   216,   114,   114,   114,
     216,   216,   216,   245,   114,   114,   114,   114,   245,   114,
     114,   114,   114,   216,   238,   238,   216,   245,   245,   216,
     216,   216,   216,   220,   216,   220,   216,   216,   216,   216,
     114,   245,   216,   245,   245,   216,   114,   235,   235,   238,
     238,   380,   238,   238,   238,   238,   238,   236,   374,   238,
     238,   236,   440,   235,   238,   238,   360,   238,   236,   364,
     128,   128,   235,   235,   238,   238,   236,   288,   235,   238,
     238,   330,   238,   238,   238,   238,   326,   238,   238,   236,
     316,   235,   238,   238,   238,   236,   389,   216,   216,   245,
     128,   216,   128,   216,   216,   216,   235,   114,   128,   216,
     128,   238,   128,   128,   114,   114,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   235,   235,   238,
     413,   236,   410,   216,   235,   237,   235,   238,   238,   238,
     238,   236,   294,   128,   235,   235,   238,   404,   238,   236,
     400,   235,   235,   235,   235,   139,   140,   141,   142,   143,
     144,   145,   244,   245,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   114,   114,   245,   238,   114,   114,
     114,   245,   114,   114,   245,   128,   114,   114,   245,   114,
     247,   247,   235,   128,   183,   184,   128,   216,   128,   128,
     238,   128,   128,   114,   128,   128,   128,   128,   235,   128,
     128,   235,   235,   128,   128,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,    48,   169,   170,   171,   174,   175,   177,   178,   180,
     182,   185,   187,   188,   193,   197,   201,   202,   203,   208,
     213,   509,   510,    48,    50,    51,   169,   170,   171,   174,
     175,   177,   178,   180,   182,   185,   187,   188,   193,   197,
     201,   202,   203,   208,   213,   505,   506,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   128,   216,
     238,   128,   114,   128,   128,   128,   235,   128,   128,   235,
     128,   128,   238,   114,   367,   368,   235,   235,   235,   128,
     128,   235,   128,   216,   238,   128,   128,   128,   216,   238,
     128,   128,   235,   128,   128,   128,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
      17,    98,   102,   160,   264,   265,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   128,   238,   235,   235,     1,   106,   200,   224,   305,
     306,   307,   308,   309,   128,   128,   128,   128,   235,   235,
     128,   238,   128,   235,   244,   244,   244,   244,   244,   244,
     244,   235,   235,   235,    52,   129,   355,   356,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,    11,
      12,    13,   246,   247,   235,   235,   235,   235,   235,   235,
     235,   235,   235,     8,   204,   430,   431,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   239,
     235,   239,   235,   235,    15,    40,    72,   107,   108,   113,
     137,   152,   215,   234,   381,   382,   235,   235,   235,   235,
     235,   235,   235,   235,   235,    48,   195,   204,   361,   362,
     223,   239,   366,   235,   235,   235,   235,     4,    21,    22,
      31,    68,    69,    71,   103,   111,   133,   135,   136,   153,
     176,   181,   185,   189,   194,   198,   209,   211,   212,   214,
     225,   233,   331,   332,   235,   235,   235,   235,    48,    50,
      51,   169,   170,   171,   174,   175,   177,   178,   180,   182,
     185,   187,   188,   193,   197,   201,   202,   203,   208,   213,
     327,   328,   235,   235,   235,   235,   235,   235,   239,   235,
      71,   136,   168,   176,   185,   209,   211,   212,   225,   233,
     414,   415,   235,   238,   238,   310,   236,   306,   235,   235,
     235,   235,   235,    71,   136,   168,   176,   185,   209,   211,
     212,   225,   233,   405,   406,   235,   235,   239,   246,   246,
     246,   235,   239,   510,   506,   235,   239,   235,   239,   114,
     368,   235,   240,   240,   240,   240,   240,   240,   235,   239,
     235,   239,   265,   235,   239,   128,   210,   247,   238,   235,
     235,   239,   356,   431,   382,   362,   134,   136,   134,   136,
     134,   134,   332,   328,   415,   235,   235,   235,    69,    71,
     119,   136,   175,   176,   227,   233,   311,   312,   406,   235,
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
     336,   336,   336,   336,   336,   336,   336,   336,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   354,   353,   355,   355,   356,
     356,   358,   357,   360,   359,   361,   361,   362,   362,   362,
     363,   363,   364,   364,   364,   364,   364,   366,   365,   367,
     367,   368,   368,   369,   370,   372,   371,   373,   373,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   375,   376,
     377,   378,   380,   379,   381,   381,   382,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   383,   384,   385,   387,
     386,   388,   388,   389,   389,   389,   389,   390,   391,   392,
     393,   394,   394,   395,   395,   396,   398,   397,   399,   399,
     400,   400,   400,   400,   401,   402,   404,   403,   405,   405,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     408,   407,   409,   409,   410,   410,   410,   411,   413,   412,
     414,   414,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   417,   416,   418,   418,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   427,
     429,   428,   430,   430,   431,   431,   432,   433,   434,   435,
     436,   438,   437,   439,   439,   440,   440,   440,   441,   442,
     444,   443,   445,   445,   446,   446,   446,   447,   448,   449,
     450,   450,   451,   451,   452,   454,   453,   455,   455,   456,
     456,   456,   457,   458,   459,   460,   460,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   489,   490,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   504,   503,   505,
     505,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   508,   507,   509,   509,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   511,   512,   513,
     514,   515,   515,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   516,   517,   518,   519,   520,   521,
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     0,     6,     0,     5,     3,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     0,     5,     3,
       1,     1,     3,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       5,     2,     1,     1,     1,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     2,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     4,     4,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
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
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2969 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 439 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 445 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 481 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_certificate_file);
    ConfigServerInfo.ssl_certificate_file = xstrdup(yylval.string);
  }
}
#line 3011 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 490 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 3023 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 499 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_param_file);
    ConfigServerInfo.ssl_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 508 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_cipher_list);
    ConfigServerInfo.ssl_cipher_list = xstrdup(yylval.string);
  }
}
#line 3047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 517 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_message_digest_algorithm);
    ConfigServerInfo.ssl_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3059 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 526 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_elliptic_curve);
    ConfigServerInfo.ssl_dh_elliptic_curve = xstrdup(yylval.string);
  }
}
#line 3071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 535 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options = 0;
}
#line 3080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 542 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_STANDARD;
#endif
}
#line 3091 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 548 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MEMORY_CACHE;
#endif
}
#line 3102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 554 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MMAP_CACHE;
#endif
}
#line 3113 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 560 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_CHECK_CACHE;
#endif
}
#line 3124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 568 "conf_parser.y" /* yacc.c:1646  */
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
#line 3142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 583 "conf_parser.y" /* yacc.c:1646  */
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
#line 3160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 598 "conf_parser.y" /* yacc.c:1646  */
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
#line 3178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 613 "conf_parser.y" /* yacc.c:1646  */
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
#line 3196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 628 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 638 "conf_parser.y" /* yacc.c:1646  */
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
#line 3226 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 652 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 661 "conf_parser.y" /* yacc.c:1646  */
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
#line 3269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 689 "conf_parser.y" /* yacc.c:1646  */
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
#line 3300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 717 "conf_parser.y" /* yacc.c:1646  */
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
#line 3328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 742 "conf_parser.y" /* yacc.c:1646  */
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
#line 3353 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 764 "conf_parser.y" /* yacc.c:1646  */
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
#line 3378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 786 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 804 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 813 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3411 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 822 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 839 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3449 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 856 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3458 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 862 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3467 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 872 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 876 "conf_parser.y" /* yacc.c:1646  */
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
#line 3494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 894 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 900 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 906 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 912 "conf_parser.y" /* yacc.c:1646  */
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
#line 3542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 940 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3551 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 946 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 950 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 966 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3584 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 974 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 977 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3600 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 982 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3609 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 989 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3618 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 993 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3627 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 997 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3636 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1001 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3645 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1005 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3654 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1009 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3663 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3672 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1017 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3681 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1034 "conf_parser.y" /* yacc.c:1646  */
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
#line 3750 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1101 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3759 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1113 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1125 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1136 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1142 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1153 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1159 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1166 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1170 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1174 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1178 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1182 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1186 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1190 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1194 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1198 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1202 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1206 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1210 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1214 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1218 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1222 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1226 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1230 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1234 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4003 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1238 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1242 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1246 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1250 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1267 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1271 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1275 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1279 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1283 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1291 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1295 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1299 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1303 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1307 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1311 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1315 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1319 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1323 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1327 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4201 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1331 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1335 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1339 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1343 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1347 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1351 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1355 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1359 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4273 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1363 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4282 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1367 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4291 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1371 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1375 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1385 "conf_parser.y" /* yacc.c:1646  */
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
#line 4326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1397 "conf_parser.y" /* yacc.c:1646  */
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
  class->max_ident = block_state.max_ident.value;
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
#line 4374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1461 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1467 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1473 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1479 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1485 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4419 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1491 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1497 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1503 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1509 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1515 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1521 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1528 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1534 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1540 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4501 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1546 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4513 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1555 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4525 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1564 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4534 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1571 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4543 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1575 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4552 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1585 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4561 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1591 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1597 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1601 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4587 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1605 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4596 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1613 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4602 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1618 "conf_parser.y" /* yacc.c:1646  */
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
#line 4620 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1631 "conf_parser.y" /* yacc.c:1646  */
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
#line 4640 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1648 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1654 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1664 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1668 "conf_parser.y" /* yacc.c:1646  */
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
#line 4712 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1721 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1727 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4730 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1733 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4739 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1739 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4753 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1750 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1757 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4771 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1761 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4780 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1765 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4789 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1769 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4798 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1773 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4807 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1777 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1781 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1785 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4834 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1789 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4843 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1793 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1799 "conf_parser.y" /* yacc.c:1646  */
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
#line 4869 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1813 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1822 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4905 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1842 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1853 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1865 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1880 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1896 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1907 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1922 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1928 "conf_parser.y" /* yacc.c:1646  */
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
#line 5020 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1954 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1958 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1966 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5065 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1970 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1974 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1978 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1982 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1986 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1990 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2009 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2022 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5155 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2039 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 404:
#line 2043 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2047 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2051 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2059 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5227 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2063 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2067 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2071 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2081 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5268 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2090 "conf_parser.y" /* yacc.c:1646  */
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
#line 5334 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2170 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5343 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2176 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2182 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5361 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2188 "conf_parser.y" /* yacc.c:1646  */
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
#line 5377 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2201 "conf_parser.y" /* yacc.c:1646  */
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
#line 5393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2214 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5411 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2226 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2230 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2236 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2242 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2246 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2252 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2275 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2281 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5510 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5519 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2300 "conf_parser.y" /* yacc.c:1646  */
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
#line 5544 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2325 "conf_parser.y" /* yacc.c:1646  */
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
#line 5567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2345 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2355 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2359 "conf_parser.y" /* yacc.c:1646  */
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
#line 5611 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 467:
#line 2385 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5620 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2391 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5629 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 474:
#line 2406 "conf_parser.y" /* yacc.c:1646  */
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
#line 5646 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 475:
#line 2423 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5655 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 476:
#line 2427 "conf_parser.y" /* yacc.c:1646  */
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
#line 5675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 482:
#line 2447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 483:
#line 2453 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2515 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5701 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2520 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2525 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5717 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2530 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5725 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2535 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5734 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2541 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5742 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2546 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5750 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2551 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5758 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2556 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5766 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2561 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5774 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2566 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2571 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5790 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2576 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5798 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2581 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5806 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2586 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2591 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5822 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2596 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5830 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2601 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2606 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2611 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2617 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2622 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2627 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2632 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2637 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2642 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2652 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2655 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2660 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2663 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2668 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2673 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5959 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2678 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2683 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2688 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2693 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2698 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2703 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2708 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2713 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6023 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2718 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6031 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2723 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2728 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2734 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2737 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6063 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2740 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2743 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2746 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2749 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6095 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2752 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2755 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2758 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2761 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2764 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2767 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2770 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2773 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2776 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6167 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2779 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6175 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2782 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2785 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2788 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6199 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2791 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6207 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2794 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6215 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2797 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2802 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2808 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6239 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2811 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6247 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2814 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2817 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2820 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6271 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2823 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6279 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2826 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6287 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2829 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6295 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2832 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6303 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2835 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6311 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2838 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 618:
#line 2841 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6327 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 619:
#line 2844 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6335 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 620:
#line 2847 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6343 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 621:
#line 2850 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6351 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 622:
#line 2853 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 623:
#line 2856 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2859 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2862 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2865 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2870 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2880 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 2910 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6431 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 2915 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2920 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6447 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2925 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2930 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2935 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6471 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2940 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6479 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 2945 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 2950 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6495 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 2955 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 669:
#line 2978 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 670:
#line 2984 "conf_parser.y" /* yacc.c:1646  */
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
#line 6531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 671:
#line 3000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6543 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 672:
#line 3009 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6552 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 673:
#line 3015 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6561 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 674:
#line 3021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6570 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 675:
#line 3027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 676:
#line 3036 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6591 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 677:
#line 3042 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6600 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6604 "conf_parser.c" /* yacc.c:1646  */
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
