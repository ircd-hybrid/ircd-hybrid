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
    CIDR_BITLEN_IPV4 = 272,
    CIDR_BITLEN_IPV6 = 273,
    CLASS = 274,
    CLOSE = 275,
    CONNECT = 276,
    CONNECTFREQ = 277,
    CYCLE_ON_HOST_CHANGE = 278,
    DEFAULT_FLOODCOUNT = 279,
    DEFAULT_FLOODTIME = 280,
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
    LISTEN = 335,
    MASK = 336,
    MAX_ACCEPT = 337,
    MAX_BANS = 338,
    MAX_BANS_LARGE = 339,
    MAX_CHANNELS = 340,
    MAX_GLOBAL = 341,
    MAX_IDLE = 342,
    MAX_INVITES = 343,
    MAX_LOCAL = 344,
    MAX_NICK_CHANGES = 345,
    MAX_NICK_LENGTH = 346,
    MAX_NICK_TIME = 347,
    MAX_NUMBER = 348,
    MAX_TARGETS = 349,
    MAX_TOPIC_LENGTH = 350,
    MAX_WATCH = 351,
    MIN_IDLE = 352,
    MIN_NONWILDCARD = 353,
    MIN_NONWILDCARD_SIMPLE = 354,
    MODULE = 355,
    MODULES = 356,
    MOTD = 357,
    NAME = 358,
    NEED_IDENT = 359,
    NEED_PASSWORD = 360,
    NETWORK_DESC = 361,
    NETWORK_NAME = 362,
    NICK = 363,
    NO_OPER_FLOOD = 364,
    NO_TILDE = 365,
    NUMBER = 366,
    NUMBER_PER_CIDR = 367,
    NUMBER_PER_IP = 368,
    OPER_ONLY_UMODES = 369,
    OPER_UMODES = 370,
    OPERATOR = 371,
    OPERS_BYPASS_CALLERID = 372,
    PACE_WAIT = 373,
    PACE_WAIT_SIMPLE = 374,
    PASSWORD = 375,
    PATH = 376,
    PING_COOKIE = 377,
    PING_TIME = 378,
    PORT = 379,
    QSTRING = 380,
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
    SPOOF_NOTICE = 404,
    SQUIT = 405,
    SSL_CERTIFICATE_FILE = 406,
    SSL_CERTIFICATE_FINGERPRINT = 407,
    SSL_CONNECTION_REQUIRED = 408,
    SSL_DH_ELLIPTIC_CURVE = 409,
    SSL_DH_PARAM_FILE = 410,
    SSL_MESSAGE_DIGEST_ALGORITHM = 411,
    STATS_E_DISABLED = 412,
    STATS_I_OPER_ONLY = 413,
    STATS_K_OPER_ONLY = 414,
    STATS_M_OPER_ONLY = 415,
    STATS_O_OPER_ONLY = 416,
    STATS_P_OPER_ONLY = 417,
    STATS_U_OPER_ONLY = 418,
    T_ALL = 419,
    T_BOTS = 420,
    T_CALLERID = 421,
    T_CCONN = 422,
    T_COMMAND = 423,
    T_CLUSTER = 424,
    T_DEAF = 425,
    T_DEBUG = 426,
    T_DLINE = 427,
    T_EXTERNAL = 428,
    T_FARCONNECT = 429,
    T_FILE = 430,
    T_FULL = 431,
    T_GLOBOPS = 432,
    T_INVISIBLE = 433,
    T_IPV4 = 434,
    T_IPV6 = 435,
    T_LOCOPS = 436,
    T_LOG = 437,
    T_NCHANGE = 438,
    T_NONONREG = 439,
    T_OPME = 440,
    T_PREPEND = 441,
    T_PSEUDO = 442,
    T_RECVQ = 443,
    T_REJ = 444,
    T_RESTART = 445,
    T_SERVER = 446,
    T_SERVICE = 447,
    T_SERVNOTICE = 448,
    T_SET = 449,
    T_SHARED = 450,
    T_SIZE = 451,
    T_SKILL = 452,
    T_SOFTCALLERID = 453,
    T_SPY = 454,
    T_SSL = 455,
    T_SSL_CIPHER_LIST = 456,
    T_TARGET = 457,
    T_UMODES = 458,
    T_UNAUTH = 459,
    T_UNDLINE = 460,
    T_UNLIMITED = 461,
    T_UNRESV = 462,
    T_UNXLINE = 463,
    T_WALLOP = 464,
    T_WALLOPS = 465,
    T_WEBIRC = 466,
    TBOOL = 467,
    THROTTLE_COUNT = 468,
    THROTTLE_TIME = 469,
    TKLINE_EXPIRE_NOTICES = 470,
    TMASKED = 471,
    TS_MAX_DELTA = 472,
    TS_WARN_DELTA = 473,
    TWODOTS = 474,
    TYPE = 475,
    UNKLINE = 476,
    USE_LOGGING = 477,
    USER = 478,
    VHOST = 479,
    VHOST6 = 480,
    WARN_NO_CONNECT_BLOCK = 481,
    WHOIS = 482,
    WHOWAS_HISTORY_LENGTH = 483,
    XLINE = 484,
    XLINE_EXEMPT = 485
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
#define CLOSE 275
#define CONNECT 276
#define CONNECTFREQ 277
#define CYCLE_ON_HOST_CHANGE 278
#define DEFAULT_FLOODCOUNT 279
#define DEFAULT_FLOODTIME 280
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
#define LISTEN 335
#define MASK 336
#define MAX_ACCEPT 337
#define MAX_BANS 338
#define MAX_BANS_LARGE 339
#define MAX_CHANNELS 340
#define MAX_GLOBAL 341
#define MAX_IDLE 342
#define MAX_INVITES 343
#define MAX_LOCAL 344
#define MAX_NICK_CHANGES 345
#define MAX_NICK_LENGTH 346
#define MAX_NICK_TIME 347
#define MAX_NUMBER 348
#define MAX_TARGETS 349
#define MAX_TOPIC_LENGTH 350
#define MAX_WATCH 351
#define MIN_IDLE 352
#define MIN_NONWILDCARD 353
#define MIN_NONWILDCARD_SIMPLE 354
#define MODULE 355
#define MODULES 356
#define MOTD 357
#define NAME 358
#define NEED_IDENT 359
#define NEED_PASSWORD 360
#define NETWORK_DESC 361
#define NETWORK_NAME 362
#define NICK 363
#define NO_OPER_FLOOD 364
#define NO_TILDE 365
#define NUMBER 366
#define NUMBER_PER_CIDR 367
#define NUMBER_PER_IP 368
#define OPER_ONLY_UMODES 369
#define OPER_UMODES 370
#define OPERATOR 371
#define OPERS_BYPASS_CALLERID 372
#define PACE_WAIT 373
#define PACE_WAIT_SIMPLE 374
#define PASSWORD 375
#define PATH 376
#define PING_COOKIE 377
#define PING_TIME 378
#define PORT 379
#define QSTRING 380
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
#define SPOOF_NOTICE 404
#define SQUIT 405
#define SSL_CERTIFICATE_FILE 406
#define SSL_CERTIFICATE_FINGERPRINT 407
#define SSL_CONNECTION_REQUIRED 408
#define SSL_DH_ELLIPTIC_CURVE 409
#define SSL_DH_PARAM_FILE 410
#define SSL_MESSAGE_DIGEST_ALGORITHM 411
#define STATS_E_DISABLED 412
#define STATS_I_OPER_ONLY 413
#define STATS_K_OPER_ONLY 414
#define STATS_M_OPER_ONLY 415
#define STATS_O_OPER_ONLY 416
#define STATS_P_OPER_ONLY 417
#define STATS_U_OPER_ONLY 418
#define T_ALL 419
#define T_BOTS 420
#define T_CALLERID 421
#define T_CCONN 422
#define T_COMMAND 423
#define T_CLUSTER 424
#define T_DEAF 425
#define T_DEBUG 426
#define T_DLINE 427
#define T_EXTERNAL 428
#define T_FARCONNECT 429
#define T_FILE 430
#define T_FULL 431
#define T_GLOBOPS 432
#define T_INVISIBLE 433
#define T_IPV4 434
#define T_IPV6 435
#define T_LOCOPS 436
#define T_LOG 437
#define T_NCHANGE 438
#define T_NONONREG 439
#define T_OPME 440
#define T_PREPEND 441
#define T_PSEUDO 442
#define T_RECVQ 443
#define T_REJ 444
#define T_RESTART 445
#define T_SERVER 446
#define T_SERVICE 447
#define T_SERVNOTICE 448
#define T_SET 449
#define T_SHARED 450
#define T_SIZE 451
#define T_SKILL 452
#define T_SOFTCALLERID 453
#define T_SPY 454
#define T_SSL 455
#define T_SSL_CIPHER_LIST 456
#define T_TARGET 457
#define T_UMODES 458
#define T_UNAUTH 459
#define T_UNDLINE 460
#define T_UNLIMITED 461
#define T_UNRESV 462
#define T_UNXLINE 463
#define T_WALLOP 464
#define T_WALLOPS 465
#define T_WEBIRC 466
#define TBOOL 467
#define THROTTLE_COUNT 468
#define THROTTLE_TIME 469
#define TKLINE_EXPIRE_NOTICES 470
#define TMASKED 471
#define TS_MAX_DELTA 472
#define TS_WARN_DELTA 473
#define TWODOTS 474
#define TYPE 475
#define UNKLINE 476
#define USE_LOGGING 477
#define USER 478
#define VHOST 479
#define VHOST6 480
#define WARN_NO_CONNECT_BLOCK 481
#define WHOIS 482
#define WHOWAS_HISTORY_LENGTH 483
#define XLINE 484
#define XLINE_EXEMPT 485

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 142 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 685 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 702 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  296
/* YYNRULES -- Number of rules.  */
#define YYNRULES  670
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1324

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   485

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
static const yytype_uint16 yyrline[] =
{
       0,   376,   376,   377,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   407,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   418,   418,
     419,   420,   421,   422,   429,   431,   431,   432,   432,   432,
     434,   440,   450,   452,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   473,   482,   491,   500,   509,   518,   527,
     542,   557,   567,   581,   590,   618,   646,   671,   693,   715,
     725,   727,   727,   728,   729,   730,   731,   733,   742,   751,
     765,   764,   782,   782,   783,   783,   783,   785,   791,   802,
     801,   820,   820,   821,   821,   821,   821,   821,   823,   829,
     835,   841,   863,   864,   864,   866,   866,   867,   869,   876,
     876,   889,   890,   892,   892,   893,   893,   895,   903,   906,
     912,   911,   917,   917,   918,   922,   926,   930,   934,   938,
     942,   946,   957,   956,  1017,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1030,  1036,  1042,
    1048,  1054,  1065,  1071,  1082,  1089,  1088,  1094,  1094,  1095,
    1099,  1103,  1107,  1111,  1115,  1119,  1123,  1127,  1131,  1135,
    1139,  1143,  1147,  1151,  1155,  1159,  1163,  1167,  1171,  1175,
    1179,  1186,  1185,  1191,  1191,  1192,  1196,  1200,  1204,  1208,
    1212,  1216,  1220,  1224,  1228,  1232,  1236,  1240,  1244,  1248,
    1252,  1256,  1260,  1264,  1268,  1272,  1276,  1280,  1284,  1288,
    1292,  1296,  1300,  1304,  1315,  1314,  1370,  1370,  1371,  1372,
    1373,  1374,  1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,
    1383,  1384,  1385,  1386,  1387,  1389,  1395,  1401,  1407,  1413,
    1419,  1425,  1431,  1437,  1443,  1450,  1456,  1462,  1468,  1477,
    1487,  1486,  1492,  1492,  1493,  1497,  1508,  1507,  1514,  1513,
    1518,  1518,  1519,  1523,  1527,  1533,  1533,  1534,  1534,  1534,
    1534,  1534,  1536,  1536,  1538,  1538,  1540,  1553,  1570,  1576,
    1587,  1586,  1632,  1632,  1633,  1634,  1635,  1636,  1637,  1638,
    1639,  1640,  1641,  1643,  1649,  1655,  1661,  1673,  1672,  1678,
    1678,  1679,  1683,  1687,  1691,  1695,  1699,  1703,  1707,  1711,
    1715,  1721,  1735,  1744,  1758,  1757,  1772,  1772,  1773,  1773,
    1773,  1773,  1775,  1781,  1787,  1797,  1799,  1799,  1800,  1800,
    1802,  1819,  1818,  1841,  1841,  1842,  1842,  1842,  1842,  1844,
    1850,  1870,  1869,  1875,  1875,  1876,  1880,  1884,  1888,  1892,
    1896,  1900,  1904,  1908,  1912,  1923,  1922,  1941,  1941,  1942,
    1942,  1942,  1944,  1951,  1950,  1956,  1956,  1957,  1961,  1965,
    1969,  1973,  1977,  1981,  1985,  1989,  1993,  2004,  2003,  2075,
    2075,  2076,  2077,  2078,  2079,  2080,  2081,  2082,  2083,  2084,
    2085,  2086,  2087,  2088,  2089,  2090,  2092,  2098,  2104,  2110,
    2123,  2136,  2142,  2148,  2152,  2159,  2158,  2163,  2163,  2164,
    2168,  2174,  2185,  2191,  2197,  2203,  2219,  2218,  2244,  2244,
    2245,  2245,  2245,  2247,  2267,  2278,  2277,  2304,  2304,  2305,
    2305,  2305,  2307,  2313,  2323,  2325,  2325,  2326,  2326,  2328,
    2346,  2345,  2366,  2366,  2367,  2367,  2367,  2369,  2375,  2385,
    2387,  2387,  2388,  2389,  2390,  2391,  2392,  2393,  2394,  2395,
    2396,  2397,  2398,  2399,  2400,  2401,  2402,  2403,  2404,  2405,
    2406,  2407,  2408,  2409,  2410,  2411,  2412,  2413,  2414,  2415,
    2416,  2417,  2418,  2419,  2420,  2421,  2422,  2423,  2424,  2425,
    2426,  2427,  2428,  2429,  2430,  2431,  2432,  2433,  2434,  2435,
    2438,  2443,  2448,  2453,  2458,  2464,  2469,  2474,  2479,  2484,
    2489,  2494,  2499,  2504,  2509,  2514,  2519,  2524,  2529,  2534,
    2540,  2545,  2550,  2555,  2560,  2565,  2570,  2575,  2578,  2583,
    2586,  2591,  2596,  2601,  2606,  2611,  2616,  2621,  2626,  2631,
    2636,  2641,  2646,  2652,  2651,  2656,  2656,  2657,  2660,  2663,
    2666,  2669,  2672,  2675,  2678,  2681,  2684,  2687,  2690,  2693,
    2696,  2699,  2702,  2705,  2708,  2711,  2714,  2717,  2720,  2726,
    2725,  2730,  2730,  2731,  2734,  2737,  2740,  2743,  2746,  2749,
    2752,  2755,  2758,  2761,  2764,  2767,  2770,  2773,  2776,  2779,
    2782,  2785,  2788,  2793,  2798,  2803,  2808,  2817,  2819,  2819,
    2820,  2821,  2822,  2823,  2824,  2825,  2826,  2827,  2828,  2829,
    2830,  2831,  2832,  2833,  2834,  2836,  2841,  2846,  2851,  2856,
    2861,  2866,  2871,  2876,  2881,  2886,  2891,  2896,  2901,  2910,
    2912,  2912,  2913,  2914,  2915,  2916,  2917,  2918,  2919,  2920,
    2921,  2922,  2924,  2930,  2946,  2955,  2961,  2967,  2973,  2982,
    2988
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
  "CLOSE", "CONNECT", "CONNECTFREQ", "CYCLE_ON_HOST_CHANGE",
  "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME", "DEFAULT_JOIN_FLOOD_COUNT",
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
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LISTEN", "MASK", "MAX_ACCEPT",
  "MAX_BANS", "MAX_BANS_LARGE", "MAX_CHANNELS", "MAX_GLOBAL", "MAX_IDLE",
  "MAX_INVITES", "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH",
  "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH",
  "MAX_WATCH", "MIN_IDLE", "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE",
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
  "SSL_MESSAGE_DIGEST_ALGORITHM", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_M_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL", "T_BOTS",
  "T_CALLERID", "T_CCONN", "T_COMMAND", "T_CLUSTER", "T_DEAF", "T_DEBUG",
  "T_DLINE", "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS",
  "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_NCHANGE",
  "T_NONONREG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ", "T_REJ",
  "T_RESTART", "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET",
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
  "serverinfo_ssl_dh_elliptic_curve", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_default_max_clients", "serverinfo_max_nick_length",
  "serverinfo_max_topic_length", "serverinfo_hub", "admin_entry",
  "admin_items", "admin_item", "admin_name", "admin_email",
  "admin_description", "motd_entry", "$@1", "motd_items", "motd_item",
  "motd_mask", "motd_file", "pseudo_entry", "$@2", "pseudo_items",
  "pseudo_item", "pseudo_command", "pseudo_name", "pseudo_prepend",
  "pseudo_target", "logging_entry", "logging_items", "logging_item",
  "logging_use_logging", "logging_file_entry", "$@3", "logging_file_items",
  "logging_file_item", "logging_file_name", "logging_file_size",
  "logging_file_type", "$@4", "logging_file_type_items",
  "logging_file_type_item", "oper_entry", "$@5", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_whois",
  "oper_encrypted", "oper_ssl_certificate_fingerprint",
  "oper_ssl_connection_required", "oper_class", "oper_umodes", "$@6",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@7",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@8",
  "class_items", "class_item", "class_name", "class_ping_time",
  "class_number_per_ip", "class_connectfreq", "class_max_channels",
  "class_max_number", "class_max_global", "class_max_local", "class_sendq",
  "class_recvq", "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "class_min_idle", "class_max_idle",
  "class_flags", "$@9", "class_flags_items", "class_flags_item",
  "listen_entry", "$@10", "listen_flags", "$@11", "listen_flags_items",
  "listen_flags_item", "listen_items", "listen_item", "listen_port",
  "$@12", "port_items", "port_item", "listen_address", "listen_host",
  "auth_entry", "$@13", "auth_items", "auth_item", "auth_user",
  "auth_passwd", "auth_class", "auth_encrypted", "auth_flags", "$@14",
  "auth_flags_items", "auth_flags_item", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@15", "resv_items", "resv_item",
  "resv_mask", "resv_reason", "resv_exempt", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@16",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@17", "shared_types", "shared_type_item",
  "cluster_entry", "$@18", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@19", "cluster_types", "cluster_type_item",
  "connect_entry", "$@20", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_ssl_certificate_fingerprint",
  "connect_port", "connect_aftype", "connect_flags", "$@21",
  "connect_flags_items", "connect_flags_item", "connect_encrypted",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_ssl_cipher_list", "kill_entry", "$@22", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@23",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@24",
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
  "$@25", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@26", "umode_items", "umode_item", "general_min_nonwildcard",
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
     485,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -749

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-749)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -749,   715,  -749,  -202,  -215,  -195,  -749,  -749,  -749,  -189,
    -749,  -181,  -749,  -749,  -749,  -179,  -749,  -749,  -749,  -161,
    -149,  -749,  -146,  -749,   -73,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,    23,   891,   -70,   -64,   -63,    11,   -53,   387,   -50,
     -38,   -37,   107,   -32,   -20,    -9,   937,   551,    40,    19,
      45,    22,    48,     9,    -1,    26,    32,     2,  -749,  -749,
    -749,  -749,  -749,    71,    77,    88,    93,    95,   102,   108,
     115,   116,   122,   123,   124,   128,   129,   276,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,   661,   570,    41,  -749,   132,    14,  -749,
    -749,    15,  -749,   133,   137,   138,   139,   140,   141,   148,
     150,   155,   157,   158,   161,   165,   166,   168,   169,   171,
     174,   179,   180,   181,   186,   187,   191,   192,   193,  -749,
    -749,   196,   198,   199,   203,   205,   206,   215,   216,   217,
     220,   222,   229,   231,   232,   233,   234,   237,   239,   240,
      57,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,   316,
      38,   314,   159,   241,   242,    13,  -749,  -749,  -749,   156,
     367,    54,  -749,   244,   248,   250,   254,   256,   257,   263,
     264,   265,   144,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,   224,   269,   273,   280,   283,   284,   292,
     293,   294,   298,   299,   301,   302,   304,   307,   309,   317,
     319,    55,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
      74,   228,   321,    27,  -749,  -749,  -749,   120,   183,  -749,
     322,    18,  -749,  -749,     7,  -749,   385,   396,   417,   326,
    -749,   306,   447,    78,   448,   447,   447,   447,   451,   447,
     447,   454,   457,   461,   463,   345,  -749,   346,   344,   348,
     349,  -749,   350,   351,   352,   353,   358,   361,   363,   364,
     369,   372,   373,   376,   221,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,   362,   377,   378,   380,   382,   383,   384,  -749,
     386,   388,   391,   393,   395,   398,   399,    30,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,   400,   401,    25,  -749,  -749,  -749,
     505,   405,  -749,  -749,   404,   406,    21,  -749,  -749,  -749,
     427,   447,   532,   447,   447,   432,   534,   447,   435,   537,
     540,   541,   441,   443,   444,   447,   548,   549,   550,   553,
     447,   554,   555,   556,   558,   458,   437,   446,   465,   447,
     447,   470,   472,   483,  -191,  -171,   485,   488,   492,   496,
     564,   447,   497,   447,   447,   498,   592,   480,  -749,   486,
     484,   487,  -749,   489,   490,   493,   495,   499,   184,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,   501,
     503,    59,  -749,  -749,  -749,   494,   504,   507,  -749,   511,
    -749,     3,  -749,  -749,  -749,  -749,  -749,   589,   601,   508,
    -749,   518,   517,   519,    33,  -749,  -749,  -749,   524,   523,
     525,  -749,   526,   529,   531,   533,  -749,   535,   536,   225,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,   546,   538,   544,   545,    10,  -749,  -749,  -749,  -749,
     520,   568,   447,   605,   571,   641,   575,   578,   586,   572,
    -749,  -749,   657,   676,   594,   683,   671,   701,   688,   689,
     693,   695,   696,   697,   702,   703,   704,   707,   708,   595,
    -749,   603,   609,  -749,    64,  -749,  -749,  -749,  -749,   632,
     614,  -749,   185,   615,   613,   616,   617,   618,    61,  -749,
    -749,  -749,  -749,  -749,   728,   623,  -749,   624,   622,  -749,
     630,    35,  -749,  -749,  -749,  -749,   636,   638,   640,  -749,
     643,   700,   646,   647,   648,   649,   651,   652,   655,   656,
     662,   663,   664,   667,   668,  -749,  -749,   761,   777,   447,
     666,   795,   802,   447,   804,   809,   447,   798,   814,   815,
     447,   817,   817,   698,  -749,  -749,   805,    89,   807,   721,
     816,   818,   705,   819,   820,   823,   821,   824,   825,   826,
     709,  -749,   831,   832,   717,  -749,   727,  -749,   834,   835,
     730,  -749,   731,   732,   733,   734,   735,   739,   741,   742,
     746,   747,   752,   753,   756,   757,   758,   762,   763,   764,
     765,   766,   767,   768,   769,   770,   771,   772,   626,   692,
     773,   774,   775,   776,   778,   779,   780,   781,   782,   783,
     784,   785,   786,   787,   788,   789,   790,   791,   792,   793,
     794,  -749,  -749,   883,   822,   796,   901,   916,   903,   904,
     906,   801,  -749,   908,   910,   806,  -749,  -749,   911,   913,
     808,   928,   810,  -749,   812,   813,  -749,  -749,   915,   920,
     827,  -749,  -749,   921,   836,   828,   922,   924,   925,   839,
     829,   927,   929,   830,  -749,  -749,   930,   931,   932,   833,
    -749,   837,   838,   840,   841,   842,   843,   844,   845,   846,
    -749,   847,   848,   849,   850,   851,   852,   853,   854,   855,
     856,   857,   858,   859,   860,   861,   862,   863,  -749,  -749,
     934,   864,   865,  -749,   866,  -749,    56,  -749,   935,   940,
     941,   942,   868,  -749,   869,  -749,  -749,   945,   867,   970,
     871,  -749,  -749,  -749,  -749,  -749,   447,   447,   447,   447,
     447,   447,   447,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,   872,   873,
     874,   -15,   875,   876,   877,   878,   879,   880,   881,   882,
     884,   885,   287,   886,   887,  -749,   888,   889,   890,   892,
     893,   894,   895,     5,   896,   897,   898,   899,   900,   902,
     905,  -749,   907,   909,  -749,  -749,   912,   914,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -188,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -185,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,   917,   918,   420,   919,   923,   926,   933,   936,
    -749,   938,   939,  -749,   943,   944,     0,   946,   947,  -749,
    -749,  -749,  -749,   948,   949,  -749,   950,   952,   491,   953,
     954,   955,   956,   738,   957,   958,  -749,   959,   960,   961,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,   962,   308,  -749,
    -749,   963,   964,   965,  -749,    16,  -749,  -749,  -749,  -749,
     966,   969,   971,   972,  -749,  -749,   973,   359,   974,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -158,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,   817,   817,   817,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -157,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,   626,  -749,   692,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -135,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -133,  -749,  1003,   928,   975,  -749,  -749,
    -749,  -749,  -749,  -749,   976,  -749,   977,   978,  -749,  -749,
     979,   980,  -749,  -749,   981,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,   -95,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,   -10,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,    66,  -749,  -749,   997,   -84,   967,   987,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,    85,  -749,  -749,  -749,
     -15,  -749,  -749,  -749,  -749,     5,  -749,  -749,  -749,   420,
    -749,     0,  -749,  -749,  -749,  1001,  1002,  1006,  1008,  1011,
    1013,  -749,   491,  -749,   738,  -749,   308,   988,   989,   990,
     271,  -749,  -749,   359,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,    90,  -749,
    -749,  -749,   271,  -749
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   234,   397,   445,     0,
     460,     0,   300,   436,   276,     0,   100,   152,   334,     0,
       0,   375,     0,   109,     0,   351,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   619,   633,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   620,
     621,   631,   632,     0,     0,     0,   458,     0,     0,   456,
     457,     0,   519,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   589,
     563,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   471,   472,   473,   517,   480,   518,   512,   513,   514,
     515,   511,   484,   474,   475,   476,   477,   478,   479,   481,
     482,   483,   485,   486,   516,   490,   491,   492,   493,   489,
     488,   494,   501,   502,   495,   496,   497,   487,   499,   509,
     510,   507,   508,   500,   498,   505,   506,   503,   504,     0,
       0,     0,     0,     0,     0,     0,    46,    47,    48,     0,
       0,     0,   661,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   651,   652,   653,   654,   655,   656,   657,
     659,   658,   660,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    69,    66,    64,    70,    71,    65,    55,
      68,    58,    59,    60,    56,    67,    61,    62,    63,    57,
       0,     0,     0,     0,   124,   125,   126,     0,     0,   349,
       0,     0,   347,   348,     0,    96,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   618,     0,     0,     0,
       0,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,   238,   241,   243,   244,
     245,   246,   247,   248,   249,   250,   239,   240,   242,   251,
     252,   253,     0,     0,     0,     0,     0,     0,     0,   425,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   401,
     402,   403,   404,   405,   406,   408,   407,   410,   414,   411,
     412,   413,   409,   451,     0,     0,     0,   448,   449,   450,
       0,     0,   455,   466,     0,     0,     0,   463,   464,   465,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,     0,
       0,     0,   317,     0,     0,     0,     0,     0,     0,   303,
     304,   305,   306,   311,   307,   308,   309,   310,   442,     0,
       0,     0,   439,   440,   441,     0,     0,     0,   278,     0,
     288,     0,   286,   287,   289,   290,    49,     0,     0,     0,
      45,     0,     0,     0,     0,   103,   104,   105,     0,     0,
       0,   201,     0,     0,     0,     0,   175,     0,     0,     0,
     155,   156,   157,   158,   159,   162,   163,   164,   161,   160,
     165,     0,     0,     0,     0,     0,   337,   338,   339,   340,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     650,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,   383,     0,   378,   379,   380,   127,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   112,
     113,   115,   114,   116,     0,     0,   346,     0,     0,   361,
       0,     0,   354,   355,   356,   357,     0,     0,     0,    90,
       0,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   617,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,   415,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   399,     0,     0,     0,   447,     0,   454,     0,     0,
       0,   462,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   469,   312,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   302,     0,     0,     0,   438,   291,     0,     0,
       0,     0,     0,   285,     0,     0,    44,   106,     0,     0,
       0,   102,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,   341,     0,     0,     0,     0,
     336,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     649,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,   381,
       0,     0,     0,   377,     0,   122,     0,   117,     0,     0,
       0,     0,     0,   111,     0,   345,   358,     0,     0,     0,
       0,   353,    99,    98,    97,   647,    28,    28,    28,    28,
      28,    28,    28,    30,    29,   648,   635,   636,   637,   638,
     639,   640,   641,   642,   645,   646,   643,   644,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   398,     0,     0,   446,   459,     0,     0,   461,   533,
     537,   520,   521,   552,   524,   615,   616,   560,   525,   526,
     557,   532,   531,   540,   530,   527,   528,   536,   535,   534,
     558,   522,   613,   614,   556,   599,   593,   609,   594,   595,
     596,   604,   612,   597,   606,   610,   600,   611,   601,   605,
     598,   608,   603,   602,   607,     0,   592,   572,   573,   574,
     567,   585,   568,   569,   570,   580,   588,   571,   582,   586,
     576,   587,   577,   581,   575,   584,   579,   578,   583,     0,
     566,   553,   551,   554,   559,   555,   542,   549,   550,   547,
     548,   543,   544,   545,   546,   561,   562,   529,   539,   538,
     541,   523,     0,     0,     0,     0,     0,     0,     0,     0,
     301,     0,     0,   437,     0,     0,     0,   296,   292,   295,
     277,    50,    51,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,     0,     0,     0,
     335,   665,   662,   663,   664,   669,   668,   670,   666,   667,
      86,    81,    89,    80,    87,    88,    79,    83,    82,    74,
      73,    78,    75,    77,    76,    84,    85,     0,     0,   376,
     128,     0,     0,     0,   140,     0,   132,   133,   135,   134,
       0,     0,     0,     0,   110,   350,     0,     0,     0,   352,
      31,    32,    33,    34,    35,    36,    37,   265,   266,   258,
     275,   274,     0,   273,   259,   261,   269,   262,   260,   268,
     255,   267,   257,   256,    38,    38,    38,    40,    39,   263,
     264,   420,   423,   424,   434,   431,   417,   432,   429,   430,
       0,   428,   433,   416,   422,   419,   421,   435,   418,   452,
     453,   467,   468,   590,     0,   564,     0,   315,   316,   326,
     322,   323,   325,   330,   327,   328,   321,   329,   324,     0,
     320,   314,   333,   332,   331,   313,   444,   443,   299,   298,
     283,   284,   282,     0,   281,     0,     0,     0,   107,   108,
     174,   171,   221,   233,   208,   217,     0,   206,   211,   227,
       0,   220,   225,   231,   210,   213,   222,   224,   228,   218,
     226,   214,   232,   216,   223,   212,   215,     0,   204,   167,
     169,   172,   173,   184,   185,   186,   179,   197,   180,   181,
     182,   192,   200,   183,   194,   198,   188,   199,   189,   193,
     187,   196,   191,   190,   195,     0,   178,   168,   170,   344,
     342,   343,   382,   387,   393,   396,   389,   395,   390,   394,
     392,   388,   391,     0,   386,   136,     0,     0,     0,     0,
     131,   119,   118,   120,   121,   359,   365,   371,   374,   367,
     373,   368,   372,   370,   366,   369,     0,   364,   360,   271,
       0,    41,    42,    43,   426,     0,   591,   565,   318,     0,
     279,     0,   297,   294,   293,     0,     0,     0,     0,     0,
       0,   202,     0,   176,     0,   384,     0,     0,     0,     0,
       0,   130,   362,     0,   272,   427,   319,   280,   207,   230,
     205,   229,   219,   209,   203,   177,   385,   137,   139,   138,
     150,   149,   145,   147,   151,   148,   144,   146,     0,   143,
     363,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -749,  -749,  -749,  -139,  -310,  -748,  -641,  -749,  -749,   951,
    -749,  -749,  -749,  -749,   968,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  1057,  -749,  -749,  -749,  -749,  -749,
    -749,   635,  -749,  -749,  -749,  -749,  -749,   559,  -749,  -749,
    -749,  -749,  -749,  -749,   760,  -749,  -749,  -749,  -749,    91,
    -749,  -749,  -749,  -749,  -749,  -170,  -749,  -749,  -749,   634,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -129,  -749,  -749,  -749,  -131,  -749,  -749,  -749,   982,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -104,  -749,
    -749,  -749,  -749,  -749,  -113,  -749,   669,  -749,  -749,  -749,
       6,  -749,  -749,  -749,  -749,  -749,   691,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -108,  -749,  -749,  -749,  -749,  -749,
    -749,   628,  -749,  -749,  -749,  -749,  -749,   870,  -749,  -749,
    -749,  -749,   565,  -749,  -749,  -749,  -749,  -749,  -125,  -749,
    -749,  -749,   598,  -749,  -749,  -749,  -749,  -109,  -749,  -749,
    -749,   983,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,   -92,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,   714,  -749,  -749,  -749,  -749,  -749,   800,  -749,
    -749,  -749,  -749,  1060,  -749,  -749,  -749,  -749,   803,  -749,
    -749,  -749,  -749,  1037,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,    82,  -749,
    -749,  -749,    86,  -749,  -749,  -749,  -749,  -749,  -749,  1114,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,   984,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   833,   834,  1097,  1098,    27,   225,   226,
     227,   228,    28,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,    29,    77,    78,    79,    80,    81,    30,    63,
     504,   505,   506,   507,    31,    70,   588,   589,   590,   591,
     592,   593,    32,   293,   294,   295,   296,   297,  1055,  1056,
    1057,  1058,  1059,  1238,  1318,  1319,    33,    64,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   760,
    1215,  1216,   530,   755,  1187,  1188,    34,    53,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   630,  1082,  1083,    35,
      61,   490,   740,  1153,  1154,   491,   492,   493,  1157,   998,
     999,   494,   495,    36,    59,   468,   469,   470,   471,   472,
     473,   474,   725,  1139,  1140,   475,   476,   477,    37,    65,
     535,   536,   537,   538,   539,    38,   301,   302,   303,    39,
      72,   601,   602,   603,   604,   605,   818,  1256,  1257,    40,
      68,   574,   575,   576,   577,   801,  1233,  1234,    41,    54,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   652,  1110,  1111,   388,   389,   390,   391,   392,    42,
      60,   481,   482,   483,   484,    43,    55,   396,   397,   398,
     399,    44,   118,   119,   120,    45,    57,   406,   407,   408,
     409,    46,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   437,   959,   960,   214,
     436,   935,   936,   215,   216,   217,   218,    47,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    48,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     863,   864,   612,    73,   485,   615,   616,   617,   597,   619,
     620,   531,   116,  1108,   222,   116,   403,  1051,    51,   299,
     291,   706,   403,   299,    73,   707,   393,   862,   291,    49,
      50,   362,    74,   363,   501,   364,   597,  1080,    52,   478,
      75,   708,   393,  1123,    56,   709,  1125,  1124,  1150,   365,
    1126,   532,    58,    74,    62,   531,   253,  1051,   122,   486,
     478,    75,   583,   123,   124,   571,   125,   126,   487,   366,
     488,   127,    66,  1259,  1264,   571,   117,  1260,  1265,   117,
     128,   129,   130,   254,    67,   255,   367,    69,   368,   131,
     394,   533,   132,   133,   134,   532,  1268,   369,  1270,   135,
    1269,   673,  1271,   675,   676,    76,   394,   679,   222,   370,
     598,  1081,   256,   223,   502,   687,   136,   137,   404,  1052,
     692,   300,  1288,   257,   404,   300,    76,   489,   138,   701,
     702,   139,   140,   371,   224,   533,  1281,   534,   598,   141,
    1282,   715,   405,   717,   718,   232,   258,   142,   405,   143,
     259,   144,   395,   145,   372,   146,   147,   501,   260,  1052,
      71,   261,   262,   113,   584,   479,   148,   572,   395,   114,
     115,   149,   150,   373,   151,   152,   153,   572,   233,   154,
     121,   534,   374,   219,   583,   459,   479,   234,   235,   236,
     263,  1151,   237,   238,  -129,   220,   221,   239,   240,   241,
    1152,   229,  -129,   460,   155,  1109,   264,   223,   503,   265,
     266,   267,  1053,   230,   156,   157,   158,   159,   160,   161,
     162,  1283,   327,   461,   231,  1284,   508,   599,   224,   585,
     600,   375,   773,   306,   309,   742,  1054,   502,   328,   329,
     305,   292,   769,   330,   509,   499,   401,   586,  1239,   292,
     595,   462,  1053,   670,   376,   599,   268,   664,   600,   580,
     307,   480,   660,   587,   510,   750,   308,   820,   867,   868,
     163,   164,   165,   290,   166,   167,  1054,    82,   298,   269,
     270,   304,   480,   168,   573,   169,   584,   569,   331,   457,
     613,   735,   511,   812,   573,   582,   802,  1285,  1094,  1095,
    1096,  1286,    83,    84,   463,   311,   332,   333,   334,    85,
     335,   312,   464,   465,   336,   485,  1292,   459,   337,   850,
    1293,  1321,   313,   854,   338,  1322,   857,   314,   512,   315,
     861,   503,   466,   339,   340,   460,   316,    86,    87,    88,
      89,  1310,   317,  1311,   341,   513,  1261,  1262,  1263,   318,
     319,   585,    90,    91,    92,   461,   320,   321,   322,    93,
      94,    95,   323,   324,    96,   342,   400,   410,   508,   586,
     486,   411,   412,   413,   414,   415,   549,   514,   515,   487,
    1223,   488,   416,   462,   417,   587,   509,  1312,   122,   418,
     496,   419,   420,   123,   124,   421,   125,   126,   862,   422,
     423,   127,   424,   425,  1313,   426,   510,   467,   427,   343,
     128,   129,   130,   428,   429,   430,   731,   610,   806,   131,
     431,   432,   132,   133,   134,   433,   434,   435,   516,   135,
     438,  1246,   439,   440,   511,  1129,   463,   441,   489,   442,
     443,  1224,  1314,  1315,   464,   465,   136,   137,   517,   444,
     445,   446,   518,   643,   447,   551,   448,   763,   138,   578,
    1130,   139,   140,   449,   466,   450,   451,   452,   453,   141,
     512,   454,  1225,   455,   456,   497,   498,   142,   540,   143,
    1226,   144,   541,   145,   542,   146,   147,   513,   543,  1227,
     544,   545,  1247,  1131,  1316,  1162,   148,   546,   547,   548,
    1317,   149,   150,   552,   151,   152,   153,   553,   325,   154,
     606,  1163,  1164,  1228,   554,  1229,  1230,   555,   556,   514,
     515,   607,  1165,  1248,  1132,  1133,   557,   558,   559,  1231,
    1134,  1249,   560,   561,   155,   562,   563,  1232,   564,   467,
    1250,   565,   608,   566,   156,   157,   158,   159,   160,   161,
     162,   567,   253,   568,  1135,   579,   594,   609,   611,   614,
    1166,  1167,   618,  1168,  1251,   621,  1252,  1253,   622,  1136,
     516,   362,   623,   363,   624,   364,   625,   626,   627,   254,
    1254,   255,   628,   629,   631,   632,   633,   634,  1255,   365,
     517,  1169,   635,   645,   518,   636,  1289,   637,   638,  1170,
     163,   164,   165,   639,   166,   167,   640,   641,   256,   366,
     642,   646,   647,   168,   648,   169,   649,   650,   651,   257,
     653,  1171,   654,  1172,  1173,   655,   367,   656,   368,   657,
     666,  1137,   658,   659,   662,   663,   667,   369,   668,   672,
     669,  1174,   258,   674,   677,   678,   259,   680,   681,   370,
    1138,   682,   683,   684,   260,   685,   686,   261,   262,   688,
     689,   690,   327,  1175,   691,   693,   694,   695,  1176,   696,
     697,   698,  1177,   371,   915,   714,  1178,   700,   328,   329,
     699,  1179,   703,   330,   704,  1180,   263,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,   372,   705,  1181,   710,  1182,  1183,
     711,  1184,   264,   720,   712,   265,   266,   267,   713,   716,
     719,   721,  1185,   373,   744,     2,     3,   722,   723,     4,
    1186,   724,   374,   726,   727,   737,   745,   728,   331,   729,
     774,     5,   771,   730,     6,   733,     7,   734,   738,   746,
     937,   739,   938,   939,     8,   741,   332,   333,   334,   747,
     335,   748,   268,   749,   336,   752,     9,   753,   337,   754,
     756,    10,    11,   757,   338,   758,   776,   759,   781,   761,
     762,   375,   766,   339,   340,   269,   270,   765,   767,   768,
     772,    12,   785,   775,   341,    13,  1193,   777,  1194,  1195,
     778,   916,   917,   918,   376,    14,   919,   920,   779,   921,
     922,   782,   923,   780,   924,   342,   783,   925,   784,   926,
     927,   611,   786,   787,   788,   928,    15,    16,   789,   929,
     790,   791,   792,   930,   931,   932,   798,   793,   794,   795,
     933,    17,   796,   797,   799,   934,   826,   827,   828,   829,
     830,   831,   832,   800,   804,   805,   807,   808,    18,   343,
     809,   810,   811,   814,   815,   816,   817,   940,   941,   942,
      19,    20,   943,   944,   819,   945,   946,   822,   947,   823,
     948,   824,   848,   949,   825,   950,   951,   835,   836,   837,
     838,   952,   839,   840,    21,   953,   841,   842,   849,   954,
     955,   956,    82,   843,   844,   845,   957,    22,   846,   847,
     851,   958,    23,  1196,  1197,  1198,   852,    24,  1199,  1200,
      25,  1201,  1202,   853,  1203,   855,  1204,    83,    84,  1205,
     856,  1206,  1207,   858,    85,   859,   860,  1208,   862,   865,
     866,  1209,   869,   870,   876,  1210,  1211,  1212,   232,   873,
     881,   871,  1213,   872,   874,   875,   877,  1214,   884,   878,
     879,   880,    86,    87,    88,    89,   882,   883,   885,   886,
     887,   888,   889,   890,   891,   892,   893,    90,    91,    92,
     894,   233,   895,   896,    93,    94,    95,   897,   898,    96,
     234,   235,   236,   899,   900,   237,   238,   901,   902,   903,
     239,   240,   241,   904,   905,   906,   907,   908,   909,   910,
     911,   912,   913,   914,   961,   962,   963,   964,   982,   965,
     966,   967,   968,   969,   970,   971,   972,   973,   974,   975,
     976,   977,   978,   979,   980,   981,   985,   986,   987,   988,
     984,   989,   990,   991,   983,   992,   994,   993,   995,   997,
    1003,  1000,   996,  1001,  1002,  1004,  1006,  1009,  1007,  1010,
    1011,  1012,  1014,   581,  1015,  1017,  1018,  1019,  1005,  1047,
    1060,  1016,  1008,  1013,  1020,  1061,  1062,  1063,  1021,  1022,
    1066,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,
    1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,
    1042,  1043,  1044,  1045,  1046,  1068,  1049,  1050,  1048,  1064,
    1065,  1067,  1069,  1077,  1078,  1079,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1272,  1092,  1093,  1099,  1100,  1101,
    1102,  1103,  1287,  1104,  1105,  1106,  1107,  1112,  1113,  1114,
    1115,  1116,  1298,  1117,   310,  1299,  1118,  1300,  1119,   751,
    1120,  1301,  1302,  1121,  1303,  1122,  1240,   813,  1127,  1128,
    1141,  1304,  1323,   764,  1142,  1305,  1294,  1143,  1297,   732,
     743,  1296,  1273,   770,  1144,  1155,   821,  1145,  1320,  1146,
    1147,   596,   803,  1295,  1148,  1149,   500,  1306,   402,  1158,
    1159,  1160,  1156,  1161,  1189,  1190,  1191,  1192,  1217,  1218,
    1219,  1220,  1221,  1222,  1235,   736,   665,  1241,  1236,  1237,
    1242,  1290,  1243,  1244,  1245,  1258,  1274,   458,  1267,   671,
    1266,   326,  1275,  1276,  1277,  1278,  1279,  1280,  1291,  1307,
    1308,  1309,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   570,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   644,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     661
};

static const yytype_int16 yycheck[] =
{
     641,   642,   312,     1,     1,   315,   316,   317,     1,   319,
     320,     1,     1,     8,     1,     1,     1,     1,   233,     1,
       1,   212,     1,     1,     1,   216,     1,   111,     1,   231,
     232,     1,    30,     3,     1,     5,     1,    52,   233,     1,
      38,   212,     1,   231,   233,   216,   231,   235,    48,    19,
     235,    41,   233,    30,   233,     1,     1,     1,     1,    56,
       1,    38,     1,     6,     7,     1,     9,    10,    65,    39,
      67,    14,   233,   231,   231,     1,    65,   235,   235,    65,
      23,    24,    25,    28,   233,    30,    56,   233,    58,    32,
      65,    81,    35,    36,    37,    41,   231,    67,   231,    42,
     235,   411,   235,   413,   414,   103,    65,   417,     1,    79,
     103,   126,    57,   100,    81,   425,    59,    60,   103,   103,
     430,   103,   206,    68,   103,   103,   103,   124,    71,   439,
     440,    74,    75,   103,   121,    81,   231,   127,   103,    82,
     235,   451,   127,   453,   454,     1,    91,    90,   127,    92,
      95,    94,   127,    96,   124,    98,    99,     1,   103,   103,
     233,   106,   107,   233,   103,   127,   109,   103,   127,   233,
     233,   114,   115,   143,   117,   118,   119,   103,    34,   122,
     233,   127,   152,   233,     1,     1,   127,    43,    44,    45,
     135,   191,    48,    49,   175,   233,   233,    53,    54,    55,
     200,   233,   175,    19,   147,   200,   151,   100,   175,   154,
     155,   156,   196,   233,   157,   158,   159,   160,   161,   162,
     163,   231,     1,    39,   233,   235,     1,   220,   121,   168,
     223,   201,   542,   234,   232,   232,   220,    81,    17,    18,
     231,   222,   232,    22,    19,   232,   232,   186,   232,   222,
     232,    67,   196,   232,   224,   220,   201,   232,   223,   232,
     234,   223,   232,   202,    39,   232,   234,   232,   179,   180,
     213,   214,   215,   233,   217,   218,   220,     1,   233,   224,
     225,   233,   223,   226,   220,   228,   103,   232,    67,   232,
     212,   232,    67,   232,   220,   175,   232,   231,    11,    12,
      13,   235,    26,    27,   120,   234,    85,    86,    87,    33,
      89,   234,   128,   129,    93,     1,   231,     1,    97,   629,
     235,   231,   234,   633,   103,   235,   636,   234,   103,   234,
     640,   175,   148,   112,   113,    19,   234,    61,    62,    63,
      64,    70,   234,    72,   123,   120,  1094,  1095,  1096,   234,
     234,   168,    76,    77,    78,    39,   234,   234,   234,    83,
      84,    85,   234,   234,    88,   144,   234,   234,     1,   186,
      56,   234,   234,   234,   234,   234,   232,   152,   153,    65,
      72,    67,   234,    67,   234,   202,    19,   116,     1,   234,
     231,   234,   234,     6,     7,   234,     9,    10,   111,   234,
     234,    14,   234,   234,   133,   234,    39,   223,   234,   188,
      23,    24,    25,   234,   234,   234,   232,   111,   233,    32,
     234,   234,    35,    36,    37,   234,   234,   234,   203,    42,
     234,    72,   234,   234,    67,    15,   120,   234,   124,   234,
     234,   133,   171,   172,   128,   129,    59,    60,   223,   234,
     234,   234,   227,   232,   234,   231,   234,   232,    71,   231,
      40,    74,    75,   234,   148,   234,   234,   234,   234,    82,
     103,   234,   164,   234,   234,   234,   234,    90,   234,    92,
     172,    94,   234,    96,   234,    98,    99,   120,   234,   181,
     234,   234,   133,    73,   223,     4,   109,   234,   234,   234,
     229,   114,   115,   234,   117,   118,   119,   234,   232,   122,
     125,    20,    21,   205,   234,   207,   208,   234,   234,   152,
     153,   125,    31,   164,   104,   105,   234,   234,   234,   221,
     110,   172,   234,   234,   147,   234,   234,   229,   234,   223,
     181,   234,   125,   234,   157,   158,   159,   160,   161,   162,
     163,   234,     1,   234,   134,   234,   234,   231,   111,   111,
      69,    70,   111,    72,   205,   111,   207,   208,   111,   149,
     203,     1,   111,     3,   111,     5,   231,   231,   234,    28,
     221,    30,   234,   234,   234,   234,   234,   234,   229,    19,
     223,   100,   234,   231,   227,   234,  1237,   234,   234,   108,
     213,   214,   215,   234,   217,   218,   234,   234,    57,    39,
     234,   234,   234,   226,   234,   228,   234,   234,   234,    68,
     234,   130,   234,   132,   133,   234,    56,   234,    58,   234,
     125,   211,   234,   234,   234,   234,   231,    67,   234,   212,
     234,   150,    91,   111,   212,   111,    95,   212,   111,    79,
     230,   111,   111,   212,   103,   212,   212,   106,   107,   111,
     111,   111,     1,   172,   111,   111,   111,   111,   177,   111,
     212,   234,   181,   103,    48,   111,   185,   212,    17,    18,
     234,   190,   212,    22,   212,   194,   135,   826,   827,   828,
     829,   830,   831,   832,   124,   212,   205,   212,   207,   208,
     212,   210,   151,   111,   212,   154,   155,   156,   212,   212,
     212,   231,   221,   143,   125,     0,     1,   231,   234,     4,
     229,   234,   152,   234,   234,   231,   125,   234,    67,   234,
     125,    16,   212,   234,    19,   234,    21,   234,   234,   231,
      48,   234,    50,    51,    29,   234,    85,    86,    87,   231,
      89,   234,   201,   234,    93,   231,    41,   234,    97,   234,
     234,    46,    47,   234,   103,   234,   125,   234,   111,   234,
     234,   201,   234,   112,   113,   224,   225,   231,   234,   234,
     212,    66,   111,   212,   123,    70,    48,   212,    50,    51,
     212,   165,   166,   167,   224,    80,   170,   171,   212,   173,
     174,   125,   176,   231,   178,   144,   212,   181,   125,   183,
     184,   111,   111,   125,   125,   189,   101,   102,   125,   193,
     125,   125,   125,   197,   198,   199,   231,   125,   125,   125,
     204,   116,   125,   125,   231,   209,   136,   137,   138,   139,
     140,   141,   142,   234,   212,   231,   231,   234,   133,   188,
     234,   234,   234,   125,   231,   231,   234,   165,   166,   167,
     145,   146,   170,   171,   234,   173,   174,   231,   176,   231,
     178,   231,   111,   181,   231,   183,   184,   231,   231,   231,
     231,   189,   231,   231,   169,   193,   231,   231,   111,   197,
     198,   199,     1,   231,   231,   231,   204,   182,   231,   231,
     234,   209,   187,   165,   166,   167,   111,   192,   170,   171,
     195,   173,   174,   111,   176,   111,   178,    26,    27,   181,
     111,   183,   184,   125,    33,   111,   111,   189,   111,   231,
     125,   193,   125,   212,   111,   197,   198,   199,     1,   234,
     231,   125,   204,   125,   125,   125,   125,   209,   231,   125,
     125,   125,    61,    62,    63,    64,   125,   125,   231,   125,
     125,   231,   231,   231,   231,   231,   231,    76,    77,    78,
     231,    34,   231,   231,    83,    84,    85,   231,   231,    88,
      43,    44,    45,   231,   231,    48,    49,   231,   231,   231,
      53,    54,    55,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   125,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   125,   111,   125,   125,
     234,   125,   231,   125,   212,   125,   125,   231,   125,   111,
     125,   231,   234,   231,   231,   125,   125,   125,   212,   125,
     125,   212,   125,   293,   125,   125,   125,   125,   231,   125,
     125,   231,   234,   234,   231,   125,   125,   125,   231,   231,
     125,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   125,   231,   231,   234,   231,
     231,   234,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   111,   231,   231,   231,   231,   231,
     231,   231,   125,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   131,   231,    77,   133,   231,   131,   231,   504,
     231,   133,   131,   231,   131,   231,  1055,   588,   231,   231,
     231,  1282,  1322,   519,   231,  1284,  1260,   231,  1271,   468,
     491,  1269,  1156,   535,   231,   219,   601,   231,  1293,   231,
     231,   301,   574,  1265,   231,   231,   225,  1286,   118,   231,
     231,   231,   235,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   481,   396,   231,   234,   234,
     231,   234,   231,   231,   231,   231,   231,   170,  1126,   406,
    1124,    97,   236,   236,   236,   236,   236,   236,   231,   231,
     231,   231,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   344,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     377
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   238,     0,     1,     4,    16,    19,    21,    29,    41,
      46,    47,    66,    70,    80,   101,   102,   116,   133,   145,
     146,   169,   182,   187,   192,   195,   239,   244,   249,   269,
     275,   281,   289,   303,   323,   346,   360,   375,   382,   386,
     396,   405,   426,   432,   438,   442,   448,   504,   521,   231,
     232,   233,   233,   324,   406,   433,   233,   443,   233,   361,
     427,   347,   233,   276,   304,   376,   233,   233,   397,   233,
     282,   233,   387,     1,    30,    38,   103,   270,   271,   272,
     273,   274,     1,    26,    27,    33,    61,    62,    63,    64,
      76,    77,    78,    83,    84,    85,    88,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   233,   233,   233,     1,    65,   439,   440,
     441,   233,     1,     6,     7,     9,    10,    14,    23,    24,
      25,    32,    35,    36,    37,    42,    59,    60,    71,    74,
      75,    82,    90,    92,    94,    96,    98,    99,   109,   114,
     115,   117,   118,   119,   122,   147,   157,   158,   159,   160,
     161,   162,   163,   213,   214,   215,   217,   218,   226,   228,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   496,   500,   501,   502,   503,   233,
     233,   233,     1,   100,   121,   245,   246,   247,   248,   233,
     233,   233,     1,    34,    43,    44,    45,    48,    49,    53,
      54,    55,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,     1,    28,    30,    57,    68,    91,    95,
     103,   106,   107,   135,   151,   154,   155,   156,   201,   224,
     225,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     233,     1,   222,   290,   291,   292,   293,   294,   233,     1,
     103,   383,   384,   385,   233,   231,   234,   234,   234,   232,
     271,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   232,   506,     1,    17,    18,
      22,    67,    85,    86,    87,    89,    93,    97,   103,   112,
     113,   123,   144,   188,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,     1,     3,     5,    19,    39,    56,    58,    67,
      79,   103,   124,   143,   152,   201,   224,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   421,   422,
     423,   424,   425,     1,    65,   127,   434,   435,   436,   437,
     234,   232,   440,     1,   103,   127,   444,   445,   446,   447,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   497,   493,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   232,   450,     1,
      19,    39,    67,   120,   128,   129,   148,   223,   362,   363,
     364,   365,   366,   367,   368,   372,   373,   374,     1,   127,
     223,   428,   429,   430,   431,     1,    56,    65,    67,   124,
     348,   352,   353,   354,   358,   359,   231,   234,   234,   232,
     246,     1,    81,   175,   277,   278,   279,   280,     1,    19,
      39,    67,   103,   120,   152,   153,   203,   223,   227,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     319,     1,    41,    81,   127,   377,   378,   379,   380,   381,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   232,
     523,   231,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   232,
     251,     1,   103,   220,   398,   399,   400,   401,   231,   234,
     232,   291,   175,     1,   103,   168,   186,   202,   283,   284,
     285,   286,   287,   288,   234,   232,   384,     1,   103,   220,
     223,   388,   389,   390,   391,   392,   125,   125,   125,   231,
     111,   111,   241,   212,   111,   241,   241,   241,   111,   241,
     241,   111,   111,   111,   111,   231,   231,   234,   234,   234,
     343,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   232,   326,   231,   234,   234,   234,   234,
     234,   234,   418,   234,   234,   234,   234,   234,   234,   234,
     232,   408,   234,   234,   232,   435,   125,   231,   234,   234,
     232,   445,   212,   241,   111,   241,   241,   212,   111,   241,
     212,   111,   111,   111,   212,   212,   212,   241,   111,   111,
     111,   111,   241,   111,   111,   111,   111,   212,   234,   234,
     212,   241,   241,   212,   212,   212,   212,   216,   212,   216,
     212,   212,   212,   212,   111,   241,   212,   241,   241,   212,
     111,   231,   231,   234,   234,   369,   234,   234,   234,   234,
     234,   232,   363,   234,   234,   232,   429,   231,   234,   234,
     349,   234,   232,   353,   125,   125,   231,   231,   234,   234,
     232,   278,   231,   234,   234,   320,   234,   234,   234,   234,
     316,   234,   234,   232,   306,   231,   234,   234,   234,   232,
     378,   212,   212,   241,   125,   212,   125,   212,   212,   212,
     231,   111,   125,   212,   125,   111,   111,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   231,   231,
     234,   402,   232,   399,   212,   231,   233,   231,   234,   234,
     234,   234,   232,   284,   125,   231,   231,   234,   393,   234,
     232,   389,   231,   231,   231,   231,   136,   137,   138,   139,
     140,   141,   142,   240,   241,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   111,   111,
     241,   234,   111,   111,   241,   111,   111,   241,   125,   111,
     111,   241,   111,   243,   243,   231,   125,   179,   180,   125,
     212,   125,   125,   234,   125,   125,   111,   125,   125,   125,
     125,   231,   125,   125,   231,   231,   125,   125,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,    48,   165,   166,   167,   170,
     171,   173,   174,   176,   178,   181,   183,   184,   189,   193,
     197,   198,   199,   204,   209,   498,   499,    48,    50,    51,
     165,   166,   167,   170,   171,   173,   174,   176,   178,   181,
     183,   184,   189,   193,   197,   198,   199,   204,   209,   494,
     495,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   125,   212,   234,   125,   111,   125,   125,   125,
     231,   125,   125,   231,   125,   125,   234,   111,   356,   357,
     231,   231,   231,   125,   125,   231,   125,   212,   234,   125,
     125,   125,   212,   234,   125,   125,   231,   125,   125,   125,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   125,   234,   231,
     231,     1,   103,   196,   220,   295,   296,   297,   298,   299,
     125,   125,   125,   125,   231,   231,   125,   234,   125,   231,
     240,   240,   240,   240,   240,   240,   240,   231,   231,   231,
      52,   126,   344,   345,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,    11,    12,    13,   242,   243,   231,
     231,   231,   231,   231,   231,   231,   231,   231,     8,   200,
     419,   420,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   235,   231,   235,   231,   231,    15,
      40,    73,   104,   105,   110,   134,   149,   211,   230,   370,
     371,   231,   231,   231,   231,   231,   231,   231,   231,   231,
      48,   191,   200,   350,   351,   219,   235,   355,   231,   231,
     231,   231,     4,    20,    21,    31,    69,    70,    72,   100,
     108,   130,   132,   133,   150,   172,   177,   181,   185,   190,
     194,   205,   207,   208,   210,   221,   229,   321,   322,   231,
     231,   231,   231,    48,    50,    51,   165,   166,   167,   170,
     171,   173,   174,   176,   178,   181,   183,   184,   189,   193,
     197,   198,   199,   204,   209,   317,   318,   231,   231,   231,
     231,   231,   231,    72,   133,   164,   172,   181,   205,   207,
     208,   221,   229,   403,   404,   231,   234,   234,   300,   232,
     296,   231,   231,   231,   231,   231,    72,   133,   164,   172,
     181,   205,   207,   208,   221,   229,   394,   395,   231,   231,
     235,   242,   242,   242,   231,   235,   499,   495,   231,   235,
     231,   235,   111,   357,   231,   236,   236,   236,   236,   236,
     236,   231,   235,   231,   235,   231,   235,   125,   206,   243,
     234,   231,   231,   235,   345,   420,   371,   351,   131,   133,
     131,   133,   131,   131,   322,   318,   404,   231,   231,   231,
      70,    72,   116,   133,   171,   172,   223,   229,   301,   302,
     395,   231,   235,   302
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   237,   238,   238,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   240,   240,
     241,   241,   241,   241,   241,   241,   241,   241,   242,   242,
     243,   243,   243,   243,   244,   245,   245,   246,   246,   246,
     247,   248,   249,   250,   250,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   270,   271,   271,   271,   271,   272,   273,   274,
     276,   275,   277,   277,   278,   278,   278,   279,   280,   282,
     281,   283,   283,   284,   284,   284,   284,   284,   285,   286,
     287,   288,   289,   290,   290,   291,   291,   291,   292,   294,
     293,   295,   295,   296,   296,   296,   296,   297,   298,   298,
     300,   299,   301,   301,   302,   302,   302,   302,   302,   302,
     302,   302,   304,   303,   305,   305,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   316,   315,   317,   317,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   320,   319,   321,   321,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   324,   323,   325,   325,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     343,   342,   344,   344,   345,   345,   347,   346,   349,   348,
     350,   350,   351,   351,   351,   352,   352,   353,   353,   353,
     353,   353,   355,   354,   356,   356,   357,   357,   358,   359,
     361,   360,   362,   362,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   364,   365,   366,   367,   369,   368,   370,
     370,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   372,   373,   374,   376,   375,   377,   377,   378,   378,
     378,   378,   379,   380,   381,   382,   383,   383,   384,   384,
     385,   387,   386,   388,   388,   389,   389,   389,   389,   390,
     391,   393,   392,   394,   394,   395,   395,   395,   395,   395,
     395,   395,   395,   395,   395,   397,   396,   398,   398,   399,
     399,   399,   400,   402,   401,   403,   403,   404,   404,   404,
     404,   404,   404,   404,   404,   404,   404,   406,   405,   407,
     407,   408,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   408,   408,   408,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   416,   418,   417,   419,   419,   420,
     420,   421,   422,   423,   424,   425,   427,   426,   428,   428,
     429,   429,   429,   430,   431,   433,   432,   434,   434,   435,
     435,   435,   436,   437,   438,   439,   439,   440,   440,   441,
     443,   442,   444,   444,   445,   445,   445,   446,   447,   448,
     449,   449,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   478,   479,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   493,   492,   494,   494,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   497,
     496,   498,   498,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   500,   501,   502,   503,   504,   505,   505,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   522,   523,   523,   523,   523,   523,   523,   523,   523,
     523,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532
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
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     2,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     2,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     0,     6,     0,     5,
       3,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     0,     5,     3,     1,     1,     3,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     2,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     4,     4,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4
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
#line 407 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 408 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 409 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 410 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 435 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2969 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 474 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_certificate_file);
    ConfigServerInfo.ssl_certificate_file = xstrdup(yylval.string);
  }
}
#line 2990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 483 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 3002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 492 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_param_file);
    ConfigServerInfo.ssl_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 501 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_cipher_list);
    ConfigServerInfo.ssl_cipher_list = xstrdup(yylval.string);
  }
}
#line 3026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 510 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_message_digest_algorithm);
    ConfigServerInfo.ssl_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 519 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_elliptic_curve);
    ConfigServerInfo.ssl_dh_elliptic_curve = xstrdup(yylval.string);
  }
}
#line 3050 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 528 "conf_parser.y" /* yacc.c:1646  */
    {
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.name)
  {
    if (server_valid_name(yylval.string))
      ConfigServerInfo.name = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 543 "conf_parser.y" /* yacc.c:1646  */
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
#line 3086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 558 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 568 "conf_parser.y" /* yacc.c:1646  */
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
#line 3116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 582 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 591 "conf_parser.y" /* yacc.c:1646  */
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
#line 3159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 619 "conf_parser.y" /* yacc.c:1646  */
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
#line 3190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 647 "conf_parser.y" /* yacc.c:1646  */
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
#line 3218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 672 "conf_parser.y" /* yacc.c:1646  */
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
#line 3243 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 694 "conf_parser.y" /* yacc.c:1646  */
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
#line 3268 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 716 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3277 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 734 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3289 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 743 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 752 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3313 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 765 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3322 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 769 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3339 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 786 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 792 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 802 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 806 "conf_parser.y" /* yacc.c:1646  */
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
#line 3384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 824 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 830 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 836 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3411 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 842 "conf_parser.y" /* yacc.c:1646  */
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
#line 3432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 870 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 876 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 880 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 896 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 904 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 907 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3490 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 912 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3499 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 919 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3508 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 923 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 927 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3526 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 931 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3535 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 935 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3544 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3553 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 943 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3562 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 957 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 964 "conf_parser.y" /* yacc.c:1646  */
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
#line 3640 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1031 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1043 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3676 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3690 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3699 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1072 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3713 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1083 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3722 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1089 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3731 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1096 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3740 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1100 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1104 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3758 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1108 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3767 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1112 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1116 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3785 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1120 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1124 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3803 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1128 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3812 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1132 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3821 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1136 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3830 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1140 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3839 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1144 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3848 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1148 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3857 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1152 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1156 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1160 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1164 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1168 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1172 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1176 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1180 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1186 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1193 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1201 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1205 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1209 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1213 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1217 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4010 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1225 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4019 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4028 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1237 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1245 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1253 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4082 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1257 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4091 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1261 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4100 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4109 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4145 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4154 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4163 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4172 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4199 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1315 "conf_parser.y" /* yacc.c:1646  */
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
#line 4216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1327 "conf_parser.y" /* yacc.c:1646  */
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
#line 4263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1390 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1396 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4281 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1402 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4290 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1408 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4299 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1414 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4308 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1420 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4317 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1426 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1432 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4335 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1438 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1444 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4354 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1451 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4363 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1457 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1463 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1469 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1478 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1487 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1494 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1498 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1508 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1514 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4449 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1520 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4458 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1524 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4467 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1528 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1536 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1541 "conf_parser.y" /* yacc.c:1646  */
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
#line 4500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1554 "conf_parser.y" /* yacc.c:1646  */
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
#line 4520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1571 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1577 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4538 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1587 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1591 "conf_parser.y" /* yacc.c:1646  */
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
#line 4592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1644 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4601 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1650 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4610 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1656 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1662 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1673 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1680 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1684 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4660 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1688 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4669 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1692 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4678 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1696 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4687 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1700 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4696 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1704 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1708 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1712 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1716 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1722 "conf_parser.y" /* yacc.c:1646  */
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
#line 4749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1736 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4761 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1745 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1758 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4785 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1765 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4796 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1776 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4805 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1782 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1788 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1803 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1819 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1830 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4869 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1845 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4878 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1851 "conf_parser.y" /* yacc.c:1646  */
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
#line 4900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1870 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1877 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1881 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1885 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1889 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1893 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1897 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1901 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1905 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1909 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1913 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1923 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5013 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1932 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1945 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1951 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1958 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1966 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1970 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1974 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1978 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1982 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5107 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1986 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1990 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 1994 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2004 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5148 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2013 "conf_parser.y" /* yacc.c:1646  */
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
#line 5214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2093 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2099 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2105 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2111 "conf_parser.y" /* yacc.c:1646  */
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
#line 5257 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2124 "conf_parser.y" /* yacc.c:1646  */
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
#line 5273 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2137 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5282 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5291 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2149 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2153 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2159 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5317 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2165 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2169 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5335 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2175 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2186 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2198 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2204 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2219 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2223 "conf_parser.y" /* yacc.c:1646  */
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
#line 5424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2248 "conf_parser.y" /* yacc.c:1646  */
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
#line 5447 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2278 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2282 "conf_parser.y" /* yacc.c:1646  */
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
#line 5491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2314 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2329 "conf_parser.y" /* yacc.c:1646  */
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
#line 5526 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2346 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5535 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2350 "conf_parser.y" /* yacc.c:1646  */
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
#line 5555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 467:
#line 2370 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5564 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2376 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2439 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2444 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2449 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5597 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2454 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5605 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2459 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5614 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2465 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5622 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2470 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5630 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2475 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5638 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2480 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5646 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2485 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5654 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2490 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5662 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2495 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5670 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2500 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5678 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2505 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5686 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2510 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5694 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2515 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5702 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2520 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5710 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2525 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5718 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2530 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5726 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2535 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5735 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2541 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5743 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2546 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5751 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2551 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5759 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2556 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5767 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2561 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2566 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5783 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2571 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2576 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5799 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2579 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5807 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2584 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2587 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2592 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5831 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2597 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5839 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2602 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2607 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2612 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2617 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2622 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2627 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2632 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2637 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2642 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2652 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2658 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2661 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2664 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2667 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5959 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2670 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2673 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2676 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2679 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2682 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2685 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2688 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2691 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6023 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2694 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6031 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2697 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2700 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2703 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2706 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6063 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2709 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2712 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2715 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2718 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6095 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2721 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2726 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2732 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2735 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2738 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2741 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2744 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2747 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2750 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6167 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2753 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6175 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2756 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2759 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6199 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2765 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6207 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2768 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6215 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2771 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2774 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6239 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6247 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2783 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2789 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6271 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2794 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6279 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2799 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6287 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6295 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2809 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6303 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6311 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2847 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6327 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6335 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6343 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2862 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6351 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 2867 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2877 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2882 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 2892 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 2897 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2902 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 2925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 2931 "conf_parser.y" /* yacc.c:1646  */
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
#line 6443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 2947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 2956 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 666:
#line 2962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 2968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 668:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 669:
#line 2983 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 670:
#line 2989 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6512 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6516 "conf_parser.c" /* yacc.c:1646  */
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
