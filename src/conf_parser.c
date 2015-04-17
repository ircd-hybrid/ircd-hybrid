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
    HAVENT_READ_CONF = 306,
    HIDDEN = 307,
    HIDDEN_NAME = 308,
    HIDE_CHANS = 309,
    HIDE_IDLE = 310,
    HIDE_IDLE_FROM_OPERS = 311,
    HIDE_SERVER_IPS = 312,
    HIDE_SERVERS = 313,
    HIDE_SERVICES = 314,
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
    KILL = 326,
    KILL_CHASE_TIME_LIMIT = 327,
    KLINE = 328,
    KLINE_EXEMPT = 329,
    KNOCK_CLIENT_COUNT = 330,
    KNOCK_CLIENT_TIME = 331,
    KNOCK_DELAY_CHANNEL = 332,
    LEAF_MASK = 333,
    LINKS_DELAY = 334,
    LISTEN = 335,
    MASK = 336,
    MAX_ACCEPT = 337,
    MAX_BANS = 338,
    MAX_CHANNELS = 339,
    MAX_GLOBAL = 340,
    MAX_IDENT = 341,
    MAX_IDLE = 342,
    MAX_LOCAL = 343,
    MAX_NICK_CHANGES = 344,
    MAX_NICK_LENGTH = 345,
    MAX_NICK_TIME = 346,
    MAX_NUMBER = 347,
    MAX_TARGETS = 348,
    MAX_TOPIC_LENGTH = 349,
    MAX_WATCH = 350,
    MIN_IDLE = 351,
    MIN_NONWILDCARD = 352,
    MIN_NONWILDCARD_SIMPLE = 353,
    MODULE = 354,
    MODULES = 355,
    MOTD = 356,
    NAME = 357,
    NEED_IDENT = 358,
    NEED_PASSWORD = 359,
    NETWORK_DESC = 360,
    NETWORK_NAME = 361,
    NICK = 362,
    NO_CREATE_ON_SPLIT = 363,
    NO_JOIN_ON_SPLIT = 364,
    NO_OPER_FLOOD = 365,
    NO_TILDE = 366,
    NUMBER = 367,
    NUMBER_PER_CIDR = 368,
    NUMBER_PER_IP = 369,
    OPER_ONLY_UMODES = 370,
    OPER_PASS_RESV = 371,
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
    RSA_PUBLIC_KEY_FILE = 393,
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
    XLINE = 486
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
#define HAVENT_READ_CONF 306
#define HIDDEN 307
#define HIDDEN_NAME 308
#define HIDE_CHANS 309
#define HIDE_IDLE 310
#define HIDE_IDLE_FROM_OPERS 311
#define HIDE_SERVER_IPS 312
#define HIDE_SERVERS 313
#define HIDE_SERVICES 314
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
#define KILL 326
#define KILL_CHASE_TIME_LIMIT 327
#define KLINE 328
#define KLINE_EXEMPT 329
#define KNOCK_CLIENT_COUNT 330
#define KNOCK_CLIENT_TIME 331
#define KNOCK_DELAY_CHANNEL 332
#define LEAF_MASK 333
#define LINKS_DELAY 334
#define LISTEN 335
#define MASK 336
#define MAX_ACCEPT 337
#define MAX_BANS 338
#define MAX_CHANNELS 339
#define MAX_GLOBAL 340
#define MAX_IDENT 341
#define MAX_IDLE 342
#define MAX_LOCAL 343
#define MAX_NICK_CHANGES 344
#define MAX_NICK_LENGTH 345
#define MAX_NICK_TIME 346
#define MAX_NUMBER 347
#define MAX_TARGETS 348
#define MAX_TOPIC_LENGTH 349
#define MAX_WATCH 350
#define MIN_IDLE 351
#define MIN_NONWILDCARD 352
#define MIN_NONWILDCARD_SIMPLE 353
#define MODULE 354
#define MODULES 355
#define MOTD 356
#define NAME 357
#define NEED_IDENT 358
#define NEED_PASSWORD 359
#define NETWORK_DESC 360
#define NETWORK_NAME 361
#define NICK 362
#define NO_CREATE_ON_SPLIT 363
#define NO_JOIN_ON_SPLIT 364
#define NO_OPER_FLOOD 365
#define NO_TILDE 366
#define NUMBER 367
#define NUMBER_PER_CIDR 368
#define NUMBER_PER_IP 369
#define OPER_ONLY_UMODES 370
#define OPER_PASS_RESV 371
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
#define RSA_PUBLIC_KEY_FILE 393
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
#define XLINE 486

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 152 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 697 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
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
#define YYLAST   1396

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  238
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  298
/* YYNRULES -- Number of rules.  */
#define YYNRULES  670
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1325

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   486

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
       2,     2,     2,     2,   236,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   237,   232,
       2,   235,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   234,     2,   233,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   387,   387,   388,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   418,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   429,   429,
     430,   431,   432,   433,   440,   443,   443,   444,   444,   444,
     446,   452,   459,   461,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   482,   522,   580,   609,   617,   631,   659,
     674,   689,   699,   713,   722,   750,   778,   803,   825,   847,
     856,   858,   858,   859,   860,   861,   862,   864,   873,   882,
     895,   894,   912,   912,   913,   913,   913,   915,   921,   931,
     930,   949,   949,   950,   950,   950,   950,   950,   952,   958,
     964,   970,   991,   992,   992,   994,   994,   995,   997,  1004,
    1004,  1017,  1018,  1020,  1020,  1021,  1021,  1023,  1031,  1034,
    1040,  1039,  1045,  1045,  1046,  1050,  1054,  1058,  1062,  1066,
    1070,  1074,  1078,  1089,  1088,  1177,  1177,  1178,  1179,  1180,
    1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1191,
    1197,  1203,  1209,  1215,  1226,  1232,  1238,  1249,  1256,  1255,
    1261,  1261,  1262,  1266,  1270,  1274,  1278,  1282,  1286,  1290,
    1294,  1298,  1302,  1306,  1310,  1314,  1318,  1322,  1326,  1330,
    1334,  1338,  1342,  1346,  1353,  1352,  1358,  1358,  1359,  1363,
    1367,  1371,  1375,  1379,  1383,  1387,  1391,  1395,  1399,  1403,
    1407,  1411,  1415,  1419,  1423,  1427,  1431,  1435,  1439,  1443,
    1447,  1451,  1462,  1461,  1523,  1523,  1524,  1525,  1526,  1527,
    1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1536,
    1537,  1538,  1539,  1540,  1542,  1548,  1554,  1560,  1566,  1572,
    1578,  1584,  1590,  1596,  1602,  1609,  1615,  1621,  1627,  1636,
    1646,  1645,  1651,  1651,  1652,  1656,  1667,  1666,  1673,  1672,
    1677,  1677,  1678,  1682,  1686,  1692,  1692,  1693,  1693,  1693,
    1693,  1693,  1695,  1695,  1697,  1697,  1699,  1712,  1729,  1735,
    1745,  1744,  1786,  1786,  1787,  1788,  1789,  1790,  1791,  1792,
    1793,  1794,  1795,  1797,  1803,  1809,  1815,  1827,  1826,  1832,
    1832,  1833,  1837,  1841,  1845,  1849,  1853,  1857,  1861,  1865,
    1869,  1875,  1889,  1898,  1912,  1911,  1926,  1926,  1927,  1927,
    1927,  1927,  1929,  1935,  1941,  1951,  1953,  1953,  1954,  1954,
    1956,  1972,  1971,  1996,  1996,  1997,  1997,  1997,  1997,  1999,
    2005,  2025,  2024,  2030,  2030,  2031,  2035,  2039,  2043,  2047,
    2051,  2055,  2059,  2063,  2067,  2077,  2076,  2097,  2097,  2098,
    2098,  2098,  2100,  2107,  2106,  2112,  2112,  2113,  2117,  2121,
    2125,  2129,  2133,  2137,  2141,  2145,  2149,  2159,  2158,  2230,
    2230,  2231,  2232,  2233,  2234,  2235,  2236,  2237,  2238,  2239,
    2240,  2241,  2242,  2243,  2244,  2245,  2247,  2253,  2259,  2265,
    2278,  2291,  2297,  2303,  2307,  2314,  2313,  2318,  2318,  2319,
    2323,  2329,  2340,  2346,  2352,  2358,  2374,  2373,  2399,  2399,
    2400,  2400,  2400,  2402,  2422,  2432,  2431,  2458,  2458,  2459,
    2459,  2459,  2461,  2467,  2476,  2478,  2478,  2479,  2479,  2481,
    2499,  2498,  2521,  2521,  2522,  2522,  2522,  2524,  2530,  2539,
    2542,  2542,  2543,  2544,  2545,  2546,  2547,  2548,  2549,  2550,
    2551,  2552,  2553,  2554,  2555,  2556,  2557,  2558,  2559,  2560,
    2561,  2562,  2563,  2564,  2565,  2566,  2567,  2568,  2569,  2570,
    2571,  2572,  2573,  2574,  2575,  2576,  2577,  2578,  2579,  2580,
    2581,  2582,  2583,  2584,  2585,  2586,  2587,  2588,  2589,  2590,
    2591,  2594,  2599,  2604,  2609,  2615,  2621,  2627,  2633,  2638,
    2643,  2648,  2653,  2658,  2663,  2668,  2673,  2678,  2683,  2688,
    2693,  2699,  2710,  2715,  2720,  2725,  2730,  2735,  2740,  2745,
    2748,  2753,  2756,  2761,  2766,  2771,  2776,  2781,  2786,  2791,
    2796,  2801,  2806,  2811,  2816,  2821,  2827,  2826,  2831,  2831,
    2832,  2835,  2838,  2841,  2844,  2847,  2850,  2853,  2856,  2859,
    2862,  2865,  2868,  2871,  2874,  2877,  2880,  2883,  2886,  2889,
    2892,  2895,  2901,  2900,  2905,  2905,  2906,  2909,  2912,  2915,
    2918,  2921,  2924,  2927,  2930,  2933,  2936,  2939,  2942,  2945,
    2948,  2951,  2954,  2957,  2960,  2963,  2968,  2973,  2978,  2987,
    2990,  2990,  2991,  2992,  2993,  2994,  2995,  2996,  2997,  2998,
    2999,  3000,  3001,  3002,  3003,  3004,  3005,  3007,  3012,  3017,
    3022,  3027,  3032,  3037,  3042,  3047,  3052,  3057,  3062,  3067,
    3072,  3080,  3083,  3083,  3084,  3085,  3086,  3087,  3088,  3089,
    3090,  3091,  3092,  3094,  3100,  3106,  3112,  3118,  3127,  3142,
    3148
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
  "GLINE_REQUEST_DURATION", "HAVENT_READ_CONF", "HIDDEN", "HIDDEN_NAME",
  "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT",
  "INVITE_CLIENT_TIME", "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID",
  "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL",
  "LEAF_MASK", "LINKS_DELAY", "LISTEN", "MASK", "MAX_ACCEPT", "MAX_BANS",
  "MAX_CHANNELS", "MAX_GLOBAL", "MAX_IDENT", "MAX_IDLE", "MAX_LOCAL",
  "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MAX_WATCH", "MIN_IDLE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD",
  "NAME", "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME",
  "NICK", "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD",
  "NO_TILDE", "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP",
  "OPER_ONLY_UMODES", "OPER_PASS_RESV", "OPER_UMODES", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD",
  "PATH", "PING_COOKIE", "PING_TIME", "PORT", "QSTRING", "RANDOM_IDLE",
  "REASON", "REDIRPORT", "REDIRSERV", "REHASH", "REMOTE", "REMOTEBAN",
  "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS",
  "SEND_PASSWORD", "SENDQ", "SERVERHIDE", "SERVERINFO", "SHORT_MOTD",
  "SPOOF", "SPOOF_NOTICE", "SQUIT", "SSL_CERTIFICATE_FILE",
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
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "XLINE", "';'", "'}'", "'{'", "'='",
  "','", "':'", "$accept", "conf", "conf_item", "timespec_", "timespec",
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
  "oper_name", "oper_user", "oper_password", "oper_whois",
  "oper_encrypted", "oper_rsa_public_key_file",
  "oper_ssl_certificate_fingerprint", "oper_ssl_connection_required",
  "oper_class", "oper_umodes", "$@6", "oper_umodes_items",
  "oper_umodes_item", "oper_flags", "$@7", "oper_flags_items",
  "oper_flags_item", "class_entry", "$@8", "class_items", "class_item",
  "class_name", "class_ping_time", "class_number_per_ip",
  "class_connectfreq", "class_max_channels", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
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
     485,   486,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -880

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-880)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -880,   690,  -880,  -216,  -229,  -212,  -880,  -880,  -880,  -209,
    -880,  -198,  -880,  -880,  -880,  -178,  -880,  -880,  -880,  -170,
    -167,  -880,  -158,  -880,  -155,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,   324,   931,  -152,  -140,  -138,    11,  -126,   455,  -107,
     -85,   -84,   203,   -77,   -75,   -69,   765,   508,   -60,   109,
      -2,    12,    41,  -199,  -197,    26,    44,    27,  -880,  -880,
    -880,  -880,  -880,    50,    55,    58,    64,    68,    70,    77,
      81,    94,    95,   104,   110,   111,   117,   168,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,   696,   623,    79,  -880,   128,    34,  -880,
    -880,    23,  -880,   133,   139,   140,   149,   150,   151,   153,
     154,   155,   156,   158,   160,   161,   163,   164,   165,   167,
     172,   173,   174,   176,   178,   179,   180,   181,   183,   184,
    -880,   185,  -880,   188,   189,   190,   192,   194,   197,   198,
     200,   201,   204,   207,   208,   212,   213,   214,   217,   218,
     222,    20,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,   300,     3,   280,    90,   223,   224,   123,  -880,  -880,
    -880,    19,   290,    47,  -880,   225,   228,   232,   233,   236,
     237,   241,   245,   120,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,   106,   248,   250,   251,   253,   254,   256,
     257,   258,   262,   263,   267,   272,   273,   275,   276,   277,
     278,    61,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
      92,   112,   279,    45,  -880,  -880,  -880,   260,   205,  -880,
     282,    40,  -880,  -880,     5,  -880,   231,   313,   357,   283,
    -880,   412,   417,   419,   420,    67,   421,   417,   423,   417,
     417,   424,   427,   325,   326,   311,  -880,   315,   310,   316,
     327,  -880,   328,   329,   331,   332,   338,   342,   345,   346,
     348,   350,   351,   352,   353,   170,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,   358,   359,   360,   361,   364,   366,
     371,  -880,   372,   373,   374,   376,   377,   387,   388,   295,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,   394,   396,    31,  -880,
    -880,  -880,   434,   400,  -880,  -880,   398,   402,    73,  -880,
    -880,  -880,   425,   417,   477,   417,   417,   426,   480,   431,
     523,   433,   417,   435,   527,   537,   417,   539,   437,   439,
     417,   547,   556,   417,   557,   558,   566,   570,   471,   453,
     481,   463,   484,   417,   417,   487,   488,   492,  -201,  -196,
     493,   496,   500,   501,   606,   417,   505,   417,   417,   506,
     490,  -880,   491,   499,   502,  -880,   503,   504,   507,   510,
     511,   211,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,   512,   513,    71,  -880,  -880,  -880,   509,   515,
     517,  -880,   518,  -880,    30,  -880,  -880,  -880,  -880,  -880,
     613,   616,   522,  -880,   524,   525,   528,    38,  -880,  -880,
    -880,   530,   529,   533,  -880,   536,   542,   544,   550,   551,
    -880,   552,   554,   249,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,   540,   559,   560,   561,
      14,  -880,  -880,  -880,  -880,   578,   582,   585,   628,   586,
     587,   588,   417,   572,  -880,  -880,   645,   632,   590,   647,
     695,   699,   685,   687,   688,   689,   692,   693,   701,   702,
     703,   704,   705,   594,  -880,   601,   599,  -880,    88,  -880,
    -880,  -880,  -880,   620,   604,  -880,   603,   615,   617,   619,
     622,   625,   103,  -880,  -880,  -880,  -880,  -880,   728,   629,
    -880,   631,   630,  -880,   634,    87,  -880,  -880,  -880,  -880,
     635,   638,   639,  -880,   644,   238,   646,   649,   650,   651,
     654,   660,   661,   664,   667,   669,   671,   674,   677,  -880,
    -880,   754,   792,   417,   642,   798,   799,   800,   417,   802,
     803,   417,   789,   806,   807,   417,   808,   808,   694,  -880,
    -880,   797,  -124,   809,   710,   812,   814,   708,   817,   819,
     815,   822,   823,   824,   825,   722,  -880,   833,   838,   734,
    -880,   735,  -880,   842,   843,   739,  -880,   740,   742,   743,
     744,   745,   746,   747,   748,   749,   750,   751,   752,   753,
     755,   756,   757,   758,   759,   760,   762,   763,   766,   767,
     768,   769,   770,   771,   761,   772,   672,   773,   777,   778,
     779,   780,   781,   784,   785,   786,   787,   788,   790,   791,
     793,   794,   795,   796,   801,   804,   805,  -880,  -880,   859,
     816,   810,   866,   909,   897,   902,   903,   811,  -880,   905,
     907,   818,  -880,  -880,   908,   911,   813,   929,   820,  -880,
     821,   826,  -880,  -880,   915,   917,   827,  -880,  -880,   919,
     832,   828,   922,   924,   927,   928,   841,   829,   930,   933,
     830,  -880,  -880,   934,   938,   939,   835,  -880,   836,   837,
     839,   840,   844,   845,   846,   847,  -880,   848,   849,   850,
     851,   852,   853,   854,   855,   856,   857,   858,   860,   861,
     862,   863,   864,   865,  -880,  -880,   943,   867,   868,  -880,
     869,  -880,   125,  -880,   946,   947,   948,   964,   871,  -880,
     872,  -880,  -880,   971,   870,   972,   874,  -880,  -880,  -880,
    -880,  -880,   417,   417,   417,   417,   417,   417,   417,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,   875,   876,   877,   -53,   878,   879,
     880,   881,   882,   883,   884,   885,   886,   887,   888,   354,
     889,   890,  -880,   891,   892,   893,   894,   895,   896,   898,
       0,   899,   900,   901,   904,   906,   910,   912,  -880,   913,
     914,  -880,  -880,   916,   918,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -192,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -187,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
     920,   921,   553,   923,   925,   926,   932,   935,  -880,   936,
     937,  -880,   940,   941,   -41,   944,   942,  -880,  -880,  -880,
    -880,   945,   949,  -880,   950,   951,   450,   952,   953,   954,
     955,   956,   721,   957,   958,  -880,   959,   960,   961,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,   962,   469,  -880,  -880,   963,
     965,   966,  -880,    36,  -880,  -880,  -880,  -880,   967,   970,
     973,   974,  -880,  -880,   975,   520,   976,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -185,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,   808,   808,   808,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -182,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,   761,  -880,   672,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -159,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -151,  -880,  1017,   929,   977,  -880,  -880,  -880,
    -880,  -880,   978,  -880,  -880,   979,  -880,  -880,  -880,  -880,
     980,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,   -68,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,   -25,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,   -23,
    -880,  -880,  1007,   -51,   968,   981,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,   -22,  -880,  -880,  -880,   -53,  -880,  -880,  -880,
    -880,     0,  -880,  -880,  -880,   553,  -880,   -41,  -880,  -880,
    -880,  1002,  1004,  1006,  -880,   450,  -880,   721,  -880,   469,
     982,   986,   987,   299,  -880,  -880,   520,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,   -15,
    -880,  -880,  -880,   299,  -880
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   232,   397,   445,     0,
     460,     0,   300,   436,   276,     0,   100,   153,   334,     0,
       0,   375,     0,   109,     0,   351,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   636,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   621,   635,
     623,   624,   625,   626,   627,   628,   622,   629,   630,   631,
     632,   633,   634,     0,     0,     0,   458,     0,     0,   456,
     457,     0,   520,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     592,     0,   566,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   471,   472,   473,   518,   519,   512,   513,   514,
     515,   516,   511,   483,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   508,   484,   485,   517,   489,   490,   491,
     492,   488,   487,   493,   501,   502,   494,   495,   496,   497,
     486,   499,   509,   510,   506,   507,   500,   498,   504,   505,
     503,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,     0,     0,     0,   662,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   653,   654,   655,   656,   657,   660,
     658,   659,   661,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    69,    66,    64,    70,    71,    65,    55,
      68,    58,    59,    60,    56,    67,    61,    62,    63,    57,
       0,     0,     0,     0,   124,   125,   126,     0,     0,   349,
       0,     0,   347,   348,     0,    96,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   620,     0,     0,     0,
       0,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,   236,   239,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   237,   238,
     240,   250,   251,   252,     0,     0,     0,     0,     0,     0,
       0,   425,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   402,   403,   404,   405,   406,   408,   407,   410,
     414,   411,   412,   413,   409,   451,     0,     0,     0,   448,
     449,   450,     0,     0,   455,   466,     0,     0,     0,   463,
     464,   465,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   470,     0,     0,     0,   317,     0,     0,     0,     0,
       0,     0,   303,   304,   305,   306,   311,   307,   308,   309,
     310,   442,     0,     0,     0,   439,   440,   441,     0,     0,
       0,   278,     0,   288,     0,   286,   287,   289,   290,    49,
       0,     0,     0,    45,     0,     0,     0,     0,   103,   104,
     105,     0,     0,     0,   204,     0,     0,     0,     0,     0,
     178,     0,     0,     0,   156,   157,   158,   159,   160,   163,
     164,   165,   166,   162,   161,   167,     0,     0,     0,     0,
       0,   337,   338,   339,   340,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   652,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,   383,     0,   378,
     379,   380,   127,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   112,   113,   115,   114,   116,     0,     0,
     346,     0,     0,   361,     0,     0,   354,   355,   356,   357,
       0,     0,     0,    90,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   619,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     415,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   399,     0,     0,     0,
     447,     0,   454,     0,     0,     0,   462,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   469,   312,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,     0,
       0,     0,   438,   291,     0,     0,     0,     0,     0,   285,
       0,     0,    44,   106,     0,     0,     0,   102,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   155,   341,     0,     0,     0,     0,   336,     0,     0,
       0,     0,     0,     0,     0,     0,   651,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,   381,     0,     0,     0,   377,
       0,   122,     0,   117,     0,     0,     0,     0,     0,   111,
       0,   345,   358,     0,     0,     0,     0,   353,    99,    98,
      97,   649,    28,    28,    28,    28,    28,    28,    28,    30,
      29,   650,   646,   645,   637,   638,   639,   640,   641,   642,
     644,   643,   647,   648,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   398,     0,
       0,   446,   459,     0,     0,   461,   534,   538,   521,   522,
     554,   524,   618,   563,   560,   533,   526,   525,   528,   529,
     527,   541,   532,   542,   531,   537,   536,   535,   561,   523,
     616,   617,   558,   602,   596,   612,   597,   598,   599,   607,
     615,   600,   609,   613,   603,   614,   604,   608,   601,   611,
     606,   605,   610,     0,   595,   559,   575,   576,   577,   570,
     588,   571,   572,   573,   583,   591,   574,   585,   589,   579,
     590,   580,   584,   578,   587,   582,   581,   586,     0,   569,
     555,   553,   556,   562,   557,   544,   551,   552,   549,   550,
     545,   546,   547,   548,   564,   565,   530,   540,   539,   543,
       0,     0,     0,     0,     0,     0,     0,     0,   301,     0,
       0,   437,     0,     0,     0,   296,   292,   295,   277,    50,
      51,     0,     0,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   154,     0,     0,     0,   335,
     664,   663,   669,   667,   670,   665,   666,   668,    86,    81,
      89,    80,    87,    88,    79,    83,    82,    74,    73,    78,
      75,    77,    76,    84,    85,     0,     0,   376,   128,     0,
       0,     0,   140,     0,   132,   133,   135,   134,     0,     0,
       0,     0,   110,   350,     0,     0,     0,   352,    31,    32,
      33,    34,    35,    36,    37,   265,   266,   257,   275,   274,
       0,   273,   258,   260,   262,   269,   261,   259,   268,   254,
     267,   256,   255,    38,    38,    38,    40,    39,   263,   264,
     420,   423,   424,   434,   431,   417,   432,   429,   430,     0,
     428,   433,   416,   422,   419,   421,   435,   418,   452,   453,
     467,   468,   593,     0,   567,     0,   315,   316,   325,   322,
     327,   323,   324,   330,   326,   328,   321,   329,     0,   320,
     314,   333,   332,   331,   313,   444,   443,   299,   298,   283,
     284,   282,     0,   281,     0,     0,     0,   107,   108,   177,
     173,   224,   211,   221,   220,   209,   214,   230,   223,   228,
     213,   216,   225,   227,   231,   222,   229,   217,   219,   226,
     215,   218,     0,   207,   169,   171,   174,   175,   176,   187,
     188,   189,   182,   200,   183,   184,   185,   195,   203,   186,
     197,   201,   191,   202,   192,   196,   190,   199,   194,   193,
     198,     0,   181,   170,   172,   344,   342,   343,   382,   387,
     393,   396,   389,   395,   390,   394,   392,   388,   391,     0,
     386,   136,     0,     0,     0,     0,   131,   119,   118,   120,
     121,   359,   365,   371,   374,   367,   373,   368,   372,   370,
     366,   369,     0,   364,   360,   271,     0,    41,    42,    43,
     426,     0,   594,   568,   318,     0,   279,     0,   297,   294,
     293,     0,     0,     0,   205,     0,   179,     0,   384,     0,
       0,     0,     0,     0,   130,   362,     0,   272,   427,   319,
     280,   210,   208,   212,   206,   180,   385,   137,   139,   138,
     146,   151,   150,   145,   148,   152,   149,   144,   147,     0,
     143,   363,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -880,  -880,  -880,  -278,  -310,  -879,  -646,  -880,  -880,   969,
    -880,  -880,  -880,  -880,   983,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  1063,  -880,  -880,  -880,  -880,  -880,
    -880,   636,  -880,  -880,  -880,  -880,  -880,   549,  -880,  -880,
    -880,  -880,  -880,  -880,   984,  -880,  -880,  -880,  -880,    84,
    -880,  -880,  -880,  -880,  -880,  -174,  -880,  -880,  -880,   633,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -136,  -880,  -880,  -880,  -131,  -880,  -880,  -880,
     831,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -106,  -880,  -880,  -880,  -880,  -880,  -118,  -880,   668,  -880,
    -880,  -880,    -4,  -880,  -880,  -880,  -880,  -880,   700,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -112,  -880,  -880,  -880,
    -880,  -880,  -880,   640,  -880,  -880,  -880,  -880,  -880,   873,
    -880,  -880,  -880,  -880,   565,  -880,  -880,  -880,  -880,  -880,
    -121,  -880,  -880,  -880,   626,  -880,  -880,  -880,  -880,  -110,
    -880,  -880,  -880,   985,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,   -74,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,   681,  -880,  -880,  -880,  -880,  -880,
     834,  -880,  -880,  -880,  -880,  1080,  -880,  -880,  -880,  -880,
     988,  -880,  -880,  -880,  -880,  1039,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,    76,  -880,  -880,  -880,    89,  -880,  -880,  -880,
    -880,  -880,  1115,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,   990,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   839,   840,  1106,  1107,    27,   227,   228,
     229,   230,    28,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,    29,    77,    78,    79,    80,    81,    30,    63,
     507,   508,   509,   510,    31,    70,   592,   593,   594,   595,
     596,   597,    32,   293,   294,   295,   296,   297,  1063,  1064,
    1065,  1066,  1067,  1244,  1319,  1320,    33,    64,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     767,  1221,  1222,   535,   761,  1192,  1193,    34,    53,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   634,  1090,
    1091,    35,    61,   493,   746,  1162,  1163,   494,   495,   496,
    1166,  1006,  1007,   497,   498,    36,    59,   471,   472,   473,
     474,   475,   476,   477,   731,  1148,  1149,   478,   479,   480,
      37,    65,   540,   541,   542,   543,   544,    38,   301,   302,
     303,    39,    72,   605,   606,   607,   608,   609,   824,  1262,
    1263,    40,    68,   578,   579,   580,   581,   807,  1239,  1240,
      41,    54,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   657,  1119,  1120,   390,   391,   392,   393,
     394,    42,    60,   484,   485,   486,   487,    43,    55,   398,
     399,   400,   401,    44,   118,   119,   120,    45,    57,   408,
     409,   410,   411,    46,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     441,   968,   969,   217,   439,   943,   944,   218,   219,   220,
      47,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    48,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     870,   871,   616,  1088,   481,    51,   601,   621,  1117,   623,
     624,  1159,   116,   299,   713,   536,    49,    50,   714,   715,
     504,   122,    52,   716,   405,    56,   123,   124,    73,   125,
     126,   488,   395,   305,   127,   116,    58,  1059,   306,   504,
    1132,   299,   128,   129,  1133,  1134,   291,  1265,   536,  1135,
    1270,  1266,   130,   537,  1271,   131,    62,    74,   874,   875,
     132,   869,   253,    75,    66,   133,   134,    67,   135,   136,
     137,   138,   481,  1274,   405,  1089,    69,  1275,   117,    71,
     395,  1276,   113,   139,   140,  1277,   537,   254,   601,   575,
     489,   255,   141,   575,   114,   538,   115,   490,   396,   491,
     505,   117,   142,   678,   587,   680,   681,   602,   121,   143,
     291,   144,   687,   145,   300,   146,   691,   147,   148,   505,
     695,   234,   256,   698,   224,   406,  1059,   221,   538,    76,
     149,   257,   482,   708,   709,   150,   151,   152,  1060,   153,
     154,   155,   300,   539,   156,   722,   396,   724,   725,   222,
     223,   258,   407,  1160,   235,   259,   492,   231,  1291,   232,
     397,   236,  1161,   260,  1284,   233,   261,   262,  1285,    82,
     157,   327,   237,   238,   290,   406,   539,   239,   240,   241,
     158,   159,   160,   161,   162,   163,   164,   328,   329,   602,
     576,   330,    83,    84,   576,    85,    86,   506,   263,   242,
     482,    87,   407,  1118,   224,   588,   587,  1286,   397,  1288,
    1295,  1287,   462,  1289,  1296,   264,   506,  1322,   265,   266,
     267,  1323,   225,  -129,  1267,  1268,  1269,  1060,   603,   483,
     463,   604,   298,    88,    89,  1061,   165,   166,   167,   331,
     168,   169,   785,    90,    91,    92,   226,   776,   464,   170,
     511,    93,    94,   460,   332,   333,   334,   335,   336,  1062,
     309,   307,   337,   748,   669,   268,   338,   403,   512,  1245,
     292,   756,   339,   599,   589,   304,    95,    96,   584,   308,
     465,   488,   619,   340,   341,   311,   513,  -129,   269,   270,
     312,   511,   590,   313,   573,   342,   364,   483,   365,   314,
     366,   462,   225,   315,   741,   316,   675,   588,   591,   512,
     603,   577,   317,   604,   367,   577,   318,   343,   514,   463,
     826,   808,   499,   856,  1061,    73,   226,   513,   861,   319,
     320,   864,   368,   466,   292,   868,   818,   464,   555,   321,
     489,   467,   468,  1310,   582,   322,   323,   490,  1062,   491,
     615,   515,   324,   553,    74,   369,   502,   370,   610,   514,
      75,   344,   469,   402,   371,  1103,  1104,  1105,   412,   465,
    1311,   516,  1312,   372,   413,   414,   589,   832,   833,   834,
     835,   836,   837,   838,   415,   416,   417,   517,   418,   419,
     420,   421,   515,   422,   590,   423,   424,   373,   425,   426,
     427,   325,   428,   648,   518,   519,   492,   429,   430,   431,
     591,   432,   516,   433,   434,   435,   436,  1313,   437,   438,
     440,   374,   466,   442,   443,   444,    76,   445,   517,   446,
     467,   468,   447,   448,  1314,   449,   450,   470,   586,   451,
     611,   375,   452,   453,   737,   518,   519,   454,   455,   456,
     376,   469,   457,   458,  1171,   520,   122,   459,   500,   501,
     545,   123,   124,   546,   125,   126,   869,   547,   548,   127,
    1172,   549,   550,  1315,  1316,   521,   551,   128,   129,   522,
     552,  1173,   770,   556,   612,   557,   558,   130,   559,   560,
     131,   561,   562,   563,  1174,   132,   520,   564,   565,   377,
     133,   134,   566,   135,   136,   137,   138,   567,   568,   253,
     569,   570,   571,   572,   583,   613,   521,   598,   139,   140,
     522,  1175,   378,  1176,   614,  1317,   470,   141,   665,   615,
    1318,   617,   618,   620,   254,   622,   625,   142,   255,   626,
     627,   628,  1229,   629,   143,   631,   144,   630,   145,  1177,
     146,   632,   147,   148,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,   671,   633,   635,   636,   149,   637,   638,  1138,   256,
     150,   151,   152,   639,   153,   154,   155,   640,   257,   156,
     641,   642,  1178,   643,  1179,   644,   645,   646,   647,   679,
     650,  1139,   683,  1252,   651,   652,   653,  1292,   258,   654,
    1140,   655,   259,  1180,  1230,   157,   656,   658,   659,   660,
     260,   661,   662,   261,   262,   158,   159,   160,   161,   162,
     163,   164,   663,   664,   364,  1181,   365,  1141,   366,   667,
    1182,   668,   672,   673,  1183,   685,  1231,   674,  1184,   689,
     677,   682,   367,  1185,  1232,   263,   684,  1186,   686,   690,
     688,   692,   693,  1233,   694,  1253,  1142,  1143,  1187,   696,
     368,  1188,   264,  1189,  1144,   265,   266,   267,   697,   699,
     700,   165,   166,   167,  1190,   168,   169,  1234,   701,  1235,
    1236,  1191,   702,   369,   170,   370,   703,  1254,   704,  1145,
       2,     3,   371,  1237,     4,  1255,   705,   327,   706,   707,
    1238,   372,   710,   711,  1256,  1146,     5,   712,   717,     6,
       7,   718,   268,   328,   329,   719,   720,   330,   721,     8,
     723,   726,   727,   728,   946,   373,   947,   948,  1257,     9,
    1258,  1259,    10,    11,   729,   269,   270,   730,   732,   733,
     750,   743,   734,   751,  1260,   735,   736,   739,   740,   374,
     744,  1261,   745,   747,   752,   781,   753,   787,    12,   788,
     754,    13,   758,   755,   759,   331,   234,  1147,   760,   375,
      14,   762,   772,  1199,   790,  1200,  1201,   763,   376,   764,
     332,   333,   334,   335,   336,   765,   766,   768,   337,   769,
      15,    16,   338,   778,   773,   774,   775,   779,   339,   235,
     780,   782,   783,   784,   786,   789,   236,   791,    17,   340,
     341,   792,   793,   923,   794,   795,   796,   237,   238,   797,
     798,   342,   239,   240,   241,    18,   804,   377,   799,   800,
     801,   802,   803,   805,   806,   810,   811,   812,    19,    20,
     949,   950,   951,   343,   242,   952,   953,   813,   954,   955,
     378,   956,   814,   957,   815,   820,   958,   816,   959,   960,
     817,   821,    21,   822,   961,   823,   854,   828,   962,   825,
     829,   830,   963,   964,   965,    22,   831,   857,   841,   966,
      23,   842,   843,   844,   967,    24,   845,   344,    25,  1202,
    1203,  1204,   846,   847,  1205,  1206,   848,  1207,  1208,   849,
    1209,   850,  1210,   851,   855,  1211,   852,  1212,  1213,   853,
     858,   859,   860,  1214,   862,   863,   865,  1215,   866,   867,
     869,  1216,  1217,  1218,   873,   877,   872,   883,  1219,   924,
     925,   926,    82,  1220,   927,   928,   876,   929,   930,   878,
     931,   879,   932,   880,   881,   933,   882,   934,   935,   884,
     885,   886,   887,   936,   888,    83,    84,   937,    85,    86,
     889,   938,   939,   940,    87,   890,   891,   892,   941,   893,
     894,   895,   896,   942,   897,   898,   899,   900,   901,   902,
     903,   904,   905,   906,   907,   908,   990,   909,   910,   911,
     912,   913,   914,   993,   915,   916,    88,    89,   917,   918,
     919,   920,   921,   922,   945,   970,    90,    91,    92,   971,
     972,   973,   974,   975,    93,    94,   976,   977,   978,   979,
     980,   994,   981,   982,   995,   983,   984,   985,   986,   996,
     997,   991,   999,   987,  1000,  1002,   988,   989,  1003,    95,
      96,  1005,  1011,   998,  1012,   992,  1014,  1015,  1004,  1017,
    1001,  1018,  1008,  1009,  1019,  1020,  1021,  1023,  1010,  1013,
    1024,  1026,  1025,  1016,  1022,  1027,  1028,  1029,  1030,  1031,
    1055,  1032,  1033,  1068,  1069,  1070,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,
    1048,  1071,  1049,  1050,  1051,  1052,  1053,  1054,  1074,  1076,
    1057,  1058,  1056,  1072,  1073,  1075,  1077,  1085,  1086,  1087,
    1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,
    1102,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1278,
    1116,  1121,  1122,  1123,  1290,  1301,  1124,  1302,  1125,  1303,
     310,   819,  1126,   757,  1127,  1128,  1129,  1246,  1130,  1324,
    1131,  1305,  1136,  1137,  1304,  1150,   771,  1151,  1152,  1300,
    1297,  1279,   749,  1299,  1153,   742,  1164,  1154,  1155,  1156,
     827,   738,  1157,  1158,   600,  1321,   649,  1167,  1165,  1306,
     777,  1168,  1169,  1170,  1194,  1195,  1196,  1197,  1198,  1223,
    1224,  1225,  1226,  1227,  1228,  1241,   503,  1298,   404,  1247,
    1242,  1243,  1248,  1293,   809,  1249,  1250,  1251,  1264,  1280,
     461,  1273,   326,  1294,  1307,  1281,  1282,  1283,  1308,  1309,
       0,     0,  1272,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   670,   554,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   585,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   666,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   676
};

static const yytype_int16 yycheck[] =
{
     646,   647,   312,    56,     1,   234,     1,   317,     8,   319,
     320,    52,     1,     1,   215,     1,   232,   233,   219,   215,
       1,     1,   234,   219,     1,   234,     6,     7,     1,     9,
      10,     1,     1,   232,    14,     1,   234,     1,   235,     1,
     232,     1,    22,    23,   236,   232,     1,   232,     1,   236,
     232,   236,    32,    39,   236,    35,   234,    30,   182,   183,
      40,   112,     1,    36,   234,    45,    46,   234,    48,    49,
      50,    51,     1,   232,     1,   128,   234,   236,    67,   234,
       1,   232,   234,    63,    64,   236,    39,    26,     1,     1,
      60,    30,    72,     1,   234,    81,   234,    67,    67,    69,
      81,    67,    82,   413,     1,   415,   416,   102,   234,    89,
       1,    91,   422,    93,   102,    95,   426,    97,    98,    81,
     430,     1,    61,   433,     1,   102,     1,   234,    81,   102,
     110,    70,   129,   443,   444,   115,   116,   117,   102,   119,
     120,   121,   102,   129,   124,   455,    67,   457,   458,   234,
     234,    90,   129,   194,    34,    94,   126,   234,   209,   234,
     129,    41,   203,   102,   232,   234,   105,   106,   236,     1,
     150,     1,    52,    53,   234,   102,   129,    57,    58,    59,
     160,   161,   162,   163,   164,   165,   166,    17,    18,   102,
     102,    21,    24,    25,   102,    27,    28,   178,   137,    79,
     129,    33,   129,   203,     1,   102,     1,   232,   129,   232,
     232,   236,     1,   236,   236,   154,   178,   232,   157,   158,
     159,   236,    99,   178,  1103,  1104,  1105,   102,   223,   226,
      19,   226,   234,    65,    66,   199,   216,   217,   218,    69,
     220,   221,   552,    75,    76,    77,   123,   233,    37,   229,
       1,    83,    84,   233,    84,    85,    86,    87,    88,   223,
     233,   235,    92,   233,   233,   204,    96,   233,    19,   233,
     225,   233,   102,   233,   171,   234,   108,   109,   233,   235,
      69,     1,   215,   113,   114,   235,    37,   178,   227,   228,
     235,     1,   189,   235,   233,   125,     1,   226,     3,   235,
       5,     1,    99,   235,   233,   235,   233,   102,   205,    19,
     223,   223,   235,   226,    19,   223,   235,   147,    69,    19,
     233,   233,   232,   633,   199,     1,   123,    37,   638,   235,
     235,   641,    37,   122,   225,   645,   233,    37,   232,   235,
      60,   130,   131,    44,   232,   235,   235,    67,   223,    69,
     112,   102,   235,   233,    30,    60,   233,    62,   127,    69,
      36,   191,   151,   235,    69,    11,    12,    13,   235,    69,
      71,   122,    73,    78,   235,   235,   171,   139,   140,   141,
     142,   143,   144,   145,   235,   235,   235,   138,   235,   235,
     235,   235,   102,   235,   189,   235,   235,   102,   235,   235,
     235,   233,   235,   233,   155,   156,   126,   235,   235,   235,
     205,   235,   122,   235,   235,   235,   235,   118,   235,   235,
     235,   126,   122,   235,   235,   235,   102,   235,   138,   235,
     130,   131,   235,   235,   135,   235,   235,   226,   178,   235,
     127,   146,   235,   235,   233,   155,   156,   235,   235,   235,
     155,   151,   235,   235,     4,   206,     1,   235,   235,   235,
     235,     6,     7,   235,     9,    10,   112,   235,   235,    14,
      20,   235,   235,   174,   175,   226,   235,    22,    23,   230,
     235,    31,   233,   235,   127,   235,   235,    32,   235,   235,
      35,   235,   235,   235,    44,    40,   206,   235,   235,   204,
      45,    46,   235,    48,    49,    50,    51,   235,   235,     1,
     235,   235,   235,   235,   235,   232,   226,   235,    63,    64,
     230,    71,   227,    73,   112,   226,   226,    72,   233,   112,
     231,   112,   112,   112,    26,   112,   112,    82,    30,   112,
     215,   215,    73,   232,    89,   235,    91,   232,    93,    99,
      95,   235,    97,    98,   832,   833,   834,   835,   836,   837,
     838,   127,   235,   235,   235,   110,   235,   235,    15,    61,
     115,   116,   117,   235,   119,   120,   121,   235,    70,   124,
     235,   235,   132,   235,   134,   235,   235,   235,   235,   112,
     232,    38,   112,    73,   235,   235,   235,  1243,    90,   235,
      47,   235,    94,   153,   135,   150,   235,   235,   235,   235,
     102,   235,   235,   105,   106,   160,   161,   162,   163,   164,
     165,   166,   235,   235,     1,   175,     3,    74,     5,   235,
     180,   235,   232,   235,   184,   112,   167,   235,   188,   112,
     215,   215,    19,   193,   175,   137,   215,   197,   215,   112,
     215,   112,   215,   184,   215,   135,   103,   104,   208,   112,
      37,   211,   154,   213,   111,   157,   158,   159,   112,   112,
     112,   216,   217,   218,   224,   220,   221,   208,   112,   210,
     211,   231,   112,    60,   229,    62,   215,   167,   235,   136,
       0,     1,    69,   224,     4,   175,   215,     1,   235,   215,
     231,    78,   215,   215,   184,   152,    16,   215,   215,    19,
      20,   215,   204,    17,    18,   215,   215,    21,   112,    29,
     215,   215,   232,   232,    52,   102,    54,    55,   208,    39,
     210,   211,    42,    43,   235,   227,   228,   235,   235,   235,
     127,   232,   235,   127,   224,   235,   235,   235,   235,   126,
     235,   231,   235,   235,   232,   127,   232,   112,    68,   127,
     235,    71,   232,   235,   235,    69,     1,   214,   235,   146,
      80,   235,   232,    52,   127,    54,    55,   235,   155,   235,
      84,    85,    86,    87,    88,   235,   235,   235,    92,   235,
     100,   101,    96,   215,   235,   235,   235,   215,   102,    34,
     215,   215,   215,   215,   232,   215,    41,   112,   118,   113,
     114,   112,   127,    52,   127,   127,   127,    52,    53,   127,
     127,   125,    57,    58,    59,   135,   232,   204,   127,   127,
     127,   127,   127,   232,   235,   215,   232,   234,   148,   149,
     168,   169,   170,   147,    79,   173,   174,   232,   176,   177,
     227,   179,   235,   181,   235,   127,   184,   235,   186,   187,
     235,   232,   172,   232,   192,   235,   112,   232,   196,   235,
     232,   232,   200,   201,   202,   185,   232,   235,   232,   207,
     190,   232,   232,   232,   212,   195,   232,   191,   198,   168,
     169,   170,   232,   232,   173,   174,   232,   176,   177,   232,
     179,   232,   181,   232,   112,   184,   232,   186,   187,   232,
     112,   112,   112,   192,   112,   112,   127,   196,   112,   112,
     112,   200,   201,   202,   127,   215,   232,   112,   207,   168,
     169,   170,     1,   212,   173,   174,   127,   176,   177,   127,
     179,   127,   181,   235,   127,   184,   127,   186,   187,   127,
     127,   127,   127,   192,   232,    24,    25,   196,    27,    28,
     127,   200,   201,   202,    33,   127,   232,   232,   207,   127,
     127,   232,   232,   212,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   127,   232,   232,   232,
     232,   232,   232,   127,   232,   232,    65,    66,   232,   232,
     232,   232,   232,   232,   232,   232,    75,    76,    77,   232,
     232,   232,   232,   232,    83,    84,   232,   232,   232,   232,
     232,   112,   232,   232,   127,   232,   232,   232,   232,   127,
     127,   215,   127,   232,   127,   127,   232,   232,   127,   108,
     109,   112,   127,   232,   127,   235,   127,   215,   235,   127,
     232,   127,   232,   232,   127,   127,   215,   127,   232,   232,
     127,   127,   232,   235,   235,   127,   127,   232,   232,   232,
     127,   232,   232,   127,   127,   127,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   127,   232,   232,   232,   232,   232,   232,   127,   127,
     232,   232,   235,   232,   232,   235,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   112,
     232,   232,   232,   232,   127,   133,   232,   133,   232,   133,
      77,   592,   232,   507,   232,   232,   232,  1063,   232,  1323,
     232,  1287,   232,   232,  1285,   232,   523,   232,   232,  1277,
    1266,  1165,   494,  1275,   232,   484,   222,   232,   232,   232,
     605,   471,   232,   232,   301,  1296,   345,   232,   236,  1289,
     540,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   227,  1271,   118,   232,
     235,   235,   232,   235,   578,   232,   232,   232,   232,   232,
     171,  1135,    97,   232,   232,   237,   237,   237,   232,   232,
      -1,    -1,  1133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   398,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   293,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   379,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   408
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   239,     0,     1,     4,    16,    19,    20,    29,    39,
      42,    43,    68,    71,    80,   100,   101,   118,   135,   148,
     149,   172,   185,   190,   195,   198,   240,   245,   250,   270,
     276,   282,   290,   304,   325,   349,   363,   378,   385,   389,
     399,   408,   429,   435,   441,   445,   451,   508,   525,   232,
     233,   234,   234,   326,   409,   436,   234,   446,   234,   364,
     430,   350,   234,   277,   305,   379,   234,   234,   400,   234,
     283,   234,   390,     1,    30,    36,   102,   271,   272,   273,
     274,   275,     1,    24,    25,    27,    28,    33,    65,    66,
      75,    76,    77,    83,    84,   108,   109,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   234,   234,   234,     1,    67,   442,   443,
     444,   234,     1,     6,     7,     9,    10,    14,    22,    23,
      32,    35,    40,    45,    46,    48,    49,    50,    51,    63,
      64,    72,    82,    89,    91,    93,    95,    97,    98,   110,
     115,   116,   117,   119,   120,   121,   124,   150,   160,   161,
     162,   163,   164,   165,   166,   216,   217,   218,   220,   221,
     229,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   501,   505,   506,
     507,   234,   234,   234,     1,    99,   123,   246,   247,   248,
     249,   234,   234,   234,     1,    34,    41,    52,    53,    57,
      58,    59,    79,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,     1,    26,    30,    61,    70,    90,    94,
     102,   105,   106,   137,   154,   157,   158,   159,   204,   227,
     228,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     234,     1,   225,   291,   292,   293,   294,   295,   234,     1,
     102,   386,   387,   388,   234,   232,   235,   235,   235,   233,
     272,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   233,   510,     1,    17,    18,
      21,    69,    84,    85,    86,    87,    88,    92,    96,   102,
     113,   114,   125,   147,   191,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,     1,     3,     5,    19,    37,    60,
      62,    69,    78,   102,   126,   146,   155,   204,   227,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     424,   425,   426,   427,   428,     1,    67,   129,   437,   438,
     439,   440,   235,   233,   443,     1,   102,   129,   447,   448,
     449,   450,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   502,
     235,   498,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     233,   453,     1,    19,    37,    69,   122,   130,   131,   151,
     226,   365,   366,   367,   368,   369,   370,   371,   375,   376,
     377,     1,   129,   226,   431,   432,   433,   434,     1,    60,
      67,    69,   126,   351,   355,   356,   357,   361,   362,   232,
     235,   235,   233,   247,     1,    81,   178,   278,   279,   280,
     281,     1,    19,    37,    69,   102,   122,   138,   155,   156,
     206,   226,   230,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   321,     1,    39,    81,   129,
     380,   381,   382,   383,   384,   235,   235,   235,   235,   235,
     235,   235,   235,   233,   527,   232,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   233,   252,     1,   102,   223,   401,   402,
     403,   404,   232,   235,   233,   292,   178,     1,   102,   171,
     189,   205,   284,   285,   286,   287,   288,   289,   235,   233,
     387,     1,   102,   223,   226,   391,   392,   393,   394,   395,
     127,   127,   127,   232,   112,   112,   242,   112,   112,   215,
     112,   242,   112,   242,   242,   112,   112,   215,   215,   232,
     232,   235,   235,   235,   346,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   233,   328,
     232,   235,   235,   235,   235,   235,   235,   421,   235,   235,
     235,   235,   235,   235,   235,   233,   411,   235,   235,   233,
     438,   127,   232,   235,   235,   233,   448,   215,   242,   112,
     242,   242,   215,   112,   215,   112,   215,   242,   215,   112,
     112,   242,   112,   215,   215,   242,   112,   112,   242,   112,
     112,   112,   112,   215,   235,   215,   235,   215,   242,   242,
     215,   215,   215,   215,   219,   215,   219,   215,   215,   215,
     215,   112,   242,   215,   242,   242,   215,   232,   232,   235,
     235,   372,   235,   235,   235,   235,   235,   233,   366,   235,
     235,   233,   432,   232,   235,   235,   352,   235,   233,   356,
     127,   127,   232,   232,   235,   235,   233,   279,   232,   235,
     235,   322,   235,   235,   235,   235,   235,   318,   235,   235,
     233,   307,   232,   235,   235,   235,   233,   381,   215,   215,
     215,   127,   215,   215,   215,   242,   232,   112,   127,   215,
     127,   112,   112,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   232,   232,   235,   405,   233,   402,
     215,   232,   234,   232,   235,   235,   235,   235,   233,   285,
     127,   232,   232,   235,   396,   235,   233,   392,   232,   232,
     232,   232,   139,   140,   141,   142,   143,   144,   145,   241,
     242,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   112,   112,   242,   235,   112,   112,
     112,   242,   112,   112,   242,   127,   112,   112,   242,   112,
     244,   244,   232,   127,   182,   183,   127,   215,   127,   127,
     235,   127,   127,   112,   127,   127,   127,   127,   232,   127,
     127,   232,   232,   127,   127,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,    52,   168,   169,   170,   173,   174,   176,
     177,   179,   181,   184,   186,   187,   192,   196,   200,   201,
     202,   207,   212,   503,   504,   232,    52,    54,    55,   168,
     169,   170,   173,   174,   176,   177,   179,   181,   184,   186,
     187,   192,   196,   200,   201,   202,   207,   212,   499,   500,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     127,   215,   235,   127,   112,   127,   127,   127,   232,   127,
     127,   232,   127,   127,   235,   112,   359,   360,   232,   232,
     232,   127,   127,   232,   127,   215,   235,   127,   127,   127,
     127,   215,   235,   127,   127,   232,   127,   127,   127,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   127,   235,   232,   232,     1,
     102,   199,   223,   296,   297,   298,   299,   300,   127,   127,
     127,   127,   232,   232,   127,   235,   127,   232,   241,   241,
     241,   241,   241,   241,   241,   232,   232,   232,    56,   128,
     347,   348,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,    11,    12,    13,   243,   244,   232,   232,
     232,   232,   232,   232,   232,   232,   232,     8,   203,   422,
     423,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   236,   232,   236,   232,   232,    15,    38,
      47,    74,   103,   104,   111,   136,   152,   214,   373,   374,
     232,   232,   232,   232,   232,   232,   232,   232,   232,    52,
     194,   203,   353,   354,   222,   236,   358,   232,   232,   232,
     232,     4,    20,    31,    44,    71,    73,    99,   132,   134,
     153,   175,   180,   184,   188,   193,   197,   208,   211,   213,
     224,   231,   323,   324,   232,   232,   232,   232,   232,    52,
      54,    55,   168,   169,   170,   173,   174,   176,   177,   179,
     181,   184,   186,   187,   192,   196,   200,   201,   202,   207,
     212,   319,   320,   232,   232,   232,   232,   232,   232,    73,
     135,   167,   175,   184,   208,   210,   211,   224,   231,   406,
     407,   232,   235,   235,   301,   233,   297,   232,   232,   232,
     232,   232,    73,   135,   167,   175,   184,   208,   210,   211,
     224,   231,   397,   398,   232,   232,   236,   243,   243,   243,
     232,   236,   504,   500,   232,   236,   232,   236,   112,   360,
     232,   237,   237,   237,   232,   236,   232,   236,   232,   236,
     127,   209,   244,   235,   232,   232,   236,   348,   423,   374,
     354,   133,   133,   133,   324,   320,   407,   232,   232,   232,
      44,    71,    73,   118,   135,   174,   175,   226,   231,   302,
     303,   398,   232,   236,   303
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   238,   239,   239,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   241,   241,
     242,   242,   242,   242,   242,   242,   242,   242,   243,   243,
     244,   244,   244,   244,   245,   246,   246,   247,   247,   247,
     248,   249,   250,   251,   251,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   271,   272,   272,   272,   272,   273,   274,   275,
     277,   276,   278,   278,   279,   279,   279,   280,   281,   283,
     282,   284,   284,   285,   285,   285,   285,   285,   286,   287,
     288,   289,   290,   291,   291,   292,   292,   292,   293,   295,
     294,   296,   296,   297,   297,   297,   297,   298,   299,   299,
     301,   300,   302,   302,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   305,   304,   306,   306,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   318,   317,
     319,   319,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   322,   321,   323,   323,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   326,   325,   327,   327,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     346,   345,   347,   347,   348,   348,   350,   349,   352,   351,
     353,   353,   354,   354,   354,   355,   355,   356,   356,   356,
     356,   356,   358,   357,   359,   359,   360,   360,   361,   362,
     364,   363,   365,   365,   366,   366,   366,   366,   366,   366,
     366,   366,   366,   367,   368,   369,   370,   372,   371,   373,
     373,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   375,   376,   377,   379,   378,   380,   380,   381,   381,
     381,   381,   382,   383,   384,   385,   386,   386,   387,   387,
     388,   390,   389,   391,   391,   392,   392,   392,   392,   393,
     394,   396,   395,   397,   397,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   400,   399,   401,   401,   402,
     402,   402,   403,   405,   404,   406,   406,   407,   407,   407,
     407,   407,   407,   407,   407,   407,   407,   409,   408,   410,
     410,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   419,   421,   420,   422,   422,   423,
     423,   424,   425,   426,   427,   428,   430,   429,   431,   431,
     432,   432,   432,   433,   434,   436,   435,   437,   437,   438,
     438,   438,   439,   440,   441,   442,   442,   443,   443,   444,
     446,   445,   447,   447,   448,   448,   448,   449,   450,   451,
     452,   452,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     482,   483,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   498,   497,   499,   499,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   502,   501,   503,   503,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   505,   506,   507,   508,
     509,   509,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   526,   527,   527,   527,   527,   527,   527,
     527,   527,   527,   528,   529,   530,   531,   532,   533,   534,
     535
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
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
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
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
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 429 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 430 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 431 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 432 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 433 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2979 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2988 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 453 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2997 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 483 "conf_parser.y" /* yacc.c:1646  */
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
#line 3040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 523 "conf_parser.y" /* yacc.c:1646  */
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
#line 3101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 581 "conf_parser.y" /* yacc.c:1646  */
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
#line 3133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 610 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 618 "conf_parser.y" /* yacc.c:1646  */
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
#line 3161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 632 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
#if OPENSSL_VERSION_NUMBER >= 0x009080FFL && !defined(OPENSSL_NO_ECDH)
  int nid = 0;
  EC_KEY *key = NULL;

  if (conf_parser_ctx.pass == 2)
  {
    if ((nid = OBJ_sn2nid(yylval.string)) == 0)
    {
        conf_error_report("Ignoring serverinfo::ssl_dh_elliptic_curve -- unknown curve name");
        break;
    }

    if ((key = EC_KEY_new_by_curve_name(nid)) == NULL)
    {
      conf_error_report("Ignoring serverinfo::ssl_dh_elliptic_curve -- could not create curve");
      break;
    }

    SSL_CTX_set_tmp_ecdh(ConfigServerInfo.server_ctx, key);
    EC_KEY_free(key);
}
#endif
#endif
}
#line 3192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 660 "conf_parser.y" /* yacc.c:1646  */
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
#line 3210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 675 "conf_parser.y" /* yacc.c:1646  */
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
#line 3228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 690 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 700 "conf_parser.y" /* yacc.c:1646  */
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
#line 3258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 714 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 723 "conf_parser.y" /* yacc.c:1646  */
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
#line 3301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 751 "conf_parser.y" /* yacc.c:1646  */
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
#line 3332 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 779 "conf_parser.y" /* yacc.c:1646  */
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
#line 3360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 804 "conf_parser.y" /* yacc.c:1646  */
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
#line 3385 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 826 "conf_parser.y" /* yacc.c:1646  */
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
#line 3410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 848 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3419 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 865 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3431 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 874 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 883 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 895 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 899 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 916 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3490 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 922 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3499 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 931 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3508 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 935 "conf_parser.y" /* yacc.c:1646  */
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
#line 3526 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 953 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3535 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3544 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 965 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3553 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 971 "conf_parser.y" /* yacc.c:1646  */
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
#line 3574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 998 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1004 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1008 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3605 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1024 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1032 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1035 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3632 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1040 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3641 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1047 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3650 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1051 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3668 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1059 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3677 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1063 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3686 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1067 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3695 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1071 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3704 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1075 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3713 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1079 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3722 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1089 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3734 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1096 "conf_parser.y" /* yacc.c:1646  */
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

    if (block_state.whois.buf[0])
      conf->whois = xstrdup(block_state.whois.buf);

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
#line 3819 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3828 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1198 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1210 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1216 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3869 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1227 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3878 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1239 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1250 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1267 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1271 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1275 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1279 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1283 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1291 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1295 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 4000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1299 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 4009 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1303 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 4018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1307 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 4027 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1311 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4036 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1315 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1319 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1323 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4063 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1327 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1331 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1335 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4090 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1339 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1343 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4108 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1347 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1360 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1364 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1368 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4153 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1372 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4162 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1376 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4171 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1380 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4180 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1384 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4189 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1388 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4198 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1392 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4207 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1396 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1400 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4225 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1404 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4234 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1408 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4243 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1412 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4252 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1416 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4261 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1420 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1424 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4279 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1428 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1432 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4297 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1436 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4306 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1440 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4315 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1444 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1448 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1452 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1462 "conf_parser.y" /* yacc.c:1646  */
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
#line 4359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1474 "conf_parser.y" /* yacc.c:1646  */
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
#line 4412 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1543 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4421 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1549 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4430 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1555 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1561 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1567 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1573 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4466 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1579 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4475 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1585 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4484 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1591 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4493 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1597 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1603 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1610 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1616 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1622 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1628 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4551 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1637 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1646 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1653 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1657 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4590 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1667 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4599 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1673 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1679 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1683 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1687 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1695 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4640 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1700 "conf_parser.y" /* yacc.c:1646  */
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
#line 4658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1713 "conf_parser.y" /* yacc.c:1646  */
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
#line 4678 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1730 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4687 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1736 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4696 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1745 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1749 "conf_parser.y" /* yacc.c:1646  */
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
#line 4746 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1798 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4755 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1804 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1810 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1816 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4787 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1827 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4796 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4805 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1838 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1842 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1846 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1850 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1854 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1858 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1862 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1866 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1870 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1876 "conf_parser.y" /* yacc.c:1646  */
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
#line 4903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1890 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1899 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1912 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1919 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1930 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4959 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1936 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1942 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4977 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1957 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1972 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1983 "conf_parser.y" /* yacc.c:1646  */
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
#line 5025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 2000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 2006 "conf_parser.y" /* yacc.c:1646  */
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
#line 5056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 2025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5065 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2032 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2036 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2040 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2052 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2056 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2060 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2064 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2068 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5155 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 2077 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2086 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5184 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2101 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5193 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5202 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2114 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5211 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2118 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5220 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2122 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2126 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2130 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5247 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2134 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2138 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5265 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2142 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5274 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2146 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5283 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2150 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5292 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2159 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5306 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2168 "conf_parser.y" /* yacc.c:1646  */
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
#line 5372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2254 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2260 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2266 "conf_parser.y" /* yacc.c:1646  */
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
#line 5415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2279 "conf_parser.y" /* yacc.c:1646  */
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
#line 5431 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2298 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5449 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5458 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5467 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2314 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5475 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5484 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5493 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2330 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5516 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2347 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5525 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5534 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2359 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2374 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5557 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2378 "conf_parser.y" /* yacc.c:1646  */
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
#line 5582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2403 "conf_parser.y" /* yacc.c:1646  */
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
#line 5605 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2423 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5614 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2432 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5623 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2436 "conf_parser.y" /* yacc.c:1646  */
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
#line 5649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2462 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2468 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2482 "conf_parser.y" /* yacc.c:1646  */
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
#line 5684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2499 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2503 "conf_parser.y" /* yacc.c:1646  */
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
#line 5715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 467:
#line 2525 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2531 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2595 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2600 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2605 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2610 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5766 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2616 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.glines = yylval.number;
}
#line 5775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2622 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_time = (yyvsp[-1].number);
}
#line 5784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2628 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.gline_request_time = (yyvsp[-1].number);
}
#line 5793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2634 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr = (yyvsp[-1].number);
}
#line 5801 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2639 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2644 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5817 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2649 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2654 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5833 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2659 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2664 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2669 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5857 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2674 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2679 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2684 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2689 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2694 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2700 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2711 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2716 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2721 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2726 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2731 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2736 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2741 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2746 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2749 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2754 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 6000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 6008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2767 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 6016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 6024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 6032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2782 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 6040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 6048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_pass_resv = yylval.number;
}
#line 6056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2797 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 6064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2802 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2812 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2817 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2827 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2833 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2836 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2839 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2845 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2851 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2854 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6184 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2860 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2869 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2878 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2884 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2893 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2896 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2901 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2907 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2910 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2913 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2916 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2919 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2922 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2925 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2928 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2931 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2934 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2937 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2940 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2943 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2946 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2949 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2952 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2955 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2958 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2961 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2964 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 618:
#line 2979 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3008 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6488 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3013 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 3018 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 3023 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3028 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3033 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3038 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6536 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 3043 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6544 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3048 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6552 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 3053 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 3058 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6568 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 3063 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 3068 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6584 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 3073 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3095 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6601 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3101 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6610 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 666:
#line 3113 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6628 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 3119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6640 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 668:
#line 3128 "conf_parser.y" /* yacc.c:1646  */
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
#line 6658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 669:
#line 3143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 670:
#line 3149 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6676 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6680 "conf_parser.c" /* yacc.c:1646  */
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
