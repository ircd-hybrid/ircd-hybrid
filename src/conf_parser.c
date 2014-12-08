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
    T_MAX_CLIENTS = 442,
    T_NCHANGE = 443,
    T_NONONREG = 444,
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
    USE_EGD = 481,
    USE_LOGGING = 482,
    USER = 483,
    VHOST = 484,
    VHOST6 = 485,
    WARN_NO_CONNECT_BLOCK = 486,
    XLINE = 487
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
#define T_MAX_CLIENTS 442
#define T_NCHANGE 443
#define T_NONONREG 444
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
#define USE_EGD 481
#define USE_LOGGING 482
#define USER 483
#define VHOST 484
#define VHOST6 485
#define WARN_NO_CONNECT_BLOCK 486
#define XLINE 487

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 152 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 699 "conf_parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 714 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  239
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  296
/* YYNRULES -- Number of rules.  */
#define YYNRULES  665
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1314

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   487

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
       2,     2,     2,     2,   237,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   238,   233,
       2,   236,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   235,     2,   234,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   388,   388,   389,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   419,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   430,   430,
     431,   432,   433,   434,   441,   444,   444,   445,   445,   445,
     447,   453,   460,   462,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   483,   523,   581,   610,   618,   632,   660,
     675,   690,   700,   714,   723,   751,   779,   804,   826,   848,
     857,   859,   859,   860,   861,   862,   863,   865,   874,   883,
     896,   895,   913,   913,   914,   914,   914,   916,   922,   932,
     931,   950,   950,   951,   951,   951,   951,   951,   953,   959,
     965,   971,   994,   995,   995,   997,   997,   998,  1000,  1007,
    1007,  1020,  1021,  1023,  1023,  1024,  1024,  1026,  1034,  1037,
    1043,  1042,  1048,  1048,  1049,  1053,  1057,  1061,  1065,  1069,
    1073,  1077,  1081,  1092,  1091,  1177,  1177,  1178,  1179,  1180,
    1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1190,  1196,
    1202,  1208,  1219,  1225,  1231,  1242,  1249,  1248,  1254,  1254,
    1255,  1259,  1263,  1267,  1271,  1275,  1279,  1283,  1287,  1291,
    1295,  1299,  1303,  1307,  1311,  1315,  1319,  1323,  1327,  1331,
    1335,  1339,  1346,  1345,  1351,  1351,  1352,  1356,  1360,  1364,
    1368,  1372,  1376,  1380,  1384,  1388,  1392,  1396,  1400,  1404,
    1408,  1412,  1416,  1420,  1424,  1428,  1432,  1436,  1440,  1451,
    1450,  1512,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,  1522,  1523,  1524,  1525,  1525,  1526,  1527,  1528,
    1529,  1531,  1537,  1543,  1549,  1555,  1561,  1567,  1573,  1579,
    1585,  1591,  1598,  1604,  1610,  1616,  1625,  1635,  1634,  1640,
    1640,  1641,  1645,  1656,  1655,  1662,  1661,  1666,  1666,  1667,
    1671,  1675,  1681,  1681,  1682,  1682,  1682,  1682,  1682,  1684,
    1684,  1686,  1686,  1688,  1701,  1718,  1724,  1734,  1733,  1775,
    1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,
    1786,  1792,  1798,  1804,  1816,  1815,  1821,  1821,  1822,  1826,
    1830,  1834,  1838,  1842,  1846,  1850,  1854,  1858,  1864,  1878,
    1887,  1901,  1900,  1915,  1915,  1916,  1916,  1916,  1916,  1918,
    1924,  1930,  1940,  1942,  1942,  1943,  1943,  1945,  1961,  1960,
    1985,  1985,  1986,  1986,  1986,  1986,  1988,  1994,  2014,  2013,
    2019,  2019,  2020,  2024,  2028,  2032,  2036,  2040,  2044,  2048,
    2052,  2056,  2066,  2065,  2086,  2086,  2087,  2087,  2087,  2089,
    2096,  2095,  2101,  2101,  2102,  2106,  2110,  2114,  2118,  2122,
    2126,  2130,  2134,  2138,  2148,  2147,  2219,  2219,  2220,  2221,
    2222,  2223,  2224,  2225,  2226,  2227,  2228,  2229,  2230,  2231,
    2232,  2233,  2234,  2236,  2242,  2248,  2254,  2267,  2280,  2286,
    2292,  2296,  2303,  2302,  2307,  2307,  2308,  2312,  2318,  2329,
    2335,  2341,  2347,  2363,  2362,  2388,  2388,  2389,  2389,  2389,
    2391,  2411,  2421,  2420,  2447,  2447,  2448,  2448,  2448,  2450,
    2456,  2465,  2467,  2467,  2468,  2468,  2470,  2488,  2487,  2510,
    2510,  2511,  2511,  2511,  2513,  2519,  2528,  2531,  2531,  2532,
    2533,  2534,  2535,  2536,  2537,  2538,  2539,  2540,  2541,  2542,
    2543,  2544,  2545,  2546,  2547,  2548,  2549,  2550,  2551,  2552,
    2553,  2554,  2555,  2556,  2557,  2558,  2559,  2560,  2561,  2562,
    2563,  2564,  2565,  2566,  2567,  2568,  2569,  2570,  2571,  2572,
    2573,  2574,  2575,  2576,  2577,  2578,  2579,  2582,  2587,  2592,
    2597,  2603,  2609,  2615,  2621,  2626,  2631,  2636,  2641,  2646,
    2651,  2656,  2661,  2666,  2671,  2676,  2681,  2687,  2698,  2703,
    2708,  2713,  2718,  2723,  2728,  2731,  2736,  2739,  2744,  2749,
    2754,  2759,  2764,  2769,  2774,  2779,  2784,  2789,  2794,  2799,
    2804,  2810,  2809,  2814,  2814,  2815,  2818,  2821,  2824,  2827,
    2830,  2833,  2836,  2839,  2842,  2845,  2848,  2851,  2854,  2857,
    2860,  2863,  2866,  2869,  2872,  2875,  2878,  2884,  2883,  2888,
    2888,  2889,  2892,  2895,  2898,  2901,  2904,  2907,  2910,  2913,
    2916,  2919,  2922,  2925,  2928,  2931,  2934,  2937,  2940,  2943,
    2946,  2951,  2956,  2961,  2970,  2973,  2973,  2974,  2975,  2976,
    2977,  2978,  2979,  2980,  2981,  2982,  2983,  2984,  2985,  2986,
    2987,  2988,  2990,  2995,  3000,  3005,  3010,  3015,  3020,  3025,
    3030,  3035,  3040,  3045,  3050,  3055,  3063,  3066,  3066,  3067,
    3068,  3069,  3070,  3071,  3072,  3073,  3074,  3075,  3077,  3083,
    3089,  3095,  3101,  3110,  3125,  3131
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
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY",
  "STATS_U_OPER_ONLY", "T_ALL", "T_BOTS", "T_CALLERID", "T_CCONN",
  "T_COMMAND", "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS", "T_INVISIBLE", "T_IPV4",
  "T_IPV6", "T_LOCOPS", "T_LOG", "T_MAX_CLIENTS", "T_NCHANGE",
  "T_NONONREG", "T_PREPEND", "T_PSEUDO", "T_RECVQ", "T_REJ", "T_RESTART",
  "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET", "T_SHARED", "T_SIZE",
  "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL", "T_SSL_CIPHER_LIST",
  "T_TARGET", "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED",
  "T_UNRESV", "T_UNXLINE", "T_WALLOP", "T_WALLOPS", "T_WEBIRC", "TBOOL",
  "THROTTLE_COUNT", "THROTTLE_TIME", "TKLINE_EXPIRE_NOTICES", "TMASKED",
  "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "TYPE", "UNKLINE", "USE_EGD",
  "USE_LOGGING", "USER", "VHOST", "VHOST6", "WARN_NO_CONNECT_BLOCK",
  "XLINE", "';'", "'}'", "'{'", "'='", "','", "':'", "$accept", "conf",
  "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_certificate_file",
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
  "general_stats_o_oper_only", "general_stats_P_oper_only",
  "general_stats_u_oper_only", "general_stats_k_oper_only",
  "general_stats_i_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_oper_pass_resv",
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
     485,   486,   487,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -761

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-761)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -761,   657,  -761,  -144,  -223,  -217,  -761,  -761,  -761,  -215,
    -761,  -208,  -761,  -761,  -761,  -198,  -761,  -761,  -761,  -196,
    -190,  -761,  -182,  -761,  -171,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,   170,   933,  -163,  -161,  -153,    10,  -143,   409,   -96,
     -75,   -43,    20,   -40,   -37,   -34,   512,   329,   -32,     4,
     -26,    25,   -20,  -204,   -18,    -1,     1,     8,  -761,  -761,
    -761,  -761,  -761,    24,    76,    77,    84,    88,    90,    92,
      95,    96,   102,   105,   110,   113,   114,   229,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,   648,   477,    57,  -761,   115,    47,  -761,
    -761,    55,  -761,   116,   119,   122,   123,   125,   127,   129,
     130,   131,   132,   134,   136,   138,   139,   140,   141,   143,
     145,   146,   147,   148,   149,   150,   153,   155,   156,   157,
    -761,   158,  -761,   171,   172,   173,   175,   178,   184,   188,
     190,   191,   192,   198,   199,   203,   204,   206,   207,   208,
     126,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,   476,
      51,   302,    64,   209,   212,    50,  -761,  -761,  -761,    15,
     498,   233,  -761,   213,   214,   215,   218,   222,   224,   225,
     226,    29,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,   231,   234,   235,   238,   240,   243,   245,   248,   250,
     251,   258,   261,   265,   267,   269,   274,   278,   282,    46,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,    61,   232,
     283,    12,  -761,  -761,  -761,    89,   223,  -761,   284,    43,
    -761,  -761,    74,  -761,   111,   338,   340,   289,  -761,   410,
     411,   320,   424,   426,   427,   426,   428,   426,   426,   430,
     434,   333,   334,   321,  -761,   322,   317,   330,   342,  -761,
     343,   344,   346,   347,   348,   349,   351,   353,   354,   356,
     358,   359,   360,     7,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,   332,   361,   362,   363,   365,   367,   368,  -761,
     370,   371,   382,   383,   384,   388,   396,   318,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,   397,   399,    37,  -761,  -761,  -761,
     507,   404,  -761,  -761,   403,   405,    53,  -761,  -761,  -761,
     429,   426,   529,   426,   426,   432,   530,   435,   536,   437,
     426,   443,   546,   548,   426,   550,   451,   454,   426,   557,
     560,   426,   561,   564,   566,   570,   470,   452,   473,   455,
     474,   426,   426,   484,   486,   491,  -206,  -201,   492,   493,
     494,   578,   426,   495,   426,   426,   497,   460,  -761,   482,
     467,   480,  -761,   485,   488,   496,   504,   511,   264,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,   513,
     514,    30,  -761,  -761,  -761,   489,   515,   518,  -761,   519,
    -761,    39,  -761,  -761,  -761,  -761,  -761,   594,   598,   500,
    -761,   524,   522,   525,    35,  -761,  -761,  -761,   533,   531,
     532,  -761,   534,   535,   537,   538,   540,  -761,   542,    22,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,   539,   543,   544,   549,    32,  -761,  -761,  -761,  -761,
     553,   571,   574,   599,   575,   576,   579,   426,   563,  -761,
    -761,   600,   582,   602,   634,   679,   670,   671,   672,   674,
     675,   676,   677,   681,   697,   683,   684,   685,   583,  -761,
     584,   587,  -761,    48,  -761,  -761,  -761,  -761,   603,   585,
    -761,   580,   591,   589,   590,   592,   593,    21,  -761,  -761,
    -761,  -761,  -761,   698,   601,  -761,   604,   595,  -761,   596,
      33,  -761,  -761,  -761,  -761,   605,   606,   608,  -761,   609,
     611,   612,   613,   259,   614,   616,   617,   619,   621,   622,
     624,   625,   629,   630,  -761,  -761,   719,   721,   426,   633,
     722,   752,   757,   426,   760,   762,   426,   751,   767,   768,
     426,   770,   770,   652,  -761,  -761,   759,   121,   761,   673,
     765,   766,   650,   773,   777,   782,   780,   785,   787,   788,
     664,  -761,   791,   792,   678,  -761,   689,  -761,   795,   796,
     693,  -761,   695,   696,   702,   703,   704,   706,   714,   717,
     729,   732,   733,   734,   736,   737,   738,   742,   743,   744,
     745,   747,   748,   749,   750,   753,   756,   758,   763,   771,
     764,   690,   769,   774,   781,   783,   784,   789,   790,   793,
     794,   797,   798,   799,   800,   801,   802,   803,   804,   805,
     806,  -761,  -761,   825,   739,   694,   861,   878,   864,   865,
     866,   807,  -761,   871,   874,   808,  -761,  -761,   877,   880,
     779,   899,   809,  -761,   812,   813,  -761,  -761,   891,   892,
     814,  -761,  -761,   895,   832,   815,   896,   900,   920,   921,
     836,   817,   925,   822,  -761,  -761,   927,   928,   929,   826,
    -761,   827,   828,   829,   830,   831,   833,   834,   835,  -761,
     837,   838,   839,   840,   841,   842,   843,   844,   845,   846,
     847,   848,   849,   850,   851,   852,   853,  -761,  -761,   936,
     854,   855,  -761,   856,  -761,   118,  -761,   940,   958,   962,
     963,   860,  -761,   862,  -761,  -761,   965,   863,   967,   867,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,   426,   426,
     426,   426,   426,   426,   426,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,   868,   869,   870,
     -52,   872,   873,   875,   876,   879,   881,   882,   883,   884,
     885,   886,   298,   887,   888,  -761,   889,   890,   893,   894,
     897,   898,   901,     9,   902,   903,   904,   905,   906,   907,
     908,  -761,   909,   910,  -761,  -761,   911,   912,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -187,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -178,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,   913,   914,   541,   915,   916,   917,   918,   919,
    -761,   922,   923,  -761,   924,   926,    -8,   930,   117,  -761,
    -761,  -761,  -761,   931,   932,  -761,   934,   935,   487,   937,
     938,   939,   941,   942,   730,   943,  -761,   944,   945,   946,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,   947,   577,  -761,  -761,
     948,   949,   950,  -761,    62,  -761,  -761,  -761,  -761,   951,
     954,   955,   956,  -761,  -761,   957,   776,   959,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -172,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,   770,   770,   770,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -167,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,   771,  -761,   690,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -166,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -154,  -761,   983,   899,   960,  -761,  -761,
    -761,  -761,  -761,   953,  -761,  -761,   961,  -761,  -761,  -761,
    -761,   964,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -149,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,   -56,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,   -25,  -761,
    -761,   969,   -82,   968,   970,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,   -17,  -761,  -761,  -761,   -52,  -761,  -761,  -761,  -761,
       9,  -761,  -761,  -761,   541,  -761,    -8,  -761,  -761,  -761,
     972,   975,   976,  -761,   487,  -761,   730,  -761,   577,   973,
     974,   977,   645,  -761,  -761,   776,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,    -5,  -761,
    -761,  -761,   645,  -761
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   229,   394,   442,     0,
     457,     0,   297,   433,   273,     0,   100,   153,   331,     0,
       0,   372,     0,   109,     0,   348,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,   630,
     618,   619,   620,   621,   622,   623,   617,   624,   625,   626,
     627,   628,   629,     0,     0,     0,   455,     0,     0,   453,
     454,     0,   516,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     587,     0,   561,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   468,   469,   470,   514,   515,   508,   509,   510,   511,
     512,   507,   480,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   504,   481,   482,   513,   484,   489,   490,   485,
     487,   486,   497,   498,   488,   491,   492,   493,   483,   495,
     505,   506,   502,   503,   496,   494,   500,   501,   499,     0,
       0,     0,     0,     0,     0,     0,    46,    47,    48,     0,
       0,     0,   657,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   648,   649,   650,   651,   652,   655,   653,   654,
     656,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    69,    66,    64,    70,    71,    65,    55,    68,    58,
      59,    60,    56,    67,    61,    62,    63,    57,     0,     0,
       0,     0,   124,   125,   126,     0,     0,   346,     0,     0,
     344,   345,     0,    96,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   615,     0,     0,     0,     0,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,   233,   236,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   234,   235,   237,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,   422,
       0,     0,     0,     0,     0,     0,     0,     0,   397,   398,
     399,   400,   401,   402,   403,   405,   404,   407,   411,   408,
     409,   410,   406,   448,     0,     0,     0,   445,   446,   447,
       0,     0,   452,   463,     0,     0,     0,   460,   461,   462,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   467,     0,
       0,     0,   314,     0,     0,     0,     0,     0,     0,   300,
     301,   302,   303,   308,   304,   305,   306,   307,   439,     0,
       0,     0,   436,   437,   438,     0,     0,     0,   275,     0,
     285,     0,   283,   284,   286,   287,    49,     0,     0,     0,
      45,     0,     0,     0,     0,   103,   104,   105,     0,     0,
       0,   202,     0,     0,     0,     0,     0,   176,     0,     0,
     156,   157,   158,   159,   162,   163,   164,   165,   161,   160,
     166,     0,     0,     0,     0,     0,   334,   335,   336,   337,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   647,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,   380,     0,   375,   376,   377,   127,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   112,   113,
     115,   114,   116,     0,     0,   343,     0,     0,   358,     0,
       0,   351,   352,   353,   354,     0,     0,     0,    90,     0,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   614,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   231,   412,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   396,     0,     0,     0,   444,     0,   451,     0,     0,
       0,   459,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   466,   309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   299,     0,     0,     0,   435,   288,     0,     0,
       0,     0,     0,   282,     0,     0,    44,   106,     0,     0,
       0,   102,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   155,   338,     0,     0,     0,     0,
     333,     0,     0,     0,     0,     0,     0,     0,     0,   646,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,   378,     0,
       0,     0,   374,     0,   122,     0,   117,     0,     0,     0,
       0,     0,   111,     0,   342,   355,     0,     0,     0,     0,
     350,    99,    98,    97,   641,   640,   632,   633,    28,    28,
      28,    28,    28,    28,    28,    30,    29,   634,   644,   645,
     635,   636,   637,   639,   638,   642,   643,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   230,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   395,     0,     0,   443,   456,     0,     0,   458,   530,
     534,   517,   518,   549,   520,   613,   558,   555,   529,   522,
     521,   524,   525,   523,   537,   528,   538,   527,   533,   532,
     531,   556,   519,   611,   612,   553,   597,   591,   607,   592,
     593,   594,   602,   610,   595,   604,   608,   598,   609,   599,
     603,   596,   606,   601,   600,   605,     0,   590,   554,   570,
     571,   572,   565,   583,   566,   567,   568,   578,   586,   569,
     580,   584,   574,   585,   575,   579,   573,   582,   577,   576,
     581,     0,   564,   550,   548,   551,   557,   552,   540,   546,
     547,   544,   545,   541,   542,   543,   559,   560,   526,   536,
     535,   539,     0,     0,     0,     0,     0,     0,     0,     0,
     298,     0,     0,   434,     0,     0,     0,   293,   289,   292,
     274,    50,    51,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,     0,     0,     0,
     332,   659,   658,   664,   662,   665,   660,   661,   663,    81,
      89,    80,    87,    88,    79,    83,    82,    74,    73,    78,
      75,    77,    86,    76,    84,    85,     0,     0,   373,   128,
       0,     0,     0,   140,     0,   132,   133,   135,   134,     0,
       0,     0,     0,   110,   347,     0,     0,     0,   349,    31,
      32,    33,    34,    35,    36,    37,   262,   263,   254,   272,
     271,     0,   270,   255,   257,   259,   266,   258,   256,   265,
     251,   264,   253,   252,    38,    38,    38,    40,    39,   260,
     261,   417,   420,   421,   431,   428,   414,   429,   426,   427,
       0,   425,   430,   413,   419,   416,   418,   432,   415,   449,
     450,   464,   465,   588,     0,   562,     0,   312,   313,   322,
     319,   324,   320,   321,   327,   323,   325,   318,   326,     0,
     317,   311,   330,   329,   328,   310,   441,   440,   296,   295,
     280,   281,   279,     0,   278,     0,     0,     0,   107,   108,
     175,   171,   222,   209,   219,   218,   207,   212,   228,   221,
     226,   211,   214,   223,   225,   220,   227,   215,   217,   224,
     213,   216,     0,   205,   168,   170,   172,   173,   174,   185,
     186,   187,   180,   198,   181,   182,   183,   193,   201,   184,
     195,   199,   189,   200,   190,   194,   188,   197,   192,   191,
     196,     0,   179,   169,   341,   339,   340,   379,   384,   390,
     393,   386,   392,   387,   391,   389,   385,   388,     0,   383,
     136,     0,     0,     0,     0,   131,   119,   118,   120,   121,
     356,   362,   368,   371,   364,   370,   365,   369,   367,   363,
     366,     0,   361,   357,   268,     0,    41,    42,    43,   423,
       0,   589,   563,   315,     0,   276,     0,   294,   291,   290,
       0,     0,     0,   203,     0,   177,     0,   381,     0,     0,
       0,     0,     0,   130,   359,     0,   269,   424,   316,   277,
     208,   206,   210,   204,   178,   382,   137,   139,   138,   146,
     151,   150,   145,   148,   152,   149,   144,   147,     0,   143,
     360,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -761,  -761,  -761,  -218,  -311,  -760,  -641,  -761,  -761,   971,
    -761,  -761,  -761,  -761,   859,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  1027,  -761,  -761,  -761,  -761,  -761,
    -761,   620,  -761,  -761,  -761,  -761,  -761,   441,  -761,  -761,
    -761,  -761,  -761,  -761,   952,  -761,  -761,  -761,  -761,    59,
    -761,  -761,  -761,  -761,  -761,  -183,  -761,  -761,  -761,   635,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -151,  -761,  -761,  -761,  -142,  -761,  -761,  -761,   818,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -122,
    -761,  -761,  -761,  -761,  -761,  -108,  -761,   669,  -761,  -761,
    -761,     6,  -761,  -761,  -761,  -761,  -761,   701,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -101,  -761,  -761,  -761,  -761,
    -761,  -761,   631,  -761,  -761,  -761,  -761,  -761,   966,  -761,
    -761,  -761,  -761,   573,  -761,  -761,  -761,  -761,  -761,  -103,
    -761,  -761,  -761,   610,  -761,  -761,  -761,  -761,   -84,  -761,
    -761,  -761,   820,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,   -65,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,   720,  -761,  -761,  -761,  -761,  -761,   816,
    -761,  -761,  -761,  -761,  1080,  -761,  -761,  -761,  -761,   810,
    -761,  -761,  -761,  -761,  1030,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
      79,  -761,  -761,  -761,    85,  -761,  -761,  -761,  -761,  -761,
    1111,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,   978,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   835,   836,  1097,  1098,    27,   225,   226,
     227,   228,    28,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,    29,    77,    78,    79,    80,    81,    30,    63,
     504,   505,   506,   507,    31,    70,   587,   588,   589,   590,
     591,   592,    32,   291,   292,   293,   294,   295,  1054,  1055,
    1056,  1057,  1058,  1233,  1308,  1309,    33,    64,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   761,
    1211,  1212,   530,   755,  1182,  1183,    34,    53,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   629,  1081,  1082,
      35,    61,   490,   740,  1153,  1154,   491,   492,   493,  1157,
     998,   999,   494,   495,    36,    59,   468,   469,   470,   471,
     472,   473,   474,   725,  1139,  1140,   475,   476,   477,    37,
      65,   535,   536,   537,   538,   539,    38,   299,   300,   301,
      39,    72,   600,   601,   602,   603,   604,   817,  1251,  1252,
      40,    68,   573,   574,   575,   576,   800,  1228,  1229,    41,
      54,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   652,  1110,  1111,   388,   389,   390,   391,   392,
      42,    60,   481,   482,   483,   484,    43,    55,   396,   397,
     398,   399,    44,   118,   119,   120,    45,    57,   406,   407,
     408,   409,    46,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   439,   961,
     962,   215,   437,   936,   937,   216,   217,   218,    47,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    48,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     863,   864,   614,  1079,   616,   289,   618,   619,   325,    73,
     708,   116,    51,   289,   709,   710,   501,  1108,    52,   711,
      56,   222,   582,   508,   326,   327,   297,    58,   328,   303,
     232,   478,   862,   531,   596,    74,   501,    62,   393,    66,
     485,   509,    75,  1150,   297,    67,  1123,   251,   116,   570,
    1124,   222,   478,    69,   403,  1125,   403,   510,   393,  1126,
     233,  1254,   570,  1050,    71,  1255,  1259,  1263,   234,   532,
    1260,  1264,   113,   252,   114,   596,   329,   117,  1080,  1265,
     235,   236,   115,  1266,  1273,   237,   238,   239,  1274,    49,
      50,   511,   121,   330,   331,   332,   333,   334,   502,   486,
     673,   335,   675,   676,   394,   336,   487,   253,   488,   682,
     240,   337,    76,   686,   117,   533,   254,   690,   502,  1050,
     693,   223,   338,   339,   394,   583,   512,   122,  1280,   298,
     703,   704,   123,   124,   340,   125,   126,   597,   255,   219,
     127,   716,   256,   718,   719,   224,   513,   298,   128,   129,
     257,   223,   571,   258,   259,   130,   341,   404,   131,   404,
     220,   479,   514,   534,   132,   571,  1051,   489,   395,   133,
     134,    73,   135,   136,   137,   224,   138,  1275,   597,   515,
     516,  1276,   479,  -129,   405,   260,   405,  1151,   395,   139,
     140,  -129,   221,   584,   503,   229,  1152,    74,   230,   342,
     141,   231,   261,   288,    75,   262,   263,   264,  1277,   296,
     142,   585,  1278,  1109,   503,   302,  1284,   143,   304,   144,
    1285,   145,  1051,   146,   582,   147,   148,   586,  1311,   517,
      82,   290,  1312,   265,   531,   305,   778,   306,   149,   290,
     605,   643,   307,   150,   151,   152,   579,   153,   154,   155,
     518,   266,   156,    83,    84,   811,   763,   598,   480,    85,
     309,   599,  1052,   548,   735,   459,   769,   819,   581,   750,
     532,   664,   572,   742,    76,   267,   268,   594,   157,   480,
     568,   401,   801,   460,   499,   572,  1053,   670,   158,   159,
     160,   161,   162,   163,    86,    87,  1234,   496,   598,   461,
      88,    89,   599,   485,   867,   868,    90,    91,    92,  1094,
    1095,  1096,   310,   311,    93,    94,   533,   849,  1052,   362,
     312,   363,   854,   364,   313,   857,   314,   583,   315,   861,
     251,   316,   317,   462,  1256,  1257,  1258,   365,   318,    95,
      96,   319,  1053,   164,   165,   166,   320,   167,   168,   321,
     322,   400,   410,   366,  1156,   411,   252,   169,   412,   413,
     457,   414,   486,   415,   534,   416,   417,   418,   419,   487,
     420,   488,   421,   613,   422,   423,   424,   425,   367,   426,
     368,   427,   428,   429,   430,   431,   432,   369,   463,   433,
     253,   434,   435,   436,   438,   584,   464,   465,   370,   254,
     828,   829,   830,   831,   832,   833,   834,   440,   441,   442,
     122,   443,   862,   585,   444,   123,   124,   466,   125,   126,
     445,   255,   371,   127,   446,   256,   447,   448,   449,   586,
     489,   128,   129,   257,   450,   451,   258,   259,   130,   452,
     453,   131,   454,   455,   456,   497,   372,   132,   498,   540,
     541,   542,   133,   134,   543,   135,   136,   137,   544,   138,
     545,   546,   547,   323,   550,   577,   373,   606,   260,   607,
     551,   552,   139,   140,   553,   374,   554,   459,   362,   555,
     363,   556,   364,   141,   557,   261,   558,   559,   262,   263,
     264,  1162,   467,   142,   560,   460,   365,   561,   731,   508,
     143,   562,   144,   563,   145,   564,   146,  1163,   147,   148,
     565,   461,   366,   232,   566,  1164,   265,   509,   567,   578,
     593,   149,   608,   375,   609,   610,   150,   151,   152,  1165,
     153,   154,   155,   510,   266,   156,   611,   367,   612,   368,
     613,   615,   617,   233,   620,   462,   369,   376,   621,   622,
     623,   234,   660,   626,   624,   625,  1129,   370,   267,   268,
    1166,   157,  1167,   235,   236,   645,   627,   511,   237,   238,
     239,   158,   159,   160,   161,   162,   163,  1130,   628,   630,
     631,   371,   632,   633,   634,   635,  1131,   636,  1168,   637,
     638,  1281,   639,   240,   640,   641,   642,   646,   647,   648,
     463,   649,   512,   650,   651,   372,   653,   654,   464,   465,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,  1132,   655,   656,
     657,  1169,   513,  1170,   658,   373,   164,   165,   166,   466,
     167,   168,   659,   662,   374,   663,   666,   667,   514,   668,
     169,   669,  1171,   674,   678,   672,  1133,  1134,   677,   325,
     680,   679,  1218,   681,  1135,   515,   516,     2,     3,   683,
     684,     4,   685,  1172,   687,   326,   327,   688,  1173,   328,
     689,   691,  1174,     5,   692,   694,     6,     7,   695,  1136,
     696,  1175,   375,     8,   697,  1176,   698,  1299,   699,   700,
     702,   701,   715,   721,     9,  1137,  1177,    10,    11,  1178,
     705,  1179,   706,   723,   467,   517,   376,   707,   712,   713,
     714,   717,  1180,   720,  1219,   722,   724,   329,  1300,  1181,
    1301,   726,   737,   744,   727,    12,   518,   745,   774,   780,
      13,   782,   728,   746,   330,   331,   332,   333,   334,    14,
     729,   939,   335,   940,   941,  1220,   336,   730,   783,   733,
     734,   738,   337,  1221,   739,   741,  1138,   747,   748,    15,
      16,   749,  1222,   338,   339,  1302,   752,   753,   754,   771,
     756,   757,   765,   758,   759,   340,   760,    17,   762,   766,
     767,  1189,  1303,  1190,  1191,   768,  1223,   772,  1224,  1225,
     773,   775,   776,   784,    18,   777,   779,   341,   781,   785,
     786,   787,  1226,   788,   789,   790,   791,    19,    20,  1227,
     792,   793,   794,   795,   796,   805,   797,   798,   804,   803,
    1304,  1305,   916,   799,   806,   807,   808,   813,   809,   810,
      21,   816,   818,   847,   814,   848,   851,   815,   821,   822,
     342,   823,   824,    22,   825,   826,   827,   837,    23,   838,
     839,  1241,   840,    24,   841,   842,    25,   843,   844,   942,
     943,   944,   845,   846,   945,   946,   852,   947,   948,   850,
     949,   853,   950,  1306,   855,   951,   856,  1307,   952,   953,
     858,   859,   860,   954,   862,   865,   873,   955,   866,   870,
     869,   956,   957,   958,   871,   872,   876,   881,   959,  1192,
    1193,  1194,   874,   960,  1195,  1196,   875,  1197,  1198,   877,
    1199,   884,  1200,  1242,   878,  1201,   879,   880,  1202,  1203,
     882,   883,   885,  1204,   886,   887,   888,  1205,   889,   890,
     984,  1206,  1207,  1208,    82,   891,   892,   893,  1209,   894,
     917,   918,   919,  1210,  1243,   920,   921,   895,   922,   923,
     896,   924,  1244,   925,   982,   983,   926,    83,    84,   927,
     928,  1245,   897,    85,   929,   898,   899,   900,   930,   901,
     902,   903,   931,   932,   933,   904,   905,   906,   907,   934,
     908,   909,   910,   911,   935,  1246,   912,  1247,  1248,   913,
     985,   914,   986,   987,   988,   989,   915,   938,    86,    87,
     991,  1249,   963,   992,    88,    89,   994,   964,  1250,   995,
      90,    91,    92,   997,   965,   996,   966,   967,    93,    94,
    1003,  1004,   968,   969,  1006,  1009,   970,   971,   812,  1010,
     972,   973,   974,   975,   976,   977,   978,   979,   980,   981,
     990,   993,  1000,    95,    96,  1001,  1002,  1005,  1007,  1011,
    1012,  1008,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1046,  1026,  1027,  1028,  1059,
    1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,
    1039,  1040,  1041,  1042,  1043,  1044,  1045,  1060,  1048,  1049,
    1047,  1061,  1062,  1063,  1065,  1064,  1067,  1267,  1279,  1066,
    1068,  1076,  1077,  1078,   308,  1083,  1084,  1290,  1085,  1086,
    1291,  1292,  1087,  1235,  1088,  1089,  1090,  1091,  1092,  1093,
    1099,  1100,  1101,  1102,   751,  1294,  1103,  1104,   569,  1313,
    1105,  1106,  1293,  1286,  1107,  1112,  1113,  1114,  1115,  1116,
    1117,  1118,  1119,  1120,  1121,  1122,  1127,  1128,  1141,  1142,
    1143,  1144,  1145,  1155,   764,  1146,  1147,  1148,  1289,  1149,
     743,   644,  1268,  1288,  1158,  1159,   770,  1160,  1161,   732,
    1184,  1185,  1186,   820,  1187,  1188,  1213,  1214,  1215,  1216,
    1217,  1230,  1310,   802,  1236,  1231,  1232,  1237,  1238,  1239,
    1240,  1270,  1253,  1269,  1295,  1287,   500,   661,   402,  1271,
     458,   736,  1272,  1283,  1282,  1262,  1296,  1297,   324,  1261,
    1298,     0,   665,     0,     0,     0,   671,     0,     0,   549,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   595
};

static const yytype_int16 yycheck[] =
{
     641,   642,   313,    55,   315,     1,   317,   318,     1,     1,
     216,     1,   235,     1,   220,   216,     1,     8,   235,   220,
     235,     1,     1,     1,    17,    18,     1,   235,    21,   233,
       1,     1,   114,     1,     1,    27,     1,   235,     1,   235,
       1,    19,    34,    51,     1,   235,   233,     1,     1,     1,
     237,     1,     1,   235,     1,   233,     1,    35,     1,   237,
      31,   233,     1,     1,   235,   237,   233,   233,    39,    37,
     237,   237,   235,    27,   235,     1,    69,    67,   130,   233,
      51,    52,   235,   237,   233,    56,    57,    58,   237,   233,
     234,    69,   235,    86,    87,    88,    89,    90,    83,    60,
     411,    94,   413,   414,    67,    98,    67,    61,    69,   420,
      81,   104,   104,   424,    67,    83,    70,   428,    83,     1,
     431,   101,   115,   116,    67,   104,   104,     1,   210,   104,
     441,   442,     6,     7,   127,     9,    10,   104,    92,   235,
      14,   452,    96,   454,   455,   125,   124,   104,    22,    23,
     104,   101,   104,   107,   108,    29,   149,   104,    32,   104,
     235,   131,   140,   131,    38,   104,   104,   128,   131,    43,
      44,     1,    46,    47,    48,   125,    50,   233,   104,   157,
     158,   237,   131,   179,   131,   139,   131,   195,   131,    63,
      64,   179,   235,   172,   179,   235,   204,    27,   235,   192,
      74,   235,   156,   235,    34,   159,   160,   161,   233,   235,
      84,   190,   237,   204,   179,   235,   233,    91,   236,    93,
     237,    95,   104,    97,     1,    99,   100,   206,   233,   207,
       1,   227,   237,   187,     1,   236,   547,   236,   112,   227,
     129,   234,   234,   117,   118,   119,   234,   121,   122,   123,
     228,   205,   126,    24,    25,   234,   234,   224,   228,    30,
     236,   228,   200,   234,   234,     1,   234,   234,   179,   234,
      37,   234,   224,   234,   104,   229,   230,   234,   152,   228,
     234,   234,   234,    19,   234,   224,   224,   234,   162,   163,
     164,   165,   166,   167,    65,    66,   234,   233,   224,    35,
      71,    72,   228,     1,   183,   184,    77,    78,    79,    11,
      12,    13,   236,   236,    85,    86,    83,   628,   200,     1,
     236,     3,   633,     5,   236,   636,   236,   104,   236,   640,
       1,   236,   236,    69,  1094,  1095,  1096,    19,   236,   110,
     111,   236,   224,   217,   218,   219,   236,   221,   222,   236,
     236,   236,   236,    35,   237,   236,    27,   231,   236,   236,
     234,   236,    60,   236,   131,   236,   236,   236,   236,    67,
     236,    69,   236,   114,   236,   236,   236,   236,    60,   236,
      62,   236,   236,   236,   236,   236,   236,    69,   124,   236,
      61,   236,   236,   236,   236,   172,   132,   133,    80,    70,
     141,   142,   143,   144,   145,   146,   147,   236,   236,   236,
       1,   236,   114,   190,   236,     6,     7,   153,     9,    10,
     236,    92,   104,    14,   236,    96,   236,   236,   236,   206,
     128,    22,    23,   104,   236,   236,   107,   108,    29,   236,
     236,    32,   236,   236,   236,   236,   128,    38,   236,   236,
     236,   236,    43,    44,   236,    46,    47,    48,   236,    50,
     236,   236,   236,   234,   233,   233,   148,   129,   139,   129,
     236,   236,    63,    64,   236,   157,   236,     1,     1,   236,
       3,   236,     5,    74,   236,   156,   236,   236,   159,   160,
     161,     4,   228,    84,   236,    19,    19,   236,   234,     1,
      91,   236,    93,   236,    95,   236,    97,    20,    99,   100,
     236,    35,    35,     1,   236,    28,   187,    19,   236,   236,
     236,   112,   233,   205,   114,   114,   117,   118,   119,    42,
     121,   122,   123,    35,   205,   126,   216,    60,   114,    62,
     114,   114,   114,    31,   114,    69,    69,   229,   114,   216,
     216,    39,   234,   236,   233,   233,    15,    80,   229,   230,
      73,   152,    75,    51,    52,   233,   236,    69,    56,    57,
      58,   162,   163,   164,   165,   166,   167,    36,   236,   236,
     236,   104,   236,   236,   236,   236,    45,   236,   101,   236,
     236,  1232,   236,    81,   236,   236,   236,   236,   236,   236,
     124,   236,   104,   236,   236,   128,   236,   236,   132,   133,
     828,   829,   830,   831,   832,   833,   834,    76,   236,   236,
     236,   134,   124,   136,   236,   148,   217,   218,   219,   153,
     221,   222,   236,   236,   157,   236,   129,   233,   140,   236,
     231,   236,   155,   114,   114,   216,   105,   106,   216,     1,
     114,   216,    75,   216,   113,   157,   158,     0,     1,   216,
     114,     4,   114,   176,   114,    17,    18,   216,   181,    21,
     216,   114,   185,    16,   114,   114,    19,    20,   114,   138,
     114,   194,   205,    26,   114,   198,   216,    42,   236,   216,
     216,   236,   114,   233,    37,   154,   209,    40,    41,   212,
     216,   214,   216,   236,   228,   207,   229,   216,   216,   216,
     216,   216,   225,   216,   137,   233,   236,    69,    73,   232,
      75,   236,   233,   129,   236,    68,   228,   129,   129,   129,
      73,   129,   236,   233,    86,    87,    88,    89,    90,    82,
     236,    51,    94,    53,    54,   168,    98,   236,   114,   236,
     236,   236,   104,   176,   236,   236,   215,   233,   236,   102,
     103,   236,   185,   115,   116,   120,   233,   236,   236,   216,
     236,   236,   233,   236,   236,   127,   236,   120,   236,   236,
     236,    51,   137,    53,    54,   236,   209,   216,   211,   212,
     216,   216,   216,   114,   137,   216,   233,   149,   216,   129,
     129,   129,   225,   129,   129,   129,   129,   150,   151,   232,
     129,   114,   129,   129,   129,   235,   233,   233,   233,   216,
     175,   176,    51,   236,   233,   236,   236,   129,   236,   236,
     173,   236,   236,   114,   233,   114,   114,   233,   233,   233,
     192,   233,   233,   186,   233,   233,   233,   233,   191,   233,
     233,    75,   233,   196,   233,   233,   199,   233,   233,   169,
     170,   171,   233,   233,   174,   175,   114,   177,   178,   236,
     180,   114,   182,   228,   114,   185,   114,   232,   188,   189,
     129,   114,   114,   193,   114,   233,   236,   197,   129,   216,
     129,   201,   202,   203,   129,   129,   114,   233,   208,   169,
     170,   171,   129,   213,   174,   175,   129,   177,   178,   129,
     180,   233,   182,   137,   129,   185,   129,   129,   188,   189,
     129,   129,   233,   193,   129,   129,   233,   197,   233,   233,
     236,   201,   202,   203,     1,   233,   233,   233,   208,   233,
     169,   170,   171,   213,   168,   174,   175,   233,   177,   178,
     233,   180,   176,   182,   129,   216,   185,    24,    25,   188,
     189,   185,   233,    30,   193,   233,   233,   233,   197,   233,
     233,   233,   201,   202,   203,   233,   233,   233,   233,   208,
     233,   233,   233,   233,   213,   209,   233,   211,   212,   233,
     129,   233,   114,   129,   129,   129,   233,   233,    65,    66,
     129,   225,   233,   129,    71,    72,   129,   233,   232,   129,
      77,    78,    79,   114,   233,   236,   233,   233,    85,    86,
     129,   129,   233,   233,   129,   129,   233,   233,   587,   129,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   110,   111,   233,   233,   233,   216,   129,
     129,   236,   216,   236,   129,   233,   129,   129,   129,   233,
     233,   233,   233,   233,   233,   129,   233,   233,   233,   129,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   129,   233,   233,
     236,   129,   129,   233,   129,   233,   129,   114,   129,   236,
     233,   233,   233,   233,    77,   233,   233,   135,   233,   233,
     135,   135,   233,  1054,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   504,  1276,   233,   233,   269,  1312,
     233,   233,  1274,  1255,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   223,   519,   233,   233,   233,  1266,   233,
     491,   343,  1156,  1264,   233,   233,   535,   233,   233,   468,
     233,   233,   233,   600,   233,   233,   233,   233,   233,   233,
     233,   233,  1285,   573,   233,   236,   236,   233,   233,   233,
     233,   238,   233,   233,  1278,  1260,   225,   377,   118,   238,
     170,   481,   238,   233,   236,  1126,   233,   233,    97,  1124,
     233,    -1,   396,    -1,    -1,    -1,   406,    -1,    -1,   241,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   291,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   299
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   240,     0,     1,     4,    16,    19,    20,    26,    37,
      40,    41,    68,    73,    82,   102,   103,   120,   137,   150,
     151,   173,   186,   191,   196,   199,   241,   246,   251,   271,
     277,   283,   291,   305,   325,   349,   363,   378,   385,   389,
     399,   408,   429,   435,   441,   445,   451,   507,   524,   233,
     234,   235,   235,   326,   409,   436,   235,   446,   235,   364,
     430,   350,   235,   278,   306,   379,   235,   235,   400,   235,
     284,   235,   390,     1,    27,    34,   104,   272,   273,   274,
     275,   276,     1,    24,    25,    30,    65,    66,    71,    72,
      77,    78,    79,    85,    86,   110,   111,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   235,   235,   235,     1,    67,   442,   443,
     444,   235,     1,     6,     7,     9,    10,    14,    22,    23,
      29,    32,    38,    43,    44,    46,    47,    48,    50,    63,
      64,    74,    84,    91,    93,    95,    97,    99,   100,   112,
     117,   118,   119,   121,   122,   123,   126,   152,   162,   163,
     164,   165,   166,   167,   217,   218,   219,   221,   222,   231,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   500,   504,   505,   506,   235,
     235,   235,     1,   101,   125,   247,   248,   249,   250,   235,
     235,   235,     1,    31,    39,    51,    52,    56,    57,    58,
      81,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,     1,    27,    61,    70,    92,    96,   104,   107,   108,
     139,   156,   159,   160,   161,   187,   205,   229,   230,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   235,     1,
     227,   292,   293,   294,   295,   296,   235,     1,   104,   386,
     387,   388,   235,   233,   236,   236,   236,   234,   273,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   234,   509,     1,    17,    18,    21,    69,
      86,    87,    88,    89,    90,    94,    98,   104,   115,   116,
     127,   149,   192,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,     1,     3,     5,    19,    35,    60,    62,    69,
      80,   104,   128,   148,   157,   205,   229,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   424,   425,
     426,   427,   428,     1,    67,   131,   437,   438,   439,   440,
     236,   234,   443,     1,   104,   131,   447,   448,   449,   450,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   501,   236,   497,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   234,   453,     1,
      19,    35,    69,   124,   132,   133,   153,   228,   365,   366,
     367,   368,   369,   370,   371,   375,   376,   377,     1,   131,
     228,   431,   432,   433,   434,     1,    60,    67,    69,   128,
     351,   355,   356,   357,   361,   362,   233,   236,   236,   234,
     248,     1,    83,   179,   279,   280,   281,   282,     1,    19,
      35,    69,   104,   124,   140,   157,   158,   207,   228,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     321,     1,    37,    83,   131,   380,   381,   382,   383,   384,
     236,   236,   236,   236,   236,   236,   236,   236,   234,   526,
     233,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   234,   253,
       1,   104,   224,   401,   402,   403,   404,   233,   236,   234,
     293,   179,     1,   104,   172,   190,   206,   285,   286,   287,
     288,   289,   290,   236,   234,   387,     1,   104,   224,   228,
     391,   392,   393,   394,   395,   129,   129,   129,   233,   114,
     114,   216,   114,   114,   243,   114,   243,   114,   243,   243,
     114,   114,   216,   216,   233,   233,   236,   236,   236,   346,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   234,   328,   233,   236,   236,   236,   236,
     236,   236,   421,   236,   236,   236,   236,   236,   236,   236,
     234,   411,   236,   236,   234,   438,   129,   233,   236,   236,
     234,   448,   216,   243,   114,   243,   243,   216,   114,   216,
     114,   216,   243,   216,   114,   114,   243,   114,   216,   216,
     243,   114,   114,   243,   114,   114,   114,   114,   216,   236,
     216,   236,   216,   243,   243,   216,   216,   216,   216,   220,
     216,   220,   216,   216,   216,   114,   243,   216,   243,   243,
     216,   233,   233,   236,   236,   372,   236,   236,   236,   236,
     236,   234,   366,   236,   236,   234,   432,   233,   236,   236,
     352,   236,   234,   356,   129,   129,   233,   233,   236,   236,
     234,   280,   233,   236,   236,   322,   236,   236,   236,   236,
     236,   318,   236,   234,   308,   233,   236,   236,   236,   234,
     381,   216,   216,   216,   129,   216,   216,   216,   243,   233,
     129,   216,   129,   114,   114,   129,   129,   129,   129,   129,
     129,   129,   129,   114,   129,   129,   129,   233,   233,   236,
     405,   234,   402,   216,   233,   235,   233,   236,   236,   236,
     236,   234,   286,   129,   233,   233,   236,   396,   236,   234,
     392,   233,   233,   233,   233,   233,   233,   233,   141,   142,
     143,   144,   145,   146,   147,   242,   243,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   114,   114,   243,
     236,   114,   114,   114,   243,   114,   114,   243,   129,   114,
     114,   243,   114,   245,   245,   233,   129,   183,   184,   129,
     216,   129,   129,   236,   129,   129,   114,   129,   129,   129,
     129,   233,   129,   129,   233,   233,   129,   129,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,    51,   169,   170,   171,
     174,   175,   177,   178,   180,   182,   185,   188,   189,   193,
     197,   201,   202,   203,   208,   213,   502,   503,   233,    51,
      53,    54,   169,   170,   171,   174,   175,   177,   178,   180,
     182,   185,   188,   189,   193,   197,   201,   202,   203,   208,
     213,   498,   499,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   129,   216,   236,   129,   114,   129,   129,   129,
     233,   129,   129,   233,   129,   129,   236,   114,   359,   360,
     233,   233,   233,   129,   129,   233,   129,   216,   236,   129,
     129,   129,   129,   216,   236,   129,   233,   129,   129,   129,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   129,   236,   233,   233,
       1,   104,   200,   224,   297,   298,   299,   300,   301,   129,
     129,   129,   129,   233,   233,   129,   236,   129,   233,   242,
     242,   242,   242,   242,   242,   242,   233,   233,   233,    55,
     130,   347,   348,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,    11,    12,    13,   244,   245,   233,
     233,   233,   233,   233,   233,   233,   233,   233,     8,   204,
     422,   423,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   237,   233,   237,   233,   233,    15,
      36,    45,    76,   105,   106,   113,   138,   154,   215,   373,
     374,   233,   233,   233,   233,   233,   233,   233,   233,   233,
      51,   195,   204,   353,   354,   223,   237,   358,   233,   233,
     233,   233,     4,    20,    28,    42,    73,    75,   101,   134,
     136,   155,   176,   181,   185,   194,   198,   209,   212,   214,
     225,   232,   323,   324,   233,   233,   233,   233,   233,    51,
      53,    54,   169,   170,   171,   174,   175,   177,   178,   180,
     182,   185,   188,   189,   193,   197,   201,   202,   203,   208,
     213,   319,   320,   233,   233,   233,   233,   233,    75,   137,
     168,   176,   185,   209,   211,   212,   225,   232,   406,   407,
     233,   236,   236,   302,   234,   298,   233,   233,   233,   233,
     233,    75,   137,   168,   176,   185,   209,   211,   212,   225,
     232,   397,   398,   233,   233,   237,   244,   244,   244,   233,
     237,   503,   499,   233,   237,   233,   237,   114,   360,   233,
     238,   238,   238,   233,   237,   233,   237,   233,   237,   129,
     210,   245,   236,   233,   233,   237,   348,   423,   374,   354,
     135,   135,   135,   324,   320,   407,   233,   233,   233,    42,
      73,    75,   120,   137,   175,   176,   228,   232,   303,   304,
     398,   233,   237,   304
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   239,   240,   240,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   242,   242,
     243,   243,   243,   243,   243,   243,   243,   243,   244,   244,
     245,   245,   245,   245,   246,   247,   247,   248,   248,   248,
     249,   250,   251,   252,   252,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   272,   273,   273,   273,   273,   274,   275,   276,
     278,   277,   279,   279,   280,   280,   280,   281,   282,   284,
     283,   285,   285,   286,   286,   286,   286,   286,   287,   288,
     289,   290,   291,   292,   292,   293,   293,   293,   294,   296,
     295,   297,   297,   298,   298,   298,   298,   299,   300,   300,
     302,   301,   303,   303,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   306,   305,   307,   307,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   318,   317,   319,   319,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   322,   321,   323,   323,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   326,
     325,   327,   327,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   346,   345,   347,
     347,   348,   348,   350,   349,   352,   351,   353,   353,   354,
     354,   354,   355,   355,   356,   356,   356,   356,   356,   358,
     357,   359,   359,   360,   360,   361,   362,   364,   363,   365,
     365,   366,   366,   366,   366,   366,   366,   366,   366,   366,
     367,   368,   369,   370,   372,   371,   373,   373,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   375,   376,
     377,   379,   378,   380,   380,   381,   381,   381,   381,   382,
     383,   384,   385,   386,   386,   387,   387,   388,   390,   389,
     391,   391,   392,   392,   392,   392,   393,   394,   396,   395,
     397,   397,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   400,   399,   401,   401,   402,   402,   402,   403,
     405,   404,   406,   406,   407,   407,   407,   407,   407,   407,
     407,   407,   407,   407,   409,   408,   410,   410,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   419,   421,   420,   422,   422,   423,   423,   424,   425,
     426,   427,   428,   430,   429,   431,   431,   432,   432,   432,
     433,   434,   436,   435,   437,   437,   438,   438,   438,   439,
     440,   441,   442,   442,   443,   443,   444,   446,   445,   447,
     447,   448,   448,   448,   449,   450,   451,   452,   452,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   481,   482,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   497,   496,   498,   498,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   501,   500,   502,
     502,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   504,   505,   506,   507,   508,   508,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   525,   526,
     526,   526,   526,   526,   526,   526,   526,   526,   527,   528,
     529,   530,   531,   532,   533,   534
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     0,     6,     0,     5,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     0,
       5,     3,     1,     1,     3,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     2,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     4,     4,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
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
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 430 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 431 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 432 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 433 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 434 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 448 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 454 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 484 "conf_parser.y" /* yacc.c:1646  */
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
#line 3007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 524 "conf_parser.y" /* yacc.c:1646  */
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
#line 3068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 582 "conf_parser.y" /* yacc.c:1646  */
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
#line 3100 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 611 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 619 "conf_parser.y" /* yacc.c:1646  */
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
#line 3128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 633 "conf_parser.y" /* yacc.c:1646  */
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
#line 3159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 661 "conf_parser.y" /* yacc.c:1646  */
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
#line 3177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 676 "conf_parser.y" /* yacc.c:1646  */
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
#line 3195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 691 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 701 "conf_parser.y" /* yacc.c:1646  */
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
#line 3225 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 715 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 724 "conf_parser.y" /* yacc.c:1646  */
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
#line 3268 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 752 "conf_parser.y" /* yacc.c:1646  */
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
#line 3299 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 780 "conf_parser.y" /* yacc.c:1646  */
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
#line 3327 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 805 "conf_parser.y" /* yacc.c:1646  */
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
#line 3352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 827 "conf_parser.y" /* yacc.c:1646  */
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
#line 3377 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 849 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3386 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 866 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 875 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 884 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 896 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3431 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 900 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 917 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 923 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3466 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 932 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3475 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 936 "conf_parser.y" /* yacc.c:1646  */
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
#line 3493 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 954 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 960 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 966 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 972 "conf_parser.y" /* yacc.c:1646  */
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
#line 3543 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1001 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3552 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1007 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3561 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1011 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1035 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3593 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1038 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3601 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1043 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3610 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1050 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3628 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3637 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1062 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3646 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3655 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3664 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1074 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1078 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1082 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1092 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3703 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1099 "conf_parser.y" /* yacc.c:1646  */
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
#line 3785 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3803 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1203 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3812 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1209 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3826 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3835 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1226 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3844 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1260 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1264 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1300 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1312 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4011 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1316 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4020 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1328 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4065 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1346 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1361 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1365 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1369 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1373 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1377 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1381 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4155 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1385 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1389 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1393 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1397 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1401 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1405 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1409 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1413 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4227 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1417 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1421 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1425 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1429 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1433 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1437 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4281 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4290 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1451 "conf_parser.y" /* yacc.c:1646  */
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
#line 4307 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1463 "conf_parser.y" /* yacc.c:1646  */
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
#line 4360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1532 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1538 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1544 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1550 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1556 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1562 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1568 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1574 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1580 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1586 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1592 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1599 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1605 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1611 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1617 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4499 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1626 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1635 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1642 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1646 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4538 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1656 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1662 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1668 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4564 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1672 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1676 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1684 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4588 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1689 "conf_parser.y" /* yacc.c:1646  */
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
#line 4606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1702 "conf_parser.y" /* yacc.c:1646  */
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
#line 4626 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1719 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4635 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1725 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4644 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1734 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4653 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1738 "conf_parser.y" /* yacc.c:1646  */
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
#line 4694 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1787 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4703 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1793 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4712 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1799 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1805 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4735 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1816 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4744 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1823 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4753 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1827 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1831 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4771 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4780 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1839 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4789 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4798 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1847 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4807 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1855 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4834 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1865 "conf_parser.y" /* yacc.c:1646  */
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
#line 4851 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1879 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1888 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1901 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1908 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1919 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1931 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1946 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1961 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1972 "conf_parser.y" /* yacc.c:1646  */
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
#line 4973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1989 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1995 "conf_parser.y" /* yacc.c:1646  */
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
#line 5004 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 2014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5013 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5022 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5031 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5049 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5058 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5067 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5076 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2075 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5132 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2090 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5141 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2096 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2103 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2111 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2115 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2123 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2127 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2131 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2135 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2139 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2148 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2157 "conf_parser.y" /* yacc.c:1646  */
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

  case 413:
#line 2237 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5329 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5347 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2255 "conf_parser.y" /* yacc.c:1646  */
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

  case 417:
#line 2268 "conf_parser.y" /* yacc.c:1646  */
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

  case 418:
#line 2281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2303 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2319 "conf_parser.y" /* yacc.c:1646  */
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

  case 429:
#line 2330 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2342 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2348 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2363 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2367 "conf_parser.y" /* yacc.c:1646  */
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

  case 440:
#line 2392 "conf_parser.y" /* yacc.c:1646  */
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

  case 441:
#line 2412 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5562 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2421 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2425 "conf_parser.y" /* yacc.c:1646  */
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

  case 449:
#line 2451 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2457 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2471 "conf_parser.y" /* yacc.c:1646  */
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
#line 5632 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2488 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5641 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2492 "conf_parser.y" /* yacc.c:1646  */
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
#line 5663 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 464:
#line 2514 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5672 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2520 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5681 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2583 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5689 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2588 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2593 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2598 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2604 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.glines = yylval.number;
}
#line 5723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2610 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_time = (yyvsp[-1].number);
}
#line 5732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2616 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_request_time = (yyvsp[-1].number);
}
#line 5741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2622 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr = (yyvsp[-1].number);
}
#line 5749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2627 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2632 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2637 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2642 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5781 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5789 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2652 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5797 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2657 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5805 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2662 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5813 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2667 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5821 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2672 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5829 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2677 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2682 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2688 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5860 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2699 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2704 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2709 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2714 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2719 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2724 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2729 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2732 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2737 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5932 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2740 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2745 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2750 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2755 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2760 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2765 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5980 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2770 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5988 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2775 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_pass_resv = yylval.number;
}
#line 5996 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 6004 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2785 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2790 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6020 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6028 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2800 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6036 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2805 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6060 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6076 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6100 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6108 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6132 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6140 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6148 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6172 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2861 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6180 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2864 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2867 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2870 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2873 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2876 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6220 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2879 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2884 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6244 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2893 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6252 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2896 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6260 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2899 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6268 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2902 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6276 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6284 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2908 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6292 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2911 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2914 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6308 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2917 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6316 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2920 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2923 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6332 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2926 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2929 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2932 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2935 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2938 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2941 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6380 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2944 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2947 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2952 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6404 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2957 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6412 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2962 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2991 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2996 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6436 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 3001 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 3006 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3011 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3016 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3021 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 3026 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6484 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 3031 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3036 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3041 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6508 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3046 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6516 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 3051 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6524 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3056 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3078 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3084 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3090 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3096 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6568 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3102 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6580 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3111 "conf_parser.y" /* yacc.c:1646  */
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
#line 6598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3126 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3132 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6616 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6620 "conf_parser.c" /* yacc.c:1646  */
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
