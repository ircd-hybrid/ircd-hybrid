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


#define YY_NO_UNPUT
#include <sys/types.h>
#include <string.h>

#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_pseudo.h"
#include "event.h"
#include "log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "irc_string.h"
#include "memory.h"
#include "modules.h"
#include "server.h"
#include "hostmask.h"
#include "send.h"
#include "listener.h"
#include "resv.h"
#include "numeric.h"
#include "user.h"
#include "motd.h"

#ifdef HAVE_LIBCRYPTO
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <openssl/dh.h>
#endif

#include "rsa.h"

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
    MyFree(node->data);
    dlinkDelete(node, &block_state.mask.list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, block_state.leaf.list.head)
  {
    MyFree(node->data);
    dlinkDelete(node, &block_state.leaf.list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, block_state.hub.list.head)
  {
    MyFree(node->data);
    dlinkDelete(node, &block_state.hub.list);
    free_dlink_node(node);
  }

  memset(&block_state, 0, sizeof(block_state));
}


#line 190 "conf_parser.c" /* yacc.c:339  */

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
    CONNECT = 275,
    CONNECTFREQ = 276,
    CYCLE_ON_HOST_CHANGE = 277,
    DEFAULT_FLOODCOUNT = 278,
    DEFAULT_JOIN_FLOOD_COUNT = 279,
    DEFAULT_JOIN_FLOOD_TIME = 280,
    DEFAULT_MAX_CLIENTS = 281,
    DEFAULT_SPLIT_SERVER_COUNT = 282,
    DEFAULT_SPLIT_USER_COUNT = 283,
    DENY = 284,
    DESCRIPTION = 285,
    DIE = 286,
    DISABLE_AUTH = 287,
    DISABLE_FAKE_CHANNELS = 288,
    DISABLE_REMOTE_COMMANDS = 289,
    DOTS_IN_IDENT = 290,
    EMAIL = 291,
    ENCRYPTED = 292,
    EXCEED_LIMIT = 293,
    EXEMPT = 294,
    FAILED_OPER_NOTICE = 295,
    FLATTEN_LINKS = 296,
    GECOS = 297,
    GENERAL = 298,
    GLINE = 299,
    GLINE_DURATION = 300,
    GLINE_ENABLE = 301,
    GLINE_EXEMPT = 302,
    GLINE_MIN_CIDR = 303,
    GLINE_MIN_CIDR6 = 304,
    GLINE_REQUEST_DURATION = 305,
    GLOBAL_KILL = 306,
    HAVENT_READ_CONF = 307,
    HIDDEN = 308,
    HIDDEN_NAME = 309,
    HIDE_CHANS = 310,
    HIDE_IDLE = 311,
    HIDE_IDLE_FROM_OPERS = 312,
    HIDE_SERVER_IPS = 313,
    HIDE_SERVERS = 314,
    HIDE_SERVICES = 315,
    HIDE_SPOOF_IPS = 316,
    HOST = 317,
    HUB = 318,
    HUB_MASK = 319,
    IGNORE_BOGUS_TS = 320,
    INVISIBLE_ON_CONNECT = 321,
    INVITE_CLIENT_COUNT = 322,
    INVITE_CLIENT_TIME = 323,
    IP = 324,
    IRCD_AUTH = 325,
    IRCD_FLAGS = 326,
    IRCD_SID = 327,
    KILL = 328,
    KILL_CHASE_TIME_LIMIT = 329,
    KLINE = 330,
    KLINE_EXEMPT = 331,
    KNOCK_CLIENT_COUNT = 332,
    KNOCK_CLIENT_TIME = 333,
    KNOCK_DELAY_CHANNEL = 334,
    LEAF_MASK = 335,
    LINKS_DELAY = 336,
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
    MIN_IDLE = 353,
    MIN_NONWILDCARD = 354,
    MIN_NONWILDCARD_SIMPLE = 355,
    MODULE = 356,
    MODULES = 357,
    MOTD = 358,
    NAME = 359,
    NEED_IDENT = 360,
    NEED_PASSWORD = 361,
    NETWORK_DESC = 362,
    NETWORK_NAME = 363,
    NICK = 364,
    NO_CREATE_ON_SPLIT = 365,
    NO_JOIN_ON_SPLIT = 366,
    NO_OPER_FLOOD = 367,
    NO_TILDE = 368,
    NUMBER = 369,
    NUMBER_PER_CIDR = 370,
    NUMBER_PER_IP = 371,
    OPER_ONLY_UMODES = 372,
    OPER_PASS_RESV = 373,
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
    RSA_PUBLIC_KEY_FILE = 395,
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
    T_MAX_CLIENTS = 443,
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
    XLINE = 488
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
#define CONNECT 275
#define CONNECTFREQ 276
#define CYCLE_ON_HOST_CHANGE 277
#define DEFAULT_FLOODCOUNT 278
#define DEFAULT_JOIN_FLOOD_COUNT 279
#define DEFAULT_JOIN_FLOOD_TIME 280
#define DEFAULT_MAX_CLIENTS 281
#define DEFAULT_SPLIT_SERVER_COUNT 282
#define DEFAULT_SPLIT_USER_COUNT 283
#define DENY 284
#define DESCRIPTION 285
#define DIE 286
#define DISABLE_AUTH 287
#define DISABLE_FAKE_CHANNELS 288
#define DISABLE_REMOTE_COMMANDS 289
#define DOTS_IN_IDENT 290
#define EMAIL 291
#define ENCRYPTED 292
#define EXCEED_LIMIT 293
#define EXEMPT 294
#define FAILED_OPER_NOTICE 295
#define FLATTEN_LINKS 296
#define GECOS 297
#define GENERAL 298
#define GLINE 299
#define GLINE_DURATION 300
#define GLINE_ENABLE 301
#define GLINE_EXEMPT 302
#define GLINE_MIN_CIDR 303
#define GLINE_MIN_CIDR6 304
#define GLINE_REQUEST_DURATION 305
#define GLOBAL_KILL 306
#define HAVENT_READ_CONF 307
#define HIDDEN 308
#define HIDDEN_NAME 309
#define HIDE_CHANS 310
#define HIDE_IDLE 311
#define HIDE_IDLE_FROM_OPERS 312
#define HIDE_SERVER_IPS 313
#define HIDE_SERVERS 314
#define HIDE_SERVICES 315
#define HIDE_SPOOF_IPS 316
#define HOST 317
#define HUB 318
#define HUB_MASK 319
#define IGNORE_BOGUS_TS 320
#define INVISIBLE_ON_CONNECT 321
#define INVITE_CLIENT_COUNT 322
#define INVITE_CLIENT_TIME 323
#define IP 324
#define IRCD_AUTH 325
#define IRCD_FLAGS 326
#define IRCD_SID 327
#define KILL 328
#define KILL_CHASE_TIME_LIMIT 329
#define KLINE 330
#define KLINE_EXEMPT 331
#define KNOCK_CLIENT_COUNT 332
#define KNOCK_CLIENT_TIME 333
#define KNOCK_DELAY_CHANNEL 334
#define LEAF_MASK 335
#define LINKS_DELAY 336
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
#define MIN_IDLE 353
#define MIN_NONWILDCARD 354
#define MIN_NONWILDCARD_SIMPLE 355
#define MODULE 356
#define MODULES 357
#define MOTD 358
#define NAME 359
#define NEED_IDENT 360
#define NEED_PASSWORD 361
#define NETWORK_DESC 362
#define NETWORK_NAME 363
#define NICK 364
#define NO_CREATE_ON_SPLIT 365
#define NO_JOIN_ON_SPLIT 366
#define NO_OPER_FLOOD 367
#define NO_TILDE 368
#define NUMBER 369
#define NUMBER_PER_CIDR 370
#define NUMBER_PER_IP 371
#define OPER_ONLY_UMODES 372
#define OPER_PASS_RESV 373
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
#define RSA_PUBLIC_KEY_FILE 395
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
#define T_MAX_CLIENTS 443
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
#define XLINE 488

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 152 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 701 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 718 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  240
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  297
/* YYNRULES -- Number of rules.  */
#define YYNRULES  668
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1320

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
       0,   389,   389,   390,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   420,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   431,   431,
     432,   433,   434,   435,   442,   445,   445,   446,   446,   446,
     448,   454,   461,   463,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   484,   524,   582,   611,   619,   633,   661,
     676,   691,   701,   715,   724,   752,   780,   805,   827,   849,
     858,   860,   860,   861,   862,   863,   864,   866,   875,   884,
     897,   896,   914,   914,   915,   915,   915,   917,   923,   933,
     932,   951,   951,   952,   952,   952,   952,   952,   954,   960,
     966,   972,   995,   996,   996,   998,   998,   999,  1001,  1008,
    1008,  1021,  1022,  1024,  1024,  1025,  1025,  1027,  1035,  1038,
    1044,  1043,  1049,  1049,  1050,  1054,  1058,  1062,  1066,  1070,
    1074,  1078,  1082,  1093,  1092,  1178,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1191,  1197,
    1203,  1209,  1220,  1226,  1232,  1243,  1250,  1249,  1255,  1255,
    1256,  1260,  1264,  1268,  1272,  1276,  1280,  1284,  1288,  1292,
    1296,  1300,  1304,  1308,  1312,  1316,  1320,  1324,  1328,  1332,
    1336,  1340,  1347,  1346,  1352,  1352,  1353,  1357,  1361,  1365,
    1369,  1373,  1377,  1381,  1385,  1389,  1393,  1397,  1401,  1405,
    1409,  1413,  1417,  1421,  1425,  1429,  1433,  1437,  1441,  1445,
    1456,  1455,  1517,  1517,  1518,  1519,  1520,  1521,  1522,  1523,
    1524,  1525,  1526,  1527,  1528,  1529,  1530,  1530,  1531,  1532,
    1533,  1534,  1536,  1542,  1548,  1554,  1560,  1566,  1572,  1578,
    1584,  1590,  1596,  1603,  1609,  1615,  1621,  1630,  1640,  1639,
    1645,  1645,  1646,  1650,  1661,  1660,  1667,  1666,  1671,  1671,
    1672,  1676,  1680,  1686,  1686,  1687,  1687,  1687,  1687,  1687,
    1689,  1689,  1691,  1691,  1693,  1706,  1723,  1729,  1739,  1738,
    1780,  1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,
    1789,  1791,  1797,  1803,  1809,  1821,  1820,  1826,  1826,  1827,
    1831,  1835,  1839,  1843,  1847,  1851,  1855,  1859,  1863,  1869,
    1883,  1892,  1906,  1905,  1920,  1920,  1921,  1921,  1921,  1921,
    1923,  1929,  1935,  1945,  1947,  1947,  1948,  1948,  1950,  1966,
    1965,  1990,  1990,  1991,  1991,  1991,  1991,  1993,  1999,  2019,
    2018,  2024,  2024,  2025,  2029,  2033,  2037,  2041,  2045,  2049,
    2053,  2057,  2061,  2071,  2070,  2091,  2091,  2092,  2092,  2092,
    2094,  2101,  2100,  2106,  2106,  2107,  2111,  2115,  2119,  2123,
    2127,  2131,  2135,  2139,  2143,  2153,  2152,  2224,  2224,  2225,
    2226,  2227,  2228,  2229,  2230,  2231,  2232,  2233,  2234,  2235,
    2236,  2237,  2238,  2239,  2241,  2247,  2253,  2259,  2272,  2285,
    2291,  2297,  2301,  2308,  2307,  2312,  2312,  2313,  2317,  2323,
    2334,  2340,  2346,  2352,  2368,  2367,  2393,  2393,  2394,  2394,
    2394,  2396,  2416,  2426,  2425,  2452,  2452,  2453,  2453,  2453,
    2455,  2461,  2470,  2472,  2472,  2473,  2473,  2475,  2493,  2492,
    2515,  2515,  2516,  2516,  2516,  2518,  2524,  2533,  2536,  2536,
    2537,  2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,  2546,
    2547,  2548,  2549,  2550,  2551,  2552,  2553,  2554,  2555,  2556,
    2557,  2558,  2559,  2560,  2561,  2562,  2563,  2564,  2565,  2566,
    2567,  2568,  2569,  2570,  2571,  2572,  2573,  2574,  2575,  2576,
    2577,  2578,  2579,  2580,  2581,  2582,  2583,  2584,  2585,  2588,
    2593,  2598,  2603,  2609,  2615,  2621,  2627,  2632,  2637,  2642,
    2647,  2652,  2657,  2662,  2667,  2672,  2677,  2682,  2687,  2693,
    2704,  2709,  2714,  2719,  2724,  2729,  2734,  2739,  2742,  2747,
    2750,  2755,  2760,  2765,  2770,  2775,  2780,  2785,  2790,  2795,
    2800,  2805,  2810,  2815,  2821,  2820,  2825,  2825,  2826,  2829,
    2832,  2835,  2838,  2841,  2844,  2847,  2850,  2853,  2856,  2859,
    2862,  2865,  2868,  2871,  2874,  2877,  2880,  2883,  2886,  2889,
    2895,  2894,  2899,  2899,  2900,  2903,  2906,  2909,  2912,  2915,
    2918,  2921,  2924,  2927,  2930,  2933,  2936,  2939,  2942,  2945,
    2948,  2951,  2954,  2957,  2962,  2967,  2972,  2981,  2984,  2984,
    2985,  2986,  2987,  2988,  2989,  2990,  2991,  2992,  2993,  2994,
    2995,  2996,  2997,  2998,  2999,  3001,  3006,  3011,  3016,  3021,
    3026,  3031,  3036,  3041,  3046,  3051,  3056,  3061,  3066,  3074,
    3077,  3077,  3078,  3079,  3080,  3081,  3082,  3083,  3084,  3085,
    3086,  3088,  3094,  3100,  3106,  3112,  3121,  3136,  3142
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
  "CONNECT", "CONNECTFREQ", "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_JOIN_FLOOD_COUNT", "DEFAULT_JOIN_FLOOD_TIME",
  "DEFAULT_MAX_CLIENTS", "DEFAULT_SPLIT_SERVER_COUNT",
  "DEFAULT_SPLIT_USER_COUNT", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT",
  "EMAIL", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE",
  "FLATTEN_LINKS", "GECOS", "GENERAL", "GLINE", "GLINE_DURATION",
  "GLINE_ENABLE", "GLINE_EXEMPT", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLINE_REQUEST_DURATION", "GLOBAL_KILL", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS",
  "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SERVICES", "HIDE_SPOOF_IPS",
  "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT",
  "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME", "IP", "IRCD_AUTH",
  "IRCD_FLAGS", "IRCD_SID", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE",
  "KLINE_EXEMPT", "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME",
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY", "LISTEN", "MASK",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANNELS", "MAX_GLOBAL", "MAX_IDENT",
  "MAX_IDLE", "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH",
  "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH",
  "MAX_WATCH", "MIN_IDLE", "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE",
  "MODULE", "MODULES", "MOTD", "NAME", "NEED_IDENT", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NO_CREATE_ON_SPLIT",
  "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE", "NUMBER",
  "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPER_ONLY_UMODES", "OPER_PASS_RESV",
  "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID", "PACE_WAIT",
  "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME",
  "PORT", "QSTRING", "RANDOM_IDLE", "REASON", "REDIRPORT", "REDIRSERV",
  "REHASH", "REMOTE", "REMOTEBAN", "RESV", "RESV_EXEMPT",
  "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ",
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE",
  "SQUIT", "SSL_CERTIFICATE_FILE", "SSL_CERTIFICATE_FINGERPRINT",
  "SSL_CONNECTION_REQUIRED", "SSL_DH_ELLIPTIC_CURVE", "SSL_DH_PARAM_FILE",
  "SSL_MESSAGE_DIGEST_ALGORITHM", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_M_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL", "T_BOTS",
  "T_CALLERID", "T_CCONN", "T_COMMAND", "T_CLUSTER", "T_DEAF", "T_DEBUG",
  "T_DLINE", "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS",
  "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_NONONREG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ",
  "T_REJ", "T_RESTART", "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET",
  "T_SHARED", "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL",
  "T_SSL_CIPHER_LIST", "T_TARGET", "T_UMODES", "T_UNAUTH", "T_UNDLINE",
  "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_WALLOP", "T_WALLOPS",
  "T_WEBIRC", "TBOOL", "THROTTLE_COUNT", "THROTTLE_TIME",
  "TKLINE_EXPIRE_NOTICES", "TMASKED", "TS_MAX_DELTA", "TS_WARN_DELTA",
  "TWODOTS", "TYPE", "UNKLINE", "USE_LOGGING", "USER", "VHOST", "VHOST6",
  "WARN_NO_CONNECT_BLOCK", "XLINE", "';'", "'}'", "'{'", "'='", "','",
  "':'", "$accept", "conf", "conf_item", "timespec_", "timespec",
  "sizespec_", "sizespec", "modules_entry", "modules_items",
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
  "oper_name", "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_ssl_certificate_fingerprint",
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
  "general_gline_enable", "general_gline_duration",
  "general_gline_request_duration", "general_gline_min_cidr",
  "general_gline_min_cidr6", "general_tkline_expire_notices",
  "general_kill_chase_time_limit", "general_ignore_bogus_ts",
  "general_failed_oper_notice", "general_anti_nick_flood",
  "general_max_nick_time", "general_max_nick_changes",
  "general_max_accept", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_havent_read_conf", "general_invisible_on_connect",
  "general_warn_no_connect_block", "general_stats_e_disabled",
  "general_stats_m_oper_only", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_u_oper_only",
  "general_stats_k_oper_only", "general_stats_i_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_opers_bypass_callerid", "general_pace_wait_simple",
  "general_short_motd", "general_no_oper_flood", "general_oper_pass_resv",
  "general_dots_in_ident", "general_max_targets", "general_ping_cookie",
  "general_disable_auth", "general_throttle_count",
  "general_throttle_time", "general_oper_umodes", "$@25", "umode_oitems",
  "umode_oitem", "general_oper_only_umodes", "$@26", "umode_items",
  "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_channels", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_default_join_flood_count", "channel_default_join_flood_time",
  "serverhide_entry", "serverhide_items", "serverhide_item",
  "serverhide_flatten_links", "serverhide_disable_remote_commands",
  "serverhide_hide_servers", "serverhide_hide_services",
  "serverhide_hidden_name", "serverhide_links_delay", "serverhide_hidden",
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
     485,   486,   487,   488,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -869

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-869)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -869,   629,  -869,  -199,  -224,  -219,  -869,  -869,  -869,  -214,
    -869,  -206,  -869,  -869,  -869,  -203,  -869,  -869,  -869,  -184,
    -171,  -869,  -164,  -869,  -161,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,   388,   904,  -143,  -138,  -136,     2,  -126,   364,  -109,
     -82,   -65,    75,   -59,   -57,   -45,   501,   397,   -27,   106,
      40,    22,    57,    50,    55,    58,    62,    61,  -869,  -869,
    -869,  -869,  -869,    69,    79,    80,    82,    88,    95,   101,
     102,   110,   118,   119,   121,   130,   132,   202,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,   656,   317,    19,  -869,   135,    13,  -869,
    -869,   322,  -869,   145,   146,   148,   154,   155,   164,   165,
     166,   168,   169,   171,   182,   183,   188,   191,   196,   199,
     203,   205,   207,   212,   214,   215,   217,   221,   230,   233,
    -869,   234,  -869,   235,   236,   238,   240,   243,   251,   254,
     257,   261,   263,   269,   272,   273,   274,   275,   276,   288,
     296,    18,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,   478,    15,   306,    74,   297,   303,    37,  -869,  -869,
    -869,     7,   477,   301,  -869,   304,   307,   308,   313,   314,
     315,   325,   326,    20,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,    93,   327,   329,   330,   331,   333,   334,
     335,   336,   337,   338,   339,   340,   342,   343,   349,   352,
     353,    59,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
      85,   177,   354,    33,  -869,  -869,  -869,   259,   258,  -869,
     355,    17,  -869,  -869,    56,  -869,   266,   378,   409,   209,
    -869,   429,   479,   481,   483,   385,   491,   479,   492,   479,
     479,   494,   495,   394,   395,   380,  -869,   381,   379,   383,
     384,  -869,   386,   387,   389,   401,   402,   403,   405,   406,
     410,   414,   415,   416,   417,   107,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,   391,   419,   422,   425,   426,   428,
     430,  -869,   433,   439,   442,   444,   445,   446,   447,   187,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,   450,   451,    30,  -869,
    -869,  -869,   489,   398,  -869,  -869,   452,   453,    38,  -869,
    -869,  -869,   404,   479,   552,   479,   479,   474,   580,   480,
     581,   482,   479,   485,   582,   590,   479,   591,   490,   496,
     479,   595,   598,   479,   599,   602,   605,   606,   503,   486,
     504,   487,   507,   479,   479,   508,   510,   511,  -163,  -141,
     512,   515,   516,   518,   625,   479,   522,   479,   479,   523,
     513,  -869,   519,   525,   526,  -869,   527,   528,   530,   532,
     533,   227,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,   536,   537,    68,  -869,  -869,  -869,   521,   538,
     539,  -869,   540,  -869,    25,  -869,  -869,  -869,  -869,  -869,
     632,   639,   544,  -869,   547,   545,   548,    36,  -869,  -869,
    -869,   550,   549,   551,  -869,   553,   554,   555,   556,   557,
    -869,   558,   206,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,   562,   561,   563,   564,    12,  -869,
    -869,  -869,  -869,   569,   571,   584,   670,   586,   588,   589,
     479,   574,  -869,  -869,   695,   681,   593,   683,   699,   701,
     688,   689,   690,   691,   692,   694,   696,   697,   700,   702,
     706,   594,  -869,   608,   587,  -869,    48,  -869,  -869,  -869,
    -869,   618,   610,  -869,   603,   613,   612,   616,   619,   621,
     158,  -869,  -869,  -869,  -869,  -869,   726,   626,  -869,   628,
     622,  -869,   627,    28,  -869,  -869,  -869,  -869,   634,   635,
     636,  -869,   637,   -99,   642,   646,   649,   651,   653,   660,
     661,   663,   665,   666,   667,   669,   675,  -869,  -869,   782,
     797,   479,   680,   798,   807,   810,   479,   812,   821,   479,
     809,   822,   826,   479,   827,   827,   708,  -869,  -869,   815,
     -28,   816,   728,   823,   824,   713,   828,   829,   837,   831,
     832,   833,   834,   721,  -869,   835,   836,   722,  -869,   732,
    -869,   838,   839,   735,  -869,   736,   739,   740,   741,   742,
     743,   745,   746,   750,   751,   752,   753,   754,   757,   758,
     759,   760,   761,   762,   763,   764,   765,   766,   767,   768,
     769,   770,   744,   771,   662,   772,   773,   774,   775,   776,
     777,   778,   779,   783,   784,   785,   786,   787,   788,   789,
     790,   791,   792,   793,   794,  -869,  -869,   849,   811,   795,
     887,   916,   902,   905,   906,   799,  -869,   907,   908,   804,
    -869,  -869,   910,   911,   805,   927,   813,  -869,   814,   817,
    -869,  -869,   914,   915,   818,  -869,  -869,   917,   840,   808,
     920,   921,   924,   925,   841,   819,   926,   830,  -869,  -869,
     928,   931,   932,   842,  -869,   843,   844,   845,   846,   847,
     848,   850,   851,  -869,   852,   853,   854,   855,   856,   857,
     858,   859,   860,   861,   862,   863,   864,   865,   866,   867,
     868,  -869,  -869,   933,   869,   870,  -869,   871,  -869,   174,
    -869,   934,   936,   937,   938,   873,  -869,   874,  -869,  -869,
     939,   872,   940,   876,  -869,  -869,  -869,  -869,  -869,   479,
     479,   479,   479,   479,   479,   479,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,   877,   878,   879,    -1,   880,   881,   882,   883,   884,
     885,   886,   888,   889,   890,   891,   161,   892,   893,  -869,
     894,   895,   896,   897,   898,   899,   900,    -4,   901,   903,
     909,   912,   913,   918,   919,  -869,   922,   923,  -869,  -869,
     929,   930,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
     -70,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,   -30,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,   935,   941,   531,
     942,   943,   944,   945,   946,  -869,   947,   948,  -869,   949,
     950,   -48,   960,   951,  -869,  -869,  -869,  -869,   952,   953,
    -869,   954,   956,   464,   957,   958,   959,   961,   962,   703,
     963,  -869,   964,   965,   966,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,   967,   524,  -869,  -869,   968,   969,   970,  -869,    10,
    -869,  -869,  -869,  -869,   971,   974,   975,   976,  -869,  -869,
     977,   677,   978,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,   -24,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,   827,
     827,   827,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,   -17,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,   744,
    -869,   662,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,    66,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,    71,  -869,
     989,   927,   979,  -869,  -869,  -869,  -869,  -869,   955,  -869,
    -869,   980,  -869,  -869,  -869,  -869,   981,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,    90,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,   103,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,   114,  -869,  -869,   992,  -108,   984,
     982,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,   115,  -869,  -869,
    -869,    -1,  -869,  -869,  -869,  -869,    -4,  -869,  -869,  -869,
     531,  -869,   -48,  -869,  -869,  -869,  1001,  1003,  1004,  -869,
     464,  -869,   703,  -869,   524,   983,   988,   990,   270,  -869,
    -869,   677,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,   123,  -869,  -869,  -869,   270,  -869
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   230,   395,   443,     0,
     458,     0,   298,   434,   274,     0,   100,   153,   332,     0,
       0,   373,     0,   109,     0,   349,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   619,   633,
     621,   622,   623,   624,   625,   626,   620,   627,   628,   629,
     630,   631,   632,     0,     0,     0,   456,     0,     0,   454,
     455,     0,   518,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590,     0,   564,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   469,   470,   471,   516,   517,   510,   511,   512,
     513,   514,   509,   481,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   506,   482,   483,   515,   487,   488,   489,
     490,   486,   485,   491,   499,   500,   492,   493,   494,   495,
     484,   497,   507,   508,   504,   505,   498,   496,   502,   503,
     501,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,     0,     0,     0,   660,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   651,   652,   653,   654,   655,   658,
     656,   657,   659,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    69,    66,    64,    70,    71,    65,    55,
      68,    58,    59,    60,    56,    67,    61,    62,    63,    57,
       0,     0,     0,     0,   124,   125,   126,     0,     0,   347,
       0,     0,   345,   346,     0,    96,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   618,     0,     0,     0,
       0,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,   234,   237,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   235,   236,
     238,   248,   249,   250,     0,     0,     0,     0,     0,     0,
       0,   423,     0,     0,     0,     0,     0,     0,     0,     0,
     398,   399,   400,   401,   402,   403,   404,   406,   405,   408,
     412,   409,   410,   411,   407,   449,     0,     0,     0,   446,
     447,   448,     0,     0,   453,   464,     0,     0,     0,   461,
     462,   463,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   468,     0,     0,     0,   315,     0,     0,     0,     0,
       0,     0,   301,   302,   303,   304,   309,   305,   306,   307,
     308,   440,     0,     0,     0,   437,   438,   439,     0,     0,
       0,   276,     0,   286,     0,   284,   285,   287,   288,    49,
       0,     0,     0,    45,     0,     0,     0,     0,   103,   104,
     105,     0,     0,     0,   202,     0,     0,     0,     0,     0,
     176,     0,     0,   156,   157,   158,   159,   162,   163,   164,
     165,   161,   160,   166,     0,     0,     0,     0,     0,   335,
     336,   337,   338,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   650,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,     0,   381,     0,   376,   377,   378,
     127,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   112,   113,   115,   114,   116,     0,     0,   344,     0,
       0,   359,     0,     0,   352,   353,   354,   355,     0,     0,
       0,    90,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   617,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   232,   413,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   397,     0,     0,     0,   445,     0,
     452,     0,     0,     0,   460,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   467,   310,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   300,     0,     0,     0,
     436,   289,     0,     0,     0,     0,     0,   283,     0,     0,
      44,   106,     0,     0,     0,   102,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,   339,
       0,     0,     0,     0,   334,     0,     0,     0,     0,     0,
       0,     0,     0,   649,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,   379,     0,     0,     0,   375,     0,   122,     0,
     117,     0,     0,     0,     0,     0,   111,     0,   343,   356,
       0,     0,     0,     0,   351,    99,    98,    97,   647,    28,
      28,    28,    28,    28,    28,    28,    30,    29,   648,   644,
     643,   635,   636,   637,   638,   639,   640,   642,   641,   645,
     646,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   396,     0,     0,   444,   457,
       0,     0,   459,   532,   536,   519,   520,   552,   522,   616,
     561,   558,   531,   524,   523,   526,   527,   525,   539,   530,
     540,   529,   535,   534,   533,   559,   521,   614,   615,   556,
     600,   594,   610,   595,   596,   597,   605,   613,   598,   607,
     611,   601,   612,   602,   606,   599,   609,   604,   603,   608,
       0,   593,   557,   573,   574,   575,   568,   586,   569,   570,
     571,   581,   589,   572,   583,   587,   577,   588,   578,   582,
     576,   585,   580,   579,   584,     0,   567,   553,   551,   554,
     560,   555,   542,   549,   550,   547,   548,   543,   544,   545,
     546,   562,   563,   528,   538,   537,   541,     0,     0,     0,
       0,     0,     0,     0,     0,   299,     0,     0,   435,     0,
       0,     0,   294,   290,   293,   275,    50,    51,     0,     0,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,     0,     0,     0,   333,   662,   661,   667,   665,
     668,   663,   664,   666,    86,    81,    89,    80,    87,    88,
      79,    83,    82,    74,    73,    78,    75,    77,    76,    84,
      85,     0,     0,   374,   128,     0,     0,     0,   140,     0,
     132,   133,   135,   134,     0,     0,     0,     0,   110,   348,
       0,     0,     0,   350,    31,    32,    33,    34,    35,    36,
      37,   263,   264,   255,   273,   272,     0,   271,   256,   258,
     260,   267,   259,   257,   266,   252,   265,   254,   253,    38,
      38,    38,    40,    39,   261,   262,   418,   421,   422,   432,
     429,   415,   430,   427,   428,     0,   426,   431,   414,   420,
     417,   419,   433,   416,   450,   451,   465,   466,   591,     0,
     565,     0,   313,   314,   323,   320,   325,   321,   322,   328,
     324,   326,   319,   327,     0,   318,   312,   331,   330,   329,
     311,   442,   441,   297,   296,   281,   282,   280,     0,   279,
       0,     0,     0,   107,   108,   175,   171,   222,   209,   219,
     218,   207,   212,   228,   221,   226,   211,   214,   223,   225,
     229,   220,   227,   215,   217,   224,   213,   216,     0,   205,
     168,   170,   172,   173,   174,   185,   186,   187,   180,   198,
     181,   182,   183,   193,   201,   184,   195,   199,   189,   200,
     190,   194,   188,   197,   192,   191,   196,     0,   179,   169,
     342,   340,   341,   380,   385,   391,   394,   387,   393,   388,
     392,   390,   386,   389,     0,   384,   136,     0,     0,     0,
       0,   131,   119,   118,   120,   121,   357,   363,   369,   372,
     365,   371,   366,   370,   368,   364,   367,     0,   362,   358,
     269,     0,    41,    42,    43,   424,     0,   592,   566,   316,
       0,   277,     0,   295,   292,   291,     0,     0,     0,   203,
       0,   177,     0,   382,     0,     0,     0,     0,     0,   130,
     360,     0,   270,   425,   317,   278,   208,   206,   210,   204,
     178,   383,   137,   139,   138,   146,   151,   150,   145,   148,
     152,   149,   144,   147,     0,   143,   361,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -869,  -869,  -869,  -312,  -310,  -868,  -644,  -869,  -869,   987,
    -869,  -869,  -869,  -869,   800,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,   993,  -869,  -869,  -869,  -869,  -869,
    -869,   565,  -869,  -869,  -869,  -869,  -869,   484,  -869,  -869,
    -869,  -869,  -869,  -869,   780,  -869,  -869,  -869,  -869,    16,
    -869,  -869,  -869,  -869,  -869,  -235,  -869,  -869,  -869,   620,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -142,  -869,  -869,  -869,  -139,  -869,  -869,  -869,   803,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -117,
    -869,  -869,  -869,  -869,  -869,  -127,  -869,   655,  -869,  -869,
    -869,   -11,  -869,  -869,  -869,  -869,  -869,   684,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -119,  -869,  -869,  -869,  -869,
    -869,  -869,   623,  -869,  -869,  -869,  -869,  -869,   972,  -869,
    -869,  -869,  -869,   559,  -869,  -869,  -869,  -869,  -869,  -137,
    -869,  -869,  -869,   583,  -869,  -869,  -869,  -869,  -124,  -869,
    -869,  -869,   825,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -101,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,   674,  -869,  -869,  -869,  -869,  -869,   820,
    -869,  -869,  -869,  -869,  1048,  -869,  -869,  -869,  -869,   875,
    -869,  -869,  -869,  -869,   996,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,    39,  -869,  -869,  -869,    42,  -869,  -869,  -869,  -869,
    -869,  1071,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,   985,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   836,   837,  1102,  1103,    27,   227,   228,
     229,   230,    28,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,    29,    77,    78,    79,    80,    81,    30,    63,
     507,   508,   509,   510,    31,    70,   590,   591,   592,   593,
     594,   595,    32,   293,   294,   295,   296,   297,  1059,  1060,
    1061,  1062,  1063,  1239,  1314,  1315,    33,    64,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   765,
    1217,  1218,   533,   759,  1188,  1189,    34,    53,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   632,  1086,  1087,
      35,    61,   493,   744,  1158,  1159,   494,   495,   496,  1162,
    1003,  1004,   497,   498,    36,    59,   471,   472,   473,   474,
     475,   476,   477,   729,  1144,  1145,   478,   479,   480,    37,
      65,   538,   539,   540,   541,   542,    38,   301,   302,   303,
      39,    72,   603,   604,   605,   606,   607,   821,  1257,  1258,
      40,    68,   576,   577,   578,   579,   804,  1234,  1235,    41,
      54,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   655,  1115,  1116,   390,   391,   392,   393,   394,
      42,    60,   484,   485,   486,   487,    43,    55,   398,   399,
     400,   401,    44,   118,   119,   120,    45,    57,   408,   409,
     410,   411,    46,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   441,
     965,   966,   217,   439,   940,   941,   218,   219,   220,    47,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    48,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     867,   868,   614,   116,  1113,  1155,   866,   619,   504,   621,
     622,  1055,    51,   534,   116,   613,   481,    52,   299,   122,
     395,   234,    56,   299,   123,   124,   488,   125,   126,   599,
      58,   395,   127,    62,   291,    49,    50,   504,   224,   405,
     128,   129,   829,   830,   831,   832,   833,   834,   835,   573,
     130,   535,    66,   131,   235,   711,  1084,   599,   132,   712,
     253,   236,    73,   133,   134,    67,   135,   136,   137,   481,
     138,   117,    69,   237,   238,    71,   224,   713,   239,   240,
     241,   714,   117,   139,   140,   254,   573,   489,   396,   255,
     505,    74,   141,   113,   490,   536,   491,    75,   114,   396,
     115,   242,   142,   676,  1286,   678,   679,   291,   327,   143,
     121,   144,   685,   145,  1056,   146,   689,   147,   148,   505,
     693,   300,   256,   696,   328,   329,   300,   221,   330,  1085,
     149,   257,   600,   706,   707,   150,   151,   152,   225,   153,
     154,   155,   406,   537,   156,   720,   482,   722,   723,  1156,
     397,   258,   574,   492,   222,   259,   871,   872,  1157,   585,
     600,   397,   226,   260,  1128,    76,   261,   262,  1129,   407,
     157,   223,  1099,  1100,  1101,  1055,   225,   231,   331,   232,
     158,   159,   160,   161,   162,   163,   164,   506,   364,   574,
     365,   233,   366,   332,   333,   334,   335,   336,   263,   482,
     226,   337,  1114,    82,  1130,   338,   367,   511,  1131,   290,
    1260,   339,  1057,  -129,  1261,   264,   506,  1265,   265,   266,
     267,  1266,   340,   341,   368,   512,    83,    84,   462,    85,
      86,  1262,  1263,  1264,   342,    87,  1058,   165,   166,   167,
     782,   168,   169,   513,   483,  1240,   463,   773,   403,   369,
     170,   370,   597,   460,   601,   551,   343,   602,   371,   585,
     746,   292,   586,   823,   464,   667,   268,   372,   582,    88,
      89,   754,   502,   673,   575,   866,   298,   514,  1056,    90,
      91,    92,   601,   805,   305,   602,  -129,    93,    94,   269,
     270,   373,   306,   304,   571,   307,   309,   483,   465,   308,
    1269,   344,   534,   739,  1270,  1271,   311,   488,   499,  1272,
     515,   575,    95,    96,  1305,   374,   312,   313,   364,   314,
     365,   853,   366,   405,  1279,   315,   858,   553,  1280,   861,
     516,   587,   316,   865,   292,   375,   367,  1281,   317,   318,
     535,  1282,   646,  1306,   376,  1307,   517,   319,  1283,  1290,
     588,   466,  1284,  1291,   368,   320,   321,  1317,   322,   467,
     468,  1318,   586,   518,   519,   122,   589,   323,   489,   324,
     123,   124,   402,   125,   126,   490,  1057,   491,   127,   369,
     469,   370,   412,   413,   536,   414,   128,   129,   371,    73,
    1308,   415,   416,   815,   377,   608,   130,   372,   253,   131,
    1058,   417,   418,   419,   132,   420,   421,  1309,   422,   133,
     134,   580,   135,   136,   137,   520,   138,   378,    74,   423,
     424,   373,   663,   254,    75,   425,   406,   255,   426,   139,
     140,   587,   537,   427,   492,   521,   428,   325,   141,   584,
     429,   767,   430,   611,   431,   374,  1310,  1311,   142,   432,
     588,   433,   434,   407,   435,   143,   470,   144,   436,   145,
     256,   146,   735,   147,   148,   375,   589,   437,  1167,   257,
     438,   440,   442,   443,   376,   444,   149,   445,   511,   462,
     446,   150,   151,   152,  1168,   153,   154,   155,   447,   258,
     156,   448,    76,   259,   449,  1169,   512,   463,   450,  1312,
     451,   260,   234,  1313,   261,   262,   452,   609,  1170,   453,
     454,   455,   456,   457,   513,   464,   157,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,   377,   458,   158,   159,   160,   161,
     162,   163,   164,   459,   500,   235,   263,  1171,   610,  1172,
     501,   543,   236,   612,   544,   545,  1134,   378,   514,   465,
     546,   547,   548,   264,   237,   238,   265,   266,   267,   239,
     240,   241,   549,   550,   554,  1173,   555,   556,   557,  1135,
     558,   559,   560,   561,   562,   563,   564,   565,  1136,   566,
     567,   515,   242,   165,   166,   167,   568,   168,   169,   569,
     570,   581,   596,   613,  1287,   615,   170,   616,  1174,  1224,
    1175,   516,   466,   617,   268,   618,   620,  1137,   623,   624,
     467,   468,   625,   626,   627,   628,   629,   517,   669,  1176,
     630,   631,   675,   633,   634,   648,   635,   269,   270,     2,
       3,   469,   670,     4,   518,   519,  1138,  1139,   636,   637,
     638,  1177,   639,   640,  1140,     5,  1178,   641,     6,     7,
    1179,   642,   643,   644,   645,  1180,   649,   327,     8,   650,
    1181,  1225,   651,   652,  1182,   653,   677,   654,     9,  1141,
     656,    10,    11,   328,   329,  1183,   657,   330,  1184,   658,
    1185,   659,   660,   661,   662,  1142,   520,   665,   666,   671,
     672,  1186,   680,  1226,   681,   683,   687,  1187,   682,    12,
     684,  1227,    13,   686,   688,   690,   521,   470,   691,   694,
    1228,    14,   695,   697,   692,   943,   698,   944,   945,   699,
     700,   701,   703,   702,   704,   705,   708,   331,   709,   710,
     715,    15,    16,   716,   717,  1229,   718,  1230,  1231,   719,
     721,   724,   332,   333,   334,   335,   336,   725,  1143,    17,
     337,  1232,  1247,   726,   338,   741,  1195,  1233,  1196,  1197,
     339,   748,   727,   728,   730,   731,    18,   732,   749,   733,
     734,   340,   341,   737,   738,   742,   743,   745,   750,    19,
      20,   751,   752,   342,   756,   753,   757,   775,   758,   776,
     760,   761,   762,   763,   764,   766,   769,   920,   770,   778,
     771,   772,   777,    21,   779,   343,   780,   781,   783,   784,
     785,   786,   787,   788,  1248,   789,    22,   790,   791,   792,
     793,   794,    23,   795,   803,   796,   797,    24,   801,   798,
      25,   799,   946,   947,   948,   800,   807,   949,   950,   809,
     951,   952,   802,   953,   808,   954,  1249,   810,   955,   811,
     344,   956,   957,   812,  1250,   817,   813,   958,   814,   820,
     818,   959,   819,  1251,   822,   960,   961,   962,   825,   826,
     827,   828,   963,  1198,  1199,  1200,   838,   964,  1201,  1202,
     839,  1203,  1204,   840,  1205,   841,  1206,   842,  1252,  1207,
    1253,  1254,  1208,  1209,   843,   844,   851,   845,  1210,   846,
     847,   848,  1211,   849,  1255,    82,  1212,  1213,  1214,   850,
    1256,   852,   855,  1215,   921,   922,   923,   854,  1216,   924,
     925,   856,   926,   927,   857,   928,   859,   929,    83,    84,
     930,    85,    86,   931,   932,   860,   863,    87,   862,   933,
     864,   866,   869,   934,   870,   873,   874,   935,   936,   937,
     877,   880,   875,   876,   938,   885,   888,   878,   879,   939,
     881,   882,   883,   884,   886,   887,   889,   890,   891,   892,
     893,    88,    89,   894,   895,   896,   897,   898,   987,   899,
     900,    90,    91,    92,   901,   902,   903,   904,   905,    93,
      94,   906,   907,   908,   909,   910,   911,   912,   913,   914,
     915,   916,   917,   918,   919,   942,   967,   968,   969,   970,
     971,   972,   973,   974,    95,    96,   990,   975,   976,   977,
     978,   979,   980,   981,   982,   983,   984,   985,   986,   988,
     991,   992,   989,   995,   993,   994,   996,   997,   998,   999,
    1000,  1002,  1001,  1008,  1009,  1013,  1011,  1005,  1006,  1014,
    1015,  1007,  1010,  1016,  1017,  1020,  1019,  1022,  1012,  1018,
    1023,  1024,  1051,  1064,  1021,  1065,  1066,  1067,  1070,  1072,
     310,   572,   755,   583,   816,  1241,  1025,  1026,  1027,  1028,
    1029,  1030,  1031,  1319,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,
    1048,  1049,  1050,  1273,  1053,  1054,  1052,  1068,  1069,  1071,
    1073,  1081,  1082,  1083,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1285,  1095,  1096,  1097,  1098,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1117,  1296,  1118,  1297,  1298,
    1300,  1299,   768,  1119,  1292,  1295,  1120,  1121,   647,   747,
    1274,  1294,  1122,  1123,  1316,   736,  1124,  1125,   740,   806,
    1301,   774,   824,  1126,  1127,  1293,   404,   461,   326,  1132,
    1268,  1267,     0,     0,     0,  1133,  1146,  1147,  1148,  1149,
    1150,  1151,  1152,  1153,  1154,  1160,  1163,  1164,  1165,  1161,
    1166,  1190,  1191,  1192,  1276,  1193,  1194,  1219,  1220,  1221,
    1222,  1223,  1236,     0,   664,  1242,  1237,  1238,  1243,  1244,
    1245,  1246,  1259,  1275,   503,     0,  1289,  1302,   668,  1277,
    1278,  1288,  1303,     0,  1304,     0,     0,     0,   552,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   674
};

static const yytype_int16 yycheck[] =
{
     644,   645,   312,     1,     8,    53,   114,   317,     1,   319,
     320,     1,   236,     1,     1,   114,     1,   236,     1,     1,
       1,     1,   236,     1,     6,     7,     1,     9,    10,     1,
     236,     1,    14,   236,     1,   234,   235,     1,     1,     1,
      22,    23,   141,   142,   143,   144,   145,   146,   147,     1,
      32,    39,   236,    35,    34,   218,    57,     1,    40,   222,
       1,    41,     1,    45,    46,   236,    48,    49,    50,     1,
      52,    69,   236,    53,    54,   236,     1,   218,    58,    59,
      60,   222,    69,    65,    66,    26,     1,    62,    69,    30,
      83,    30,    74,   236,    69,    83,    71,    36,   236,    69,
     236,    81,    84,   413,   212,   415,   416,     1,     1,    91,
     236,    93,   422,    95,   104,    97,   426,    99,   100,    83,
     430,   104,    63,   433,    17,    18,   104,   236,    21,   130,
     112,    72,   104,   443,   444,   117,   118,   119,   101,   121,
     122,   123,   104,   131,   126,   455,   131,   457,   458,   197,
     131,    92,   104,   128,   236,    96,   184,   185,   206,     1,
     104,   131,   125,   104,   234,   104,   107,   108,   238,   131,
     152,   236,    11,    12,    13,     1,   101,   236,    71,   236,
     162,   163,   164,   165,   166,   167,   168,   180,     1,   104,
       3,   236,     5,    86,    87,    88,    89,    90,   139,   131,
     125,    94,   206,     1,   234,    98,    19,     1,   238,   236,
     234,   104,   202,   180,   238,   156,   180,   234,   159,   160,
     161,   238,   115,   116,    37,    19,    24,    25,     1,    27,
      28,  1099,  1100,  1101,   127,    33,   226,   219,   220,   221,
     550,   223,   224,    37,   229,   235,    19,   235,   235,    62,
     232,    64,   235,   235,   226,   235,   149,   229,    71,     1,
     235,   228,   104,   235,    37,   235,   207,    80,   235,    67,
      68,   235,   235,   235,   226,   114,   236,    71,   104,    77,
      78,    79,   226,   235,   234,   229,   180,    85,    86,   230,
     231,   104,   237,   236,   235,   237,   235,   229,    71,   237,
     234,   194,     1,   235,   238,   234,   237,     1,   234,   238,
     104,   226,   110,   111,    44,   128,   237,   237,     1,   237,
       3,   631,     5,     1,   234,   237,   636,   234,   238,   639,
     124,   173,   237,   643,   228,   148,    19,   234,   237,   237,
      39,   238,   235,    73,   157,    75,   140,   237,   234,   234,
     192,   124,   238,   238,    37,   237,   237,   234,   237,   132,
     133,   238,   104,   157,   158,     1,   208,   237,    62,   237,
       6,     7,   237,     9,    10,    69,   202,    71,    14,    62,
     153,    64,   237,   237,    83,   237,    22,    23,    71,     1,
     120,   237,   237,   235,   207,   129,    32,    80,     1,    35,
     226,   237,   237,   237,    40,   237,   237,   137,   237,    45,
      46,   234,    48,    49,    50,   209,    52,   230,    30,   237,
     237,   104,   235,    26,    36,   237,   104,    30,   237,    65,
      66,   173,   131,   237,   128,   229,   237,   235,    74,   180,
     237,   235,   237,   234,   237,   128,   176,   177,    84,   237,
     192,   237,   237,   131,   237,    91,   229,    93,   237,    95,
      63,    97,   235,    99,   100,   148,   208,   237,     4,    72,
     237,   237,   237,   237,   157,   237,   112,   237,     1,     1,
     237,   117,   118,   119,    20,   121,   122,   123,   237,    92,
     126,   237,   104,    96,   237,    31,    19,    19,   237,   229,
     237,   104,     1,   233,   107,   108,   237,   129,    44,   237,
     237,   237,   237,   237,    37,    37,   152,   829,   830,   831,
     832,   833,   834,   835,   207,   237,   162,   163,   164,   165,
     166,   167,   168,   237,   237,    34,   139,    73,   129,    75,
     237,   237,    41,   114,   237,   237,    15,   230,    71,    71,
     237,   237,   237,   156,    53,    54,   159,   160,   161,    58,
      59,    60,   237,   237,   237,   101,   237,   237,   237,    38,
     237,   237,   237,   237,   237,   237,   237,   237,    47,   237,
     237,   104,    81,   219,   220,   221,   237,   223,   224,   237,
     237,   237,   237,   114,  1238,   114,   232,   114,   134,    75,
     136,   124,   124,   218,   207,   114,   114,    76,   114,   114,
     132,   133,   218,   218,   234,   234,   237,   140,   129,   155,
     237,   237,   218,   237,   237,   234,   237,   230,   231,     0,
       1,   153,   234,     4,   157,   158,   105,   106,   237,   237,
     237,   177,   237,   237,   113,    16,   182,   237,    19,    20,
     186,   237,   237,   237,   237,   191,   237,     1,    29,   237,
     196,   137,   237,   237,   200,   237,   114,   237,    39,   138,
     237,    42,    43,    17,    18,   211,   237,    21,   214,   237,
     216,   237,   237,   237,   237,   154,   209,   237,   237,   237,
     237,   227,   218,   169,   114,   114,   114,   233,   218,    70,
     218,   177,    73,   218,   114,   114,   229,   229,   218,   114,
     186,    82,   114,   114,   218,    53,   114,    55,    56,   114,
     114,   218,   218,   237,   237,   218,   218,    71,   218,   218,
     218,   102,   103,   218,   218,   211,   218,   213,   214,   114,
     218,   218,    86,    87,    88,    89,    90,   234,   217,   120,
      94,   227,    75,   234,    98,   234,    53,   233,    55,    56,
     104,   129,   237,   237,   237,   237,   137,   237,   129,   237,
     237,   115,   116,   237,   237,   237,   237,   237,   234,   150,
     151,   234,   237,   127,   234,   237,   237,   218,   237,   218,
     237,   237,   237,   237,   237,   237,   234,    53,   237,   129,
     237,   237,   218,   174,   218,   149,   218,   218,   234,   114,
     129,   218,   129,   114,   137,   114,   187,   129,   129,   129,
     129,   129,   193,   129,   237,   129,   129,   198,   234,   129,
     201,   129,   170,   171,   172,   129,   218,   175,   176,   236,
     178,   179,   234,   181,   234,   183,   169,   234,   186,   237,
     194,   189,   190,   237,   177,   129,   237,   195,   237,   237,
     234,   199,   234,   186,   237,   203,   204,   205,   234,   234,
     234,   234,   210,   170,   171,   172,   234,   215,   175,   176,
     234,   178,   179,   234,   181,   234,   183,   234,   211,   186,
     213,   214,   189,   190,   234,   234,   114,   234,   195,   234,
     234,   234,   199,   234,   227,     1,   203,   204,   205,   234,
     233,   114,   114,   210,   170,   171,   172,   237,   215,   175,
     176,   114,   178,   179,   114,   181,   114,   183,    24,    25,
     186,    27,    28,   189,   190,   114,   114,    33,   129,   195,
     114,   114,   234,   199,   129,   129,   218,   203,   204,   205,
     237,   114,   129,   129,   210,   234,   234,   129,   129,   215,
     129,   129,   129,   129,   129,   129,   234,   129,   129,   234,
     234,    67,    68,   234,   234,   234,   234,   234,   129,   234,
     234,    77,    78,    79,   234,   234,   234,   234,   234,    85,
      86,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   110,   111,   129,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   218,
     114,   129,   237,   234,   129,   129,   129,   129,   234,   129,
     129,   114,   237,   129,   129,   237,   129,   234,   234,   129,
     129,   234,   234,   129,   129,   129,   237,   129,   218,   218,
     129,   129,   129,   129,   234,   129,   129,   129,   129,   129,
      77,   271,   507,   293,   590,  1059,   234,   234,   234,   234,
     234,   234,   234,  1318,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   114,   234,   234,   237,   234,   234,   237,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   129,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   135,   234,   135,   135,
    1282,  1280,   522,   234,  1261,  1272,   234,   234,   345,   494,
    1161,  1270,   234,   234,  1291,   471,   234,   234,   484,   576,
    1284,   538,   603,   234,   234,  1266,   118,   171,    97,   234,
    1131,  1129,    -1,    -1,    -1,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   225,   234,   234,   234,   238,
     234,   234,   234,   234,   239,   234,   234,   234,   234,   234,
     234,   234,   234,    -1,   379,   234,   237,   237,   234,   234,
     234,   234,   234,   234,   227,    -1,   234,   234,   398,   239,
     239,   237,   234,    -1,   234,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   408
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   241,     0,     1,     4,    16,    19,    20,    29,    39,
      42,    43,    70,    73,    82,   102,   103,   120,   137,   150,
     151,   174,   187,   193,   198,   201,   242,   247,   252,   272,
     278,   284,   292,   306,   326,   350,   364,   379,   386,   390,
     400,   409,   430,   436,   442,   446,   452,   509,   526,   234,
     235,   236,   236,   327,   410,   437,   236,   447,   236,   365,
     431,   351,   236,   279,   307,   380,   236,   236,   401,   236,
     285,   236,   391,     1,    30,    36,   104,   273,   274,   275,
     276,   277,     1,    24,    25,    27,    28,    33,    67,    68,
      77,    78,    79,    85,    86,   110,   111,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   236,   236,   236,     1,    69,   443,   444,
     445,   236,     1,     6,     7,     9,    10,    14,    22,    23,
      32,    35,    40,    45,    46,    48,    49,    50,    52,    65,
      66,    74,    84,    91,    93,    95,    97,    99,   100,   112,
     117,   118,   119,   121,   122,   123,   126,   152,   162,   163,
     164,   165,   166,   167,   168,   219,   220,   221,   223,   224,
     232,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   502,   506,   507,
     508,   236,   236,   236,     1,   101,   125,   248,   249,   250,
     251,   236,   236,   236,     1,    34,    41,    53,    54,    58,
      59,    60,    81,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,     1,    26,    30,    63,    72,    92,    96,
     104,   107,   108,   139,   156,   159,   160,   161,   207,   230,
     231,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     236,     1,   228,   293,   294,   295,   296,   297,   236,     1,
     104,   387,   388,   389,   236,   234,   237,   237,   237,   235,
     274,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   235,   511,     1,    17,    18,
      21,    71,    86,    87,    88,    89,    90,    94,    98,   104,
     115,   116,   127,   149,   194,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,     1,     3,     5,    19,    37,    62,
      64,    71,    80,   104,   128,   148,   157,   207,   230,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     425,   426,   427,   428,   429,     1,    69,   131,   438,   439,
     440,   441,   237,   235,   444,     1,   104,   131,   448,   449,
     450,   451,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   503,
     237,   499,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     235,   454,     1,    19,    37,    71,   124,   132,   133,   153,
     229,   366,   367,   368,   369,   370,   371,   372,   376,   377,
     378,     1,   131,   229,   432,   433,   434,   435,     1,    62,
      69,    71,   128,   352,   356,   357,   358,   362,   363,   234,
     237,   237,   235,   249,     1,    83,   180,   280,   281,   282,
     283,     1,    19,    37,    71,   104,   124,   140,   157,   158,
     209,   229,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   322,     1,    39,    83,   131,   381,   382,
     383,   384,   385,   237,   237,   237,   237,   237,   237,   237,
     237,   235,   528,   234,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   235,   254,     1,   104,   226,   402,   403,   404,   405,
     234,   237,   235,   294,   180,     1,   104,   173,   192,   208,
     286,   287,   288,   289,   290,   291,   237,   235,   388,     1,
     104,   226,   229,   392,   393,   394,   395,   396,   129,   129,
     129,   234,   114,   114,   244,   114,   114,   218,   114,   244,
     114,   244,   244,   114,   114,   218,   218,   234,   234,   237,
     237,   237,   347,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   235,   329,   234,   237,
     237,   237,   237,   237,   237,   422,   237,   237,   237,   237,
     237,   237,   237,   235,   412,   237,   237,   235,   439,   129,
     234,   237,   237,   235,   449,   218,   244,   114,   244,   244,
     218,   114,   218,   114,   218,   244,   218,   114,   114,   244,
     114,   218,   218,   244,   114,   114,   244,   114,   114,   114,
     114,   218,   237,   218,   237,   218,   244,   244,   218,   218,
     218,   218,   222,   218,   222,   218,   218,   218,   218,   114,
     244,   218,   244,   244,   218,   234,   234,   237,   237,   373,
     237,   237,   237,   237,   237,   235,   367,   237,   237,   235,
     433,   234,   237,   237,   353,   237,   235,   357,   129,   129,
     234,   234,   237,   237,   235,   281,   234,   237,   237,   323,
     237,   237,   237,   237,   237,   319,   237,   235,   309,   234,
     237,   237,   237,   235,   382,   218,   218,   218,   129,   218,
     218,   218,   244,   234,   114,   129,   218,   129,   114,   114,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   234,   234,   237,   406,   235,   403,   218,   234,   236,
     234,   237,   237,   237,   237,   235,   287,   129,   234,   234,
     237,   397,   237,   235,   393,   234,   234,   234,   234,   141,
     142,   143,   144,   145,   146,   147,   243,   244,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   114,   114,   244,   237,   114,   114,   114,   244,   114,
     114,   244,   129,   114,   114,   244,   114,   246,   246,   234,
     129,   184,   185,   129,   218,   129,   129,   237,   129,   129,
     114,   129,   129,   129,   129,   234,   129,   129,   234,   234,
     129,   129,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
      53,   170,   171,   172,   175,   176,   178,   179,   181,   183,
     186,   189,   190,   195,   199,   203,   204,   205,   210,   215,
     504,   505,   234,    53,    55,    56,   170,   171,   172,   175,
     176,   178,   179,   181,   183,   186,   189,   190,   195,   199,
     203,   204,   205,   210,   215,   500,   501,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   129,   218,   237,
     129,   114,   129,   129,   129,   234,   129,   129,   234,   129,
     129,   237,   114,   360,   361,   234,   234,   234,   129,   129,
     234,   129,   218,   237,   129,   129,   129,   129,   218,   237,
     129,   234,   129,   129,   129,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   129,   237,   234,   234,     1,   104,   202,   226,   298,
     299,   300,   301,   302,   129,   129,   129,   129,   234,   234,
     129,   237,   129,   234,   243,   243,   243,   243,   243,   243,
     243,   234,   234,   234,    57,   130,   348,   349,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,    11,
      12,    13,   245,   246,   234,   234,   234,   234,   234,   234,
     234,   234,   234,     8,   206,   423,   424,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   238,
     234,   238,   234,   234,    15,    38,    47,    76,   105,   106,
     113,   138,   154,   217,   374,   375,   234,   234,   234,   234,
     234,   234,   234,   234,   234,    53,   197,   206,   354,   355,
     225,   238,   359,   234,   234,   234,   234,     4,    20,    31,
      44,    73,    75,   101,   134,   136,   155,   177,   182,   186,
     191,   196,   200,   211,   214,   216,   227,   233,   324,   325,
     234,   234,   234,   234,   234,    53,    55,    56,   170,   171,
     172,   175,   176,   178,   179,   181,   183,   186,   189,   190,
     195,   199,   203,   204,   205,   210,   215,   320,   321,   234,
     234,   234,   234,   234,    75,   137,   169,   177,   186,   211,
     213,   214,   227,   233,   407,   408,   234,   237,   237,   303,
     235,   299,   234,   234,   234,   234,   234,    75,   137,   169,
     177,   186,   211,   213,   214,   227,   233,   398,   399,   234,
     234,   238,   245,   245,   245,   234,   238,   505,   501,   234,
     238,   234,   238,   114,   361,   234,   239,   239,   239,   234,
     238,   234,   238,   234,   238,   129,   212,   246,   237,   234,
     234,   238,   349,   424,   375,   355,   135,   135,   135,   325,
     321,   408,   234,   234,   234,    44,    73,    75,   120,   137,
     176,   177,   229,   233,   304,   305,   399,   234,   238,   305
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
     254,   254,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   273,   274,   274,   274,   274,   275,   276,   277,
     279,   278,   280,   280,   281,   281,   281,   282,   283,   285,
     284,   286,   286,   287,   287,   287,   287,   287,   288,   289,
     290,   291,   292,   293,   293,   294,   294,   294,   295,   297,
     296,   298,   298,   299,   299,   299,   299,   300,   301,   301,
     303,   302,   304,   304,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   307,   306,   308,   308,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   319,   318,   320,   320,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   323,   322,   324,   324,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     327,   326,   328,   328,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   347,   346,
     348,   348,   349,   349,   351,   350,   353,   352,   354,   354,
     355,   355,   355,   356,   356,   357,   357,   357,   357,   357,
     359,   358,   360,   360,   361,   361,   362,   363,   365,   364,
     366,   366,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   368,   369,   370,   371,   373,   372,   374,   374,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   376,
     377,   378,   380,   379,   381,   381,   382,   382,   382,   382,
     383,   384,   385,   386,   387,   387,   388,   388,   389,   391,
     390,   392,   392,   393,   393,   393,   393,   394,   395,   397,
     396,   398,   398,   399,   399,   399,   399,   399,   399,   399,
     399,   399,   399,   401,   400,   402,   402,   403,   403,   403,
     404,   406,   405,   407,   407,   408,   408,   408,   408,   408,
     408,   408,   408,   408,   408,   410,   409,   411,   411,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   420,   422,   421,   423,   423,   424,   424,   425,
     426,   427,   428,   429,   431,   430,   432,   432,   433,   433,
     433,   434,   435,   437,   436,   438,   438,   439,   439,   439,
     440,   441,   442,   443,   443,   444,   444,   445,   447,   446,
     448,   448,   449,   449,   449,   450,   451,   452,   453,   453,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   483,   484,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   499,   498,   500,   500,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     503,   502,   504,   504,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   506,   507,   508,   509,   510,   510,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   527,   528,   528,   528,   528,   528,   528,   528,   528,
     528,   529,   530,   531,   532,   533,   534,   535,   536
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
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4
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
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 428 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 431 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 432 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 433 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 434 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 435 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 449 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 455 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 485 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    if (!ConfigServerInfo.rsa_private_key_file)
    {
      conf_error_report("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_chain_file(ConfigServerInfo.server_ctx, yylval.string) <= 0 ||
        SSL_CTX_use_certificate_chain_file(ConfigServerInfo.client_ctx, yylval.string) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not open/read certificate file");
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ConfigServerInfo.server_ctx, ConfigServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ConfigServerInfo.client_ctx, ConfigServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }

    if (!SSL_CTX_check_private_key(ConfigServerInfo.server_ctx) ||
        !SSL_CTX_check_private_key(ConfigServerInfo.client_ctx))
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }
  }
#endif
}
#line 3016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 525 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  BIO *file = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

  if (ConfigServerInfo.rsa_private_key)
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;
  }

  if (ConfigServerInfo.rsa_private_key_file)
  {
    MyFree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = NULL;
  }

  ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);

  if ((file = BIO_new_file(yylval.string, "r")) == NULL)
  {
    conf_error_report("File open failed, ignoring");
    break;
  }

  ConfigServerInfo.rsa_private_key = PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

  BIO_set_close(file, BIO_CLOSE);
  BIO_free(file);

  if (ConfigServerInfo.rsa_private_key == NULL)
  {
    conf_error_report("Couldn't extract key, ignoring");
    break;
  }

  if (!RSA_check_key(ConfigServerInfo.rsa_private_key))
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;

    conf_error_report("Invalid key, ignoring");
    break;
  }

  if (RSA_size(ConfigServerInfo.rsa_private_key) < 128)
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;

    conf_error_report("Ignoring serverinfo::rsa_private_key_file -- need at least a 1024 bit key size");
  }
#endif
}
#line 3077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 583 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    BIO *file = BIO_new_file(yylval.string, "r");

    if (file)
    {
      DH *dh = PEM_read_bio_DHparams(file, NULL, NULL, NULL);

      BIO_free(file);

      if (dh)
      {
        if (DH_size(dh) < 128)
          conf_error_report("Ignoring serverinfo::ssl_dh_param_file -- need at least a 1024 bit DH prime size");
        else
          SSL_CTX_set_tmp_dh(ConfigServerInfo.server_ctx, dh);

        DH_free(dh);
      }
    }
    else
      conf_error_report("Ignoring serverinfo::ssl_dh_param_file -- could not open/read Diffie-Hellman parameter file");
  }
#endif
}
#line 3109 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 612 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 620 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    if ((ConfigServerInfo.message_digest_algorithm = EVP_get_digestbyname(yylval.string)) == NULL)
    {
      ConfigServerInfo.message_digest_algorithm = EVP_sha256();
      conf_error_report("Ignoring serverinfo::ssl_message_digest_algorithm -- unknown message digest algorithm");
    }
  }
#endif
}
#line 3137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 634 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
#if OPENSSL_VERSION_NUMBER >= 0x009080FFL && !defined(OPENSSL_NO_ECDH)
  int nid = 0;
  EC_KEY *key = NULL;

  if (conf_parser_ctx.pass == 2)
  {
    if ((nid = OBJ_sn2nid(yylval.string)) == 0)
    {
        conf_error_report("Ignoring serverinfo::serverinfo_ssl_dh_elliptic_curve -- unknown curve name");
        break;
    }

    if ((key = EC_KEY_new_by_curve_name(nid)) == NULL)
    {
      conf_error_report("Ignoring serverinfo::serverinfo_ssl_dh_elliptic_curve -- could not create curve");
      break;
    }

    SSL_CTX_set_tmp_ecdh(ConfigServerInfo.server_ctx, key);
    EC_KEY_free(key);
}
#endif
#endif
}
#line 3168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 662 "conf_parser.y" /* yacc.c:1646  */
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.name)
  {
    if (valid_servname(yylval.string))
      ConfigServerInfo.name = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
#line 3186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 677 "conf_parser.y" /* yacc.c:1646  */
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      ConfigServerInfo.sid = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
#line 3204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 692 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3217 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 702 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')))
      *p = '\0';

    MyFree(ConfigServerInfo.network_name);
    ConfigServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3234 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 716 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 725 "conf_parser.y" /* yacc.c:1646  */
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
#line 3277 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 753 "conf_parser.y" /* yacc.c:1646  */
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
#line 3308 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 781 "conf_parser.y" /* yacc.c:1646  */
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
#line 3336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 806 "conf_parser.y" /* yacc.c:1646  */
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
#line 3361 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 828 "conf_parser.y" /* yacc.c:1646  */
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
#line 3386 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 850 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3395 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 867 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 876 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3419 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 885 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3431 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 897 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 901 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 918 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3466 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 924 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3475 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 933 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3484 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 937 "conf_parser.y" /* yacc.c:1646  */
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
#line 3502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 955 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 961 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 967 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 973 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.nick.buf);
    nuh.hostsize = sizeof(block_state.host.buf);
    split_nuh(&nuh);

    strlcpy(block_state.nick.buf, nuh.userptr, sizeof(block_state.nick.buf));
    strlcpy(block_state.host.buf, nuh.hostptr, sizeof(block_state.host.buf));
  }
}
#line 3552 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1002 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3561 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1008 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3570 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1012 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3594 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1036 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3602 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1039 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3610 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1051 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3628 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3637 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1059 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3646 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1063 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3655 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1067 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3664 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1071 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1075 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1079 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1083 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3700 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1093 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3712 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1100 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;
#ifdef HAVE_LIBCRYPTO
  if (!block_state.file.buf[0] &&
      !block_state.rpass.buf[0])
    break;
#else
  if (!block_state.rpass.buf[0])
    break;
#endif

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

    conf->flags = block_state.flags.value;
    conf->modes = block_state.modes.value;
    conf->port  = block_state.port.value;
    conf->htype = parse_netmask(conf->host, &conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);

#ifdef HAVE_LIBCRYPTO
    if (block_state.file.buf[0])
    {
      BIO *file = NULL;
      RSA *pkey = NULL;

      if ((file = BIO_new_file(block_state.file.buf, "r")) == NULL)
      {
        ilog(LOG_TYPE_IRCD, "Ignoring rsa_public_key_file -- file doesn't exist");
        break;
      }

      if ((pkey = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL)) == NULL)
        ilog(LOG_TYPE_IRCD, "Ignoring rsa_public_key_file -- key invalid; check key syntax");
      else
      {
        if (RSA_size(pkey) > 128)
          ilog(LOG_TYPE_IRCD, "Ignoring rsa_public_key_file -- key size must be 1024 or below");
        else
          conf->rsa_public_key = pkey;
      }

      BIO_set_close(file, BIO_CLOSE);
      BIO_free(file);
    }
#endif /* HAVE_LIBCRYPTO */
  }
}
#line 3794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3803 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1198 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3812 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3821 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1210 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3835 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3844 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1227 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3853 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1250 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1257 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1261 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4011 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4020 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4065 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1347 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1354 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1358 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1362 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1366 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1370 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1374 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1378 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4155 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1382 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1386 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1390 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1394 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1398 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1402 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1406 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1410 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4227 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1414 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1418 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1422 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1426 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1430 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1434 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4281 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1438 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4290 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1442 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4299 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4308 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1456 "conf_parser.y" /* yacc.c:1646  */
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
#line 4325 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1468 "conf_parser.y" /* yacc.c:1646  */
    {
  struct ClassItem *class = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.class.buf[0])
    break;

  if (!(class = class_find(block_state.class.buf, 0)))
    class = class_make();

  class->active = 1;
  MyFree(class->name);
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

  if (class->number_per_cidr && block_state.number_per_cidr.value)
    if ((class->cidr_bitlen_ipv4 && block_state.cidr_bitlen_ipv4.value) ||
        (class->cidr_bitlen_ipv6 && block_state.cidr_bitlen_ipv6.value))
      if ((class->cidr_bitlen_ipv4 != block_state.cidr_bitlen_ipv4.value) ||
          (class->cidr_bitlen_ipv6 != block_state.cidr_bitlen_ipv6.value))
        rebuild_cidr_list(class);

  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;
}
#line 4378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1537 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1543 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1549 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1555 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1561 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1567 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1573 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1579 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1585 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1591 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1597 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1604 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1610 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1616 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1622 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1631 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1640 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4538 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1647 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1651 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4556 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1661 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1667 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1673 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1677 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4591 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1681 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4600 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1689 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1694 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_LIBCRYPTO
    if (block_state.flags.value & LISTENER_SSL)
    {
      conf_error_report("SSL not available - port closed");
      break;
    }
#endif
    add_listener((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1707 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_LIBCRYPTO
    if (block_state.flags.value & LISTENER_SSL)
    {
      conf_error_report("SSL not available - port closed");
      break;
    }
#endif

    for (int i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      add_listener(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4644 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1724 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4653 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1730 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4662 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1739 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4671 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1743 "conf_parser.y" /* yacc.c:1646  */
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
#line 4712 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1792 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1798 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4730 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1804 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4739 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1810 "conf_parser.y" /* yacc.c:1646  */
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

  case 315:
#line 1821 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1828 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4771 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1832 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4780 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1836 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4789 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1840 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4798 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1844 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4807 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1848 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1852 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1856 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4834 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1860 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4843 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1864 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1870 "conf_parser.y" /* yacc.c:1646  */
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

  case 330:
#line 1884 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1893 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1906 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4905 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1913 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1924 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1930 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1936 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1951 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1966 "conf_parser.y" /* yacc.c:1646  */
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

  case 350:
#line 1977 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_ULINE);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
  conf->user = xstrdup(block_state.user.buf);
  conf->host = xstrdup(block_state.host.buf);
}
#line 4991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1994 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 2000 "conf_parser.y" /* yacc.c:1646  */
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

  case 359:
#line 2019 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5031 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2026 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2030 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5049 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5058 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2038 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5067 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2042 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5076 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2050 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2062 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5121 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2071 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2080 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2095 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2101 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2108 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2112 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2116 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2120 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2124 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2128 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2132 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2136 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2140 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2144 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2153 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2162 "conf_parser.y" /* yacc.c:1646  */
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

  case 414:
#line 2242 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5347 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2254 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2260 "conf_parser.y" /* yacc.c:1646  */
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

  case 418:
#line 2273 "conf_parser.y" /* yacc.c:1646  */
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

  case 419:
#line 2286 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2298 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2302 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2308 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2314 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2318 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2324 "conf_parser.y" /* yacc.c:1646  */
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

  case 430:
#line 2335 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2347 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2353 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2368 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2372 "conf_parser.y" /* yacc.c:1646  */
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

  case 441:
#line 2397 "conf_parser.y" /* yacc.c:1646  */
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

  case 442:
#line 2417 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5580 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2426 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2430 "conf_parser.y" /* yacc.c:1646  */
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

  case 450:
#line 2456 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2462 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2476 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      struct MaskItem *conf = conf_make(CONF_EXEMPT);
      conf->host = xstrdup(yylval.string);

      add_conf_by_address(CONF_EXEMPT, conf);
    }
  }
}
#line 5650 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2493 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2497 "conf_parser.y" /* yacc.c:1646  */
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
#line 5681 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2519 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5690 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2525 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5699 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2589 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5707 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2594 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2599 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2604 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2610 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.glines = yylval.number;
}
#line 5741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2616 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_time = (yyvsp[-1].number);
}
#line 5750 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2622 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_request_time = (yyvsp[-1].number);
}
#line 5759 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2628 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr = (yyvsp[-1].number);
}
#line 5767 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2633 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2638 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5783 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2643 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2648 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5799 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2653 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5807 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2658 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2663 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2668 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5831 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2673 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5839 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2678 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2683 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2688 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2694 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5878 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2705 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2710 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2715 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2720 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2725 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2730 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2735 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2740 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2743 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2751 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2756 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2761 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2766 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2771 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2776 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 6006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2781 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_pass_resv = yylval.number;
}
#line 6022 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2791 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 6030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2796 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2806 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2811 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2821 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2827 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2830 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2833 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2836 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2839 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2845 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2851 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2854 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6158 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6166 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2860 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2869 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6198 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2878 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2884 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2895 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6262 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2901 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2904 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2907 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6286 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2910 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2913 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6302 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2916 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2919 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2922 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2925 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6334 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2928 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2931 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2934 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2937 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2940 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2943 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2946 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2949 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2952 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2955 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2958 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2963 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6430 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2968 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2973 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 3002 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3007 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3012 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3017 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 3022 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 3027 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3032 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3037 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6510 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3042 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6518 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 3047 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6526 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3052 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6534 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 3057 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 3062 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 3067 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3089 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3095 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3101 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6594 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3113 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 666:
#line 3122 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (((yyvsp[-1].number) > 0) && ConfigServerHide.links_disabled == 1)
    {
      event_write_links_file.when = (yyvsp[-1].number);
      event_addish(&event_write_links_file, NULL);
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = (yyvsp[-1].number);
  }
}
#line 6624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 3137 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 668:
#line 3143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6642 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6646 "conf_parser.c" /* yacc.c:1646  */
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
