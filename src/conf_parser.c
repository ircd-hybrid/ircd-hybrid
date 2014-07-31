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
    T_MAX_CLIENTS = 441,
    T_NCHANGE = 442,
    T_NONONREG = 443,
    T_RECVQ = 444,
    T_REJ = 445,
    T_RESTART = 446,
    T_SERVER = 447,
    T_SERVICE = 448,
    T_SERVICES_NAME = 449,
    T_SERVNOTICE = 450,
    T_SET = 451,
    T_SHARED = 452,
    T_SIZE = 453,
    T_SKILL = 454,
    T_SOFTCALLERID = 455,
    T_SPY = 456,
    T_SSL = 457,
    T_SSL_CIPHER_LIST = 458,
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
#define T_MAX_CLIENTS 441
#define T_NCHANGE 442
#define T_NONONREG 443
#define T_RECVQ 444
#define T_REJ 445
#define T_RESTART 446
#define T_SERVER 447
#define T_SERVICE 448
#define T_SERVICES_NAME 449
#define T_SERVNOTICE 450
#define T_SET 451
#define T_SHARED 452
#define T_SIZE 453
#define T_SKILL 454
#define T_SOFTCALLERID 455
#define T_SPY 456
#define T_SSL 457
#define T_SSL_CIPHER_LIST 458
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
#define YYLAST   1371

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  657
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1298

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
     471,   472,   475,   517,   575,   604,   612,   626,   654,   669,
     684,   693,   707,   716,   744,   774,   799,   821,   843,   852,
     854,   854,   855,   856,   857,   858,   860,   869,   878,   891,
     890,   908,   908,   909,   909,   909,   911,   917,   926,   927,
     927,   929,   929,   930,   932,   939,   939,   952,   953,   955,
     955,   956,   956,   958,   966,   969,   975,   974,   980,   980,
     981,   985,   989,   993,   997,  1001,  1005,  1009,  1013,  1024,
    1023,  1109,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,
    1117,  1118,  1119,  1120,  1122,  1128,  1134,  1140,  1151,  1157,
    1163,  1174,  1181,  1180,  1186,  1186,  1187,  1191,  1195,  1199,
    1203,  1207,  1211,  1215,  1219,  1223,  1227,  1231,  1235,  1239,
    1243,  1247,  1251,  1255,  1259,  1263,  1267,  1271,  1278,  1277,
    1283,  1283,  1284,  1288,  1292,  1296,  1300,  1304,  1308,  1312,
    1316,  1320,  1324,  1328,  1332,  1336,  1340,  1344,  1348,  1352,
    1356,  1360,  1364,  1368,  1372,  1383,  1382,  1444,  1444,  1445,
    1446,  1447,  1448,  1449,  1450,  1451,  1452,  1453,  1454,  1455,
    1456,  1457,  1457,  1458,  1459,  1460,  1461,  1463,  1469,  1475,
    1481,  1487,  1493,  1499,  1505,  1511,  1517,  1523,  1530,  1536,
    1542,  1548,  1557,  1567,  1566,  1572,  1572,  1573,  1577,  1588,
    1587,  1594,  1593,  1598,  1598,  1599,  1603,  1607,  1613,  1613,
    1614,  1614,  1614,  1614,  1614,  1616,  1616,  1618,  1618,  1620,
    1634,  1652,  1658,  1668,  1667,  1709,  1709,  1710,  1711,  1712,
    1713,  1714,  1715,  1716,  1717,  1718,  1720,  1726,  1732,  1738,
    1750,  1749,  1755,  1755,  1756,  1760,  1764,  1768,  1772,  1776,
    1780,  1784,  1788,  1792,  1798,  1812,  1821,  1835,  1834,  1849,
    1849,  1850,  1850,  1850,  1850,  1852,  1858,  1864,  1874,  1876,
    1876,  1877,  1877,  1879,  1895,  1894,  1919,  1919,  1920,  1920,
    1920,  1920,  1922,  1928,  1948,  1947,  1953,  1953,  1954,  1958,
    1962,  1966,  1970,  1974,  1978,  1982,  1986,  1990,  2000,  1999,
    2020,  2020,  2021,  2021,  2021,  2023,  2030,  2029,  2035,  2035,
    2036,  2040,  2044,  2048,  2052,  2056,  2060,  2064,  2068,  2072,
    2082,  2081,  2153,  2153,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2170,
    2176,  2182,  2188,  2201,  2214,  2220,  2226,  2230,  2239,  2238,
    2243,  2243,  2244,  2248,  2254,  2265,  2271,  2277,  2283,  2299,
    2298,  2324,  2324,  2325,  2325,  2325,  2327,  2347,  2357,  2356,
    2383,  2383,  2384,  2384,  2384,  2386,  2392,  2401,  2403,  2403,
    2404,  2404,  2406,  2424,  2423,  2446,  2446,  2447,  2447,  2447,
    2449,  2455,  2464,  2467,  2467,  2468,  2469,  2470,  2471,  2472,
    2473,  2474,  2475,  2476,  2477,  2478,  2479,  2480,  2481,  2482,
    2483,  2484,  2485,  2486,  2487,  2488,  2489,  2490,  2491,  2492,
    2493,  2494,  2495,  2496,  2497,  2498,  2499,  2500,  2501,  2502,
    2503,  2504,  2505,  2506,  2507,  2508,  2509,  2510,  2511,  2512,
    2513,  2514,  2515,  2516,  2517,  2518,  2521,  2526,  2531,  2536,
    2542,  2548,  2554,  2560,  2565,  2570,  2575,  2580,  2585,  2590,
    2595,  2600,  2605,  2610,  2615,  2620,  2625,  2631,  2642,  2647,
    2652,  2657,  2662,  2667,  2672,  2675,  2680,  2683,  2688,  2693,
    2698,  2703,  2708,  2713,  2718,  2723,  2728,  2733,  2738,  2747,
    2752,  2757,  2762,  2768,  2767,  2772,  2772,  2773,  2776,  2779,
    2782,  2785,  2788,  2791,  2794,  2797,  2800,  2803,  2806,  2809,
    2812,  2815,  2818,  2821,  2824,  2827,  2830,  2833,  2836,  2842,
    2841,  2846,  2846,  2847,  2850,  2853,  2856,  2859,  2862,  2865,
    2868,  2871,  2874,  2877,  2880,  2883,  2886,  2889,  2892,  2895,
    2898,  2901,  2904,  2909,  2914,  2919,  2928,  2931,  2931,  2932,
    2933,  2934,  2935,  2936,  2937,  2938,  2939,  2940,  2941,  2942,
    2943,  2944,  2945,  2946,  2948,  2953,  2958,  2963,  2968,  2973,
    2978,  2983,  2988,  2993,  2998,  3003,  3008,  3013,  3021,  3024,
    3024,  3025,  3026,  3027,  3028,  3029,  3030,  3031,  3032,  3033,
    3035,  3041,  3047,  3053,  3059,  3068,  3083,  3089
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
  "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS", "T_INVISIBLE", "T_IPV4",
  "T_IPV6", "T_LOCOPS", "T_LOG", "T_MAX_CLIENTS", "T_NCHANGE",
  "T_NONONREG", "T_RECVQ", "T_REJ", "T_RESTART", "T_SERVER", "T_SERVICE",
  "T_SERVICES_NAME", "T_SERVNOTICE", "T_SET", "T_SHARED", "T_SIZE",
  "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL", "T_SSL_CIPHER_LIST",
  "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV",
  "T_UNXLINE", "T_WALLOP", "T_WALLOPS", "T_WEBIRC", "TBOOL",
  "THROTTLE_COUNT", "THROTTLE_TIME", "TKLINE_EXPIRE_NOTICES", "TMASKED",
  "TRUE_NO_OPER_FLOOD", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "TYPE",
  "UNKLINE", "USE_EGD", "USE_LOGGING", "USER", "VHOST", "VHOST6",
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
  "general_entry", "general_items", "general_item", "general_away_count",
  "general_away_time", "general_max_watch", "general_cycle_on_host_change",
  "general_gline_enable", "general_gline_duration",
  "general_gline_request_duration", "general_gline_min_cidr",
  "general_gline_min_cidr6", "general_tkline_expire_notices",
  "general_kill_chase_time_limit", "general_hide_spoof_ips",
  "general_ignore_bogus_ts", "general_failed_oper_notice",
  "general_anti_nick_flood", "general_max_nick_time",
  "general_max_nick_changes", "general_max_accept",
  "general_anti_spam_exit_message_time", "general_ts_warn_delta",
  "general_ts_max_delta", "general_havent_read_conf",
  "general_invisible_on_connect", "general_warn_no_connect_block",
  "general_stats_e_disabled", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_u_oper_only",
  "general_stats_k_oper_only", "general_stats_i_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_opers_bypass_callerid", "general_pace_wait_simple",
  "general_short_motd", "general_no_oper_flood",
  "general_true_no_oper_flood", "general_oper_pass_resv",
  "general_dots_in_ident", "general_max_targets", "general_services_name",
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

#define YYPACT_NINF -790

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-790)))

#define YYTABLE_NINF -116

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -790,   639,  -790,  -150,  -213,  -210,  -790,  -790,  -790,  -207,
    -790,  -192,  -790,  -790,  -790,  -189,  -790,  -790,  -790,  -187,
    -179,  -790,  -163,  -157,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,    26,
     926,  -142,  -134,  -121,    16,  -116,   403,  -113,  -108,   -95,
       9,   -83,   -78,   -63,   769,   372,   -54,     4,    10,   -50,
     -53,   -33,   -31,   -16,    11,  -790,  -790,  -790,  -790,  -790,
     -14,    -9,     3,    30,    35,    55,    65,    72,    76,    79,
      84,    91,    93,    95,   156,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
     667,   545,    20,  -790,    97,    12,  -790,  -790,    41,  -790,
     102,   103,   112,   119,   131,   132,   133,   136,   137,   140,
     141,   143,   144,   145,   146,   148,   149,   150,   152,   163,
     164,   167,   168,   169,   171,   172,   173,   174,  -790,   177,
    -790,   180,   182,   184,   185,   188,   190,   193,   197,   200,
     202,   206,   210,   214,   218,   220,   223,   224,   226,   227,
      42,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,   420,    46,   295,    45,   229,   231,    23,  -790,
    -790,  -790,    14,   437,    21,  -790,   235,   236,   237,   239,
     240,   244,   247,   248,   291,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,    70,   250,   251,   252,   254,   256,
     257,   258,   259,   261,   263,   267,   271,   273,   274,   275,
     276,   278,    92,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,   122,   109,   279,    38,  -790,  -790,  -790,   305,  -790,
     280,    36,  -790,  -790,   128,  -790,   120,   125,   260,   199,
    -790,   331,   402,   304,   405,   413,   416,   413,   421,   413,
     413,   422,   423,   325,   326,   309,  -790,   312,   311,   313,
     315,  -790,   317,   320,   323,   328,   329,   337,   338,   340,
     342,   344,   347,   348,   349,   196,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,   353,   352,   354,   357,   359,   362,
     364,  -790,   367,   368,   369,   370,   374,   375,   376,   272,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,   377,   378,    27,  -790,
    -790,  -790,   431,   382,  -790,  -790,   386,   390,    18,  -790,
    -790,  -790,   366,   413,   502,   413,   413,   415,   512,   417,
     515,   418,   413,   425,   519,   520,   413,   521,   429,   432,
     434,   413,   530,   537,   413,   538,   539,   542,   543,   447,
     427,   449,   430,   453,   413,   413,   457,   458,   459,  -177,
    -158,   461,   462,   464,   549,   567,   413,   469,   470,   413,
     413,   473,   456,  -790,   468,   466,   467,  -790,   472,   474,
     475,   477,   480,   155,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,   482,   485,   107,  -790,  -790,  -790,
     491,   490,   492,  -790,   493,  -790,     8,  -790,  -790,  -790,
    -790,  -790,   561,   566,   497,  -790,   499,   498,   500,    15,
    -790,  -790,  -790,   504,   505,   506,  -790,   516,   518,   524,
     532,   534,  -790,   535,   211,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,   507,   540,   544,   546,
      13,  -790,  -790,  -790,  -790,   533,   536,   551,   574,   560,
     564,   568,   413,   548,  -790,  -790,   602,   571,   604,   637,
     671,   657,   658,   659,   662,   663,   666,   668,   670,   679,
     672,   673,   675,   565,  -790,   576,   575,  -790,    94,  -790,
    -790,  -790,  -790,   592,   579,  -790,   581,   683,   584,  -790,
     586,   585,  -790,   589,    71,  -790,  -790,  -790,  -790,   587,
     597,   599,  -790,   600,   608,   611,   618,   249,   622,   624,
     626,   627,   631,   635,   640,   641,   642,   644,  -790,  -790,
     756,   763,   413,   647,   770,   773,   775,   413,   777,   778,
     413,   765,   781,   788,   413,   789,   789,   674,  -790,  -790,
     782,   -55,   783,   693,   784,   796,   695,   801,   803,   793,
     804,   807,   809,   810,   710,  -790,   811,   814,   713,  -790,
     714,  -790,   820,   824,   723,  -790,   724,   727,   728,   729,
     730,   731,   732,   733,   734,   735,   736,   737,   738,   739,
     740,   741,   742,   743,   744,   745,   746,   748,   749,   750,
     751,   752,   753,   754,   747,   755,   664,   757,   758,   759,
     762,   764,   768,   771,   776,   779,   785,   786,   787,   790,
     791,   792,   794,   795,   797,   798,   799,   800,  -790,  -790,
     849,   774,   760,   867,   886,   872,   877,   879,   802,  -790,
     880,   884,   808,  -790,  -790,   885,   890,   806,   901,   812,
    -790,   813,   815,  -790,  -790,   891,   895,   816,  -790,  -790,
     898,   819,   817,   905,   906,   909,   912,   829,   818,   916,
     822,  -790,  -790,   919,   920,   921,   823,  -790,   825,   826,
     827,   828,   830,   831,   832,   833,  -790,   834,   835,   836,
     837,   838,   839,   840,   841,   842,   843,   844,   845,   846,
     847,   848,   850,   851,  -790,  -790,   931,   821,   852,  -790,
     853,  -790,    83,   854,  -790,  -790,   951,   855,   957,   856,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,   413,   413,
     413,   413,   413,   413,   413,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,   857,   859,   860,
     -52,   861,   862,   863,   864,   865,   866,   868,   869,   870,
     871,   873,   345,   874,   875,  -790,   876,   878,   881,   882,
     883,   887,   888,     0,   889,   892,   893,   894,   896,   897,
     899,  -790,   900,   902,  -790,  -790,   903,   904,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -174,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -169,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,   907,   908,   591,   910,   911,
     913,   914,   915,  -790,   917,   918,  -790,   922,   923,   -26,
     929,   924,  -790,  -790,  -790,  -790,   925,   927,  -790,   930,
     932,   514,   933,   934,   935,   936,   937,   709,   938,  -790,
     939,   940,   941,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,   942,
     638,  -790,  -790,   943,   928,   944,  -790,   106,  -790,  -790,
    -790,  -790,  -790,   945,   692,   946,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -168,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,   789,   789,   789,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -162,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,   747,  -790,   664,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,   -64,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,   -62,  -790,   984,   901,   948,  -790,  -790,  -790,  -790,
    -790,   947,  -790,  -790,   949,  -790,  -790,  -790,  -790,   950,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
     -46,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,   -40,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,   -20,  -790,  -790,   974,
     -96,   953,   958,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,   -12,  -790,  -790,  -790,   -52,
    -790,  -790,  -790,  -790,     0,  -790,  -790,  -790,   591,  -790,
     -26,  -790,  -790,  -790,   973,   975,   976,  -790,   514,  -790,
     709,  -790,   638,   959,   960,   961,   517,  -790,  -790,   692,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,    67,  -790,  -790,  -790,   517,  -790
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   215,   380,   428,     0,
     443,     0,   283,   419,   259,     0,    99,   139,   317,     0,
       0,   358,     0,     0,   334,     3,    23,    11,     4,    24,
       5,     6,     8,     9,    10,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    21,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    94,    93,   623,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   608,   622,   610,   611,   612,
     613,   614,   615,   609,   616,   617,   618,   619,   620,   621,
       0,     0,     0,   441,     0,     0,   439,   440,     0,   505,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   579,     0,
     553,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   454,   455,   456,   502,   504,   496,   497,   498,   499,
     500,   495,   467,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   492,   468,   469,   501,   471,   476,   477,
     472,   474,   473,   485,   486,   475,   478,   479,   480,   481,
     470,   483,   503,   493,   494,   490,   491,   484,   482,   488,
     489,   487,     0,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,     0,   649,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   640,   641,   642,   643,   644,
     647,   645,   646,   648,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    68,    65,    63,    69,    70,    64,
      54,    67,    57,    58,    59,    55,    66,    60,    61,    62,
      56,     0,     0,     0,     0,   110,   111,   112,     0,   332,
       0,     0,   330,   331,     0,    95,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   607,     0,     0,     0,
       0,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   218,   219,   222,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   220,   221,
     223,   233,   234,   235,     0,     0,     0,     0,     0,     0,
       0,   408,     0,     0,     0,     0,     0,     0,     0,     0,
     383,   384,   385,   386,   387,   388,   389,   391,   390,   393,
     397,   394,   395,   396,   392,   434,     0,     0,     0,   431,
     432,   433,     0,     0,   438,   449,     0,     0,     0,   446,
     447,   448,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   453,     0,     0,     0,   300,     0,     0,
       0,     0,     0,     0,   286,   287,   288,   289,   294,   290,
     291,   292,   293,   425,     0,     0,     0,   422,   423,   424,
       0,     0,     0,   261,     0,   271,     0,   269,   270,   272,
     273,    48,     0,     0,     0,    44,     0,     0,     0,     0,
     102,   103,   104,     0,     0,     0,   188,     0,     0,     0,
       0,     0,   162,     0,     0,   142,   143,   144,   145,   148,
     149,   150,   151,   147,   146,   152,     0,     0,     0,     0,
       0,   320,   321,   322,   323,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   639,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,   366,     0,   361,
     362,   363,   113,     0,     0,   109,     0,     0,     0,   329,
       0,     0,   344,     0,     0,   337,   338,   339,   340,     0,
       0,     0,    89,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   606,   236,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   217,   398,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   382,     0,     0,     0,   430,
       0,   437,     0,     0,     0,   445,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   452,   295,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   285,
       0,     0,     0,   421,   274,     0,     0,     0,     0,     0,
     268,     0,     0,    43,   105,     0,     0,     0,   101,   153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,   324,     0,     0,     0,     0,   319,     0,     0,
       0,     0,     0,     0,     0,     0,   638,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,   364,     0,     0,     0,   360,
       0,   108,     0,     0,   328,   341,     0,     0,     0,     0,
     336,    98,    97,    96,   633,   632,   624,   625,    27,    27,
      27,    27,    27,    27,    27,    29,    28,   626,   636,   637,
     627,   628,   629,   631,   630,   634,   635,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   381,     0,     0,   429,   442,     0,     0,   444,   520,
     524,   506,   507,   539,   509,   605,   550,   546,   519,   511,
     510,   513,   514,   512,   527,   517,   518,   528,   516,   523,
     522,   521,   547,   508,   603,   604,   543,   589,   583,   599,
     584,   585,   586,   594,   602,   587,   596,   600,   590,   601,
     591,   595,   588,   598,   593,   592,   597,     0,   582,   545,
     562,   563,   564,   557,   575,   558,   559,   560,   570,   578,
     561,   572,   576,   566,   577,   567,   571,   565,   574,   569,
     568,   573,     0,   556,   540,   538,   541,   549,   542,   530,
     536,   537,   534,   535,   531,   532,   533,   548,   551,   552,
     515,   544,   526,   525,   529,     0,     0,     0,     0,     0,
       0,     0,     0,   284,     0,     0,   420,     0,     0,     0,
     279,   275,   278,   260,    49,    50,     0,     0,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,     0,     0,   318,   651,   650,   656,   654,   657,   652,
     653,   655,    80,    88,    79,    86,    87,    78,    82,    81,
      73,    72,    77,    74,    76,    85,    75,    83,    84,     0,
       0,   359,   114,     0,     0,     0,   126,     0,   118,   119,
     121,   120,   333,     0,     0,     0,   335,    30,    31,    32,
      33,    34,    35,    36,   248,   249,   240,   258,   257,     0,
     256,   241,   243,   245,   252,   244,   242,   251,   237,   250,
     239,   238,    37,    37,    37,    39,    38,   246,   247,   403,
     406,   407,   417,   414,   400,   415,   412,   413,     0,   411,
     416,   399,   405,   402,   404,   418,   401,   435,   436,   450,
     451,   580,     0,   554,     0,   298,   299,   308,   305,   310,
     306,   307,   313,   309,   311,   304,   312,     0,   303,   297,
     316,   315,   314,   296,   427,   426,   282,   281,   266,   267,
     265,     0,   264,     0,     0,     0,   106,   107,   161,   157,
     208,   195,   205,   204,   193,   198,   214,   207,   212,   197,
     200,   209,   211,   206,   213,   201,   203,   210,   199,   202,
       0,   191,   154,   156,   158,   159,   160,   171,   172,   173,
     166,   184,   167,   168,   169,   179,   187,   170,   181,   185,
     175,   186,   176,   180,   174,   183,   178,   177,   182,     0,
     165,   155,   327,   325,   326,   365,   370,   376,   379,   372,
     378,   373,   377,   375,   371,   374,     0,   369,   122,     0,
       0,     0,     0,   117,   342,   348,   354,   357,   350,   356,
     351,   355,   353,   349,   352,     0,   347,   343,   254,     0,
      40,    41,    42,   409,     0,   581,   555,   301,     0,   262,
       0,   280,   277,   276,     0,     0,     0,   189,     0,   163,
       0,   367,     0,     0,     0,     0,     0,   116,   345,     0,
     255,   410,   302,   263,   194,   192,   196,   190,   164,   368,
     123,   125,   124,   132,   137,   136,   131,   134,   138,   135,
     130,   133,     0,   129,   346,   127,     0,   128
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -790,  -790,  -790,  -789,  -313,  -723,  -635,  -790,  -790,   952,
    -790,  -790,  -790,  -790,   954,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  1041,  -790,  -790,  -790,  -790,  -790,
    -790,   607,  -790,  -790,  -790,  -790,   858,  -790,  -790,  -790,
    -790,    74,  -790,  -790,  -790,  -790,  -790,  -170,  -790,  -790,
    -790,   593,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -138,  -790,  -790,  -790,  -129,  -790,  -790,
    -790,   955,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -107,  -790,  -790,  -790,  -790,  -790,  -114,  -790,   651,
    -790,  -790,  -790,    -7,  -790,  -790,  -790,  -790,  -790,   678,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -105,  -790,  -790,
    -790,  -790,  -790,  -790,   615,  -790,  -790,  -790,  -790,  -790,
     956,  -790,  -790,  -790,  -790,   563,  -790,  -790,  -790,  -790,
    -790,  -109,  -790,  -790,  -790,   562,  -790,  -790,  -790,  -790,
     -87,  -790,  -790,  -790,   805,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,   -56,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,   696,  -790,  -790,  -790,  -790,
    -790,   962,  -790,  -790,  -790,  -790,  1066,  -790,  -790,  -790,
    -790,   963,  -790,  -790,  -790,  -790,  1023,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,    80,  -790,  -790,  -790,    85,
    -790,  -790,  -790,  -790,  -790,  1101,  -790,  -790,  -790,  -790,
    -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790,  -790,   964,  -790,  -790,  -790,  -790,  -790,  -790,  -790,
    -790
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   825,   826,  1085,  1086,    26,   228,   229,
     230,   231,    27,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,    28,    74,    75,    76,    77,    78,    29,    61,
     509,   510,   511,   512,    30,   294,   295,   296,   297,   298,
    1047,  1048,  1049,  1050,  1051,  1221,  1292,  1293,    31,    62,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   758,  1199,  1200,   535,   752,  1170,  1171,    32,    51,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   623,
    1069,  1070,    33,    59,   495,   737,  1141,  1142,   496,   497,
     498,  1145,   991,   992,   499,   500,    34,    57,   473,   474,
     475,   476,   477,   478,   479,   722,  1127,  1128,   480,   481,
     482,    35,    63,   540,   541,   542,   543,   544,    36,   301,
     302,   303,    37,    69,   594,   595,   596,   597,   598,   807,
    1235,  1236,    38,    66,   578,   579,   580,   581,   797,  1216,
    1217,    39,    52,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   646,  1098,  1099,   390,   391,   392,
     393,   394,    40,    58,   486,   487,   488,   489,    41,    53,
     398,   399,   400,   401,    42,   115,   116,   117,    43,    55,
     408,   409,   410,   411,    44,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   442,   952,   953,   218,   440,   927,   928,
     219,   220,   221,    45,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      46,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     853,   854,   608,  1067,   610,   292,   612,   613,  1096,   490,
     225,   299,    70,   113,   536,   506,   506,   113,   852,   405,
      49,   395,   536,    50,   225,  1138,    54,    70,   395,  1057,
    1058,  1059,  1060,  1061,  1062,  1063,   703,   299,    71,   292,
     704,    56,   405,   119,    60,    72,    64,   483,   120,   121,
     537,   122,   123,    71,    65,   705,   124,  1111,   537,   706,
      72,  1112,  1113,  1238,   125,   126,  1114,  1239,   491,  1243,
      67,   127,   590,  1244,   128,   492,    68,   493,  1068,   114,
     129,    47,    48,   114,  1043,   130,   131,   396,   132,   133,
     134,   110,   135,   254,   396,   575,   538,   507,   507,   111,
     667,   136,   669,   670,   538,   137,   138,  1043,   483,   676,
     226,  1264,   112,   680,   300,    73,   139,   118,   685,   255,
     222,   688,   406,   575,   226,   223,   140,   857,   858,   590,
      73,   698,   699,   141,   227,   142,   494,   143,   224,   144,
     300,   145,   146,   712,   539,   406,   715,   716,   227,   407,
     232,   397,   539,   256,   147,   233,   464,    79,   397,   148,
     149,   150,   257,   151,   152,   153,  1139,  1247,   154,  1249,
     234,  1248,   407,  1250,   465,   591,  1140,   484,   305,   291,
      80,    81,  -115,   304,   258,  1257,    82,  1044,   259,  1258,
     466,  1259,   508,   508,   155,  1260,   260,   327,   576,   261,
     262,   306,  1097,   307,   156,   157,   158,   159,   160,   161,
    1044,  1261,   513,   328,   329,  1262,  -115,   330,   308,  1268,
     311,    83,    84,  1269,   467,   312,   576,    85,    86,   293,
     514,   263,   591,    87,    88,    89,   162,   313,   484,   775,
     739,    90,    91,   309,   403,   766,   515,   747,   264,   599,
     664,   265,   266,   267,   600,   504,   163,   164,   165,   658,
     166,   167,   168,   293,   314,   331,    92,    93,   588,   315,
     584,   169,   485,   364,   462,   365,   501,   366,   268,   468,
     516,  1045,   332,   333,   334,   335,   336,   469,   470,   316,
     337,   367,   235,   592,   338,   269,   490,   593,  1295,   317,
     339,   555,  1296,   809,  1045,  1046,   318,   368,   471,   839,
     319,   340,   341,   320,   844,   517,   577,   847,   321,   270,
     271,   851,   236,   342,   573,   322,   798,   323,  1046,   324,
     237,   402,   369,   485,   370,   518,   412,   413,  1222,   732,
     582,   371,   238,   239,   577,   343,   414,   240,   241,   242,
     592,   519,   372,   415,   593,   491,  1082,  1083,  1084,  1240,
    1241,  1242,   492,   607,   493,   416,   417,   418,   520,   521,
     419,   420,   243,   254,   421,   422,   373,   423,   424,   425,
     426,   472,   427,   428,   429,   344,   430,   728,   325,   601,
     818,   819,   820,   821,   822,   823,   824,   431,   432,   255,
     374,   433,   434,   435,   119,   436,   437,   438,   439,   120,
     121,   441,   122,   123,   443,   522,   444,   124,   445,   446,
     375,   464,   447,   494,   448,   125,   126,   449,   637,   376,
     602,   450,   127,   256,   451,   128,   452,   523,   513,   465,
     453,   129,   257,   760,   454,   603,   130,   131,   455,   132,
     133,   134,   456,   135,   457,   466,   514,   458,   459,   852,
     460,   461,   136,   502,   258,   503,   137,   138,   259,   545,
     546,   547,   515,   548,   549,   377,   260,   139,   550,   261,
     262,   551,   552,   586,   556,   557,   558,   140,   559,   467,
     560,   561,   562,   563,   141,   564,   142,   565,   143,   378,
     144,   566,   145,   146,   654,   567,   516,   568,   569,   570,
     571,   263,   572,   583,   587,   147,   604,   605,  1150,   606,
     148,   149,   150,   553,   151,   152,   153,   607,   264,   154,
     609,   265,   266,   267,  1151,   611,   614,   615,   616,   617,
     618,   517,  1152,   619,   468,   620,   364,   621,   365,   622,
     366,   624,   469,   470,   625,   155,  1153,   626,   268,  1283,
     660,   518,   627,   628,   367,   156,   157,   158,   159,   160,
     161,   629,   630,   471,   631,   269,   632,   519,   633,   666,
     368,   634,   635,   636,   639,  1265,   640,  1154,   641,  1155,
    1284,   642,  1285,   643,   520,   521,   644,   162,   645,   270,
     271,   647,   648,   649,   650,   369,  1117,   370,   651,   652,
     653,   656,   657,   661,   371,  1156,   668,   163,   164,   165,
     662,   166,   167,   168,   663,   372,   672,  1118,   671,   674,
     673,   675,   169,   678,   679,   681,  1119,  1286,   677,     2,
       3,   522,   682,     4,   686,   683,   472,   684,  1157,   373,
    1158,   687,   689,   690,  1287,     5,   691,   692,     6,     7,
     693,   694,   695,   523,   696,     8,   697,  1120,   327,  1159,
     700,   701,   702,   374,   707,   708,     9,   709,   710,    10,
      11,   711,   713,   714,   328,   329,   717,   718,   330,  1160,
     741,  1288,  1289,   375,  1161,   742,  1121,  1122,  1162,   719,
     720,   721,   376,   771,  1123,  1163,   723,    12,   724,   725,
    1164,   726,    13,  1206,   727,   930,   730,   931,   932,   731,
    1165,    14,   734,  1166,   735,  1167,   736,   738,   743,  1124,
     744,   777,   745,   779,   746,   749,   331,  1168,   762,   750,
     751,    15,    16,  1290,  1169,  1125,   768,  1291,   377,   769,
     753,   780,   754,   332,   333,   334,   335,   336,   755,    17,
    1177,   337,  1178,  1179,   770,   338,   756,  1225,   757,   759,
     235,   339,   378,   772,   763,  1207,    18,   773,   764,   776,
     765,   774,   340,   341,   778,   781,   782,   783,   784,    19,
      20,   785,   786,   790,   342,   787,   794,   788,   907,   789,
     236,   791,   792,  1126,   793,   800,  1208,   795,   237,   796,
     801,    21,   803,  1209,   802,   804,   343,   805,   811,   806,
     238,   239,  1210,   808,    22,   240,   241,   242,   812,  1226,
     813,   814,    23,   933,   934,   935,    24,   936,   937,   815,
     938,   939,   816,   940,  1211,   941,  1212,  1213,   942,   817,
     243,   943,   944,   827,   945,   828,   344,   829,   830,   946,
    1227,  1214,   831,   947,   948,   949,   832,  1228,  1215,   950,
     837,   833,   834,   835,   951,   836,  1229,   838,  1180,  1181,
    1182,   840,  1183,  1184,   841,  1185,  1186,   842,  1187,   843,
    1188,   845,   846,  1189,   848,   849,  1190,  1191,  1230,  1192,
    1231,  1232,   850,   852,  1193,   855,   860,   866,  1194,  1195,
    1196,   856,   859,   861,  1197,  1233,   908,   909,   910,  1198,
     911,   912,  1234,   913,   914,   862,   915,    79,   916,   863,
     864,   917,   865,   867,   918,   919,   868,   920,   869,   870,
     872,   871,   921,   873,   874,   875,   922,   923,   924,   876,
      80,    81,   925,   877,   878,   879,    82,   926,   880,   881,
     882,   883,   884,   885,   886,   887,   888,   889,   890,   891,
     892,   893,   894,   895,   896,   897,   898,   899,   975,   900,
     901,   902,   903,   904,   905,   906,   929,   976,   954,   955,
     956,    83,    84,   957,   977,   958,   978,    85,    86,   959,
     979,   980,   960,    87,    88,    89,   981,   961,   982,   984,
     962,    90,    91,   985,   987,   990,   963,   964,   965,   988,
     996,   966,   967,   968,   997,   969,   970,   999,   971,   972,
     973,   974,  1000,   983,  1002,  1003,    92,    93,  1004,   986,
     989,  1005,  1006,   993,   994,  1008,   995,   998,  1010,  1011,
    1012,  1001,  1007,  1009,  1013,  1040,  1014,  1015,  1016,  1017,
    1039,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,
    1053,  1037,  1038,  1041,  1042,  1052,  1055,  1056,  1064,  1054,
    1065,  1066,  1071,  1072,  1073,  1074,  1075,  1076,  1251,  1077,
    1078,  1079,  1080,  1263,  1081,  1087,  1088,  1089,  1274,  1090,
    1275,  1276,  1091,  1092,  1093,   310,   748,   761,  1094,  1095,
    1100,  1223,  1278,  1101,  1102,  1103,  1297,  1104,  1105,  1277,
    1106,  1107,  1270,  1108,  1109,  1110,  1273,  1252,  1115,  1116,
     799,  1129,  1130,  1272,  1131,  1132,  1133,   740,  1134,  1135,
    1143,   729,   585,  1136,  1137,   767,  1146,   810,  1147,  1144,
    1294,  1148,  1219,  1149,  1172,  1173,  1174,  1175,  1176,  1201,
    1202,  1203,  1204,  1205,  1218,  1279,  1224,  1237,  1220,  1253,
     505,   404,   733,  1254,   655,  1255,  1256,  1266,  1271,  1267,
    1280,  1281,  1282,   463,  1246,   326,     0,  1245,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   554,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   574,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   589,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     638,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     659,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   665
};

static const yytype_int16 yycheck[] =
{
     635,   636,   315,    55,   317,     1,   319,   320,     8,     1,
       1,     1,     1,     1,     1,     1,     1,     1,   114,     1,
     233,     1,     1,   233,     1,    51,   233,     1,     1,   818,
     819,   820,   821,   822,   823,   824,   213,     1,    27,     1,
     217,   233,     1,     1,   233,    34,   233,     1,     6,     7,
      37,     9,    10,    27,   233,   213,    14,   231,    37,   217,
      34,   235,   231,   231,    22,    23,   235,   235,    60,   231,
     233,    29,     1,   235,    32,    67,   233,    69,   130,    67,
      38,   231,   232,    67,     1,    43,    44,    67,    46,    47,
      48,   233,    50,     1,    67,     1,    83,    83,    83,   233,
     413,    59,   415,   416,    83,    63,    64,     1,     1,   422,
     101,   207,   233,   426,   104,   104,    74,   233,   431,    27,
     233,   434,   104,     1,   101,   233,    84,   182,   183,     1,
     104,   444,   445,    91,   125,    93,   128,    95,   233,    97,
     104,    99,   100,   456,   131,   104,   459,   460,   125,   131,
     233,   131,   131,    61,   112,   233,     1,     1,   131,   117,
     118,   119,    70,   121,   122,   123,   192,   231,   126,   231,
     233,   235,   131,   235,    19,   104,   202,   131,   231,   233,
      24,    25,   178,   233,    92,   231,    30,   104,    96,   235,
      35,   231,   178,   178,   152,   235,   104,     1,   104,   107,
     108,   234,   202,   234,   162,   163,   164,   165,   166,   167,
     104,   231,     1,    17,    18,   235,   178,    21,   234,   231,
     234,    65,    66,   235,    69,   234,   104,    71,    72,   225,
      19,   139,   104,    77,    78,    79,   194,   234,   131,   552,
     232,    85,    86,   232,   232,   232,    35,   232,   156,   129,
     232,   159,   160,   161,   129,   232,   214,   215,   216,   232,
     218,   219,   220,   225,   234,    69,   110,   111,   232,   234,
     232,   229,   226,     1,   232,     3,   231,     5,   186,   124,
      69,   198,    86,    87,    88,    89,    90,   132,   133,   234,
      94,    19,     1,   222,    98,   203,     1,   226,   231,   234,
     104,   231,   235,   232,   198,   222,   234,    35,   153,   622,
     234,   115,   116,   234,   627,   104,   222,   630,   234,   227,
     228,   634,    31,   127,   232,   234,   232,   234,   222,   234,
      39,   234,    60,   226,    62,   124,   234,   234,   232,   232,
     231,    69,    51,    52,   222,   149,   234,    56,    57,    58,
     222,   140,    80,   234,   226,    60,    11,    12,    13,  1082,
    1083,  1084,    67,   114,    69,   234,   234,   234,   157,   158,
     234,   234,    81,     1,   234,   234,   104,   234,   234,   234,
     234,   226,   234,   234,   234,   189,   234,   232,   232,   129,
     141,   142,   143,   144,   145,   146,   147,   234,   234,    27,
     128,   234,   234,   234,     1,   234,   234,   234,   234,     6,
       7,   234,     9,    10,   234,   204,   234,    14,   234,   234,
     148,     1,   234,   128,   234,    22,    23,   234,   232,   157,
     231,   234,    29,    61,   234,    32,   234,   226,     1,    19,
     234,    38,    70,   232,   234,   114,    43,    44,   234,    46,
      47,    48,   234,    50,   234,    35,    19,   234,   234,   114,
     234,   234,    59,   234,    92,   234,    63,    64,    96,   234,
     234,   234,    35,   234,   234,   203,   104,    74,   234,   107,
     108,   234,   234,   178,   234,   234,   234,    84,   234,    69,
     234,   234,   234,   234,    91,   234,    93,   234,    95,   227,
      97,   234,    99,   100,   232,   234,    69,   234,   234,   234,
     234,   139,   234,   234,   234,   112,   114,   213,     4,   114,
     117,   118,   119,   232,   121,   122,   123,   114,   156,   126,
     114,   159,   160,   161,    20,   114,   114,   114,   213,   213,
     231,   104,    28,   231,   124,   234,     1,   234,     3,   234,
       5,   234,   132,   133,   234,   152,    42,   234,   186,    42,
     129,   124,   234,   234,    19,   162,   163,   164,   165,   166,
     167,   234,   234,   153,   234,   203,   234,   140,   234,   213,
      35,   234,   234,   234,   231,  1220,   234,    73,   234,    75,
      73,   234,    75,   234,   157,   158,   234,   194,   234,   227,
     228,   234,   234,   234,   234,    60,    15,    62,   234,   234,
     234,   234,   234,   231,    69,   101,   114,   214,   215,   216,
     234,   218,   219,   220,   234,    80,   114,    36,   213,   114,
     213,   213,   229,   114,   114,   114,    45,   120,   213,     0,
       1,   204,   213,     4,   114,   213,   226,   213,   134,   104,
     136,   114,   114,   114,   137,    16,   114,   114,    19,    20,
     213,   234,   213,   226,   234,    26,   213,    76,     1,   155,
     213,   213,   213,   128,   213,   213,    37,   213,   129,    40,
      41,   114,   213,   213,    17,    18,   213,   231,    21,   175,
     129,   174,   175,   148,   180,   129,   105,   106,   184,   231,
     234,   234,   157,   129,   113,   191,   234,    68,   234,   234,
     196,   234,    73,    75,   234,    51,   234,    53,    54,   234,
     206,    82,   231,   209,   234,   211,   234,   234,   231,   138,
     231,   129,   234,   129,   234,   231,    69,   223,   231,   234,
     234,   102,   103,   226,   230,   154,   213,   230,   203,   213,
     234,   114,   234,    86,    87,    88,    89,    90,   234,   120,
      51,    94,    53,    54,   213,    98,   234,    75,   234,   234,
       1,   104,   227,   213,   234,   137,   137,   213,   234,   231,
     234,   213,   115,   116,   213,   114,   129,   129,   129,   150,
     151,   129,   129,   114,   127,   129,   231,   129,    51,   129,
      31,   129,   129,   212,   129,   213,   168,   231,    39,   234,
     231,   172,   129,   175,   233,   231,   149,   231,   231,   234,
      51,    52,   184,   234,   185,    56,    57,    58,   231,   137,
     231,   231,   193,   169,   170,   171,   197,   173,   174,   231,
     176,   177,   231,   179,   206,   181,   208,   209,   184,   231,
      81,   187,   188,   231,   190,   231,   189,   231,   231,   195,
     168,   223,   231,   199,   200,   201,   231,   175,   230,   205,
     114,   231,   231,   231,   210,   231,   184,   114,   169,   170,
     171,   234,   173,   174,   114,   176,   177,   114,   179,   114,
     181,   114,   114,   184,   129,   114,   187,   188,   206,   190,
     208,   209,   114,   114,   195,   231,   213,   114,   199,   200,
     201,   129,   129,   129,   205,   223,   169,   170,   171,   210,
     173,   174,   230,   176,   177,   129,   179,     1,   181,   234,
     129,   184,   129,   129,   187,   188,   129,   190,   129,   129,
     129,   231,   195,   129,   231,   231,   199,   200,   201,   129,
      24,    25,   205,   129,   231,   231,    30,   210,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   129,   231,
     231,   231,   231,   231,   231,   231,   231,   213,   231,   231,
     231,    65,    66,   231,   234,   231,   129,    71,    72,   231,
     114,   129,   231,    77,    78,    79,   129,   231,   129,   129,
     231,    85,    86,   129,   129,   114,   231,   231,   231,   129,
     129,   231,   231,   231,   129,   231,   231,   129,   231,   231,
     231,   231,   213,   231,   129,   129,   110,   111,   129,   231,
     234,   129,   213,   231,   231,   129,   231,   231,   129,   129,
     129,   234,   234,   231,   231,   234,   231,   231,   231,   231,
     129,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     129,   231,   231,   231,   231,   231,   129,   231,   231,   234,
     231,   231,   231,   231,   231,   231,   231,   231,   114,   231,
     231,   231,   231,   129,   231,   231,   231,   231,   135,   231,
     135,   135,   231,   231,   231,    74,   509,   524,   231,   231,
     231,  1047,  1260,   231,   231,   231,  1296,   231,   231,  1258,
     231,   231,  1239,   231,   231,   231,  1250,  1144,   231,   231,
     578,   231,   231,  1248,   231,   231,   231,   496,   231,   231,
     221,   473,   294,   231,   231,   540,   231,   594,   231,   235,
    1269,   231,   234,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,  1262,   231,   231,   234,   231,
     228,   115,   486,   236,   379,   236,   236,   234,  1244,   231,
     231,   231,   231,   170,  1114,    94,    -1,  1112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   408
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   238,     0,     1,     4,    16,    19,    20,    26,    37,
      40,    41,    68,    73,    82,   102,   103,   120,   137,   150,
     151,   172,   185,   193,   197,   239,   244,   249,   269,   275,
     281,   295,   315,   339,   353,   368,   375,   379,   389,   398,
     419,   425,   431,   435,   441,   500,   517,   231,   232,   233,
     233,   316,   399,   426,   233,   436,   233,   354,   420,   340,
     233,   276,   296,   369,   233,   233,   390,   233,   233,   380,
       1,    27,    34,   104,   270,   271,   272,   273,   274,     1,
      24,    25,    30,    65,    66,    71,    72,    77,    78,    79,
      85,    86,   110,   111,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     233,   233,   233,     1,    67,   432,   433,   434,   233,     1,
       6,     7,     9,    10,    14,    22,    23,    29,    32,    38,
      43,    44,    46,    47,    48,    50,    59,    63,    64,    74,
      84,    91,    93,    95,    97,    99,   100,   112,   117,   118,
     119,   121,   122,   123,   126,   152,   162,   163,   164,   165,
     166,   167,   194,   214,   215,   216,   218,   219,   220,   229,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   493,   497,
     498,   499,   233,   233,   233,     1,   101,   125,   245,   246,
     247,   248,   233,   233,   233,     1,    31,    39,    51,    52,
      56,    57,    58,    81,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,     1,    27,    61,    70,    92,    96,
     104,   107,   108,   139,   156,   159,   160,   161,   186,   203,
     227,   228,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   233,     1,   225,   282,   283,   284,   285,   286,     1,
     104,   376,   377,   378,   233,   231,   234,   234,   234,   232,
     271,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   232,   502,     1,    17,    18,
      21,    69,    86,    87,    88,    89,    90,    94,    98,   104,
     115,   116,   127,   149,   189,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,     1,     3,     5,    19,    35,    60,
      62,    69,    80,   104,   128,   148,   157,   203,   227,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     414,   415,   416,   417,   418,     1,    67,   131,   427,   428,
     429,   430,   234,   232,   433,     1,   104,   131,   437,   438,
     439,   440,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     494,   234,   490,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   232,   443,     1,    19,    35,    69,   124,   132,
     133,   153,   226,   355,   356,   357,   358,   359,   360,   361,
     365,   366,   367,     1,   131,   226,   421,   422,   423,   424,
       1,    60,    67,    69,   128,   341,   345,   346,   347,   351,
     352,   231,   234,   234,   232,   246,     1,    83,   178,   277,
     278,   279,   280,     1,    19,    35,    69,   104,   124,   140,
     157,   158,   204,   226,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   311,     1,    37,    83,   131,
     370,   371,   372,   373,   374,   234,   234,   234,   234,   234,
     234,   234,   234,   232,   519,   231,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   232,   251,     1,   104,   222,   391,   392,
     393,   394,   231,   234,   232,   283,   178,   234,   232,   377,
       1,   104,   222,   226,   381,   382,   383,   384,   385,   129,
     129,   129,   231,   114,   114,   213,   114,   114,   241,   114,
     241,   114,   241,   241,   114,   114,   213,   213,   231,   231,
     234,   234,   234,   336,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   232,   318,   231,
     234,   234,   234,   234,   234,   234,   411,   234,   234,   234,
     234,   234,   234,   234,   232,   401,   234,   234,   232,   428,
     129,   231,   234,   234,   232,   438,   213,   241,   114,   241,
     241,   213,   114,   213,   114,   213,   241,   213,   114,   114,
     241,   114,   213,   213,   213,   241,   114,   114,   241,   114,
     114,   114,   114,   213,   234,   213,   234,   213,   241,   241,
     213,   213,   213,   213,   217,   213,   217,   213,   213,   213,
     129,   114,   241,   213,   213,   241,   241,   213,   231,   231,
     234,   234,   362,   234,   234,   234,   234,   234,   232,   356,
     234,   234,   232,   422,   231,   234,   234,   342,   234,   232,
     346,   129,   129,   231,   231,   234,   234,   232,   278,   231,
     234,   234,   312,   234,   234,   234,   234,   234,   308,   234,
     232,   298,   231,   234,   234,   234,   232,   371,   213,   213,
     213,   129,   213,   213,   213,   241,   231,   129,   213,   129,
     114,   114,   129,   129,   129,   129,   129,   129,   129,   129,
     114,   129,   129,   129,   231,   231,   234,   395,   232,   392,
     213,   231,   233,   129,   231,   231,   234,   386,   234,   232,
     382,   231,   231,   231,   231,   231,   231,   231,   141,   142,
     143,   144,   145,   146,   147,   240,   241,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   114,   114,   241,
     234,   114,   114,   114,   241,   114,   114,   241,   129,   114,
     114,   241,   114,   243,   243,   231,   129,   182,   183,   129,
     213,   129,   129,   234,   129,   129,   114,   129,   129,   129,
     129,   231,   129,   129,   231,   231,   129,   129,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,    51,   169,   170,
     171,   173,   174,   176,   177,   179,   181,   184,   187,   188,
     190,   195,   199,   200,   201,   205,   210,   495,   496,   231,
      51,    53,    54,   169,   170,   171,   173,   174,   176,   177,
     179,   181,   184,   187,   188,   190,   195,   199,   200,   201,
     205,   210,   491,   492,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   129,   213,   234,   129,   114,
     129,   129,   129,   231,   129,   129,   231,   129,   129,   234,
     114,   349,   350,   231,   231,   231,   129,   129,   231,   129,
     213,   234,   129,   129,   129,   129,   213,   234,   129,   231,
     129,   129,   129,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   129,
     234,   231,   231,     1,   104,   198,   222,   287,   288,   289,
     290,   291,   231,   129,   234,   129,   231,   240,   240,   240,
     240,   240,   240,   240,   231,   231,   231,    55,   130,   337,
     338,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,    11,    12,    13,   242,   243,   231,   231,   231,
     231,   231,   231,   231,   231,   231,     8,   202,   412,   413,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   235,   231,   235,   231,   231,    15,    36,    45,
      76,   105,   106,   113,   138,   154,   212,   363,   364,   231,
     231,   231,   231,   231,   231,   231,   231,   231,    51,   192,
     202,   343,   344,   221,   235,   348,   231,   231,   231,   231,
       4,    20,    28,    42,    73,    75,   101,   134,   136,   155,
     175,   180,   184,   191,   196,   206,   209,   211,   223,   230,
     313,   314,   231,   231,   231,   231,   231,    51,    53,    54,
     169,   170,   171,   173,   174,   176,   177,   179,   181,   184,
     187,   188,   190,   195,   199,   200,   201,   205,   210,   309,
     310,   231,   231,   231,   231,   231,    75,   137,   168,   175,
     184,   206,   208,   209,   223,   230,   396,   397,   231,   234,
     234,   292,   232,   288,   231,    75,   137,   168,   175,   184,
     206,   208,   209,   223,   230,   387,   388,   231,   231,   235,
     242,   242,   242,   231,   235,   496,   492,   231,   235,   231,
     235,   114,   350,   231,   236,   236,   236,   231,   235,   231,
     235,   231,   235,   129,   207,   243,   234,   231,   231,   235,
     338,   413,   364,   344,   135,   135,   135,   314,   310,   397,
     231,   231,   231,    42,    73,    75,   120,   137,   174,   175,
     226,   230,   293,   294,   388,   231,   235,   294
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
     251,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   270,   271,   271,   271,   271,   272,   273,   274,   276,
     275,   277,   277,   278,   278,   278,   279,   280,   281,   282,
     282,   283,   283,   283,   284,   286,   285,   287,   287,   288,
     288,   288,   288,   289,   290,   290,   292,   291,   293,   293,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   296,
     295,   297,   297,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   308,   307,   309,   309,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   312,   311,
     313,   313,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   316,   315,   317,   317,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   336,   335,   337,   337,   338,   338,   340,
     339,   342,   341,   343,   343,   344,   344,   344,   345,   345,
     346,   346,   346,   346,   346,   348,   347,   349,   349,   350,
     350,   351,   352,   354,   353,   355,   355,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   357,   358,   359,   360,
     362,   361,   363,   363,   364,   364,   364,   364,   364,   364,
     364,   364,   364,   364,   365,   366,   367,   369,   368,   370,
     370,   371,   371,   371,   371,   372,   373,   374,   375,   376,
     376,   377,   377,   378,   380,   379,   381,   381,   382,   382,
     382,   382,   383,   384,   386,   385,   387,   387,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   390,   389,
     391,   391,   392,   392,   392,   393,   395,   394,   396,   396,
     397,   397,   397,   397,   397,   397,   397,   397,   397,   397,
     399,   398,   400,   400,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   409,   411,   410,
     412,   412,   413,   413,   414,   415,   416,   417,   418,   420,
     419,   421,   421,   422,   422,   422,   423,   424,   426,   425,
     427,   427,   428,   428,   428,   429,   430,   431,   432,   432,
     433,   433,   434,   436,   435,   437,   437,   438,   438,   438,
     439,   440,   441,   442,   442,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   472,   473,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   490,   489,   491,   491,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   494,
     493,   495,   495,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   497,   498,   499,   500,   501,   501,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     518,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     520,   521,   522,   523,   524,   525,   526,   527
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
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
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
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 440 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 476 "conf_parser.y" /* yacc.c:1646  */
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
#line 3012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 518 "conf_parser.y" /* yacc.c:1646  */
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
#line 3073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 576 "conf_parser.y" /* yacc.c:1646  */
    {
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
    else
      conf_error_report("Ignoring serverinfo::ssl_dh_param_file -- could not open/read Diffie-Hellman parameter file");
  }
#endif
}
#line 3105 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 605 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 613 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
  {
    if ((ServerInfo.message_digest_algorithm = EVP_get_digestbyname(yylval.string)) == NULL)
    {
      ServerInfo.message_digest_algorithm = EVP_sha256();
      conf_error_report("Ignoring serverinfo::ssl_message_digest_algorithm -- unknown message digest algorithm");
    }
  }
#endif
}
#line 3133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 627 "conf_parser.y" /* yacc.c:1646  */
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
#line 3164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 655 "conf_parser.y" /* yacc.c:1646  */
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
#line 3182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 670 "conf_parser.y" /* yacc.c:1646  */
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
#line 3200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 685 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
#line 3212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 694 "conf_parser.y" /* yacc.c:1646  */
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
#line 3229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 708 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 717 "conf_parser.y" /* yacc.c:1646  */
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
#line 3272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 745 "conf_parser.y" /* yacc.c:1646  */
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
#line 3305 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 775 "conf_parser.y" /* yacc.c:1646  */
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
#line 3333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 800 "conf_parser.y" /* yacc.c:1646  */
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
#line 3358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 822 "conf_parser.y" /* yacc.c:1646  */
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
#line 3383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 844 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 861 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3404 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 870 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 879 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 891 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 895 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
    motd_add(ptr->data, block_state.file.buf);
}
#line 3454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 912 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 918 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 933 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3490 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 943 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 967 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3522 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 970 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 975 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 982 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 986 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3557 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 990 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3566 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 994 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3575 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 998 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3584 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1002 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3593 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1006 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3602 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1010 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3611 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3620 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1024 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3632 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1031 "conf_parser.y" /* yacc.c:1646  */
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
#line 3714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1123 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1129 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1135 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1141 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3755 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1152 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1158 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1164 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3787 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1175 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3796 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1181 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3805 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1188 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1196 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1208 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1216 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1224 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1228 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1252 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1260 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1264 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4003 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1278 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1345 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1349 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1361 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1365 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4201 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1369 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1373 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1383 "conf_parser.y" /* yacc.c:1646  */
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
#line 4236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1395 "conf_parser.y" /* yacc.c:1646  */
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
#line 4289 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1464 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4298 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1470 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4307 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1476 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4316 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1482 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4325 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1488 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4334 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1494 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4343 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1500 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1506 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4361 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1512 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4370 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1518 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1524 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1531 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1537 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1543 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1549 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1558 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1567 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4449 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1574 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4458 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1578 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4467 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1588 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1594 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4484 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1600 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4493 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1604 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1608 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1616 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1621 "conf_parser.y" /* yacc.c:1646  */
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
#line 4536 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
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

    for (int i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      add_listener(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4557 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1653 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4566 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1659 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4575 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1668 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4584 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1672 "conf_parser.y" /* yacc.c:1646  */
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
#line 4625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1721 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1727 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1733 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4652 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1739 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4666 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1750 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1757 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1761 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1765 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4702 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1769 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4711 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1773 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4720 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1777 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4729 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1781 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4738 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1785 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1789 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4756 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1793 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1799 "conf_parser.y" /* yacc.c:1646  */
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
#line 4782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1813 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1822 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4806 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1842 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4829 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1853 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1865 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1880 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1895 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1906 "conf_parser.y" /* yacc.c:1646  */
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
#line 4904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1923 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1929 "conf_parser.y" /* yacc.c:1646  */
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
#line 4935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1948 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1955 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1963 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4971 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1967 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4980 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1971 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1975 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1979 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1983 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1987 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1991 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 2000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 2009 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5063 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2024 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2030 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5090 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5108 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 2057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2061 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2065 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5153 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2069 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5162 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2073 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5171 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2082 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5185 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2091 "conf_parser.y" /* yacc.c:1646  */
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
#line 5251 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 399:
#line 2171 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5260 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2177 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2183 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2189 "conf_parser.y" /* yacc.c:1646  */
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
#line 5294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2202 "conf_parser.y" /* yacc.c:1646  */
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
#line 5310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 404:
#line 2215 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2227 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5337 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2231 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2239 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2245 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2266 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2278 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2284 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2299 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2303 "conf_parser.y" /* yacc.c:1646  */
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
#line 5463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2328 "conf_parser.y" /* yacc.c:1646  */
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
#line 5486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2348 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5495 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2361 "conf_parser.y" /* yacc.c:1646  */
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
#line 5530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2387 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2393 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2407 "conf_parser.y" /* yacc.c:1646  */
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
#line 5565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2424 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2428 "conf_parser.y" /* yacc.c:1646  */
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
#line 5596 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2450 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5605 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2456 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5614 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 506:
#line 2522 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.away_count = (yyvsp[-1].number);
}
#line 5622 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 507:
#line 2527 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.away_time = (yyvsp[-1].number);
}
#line 5630 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 508:
#line 2532 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5638 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 509:
#line 2537 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5647 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 510:
#line 2543 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5656 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 511:
#line 2549 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 512:
#line 2555 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5674 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2561 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2566 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5690 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2571 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5698 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2576 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5706 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2581 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2586 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5722 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2591 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5730 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2596 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5738 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2601 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number);
}
#line 5746 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2606 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5754 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2611 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2616 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5770 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2621 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5778 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2626 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5787 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2632 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5801 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2643 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2648 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_connect_block = yylval.number;
}
#line 5817 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2653 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2658 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5833 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2663 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2668 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2673 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5857 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2676 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2681 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2684 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2689 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2694 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2699 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5905 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2704 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2709 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2714 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2719 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2724 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2729 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2734 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2739 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 5973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 5981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2753 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 5989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2758 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_count = (yyvsp[-1].number);
}
#line 5997 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2763 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = (yyvsp[-1].number);
}
#line 6005 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2768 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 6013 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2774 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 6021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 6029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 6037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2783 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 6045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 6053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2789 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 6061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDECHANS;
}
#line 6069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2798 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 6085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6109 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6141 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6157 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6189 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2851 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2854 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6221 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2860 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6253 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2869 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6261 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6277 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2878 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6285 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6293 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2884 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6317 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2893 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6325 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2896 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2899 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2902 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2910 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2915 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2920 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2949 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2954 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2959 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2964 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6421 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2979 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2984 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6445 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2989 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2994 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2999 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 3004 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6477 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3009 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6485 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3014 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6493 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 3036 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 3042 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 3048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 3054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 3060 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 3069 "conf_parser.y" /* yacc.c:1646  */
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
#line 6559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3084 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6568 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3090 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6577 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6581 "conf_parser.c" /* yacc.c:1646  */
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
