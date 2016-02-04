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
    CIDR_BITLEN_IPV4 = 272,
    CIDR_BITLEN_IPV6 = 273,
    CLASS = 274,
    CLOSE = 275,
    CONNECT = 276,
    CONNECTFREQ = 277,
    CYCLE_ON_HOST_CHANGE = 278,
    DEFAULT_FLOODCOUNT = 279,
    DEFAULT_JOIN_FLOOD_COUNT = 280,
    DEFAULT_JOIN_FLOOD_TIME = 281,
    DEFAULT_MAX_CLIENTS = 282,
    DENY = 283,
    DESCRIPTION = 284,
    DIE = 285,
    DISABLE_AUTH = 286,
    DISABLE_FAKE_CHANNELS = 287,
    DISABLE_REMOTE_COMMANDS = 288,
    DLINE_MIN_CIDR = 289,
    DLINE_MIN_CIDR6 = 290,
    DOTS_IN_IDENT = 291,
    EMAIL = 292,
    ENCRYPTED = 293,
    EXCEED_LIMIT = 294,
    EXEMPT = 295,
    FAILED_OPER_NOTICE = 296,
    FLATTEN_LINKS = 297,
    FLATTEN_LINKS_DELAY = 298,
    FLATTEN_LINKS_FILE = 299,
    GECOS = 300,
    GENERAL = 301,
    HIDDEN = 302,
    HIDDEN_NAME = 303,
    HIDE_CHANS = 304,
    HIDE_IDLE = 305,
    HIDE_IDLE_FROM_OPERS = 306,
    HIDE_SERVER_IPS = 307,
    HIDE_SERVERS = 308,
    HIDE_SERVICES = 309,
    HOST = 310,
    HUB = 311,
    HUB_MASK = 312,
    IGNORE_BOGUS_TS = 313,
    INVISIBLE_ON_CONNECT = 314,
    INVITE_CLIENT_COUNT = 315,
    INVITE_CLIENT_TIME = 316,
    INVITE_DELAY_CHANNEL = 317,
    IP = 318,
    IRCD_AUTH = 319,
    IRCD_FLAGS = 320,
    IRCD_SID = 321,
    JOIN = 322,
    KILL = 323,
    KILL_CHASE_TIME_LIMIT = 324,
    KLINE = 325,
    KLINE_EXEMPT = 326,
    KLINE_MIN_CIDR = 327,
    KLINE_MIN_CIDR6 = 328,
    KNOCK_CLIENT_COUNT = 329,
    KNOCK_CLIENT_TIME = 330,
    KNOCK_DELAY_CHANNEL = 331,
    LEAF_MASK = 332,
    LISTEN = 333,
    MASK = 334,
    MAX_ACCEPT = 335,
    MAX_BANS = 336,
    MAX_CHANNELS = 337,
    MAX_GLOBAL = 338,
    MAX_IDENT = 339,
    MAX_IDLE = 340,
    MAX_LOCAL = 341,
    MAX_NICK_CHANGES = 342,
    MAX_NICK_LENGTH = 343,
    MAX_NICK_TIME = 344,
    MAX_NUMBER = 345,
    MAX_TARGETS = 346,
    MAX_TOPIC_LENGTH = 347,
    MAX_WATCH = 348,
    MIN_IDLE = 349,
    MIN_NONWILDCARD = 350,
    MIN_NONWILDCARD_SIMPLE = 351,
    MODULE = 352,
    MODULES = 353,
    MOTD = 354,
    NAME = 355,
    NEED_IDENT = 356,
    NEED_PASSWORD = 357,
    NETWORK_DESC = 358,
    NETWORK_NAME = 359,
    NICK = 360,
    NO_OPER_FLOOD = 361,
    NO_TILDE = 362,
    NUMBER = 363,
    NUMBER_PER_CIDR = 364,
    NUMBER_PER_IP = 365,
    OPER_ONLY_UMODES = 366,
    OPER_UMODES = 367,
    OPERATOR = 368,
    OPERS_BYPASS_CALLERID = 369,
    PACE_WAIT = 370,
    PACE_WAIT_SIMPLE = 371,
    PASSWORD = 372,
    PATH = 373,
    PING_COOKIE = 374,
    PING_TIME = 375,
    PORT = 376,
    QSTRING = 377,
    RANDOM_IDLE = 378,
    REASON = 379,
    REDIRPORT = 380,
    REDIRSERV = 381,
    REHASH = 382,
    REMOTE = 383,
    REMOTEBAN = 384,
    RESV = 385,
    RESV_EXEMPT = 386,
    RSA_PRIVATE_KEY_FILE = 387,
    SECONDS = 388,
    MINUTES = 389,
    HOURS = 390,
    DAYS = 391,
    WEEKS = 392,
    MONTHS = 393,
    YEARS = 394,
    SEND_PASSWORD = 395,
    SENDQ = 396,
    SERVERHIDE = 397,
    SERVERINFO = 398,
    SHORT_MOTD = 399,
    SPOOF = 400,
    SPOOF_NOTICE = 401,
    SQUIT = 402,
    SSL_CERTIFICATE_FILE = 403,
    SSL_CERTIFICATE_FINGERPRINT = 404,
    SSL_CONNECTION_REQUIRED = 405,
    SSL_DH_ELLIPTIC_CURVE = 406,
    SSL_DH_PARAM_FILE = 407,
    SSL_MESSAGE_DIGEST_ALGORITHM = 408,
    STATS_E_DISABLED = 409,
    STATS_I_OPER_ONLY = 410,
    STATS_K_OPER_ONLY = 411,
    STATS_M_OPER_ONLY = 412,
    STATS_O_OPER_ONLY = 413,
    STATS_P_OPER_ONLY = 414,
    STATS_U_OPER_ONLY = 415,
    T_ALL = 416,
    T_BOTS = 417,
    T_CALLERID = 418,
    T_CCONN = 419,
    T_COMMAND = 420,
    T_CLUSTER = 421,
    T_DEAF = 422,
    T_DEBUG = 423,
    T_DLINE = 424,
    T_EXTERNAL = 425,
    T_FARCONNECT = 426,
    T_FILE = 427,
    T_FULL = 428,
    T_GLOBOPS = 429,
    T_INVISIBLE = 430,
    T_IPV4 = 431,
    T_IPV6 = 432,
    T_LOCOPS = 433,
    T_LOG = 434,
    T_NCHANGE = 435,
    T_NONONREG = 436,
    T_OPME = 437,
    T_PREPEND = 438,
    T_PSEUDO = 439,
    T_RECVQ = 440,
    T_REJ = 441,
    T_RESTART = 442,
    T_SERVER = 443,
    T_SERVICE = 444,
    T_SERVNOTICE = 445,
    T_SET = 446,
    T_SHARED = 447,
    T_SIZE = 448,
    T_SKILL = 449,
    T_SOFTCALLERID = 450,
    T_SPY = 451,
    T_SSL = 452,
    T_SSL_CIPHER_LIST = 453,
    T_TARGET = 454,
    T_UMODES = 455,
    T_UNAUTH = 456,
    T_UNDLINE = 457,
    T_UNLIMITED = 458,
    T_UNRESV = 459,
    T_UNXLINE = 460,
    T_WALLOP = 461,
    T_WALLOPS = 462,
    T_WEBIRC = 463,
    TBOOL = 464,
    THROTTLE_COUNT = 465,
    THROTTLE_TIME = 466,
    TKLINE_EXPIRE_NOTICES = 467,
    TMASKED = 468,
    TS_MAX_DELTA = 469,
    TS_WARN_DELTA = 470,
    TWODOTS = 471,
    TYPE = 472,
    UNKLINE = 473,
    USE_LOGGING = 474,
    USER = 475,
    VHOST = 476,
    VHOST6 = 477,
    WARN_NO_CONNECT_BLOCK = 478,
    WHOIS = 479,
    XLINE = 480,
    XLINE_EXEMPT = 481
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
#define DEFAULT_JOIN_FLOOD_COUNT 280
#define DEFAULT_JOIN_FLOOD_TIME 281
#define DEFAULT_MAX_CLIENTS 282
#define DENY 283
#define DESCRIPTION 284
#define DIE 285
#define DISABLE_AUTH 286
#define DISABLE_FAKE_CHANNELS 287
#define DISABLE_REMOTE_COMMANDS 288
#define DLINE_MIN_CIDR 289
#define DLINE_MIN_CIDR6 290
#define DOTS_IN_IDENT 291
#define EMAIL 292
#define ENCRYPTED 293
#define EXCEED_LIMIT 294
#define EXEMPT 295
#define FAILED_OPER_NOTICE 296
#define FLATTEN_LINKS 297
#define FLATTEN_LINKS_DELAY 298
#define FLATTEN_LINKS_FILE 299
#define GECOS 300
#define GENERAL 301
#define HIDDEN 302
#define HIDDEN_NAME 303
#define HIDE_CHANS 304
#define HIDE_IDLE 305
#define HIDE_IDLE_FROM_OPERS 306
#define HIDE_SERVER_IPS 307
#define HIDE_SERVERS 308
#define HIDE_SERVICES 309
#define HOST 310
#define HUB 311
#define HUB_MASK 312
#define IGNORE_BOGUS_TS 313
#define INVISIBLE_ON_CONNECT 314
#define INVITE_CLIENT_COUNT 315
#define INVITE_CLIENT_TIME 316
#define INVITE_DELAY_CHANNEL 317
#define IP 318
#define IRCD_AUTH 319
#define IRCD_FLAGS 320
#define IRCD_SID 321
#define JOIN 322
#define KILL 323
#define KILL_CHASE_TIME_LIMIT 324
#define KLINE 325
#define KLINE_EXEMPT 326
#define KLINE_MIN_CIDR 327
#define KLINE_MIN_CIDR6 328
#define KNOCK_CLIENT_COUNT 329
#define KNOCK_CLIENT_TIME 330
#define KNOCK_DELAY_CHANNEL 331
#define LEAF_MASK 332
#define LISTEN 333
#define MASK 334
#define MAX_ACCEPT 335
#define MAX_BANS 336
#define MAX_CHANNELS 337
#define MAX_GLOBAL 338
#define MAX_IDENT 339
#define MAX_IDLE 340
#define MAX_LOCAL 341
#define MAX_NICK_CHANGES 342
#define MAX_NICK_LENGTH 343
#define MAX_NICK_TIME 344
#define MAX_NUMBER 345
#define MAX_TARGETS 346
#define MAX_TOPIC_LENGTH 347
#define MAX_WATCH 348
#define MIN_IDLE 349
#define MIN_NONWILDCARD 350
#define MIN_NONWILDCARD_SIMPLE 351
#define MODULE 352
#define MODULES 353
#define MOTD 354
#define NAME 355
#define NEED_IDENT 356
#define NEED_PASSWORD 357
#define NETWORK_DESC 358
#define NETWORK_NAME 359
#define NICK 360
#define NO_OPER_FLOOD 361
#define NO_TILDE 362
#define NUMBER 363
#define NUMBER_PER_CIDR 364
#define NUMBER_PER_IP 365
#define OPER_ONLY_UMODES 366
#define OPER_UMODES 367
#define OPERATOR 368
#define OPERS_BYPASS_CALLERID 369
#define PACE_WAIT 370
#define PACE_WAIT_SIMPLE 371
#define PASSWORD 372
#define PATH 373
#define PING_COOKIE 374
#define PING_TIME 375
#define PORT 376
#define QSTRING 377
#define RANDOM_IDLE 378
#define REASON 379
#define REDIRPORT 380
#define REDIRSERV 381
#define REHASH 382
#define REMOTE 383
#define REMOTEBAN 384
#define RESV 385
#define RESV_EXEMPT 386
#define RSA_PRIVATE_KEY_FILE 387
#define SECONDS 388
#define MINUTES 389
#define HOURS 390
#define DAYS 391
#define WEEKS 392
#define MONTHS 393
#define YEARS 394
#define SEND_PASSWORD 395
#define SENDQ 396
#define SERVERHIDE 397
#define SERVERINFO 398
#define SHORT_MOTD 399
#define SPOOF 400
#define SPOOF_NOTICE 401
#define SQUIT 402
#define SSL_CERTIFICATE_FILE 403
#define SSL_CERTIFICATE_FINGERPRINT 404
#define SSL_CONNECTION_REQUIRED 405
#define SSL_DH_ELLIPTIC_CURVE 406
#define SSL_DH_PARAM_FILE 407
#define SSL_MESSAGE_DIGEST_ALGORITHM 408
#define STATS_E_DISABLED 409
#define STATS_I_OPER_ONLY 410
#define STATS_K_OPER_ONLY 411
#define STATS_M_OPER_ONLY 412
#define STATS_O_OPER_ONLY 413
#define STATS_P_OPER_ONLY 414
#define STATS_U_OPER_ONLY 415
#define T_ALL 416
#define T_BOTS 417
#define T_CALLERID 418
#define T_CCONN 419
#define T_COMMAND 420
#define T_CLUSTER 421
#define T_DEAF 422
#define T_DEBUG 423
#define T_DLINE 424
#define T_EXTERNAL 425
#define T_FARCONNECT 426
#define T_FILE 427
#define T_FULL 428
#define T_GLOBOPS 429
#define T_INVISIBLE 430
#define T_IPV4 431
#define T_IPV6 432
#define T_LOCOPS 433
#define T_LOG 434
#define T_NCHANGE 435
#define T_NONONREG 436
#define T_OPME 437
#define T_PREPEND 438
#define T_PSEUDO 439
#define T_RECVQ 440
#define T_REJ 441
#define T_RESTART 442
#define T_SERVER 443
#define T_SERVICE 444
#define T_SERVNOTICE 445
#define T_SET 446
#define T_SHARED 447
#define T_SIZE 448
#define T_SKILL 449
#define T_SOFTCALLERID 450
#define T_SPY 451
#define T_SSL 452
#define T_SSL_CIPHER_LIST 453
#define T_TARGET 454
#define T_UMODES 455
#define T_UNAUTH 456
#define T_UNDLINE 457
#define T_UNLIMITED 458
#define T_UNRESV 459
#define T_UNXLINE 460
#define T_WALLOP 461
#define T_WALLOPS 462
#define T_WEBIRC 463
#define TBOOL 464
#define THROTTLE_COUNT 465
#define THROTTLE_TIME 466
#define TKLINE_EXPIRE_NOTICES 467
#define TMASKED 468
#define TS_MAX_DELTA 469
#define TS_WARN_DELTA 470
#define TWODOTS 471
#define TYPE 472
#define UNKLINE 473
#define USE_LOGGING 474
#define USER 475
#define VHOST 476
#define VHOST6 477
#define WARN_NO_CONNECT_BLOCK 478
#define WHOIS 479
#define XLINE 480
#define XLINE_EXEMPT 481

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 141 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 676 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 693 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1322

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  233
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  292
/* YYNRULES -- Number of rules.  */
#define YYNRULES  662
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1304

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   481

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
       2,     2,     2,     2,   231,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   232,   227,
       2,   230,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   229,     2,   228,     2,     2,     2,     2,
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
     225,   226
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   371,   371,   372,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   402,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   413,   413,
     414,   415,   416,   417,   424,   426,   426,   427,   427,   427,
     429,   435,   445,   447,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   468,   477,   486,   495,   504,   513,   522,
     537,   552,   562,   576,   585,   613,   641,   666,   688,   710,
     720,   722,   722,   723,   724,   725,   726,   728,   737,   746,
     760,   759,   777,   777,   778,   778,   778,   780,   786,   797,
     796,   815,   815,   816,   816,   816,   816,   816,   818,   824,
     830,   836,   858,   859,   859,   861,   861,   862,   864,   871,
     871,   884,   885,   887,   887,   888,   888,   890,   898,   901,
     907,   906,   912,   912,   913,   917,   921,   925,   929,   933,
     937,   941,   952,   951,  1008,  1008,  1009,  1010,  1011,  1012,
    1013,  1014,  1015,  1016,  1017,  1018,  1019,  1021,  1027,  1033,
    1039,  1045,  1056,  1062,  1073,  1080,  1079,  1085,  1085,  1086,
    1090,  1094,  1098,  1102,  1106,  1110,  1114,  1118,  1122,  1126,
    1130,  1134,  1138,  1142,  1146,  1150,  1154,  1158,  1162,  1166,
    1170,  1177,  1176,  1182,  1182,  1183,  1187,  1191,  1195,  1199,
    1203,  1207,  1211,  1215,  1219,  1223,  1227,  1231,  1235,  1239,
    1243,  1247,  1251,  1255,  1259,  1263,  1267,  1271,  1275,  1279,
    1283,  1287,  1291,  1295,  1306,  1305,  1362,  1362,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,
    1375,  1375,  1376,  1377,  1378,  1379,  1381,  1387,  1393,  1399,
    1405,  1411,  1417,  1423,  1429,  1435,  1441,  1448,  1454,  1460,
    1466,  1475,  1485,  1484,  1490,  1490,  1491,  1495,  1506,  1505,
    1512,  1511,  1516,  1516,  1517,  1521,  1525,  1531,  1531,  1532,
    1532,  1532,  1532,  1532,  1534,  1534,  1536,  1536,  1538,  1551,
    1568,  1574,  1585,  1584,  1626,  1626,  1627,  1628,  1629,  1630,
    1631,  1632,  1633,  1634,  1635,  1637,  1643,  1649,  1655,  1667,
    1666,  1672,  1672,  1673,  1677,  1681,  1685,  1689,  1693,  1697,
    1701,  1705,  1709,  1715,  1729,  1738,  1752,  1751,  1766,  1766,
    1767,  1767,  1767,  1767,  1769,  1775,  1781,  1791,  1793,  1793,
    1794,  1794,  1796,  1813,  1812,  1835,  1835,  1836,  1836,  1836,
    1836,  1838,  1844,  1864,  1863,  1869,  1869,  1870,  1874,  1878,
    1882,  1886,  1890,  1894,  1898,  1902,  1906,  1917,  1916,  1935,
    1935,  1936,  1936,  1936,  1938,  1945,  1944,  1950,  1950,  1951,
    1955,  1959,  1963,  1967,  1971,  1975,  1979,  1983,  1987,  1998,
    1997,  2069,  2069,  2070,  2071,  2072,  2073,  2074,  2075,  2076,
    2077,  2078,  2079,  2080,  2081,  2082,  2083,  2084,  2086,  2092,
    2098,  2104,  2117,  2130,  2136,  2142,  2146,  2153,  2152,  2157,
    2157,  2158,  2162,  2168,  2179,  2185,  2191,  2197,  2213,  2212,
    2238,  2238,  2239,  2239,  2239,  2241,  2261,  2272,  2271,  2298,
    2298,  2299,  2299,  2299,  2301,  2307,  2317,  2319,  2319,  2320,
    2320,  2322,  2340,  2339,  2362,  2362,  2363,  2363,  2363,  2365,
    2371,  2381,  2383,  2383,  2384,  2385,  2386,  2387,  2388,  2389,
    2390,  2391,  2392,  2393,  2394,  2395,  2396,  2397,  2398,  2399,
    2400,  2401,  2402,  2403,  2404,  2405,  2406,  2407,  2408,  2409,
    2410,  2411,  2412,  2413,  2414,  2415,  2416,  2417,  2418,  2419,
    2420,  2421,  2422,  2423,  2424,  2425,  2426,  2427,  2428,  2429,
    2432,  2437,  2442,  2447,  2453,  2458,  2463,  2468,  2473,  2478,
    2483,  2488,  2493,  2498,  2503,  2508,  2513,  2518,  2523,  2529,
    2534,  2539,  2544,  2549,  2554,  2559,  2564,  2567,  2572,  2575,
    2580,  2585,  2590,  2595,  2600,  2605,  2610,  2615,  2620,  2625,
    2630,  2635,  2641,  2640,  2645,  2645,  2646,  2649,  2652,  2655,
    2658,  2661,  2664,  2667,  2670,  2673,  2676,  2679,  2682,  2685,
    2688,  2691,  2694,  2697,  2700,  2703,  2706,  2709,  2715,  2714,
    2719,  2719,  2720,  2723,  2726,  2729,  2732,  2735,  2738,  2741,
    2744,  2747,  2750,  2753,  2756,  2759,  2762,  2765,  2768,  2771,
    2774,  2777,  2782,  2787,  2792,  2801,  2803,  2803,  2804,  2805,
    2806,  2807,  2808,  2809,  2810,  2811,  2812,  2813,  2814,  2815,
    2817,  2822,  2827,  2832,  2837,  2842,  2847,  2852,  2857,  2862,
    2867,  2876,  2878,  2878,  2879,  2880,  2881,  2882,  2883,  2884,
    2885,  2886,  2887,  2888,  2890,  2896,  2912,  2921,  2927,  2933,
    2939,  2948,  2954
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
  "DEFAULT_FLOODCOUNT", "DEFAULT_JOIN_FLOOD_COUNT",
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
  "LEAF_MASK", "LISTEN", "MASK", "MAX_ACCEPT", "MAX_BANS", "MAX_CHANNELS",
  "MAX_GLOBAL", "MAX_IDENT", "MAX_IDLE", "MAX_LOCAL", "MAX_NICK_CHANGES",
  "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_TOPIC_LENGTH", "MAX_WATCH", "MIN_IDLE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD", "NAME",
  "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK",
  "NO_OPER_FLOOD", "NO_TILDE", "NUMBER", "NUMBER_PER_CIDR",
  "NUMBER_PER_IP", "OPER_ONLY_UMODES", "OPER_UMODES", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD",
  "PATH", "PING_COOKIE", "PING_TIME", "PORT", "QSTRING", "RANDOM_IDLE",
  "REASON", "REDIRPORT", "REDIRSERV", "REHASH", "REMOTE", "REMOTEBAN",
  "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ",
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE",
  "SQUIT", "SSL_CERTIFICATE_FILE", "SSL_CERTIFICATE_FINGERPRINT",
  "SSL_CONNECTION_REQUIRED", "SSL_DH_ELLIPTIC_CURVE", "SSL_DH_PARAM_FILE",
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
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "XLINE", "XLINE_EXEMPT", "';'", "'}'",
  "'{'", "'='", "','", "':'", "$accept", "conf", "conf_item", "timespec_",
  "timespec", "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_ssl_certificate_file",
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
  "class_max_number", "class_max_global", "class_max_local",
  "class_max_ident", "class_sendq", "class_recvq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
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
  "$@25", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@26", "umode_items", "umode_item", "general_min_nonwildcard",
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
     475,   476,   477,   478,   479,   480,   481,    59,   125,   123,
      61,    44,    58
};
# endif

#define YYPACT_NINF -887

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-887)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -887,   721,  -887,  -174,  -213,  -208,  -887,  -887,  -887,  -197,
    -887,  -181,  -887,  -887,  -887,  -170,  -887,  -887,  -887,  -160,
    -152,  -887,  -140,  -887,  -122,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,    23,   361,  -119,  -117,   -97,    13,   -91,   486,   -84,
     -78,   -68,    84,   -55,   -49,   -45,   413,   624,   -35,    14,
     -32,    49,   -25,  -185,   -20,   -10,    -7,     9,  -887,  -887,
    -887,  -887,  -887,    -6,    44,    45,    48,    63,    64,    66,
      79,    89,    90,   102,   166,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,   783,   614,    61,
    -887,   106,    32,  -887,  -887,   121,  -887,   116,   118,   119,
     120,   122,   131,   134,   135,   136,   140,   143,   144,   145,
     146,   147,   148,   150,   153,   154,   158,   159,   162,   167,
     168,   169,  -887,  -887,   173,   174,   177,   180,   182,   183,
     185,   186,   188,   189,   194,   196,   197,   200,   201,   202,
     203,   204,    57,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,   352,
      12,   304,   -22,   209,   210,     2,  -887,  -887,  -887,    11,
     341,    85,  -887,   214,   220,   223,   224,   229,   233,   234,
     240,   241,   291,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,    52,   243,   244,   245,   246,   250,   252,
     253,   254,   256,   258,   259,   268,   273,   274,   275,   276,
     282,    55,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
      19,    87,   283,     3,  -887,  -887,  -887,   115,   164,  -887,
     284,    35,  -887,  -887,   165,  -887,   289,   359,   393,   299,
    -887,   149,   410,    81,   420,   410,   410,   421,   410,   410,
     424,   438,   320,  -887,   323,   322,   327,   330,  -887,   332,
     334,   337,   340,   344,   346,   350,   353,   354,   355,   357,
     358,   360,   217,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,   326,   363,   364,   365,   366,   369,   373,  -887,   374,
     376,   377,   379,   382,   383,   384,   251,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,   386,   388,    16,  -887,  -887,  -887,   446,
     362,  -887,  -887,   390,   391,    33,  -887,  -887,  -887,    82,
     410,   463,   410,   410,   414,   514,   415,   518,   519,   521,
     425,   426,   427,   410,   524,   529,   530,   531,   410,   540,
     546,   548,   549,   449,   430,   431,   453,   410,   410,   455,
     456,   457,  -191,  -186,   458,   461,   464,   465,   567,   410,
     467,   410,   410,   468,   451,  -887,   454,   452,   459,  -887,
     462,   472,   473,   474,   475,   303,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,   478,   480,    30,  -887,
    -887,  -887,   460,   483,   485,  -887,   487,  -887,    10,  -887,
    -887,  -887,  -887,  -887,   562,   571,   484,  -887,   491,   489,
     490,    27,  -887,  -887,  -887,   496,   499,   500,  -887,   501,
     502,   503,   504,  -887,   506,   509,   181,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,   516,   511,
     515,   517,    38,  -887,  -887,  -887,  -887,   535,   539,   410,
     572,   541,   573,   542,   543,   544,   532,  -887,  -887,   618,
     635,   551,   636,   654,   656,   643,   646,   647,   648,   649,
     651,   652,   658,   661,   664,   665,   561,  -887,   563,   564,
    -887,    34,  -887,  -887,  -887,  -887,   569,   565,  -887,   568,
     566,   574,   580,   581,   583,    60,  -887,  -887,  -887,  -887,
    -887,   669,   576,  -887,   587,   585,  -887,   586,    95,  -887,
    -887,  -887,  -887,   590,   591,   594,  -887,   596,   400,   604,
     605,   606,   609,   610,   611,   612,   613,   615,   616,  -887,
    -887,   688,   690,   410,   617,   699,   733,   736,   410,   741,
     742,   410,   730,   745,   747,   410,   750,   750,   632,  -887,
    -887,   738,     1,   739,   653,   748,   749,   642,   752,   753,
     768,   756,   757,   758,   760,   657,  -887,   763,   764,   662,
    -887,   663,  -887,   766,   769,   668,  -887,   670,   671,   672,
     674,   675,   677,   679,   680,   681,   682,   684,   685,   687,
     689,   691,   692,   693,   698,   701,   704,   706,   708,   709,
     711,   714,   847,   759,   715,   716,   717,   719,   720,   723,
     724,   725,   729,   731,   732,   734,   735,   737,   740,   746,
     754,   762,   765,   767,  -887,  -887,   774,   770,   718,   793,
     773,   795,   835,   841,   771,  -887,   844,   850,   772,  -887,
    -887,   854,   861,   761,   876,   777,  -887,   778,   779,  -887,
    -887,   864,   868,   780,  -887,  -887,   873,   787,   782,   878,
     894,   897,   812,   794,   901,   904,   802,  -887,  -887,   908,
     909,   910,   808,  -887,   809,   811,   813,   817,   818,   819,
     820,   822,   823,  -887,   824,   825,   827,   828,   829,   830,
     831,   832,   833,   834,   836,   837,   838,   839,   840,   842,
     843,  -887,  -887,   912,   845,   846,  -887,   849,  -887,    93,
    -887,   917,   940,   946,   949,   851,  -887,   852,  -887,  -887,
     950,   853,   952,   855,  -887,  -887,  -887,  -887,  -887,   410,
     410,   410,   410,   410,   410,   410,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,   857,   858,
     859,   -26,   860,   862,   863,   865,   866,   867,   869,   870,
     871,   872,   874,   343,   875,   877,  -887,   879,   880,   881,
     882,   883,   884,   885,    -1,   886,   887,   888,   889,   890,
     891,   892,  -887,   893,   895,  -887,  -887,   896,   898,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -201,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -190,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,   899,   900,   423,   902,   903,   905,   906,   907,  -887,
     911,   913,  -887,   914,   915,   -18,   919,   916,  -887,  -887,
    -887,  -887,   918,   921,  -887,   922,   923,   481,   924,   925,
     926,   927,   807,   928,   929,  -887,   930,   931,   932,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,   933,   338,  -887,  -887,
     934,   935,   936,  -887,    56,  -887,  -887,  -887,  -887,   937,
     941,   942,   943,  -887,  -887,   944,   577,   945,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -187,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,   750,   750,   750,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -184,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,   847,  -887,   759,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -182,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -176,  -887,   969,   876,   947,  -887,  -887,
    -887,  -887,  -887,  -887,   848,  -887,   856,   948,  -887,  -887,
     951,   953,  -887,  -887,   954,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -159,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -157,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -144,  -887,  -887,   959,   -89,   957,   955,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -126,  -887,  -887,  -887,
     -26,  -887,  -887,  -887,  -887,    -1,  -887,  -887,  -887,   423,
    -887,   -18,  -887,  -887,  -887,   963,   965,   972,   973,   977,
     993,  -887,   481,  -887,   807,  -887,   338,   961,   962,   964,
     227,  -887,  -887,   577,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -123,  -887,
    -887,  -887,   227,  -887
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   234,   399,   447,     0,
     462,     0,   302,   438,   278,     0,   100,   152,   336,     0,
       0,   377,     0,   109,     0,   353,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   617,   628,   619,   620,   621,
     622,   623,   624,   625,   618,   626,   627,     0,     0,     0,
     460,     0,     0,   458,   459,     0,   519,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   588,   562,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   473,   474,   475,   517,   518,   512,   513,
     514,   515,   511,   485,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   486,   487,   516,   491,   492,   493,   494,
     490,   489,   495,   502,   503,   496,   497,   498,   488,   500,
     509,   510,   507,   508,   501,   499,   505,   506,   504,     0,
       0,     0,     0,     0,     0,     0,    46,    47,    48,     0,
       0,     0,   653,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   643,   644,   645,   646,   647,   648,   649,
     651,   650,   652,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    69,    66,    64,    70,    71,    65,    55,
      68,    58,    59,    60,    56,    67,    61,    62,    63,    57,
       0,     0,     0,     0,   124,   125,   126,     0,     0,   351,
       0,     0,   349,   350,     0,    96,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   616,     0,     0,     0,     0,   272,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   241,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   239,   240,   242,   252,   253,
     254,     0,     0,     0,     0,     0,     0,     0,   427,     0,
       0,     0,     0,     0,     0,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   410,   409,   412,   416,   413,   414,
     415,   411,   453,     0,     0,     0,   450,   451,   452,     0,
       0,   457,   468,     0,     0,     0,   465,   466,   467,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,     0,     0,     0,   319,
       0,     0,     0,     0,     0,     0,   305,   306,   307,   308,
     313,   309,   310,   311,   312,   444,     0,     0,     0,   441,
     442,   443,     0,     0,     0,   280,     0,   290,     0,   288,
     289,   291,   292,    49,     0,     0,     0,    45,     0,     0,
       0,     0,   103,   104,   105,     0,     0,     0,   201,     0,
       0,     0,     0,   175,     0,     0,     0,   155,   156,   157,
     158,   159,   162,   163,   164,   161,   160,   165,     0,     0,
       0,     0,     0,   339,   340,   341,   342,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   642,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
     385,     0,   380,   381,   382,   127,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   112,   113,   115,   114,
     116,     0,     0,   348,     0,     0,   363,     0,     0,   356,
     357,   358,   359,     0,     0,     0,    90,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   615,
     255,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
     417,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   401,     0,     0,     0,
     449,     0,   456,     0,     0,     0,   464,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   471,   314,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   304,     0,     0,     0,   440,
     293,     0,     0,     0,     0,     0,   287,     0,     0,    44,
     106,     0,     0,     0,   102,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,   343,     0,
       0,     0,     0,   338,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   641,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,   383,     0,     0,     0,   379,     0,   122,     0,
     117,     0,     0,     0,     0,     0,   111,     0,   347,   360,
       0,     0,     0,     0,   355,    99,    98,    97,   639,    28,
      28,    28,    28,    28,    28,    28,    30,    29,   640,   630,
     631,   632,   633,   634,   635,   636,   638,   637,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,   235,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   400,     0,     0,   448,   461,     0,     0,   463,
     532,   536,   520,   521,   551,   523,   614,   559,   524,   525,
     556,   531,   530,   539,   529,   526,   527,   535,   534,   533,
     557,   522,   612,   613,   555,   598,   592,   608,   593,   594,
     595,   603,   611,   596,   605,   609,   599,   610,   600,   604,
     597,   607,   602,   601,   606,     0,   591,   571,   572,   573,
     566,   584,   567,   568,   569,   579,   587,   570,   581,   585,
     575,   586,   576,   580,   574,   583,   578,   577,   582,     0,
     565,   552,   550,   553,   558,   554,   541,   548,   549,   546,
     547,   542,   543,   544,   545,   560,   561,   528,   538,   537,
     540,     0,     0,     0,     0,     0,     0,     0,     0,   303,
       0,     0,   439,     0,     0,     0,   298,   294,   297,   279,
      50,    51,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,     0,     0,     0,   337,
     657,   654,   655,   656,   661,   660,   662,   658,   659,    86,
      81,    89,    80,    87,    88,    79,    83,    82,    74,    73,
      78,    75,    77,    76,    84,    85,     0,     0,   378,   128,
       0,     0,     0,   140,     0,   132,   133,   135,   134,     0,
       0,     0,     0,   110,   352,     0,     0,     0,   354,    31,
      32,    33,    34,    35,    36,    37,   267,   268,   259,   277,
     276,     0,   275,   260,   262,   264,   271,   263,   261,   270,
     256,   269,   258,   257,    38,    38,    38,    40,    39,   265,
     266,   422,   425,   426,   436,   433,   419,   434,   431,   432,
       0,   430,   435,   418,   424,   421,   423,   437,   420,   454,
     455,   469,   470,   589,     0,   563,     0,   317,   318,   328,
     324,   325,   327,   332,   329,   330,   323,   331,   326,     0,
     322,   316,   335,   334,   333,   315,   446,   445,   301,   300,
     285,   286,   284,     0,   283,     0,     0,     0,   107,   108,
     174,   171,   221,   233,   208,   217,     0,   206,   211,   227,
       0,   220,   225,   231,   210,   213,   222,   224,   228,   218,
     226,   214,   232,   216,   223,   212,   215,     0,   204,   167,
     169,   172,   173,   184,   185,   186,   179,   197,   180,   181,
     182,   192,   200,   183,   194,   198,   188,   199,   189,   193,
     187,   196,   191,   190,   195,     0,   178,   168,   170,   346,
     344,   345,   384,   389,   395,   398,   391,   397,   392,   396,
     394,   390,   393,     0,   388,   136,     0,     0,     0,     0,
     131,   119,   118,   120,   121,   361,   367,   373,   376,   369,
     375,   370,   374,   372,   368,   371,     0,   366,   362,   273,
       0,    41,    42,    43,   428,     0,   590,   564,   320,     0,
     281,     0,   299,   296,   295,     0,     0,     0,     0,     0,
       0,   202,     0,   176,     0,   386,     0,     0,     0,     0,
       0,   130,   364,     0,   274,   429,   321,   282,   207,   230,
     205,   229,   219,   209,   203,   177,   387,   137,   139,   138,
     150,   149,   145,   147,   151,   148,   144,   146,     0,   143,
     365,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -887,  -887,  -887,    15,  -300,  -886,  -626,  -887,  -887,   958,
    -887,  -887,  -887,  -887,   920,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  1047,  -887,  -887,  -887,  -887,  -887,
    -887,   637,  -887,  -887,  -887,  -887,  -887,   556,  -887,  -887,
    -887,  -887,  -887,  -887,   938,  -887,  -887,  -887,  -887,   103,
    -887,  -887,  -887,  -887,  -887,  -166,  -887,  -887,  -887,   633,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -121,  -887,  -887,  -887,  -118,  -887,  -887,  -887,   814,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,   -77,
    -887,  -887,  -887,  -887,  -887,   -76,  -887,   700,  -887,  -887,
    -887,    26,  -887,  -887,  -887,  -887,  -887,   712,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,   -73,  -887,  -887,  -887,  -887,
    -887,  -887,   655,  -887,  -887,  -887,  -887,  -887,   939,  -887,
    -887,  -887,  -887,   602,  -887,  -887,  -887,  -887,  -887,   -94,
    -887,  -887,  -887,   623,  -887,  -887,  -887,  -887,   -74,  -887,
    -887,  -887,   956,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,   -52,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,   726,  -887,  -887,  -887,  -887,  -887,   810,
    -887,  -887,  -887,  -887,  1084,  -887,  -887,  -887,  -887,   803,
    -887,  -887,  -887,  -887,  1035,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,    94,  -887,
    -887,  -887,    97,  -887,  -887,  -887,  -887,  -887,  1105,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,   970,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   816,   817,  1077,  1078,    27,   215,   216,
     217,   218,    28,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,    29,    77,    78,    79,    80,    81,    30,    63,
     491,   492,   493,   494,    31,    70,   575,   576,   577,   578,
     579,   580,    32,   283,   284,   285,   286,   287,  1034,  1035,
    1036,  1037,  1038,  1218,  1298,  1299,    33,    64,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   743,
    1195,  1196,   517,   738,  1167,  1168,    34,    53,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   614,  1061,  1062,
      35,    61,   477,   723,  1133,  1134,   478,   479,   480,  1137,
     977,   978,   481,   482,    36,    59,   455,   456,   457,   458,
     459,   460,   461,   708,  1119,  1120,   462,   463,   464,    37,
      65,   522,   523,   524,   525,   526,    38,   291,   292,   293,
      39,    72,   588,   589,   590,   591,   592,   801,  1236,  1237,
      40,    68,   561,   562,   563,   564,   784,  1213,  1214,    41,
      54,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   637,  1090,  1091,   377,   378,   379,   380,   381,
      42,    60,   468,   469,   470,   471,    43,    55,   385,   386,
     387,   388,    44,   112,   113,   114,    45,    57,   395,   396,
     397,   398,    46,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   425,   939,   940,   205,
     424,   915,   916,   206,   207,   208,    47,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      48,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     844,   845,   599,   212,   281,   602,   603,  1088,   605,   606,
      73,   472,   488,   465,   110,   281,    51,   382,   690,   843,
     558,    52,   691,   692,    73,  1059,  1103,   693,   488,  1130,
    1104,   465,    56,   110,   392,   558,   289,  1105,    74,   518,
    1239,  1106,   295,  1244,  1240,  1248,    75,  1245,    58,  1249,
     289,  1250,    74,    49,    50,  1251,   243,  1030,   116,    62,
      75,   570,   382,   117,   118,   473,   119,   120,  1261,    66,
    1263,   121,  1262,   474,  1264,   475,   111,    67,   519,   383,
     122,   123,   244,  1265,   245,   212,   518,  1266,   124,    69,
     489,   125,   126,   127,  1030,   111,   584,  1060,   128,   213,
     658,  1272,   660,   661,  1301,  1273,   489,    71,  1302,    76,
     107,   246,   108,   671,  1268,   129,   130,   520,   676,   559,
     214,   247,   392,    76,   383,   519,   131,   685,   686,   132,
     133,   476,   109,   393,   559,   290,   466,   134,   115,   699,
     384,   701,   702,   248,   135,   209,   136,   249,   137,   290,
     138,   210,   139,   140,   466,   250,  1031,   394,   251,   252,
     571,   211,   521,   141,   520,   570,   584,    82,   142,   143,
    1131,   144,   145,   146,   219,  -129,   147,   848,   849,  1132,
     220,   213,   495,   490,   221,   384,  -129,   253,  1241,  1242,
    1243,    83,    84,  1031,   280,   585,  1089,   288,    85,   490,
     496,   148,   214,   254,   294,   483,   255,   256,   257,   521,
     296,   149,   150,   151,   152,   153,   154,   155,   314,   497,
     297,   393,   282,   298,   301,   572,    86,    87,    88,   756,
     486,   567,   467,   282,   315,   316,   560,   299,   725,   317,
      89,    90,    91,   573,   649,   394,   498,    92,    93,  1032,
     467,   560,   351,   258,   352,   733,   353,   597,   718,   574,
     390,   655,   785,   582,   571,   585,   752,   156,   157,   158,
     354,   159,   160,  1033,   302,   303,   259,   260,   304,   538,
     161,   499,   318,   556,  1219,   444,  1032,   569,   795,   355,
     600,   657,   222,   305,   306,  1290,   307,  1291,   500,   319,
     320,   321,   322,   323,   446,   472,   356,   324,   357,   308,
    1033,   325,   586,   830,   565,   587,   358,   326,   835,   309,
     310,   838,   447,   803,   223,   842,   327,   328,   359,   572,
     501,   502,   311,   224,   225,   226,   389,   329,   227,   228,
    1292,   448,   495,   229,   230,   231,   399,   573,   400,   401,
     402,   360,   403,   446,  1074,  1075,  1076,  1293,   330,   473,
     496,   404,    82,   574,   405,   406,   407,   474,   449,   475,
     408,   447,   361,   409,   410,   411,   412,   413,   414,   497,
     415,   503,   586,   416,   417,   587,    83,    84,   418,   419,
     448,   362,   420,    85,   312,  1294,  1295,   421,   422,   423,
     363,   504,   331,   426,   427,   505,   498,   428,  1203,   746,
     429,   593,   430,   431,   222,   432,   433,   449,   434,   435,
     450,    86,    87,    88,   436,   476,   437,   438,   451,   452,
     439,   440,   441,   442,   443,    89,    90,    91,  1109,   484,
     485,   499,    92,    93,   527,   628,   223,  1296,   453,   364,
     528,   843,  1297,   529,   530,   224,   225,   226,   500,   531,
     227,   228,  1110,   532,   533,   229,   230,   231,  1204,   450,
     534,   535,   365,   539,   540,   541,   542,   451,   452,   645,
     543,   594,   544,   545,   546,  1142,   547,   116,   548,   549,
     501,   502,   117,   118,  1111,   119,   120,   453,   550,  1205,
     121,  1143,  1144,   551,   552,   553,   554,  1206,   598,   122,
     123,  1145,   555,   566,   581,   595,  1207,   124,   598,   536,
     125,   126,   127,   454,  1112,  1113,   596,   128,   601,   604,
    1114,   714,   607,   809,   810,   811,   812,   813,   814,   815,
    1208,   503,  1209,  1210,   129,   130,   608,   609,  1146,  1147,
     610,  1148,   611,   630,  1115,   131,  1211,   612,   132,   133,
     613,   504,   615,  1212,   616,   505,   134,   617,   651,  1116,
     618,   659,   454,   135,   619,   136,   620,   137,  1149,   138,
     621,   139,   140,   622,   623,   624,  1150,   625,   626,   652,
     627,  1269,   141,   631,   632,   633,   634,   142,   143,   635,
     144,   145,   146,   636,   638,   147,   639,   640,  1151,   641,
    1152,  1153,   642,   643,   644,   351,   647,   352,   648,   353,
     653,   654,   663,   662,   664,   243,   665,   666,  1154,   667,
     148,  1117,   672,   354,   668,   669,   670,   673,   674,   675,
     149,   150,   151,   152,   153,   154,   155,  1226,   677,  1118,
    1155,   244,   355,   245,   678,  1156,   679,   680,   681,  1157,
     682,   683,   684,  1158,   687,   688,   689,   694,  1159,   356,
     695,   357,  1160,   696,   697,   698,   700,   703,   704,   358,
     246,   705,   706,  1161,   727,  1162,  1163,   720,  1164,   707,
     247,   359,   709,   728,   757,   759,   156,   157,   158,  1165,
     159,   160,   710,   711,   712,   713,  1166,  1227,   716,   161,
     717,   729,   248,   721,   360,   722,   249,   724,   730,   731,
     732,     2,     3,   735,   250,     4,   764,   251,   252,   736,
     737,   739,   740,   741,   742,   361,   744,     5,  1228,   745,
       6,   749,     7,   748,   754,   750,  1229,   751,   755,     8,
     758,   760,   761,   762,   362,  1230,   253,   765,   767,   763,
     766,     9,   768,   363,   769,   770,    10,    11,   771,   772,
     773,   774,   254,   775,   776,   255,   256,   257,   787,  1231,
     777,  1232,  1233,   778,   314,    12,   779,   780,   781,    13,
     782,   797,   788,   790,   783,  1234,   828,   789,   829,    14,
     315,   316,  1235,   798,   791,   317,   917,   832,   918,   919,
     792,   793,   364,   794,   799,   800,   802,   805,   806,    15,
      16,   807,   258,   808,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,   818,   819,   820,    17,   365,   821,   822,   823,   824,
     825,   833,   826,   827,   834,   259,   260,   831,   318,   836,
     837,    18,   839,   840,  1173,   841,  1174,  1175,   843,   846,
     847,   850,   851,    19,    20,   319,   320,   321,   322,   323,
     852,   853,   854,   324,   855,   856,   857,   325,   858,   859,
     860,   965,   861,   326,   862,   863,   864,    21,   867,   865,
     866,   868,   327,   328,   895,   869,   961,   870,   871,   872,
      22,   873,   874,   329,   875,    23,   876,   877,   878,   879,
      24,   880,   881,    25,   882,   964,   883,   966,   884,   885,
     886,   920,   921,   922,   330,   887,   923,   924,   888,   925,
     926,   889,   927,   890,   928,   891,   892,   929,   893,   930,
     931,   894,   941,   942,   943,   932,   944,   945,   963,   933,
     946,   947,   948,   934,   935,   936,   949,   967,   950,   951,
     937,   952,   953,   968,   954,   938,   970,   955,   331,  1176,
    1177,  1178,   971,   956,  1179,  1180,   973,  1181,  1182,   962,
    1183,   957,  1184,   974,   976,  1185,   982,  1186,  1187,   958,
     983,   975,   959,  1188,   960,   985,   986,  1189,   969,   972,
     988,  1190,  1191,  1192,   979,   980,   981,   984,  1193,   896,
     897,   898,   987,  1194,   899,   900,   989,   901,   902,   990,
     903,   991,   904,   993,   992,   905,   994,   906,   907,   995,
     996,   997,   998,   908,  1026,   999,  1000,   909,  1001,  1039,
    1002,   910,   911,   912,  1003,  1004,  1005,  1006,   913,  1007,
    1008,  1009,  1010,   914,  1011,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1040,  1019,  1020,  1021,  1022,  1023,  1041,  1024,
    1025,  1042,  1045,  1028,  1047,  1027,  1029,  1252,  1043,  1044,
    1255,  1267,  1048,  1046,  1056,  1057,  1058,  1063,  1256,  1064,
    1065,  1278,  1066,  1067,  1068,  1279,  1069,  1070,  1071,  1072,
    1280,  1073,  1079,  1281,  1080,  1282,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1092,  1093,  1094,  1095,  1096,  1097,  1098,
    1099,  1283,  1100,  1101,   300,  1102,  1107,  1108,   734,  1121,
    1122,   796,  1123,  1124,  1125,  1135,  1303,  1220,  1126,   747,
    1127,  1128,  1129,  1285,  1284,  1138,   629,  1136,  1139,  1140,
    1141,  1169,  1170,  1171,  1172,  1197,  1198,  1199,  1200,  1201,
    1202,  1215,  1253,  1274,  1221,  1216,  1217,   715,  1222,  1223,
    1224,  1225,  1238,   487,  1254,  1277,  1276,   753,   726,  1300,
    1257,   557,  1271,  1258,   786,  1259,  1260,  1270,  1287,  1288,
     804,  1289,  1286,  1275,   719,   650,   391,   445,   656,   313,
    1247,  1246,   537,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   568,     0,     0,     0,     0,     0,     0,     0,     0,
     583,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   646
};

static const yytype_int16 yycheck[] =
{
     626,   627,   302,     1,     1,   305,   306,     8,   308,   309,
       1,     1,     1,     1,     1,     1,   229,     1,   209,   108,
       1,   229,   213,   209,     1,    51,   227,   213,     1,    47,
     231,     1,   229,     1,     1,     1,     1,   227,    29,     1,
     227,   231,   227,   227,   231,   227,    37,   231,   229,   231,
       1,   227,    29,   227,   228,   231,     1,     1,     1,   229,
      37,     1,     1,     6,     7,    55,     9,    10,   227,   229,
     227,    14,   231,    63,   231,    65,    63,   229,    40,    63,
      23,    24,    27,   227,    29,     1,     1,   231,    31,   229,
      79,    34,    35,    36,     1,    63,     1,   123,    41,    97,
     400,   227,   402,   403,   227,   231,    79,   229,   231,   100,
     229,    56,   229,   413,   203,    58,    59,    79,   418,   100,
     118,    66,     1,   100,    63,    40,    69,   427,   428,    72,
      73,   121,   229,   100,   100,   100,   124,    80,   229,   439,
     124,   441,   442,    88,    87,   229,    89,    92,    91,   100,
      93,   229,    95,    96,   124,   100,   100,   124,   103,   104,
     100,   229,   124,   106,    79,     1,     1,     1,   111,   112,
     188,   114,   115,   116,   229,   172,   119,   176,   177,   197,
     229,    97,     1,   172,   229,   124,   172,   132,  1074,  1075,
    1076,    25,    26,   100,   229,   100,   197,   229,    32,   172,
      19,   144,   118,   148,   229,   227,   151,   152,   153,   124,
     230,   154,   155,   156,   157,   158,   159,   160,     1,    38,
     230,   100,   219,   230,   230,   165,    60,    61,    62,   529,
     228,   228,   220,   219,    17,    18,   217,   228,   228,    22,
      74,    75,    76,   183,   228,   124,    65,    81,    82,   193,
     220,   217,     1,   198,     3,   228,     5,   108,   228,   199,
     228,   228,   228,   228,   100,   100,   228,   210,   211,   212,
      19,   214,   215,   217,   230,   230,   221,   222,   230,   227,
     223,   100,    65,   228,   228,   228,   193,   172,   228,    38,
     209,   209,     1,   230,   230,    68,   230,    70,   117,    82,
      83,    84,    85,    86,     1,     1,    55,    90,    57,   230,
     217,    94,   217,   613,   227,   220,    65,   100,   618,   230,
     230,   621,    19,   228,    33,   625,   109,   110,    77,   165,
     149,   150,   230,    42,    43,    44,   230,   120,    47,    48,
     113,    38,     1,    52,    53,    54,   230,   183,   230,   230,
     230,   100,   230,     1,    11,    12,    13,   130,   141,    55,
      19,   230,     1,   199,   230,   230,   230,    63,    65,    65,
     230,    19,   121,   230,   230,   230,   230,   230,   230,    38,
     230,   200,   217,   230,   230,   220,    25,    26,   230,   230,
      38,   140,   230,    32,   228,   168,   169,   230,   230,   230,
     149,   220,   185,   230,   230,   224,    65,   230,    70,   228,
     230,   122,   230,   230,     1,   230,   230,    65,   230,   230,
     117,    60,    61,    62,   230,   121,   230,   230,   125,   126,
     230,   230,   230,   230,   230,    74,    75,    76,    15,   230,
     230,   100,    81,    82,   230,   228,    33,   220,   145,   198,
     230,   108,   225,   230,   230,    42,    43,    44,   117,   230,
      47,    48,    39,   230,   230,    52,    53,    54,   130,   117,
     230,   230,   221,   230,   230,   230,   230,   125,   126,   228,
     230,   122,   230,   230,   230,     4,   230,     1,   230,   230,
     149,   150,     6,     7,    71,     9,    10,   145,   230,   161,
      14,    20,    21,   230,   230,   230,   230,   169,   108,    23,
      24,    30,   230,   230,   230,   122,   178,    31,   108,   228,
      34,    35,    36,   220,   101,   102,   227,    41,   108,   108,
     107,   228,   108,   133,   134,   135,   136,   137,   138,   139,
     202,   200,   204,   205,    58,    59,   108,   227,    67,    68,
     227,    70,   230,   227,   131,    69,   218,   230,    72,    73,
     230,   220,   230,   225,   230,   224,    80,   230,   122,   146,
     230,   108,   220,    87,   230,    89,   230,    91,    97,    93,
     230,    95,    96,   230,   230,   230,   105,   230,   230,   227,
     230,  1217,   106,   230,   230,   230,   230,   111,   112,   230,
     114,   115,   116,   230,   230,   119,   230,   230,   127,   230,
     129,   130,   230,   230,   230,     1,   230,     3,   230,     5,
     230,   230,   108,   209,   209,     1,   108,   108,   147,   108,
     144,   208,   108,    19,   209,   209,   209,   108,   108,   108,
     154,   155,   156,   157,   158,   159,   160,    70,   108,   226,
     169,    27,    38,    29,   108,   174,   108,   108,   209,   178,
     230,   230,   209,   182,   209,   209,   209,   209,   187,    55,
     209,    57,   191,   209,   209,   108,   209,   209,   227,    65,
      56,   227,   230,   202,   122,   204,   205,   227,   207,   230,
      66,    77,   230,   122,   122,   122,   210,   211,   212,   218,
     214,   215,   230,   230,   230,   230,   225,   130,   230,   223,
     230,   227,    88,   230,   100,   230,    92,   230,   227,   230,
     230,     0,     1,   227,   100,     4,   108,   103,   104,   230,
     230,   230,   230,   230,   230,   121,   230,    16,   161,   230,
      19,   230,    21,   227,   209,   230,   169,   230,   209,    28,
     209,   209,   209,   209,   140,   178,   132,   122,   122,   227,
     209,    40,   108,   149,   108,   122,    45,    46,   122,   122,
     122,   122,   148,   122,   122,   151,   152,   153,   209,   202,
     122,   204,   205,   122,     1,    64,   122,   122,   227,    68,
     227,   122,   227,   227,   230,   218,   108,   229,   108,    78,
      17,    18,   225,   227,   230,    22,    47,   108,    49,    50,
     230,   230,   198,   230,   227,   230,   230,   227,   227,    98,
      99,   227,   198,   227,   809,   810,   811,   812,   813,   814,
     815,   227,   227,   227,   113,   221,   227,   227,   227,   227,
     227,   108,   227,   227,   108,   221,   222,   230,    65,   108,
     108,   130,   122,   108,    47,   108,    49,    50,   108,   227,
     122,   122,   209,   142,   143,    82,    83,    84,    85,    86,
     122,   122,   230,    90,   122,   122,   108,    94,   122,   122,
     122,   108,   122,   100,   227,   122,   122,   166,   122,   227,
     227,   122,   109,   110,    47,   227,   122,   227,   227,   227,
     179,   227,   227,   120,   227,   184,   227,   227,   227,   227,
     189,   227,   227,   192,   227,   122,   227,   122,   227,   227,
     227,   162,   163,   164,   141,   227,   167,   168,   227,   170,
     171,   227,   173,   227,   175,   227,   227,   178,   227,   180,
     181,   227,   227,   227,   227,   186,   227,   227,   230,   190,
     227,   227,   227,   194,   195,   196,   227,   122,   227,   227,
     201,   227,   227,   122,   227,   206,   122,   227,   185,   162,
     163,   164,   122,   227,   167,   168,   122,   170,   171,   209,
     173,   227,   175,   122,   108,   178,   122,   180,   181,   227,
     122,   230,   227,   186,   227,   122,   209,   190,   227,   227,
     122,   194,   195,   196,   227,   227,   227,   227,   201,   162,
     163,   164,   230,   206,   167,   168,   122,   170,   171,   122,
     173,   209,   175,   122,   230,   178,   122,   180,   181,   227,
     122,   122,   122,   186,   122,   227,   227,   190,   227,   122,
     227,   194,   195,   196,   227,   227,   227,   227,   201,   227,
     227,   227,   227,   206,   227,   227,   227,   227,   227,   227,
     227,   227,   122,   227,   227,   227,   227,   227,   122,   227,
     227,   122,   122,   227,   122,   230,   227,   108,   227,   227,
     232,   122,   227,   230,   227,   227,   227,   227,   232,   227,
     227,   128,   227,   227,   227,   130,   227,   227,   227,   227,
     128,   227,   227,   130,   227,   128,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   128,   227,   227,    77,   227,   227,   227,   491,   227,
     227,   575,   227,   227,   227,   216,  1302,  1034,   227,   506,
     227,   227,   227,  1264,  1262,   227,   332,   231,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,  1136,  1240,   227,   230,   230,   455,   227,   227,
     227,   227,   227,   215,   227,  1251,  1249,   522,   478,  1273,
     232,   261,   227,   232,   561,   232,   232,   230,   227,   227,
     588,   227,  1266,  1245,   468,   385,   112,   162,   395,    94,
    1106,  1104,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   366
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   234,     0,     1,     4,    16,    19,    21,    28,    40,
      45,    46,    64,    68,    78,    98,    99,   113,   130,   142,
     143,   166,   179,   184,   189,   192,   235,   240,   245,   265,
     271,   277,   285,   299,   319,   343,   357,   372,   379,   383,
     393,   402,   423,   429,   435,   439,   445,   499,   513,   227,
     228,   229,   229,   320,   403,   430,   229,   440,   229,   358,
     424,   344,   229,   272,   300,   373,   229,   229,   394,   229,
     278,   229,   384,     1,    29,    37,   100,   266,   267,   268,
     269,   270,     1,    25,    26,    32,    60,    61,    62,    74,
      75,    76,    81,    82,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   229,   229,   229,
       1,    63,   436,   437,   438,   229,     1,     6,     7,     9,
      10,    14,    23,    24,    31,    34,    35,    36,    41,    58,
      59,    69,    72,    73,    80,    87,    89,    91,    93,    95,
      96,   106,   111,   112,   114,   115,   116,   119,   144,   154,
     155,   156,   157,   158,   159,   160,   210,   211,   212,   214,
     215,   223,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   492,   496,   497,   498,   229,
     229,   229,     1,    97,   118,   241,   242,   243,   244,   229,
     229,   229,     1,    33,    42,    43,    44,    47,    48,    52,
      53,    54,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,     1,    27,    29,    56,    66,    88,    92,
     100,   103,   104,   132,   148,   151,   152,   153,   198,   221,
     222,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     229,     1,   219,   286,   287,   288,   289,   290,   229,     1,
     100,   380,   381,   382,   229,   227,   230,   230,   230,   228,
     267,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   228,   501,     1,    17,    18,    22,    65,    82,
      83,    84,    85,    86,    90,    94,   100,   109,   110,   120,
     141,   185,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,     1,     3,     5,    19,    38,    55,    57,    65,    77,
     100,   121,   140,   149,   198,   221,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   418,   419,   420,
     421,   422,     1,    63,   124,   431,   432,   433,   434,   230,
     228,   437,     1,   100,   124,   441,   442,   443,   444,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   493,   489,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   228,   447,     1,    19,    38,    65,
     117,   125,   126,   145,   220,   359,   360,   361,   362,   363,
     364,   365,   369,   370,   371,     1,   124,   220,   425,   426,
     427,   428,     1,    55,    63,    65,   121,   345,   349,   350,
     351,   355,   356,   227,   230,   230,   228,   242,     1,    79,
     172,   273,   274,   275,   276,     1,    19,    38,    65,   100,
     117,   149,   150,   200,   220,   224,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   315,     1,    40,
      79,   124,   374,   375,   376,   377,   378,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   228,   515,   227,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   228,   247,     1,   100,
     217,   395,   396,   397,   398,   227,   230,   228,   287,   172,
       1,   100,   165,   183,   199,   279,   280,   281,   282,   283,
     284,   230,   228,   381,     1,   100,   217,   220,   385,   386,
     387,   388,   389,   122,   122,   122,   227,   108,   108,   237,
     209,   108,   237,   237,   108,   237,   237,   108,   108,   227,
     227,   230,   230,   230,   340,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   228,   322,
     227,   230,   230,   230,   230,   230,   230,   415,   230,   230,
     230,   230,   230,   230,   230,   228,   405,   230,   230,   228,
     432,   122,   227,   230,   230,   228,   442,   209,   237,   108,
     237,   237,   209,   108,   209,   108,   108,   108,   209,   209,
     209,   237,   108,   108,   108,   108,   237,   108,   108,   108,
     108,   209,   230,   230,   209,   237,   237,   209,   209,   209,
     209,   213,   209,   213,   209,   209,   209,   209,   108,   237,
     209,   237,   237,   209,   227,   227,   230,   230,   366,   230,
     230,   230,   230,   230,   228,   360,   230,   230,   228,   426,
     227,   230,   230,   346,   230,   228,   350,   122,   122,   227,
     227,   230,   230,   228,   274,   227,   230,   230,   316,   230,
     230,   230,   230,   312,   230,   230,   228,   302,   227,   230,
     230,   230,   228,   375,   209,   209,   237,   122,   209,   122,
     209,   209,   209,   227,   108,   122,   209,   122,   108,   108,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   227,   227,   230,   399,   228,   396,   209,   227,   229,
     227,   230,   230,   230,   230,   228,   280,   122,   227,   227,
     230,   390,   230,   228,   386,   227,   227,   227,   227,   133,
     134,   135,   136,   137,   138,   139,   236,   237,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   108,   108,
     237,   230,   108,   108,   108,   237,   108,   108,   237,   122,
     108,   108,   237,   108,   239,   239,   227,   122,   176,   177,
     122,   209,   122,   122,   230,   122,   122,   108,   122,   122,
     122,   122,   227,   122,   122,   227,   227,   122,   122,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,    47,   162,   163,   164,   167,
     168,   170,   171,   173,   175,   178,   180,   181,   186,   190,
     194,   195,   196,   201,   206,   494,   495,    47,    49,    50,
     162,   163,   164,   167,   168,   170,   171,   173,   175,   178,
     180,   181,   186,   190,   194,   195,   196,   201,   206,   490,
     491,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   122,   209,   230,   122,   108,   122,   122,   122,   227,
     122,   122,   227,   122,   122,   230,   108,   353,   354,   227,
     227,   227,   122,   122,   227,   122,   209,   230,   122,   122,
     122,   209,   230,   122,   122,   227,   122,   122,   122,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   122,   230,   227,   227,
       1,   100,   193,   217,   291,   292,   293,   294,   295,   122,
     122,   122,   122,   227,   227,   122,   230,   122,   227,   236,
     236,   236,   236,   236,   236,   236,   227,   227,   227,    51,
     123,   341,   342,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,    11,    12,    13,   238,   239,   227,
     227,   227,   227,   227,   227,   227,   227,   227,     8,   197,
     416,   417,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   231,   227,   231,   227,   227,    15,
      39,    71,   101,   102,   107,   131,   146,   208,   226,   367,
     368,   227,   227,   227,   227,   227,   227,   227,   227,   227,
      47,   188,   197,   347,   348,   216,   231,   352,   227,   227,
     227,   227,     4,    20,    21,    30,    67,    68,    70,    97,
     105,   127,   129,   130,   147,   169,   174,   178,   182,   187,
     191,   202,   204,   205,   207,   218,   225,   317,   318,   227,
     227,   227,   227,    47,    49,    50,   162,   163,   164,   167,
     168,   170,   171,   173,   175,   178,   180,   181,   186,   190,
     194,   195,   196,   201,   206,   313,   314,   227,   227,   227,
     227,   227,   227,    70,   130,   161,   169,   178,   202,   204,
     205,   218,   225,   400,   401,   227,   230,   230,   296,   228,
     292,   227,   227,   227,   227,   227,    70,   130,   161,   169,
     178,   202,   204,   205,   218,   225,   391,   392,   227,   227,
     231,   238,   238,   238,   227,   231,   495,   491,   227,   231,
     227,   231,   108,   354,   227,   232,   232,   232,   232,   232,
     232,   227,   231,   227,   231,   227,   231,   122,   203,   239,
     230,   227,   227,   231,   342,   417,   368,   348,   128,   130,
     128,   130,   128,   128,   318,   314,   401,   227,   227,   227,
      68,    70,   113,   130,   168,   169,   220,   225,   297,   298,
     392,   227,   231,   298
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   233,   234,   234,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   236,   236,
     237,   237,   237,   237,   237,   237,   237,   237,   238,   238,
     239,   239,   239,   239,   240,   241,   241,   242,   242,   242,
     243,   244,   245,   246,   246,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   266,   267,   267,   267,   267,   268,   269,   270,
     272,   271,   273,   273,   274,   274,   274,   275,   276,   278,
     277,   279,   279,   280,   280,   280,   280,   280,   281,   282,
     283,   284,   285,   286,   286,   287,   287,   287,   288,   290,
     289,   291,   291,   292,   292,   292,   292,   293,   294,   294,
     296,   295,   297,   297,   298,   298,   298,   298,   298,   298,
     298,   298,   300,   299,   301,   301,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   312,   311,   313,   313,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   316,   315,   317,   317,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   320,   319,   321,   321,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   340,   339,   341,   341,   342,   342,   344,   343,
     346,   345,   347,   347,   348,   348,   348,   349,   349,   350,
     350,   350,   350,   350,   352,   351,   353,   353,   354,   354,
     355,   356,   358,   357,   359,   359,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   361,   362,   363,   364,   366,
     365,   367,   367,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   369,   370,   371,   373,   372,   374,   374,
     375,   375,   375,   375,   376,   377,   378,   379,   380,   380,
     381,   381,   382,   384,   383,   385,   385,   386,   386,   386,
     386,   387,   388,   390,   389,   391,   391,   392,   392,   392,
     392,   392,   392,   392,   392,   392,   392,   394,   393,   395,
     395,   396,   396,   396,   397,   399,   398,   400,   400,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   403,
     402,   404,   404,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   413,   415,   414,   416,
     416,   417,   417,   418,   419,   420,   421,   422,   424,   423,
     425,   425,   426,   426,   426,   427,   428,   430,   429,   431,
     431,   432,   432,   432,   433,   434,   435,   436,   436,   437,
     437,   438,   440,   439,   441,   441,   442,   442,   442,   443,
     444,   445,   446,   446,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   474,   475,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   489,   488,   490,   490,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   493,   492,
     494,   494,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   496,   497,   498,   499,   500,   500,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   514,   515,   515,   515,   515,   515,   515,
     515,   515,   515,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524
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
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     0,     6,
       0,     5,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     0,     5,     3,     1,     1,     3,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     4,     5,     2,     1,
       1,     1,     4,     0,     6,     2,     1,     1,     1,     1,
       2,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     2,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     4,     4,     4,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     4,     0,     6,     2,     1,     1,     1,     1,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4
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
#line 402 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 403 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 404 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 405 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2870 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 406 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 407 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 408 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 409 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 410 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 430 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 436 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 469 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_certificate_file);
    ConfigServerInfo.ssl_certificate_file = xstrdup(yylval.string);
  }
}
#line 2960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 478 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 2972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 487 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_param_file);
    ConfigServerInfo.ssl_dh_param_file = xstrdup(yylval.string);
  }
}
#line 2984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 496 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_cipher_list);
    ConfigServerInfo.ssl_cipher_list = xstrdup(yylval.string);
  }
}
#line 2996 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 505 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_message_digest_algorithm);
    ConfigServerInfo.ssl_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 514 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_elliptic_curve);
    ConfigServerInfo.ssl_dh_elliptic_curve = xstrdup(yylval.string);
  }
}
#line 3020 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 523 "conf_parser.y" /* yacc.c:1646  */
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
#line 3038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 538 "conf_parser.y" /* yacc.c:1646  */
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
#line 3056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 553 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 563 "conf_parser.y" /* yacc.c:1646  */
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
#line 3086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 577 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 586 "conf_parser.y" /* yacc.c:1646  */
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
#line 3129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 614 "conf_parser.y" /* yacc.c:1646  */
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
#line 3160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 642 "conf_parser.y" /* yacc.c:1646  */
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
#line 3188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 667 "conf_parser.y" /* yacc.c:1646  */
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
#line 3213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 689 "conf_parser.y" /* yacc.c:1646  */
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
#line 3238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 711 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3247 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 729 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3259 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 738 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3271 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 747 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3283 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 760 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3292 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 764 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 781 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 787 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3327 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 797 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 801 "conf_parser.y" /* yacc.c:1646  */
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
#line 3354 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 819 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3363 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 825 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 831 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 837 "conf_parser.y" /* yacc.c:1646  */
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
#line 3402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 865 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3411 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 871 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 875 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 891 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 899 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 902 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 907 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 914 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 918 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 922 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 926 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 930 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 934 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 938 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 942 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 952 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3553 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 959 "conf_parser.y" /* yacc.c:1646  */
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

    nuh.nuhmask  = node->data;
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
#line 3606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1022 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1040 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3656 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1063 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1074 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3688 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1080 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1087 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3706 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1091 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1095 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1099 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1103 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3742 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3751 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1111 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3760 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1115 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3769 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3778 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1123 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3787 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1127 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3796 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1131 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3805 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1135 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1139 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1147 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1151 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1155 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1159 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1163 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1167 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1171 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1177 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1184 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1188 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1196 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1208 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1216 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 3985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 3994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1224 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4003 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1228 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1252 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1260 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1264 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1306 "conf_parser.y" /* yacc.c:1646  */
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
#line 4182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1318 "conf_parser.y" /* yacc.c:1646  */
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
#line 4230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1382 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4239 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1388 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1394 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4257 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1400 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4266 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1406 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4275 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1412 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4284 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1418 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4293 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1424 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4302 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1430 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4311 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1436 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1442 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4330 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1449 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4339 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1455 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1461 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1467 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1476 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1485 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1492 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1496 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1506 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1512 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1518 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1522 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1526 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1534 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4458 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1539 "conf_parser.y" /* yacc.c:1646  */
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
#line 4476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1552 "conf_parser.y" /* yacc.c:1646  */
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
#line 4496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1569 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1575 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1585 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1589 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = node->data;
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
#line 4564 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1638 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1644 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1650 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4591 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1656 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4605 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1667 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4614 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1674 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4623 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1678 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4632 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1682 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4641 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1686 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4650 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1690 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1694 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4668 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1698 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4677 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1702 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4686 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1706 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4695 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1710 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4704 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1716 "conf_parser.y" /* yacc.c:1646  */
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
#line 4721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1730 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1739 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4745 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1752 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1759 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1770 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1776 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1782 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4795 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1797 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1813 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4826 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1824 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1839 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1845 "conf_parser.y" /* yacc.c:1646  */
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
#line 4872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1864 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1871 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1875 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1879 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1883 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1887 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1891 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1895 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1899 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1903 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1907 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4971 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1917 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 4985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1926 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 4998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1945 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1952 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1956 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1960 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1964 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1972 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1976 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 1980 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 1984 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 1988 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 399:
#line 1998 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2007 "conf_parser.y" /* yacc.c:1646  */
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
#line 5186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2087 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2093 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2099 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2105 "conf_parser.y" /* yacc.c:1646  */
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
#line 5229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2118 "conf_parser.y" /* yacc.c:1646  */
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
#line 5245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2131 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2137 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2147 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5281 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2153 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5289 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2159 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5298 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2163 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5307 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2169 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5321 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2180 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5330 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2186 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5339 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2198 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5362 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2213 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5371 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2217 "conf_parser.y" /* yacc.c:1646  */
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
#line 5396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2242 "conf_parser.y" /* yacc.c:1646  */
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
#line 5419 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2276 "conf_parser.y" /* yacc.c:1646  */
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
#line 5463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 454:
#line 2302 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 455:
#line 2308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2323 "conf_parser.y" /* yacc.c:1646  */
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
#line 5498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 462:
#line 2340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 463:
#line 2344 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  conf = conf_make(CONF_XLINE);
  conf->name = xstrdup(block_state.name.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
}
#line 5529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 469:
#line 2366 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5538 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 470:
#line 2372 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2433 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2438 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2443 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2448 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5580 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2454 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5588 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2459 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5596 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2464 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5604 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2469 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5612 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2474 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5620 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2479 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5628 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2484 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5636 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2489 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5644 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2494 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5652 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2499 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5660 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2504 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5668 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2509 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5676 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2514 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2519 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5692 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2524 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5701 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2530 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2535 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5717 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2540 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5725 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2545 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2550 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2555 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2560 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2565 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2568 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2573 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5781 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2576 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5789 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2581 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5797 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2586 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5805 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2591 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5813 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2596 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5821 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2601 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5829 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2606 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2611 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2616 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5853 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2621 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2626 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5869 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2631 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2636 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2641 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2650 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2653 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2656 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2659 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2662 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5941 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2665 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2668 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2671 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2674 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2677 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2680 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 5989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2683 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 5997 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2686 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6005 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2689 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6013 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2692 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2695 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2698 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2701 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2704 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2707 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2710 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2715 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2721 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2724 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2727 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2730 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6109 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2733 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2736 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2739 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6141 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2745 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6157 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2751 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2754 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2760 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6189 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2763 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2766 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2769 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6221 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2775 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2778 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2783 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2788 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6253 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2793 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6261 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2818 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2823 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6277 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6285 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2833 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6293 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2838 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6317 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2853 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6325 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2868 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 2891 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 2897 "conf_parser.y" /* yacc.c:1646  */
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
#line 6377 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 2913 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 2922 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 2928 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 2934 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 2940 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 2949 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 2955 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6446 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6450 "conf_parser.c" /* yacc.c:1646  */
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
