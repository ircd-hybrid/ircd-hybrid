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
#define XLINE 487
#define XLINE_EXEMPT 488

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 142 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 691 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 708 "conf_parser.c" /* yacc.c:358  */

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
    1349,  1353,  1357,  1361,  1365,  1369,  1373,  1384,  1383,  1440,
    1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,
    1450,  1451,  1452,  1453,  1453,  1454,  1455,  1456,  1457,  1459,
    1465,  1471,  1477,  1483,  1489,  1495,  1501,  1507,  1513,  1519,
    1526,  1532,  1538,  1544,  1553,  1563,  1562,  1568,  1568,  1569,
    1573,  1584,  1583,  1590,  1589,  1594,  1594,  1595,  1599,  1603,
    1609,  1609,  1610,  1610,  1610,  1610,  1610,  1612,  1612,  1614,
    1614,  1616,  1629,  1646,  1652,  1663,  1662,  1708,  1708,  1709,
    1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,  1719,  1725,
    1731,  1737,  1749,  1748,  1754,  1754,  1755,  1759,  1763,  1767,
    1771,  1775,  1779,  1783,  1787,  1791,  1797,  1811,  1820,  1834,
    1833,  1848,  1848,  1849,  1849,  1849,  1849,  1851,  1857,  1863,
    1873,  1875,  1875,  1876,  1876,  1878,  1895,  1894,  1917,  1917,
    1918,  1918,  1918,  1918,  1920,  1926,  1946,  1945,  1951,  1951,
    1952,  1956,  1960,  1964,  1968,  1972,  1976,  1980,  1984,  1988,
    1999,  1998,  2017,  2017,  2018,  2018,  2018,  2020,  2027,  2026,
    2032,  2032,  2033,  2037,  2041,  2045,  2049,  2053,  2057,  2061,
    2065,  2069,  2080,  2079,  2151,  2151,  2152,  2153,  2154,  2155,
    2156,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,
    2166,  2168,  2174,  2180,  2186,  2199,  2212,  2218,  2224,  2228,
    2235,  2234,  2239,  2239,  2240,  2244,  2250,  2261,  2267,  2273,
    2279,  2295,  2294,  2320,  2320,  2321,  2321,  2321,  2323,  2343,
    2354,  2353,  2380,  2380,  2381,  2381,  2381,  2383,  2389,  2399,
    2401,  2401,  2402,  2402,  2404,  2422,  2421,  2442,  2442,  2443,
    2443,  2443,  2445,  2451,  2461,  2463,  2463,  2464,  2465,  2466,
    2467,  2468,  2469,  2470,  2471,  2472,  2473,  2474,  2475,  2476,
    2477,  2478,  2479,  2480,  2481,  2482,  2483,  2484,  2485,  2486,
    2487,  2488,  2489,  2490,  2491,  2492,  2493,  2494,  2495,  2496,
    2497,  2498,  2499,  2500,  2501,  2502,  2503,  2504,  2505,  2506,
    2507,  2508,  2509,  2512,  2517,  2522,  2527,  2533,  2538,  2543,
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
    2893,  2894,  2895,  2897,  2902,  2907,  2912,  2917,  2922,  2927,
    2932,  2937,  2942,  2947,  2956,  2958,  2958,  2959,  2960,  2961,
    2962,  2963,  2964,  2965,  2966,  2967,  2968,  2970,  2976,  2992,
    3001,  3007,  3013,  3019,  3028,  3034
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
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "XLINE", "XLINE_EXEMPT", "';'", "'}'",
  "'{'", "'='", "','", "':'", "$accept", "conf", "conf_item", "timespec_",
  "timespec", "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_ssl_certificate_file",
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
  "general_away_time", "general_max_watch", "general_cycle_on_host_change",
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

#define YYPACT_NINF -1024

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1024)))

#define YYTABLE_NINF -143

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1024,   697, -1024,  -192,  -218,  -216, -1024, -1024, -1024,  -208,
   -1024,  -206, -1024, -1024, -1024,  -182, -1024, -1024, -1024,  -176,
    -173, -1024,  -158, -1024,  -137, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024,   330,   814,  -131,  -126,  -104,    37,  -101,   434,   -99,
     -76,   -68,    63,   -60,   -54,   -32,   764,   552,   -31,     9,
     -30,    24,   -29,   -13,   -15,   -14,    -6,    78, -1024, -1024,
   -1024, -1024, -1024,    17,    41,    53,    60,    65,    95,   103,
     108,   115,   116,   127,     6, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024,   766,   615,    33,
   -1024,   132,    11, -1024, -1024,    28, -1024,   141,   143,   148,
     150,   155,   157,   172,   174,   175,   180,   182,   183,   184,
     186,   188,   192,   195,   197,   200,   201,   202,   205,   210,
     212,   215, -1024, -1024,   216,   217,   218,   219,   220,   223,
     224,   225,   226,   227,   231,   235,   236,   237,   238,   240,
     241,   242,    52, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,   299,
      69,    40,    55,   243,   244,    20, -1024, -1024, -1024,    10,
     260,    97, -1024,   245,   247,   248,   249,   251,   252,   258,
     259,   261,     2, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024,    81,   262,   263,   264,   266, -1024,   268,
     272,   273,   274,   275,   277,   279,   280,   282,   283,   284,
     286,   291,   293,   296,   153, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024,   119,   123,   300,    16,
   -1024, -1024, -1024,    61,   189, -1024,   301,    13, -1024, -1024,
      79, -1024,   234,   239,   265,   194, -1024,   401,   422,   323,
     426,   422,   422,   428,   422,   422,   430,   431,   313, -1024,
     314,   312,   327,   329, -1024,   332,   334,   335,   336,   338,
     339,   340,   341,   342,   346,   348,   349,   352,   178, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024,   316,   353,   354,
     355,   357,   366,   368, -1024,   369,   374,   375,   376,   377,
     378,   380,   278, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,   384,
     385,    21, -1024, -1024, -1024,   446,   359, -1024, -1024,   386,
     387,    18, -1024, -1024, -1024,   409,   422,   512,   422,   422,
     412,   515,   414,   520,   522,   523,   423,   424,   425,   422,
     524,   529,   531,   532,   422,   533,   535,   543,   546,   447,
     429,   432,   452,   422,   422,   454,   461,   462,  -193,  -185,
     463,   464,   466,   468,   571,   422,   470,   422,   422,   471,
     455, -1024,   457,   451,   458, -1024,   459,   467,   475,   477,
     481,   191, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024,   485,   488,    25, -1024, -1024, -1024,   460,   490,
     492, -1024,   493, -1024,    51, -1024, -1024, -1024, -1024, -1024,
     577,   579,   465, -1024,   474,   494,   495,   156, -1024, -1024,
   -1024,   500,   498,   499, -1024,   502,   503,   504,   508, -1024,
     509,   510,   120, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024,   518,   517,   519,   521,    73, -1024,
   -1024, -1024, -1024,   544,   547,   422,   621,   553,   627,   556,
     557,   558,   525, -1024, -1024,   654,   647,   560,   649,   541,
     655,   658,   668,   673,   664,   665,   666,   667,   669,   671,
     672,   675,   676,   677,   678,   562, -1024,   576,   574, -1024,
      94, -1024, -1024, -1024, -1024,   598,   587, -1024,   586,   589,
     588,   590,   591,   592,     3, -1024, -1024, -1024, -1024, -1024,
     696,   596, -1024,   597,   601, -1024,   602,    23, -1024, -1024,
   -1024, -1024,   608,   610,   614, -1024,   616,   232,   617,   623,
     624,   625,   628,   629,   630,   632,   633,   634, -1024, -1024,
     712,   721,   422,   612,   747,   755,   757,   422,   759,   765,
     422,   750,   770,   771,   422,   772,   772,   646, -1024, -1024,
     767,  -135,   769,   682,   773,   774,   650,   775,   776,   780,
     777,   778,   779,   784,   674, -1024,   788,   791,   687, -1024,
     689, -1024,   796,   798,   695, -1024,   698,   700,   701,   702,
     704,   705,   706,   710,   711,   713,   715,   716,   717,   718,
     720,   725,   728,   731,   733,   735,   736,   738,   741,   742,
     743,   826,   740,   744,   746,   748,   751,   752,   756,   758,
     768,   781,   782,   783,   787,   790,   792,   797,   799,   801,
     802,   803,   804, -1024, -1024,   818,   714,   694,   853,   870,
     863,   865,   877,   806, -1024,   879,   881,   807, -1024, -1024,
     882,   884,   761,   904,   808, -1024,   809,   810, -1024, -1024,
     892,   894,   811, -1024, -1024,   897,   816,   793,   918,   919,
     920,   833,   813,   923,   924,   819, -1024, -1024,   926,   927,
     928,   823, -1024,   824,   825,   827,   828,   829,   830,   831,
     832,   834, -1024,   835,   836,   837,   838,    48,   839,   840,
     841,   842,   843,   844,   845,   846,   847,   848,   849,   850,
     851,   852,   854, -1024, -1024,   932,   855,   856, -1024,   857,
   -1024,   130, -1024,   939,   959,   961,   965,   860, -1024,   861,
   -1024, -1024,   968,   862,   969,   864, -1024, -1024, -1024, -1024,
   -1024,   422,   422,   422,   422,   422,   422,   422, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
     866,   867,   868,   -39,   869,   871,   872,   873,   874,   875,
     876,   878,   880,   883,   885,   337,   886,   887, -1024,   888,
     889,   890,   891,   893,   895,   896,     8,   898,   899,   900,
     901,   902,   903,   905, -1024,   906,   907, -1024, -1024,   908,
     909, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024,  -194, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024,   -73, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024,   910,   911,   450,   912,   913,   914,   915,
     916, -1024,   917,   921, -1024,   922,   925,   -33,   929,   930,
   -1024, -1024, -1024, -1024,   931,   933, -1024,   935,   936,   539,
     937,   938,   940,   941,   786,   942,   943, -1024,   944,   945,
     946, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,   -40,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024,   947,   356, -1024, -1024,
     948,   949,   950, -1024,    85, -1024, -1024, -1024, -1024,   951,
     954,   955,   956, -1024, -1024,   957,   491,   958, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024,   -10, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024,   772,   772,   772, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
      54, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024,   826, -1024,   740, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,    67,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024,    99, -1024,   990,   904,   960, -1024, -1024,
   -1024, -1024, -1024, -1024,   934, -1024,   962,   963, -1024, -1024,
     964,   966, -1024, -1024,   967, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024,   125, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024,   152, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024,    48, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024,   169, -1024, -1024,   983,   -77,
     970,   974, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,   170, -1024,
   -1024, -1024,   -39, -1024, -1024, -1024, -1024,     8, -1024, -1024,
   -1024,   450, -1024,   -33, -1024, -1024, -1024,   979,   980,   981,
     982,   992,   994, -1024,   539, -1024,   786, -1024, -1024,   356,
     975,   976,   977,   270, -1024, -1024,   491, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024,   176, -1024, -1024, -1024,   270, -1024
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
     108,   107,   642,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   630,   641,   632,   633,   634,
     635,   636,   637,   638,   631,   639,   640,     0,     0,     0,
     473,     0,     0,   471,   472,     0,   532,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   601,   575,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   486,   487,   488,   530,   531,   525,   526,
     527,   528,   524,   498,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   499,   500,   529,   504,   505,   506,   507,
     503,   502,   508,   515,   516,   509,   510,   511,   501,   513,
     522,   523,   520,   521,   514,   512,   518,   519,   517,     0,
       0,     0,     0,     0,     0,     0,    46,    47,    48,     0,
       0,     0,   666,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   656,   657,   658,   659,   660,   661,   662,
     664,   663,   665,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    69,    66,    64,    70,
      71,    65,    72,    73,    74,    55,    68,    58,    59,    60,
      56,    67,    61,    62,    63,    57,     0,     0,     0,     0,
     137,   138,   139,     0,     0,   364,     0,     0,   362,   363,
       0,   109,     0,     0,     0,     0,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   629,
       0,     0,     0,     0,   285,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
     251,   254,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   252,   253,   255,   265,   266,   267,     0,     0,     0,
       0,     0,     0,     0,   440,     0,     0,     0,     0,     0,
       0,     0,     0,   415,   416,   417,   418,   419,   420,   421,
     423,   422,   425,   429,   426,   427,   428,   424,   466,     0,
       0,     0,   463,   464,   465,     0,     0,   470,   481,     0,
       0,     0,   478,   479,   480,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   485,     0,     0,     0,   332,     0,     0,     0,     0,
       0,     0,   318,   319,   320,   321,   326,   322,   323,   324,
     325,   457,     0,     0,     0,   454,   455,   456,     0,     0,
       0,   293,     0,   303,     0,   301,   302,   304,   305,    49,
       0,     0,     0,    45,     0,     0,     0,     0,   116,   117,
     118,     0,     0,     0,   214,     0,     0,     0,     0,   188,
       0,     0,     0,   168,   169,   170,   171,   172,   175,   176,
     177,   174,   173,   178,     0,     0,     0,     0,     0,   352,
     353,   354,   355,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   655,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,     0,   398,
       0,   393,   394,   395,   140,     0,     0,   136,     0,     0,
       0,     0,     0,     0,     0,   125,   126,   128,   127,   129,
       0,     0,   361,     0,     0,   376,     0,     0,   369,   370,
     371,   372,     0,     0,     0,   103,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   628,   268,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   249,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   414,     0,     0,     0,   462,
       0,   469,     0,     0,     0,   477,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,   327,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   317,     0,     0,     0,   453,   306,
       0,     0,     0,     0,     0,   300,     0,     0,    44,   119,
       0,     0,     0,   115,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   356,     0,     0,
       0,     0,   351,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   654,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,   396,     0,     0,     0,   392,     0,
     135,     0,   130,     0,     0,     0,     0,     0,   124,     0,
     360,   373,     0,     0,     0,     0,   368,   112,   111,   110,
     652,    28,    28,    28,    28,    28,    28,    28,    30,    29,
     653,   643,   644,   645,   646,   647,   648,   649,   651,   650,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,   248,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   413,     0,     0,   461,   474,     0,
       0,   476,   545,   549,   533,   534,   564,   536,   627,   572,
     537,   538,   569,   544,   543,   552,   542,   539,   540,   548,
     547,   546,   570,   535,   625,   626,   568,   611,   605,   621,
     606,   607,   608,   616,   624,   609,   618,   622,   612,   623,
     613,   617,   610,   620,   615,   614,   619,     0,   604,   584,
     585,   586,   579,   597,   580,   581,   582,   592,   600,   583,
     594,   598,   588,   599,   589,   593,   587,   596,   591,   590,
     595,     0,   578,   565,   563,   566,   571,   567,   554,   561,
     562,   559,   560,   555,   556,   557,   558,   573,   574,   541,
     551,   550,   553,     0,     0,     0,     0,     0,     0,     0,
       0,   316,     0,     0,   452,     0,     0,     0,   311,   307,
     310,   292,    50,    51,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,     0,     0,
       0,   350,   670,   667,   668,   669,   674,   673,   675,   671,
     672,    99,    94,   102,    93,    89,    87,    88,    86,     0,
      85,    90,    91,   100,   101,    92,    96,    95,    77,    76,
      81,    78,    80,    79,    97,    98,     0,     0,   391,   141,
       0,     0,     0,   153,     0,   145,   146,   148,   147,     0,
       0,     0,     0,   123,   365,     0,     0,     0,   367,    31,
      32,    33,    34,    35,    36,    37,   280,   281,   272,   290,
     289,     0,   288,   273,   275,   277,   284,   276,   274,   283,
     269,   282,   271,   270,    38,    38,    38,    40,    39,   278,
     279,   435,   438,   439,   449,   446,   432,   447,   444,   445,
       0,   443,   448,   431,   437,   434,   436,   450,   433,   467,
     468,   482,   483,   602,     0,   576,     0,   330,   331,   341,
     337,   338,   340,   345,   342,   343,   336,   344,   339,     0,
     335,   329,   348,   347,   346,   328,   459,   458,   314,   313,
     298,   299,   297,     0,   296,     0,     0,     0,   120,   121,
     187,   184,   234,   246,   221,   230,     0,   219,   224,   240,
       0,   233,   238,   244,   223,   226,   235,   237,   241,   231,
     239,   227,   245,   229,   236,   225,   228,     0,   217,   180,
     182,   185,   186,   197,   198,   199,   192,   210,   193,   194,
     195,   205,   213,   196,   207,   211,   201,   212,   202,   206,
     200,   209,   204,   203,   208,     0,   191,   181,   183,   359,
     357,   358,    83,     0,   397,   402,   408,   411,   404,   410,
     405,   409,   407,   403,   406,     0,   401,   149,     0,     0,
       0,     0,   144,   132,   131,   133,   134,   374,   380,   386,
     389,   382,   388,   383,   387,   385,   381,   384,     0,   379,
     375,   286,     0,    41,    42,    43,   441,     0,   603,   577,
     333,     0,   294,     0,   312,   309,   308,     0,     0,     0,
       0,     0,     0,   215,     0,   189,     0,    84,   399,     0,
       0,     0,     0,     0,   143,   377,     0,   287,   442,   334,
     295,   220,   243,   218,   242,   232,   222,   216,   190,   400,
     150,   152,   151,   163,   162,   158,   160,   164,   161,   157,
     159,     0,   156,   378,   154,     0,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1024, -1024, -1024,  -425,  -306, -1023,  -635, -1024, -1024,   978,
   -1024, -1024, -1024, -1024,   952, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024,   -92, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
    1061, -1024, -1024, -1024, -1024, -1024, -1024,   656, -1024, -1024,
   -1024, -1024, -1024,   570, -1024, -1024, -1024, -1024, -1024, -1024,
     953, -1024, -1024, -1024, -1024,   104, -1024, -1024, -1024, -1024,
   -1024,  -168, -1024, -1024, -1024,   648, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024,  -125, -1024, -1024,
   -1024,  -122, -1024, -1024, -1024,   858, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024,   -98, -1024, -1024, -1024, -1024,
   -1024,  -110, -1024,   699, -1024, -1024, -1024,    39, -1024, -1024,
   -1024, -1024, -1024,   723, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024,  -105, -1024, -1024, -1024, -1024, -1024, -1024,   670, -1024,
   -1024, -1024, -1024, -1024,   971, -1024, -1024, -1024, -1024,   600,
   -1024, -1024, -1024, -1024, -1024,   -97, -1024, -1024, -1024,   642,
   -1024, -1024, -1024, -1024,   -89, -1024, -1024, -1024,   859, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
     -63, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,   739,
   -1024, -1024, -1024, -1024, -1024,   972, -1024, -1024, -1024, -1024,
    1102, -1024, -1024, -1024, -1024,   817, -1024, -1024, -1024, -1024,
    1053, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024,    91, -1024, -1024, -1024,    96, -1024,
   -1024, -1024, -1024, -1024,  1125, -1024, -1024, -1024, -1024, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024,   989, -1024,
   -1024, -1024, -1024, -1024, -1024, -1024, -1024, -1024
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   828,   829,  1097,  1098,    27,   215,   216,
     217,   218,    28,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   549,  1029,  1030,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,    29,    77,
      78,    79,    80,    81,    30,    63,   497,   498,   499,   500,
      31,    70,   584,   585,   586,   587,   588,   589,    32,   289,
     290,   291,   292,   293,  1054,  1055,  1056,  1057,  1058,  1240,
    1321,  1322,    33,    64,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   752,  1215,  1216,   523,   747,
    1187,  1188,    34,    53,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   623,  1081,  1082,    35,    61,   483,   732,
    1153,  1154,   484,   485,   486,  1157,   989,   990,   487,   488,
      36,    59,   461,   462,   463,   464,   465,   466,   467,   717,
    1139,  1140,   468,   469,   470,    37,    65,   528,   529,   530,
     531,   532,    38,   297,   298,   299,    39,    72,   597,   598,
     599,   600,   601,   813,  1258,  1259,    40,    68,   570,   571,
     572,   573,   796,  1235,  1236,    41,    54,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   646,  1110,
    1111,   383,   384,   385,   386,   387,    42,    60,   474,   475,
     476,   477,    43,    55,   391,   392,   393,   394,    44,   112,
     113,   114,    45,    57,   401,   402,   403,   404,    46,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   431,   951,   952,   205,   430,   927,   928,   206,
     207,   208,    47,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    48,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     856,   857,   608,   222,   579,   611,   612,    82,   614,   615,
     287,   494,   110,  1079,   295,  1150,  1108,   287,    51,   398,
      52,   212,   388,   699,   593,   295,   471,   700,    56,   398,
      58,   701,    83,    84,   388,   702,   223,   855,   110,    85,
    1123,   478,    49,    50,  1124,   224,   225,   226,   860,   861,
     227,   228,   478,   116,    62,   229,   230,   231,   117,   118,
      66,   119,   120,    67,   212,  1025,   121,    86,    87,    88,
     471,  1263,  1264,  1265,   524,   111,   122,   123,    69,    73,
     593,    89,    90,    91,   124,   389,  1050,   125,   126,   127,
    1080,    92,    93,   495,   128,   567,   479,   389,   524,    71,
     667,   111,   669,   670,   480,   107,   481,   479,    74,   580,
     108,   129,   130,   680,   525,   480,    75,   481,   685,   296,
     567,   501,   131,   213,   399,   132,   133,   694,   695,   594,
     296,  1050,   109,  1291,   399,   115,   134,   209,   525,   708,
     502,   710,   711,   135,   214,   136,  1026,   137,   400,   138,
    1027,   390,   139,   140,   243,   472,   526,   494,   400,   503,
     210,  1125,  1151,   390,   141,  1126,   213,   482,   211,   142,
     143,  1152,   144,   145,   146,   581,   219,   147,   482,   320,
     526,   244,   220,   245,    76,   594,   504,   214,  -142,   496,
     579,  1051,   452,   582,  1222,  -142,   321,   322,  1223,   472,
     568,   323,   148,   527,   221,   286,   294,   300,  1028,   583,
     246,   453,  1109,   149,   150,   151,   152,   153,   154,   155,
     247,   301,   302,   303,  1261,   568,   505,   527,  1262,   765,
     454,   304,   248,   249,   250,   288,  1051,   542,   807,   495,
     578,   318,   288,   506,   324,   251,   396,   595,   591,   252,
     596,   576,   473,   664,   307,   492,   658,   455,   815,   253,
     727,   501,   254,   255,   325,   326,   327,   328,   329,   156,
     157,   158,   330,   159,   160,   507,   508,   331,   308,   357,
     502,   358,   161,   359,   332,  1052,   734,   450,  1266,   489,
     309,   256,  1267,   333,   334,   580,   473,   310,   360,   503,
     452,  1270,   311,   595,   335,  1271,   596,   257,   761,  1053,
     258,   259,   260,   305,   456,   544,   842,   361,   569,   453,
    1241,   847,   457,   458,   850,   336,   504,   509,   854,   797,
    1052,    73,   312,  1272,   362,   496,   363,  1273,   454,  1313,
     313,  1314,   459,   569,   364,   314,   607,   510,  1094,  1095,
    1096,   511,   315,   316,  1053,   755,   365,   574,   261,  1283,
      74,   581,   602,  1284,   317,   455,   505,   603,    75,   395,
     337,   821,   822,   823,   824,   825,   826,   827,   405,   582,
     406,   262,   263,   506,   366,   407,  1285,   408,   565,  1315,
    1286,   742,   409,   604,   410,   583,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1288,  1295,   367,  1316,  1289,  1296,   411,
    1324,   412,   413,   637,  1325,   507,   508,   414,   460,   415,
     416,   417,   456,   418,   368,   419,   723,  1225,   605,   420,
     457,   458,   421,   369,   422,   116,    76,   423,   424,   425,
     117,   118,   426,   119,   120,  1317,  1318,   427,   121,   428,
     459,   855,   429,   432,   433,   434,   435,   436,   122,   123,
     437,   438,   439,   440,   441,  1129,   124,   509,   442,   125,
     126,   127,   443,   444,   445,   446,   128,   447,   448,   449,
     490,   491,   533,   370,   534,   535,   536,   510,   537,   538,
    1130,   511,  1226,   129,   130,   539,   540,  1319,   541,   545,
     546,   547,  1320,   548,   131,   550,   371,   132,   133,   551,
     552,   553,   554,   654,   555,   606,   556,   557,   134,   558,
     559,   560,  1131,   561,  1227,   135,   460,   136,   562,   137,
     563,   138,  1228,   564,   139,   140,   607,   575,   590,   609,
     610,  1229,   613,  1162,   616,   617,   141,   618,   619,   620,
     639,   142,   143,   243,   144,   145,   146,  1132,  1133,   147,
    1163,  1164,  1248,  1134,   621,  1230,   622,  1231,  1232,   624,
    1165,   625,   626,   627,   660,   628,   629,   630,   631,   632,
     244,  1233,   245,   633,   148,   634,   635,  1135,  1234,   636,
     640,   641,   642,   661,   643,   149,   150,   151,   152,   153,
     154,   155,  1136,   644,  1292,   645,   647,  1166,  1167,   246,
    1168,   648,   649,   650,   651,   652,   357,   653,   358,   247,
     359,   656,   657,   662,   663,   666,   668,  1249,   671,   672,
     673,   248,   249,   250,   674,   360,   675,   676,   681,   677,
     678,   679,  1169,   682,   251,   683,   684,   686,   252,   687,
    1170,   156,   157,   158,   361,   159,   160,   688,   253,  1250,
     689,   254,   255,   690,   161,  1137,   691,  1251,   693,   692,
     696,   362,  1171,   363,  1172,  1173,  1252,   697,   698,   703,
     704,   364,   705,  1138,   706,   707,   709,   712,   715,   713,
     256,   714,  1174,   365,   729,   716,   718,     2,     3,   738,
    1253,     4,  1254,  1255,   719,   736,   257,   737,   739,   258,
     259,   260,   720,     5,   721,  1175,  1256,     6,   722,     7,
    1176,   366,   725,  1257,  1177,   726,     8,   730,  1178,   731,
     733,   740,   741,  1179,   744,   745,   746,  1180,     9,   748,
     749,   750,   367,    10,    11,   751,   753,   754,  1181,   766,
    1182,  1183,   757,  1184,   758,   768,   759,   261,   760,   772,
     763,   368,    12,   764,  1185,   222,    13,   320,   773,   767,
     369,  1186,   769,   770,   771,   774,   775,   776,   777,    14,
     262,   263,   780,   778,   321,   322,   779,   781,   929,   323,
     930,   931,   782,   783,   784,   785,   793,   786,   223,   787,
     788,    15,    16,   789,   790,   791,   792,   224,   225,   226,
     794,   795,   227,   228,   799,    82,    17,   229,   230,   231,
     370,   800,   801,   802,   809,   803,   840,   804,   805,   806,
     810,   811,   324,    18,  1193,   841,  1194,  1195,   812,   814,
      83,    84,   817,   371,   818,    19,    20,    85,   819,   843,
     820,   830,   325,   326,   327,   328,   329,   831,   832,   833,
     330,   844,   834,   835,   836,   331,   837,   838,   839,   845,
      21,   846,   332,   848,   907,    86,    87,    88,   851,   849,
     858,   333,   334,    22,   852,   853,   855,   866,    23,    89,
      90,    91,   335,    24,   869,   859,    25,   862,   863,    92,
      93,   864,   865,   867,   868,   870,   871,   872,   874,   932,
     933,   934,   873,   336,   935,   936,   875,   937,   938,   876,
     939,   877,   940,   878,   879,   941,   880,   942,   943,   881,
     974,   975,   882,   944,   883,   884,   885,   945,   886,   887,
     888,   946,   947,   948,   889,   890,   973,   891,   949,   892,
     893,   894,   895,   950,   896,  1196,  1197,  1198,   337,   897,
    1199,  1200,   898,  1201,  1202,   899,  1203,   900,  1204,   901,
     902,  1205,   903,  1206,  1207,   904,   905,   906,   953,  1208,
     954,   976,   955,  1209,   977,   956,   957,  1210,  1211,  1212,
     958,   978,   959,   979,  1213,   908,   909,   910,   987,  1214,
     911,   912,   960,   913,   914,   980,   915,   982,   916,   983,
     985,   917,   986,   918,   919,   961,   962,   963,   988,   920,
     994,   964,   995,   921,   965,   997,   966,   922,   923,   924,
     999,   967,   998,   968,   925,   969,   970,   971,   972,   926,
     981,   984,   991,   992,   993,   996,  1000,  1001,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,
    1046,  1014,  1015,  1016,  1017,  1018,  1019,  1059,  1020,  1021,
    1022,  1023,  1024,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1060,  1045,  1061,
    1048,  1049,  1047,  1062,  1063,  1064,  1065,  1067,  1068,  1066,
    1076,  1077,  1078,  1083,  1274,  1084,  1085,  1086,  1087,  1088,
    1089,  1290,  1090,  1301,  1091,  1303,  1302,  1092,  1304,  1093,
    1099,  1100,  1101,  1102,  1103,  1104,  1305,  1105,  1306,  1106,
    1107,  1287,  1112,  1113,  1114,  1115,  1116,  1117,   306,  1118,
    1119,  1120,  1121,  1122,  1127,  1128,  1141,  1142,  1143,  1144,
    1145,  1146,  1155,   743,   808,  1147,  1148,  1326,  1242,  1149,
     756,  1308,  1307,  1300,  1297,  1158,  1299,  1159,  1156,  1160,
    1161,  1189,  1190,  1277,  1191,  1192,  1217,  1218,  1219,  1220,
    1221,  1224,  1237,   735,   724,  1243,  1238,  1239,  1244,  1245,
    1246,  1247,  1260,   493,  1276,  1275,   638,   816,   762,  1323,
    1309,  1278,  1279,  1280,  1298,  1281,  1282,  1293,  1294,  1310,
    1311,  1312,   798,   728,   397,   451,   566,  1269,   665,   319,
    1268,   543,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   655,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   577,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   592,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   659
};

static const yytype_int16 yycheck[] =
{
     635,   636,   308,     1,     1,   311,   312,     1,   314,   315,
       1,     1,     1,    52,     1,    48,     8,     1,   236,     1,
     236,     1,     1,   216,     1,     1,     1,   220,   236,     1,
     236,   216,    26,    27,     1,   220,    34,   114,     1,    33,
     234,     1,   234,   235,   238,    43,    44,    45,   183,   184,
      48,    49,     1,     1,   236,    53,    54,    55,     6,     7,
     236,     9,    10,   236,     1,    17,    14,    61,    62,    63,
       1,  1094,  1095,  1096,     1,    64,    24,    25,   236,     1,
       1,    75,    76,    77,    32,    64,     1,    35,    36,    37,
     129,    85,    86,    83,    42,     1,    56,    64,     1,   236,
     406,    64,   408,   409,    64,   236,    66,    56,    30,   106,
     236,    59,    60,   419,    41,    64,    38,    66,   424,   106,
       1,     1,    70,   103,   106,    73,    74,   433,   434,   106,
     106,     1,   236,   210,   106,   236,    84,   236,    41,   445,
      20,   447,   448,    91,   124,    93,    98,    95,   130,    97,
     102,   130,   100,   101,     1,   130,    83,     1,   130,    39,
     236,   234,   195,   130,   112,   238,   103,   127,   236,   117,
     118,   204,   120,   121,   122,   172,   236,   125,   127,     1,
      83,    28,   236,    30,   106,   106,    66,   124,   179,   179,
       1,   106,     1,   190,   234,   179,    18,    19,   238,   130,
     106,    23,   150,   130,   236,   236,   236,   236,   160,   206,
      57,    20,   204,   161,   162,   163,   164,   165,   166,   167,
      67,   234,   237,   237,   234,   106,   106,   130,   238,   535,
      39,   237,    79,    80,    81,   226,   106,   235,   235,    83,
     179,   235,   226,   123,    66,    92,   235,   224,   235,    96,
     227,   235,   227,   235,   237,   235,   235,    66,   235,   106,
     235,     1,   109,   110,    86,    87,    88,    89,    90,   217,
     218,   219,    94,   221,   222,   155,   156,    99,   237,     1,
      20,     3,   230,     5,   106,   200,   235,   235,   234,   234,
     237,   138,   238,   115,   116,   106,   227,   237,    20,    39,
       1,   234,   237,   224,   126,   238,   227,   154,   235,   224,
     157,   158,   159,   235,   123,   234,   622,    39,   224,    20,
     235,   627,   131,   132,   630,   147,    66,   207,   634,   235,
     200,     1,   237,   234,    56,   179,    58,   238,    39,    69,
     237,    71,   151,   224,    66,   237,   114,   227,    11,    12,
      13,   231,   237,   237,   224,   235,    78,   234,   205,   234,
      30,   172,   128,   238,   237,    66,   106,   128,    38,   237,
     192,   139,   140,   141,   142,   143,   144,   145,   237,   190,
     237,   228,   229,   123,   106,   237,   234,   237,   235,   119,
     238,   235,   237,   128,   237,   206,   821,   822,   823,   824,
     825,   826,   827,   234,   234,   127,   136,   238,   238,   237,
     234,   237,   237,   235,   238,   155,   156,   237,   227,   237,
     237,   237,   123,   237,   146,   237,   235,    71,   234,   237,
     131,   132,   237,   155,   237,     1,   106,   237,   237,   237,
       6,     7,   237,     9,    10,   175,   176,   237,    14,   237,
     151,   114,   237,   237,   237,   237,   237,   237,    24,    25,
     237,   237,   237,   237,   237,    15,    32,   207,   237,    35,
      36,    37,   237,   237,   237,   237,    42,   237,   237,   237,
     237,   237,   237,   205,   237,   237,   237,   227,   237,   237,
      40,   231,   136,    59,    60,   237,   237,   227,   237,   237,
     237,   237,   232,   237,    70,   237,   228,    73,    74,   237,
     237,   237,   237,   235,   237,   114,   237,   237,    84,   237,
     237,   237,    72,   237,   168,    91,   227,    93,   237,    95,
     237,    97,   176,   237,   100,   101,   114,   237,   237,   216,
     114,   185,   114,     4,   114,   114,   112,   234,   234,   237,
     234,   117,   118,     1,   120,   121,   122,   107,   108,   125,
      21,    22,    71,   113,   237,   209,   237,   211,   212,   237,
      31,   237,   237,   237,   128,   237,   237,   237,   237,   237,
      28,   225,    30,   237,   150,   237,   237,   137,   232,   237,
     237,   237,   237,   234,   237,   161,   162,   163,   164,   165,
     166,   167,   152,   237,  1239,   237,   237,    68,    69,    57,
      71,   237,   237,   237,   237,   237,     1,   237,     3,    67,
       5,   237,   237,   237,   237,   216,   114,   136,   216,   114,
     216,    79,    80,    81,   114,    20,   114,   114,   114,   216,
     216,   216,   103,   114,    92,   114,   114,   114,    96,   114,
     111,   217,   218,   219,    39,   221,   222,   114,   106,   168,
     114,   109,   110,   216,   230,   215,   237,   176,   216,   237,
     216,    56,   133,    58,   135,   136,   185,   216,   216,   216,
     216,    66,   216,   233,   216,   114,   216,   216,   237,   234,
     138,   234,   153,    78,   234,   237,   237,     0,     1,   234,
     209,     4,   211,   212,   237,   128,   154,   128,   234,   157,
     158,   159,   237,    16,   237,   176,   225,    20,   237,    22,
     181,   106,   237,   232,   185,   237,    29,   237,   189,   237,
     237,   237,   237,   194,   234,   237,   237,   198,    41,   237,
     237,   237,   127,    46,    47,   237,   237,   237,   209,   128,
     211,   212,   234,   214,   237,   128,   237,   205,   237,   234,
     216,   146,    65,   216,   225,     1,    69,     1,   114,   216,
     155,   232,   216,   216,   216,   128,   216,   128,   237,    82,
     228,   229,   114,   128,    18,    19,   128,   114,    48,    23,
      50,    51,   128,   128,   128,   128,   234,   128,    34,   128,
     128,   104,   105,   128,   128,   128,   128,    43,    44,    45,
     234,   237,    48,    49,   216,     1,   119,    53,    54,    55,
     205,   234,   236,   234,   128,   237,   114,   237,   237,   237,
     234,   234,    66,   136,    48,   114,    50,    51,   237,   237,
      26,    27,   234,   228,   234,   148,   149,    33,   234,   237,
     234,   234,    86,    87,    88,    89,    90,   234,   234,   234,
      94,   114,   234,   234,   234,    99,   234,   234,   234,   114,
     173,   114,   106,   114,    48,    61,    62,    63,   128,   114,
     234,   115,   116,   186,   114,   114,   114,   237,   191,    75,
      76,    77,   126,   196,   114,   128,   199,   128,   216,    85,
      86,   128,   128,   128,   128,   128,   128,   128,   234,   169,
     170,   171,   128,   147,   174,   175,   128,   177,   178,   128,
     180,   234,   182,   234,   128,   185,   128,   187,   188,   234,
     216,   237,   234,   193,   234,   234,   234,   197,   234,   234,
     234,   201,   202,   203,   234,   234,   128,   234,   208,   234,
     234,   234,   234,   213,   234,   169,   170,   171,   192,   234,
     174,   175,   234,   177,   178,   234,   180,   234,   182,   234,
     234,   185,   234,   187,   188,   234,   234,   234,   234,   193,
     234,   128,   234,   197,   114,   234,   234,   201,   202,   203,
     234,   128,   234,   128,   208,   169,   170,   171,   237,   213,
     174,   175,   234,   177,   178,   128,   180,   128,   182,   128,
     128,   185,   128,   187,   188,   234,   234,   234,   114,   193,
     128,   234,   128,   197,   234,   128,   234,   201,   202,   203,
     237,   234,   216,   234,   208,   234,   234,   234,   234,   213,
     234,   234,   234,   234,   234,   234,   128,   128,   128,   216,
     237,   128,   128,   234,   128,   128,   128,   234,   234,   234,
     128,   234,   234,   234,   234,   234,   234,   128,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   128,   234,   128,
     234,   234,   237,   128,   234,   234,   128,   128,   234,   237,
     234,   234,   234,   234,   114,   234,   234,   234,   234,   234,
     234,   128,   234,   134,   234,   134,   136,   234,   136,   234,
     234,   234,   234,   234,   234,   234,   134,   234,   134,   234,
     234,  1223,   234,   234,   234,   234,   234,   234,    77,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   223,   497,   584,   234,   234,  1325,  1054,   234,
     512,  1286,  1284,  1273,  1262,   234,  1271,   234,   238,   234,
     234,   234,   234,   239,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   484,   461,   234,   237,   237,   234,   234,
     234,   234,   234,   215,   234,  1156,   338,   597,   528,  1296,
    1289,   239,   239,   239,  1267,   239,   239,   237,   234,   234,
     234,   234,   570,   474,   112,   162,   264,  1126,   401,    94,
    1124,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   297,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   391
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   241,     0,     1,     4,    16,    20,    22,    29,    41,
      46,    47,    65,    69,    82,   104,   105,   119,   136,   148,
     149,   173,   186,   191,   196,   199,   242,   247,   252,   278,
     284,   290,   298,   312,   332,   356,   370,   385,   392,   396,
     406,   415,   436,   442,   448,   452,   458,   512,   526,   234,
     235,   236,   236,   333,   416,   443,   236,   453,   236,   371,
     437,   357,   236,   285,   313,   386,   236,   236,   407,   236,
     291,   236,   397,     1,    30,    38,   106,   279,   280,   281,
     282,   283,     1,    26,    27,    33,    61,    62,    63,    75,
      76,    77,    85,    86,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   236,   236,   236,
       1,    64,   449,   450,   451,   236,     1,     6,     7,     9,
      10,    14,    24,    25,    32,    35,    36,    37,    42,    59,
      60,    70,    73,    74,    84,    91,    93,    95,    97,   100,
     101,   112,   117,   118,   120,   121,   122,   125,   150,   161,
     162,   163,   164,   165,   166,   167,   217,   218,   219,   221,
     222,   230,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   505,   509,   510,   511,   236,
     236,   236,     1,   103,   124,   248,   249,   250,   251,   236,
     236,   236,     1,    34,    43,    44,    45,    48,    49,    53,
      54,    55,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,     1,    28,    30,    57,    67,    79,    80,
      81,    92,    96,   106,   109,   110,   138,   154,   157,   158,
     159,   205,   228,   229,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   236,     1,   226,   299,
     300,   301,   302,   303,   236,     1,   106,   393,   394,   395,
     236,   234,   237,   237,   237,   235,   280,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   235,   514,
       1,    18,    19,    23,    66,    86,    87,    88,    89,    90,
      94,    99,   106,   115,   116,   126,   147,   192,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,     1,     3,     5,
      20,    39,    56,    58,    66,    78,   106,   127,   146,   155,
     205,   228,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   431,   432,   433,   434,   435,     1,    64,
     130,   444,   445,   446,   447,   237,   235,   450,     1,   106,
     130,   454,   455,   456,   457,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     506,   502,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     235,   460,     1,    20,    39,    66,   123,   131,   132,   151,
     227,   372,   373,   374,   375,   376,   377,   378,   382,   383,
     384,     1,   130,   227,   438,   439,   440,   441,     1,    56,
      64,    66,   127,   358,   362,   363,   364,   368,   369,   234,
     237,   237,   235,   249,     1,    83,   179,   286,   287,   288,
     289,     1,    20,    39,    66,   106,   123,   155,   156,   207,
     227,   231,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   328,     1,    41,    83,   130,   387,   388,
     389,   390,   391,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   235,   528,   234,   237,   237,   237,   237,   262,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   235,   254,     1,   106,   224,
     408,   409,   410,   411,   234,   237,   235,   300,   179,     1,
     106,   172,   190,   206,   292,   293,   294,   295,   296,   297,
     237,   235,   394,     1,   106,   224,   227,   398,   399,   400,
     401,   402,   128,   128,   128,   234,   114,   114,   244,   216,
     114,   244,   244,   114,   244,   244,   114,   114,   234,   234,
     237,   237,   237,   353,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   235,   335,   234,
     237,   237,   237,   237,   237,   237,   428,   237,   237,   237,
     237,   237,   237,   237,   235,   418,   237,   237,   235,   445,
     128,   234,   237,   237,   235,   455,   216,   244,   114,   244,
     244,   216,   114,   216,   114,   114,   114,   216,   216,   216,
     244,   114,   114,   114,   114,   244,   114,   114,   114,   114,
     216,   237,   237,   216,   244,   244,   216,   216,   216,   216,
     220,   216,   220,   216,   216,   216,   216,   114,   244,   216,
     244,   244,   216,   234,   234,   237,   237,   379,   237,   237,
     237,   237,   237,   235,   373,   237,   237,   235,   439,   234,
     237,   237,   359,   237,   235,   363,   128,   128,   234,   234,
     237,   237,   235,   287,   234,   237,   237,   329,   237,   237,
     237,   237,   325,   237,   237,   235,   315,   234,   237,   237,
     237,   235,   388,   216,   216,   244,   128,   216,   128,   216,
     216,   216,   234,   114,   128,   216,   128,   237,   128,   128,
     114,   114,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   234,   234,   237,   412,   235,   409,   216,
     234,   236,   234,   237,   237,   237,   237,   235,   293,   128,
     234,   234,   237,   403,   237,   235,   399,   234,   234,   234,
     234,   139,   140,   141,   142,   143,   144,   145,   243,   244,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     114,   114,   244,   237,   114,   114,   114,   244,   114,   114,
     244,   128,   114,   114,   244,   114,   246,   246,   234,   128,
     183,   184,   128,   216,   128,   128,   237,   128,   128,   114,
     128,   128,   128,   128,   234,   128,   128,   234,   234,   128,
     128,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,    48,   169,   170,
     171,   174,   175,   177,   178,   180,   182,   185,   187,   188,
     193,   197,   201,   202,   203,   208,   213,   507,   508,    48,
      50,    51,   169,   170,   171,   174,   175,   177,   178,   180,
     182,   185,   187,   188,   193,   197,   201,   202,   203,   208,
     213,   503,   504,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   128,   216,   237,   128,   114,   128,   128,
     128,   234,   128,   128,   234,   128,   128,   237,   114,   366,
     367,   234,   234,   234,   128,   128,   234,   128,   216,   237,
     128,   128,   128,   216,   237,   128,   128,   234,   128,   128,
     128,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,    17,    98,   102,   160,   263,
     264,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   128,   237,   234,   234,
       1,   106,   200,   224,   304,   305,   306,   307,   308,   128,
     128,   128,   128,   234,   234,   128,   237,   128,   234,   243,
     243,   243,   243,   243,   243,   243,   234,   234,   234,    52,
     129,   354,   355,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,    11,    12,    13,   245,   246,   234,
     234,   234,   234,   234,   234,   234,   234,   234,     8,   204,
     429,   430,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   238,   234,   238,   234,   234,    15,
      40,    72,   107,   108,   113,   137,   152,   215,   233,   380,
     381,   234,   234,   234,   234,   234,   234,   234,   234,   234,
      48,   195,   204,   360,   361,   223,   238,   365,   234,   234,
     234,   234,     4,    21,    22,    31,    68,    69,    71,   103,
     111,   133,   135,   136,   153,   176,   181,   185,   189,   194,
     198,   209,   211,   212,   214,   225,   232,   330,   331,   234,
     234,   234,   234,    48,    50,    51,   169,   170,   171,   174,
     175,   177,   178,   180,   182,   185,   187,   188,   193,   197,
     201,   202,   203,   208,   213,   326,   327,   234,   234,   234,
     234,   234,   234,   238,   234,    71,   136,   168,   176,   185,
     209,   211,   212,   225,   232,   413,   414,   234,   237,   237,
     309,   235,   305,   234,   234,   234,   234,   234,    71,   136,
     168,   176,   185,   209,   211,   212,   225,   232,   404,   405,
     234,   234,   238,   245,   245,   245,   234,   238,   508,   504,
     234,   238,   234,   238,   114,   367,   234,   239,   239,   239,
     239,   239,   239,   234,   238,   234,   238,   264,   234,   238,
     128,   210,   246,   237,   234,   234,   238,   355,   430,   381,
     361,   134,   136,   134,   136,   134,   134,   331,   327,   414,
     234,   234,   234,    69,    71,   119,   136,   175,   176,   227,
     232,   310,   311,   405,   234,   238,   311
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
     335,   335,   335,   335,   335,   335,   335,   335,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   353,   352,   354,   354,   355,
     355,   357,   356,   359,   358,   360,   360,   361,   361,   361,
     362,   362,   363,   363,   363,   363,   363,   365,   364,   366,
     366,   367,   367,   368,   369,   371,   370,   372,   372,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   374,   375,
     376,   377,   379,   378,   380,   380,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   382,   383,   384,   386,
     385,   387,   387,   388,   388,   388,   388,   389,   390,   391,
     392,   393,   393,   394,   394,   395,   397,   396,   398,   398,
     399,   399,   399,   399,   400,   401,   403,   402,   404,   404,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     407,   406,   408,   408,   409,   409,   409,   410,   412,   411,
     413,   413,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   416,   415,   417,   417,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   426,
     428,   427,   429,   429,   430,   430,   431,   432,   433,   434,
     435,   437,   436,   438,   438,   439,   439,   439,   440,   441,
     443,   442,   444,   444,   445,   445,   445,   446,   447,   448,
     449,   449,   450,   450,   451,   453,   452,   454,   454,   455,
     455,   455,   456,   457,   458,   459,   459,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   460,   460,   460,   460,   460,   460,   460,
     460,   460,   460,   461,   462,   463,   464,   465,   466,   467,
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
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
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
#line 410 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 438 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 444 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2985 "conf_parser.c" /* yacc.c:1646  */
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
#line 2997 "conf_parser.c" /* yacc.c:1646  */
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
#line 3009 "conf_parser.c" /* yacc.c:1646  */
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
#line 3021 "conf_parser.c" /* yacc.c:1646  */
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
#line 3033 "conf_parser.c" /* yacc.c:1646  */
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
#line 3045 "conf_parser.c" /* yacc.c:1646  */
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
#line 3057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 534 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options = 0;
}
#line 3066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 541 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_STANDARD;
#endif
}
#line 3077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 547 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MEMORY_CACHE;
#endif
}
#line 3088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 553 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_MMAP_CACHE;
#endif
}
#line 3099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 559 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBGEOIP
  if (conf_parser_ctx.pass == 1)
    ConfigServerInfo.libgeoip_database_options |= GEOIP_CHECK_CACHE;
#endif
}
#line 3110 "conf_parser.c" /* yacc.c:1646  */
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
#line 3128 "conf_parser.c" /* yacc.c:1646  */
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
#line 3146 "conf_parser.c" /* yacc.c:1646  */
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
#line 3164 "conf_parser.c" /* yacc.c:1646  */
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
#line 3182 "conf_parser.c" /* yacc.c:1646  */
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
#line 3195 "conf_parser.c" /* yacc.c:1646  */
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
#line 3212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 651 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3224 "conf_parser.c" /* yacc.c:1646  */
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
#line 3255 "conf_parser.c" /* yacc.c:1646  */
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
#line 3286 "conf_parser.c" /* yacc.c:1646  */
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
#line 3314 "conf_parser.c" /* yacc.c:1646  */
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
#line 3339 "conf_parser.c" /* yacc.c:1646  */
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
#line 3364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 785 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 803 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3385 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 812 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 821 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3418 "conf_parser.c" /* yacc.c:1646  */
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
#line 3435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 855 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 861 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 871 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3462 "conf_parser.c" /* yacc.c:1646  */
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
#line 3480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 893 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 899 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 905 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3507 "conf_parser.c" /* yacc.c:1646  */
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
#line 3528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3537 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 945 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3546 "conf_parser.c" /* yacc.c:1646  */
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
#line 3559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 965 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3570 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 973 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 976 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3586 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 981 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3595 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 988 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3604 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3613 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 996 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3622 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3631 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1004 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3640 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1008 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1012 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1016 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1026 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3679 "conf_parser.c" /* yacc.c:1646  */
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
#line 3736 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1100 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3745 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1106 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3754 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1112 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3763 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1118 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3772 "conf_parser.c" /* yacc.c:1646  */
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
#line 3786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1135 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3795 "conf_parser.c" /* yacc.c:1646  */
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
#line 3809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1152 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1158 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1165 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1169 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1173 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1177 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1181 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1185 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1189 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1193 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1201 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1205 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1209 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1213 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1217 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1225 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3971 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3980 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1237 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1245 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1266 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1270 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1274 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1278 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1282 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1286 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1290 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1294 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1298 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1302 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1306 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1310 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1314 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1318 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1322 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1326 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4187 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1330 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1334 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1338 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1342 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1346 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1350 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1354 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4250 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1358 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4259 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1362 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4268 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1366 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4277 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1370 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4286 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1374 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4295 "conf_parser.c" /* yacc.c:1646  */
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
#line 4312 "conf_parser.c" /* yacc.c:1646  */
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
#line 4360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1460 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1466 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1472 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1478 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1484 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1490 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1496 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1502 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1508 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1514 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1520 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1527 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1533 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1539 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1545 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4499 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1554 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1563 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1570 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1574 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4538 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1584 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1590 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1596 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4564 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1600 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1604 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1612 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4588 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1617 "conf_parser.y" /* yacc.c:1646  */
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
#line 4606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1630 "conf_parser.y" /* yacc.c:1646  */
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
#line 4626 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1647 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4635 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1653 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4644 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1663 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4653 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1667 "conf_parser.y" /* yacc.c:1646  */
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
#line 4698 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1720 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4707 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1726 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4716 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1732 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4725 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1738 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4739 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1749 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4748 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1756 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1760 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4766 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1764 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1768 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1772 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1776 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1780 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4811 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1784 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4820 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1788 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4829 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1792 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1798 "conf_parser.y" /* yacc.c:1646  */
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
#line 4855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1812 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1821 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1841 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1852 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1858 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1864 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1879 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1895 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1906 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1921 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1927 "conf_parser.y" /* yacc.c:1646  */
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
#line 5006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1946 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1953 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1957 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5033 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1961 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5042 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1965 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5051 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1969 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5060 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1973 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1977 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1981 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1985 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1989 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5105 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1999 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2008 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5132 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5141 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2038 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 404:
#line 2042 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2050 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2062 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2080 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2089 "conf_parser.y" /* yacc.c:1646  */
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
#line 5320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2169 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5329 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2175 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2181 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5347 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2187 "conf_parser.y" /* yacc.c:1646  */
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
#line 5363 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2200 "conf_parser.y" /* yacc.c:1646  */
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
#line 5379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2213 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2219 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2225 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2235 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2245 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2251 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2274 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2280 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2295 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2299 "conf_parser.y" /* yacc.c:1646  */
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
#line 5530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2324 "conf_parser.y" /* yacc.c:1646  */
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
#line 5553 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2344 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5562 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2354 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2358 "conf_parser.y" /* yacc.c:1646  */
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
#line 5597 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 467:
#line 2384 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2390 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 474:
#line 2405 "conf_parser.y" /* yacc.c:1646  */
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
#line 5632 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 475:
#line 2422 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5641 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 476:
#line 2426 "conf_parser.y" /* yacc.c:1646  */
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
#line 5661 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 482:
#line 2446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5670 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 483:
#line 2452 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2513 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5687 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2518 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5695 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2523 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5703 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2528 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5712 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2534 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5720 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2539 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5728 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2544 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5736 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2549 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5744 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2554 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5752 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2559 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5760 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2564 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2569 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2574 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2579 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2584 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2589 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5808 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2594 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2599 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2604 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5833 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2610 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2615 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2620 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5857 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2625 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2630 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2635 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2640 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2645 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2648 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5905 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2653 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2656 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2661 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2666 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2671 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2676 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2681 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2686 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5969 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2691 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5977 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2696 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2701 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2706 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2711 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6009 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2716 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2721 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2727 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6033 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2730 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6041 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2733 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6049 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2736 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2739 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6065 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2745 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2751 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2754 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6105 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6113 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2760 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6121 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2763 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2766 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2769 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6145 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6153 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2775 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2778 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2781 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2784 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6185 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6193 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2790 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6201 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6217 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6225 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6233 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6257 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6265 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6273 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6281 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6289 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6297 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6305 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6313 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 618:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6321 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 619:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6329 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 620:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6337 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 621:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6345 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 622:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6353 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 623:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6361 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6377 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2868 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6385 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2873 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2898 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2903 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 2908 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 2913 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 2918 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2923 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2928 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6449 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2933 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2938 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2943 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 2948 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 2971 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6490 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 668:
#line 2977 "conf_parser.y" /* yacc.c:1646  */
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
#line 6509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 669:
#line 2993 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 670:
#line 3002 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 671:
#line 3008 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 672:
#line 3014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 673:
#line 3020 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 674:
#line 3029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 675:
#line 3035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6578 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6582 "conf_parser.c" /* yacc.c:1646  */
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
