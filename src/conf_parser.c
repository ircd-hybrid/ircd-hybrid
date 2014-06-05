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


#line 184 "conf_parser.c" /* yacc.c:339  */

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
    MAX_CHANS_PER_OPER = 339,
    MAX_CHANS_PER_USER = 340,
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
    T_OPERWALL = 441,
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
#define MAX_CHANS_PER_OPER 339
#define MAX_CHANS_PER_USER 340
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
#define T_OPERWALL 441
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
#line 146 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 691 "conf_parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 706 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1261

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  238
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  667
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1307

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
       0,   381,   381,   382,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   411,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   422,   422,   423,
     424,   425,   426,   433,   436,   436,   437,   437,   437,   439,
     445,   452,   454,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   475,   476,   478,   478,   479,   485,   493,   493,
     494,   500,   508,   550,   608,   636,   644,   659,   674,   683,
     697,   706,   734,   764,   789,   811,   833,   842,   844,   844,
     845,   846,   847,   848,   850,   859,   868,   881,   880,   898,
     898,   899,   899,   899,   901,   907,   916,   917,   917,   919,
     919,   920,   922,   929,   929,   942,   943,   945,   945,   946,
     946,   948,   956,   959,   965,   964,   970,   970,   971,   975,
     979,   983,   987,   991,   995,   999,  1003,  1014,  1013,  1093,
    1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1106,  1112,  1118,  1124,  1135,  1141,  1147,  1158,
    1165,  1164,  1170,  1170,  1171,  1175,  1179,  1183,  1187,  1191,
    1195,  1199,  1203,  1207,  1211,  1215,  1219,  1223,  1227,  1231,
    1235,  1239,  1243,  1247,  1251,  1255,  1259,  1266,  1265,  1271,
    1271,  1272,  1276,  1280,  1284,  1288,  1292,  1296,  1300,  1304,
    1308,  1312,  1316,  1320,  1324,  1328,  1332,  1336,  1340,  1344,
    1348,  1352,  1356,  1360,  1364,  1375,  1374,  1435,  1435,  1436,
    1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,
    1447,  1447,  1448,  1449,  1450,  1451,  1453,  1459,  1465,  1471,
    1477,  1483,  1489,  1495,  1501,  1507,  1514,  1520,  1526,  1532,
    1541,  1551,  1550,  1556,  1556,  1557,  1561,  1572,  1571,  1578,
    1577,  1582,  1582,  1583,  1587,  1591,  1597,  1597,  1598,  1598,
    1598,  1598,  1598,  1600,  1600,  1602,  1602,  1604,  1618,  1636,
    1642,  1652,  1651,  1693,  1693,  1694,  1695,  1696,  1697,  1698,
    1699,  1700,  1701,  1702,  1704,  1710,  1716,  1722,  1734,  1733,
    1739,  1739,  1740,  1744,  1748,  1752,  1756,  1760,  1764,  1768,
    1772,  1776,  1782,  1796,  1805,  1819,  1818,  1833,  1833,  1834,
    1834,  1834,  1834,  1836,  1842,  1848,  1858,  1860,  1860,  1861,
    1861,  1863,  1879,  1878,  1903,  1903,  1904,  1904,  1904,  1904,
    1906,  1912,  1932,  1931,  1937,  1937,  1938,  1942,  1946,  1950,
    1954,  1958,  1962,  1966,  1970,  1974,  1984,  1983,  2004,  2004,
    2005,  2005,  2005,  2007,  2014,  2013,  2019,  2019,  2020,  2024,
    2028,  2032,  2036,  2040,  2044,  2048,  2052,  2056,  2066,  2065,
    2137,  2137,  2138,  2139,  2140,  2141,  2142,  2143,  2144,  2145,
    2146,  2147,  2148,  2149,  2150,  2151,  2152,  2154,  2160,  2166,
    2172,  2185,  2198,  2204,  2210,  2214,  2223,  2222,  2227,  2227,
    2228,  2232,  2238,  2249,  2255,  2261,  2267,  2283,  2282,  2308,
    2308,  2309,  2309,  2309,  2311,  2331,  2341,  2340,  2367,  2367,
    2368,  2368,  2368,  2370,  2376,  2385,  2387,  2387,  2388,  2388,
    2390,  2408,  2407,  2430,  2430,  2431,  2431,  2431,  2433,  2439,
    2448,  2451,  2451,  2452,  2453,  2454,  2455,  2456,  2457,  2458,
    2459,  2460,  2461,  2462,  2463,  2464,  2465,  2466,  2467,  2468,
    2469,  2470,  2471,  2472,  2473,  2474,  2475,  2476,  2477,  2478,
    2479,  2480,  2481,  2482,  2483,  2484,  2485,  2486,  2487,  2488,
    2489,  2490,  2491,  2492,  2493,  2494,  2495,  2496,  2497,  2498,
    2499,  2500,  2501,  2504,  2509,  2515,  2521,  2527,  2533,  2538,
    2543,  2548,  2553,  2558,  2563,  2568,  2573,  2578,  2583,  2588,
    2593,  2598,  2604,  2615,  2620,  2625,  2630,  2635,  2640,  2645,
    2648,  2653,  2656,  2661,  2666,  2671,  2676,  2681,  2686,  2691,
    2696,  2701,  2706,  2711,  2716,  2725,  2734,  2739,  2744,  2750,
    2749,  2754,  2754,  2755,  2758,  2761,  2764,  2767,  2770,  2773,
    2776,  2779,  2782,  2785,  2788,  2791,  2794,  2797,  2800,  2803,
    2806,  2809,  2812,  2815,  2818,  2821,  2827,  2826,  2831,  2831,
    2832,  2835,  2838,  2841,  2844,  2847,  2850,  2853,  2856,  2859,
    2862,  2865,  2868,  2871,  2874,  2877,  2880,  2883,  2886,  2889,
    2892,  2897,  2902,  2907,  2916,  2919,  2919,  2920,  2921,  2922,
    2923,  2924,  2925,  2926,  2927,  2928,  2929,  2930,  2931,  2932,
    2933,  2934,  2935,  2937,  2943,  2948,  2953,  2958,  2963,  2968,
    2973,  2978,  2983,  2988,  2993,  2998,  3003,  3008,  3016,  3019,
    3019,  3020,  3021,  3022,  3023,  3024,  3025,  3026,  3027,  3028,
    3030,  3036,  3042,  3048,  3054,  3063,  3077,  3083
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
  "LISTEN", "MASK", "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_OPER",
  "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT", "MAX_IDLE", "MAX_LOCAL",
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
  "SSL_DH_PARAM_FILE", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY",
  "STATS_U_OPER_ONLY", "T_ALL", "T_BOTS", "T_CALLERID", "T_CCONN",
  "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS", "T_INVISIBLE", "T_IPV4",
  "T_IPV6", "T_LOCOPS", "T_LOG", "T_MAX_CLIENTS", "T_NCHANGE",
  "T_NONONREG", "T_OPERWALL", "T_RECVQ", "T_REJ", "T_RESTART", "T_SERVER",
  "T_SERVICE", "T_SERVICES_NAME", "T_SERVNOTICE", "T_SET", "T_SHARED",
  "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL",
  "T_SSL_CIPHER_LIST", "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD",
  "T_SSLV3", "T_TLSV1", "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED",
  "T_UNRESV", "T_UNXLINE", "T_WALLOP", "T_WALLOPS", "T_WEBIRC", "TBOOL",
  "THROTTLE_TIME", "TKLINE_EXPIRE_NOTICES", "TMASKED",
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
  "serverinfo_ssl_cipher_list", "serverinfo_name", "serverinfo_sid",
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
  "class_connectfreq", "class_max_number", "class_max_global",
  "class_max_local", "class_max_ident", "class_sendq", "class_recvq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
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
  "general_ping_cookie", "general_disable_auth", "general_throttle_time",
  "general_oper_umodes", "$@24", "umode_oitems", "umode_oitem",
  "general_oper_only_umodes", "$@25", "umode_items", "umode_item",
  "general_min_nonwildcard", "general_min_nonwildcard_simple",
  "general_default_floodcount", "channel_entry", "channel_items",
  "channel_item", "channel_disable_fake_channels",
  "channel_invite_client_count", "channel_invite_client_time",
  "channel_knock_client_count", "channel_knock_client_time",
  "channel_knock_delay_channel", "channel_max_chans_per_user",
  "channel_max_chans_per_oper", "channel_max_bans",
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

#define YYPACT_NINF -922

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-922)))

#define YYTABLE_NINF -124

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -922,   749,  -922,  -140,  -226,  -214,  -922,  -922,  -922,  -204,
    -922,  -192,  -922,  -922,  -922,  -186,  -922,  -922,  -922,  -172,
    -151,  -922,  -149,  -125,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,    20,
     852,  -107,   -98,   -93,    10,   -85,   454,   -79,   -60,   -59,
      24,   -41,   -27,   -25,   409,   530,   -21,     4,    32,   -17,
    -156,   -10,    -8,    -6,    15,  -922,  -922,  -922,  -922,  -922,
      -4,    -2,     1,    37,    38,    39,    43,    51,    53,    61,
      62,    64,    67,    69,    74,   299,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,   746,   411,    21,  -922,    75,     8,  -922,  -922,
      23,  -922,    78,    90,    91,    93,    94,    96,   100,   102,
     106,   108,   117,   118,   119,   121,   124,   126,   136,   138,
     142,   144,   145,   150,   151,   152,   154,   163,   164,  -922,
     167,  -922,   169,   170,   171,   172,   176,   180,   182,   183,
     184,   188,   189,   191,   194,   195,   196,   197,   198,   199,
     200,    60,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,   476,    35,   323,   -31,   202,   204,    13,  -922,
    -922,  -922,    22,   424,    34,  -922,   208,   210,   213,   214,
     216,   217,   227,   232,     9,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,   -14,   233,   235,   237,   238,   241,
     244,   245,   247,   248,   251,   252,   257,   262,   269,   270,
     271,   272,   137,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,    83,     7,   273,    25,  -922,  -922,  -922,    84,  -922,
     275,    54,  -922,  -922,    11,  -922,   141,   161,   312,   140,
    -922,   157,   399,   298,   405,   406,   407,   406,   408,   406,
     406,   412,   416,   422,   307,   319,   305,  -922,   308,   304,
     306,   310,  -922,   314,   316,   324,   325,   326,   327,   329,
     331,   333,   334,   338,   342,   168,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,   322,   343,   347,   348,   349,   350,   353,
    -922,   355,   356,   357,   359,   360,   362,   365,   300,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,   368,   369,    17,  -922,  -922,
    -922,   414,   374,  -922,  -922,   376,   385,    31,  -922,  -922,
    -922,   419,   406,   406,   420,   509,   423,   511,   498,   425,
     406,   427,   514,   531,   406,   534,   434,   435,   438,   406,
     544,   545,   406,   546,   547,   548,   549,   448,   430,   451,
     432,   457,   406,   406,   461,   462,   463,  -147,   -90,   465,
     466,   467,   541,   406,   471,   475,   406,   406,   477,   480,
     464,  -922,   468,   469,   470,  -922,   474,   484,   485,   486,
     487,   290,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,   488,   489,    33,  -922,  -922,  -922,   478,   490,
     491,  -922,   492,  -922,    12,  -922,  -922,  -922,  -922,  -922,
     569,   571,   479,  -922,   496,   494,   495,    14,  -922,  -922,
    -922,   502,   500,   501,  -922,   503,   504,   505,   508,   510,
    -922,   516,   297,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,   512,   517,   519,   521,    16,  -922,
    -922,  -922,  -922,   497,   542,   553,   573,   555,   556,   559,
     406,   543,  -922,  -922,   574,   561,   587,   585,   633,   652,
     653,   654,   655,   657,   661,   677,   664,   -32,    63,   665,
     667,   566,  -922,   567,   565,  -922,   111,  -922,  -922,  -922,
    -922,   588,   572,  -922,   568,   678,   576,  -922,   577,   575,
    -922,   581,   109,  -922,  -922,  -922,  -922,   580,   586,   589,
    -922,   590,   591,   592,   593,   205,   594,   604,   605,   606,
     608,   609,   610,   612,   613,   614,   615,  -922,  -922,   692,
     704,   406,   584,   735,   739,   406,   741,   742,   406,   728,
     744,   745,   406,   751,   751,   627,  -922,  -922,   734,    36,
     743,   658,   748,   750,   632,   753,   754,   756,   755,   758,
     759,   761,   638,  -922,   762,   763,   645,  -922,   647,  -922,
     764,   765,   663,  -922,   668,   669,   670,   671,   672,   673,
     675,   676,   679,   680,   681,   682,   685,   687,   688,   691,
     693,   694,   698,   700,   702,   706,   707,   709,   710,   711,
     716,   857,   719,   779,   722,   724,   726,   727,   736,   737,
     738,   747,   757,   769,   771,   772,   773,   774,   776,   777,
     778,   782,   783,   784,   785,  -922,  -922,   768,   695,   649,
     781,   811,   838,   843,   845,   786,  -922,   846,   847,   787,
    -922,  -922,   855,   865,   662,   881,   788,  -922,   790,   797,
    -922,  -922,   868,   869,   800,  -922,  -922,   906,   821,   802,
     911,   912,   916,   918,   832,   813,   921,   819,  -922,  -922,
     924,   925,   929,   826,  -922,   827,   828,   829,   830,   831,
     833,   834,   835,  -922,   836,   839,   840,   841,   842,   844,
     848,   849,   850,   851,   853,   854,   856,  -922,  -922,  -195,
    -922,  -922,  -922,  -193,  -922,   858,   859,  -922,  -922,   942,
     860,   861,  -922,   862,  -922,    88,   864,  -922,  -922,   947,
     863,   949,   867,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,   406,   406,   406,   406,   406,   406,   406,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,   870,   871,   872,    -9,   873,   874,   875,   876,   877,
     878,   879,   880,   882,   883,    18,   884,   885,  -922,   886,
     887,   888,   889,   890,   891,   892,    -5,   893,   894,   895,
     896,   897,   898,   899,  -922,   900,   901,  -922,  -922,   902,
     903,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -182,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -179,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,   904,
     905,   674,   907,   908,   909,   910,   913,  -922,   914,   915,
    -922,   917,   919,   -30,   922,   920,  -922,  -922,  -922,  -922,
     923,   926,  -922,   927,   928,   583,   930,   931,   932,   933,
     934,   814,   935,  -922,   936,   937,   938,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
     -32,  -922,    63,  -922,  -922,   939,   421,  -922,  -922,   940,
     866,   941,  -922,    30,  -922,  -922,  -922,  -922,  -922,   943,
     483,   945,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -176,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,   751,   751,   751,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -158,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,   857,  -922,   779,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -138,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,   -44,  -922,   965,   881,
     946,  -922,  -922,  -922,  -922,  -922,   944,  -922,  -922,   948,
    -922,  -922,  -922,  -922,   950,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,   -42,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,   -34,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,   -33,  -922,  -922,   951,   -64,
     953,   952,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,   -28,  -922,  -922,  -922,    -9,  -922,
    -922,  -922,  -922,    -5,  -922,  -922,  -922,   674,  -922,   -30,
    -922,  -922,  -922,   955,   958,   963,  -922,   583,  -922,   814,
    -922,   421,   954,   957,   959,   570,  -922,  -922,   483,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,   -26,  -922,  -922,  -922,   570,  -922
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   225,   388,   436,     0,
     451,     0,   291,   427,   267,     0,   107,   147,   325,     0,
       0,   366,     0,     0,   342,     3,    23,    11,     4,    24,
       5,     6,     8,     9,    10,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    21,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   102,   101,   632,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   616,   631,   618,   619,
     620,   621,   622,   623,   624,   617,   625,   626,   627,   628,
     629,   630,     0,     0,     0,   449,     0,     0,   447,   448,
       0,   512,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   586,
       0,   559,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   462,   509,   511,   503,   504,   505,   506,   507,
     502,   473,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   499,   474,   475,   508,   477,   482,   483,   478,
     480,   479,   493,   494,   481,   484,   485,   486,   487,   476,
     489,   490,   491,   510,   500,   501,   498,   492,   488,   496,
     497,   495,     0,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,     0,   659,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   650,   651,   652,   653,   654,
     657,   655,   656,   658,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    68,    69,    67,    64,    63,    70,
      54,    66,    57,    58,    59,    55,    65,    60,    61,    62,
      56,     0,     0,     0,     0,   118,   119,   120,     0,   340,
       0,     0,   338,   339,     0,   103,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   615,     0,     0,
       0,     0,   261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,   229,   232,   234,
     235,   236,   237,   238,   239,   240,   241,   230,   231,   233,
     242,   243,   244,     0,     0,     0,     0,     0,     0,     0,
     416,     0,     0,     0,     0,     0,     0,     0,     0,   391,
     392,   393,   394,   395,   396,   397,   399,   398,   401,   405,
     402,   403,   404,   400,   442,     0,     0,     0,   439,   440,
     441,     0,     0,   446,   457,     0,     0,     0,   454,   455,
     456,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   461,     0,     0,     0,   308,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   302,   298,   299,   300,
     301,   433,     0,     0,     0,   430,   431,   432,     0,     0,
       0,   269,     0,   279,     0,   277,   278,   280,   281,    48,
       0,     0,     0,    44,     0,     0,     0,     0,   110,   111,
     112,     0,     0,     0,   197,     0,     0,     0,     0,     0,
     170,     0,     0,   150,   151,   152,   153,   156,   157,   158,
     159,   155,   154,   160,     0,     0,     0,     0,     0,   328,
     329,   330,   331,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   649,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,   374,     0,   369,   370,   371,
     121,     0,     0,   117,     0,     0,     0,   337,     0,     0,
     352,     0,     0,   345,   346,   347,   348,     0,     0,     0,
      97,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   614,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   406,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   390,     0,     0,     0,   438,     0,   445,
       0,     0,     0,   453,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   460,   303,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,     0,     0,     0,
     429,   282,     0,     0,     0,     0,     0,   276,     0,     0,
      43,   113,     0,     0,     0,   109,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,   332,
       0,     0,     0,     0,   327,     0,     0,     0,     0,     0,
       0,     0,     0,   648,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,     0,
      75,    80,    81,     0,    79,     0,     0,    51,   372,     0,
       0,     0,   368,     0,   116,     0,     0,   336,   349,     0,
       0,     0,     0,   344,   106,   105,   104,   643,   642,   633,
     634,    27,    27,    27,    27,    27,    27,    27,    29,    28,
     635,   646,   647,   636,   637,   638,   641,   640,   639,   644,
     645,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   389,     0,     0,   437,   450,     0,
       0,   452,   525,   529,   544,   514,   613,   557,   551,   554,
     524,   516,   515,   518,   519,   517,   532,   522,   523,   533,
     521,   528,   527,   526,   552,   513,   611,   612,   548,   596,
     590,   607,   591,   592,   593,   601,   610,   594,   604,   608,
     597,   609,   602,   598,   603,   595,   606,   600,   599,   605,
       0,   589,   550,   568,   569,   570,   563,   582,   564,   565,
     566,   576,   585,   567,   579,   583,   572,   584,   577,   573,
     578,   571,   581,   575,   574,   580,     0,   562,   545,   543,
     546,   556,   547,   535,   541,   542,   539,   540,   536,   537,
     538,   555,   558,   520,   549,   531,   530,   553,   534,     0,
       0,     0,     0,     0,     0,     0,     0,   292,     0,     0,
     428,     0,     0,     0,   287,   283,   286,   268,    49,    50,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,     0,     0,     0,   326,   661,   660,
     666,   664,   667,   662,   663,   665,    88,    96,    87,    94,
      95,    86,    90,    89,    83,    82,    84,    93,    85,    72,
       0,    73,     0,    91,    92,     0,     0,   367,   122,     0,
       0,     0,   134,     0,   126,   127,   129,   128,   341,     0,
       0,     0,   343,    30,    31,    32,    33,    34,    35,    36,
     256,   257,   249,   266,   265,     0,   264,   251,   253,   260,
     252,   250,   259,   246,   258,   248,   247,    37,    37,    37,
      39,    38,   254,   255,   411,   414,   415,   425,   422,   408,
     423,   420,   421,     0,   419,   424,   407,   413,   410,   412,
     426,   409,   443,   444,   458,   459,   587,     0,   560,     0,
     306,   307,   316,   313,   318,   314,   315,   321,   317,   319,
     312,   320,     0,   311,   305,   324,   323,   322,   304,   435,
     434,   290,   289,   274,   275,   273,     0,   272,     0,     0,
       0,   114,   115,   169,   165,   217,   204,   214,   213,   202,
     207,   224,   216,   222,   206,   209,   219,   221,   218,   215,
     223,   210,   212,   220,   208,   211,     0,   200,   162,   164,
     166,   167,   168,   179,   180,   181,   174,   193,   175,   176,
     177,   187,   196,   178,   190,   194,   183,   195,   188,   184,
     189,   182,   192,   186,   185,   191,     0,   173,   163,   335,
     333,   334,    74,    78,   373,   378,   384,   387,   380,   386,
     381,   385,   383,   379,   382,     0,   377,   130,     0,     0,
       0,     0,   125,   350,   356,   362,   365,   358,   364,   359,
     363,   361,   357,   360,     0,   355,   351,   262,     0,    40,
      41,    42,   417,     0,   588,   561,   309,     0,   270,     0,
     288,   285,   284,     0,     0,     0,   198,     0,   171,     0,
     375,     0,     0,     0,     0,     0,   124,   353,     0,   263,
     418,   310,   271,   203,   201,   205,   199,   172,   376,   131,
     133,   132,   140,   145,   144,   139,   142,   146,   143,   138,
     141,     0,   137,   354,   135,     0,   136
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -922,  -922,  -922,  -430,  -313,  -921,  -633,  -922,  -922,   962,
    -922,  -922,  -922,  -922,   812,  -922,  -922,  -922,    47,  -922,
      58,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  1039,  -922,
    -922,  -922,  -922,  -922,  -922,   631,  -922,  -922,  -922,  -922,
     956,  -922,  -922,  -922,  -922,    95,  -922,  -922,  -922,  -922,
    -922,  -162,  -922,  -922,  -922,   628,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -117,  -922,  -922,
    -922,  -114,  -922,  -922,  -922,   809,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,   -91,  -922,  -922,  -922,  -922,  -922,
     -86,  -922,   686,  -922,  -922,  -922,    44,  -922,  -922,  -922,
    -922,  -922,   690,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
     -83,  -922,  -922,  -922,  -922,  -922,  -922,   641,  -922,  -922,
    -922,  -922,  -922,   960,  -922,  -922,  -922,  -922,   600,  -922,
    -922,  -922,  -922,  -922,   -96,  -922,  -922,  -922,   607,  -922,
    -922,  -922,  -922,   -77,  -922,  -922,  -922,   817,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,   -57,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,   713,  -922,
    -922,  -922,  -922,  -922,   801,  -922,  -922,  -922,  -922,  1082,
    -922,  -922,  -922,  -922,   793,  -922,  -922,  -922,  -922,  1030,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,    85,  -922,  -922,
    -922,    86,  -922,  -922,  -922,  -922,  -922,  1107,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922,  -922,   961,  -922,  -922,  -922,  -922,
    -922,  -922,  -922,  -922
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   828,   829,  1090,  1091,    26,   228,   229,
     230,   231,    27,   272,   273,   274,   275,   789,   790,   793,
     794,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    28,    74,    75,    76,
      77,    78,    29,    61,   507,   508,   509,   510,    30,   294,
     295,   296,   297,   298,  1053,  1054,  1055,  1056,  1057,  1230,
    1301,  1302,    31,    62,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   755,  1206,  1207,   533,   749,
    1176,  1177,    32,    51,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   622,  1075,  1076,    33,    59,   493,   734,  1146,
    1147,   494,   495,   496,  1150,   995,   996,   497,   498,    34,
      57,   471,   472,   473,   474,   475,   476,   477,   719,  1132,
    1133,   478,   479,   480,    35,    63,   538,   539,   540,   541,
     542,    36,   301,   302,   303,    37,    69,   592,   593,   594,
     595,   596,   810,  1244,  1245,    38,    66,   576,   577,   578,
     579,   800,  1225,  1226,    39,    52,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   644,  1103,  1104,
     389,   390,   391,   392,   393,    40,    58,   484,   485,   486,
     487,    41,    53,   397,   398,   399,   400,    42,   117,   118,
     119,    43,    55,   407,   408,   409,   410,    44,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   440,   956,   957,   218,   438,
     930,   931,   219,   220,   221,    45,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    46,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     856,   857,   606,  1101,   608,   292,   610,   611,    49,   115,
     235,   115,   588,   488,   225,   504,    70,   534,   394,  1143,
      50,    70,   394,   504,   404,   225,   292,  1087,  1088,  1089,
      54,  1049,   404,   299,   481,   534,   481,  1039,   236,  1041,
      71,  1040,    56,  1042,  1073,    71,   237,    72,    60,   855,
    1116,   535,    72,  1118,  1117,   299,  1247,  1119,   238,   239,
    1248,   121,    64,   240,   241,   242,   122,   123,   700,   535,
     489,   701,   124,   116,  1252,   116,   305,   490,  1253,   491,
     125,   126,   395,    65,   573,    67,   395,   127,   243,  1049,
     128,   129,    47,    48,  1256,   505,   130,   536,  1257,   665,
     666,   131,   132,   505,   133,   134,   135,   673,   136,    68,
     588,   677,   573,   226,   589,   536,   682,   137,    73,   685,
    1074,   138,   139,    73,   226,   702,   405,   112,   703,   695,
     696,   855,   140,  1050,   405,   300,   113,   227,   254,   492,
     708,   114,   141,   711,   712,  1273,   537,   396,   227,   120,
     142,   396,   143,   406,   144,   222,   145,   300,   146,   147,
    1144,   406,   255,   482,   537,   482,  1249,  1250,  1251,   328,
    1145,   148,   787,   788,   223,   224,   149,   150,   151,  -123,
     152,   153,   154,   329,   330,   155,   574,   331,  1258,   506,
    1266,  1050,  1259,   232,  1267,  1102,   256,   506,  1268,  1270,
    -123,   499,  1269,  1271,  1277,   257,  1304,   233,  1278,   234,
    1305,   156,   589,   291,   574,   860,   861,   304,   553,   157,
     158,   159,   160,   161,   162,   306,  1051,   307,   258,   308,
     293,   311,   259,   312,   590,   332,   313,   772,   591,   580,
     260,   402,   551,   261,   262,   736,   502,   744,   309,   763,
     656,   293,   163,  1052,   333,   334,   335,   336,   582,   584,
     483,   337,   483,  1231,   662,   338,   729,   791,   792,   597,
     601,   339,   314,   315,   316,   263,   164,   165,   317,   166,
     167,   168,   340,   341,  1051,   169,   318,   586,   319,   598,
     170,   462,   264,   460,   342,   265,   320,   321,   511,   322,
      79,   363,   323,   364,   324,   365,   575,   463,   843,   325,
     401,  1052,   847,   411,   512,   850,   343,   366,   605,   854,
     266,    80,    81,   464,   488,   412,   413,    82,   414,   415,
     513,   416,   590,   367,   575,   417,   591,   418,   267,   268,
     269,   419,   812,   420,   801,   821,   822,   823,   824,   825,
     826,   827,   421,   422,   423,   344,   424,   465,   368,   425,
     369,   426,    83,    84,   514,   270,   271,   370,    85,    86,
     571,   427,   600,   428,    87,    88,    89,   429,   371,   430,
     431,   489,    90,    91,    92,   432,   433,   434,   490,   435,
     491,  1063,  1064,  1065,  1066,  1067,  1068,  1069,   436,   437,
     515,   635,   439,   372,   441,   442,   443,   444,    93,    94,
     235,   445,   363,   466,   364,   446,   365,   447,   448,   449,
     516,   467,   468,   450,   451,   511,   452,   373,   366,   453,
     454,   455,   456,   457,   458,   459,   517,   500,   236,   501,
     599,   512,   469,   543,   367,   544,   237,   374,   545,   546,
     492,   547,   548,   518,   519,   121,   375,   513,   238,   239,
     122,   123,   549,   240,   241,   242,   124,   550,   554,   368,
     555,   369,   556,   557,   125,   126,   558,   462,   370,   559,
     560,   127,   561,   562,   128,   129,   563,   564,   243,   371,
     130,   514,   565,   463,  1215,   131,   132,   566,   133,   134,
     135,   376,   136,   520,   567,   568,   569,   570,   581,   464,
     585,   137,   602,   603,   372,   138,   139,   470,   604,   605,
     607,   609,   615,   725,   521,   612,   140,   515,   377,   613,
     757,   254,   326,   652,   616,   614,   141,   617,   373,   619,
     618,   620,   658,   465,   142,   621,   143,   516,   144,   623,
     145,   624,   146,   147,   637,   255,  1234,  1216,   374,   625,
     626,   627,   628,   517,   629,   148,   630,   375,   631,   632,
     149,   150,   151,   633,   152,   153,   154,   634,   638,   155,
     518,   519,   639,   640,   641,   642,  1217,  1155,   643,   256,
     645,   646,   647,  1218,   648,   649,  1274,   650,   257,   466,
     651,  1156,  1219,   654,   655,   156,   659,   467,   468,  1157,
    1292,   660,   376,   157,   158,   159,   160,   161,   162,  1235,
     661,   258,   668,  1158,   670,   259,   671,   675,   469,  1220,
     520,  1221,  1222,   260,   664,   667,   261,   262,   669,   377,
     672,  1293,   674,  1294,   676,  1223,   163,   678,  1236,   679,
     680,   521,  1224,   681,  1159,  1237,  1160,   683,   684,   686,
     687,   688,   689,   690,  1238,   691,   692,   693,   263,   707,
     164,   165,   694,   166,   167,   168,   697,   698,   699,   169,
     704,   705,   706,  1161,   170,   264,   709,  1122,   265,  1295,
     710,  1239,   713,  1240,  1241,   714,   715,   738,   777,   739,
     716,   768,   774,   470,   717,   718,  1296,  1242,  1123,   720,
     731,   740,   765,   266,  1243,   776,  1162,  1124,  1163,   721,
     722,   723,   724,   727,   728,   732,   733,   735,   741,   742,
     743,   267,   268,   269,   746,   747,   748,  1164,   750,   751,
     752,  1297,  1298,   753,   759,   754,   778,   328,  1125,     2,
       3,   756,   760,     4,   761,  1165,   762,   766,   270,   271,
    1166,   329,   330,     5,  1167,   331,     6,     7,   767,  1168,
     769,   770,  1169,     8,   771,   773,   775,  1170,  1126,  1127,
     779,   780,   781,   782,     9,   783,  1128,    10,    11,   784,
     785,  1171,   786,   795,  1172,   796,  1173,  1299,   797,   798,
     799,  1300,   805,   803,   804,   841,   806,  1174,   807,   808,
     809,  1129,   814,   332,  1175,    12,   811,   842,   815,   844,
      13,   816,   817,   818,   819,   820,   830,  1130,   933,    14,
     934,   935,   333,   334,   335,   336,   831,   832,   833,   337,
     834,   835,   836,   338,   837,   838,   839,   840,   845,   339,
      15,    16,   846,    79,   848,   849,   851,   852,   853,   858,
     340,   341,   859,  1183,   855,  1184,  1185,   866,    17,   869,
     874,   862,   342,   863,    80,    81,   864,   877,   865,   878,
      82,   867,   868,   870,   981,    18,   871,   872,  1131,   873,
     875,   876,   879,   880,   343,   881,   979,   993,    19,    20,
     882,   883,   884,   885,   886,   887,   909,   888,   889,   982,
     980,   890,   891,   892,   893,    83,    84,   894,    21,   895,
     896,    85,    86,   897,   983,   898,   899,    87,    88,    89,
     900,    22,   901,   344,   902,    90,    91,    92,   903,   904,
      23,   905,   906,   907,    24,   936,   937,   938,   908,   939,
     940,   932,   941,   942,   958,   943,   959,   944,   960,   961,
     945,    93,    94,   946,   947,   948,   984,   949,   962,   963,
     964,   985,   950,   986,   988,   989,   951,   952,   953,   965,
    1186,  1187,  1188,   991,  1189,  1190,   954,  1191,  1192,   966,
    1193,   955,  1194,   992,   994,  1195,  1000,  1001,  1196,  1197,
    1198,   967,  1199,   968,   969,   970,   971,  1200,   972,   973,
     974,  1201,  1202,  1203,   975,   976,   977,   978,   987,   990,
     997,  1204,   998,   910,   911,   912,  1205,   913,   914,   999,
     915,   916,  1002,   917,  1003,   918,  1004,  1005,   919,  1006,
    1007,   920,   921,   922,  1008,   923,  1009,  1010,  1011,  1012,
     924,  1013,  1014,  1015,   925,   926,   927,  1016,  1017,  1018,
    1019,  1020,  1021,  1022,   928,  1023,  1024,  1025,  1026,   929,
    1045,  1027,  1028,  1029,  1030,  1059,  1031,  1061,  1260,  1272,
    1032,  1033,  1034,  1035,   572,  1036,  1037,  1212,  1038,  1283,
    1043,  1044,  1284,  1047,  1048,  1046,  1058,  1285,  1060,  1062,
    1213,  1228,  1070,  1071,  1072,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,   310,  1085,  1086,  1092,  1093,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,  1105,  1106,  1107,  1108,  1109,
    1110,  1111,  1112,  1113,  1114,  1115,  1120,  1121,   745,  1134,
    1135,  1136,  1137,  1306,  1148,  1138,  1139,  1140,  1232,  1141,
     758,  1142,  1287,  1286,   636,  1151,  1149,  1279,  1152,  1153,
    1154,   726,  1178,  1179,  1180,  1181,  1182,  1208,  1209,  1210,
    1211,  1214,  1227,  1282,  1281,  1233,  1229,  1246,  1262,   764,
     737,  1263,  1303,   802,  1276,  1264,  1289,  1265,  1275,  1290,
     503,  1291,   813,  1261,  1288,   653,  1280,   730,   657,   403,
     663,   461,   327,  1254,  1255,   552,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     583,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   587
};

static const yytype_int16 yycheck[] =
{
     633,   634,   315,     8,   317,     1,   319,   320,   234,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,    49,
     234,     1,     1,     1,     1,     1,     1,     9,    10,    11,
     234,     1,     1,     1,     1,     1,     1,   232,    29,   232,
      25,   236,   234,   236,    53,    25,    37,    32,   234,   113,
     232,    35,    32,   232,   236,     1,   232,   236,    49,    50,
     236,     1,   234,    54,    55,    56,     6,     7,   215,    35,
      58,   218,    12,    65,   232,    65,   232,    65,   236,    67,
      20,    21,    65,   234,     1,   234,    65,    27,    79,     1,
      30,    31,   232,   233,   232,    81,    36,    81,   236,   412,
     413,    41,    42,    81,    44,    45,    46,   420,    48,   234,
       1,   424,     1,   100,   103,    81,   429,    57,   103,   432,
     129,    61,    62,   103,   100,   215,   103,   234,   218,   442,
     443,   113,    72,   103,   103,   103,   234,   124,     1,   127,
     453,   234,    82,   456,   457,   209,   130,   130,   124,   234,
      90,   130,    92,   130,    94,   234,    96,   103,    98,    99,
     190,   130,    25,   130,   130,   130,  1087,  1088,  1089,     1,
     200,   111,   204,   205,   234,   234,   116,   117,   118,   175,
     120,   121,   122,    15,    16,   125,   103,    19,   232,   175,
     232,   103,   236,   234,   236,   200,    59,   175,   232,   232,
     175,   232,   236,   236,   232,    68,   232,   234,   236,   234,
     236,   151,   103,   234,   103,   179,   180,   234,   232,   159,
     160,   161,   162,   163,   164,   235,   196,   235,    91,   235,
     226,   235,    95,   235,   223,    67,   235,   550,   227,   232,
     103,   233,   233,   106,   107,   233,   233,   233,   233,   233,
     233,   226,   192,   223,    86,    87,    88,    89,   233,   175,
     227,    93,   227,   233,   233,    97,   233,   204,   205,   128,
     113,   103,   235,   235,   235,   138,   216,   217,   235,   219,
     220,   221,   114,   115,   196,   225,   235,   233,   235,   128,
     230,     1,   155,   233,   126,   158,   235,   235,     1,   235,
       1,     1,   235,     3,   235,     5,   223,    17,   621,   235,
     235,   223,   625,   235,    17,   628,   148,    17,   113,   632,
     183,    22,    23,    33,     1,   235,   235,    28,   235,   235,
      33,   235,   223,    33,   223,   235,   227,   235,   201,   202,
     203,   235,   233,   235,   233,   140,   141,   142,   143,   144,
     145,   146,   235,   235,   235,   187,   235,    67,    58,   235,
      60,   235,    63,    64,    67,   228,   229,    67,    69,    70,
     233,   235,   232,   235,    75,    76,    77,   235,    78,   235,
     235,    58,    83,    84,    85,   235,   235,   235,    65,   235,
      67,   821,   822,   823,   824,   825,   826,   827,   235,   235,
     103,   233,   235,   103,   235,   235,   235,   235,   109,   110,
       1,   235,     1,   123,     3,   235,     5,   235,   235,   235,
     123,   131,   132,   235,   235,     1,   235,   127,    17,   235,
     235,   235,   235,   235,   235,   235,   139,   235,    29,   235,
     128,    17,   152,   235,    33,   235,    37,   147,   235,   235,
     127,   235,   235,   156,   157,     1,   156,    33,    49,    50,
       6,     7,   235,    54,    55,    56,    12,   235,   235,    58,
     235,    60,   235,   235,    20,    21,   235,     1,    67,   235,
     235,    27,   235,   235,    30,    31,   235,   235,    79,    78,
      36,    67,   235,    17,    73,    41,    42,   235,    44,    45,
      46,   201,    48,   206,   235,   235,   235,   235,   235,    33,
     235,    57,   113,   215,   103,    61,    62,   227,   113,   113,
     113,   113,   215,   233,   227,   113,    72,   103,   228,   113,
     233,     1,   233,   233,   215,   113,    82,   232,   127,   235,
     232,   235,   128,    67,    90,   235,    92,   123,    94,   235,
      96,   235,    98,    99,   232,    25,    73,   136,   147,   235,
     235,   235,   235,   139,   235,   111,   235,   156,   235,   235,
     116,   117,   118,   235,   120,   121,   122,   235,   235,   125,
     156,   157,   235,   235,   235,   235,   165,     4,   235,    59,
     235,   235,   235,   172,   235,   235,  1229,   235,    68,   123,
     235,    18,   181,   235,   235,   151,   232,   131,   132,    26,
      40,   235,   201,   159,   160,   161,   162,   163,   164,   136,
     235,    91,   113,    40,   113,    95,   128,   113,   152,   208,
     206,   210,   211,   103,   215,   215,   106,   107,   215,   228,
     215,    71,   215,    73,   113,   224,   192,   113,   165,   215,
     215,   227,   231,   215,    71,   172,    73,   113,   113,   113,
     113,   113,   113,   215,   181,   235,   215,   235,   138,   128,
     216,   217,   215,   219,   220,   221,   215,   215,   215,   225,
     215,   215,   215,   100,   230,   155,   215,    13,   158,   119,
     215,   208,   215,   210,   211,   215,   232,   128,   113,   128,
     232,   128,   128,   227,   235,   235,   136,   224,    34,   235,
     232,   232,   215,   183,   231,   128,   133,    43,   135,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   232,   235,
     235,   201,   202,   203,   232,   235,   235,   154,   235,   235,
     235,   171,   172,   235,   232,   235,   113,     1,    74,     0,
       1,   235,   235,     4,   235,   172,   235,   215,   228,   229,
     177,    15,    16,    14,   181,    19,    17,    18,   215,   186,
     215,   215,   189,    24,   215,   232,   215,   194,   104,   105,
     128,   128,   128,   128,    35,   128,   112,    38,    39,   128,
     113,   208,   128,   128,   211,   128,   213,   227,   232,   232,
     235,   231,   234,   215,   232,   113,   128,   224,   232,   232,
     235,   137,   232,    67,   231,    66,   235,   113,   232,   235,
      71,   232,   232,   232,   232,   232,   232,   153,    49,    80,
      51,    52,    86,    87,    88,    89,   232,   232,   232,    93,
     232,   232,   232,    97,   232,   232,   232,   232,   113,   103,
     101,   102,   113,     1,   113,   113,   128,   113,   113,   232,
     114,   115,   128,    49,   113,    51,    52,   235,   119,   113,
     232,   128,   126,   215,    22,    23,   128,   232,   128,   232,
      28,   128,   128,   128,   235,   136,   128,   128,   214,   128,
     128,   128,   128,   128,   148,   232,   128,   235,   149,   150,
     232,   232,   232,   232,   232,   232,    49,   232,   232,   128,
     215,   232,   232,   232,   232,    63,    64,   232,   169,   232,
     232,    69,    70,   232,   113,   232,   232,    75,    76,    77,
     232,   182,   232,   187,   232,    83,    84,    85,   232,   232,
     191,   232,   232,   232,   195,   166,   167,   168,   232,   170,
     171,   232,   173,   174,   232,   176,   232,   178,   232,   232,
     181,   109,   110,   184,   185,   186,   128,   188,   232,   232,
     232,   128,   193,   128,   128,   128,   197,   198,   199,   232,
     166,   167,   168,   128,   170,   171,   207,   173,   174,   232,
     176,   212,   178,   128,   113,   181,   128,   128,   184,   185,
     186,   232,   188,   232,   232,   232,   232,   193,   232,   232,
     232,   197,   198,   199,   232,   232,   232,   232,   232,   232,
     232,   207,   232,   166,   167,   168,   212,   170,   171,   232,
     173,   174,   232,   176,   128,   178,   215,   235,   181,   128,
     128,   184,   185,   186,   128,   188,   128,   215,   235,   128,
     193,   232,   128,   128,   197,   198,   199,   128,   232,   232,
     232,   232,   232,   232,   207,   232,   232,   232,   232,   212,
     128,   232,   232,   232,   232,   128,   232,   128,   113,   128,
     232,   232,   232,   232,   272,   232,   232,  1040,   232,   134,
     232,   232,   134,   232,   232,   235,   232,   134,   235,   232,
    1042,   235,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,    74,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   507,   232,
     232,   232,   232,  1305,   222,   232,   232,   232,  1053,   232,
     522,   232,  1269,  1267,   345,   232,   236,  1248,   232,   232,
     232,   471,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,  1259,  1257,   232,   235,   232,   232,   538,
     494,   237,  1278,   576,   232,   237,   232,   237,   235,   232,
     228,   232,   592,  1149,  1271,   378,  1253,   484,   397,   117,
     407,   171,    95,  1117,  1119,   244,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   301
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   239,     0,     1,     4,    14,    17,    18,    24,    35,
      38,    39,    66,    71,    80,   101,   102,   119,   136,   149,
     150,   169,   182,   191,   195,   240,   245,   250,   274,   280,
     286,   300,   320,   343,   357,   372,   379,   383,   393,   402,
     423,   429,   435,   439,   445,   503,   521,   232,   233,   234,
     234,   321,   403,   430,   234,   440,   234,   358,   424,   344,
     234,   281,   301,   373,   234,   234,   394,   234,   234,   384,
       1,    25,    32,   103,   275,   276,   277,   278,   279,     1,
      22,    23,    28,    63,    64,    69,    70,    75,    76,    77,
      83,    84,    85,   109,   110,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   234,   234,   234,     1,    65,   436,   437,   438,
     234,     1,     6,     7,    12,    20,    21,    27,    30,    31,
      36,    41,    42,    44,    45,    46,    48,    57,    61,    62,
      72,    82,    90,    92,    94,    96,    98,    99,   111,   116,
     117,   118,   120,   121,   122,   125,   151,   159,   160,   161,
     162,   163,   164,   192,   216,   217,   219,   220,   221,   225,
     230,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   496,   500,
     501,   502,   234,   234,   234,     1,   100,   124,   246,   247,
     248,   249,   234,   234,   234,     1,    29,    37,    49,    50,
      54,    55,    56,    79,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,     1,    25,    59,    68,    91,    95,
     103,   106,   107,   138,   155,   158,   183,   201,   202,   203,
     228,   229,   251,   252,   253,   254,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   234,     1,   226,   287,   288,   289,   290,   291,     1,
     103,   380,   381,   382,   234,   232,   235,   235,   235,   233,
     276,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   233,   505,     1,    15,
      16,    19,    67,    86,    87,    88,    89,    93,    97,   103,
     114,   115,   126,   148,   187,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,     1,     3,     5,    17,    33,    58,    60,
      67,    78,   103,   127,   147,   156,   201,   228,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   418,
     419,   420,   421,   422,     1,    65,   130,   431,   432,   433,
     434,   235,   233,   437,     1,   103,   130,   441,   442,   443,
     444,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   497,   235,
     493,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     233,   447,     1,    17,    33,    67,   123,   131,   132,   152,
     227,   359,   360,   361,   362,   363,   364,   365,   369,   370,
     371,     1,   130,   227,   425,   426,   427,   428,     1,    58,
      65,    67,   127,   345,   349,   350,   351,   355,   356,   232,
     235,   235,   233,   247,     1,    81,   175,   282,   283,   284,
     285,     1,    17,    33,    67,   103,   123,   139,   156,   157,
     206,   227,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   316,     1,    35,    81,   130,   374,   375,
     376,   377,   378,   235,   235,   235,   235,   235,   235,   235,
     235,   233,   523,   232,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   233,   252,     1,   103,   223,   395,   396,   397,   398,
     232,   235,   233,   288,   175,   235,   233,   381,     1,   103,
     223,   227,   385,   386,   387,   388,   389,   128,   128,   128,
     232,   113,   113,   215,   113,   113,   242,   113,   242,   113,
     242,   242,   113,   113,   113,   215,   215,   232,   232,   235,
     235,   235,   340,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   233,   323,   232,   235,   235,
     235,   235,   235,   235,   415,   235,   235,   235,   235,   235,
     235,   235,   233,   405,   235,   235,   233,   432,   128,   232,
     235,   235,   233,   442,   215,   242,   242,   215,   113,   215,
     113,   128,   215,   242,   215,   113,   113,   242,   113,   215,
     215,   215,   242,   113,   113,   242,   113,   113,   113,   113,
     215,   235,   215,   235,   215,   242,   242,   215,   215,   215,
     215,   218,   215,   218,   215,   215,   215,   128,   242,   215,
     215,   242,   242,   215,   215,   232,   232,   235,   235,   366,
     235,   235,   235,   235,   235,   233,   360,   235,   235,   233,
     426,   232,   235,   235,   346,   235,   233,   350,   128,   128,
     232,   232,   235,   235,   233,   283,   232,   235,   235,   317,
     235,   235,   235,   235,   235,   313,   235,   233,   303,   232,
     235,   235,   235,   233,   375,   215,   215,   215,   128,   215,
     215,   215,   242,   232,   128,   215,   128,   113,   113,   128,
     128,   128,   128,   128,   128,   113,   128,   204,   205,   255,
     256,   204,   205,   257,   258,   128,   128,   232,   232,   235,
     399,   233,   396,   215,   232,   234,   128,   232,   232,   235,
     390,   235,   233,   386,   232,   232,   232,   232,   232,   232,
     232,   140,   141,   142,   143,   144,   145,   146,   241,   242,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   113,   113,   242,   235,   113,   113,   242,   113,   113,
     242,   128,   113,   113,   242,   113,   244,   244,   232,   128,
     179,   180,   128,   215,   128,   128,   235,   128,   128,   113,
     128,   128,   128,   128,   232,   128,   128,   232,   232,   128,
     128,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,    49,
     166,   167,   168,   170,   171,   173,   174,   176,   178,   181,
     184,   185,   186,   188,   193,   197,   198,   199,   207,   212,
     498,   499,   232,    49,    51,    52,   166,   167,   168,   170,
     171,   173,   174,   176,   178,   181,   184,   185,   186,   188,
     193,   197,   198,   199,   207,   212,   494,   495,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   128,
     215,   235,   128,   113,   128,   128,   128,   232,   128,   128,
     232,   128,   128,   235,   113,   353,   354,   232,   232,   232,
     128,   128,   232,   128,   215,   235,   128,   128,   128,   128,
     215,   235,   128,   232,   128,   128,   128,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     236,   232,   236,   232,   232,   128,   235,   232,   232,     1,
     103,   196,   223,   292,   293,   294,   295,   296,   232,   128,
     235,   128,   232,   241,   241,   241,   241,   241,   241,   241,
     232,   232,   232,    53,   129,   341,   342,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,     9,    10,    11,
     243,   244,   232,   232,   232,   232,   232,   232,   232,   232,
     232,     8,   200,   416,   417,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   236,   232,   236,
     232,   232,    13,    34,    43,    74,   104,   105,   112,   137,
     153,   214,   367,   368,   232,   232,   232,   232,   232,   232,
     232,   232,   232,    49,   190,   200,   347,   348,   222,   236,
     352,   232,   232,   232,   232,     4,    18,    26,    40,    71,
      73,   100,   133,   135,   154,   172,   177,   181,   186,   189,
     194,   208,   211,   213,   224,   231,   318,   319,   232,   232,
     232,   232,   232,    49,    51,    52,   166,   167,   168,   170,
     171,   173,   174,   176,   178,   181,   184,   185,   186,   188,
     193,   197,   198,   199,   207,   212,   314,   315,   232,   232,
     232,   232,   256,   258,   232,    73,   136,   165,   172,   181,
     208,   210,   211,   224,   231,   400,   401,   232,   235,   235,
     297,   233,   293,   232,    73,   136,   165,   172,   181,   208,
     210,   211,   224,   231,   391,   392,   232,   232,   236,   243,
     243,   243,   232,   236,   499,   495,   232,   236,   232,   236,
     113,   354,   232,   237,   237,   237,   232,   236,   232,   236,
     232,   236,   128,   209,   244,   235,   232,   232,   236,   342,
     417,   368,   348,   134,   134,   134,   319,   315,   401,   232,
     232,   232,    40,    71,    73,   119,   136,   171,   172,   227,
     231,   298,   299,   392,   232,   236,   299
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
     252,   252,   253,   254,   255,   255,   256,   256,   257,   257,
     258,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   275,
     276,   276,   276,   276,   277,   278,   279,   281,   280,   282,
     282,   283,   283,   283,   284,   285,   286,   287,   287,   288,
     288,   288,   289,   291,   290,   292,   292,   293,   293,   293,
     293,   294,   295,   295,   297,   296,   298,   298,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   301,   300,   302,
     302,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     313,   312,   314,   314,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   317,   316,   318,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   321,   320,   322,   322,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   340,   339,   341,   341,   342,   342,   344,   343,   346,
     345,   347,   347,   348,   348,   348,   349,   349,   350,   350,
     350,   350,   350,   352,   351,   353,   353,   354,   354,   355,
     356,   358,   357,   359,   359,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   361,   362,   363,   364,   366,   365,
     367,   367,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   369,   370,   371,   373,   372,   374,   374,   375,
     375,   375,   375,   376,   377,   378,   379,   380,   380,   381,
     381,   382,   384,   383,   385,   385,   386,   386,   386,   386,
     387,   388,   390,   389,   391,   391,   392,   392,   392,   392,
     392,   392,   392,   392,   392,   392,   394,   393,   395,   395,
     396,   396,   396,   397,   399,   398,   400,   400,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   403,   402,
     404,   404,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   413,   415,   414,   416,   416,
     417,   417,   418,   419,   420,   421,   422,   424,   423,   425,
     425,   426,   426,   426,   427,   428,   430,   429,   431,   431,
     432,   432,   432,   433,   434,   435,   436,   436,   437,   437,
     438,   440,   439,   441,   441,   442,   442,   442,   443,   444,
     445,   446,   446,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     474,   475,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   493,
     492,   494,   494,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   497,   496,   498,   498,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   500,   501,   502,   503,   504,   504,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     522,   523,   523,   523,   523,   523,   523,   523,   523,   523,
     524,   525,   526,   527,   528,   529,   530,   531
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
       1,     2,     4,     4,     3,     1,     1,     1,     3,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     2,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     2,     4,     4,     5,     2,     1,     1,
       1,     2,     4,     0,     6,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     0,     6,     0,
       5,     3,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     0,     5,     3,     1,     1,     3,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     5,     2,     1,     1,
       1,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     2,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     4,     4,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     2,     1,     1,     1,     1,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
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
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 440 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 480 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 486 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2977 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 495 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2988 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 501 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 509 "conf_parser.y" /* yacc.c:1646  */
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
#line 3044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 551 "conf_parser.y" /* yacc.c:1646  */
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
#line 3105 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 609 "conf_parser.y" /* yacc.c:1646  */
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
#line 3136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 637 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 645 "conf_parser.y" /* yacc.c:1646  */
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
#line 3165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 660 "conf_parser.y" /* yacc.c:1646  */
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
#line 3183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 675 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
#line 3195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 684 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')))
      p = '\0';

    MyFree(ServerInfo.network_name);
    ServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 698 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 707 "conf_parser.y" /* yacc.c:1646  */
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
#line 3255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 735 "conf_parser.y" /* yacc.c:1646  */
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
#line 3288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 765 "conf_parser.y" /* yacc.c:1646  */
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
#line 3316 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 790 "conf_parser.y" /* yacc.c:1646  */
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
#line 3341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 812 "conf_parser.y" /* yacc.c:1646  */
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
#line 3366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 860 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 869 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3411 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 881 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 885 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
    motd_add(ptr->data, block_state.file.buf);
}
#line 3437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 902 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 908 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 923 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 929 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 933 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 949 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 957 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 960 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3513 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 965 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3522 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 972 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 976 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3540 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 980 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3549 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 984 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 988 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 996 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3594 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1004 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3603 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1021 "conf_parser.y" /* yacc.c:1646  */
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
#line 3691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3700 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1113 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3718 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1125 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1136 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1142 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3750 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1148 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1159 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1165 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1172 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1176 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1180 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1184 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1188 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1196 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1208 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1216 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1224 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1228 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
#line 3917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1252 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3971 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3980 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1260 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1266 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
#line 4061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
#line 4160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1345 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1349 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4187 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1361 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1365 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1375 "conf_parser.y" /* yacc.c:1646  */
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
#line 4231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1387 "conf_parser.y" /* yacc.c:1646  */
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
#line 4283 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1454 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4292 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1460 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1466 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1472 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1478 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1484 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4337 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1490 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4346 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1496 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4355 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1502 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1508 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1515 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1521 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1527 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1533 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1542 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1551 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1558 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1562 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1572 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1578 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1584 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1588 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1592 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1600 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1605 "conf_parser.y" /* yacc.c:1646  */
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
#line 4521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1619 "conf_parser.y" /* yacc.c:1646  */
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
#line 4542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1637 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4551 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1643 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1652 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1656 "conf_parser.y" /* yacc.c:1646  */
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
#line 4610 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1705 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1711 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4628 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1717 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4637 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1723 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1734 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4660 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1741 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4669 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1745 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4678 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1749 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4687 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1753 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4696 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1757 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1761 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1765 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1769 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1773 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1777 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4750 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1783 "conf_parser.y" /* yacc.c:1646  */
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
#line 4767 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1797 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4779 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1806 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1819 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4803 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1826 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1837 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1849 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1864 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1879 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1890 "conf_parser.y" /* yacc.c:1646  */
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
#line 4889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1907 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1913 "conf_parser.y" /* yacc.c:1646  */
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
#line 4920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1932 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1943 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1951 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1955 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1963 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1967 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1971 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5010 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1975 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5019 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1984 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5033 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1993 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2008 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2066 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2075 "conf_parser.y" /* yacc.c:1646  */
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
#line 5236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2155 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2161 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2167 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2173 "conf_parser.y" /* yacc.c:1646  */
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
#line 5279 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2186 "conf_parser.y" /* yacc.c:1646  */
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
#line 5295 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2199 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2205 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5313 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2211 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5322 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2215 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2223 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2239 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2250 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2268 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2283 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2287 "conf_parser.y" /* yacc.c:1646  */
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
#line 5448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2312 "conf_parser.y" /* yacc.c:1646  */
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
#line 5471 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2345 "conf_parser.y" /* yacc.c:1646  */
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
#line 5515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2371 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5524 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2377 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2391 "conf_parser.y" /* yacc.c:1646  */
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
#line 5550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2408 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2412 "conf_parser.y" /* yacc.c:1646  */
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
#line 5581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2434 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5590 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2440 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5599 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2505 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2510 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2516 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2522 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2528 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2534 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2539 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2544 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2549 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2554 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5683 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2559 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2564 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5699 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2569 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5707 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2574 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number);
}
#line 5715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2579 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2584 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5731 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2589 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5739 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2594 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2599 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5756 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2605 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5770 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2616 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5778 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2621 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_connect_block = yylval.number;
}
#line 5786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2626 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2631 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2636 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2641 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2646 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5826 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2649 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5834 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2654 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5842 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2657 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2662 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2667 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2672 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2677 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2682 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2687 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2692 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2697 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5914 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2702 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2707 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2712 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.use_egd = yylval.number;
}
#line 5938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2717 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
#line 5950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2726 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 5962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2735 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 5970 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2740 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 5978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2745 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = (yyvsp[-1].number);
}
#line 5986 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2750 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 5994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2756 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 6002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2759 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 6010 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 6018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2765 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 6026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2768 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 6034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2771 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 6042 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2774 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDECHANS;
}
#line 6050 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6058 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 6066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2783 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6082 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2789 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6090 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2798 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
#line 6114 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6122 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6130 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6154 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6162 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2827 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2833 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6194 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2836 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6202 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2839 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2845 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6226 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6234 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2851 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6242 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2854 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6250 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2860 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6266 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6274 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6282 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2869 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
#line 6290 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6298 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6306 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2878 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6314 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6322 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2884 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6330 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6346 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2893 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6354 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2898 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6362 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2903 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6370 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2908 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2938 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6386 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2944 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6394 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2949 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2954 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2959 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2964 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
#line 6434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[-1].number);
}
#line 6442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 2979 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 2984 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6458 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2989 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6466 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2994 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 2999 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 3004 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6490 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 3009 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3031 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6516 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3043 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6525 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6534 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3064 "conf_parser.y" /* yacc.c:1646  */
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
#line 6563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 666:
#line 3078 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 667:
#line 3084 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6581 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6585 "conf_parser.c" /* yacc.c:1646  */
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
