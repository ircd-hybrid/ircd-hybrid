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
    MAX_LOCAL = 344,
    MAX_NICK_CHANGES = 345,
    MAX_NICK_LENGTH = 346,
    MAX_NICK_TIME = 347,
    MAX_NUMBER = 348,
    MAX_TARGETS = 349,
    MAX_TOPIC_LENGTH = 350,
    MAX_WATCH = 351,
    MEMORY_CACHE = 352,
    MIN_IDLE = 353,
    MIN_NONWILDCARD = 354,
    MIN_NONWILDCARD_SIMPLE = 355,
    MMAP_CACHE = 356,
    MODULE = 357,
    MODULES = 358,
    MOTD = 359,
    NAME = 360,
    NEED_IDENT = 361,
    NEED_PASSWORD = 362,
    NETWORK_DESC = 363,
    NETWORK_NAME = 364,
    NICK = 365,
    NO_OPER_FLOOD = 366,
    NO_TILDE = 367,
    NUMBER = 368,
    NUMBER_PER_CIDR = 369,
    NUMBER_PER_IP = 370,
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
    QSTRING = 382,
    RANDOM_IDLE = 383,
    REASON = 384,
    REDIRPORT = 385,
    REDIRSERV = 386,
    REHASH = 387,
    REMOTE = 388,
    REMOTEBAN = 389,
    RESV = 390,
    RESV_EXEMPT = 391,
    RSA_PRIVATE_KEY_FILE = 392,
    SECONDS = 393,
    MINUTES = 394,
    HOURS = 395,
    DAYS = 396,
    WEEKS = 397,
    MONTHS = 398,
    YEARS = 399,
    SEND_PASSWORD = 400,
    SENDQ = 401,
    SERVERHIDE = 402,
    SERVERINFO = 403,
    SHORT_MOTD = 404,
    SPOOF = 405,
    SPOOF_NOTICE = 406,
    SQUIT = 407,
    SSL_CERTIFICATE_FILE = 408,
    SSL_CERTIFICATE_FINGERPRINT = 409,
    SSL_CONNECTION_REQUIRED = 410,
    SSL_DH_ELLIPTIC_CURVE = 411,
    SSL_DH_PARAM_FILE = 412,
    SSL_MESSAGE_DIGEST_ALGORITHM = 413,
    STANDARD = 414,
    STATS_E_DISABLED = 415,
    STATS_I_OPER_ONLY = 416,
    STATS_K_OPER_ONLY = 417,
    STATS_M_OPER_ONLY = 418,
    STATS_O_OPER_ONLY = 419,
    STATS_P_OPER_ONLY = 420,
    STATS_U_OPER_ONLY = 421,
    T_ALL = 422,
    T_BOTS = 423,
    T_CALLERID = 424,
    T_CCONN = 425,
    T_COMMAND = 426,
    T_CLUSTER = 427,
    T_DEAF = 428,
    T_DEBUG = 429,
    T_DLINE = 430,
    T_EXTERNAL = 431,
    T_FARCONNECT = 432,
    T_FILE = 433,
    T_FULL = 434,
    T_GLOBOPS = 435,
    T_INVISIBLE = 436,
    T_IPV4 = 437,
    T_IPV6 = 438,
    T_LOCOPS = 439,
    T_LOG = 440,
    T_NCHANGE = 441,
    T_NONONREG = 442,
    T_OPME = 443,
    T_PREPEND = 444,
    T_PSEUDO = 445,
    T_RECVQ = 446,
    T_REJ = 447,
    T_RESTART = 448,
    T_SERVER = 449,
    T_SERVICE = 450,
    T_SERVNOTICE = 451,
    T_SET = 452,
    T_SHARED = 453,
    T_SIZE = 454,
    T_SKILL = 455,
    T_SOFTCALLERID = 456,
    T_SPY = 457,
    T_SSL = 458,
    T_SSL_CIPHER_LIST = 459,
    T_TARGET = 460,
    T_UMODES = 461,
    T_UNAUTH = 462,
    T_UNDLINE = 463,
    T_UNLIMITED = 464,
    T_UNRESV = 465,
    T_UNXLINE = 466,
    T_WALLOP = 467,
    T_WALLOPS = 468,
    T_WEBIRC = 469,
    TBOOL = 470,
    THROTTLE_COUNT = 471,
    THROTTLE_TIME = 472,
    TKLINE_EXPIRE_NOTICES = 473,
    TMASKED = 474,
    TS_MAX_DELTA = 475,
    TS_WARN_DELTA = 476,
    TWODOTS = 477,
    TYPE = 478,
    UNKLINE = 479,
    USE_LOGGING = 480,
    USER = 481,
    VHOST = 482,
    VHOST6 = 483,
    WARN_NO_CONNECT_BLOCK = 484,
    WHOIS = 485,
    WHOWAS_HISTORY_LENGTH = 486,
    XLINE = 487,
    XLINE_EXEMPT = 488
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
#define MAX_LOCAL 344
#define MAX_NICK_CHANGES 345
#define MAX_NICK_LENGTH 346
#define MAX_NICK_TIME 347
#define MAX_NUMBER 348
#define MAX_TARGETS 349
#define MAX_TOPIC_LENGTH 350
#define MAX_WATCH 351
#define MEMORY_CACHE 352
#define MIN_IDLE 353
#define MIN_NONWILDCARD 354
#define MIN_NONWILDCARD_SIMPLE 355
#define MMAP_CACHE 356
#define MODULE 357
#define MODULES 358
#define MOTD 359
#define NAME 360
#define NEED_IDENT 361
#define NEED_PASSWORD 362
#define NETWORK_DESC 363
#define NETWORK_NAME 364
#define NICK 365
#define NO_OPER_FLOOD 366
#define NO_TILDE 367
#define NUMBER 368
#define NUMBER_PER_CIDR 369
#define NUMBER_PER_IP 370
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
#define QSTRING 382
#define RANDOM_IDLE 383
#define REASON 384
#define REDIRPORT 385
#define REDIRSERV 386
#define REHASH 387
#define REMOTE 388
#define REMOTEBAN 389
#define RESV 390
#define RESV_EXEMPT 391
#define RSA_PRIVATE_KEY_FILE 392
#define SECONDS 393
#define MINUTES 394
#define HOURS 395
#define DAYS 396
#define WEEKS 397
#define MONTHS 398
#define YEARS 399
#define SEND_PASSWORD 400
#define SENDQ 401
#define SERVERHIDE 402
#define SERVERINFO 403
#define SHORT_MOTD 404
#define SPOOF 405
#define SPOOF_NOTICE 406
#define SQUIT 407
#define SSL_CERTIFICATE_FILE 408
#define SSL_CERTIFICATE_FINGERPRINT 409
#define SSL_CONNECTION_REQUIRED 410
#define SSL_DH_ELLIPTIC_CURVE 411
#define SSL_DH_PARAM_FILE 412
#define SSL_MESSAGE_DIGEST_ALGORITHM 413
#define STANDARD 414
#define STATS_E_DISABLED 415
#define STATS_I_OPER_ONLY 416
#define STATS_K_OPER_ONLY 417
#define STATS_M_OPER_ONLY 418
#define STATS_O_OPER_ONLY 419
#define STATS_P_OPER_ONLY 420
#define STATS_U_OPER_ONLY 421
#define T_ALL 422
#define T_BOTS 423
#define T_CALLERID 424
#define T_CCONN 425
#define T_COMMAND 426
#define T_CLUSTER 427
#define T_DEAF 428
#define T_DEBUG 429
#define T_DLINE 430
#define T_EXTERNAL 431
#define T_FARCONNECT 432
#define T_FILE 433
#define T_FULL 434
#define T_GLOBOPS 435
#define T_INVISIBLE 436
#define T_IPV4 437
#define T_IPV6 438
#define T_LOCOPS 439
#define T_LOG 440
#define T_NCHANGE 441
#define T_NONONREG 442
#define T_OPME 443
#define T_PREPEND 444
#define T_PSEUDO 445
#define T_RECVQ 446
#define T_REJ 447
#define T_RESTART 448
#define T_SERVER 449
#define T_SERVICE 450
#define T_SERVNOTICE 451
#define T_SET 452
#define T_SHARED 453
#define T_SIZE 454
#define T_SKILL 455
#define T_SOFTCALLERID 456
#define T_SPY 457
#define T_SSL 458
#define T_SSL_CIPHER_LIST 459
#define T_TARGET 460
#define T_UMODES 461
#define T_UNAUTH 462
#define T_UNDLINE 463
#define T_UNLIMITED 464
#define T_UNRESV 465
#define T_UNXLINE 466
#define T_WALLOP 467
#define T_WALLOPS 468
#define T_WEBIRC 469
#define TBOOL 470
#define THROTTLE_COUNT 471
#define THROTTLE_TIME 472
#define TKLINE_EXPIRE_NOTICES 473
#define TMASKED 474
#define TS_MAX_DELTA 475
#define TS_WARN_DELTA 476
#define TWODOTS 477
#define TYPE 478
#define UNKLINE 479
#define USE_LOGGING 480
#define USER 481
#define VHOST 482
#define VHOST6 483
#define WARN_NO_CONNECT_BLOCK 484
#define WHOIS 485
#define WHOWAS_HISTORY_LENGTH 486
#define XLINE 487
#define XLINE_EXEMPT 488

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 141 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 690 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 707 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1274

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  240
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  298
/* YYNRULES -- Number of rules.  */
#define YYNRULES  675
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1327

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   488

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
       2,     2,     2,     2,   238,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   239,   234,
       2,   237,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   236,     2,   235,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   378,   378,   379,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   409,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   420,   420,
     421,   422,   423,   424,   431,   433,   433,   434,   434,   434,
     436,   442,   452,   454,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   478,   487,   496,   505,
     514,   523,   533,   532,   538,   538,   539,   545,   551,   557,
     565,   580,   595,   610,   625,   635,   649,   658,   686,   714,
     739,   761,   783,   793,   795,   795,   796,   797,   798,   799,
     801,   810,   819,   833,   832,   850,   850,   851,   851,   851,
     853,   859,   870,   869,   888,   888,   889,   889,   889,   889,
     889,   891,   897,   903,   909,   931,   932,   932,   934,   934,
     935,   937,   944,   944,   957,   958,   960,   960,   961,   961,
     963,   971,   974,   980,   979,   985,   985,   986,   990,   994,
     998,  1002,  1006,  1010,  1014,  1025,  1024,  1085,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1098,  1104,  1110,  1116,  1122,  1133,  1139,  1150,  1157,  1156,
    1162,  1162,  1163,  1167,  1171,  1175,  1179,  1183,  1187,  1191,
    1195,  1199,  1203,  1207,  1211,  1215,  1219,  1223,  1227,  1231,
    1235,  1239,  1243,  1247,  1254,  1253,  1259,  1259,  1260,  1264,
    1268,  1272,  1276,  1280,  1284,  1288,  1292,  1296,  1300,  1304,
    1308,  1312,  1316,  1320,  1324,  1328,  1332,  1336,  1340,  1344,
    1348,  1352,  1356,  1360,  1364,  1368,  1372,  1383,  1382,  1438,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,
    1448,  1449,  1450,  1451,  1452,  1453,  1454,  1455,  1457,  1463,
    1469,  1475,  1481,  1487,  1493,  1499,  1505,  1511,  1518,  1524,
    1530,  1536,  1545,  1555,  1554,  1560,  1560,  1561,  1565,  1576,
    1575,  1582,  1581,  1586,  1586,  1587,  1591,  1595,  1601,  1601,
    1602,  1602,  1602,  1602,  1602,  1604,  1604,  1606,  1606,  1608,
    1621,  1638,  1644,  1655,  1654,  1700,  1700,  1701,  1702,  1703,
    1704,  1705,  1706,  1707,  1708,  1709,  1711,  1717,  1723,  1729,
    1741,  1740,  1746,  1746,  1747,  1751,  1755,  1759,  1763,  1767,
    1771,  1775,  1779,  1783,  1789,  1803,  1812,  1826,  1825,  1840,
    1840,  1841,  1841,  1841,  1841,  1843,  1849,  1855,  1865,  1867,
    1867,  1868,  1868,  1870,  1887,  1886,  1909,  1909,  1910,  1910,
    1910,  1910,  1912,  1918,  1938,  1937,  1943,  1943,  1944,  1948,
    1952,  1956,  1960,  1964,  1968,  1972,  1976,  1980,  1991,  1990,
    2009,  2009,  2010,  2010,  2010,  2012,  2019,  2018,  2024,  2024,
    2025,  2029,  2033,  2037,  2041,  2045,  2049,  2053,  2057,  2061,
    2072,  2071,  2143,  2143,  2144,  2145,  2146,  2147,  2148,  2149,
    2150,  2151,  2152,  2153,  2154,  2155,  2156,  2157,  2158,  2160,
    2166,  2172,  2178,  2191,  2204,  2210,  2216,  2220,  2227,  2226,
    2231,  2231,  2232,  2236,  2242,  2253,  2259,  2265,  2271,  2287,
    2286,  2312,  2312,  2313,  2313,  2313,  2315,  2335,  2346,  2345,
    2372,  2372,  2373,  2373,  2373,  2375,  2381,  2391,  2393,  2393,
    2394,  2394,  2396,  2414,  2413,  2434,  2434,  2435,  2435,  2435,
    2437,  2443,  2453,  2455,  2455,  2456,  2457,  2458,  2459,  2460,
    2461,  2462,  2463,  2464,  2465,  2466,  2467,  2468,  2469,  2470,
    2471,  2472,  2473,  2474,  2475,  2476,  2477,  2478,  2479,  2480,
    2481,  2482,  2483,  2484,  2485,  2486,  2487,  2488,  2489,  2490,
    2491,  2492,  2493,  2494,  2495,  2496,  2497,  2498,  2499,  2500,
    2501,  2502,  2505,  2510,  2515,  2520,  2525,  2531,  2536,  2541,
    2546,  2551,  2556,  2561,  2566,  2571,  2576,  2581,  2586,  2591,
    2596,  2601,  2607,  2612,  2617,  2622,  2627,  2632,  2637,  2642,
    2645,  2650,  2653,  2658,  2663,  2668,  2673,  2678,  2683,  2688,
    2693,  2698,  2703,  2708,  2713,  2719,  2718,  2723,  2723,  2724,
    2727,  2730,  2733,  2736,  2739,  2742,  2745,  2748,  2751,  2754,
    2757,  2760,  2763,  2766,  2769,  2772,  2775,  2778,  2781,  2784,
    2787,  2793,  2792,  2797,  2797,  2798,  2801,  2804,  2807,  2810,
    2813,  2816,  2819,  2822,  2825,  2828,  2831,  2834,  2837,  2840,
    2843,  2846,  2849,  2852,  2855,  2860,  2865,  2870,  2879,  2881,
    2881,  2882,  2883,  2884,  2885,  2886,  2887,  2888,  2889,  2890,
    2891,  2892,  2893,  2895,  2900,  2905,  2910,  2915,  2920,  2925,
    2930,  2935,  2940,  2945,  2954,  2956,  2956,  2957,  2958,  2959,
    2960,  2961,  2962,  2963,  2964,  2965,  2966,  2968,  2974,  2990,
    2999,  3005,  3011,  3017,  3026,  3032
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
  "MAX_BANS", "MAX_CHANNELS", "MAX_GLOBAL", "MAX_IDLE", "MAX_LOCAL",
  "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MAX_WATCH", "MEMORY_CACHE",
  "MIN_IDLE", "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MMAP_CACHE",
  "MODULE", "MODULES", "MOTD", "NAME", "NEED_IDENT", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPER_ONLY_UMODES",
  "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID", "PACE_WAIT",
  "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME",
  "PORT", "QSTRING", "RANDOM_IDLE", "REASON", "REDIRPORT", "REDIRSERV",
  "REHASH", "REMOTE", "REMOTEBAN", "RESV", "RESV_EXEMPT",
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
     485,   486,   487,   488,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -728

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-728)))

#define YYTABLE_NINF -143

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -728,   669,  -728,  -191,  -226,  -219,  -728,  -728,  -728,  -216,
    -728,  -214,  -728,  -728,  -728,  -208,  -728,  -728,  -728,  -195,
    -187,  -728,  -177,  -728,  -167,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,    37,   762,  -165,  -162,  -160,     2,  -154,   390,  -152,
    -139,  -127,   287,  -124,  -113,  -106,   934,   438,   -80,    35,
     -75,    17,   -68,   -48,   -44,   -43,   -37,    10,  -728,  -728,
    -728,  -728,  -728,   -29,   -15,    47,    53,    66,    67,    80,
      86,    87,   106,   112,   171,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,   705,   573,    30,
    -728,   114,    24,  -728,  -728,    28,  -728,   117,   122,   124,
     125,   128,   133,   134,   136,   137,   142,   143,   147,   149,
     151,   156,   158,   161,   164,   165,   166,   168,   170,   175,
     180,   182,  -728,  -728,   183,   187,   191,   193,   194,   198,
     199,   200,   203,   204,   205,   206,   207,   208,   214,   215,
     216,   217,   222,    54,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,   522,    51,   352,   -23,   224,   225,    41,  -728,  -728,
    -728,    12,   343,   309,  -728,   230,   232,   233,   234,   235,
     236,   238,   239,   240,   293,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,    98,   242,   244,   246,   250,
    -728,   251,   255,   262,   263,   265,   266,   267,   271,   275,
     276,   278,   279,   283,   284,   285,    26,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,    50,   153,
     288,    57,  -728,  -728,  -728,   100,    91,  -728,   289,    15,
    -728,  -728,    72,  -728,   138,   256,   296,   223,  -728,   411,
     417,   316,   419,   417,   417,   421,   417,   417,   423,   424,
     304,  -728,   306,   307,   308,   311,  -728,   321,   325,   326,
     327,   328,   329,   331,   333,   334,   335,   349,   350,   220,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,   355,   353,   360,
     361,   362,   364,   365,  -728,   366,   377,   378,   379,   383,
     386,   388,   186,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,   389,
     391,    23,  -728,  -728,  -728,   414,   393,  -728,  -728,   395,
     397,    31,  -728,  -728,  -728,   415,   417,   524,   417,   417,
     426,   527,   428,   532,   533,   534,   433,   435,   439,   417,
     542,   543,   547,   548,   417,   549,   550,   554,   555,   456,
     437,   440,   460,   417,   417,   461,   464,   465,  -196,  -185,
     467,   468,   469,   471,   574,   417,   475,   417,   417,   477,
     580,   462,  -728,   463,   457,   458,  -728,   470,   472,   474,
     480,   482,    79,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,   483,   485,    76,  -728,  -728,  -728,   466,
     488,   489,  -728,   492,  -728,     6,  -728,  -728,  -728,  -728,
    -728,   575,   577,   478,  -728,   497,   495,   496,    46,  -728,
    -728,  -728,   501,   499,   500,  -728,   502,   504,   507,   508,
    -728,   509,   510,   146,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,   515,   513,   516,   518,   140,
    -728,  -728,  -728,  -728,   486,   490,   417,   581,   537,   587,
     544,   545,   553,   528,  -728,  -728,   645,   634,   559,   637,
     530,   638,   642,   662,   663,   652,   654,   657,   659,   670,
     672,   674,   675,   678,   679,   680,   556,  -728,   562,   571,
    -728,    44,  -728,  -728,  -728,  -728,   594,   578,  -728,   579,
     584,   576,   585,   589,   590,   150,  -728,  -728,  -728,  -728,
    -728,   684,   595,  -728,   597,   591,  -728,   596,    14,  -728,
    -728,  -728,  -728,   598,   600,   601,  -728,   602,   863,   606,
     608,   609,   610,   611,   612,   615,   616,   618,   619,  -728,
    -728,   701,   742,   417,   621,   743,   750,   417,   757,   759,
     417,   747,   764,   767,   417,   768,   768,   641,  -728,  -728,
     755,   -79,   756,   671,   758,   760,   653,   770,   771,   776,
     780,   783,   785,   787,   661,  -728,   788,   790,   686,  -728,
     688,  -728,   796,   798,   693,  -728,   695,   696,   697,   702,
     703,   704,   706,   711,   714,   717,   721,   722,   724,   728,
     729,   730,   733,   737,   738,   752,   761,   765,   766,   774,
     775,   773,   692,   777,   778,   779,   781,   782,   789,   791,
     792,   793,   794,   795,   797,   799,   800,   801,   802,   803,
     804,   805,   806,   807,  -728,  -728,   839,   676,   666,   854,
     813,   857,   864,   865,   808,  -728,   866,   871,   809,  -728,
    -728,   887,   890,   753,   906,   810,  -728,   811,   812,  -728,
    -728,   893,   894,   814,  -728,  -728,   895,   815,   816,   897,
     905,   920,   834,   817,   923,   924,   818,  -728,  -728,   928,
     929,   930,   824,  -728,   825,   826,   827,   828,   829,   830,
     831,   832,   833,  -728,   835,   836,   837,   838,   219,   840,
     841,   842,   843,   844,   845,   846,   847,   848,   849,   850,
     851,   852,   853,   855,  -728,  -728,   941,   856,   858,  -728,
     860,  -728,     3,  -728,   946,   961,   963,   964,   861,  -728,
     862,  -728,  -728,   970,   867,   971,   868,  -728,  -728,  -728,
    -728,  -728,   417,   417,   417,   417,   417,   417,   417,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,   869,   872,   873,   -26,   874,   875,   876,   877,   878,
     879,   880,   881,   882,   883,   345,   884,   885,  -728,   886,
     888,   889,   891,   892,   896,   898,     4,   899,   900,   901,
     902,   903,   904,   907,  -728,   908,   909,  -728,  -728,   910,
     911,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -201,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -199,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,   912,   913,   552,   914,   915,   916,
     917,   918,  -728,   919,   921,  -728,   922,   925,   -27,   932,
     926,  -728,  -728,  -728,  -728,   927,   931,  -728,   933,   935,
     425,   936,   937,   938,   939,   732,   940,   942,  -728,   943,
     944,   945,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -188,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,   947,   546,  -728,
    -728,   948,   949,   950,  -728,    64,  -728,  -728,  -728,  -728,
     951,   954,   955,   956,  -728,  -728,   957,   786,   958,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -181,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,   768,   768,   768,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -153,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,   773,  -728,   692,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,   -76,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,   -46,  -728,   986,   906,   959,  -728,  -728,
    -728,  -728,  -728,  -728,   960,  -728,   962,   965,  -728,  -728,
     966,   967,  -728,  -728,   968,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,   -39,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,    -7,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,   219,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,    59,  -728,  -728,   973,   -99,
     972,   969,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,    95,  -728,
    -728,  -728,   -26,  -728,  -728,  -728,  -728,     4,  -728,  -728,
    -728,   552,  -728,   -27,  -728,  -728,  -728,   988,   989,   994,
     993,   996,   998,  -728,   425,  -728,   732,  -728,  -728,   546,
     974,   976,   977,   259,  -728,  -728,   786,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,   126,  -728,  -728,  -728,   259,  -728
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
     108,   107,   642,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   630,   641,   632,   633,   634,
     635,   636,   637,   638,   631,   639,   640,     0,     0,     0,
     471,     0,     0,   469,   470,     0,   531,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   601,   575,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   484,   485,   486,   529,   493,   530,
     524,   525,   526,   527,   523,   497,   487,   488,   489,   490,
     491,   492,   494,   495,   496,   498,   499,   528,   503,   504,
     505,   506,   502,   501,   507,   514,   515,   508,   509,   510,
     500,   512,   521,   522,   519,   520,   513,   511,   517,   518,
     516,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,     0,     0,     0,   666,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   656,   657,   658,   659,   660,
     661,   662,   664,   663,   665,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    69,    66,
      64,    70,    71,    65,    72,    73,    74,    55,    68,    58,
      59,    60,    56,    67,    61,    62,    63,    57,     0,     0,
       0,     0,   137,   138,   139,     0,     0,   362,     0,     0,
     360,   361,     0,   109,     0,     0,     0,     0,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   629,     0,     0,     0,     0,   283,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   251,   254,   256,   257,   258,   259,   260,   261,   262,
     263,   252,   253,   255,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,   438,     0,     0,     0,     0,     0,
       0,     0,     0,   413,   414,   415,   416,   417,   418,   419,
     421,   420,   423,   427,   424,   425,   426,   422,   464,     0,
       0,     0,   461,   462,   463,     0,     0,   468,   479,     0,
       0,     0,   476,   477,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   483,     0,     0,     0,   330,     0,     0,     0,
       0,     0,     0,   316,   317,   318,   319,   324,   320,   321,
     322,   323,   455,     0,     0,     0,   452,   453,   454,     0,
       0,     0,   291,     0,   301,     0,   299,   300,   302,   303,
      49,     0,     0,     0,    45,     0,     0,     0,     0,   116,
     117,   118,     0,     0,     0,   214,     0,     0,     0,     0,
     188,     0,     0,     0,   168,   169,   170,   171,   172,   175,
     176,   177,   174,   173,   178,     0,     0,     0,     0,     0,
     350,   351,   352,   353,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   655,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
     396,     0,   391,   392,   393,   140,     0,     0,   136,     0,
       0,     0,     0,     0,     0,     0,   125,   126,   128,   127,
     129,     0,     0,   359,     0,     0,   374,     0,     0,   367,
     368,   369,   370,     0,     0,     0,   103,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   628,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   249,   428,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   412,     0,     0,     0,   460,
       0,   467,     0,     0,     0,   475,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   482,   325,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   315,     0,     0,     0,   451,
     304,     0,     0,     0,     0,     0,   298,     0,     0,    44,
     119,     0,     0,     0,   115,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   354,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   654,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,   394,     0,     0,     0,   390,
       0,   135,     0,   130,     0,     0,     0,     0,     0,   124,
       0,   358,   371,     0,     0,     0,     0,   366,   112,   111,
     110,   652,    28,    28,    28,    28,    28,    28,    28,    30,
      29,   653,   643,   644,   645,   646,   647,   648,   649,   651,
     650,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,   348,   670,   667,   668,   669,   674,   673,   675,
     671,   672,    99,    94,   102,    93,    89,    87,    88,    86,
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
    -728,  -728,  -728,  -243,  -308,  -727,  -635,  -728,  -728,   978,
    -728,  -728,  -728,  -728,   952,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -122,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    1028,  -728,  -728,  -728,  -728,  -728,  -728,   660,  -728,  -728,
    -728,  -728,  -728,   572,  -728,  -728,  -728,  -728,  -728,  -728,
     953,  -728,  -728,  -728,  -728,    84,  -728,  -728,  -728,  -728,
    -728,  -163,  -728,  -728,  -728,   627,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -126,  -728,  -728,
    -728,  -121,  -728,  -728,  -728,   859,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,   -96,  -728,  -728,  -728,  -728,  -728,
    -105,  -728,   690,  -728,  -728,  -728,    27,  -728,  -728,  -728,
    -728,  -728,   718,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
     -87,  -728,  -728,  -728,  -728,  -728,  -728,   665,  -728,  -728,
    -728,  -728,  -728,   975,  -728,  -728,  -728,  -728,   599,  -728,
    -728,  -728,  -728,  -728,  -100,  -728,  -728,  -728,   629,  -728,
    -728,  -728,  -728,   -77,  -728,  -728,  -728,   870,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,   -65,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,   739,  -728,
    -728,  -728,  -728,  -728,   822,  -728,  -728,  -728,  -728,  1103,
    -728,  -728,  -728,  -728,   819,  -728,  -728,  -728,  -728,  1053,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,    93,  -728,  -728,  -728,    97,  -728,
    -728,  -728,  -728,  -728,  1123,  -728,  -728,  -728,  -728,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728,   990,  -728,
    -728,  -728,  -728,  -728,  -728,  -728,  -728,  -728
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   829,   830,  1097,  1098,    27,   217,   218,
     219,   220,    28,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   550,  1030,  1031,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,    29,    77,
      78,    79,    80,    81,    30,    63,   498,   499,   500,   501,
      31,    70,   585,   586,   587,   588,   589,   590,    32,   291,
     292,   293,   294,   295,  1055,  1056,  1057,  1058,  1059,  1240,
    1321,  1322,    33,    64,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   753,  1215,  1216,   524,   748,
    1187,  1188,    34,    53,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   624,  1082,  1083,    35,    61,   484,   733,  1153,
    1154,   485,   486,   487,  1157,   990,   991,   488,   489,    36,
      59,   462,   463,   464,   465,   466,   467,   468,   718,  1139,
    1140,   469,   470,   471,    37,    65,   529,   530,   531,   532,
     533,    38,   299,   300,   301,    39,    72,   598,   599,   600,
     601,   602,   814,  1258,  1259,    40,    68,   571,   572,   573,
     574,   797,  1235,  1236,    41,    54,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   646,  1110,  1111,
     383,   384,   385,   386,   387,    42,    60,   475,   476,   477,
     478,    43,    55,   391,   392,   393,   394,    44,   112,   113,
     114,    45,    57,   401,   402,   403,   404,    46,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   431,   951,   952,   207,   430,   927,   928,   208,
     209,   210,    47,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    48,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     856,   857,   609,   110,  1051,   612,   613,   479,   615,   616,
      51,    73,  1108,   495,   855,   594,   297,    52,   297,   699,
      56,  1150,    58,   700,   388,   110,  1080,   245,    62,   398,
     701,   388,   398,  1123,   702,  1125,   289,  1124,    73,  1126,
      74,    66,   214,    49,    50,   568,  1222,   495,    75,    67,
    1223,   568,   472,  1261,   246,   116,   247,  1262,   289,    69,
     117,   118,   480,   119,   120,  1051,   111,    74,   121,    71,
     481,   107,   482,   594,   108,    75,   109,   472,   122,   123,
     453,  1266,   115,   248,   211,  1267,   124,   389,   111,   125,
     126,   127,   580,   249,   389,   496,   128,   212,   667,   454,
     669,   670,  1081,   860,   861,   250,   251,   252,  1052,   213,
    1291,   680,   221,   129,   130,    76,   685,   253,   455,   595,
     298,   254,   298,   222,   131,   694,   695,   132,   133,   496,
     223,   255,   483,   399,   256,   257,   399,   708,   134,   710,
     711,   525,    76,   215,   135,   456,   136,   502,   137,   569,
     138,   580,   390,   139,   140,   569,   288,   400,  1270,   390,
     400,   296,  1271,   258,   216,   141,   503,  1151,   302,  1052,
     142,   143,    82,   144,   145,   146,  1152,   595,   147,   259,
     473,   526,   260,   261,   262,   504,   303,   357,  1272,   358,
     497,   359,  1273,   304,   305,  1283,   581,    83,    84,  1284,
     306,   457,  1053,   148,    85,   473,   360,  1109,   309,   458,
     459,   490,   505,  -142,   149,   150,   151,   152,   153,   154,
     155,   322,   310,   527,   497,   361,  1054,  1285,   766,   460,
     263,  1286,    86,    87,    88,  -142,  1026,   596,   323,   324,
     597,   735,   362,   325,   363,   307,    89,    90,    91,   816,
     592,   506,   364,   264,   265,   581,    92,    93,   658,   396,
     290,   566,   582,  1053,   365,   603,   664,   570,   507,   528,
     156,   157,   158,   570,   159,   160,   493,   474,   579,   798,
     583,   743,   290,   161,   311,   162,   326,  1054,   214,   451,
     312,   366,   577,  1288,   224,   596,   584,  1289,   597,  1241,
     508,   509,   474,   313,   314,   461,   327,   328,   329,   330,
     525,   728,   367,   331,   724,   843,  1027,   315,   332,   847,
    1028,   582,   850,   316,   317,   333,   854,   225,  1313,  1295,
    1314,   368,   545,  1296,   334,   335,   226,   227,   228,   583,
     369,   229,   230,   318,   502,   336,   231,   232,   233,   319,
     526,   395,   510,   479,   405,   584,  1094,  1095,  1096,   406,
    1324,   407,   408,   503,  1325,   409,   337,  1263,  1264,  1265,
     410,   411,   511,   412,   413,   762,   512,  1315,  1029,   414,
     415,   756,   504,   604,   416,   808,   417,   575,   418,   215,
     370,   116,   527,   419,  1316,   420,   117,   118,   421,   119,
     120,   422,   423,   424,   121,   425,   320,   426,   480,   505,
     216,   338,   427,   371,   122,   123,   481,   428,   482,   429,
     432,   654,   124,   605,   433,   125,   126,   127,   434,  1162,
     435,   436,   128,  1317,  1318,   437,   438,   439,   528,   245,
     440,   441,   442,   443,   444,   445,  1163,  1164,   506,   129,
     130,   446,   447,   448,   449,   637,  1165,   606,   855,   450,
     131,   491,   492,   132,   133,   507,   246,   534,   247,   535,
     536,   537,   538,   539,   134,   540,   541,   542,   483,   546,
     135,   547,   136,   548,   137,  1319,   138,   549,   551,   139,
     140,  1320,   552,  1166,  1167,   248,  1168,   508,   509,   553,
     554,   141,   555,   556,   557,   249,   142,   143,   558,   144,
     145,   146,   559,   560,   147,   561,   562,   250,   251,   252,
     563,   564,   565,   453,   607,   576,   591,  1169,   543,   253,
     608,   610,   611,   254,   614,  1170,   617,   618,   619,   148,
     620,   660,   454,   255,   621,   622,   256,   257,   623,   510,
     149,   150,   151,   152,   153,   154,   155,  1171,   625,  1172,
    1173,   455,   626,   627,   628,   629,   630,  1129,   631,   511,
     632,   633,   634,   512,   357,   258,   358,  1174,   359,  1070,
    1071,  1072,  1073,  1074,  1075,  1076,   635,   636,   456,   639,
     640,   259,  1130,   360,   260,   261,   262,   641,   642,   643,
    1175,   644,   645,   647,  1292,  1176,   156,   157,   158,  1177,
     159,   160,   361,  1178,   648,   649,   650,  1225,  1179,   161,
     651,   162,  1180,   652,  1131,   653,   656,   661,   657,   362,
     666,   363,   662,  1181,   663,  1182,  1183,   668,  1184,   364,
     672,   671,   263,   673,   457,   674,   675,   676,   677,  1185,
     678,   365,   458,   459,   679,   681,   682,  1186,  1132,  1133,
     683,   684,   686,   687,  1134,   264,   265,   688,   689,     2,
       3,   690,   460,     4,   691,   693,   696,   692,   366,   697,
     698,  1226,   703,   704,   705,     5,   706,   707,  1135,     6,
     709,     7,   712,   713,   716,   717,   714,   715,     8,   367,
     730,   764,   737,  1136,   738,   765,   322,   719,   767,   720,
       9,   721,   739,  1227,   769,    10,    11,   722,   368,   723,
     726,  1228,   727,   323,   324,   731,   732,   369,   325,   734,
    1229,   740,   741,   742,    12,   745,   746,   747,    13,   749,
     929,   750,   930,   931,   751,   752,   754,   755,   461,   758,
     759,    14,   768,   760,  1230,   761,  1231,  1232,   774,   770,
     771,   775,   773,    82,   777,   779,  1137,   778,   772,   780,
    1233,   326,    15,    16,   776,   781,   782,   370,  1234,   783,
    1193,   784,  1194,  1195,   785,  1138,   786,    17,    83,    84,
     794,   327,   328,   329,   330,    85,   795,   787,   331,   788,
     371,   789,   790,   332,    18,   791,   792,   793,   796,   800,
     333,   810,   801,   804,   841,   802,    19,    20,   803,   334,
     335,   907,   805,    86,    87,    88,   806,   807,   813,   811,
     336,   812,   818,   815,   819,   820,   821,    89,    90,    91,
     831,    21,   832,   833,   834,   835,   836,    92,    93,   837,
     838,   337,   839,   840,    22,   842,   845,  1248,   844,    23,
     932,   933,   934,   846,    24,   935,   936,    25,   937,   938,
     848,   939,   849,   940,   851,   858,   941,   852,   942,   943,
     853,   855,   859,   862,   944,   864,   863,   865,   945,   869,
     866,   975,   946,   947,   948,   874,   338,   867,   868,   949,
    1196,  1197,  1198,   976,   950,  1199,  1200,   870,  1201,  1202,
     871,  1203,   872,  1204,   873,   875,  1205,   876,  1206,  1207,
     877,  1249,   878,   879,  1208,   880,   978,   881,  1209,   882,
     883,   884,  1210,  1211,  1212,   224,   885,   886,   887,  1213,
     888,   908,   909,   910,  1214,   889,   911,   912,   890,   913,
     914,   891,   915,  1250,   916,   892,   893,   917,   894,   918,
     919,  1251,   895,   896,   897,   920,   974,   898,   225,   921,
    1252,   899,   900,   922,   923,   924,   608,   226,   227,   228,
     925,   977,   229,   230,   979,   926,   901,   231,   232,   233,
     988,   980,   981,   983,  1253,   902,  1254,  1255,   984,   903,
     904,   822,   823,   824,   825,   826,   827,   828,   905,   906,
    1256,   953,   954,   955,   986,   956,   957,   987,  1257,   989,
     995,   996,   998,   958,  1001,   959,   960,   961,   962,   963,
     999,   964,  1002,   965,   966,   967,   968,   969,   970,   971,
     972,   973,   982,   985,   992,   993,   994,  1003,   997,  1004,
    1006,  1007,  1008,  1000,  1005,  1009,  1010,  1011,  1012,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1047,  1022,
    1023,  1024,  1025,  1060,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1061,  1046,
    1062,  1063,  1049,  1048,  1050,  1064,  1065,  1066,  1068,  1274,
    1290,  1287,  1069,  1077,  1067,   308,  1078,  1079,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1099,  1100,
    1101,  1301,  1102,  1103,  1302,  1104,  1105,  1303,  1304,  1305,
    1106,  1306,  1107,  1112,  1113,  1114,  1115,  1116,  1117,  1242,
     757,  1118,  1119,  1120,  1121,  1122,  1127,  1128,  1141,  1142,
    1143,  1144,  1145,  1146,  1155,  1147,  1148,   809,   744,  1149,
    1308,  1158,  1326,  1307,  1156,  1159,  1297,  1160,  1300,  1161,
    1189,  1190,  1191,  1192,  1217,   736,  1218,  1219,  1220,  1221,
     725,  1224,  1237,  1275,  1299,  1243,  1238,  1239,  1244,  1245,
    1246,  1247,  1260,  1276,   763,   494,  1323,   817,   638,  1277,
     799,  1278,  1298,  1294,  1279,  1280,  1281,  1282,  1310,  1293,
    1311,  1312,  1309,   659,   729,   397,   452,   321,   567,  1269,
     665,  1268,     0,     0,   544,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   655,     0,   578,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   593
};

static const yytype_int16 yycheck[] =
{
     635,   636,   310,     1,     1,   313,   314,     1,   316,   317,
     236,     1,     8,     1,   113,     1,     1,   236,     1,   215,
     236,    48,   236,   219,     1,     1,    52,     1,   236,     1,
     215,     1,     1,   234,   219,   234,     1,   238,     1,   238,
      30,   236,     1,   234,   235,     1,   234,     1,    38,   236,
     238,     1,     1,   234,    28,     1,    30,   238,     1,   236,
       6,     7,    56,     9,    10,     1,    64,    30,    14,   236,
      64,   236,    66,     1,   236,    38,   236,     1,    24,    25,
       1,   234,   236,    57,   236,   238,    32,    64,    64,    35,
      36,    37,     1,    67,    64,    83,    42,   236,   406,    20,
     408,   409,   128,   182,   183,    79,    80,    81,   105,   236,
     209,   419,   236,    59,    60,   105,   424,    91,    39,   105,
     105,    95,   105,   236,    70,   433,   434,    73,    74,    83,
     236,   105,   126,   105,   108,   109,   105,   445,    84,   447,
     448,     1,   105,   102,    90,    66,    92,     1,    94,   105,
      96,     1,   129,    99,   100,   105,   236,   129,   234,   129,
     129,   236,   238,   137,   123,   111,    20,   194,   236,   105,
     116,   117,     1,   119,   120,   121,   203,   105,   124,   153,
     129,    41,   156,   157,   158,    39,   234,     1,   234,     3,
     178,     5,   238,   237,   237,   234,   105,    26,    27,   238,
     237,   122,   199,   149,    33,   129,    20,   203,   237,   130,
     131,   234,    66,   178,   160,   161,   162,   163,   164,   165,
     166,     1,   237,    83,   178,    39,   223,   234,   536,   150,
     204,   238,    61,    62,    63,   178,    17,   223,    18,    19,
     226,   235,    56,    23,    58,   235,    75,    76,    77,   235,
     235,   105,    66,   227,   228,   105,    85,    86,   235,   235,
     225,   235,   171,   199,    78,   127,   235,   223,   122,   129,
     216,   217,   218,   223,   220,   221,   235,   226,   178,   235,
     189,   235,   225,   229,   237,   231,    66,   223,     1,   235,
     237,   105,   235,   234,     1,   223,   205,   238,   226,   235,
     154,   155,   226,   237,   237,   226,    86,    87,    88,    89,
       1,   235,   126,    93,   235,   623,    97,   237,    98,   627,
     101,   171,   630,   237,   237,   105,   634,    34,    69,   234,
      71,   145,   234,   238,   114,   115,    43,    44,    45,   189,
     154,    48,    49,   237,     1,   125,    53,    54,    55,   237,
      41,   237,   206,     1,   237,   205,    11,    12,    13,   237,
     234,   237,   237,    20,   238,   237,   146,  1094,  1095,  1096,
     237,   237,   226,   237,   237,   235,   230,   118,   159,   237,
     237,   235,    39,   127,   237,   235,   237,   234,   237,   102,
     204,     1,    83,   237,   135,   237,     6,     7,   237,     9,
      10,   237,   237,   237,    14,   237,   235,   237,    56,    66,
     123,   191,   237,   227,    24,    25,    64,   237,    66,   237,
     237,   235,    32,   127,   237,    35,    36,    37,   237,     4,
     237,   237,    42,   174,   175,   237,   237,   237,   129,     1,
     237,   237,   237,   237,   237,   237,    21,    22,   105,    59,
      60,   237,   237,   237,   237,   235,    31,   234,   113,   237,
      70,   237,   237,    73,    74,   122,    28,   237,    30,   237,
     237,   237,   237,   237,    84,   237,   237,   237,   126,   237,
      90,   237,    92,   237,    94,   226,    96,   237,   237,    99,
     100,   232,   237,    68,    69,    57,    71,   154,   155,   237,
     237,   111,   237,   237,   237,    67,   116,   117,   237,   119,
     120,   121,   237,   237,   124,   237,   237,    79,    80,    81,
     237,   237,   237,     1,   113,   237,   237,   102,   235,    91,
     113,   215,   113,    95,   113,   110,   113,   113,   234,   149,
     234,   127,    20,   105,   237,   237,   108,   109,   237,   206,
     160,   161,   162,   163,   164,   165,   166,   132,   237,   134,
     135,    39,   237,   237,   237,   237,   237,    15,   237,   226,
     237,   237,   237,   230,     1,   137,     3,   152,     5,   822,
     823,   824,   825,   826,   827,   828,   237,   237,    66,   234,
     237,   153,    40,    20,   156,   157,   158,   237,   237,   237,
     175,   237,   237,   237,  1239,   180,   216,   217,   218,   184,
     220,   221,    39,   188,   237,   237,   237,    71,   193,   229,
     237,   231,   197,   237,    72,   237,   237,   234,   237,    56,
     215,    58,   237,   208,   237,   210,   211,   113,   213,    66,
     113,   215,   204,   215,   122,   113,   113,   113,   215,   224,
     215,    78,   130,   131,   215,   113,   113,   232,   106,   107,
     113,   113,   113,   113,   112,   227,   228,   113,   113,     0,
       1,   215,   150,     4,   237,   215,   215,   237,   105,   215,
     215,   135,   215,   215,   215,    16,   215,   113,   136,    20,
     215,    22,   215,   113,   237,   237,   234,   234,    29,   126,
     234,   215,   127,   151,   127,   215,     1,   237,   127,   237,
      41,   237,   234,   167,   127,    46,    47,   237,   145,   237,
     237,   175,   237,    18,    19,   237,   237,   154,    23,   237,
     184,   234,   237,   237,    65,   234,   237,   237,    69,   237,
      48,   237,    50,    51,   237,   237,   237,   237,   226,   234,
     237,    82,   215,   237,   208,   237,   210,   211,   113,   215,
     215,   127,   234,     1,   127,   127,   214,   237,   215,   127,
     224,    66,   103,   104,   215,   113,   113,   204,   232,   127,
      48,   127,    50,    51,   127,   233,   127,   118,    26,    27,
     234,    86,    87,    88,    89,    33,   234,   127,    93,   127,
     227,   127,   127,    98,   135,   127,   127,   127,   237,   215,
     105,   127,   234,   237,   113,   236,   147,   148,   234,   114,
     115,    48,   237,    61,    62,    63,   237,   237,   237,   234,
     125,   234,   234,   237,   234,   234,   234,    75,    76,    77,
     234,   172,   234,   234,   234,   234,   234,    85,    86,   234,
     234,   146,   234,   234,   185,   113,   113,    71,   237,   190,
     168,   169,   170,   113,   195,   173,   174,   198,   176,   177,
     113,   179,   113,   181,   127,   234,   184,   113,   186,   187,
     113,   113,   127,   127,   192,   127,   215,   127,   196,   113,
     237,   215,   200,   201,   202,   234,   191,   127,   127,   207,
     168,   169,   170,   237,   212,   173,   174,   127,   176,   177,
     127,   179,   127,   181,   127,   127,   184,   127,   186,   187,
     234,   135,   234,   127,   192,   127,   113,   234,   196,   234,
     234,   234,   200,   201,   202,     1,   234,   234,   234,   207,
     234,   168,   169,   170,   212,   234,   173,   174,   234,   176,
     177,   234,   179,   167,   181,   234,   234,   184,   234,   186,
     187,   175,   234,   234,   234,   192,   127,   234,    34,   196,
     184,   234,   234,   200,   201,   202,   113,    43,    44,    45,
     207,   127,    48,    49,   127,   212,   234,    53,    54,    55,
     237,   127,   127,   127,   208,   234,   210,   211,   127,   234,
     234,   138,   139,   140,   141,   142,   143,   144,   234,   234,
     224,   234,   234,   234,   127,   234,   234,   127,   232,   113,
     127,   127,   127,   234,   127,   234,   234,   234,   234,   234,
     215,   234,   127,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   127,   234,   215,
     127,   127,   234,   237,   237,   127,   127,   127,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   127,   234,
     234,   234,   234,   127,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   127,   234,
     127,   127,   234,   237,   234,   234,   234,   127,   127,   113,
     127,  1223,   234,   234,   237,    77,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   133,   234,   234,   135,   234,   234,   133,   135,   133,
     234,   133,   234,   234,   234,   234,   234,   234,   234,  1055,
     513,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   222,   234,   234,   585,   498,   234,
    1286,   234,  1325,  1284,   238,   234,  1262,   234,  1273,   234,
     234,   234,   234,   234,   234,   485,   234,   234,   234,   234,
     462,   234,   234,  1156,  1271,   234,   237,   237,   234,   234,
     234,   234,   234,   234,   529,   217,  1296,   598,   339,   239,
     571,   239,  1267,   234,   239,   239,   239,   239,   234,   237,
     234,   234,  1289,   391,   475,   112,   163,    94,   266,  1126,
     401,  1124,    -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   372,    -1,   291,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   299
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   241,     0,     1,     4,    16,    20,    22,    29,    41,
      46,    47,    65,    69,    82,   103,   104,   118,   135,   147,
     148,   172,   185,   190,   195,   198,   242,   247,   252,   278,
     284,   290,   298,   312,   332,   355,   369,   384,   391,   395,
     405,   414,   435,   441,   447,   451,   457,   512,   526,   234,
     235,   236,   236,   333,   415,   442,   236,   452,   236,   370,
     436,   356,   236,   285,   313,   385,   236,   236,   406,   236,
     291,   236,   396,     1,    30,    38,   105,   279,   280,   281,
     282,   283,     1,    26,    27,    33,    61,    62,    63,    75,
      76,    77,    85,    86,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   236,   236,   236,
       1,    64,   448,   449,   450,   236,     1,     6,     7,     9,
      10,    14,    24,    25,    32,    35,    36,    37,    42,    59,
      60,    70,    73,    74,    84,    90,    92,    94,    96,    99,
     100,   111,   116,   117,   119,   120,   121,   124,   149,   160,
     161,   162,   163,   164,   165,   166,   216,   217,   218,   220,
     221,   229,   231,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   505,   509,   510,
     511,   236,   236,   236,     1,   102,   123,   248,   249,   250,
     251,   236,   236,   236,     1,    34,    43,    44,    45,    48,
      49,    53,    54,    55,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,     1,    28,    30,    57,    67,
      79,    80,    81,    91,    95,   105,   108,   109,   137,   153,
     156,   157,   158,   204,   227,   228,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   236,     1,
     225,   299,   300,   301,   302,   303,   236,     1,   105,   392,
     393,   394,   236,   234,   237,   237,   237,   235,   280,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     235,   514,     1,    18,    19,    23,    66,    86,    87,    88,
      89,    93,    98,   105,   114,   115,   125,   146,   191,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     1,     3,     5,
      20,    39,    56,    58,    66,    78,   105,   126,   145,   154,
     204,   227,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   430,   431,   432,   433,   434,     1,    64,
     129,   443,   444,   445,   446,   237,   235,   449,     1,   105,
     129,   453,   454,   455,   456,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     506,   502,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   235,   459,     1,    20,    39,    66,   122,   130,   131,
     150,   226,   371,   372,   373,   374,   375,   376,   377,   381,
     382,   383,     1,   129,   226,   437,   438,   439,   440,     1,
      56,    64,    66,   126,   357,   361,   362,   363,   367,   368,
     234,   237,   237,   235,   249,     1,    83,   178,   286,   287,
     288,   289,     1,    20,    39,    66,   105,   122,   154,   155,
     206,   226,   230,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   328,     1,    41,    83,   129,   386,
     387,   388,   389,   390,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   235,   528,   234,   237,   237,   237,   237,
     262,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   235,   254,     1,   105,
     223,   407,   408,   409,   410,   234,   237,   235,   300,   178,
       1,   105,   171,   189,   205,   292,   293,   294,   295,   296,
     297,   237,   235,   393,     1,   105,   223,   226,   397,   398,
     399,   400,   401,   127,   127,   127,   234,   113,   113,   244,
     215,   113,   244,   244,   113,   244,   244,   113,   113,   234,
     234,   237,   237,   237,   352,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   235,   335,   234,
     237,   237,   237,   237,   237,   237,   427,   237,   237,   237,
     237,   237,   237,   237,   235,   417,   237,   237,   235,   444,
     127,   234,   237,   237,   235,   454,   215,   244,   113,   244,
     244,   215,   113,   215,   113,   113,   113,   215,   215,   215,
     244,   113,   113,   113,   113,   244,   113,   113,   113,   113,
     215,   237,   237,   215,   244,   244,   215,   215,   215,   215,
     219,   215,   219,   215,   215,   215,   215,   113,   244,   215,
     244,   244,   215,   113,   234,   234,   237,   237,   378,   237,
     237,   237,   237,   237,   235,   372,   237,   237,   235,   438,
     234,   237,   237,   358,   237,   235,   362,   127,   127,   234,
     234,   237,   237,   235,   287,   234,   237,   237,   329,   237,
     237,   237,   237,   325,   237,   237,   235,   315,   234,   237,
     237,   237,   235,   387,   215,   215,   244,   127,   215,   127,
     215,   215,   215,   234,   113,   127,   215,   127,   237,   127,
     127,   113,   113,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   234,   234,   237,   411,   235,   408,
     215,   234,   236,   234,   237,   237,   237,   237,   235,   293,
     127,   234,   234,   237,   402,   237,   235,   398,   234,   234,
     234,   234,   138,   139,   140,   141,   142,   143,   144,   243,
     244,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   113,   113,   244,   237,   113,   113,   244,   113,   113,
     244,   127,   113,   113,   244,   113,   246,   246,   234,   127,
     182,   183,   127,   215,   127,   127,   237,   127,   127,   113,
     127,   127,   127,   127,   234,   127,   127,   234,   234,   127,
     127,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,    48,   168,   169,
     170,   173,   174,   176,   177,   179,   181,   184,   186,   187,
     192,   196,   200,   201,   202,   207,   212,   507,   508,    48,
      50,    51,   168,   169,   170,   173,   174,   176,   177,   179,
     181,   184,   186,   187,   192,   196,   200,   201,   202,   207,
     212,   503,   504,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   127,   215,   237,   127,   113,   127,
     127,   127,   234,   127,   127,   234,   127,   127,   237,   113,
     365,   366,   234,   234,   234,   127,   127,   234,   127,   215,
     237,   127,   127,   127,   215,   237,   127,   127,   234,   127,
     127,   127,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,    17,    97,   101,   159,
     263,   264,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   127,   237,   234,
     234,     1,   105,   199,   223,   304,   305,   306,   307,   308,
     127,   127,   127,   127,   234,   234,   127,   237,   127,   234,
     243,   243,   243,   243,   243,   243,   243,   234,   234,   234,
      52,   128,   353,   354,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,    11,    12,    13,   245,   246,   234,
     234,   234,   234,   234,   234,   234,   234,   234,     8,   203,
     428,   429,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   238,   234,   238,   234,   234,    15,
      40,    72,   106,   107,   112,   136,   151,   214,   233,   379,
     380,   234,   234,   234,   234,   234,   234,   234,   234,   234,
      48,   194,   203,   359,   360,   222,   238,   364,   234,   234,
     234,   234,     4,    21,    22,    31,    68,    69,    71,   102,
     110,   132,   134,   135,   152,   175,   180,   184,   188,   193,
     197,   208,   210,   211,   213,   224,   232,   330,   331,   234,
     234,   234,   234,    48,    50,    51,   168,   169,   170,   173,
     174,   176,   177,   179,   181,   184,   186,   187,   192,   196,
     200,   201,   202,   207,   212,   326,   327,   234,   234,   234,
     234,   234,   234,   238,   234,    71,   135,   167,   175,   184,
     208,   210,   211,   224,   232,   412,   413,   234,   237,   237,
     309,   235,   305,   234,   234,   234,   234,   234,    71,   135,
     167,   175,   184,   208,   210,   211,   224,   232,   403,   404,
     234,   234,   238,   245,   245,   245,   234,   238,   508,   504,
     234,   238,   234,   238,   113,   366,   234,   239,   239,   239,
     239,   239,   239,   234,   238,   234,   238,   264,   234,   238,
     127,   209,   246,   237,   234,   234,   238,   354,   429,   380,
     360,   133,   135,   133,   135,   133,   133,   331,   327,   413,
     234,   234,   234,    69,    71,   118,   135,   174,   175,   226,
     232,   310,   311,   404,   234,   238,   311
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   240,   241,   241,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   243,   243,
     244,   244,   244,   244,   244,   244,   244,   244,   245,   245,
     246,   246,   246,   246,   247,   248,   248,   249,   249,   249,
     250,   251,   252,   253,   253,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   255,   256,   257,   258,
     259,   260,   262,   261,   263,   263,   264,   264,   264,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   279,   280,   280,   280,   280,
     281,   282,   283,   285,   284,   286,   286,   287,   287,   287,
     288,   289,   291,   290,   292,   292,   293,   293,   293,   293,
     293,   294,   295,   296,   297,   298,   299,   299,   300,   300,
     300,   301,   303,   302,   304,   304,   305,   305,   305,   305,
     306,   307,   307,   309,   308,   310,   310,   311,   311,   311,
     311,   311,   311,   311,   311,   313,   312,   314,   314,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   325,   324,
     326,   326,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   329,   328,   330,   330,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   333,   332,   334,
     334,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   352,   351,   353,   353,   354,   354,   356,
     355,   358,   357,   359,   359,   360,   360,   360,   361,   361,
     362,   362,   362,   362,   362,   364,   363,   365,   365,   366,
     366,   367,   368,   370,   369,   371,   371,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   373,   374,   375,   376,
     378,   377,   379,   379,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   381,   382,   383,   385,   384,   386,
     386,   387,   387,   387,   387,   388,   389,   390,   391,   392,
     392,   393,   393,   394,   396,   395,   397,   397,   398,   398,
     398,   398,   399,   400,   402,   401,   403,   403,   404,   404,
     404,   404,   404,   404,   404,   404,   404,   404,   406,   405,
     407,   407,   408,   408,   408,   409,   411,   410,   412,   412,
     413,   413,   413,   413,   413,   413,   413,   413,   413,   413,
     415,   414,   416,   416,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   425,   427,   426,
     428,   428,   429,   429,   430,   431,   432,   433,   434,   436,
     435,   437,   437,   438,   438,   438,   439,   440,   442,   441,
     443,   443,   444,   444,   444,   445,   446,   447,   448,   448,
     449,   449,   450,   452,   451,   453,   453,   454,   454,   454,
     455,   456,   457,   458,   458,   459,   459,   459,   459,   459,
     459,   459,   459,   459,   459,   459,   459,   459,   459,   459,
     459,   459,   459,   459,   459,   459,   459,   459,   459,   459,
     459,   459,   459,   459,   459,   459,   459,   459,   459,   459,
     459,   459,   459,   459,   459,   459,   459,   459,   459,   459,
     459,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     487,   488,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   502,   501,   503,   503,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   506,   505,   507,   507,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   509,   510,   511,   512,   513,
     513,   514,   514,   514,   514,   514,   514,   514,   514,   514,
     514,   514,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   527,   528,   528,   528,
     528,   528,   528,   528,   528,   528,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537
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
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
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
#line 409 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 410 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 437 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 443 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 479 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_certificate_file);
    ConfigServerInfo.ssl_certificate_file = xstrdup(yylval.string);
  }
}
#line 2979 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 488 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 2991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 497 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_param_file);
    ConfigServerInfo.ssl_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3003 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 506 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_cipher_list);
    ConfigServerInfo.ssl_cipher_list = xstrdup(yylval.string);
  }
}
#line 3015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 515 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_message_digest_algorithm);
    ConfigServerInfo.ssl_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3027 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 524 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_elliptic_curve);
    ConfigServerInfo.ssl_dh_elliptic_curve = xstrdup(yylval.string);
  }
}
#line 3039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 533 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options = 0;
}
#line 3048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 540 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_STANDARD;
#endif
}
#line 3059 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 546 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MEMORY_CACHE;
#endif
}
#line 3070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 552 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MMAP_CACHE;
#endif
}
#line 3081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 558 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_CHECK_CACHE;
#endif
}
#line 3092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 566 "conf_parser.y" /* yacc.c:1646  */
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
#line 3110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 581 "conf_parser.y" /* yacc.c:1646  */
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
#line 3128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 596 "conf_parser.y" /* yacc.c:1646  */
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
#line 3146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 611 "conf_parser.y" /* yacc.c:1646  */
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
#line 3164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 626 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 636 "conf_parser.y" /* yacc.c:1646  */
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
#line 3194 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 650 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 659 "conf_parser.y" /* yacc.c:1646  */
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
#line 3237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 687 "conf_parser.y" /* yacc.c:1646  */
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
#line 3268 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 715 "conf_parser.y" /* yacc.c:1646  */
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
#line 3296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 740 "conf_parser.y" /* yacc.c:1646  */
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
#line 3321 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 762 "conf_parser.y" /* yacc.c:1646  */
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
#line 3346 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 784 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3355 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 802 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 811 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 820 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 833 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 837 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 854 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 860 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 870 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 874 "conf_parser.y" /* yacc.c:1646  */
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
#line 3462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 892 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3471 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 898 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 904 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 910 "conf_parser.y" /* yacc.c:1646  */
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
#line 3510 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 938 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3519 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 944 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 948 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 964 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3552 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 972 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 975 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3568 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 980 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3577 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 987 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3586 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 991 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3595 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 995 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3604 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 999 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3613 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1003 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3622 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1007 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3631 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1011 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3640 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1015 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3661 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1032 "conf_parser.y" /* yacc.c:1646  */
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
#line 3718 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1099 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3727 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1105 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3736 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1111 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3745 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1117 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3754 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1123 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1134 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1140 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1151 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1157 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1164 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1168 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1172 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1176 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1180 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1184 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1188 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1196 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1208 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1216 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1224 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1228 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3971 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3980 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1254 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1261 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4187 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1345 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1349 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1361 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4250 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1365 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4259 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1369 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4268 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1373 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4277 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1383 "conf_parser.y" /* yacc.c:1646  */
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
#line 4294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1395 "conf_parser.y" /* yacc.c:1646  */
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
#line 4341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1458 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1464 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1470 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1476 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4377 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1482 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4386 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1488 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4395 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1494 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4404 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1500 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1506 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1512 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1519 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1525 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1531 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1537 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4471 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1546 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1555 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1562 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4501 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1566 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4510 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1576 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4519 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1582 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4527 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1588 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4536 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1592 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4545 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1596 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4554 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1604 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1609 "conf_parser.y" /* yacc.c:1646  */
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
#line 4578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1622 "conf_parser.y" /* yacc.c:1646  */
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
#line 4598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1639 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1645 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1655 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1659 "conf_parser.y" /* yacc.c:1646  */
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
#line 4670 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1712 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1718 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4688 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1724 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1730 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4711 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1741 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4720 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1748 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4729 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1752 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4738 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1756 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1760 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4756 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1764 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1768 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4774 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1772 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4783 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1776 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1780 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4801 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1784 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1790 "conf_parser.y" /* yacc.c:1646  */
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
#line 4827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1804 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4839 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1813 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4851 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1826 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1833 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1844 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1850 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1856 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1871 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1887 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4932 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1898 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1913 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1919 "conf_parser.y" /* yacc.c:1646  */
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
#line 4978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1938 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4987 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1945 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4996 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1949 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5005 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1953 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1957 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5023 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1961 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1965 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5041 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1969 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5050 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1973 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5059 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1977 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1981 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1991 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5091 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5113 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2019 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5122 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2026 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5131 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2030 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5140 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2038 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5158 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 404:
#line 2042 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5167 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2050 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5185 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5194 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5203 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2062 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2072 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5226 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2081 "conf_parser.y" /* yacc.c:1646  */
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
#line 5292 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2161 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2167 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2173 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2179 "conf_parser.y" /* yacc.c:1646  */
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
#line 5335 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2192 "conf_parser.y" /* yacc.c:1646  */
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
#line 5351 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2205 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2211 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2217 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2227 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5395 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5404 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2237 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2254 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5436 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2260 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5445 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2266 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2272 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5477 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2291 "conf_parser.y" /* yacc.c:1646  */
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
#line 5502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2316 "conf_parser.y" /* yacc.c:1646  */
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
#line 5525 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5534 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2346 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5543 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2350 "conf_parser.y" /* yacc.c:1646  */
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
#line 5569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2376 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2382 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5587 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 472:
#line 2397 "conf_parser.y" /* yacc.c:1646  */
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
#line 5604 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 473:
#line 2414 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5613 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 474:
#line 2418 "conf_parser.y" /* yacc.c:1646  */
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
#line 5633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 480:
#line 2438 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 481:
#line 2444 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2506 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2511 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2516 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2521 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5683 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2526 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5692 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2532 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5700 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2537 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5708 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2542 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5716 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2547 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2552 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2557 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5740 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2562 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5748 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2567 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5756 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2572 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2577 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5772 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2582 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5780 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2587 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5788 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2592 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5796 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2597 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5804 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2602 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5813 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2608 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5821 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2613 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5829 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2618 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2623 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2628 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5853 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2633 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2638 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5869 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2643 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2646 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2651 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2654 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2659 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2664 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2669 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2674 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2679 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5941 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2684 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2689 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2694 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2699 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2704 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2709 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2714 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5997 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2719 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6005 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2725 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6013 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2728 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2731 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2734 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2737 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2740 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2743 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2746 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2749 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2752 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2755 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2758 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2761 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6109 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2764 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2767 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2770 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2773 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6141 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2776 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2779 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6157 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2782 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2785 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2788 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2793 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6189 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2799 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2802 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2805 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2808 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6221 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2811 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2814 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2817 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2820 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6253 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2823 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6261 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2826 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2829 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6277 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2832 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6285 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2835 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6293 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 618:
#line 2838 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 619:
#line 2841 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 620:
#line 2844 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6317 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 621:
#line 2847 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6325 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 622:
#line 2850 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 623:
#line 2853 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2856 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2861 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2871 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2896 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2901 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 2906 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 2911 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 2916 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2921 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6421 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2926 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2931 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2936 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6445 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2941 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 2946 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 668:
#line 2975 "conf_parser.y" /* yacc.c:1646  */
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
#line 6489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 669:
#line 2991 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6501 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 670:
#line 3000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6510 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 671:
#line 3006 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6519 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 672:
#line 3012 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 673:
#line 3018 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6540 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 674:
#line 3027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6549 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 675:
#line 3033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6558 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6562 "conf_parser.c" /* yacc.c:1646  */
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
