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
    SSL_MESSAGE_DIGEST_ALGORITHM = 414,
    STATS_E_DISABLED = 415,
    STATS_I_OPER_ONLY = 416,
    STATS_K_OPER_ONLY = 417,
    STATS_O_OPER_ONLY = 418,
    STATS_P_OPER_ONLY = 419,
    STATS_U_OPER_ONLY = 420,
    T_ALL = 421,
    T_BOTS = 422,
    T_CALLERID = 423,
    T_CCONN = 424,
    T_CLUSTER = 425,
    T_DEAF = 426,
    T_DEBUG = 427,
    T_DLINE = 428,
    T_EXTERNAL = 429,
    T_FARCONNECT = 430,
    T_FILE = 431,
    T_FULL = 432,
    T_GLOBOPS = 433,
    T_INVISIBLE = 434,
    T_IPV4 = 435,
    T_IPV6 = 436,
    T_LOCOPS = 437,
    T_LOG = 438,
    T_MAX_CLIENTS = 439,
    T_NCHANGE = 440,
    T_NONONREG = 441,
    T_RECVQ = 442,
    T_REJ = 443,
    T_RESTART = 444,
    T_SERVER = 445,
    T_SERVICE = 446,
    T_SERVICES_NAME = 447,
    T_SERVNOTICE = 448,
    T_SET = 449,
    T_SHARED = 450,
    T_SIZE = 451,
    T_SKILL = 452,
    T_SOFTCALLERID = 453,
    T_SPY = 454,
    T_SSL = 455,
    T_SSL_CIPHER_LIST = 456,
    T_SSL_CLIENT_METHOD = 457,
    T_SSL_SERVER_METHOD = 458,
    T_SSLV3 = 459,
    T_TLSV1 = 460,
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
    TRUE_NO_OPER_FLOOD = 475,
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
#define SSL_MESSAGE_DIGEST_ALGORITHM 414
#define STATS_E_DISABLED 415
#define STATS_I_OPER_ONLY 416
#define STATS_K_OPER_ONLY 417
#define STATS_O_OPER_ONLY 418
#define STATS_P_OPER_ONLY 419
#define STATS_U_OPER_ONLY 420
#define T_ALL 421
#define T_BOTS 422
#define T_CALLERID 423
#define T_CCONN 424
#define T_CLUSTER 425
#define T_DEAF 426
#define T_DEBUG 427
#define T_DLINE 428
#define T_EXTERNAL 429
#define T_FARCONNECT 430
#define T_FILE 431
#define T_FULL 432
#define T_GLOBOPS 433
#define T_INVISIBLE 434
#define T_IPV4 435
#define T_IPV6 436
#define T_LOCOPS 437
#define T_LOG 438
#define T_MAX_CLIENTS 439
#define T_NCHANGE 440
#define T_NONONREG 441
#define T_RECVQ 442
#define T_REJ 443
#define T_RESTART 444
#define T_SERVER 445
#define T_SERVICE 446
#define T_SERVICES_NAME 447
#define T_SERVNOTICE 448
#define T_SET 449
#define T_SHARED 450
#define T_SIZE 451
#define T_SKILL 452
#define T_SOFTCALLERID 453
#define T_SPY 454
#define T_SSL 455
#define T_SSL_CIPHER_LIST 456
#define T_SSL_CLIENT_METHOD 457
#define T_SSL_SERVER_METHOD 458
#define T_SSLV3 459
#define T_TLSV1 460
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
#define TRUE_NO_OPER_FLOOD 475
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
#line 147 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 694 "conf_parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 709 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1377

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  239
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  297
/* YYNRULES -- Number of rules.  */
#define YYNRULES  669
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1318

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
       0,   383,   383,   384,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   413,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   424,   424,   425,
     426,   427,   428,   435,   438,   438,   439,   439,   439,   441,
     447,   454,   456,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   479,   480,   482,   482,   483,   489,
     497,   497,   498,   504,   512,   554,   612,   640,   648,   661,
     689,   704,   719,   728,   742,   751,   779,   809,   834,   856,
     878,   887,   889,   889,   890,   891,   892,   893,   895,   904,
     913,   926,   925,   943,   943,   944,   944,   944,   946,   952,
     961,   962,   962,   964,   964,   965,   967,   974,   974,   987,
     988,   990,   990,   991,   991,   993,  1001,  1004,  1010,  1009,
    1015,  1015,  1016,  1020,  1024,  1028,  1032,  1036,  1040,  1044,
    1048,  1059,  1058,  1138,  1138,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,  1151,  1157,  1163,  1169,
    1180,  1186,  1192,  1203,  1210,  1209,  1215,  1215,  1216,  1220,
    1224,  1228,  1232,  1236,  1240,  1244,  1248,  1252,  1256,  1260,
    1264,  1268,  1272,  1276,  1280,  1284,  1288,  1292,  1296,  1300,
    1307,  1306,  1312,  1312,  1313,  1317,  1321,  1325,  1329,  1333,
    1337,  1341,  1345,  1349,  1353,  1357,  1361,  1365,  1369,  1373,
    1377,  1381,  1385,  1389,  1393,  1397,  1401,  1412,  1411,  1473,
    1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,  1481,  1482,
    1483,  1484,  1485,  1486,  1486,  1487,  1488,  1489,  1490,  1492,
    1498,  1504,  1510,  1516,  1522,  1528,  1534,  1540,  1546,  1552,
    1559,  1565,  1571,  1577,  1586,  1596,  1595,  1601,  1601,  1602,
    1606,  1617,  1616,  1623,  1622,  1627,  1627,  1628,  1632,  1636,
    1642,  1642,  1643,  1643,  1643,  1643,  1643,  1645,  1645,  1647,
    1647,  1649,  1663,  1681,  1687,  1697,  1696,  1738,  1738,  1739,
    1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,  1749,  1755,
    1761,  1767,  1779,  1778,  1784,  1784,  1785,  1789,  1793,  1797,
    1801,  1805,  1809,  1813,  1817,  1821,  1827,  1841,  1850,  1864,
    1863,  1878,  1878,  1879,  1879,  1879,  1879,  1881,  1887,  1893,
    1903,  1905,  1905,  1906,  1906,  1908,  1924,  1923,  1948,  1948,
    1949,  1949,  1949,  1949,  1951,  1957,  1977,  1976,  1982,  1982,
    1983,  1987,  1991,  1995,  1999,  2003,  2007,  2011,  2015,  2019,
    2029,  2028,  2049,  2049,  2050,  2050,  2050,  2052,  2059,  2058,
    2064,  2064,  2065,  2069,  2073,  2077,  2081,  2085,  2089,  2093,
    2097,  2101,  2111,  2110,  2182,  2182,  2183,  2184,  2185,  2186,
    2187,  2188,  2189,  2190,  2191,  2192,  2193,  2194,  2195,  2196,
    2197,  2199,  2205,  2211,  2217,  2230,  2243,  2249,  2255,  2259,
    2268,  2267,  2272,  2272,  2273,  2277,  2283,  2294,  2300,  2306,
    2312,  2328,  2327,  2353,  2353,  2354,  2354,  2354,  2356,  2376,
    2386,  2385,  2412,  2412,  2413,  2413,  2413,  2415,  2421,  2430,
    2432,  2432,  2433,  2433,  2435,  2453,  2452,  2475,  2475,  2476,
    2476,  2476,  2478,  2484,  2493,  2496,  2496,  2497,  2498,  2499,
    2500,  2501,  2502,  2503,  2504,  2505,  2506,  2507,  2508,  2509,
    2510,  2511,  2512,  2513,  2514,  2515,  2516,  2517,  2518,  2519,
    2520,  2521,  2522,  2523,  2524,  2525,  2526,  2527,  2528,  2529,
    2530,  2531,  2532,  2533,  2534,  2535,  2536,  2537,  2538,  2539,
    2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,  2550,  2555,
    2561,  2567,  2573,  2579,  2584,  2589,  2594,  2599,  2604,  2609,
    2614,  2619,  2624,  2629,  2634,  2639,  2644,  2650,  2661,  2666,
    2671,  2676,  2681,  2686,  2691,  2694,  2699,  2702,  2707,  2712,
    2717,  2722,  2727,  2732,  2737,  2742,  2747,  2752,  2757,  2762,
    2771,  2780,  2785,  2790,  2795,  2801,  2800,  2805,  2805,  2806,
    2809,  2812,  2815,  2818,  2821,  2824,  2827,  2830,  2833,  2836,
    2839,  2842,  2845,  2848,  2851,  2854,  2857,  2860,  2863,  2866,
    2869,  2875,  2874,  2879,  2879,  2880,  2883,  2886,  2889,  2892,
    2895,  2898,  2901,  2904,  2907,  2910,  2913,  2916,  2919,  2922,
    2925,  2928,  2931,  2934,  2937,  2942,  2947,  2952,  2961,  2964,
    2964,  2965,  2966,  2967,  2968,  2969,  2970,  2971,  2972,  2973,
    2974,  2975,  2976,  2977,  2978,  2979,  2981,  2986,  2991,  2996,
    3001,  3006,  3011,  3016,  3021,  3026,  3031,  3036,  3041,  3046,
    3054,  3057,  3057,  3058,  3059,  3060,  3061,  3062,  3063,  3064,
    3065,  3066,  3068,  3074,  3080,  3086,  3092,  3101,  3116,  3122
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
  "SSL_MESSAGE_DIGEST_ALGORITHM", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY",
  "STATS_U_OPER_ONLY", "T_ALL", "T_BOTS", "T_CALLERID", "T_CCONN",
  "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS", "T_INVISIBLE", "T_IPV4",
  "T_IPV6", "T_LOCOPS", "T_LOG", "T_MAX_CLIENTS", "T_NCHANGE",
  "T_NONONREG", "T_RECVQ", "T_REJ", "T_RESTART", "T_SERVER", "T_SERVICE",
  "T_SERVICES_NAME", "T_SERVNOTICE", "T_SET", "T_SHARED", "T_SIZE",
  "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL", "T_SSL_CIPHER_LIST",
  "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD", "T_SSLV3", "T_TLSV1",
  "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV",
  "T_UNXLINE", "T_WALLOP", "T_WALLOPS", "T_WEBIRC", "TBOOL",
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
  "serverinfo_ssl_cipher_list", "serverinfo_ssl_message_digest_algorithm",
  "serverinfo_ssl_dh_elliptic_curve", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_max_nick_length",
  "serverinfo_max_topic_length", "serverinfo_hub", "admin_entry",
  "admin_items", "admin_item", "admin_name", "admin_email",
  "admin_description", "motd_entry", "$@1", "motd_items", "motd_item",
  "motd_mask", "motd_file", "logging_entry", "logging_items",
  "logging_item", "logging_use_logging", "logging_file_entry", "$@2",
  "logging_file_items", "logging_file_item", "logging_file_name",
  "logging_file_size", "logging_file_type", "$@3",
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
     485,   486,   487,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -789

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-789)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -789,   656,  -789,   -59,  -226,  -220,  -789,  -789,  -789,  -217,
    -789,  -198,  -789,  -789,  -789,  -195,  -789,  -789,  -789,  -192,
    -189,  -789,  -181,  -171,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,   307,
     925,  -169,  -160,  -158,    22,  -155,   387,  -136,  -121,  -119,
      50,  -116,  -114,   -97,   761,   433,   -84,    34,     2,   -82,
     -73,   -47,   -34,   -27,     9,  -789,  -789,  -789,  -789,  -789,
     -22,    -7,    -1,    44,    68,    79,    82,    84,    88,    92,
      98,   102,   104,   112,   266,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
     681,   563,    19,  -789,   115,    21,  -789,  -789,    26,  -789,
     119,   129,   131,   141,   143,   145,   147,   148,   150,   154,
     155,   156,   159,   160,   164,   167,   175,   176,   177,   179,
     180,   183,   184,   186,   188,   189,   190,  -789,   194,  -789,
     207,   209,   210,   211,   215,   216,   217,   218,   220,   221,
     224,   225,   226,   227,   228,   230,   231,   232,   234,   235,
      61,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,   343,    69,   301,   -70,   236,   239,    16,  -789,
    -789,  -789,   125,   388,   275,  -789,   241,   243,   251,   252,
     253,   255,   257,   259,   308,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,   -29,   260,   263,   269,   273,   285,
     286,   288,   293,   294,   295,   296,   297,   300,   304,   305,
     310,   317,   319,   320,   168,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,    25,    53,   321,    10,  -789,
    -789,  -789,    89,  -789,   322,    97,  -789,  -789,    93,  -789,
     258,   398,   432,    73,  -789,   249,   270,   345,   449,   450,
     451,   450,   457,   450,   450,   460,   461,   359,   361,   344,
    -789,   348,   342,   349,   350,  -789,   352,   353,   362,   364,
     365,   366,   370,   375,   376,   378,   383,   384,   386,   146,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,   377,   389,
     391,   393,   395,   396,   397,  -789,   401,   403,   404,   407,
     412,   414,   415,    11,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
     417,   418,     7,  -789,  -789,  -789,   468,   413,  -789,  -789,
     419,   422,    38,  -789,  -789,  -789,   382,   450,   450,   409,
     547,   446,   552,   539,   453,   450,   454,   559,   566,   450,
     567,   466,   469,   470,   450,   574,   575,   450,   578,   580,
     586,   587,   486,   439,   488,   472,   489,   450,   450,   491,
     495,   497,  -190,  -183,   498,   499,   500,   589,   605,   450,
     505,   506,   450,   450,   508,   509,   492,  -789,   496,   502,
     507,  -789,   510,   511,   514,   515,   516,    57,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,   517,   518,
      41,  -789,  -789,  -789,   501,   523,   524,  -789,   525,  -789,
      18,  -789,  -789,  -789,  -789,  -789,   601,   603,   512,  -789,
     530,   534,   535,    29,  -789,  -789,  -789,   542,   536,   540,
    -789,   544,   549,   553,   557,   560,  -789,   561,    62,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
     545,   564,   571,   573,    12,  -789,  -789,  -789,  -789,   520,
     526,   529,   604,   584,   588,   597,   450,   555,  -789,  -789,
     606,   599,   675,   620,   706,   692,   693,   695,   696,   697,
     698,   700,   702,   718,   704,   142,   149,   705,   707,   600,
    -789,   602,   607,  -789,    30,  -789,  -789,  -789,  -789,   621,
     608,  -789,   609,   710,   612,  -789,   613,   614,  -789,   616,
      23,  -789,  -789,  -789,  -789,   615,   625,   628,  -789,   631,
     633,   636,   638,   374,   639,   642,   644,   645,   646,   647,
     649,   651,   655,   657,  -789,  -789,   726,   737,   450,   617,
     742,   777,   779,   450,   780,   781,   450,   715,   782,   784,
     450,   791,   791,   673,  -789,  -789,   783,   192,   786,   709,
     790,   792,   672,   793,   795,   799,   798,   807,   813,   817,
     712,  -789,   824,   827,   722,  -789,   727,  -789,   837,   838,
     733,  -789,   734,   735,   736,   739,   741,   744,   745,   746,
     749,   750,   751,   752,   753,   754,   757,   758,   759,   760,
     763,   765,   766,   770,   771,   772,   773,   774,   778,   764,
     785,   688,   787,   788,   789,   794,   796,   797,   802,   803,
     804,   805,   806,   808,   809,   810,   811,   812,   814,   815,
     816,   818,   819,   820,  -789,  -789,   843,   800,   776,   848,
     869,   870,   883,   886,   821,  -789,   887,   889,   822,  -789,
    -789,   890,   892,   823,   911,   825,  -789,   828,   829,  -789,
    -789,   897,   898,   830,  -789,  -789,   899,   831,   832,   901,
     904,   905,   913,   835,   833,   929,   834,  -789,  -789,   930,
     933,   937,   839,  -789,   840,   841,   842,   844,   845,   846,
     847,   849,  -789,   850,   851,   852,   853,   854,   855,   856,
     857,   858,   859,   860,   861,   862,   863,   864,  -789,  -789,
    -188,  -789,  -789,  -789,  -185,  -789,   865,   866,  -789,  -789,
     938,   867,   868,  -789,   871,  -789,   182,   872,  -789,  -789,
     939,   873,   943,   874,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,   450,   450,   450,   450,   450,   450,   450,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,   875,   877,   878,   -32,   879,   880,   881,   882,   884,
     885,   888,   891,   893,   894,   895,   289,   896,   900,  -789,
     902,   903,   906,   907,   908,   909,   910,    -3,   912,   914,
     915,   916,   917,   918,   919,  -789,   920,   921,  -789,  -789,
     922,   923,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -180,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -178,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,   924,
     926,   541,   927,   928,   931,   932,   934,  -789,   935,   936,
    -789,   940,   941,     1,   947,   942,  -789,  -789,  -789,  -789,
     944,   945,  -789,   948,   949,   494,   950,   951,   952,   953,
     954,   730,   955,  -789,   956,   957,   958,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,   142,  -789,   149,  -789,  -789,   959,   576,  -789,
    -789,   960,   961,   962,  -789,    32,  -789,  -789,  -789,  -789,
    -789,   963,   748,   966,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -177,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
     791,   791,   791,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -172,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
     764,  -789,   688,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,   -65,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,   -43,
    -789,   964,   911,   967,  -789,  -789,  -789,  -789,  -789,   965,
    -789,  -789,   968,  -789,  -789,  -789,  -789,   969,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,   -41,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,   -30,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,   -18,  -789,  -789,   973,
     -74,   972,   971,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,   -17,  -789,  -789,  -789,   -32,
    -789,  -789,  -789,  -789,    -3,  -789,  -789,  -789,   541,  -789,
       1,  -789,  -789,  -789,   983,   986,   987,  -789,   494,  -789,
     730,  -789,   576,   976,   977,   978,   410,  -789,  -789,   748,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,    70,  -789,  -789,  -789,   410,  -789
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   227,   392,   440,     0,
     455,     0,   295,   431,   271,     0,   111,   151,   329,     0,
       0,   370,     0,     0,   346,     3,    23,    11,     4,    24,
       5,     6,     8,     9,    10,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    21,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   106,   105,   635,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   620,   634,   622,   623,   624,
     625,   626,   627,   621,   628,   629,   630,   631,   632,   633,
       0,     0,     0,   453,     0,     0,   451,   452,     0,   517,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   591,     0,   565,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   466,   514,   516,   508,   509,   510,   511,   512,   507,
     477,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   504,   478,   479,   513,   481,   486,   487,   482,   484,
     483,   497,   498,   485,   488,   489,   490,   491,   480,   493,
     494,   495,   515,   505,   506,   502,   503,   496,   492,   500,
     501,   499,     0,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,     0,   661,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   652,   653,   654,   655,   656,
     659,   657,   658,   660,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    69,    70,    68,    65,
      63,    71,    72,    64,    54,    67,    57,    58,    59,    55,
      66,    60,    61,    62,    56,     0,     0,     0,     0,   122,
     123,   124,     0,   344,     0,     0,   342,   343,     0,   107,
       0,     0,     0,     0,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     619,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,   231,   234,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   232,   233,   235,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,   395,   396,   397,   398,   399,   400,
     401,   403,   402,   405,   409,   406,   407,   408,   404,   446,
       0,     0,     0,   443,   444,   445,     0,     0,   450,   461,
       0,     0,     0,   458,   459,   460,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   465,     0,     0,
       0,   312,     0,     0,     0,     0,     0,     0,   298,   299,
     300,   301,   306,   302,   303,   304,   305,   437,     0,     0,
       0,   434,   435,   436,     0,     0,     0,   273,     0,   283,
       0,   281,   282,   284,   285,    48,     0,     0,     0,    44,
       0,     0,     0,     0,   114,   115,   116,     0,     0,     0,
     200,     0,     0,     0,     0,     0,   174,     0,     0,   154,
     155,   156,   157,   160,   161,   162,   163,   159,   158,   164,
       0,     0,     0,     0,     0,   332,   333,   334,   335,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   651,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,     0,   378,     0,   373,   374,   375,   125,     0,
       0,   121,     0,     0,     0,   341,     0,     0,   356,     0,
       0,   349,   350,   351,   352,     0,     0,     0,   101,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   618,   248,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   229,   410,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   394,     0,     0,     0,   442,     0,   449,     0,     0,
       0,   457,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   464,   307,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,     0,   433,
     286,     0,     0,     0,     0,     0,   280,     0,     0,    43,
     117,     0,     0,     0,   113,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   336,     0,
       0,     0,     0,   331,     0,     0,     0,     0,     0,     0,
       0,     0,   650,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
       0,    77,    82,    83,     0,    81,     0,     0,    51,   376,
       0,     0,     0,   372,     0,   120,     0,     0,   340,   353,
       0,     0,     0,     0,   348,   110,   109,   108,   645,   644,
     636,   637,    27,    27,    27,    27,    27,    27,    27,    29,
      28,   638,   648,   649,   639,   640,   641,   643,   642,   646,
     647,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,   228,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   393,     0,     0,   441,   454,
       0,     0,   456,   530,   534,   549,   519,   617,   562,   556,
     559,   529,   521,   520,   523,   524,   522,   537,   527,   528,
     538,   526,   533,   532,   531,   557,   518,   615,   616,   553,
     601,   595,   611,   596,   597,   598,   606,   614,   599,   608,
     612,   602,   613,   603,   607,   600,   610,   605,   604,   609,
       0,   594,   555,   574,   575,   576,   569,   587,   570,   571,
     572,   582,   590,   573,   584,   588,   578,   589,   579,   583,
     577,   586,   581,   580,   585,     0,   568,   550,   548,   551,
     561,   552,   540,   546,   547,   544,   545,   541,   542,   543,
     560,   563,   564,   525,   554,   536,   535,   558,   539,     0,
       0,     0,     0,     0,     0,     0,     0,   296,     0,     0,
     432,     0,     0,     0,   291,   287,   290,   272,    49,    50,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   152,     0,     0,     0,   330,   663,   662,
     668,   666,   669,   664,   665,   667,    92,   100,    91,    98,
      99,    90,    94,    93,    85,    84,    89,    86,    88,    97,
      87,    74,     0,    75,     0,    95,    96,     0,     0,   371,
     126,     0,     0,     0,   138,     0,   130,   131,   133,   132,
     345,     0,     0,     0,   347,    30,    31,    32,    33,    34,
      35,    36,   260,   261,   252,   270,   269,     0,   268,   253,
     255,   257,   264,   256,   254,   263,   249,   262,   251,   250,
      37,    37,    37,    39,    38,   258,   259,   415,   418,   419,
     429,   426,   412,   427,   424,   425,     0,   423,   428,   411,
     417,   414,   416,   430,   413,   447,   448,   462,   463,   592,
       0,   566,     0,   310,   311,   320,   317,   322,   318,   319,
     325,   321,   323,   316,   324,     0,   315,   309,   328,   327,
     326,   308,   439,   438,   294,   293,   278,   279,   277,     0,
     276,     0,     0,     0,   118,   119,   173,   169,   220,   207,
     217,   216,   205,   210,   226,   219,   224,   209,   212,   221,
     223,   218,   225,   213,   215,   222,   211,   214,     0,   203,
     166,   168,   170,   171,   172,   183,   184,   185,   178,   196,
     179,   180,   181,   191,   199,   182,   193,   197,   187,   198,
     188,   192,   186,   195,   190,   189,   194,     0,   177,   167,
     339,   337,   338,    76,    80,   377,   382,   388,   391,   384,
     390,   385,   389,   387,   383,   386,     0,   381,   134,     0,
       0,     0,     0,   129,   354,   360,   366,   369,   362,   368,
     363,   367,   365,   361,   364,     0,   359,   355,   266,     0,
      40,    41,    42,   421,     0,   593,   567,   313,     0,   274,
       0,   292,   289,   288,     0,     0,     0,   201,     0,   175,
       0,   379,     0,     0,     0,     0,     0,   128,   357,     0,
     267,   422,   314,   275,   206,   204,   208,   202,   176,   380,
     135,   137,   136,   144,   149,   148,   143,   146,   150,   147,
     142,   145,     0,   141,   358,   139,     0,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -789,  -789,  -789,  -396,  -317,  -788,  -641,  -789,  -789,   974,
    -789,  -789,  -789,  -789,   946,  -789,  -789,  -789,    54,  -789,
      17,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    1007,  -789,  -789,  -789,  -789,  -789,  -789,   610,  -789,  -789,
    -789,  -789,   836,  -789,  -789,  -789,  -789,    37,  -789,  -789,
    -789,  -789,  -789,  -194,  -789,  -789,  -789,   618,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -150,
    -789,  -789,  -789,  -153,  -789,  -789,  -789,   826,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -128,  -789,  -789,
    -789,  -789,  -789,  -138,  -789,   637,  -789,  -789,  -789,   -24,
    -789,  -789,  -789,  -789,  -789,   667,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -110,  -789,  -789,  -789,  -789,  -789,  -789,
     619,  -789,  -789,  -789,  -789,  -789,   970,  -789,  -789,  -789,
    -789,   562,  -789,  -789,  -789,  -789,  -789,  -123,  -789,  -789,
    -789,   592,  -789,  -789,  -789,  -789,  -111,  -789,  -789,  -789,
     876,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,   -92,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,   690,  -789,  -789,  -789,  -789,  -789,   975,  -789,  -789,
    -789,  -789,  1079,  -789,  -789,  -789,  -789,   801,  -789,  -789,
    -789,  -789,  1025,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,    80,  -789,  -789,  -789,    71,  -789,  -789,  -789,  -789,
    -789,  1111,  -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789,  -789,   979,  -789,
    -789,  -789,  -789,  -789,  -789,  -789,  -789
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   839,   840,  1103,  1104,    26,   228,   229,
     230,   231,    27,   274,   275,   276,   277,   800,   801,   804,
     805,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,    28,    74,
      75,    76,    77,    78,    29,    61,   513,   514,   515,   516,
      30,   298,   299,   300,   301,   302,  1065,  1066,  1067,  1068,
    1069,  1241,  1312,  1313,    31,    62,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   764,  1217,  1218,
     539,   758,  1188,  1189,    32,    51,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   629,  1087,  1088,    33,    59,
     499,   743,  1159,  1160,   500,   501,   502,  1163,  1005,  1006,
     503,   504,    34,    57,   477,   478,   479,   480,   481,   482,
     483,   728,  1145,  1146,   484,   485,   486,    35,    63,   544,
     545,   546,   547,   548,    36,   305,   306,   307,    37,    69,
     600,   601,   602,   603,   604,   821,  1255,  1256,    38,    66,
     584,   585,   586,   587,   811,  1236,  1237,    39,    52,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     652,  1116,  1117,   394,   395,   396,   397,   398,    40,    58,
     490,   491,   492,   493,    41,    53,   402,   403,   404,   405,
      42,   115,   116,   117,    43,    55,   412,   413,   414,   415,
      44,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   445,
     965,   966,   218,   443,   940,   941,   219,   220,   221,    45,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,    46,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     867,   868,   614,   303,   616,  1114,   618,   619,   399,    49,
      70,   296,   368,   540,   369,    50,   370,   225,    54,   494,
     399,  1085,   113,   113,   596,   708,   581,   409,   371,   709,
     510,   581,   710,  1061,    71,   296,   711,    56,   866,   409,
      60,    72,   487,    64,   372,  1051,    65,   541,  1053,  1052,
    1156,   225,  1054,  1129,    67,  1131,  1258,  1130,   468,  1132,
    1259,  1263,   119,   517,    68,  1264,   110,   120,   121,   373,
     487,   374,   400,   122,   469,   111,   495,   112,   375,   518,
     118,   123,   124,   496,   400,   497,   114,   114,   125,   376,
     470,   126,   127,   542,   596,   519,  1086,   128,   303,   222,
     673,   674,   129,   130,   304,   131,   132,   133,   681,   134,
     511,    73,   685,   377,   223,   226,   224,   690,   135,   232,
     693,   233,   136,   137,   471,   597,   510,   582,   410,   520,
     703,   704,   582,   138,  1062,  1284,   401,   378,   234,   227,
     410,   543,   717,   139,   498,   720,   721,   331,   401,   226,
     140,   295,   141,   308,   142,   411,   143,   379,   144,   145,
     309,   332,   333,   505,   521,   334,   380,   411,  1267,   254,
     488,   146,  1268,   227,    47,    48,   147,   148,   149,   472,
     150,   151,   152,  1061,   522,   153,  -127,   473,   474,   310,
    1269,  1157,  1277,   255,  1270,   597,  1278,  1115,   488,   304,
     523,  1158,   311,  1279,   559,   512,   511,  1280,   475,   312,
    -127,   154,   381,   335,   315,  1281,  1288,   524,   525,  1282,
    1289,   155,   156,   157,   158,   159,   160,   256,  1063,   316,
     336,   337,   338,   339,   340,   317,   257,   297,   341,   781,
     382,   664,   342,   313,   590,   660,   772,   598,   343,   583,
     508,   599,   745,   161,   583,   407,  1064,   823,   258,   344,
     345,   297,   259,   753,   812,   592,  1242,    79,   526,   489,
     260,   346,   670,   261,   262,   738,   540,   162,   163,   164,
     318,   165,   166,   167,  1062,   476,   588,   168,    80,    81,
     527,   734,   169,   347,    82,   466,   766,   489,  1100,  1101,
    1102,   512,   494,  1315,   319,   263,   608,  1316,    70,   235,
     541,   853,  1260,  1261,  1262,   320,   858,   598,   321,   861,
     322,   599,   264,   865,   323,   265,   266,   267,   324,    83,
      84,   594,    71,   348,   325,    85,    86,   236,   326,    72,
     327,    87,    88,    89,   468,   237,   798,   799,   328,    90,
      91,   406,   268,   802,   803,   416,   542,   238,   239,   495,
     469,   609,   240,   241,   242,   417,   496,   418,   497,   269,
     270,   271,   871,   872,    92,    93,   470,   419,  1063,   420,
     643,   421,   610,   422,   423,   605,   424,   243,   119,   517,
     425,   426,   427,   120,   121,   428,   429,   272,   273,   122,
     430,   866,   579,   431,   543,   518,  1064,   123,   124,    73,
     471,   432,   433,   434,   125,   435,   436,   126,   127,   437,
     438,   519,   439,   128,   440,   441,   442,   498,   129,   130,
     444,   131,   132,   133,   254,   134,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,   446,   135,   447,   448,   449,   136,   137,
    1303,   450,   451,   452,   453,   520,   454,   455,   255,   138,
     456,   457,   458,   459,   460,   472,   461,   462,   463,   139,
     464,   465,   506,   473,   474,   507,   140,   549,   141,   550,
     142,  1304,   143,  1305,   144,   145,   613,   551,   552,   553,
     521,   554,   256,   555,   475,   556,   560,   146,  1168,   561,
     329,   257,   147,   148,   149,   562,   150,   151,   152,   563,
     522,   153,  1169,   832,   833,   834,   835,   836,   837,   838,
    1170,   564,   565,   258,   566,   606,   523,   259,  1306,   567,
     568,   569,   570,   571,  1171,   260,   572,   154,   261,   262,
     573,   574,   557,   524,   525,  1307,   575,   155,   156,   157,
     158,   159,   160,   576,  1135,   577,   578,   589,   593,   607,
     611,   612,   613,   615,   368,  1172,   369,  1173,   370,   617,
     263,   476,   620,   621,   622,  1136,   623,   624,   626,   161,
     371,   625,  1308,  1309,  1137,   627,   628,   264,   630,   631,
     265,   266,   267,  1174,   526,   666,   372,   672,   632,  1285,
     633,   634,   635,   162,   163,   164,   636,   165,   166,   167,
     645,   637,   638,   168,   639,  1138,   527,   268,   169,   640,
     641,   373,   642,   374,   675,   646,  1175,   647,  1176,   648,
     375,   649,   650,   651,   269,   270,   271,   653,  1310,   654,
     655,   376,  1311,   656,  1139,  1140,   667,  1177,   657,  1226,
     658,   659,  1141,   662,   663,   668,     2,     3,   669,   676,
       4,   677,   272,   273,   678,   377,   679,  1178,   680,   682,
       5,   683,  1179,     6,     7,   699,  1180,  1142,   684,   686,
       8,   687,   331,  1181,   688,   689,   691,   692,  1182,   378,
     694,     9,   695,  1143,    10,    11,   332,   333,   696,   697,
     334,   698,  1183,   700,   702,  1184,   705,  1185,   701,   379,
     706,  1227,   707,   712,   713,   714,   715,   716,   380,  1186,
     718,   719,    12,   722,   723,   724,  1187,    13,   747,   725,
     748,   777,   786,   783,   740,   774,    14,   943,   726,   944,
     945,   775,  1228,   727,   776,   749,   729,   730,   335,  1229,
     731,   732,   733,   736,   737,  1144,    15,    16,  1230,   741,
     742,   744,   235,   750,   381,   336,   337,   338,   339,   340,
     751,   752,   756,   341,    17,   755,   757,   342,   768,  1195,
     759,  1196,  1197,   343,  1231,   760,  1232,  1233,   782,   761,
     236,    18,   382,   762,   344,   345,   763,   765,   237,   778,
     769,  1234,   785,   779,    19,    20,   346,   770,  1235,   771,
     238,   239,   780,   920,   784,   240,   241,   242,   787,   788,
     789,  1245,   790,   791,   792,   793,    21,   794,   347,   795,
     796,   797,   806,   808,   807,   809,   814,   817,   851,    22,
     243,   815,   862,   810,   816,   818,   819,    23,   825,   852,
     820,    24,   822,   854,   855,   946,   947,   948,   826,   949,
     950,   827,   951,   952,   828,   953,   829,   954,   348,   830,
     955,   831,   841,   956,   957,   842,   958,   843,   844,   845,
     846,   959,   847,  1246,   848,   960,   961,   962,   849,   856,
     850,   857,   859,   860,   863,   963,   864,  1198,  1199,  1200,
     964,  1201,  1202,   866,  1203,  1204,   869,  1205,   877,  1206,
     870,   880,  1207,   873,  1247,  1208,  1209,   875,  1210,   876,
     878,  1248,   879,  1211,   874,   881,    79,  1212,  1213,  1214,
    1249,   921,   922,   923,   882,   924,   925,  1215,   926,   927,
     883,   928,  1216,   929,   884,   885,   930,    80,    81,   931,
     932,   886,   933,    82,   887,   888,  1250,   934,  1251,  1252,
     889,   935,   936,   937,   890,   891,   892,   893,   894,   895,
     989,   938,   896,  1253,   897,   992,   939,   898,   899,   900,
    1254,   993,   901,   902,   903,   904,   905,   906,    83,    84,
     907,   908,   909,   910,    85,    86,   911,   994,   912,   913,
      87,    88,    89,   914,   915,   916,   917,   918,    90,    91,
     995,   919,   991,   996,   998,   990,   999,  1001,   942,  1002,
     967,   968,   969,  1004,  1010,  1011,  1013,   970,  1016,   971,
     972,  1017,  1018,    92,    93,   973,   974,   975,   976,   977,
    1019,   978,   979,   980,   981,   982,  1014,   983,   984,   985,
    1020,   986,   987,   988,   997,  1000,  1022,  1024,  1007,  1003,
    1025,  1008,  1009,  1012,  1026,  1057,  1071,  1023,  1015,  1021,
    1073,  1224,  1027,  1028,  1029,  1030,  1271,  1031,  1032,  1033,
    1034,   314,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,
    1043,  1044,  1045,  1046,  1047,  1048,  1049,  1050,  1055,  1056,
    1283,  1059,  1243,  1058,  1060,  1070,  1223,  1074,  1082,  1072,
    1083,  1084,  1089,  1090,  1091,  1092,  1294,  1093,  1094,  1295,
    1296,  1095,  1317,   754,  1096,  1297,  1097,  1098,  1099,  1105,
    1298,  1290,  1293,  1106,   591,  1107,  1108,   746,  1272,  1109,
    1110,  1111,  1112,  1113,   735,  1118,   767,  1119,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,  1127,  1128,  1133,  1292,  1134,
    1147,  1148,   824,   773,  1149,  1150,  1314,  1151,  1152,  1153,
    1161,  1299,  1291,  1154,  1155,   644,   813,  1164,  1165,  1162,
     739,  1166,  1167,  1190,  1191,  1192,  1193,  1194,  1219,  1220,
    1221,  1222,  1225,  1238,   408,   467,  1244,  1239,  1240,  1257,
    1273,  1265,   509,  1274,  1287,   330,  1275,  1276,  1286,  1300,
    1301,  1302,  1266,   671,     0,     0,     0,     0,     0,     0,
     580,     0,     0,   558,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   661,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   665
};

static const yytype_int16 yycheck[] =
{
     641,   642,   319,     1,   321,     8,   323,   324,     1,   235,
       1,     1,     1,     1,     3,   235,     5,     1,   235,     1,
       1,    53,     1,     1,     1,   215,     1,     1,    17,   219,
       1,     1,   215,     1,    25,     1,   219,   235,   112,     1,
     235,    32,     1,   235,    33,   233,   235,    35,   233,   237,
      49,     1,   237,   233,   235,   233,   233,   237,     1,   237,
     237,   233,     1,     1,   235,   237,   235,     6,     7,    58,
       1,    60,    65,    12,    17,   235,    58,   235,    67,    17,
     235,    20,    21,    65,    65,    67,    65,    65,    27,    78,
      33,    30,    31,    81,     1,    33,   128,    36,     1,   235,
     417,   418,    41,    42,   102,    44,    45,    46,   425,    48,
      81,   102,   429,   102,   235,    99,   235,   434,    57,   235,
     437,   235,    61,    62,    67,   102,     1,   102,   102,    67,
     447,   448,   102,    72,   102,   209,   129,   126,   235,   123,
     102,   129,   459,    82,   126,   462,   463,     1,   129,    99,
      89,   235,    91,   235,    93,   129,    95,   146,    97,    98,
     233,    15,    16,   233,   102,    19,   155,   129,   233,     1,
     129,   110,   237,   123,   233,   234,   115,   116,   117,   122,
     119,   120,   121,     1,   122,   124,   176,   130,   131,   236,
     233,   190,   233,    25,   237,   102,   237,   200,   129,   102,
     138,   200,   236,   233,   233,   176,    81,   237,   151,   236,
     176,   150,   201,    67,   236,   233,   233,   155,   156,   237,
     237,   160,   161,   162,   163,   164,   165,    59,   196,   236,
      84,    85,    86,    87,    88,   236,    68,   227,    92,   556,
     229,   234,    96,   234,   234,   234,   234,   224,   102,   224,
     234,   228,   234,   192,   224,   234,   224,   234,    90,   113,
     114,   227,    94,   234,   234,   176,   234,     1,   206,   228,
     102,   125,   234,   105,   106,   234,     1,   216,   217,   218,
     236,   220,   221,   222,   102,   228,   233,   226,    22,    23,
     228,   234,   231,   147,    28,   234,   234,   228,     9,    10,
      11,   176,     1,   233,   236,   137,   233,   237,     1,     1,
      35,   628,  1100,  1101,  1102,   236,   633,   224,   236,   636,
     236,   228,   154,   640,   236,   157,   158,   159,   236,    63,
      64,   234,    25,   187,   236,    69,    70,    29,   236,    32,
     236,    75,    76,    77,     1,    37,   204,   205,   236,    83,
      84,   236,   184,   204,   205,   236,    81,    49,    50,    58,
      17,   112,    54,    55,    56,   236,    65,   236,    67,   201,
     202,   203,   180,   181,   108,   109,    33,   236,   196,   236,
     234,   236,   112,   236,   236,   127,   236,    79,     1,     1,
     236,   236,   236,     6,     7,   236,   236,   229,   230,    12,
     236,   112,   234,   236,   129,    17,   224,    20,    21,   102,
      67,   236,   236,   236,    27,   236,   236,    30,    31,   236,
     236,    33,   236,    36,   236,   236,   236,   126,    41,    42,
     236,    44,    45,    46,     1,    48,   832,   833,   834,   835,
     836,   837,   838,   236,    57,   236,   236,   236,    61,    62,
      40,   236,   236,   236,   236,    67,   236,   236,    25,    72,
     236,   236,   236,   236,   236,   122,   236,   236,   236,    82,
     236,   236,   236,   130,   131,   236,    89,   236,    91,   236,
      93,    71,    95,    73,    97,    98,   112,   236,   236,   236,
     102,   236,    59,   236,   151,   236,   236,   110,     4,   236,
     234,    68,   115,   116,   117,   236,   119,   120,   121,   236,
     122,   124,    18,   139,   140,   141,   142,   143,   144,   145,
      26,   236,   236,    90,   236,   127,   138,    94,   118,   236,
     236,   236,   236,   236,    40,   102,   236,   150,   105,   106,
     236,   236,   234,   155,   156,   135,   236,   160,   161,   162,
     163,   164,   165,   236,    13,   236,   236,   236,   236,   127,
     215,   112,   112,   112,     1,    71,     3,    73,     5,   112,
     137,   228,   112,   112,   215,    34,   215,   233,   236,   192,
      17,   233,   172,   173,    43,   236,   236,   154,   236,   236,
     157,   158,   159,    99,   206,   127,    33,   215,   236,  1240,
     236,   236,   236,   216,   217,   218,   236,   220,   221,   222,
     233,   236,   236,   226,   236,    74,   228,   184,   231,   236,
     236,    58,   236,    60,   215,   236,   132,   236,   134,   236,
      67,   236,   236,   236,   201,   202,   203,   236,   228,   236,
     236,    78,   232,   236,   103,   104,   233,   153,   236,    73,
     236,   236,   111,   236,   236,   236,     0,     1,   236,   112,
       4,   215,   229,   230,   112,   102,   127,   173,   215,   215,
      14,   112,   178,    17,    18,   236,   182,   136,   112,   112,
      24,   215,     1,   189,   215,   215,   112,   112,   194,   126,
     112,    35,   112,   152,    38,    39,    15,    16,   112,   112,
      19,   215,   208,   215,   215,   211,   215,   213,   236,   146,
     215,   135,   215,   215,   215,   215,   127,   112,   155,   225,
     215,   215,    66,   215,   215,   233,   232,    71,   127,   233,
     127,   127,   112,   127,   233,   215,    80,    49,   236,    51,
      52,   215,   166,   236,   215,   233,   236,   236,    67,   173,
     236,   236,   236,   236,   236,   214,   100,   101,   182,   236,
     236,   236,     1,   233,   201,    84,    85,    86,    87,    88,
     236,   236,   236,    92,   118,   233,   236,    96,   233,    49,
     236,    51,    52,   102,   208,   236,   210,   211,   233,   236,
      29,   135,   229,   236,   113,   114,   236,   236,    37,   215,
     236,   225,   127,   215,   148,   149,   125,   236,   232,   236,
      49,    50,   215,    49,   215,    54,    55,    56,   112,   127,
     127,    73,   127,   127,   127,   127,   170,   127,   147,   127,
     112,   127,   127,   233,   127,   233,   215,   127,   112,   183,
      79,   233,   127,   236,   235,   233,   233,   191,   233,   112,
     236,   195,   236,   236,   112,   167,   168,   169,   233,   171,
     172,   233,   174,   175,   233,   177,   233,   179,   187,   233,
     182,   233,   233,   185,   186,   233,   188,   233,   233,   233,
     233,   193,   233,   135,   233,   197,   198,   199,   233,   112,
     233,   112,   112,   112,   112,   207,   112,   167,   168,   169,
     212,   171,   172,   112,   174,   175,   233,   177,   236,   179,
     127,   112,   182,   127,   166,   185,   186,   127,   188,   127,
     127,   173,   127,   193,   215,   127,     1,   197,   198,   199,
     182,   167,   168,   169,   127,   171,   172,   207,   174,   175,
     127,   177,   212,   179,   127,   233,   182,    22,    23,   185,
     186,   127,   188,    28,   127,   233,   208,   193,   210,   211,
     233,   197,   198,   199,   127,   127,   233,   233,   233,   233,
     127,   207,   233,   225,   233,   127,   212,   233,   233,   233,
     232,   112,   233,   233,   233,   233,   233,   233,    63,    64,
     233,   233,   233,   233,    69,    70,   233,   127,   233,   233,
      75,    76,    77,   233,   233,   233,   233,   233,    83,    84,
     127,   233,   236,   127,   127,   215,   127,   127,   233,   127,
     233,   233,   233,   112,   127,   127,   127,   233,   127,   233,
     233,   127,   127,   108,   109,   233,   233,   233,   233,   233,
     127,   233,   233,   233,   233,   233,   215,   233,   233,   233,
     215,   233,   233,   233,   233,   233,   127,   127,   233,   236,
     127,   233,   233,   233,   127,   127,   127,   233,   236,   236,
     127,  1054,   233,   233,   233,   233,   112,   233,   233,   233,
     233,    74,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     127,   233,  1065,   236,   233,   233,  1052,   233,   233,   236,
     233,   233,   233,   233,   233,   233,   133,   233,   233,   133,
     133,   233,  1316,   513,   233,  1278,   233,   233,   233,   233,
    1280,  1259,  1270,   233,   298,   233,   233,   500,  1162,   233,
     233,   233,   233,   233,   477,   233,   528,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,  1268,   233,
     233,   233,   600,   544,   233,   233,  1289,   233,   233,   233,
     223,  1282,  1264,   233,   233,   349,   584,   233,   233,   237,
     490,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   115,   170,   233,   236,   236,   233,
     233,  1130,   228,   238,   233,    94,   238,   238,   236,   233,
     233,   233,  1132,   412,    -1,    -1,    -1,    -1,    -1,    -1,
     274,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   402
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   240,     0,     1,     4,    14,    17,    18,    24,    35,
      38,    39,    66,    71,    80,   100,   101,   118,   135,   148,
     149,   170,   183,   191,   195,   241,   246,   251,   277,   283,
     289,   303,   323,   347,   361,   376,   383,   387,   397,   406,
     427,   433,   439,   443,   449,   508,   525,   233,   234,   235,
     235,   324,   407,   434,   235,   444,   235,   362,   428,   348,
     235,   284,   304,   377,   235,   235,   398,   235,   235,   388,
       1,    25,    32,   102,   278,   279,   280,   281,   282,     1,
      22,    23,    28,    63,    64,    69,    70,    75,    76,    77,
      83,    84,   108,   109,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     235,   235,   235,     1,    65,   440,   441,   442,   235,     1,
       6,     7,    12,    20,    21,    27,    30,    31,    36,    41,
      42,    44,    45,    46,    48,    57,    61,    62,    72,    82,
      89,    91,    93,    95,    97,    98,   110,   115,   116,   117,
     119,   120,   121,   124,   150,   160,   161,   162,   163,   164,
     165,   192,   216,   217,   218,   220,   221,   222,   226,   231,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   501,   505,
     506,   507,   235,   235,   235,     1,    99,   123,   247,   248,
     249,   250,   235,   235,   235,     1,    29,    37,    49,    50,
      54,    55,    56,    79,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,     1,    25,    59,    68,    90,    94,
     102,   105,   106,   137,   154,   157,   158,   159,   184,   201,
     202,   203,   229,   230,   252,   253,   254,   255,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   235,     1,   227,   290,   291,
     292,   293,   294,     1,   102,   384,   385,   386,   235,   233,
     236,   236,   236,   234,   279,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   234,
     510,     1,    15,    16,    19,    67,    84,    85,    86,    87,
      88,    92,    96,   102,   113,   114,   125,   147,   187,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,     1,     3,
       5,    17,    33,    58,    60,    67,    78,   102,   126,   146,
     155,   201,   229,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   422,   423,   424,   425,   426,     1,
      65,   129,   435,   436,   437,   438,   236,   234,   441,     1,
     102,   129,   445,   446,   447,   448,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   502,   236,   498,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   234,   451,     1,    17,
      33,    67,   122,   130,   131,   151,   228,   363,   364,   365,
     366,   367,   368,   369,   373,   374,   375,     1,   129,   228,
     429,   430,   431,   432,     1,    58,    65,    67,   126,   349,
     353,   354,   355,   359,   360,   233,   236,   236,   234,   248,
       1,    81,   176,   285,   286,   287,   288,     1,    17,    33,
      67,   102,   122,   138,   155,   156,   206,   228,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   319,
       1,    35,    81,   129,   378,   379,   380,   381,   382,   236,
     236,   236,   236,   236,   236,   236,   236,   234,   527,   233,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   234,
     253,     1,   102,   224,   399,   400,   401,   402,   233,   236,
     234,   291,   176,   236,   234,   385,     1,   102,   224,   228,
     389,   390,   391,   392,   393,   127,   127,   127,   233,   112,
     112,   215,   112,   112,   243,   112,   243,   112,   243,   243,
     112,   112,   215,   215,   233,   233,   236,   236,   236,   344,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   234,   326,   233,   236,   236,   236,   236,
     236,   236,   419,   236,   236,   236,   236,   236,   236,   236,
     234,   409,   236,   236,   234,   436,   127,   233,   236,   236,
     234,   446,   215,   243,   243,   215,   112,   215,   112,   127,
     215,   243,   215,   112,   112,   243,   112,   215,   215,   215,
     243,   112,   112,   243,   112,   112,   112,   112,   215,   236,
     215,   236,   215,   243,   243,   215,   215,   215,   215,   219,
     215,   219,   215,   215,   215,   127,   112,   243,   215,   215,
     243,   243,   215,   215,   233,   233,   236,   236,   370,   236,
     236,   236,   236,   236,   234,   364,   236,   236,   234,   430,
     233,   236,   236,   350,   236,   234,   354,   127,   127,   233,
     233,   236,   236,   234,   286,   233,   236,   236,   320,   236,
     236,   236,   236,   236,   316,   236,   234,   306,   233,   236,
     236,   236,   234,   379,   215,   215,   215,   127,   215,   215,
     215,   243,   233,   127,   215,   127,   112,   112,   127,   127,
     127,   127,   127,   127,   127,   127,   112,   127,   204,   205,
     256,   257,   204,   205,   258,   259,   127,   127,   233,   233,
     236,   403,   234,   400,   215,   233,   235,   127,   233,   233,
     236,   394,   236,   234,   390,   233,   233,   233,   233,   233,
     233,   233,   139,   140,   141,   142,   143,   144,   145,   242,
     243,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   112,   112,   243,   236,   112,   112,   112,   243,   112,
     112,   243,   127,   112,   112,   243,   112,   245,   245,   233,
     127,   180,   181,   127,   215,   127,   127,   236,   127,   127,
     112,   127,   127,   127,   127,   233,   127,   127,   233,   233,
     127,   127,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
      49,   167,   168,   169,   171,   172,   174,   175,   177,   179,
     182,   185,   186,   188,   193,   197,   198,   199,   207,   212,
     503,   504,   233,    49,    51,    52,   167,   168,   169,   171,
     172,   174,   175,   177,   179,   182,   185,   186,   188,   193,
     197,   198,   199,   207,   212,   499,   500,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   127,
     215,   236,   127,   112,   127,   127,   127,   233,   127,   127,
     233,   127,   127,   236,   112,   357,   358,   233,   233,   233,
     127,   127,   233,   127,   215,   236,   127,   127,   127,   127,
     215,   236,   127,   233,   127,   127,   127,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   237,   233,   237,   233,   233,   127,   236,   233,
     233,     1,   102,   196,   224,   295,   296,   297,   298,   299,
     233,   127,   236,   127,   233,   242,   242,   242,   242,   242,
     242,   242,   233,   233,   233,    53,   128,   345,   346,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
       9,    10,    11,   244,   245,   233,   233,   233,   233,   233,
     233,   233,   233,   233,     8,   200,   420,   421,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     237,   233,   237,   233,   233,    13,    34,    43,    74,   103,
     104,   111,   136,   152,   214,   371,   372,   233,   233,   233,
     233,   233,   233,   233,   233,   233,    49,   190,   200,   351,
     352,   223,   237,   356,   233,   233,   233,   233,     4,    18,
      26,    40,    71,    73,    99,   132,   134,   153,   173,   178,
     182,   189,   194,   208,   211,   213,   225,   232,   321,   322,
     233,   233,   233,   233,   233,    49,    51,    52,   167,   168,
     169,   171,   172,   174,   175,   177,   179,   182,   185,   186,
     188,   193,   197,   198,   199,   207,   212,   317,   318,   233,
     233,   233,   233,   257,   259,   233,    73,   135,   166,   173,
     182,   208,   210,   211,   225,   232,   404,   405,   233,   236,
     236,   300,   234,   296,   233,    73,   135,   166,   173,   182,
     208,   210,   211,   225,   232,   395,   396,   233,   233,   237,
     244,   244,   244,   233,   237,   504,   500,   233,   237,   233,
     237,   112,   358,   233,   238,   238,   238,   233,   237,   233,
     237,   233,   237,   127,   209,   245,   236,   233,   233,   237,
     346,   421,   372,   352,   133,   133,   133,   322,   318,   405,
     233,   233,   233,    40,    71,    73,   118,   135,   172,   173,
     228,   232,   301,   302,   396,   233,   237,   302
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   239,   240,   240,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   242,   242,   243,
     243,   243,   243,   243,   243,   243,   243,   244,   244,   245,
     245,   245,   245,   246,   247,   247,   248,   248,   248,   249,
     250,   251,   252,   252,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   254,   255,   256,   256,   257,   257,
     258,   258,   259,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   278,   279,   279,   279,   279,   280,   281,
     282,   284,   283,   285,   285,   286,   286,   286,   287,   288,
     289,   290,   290,   291,   291,   291,   292,   294,   293,   295,
     295,   296,   296,   296,   296,   297,   298,   298,   300,   299,
     301,   301,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   304,   303,   305,   305,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   316,   315,   317,   317,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     320,   319,   321,   321,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   324,   323,   325,
     325,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   344,   343,   345,   345,   346,
     346,   348,   347,   350,   349,   351,   351,   352,   352,   352,
     353,   353,   354,   354,   354,   354,   354,   356,   355,   357,
     357,   358,   358,   359,   360,   362,   361,   363,   363,   364,
     364,   364,   364,   364,   364,   364,   364,   364,   365,   366,
     367,   368,   370,   369,   371,   371,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   373,   374,   375,   377,
     376,   378,   378,   379,   379,   379,   379,   380,   381,   382,
     383,   384,   384,   385,   385,   386,   388,   387,   389,   389,
     390,   390,   390,   390,   391,   392,   394,   393,   395,   395,
     396,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     398,   397,   399,   399,   400,   400,   400,   401,   403,   402,
     404,   404,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   407,   406,   408,   408,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   417,
     419,   418,   420,   420,   421,   421,   422,   423,   424,   425,
     426,   428,   427,   429,   429,   430,   430,   430,   431,   432,
     434,   433,   435,   435,   436,   436,   436,   437,   438,   439,
     440,   440,   441,   441,   442,   444,   443,   445,   445,   446,
     446,   446,   447,   448,   449,   450,   450,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   478,   479,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   498,   497,   499,   499,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   502,   501,   503,   503,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   505,   506,   507,   508,   509,
     509,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   526,   527,   527,   527,   527,   527,   527,   527,
     527,   527,   528,   529,   530,   531,   532,   533,   534,   535
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
       1,     1,     1,     2,     4,     4,     3,     1,     1,     1,
       3,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     2,     4,     4,
       5,     2,     1,     1,     1,     2,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
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
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4
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
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 428 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 442 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 448 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 484 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2995 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 490 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 3006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 499 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 3017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 505 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 3028 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 513 "conf_parser.y" /* yacc.c:1646  */
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
#line 3073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 555 "conf_parser.y" /* yacc.c:1646  */
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
#line 3134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 613 "conf_parser.y" /* yacc.c:1646  */
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
#line 3165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 641 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 649 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
  {
    if ((ServerInfo.message_digest_algorithm = EVP_get_digestbyname(yylval.string)) == NULL)
      conf_error_report("Ignoring serverinfo::ssl_message_digest_algorithm -- unknown message digest algorithm");
    else 
      ServerInfo.message_digest_algorithm = EVP_sha256();
  }
#endif
}
#line 3192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 662 "conf_parser.y" /* yacc.c:1646  */
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
#line 3223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 690 "conf_parser.y" /* yacc.c:1646  */
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
#line 3241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 705 "conf_parser.y" /* yacc.c:1646  */
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
#line 3259 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 720 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
#line 3271 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 729 "conf_parser.y" /* yacc.c:1646  */
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
#line 3288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 743 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
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
#line 3331 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 780 "conf_parser.y" /* yacc.c:1646  */
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
#line 3364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 810 "conf_parser.y" /* yacc.c:1646  */
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
#line 3392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 835 "conf_parser.y" /* yacc.c:1646  */
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
#line 3417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 857 "conf_parser.y" /* yacc.c:1646  */
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
#line 3442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 879 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 896 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 905 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3475 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 914 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 926 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 930 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
    motd_add(ptr->data, block_state.file.buf);
}
#line 3513 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3522 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 953 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3540 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 974 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3549 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 978 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3562 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 994 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1002 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1005 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1010 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1017 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3652 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3661 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3670 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1059 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1066 "conf_parser.y" /* yacc.c:1646  */
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
#line 3767 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1152 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1158 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3785 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1164 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1170 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3808 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1181 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3817 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1187 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3826 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1193 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1210 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1217 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1225 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1237 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1245 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1253 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1257 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1261 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4011 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4020 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1307 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4065 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1314 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1318 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1322 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1326 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1330 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1334 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1338 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1342 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1346 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1350 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4155 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1354 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1358 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1362 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1366 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1370 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1374 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1378 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1382 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4227 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1386 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1390 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1394 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1398 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1402 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1412 "conf_parser.y" /* yacc.c:1646  */
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
#line 4289 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1424 "conf_parser.y" /* yacc.c:1646  */
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
#line 4342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1493 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4351 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1499 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1505 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1511 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1517 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1523 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1529 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1535 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1541 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1547 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1553 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1560 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1566 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1572 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1578 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1587 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4493 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1596 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1603 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1607 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1617 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1623 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4537 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1629 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1633 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1637 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4564 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1645 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4570 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1650 "conf_parser.y" /* yacc.c:1646  */
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
#line 4589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1664 "conf_parser.y" /* yacc.c:1646  */
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
#line 4610 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1682 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1688 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4628 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1697 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4637 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1701 "conf_parser.y" /* yacc.c:1646  */
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
#line 4678 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1750 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4687 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1756 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4696 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1762 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1768 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4719 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1779 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4728 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1786 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4737 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1790 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4746 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1794 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4755 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1798 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1802 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1806 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1810 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1814 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1818 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1822 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1828 "conf_parser.y" /* yacc.c:1646  */
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
#line 4835 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1842 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1864 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1871 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1882 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1888 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1894 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1909 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1924 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1935 "conf_parser.y" /* yacc.c:1646  */
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
#line 4957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1952 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1958 "conf_parser.y" /* yacc.c:1646  */
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
#line 4988 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1977 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4997 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1984 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1988 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1996 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5033 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5042 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2004 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5051 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2008 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5060 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2012 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2016 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2020 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2038 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2059 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2074 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2078 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2082 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5179 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2086 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2090 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2094 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2098 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5215 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2102 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2111 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2120 "conf_parser.y" /* yacc.c:1646  */
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
#line 5304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5313 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2206 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5322 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5331 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2218 "conf_parser.y" /* yacc.c:1646  */
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
#line 5347 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2231 "conf_parser.y" /* yacc.c:1646  */
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
#line 5363 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2250 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2260 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2268 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2274 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2278 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2295 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2307 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2313 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2328 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2332 "conf_parser.y" /* yacc.c:1646  */
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
#line 5516 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2357 "conf_parser.y" /* yacc.c:1646  */
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
#line 5539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2377 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2386 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5557 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2390 "conf_parser.y" /* yacc.c:1646  */
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
#line 5583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2416 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2422 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5601 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 454:
#line 2436 "conf_parser.y" /* yacc.c:1646  */
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
#line 5618 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 455:
#line 2453 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5627 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2457 "conf_parser.y" /* yacc.c:1646  */
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
#line 5649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 462:
#line 2479 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 463:
#line 2485 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2551 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2556 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2562 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2568 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5702 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2574 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5711 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2580 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5719 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2585 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5727 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2590 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5735 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2595 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5743 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2600 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5751 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2605 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5759 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2610 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5767 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2615 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2620 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number);
}
#line 5783 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2625 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2630 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5799 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2635 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5807 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2640 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2645 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2651 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2662 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2667 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_connect_block = yylval.number;
}
#line 5854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2672 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5862 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2677 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5870 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2682 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5878 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2687 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2692 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2695 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2700 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2703 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2708 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2713 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2718 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2723 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2728 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2733 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2738 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2743 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2753 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2758 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.use_egd = yylval.number;
}
#line 6006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2763 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
#line 6018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 6030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2781 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 6038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 6046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2791 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_count = (yyvsp[-1].number);
}
#line 6054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2796 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = (yyvsp[-1].number);
}
#line 6062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 6070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 6078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 6086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 6094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 6102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 6110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 6118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDECHANS;
}
#line 6126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 6142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6158 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6166 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6198 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2861 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2864 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2867 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2870 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6262 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2884 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6286 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2893 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2896 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6302 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2899 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2902 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2908 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6334 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2911 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2914 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2917 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2920 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2923 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2926 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2929 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2932 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2935 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2938 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2943 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2948 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6430 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2953 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2982 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2987 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2992 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2997 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 3002 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3007 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3012 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3017 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 3022 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6510 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3027 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6518 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 3032 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6526 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 3037 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6534 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 3042 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 3047 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3069 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3075 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6568 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3081 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6577 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3087 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6586 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 666:
#line 3093 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 3102 "conf_parser.y" /* yacc.c:1646  */
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
#line 6616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 668:
#line 3117 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 669:
#line 3123 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6634 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6638 "conf_parser.c" /* yacc.c:1646  */
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
