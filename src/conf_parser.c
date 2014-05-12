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
    IP = 318,
    IRCD_AUTH = 319,
    IRCD_FLAGS = 320,
    IRCD_SID = 321,
    JOIN_FLOOD_COUNT = 322,
    JOIN_FLOOD_TIME = 323,
    KILL = 324,
    KILL_CHASE_TIME_LIMIT = 325,
    KLINE = 326,
    KLINE_EXEMPT = 327,
    KNOCK_DELAY = 328,
    KNOCK_DELAY_CHANNEL = 329,
    LEAF_MASK = 330,
    LINKS_DELAY = 331,
    LISTEN = 332,
    MASK = 333,
    MAX_ACCEPT = 334,
    MAX_BANS = 335,
    MAX_CHANS_PER_OPER = 336,
    MAX_CHANS_PER_USER = 337,
    MAX_GLOBAL = 338,
    MAX_IDENT = 339,
    MAX_IDLE = 340,
    MAX_LOCAL = 341,
    MAX_NICK_CHANGES = 342,
    MAX_NICK_LENGTH = 343,
    MAX_NICK_TIME = 344,
    MAX_NUMBER = 345,
    MAX_TARGETS = 346,
    MAX_TOPIC_LENGTH = 347,
    MAX_WATCH = 348,
    MIN_IDLE = 349,
    MIN_NONWILDCARD = 350,
    MIN_NONWILDCARD_SIMPLE = 351,
    MODULE = 352,
    MODULES = 353,
    MOTD = 354,
    NAME = 355,
    NEED_IDENT = 356,
    NEED_PASSWORD = 357,
    NETWORK_DESC = 358,
    NETWORK_NAME = 359,
    NICK = 360,
    NO_CREATE_ON_SPLIT = 361,
    NO_JOIN_ON_SPLIT = 362,
    NO_OPER_FLOOD = 363,
    NO_TILDE = 364,
    NUMBER = 365,
    NUMBER_PER_CIDR = 366,
    NUMBER_PER_IP = 367,
    OPER_ONLY_UMODES = 368,
    OPER_PASS_RESV = 369,
    OPER_UMODES = 370,
    OPERATOR = 371,
    OPERS_BYPASS_CALLERID = 372,
    PACE_WAIT = 373,
    PACE_WAIT_SIMPLE = 374,
    PASSWORD = 375,
    PATH = 376,
    PING_COOKIE = 377,
    PING_TIME = 378,
    PORT = 379,
    QSTRING = 380,
    RANDOM_IDLE = 381,
    REASON = 382,
    REDIRPORT = 383,
    REDIRSERV = 384,
    REHASH = 385,
    REMOTE = 386,
    REMOTEBAN = 387,
    RESV = 388,
    RESV_EXEMPT = 389,
    RSA_PRIVATE_KEY_FILE = 390,
    RSA_PUBLIC_KEY_FILE = 391,
    SECONDS = 392,
    MINUTES = 393,
    HOURS = 394,
    DAYS = 395,
    WEEKS = 396,
    MONTHS = 397,
    YEARS = 398,
    SEND_PASSWORD = 399,
    SENDQ = 400,
    SERVERHIDE = 401,
    SERVERINFO = 402,
    SHORT_MOTD = 403,
    SPOOF = 404,
    SPOOF_NOTICE = 405,
    SQUIT = 406,
    SSL_CERTIFICATE_FILE = 407,
    SSL_CERTIFICATE_FINGERPRINT = 408,
    SSL_CONNECTION_REQUIRED = 409,
    SSL_DH_PARAM_FILE = 410,
    STATS_E_DISABLED = 411,
    STATS_I_OPER_ONLY = 412,
    STATS_K_OPER_ONLY = 413,
    STATS_O_OPER_ONLY = 414,
    STATS_P_OPER_ONLY = 415,
    STATS_U_OPER_ONLY = 416,
    T_ALL = 417,
    T_BOTS = 418,
    T_CALLERID = 419,
    T_CCONN = 420,
    T_CLUSTER = 421,
    T_DEAF = 422,
    T_DEBUG = 423,
    T_DLINE = 424,
    T_EXTERNAL = 425,
    T_FARCONNECT = 426,
    T_FILE = 427,
    T_FULL = 428,
    T_GLOBOPS = 429,
    T_INVISIBLE = 430,
    T_IPV4 = 431,
    T_IPV6 = 432,
    T_LOCOPS = 433,
    T_LOG = 434,
    T_MAX_CLIENTS = 435,
    T_NCHANGE = 436,
    T_NONONREG = 437,
    T_OPERWALL = 438,
    T_RECVQ = 439,
    T_REJ = 440,
    T_RESTART = 441,
    T_SERVER = 442,
    T_SERVICE = 443,
    T_SERVICES_NAME = 444,
    T_SERVNOTICE = 445,
    T_SET = 446,
    T_SHARED = 447,
    T_SIZE = 448,
    T_SKILL = 449,
    T_SOFTCALLERID = 450,
    T_SPY = 451,
    T_SSL = 452,
    T_SSL_CIPHER_LIST = 453,
    T_SSL_CLIENT_METHOD = 454,
    T_SSL_SERVER_METHOD = 455,
    T_SSLV3 = 456,
    T_TLSV1 = 457,
    T_UMODES = 458,
    T_UNAUTH = 459,
    T_UNDLINE = 460,
    T_UNLIMITED = 461,
    T_UNRESV = 462,
    T_UNXLINE = 463,
    T_WALLOP = 464,
    T_WALLOPS = 465,
    T_WEBIRC = 466,
    TBOOL = 467,
    THROTTLE_TIME = 468,
    TKLINE_EXPIRE_NOTICES = 469,
    TMASKED = 470,
    TRUE_NO_OPER_FLOOD = 471,
    TS_MAX_DELTA = 472,
    TS_WARN_DELTA = 473,
    TWODOTS = 474,
    TYPE = 475,
    UNKLINE = 476,
    USE_EGD = 477,
    USE_LOGGING = 478,
    USER = 479,
    VHOST = 480,
    VHOST6 = 481,
    WARN_NO_CONNECT_BLOCK = 482,
    XLINE = 483
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
#define IP 318
#define IRCD_AUTH 319
#define IRCD_FLAGS 320
#define IRCD_SID 321
#define JOIN_FLOOD_COUNT 322
#define JOIN_FLOOD_TIME 323
#define KILL 324
#define KILL_CHASE_TIME_LIMIT 325
#define KLINE 326
#define KLINE_EXEMPT 327
#define KNOCK_DELAY 328
#define KNOCK_DELAY_CHANNEL 329
#define LEAF_MASK 330
#define LINKS_DELAY 331
#define LISTEN 332
#define MASK 333
#define MAX_ACCEPT 334
#define MAX_BANS 335
#define MAX_CHANS_PER_OPER 336
#define MAX_CHANS_PER_USER 337
#define MAX_GLOBAL 338
#define MAX_IDENT 339
#define MAX_IDLE 340
#define MAX_LOCAL 341
#define MAX_NICK_CHANGES 342
#define MAX_NICK_LENGTH 343
#define MAX_NICK_TIME 344
#define MAX_NUMBER 345
#define MAX_TARGETS 346
#define MAX_TOPIC_LENGTH 347
#define MAX_WATCH 348
#define MIN_IDLE 349
#define MIN_NONWILDCARD 350
#define MIN_NONWILDCARD_SIMPLE 351
#define MODULE 352
#define MODULES 353
#define MOTD 354
#define NAME 355
#define NEED_IDENT 356
#define NEED_PASSWORD 357
#define NETWORK_DESC 358
#define NETWORK_NAME 359
#define NICK 360
#define NO_CREATE_ON_SPLIT 361
#define NO_JOIN_ON_SPLIT 362
#define NO_OPER_FLOOD 363
#define NO_TILDE 364
#define NUMBER 365
#define NUMBER_PER_CIDR 366
#define NUMBER_PER_IP 367
#define OPER_ONLY_UMODES 368
#define OPER_PASS_RESV 369
#define OPER_UMODES 370
#define OPERATOR 371
#define OPERS_BYPASS_CALLERID 372
#define PACE_WAIT 373
#define PACE_WAIT_SIMPLE 374
#define PASSWORD 375
#define PATH 376
#define PING_COOKIE 377
#define PING_TIME 378
#define PORT 379
#define QSTRING 380
#define RANDOM_IDLE 381
#define REASON 382
#define REDIRPORT 383
#define REDIRSERV 384
#define REHASH 385
#define REMOTE 386
#define REMOTEBAN 387
#define RESV 388
#define RESV_EXEMPT 389
#define RSA_PRIVATE_KEY_FILE 390
#define RSA_PUBLIC_KEY_FILE 391
#define SECONDS 392
#define MINUTES 393
#define HOURS 394
#define DAYS 395
#define WEEKS 396
#define MONTHS 397
#define YEARS 398
#define SEND_PASSWORD 399
#define SENDQ 400
#define SERVERHIDE 401
#define SERVERINFO 402
#define SHORT_MOTD 403
#define SPOOF 404
#define SPOOF_NOTICE 405
#define SQUIT 406
#define SSL_CERTIFICATE_FILE 407
#define SSL_CERTIFICATE_FINGERPRINT 408
#define SSL_CONNECTION_REQUIRED 409
#define SSL_DH_PARAM_FILE 410
#define STATS_E_DISABLED 411
#define STATS_I_OPER_ONLY 412
#define STATS_K_OPER_ONLY 413
#define STATS_O_OPER_ONLY 414
#define STATS_P_OPER_ONLY 415
#define STATS_U_OPER_ONLY 416
#define T_ALL 417
#define T_BOTS 418
#define T_CALLERID 419
#define T_CCONN 420
#define T_CLUSTER 421
#define T_DEAF 422
#define T_DEBUG 423
#define T_DLINE 424
#define T_EXTERNAL 425
#define T_FARCONNECT 426
#define T_FILE 427
#define T_FULL 428
#define T_GLOBOPS 429
#define T_INVISIBLE 430
#define T_IPV4 431
#define T_IPV6 432
#define T_LOCOPS 433
#define T_LOG 434
#define T_MAX_CLIENTS 435
#define T_NCHANGE 436
#define T_NONONREG 437
#define T_OPERWALL 438
#define T_RECVQ 439
#define T_REJ 440
#define T_RESTART 441
#define T_SERVER 442
#define T_SERVICE 443
#define T_SERVICES_NAME 444
#define T_SERVNOTICE 445
#define T_SET 446
#define T_SHARED 447
#define T_SIZE 448
#define T_SKILL 449
#define T_SOFTCALLERID 450
#define T_SPY 451
#define T_SSL 452
#define T_SSL_CIPHER_LIST 453
#define T_SSL_CLIENT_METHOD 454
#define T_SSL_SERVER_METHOD 455
#define T_SSLV3 456
#define T_TLSV1 457
#define T_UMODES 458
#define T_UNAUTH 459
#define T_UNDLINE 460
#define T_UNLIMITED 461
#define T_UNRESV 462
#define T_UNXLINE 463
#define T_WALLOP 464
#define T_WALLOPS 465
#define T_WEBIRC 466
#define TBOOL 467
#define THROTTLE_TIME 468
#define TKLINE_EXPIRE_NOTICES 469
#define TMASKED 470
#define TRUE_NO_OPER_FLOOD 471
#define TS_MAX_DELTA 472
#define TS_WARN_DELTA 473
#define TWODOTS 474
#define TYPE 475
#define UNKLINE 476
#define USE_EGD 477
#define USE_LOGGING 478
#define USER 479
#define VHOST 480
#define VHOST6 481
#define WARN_NO_CONNECT_BLOCK 482
#define XLINE 483

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 146 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 685 "conf_parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 700 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  661
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1292

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   483

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
       2,     2,     2,     2,   233,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   234,   229,
       2,   232,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   231,     2,   230,     2,     2,     2,     2,
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
     225,   226,   227,   228
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   378,   378,   379,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   408,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   419,   419,   420,
     421,   422,   423,   430,   433,   433,   434,   434,   434,   436,
     442,   449,   451,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   472,   473,   475,   475,   476,   482,   490,   490,
     491,   497,   505,   547,   605,   633,   641,   656,   671,   680,
     694,   703,   731,   761,   786,   808,   830,   839,   841,   841,
     842,   843,   844,   845,   847,   856,   865,   878,   877,   895,
     895,   896,   896,   896,   898,   904,   913,   914,   914,   916,
     916,   917,   919,   926,   926,   939,   940,   942,   942,   943,
     943,   945,   953,   956,   962,   961,   967,   967,   968,   972,
     976,   980,   984,   988,   992,   996,  1000,  1011,  1010,  1090,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,
    1100,  1101,  1103,  1109,  1115,  1121,  1132,  1138,  1144,  1155,
    1162,  1161,  1167,  1167,  1168,  1172,  1176,  1180,  1184,  1188,
    1192,  1196,  1200,  1204,  1208,  1212,  1216,  1220,  1224,  1228,
    1232,  1236,  1240,  1244,  1248,  1252,  1256,  1263,  1262,  1268,
    1268,  1269,  1273,  1277,  1281,  1285,  1289,  1293,  1297,  1301,
    1305,  1309,  1313,  1317,  1321,  1325,  1329,  1333,  1337,  1341,
    1345,  1349,  1353,  1357,  1361,  1372,  1371,  1432,  1432,  1433,
    1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,
    1444,  1444,  1445,  1446,  1447,  1448,  1450,  1456,  1462,  1468,
    1474,  1480,  1486,  1492,  1498,  1504,  1511,  1517,  1523,  1529,
    1538,  1548,  1547,  1553,  1553,  1554,  1558,  1569,  1568,  1575,
    1574,  1579,  1579,  1580,  1584,  1588,  1594,  1594,  1595,  1595,
    1595,  1595,  1595,  1597,  1597,  1599,  1599,  1601,  1615,  1633,
    1639,  1649,  1648,  1690,  1690,  1691,  1692,  1693,  1694,  1695,
    1696,  1697,  1698,  1699,  1701,  1707,  1713,  1719,  1731,  1730,
    1736,  1736,  1737,  1741,  1745,  1749,  1753,  1757,  1761,  1765,
    1769,  1773,  1779,  1793,  1802,  1816,  1815,  1830,  1830,  1831,
    1831,  1831,  1831,  1833,  1839,  1845,  1855,  1857,  1857,  1858,
    1858,  1860,  1876,  1875,  1900,  1900,  1901,  1901,  1901,  1901,
    1903,  1909,  1929,  1928,  1934,  1934,  1935,  1939,  1943,  1947,
    1951,  1955,  1959,  1963,  1967,  1971,  1981,  1980,  2001,  2001,
    2002,  2002,  2002,  2004,  2011,  2010,  2016,  2016,  2017,  2021,
    2025,  2029,  2033,  2037,  2041,  2045,  2049,  2053,  2063,  2062,
    2134,  2134,  2135,  2136,  2137,  2138,  2139,  2140,  2141,  2142,
    2143,  2144,  2145,  2146,  2147,  2148,  2149,  2151,  2157,  2163,
    2169,  2182,  2195,  2201,  2207,  2211,  2220,  2219,  2224,  2224,
    2225,  2229,  2235,  2246,  2252,  2258,  2264,  2280,  2279,  2305,
    2305,  2306,  2306,  2306,  2308,  2328,  2338,  2337,  2364,  2364,
    2365,  2365,  2365,  2367,  2373,  2382,  2384,  2384,  2385,  2385,
    2387,  2405,  2404,  2427,  2427,  2428,  2428,  2428,  2430,  2436,
    2445,  2448,  2448,  2449,  2450,  2451,  2452,  2453,  2454,  2455,
    2456,  2457,  2458,  2459,  2460,  2461,  2462,  2463,  2464,  2465,
    2466,  2467,  2468,  2469,  2470,  2471,  2472,  2473,  2474,  2475,
    2476,  2477,  2478,  2479,  2480,  2481,  2482,  2483,  2484,  2485,
    2486,  2487,  2488,  2489,  2490,  2491,  2492,  2493,  2494,  2495,
    2496,  2497,  2498,  2501,  2506,  2512,  2518,  2524,  2530,  2535,
    2540,  2545,  2550,  2555,  2560,  2565,  2570,  2575,  2580,  2585,
    2590,  2595,  2601,  2612,  2617,  2622,  2627,  2632,  2637,  2642,
    2645,  2650,  2653,  2658,  2663,  2668,  2673,  2678,  2683,  2688,
    2693,  2698,  2703,  2708,  2713,  2722,  2731,  2736,  2741,  2747,
    2746,  2751,  2751,  2752,  2755,  2758,  2761,  2764,  2767,  2770,
    2773,  2776,  2779,  2782,  2785,  2788,  2791,  2794,  2797,  2800,
    2803,  2806,  2809,  2812,  2815,  2818,  2824,  2823,  2828,  2828,
    2829,  2832,  2835,  2838,  2841,  2844,  2847,  2850,  2853,  2856,
    2859,  2862,  2865,  2868,  2871,  2874,  2877,  2880,  2883,  2886,
    2889,  2894,  2899,  2904,  2913,  2916,  2916,  2917,  2918,  2919,
    2920,  2921,  2922,  2923,  2924,  2925,  2926,  2927,  2928,  2929,
    2931,  2936,  2941,  2946,  2951,  2956,  2961,  2966,  2971,  2976,
    2981,  2986,  2994,  2997,  2997,  2998,  2999,  3000,  3001,  3002,
    3003,  3004,  3005,  3006,  3008,  3014,  3020,  3026,  3032,  3041,
    3055,  3061
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
  "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID", "JOIN_FLOOD_COUNT",
  "JOIN_FLOOD_TIME", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE",
  "KLINE_EXEMPT", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK",
  "LINKS_DELAY", "LISTEN", "MASK", "MAX_ACCEPT", "MAX_BANS",
  "MAX_CHANS_PER_OPER", "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT",
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
     475,   476,   477,   478,   479,   480,   481,   482,   483,    59,
     125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -1020

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1020)))

#define YYTABLE_NINF -124

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1020,   742, -1020,  -200,  -226,  -218, -1020, -1020, -1020,  -210,
   -1020,  -193, -1020, -1020, -1020,  -191, -1020, -1020, -1020,  -131,
    -129, -1020,   -98,   -60, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,   333,
     309,   -43,   -41,   -35,    25,   -21,   449,   -19,   -11,    -2,
      46,    48,    51,    52,   646,   488,    61,   118,    24,    69,
     -38,   -25,    30,    39,    17, -1020, -1020, -1020, -1020, -1020,
      41,    82,    85,    87,   101,   107,   110,   112,   117,   119,
     121,   122,     5, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020,   748,   536,    18, -1020,
     125,    40, -1020, -1020,    21, -1020,   127,   128,   129,   131,
     132,   134,   137,   138,   140,   143,   148,   149,   152,   156,
     160,   161,   162,   165,   166,   169,   171,   172,   174,   176,
     177,   179,   180, -1020,   181, -1020,   182,   185,   188,   189,
     194,   195,   196,   197,   198,   202,   203,   204,   205,   208,
     210,   211,   212,   216,   221,   108, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020,   303,     9,    36,    76,
     222,   225,    13, -1020, -1020, -1020,    14,   450,    97, -1020,
     226,   227,   228,   230,   231,   233,   234,   239,     7, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,    86,   240,
     242,   245,   246,   249,   250,   252,   254,   255,   256,   264,
     266,   269,   271,   272,   273,   275,    59, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020,    73,   111,   276,     8, -1020,
   -1020, -1020,    78, -1020,   277,    23, -1020, -1020,    74, -1020,
     324,   350,   387,   287, -1020,   144,   407,   306,   411,   412,
     412,   412,   413,   414,   415,   314,   334,   319, -1020,   320,
     311,   326,   328, -1020,   329,   340,   342,   343,   345,   346,
     347,   349,   351,   352,   353,   357,   262, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020,   323,   358,   363,   366,   367,   368,
     370, -1020,   380,   381,   382,   383,   385,   388,   389,   243,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020,   390,   399,    19, -1020,
   -1020, -1020,   431,   403, -1020, -1020,   401,   402,    57, -1020,
   -1020, -1020,   423,   412,   412,   425,   472,   427,   509,   516,
     430,   412,   433,   539,   540,   412,   541,   434,   440,   442,
     412,   545,   546,   412,   548,   549,   551,   554,   445,   438,
     460,   441,   469,   412,   412,   470,   473,   478,  -147,   -54,
     479,   480,   481,   559,   412,   482,   485,   412,   412,   487,
     491,   475, -1020,   476,   474,   477, -1020,   483,   486,   492,
     494,   495,   290, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020,   496,   497,    50, -1020, -1020, -1020,   490,
     499,   500, -1020,   503, -1020,     6, -1020, -1020, -1020, -1020,
   -1020,   583,   585,   510, -1020,   511,   513,   515,    11, -1020,
   -1020, -1020,   512,   518,   519, -1020,   521,   522,   530,   533,
     538, -1020,   542,   175, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020,   543,   544,   550,   552,    15,
   -1020, -1020, -1020, -1020,   505,   508,   561,   586,   566,   567,
     571,   412,   557, -1020, -1020,   587,   575,   598,   638,   661,
     663,   664,   665,   666,   667,   668,   684,   670,  -156,  -125,
     671,   672,   569, -1020,   570,   568, -1020,    66, -1020, -1020,
   -1020, -1020,   589,   573, -1020,   572,   679,   576, -1020,   578,
     577, -1020,   580,    31, -1020, -1020, -1020, -1020,   579,   581,
     588, -1020,   591,   593,   596,   597,   392,   599,   600,   601,
     606,   607,   608,   610,   614, -1020, -1020,   704,   705,   412,
     584,   708,   717,   412,   734,   735,   412,   722,   739,   740,
     412,   741,   741,   623, -1020, -1020,   728,    42,   729,   643,
     731,   732,   629,   737,   738,   758,   744,   745,   753,   756,
     654, -1020,   760,   761,   669, -1020,   673, -1020,   770,   771,
     677, -1020,   678,   680,   681,   682,   683,   685,   686,   687,
     688,   690,   691,   693,   694,   695,   696,   697,   699,   700,
     702,   712,   715,   719,   720,   723,   730,   736,   746,   709,
     755,   772,   762,   763,   765,   766,   774,   775,   777,   778,
     779,   783,   784,   785,   787,   788,   789,   791,   792,   796,
     797,   798,   799, -1020, -1020,   776,   721,   706,   821,   790,
     826,   833,   835,   800, -1020,   836,   839,   801, -1020, -1020,
     844,   845,   757,   861,   802, -1020,   803,   804, -1020, -1020,
     848,   849,   805, -1020, -1020,   852,   811,   806,   862,   910,
     911,   912,   827,   808,   916,   813, -1020, -1020,   918,   919,
     920,   817, -1020,   818,   819,   820,   822,   823,   824,   825,
     828, -1020,   829,   830,   831,   832,   834,   837,   838,   840,
     841,   842,   843,   846,   847, -1020, -1020,  -198, -1020, -1020,
   -1020,  -190, -1020,   850,   851, -1020, -1020,   925,   853,   854,
   -1020,   855, -1020,    79,   857, -1020, -1020,   930,   856,   931,
     858, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,   412,
     412,   412,   412,   412,   412,   412, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020,   860,   863,   864,   -36,
     865,   866,   867,   868,   869,   870,   871,   872,   873,   874,
      96,   875,   876, -1020,   877,   878,   879,   880,   881,   882,
     883,     3,   884,   885,   886,   887,   888,   889,   890, -1020,
     891,   892, -1020, -1020,   893,   894, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020,  -181, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020,  -163, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020,   895,   896,   635,   897,   898,   899,
     900,   901, -1020,   902,   903, -1020,   904,   905,   -15,   859,
     906, -1020, -1020, -1020, -1020,   907,   908, -1020,   909,   913,
     547,   914,   915,   917,   921,   922,   815,   923, -1020,   924,
     926,   927, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020,  -156, -1020,  -125, -1020, -1020,
     928,   217, -1020, -1020,   929,   932,   933, -1020,    22, -1020,
   -1020, -1020, -1020, -1020,   934,   794,   937, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
    -138, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020,   741,   741,   741, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,   -65, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020,   709, -1020,   772, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020,   -48, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020,   -40, -1020,   952,   861,   938, -1020, -1020, -1020, -1020,
   -1020,   935, -1020, -1020,   936, -1020, -1020, -1020, -1020,   939,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020,   -31, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020,   -24, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
     -16, -1020, -1020,   940,   -51,   942,   943, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,    -1,
   -1020, -1020, -1020,   -36, -1020, -1020, -1020, -1020,     3, -1020,
   -1020, -1020,   635, -1020,   -15, -1020, -1020, -1020,   946,   950,
     951, -1020,   547, -1020,   815, -1020,   217,   947,   948,   949,
     331, -1020, -1020,   794, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020,    83, -1020, -1020, -1020,
     331, -1020
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
       0,     0,     0,     0,     0,    99,   100,   102,   101,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   616,   628,   618,   619,   620,   621,   617,
     622,   623,   624,   625,   626,   627,     0,     0,     0,   449,
       0,     0,   447,   448,     0,   512,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   586,     0,   559,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   462,   509,   511,   503,
     504,   505,   506,   507,   502,   473,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   499,   474,   475,   508,
     477,   482,   483,   478,   480,   479,   493,   494,   481,   484,
     485,   486,   487,   476,   489,   490,   491,   510,   500,   501,
     498,   492,   488,   496,   497,   495,     0,     0,     0,     0,
       0,     0,     0,    45,    46,    47,     0,     0,     0,   653,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   644,
     645,   646,   647,   648,   651,   649,   650,   652,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    68,    69,
      67,    64,    63,    70,    54,    66,    57,    58,    59,    55,
      65,    60,    61,    62,    56,     0,     0,     0,     0,   118,
     119,   120,     0,   340,     0,     0,   338,   339,     0,   103,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   615,     0,
       0,     0,     0,   261,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,   229,   232,
     234,   235,   236,   237,   238,   239,   240,   241,   230,   231,
     233,   242,   243,   244,     0,     0,     0,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,     0,     0,
     391,   392,   393,   394,   395,   396,   397,   399,   398,   401,
     405,   402,   403,   404,   400,   442,     0,     0,     0,   439,
     440,   441,     0,     0,   446,   457,     0,     0,     0,   454,
     455,   456,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   461,     0,     0,     0,   308,     0,     0,     0,
       0,     0,     0,   294,   295,   296,   297,   302,   298,   299,
     300,   301,   433,     0,     0,     0,   430,   431,   432,     0,
       0,     0,   269,     0,   279,     0,   277,   278,   280,   281,
      48,     0,     0,     0,    44,     0,     0,     0,     0,   110,
     111,   112,     0,     0,     0,   197,     0,     0,     0,     0,
       0,   170,     0,     0,   150,   151,   152,   153,   156,   157,
     158,   159,   155,   154,   160,     0,     0,     0,     0,     0,
     328,   329,   330,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   643,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,   374,     0,   369,   370,
     371,   121,     0,     0,   117,     0,     0,     0,   337,     0,
       0,   352,     0,     0,   345,   346,   347,   348,     0,     0,
       0,    97,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,   614,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   406,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   390,     0,     0,     0,   438,     0,   445,     0,     0,
       0,   453,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   460,   303,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   293,     0,     0,     0,   429,   282,
       0,     0,     0,     0,     0,   276,     0,     0,    43,   113,
       0,     0,     0,   109,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,   332,     0,     0,
       0,     0,   327,     0,     0,     0,     0,     0,     0,     0,
       0,   642,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,    75,    80,
      81,     0,    79,     0,     0,    51,   372,     0,     0,     0,
     368,     0,   116,     0,     0,   336,   349,     0,     0,     0,
       0,   344,   106,   105,   104,   637,   636,   630,   640,    27,
      27,    27,    27,    27,    27,    27,    29,    28,   641,   631,
     632,   635,   634,   633,   638,   639,     0,     0,     0,     0,
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
       0,     0,   326,   655,   654,   660,   658,   661,   656,   657,
     659,    88,    96,    87,    94,    95,    86,    90,    89,    83,
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
   -1020, -1020, -1020,  -185,  -307, -1019,  -621, -1020, -1020,   675,
   -1020, -1020, -1020, -1020,   807, -1020, -1020, -1020,    43, -1020,
      37, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,  1000, -1020,
   -1020, -1020, -1020, -1020, -1020,   592, -1020, -1020, -1020, -1020,
     941, -1020, -1020, -1020, -1020,    53, -1020, -1020, -1020, -1020,
   -1020,  -155, -1020, -1020, -1020,   627, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020,  -113, -1020, -1020,
   -1020,  -107, -1020, -1020, -1020,   812, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020,   -86, -1020, -1020, -1020, -1020, -1020,
     -95, -1020,   674, -1020, -1020, -1020,    20, -1020, -1020, -1020,
   -1020, -1020,   698, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
     -81, -1020, -1020, -1020, -1020, -1020, -1020,   633, -1020, -1020,
   -1020, -1020, -1020,   944, -1020, -1020, -1020, -1020,   602, -1020,
   -1020, -1020, -1020, -1020,   -92, -1020, -1020, -1020,   612, -1020,
   -1020, -1020, -1020,   -88, -1020, -1020, -1020,   814, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,   -63,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,   707, -1020,
   -1020, -1020, -1020, -1020,   793, -1020, -1020, -1020, -1020,  1069,
   -1020, -1020, -1020, -1020,   786, -1020, -1020, -1020, -1020,  1021,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020,    84, -1020, -1020,
   -1020,    88, -1020, -1020, -1020, -1020, -1020,  1095, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020,   953, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   816,   817,  1075,  1076,    26,   222,   223,
     224,   225,    27,   266,   267,   268,   269,   777,   778,   781,
     782,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,    28,    74,    75,    76,
      77,    78,    29,    61,   498,   499,   500,   501,    30,   288,
     289,   290,   291,   292,  1038,  1039,  1040,  1041,  1042,  1215,
    1286,  1287,    31,    62,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   743,  1191,  1192,   524,   737,
    1161,  1162,    32,    51,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   610,  1060,  1061,    33,    59,   484,   722,  1131,
    1132,   485,   486,   487,  1135,   980,   981,   488,   489,    34,
      57,   462,   463,   464,   465,   466,   467,   468,   707,  1117,
    1118,   469,   470,   471,    35,    63,   529,   530,   531,   532,
     533,    36,   295,   296,   297,    37,    69,   583,   584,   585,
     586,   587,   798,  1229,  1230,    38,    66,   567,   568,   569,
     570,   788,  1210,  1211,    39,    52,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   632,  1088,  1089,
     380,   381,   382,   383,   384,    40,    58,   475,   476,   477,
     478,    41,    53,   388,   389,   390,   391,    42,   111,   112,
     113,    43,    55,   398,   399,   400,   401,    44,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   431,   941,   942,   212,   429,
     915,   916,   213,   214,   215,    45,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      46,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     841,   842,   597,   598,   599,    49,    79,   479,   229,   286,
     472,  1086,   495,    50,   219,   495,   525,  1058,    70,   385,
     385,    54,   395,  1034,   293,   293,   109,    80,    81,    47,
      48,  1024,   579,    82,  1128,  1025,   230,   479,    56,  1026,
      60,   109,    71,  1027,   231,   775,   776,   219,  1101,    72,
     526,   472,  1102,  1234,  1235,  1236,   232,   233,   395,   840,
     248,   234,   235,   236,   480,   688,  1103,   564,   689,   481,
    1104,   482,    83,    84,   564,   579,   779,   780,    85,    86,
    1034,   386,   386,   237,   249,    87,    88,    89,   110,   496,
    1059,  1232,   496,   527,   480,  1233,   653,   654,   525,   481,
      64,   482,    65,   110,   661,  1072,  1073,  1074,   665,   115,
     220,    90,    91,   670,   116,   117,   673,    73,   250,   286,
     118,   396,  1035,   294,   294,   251,   683,   684,   119,   120,
     483,   580,   526,    67,   221,   121,   473,   696,   122,   123,
     699,   700,   528,   220,   124,   387,   387,   252,   397,   125,
     126,   253,   127,   128,   129,  1258,   130,   396,   690,   254,
     483,   691,   255,   256,  1237,   131,   565,   221,  1238,   132,
     133,    68,  1129,   565,   580,   527,   502,   473,   134,  1035,
    -123,  1241,  1130,   497,   397,  1242,   497,   135,   106,  1243,
     107,   299,   503,  1244,   257,   136,   108,   137,  1251,   138,
    1087,   139,  1252,   140,   141,  1253,   840,   300,   504,  1254,
     114,   258,   216,  1255,   259,  1036,   142,  1256,   845,   846,
     217,   143,   144,   145,   528,   146,   147,   148,  1262,   218,
     149,   287,  1263,   474,   760,   317,   724,   542,   573,   260,
     505,   732,  1037,   493,   354,   751,   355,   303,   356,   644,
     575,   581,  1216,   577,   592,   582,   150,   261,   262,   263,
     357,   800,   301,   319,   151,   152,   153,   154,   155,   156,
     393,   302,  1036,   305,   474,   506,   358,   320,   321,   226,
     717,   322,   227,   228,   264,   265,   566,   650,  1200,   562,
    -123,   453,   285,   566,   581,   507,   789,   157,   582,  1037,
     298,   359,   828,   360,   453,   490,   832,   454,   361,   835,
      79,   508,  1289,   839,   306,   544,  1290,   307,   362,   308,
     454,   158,   159,   455,   160,   161,   162,   323,   509,   510,
     163,    80,    81,   309,    70,   164,   455,    82,   451,   310,
     571,   287,   311,   363,   312,   324,   325,   326,   327,   313,
    1201,   314,   328,   315,   316,   456,   329,   392,    71,   402,
     403,   404,   330,   405,   406,    72,   407,   364,   456,   408,
     409,  1277,   410,   331,   332,   411,    83,    84,   511,  1202,
     412,   413,    85,    86,   414,   333,  1203,   365,   415,    87,
      88,    89,   416,   417,   418,  1204,   366,   419,   420,   512,
    1278,   421,  1279,   422,   423,   745,   424,   334,   425,   426,
     457,   427,   428,   430,   432,    90,    91,   433,   458,   459,
     434,   435,  1205,   457,  1206,  1207,   436,   437,   438,   439,
     440,   458,   459,    73,   441,   442,   443,   444,  1208,   460,
     445,   367,   446,   447,   448,  1209,   335,  1280,   449,   588,
     115,   502,   460,   450,   491,   116,   117,   492,   534,   535,
     536,   118,   537,   538,  1281,   539,   540,   503,   368,   119,
     120,   541,   545,   640,   546,   589,   121,   547,   548,   122,
     123,   549,   550,   504,   551,   124,   552,   553,   554,   248,
     125,   126,   623,   127,   128,   129,   555,   130,   556,  1282,
    1283,   557,   596,   558,   559,   560,   131,   561,   572,   576,
     132,   133,   590,   249,   461,   505,   591,   593,   594,   134,
     713,   595,   596,   600,   601,   602,   603,   461,   135,   809,
     810,   811,   812,   813,   814,   815,   136,   354,   137,   355,
     138,   356,   139,   607,   140,   141,   604,   250,   605,   606,
     506,  1140,   625,   357,   251,  1284,   646,   142,   608,  1285,
     609,   611,   143,   144,   145,  1141,   146,   147,   148,   358,
     507,   149,   612,  1142,   613,   614,   252,   615,   616,   617,
     253,   618,   656,   619,   620,   621,   508,  1143,   254,   622,
     626,   255,   256,  1259,   359,   627,   360,   150,   628,   629,
     630,   361,   631,   509,   510,   151,   152,   153,   154,   155,
     156,   362,   633,   634,   635,   636,  1144,   637,  1145,   658,
     638,   639,   642,   257,  1048,  1049,  1050,  1051,  1052,  1053,
    1054,   643,   647,   648,   649,   652,   363,   655,   157,   657,
     258,   659,   660,   259,  1146,   662,   667,   229,  1107,   663,
     664,   666,   668,   511,   669,   671,   672,   678,   674,   675,
     364,   676,   158,   159,   677,   160,   161,   162,   260,  1108,
     679,   163,   680,   681,   512,   230,   164,  1147,  1109,  1148,
     365,   682,   685,   231,   695,   686,   261,   262,   263,   366,
     687,   692,   693,   694,   697,   232,   233,   698,  1149,   701,
     234,   235,   236,   702,   703,   704,   705,  1110,   726,   706,
     727,   756,   762,   264,   265,   708,  1150,   753,   709,   719,
     754,  1151,   237,   764,   710,  1152,   711,   712,   715,   716,
    1153,   720,   721,  1154,   367,   723,  1111,  1112,  1155,   728,
     729,   734,     2,     3,  1113,   730,     4,   731,   765,   319,
     735,   736,  1156,   738,   739,  1157,     5,  1158,   894,     6,
       7,   368,   740,   320,   321,   741,     8,   322,  1159,  1114,
     742,   766,   747,   755,   744,  1160,   748,     9,   757,   758,
      10,    11,   749,   759,   750,  1115,   761,   763,   767,   768,
     769,   770,   771,   772,   773,   774,   783,   784,   785,   786,
     787,   791,   792,   793,   794,   795,    12,   796,   802,   797,
     803,    13,   799,   323,   826,   827,   829,   804,   830,    14,
     805,   918,   806,   919,   920,   807,   808,   831,   818,   819,
     820,   324,   325,   326,   327,   821,   822,   823,   328,   824,
      15,    16,   329,   825,   833,   834,  1116,   836,   330,   837,
     838,   840,   843,   844,   847,   848,   849,   850,    17,   331,
     332,   851,   852,   853,  1168,  1219,  1169,  1170,   854,   855,
     856,   333,   895,   896,   897,    18,   898,   899,   857,   900,
     901,   858,   902,   859,   903,   860,   861,   904,    19,    20,
     905,   906,   907,   334,   908,   864,   865,   494,   862,   909,
     968,   964,   863,   910,   911,   912,   866,   867,    21,   868,
     869,   870,   871,   913,   872,   873,   874,   875,   914,   876,
     877,    22,   878,   879,   880,   881,   882,  1220,   883,   884,
      23,   885,   335,   965,    24,   921,   922,   923,   966,   924,
     925,   886,   926,   927,   887,   928,   967,   929,   888,   889,
     930,   969,   890,   931,   932,   933,  1221,   934,   970,   891,
     971,   973,   935,  1222,   974,   892,   936,   937,   938,   976,
     977,   979,  1223,   985,   986,   893,   939,   988,  1171,  1172,
    1173,   940,  1174,  1175,   917,  1176,  1177,   991,  1178,   978,
    1179,   943,   944,  1180,   945,   946,  1181,  1182,  1183,  1224,
    1184,  1225,  1226,   947,   948,  1185,   949,   950,   951,  1186,
    1187,  1188,   952,   953,   954,  1227,   955,   956,   957,  1189,
     958,   959,  1228,   989,  1190,   960,   961,   962,   963,   972,
     975,   982,   983,   984,   987,   992,   993,   994,   990,   995,
     996,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,
    1030,  1006,  1007,  1008,  1009,  1044,  1046,  1010,  1011,  1012,
    1013,  1014,  1245,  1015,  1198,  1257,  1016,  1017,  1197,  1018,
    1019,  1020,  1021,   563,   304,  1022,  1023,  1268,  1133,  1028,
    1029,  1269,  1270,  1032,  1033,  1031,  1043,  1047,  1045,  1055,
     733,  1217,  1056,  1057,  1062,  1063,  1064,  1065,  1066,  1067,
    1068,  1069,  1070,  1071,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1105,  1106,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,  1291,  1136,  1137,  1138,  1134,
     746,  1272,  1139,  1163,  1164,  1271,  1165,  1264,   624,  1267,
    1166,  1167,  1193,  1194,  1246,  1195,  1196,  1199,  1212,   725,
     714,  1266,   752,  1218,  1213,  1214,  1231,  1247,  1273,  1248,
    1249,  1288,  1261,  1250,  1260,  1265,  1274,  1275,  1276,   790,
     394,   645,   718,   641,   651,   801,   452,   318,  1240,     0,
    1239,   543,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   574,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   578
};

static const yytype_int16 yycheck[] =
{
     621,   622,   309,   310,   311,   231,     1,     1,     1,     1,
       1,     8,     1,   231,     1,     1,     1,    53,     1,     1,
       1,   231,     1,     1,     1,     1,     1,    22,    23,   229,
     230,   229,     1,    28,    49,   233,    29,     1,   231,   229,
     231,     1,    25,   233,    37,   201,   202,     1,   229,    32,
      35,     1,   233,  1072,  1073,  1074,    49,    50,     1,   110,
       1,    54,    55,    56,    58,   212,   229,     1,   215,    63,
     233,    65,    67,    68,     1,     1,   201,   202,    73,    74,
       1,    63,    63,    76,    25,    80,    81,    82,    63,    78,
     126,   229,    78,    78,    58,   233,   403,   404,     1,    63,
     231,    65,   231,    63,   411,     9,    10,    11,   415,     1,
      97,   106,   107,   420,     6,     7,   423,   100,    59,     1,
      12,   100,   100,   100,   100,    66,   433,   434,    20,    21,
     124,   100,    35,   231,   121,    27,   127,   444,    30,    31,
     447,   448,   127,    97,    36,   127,   127,    88,   127,    41,
      42,    92,    44,    45,    46,   206,    48,   100,   212,   100,
     124,   215,   103,   104,   229,    57,   100,   121,   233,    61,
      62,   231,   187,   100,   100,    78,     1,   127,    70,   100,
     172,   229,   197,   172,   127,   233,   172,    79,   231,   229,
     231,   229,    17,   233,   135,    87,   231,    89,   229,    91,
     197,    93,   233,    95,    96,   229,   110,   232,    33,   233,
     231,   152,   231,   229,   155,   193,   108,   233,   176,   177,
     231,   113,   114,   115,   127,   117,   118,   119,   229,   231,
     122,   223,   233,   224,   541,   230,   230,   230,   230,   180,
      65,   230,   220,   230,     1,   230,     3,   230,     5,   230,
     172,   220,   230,   230,   110,   224,   148,   198,   199,   200,
      17,   230,   232,     1,   156,   157,   158,   159,   160,   161,
     230,   232,   193,   232,   224,   100,    33,    15,    16,   231,
     230,    19,   231,   231,   225,   226,   220,   230,    71,   230,
     172,     1,   231,   220,   220,   120,   230,   189,   224,   220,
     231,    58,   609,    60,     1,   229,   613,    17,    65,   616,
       1,   136,   229,   620,   232,   229,   233,   232,    75,   232,
      17,   213,   214,    33,   216,   217,   218,    65,   153,   154,
     222,    22,    23,   232,     1,   227,    33,    28,   230,   232,
     229,   223,   232,   100,   232,    83,    84,    85,    86,   232,
     133,   232,    90,   232,   232,    65,    94,   232,    25,   232,
     232,   232,   100,   232,   232,    32,   232,   124,    65,   232,
     232,    40,   232,   111,   112,   232,    67,    68,   203,   162,
     232,   232,    73,    74,   232,   123,   169,   144,   232,    80,
      81,    82,   232,   232,   232,   178,   153,   232,   232,   224,
      69,   232,    71,   232,   232,   230,   232,   145,   232,   232,
     120,   232,   232,   232,   232,   106,   107,   232,   128,   129,
     232,   232,   205,   120,   207,   208,   232,   232,   232,   232,
     232,   128,   129,   100,   232,   232,   232,   232,   221,   149,
     232,   198,   232,   232,   232,   228,   184,   116,   232,   125,
       1,     1,   149,   232,   232,     6,     7,   232,   232,   232,
     232,    12,   232,   232,   133,   232,   232,    17,   225,    20,
      21,   232,   232,   230,   232,   125,    27,   232,   232,    30,
      31,   232,   232,    33,   232,    36,   232,   232,   232,     1,
      41,    42,   230,    44,    45,    46,   232,    48,   232,   168,
     169,   232,   110,   232,   232,   232,    57,   232,   232,   232,
      61,    62,   125,    25,   224,    65,   229,   110,   212,    70,
     230,   110,   110,   110,   110,   110,   212,   224,    79,   137,
     138,   139,   140,   141,   142,   143,    87,     1,    89,     3,
      91,     5,    93,   232,    95,    96,   212,    59,   229,   229,
     100,     4,   229,    17,    66,   224,   125,   108,   232,   228,
     232,   232,   113,   114,   115,    18,   117,   118,   119,    33,
     120,   122,   232,    26,   232,   232,    88,   232,   232,   232,
      92,   232,   110,   232,   232,   232,   136,    40,   100,   232,
     232,   103,   104,  1214,    58,   232,    60,   148,   232,   232,
     232,    65,   232,   153,   154,   156,   157,   158,   159,   160,
     161,    75,   232,   232,   232,   232,    69,   232,    71,   110,
     232,   232,   232,   135,   809,   810,   811,   812,   813,   814,
     815,   232,   229,   232,   232,   212,   100,   212,   189,   212,
     152,   125,   212,   155,    97,   212,   212,     1,    13,   110,
     110,   110,   212,   203,   212,   110,   110,   212,   110,   110,
     124,   110,   213,   214,   110,   216,   217,   218,   180,    34,
     232,   222,   212,   232,   224,    29,   227,   130,    43,   132,
     144,   212,   212,    37,   125,   212,   198,   199,   200,   153,
     212,   212,   212,   212,   212,    49,    50,   212,   151,   212,
      54,    55,    56,   212,   229,   229,   232,    72,   125,   232,
     125,   125,   125,   225,   226,   232,   169,   212,   232,   229,
     212,   174,    76,   125,   232,   178,   232,   232,   232,   232,
     183,   232,   232,   186,   198,   232,   101,   102,   191,   229,
     229,   229,     0,     1,   109,   232,     4,   232,   110,     1,
     232,   232,   205,   232,   232,   208,    14,   210,    49,    17,
      18,   225,   232,    15,    16,   232,    24,    19,   221,   134,
     232,   110,   229,   212,   232,   228,   232,    35,   212,   212,
      38,    39,   232,   212,   232,   150,   229,   212,   125,   125,
     125,   125,   125,   125,   110,   125,   125,   125,   229,   229,
     232,   212,   229,   231,   125,   229,    64,   229,   229,   232,
     229,    69,   232,    65,   110,   110,   232,   229,   110,    77,
     229,    49,   229,    51,    52,   229,   229,   110,   229,   229,
     229,    83,    84,    85,    86,   229,   229,   229,    90,   229,
      98,    99,    94,   229,   110,   110,   211,   125,   100,   110,
     110,   110,   229,   125,   125,   212,   125,   125,   116,   111,
     112,   232,   125,   125,    49,    71,    51,    52,   110,   125,
     125,   123,   163,   164,   165,   133,   167,   168,   125,   170,
     171,   125,   173,   229,   175,   125,   125,   178,   146,   147,
     181,   182,   183,   145,   185,   125,   125,   222,   229,   190,
     110,   125,   229,   194,   195,   196,   229,   229,   166,   229,
     229,   229,   229,   204,   229,   229,   229,   229,   209,   229,
     229,   179,   229,   229,   229,   229,   229,   133,   229,   229,
     188,   229,   184,   212,   192,   163,   164,   165,   232,   167,
     168,   229,   170,   171,   229,   173,   125,   175,   229,   229,
     178,   125,   229,   181,   182,   183,   162,   185,   125,   229,
     125,   125,   190,   169,   125,   229,   194,   195,   196,   125,
     125,   110,   178,   125,   125,   229,   204,   125,   163,   164,
     165,   209,   167,   168,   229,   170,   171,   125,   173,   232,
     175,   229,   229,   178,   229,   229,   181,   182,   183,   205,
     185,   207,   208,   229,   229,   190,   229,   229,   229,   194,
     195,   196,   229,   229,   229,   221,   229,   229,   229,   204,
     229,   229,   228,   212,   209,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   125,   125,   125,   232,   212,
     232,   125,   229,   125,   125,   125,   229,   229,   229,   229,
     125,   229,   229,   229,   229,   125,   125,   229,   229,   229,
     229,   229,   110,   229,  1027,   125,   229,   229,  1025,   229,
     229,   229,   229,   266,    74,   229,   229,   131,   219,   229,
     229,   131,   131,   229,   229,   232,   229,   229,   232,   229,
     498,  1038,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,  1290,   229,   229,   229,   233,
     513,  1254,   229,   229,   229,  1252,   229,  1233,   336,  1244,
     229,   229,   229,   229,  1134,   229,   229,   229,   229,   485,
     462,  1242,   529,   229,   232,   232,   229,   229,  1256,   234,
     234,  1263,   229,   234,   232,  1238,   229,   229,   229,   567,
     111,   388,   475,   369,   398,   583,   165,    92,  1104,    -1,
    1102,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   295
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   236,     0,     1,     4,    14,    17,    18,    24,    35,
      38,    39,    64,    69,    77,    98,    99,   116,   133,   146,
     147,   166,   179,   188,   192,   237,   242,   247,   271,   277,
     283,   297,   317,   340,   354,   369,   376,   380,   390,   399,
     420,   426,   432,   436,   442,   500,   515,   229,   230,   231,
     231,   318,   400,   427,   231,   437,   231,   355,   421,   341,
     231,   278,   298,   370,   231,   231,   391,   231,   231,   381,
       1,    25,    32,   100,   272,   273,   274,   275,   276,     1,
      22,    23,    28,    67,    68,    73,    74,    80,    81,    82,
     106,   107,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   231,   231,   231,     1,
      63,   433,   434,   435,   231,     1,     6,     7,    12,    20,
      21,    27,    30,    31,    36,    41,    42,    44,    45,    46,
      48,    57,    61,    62,    70,    79,    87,    89,    91,    93,
      95,    96,   108,   113,   114,   115,   117,   118,   119,   122,
     148,   156,   157,   158,   159,   160,   161,   189,   213,   214,
     216,   217,   218,   222,   227,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   493,   497,   498,   499,   231,   231,   231,     1,
      97,   121,   243,   244,   245,   246,   231,   231,   231,     1,
      29,    37,    49,    50,    54,    55,    56,    76,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,     1,    25,
      59,    66,    88,    92,   100,   103,   104,   135,   152,   155,
     180,   198,   199,   200,   225,   226,   248,   249,   250,   251,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   231,     1,   223,   284,   285,
     286,   287,   288,     1,   100,   377,   378,   379,   231,   229,
     232,   232,   232,   230,   273,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   230,   502,     1,
      15,    16,    19,    65,    83,    84,    85,    86,    90,    94,
     100,   111,   112,   123,   145,   184,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,     1,     3,     5,    17,    33,    58,
      60,    65,    75,   100,   124,   144,   153,   198,   225,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     415,   416,   417,   418,   419,     1,    63,   127,   428,   429,
     430,   431,   232,   230,   434,     1,   100,   127,   438,   439,
     440,   441,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   494,
     232,   490,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   230,   444,     1,    17,    33,    65,   120,   128,   129,
     149,   224,   356,   357,   358,   359,   360,   361,   362,   366,
     367,   368,     1,   127,   224,   422,   423,   424,   425,     1,
      58,    63,    65,   124,   342,   346,   347,   348,   352,   353,
     229,   232,   232,   230,   244,     1,    78,   172,   279,   280,
     281,   282,     1,    17,    33,    65,   100,   120,   136,   153,
     154,   203,   224,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   313,     1,    35,    78,   127,   371,
     372,   373,   374,   375,   232,   232,   232,   232,   232,   232,
     232,   232,   230,   517,   229,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   230,   249,     1,   100,   220,   392,   393,   394,
     395,   229,   232,   230,   285,   172,   232,   230,   378,     1,
     100,   220,   224,   382,   383,   384,   385,   386,   125,   125,
     125,   229,   110,   110,   212,   110,   110,   239,   239,   239,
     110,   110,   110,   212,   212,   229,   229,   232,   232,   232,
     337,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   230,   320,   229,   232,   232,   232,   232,
     232,   232,   412,   232,   232,   232,   232,   232,   232,   232,
     230,   402,   232,   232,   230,   429,   125,   229,   232,   232,
     230,   439,   212,   239,   239,   212,   110,   212,   110,   125,
     212,   239,   212,   110,   110,   239,   110,   212,   212,   212,
     239,   110,   110,   239,   110,   110,   110,   110,   212,   232,
     212,   232,   212,   239,   239,   212,   212,   212,   212,   215,
     212,   215,   212,   212,   212,   125,   239,   212,   212,   239,
     239,   212,   212,   229,   229,   232,   232,   363,   232,   232,
     232,   232,   232,   230,   357,   232,   232,   230,   423,   229,
     232,   232,   343,   232,   230,   347,   125,   125,   229,   229,
     232,   232,   230,   280,   229,   232,   232,   314,   232,   232,
     232,   232,   232,   310,   232,   230,   300,   229,   232,   232,
     232,   230,   372,   212,   212,   212,   125,   212,   212,   212,
     239,   229,   125,   212,   125,   110,   110,   125,   125,   125,
     125,   125,   125,   110,   125,   201,   202,   252,   253,   201,
     202,   254,   255,   125,   125,   229,   229,   232,   396,   230,
     393,   212,   229,   231,   125,   229,   229,   232,   387,   232,
     230,   383,   229,   229,   229,   229,   229,   229,   229,   137,
     138,   139,   140,   141,   142,   143,   238,   239,   229,   229,
     229,   229,   229,   229,   229,   229,   110,   110,   239,   232,
     110,   110,   239,   110,   110,   239,   125,   110,   110,   239,
     110,   241,   241,   229,   125,   176,   177,   125,   212,   125,
     125,   232,   125,   125,   110,   125,   125,   125,   125,   229,
     125,   125,   229,   229,   125,   125,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,    49,   163,   164,   165,   167,   168,
     170,   171,   173,   175,   178,   181,   182,   183,   185,   190,
     194,   195,   196,   204,   209,   495,   496,   229,    49,    51,
      52,   163,   164,   165,   167,   168,   170,   171,   173,   175,
     178,   181,   182,   183,   185,   190,   194,   195,   196,   204,
     209,   491,   492,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   125,   212,   232,   125,   110,   125,
     125,   125,   229,   125,   125,   229,   125,   125,   232,   110,
     350,   351,   229,   229,   229,   125,   125,   229,   125,   212,
     232,   125,   125,   125,   125,   212,   232,   125,   229,   125,
     125,   125,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   233,   229,   233,   229,   229,
     125,   232,   229,   229,     1,   100,   193,   220,   289,   290,
     291,   292,   293,   229,   125,   232,   125,   229,   238,   238,
     238,   238,   238,   238,   238,   229,   229,   229,    53,   126,
     338,   339,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,     9,    10,    11,   240,   241,   229,   229,   229,
     229,   229,   229,   229,   229,   229,     8,   197,   413,   414,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   233,   229,   233,   229,   229,    13,    34,    43,
      72,   101,   102,   109,   134,   150,   211,   364,   365,   229,
     229,   229,   229,   229,   229,   229,   229,   229,    49,   187,
     197,   344,   345,   219,   233,   349,   229,   229,   229,   229,
       4,    18,    26,    40,    69,    71,    97,   130,   132,   151,
     169,   174,   178,   183,   186,   191,   205,   208,   210,   221,
     228,   315,   316,   229,   229,   229,   229,   229,    49,    51,
      52,   163,   164,   165,   167,   168,   170,   171,   173,   175,
     178,   181,   182,   183,   185,   190,   194,   195,   196,   204,
     209,   311,   312,   229,   229,   229,   229,   253,   255,   229,
      71,   133,   162,   169,   178,   205,   207,   208,   221,   228,
     397,   398,   229,   232,   232,   294,   230,   290,   229,    71,
     133,   162,   169,   178,   205,   207,   208,   221,   228,   388,
     389,   229,   229,   233,   240,   240,   240,   229,   233,   496,
     492,   229,   233,   229,   233,   110,   351,   229,   234,   234,
     234,   229,   233,   229,   233,   229,   233,   125,   206,   241,
     232,   229,   229,   233,   339,   414,   365,   345,   131,   131,
     131,   316,   312,   398,   229,   229,   229,    40,    69,    71,
     116,   133,   168,   169,   224,   228,   295,   296,   389,   229,
     233,   296
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   235,   236,   236,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   238,   238,   239,
     239,   239,   239,   239,   239,   239,   239,   240,   240,   241,
     241,   241,   241,   242,   243,   243,   244,   244,   244,   245,
     246,   247,   248,   248,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   250,   251,   252,   252,   253,   253,   254,   254,
     255,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   272,
     273,   273,   273,   273,   274,   275,   276,   278,   277,   279,
     279,   280,   280,   280,   281,   282,   283,   284,   284,   285,
     285,   285,   286,   288,   287,   289,   289,   290,   290,   290,
     290,   291,   292,   292,   294,   293,   295,   295,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   298,   297,   299,
     299,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     310,   309,   311,   311,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   314,   313,   315,
     315,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   318,   317,   319,   319,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   337,   336,   338,   338,   339,   339,   341,   340,   343,
     342,   344,   344,   345,   345,   345,   346,   346,   347,   347,
     347,   347,   347,   349,   348,   350,   350,   351,   351,   352,
     353,   355,   354,   356,   356,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   358,   359,   360,   361,   363,   362,
     364,   364,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   366,   367,   368,   370,   369,   371,   371,   372,
     372,   372,   372,   373,   374,   375,   376,   377,   377,   378,
     378,   379,   381,   380,   382,   382,   383,   383,   383,   383,
     384,   385,   387,   386,   388,   388,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   391,   390,   392,   392,
     393,   393,   393,   394,   396,   395,   397,   397,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   400,   399,
     401,   401,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   410,   412,   411,   413,   413,
     414,   414,   415,   416,   417,   418,   419,   421,   420,   422,
     422,   423,   423,   423,   424,   425,   427,   426,   428,   428,
     429,   429,   429,   430,   431,   432,   433,   433,   434,   434,
     435,   437,   436,   438,   438,   439,   439,   439,   440,   441,
     442,   443,   443,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     471,   472,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   490,
     489,   491,   491,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   494,   493,   495,   495,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   497,   498,   499,   500,   501,   501,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   516,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   518,   519,   520,   521,   522,   523,
     524,   525
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
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4
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
#line 408 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 409 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 410 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2853 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 437 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 443 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 477 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 483 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2959 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 492 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2970 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 498 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 506 "conf_parser.y" /* yacc.c:1646  */
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
#line 3026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 548 "conf_parser.y" /* yacc.c:1646  */
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
#line 3087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 606 "conf_parser.y" /* yacc.c:1646  */
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
#line 3118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 634 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 642 "conf_parser.y" /* yacc.c:1646  */
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
#line 3147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 657 "conf_parser.y" /* yacc.c:1646  */
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
#line 3165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 672 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
#line 3177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 681 "conf_parser.y" /* yacc.c:1646  */
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
#line 3194 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 695 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 704 "conf_parser.y" /* yacc.c:1646  */
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
#line 3237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 732 "conf_parser.y" /* yacc.c:1646  */
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
#line 3270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 762 "conf_parser.y" /* yacc.c:1646  */
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
#line 3298 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 787 "conf_parser.y" /* yacc.c:1646  */
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
#line 3323 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 809 "conf_parser.y" /* yacc.c:1646  */
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
#line 3348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 831 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 848 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 857 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 866 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 878 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 882 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
    motd_add(ptr->data, block_state.file.buf);
}
#line 3419 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 899 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 905 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 920 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 926 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 930 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 946 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3479 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 954 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 957 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3495 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 969 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3513 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 973 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3522 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 977 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 981 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3540 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 985 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3549 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 989 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 993 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 997 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1001 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1011 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3597 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1018 "conf_parser.y" /* yacc.c:1646  */
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
#line 3673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1104 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1110 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1116 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3700 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1122 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1133 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1139 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1145 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3746 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1156 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3755 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1162 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1169 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1173 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1177 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1181 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1185 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1189 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1193 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1201 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1205 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1209 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1213 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1217 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1225 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
#line 3899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1237 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1245 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1253 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1257 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3971 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3980 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1270 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1274 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1278 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1282 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1286 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1290 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1294 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
#line 4043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1298 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1302 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1306 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1310 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1314 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1318 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1322 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1326 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1330 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1334 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1338 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
#line 4142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1342 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1346 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1350 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1354 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1358 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4187 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1362 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1372 "conf_parser.y" /* yacc.c:1646  */
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
#line 4213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1384 "conf_parser.y" /* yacc.c:1646  */
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
#line 4265 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1451 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4274 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1457 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4283 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1463 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4292 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1469 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1475 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1481 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1487 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1493 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4337 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1499 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4346 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1505 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1512 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1518 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1524 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1530 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4395 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1539 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1548 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1555 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1559 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1569 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1575 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1581 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1585 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1589 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1597 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4484 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1602 "conf_parser.y" /* yacc.c:1646  */
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
#line 4503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1616 "conf_parser.y" /* yacc.c:1646  */
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
#line 4524 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1634 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1640 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1649 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4551 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1653 "conf_parser.y" /* yacc.c:1646  */
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
#line 4592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1702 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4601 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1708 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4610 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1714 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1720 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1731 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1738 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1742 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4660 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1746 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4669 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1750 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4678 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1754 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4687 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1758 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4696 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1762 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1766 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1770 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1774 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1780 "conf_parser.y" /* yacc.c:1646  */
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
#line 4749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1794 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4761 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1803 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1816 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4785 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1823 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4796 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4805 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1840 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1846 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1861 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1876 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1887 "conf_parser.y" /* yacc.c:1646  */
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
#line 4871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1904 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1910 "conf_parser.y" /* yacc.c:1646  */
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
#line 4902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1929 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1936 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1940 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1944 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1948 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1952 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1956 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1960 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1964 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1972 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1981 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1990 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2005 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2011 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2018 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2022 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2026 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2030 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2038 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2042 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2050 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2063 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2072 "conf_parser.y" /* yacc.c:1646  */
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
#line 5218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2152 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5227 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2158 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2164 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2170 "conf_parser.y" /* yacc.c:1646  */
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
#line 5261 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2183 "conf_parser.y" /* yacc.c:1646  */
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
#line 5277 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2196 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5286 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2202 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5295 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2208 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2212 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5315 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2220 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5323 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2226 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5332 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2230 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5355 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2247 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2253 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2259 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2265 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2284 "conf_parser.y" /* yacc.c:1646  */
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
#line 5430 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2309 "conf_parser.y" /* yacc.c:1646  */
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
#line 5453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2338 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5471 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2342 "conf_parser.y" /* yacc.c:1646  */
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
#line 5497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2368 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2374 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2388 "conf_parser.y" /* yacc.c:1646  */
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
#line 5532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2405 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2409 "conf_parser.y" /* yacc.c:1646  */
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
#line 5563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2431 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2437 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2502 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2507 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2513 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2519 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2525 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2531 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2536 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5641 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2541 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2546 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5657 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2551 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2556 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2561 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5681 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2566 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5689 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2571 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number);
}
#line 5697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2576 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2581 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5713 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2586 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2591 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5729 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2596 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5738 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2602 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5752 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2613 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5760 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2618 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_connect_block = yylval.number;
}
#line 5768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2623 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2628 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2633 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2638 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2643 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5808 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2646 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2651 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2654 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2659 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2664 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5848 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2669 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2674 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2679 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2684 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2689 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2694 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2699 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2704 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2709 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.use_egd = yylval.number;
}
#line 5920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2714 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
#line 5932 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2723 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 5944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2732 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 5952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2737 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 5960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = (yyvsp[-1].number);
}
#line 5968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2747 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 5976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2753 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 5984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2756 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 5992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2759 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 6000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 6008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2765 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 6016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2768 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 6024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2771 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDECHANS;
}
#line 6032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2774 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 6048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2783 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2789 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
#line 6096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2798 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2824 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2830 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2833 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6184 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2836 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2839 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2845 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2851 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2854 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2860 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
#line 6272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2869 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2878 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2884 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2895 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2900 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2932 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2937 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay = (yyvsp[-1].number);
}
#line 6376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2942 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2947 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
#line 6392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2952 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[-1].number);
}
#line 6400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2957 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2962 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2967 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2972 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2977 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2982 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 2987 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 3009 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 3015 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3042 "conf_parser.y" /* yacc.c:1646  */
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
#line 6521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3056 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3062 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6539 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6543 "conf_parser.c" /* yacc.c:1646  */
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
