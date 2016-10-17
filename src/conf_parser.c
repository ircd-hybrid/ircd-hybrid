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
    INVITE_EXPIRE_TIME = 319,
    IP = 320,
    IRCD_AUTH = 321,
    IRCD_FLAGS = 322,
    IRCD_SID = 323,
    JOIN = 324,
    KILL = 325,
    KILL_CHASE_TIME_LIMIT = 326,
    KLINE = 327,
    KLINE_EXEMPT = 328,
    KLINE_MIN_CIDR = 329,
    KLINE_MIN_CIDR6 = 330,
    KNOCK_CLIENT_COUNT = 331,
    KNOCK_CLIENT_TIME = 332,
    KNOCK_DELAY_CHANNEL = 333,
    LEAF_MASK = 334,
    LIBGEOIP_DATABASE_OPTIONS = 335,
    LIBGEOIP_IPV4_DATABASE_FILE = 336,
    LIBGEOIP_IPV6_DATABASE_FILE = 337,
    LISTEN = 338,
    MASK = 339,
    MAX_ACCEPT = 340,
    MAX_BANS = 341,
    MAX_CHANNELS = 342,
    MAX_GLOBAL = 343,
    MAX_IDLE = 344,
    MAX_INVITES = 345,
    MAX_LOCAL = 346,
    MAX_NICK_CHANGES = 347,
    MAX_NICK_LENGTH = 348,
    MAX_NICK_TIME = 349,
    MAX_NUMBER = 350,
    MAX_TARGETS = 351,
    MAX_TOPIC_LENGTH = 352,
    MAX_WATCH = 353,
    MEMORY_CACHE = 354,
    MIN_IDLE = 355,
    MIN_NONWILDCARD = 356,
    MIN_NONWILDCARD_SIMPLE = 357,
    MMAP_CACHE = 358,
    MODULE = 359,
    MODULES = 360,
    MOTD = 361,
    NAME = 362,
    NEED_IDENT = 363,
    NEED_PASSWORD = 364,
    NETWORK_DESC = 365,
    NETWORK_NAME = 366,
    NICK = 367,
    NO_OPER_FLOOD = 368,
    NO_TILDE = 369,
    NUMBER = 370,
    NUMBER_PER_CIDR = 371,
    NUMBER_PER_IP = 372,
    OPER_ONLY_UMODES = 373,
    OPER_UMODES = 374,
    OPERATOR = 375,
    OPERS_BYPASS_CALLERID = 376,
    PACE_WAIT = 377,
    PACE_WAIT_SIMPLE = 378,
    PASSWORD = 379,
    PATH = 380,
    PING_COOKIE = 381,
    PING_TIME = 382,
    PORT = 383,
    QSTRING = 384,
    RANDOM_IDLE = 385,
    REASON = 386,
    REDIRPORT = 387,
    REDIRSERV = 388,
    REHASH = 389,
    REMOTE = 390,
    REMOTEBAN = 391,
    RESV = 392,
    RESV_EXEMPT = 393,
    RSA_PRIVATE_KEY_FILE = 394,
    SECONDS = 395,
    MINUTES = 396,
    HOURS = 397,
    DAYS = 398,
    WEEKS = 399,
    MONTHS = 400,
    YEARS = 401,
    SEND_PASSWORD = 402,
    SENDQ = 403,
    SERVERHIDE = 404,
    SERVERINFO = 405,
    SHORT_MOTD = 406,
    SPOOF = 407,
    SPOOF_NOTICE = 408,
    SQUIT = 409,
    SSL_CERTIFICATE_FILE = 410,
    SSL_CERTIFICATE_FINGERPRINT = 411,
    SSL_CONNECTION_REQUIRED = 412,
    SSL_DH_ELLIPTIC_CURVE = 413,
    SSL_DH_PARAM_FILE = 414,
    SSL_MESSAGE_DIGEST_ALGORITHM = 415,
    STANDARD = 416,
    STATS_E_DISABLED = 417,
    STATS_I_OPER_ONLY = 418,
    STATS_K_OPER_ONLY = 419,
    STATS_M_OPER_ONLY = 420,
    STATS_O_OPER_ONLY = 421,
    STATS_P_OPER_ONLY = 422,
    STATS_U_OPER_ONLY = 423,
    T_ALL = 424,
    T_BOTS = 425,
    T_CALLERID = 426,
    T_CCONN = 427,
    T_COMMAND = 428,
    T_CLUSTER = 429,
    T_DEAF = 430,
    T_DEBUG = 431,
    T_DLINE = 432,
    T_EXTERNAL = 433,
    T_FARCONNECT = 434,
    T_FILE = 435,
    T_FULL = 436,
    T_GLOBOPS = 437,
    T_INVISIBLE = 438,
    T_IPV4 = 439,
    T_IPV6 = 440,
    T_LOCOPS = 441,
    T_LOG = 442,
    T_NCHANGE = 443,
    T_NONONREG = 444,
    T_OPME = 445,
    T_PREPEND = 446,
    T_PSEUDO = 447,
    T_RECVQ = 448,
    T_REJ = 449,
    T_RESTART = 450,
    T_SERVER = 451,
    T_SERVICE = 452,
    T_SERVNOTICE = 453,
    T_SET = 454,
    T_SHARED = 455,
    T_SIZE = 456,
    T_SKILL = 457,
    T_SOFTCALLERID = 458,
    T_SPY = 459,
    T_SSL = 460,
    T_SSL_CIPHER_LIST = 461,
    T_TARGET = 462,
    T_UMODES = 463,
    T_UNAUTH = 464,
    T_UNDLINE = 465,
    T_UNLIMITED = 466,
    T_UNRESV = 467,
    T_UNXLINE = 468,
    T_WALLOP = 469,
    T_WALLOPS = 470,
    T_WEBIRC = 471,
    TBOOL = 472,
    THROTTLE_COUNT = 473,
    THROTTLE_TIME = 474,
    TKLINE_EXPIRE_NOTICES = 475,
    TMASKED = 476,
    TS_MAX_DELTA = 477,
    TS_WARN_DELTA = 478,
    TWODOTS = 479,
    TYPE = 480,
    UNKLINE = 481,
    USE_LOGGING = 482,
    USER = 483,
    VHOST = 484,
    VHOST6 = 485,
    WARN_NO_CONNECT_BLOCK = 486,
    WHOIS = 487,
    WHOWAS_HISTORY_LENGTH = 488,
    XLINE = 489,
    XLINE_EXEMPT = 490
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
#define INVITE_EXPIRE_TIME 319
#define IP 320
#define IRCD_AUTH 321
#define IRCD_FLAGS 322
#define IRCD_SID 323
#define JOIN 324
#define KILL 325
#define KILL_CHASE_TIME_LIMIT 326
#define KLINE 327
#define KLINE_EXEMPT 328
#define KLINE_MIN_CIDR 329
#define KLINE_MIN_CIDR6 330
#define KNOCK_CLIENT_COUNT 331
#define KNOCK_CLIENT_TIME 332
#define KNOCK_DELAY_CHANNEL 333
#define LEAF_MASK 334
#define LIBGEOIP_DATABASE_OPTIONS 335
#define LIBGEOIP_IPV4_DATABASE_FILE 336
#define LIBGEOIP_IPV6_DATABASE_FILE 337
#define LISTEN 338
#define MASK 339
#define MAX_ACCEPT 340
#define MAX_BANS 341
#define MAX_CHANNELS 342
#define MAX_GLOBAL 343
#define MAX_IDLE 344
#define MAX_INVITES 345
#define MAX_LOCAL 346
#define MAX_NICK_CHANGES 347
#define MAX_NICK_LENGTH 348
#define MAX_NICK_TIME 349
#define MAX_NUMBER 350
#define MAX_TARGETS 351
#define MAX_TOPIC_LENGTH 352
#define MAX_WATCH 353
#define MEMORY_CACHE 354
#define MIN_IDLE 355
#define MIN_NONWILDCARD 356
#define MIN_NONWILDCARD_SIMPLE 357
#define MMAP_CACHE 358
#define MODULE 359
#define MODULES 360
#define MOTD 361
#define NAME 362
#define NEED_IDENT 363
#define NEED_PASSWORD 364
#define NETWORK_DESC 365
#define NETWORK_NAME 366
#define NICK 367
#define NO_OPER_FLOOD 368
#define NO_TILDE 369
#define NUMBER 370
#define NUMBER_PER_CIDR 371
#define NUMBER_PER_IP 372
#define OPER_ONLY_UMODES 373
#define OPER_UMODES 374
#define OPERATOR 375
#define OPERS_BYPASS_CALLERID 376
#define PACE_WAIT 377
#define PACE_WAIT_SIMPLE 378
#define PASSWORD 379
#define PATH 380
#define PING_COOKIE 381
#define PING_TIME 382
#define PORT 383
#define QSTRING 384
#define RANDOM_IDLE 385
#define REASON 386
#define REDIRPORT 387
#define REDIRSERV 388
#define REHASH 389
#define REMOTE 390
#define REMOTEBAN 391
#define RESV 392
#define RESV_EXEMPT 393
#define RSA_PRIVATE_KEY_FILE 394
#define SECONDS 395
#define MINUTES 396
#define HOURS 397
#define DAYS 398
#define WEEKS 399
#define MONTHS 400
#define YEARS 401
#define SEND_PASSWORD 402
#define SENDQ 403
#define SERVERHIDE 404
#define SERVERINFO 405
#define SHORT_MOTD 406
#define SPOOF 407
#define SPOOF_NOTICE 408
#define SQUIT 409
#define SSL_CERTIFICATE_FILE 410
#define SSL_CERTIFICATE_FINGERPRINT 411
#define SSL_CONNECTION_REQUIRED 412
#define SSL_DH_ELLIPTIC_CURVE 413
#define SSL_DH_PARAM_FILE 414
#define SSL_MESSAGE_DIGEST_ALGORITHM 415
#define STANDARD 416
#define STATS_E_DISABLED 417
#define STATS_I_OPER_ONLY 418
#define STATS_K_OPER_ONLY 419
#define STATS_M_OPER_ONLY 420
#define STATS_O_OPER_ONLY 421
#define STATS_P_OPER_ONLY 422
#define STATS_U_OPER_ONLY 423
#define T_ALL 424
#define T_BOTS 425
#define T_CALLERID 426
#define T_CCONN 427
#define T_COMMAND 428
#define T_CLUSTER 429
#define T_DEAF 430
#define T_DEBUG 431
#define T_DLINE 432
#define T_EXTERNAL 433
#define T_FARCONNECT 434
#define T_FILE 435
#define T_FULL 436
#define T_GLOBOPS 437
#define T_INVISIBLE 438
#define T_IPV4 439
#define T_IPV6 440
#define T_LOCOPS 441
#define T_LOG 442
#define T_NCHANGE 443
#define T_NONONREG 444
#define T_OPME 445
#define T_PREPEND 446
#define T_PSEUDO 447
#define T_RECVQ 448
#define T_REJ 449
#define T_RESTART 450
#define T_SERVER 451
#define T_SERVICE 452
#define T_SERVNOTICE 453
#define T_SET 454
#define T_SHARED 455
#define T_SIZE 456
#define T_SKILL 457
#define T_SOFTCALLERID 458
#define T_SPY 459
#define T_SSL 460
#define T_SSL_CIPHER_LIST 461
#define T_TARGET 462
#define T_UMODES 463
#define T_UNAUTH 464
#define T_UNDLINE 465
#define T_UNLIMITED 466
#define T_UNRESV 467
#define T_UNXLINE 468
#define T_WALLOP 469
#define T_WALLOPS 470
#define T_WEBIRC 471
#define TBOOL 472
#define THROTTLE_COUNT 473
#define THROTTLE_TIME 474
#define TKLINE_EXPIRE_NOTICES 475
#define TMASKED 476
#define TS_MAX_DELTA 477
#define TS_WARN_DELTA 478
#define TWODOTS 479
#define TYPE 480
#define UNKLINE 481
#define USE_LOGGING 482
#define USER 483
#define VHOST 484
#define VHOST6 485
#define WARN_NO_CONNECT_BLOCK 486
#define WHOIS 487
#define WHOWAS_HISTORY_LENGTH 488
#define XLINE 489
#define XLINE_EXEMPT 490

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 141 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 694 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 711 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1363

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  242
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  300
/* YYNRULES -- Number of rules.  */
#define YYNRULES  679
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1337

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   490

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
       2,     2,     2,     2,   240,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   241,   236,
       2,   239,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   238,     2,   237,     2,     2,     2,     2,
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
     235
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
    1350,  1354,  1358,  1362,  1366,  1370,  1374,  1385,  1384,  1440,
    1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,
    1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1459,  1465,
    1471,  1477,  1483,  1489,  1495,  1501,  1507,  1513,  1520,  1526,
    1532,  1538,  1547,  1557,  1556,  1562,  1562,  1563,  1567,  1578,
    1577,  1584,  1583,  1588,  1588,  1589,  1593,  1597,  1603,  1603,
    1604,  1604,  1604,  1604,  1604,  1606,  1606,  1608,  1608,  1610,
    1623,  1640,  1646,  1657,  1656,  1702,  1702,  1703,  1704,  1705,
    1706,  1707,  1708,  1709,  1710,  1711,  1713,  1719,  1725,  1731,
    1743,  1742,  1748,  1748,  1749,  1753,  1757,  1761,  1765,  1769,
    1773,  1777,  1781,  1785,  1791,  1805,  1814,  1828,  1827,  1842,
    1842,  1843,  1843,  1843,  1843,  1845,  1851,  1857,  1867,  1869,
    1869,  1870,  1870,  1872,  1889,  1888,  1911,  1911,  1912,  1912,
    1912,  1912,  1914,  1920,  1940,  1939,  1945,  1945,  1946,  1950,
    1954,  1958,  1962,  1966,  1970,  1974,  1978,  1982,  1993,  1992,
    2011,  2011,  2012,  2012,  2012,  2014,  2021,  2020,  2026,  2026,
    2027,  2031,  2035,  2039,  2043,  2047,  2051,  2055,  2059,  2063,
    2074,  2073,  2145,  2145,  2146,  2147,  2148,  2149,  2150,  2151,
    2152,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,  2162,
    2168,  2174,  2180,  2193,  2206,  2212,  2218,  2222,  2229,  2228,
    2233,  2233,  2234,  2238,  2244,  2255,  2261,  2267,  2273,  2289,
    2288,  2314,  2314,  2315,  2315,  2315,  2317,  2337,  2348,  2347,
    2374,  2374,  2375,  2375,  2375,  2377,  2383,  2393,  2395,  2395,
    2396,  2396,  2398,  2416,  2415,  2436,  2436,  2437,  2437,  2437,
    2439,  2445,  2455,  2457,  2457,  2458,  2459,  2460,  2461,  2462,
    2463,  2464,  2465,  2466,  2467,  2468,  2469,  2470,  2471,  2472,
    2473,  2474,  2475,  2476,  2477,  2478,  2479,  2480,  2481,  2482,
    2483,  2484,  2485,  2486,  2487,  2488,  2489,  2490,  2491,  2492,
    2493,  2494,  2495,  2496,  2497,  2498,  2499,  2500,  2501,  2502,
    2503,  2504,  2507,  2512,  2517,  2522,  2527,  2533,  2538,  2543,
    2548,  2553,  2558,  2563,  2568,  2573,  2578,  2583,  2588,  2593,
    2598,  2603,  2609,  2614,  2619,  2624,  2629,  2634,  2639,  2644,
    2647,  2652,  2655,  2660,  2665,  2670,  2675,  2680,  2685,  2690,
    2695,  2700,  2705,  2710,  2715,  2721,  2720,  2725,  2725,  2726,
    2729,  2732,  2735,  2738,  2741,  2744,  2747,  2750,  2753,  2756,
    2759,  2762,  2765,  2768,  2771,  2774,  2777,  2780,  2783,  2786,
    2789,  2795,  2794,  2799,  2799,  2800,  2803,  2806,  2809,  2812,
    2815,  2818,  2821,  2824,  2827,  2830,  2833,  2836,  2839,  2842,
    2845,  2848,  2851,  2854,  2857,  2862,  2867,  2872,  2881,  2883,
    2883,  2884,  2885,  2886,  2887,  2888,  2889,  2890,  2891,  2892,
    2893,  2894,  2895,  2896,  2897,  2899,  2904,  2909,  2914,  2919,
    2924,  2929,  2934,  2939,  2944,  2949,  2954,  2959,  2968,  2970,
    2970,  2971,  2972,  2973,  2974,  2975,  2976,  2977,  2978,  2979,
    2980,  2982,  2988,  3004,  3013,  3019,  3025,  3031,  3040,  3046
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
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_invite_delay_channel",
  "channel_invite_expire_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_channels", "channel_max_invites", "channel_max_bans",
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
     485,   486,   487,   488,   489,   490,    59,   125,   123,    61,
      44,    58
};
# endif

#define YYPACT_NINF -1059

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1059)))

#define YYTABLE_NINF -143

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1059,   706, -1059,  -155,  -222,  -216, -1059, -1059, -1059,  -214,
   -1059,  -208, -1059, -1059, -1059,  -205, -1059, -1059, -1059,  -199,
    -189, -1059,  -184, -1059,  -182, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,   309,   978,  -179,  -176,  -148,    14,  -131,   405,  -124,
    -123,  -115,    36,  -106,  -105,   -90,   560,   561,   -87,     2,
     -75,    13,   -67,   -56,   -53,   -34,   -27,    12, -1059, -1059,
   -1059, -1059, -1059,   -19,    39,    52,    54,    62,    79,    93,
     101,   117,   121,   123,   124,   126,   161, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,   741,   577,    27, -1059,   131,    31, -1059, -1059,    96,
   -1059,   132,   133,   136,   137,   138,   139,   140,   142,   146,
     147,   149,   150,   155,   156,   158,   168,   169,   171,   178,
     181,   182,   184,   189,   192,   193, -1059, -1059,   194,   196,
     197,   199,   204,   206,   207,   209,   210,   221,   222,   223,
     224,   228,   238,   239,   242,   243,   244,    51, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059,   360,    37,   357,   -44,   247,
     250,    40, -1059, -1059, -1059,    10,   302,    28, -1059,   252,
     256,   259,   263,   270,   272,   274,   276,   277,   251, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,     5,
     280,   281,   282,   283, -1059,   286,   290,   293,   297,   298,
     299,   300,   301,   303,   306,   307,   308,   310,   311,   312,
     153, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059,   104,    99,   319,    16, -1059, -1059, -1059,   106,
     227, -1059,   320,    77, -1059, -1059,   100, -1059,   130,   214,
     275,   203, -1059,   175,   253,   249,   381,   253,   253,   253,
     433,   253,   253,   445,   448,   449,   330, -1059,   338,   336,
     337,   342, -1059,   345,   346,   347,   351,   353,   354,   359,
     362,   363,   368,   371,   372,   257, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059,   341,   382,   383,   387,   391,   392,   393,
   -1059,   395,   406,   407,   410,   411,   412,   413,    50, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059,   416,   418,     3, -1059, -1059,
   -1059,   467,   423, -1059, -1059,   422,   424,    24, -1059, -1059,
   -1059,   447,   253,   484,   253,   253,   450,   547,   453,   551,
     559,   564,   458,   459,   464,   253,   565,   568,   570,   571,
     253,   572,   573,   574,   575,   477,   460,   462,   485,   253,
     253,   486,   487,   491,  -194,  -177,   494,   495,   497,   498,
     603,   253,   506,   253,   253,   508,   612,   493, -1059,   496,
     492,   499, -1059,   500,   501,   502,   504,   505,   165, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,   507,
     509,    44, -1059, -1059, -1059,   513,   511,   512, -1059,   515,
   -1059,     7, -1059, -1059, -1059, -1059, -1059,   601,   605,   520,
   -1059,   521,   519,   522,    20, -1059, -1059, -1059,   526,   524,
     527, -1059,   529,   530,   531,   532, -1059,   534,   536,   159,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,   545,   543,   546,   548,    25, -1059, -1059, -1059, -1059,
     528,   567,   253,   607,   569,   608,   576,   578,   579,   552,
   -1059, -1059,   650,   663,   580,   665,   562,   669,   670,   685,
     687,   674,   675,   676,   678,   680,   684,   686,   692,   693,
     694,   695,   589, -1059,   595,   594, -1059,    84, -1059, -1059,
   -1059, -1059,   597,   598, -1059,   154,   599,   600,   606,   610,
     611,   129, -1059, -1059, -1059, -1059, -1059,   708,   602, -1059,
     604,   613, -1059,   620,    17, -1059, -1059, -1059, -1059,   624,
     625,   627, -1059,   628,   329,   629,   630,   633,   634,   635,
     636,   637,   638,   640,   642,   643,   645, -1059, -1059,   701,
     727,   253,   644,   731,   732,   253,   762,   767,   253,   715,
     770,   771,   253,   772,   772,   648, -1059, -1059,   759,   -86,
     761,   677,   763,   766,   652,   768,   773,   781,   780,   782,
     784,   785,   683, -1059,   787,   791,   688, -1059,   689, -1059,
     792,   793,   690, -1059,   699,   700,   710,   713,   717,   718,
     720,   723,   724,   725,   726,   728,   730,   733,   734,   738,
     739,   740,   744,   745,   746,   751,   752,   755,   758,   814,
     729,   760,   765,   774,   777,   778,   779,   783,   786,   788,
     789,   790,   794,   795,   796,   797,   798,   799,   800,   801,
     802,   807, -1059, -1059,   808,   711,   691,   813,   836,   839,
     848,   869,   809, -1059,   870,   877,   810, -1059, -1059,   878,
     880,   805,   850,   811, -1059,   812,   815, -1059, -1059,   891,
     892,   816, -1059, -1059,   898,   712,   818,   900,   920,   921,
     841,   820,   924,   931,   825, -1059, -1059,   933,   934,   937,
     831, -1059,   833,   834,   835,   837,   838,   840,   842,   843,
     844, -1059,   845,   846,   847,   849,    47,   851,   852,   853,
     854,   855,   856,   857,   858,   859,   860,   861,   862,   863,
     864,   865, -1059, -1059,   943,   866,   867, -1059,   868, -1059,
     200, -1059,   946,   948,   955,   957,   871, -1059,   872, -1059,
   -1059,   973,   873,   977,   874, -1059, -1059, -1059, -1059, -1059,
     253,   253,   253,   253,   253,   253,   253, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,   875,   879,   881,    -9,   882,   883,   884,   885,   886,
     887,   888,   889,   890,   893,    23,   894,   895, -1059,   896,
     897,   899,   901,   902,   903,   904,     4,   905,   906,   907,
     908,   909,   910,   911, -1059,   912,   913, -1059, -1059,   914,
     915, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059,  -169, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,  -163, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,   916,   917,   539,   918,   919,   922,
     923,   925, -1059,   926,   927, -1059,   928,   929,   -29,   932,
     876, -1059, -1059, -1059, -1059,   930,   935, -1059,   936,   938,
     483,   939,   940,   941,   942,   769,   944,   945, -1059,   947,
     949,   950, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
    -156, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059,   951,   331, -1059,
   -1059,   952,   953,   954, -1059,    30, -1059, -1059, -1059, -1059,
     958,   959,   960,   961, -1059, -1059,   962,   641,   963, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059,  -145, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,   772,   772,   772, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
     -47, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,   814, -1059,   729, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,   -41,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059,    91, -1059,   994,   850,   964, -1059, -1059,
   -1059, -1059, -1059, -1059,   965, -1059,   966,   967, -1059, -1059,
     968,   969, -1059, -1059,   970, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059,    97, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059,   102, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059,    47, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059,   113, -1059, -1059,   984,   -95,
     974,   976, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,   114, -1059,
   -1059, -1059,    -9, -1059, -1059, -1059, -1059,     4, -1059, -1059,
   -1059,   539, -1059,   -29, -1059, -1059, -1059,   979,   990,   993,
     997,  1001,  1022, -1059,   483, -1059,   769, -1059, -1059,   331,
     980,   981,   982,   463, -1059, -1059,   641, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,   115, -1059, -1059, -1059,   463, -1059
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
     108,   107,   644,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,   643,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   631,   641,
     642,     0,     0,     0,   471,     0,     0,   469,   470,     0,
     531,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   601,   575,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   484,   485,
     486,   529,   493,   530,   524,   525,   526,   527,   523,   497,
     487,   488,   489,   490,   491,   492,   494,   495,   496,   498,
     499,   528,   503,   504,   505,   506,   502,   501,   507,   514,
     515,   508,   509,   510,   500,   512,   521,   522,   519,   520,
     513,   511,   517,   518,   516,     0,     0,     0,     0,     0,
       0,     0,    46,    47,    48,     0,     0,     0,   670,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   660,
     661,   662,   663,   664,   665,   666,   668,   667,   669,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    69,    66,    64,    70,    71,    65,    72,    73,
      74,    55,    68,    58,    59,    60,    56,    67,    61,    62,
      63,    57,     0,     0,     0,     0,   137,   138,   139,     0,
       0,   362,     0,     0,   360,   361,     0,   109,     0,     0,
       0,     0,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   629,     0,     0,
       0,     0,   283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   250,   251,   254,   256,
     257,   258,   259,   260,   261,   262,   263,   252,   253,   255,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
     438,     0,     0,     0,     0,     0,     0,     0,     0,   413,
     414,   415,   416,   417,   418,   419,   421,   420,   423,   427,
     424,   425,   426,   422,   464,     0,     0,     0,   461,   462,
     463,     0,     0,   468,   479,     0,     0,     0,   476,   477,
     478,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   483,     0,
       0,     0,   330,     0,     0,     0,     0,     0,     0,   316,
     317,   318,   319,   324,   320,   321,   322,   323,   455,     0,
       0,     0,   452,   453,   454,     0,     0,     0,   291,     0,
     301,     0,   299,   300,   302,   303,    49,     0,     0,     0,
      45,     0,     0,     0,     0,   116,   117,   118,     0,     0,
       0,   214,     0,     0,     0,     0,   188,     0,     0,     0,
     168,   169,   170,   171,   172,   175,   176,   177,   174,   173,
     178,     0,     0,     0,     0,     0,   350,   351,   352,   353,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     659,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,   396,     0,   391,   392,
     393,   140,     0,     0,   136,     0,     0,     0,     0,     0,
       0,     0,   125,   126,   128,   127,   129,     0,     0,   359,
       0,     0,   374,     0,     0,   367,   368,   369,   370,     0,
       0,     0,   103,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   628,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   249,   428,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   412,     0,     0,     0,   460,     0,   467,
       0,     0,     0,   475,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,   325,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   315,     0,     0,     0,   451,   304,     0,
       0,     0,     0,     0,   298,     0,     0,    44,   119,     0,
       0,     0,   115,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   354,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   658,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,   394,     0,     0,     0,   390,     0,   135,
       0,   130,     0,     0,     0,     0,     0,   124,     0,   358,
     371,     0,     0,     0,     0,   366,   112,   111,   110,   656,
      28,    28,    28,    28,    28,    28,    28,    30,    29,   657,
     645,   646,   647,   648,   649,   650,   651,   652,   655,   653,
     654,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,   248,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   411,     0,     0,   459,   472,     0,
       0,   474,   545,   549,   532,   533,   564,   536,   627,   572,
     537,   538,   569,   544,   543,   552,   542,   539,   540,   548,
     547,   546,   570,   534,   625,   626,   568,   611,   605,   621,
     606,   607,   608,   616,   624,   609,   618,   622,   612,   623,
     613,   617,   610,   620,   615,   614,   619,     0,   604,   584,
     585,   586,   579,   597,   580,   581,   582,   592,   600,   583,
     594,   598,   588,   599,   589,   593,   587,   596,   591,   590,
     595,     0,   578,   565,   563,   566,   571,   567,   554,   561,
     562,   559,   560,   555,   556,   557,   558,   573,   574,   541,
     551,   550,   553,   535,     0,     0,     0,     0,     0,     0,
       0,     0,   314,     0,     0,   450,     0,     0,     0,   309,
     305,   308,   290,    50,    51,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
       0,     0,   348,   674,   671,   672,   673,   678,   677,   679,
     675,   676,    99,    94,   102,    93,    89,    87,    88,    86,
       0,    85,    90,    91,   100,   101,    92,    96,    95,    77,
      76,    81,    78,    80,    79,    97,    98,     0,     0,   389,
     141,     0,     0,     0,   153,     0,   145,   146,   148,   147,
       0,     0,     0,     0,   123,   363,     0,     0,     0,   365,
      31,    32,    33,    34,    35,    36,    37,   278,   279,   271,
     288,   287,     0,   286,   272,   274,   282,   275,   273,   281,
     268,   280,   270,   269,    38,    38,    38,    40,    39,   276,
     277,   433,   436,   437,   447,   444,   430,   445,   442,   443,
       0,   441,   446,   429,   435,   432,   434,   448,   431,   465,
     466,   480,   481,   602,     0,   576,     0,   328,   329,   339,
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
     373,   284,     0,    41,    42,    43,   439,     0,   603,   577,
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
   -1059, -1059, -1059,  -379,  -312, -1058,  -643, -1059, -1059,   983,
   -1059, -1059, -1059, -1059,   956, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,   -73, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
    1090, -1059, -1059, -1059, -1059, -1059, -1059,   664, -1059, -1059,
   -1059, -1059, -1059,   582, -1059, -1059, -1059, -1059, -1059, -1059,
     971, -1059, -1059, -1059, -1059,   105, -1059, -1059, -1059, -1059,
   -1059,  -166, -1059, -1059, -1059,   660, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059,  -114, -1059, -1059,
   -1059,  -110, -1059, -1059, -1059,   972, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,   -83, -1059, -1059, -1059, -1059, -1059,
     -93, -1059,   714, -1059, -1059, -1059,    35, -1059, -1059, -1059,
   -1059, -1059,   735, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
     -79, -1059, -1059, -1059, -1059, -1059, -1059,   656, -1059, -1059,
   -1059, -1059, -1059,   975, -1059, -1059, -1059, -1059,   615, -1059,
   -1059, -1059, -1059, -1059,   -92, -1059, -1059, -1059,   646, -1059,
   -1059, -1059, -1059,   -84, -1059, -1059, -1059,   985, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,   -57,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,   743, -1059,
   -1059, -1059, -1059, -1059,   824, -1059, -1059, -1059, -1059,  1106,
   -1059, -1059, -1059, -1059,   821, -1059, -1059, -1059, -1059,  1058,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,    94, -1059, -1059, -1059,    95, -1059,
   -1059, -1059, -1059, -1059,  1131, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
     995, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   837,   838,  1107,  1108,    27,   221,   222,
     223,   224,    28,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   556,  1040,  1041,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,    29,    77,
      78,    79,    80,    81,    30,    63,   504,   505,   506,   507,
      31,    70,   591,   592,   593,   594,   595,   596,    32,   295,
     296,   297,   298,   299,  1065,  1066,  1067,  1068,  1069,  1250,
    1331,  1332,    33,    64,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   761,  1225,  1226,   530,   756,
    1197,  1198,    34,    53,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   632,  1092,  1093,    35,    61,   490,   741,  1163,
    1164,   491,   492,   493,  1167,  1000,  1001,   494,   495,    36,
      59,   468,   469,   470,   471,   472,   473,   474,   726,  1149,
    1150,   475,   476,   477,    37,    65,   535,   536,   537,   538,
     539,    38,   303,   304,   305,    39,    72,   604,   605,   606,
     607,   608,   822,  1268,  1269,    40,    68,   577,   578,   579,
     580,   805,  1245,  1246,    41,    54,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   654,  1120,  1121,
     389,   390,   391,   392,   393,    42,    60,   481,   482,   483,
     484,    43,    55,   397,   398,   399,   400,    44,   116,   117,
     118,    45,    57,   407,   408,   409,   410,    46,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   437,   961,   962,   211,   436,   937,   938,   212,
     213,   214,    47,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    48,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     866,   867,   615,   293,   394,   618,   619,   620,   485,   622,
     623,   501,  1118,    73,   301,   114,    51,   293,   600,  1160,
     865,   501,    52,   707,    56,   404,   531,   708,   394,   531,
      58,  1061,   114,    62,  1104,  1105,  1106,   218,   478,    66,
     709,   218,    74,  1090,   710,   478,  1273,  1274,  1275,    67,
      75,   363,   120,   364,    69,   365,    71,   121,   122,   111,
     123,   124,   112,   486,  1036,   125,   532,  1133,   395,   532,
     366,  1134,   487,  1135,   488,   126,   127,  1136,   301,   115,
    1232,    49,    50,   128,  1233,   574,   129,   130,   131,   367,
     113,  1271,   395,   132,   502,  1272,   115,   404,   870,   871,
     675,   600,   677,   678,   502,   574,   368,   119,   369,   533,
     133,   134,   533,   688,   215,   216,  1301,   370,   693,    76,
     302,  1091,   135,   217,   601,   136,   137,   702,   703,   371,
     586,   405,   225,   226,   396,   489,   138,  1062,   865,   716,
     219,   718,   719,   139,   219,   140,  1037,   141,   227,   142,
    1038,   292,   143,   144,   249,   406,   534,   372,   396,   534,
     508,   220,    82,   300,   145,   220,   459,  1161,   479,   146,
     147,   306,   148,   149,   150,   479,  1162,   151,   373,   509,
     307,   250,  -142,   251,   302,   460,   308,    83,    84,  1276,
     503,   575,   496,  1277,    85,  1280,  -142,   374,   510,  1281,
     503,  1061,   152,   405,   461,   309,   375,   601,  1039,  1119,
     252,   575,   310,   153,   154,   155,   156,   157,   158,   159,
     313,   253,    86,    87,    88,    89,   511,   406,   586,   294,
     774,  1063,   462,   254,   255,   256,   587,    90,    91,    92,
     666,   551,   602,   294,   743,   603,   257,    93,    94,   311,
     258,    95,   228,   583,   824,  1064,   376,   751,   328,   609,
     259,   672,   770,   260,   261,   480,   512,  1251,   402,   160,
     161,   162,   480,   163,   164,   329,   330,   499,   314,   377,
     331,   736,   165,   513,   166,   229,   585,   662,   457,   463,
     613,   315,   262,   316,   230,   231,   232,   464,   465,   233,
     234,   317,   588,   508,   235,   236,   237,  1062,   263,   576,
      73,   264,   265,   266,   598,   514,   515,   466,   318,   853,
     589,   806,   509,   857,   332,   602,   860,  1282,   603,   576,
     864,  1283,   319,  1293,   587,   581,   590,  1294,  1295,    74,
     320,   510,  1296,   610,   333,   334,   335,    75,   336,  1298,
    1305,  1334,   337,  1299,  1306,  1335,   321,   338,   485,   267,
     322,   459,   323,   324,   339,   325,   816,   516,   614,   511,
     401,   411,   412,   340,   341,   413,   414,   415,   416,   417,
     460,   418,   268,   269,   342,   419,   420,   517,   421,   422,
     572,   518,   810,   467,   423,   424,   764,   425,   326,   461,
     588,  1063,   732,  1235,   611,   343,   120,   426,   427,   512,
     428,   121,   122,   486,   123,   124,    76,   429,   589,   125,
     430,   431,   487,   432,   488,  1064,   513,   462,   433,   126,
     127,   434,   435,   438,   590,   439,   440,   128,   441,   612,
     129,   130,   131,   442,   614,   443,   444,   132,   445,   446,
     344,  1080,  1081,  1082,  1083,  1084,  1085,  1086,   514,   515,
     447,   448,   449,   450,   133,   134,   616,   451,  1236,   830,
     831,   832,   833,   834,   835,   836,   135,   452,   453,   136,
     137,   454,   455,   456,   463,   489,   497,  1172,   549,   498,
     138,   540,   464,   465,   645,   541,   617,   139,   542,   140,
    1237,   141,   543,   142,  1173,  1174,   143,   144,  1238,   544,
     516,   545,   466,   546,  1175,   547,   548,  1239,   145,   552,
     553,   554,   555,   146,   147,   557,   148,   149,   150,   558,
     517,   151,   559,  1323,   518,  1324,   560,   561,   562,   563,
     564,  1240,   565,  1241,  1242,   566,   567,   568,   621,   569,
     570,   571,  1176,  1177,  1139,  1178,   152,  1243,   582,   597,
     624,   228,   249,   625,   626,  1244,   627,   153,   154,   155,
     156,   157,   158,   159,   628,   629,   630,   647,   363,  1140,
     364,   631,   365,  1325,   633,   634,   635,  1179,   467,   250,
     636,   251,   637,   638,   229,  1180,   668,   366,   639,   676,
    1326,   640,   641,   230,   231,   232,  1302,   642,   233,   234,
     643,   644,  1141,   235,   236,   237,   367,  1181,   252,  1182,
    1183,   648,   649,   160,   161,   162,   650,   163,   164,   253,
     651,   652,   653,   368,   655,   369,   165,  1184,   166,  1327,
    1328,   254,   255,   256,   370,   656,   657,  1142,  1143,   658,
     659,   660,   661,  1144,   257,   664,   371,   665,   258,   669,
    1185,   670,   680,   671,   674,  1186,   682,   679,   259,  1187,
     681,   260,   261,  1188,   683,   685,   686,  1145,  1189,   684,
     689,   687,  1190,   690,   372,   691,   692,   694,   695,   696,
     697,  1329,  1146,  1191,   698,  1192,  1193,  1330,  1194,   699,
     262,   700,   701,   704,   705,   373,     2,     3,   706,  1195,
       4,   711,   712,  1258,   713,   714,   263,  1196,   715,   264,
     265,   266,     5,   717,   374,   720,     6,   721,     7,   722,
     745,   724,   723,   375,   746,     8,   775,   777,   725,   727,
     728,   729,   328,   730,   731,   772,   734,     9,   735,   738,
     739,   740,    10,    11,   742,  1147,   747,   748,   749,   329,
     330,   750,   753,   754,   331,   782,   755,   267,   757,   758,
     759,   760,    12,   762,  1148,   763,    13,   939,  1259,   940,
     941,   766,   767,   376,   773,   768,   776,   769,   781,    14,
     268,   269,   783,   778,   785,   779,   780,   784,   787,   788,
     789,   786,   790,   791,   792,   793,   377,   794,   332,   795,
    1260,    15,    16,   796,   808,   797,   851,  1203,  1261,  1204,
    1205,   798,   799,   800,   801,   802,    17,  1262,   333,   334,
     335,   803,   336,   804,   809,   811,   337,   818,   819,   812,
     820,   338,   852,    18,   861,   813,   855,   856,   339,   814,
     815,  1263,   821,  1264,  1265,    19,    20,   340,   341,   823,
     826,   827,   917,   828,   829,   839,   840,  1266,   342,   841,
     842,   843,   844,   845,   846,  1267,   847,   858,   848,   849,
      21,   850,   859,   854,   868,   862,   863,   865,   869,   343,
     872,   876,   874,    22,   873,   875,   879,   877,    23,   942,
     943,   944,   878,    24,   945,   946,    25,   947,   948,   880,
     949,   881,   950,   882,   883,   951,   885,   952,   953,   884,
     886,   889,   890,   954,   887,   888,   891,   955,   985,  1009,
     986,   956,   957,   958,   344,   892,   893,   984,   959,  1206,
    1207,  1208,   987,   960,  1209,  1210,   894,  1211,  1212,   895,
    1213,   988,  1214,   896,   897,  1215,   898,  1216,  1217,   899,
     900,   901,   902,  1218,   903,   999,   904,  1219,   989,   905,
     906,  1220,  1221,  1222,   907,   908,   909,   990,  1223,    82,
     910,   911,   912,  1224,   918,   919,   920,   913,   914,   921,
     922,   915,   923,   924,   916,   925,   963,   926,   991,   993,
     927,   964,   928,   929,    83,    84,   994,   996,   930,   997,
     965,    85,   931,   966,   967,   968,   932,   933,   934,   969,
    1005,  1006,   970,   935,   971,   972,   973,  1008,   936,  1011,
     974,   975,   976,   977,   978,   979,   980,   981,   982,    86,
      87,    88,    89,   983,   998,   992,   995,  1002,  1003,  1012,
    1013,  1004,  1007,  1016,    90,    91,    92,  1010,  1014,  1015,
    1017,  1018,  1019,  1020,    93,    94,  1021,  1022,    95,  1023,
    1024,  1025,  1057,  1026,  1027,  1070,  1028,  1071,  1029,  1030,
    1031,  1032,  1033,  1034,  1072,  1035,  1073,  1042,  1043,  1044,
    1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,  1056,  1076,  1059,  1060,  1058,  1078,  1074,  1075,  1284,
    1079,  1087,  1077,  1300,  1311,  1088,  1166,  1089,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1312,  1313,  1103,
    1109,  1110,  1111,  1112,  1314,  1113,  1315,  1114,  1115,  1116,
    1117,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,
    1131,  1132,  1137,  1138,  1151,  1152,  1165,  1316,  1153,  1154,
    1297,  1155,  1156,  1157,  1158,  1159,  1168,   312,   752,  1336,
    1252,  1169,  1170,   817,  1171,  1199,  1200,  1201,  1202,   765,
    1227,  1228,  1318,  1229,  1317,  1230,  1231,  1234,  1247,  1307,
    1310,   771,  1248,  1249,  1253,  1254,  1255,  1256,  1257,  1270,
    1286,  1285,  1309,   733,   500,   744,  1287,  1288,  1289,  1290,
    1291,  1292,  1304,  1303,  1333,  1319,  1320,  1321,  1322,   825,
    1308,   667,   403,   807,   737,   458,   573,   327,   673,  1278,
    1279,     0,     0,   550,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   584,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   646,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   663
};

static const yytype_int16 yycheck[] =
{
     643,   644,   314,     1,     1,   317,   318,   319,     1,   321,
     322,     1,     8,     1,     1,     1,   238,     1,     1,    48,
     115,     1,   238,   217,   238,     1,     1,   221,     1,     1,
     238,     1,     1,   238,    11,    12,    13,     1,     1,   238,
     217,     1,    30,    52,   221,     1,  1104,  1105,  1106,   238,
      38,     1,     1,     3,   238,     5,   238,     6,     7,   238,
       9,    10,   238,    56,    17,    14,    41,   236,    65,    41,
      20,   240,    65,   236,    67,    24,    25,   240,     1,    65,
     236,   236,   237,    32,   240,     1,    35,    36,    37,    39,
     238,   236,    65,    42,    84,   240,    65,     1,   184,   185,
     412,     1,   414,   415,    84,     1,    56,   238,    58,    84,
      59,    60,    84,   425,   238,   238,   211,    67,   430,   107,
     107,   130,    71,   238,   107,    74,    75,   439,   440,    79,
       1,   107,   238,   238,   131,   128,    85,   107,   115,   451,
     104,   453,   454,    92,   104,    94,    99,    96,   238,    98,
     103,   238,   101,   102,     1,   131,   131,   107,   131,   131,
       1,   125,     1,   238,   113,   125,     1,   196,   131,   118,
     119,   238,   121,   122,   123,   131,   205,   126,   128,    20,
     236,    28,   180,    30,   107,    20,   239,    26,    27,   236,
     180,   107,   236,   240,    33,   236,   180,   147,    39,   240,
     180,     1,   151,   107,    39,   239,   156,   107,   161,   205,
      57,   107,   239,   162,   163,   164,   165,   166,   167,   168,
     239,    68,    61,    62,    63,    64,    67,   131,     1,   227,
     542,   201,    67,    80,    81,    82,   107,    76,    77,    78,
     237,   236,   225,   227,   237,   228,    93,    86,    87,   237,
      97,    90,     1,   237,   237,   225,   206,   237,     1,   129,
     107,   237,   237,   110,   111,   228,   107,   237,   237,   218,
     219,   220,   228,   222,   223,    18,    19,   237,   239,   229,
      23,   237,   231,   124,   233,    34,   180,   237,   237,   124,
     115,   239,   139,   239,    43,    44,    45,   132,   133,    48,
      49,   239,   173,     1,    53,    54,    55,   107,   155,   225,
       1,   158,   159,   160,   237,   156,   157,   152,   239,   631,
     191,   237,    20,   635,    67,   225,   638,   236,   228,   225,
     642,   240,   239,   236,   107,   236,   207,   240,   236,    30,
     239,    39,   240,   129,    87,    88,    89,    38,    91,   236,
     236,   236,    95,   240,   240,   240,   239,   100,     1,   206,
     239,     1,   239,   239,   107,   239,   237,   208,   115,    67,
     239,   239,   239,   116,   117,   239,   239,   239,   239,   239,
      20,   239,   229,   230,   127,   239,   239,   228,   239,   239,
     237,   232,   238,   228,   239,   239,   237,   239,   237,    39,
     173,   201,   237,    72,   129,   148,     1,   239,   239,   107,
     239,     6,     7,    56,     9,    10,   107,   239,   191,    14,
     239,   239,    65,   239,    67,   225,   124,    67,   239,    24,
      25,   239,   239,   239,   207,   239,   239,    32,   239,   236,
      35,    36,    37,   239,   115,   239,   239,    42,   239,   239,
     193,   830,   831,   832,   833,   834,   835,   836,   156,   157,
     239,   239,   239,   239,    59,    60,   217,   239,   137,   140,
     141,   142,   143,   144,   145,   146,    71,   239,   239,    74,
      75,   239,   239,   239,   124,   128,   239,     4,   237,   239,
      85,   239,   132,   133,   237,   239,   115,    92,   239,    94,
     169,    96,   239,    98,    21,    22,   101,   102,   177,   239,
     208,   239,   152,   239,    31,   239,   239,   186,   113,   239,
     239,   239,   239,   118,   119,   239,   121,   122,   123,   239,
     228,   126,   239,    70,   232,    72,   239,   239,   239,   239,
     239,   210,   239,   212,   213,   239,   239,   239,   115,   239,
     239,   239,    69,    70,    15,    72,   151,   226,   239,   239,
     115,     1,     1,   115,   115,   234,   236,   162,   163,   164,
     165,   166,   167,   168,   236,   239,   239,   236,     1,    40,
       3,   239,     5,   120,   239,   239,   239,   104,   228,    28,
     239,    30,   239,   239,    34,   112,   129,    20,   239,   115,
     137,   239,   239,    43,    44,    45,  1249,   239,    48,    49,
     239,   239,    73,    53,    54,    55,    39,   134,    57,   136,
     137,   239,   239,   218,   219,   220,   239,   222,   223,    68,
     239,   239,   239,    56,   239,    58,   231,   154,   233,   176,
     177,    80,    81,    82,    67,   239,   239,   108,   109,   239,
     239,   239,   239,   114,    93,   239,    79,   239,    97,   236,
     177,   239,   115,   239,   217,   182,   115,   217,   107,   186,
     217,   110,   111,   190,   115,   217,   217,   138,   195,   115,
     115,   217,   199,   115,   107,   115,   115,   115,   115,   115,
     115,   228,   153,   210,   217,   212,   213,   234,   215,   239,
     139,   239,   217,   217,   217,   128,     0,     1,   217,   226,
       4,   217,   217,    72,   217,   217,   155,   234,   115,   158,
     159,   160,    16,   217,   147,   217,    20,   115,    22,   236,
     129,   239,   236,   156,   129,    29,   129,   129,   239,   239,
     239,   239,     1,   239,   239,   217,   239,    41,   239,   236,
     239,   239,    46,    47,   239,   216,   236,   236,   239,    18,
      19,   239,   236,   239,    23,   115,   239,   206,   239,   239,
     239,   239,    66,   239,   235,   239,    70,    48,   137,    50,
      51,   236,   239,   206,   217,   239,   217,   239,   236,    83,
     229,   230,   129,   217,   129,   217,   217,   217,   129,   129,
     115,   239,   115,   129,   129,   129,   229,   129,    67,   129,
     169,   105,   106,   129,   217,   129,   115,    48,   177,    50,
      51,   129,   129,   129,   129,   236,   120,   186,    87,    88,
      89,   236,    91,   239,   236,   236,    95,   129,   236,   239,
     236,   100,   115,   137,   129,   239,   115,   115,   107,   239,
     239,   210,   239,   212,   213,   149,   150,   116,   117,   239,
     236,   236,    48,   236,   236,   236,   236,   226,   127,   236,
     236,   236,   236,   236,   236,   234,   236,   115,   236,   236,
     174,   236,   115,   239,   236,   115,   115,   115,   129,   148,
     129,   239,   129,   187,   217,   129,   115,   129,   192,   170,
     171,   172,   129,   197,   175,   176,   200,   178,   179,   129,
     181,   129,   183,   129,   129,   186,   129,   188,   189,   236,
     129,   129,   129,   194,   236,   236,   236,   198,   217,   217,
     239,   202,   203,   204,   193,   236,   236,   129,   209,   170,
     171,   172,   129,   214,   175,   176,   236,   178,   179,   236,
     181,   115,   183,   236,   236,   186,   236,   188,   189,   236,
     236,   236,   236,   194,   236,   115,   236,   198,   129,   236,
     236,   202,   203,   204,   236,   236,   236,   129,   209,     1,
     236,   236,   236,   214,   170,   171,   172,   236,   236,   175,
     176,   236,   178,   179,   236,   181,   236,   183,   129,   129,
     186,   236,   188,   189,    26,    27,   129,   129,   194,   129,
     236,    33,   198,   236,   236,   236,   202,   203,   204,   236,
     129,   129,   236,   209,   236,   236,   236,   129,   214,   129,
     236,   236,   236,   236,   236,   236,   236,   236,   236,    61,
      62,    63,    64,   236,   239,   236,   236,   236,   236,   129,
     129,   236,   236,   129,    76,    77,    78,   239,   217,   239,
     129,   236,   129,   129,    86,    87,   129,   236,    90,   236,
     236,   236,   129,   236,   236,   129,   236,   129,   236,   236,
     236,   236,   236,   236,   129,   236,   129,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   129,   236,   236,   239,   129,   236,   236,   115,
     236,   236,   239,   129,   135,   236,   240,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   137,   135,   236,
     236,   236,   236,   236,   137,   236,   135,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   224,   135,   236,   236,
    1233,   236,   236,   236,   236,   236,   236,    77,   504,  1335,
    1065,   236,   236,   591,   236,   236,   236,   236,   236,   519,
     236,   236,  1296,   236,  1294,   236,   236,   236,   236,  1272,
    1283,   535,   239,   239,   236,   236,   236,   236,   236,   236,
     236,  1166,  1281,   468,   221,   491,   241,   241,   241,   241,
     241,   241,   236,   239,  1306,  1299,   236,   236,   236,   604,
    1277,   397,   116,   577,   481,   167,   270,    96,   407,  1134,
    1136,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   378
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   243,     0,     1,     4,    16,    20,    22,    29,    41,
      46,    47,    66,    70,    83,   105,   106,   120,   137,   149,
     150,   174,   187,   192,   197,   200,   244,   249,   254,   280,
     286,   292,   300,   314,   334,   357,   371,   386,   393,   397,
     407,   416,   437,   443,   449,   453,   459,   514,   530,   236,
     237,   238,   238,   335,   417,   444,   238,   454,   238,   372,
     438,   358,   238,   287,   315,   387,   238,   238,   408,   238,
     293,   238,   398,     1,    30,    38,   107,   281,   282,   283,
     284,   285,     1,    26,    27,    33,    61,    62,    63,    64,
      76,    77,    78,    86,    87,    90,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   238,   238,   238,     1,    65,   450,   451,   452,   238,
       1,     6,     7,     9,    10,    14,    24,    25,    32,    35,
      36,    37,    42,    59,    60,    71,    74,    75,    85,    92,
      94,    96,    98,   101,   102,   113,   118,   119,   121,   122,
     123,   126,   151,   162,   163,   164,   165,   166,   167,   168,
     218,   219,   220,   222,   223,   231,   233,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   507,   511,   512,   513,   238,   238,   238,     1,   104,
     125,   250,   251,   252,   253,   238,   238,   238,     1,    34,
      43,    44,    45,    48,    49,    53,    54,    55,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,     1,
      28,    30,    57,    68,    80,    81,    82,    93,    97,   107,
     110,   111,   139,   155,   158,   159,   160,   206,   229,   230,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   238,     1,   227,   301,   302,   303,   304,   305,
     238,     1,   107,   394,   395,   396,   238,   236,   239,   239,
     239,   237,   282,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   237,   516,     1,    18,
      19,    23,    67,    87,    88,    89,    91,    95,   100,   107,
     116,   117,   127,   148,   193,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,     1,     3,     5,    20,    39,    56,    58,
      67,    79,   107,   128,   147,   156,   206,   229,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   432,
     433,   434,   435,   436,     1,    65,   131,   445,   446,   447,
     448,   239,   237,   451,     1,   107,   131,   455,   456,   457,
     458,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   508,   504,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   237,   461,     1,
      20,    39,    67,   124,   132,   133,   152,   228,   373,   374,
     375,   376,   377,   378,   379,   383,   384,   385,     1,   131,
     228,   439,   440,   441,   442,     1,    56,    65,    67,   128,
     359,   363,   364,   365,   369,   370,   236,   239,   239,   237,
     251,     1,    84,   180,   288,   289,   290,   291,     1,    20,
      39,    67,   107,   124,   156,   157,   208,   228,   232,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     330,     1,    41,    84,   131,   388,   389,   390,   391,   392,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   237,
     532,   236,   239,   239,   239,   239,   264,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   237,   256,     1,   107,   225,   409,   410,   411,
     412,   236,   239,   237,   302,   180,     1,   107,   173,   191,
     207,   294,   295,   296,   297,   298,   299,   239,   237,   395,
       1,   107,   225,   228,   399,   400,   401,   402,   403,   129,
     129,   129,   236,   115,   115,   246,   217,   115,   246,   246,
     246,   115,   246,   246,   115,   115,   115,   236,   236,   239,
     239,   239,   354,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   237,   337,   236,   239,   239,
     239,   239,   239,   239,   429,   239,   239,   239,   239,   239,
     239,   239,   237,   419,   239,   239,   237,   446,   129,   236,
     239,   239,   237,   456,   217,   246,   115,   246,   246,   217,
     115,   217,   115,   115,   115,   217,   217,   217,   246,   115,
     115,   115,   115,   246,   115,   115,   115,   115,   217,   239,
     239,   217,   246,   246,   217,   217,   217,   217,   221,   217,
     221,   217,   217,   217,   217,   115,   246,   217,   246,   246,
     217,   115,   236,   236,   239,   239,   380,   239,   239,   239,
     239,   239,   237,   374,   239,   239,   237,   440,   236,   239,
     239,   360,   239,   237,   364,   129,   129,   236,   236,   239,
     239,   237,   289,   236,   239,   239,   331,   239,   239,   239,
     239,   327,   239,   239,   237,   317,   236,   239,   239,   239,
     237,   389,   217,   217,   246,   129,   217,   129,   217,   217,
     217,   236,   115,   129,   217,   129,   239,   129,   129,   115,
     115,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   236,   236,   239,   413,   237,   410,   217,   236,
     238,   236,   239,   239,   239,   239,   237,   295,   129,   236,
     236,   239,   404,   239,   237,   400,   236,   236,   236,   236,
     140,   141,   142,   143,   144,   145,   146,   245,   246,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   115,   115,   246,   239,   115,   115,   246,   115,   115,
     246,   129,   115,   115,   246,   115,   248,   248,   236,   129,
     184,   185,   129,   217,   129,   129,   239,   129,   129,   115,
     129,   129,   129,   129,   236,   129,   129,   236,   236,   129,
     129,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,    48,   170,   171,
     172,   175,   176,   178,   179,   181,   183,   186,   188,   189,
     194,   198,   202,   203,   204,   209,   214,   509,   510,    48,
      50,    51,   170,   171,   172,   175,   176,   178,   179,   181,
     183,   186,   188,   189,   194,   198,   202,   203,   204,   209,
     214,   505,   506,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   129,   217,   239,   129,   115,   129,
     129,   129,   236,   129,   129,   236,   129,   129,   239,   115,
     367,   368,   236,   236,   236,   129,   129,   236,   129,   217,
     239,   129,   129,   129,   217,   239,   129,   129,   236,   129,
     129,   129,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,    17,    99,   103,   161,
     265,   266,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   129,   239,   236,
     236,     1,   107,   201,   225,   306,   307,   308,   309,   310,
     129,   129,   129,   129,   236,   236,   129,   239,   129,   236,
     245,   245,   245,   245,   245,   245,   245,   236,   236,   236,
      52,   130,   355,   356,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,    11,    12,    13,   247,   248,   236,
     236,   236,   236,   236,   236,   236,   236,   236,     8,   205,
     430,   431,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   240,   236,   240,   236,   236,    15,
      40,    73,   108,   109,   114,   138,   153,   216,   235,   381,
     382,   236,   236,   236,   236,   236,   236,   236,   236,   236,
      48,   196,   205,   361,   362,   224,   240,   366,   236,   236,
     236,   236,     4,    21,    22,    31,    69,    70,    72,   104,
     112,   134,   136,   137,   154,   177,   182,   186,   190,   195,
     199,   210,   212,   213,   215,   226,   234,   332,   333,   236,
     236,   236,   236,    48,    50,    51,   170,   171,   172,   175,
     176,   178,   179,   181,   183,   186,   188,   189,   194,   198,
     202,   203,   204,   209,   214,   328,   329,   236,   236,   236,
     236,   236,   236,   240,   236,    72,   137,   169,   177,   186,
     210,   212,   213,   226,   234,   414,   415,   236,   239,   239,
     311,   237,   307,   236,   236,   236,   236,   236,    72,   137,
     169,   177,   186,   210,   212,   213,   226,   234,   405,   406,
     236,   236,   240,   247,   247,   247,   236,   240,   510,   506,
     236,   240,   236,   240,   115,   368,   236,   241,   241,   241,
     241,   241,   241,   236,   240,   236,   240,   266,   236,   240,
     129,   211,   248,   239,   236,   236,   240,   356,   431,   382,
     362,   135,   137,   135,   137,   135,   135,   333,   329,   415,
     236,   236,   236,    70,    72,   120,   137,   176,   177,   228,
     234,   312,   313,   406,   236,   240,   313
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   242,   243,   243,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   245,   245,
     246,   246,   246,   246,   246,   246,   246,   246,   247,   247,
     248,   248,   248,   248,   249,   250,   250,   251,   251,   251,
     252,   253,   254,   255,   255,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   257,   258,   259,   260,
     261,   262,   264,   263,   265,   265,   266,   266,   266,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   281,   282,   282,   282,   282,
     283,   284,   285,   287,   286,   288,   288,   289,   289,   289,
     290,   291,   293,   292,   294,   294,   295,   295,   295,   295,
     295,   296,   297,   298,   299,   300,   301,   301,   302,   302,
     302,   303,   305,   304,   306,   306,   307,   307,   307,   307,
     308,   309,   309,   311,   310,   312,   312,   313,   313,   313,
     313,   313,   313,   313,   313,   315,   314,   316,   316,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   327,   326,
     328,   328,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   331,   330,   332,   332,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   335,   334,   336,
     336,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   354,   353,   355,   355,   356,   356,   358,
     357,   360,   359,   361,   361,   362,   362,   362,   363,   363,
     364,   364,   364,   364,   364,   366,   365,   367,   367,   368,
     368,   369,   370,   372,   371,   373,   373,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   375,   376,   377,   378,
     380,   379,   381,   381,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   383,   384,   385,   387,   386,   388,
     388,   389,   389,   389,   389,   390,   391,   392,   393,   394,
     394,   395,   395,   396,   398,   397,   399,   399,   400,   400,
     400,   400,   401,   402,   404,   403,   405,   405,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   408,   407,
     409,   409,   410,   410,   410,   411,   413,   412,   414,   414,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     417,   416,   418,   418,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   427,   429,   428,
     430,   430,   431,   431,   432,   433,   434,   435,   436,   438,
     437,   439,   439,   440,   440,   440,   441,   442,   444,   443,
     445,   445,   446,   446,   446,   447,   448,   449,   450,   450,
     451,   451,   452,   454,   453,   455,   455,   456,   456,   456,
     457,   458,   459,   460,   460,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     489,   490,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   504,   503,   505,   505,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   508,   507,   509,   509,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   511,   512,   513,   514,   515,
     515,   516,   516,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     531,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541
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
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4
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
#line 2900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 439 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2987 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 445 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2996 "conf_parser.c" /* yacc.c:1646  */
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
#line 3008 "conf_parser.c" /* yacc.c:1646  */
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
#line 3020 "conf_parser.c" /* yacc.c:1646  */
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
#line 3032 "conf_parser.c" /* yacc.c:1646  */
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
#line 3044 "conf_parser.c" /* yacc.c:1646  */
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
#line 3056 "conf_parser.c" /* yacc.c:1646  */
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
#line 3068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 535 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options = 0;
}
#line 3077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 542 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_STANDARD;
#endif
}
#line 3088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 548 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MEMORY_CACHE;
#endif
}
#line 3099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 554 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MMAP_CACHE;
#endif
}
#line 3110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 560 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_CHECK_CACHE;
#endif
}
#line 3121 "conf_parser.c" /* yacc.c:1646  */
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
#line 3139 "conf_parser.c" /* yacc.c:1646  */
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
#line 3157 "conf_parser.c" /* yacc.c:1646  */
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
#line 3175 "conf_parser.c" /* yacc.c:1646  */
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
#line 3193 "conf_parser.c" /* yacc.c:1646  */
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
#line 3206 "conf_parser.c" /* yacc.c:1646  */
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
#line 3223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 652 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3235 "conf_parser.c" /* yacc.c:1646  */
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
#line 3266 "conf_parser.c" /* yacc.c:1646  */
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
#line 3297 "conf_parser.c" /* yacc.c:1646  */
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
#line 3325 "conf_parser.c" /* yacc.c:1646  */
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
#line 3350 "conf_parser.c" /* yacc.c:1646  */
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
#line 3375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 786 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 804 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 813 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 822 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3429 "conf_parser.c" /* yacc.c:1646  */
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
#line 3446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 856 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 862 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 872 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3473 "conf_parser.c" /* yacc.c:1646  */
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
#line 3491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 894 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 900 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 906 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3518 "conf_parser.c" /* yacc.c:1646  */
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
#line 3539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 940 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 946 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3557 "conf_parser.c" /* yacc.c:1646  */
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
#line 3570 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 966 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 974 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 977 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3597 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 982 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 989 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 993 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 997 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1001 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1005 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1009 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3660 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3669 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1017 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3678 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3690 "conf_parser.c" /* yacc.c:1646  */
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
#line 3747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1101 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3756 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1113 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3774 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3783 "conf_parser.c" /* yacc.c:1646  */
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
#line 3797 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1136 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3806 "conf_parser.c" /* yacc.c:1646  */
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
#line 3820 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1153 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3829 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1159 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1166 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1170 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1174 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1178 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1182 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1186 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1190 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1194 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1198 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1202 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1206 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1210 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1214 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1218 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1222 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1226 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1230 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1234 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1238 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4009 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1242 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1246 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4027 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1250 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4036 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1267 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4063 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1271 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1275 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1279 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4090 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1283 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4108 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1291 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1295 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1299 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1303 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1307 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4153 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1311 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4162 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1315 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4171 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1319 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4180 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1323 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4189 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1327 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4198 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1331 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4207 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1335 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1339 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4225 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1343 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4234 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1347 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4243 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1351 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4252 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1355 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4261 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1359 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1363 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4279 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1367 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1371 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4297 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1375 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4306 "conf_parser.c" /* yacc.c:1646  */
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
#line 4323 "conf_parser.c" /* yacc.c:1646  */
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
#line 4370 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1460 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1466 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1472 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1478 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1484 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1490 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1496 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1502 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1508 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1514 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1521 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1527 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4479 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1533 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4488 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1539 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1548 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1557 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1564 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1568 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1578 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1584 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4556 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1590 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1594 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1598 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1606 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1611 "conf_parser.y" /* yacc.c:1646  */
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
#line 4607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1624 "conf_parser.y" /* yacc.c:1646  */
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
#line 4627 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1641 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4636 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1647 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4645 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1657 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4654 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1661 "conf_parser.y" /* yacc.c:1646  */
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
#line 4699 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1714 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4708 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1720 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4717 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1726 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4726 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1732 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4740 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1743 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1750 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4758 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1754 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4767 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1758 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1762 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4785 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1766 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1770 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4803 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1774 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4812 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1778 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4821 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1782 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4830 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1786 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4839 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1792 "conf_parser.y" /* yacc.c:1646  */
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
#line 4856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1806 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1815 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1828 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1846 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1852 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1858 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1873 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1889 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1900 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1915 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1921 "conf_parser.y" /* yacc.c:1646  */
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
#line 5007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1940 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1951 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1955 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1963 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1967 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1971 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1975 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1979 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1983 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1993 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2002 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2015 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2032 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2036 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2040 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5187 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 404:
#line 2044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2052 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2056 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2060 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2064 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2074 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2083 "conf_parser.y" /* yacc.c:1646  */
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
#line 5321 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2163 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5330 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2169 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5339 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2175 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2181 "conf_parser.y" /* yacc.c:1646  */
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
#line 5364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2194 "conf_parser.y" /* yacc.c:1646  */
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
#line 5380 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2207 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2213 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2219 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2223 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2229 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2235 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2239 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2245 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2274 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2293 "conf_parser.y" /* yacc.c:1646  */
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
#line 5531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2318 "conf_parser.y" /* yacc.c:1646  */
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
#line 5554 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2338 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2348 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2352 "conf_parser.y" /* yacc.c:1646  */
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
#line 5598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2378 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2384 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 472:
#line 2399 "conf_parser.y" /* yacc.c:1646  */
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
#line 5633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 473:
#line 2416 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 474:
#line 2420 "conf_parser.y" /* yacc.c:1646  */
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
#line 5662 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 480:
#line 2440 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5671 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 481:
#line 2446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5680 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2508 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5688 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2513 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5696 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2518 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5704 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2523 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5712 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2528 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2534 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5729 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2539 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5737 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2544 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5745 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2549 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5753 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2554 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5761 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2559 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5769 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2564 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2569 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5785 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2574 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2579 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5801 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2584 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2589 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5817 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2594 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2599 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5833 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2604 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5842 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2610 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2615 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2620 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2625 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2630 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2635 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2640 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2645 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2648 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5914 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2653 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2656 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2661 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2666 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2671 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2676 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2681 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5970 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2686 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2691 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5986 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2696 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2701 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2706 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6010 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2711 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2716 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2721 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2727 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6042 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2730 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6050 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2733 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6058 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2736 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2739 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6082 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2745 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6090 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2751 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2754 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6114 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6122 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2760 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6130 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2763 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2766 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2769 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6154 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6162 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2775 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2778 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2781 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2784 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6194 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6202 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2790 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6226 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6234 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6242 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6250 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6266 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6274 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6282 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6290 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6298 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6306 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6314 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6322 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 618:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6330 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 619:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 620:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6346 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 621:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6354 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 622:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6362 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 623:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6370 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6386 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2868 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6394 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2873 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 2900 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 2910 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2915 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2920 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2925 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2930 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6458 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2935 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6466 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 2940 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 2945 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 2950 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6490 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 2955 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 2960 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 671:
#line 2983 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 672:
#line 2989 "conf_parser.y" /* yacc.c:1646  */
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
#line 6534 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 673:
#line 3005 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 674:
#line 3014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 675:
#line 3020 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6564 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 676:
#line 3026 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 677:
#line 3032 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 678:
#line 3041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6594 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 679:
#line 3047 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6603 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6607 "conf_parser.c" /* yacc.c:1646  */
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
