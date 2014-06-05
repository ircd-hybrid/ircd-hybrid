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
#line 146 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 689 "conf_parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 704 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  663
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1303

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
       0,   380,   380,   381,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   410,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   421,   421,   422,
     423,   424,   425,   432,   435,   435,   436,   436,   436,   438,
     444,   451,   453,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   474,   475,   477,   477,   478,   484,   492,   492,
     493,   499,   507,   549,   607,   635,   643,   658,   673,   682,
     696,   705,   733,   763,   788,   810,   832,   841,   843,   843,
     844,   845,   846,   847,   849,   858,   867,   880,   879,   897,
     897,   898,   898,   898,   900,   906,   915,   916,   916,   918,
     918,   919,   921,   928,   928,   941,   942,   944,   944,   945,
     945,   947,   955,   958,   964,   963,   969,   969,   970,   974,
     978,   982,   986,   990,   994,   998,  1002,  1013,  1012,  1092,
    1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,
    1102,  1103,  1105,  1111,  1117,  1123,  1134,  1140,  1146,  1157,
    1164,  1163,  1169,  1169,  1170,  1174,  1178,  1182,  1186,  1190,
    1194,  1198,  1202,  1206,  1210,  1214,  1218,  1222,  1226,  1230,
    1234,  1238,  1242,  1246,  1250,  1254,  1261,  1260,  1266,  1266,
    1267,  1271,  1275,  1279,  1283,  1287,  1291,  1295,  1299,  1303,
    1307,  1311,  1315,  1319,  1323,  1327,  1331,  1335,  1339,  1343,
    1347,  1351,  1355,  1366,  1365,  1426,  1426,  1427,  1428,  1429,
    1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1438,
    1439,  1440,  1441,  1442,  1444,  1450,  1456,  1462,  1468,  1474,
    1480,  1486,  1492,  1498,  1505,  1511,  1517,  1523,  1532,  1542,
    1541,  1547,  1547,  1548,  1552,  1563,  1562,  1569,  1568,  1573,
    1573,  1574,  1578,  1582,  1588,  1588,  1589,  1589,  1589,  1589,
    1589,  1591,  1591,  1593,  1593,  1595,  1609,  1627,  1633,  1643,
    1642,  1684,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,
    1692,  1693,  1695,  1701,  1707,  1713,  1725,  1724,  1730,  1730,
    1731,  1735,  1739,  1743,  1747,  1751,  1755,  1759,  1763,  1767,
    1773,  1787,  1796,  1810,  1809,  1824,  1824,  1825,  1825,  1825,
    1825,  1827,  1833,  1839,  1849,  1851,  1851,  1852,  1852,  1854,
    1870,  1869,  1894,  1894,  1895,  1895,  1895,  1895,  1897,  1903,
    1923,  1922,  1928,  1928,  1929,  1933,  1937,  1941,  1945,  1949,
    1953,  1957,  1961,  1965,  1975,  1974,  1995,  1995,  1996,  1996,
    1996,  1998,  2005,  2004,  2010,  2010,  2011,  2015,  2019,  2023,
    2027,  2031,  2035,  2039,  2043,  2047,  2057,  2056,  2128,  2128,
    2129,  2130,  2131,  2132,  2133,  2134,  2135,  2136,  2137,  2138,
    2139,  2140,  2141,  2142,  2143,  2145,  2151,  2157,  2163,  2176,
    2189,  2195,  2201,  2205,  2214,  2213,  2218,  2218,  2219,  2223,
    2229,  2240,  2246,  2252,  2258,  2274,  2273,  2299,  2299,  2300,
    2300,  2300,  2302,  2322,  2332,  2331,  2358,  2358,  2359,  2359,
    2359,  2361,  2367,  2376,  2378,  2378,  2379,  2379,  2381,  2399,
    2398,  2421,  2421,  2422,  2422,  2422,  2424,  2430,  2439,  2442,
    2442,  2443,  2444,  2445,  2446,  2447,  2448,  2449,  2450,  2451,
    2452,  2453,  2454,  2455,  2456,  2457,  2458,  2459,  2460,  2461,
    2462,  2463,  2464,  2465,  2466,  2467,  2468,  2469,  2470,  2471,
    2472,  2473,  2474,  2475,  2476,  2477,  2478,  2479,  2480,  2481,
    2482,  2483,  2484,  2485,  2486,  2487,  2488,  2489,  2490,  2491,
    2492,  2495,  2500,  2506,  2512,  2518,  2524,  2529,  2534,  2539,
    2544,  2549,  2554,  2559,  2564,  2569,  2574,  2579,  2584,  2589,
    2595,  2606,  2611,  2616,  2621,  2626,  2631,  2636,  2639,  2644,
    2647,  2652,  2657,  2662,  2667,  2672,  2677,  2682,  2687,  2692,
    2697,  2702,  2707,  2716,  2725,  2730,  2735,  2741,  2740,  2745,
    2745,  2746,  2749,  2752,  2755,  2758,  2761,  2764,  2767,  2770,
    2773,  2776,  2779,  2782,  2785,  2788,  2791,  2794,  2797,  2800,
    2803,  2806,  2809,  2815,  2814,  2819,  2819,  2820,  2823,  2826,
    2829,  2832,  2835,  2838,  2841,  2844,  2847,  2850,  2853,  2856,
    2859,  2862,  2865,  2868,  2871,  2874,  2877,  2882,  2887,  2892,
    2901,  2904,  2904,  2905,  2906,  2907,  2908,  2909,  2910,  2911,
    2912,  2913,  2914,  2915,  2916,  2917,  2918,  2919,  2920,  2922,
    2928,  2933,  2938,  2943,  2948,  2953,  2958,  2963,  2968,  2973,
    2978,  2983,  2988,  2993,  3001,  3004,  3004,  3005,  3006,  3007,
    3008,  3009,  3010,  3011,  3012,  3013,  3015,  3021,  3027,  3033,
    3039,  3048,  3062,  3068
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
     485,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -1032

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1032)))

#define YYTABLE_NINF -124

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1032,   693, -1032,   -69,  -224,  -209, -1032, -1032, -1032,  -194,
   -1032,  -185, -1032, -1032, -1032,  -165, -1032, -1032, -1032,  -146,
    -139, -1032,  -128,   -38, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,   165,
     912,   -32,   -19,   -16,     4,   -14,   388,    -3,     0,    41,
      48,    46,    50,    51,   726,   463,    67,    13,    83,    74,
    -166,   -12,    -6,    70,    10, -1032, -1032, -1032, -1032, -1032,
      75,    79,    86,    91,    97,   104,   105,   106,   113,   114,
     119,   120,   121,   122,   130,   266, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032,   636,   458,    39, -1032,   134,    14, -1032, -1032,
     123, -1032,   135,   137,   139,   140,   143,   146,   147,   148,
     149,   150,   157,   158,   162,   163,   164,   167,   168,   171,
     172,   173,   176,   178,   179,   183,   189,   191,   192, -1032,
     194, -1032,   197,   203,   205,   206,   207,   208,   209,   210,
     212,   214,   218,   219,   220,   221,   223,   224,   228,   231,
     232,    16, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032,   371,    52,   294,    95,   234,   235,    18, -1032,
   -1032, -1032,     9,   434,   281, -1032,   237,   238,   239,   240,
     242,   243,   245,   247,   102, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,   115,   249,   251,   255,   256,   258,
     261,   262,   277,   278,   280,   283,   285,   286,   287,   290,
     292,   299,    58, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032,    71,   126,   304,    31, -1032, -1032, -1032,   215, -1032,
     319,    65, -1032, -1032,    80, -1032,   186,   259,   271,   303,
   -1032,   309,   442,   345,   450,   451,   454,   451,   455,   451,
     451,   459,   461,   462,   357,   363,   347, -1032,   349,   348,
     350,   352, -1032,   353,   354,   360,   361,   364,   365,   366,
     368,   375,   376,   377,   379,   184, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032,   384,   382,   385,   386,   389,   391,   396,
   -1032,   397,   398,   399,   401,   402,   404,   406,   300, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032,   407,   408,    20, -1032, -1032,
   -1032,   453,   413, -1032, -1032,   411,   414,    25, -1032, -1032,
   -1032,   369,   451,   451,   433,   536,   436,   540,   526,   443,
     451,   448,   543,   554,   451,   555,   460,   464,   465,   451,
     556,   558,   451,   559,   560,   563,   567,   467,   452,   470,
     466,   474,   451,   451,   478,   481,   484,  -176,  -122,   488,
     490,   491,   578,   451,   494,   495,   451,   451,   500,   501,
     485, -1032,   487,   486,   492, -1032,   496,   502,   503,   504,
     513,    92, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032,   514,   515,    43, -1032, -1032, -1032,   521,   519,
     520, -1032,   523, -1032,   153, -1032, -1032, -1032, -1032, -1032,
     593,   606,   525, -1032,   527,   531,   532,    90, -1032, -1032,
   -1032,   529,   534,   537, -1032,   538,   544,   545,   549,   551,
   -1032,   552,   188, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,   530,   553,   557,   562,    15, -1032,
   -1032, -1032, -1032,   574,   575,   576,   646,   579,   583,   584,
     451,   546, -1032, -1032,   664,   585,   672,   689,   702,   691,
     692,   695,   698,   700,   703,   704,   705,   -11,     6,   706,
     707,   599, -1032,   608,   607, -1032,    44, -1032, -1032, -1032,
   -1032,   626,   613, -1032,   612,   719,   617, -1032,   618,   616,
   -1032,   619,    17, -1032, -1032, -1032, -1032,   621,   623,   624,
   -1032,   625,   627,   628,   629,   600,   630,   632,   633,   634,
     635,   637,   638,   639,   642,   643,   645, -1032, -1032,   744,
     754,   451,   644,   758,   764,   451,   766,   767,   451,   753,
     769,   777,   451,   780,   780,   666, -1032, -1032,   770,    82,
     772,   681,   776,   778,   673,   781,   783,   799,   793,   803,
     804,   810,   696, -1032,   813,   814,   716, -1032,   720, -1032,
     824,   825,   723, -1032,   724,   725,   729,   730,   731,   733,
     734,   737,   738,   739,   740,   741,   742,   743,   746,   747,
     748,   749,   755,   759,   760,   761,   762,   763,   768,   771,
     773,   640,   774,   718,   775,   779,   782,   784,   785,   786,
     787,   788,   789,   792,   794,   795,   796,   797,   798,   800,
     801,   802,   805,   806,   807, -1032, -1032,   829,   816,   750,
     839,   870,   857,   872,   873,   808, -1032,   875,   879,   809,
   -1032, -1032,   880,   881,   790,   885,   811, -1032,   812,   815,
   -1032, -1032,   883,   884,   817, -1032, -1032,   886,   820,   818,
     907,   913,   916,   917,   833,   819,   921,   823, -1032, -1032,
     922,   923,   927,   826, -1032,   827,   828,   830,   831,   832,
     834,   835,   836, -1032,   837,   838,   840,   841,   842,   843,
     844,   845,   846,   847,   848,   849,   850, -1032, -1032,  -223,
   -1032, -1032, -1032,  -206, -1032,   851,   852, -1032, -1032,   928,
     853,   854, -1032,   855, -1032,   101,   858, -1032, -1032,   932,
     856,   936,   860, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032,   451,   451,   451,   451,   451,   451,   451, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032,   861,   862,   863,   -40,   864,   865,   866,   867,   868,
     869,   871,   874,   876,   877,   112,   878,   882, -1032,   887,
     888,   889,   890,   891,   892,   893,    -5,   894,   895,   896,
     897,   898,   899,   900, -1032,   901,   902, -1032, -1032,   903,
     904, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,  -204,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,  -201, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032,   905,   906,   522,
     908,   909,   910,   911,   914, -1032,   915,   918, -1032,   919,
     920,   -29,   926,   924, -1032, -1032, -1032, -1032,   925,   929,
   -1032,   930,   931,   489,   933,   934,   935,   937,   938,   752,
     939, -1032,   940,   941,   942, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,   -11, -1032,
       6, -1032, -1032,   943,   156, -1032, -1032,   944,   945,   946,
   -1032,    32, -1032, -1032, -1032, -1032, -1032,   947,   736,   950,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032,  -168, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032,   780,   780,   780, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032,  -161, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032,   640, -1032,   718, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
    -160, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,  -155, -1032,   957,   885,   951, -1032,
   -1032, -1032, -1032, -1032,   948, -1032, -1032,   949, -1032, -1032,
   -1032, -1032,   952, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032,  -149, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032,  -134, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032,   -44, -1032, -1032,   956,   -62,   953,   955, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
     -33, -1032, -1032, -1032,   -40, -1032, -1032, -1032, -1032,    -5,
   -1032, -1032, -1032,   522, -1032,   -29, -1032, -1032, -1032,   954,
     967,   969, -1032,   489, -1032,   752, -1032,   156,   958,   959,
     960,   457, -1032, -1032,   736, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032,   -23, -1032, -1032,
   -1032,   457, -1032
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
       0,     0,     0,     0,     0,    99,   100,   102,   101,   628,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   612,   627,   614,   615,
     616,   617,   618,   619,   620,   613,   621,   622,   623,   624,
     625,   626,     0,     0,     0,   447,     0,     0,   445,   446,
       0,   510,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   583,
       0,   557,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   460,   507,   509,   501,   502,   503,   504,   505,
     500,   471,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   497,   472,   473,   506,   475,   480,   481,   476,
     478,   477,   491,   492,   479,   482,   483,   484,   485,   474,
     487,   488,   489,   508,   498,   499,   496,   490,   486,   494,
     495,   493,     0,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,     0,   655,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   646,   647,   648,   649,   650,
     653,   651,   652,   654,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    68,    69,    67,    64,    63,    70,
      54,    66,    57,    58,    59,    55,    65,    60,    61,    62,
      56,     0,     0,     0,     0,   118,   119,   120,     0,   338,
       0,     0,   336,   337,     0,   103,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   611,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,   227,   230,   232,
     233,   234,   235,   236,   237,   238,   239,   228,   229,   231,
     240,   241,   242,     0,     0,     0,     0,     0,     0,     0,
     414,     0,     0,     0,     0,     0,     0,     0,     0,   389,
     390,   391,   392,   393,   394,   395,   397,   396,   399,   403,
     400,   401,   402,   398,   440,     0,     0,     0,   437,   438,
     439,     0,     0,   444,   455,     0,     0,     0,   452,   453,
     454,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   459,     0,     0,     0,   306,     0,     0,     0,     0,
       0,     0,   292,   293,   294,   295,   300,   296,   297,   298,
     299,   431,     0,     0,     0,   428,   429,   430,     0,     0,
       0,   267,     0,   277,     0,   275,   276,   278,   279,    48,
       0,     0,     0,    44,     0,     0,     0,     0,   110,   111,
     112,     0,     0,     0,   196,     0,     0,     0,     0,     0,
     170,     0,     0,   150,   151,   152,   153,   156,   157,   158,
     159,   155,   154,   160,     0,     0,     0,     0,     0,   326,
     327,   328,   329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   645,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,   372,     0,   367,   368,   369,
     121,     0,     0,   117,     0,     0,     0,   335,     0,     0,
     350,     0,     0,   343,   344,   345,   346,     0,     0,     0,
      97,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   610,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,   404,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   388,     0,     0,     0,   436,     0,   443,
       0,     0,     0,   451,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   458,   301,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,     0,     0,     0,
     427,   280,     0,     0,     0,     0,     0,   274,     0,     0,
      43,   113,     0,     0,     0,   109,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,   330,
       0,     0,     0,     0,   325,     0,     0,     0,     0,     0,
       0,     0,     0,   644,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,     0,
      75,    80,    81,     0,    79,     0,     0,    51,   370,     0,
       0,     0,   366,     0,   116,     0,     0,   334,   347,     0,
       0,     0,     0,   342,   106,   105,   104,   639,   638,   629,
     630,    27,    27,    27,    27,    27,    27,    27,    29,    28,
     631,   642,   643,   632,   633,   634,   637,   636,   635,   640,
     641,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   387,     0,     0,   435,   448,     0,
       0,   450,   523,   527,   542,   512,   609,   555,   549,   552,
     522,   514,   513,   516,   517,   515,   530,   520,   521,   531,
     519,   526,   525,   524,   550,   511,   607,   608,   546,   593,
     587,   603,   588,   589,   590,   598,   606,   591,   600,   604,
     594,   605,   595,   599,   592,   602,   597,   596,   601,     0,
     586,   548,   566,   567,   568,   561,   579,   562,   563,   564,
     574,   582,   565,   576,   580,   570,   581,   571,   575,   569,
     578,   573,   572,   577,     0,   560,   543,   541,   544,   554,
     545,   533,   539,   540,   537,   538,   534,   535,   536,   553,
     556,   518,   547,   529,   528,   551,   532,     0,     0,     0,
       0,     0,     0,     0,     0,   290,     0,     0,   426,     0,
       0,     0,   285,   281,   284,   266,    49,    50,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,     0,     0,     0,   324,   657,   656,   662,   660,
     663,   658,   659,   661,    88,    96,    87,    94,    95,    86,
      90,    89,    83,    82,    84,    93,    85,    72,     0,    73,
       0,    91,    92,     0,     0,   365,   122,     0,     0,     0,
     134,     0,   126,   127,   129,   128,   339,     0,     0,     0,
     341,    30,    31,    32,    33,    34,    35,    36,   254,   255,
     247,   264,   263,     0,   262,   249,   251,   258,   250,   248,
     257,   244,   256,   246,   245,    37,    37,    37,    39,    38,
     252,   253,   409,   412,   413,   423,   420,   406,   421,   418,
     419,     0,   417,   422,   405,   411,   408,   410,   424,   407,
     441,   442,   456,   457,   584,     0,   558,     0,   304,   305,
     314,   311,   316,   312,   313,   319,   315,   317,   310,   318,
       0,   309,   303,   322,   321,   320,   302,   433,   432,   288,
     287,   272,   273,   271,     0,   270,     0,     0,     0,   114,
     115,   169,   165,   216,   203,   213,   212,   201,   206,   222,
     215,   220,   205,   208,   217,   219,   214,   221,   209,   211,
     218,   207,   210,     0,   199,   162,   164,   166,   167,   168,
     179,   180,   181,   174,   192,   175,   176,   177,   187,   195,
     178,   189,   193,   183,   194,   184,   188,   182,   191,   186,
     185,   190,     0,   173,   163,   333,   331,   332,    74,    78,
     371,   376,   382,   385,   378,   384,   379,   383,   381,   377,
     380,     0,   375,   130,     0,     0,     0,     0,   125,   348,
     354,   360,   363,   356,   362,   357,   361,   359,   355,   358,
       0,   353,   349,   260,     0,    40,    41,    42,   415,     0,
     585,   559,   307,     0,   268,     0,   286,   283,   282,     0,
       0,     0,   197,     0,   171,     0,   373,     0,     0,     0,
       0,     0,   124,   351,     0,   261,   416,   308,   269,   202,
     200,   204,   198,   172,   374,   131,   133,   132,   140,   145,
     144,   139,   142,   146,   143,   138,   141,     0,   137,   352,
     135,     0,   136
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1032, -1032, -1032,  -281,  -313, -1031,  -633, -1032, -1032,   964,
   -1032, -1032, -1032, -1032,   961, -1032, -1032, -1032,    66, -1032,
      72, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,  1032, -1032,
   -1032, -1032, -1032, -1032, -1032,   603, -1032, -1032, -1032, -1032,
     821, -1032, -1032, -1032, -1032,    60, -1032, -1032, -1032, -1032,
   -1032,  -187, -1032, -1032, -1032,   594, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032,  -148, -1032, -1032,
   -1032,  -125, -1032, -1032, -1032,   822, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,  -101, -1032, -1032, -1032, -1032, -1032,
    -111, -1032,   654, -1032, -1032, -1032,     5, -1032, -1032, -1032,
   -1032, -1032,   682, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
     -99, -1032, -1032, -1032, -1032, -1032, -1032,   620, -1032, -1032,
   -1032, -1032, -1032,   962, -1032, -1032, -1032, -1032,   565, -1032,
   -1032, -1032, -1032, -1032,  -119, -1032, -1032, -1032,   587, -1032,
   -1032, -1032, -1032,   -91, -1032, -1032, -1032,   859, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,   -72,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,   699, -1032,
   -1032, -1032, -1032, -1032,   963, -1032, -1032, -1032, -1032,  1076,
   -1032, -1032, -1032, -1032,   791, -1032, -1032, -1032, -1032,  1023,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032,    78, -1032, -1032,
   -1032,    81, -1032, -1032, -1032, -1032, -1032,  1102, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032,   965, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   828,   829,  1088,  1089,    26,   228,   229,
     230,   231,    27,   272,   273,   274,   275,   789,   790,   793,
     794,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    28,    74,    75,    76,
      77,    78,    29,    61,   507,   508,   509,   510,    30,   294,
     295,   296,   297,   298,  1051,  1052,  1053,  1054,  1055,  1226,
    1297,  1298,    31,    62,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   755,  1202,  1203,   533,   749,
    1173,  1174,    32,    51,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   622,  1073,  1074,    33,    59,   493,   734,  1144,
    1145,   494,   495,   496,  1148,   993,   994,   497,   498,    34,
      57,   471,   472,   473,   474,   475,   476,   477,   719,  1130,
    1131,   478,   479,   480,    35,    63,   538,   539,   540,   541,
     542,    36,   301,   302,   303,    37,    69,   592,   593,   594,
     595,   596,   810,  1240,  1241,    38,    66,   576,   577,   578,
     579,   800,  1221,  1222,    39,    52,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   644,  1101,  1102,
     389,   390,   391,   392,   393,    40,    58,   484,   485,   486,
     487,    41,    53,   397,   398,   399,   400,    42,   117,   118,
     119,    43,    55,   407,   408,   409,   410,    44,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   440,   954,   955,   218,   438,
     929,   930,   219,   220,   221,    45,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    46,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     856,   857,   606,  1099,   608,   115,   610,   611,  1037,    49,
     504,    70,  1038,  1071,   292,   115,   534,   121,   588,   225,
    1141,   394,   122,   123,    50,  1039,   404,  1114,   124,  1040,
    1116,  1115,   292,  1047,  1117,    71,   125,   126,   700,    54,
     394,   701,    72,   127,   481,   573,   128,   129,    56,   225,
     535,   855,   130,   481,  1245,  1246,  1247,   131,   132,   254,
     133,   134,   135,  1243,   136,   305,   299,  1244,    60,   116,
    1248,  1252,   573,   137,  1249,  1253,  1254,   138,   139,   116,
    1255,   588,  1262,   255,   299,   395,  1263,    64,   140,  1072,
     505,   504,   702,   462,    65,   703,   536,  1264,   141,   665,
     666,  1265,  1047,   235,   395,    67,   142,   673,   143,   463,
     144,   677,   145,    73,   146,   147,   682,   256,   226,   685,
     589,  1085,  1086,  1087,   404,   464,   257,   148,   405,   695,
     696,   236,   149,   150,   151,  1048,   152,   153,   154,   237,
     708,   155,   227,   711,   712,   537,  1269,   574,   226,   258,
     396,   238,   239,   259,   488,   406,   240,   241,   242,   465,
    1142,   260,    47,    48,   261,   262,    70,   156,   300,   396,
    1143,   505,   227,   482,   574,   157,   158,   159,   160,   161,
     162,   243,   482,   589,   506,   328,   300,  1266,  -123,   511,
      71,  1267,   787,   788,  1100,    68,   263,    72,  1273,   329,
     330,   112,  1274,   331,  1048,   512,  -123,   163,  1300,   791,
     792,   489,  1301,   264,   113,   466,   265,   114,   490,   120,
     491,   513,   306,   467,   468,   855,   405,  1049,   307,  1211,
     222,   164,   165,   223,   166,   167,   168,   772,   293,   590,
     169,   266,   309,   591,   469,   170,   402,   763,   460,   812,
     502,   332,   656,   406,  1050,   514,   293,   662,   267,   268,
     269,   860,   861,   582,  1227,   506,   575,    79,    73,   483,
     333,   334,   335,   336,   224,   729,   801,   337,   483,   232,
     492,   338,   534,   233,   234,   270,   271,   339,    80,    81,
     571,   515,  1212,   575,    82,   488,  1049,   586,   340,   341,
     291,   363,   590,   364,   308,   365,   591,   304,   843,   311,
     342,   516,   847,   312,   597,   850,   535,   366,   470,   854,
     313,  1213,   744,  1050,   725,   314,   499,   517,  1214,    83,
      84,   315,   343,   367,   551,    85,    86,  1215,   316,   317,
     318,    87,    88,    89,   518,   519,   553,   319,   320,    90,
      91,    92,   489,   321,   322,   323,   324,   580,   368,   490,
     369,   491,   536,  1216,   325,  1217,  1218,   370,   401,   411,
     344,   412,   462,   413,   414,    93,    94,   415,   371,  1219,
     416,   417,   418,   419,   420,   736,  1220,   598,   463,   121,
     584,   421,   422,   520,   122,   123,   423,   424,   425,   599,
     124,   426,   427,   372,   464,   428,   429,   430,   125,   126,
     431,   537,   432,   433,   521,   127,   635,   434,   128,   129,
     757,   492,   601,   435,   130,   436,   437,   373,   439,   131,
     132,   441,   133,   134,   135,   511,   136,   442,   465,   443,
     444,   445,   446,   447,   448,   137,   449,   374,   450,   138,
     139,   512,   451,   452,   453,   454,   375,   455,   456,   363,
     140,   364,   457,   365,   254,   458,   459,   513,   500,   501,
     141,   543,   544,   545,   546,   366,   547,   548,   142,   549,
     143,   550,   144,   554,   145,   555,   146,   147,   255,   556,
     557,   367,   558,  1153,   466,   559,   560,  1288,   326,   148,
     376,   514,   467,   468,   149,   150,   151,  1154,   152,   153,
     154,   561,   562,   155,   563,  1155,   368,   564,   369,   565,
     566,   567,   256,   469,   568,   370,   569,   377,  1289,  1156,
    1290,   257,   652,   570,   600,  1120,   371,   515,   581,   156,
    1061,  1062,  1063,  1064,  1065,  1066,  1067,   157,   158,   159,
     160,   161,   162,   585,   258,   602,  1121,   516,   259,   603,
    1157,   372,  1158,   604,   605,  1122,   260,   607,   609,   261,
     262,   615,   612,   517,   613,   614,  1291,   616,   617,   163,
     618,   658,   619,   664,   620,   373,   621,   623,   624,  1159,
     518,   519,  1270,  1292,   625,   626,  1123,   470,   627,   628,
     629,   263,   630,   164,   165,   374,   166,   167,   168,   631,
     632,   633,   169,   634,   375,   637,   638,   170,   264,   639,
     640,   265,  1160,   641,  1161,   642,  1124,  1125,  1293,  1294,
     643,   645,   646,   647,  1126,   648,   649,   328,   650,   520,
     651,   654,   655,  1162,   659,   660,   266,   667,   661,   668,
     669,   329,   330,   670,   671,   331,   675,   672,   376,  1127,
     521,  1163,   674,   267,   268,   269,  1164,   676,   678,   683,
    1165,   684,   686,   687,   679,  1128,   688,  1166,   680,   681,
     689,   690,  1167,  1295,   692,   377,   691,  1296,   694,   909,
     270,   271,   697,     2,     3,   698,  1168,     4,   699,  1169,
     693,  1170,   704,   332,   705,   706,   707,     5,   709,   710,
       6,     7,  1171,   605,   713,   714,   715,     8,   716,  1172,
     717,   738,   333,   334,   335,   336,   718,   235,     9,   337,
     720,    10,    11,   338,   739,  1129,   721,   722,   723,   339,
     821,   822,   823,   824,   825,   826,   827,   724,   727,   728,
     340,   341,   731,   732,   733,   236,   740,   735,   741,    12,
     746,   759,   342,   237,    13,   742,   743,   932,   747,   933,
     934,   748,   750,    14,   768,   238,   239,   773,   751,   752,
     240,   241,   242,   753,   343,   754,   756,   760,   765,   766,
     767,   761,   774,   769,    15,    16,   762,   770,   771,   775,
     776,  1180,   777,  1181,  1182,   243,   910,   911,   912,  1230,
     913,   914,    17,   915,   916,   778,   917,   785,   918,   779,
     780,   919,   344,   781,   920,   921,   782,   922,   783,    18,
     797,   784,   923,   786,   795,   796,   924,   925,   926,   798,
     803,   799,    19,    20,   804,   805,   927,   806,   807,   808,
     809,   928,   814,   811,   815,   816,   817,   841,   818,   819,
     820,   830,    21,   831,   832,   833,   834,   842,   835,   836,
     837,   845,  1231,   838,   839,    22,   840,   846,   844,   848,
     849,   851,   852,    23,   935,   936,   937,    24,   938,   939,
     853,   940,   941,   855,   942,   863,   943,   858,   859,   944,
     862,  1232,   945,   946,   864,   947,   865,   866,  1233,   867,
     948,   868,   869,    79,   949,   950,   951,  1234,  1183,  1184,
    1185,   870,  1186,  1187,   952,  1188,  1189,   874,  1190,   953,
    1191,   871,   872,  1192,    80,    81,  1193,  1194,   873,  1195,
      82,   875,   876,  1235,  1196,  1236,  1237,   877,  1197,  1198,
    1199,   878,   879,   880,   881,   882,   883,   977,  1200,  1238,
     884,   885,   886,  1201,   887,   888,  1239,   980,   889,   890,
     891,   892,   893,   894,   895,    83,    84,   896,   897,   898,
     899,    85,    86,   981,   979,   982,   900,    87,    88,    89,
     901,   902,   903,   904,   905,    90,    91,    92,   992,   906,
     983,   984,   907,   986,   908,   931,   956,   987,   989,   990,
     957,   998,   999,   958,  1001,   959,   960,   961,   962,   963,
     964,    93,    94,   965,   991,   966,   967,   968,   969,   970,
     978,   971,   972,   973,  1002,  1004,   974,   975,   976,   985,
     988,  1005,   995,   996,  1006,  1007,   997,  1008,  1000,  1010,
    1012,  1013,  1003,  1009,  1011,  1014,  1043,  1015,  1016,  1017,
    1057,  1018,  1019,  1020,  1059,  1021,  1022,  1023,  1024,  1025,
    1256,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,
    1035,  1036,  1041,  1042,  1268,  1045,  1046,  1044,  1279,  1056,
    1058,  1060,  1068,  1069,  1070,  1075,  1076,  1077,  1078,  1079,
    1080,  1280,  1081,  1281,  1208,  1082,   310,  1083,  1084,  1090,
     745,  1228,  1209,  1091,  1302,   583,   758,  1283,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1118,  1119,  1282,  1132,
    1133,  1134,  1135,  1275,  1278,  1136,  1137,  1146,   737,  1138,
    1139,  1140,  1257,   726,  1277,  1299,  1149,   813,   764,  1147,
    1150,  1151,  1152,   802,  1175,  1176,  1177,   636,  1178,  1179,
    1204,  1205,  1206,  1207,  1210,  1223,  1284,  1276,  1229,  1224,
    1225,  1242,  1258,   730,  1259,  1260,  1272,  1271,  1261,  1285,
    1286,  1287,   503,   403,   461,  1251,  1250,   327,   663,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   552,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   572,     0,     0,     0,   653,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     657
};

static const yytype_int16 yycheck[] =
{
     633,   634,   315,     8,   317,     1,   319,   320,   231,   233,
       1,     1,   235,    53,     1,     1,     1,     1,     1,     1,
      49,     1,     6,     7,   233,   231,     1,   231,    12,   235,
     231,   235,     1,     1,   235,    25,    20,    21,   214,   233,
       1,   217,    32,    27,     1,     1,    30,    31,   233,     1,
      35,   113,    36,     1,  1085,  1086,  1087,    41,    42,     1,
      44,    45,    46,   231,    48,   231,     1,   235,   233,    65,
     231,   231,     1,    57,   235,   235,   231,    61,    62,    65,
     235,     1,   231,    25,     1,    65,   235,   233,    72,   129,
      81,     1,   214,     1,   233,   217,    81,   231,    82,   412,
     413,   235,     1,     1,    65,   233,    90,   420,    92,    17,
      94,   424,    96,   103,    98,    99,   429,    59,   100,   432,
     103,     9,    10,    11,     1,    33,    68,   111,   103,   442,
     443,    29,   116,   117,   118,   103,   120,   121,   122,    37,
     453,   125,   124,   456,   457,   130,   208,   103,   100,    91,
     130,    49,    50,    95,     1,   130,    54,    55,    56,    67,
     189,   103,   231,   232,   106,   107,     1,   151,   103,   130,
     199,    81,   124,   130,   103,   159,   160,   161,   162,   163,
     164,    79,   130,   103,   175,     1,   103,   231,   175,     1,
      25,   235,   203,   204,   199,   233,   138,    32,   231,    15,
      16,   233,   235,    19,   103,    17,   175,   191,   231,   203,
     204,    58,   235,   155,   233,   123,   158,   233,    65,   233,
      67,    33,   234,   131,   132,   113,   103,   195,   234,    73,
     233,   215,   216,   233,   218,   219,   220,   550,   225,   222,
     224,   183,   232,   226,   152,   229,   232,   232,   232,   232,
     232,    67,   232,   130,   222,    67,   225,   232,   200,   201,
     202,   179,   180,   232,   232,   175,   222,     1,   103,   226,
      86,    87,    88,    89,   233,   232,   232,    93,   226,   233,
     127,    97,     1,   233,   233,   227,   228,   103,    22,    23,
     232,   103,   136,   222,    28,     1,   195,   232,   114,   115,
     233,     1,   222,     3,   234,     5,   226,   233,   621,   234,
     126,   123,   625,   234,   128,   628,    35,    17,   226,   632,
     234,   165,   232,   222,   232,   234,   231,   139,   172,    63,
      64,   234,   148,    33,   232,    69,    70,   181,   234,   234,
     234,    75,    76,    77,   156,   157,   231,   234,   234,    83,
      84,    85,    58,   234,   234,   234,   234,   231,    58,    65,
      60,    67,    81,   207,   234,   209,   210,    67,   234,   234,
     186,   234,     1,   234,   234,   109,   110,   234,    78,   223,
     234,   234,   234,   234,   234,   232,   230,   128,    17,     1,
     175,   234,   234,   205,     6,     7,   234,   234,   234,   128,
      12,   234,   234,   103,    33,   234,   234,   234,    20,    21,
     234,   130,   234,   234,   226,    27,   232,   234,    30,    31,
     232,   127,   113,   234,    36,   234,   234,   127,   234,    41,
      42,   234,    44,    45,    46,     1,    48,   234,    67,   234,
     234,   234,   234,   234,   234,    57,   234,   147,   234,    61,
      62,    17,   234,   234,   234,   234,   156,   234,   234,     1,
      72,     3,   234,     5,     1,   234,   234,    33,   234,   234,
      82,   234,   234,   234,   234,    17,   234,   234,    90,   234,
      92,   234,    94,   234,    96,   234,    98,    99,    25,   234,
     234,    33,   234,     4,   123,   234,   234,    40,   232,   111,
     200,    67,   131,   132,   116,   117,   118,    18,   120,   121,
     122,   234,   234,   125,   234,    26,    58,   234,    60,   234,
     234,   234,    59,   152,   234,    67,   234,   227,    71,    40,
      73,    68,   232,   234,   231,    13,    78,   103,   234,   151,
     821,   822,   823,   824,   825,   826,   827,   159,   160,   161,
     162,   163,   164,   234,    91,   113,    34,   123,    95,   214,
      71,   103,    73,   113,   113,    43,   103,   113,   113,   106,
     107,   214,   113,   139,   113,   113,   119,   214,   231,   191,
     231,   128,   234,   214,   234,   127,   234,   234,   234,   100,
     156,   157,  1225,   136,   234,   234,    74,   226,   234,   234,
     234,   138,   234,   215,   216,   147,   218,   219,   220,   234,
     234,   234,   224,   234,   156,   231,   234,   229,   155,   234,
     234,   158,   133,   234,   135,   234,   104,   105,   171,   172,
     234,   234,   234,   234,   112,   234,   234,     1,   234,   205,
     234,   234,   234,   154,   231,   234,   183,   214,   234,   113,
     214,    15,    16,   113,   128,    19,   113,   214,   200,   137,
     226,   172,   214,   200,   201,   202,   177,   113,   113,   113,
     181,   113,   113,   113,   214,   153,   113,   188,   214,   214,
     113,   214,   193,   226,   214,   227,   234,   230,   214,    49,
     227,   228,   214,     0,     1,   214,   207,     4,   214,   210,
     234,   212,   214,    67,   214,   214,   128,    14,   214,   214,
      17,    18,   223,   113,   214,   214,   231,    24,   231,   230,
     234,   128,    86,    87,    88,    89,   234,     1,    35,    93,
     234,    38,    39,    97,   128,   213,   234,   234,   234,   103,
     140,   141,   142,   143,   144,   145,   146,   234,   234,   234,
     114,   115,   231,   234,   234,    29,   231,   234,   231,    66,
     231,   231,   126,    37,    71,   234,   234,    49,   234,    51,
      52,   234,   234,    80,   128,    49,    50,   231,   234,   234,
      54,    55,    56,   234,   148,   234,   234,   234,   214,   214,
     214,   234,   128,   214,   101,   102,   234,   214,   214,   214,
     128,    49,   113,    51,    52,    79,   166,   167,   168,    73,
     170,   171,   119,   173,   174,   113,   176,   113,   178,   128,
     128,   181,   186,   128,   184,   185,   128,   187,   128,   136,
     231,   128,   192,   128,   128,   128,   196,   197,   198,   231,
     214,   234,   149,   150,   231,   233,   206,   128,   231,   231,
     234,   211,   231,   234,   231,   231,   231,   113,   231,   231,
     231,   231,   169,   231,   231,   231,   231,   113,   231,   231,
     231,   113,   136,   231,   231,   182,   231,   113,   234,   113,
     113,   128,   113,   190,   166,   167,   168,   194,   170,   171,
     113,   173,   174,   113,   176,   214,   178,   231,   128,   181,
     128,   165,   184,   185,   128,   187,   128,   234,   172,   128,
     192,   128,   113,     1,   196,   197,   198,   181,   166,   167,
     168,   128,   170,   171,   206,   173,   174,   231,   176,   211,
     178,   128,   128,   181,    22,    23,   184,   185,   128,   187,
      28,   128,   128,   207,   192,   209,   210,   231,   196,   197,
     198,   231,   128,   128,   231,   231,   231,   128,   206,   223,
     231,   231,   231,   211,   231,   231,   230,   128,   231,   231,
     231,   231,   231,   231,   231,    63,    64,   231,   231,   231,
     231,    69,    70,   113,   234,   128,   231,    75,    76,    77,
     231,   231,   231,   231,   231,    83,    84,    85,   113,   231,
     128,   128,   231,   128,   231,   231,   231,   128,   128,   128,
     231,   128,   128,   231,   128,   231,   231,   231,   231,   231,
     231,   109,   110,   231,   234,   231,   231,   231,   231,   231,
     214,   231,   231,   231,   214,   128,   231,   231,   231,   231,
     231,   128,   231,   231,   128,   128,   231,   214,   231,   128,
     128,   128,   234,   234,   231,   128,   128,   231,   231,   231,
     128,   231,   231,   231,   128,   231,   231,   231,   231,   231,
     113,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   128,   231,   231,   234,   134,   231,
     234,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   134,   231,   134,  1038,   231,    74,   231,   231,   231,
     507,  1051,  1040,   231,  1301,   294,   522,  1265,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,  1263,   231,
     231,   231,   231,  1244,  1255,   231,   231,   221,   494,   231,
     231,   231,  1147,   471,  1253,  1274,   231,   592,   538,   235,
     231,   231,   231,   576,   231,   231,   231,   345,   231,   231,
     231,   231,   231,   231,   231,   231,  1267,  1249,   231,   234,
     234,   231,   231,   484,   236,   236,   231,   234,   236,   231,
     231,   231,   228,   117,   171,  1117,  1115,    95,   407,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,   378,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     397
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   238,     0,     1,     4,    14,    17,    18,    24,    35,
      38,    39,    66,    71,    80,   101,   102,   119,   136,   149,
     150,   169,   182,   190,   194,   239,   244,   249,   273,   279,
     285,   299,   319,   342,   356,   371,   378,   382,   392,   401,
     422,   428,   434,   438,   444,   502,   520,   231,   232,   233,
     233,   320,   402,   429,   233,   439,   233,   357,   423,   343,
     233,   280,   300,   372,   233,   233,   393,   233,   233,   383,
       1,    25,    32,   103,   274,   275,   276,   277,   278,     1,
      22,    23,    28,    63,    64,    69,    70,    75,    76,    77,
      83,    84,    85,   109,   110,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   233,   233,   233,     1,    65,   435,   436,   437,
     233,     1,     6,     7,    12,    20,    21,    27,    30,    31,
      36,    41,    42,    44,    45,    46,    48,    57,    61,    62,
      72,    82,    90,    92,    94,    96,    98,    99,   111,   116,
     117,   118,   120,   121,   122,   125,   151,   159,   160,   161,
     162,   163,   164,   191,   215,   216,   218,   219,   220,   224,
     229,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   495,   499,
     500,   501,   233,   233,   233,     1,   100,   124,   245,   246,
     247,   248,   233,   233,   233,     1,    29,    37,    49,    50,
      54,    55,    56,    79,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,     1,    25,    59,    68,    91,    95,
     103,   106,   107,   138,   155,   158,   183,   200,   201,   202,
     227,   228,   250,   251,   252,   253,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   233,     1,   225,   286,   287,   288,   289,   290,     1,
     103,   379,   380,   381,   233,   231,   234,   234,   234,   232,
     275,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   232,   504,     1,    15,
      16,    19,    67,    86,    87,    88,    89,    93,    97,   103,
     114,   115,   126,   148,   186,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,     1,     3,     5,    17,    33,    58,    60,
      67,    78,   103,   127,   147,   156,   200,   227,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   417,
     418,   419,   420,   421,     1,    65,   130,   430,   431,   432,
     433,   234,   232,   436,     1,   103,   130,   440,   441,   442,
     443,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   496,   234,
     492,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     232,   446,     1,    17,    33,    67,   123,   131,   132,   152,
     226,   358,   359,   360,   361,   362,   363,   364,   368,   369,
     370,     1,   130,   226,   424,   425,   426,   427,     1,    58,
      65,    67,   127,   344,   348,   349,   350,   354,   355,   231,
     234,   234,   232,   246,     1,    81,   175,   281,   282,   283,
     284,     1,    17,    33,    67,   103,   123,   139,   156,   157,
     205,   226,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   315,     1,    35,    81,   130,   373,   374,
     375,   376,   377,   234,   234,   234,   234,   234,   234,   234,
     234,   232,   522,   231,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   232,   251,     1,   103,   222,   394,   395,   396,   397,
     231,   234,   232,   287,   175,   234,   232,   380,     1,   103,
     222,   226,   384,   385,   386,   387,   388,   128,   128,   128,
     231,   113,   113,   214,   113,   113,   241,   113,   241,   113,
     241,   241,   113,   113,   113,   214,   214,   231,   231,   234,
     234,   234,   339,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   232,   322,   231,   234,   234,
     234,   234,   234,   234,   414,   234,   234,   234,   234,   234,
     234,   234,   232,   404,   234,   234,   232,   431,   128,   231,
     234,   234,   232,   441,   214,   241,   241,   214,   113,   214,
     113,   128,   214,   241,   214,   113,   113,   241,   113,   214,
     214,   214,   241,   113,   113,   241,   113,   113,   113,   113,
     214,   234,   214,   234,   214,   241,   241,   214,   214,   214,
     214,   217,   214,   217,   214,   214,   214,   128,   241,   214,
     214,   241,   241,   214,   214,   231,   231,   234,   234,   365,
     234,   234,   234,   234,   234,   232,   359,   234,   234,   232,
     425,   231,   234,   234,   345,   234,   232,   349,   128,   128,
     231,   231,   234,   234,   232,   282,   231,   234,   234,   316,
     234,   234,   234,   234,   234,   312,   234,   232,   302,   231,
     234,   234,   234,   232,   374,   214,   214,   214,   128,   214,
     214,   214,   241,   231,   128,   214,   128,   113,   113,   128,
     128,   128,   128,   128,   128,   113,   128,   203,   204,   254,
     255,   203,   204,   256,   257,   128,   128,   231,   231,   234,
     398,   232,   395,   214,   231,   233,   128,   231,   231,   234,
     389,   234,   232,   385,   231,   231,   231,   231,   231,   231,
     231,   140,   141,   142,   143,   144,   145,   146,   240,   241,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   113,   113,   241,   234,   113,   113,   241,   113,   113,
     241,   128,   113,   113,   241,   113,   243,   243,   231,   128,
     179,   180,   128,   214,   128,   128,   234,   128,   128,   113,
     128,   128,   128,   128,   231,   128,   128,   231,   231,   128,
     128,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,    49,
     166,   167,   168,   170,   171,   173,   174,   176,   178,   181,
     184,   185,   187,   192,   196,   197,   198,   206,   211,   497,
     498,   231,    49,    51,    52,   166,   167,   168,   170,   171,
     173,   174,   176,   178,   181,   184,   185,   187,   192,   196,
     197,   198,   206,   211,   493,   494,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   128,   214,   234,
     128,   113,   128,   128,   128,   231,   128,   128,   231,   128,
     128,   234,   113,   352,   353,   231,   231,   231,   128,   128,
     231,   128,   214,   234,   128,   128,   128,   128,   214,   234,
     128,   231,   128,   128,   128,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   235,   231,
     235,   231,   231,   128,   234,   231,   231,     1,   103,   195,
     222,   291,   292,   293,   294,   295,   231,   128,   234,   128,
     231,   240,   240,   240,   240,   240,   240,   240,   231,   231,
     231,    53,   129,   340,   341,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,     9,    10,    11,   242,   243,
     231,   231,   231,   231,   231,   231,   231,   231,   231,     8,
     199,   415,   416,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   235,   231,   235,   231,   231,
      13,    34,    43,    74,   104,   105,   112,   137,   153,   213,
     366,   367,   231,   231,   231,   231,   231,   231,   231,   231,
     231,    49,   189,   199,   346,   347,   221,   235,   351,   231,
     231,   231,   231,     4,    18,    26,    40,    71,    73,   100,
     133,   135,   154,   172,   177,   181,   188,   193,   207,   210,
     212,   223,   230,   317,   318,   231,   231,   231,   231,   231,
      49,    51,    52,   166,   167,   168,   170,   171,   173,   174,
     176,   178,   181,   184,   185,   187,   192,   196,   197,   198,
     206,   211,   313,   314,   231,   231,   231,   231,   255,   257,
     231,    73,   136,   165,   172,   181,   207,   209,   210,   223,
     230,   399,   400,   231,   234,   234,   296,   232,   292,   231,
      73,   136,   165,   172,   181,   207,   209,   210,   223,   230,
     390,   391,   231,   231,   235,   242,   242,   242,   231,   235,
     498,   494,   231,   235,   231,   235,   113,   353,   231,   236,
     236,   236,   231,   235,   231,   235,   231,   235,   128,   208,
     243,   234,   231,   231,   235,   341,   416,   367,   347,   134,
     134,   134,   318,   314,   400,   231,   231,   231,    40,    71,
      73,   119,   136,   171,   172,   226,   230,   297,   298,   391,
     231,   235,   298
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
     322,   322,   322,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   339,
     338,   340,   340,   341,   341,   343,   342,   345,   344,   346,
     346,   347,   347,   347,   348,   348,   349,   349,   349,   349,
     349,   351,   350,   352,   352,   353,   353,   354,   355,   357,
     356,   358,   358,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   360,   361,   362,   363,   365,   364,   366,   366,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     368,   369,   370,   372,   371,   373,   373,   374,   374,   374,
     374,   375,   376,   377,   378,   379,   379,   380,   380,   381,
     383,   382,   384,   384,   385,   385,   385,   385,   386,   387,
     389,   388,   390,   390,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   391,   393,   392,   394,   394,   395,   395,
     395,   396,   398,   397,   399,   399,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   402,   401,   403,   403,
     404,   404,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   412,   414,   413,   415,   415,   416,   416,
     417,   418,   419,   420,   421,   423,   422,   424,   424,   425,
     425,   425,   426,   427,   429,   428,   430,   430,   431,   431,
     431,   432,   433,   434,   435,   435,   436,   436,   437,   439,
     438,   440,   440,   441,   441,   441,   442,   443,   444,   445,
     445,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   473,   474,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   492,   491,   493,
     493,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   496,   495,   497,   497,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   499,   500,   501,
     502,   503,   503,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   521,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   523,   524,   525,   526,
     527,   528,   529,   530
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
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4
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
#line 410 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 439 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 445 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 479 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 485 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2995 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 494 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 3006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 500 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 3017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 508 "conf_parser.y" /* yacc.c:1646  */
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
#line 3062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 550 "conf_parser.y" /* yacc.c:1646  */
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
#line 3123 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 608 "conf_parser.y" /* yacc.c:1646  */
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
#line 3154 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 636 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 644 "conf_parser.y" /* yacc.c:1646  */
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
#line 3183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 659 "conf_parser.y" /* yacc.c:1646  */
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
#line 3201 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 674 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
#line 3213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 683 "conf_parser.y" /* yacc.c:1646  */
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
#line 3230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 697 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3242 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 706 "conf_parser.y" /* yacc.c:1646  */
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
#line 3273 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 734 "conf_parser.y" /* yacc.c:1646  */
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
#line 3306 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 764 "conf_parser.y" /* yacc.c:1646  */
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
#line 3334 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 789 "conf_parser.y" /* yacc.c:1646  */
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
#line 3359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 811 "conf_parser.y" /* yacc.c:1646  */
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
#line 3384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 833 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 850 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 868 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 880 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 884 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
    motd_add(ptr->data, block_state.file.buf);
}
#line 3455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 901 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 907 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 922 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 928 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 932 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 948 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 956 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 959 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 964 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3540 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 971 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3549 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 975 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 979 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 983 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 987 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 991 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3594 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 995 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3603 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 999 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3612 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1003 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3621 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1020 "conf_parser.y" /* yacc.c:1646  */
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
#line 3709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1106 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3718 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1112 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3727 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1118 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3736 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1124 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3750 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1135 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3759 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1141 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1147 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1158 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1164 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1171 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1175 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1179 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1183 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1187 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1195 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1199 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1203 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1207 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1211 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1215 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1219 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1223 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1227 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1231 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1235 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1239 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3971 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1247 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3980 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1251 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1261 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
#line 4070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1300 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1312 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1316 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1328 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1344 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4187 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1348 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1352 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1356 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1366 "conf_parser.y" /* yacc.c:1646  */
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

  case 224:
#line 1378 "conf_parser.y" /* yacc.c:1646  */
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

  case 244:
#line 1445 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4292 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1451 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1457 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1463 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1469 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1475 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4337 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1481 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4346 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1487 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4355 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1493 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1499 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1506 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1512 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1518 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1524 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1533 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1542 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1549 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1553 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1563 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1569 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1575 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1579 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1583 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1591 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1596 "conf_parser.y" /* yacc.c:1646  */
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

  case 286:
#line 1610 "conf_parser.y" /* yacc.c:1646  */
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

  case 287:
#line 1628 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4551 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1634 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1643 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1647 "conf_parser.y" /* yacc.c:1646  */
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

  case 302:
#line 1696 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1702 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4628 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1708 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4637 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1714 "conf_parser.y" /* yacc.c:1646  */
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

  case 306:
#line 1725 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4660 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1732 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4669 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1736 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4678 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1740 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4687 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1744 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4696 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1748 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1752 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1756 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1760 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1764 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1768 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4750 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1774 "conf_parser.y" /* yacc.c:1646  */
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

  case 321:
#line 1788 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4779 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1797 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1810 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4803 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1817 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1828 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1840 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1855 "conf_parser.y" /* yacc.c:1646  */
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

  case 340:
#line 1870 "conf_parser.y" /* yacc.c:1646  */
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

  case 341:
#line 1881 "conf_parser.y" /* yacc.c:1646  */
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

  case 348:
#line 1898 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1904 "conf_parser.y" /* yacc.c:1646  */
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

  case 350:
#line 1923 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1930 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1934 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1938 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1942 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1946 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1950 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1954 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1958 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5010 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1966 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5019 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1975 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5033 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1984 "conf_parser.y" /* yacc.c:1646  */
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

  case 371:
#line 1999 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2005 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2012 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2016 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2020 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2024 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2032 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2036 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2040 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2057 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2066 "conf_parser.y" /* yacc.c:1646  */
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

  case 405:
#line 2146 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2152 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2158 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2164 "conf_parser.y" /* yacc.c:1646  */
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

  case 409:
#line 2177 "conf_parser.y" /* yacc.c:1646  */
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

  case 410:
#line 2190 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2196 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5313 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2202 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5322 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2206 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2214 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2224 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2230 "conf_parser.y" /* yacc.c:1646  */
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

  case 421:
#line 2241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2247 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2253 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2259 "conf_parser.y" /* yacc.c:1646  */
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

  case 425:
#line 2274 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2278 "conf_parser.y" /* yacc.c:1646  */
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

  case 432:
#line 2303 "conf_parser.y" /* yacc.c:1646  */
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

  case 433:
#line 2323 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2336 "conf_parser.y" /* yacc.c:1646  */
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

  case 441:
#line 2362 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5524 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2368 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2382 "conf_parser.y" /* yacc.c:1646  */
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

  case 449:
#line 2399 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2403 "conf_parser.y" /* yacc.c:1646  */
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

  case 456:
#line 2425 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5590 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2431 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5599 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 511:
#line 2496 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 512:
#line 2501 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2507 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2513 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2519 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2525 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2530 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2535 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2540 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2545 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5683 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2550 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2555 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5699 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2560 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5707 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2565 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number);
}
#line 5715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2570 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2575 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5731 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2580 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5739 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2585 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2590 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5756 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2596 "conf_parser.y" /* yacc.c:1646  */
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

  case 531:
#line 2607 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5778 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2612 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_connect_block = yylval.number;
}
#line 5786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2617 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2622 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2627 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2632 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2637 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5826 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2640 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5834 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2645 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5842 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2648 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2653 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2658 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2663 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2668 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2673 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2678 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2683 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2688 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5914 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2693 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2698 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2703 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.use_egd = yylval.number;
}
#line 5938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2708 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
#line 5950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2717 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 5962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2726 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 5970 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2731 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 5978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2736 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = (yyvsp[-1].number);
}
#line 5986 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2741 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 5994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2747 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 6002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2750 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 6010 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2753 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 6018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2756 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 6026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2759 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 6034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 6042 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2765 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDECHANS;
}
#line 6050 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2768 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6058 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2771 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 6066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2774 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6082 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6090 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2783 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2789 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6114 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6122 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6130 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2798 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6154 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6162 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2815 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2821 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2824 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6194 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2827 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6202 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2830 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2833 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2836 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6226 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2839 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6234 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6242 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2845 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6250 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2851 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6266 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2854 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6274 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6282 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2860 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6290 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6298 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6306 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2869 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6314 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6322 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6330 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2878 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2883 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6346 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2888 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6354 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2893 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6362 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2923 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6370 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2929 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2934 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6386 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2939 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6394 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2944 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2949 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2954 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
#line 6418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2959 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[-1].number);
}
#line 6426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2964 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2979 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6458 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 2984 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6466 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 2989 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2994 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3016 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3022 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6518 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3040 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3049 "conf_parser.y" /* yacc.c:1646  */
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
#line 6547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3063 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6556 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3069 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6565 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6569 "conf_parser.c" /* yacc.c:1646  */
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
