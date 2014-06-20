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
    SSL_DH_PARAM_FILE = 412,
    STATS_E_DISABLED = 413,
    STATS_I_OPER_ONLY = 414,
    STATS_K_OPER_ONLY = 415,
    STATS_O_OPER_ONLY = 416,
    STATS_P_OPER_ONLY = 417,
    STATS_U_OPER_ONLY = 418,
    T_ALL = 419,
    T_BOTS = 420,
    T_CALLERID = 421,
    T_CCONN = 422,
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
    T_MAX_CLIENTS = 437,
    T_NCHANGE = 438,
    T_NONONREG = 439,
    T_RECVQ = 440,
    T_REJ = 441,
    T_RESTART = 442,
    T_SERVER = 443,
    T_SERVICE = 444,
    T_SERVICES_NAME = 445,
    T_SERVNOTICE = 446,
    T_SET = 447,
    T_SHARED = 448,
    T_SIZE = 449,
    T_SKILL = 450,
    T_SOFTCALLERID = 451,
    T_SPY = 452,
    T_SSL = 453,
    T_SSL_CIPHER_LIST = 454,
    T_SSL_CLIENT_METHOD = 455,
    T_SSL_SERVER_METHOD = 456,
    T_SSLV3 = 457,
    T_TLSV1 = 458,
    T_UMODES = 459,
    T_UNAUTH = 460,
    T_UNDLINE = 461,
    T_UNLIMITED = 462,
    T_UNRESV = 463,
    T_UNXLINE = 464,
    T_WALLOP = 465,
    T_WALLOPS = 466,
    T_WEBIRC = 467,
    TBOOL = 468,
    THROTTLE_COUNT = 469,
    THROTTLE_TIME = 470,
    TKLINE_EXPIRE_NOTICES = 471,
    TMASKED = 472,
    TRUE_NO_OPER_FLOOD = 473,
    TS_MAX_DELTA = 474,
    TS_WARN_DELTA = 475,
    TWODOTS = 476,
    TYPE = 477,
    UNKLINE = 478,
    USE_EGD = 479,
    USE_LOGGING = 480,
    USER = 481,
    VHOST = 482,
    VHOST6 = 483,
    WARN_NO_CONNECT_BLOCK = 484,
    XLINE = 485
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
#define SSL_DH_PARAM_FILE 412
#define STATS_E_DISABLED 413
#define STATS_I_OPER_ONLY 414
#define STATS_K_OPER_ONLY 415
#define STATS_O_OPER_ONLY 416
#define STATS_P_OPER_ONLY 417
#define STATS_U_OPER_ONLY 418
#define T_ALL 419
#define T_BOTS 420
#define T_CALLERID 421
#define T_CCONN 422
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
#define T_MAX_CLIENTS 437
#define T_NCHANGE 438
#define T_NONONREG 439
#define T_RECVQ 440
#define T_REJ 441
#define T_RESTART 442
#define T_SERVER 443
#define T_SERVICE 444
#define T_SERVICES_NAME 445
#define T_SERVNOTICE 446
#define T_SET 447
#define T_SHARED 448
#define T_SIZE 449
#define T_SKILL 450
#define T_SOFTCALLERID 451
#define T_SPY 452
#define T_SSL 453
#define T_SSL_CIPHER_LIST 454
#define T_SSL_CLIENT_METHOD 455
#define T_SSL_SERVER_METHOD 456
#define T_SSLV3 457
#define T_TLSV1 458
#define T_UMODES 459
#define T_UNAUTH 460
#define T_UNDLINE 461
#define T_UNLIMITED 462
#define T_UNRESV 463
#define T_UNXLINE 464
#define T_WALLOP 465
#define T_WALLOPS 466
#define T_WEBIRC 467
#define TBOOL 468
#define THROTTLE_COUNT 469
#define THROTTLE_TIME 470
#define TKLINE_EXPIRE_NOTICES 471
#define TMASKED 472
#define TRUE_NO_OPER_FLOOD 473
#define TS_MAX_DELTA 474
#define TS_WARN_DELTA 475
#define TWODOTS 476
#define TYPE 477
#define UNKLINE 478
#define USE_EGD 479
#define USE_LOGGING 480
#define USER 481
#define VHOST 482
#define VHOST6 483
#define WARN_NO_CONNECT_BLOCK 484
#define XLINE 485

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 147 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 690 "conf_parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 705 "conf_parser.c" /* yacc.c:358  */

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
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  295
/* YYNRULES -- Number of rules.  */
#define YYNRULES  665
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1308

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   485

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
       2,     2,     2,     2,   235,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   236,   231,
       2,   234,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   233,     2,   232,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230
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
    1348,  1352,  1356,  1367,  1366,  1428,  1428,  1429,  1430,  1431,
    1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,
    1441,  1442,  1443,  1444,  1445,  1447,  1453,  1459,  1465,  1471,
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
    2499,  2500,  2501,  2502,  2505,  2510,  2516,  2522,  2528,  2534,
    2539,  2544,  2549,  2554,  2559,  2564,  2569,  2574,  2579,  2584,
    2589,  2594,  2599,  2605,  2616,  2621,  2626,  2631,  2636,  2641,
    2646,  2649,  2654,  2657,  2662,  2667,  2672,  2677,  2682,  2687,
    2692,  2697,  2702,  2707,  2712,  2717,  2726,  2735,  2740,  2745,
    2750,  2756,  2755,  2760,  2760,  2761,  2764,  2767,  2770,  2773,
    2776,  2779,  2782,  2785,  2788,  2791,  2794,  2797,  2800,  2803,
    2806,  2809,  2812,  2815,  2818,  2821,  2824,  2830,  2829,  2834,
    2834,  2835,  2838,  2841,  2844,  2847,  2850,  2853,  2856,  2859,
    2862,  2865,  2868,  2871,  2874,  2877,  2880,  2883,  2886,  2889,
    2892,  2897,  2902,  2907,  2916,  2919,  2919,  2920,  2921,  2922,
    2923,  2924,  2925,  2926,  2927,  2928,  2929,  2930,  2931,  2932,
    2933,  2934,  2936,  2941,  2946,  2951,  2956,  2961,  2966,  2971,
    2976,  2981,  2986,  2991,  2996,  3001,  3009,  3012,  3012,  3013,
    3014,  3015,  3016,  3017,  3018,  3019,  3020,  3021,  3023,  3029,
    3035,  3041,  3047,  3056,  3070,  3076
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
  "SSL_CONNECTION_REQUIRED", "SSL_DH_PARAM_FILE", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL", "T_BOTS",
  "T_CALLERID", "T_CCONN", "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE",
  "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS",
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
     485,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -957

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-957)))

#define YYTABLE_NINF -124

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -957,   701,  -957,   -24,  -223,  -211,  -957,  -957,  -957,  -204,
    -957,  -183,  -957,  -957,  -957,  -176,  -957,  -957,  -957,  -157,
    -138,  -957,  -108,   -89,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,   287,
     943,   -72,   -69,   -66,    54,   -43,   394,   -31,   -23,   -20,
      74,   -17,   -15,    -2,   445,   444,    17,    30,    27,    35,
      -3,    40,    49,    66,    11,  -957,  -957,  -957,  -957,  -957,
      76,    82,    94,   100,   103,   111,   115,   116,   118,   120,
     123,   125,   126,   128,     2,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
     661,   561,    62,  -957,   131,    25,  -957,  -957,    63,  -957,
     133,   137,   139,   142,   143,   144,   146,   148,   149,   150,
     152,   153,   154,   157,   158,   163,   165,   171,   173,   174,
     175,   176,   179,   182,   183,   184,   185,  -957,   186,  -957,
     188,   193,   195,   197,   199,   203,   207,   210,   213,   214,
     215,   216,   218,   219,   220,   223,   224,   225,   226,   227,
      61,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,   272,    60,   286,   141,   228,   233,    15,  -957,
    -957,  -957,    12,   530,    45,  -957,   234,   236,   238,   241,
     243,   244,   245,   246,     4,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,   162,   247,   250,   252,   254,   256,
     259,   262,   263,   268,   271,   274,   282,   283,   288,   291,
     292,   294,   147,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,    47,   167,   296,    10,  -957,  -957,  -957,    90,  -957,
     298,    14,  -957,  -957,   159,  -957,   307,   346,   379,   289,
    -957,   415,   421,    81,   423,   424,   425,   424,   427,   424,
     424,   429,   430,   332,   335,   320,  -957,   327,   326,   331,
     341,  -957,   343,   345,   348,   349,   351,   352,   353,   354,
     356,   357,   358,   359,   362,   211,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,   330,   365,   366,   369,   370,   371,
     372,  -957,   373,   377,   381,   382,   383,   388,   390,   136,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,   391,   393,    39,  -957,
    -957,  -957,   502,   399,  -957,  -957,   397,   400,    26,  -957,
    -957,  -957,   420,   424,   424,   433,   524,   434,   526,   513,
     435,   424,   438,   529,   541,   424,   542,   442,   446,   447,
     424,   549,   552,   424,   553,   554,   555,   557,   457,   408,
     460,   441,   465,   424,   424,   468,   471,   475,  -196,  -175,
     476,   478,   479,   531,   581,   424,   481,   483,   424,   424,
     490,   491,   477,  -957,   480,   472,   486,  -957,   487,   488,
     489,   493,   495,   239,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,   496,   497,    33,  -957,  -957,  -957,
     482,   498,   504,  -957,   507,  -957,    31,  -957,  -957,  -957,
    -957,  -957,   583,   590,   506,  -957,   511,   509,   510,    13,
    -957,  -957,  -957,   519,   517,   518,  -957,   520,   521,   525,
     527,   528,  -957,   532,   200,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,   533,   534,   535,   536,
      34,  -957,  -957,  -957,  -957,   558,   560,   563,   597,   564,
     565,   566,   424,   556,  -957,  -957,   638,   571,   658,   684,
     686,   672,   673,   676,   677,   678,   679,   695,   682,   129,
     138,   683,   685,   580,  -957,   585,   595,  -957,    86,  -957,
    -957,  -957,  -957,   611,   599,  -957,   602,   710,   607,  -957,
     609,   613,  -957,   614,    22,  -957,  -957,  -957,  -957,   610,
     620,   621,  -957,   623,   624,   625,   626,   428,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   641,  -957,  -957,
     761,   762,   424,   642,   763,   765,   766,   424,   767,   768,
     424,   756,   769,   772,   424,   774,   774,   656,  -957,  -957,
     764,   164,   775,   675,   778,   780,   659,   782,   783,   787,
     785,   786,   789,   792,   664,  -957,   793,   794,   692,  -957,
     693,  -957,   802,   803,   700,  -957,   702,   704,   706,   716,
     718,   720,   721,   723,   724,   727,   730,   736,   741,   742,
     743,   744,   745,   748,   749,   750,   751,   755,   757,   758,
     759,   760,   770,   773,   771,   648,   777,   779,   784,   790,
     791,   797,   798,   799,   800,   801,   804,   805,   806,   807,
     808,   809,   810,   811,   812,   813,   814,   815,  -957,  -957,
     858,   719,   753,   865,   881,   867,   868,   869,   816,  -957,
     870,   871,   817,  -957,  -957,   872,   873,   819,   891,   818,
    -957,   823,   824,  -957,  -957,   877,   878,   825,  -957,  -957,
     882,   820,   826,   884,   887,   889,   890,   821,   827,   896,
     828,  -957,  -957,   897,   898,   923,   831,  -957,   832,   833,
     834,   835,   836,   837,   838,   839,  -957,   840,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
    -957,  -957,  -186,  -957,  -957,  -957,  -184,  -957,   853,   854,
    -957,  -957,   930,   855,   856,  -957,   857,  -957,    98,   859,
    -957,  -957,   931,   860,   959,   861,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,   424,   424,   424,   424,   424,   424,
     424,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,   862,   864,   866,   -44,   874,   875,   876,
     879,   880,   883,   885,   886,   888,   892,   893,     9,   894,
     895,  -957,   899,   900,   901,   902,   903,   904,   905,     0,
     906,   907,   908,   909,   910,   911,   912,  -957,   913,   914,
    -957,  -957,   915,   916,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -179,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -161,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,   917,   918,   546,   919,   920,   921,   922,   924,  -957,
     925,   926,  -957,   927,   928,    -5,   933,   863,  -957,  -957,
    -957,  -957,   929,   932,  -957,   934,   935,   503,   936,   937,
     938,   939,   940,   731,   941,  -957,   942,   944,   945,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,   129,  -957,   138,  -957,  -957,   946,   662,  -957,
    -957,   947,   948,   949,  -957,    38,  -957,  -957,  -957,  -957,
    -957,   950,   754,   953,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,   -84,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
     774,   774,   774,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,   -65,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
     773,  -957,   648,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,   -56,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,   -36,
    -957,   979,   891,   954,  -957,  -957,  -957,  -957,  -957,   951,
    -957,  -957,   952,  -957,  -957,  -957,  -957,   955,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,   -26,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,    -6,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,    80,  -957,  -957,   969,
     -75,   956,   958,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,    92,  -957,  -957,  -957,   -44,
    -957,  -957,  -957,  -957,     0,  -957,  -957,  -957,   546,  -957,
      -5,  -957,  -957,  -957,   966,   967,   968,  -957,   503,  -957,
     731,  -957,   662,   961,   962,   963,   293,  -957,  -957,   754,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,    95,  -957,  -957,  -957,   293,  -957
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   223,   388,   436,     0,
     451,     0,   291,   427,   267,     0,   107,   147,   325,     0,
       0,   366,     0,     0,   342,     3,    23,    11,     4,    24,
       5,     6,     8,     9,    10,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    21,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   102,   101,   631,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   616,   630,   618,   619,   620,
     621,   622,   623,   617,   624,   625,   626,   627,   628,   629,
       0,     0,     0,   449,     0,     0,   447,   448,     0,   513,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   587,     0,   561,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   462,   510,   512,   504,   505,   506,   507,   508,   503,
     473,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   500,   474,   475,   509,   477,   482,   483,   478,   480,
     479,   493,   494,   481,   484,   485,   486,   487,   476,   489,
     490,   491,   511,   501,   502,   498,   499,   492,   488,   496,
     497,   495,     0,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,     0,   657,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   648,   649,   650,   651,   652,
     655,   653,   654,   656,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    68,    69,    67,    64,    63,    70,
      54,    66,    57,    58,    59,    55,    65,    60,    61,    62,
      56,     0,     0,     0,     0,   118,   119,   120,     0,   340,
       0,     0,   338,   339,     0,   103,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   615,     0,     0,     0,
       0,   261,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,   227,   230,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   228,   229,
     231,   241,   242,   243,     0,     0,     0,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   399,   398,   401,
     405,   402,   403,   404,   400,   442,     0,     0,     0,   439,
     440,   441,     0,     0,   446,   457,     0,     0,     0,   454,
     455,   456,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   461,     0,     0,     0,   308,     0,     0,
       0,     0,     0,     0,   294,   295,   296,   297,   302,   298,
     299,   300,   301,   433,     0,     0,     0,   430,   431,   432,
       0,     0,     0,   269,     0,   279,     0,   277,   278,   280,
     281,    48,     0,     0,     0,    44,     0,     0,     0,     0,
     110,   111,   112,     0,     0,     0,   196,     0,     0,     0,
       0,     0,   170,     0,     0,   150,   151,   152,   153,   156,
     157,   158,   159,   155,   154,   160,     0,     0,     0,     0,
       0,   328,   329,   330,   331,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   647,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,   374,     0,   369,
     370,   371,   121,     0,     0,   117,     0,     0,     0,   337,
       0,     0,   352,     0,     0,   345,   346,   347,   348,     0,
       0,     0,    97,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   614,   244,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,   406,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   390,     0,     0,     0,   438,
       0,   445,     0,     0,     0,   453,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   460,   303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
       0,     0,     0,   429,   282,     0,     0,     0,     0,     0,
     276,     0,     0,    43,   113,     0,     0,     0,   109,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   149,   332,     0,     0,     0,     0,   327,     0,     0,
       0,     0,     0,     0,     0,     0,   646,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    77,     0,    75,    80,    81,     0,    79,     0,     0,
      51,   372,     0,     0,     0,   368,     0,   116,     0,     0,
     336,   349,     0,     0,     0,     0,   344,   106,   105,   104,
     641,   640,   632,   633,    27,    27,    27,    27,    27,    27,
      27,    29,    28,   634,   644,   645,   635,   636,   637,   639,
     638,   642,   643,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   389,     0,     0,
     437,   450,     0,     0,   452,   526,   530,   545,   515,   613,
     558,   552,   555,   525,   517,   516,   519,   520,   518,   533,
     523,   524,   534,   522,   529,   528,   527,   553,   514,   611,
     612,   549,   597,   591,   607,   592,   593,   594,   602,   610,
     595,   604,   608,   598,   609,   599,   603,   596,   606,   601,
     600,   605,     0,   590,   551,   570,   571,   572,   565,   583,
     566,   567,   568,   578,   586,   569,   580,   584,   574,   585,
     575,   579,   573,   582,   577,   576,   581,     0,   564,   546,
     544,   547,   557,   548,   536,   542,   543,   540,   541,   537,
     538,   539,   556,   559,   560,   521,   550,   532,   531,   554,
     535,     0,     0,     0,     0,     0,     0,     0,     0,   292,
       0,     0,   428,     0,     0,     0,   287,   283,   286,   268,
      49,    50,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,   326,
     659,   658,   664,   662,   665,   660,   661,   663,    88,    96,
      87,    94,    95,    86,    90,    89,    83,    82,    84,    93,
      85,    72,     0,    73,     0,    91,    92,     0,     0,   367,
     122,     0,     0,     0,   134,     0,   126,   127,   129,   128,
     341,     0,     0,     0,   343,    30,    31,    32,    33,    34,
      35,    36,   256,   257,   248,   266,   265,     0,   264,   249,
     251,   253,   260,   252,   250,   259,   245,   258,   247,   246,
      37,    37,    37,    39,    38,   254,   255,   411,   414,   415,
     425,   422,   408,   423,   420,   421,     0,   419,   424,   407,
     413,   410,   412,   426,   409,   443,   444,   458,   459,   588,
       0,   562,     0,   306,   307,   316,   313,   318,   314,   315,
     321,   317,   319,   312,   320,     0,   311,   305,   324,   323,
     322,   304,   435,   434,   290,   289,   274,   275,   273,     0,
     272,     0,     0,     0,   114,   115,   169,   165,   216,   203,
     213,   212,   201,   206,   222,   215,   220,   205,   208,   217,
     219,   214,   221,   209,   211,   218,   207,   210,     0,   199,
     162,   164,   166,   167,   168,   179,   180,   181,   174,   192,
     175,   176,   177,   187,   195,   178,   189,   193,   183,   194,
     184,   188,   182,   191,   186,   185,   190,     0,   173,   163,
     335,   333,   334,    74,    78,   373,   378,   384,   387,   380,
     386,   381,   385,   383,   379,   382,     0,   377,   130,     0,
       0,     0,     0,   125,   350,   356,   362,   365,   358,   364,
     359,   363,   361,   357,   360,     0,   355,   351,   262,     0,
      40,    41,    42,   417,     0,   589,   563,   309,     0,   270,
       0,   288,   285,   284,     0,     0,     0,   197,     0,   171,
       0,   375,     0,     0,     0,     0,     0,   124,   353,     0,
     263,   418,   310,   271,   202,   200,   204,   198,   172,   376,
     131,   133,   132,   140,   145,   144,   139,   142,   146,   143,
     138,   141,     0,   137,   354,   135,     0,   136
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -957,  -957,  -957,   -35,  -313,  -956,  -635,  -957,  -957,   970,
    -957,  -957,  -957,  -957,   830,  -957,  -957,  -957,    67,  -957,
      59,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  1030,  -957,
    -957,  -957,  -957,  -957,  -957,   603,  -957,  -957,  -957,  -957,
     957,  -957,  -957,  -957,  -957,    53,  -957,  -957,  -957,  -957,
    -957,  -193,  -957,  -957,  -957,   591,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -152,  -957,  -957,
    -957,  -148,  -957,  -957,  -957,   776,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -127,  -957,  -957,  -957,  -957,
    -957,  -133,  -957,   665,  -957,  -957,  -957,    28,  -957,  -957,
    -957,  -957,  -957,   655,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -129,  -957,  -957,  -957,  -957,  -957,  -957,   622,  -957,
    -957,  -957,  -957,  -957,   960,  -957,  -957,  -957,  -957,   570,
    -957,  -957,  -957,  -957,  -957,  -105,  -957,  -957,  -957,   601,
    -957,  -957,  -957,  -957,   -86,  -957,  -957,  -957,   822,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
     -59,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,   711,
    -957,  -957,  -957,  -957,  -957,   829,  -957,  -957,  -957,  -957,
    1081,  -957,  -957,  -957,  -957,   795,  -957,  -957,  -957,  -957,
    1029,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,    78,
    -957,  -957,  -957,    84,  -957,  -957,  -957,  -957,  -957,  1108,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,   964,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   831,   832,  1093,  1094,    26,   228,   229,
     230,   231,    27,   272,   273,   274,   275,   792,   793,   796,
     797,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    28,    74,    75,    76,
      77,    78,    29,    61,   509,   510,   511,   512,    30,   294,
     295,   296,   297,   298,  1055,  1056,  1057,  1058,  1059,  1231,
    1302,  1303,    31,    62,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   758,  1207,  1208,   535,   752,
    1178,  1179,    32,    51,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   623,  1077,  1078,    33,    59,   495,   737,
    1149,  1150,   496,   497,   498,  1153,   997,   998,   499,   500,
      34,    57,   473,   474,   475,   476,   477,   478,   479,   722,
    1135,  1136,   480,   481,   482,    35,    63,   540,   541,   542,
     543,   544,    36,   301,   302,   303,    37,    69,   594,   595,
     596,   597,   598,   813,  1245,  1246,    38,    66,   578,   579,
     580,   581,   803,  1226,  1227,    39,    52,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   646,  1106,
    1107,   390,   391,   392,   393,   394,    40,    58,   486,   487,
     488,   489,    41,    53,   398,   399,   400,   401,    42,   115,
     116,   117,    43,    55,   408,   409,   410,   411,    44,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   441,   957,   958,
     218,   439,   932,   933,   219,   220,   221,    45,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    46,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     859,   860,   608,    79,   610,   235,   612,   613,  1104,  1075,
      49,   292,    70,   506,   506,   299,   225,   702,  1090,  1091,
    1092,   703,    50,   590,    80,    81,   113,   405,   299,    54,
      82,   292,   490,   236,   483,   536,    71,   858,   704,  1051,
     395,   237,   705,    72,  1146,  1041,   536,  1043,   575,  1042,
      56,  1044,  1119,   238,   239,   113,  1120,    60,   240,   241,
     242,   483,   119,   395,   405,    83,    84,   120,   121,   537,
    1121,    85,    86,   122,  1122,   225,    64,    87,    88,    89,
     537,   123,   124,   243,  1076,    90,    91,   575,   125,   491,
     114,   126,   127,   507,   507,    65,   492,   128,   493,  1051,
     667,   668,   129,   130,   396,   131,   132,   133,   675,   134,
      92,    93,   679,    73,   226,   538,   300,   684,   135,   114,
     687,   858,   136,   137,   591,    67,   538,   396,   406,   300,
     697,   698,  1274,   138,  1250,  1251,  1252,   364,   227,   365,
    1052,   366,   711,   139,    68,   714,   715,  1248,   254,   576,
     140,  1249,   141,   367,   142,   407,   143,   494,   144,   145,
     590,   110,   484,   539,   111,   406,  1253,   112,   397,   368,
    1254,   146,   255,   226,   539,  1257,   147,   148,   149,  1258,
     150,   151,   152,  1147,  -123,   153,   508,   508,   576,   484,
     118,   397,   407,  1148,   369,  1259,   370,   227,  1105,  1260,
    1052,   513,   222,   371,  -123,  1267,   256,    47,    48,  1268,
     223,   154,   327,   224,   372,   257,   232,   514,   233,   155,
     156,   157,   158,   159,   160,  1269,   328,   329,   305,  1270,
     330,   234,  1053,   515,   325,   293,   553,   258,   373,   775,
     464,   259,   584,   309,   592,   747,   588,   504,   593,   260,
     291,   161,   261,   262,   815,   293,   465,   403,   664,   485,
    1054,   591,   374,   739,   586,   732,   766,   516,   304,   577,
    1232,   658,   466,   464,   306,   162,   163,   164,   331,   165,
     166,   167,   375,   307,   263,   168,   485,   490,    70,   465,
     169,   376,  1053,   462,   605,   332,   333,   334,   335,   336,
     308,   264,   517,   337,   265,   466,   467,   338,   577,   845,
     311,  1271,    71,   339,   850,  1272,   312,   853,   804,    72,
    1054,   857,   518,  1278,   340,   341,  1305,  1279,   313,   266,
    1306,   790,   791,  1293,   314,   377,   342,   315,   519,   467,
     794,   795,   863,   864,   491,   316,   267,   268,   269,   317,
     318,   492,   319,   493,   320,   520,   521,   321,   343,   322,
     323,   468,   324,   378,  1294,   402,  1295,   412,   654,   469,
     470,   413,   501,   414,   270,   271,   415,   416,   417,   573,
     418,   592,   419,   420,   421,   593,   422,   423,   424,    73,
     471,   425,   426,   555,   468,   119,   344,   427,   582,   428,
     120,   121,   469,   470,   522,   429,   122,   430,   431,   432,
     433,  1296,   494,   434,   123,   124,   435,   436,   437,   438,
     440,   125,   442,   471,   126,   127,   523,   443,  1297,   444,
     128,   445,   760,   446,   599,   129,   130,   447,   131,   132,
     133,   448,   134,   637,   449,   254,   235,   450,   451,   452,
     453,   135,   454,   455,   456,   136,   137,   457,   458,   459,
     460,   461,   502,  1298,  1299,   472,   138,   503,   545,   255,
     546,   728,   547,   600,   236,   548,   139,   549,   550,   551,
     552,   556,   237,   140,   557,   141,   558,   142,   559,   143,
     560,   144,   145,   561,   238,   239,   562,   563,   472,   240,
     241,   242,   564,   256,   146,   565,   601,  1158,   566,   147,
     148,   149,   257,   150,   151,   152,   567,   568,   153,  1300,
     602,  1159,   569,  1301,   243,   570,   571,   603,   572,  1160,
     583,   513,   587,   604,   258,   606,   607,   609,   259,   611,
     607,   614,   615,  1161,   154,   616,   260,   514,   617,   261,
     262,   618,   155,   156,   157,   158,   159,   160,   619,  1125,
     620,   639,   364,   515,   365,   621,   366,   824,   825,   826,
     827,   828,   829,   830,  1162,   622,  1163,   624,   367,   625,
    1126,   263,   626,   627,   161,   628,   629,   630,   631,  1127,
     632,   633,   634,   635,   368,  1275,   636,   516,   264,   640,
     641,   265,  1164,   642,   643,   644,   645,   647,   162,   163,
     164,   648,   165,   166,   167,   649,   650,   651,   168,   369,
    1128,   370,   652,   169,   653,   656,   266,   657,   371,   660,
     661,   662,   517,   666,   663,  1165,   670,  1166,   672,   372,
     673,   677,   693,   267,   268,   269,   669,   671,   674,  1129,
    1130,   676,   518,   678,   680,   681,  1167,  1131,   709,   682,
     683,   685,   327,   373,   686,   688,   689,   690,   519,   691,
     692,   270,   271,   694,  1168,   695,   328,   329,   696,  1169,
     330,   699,  1132,  1170,   700,   520,   521,   374,   701,   706,
    1171,   707,   708,   710,   712,  1172,   713,   935,  1133,   936,
     937,     2,     3,   716,   717,     4,   720,   375,   718,  1173,
     741,   719,  1174,   734,  1175,     5,   376,   742,     6,     7,
     721,   723,   724,   725,   771,     8,  1176,   726,   331,   727,
     730,   731,   735,  1177,   522,  1216,     9,   743,   736,    10,
      11,   738,   744,   745,   746,   332,   333,   334,   335,   336,
     749,   750,   751,   337,   753,   754,   523,   338,  1134,   755,
     377,   756,   757,   339,   762,   777,   759,    12,   763,   764,
     765,   768,    13,   769,   340,   341,   770,   772,   773,   774,
    1185,    14,  1186,  1187,   778,   779,   342,   776,   378,  1065,
    1066,  1067,  1068,  1069,  1070,  1071,   780,  1217,   781,   782,
     783,    15,    16,   784,   785,   786,   787,   788,   343,   789,
     798,   800,   799,   938,   939,   940,   801,   941,   942,    17,
     943,   944,   912,   945,   806,   946,  1218,  1235,   947,   802,
     807,   948,   949,  1219,   950,   808,    18,   809,   810,   951,
     811,   817,  1220,   952,   953,   954,   344,   812,   814,    19,
      20,   818,   819,   955,   820,   821,   822,   823,   956,   833,
     834,   835,   836,   837,   838,   839,   840,   841,  1221,    21,
    1222,  1223,   842,   843,   844,   847,   846,   848,   849,   851,
     852,   855,    22,   854,   856,  1224,   858,   861,   866,  1236,
      23,   862,  1225,   869,    24,   877,  1188,  1189,  1190,   872,
    1191,  1192,   865,  1193,  1194,   867,  1195,   868,  1196,   870,
     871,  1197,   873,   874,  1198,  1199,   875,  1200,  1237,   876,
     878,   879,  1201,   880,   881,  1238,  1202,  1203,  1204,   882,
     883,   884,   982,   885,  1239,   886,  1205,   887,   913,   914,
     915,  1206,   916,   917,    79,   918,   919,   888,   920,   889,
     921,   890,   891,   922,   892,   893,   923,   924,   894,   925,
    1240,   895,  1241,  1242,   926,    80,    81,   896,   927,   928,
     929,    82,   897,   898,   899,   900,   901,  1243,   930,   902,
     903,   904,   905,   931,  1244,   981,   906,   983,   907,   908,
     909,   910,   984,   985,   986,   987,   988,   990,   991,   993,
     994,   911,   934,   996,  1002,  1003,    83,    84,   959,  1005,
     960,  1008,    85,    86,  1009,   961,  1010,  1011,    87,    88,
      89,   962,   963,  1014,  1016,  1017,    90,    91,   964,   965,
     966,   967,   968,  1006,  1012,   969,   970,   971,   972,   973,
     974,   975,   976,   977,   978,   979,   980,   989,   992,   999,
    1018,    92,    93,   995,  1000,  1001,  1004,  1047,  1061,  1015,
    1007,  1013,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1045,  1046,  1063,  1049,  1050,  1048,
    1060,  1261,  1064,  1072,  1062,  1073,  1273,  1074,  1152,  1284,
    1285,  1286,   574,  1214,   310,  1079,  1080,  1081,  1233,  1213,
    1082,  1083,   748,  1307,  1084,   761,  1085,  1086,  1288,  1087,
    1287,   638,  1280,  1088,  1089,  1095,  1096,  1283,   729,  1282,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1108,  1109,  1110,
    1111,  1112,  1113,  1114,  1115,  1116,  1117,  1118,  1123,  1124,
    1137,  1138,  1139,  1140,  1151,  1141,  1142,  1143,  1144,  1145,
    1154,   740,   767,  1155,   816,  1156,  1157,  1180,  1181,  1182,
    1183,  1184,  1209,  1210,  1304,  1211,  1212,  1215,  1228,   805,
    1262,  1234,  1229,  1230,  1247,  1263,  1289,  1264,  1265,  1277,
    1276,  1266,  1290,  1291,  1292,  1281,   404,   733,   505,   463,
    1256,   655,   326,   665,  1255,     0,     0,     0,   554,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   659,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   585,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   589
};

static const yytype_int16 yycheck[] =
{
     635,   636,   315,     1,   317,     1,   319,   320,     8,    53,
     233,     1,     1,     1,     1,     1,     1,   213,     9,    10,
      11,   217,   233,     1,    22,    23,     1,     1,     1,   233,
      28,     1,     1,    29,     1,     1,    25,   112,   213,     1,
       1,    37,   217,    32,    49,   231,     1,   231,     1,   235,
     233,   235,   231,    49,    50,     1,   235,   233,    54,    55,
      56,     1,     1,     1,     1,    63,    64,     6,     7,    35,
     231,    69,    70,    12,   235,     1,   233,    75,    76,    77,
      35,    20,    21,    79,   128,    83,    84,     1,    27,    58,
      65,    30,    31,    81,    81,   233,    65,    36,    67,     1,
     413,   414,    41,    42,    65,    44,    45,    46,   421,    48,
     108,   109,   425,   102,    99,    81,   102,   430,    57,    65,
     433,   112,    61,    62,   102,   233,    81,    65,   102,   102,
     443,   444,   207,    72,  1090,  1091,  1092,     1,   123,     3,
     102,     5,   455,    82,   233,   458,   459,   231,     1,   102,
      89,   235,    91,    17,    93,   129,    95,   126,    97,    98,
       1,   233,   129,   129,   233,   102,   231,   233,   129,    33,
     235,   110,    25,    99,   129,   231,   115,   116,   117,   235,
     119,   120,   121,   188,   174,   124,   174,   174,   102,   129,
     233,   129,   129,   198,    58,   231,    60,   123,   198,   235,
     102,     1,   233,    67,   174,   231,    59,   231,   232,   235,
     233,   150,     1,   233,    78,    68,   233,    17,   233,   158,
     159,   160,   161,   162,   163,   231,    15,    16,   231,   235,
      19,   233,   194,    33,   232,   225,   232,    90,   102,   552,
       1,    94,   232,   232,   222,   232,   232,   232,   226,   102,
     233,   190,   105,   106,   232,   225,    17,   232,   232,   226,
     222,   102,   126,   232,   174,   232,   232,    67,   233,   222,
     232,   232,    33,     1,   234,   214,   215,   216,    67,   218,
     219,   220,   146,   234,   137,   224,   226,     1,     1,    17,
     229,   155,   194,   232,   213,    84,    85,    86,    87,    88,
     234,   154,   102,    92,   157,    33,    67,    96,   222,   622,
     234,   231,    25,   102,   627,   235,   234,   630,   232,    32,
     222,   634,   122,   231,   113,   114,   231,   235,   234,   182,
     235,   202,   203,    40,   234,   199,   125,   234,   138,    67,
     202,   203,   178,   179,    58,   234,   199,   200,   201,   234,
     234,    65,   234,    67,   234,   155,   156,   234,   147,   234,
     234,   122,   234,   227,    71,   234,    73,   234,   232,   130,
     131,   234,   231,   234,   227,   228,   234,   234,   234,   232,
     234,   222,   234,   234,   234,   226,   234,   234,   234,   102,
     151,   234,   234,   231,   122,     1,   185,   234,   231,   234,
       6,     7,   130,   131,   204,   234,    12,   234,   234,   234,
     234,   118,   126,   234,    20,    21,   234,   234,   234,   234,
     234,    27,   234,   151,    30,    31,   226,   234,   135,   234,
      36,   234,   232,   234,   127,    41,    42,   234,    44,    45,
      46,   234,    48,   232,   234,     1,     1,   234,   234,   234,
     234,    57,   234,   234,   234,    61,    62,   234,   234,   234,
     234,   234,   234,   170,   171,   226,    72,   234,   234,    25,
     234,   232,   234,   127,    29,   234,    82,   234,   234,   234,
     234,   234,    37,    89,   234,    91,   234,    93,   234,    95,
     234,    97,    98,   234,    49,    50,   234,   234,   226,    54,
      55,    56,   234,    59,   110,   234,   127,     4,   234,   115,
     116,   117,    68,   119,   120,   121,   234,   234,   124,   226,
     231,    18,   234,   230,    79,   234,   234,   112,   234,    26,
     234,     1,   234,   112,    90,   112,   112,   112,    94,   112,
     112,   112,   112,    40,   150,   213,   102,    17,   213,   105,
     106,   231,   158,   159,   160,   161,   162,   163,   231,    13,
     234,   231,     1,    33,     3,   234,     5,   139,   140,   141,
     142,   143,   144,   145,    71,   234,    73,   234,    17,   234,
      34,   137,   234,   234,   190,   234,   234,   234,   234,    43,
     234,   234,   234,   234,    33,  1230,   234,    67,   154,   234,
     234,   157,    99,   234,   234,   234,   234,   234,   214,   215,
     216,   234,   218,   219,   220,   234,   234,   234,   224,    58,
      74,    60,   234,   229,   234,   234,   182,   234,    67,   127,
     231,   234,   102,   213,   234,   132,   112,   134,   112,    78,
     127,   112,   234,   199,   200,   201,   213,   213,   213,   103,
     104,   213,   122,   112,   112,   213,   153,   111,   127,   213,
     213,   112,     1,   102,   112,   112,   112,   112,   138,   112,
     213,   227,   228,   213,   171,   234,    15,    16,   213,   176,
      19,   213,   136,   180,   213,   155,   156,   126,   213,   213,
     187,   213,   213,   112,   213,   192,   213,    49,   152,    51,
      52,     0,     1,   213,   213,     4,   234,   146,   231,   206,
     127,   231,   209,   231,   211,    14,   155,   127,    17,    18,
     234,   234,   234,   234,   127,    24,   223,   234,    67,   234,
     234,   234,   234,   230,   204,    73,    35,   231,   234,    38,
      39,   234,   231,   234,   234,    84,    85,    86,    87,    88,
     231,   234,   234,    92,   234,   234,   226,    96,   212,   234,
     199,   234,   234,   102,   231,   127,   234,    66,   234,   234,
     234,   213,    71,   213,   113,   114,   213,   213,   213,   213,
      49,    80,    51,    52,   213,   127,   125,   231,   227,   824,
     825,   826,   827,   828,   829,   830,   112,   135,   112,   127,
     127,   100,   101,   127,   127,   127,   127,   112,   147,   127,
     127,   231,   127,   165,   166,   167,   231,   169,   170,   118,
     172,   173,    49,   175,   213,   177,   164,    73,   180,   234,
     231,   183,   184,   171,   186,   233,   135,   127,   231,   191,
     231,   231,   180,   195,   196,   197,   185,   234,   234,   148,
     149,   231,   231,   205,   231,   231,   231,   231,   210,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   206,   168,
     208,   209,   231,   112,   112,   112,   234,   112,   112,   112,
     112,   112,   181,   127,   112,   223,   112,   231,   213,   135,
     189,   127,   230,   234,   193,   231,   165,   166,   167,   112,
     169,   170,   127,   172,   173,   127,   175,   127,   177,   127,
     127,   180,   127,   127,   183,   184,   127,   186,   164,   127,
     127,   127,   191,   231,   231,   171,   195,   196,   197,   127,
     127,   231,   213,   231,   180,   231,   205,   231,   165,   166,
     167,   210,   169,   170,     1,   172,   173,   231,   175,   231,
     177,   231,   231,   180,   231,   231,   183,   184,   231,   186,
     206,   231,   208,   209,   191,    22,    23,   231,   195,   196,
     197,    28,   231,   231,   231,   231,   231,   223,   205,   231,
     231,   231,   231,   210,   230,   127,   231,   234,   231,   231,
     231,   231,   127,   112,   127,   127,   127,   127,   127,   127,
     127,   231,   231,   112,   127,   127,    63,    64,   231,   127,
     231,   127,    69,    70,   127,   231,   127,   127,    75,    76,
      77,   231,   231,   127,   127,   127,    83,    84,   231,   231,
     231,   231,   231,   213,   213,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     127,   108,   109,   234,   231,   231,   231,   127,   127,   231,
     234,   234,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   127,   231,   231,   234,
     231,   112,   231,   231,   234,   231,   127,   231,   235,   133,
     133,   133,   272,  1044,    74,   231,   231,   231,  1055,  1042,
     231,   231,   509,  1306,   231,   524,   231,   231,  1270,   231,
    1268,   345,  1249,   231,   231,   231,   231,  1260,   473,  1258,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   221,   231,   231,   231,   231,   231,
     231,   496,   540,   231,   594,   231,   231,   231,   231,   231,
     231,   231,   231,   231,  1279,   231,   231,   231,   231,   578,
    1152,   231,   234,   234,   231,   231,  1272,   236,   236,   231,
     234,   236,   231,   231,   231,  1254,   115,   486,   228,   170,
    1122,   379,    94,   408,  1120,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   301
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   238,     0,     1,     4,    14,    17,    18,    24,    35,
      38,    39,    66,    71,    80,   100,   101,   118,   135,   148,
     149,   168,   181,   189,   193,   239,   244,   249,   273,   279,
     285,   299,   319,   343,   357,   372,   379,   383,   393,   402,
     423,   429,   435,   439,   445,   504,   521,   231,   232,   233,
     233,   320,   403,   430,   233,   440,   233,   358,   424,   344,
     233,   280,   300,   373,   233,   233,   394,   233,   233,   384,
       1,    25,    32,   102,   274,   275,   276,   277,   278,     1,
      22,    23,    28,    63,    64,    69,    70,    75,    76,    77,
      83,    84,   108,   109,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     233,   233,   233,     1,    65,   436,   437,   438,   233,     1,
       6,     7,    12,    20,    21,    27,    30,    31,    36,    41,
      42,    44,    45,    46,    48,    57,    61,    62,    72,    82,
      89,    91,    93,    95,    97,    98,   110,   115,   116,   117,
     119,   120,   121,   124,   150,   158,   159,   160,   161,   162,
     163,   190,   214,   215,   216,   218,   219,   220,   224,   229,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   497,   501,
     502,   503,   233,   233,   233,     1,    99,   123,   245,   246,
     247,   248,   233,   233,   233,     1,    29,    37,    49,    50,
      54,    55,    56,    79,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,     1,    25,    59,    68,    90,    94,
     102,   105,   106,   137,   154,   157,   182,   199,   200,   201,
     227,   228,   250,   251,   252,   253,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   233,     1,   225,   286,   287,   288,   289,   290,     1,
     102,   380,   381,   382,   233,   231,   234,   234,   234,   232,
     275,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   232,   506,     1,    15,    16,
      19,    67,    84,    85,    86,    87,    88,    92,    96,   102,
     113,   114,   125,   147,   185,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,     1,     3,     5,    17,    33,    58,
      60,    67,    78,   102,   126,   146,   155,   199,   227,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     418,   419,   420,   421,   422,     1,    65,   129,   431,   432,
     433,   434,   234,   232,   437,     1,   102,   129,   441,   442,
     443,   444,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   498,
     234,   494,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   232,   447,     1,    17,    33,    67,   122,   130,
     131,   151,   226,   359,   360,   361,   362,   363,   364,   365,
     369,   370,   371,     1,   129,   226,   425,   426,   427,   428,
       1,    58,    65,    67,   126,   345,   349,   350,   351,   355,
     356,   231,   234,   234,   232,   246,     1,    81,   174,   281,
     282,   283,   284,     1,    17,    33,    67,   102,   122,   138,
     155,   156,   204,   226,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   315,     1,    35,    81,   129,
     374,   375,   376,   377,   378,   234,   234,   234,   234,   234,
     234,   234,   234,   232,   523,   231,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   232,   251,     1,   102,   222,   395,   396,
     397,   398,   231,   234,   232,   287,   174,   234,   232,   381,
       1,   102,   222,   226,   385,   386,   387,   388,   389,   127,
     127,   127,   231,   112,   112,   213,   112,   112,   241,   112,
     241,   112,   241,   241,   112,   112,   213,   213,   231,   231,
     234,   234,   234,   340,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   232,   322,   231,
     234,   234,   234,   234,   234,   234,   415,   234,   234,   234,
     234,   234,   234,   234,   232,   405,   234,   234,   232,   432,
     127,   231,   234,   234,   232,   442,   213,   241,   241,   213,
     112,   213,   112,   127,   213,   241,   213,   112,   112,   241,
     112,   213,   213,   213,   241,   112,   112,   241,   112,   112,
     112,   112,   213,   234,   213,   234,   213,   241,   241,   213,
     213,   213,   213,   217,   213,   217,   213,   213,   213,   127,
     112,   241,   213,   213,   241,   241,   213,   213,   231,   231,
     234,   234,   366,   234,   234,   234,   234,   234,   232,   360,
     234,   234,   232,   426,   231,   234,   234,   346,   234,   232,
     350,   127,   127,   231,   231,   234,   234,   232,   282,   231,
     234,   234,   316,   234,   234,   234,   234,   234,   312,   234,
     232,   302,   231,   234,   234,   234,   232,   375,   213,   213,
     213,   127,   213,   213,   213,   241,   231,   127,   213,   127,
     112,   112,   127,   127,   127,   127,   127,   127,   112,   127,
     202,   203,   254,   255,   202,   203,   256,   257,   127,   127,
     231,   231,   234,   399,   232,   396,   213,   231,   233,   127,
     231,   231,   234,   390,   234,   232,   386,   231,   231,   231,
     231,   231,   231,   231,   139,   140,   141,   142,   143,   144,
     145,   240,   241,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   112,   112,   241,   234,   112,   112,   112,
     241,   112,   112,   241,   127,   112,   112,   241,   112,   243,
     243,   231,   127,   178,   179,   127,   213,   127,   127,   234,
     127,   127,   112,   127,   127,   127,   127,   231,   127,   127,
     231,   231,   127,   127,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,    49,   165,   166,   167,   169,   170,   172,   173,
     175,   177,   180,   183,   184,   186,   191,   195,   196,   197,
     205,   210,   499,   500,   231,    49,    51,    52,   165,   166,
     167,   169,   170,   172,   173,   175,   177,   180,   183,   184,
     186,   191,   195,   196,   197,   205,   210,   495,   496,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   127,   213,   234,   127,   112,   127,   127,   127,   231,
     127,   127,   231,   127,   127,   234,   112,   353,   354,   231,
     231,   231,   127,   127,   231,   127,   213,   234,   127,   127,
     127,   127,   213,   234,   127,   231,   127,   127,   127,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   235,   231,   235,   231,   231,   127,   234,   231,
     231,     1,   102,   194,   222,   291,   292,   293,   294,   295,
     231,   127,   234,   127,   231,   240,   240,   240,   240,   240,
     240,   240,   231,   231,   231,    53,   128,   341,   342,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
       9,    10,    11,   242,   243,   231,   231,   231,   231,   231,
     231,   231,   231,   231,     8,   198,   416,   417,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     235,   231,   235,   231,   231,    13,    34,    43,    74,   103,
     104,   111,   136,   152,   212,   367,   368,   231,   231,   231,
     231,   231,   231,   231,   231,   231,    49,   188,   198,   347,
     348,   221,   235,   352,   231,   231,   231,   231,     4,    18,
      26,    40,    71,    73,    99,   132,   134,   153,   171,   176,
     180,   187,   192,   206,   209,   211,   223,   230,   317,   318,
     231,   231,   231,   231,   231,    49,    51,    52,   165,   166,
     167,   169,   170,   172,   173,   175,   177,   180,   183,   184,
     186,   191,   195,   196,   197,   205,   210,   313,   314,   231,
     231,   231,   231,   255,   257,   231,    73,   135,   164,   171,
     180,   206,   208,   209,   223,   230,   400,   401,   231,   234,
     234,   296,   232,   292,   231,    73,   135,   164,   171,   180,
     206,   208,   209,   223,   230,   391,   392,   231,   231,   235,
     242,   242,   242,   231,   235,   500,   496,   231,   235,   231,
     235,   112,   354,   231,   236,   236,   236,   231,   235,   231,
     235,   231,   235,   127,   207,   243,   234,   231,   231,   235,
     342,   417,   368,   348,   133,   133,   133,   318,   314,   401,
     231,   231,   231,    40,    71,    73,   118,   135,   170,   171,
     226,   230,   297,   298,   392,   231,   235,   298
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   237,   238,   238,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   240,   240,   241,
     241,   241,   241,   241,   241,   241,   241,   242,   242,   243,
     243,   243,   243,   244,   245,   245,   246,   246,   246,   247,
     248,   249,   250,   250,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   252,   253,   254,   254,   255,   255,   256,   256,
     257,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   274,
     275,   275,   275,   275,   276,   277,   278,   280,   279,   281,
     281,   282,   282,   282,   283,   284,   285,   286,   286,   287,
     287,   287,   288,   290,   289,   291,   291,   292,   292,   292,
     292,   293,   294,   294,   296,   295,   297,   297,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   300,   299,   301,
     301,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     312,   311,   313,   313,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   316,   315,   317,   317,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   320,   319,   321,   321,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   323,   324,   325,   326,   327,
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
     447,   447,   447,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   474,   475,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   494,   493,   495,   495,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   498,   497,   499,
     499,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   501,   502,   503,   504,   505,   505,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   522,   523,
     523,   523,   523,   523,   523,   523,   523,   523,   524,   525,
     526,   527,   528,   529,   530,   531
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
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
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
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
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
        case 27:
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2857 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2869 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2905 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2923 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 440 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 480 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 486 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 495 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2986 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 501 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2997 "conf_parser.c" /* yacc.c:1646  */
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
#line 3042 "conf_parser.c" /* yacc.c:1646  */
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
#line 3103 "conf_parser.c" /* yacc.c:1646  */
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
#line 3134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 637 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3145 "conf_parser.c" /* yacc.c:1646  */
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
#line 3163 "conf_parser.c" /* yacc.c:1646  */
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
#line 3181 "conf_parser.c" /* yacc.c:1646  */
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
#line 3193 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 684 "conf_parser.y" /* yacc.c:1646  */
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
#line 3210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 698 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3222 "conf_parser.c" /* yacc.c:1646  */
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
#line 3253 "conf_parser.c" /* yacc.c:1646  */
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
#line 3286 "conf_parser.c" /* yacc.c:1646  */
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
#line 3314 "conf_parser.c" /* yacc.c:1646  */
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
#line 3339 "conf_parser.c" /* yacc.c:1646  */
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
#line 3364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3385 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 860 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 869 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 881 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3418 "conf_parser.c" /* yacc.c:1646  */
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
#line 3435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 902 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 908 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 923 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 929 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3471 "conf_parser.c" /* yacc.c:1646  */
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
#line 3484 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 949 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3495 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 957 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 960 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 965 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 972 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 976 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3538 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 980 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 984 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3556 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 988 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 996 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1004 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3601 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3613 "conf_parser.c" /* yacc.c:1646  */
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
#line 3689 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3698 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1113 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3707 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3716 "conf_parser.c" /* yacc.c:1646  */
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
#line 3730 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1136 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3739 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1142 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3748 "conf_parser.c" /* yacc.c:1646  */
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
#line 3762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1159 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3771 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1165 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3780 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1172 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3789 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1176 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3798 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1180 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3807 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1184 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1188 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3834 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1196 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3843 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1208 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3870 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1216 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1224 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1228 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1252 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3969 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3987 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3996 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4005 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4023 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4041 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4050 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4059 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4095 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4113 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4122 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4131 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4140 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4158 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1345 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4167 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1349 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4185 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4194 "conf_parser.c" /* yacc.c:1646  */
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
#line 4211 "conf_parser.c" /* yacc.c:1646  */
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
#line 4264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1448 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4273 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1454 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4282 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1460 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4291 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1466 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1472 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1478 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1484 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4327 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1490 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1496 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4345 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1502 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4354 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1508 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1515 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1521 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1527 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1533 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4403 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1542 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1551 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1558 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1562 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1572 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1578 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1584 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1588 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4477 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1592 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1600 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4492 "conf_parser.c" /* yacc.c:1646  */
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
#line 4511 "conf_parser.c" /* yacc.c:1646  */
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
#line 4532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1637 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1643 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1652 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4559 "conf_parser.c" /* yacc.c:1646  */
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
#line 4600 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1705 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4609 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1711 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4618 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1717 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4627 "conf_parser.c" /* yacc.c:1646  */
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
#line 4641 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1734 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4650 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1741 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1745 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4668 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1749 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4677 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1753 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4686 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1757 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4695 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1761 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4704 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1765 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4713 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1769 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4722 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1773 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4731 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1777 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4740 "conf_parser.c" /* yacc.c:1646  */
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
#line 4757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1797 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4769 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1806 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4781 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1819 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1826 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4804 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1837 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4813 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4822 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1849 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4831 "conf_parser.c" /* yacc.c:1646  */
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
#line 4846 "conf_parser.c" /* yacc.c:1646  */
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
#line 4862 "conf_parser.c" /* yacc.c:1646  */
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
#line 4879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1907 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4888 "conf_parser.c" /* yacc.c:1646  */
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
#line 4910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1932 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1943 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1951 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1955 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1963 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1967 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1971 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1975 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5009 "conf_parser.c" /* yacc.c:1646  */
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
#line 5023 "conf_parser.c" /* yacc.c:1646  */
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
#line 5038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2008 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5065 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5146 "conf_parser.c" /* yacc.c:1646  */
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
#line 5160 "conf_parser.c" /* yacc.c:1646  */
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
#line 5226 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2155 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5235 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2161 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5244 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2167 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5253 "conf_parser.c" /* yacc.c:1646  */
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
#line 5269 "conf_parser.c" /* yacc.c:1646  */
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
#line 5285 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2199 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2205 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5303 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2211 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2215 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5323 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2223 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5331 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5349 "conf_parser.c" /* yacc.c:1646  */
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
#line 5363 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2250 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5390 "conf_parser.c" /* yacc.c:1646  */
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
#line 5404 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2283 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5413 "conf_parser.c" /* yacc.c:1646  */
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
#line 5438 "conf_parser.c" /* yacc.c:1646  */
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
#line 5461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5479 "conf_parser.c" /* yacc.c:1646  */
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
#line 5505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2371 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2377 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5523 "conf_parser.c" /* yacc.c:1646  */
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
#line 5540 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2408 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5549 "conf_parser.c" /* yacc.c:1646  */
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
#line 5571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2434 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5580 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2440 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2506 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5597 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2511 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2517 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2523 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2529 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2535 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5641 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2540 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2545 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5657 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2550 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2555 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2560 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5681 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2565 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5689 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2570 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2575 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number);
}
#line 5705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2580 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5713 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2585 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2590 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5729 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2595 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5737 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2600 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5746 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2606 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5760 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2617 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2622 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_connect_block = yylval.number;
}
#line 5776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2627 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2632 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2637 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2642 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5808 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2650 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2655 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2658 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2663 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5848 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2668 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2673 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2678 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2683 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2688 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2693 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2698 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2703 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2708 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2713 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.use_egd = yylval.number;
}
#line 5928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2718 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
#line 5940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2727 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 5952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2736 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 5960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2741 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 5968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2746 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_count = (yyvsp[-1].number);
}
#line 5976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2751 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = (yyvsp[-1].number);
}
#line 5984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2756 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 5992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 6000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2765 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 6008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2768 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 6016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2771 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 6024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2774 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 6032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 6040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDECHANS;
}
#line 6048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2783 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 6064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2789 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2798 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2830 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2836 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6184 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2839 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2845 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2851 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2854 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2860 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2869 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2878 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2884 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2893 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2898 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2903 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2908 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2937 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2942 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2947 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2952 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2957 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2962 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2967 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2972 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2977 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 2982 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 2987 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2992 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2997 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3002 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3024 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3030 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6490 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3036 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6499 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3042 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6508 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3057 "conf_parser.y" /* yacc.c:1646  */
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
#line 6537 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3071 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3077 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6555 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6559 "conf_parser.c" /* yacc.c:1646  */
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
