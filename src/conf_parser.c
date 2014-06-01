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
    INVITE_DELAY = 318,
    INVITE_DELAY_CHANNEL = 319,
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
    KNOCK_DELAY = 330,
    KNOCK_DELAY_CHANNEL = 331,
    LEAF_MASK = 332,
    LINKS_DELAY = 333,
    LISTEN = 334,
    MASK = 335,
    MAX_ACCEPT = 336,
    MAX_BANS = 337,
    MAX_CHANS_PER_OPER = 338,
    MAX_CHANS_PER_USER = 339,
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
    T_OPERWALL = 440,
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
#define INVITE_DELAY 318
#define INVITE_DELAY_CHANNEL 319
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
#define KNOCK_DELAY 330
#define KNOCK_DELAY_CHANNEL 331
#define LEAF_MASK 332
#define LINKS_DELAY 333
#define LISTEN 334
#define MASK 335
#define MAX_ACCEPT 336
#define MAX_BANS 337
#define MAX_CHANS_PER_OPER 338
#define MAX_CHANS_PER_USER 339
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
#define T_OPERWALL 440
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
#define YYLAST   1264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  293
/* YYNRULES -- Number of rules.  */
#define YYNRULES  665
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1302

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
    1234,  1238,  1242,  1246,  1250,  1254,  1258,  1265,  1264,  1270,
    1270,  1271,  1275,  1279,  1283,  1287,  1291,  1295,  1299,  1303,
    1307,  1311,  1315,  1319,  1323,  1327,  1331,  1335,  1339,  1343,
    1347,  1351,  1355,  1359,  1363,  1374,  1373,  1434,  1434,  1435,
    1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,
    1446,  1446,  1447,  1448,  1449,  1450,  1452,  1458,  1464,  1470,
    1476,  1482,  1488,  1494,  1500,  1506,  1513,  1519,  1525,  1531,
    1540,  1550,  1549,  1555,  1555,  1556,  1560,  1571,  1570,  1577,
    1576,  1581,  1581,  1582,  1586,  1590,  1596,  1596,  1597,  1597,
    1597,  1597,  1597,  1599,  1599,  1601,  1601,  1603,  1617,  1635,
    1641,  1651,  1650,  1692,  1692,  1693,  1694,  1695,  1696,  1697,
    1698,  1699,  1700,  1701,  1703,  1709,  1715,  1721,  1733,  1732,
    1738,  1738,  1739,  1743,  1747,  1751,  1755,  1759,  1763,  1767,
    1771,  1775,  1781,  1795,  1804,  1818,  1817,  1832,  1832,  1833,
    1833,  1833,  1833,  1835,  1841,  1847,  1857,  1859,  1859,  1860,
    1860,  1862,  1878,  1877,  1902,  1902,  1903,  1903,  1903,  1903,
    1905,  1911,  1931,  1930,  1936,  1936,  1937,  1941,  1945,  1949,
    1953,  1957,  1961,  1965,  1969,  1973,  1983,  1982,  2003,  2003,
    2004,  2004,  2004,  2006,  2013,  2012,  2018,  2018,  2019,  2023,
    2027,  2031,  2035,  2039,  2043,  2047,  2051,  2055,  2065,  2064,
    2136,  2136,  2137,  2138,  2139,  2140,  2141,  2142,  2143,  2144,
    2145,  2146,  2147,  2148,  2149,  2150,  2151,  2153,  2159,  2165,
    2171,  2184,  2197,  2203,  2209,  2213,  2222,  2221,  2226,  2226,
    2227,  2231,  2237,  2248,  2254,  2260,  2266,  2282,  2281,  2307,
    2307,  2308,  2308,  2308,  2310,  2330,  2340,  2339,  2366,  2366,
    2367,  2367,  2367,  2369,  2375,  2384,  2386,  2386,  2387,  2387,
    2389,  2407,  2406,  2429,  2429,  2430,  2430,  2430,  2432,  2438,
    2447,  2450,  2450,  2451,  2452,  2453,  2454,  2455,  2456,  2457,
    2458,  2459,  2460,  2461,  2462,  2463,  2464,  2465,  2466,  2467,
    2468,  2469,  2470,  2471,  2472,  2473,  2474,  2475,  2476,  2477,
    2478,  2479,  2480,  2481,  2482,  2483,  2484,  2485,  2486,  2487,
    2488,  2489,  2490,  2491,  2492,  2493,  2494,  2495,  2496,  2497,
    2498,  2499,  2500,  2503,  2508,  2514,  2520,  2526,  2532,  2537,
    2542,  2547,  2552,  2557,  2562,  2567,  2572,  2577,  2582,  2587,
    2592,  2597,  2603,  2614,  2619,  2624,  2629,  2634,  2639,  2644,
    2647,  2652,  2655,  2660,  2665,  2670,  2675,  2680,  2685,  2690,
    2695,  2700,  2705,  2710,  2715,  2724,  2733,  2738,  2743,  2749,
    2748,  2753,  2753,  2754,  2757,  2760,  2763,  2766,  2769,  2772,
    2775,  2778,  2781,  2784,  2787,  2790,  2793,  2796,  2799,  2802,
    2805,  2808,  2811,  2814,  2817,  2820,  2826,  2825,  2830,  2830,
    2831,  2834,  2837,  2840,  2843,  2846,  2849,  2852,  2855,  2858,
    2861,  2864,  2867,  2870,  2873,  2876,  2879,  2882,  2885,  2888,
    2891,  2896,  2901,  2906,  2915,  2918,  2918,  2919,  2920,  2921,
    2922,  2923,  2924,  2925,  2926,  2927,  2928,  2929,  2930,  2931,
    2932,  2933,  2935,  2940,  2945,  2950,  2955,  2960,  2965,  2970,
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
  "INVITE_DELAY", "INVITE_DELAY_CHANNEL", "IP", "IRCD_AUTH", "IRCD_FLAGS",
  "IRCD_SID", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KNOCK_DELAY",
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY", "LISTEN", "MASK",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_OPER", "MAX_CHANS_PER_USER",
  "MAX_GLOBAL", "MAX_IDENT", "MAX_IDLE", "MAX_LOCAL", "MAX_NICK_CHANGES",
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
  "T_NCHANGE", "T_NONONREG", "T_OPERWALL", "T_RECVQ", "T_REJ", "T_RESTART",
  "T_SERVER", "T_SERVICE", "T_SERVICES_NAME", "T_SERVNOTICE", "T_SET",
  "T_SHARED", "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL",
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
  "channel_item", "channel_disable_fake_channels", "channel_knock_delay",
  "channel_knock_delay_channel", "channel_invite_delay",
  "channel_invite_delay_channel", "channel_max_chans_per_user",
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

#define YYPACT_NINF -1009

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1009)))

#define YYTABLE_NINF -124

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1009,   647, -1009,   -18,  -215,  -213, -1009, -1009, -1009,  -194,
   -1009,  -186, -1009, -1009, -1009,  -184, -1009, -1009, -1009,  -178,
    -176, -1009,  -168,  -115, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,   351,
     903,  -113,  -106,   -97,    20,   -81,   400,   -71,   -62,   -60,
      16,   -25,    -7,    -6,   707,   369,    -1,    35,    72,    53,
     -43,   -36,   -29,    79,    10, -1009, -1009, -1009, -1009, -1009,
      91,   103,   106,   107,   109,   112,   114,   115,   119,   120,
     121,   124,   126,   137,   281, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
     653,   532,   164, -1009,   141,    21, -1009, -1009,    70, -1009,
     143,   144,   145,   146,   148,   150,   151,   152,   153,   158,
     159,   161,   162,   163,   165,   166,   170,   171,   174,   175,
     177,   180,   183,   184,   185,   188,   189, -1009,   191, -1009,
     192,   195,   198,   199,   200,   204,   205,   209,   213,   215,
     216,   220,   221,   222,   224,   231,   232,   233,   236,    60,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
      61,     9,   262,    68,   239,   243,    25, -1009, -1009, -1009,
      51,   451,   230, -1009,   244,   245,   246,   248,   249,   251,
     252,   253,    14, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009,   101,   254,   256,   258,   260,   273,   277,   291,
     293,   294,   295,   297,   298,   300,   302,   305,   309,   311,
     134, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,    83,
     138,   313,    27, -1009, -1009, -1009,    80, -1009,   318,    24,
   -1009, -1009,     8, -1009,   241,   271,   288,   265, -1009,   352,
     436,   340,   443,   443,   444,   443,   443,   443,   445,   452,
     454,   354,   358,   345, -1009,   347,   346,   348,   350, -1009,
     359,   360,   364,   366,   367,   368,   371,   374,   377,   380,
     383,   387,   181, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
     355,   388,   389,   391,   393,   394,   396, -1009,   397,   398,
     401,   407,   408,   409,   410,   314, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009,   411,   412,    58, -1009, -1009, -1009,   458,   357,
   -1009, -1009,   415,   416,    40, -1009, -1009, -1009,   365,   443,
     443,   423,   540,   439,   543,   533,   448,   443,   453,   547,
     554,   443,   558,   460,   462,   465,   443,   569,   571,   443,
     576,   578,   579,   581,   480,   464,   482,   473,   495,   443,
     443,   496,   498,   501,   -54,   -28,   503,   505,   507,   595,
     443,   509,   510,   443,   443,   511,   515,   502, -1009,   506,
     508,   512, -1009,   516,   517,   518,   519,   520,    15, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,   524,
     526,    32, -1009, -1009, -1009,   537,   530,   535, -1009,   536,
   -1009,    30, -1009, -1009, -1009, -1009, -1009,   608,   616,   541,
   -1009,   544,   542,   556,    29, -1009, -1009, -1009,   546,   559,
     568, -1009,   570,   573,   574,   575,   580, -1009,   582,    12,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009,   557,   583,   584,   585,    18, -1009, -1009, -1009, -1009,
     589,   599,   607,   665,   609,   610,   612,   443,   591, -1009,
   -1009,   700,   615,   703,   719,   720,   706,   708,   709,   711,
     713,   715,   731,   723,    98,   135,   726,   728,   603, -1009,
     626,   613, -1009,    76, -1009, -1009, -1009, -1009,   644,   629,
   -1009,   628,   738,   637, -1009,   638,   636, -1009,   639,    23,
   -1009, -1009, -1009, -1009,   641,   643,   648, -1009,   649,   650,
     651,   561,   652,   655,   662,   667,   669,   670,   677,   680,
     682,   684,   685, -1009, -1009,   766,   772,   443,   676,   805,
     809,   443,   810,   811,   443,   797,   815,   817,   443,   818,
     818,   701, -1009, -1009,   807,    37,   808,   724,   813,   816,
     702,   819,   820,   825,   821,   822,   823,   824,   714, -1009,
     826,   827,   721, -1009,   725, -1009,   830,   831,   729, -1009,
     730,   733,   734,   737,   739,   740,   743,   744,   745,   746,
     749,   750,   751,   752,   753,   757,   758,   759,   760,   761,
     762,   763,   764,   765,   767,   768,   769,   614,   770,   679,
     771,   773,   774,   775,   776,   777,   778,   779,   782,   783,
     784,   785,   786,   787,   788,   789,   790,   791,   792,   793,
     794, -1009, -1009,   832,   755,   710,   836,   885,   876,   899,
     900,   798, -1009,   901,   904,   799, -1009, -1009,   905,   906,
     800,   923,   806, -1009,   812,   814, -1009, -1009,   909,   911,
     828, -1009, -1009,   912,   833,   829,   913,   914,   915,   917,
     834,   835,   919,   837, -1009, -1009,   922,   924,   925,   839,
   -1009,   840,   841,   842,   843,   844,   845,   846,   847, -1009,
     848,   849,   850,   851,   852,   853,   854,   855,   856,   857,
     858,   859,   860, -1009, -1009,  -208, -1009, -1009, -1009,  -197,
   -1009,   861,   862, -1009, -1009,   926,   863,   864, -1009,   865,
   -1009,   102,   867, -1009, -1009,   927,   866,   928,   868, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009,   443,   443,   443,   443,
     443,   443,   443, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009,   870,   871,   872,   -45,
     873,   874,   875,   877,   878,   879,   880,   881,   882,   883,
     312,   884,   886, -1009,   887,   888,   889,   890,   891,   892,
     893,    -4,   894,   895,   896,   897,   898,   902,   907, -1009,
     908,   910, -1009, -1009,   916,   918, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009,  -191, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009,  -185, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009,   920,   921,   299,   929,   930,   931,
     932,   933, -1009,   934,   935, -1009,   936,   937,   -35,   938,
     939, -1009, -1009, -1009, -1009,   940,   941, -1009,   942,   944,
     504,   945,   946,   947,   948,   949,   722,   950, -1009,   951,
     952,   953, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009,    98, -1009,   135, -1009, -1009,
     954,   403, -1009, -1009,   955,   956,   957, -1009,    11, -1009,
   -1009, -1009, -1009, -1009,   958,   732,   961, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
    -177, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009,   818,   818,   818, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,  -175, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009,   614, -1009,   679, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009,  -142, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009,   -41, -1009,   982,   923,   962, -1009, -1009, -1009, -1009,
   -1009,   959, -1009, -1009,   960, -1009, -1009, -1009, -1009,   963,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009,   -24, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009,    39, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
      50, -1009, -1009,   980,   -75,   964,   966, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,    65,
   -1009, -1009, -1009,   -45, -1009, -1009, -1009, -1009,    -4, -1009,
   -1009, -1009,   299, -1009,   -35, -1009, -1009, -1009,   983,   997,
     998, -1009,   504, -1009,   722, -1009,   403,   969,   970,   971,
     469, -1009, -1009,   732, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009,    95, -1009, -1009, -1009,
     469, -1009
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
       0,     0,     0,     0,     0,    99,   100,   102,   101,   631,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   616,   630,   620,   621,   618,
     619,   622,   623,   617,   624,   625,   626,   627,   628,   629,
       0,     0,     0,   449,     0,     0,   447,   448,     0,   512,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   586,     0,   559,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     462,   509,   511,   503,   504,   505,   506,   507,   502,   473,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     499,   474,   475,   508,   477,   482,   483,   478,   480,   479,
     493,   494,   481,   484,   485,   486,   487,   476,   489,   490,
     491,   510,   500,   501,   498,   492,   488,   496,   497,   495,
       0,     0,     0,     0,     0,     0,     0,    45,    46,    47,
       0,     0,     0,   657,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   648,   649,   650,   651,   652,   655,   653,
     654,   656,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    68,    69,    67,    64,    63,    70,    54,    66,
      57,    58,    59,    55,    65,    60,    61,    62,    56,     0,
       0,     0,     0,   118,   119,   120,     0,   340,     0,     0,
     338,   339,     0,   103,     0,     0,     0,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   615,     0,     0,     0,     0,   261,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,   229,   232,   234,   235,   236,   237,
     238,   239,   240,   241,   230,   231,   233,   242,   243,   244,
       0,     0,     0,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   399,   398,   401,   405,   402,   403,   404,
     400,   442,     0,     0,     0,   439,   440,   441,     0,     0,
     446,   457,     0,     0,     0,   454,   455,   456,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   461,     0,
       0,     0,   308,     0,     0,     0,     0,     0,     0,   294,
     295,   296,   297,   302,   298,   299,   300,   301,   433,     0,
       0,     0,   430,   431,   432,     0,     0,     0,   269,     0,
     279,     0,   277,   278,   280,   281,    48,     0,     0,     0,
      44,     0,     0,     0,     0,   110,   111,   112,     0,     0,
       0,   197,     0,     0,     0,     0,     0,   170,     0,     0,
     150,   151,   152,   153,   156,   157,   158,   159,   155,   154,
     160,     0,     0,     0,     0,     0,   328,   329,   330,   331,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   647,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,   374,     0,   369,   370,   371,   121,     0,     0,
     117,     0,     0,     0,   337,     0,     0,   352,     0,     0,
     345,   346,   347,   348,     0,     0,     0,    97,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   614,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   406,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   390,
       0,     0,     0,   438,     0,   445,     0,     0,     0,   453,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   460,   303,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,     0,     0,     0,   429,   282,     0,     0,
       0,     0,     0,   276,     0,     0,    43,   113,     0,     0,
       0,   109,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   332,     0,     0,     0,     0,
     327,     0,     0,     0,     0,     0,     0,     0,     0,   646,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    77,     0,    75,    80,    81,     0,
      79,     0,     0,    51,   372,     0,     0,     0,   368,     0,
     116,     0,     0,   336,   349,     0,     0,     0,     0,   344,
     106,   105,   104,   641,   640,   632,    27,    27,    27,    27,
      27,    27,    27,    29,    28,   635,   636,   644,   645,   633,
     634,   639,   638,   637,   642,   643,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   389,
       0,     0,   437,   450,     0,     0,   452,   525,   529,   544,
     514,   613,   557,   551,   554,   524,   516,   515,   518,   519,
     517,   532,   522,   523,   533,   521,   528,   527,   526,   552,
     513,   611,   612,   548,   596,   590,   607,   591,   592,   593,
     601,   610,   594,   604,   608,   597,   609,   602,   598,   603,
     595,   606,   600,   599,   605,     0,   589,   550,   568,   569,
     570,   563,   582,   564,   565,   566,   576,   585,   567,   579,
     583,   572,   584,   577,   573,   578,   571,   581,   575,   574,
     580,     0,   562,   545,   543,   546,   556,   547,   535,   541,
     542,   539,   540,   536,   537,   538,   555,   558,   520,   549,
     531,   530,   553,   534,     0,     0,     0,     0,     0,     0,
       0,     0,   292,     0,     0,   428,     0,     0,     0,   287,
     283,   286,   268,    49,    50,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,   326,   659,   658,   664,   662,   665,   660,   661,
     663,    88,    96,    87,    94,    95,    86,    90,    89,    83,
      82,    84,    93,    85,    72,     0,    73,     0,    91,    92,
       0,     0,   367,   122,     0,     0,     0,   134,     0,   126,
     127,   129,   128,   341,     0,     0,     0,   343,    30,    31,
      32,    33,    34,    35,    36,   256,   257,   249,   266,   265,
       0,   264,   251,   253,   260,   252,   250,   259,   246,   258,
     248,   247,    37,    37,    37,    39,    38,   254,   255,   411,
     414,   415,   425,   422,   408,   423,   420,   421,     0,   419,
     424,   407,   413,   410,   412,   426,   409,   443,   444,   458,
     459,   587,     0,   560,     0,   306,   307,   316,   313,   318,
     314,   315,   321,   317,   319,   312,   320,     0,   311,   305,
     324,   323,   322,   304,   435,   434,   290,   289,   274,   275,
     273,     0,   272,     0,     0,     0,   114,   115,   169,   165,
     217,   204,   214,   213,   202,   207,   224,   216,   222,   206,
     209,   219,   221,   218,   215,   223,   210,   212,   220,   208,
     211,     0,   200,   162,   164,   166,   167,   168,   179,   180,
     181,   174,   193,   175,   176,   177,   187,   196,   178,   190,
     194,   183,   195,   188,   184,   189,   182,   192,   186,   185,
     191,     0,   173,   163,   335,   333,   334,    74,    78,   373,
     378,   384,   387,   380,   386,   381,   385,   383,   379,   382,
       0,   377,   130,     0,     0,     0,     0,   125,   350,   356,
     362,   365,   358,   364,   359,   363,   361,   357,   360,     0,
     355,   351,   262,     0,    40,    41,    42,   417,     0,   588,
     561,   309,     0,   270,     0,   288,   285,   284,     0,     0,
       0,   198,     0,   171,     0,   375,     0,     0,     0,     0,
       0,   124,   353,     0,   263,   418,   310,   271,   203,   201,
     205,   199,   172,   376,   131,   133,   132,   140,   145,   144,
     139,   142,   146,   143,   138,   141,     0,   137,   354,   135,
       0,   136
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1009, -1009, -1009,  -317,  -310, -1008,  -629, -1009, -1009,   838,
   -1009, -1009, -1009, -1009,   780, -1009, -1009, -1009,  -454, -1009,
      19, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,   984, -1009,
   -1009, -1009, -1009, -1009, -1009,   553, -1009, -1009, -1009, -1009,
     943, -1009, -1009, -1009, -1009,    13, -1009, -1009, -1009, -1009,
   -1009,  -240, -1009, -1009, -1009,   548, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009,  -202, -1009, -1009,
   -1009,  -196, -1009, -1009, -1009,   795, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009,  -111, -1009, -1009, -1009, -1009, -1009,
    -189, -1009,   645, -1009, -1009, -1009,   -10, -1009, -1009, -1009,
   -1009, -1009,   672, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
    -117, -1009, -1009, -1009, -1009, -1009, -1009,   611, -1009, -1009,
   -1009, -1009, -1009,   965, -1009, -1009, -1009, -1009,   555, -1009,
   -1009, -1009, -1009, -1009,  -131, -1009, -1009, -1009,   572, -1009,
   -1009, -1009, -1009,  -123, -1009, -1009, -1009,   781, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,  -100,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,   673, -1009,
   -1009, -1009, -1009, -1009,   756, -1009, -1009, -1009, -1009,  1038,
   -1009, -1009, -1009, -1009,   754, -1009, -1009, -1009, -1009,   986,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009,    43, -1009, -1009,
   -1009,    57, -1009, -1009, -1009, -1009, -1009,  1076, -1009, -1009,
   -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009, -1009,   967, -1009, -1009, -1009, -1009, -1009,
   -1009, -1009, -1009
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   823,   824,  1085,  1086,    26,   226,   227,
     228,   229,    27,   270,   271,   272,   273,   785,   786,   789,
     790,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,    28,    74,    75,    76,
      77,    78,    29,    61,   504,   505,   506,   507,    30,   292,
     293,   294,   295,   296,  1048,  1049,  1050,  1051,  1052,  1225,
    1296,  1297,    31,    62,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   751,  1201,  1202,   530,   745,
    1171,  1172,    32,    51,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   618,  1070,  1071,    33,    59,   490,   730,  1141,
    1142,   491,   492,   493,  1145,   990,   991,   494,   495,    34,
      57,   468,   469,   470,   471,   472,   473,   474,   715,  1127,
    1128,   475,   476,   477,    35,    63,   535,   536,   537,   538,
     539,    36,   299,   300,   301,    37,    69,   589,   590,   591,
     592,   593,   806,  1239,  1240,    38,    66,   573,   574,   575,
     576,   796,  1220,  1221,    39,    52,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   640,  1098,  1099,
     386,   387,   388,   389,   390,    40,    58,   481,   482,   483,
     484,    41,    53,   394,   395,   396,   397,    42,   115,   116,
     117,    43,    55,   404,   405,   406,   407,    44,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   437,   951,   952,   216,   435,
     925,   926,   217,   218,   219,    45,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    46,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     851,   852,   602,   603,  1096,   605,   606,   607,  1068,   585,
     478,    70,  1044,   508,  1138,   233,   459,   223,    49,   531,
      50,   113,   113,  1034,   585,   297,   223,  1035,   290,   509,
     501,   485,   460,   478,  1036,    71,   290,   850,  1037,    54,
    1111,   401,    72,   234,  1112,   510,  1113,    56,   461,    60,
    1114,   235,   501,   532,  1242,    64,  1247,    65,  1243,   391,
    1248,   119,   459,   236,   237,    67,   120,   121,   238,   239,
     240,   401,   122,   297,  1244,  1245,  1246,   570,   460,   511,
     123,   124,   462,  1069,   570,   114,   114,   125,   486,  1251,
     126,   127,   241,  1252,   461,   487,   128,   488,   533,   661,
     662,   129,   130,  1044,   131,   132,   133,   669,   134,   502,
     586,   673,    73,  1045,   512,   224,   678,   135,    68,   681,
     110,   136,   137,   392,   224,   586,   298,   111,   462,   691,
     692,   502,   138,  1268,   513,   252,   112,   463,   479,   225,
     704,   139,   402,   707,   708,   464,   465,   534,   225,   140,
     514,   141,   118,   142,  1139,   143,   489,   144,   145,   253,
     696,   479,   220,   697,  1140,   391,   466,   515,   516,   403,
     146,   221,   402,   222,   298,   147,   148,   149,   571,   150,
     151,   152,   325,   463,   153,   571,   698,   393,   303,   699,
    1253,   464,   465,   254,  1254,  1097,   326,   327,   304,   403,
     328,  -123,   255,   503,  1045,   305,  1046,  1261,   230,  -123,
     154,  1262,   466,    47,    48,   855,   856,   517,   155,   156,
     157,   158,   159,   160,   256,   503,   231,   232,   257,   392,
     587,   531,   289,  1047,   588,   480,   258,   768,   518,   259,
     260,   467,   307,  1226,   753,   587,   548,   721,   329,   588,
     759,   161,   291,   399,   581,   808,   583,   499,   480,   579,
     291,   740,   732,   485,   725,   532,   330,   331,   332,   333,
    1263,   261,   658,   334,  1264,   162,   163,   335,   164,   165,
     166,  1265,    79,   336,   167,  1266,   302,   467,   262,   168,
     652,   263,   457,   393,   337,   338,  1272,  1046,   572,   496,
    1273,   783,   784,    80,    81,   572,   339,   838,   797,    82,
     533,   842,  1117,   306,   845,   360,   264,   361,   849,   362,
     486,  1082,  1083,  1084,  1047,   309,  1299,   487,   340,   488,
    1300,   363,   550,  1118,   265,   266,   267,   310,   787,   788,
     311,   312,  1119,   313,    83,    84,   314,   364,   315,   316,
      85,    86,    70,   317,   318,   319,    87,    88,   320,   534,
     321,   268,   269,    89,    90,    91,   568,   341,   594,   577,
     252,   322,   365,  1120,   366,   398,    71,   408,   409,   410,
     411,   367,   412,    72,   413,   414,   415,   416,   489,    92,
      93,   368,   417,   418,   253,   419,   420,   421,   595,   422,
     423,   119,  1121,  1122,   424,   425,   120,   121,   426,   427,
    1123,   428,   122,   631,   429,   596,   369,   430,   431,   432,
     123,   124,   433,   434,   850,   436,   438,   125,   254,   439,
     126,   127,   440,   441,   442,  1124,   128,   255,   443,   444,
     370,   129,   130,   445,   131,   132,   133,   446,   134,   447,
     448,  1125,   508,    73,   449,   450,   451,   135,   452,   256,
     371,   136,   137,   257,   598,   453,   454,   455,   509,   372,
     456,   258,   138,   497,   259,   260,  1210,   498,   540,   541,
     542,   139,   543,   544,   510,   545,   546,   547,   551,   140,
     552,   141,   553,   142,   554,   143,   597,   144,   145,  1058,
    1059,  1060,  1061,  1062,  1063,  1064,   261,   555,  1150,  1287,
     146,   556,  1126,   323,   373,   147,   148,   149,   511,   150,
     151,   152,  1151,   262,   153,   557,   263,   558,   559,   560,
    1152,   561,   562,   360,   563,   361,   564,   362,  1211,   565,
    1288,   374,  1289,   566,  1153,   567,   648,   578,   599,   363,
     154,   264,   582,   512,   600,   601,   604,   608,   155,   156,
     157,   158,   159,   160,   609,   364,   610,  1212,   611,   265,
     266,   267,   612,   513,  1213,  1154,   613,  1155,   614,   660,
     615,  1207,   616,  1214,   617,   654,   633,  1290,   655,   514,
     365,   161,   366,   619,   620,  1269,   268,   269,   621,   367,
     622,   623,   624,  1156,  1291,   625,   515,   516,   626,   368,
    1215,   627,  1216,  1217,   628,   162,   163,   629,   164,   165,
     166,   630,   634,   635,   167,   636,  1218,   637,   638,   168,
     639,   641,   642,  1219,   369,   643,  1157,   663,  1158,  1292,
    1293,   644,   645,   646,   647,   650,   651,     2,     3,   656,
     657,     4,   664,   665,   325,   666,   517,  1159,   370,   671,
     667,     5,   668,   904,     6,     7,   672,   670,   326,   327,
     674,     8,   328,   601,   675,  1160,   676,   518,   371,   677,
    1161,   679,     9,   680,  1162,    10,    11,   372,   682,  1163,
     683,   684,  1164,   685,   686,  1294,   688,  1165,   687,  1295,
     816,   817,   818,   819,   820,   821,   822,   689,   233,   690,
     693,  1166,   694,    12,  1167,   695,  1168,   700,    13,   701,
     329,   702,   703,   705,   706,   709,    14,  1169,   928,   710,
     929,   930,   373,   711,  1170,   734,   234,   712,   330,   331,
     332,   333,   713,   735,   235,   334,   714,    15,    16,   335,
     716,   717,   718,   719,   720,   336,   236,   237,   723,   374,
     724,   238,   239,   240,   728,    17,   337,   338,   727,   729,
     731,  1178,   736,  1179,  1180,   737,   738,   742,   339,   905,
     906,   907,    18,   908,   909,   241,   910,   911,   755,   912,
     739,   913,   764,   743,   914,    19,    20,   915,   916,   917,
     340,   918,   744,   761,   746,  1229,   919,   747,   748,   749,
     920,   921,   922,   762,   750,    21,   752,   756,   757,   758,
     923,   763,   769,   765,   766,   924,   767,   770,    22,   771,
     772,   773,   774,   775,   793,   776,   777,    23,   778,   341,
     779,    24,   780,   781,   931,   932,   933,   795,   934,   935,
     782,   936,   937,   791,   938,   792,   939,   794,   799,   940,
     800,   801,   941,   942,   943,   802,   944,  1230,   803,   804,
     805,   945,   810,   807,   811,   946,   947,   948,   836,   812,
     813,   814,   815,   825,   837,   949,   826,  1181,  1182,  1183,
     950,  1184,  1185,   827,  1186,  1187,  1231,  1188,   828,  1189,
     829,   830,  1190,  1232,    79,  1191,  1192,  1193,   831,  1194,
     839,   832,  1233,   833,  1195,   834,   835,   840,  1196,  1197,
    1198,   841,   843,   844,   846,    80,    81,   847,  1199,   848,
     850,    82,   853,  1200,   854,   857,   861,   864,   858,  1234,
     859,  1235,  1236,   860,   976,   869,   862,   863,   865,   866,
     867,   868,   872,   870,   871,  1237,   873,   874,   875,   974,
     876,   877,  1238,   977,   878,   879,    83,    84,   880,   975,
     881,   882,    85,    86,   883,   884,   885,   886,    87,    88,
     887,   888,   889,   890,   891,    89,    90,    91,   892,   893,
     894,   895,   896,   897,   898,   899,   900,   978,   901,   902,
     903,   927,   953,   979,   954,   955,   956,   957,   958,   959,
     960,    92,    93,   961,   962,   963,   964,   965,   966,   967,
     968,   969,   970,   971,   972,   973,   980,   981,   983,   982,
     985,   984,   986,   987,   988,   989,   995,   992,   996,   998,
    1001,  1002,  1003,   993,  1004,   994,  1007,   999,  1005,  1009,
     569,  1010,  1011,  1040,  1054,  1056,  1208,   741,   308,   997,
    1301,  1227,  1282,  1000,   500,  1277,  1281,   754,  1008,  1006,
    1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,
    1032,  1033,  1038,  1039,  1255,  1042,  1043,  1041,  1053,  1057,
    1055,  1065,  1066,  1067,  1072,  1073,  1074,  1267,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1087,  1278,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,  1100,  1101,  1102,  1103,  1104,
    1279,  1280,  1274,  1105,  1256,  1276,   733,   632,  1106,  1107,
     722,  1108,  1298,  1283,   809,   798,   760,  1109,  1275,  1110,
     653,  1115,  1116,   400,   726,   458,   649,  1250,   659,  1143,
    1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1249,
     324,  1146,  1147,  1148,  1144,  1149,  1173,  1174,  1175,  1176,
    1177,  1203,  1204,  1205,  1206,  1209,  1222,     0,     0,  1228,
    1223,  1224,  1241,  1257,     0,  1258,  1259,  1271,  1270,  1260,
    1284,  1285,  1286,     0,     0,     0,     0,     0,     0,   549,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   580,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   584
};

static const yytype_int16 yycheck[] =
{
     629,   630,   312,   313,     8,   315,   316,   317,    53,     1,
       1,     1,     1,     1,    49,     1,     1,     1,   233,     1,
     233,     1,     1,   231,     1,     1,     1,   235,     1,    17,
       1,     1,    17,     1,   231,    25,     1,   112,   235,   233,
     231,     1,    32,    29,   235,    33,   231,   233,    33,   233,
     235,    37,     1,    35,   231,   233,   231,   233,   235,     1,
     235,     1,     1,    49,    50,   233,     6,     7,    54,    55,
      56,     1,    12,     1,  1082,  1083,  1084,     1,    17,    67,
      20,    21,    67,   128,     1,    65,    65,    27,    58,   231,
      30,    31,    78,   235,    33,    65,    36,    67,    80,   409,
     410,    41,    42,     1,    44,    45,    46,   417,    48,    80,
     102,   421,   102,   102,   102,    99,   426,    57,   233,   429,
     233,    61,    62,    65,    99,   102,   102,   233,    67,   439,
     440,    80,    72,   208,   122,     1,   233,   122,   129,   123,
     450,    81,   102,   453,   454,   130,   131,   129,   123,    89,
     138,    91,   233,    93,   189,    95,   126,    97,    98,    25,
     214,   129,   233,   217,   199,     1,   151,   155,   156,   129,
     110,   233,   102,   233,   102,   115,   116,   117,   102,   119,
     120,   121,     1,   122,   124,   102,   214,   129,   231,   217,
     231,   130,   131,    59,   235,   199,    15,    16,   234,   129,
      19,   174,    68,   174,   102,   234,   195,   231,   233,   174,
     150,   235,   151,   231,   232,   178,   179,   205,   158,   159,
     160,   161,   162,   163,    90,   174,   233,   233,    94,    65,
     222,     1,   233,   222,   226,   226,   102,   547,   226,   105,
     106,   226,   232,   232,   232,   222,   232,   232,    67,   226,
     232,   191,   225,   232,   174,   232,   232,   232,   226,   232,
     225,   232,   232,     1,   232,    35,    85,    86,    87,    88,
     231,   137,   232,    92,   235,   215,   216,    96,   218,   219,
     220,   231,     1,   102,   224,   235,   233,   226,   154,   229,
     232,   157,   232,   129,   113,   114,   231,   195,   222,   231,
     235,   203,   204,    22,    23,   222,   125,   617,   232,    28,
      80,   621,    13,   234,   624,     1,   182,     3,   628,     5,
      58,     9,    10,    11,   222,   234,   231,    65,   147,    67,
     235,    17,   231,    34,   200,   201,   202,   234,   203,   204,
     234,   234,    43,   234,    63,    64,   234,    33,   234,   234,
      69,    70,     1,   234,   234,   234,    75,    76,   234,   129,
     234,   227,   228,    82,    83,    84,   232,   186,   127,   231,
       1,   234,    58,    74,    60,   234,    25,   234,   234,   234,
     234,    67,   234,    32,   234,   234,   234,   234,   126,   108,
     109,    77,   234,   234,    25,   234,   234,   234,   127,   234,
     234,     1,   103,   104,   234,   234,     6,     7,   234,   234,
     111,   234,    12,   232,   234,   127,   102,   234,   234,   234,
      20,    21,   234,   234,   112,   234,   234,    27,    59,   234,
      30,    31,   234,   234,   234,   136,    36,    68,   234,   234,
     126,    41,    42,   234,    44,    45,    46,   234,    48,   234,
     234,   152,     1,   102,   234,   234,   234,    57,   234,    90,
     146,    61,    62,    94,   112,   234,   234,   234,    17,   155,
     234,   102,    72,   234,   105,   106,    73,   234,   234,   234,
     234,    81,   234,   234,    33,   234,   234,   234,   234,    89,
     234,    91,   234,    93,   234,    95,   231,    97,    98,   816,
     817,   818,   819,   820,   821,   822,   137,   234,     4,    40,
     110,   234,   213,   232,   200,   115,   116,   117,    67,   119,
     120,   121,    18,   154,   124,   234,   157,   234,   234,   234,
      26,   234,   234,     1,   234,     3,   234,     5,   135,   234,
      71,   227,    73,   234,    40,   234,   232,   234,   112,    17,
     150,   182,   234,   102,   214,   112,   112,   112,   158,   159,
     160,   161,   162,   163,   112,    33,   112,   164,   214,   200,
     201,   202,   214,   122,   171,    71,   231,    73,   231,   214,
     234,  1035,   234,   180,   234,   127,   231,   118,   231,   138,
      58,   191,    60,   234,   234,  1224,   227,   228,   234,    67,
     234,   234,   234,    99,   135,   234,   155,   156,   234,    77,
     207,   234,   209,   210,   234,   215,   216,   234,   218,   219,
     220,   234,   234,   234,   224,   234,   223,   234,   234,   229,
     234,   234,   234,   230,   102,   234,   132,   214,   134,   170,
     171,   234,   234,   234,   234,   234,   234,     0,     1,   234,
     234,     4,   112,   214,     1,   112,   205,   153,   126,   112,
     127,    14,   214,    49,    17,    18,   112,   214,    15,    16,
     112,    24,    19,   112,   214,   171,   214,   226,   146,   214,
     176,   112,    35,   112,   180,    38,    39,   155,   112,   185,
     112,   112,   188,   112,   214,   226,   214,   193,   234,   230,
     139,   140,   141,   142,   143,   144,   145,   234,     1,   214,
     214,   207,   214,    66,   210,   214,   212,   214,    71,   214,
      67,   214,   127,   214,   214,   214,    79,   223,    49,   214,
      51,    52,   200,   231,   230,   127,    29,   231,    85,    86,
      87,    88,   234,   127,    37,    92,   234,   100,   101,    96,
     234,   234,   234,   234,   234,   102,    49,    50,   234,   227,
     234,    54,    55,    56,   234,   118,   113,   114,   231,   234,
     234,    49,   231,    51,    52,   231,   234,   231,   125,   165,
     166,   167,   135,   169,   170,    78,   172,   173,   231,   175,
     234,   177,   127,   234,   180,   148,   149,   183,   184,   185,
     147,   187,   234,   214,   234,    73,   192,   234,   234,   234,
     196,   197,   198,   214,   234,   168,   234,   234,   234,   234,
     206,   214,   231,   214,   214,   211,   214,   127,   181,   214,
     127,   112,   112,   127,   231,   127,   127,   190,   127,   186,
     127,   194,   127,   112,   165,   166,   167,   234,   169,   170,
     127,   172,   173,   127,   175,   127,   177,   231,   214,   180,
     231,   233,   183,   184,   185,   127,   187,   135,   231,   231,
     234,   192,   231,   234,   231,   196,   197,   198,   112,   231,
     231,   231,   231,   231,   112,   206,   231,   165,   166,   167,
     211,   169,   170,   231,   172,   173,   164,   175,   231,   177,
     231,   231,   180,   171,     1,   183,   184,   185,   231,   187,
     234,   231,   180,   231,   192,   231,   231,   112,   196,   197,
     198,   112,   112,   112,   127,    22,    23,   112,   206,   112,
     112,    28,   231,   211,   127,   127,   234,   112,   214,   207,
     127,   209,   210,   127,   234,   231,   127,   127,   127,   127,
     127,   127,   231,   127,   127,   223,   231,   127,   127,   127,
     231,   231,   230,   127,   231,   231,    63,    64,   231,   214,
     231,   231,    69,    70,   231,   231,   231,   231,    75,    76,
     231,   231,   231,   231,   231,    82,    83,    84,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   112,   231,   231,
     231,   231,   231,   127,   231,   231,   231,   231,   231,   231,
     231,   108,   109,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   127,   127,   127,   231,
     231,   127,   127,   127,   234,   112,   127,   231,   127,   127,
     127,   127,   127,   231,   127,   231,   127,   214,   214,   127,
     270,   127,   127,   127,   127,   127,  1037,   504,    74,   231,
    1300,  1048,  1264,   234,   226,  1254,  1262,   519,   231,   234,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   112,   231,   231,   234,   231,   231,
     234,   231,   231,   231,   231,   231,   231,   127,   231,   231,
     231,   231,   231,   231,   231,   231,   133,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     133,   133,  1243,   231,  1144,  1252,   491,   342,   231,   231,
     468,   231,  1273,  1266,   589,   573,   535,   231,  1248,   231,
     394,   231,   231,   115,   481,   169,   375,  1114,   404,   221,
     231,   231,   231,   231,   231,   231,   231,   231,   231,  1112,
      94,   231,   231,   231,   235,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,    -1,    -1,   231,
     234,   234,   231,   231,    -1,   236,   236,   231,   234,   236,
     231,   231,   231,    -1,    -1,    -1,    -1,    -1,    -1,   242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   292,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   299
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   238,     0,     1,     4,    14,    17,    18,    24,    35,
      38,    39,    66,    71,    79,   100,   101,   118,   135,   148,
     149,   168,   181,   190,   194,   239,   244,   249,   273,   279,
     285,   299,   319,   342,   356,   371,   378,   382,   392,   401,
     422,   428,   434,   438,   444,   502,   519,   231,   232,   233,
     233,   320,   402,   429,   233,   439,   233,   357,   423,   343,
     233,   280,   300,   372,   233,   233,   393,   233,   233,   383,
       1,    25,    32,   102,   274,   275,   276,   277,   278,     1,
      22,    23,    28,    63,    64,    69,    70,    75,    76,    82,
      83,    84,   108,   109,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     233,   233,   233,     1,    65,   435,   436,   437,   233,     1,
       6,     7,    12,    20,    21,    27,    30,    31,    36,    41,
      42,    44,    45,    46,    48,    57,    61,    62,    72,    81,
      89,    91,    93,    95,    97,    98,   110,   115,   116,   117,
     119,   120,   121,   124,   150,   158,   159,   160,   161,   162,
     163,   191,   215,   216,   218,   219,   220,   224,   229,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   495,   499,   500,   501,
     233,   233,   233,     1,    99,   123,   245,   246,   247,   248,
     233,   233,   233,     1,    29,    37,    49,    50,    54,    55,
      56,    78,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,     1,    25,    59,    68,    90,    94,   102,   105,
     106,   137,   154,   157,   182,   200,   201,   202,   227,   228,
     250,   251,   252,   253,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   233,
       1,   225,   286,   287,   288,   289,   290,     1,   102,   379,
     380,   381,   233,   231,   234,   234,   234,   232,   275,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   232,   504,     1,    15,    16,    19,    67,
      85,    86,    87,    88,    92,    96,   102,   113,   114,   125,
     147,   186,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
       1,     3,     5,    17,    33,    58,    60,    67,    77,   102,
     126,   146,   155,   200,   227,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   417,   418,   419,   420,
     421,     1,    65,   129,   430,   431,   432,   433,   234,   232,
     436,     1,   102,   129,   440,   441,   442,   443,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   496,   234,   492,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   232,   446,     1,
      17,    33,    67,   122,   130,   131,   151,   226,   358,   359,
     360,   361,   362,   363,   364,   368,   369,   370,     1,   129,
     226,   424,   425,   426,   427,     1,    58,    65,    67,   126,
     344,   348,   349,   350,   354,   355,   231,   234,   234,   232,
     246,     1,    80,   174,   281,   282,   283,   284,     1,    17,
      33,    67,   102,   122,   138,   155,   156,   205,   226,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     315,     1,    35,    80,   129,   373,   374,   375,   376,   377,
     234,   234,   234,   234,   234,   234,   234,   234,   232,   521,
     231,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   232,   251,
       1,   102,   222,   394,   395,   396,   397,   231,   234,   232,
     287,   174,   234,   232,   380,     1,   102,   222,   226,   384,
     385,   386,   387,   388,   127,   127,   127,   231,   112,   112,
     214,   112,   241,   241,   112,   241,   241,   241,   112,   112,
     112,   214,   214,   231,   231,   234,   234,   234,   339,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   232,   322,   231,   234,   234,   234,   234,   234,   234,
     414,   234,   234,   234,   234,   234,   234,   234,   232,   404,
     234,   234,   232,   431,   127,   231,   234,   234,   232,   441,
     214,   241,   241,   214,   112,   214,   112,   127,   214,   241,
     214,   112,   112,   241,   112,   214,   214,   214,   241,   112,
     112,   241,   112,   112,   112,   112,   214,   234,   214,   234,
     214,   241,   241,   214,   214,   214,   214,   217,   214,   217,
     214,   214,   214,   127,   241,   214,   214,   241,   241,   214,
     214,   231,   231,   234,   234,   365,   234,   234,   234,   234,
     234,   232,   359,   234,   234,   232,   425,   231,   234,   234,
     345,   234,   232,   349,   127,   127,   231,   231,   234,   234,
     232,   282,   231,   234,   234,   316,   234,   234,   234,   234,
     234,   312,   234,   232,   302,   231,   234,   234,   234,   232,
     374,   214,   214,   214,   127,   214,   214,   214,   241,   231,
     127,   214,   127,   112,   112,   127,   127,   127,   127,   127,
     127,   112,   127,   203,   204,   254,   255,   203,   204,   256,
     257,   127,   127,   231,   231,   234,   398,   232,   395,   214,
     231,   233,   127,   231,   231,   234,   389,   234,   232,   385,
     231,   231,   231,   231,   231,   231,   139,   140,   141,   142,
     143,   144,   145,   240,   241,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   112,   112,   241,   234,
     112,   112,   241,   112,   112,   241,   127,   112,   112,   241,
     112,   243,   243,   231,   127,   178,   179,   127,   214,   127,
     127,   234,   127,   127,   112,   127,   127,   127,   127,   231,
     127,   127,   231,   231,   127,   127,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,    49,   165,   166,   167,   169,   170,
     172,   173,   175,   177,   180,   183,   184,   185,   187,   192,
     196,   197,   198,   206,   211,   497,   498,   231,    49,    51,
      52,   165,   166,   167,   169,   170,   172,   173,   175,   177,
     180,   183,   184,   185,   187,   192,   196,   197,   198,   206,
     211,   493,   494,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   127,   214,   234,   127,   112,   127,
     127,   127,   231,   127,   127,   231,   127,   127,   234,   112,
     352,   353,   231,   231,   231,   127,   127,   231,   127,   214,
     234,   127,   127,   127,   127,   214,   234,   127,   231,   127,
     127,   127,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   235,   231,   235,   231,   231,
     127,   234,   231,   231,     1,   102,   195,   222,   291,   292,
     293,   294,   295,   231,   127,   234,   127,   231,   240,   240,
     240,   240,   240,   240,   240,   231,   231,   231,    53,   128,
     340,   341,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,     9,    10,    11,   242,   243,   231,   231,   231,
     231,   231,   231,   231,   231,   231,     8,   199,   415,   416,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   235,   231,   235,   231,   231,    13,    34,    43,
      74,   103,   104,   111,   136,   152,   213,   366,   367,   231,
     231,   231,   231,   231,   231,   231,   231,   231,    49,   189,
     199,   346,   347,   221,   235,   351,   231,   231,   231,   231,
       4,    18,    26,    40,    71,    73,    99,   132,   134,   153,
     171,   176,   180,   185,   188,   193,   207,   210,   212,   223,
     230,   317,   318,   231,   231,   231,   231,   231,    49,    51,
      52,   165,   166,   167,   169,   170,   172,   173,   175,   177,
     180,   183,   184,   185,   187,   192,   196,   197,   198,   206,
     211,   313,   314,   231,   231,   231,   231,   255,   257,   231,
      73,   135,   164,   171,   180,   207,   209,   210,   223,   230,
     399,   400,   231,   234,   234,   296,   232,   292,   231,    73,
     135,   164,   171,   180,   207,   209,   210,   223,   230,   390,
     391,   231,   231,   235,   242,   242,   242,   231,   235,   498,
     494,   231,   235,   231,   235,   112,   353,   231,   236,   236,
     236,   231,   235,   231,   235,   231,   235,   127,   208,   243,
     234,   231,   231,   235,   341,   416,   367,   347,   133,   133,
     133,   318,   314,   400,   231,   231,   231,    40,    71,    73,
     118,   135,   170,   171,   226,   230,   297,   298,   391,   231,
     235,   298
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
     314,   314,   314,   314,   314,   314,   314,   316,   315,   317,
     317,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   320,   319,   321,   321,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   339,   338,   340,   340,   341,   341,   343,   342,   345,
     344,   346,   346,   347,   347,   347,   348,   348,   349,   349,
     349,   349,   349,   351,   350,   352,   352,   353,   353,   354,
     355,   357,   356,   358,   358,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   360,   361,   362,   363,   365,   364,
     366,   366,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   368,   369,   370,   372,   371,   373,   373,   374,
     374,   374,   374,   375,   376,   377,   378,   379,   379,   380,
     380,   381,   383,   382,   384,   384,   385,   385,   385,   385,
     386,   387,   389,   388,   390,   390,   391,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   393,   392,   394,   394,
     395,   395,   395,   396,   398,   397,   399,   399,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   402,   401,
     403,   403,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   404,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   412,   414,   413,   415,   415,
     416,   416,   417,   418,   419,   420,   421,   423,   422,   424,
     424,   425,   425,   425,   426,   427,   429,   428,   430,   430,
     431,   431,   431,   432,   433,   434,   435,   435,   436,   436,
     437,   439,   438,   440,   440,   441,   441,   441,   442,   443,
     444,   445,   445,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     473,   474,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   492,
     491,   493,   493,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   496,   495,   497,   497,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   499,   500,   501,   502,   503,   503,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   520,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   522,   523,
     524,   525,   526,   527,   528,   529
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
#line 410 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 439 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 445 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 479 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 485 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 494 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 500 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2995 "conf_parser.c" /* yacc.c:1646  */
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
#line 3040 "conf_parser.c" /* yacc.c:1646  */
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
#line 3101 "conf_parser.c" /* yacc.c:1646  */
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
#line 3132 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 636 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3143 "conf_parser.c" /* yacc.c:1646  */
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
#line 3161 "conf_parser.c" /* yacc.c:1646  */
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
#line 3179 "conf_parser.c" /* yacc.c:1646  */
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
#line 3191 "conf_parser.c" /* yacc.c:1646  */
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
#line 3208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 697 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3220 "conf_parser.c" /* yacc.c:1646  */
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
#line 3251 "conf_parser.c" /* yacc.c:1646  */
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
#line 3284 "conf_parser.c" /* yacc.c:1646  */
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
#line 3312 "conf_parser.c" /* yacc.c:1646  */
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
#line 3337 "conf_parser.c" /* yacc.c:1646  */
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
#line 3362 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 833 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3371 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 850 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3395 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 868 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 880 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3416 "conf_parser.c" /* yacc.c:1646  */
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
#line 3433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 901 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 907 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 922 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 928 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3469 "conf_parser.c" /* yacc.c:1646  */
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
#line 3482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 948 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3493 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 956 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3501 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 959 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 964 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3518 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 971 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3527 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 975 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3536 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 979 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3545 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 983 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3554 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 987 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 991 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 995 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 999 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3590 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1003 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3599 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3611 "conf_parser.c" /* yacc.c:1646  */
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
#line 3687 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1106 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3696 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1112 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1118 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3714 "conf_parser.c" /* yacc.c:1646  */
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
#line 3728 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1135 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3737 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1141 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3746 "conf_parser.c" /* yacc.c:1646  */
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
#line 3760 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1158 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3769 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1164 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3778 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1171 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3787 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1175 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3796 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1179 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3805 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1183 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1187 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1195 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1199 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1203 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1207 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1211 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1215 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1219 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1223 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1227 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
#line 3913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1231 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1235 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1239 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1247 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1251 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1259 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4003 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
#line 4057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1300 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1312 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1316 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1328 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
#line 4156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1344 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1348 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1352 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1356 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1360 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4201 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1364 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1374 "conf_parser.y" /* yacc.c:1646  */
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
#line 4227 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1386 "conf_parser.y" /* yacc.c:1646  */
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
#line 4279 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1453 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1459 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4297 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1465 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4306 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1471 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4315 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1477 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1483 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1489 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1495 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4351 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1501 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1507 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4370 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1514 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1520 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1526 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1532 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1541 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4421 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1550 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4430 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1557 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1561 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1571 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1577 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1583 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1587 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1591 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1599 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1604 "conf_parser.y" /* yacc.c:1646  */
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
#line 4517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1618 "conf_parser.y" /* yacc.c:1646  */
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
#line 4538 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1636 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1642 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4556 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1651 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1655 "conf_parser.y" /* yacc.c:1646  */
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
#line 4606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1704 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1710 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1716 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1722 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4647 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1733 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4656 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1740 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1744 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4674 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1748 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4683 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1752 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4692 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1756 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4701 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1760 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4710 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1764 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4719 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1768 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4728 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1772 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4737 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1776 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4746 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1782 "conf_parser.y" /* yacc.c:1646  */
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
#line 4763 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1796 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1805 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4787 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1818 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4799 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1825 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1836 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4819 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1842 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4828 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1848 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1863 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1878 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1889 "conf_parser.y" /* yacc.c:1646  */
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
#line 4885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1906 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1912 "conf_parser.y" /* yacc.c:1646  */
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
#line 4916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1931 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1938 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1942 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1946 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1950 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1954 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4970 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1958 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4979 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4988 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1966 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4997 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1970 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1974 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1983 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1992 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2007 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2020 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2024 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2032 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2036 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5107 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2040 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2052 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2056 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2065 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5166 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2074 "conf_parser.y" /* yacc.c:1646  */
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
#line 5232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2154 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2160 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5250 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2166 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5259 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2172 "conf_parser.y" /* yacc.c:1646  */
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
#line 5275 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2185 "conf_parser.y" /* yacc.c:1646  */
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
#line 5291 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2198 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2210 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2214 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5329 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2222 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5337 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2228 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5346 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5355 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2238 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2261 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2267 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2282 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5419 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2286 "conf_parser.y" /* yacc.c:1646  */
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
#line 5444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2311 "conf_parser.y" /* yacc.c:1646  */
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
#line 5467 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2331 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5485 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2344 "conf_parser.y" /* yacc.c:1646  */
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
#line 5511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2370 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2376 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2390 "conf_parser.y" /* yacc.c:1646  */
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
#line 5546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2407 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2411 "conf_parser.y" /* yacc.c:1646  */
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
#line 5577 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2433 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5586 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2439 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5595 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2504 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5603 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2509 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5612 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2515 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5621 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2521 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5630 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2527 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5639 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2533 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5647 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2538 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5655 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2543 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5663 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2548 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5671 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2553 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2558 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5687 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2563 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5695 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2568 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5703 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2573 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number);
}
#line 5711 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2578 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5719 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2583 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5727 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2588 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5735 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2593 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5743 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2598 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5752 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2604 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5766 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2615 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5774 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2620 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_connect_block = yylval.number;
}
#line 5782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2625 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5790 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2630 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5798 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2635 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5806 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2640 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2645 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5822 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2648 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5830 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2653 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2656 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2661 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2666 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5862 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2671 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5870 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2676 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5878 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2681 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2686 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2691 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2696 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2701 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2706 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2711 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.use_egd = yylval.number;
}
#line 5934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2716 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
#line 5946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2725 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 5958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2734 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 5966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2739 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 5974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2744 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = (yyvsp[-1].number);
}
#line 5982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2749 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 5990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2755 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 5998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2758 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 6006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2761 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 6014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2764 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 6022 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2767 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 6030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2770 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 6038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2773 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDECHANS;
}
#line 6046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2776 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2779 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 6062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2782 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2785 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2788 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2791 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2794 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2797 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
#line 6110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2800 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2803 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2806 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2809 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2812 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2815 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6158 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2818 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6166 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2821 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2826 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2832 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2835 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6198 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2838 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2841 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2844 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2847 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2850 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2853 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2856 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2859 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6262 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2862 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2865 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2868 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
#line 6286 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2871 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2874 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6302 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2877 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2880 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2883 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2886 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6334 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2889 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2892 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2897 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2902 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2907 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2936 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2941 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay = (yyvsp[-1].number);
}
#line 6390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2946 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2951 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_delay = (yyvsp[-1].number);
}
#line 6406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2956 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2961 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
#line 6422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2966 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[-1].number);
}
#line 6430 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2971 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2976 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 2981 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 2986 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2991 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2996 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3001 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3023 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6495 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6513 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6522 "conf_parser.c" /* yacc.c:1646  */
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
#line 6534 "conf_parser.c" /* yacc.c:1646  */
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
#line 6551 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3076 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6569 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6573 "conf_parser.c" /* yacc.c:1646  */
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
