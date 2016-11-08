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
    MAX_CHANNELS = 343,
    MAX_GLOBAL = 344,
    MAX_IDLE = 345,
    MAX_INVITES = 346,
    MAX_LOCAL = 347,
    MAX_NICK_CHANGES = 348,
    MAX_NICK_LENGTH = 349,
    MAX_NICK_TIME = 350,
    MAX_NUMBER = 351,
    MAX_TARGETS = 352,
    MAX_TOPIC_LENGTH = 353,
    MAX_WATCH = 354,
    MEMORY_CACHE = 355,
    MIN_IDLE = 356,
    MIN_NONWILDCARD = 357,
    MIN_NONWILDCARD_SIMPLE = 358,
    MMAP_CACHE = 359,
    MODULE = 360,
    MODULES = 361,
    MOTD = 362,
    NAME = 363,
    NEED_IDENT = 364,
    NEED_PASSWORD = 365,
    NETWORK_DESC = 366,
    NETWORK_NAME = 367,
    NICK = 368,
    NO_OPER_FLOOD = 369,
    NO_TILDE = 370,
    NUMBER = 371,
    NUMBER_PER_CIDR = 372,
    NUMBER_PER_IP = 373,
    OPER_ONLY_UMODES = 374,
    OPER_UMODES = 375,
    OPERATOR = 376,
    OPERS_BYPASS_CALLERID = 377,
    PACE_WAIT = 378,
    PACE_WAIT_SIMPLE = 379,
    PASSWORD = 380,
    PATH = 381,
    PING_COOKIE = 382,
    PING_TIME = 383,
    PORT = 384,
    QSTRING = 385,
    RANDOM_IDLE = 386,
    REASON = 387,
    REDIRPORT = 388,
    REDIRSERV = 389,
    REHASH = 390,
    REMOTE = 391,
    REMOTEBAN = 392,
    RESV = 393,
    RESV_EXEMPT = 394,
    RSA_PRIVATE_KEY_FILE = 395,
    SECONDS = 396,
    MINUTES = 397,
    HOURS = 398,
    DAYS = 399,
    WEEKS = 400,
    MONTHS = 401,
    YEARS = 402,
    SEND_PASSWORD = 403,
    SENDQ = 404,
    SERVERHIDE = 405,
    SERVERINFO = 406,
    SHORT_MOTD = 407,
    SPOOF = 408,
    SPOOF_NOTICE = 409,
    SQUIT = 410,
    SSL_CERTIFICATE_FILE = 411,
    SSL_CERTIFICATE_FINGERPRINT = 412,
    SSL_CONNECTION_REQUIRED = 413,
    SSL_DH_ELLIPTIC_CURVE = 414,
    SSL_DH_PARAM_FILE = 415,
    SSL_MESSAGE_DIGEST_ALGORITHM = 416,
    STANDARD = 417,
    STATS_E_DISABLED = 418,
    STATS_I_OPER_ONLY = 419,
    STATS_K_OPER_ONLY = 420,
    STATS_M_OPER_ONLY = 421,
    STATS_O_OPER_ONLY = 422,
    STATS_P_OPER_ONLY = 423,
    STATS_U_OPER_ONLY = 424,
    T_ALL = 425,
    T_BOTS = 426,
    T_CALLERID = 427,
    T_CCONN = 428,
    T_COMMAND = 429,
    T_CLUSTER = 430,
    T_DEAF = 431,
    T_DEBUG = 432,
    T_DLINE = 433,
    T_EXTERNAL = 434,
    T_FARCONNECT = 435,
    T_FILE = 436,
    T_FULL = 437,
    T_GLOBOPS = 438,
    T_INVISIBLE = 439,
    T_IPV4 = 440,
    T_IPV6 = 441,
    T_LOCOPS = 442,
    T_LOG = 443,
    T_NCHANGE = 444,
    T_NONONREG = 445,
    T_OPME = 446,
    T_PREPEND = 447,
    T_PSEUDO = 448,
    T_RECVQ = 449,
    T_REJ = 450,
    T_RESTART = 451,
    T_SERVER = 452,
    T_SERVICE = 453,
    T_SERVNOTICE = 454,
    T_SET = 455,
    T_SHARED = 456,
    T_SIZE = 457,
    T_SKILL = 458,
    T_SOFTCALLERID = 459,
    T_SPY = 460,
    T_SSL = 461,
    T_SSL_CIPHER_LIST = 462,
    T_TARGET = 463,
    T_UMODES = 464,
    T_UNAUTH = 465,
    T_UNDLINE = 466,
    T_UNLIMITED = 467,
    T_UNRESV = 468,
    T_UNXLINE = 469,
    T_WALLOP = 470,
    T_WALLOPS = 471,
    T_WEBIRC = 472,
    TBOOL = 473,
    THROTTLE_COUNT = 474,
    THROTTLE_TIME = 475,
    TKLINE_EXPIRE_NOTICES = 476,
    TMASKED = 477,
    TS_MAX_DELTA = 478,
    TS_WARN_DELTA = 479,
    TWODOTS = 480,
    TYPE = 481,
    UNKLINE = 482,
    USE_LOGGING = 483,
    USER = 484,
    VHOST = 485,
    VHOST6 = 486,
    WARN_NO_CONNECT_BLOCK = 487,
    WHOIS = 488,
    WHOWAS_HISTORY_LENGTH = 489,
    XLINE = 490,
    XLINE_EXEMPT = 491
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
#define MAX_CHANNELS 343
#define MAX_GLOBAL 344
#define MAX_IDLE 345
#define MAX_INVITES 346
#define MAX_LOCAL 347
#define MAX_NICK_CHANGES 348
#define MAX_NICK_LENGTH 349
#define MAX_NICK_TIME 350
#define MAX_NUMBER 351
#define MAX_TARGETS 352
#define MAX_TOPIC_LENGTH 353
#define MAX_WATCH 354
#define MEMORY_CACHE 355
#define MIN_IDLE 356
#define MIN_NONWILDCARD 357
#define MIN_NONWILDCARD_SIMPLE 358
#define MMAP_CACHE 359
#define MODULE 360
#define MODULES 361
#define MOTD 362
#define NAME 363
#define NEED_IDENT 364
#define NEED_PASSWORD 365
#define NETWORK_DESC 366
#define NETWORK_NAME 367
#define NICK 368
#define NO_OPER_FLOOD 369
#define NO_TILDE 370
#define NUMBER 371
#define NUMBER_PER_CIDR 372
#define NUMBER_PER_IP 373
#define OPER_ONLY_UMODES 374
#define OPER_UMODES 375
#define OPERATOR 376
#define OPERS_BYPASS_CALLERID 377
#define PACE_WAIT 378
#define PACE_WAIT_SIMPLE 379
#define PASSWORD 380
#define PATH 381
#define PING_COOKIE 382
#define PING_TIME 383
#define PORT 384
#define QSTRING 385
#define RANDOM_IDLE 386
#define REASON 387
#define REDIRPORT 388
#define REDIRSERV 389
#define REHASH 390
#define REMOTE 391
#define REMOTEBAN 392
#define RESV 393
#define RESV_EXEMPT 394
#define RSA_PRIVATE_KEY_FILE 395
#define SECONDS 396
#define MINUTES 397
#define HOURS 398
#define DAYS 399
#define WEEKS 400
#define MONTHS 401
#define YEARS 402
#define SEND_PASSWORD 403
#define SENDQ 404
#define SERVERHIDE 405
#define SERVERINFO 406
#define SHORT_MOTD 407
#define SPOOF 408
#define SPOOF_NOTICE 409
#define SQUIT 410
#define SSL_CERTIFICATE_FILE 411
#define SSL_CERTIFICATE_FINGERPRINT 412
#define SSL_CONNECTION_REQUIRED 413
#define SSL_DH_ELLIPTIC_CURVE 414
#define SSL_DH_PARAM_FILE 415
#define SSL_MESSAGE_DIGEST_ALGORITHM 416
#define STANDARD 417
#define STATS_E_DISABLED 418
#define STATS_I_OPER_ONLY 419
#define STATS_K_OPER_ONLY 420
#define STATS_M_OPER_ONLY 421
#define STATS_O_OPER_ONLY 422
#define STATS_P_OPER_ONLY 423
#define STATS_U_OPER_ONLY 424
#define T_ALL 425
#define T_BOTS 426
#define T_CALLERID 427
#define T_CCONN 428
#define T_COMMAND 429
#define T_CLUSTER 430
#define T_DEAF 431
#define T_DEBUG 432
#define T_DLINE 433
#define T_EXTERNAL 434
#define T_FARCONNECT 435
#define T_FILE 436
#define T_FULL 437
#define T_GLOBOPS 438
#define T_INVISIBLE 439
#define T_IPV4 440
#define T_IPV6 441
#define T_LOCOPS 442
#define T_LOG 443
#define T_NCHANGE 444
#define T_NONONREG 445
#define T_OPME 446
#define T_PREPEND 447
#define T_PSEUDO 448
#define T_RECVQ 449
#define T_REJ 450
#define T_RESTART 451
#define T_SERVER 452
#define T_SERVICE 453
#define T_SERVNOTICE 454
#define T_SET 455
#define T_SHARED 456
#define T_SIZE 457
#define T_SKILL 458
#define T_SOFTCALLERID 459
#define T_SPY 460
#define T_SSL 461
#define T_SSL_CIPHER_LIST 462
#define T_TARGET 463
#define T_UMODES 464
#define T_UNAUTH 465
#define T_UNDLINE 466
#define T_UNLIMITED 467
#define T_UNRESV 468
#define T_UNXLINE 469
#define T_WALLOP 470
#define T_WALLOPS 471
#define T_WEBIRC 472
#define TBOOL 473
#define THROTTLE_COUNT 474
#define THROTTLE_TIME 475
#define TKLINE_EXPIRE_NOTICES 476
#define TMASKED 477
#define TS_MAX_DELTA 478
#define TS_WARN_DELTA 479
#define TWODOTS 480
#define TYPE 481
#define UNKLINE 482
#define USE_LOGGING 483
#define USER 484
#define VHOST 485
#define VHOST6 486
#define WARN_NO_CONNECT_BLOCK 487
#define WHOIS 488
#define WHOWAS_HISTORY_LENGTH 489
#define XLINE 490
#define XLINE_EXEMPT 491

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 141 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 696 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 713 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1397

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  243
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  301
/* YYNRULES -- Number of rules.  */
#define YYNRULES  681
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1342

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   491

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
       2,     2,     2,     2,   241,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   242,   237,
       2,   240,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   239,     2,   238,     2,     2,     2,     2,
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
     235,   236
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   381,   381,   382,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   412,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   423,   423,
     424,   425,   426,   427,   434,   436,   436,   437,   437,   437,
     439,   445,   455,   457,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   481,   490,   499,   508,
     517,   526,   536,   535,   541,   541,   542,   548,   554,   560,
     568,   583,   598,   613,   628,   638,   652,   661,   689,   717,
     742,   764,   786,   796,   798,   798,   799,   800,   801,   802,
     804,   813,   822,   836,   835,   853,   853,   854,   854,   854,
     856,   862,   873,   872,   891,   891,   892,   892,   892,   892,
     892,   894,   900,   906,   912,   934,   935,   935,   937,   937,
     938,   940,   947,   947,   960,   961,   963,   963,   964,   964,
     966,   974,   977,   983,   982,   988,   988,   989,   993,   997,
    1001,  1005,  1009,  1013,  1017,  1028,  1027,  1088,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,
    1101,  1107,  1113,  1119,  1125,  1136,  1142,  1153,  1160,  1159,
    1165,  1165,  1166,  1170,  1174,  1178,  1182,  1186,  1190,  1194,
    1198,  1202,  1206,  1210,  1214,  1218,  1222,  1226,  1230,  1234,
    1238,  1242,  1246,  1250,  1257,  1256,  1262,  1262,  1263,  1267,
    1271,  1275,  1279,  1283,  1287,  1291,  1295,  1299,  1303,  1307,
    1311,  1315,  1319,  1323,  1327,  1331,  1335,  1339,  1343,  1347,
    1351,  1355,  1359,  1363,  1367,  1371,  1375,  1386,  1385,  1441,
    1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,
    1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1460,  1466,
    1472,  1478,  1484,  1490,  1496,  1502,  1508,  1514,  1521,  1527,
    1533,  1539,  1548,  1558,  1557,  1563,  1563,  1564,  1568,  1579,
    1578,  1585,  1584,  1589,  1589,  1590,  1594,  1598,  1604,  1604,
    1605,  1605,  1605,  1605,  1605,  1607,  1607,  1609,  1609,  1611,
    1624,  1641,  1647,  1658,  1657,  1703,  1703,  1704,  1705,  1706,
    1707,  1708,  1709,  1710,  1711,  1712,  1714,  1720,  1726,  1732,
    1744,  1743,  1749,  1749,  1750,  1754,  1758,  1762,  1766,  1770,
    1774,  1778,  1782,  1786,  1792,  1806,  1815,  1829,  1828,  1843,
    1843,  1844,  1844,  1844,  1844,  1846,  1852,  1858,  1868,  1870,
    1870,  1871,  1871,  1873,  1890,  1889,  1912,  1912,  1913,  1913,
    1913,  1913,  1915,  1921,  1941,  1940,  1946,  1946,  1947,  1951,
    1955,  1959,  1963,  1967,  1971,  1975,  1979,  1983,  1994,  1993,
    2012,  2012,  2013,  2013,  2013,  2015,  2022,  2021,  2027,  2027,
    2028,  2032,  2036,  2040,  2044,  2048,  2052,  2056,  2060,  2064,
    2075,  2074,  2146,  2146,  2147,  2148,  2149,  2150,  2151,  2152,
    2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2163,
    2169,  2175,  2181,  2194,  2207,  2213,  2219,  2223,  2230,  2229,
    2234,  2234,  2235,  2239,  2245,  2256,  2262,  2268,  2274,  2290,
    2289,  2315,  2315,  2316,  2316,  2316,  2318,  2338,  2349,  2348,
    2375,  2375,  2376,  2376,  2376,  2378,  2384,  2394,  2396,  2396,
    2397,  2397,  2399,  2417,  2416,  2437,  2437,  2438,  2438,  2438,
    2440,  2446,  2456,  2458,  2458,  2459,  2460,  2461,  2462,  2463,
    2464,  2465,  2466,  2467,  2468,  2469,  2470,  2471,  2472,  2473,
    2474,  2475,  2476,  2477,  2478,  2479,  2480,  2481,  2482,  2483,
    2484,  2485,  2486,  2487,  2488,  2489,  2490,  2491,  2492,  2493,
    2494,  2495,  2496,  2497,  2498,  2499,  2500,  2501,  2502,  2503,
    2504,  2505,  2506,  2509,  2514,  2519,  2524,  2529,  2535,  2540,
    2545,  2550,  2555,  2560,  2565,  2570,  2575,  2580,  2585,  2590,
    2595,  2600,  2605,  2611,  2616,  2621,  2626,  2631,  2636,  2641,
    2646,  2649,  2654,  2657,  2662,  2667,  2672,  2677,  2682,  2687,
    2692,  2697,  2702,  2707,  2712,  2717,  2723,  2722,  2727,  2727,
    2728,  2731,  2734,  2737,  2740,  2743,  2746,  2749,  2752,  2755,
    2758,  2761,  2764,  2767,  2770,  2773,  2776,  2779,  2782,  2785,
    2788,  2791,  2797,  2796,  2801,  2801,  2802,  2805,  2808,  2811,
    2814,  2817,  2820,  2823,  2826,  2829,  2832,  2835,  2838,  2841,
    2844,  2847,  2850,  2853,  2856,  2859,  2864,  2869,  2874,  2879,
    2888,  2890,  2890,  2891,  2892,  2893,  2894,  2895,  2896,  2897,
    2898,  2899,  2900,  2901,  2902,  2903,  2904,  2906,  2911,  2916,
    2921,  2926,  2931,  2936,  2941,  2946,  2951,  2956,  2961,  2966,
    2975,  2977,  2977,  2978,  2979,  2980,  2981,  2982,  2983,  2984,
    2985,  2986,  2987,  2989,  2995,  3011,  3020,  3026,  3032,  3038,
    3047,  3053
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
  "MASK", "MAX_ACCEPT", "MAX_BANS", "MAX_CHANNELS", "MAX_GLOBAL",
  "MAX_IDLE", "MAX_INVITES", "MAX_LOCAL", "MAX_NICK_CHANGES",
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
     485,   486,   487,   488,   489,   490,   491,    59,   125,   123,
      61,    44,    58
};
# endif

#define YYPACT_NINF -978

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-978)))

#define YYTABLE_NINF -143

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -978,   680,  -978,  -215,  -207,  -205,  -978,  -978,  -978,  -199,
    -978,  -196,  -978,  -978,  -978,  -194,  -978,  -978,  -978,  -189,
    -160,  -978,  -154,  -978,  -146,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,   303,   757,  -141,  -140,  -134,    26,  -126,   413,  -123,
    -100,   -94,    85,   -92,   -70,   -55,   686,   559,   -53,    10,
     -26,    14,   -18,   -31,    -8,     4,     6,     7,  -978,  -978,
    -978,  -978,  -978,    52,    60,    71,    77,    81,    82,    83,
      86,    95,   103,   105,   106,   109,   275,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,   715,   649,    25,  -978,   110,    29,  -978,  -978,    28,
    -978,   111,   115,   116,   119,   120,   125,   129,   131,   134,
     135,   139,   140,   143,   155,   160,   162,   165,   166,   168,
     173,   176,   177,   178,   181,   184,   185,  -978,  -978,   186,
     188,   190,   193,   196,   200,   201,   202,   203,   204,   205,
     207,   208,   214,   218,   219,   225,   228,   231,    51,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,   395,    27,   396,
     -10,   235,   236,    30,  -978,  -978,  -978,    11,   392,    32,
    -978,   237,   239,   241,   242,   243,   244,   246,   247,   250,
     332,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,    75,   251,   252,   253,   254,  -978,   255,   257,   258,
     261,   262,   263,   264,   267,   269,   283,   284,   286,   290,
     291,   294,   154,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,    72,    88,   298,    15,  -978,  -978,
    -978,    66,   199,  -978,   299,    43,  -978,  -978,    58,  -978,
     130,   421,   422,   318,  -978,   117,   174,   338,   179,   174,
     174,   174,   441,   174,   174,   442,   443,   447,   327,  -978,
     329,   328,   333,   335,  -978,   344,   347,   349,   351,   352,
     354,   356,   359,   360,   362,   364,   365,   240,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,   330,   366,   367,   369,   370,
     372,   373,  -978,   374,   375,   376,   378,   380,   382,   383,
      50,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,   387,   389,    17,
    -978,  -978,  -978,   439,   393,  -978,  -978,   398,   403,    55,
    -978,  -978,  -978,   428,   174,   456,   174,   174,   431,   535,
     174,   437,   540,   542,   544,   445,   450,   454,   174,   549,
     550,   557,   558,   174,   560,   561,   562,   563,   464,   446,
     451,   467,   174,   174,   470,   472,   474,  -197,  -183,   475,
     476,   477,   479,   582,   174,   483,   174,   174,   485,   588,
     468,  -978,   486,   469,   471,  -978,   473,   484,   497,   499,
     504,   276,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,   505,   506,    35,  -978,  -978,  -978,   488,   508,
     509,  -978,   510,  -978,    12,  -978,  -978,  -978,  -978,  -978,
     577,   584,   489,  -978,   515,   513,   514,    16,  -978,  -978,
    -978,   518,   516,   519,  -978,   521,   525,   527,   536,  -978,
     537,   539,   161,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,   538,   541,   548,   552,    40,  -978,
    -978,  -978,  -978,   494,   564,   174,   650,   575,   664,   578,
     580,   581,   565,  -978,  -978,   679,   670,   590,   684,   569,
     685,   687,   708,   709,   696,   697,   698,   699,   707,   710,
     712,   716,   717,   719,   721,   601,  -978,   602,   612,  -978,
      53,  -978,  -978,  -978,  -978,   623,   616,  -978,   615,   620,
     618,   619,   621,   622,     2,  -978,  -978,  -978,  -978,  -978,
     730,   626,  -978,   628,   629,  -978,   630,    13,  -978,  -978,
    -978,  -978,   634,   635,   637,  -978,   638,   627,   639,   640,
     643,   648,   655,   657,   659,   660,   662,   665,   666,   667,
    -978,  -978,   750,   751,   174,   646,   789,   791,   174,   792,
     795,   174,   782,   797,   802,   174,   803,   803,   683,  -978,
    -978,   787,  -114,   793,   704,   794,   798,   689,   800,   805,
     809,   806,   812,   814,   817,   690,  -978,   819,   822,   694,
    -978,   702,  -978,   823,   825,   720,  -978,   722,   724,   725,
     726,   731,   732,   733,   738,   742,   745,   747,   752,   755,
     756,   758,   760,   762,   764,   765,   770,   771,   772,   773,
     775,   776,   777,   801,   711,   778,   780,   781,   783,   784,
     785,   786,   788,   796,   799,   804,   807,   808,   810,   811,
     813,   815,   818,   820,   821,   824,  -978,  -978,   828,   728,
     727,   857,   882,   889,   894,   896,   826,  -978,   898,   901,
     827,  -978,  -978,   902,   904,   829,   919,   830,  -978,   831,
     833,  -978,  -978,   907,   908,   834,  -978,  -978,   909,   835,
     832,   910,   912,   916,   836,   837,   926,   929,   838,  -978,
    -978,   930,   932,   935,   839,  -978,   841,   842,   843,   844,
     845,   846,   847,   848,   849,  -978,   850,   851,   852,   853,
      20,   854,   855,   856,   858,   859,   860,   861,   862,   863,
     864,   865,   866,   867,   868,   869,  -978,  -978,   936,   870,
     871,  -978,   872,  -978,    80,  -978,   943,   944,   964,   977,
     874,  -978,   875,  -978,  -978,   983,   876,   984,   878,  -978,
    -978,  -978,  -978,  -978,   174,   174,   174,   174,   174,   174,
     174,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,   880,   881,   883,   -34,   884,
     885,   886,   887,   888,   890,   891,   892,   893,   895,    36,
     897,   899,  -978,   900,   903,   905,   906,   911,   913,   914,
      -4,   915,   917,   918,   920,   921,   922,   923,  -978,   924,
     925,  -978,  -978,   927,   928,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -175,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -174,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   931,
     933,   357,   934,   937,   938,   939,   940,  -978,   941,   942,
    -978,   945,   946,   -29,   947,   948,  -978,  -978,  -978,  -978,
     949,   950,  -978,   951,   953,   448,   954,   955,   956,   957,
     761,   958,   959,  -978,   960,   961,   962,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -173,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,   963,   384,  -978,  -978,   965,   879,   966,  -978,
      23,  -978,  -978,  -978,  -978,   967,   968,   970,   971,  -978,
    -978,   972,   816,   973,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -133,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   803,
     803,   803,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,   -48,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   801,
    -978,   711,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,   -42,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   -33,  -978,
    1010,   919,   974,  -978,  -978,  -978,  -978,  -978,  -978,   975,
    -978,   976,   978,  -978,  -978,   979,   980,  -978,  -978,   981,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,   -32,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
     -15,  -978,  -978,  -978,  -978,  -978,  -978,  -978,    20,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
     -13,  -978,  -978,  1001,   -74,   985,   982,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,    -7,  -978,  -978,  -978,   -34,  -978,  -978,
    -978,  -978,    -4,  -978,  -978,  -978,   357,  -978,   -29,  -978,
    -978,  -978,   997,  1000,   999,  1003,  1008,  1009,  -978,   448,
    -978,   761,  -978,  -978,   384,   987,   989,   990,   226,  -978,
    -978,   816,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,    64,  -978,  -978,  -978,
     226,  -978
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
     108,   107,   646,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   632,   645,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   633,   643,
     644,     0,     0,     0,   471,     0,     0,   469,   470,     0,
     532,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   602,   576,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
     485,   486,   530,   493,   531,   525,   526,   527,   528,   524,
     497,   487,   488,   489,   490,   491,   492,   494,   495,   496,
     498,   499,   529,   503,   504,   505,   506,   502,   501,   507,
     514,   515,   508,   509,   510,   500,   512,   522,   523,   520,
     521,   513,   511,   518,   519,   516,   517,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     672,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   662,   663,   664,   665,   666,   667,   668,   670,   669,
     671,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    69,    66,    64,    70,    71,    65,
      72,    73,    74,    55,    68,    58,    59,    60,    56,    67,
      61,    62,    63,    57,     0,     0,     0,     0,   137,   138,
     139,     0,     0,   362,     0,     0,   360,   361,     0,   109,
       0,     0,     0,     0,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   631,
       0,     0,     0,     0,   283,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   251,
     254,   256,   257,   258,   259,   260,   261,   262,   263,   252,
     253,   255,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,   438,     0,     0,     0,     0,     0,     0,     0,
       0,   413,   414,   415,   416,   417,   418,   419,   421,   420,
     423,   427,   424,   425,   426,   422,   464,     0,     0,     0,
     461,   462,   463,     0,     0,   468,   479,     0,     0,     0,
     476,   477,   478,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   483,     0,     0,     0,   330,     0,     0,     0,     0,
       0,     0,   316,   317,   318,   319,   324,   320,   321,   322,
     323,   455,     0,     0,     0,   452,   453,   454,     0,     0,
       0,   291,     0,   301,     0,   299,   300,   302,   303,    49,
       0,     0,     0,    45,     0,     0,     0,     0,   116,   117,
     118,     0,     0,     0,   214,     0,     0,     0,     0,   188,
       0,     0,     0,   168,   169,   170,   171,   172,   175,   176,
     177,   174,   173,   178,     0,     0,     0,     0,     0,   350,
     351,   352,   353,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   661,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,     0,   396,
       0,   391,   392,   393,   140,     0,     0,   136,     0,     0,
       0,     0,     0,     0,     0,   125,   126,   128,   127,   129,
       0,     0,   359,     0,     0,   374,     0,     0,   367,   368,
     369,   370,     0,     0,     0,   103,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,   267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   249,
     428,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   412,     0,     0,     0,
     460,     0,   467,     0,     0,     0,   475,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   482,   325,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   315,     0,     0,
       0,   451,   304,     0,     0,     0,     0,     0,   298,     0,
       0,    44,   119,     0,     0,     0,   115,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     354,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   660,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,   394,     0,     0,
       0,   390,     0,   135,     0,   130,     0,     0,     0,     0,
       0,   124,     0,   358,   371,     0,     0,     0,     0,   366,
     112,   111,   110,   658,    28,    28,    28,    28,    28,    28,
      28,    30,    29,   659,   647,   648,   649,   650,   651,   652,
     653,   654,   657,   655,   656,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   411,     0,
       0,   459,   472,     0,     0,   474,   546,   550,   533,   534,
     565,   537,   628,   629,   573,   538,   539,   570,   545,   544,
     553,   543,   540,   541,   549,   548,   547,   571,   535,   626,
     627,   569,   612,   606,   622,   607,   608,   609,   617,   625,
     610,   619,   623,   613,   624,   614,   618,   611,   621,   616,
     615,   620,     0,   605,   585,   586,   587,   580,   598,   581,
     582,   583,   593,   601,   584,   595,   599,   589,   600,   590,
     594,   588,   597,   592,   591,   596,     0,   579,   566,   564,
     567,   572,   568,   555,   562,   563,   560,   561,   556,   557,
     558,   559,   574,   575,   542,   552,   551,   554,   536,     0,
       0,     0,     0,     0,     0,     0,     0,   314,     0,     0,
     450,     0,     0,     0,   309,   305,   308,   290,    50,    51,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,     0,     0,     0,   348,   676,   673,
     674,   675,   680,   679,   681,   677,   678,    99,    94,   102,
      93,    89,    87,    88,    86,     0,    85,    90,    91,   100,
     101,    92,    96,    95,    77,    76,    81,    78,    80,    79,
      97,    98,     0,     0,   389,   141,     0,     0,     0,   153,
       0,   145,   146,   148,   147,     0,     0,     0,     0,   123,
     363,     0,     0,     0,   365,    31,    32,    33,    34,    35,
      36,    37,   278,   279,   271,   288,   287,     0,   286,   272,
     274,   282,   275,   273,   281,   268,   280,   270,   269,    38,
      38,    38,    40,    39,   276,   277,   433,   436,   437,   447,
     444,   430,   445,   442,   443,     0,   441,   446,   429,   435,
     432,   434,   448,   431,   465,   466,   480,   481,   603,     0,
     577,     0,   328,   329,   339,   335,   336,   338,   343,   340,
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
      43,   439,     0,   604,   578,   331,     0,   292,     0,   310,
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
    -978,  -978,  -978,  -293,  -314,  -977,  -646,  -978,  -978,   991,
    -978,  -978,  -978,  -978,   877,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,   -99,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    1069,  -978,  -978,  -978,  -978,  -978,  -978,   656,  -978,  -978,
    -978,  -978,  -978,   455,  -978,  -978,  -978,  -978,  -978,  -978,
     952,  -978,  -978,  -978,  -978,    96,  -978,  -978,  -978,  -978,
    -978,  -193,  -978,  -978,  -978,   631,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -145,  -978,  -978,
    -978,  -132,  -978,  -978,  -978,   969,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -108,  -978,  -978,  -978,  -978,  -978,
    -115,  -978,   691,  -978,  -978,  -978,     9,  -978,  -978,  -978,
    -978,  -978,   713,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -105,  -978,  -978,  -978,  -978,  -978,  -978,   663,  -978,  -978,
    -978,  -978,  -978,   986,  -978,  -978,  -978,  -978,   596,  -978,
    -978,  -978,  -978,  -978,   -98,  -978,  -978,  -978,   632,  -978,
    -978,  -978,  -978,   -89,  -978,  -978,  -978,   873,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   -66,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   744,  -978,
    -978,  -978,  -978,  -978,   840,  -978,  -978,  -978,  -978,  1113,
    -978,  -978,  -978,  -978,   988,  -978,  -978,  -978,  -978,  1062,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,    90,  -978,  -978,  -978,    93,  -978,
    -978,  -978,  -978,  -978,  -978,  1137,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,   994,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   841,   842,  1112,  1113,    27,   223,   224,
     225,   226,    28,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   559,  1045,  1046,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,    29,    77,
      78,    79,    80,    81,    30,    63,   507,   508,   509,   510,
      31,    70,   594,   595,   596,   597,   598,   599,    32,   297,
     298,   299,   300,   301,  1070,  1071,  1072,  1073,  1074,  1255,
    1336,  1337,    33,    64,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   765,  1230,  1231,   533,   760,
    1202,  1203,    34,    53,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   635,  1097,  1098,    35,    61,   493,   745,  1168,
    1169,   494,   495,   496,  1172,  1005,  1006,   497,   498,    36,
      59,   471,   472,   473,   474,   475,   476,   477,   730,  1154,
    1155,   478,   479,   480,    37,    65,   538,   539,   540,   541,
     542,    38,   305,   306,   307,    39,    72,   607,   608,   609,
     610,   611,   826,  1273,  1274,    40,    68,   580,   581,   582,
     583,   809,  1250,  1251,    41,    54,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   657,  1125,  1126,
     391,   392,   393,   394,   395,    42,    60,   484,   485,   486,
     487,    43,    55,   399,   400,   401,   402,    44,   116,   117,
     118,    45,    57,   409,   410,   411,   412,    46,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   440,   966,   967,   212,   439,   942,   943,   213,
     214,   215,   216,    47,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    48,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     870,   871,   618,   589,  1123,   621,   622,   623,    73,   625,
     626,   295,   504,   488,   603,   303,   295,   504,   396,  1095,
    1165,   711,    49,    50,  1066,   712,   396,   114,   481,   406,
     114,   220,    51,   534,    52,   713,   481,  1041,    74,   714,
      56,   534,   869,    58,   303,    62,    75,  1109,  1110,  1111,
      66,   365,   120,   366,   577,   367,   406,   121,   122,   603,
     123,   124,  1138,  1140,  1237,   125,  1139,  1141,  1238,   489,
     368,   874,   875,   577,   535,   126,   127,   128,   490,    67,
     491,  1066,   535,   397,   129,    69,   220,   130,   131,   132,
     369,   397,   115,    71,   133,   115,   505,  1096,   111,   112,
     678,   505,   680,   681,  1276,   113,   684,   370,  1277,   371,
     590,   134,   135,   119,   692,    76,   217,   536,   372,   697,
    1042,   604,   304,   136,  1043,   536,   137,   138,   706,   707,
     373,  1067,  1278,  1279,  1280,   221,   407,   139,  1306,   218,
     720,   492,   722,   723,   140,   219,   141,   227,   142,   398,
     143,   304,   869,   144,   145,   251,   222,   398,   374,   482,
     408,   578,   511,   407,   537,   146,   604,   482,  1166,   228,
     147,   148,   537,   149,   150,   151,   591,  1167,   152,   375,
     578,   512,  1044,   252,   229,   253,   294,   408,  1067,  1281,
     221,  -142,   506,  1282,   592,  1285,  -142,   506,   376,  1286,
     589,   513,  1124,   153,  1287,  1298,   309,   377,  1288,  1299,
     593,   222,   254,   302,   154,   155,   156,   157,   158,   159,
     160,   308,  1300,   255,  1303,  1068,  1301,   499,  1304,   514,
    1310,   778,   310,   616,  1311,   256,   257,   258,   296,   605,
     820,   330,   606,   296,   311,   313,   312,   588,   259,  1069,
     747,   828,   260,   586,   755,   669,   483,   378,   331,   332,
     612,  1256,   261,   333,   483,   262,   263,   404,   502,   515,
     161,   162,   163,   740,   164,   165,    82,   462,   774,   579,
     379,   601,  1068,   166,   605,   167,   516,   606,   665,   460,
     617,   810,   315,   675,   264,   620,   463,  1328,   579,  1329,
     316,  1339,    83,    84,    73,  1340,  1069,   590,   334,    85,
     265,   317,   554,   266,   267,   268,   464,   318,   517,   518,
     857,   319,   320,   321,   861,   584,   322,   864,   335,   336,
     337,   868,   338,   230,    74,   323,   339,    86,    87,    88,
      89,   340,    75,   324,   465,   325,   326,  1330,   341,   327,
     403,   413,    90,    91,    92,   414,   415,   342,   343,   416,
     417,   269,    93,    94,  1331,   418,    95,   231,   344,   419,
     519,   420,  1144,   591,   421,   422,   232,   233,   234,   423,
     424,   235,   236,   425,   270,   271,   237,   238,   239,   345,
     520,   592,   575,   511,   521,   426,   462,   488,  1145,   768,
     427,   466,   428,  1332,  1333,   429,   430,   593,   431,   467,
     468,    76,   512,   432,   120,   463,   433,   434,   435,   121,
     122,   436,   123,   124,   437,   438,   441,   125,   442,   469,
     443,  1146,   513,   444,   346,   464,   445,   126,   127,   128,
     446,   447,   448,   449,   450,   451,   129,   452,   453,   130,
     131,   132,  1177,   489,   454,  1334,   133,  1240,   455,   456,
     514,  1335,   490,   465,   491,   457,  1147,  1148,   458,  1178,
    1179,   459,  1149,   134,   135,   500,   501,   543,   648,   544,
    1180,   545,   546,   547,   548,   136,   549,   550,   137,   138,
     551,   555,   556,   557,   558,   560,  1150,   561,   562,   139,
     515,   563,   564,   565,   566,   470,   140,   567,   141,   568,
     142,  1151,   143,   328,   736,   144,   145,   516,  1181,  1182,
     466,  1183,  1241,   569,   570,   492,   571,   146,   467,   468,
     572,   573,   147,   148,   574,   149,   150,   151,   585,   600,
     152,  1085,  1086,  1087,  1088,  1089,  1090,  1091,   469,   517,
     518,   613,   614,  1184,  1242,   615,   619,   624,   627,   628,
     251,  1185,  1243,   629,   630,   153,   631,   650,   632,   671,
     552,  1244,   679,   633,  1152,   634,   154,   155,   156,   157,
     158,   159,   160,  1186,   636,  1187,  1188,   637,   252,   638,
     253,   639,   640,  1153,   641,  1245,   642,  1246,  1247,   643,
     644,   519,   645,  1189,   646,   647,   651,   652,  1307,   653,
     654,  1248,   655,   656,   658,   659,   660,   254,   661,  1249,
     662,   520,   663,   664,   470,   521,  1190,   667,   255,   668,
     672,  1191,   161,   162,   163,  1192,   164,   165,   673,  1193,
     256,   257,   258,   674,  1194,   166,   677,   167,  1195,   682,
     365,   683,   366,   259,   367,   685,   686,   260,   687,  1196,
     688,  1197,  1198,   689,  1199,   693,   694,   261,   690,   368,
     262,   263,   691,   695,   696,  1200,   698,   699,   700,   701,
       2,     3,   702,  1201,     4,   705,   703,   230,   708,   369,
     709,   704,   710,   715,   716,   717,     5,   718,   719,   264,
       6,   721,     7,   724,   725,   726,   370,   749,   371,   728,
       8,   729,   776,   731,   750,   265,   330,   372,   266,   267,
     268,   231,     9,   727,   732,   742,   751,    10,    11,   373,
     232,   233,   234,   331,   332,   235,   236,   733,   333,   734,
     237,   238,   239,   617,   735,   738,   739,    12,   743,   744,
     746,    13,   752,   753,   754,   757,   758,   374,    82,   759,
     944,   761,   945,   946,    14,   762,   269,   763,   834,   835,
     836,   837,   838,   839,   840,   770,   764,   766,   375,   767,
     779,   771,   777,   334,    83,    84,    15,    16,   772,   270,
     271,    85,   773,   780,   781,   786,   782,   376,   783,   784,
     787,    17,   785,   335,   336,   337,   377,   338,   788,   790,
    1208,   339,  1209,  1210,   789,   791,   340,   792,    18,    86,
      87,    88,    89,   341,   793,   794,   795,   796,   797,   798,
      19,    20,   342,   343,    90,    91,    92,   799,   806,   807,
     800,   812,   801,   344,    93,    94,   802,   803,    95,   804,
     922,   805,   808,   813,   814,    21,   378,   815,   816,   817,
     822,   818,   819,   823,   345,   824,   855,   856,    22,   825,
     827,   830,   831,    23,   832,   833,   843,   844,    24,   379,
     845,    25,   947,   948,   949,   846,   858,   950,   951,  1263,
     952,   953,   847,   954,   848,   955,   849,   850,   956,   851,
     957,   958,   852,   853,   854,   859,   959,   860,   862,   346,
     960,   863,   865,   866,   961,   962,   963,   873,   867,   869,
     872,   964,   877,   876,   878,   883,   965,   888,   879,   880,
     881,   891,  1211,  1212,  1213,   882,   884,  1214,  1215,   892,
    1216,  1217,   885,  1218,   886,  1219,   990,   887,  1220,   889,
    1221,  1222,   890,   893,  1264,   894,  1223,   895,   989,   896,
    1224,   897,   898,   899,  1225,  1226,  1227,   991,   900,   901,
     902,  1228,   923,   924,   925,   903,  1229,   926,   927,   904,
     928,   929,   905,   930,   906,   931,  1265,   992,   932,   907,
     933,   934,   908,   909,  1266,   910,   935,   911,   993,   912,
     936,   913,   914,  1267,   937,   938,   939,   915,   916,   917,
     918,   940,   919,   920,   921,   968,   941,   969,   970,   994,
     971,   972,   973,   974,   995,   975,   996,  1268,   998,  1269,
    1270,   999,  1001,   976,  1002,  1004,   977,  1010,  1011,  1013,
    1016,   978,  1017,  1271,   979,   980,  1018,   981,   982,   821,
     983,  1272,   984,  1014,  1019,   985,  1021,   986,   987,  1022,
    1024,   988,  1025,   997,  1000,  1026,  1062,  1007,  1008,  1003,
    1009,  1012,  1015,  1075,  1076,  1023,  1027,  1020,  1028,  1029,
    1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,
    1040,  1047,  1048,  1049,  1077,  1050,  1051,  1052,  1053,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1078,  1064,  1065,
    1063,  1079,  1080,  1081,  1083,  1084,  1082,  1092,  1093,  1253,
    1094,  1099,  1100,  1101,  1102,  1103,  1289,  1104,  1105,  1106,
    1107,  1305,  1108,  1316,  1114,  1318,  1115,  1116,  1317,  1302,
    1117,  1319,  1118,  1119,  1320,  1321,   314,  1341,  1120,   576,
    1121,  1122,  1127,   769,  1128,  1129,  1323,  1130,  1131,  1132,
    1133,  1134,  1135,   756,  1136,  1137,  1257,  1322,  1142,  1312,
    1143,  1156,  1170,  1315,  1157,  1158,  1159,  1160,  1161,  1162,
    1290,  1314,  1163,  1164,   737,   748,  1173,  1174,  1175,  1171,
    1176,  1204,  1205,  1206,  1207,  1232,  1233,  1234,  1235,  1236,
    1239,   775,  1252,   829,  1258,  1259,  1254,  1260,  1261,  1262,
    1275,  1291,   811,  1338,   503,  1324,  1313,  1292,  1293,  1309,
    1294,  1295,  1296,  1297,  1325,  1308,  1326,  1327,   741,   405,
     461,  1284,  1283,   329,   553,     0,     0,     0,     0,   670,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   587,
       0,     0,     0,   666,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   602,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   649,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   676
};

static const yytype_int16 yycheck[] =
{
     646,   647,   316,     1,     8,   319,   320,   321,     1,   323,
     324,     1,     1,     1,     1,     1,     1,     1,     1,    53,
      49,   218,   237,   238,     1,   222,     1,     1,     1,     1,
       1,     1,   239,     1,   239,   218,     1,    17,    31,   222,
     239,     1,   116,   239,     1,   239,    39,    11,    12,    13,
     239,     1,     1,     3,     1,     5,     1,     6,     7,     1,
       9,    10,   237,   237,   237,    14,   241,   241,   241,    57,
      20,   185,   186,     1,    42,    24,    25,    26,    66,   239,
      68,     1,    42,    66,    33,   239,     1,    36,    37,    38,
      40,    66,    66,   239,    43,    66,    85,   131,   239,   239,
     414,    85,   416,   417,   237,   239,   420,    57,   241,    59,
     108,    60,    61,   239,   428,   108,   239,    85,    68,   433,
     100,   108,   108,    72,   104,    85,    75,    76,   442,   443,
      80,   108,  1109,  1110,  1111,   105,   108,    86,   212,   239,
     454,   129,   456,   457,    93,   239,    95,   239,    97,   132,
      99,   108,   116,   102,   103,     1,   126,   132,   108,   132,
     132,   108,     1,   108,   132,   114,   108,   132,   197,   239,
     119,   120,   132,   122,   123,   124,   174,   206,   127,   129,
     108,    20,   162,    29,   239,    31,   239,   132,   108,   237,
     105,   181,   181,   241,   192,   237,   181,   181,   148,   241,
       1,    40,   206,   152,   237,   237,   237,   157,   241,   241,
     208,   126,    58,   239,   163,   164,   165,   166,   167,   168,
     169,   239,   237,    69,   237,   202,   241,   237,   241,    68,
     237,   545,   240,   116,   241,    81,    82,    83,   228,   226,
     238,     1,   229,   228,   240,   238,   240,   181,    94,   226,
     238,   238,    98,   238,   238,   238,   229,   207,    18,    19,
     130,   238,   108,    23,   229,   111,   112,   238,   238,   108,
     219,   220,   221,   238,   223,   224,     1,     1,   238,   226,
     230,   238,   202,   232,   226,   234,   125,   229,   238,   238,
     116,   238,   240,   238,   140,   116,    20,    71,   226,    73,
     240,   237,    27,    28,     1,   241,   226,   108,    68,    34,
     156,   240,   237,   159,   160,   161,    40,   240,   157,   158,
     634,   240,   240,   240,   638,   237,   240,   641,    88,    89,
      90,   645,    92,     1,    31,   240,    96,    62,    63,    64,
      65,   101,    39,   240,    68,   240,   240,   121,   108,   240,
     240,   240,    77,    78,    79,   240,   240,   117,   118,   240,
     240,   207,    87,    88,   138,   240,    91,    35,   128,   240,
     209,   240,    15,   174,   240,   240,    44,    45,    46,   240,
     240,    49,    50,   240,   230,   231,    54,    55,    56,   149,
     229,   192,   238,     1,   233,   240,     1,     1,    41,   238,
     240,   125,   240,   177,   178,   240,   240,   208,   240,   133,
     134,   108,    20,   240,     1,    20,   240,   240,   240,     6,
       7,   240,     9,    10,   240,   240,   240,    14,   240,   153,
     240,    74,    40,   240,   194,    40,   240,    24,    25,    26,
     240,   240,   240,   240,   240,   240,    33,   240,   240,    36,
      37,    38,     4,    57,   240,   229,    43,    73,   240,   240,
      68,   235,    66,    68,    68,   240,   109,   110,   240,    21,
      22,   240,   115,    60,    61,   240,   240,   240,   238,   240,
      32,   240,   240,   240,   240,    72,   240,   240,    75,    76,
     240,   240,   240,   240,   240,   240,   139,   240,   240,    86,
     108,   240,   240,   240,   240,   229,    93,   240,    95,   240,
      97,   154,    99,   238,   238,   102,   103,   125,    70,    71,
     125,    73,   138,   240,   240,   129,   240,   114,   133,   134,
     240,   240,   119,   120,   240,   122,   123,   124,   240,   240,
     127,   834,   835,   836,   837,   838,   839,   840,   153,   157,
     158,   130,   130,   105,   170,   237,   218,   116,   116,   116,
       1,   113,   178,   116,   237,   152,   237,   237,   240,   130,
     238,   187,   116,   240,   217,   240,   163,   164,   165,   166,
     167,   168,   169,   135,   240,   137,   138,   240,    29,   240,
      31,   240,   240,   236,   240,   211,   240,   213,   214,   240,
     240,   209,   240,   155,   240,   240,   240,   240,  1254,   240,
     240,   227,   240,   240,   240,   240,   240,    58,   240,   235,
     240,   229,   240,   240,   229,   233,   178,   240,    69,   240,
     237,   183,   219,   220,   221,   187,   223,   224,   240,   191,
      81,    82,    83,   240,   196,   232,   218,   234,   200,   218,
       1,   116,     3,    94,     5,   218,   116,    98,   116,   211,
     116,   213,   214,   218,   216,   116,   116,   108,   218,    20,
     111,   112,   218,   116,   116,   227,   116,   116,   116,   116,
       0,     1,   218,   235,     4,   218,   240,     1,   218,    40,
     218,   240,   218,   218,   218,   218,    16,   218,   116,   140,
      20,   218,    22,   218,   116,   237,    57,   130,    59,   240,
      30,   240,   218,   240,   130,   156,     1,    68,   159,   160,
     161,    35,    42,   237,   240,   237,   237,    47,    48,    80,
      44,    45,    46,    18,    19,    49,    50,   240,    23,   240,
      54,    55,    56,   116,   240,   240,   240,    67,   240,   240,
     240,    71,   237,   240,   240,   237,   240,   108,     1,   240,
      49,   240,    51,    52,    84,   240,   207,   240,   141,   142,
     143,   144,   145,   146,   147,   237,   240,   240,   129,   240,
     130,   240,   218,    68,    27,    28,   106,   107,   240,   230,
     231,    34,   240,   218,   130,   116,   218,   148,   218,   218,
     130,   121,   237,    88,    89,    90,   157,    92,   218,   240,
      49,    96,    51,    52,   130,   130,   101,   130,   138,    62,
      63,    64,    65,   108,   116,   116,   130,   130,   130,   130,
     150,   151,   117,   118,    77,    78,    79,   130,   237,   237,
     130,   218,   130,   128,    87,    88,   130,   130,    91,   130,
      49,   130,   240,   237,   239,   175,   207,   237,   240,   240,
     130,   240,   240,   237,   149,   237,   116,   116,   188,   240,
     240,   237,   237,   193,   237,   237,   237,   237,   198,   230,
     237,   201,   171,   172,   173,   237,   240,   176,   177,    73,
     179,   180,   237,   182,   237,   184,   237,   237,   187,   237,
     189,   190,   237,   237,   237,   116,   195,   116,   116,   194,
     199,   116,   130,   116,   203,   204,   205,   130,   116,   116,
     237,   210,   218,   130,   130,   116,   215,   237,   130,   240,
     130,   237,   171,   172,   173,   130,   130,   176,   177,   237,
     179,   180,   130,   182,   130,   184,   218,   130,   187,   130,
     189,   190,   130,   130,   138,   130,   195,   237,   130,   237,
     199,   237,   237,   237,   203,   204,   205,   240,   237,   237,
     237,   210,   171,   172,   173,   237,   215,   176,   177,   237,
     179,   180,   237,   182,   237,   184,   170,   130,   187,   237,
     189,   190,   237,   237,   178,   237,   195,   237,   116,   237,
     199,   237,   237,   187,   203,   204,   205,   237,   237,   237,
     237,   210,   237,   237,   237,   237,   215,   237,   237,   130,
     237,   237,   237,   237,   130,   237,   130,   211,   130,   213,
     214,   130,   130,   237,   130,   116,   237,   130,   130,   130,
     130,   237,   130,   227,   237,   237,   130,   237,   237,   594,
     237,   235,   237,   218,   218,   237,   130,   237,   237,   130,
     130,   237,   130,   237,   237,   130,   130,   237,   237,   240,
     237,   237,   240,   130,   130,   237,   237,   240,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   130,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   130,   237,   237,
     240,   237,   237,   130,   130,   237,   240,   237,   237,   240,
     237,   237,   237,   237,   237,   237,   116,   237,   237,   237,
     237,   130,   237,   136,   237,   136,   237,   237,   138,  1238,
     237,   138,   237,   237,   136,   136,    77,  1340,   237,   272,
     237,   237,   237,   522,   237,   237,  1301,   237,   237,   237,
     237,   237,   237,   507,   237,   237,  1070,  1299,   237,  1277,
     237,   237,   225,  1288,   237,   237,   237,   237,   237,   237,
    1171,  1286,   237,   237,   471,   494,   237,   237,   237,   241,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   538,   237,   607,   237,   237,   240,   237,   237,   237,
     237,   237,   580,  1311,   223,  1304,  1282,   242,   242,   237,
     242,   242,   242,   242,   237,   240,   237,   237,   484,   116,
     168,  1141,  1139,    96,   240,    -1,    -1,    -1,    -1,   399,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   297,
      -1,    -1,    -1,   380,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   409
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   244,     0,     1,     4,    16,    20,    22,    30,    42,
      47,    48,    67,    71,    84,   106,   107,   121,   138,   150,
     151,   175,   188,   193,   198,   201,   245,   250,   255,   281,
     287,   293,   301,   315,   335,   358,   372,   387,   394,   398,
     408,   417,   438,   444,   450,   454,   460,   516,   532,   237,
     238,   239,   239,   336,   418,   445,   239,   455,   239,   373,
     439,   359,   239,   288,   316,   388,   239,   239,   409,   239,
     294,   239,   399,     1,    31,    39,   108,   282,   283,   284,
     285,   286,     1,    27,    28,    34,    62,    63,    64,    65,
      77,    78,    79,    87,    88,    91,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   239,   239,   239,     1,    66,   451,   452,   453,   239,
       1,     6,     7,     9,    10,    14,    24,    25,    26,    33,
      36,    37,    38,    43,    60,    61,    72,    75,    76,    86,
      93,    95,    97,    99,   102,   103,   114,   119,   120,   122,
     123,   124,   127,   152,   163,   164,   165,   166,   167,   168,
     169,   219,   220,   221,   223,   224,   232,   234,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   508,   512,   513,   514,   515,   239,   239,   239,
       1,   105,   126,   251,   252,   253,   254,   239,   239,   239,
       1,    35,    44,    45,    46,    49,    50,    54,    55,    56,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,     1,    29,    31,    58,    69,    81,    82,    83,    94,
      98,   108,   111,   112,   140,   156,   159,   160,   161,   207,
     230,   231,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   239,     1,   228,   302,   303,   304,
     305,   306,   239,     1,   108,   395,   396,   397,   239,   237,
     240,   240,   240,   238,   283,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   238,   518,
       1,    18,    19,    23,    68,    88,    89,    90,    92,    96,
     101,   108,   117,   118,   128,   149,   194,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     1,     3,     5,    20,    40,
      57,    59,    68,    80,   108,   129,   148,   157,   207,   230,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   433,   434,   435,   436,   437,     1,    66,   132,   446,
     447,   448,   449,   240,   238,   452,     1,   108,   132,   456,
     457,   458,   459,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   509,
     505,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     238,   462,     1,    20,    40,    68,   125,   133,   134,   153,
     229,   374,   375,   376,   377,   378,   379,   380,   384,   385,
     386,     1,   132,   229,   440,   441,   442,   443,     1,    57,
      66,    68,   129,   360,   364,   365,   366,   370,   371,   237,
     240,   240,   238,   252,     1,    85,   181,   289,   290,   291,
     292,     1,    20,    40,    68,   108,   125,   157,   158,   209,
     229,   233,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   331,     1,    42,    85,   132,   389,   390,
     391,   392,   393,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   238,   534,   237,   240,   240,   240,   240,   265,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   238,   257,     1,   108,   226,
     410,   411,   412,   413,   237,   240,   238,   303,   181,     1,
     108,   174,   192,   208,   295,   296,   297,   298,   299,   300,
     240,   238,   396,     1,   108,   226,   229,   400,   401,   402,
     403,   404,   130,   130,   130,   237,   116,   116,   247,   218,
     116,   247,   247,   247,   116,   247,   247,   116,   116,   116,
     237,   237,   240,   240,   240,   355,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   238,   338,
     237,   240,   240,   240,   240,   240,   240,   430,   240,   240,
     240,   240,   240,   240,   240,   238,   420,   240,   240,   238,
     447,   130,   237,   240,   240,   238,   457,   218,   247,   116,
     247,   247,   218,   116,   247,   218,   116,   116,   116,   218,
     218,   218,   247,   116,   116,   116,   116,   247,   116,   116,
     116,   116,   218,   240,   240,   218,   247,   247,   218,   218,
     218,   218,   222,   218,   222,   218,   218,   218,   218,   116,
     247,   218,   247,   247,   218,   116,   237,   237,   240,   240,
     381,   240,   240,   240,   240,   240,   238,   375,   240,   240,
     238,   441,   237,   240,   240,   361,   240,   238,   365,   130,
     130,   237,   237,   240,   240,   238,   290,   237,   240,   240,
     332,   240,   240,   240,   240,   328,   240,   240,   238,   318,
     237,   240,   240,   240,   238,   390,   218,   218,   247,   130,
     218,   130,   218,   218,   218,   237,   116,   130,   218,   130,
     240,   130,   130,   116,   116,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   237,   237,   240,   414,
     238,   411,   218,   237,   239,   237,   240,   240,   240,   240,
     238,   296,   130,   237,   237,   240,   405,   240,   238,   401,
     237,   237,   237,   237,   141,   142,   143,   144,   145,   146,
     147,   246,   247,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   116,   116,   247,   240,   116,
     116,   247,   116,   116,   247,   130,   116,   116,   247,   116,
     249,   249,   237,   130,   185,   186,   130,   218,   130,   130,
     240,   130,   130,   116,   130,   130,   130,   130,   237,   130,
     130,   237,   237,   130,   130,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,    49,   171,   172,   173,   176,   177,   179,   180,
     182,   184,   187,   189,   190,   195,   199,   203,   204,   205,
     210,   215,   510,   511,    49,    51,    52,   171,   172,   173,
     176,   177,   179,   180,   182,   184,   187,   189,   190,   195,
     199,   203,   204,   205,   210,   215,   506,   507,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   130,
     218,   240,   130,   116,   130,   130,   130,   237,   130,   130,
     237,   130,   130,   240,   116,   368,   369,   237,   237,   237,
     130,   130,   237,   130,   218,   240,   130,   130,   130,   218,
     240,   130,   130,   237,   130,   130,   130,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,    17,   100,   104,   162,   266,   267,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   130,   240,   237,   237,     1,   108,   202,   226,
     307,   308,   309,   310,   311,   130,   130,   130,   130,   237,
     237,   130,   240,   130,   237,   246,   246,   246,   246,   246,
     246,   246,   237,   237,   237,    53,   131,   356,   357,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,    11,
      12,    13,   248,   249,   237,   237,   237,   237,   237,   237,
     237,   237,   237,     8,   206,   431,   432,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   241,
     237,   241,   237,   237,    15,    41,    74,   109,   110,   115,
     139,   154,   217,   236,   382,   383,   237,   237,   237,   237,
     237,   237,   237,   237,   237,    49,   197,   206,   362,   363,
     225,   241,   367,   237,   237,   237,   237,     4,    21,    22,
      32,    70,    71,    73,   105,   113,   135,   137,   138,   155,
     178,   183,   187,   191,   196,   200,   211,   213,   214,   216,
     227,   235,   333,   334,   237,   237,   237,   237,    49,    51,
      52,   171,   172,   173,   176,   177,   179,   180,   182,   184,
     187,   189,   190,   195,   199,   203,   204,   205,   210,   215,
     329,   330,   237,   237,   237,   237,   237,   237,   241,   237,
      73,   138,   170,   178,   187,   211,   213,   214,   227,   235,
     415,   416,   237,   240,   240,   312,   238,   308,   237,   237,
     237,   237,   237,    73,   138,   170,   178,   187,   211,   213,
     214,   227,   235,   406,   407,   237,   237,   241,   248,   248,
     248,   237,   241,   511,   507,   237,   241,   237,   241,   116,
     369,   237,   242,   242,   242,   242,   242,   242,   237,   241,
     237,   241,   267,   237,   241,   130,   212,   249,   240,   237,
     237,   241,   357,   432,   383,   363,   136,   138,   136,   138,
     136,   136,   334,   330,   416,   237,   237,   237,    71,    73,
     121,   138,   177,   178,   229,   235,   313,   314,   407,   237,
     241,   314
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   243,   244,   244,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   246,   246,
     247,   247,   247,   247,   247,   247,   247,   247,   248,   248,
     249,   249,   249,   249,   250,   251,   251,   252,   252,   252,
     253,   254,   255,   256,   256,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   258,   259,   260,   261,
     262,   263,   265,   264,   266,   266,   267,   267,   267,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   282,   283,   283,   283,   283,
     284,   285,   286,   288,   287,   289,   289,   290,   290,   290,
     291,   292,   294,   293,   295,   295,   296,   296,   296,   296,
     296,   297,   298,   299,   300,   301,   302,   302,   303,   303,
     303,   304,   306,   305,   307,   307,   308,   308,   308,   308,
     309,   310,   310,   312,   311,   313,   313,   314,   314,   314,
     314,   314,   314,   314,   314,   316,   315,   317,   317,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   328,   327,
     329,   329,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   332,   331,   333,   333,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   336,   335,   337,
     337,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   355,   354,   356,   356,   357,   357,   359,
     358,   361,   360,   362,   362,   363,   363,   363,   364,   364,
     365,   365,   365,   365,   365,   367,   366,   368,   368,   369,
     369,   370,   371,   373,   372,   374,   374,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   376,   377,   378,   379,
     381,   380,   382,   382,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   384,   385,   386,   388,   387,   389,
     389,   390,   390,   390,   390,   391,   392,   393,   394,   395,
     395,   396,   396,   397,   399,   398,   400,   400,   401,   401,
     401,   401,   402,   403,   405,   404,   406,   406,   407,   407,
     407,   407,   407,   407,   407,   407,   407,   407,   409,   408,
     410,   410,   411,   411,   411,   412,   414,   413,   415,   415,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     418,   417,   419,   419,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   428,   430,   429,
     431,   431,   432,   432,   433,   434,   435,   436,   437,   439,
     438,   440,   440,   441,   441,   441,   442,   443,   445,   444,
     446,   446,   447,   447,   447,   448,   449,   450,   451,   451,
     452,   452,   453,   455,   454,   456,   456,   457,   457,   457,
     458,   459,   460,   461,   461,   462,   462,   462,   462,   462,
     462,   462,   462,   462,   462,   462,   462,   462,   462,   462,
     462,   462,   462,   462,   462,   462,   462,   462,   462,   462,
     462,   462,   462,   462,   462,   462,   462,   462,   462,   462,
     462,   462,   462,   462,   462,   462,   462,   462,   462,   462,
     462,   462,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   490,   491,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   505,   504,   506,   506,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   509,   508,   510,   510,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   512,   513,   514,   515,
     516,   517,   517,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   533,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543
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
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4
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
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2923 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2941 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2959 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2971 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2977 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2995 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 440 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 3004 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 3013 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 482 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_certificate_file);
    ConfigServerInfo.ssl_certificate_file = xstrdup(yylval.string);
  }
}
#line 3025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 491 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 3037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 500 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_param_file);
    ConfigServerInfo.ssl_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3049 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 509 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_cipher_list);
    ConfigServerInfo.ssl_cipher_list = xstrdup(yylval.string);
  }
}
#line 3061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 518 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_message_digest_algorithm);
    ConfigServerInfo.ssl_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 527 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_elliptic_curve);
    ConfigServerInfo.ssl_dh_elliptic_curve = xstrdup(yylval.string);
  }
}
#line 3085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 536 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options = 0;
}
#line 3094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 543 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_STANDARD;
#endif
}
#line 3105 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 549 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MEMORY_CACHE;
#endif
}
#line 3116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 555 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MMAP_CACHE;
#endif
}
#line 3127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 561 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_CHECK_CACHE;
#endif
}
#line 3138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 569 "conf_parser.y" /* yacc.c:1646  */
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
#line 3156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 584 "conf_parser.y" /* yacc.c:1646  */
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
#line 3174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 599 "conf_parser.y" /* yacc.c:1646  */
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
#line 3192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 614 "conf_parser.y" /* yacc.c:1646  */
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
#line 3210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 629 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 639 "conf_parser.y" /* yacc.c:1646  */
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
#line 3240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 653 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3252 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 662 "conf_parser.y" /* yacc.c:1646  */
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
#line 3283 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 690 "conf_parser.y" /* yacc.c:1646  */
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
#line 3314 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 718 "conf_parser.y" /* yacc.c:1646  */
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
#line 3342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 743 "conf_parser.y" /* yacc.c:1646  */
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
#line 3367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 765 "conf_parser.y" /* yacc.c:1646  */
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
#line 3392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 787 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 805 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 814 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 823 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 836 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 840 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 857 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 863 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 873 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3490 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 877 "conf_parser.y" /* yacc.c:1646  */
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
#line 3508 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 895 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 901 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3526 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 907 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3535 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 913 "conf_parser.y" /* yacc.c:1646  */
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
#line 3556 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 941 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 951 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3587 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 967 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 975 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 978 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3614 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 983 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3623 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 990 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3632 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 994 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3641 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 998 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3650 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1002 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1006 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3668 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1010 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3677 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3686 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1018 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3695 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3707 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1035 "conf_parser.y" /* yacc.c:1646  */
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
#line 3764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1102 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1108 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1114 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1120 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1126 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1137 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1154 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1160 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1167 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1171 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1175 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1179 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1183 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1187 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1195 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1199 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1203 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1207 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1211 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1215 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1219 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1223 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1227 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1231 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1235 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1239 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1247 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1251 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1257 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1264 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4107 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1300 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1312 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4179 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1316 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1328 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4215 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4233 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4242 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1344 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4251 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1348 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4260 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1352 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1356 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1360 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4287 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1364 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1368 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4305 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1372 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4314 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1376 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4323 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1386 "conf_parser.y" /* yacc.c:1646  */
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
#line 4340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1398 "conf_parser.y" /* yacc.c:1646  */
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
#line 4387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1461 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1467 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1473 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1479 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1485 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1491 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1497 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1503 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1509 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1515 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1522 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1528 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1534 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1540 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1549 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1558 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4538 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1565 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1569 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4556 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1579 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1585 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1591 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1595 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4591 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1599 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4600 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1607 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1612 "conf_parser.y" /* yacc.c:1646  */
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
#line 4624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1625 "conf_parser.y" /* yacc.c:1646  */
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
#line 4644 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1642 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4653 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1648 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4662 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1658 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4671 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1662 "conf_parser.y" /* yacc.c:1646  */
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
#line 4716 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1715 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4725 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1721 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4734 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1727 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4743 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1733 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1744 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4766 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1751 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1755 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1759 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1763 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1767 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4811 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1771 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4820 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1775 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4829 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1779 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1783 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1787 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1793 "conf_parser.y" /* yacc.c:1646  */
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
#line 4873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1807 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1816 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1829 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1836 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1847 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1853 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1874 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1890 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1901 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1916 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1922 "conf_parser.y" /* yacc.c:1646  */
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
#line 5024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1941 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5033 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1948 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5042 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1952 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5051 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1956 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5060 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1960 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1964 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1972 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1976 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5105 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1980 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5114 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1984 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5123 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1994 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2003 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2016 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2022 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 404:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2061 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2065 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2075 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2084 "conf_parser.y" /* yacc.c:1646  */
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
#line 5338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2164 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5347 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2170 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2176 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2182 "conf_parser.y" /* yacc.c:1646  */
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
#line 5381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2195 "conf_parser.y" /* yacc.c:1646  */
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
#line 5397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2208 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2214 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2224 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2230 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2246 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2257 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2275 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2290 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2294 "conf_parser.y" /* yacc.c:1646  */
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
#line 5548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2319 "conf_parser.y" /* yacc.c:1646  */
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
#line 5571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2339 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5580 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2349 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2353 "conf_parser.y" /* yacc.c:1646  */
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
#line 5615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2379 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2385 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 472:
#line 2400 "conf_parser.y" /* yacc.c:1646  */
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
#line 5650 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 473:
#line 2417 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 474:
#line 2421 "conf_parser.y" /* yacc.c:1646  */
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
#line 5679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 480:
#line 2441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5688 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 481:
#line 2447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2510 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2515 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5713 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2520 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2525 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5729 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2530 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5738 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2536 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5746 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2541 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5754 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2546 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2551 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5770 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2556 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5778 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2561 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2566 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2571 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2576 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2581 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2586 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5826 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2591 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5834 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2596 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5842 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2601 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2606 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2612 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2617 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2622 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2627 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2632 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2637 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2642 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5923 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2650 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2655 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2658 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2663 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2668 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2673 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5971 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2678 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5979 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2683 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5987 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2688 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5995 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2693 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 6003 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2698 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6011 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2703 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6019 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2708 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6027 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2713 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2718 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2723 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6051 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2729 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6059 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2732 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6067 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2735 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2738 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2741 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6091 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2744 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2747 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6107 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2750 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2753 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6123 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2756 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6131 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2759 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6139 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2765 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6155 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2768 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6163 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2771 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6171 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2774 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6179 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6187 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2783 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6203 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6211 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2789 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6227 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2797 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6235 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2803 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6243 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2806 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6251 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2809 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6259 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2812 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6267 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2815 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6275 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2818 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6283 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2821 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6291 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2824 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6299 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2827 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6307 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2830 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6315 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2833 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6323 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2836 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6331 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 618:
#line 2839 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6339 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 619:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6347 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 620:
#line 2845 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6355 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 621:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6363 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 622:
#line 2851 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6371 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 623:
#line 2854 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2860 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6395 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2865 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6403 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2870 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6411 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6419 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2880 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 2907 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2912 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2917 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2922 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2927 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6467 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2932 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6475 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 2937 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 2942 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 2947 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6499 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 2952 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 2957 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 2962 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 2967 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 673:
#line 2990 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6540 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 674:
#line 2996 "conf_parser.y" /* yacc.c:1646  */
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
#line 6559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 675:
#line 3012 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 676:
#line 3021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6580 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 677:
#line 3027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 678:
#line 3033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 679:
#line 3039 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6610 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 680:
#line 3048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 681:
#line 3054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6628 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6632 "conf_parser.c" /* yacc.c:1646  */
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
