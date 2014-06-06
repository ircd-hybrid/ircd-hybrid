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
#define YYLAST   1260

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  238
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  295
/* YYNRULES -- Number of rules.  */
#define YYNRULES  665
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1308

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
    1235,  1239,  1243,  1247,  1251,  1255,  1262,  1261,  1267,  1267,
    1268,  1272,  1276,  1280,  1284,  1288,  1292,  1296,  1300,  1304,
    1308,  1312,  1316,  1320,  1324,  1328,  1332,  1336,  1340,  1344,
    1348,  1352,  1356,  1367,  1366,  1427,  1427,  1428,  1429,  1430,
    1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1439,
    1440,  1441,  1442,  1443,  1445,  1451,  1457,  1463,  1469,  1475,
    1481,  1487,  1493,  1499,  1506,  1512,  1518,  1524,  1533,  1543,
    1542,  1548,  1548,  1549,  1553,  1564,  1563,  1570,  1569,  1574,
    1574,  1575,  1579,  1583,  1589,  1589,  1590,  1590,  1590,  1590,
    1590,  1592,  1592,  1594,  1594,  1596,  1610,  1628,  1634,  1644,
    1643,  1685,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,  1696,  1702,  1708,  1714,  1726,  1725,  1731,  1731,
    1732,  1736,  1740,  1744,  1748,  1752,  1756,  1760,  1764,  1768,
    1774,  1788,  1797,  1811,  1810,  1825,  1825,  1826,  1826,  1826,
    1826,  1828,  1834,  1840,  1850,  1852,  1852,  1853,  1853,  1855,
    1871,  1870,  1895,  1895,  1896,  1896,  1896,  1896,  1898,  1904,
    1924,  1923,  1929,  1929,  1930,  1934,  1938,  1942,  1946,  1950,
    1954,  1958,  1962,  1966,  1976,  1975,  1996,  1996,  1997,  1997,
    1997,  1999,  2006,  2005,  2011,  2011,  2012,  2016,  2020,  2024,
    2028,  2032,  2036,  2040,  2044,  2048,  2058,  2057,  2129,  2129,
    2130,  2131,  2132,  2133,  2134,  2135,  2136,  2137,  2138,  2139,
    2140,  2141,  2142,  2143,  2144,  2146,  2152,  2158,  2164,  2177,
    2190,  2196,  2202,  2206,  2215,  2214,  2219,  2219,  2220,  2224,
    2230,  2241,  2247,  2253,  2259,  2275,  2274,  2300,  2300,  2301,
    2301,  2301,  2303,  2323,  2333,  2332,  2359,  2359,  2360,  2360,
    2360,  2362,  2368,  2377,  2379,  2379,  2380,  2380,  2382,  2400,
    2399,  2422,  2422,  2423,  2423,  2423,  2425,  2431,  2440,  2443,
    2443,  2444,  2445,  2446,  2447,  2448,  2449,  2450,  2451,  2452,
    2453,  2454,  2455,  2456,  2457,  2458,  2459,  2460,  2461,  2462,
    2463,  2464,  2465,  2466,  2467,  2468,  2469,  2470,  2471,  2472,
    2473,  2474,  2475,  2476,  2477,  2478,  2479,  2480,  2481,  2482,
    2483,  2484,  2485,  2486,  2487,  2488,  2489,  2490,  2491,  2492,
    2493,  2494,  2497,  2502,  2508,  2514,  2520,  2526,  2531,  2536,
    2541,  2546,  2551,  2556,  2561,  2566,  2571,  2576,  2581,  2586,
    2591,  2597,  2608,  2613,  2618,  2623,  2628,  2633,  2638,  2641,
    2646,  2649,  2654,  2659,  2664,  2669,  2674,  2679,  2684,  2689,
    2694,  2699,  2704,  2709,  2718,  2727,  2732,  2737,  2742,  2748,
    2747,  2752,  2752,  2753,  2756,  2759,  2762,  2765,  2768,  2771,
    2774,  2777,  2780,  2783,  2786,  2789,  2792,  2795,  2798,  2801,
    2804,  2807,  2810,  2813,  2816,  2822,  2821,  2826,  2826,  2827,
    2830,  2833,  2836,  2839,  2842,  2845,  2848,  2851,  2854,  2857,
    2860,  2863,  2866,  2869,  2872,  2875,  2878,  2881,  2884,  2889,
    2894,  2899,  2908,  2911,  2911,  2912,  2913,  2914,  2915,  2916,
    2917,  2918,  2919,  2920,  2921,  2922,  2923,  2924,  2925,  2926,
    2927,  2929,  2935,  2940,  2945,  2950,  2955,  2960,  2965,  2970,
    2975,  2980,  2985,  2990,  2995,  3000,  3008,  3011,  3011,  3012,
    3013,  3014,  3015,  3016,  3017,  3018,  3019,  3020,  3022,  3028,
    3034,  3040,  3046,  3055,  3069,  3075
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
  "general_ping_cookie", "general_disable_auth", "general_throttle_count",
  "general_throttle_time", "general_oper_umodes", "$@24", "umode_oitems",
  "umode_oitem", "general_oper_only_umodes", "$@25", "umode_items",
  "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_chans_per_user", "channel_max_chans_per_oper",
  "channel_max_bans", "channel_default_split_user_count",
  "channel_default_split_server_count", "channel_no_create_on_split",
  "channel_no_join_on_split", "channel_jflood_count",
  "channel_jflood_time", "serverhide_entry", "serverhide_items",
  "serverhide_item", "serverhide_flatten_links",
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

#define YYPACT_NINF -734

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-734)))

#define YYTABLE_NINF -124

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -734,   658,  -734,   -63,  -225,  -211,  -734,  -734,  -734,  -202,
    -734,  -196,  -734,  -734,  -734,  -194,  -734,  -734,  -734,  -174,
    -169,  -734,  -154,  -146,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,   322,
     943,  -144,  -138,  -122,    27,  -112,   427,   -96,   -80,   -62,
      25,   -28,   -25,   -18,   386,   478,    -8,   108,    12,     5,
    -197,  -190,  -185,   -51,    11,  -734,  -734,  -734,  -734,  -734,
       1,    35,    38,    42,    44,    47,    54,    57,    73,    90,
     100,   106,   113,   116,   118,   104,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,   702,   335,    26,  -734,   126,    19,  -734,  -734,
      48,  -734,   128,   134,   136,   140,   141,   142,   145,   146,
     149,   150,   151,   154,   155,   157,   159,   162,   163,   165,
     166,   168,   171,   172,   173,   174,   175,   177,   179,  -734,
     183,  -734,   184,   186,   191,   192,   194,   195,   202,   208,
     209,   210,   211,   217,   220,   221,   225,   231,   232,   235,
     241,   242,    41,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,   355,     4,   297,    55,   246,   250,
      53,  -734,  -734,  -734,    23,   293,   182,  -734,   255,   258,
     259,   260,   261,   265,   267,   269,     2,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,    71,   270,   271,   273,
     283,   289,   292,   294,   295,   298,   299,   304,   305,   306,
     307,   316,   318,   319,   117,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,     7,   111,   320,    21,  -734,  -734,  -734,
     164,  -734,   321,    43,  -734,  -734,    72,  -734,   277,   333,
     400,   185,  -734,   419,   444,   345,   447,   448,   451,   448,
     452,   448,   448,   453,   454,   455,   356,   357,   342,  -734,
     343,   341,   344,   348,  -734,   361,   362,   363,   364,   366,
     367,   369,   378,   379,   380,   382,   384,   218,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,   388,   387,   389,   392,   394,
     395,   396,  -734,   399,   402,   403,   404,   405,   410,   414,
     264,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,   415,   416,    13,
    -734,  -734,  -734,   449,   391,  -734,  -734,   418,   420,    17,
    -734,  -734,  -734,   407,   448,   448,   421,   467,   440,   543,
     535,   446,   448,   450,   553,   556,   448,   557,   457,   459,
     463,   448,   568,   570,   448,   572,   574,   576,   577,   480,
     433,   481,   464,   484,   448,   448,   486,   491,   494,  -189,
    -184,   496,   497,   498,   564,   589,   448,   500,   501,   448,
     448,   502,   505,   490,  -734,   499,   493,   495,  -734,   506,
     513,   514,   515,   517,   247,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,   518,   519,    63,  -734,  -734,
    -734,   503,   520,   522,  -734,   523,  -734,     9,  -734,  -734,
    -734,  -734,  -734,   595,   604,   504,  -734,   508,   526,   527,
      16,  -734,  -734,  -734,   533,   529,   531,  -734,   536,   537,
     538,   539,   540,  -734,   544,   226,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,   546,   549,   550,
     558,    20,  -734,  -734,  -734,  -734,   554,   567,   583,   605,
     588,   590,   592,   448,   571,  -734,  -734,   606,   596,   609,
     654,   657,   681,   683,   684,   685,   686,   687,   706,   695,
     124,   170,   698,   701,   598,  -734,   599,   601,  -734,    68,
    -734,  -734,  -734,  -734,   619,   602,  -734,   603,   710,   612,
    -734,   613,   608,  -734,   614,    18,  -734,  -734,  -734,  -734,
     621,   622,   623,  -734,   624,   625,   626,   627,   370,   631,
     634,   637,   639,   641,   642,   644,   645,   648,   650,   651,
    -734,  -734,   728,   734,   448,   616,   771,   772,   448,   774,
     776,   448,   765,   781,   782,   448,   784,   784,   664,  -734,
    -734,   770,    49,   773,   688,   775,   778,   669,   779,   780,
     786,   785,   790,   793,   796,   677,  -734,   798,   800,   678,
    -734,   679,  -734,   801,   803,   680,  -734,   682,   700,   703,
     705,   707,   708,   711,   716,   720,   726,   730,   731,   737,
     740,   741,   742,   744,   745,   746,   750,   751,   752,   753,
     754,   755,   756,   758,   783,   759,   694,   760,   761,   763,
     764,   766,   767,   768,   769,   777,   789,   791,   792,   797,
     799,   802,   804,   805,   806,   807,   808,   809,   810,  -734,
    -734,   814,   724,   762,   874,   890,   876,   877,   880,   811,
    -734,   882,   883,   812,  -734,  -734,   886,   887,   787,   903,
     813,  -734,   815,   816,  -734,  -734,   889,   897,   817,  -734,
    -734,   902,   818,   819,   905,   907,   918,   922,   837,   820,
     928,   825,  -734,  -734,   930,   931,   932,   829,  -734,   830,
     831,   832,   833,   834,   835,   836,   838,  -734,   839,   840,
     841,   842,   843,   844,   845,   846,   847,   848,   849,   850,
     851,  -734,  -734,  -199,  -734,  -734,  -734,  -173,  -734,   852,
     853,  -734,  -734,   941,   854,   855,  -734,   856,  -734,   107,
     858,  -734,  -734,   958,   857,   963,   861,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,   448,   448,   448,   448,   448,
     448,   448,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,   862,   863,   864,   -12,   865,
     866,   867,   868,   869,   870,   871,   872,   873,   875,    84,
     878,   879,  -734,   881,   884,   885,   888,   891,   892,   893,
       8,   894,   895,   896,   898,   899,   900,   901,  -734,   904,
     906,  -734,  -734,   908,   909,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -166,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -157,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,   910,   911,   488,   912,   913,   914,   915,   916,
    -734,   917,   919,  -734,   920,   921,   -34,   933,   923,  -734,
    -734,  -734,  -734,   924,   925,  -734,   926,   929,   532,   934,
     935,   936,   937,   938,   749,   939,  -734,   940,   942,   944,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,   124,  -734,   170,  -734,  -734,   945,   611,
    -734,  -734,   946,   927,   947,  -734,    45,  -734,  -734,  -734,
    -734,  -734,   948,   615,   949,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -108,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
     784,   784,   784,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,   -72,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
     783,  -734,   694,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,   -50,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,   -42,
    -734,   993,   903,   951,  -734,  -734,  -734,  -734,  -734,   950,
    -734,  -734,   952,  -734,  -734,  -734,  -734,   953,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,   -37,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,   -21,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,   -14,  -734,  -734,   980,
    -102,   956,   954,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,   -11,  -734,  -734,  -734,   -12,
    -734,  -734,  -734,  -734,     8,  -734,  -734,  -734,   488,  -734,
     -34,  -734,  -734,  -734,   975,   978,   981,  -734,   532,  -734,
     749,  -734,   611,   960,   961,   962,   555,  -734,  -734,   615,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,    52,  -734,  -734,  -734,   555,  -734
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   223,   386,   434,     0,
     449,     0,   289,   425,   265,     0,   107,   147,   323,     0,
       0,   364,     0,     0,   340,     3,    23,    11,     4,    24,
       5,     6,     8,     9,    10,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    21,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   102,   101,   630,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   614,   629,   616,   617,
     618,   619,   620,   621,   622,   615,   623,   624,   625,   626,
     627,   628,     0,     0,     0,   447,     0,     0,   445,   446,
       0,   511,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   585,
       0,   559,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   460,   508,   510,   502,   503,   504,   505,
     506,   501,   471,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   498,   472,   473,   507,   475,   480,   481,
     476,   478,   477,   491,   492,   479,   482,   483,   484,   485,
     474,   487,   488,   489,   509,   499,   500,   496,   497,   490,
     486,   494,   495,   493,     0,     0,     0,     0,     0,     0,
       0,    45,    46,    47,     0,     0,     0,   657,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   648,   649,   650,
     651,   652,   655,   653,   654,   656,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    68,    69,    67,    64,
      63,    70,    54,    66,    57,    58,    59,    55,    65,    60,
      61,    62,    56,     0,     0,     0,     0,   118,   119,   120,
       0,   338,     0,     0,   336,   337,     0,   103,     0,     0,
       0,     0,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
       0,     0,     0,     0,   259,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   227,
     230,   232,   233,   234,   235,   236,   237,   238,   239,   228,
     229,   231,   240,   241,   242,     0,     0,     0,     0,     0,
       0,     0,   414,     0,     0,     0,     0,     0,     0,     0,
       0,   389,   390,   391,   392,   393,   394,   395,   397,   396,
     399,   403,   400,   401,   402,   398,   440,     0,     0,     0,
     437,   438,   439,     0,     0,   444,   455,     0,     0,     0,
     452,   453,   454,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   459,     0,     0,     0,   306,     0,
       0,     0,     0,     0,     0,   292,   293,   294,   295,   300,
     296,   297,   298,   299,   431,     0,     0,     0,   428,   429,
     430,     0,     0,     0,   267,     0,   277,     0,   275,   276,
     278,   279,    48,     0,     0,     0,    44,     0,     0,     0,
       0,   110,   111,   112,     0,     0,     0,   196,     0,     0,
       0,     0,     0,   170,     0,     0,   150,   151,   152,   153,
     156,   157,   158,   159,   155,   154,   160,     0,     0,     0,
       0,     0,   326,   327,   328,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   647,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,     0,     0,   372,     0,
     367,   368,   369,   121,     0,     0,   117,     0,     0,     0,
     335,     0,     0,   350,     0,     0,   343,   344,   345,   346,
       0,     0,     0,    97,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     612,   243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
     404,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   388,     0,     0,     0,
     436,     0,   443,     0,     0,     0,   451,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   458,
     301,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,     0,     0,     0,   427,   280,     0,     0,     0,     0,
       0,   274,     0,     0,    43,   113,     0,     0,     0,   109,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,   330,     0,     0,     0,     0,   325,     0,
       0,     0,     0,     0,     0,     0,     0,   646,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,     0,    75,    80,    81,     0,    79,     0,
       0,    51,   370,     0,     0,     0,   366,     0,   116,     0,
       0,   334,   347,     0,     0,     0,     0,   342,   106,   105,
     104,   641,   640,   631,   632,    27,    27,    27,    27,    27,
      27,    27,    29,    28,   633,   644,   645,   634,   635,   636,
     639,   638,   637,   642,   643,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   387,     0,
       0,   435,   448,     0,     0,   450,   524,   528,   543,   513,
     611,   556,   550,   553,   523,   515,   514,   517,   518,   516,
     531,   521,   522,   532,   520,   527,   526,   525,   551,   512,
     609,   610,   547,   595,   589,   605,   590,   591,   592,   600,
     608,   593,   602,   606,   596,   607,   597,   601,   594,   604,
     599,   598,   603,     0,   588,   549,   568,   569,   570,   563,
     581,   564,   565,   566,   576,   584,   567,   578,   582,   572,
     583,   573,   577,   571,   580,   575,   574,   579,     0,   562,
     544,   542,   545,   555,   546,   534,   540,   541,   538,   539,
     535,   536,   537,   554,   557,   558,   519,   548,   530,   529,
     552,   533,     0,     0,     0,     0,     0,     0,     0,     0,
     290,     0,     0,   426,     0,     0,     0,   285,   281,   284,
     266,    49,    50,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
     324,   659,   658,   664,   662,   665,   660,   661,   663,    88,
      96,    87,    94,    95,    86,    90,    89,    83,    82,    84,
      93,    85,    72,     0,    73,     0,    91,    92,     0,     0,
     365,   122,     0,     0,     0,   134,     0,   126,   127,   129,
     128,   339,     0,     0,     0,   341,    30,    31,    32,    33,
      34,    35,    36,   254,   255,   247,   264,   263,     0,   262,
     249,   251,   258,   250,   248,   257,   244,   256,   246,   245,
      37,    37,    37,    39,    38,   252,   253,   409,   412,   413,
     423,   420,   406,   421,   418,   419,     0,   417,   422,   405,
     411,   408,   410,   424,   407,   441,   442,   456,   457,   586,
       0,   560,     0,   304,   305,   314,   311,   316,   312,   313,
     319,   315,   317,   310,   318,     0,   309,   303,   322,   321,
     320,   302,   433,   432,   288,   287,   272,   273,   271,     0,
     270,     0,     0,     0,   114,   115,   169,   165,   216,   203,
     213,   212,   201,   206,   222,   215,   220,   205,   208,   217,
     219,   214,   221,   209,   211,   218,   207,   210,     0,   199,
     162,   164,   166,   167,   168,   179,   180,   181,   174,   192,
     175,   176,   177,   187,   195,   178,   189,   193,   183,   194,
     184,   188,   182,   191,   186,   185,   190,     0,   173,   163,
     333,   331,   332,    74,    78,   371,   376,   382,   385,   378,
     384,   379,   383,   381,   377,   380,     0,   375,   130,     0,
       0,     0,     0,   125,   348,   354,   360,   363,   356,   362,
     357,   361,   359,   355,   358,     0,   353,   349,   260,     0,
      40,    41,    42,   415,     0,   587,   561,   307,     0,   268,
       0,   286,   283,   282,     0,     0,     0,   197,     0,   171,
       0,   373,     0,     0,     0,     0,     0,   124,   351,     0,
     261,   416,   308,   269,   202,   200,   204,   198,   172,   374,
     131,   133,   132,   140,   145,   144,   139,   142,   146,   143,
     138,   141,     0,   137,   352,   135,     0,   136
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -734,  -734,  -734,  -219,  -315,  -733,  -636,  -734,  -734,   955,
    -734,  -734,  -734,  -734,   860,  -734,  -734,  -734,    75,  -734,
      69,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  1045,  -734,
    -734,  -734,  -734,  -734,  -734,   629,  -734,  -734,  -734,  -734,
     826,  -734,  -734,  -734,  -734,    65,  -734,  -734,  -734,  -734,
    -734,  -177,  -734,  -734,  -734,   610,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -133,  -734,  -734,
    -734,  -118,  -734,  -734,  -734,   828,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,   -95,  -734,  -734,  -734,  -734,  -734,
    -100,  -734,   666,  -734,  -734,  -734,    32,  -734,  -734,  -734,
    -734,  -734,   690,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
     -93,  -734,  -734,  -734,  -734,  -734,  -734,   632,  -734,  -734,
    -734,  -734,  -734,   957,  -734,  -734,  -734,  -734,   584,  -734,
    -734,  -734,  -734,  -734,   -91,  -734,  -734,  -734,   617,  -734,
    -734,  -734,  -734,   -77,  -734,  -734,  -734,   821,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,   -57,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,   712,  -734,
    -734,  -734,  -734,  -734,   822,  -734,  -734,  -734,  -734,  1081,
    -734,  -734,  -734,  -734,   794,  -734,  -734,  -734,  -734,  1028,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,    80,  -734,
    -734,  -734,    85,  -734,  -734,  -734,  -734,  -734,  1109,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734,  -734,   964,  -734,  -734,  -734,
    -734,  -734,  -734,  -734,  -734
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   832,   833,  1093,  1094,    26,   230,   231,
     232,   233,    27,   274,   275,   276,   277,   793,   794,   797,
     798,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,    28,    74,    75,    76,
      77,    78,    29,    61,   510,   511,   512,   513,    30,   296,
     297,   298,   299,   300,  1056,  1057,  1058,  1059,  1060,  1231,
    1302,  1303,    31,    62,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   759,  1207,  1208,   536,   753,
    1178,  1179,    32,    51,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   625,  1078,  1079,    33,    59,   496,   738,  1149,
    1150,   497,   498,   499,  1153,   998,   999,   500,   501,    34,
      57,   474,   475,   476,   477,   478,   479,   480,   723,  1135,
    1136,   481,   482,   483,    35,    63,   541,   542,   543,   544,
     545,    36,   303,   304,   305,    37,    69,   595,   596,   597,
     598,   599,   814,  1245,  1246,    38,    66,   579,   580,   581,
     582,   804,  1226,  1227,    39,    52,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   647,  1106,  1107,
     391,   392,   393,   394,   395,    40,    58,   487,   488,   489,
     490,    41,    53,   399,   400,   401,   402,    42,   117,   118,
     119,    43,    55,   409,   410,   411,   412,    44,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   442,   958,   959,   220,
     440,   933,   934,   221,   222,   223,    45,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    46,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     860,   861,   609,   237,   611,   484,   613,   614,   576,    49,
     491,   859,    70,   301,   396,  1146,  1104,   507,   406,   591,
     115,   537,   294,    50,   507,   703,   227,   396,   115,   704,
     705,   238,    54,  1042,   706,   307,    71,  1043,    56,   239,
      60,  1076,   121,    72,   301,   308,  1052,   122,   123,   406,
     309,   240,   241,   124,   227,   538,   242,   243,   244,  1044,
      64,   125,   126,  1045,   484,    65,  1119,   492,   127,   576,
    1120,   128,   129,   591,   493,  1121,   494,   130,   397,  1122,
      67,   245,   131,   132,   116,   133,   134,   135,    68,   136,
     112,   397,   116,  1090,  1091,  1092,   113,   508,   137,   668,
     669,   539,   138,   139,   508,    79,  1274,   676,  1052,   294,
     577,   680,   114,   140,    73,   302,   685,  1077,   256,   688,
     407,   592,   120,   141,  1248,   228,    80,    81,  1249,   698,
     699,   142,    82,   143,   485,   144,   495,   145,   224,   146,
     147,   712,   257,   398,   715,   716,   302,   408,  1053,   229,
     540,   407,   148,   228,   225,  1147,   398,   149,   150,   151,
    1253,   152,   153,   154,  1254,  1148,   155,    83,    84,    47,
      48,   577,   226,    85,    86,   592,   258,   229,   408,    87,
      88,    89,  1257,   537,   310,   259,  1258,    90,    91,    92,
    1259,   509,   156,   485,  1260,  1267,  -123,   859,   509,  1268,
     157,   158,   159,   160,   161,   162,   234,  1105,   260,   235,
    1053,  1269,   261,    93,    94,  1270,   236,   538,  1271,   330,
     262,  1278,  1272,   263,   264,  1279,   293,   514,   864,   865,
     578,   486,   163,   331,   332,   554,   313,   333,   776,   306,
    1054,   593,   740,   515,   311,   594,   659,   295,   465,   748,
     665,   816,   404,   767,   585,   265,   164,   165,   166,   516,
     167,   168,   169,   539,   466,   365,   170,   366,  1055,   367,
     314,   171,   266,   315,   463,   267,   589,   316,  1232,   317,
     467,   368,   318,  -123,  1305,   334,   505,   502,  1306,   319,
     486,   578,   320,   517,   514,   593,   733,   369,   491,   594,
     268,   805,  1054,   556,   335,   336,   337,   338,   321,   847,
     515,   339,   540,   851,   468,   340,   854,   269,   270,   271,
     858,   341,   370,    70,   371,   322,   516,   791,   792,   518,
    1055,   372,   342,   343,   295,   323,   365,   328,   366,   587,
     367,   324,   373,   583,   344,   272,   273,    71,   325,   519,
     574,   326,   368,   327,    72,   492,   465,  1250,  1251,  1252,
     517,   403,   493,   413,   494,   520,   345,   374,   369,   414,
     469,   415,   466,   795,   796,   416,   417,   418,   470,   471,
     419,   420,   521,   522,   421,   422,   423,   237,   467,   424,
     425,   375,   426,   370,   427,   371,   518,   428,   429,   472,
     430,   431,   372,   432,   346,   600,   433,   434,   435,   436,
     437,   376,   438,   373,   439,   238,   519,   603,   441,   443,
     377,   444,   468,   239,   495,    73,   445,   446,   121,   447,
     448,   523,   520,   122,   123,   240,   241,   449,   374,   124,
     242,   243,   244,   450,   451,   452,   453,   125,   126,   521,
     522,   638,   454,   524,   127,   455,   456,   128,   129,   761,
     457,   601,   375,   130,   378,   245,   458,   459,   131,   132,
     460,   133,   134,   135,   473,   136,   461,   462,   469,   256,
     729,   503,   376,   608,   137,   504,   470,   471,   138,   139,
     546,   377,   379,   547,   548,   549,   550,   655,   523,   140,
     551,  1125,   552,   257,   553,   557,   558,   472,   559,   141,
     825,   826,   827,   828,   829,   830,   831,   142,   560,   143,
     524,   144,  1126,   145,   561,   146,   147,   562,   602,   563,
     564,  1127,   604,   565,   566,   378,  1158,   258,   148,   567,
     568,   569,   570,   149,   150,   151,   259,   152,   153,   154,
    1159,   571,   155,   572,   573,   584,   588,   605,  1160,   606,
     607,   608,  1128,   379,   610,   612,   615,   616,   617,   260,
     618,   619,  1161,   261,   620,   621,   622,   661,   156,   623,
     671,   262,   473,   624,   263,   264,   157,   158,   159,   160,
     161,   162,  1129,  1130,  1275,  1293,   626,   627,   628,   629,
    1131,   630,   631,  1162,   632,  1163,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,   633,   634,   635,   265,   636,   163,   637,
     640,   667,   641,   662,   642,  1132,  1294,   643,  1295,   644,
     645,   646,  1164,   266,   648,   670,   267,   649,   650,   651,
     652,  1133,   164,   165,   166,   653,   167,   168,   169,   654,
     657,   658,   170,   663,   672,   664,   673,   171,     2,     3,
     675,   268,     4,   674,   677,  1165,   678,  1166,   694,   679,
     681,   682,     5,   683,  1296,     6,     7,   684,   269,   270,
     271,   686,     8,   687,  1216,   689,  1167,   690,  1235,   691,
     692,  1297,   710,     9,   693,   695,    10,    11,   697,   696,
     700,  1134,   711,   330,  1168,   701,   272,   273,   702,  1169,
     707,   708,   709,  1170,   713,   714,   717,   331,   332,   718,
    1171,   333,   719,   742,    12,  1172,  1298,  1299,   721,    13,
     722,   720,   743,   772,   778,   735,   744,   780,    14,  1173,
     745,   724,  1174,   936,  1175,   937,   938,  1217,   725,   726,
     727,  1236,   728,   731,   732,   736,  1176,   737,   739,    15,
      16,   746,   747,  1177,   751,   750,   752,   781,   769,   334,
     782,   754,   755,   756,   757,   758,  1218,    17,   763,   760,
    1237,   770,  1300,  1219,   764,   765,  1301,  1238,   335,   336,
     337,   338,  1220,   766,    18,   339,  1239,   771,  1185,   340,
    1186,  1187,   773,   777,   774,   341,   775,    19,    20,   783,
     779,   784,   785,   786,   787,   788,   342,   343,  1221,   789,
    1222,  1223,  1240,   790,  1241,  1242,   799,    21,   344,   800,
     801,   802,   913,   807,   808,  1224,   803,   809,   810,  1243,
      22,   845,  1225,   813,   811,   812,  1244,   846,    23,   815,
     345,   848,    24,   818,   819,   820,   821,   822,   823,   824,
     939,   940,   941,   834,   942,   943,   835,   944,   945,   836,
     946,   837,   947,   838,   839,   948,   840,   841,   949,   950,
     842,   951,   843,   844,   849,   850,   952,   852,   346,   853,
     953,   954,   955,   855,   856,   857,   862,   859,   863,   873,
     956,   866,   867,   868,   870,   957,   869,   871,   872,   878,
     881,   882,   885,   874,   886,  1188,  1189,  1190,   875,  1191,
    1192,   876,  1193,  1194,   877,  1195,   879,  1196,   880,   883,
    1197,   884,   887,  1198,  1199,   888,  1200,   889,   983,   890,
     891,  1201,   982,   892,    79,  1202,  1203,  1204,   893,   914,
     915,   916,   894,   917,   918,  1205,   919,   920,   895,   921,
    1206,   922,   896,   897,   923,    80,    81,   924,   925,   898,
     926,    82,   899,   900,   901,   927,   902,   903,   904,   928,
     929,   930,   905,   906,   907,   908,   909,   910,   911,   931,
     912,   935,   960,   961,   932,   962,   963,   984,   964,   965,
     966,   967,   985,   986,   987,   988,    83,    84,   989,   968,
     991,   992,    85,    86,   994,   995,   997,  1003,    87,    88,
      89,   969,   996,   970,   971,  1004,    90,    91,    92,   972,
    1006,   973,  1007,  1009,   974,  1010,   975,   976,   977,   978,
     979,   980,   981,   990,   993,  1000,  1011,  1001,  1002,  1005,
    1012,  1013,    93,    94,  1008,  1014,  1015,  1016,  1017,  1018,
    1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1048,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1046,  1047,  1062,  1050,  1051,  1049,
    1061,  1064,  1063,  1065,  1073,  1074,  1075,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1261,  1089,  1273,  1284,
    1095,  1096,  1285,  1097,  1214,  1286,  1098,  1099,  1213,   312,
    1100,  1233,   586,  1101,  1102,  1103,  1108,  1109,  1110,  1307,
    1111,  1112,  1113,  1114,   575,   762,  1115,  1288,  1116,   749,
    1117,  1118,  1123,  1124,  1137,  1138,  1139,  1140,  1141,  1142,
    1287,  1143,  1144,  1145,  1280,  1151,  1154,  1155,  1156,  1152,
    1283,  1157,  1229,   741,   730,  1282,  1180,  1181,  1182,  1183,
    1184,  1209,  1210,   768,  1211,   639,  1212,  1215,  1228,   817,
    1234,  1247,  1230,  1263,  1262,   506,  1277,  1264,  1304,  1265,
    1266,  1276,  1290,  1291,  1292,  1289,   806,  1281,   405,   734,
     464,   656,  1256,   666,   329,  1255,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   660,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590
};

static const yytype_int16 yycheck[] =
{
     636,   637,   317,     1,   319,     1,   321,   322,     1,   234,
       1,   113,     1,     1,     1,    49,     8,     1,     1,     1,
       1,     1,     1,   234,     1,   214,     1,     1,     1,   218,
     214,    29,   234,   232,   218,   232,    25,   236,   234,    37,
     234,    53,     1,    32,     1,   235,     1,     6,     7,     1,
     235,    49,    50,    12,     1,    35,    54,    55,    56,   232,
     234,    20,    21,   236,     1,   234,   232,    58,    27,     1,
     236,    30,    31,     1,    65,   232,    67,    36,    65,   236,
     234,    79,    41,    42,    65,    44,    45,    46,   234,    48,
     234,    65,    65,     9,    10,    11,   234,    81,    57,   414,
     415,    81,    61,    62,    81,     1,   208,   422,     1,     1,
     103,   426,   234,    72,   103,   103,   431,   129,     1,   434,
     103,   103,   234,    82,   232,   100,    22,    23,   236,   444,
     445,    90,    28,    92,   130,    94,   127,    96,   234,    98,
      99,   456,    25,   130,   459,   460,   103,   130,   103,   124,
     130,   103,   111,   100,   234,   189,   130,   116,   117,   118,
     232,   120,   121,   122,   236,   199,   125,    63,    64,   232,
     233,   103,   234,    69,    70,   103,    59,   124,   130,    75,
      76,    77,   232,     1,   235,    68,   236,    83,    84,    85,
     232,   175,   151,   130,   236,   232,   175,   113,   175,   236,
     159,   160,   161,   162,   163,   164,   234,   199,    91,   234,
     103,   232,    95,   109,   110,   236,   234,    35,   232,     1,
     103,   232,   236,   106,   107,   236,   234,     1,   179,   180,
     223,   227,   191,    15,    16,   233,   235,    19,   553,   234,
     195,   223,   233,    17,   233,   227,   233,   226,     1,   233,
     233,   233,   233,   233,   233,   138,   215,   216,   217,    33,
     219,   220,   221,    81,    17,     1,   225,     3,   223,     5,
     235,   230,   155,   235,   233,   158,   233,   235,   233,   235,
      33,    17,   235,   175,   232,    67,   233,   232,   236,   235,
     227,   223,   235,    67,     1,   223,   233,    33,     1,   227,
     183,   233,   195,   232,    86,    87,    88,    89,   235,   624,
      17,    93,   130,   628,    67,    97,   631,   200,   201,   202,
     635,   103,    58,     1,    60,   235,    33,   203,   204,   103,
     223,    67,   114,   115,   226,   235,     1,   233,     3,   175,
       5,   235,    78,   232,   126,   228,   229,    25,   235,   123,
     233,   235,    17,   235,    32,    58,     1,  1090,  1091,  1092,
      67,   235,    65,   235,    67,   139,   148,   103,    33,   235,
     123,   235,    17,   203,   204,   235,   235,   235,   131,   132,
     235,   235,   156,   157,   235,   235,   235,     1,    33,   235,
     235,   127,   235,    58,   235,    60,   103,   235,   235,   152,
     235,   235,    67,   235,   186,   128,   235,   235,   235,   235,
     235,   147,   235,    78,   235,    29,   123,   232,   235,   235,
     156,   235,    67,    37,   127,   103,   235,   235,     1,   235,
     235,   205,   139,     6,     7,    49,    50,   235,   103,    12,
      54,    55,    56,   235,   235,   235,   235,    20,    21,   156,
     157,   233,   235,   227,    27,   235,   235,    30,    31,   233,
     235,   128,   127,    36,   200,    79,   235,   235,    41,    42,
     235,    44,    45,    46,   227,    48,   235,   235,   123,     1,
     233,   235,   147,   113,    57,   235,   131,   132,    61,    62,
     235,   156,   228,   235,   235,   235,   235,   233,   205,    72,
     235,    13,   235,    25,   235,   235,   235,   152,   235,    82,
     140,   141,   142,   143,   144,   145,   146,    90,   235,    92,
     227,    94,    34,    96,   235,    98,    99,   235,   128,   235,
     235,    43,   113,   235,   235,   200,     4,    59,   111,   235,
     235,   235,   235,   116,   117,   118,    68,   120,   121,   122,
      18,   235,   125,   235,   235,   235,   235,   113,    26,   214,
     113,   113,    74,   228,   113,   113,   113,   113,   113,    91,
     214,   214,    40,    95,   232,   232,   235,   128,   151,   235,
     113,   103,   227,   235,   106,   107,   159,   160,   161,   162,
     163,   164,   104,   105,  1230,    40,   235,   235,   235,   235,
     112,   235,   235,    71,   235,    73,   825,   826,   827,   828,
     829,   830,   831,   235,   235,   235,   138,   235,   191,   235,
     232,   214,   235,   232,   235,   137,    71,   235,    73,   235,
     235,   235,   100,   155,   235,   214,   158,   235,   235,   235,
     235,   153,   215,   216,   217,   235,   219,   220,   221,   235,
     235,   235,   225,   235,   214,   235,   113,   230,     0,     1,
     214,   183,     4,   128,   214,   133,   113,   135,   235,   113,
     113,   214,    14,   214,   119,    17,    18,   214,   200,   201,
     202,   113,    24,   113,    73,   113,   154,   113,    73,   113,
     113,   136,   128,    35,   214,   214,    38,    39,   214,   235,
     214,   213,   113,     1,   172,   214,   228,   229,   214,   177,
     214,   214,   214,   181,   214,   214,   214,    15,    16,   214,
     188,    19,   232,   128,    66,   193,   171,   172,   235,    71,
     235,   232,   128,   128,   128,   232,   232,   128,    80,   207,
     232,   235,   210,    49,   212,    51,    52,   136,   235,   235,
     235,   136,   235,   235,   235,   235,   224,   235,   235,   101,
     102,   235,   235,   231,   235,   232,   235,   113,   214,    67,
     113,   235,   235,   235,   235,   235,   165,   119,   232,   235,
     165,   214,   227,   172,   235,   235,   231,   172,    86,    87,
      88,    89,   181,   235,   136,    93,   181,   214,    49,    97,
      51,    52,   214,   232,   214,   103,   214,   149,   150,   128,
     214,   128,   128,   128,   128,   128,   114,   115,   207,   113,
     209,   210,   207,   128,   209,   210,   128,   169,   126,   128,
     232,   232,    49,   214,   232,   224,   235,   234,   128,   224,
     182,   113,   231,   235,   232,   232,   231,   113,   190,   235,
     148,   235,   194,   232,   232,   232,   232,   232,   232,   232,
     166,   167,   168,   232,   170,   171,   232,   173,   174,   232,
     176,   232,   178,   232,   232,   181,   232,   232,   184,   185,
     232,   187,   232,   232,   113,   113,   192,   113,   186,   113,
     196,   197,   198,   128,   113,   113,   232,   113,   128,   113,
     206,   128,   214,   128,   235,   211,   128,   128,   128,   232,
     232,   232,   232,   128,   232,   166,   167,   168,   128,   170,
     171,   128,   173,   174,   128,   176,   128,   178,   128,   128,
     181,   128,   232,   184,   185,   232,   187,   232,   214,   232,
     232,   192,   128,   232,     1,   196,   197,   198,   232,   166,
     167,   168,   232,   170,   171,   206,   173,   174,   232,   176,
     211,   178,   232,   232,   181,    22,    23,   184,   185,   232,
     187,    28,   232,   232,   232,   192,   232,   232,   232,   196,
     197,   198,   232,   232,   232,   232,   232,   232,   232,   206,
     232,   232,   232,   232,   211,   232,   232,   235,   232,   232,
     232,   232,   128,   113,   128,   128,    63,    64,   128,   232,
     128,   128,    69,    70,   128,   128,   113,   128,    75,    76,
      77,   232,   235,   232,   232,   128,    83,    84,    85,   232,
     128,   232,   214,   128,   232,   128,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   128,   232,   232,   232,
     128,   214,   109,   110,   235,   235,   128,   232,   128,   128,
     128,   232,   232,   232,   232,   232,   232,   232,   232,   128,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   128,   232,   232,   235,
     232,   128,   235,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   113,   232,   128,   134,
     232,   232,   134,   232,  1045,   134,   232,   232,  1043,    74,
     232,  1056,   296,   232,   232,   232,   232,   232,   232,  1306,
     232,   232,   232,   232,   274,   525,   232,  1270,   232,   510,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
    1268,   232,   232,   232,  1249,   222,   232,   232,   232,   236,
    1260,   232,   235,   497,   474,  1258,   232,   232,   232,   232,
     232,   232,   232,   541,   232,   347,   232,   232,   232,   595,
     232,   232,   235,   232,  1152,   230,   232,   237,  1279,   237,
     237,   235,   232,   232,   232,  1272,   579,  1254,   117,   487,
     172,   380,  1122,   409,    95,  1120,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   399,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      38,    39,    66,    71,    80,   101,   102,   119,   136,   149,
     150,   169,   182,   190,   194,   240,   245,   250,   274,   280,
     286,   300,   320,   343,   357,   372,   379,   383,   393,   402,
     423,   429,   435,   439,   445,   504,   522,   232,   233,   234,
     234,   321,   403,   430,   234,   440,   234,   358,   424,   344,
     234,   281,   301,   373,   234,   234,   394,   234,   234,   384,
       1,    25,    32,   103,   275,   276,   277,   278,   279,     1,
      22,    23,    28,    63,    64,    69,    70,    75,    76,    77,
      83,    84,    85,   109,   110,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   234,   234,   234,     1,    65,   436,   437,   438,
     234,     1,     6,     7,    12,    20,    21,    27,    30,    31,
      36,    41,    42,    44,    45,    46,    48,    57,    61,    62,
      72,    82,    90,    92,    94,    96,    98,    99,   111,   116,
     117,   118,   120,   121,   122,   125,   151,   159,   160,   161,
     162,   163,   164,   191,   215,   216,   217,   219,   220,   221,
     225,   230,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     497,   501,   502,   503,   234,   234,   234,     1,   100,   124,
     246,   247,   248,   249,   234,   234,   234,     1,    29,    37,
      49,    50,    54,    55,    56,    79,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,     1,    25,    59,    68,
      91,    95,   103,   106,   107,   138,   155,   158,   183,   200,
     201,   202,   228,   229,   251,   252,   253,   254,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   234,     1,   226,   287,   288,   289,   290,
     291,     1,   103,   380,   381,   382,   234,   232,   235,   235,
     235,   233,   276,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   233,   506,
       1,    15,    16,    19,    67,    86,    87,    88,    89,    93,
      97,   103,   114,   115,   126,   148,   186,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,     1,     3,     5,    17,    33,
      58,    60,    67,    78,   103,   127,   147,   156,   200,   228,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   418,   419,   420,   421,   422,     1,    65,   130,   431,
     432,   433,   434,   235,   233,   437,     1,   103,   130,   441,
     442,   443,   444,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     498,   235,   494,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   233,   447,     1,    17,    33,    67,   123,
     131,   132,   152,   227,   359,   360,   361,   362,   363,   364,
     365,   369,   370,   371,     1,   130,   227,   425,   426,   427,
     428,     1,    58,    65,    67,   127,   345,   349,   350,   351,
     355,   356,   232,   235,   235,   233,   247,     1,    81,   175,
     282,   283,   284,   285,     1,    17,    33,    67,   103,   123,
     139,   156,   157,   205,   227,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   316,     1,    35,    81,
     130,   374,   375,   376,   377,   378,   235,   235,   235,   235,
     235,   235,   235,   235,   233,   524,   232,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   233,   252,     1,   103,   223,   395,
     396,   397,   398,   232,   235,   233,   288,   175,   235,   233,
     381,     1,   103,   223,   227,   385,   386,   387,   388,   389,
     128,   128,   128,   232,   113,   113,   214,   113,   113,   242,
     113,   242,   113,   242,   242,   113,   113,   113,   214,   214,
     232,   232,   235,   235,   235,   340,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   233,   323,
     232,   235,   235,   235,   235,   235,   235,   415,   235,   235,
     235,   235,   235,   235,   235,   233,   405,   235,   235,   233,
     432,   128,   232,   235,   235,   233,   442,   214,   242,   242,
     214,   113,   214,   113,   128,   214,   242,   214,   113,   113,
     242,   113,   214,   214,   214,   242,   113,   113,   242,   113,
     113,   113,   113,   214,   235,   214,   235,   214,   242,   242,
     214,   214,   214,   214,   218,   214,   218,   214,   214,   214,
     128,   113,   242,   214,   214,   242,   242,   214,   214,   232,
     232,   235,   235,   366,   235,   235,   235,   235,   235,   233,
     360,   235,   235,   233,   426,   232,   235,   235,   346,   235,
     233,   350,   128,   128,   232,   232,   235,   235,   233,   283,
     232,   235,   235,   317,   235,   235,   235,   235,   235,   313,
     235,   233,   303,   232,   235,   235,   235,   233,   375,   214,
     214,   214,   128,   214,   214,   214,   242,   232,   128,   214,
     128,   113,   113,   128,   128,   128,   128,   128,   128,   113,
     128,   203,   204,   255,   256,   203,   204,   257,   258,   128,
     128,   232,   232,   235,   399,   233,   396,   214,   232,   234,
     128,   232,   232,   235,   390,   235,   233,   386,   232,   232,
     232,   232,   232,   232,   232,   140,   141,   142,   143,   144,
     145,   146,   241,   242,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   113,   113,   242,   235,   113,
     113,   242,   113,   113,   242,   128,   113,   113,   242,   113,
     244,   244,   232,   128,   179,   180,   128,   214,   128,   128,
     235,   128,   128,   113,   128,   128,   128,   128,   232,   128,
     128,   232,   232,   128,   128,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,    49,   166,   167,   168,   170,   171,   173,
     174,   176,   178,   181,   184,   185,   187,   192,   196,   197,
     198,   206,   211,   499,   500,   232,    49,    51,    52,   166,
     167,   168,   170,   171,   173,   174,   176,   178,   181,   184,
     185,   187,   192,   196,   197,   198,   206,   211,   495,   496,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   128,   214,   235,   128,   113,   128,   128,   128,
     232,   128,   128,   232,   128,   128,   235,   113,   353,   354,
     232,   232,   232,   128,   128,   232,   128,   214,   235,   128,
     128,   128,   128,   214,   235,   128,   232,   128,   128,   128,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   236,   232,   236,   232,   232,   128,   235,
     232,   232,     1,   103,   195,   223,   292,   293,   294,   295,
     296,   232,   128,   235,   128,   232,   241,   241,   241,   241,
     241,   241,   241,   232,   232,   232,    53,   129,   341,   342,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
       9,    10,    11,   243,   244,   232,   232,   232,   232,   232,
     232,   232,   232,   232,     8,   199,   416,   417,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     236,   232,   236,   232,   232,    13,    34,    43,    74,   104,
     105,   112,   137,   153,   213,   367,   368,   232,   232,   232,
     232,   232,   232,   232,   232,   232,    49,   189,   199,   347,
     348,   222,   236,   352,   232,   232,   232,   232,     4,    18,
      26,    40,    71,    73,   100,   133,   135,   154,   172,   177,
     181,   188,   193,   207,   210,   212,   224,   231,   318,   319,
     232,   232,   232,   232,   232,    49,    51,    52,   166,   167,
     168,   170,   171,   173,   174,   176,   178,   181,   184,   185,
     187,   192,   196,   197,   198,   206,   211,   314,   315,   232,
     232,   232,   232,   256,   258,   232,    73,   136,   165,   172,
     181,   207,   209,   210,   224,   231,   400,   401,   232,   235,
     235,   297,   233,   293,   232,    73,   136,   165,   172,   181,
     207,   209,   210,   224,   231,   391,   392,   232,   232,   236,
     243,   243,   243,   232,   236,   500,   496,   232,   236,   232,
     236,   113,   354,   232,   237,   237,   237,   232,   236,   232,
     236,   232,   236,   128,   208,   244,   235,   232,   232,   236,
     342,   417,   368,   348,   134,   134,   134,   319,   315,   401,
     232,   232,   232,    40,    71,    73,   119,   136,   171,   172,
     227,   231,   298,   299,   392,   232,   236,   299
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
     315,   315,   315,   315,   315,   315,   317,   316,   318,   318,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   321,   320,   322,   322,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   340,
     339,   341,   341,   342,   342,   344,   343,   346,   345,   347,
     347,   348,   348,   348,   349,   349,   350,   350,   350,   350,
     350,   352,   351,   353,   353,   354,   354,   355,   356,   358,
     357,   359,   359,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   361,   362,   363,   364,   366,   365,   367,   367,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     369,   370,   371,   373,   372,   374,   374,   375,   375,   375,
     375,   376,   377,   378,   379,   380,   380,   381,   381,   382,
     384,   383,   385,   385,   386,   386,   386,   386,   387,   388,
     390,   389,   391,   391,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   392,   394,   393,   395,   395,   396,   396,
     396,   397,   399,   398,   400,   400,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   403,   402,   404,   404,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   413,   415,   414,   416,   416,   417,   417,
     418,   419,   420,   421,   422,   424,   423,   425,   425,   426,
     426,   426,   427,   428,   430,   429,   431,   431,   432,   432,
     432,   433,   434,   435,   436,   436,   437,   437,   438,   440,
     439,   441,   441,   442,   442,   442,   443,   444,   445,   446,
     446,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   474,
     475,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   494,
     493,   495,   495,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   498,   497,   499,   499,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   501,
     502,   503,   504,   505,   505,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   523,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   525,   526,
     527,   528,   529,   530,   531,   532
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
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     0,     6,     0,     5,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     0,     5,     3,     1,     1,     3,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     5,     2,     1,     1,     1,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       2,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       4,     4,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
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
        case 27:
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2860 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2878 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2914 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2932 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 440 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 480 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 486 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 495 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 501 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 3000 "conf_parser.c" /* yacc.c:1646  */
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
#line 3045 "conf_parser.c" /* yacc.c:1646  */
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
#line 3106 "conf_parser.c" /* yacc.c:1646  */
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
#line 3137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 637 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3148 "conf_parser.c" /* yacc.c:1646  */
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
#line 3166 "conf_parser.c" /* yacc.c:1646  */
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
#line 3184 "conf_parser.c" /* yacc.c:1646  */
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
#line 3196 "conf_parser.c" /* yacc.c:1646  */
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
#line 3213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 698 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3225 "conf_parser.c" /* yacc.c:1646  */
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
#line 3256 "conf_parser.c" /* yacc.c:1646  */
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
#line 3289 "conf_parser.c" /* yacc.c:1646  */
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
#line 3317 "conf_parser.c" /* yacc.c:1646  */
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
#line 3342 "conf_parser.c" /* yacc.c:1646  */
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
#line 3367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 860 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 869 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3412 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 881 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3421 "conf_parser.c" /* yacc.c:1646  */
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
#line 3438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 902 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3447 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 908 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 923 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 929 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3474 "conf_parser.c" /* yacc.c:1646  */
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
#line 3487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 949 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 957 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 960 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 965 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 972 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 976 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 980 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 984 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 988 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3568 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3577 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 996 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3586 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3595 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1004 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3604 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3616 "conf_parser.c" /* yacc.c:1646  */
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
#line 3692 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3701 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1113 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3710 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3719 "conf_parser.c" /* yacc.c:1646  */
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
#line 3733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1136 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3742 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1142 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3751 "conf_parser.c" /* yacc.c:1646  */
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
#line 3765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1159 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3774 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1165 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3783 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1172 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1176 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3801 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1180 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1184 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3819 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1188 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3828 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1196 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1208 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1216 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1224 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1228 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1252 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
#line 4053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4107 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1345 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1349 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4179 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1367 "conf_parser.y" /* yacc.c:1646  */
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
#line 4214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1379 "conf_parser.y" /* yacc.c:1646  */
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
#line 4266 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4275 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1452 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4284 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1458 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4293 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1464 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4302 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1470 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4311 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1476 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1482 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4329 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1488 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1494 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4347 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1500 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1507 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1513 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1519 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1525 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1534 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1543 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1550 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1554 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1564 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1570 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1576 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1580 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1584 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4479 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1592 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4485 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1597 "conf_parser.y" /* yacc.c:1646  */
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
#line 4504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1611 "conf_parser.y" /* yacc.c:1646  */
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
#line 4525 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1629 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4534 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1635 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4543 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1644 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4552 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1648 "conf_parser.y" /* yacc.c:1646  */
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
#line 4593 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1697 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4602 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1703 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4611 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1709 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4620 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1715 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1726 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1733 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4652 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1737 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4661 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1741 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4670 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1745 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1749 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4688 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1753 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1757 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4706 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1761 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1765 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1769 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1775 "conf_parser.y" /* yacc.c:1646  */
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
#line 4750 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1789 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1798 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4774 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1811 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1818 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4797 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1829 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4806 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1841 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1856 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4839 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1871 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1882 "conf_parser.y" /* yacc.c:1646  */
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
#line 4872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1899 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1905 "conf_parser.y" /* yacc.c:1646  */
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
#line 4903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1924 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1931 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1935 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1943 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1951 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1955 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1963 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1967 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1976 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1985 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5031 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2006 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5049 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5058 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2017 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5067 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5076 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5121 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5130 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5139 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2058 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5153 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2067 "conf_parser.y" /* yacc.c:1646  */
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
#line 5219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2147 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2153 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2159 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2165 "conf_parser.y" /* yacc.c:1646  */
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
#line 5262 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2178 "conf_parser.y" /* yacc.c:1646  */
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
#line 5278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5287 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2203 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5305 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2207 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5316 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2215 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2225 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2231 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2242 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2254 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2260 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2275 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2279 "conf_parser.y" /* yacc.c:1646  */
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
#line 5431 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2304 "conf_parser.y" /* yacc.c:1646  */
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
#line 5454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2337 "conf_parser.y" /* yacc.c:1646  */
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
#line 5498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2363 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2369 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5516 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2383 "conf_parser.y" /* yacc.c:1646  */
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
#line 5533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2400 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2404 "conf_parser.y" /* yacc.c:1646  */
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
#line 5564 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2426 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2432 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 512:
#line 2498 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5590 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2503 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5599 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2509 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5608 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2515 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5617 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2521 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5626 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2527 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2532 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2537 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5650 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2542 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2547 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5666 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2552 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5674 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2557 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2562 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5690 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2567 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number);
}
#line 5698 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2572 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5706 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2577 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2582 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5722 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2587 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5730 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2592 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5739 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2598 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5753 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2609 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5761 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2614 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_connect_block = yylval.number;
}
#line 5769 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2619 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2624 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5785 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2629 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2634 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5801 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2639 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2642 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5817 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2650 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5833 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2655 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2660 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2665 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5857 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2670 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2675 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2680 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2685 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2690 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2695 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5905 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2700 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2705 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.use_egd = yylval.number;
}
#line 5921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2710 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
#line 5933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2719 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 5945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2728 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 5953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2733 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 5961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2738 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_count = (yyvsp[-1].number);
}
#line 5969 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2743 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = (yyvsp[-1].number);
}
#line 5977 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 5985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2754 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 5993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 6001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2760 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 6009 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2763 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 6017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2766 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 6025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2769 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 6033 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDECHANS;
}
#line 6041 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2775 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6049 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2778 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 6057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2781 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6065 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2784 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2790 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2793 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2796 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6105 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2799 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6113 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2802 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6121 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2805 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2808 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2811 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6145 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2814 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6153 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2817 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6185 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6193 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6201 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6217 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6225 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6233 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6257 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2861 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6265 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2864 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6273 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2867 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6281 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2870 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6289 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2873 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6297 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2876 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6305 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2879 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6313 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2882 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6321 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2885 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6329 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6337 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2895 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6345 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2900 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6353 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2930 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6361 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2936 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2941 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6377 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2946 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6385 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2951 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2956 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2961 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
#line 6409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2966 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[-1].number);
}
#line 6417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2971 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2976 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 2981 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 2986 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6449 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2991 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2996 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3001 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3023 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3047 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3056 "conf_parser.y" /* yacc.c:1646  */
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
#line 6538 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3076 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6556 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6560 "conf_parser.c" /* yacc.c:1646  */
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
