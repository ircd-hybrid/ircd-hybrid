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
    DEFAULT_SPLIT_SERVER_COUNT = 279,
    DEFAULT_SPLIT_USER_COUNT = 280,
    DENY = 281,
    DESCRIPTION = 282,
    DIE = 283,
    DISABLE_AUTH = 284,
    DISABLE_FAKE_CHANNELS = 285,
    DISABLE_REMOTE_COMMANDS = 286,
    DOTS_IN_IDENT = 287,
    EMAIL = 288,
    ENCRYPTED = 289,
    EXCEED_LIMIT = 290,
    EXEMPT = 291,
    FAILED_OPER_NOTICE = 292,
    FLATTEN_LINKS = 293,
    GECOS = 294,
    GENERAL = 295,
    GLINE = 296,
    GLINE_DURATION = 297,
    GLINE_ENABLE = 298,
    GLINE_EXEMPT = 299,
    GLINE_MIN_CIDR = 300,
    GLINE_MIN_CIDR6 = 301,
    GLINE_REQUEST_DURATION = 302,
    GLOBAL_KILL = 303,
    HAVENT_READ_CONF = 304,
    HIDDEN = 305,
    HIDDEN_NAME = 306,
    HIDE_CHANS = 307,
    HIDE_IDLE = 308,
    HIDE_IDLE_FROM_OPERS = 309,
    HIDE_SERVER_IPS = 310,
    HIDE_SERVERS = 311,
    HIDE_SERVICES = 312,
    HIDE_SPOOF_IPS = 313,
    HOST = 314,
    HUB = 315,
    HUB_MASK = 316,
    IGNORE_BOGUS_TS = 317,
    INVISIBLE_ON_CONNECT = 318,
    INVITE_CLIENT_COUNT = 319,
    INVITE_CLIENT_TIME = 320,
    IP = 321,
    IRCD_AUTH = 322,
    IRCD_FLAGS = 323,
    IRCD_SID = 324,
    JOIN_FLOOD_COUNT = 325,
    JOIN_FLOOD_TIME = 326,
    KILL = 327,
    KILL_CHASE_TIME_LIMIT = 328,
    KLINE = 329,
    KLINE_EXEMPT = 330,
    KNOCK_CLIENT_COUNT = 331,
    KNOCK_CLIENT_TIME = 332,
    KNOCK_DELAY_CHANNEL = 333,
    LEAF_MASK = 334,
    LINKS_DELAY = 335,
    LISTEN = 336,
    MASK = 337,
    MAX_ACCEPT = 338,
    MAX_BANS = 339,
    MAX_CHANNELS = 340,
    MAX_GLOBAL = 341,
    MAX_IDENT = 342,
    MAX_IDLE = 343,
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
    NO_CREATE_ON_SPLIT = 364,
    NO_JOIN_ON_SPLIT = 365,
    NO_OPER_FLOOD = 366,
    NO_TILDE = 367,
    NUMBER = 368,
    NUMBER_PER_CIDR = 369,
    NUMBER_PER_IP = 370,
    OPER_ONLY_UMODES = 371,
    OPER_PASS_RESV = 372,
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
    RSA_PUBLIC_KEY_FILE = 394,
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
    T_MAX_CLIENTS = 442,
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
#define EMAIL 288
#define ENCRYPTED 289
#define EXCEED_LIMIT 290
#define EXEMPT 291
#define FAILED_OPER_NOTICE 292
#define FLATTEN_LINKS 293
#define GECOS 294
#define GENERAL 295
#define GLINE 296
#define GLINE_DURATION 297
#define GLINE_ENABLE 298
#define GLINE_EXEMPT 299
#define GLINE_MIN_CIDR 300
#define GLINE_MIN_CIDR6 301
#define GLINE_REQUEST_DURATION 302
#define GLOBAL_KILL 303
#define HAVENT_READ_CONF 304
#define HIDDEN 305
#define HIDDEN_NAME 306
#define HIDE_CHANS 307
#define HIDE_IDLE 308
#define HIDE_IDLE_FROM_OPERS 309
#define HIDE_SERVER_IPS 310
#define HIDE_SERVERS 311
#define HIDE_SERVICES 312
#define HIDE_SPOOF_IPS 313
#define HOST 314
#define HUB 315
#define HUB_MASK 316
#define IGNORE_BOGUS_TS 317
#define INVISIBLE_ON_CONNECT 318
#define INVITE_CLIENT_COUNT 319
#define INVITE_CLIENT_TIME 320
#define IP 321
#define IRCD_AUTH 322
#define IRCD_FLAGS 323
#define IRCD_SID 324
#define JOIN_FLOOD_COUNT 325
#define JOIN_FLOOD_TIME 326
#define KILL 327
#define KILL_CHASE_TIME_LIMIT 328
#define KLINE 329
#define KLINE_EXEMPT 330
#define KNOCK_CLIENT_COUNT 331
#define KNOCK_CLIENT_TIME 332
#define KNOCK_DELAY_CHANNEL 333
#define LEAF_MASK 334
#define LINKS_DELAY 335
#define LISTEN 336
#define MASK 337
#define MAX_ACCEPT 338
#define MAX_BANS 339
#define MAX_CHANNELS 340
#define MAX_GLOBAL 341
#define MAX_IDENT 342
#define MAX_IDLE 343
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
#define NO_CREATE_ON_SPLIT 364
#define NO_JOIN_ON_SPLIT 365
#define NO_OPER_FLOOD 366
#define NO_TILDE 367
#define NUMBER 368
#define NUMBER_PER_CIDR 369
#define NUMBER_PER_IP 370
#define OPER_ONLY_UMODES 371
#define OPER_PASS_RESV 372
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
#define RSA_PUBLIC_KEY_FILE 394
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
#define T_MAX_CLIENTS 442
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
#define XLINE 487

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 152 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 699 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 716 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1373

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  239
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  297
/* YYNRULES -- Number of rules.  */
#define YYNRULES  668
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1320

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
    1408,  1412,  1416,  1420,  1424,  1428,  1432,  1436,  1440,  1444,
    1455,  1454,  1516,  1516,  1517,  1518,  1519,  1520,  1521,  1522,
    1523,  1524,  1525,  1526,  1527,  1528,  1529,  1529,  1530,  1531,
    1532,  1533,  1535,  1541,  1547,  1553,  1559,  1565,  1571,  1577,
    1583,  1589,  1595,  1602,  1608,  1614,  1620,  1629,  1639,  1638,
    1644,  1644,  1645,  1649,  1660,  1659,  1666,  1665,  1670,  1670,
    1671,  1675,  1679,  1685,  1685,  1686,  1686,  1686,  1686,  1686,
    1688,  1688,  1690,  1690,  1692,  1705,  1722,  1728,  1738,  1737,
    1779,  1779,  1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,
    1788,  1790,  1796,  1802,  1808,  1820,  1819,  1825,  1825,  1826,
    1830,  1834,  1838,  1842,  1846,  1850,  1854,  1858,  1862,  1868,
    1882,  1891,  1905,  1904,  1919,  1919,  1920,  1920,  1920,  1920,
    1922,  1928,  1934,  1944,  1946,  1946,  1947,  1947,  1949,  1965,
    1964,  1989,  1989,  1990,  1990,  1990,  1990,  1992,  1998,  2018,
    2017,  2023,  2023,  2024,  2028,  2032,  2036,  2040,  2044,  2048,
    2052,  2056,  2060,  2070,  2069,  2090,  2090,  2091,  2091,  2091,
    2093,  2100,  2099,  2105,  2105,  2106,  2110,  2114,  2118,  2122,
    2126,  2130,  2134,  2138,  2142,  2152,  2151,  2223,  2223,  2224,
    2225,  2226,  2227,  2228,  2229,  2230,  2231,  2232,  2233,  2234,
    2235,  2236,  2237,  2238,  2240,  2246,  2252,  2258,  2271,  2284,
    2290,  2296,  2300,  2307,  2306,  2311,  2311,  2312,  2316,  2322,
    2333,  2339,  2345,  2351,  2367,  2366,  2392,  2392,  2393,  2393,
    2393,  2395,  2415,  2425,  2424,  2451,  2451,  2452,  2452,  2452,
    2454,  2460,  2469,  2471,  2471,  2472,  2472,  2474,  2492,  2491,
    2514,  2514,  2515,  2515,  2515,  2517,  2523,  2532,  2535,  2535,
    2536,  2537,  2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,
    2546,  2547,  2548,  2549,  2550,  2551,  2552,  2553,  2554,  2555,
    2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,  2564,  2565,
    2566,  2567,  2568,  2569,  2570,  2571,  2572,  2573,  2574,  2575,
    2576,  2577,  2578,  2579,  2580,  2581,  2582,  2583,  2584,  2587,
    2592,  2597,  2602,  2608,  2614,  2620,  2626,  2631,  2636,  2641,
    2646,  2651,  2656,  2661,  2666,  2671,  2676,  2681,  2686,  2692,
    2703,  2708,  2713,  2718,  2723,  2728,  2733,  2738,  2741,  2746,
    2749,  2754,  2759,  2764,  2769,  2774,  2779,  2784,  2789,  2794,
    2799,  2804,  2809,  2814,  2820,  2819,  2824,  2824,  2825,  2828,
    2831,  2834,  2837,  2840,  2843,  2846,  2849,  2852,  2855,  2858,
    2861,  2864,  2867,  2870,  2873,  2876,  2879,  2882,  2885,  2888,
    2894,  2893,  2898,  2898,  2899,  2902,  2905,  2908,  2911,  2914,
    2917,  2920,  2923,  2926,  2929,  2932,  2935,  2938,  2941,  2944,
    2947,  2950,  2953,  2956,  2961,  2966,  2971,  2980,  2983,  2983,
    2984,  2985,  2986,  2987,  2988,  2989,  2990,  2991,  2992,  2993,
    2994,  2995,  2996,  2997,  2998,  3000,  3005,  3010,  3015,  3020,
    3025,  3030,  3035,  3040,  3045,  3050,  3055,  3060,  3065,  3073,
    3076,  3076,  3077,  3078,  3079,  3080,  3081,  3082,  3083,  3084,
    3085,  3087,  3093,  3099,  3105,  3111,  3120,  3135,  3141
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
  "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT", "EMAIL", "ENCRYPTED",
  "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "GECOS",
  "GENERAL", "GLINE", "GLINE_DURATION", "GLINE_ENABLE", "GLINE_EXEMPT",
  "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6", "GLINE_REQUEST_DURATION",
  "GLOBAL_KILL", "HAVENT_READ_CONF", "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS",
  "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS", "HIDE_SERVERS",
  "HIDE_SERVICES", "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT",
  "INVITE_CLIENT_TIME", "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID",
  "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "KILL", "KILL_CHASE_TIME_LIMIT",
  "KLINE", "KLINE_EXEMPT", "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME",
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
     485,   486,   487,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -946

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-946)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -946,   637,  -946,  -199,  -224,  -217,  -946,  -946,  -946,  -198,
    -946,  -186,  -946,  -946,  -946,  -181,  -946,  -946,  -946,  -180,
    -169,  -946,  -167,  -946,  -154,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,    55,   885,  -143,  -137,  -131,    14,  -130,   397,  -124,
    -116,   -92,    86,   -89,   -60,   -48,   336,   437,   -45,    39,
     -32,    23,   -13,   -21,    -8,    -6,     9,    19,  -946,  -946,
    -946,  -946,  -946,    43,    57,    68,    77,    78,    80,    89,
      91,   100,   102,   105,   107,   110,   117,   224,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,   634,   568,    20,  -946,   120,     7,  -946,
    -946,    18,  -946,   129,   133,   134,   136,   139,   140,   143,
     144,   145,   146,   147,   152,   153,   159,   160,   161,   164,
     166,   173,   174,   177,   178,   181,   186,   188,   189,   191,
    -946,   195,  -946,   196,   199,   205,   213,   214,   215,   218,
     219,   220,   225,   226,   227,   230,   235,   236,   237,   239,
     240,    16,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,   414,    35,   281,    -2,   242,   243,    40,  -946,  -946,
    -946,   138,   344,   275,  -946,   245,   248,   250,   252,   256,
     258,   262,   263,   304,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,    22,   266,   267,   268,   271,   273,   274,
     276,   280,   284,   290,   291,   293,   294,   295,   300,   311,
     314,    56,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
      71,    34,   315,    30,  -946,  -946,  -946,   128,   194,  -946,
     317,    69,  -946,  -946,     4,  -946,   203,   302,   383,   308,
    -946,   441,   442,   340,   443,   452,   455,   452,   457,   452,
     452,   461,   463,   361,   362,   352,  -946,   353,   354,   355,
     357,  -946,   363,   364,   365,   368,   369,   378,   382,   385,
     386,   387,   390,   395,   404,   184,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,   356,   409,   413,   418,   422,   424,
     425,  -946,   429,   433,   434,   436,   438,   444,   453,   165,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,   454,   456,    27,  -946,
    -946,  -946,   460,   400,  -946,  -946,   462,   465,    46,  -946,
    -946,  -946,   381,   452,   537,   452,   452,   474,   565,   476,
     566,   479,   452,   480,   586,   590,   452,   592,   489,   490,
     452,   597,   599,   452,   603,   612,   615,   616,   513,   496,
     516,   499,   519,   452,   452,   523,   524,   529,  -205,  -188,
     530,   533,   534,   536,   644,   452,   542,   452,   452,   544,
     539,  -946,   543,   526,   527,  -946,   531,   541,   545,   547,
     549,   305,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,   552,   553,    31,  -946,  -946,  -946,   546,   555,
     556,  -946,   559,  -946,     8,  -946,  -946,  -946,  -946,  -946,
     638,   641,   561,  -946,   563,   562,   564,    12,  -946,  -946,
    -946,   569,   567,   570,  -946,   571,   572,   573,   575,   576,
    -946,   577,    50,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,   581,   579,   580,   582,    41,  -946,
    -946,  -946,  -946,   548,   584,   587,   647,   588,   600,   602,
     452,   589,  -946,  -946,   650,   604,   652,   686,   707,   696,
     697,   698,   700,   705,   712,   714,   716,   732,   719,   720,
     723,   619,  -946,   620,   618,  -946,    95,  -946,  -946,  -946,
    -946,   639,   624,  -946,   623,   627,   625,   626,   630,   631,
      49,  -946,  -946,  -946,  -946,  -946,   740,   636,  -946,   645,
     649,  -946,   653,    94,  -946,  -946,  -946,  -946,   648,   655,
     659,  -946,   660,   662,   664,   665,   467,   666,   668,   669,
     670,   674,   675,   689,   691,   693,   694,  -946,  -946,   761,
     770,   452,   658,   806,   816,   817,   452,   820,   821,   452,
     807,   823,   825,   452,   826,   826,   709,  -946,  -946,   812,
    -140,   815,   727,   830,   831,   715,   832,   836,   835,   837,
     838,   839,   840,   721,  -946,   843,   844,   741,  -946,   742,
    -946,   845,   848,   744,  -946,   745,   746,   747,   748,   749,
     750,   751,   752,   753,   754,   755,   756,   757,   758,   759,
     760,   763,   764,   765,   766,   767,   768,   769,   771,   772,
     773,   774,   743,   775,   661,   776,   777,   778,   779,   780,
     781,   782,   783,   784,   785,   786,   787,   788,   789,   790,
     791,   792,   793,   794,   795,  -946,  -946,   875,   736,   796,
     901,   917,   903,   905,   906,   802,  -946,   908,   909,   805,
    -946,  -946,   911,   912,   808,   928,   809,  -946,   810,   813,
    -946,  -946,   919,   920,   818,  -946,  -946,   921,   828,   814,
     924,   925,   926,   927,   841,   824,   929,   829,  -946,  -946,
     931,   933,   935,   833,  -946,   834,   842,   846,   847,   849,
     850,   851,   852,  -946,   853,   854,   855,   856,   857,   858,
     859,   860,   861,   862,   863,   864,   865,   866,   867,   868,
     869,  -946,  -946,   936,   870,   871,  -946,   872,  -946,    90,
    -946,   937,   940,   941,   942,   874,  -946,   876,  -946,  -946,
     943,   877,   944,   878,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,   452,   452,   452,   452,   452,   452,   452,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,   879,   881,   882,   -44,   883,   884,   886,   887,   888,
     889,   890,   891,   892,   893,   894,   339,   895,   896,  -946,
     897,   898,   899,   900,   902,   904,   907,    -5,   910,   913,
     914,   915,   916,   918,   922,  -946,   923,   930,  -946,  -946,
     932,   934,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -173,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -162,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,   938,   939,   430,
     945,   946,   947,   948,   949,  -946,   950,   951,  -946,   952,
     953,   -36,   963,   819,  -946,  -946,  -946,  -946,   955,   956,
    -946,   957,   958,   449,   959,   960,   961,   962,   964,   702,
     965,  -946,   966,   967,   968,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,   969,   532,  -946,  -946,   970,   971,   972,  -946,    26,
    -946,  -946,  -946,  -946,   973,   976,   977,   978,  -946,  -946,
     979,   558,   980,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -136,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,   826,
     826,   826,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -109,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,   743,
    -946,   661,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,   -41,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,   -29,  -946,
     990,   928,   981,  -946,  -946,  -946,  -946,  -946,   880,  -946,
    -946,   982,  -946,  -946,  -946,  -946,   983,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,   -20,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,   -14,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,   111,  -946,  -946,  1006,   -23,   986,
     984,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,   125,  -946,  -946,
    -946,   -44,  -946,  -946,  -946,  -946,    -5,  -946,  -946,  -946,
     430,  -946,   -36,  -946,  -946,  -946,   974,  1002,  1004,  -946,
     449,  -946,   702,  -946,   532,   985,   991,   992,   349,  -946,
    -946,   558,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,   131,  -946,  -946,  -946,   349,  -946
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
    -946,  -946,  -946,  -150,  -313,  -945,  -644,  -946,  -946,   988,
    -946,  -946,  -946,  -946,   803,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,   996,  -946,  -946,  -946,  -946,  -946,
    -946,   574,  -946,  -946,  -946,  -946,  -946,   486,  -946,  -946,
    -946,  -946,  -946,  -946,   873,  -946,  -946,  -946,  -946,    51,
    -946,  -946,  -946,  -946,  -946,  -241,  -946,  -946,  -946,   617,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -204,  -946,  -946,  -946,  -139,  -946,  -946,  -946,   797,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -117,
    -946,  -946,  -946,  -946,  -946,  -127,  -946,   656,  -946,  -946,
    -946,    -9,  -946,  -946,  -946,  -946,  -946,   682,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -113,  -946,  -946,  -946,  -946,
    -946,  -946,   621,  -946,  -946,  -946,  -946,  -946,   954,  -946,
    -946,  -946,  -946,   551,  -946,  -946,  -946,  -946,  -946,  -133,
    -946,  -946,  -946,   585,  -946,  -946,  -946,  -946,  -122,  -946,
    -946,  -946,   798,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -106,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,   680,  -946,  -946,  -946,  -946,  -946,   975,
    -946,  -946,  -946,  -946,  1050,  -946,  -946,  -946,  -946,   762,
    -946,  -946,  -946,  -946,   998,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,    42,  -946,  -946,  -946,    45,  -946,  -946,  -946,  -946,
    -946,  1078,  -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946,  -946,   987,  -946,
    -946,  -946,  -946,  -946,  -946,  -946,  -946
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
     867,   868,   617,  1113,   619,   599,   621,   622,   116,   488,
    1084,    51,   711,   504,  1155,   116,   712,   122,    52,   405,
      73,   395,   123,   124,   299,   125,   126,  1055,   395,   713,
     127,   291,   481,   714,    49,    50,   481,    56,   128,   129,
     291,   224,   534,   871,   872,   130,    74,   405,   131,    58,
     585,   511,    75,   132,    62,    66,    73,   253,   133,   134,
    1128,   135,   136,   137,  1129,   138,    67,   489,    69,   512,
     299,  1130,   573,   117,   490,  1131,   491,   535,   139,   140,
     117,    71,    74,   254,   513,  1085,   396,   224,    75,   141,
     866,  1055,   113,   396,   505,   599,   573,  1260,   114,   142,
     676,  1261,   678,   679,   115,   121,   143,   600,   144,   685,
     145,   221,   146,   689,   147,   148,   255,   693,   514,   222,
     696,   406,    76,   536,  1265,   256,   300,   149,  1266,  1056,
     706,   707,   150,   151,   152,   492,   153,   154,   155,   504,
     225,   156,   720,   223,   722,   723,   231,   257,   407,   406,
     397,   258,   586,   515,  1262,  1263,  1264,   397,    76,   259,
    1156,   482,   260,   261,   226,   482,   364,   157,   365,  1157,
     366,   537,   300,   516,   574,   232,   407,   158,   159,   160,
     161,   162,   163,   164,   367,   327,   225,   233,  1286,   517,
     290,   506,  1269,  1056,   262,   585,  1270,   600,   574,   368,
    1114,   328,   329,   298,  1271,   330,   518,   519,  1272,  -129,
     226,   263,   305,  1279,   264,   265,   266,  1280,  -129,  1281,
     505,   587,   304,  1282,   369,    82,   370,  1057,   306,   601,
     307,   499,   602,   371,   165,   166,   167,   782,   168,   169,
     588,   403,   746,   267,   372,   308,   754,   170,    83,    84,
     460,  1058,   331,   309,    85,   553,   589,   292,   520,   483,
    1240,   667,   268,   483,   582,   739,   292,   580,   373,   332,
     333,   334,   335,   336,   502,   773,   534,   337,   521,   311,
     673,   338,   488,   815,   767,   269,   270,   339,    86,    87,
     571,  1057,   374,   312,    88,    89,   575,   586,   340,   341,
      90,    91,    92,   597,   313,   234,   462,   584,    93,    94,
     342,   535,   375,   314,   315,  1058,   316,   506,   853,   601,
     575,   376,   602,   858,   463,   317,   861,   318,   823,   805,
     865,   608,   343,    95,    96,   235,   319,   234,   320,   464,
     489,   321,   236,   322,  1283,   511,   323,   490,  1284,   491,
    1099,  1100,  1101,   324,   237,   238,   402,   536,  1290,   239,
     240,   241,  1291,   512,  1317,   412,   587,   235,  1318,   413,
     414,   377,   415,   465,   236,   416,   417,   344,   513,   418,
     419,   420,   421,   422,   242,   588,   237,   238,   423,   424,
    1305,   239,   240,   241,   378,   425,   426,   427,   122,   663,
     428,   589,   429,   123,   124,   537,   125,   126,   492,   430,
     431,   127,   514,   432,   433,   462,   242,   434,   646,   128,
     129,  1306,   435,  1307,   436,   437,   130,   438,   466,   131,
     609,   440,   442,   463,   132,   443,   467,   468,   253,   133,
     134,   444,   135,   136,   137,  1134,   138,   515,   464,   445,
     446,   447,   866,  1167,   448,   449,   450,   469,   325,   139,
     140,   451,   452,   453,   254,  1135,   454,   516,  1308,  1168,
     141,   455,   456,   457,  1136,   458,   459,  1169,   500,   501,
     142,   543,   465,   517,   544,  1309,   545,   143,   546,   144,
    1170,   145,   547,   146,   548,   147,   148,   255,   549,   550,
     518,   519,   554,   555,   556,  1137,   256,   557,   149,   558,
     559,   610,   560,   150,   151,   152,   561,   153,   154,   155,
     562,  1171,   156,  1172,  1310,  1311,   563,   564,   257,   565,
     566,   567,   258,   470,  1138,  1139,   568,   466,   551,   735,
     259,   611,  1140,   260,   261,   467,   468,   569,   157,  1173,
     570,   581,   520,   596,   612,   613,   615,   614,   158,   159,
     160,   161,   162,   163,   164,   616,   469,  1141,   618,   364,
     620,   365,   521,   366,   623,   262,   624,  1312,   625,   626,
     616,  1313,  1174,  1142,  1175,   627,   628,   367,   669,   648,
     629,   630,   263,   631,  1287,   264,   265,   266,   675,   633,
     634,   635,   368,  1176,   636,   637,  1224,   832,   833,   834,
     835,   836,   837,   838,   638,   165,   166,   167,   639,   168,
     169,   640,   641,   642,   267,  1177,   643,   369,   170,   370,
    1178,   644,  1247,   670,  1179,   327,   371,     2,     3,  1180,
     645,     4,   470,   268,  1181,   649,  1143,   372,  1182,   650,
     677,   328,   329,     5,   651,   330,     6,     7,   652,  1183,
     653,   654,  1184,     8,  1185,   656,   269,   270,  1225,   657,
     658,   373,   659,     9,   660,  1186,    10,    11,   681,   683,
     661,  1187,  1074,  1075,  1076,  1077,  1078,  1079,  1080,   662,
     665,   680,   666,   682,  1248,   374,   684,   686,   671,   687,
    1226,   672,   331,   688,    12,   690,   691,   692,  1227,    13,
     694,   943,   695,   944,   945,   375,   697,  1228,    14,   332,
     333,   334,   335,   336,   376,   698,  1249,   337,   699,   700,
     701,   338,   702,   703,  1250,   704,   705,   339,    15,    16,
     708,   709,  1229,  1251,  1230,  1231,   710,   715,   340,   341,
     716,   717,  1195,   718,  1196,  1197,    17,   719,  1232,   721,
     342,   724,   727,   728,  1233,   775,   748,   730,  1252,   749,
    1253,  1254,   725,    18,   377,   778,   726,   731,   784,   741,
     786,   732,   343,   733,  1255,   734,    19,    20,   737,   738,
    1256,   742,   743,   920,   750,   745,   751,   378,   752,   787,
     753,   776,   756,   757,   777,   779,   758,   760,   761,   762,
      21,   763,   764,   766,   769,   770,   771,   780,   772,   781,
     788,   785,   783,    22,   789,   790,   791,   344,   792,    23,
     946,   947,   948,   793,    24,   949,   950,    25,   951,   952,
     794,   953,   795,   954,   796,   797,   955,   798,   799,   956,
     957,   800,   801,   802,   803,   958,   807,   808,   809,   959,
     810,   811,   812,   960,   961,   962,   813,   814,   817,   818,
     963,  1198,  1199,  1200,   851,   964,  1201,  1202,   819,  1203,
    1204,   825,  1205,   852,  1206,   820,    82,  1207,   826,   822,
    1208,  1209,   827,   828,   854,   829,  1210,   830,   831,   841,
    1211,   842,   843,   844,  1212,  1213,  1214,   845,   846,    83,
      84,  1215,   921,   922,   923,    85,  1216,   924,   925,   855,
     926,   927,   847,   928,   848,   929,   849,   850,   930,   856,
     857,   931,   932,   859,   860,   862,   863,   933,   864,   866,
     870,   934,   869,   873,   874,   935,   936,   937,   880,    86,
      87,   877,   938,   988,   885,    88,    89,   939,   875,   876,
     878,    90,    91,    92,   879,   881,   882,   883,   884,    93,
      94,   886,   887,   890,   888,   889,   891,   892,   893,   894,
     895,   896,   897,   898,   899,   900,   901,   902,   903,   904,
     905,   906,   907,   908,    95,    96,   909,   910,   911,   912,
     913,   914,   915,   987,   916,   917,   918,   919,   942,   967,
     968,   969,   970,   971,   972,   973,   974,   975,   976,   977,
     978,   979,   980,   981,   982,   983,   984,   985,   986,   990,
     991,   992,   989,   993,   994,   995,   996,   997,   998,   999,
    1000,  1002,  1005,  1006,  1001,  1012,  1007,  1008,  1009,  1011,
    1013,  1010,  1014,  1015,  1016,  1017,  1161,  1020,  1018,  1022,
    1019,  1023,  1021,  1024,  1051,  1064,  1025,  1026,  1065,  1066,
    1067,  1070,  1072,   310,   572,  1027,   816,  1319,  1300,  1028,
    1029,   755,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,
    1048,  1049,  1050,  1273,  1053,  1054,  1052,  1068,  1296,  1069,
    1241,  1073,  1081,  1071,  1082,  1083,  1088,  1089,  1276,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1104,  1105,
    1106,  1107,  1108,  1109,  1285,  1110,  1297,  1111,  1298,   768,
    1112,  1299,   647,  1117,  1292,  1295,  1118,  1119,  1120,  1121,
     747,  1122,  1274,   736,   824,  1123,  1124,  1294,  1316,   774,
    1293,   806,  1301,  1125,   740,  1126,   583,  1127,   404,   461,
     674,  1132,  1133,  1268,  1267,   326,     0,   664,  1146,  1147,
    1148,  1149,  1150,  1151,  1152,  1153,  1154,  1160,  1163,  1164,
    1165,  1166,  1190,  1191,  1192,  1193,     0,  1194,  1219,  1220,
    1221,  1222,  1223,  1236,     0,     0,  1242,  1237,  1238,  1243,
    1244,  1245,  1246,  1259,  1275,   503,     0,  1289,  1302,     0,
    1277,  1278,  1288,     0,  1303,  1304,     0,     0,     0,     0,
     552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   598,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   668
};

static const yytype_int16 yycheck[] =
{
     644,   645,   315,     8,   317,     1,   319,   320,     1,     1,
      54,   235,   217,     1,    50,     1,   221,     1,   235,     1,
       1,     1,     6,     7,     1,     9,    10,     1,     1,   217,
      14,     1,     1,   221,   233,   234,     1,   235,    22,    23,
       1,     1,     1,   183,   184,    29,    27,     1,    32,   235,
       1,     1,    33,    37,   235,   235,     1,     1,    42,    43,
     233,    45,    46,    47,   237,    49,   235,    59,   235,    19,
       1,   233,     1,    66,    66,   237,    68,    36,    62,    63,
      66,   235,    27,    27,    34,   129,    66,     1,    33,    73,
     113,     1,   235,    66,    82,     1,     1,   233,   235,    83,
     413,   237,   415,   416,   235,   235,    90,   103,    92,   422,
      94,   235,    96,   426,    98,    99,    60,   430,    68,   235,
     433,   103,   103,    82,   233,    69,   103,   111,   237,   103,
     443,   444,   116,   117,   118,   127,   120,   121,   122,     1,
     100,   125,   455,   235,   457,   458,   235,    91,   130,   103,
     130,    95,   103,   103,  1099,  1100,  1101,   130,   103,   103,
     196,   130,   106,   107,   124,   130,     1,   151,     3,   205,
       5,   130,   103,   123,   103,   235,   130,   161,   162,   163,
     164,   165,   166,   167,    19,     1,   100,   235,   211,   139,
     235,   179,   233,   103,   138,     1,   237,   103,   103,    34,
     205,    17,    18,   235,   233,    21,   156,   157,   237,   179,
     124,   155,   233,   233,   158,   159,   160,   237,   179,   233,
      82,   172,   235,   237,    59,     1,    61,   201,   236,   225,
     236,   233,   228,    68,   218,   219,   220,   550,   222,   223,
     191,   234,   234,   187,    79,   236,   234,   231,    24,    25,
     234,   225,    68,   234,    30,   233,   207,   227,   208,   228,
     234,   234,   206,   228,   234,   234,   227,   233,   103,    85,
      86,    87,    88,    89,   234,   234,     1,    93,   228,   236,
     234,    97,     1,   234,   234,   229,   230,   103,    64,    65,
     234,   201,   127,   236,    70,    71,   225,   103,   114,   115,
      76,    77,    78,   234,   236,     1,     1,   179,    84,    85,
     126,    36,   147,   236,   236,   225,   236,   179,   631,   225,
     225,   156,   228,   636,    19,   236,   639,   236,   234,   234,
     643,   128,   148,   109,   110,    31,   236,     1,   236,    34,
      59,   236,    38,   236,   233,     1,   236,    66,   237,    68,
      11,    12,    13,   236,    50,    51,   236,    82,   233,    55,
      56,    57,   237,    19,   233,   236,   172,    31,   237,   236,
     236,   206,   236,    68,    38,   236,   236,   193,    34,   236,
     236,   236,   236,   236,    80,   191,    50,    51,   236,   236,
      41,    55,    56,    57,   229,   236,   236,   236,     1,   234,
     236,   207,   236,     6,     7,   130,     9,    10,   127,   236,
     236,    14,    68,   236,   236,     1,    80,   236,   234,    22,
      23,    72,   236,    74,   236,   236,    29,   236,   123,    32,
     128,   236,   236,    19,    37,   236,   131,   132,     1,    42,
      43,   236,    45,    46,    47,    15,    49,   103,    34,   236,
     236,   236,   113,     4,   236,   236,   236,   152,   234,    62,
      63,   236,   236,   236,    27,    35,   236,   123,   119,    20,
      73,   236,   236,   236,    44,   236,   236,    28,   236,   236,
      83,   236,    68,   139,   236,   136,   236,    90,   236,    92,
      41,    94,   236,    96,   236,    98,    99,    60,   236,   236,
     156,   157,   236,   236,   236,    75,    69,   236,   111,   236,
     236,   128,   236,   116,   117,   118,   236,   120,   121,   122,
     236,    72,   125,    74,   175,   176,   236,   236,    91,   236,
     236,   236,    95,   228,   104,   105,   236,   123,   234,   234,
     103,   233,   112,   106,   107,   131,   132,   236,   151,   100,
     236,   236,   208,   236,   113,   113,   113,   217,   161,   162,
     163,   164,   165,   166,   167,   113,   152,   137,   113,     1,
     113,     3,   228,     5,   113,   138,   113,   228,   217,   217,
     113,   232,   133,   153,   135,   233,   233,    19,   128,   233,
     236,   236,   155,   236,  1238,   158,   159,   160,   217,   236,
     236,   236,    34,   154,   236,   236,    74,   140,   141,   142,
     143,   144,   145,   146,   236,   218,   219,   220,   236,   222,
     223,   236,   236,   236,   187,   176,   236,    59,   231,    61,
     181,   236,    74,   233,   185,     1,    68,     0,     1,   190,
     236,     4,   228,   206,   195,   236,   216,    79,   199,   236,
     113,    17,    18,    16,   236,    21,    19,    20,   236,   210,
     236,   236,   213,    26,   215,   236,   229,   230,   136,   236,
     236,   103,   236,    36,   236,   226,    39,    40,   113,   113,
     236,   232,   832,   833,   834,   835,   836,   837,   838,   236,
     236,   217,   236,   217,   136,   127,   217,   217,   236,   113,
     168,   236,    68,   113,    67,   113,   217,   217,   176,    72,
     113,    50,   113,    52,    53,   147,   113,   185,    81,    85,
      86,    87,    88,    89,   156,   113,   168,    93,   113,   113,
     217,    97,   236,   217,   176,   236,   217,   103,   101,   102,
     217,   217,   210,   185,   212,   213,   217,   217,   114,   115,
     217,   217,    50,   217,    52,    53,   119,   113,   226,   217,
     126,   217,   236,   236,   232,   217,   128,   236,   210,   128,
     212,   213,   233,   136,   206,   128,   233,   236,   128,   233,
     128,   236,   148,   236,   226,   236,   149,   150,   236,   236,
     232,   236,   236,    50,   233,   236,   233,   229,   236,   113,
     236,   217,   233,   236,   217,   217,   236,   236,   236,   236,
     173,   236,   236,   236,   233,   236,   236,   217,   236,   217,
     113,   217,   233,   186,   128,   128,   128,   193,   128,   192,
     169,   170,   171,   128,   197,   174,   175,   200,   177,   178,
     128,   180,   128,   182,   128,   113,   185,   128,   128,   188,
     189,   128,   233,   233,   236,   194,   217,   233,   235,   198,
     233,   236,   236,   202,   203,   204,   236,   236,   128,   233,
     209,   169,   170,   171,   113,   214,   174,   175,   233,   177,
     178,   233,   180,   113,   182,   236,     1,   185,   233,   236,
     188,   189,   233,   233,   236,   233,   194,   233,   233,   233,
     198,   233,   233,   233,   202,   203,   204,   233,   233,    24,
      25,   209,   169,   170,   171,    30,   214,   174,   175,   113,
     177,   178,   233,   180,   233,   182,   233,   233,   185,   113,
     113,   188,   189,   113,   113,   128,   113,   194,   113,   113,
     128,   198,   233,   128,   217,   202,   203,   204,   113,    64,
      65,   236,   209,   217,   233,    70,    71,   214,   128,   128,
     128,    76,    77,    78,   128,   128,   128,   128,   128,    84,
      85,   128,   128,   128,   233,   233,   128,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   109,   110,   233,   233,   233,   233,
     233,   233,   233,   128,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   128,
     113,   128,   236,   128,   128,   233,   128,   128,   233,   128,
     128,   113,   233,   233,   236,   217,   233,   128,   128,   128,
     236,   233,   128,   128,   128,   128,   237,   128,   217,   128,
     236,   128,   233,   128,   128,   128,   233,   233,   128,   128,
     128,   128,   128,    77,   271,   233,   590,  1318,  1282,   233,
     233,   507,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   113,   233,   233,   236,   233,   134,   233,
    1059,   233,   233,   236,   233,   233,   233,   233,   238,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   128,   233,   134,   233,   134,   522,
     233,  1280,   345,   233,  1261,  1272,   233,   233,   233,   233,
     494,   233,  1161,   471,   603,   233,   233,  1270,  1291,   538,
    1266,   576,  1284,   233,   484,   233,   293,   233,   118,   171,
     408,   233,   233,  1131,  1129,    97,    -1,   379,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   224,   233,   233,
     233,   233,   233,   233,   233,   233,    -1,   233,   233,   233,
     233,   233,   233,   233,    -1,    -1,   233,   236,   236,   233,
     233,   233,   233,   233,   233,   227,    -1,   233,   233,    -1,
     238,   238,   236,    -1,   233,   233,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   398
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   240,     0,     1,     4,    16,    19,    20,    26,    36,
      39,    40,    67,    72,    81,   101,   102,   119,   136,   149,
     150,   173,   186,   192,   197,   200,   241,   246,   251,   271,
     277,   283,   291,   305,   325,   349,   363,   378,   385,   389,
     399,   408,   429,   435,   441,   445,   451,   508,   525,   233,
     234,   235,   235,   326,   409,   436,   235,   446,   235,   364,
     430,   350,   235,   278,   306,   379,   235,   235,   400,   235,
     284,   235,   390,     1,    27,    33,   103,   272,   273,   274,
     275,   276,     1,    24,    25,    30,    64,    65,    70,    71,
      76,    77,    78,    84,    85,   109,   110,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   235,   235,   235,     1,    66,   442,   443,
     444,   235,     1,     6,     7,     9,    10,    14,    22,    23,
      29,    32,    37,    42,    43,    45,    46,    47,    49,    62,
      63,    73,    83,    90,    92,    94,    96,    98,    99,   111,
     116,   117,   118,   120,   121,   122,   125,   151,   161,   162,
     163,   164,   165,   166,   167,   218,   219,   220,   222,   223,
     231,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   501,   505,   506,
     507,   235,   235,   235,     1,   100,   124,   247,   248,   249,
     250,   235,   235,   235,     1,    31,    38,    50,    51,    55,
      56,    57,    80,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,     1,    27,    60,    69,    91,    95,   103,
     106,   107,   138,   155,   158,   159,   160,   187,   206,   229,
     230,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     235,     1,   227,   292,   293,   294,   295,   296,   235,     1,
     103,   386,   387,   388,   235,   233,   236,   236,   236,   234,
     273,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   234,   510,     1,    17,    18,
      21,    68,    85,    86,    87,    88,    89,    93,    97,   103,
     114,   115,   126,   148,   193,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,     1,     3,     5,    19,    34,    59,
      61,    68,    79,   103,   127,   147,   156,   206,   229,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     424,   425,   426,   427,   428,     1,    66,   130,   437,   438,
     439,   440,   236,   234,   443,     1,   103,   130,   447,   448,
     449,   450,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   502,
     236,   498,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     234,   453,     1,    19,    34,    68,   123,   131,   132,   152,
     228,   365,   366,   367,   368,   369,   370,   371,   375,   376,
     377,     1,   130,   228,   431,   432,   433,   434,     1,    59,
      66,    68,   127,   351,   355,   356,   357,   361,   362,   233,
     236,   236,   234,   248,     1,    82,   179,   279,   280,   281,
     282,     1,    19,    34,    68,   103,   123,   139,   156,   157,
     208,   228,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   321,     1,    36,    82,   130,   380,   381,
     382,   383,   384,   236,   236,   236,   236,   236,   236,   236,
     236,   234,   527,   233,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   234,   253,     1,   103,   225,   401,   402,   403,   404,
     233,   236,   234,   293,   179,     1,   103,   172,   191,   207,
     285,   286,   287,   288,   289,   290,   236,   234,   387,     1,
     103,   225,   228,   391,   392,   393,   394,   395,   128,   128,
     128,   233,   113,   113,   217,   113,   113,   243,   113,   243,
     113,   243,   243,   113,   113,   217,   217,   233,   233,   236,
     236,   236,   346,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   234,   328,   233,   236,
     236,   236,   236,   236,   236,   421,   236,   236,   236,   236,
     236,   236,   236,   234,   411,   236,   236,   234,   438,   128,
     233,   236,   236,   234,   448,   217,   243,   113,   243,   243,
     217,   113,   217,   113,   217,   243,   217,   113,   113,   243,
     113,   217,   217,   243,   113,   113,   243,   113,   113,   113,
     113,   217,   236,   217,   236,   217,   243,   243,   217,   217,
     217,   217,   221,   217,   221,   217,   217,   217,   217,   113,
     243,   217,   243,   243,   217,   233,   233,   236,   236,   372,
     236,   236,   236,   236,   236,   234,   366,   236,   236,   234,
     432,   233,   236,   236,   352,   236,   234,   356,   128,   128,
     233,   233,   236,   236,   234,   280,   233,   236,   236,   322,
     236,   236,   236,   236,   236,   318,   236,   234,   308,   233,
     236,   236,   236,   234,   381,   217,   217,   217,   128,   217,
     217,   217,   243,   233,   128,   217,   128,   113,   113,   128,
     128,   128,   128,   128,   128,   128,   128,   113,   128,   128,
     128,   233,   233,   236,   405,   234,   402,   217,   233,   235,
     233,   236,   236,   236,   236,   234,   286,   128,   233,   233,
     236,   396,   236,   234,   392,   233,   233,   233,   233,   233,
     233,   233,   140,   141,   142,   143,   144,   145,   146,   242,
     243,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   113,   113,   243,   236,   113,   113,   113,   243,   113,
     113,   243,   128,   113,   113,   243,   113,   245,   245,   233,
     128,   183,   184,   128,   217,   128,   128,   236,   128,   128,
     113,   128,   128,   128,   128,   233,   128,   128,   233,   233,
     128,   128,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
      50,   169,   170,   171,   174,   175,   177,   178,   180,   182,
     185,   188,   189,   194,   198,   202,   203,   204,   209,   214,
     503,   504,   233,    50,    52,    53,   169,   170,   171,   174,
     175,   177,   178,   180,   182,   185,   188,   189,   194,   198,
     202,   203,   204,   209,   214,   499,   500,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   128,   217,   236,
     128,   113,   128,   128,   128,   233,   128,   128,   233,   128,
     128,   236,   113,   359,   360,   233,   233,   233,   128,   128,
     233,   128,   217,   236,   128,   128,   128,   128,   217,   236,
     128,   233,   128,   128,   128,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   128,   236,   233,   233,     1,   103,   201,   225,   297,
     298,   299,   300,   301,   128,   128,   128,   128,   233,   233,
     128,   236,   128,   233,   242,   242,   242,   242,   242,   242,
     242,   233,   233,   233,    54,   129,   347,   348,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,    11,
      12,    13,   244,   245,   233,   233,   233,   233,   233,   233,
     233,   233,   233,     8,   205,   422,   423,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   237,
     233,   237,   233,   233,    15,    35,    44,    75,   104,   105,
     112,   137,   153,   216,   373,   374,   233,   233,   233,   233,
     233,   233,   233,   233,   233,    50,   196,   205,   353,   354,
     224,   237,   358,   233,   233,   233,   233,     4,    20,    28,
      41,    72,    74,   100,   133,   135,   154,   176,   181,   185,
     190,   195,   199,   210,   213,   215,   226,   232,   323,   324,
     233,   233,   233,   233,   233,    50,    52,    53,   169,   170,
     171,   174,   175,   177,   178,   180,   182,   185,   188,   189,
     194,   198,   202,   203,   204,   209,   214,   319,   320,   233,
     233,   233,   233,   233,    74,   136,   168,   176,   185,   210,
     212,   213,   226,   232,   406,   407,   233,   236,   236,   302,
     234,   298,   233,   233,   233,   233,   233,    74,   136,   168,
     176,   185,   210,   212,   213,   226,   232,   397,   398,   233,
     233,   237,   244,   244,   244,   233,   237,   504,   500,   233,
     237,   233,   237,   113,   360,   233,   238,   238,   238,   233,
     237,   233,   237,   233,   237,   128,   211,   245,   236,   233,
     233,   237,   348,   423,   374,   354,   134,   134,   134,   324,
     320,   407,   233,   233,   233,    41,    72,    74,   119,   136,
     175,   176,   228,   232,   303,   304,   398,   233,   237,   304
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
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     326,   325,   327,   327,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   346,   345,
     347,   347,   348,   348,   350,   349,   352,   351,   353,   353,
     354,   354,   354,   355,   355,   356,   356,   356,   356,   356,
     358,   357,   359,   359,   360,   360,   361,   362,   364,   363,
     365,   365,   366,   366,   366,   366,   366,   366,   366,   366,
     366,   367,   368,   369,   370,   372,   371,   373,   373,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   375,
     376,   377,   379,   378,   380,   380,   381,   381,   381,   381,
     382,   383,   384,   385,   386,   386,   387,   387,   388,   390,
     389,   391,   391,   392,   392,   392,   392,   393,   394,   396,
     395,   397,   397,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   400,   399,   401,   401,   402,   402,   402,
     403,   405,   404,   406,   406,   407,   407,   407,   407,   407,
     407,   407,   407,   407,   407,   409,   408,   410,   410,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   419,   421,   420,   422,   422,   423,   423,   424,
     425,   426,   427,   428,   430,   429,   431,   431,   432,   432,
     432,   433,   434,   436,   435,   437,   437,   438,   438,   438,
     439,   440,   441,   442,   442,   443,   443,   444,   446,   445,
     447,   447,   448,   448,   448,   449,   450,   451,   452,   452,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   482,   483,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   498,   497,   499,   499,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     502,   501,   503,   503,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   505,   506,   507,   508,   509,   509,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   526,   527,   527,   527,   527,   527,   527,   527,   527,
     527,   528,   529,   530,   531,   532,   533,   534,   535
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
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 430 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 431 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 432 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 433 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 434 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2970 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 448 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2979 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 454 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2988 "conf_parser.c" /* yacc.c:1646  */
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
#line 3031 "conf_parser.c" /* yacc.c:1646  */
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
#line 3092 "conf_parser.c" /* yacc.c:1646  */
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
#line 3124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 611 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3135 "conf_parser.c" /* yacc.c:1646  */
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
#line 3152 "conf_parser.c" /* yacc.c:1646  */
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
#line 3183 "conf_parser.c" /* yacc.c:1646  */
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
#line 3201 "conf_parser.c" /* yacc.c:1646  */
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
#line 3219 "conf_parser.c" /* yacc.c:1646  */
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
#line 3232 "conf_parser.c" /* yacc.c:1646  */
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
#line 3249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 715 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3261 "conf_parser.c" /* yacc.c:1646  */
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
#line 3292 "conf_parser.c" /* yacc.c:1646  */
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
#line 3323 "conf_parser.c" /* yacc.c:1646  */
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
#line 3351 "conf_parser.c" /* yacc.c:1646  */
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
#line 3376 "conf_parser.c" /* yacc.c:1646  */
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
#line 3401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 849 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 866 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 875 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 884 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 896 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3455 "conf_parser.c" /* yacc.c:1646  */
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
#line 3472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 917 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 923 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3490 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 932 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3499 "conf_parser.c" /* yacc.c:1646  */
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
#line 3517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 954 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3526 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 960 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3535 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 966 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3544 "conf_parser.c" /* yacc.c:1646  */
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
#line 3567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1001 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1007 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3585 "conf_parser.c" /* yacc.c:1646  */
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
#line 3598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3609 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1035 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3617 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1038 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1043 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1050 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3652 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3661 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1062 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3670 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3688 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1074 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1078 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3706 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1082 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1092 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3727 "conf_parser.c" /* yacc.c:1646  */
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
#line 3809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1203 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3836 "conf_parser.c" /* yacc.c:1646  */
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
#line 3850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1226 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3868 "conf_parser.c" /* yacc.c:1646  */
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
#line 3882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1260 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1264 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1300 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 4008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1312 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1316 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1328 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1346 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4107 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1361 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1365 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1369 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1373 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1377 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1381 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4179 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1385 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1389 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1393 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1397 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4215 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1401 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1405 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4233 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1409 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4242 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1413 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4251 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1417 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4260 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1421 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1425 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1429 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4287 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1433 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1437 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4305 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4314 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1445 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4323 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1455 "conf_parser.y" /* yacc.c:1646  */
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

  case 231:
#line 1467 "conf_parser.y" /* yacc.c:1646  */
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
#line 4393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1536 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1542 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4411 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1548 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1554 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1560 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1566 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4447 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1572 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1578 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1584 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1590 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1596 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4493 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1603 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1609 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1615 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1621 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1630 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4544 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1639 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4553 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1646 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4562 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1650 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1660 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4580 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1666 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4588 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1672 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4597 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1676 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1680 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1688 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4621 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1693 "conf_parser.y" /* yacc.c:1646  */
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
#line 4639 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1706 "conf_parser.y" /* yacc.c:1646  */
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
#line 4659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1723 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4668 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1729 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4677 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1738 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4686 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1742 "conf_parser.y" /* yacc.c:1646  */
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
#line 4727 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1791 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4736 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1797 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4745 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1803 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4754 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1809 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1820 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1827 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1831 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4795 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4804 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1839 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4813 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4822 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1847 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4831 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1855 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1863 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1869 "conf_parser.y" /* yacc.c:1646  */
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
#line 4884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1883 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1892 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1905 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1912 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1923 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1929 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1935 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1950 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1965 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1976 "conf_parser.y" /* yacc.c:1646  */
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
#line 5006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1993 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1999 "conf_parser.y" /* yacc.c:1646  */
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
#line 5037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 2018 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5082 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5091 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5100 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5109 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2061 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2079 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2094 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2100 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2111 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5201 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2115 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2123 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2127 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2131 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2135 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2139 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5273 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2152 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5287 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2161 "conf_parser.y" /* yacc.c:1646  */
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
#line 5353 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5362 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2247 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5371 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2253 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5380 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2259 "conf_parser.y" /* yacc.c:1646  */
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
#line 5396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2272 "conf_parser.y" /* yacc.c:1646  */
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
#line 5412 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5421 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2291 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5430 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2307 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2323 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5488 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2334 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2346 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2352 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2367 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5538 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2371 "conf_parser.y" /* yacc.c:1646  */
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
#line 5563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2396 "conf_parser.y" /* yacc.c:1646  */
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
#line 5586 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2416 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5595 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2425 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5604 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2429 "conf_parser.y" /* yacc.c:1646  */
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
#line 5630 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2455 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5639 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2461 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5648 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2475 "conf_parser.y" /* yacc.c:1646  */
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
#line 5665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2492 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5674 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2496 "conf_parser.y" /* yacc.c:1646  */
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
#line 5696 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2518 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2524 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2588 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5722 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2593 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5730 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2598 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5738 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2603 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2609 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.glines = yylval.number;
}
#line 5756 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2615 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_time = (yyvsp[-1].number);
}
#line 5765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2621 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_request_time = (yyvsp[-1].number);
}
#line 5774 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2627 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr = (yyvsp[-1].number);
}
#line 5782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2632 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5790 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2637 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5798 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2642 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5806 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2652 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5822 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2657 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5830 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2662 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2667 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2672 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2677 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5862 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2682 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5870 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2687 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2693 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2704 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2709 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2714 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2719 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2724 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2729 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5941 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2734 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2739 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2747 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2750 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2755 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2760 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5997 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2765 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6005 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2770 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6013 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2775 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 6021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2785 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_pass_resv = yylval.number;
}
#line 6037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2790 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 6045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2800 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2805 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2815 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2820 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2826 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2829 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6109 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2832 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2835 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2838 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2841 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6141 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2844 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2847 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6157 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2850 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2853 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2856 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2859 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6189 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2862 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2865 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2868 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2871 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6221 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2874 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2877 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2880 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2883 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6253 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2886 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6261 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2889 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2894 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6277 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2900 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6285 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2903 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6293 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2906 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2909 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2912 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6317 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2915 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6325 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2918 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2921 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2924 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2927 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2930 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2933 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2936 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2939 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2942 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2945 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2948 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2951 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6421 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2954 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2957 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2962 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6445 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2967 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2972 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 3001 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3006 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6477 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3011 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6485 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3016 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6493 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 3021 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6501 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 3026 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3031 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3036 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6525 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3041 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 3046 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3051 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6549 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 3056 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6557 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 3061 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 3066 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3088 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3094 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6591 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3100 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6600 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3106 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6609 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3112 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6621 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 666:
#line 3121 "conf_parser.y" /* yacc.c:1646  */
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
#line 6639 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 3136 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6648 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 668:
#line 3142 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6657 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6661 "conf_parser.c" /* yacc.c:1646  */
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
