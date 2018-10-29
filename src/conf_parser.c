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
    MAX_IDLE = 341,
    MAX_INVITES = 342,
    MAX_NICK_CHANGES = 343,
    MAX_NICK_LENGTH = 344,
    MAX_NICK_TIME = 345,
    MAX_NUMBER = 346,
    MAX_TARGETS = 347,
    MAX_TOPIC_LENGTH = 348,
    MAX_WATCH = 349,
    MIN_IDLE = 350,
    MIN_NONWILDCARD = 351,
    MIN_NONWILDCARD_SIMPLE = 352,
    MODULE = 353,
    MODULES = 354,
    MOTD = 355,
    NAME = 356,
    NEED_IDENT = 357,
    NEED_PASSWORD = 358,
    NETWORK_DESC = 359,
    NETWORK_NAME = 360,
    NICK = 361,
    NO_OPER_FLOOD = 362,
    NO_TILDE = 363,
    NUMBER = 364,
    NUMBER_PER_CIDR = 365,
    NUMBER_PER_IP_GLOBAL = 366,
    NUMBER_PER_IP_LOCAL = 367,
    OPER_ONLY_UMODES = 368,
    OPER_UMODES = 369,
    OPERATOR = 370,
    OPERS_BYPASS_CALLERID = 371,
    PACE_WAIT = 372,
    PACE_WAIT_SIMPLE = 373,
    PASSWORD = 374,
    PATH = 375,
    PING_COOKIE = 376,
    PING_TIME = 377,
    PORT = 378,
    QSTRING = 379,
    RANDOM_IDLE = 380,
    REASON = 381,
    REDIRPORT = 382,
    REDIRSERV = 383,
    REHASH = 384,
    REMOTE = 385,
    REMOTEBAN = 386,
    RESV = 387,
    RESV_EXEMPT = 388,
    RSA_PRIVATE_KEY_FILE = 389,
    SECONDS = 390,
    MINUTES = 391,
    HOURS = 392,
    DAYS = 393,
    WEEKS = 394,
    MONTHS = 395,
    YEARS = 396,
    SEND_PASSWORD = 397,
    SENDQ = 398,
    SERVERHIDE = 399,
    SERVERINFO = 400,
    SHORT_MOTD = 401,
    SPOOF = 402,
    SPOOF_NOTICE = 403,
    SQUIT = 404,
    SSL_CERTIFICATE_FILE = 405,
    SSL_CERTIFICATE_FINGERPRINT = 406,
    SSL_CONNECTION_REQUIRED = 407,
    SSL_DH_ELLIPTIC_CURVE = 408,
    SSL_DH_PARAM_FILE = 409,
    SSL_MESSAGE_DIGEST_ALGORITHM = 410,
    STATS_E_DISABLED = 411,
    STATS_I_OPER_ONLY = 412,
    STATS_K_OPER_ONLY = 413,
    STATS_M_OPER_ONLY = 414,
    STATS_O_OPER_ONLY = 415,
    STATS_P_OPER_ONLY = 416,
    STATS_U_OPER_ONLY = 417,
    T_ALL = 418,
    T_BOTS = 419,
    T_CALLERID = 420,
    T_CCONN = 421,
    T_COMMAND = 422,
    T_CLUSTER = 423,
    T_DEAF = 424,
    T_DEBUG = 425,
    T_DLINE = 426,
    T_EXTERNAL = 427,
    T_FARCONNECT = 428,
    T_FILE = 429,
    T_FULL = 430,
    T_GLOBOPS = 431,
    T_INVISIBLE = 432,
    T_IPV4 = 433,
    T_IPV6 = 434,
    T_LOCOPS = 435,
    T_LOG = 436,
    T_NCHANGE = 437,
    T_NONONREG = 438,
    T_OPME = 439,
    T_PREPEND = 440,
    T_PSEUDO = 441,
    T_RECVQ = 442,
    T_REJ = 443,
    T_RESTART = 444,
    T_SERVER = 445,
    T_SERVICE = 446,
    T_SERVNOTICE = 447,
    T_SET = 448,
    T_SHARED = 449,
    T_SIZE = 450,
    T_SKILL = 451,
    T_SOFTCALLERID = 452,
    T_SPY = 453,
    T_SSL = 454,
    T_SSL_CIPHER_LIST = 455,
    T_TARGET = 456,
    T_UMODES = 457,
    T_UNAUTH = 458,
    T_UNDLINE = 459,
    T_UNLIMITED = 460,
    T_UNRESV = 461,
    T_UNXLINE = 462,
    T_WALLOP = 463,
    T_WALLOPS = 464,
    T_WEBIRC = 465,
    TBOOL = 466,
    THROTTLE_COUNT = 467,
    THROTTLE_TIME = 468,
    TKLINE_EXPIRE_NOTICES = 469,
    TMASKED = 470,
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
    XLINE_EXEMPT = 484
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
#define MAX_IDLE 341
#define MAX_INVITES 342
#define MAX_NICK_CHANGES 343
#define MAX_NICK_LENGTH 344
#define MAX_NICK_TIME 345
#define MAX_NUMBER 346
#define MAX_TARGETS 347
#define MAX_TOPIC_LENGTH 348
#define MAX_WATCH 349
#define MIN_IDLE 350
#define MIN_NONWILDCARD 351
#define MIN_NONWILDCARD_SIMPLE 352
#define MODULE 353
#define MODULES 354
#define MOTD 355
#define NAME 356
#define NEED_IDENT 357
#define NEED_PASSWORD 358
#define NETWORK_DESC 359
#define NETWORK_NAME 360
#define NICK 361
#define NO_OPER_FLOOD 362
#define NO_TILDE 363
#define NUMBER 364
#define NUMBER_PER_CIDR 365
#define NUMBER_PER_IP_GLOBAL 366
#define NUMBER_PER_IP_LOCAL 367
#define OPER_ONLY_UMODES 368
#define OPER_UMODES 369
#define OPERATOR 370
#define OPERS_BYPASS_CALLERID 371
#define PACE_WAIT 372
#define PACE_WAIT_SIMPLE 373
#define PASSWORD 374
#define PATH 375
#define PING_COOKIE 376
#define PING_TIME 377
#define PORT 378
#define QSTRING 379
#define RANDOM_IDLE 380
#define REASON 381
#define REDIRPORT 382
#define REDIRSERV 383
#define REHASH 384
#define REMOTE 385
#define REMOTEBAN 386
#define RESV 387
#define RESV_EXEMPT 388
#define RSA_PRIVATE_KEY_FILE 389
#define SECONDS 390
#define MINUTES 391
#define HOURS 392
#define DAYS 393
#define WEEKS 394
#define MONTHS 395
#define YEARS 396
#define SEND_PASSWORD 397
#define SENDQ 398
#define SERVERHIDE 399
#define SERVERINFO 400
#define SHORT_MOTD 401
#define SPOOF 402
#define SPOOF_NOTICE 403
#define SQUIT 404
#define SSL_CERTIFICATE_FILE 405
#define SSL_CERTIFICATE_FINGERPRINT 406
#define SSL_CONNECTION_REQUIRED 407
#define SSL_DH_ELLIPTIC_CURVE 408
#define SSL_DH_PARAM_FILE 409
#define SSL_MESSAGE_DIGEST_ALGORITHM 410
#define STATS_E_DISABLED 411
#define STATS_I_OPER_ONLY 412
#define STATS_K_OPER_ONLY 413
#define STATS_M_OPER_ONLY 414
#define STATS_O_OPER_ONLY 415
#define STATS_P_OPER_ONLY 416
#define STATS_U_OPER_ONLY 417
#define T_ALL 418
#define T_BOTS 419
#define T_CALLERID 420
#define T_CCONN 421
#define T_COMMAND 422
#define T_CLUSTER 423
#define T_DEAF 424
#define T_DEBUG 425
#define T_DLINE 426
#define T_EXTERNAL 427
#define T_FARCONNECT 428
#define T_FILE 429
#define T_FULL 430
#define T_GLOBOPS 431
#define T_INVISIBLE 432
#define T_IPV4 433
#define T_IPV6 434
#define T_LOCOPS 435
#define T_LOG 436
#define T_NCHANGE 437
#define T_NONONREG 438
#define T_OPME 439
#define T_PREPEND 440
#define T_PSEUDO 441
#define T_RECVQ 442
#define T_REJ 443
#define T_RESTART 444
#define T_SERVER 445
#define T_SERVICE 446
#define T_SERVNOTICE 447
#define T_SET 448
#define T_SHARED 449
#define T_SIZE 450
#define T_SKILL 451
#define T_SOFTCALLERID 452
#define T_SPY 453
#define T_SSL 454
#define T_SSL_CIPHER_LIST 455
#define T_TARGET 456
#define T_UMODES 457
#define T_UNAUTH 458
#define T_UNDLINE 459
#define T_UNLIMITED 460
#define T_UNRESV 461
#define T_UNXLINE 462
#define T_WALLOP 463
#define T_WALLOPS 464
#define T_WEBIRC 465
#define TBOOL 466
#define THROTTLE_COUNT 467
#define THROTTLE_TIME 468
#define TKLINE_EXPIRE_NOTICES 469
#define TMASKED 470
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 141 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 682 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 699 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1348

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  236
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  295
/* YYNRULES -- Number of rules.  */
#define YYNRULES  668
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1319

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   484

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
       2,     2,     2,     2,   234,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   235,   230,
       2,   233,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   232,     2,   231,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   374,   374,   375,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   405,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   416,   416,
     417,   418,   419,   420,   427,   429,   429,   430,   430,   430,
     432,   438,   448,   450,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   471,   480,   489,   498,   507,   516,   525,
     540,   555,   565,   579,   588,   616,   644,   669,   691,   713,
     723,   725,   725,   726,   727,   728,   729,   731,   740,   749,
     763,   762,   780,   780,   781,   781,   781,   783,   789,   800,
     799,   818,   818,   819,   819,   819,   819,   819,   821,   827,
     833,   839,   861,   862,   862,   864,   864,   865,   867,   874,
     874,   887,   888,   890,   890,   891,   891,   893,   901,   904,
     910,   909,   915,   915,   916,   920,   924,   928,   932,   936,
     940,   944,   955,   954,  1015,  1015,  1016,  1017,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1025,  1026,  1028,  1034,  1040,
    1046,  1052,  1063,  1069,  1080,  1087,  1086,  1092,  1092,  1093,
    1097,  1101,  1105,  1109,  1113,  1117,  1121,  1125,  1129,  1133,
    1137,  1141,  1145,  1149,  1153,  1157,  1161,  1165,  1169,  1173,
    1177,  1184,  1183,  1189,  1189,  1190,  1194,  1198,  1202,  1206,
    1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,  1242,  1246,
    1250,  1254,  1258,  1262,  1266,  1270,  1274,  1278,  1282,  1286,
    1290,  1294,  1298,  1302,  1313,  1312,  1367,  1367,  1368,  1369,
    1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,  1378,  1379,
    1380,  1381,  1382,  1383,  1385,  1391,  1397,  1403,  1409,  1415,
    1421,  1427,  1433,  1440,  1446,  1452,  1458,  1467,  1477,  1476,
    1482,  1482,  1483,  1487,  1498,  1497,  1504,  1503,  1508,  1508,
    1509,  1513,  1517,  1523,  1523,  1524,  1524,  1524,  1524,  1524,
    1526,  1526,  1528,  1528,  1530,  1543,  1560,  1566,  1577,  1576,
    1622,  1622,  1623,  1624,  1625,  1626,  1627,  1628,  1629,  1630,
    1631,  1633,  1639,  1645,  1651,  1663,  1662,  1668,  1668,  1669,
    1673,  1677,  1681,  1685,  1689,  1693,  1697,  1701,  1705,  1711,
    1725,  1734,  1748,  1747,  1762,  1762,  1763,  1763,  1763,  1763,
    1765,  1771,  1777,  1787,  1789,  1789,  1790,  1790,  1792,  1809,
    1808,  1831,  1831,  1832,  1832,  1832,  1832,  1834,  1840,  1860,
    1859,  1865,  1865,  1866,  1870,  1874,  1878,  1882,  1886,  1890,
    1894,  1898,  1902,  1913,  1912,  1931,  1931,  1932,  1932,  1932,
    1934,  1941,  1940,  1946,  1946,  1947,  1951,  1955,  1959,  1963,
    1967,  1971,  1975,  1979,  1983,  1994,  1993,  2065,  2065,  2066,
    2067,  2068,  2069,  2070,  2071,  2072,  2073,  2074,  2075,  2076,
    2077,  2078,  2079,  2080,  2082,  2088,  2094,  2100,  2113,  2126,
    2132,  2138,  2142,  2149,  2148,  2153,  2153,  2154,  2158,  2164,
    2175,  2181,  2187,  2193,  2209,  2208,  2234,  2234,  2235,  2235,
    2235,  2237,  2257,  2268,  2267,  2294,  2294,  2295,  2295,  2295,
    2297,  2303,  2313,  2315,  2315,  2316,  2316,  2318,  2336,  2335,
    2356,  2356,  2357,  2357,  2357,  2359,  2365,  2375,  2377,  2377,
    2378,  2379,  2380,  2381,  2382,  2383,  2384,  2385,  2386,  2387,
    2388,  2389,  2390,  2391,  2392,  2393,  2394,  2395,  2396,  2397,
    2398,  2399,  2400,  2401,  2402,  2403,  2404,  2405,  2406,  2407,
    2408,  2409,  2410,  2411,  2412,  2413,  2414,  2415,  2416,  2417,
    2418,  2419,  2420,  2421,  2422,  2423,  2424,  2425,  2428,  2433,
    2438,  2443,  2448,  2454,  2459,  2464,  2469,  2474,  2479,  2484,
    2489,  2494,  2499,  2504,  2509,  2514,  2519,  2524,  2530,  2535,
    2540,  2545,  2550,  2555,  2560,  2565,  2568,  2573,  2576,  2581,
    2586,  2591,  2596,  2601,  2606,  2611,  2616,  2621,  2626,  2631,
    2636,  2642,  2641,  2646,  2646,  2647,  2650,  2653,  2656,  2659,
    2662,  2665,  2668,  2671,  2674,  2677,  2680,  2683,  2686,  2689,
    2692,  2695,  2698,  2701,  2704,  2707,  2710,  2716,  2715,  2720,
    2720,  2721,  2724,  2727,  2730,  2733,  2736,  2739,  2742,  2745,
    2748,  2751,  2754,  2757,  2760,  2763,  2766,  2769,  2772,  2775,
    2778,  2783,  2788,  2793,  2798,  2807,  2809,  2809,  2810,  2811,
    2812,  2813,  2814,  2815,  2816,  2817,  2818,  2819,  2820,  2821,
    2822,  2823,  2824,  2826,  2831,  2836,  2841,  2846,  2851,  2856,
    2861,  2866,  2871,  2876,  2881,  2886,  2891,  2900,  2902,  2902,
    2903,  2904,  2905,  2906,  2907,  2908,  2909,  2910,  2911,  2912,
    2914,  2920,  2936,  2945,  2951,  2957,  2963,  2972,  2978
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
  "MAX_BANS", "MAX_BANS_LARGE", "MAX_CHANNELS", "MAX_IDLE", "MAX_INVITES",
  "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MAX_WATCH", "MIN_IDLE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD",
  "NAME", "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME",
  "NICK", "NO_OPER_FLOOD", "NO_TILDE", "NUMBER", "NUMBER_PER_CIDR",
  "NUMBER_PER_IP_GLOBAL", "NUMBER_PER_IP_LOCAL", "OPER_ONLY_UMODES",
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
      59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -1054

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1054)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1054,   723, -1054,  -205,  -214,  -204, -1054, -1054, -1054,  -188,
   -1054,  -183, -1054, -1054, -1054,  -180, -1054, -1054, -1054,  -175,
    -165, -1054,  -159, -1054,  -144, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054,   294,   939,  -143,  -116,  -108,    21,  -107,   414,   -97,
     -96,   -72,    33,   -58,   -57,   -39,   985,   583,   -28,    15,
     -26,    11,   -23,  -156,  -150,    -8,     4,     3, -1054, -1054,
   -1054, -1054, -1054,    23,    50,    52,    60,    68,    69,    71,
      76,    85,    96,   104,   105,   106,   110,   272, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054,   729,   578,    38, -1054,   112,    19, -1054,
   -1054,    81, -1054,   113,   114,   118,   121,   125,   128,   130,
     133,   135,   136,   138,   139,   142,   146,   147,   152,   156,
     157,   170,   173,   174,   175,   176,   178,   179,   180, -1054,
   -1054,   181,   183,   185,   186,   189,   203,   207,   209,   210,
     211,   212,   214,   219,   221,   222,   224,   225,   227,   229,
      55, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,   440,
      41,    67,    -7,   231,   235,     2, -1054, -1054, -1054,    26,
     386,    30, -1054,   236,   237,   238,   239,   242,   244,   245,
     247,   248,   143, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054,    14,   249,   250,   251,   253,   257,   258,
     259,   260,   262,   265,   266,   267,   268,   276,   282,   283,
     285,   153, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
      16,    58,   286,    34, -1054, -1054, -1054,   100,   193, -1054,
     287,    47, -1054, -1054,    62, -1054,   269,   339,   370,   292,
   -1054,   168,   403,   315,   420,   403,   403,   403,   424,   403,
     403,   425,   427,   430,   431,   311, -1054,   312,   310,   313,
     314, -1054,   316,   317,   318,   319,   320,   321,   322,   324,
     328,   331,   333,   230, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
     347,   336,   345,   349,   352,   353,   356, -1054,   357,   359,
     360,   362,   363,   365,   367,   325, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054,   368,   369,    29, -1054, -1054, -1054,   421,   350,
   -1054, -1054,   371,   372,    39, -1054, -1054, -1054,   392,   403,
     435,   403,   403,   395,   449,   403,   396,   500,   501,   505,
     404,   405,   407,   403,   510,   511,   512,   520,   403,   523,
     524,   526,   528,   432,   411,   413,   436,   403,   403,   438,
     443,   444,  -168,  -160,   445,   447,   448,   450,   529,   403,
     452,   403,   403,   454,   551,   437, -1054,   441,   433,   442,
   -1054,   456,   457,   458,   459,   460,    31, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054,   461,   462,    44,
   -1054, -1054, -1054,   453,   463,   465, -1054,   470, -1054,    10,
   -1054, -1054, -1054, -1054, -1054,   544,   546,   455, -1054,   474,
     472,   473,    28, -1054, -1054, -1054,   477,   475,   476, -1054,
     479,   481,   482,   485, -1054,   486,   489,   160, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,   495,
     498,   499,   502,    12, -1054, -1054, -1054, -1054,   467,   469,
     403,   550,   515,   604,   532,   534,   537,   504, -1054, -1054,
     631,   625,   539,   629,   645,   646,   633,   635,   638,   639,
     641,   649,   652,   656,   657,   662,   663,   558, -1054,   561,
     559, -1054,    20, -1054, -1054, -1054, -1054,   584,   567, -1054,
      13,   572,   575,   576,   579,   580,    18, -1054, -1054, -1054,
   -1054, -1054,   687,   586, -1054,   587,   588, -1054,   592,     7,
   -1054, -1054, -1054, -1054,   589,   596,   597, -1054,   598,   261,
     599,   601,   603,   605,   606,   612,   614,   615,   616,   617,
     618,   619,   622, -1054, -1054,   725,   744,   403,   621,   747,
     403,   748,   403,   708,   749,   750,   751,   403,   752,   752,
     632, -1054, -1054,   739,  -119,   740,   654,   742,   745,   637,
     753,   754,   762,   757,   760,   764,   765,   643, -1054,   770,
     772,   665, -1054,   667, -1054,   775,   776,   671, -1054,   675,
     681,   682,   685,   689,   693,   694,   697,   700,   702,   705,
     707,   713,   715,   716,   717,   720,   726,   727,   730,   731,
     732,   733,   737,   738,   741,   756,   602,   743,   746,   758,
     759,   763,   766,   767,   774,   777,   779,   780,   781,   782,
     783,   784,   788,   790,   791,   795,   797,   801, -1054, -1054,
     831,   768,   653,   845,   861,   850,   856,   857,   802, -1054,
     859,   863,   805, -1054, -1054,   866,   868,   761,   886,   806,
   -1054,   807,   811, -1054, -1054,   881,   884,   812, -1054, -1054,
     919,   833,   813,   921,   923,   924,   838,   817,   927,   928,
     823, -1054, -1054,   930,   931,   932,   827, -1054,   828,   829,
     830,   832,   834,   835,   836,   837,   839, -1054,   840,   841,
     842,   843,   844,   846,   847,   848,   849,   851,   852,   853,
     854,   855,   858,   860,   862, -1054, -1054,   937,   864,   865,
   -1054,   869, -1054,    94, -1054,   944,   951,   956,   962,   870,
   -1054,   871, -1054, -1054,   963,   872,   965,   873, -1054, -1054,
   -1054, -1054, -1054,   403,   403,   403,   403,   403,   403,   403,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054,   874,   876,   877,   -29,   878,
     879,   880,   882,   883,   885,   887,   888,   889,   279,   890,
     891, -1054,   892,   893,   894,   895,   896,   897,   898,     6,
     899,   900,   901,   902,   903,   904,   905, -1054,   906,   907,
   -1054, -1054,   908,   909, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054,  -176, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054,  -158, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,   910,   911,
     608,   912,   913,   914,   915,   916, -1054,   917,   918, -1054,
     920,   922,   -33,   875,   925, -1054, -1054, -1054, -1054,   926,
     933, -1054,   934,   935,   493,   936,   938,   940,   941,   710,
     942,   943, -1054,   945,   946,   947, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054,   948,   771, -1054, -1054,   949,   929,   950,
   -1054,    45, -1054, -1054, -1054, -1054,   952,   954,   955,   957,
   -1054, -1054,   958,   778,   959, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,  -149, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,   752,
     752,   752, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054,  -124, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,   756,
   -1054,   602, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054,   -50, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,   -12, -1054,
     982,   886,   960, -1054, -1054, -1054, -1054, -1054, -1054,   867,
   -1054,   961,   964, -1054, -1054,   966,   967, -1054, -1054,   968,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054,   -10, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
      -2, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,    66, -1054,
   -1054,   970,   -85,   953,   974, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054,    80, -1054, -1054, -1054,   -29, -1054, -1054, -1054, -1054,
       6, -1054, -1054, -1054,   608, -1054,   -33, -1054, -1054, -1054,
     981,   984,  1019,  1021,  1024,  1025, -1054,   493, -1054,   710,
   -1054,   771,   975,   976,   977,   295, -1054, -1054,   778, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054,    89, -1054, -1054, -1054,   295, -1054
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   234,   395,   443,     0,
     458,     0,   298,   434,   274,     0,   100,   152,   332,     0,
       0,   373,     0,   109,     0,   349,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   632,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   631,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   618,
     619,   629,   630,     0,     0,     0,   456,     0,     0,   454,
     455,     0,   517,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   587,
     561,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   469,   470,   471,   515,   478,   516,   510,   511,   512,
     513,   509,   482,   472,   473,   474,   475,   476,   477,   479,
     480,   481,   483,   484,   514,   488,   489,   490,   491,   487,
     486,   492,   499,   500,   493,   494,   495,   485,   497,   507,
     508,   505,   506,   498,   496,   503,   504,   501,   502,     0,
       0,     0,     0,     0,     0,     0,    46,    47,    48,     0,
       0,     0,   659,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   649,   650,   651,   652,   653,   654,   655,
     657,   656,   658,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    69,    66,    64,    70,    71,    65,    55,
      68,    58,    59,    60,    56,    67,    61,    62,    63,    57,
       0,     0,     0,     0,   124,   125,   126,     0,     0,   347,
       0,     0,   345,   346,     0,    96,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   616,     0,     0,     0,
       0,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   241,   243,   244,   245,
     246,   247,   248,   249,   239,   240,   242,   250,   251,   252,
       0,     0,     0,     0,     0,     0,     0,   423,     0,     0,
       0,     0,     0,     0,     0,     0,   398,   399,   400,   401,
     402,   403,   404,   406,   405,   408,   412,   409,   410,   411,
     407,   449,     0,     0,     0,   446,   447,   448,     0,     0,
     453,   464,     0,     0,     0,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   468,     0,     0,     0,
     315,     0,     0,     0,     0,     0,     0,   301,   302,   303,
     304,   309,   305,   306,   307,   308,   440,     0,     0,     0,
     437,   438,   439,     0,     0,     0,   276,     0,   286,     0,
     284,   285,   287,   288,    49,     0,     0,     0,    45,     0,
       0,     0,     0,   103,   104,   105,     0,     0,     0,   201,
       0,     0,     0,     0,   175,     0,     0,     0,   155,   156,
     157,   158,   159,   162,   163,   164,   161,   160,   165,     0,
       0,     0,     0,     0,   335,   336,   337,   338,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   648,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,   381,     0,   376,   377,   378,   127,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   115,
     114,   116,     0,     0,   344,     0,     0,   359,     0,     0,
     352,   353,   354,   355,     0,     0,     0,    90,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   615,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,   413,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   397,     0,
       0,     0,   445,     0,   452,     0,     0,     0,   460,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   467,   310,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   300,
       0,     0,     0,   436,   289,     0,     0,     0,     0,     0,
     283,     0,     0,    44,   106,     0,     0,     0,   102,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,   339,     0,     0,     0,     0,   334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   647,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,   379,     0,     0,     0,
     375,     0,   122,     0,   117,     0,     0,     0,     0,     0,
     111,     0,   343,   356,     0,     0,     0,     0,   351,    99,
      98,    97,   645,    28,    28,    28,    28,    28,    28,    28,
      30,    29,   646,   633,   634,   635,   636,   637,   638,   639,
     640,   643,   644,   641,   642,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   396,     0,     0,
     444,   457,     0,     0,   459,   531,   535,   518,   519,   550,
     522,   613,   614,   558,   523,   524,   555,   530,   529,   538,
     528,   525,   526,   534,   533,   532,   556,   520,   611,   612,
     554,   597,   591,   607,   592,   593,   594,   602,   610,   595,
     604,   608,   598,   609,   599,   603,   596,   606,   601,   600,
     605,     0,   590,   570,   571,   572,   565,   583,   566,   567,
     568,   578,   586,   569,   580,   584,   574,   585,   575,   579,
     573,   582,   577,   576,   581,     0,   564,   551,   549,   552,
     557,   553,   540,   547,   548,   545,   546,   541,   542,   543,
     544,   559,   560,   527,   537,   536,   539,   521,     0,     0,
       0,     0,     0,     0,     0,     0,   299,     0,     0,   435,
       0,     0,     0,   294,   290,   293,   275,    50,    51,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   153,     0,     0,     0,   333,   663,   660,   661,
     662,   667,   666,   668,   664,   665,    86,    81,    89,    80,
      87,    88,    79,    83,    82,    74,    73,    78,    75,    77,
      76,    84,    85,     0,     0,   374,   128,     0,     0,     0,
     140,     0,   132,   133,   135,   134,     0,     0,     0,     0,
     110,   348,     0,     0,     0,   350,    31,    32,    33,    34,
      35,    36,    37,   263,   264,   258,   273,   272,     0,   271,
     259,   267,   260,   266,   254,   265,   257,   256,   255,    38,
      38,    38,    40,    39,   261,   262,   418,   421,   422,   432,
     429,   415,   430,   427,   428,     0,   426,   431,   414,   420,
     417,   419,   433,   416,   450,   451,   465,   466,   588,     0,
     562,     0,   313,   314,   324,   320,   321,   323,   328,   325,
     326,   319,   327,   322,     0,   318,   312,   331,   330,   329,
     311,   442,   441,   297,   296,   281,   282,   280,     0,   279,
       0,     0,     0,   107,   108,   174,   171,   221,   233,   208,
     217,     0,   206,   211,   227,     0,   220,   225,   231,   210,
     213,   222,   224,   228,   218,   226,   214,   232,   216,   223,
     212,   215,     0,   204,   167,   169,   172,   173,   184,   185,
     186,   179,   197,   180,   181,   182,   192,   200,   183,   194,
     198,   188,   199,   189,   193,   187,   196,   191,   190,   195,
       0,   178,   168,   170,   342,   340,   341,   380,   385,   391,
     394,   387,   393,   388,   392,   390,   386,   389,     0,   384,
     136,     0,     0,     0,     0,   131,   119,   118,   120,   121,
     357,   363,   369,   372,   365,   371,   366,   370,   368,   364,
     367,     0,   362,   358,   269,     0,    41,    42,    43,   424,
       0,   589,   563,   316,     0,   277,     0,   295,   292,   291,
       0,     0,     0,     0,     0,     0,   202,     0,   176,     0,
     382,     0,     0,     0,     0,     0,   130,   360,     0,   270,
     425,   317,   278,   207,   230,   205,   229,   219,   209,   203,
     177,   383,   137,   139,   138,   150,   149,   145,   147,   151,
     148,   144,   146,     0,   143,   361,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1054, -1054, -1054,  -394,  -310, -1053,  -638, -1054, -1054,   969,
   -1054, -1054, -1054, -1054,   792, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054,  1037, -1054, -1054, -1054, -1054, -1054,
   -1054,   594, -1054, -1054, -1054, -1054, -1054,   565, -1054, -1054,
   -1054, -1054, -1054, -1054,   971, -1054, -1054, -1054, -1054,   107,
   -1054, -1054, -1054, -1054, -1054,  -219, -1054, -1054, -1054,   640,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054,  -118, -1054, -1054, -1054,  -117, -1054, -1054, -1054,   824,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054,   -86, -1054, -1054,
   -1054, -1054, -1054,   -92, -1054,   691, -1054, -1054, -1054,    40,
   -1054, -1054, -1054, -1054, -1054,   734, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054,   -83, -1054, -1054, -1054, -1054, -1054, -1054,
     659, -1054, -1054, -1054, -1054, -1054,   972, -1054, -1054, -1054,
   -1054,   609, -1054, -1054, -1054, -1054, -1054,   -95, -1054, -1054,
   -1054,   623, -1054, -1054, -1054, -1054,   -84, -1054, -1054, -1054,
     973, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054,   -62, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054,   735, -1054, -1054, -1054, -1054, -1054,   815, -1054, -1054,
   -1054, -1054,  1092, -1054, -1054, -1054, -1054,   808, -1054, -1054,
   -1054, -1054,  1041, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054,    92, -1054, -1054,
   -1054,    97, -1054, -1054, -1054, -1054, -1054, -1054,  1118, -1054,
   -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054,   978, -1054, -1054, -1054, -1054,
   -1054, -1054, -1054, -1054, -1054
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   830,   831,  1092,  1093,    27,   225,   226,
     227,   228,    28,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,    29,    77,    78,    79,    80,    81,    30,    63,
     502,   503,   504,   505,    31,    70,   586,   587,   588,   589,
     590,   591,    32,   293,   294,   295,   296,   297,  1051,  1052,
    1053,  1054,  1055,  1233,  1313,  1314,    33,    64,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   757,
    1210,  1211,   528,   752,  1182,  1183,    34,    53,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   628,  1078,  1079,    35,    61,
     488,   737,  1148,  1149,   489,   490,   491,  1152,   994,   995,
     492,   493,    36,    59,   466,   467,   468,   469,   470,   471,
     472,   722,  1134,  1135,   473,   474,   475,    37,    65,   533,
     534,   535,   536,   537,    38,   301,   302,   303,    39,    72,
     599,   600,   601,   602,   603,   815,  1251,  1252,    40,    68,
     572,   573,   574,   575,   798,  1228,  1229,    41,    54,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     649,  1105,  1106,   386,   387,   388,   389,   390,    42,    60,
     479,   480,   481,   482,    43,    55,   394,   395,   396,   397,
      44,   118,   119,   120,    45,    57,   404,   405,   406,   407,
      46,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   435,   955,   956,   214,   434,
     931,   932,   215,   216,   217,   218,    47,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    48,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     859,   860,   610,   222,    73,   613,   614,   615,   595,   617,
     618,   483,   299,   529,  1103,  1145,   291,   569,    51,   581,
     116,   569,   116,  1076,   858,    49,    50,   499,    52,   499,
     391,   529,   457,    74,   222,   291,  1256,  1257,  1258,   391,
     401,    75,   476,   703,    56,   476,  1047,   704,   299,    58,
     458,   705,    62,   530,  1118,   706,   122,    66,  1119,   863,
     864,   123,   124,   595,   125,   126,   484,    67,   483,   127,
     459,   530,  1120,    69,   305,   485,  1121,   486,   128,   129,
     130,  1254,   401,   306,   117,  1255,   117,   131,    71,   113,
     132,   133,   134,   531,   392,  1047,  1077,   135,   460,   670,
     223,   672,   673,   392,    76,   676,  1259,   500,   596,   500,
    1260,   531,   300,   684,   136,   137,   114,   570,   689,   582,
    1283,   570,   224,   484,   115,   121,   138,   698,   699,   139,
     140,   223,   485,   487,   486,   219,   220,   141,   532,   712,
     402,   714,   715,   142,   232,   143,  1048,   144,   300,   145,
     461,   146,   147,   224,   253,   393,   532,  1146,   462,   463,
     221,   506,   148,   596,   393,   403,  1147,   477,   149,   150,
     477,   151,   152,   153,   229,   230,   154,   233,   464,   507,
    1263,   254,   402,   255,  1264,   583,   234,   235,   236,  -129,
     487,   237,   238,   231,   581,  1048,   239,   240,   241,   508,
     501,   155,   501,   584,   290,  1104,   298,   403,  -129,   304,
     256,   156,   157,   158,   159,   160,   161,   162,  1265,   585,
    1276,   257,  1266,   494,  1277,   307,   597,   509,  1278,   598,
     770,   327,  1279,   497,   309,   571,   292,   308,   817,   571,
    1049,   739,   258,   766,   549,   803,   259,   328,   329,   809,
     399,   799,   330,   465,   260,   292,   311,   261,   262,   747,
     661,   510,   728,   478,  1050,   578,   478,   163,   164,   165,
     667,   166,   167,    82,   580,   732,  1234,   608,   593,   511,
     168,   597,   169,   312,   598,   313,   455,   263,   576,  1049,
    1089,  1090,  1091,   314,   582,    73,  1280,   331,    83,    84,
    1281,   315,   316,   264,   317,    85,   265,   266,   267,   318,
    1287,   512,   513,  1050,  1288,   332,   333,   847,   319,  1316,
     850,   334,   852,  1317,    74,   335,   360,   857,   361,   320,
     362,   336,    75,    86,    87,    88,    89,   321,   322,   323,
     337,   338,   339,   324,   363,   398,   408,   409,    90,    91,
      92,   410,   340,   268,   411,    93,    94,    95,   412,    96,
     583,   413,   514,   414,   364,  1305,   415,  1306,   416,   417,
     609,   418,   419,   341,   547,   420,   269,   270,   584,   421,
     422,   365,   515,   366,   567,   423,   516,   506,   858,   424,
     425,   760,   367,   604,   585,    76,   823,   824,   825,   826,
     827,   828,   829,   426,   368,   507,   427,   428,   429,   430,
    1307,   431,   432,   433,   436,   122,   437,   342,   438,   439,
     123,   124,   440,   125,   126,   508,   369,  1308,   127,  1066,
    1067,  1068,  1069,  1070,  1071,  1072,   441,   128,   129,   130,
     442,   457,   443,   444,   445,   446,   131,   447,   370,   132,
     133,   134,   448,   509,   449,   450,   135,   451,   452,   458,
     453,   640,   454,   605,   495,  1309,  1310,   371,   496,   538,
     539,   540,   541,   136,   137,   542,   372,   543,   544,   459,
     545,   546,   550,   551,   552,   138,   553,   510,   139,   140,
     554,   555,   556,   557,   606,   558,   141,  1157,   559,   560,
     561,   562,   142,   325,   143,   511,   144,   460,   145,   563,
     146,   147,   609,  1158,  1159,   564,   565,  1311,   566,   577,
     592,   148,   607,  1312,  1160,   373,   611,   149,   150,   612,
     151,   152,   153,   616,   619,   154,   620,   512,   513,   621,
     622,   623,   624,   625,   671,   663,   626,   627,   374,   629,
     630,   631,   632,   633,   634,   635,   657,   636,   675,   461,
     155,   637,  1161,  1162,   638,  1163,   639,   462,   463,   643,
     156,   157,   158,   159,   160,   161,   162,   642,   644,   360,
     664,   361,   645,   362,   253,   646,   647,   464,   514,   648,
     650,  1164,   651,   652,  1284,   653,   654,   363,   655,  1165,
     656,   659,   660,   669,   665,   666,   674,   677,   515,   678,
     679,   254,   516,   255,   680,   681,   682,   364,   683,   685,
     686,   687,  1166,  1124,  1167,  1168,   163,   164,   165,   688,
     166,   167,   690,   691,   365,   692,   366,   693,   711,   168,
     256,   169,  1169,   694,   695,   367,   696,   697,  1125,   700,
     933,   257,   934,   935,   701,   702,   707,   368,   708,   709,
     717,   710,   465,   713,  1170,   716,   720,   718,   741,  1171,
     742,   719,   258,  1172,   771,   721,   259,  1173,   768,   369,
     769,  1126,  1174,   734,   260,   743,  1175,   261,   262,   723,
     724,   725,   726,   727,   730,   731,   735,  1176,   736,  1177,
    1178,   370,  1179,   738,   744,   745,   746,   749,   750,   751,
    1127,  1128,   753,  1180,   754,   755,  1129,   263,   756,   758,
     371,  1181,   759,     2,     3,   762,   772,     4,   773,   372,
     327,   763,   764,   264,   777,   765,   265,   266,   267,     5,
     778,  1130,     6,   774,     7,   775,   328,   329,   776,   779,
     780,   330,     8,   781,   782,   783,  1131,   784,  1188,   785,
    1189,  1190,   786,   787,     9,   788,   936,   937,   938,    10,
      11,   939,   940,   789,   941,   942,   790,   943,   373,   944,
     791,   792,   945,   268,   946,   947,   793,   794,   795,    12,
     948,   796,   797,    13,   949,   801,   331,   802,   950,   951,
     952,   374,   804,    14,   911,   953,   269,   270,   805,   806,
     954,   811,   807,   808,   332,   333,   812,   813,  1132,   819,
     334,   814,    15,    16,   335,   816,   820,   821,   822,   832,
     336,   833,   853,   834,   845,   835,   836,  1133,    17,   337,
     338,   339,   837,  1218,   838,   839,   840,   841,   842,   843,
    1241,   340,   844,   846,   848,    18,   849,   851,   854,   855,
     856,   858,   861,   862,   865,   866,   867,    19,    20,   868,
     869,   872,   341,   877,  1191,  1192,  1193,   870,   871,  1194,
    1195,   873,  1196,  1197,   874,  1198,   980,  1199,   875,   876,
    1200,    21,  1201,  1202,   878,   880,   879,   881,  1203,   882,
     883,   884,  1204,  1219,    22,   885,  1205,  1206,  1207,    23,
    1242,   886,   887,  1208,    24,   888,   342,    25,  1209,   889,
     912,   913,   914,   890,   891,   915,   916,   892,   917,   918,
     893,   919,   894,   920,  1220,   895,   921,   896,   922,   923,
      82,  1243,  1221,   897,   924,   898,   899,   900,   925,  1244,
     901,  1222,   926,   927,   928,   978,   902,   903,  1245,   929,
     904,   905,   906,   907,   930,    83,    84,   908,   909,   981,
     982,   910,    85,   957,   983,  1223,   958,  1224,  1225,   979,
     984,   985,  1246,   987,  1247,  1248,   232,   988,   959,   960,
     990,  1226,   991,   961,   992,   993,   962,   963,  1249,  1227,
      86,    87,    88,    89,   964,   999,  1250,   965,  1000,   966,
     967,   968,   969,   970,   971,    90,    91,    92,   972,   233,
     973,   974,    93,    94,    95,   975,    96,   976,   234,   235,
     236,   977,   986,   237,   238,   989,   996,   997,   239,   240,
     241,   998,  1001,  1002,  1003,  1005,  1004,  1006,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
    1019,  1043,  1020,   568,  1021,  1022,  1023,  1024,  1056,  1025,
    1026,  1027,  1028,  1029,  1030,  1057,  1031,  1032,  1033,  1034,
    1058,  1035,  1036,  1037,  1038,  1039,  1059,  1062,  1040,  1064,
    1041,  1267,  1042,  1150,  1282,  1045,   748,  1044,  1318,  1046,
    1060,  1061,  1270,  1065,  1073,  1063,  1074,  1075,  1080,  1081,
    1082,  1293,  1083,  1084,   310,  1085,  1294,  1086,  1087,  1088,
    1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1117,
    1122,  1123,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1295,
    1143,   810,  1144,  1296,  1297,  1298,  1153,   761,  1235,  1151,
    1299,  1300,  1231,  1154,  1155,  1156,  1184,   641,  1185,  1289,
    1186,  1187,  1212,  1213,  1292,  1214,  1215,  1216,  1217,  1230,
     740,  1291,  1236,  1232,  1237,  1238,  1285,  1239,  1240,  1253,
    1269,  1268,   767,  1315,   498,   800,  1271,  1301,  1290,  1272,
     729,  1273,  1274,  1275,  1286,  1302,  1303,  1304,   818,   662,
     400,   456,   668,  1262,   733,   326,  1261,     0,     0,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   579,     0,     0,     0,     0,     0,
       0,     0,     0,   594,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   658
};

static const yytype_int16 yycheck[] =
{
     638,   639,   312,     1,     1,   315,   316,   317,     1,   319,
     320,     1,     1,     1,     8,    48,     1,     1,   232,     1,
       1,     1,     1,    52,   109,   230,   231,     1,   232,     1,
       1,     1,     1,    30,     1,     1,  1089,  1090,  1091,     1,
       1,    38,     1,   211,   232,     1,     1,   215,     1,   232,
      19,   211,   232,    41,   230,   215,     1,   232,   234,   178,
     179,     6,     7,     1,     9,    10,    56,   232,     1,    14,
      39,    41,   230,   232,   230,    65,   234,    67,    23,    24,
      25,   230,     1,   233,    65,   234,    65,    32,   232,   232,
      35,    36,    37,    81,    65,     1,   125,    42,    67,   409,
      98,   411,   412,    65,   101,   415,   230,    81,   101,    81,
     234,    81,   101,   423,    59,    60,   232,   101,   428,   101,
     205,   101,   120,    56,   232,   232,    71,   437,   438,    74,
      75,    98,    65,   123,    67,   232,   232,    82,   126,   449,
     101,   451,   452,    88,     1,    90,   101,    92,   101,    94,
     119,    96,    97,   120,     1,   126,   126,   190,   127,   128,
     232,     1,   107,   101,   126,   126,   199,   126,   113,   114,
     126,   116,   117,   118,   232,   232,   121,    34,   147,    19,
     230,    28,   101,    30,   234,   167,    43,    44,    45,   174,
     123,    48,    49,   232,     1,   101,    53,    54,    55,    39,
     174,   146,   174,   185,   232,   199,   232,   126,   174,   232,
      57,   156,   157,   158,   159,   160,   161,   162,   230,   201,
     230,    68,   234,   230,   234,   233,   219,    67,   230,   222,
     540,     1,   234,   231,   231,   219,   221,   233,   231,   219,
     195,   231,    89,   231,   230,   232,    93,    17,    18,   231,
     231,   231,    22,   222,   101,   221,   233,   104,   105,   231,
     231,   101,   231,   222,   219,   231,   222,   212,   213,   214,
     231,   216,   217,     1,   174,   231,   231,   109,   231,   119,
     225,   219,   227,   233,   222,   233,   231,   134,   230,   195,
      11,    12,    13,   233,   101,     1,   230,    67,    26,    27,
     234,   233,   233,   150,   233,    33,   153,   154,   155,   233,
     230,   151,   152,   219,   234,    85,    86,   627,   233,   230,
     630,    91,   632,   234,    30,    95,     1,   637,     3,   233,
       5,   101,    38,    61,    62,    63,    64,   233,   233,   233,
     110,   111,   112,   233,    19,   233,   233,   233,    76,    77,
      78,   233,   122,   200,   233,    83,    84,    85,   233,    87,
     167,   233,   202,   233,    39,    70,   233,    72,   233,   233,
     109,   233,   233,   143,   231,   233,   223,   224,   185,   233,
     233,    56,   222,    58,   231,   233,   226,     1,   109,   233,
     233,   231,    67,   124,   201,   101,   135,   136,   137,   138,
     139,   140,   141,   233,    79,    19,   233,   233,   233,   233,
     115,   233,   233,   233,   233,     1,   233,   187,   233,   233,
       6,     7,   233,     9,    10,    39,   101,   132,    14,   823,
     824,   825,   826,   827,   828,   829,   233,    23,    24,    25,
     233,     1,   233,   233,   233,   233,    32,   233,   123,    35,
      36,    37,   233,    67,   233,   233,    42,   233,   233,    19,
     233,   231,   233,   124,   233,   170,   171,   142,   233,   233,
     233,   233,   233,    59,    60,   233,   151,   233,   233,    39,
     233,   233,   233,   233,   233,    71,   233,   101,    74,    75,
     233,   233,   233,   233,   124,   233,    82,     4,   233,   233,
     233,   233,    88,   231,    90,   119,    92,    67,    94,   233,
      96,    97,   109,    20,    21,   233,   233,   222,   233,   233,
     233,   107,   230,   228,    31,   200,   211,   113,   114,   109,
     116,   117,   118,   109,   109,   121,   109,   151,   152,   109,
     109,   230,   230,   233,   109,   124,   233,   233,   223,   233,
     233,   233,   233,   233,   233,   233,   231,   233,   109,   119,
     146,   233,    69,    70,   233,    72,   233,   127,   128,   233,
     156,   157,   158,   159,   160,   161,   162,   230,   233,     1,
     230,     3,   233,     5,     1,   233,   233,   147,   202,   233,
     233,    98,   233,   233,  1232,   233,   233,    19,   233,   106,
     233,   233,   233,   211,   233,   233,   211,   211,   222,   109,
     109,    28,   226,    30,   109,   211,   211,    39,   211,   109,
     109,   109,   129,    15,   131,   132,   212,   213,   214,   109,
     216,   217,   109,   109,    56,   109,    58,   109,   109,   225,
      57,   227,   149,   211,   233,    67,   233,   211,    40,   211,
      48,    68,    50,    51,   211,   211,   211,    79,   211,   211,
     109,   211,   222,   211,   171,   211,   233,   230,   124,   176,
     124,   230,    89,   180,   124,   233,    93,   184,   211,   101,
     211,    73,   189,   230,   101,   230,   193,   104,   105,   233,
     233,   233,   233,   233,   233,   233,   233,   204,   233,   206,
     207,   123,   209,   233,   230,   233,   233,   230,   233,   233,
     102,   103,   233,   220,   233,   233,   108,   134,   233,   233,
     142,   228,   233,     0,     1,   230,   211,     4,   124,   151,
       1,   233,   233,   150,   230,   233,   153,   154,   155,    16,
     109,   133,    19,   211,    21,   211,    17,    18,   211,   124,
     211,    22,    29,   124,   109,   109,   148,   124,    48,   124,
      50,    51,   124,   124,    41,   124,   164,   165,   166,    46,
      47,   169,   170,   124,   172,   173,   124,   175,   200,   177,
     124,   124,   180,   200,   182,   183,   124,   124,   230,    66,
     188,   230,   233,    70,   192,   211,    67,   230,   196,   197,
     198,   223,   230,    80,    48,   203,   223,   224,   233,   233,
     208,   124,   233,   233,    85,    86,   230,   230,   210,   230,
      91,   233,    99,   100,    95,   233,   230,   230,   230,   230,
     101,   230,   124,   230,   109,   230,   230,   229,   115,   110,
     111,   112,   230,    72,   230,   230,   230,   230,   230,   230,
      72,   122,   230,   109,   233,   132,   109,   109,   109,   109,
     109,   109,   230,   124,   124,   211,   124,   144,   145,   124,
     233,   109,   143,   230,   164,   165,   166,   124,   124,   169,
     170,   124,   172,   173,   124,   175,   233,   177,   124,   124,
     180,   168,   182,   183,   124,   230,   124,   230,   188,   124,
     124,   230,   192,   132,   181,   230,   196,   197,   198,   186,
     132,   230,   230,   203,   191,   230,   187,   194,   208,   230,
     164,   165,   166,   230,   230,   169,   170,   230,   172,   173,
     230,   175,   230,   177,   163,   230,   180,   230,   182,   183,
       1,   163,   171,   230,   188,   230,   230,   230,   192,   171,
     230,   180,   196,   197,   198,   124,   230,   230,   180,   203,
     230,   230,   230,   230,   208,    26,    27,   230,   230,   124,
     109,   230,    33,   230,   124,   204,   230,   206,   207,   211,
     124,   124,   204,   124,   206,   207,     1,   124,   230,   230,
     124,   220,   124,   230,   233,   109,   230,   230,   220,   228,
      61,    62,    63,    64,   230,   124,   228,   230,   124,   230,
     230,   230,   230,   230,   230,    76,    77,    78,   230,    34,
     230,   230,    83,    84,    85,   230,    87,   230,    43,    44,
      45,   230,   230,    48,    49,   230,   230,   230,    53,    54,
      55,   230,   230,   124,   211,   124,   233,   124,   124,   211,
     233,   124,   124,   230,   124,   124,   124,   230,   230,   230,
     230,   124,   230,   271,   230,   230,   230,   230,   124,   230,
     230,   230,   230,   230,   230,   124,   230,   230,   230,   230,
     124,   230,   230,   230,   230,   230,   124,   124,   230,   124,
     230,   109,   230,   218,   124,   230,   502,   233,  1317,   230,
     230,   230,   235,   230,   230,   233,   230,   230,   230,   230,
     230,   130,   230,   230,    77,   230,   132,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   130,
     230,   586,   230,   132,   130,   130,   230,   517,  1051,   234,
    1277,  1279,   233,   230,   230,   230,   230,   343,   230,  1255,
     230,   230,   230,   230,  1266,   230,   230,   230,   230,   230,
     489,  1264,   230,   233,   230,   230,   233,   230,   230,   230,
     230,  1151,   533,  1288,   225,   572,   235,  1281,  1260,   235,
     466,   235,   235,   235,   230,   230,   230,   230,   599,   394,
     118,   170,   404,  1121,   479,    97,  1119,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   375
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   237,     0,     1,     4,    16,    19,    21,    29,    41,
      46,    47,    66,    70,    80,    99,   100,   115,   132,   144,
     145,   168,   181,   186,   191,   194,   238,   243,   248,   268,
     274,   280,   288,   302,   322,   344,   358,   373,   380,   384,
     394,   403,   424,   430,   436,   440,   446,   502,   519,   230,
     231,   232,   232,   323,   404,   431,   232,   441,   232,   359,
     425,   345,   232,   275,   303,   374,   232,   232,   395,   232,
     281,   232,   385,     1,    30,    38,   101,   269,   270,   271,
     272,   273,     1,    26,    27,    33,    61,    62,    63,    64,
      76,    77,    78,    83,    84,    85,    87,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   232,   232,   232,     1,    65,   437,   438,
     439,   232,     1,     6,     7,     9,    10,    14,    23,    24,
      25,    32,    35,    36,    37,    42,    59,    60,    71,    74,
      75,    82,    88,    90,    92,    94,    96,    97,   107,   113,
     114,   116,   117,   118,   121,   146,   156,   157,   158,   159,
     160,   161,   162,   212,   213,   214,   216,   217,   225,   227,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   494,   498,   499,   500,   501,   232,
     232,   232,     1,    98,   120,   244,   245,   246,   247,   232,
     232,   232,     1,    34,    43,    44,    45,    48,    49,    53,
      54,    55,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,     1,    28,    30,    57,    68,    89,    93,
     101,   104,   105,   134,   150,   153,   154,   155,   200,   223,
     224,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     232,     1,   221,   289,   290,   291,   292,   293,   232,     1,
     101,   381,   382,   383,   232,   230,   233,   233,   233,   231,
     270,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   231,   504,     1,    17,    18,
      22,    67,    85,    86,    91,    95,   101,   110,   111,   112,
     122,   143,   187,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
       1,     3,     5,    19,    39,    56,    58,    67,    79,   101,
     123,   142,   151,   200,   223,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   419,   420,   421,   422,
     423,     1,    65,   126,   432,   433,   434,   435,   233,   231,
     438,     1,   101,   126,   442,   443,   444,   445,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   495,   491,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   231,   448,     1,    19,    39,
      67,   119,   127,   128,   147,   222,   360,   361,   362,   363,
     364,   365,   366,   370,   371,   372,     1,   126,   222,   426,
     427,   428,   429,     1,    56,    65,    67,   123,   346,   350,
     351,   352,   356,   357,   230,   233,   233,   231,   245,     1,
      81,   174,   276,   277,   278,   279,     1,    19,    39,    67,
     101,   119,   151,   152,   202,   222,   226,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   318,     1,
      41,    81,   126,   375,   376,   377,   378,   379,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   231,   521,   230,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   231,   250,     1,
     101,   219,   396,   397,   398,   399,   230,   233,   231,   290,
     174,     1,   101,   167,   185,   201,   282,   283,   284,   285,
     286,   287,   233,   231,   382,     1,   101,   219,   222,   386,
     387,   388,   389,   390,   124,   124,   124,   230,   109,   109,
     240,   211,   109,   240,   240,   240,   109,   240,   240,   109,
     109,   109,   109,   230,   230,   233,   233,   233,   341,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     231,   325,   230,   233,   233,   233,   233,   233,   233,   416,
     233,   233,   233,   233,   233,   233,   233,   231,   406,   233,
     233,   231,   433,   124,   230,   233,   233,   231,   443,   211,
     240,   109,   240,   240,   211,   109,   240,   211,   109,   109,
     109,   211,   211,   211,   240,   109,   109,   109,   109,   240,
     109,   109,   109,   109,   211,   233,   233,   211,   240,   240,
     211,   211,   211,   211,   215,   211,   215,   211,   211,   211,
     211,   109,   240,   211,   240,   240,   211,   109,   230,   230,
     233,   233,   367,   233,   233,   233,   233,   233,   231,   361,
     233,   233,   231,   427,   230,   233,   233,   347,   233,   231,
     351,   124,   124,   230,   230,   233,   233,   231,   277,   230,
     233,   233,   319,   233,   233,   233,   233,   315,   233,   233,
     231,   305,   230,   233,   233,   233,   231,   376,   211,   211,
     240,   124,   211,   124,   211,   211,   211,   230,   109,   124,
     211,   124,   109,   109,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   230,   230,   233,   400,   231,
     397,   211,   230,   232,   230,   233,   233,   233,   233,   231,
     283,   124,   230,   230,   233,   391,   233,   231,   387,   230,
     230,   230,   230,   135,   136,   137,   138,   139,   140,   141,
     239,   240,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   109,   109,   240,   233,   109,
     240,   109,   240,   124,   109,   109,   109,   240,   109,   242,
     242,   230,   124,   178,   179,   124,   211,   124,   124,   233,
     124,   124,   109,   124,   124,   124,   124,   230,   124,   124,
     230,   230,   124,   124,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,    48,   164,   165,   166,   169,   170,   172,   173,   175,
     177,   180,   182,   183,   188,   192,   196,   197,   198,   203,
     208,   496,   497,    48,    50,    51,   164,   165,   166,   169,
     170,   172,   173,   175,   177,   180,   182,   183,   188,   192,
     196,   197,   198,   203,   208,   492,   493,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   124,   211,
     233,   124,   109,   124,   124,   124,   230,   124,   124,   230,
     124,   124,   233,   109,   354,   355,   230,   230,   230,   124,
     124,   230,   124,   211,   233,   124,   124,   124,   211,   233,
     124,   124,   230,   124,   124,   124,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   124,   233,   230,   230,     1,   101,   195,
     219,   294,   295,   296,   297,   298,   124,   124,   124,   124,
     230,   230,   124,   233,   124,   230,   239,   239,   239,   239,
     239,   239,   239,   230,   230,   230,    52,   125,   342,   343,
     230,   230,   230,   230,   230,   230,   230,   230,   230,    11,
      12,    13,   241,   242,   230,   230,   230,   230,   230,   230,
     230,   230,   230,     8,   199,   417,   418,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   234,
     230,   234,   230,   230,    15,    40,    73,   102,   103,   108,
     133,   148,   210,   229,   368,   369,   230,   230,   230,   230,
     230,   230,   230,   230,   230,    48,   190,   199,   348,   349,
     218,   234,   353,   230,   230,   230,   230,     4,    20,    21,
      31,    69,    70,    72,    98,   106,   129,   131,   132,   149,
     171,   176,   180,   184,   189,   193,   204,   206,   207,   209,
     220,   228,   320,   321,   230,   230,   230,   230,    48,    50,
      51,   164,   165,   166,   169,   170,   172,   173,   175,   177,
     180,   182,   183,   188,   192,   196,   197,   198,   203,   208,
     316,   317,   230,   230,   230,   230,   230,   230,    72,   132,
     163,   171,   180,   204,   206,   207,   220,   228,   401,   402,
     230,   233,   233,   299,   231,   295,   230,   230,   230,   230,
     230,    72,   132,   163,   171,   180,   204,   206,   207,   220,
     228,   392,   393,   230,   230,   234,   241,   241,   241,   230,
     234,   497,   493,   230,   234,   230,   234,   109,   355,   230,
     235,   235,   235,   235,   235,   235,   230,   234,   230,   234,
     230,   234,   124,   205,   242,   233,   230,   230,   234,   343,
     418,   369,   349,   130,   132,   130,   132,   130,   130,   321,
     317,   402,   230,   230,   230,    70,    72,   115,   132,   170,
     171,   222,   228,   300,   301,   393,   230,   234,   301
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   236,   237,   237,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   239,   239,
     240,   240,   240,   240,   240,   240,   240,   240,   241,   241,
     242,   242,   242,   242,   243,   244,   244,   245,   245,   245,
     246,   247,   248,   249,   249,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   269,   270,   270,   270,   270,   271,   272,   273,
     275,   274,   276,   276,   277,   277,   277,   278,   279,   281,
     280,   282,   282,   283,   283,   283,   283,   283,   284,   285,
     286,   287,   288,   289,   289,   290,   290,   290,   291,   293,
     292,   294,   294,   295,   295,   295,   295,   296,   297,   297,
     299,   298,   300,   300,   301,   301,   301,   301,   301,   301,
     301,   301,   303,   302,   304,   304,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   315,   314,   316,   316,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   319,   318,   320,   320,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   323,   322,   324,   324,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   341,   340,
     342,   342,   343,   343,   345,   344,   347,   346,   348,   348,
     349,   349,   349,   350,   350,   351,   351,   351,   351,   351,
     353,   352,   354,   354,   355,   355,   356,   357,   359,   358,
     360,   360,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   362,   363,   364,   365,   367,   366,   368,   368,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   370,
     371,   372,   374,   373,   375,   375,   376,   376,   376,   376,
     377,   378,   379,   380,   381,   381,   382,   382,   383,   385,
     384,   386,   386,   387,   387,   387,   387,   388,   389,   391,
     390,   392,   392,   393,   393,   393,   393,   393,   393,   393,
     393,   393,   393,   395,   394,   396,   396,   397,   397,   397,
     398,   400,   399,   401,   401,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   404,   403,   405,   405,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   414,   416,   415,   417,   417,   418,   418,   419,
     420,   421,   422,   423,   425,   424,   426,   426,   427,   427,
     427,   428,   429,   431,   430,   432,   432,   433,   433,   433,
     434,   435,   436,   437,   437,   438,   438,   439,   441,   440,
     442,   442,   443,   443,   443,   444,   445,   446,   447,   447,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   476,   477,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   491,   490,   492,   492,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   495,   494,   496,
     496,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   498,   499,   500,   501,   502,   503,   503,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   520,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530
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
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     0,     6,     0,     5,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       0,     5,     3,     1,     1,     3,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     2,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     4,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4
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
#line 405 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2869 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 406 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 407 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 408 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 409 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 410 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2905 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2923 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2941 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 433 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 439 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 472 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_certificate_file);
    ConfigServerInfo.ssl_certificate_file = xstrdup(yylval.string);
  }
}
#line 2977 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 481 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 2989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 490 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_param_file);
    ConfigServerInfo.ssl_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 499 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_cipher_list);
    ConfigServerInfo.ssl_cipher_list = xstrdup(yylval.string);
  }
}
#line 3013 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 508 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_message_digest_algorithm);
    ConfigServerInfo.ssl_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 517 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_elliptic_curve);
    ConfigServerInfo.ssl_dh_elliptic_curve = xstrdup(yylval.string);
  }
}
#line 3037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 526 "conf_parser.y" /* yacc.c:1646  */
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
#line 3055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 541 "conf_parser.y" /* yacc.c:1646  */
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
#line 3073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 556 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 566 "conf_parser.y" /* yacc.c:1646  */
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
#line 3103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 580 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 589 "conf_parser.y" /* yacc.c:1646  */
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
#line 3146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 617 "conf_parser.y" /* yacc.c:1646  */
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
#line 3177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 645 "conf_parser.y" /* yacc.c:1646  */
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
#line 3205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 670 "conf_parser.y" /* yacc.c:1646  */
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
#line 3230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 692 "conf_parser.y" /* yacc.c:1646  */
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
#line 3255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 714 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 732 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3276 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 741 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 750 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 763 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 767 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 784 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3335 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 790 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 800 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3353 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 804 "conf_parser.y" /* yacc.c:1646  */
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
#line 3371 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 822 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3380 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 828 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 840 "conf_parser.y" /* yacc.c:1646  */
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
#line 3419 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 868 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 874 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 878 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 894 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 902 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 905 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3477 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 910 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 917 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3495 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 921 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3513 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 929 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3522 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 933 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 937 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3540 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 941 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3549 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 945 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 955 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3570 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 962 "conf_parser.y" /* yacc.c:1646  */
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
#line 3627 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3636 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3645 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3654 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1047 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3663 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3677 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1064 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3686 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3700 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1081 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1087 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3718 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1094 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3727 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1098 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3736 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1102 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3745 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1106 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3754 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1110 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3763 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1114 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3772 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1118 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3781 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1122 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3790 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1126 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3799 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1130 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3808 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1134 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3817 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1138 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3826 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1142 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3835 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1146 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3844 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1150 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3853 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1154 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3862 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1158 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1162 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1166 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1170 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1174 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1178 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1184 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1195 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1199 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1203 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1207 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3970 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1211 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3979 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1215 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3988 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1219 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3997 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1223 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1227 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1231 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1235 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4033 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1239 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4042 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4051 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1247 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4060 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1251 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1259 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1267 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4105 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1271 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4114 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1275 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4123 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1279 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4132 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1283 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4141 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1291 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1295 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1299 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1303 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
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
#line 4203 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
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

  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;

  class_ip_limit_rebuild(class);
}
#line 4249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1386 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1392 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4267 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1398 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4276 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1404 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4285 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1410 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1416 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4303 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1422 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1428 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4321 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1434 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4331 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1453 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1459 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4370 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1468 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1477 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1484 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1488 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1498 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1504 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1510 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1514 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1518 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1526 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1531 "conf_parser.y" /* yacc.c:1646  */
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
#line 4477 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1544 "conf_parser.y" /* yacc.c:1646  */
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
#line 4497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1561 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1567 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1577 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4524 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1581 "conf_parser.y" /* yacc.c:1646  */
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
#line 4569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1634 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1640 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4587 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1646 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4596 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1652 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4610 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1663 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1670 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4628 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1674 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4637 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1678 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4646 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1682 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4655 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1686 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4664 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1690 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1694 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1698 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1702 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4700 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1706 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1712 "conf_parser.y" /* yacc.c:1646  */
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
#line 4726 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1726 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4738 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1735 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4750 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1748 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1755 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1766 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1772 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1778 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1793 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string))
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1809 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4831 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1820 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1841 "conf_parser.y" /* yacc.c:1646  */
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
#line 4877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1860 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1867 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1871 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1875 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1879 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1883 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1887 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1891 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1895 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1899 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1903 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1913 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 4990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1922 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5003 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1935 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1941 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1948 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1952 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1956 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1960 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1964 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1972 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1976 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1980 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1984 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1994 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2003 "conf_parser.y" /* yacc.c:1646  */
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
#line 5191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2083 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2089 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2095 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2101 "conf_parser.y" /* yacc.c:1646  */
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
#line 5234 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2114 "conf_parser.y" /* yacc.c:1646  */
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
#line 5250 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2127 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5259 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2133 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5268 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2139 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5277 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5286 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2149 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2155 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5303 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2159 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2165 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2176 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5335 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2182 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2188 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5353 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2194 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2209 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2213 "conf_parser.y" /* yacc.c:1646  */
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
#line 5401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2238 "conf_parser.y" /* yacc.c:1646  */
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
#line 5424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2258 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2272 "conf_parser.y" /* yacc.c:1646  */
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
#line 5468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2298 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5477 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2319 "conf_parser.y" /* yacc.c:1646  */
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
#line 5503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2340 "conf_parser.y" /* yacc.c:1646  */
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
#line 5532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2360 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2366 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2429 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2434 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5566 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2439 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2444 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2449 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5591 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2455 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5599 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2460 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2465 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2470 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5623 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2475 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5631 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2480 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5639 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2485 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5647 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2490 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5655 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2495 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5663 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2500 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5671 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2505 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2510 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5687 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2515 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5695 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2520 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5703 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2525 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5712 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2531 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5720 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2536 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5728 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2541 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5736 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2546 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5744 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2551 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5752 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2556 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5760 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2561 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2566 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2569 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2574 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2577 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2582 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5808 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2587 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2592 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2597 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2602 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2607 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5848 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2612 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2617 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2622 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2627 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2632 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2637 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2642 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2648 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2651 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2654 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2657 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2660 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2663 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2666 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2669 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2672 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2675 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2678 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2681 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2684 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2687 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2690 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2693 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2696 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2699 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2702 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2705 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2708 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2711 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2716 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2722 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2725 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2728 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2731 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2734 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2737 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2740 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2743 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2746 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2749 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2752 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2755 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6184 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2758 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2761 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2764 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2767 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2770 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2773 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2776 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2779 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2784 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2789 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2794 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2799 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2827 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2832 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2847 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2862 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 2867 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2877 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2882 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 2892 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 2915 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 2921 "conf_parser.y" /* yacc.c:1646  */
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
#line 6420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 2937 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 2946 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 2952 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 2958 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 666:
#line 2964 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6471 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 2973 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 668:
#line 2979 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6489 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6493 "conf_parser.c" /* yacc.c:1646  */
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
