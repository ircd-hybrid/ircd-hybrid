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
    user,
    host,
    addr,
    bind,
    file,
    ciph,
    cert,
    rpass,
    spass,
    class;

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
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.mask.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.mask.list);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.leaf.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.leaf.list);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.hub.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.hub.list);
    free_dlink_node(ptr);
  }

  memset(&block_state, 0, sizeof(block_state));
}


#line 185 "conf_parser.c" /* yacc.c:339  */

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
    BYTES = 264,
    KBYTES = 265,
    MBYTES = 266,
    CALLER_ID_WAIT = 267,
    CAN_FLOOD = 268,
    CHANNEL = 269,
    CIDR_BITLEN_IPV4 = 270,
    CIDR_BITLEN_IPV6 = 271,
    CLASS = 272,
    CONNECT = 273,
    CONNECTFREQ = 274,
    CYCLE_ON_HOST_CHANGE = 275,
    DEFAULT_FLOODCOUNT = 276,
    DEFAULT_SPLIT_SERVER_COUNT = 277,
    DEFAULT_SPLIT_USER_COUNT = 278,
    DENY = 279,
    DESCRIPTION = 280,
    DIE = 281,
    DISABLE_AUTH = 282,
    DISABLE_FAKE_CHANNELS = 283,
    DISABLE_REMOTE_COMMANDS = 284,
    DOTS_IN_IDENT = 285,
    EGDPOOL_PATH = 286,
    EMAIL = 287,
    ENCRYPTED = 288,
    EXCEED_LIMIT = 289,
    EXEMPT = 290,
    FAILED_OPER_NOTICE = 291,
    FLATTEN_LINKS = 292,
    GECOS = 293,
    GENERAL = 294,
    GLINE = 295,
    GLINE_DURATION = 296,
    GLINE_ENABLE = 297,
    GLINE_EXEMPT = 298,
    GLINE_MIN_CIDR = 299,
    GLINE_MIN_CIDR6 = 300,
    GLINE_REQUEST_DURATION = 301,
    GLOBAL_KILL = 302,
    HAVENT_READ_CONF = 303,
    HIDDEN = 304,
    HIDDEN_NAME = 305,
    HIDE_CHANS = 306,
    HIDE_IDLE = 307,
    HIDE_IDLE_FROM_OPERS = 308,
    HIDE_SERVER_IPS = 309,
    HIDE_SERVERS = 310,
    HIDE_SERVICES = 311,
    HIDE_SPOOF_IPS = 312,
    HOST = 313,
    HUB = 314,
    HUB_MASK = 315,
    IGNORE_BOGUS_TS = 316,
    INVISIBLE_ON_CONNECT = 317,
    INVITE_CLIENT_COUNT = 318,
    INVITE_CLIENT_TIME = 319,
    IP = 320,
    IRCD_AUTH = 321,
    IRCD_FLAGS = 322,
    IRCD_SID = 323,
    JOIN_FLOOD_COUNT = 324,
    JOIN_FLOOD_TIME = 325,
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
    STATS_E_DISABLED = 414,
    STATS_I_OPER_ONLY = 415,
    STATS_K_OPER_ONLY = 416,
    STATS_O_OPER_ONLY = 417,
    STATS_P_OPER_ONLY = 418,
    STATS_U_OPER_ONLY = 419,
    T_ALL = 420,
    T_BOTS = 421,
    T_CALLERID = 422,
    T_CCONN = 423,
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
    T_MAX_CLIENTS = 438,
    T_NCHANGE = 439,
    T_NONONREG = 440,
    T_RECVQ = 441,
    T_REJ = 442,
    T_RESTART = 443,
    T_SERVER = 444,
    T_SERVICE = 445,
    T_SERVICES_NAME = 446,
    T_SERVNOTICE = 447,
    T_SET = 448,
    T_SHARED = 449,
    T_SIZE = 450,
    T_SKILL = 451,
    T_SOFTCALLERID = 452,
    T_SPY = 453,
    T_SSL = 454,
    T_SSL_CIPHER_LIST = 455,
    T_SSL_CLIENT_METHOD = 456,
    T_SSL_SERVER_METHOD = 457,
    T_SSLV3 = 458,
    T_TLSV1 = 459,
    T_UMODES = 460,
    T_UNAUTH = 461,
    T_UNDLINE = 462,
    T_UNLIMITED = 463,
    T_UNRESV = 464,
    T_UNXLINE = 465,
    T_WALLOP = 466,
    T_WALLOPS = 467,
    T_WEBIRC = 468,
    TBOOL = 469,
    THROTTLE_COUNT = 470,
    THROTTLE_TIME = 471,
    TKLINE_EXPIRE_NOTICES = 472,
    TMASKED = 473,
    TRUE_NO_OPER_FLOOD = 474,
    TS_MAX_DELTA = 475,
    TS_WARN_DELTA = 476,
    TWODOTS = 477,
    TYPE = 478,
    UNKLINE = 479,
    USE_EGD = 480,
    USE_LOGGING = 481,
    USER = 482,
    VHOST = 483,
    VHOST6 = 484,
    WARN_NO_CONNECT_BLOCK = 485,
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
#define BYTES 264
#define KBYTES 265
#define MBYTES 266
#define CALLER_ID_WAIT 267
#define CAN_FLOOD 268
#define CHANNEL 269
#define CIDR_BITLEN_IPV4 270
#define CIDR_BITLEN_IPV6 271
#define CLASS 272
#define CONNECT 273
#define CONNECTFREQ 274
#define CYCLE_ON_HOST_CHANGE 275
#define DEFAULT_FLOODCOUNT 276
#define DEFAULT_SPLIT_SERVER_COUNT 277
#define DEFAULT_SPLIT_USER_COUNT 278
#define DENY 279
#define DESCRIPTION 280
#define DIE 281
#define DISABLE_AUTH 282
#define DISABLE_FAKE_CHANNELS 283
#define DISABLE_REMOTE_COMMANDS 284
#define DOTS_IN_IDENT 285
#define EGDPOOL_PATH 286
#define EMAIL 287
#define ENCRYPTED 288
#define EXCEED_LIMIT 289
#define EXEMPT 290
#define FAILED_OPER_NOTICE 291
#define FLATTEN_LINKS 292
#define GECOS 293
#define GENERAL 294
#define GLINE 295
#define GLINE_DURATION 296
#define GLINE_ENABLE 297
#define GLINE_EXEMPT 298
#define GLINE_MIN_CIDR 299
#define GLINE_MIN_CIDR6 300
#define GLINE_REQUEST_DURATION 301
#define GLOBAL_KILL 302
#define HAVENT_READ_CONF 303
#define HIDDEN 304
#define HIDDEN_NAME 305
#define HIDE_CHANS 306
#define HIDE_IDLE 307
#define HIDE_IDLE_FROM_OPERS 308
#define HIDE_SERVER_IPS 309
#define HIDE_SERVERS 310
#define HIDE_SERVICES 311
#define HIDE_SPOOF_IPS 312
#define HOST 313
#define HUB 314
#define HUB_MASK 315
#define IGNORE_BOGUS_TS 316
#define INVISIBLE_ON_CONNECT 317
#define INVITE_CLIENT_COUNT 318
#define INVITE_CLIENT_TIME 319
#define IP 320
#define IRCD_AUTH 321
#define IRCD_FLAGS 322
#define IRCD_SID 323
#define JOIN_FLOOD_COUNT 324
#define JOIN_FLOOD_TIME 325
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
#define STATS_E_DISABLED 414
#define STATS_I_OPER_ONLY 415
#define STATS_K_OPER_ONLY 416
#define STATS_O_OPER_ONLY 417
#define STATS_P_OPER_ONLY 418
#define STATS_U_OPER_ONLY 419
#define T_ALL 420
#define T_BOTS 421
#define T_CALLERID 422
#define T_CCONN 423
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
#define T_MAX_CLIENTS 438
#define T_NCHANGE 439
#define T_NONONREG 440
#define T_RECVQ 441
#define T_REJ 442
#define T_RESTART 443
#define T_SERVER 444
#define T_SERVICE 445
#define T_SERVICES_NAME 446
#define T_SERVNOTICE 447
#define T_SET 448
#define T_SHARED 449
#define T_SIZE 450
#define T_SKILL 451
#define T_SOFTCALLERID 452
#define T_SPY 453
#define T_SSL 454
#define T_SSL_CIPHER_LIST 455
#define T_SSL_CLIENT_METHOD 456
#define T_SSL_SERVER_METHOD 457
#define T_SSLV3 458
#define T_TLSV1 459
#define T_UMODES 460
#define T_UNAUTH 461
#define T_UNDLINE 462
#define T_UNLIMITED 463
#define T_UNRESV 464
#define T_UNXLINE 465
#define T_WALLOP 466
#define T_WALLOPS 467
#define T_WEBIRC 468
#define TBOOL 469
#define THROTTLE_COUNT 470
#define THROTTLE_TIME 471
#define TKLINE_EXPIRE_NOTICES 472
#define TMASKED 473
#define TRUE_NO_OPER_FLOOD 474
#define TS_MAX_DELTA 475
#define TS_WARN_DELTA 476
#define TWODOTS 477
#define TYPE 478
#define UNKLINE 479
#define USE_EGD 480
#define USE_LOGGING 481
#define USER 482
#define VHOST 483
#define VHOST6 484
#define WARN_NO_CONNECT_BLOCK 485
#define XLINE 486

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 147 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 692 "conf_parser.c" /* yacc.c:355  */
};
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
#define YYLAST   1260

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  238
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  296
/* YYNRULES -- Number of rules.  */
#define YYNRULES  667
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1313

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
       0,   382,   382,   383,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   412,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   423,   423,   424,
     425,   426,   427,   434,   437,   437,   438,   438,   438,   440,
     446,   453,   455,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   477,   478,   480,   480,   481,   487,   495,
     495,   496,   502,   510,   552,   610,   638,   646,   674,   689,
     704,   713,   727,   736,   764,   794,   819,   841,   863,   872,
     874,   874,   875,   876,   877,   878,   880,   889,   898,   911,
     910,   928,   928,   929,   929,   929,   931,   937,   946,   947,
     947,   949,   949,   950,   952,   959,   959,   972,   973,   975,
     975,   976,   976,   978,   986,   989,   995,   994,  1000,  1000,
    1001,  1005,  1009,  1013,  1017,  1021,  1025,  1029,  1033,  1044,
    1043,  1123,  1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,
    1131,  1132,  1133,  1134,  1136,  1142,  1148,  1154,  1165,  1171,
    1177,  1188,  1195,  1194,  1200,  1200,  1201,  1205,  1209,  1213,
    1217,  1221,  1225,  1229,  1233,  1237,  1241,  1245,  1249,  1253,
    1257,  1261,  1265,  1269,  1273,  1277,  1281,  1285,  1292,  1291,
    1297,  1297,  1298,  1302,  1306,  1310,  1314,  1318,  1322,  1326,
    1330,  1334,  1338,  1342,  1346,  1350,  1354,  1358,  1362,  1366,
    1370,  1374,  1378,  1382,  1386,  1397,  1396,  1458,  1458,  1459,
    1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,  1469,
    1470,  1471,  1471,  1472,  1473,  1474,  1475,  1477,  1483,  1489,
    1495,  1501,  1507,  1513,  1519,  1525,  1531,  1537,  1544,  1550,
    1556,  1562,  1571,  1581,  1580,  1586,  1586,  1587,  1591,  1602,
    1601,  1608,  1607,  1612,  1612,  1613,  1617,  1621,  1627,  1627,
    1628,  1628,  1628,  1628,  1628,  1630,  1630,  1632,  1632,  1634,
    1648,  1666,  1672,  1682,  1681,  1723,  1723,  1724,  1725,  1726,
    1727,  1728,  1729,  1730,  1731,  1732,  1734,  1740,  1746,  1752,
    1764,  1763,  1769,  1769,  1770,  1774,  1778,  1782,  1786,  1790,
    1794,  1798,  1802,  1806,  1812,  1826,  1835,  1849,  1848,  1863,
    1863,  1864,  1864,  1864,  1864,  1866,  1872,  1878,  1888,  1890,
    1890,  1891,  1891,  1893,  1909,  1908,  1933,  1933,  1934,  1934,
    1934,  1934,  1936,  1942,  1962,  1961,  1967,  1967,  1968,  1972,
    1976,  1980,  1984,  1988,  1992,  1996,  2000,  2004,  2014,  2013,
    2034,  2034,  2035,  2035,  2035,  2037,  2044,  2043,  2049,  2049,
    2050,  2054,  2058,  2062,  2066,  2070,  2074,  2078,  2082,  2086,
    2096,  2095,  2167,  2167,  2168,  2169,  2170,  2171,  2172,  2173,
    2174,  2175,  2176,  2177,  2178,  2179,  2180,  2181,  2182,  2184,
    2190,  2196,  2202,  2215,  2228,  2234,  2240,  2244,  2253,  2252,
    2257,  2257,  2258,  2262,  2268,  2279,  2285,  2291,  2297,  2313,
    2312,  2338,  2338,  2339,  2339,  2339,  2341,  2361,  2371,  2370,
    2397,  2397,  2398,  2398,  2398,  2400,  2406,  2415,  2417,  2417,
    2418,  2418,  2420,  2438,  2437,  2460,  2460,  2461,  2461,  2461,
    2463,  2469,  2478,  2481,  2481,  2482,  2483,  2484,  2485,  2486,
    2487,  2488,  2489,  2490,  2491,  2492,  2493,  2494,  2495,  2496,
    2497,  2498,  2499,  2500,  2501,  2502,  2503,  2504,  2505,  2506,
    2507,  2508,  2509,  2510,  2511,  2512,  2513,  2514,  2515,  2516,
    2517,  2518,  2519,  2520,  2521,  2522,  2523,  2524,  2525,  2526,
    2527,  2528,  2529,  2530,  2531,  2532,  2535,  2540,  2546,  2552,
    2558,  2564,  2569,  2574,  2579,  2584,  2589,  2594,  2599,  2604,
    2609,  2614,  2619,  2624,  2629,  2635,  2646,  2651,  2656,  2661,
    2666,  2671,  2676,  2679,  2684,  2687,  2692,  2697,  2702,  2707,
    2712,  2717,  2722,  2727,  2732,  2737,  2742,  2747,  2756,  2765,
    2770,  2775,  2780,  2786,  2785,  2790,  2790,  2791,  2794,  2797,
    2800,  2803,  2806,  2809,  2812,  2815,  2818,  2821,  2824,  2827,
    2830,  2833,  2836,  2839,  2842,  2845,  2848,  2851,  2854,  2860,
    2859,  2864,  2864,  2865,  2868,  2871,  2874,  2877,  2880,  2883,
    2886,  2889,  2892,  2895,  2898,  2901,  2904,  2907,  2910,  2913,
    2916,  2919,  2922,  2927,  2932,  2937,  2946,  2949,  2949,  2950,
    2951,  2952,  2953,  2954,  2955,  2956,  2957,  2958,  2959,  2960,
    2961,  2962,  2963,  2964,  2966,  2971,  2976,  2981,  2986,  2991,
    2996,  3001,  3006,  3011,  3016,  3021,  3026,  3031,  3039,  3042,
    3042,  3043,  3044,  3045,  3046,  3047,  3048,  3049,  3050,  3051,
    3053,  3059,  3065,  3071,  3077,  3086,  3100,  3106
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ADMIN", "AFTYPE",
  "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME", "AUTOCONN", "BYTES",
  "KBYTES", "MBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL",
  "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CLASS", "CONNECT",
  "CONNECTFREQ", "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT",
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
  "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL",
  "T_BOTS", "T_CALLERID", "T_CCONN", "T_CLUSTER", "T_DEAF", "T_DEBUG",
  "T_DLINE", "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS",
  "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_NONONREG", "T_RECVQ", "T_REJ", "T_RESTART", "T_SERVER",
  "T_SERVICE", "T_SERVICES_NAME", "T_SERVNOTICE", "T_SET", "T_SHARED",
  "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL",
  "T_SSL_CIPHER_LIST", "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD",
  "T_SSLV3", "T_TLSV1", "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED",
  "T_UNRESV", "T_UNXLINE", "T_WALLOP", "T_WALLOPS", "T_WEBIRC", "TBOOL",
  "THROTTLE_COUNT", "THROTTLE_TIME", "TKLINE_EXPIRE_NOTICES", "TMASKED",
  "TRUE_NO_OPER_FLOOD", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "TYPE",
  "UNKLINE", "USE_EGD", "USE_LOGGING", "USER", "VHOST", "VHOST6",
  "WARN_NO_CONNECT_BLOCK", "XLINE", "';'", "'}'", "'{'", "'='", "','",
  "':'", "$accept", "conf", "conf_item", "timespec_", "timespec",
  "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_ssl_client_method",
  "serverinfo_ssl_server_method", "client_method_types",
  "client_method_type_item", "server_method_types",
  "server_method_type_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_ssl_dh_elliptic_curve",
  "serverinfo_name", "serverinfo_sid", "serverinfo_description",
  "serverinfo_network_name", "serverinfo_network_desc", "serverinfo_vhost",
  "serverinfo_vhost6", "serverinfo_max_clients",
  "serverinfo_max_nick_length", "serverinfo_max_topic_length",
  "serverinfo_hub", "admin_entry", "admin_items", "admin_item",
  "admin_name", "admin_email", "admin_description", "motd_entry", "$@1",
  "motd_items", "motd_item", "motd_mask", "motd_file", "logging_entry",
  "logging_items", "logging_item", "logging_use_logging",
  "logging_file_entry", "$@2", "logging_file_items", "logging_file_item",
  "logging_file_name", "logging_file_size", "logging_file_type", "$@3",
  "logging_file_type_items", "logging_file_type_item", "oper_entry", "$@4",
  "oper_items", "oper_item", "oper_name", "oper_user", "oper_password",
  "oper_encrypted", "oper_rsa_public_key_file",
  "oper_ssl_certificate_fingerprint", "oper_ssl_connection_required",
  "oper_class", "oper_umodes", "$@5", "oper_umodes_items",
  "oper_umodes_item", "oper_flags", "$@6", "oper_flags_items",
  "oper_flags_item", "class_entry", "$@7", "class_items", "class_item",
  "class_name", "class_ping_time", "class_number_per_ip",
  "class_connectfreq", "class_max_channels", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_recvq", "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "class_min_idle", "class_max_idle",
  "class_flags", "$@8", "class_flags_items", "class_flags_item",
  "listen_entry", "$@9", "listen_flags", "$@10", "listen_flags_items",
  "listen_flags_item", "listen_items", "listen_item", "listen_port",
  "$@11", "port_items", "port_item", "listen_address", "listen_host",
  "auth_entry", "$@12", "auth_items", "auth_item", "auth_user",
  "auth_passwd", "auth_class", "auth_encrypted", "auth_flags", "$@13",
  "auth_flags_items", "auth_flags_item", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@14", "resv_items", "resv_item",
  "resv_mask", "resv_reason", "resv_exempt", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@15",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@16", "shared_types", "shared_type_item",
  "cluster_entry", "$@17", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@18", "cluster_types", "cluster_type_item",
  "connect_entry", "$@19", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_ssl_certificate_fingerprint",
  "connect_port", "connect_aftype", "connect_flags", "$@20",
  "connect_flags_items", "connect_flags_item", "connect_encrypted",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_ssl_cipher_list", "kill_entry", "$@21", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@22",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@23",
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason",
  "general_entry", "general_items", "general_item", "general_max_watch",
  "general_cycle_on_host_change", "general_gline_enable",
  "general_gline_duration", "general_gline_request_duration",
  "general_gline_min_cidr", "general_gline_min_cidr6",
  "general_tkline_expire_notices", "general_kill_chase_time_limit",
  "general_hide_spoof_ips", "general_ignore_bogus_ts",
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
  "general_no_oper_flood", "general_true_no_oper_flood",
  "general_oper_pass_resv", "general_dots_in_ident", "general_max_targets",
  "general_use_egd", "general_egdpool_path", "general_services_name",
  "general_ping_cookie", "general_disable_auth", "general_throttle_count",
  "general_throttle_time", "general_oper_umodes", "$@24", "umode_oitems",
  "umode_oitem", "general_oper_only_umodes", "$@25", "umode_items",
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
     485,   486,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -880

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-880)))

#define YYTABLE_NINF -126

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -880,   707,  -880,  -177,  -165,  -159,  -880,  -880,  -880,  -150,
    -880,  -147,  -880,  -880,  -880,   -87,  -880,  -880,  -880,   -81,
     -74,  -880,   -62,   -55,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,    25,
     965,   -43,   -30,   -24,   125,   -15,   418,    -8,    51,    53,
      50,    72,    75,    77,   823,   464,    83,   118,    22,    89,
      -3,   -41,    68,    94,    12,  -880,  -880,  -880,  -880,  -880,
      96,   102,   106,   110,   112,   113,   114,   115,   117,   121,
     124,   126,   127,   134,     2,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
     667,   612,    60,  -880,   135,    28,  -880,  -880,    26,  -880,
     137,   142,   143,   145,   146,   147,   149,   150,   151,   153,
     154,   156,   158,   159,   160,   163,   165,   166,   167,   168,
     169,   170,   172,   173,   175,   176,   178,  -880,   179,  -880,
     181,   187,   192,   193,   194,   196,   197,   198,   199,   201,
     202,   206,   209,   212,   215,   218,   220,   221,   222,   223,
      61,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,   373,    11,   232,   119,   226,   234,    14,  -880,
    -880,  -880,     9,   450,   133,  -880,   235,   236,   237,   242,
     243,   246,   247,   249,     4,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,   128,   250,   251,   252,   253,   256,
     257,   258,   259,   261,   263,   264,   266,   267,   270,   271,
     273,   275,   277,   138,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,    30,   136,   279,    37,  -880,  -880,  -880,
     301,  -880,   283,    39,  -880,  -880,    46,  -880,   285,   290,
     392,   141,  -880,   408,   409,   308,   414,   415,   419,   415,
     424,   415,   415,   428,   429,   339,   341,   324,  -880,   325,
     326,   328,   329,  -880,   332,   336,   338,   340,   349,   350,
     351,   352,   354,   355,   356,   358,   359,   240,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,   327,   360,   364,   367,
     368,   369,   372,  -880,   375,   376,   377,   379,   381,   384,
     385,   297,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,   390,   391,
      15,  -880,  -880,  -880,   433,   342,  -880,  -880,   393,   395,
      33,  -880,  -880,  -880,   362,   415,   415,   394,   515,   417,
     520,   509,   426,   415,   427,   530,   532,   415,   534,   435,
     436,   437,   415,   542,   544,   415,   546,   550,   551,   555,
     447,   434,   457,   438,   460,   415,   415,   461,   462,   466,
    -197,  -196,   467,   470,   473,   561,   577,   415,   477,   480,
     415,   415,   481,   482,   468,  -880,   471,   463,   469,  -880,
     474,   484,   485,   487,   488,   182,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,   491,   492,    38,  -880,
    -880,  -880,   483,   493,   494,  -880,   495,  -880,    31,  -880,
    -880,  -880,  -880,  -880,   572,   578,   501,  -880,   504,   505,
     506,    18,  -880,  -880,  -880,   507,   508,   512,  -880,   513,
     522,   526,   529,   533,  -880,   535,   241,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,   518,   536,
     539,   540,    35,  -880,  -880,  -880,  -880,   498,   502,   503,
     617,   562,   563,   565,   415,   528,  -880,  -880,   638,   568,
     656,   672,   673,   663,   664,   674,   676,   677,   678,   679,
     688,   683,  -140,   116,   684,   686,   583,  -880,   584,   582,
    -880,    34,  -880,  -880,  -880,  -880,   605,   589,  -880,   592,
     700,   596,  -880,   597,   595,  -880,   598,    27,  -880,  -880,
    -880,  -880,   599,   600,   602,  -880,   603,   604,   606,   607,
     654,   609,   611,   613,   616,   618,   619,   625,   626,   627,
     630,  -880,  -880,   725,   751,   415,   614,   752,   753,   754,
     415,   755,   757,   415,   743,   759,   762,   415,   763,   763,
     648,  -880,  -880,   756,   155,   758,   668,   760,   761,   646,
     764,   765,   772,   766,   767,   768,   769,   658,  -880,   773,
     779,   666,  -880,   680,  -880,   782,   787,   685,  -880,   687,
     691,   693,   694,   695,   696,   698,   699,   704,   708,   714,
     718,   719,   721,   722,   727,   728,   729,   730,   732,   733,
     738,   742,   748,   774,   775,   776,   805,   777,   737,   778,
     780,   781,   783,   785,   786,   788,   789,   790,   791,   792,
     793,   794,   795,   798,   799,   800,   801,   804,   806,   807,
     811,  -880,  -880,   830,   702,   651,   857,   808,   858,   864,
     867,   812,  -880,   868,   869,   813,  -880,  -880,   871,   872,
     697,   888,   814,  -880,   815,   818,  -880,  -880,   877,   878,
     819,  -880,  -880,   887,   838,   784,   910,   926,   927,   928,
     842,   822,   931,   827,  -880,  -880,   933,   934,   935,   831,
    -880,   832,   833,   834,   835,   836,   837,   839,   840,  -880,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
     853,   854,   855,   856,  -880,  -880,  -190,  -880,  -880,  -880,
    -187,  -880,   859,   860,  -880,  -880,   943,   861,   862,  -880,
     863,  -880,    93,   865,  -880,  -880,   962,   866,   963,   870,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,   415,   415,
     415,   415,   415,   415,   415,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,   873,   874,   875,
     -33,   876,   879,   880,   881,   882,   883,   884,   885,   886,
     889,   890,   177,   891,   892,  -880,   893,   894,   895,   896,
     897,   898,   899,     1,   900,   901,   902,   903,   904,   905,
     906,  -880,   907,   908,  -880,  -880,   909,   911,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -184,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,   -67,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,   912,   913,   549,   914,   915,
     916,   917,   918,  -880,   919,   920,  -880,   921,   922,   -38,
     936,   923,  -880,  -880,  -880,  -880,   924,   925,  -880,   929,
     930,   525,   932,   937,   938,   939,   940,   771,   941,  -880,
     942,   944,   945,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -140,  -880,   116,
    -880,  -880,   946,   211,  -880,  -880,   947,   948,   949,  -880,
      13,  -880,  -880,  -880,  -880,  -880,   950,   637,   953,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,   -66,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,   763,   763,   763,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,   -40,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,   805,  -880,   737,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
     -34,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,   -31,  -880,   981,   888,   954,  -880,
    -880,  -880,  -880,  -880,   662,  -880,  -880,   951,  -880,  -880,
    -880,  -880,   952,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,   -29,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,   -23,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,    -5,  -880,  -880,   971,  -104,   955,   959,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
      47,  -880,  -880,  -880,   -33,  -880,  -880,  -880,  -880,     1,
    -880,  -880,  -880,   549,  -880,   -38,  -880,  -880,  -880,   966,
     967,   970,  -880,   525,  -880,   771,  -880,   211,   960,   961,
     964,     3,  -880,  -880,   637,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,    69,  -880,  -880,
    -880,     3,  -880
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   225,   390,   438,     0,
     453,     0,   293,   429,   269,     0,   109,   149,   327,     0,
       0,   368,     0,     0,   344,     3,    23,    11,     4,    24,
       5,     6,     8,     9,    10,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    21,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   102,   104,   103,   633,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   618,   632,   620,   621,   622,
     623,   624,   625,   619,   626,   627,   628,   629,   630,   631,
       0,     0,     0,   451,     0,     0,   449,   450,     0,   515,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   589,     0,   563,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   512,   514,   506,   507,   508,   509,   510,   505,
     475,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   502,   476,   477,   511,   479,   484,   485,   480,   482,
     481,   495,   496,   483,   486,   487,   488,   489,   478,   491,
     492,   493,   513,   503,   504,   500,   501,   494,   490,   498,
     499,   497,     0,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,     0,   659,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   650,   651,   652,   653,   654,
     657,   655,   656,   658,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    69,    70,    68,    65,    63,
      71,    64,    54,    67,    57,    58,    59,    55,    66,    60,
      61,    62,    56,     0,     0,     0,     0,   120,   121,   122,
       0,   342,     0,     0,   340,   341,     0,   105,     0,     0,
       0,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   617,     0,
       0,     0,     0,   263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   228,   229,
     232,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     230,   231,   233,   243,   244,   245,     0,     0,     0,     0,
       0,     0,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,   393,   394,   395,   396,   397,   398,   399,   401,
     400,   403,   407,   404,   405,   406,   402,   444,     0,     0,
       0,   441,   442,   443,     0,     0,   448,   459,     0,     0,
       0,   456,   457,   458,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   463,     0,     0,     0,   310,
       0,     0,     0,     0,     0,     0,   296,   297,   298,   299,
     304,   300,   301,   302,   303,   435,     0,     0,     0,   432,
     433,   434,     0,     0,     0,   271,     0,   281,     0,   279,
     280,   282,   283,    48,     0,     0,     0,    44,     0,     0,
       0,     0,   112,   113,   114,     0,     0,     0,   198,     0,
       0,     0,     0,     0,   172,     0,     0,   152,   153,   154,
     155,   158,   159,   160,   161,   157,   156,   162,     0,     0,
       0,     0,     0,   330,   331,   332,   333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   649,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
     376,     0,   371,   372,   373,   123,     0,     0,   119,     0,
       0,     0,   339,     0,     0,   354,     0,     0,   347,   348,
     349,   350,     0,     0,     0,    99,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   616,   246,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   408,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   392,     0,
       0,     0,   440,     0,   447,     0,     0,     0,   455,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   462,   305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,     0,   431,   284,     0,     0,
       0,     0,     0,   278,     0,     0,    43,   115,     0,     0,
       0,   111,   163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   334,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,     0,     0,   648,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,     0,    76,    81,    82,
       0,    80,     0,     0,    51,   374,     0,     0,     0,   370,
       0,   118,     0,     0,   338,   351,     0,     0,     0,     0,
     346,   108,   107,   106,   643,   642,   634,   635,    27,    27,
      27,    27,    27,    27,    27,    29,    28,   636,   646,   647,
     637,   638,   639,   641,   640,   644,   645,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   391,     0,     0,   439,   452,     0,     0,   454,   528,
     532,   547,   517,   615,   560,   554,   557,   527,   519,   518,
     521,   522,   520,   535,   525,   526,   536,   524,   531,   530,
     529,   555,   516,   613,   614,   551,   599,   593,   609,   594,
     595,   596,   604,   612,   597,   606,   610,   600,   611,   601,
     605,   598,   608,   603,   602,   607,     0,   592,   553,   572,
     573,   574,   567,   585,   568,   569,   570,   580,   588,   571,
     582,   586,   576,   587,   577,   581,   575,   584,   579,   578,
     583,     0,   566,   548,   546,   549,   559,   550,   538,   544,
     545,   542,   543,   539,   540,   541,   558,   561,   562,   523,
     552,   534,   533,   556,   537,     0,     0,     0,     0,     0,
       0,     0,     0,   294,     0,     0,   430,     0,     0,     0,
     289,   285,   288,   270,    49,    50,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
       0,     0,     0,   328,   661,   660,   666,   664,   667,   662,
     663,   665,    90,    98,    89,    96,    97,    88,    92,    91,
      84,    83,    87,    85,    95,    86,    73,     0,    74,     0,
      93,    94,     0,     0,   369,   124,     0,     0,     0,   136,
       0,   128,   129,   131,   130,   343,     0,     0,     0,   345,
      30,    31,    32,    33,    34,    35,    36,   258,   259,   250,
     268,   267,     0,   266,   251,   253,   255,   262,   254,   252,
     261,   247,   260,   249,   248,    37,    37,    37,    39,    38,
     256,   257,   413,   416,   417,   427,   424,   410,   425,   422,
     423,     0,   421,   426,   409,   415,   412,   414,   428,   411,
     445,   446,   460,   461,   590,     0,   564,     0,   308,   309,
     318,   315,   320,   316,   317,   323,   319,   321,   314,   322,
       0,   313,   307,   326,   325,   324,   306,   437,   436,   292,
     291,   276,   277,   275,     0,   274,     0,     0,     0,   116,
     117,   171,   167,   218,   205,   215,   214,   203,   208,   224,
     217,   222,   207,   210,   219,   221,   216,   223,   211,   213,
     220,   209,   212,     0,   201,   164,   166,   168,   169,   170,
     181,   182,   183,   176,   194,   177,   178,   179,   189,   197,
     180,   191,   195,   185,   196,   186,   190,   184,   193,   188,
     187,   192,     0,   175,   165,   337,   335,   336,    75,    79,
     375,   380,   386,   389,   382,   388,   383,   387,   385,   381,
     384,     0,   379,   132,     0,     0,     0,     0,   127,   352,
     358,   364,   367,   360,   366,   361,   365,   363,   359,   362,
       0,   357,   353,   264,     0,    40,    41,    42,   419,     0,
     591,   565,   311,     0,   272,     0,   290,   287,   286,     0,
       0,     0,   199,     0,   173,     0,   377,     0,     0,     0,
       0,     0,   126,   355,     0,   265,   420,   312,   273,   204,
     202,   206,   200,   174,   378,   133,   135,   134,   142,   147,
     146,   141,   144,   148,   145,   140,   143,     0,   139,   356,
     137,     0,   138
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -880,  -880,  -880,  -284,  -315,  -879,  -638,  -880,  -880,   969,
    -880,  -880,  -880,  -880,   956,  -880,  -880,  -880,    57,  -880,
      70,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  1035,
    -880,  -880,  -880,  -880,  -880,  -880,   631,  -880,  -880,  -880,
    -880,   824,  -880,  -880,  -880,  -880,    95,  -880,  -880,  -880,
    -880,  -880,  -201,  -880,  -880,  -880,   634,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -112,  -880,
    -880,  -880,  -108,  -880,  -880,  -880,   820,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,   -88,  -880,  -880,  -880,
    -880,  -880,   -97,  -880,   682,  -880,  -880,  -880,    24,  -880,
    -880,  -880,  -880,  -880,   712,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,   -69,  -880,  -880,  -880,  -880,  -880,  -880,   633,
    -880,  -880,  -880,  -880,  -880,   957,  -880,  -880,  -880,  -880,
     601,  -880,  -880,  -880,  -880,  -880,   -89,  -880,  -880,  -880,
     620,  -880,  -880,  -880,  -880,   -78,  -880,  -880,  -880,   821,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,   -59,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
     715,  -880,  -880,  -880,  -880,  -880,   809,  -880,  -880,  -880,
    -880,  1089,  -880,  -880,  -880,  -880,   796,  -880,  -880,  -880,
    -880,  1037,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
      78,  -880,  -880,  -880,    85,  -880,  -880,  -880,  -880,  -880,
    1114,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880,  -880,   968,  -880,  -880,
    -880,  -880,  -880,  -880,  -880,  -880
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   835,   836,  1098,  1099,    26,   228,   229,
     230,   231,    27,   273,   274,   275,   276,   796,   797,   800,
     801,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,    28,    74,    75,
      76,    77,    78,    29,    61,   511,   512,   513,   514,    30,
     296,   297,   298,   299,   300,  1060,  1061,  1062,  1063,  1064,
    1236,  1307,  1308,    31,    62,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   761,  1212,  1213,   537,
     755,  1183,  1184,    32,    51,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   626,  1082,  1083,    33,    59,   497,
     740,  1154,  1155,   498,   499,   500,  1158,  1001,  1002,   501,
     502,    34,    57,   475,   476,   477,   478,   479,   480,   481,
     725,  1140,  1141,   482,   483,   484,    35,    63,   542,   543,
     544,   545,   546,    36,   303,   304,   305,    37,    69,   597,
     598,   599,   600,   601,   817,  1250,  1251,    38,    66,   581,
     582,   583,   584,   807,  1231,  1232,    39,    52,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   649,
    1111,  1112,   392,   393,   394,   395,   396,    40,    58,   488,
     489,   490,   491,    41,    53,   400,   401,   402,   403,    42,
     115,   116,   117,    43,    55,   410,   411,   412,   413,    44,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   443,   961,
     962,   218,   441,   936,   937,   219,   220,   221,    45,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,    46,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     863,   864,   611,    79,   613,   235,   615,   616,   862,  1109,
     508,  1151,   485,    70,  1056,   225,   397,   705,   707,   508,
    1080,   706,   708,   301,    80,    81,    70,   407,   593,   113,
      82,   578,   492,   236,   407,   578,   538,    71,   294,   485,
     301,   237,  1046,  1298,    72,  1048,  1047,   593,  1124,  1049,
      71,   225,  1125,   238,   239,    47,    48,    72,   240,   241,
     242,   397,   119,   794,   795,    83,    84,   120,   121,    49,
     539,    85,    86,   122,  1299,    50,  1300,    87,    88,    89,
     398,   123,   124,   243,    54,    90,    91,    56,   125,   493,
     509,   126,   127,   114,  1056,  1081,   494,   128,   495,   509,
     670,   671,   129,   130,  1279,   131,   132,   133,   678,   134,
      92,    93,   682,   226,    73,  1057,   540,   687,   135,   294,
     690,  1301,   136,   137,   302,   398,   113,    73,   408,   594,
     700,   701,   579,   138,   538,   408,   579,   227,  1302,   254,
     486,   302,   714,   139,   399,   717,   718,    60,   594,   226,
     140,  1152,   141,    64,   142,   409,   143,   496,   144,   145,
      65,  1153,   409,   255,   541,  1126,  1253,   486,   539,  1127,
    1254,   146,    67,   227,  1303,  1304,   147,   148,   149,    68,
     150,   151,   152,   466,   510,   153,  1095,  1096,  1097,   399,
     114,   110,  1258,   510,   308,  1057,  1259,   256,  1262,   467,
    1110,  1264,  1263,  1272,   111,  1265,   257,  1273,  1058,  1274,
     112,   154,  -125,  1275,   540,   468,  1255,  1256,  1257,   118,
     155,   156,   157,   158,   159,   160,   222,  1276,   258,   307,
    1305,  1277,   259,   492,  1306,   327,  1059,   555,   487,   778,
     260,   329,   515,   261,   262,   311,  1237,   506,   661,   469,
     595,   750,   161,   580,   596,   330,   331,   580,   516,   332,
     819,   405,   541,   295,   742,   487,   667,   808,   769,   595,
     587,   735,   591,   596,   517,   263,   162,   163,   164,  1283,
     165,   166,   167,  1284,  1221,   223,   168,   224,  1058,   862,
     493,   169,   264,  -125,   464,   265,   266,   494,   366,   495,
     367,  1310,   368,   309,   470,  1311,   232,   333,   518,   233,
     849,   234,   471,   472,   369,   854,  1059,   293,   857,   798,
     799,   267,   861,   306,   334,   335,   336,   337,   338,   310,
     370,   313,   339,   473,   867,   868,   340,   314,   268,   269,
     270,   315,   341,   519,   295,   316,  1222,   317,   318,   319,
     320,   503,   321,   342,   343,   371,   322,   372,   496,   323,
     557,   324,   325,   520,   373,   344,   271,   272,   585,   326,
     404,   576,   414,   605,   466,   374,  1223,   415,   416,   521,
     417,   418,   419,  1224,   420,   421,   422,   345,   423,   424,
     467,   425,  1225,   426,   427,   428,   522,   523,   429,   375,
     430,   431,   432,   433,   434,   435,   468,   436,   437,   474,
     438,   439,   602,   440,   442,   731,   444,   603,  1226,   119,
    1227,  1228,   445,   376,   120,   121,   346,   446,   447,   448,
     122,   449,   450,   451,   452,  1229,   453,   454,   123,   124,
     469,   455,  1230,   377,   456,   125,   524,   457,   126,   127,
     458,   515,   378,   459,   128,   460,   461,   462,   463,   129,
     130,   504,   131,   132,   133,   254,   134,   516,   525,   505,
     547,   548,   549,   640,   763,   135,   589,   550,   551,   136,
     137,   552,   553,   517,   554,   558,   559,   560,   561,   255,
     138,   562,   563,   564,   565,   470,   566,   379,   567,   568,
     139,   569,   570,   471,   472,   571,   572,   140,   573,   141,
     574,   142,   575,   143,   586,   144,   145,   518,   590,   604,
     606,   607,   608,   256,   473,   380,   609,   610,   146,  1163,
     657,   612,   257,   147,   148,   149,   614,   150,   151,   152,
     617,   618,   153,  1164,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1165,   519,   619,   258,   620,   621,   622,   259,   642,
     663,   623,  1130,   624,   625,  1166,   260,   627,   154,   261,
     262,   628,   520,   629,   664,   630,   669,   155,   156,   157,
     158,   159,   160,  1131,   631,   632,   633,   634,   521,   635,
     636,   637,  1132,   638,   639,   643,  1167,  1280,  1168,   644,
     474,   263,   645,   646,   647,   522,   523,   648,   672,   161,
     650,   651,   652,   366,   653,   367,   654,   368,   264,   655,
     656,   265,   266,  1133,  1169,   659,   660,   673,   665,   369,
     666,   674,   675,   162,   163,   164,   676,   165,   166,   167,
     677,   679,   680,   168,   681,   370,   683,   267,   169,   684,
     685,   686,  1134,  1135,   688,   524,   689,  1170,   691,  1171,
    1136,   695,   692,   693,   268,   269,   270,   694,   329,   696,
     371,   697,   372,   698,   699,   702,   703,   525,  1172,   373,
     704,   709,   330,   331,   710,  1137,   332,   711,   712,   713,
     374,   715,   271,   272,   716,   719,   720,  1173,   723,   744,
     721,  1138,  1174,   722,   724,   745,  1175,     2,     3,   726,
    1240,     4,   771,  1176,   375,   737,   772,   773,  1177,   727,
     728,     5,   729,   730,     6,     7,   733,   734,   738,   739,
     741,     8,  1178,   746,   333,  1179,   747,  1180,   376,   752,
     748,   749,     9,   753,   774,    10,    11,   754,   756,  1181,
     765,   334,   335,   336,   337,   338,  1182,   757,   377,   339,
     779,   758,  1139,   340,   759,   780,   610,   378,   760,   341,
     762,   766,  1241,    12,   767,   768,   775,   776,    13,   777,
     342,   343,   781,   782,   783,   784,   939,    14,   940,   941,
     785,   786,   344,   828,   829,   830,   831,   832,   833,   834,
     792,   787,  1242,   788,   789,   790,   791,    15,    16,  1243,
     793,   802,   379,   803,   345,   804,   805,   806,  1244,   810,
    1190,   811,  1191,  1192,   235,    17,   812,   813,   814,   815,
     816,   821,   822,   818,   823,   824,   825,   847,   826,   827,
     380,   837,    18,   838,  1245,   839,  1246,  1247,   840,   850,
     841,   842,   236,   346,   916,    19,    20,   843,   844,   845,
     237,  1248,   846,   848,   851,   852,   853,   855,  1249,   856,
     858,   859,   238,   239,   860,   862,    21,   240,   241,   242,
     865,   873,   870,   866,   876,   869,   987,   871,   872,    22,
     881,   874,   875,   877,   878,   879,   880,    23,   884,  1269,
     882,    24,   243,   942,   943,   944,   883,   945,   946,   886,
     947,   948,   885,   949,   887,   950,   986,   888,   951,   889,
     989,   952,   953,   890,   954,   891,   892,   893,   894,   955,
     895,   896,   999,   956,   957,   958,   897,  1193,  1194,  1195,
     898,  1196,  1197,   959,  1198,  1199,   899,  1200,   960,  1201,
     900,   901,  1202,   902,   903,  1203,  1204,   985,  1205,   904,
     905,   906,   907,  1206,   908,   909,    79,  1207,  1208,  1209,
     910,   917,   918,   919,   911,   920,   921,  1210,   922,   923,
     912,   924,  1211,   925,   988,   990,   926,    80,    81,   927,
     928,   991,   929,    82,   992,   994,   995,   930,   997,   998,
    1000,   931,   932,   933,  1006,  1007,   913,   914,   915,   938,
     963,   934,   964,   965,  1009,   966,   935,   967,   968,  1011,
     969,   970,   971,   972,   973,   974,   975,   976,    83,    84,
     977,   978,   979,   980,    85,    86,   981,  1012,   982,   983,
      87,    88,    89,   984,   993,   996,  1003,  1004,    90,    91,
    1005,  1008,  1010,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,
    1052,  1030,  1031,    92,    93,  1032,  1033,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1066,
    1068,  1050,  1051,  1266,  1054,  1055,  1053,  1065,  1278,  1289,
    1290,  1067,  1069,  1291,  1218,  1077,  1078,  1079,  1084,   312,
    1312,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1219,
     588,  1093,  1094,  1100,  1101,  1102,  1103,  1104,  1105,  1106,
    1107,  1108,  1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,
    1121,  1122,   751,  1123,  1128,  1129,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1238,  1159,  1160,  1156,  1157,
     764,  1161,  1162,  1293,  1185,  1292,  1285,   641,  1288,  1186,
    1187,  1188,  1189,  1214,  1215,   770,  1216,  1217,  1220,  1233,
     743,  1267,  1239,  1234,  1235,  1252,  1268,   732,  1270,  1271,
    1281,  1282,  1295,  1296,  1287,  1309,  1297,   507,   820,  1294,
    1286,   809,   658,   736,   406,  1261,   668,   465,   328,   662,
    1260,     0,   556,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   577,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     592
};

static const yytype_int16 yycheck[] =
{
     638,   639,   317,     1,   319,     1,   321,   322,   112,     8,
       1,    49,     1,     1,     1,     1,     1,   214,   214,     1,
      53,   218,   218,     1,    22,    23,     1,     1,     1,     1,
      28,     1,     1,    29,     1,     1,     1,    25,     1,     1,
       1,    37,   232,    40,    32,   232,   236,     1,   232,   236,
      25,     1,   236,    49,    50,   232,   233,    32,    54,    55,
      56,     1,     1,   203,   204,    63,    64,     6,     7,   234,
      35,    69,    70,    12,    71,   234,    73,    75,    76,    77,
      65,    20,    21,    79,   234,    83,    84,   234,    27,    58,
      81,    30,    31,    65,     1,   128,    65,    36,    67,    81,
     415,   416,    41,    42,   208,    44,    45,    46,   423,    48,
     108,   109,   427,    99,   102,   102,    81,   432,    57,     1,
     435,   118,    61,    62,   102,    65,     1,   102,   102,   102,
     445,   446,   102,    72,     1,   102,   102,   123,   135,     1,
     129,   102,   457,    82,   129,   460,   461,   234,   102,    99,
      89,   189,    91,   234,    93,   129,    95,   126,    97,    98,
     234,   199,   129,    25,   129,   232,   232,   129,    35,   236,
     236,   110,   234,   123,   171,   172,   115,   116,   117,   234,
     119,   120,   121,     1,   175,   124,     9,    10,    11,   129,
      65,   234,   232,   175,   235,   102,   236,    59,   232,    17,
     199,   232,   236,   232,   234,   236,    68,   236,   195,   232,
     234,   150,   175,   236,    81,    33,  1095,  1096,  1097,   234,
     159,   160,   161,   162,   163,   164,   234,   232,    90,   232,
     227,   236,    94,     1,   231,   233,   223,   233,   227,   554,
     102,     1,     1,   105,   106,   233,   233,   233,   233,    67,
     223,   233,   191,   223,   227,    15,    16,   223,    17,    19,
     233,   233,   129,   226,   233,   227,   233,   233,   233,   223,
     233,   233,   233,   227,    33,   137,   215,   216,   217,   232,
     219,   220,   221,   236,    73,   234,   225,   234,   195,   112,
      58,   230,   154,   175,   233,   157,   158,    65,     1,    67,
       3,   232,     5,   235,   122,   236,   234,    67,    67,   234,
     625,   234,   130,   131,    17,   630,   223,   234,   633,   203,
     204,   183,   637,   234,    84,    85,    86,    87,    88,   235,
      33,   235,    92,   151,   179,   180,    96,   235,   200,   201,
     202,   235,   102,   102,   226,   235,   135,   235,   235,   235,
     235,   232,   235,   113,   114,    58,   235,    60,   126,   235,
     232,   235,   235,   122,    67,   125,   228,   229,   232,   235,
     235,   233,   235,   232,     1,    78,   165,   235,   235,   138,
     235,   235,   235,   172,   235,   235,   235,   147,   235,   235,
      17,   235,   181,   235,   235,   235,   155,   156,   235,   102,
     235,   235,   235,   235,   235,   235,    33,   235,   235,   227,
     235,   235,   127,   235,   235,   233,   235,   127,   207,     1,
     209,   210,   235,   126,     6,     7,   186,   235,   235,   235,
      12,   235,   235,   235,   235,   224,   235,   235,    20,    21,
      67,   235,   231,   146,   235,    27,   205,   235,    30,    31,
     235,     1,   155,   235,    36,   235,   235,   235,   235,    41,
      42,   235,    44,    45,    46,     1,    48,    17,   227,   235,
     235,   235,   235,   233,   233,    57,   175,   235,   235,    61,
      62,   235,   235,    33,   235,   235,   235,   235,   235,    25,
      72,   235,   235,   235,   235,   122,   235,   200,   235,   235,
      82,   235,   235,   130,   131,   235,   235,    89,   235,    91,
     235,    93,   235,    95,   235,    97,    98,    67,   235,   127,
     112,   112,   214,    59,   151,   228,   112,   112,   110,     4,
     233,   112,    68,   115,   116,   117,   112,   119,   120,   121,
     112,   112,   124,    18,   828,   829,   830,   831,   832,   833,
     834,    26,   102,   214,    90,   214,   232,   232,    94,   232,
     127,   235,    13,   235,   235,    40,   102,   235,   150,   105,
     106,   235,   122,   235,   232,   235,   214,   159,   160,   161,
     162,   163,   164,    34,   235,   235,   235,   235,   138,   235,
     235,   235,    43,   235,   235,   235,    71,  1235,    73,   235,
     227,   137,   235,   235,   235,   155,   156,   235,   214,   191,
     235,   235,   235,     1,   235,     3,   235,     5,   154,   235,
     235,   157,   158,    74,    99,   235,   235,   112,   235,    17,
     235,   214,   112,   215,   216,   217,   127,   219,   220,   221,
     214,   214,   112,   225,   112,    33,   112,   183,   230,   214,
     214,   214,   103,   104,   112,   205,   112,   132,   112,   134,
     111,   214,   112,   112,   200,   201,   202,   112,     1,   235,
      58,   214,    60,   235,   214,   214,   214,   227,   153,    67,
     214,   214,    15,    16,   214,   136,    19,   214,   127,   112,
      78,   214,   228,   229,   214,   214,   214,   172,   235,   127,
     232,   152,   177,   232,   235,   127,   181,     0,     1,   235,
      73,     4,   214,   188,   102,   232,   214,   214,   193,   235,
     235,    14,   235,   235,    17,    18,   235,   235,   235,   235,
     235,    24,   207,   232,    67,   210,   232,   212,   126,   232,
     235,   235,    35,   235,   127,    38,    39,   235,   235,   224,
     232,    84,    85,    86,    87,    88,   231,   235,   146,    92,
     232,   235,   213,    96,   235,   127,   112,   155,   235,   102,
     235,   235,   135,    66,   235,   235,   214,   214,    71,   214,
     113,   114,   214,   127,   112,   112,    49,    80,    51,    52,
     127,   127,   125,   139,   140,   141,   142,   143,   144,   145,
     112,   127,   165,   127,   127,   127,   127,   100,   101,   172,
     127,   127,   200,   127,   147,   232,   232,   235,   181,   214,
      49,   232,    51,    52,     1,   118,   234,   127,   232,   232,
     235,   232,   232,   235,   232,   232,   232,   112,   232,   232,
     228,   232,   135,   232,   207,   232,   209,   210,   232,   235,
     232,   232,    29,   186,    49,   148,   149,   232,   232,   232,
      37,   224,   232,   112,   112,   112,   112,   112,   231,   112,
     127,   112,    49,    50,   112,   112,   169,    54,    55,    56,
     232,   235,   214,   127,   112,   127,   235,   127,   127,   182,
     232,   127,   127,   127,   127,   127,   127,   190,   232,   237,
     127,   194,    79,   166,   167,   168,   127,   170,   171,   127,
     173,   174,   232,   176,   127,   178,   214,   232,   181,   232,
     112,   184,   185,   232,   187,   232,   232,   232,   232,   192,
     232,   232,   235,   196,   197,   198,   232,   166,   167,   168,
     232,   170,   171,   206,   173,   174,   232,   176,   211,   178,
     232,   232,   181,   232,   232,   184,   185,   127,   187,   232,
     232,   232,   232,   192,   232,   232,     1,   196,   197,   198,
     232,   166,   167,   168,   232,   170,   171,   206,   173,   174,
     232,   176,   211,   178,   127,   127,   181,    22,    23,   184,
     185,   127,   187,    28,   127,   127,   127,   192,   127,   127,
     112,   196,   197,   198,   127,   127,   232,   232,   232,   232,
     232,   206,   232,   232,   127,   232,   211,   232,   232,   235,
     232,   232,   232,   232,   232,   232,   232,   232,    63,    64,
     232,   232,   232,   232,    69,    70,   232,   127,   232,   232,
      75,    76,    77,   232,   232,   232,   232,   232,    83,    84,
     232,   232,   214,   127,   127,   127,   214,   235,   127,   232,
     127,   127,   127,   232,   232,   232,   232,   232,   232,   232,
     127,   232,   232,   108,   109,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   127,
     127,   232,   232,   112,   232,   232,   235,   232,   127,   133,
     133,   235,   232,   133,  1047,   232,   232,   232,   232,    74,
    1311,   232,   232,   232,   232,   232,   232,   232,   232,  1049,
     296,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   511,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,  1060,   232,   232,   222,   236,
     526,   232,   232,  1275,   232,  1273,  1254,   347,  1265,   232,
     232,   232,   232,   232,   232,   542,   232,   232,   232,   232,
     498,  1157,   232,   235,   235,   232,   232,   475,   237,   237,
     235,   232,   232,   232,  1263,  1284,   232,   228,   597,  1277,
    1259,   581,   381,   488,   115,  1127,   410,   170,    94,   400,
    1125,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   239,     0,     1,     4,    14,    17,    18,    24,    35,
      38,    39,    66,    71,    80,   100,   101,   118,   135,   148,
     149,   169,   182,   190,   194,   240,   245,   250,   275,   281,
     287,   301,   321,   345,   359,   374,   381,   385,   395,   404,
     425,   431,   437,   441,   447,   506,   523,   232,   233,   234,
     234,   322,   405,   432,   234,   442,   234,   360,   426,   346,
     234,   282,   302,   375,   234,   234,   396,   234,   234,   386,
       1,    25,    32,   102,   276,   277,   278,   279,   280,     1,
      22,    23,    28,    63,    64,    69,    70,    75,    76,    77,
      83,    84,   108,   109,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     234,   234,   234,     1,    65,   438,   439,   440,   234,     1,
       6,     7,    12,    20,    21,    27,    30,    31,    36,    41,
      42,    44,    45,    46,    48,    57,    61,    62,    72,    82,
      89,    91,    93,    95,    97,    98,   110,   115,   116,   117,
     119,   120,   121,   124,   150,   159,   160,   161,   162,   163,
     164,   191,   215,   216,   217,   219,   220,   221,   225,   230,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   499,   503,
     504,   505,   234,   234,   234,     1,    99,   123,   246,   247,
     248,   249,   234,   234,   234,     1,    29,    37,    49,    50,
      54,    55,    56,    79,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,     1,    25,    59,    68,    90,    94,
     102,   105,   106,   137,   154,   157,   158,   183,   200,   201,
     202,   228,   229,   251,   252,   253,   254,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   234,     1,   226,   288,   289,   290,   291,
     292,     1,   102,   382,   383,   384,   234,   232,   235,   235,
     235,   233,   277,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   233,   508,     1,
      15,    16,    19,    67,    84,    85,    86,    87,    88,    92,
      96,   102,   113,   114,   125,   147,   186,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,     1,     3,     5,    17,
      33,    58,    60,    67,    78,   102,   126,   146,   155,   200,
     228,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   420,   421,   422,   423,   424,     1,    65,   129,
     433,   434,   435,   436,   235,   233,   439,     1,   102,   129,
     443,   444,   445,   446,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   500,   235,   496,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   233,   449,     1,    17,    33,    67,
     122,   130,   131,   151,   227,   361,   362,   363,   364,   365,
     366,   367,   371,   372,   373,     1,   129,   227,   427,   428,
     429,   430,     1,    58,    65,    67,   126,   347,   351,   352,
     353,   357,   358,   232,   235,   235,   233,   247,     1,    81,
     175,   283,   284,   285,   286,     1,    17,    33,    67,   102,
     122,   138,   155,   156,   205,   227,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   317,     1,    35,
      81,   129,   376,   377,   378,   379,   380,   235,   235,   235,
     235,   235,   235,   235,   235,   233,   525,   232,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   233,   252,     1,   102,
     223,   397,   398,   399,   400,   232,   235,   233,   289,   175,
     235,   233,   383,     1,   102,   223,   227,   387,   388,   389,
     390,   391,   127,   127,   127,   232,   112,   112,   214,   112,
     112,   242,   112,   242,   112,   242,   242,   112,   112,   214,
     214,   232,   232,   235,   235,   235,   342,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     233,   324,   232,   235,   235,   235,   235,   235,   235,   417,
     235,   235,   235,   235,   235,   235,   235,   233,   407,   235,
     235,   233,   434,   127,   232,   235,   235,   233,   444,   214,
     242,   242,   214,   112,   214,   112,   127,   214,   242,   214,
     112,   112,   242,   112,   214,   214,   214,   242,   112,   112,
     242,   112,   112,   112,   112,   214,   235,   214,   235,   214,
     242,   242,   214,   214,   214,   214,   218,   214,   218,   214,
     214,   214,   127,   112,   242,   214,   214,   242,   242,   214,
     214,   232,   232,   235,   235,   368,   235,   235,   235,   235,
     235,   233,   362,   235,   235,   233,   428,   232,   235,   235,
     348,   235,   233,   352,   127,   127,   232,   232,   235,   235,
     233,   284,   232,   235,   235,   318,   235,   235,   235,   235,
     235,   314,   235,   233,   304,   232,   235,   235,   235,   233,
     377,   214,   214,   214,   127,   214,   214,   214,   242,   232,
     127,   214,   127,   112,   112,   127,   127,   127,   127,   127,
     127,   127,   112,   127,   203,   204,   255,   256,   203,   204,
     257,   258,   127,   127,   232,   232,   235,   401,   233,   398,
     214,   232,   234,   127,   232,   232,   235,   392,   235,   233,
     388,   232,   232,   232,   232,   232,   232,   232,   139,   140,
     141,   142,   143,   144,   145,   241,   242,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   112,   112,   242,
     235,   112,   112,   112,   242,   112,   112,   242,   127,   112,
     112,   242,   112,   244,   244,   232,   127,   179,   180,   127,
     214,   127,   127,   235,   127,   127,   112,   127,   127,   127,
     127,   232,   127,   127,   232,   232,   127,   127,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,    49,   166,   167,   168,
     170,   171,   173,   174,   176,   178,   181,   184,   185,   187,
     192,   196,   197,   198,   206,   211,   501,   502,   232,    49,
      51,    52,   166,   167,   168,   170,   171,   173,   174,   176,
     178,   181,   184,   185,   187,   192,   196,   197,   198,   206,
     211,   497,   498,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   127,   214,   235,   127,   112,
     127,   127,   127,   232,   127,   127,   232,   127,   127,   235,
     112,   355,   356,   232,   232,   232,   127,   127,   232,   127,
     214,   235,   127,   127,   127,   127,   214,   235,   127,   232,
     127,   127,   127,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   236,   232,   236,
     232,   232,   127,   235,   232,   232,     1,   102,   195,   223,
     293,   294,   295,   296,   297,   232,   127,   235,   127,   232,
     241,   241,   241,   241,   241,   241,   241,   232,   232,   232,
      53,   128,   343,   344,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,     9,    10,    11,   243,   244,
     232,   232,   232,   232,   232,   232,   232,   232,   232,     8,
     199,   418,   419,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   236,   232,   236,   232,   232,
      13,    34,    43,    74,   103,   104,   111,   136,   152,   213,
     369,   370,   232,   232,   232,   232,   232,   232,   232,   232,
     232,    49,   189,   199,   349,   350,   222,   236,   354,   232,
     232,   232,   232,     4,    18,    26,    40,    71,    73,    99,
     132,   134,   153,   172,   177,   181,   188,   193,   207,   210,
     212,   224,   231,   319,   320,   232,   232,   232,   232,   232,
      49,    51,    52,   166,   167,   168,   170,   171,   173,   174,
     176,   178,   181,   184,   185,   187,   192,   196,   197,   198,
     206,   211,   315,   316,   232,   232,   232,   232,   256,   258,
     232,    73,   135,   165,   172,   181,   207,   209,   210,   224,
     231,   402,   403,   232,   235,   235,   298,   233,   294,   232,
      73,   135,   165,   172,   181,   207,   209,   210,   224,   231,
     393,   394,   232,   232,   236,   243,   243,   243,   232,   236,
     502,   498,   232,   236,   232,   236,   112,   356,   232,   237,
     237,   237,   232,   236,   232,   236,   232,   236,   127,   208,
     244,   235,   232,   232,   236,   344,   419,   370,   350,   133,
     133,   133,   320,   316,   403,   232,   232,   232,    40,    71,
      73,   118,   135,   171,   172,   227,   231,   299,   300,   394,
     232,   236,   300
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   238,   239,   239,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   241,   241,   242,
     242,   242,   242,   242,   242,   242,   242,   243,   243,   244,
     244,   244,   244,   245,   246,   246,   247,   247,   247,   248,
     249,   250,   251,   251,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   253,   254,   255,   255,   256,   256,   257,
     257,   258,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   276,   277,   277,   277,   277,   278,   279,   280,   282,
     281,   283,   283,   284,   284,   284,   285,   286,   287,   288,
     288,   289,   289,   289,   290,   292,   291,   293,   293,   294,
     294,   294,   294,   295,   296,   296,   298,   297,   299,   299,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   302,
     301,   303,   303,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   314,   313,   315,   315,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   318,   317,
     319,   319,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   322,   321,   323,   323,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   342,   341,   343,   343,   344,   344,   346,
     345,   348,   347,   349,   349,   350,   350,   350,   351,   351,
     352,   352,   352,   352,   352,   354,   353,   355,   355,   356,
     356,   357,   358,   360,   359,   361,   361,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   363,   364,   365,   366,
     368,   367,   369,   369,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   371,   372,   373,   375,   374,   376,
     376,   377,   377,   377,   377,   378,   379,   380,   381,   382,
     382,   383,   383,   384,   386,   385,   387,   387,   388,   388,
     388,   388,   389,   390,   392,   391,   393,   393,   394,   394,
     394,   394,   394,   394,   394,   394,   394,   394,   396,   395,
     397,   397,   398,   398,   398,   399,   401,   400,   402,   402,
     403,   403,   403,   403,   403,   403,   403,   403,   403,   403,
     405,   404,   406,   406,   407,   407,   407,   407,   407,   407,
     407,   407,   407,   407,   407,   407,   407,   407,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   415,   417,   416,
     418,   418,   419,   419,   420,   421,   422,   423,   424,   426,
     425,   427,   427,   428,   428,   428,   429,   430,   432,   431,
     433,   433,   434,   434,   434,   435,   436,   437,   438,   438,
     439,   439,   440,   442,   441,   443,   443,   444,   444,   444,
     445,   446,   447,   448,   448,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   476,   477,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   496,   495,   497,   497,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   500,
     499,   501,   501,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   503,   504,   505,   506,   507,   507,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     524,   525,   525,   525,   525,   525,   525,   525,   525,   525,
     526,   527,   528,   529,   530,   531,   532,   533
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     0,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     0,     1,     2,
       3,     3,     3,     5,     2,     1,     1,     1,     2,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     3,     1,     1,     1,     3,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     2,     4,     4,     4,     0,
       6,     2,     1,     1,     1,     2,     4,     4,     5,     2,
       1,     1,     1,     2,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
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
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4
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
        case 27:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2862 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 482 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2969 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 488 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2980 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 497 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 503 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 3002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 511 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
  {
    if (!ServerInfo.rsa_private_key_file)
    {
      conf_error_report("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_file(ServerInfo.server_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_certificate_file(ServerInfo.client_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not open/read certificate file");
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.server_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ServerInfo.client_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.server_ctx) ||
        !SSL_CTX_check_private_key(ServerInfo.client_ctx))
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }
  }
#endif
}
#line 3047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 553 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  BIO *file = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

  if (ServerInfo.rsa_private_key)
  {
    RSA_free(ServerInfo.rsa_private_key);
    ServerInfo.rsa_private_key = NULL;
  }

  if (ServerInfo.rsa_private_key_file)
  {
    MyFree(ServerInfo.rsa_private_key_file);
    ServerInfo.rsa_private_key_file = NULL;
  }

  ServerInfo.rsa_private_key_file = xstrdup(yylval.string);

  if ((file = BIO_new_file(yylval.string, "r")) == NULL)
  {
    conf_error_report("File open failed, ignoring");
    break;
  }

  ServerInfo.rsa_private_key = PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

  BIO_set_close(file, BIO_CLOSE);
  BIO_free(file);

  if (ServerInfo.rsa_private_key == NULL)
  {
    conf_error_report("Couldn't extract key, ignoring");
    break;
  }

  if (!RSA_check_key(ServerInfo.rsa_private_key))
  {
    RSA_free(ServerInfo.rsa_private_key);
    ServerInfo.rsa_private_key = NULL;

    conf_error_report("Invalid key, ignoring");
    break;
  }

  if (RSA_size(ServerInfo.rsa_private_key) < 128)
  {
    RSA_free(ServerInfo.rsa_private_key);
    ServerInfo.rsa_private_key = NULL;

    conf_error_report("Ignoring serverinfo::rsa_private_key_file -- need at least a 1024 bit key size");
  }
#endif
}
#line 3108 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 611 "conf_parser.y" /* yacc.c:1646  */
    {
/* TBD - XXX: error reporting */
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
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
          SSL_CTX_set_tmp_dh(ServerInfo.server_ctx, dh);

        DH_free(dh);
      }
    }
  }
#endif
}
#line 3139 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 639 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 647 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
#if OPENSSL_VERSION_NUMBER >= 0x1000005FL && !defined(OPENSSL_NO_ECDH)
  int nid = 0;
  EC_KEY *key = NULL;

  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
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

    SSL_CTX_set_tmp_ecdh(ServerInfo.server_ctx, key);
    EC_KEY_free(key);
}
#endif
#endif
}
#line 3181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 675 "conf_parser.y" /* yacc.c:1646  */
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.name)
  {
    if (valid_servname(yylval.string))
      ServerInfo.name = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
#line 3199 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 690 "conf_parser.y" /* yacc.c:1646  */
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      ServerInfo.sid = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
#line 3217 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 705 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
#line 3229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 714 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')))
      *p = '\0';

    MyFree(ServerInfo.network_name);
    ServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 728 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 737 "conf_parser.y" /* yacc.c:1646  */
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

      memcpy(&ServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip.ss.ss_family = res->ai_family;
      ServerInfo.ip.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
#line 3289 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 765 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
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

      memcpy(&ServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip6.ss.ss_family = res->ai_family;
      ServerInfo.ip6.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ServerInfo.specific_ipv6_vhost = 1;
    }
  }
#endif
}
#line 3322 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 795 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < MAXCLIENTS_MIN)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
    conf_error_report(buf);
    ServerInfo.max_clients = MAXCLIENTS_MIN;
  }
  else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);
    ServerInfo.max_clients = MAXCLIENTS_MAX;
  }
  else
    ServerInfo.max_clients = (yyvsp[-1].number);
}
#line 3350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 820 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 9)
  {
    conf_error_report("max_nick_length too low, setting to 9");
    ServerInfo.max_nick_length = 9;
  }
  else if ((yyvsp[-1].number) > NICKLEN)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
    conf_error_report(buf);
    ServerInfo.max_nick_length = NICKLEN;
  }
  else
    ServerInfo.max_nick_length = (yyvsp[-1].number);
}
#line 3375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 842 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 80)
  {
    conf_error_report("max_topic_length too low, setting to 80");
    ServerInfo.max_topic_length = 80;
  }
  else if ((yyvsp[-1].number) > TOPICLEN)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
    conf_error_report(buf);
    ServerInfo.max_topic_length = TOPICLEN;
  }
  else
    ServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 864 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 881 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3421 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 890 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 899 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3445 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 911 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 915 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
    motd_add(ptr->data, block_state.file.buf);
}
#line 3471 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 932 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 938 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 953 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 963 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 979 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 987 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 990 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 995 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3556 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1002 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1006 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1010 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1018 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3601 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1022 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3610 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1026 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1030 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3628 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3637 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1051 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

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

  DLINK_FOREACH(ptr, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = ptr->data;
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
        conf_error_report("Ignoring rsa_public_key_file -- file doesn't exist");
        break;
      }

      if ((pkey = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL)) == NULL)
        conf_error_report("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");

      conf->rsa_public_key = pkey;
      BIO_set_close(file, BIO_CLOSE);
      BIO_free(file);
    }
#endif /* HAVE_LIBCRYPTO */
  }
}
#line 3725 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1137 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3734 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3743 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1149 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3752 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1155 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3766 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1166 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1172 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1178 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3798 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1189 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3807 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1195 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1202 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1206 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3834 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1210 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3843 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1214 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1218 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1222 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3870 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1226 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1230 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1234 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1238 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1242 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1246 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1250 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1254 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1258 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1266 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3969 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1270 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1274 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3987 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1278 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3996 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1282 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4005 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1286 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4023 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1299 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1303 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4041 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1307 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4050 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1311 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4059 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1315 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1319 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1323 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1327 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4095 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1331 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1335 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4113 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1339 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4122 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1343 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4131 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1347 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4140 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1351 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1355 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4158 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1359 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4167 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1363 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1367 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4185 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1371 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4194 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1375 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4203 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1379 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1383 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4221 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1387 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1397 "conf_parser.y" /* yacc.c:1646  */
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
#line 4247 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1409 "conf_parser.y" /* yacc.c:1646  */
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
#line 4300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1478 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1484 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1490 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4327 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1496 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1502 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4345 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1508 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4354 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1514 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4363 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1520 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1526 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1532 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1538 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1545 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1551 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1557 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1563 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1572 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1581 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1588 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1592 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1602 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1608 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4495 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1614 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1618 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4513 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1622 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4522 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1630 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1635 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (block_state.flags.value & LISTENER_SSL)
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        conf_error_report("SSL not available - port closed");
        break;
      }
    add_listener((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1649 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (block_state.flags.value & LISTENER_SSL)
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        conf_error_report("SSL not available - port closed");
        break;
      }

    for (int i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      add_listener(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4568 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1667 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4577 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1673 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4586 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1682 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4595 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1686 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = ptr->data;
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
#line 4636 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1735 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4645 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1741 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4654 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1747 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4663 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1753 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4677 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1764 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4686 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1771 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4695 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1775 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4704 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1779 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4713 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1783 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4722 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1787 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4731 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1791 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4740 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1795 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1799 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4758 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1803 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4767 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1807 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1813 "conf_parser.y" /* yacc.c:1646  */
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
#line 4793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1827 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4805 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1836 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4817 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1849 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4829 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1856 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1867 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1873 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1879 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1894 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1909 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1920 "conf_parser.y" /* yacc.c:1646  */
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
#line 4915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1937 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1943 "conf_parser.y" /* yacc.c:1646  */
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
#line 4946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1969 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1973 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1977 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1981 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1985 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1989 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5009 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1993 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1997 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5027 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2001 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5036 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2005 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5059 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2023 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 2038 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2051 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2059 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2063 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2067 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2071 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2075 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5155 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2079 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2083 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2087 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2096 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2105 "conf_parser.y" /* yacc.c:1646  */
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
#line 5262 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2185 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5271 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5289 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2203 "conf_parser.y" /* yacc.c:1646  */
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
#line 5305 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2216 "conf_parser.y" /* yacc.c:1646  */
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
#line 5321 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5330 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2235 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5339 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2245 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2253 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2259 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5385 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2286 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2298 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5449 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2317 "conf_parser.y" /* yacc.c:1646  */
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
#line 5474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2342 "conf_parser.y" /* yacc.c:1646  */
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
#line 5497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2362 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2371 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2375 "conf_parser.y" /* yacc.c:1646  */
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
#line 5541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2401 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2407 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2421 "conf_parser.y" /* yacc.c:1646  */
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
#line 5576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2438 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 454:
#line 2442 "conf_parser.y" /* yacc.c:1646  */
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
#line 5607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2464 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2470 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2536 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2541 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2547 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2553 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5660 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2559 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5669 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2565 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5677 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2570 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5685 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2575 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2580 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5701 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2585 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2590 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5717 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2595 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5725 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2600 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2605 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number);
}
#line 5741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2610 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2615 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2620 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2625 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2630 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2636 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5796 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5804 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2652 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_connect_block = yylval.number;
}
#line 5812 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2657 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5820 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2662 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5828 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2667 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2672 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5844 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2677 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2680 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5860 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2685 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2688 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2693 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2698 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2703 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2708 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2713 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2718 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2723 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5932 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2728 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2733 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2738 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2743 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.use_egd = yylval.number;
}
#line 5964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
#line 5976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 5988 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2766 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 5996 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2771 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 6004 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2776 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_count = (yyvsp[-1].number);
}
#line 6012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2781 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = (yyvsp[-1].number);
}
#line 6020 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 6028 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 6036 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 6044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2798 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 6052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 6060 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 6068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 6076 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDECHANS;
}
#line 6084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 6100 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6108 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6132 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6140 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6148 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6172 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6180 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2860 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6220 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2869 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6244 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2878 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6252 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6260 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2884 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6268 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6276 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6284 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2893 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6292 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2896 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2899 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6308 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2902 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6316 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2908 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6332 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2911 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2914 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2917 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2920 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2923 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2928 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6380 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2933 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2938 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2967 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6404 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2972 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6412 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2977 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2982 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2987 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6436 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2992 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2997 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3002 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3007 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3012 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 3017 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6484 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3022 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 3027 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 3032 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6508 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3060 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6526 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6535 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3072 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6544 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3078 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6556 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3087 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (((yyvsp[-1].number) > 0) && ConfigServerHide.links_disabled == 1)
    {
      eventAddIsh("write_links_file", write_links_file, NULL, (yyvsp[-1].number));
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = (yyvsp[-1].number);
  }
}
#line 6573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 666:
#line 3101 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 3107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6591 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6595 "conf_parser.c" /* yacc.c:1646  */
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
