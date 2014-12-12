/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

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
    DEFAULT_SPLIT_SERVER_COUNT = 279,
    DEFAULT_SPLIT_USER_COUNT = 280,
    DENY = 281,
    DESCRIPTION = 282,
    DIE = 283,
    DISABLE_AUTH = 284,
    DISABLE_FAKE_CHANNELS = 285,
    DISABLE_REMOTE_COMMANDS = 286,
    DOTS_IN_IDENT = 287,
    EGDPOOL_PATH = 288,
    EMAIL = 289,
    ENCRYPTED = 290,
    EXCEED_LIMIT = 291,
    EXEMPT = 292,
    FAILED_OPER_NOTICE = 293,
    FLATTEN_LINKS = 294,
    GECOS = 295,
    GENERAL = 296,
    GLINE = 297,
    GLINE_DURATION = 298,
    GLINE_ENABLE = 299,
    GLINE_EXEMPT = 300,
    GLINE_MIN_CIDR = 301,
    GLINE_MIN_CIDR6 = 302,
    GLINE_REQUEST_DURATION = 303,
    GLOBAL_KILL = 304,
    HAVENT_READ_CONF = 305,
    HIDDEN = 306,
    HIDDEN_NAME = 307,
    HIDE_CHANS = 308,
    HIDE_IDLE = 309,
    HIDE_IDLE_FROM_OPERS = 310,
    HIDE_SERVER_IPS = 311,
    HIDE_SERVERS = 312,
    HIDE_SERVICES = 313,
    HIDE_SPOOF_IPS = 314,
    HOST = 315,
    HUB = 316,
    HUB_MASK = 317,
    IGNORE_BOGUS_TS = 318,
    INVISIBLE_ON_CONNECT = 319,
    INVITE_CLIENT_COUNT = 320,
    INVITE_CLIENT_TIME = 321,
    IP = 322,
    IRCD_AUTH = 323,
    IRCD_FLAGS = 324,
    IRCD_SID = 325,
    JOIN_FLOOD_COUNT = 326,
    JOIN_FLOOD_TIME = 327,
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
    USE_EGD = 483,
    USE_LOGGING = 484,
    USER = 485,
    VHOST = 486,
    VHOST6 = 487,
    WARN_NO_CONNECT_BLOCK = 488,
    XLINE = 489
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
#define DEFAULT_SPLIT_SERVER_COUNT 279
#define DEFAULT_SPLIT_USER_COUNT 280
#define DENY 281
#define DESCRIPTION 282
#define DIE 283
#define DISABLE_AUTH 284
#define DISABLE_FAKE_CHANNELS 285
#define DISABLE_REMOTE_COMMANDS 286
#define DOTS_IN_IDENT 287
#define EGDPOOL_PATH 288
#define EMAIL 289
#define ENCRYPTED 290
#define EXCEED_LIMIT 291
#define EXEMPT 292
#define FAILED_OPER_NOTICE 293
#define FLATTEN_LINKS 294
#define GECOS 295
#define GENERAL 296
#define GLINE 297
#define GLINE_DURATION 298
#define GLINE_ENABLE 299
#define GLINE_EXEMPT 300
#define GLINE_MIN_CIDR 301
#define GLINE_MIN_CIDR6 302
#define GLINE_REQUEST_DURATION 303
#define GLOBAL_KILL 304
#define HAVENT_READ_CONF 305
#define HIDDEN 306
#define HIDDEN_NAME 307
#define HIDE_CHANS 308
#define HIDE_IDLE 309
#define HIDE_IDLE_FROM_OPERS 310
#define HIDE_SERVER_IPS 311
#define HIDE_SERVERS 312
#define HIDE_SERVICES 313
#define HIDE_SPOOF_IPS 314
#define HOST 315
#define HUB 316
#define HUB_MASK 317
#define IGNORE_BOGUS_TS 318
#define INVISIBLE_ON_CONNECT 319
#define INVITE_CLIENT_COUNT 320
#define INVITE_CLIENT_TIME 321
#define IP 322
#define IRCD_AUTH 323
#define IRCD_FLAGS 324
#define IRCD_SID 325
#define JOIN_FLOOD_COUNT 326
#define JOIN_FLOOD_TIME 327
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
#define USE_EGD 483
#define USE_LOGGING 484
#define USER 485
#define VHOST 486
#define VHOST6 487
#define WARN_NO_CONNECT_BLOCK 488
#define XLINE 489

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 152 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 703 "conf_parser.c" /* yacc.c:355  */
};
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
#define YYLAST   1291

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  241
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  297
/* YYNRULES -- Number of rules.  */
#define YYNRULES  668
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1320

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
       0,   390,   390,   391,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   421,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   432,   432,
     433,   434,   435,   436,   443,   446,   446,   447,   447,   447,
     449,   455,   462,   464,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   485,   525,   583,   612,   620,   634,   662,
     677,   692,   702,   716,   725,   753,   781,   806,   828,   850,
     859,   861,   861,   862,   863,   864,   865,   867,   876,   885,
     898,   897,   915,   915,   916,   916,   916,   918,   924,   934,
     933,   952,   952,   953,   953,   953,   953,   953,   955,   961,
     967,   973,   996,   997,   997,   999,   999,  1000,  1002,  1009,
    1009,  1022,  1023,  1025,  1025,  1026,  1026,  1028,  1036,  1039,
    1045,  1044,  1050,  1050,  1051,  1055,  1059,  1063,  1067,  1071,
    1075,  1079,  1083,  1094,  1093,  1179,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1192,  1198,
    1204,  1210,  1221,  1227,  1233,  1244,  1251,  1250,  1256,  1256,
    1257,  1261,  1265,  1269,  1273,  1277,  1281,  1285,  1289,  1293,
    1297,  1301,  1305,  1309,  1313,  1317,  1321,  1325,  1329,  1333,
    1337,  1341,  1348,  1347,  1353,  1353,  1354,  1358,  1362,  1366,
    1370,  1374,  1378,  1382,  1386,  1390,  1394,  1398,  1402,  1406,
    1410,  1414,  1418,  1422,  1426,  1430,  1434,  1438,  1442,  1446,
    1457,  1456,  1518,  1518,  1519,  1520,  1521,  1522,  1523,  1524,
    1525,  1526,  1527,  1528,  1529,  1530,  1531,  1531,  1532,  1533,
    1534,  1535,  1537,  1543,  1549,  1555,  1561,  1567,  1573,  1579,
    1585,  1591,  1597,  1604,  1610,  1616,  1622,  1631,  1641,  1640,
    1646,  1646,  1647,  1651,  1662,  1661,  1668,  1667,  1672,  1672,
    1673,  1677,  1681,  1687,  1687,  1688,  1688,  1688,  1688,  1688,
    1690,  1690,  1692,  1692,  1694,  1707,  1724,  1730,  1740,  1739,
    1781,  1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,
    1790,  1792,  1798,  1804,  1810,  1822,  1821,  1827,  1827,  1828,
    1832,  1836,  1840,  1844,  1848,  1852,  1856,  1860,  1864,  1870,
    1884,  1893,  1907,  1906,  1921,  1921,  1922,  1922,  1922,  1922,
    1924,  1930,  1936,  1946,  1948,  1948,  1949,  1949,  1951,  1967,
    1966,  1991,  1991,  1992,  1992,  1992,  1992,  1994,  2000,  2020,
    2019,  2025,  2025,  2026,  2030,  2034,  2038,  2042,  2046,  2050,
    2054,  2058,  2062,  2072,  2071,  2092,  2092,  2093,  2093,  2093,
    2095,  2102,  2101,  2107,  2107,  2108,  2112,  2116,  2120,  2124,
    2128,  2132,  2136,  2140,  2144,  2154,  2153,  2225,  2225,  2226,
    2227,  2228,  2229,  2230,  2231,  2232,  2233,  2234,  2235,  2236,
    2237,  2238,  2239,  2240,  2242,  2248,  2254,  2260,  2273,  2286,
    2292,  2298,  2302,  2309,  2308,  2313,  2313,  2314,  2318,  2324,
    2335,  2341,  2347,  2353,  2369,  2368,  2394,  2394,  2395,  2395,
    2395,  2397,  2417,  2427,  2426,  2453,  2453,  2454,  2454,  2454,
    2456,  2462,  2471,  2473,  2473,  2474,  2474,  2476,  2494,  2493,
    2516,  2516,  2517,  2517,  2517,  2519,  2525,  2534,  2537,  2537,
    2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,
    2548,  2549,  2550,  2551,  2552,  2553,  2554,  2555,  2556,  2557,
    2558,  2559,  2560,  2561,  2562,  2563,  2564,  2565,  2566,  2567,
    2568,  2569,  2570,  2571,  2572,  2573,  2574,  2575,  2576,  2577,
    2578,  2579,  2580,  2581,  2582,  2583,  2584,  2585,  2586,  2589,
    2594,  2599,  2604,  2610,  2616,  2622,  2628,  2633,  2638,  2643,
    2648,  2653,  2658,  2663,  2668,  2673,  2678,  2683,  2688,  2694,
    2705,  2710,  2715,  2720,  2725,  2730,  2735,  2740,  2743,  2748,
    2751,  2756,  2761,  2766,  2771,  2776,  2781,  2786,  2791,  2796,
    2801,  2806,  2811,  2816,  2822,  2821,  2826,  2826,  2827,  2830,
    2833,  2836,  2839,  2842,  2845,  2848,  2851,  2854,  2857,  2860,
    2863,  2866,  2869,  2872,  2875,  2878,  2881,  2884,  2887,  2890,
    2896,  2895,  2900,  2900,  2901,  2904,  2907,  2910,  2913,  2916,
    2919,  2922,  2925,  2928,  2931,  2934,  2937,  2940,  2943,  2946,
    2949,  2952,  2955,  2958,  2963,  2968,  2973,  2982,  2985,  2985,
    2986,  2987,  2988,  2989,  2990,  2991,  2992,  2993,  2994,  2995,
    2996,  2997,  2998,  2999,  3000,  3002,  3007,  3012,  3017,  3022,
    3027,  3032,  3037,  3042,  3047,  3052,  3057,  3062,  3067,  3075,
    3078,  3078,  3079,  3080,  3081,  3082,  3083,  3084,  3085,  3086,
    3087,  3089,  3095,  3101,  3107,  3113,  3122,  3137,  3143
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
  "DEFAULT_SPLIT_SERVER_COUNT", "DEFAULT_SPLIT_USER_COUNT", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT", "EGDPOOL_PATH", "EMAIL",
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE",
  "FLATTEN_LINKS", "GECOS", "GENERAL", "GLINE", "GLINE_DURATION",
  "GLINE_ENABLE", "GLINE_EXEMPT", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLINE_REQUEST_DURATION", "GLOBAL_KILL", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS",
  "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SERVICES", "HIDE_SPOOF_IPS",
  "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT",
  "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME", "IP", "IRCD_AUTH",
  "IRCD_FLAGS", "IRCD_SID", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KNOCK_CLIENT_COUNT",
  "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY",
  "LISTEN", "MASK", "MAX_ACCEPT", "MAX_BANS", "MAX_CHANNELS", "MAX_GLOBAL",
  "MAX_IDENT", "MAX_IDLE", "MAX_LOCAL", "MAX_NICK_CHANGES",
  "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_TOPIC_LENGTH", "MAX_WATCH", "MIN_IDLE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD", "NAME",
  "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPER_ONLY_UMODES",
  "OPER_PASS_RESV", "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID",
  "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE",
  "PING_TIME", "PORT", "QSTRING", "RANDOM_IDLE", "REASON", "REDIRPORT",
  "REDIRSERV", "REHASH", "REMOTE", "REMOTEBAN", "RESV", "RESV_EXEMPT",
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
  "TWODOTS", "TYPE", "UNKLINE", "USE_EGD", "USE_LOGGING", "USER", "VHOST",
  "VHOST6", "WARN_NO_CONNECT_BLOCK", "XLINE", "';'", "'}'", "'{'", "'='",
  "','", "':'", "$accept", "conf", "conf_item", "timespec_", "timespec",
  "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_ssl_message_digest_algorithm",
  "serverinfo_ssl_dh_elliptic_curve", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_max_nick_length",
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
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_disable_remote_commands", "serverhide_hide_servers",
  "serverhide_hide_services", "serverhide_hidden_name",
  "serverhide_links_delay", "serverhide_hidden",
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
     485,   486,   487,   488,   489,    59,   125,   123,    61,    44,
      58
};
# endif

#define YYPACT_NINF -752

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-752)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -752,   617,  -752,  -202,  -226,  -217,  -752,  -752,  -752,  -209,
    -752,  -206,  -752,  -752,  -752,  -201,  -752,  -752,  -752,  -189,
    -180,  -752,  -162,  -752,  -153,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,   304,   687,  -140,  -139,  -133,    14,  -132,   381,  -118,
    -113,  -109,   209,  -108,   -88,   -87,   731,   421,   -76,    12,
     -73,    17,   -71,  -163,  -112,   -62,   -48,    39,  -752,  -752,
    -752,  -752,  -752,   -32,   -30,   -29,   -16,    21,    28,    41,
      81,    84,    91,    98,    99,   101,   116,   230,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,   606,   507,     9,  -752,   118,    13,  -752,
    -752,    82,  -752,   120,   122,   125,   127,   128,   129,   132,
     134,   135,   136,   137,   138,   139,   141,   146,   151,   154,
     155,   156,   167,   168,   169,   171,   173,   174,   177,   180,
    -752,   183,  -752,   185,   188,   194,   195,   196,   198,   200,
     201,   205,   208,   212,   214,   215,   218,   219,   224,   225,
     229,    15,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,   515,    34,    26,   124,   233,   235,    45,  -752,  -752,
    -752,     7,   416,   231,  -752,   241,   245,   248,   249,   250,
     251,   252,   254,   117,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,   234,   256,   257,   259,   267,   268,   271,
     273,   276,   277,   281,   283,   286,   297,   298,   301,   313,
     320,    55,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
      51,   324,   323,    16,  -752,  -752,  -752,    70,   380,  -752,
     326,    54,  -752,  -752,    87,  -752,   226,   339,   436,   331,
    -752,   335,   456,   360,   469,   471,   472,   471,   476,   471,
     471,   477,   478,   375,   377,   362,  -752,   368,   370,   372,
     378,  -752,   388,   391,   392,   393,   394,   396,   400,   403,
     406,   407,   412,   413,   418,   184,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,   371,   422,   423,   424,   427,   428,
     431,  -752,   432,   433,   434,   435,   445,   448,   449,   223,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,   451,   453,    29,  -752,
    -752,  -752,   484,   439,  -752,  -752,   459,   460,    53,  -752,
    -752,  -752,   397,   471,   545,   471,   471,   483,   549,   489,
     594,   491,   471,   495,   601,   602,   471,   604,   508,   509,
     471,   611,   614,   471,   615,   616,   621,   622,   513,   501,
     522,   503,   525,   471,   471,   530,   531,   532,  -199,  -179,
     538,   539,   542,   543,   649,   471,   551,   471,   471,   553,
     540,  -752,   555,   536,   546,  -752,   548,   556,   557,   558,
     563,   211,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,   564,   567,    76,  -752,  -752,  -752,   568,   569,
     570,  -752,   571,  -752,    25,  -752,  -752,  -752,  -752,  -752,
     651,   664,   576,  -752,   578,   579,   581,    40,  -752,  -752,
    -752,   585,   583,   587,  -752,   588,   591,   596,   598,   599,
    -752,   605,   228,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,   597,   607,   608,   610,     8,  -752,
    -752,  -752,  -752,   626,   631,   632,   677,   634,   635,   636,
     471,   623,  -752,  -752,   685,   641,   710,   702,   726,   732,
     737,   741,   744,   746,   748,   749,   751,   767,   755,   756,
     757,   625,  -752,   654,   653,  -752,   121,  -752,  -752,  -752,
    -752,   669,   655,  -752,   656,   659,   657,   661,   662,   663,
      48,  -752,  -752,  -752,  -752,  -752,   773,   672,  -752,   676,
     678,  -752,   680,    68,  -752,  -752,  -752,  -752,   679,   684,
     686,  -752,   690,   691,   692,   695,   535,   696,   697,   699,
     700,   701,   705,   706,   707,   708,   711,  -752,  -752,   808,
     814,   471,   709,   831,   834,   836,   471,   837,   838,   471,
     824,   840,   841,   471,   842,   842,   722,  -752,  -752,   829,
    -134,   830,   742,   832,   833,   725,   835,   839,   851,   843,
     844,   845,   846,   735,  -752,   847,   848,   736,  -752,   743,
    -752,   850,   852,   745,  -752,   747,   750,   752,   753,   754,
     758,   759,   760,   761,   762,   763,   764,   765,   766,   768,
     769,   770,   771,   772,   774,   775,   776,   777,   778,   779,
     780,   781,   734,   782,   652,   783,   784,   785,   786,   787,
     788,   789,   790,   791,   792,   793,   794,   795,   796,   797,
     798,   799,   800,   801,   802,  -752,  -752,   854,   820,   728,
     855,   853,   857,   861,   862,   804,  -752,   863,   873,   805,
    -752,  -752,   879,   912,   806,   928,   810,  -752,   811,   812,
    -752,  -752,   914,   919,   815,  -752,  -752,   920,   849,   813,
     923,   924,   925,   926,   856,   818,   929,   822,  -752,  -752,
     930,   931,   932,   827,  -752,   828,   858,   859,   860,   864,
     865,   866,   867,  -752,   868,   869,   870,   871,   872,   874,
     875,   876,   877,   878,   880,   881,   882,   883,   884,   885,
     886,  -752,  -752,   935,   887,   888,  -752,   889,  -752,    67,
    -752,   936,   937,   939,   940,   891,  -752,   892,  -752,  -752,
     941,   890,   942,   894,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,   471,   471,   471,   471,   471,   471,   471,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,   895,   896,   897,   -43,   898,   899,   900,   901,   902,
     903,   904,   905,   906,   907,   908,   206,   909,   910,  -752,
     911,   913,   915,   916,   917,   918,   921,    -3,   922,   927,
     933,   934,   938,   943,   944,  -752,   945,   946,  -752,  -752,
     947,   948,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -175,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -168,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,   949,   950,   425,
     951,   952,   953,   954,   955,  -752,   956,   957,  -752,   958,
     959,    -9,   970,   730,  -752,  -752,  -752,  -752,   961,   962,
    -752,   963,   964,   341,   965,   966,   967,   968,   969,   693,
     971,  -752,   972,   973,   974,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,   975,   385,  -752,  -752,   976,   977,   978,  -752,    31,
    -752,  -752,  -752,  -752,   979,   982,   983,   984,  -752,  -752,
     985,   565,   986,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -165,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,   842,
     842,   842,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -128,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,   734,
    -752,   652,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,   -46,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,   -40,  -752,
     994,   928,   987,  -752,  -752,  -752,  -752,  -752,   988,  -752,
    -752,   989,  -752,  -752,  -752,  -752,   990,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,   -35,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,   -12,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,    86,  -752,  -752,   960,  -111,   993,
     991,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,    89,  -752,  -752,
    -752,   -43,  -752,  -752,  -752,  -752,    -3,  -752,  -752,  -752,
     425,  -752,    -9,  -752,  -752,  -752,  1012,  1014,  1019,  -752,
     341,  -752,   693,  -752,   385,   992,   997,   998,   547,  -752,
    -752,   565,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,   107,  -752,  -752,  -752,   547,  -752
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
       0,    90,     0,     0,     0,     0,    28,     0,     0,     0,
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
       0,     0,     0,     0,   351,    99,    98,    97,   644,   643,
     635,   636,    28,    28,    28,    28,    28,    28,    28,    30,
      29,   637,   647,   648,   638,   639,   640,   642,   641,   645,
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
     668,   663,   664,   666,    81,    89,    80,    87,    88,    79,
      83,    82,    74,    73,    78,    75,    77,    86,    76,    84,
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
    -752,  -752,  -752,  -436,  -313,  -751,  -644,  -752,  -752,   996,
    -752,  -752,  -752,  -752,   807,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,   995,  -752,  -752,  -752,  -752,  -752,
    -752,   566,  -752,  -752,  -752,  -752,  -752,   485,  -752,  -752,
    -752,  -752,  -752,  -752,   803,  -752,  -752,  -752,  -752,    18,
    -752,  -752,  -752,  -752,  -752,  -242,  -752,  -752,  -752,   559,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -203,  -752,  -752,  -752,  -200,  -752,  -752,  -752,   738,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -177,
    -752,  -752,  -752,  -752,  -752,  -190,  -752,   592,  -752,  -752,
    -752,   -74,  -752,  -752,  -752,  -752,  -752,   619,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -185,  -752,  -752,  -752,  -752,
    -752,  -752,   550,  -752,  -752,  -752,  -752,  -752,   821,  -752,
    -752,  -752,  -752,   488,  -752,  -752,  -752,  -752,  -752,  -194,
    -752,  -752,  -752,   516,  -752,  -752,  -752,  -752,  -186,  -752,
    -752,  -752,   826,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -152,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,   671,  -752,  -752,  -752,  -752,  -752,   893,
    -752,  -752,  -752,  -752,  1040,  -752,  -752,  -752,  -752,   816,
    -752,  -752,  -752,  -752,   999,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,    30,  -752,  -752,  -752,    35,  -752,  -752,  -752,  -752,
    -752,  1062,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752,  -752,  1000,  -752,
    -752,  -752,  -752,  -752,  -752,  -752,  -752
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   839,   840,  1102,  1103,    27,   227,   228,
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
     867,   868,   617,   866,   619,  1113,   621,   622,   504,   534,
     395,    51,  1084,   291,   116,   116,   122,   291,   299,   711,
      52,   123,   124,   712,   125,   126,   488,   488,    56,   127,
     395,    58,  1055,    49,    50,   481,    62,   128,   129,   713,
      73,   504,  1155,   714,   130,   535,   224,   131,    66,   585,
     871,   872,   573,   132,   405,   299,   253,    67,   133,   134,
    1128,   135,   136,   137,  1129,   138,    74,  1130,  1055,   599,
    1260,  1131,   305,    75,  1261,    69,   396,   481,   139,   140,
     117,   117,   254,   405,    71,   489,   489,  1085,   599,   141,
     505,   536,   490,   490,   491,   491,   396,   113,   114,   142,
     676,  1286,   678,   679,   115,   121,   143,  1265,   144,   685,
     145,  1266,   146,   689,   147,   148,   255,   693,   234,   221,
     696,   300,   573,   505,   222,   256,   306,   149,   223,   231,
     706,   707,   150,   151,   152,  1056,   153,   154,   155,   537,
     397,   156,   720,    76,   722,   723,   225,   257,   235,   232,
     233,   258,   586,   492,   492,   574,   236,   406,   300,   259,
     397,   290,   260,   261,   298,   482,   304,   157,   237,   238,
     226,  1056,   600,   239,   240,   241,   307,   158,   159,   160,
     161,   162,   163,   164,   407,   327,   406,   506,  1156,  1269,
     308,   600,  -129,  1270,   262,  1271,  -129,  1157,   242,  1272,
    1279,   328,   329,  1114,  1280,   330,   311,   482,   312,   313,
     224,   263,   462,   407,   264,   265,   266,  1099,  1100,  1101,
     506,   587,   314,  1281,   364,   574,   365,  1282,   366,   511,
     463,    82,   534,  1057,   165,   166,   167,   782,   168,   169,
     588,   292,   367,   267,   773,   292,   464,   512,   170,   403,
     584,   460,   582,   331,    83,    84,   589,  1058,   368,   315,
      85,   746,   268,   513,   483,   667,   316,  1240,   535,  1057,
     332,   333,   334,   335,   336,   309,   754,   575,   337,   317,
     465,   502,   338,   369,   815,   370,   269,   270,   339,   673,
     597,   571,   371,  1058,   601,    86,    87,   514,   602,   340,
     341,    88,    89,   372,   823,    73,   483,    90,    91,    92,
     225,   342,   739,   601,   536,    93,    94,   602,   853,   318,
     866,  1283,   319,   858,  1290,  1284,   861,   373,  1291,   320,
     865,    74,   515,   343,   226,   466,   321,   322,    75,   323,
      95,    96,  1317,   467,   468,  1167,  1318,   575,  1262,  1263,
    1264,   374,   516,   551,   324,   608,   402,   805,   412,   499,
     413,  1168,   537,   414,   469,   415,   416,   417,   517,  1169,
     418,   375,   419,   420,   421,   422,   423,   424,   344,   425,
     376,   585,   122,  1170,   426,   518,   519,   123,   124,   427,
     125,   126,   428,   429,   430,   127,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,   128,   129,   431,   432,   433,    76,   434,
     130,   435,   436,   131,  1171,   437,  1172,   511,   438,   132,
     646,   440,   253,   442,   133,   134,   443,   135,   136,   137,
     377,   138,   444,   445,   446,   512,   447,   520,   448,   449,
    1134,   470,  1173,   450,   139,   140,   451,   735,   254,   612,
     452,   513,   453,   454,   378,   141,   455,   456,   521,   663,
    1224,  1135,   457,   458,   767,   142,   325,   459,   609,   553,
    1136,   500,   143,   501,   144,  1174,   145,  1175,   146,   543,
     147,   148,   255,   544,   586,   514,   545,   546,   547,   548,
     549,   256,   550,   149,   554,   555,  1176,   556,   150,   151,
     152,  1137,   153,   154,   155,   557,   558,   156,   364,   559,
     365,   560,   366,   257,   561,   562,   462,   258,  1177,   563,
     515,   564,  1225,  1178,   565,   259,   367,  1179,   260,   261,
    1138,  1139,  1180,   157,   463,   566,   567,  1181,  1140,   568,
     516,  1182,   368,   158,   159,   160,   161,   162,   163,   164,
     464,   569,  1183,   587,  1226,  1184,   517,  1185,   570,   580,
     262,   581,  1227,  1141,   596,   610,   611,   369,  1186,   370,
     613,  1228,   588,   518,   519,  1187,   371,   263,   614,  1142,
     264,   265,   266,   615,   465,   616,   618,   372,   589,  1305,
     620,   623,   624,   625,  1287,   626,  1229,   627,  1230,  1231,
     165,   166,   167,   628,   168,   169,   648,   327,   629,   267,
     630,   373,  1232,   669,   170,   675,   631,     2,     3,  1233,
    1306,     4,  1307,   328,   329,   520,   633,   330,   268,   634,
     635,   636,   637,     5,   638,   374,     6,     7,   639,   466,
    1247,   640,  1143,     8,   641,   642,   521,   467,   468,   616,
     643,   644,   269,   270,     9,   375,   645,    10,    11,   677,
     649,   650,   651,   681,   376,   652,   653,  1308,   469,   654,
     656,   657,   658,   659,   670,   331,   832,   833,   834,   835,
     836,   837,   838,   660,  1309,    12,   661,   662,    82,   665,
      13,   666,   332,   333,   334,   335,   336,   671,   672,    14,
     337,   680,  1248,   943,   338,   944,   945,   682,   683,   684,
     339,    83,    84,   686,   377,   687,   688,    85,   690,    15,
      16,   340,   341,  1310,  1311,   694,   691,   692,   695,   697,
     698,   701,   234,   342,  1249,   699,   700,    17,   378,   702,
     703,   704,  1250,   705,  1195,   470,  1196,  1197,   708,   709,
     710,  1251,    86,    87,    18,   343,   715,   716,    88,    89,
     717,   718,   235,   719,    90,    91,    92,    19,    20,   721,
     236,   724,    93,    94,   727,   725,  1252,  1312,  1253,  1254,
     748,  1313,   237,   238,   728,   920,   730,   239,   240,   241,
     726,    21,  1255,   749,   731,   732,   733,    95,    96,  1256,
     344,   734,   737,   741,    22,   738,   778,   742,   743,   745,
      23,   750,   242,   751,   784,    24,   787,   752,    25,   753,
     756,   757,   946,   947,   948,   758,   760,   949,   950,   761,
     951,   952,   769,   953,   762,   954,   763,   764,   955,   786,
     788,   956,   957,   766,   775,   770,   771,   958,   772,   776,
     777,   959,   779,   780,   781,   960,   961,   962,   783,   785,
     801,   789,   963,  1198,  1199,  1200,   790,   964,  1201,  1202,
     791,  1203,  1204,   792,  1205,   793,  1206,   794,   795,  1207,
     796,   797,  1208,  1209,   798,   799,   800,   807,  1210,   802,
     808,   803,  1211,   809,   810,   811,  1212,  1213,  1214,   812,
     813,   814,   817,  1215,   921,   922,   923,   818,  1216,   924,
     925,   819,   926,   927,   825,   928,   820,   929,   822,   826,
     930,   827,   851,   931,   932,   828,   829,   830,   852,   933,
     831,   841,   842,   934,   843,   844,   845,   935,   936,   937,
     846,   847,   848,   849,   938,   855,   850,   854,   856,   939,
     857,   859,   860,   862,   863,   864,   866,   869,   870,   873,
     874,   875,   876,   877,   878,   880,   989,   991,   879,  1161,
     885,   888,   881,   882,   883,   884,   886,   887,   889,   890,
     892,   891,   893,   987,   990,   894,   992,   895,   896,   897,
     993,   994,   996,   898,   899,   900,   901,   902,   903,   904,
     905,   906,   997,   907,   908,   909,   910,   911,   999,   912,
     913,   914,   915,   916,   917,   918,   919,   942,   967,   968,
     969,   970,   971,   972,   973,   974,   975,   976,   977,   978,
     979,   980,   981,   982,   983,   984,   985,   986,   988,   995,
     998,  1000,  1002,  1008,  1001,  1005,  1006,  1007,  1009,  1011,
    1010,  1013,  1014,  1015,  1016,  1017,  1019,  1021,  1020,  1022,
    1023,  1024,  1025,  1026,  1051,  1064,  1065,  1012,  1066,  1067,
    1070,  1072,   310,   755,  1018,   816,  1319,  1241,   572,  1300,
    1299,   768,  1295,   647,  1292,  1294,   747,  1274,   774,  1285,
     736,   824,   806,  1027,  1028,  1029,   583,  1316,  1301,  1030,
    1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1273,  1039,
    1040,  1041,  1042,  1043,  1293,  1044,  1045,  1046,  1047,  1048,
    1049,  1050,   598,  1053,  1054,  1052,  1068,  1069,  1071,  1073,
    1081,  1082,  1083,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  1097,  1098,  1104,  1105,  1106,  1296,  1107,  1297,
    1108,  1109,  1110,  1111,  1298,   740,  1112,  1117,   404,   326,
       0,  1268,  1118,     0,  1267,     0,     0,     0,  1119,  1120,
     461,     0,     0,  1121,     0,     0,     0,     0,  1122,  1123,
    1124,  1125,  1126,  1127,  1132,  1133,  1146,  1147,  1148,  1149,
    1150,  1151,  1152,  1153,  1154,  1160,  1163,  1164,  1165,  1166,
    1190,  1191,  1192,  1193,  1194,   664,  1219,  1220,  1221,  1222,
    1223,  1236,     0,     0,  1242,  1237,  1238,  1243,  1244,  1245,
    1246,  1259,  1275,   503,   674,     0,  1289,  1302,  1276,  1277,
    1278,  1288,  1303,  1304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   552,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   668
};

static const yytype_int16 yycheck[] =
{
     644,   645,   315,   114,   317,     8,   319,   320,     1,     1,
       1,   237,    55,     1,     1,     1,     1,     1,     1,   218,
     237,     6,     7,   222,     9,    10,     1,     1,   237,    14,
       1,   237,     1,   235,   236,     1,   237,    22,    23,   218,
       1,     1,    51,   222,    29,    37,     1,    32,   237,     1,
     184,   185,     1,    38,     1,     1,     1,   237,    43,    44,
     235,    46,    47,    48,   239,    50,    27,   235,     1,     1,
     235,   239,   235,    34,   239,   237,    67,     1,    63,    64,
      67,    67,    27,     1,   237,    60,    60,   130,     1,    74,
      83,    83,    67,    67,    69,    69,    67,   237,   237,    84,
     413,   212,   415,   416,   237,   237,    91,   235,    93,   422,
      95,   239,    97,   426,    99,   100,    61,   430,     1,   237,
     433,   104,     1,    83,   237,    70,   238,   112,   237,   237,
     443,   444,   117,   118,   119,   104,   121,   122,   123,   131,
     131,   126,   455,   104,   457,   458,   101,    92,    31,   237,
     237,    96,   104,   128,   128,   104,    39,   104,   104,   104,
     131,   237,   107,   108,   237,   131,   237,   152,    51,    52,
     125,   104,   104,    56,    57,    58,   238,   162,   163,   164,
     165,   166,   167,   168,   131,     1,   104,   180,   197,   235,
     238,   104,   180,   239,   139,   235,   180,   206,    81,   239,
     235,    17,    18,   206,   239,    21,   238,   131,   238,   238,
       1,   156,     1,   131,   159,   160,   161,    11,    12,    13,
     180,   173,   238,   235,     1,   104,     3,   239,     5,     1,
      19,     1,     1,   202,   219,   220,   221,   550,   223,   224,
     192,   229,    19,   188,   236,   229,    35,    19,   233,   236,
     180,   236,   236,    69,    24,    25,   208,   226,    35,   238,
      30,   236,   207,    35,   230,   236,   238,   236,    37,   202,
      86,    87,    88,    89,    90,   236,   236,   226,    94,   238,
      69,   236,    98,    60,   236,    62,   231,   232,   104,   236,
     236,   236,    69,   226,   226,    65,    66,    69,   230,   115,
     116,    71,    72,    80,   236,     1,   230,    77,    78,    79,
     101,   127,   236,   226,    83,    85,    86,   230,   631,   238,
     114,   235,   238,   636,   235,   239,   639,   104,   239,   238,
     643,    27,   104,   149,   125,   124,   238,   238,    34,   238,
     110,   111,   235,   132,   133,     4,   239,   226,  1099,  1100,
    1101,   128,   124,   236,   238,   129,   238,   236,   238,   235,
     238,    20,   131,   238,   153,   238,   238,   238,   140,    28,
     238,   148,   238,   238,   238,   238,   238,   238,   194,   238,
     157,     1,     1,    42,   238,   157,   158,     6,     7,   238,
       9,    10,   238,   238,   238,    14,   832,   833,   834,   835,
     836,   837,   838,    22,    23,   238,   238,   238,   104,   238,
      29,   238,   238,    32,    73,   238,    75,     1,   238,    38,
     236,   238,     1,   238,    43,    44,   238,    46,    47,    48,
     207,    50,   238,   238,   238,    19,   238,   209,   238,   238,
      15,   230,   101,   238,    63,    64,   238,   236,    27,   114,
     238,    35,   238,   238,   231,    74,   238,   238,   230,   236,
      75,    36,   238,   238,   236,    84,   236,   238,   129,   235,
      45,   238,    91,   238,    93,   134,    95,   136,    97,   238,
      99,   100,    61,   238,   104,    69,   238,   238,   238,   238,
     238,    70,   238,   112,   238,   238,   155,   238,   117,   118,
     119,    76,   121,   122,   123,   238,   238,   126,     1,   238,
       3,   238,     5,    92,   238,   238,     1,    96,   177,   238,
     104,   238,   137,   182,   238,   104,    19,   186,   107,   108,
     105,   106,   191,   152,    19,   238,   238,   196,   113,   238,
     124,   200,    35,   162,   163,   164,   165,   166,   167,   168,
      35,   238,   211,   173,   169,   214,   140,   216,   238,   235,
     139,   238,   177,   138,   238,   129,   235,    60,   227,    62,
     114,   186,   192,   157,   158,   234,    69,   156,   218,   154,
     159,   160,   161,   114,    69,   114,   114,    80,   208,    42,
     114,   114,   114,   218,  1238,   218,   211,   235,   213,   214,
     219,   220,   221,   235,   223,   224,   235,     1,   238,   188,
     238,   104,   227,   129,   233,   218,   238,     0,     1,   234,
      73,     4,    75,    17,    18,   209,   238,    21,   207,   238,
     238,   238,   238,    16,   238,   128,    19,    20,   238,   124,
      75,   238,   217,    26,   238,   238,   230,   132,   133,   114,
     238,   238,   231,   232,    37,   148,   238,    40,    41,   114,
     238,   238,   238,   114,   157,   238,   238,   120,   153,   238,
     238,   238,   238,   238,   235,    69,   141,   142,   143,   144,
     145,   146,   147,   238,   137,    68,   238,   238,     1,   238,
      73,   238,    86,    87,    88,    89,    90,   238,   238,    82,
      94,   218,   137,    51,    98,    53,    54,   218,   114,   218,
     104,    24,    25,   218,   207,   114,   114,    30,   114,   102,
     103,   115,   116,   176,   177,   114,   218,   218,   114,   114,
     114,   218,     1,   127,   169,   114,   114,   120,   231,   238,
     218,   238,   177,   218,    51,   230,    53,    54,   218,   218,
     218,   186,    65,    66,   137,   149,   218,   218,    71,    72,
     218,   218,    31,   114,    77,    78,    79,   150,   151,   218,
      39,   218,    85,    86,   238,   235,   211,   230,   213,   214,
     129,   234,    51,    52,   238,    51,   238,    56,    57,    58,
     235,   174,   227,   129,   238,   238,   238,   110,   111,   234,
     194,   238,   238,   235,   187,   238,   129,   238,   238,   238,
     193,   235,    81,   235,   129,   198,   114,   238,   201,   238,
     235,   238,   170,   171,   172,   238,   238,   175,   176,   238,
     178,   179,   235,   181,   238,   183,   238,   238,   186,   129,
     114,   189,   190,   238,   218,   238,   238,   195,   238,   218,
     218,   199,   218,   218,   218,   203,   204,   205,   235,   218,
     235,   129,   210,   170,   171,   172,   129,   215,   175,   176,
     129,   178,   179,   129,   181,   129,   183,   129,   129,   186,
     129,   114,   189,   190,   129,   129,   129,   218,   195,   235,
     235,   238,   199,   237,   235,   238,   203,   204,   205,   238,
     238,   238,   129,   210,   170,   171,   172,   235,   215,   175,
     176,   235,   178,   179,   235,   181,   238,   183,   238,   235,
     186,   235,   114,   189,   190,   235,   235,   235,   114,   195,
     235,   235,   235,   199,   235,   235,   235,   203,   204,   205,
     235,   235,   235,   235,   210,   114,   235,   238,   114,   215,
     114,   114,   114,   129,   114,   114,   114,   235,   129,   129,
     218,   129,   129,   238,   129,   114,   238,   114,   129,   239,
     235,   235,   129,   129,   129,   129,   129,   129,   235,   129,
     235,   129,   235,   129,   129,   235,   129,   235,   235,   235,
     129,   129,   129,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   129,   235,   235,   235,   235,   235,   129,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   218,   235,
     235,   129,   114,   129,   238,   235,   235,   235,   129,   129,
     235,   238,   129,   129,   129,   129,   238,   235,   129,   129,
     129,   129,   235,   235,   129,   129,   129,   218,   129,   129,
     129,   129,    77,   507,   218,   590,  1318,  1059,   271,  1282,
    1280,   522,  1272,   345,  1261,  1270,   494,  1161,   538,   129,
     471,   603,   576,   235,   235,   235,   293,  1291,  1284,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   114,   235,
     235,   235,   235,   235,  1266,   235,   235,   235,   235,   235,
     235,   235,   301,   235,   235,   238,   235,   235,   238,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   135,   235,   135,
     235,   235,   235,   235,   135,   484,   235,   235,   118,    97,
      -1,  1131,   235,    -1,  1129,    -1,    -1,    -1,   235,   235,
     171,    -1,    -1,   235,    -1,    -1,    -1,    -1,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   225,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   379,   235,   235,   235,   235,
     235,   235,    -1,    -1,   235,   238,   238,   235,   235,   235,
     235,   235,   235,   227,   408,    -1,   235,   235,   240,   240,
     240,   238,   235,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   398
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   242,     0,     1,     4,    16,    19,    20,    26,    37,
      40,    41,    68,    73,    82,   102,   103,   120,   137,   150,
     151,   174,   187,   193,   198,   201,   243,   248,   253,   273,
     279,   285,   293,   307,   327,   351,   365,   380,   387,   391,
     401,   410,   431,   437,   443,   447,   453,   510,   527,   235,
     236,   237,   237,   328,   411,   438,   237,   448,   237,   366,
     432,   352,   237,   280,   308,   381,   237,   237,   402,   237,
     286,   237,   392,     1,    27,    34,   104,   274,   275,   276,
     277,   278,     1,    24,    25,    30,    65,    66,    71,    72,
      77,    78,    79,    85,    86,   110,   111,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   237,   237,   237,     1,    67,   444,   445,
     446,   237,     1,     6,     7,     9,    10,    14,    22,    23,
      29,    32,    38,    43,    44,    46,    47,    48,    50,    63,
      64,    74,    84,    91,    93,    95,    97,    99,   100,   112,
     117,   118,   119,   121,   122,   123,   126,   152,   162,   163,
     164,   165,   166,   167,   168,   219,   220,   221,   223,   224,
     233,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   503,   507,   508,
     509,   237,   237,   237,     1,   101,   125,   249,   250,   251,
     252,   237,   237,   237,     1,    31,    39,    51,    52,    56,
      57,    58,    81,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,     1,    27,    61,    70,    92,    96,   104,
     107,   108,   139,   156,   159,   160,   161,   188,   207,   231,
     232,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     237,     1,   229,   294,   295,   296,   297,   298,   237,     1,
     104,   388,   389,   390,   237,   235,   238,   238,   238,   236,
     275,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   236,   512,     1,    17,    18,
      21,    69,    86,    87,    88,    89,    90,    94,    98,   104,
     115,   116,   127,   149,   194,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,     1,     3,     5,    19,    35,    60,
      62,    69,    80,   104,   128,   148,   157,   207,   231,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     426,   427,   428,   429,   430,     1,    67,   131,   439,   440,
     441,   442,   238,   236,   445,     1,   104,   131,   449,   450,
     451,   452,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   504,
     238,   500,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     236,   455,     1,    19,    35,    69,   124,   132,   133,   153,
     230,   367,   368,   369,   370,   371,   372,   373,   377,   378,
     379,     1,   131,   230,   433,   434,   435,   436,     1,    60,
      67,    69,   128,   353,   357,   358,   359,   363,   364,   235,
     238,   238,   236,   250,     1,    83,   180,   281,   282,   283,
     284,     1,    19,    35,    69,   104,   124,   140,   157,   158,
     209,   230,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   323,     1,    37,    83,   131,   382,   383,
     384,   385,   386,   238,   238,   238,   238,   238,   238,   238,
     238,   236,   529,   235,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   236,   255,     1,   104,   226,   403,   404,   405,   406,
     235,   238,   236,   295,   180,     1,   104,   173,   192,   208,
     287,   288,   289,   290,   291,   292,   238,   236,   389,     1,
     104,   226,   230,   393,   394,   395,   396,   397,   129,   129,
     129,   235,   114,   114,   218,   114,   114,   245,   114,   245,
     114,   245,   245,   114,   114,   218,   218,   235,   235,   238,
     238,   238,   348,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   236,   330,   235,   238,
     238,   238,   238,   238,   238,   423,   238,   238,   238,   238,
     238,   238,   238,   236,   413,   238,   238,   236,   440,   129,
     235,   238,   238,   236,   450,   218,   245,   114,   245,   245,
     218,   114,   218,   114,   218,   245,   218,   114,   114,   245,
     114,   218,   218,   245,   114,   114,   245,   114,   114,   114,
     114,   218,   238,   218,   238,   218,   245,   245,   218,   218,
     218,   218,   222,   218,   222,   218,   218,   218,   218,   114,
     245,   218,   245,   245,   218,   235,   235,   238,   238,   374,
     238,   238,   238,   238,   238,   236,   368,   238,   238,   236,
     434,   235,   238,   238,   354,   238,   236,   358,   129,   129,
     235,   235,   238,   238,   236,   282,   235,   238,   238,   324,
     238,   238,   238,   238,   238,   320,   238,   236,   310,   235,
     238,   238,   238,   236,   383,   218,   218,   218,   129,   218,
     218,   218,   245,   235,   129,   218,   129,   114,   114,   129,
     129,   129,   129,   129,   129,   129,   129,   114,   129,   129,
     129,   235,   235,   238,   407,   236,   404,   218,   235,   237,
     235,   238,   238,   238,   238,   236,   288,   129,   235,   235,
     238,   398,   238,   236,   394,   235,   235,   235,   235,   235,
     235,   235,   141,   142,   143,   144,   145,   146,   147,   244,
     245,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   114,   114,   245,   238,   114,   114,   114,   245,   114,
     114,   245,   129,   114,   114,   245,   114,   247,   247,   235,
     129,   184,   185,   129,   218,   129,   129,   238,   129,   129,
     114,   129,   129,   129,   129,   235,   129,   129,   235,   235,
     129,   129,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
      51,   170,   171,   172,   175,   176,   178,   179,   181,   183,
     186,   189,   190,   195,   199,   203,   204,   205,   210,   215,
     505,   506,   235,    51,    53,    54,   170,   171,   172,   175,
     176,   178,   179,   181,   183,   186,   189,   190,   195,   199,
     203,   204,   205,   210,   215,   501,   502,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   129,   218,   238,
     129,   114,   129,   129,   129,   235,   129,   129,   235,   129,
     129,   238,   114,   361,   362,   235,   235,   235,   129,   129,
     235,   129,   218,   238,   129,   129,   129,   129,   218,   238,
     129,   235,   129,   129,   129,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   129,   238,   235,   235,     1,   104,   202,   226,   299,
     300,   301,   302,   303,   129,   129,   129,   129,   235,   235,
     129,   238,   129,   235,   244,   244,   244,   244,   244,   244,
     244,   235,   235,   235,    55,   130,   349,   350,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,    11,
      12,    13,   246,   247,   235,   235,   235,   235,   235,   235,
     235,   235,   235,     8,   206,   424,   425,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   239,
     235,   239,   235,   235,    15,    36,    45,    76,   105,   106,
     113,   138,   154,   217,   375,   376,   235,   235,   235,   235,
     235,   235,   235,   235,   235,    51,   197,   206,   355,   356,
     225,   239,   360,   235,   235,   235,   235,     4,    20,    28,
      42,    73,    75,   101,   134,   136,   155,   177,   182,   186,
     191,   196,   200,   211,   214,   216,   227,   234,   325,   326,
     235,   235,   235,   235,   235,    51,    53,    54,   170,   171,
     172,   175,   176,   178,   179,   181,   183,   186,   189,   190,
     195,   199,   203,   204,   205,   210,   215,   321,   322,   235,
     235,   235,   235,   235,    75,   137,   169,   177,   186,   211,
     213,   214,   227,   234,   408,   409,   235,   238,   238,   304,
     236,   300,   235,   235,   235,   235,   235,    75,   137,   169,
     177,   186,   211,   213,   214,   227,   234,   399,   400,   235,
     235,   239,   246,   246,   246,   235,   239,   506,   502,   235,
     239,   235,   239,   114,   362,   235,   240,   240,   240,   235,
     239,   235,   239,   235,   239,   129,   212,   247,   238,   235,
     235,   239,   350,   425,   376,   356,   135,   135,   135,   326,
     322,   409,   235,   235,   235,    42,    73,    75,   120,   137,
     176,   177,   230,   234,   305,   306,   400,   235,   239,   306
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
     255,   255,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   274,   275,   275,   275,   275,   276,   277,   278,
     280,   279,   281,   281,   282,   282,   282,   283,   284,   286,
     285,   287,   287,   288,   288,   288,   288,   288,   289,   290,
     291,   292,   293,   294,   294,   295,   295,   295,   296,   298,
     297,   299,   299,   300,   300,   300,   300,   301,   302,   302,
     304,   303,   305,   305,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   308,   307,   309,   309,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   320,   319,   321,   321,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   324,   323,   325,   325,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     328,   327,   329,   329,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   348,   347,
     349,   349,   350,   350,   352,   351,   354,   353,   355,   355,
     356,   356,   356,   357,   357,   358,   358,   358,   358,   358,
     360,   359,   361,   361,   362,   362,   363,   364,   366,   365,
     367,   367,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   369,   370,   371,   372,   374,   373,   375,   375,   376,
     376,   376,   376,   376,   376,   376,   376,   376,   376,   377,
     378,   379,   381,   380,   382,   382,   383,   383,   383,   383,
     384,   385,   386,   387,   388,   388,   389,   389,   390,   392,
     391,   393,   393,   394,   394,   394,   394,   395,   396,   398,
     397,   399,   399,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   402,   401,   403,   403,   404,   404,   404,
     405,   407,   406,   408,   408,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   411,   410,   412,   412,   413,
     413,   413,   413,   413,   413,   413,   413,   413,   413,   413,
     413,   413,   413,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   421,   423,   422,   424,   424,   425,   425,   426,
     427,   428,   429,   430,   432,   431,   433,   433,   434,   434,
     434,   435,   436,   438,   437,   439,   439,   440,   440,   440,
     441,   442,   443,   444,   444,   445,   445,   446,   448,   447,
     449,   449,   450,   450,   450,   451,   452,   453,   454,   454,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   484,   485,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   500,   499,   501,   501,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     504,   503,   505,   505,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   507,   508,   509,   510,   511,   511,
     512,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     512,   512,   512,   512,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   528,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   530,   531,   532,   533,   534,   535,   536,   537
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
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 428 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 429 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 432 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 433 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 434 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 435 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 436 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 450 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 456 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 486 "conf_parser.y" /* yacc.c:1646  */
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
#line 3018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 526 "conf_parser.y" /* yacc.c:1646  */
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
#line 3079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 584 "conf_parser.y" /* yacc.c:1646  */
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
#line 3111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 613 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3122 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 621 "conf_parser.y" /* yacc.c:1646  */
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
#line 3139 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 635 "conf_parser.y" /* yacc.c:1646  */
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
#line 3170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 663 "conf_parser.y" /* yacc.c:1646  */
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
#line 3188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 678 "conf_parser.y" /* yacc.c:1646  */
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
#line 3206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 693 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 703 "conf_parser.y" /* yacc.c:1646  */
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
#line 3236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 717 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 726 "conf_parser.y" /* yacc.c:1646  */
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
#line 3279 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 754 "conf_parser.y" /* yacc.c:1646  */
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
#line 3310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 782 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < MAXCLIENTS_MIN)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
    conf_error_report(buf);
    ConfigServerInfo.max_clients = MAXCLIENTS_MIN;
  }
  else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);
    ConfigServerInfo.max_clients = MAXCLIENTS_MAX;
  }
  else
    ConfigServerInfo.max_clients = (yyvsp[-1].number);
}
#line 3338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 807 "conf_parser.y" /* yacc.c:1646  */
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
#line 3363 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 829 "conf_parser.y" /* yacc.c:1646  */
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
#line 3388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 868 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 877 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3421 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 886 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 898 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 902 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 919 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3477 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 934 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 938 "conf_parser.y" /* yacc.c:1646  */
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
#line 3504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 956 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3513 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3522 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 974 "conf_parser.y" /* yacc.c:1646  */
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
#line 3554 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1003 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1009 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3596 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1037 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3604 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1040 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3612 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3621 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1052 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3630 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1056 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3639 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1060 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3648 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1064 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3657 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1068 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3666 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1072 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1076 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1080 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1084 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3702 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1094 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1101 "conf_parser.y" /* yacc.c:1646  */
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
#line 3796 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1193 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3805 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1199 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1205 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1211 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1222 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1228 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1234 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3869 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1245 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3878 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1251 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1258 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3905 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1266 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3914 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1270 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3923 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1274 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3932 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1278 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3941 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1282 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1286 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3959 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1290 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1294 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3977 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1298 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3986 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1302 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3995 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1306 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4004 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1310 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4013 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1314 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4022 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1318 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4031 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1322 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1326 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4049 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1330 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4058 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1334 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4067 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1338 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4076 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1342 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1348 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1355 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1359 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1363 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4121 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1367 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4130 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1371 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4139 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1375 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4148 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1379 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4157 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1383 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4166 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1387 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4175 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1391 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4184 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1395 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4193 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1399 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4202 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1403 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4211 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1407 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4220 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1411 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1415 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1419 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4247 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1423 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1427 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4265 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1431 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4274 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1435 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4283 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1439 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4292 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1443 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1457 "conf_parser.y" /* yacc.c:1646  */
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
#line 4327 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1469 "conf_parser.y" /* yacc.c:1646  */
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
#line 4380 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1538 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1544 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1550 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1556 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1562 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1568 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1574 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1580 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1586 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1592 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1598 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1605 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1611 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1617 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1623 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4519 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1632 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1641 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4540 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1648 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4549 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1652 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1662 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1668 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4575 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1674 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4584 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1678 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4593 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1682 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4602 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1690 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4608 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1695 "conf_parser.y" /* yacc.c:1646  */
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
#line 4626 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1708 "conf_parser.y" /* yacc.c:1646  */
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
#line 4646 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1725 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4655 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1731 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4664 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1740 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1744 "conf_parser.y" /* yacc.c:1646  */
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
#line 4714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1793 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1799 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1805 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1811 "conf_parser.y" /* yacc.c:1646  */
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

  case 315:
#line 1822 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1829 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1833 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1837 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1841 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1845 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1849 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1853 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1857 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1861 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1865 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1871 "conf_parser.y" /* yacc.c:1646  */
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

  case 330:
#line 1885 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1894 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1907 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1914 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1931 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1937 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1952 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1967 "conf_parser.y" /* yacc.c:1646  */
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

  case 350:
#line 1978 "conf_parser.y" /* yacc.c:1646  */
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
#line 4993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1995 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 2001 "conf_parser.y" /* yacc.c:1646  */
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

  case 359:
#line 2020 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5033 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5042 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2031 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5051 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5060 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2039 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2043 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2047 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2051 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5105 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2059 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5114 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2063 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5123 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2072 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2081 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2096 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2102 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2109 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5179 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2113 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2117 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2121 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2125 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5215 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2129 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2133 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5233 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2137 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5242 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2141 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5251 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2145 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5260 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2154 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5274 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2163 "conf_parser.y" /* yacc.c:1646  */
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
#line 5340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2261 "conf_parser.y" /* yacc.c:1646  */
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
#line 5383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2274 "conf_parser.y" /* yacc.c:1646  */
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
#line 5399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2299 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2303 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2309 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2315 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2319 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5475 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5484 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2342 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5493 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2348 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2354 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5516 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2369 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5525 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2373 "conf_parser.y" /* yacc.c:1646  */
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
#line 5550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2398 "conf_parser.y" /* yacc.c:1646  */
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
#line 5573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2418 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2427 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5591 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2431 "conf_parser.y" /* yacc.c:1646  */
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
#line 5617 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2457 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5626 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2463 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5635 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2477 "conf_parser.y" /* yacc.c:1646  */
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
#line 5652 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2494 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5661 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2498 "conf_parser.y" /* yacc.c:1646  */
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
#line 5683 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2520 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5692 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2526 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5701 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2590 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2595 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5717 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2600 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5725 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2605 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5734 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2611 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.glines = yylval.number;
}
#line 5743 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2617 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_time = (yyvsp[-1].number);
}
#line 5752 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2623 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_request_time = (yyvsp[-1].number);
}
#line 5761 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2629 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr = (yyvsp[-1].number);
}
#line 5769 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2634 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2639 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5785 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2644 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2649 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5801 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2654 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2659 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5817 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2664 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2669 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5833 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2674 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2679 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2684 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5857 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2689 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2695 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2706 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2711 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2716 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2721 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2726 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2731 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2736 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2741 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2744 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2749 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2752 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2767 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 6008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2782 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_pass_resv = yylval.number;
}
#line 6024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 6032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2797 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2802 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2812 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2817 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2861 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2864 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6184 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2867 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2870 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2873 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2876 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2879 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2882 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2885 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2888 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2891 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2896 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2902 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2908 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2911 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2914 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2917 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2920 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2923 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2926 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2929 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2932 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2935 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2938 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2941 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2944 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2947 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2950 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2953 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2956 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2959 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2964 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 3003 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3008 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3013 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3018 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 3023 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6488 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 3028 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3033 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3038 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3043 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 3048 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3053 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6536 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 3058 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6544 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 3063 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6552 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 3068 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3090 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3096 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3102 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6587 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3108 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6596 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3114 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6608 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 666:
#line 3123 "conf_parser.y" /* yacc.c:1646  */
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
#line 6626 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 3138 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6635 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 668:
#line 3144 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6644 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6648 "conf_parser.c" /* yacc.c:1646  */
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
